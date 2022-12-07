#include <ultra64.h>
#include "constants.h"
#include "game/prop.h"
#include "game/game_1531a0.h"
#include "game/bg.h"
#include "bss.h"
#include "lib/dma.h"
#include "lib/memp.h"
#include "lib/mtx.h"
#include "lib/anim.h"
#include "lib/lib_2f490.h"
#include "lib/libc/ll.h"
#include "data.h"
#include "types.h"

#define ANIM_HEADER_CACHE_SIZE 40
#define ANIM_FRAME_CACHE_SIZE  32

u8 *g_AnimFrameByteSlots;
u8 **g_AnimFrameBytes;
s16 *g_AnimFrameAnimNums;
s16 *g_AnimFrameFrameNums;
u8 *g_AnimFrameBirths;
u8 *g_AnimHeaderByteSlots;
u8 **g_AnimHeaderBytes;
s16 *g_AnimHeaderAnimNums;
s32 *g_AnimHeaderBirths;
s16 g_NumRomAnimations;
struct animtableentry *g_RomAnims;

u32 g_NextAnimFrameIndex = 0;
s32 g_NextAnimHeaderIndex = 0;
s16 g_NumAnimations = 0;
struct animtableentry *g_Anims = NULL;
u8 *g_AnimToHeaderSlot = NULL;
s16 *var8005f014 = NULL;
s32 g_AnimMaxBytesPerFrame = 176;
s32 g_AnimMaxHeaderLength = 608;
bool g_AnimHostEnabled = false;
u8 *g_AnimHostSegment = NULL;

extern u8 _animationsTableRomStart;
extern u8 _animationsTableRomEnd;

void animsInit(void)
{
	s32 i;
	u32 *ptr;
	u32 tablelen = ALIGN64(&_animationsTableRomEnd - &_animationsTableRomStart);

	ptr = mempAlloc(tablelen, MEMPOOL_PERMANENT);
	dmaExec(ptr, (romptr_t) &_animationsTableRomStart, tablelen);

	g_NumAnimations = g_NumRomAnimations = ptr[0];
	g_Anims = g_RomAnims = (struct animtableentry *)&ptr[1];

	g_AnimMaxHeaderLength = 1;
	g_AnimMaxBytesPerFrame = 1;

	for (i = 0; i < g_NumAnimations; i++) {
		if (g_Anims[i].headerlen > g_AnimMaxHeaderLength) {
			g_AnimMaxHeaderLength = g_Anims[i].headerlen;
		}

		if (g_Anims[i].bytesperframe > g_AnimMaxBytesPerFrame) {
			g_AnimMaxBytesPerFrame = g_Anims[i].bytesperframe;
		}
	}

	g_AnimMaxHeaderLength = ALIGN16(g_AnimMaxHeaderLength + 34);
	g_AnimMaxBytesPerFrame = ALIGN16(g_AnimMaxBytesPerFrame + 34);

	g_AnimToHeaderSlot    = mempAlloc(ALIGN64(g_NumAnimations), MEMPOOL_PERMANENT);
	var8005f014           = mempAlloc(ALIGN64(g_NumAnimations * sizeof(*var8005f014)), MEMPOOL_PERMANENT);
	g_AnimFrameByteSlots  = mempAlloc(ALIGN64(ANIM_FRAME_CACHE_SIZE * g_AnimMaxBytesPerFrame), MEMPOOL_PERMANENT);
	g_AnimFrameBytes      = mempAlloc(ALIGN64(ANIM_FRAME_CACHE_SIZE * sizeof(*g_AnimFrameBytes)), MEMPOOL_PERMANENT);
	g_AnimFrameAnimNums   = mempAlloc(ALIGN64(ANIM_FRAME_CACHE_SIZE * sizeof(*g_AnimFrameAnimNums)), MEMPOOL_PERMANENT);
	g_AnimFrameFrameNums  = mempAlloc(ALIGN64(ANIM_FRAME_CACHE_SIZE * sizeof(*g_AnimFrameFrameNums)), MEMPOOL_PERMANENT);
	g_AnimFrameBirths     = mempAlloc(ALIGN64(ANIM_FRAME_CACHE_SIZE * sizeof(*g_AnimFrameBirths)), MEMPOOL_PERMANENT);
	g_AnimHeaderByteSlots = mempAlloc(ALIGN64(ANIM_HEADER_CACHE_SIZE * g_AnimMaxHeaderLength), MEMPOOL_PERMANENT);
	g_AnimHeaderBytes     = mempAlloc(ALIGN64(ANIM_HEADER_CACHE_SIZE * sizeof(*g_AnimHeaderBytes)), MEMPOOL_PERMANENT);
	g_AnimHeaderAnimNums  = mempAlloc(ALIGN64(ANIM_HEADER_CACHE_SIZE * sizeof(*g_AnimHeaderAnimNums)), MEMPOOL_PERMANENT);
	g_AnimHeaderBirths    = mempAlloc(ALIGN64(ANIM_HEADER_CACHE_SIZE * sizeof(*g_AnimHeaderBirths)), MEMPOOL_PERMANENT);

	animsInitTables();

	g_AnimHostSegment = NULL;
	g_AnimHostEnabled = false;
}

void animsInitTables(void)
{
	s32 i;

	for (i = 0; i < g_NumAnimations; i++) {
		g_AnimToHeaderSlot[i] = 0xff;
		var8005f014[i] = 0;
	}

	for (i = 0; i < ANIM_FRAME_CACHE_SIZE; i++) {
		g_AnimFrameAnimNums[i] = 0;
		g_AnimFrameFrameNums[i] = 0;
		g_AnimFrameBirths[i] = 0;
	}

	for (i = 0; i < ANIM_HEADER_CACHE_SIZE; i++) {
		g_AnimHeaderAnimNums[i] = 0;
		g_AnimHeaderBirths[i] = -2;
	}
}

void animsReset(void)
{
	g_NumAnimations = g_NumRomAnimations;
	g_Anims = g_RomAnims;
	g_AnimHostEnabled = false;
}

s32 animGetNumFrames(s16 animnum)
{
	return g_Anims[animnum].numframes;
}

bool animHasFrames(s16 animnum)
{
	return animnum < g_NumAnimations && g_Anims[animnum].numframes > 0;
}

s32 animGetNumAnimations(void)
{
	return g_NumAnimations;
}

extern u8 _animationsSegmentRomStart;

u8 *animDma(u8 *dst, u32 segoffset, u32 len)
{
	if (g_AnimHostEnabled) {
		bcopy(&g_AnimHostSegment[segoffset], dst, len);
		return dst;
	}

	return dmaExecWithAutoAlign(dst, (romptr_t) &_animationsSegmentRomStart + segoffset, len);
}

/**
 * Return -1 if the given apparent frame is a repeat frame, or if not a repeat
 * frame then remap the apparent frame to a real one and return it.
 *
 * The end of the header can contain a sequence of shorts such as:
 * -1, 55, 30
 *
 * The values are iterated backwards in pairs of 2 and are terminated by -1.
 *
 * In each pair, the right value is the repeatfromframe and the left value is
 * the repeattoframe. In the above example, apparent frames 30 to 55 are
 * repeated, so the remapping looks like:
 * 29 -> 29
 * 30 -> -1
 * ...
 * 55 -> -1
 * 56 -> 30
 * 57 -> 31
 */
s32 animGetRemappedFrame(s16 animnum, s32 apparentframe)
{
	u8 *ptr = (u8 *)(g_AnimHeaderBytes[g_AnimToHeaderSlot[animnum]] + g_Anims[animnum].headerlen - 2);
	s32 realframe = apparentframe;

	while (true) {
		s16 repeatfromframe = ptr[0] << 8 | ptr[1];
		s16 repeattoframe;

		if (repeatfromframe < 0) {
			break;
		}

		repeattoframe = ptr[-2] << 8 | ptr[-1];
		ptr -= 4;

		if (repeatfromframe <= apparentframe) {
			if (repeattoframe < apparentframe) {
				realframe = realframe - repeattoframe + repeatfromframe - 1;
			} else {
				realframe = -1;
				break;
			}
		}
	}

	return realframe;
}

/**
 * Similar to the above, but with the following differences:
 * - Write the remapped frame to the frameptr pointer instead of returning it.
 * - If the apparent frame is a repeat, write the original frame rather than -1.
 * - Return true if the frame is original or false if it's a repeat.
 */
bool animRemapFrameForLoad(s16 animnum, s32 apparentframe, s32 *frameptr)
{
	u8 *ptr = (u8 *)(g_AnimHeaderBytes[g_AnimToHeaderSlot[animnum]] + g_Anims[animnum].headerlen - 2);
	s32 result = apparentframe;
	bool ret = true;

	while (true) {
		s16 repeatfromframe = ptr[0] << 8 | ptr[1];
		s16 repeattoframe;

		if (repeatfromframe < 0) {
			break;
		}

		repeattoframe = ptr[-2] << 8 | ptr[-1];
		ptr -= 4;

		if (repeatfromframe <= apparentframe) {
			if (repeattoframe < apparentframe) {
				result = result - repeattoframe + repeatfromframe - 1;
			} else {
				result = result - apparentframe + repeatfromframe;
				ret = false;
				break;
			}
		}
	}

	*frameptr = result;

	return ret;
}

/**
 * Return true if the given animation and frame should be skipped.
 *
 * Used by cutscenes.
 *
 * The skip frame numbers are stored at the tail end of the header, prior to the
 * frame repeat data. The frame numbers are stored as a list of shorts.
 * The list is terminated on the left side with a negative value.
 */
bool animIsFrameCutSkipped(s16 animnum, s32 frame)
{
	u8 *ptr = (u8 *)(g_AnimHeaderBytes[g_AnimToHeaderSlot[animnum]] + g_Anims[animnum].headerlen - 2);

	// Iterate past the repeat list
	if (g_Anims[animnum].flags & ANIMFLAG_HASREPEATFRAMES) {
		while (true) {
			s16 repeatfromframe = ptr[0] << 8 | ptr[1];

			if (repeatfromframe < 0) {
				break;
			}

			ptr -= 4;
		}

		ptr -= 2;
	}

	while (true) {
		s16 skipframe = ptr[0] << 8 | ptr[1];

		if (skipframe < 0) {
			break;
		}

		if (skipframe == frame) {
			return true;
		}

		ptr -= 2;
	}

	return false;
}

u8 animLoadFrame(s16 animnum, s32 framenum)
{
	s32 slot = -1;
	s32 i;
	s32 offset;
	s32 stack;
	s32 loadframenum = framenum;

	for (i = 0; i < ANIM_FRAME_CACHE_SIZE; i++) {
		if (g_AnimFrameAnimNums[i] == animnum && g_AnimFrameFrameNums[i] == loadframenum) {
			slot = i;
			break;
		}
	}

	if (slot >= 0) {
		g_AnimFrameBirths[slot] = 1;
	} else {
		slot = g_NextAnimFrameIndex;

		while (g_AnimFrameBirths[slot]) {
			slot = (slot + 1) % ANIM_FRAME_CACHE_SIZE;
		}

		if (g_Anims[animnum].flags & ANIMFLAG_HASREPEATFRAMES) {
			animRemapFrameForLoad(animnum, framenum, &loadframenum);
		}

		if (g_Anims[animnum].bytesperframe) {
			offset = g_Anims[animnum].bytesperframe * loadframenum + (g_Anims[animnum].data + g_Anims[animnum].headerlen);
			g_AnimFrameBytes[slot] = animDma(&g_AnimFrameByteSlots[slot * g_AnimMaxBytesPerFrame], offset, g_Anims[animnum].bytesperframe);
		} else {
			g_AnimFrameBytes[slot] = &g_AnimFrameByteSlots[slot * g_AnimMaxBytesPerFrame];
		}

		g_AnimFrameAnimNums[slot] = animnum;
		g_AnimFrameFrameNums[slot] = framenum;
		g_AnimFrameBirths[slot] = 1;
		g_NextAnimFrameIndex = (slot + 1) % ANIM_FRAME_CACHE_SIZE;
	}

	return slot;
}

void animForgetFrameBirths(void)
{
	s32 i;

	for (i = 0; i < ANIM_FRAME_CACHE_SIZE; i++) {
		g_AnimFrameBirths[i] = 0;
	}
}

void animLoadHeader(s16 animnum)
{
	s32 i;

	if (g_AnimToHeaderSlot[animnum] != 0xff) {
		g_AnimHeaderBirths[g_AnimToHeaderSlot[animnum]] = g_Vars.thisframestart240;
		g_NextAnimHeaderIndex = (g_AnimToHeaderSlot[animnum] + 1) % ANIM_HEADER_CACHE_SIZE;
	} else {
		s32 tmp;
		s32 slot = g_NextAnimHeaderIndex;
		s32 stack;

		for (i = 0; i < ANIM_HEADER_CACHE_SIZE; i++) {
			if (g_AnimHeaderBirths[i] < g_AnimHeaderBirths[slot]) {
				slot = i;
			}
		}

		if (g_AnimHeaderBirths[slot]);
		if (&g_Vars && &g_Vars);

		if (g_AnimHeaderAnimNums[slot]) {
			g_AnimToHeaderSlot[g_AnimHeaderAnimNums[slot]] = 0xff;
		}

		tmp = g_Anims[animnum].headerlen;

		g_AnimHeaderBytes[slot] = animDma(&g_AnimHeaderByteSlots[slot * g_AnimMaxHeaderLength], g_Anims[animnum].data, tmp);
		g_AnimToHeaderSlot[animnum] = slot;
		g_AnimHeaderAnimNums[slot] = animnum;
		g_AnimHeaderBirths[slot] = g_Vars.thisframestart240;
		g_NextAnimHeaderIndex = (slot + 1) % ANIM_HEADER_CACHE_SIZE;
	}
}

#if MATCHING
GLOBAL_ASM(
glabel animReadBits
/*    23f50:	30cf0007 */ 	andi	$t7,$a2,0x7
/*    23f54:	24180008 */ 	addiu	$t8,$zero,0x8
/*    23f58:	030f4023 */ 	subu	$t0,$t8,$t7
/*    23f5c:	30a900ff */ 	andi	$t1,$a1,0xff
/*    23f60:	311900ff */ 	andi	$t9,$t0,0xff
/*    23f64:	000610c2 */ 	srl	$v0,$a2,0x3
/*    23f68:	0139082a */ 	slt	$at,$t1,$t9
/*    23f6c:	afa50004 */ 	sw	$a1,0x4($sp)
/*    23f70:	00001825 */ 	or	$v1,$zero,$zero
/*    23f74:	00822021 */ 	addu	$a0,$a0,$v0
/*    23f78:	1420000e */ 	bnez	$at,.L00023fb4
/*    23f7c:	310700ff */ 	andi	$a3,$t0,0xff
.L00023f80:
/*    23f80:	908b0000 */ 	lbu	$t3,0x0($a0)
/*    23f84:	240c0001 */ 	addiu	$t4,$zero,0x1
/*    23f88:	01272823 */ 	subu	$a1,$t1,$a3
/*    23f8c:	00ec6804 */ 	sllv	$t5,$t4,$a3
/*    23f90:	30a900ff */ 	andi	$t1,$a1,0xff
/*    23f94:	25aeffff */ 	addiu	$t6,$t5,-1
/*    23f98:	016e7824 */ 	and	$t7,$t3,$t6
/*    23f9c:	012fc004 */ 	sllv	$t8,$t7,$t1
/*    23fa0:	29210008 */ 	slti	$at,$t1,0x8
/*    23fa4:	00781825 */ 	or	$v1,$v1,$t8
/*    23fa8:	24840001 */ 	addiu	$a0,$a0,0x1
/*    23fac:	1020fff4 */ 	beqz	$at,.L00023f80
/*    23fb0:	24070008 */ 	addiu	$a3,$zero,0x8
.L00023fb4:
/*    23fb4:	19200008 */ 	blez	$t1,.L00023fd8
/*    23fb8:	00e95023 */ 	subu	$t2,$a3,$t1
/*    23fbc:	90990000 */ 	lbu	$t9,0x0($a0)
/*    23fc0:	240d0001 */ 	addiu	$t5,$zero,0x1
/*    23fc4:	012d5804 */ 	sllv	$t3,$t5,$t1
/*    23fc8:	256effff */ 	addiu	$t6,$t3,-1
/*    23fcc:	01596007 */ 	srav	$t4,$t9,$t2
/*    23fd0:	018e7824 */ 	and	$t7,$t4,$t6
/*    23fd4:	006f1825 */ 	or	$v1,$v1,$t7
.L00023fd8:
/*    23fd8:	03e00008 */ 	jr	$ra
/*    23fdc:	00601025 */ 	or	$v0,$v1,$zero
);
#else
// Mismatch: regalloc
s32 animReadBits(u8 *ptr, u8 readbitlen, u32 bitoffset)
{
	u32 result = 0;
	u8 numbitsthisbyte;
	u32 tmp;

	ptr += bitoffset / 8;
	numbitsthisbyte = 8 - (bitoffset % 8);

	while (readbitlen >= numbitsthisbyte) {
		readbitlen -= numbitsthisbyte;
		result |= (*ptr & ((1 << numbitsthisbyte) - 1)) << readbitlen;
		ptr++;
		numbitsthisbyte = 8;
	}

	if (readbitlen > 0) {
		result |= (*ptr >> (numbitsthisbyte - readbitlen)) & ((1 << readbitlen) - 1);
	}

	if (bitoffset / 8);

	return result;
}
#endif

s32 animReadSignedShort(u8 *ptr, u8 readbitlen, s32 bitoffset)
{
	u16 result = animReadBits(ptr, readbitlen, bitoffset);

	if (readbitlen < 16 && (result & (1 << (readbitlen - 1)))) {
		result |= ((1 << (16 - readbitlen)) - 1) << readbitlen;
	}

	return result;
}

/**
 * Read the rotation, position and scale values for the given part for the frame
 * at the given frameslot.
 *
 * Both the anim header and frame data must be loaded already.
 */
void animGetRotTranslateScale(s32 part, bool flip, struct skeleton *skel, s16 animnum, u8 frameslot, struct coord *rot, struct coord *translate, struct coord *scale)
{
	s32 i;
	u16 introt[3];
	u8 readbitlen;
	u8 *framebytes = g_AnimFrameBytes[frameslot];
	u8 framelen;
	u8 *ptr;
	u8 *end;
	s32 bitoffset;
	u32 stack;

	if (flip) {
		part = skel->things[part][1];
	}

	framelen = g_Anims[animnum].framelen;
	ptr = g_AnimHeaderBytes[g_AnimToHeaderSlot[animnum]];
	bitoffset = 0;
	end = ptr + g_Anims[animnum].headerlen;

	for (i = 0; i < part && ptr < end; i++) {
		u8 flags = *ptr;
		ptr++;

		if (flags & ANIMFIELD_08) {
			bitoffset += ptr[2] + ptr[5] + ptr[8] + ptr[11];
			ptr += 12;
		} else if (flags & ANIMFIELD_S16_TRANSLATE) {
			bitoffset += ptr[2] + ptr[5] + ptr[8];
			ptr += 9;
		} else if (flags & ANIMFIELD_S32_TRANSLATE) {
			bitoffset += ptr[0] + ptr[5] + ptr[10];
			ptr += 15;
		}

		if (flags & ANIMFIELD_S16_ROTATE) {
			bitoffset += ptr[2] + ptr[5] + ptr[8];
			ptr += 9;
		} else if (flags & ANIMFIELD_F32_ROTATE) {
			bitoffset += 96;
		}

		if (flags & ANIMFIELD_CAMERA) {
			bitoffset += ptr[0];
			ptr += 5;
		}

		if (flags & ANIMFIELD_F32_SCALE) {
			bitoffset += 0x60;
		}
	}

	if (ptr < end) {
		u8 flags = *ptr;
		ptr++;

		if (flags & ANIMFIELD_S16_TRANSLATE) {
			readbitlen = ptr[2];
			translate->x = (s16) (animReadSignedShort(framebytes, readbitlen, bitoffset) + (ptr[0] << 8) + ptr[1]);
			bitoffset += readbitlen;

			readbitlen = ptr[5];
			translate->y = (s16) (animReadSignedShort(framebytes, readbitlen, bitoffset) + (ptr[3] << 8) + ptr[4]);
			bitoffset += readbitlen;

			readbitlen = ptr[8];
			translate->z = (s16) (animReadSignedShort(framebytes, readbitlen, bitoffset) + (ptr[6] << 8) + ptr[7]);
			bitoffset += readbitlen;

			ptr += 9;
		} else if (flags & ANIMFIELD_S32_TRANSLATE) {
			readbitlen = ptr[0];
			translate->x = (animReadBits(framebytes, readbitlen, bitoffset) + ((ptr[1] << 24) + (ptr[2] << 16) + (ptr[3] << 8) + ptr[4])) * 0.001f;
			bitoffset += readbitlen;

			readbitlen = ptr[5];
			translate->y = (animReadBits(framebytes, readbitlen, bitoffset) + ((ptr[6] << 24) + (ptr[7] << 16) + (ptr[8] << 8) + ptr[9])) * 0.001f;
			bitoffset += readbitlen;

			readbitlen = ptr[10];
			translate->z = (animReadBits(framebytes, readbitlen, bitoffset) + ((ptr[11] << 24) + (ptr[12] << 16) + (ptr[13] << 8) + ptr[14])) * 0.001f;
			bitoffset += readbitlen;

			ptr += 15;
		} else {
			if (flags & ANIMFIELD_08) {
				bitoffset += ptr[2] + ptr[5] + ptr[8] + ptr[11];
				ptr += 12;
			}

			translate->x = translate->y = translate->z = 0.0f;
		}

		if (flags & ANIMFIELD_S16_ROTATE) {
			readbitlen = ptr[2];
			introt[0] = animReadBits(framebytes, readbitlen, bitoffset);
			introt[0] += (ptr[0] << 8) + ptr[1];
			introt[0] <<= 16 - framelen;
			bitoffset += readbitlen;

			readbitlen = ptr[5];
			introt[1] = animReadBits(framebytes, readbitlen, bitoffset);
			introt[1] += (ptr[3] << 8) + ptr[4];
			introt[1] <<= 16 - framelen;
			bitoffset += readbitlen;

			readbitlen = ptr[8];
			introt[2] = animReadBits(framebytes, readbitlen, bitoffset);
			introt[2] += (ptr[6] << 8) + ptr[7];
			introt[2] <<= 16 - framelen;
			bitoffset += readbitlen;

			rot->x = introt[0] * M_BADTAU / 65536.0f;

			if (flip) {
				if (introt[1] != 0) {
					rot->y = (0x10000 - introt[1]) * M_BADTAU / 65536.0f;
				} else {
					rot->y = 0.0f;
				}

				if (introt[2] != 0) {
					rot->z = (0x10000 - introt[2]) * M_BADTAU / 65536.0f;
				} else {
					rot->z = 0.0f;
				}
			} else {
				rot->y = introt[1] * M_BADTAU / 65536.0f;
				rot->z = introt[2] * M_BADTAU / 65536.0f;
			}
		} else if (flags & ANIMFIELD_F32_ROTATE) {
			s32 sp38;

			sp38 = animReadBits(framebytes, 32, bitoffset);
			rot->x = *(f32 *)&sp38;
			bitoffset += 32;

			sp38 = animReadBits(framebytes, 32, bitoffset);
			rot->y = *(f32 *)&sp38;
			bitoffset += 32;

			sp38 = animReadBits(framebytes, 32, bitoffset);
			rot->z = *(f32 *)&sp38;
			bitoffset += 32;

			if (flip) {
				if (rot->y != 0.0f) {
					rot->y = M_BADTAU - rot->y;
				}

				if (rot->z != 0.0f) {
					rot->z = M_BADTAU - rot->z;
				}
			}
		} else {
			rot->x = rot->y = rot->z = 0.0f;
		}

		if (flags & ANIMFIELD_F32_SCALE) {
			s32 word;

			word = animReadBits(framebytes, 32, bitoffset);
			scale->x = *(f32 *)&word;
			bitoffset += 32;

			word = animReadBits(framebytes, 32, bitoffset);
			scale->y = *(f32 *)&word;
			bitoffset += 32;

			word = animReadBits(framebytes, 32, bitoffset);
			scale->z = *(f32 *)&word;
		} else {
			scale->x = scale->y = scale->z = 1.0f;
		}

		return;
	}

	rot->x = rot->y = rot->z = 0.0f;
	translate->x = translate->y = translate->z = 0.0f;
	scale->x = scale->y = scale->z = 1.0f;
}

/**
 * Read the position and Y rotation (?) values for the given part at the given
 * frame number.
 *
 * No data needs to be loaded by the caller - the function will ensure the
 * header and frame are loaded.
 */
u16 animGetPosAngleAsInt(s32 part, bool flip, struct skeleton *skel, s16 animnum, s32 framenum, s16 inttranslate[3], bool arg6)
{
	u16 result = 0;
	s32 bitoffset;
	u8 readbitlen;
	u8 slot;
	u8 *framebytes;
	u8 *ptr;
	s32 i;

	if (arg6) {
		inttranslate[0] = 0;
		inttranslate[1] = 0;
		inttranslate[2] = var8005f014[animnum];
	} else {
		animLoadHeader(animnum);
		slot = animLoadFrame(animnum, framenum);
		animForgetFrameBirths();

		framebytes = g_AnimFrameBytes[slot];

		if (flip) {
			part = skel->things[part][1];
		}

		bitoffset = 0;
		ptr = g_AnimHeaderBytes[g_AnimToHeaderSlot[animnum]];

		for (i = 0; i < part; i++) {
			u8 flags = *ptr;
			ptr++;

			if (flags & ANIMFIELD_08) {
				bitoffset += ptr[2] + ptr[5] + ptr[8] + ptr[11];
				ptr += 12;
			} else if (flags & ANIMFIELD_S16_TRANSLATE) {
				bitoffset += ptr[2] + ptr[5] + ptr[8];
				ptr += 9;
			} else if (flags & ANIMFIELD_S32_TRANSLATE) {
				bitoffset += ptr[0] + ptr[5] + ptr[10];
				ptr += 15;
			}

			if (flags & ANIMFIELD_S16_ROTATE) {
				bitoffset += ptr[2] + ptr[5] + ptr[8];
				ptr += 9;
			} else if (flags & ANIMFIELD_F32_ROTATE) {
				bitoffset += 96;
			}

			if (flags & ANIMFIELD_CAMERA) {
				bitoffset += *ptr;
				ptr += 5;
			}

			if (flags & ANIMFIELD_F32_SCALE) {
				bitoffset += 96;
			}
		}

		readbitlen = ptr[3];
		inttranslate[0] = animReadSignedShort(framebytes, readbitlen, bitoffset) + ptr[1] * 256 + ptr[2];
		bitoffset += readbitlen;

		readbitlen = ptr[6];
		inttranslate[1] = animReadSignedShort(framebytes, readbitlen, bitoffset) + ptr[4] * 256 + ptr[5];
		bitoffset += readbitlen;

		readbitlen = ptr[9];
		inttranslate[2] = animReadSignedShort(framebytes, readbitlen, bitoffset) + ptr[7] * 256 + ptr[8];
		bitoffset += readbitlen;

		readbitlen = ptr[12];
		result = animReadSignedShort(framebytes, readbitlen, bitoffset) + ptr[10] * 256 + ptr[11];

		if (flip) {
			inttranslate[0] = -inttranslate[0];

			if (result != 0) {
				result = 0x10000 - result;
			}
		}
	}

	return result;
}

f32 animGetTranslateAngle(s32 part, bool flip, struct skeleton *skel, s16 animnum, s32 framenum, struct coord *translate, bool arg6)
{
	s16 inttranslate[3];

	f32 angle = animGetPosAngleAsInt(part, flip, skel, animnum, framenum, inttranslate, arg6);

	translate->x = inttranslate[0];
	translate->y = inttranslate[1];
	translate->z = inttranslate[2];

	return angle * M_BADTAU / 65536.0f;
}

/**
 * Return a camera value (FOV Y or blur frac) for the current frame.
 *
 * The function assumes the current frame's data has been loaded.
 * Its slot is provided by the frameslot argument.
 *
 * When part = 1, the returned value is the FOV Y.
 * When part = 2, the returned value is the blur frac.
 */
f32 animGetCameraValue(s32 part, s16 animnum, u8 frameslot)
{
	u32 stack[2];
	u8 *framebytes = g_AnimFrameBytes[frameslot];
	u8 *ptr = g_AnimHeaderBytes[g_AnimToHeaderSlot[animnum]];
	f32 result = 0;
	s32 bitoffset = 0;
	s32 i;
	u8 *end = ptr + g_Anims[animnum].headerlen;

	for (i = 0; i < part && ptr < end; i++) {
		u8 flags = ptr[0];
		ptr++;

		if (flags & ANIMFIELD_08) {
			bitoffset += ptr[2] + ptr[5] + ptr[8] + ptr[11];
			ptr += 12;
		} else if (flags & ANIMFIELD_S16_TRANSLATE) {
			bitoffset += ptr[2] + ptr[5] + ptr[8];
			ptr += 9;
		} else if (flags & ANIMFIELD_S32_TRANSLATE) {
			bitoffset += ptr[0] + ptr[5] + ptr[10];
			ptr += 15;
		}

		if (flags & ANIMFIELD_S16_ROTATE) {
			bitoffset += ptr[2] + ptr[5] + ptr[8];
			ptr += 9;
		} else if (flags & ANIMFIELD_F32_ROTATE) {
			bitoffset += 0x60;
		}

		if (flags & ANIMFIELD_CAMERA) {
			bitoffset += ptr[0];
			ptr += 5;
		}

		if (flags & ANIMFIELD_F32_SCALE) {
			bitoffset += 0x60;
		}
	}

	if (ptr < end) {
		u8 flags = ptr[0];
		ptr++;

		if (flags & ANIMFIELD_CAMERA) {
			/**
			 * In the header:
			 * ptr[0] = number of bits to read in the frame data
			 * ptr[1,2,3,4] = base value
			 *
			 * The value in the frame data is an adjustment value that is added
			 * to the base value.
			 */
			s32 framevalue = animReadBits(framebytes, ptr[0], bitoffset);
			result = (framevalue + ptr[1] * 0x1000000 + ptr[2] * 0x10000 + ptr[3] * 0x100 + ptr[4]) * 0.001f;
		}
	}

	return result;
}
