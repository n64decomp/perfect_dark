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

u8 *var8009a870;
u8 **var8009a874;
s16 *var8009a878;
s16 *var8009a87c;
u8 *var8009a880;
u8 *var8009a884;
u8 **var8009a888;
s16 *var8009a88c;
s32 *var8009a890;
s16 var8009a894;
struct animsummary *var8009a898;

u32 var8005f000 = 0;
s32 var8005f004 = 0;
s16 g_NumAnimations = 0;
struct animsummary *g_Anims = NULL;
u8 *var8005f010 = NULL;
s16 *var8005f014 = NULL;
s32 var8005f018 = 176;
s32 var8005f01c = 608;
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
	dmaExec(ptr, (s32)&_animationsTableRomStart, tablelen);

	g_NumAnimations = var8009a894 = ptr[0];
	g_Anims = var8009a898 = (struct animsummary *)&ptr[1];

	var8005f01c = 1;
	var8005f018 = 1;

	for (i = 0; i < g_NumAnimations; i++) {
		if (g_Anims[i].headerlen > var8005f01c) {
			var8005f01c = g_Anims[i].headerlen;
		}

		if (g_Anims[i].bytesperframe > var8005f018) {
			var8005f018 = g_Anims[i].bytesperframe;
		}
	}

	var8005f01c = ALIGN16(var8005f01c + 34);
	var8005f018 = ALIGN16(var8005f018 + 34);

	var8005f010 = mempAlloc(ALIGN64(g_NumAnimations), MEMPOOL_PERMANENT);
	var8005f014 = mempAlloc(ALIGN64(g_NumAnimations * 2), MEMPOOL_PERMANENT);
	var8009a870 = mempAlloc(ALIGN64(var8005f018 * 0x20), MEMPOOL_PERMANENT);
	var8009a874 = mempAlloc(0x80, MEMPOOL_PERMANENT);
	var8009a878 = mempAlloc(0x40, MEMPOOL_PERMANENT);
	var8009a87c = mempAlloc(0x40, MEMPOOL_PERMANENT);
	var8009a880 = mempAlloc(0x40, MEMPOOL_PERMANENT);
	var8009a884 = mempAlloc(ALIGN64(var8005f01c * 40), MEMPOOL_PERMANENT);
	var8009a888 = mempAlloc(0xc0, MEMPOOL_PERMANENT);
	var8009a88c = mempAlloc(0x80, MEMPOOL_PERMANENT);
	var8009a890 = mempAlloc(0xc0, MEMPOOL_PERMANENT);

	for (i = 0; i < g_NumAnimations; i++) {
		var8005f010[i] = 0xff;
		var8005f014[i] = 0;
	}

	for (i = 0; i < 32; i++) {
		var8009a878[i] = 0;
		var8009a87c[i] = 0;
		var8009a880[i] = 0;
	}

	for (i = 0; i < 40; i++) {
		var8009a88c[i] = 0;
		var8009a890[i] = -2;
	}

	g_AnimHostSegment = NULL;
	g_AnimHostEnabled = false;
}

void animsReset(void)
{
	g_NumAnimations = var8009a894;
	g_Anims = var8009a898;
	g_AnimHostEnabled = false;
}

extern u8 _animationsSegmentRomStart;

static u8 *animDma(u8 *dst, u32 segoffset, u32 len)
{
	if (g_AnimHostEnabled) {
		bcopy(&g_AnimHostSegment[segoffset], dst, len);
		return dst;
	}

	return dmaExecWithAutoAlign(dst, (u32)&_animationsSegmentRomStart + segoffset, len);
}

s32 anim0002384c(s16 animnum, s32 frame)
{
	u8 *ptr = (u8 *)(var8009a888[var8005f010[animnum]] + g_Anims[animnum].headerlen - 2);
	s32 result = frame;

	while (true) {
		s16 value1 = ptr[0] << 8 | ptr[1];
		s16 value2;

		if (value1 < 0) {
			break;
		}

		value2 = ptr[-2] << 8 | ptr[-1];
		ptr -= 4;

		if (value1 <= frame) {
			if (value2 < frame) {
				result = result - value2 + value1 - 1;
			} else {
				result = -1;
				break;
			}
		}
	}

	return result;
}

static bool anim00023908(s16 animnum, s32 frame, s32 *frameptr)
{
	u8 *ptr = (u8 *)(var8009a888[var8005f010[animnum]] + g_Anims[animnum].headerlen - 2);
	s32 result = frame;
	bool ret = true;

	while (true) {
		s16 value1 = ptr[0] << 8 | ptr[1];

		if (value1 >= 0) {
			s16 value2 = ptr[-2] << 8 | ptr[-1];
			ptr -= 4;

			if (value1 <= frame) {
				if (value2 < frame) {
					result = result - value2 + value1 - 1;
					continue;
				}

				result = result - frame + value1;
				ret = false;
				break;
			}
		} else {
			break;
		}
	}

	*frameptr = result;

	return ret;
}

bool anim000239e0(s16 animnum, s32 frame)
{
	u8 *ptr = (u8 *)(var8009a888[var8005f010[animnum]] + g_Anims[animnum].headerlen - 2);

	if (g_Anims[animnum].flags & ANIMFLAG_04) {
		while (true) {
			s16 value1 = ptr[0] << 8 | ptr[1];

			if (value1 < 0) {
				break;
			}

			ptr -= 4;
		}

		ptr -= 2;
	}

	while (true) {
		s16 value2 = ptr[0] << 8 | ptr[1];

		if (value2 < 0) {
			break;
		}

		if (value2 == frame) {
			return true;
		}

		ptr -= 2;
	}

	return false;
}

u8 anim00023ab0(s16 animnum, s32 framenum)
{
	s32 index = -1;
	s32 i;
	s32 offset;
	s32 stack;
	s32 sp2c = framenum;

	for (i = 0; i < 32; i++) {
		if (var8009a878[i] == animnum && var8009a87c[i] == sp2c) {
			index = i;
			break;
		}
	}

	if (index >= 0) {
		var8009a880[index] = 1;
	} else {
		index = var8005f000;

		while (var8009a880[index]) {
			index = (index + 1) % 32;
		}

		if (g_Anims[animnum].flags & ANIMFLAG_04) {
			anim00023908(animnum, framenum, &sp2c);
		}

		if (g_Anims[animnum].bytesperframe) {
			offset = g_Anims[animnum].bytesperframe * sp2c + (g_Anims[animnum].data + g_Anims[animnum].headerlen);
			var8009a874[index] = animDma(&var8009a870[index * var8005f018], offset, g_Anims[animnum].bytesperframe);
		} else {
			var8009a874[index] = &var8009a870[index * var8005f018];
		}

		var8009a878[index] = animnum;
		var8009a87c[index] = framenum;
		var8009a880[index] = 1;
		var8005f000 = (index + 1) % 32;
	}

	return index;
}

void anim00023d0c(void)
{
	s32 i;

	for (i = 0; i < 32; i++) {
		var8009a880[i] = 0;
	}
}

void anim00023d38(s16 animnum)
{
	s32 i;

	if (var8005f010[animnum] != 0xff) {
		var8009a890[var8005f010[animnum]] = g_Vars.thisframestart240;
		var8005f004 = var8005f010[animnum] + 1;
		WRAP(var8005f004, 40);
	} else {
		s32 tmp;
		s32 bestindex = var8005f004;
		s32 stack;

		for (i = 0; i < 40; i++) {
			if (var8009a890[i] < var8009a890[bestindex]) {
				bestindex = i;
			}
		}

		if (var8009a890[bestindex]);
		if (&g_Vars && &g_Vars);

		if (var8009a88c[bestindex]) {
			var8005f010[var8009a88c[bestindex]] = 0xff;
		}

		tmp = g_Anims[animnum].headerlen;

		var8009a888[bestindex] = animDma(&var8009a884[bestindex * var8005f01c], g_Anims[animnum].data, tmp);
		var8005f010[animnum] = bestindex;
		var8009a88c[bestindex] = animnum;
		var8009a890[bestindex] = g_Vars.thisframestart240;
		var8005f004 = bestindex + 1;
		WRAP(var8005f004, 40);
	}
}

static s32 anim00023f50(u8 *arg0, u8 arg1, u32 arg2)
{
	u32 result = 0;
	u8 numbits;
	u32 tmp;

	arg0 += arg2 / 8;
	numbits = 8 - (arg2 % 8);

	while (arg1 >= numbits) {
		arg1 -= numbits;
		result |= (*arg0 & ((1 << numbits) - 1)) << arg1;
		arg0++;
		numbits = 8;
	}

	if (arg1 > 0) {
		result |= (*arg0 >> (numbits - arg1)) & ((1 << arg1) - 1);
	}

	if (arg2 / 8);

	return result;
}

static s32 anim00023fe0(u8 *arg0, u8 arg1, s32 arg2)
{
	u16 result = anim00023f50(arg0, arg1, arg2);

	if (arg1 < 16 && (result & (1 << (arg1 - 1)))) {
		result |= ((1 << (16 - arg1)) - 1) << arg1;
	}

	return result;
}

void anim00024050(s32 arg0, bool flip, struct skeleton *skel, s16 animnum, u8 arg4, struct coord *arg5, struct coord *arg6, struct coord *arg7)
{
	s32 i;
	u16 sp5c[3];
	u8 sp5b;
	u8 *sp54 = var8009a874[arg4];
	u8 bitsperentry;
	u8 *ptr;
	u8 *end;
	s32 sum;
	u32 stack;

	if (flip) {
		arg0 = skel->things[arg0][1];
	}

	bitsperentry = g_Anims[animnum].initialposbitsperentry;
	ptr = var8009a888[var8005f010[animnum]];
	sum = 0;
	end = ptr + g_Anims[animnum].headerlen;

	for (i = 0; i < arg0 && ptr < end; i++) {
		u8 flags = *ptr;
		ptr++;

		if (flags & 0x08) {
			sum += ptr[2] + ptr[5] + ptr[8] + ptr[11];
			ptr += 12;
		} else if (flags & 0x02) {
			sum += ptr[2] + ptr[5] + ptr[8];
			ptr += 9;
		} else if (flags & 0x20) {
			sum += ptr[0] + ptr[5] + ptr[10];
			ptr += 15;
		}

		if (flags & 0x01) {
			sum += ptr[2] + ptr[5] + ptr[8];
			ptr += 9;
		} else if (flags & 0x10) {
			sum += 96;
		}

		if (flags & 0x40) {
			sum += ptr[0];
			ptr += 5;
		}

		if (flags & 0x80) {
			sum += 0x60;
		}
	}

	if (ptr < end) {
		u8 flags = *ptr;
		ptr++;

		if (flags & 0x02) {
			sp5b = ptr[2];
			arg6->x = (s16) (anim00023fe0(sp54, sp5b, sum) + (ptr[0] << 8) + ptr[1]);
			sum += sp5b;

			sp5b = ptr[5];
			arg6->y = (s16) (anim00023fe0(sp54, sp5b, sum) + (ptr[3] << 8) + ptr[4]);
			sum += sp5b;

			sp5b = ptr[8];
			arg6->z = (s16) (anim00023fe0(sp54, sp5b, sum) + (ptr[6] << 8) + ptr[7]);
			sum += sp5b;

			ptr += 9;
		} else if (flags & 0x20) {
			sp5b = ptr[0];
			arg6->x = (anim00023f50(sp54, sp5b, sum) + ((ptr[1] << 24) + (ptr[2] << 16) + (ptr[3] << 8) + ptr[4])) * 0.001f;
			sum += sp5b;

			sp5b = ptr[5];
			arg6->y = (anim00023f50(sp54, sp5b, sum) + ((ptr[6] << 24) + (ptr[7] << 16) + (ptr[8] << 8) + ptr[9])) * 0.001f;
			sum += sp5b;

			sp5b = ptr[10];
			arg6->z = (anim00023f50(sp54, sp5b, sum) + ((ptr[11] << 24) + (ptr[12] << 16) + (ptr[13] << 8) + ptr[14])) * 0.001f;
			sum += sp5b;

			ptr += 15;
		} else {
			if (flags & 0x08) {
				sum += ptr[2] + ptr[5] + ptr[8] + ptr[11];
				ptr += 12;
			}

			arg6->x = arg6->y = arg6->z = 0.0f;
		}

		if (flags & 0x01) {
			sp5b = ptr[2];
			sp5c[0] = anim00023f50(sp54, sp5b, sum);
			sp5c[0] += (ptr[0] << 8) + ptr[1];
			sp5c[0] <<= 16 - bitsperentry;
			sum += sp5b;

			sp5b = ptr[5];
			sp5c[1] = anim00023f50(sp54, sp5b, sum);
			sp5c[1] += (ptr[3] << 8) + ptr[4];
			sp5c[1] <<= 16 - bitsperentry;
			sum += sp5b;

			sp5b = ptr[8];
			sp5c[2] = anim00023f50(sp54, sp5b, sum);
			sp5c[2] += (ptr[6] << 8) + ptr[7];
			sp5c[2] <<= 16 - bitsperentry;
			sum += sp5b;

			arg5->x = sp5c[0] * M_BADTAU / 65536.0f;

			if (flip) {
				if (sp5c[1] != 0) {
					arg5->y = (0x10000 - sp5c[1]) * M_BADTAU / 65536.0f;
				} else {
					arg5->y = 0.0f;
				}

				if (sp5c[2] != 0) {
					arg5->z = (0x10000 - sp5c[2]) * M_BADTAU / 65536.0f;
				} else {
					arg5->z = 0.0f;
				}
			} else {
				arg5->y = sp5c[1] * M_BADTAU / 65536.0f;
				arg5->z = sp5c[2] * M_BADTAU / 65536.0f;
			}
		} else if (flags & 0x10) {
			s32 sp38;

			sp38 = anim00023f50(sp54, 32, sum);
			arg5->x = *(f32 *)&sp38;
			sum += 32;

			sp38 = anim00023f50(sp54, 32, sum);
			arg5->y = *(f32 *)&sp38;
			sum += 32;

			sp38 = anim00023f50(sp54, 32, sum);
			arg5->z = *(f32 *)&sp38;
			sum += 32;

			if (flip) {
				if (arg5->y != 0.0f) {
					arg5->y = M_BADTAU - arg5->y;
				}

				if (arg5->z != 0.0f) {
					arg5->z = M_BADTAU - arg5->z;
				}
			}
		} else {
			arg5->x = arg5->y = arg5->z = 0.0f;
		}

		if (flags & 0x80) {
			s32 sp34;

			sp34 = anim00023f50(sp54, 32, sum);
			arg7->x = *(f32 *)&sp34;
			sum += 32;

			sp34 = anim00023f50(sp54, 32, sum);
			arg7->y = *(f32 *)&sp34;
			sum += 32;

			sp34 = anim00023f50(sp54, 32, sum);
			arg7->z = *(f32 *)&sp34;
		} else {
			arg7->x = arg7->y = arg7->z = 1.0f;
		}

		return;
	}

	arg5->x = arg5->y = arg5->z = 0.0f;
	arg6->x = arg6->y = arg6->z = 0.0f;
	arg7->x = arg7->y = arg7->z = 1.0f;
}

u16 anim0002485c(s32 arg0, bool arg1, struct skeleton *skel, s16 animnum, s32 loopframe, s16 *arg5, bool arg6)
{
	u16 result = 0;
	s32 sum;
	u8 sp2f;
	u8 index;
	u8 *sp28;
	u8 *ptr;
	s32 i;

	if (arg6) {
		arg5[0] = 0;
		arg5[1] = 0;
		arg5[2] = var8005f014[animnum];
	} else {
		anim00023d38(animnum);
		index = anim00023ab0(animnum, loopframe);
		anim00023d0c();

		sp28 = var8009a874[index];

		if (arg1) {
			arg0 = skel->things[arg0][1];
		}

		// This is iterating the header information in the animation's data
		sum = 0;
		ptr = var8009a888[var8005f010[animnum]];

		for (i = 0; i < arg0; i++) {
			u8 flags = *ptr;
			ptr++;

			if (flags & 0x08) {
				sum += ptr[2] + ptr[5] + ptr[8] + ptr[11];
				ptr += 12;
			} else if (flags & 0x02) {
				sum += ptr[2] + ptr[5] + ptr[8];
				ptr += 9;
			} else if (flags & 0x20) {
				sum += ptr[0] + ptr[5] + ptr[10];
				ptr += 15;
			}

			if (flags & 0x01) {
				sum += ptr[2] + ptr[5] + ptr[8];
				ptr += 9;
			} else if (flags & 0x10) {
				sum += 96;
			}

			if (flags & 0x40) {
				sum += *ptr;
				ptr += 5;
			}

			if (flags & 0x80) {
				sum += 96;
			}
		}

		sp2f = ptr[3];
		arg5[0] = anim00023fe0(sp28, sp2f, sum) + ptr[1] * 256 + ptr[2];
		sum += sp2f;

		sp2f = ptr[6];
		arg5[1] = anim00023fe0(sp28, sp2f, sum) + ptr[4] * 256 + ptr[5];
		sum += sp2f;

		sp2f = ptr[9];
		arg5[2] = anim00023fe0(sp28, sp2f, sum) + ptr[7] * 256 + ptr[8];
		sum += sp2f;

		sp2f = ptr[12];
		result = anim00023fe0(sp28, sp2f, sum) + ptr[10] * 256 + ptr[11];

		if (arg1) {
			arg5[0] = -arg5[0];

			if (result != 0) {
				result = 0x10000 - result;
			}
		}
	}

	return result;
}

f32 anim00024b64(u32 arg0, u32 arg1, struct skeleton *arg2, s16 animnum, u32 arg4, struct coord *coord, u32 arg6)
{
	s16 sp30[3];

	f32 value = anim0002485c(arg0, arg1, arg2, animnum, arg4, sp30, arg6);

	coord->x = sp30[0];
	coord->y = sp30[1];
	coord->z = sp30[2];

	return value * M_BADTAU / 65536.0f;
}

f32 anim00024c14(s32 arg0, s16 animnum, u8 arg2)
{
	u32 stack[2];
	u8 *sp24 = var8009a874[arg2];
	u8 *ptr = var8009a888[var8005f010[animnum]];
	f32 result = 0;
	s32 total = 0;
	s32 i;
	u8 *end = ptr + g_Anims[animnum].headerlen;

	for (i = 0; i < arg0 && ptr < end; i++) {
		u8 flags = ptr[0];
		ptr++;

		if (flags & ANIMHEADERFLAG_08) {
			total += ptr[2] + ptr[5] + ptr[8] + ptr[11];
			ptr += 12;
		} else if (flags & ANIMHEADERFLAG_02) {
			total += ptr[2] + ptr[5] + ptr[8];
			ptr += 9;
		} else if (flags & ANIMHEADERFLAG_20) {
			total += ptr[0] + ptr[5] + ptr[10];
			ptr += 15;
		}

		if (flags & ANIMHEADERFLAG_01) {
			total += ptr[2] + ptr[5] + ptr[8];
			ptr += 9;
		} else if (flags & ANIMHEADERFLAG_10) {
			total += 0x60;
		}

		if (flags & ANIMHEADERFLAG_40) {
			total += ptr[0];
			ptr += 5;
		}

		if (flags & ANIMHEADERFLAG_80) {
			total += 0x60;
		}
	}

	if (ptr < end) {
		u8 flags = ptr[0];
		ptr++;

		if (flags & ANIMHEADERFLAG_40) {
			total = anim00023f50(sp24, ptr[0], total);
			result = (total + ptr[1] * 0x1000000 + ptr[2] * 0x10000 + ptr[3] * 0x100 + ptr[4]) * 0.001f;
		}
	}

	return result;
}
