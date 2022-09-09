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

void animsReset(void)
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

#if MATCHING
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
#else
// Mismatch: for loop is handled differently
void anim00023d38(s16 animnum)
{
	s32 i;

	if (var8005f010[animnum] != 0xff) {
		var8009a890[var8005f010[animnum]] = g_Vars.thisframe240;
		var8005f004 = (var8005f010[animnum] + 1) % 40;
	} else {
		s32 index = var8005f004;
		s32 bestvalue = var8009a890[index];
		s32 stack;
		s32 tmp;

		for (i = 0; i < 40; i++) {
			if (var8009a890[i] < bestvalue) {
				bestvalue = var8009a890[i];
				index = i;
			}
		}

		tmp = var8009a88c[index];

		if (tmp) {
			var8005f010[tmp] = 0xff;
		}

		tmp = g_Anims[animnum].headerlen;

		var8009a888[index] = animDma(&var8009a884[var8005f01c * index], g_Anims[animnum].data, tmp);
		var8005f010[animnum] = index;
		var8009a88c[index] = animnum;
		var8009a890[index] = g_Vars.thisframe240;
		var8005f004 = (index + 1) % 40;
	}
}
#endif

#if MATCHING
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
#else
// Mismatch: regalloc
s32 anim00023f50(u8 *arg0, u8 arg1, u32 arg2)
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
#endif

s32 anim00023fe0(u8 *arg0, u8 arg1, s32 arg2)
{
	u16 result = anim00023f50(arg0, arg1, arg2);

	if (arg1 < 16 && (result & 1 << (arg1 + 31))) {
		result |= (1 << (16 - arg1)) - 1 << arg1;
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

	return (value * M_BADTAU) / 65536.0f;
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
