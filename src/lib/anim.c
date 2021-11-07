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
s32 *var8009a888;
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

	animsInitTables();

	g_AnimHostSegment = NULL;
	g_AnimHostEnabled = false;
}

void animsInitTables(void)
{
	s32 i;

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
}

void anim0002373c(void)
{
	g_NumAnimations = var8009a894;
	g_Anims = var8009a898;
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

bool anim00023908(s16 animnum, s32 frame, s32 *frameptr)
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

GLOBAL_ASM(
glabel anim00023ab0
/*    23ab0:	27bdffc0 */ 	addiu	$sp,$sp,-64
/*    23ab4:	afb10018 */ 	sw	$s1,0x18($sp)
/*    23ab8:	00048c00 */ 	sll	$s1,$a0,0x10
/*    23abc:	00117403 */ 	sra	$t6,$s1,0x10
/*    23ac0:	afb00014 */ 	sw	$s0,0x14($sp)
/*    23ac4:	afa40040 */ 	sw	$a0,0x40($sp)
/*    23ac8:	3c06800a */ 	lui	$a2,%hi(var8009a878)
/*    23acc:	3c08800a */ 	lui	$t0,%hi(var8009a87c)
/*    23ad0:	00a08025 */ 	or	$s0,$a1,$zero
/*    23ad4:	01c08825 */ 	or	$s1,$t6,$zero
/*    23ad8:	afbf001c */ 	sw	$ra,0x1c($sp)
/*    23adc:	2407ffff */ 	addiu	$a3,$zero,-1
/*    23ae0:	afa5002c */ 	sw	$a1,0x2c($sp)
/*    23ae4:	2508a87c */ 	addiu	$t0,$t0,%lo(var8009a87c)
/*    23ae8:	8cc6a878 */ 	lw	$a2,%lo(var8009a878)($a2)
/*    23aec:	24040020 */ 	addiu	$a0,$zero,0x20
/*    23af0:	00001025 */ 	or	$v0,$zero,$zero
/*    23af4:	00001825 */ 	or	$v1,$zero,$zero
.L00023af8:
/*    23af8:	84cf0000 */ 	lh	$t7,0x0($a2)
/*    23afc:	24c60002 */ 	addiu	$a2,$a2,0x2
/*    23b00:	562f0009 */ 	bnel	$s1,$t7,.L00023b28
/*    23b04:	24420001 */ 	addiu	$v0,$v0,0x1
/*    23b08:	8d180000 */ 	lw	$t8,0x0($t0)
/*    23b0c:	0303c821 */ 	addu	$t9,$t8,$v1
/*    23b10:	872a0000 */ 	lh	$t2,0x0($t9)
/*    23b14:	560a0004 */ 	bnel	$s0,$t2,.L00023b28
/*    23b18:	24420001 */ 	addiu	$v0,$v0,0x1
/*    23b1c:	10000004 */ 	b	.L00023b30
/*    23b20:	00403825 */ 	or	$a3,$v0,$zero
/*    23b24:	24420001 */ 	addiu	$v0,$v0,0x1
.L00023b28:
/*    23b28:	1444fff3 */ 	bne	$v0,$a0,.L00023af8
/*    23b2c:	24630002 */ 	addiu	$v1,$v1,0x2
.L00023b30:
/*    23b30:	04e00007 */ 	bltz	$a3,.L00023b50
/*    23b34:	3c02800a */ 	lui	$v0,%hi(var8009a880)
/*    23b38:	3c0c800a */ 	lui	$t4,%hi(var8009a880)
/*    23b3c:	8d8ca880 */ 	lw	$t4,%lo(var8009a880)($t4)
/*    23b40:	240b0001 */ 	addiu	$t3,$zero,0x1
/*    23b44:	01876821 */ 	addu	$t5,$t4,$a3
/*    23b48:	1000006a */ 	b	.L00023cf4
/*    23b4c:	a1ab0000 */ 	sb	$t3,0x0($t5)
.L00023b50:
/*    23b50:	3c078006 */ 	lui	$a3,%hi(var8005f000)
/*    23b54:	8ce7f000 */ 	lw	$a3,%lo(var8005f000)($a3)
/*    23b58:	8c42a880 */ 	lw	$v0,%lo(var8009a880)($v0)
/*    23b5c:	00112400 */ 	sll	$a0,$s1,0x10
/*    23b60:	00114880 */ 	sll	$t1,$s1,0x2
/*    23b64:	00477021 */ 	addu	$t6,$v0,$a3
/*    23b68:	91cf0000 */ 	lbu	$t7,0x0($t6)
/*    23b6c:	00047403 */ 	sra	$t6,$a0,0x10
/*    23b70:	3c0c8006 */ 	lui	$t4,%hi(g_Anims)
/*    23b74:	11e0000c */ 	beqz	$t7,.L00023ba8
/*    23b78:	01c02025 */ 	or	$a0,$t6,$zero
/*    23b7c:	24e70001 */ 	addiu	$a3,$a3,0x1
.L00023b80:
/*    23b80:	04e10004 */ 	bgez	$a3,.L00023b94
/*    23b84:	30f8001f */ 	andi	$t8,$a3,0x1f
/*    23b88:	13000002 */ 	beqz	$t8,.L00023b94
/*    23b8c:	00000000 */ 	nop
/*    23b90:	2718ffe0 */ 	addiu	$t8,$t8,-32
.L00023b94:
/*    23b94:	0058c821 */ 	addu	$t9,$v0,$t8
/*    23b98:	932a0000 */ 	lbu	$t2,0x0($t9)
/*    23b9c:	03003825 */ 	or	$a3,$t8,$zero
/*    23ba0:	5540fff7 */ 	bnezl	$t2,.L00023b80
/*    23ba4:	24e70001 */ 	addiu	$a3,$a3,0x1
.L00023ba8:
/*    23ba8:	8d8cf00c */ 	lw	$t4,%lo(g_Anims)($t4)
/*    23bac:	01314823 */ 	subu	$t1,$t1,$s1
/*    23bb0:	00094880 */ 	sll	$t1,$t1,0x2
/*    23bb4:	01891821 */ 	addu	$v1,$t4,$t1
/*    23bb8:	906b000b */ 	lbu	$t3,0xb($v1)
/*    23bbc:	02002825 */ 	or	$a1,$s0,$zero
/*    23bc0:	27a6002c */ 	addiu	$a2,$sp,0x2c
/*    23bc4:	316d0004 */ 	andi	$t5,$t3,0x4
/*    23bc8:	51a0000c */ 	beqzl	$t5,.L00023bfc
/*    23bcc:	94660002 */ 	lhu	$a2,0x2($v1)
/*    23bd0:	afa7003c */ 	sw	$a3,0x3c($sp)
/*    23bd4:	0c008e42 */ 	jal	anim00023908
/*    23bd8:	afa90028 */ 	sw	$t1,0x28($sp)
/*    23bdc:	3c0f8006 */ 	lui	$t7,%hi(g_Anims)
/*    23be0:	8deff00c */ 	lw	$t7,%lo(g_Anims)($t7)
/*    23be4:	8fa90028 */ 	lw	$t1,0x28($sp)
/*    23be8:	3c08800a */ 	lui	$t0,%hi(var8009a87c)
/*    23bec:	2508a87c */ 	addiu	$t0,$t0,%lo(var8009a87c)
/*    23bf0:	8fa7003c */ 	lw	$a3,0x3c($sp)
/*    23bf4:	01e91821 */ 	addu	$v1,$t7,$t1
/*    23bf8:	94660002 */ 	lhu	$a2,0x2($v1)
.L00023bfc:
/*    23bfc:	8fac002c */ 	lw	$t4,0x2c($sp)
/*    23c00:	3c0a8006 */ 	lui	$t2,%hi(var8005f018)
/*    23c04:	10c0001b */ 	beqz	$a2,.L00023c74
/*    23c08:	00000000 */ 	nop
/*    23c0c:	00cc0019 */ 	multu	$a2,$t4
/*    23c10:	3c0d8006 */ 	lui	$t5,%hi(var8005f018)
/*    23c14:	8dadf018 */ 	lw	$t5,%lo(var8005f018)($t5)
/*    23c18:	94780008 */ 	lhu	$t8,0x8($v1)
/*    23c1c:	8c790004 */ 	lw	$t9,0x4($v1)
/*    23c20:	3c0f800a */ 	lui	$t7,%hi(var8009a870)
/*    23c24:	8defa870 */ 	lw	$t7,%lo(var8009a870)($t7)
/*    23c28:	03195021 */ 	addu	$t2,$t8,$t9
/*    23c2c:	afa7003c */ 	sw	$a3,0x3c($sp)
/*    23c30:	00005812 */ 	mflo	$t3
/*    23c34:	014b2821 */ 	addu	$a1,$t2,$t3
/*    23c38:	00000000 */ 	nop
/*    23c3c:	00ed0019 */ 	multu	$a3,$t5
/*    23c40:	00007012 */ 	mflo	$t6
/*    23c44:	01cf2021 */ 	addu	$a0,$t6,$t7
/*    23c48:	0c008dfa */ 	jal	animDma
/*    23c4c:	00000000 */ 	nop
/*    23c50:	8fa7003c */ 	lw	$a3,0x3c($sp)
/*    23c54:	3c18800a */ 	lui	$t8,%hi(var8009a874)
/*    23c58:	8f18a874 */ 	lw	$t8,%lo(var8009a874)($t8)
/*    23c5c:	0007c880 */ 	sll	$t9,$a3,0x2
/*    23c60:	3c08800a */ 	lui	$t0,%hi(var8009a87c)
/*    23c64:	03196021 */ 	addu	$t4,$t8,$t9
/*    23c68:	ad820000 */ 	sw	$v0,0x0($t4)
/*    23c6c:	1000000c */ 	b	.L00023ca0
/*    23c70:	2508a87c */ 	addiu	$t0,$t0,%lo(var8009a87c)
.L00023c74:
/*    23c74:	8d4af018 */ 	lw	$t2,%lo(var8005f018)($t2)
/*    23c78:	3c0d800a */ 	lui	$t5,%hi(var8009a870)
/*    23c7c:	3c0f800a */ 	lui	$t7,%hi(var8009a874)
/*    23c80:	00ea0019 */ 	multu	$a3,$t2
/*    23c84:	8defa874 */ 	lw	$t7,%lo(var8009a874)($t7)
/*    23c88:	8dada870 */ 	lw	$t5,%lo(var8009a870)($t5)
/*    23c8c:	0007c080 */ 	sll	$t8,$a3,0x2
/*    23c90:	01f8c821 */ 	addu	$t9,$t7,$t8
/*    23c94:	00005812 */ 	mflo	$t3
/*    23c98:	016d7021 */ 	addu	$t6,$t3,$t5
/*    23c9c:	af2e0000 */ 	sw	$t6,0x0($t9)
.L00023ca0:
/*    23ca0:	3c0c800a */ 	lui	$t4,%hi(var8009a878)
/*    23ca4:	8d8ca878 */ 	lw	$t4,%lo(var8009a878)($t4)
/*    23ca8:	00071040 */ 	sll	$v0,$a3,0x1
/*    23cac:	3c18800a */ 	lui	$t8,%hi(var8009a880)
/*    23cb0:	01825021 */ 	addu	$t2,$t4,$v0
/*    23cb4:	a5510000 */ 	sh	$s1,0x0($t2)
/*    23cb8:	8d0b0000 */ 	lw	$t3,0x0($t0)
/*    23cbc:	24f90001 */ 	addiu	$t9,$a3,0x1
/*    23cc0:	240f0001 */ 	addiu	$t7,$zero,0x1
/*    23cc4:	01626821 */ 	addu	$t5,$t3,$v0
/*    23cc8:	a5b00000 */ 	sh	$s0,0x0($t5)
/*    23ccc:	8f18a880 */ 	lw	$t8,%lo(var8009a880)($t8)
/*    23cd0:	3c018006 */ 	lui	$at,%hi(var8005f000)
/*    23cd4:	03077021 */ 	addu	$t6,$t8,$a3
/*    23cd8:	a1cf0000 */ 	sb	$t7,0x0($t6)
/*    23cdc:	07210004 */ 	bgez	$t9,.L00023cf0
/*    23ce0:	332c001f */ 	andi	$t4,$t9,0x1f
/*    23ce4:	11800002 */ 	beqz	$t4,.L00023cf0
/*    23ce8:	00000000 */ 	nop
/*    23cec:	258cffe0 */ 	addiu	$t4,$t4,-32
.L00023cf0:
/*    23cf0:	ac2cf000 */ 	sw	$t4,%lo(var8005f000)($at)
.L00023cf4:
/*    23cf4:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*    23cf8:	8fb00014 */ 	lw	$s0,0x14($sp)
/*    23cfc:	8fb10018 */ 	lw	$s1,0x18($sp)
/*    23d00:	27bd0040 */ 	addiu	$sp,$sp,0x40
/*    23d04:	03e00008 */ 	jr	$ra
/*    23d08:	30e200ff */ 	andi	$v0,$a3,0xff
);

// Mismatch: regalloc near tmp1 and tmp2
//u8 anim00023ab0(s16 animnum, s32 framenum)
//{
//	s32 index = -1;
//	s32 i;
//	s32 tmp1;
//	s32 tmp2;
//	s32 sp2c = framenum;
//
//	for (i = 0; i < 32; i++) {
//		if (var8009a878[i] == animnum && var8009a87c[i] == sp2c) {
//			index = i;
//			break;
//		}
//	}
//
//	if (index >= 0) {
//		var8009a880[index] = 1;
//	} else {
//		index = var8005f000;
//
//		while (var8009a880[index]) {
//			index = (index + 1) % 32;
//		}
//
//		if (g_Anims[animnum].flags & ANIMFLAG_04) {
//			anim00023908(animnum, framenum, &sp2c);
//		}
//
//		if (g_Anims[animnum].bytesperframe) {
//			tmp1 = g_Anims[animnum].bytesperframe * sp2c;
//			tmp2 = tmp1 + (g_Anims[animnum].data + g_Anims[animnum].headerlen);
//			var8009a874[index] = animDma(&var8009a870[index * var8005f018], tmp2, g_Anims[animnum].bytesperframe);
//		} else {
//			var8009a874[index] = &var8009a870[index * var8005f018];
//		}
//
//		var8009a878[index] = animnum;
//		var8009a87c[index] = framenum;
//		var8009a880[index] = 1;
//		var8005f000 = (index + 1) % 32;
//	}
//
//	return index;
//}

void anim00023d0c(void)
{
	s32 i;

	for (i = 0; i < 32; i++) {
		var8009a880[i] = 0;
	}
}

GLOBAL_ASM(
glabel anim00023d38
/*    23d38:	3c0b8006 */ 	lui	$t3,%hi(var8005f010)
/*    23d3c:	256bf010 */ 	addiu	$t3,$t3,%lo(var8005f010)
/*    23d40:	27bdffc0 */ 	addiu	$sp,$sp,-64
/*    23d44:	8d660000 */ 	lw	$a2,0x0($t3)
/*    23d48:	afb00018 */ 	sw	$s0,0x18($sp)
/*    23d4c:	00048400 */ 	sll	$s0,$a0,0x10
/*    23d50:	00107403 */ 	sra	$t6,$s0,0x10
/*    23d54:	afbf001c */ 	sw	$ra,0x1c($sp)
/*    23d58:	afa40040 */ 	sw	$a0,0x40($sp)
/*    23d5c:	01c67821 */ 	addu	$t7,$t6,$a2
/*    23d60:	91e20000 */ 	lbu	$v0,0x0($t7)
/*    23d64:	240100ff */ 	addiu	$at,$zero,0xff
/*    23d68:	01c08025 */ 	or	$s0,$t6,$zero
/*    23d6c:	1041001c */ 	beq	$v0,$at,.L00023de0
/*    23d70:	3c0a800a */ 	lui	$t2,%hi(g_Vars)
/*    23d74:	3c19800a */ 	lui	$t9,%hi(var8009a890)
/*    23d78:	8f39a890 */ 	lw	$t9,%lo(var8009a890)($t9)
/*    23d7c:	254a9fc0 */ 	addiu	$t2,$t2,%lo(g_Vars)
/*    23d80:	8d580058 */ 	lw	$t8,0x58($t2)
/*    23d84:	00026080 */ 	sll	$t4,$v0,0x2
/*    23d88:	032c6821 */ 	addu	$t5,$t9,$t4
/*    23d8c:	adb80000 */ 	sw	$t8,0x0($t5)
/*    23d90:	8d6e0000 */ 	lw	$t6,0x0($t3)
/*    23d94:	24090028 */ 	addiu	$t1,$zero,0x28
/*    23d98:	020e7821 */ 	addu	$t7,$s0,$t6
/*    23d9c:	91f90000 */ 	lbu	$t9,0x0($t7)
/*    23da0:	272c0001 */ 	addiu	$t4,$t9,0x1
/*    23da4:	0189001a */ 	div	$zero,$t4,$t1
/*    23da8:	15200002 */ 	bnez	$t1,.L00023db4
/*    23dac:	00000000 */ 	nop
/*    23db0:	0007000d */ 	break	0x7
.L00023db4:
/*    23db4:	2401ffff */ 	addiu	$at,$zero,-1
/*    23db8:	15210004 */ 	bne	$t1,$at,.L00023dcc
/*    23dbc:	3c018000 */ 	lui	$at,0x8000
/*    23dc0:	15810002 */ 	bne	$t4,$at,.L00023dcc
/*    23dc4:	00000000 */ 	nop
/*    23dc8:	0006000d */ 	break	0x6
.L00023dcc:
/*    23dcc:	3c018006 */ 	lui	$at,%hi(var8005f004)
/*    23dd0:	0000c010 */ 	mfhi	$t8
/*    23dd4:	ac38f004 */ 	sw	$t8,%lo(var8005f004)($at)
/*    23dd8:	10000059 */ 	b	.L00023f40
/*    23ddc:	8fbf001c */ 	lw	$ra,0x1c($sp)
.L00023de0:
/*    23de0:	3c078006 */ 	lui	$a3,%hi(var8005f004)
/*    23de4:	8ce7f004 */ 	lw	$a3,%lo(var8005f004)($a3)
/*    23de8:	3c05800a */ 	lui	$a1,%hi(var8009a890)
/*    23dec:	8ca5a890 */ 	lw	$a1,%lo(var8009a890)($a1)
/*    23df0:	00074080 */ 	sll	$t0,$a3,0x2
/*    23df4:	00001025 */ 	or	$v0,$zero,$zero
/*    23df8:	00a86821 */ 	addu	$t5,$a1,$t0
/*    23dfc:	8da40000 */ 	lw	$a0,0x0($t5)
/*    23e00:	24090028 */ 	addiu	$t1,$zero,0x28
/*    23e04:	00a01825 */ 	or	$v1,$a1,$zero
.L00023e08:
/*    23e08:	8c6e0000 */ 	lw	$t6,0x0($v1)
/*    23e0c:	01c4082a */ 	slt	$at,$t6,$a0
/*    23e10:	50200006 */ 	beqzl	$at,.L00023e2c
/*    23e14:	24420001 */ 	addiu	$v0,$v0,0x1
/*    23e18:	00024080 */ 	sll	$t0,$v0,0x2
/*    23e1c:	00a87821 */ 	addu	$t7,$a1,$t0
/*    23e20:	8de40000 */ 	lw	$a0,0x0($t7)
/*    23e24:	00403825 */ 	or	$a3,$v0,$zero
/*    23e28:	24420001 */ 	addiu	$v0,$v0,0x1
.L00023e2c:
/*    23e2c:	1449fff6 */ 	bne	$v0,$t1,.L00023e08
/*    23e30:	24630004 */ 	addiu	$v1,$v1,0x4
/*    23e34:	3c19800a */ 	lui	$t9,%hi(var8009a88c)
/*    23e38:	8f39a88c */ 	lw	$t9,%lo(var8009a88c)($t9)
/*    23e3c:	00071840 */ 	sll	$v1,$a3,0x1
/*    23e40:	3c0e8006 */ 	lui	$t6,%hi(g_Anims)
/*    23e44:	03236021 */ 	addu	$t4,$t9,$v1
/*    23e48:	85820000 */ 	lh	$v0,0x0($t4)
/*    23e4c:	3c198006 */ 	lui	$t9,%hi(var8005f01c)
/*    23e50:	10400003 */ 	beqz	$v0,.L00023e60
/*    23e54:	241800ff */ 	addiu	$t8,$zero,0xff
/*    23e58:	00c26821 */ 	addu	$t5,$a2,$v0
/*    23e5c:	a1b80000 */ 	sb	$t8,0x0($t5)
.L00023e60:
/*    23e60:	8f39f01c */ 	lw	$t9,%lo(var8005f01c)($t9)
/*    23e64:	8dcef00c */ 	lw	$t6,%lo(g_Anims)($t6)
/*    23e68:	00107880 */ 	sll	$t7,$s0,0x2
/*    23e6c:	00f90019 */ 	multu	$a3,$t9
/*    23e70:	01f07823 */ 	subu	$t7,$t7,$s0
/*    23e74:	000f7880 */ 	sll	$t7,$t7,0x2
/*    23e78:	01cf1021 */ 	addu	$v0,$t6,$t7
/*    23e7c:	3c18800a */ 	lui	$t8,%hi(var8009a884)
/*    23e80:	8f18a884 */ 	lw	$t8,%lo(var8009a884)($t8)
/*    23e84:	94460008 */ 	lhu	$a2,0x8($v0)
/*    23e88:	8c450004 */ 	lw	$a1,0x4($v0)
/*    23e8c:	afa80020 */ 	sw	$t0,0x20($sp)
/*    23e90:	afa70034 */ 	sw	$a3,0x34($sp)
/*    23e94:	00006012 */ 	mflo	$t4
/*    23e98:	afa30028 */ 	sw	$v1,0x28($sp)
/*    23e9c:	0c008dfa */ 	jal	animDma
/*    23ea0:	01982021 */ 	addu	$a0,$t4,$t8
/*    23ea4:	3c0d800a */ 	lui	$t5,%hi(var8009a888)
/*    23ea8:	8dada888 */ 	lw	$t5,%lo(var8009a888)($t5)
/*    23eac:	8fa80020 */ 	lw	$t0,0x20($sp)
/*    23eb0:	8fa30028 */ 	lw	$v1,0x28($sp)
/*    23eb4:	8fa70034 */ 	lw	$a3,0x34($sp)
/*    23eb8:	3c0b8006 */ 	lui	$t3,%hi(var8005f010)
/*    23ebc:	01a87021 */ 	addu	$t6,$t5,$t0
/*    23ec0:	adc20000 */ 	sw	$v0,0x0($t6)
/*    23ec4:	256bf010 */ 	addiu	$t3,$t3,%lo(var8005f010)
/*    23ec8:	8d6f0000 */ 	lw	$t7,0x0($t3)
/*    23ecc:	24090028 */ 	addiu	$t1,$zero,0x28
/*    23ed0:	3c0c800a */ 	lui	$t4,%hi(var8009a88c)
/*    23ed4:	01f0c821 */ 	addu	$t9,$t7,$s0
/*    23ed8:	a3270000 */ 	sb	$a3,0x0($t9)
/*    23edc:	24f90001 */ 	addiu	$t9,$a3,0x1
/*    23ee0:	0329001a */ 	div	$zero,$t9,$t1
/*    23ee4:	8d8ca88c */ 	lw	$t4,%lo(var8009a88c)($t4)
/*    23ee8:	3c0a800a */ 	lui	$t2,%hi(g_Vars)
/*    23eec:	3c0e800a */ 	lui	$t6,%hi(var8009a890)
/*    23ef0:	0183c021 */ 	addu	$t8,$t4,$v1
/*    23ef4:	a7100000 */ 	sh	$s0,0x0($t8)
/*    23ef8:	8dcea890 */ 	lw	$t6,%lo(var8009a890)($t6)
/*    23efc:	254a9fc0 */ 	addiu	$t2,$t2,%lo(g_Vars)
/*    23f00:	8d4d0058 */ 	lw	$t5,0x58($t2)
/*    23f04:	00006010 */ 	mfhi	$t4
/*    23f08:	01c87821 */ 	addu	$t7,$t6,$t0
/*    23f0c:	aded0000 */ 	sw	$t5,0x0($t7)
/*    23f10:	15200002 */ 	bnez	$t1,.L00023f1c
/*    23f14:	00000000 */ 	nop
/*    23f18:	0007000d */ 	break	0x7
.L00023f1c:
/*    23f1c:	2401ffff */ 	addiu	$at,$zero,-1
/*    23f20:	15210004 */ 	bne	$t1,$at,.L00023f34
/*    23f24:	3c018000 */ 	lui	$at,0x8000
/*    23f28:	17210002 */ 	bne	$t9,$at,.L00023f34
/*    23f2c:	00000000 */ 	nop
/*    23f30:	0006000d */ 	break	0x6
.L00023f34:
/*    23f34:	3c018006 */ 	lui	$at,%hi(var8005f004)
/*    23f38:	ac2cf004 */ 	sw	$t4,%lo(var8005f004)($at)
/*    23f3c:	8fbf001c */ 	lw	$ra,0x1c($sp)
.L00023f40:
/*    23f40:	8fb00018 */ 	lw	$s0,0x18($sp)
/*    23f44:	27bd0040 */ 	addiu	$sp,$sp,0x40
/*    23f48:	03e00008 */ 	jr	$ra
/*    23f4c:	00000000 */ 	nop
);

// Mismatch: for loop is handled differently
//void anim00023d38(s16 animnum)
//{
//	s32 i;
//
//	if (var8005f010[animnum] != 0xff) {
//		var8009a890[var8005f010[animnum]] = g_Vars.thisframe240;
//		var8005f004 = (var8005f010[animnum] + 1) % 40;
//	} else {
//		s32 index = var8005f004;
//		s32 bestvalue = var8009a890[index];
//		s32 stack;
//		s32 tmp;
//
//		for (i = 0; i < 40; i++) {
//			if (var8009a890[i] < bestvalue) {
//				bestvalue = var8009a890[i];
//				index = i;
//			}
//		}
//
//		tmp = var8009a88c[index];
//
//		if (tmp) {
//			var8005f010[tmp] = 0xff;
//		}
//
//		tmp = g_Anims[animnum].headerlen;
//
//		var8009a888[index] = animDma(&var8009a884[var8005f01c * index], g_Anims[animnum].data, tmp);
//		var8005f010[animnum] = index;
//		var8009a88c[index] = animnum;
//		var8009a890[index] = g_Vars.thisframe240;
//		var8005f004 = (index + 1) % 40;
//	}
//}

GLOBAL_ASM(
glabel anim00023f50
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

GLOBAL_ASM(
glabel anim00023fe0
/*    23fe0:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*    23fe4:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    23fe8:	afa5001c */ 	sw	$a1,0x1c($sp)
/*    23fec:	0c008fd4 */ 	jal	anim00023f50
/*    23ff0:	93a5001f */ 	lbu	$a1,0x1f($sp)
/*    23ff4:	93a3001f */ 	lbu	$v1,0x1f($sp)
/*    23ff8:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    23ffc:	3044ffff */ 	andi	$a0,$v0,0xffff
/*    24000:	28610010 */ 	slti	$at,$v1,0x10
/*    24004:	10200010 */ 	beqz	$at,.L00024048
/*    24008:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*    2400c:	246e001f */ 	addiu	$t6,$v1,0x1f
/*    24010:	240f0001 */ 	addiu	$t7,$zero,0x1
/*    24014:	01cfc004 */ 	sllv	$t8,$t7,$t6
/*    24018:	3045ffff */ 	andi	$a1,$v0,0xffff
/*    2401c:	00b8c824 */ 	and	$t9,$a1,$t8
/*    24020:	13200009 */ 	beqz	$t9,.L00024048
/*    24024:	24080010 */ 	addiu	$t0,$zero,0x10
/*    24028:	01034823 */ 	subu	$t1,$t0,$v1
/*    2402c:	240a0001 */ 	addiu	$t2,$zero,0x1
/*    24030:	012a5804 */ 	sllv	$t3,$t2,$t1
/*    24034:	256cffff */ 	addiu	$t4,$t3,-1
/*    24038:	006c6804 */ 	sllv	$t5,$t4,$v1
/*    2403c:	00ad2025 */ 	or	$a0,$a1,$t5
/*    24040:	308fffff */ 	andi	$t7,$a0,0xffff
/*    24044:	01e02025 */ 	or	$a0,$t7,$zero
.L00024048:
/*    24048:	03e00008 */ 	jr	$ra
/*    2404c:	00801025 */ 	or	$v0,$a0,$zero
);

GLOBAL_ASM(
glabel anim00024050
.late_rodata
glabel var70054690
.word 0x3a83126f
glabel var70054694
.word 0x3a83126f
glabel var70054698
.word 0x3a83126f
glabel var7005469c
.word 0x40c907a9
glabel var700546a0
.word 0x40c907a9
glabel var700546a4
.word 0x40c907a9
.text
/*    24050:	27bdff98 */ 	addiu	$sp,$sp,-104
/*    24054:	93b9007b */ 	lbu	$t9,0x7b($sp)
/*    24058:	3c18800a */ 	lui	$t8,%hi(var8009a874)
/*    2405c:	8f18a874 */ 	lw	$t8,%lo(var8009a874)($t8)
/*    24060:	00194080 */ 	sll	$t0,$t9,0x2
/*    24064:	afbf001c */ 	sw	$ra,0x1c($sp)
/*    24068:	afb10018 */ 	sw	$s1,0x18($sp)
/*    2406c:	afb00014 */ 	sw	$s0,0x14($sp)
/*    24070:	afa40068 */ 	sw	$a0,0x68($sp)
/*    24074:	afa5006c */ 	sw	$a1,0x6c($sp)
/*    24078:	afa70074 */ 	sw	$a3,0x74($sp)
/*    2407c:	03084821 */ 	addu	$t1,$t8,$t0
/*    24080:	8d2a0000 */ 	lw	$t2,0x0($t1)
/*    24084:	00077400 */ 	sll	$t6,$a3,0x10
/*    24088:	000e3c03 */ 	sra	$a3,$t6,0x10
/*    2408c:	10a00006 */ 	beqz	$a1,.L000240a8
/*    24090:	afaa0054 */ 	sw	$t2,0x54($sp)
/*    24094:	8ccc0004 */ 	lw	$t4,0x4($a2)
/*    24098:	00047040 */ 	sll	$t6,$a0,0x1
/*    2409c:	018e7821 */ 	addu	$t7,$t4,$t6
/*    240a0:	91f90001 */ 	lbu	$t9,0x1($t7)
/*    240a4:	afb90068 */ 	sw	$t9,0x68($sp)
.L000240a8:
/*    240a8:	3c188006 */ 	lui	$t8,%hi(g_Anims)
/*    240ac:	8f18f00c */ 	lw	$t8,%lo(g_Anims)($t8)
/*    240b0:	00074080 */ 	sll	$t0,$a3,0x2
/*    240b4:	01074023 */ 	subu	$t0,$t0,$a3
/*    240b8:	00084080 */ 	sll	$t0,$t0,0x2
/*    240bc:	3c0b8006 */ 	lui	$t3,%hi(var8005f010)
/*    240c0:	03081021 */ 	addu	$v0,$t8,$t0
/*    240c4:	9049000a */ 	lbu	$t1,0xa($v0)
/*    240c8:	8d6bf010 */ 	lw	$t3,%lo(var8005f010)($t3)
/*    240cc:	3c0a800a */ 	lui	$t2,%hi(var8009a888)
/*    240d0:	a3a90053 */ 	sb	$t1,0x53($sp)
/*    240d4:	00eb6821 */ 	addu	$t5,$a3,$t3
/*    240d8:	91ac0000 */ 	lbu	$t4,0x0($t5)
/*    240dc:	8d4aa888 */ 	lw	$t2,%lo(var8009a888)($t2)
/*    240e0:	8fb80068 */ 	lw	$t8,0x68($sp)
/*    240e4:	000c7080 */ 	sll	$t6,$t4,0x2
/*    240e8:	014e7821 */ 	addu	$t7,$t2,$t6
/*    240ec:	8df00000 */ 	lw	$s0,0x0($t7)
/*    240f0:	94590008 */ 	lhu	$t9,0x8($v0)
/*    240f4:	00008825 */ 	or	$s1,$zero,$zero
/*    240f8:	00002025 */ 	or	$a0,$zero,$zero
/*    240fc:	1b000043 */ 	blez	$t8,.L0002420c
/*    24100:	03302821 */ 	addu	$a1,$t9,$s0
/*    24104:	0205082b */ 	sltu	$at,$s0,$a1
/*    24108:	50200041 */ 	beqzl	$at,.L00024210
/*    2410c:	0205082b */ 	sltu	$at,$s0,$a1
/*    24110:	92030000 */ 	lbu	$v1,0x0($s0)
.L00024114:
/*    24114:	26100001 */ 	addiu	$s0,$s0,0x1
/*    24118:	30680008 */ 	andi	$t0,$v1,0x8
/*    2411c:	1100000b */ 	beqz	$t0,.L0002414c
/*    24120:	30790002 */ 	andi	$t9,$v1,0x2
/*    24124:	92090002 */ 	lbu	$t1,0x2($s0)
/*    24128:	920d0005 */ 	lbu	$t5,0x5($s0)
/*    2412c:	920a0008 */ 	lbu	$t2,0x8($s0)
/*    24130:	02295821 */ 	addu	$t3,$s1,$t1
/*    24134:	920f000b */ 	lbu	$t7,0xb($s0)
/*    24138:	016d6021 */ 	addu	$t4,$t3,$t5
/*    2413c:	018a7021 */ 	addu	$t6,$t4,$t2
/*    24140:	2610000c */ 	addiu	$s0,$s0,0xc
/*    24144:	10000014 */ 	b	.L00024198
/*    24148:	01cf8821 */ 	addu	$s1,$t6,$t7
.L0002414c:
/*    2414c:	13200009 */ 	beqz	$t9,.L00024174
/*    24150:	306c0020 */ 	andi	$t4,$v1,0x20
/*    24154:	92180002 */ 	lbu	$t8,0x2($s0)
/*    24158:	92090005 */ 	lbu	$t1,0x5($s0)
/*    2415c:	920d0008 */ 	lbu	$t5,0x8($s0)
/*    24160:	02384021 */ 	addu	$t0,$s1,$t8
/*    24164:	01095821 */ 	addu	$t3,$t0,$t1
/*    24168:	26100009 */ 	addiu	$s0,$s0,0x9
/*    2416c:	1000000a */ 	b	.L00024198
/*    24170:	016d8821 */ 	addu	$s1,$t3,$t5
.L00024174:
/*    24174:	51800009 */ 	beqzl	$t4,.L0002419c
/*    24178:	30680001 */ 	andi	$t0,$v1,0x1
/*    2417c:	920a0000 */ 	lbu	$t2,0x0($s0)
/*    24180:	920f0005 */ 	lbu	$t7,0x5($s0)
/*    24184:	9218000a */ 	lbu	$t8,0xa($s0)
/*    24188:	022a7021 */ 	addu	$t6,$s1,$t2
/*    2418c:	01cfc821 */ 	addu	$t9,$t6,$t7
/*    24190:	2610000f */ 	addiu	$s0,$s0,0xf
/*    24194:	03388821 */ 	addu	$s1,$t9,$t8
.L00024198:
/*    24198:	30680001 */ 	andi	$t0,$v1,0x1
.L0002419c:
/*    2419c:	11000009 */ 	beqz	$t0,.L000241c4
/*    241a0:	306f0040 */ 	andi	$t7,$v1,0x40
/*    241a4:	92090002 */ 	lbu	$t1,0x2($s0)
/*    241a8:	920d0005 */ 	lbu	$t5,0x5($s0)
/*    241ac:	920a0008 */ 	lbu	$t2,0x8($s0)
/*    241b0:	02295821 */ 	addu	$t3,$s1,$t1
/*    241b4:	016d6021 */ 	addu	$t4,$t3,$t5
/*    241b8:	26100009 */ 	addiu	$s0,$s0,0x9
/*    241bc:	10000005 */ 	b	.L000241d4
/*    241c0:	018a8821 */ 	addu	$s1,$t4,$t2
.L000241c4:
/*    241c4:	306e0010 */ 	andi	$t6,$v1,0x10
/*    241c8:	11c00002 */ 	beqz	$t6,.L000241d4
/*    241cc:	00000000 */ 	nop
/*    241d0:	26310060 */ 	addiu	$s1,$s1,0x60
.L000241d4:
/*    241d4:	11e00004 */ 	beqz	$t7,.L000241e8
/*    241d8:	30780080 */ 	andi	$t8,$v1,0x80
/*    241dc:	92190000 */ 	lbu	$t9,0x0($s0)
/*    241e0:	26100005 */ 	addiu	$s0,$s0,0x5
/*    241e4:	02398821 */ 	addu	$s1,$s1,$t9
.L000241e8:
/*    241e8:	13000002 */ 	beqz	$t8,.L000241f4
/*    241ec:	8fa80068 */ 	lw	$t0,0x68($sp)
/*    241f0:	26310060 */ 	addiu	$s1,$s1,0x60
.L000241f4:
/*    241f4:	24840001 */ 	addiu	$a0,$a0,0x1
/*    241f8:	0088082a */ 	slt	$at,$a0,$t0
/*    241fc:	10200003 */ 	beqz	$at,.L0002420c
/*    24200:	0205082b */ 	sltu	$at,$s0,$a1
/*    24204:	5420ffc3 */ 	bnezl	$at,.L00024114
/*    24208:	92030000 */ 	lbu	$v1,0x0($s0)
.L0002420c:
/*    2420c:	0205082b */ 	sltu	$at,$s0,$a1
.L00024210:
/*    24210:	1020017f */ 	beqz	$at,.L00024810
/*    24214:	8fa3007c */ 	lw	$v1,0x7c($sp)
/*    24218:	92020000 */ 	lbu	$v0,0x0($s0)
/*    2421c:	26100001 */ 	addiu	$s0,$s0,0x1
/*    24220:	8fa40054 */ 	lw	$a0,0x54($sp)
/*    24224:	304b0002 */ 	andi	$t3,$v0,0x2
/*    24228:	11600039 */ 	beqz	$t3,.L00024310
/*    2422c:	afa20028 */ 	sw	$v0,0x28($sp)
/*    24230:	92050002 */ 	lbu	$a1,0x2($s0)
/*    24234:	02203025 */ 	or	$a2,$s1,$zero
/*    24238:	0c008ff8 */ 	jal	anim00023fe0
/*    2423c:	a3a5005b */ 	sb	$a1,0x5b($sp)
/*    24240:	920d0001 */ 	lbu	$t5,0x1($s0)
/*    24244:	920a0000 */ 	lbu	$t2,0x0($s0)
/*    24248:	93a5005b */ 	lbu	$a1,0x5b($sp)
/*    2424c:	01a26021 */ 	addu	$t4,$t5,$v0
/*    24250:	000a7200 */ 	sll	$t6,$t2,0x8
/*    24254:	018e7821 */ 	addu	$t7,$t4,$t6
/*    24258:	000fcc00 */ 	sll	$t9,$t7,0x10
/*    2425c:	0019c403 */ 	sra	$t8,$t9,0x10
/*    24260:	44982000 */ 	mtc1	$t8,$f4
/*    24264:	8fa80080 */ 	lw	$t0,0x80($sp)
/*    24268:	02258821 */ 	addu	$s1,$s1,$a1
/*    2426c:	468021a0 */ 	cvt.s.w	$f6,$f4
/*    24270:	02203025 */ 	or	$a2,$s1,$zero
/*    24274:	e5060000 */ 	swc1	$f6,0x0($t0)
/*    24278:	92050005 */ 	lbu	$a1,0x5($s0)
/*    2427c:	8fa40054 */ 	lw	$a0,0x54($sp)
/*    24280:	0c008ff8 */ 	jal	anim00023fe0
/*    24284:	a3a5005b */ 	sb	$a1,0x5b($sp)
/*    24288:	92090004 */ 	lbu	$t1,0x4($s0)
/*    2428c:	920d0003 */ 	lbu	$t5,0x3($s0)
/*    24290:	93a5005b */ 	lbu	$a1,0x5b($sp)
/*    24294:	01225821 */ 	addu	$t3,$t1,$v0
/*    24298:	000d5200 */ 	sll	$t2,$t5,0x8
/*    2429c:	016a6021 */ 	addu	$t4,$t3,$t2
/*    242a0:	000c7400 */ 	sll	$t6,$t4,0x10
/*    242a4:	000e7c03 */ 	sra	$t7,$t6,0x10
/*    242a8:	448f4000 */ 	mtc1	$t7,$f8
/*    242ac:	8fa70080 */ 	lw	$a3,0x80($sp)
/*    242b0:	02258821 */ 	addu	$s1,$s1,$a1
/*    242b4:	468042a0 */ 	cvt.s.w	$f10,$f8
/*    242b8:	02203025 */ 	or	$a2,$s1,$zero
/*    242bc:	e4ea0004 */ 	swc1	$f10,0x4($a3)
/*    242c0:	92050008 */ 	lbu	$a1,0x8($s0)
/*    242c4:	8fa40054 */ 	lw	$a0,0x54($sp)
/*    242c8:	0c008ff8 */ 	jal	anim00023fe0
/*    242cc:	a3a5005b */ 	sb	$a1,0x5b($sp)
/*    242d0:	92190007 */ 	lbu	$t9,0x7($s0)
/*    242d4:	92080006 */ 	lbu	$t0,0x6($s0)
/*    242d8:	93a5005b */ 	lbu	$a1,0x5b($sp)
/*    242dc:	0322c021 */ 	addu	$t8,$t9,$v0
/*    242e0:	00084a00 */ 	sll	$t1,$t0,0x8
/*    242e4:	03096821 */ 	addu	$t5,$t8,$t1
/*    242e8:	000d5c00 */ 	sll	$t3,$t5,0x10
/*    242ec:	000b5403 */ 	sra	$t2,$t3,0x10
/*    242f0:	448a8000 */ 	mtc1	$t2,$f16
/*    242f4:	8fa70080 */ 	lw	$a3,0x80($sp)
/*    242f8:	44800000 */ 	mtc1	$zero,$f0
/*    242fc:	468084a0 */ 	cvt.s.w	$f18,$f16
/*    24300:	26100009 */ 	addiu	$s0,$s0,0x9
/*    24304:	02258821 */ 	addu	$s1,$s1,$a1
/*    24308:	10000064 */ 	b	.L0002449c
/*    2430c:	e4f20008 */ 	swc1	$f18,0x8($a3)
.L00024310:
/*    24310:	8fac0028 */ 	lw	$t4,0x28($sp)
/*    24314:	8faf0028 */ 	lw	$t7,0x28($sp)
/*    24318:	8fa70080 */ 	lw	$a3,0x80($sp)
/*    2431c:	318e0020 */ 	andi	$t6,$t4,0x20
/*    24320:	11c0004f */ 	beqz	$t6,.L00024460
/*    24324:	31ed0008 */ 	andi	$t5,$t7,0x8
/*    24328:	92050000 */ 	lbu	$a1,0x0($s0)
/*    2432c:	8fa40054 */ 	lw	$a0,0x54($sp)
/*    24330:	02203025 */ 	or	$a2,$s1,$zero
/*    24334:	0c008fd4 */ 	jal	anim00023f50
/*    24338:	a3a5005b */ 	sb	$a1,0x5b($sp)
/*    2433c:	92190001 */ 	lbu	$t9,0x1($s0)
/*    24340:	920f0004 */ 	lbu	$t7,0x4($s0)
/*    24344:	92090002 */ 	lbu	$t1,0x2($s0)
/*    24348:	920a0003 */ 	lbu	$t2,0x3($s0)
/*    2434c:	00194600 */ 	sll	$t0,$t9,0x18
/*    24350:	01e8c021 */ 	addu	$t8,$t7,$t0
/*    24354:	00096c00 */ 	sll	$t5,$t1,0x10
/*    24358:	030d5821 */ 	addu	$t3,$t8,$t5
/*    2435c:	000a6200 */ 	sll	$t4,$t2,0x8
/*    24360:	016c7021 */ 	addu	$t6,$t3,$t4
/*    24364:	01c2c821 */ 	addu	$t9,$t6,$v0
/*    24368:	44992000 */ 	mtc1	$t9,$f4
/*    2436c:	3c017005 */ 	lui	$at,%hi(var70054690)
/*    24370:	c4284690 */ 	lwc1	$f8,%lo(var70054690)($at)
/*    24374:	468021a0 */ 	cvt.s.w	$f6,$f4
/*    24378:	93a5005b */ 	lbu	$a1,0x5b($sp)
/*    2437c:	8fa70080 */ 	lw	$a3,0x80($sp)
/*    24380:	02258821 */ 	addu	$s1,$s1,$a1
/*    24384:	02203025 */ 	or	$a2,$s1,$zero
/*    24388:	46083282 */ 	mul.s	$f10,$f6,$f8
/*    2438c:	e4ea0000 */ 	swc1	$f10,0x0($a3)
/*    24390:	92050005 */ 	lbu	$a1,0x5($s0)
/*    24394:	8fa40054 */ 	lw	$a0,0x54($sp)
/*    24398:	0c008fd4 */ 	jal	anim00023f50
/*    2439c:	a3a5005b */ 	sb	$a1,0x5b($sp)
/*    243a0:	92080006 */ 	lbu	$t0,0x6($s0)
/*    243a4:	920f0009 */ 	lbu	$t7,0x9($s0)
/*    243a8:	920d0007 */ 	lbu	$t5,0x7($s0)
/*    243ac:	920c0008 */ 	lbu	$t4,0x8($s0)
/*    243b0:	00084e00 */ 	sll	$t1,$t0,0x18
/*    243b4:	01e9c021 */ 	addu	$t8,$t7,$t1
/*    243b8:	000d5400 */ 	sll	$t2,$t5,0x10
/*    243bc:	030a5821 */ 	addu	$t3,$t8,$t2
/*    243c0:	000c7200 */ 	sll	$t6,$t4,0x8
/*    243c4:	016ec821 */ 	addu	$t9,$t3,$t6
/*    243c8:	03224021 */ 	addu	$t0,$t9,$v0
/*    243cc:	44888000 */ 	mtc1	$t0,$f16
/*    243d0:	3c017005 */ 	lui	$at,%hi(var70054694)
/*    243d4:	c4244694 */ 	lwc1	$f4,%lo(var70054694)($at)
/*    243d8:	468084a0 */ 	cvt.s.w	$f18,$f16
/*    243dc:	93a5005b */ 	lbu	$a1,0x5b($sp)
/*    243e0:	8fa70080 */ 	lw	$a3,0x80($sp)
/*    243e4:	02258821 */ 	addu	$s1,$s1,$a1
/*    243e8:	02203025 */ 	or	$a2,$s1,$zero
/*    243ec:	46049182 */ 	mul.s	$f6,$f18,$f4
/*    243f0:	e4e60004 */ 	swc1	$f6,0x4($a3)
/*    243f4:	9205000a */ 	lbu	$a1,0xa($s0)
/*    243f8:	8fa40054 */ 	lw	$a0,0x54($sp)
/*    243fc:	0c008fd4 */ 	jal	anim00023f50
/*    24400:	a3a5005b */ 	sb	$a1,0x5b($sp)
/*    24404:	9209000b */ 	lbu	$t1,0xb($s0)
/*    24408:	920f000e */ 	lbu	$t7,0xe($s0)
/*    2440c:	920a000c */ 	lbu	$t2,0xc($s0)
/*    24410:	920e000d */ 	lbu	$t6,0xd($s0)
/*    24414:	00096e00 */ 	sll	$t5,$t1,0x18
/*    24418:	01edc021 */ 	addu	$t8,$t7,$t5
/*    2441c:	000a6400 */ 	sll	$t4,$t2,0x10
/*    24420:	030c5821 */ 	addu	$t3,$t8,$t4
/*    24424:	000eca00 */ 	sll	$t9,$t6,0x8
/*    24428:	01794021 */ 	addu	$t0,$t3,$t9
/*    2442c:	01024821 */ 	addu	$t1,$t0,$v0
/*    24430:	44894000 */ 	mtc1	$t1,$f8
/*    24434:	3c017005 */ 	lui	$at,%hi(var70054698)
/*    24438:	c4304698 */ 	lwc1	$f16,%lo(var70054698)($at)
/*    2443c:	468042a0 */ 	cvt.s.w	$f10,$f8
/*    24440:	93a5005b */ 	lbu	$a1,0x5b($sp)
/*    24444:	8fa70080 */ 	lw	$a3,0x80($sp)
/*    24448:	44800000 */ 	mtc1	$zero,$f0
/*    2444c:	2610000f */ 	addiu	$s0,$s0,0xf
/*    24450:	02258821 */ 	addu	$s1,$s1,$a1
/*    24454:	46105482 */ 	mul.s	$f18,$f10,$f16
/*    24458:	10000010 */ 	b	.L0002449c
/*    2445c:	e4f20008 */ 	swc1	$f18,0x8($a3)
.L00024460:
/*    24460:	44800000 */ 	mtc1	$zero,$f0
/*    24464:	51a0000b */ 	beqzl	$t5,.L00024494
/*    24468:	e4e00008 */ 	swc1	$f0,0x8($a3)
/*    2446c:	920a0002 */ 	lbu	$t2,0x2($s0)
/*    24470:	920c0005 */ 	lbu	$t4,0x5($s0)
/*    24474:	920b0008 */ 	lbu	$t3,0x8($s0)
/*    24478:	9208000b */ 	lbu	$t0,0xb($s0)
/*    2447c:	022ac021 */ 	addu	$t8,$s1,$t2
/*    24480:	030c7021 */ 	addu	$t6,$t8,$t4
/*    24484:	01cbc821 */ 	addu	$t9,$t6,$t3
/*    24488:	2610000c */ 	addiu	$s0,$s0,0xc
/*    2448c:	03288821 */ 	addu	$s1,$t9,$t0
/*    24490:	e4e00008 */ 	swc1	$f0,0x8($a3)
.L00024494:
/*    24494:	e4e00004 */ 	swc1	$f0,0x4($a3)
/*    24498:	e4e00000 */ 	swc1	$f0,0x0($a3)
.L0002449c:
/*    2449c:	8fa90028 */ 	lw	$t1,0x28($sp)
/*    244a0:	8fa80028 */ 	lw	$t0,0x28($sp)
/*    244a4:	8fa40054 */ 	lw	$a0,0x54($sp)
/*    244a8:	312f0001 */ 	andi	$t7,$t1,0x1
/*    244ac:	11e0007d */ 	beqz	$t7,.L000246a4
/*    244b0:	31190010 */ 	andi	$t9,$t0,0x10
/*    244b4:	92050002 */ 	lbu	$a1,0x2($s0)
/*    244b8:	02203025 */ 	or	$a2,$s1,$zero
/*    244bc:	0c008fd4 */ 	jal	anim00023f50
/*    244c0:	a3a5005b */ 	sb	$a1,0x5b($sp)
/*    244c4:	a7a2005c */ 	sh	$v0,0x5c($sp)
/*    244c8:	920a0000 */ 	lbu	$t2,0x0($s0)
/*    244cc:	920e0001 */ 	lbu	$t6,0x1($s0)
/*    244d0:	93b90053 */ 	lbu	$t9,0x53($sp)
/*    244d4:	000ac200 */ 	sll	$t8,$t2,0x8
/*    244d8:	00586021 */ 	addu	$t4,$v0,$t8
/*    244dc:	93a5005b */ 	lbu	$a1,0x5b($sp)
/*    244e0:	24080010 */ 	addiu	$t0,$zero,0x10
/*    244e4:	018e5821 */ 	addu	$t3,$t4,$t6
/*    244e8:	3169ffff */ 	andi	$t1,$t3,0xffff
/*    244ec:	01191823 */ 	subu	$v1,$t0,$t9
/*    244f0:	a7ab005c */ 	sh	$t3,0x5c($sp)
/*    244f4:	00697804 */ 	sllv	$t7,$t1,$v1
/*    244f8:	a7af005c */ 	sh	$t7,0x5c($sp)
/*    244fc:	02258821 */ 	addu	$s1,$s1,$a1
/*    24500:	92050005 */ 	lbu	$a1,0x5($s0)
/*    24504:	afa30024 */ 	sw	$v1,0x24($sp)
/*    24508:	02203025 */ 	or	$a2,$s1,$zero
/*    2450c:	8fa40054 */ 	lw	$a0,0x54($sp)
/*    24510:	0c008fd4 */ 	jal	anim00023f50
/*    24514:	a3a5005b */ 	sb	$a1,0x5b($sp)
/*    24518:	a7a2005e */ 	sh	$v0,0x5e($sp)
/*    2451c:	920d0003 */ 	lbu	$t5,0x3($s0)
/*    24520:	920e0004 */ 	lbu	$t6,0x4($s0)
/*    24524:	8fb90024 */ 	lw	$t9,0x24($sp)
/*    24528:	000dc200 */ 	sll	$t8,$t5,0x8
/*    2452c:	00586021 */ 	addu	$t4,$v0,$t8
/*    24530:	93a5005b */ 	lbu	$a1,0x5b($sp)
/*    24534:	018e4021 */ 	addu	$t0,$t4,$t6
/*    24538:	310bffff */ 	andi	$t3,$t0,0xffff
/*    2453c:	a7a8005e */ 	sh	$t0,0x5e($sp)
/*    24540:	032b4804 */ 	sllv	$t1,$t3,$t9
/*    24544:	a7a9005e */ 	sh	$t1,0x5e($sp)
/*    24548:	02258821 */ 	addu	$s1,$s1,$a1
/*    2454c:	92050008 */ 	lbu	$a1,0x8($s0)
/*    24550:	02203025 */ 	or	$a2,$s1,$zero
/*    24554:	8fa40054 */ 	lw	$a0,0x54($sp)
/*    24558:	0c008fd4 */ 	jal	anim00023f50
/*    2455c:	a3a5005b */ 	sb	$a1,0x5b($sp)
/*    24560:	a7a20060 */ 	sh	$v0,0x60($sp)
/*    24564:	920d0006 */ 	lbu	$t5,0x6($s0)
/*    24568:	920c0007 */ 	lbu	$t4,0x7($s0)
/*    2456c:	97a9005c */ 	lhu	$t1,0x5c($sp)
/*    24570:	000d5200 */ 	sll	$t2,$t5,0x8
/*    24574:	8fa80024 */ 	lw	$t0,0x24($sp)
/*    24578:	004ac021 */ 	addu	$t8,$v0,$t2
/*    2457c:	3c014780 */ 	lui	$at,0x4780
/*    24580:	030c7021 */ 	addu	$t6,$t8,$t4
/*    24584:	93a5005b */ 	lbu	$a1,0x5b($sp)
/*    24588:	44892000 */ 	mtc1	$t1,$f4
/*    2458c:	44811000 */ 	mtc1	$at,$f2
/*    24590:	31cbffff */ 	andi	$t3,$t6,0xffff
/*    24594:	3c017005 */ 	lui	$at,%hi(var7005469c)
/*    24598:	44800000 */ 	mtc1	$zero,$f0
/*    2459c:	a7ae0060 */ 	sh	$t6,0x60($sp)
/*    245a0:	010bc804 */ 	sllv	$t9,$t3,$t0
/*    245a4:	c42c469c */ 	lwc1	$f12,%lo(var7005469c)($at)
/*    245a8:	8fa3007c */ 	lw	$v1,0x7c($sp)
/*    245ac:	a7b90060 */ 	sh	$t9,0x60($sp)
/*    245b0:	02258821 */ 	addu	$s1,$s1,$a1
/*    245b4:	05210005 */ 	bgez	$t1,.L000245cc
/*    245b8:	468021a0 */ 	cvt.s.w	$f6,$f4
/*    245bc:	3c014f80 */ 	lui	$at,0x4f80
/*    245c0:	44814000 */ 	mtc1	$at,$f8
/*    245c4:	00000000 */ 	nop
/*    245c8:	46083180 */ 	add.s	$f6,$f6,$f8
.L000245cc:
/*    245cc:	460c3282 */ 	mul.s	$f10,$f6,$f12
/*    245d0:	46025403 */ 	div.s	$f16,$f10,$f2
/*    245d4:	e4700000 */ 	swc1	$f16,0x0($v1)
/*    245d8:	8fad006c */ 	lw	$t5,0x6c($sp)
/*    245dc:	97a2005e */ 	lhu	$v0,0x5e($sp)
/*    245e0:	97ae005e */ 	lhu	$t6,0x5e($sp)
/*    245e4:	51a0001a */ 	beqzl	$t5,.L00024650
/*    245e8:	448e4000 */ 	mtc1	$t6,$f8
/*    245ec:	10400009 */ 	beqz	$v0,.L00024614
/*    245f0:	3c0f0001 */ 	lui	$t7,0x1
/*    245f4:	01e25023 */ 	subu	$t2,$t7,$v0
/*    245f8:	448a9000 */ 	mtc1	$t2,$f18
/*    245fc:	00000000 */ 	nop
/*    24600:	46809120 */ 	cvt.s.w	$f4,$f18
/*    24604:	460c2202 */ 	mul.s	$f8,$f4,$f12
/*    24608:	46024183 */ 	div.s	$f6,$f8,$f2
/*    2460c:	10000002 */ 	b	.L00024618
/*    24610:	e4660004 */ 	swc1	$f6,0x4($v1)
.L00024614:
/*    24614:	e4600004 */ 	swc1	$f0,0x4($v1)
.L00024618:
/*    24618:	97a20060 */ 	lhu	$v0,0x60($sp)
/*    2461c:	3c180001 */ 	lui	$t8,0x1
/*    24620:	10400008 */ 	beqz	$v0,.L00024644
/*    24624:	03026023 */ 	subu	$t4,$t8,$v0
/*    24628:	448c5000 */ 	mtc1	$t4,$f10
/*    2462c:	00000000 */ 	nop
/*    24630:	46805420 */ 	cvt.s.w	$f16,$f10
/*    24634:	460c8482 */ 	mul.s	$f18,$f16,$f12
/*    24638:	46029103 */ 	div.s	$f4,$f18,$f2
/*    2463c:	10000051 */ 	b	.L00024784
/*    24640:	e4640008 */ 	swc1	$f4,0x8($v1)
.L00024644:
/*    24644:	1000004f */ 	b	.L00024784
/*    24648:	e4600008 */ 	swc1	$f0,0x8($v1)
/*    2464c:	448e4000 */ 	mtc1	$t6,$f8
.L00024650:
/*    24650:	3c014f80 */ 	lui	$at,0x4f80
/*    24654:	05c10004 */ 	bgez	$t6,.L00024668
/*    24658:	468041a0 */ 	cvt.s.w	$f6,$f8
/*    2465c:	44815000 */ 	mtc1	$at,$f10
/*    24660:	00000000 */ 	nop
/*    24664:	460a3180 */ 	add.s	$f6,$f6,$f10
.L00024668:
/*    24668:	460c3402 */ 	mul.s	$f16,$f6,$f12
/*    2466c:	3c014f80 */ 	lui	$at,0x4f80
/*    24670:	46028483 */ 	div.s	$f18,$f16,$f2
/*    24674:	e4720004 */ 	swc1	$f18,0x4($v1)
/*    24678:	97ab0060 */ 	lhu	$t3,0x60($sp)
/*    2467c:	448b2000 */ 	mtc1	$t3,$f4
/*    24680:	05610004 */ 	bgez	$t3,.L00024694
/*    24684:	46802220 */ 	cvt.s.w	$f8,$f4
/*    24688:	44815000 */ 	mtc1	$at,$f10
/*    2468c:	00000000 */ 	nop
/*    24690:	460a4200 */ 	add.s	$f8,$f8,$f10
.L00024694:
/*    24694:	460c4182 */ 	mul.s	$f6,$f8,$f12
/*    24698:	46023403 */ 	div.s	$f16,$f6,$f2
/*    2469c:	10000039 */ 	b	.L00024784
/*    246a0:	e4700008 */ 	swc1	$f16,0x8($v1)
.L000246a4:
/*    246a4:	13200034 */ 	beqz	$t9,.L00024778
/*    246a8:	8fa3007c */ 	lw	$v1,0x7c($sp)
/*    246ac:	8fa40054 */ 	lw	$a0,0x54($sp)
/*    246b0:	24050020 */ 	addiu	$a1,$zero,0x20
/*    246b4:	0c008fd4 */ 	jal	anim00023f50
/*    246b8:	02203025 */ 	or	$a2,$s1,$zero
/*    246bc:	27b00038 */ 	addiu	$s0,$sp,0x38
/*    246c0:	afa20038 */ 	sw	$v0,0x38($sp)
/*    246c4:	8fa3007c */ 	lw	$v1,0x7c($sp)
/*    246c8:	c6120000 */ 	lwc1	$f18,0x0($s0)
/*    246cc:	26310020 */ 	addiu	$s1,$s1,0x20
/*    246d0:	02203025 */ 	or	$a2,$s1,$zero
/*    246d4:	e4720000 */ 	swc1	$f18,0x0($v1)
/*    246d8:	8fa40054 */ 	lw	$a0,0x54($sp)
/*    246dc:	0c008fd4 */ 	jal	anim00023f50
/*    246e0:	24050020 */ 	addiu	$a1,$zero,0x20
/*    246e4:	afa20038 */ 	sw	$v0,0x38($sp)
/*    246e8:	8fa3007c */ 	lw	$v1,0x7c($sp)
/*    246ec:	c6040000 */ 	lwc1	$f4,0x0($s0)
/*    246f0:	26310020 */ 	addiu	$s1,$s1,0x20
/*    246f4:	02203025 */ 	or	$a2,$s1,$zero
/*    246f8:	e4640004 */ 	swc1	$f4,0x4($v1)
/*    246fc:	8fa40054 */ 	lw	$a0,0x54($sp)
/*    24700:	0c008fd4 */ 	jal	anim00023f50
/*    24704:	24050020 */ 	addiu	$a1,$zero,0x20
/*    24708:	afa20038 */ 	sw	$v0,0x38($sp)
/*    2470c:	8fa3007c */ 	lw	$v1,0x7c($sp)
/*    24710:	c60a0000 */ 	lwc1	$f10,0x0($s0)
/*    24714:	44800000 */ 	mtc1	$zero,$f0
/*    24718:	26310020 */ 	addiu	$s1,$s1,0x20
/*    2471c:	e46a0008 */ 	swc1	$f10,0x8($v1)
/*    24720:	8fa9006c */ 	lw	$t1,0x6c($sp)
/*    24724:	51200018 */ 	beqzl	$t1,.L00024788
/*    24728:	8fad0028 */ 	lw	$t5,0x28($sp)
/*    2472c:	c4620004 */ 	lwc1	$f2,0x4($v1)
/*    24730:	3c017005 */ 	lui	$at,%hi(var700546a0)
/*    24734:	46020032 */ 	c.eq.s	$f0,$f2
/*    24738:	00000000 */ 	nop
/*    2473c:	45030005 */ 	bc1tl	.L00024754
/*    24740:	c4620008 */ 	lwc1	$f2,0x8($v1)
/*    24744:	c42c46a0 */ 	lwc1	$f12,%lo(var700546a0)($at)
/*    24748:	46026201 */ 	sub.s	$f8,$f12,$f2
/*    2474c:	e4680004 */ 	swc1	$f8,0x4($v1)
/*    24750:	c4620008 */ 	lwc1	$f2,0x8($v1)
.L00024754:
/*    24754:	3c017005 */ 	lui	$at,%hi(var700546a4)
/*    24758:	c42c46a4 */ 	lwc1	$f12,%lo(var700546a4)($at)
/*    2475c:	46020032 */ 	c.eq.s	$f0,$f2
/*    24760:	00000000 */ 	nop
/*    24764:	45030008 */ 	bc1tl	.L00024788
/*    24768:	8fad0028 */ 	lw	$t5,0x28($sp)
/*    2476c:	46026181 */ 	sub.s	$f6,$f12,$f2
/*    24770:	10000004 */ 	b	.L00024784
/*    24774:	e4660008 */ 	swc1	$f6,0x8($v1)
.L00024778:
/*    24778:	e4600008 */ 	swc1	$f0,0x8($v1)
/*    2477c:	e4600004 */ 	swc1	$f0,0x4($v1)
/*    24780:	e4600000 */ 	swc1	$f0,0x0($v1)
.L00024784:
/*    24784:	8fad0028 */ 	lw	$t5,0x28($sp)
.L00024788:
/*    24788:	8fa40054 */ 	lw	$a0,0x54($sp)
/*    2478c:	8fb00084 */ 	lw	$s0,0x84($sp)
/*    24790:	31af0080 */ 	andi	$t7,$t5,0x80
/*    24794:	11e00018 */ 	beqz	$t7,.L000247f8
/*    24798:	3c013f80 */ 	lui	$at,0x3f80
/*    2479c:	24050020 */ 	addiu	$a1,$zero,0x20
/*    247a0:	0c008fd4 */ 	jal	anim00023f50
/*    247a4:	02203025 */ 	or	$a2,$s1,$zero
/*    247a8:	afa20034 */ 	sw	$v0,0x34($sp)
/*    247ac:	8fb00084 */ 	lw	$s0,0x84($sp)
/*    247b0:	c7b00034 */ 	lwc1	$f16,0x34($sp)
/*    247b4:	26310020 */ 	addiu	$s1,$s1,0x20
/*    247b8:	02203025 */ 	or	$a2,$s1,$zero
/*    247bc:	e6100000 */ 	swc1	$f16,0x0($s0)
/*    247c0:	8fa40054 */ 	lw	$a0,0x54($sp)
/*    247c4:	0c008fd4 */ 	jal	anim00023f50
/*    247c8:	24050020 */ 	addiu	$a1,$zero,0x20
/*    247cc:	afa20034 */ 	sw	$v0,0x34($sp)
/*    247d0:	c7b20034 */ 	lwc1	$f18,0x34($sp)
/*    247d4:	26260020 */ 	addiu	$a2,$s1,0x20
/*    247d8:	24050020 */ 	addiu	$a1,$zero,0x20
/*    247dc:	e6120004 */ 	swc1	$f18,0x4($s0)
/*    247e0:	0c008fd4 */ 	jal	anim00023f50
/*    247e4:	8fa40054 */ 	lw	$a0,0x54($sp)
/*    247e8:	afa20034 */ 	sw	$v0,0x34($sp)
/*    247ec:	c7a40034 */ 	lwc1	$f4,0x34($sp)
/*    247f0:	10000015 */ 	b	.L00024848
/*    247f4:	e6040008 */ 	swc1	$f4,0x8($s0)
.L000247f8:
/*    247f8:	44811000 */ 	mtc1	$at,$f2
/*    247fc:	00000000 */ 	nop
/*    24800:	e6020008 */ 	swc1	$f2,0x8($s0)
/*    24804:	e6020004 */ 	swc1	$f2,0x4($s0)
/*    24808:	1000000f */ 	b	.L00024848
/*    2480c:	e6020000 */ 	swc1	$f2,0x0($s0)
.L00024810:
/*    24810:	8fa70080 */ 	lw	$a3,0x80($sp)
/*    24814:	8fb00084 */ 	lw	$s0,0x84($sp)
/*    24818:	44800000 */ 	mtc1	$zero,$f0
/*    2481c:	3c013f80 */ 	lui	$at,0x3f80
/*    24820:	44811000 */ 	mtc1	$at,$f2
/*    24824:	e4600008 */ 	swc1	$f0,0x8($v1)
/*    24828:	e4600004 */ 	swc1	$f0,0x4($v1)
/*    2482c:	e4600000 */ 	swc1	$f0,0x0($v1)
/*    24830:	e4e00000 */ 	swc1	$f0,0x0($a3)
/*    24834:	e4e00004 */ 	swc1	$f0,0x4($a3)
/*    24838:	e4e00008 */ 	swc1	$f0,0x8($a3)
/*    2483c:	e6020000 */ 	swc1	$f2,0x0($s0)
/*    24840:	e6020004 */ 	swc1	$f2,0x4($s0)
/*    24844:	e6020008 */ 	swc1	$f2,0x8($s0)
.L00024848:
/*    24848:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*    2484c:	8fb00014 */ 	lw	$s0,0x14($sp)
/*    24850:	8fb10018 */ 	lw	$s1,0x18($sp)
/*    24854:	03e00008 */ 	jr	$ra
/*    24858:	27bd0068 */ 	addiu	$sp,$sp,0x68
);

GLOBAL_ASM(
glabel anim0002485c
/*    2485c:	27bdffc8 */ 	addiu	$sp,$sp,-56
/*    24860:	8fb80050 */ 	lw	$t8,0x50($sp)
/*    24864:	00077400 */ 	sll	$t6,$a3,0x10
/*    24868:	000e7c03 */ 	sra	$t7,$t6,0x10
/*    2486c:	afb00018 */ 	sw	$s0,0x18($sp)
/*    24870:	afa70044 */ 	sw	$a3,0x44($sp)
/*    24874:	01e03825 */ 	or	$a3,$t7,$zero
/*    24878:	00808025 */ 	or	$s0,$a0,$zero
/*    2487c:	afbf001c */ 	sw	$ra,0x1c($sp)
/*    24880:	afa5003c */ 	sw	$a1,0x3c($sp)
/*    24884:	afa60040 */ 	sw	$a2,0x40($sp)
/*    24888:	1300000b */ 	beqz	$t8,.L000248b8
/*    2488c:	00004025 */ 	or	$t0,$zero,$zero
/*    24890:	8fa2004c */ 	lw	$v0,0x4c($sp)
/*    24894:	3c198006 */ 	lui	$t9,%hi(var8005f014)
/*    24898:	000f4840 */ 	sll	$t1,$t7,0x1
/*    2489c:	a4400000 */ 	sh	$zero,0x0($v0)
/*    248a0:	a4400002 */ 	sh	$zero,0x2($v0)
/*    248a4:	8f39f014 */ 	lw	$t9,%lo(var8005f014)($t9)
/*    248a8:	03295021 */ 	addu	$t2,$t9,$t1
/*    248ac:	854b0000 */ 	lh	$t3,0x0($t2)
/*    248b0:	100000a7 */ 	b	.L00024b50
/*    248b4:	a44b0004 */ 	sh	$t3,0x4($v0)
.L000248b8:
/*    248b8:	00072400 */ 	sll	$a0,$a3,0x10
/*    248bc:	00046403 */ 	sra	$t4,$a0,0x10
/*    248c0:	01802025 */ 	or	$a0,$t4,$zero
/*    248c4:	0c008f4e */ 	jal	anim00023d38
/*    248c8:	a7a70046 */ 	sh	$a3,0x46($sp)
/*    248cc:	87a40046 */ 	lh	$a0,0x46($sp)
/*    248d0:	0c008eac */ 	jal	anim00023ab0
/*    248d4:	8fa50048 */ 	lw	$a1,0x48($sp)
/*    248d8:	0c008f43 */ 	jal	anim00023d0c
/*    248dc:	a3a2002e */ 	sb	$v0,0x2e($sp)
/*    248e0:	93ae002e */ 	lbu	$t6,0x2e($sp)
/*    248e4:	3c0d800a */ 	lui	$t5,%hi(var8009a874)
/*    248e8:	8dada874 */ 	lw	$t5,%lo(var8009a874)($t5)
/*    248ec:	8fb9003c */ 	lw	$t9,0x3c($sp)
/*    248f0:	000e7880 */ 	sll	$t7,$t6,0x2
/*    248f4:	01afc021 */ 	addu	$t8,$t5,$t7
/*    248f8:	13200006 */ 	beqz	$t9,.L00024914
/*    248fc:	8f070000 */ 	lw	$a3,0x0($t8)
/*    24900:	8fa90040 */ 	lw	$t1,0x40($sp)
/*    24904:	00105840 */ 	sll	$t3,$s0,0x1
/*    24908:	8d2a0004 */ 	lw	$t2,0x4($t1)
/*    2490c:	014b6021 */ 	addu	$t4,$t2,$t3
/*    24910:	91900001 */ 	lbu	$s0,0x1($t4)
.L00024914:
/*    24914:	3c0d8006 */ 	lui	$t5,%hi(var8005f010)
/*    24918:	8dadf010 */ 	lw	$t5,%lo(var8005f010)($t5)
/*    2491c:	87ae0046 */ 	lh	$t6,0x46($sp)
/*    24920:	3c09800a */ 	lui	$t1,%hi(var8009a888)
/*    24924:	8d29a888 */ 	lw	$t1,%lo(var8009a888)($t1)
/*    24928:	01cd7821 */ 	addu	$t7,$t6,$t5
/*    2492c:	91f80000 */ 	lbu	$t8,0x0($t7)
/*    24930:	00003025 */ 	or	$a2,$zero,$zero
/*    24934:	00002825 */ 	or	$a1,$zero,$zero
/*    24938:	0018c880 */ 	sll	$t9,$t8,0x2
/*    2493c:	01395021 */ 	addu	$t2,$t1,$t9
/*    24940:	1a00003d */ 	blez	$s0,.L00024a38
/*    24944:	8d430000 */ 	lw	$v1,0x0($t2)
/*    24948:	90640000 */ 	lbu	$a0,0x0($v1)
.L0002494c:
/*    2494c:	24a50001 */ 	addiu	$a1,$a1,0x1
/*    24950:	24630001 */ 	addiu	$v1,$v1,0x1
/*    24954:	308b0008 */ 	andi	$t3,$a0,0x8
/*    24958:	1160000b */ 	beqz	$t3,.L00024988
/*    2495c:	308a0002 */ 	andi	$t2,$a0,0x2
/*    24960:	906c0002 */ 	lbu	$t4,0x2($v1)
/*    24964:	906d0005 */ 	lbu	$t5,0x5($v1)
/*    24968:	90780008 */ 	lbu	$t8,0x8($v1)
/*    2496c:	00cc7021 */ 	addu	$t6,$a2,$t4
/*    24970:	9079000b */ 	lbu	$t9,0xb($v1)
/*    24974:	01cd7821 */ 	addu	$t7,$t6,$t5
/*    24978:	01f84821 */ 	addu	$t1,$t7,$t8
/*    2497c:	2463000c */ 	addiu	$v1,$v1,0xc
/*    24980:	10000014 */ 	b	.L000249d4
/*    24984:	01393021 */ 	addu	$a2,$t1,$t9
.L00024988:
/*    24988:	11400009 */ 	beqz	$t2,.L000249b0
/*    2498c:	30980020 */ 	andi	$t8,$a0,0x20
/*    24990:	906b0002 */ 	lbu	$t3,0x2($v1)
/*    24994:	906e0005 */ 	lbu	$t6,0x5($v1)
/*    24998:	906f0008 */ 	lbu	$t7,0x8($v1)
/*    2499c:	00cb6021 */ 	addu	$t4,$a2,$t3
/*    249a0:	018e6821 */ 	addu	$t5,$t4,$t6
/*    249a4:	24630009 */ 	addiu	$v1,$v1,0x9
/*    249a8:	1000000a */ 	b	.L000249d4
/*    249ac:	01af3021 */ 	addu	$a2,$t5,$t7
.L000249b0:
/*    249b0:	53000009 */ 	beqzl	$t8,.L000249d8
/*    249b4:	308e0001 */ 	andi	$t6,$a0,0x1
/*    249b8:	90690000 */ 	lbu	$t1,0x0($v1)
/*    249bc:	906a0005 */ 	lbu	$t2,0x5($v1)
/*    249c0:	906c000a */ 	lbu	$t4,0xa($v1)
/*    249c4:	00c9c821 */ 	addu	$t9,$a2,$t1
/*    249c8:	032a5821 */ 	addu	$t3,$t9,$t2
/*    249cc:	2463000f */ 	addiu	$v1,$v1,0xf
/*    249d0:	016c3021 */ 	addu	$a2,$t3,$t4
.L000249d4:
/*    249d4:	308e0001 */ 	andi	$t6,$a0,0x1
.L000249d8:
/*    249d8:	11c00009 */ 	beqz	$t6,.L00024a00
/*    249dc:	308b0040 */ 	andi	$t3,$a0,0x40
/*    249e0:	906d0002 */ 	lbu	$t5,0x2($v1)
/*    249e4:	90780005 */ 	lbu	$t8,0x5($v1)
/*    249e8:	90790008 */ 	lbu	$t9,0x8($v1)
/*    249ec:	00cd7821 */ 	addu	$t7,$a2,$t5
/*    249f0:	01f84821 */ 	addu	$t1,$t7,$t8
/*    249f4:	24630009 */ 	addiu	$v1,$v1,0x9
/*    249f8:	10000005 */ 	b	.L00024a10
/*    249fc:	01393021 */ 	addu	$a2,$t1,$t9
.L00024a00:
/*    24a00:	308a0010 */ 	andi	$t2,$a0,0x10
/*    24a04:	11400002 */ 	beqz	$t2,.L00024a10
/*    24a08:	00000000 */ 	nop
/*    24a0c:	24c60060 */ 	addiu	$a2,$a2,0x60
.L00024a10:
/*    24a10:	11600004 */ 	beqz	$t3,.L00024a24
/*    24a14:	308e0080 */ 	andi	$t6,$a0,0x80
/*    24a18:	906c0000 */ 	lbu	$t4,0x0($v1)
/*    24a1c:	24630005 */ 	addiu	$v1,$v1,0x5
/*    24a20:	00cc3021 */ 	addu	$a2,$a2,$t4
.L00024a24:
/*    24a24:	11c00002 */ 	beqz	$t6,.L00024a30
/*    24a28:	00000000 */ 	nop
/*    24a2c:	24c60060 */ 	addiu	$a2,$a2,0x60
.L00024a30:
/*    24a30:	54b0ffc6 */ 	bnel	$a1,$s0,.L0002494c
/*    24a34:	90640000 */ 	lbu	$a0,0x0($v1)
.L00024a38:
/*    24a38:	90650003 */ 	lbu	$a1,0x3($v1)
/*    24a3c:	afa70028 */ 	sw	$a3,0x28($sp)
/*    24a40:	afa60030 */ 	sw	$a2,0x30($sp)
/*    24a44:	afa30024 */ 	sw	$v1,0x24($sp)
/*    24a48:	00e02025 */ 	or	$a0,$a3,$zero
/*    24a4c:	0c008ff8 */ 	jal	anim00023fe0
/*    24a50:	a3a5002f */ 	sb	$a1,0x2f($sp)
/*    24a54:	8fa30024 */ 	lw	$v1,0x24($sp)
/*    24a58:	93a5002f */ 	lbu	$a1,0x2f($sp)
/*    24a5c:	8fa60030 */ 	lw	$a2,0x30($sp)
/*    24a60:	906d0002 */ 	lbu	$t5,0x2($v1)
/*    24a64:	90780001 */ 	lbu	$t8,0x1($v1)
/*    24a68:	8faa004c */ 	lw	$t2,0x4c($sp)
/*    24a6c:	01a27821 */ 	addu	$t7,$t5,$v0
/*    24a70:	00184a00 */ 	sll	$t1,$t8,0x8
/*    24a74:	01e9c821 */ 	addu	$t9,$t7,$t1
/*    24a78:	00c53021 */ 	addu	$a2,$a2,$a1
/*    24a7c:	a5590000 */ 	sh	$t9,0x0($t2)
/*    24a80:	90650006 */ 	lbu	$a1,0x6($v1)
/*    24a84:	afa60030 */ 	sw	$a2,0x30($sp)
/*    24a88:	8fa40028 */ 	lw	$a0,0x28($sp)
/*    24a8c:	0c008ff8 */ 	jal	anim00023fe0
/*    24a90:	a3a5002f */ 	sb	$a1,0x2f($sp)
/*    24a94:	8fa30024 */ 	lw	$v1,0x24($sp)
/*    24a98:	93a5002f */ 	lbu	$a1,0x2f($sp)
/*    24a9c:	8fa60030 */ 	lw	$a2,0x30($sp)
/*    24aa0:	906b0005 */ 	lbu	$t3,0x5($v1)
/*    24aa4:	906e0004 */ 	lbu	$t6,0x4($v1)
/*    24aa8:	8fb0004c */ 	lw	$s0,0x4c($sp)
/*    24aac:	01626021 */ 	addu	$t4,$t3,$v0
/*    24ab0:	000e6a00 */ 	sll	$t5,$t6,0x8
/*    24ab4:	018dc021 */ 	addu	$t8,$t4,$t5
/*    24ab8:	00c53021 */ 	addu	$a2,$a2,$a1
/*    24abc:	a6180002 */ 	sh	$t8,0x2($s0)
/*    24ac0:	90650009 */ 	lbu	$a1,0x9($v1)
/*    24ac4:	afa60030 */ 	sw	$a2,0x30($sp)
/*    24ac8:	8fa40028 */ 	lw	$a0,0x28($sp)
/*    24acc:	0c008ff8 */ 	jal	anim00023fe0
/*    24ad0:	a3a5002f */ 	sb	$a1,0x2f($sp)
/*    24ad4:	8fa30024 */ 	lw	$v1,0x24($sp)
/*    24ad8:	93a5002f */ 	lbu	$a1,0x2f($sp)
/*    24adc:	8fa60030 */ 	lw	$a2,0x30($sp)
/*    24ae0:	906f0008 */ 	lbu	$t7,0x8($v1)
/*    24ae4:	90790007 */ 	lbu	$t9,0x7($v1)
/*    24ae8:	00c53021 */ 	addu	$a2,$a2,$a1
/*    24aec:	01e24821 */ 	addu	$t1,$t7,$v0
/*    24af0:	00195200 */ 	sll	$t2,$t9,0x8
/*    24af4:	012a5821 */ 	addu	$t3,$t1,$t2
/*    24af8:	a60b0004 */ 	sh	$t3,0x4($s0)
/*    24afc:	8fa40028 */ 	lw	$a0,0x28($sp)
/*    24b00:	0c008ff8 */ 	jal	anim00023fe0
/*    24b04:	9065000c */ 	lbu	$a1,0xc($v1)
/*    24b08:	8fa30024 */ 	lw	$v1,0x24($sp)
/*    24b0c:	8fb9003c */ 	lw	$t9,0x3c($sp)
/*    24b10:	906e000b */ 	lbu	$t6,0xb($v1)
/*    24b14:	906d000a */ 	lbu	$t5,0xa($v1)
/*    24b18:	01c26021 */ 	addu	$t4,$t6,$v0
/*    24b1c:	000dc200 */ 	sll	$t8,$t5,0x8
/*    24b20:	01984021 */ 	addu	$t0,$t4,$t8
/*    24b24:	310fffff */ 	andi	$t7,$t0,0xffff
/*    24b28:	13200009 */ 	beqz	$t9,.L00024b50
/*    24b2c:	01e04025 */ 	or	$t0,$t7,$zero
/*    24b30:	86090000 */ 	lh	$t1,0x0($s0)
/*    24b34:	3c0b0001 */ 	lui	$t3,0x1
/*    24b38:	00095023 */ 	negu	$t2,$t1
/*    24b3c:	11e00004 */ 	beqz	$t7,.L00024b50
/*    24b40:	a60a0000 */ 	sh	$t2,0x0($s0)
/*    24b44:	016f4023 */ 	subu	$t0,$t3,$t7
/*    24b48:	310effff */ 	andi	$t6,$t0,0xffff
/*    24b4c:	01c04025 */ 	or	$t0,$t6,$zero
.L00024b50:
/*    24b50:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*    24b54:	8fb00018 */ 	lw	$s0,0x18($sp)
/*    24b58:	27bd0038 */ 	addiu	$sp,$sp,0x38
/*    24b5c:	03e00008 */ 	jr	$ra
/*    24b60:	01001025 */ 	or	$v0,$t0,$zero
);

f32 anim00024b64(u32 arg0, u32 arg1, struct modeltype *arg2, s16 animnum, u32 arg4, struct coord *coord, u32 arg6)
{
	s16 sp30[3];

	f32 value = anim0002485c(arg0, arg1, arg2, animnum, arg4, sp30, arg6);

	coord->x = sp30[0];
	coord->y = sp30[1];
	coord->z = sp30[2];

	return (value * M_BADTAU) / 65536.0f;
}

f32 anim00024c14(s32 arg0, s16 animnum, u8 arg2)
{
	u32 stack[2];
	u8 *sp24 = var8009a874[arg2];
	u8 *ptr = (u8 *)var8009a888[var8005f010[animnum]];
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
