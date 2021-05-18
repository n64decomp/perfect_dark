#include <ultra64.h>
#include "constants.h"
#include "game/cheats.h"
#include "game/chr/chraction.h"
#include "game/chr/chr.h"
#include "game/game_02cde0.h"
#include "game/prop.h"
#include "game/atan2f.h"
#include "game/game_0b28d0.h"
#include "game/lv.h"
#include "game/game_1a7560.h"
#include "game/mplayer/mplayer.h"
#include "game/pad.h"
#include "game/propobj.h"
#include "bss.h"
#include "lib/memory.h"
#include "lib/model.h"
#include "lib/lib_126b0.h"
#include "lib/rng.h"
#include "lib/lib_16110.h"
#include "lib/lib_184d0.h"
#include "lib/lib_233c0.h"
#include "lib/lib_24e40.h"
#include "data.h"
#include "types.h"

s32 g_NumActiveHeadsPerGender;
u32 var8009cd24;
u32 g_ActiveMaleHeads[8];
u32 g_ActiveFemaleHeads[8];

s32 g_NumBondBodies = 0;
s32 g_NumMaleGuardHeads = 0;
s32 g_NumFemaleGuardHeads = 0;
s32 g_NumMaleGuardTeamHeads = 0;
s32 g_NumFemaleGuardTeamHeads = 0;
s32 var80062b14 = 0;
s32 var80062b18 = 0;

s32 g_BondBodies[] = {
	BODY_DJBOND,
	BODY_CONNERY,
	BODY_DALTON,
	BODY_MOORE,
	-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
};

s32 g_MaleGuardHeads[] = {
	HEAD_BEAU1,
	HEAD_CHRIST,
	HEAD_DARLING,
	HEAD_JON,
	HEAD_ROSS,
	HEAD_RUSS,
	HEAD_MARK2,
	HEAD_JAMIE,
	HEAD_DUNCAN2,
	HEAD_BRIAN,
	HEAD_STEVEM,
	HEAD_KEITH,
	HEAD_GRANT,
	HEAD_PENNY,
	HEAD_DAVEC,
	HEAD_JONES,
	HEAD_GRAHAM,
	HEAD_SHAUN,
	HEAD_NEIL2,
	HEAD_EDMCG,
	HEAD_MATT_C,
	HEAD_PEER_S,
	HEAD_ANDY_R,
	HEAD_BEN_R,
	HEAD_STEVE_K,
	HEAD_SCOTT_H,
	HEAD_SANCHEZ,
	HEAD_COOK,
	HEAD_PRYCE,
	HEAD_SILKE,
	HEAD_SMITH,
	HEAD_GARETH,
	HEAD_MURCHIE,
	HEAD_WONG,
	HEAD_CARTER,
	HEAD_TINTIN,
	HEAD_MUNTON,
	HEAD_PHELPS,
	HEAD_KEN,
	HEAD_JOEL,
	HEAD_TIM,
	HEAD_ROBIN,
	-1,
};

s32 g_MaleGuardTeamHeads[] = {
	HEAD_BEAU1,
	HEAD_CHRIST,
	HEAD_DARLING,
	HEAD_JON,
	HEAD_ROSS,
	HEAD_RUSS,
	HEAD_MARK2,
	HEAD_JAMIE,
	HEAD_DUNCAN2,
	HEAD_BRIAN,
	HEAD_STEVEM,
	HEAD_KEITH,
	HEAD_GRANT,
	HEAD_PENNY,
	HEAD_DAVEC,
	HEAD_JONES,
	-1,
};

s32 g_FemaleGuardHeads[] = {
	HEAD_LESLIE_S,
	HEAD_ANKA,
	HEAD_EILEEN_T,
	HEAD_EILEEN_H,
	-1,
};

s32 g_FemaleGuardTeamHeads[] = {
	HEAD_LESLIE_S,
	HEAD_ANKA,
	HEAD_EILEEN_T,
	HEAD_EILEEN_H,
	-1,
};

s32 var80062c80 = 0;
s32 g_ActiveMaleHeadsIndex = 0;
s32 g_ActiveFemaleHeadsIndex = 0;

s32 g_FemGuardHeads[3] = {
	HEAD_ALEX,
	HEAD_JULIANNE,
	HEAD_LAURA,
};

u32 bodyGetRace(s32 bodynum)
{
	switch (bodynum) {
	case BODY_SKEDAR:
	case BODY_MINISKEDAR:
	case BODY_SKEDARKING:
		return RACE_SKEDAR;
	case BODY_DRCAROLL:
		return RACE_DRCAROLL;
	case BODY_EYESPY:
		return RACE_EYESPY;
	case BODY_CHICROB:
		return RACE_ROBOT;
	}

	return RACE_HUMAN;
}

bool bodyLoad(s32 bodynum)
{
	if (!g_HeadsAndBodies[bodynum].filedata) {
		g_HeadsAndBodies[bodynum].filedata = fileLoad(g_HeadsAndBodies[bodynum].filenum);
		return true;
	}

	return false;
}

GLOBAL_ASM(
glabel func0f02ce8c
.late_rodata
glabel var7f1a8a70
.word 0x3dccccce
glabel var7f1a8a74
.word 0x3f4ccccd
glabel var7f1a8a78
.word 0x3d4ccccd
glabel var7f1a8a7c
.word 0x3ecccccd
glabel var7f1a8a80
.word 0x3ecccccd
glabel var7f1a8a84
.word 0x3dcccccd
.text
/*  f02ce8c:	00047880 */ 	sll	$t7,$a0,0x2
/*  f02ce90:	01e47821 */ 	addu	$t7,$t7,$a0
/*  f02ce94:	3c188008 */ 	lui	$t8,%hi(g_HeadsAndBodies)
/*  f02ce98:	2718cf04 */ 	addiu	$t8,$t8,%lo(g_HeadsAndBodies)
/*  f02ce9c:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f02cea0:	01f81021 */ 	addu	$v0,$t7,$t8
/*  f02cea4:	3c017f1b */ 	lui	$at,%hi(var7f1a8a70)
/*  f02cea8:	c4268a70 */ 	lwc1	$f6,%lo(var7f1a8a70)($at)
/*  f02ceac:	c4440004 */ 	lwc1	$f4,0x4($v0)
/*  f02ceb0:	27bdffb8 */ 	addiu	$sp,$sp,-72
/*  f02ceb4:	c44a0008 */ 	lwc1	$f10,0x8($v0)
/*  f02ceb8:	46062202 */ 	mul.s	$f8,$f4,$f6
/*  f02cebc:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f02cec0:	afa40048 */ 	sw	$a0,0x48($sp)
/*  f02cec4:	afa5004c */ 	sw	$a1,0x4c($sp)
/*  f02cec8:	afa60050 */ 	sw	$a2,0x50($sp)
/*  f02cecc:	afa70054 */ 	sw	$a3,0x54($sp)
/*  f02ced0:	afa0003c */ 	sw	$zero,0x3c($sp)
/*  f02ced4:	e7a80044 */ 	swc1	$f8,0x44($sp)
/*  f02ced8:	24040007 */ 	addiu	$a0,$zero,0x7
/*  f02cedc:	afa2001c */ 	sw	$v0,0x1c($sp)
/*  f02cee0:	0fc41b99 */ 	jal	cheatIsActive
/*  f02cee4:	e7aa0040 */ 	swc1	$f10,0x40($sp)
/*  f02cee8:	10400005 */ 	beqz	$v0,.L0f02cf00
/*  f02ceec:	c7b00044 */ 	lwc1	$f16,0x44($sp)
/*  f02cef0:	3c017f1b */ 	lui	$at,%hi(var7f1a8a74)
/*  f02cef4:	c4328a74 */ 	lwc1	$f18,%lo(var7f1a8a74)($at)
/*  f02cef8:	46128102 */ 	mul.s	$f4,$f16,$f18
/*  f02cefc:	e7a40044 */ 	swc1	$f4,0x44($sp)
.L0f02cf00:
/*  f02cf00:	8fb90050 */ 	lw	$t9,0x50($sp)
/*  f02cf04:	8fa8001c */ 	lw	$t0,0x1c($sp)
/*  f02cf08:	1720000a */ 	bnez	$t9,.L0f02cf34
/*  f02cf0c:	00000000 */ 	nop
/*  f02cf10:	8d03000c */ 	lw	$v1,0xc($t0)
/*  f02cf14:	54600007 */ 	bnezl	$v1,.L0f02cf34
/*  f02cf18:	afa30050 */ 	sw	$v1,0x50($sp)
/*  f02cf1c:	0fc69e11 */ 	jal	fileLoad
/*  f02cf20:	95040002 */ 	lhu	$a0,0x2($t0)
/*  f02cf24:	8fa4001c */ 	lw	$a0,0x1c($sp)
/*  f02cf28:	00401825 */ 	or	$v1,$v0,$zero
/*  f02cf2c:	ac82000c */ 	sw	$v0,0xc($a0)
/*  f02cf30:	afa30050 */ 	sw	$v1,0x50($sp)
.L0f02cf34:
/*  f02cf34:	0c008b49 */ 	jal	modelCalculateRwDataLen
/*  f02cf38:	8fa40050 */ 	lw	$a0,0x50($sp)
/*  f02cf3c:	8fa9001c */ 	lw	$t1,0x1c($sp)
/*  f02cf40:	8fac0050 */ 	lw	$t4,0x50($sp)
/*  f02cf44:	8d220000 */ 	lw	$v0,0x0($t1)
/*  f02cf48:	00025840 */ 	sll	$t3,$v0,0x1
/*  f02cf4c:	056200b9 */ 	bltzl	$t3,.L0f02d234
/*  f02cf50:	8fa2005c */ 	lw	$v0,0x5c($sp)
/*  f02cf54:	8d830004 */ 	lw	$v1,0x4($t4)
/*  f02cf58:	3c0d8008 */ 	lui	$t5,%hi(g_ModelTypeChr)
/*  f02cf5c:	25adce40 */ 	addiu	$t5,$t5,%lo(g_ModelTypeChr)
/*  f02cf60:	15a30090 */ 	bne	$t5,$v1,.L0f02d1a4
/*  f02cf64:	01802025 */ 	or	$a0,$t4,$zero
/*  f02cf68:	0c006a47 */ 	jal	modelGetPart
/*  f02cf6c:	24050004 */ 	addiu	$a1,$zero,0x4
/*  f02cf70:	104000af */ 	beqz	$v0,.L0f02d230
/*  f02cf74:	afa2003c */ 	sw	$v0,0x3c($sp)
/*  f02cf78:	8fa7004c */ 	lw	$a3,0x4c($sp)
/*  f02cf7c:	240effff */ 	addiu	$t6,$zero,-1
/*  f02cf80:	04e1000a */ 	bgez	$a3,.L0f02cfac
/*  f02cf84:	01c72023 */ 	subu	$a0,$t6,$a3
/*  f02cf88:	0fc6395f */ 	jal	func0f18e57c
/*  f02cf8c:	27a5004c */ 	addiu	$a1,$sp,0x4c
/*  f02cf90:	8faf0050 */ 	lw	$t7,0x50($sp)
/*  f02cf94:	afa20054 */ 	sw	$v0,0x54($sp)
/*  f02cf98:	84590014 */ 	lh	$t9,0x14($v0)
/*  f02cf9c:	85f80014 */ 	lh	$t8,0x14($t7)
/*  f02cfa0:	03194021 */ 	addu	$t0,$t8,$t9
/*  f02cfa4:	10000061 */ 	b	.L0f02d12c
/*  f02cfa8:	a5e80014 */ 	sh	$t0,0x14($t7)
.L0f02cfac:
/*  f02cfac:	18e0005f */ 	blez	$a3,.L0f02d12c
/*  f02cfb0:	8fa90054 */ 	lw	$t1,0x54($sp)
/*  f02cfb4:	15200036 */ 	bnez	$t1,.L0f02d090
/*  f02cfb8:	3c0a800a */ 	lui	$t2,%hi(g_Vars+0x318)
/*  f02cfbc:	8d4aa2d8 */ 	lw	$t2,%lo(g_Vars+0x318)($t2)
/*  f02cfc0:	00074080 */ 	sll	$t0,$a3,0x2
/*  f02cfc4:	3c0b8009 */ 	lui	$t3,%hi(g_Is4Mb)
/*  f02cfc8:	1140001e */ 	beqz	$t2,.L0f02d044
/*  f02cfcc:	01074021 */ 	addu	$t0,$t0,$a3
/*  f02cfd0:	916b0af0 */ 	lbu	$t3,%lo(g_Is4Mb)($t3)
/*  f02cfd4:	24010001 */ 	addiu	$at,$zero,0x1
/*  f02cfd8:	00076880 */ 	sll	$t5,$a3,0x2
/*  f02cfdc:	11610019 */ 	beq	$t3,$at,.L0f02d044
/*  f02cfe0:	01a76821 */ 	addu	$t5,$t5,$a3
/*  f02cfe4:	000d6880 */ 	sll	$t5,$t5,0x2
/*  f02cfe8:	3c048008 */ 	lui	$a0,%hi(g_HeadsAndBodies+0x2)
/*  f02cfec:	008d2021 */ 	addu	$a0,$a0,$t5
/*  f02cff0:	0fc69e11 */ 	jal	fileLoad
/*  f02cff4:	9484cf06 */ 	lhu	$a0,%lo(g_HeadsAndBodies+0x2)($a0)
/*  f02cff8:	8fa5004c */ 	lw	$a1,0x4c($sp)
/*  f02cffc:	3c0e8008 */ 	lui	$t6,%hi(g_HeadsAndBodies)
/*  f02d000:	25cecf04 */ 	addiu	$t6,$t6,%lo(g_HeadsAndBodies)
/*  f02d004:	00056080 */ 	sll	$t4,$a1,0x2
/*  f02d008:	01856021 */ 	addu	$t4,$t4,$a1
/*  f02d00c:	000c6080 */ 	sll	$t4,$t4,0x2
/*  f02d010:	018e1821 */ 	addu	$v1,$t4,$t6
/*  f02d014:	94780002 */ 	lhu	$t8,0x2($v1)
/*  f02d018:	3c01800a */ 	lui	$at,%hi(g_FileInfo)
/*  f02d01c:	ac62000c */ 	sw	$v0,0xc($v1)
/*  f02d020:	0018c8c0 */ 	sll	$t9,$t8,0x3
/*  f02d024:	00390821 */ 	addu	$at,$at,$t9
/*  f02d028:	afa20054 */ 	sw	$v0,0x54($sp)
/*  f02d02c:	ac206680 */ 	sw	$zero,%lo(g_FileInfo)($at)
/*  f02d030:	00402025 */ 	or	$a0,$v0,$zero
/*  f02d034:	0fc0b76f */ 	jal	func0f02ddbc
/*  f02d038:	8fa60048 */ 	lw	$a2,0x48($sp)
/*  f02d03c:	10000014 */ 	b	.L0f02d090
/*  f02d040:	00000000 */ 	nop
.L0f02d044:
/*  f02d044:	3c0f8008 */ 	lui	$t7,%hi(g_HeadsAndBodies)
/*  f02d048:	25efcf04 */ 	addiu	$t7,$t7,%lo(g_HeadsAndBodies)
/*  f02d04c:	00084080 */ 	sll	$t0,$t0,0x2
/*  f02d050:	010f1821 */ 	addu	$v1,$t0,$t7
/*  f02d054:	8c64000c */ 	lw	$a0,0xc($v1)
/*  f02d058:	5480000d */ 	bnezl	$a0,.L0f02d090
/*  f02d05c:	afa40054 */ 	sw	$a0,0x54($sp)
/*  f02d060:	0fc69e11 */ 	jal	fileLoad
/*  f02d064:	94640002 */ 	lhu	$a0,0x2($v1)
/*  f02d068:	8fa7004c */ 	lw	$a3,0x4c($sp)
/*  f02d06c:	3c0a8008 */ 	lui	$t2,%hi(g_HeadsAndBodies)
/*  f02d070:	254acf04 */ 	addiu	$t2,$t2,%lo(g_HeadsAndBodies)
/*  f02d074:	00074880 */ 	sll	$t1,$a3,0x2
/*  f02d078:	01274821 */ 	addu	$t1,$t1,$a3
/*  f02d07c:	00094880 */ 	sll	$t1,$t1,0x2
/*  f02d080:	012a1821 */ 	addu	$v1,$t1,$t2
/*  f02d084:	ac62000c */ 	sw	$v0,0xc($v1)
/*  f02d088:	00402025 */ 	or	$a0,$v0,$zero
/*  f02d08c:	afa40054 */ 	sw	$a0,0x54($sp)
.L0f02d090:
/*  f02d090:	0c008b49 */ 	jal	modelCalculateRwDataLen
/*  f02d094:	8fa40054 */ 	lw	$a0,0x54($sp)
/*  f02d098:	8fab0050 */ 	lw	$t3,0x50($sp)
/*  f02d09c:	8fac0054 */ 	lw	$t4,0x54($sp)
/*  f02d0a0:	856d0014 */ 	lh	$t5,0x14($t3)
/*  f02d0a4:	858e0014 */ 	lh	$t6,0x14($t4)
/*  f02d0a8:	01aec021 */ 	addu	$t8,$t5,$t6
/*  f02d0ac:	a5780014 */ 	sh	$t8,0x14($t3)
/*  f02d0b0:	8fb9001c */ 	lw	$t9,0x1c($sp)
/*  f02d0b4:	93aa0067 */ 	lbu	$t2,0x67($sp)
/*  f02d0b8:	8f280000 */ 	lw	$t0,0x0($t9)
/*  f02d0bc:	00084880 */ 	sll	$t1,$t0,0x2
/*  f02d0c0:	0523001b */ 	bgezl	$t1,.L0f02d130
/*  f02d0c4:	8fac0060 */ 	lw	$t4,0x60($sp)
/*  f02d0c8:	51400019 */ 	beqzl	$t2,.L0f02d130
/*  f02d0cc:	8fac0060 */ 	lw	$t4,0x60($sp)
/*  f02d0d0:	0c004b70 */ 	jal	random
/*  f02d0d4:	00000000 */ 	nop
/*  f02d0d8:	44823000 */ 	mtc1	$v0,$f6
/*  f02d0dc:	3c017f1b */ 	lui	$at,%hi(var7f1a8a78)
/*  f02d0e0:	c4228a78 */ 	lwc1	$f2,%lo(var7f1a8a78)($at)
/*  f02d0e4:	04410005 */ 	bgez	$v0,.L0f02d0fc
/*  f02d0e8:	46803220 */ 	cvt.s.w	$f8,$f6
/*  f02d0ec:	3c014f80 */ 	lui	$at,0x4f80
/*  f02d0f0:	44815000 */ 	mtc1	$at,$f10
/*  f02d0f4:	00000000 */ 	nop
/*  f02d0f8:	460a4200 */ 	add.s	$f8,$f8,$f10
.L0f02d0fc:
/*  f02d0fc:	3c012f80 */ 	lui	$at,0x2f80
/*  f02d100:	44818000 */ 	mtc1	$at,$f16
/*  f02d104:	3c013f80 */ 	lui	$at,0x3f80
/*  f02d108:	44815000 */ 	mtc1	$at,$f10
/*  f02d10c:	46104482 */ 	mul.s	$f18,$f8,$f16
/*  f02d110:	c7b00044 */ 	lwc1	$f16,0x44($sp)
/*  f02d114:	46029002 */ 	mul.s	$f0,$f18,$f2
/*  f02d118:	46000100 */ 	add.s	$f4,$f0,$f0
/*  f02d11c:	46022181 */ 	sub.s	$f6,$f4,$f2
/*  f02d120:	460a3200 */ 	add.s	$f8,$f6,$f10
/*  f02d124:	46088482 */ 	mul.s	$f18,$f16,$f8
/*  f02d128:	e7b20044 */ 	swc1	$f18,0x44($sp)
.L0f02d12c:
/*  f02d12c:	8fac0060 */ 	lw	$t4,0x60($sp)
.L0f02d130:
/*  f02d130:	15800013 */ 	bnez	$t4,.L0f02d180
/*  f02d134:	00000000 */ 	nop
/*  f02d138:	0fc41b99 */ 	jal	cheatIsActive
/*  f02d13c:	2404000b */ 	addiu	$a0,$zero,0xb
/*  f02d140:	10400005 */ 	beqz	$v0,.L0f02d158
/*  f02d144:	c7a40044 */ 	lwc1	$f4,0x44($sp)
/*  f02d148:	3c017f1b */ 	lui	$at,%hi(var7f1a8a7c)
/*  f02d14c:	c4268a7c */ 	lwc1	$f6,%lo(var7f1a8a7c)($at)
/*  f02d150:	46062282 */ 	mul.s	$f10,$f4,$f6
/*  f02d154:	e7aa0044 */ 	swc1	$f10,0x44($sp)
.L0f02d158:
/*  f02d158:	0fc41b99 */ 	jal	cheatIsActive
/*  f02d15c:	24040007 */ 	addiu	$a0,$zero,0x7
/*  f02d160:	10400033 */ 	beqz	$v0,.L0f02d230
/*  f02d164:	c7b00044 */ 	lwc1	$f16,0x44($sp)
/*  f02d168:	3c013fa0 */ 	lui	$at,0x3fa0
/*  f02d16c:	44814000 */ 	mtc1	$at,$f8
/*  f02d170:	00000000 */ 	nop
/*  f02d174:	46088482 */ 	mul.s	$f18,$f16,$f8
/*  f02d178:	1000002d */ 	b	.L0f02d230
/*  f02d17c:	e7b20044 */ 	swc1	$f18,0x44($sp)
.L0f02d180:
/*  f02d180:	0fc41b99 */ 	jal	cheatIsActive
/*  f02d184:	2404000a */ 	addiu	$a0,$zero,0xa
/*  f02d188:	10400029 */ 	beqz	$v0,.L0f02d230
/*  f02d18c:	c7a40044 */ 	lwc1	$f4,0x44($sp)
/*  f02d190:	3c017f1b */ 	lui	$at,%hi(var7f1a8a80)
/*  f02d194:	c4268a80 */ 	lwc1	$f6,%lo(var7f1a8a80)($at)
/*  f02d198:	46062282 */ 	mul.s	$f10,$f4,$f6
/*  f02d19c:	10000024 */ 	b	.L0f02d230
/*  f02d1a0:	e7aa0044 */ 	swc1	$f10,0x44($sp)
.L0f02d1a4:
/*  f02d1a4:	3c0d8008 */ 	lui	$t5,%hi(g_ModelTypeSkedar)
/*  f02d1a8:	25adce98 */ 	addiu	$t5,$t5,%lo(g_ModelTypeSkedar)
/*  f02d1ac:	15a30020 */ 	bne	$t5,$v1,.L0f02d230
/*  f02d1b0:	0002c080 */ 	sll	$t8,$v0,0x2
/*  f02d1b4:	0701001e */ 	bgez	$t8,.L0f02d230
/*  f02d1b8:	93ab0067 */ 	lbu	$t3,0x67($sp)
/*  f02d1bc:	1160001c */ 	beqz	$t3,.L0f02d230
/*  f02d1c0:	8fb9001c */ 	lw	$t9,0x1c($sp)
/*  f02d1c4:	3c088008 */ 	lui	$t0,%hi(g_HeadsAndBodies+0x730)
/*  f02d1c8:	2508d634 */ 	addiu	$t0,$t0,%lo(g_HeadsAndBodies+0x730)
/*  f02d1cc:	57280019 */ 	bnel	$t9,$t0,.L0f02d234
/*  f02d1d0:	8fa2005c */ 	lw	$v0,0x5c($sp)
/*  f02d1d4:	0c004b70 */ 	jal	random
/*  f02d1d8:	00000000 */ 	nop
/*  f02d1dc:	44828000 */ 	mtc1	$v0,$f16
/*  f02d1e0:	3c017f1b */ 	lui	$at,%hi(var7f1a8a84)
/*  f02d1e4:	c4228a84 */ 	lwc1	$f2,%lo(var7f1a8a84)($at)
/*  f02d1e8:	04410005 */ 	bgez	$v0,.L0f02d200
/*  f02d1ec:	46808220 */ 	cvt.s.w	$f8,$f16
/*  f02d1f0:	3c014f80 */ 	lui	$at,0x4f80
/*  f02d1f4:	44819000 */ 	mtc1	$at,$f18
/*  f02d1f8:	00000000 */ 	nop
/*  f02d1fc:	46124200 */ 	add.s	$f8,$f8,$f18
.L0f02d200:
/*  f02d200:	3c012f80 */ 	lui	$at,0x2f80
/*  f02d204:	44812000 */ 	mtc1	$at,$f4
/*  f02d208:	3c013f40 */ 	lui	$at,0x3f40
/*  f02d20c:	44819000 */ 	mtc1	$at,$f18
/*  f02d210:	46044182 */ 	mul.s	$f6,$f8,$f4
/*  f02d214:	c7a40044 */ 	lwc1	$f4,0x44($sp)
/*  f02d218:	46061002 */ 	mul.s	$f0,$f2,$f6
/*  f02d21c:	46000280 */ 	add.s	$f10,$f0,$f0
/*  f02d220:	46025401 */ 	sub.s	$f16,$f10,$f2
/*  f02d224:	46128200 */ 	add.s	$f8,$f16,$f18
/*  f02d228:	46082182 */ 	mul.s	$f6,$f4,$f8
/*  f02d22c:	e7a60044 */ 	swc1	$f6,0x44($sp)
.L0f02d230:
/*  f02d230:	8fa2005c */ 	lw	$v0,0x5c($sp)
.L0f02d234:
/*  f02d234:	8fa90050 */ 	lw	$t1,0x50($sp)
/*  f02d238:	10400008 */ 	beqz	$v0,.L0f02d25c
/*  f02d23c:	00000000 */ 	nop
/*  f02d240:	844f0002 */ 	lh	$t7,0x2($v0)
/*  f02d244:	852a0014 */ 	lh	$t2,0x14($t1)
/*  f02d248:	01ea082a */ 	slt	$at,$t7,$t2
/*  f02d24c:	50200007 */ 	beqzl	$at,.L0f02d26c
/*  f02d250:	8fac005c */ 	lw	$t4,0x5c($sp)
/*  f02d254:	10000005 */ 	b	.L0f02d26c
/*  f02d258:	8fac005c */ 	lw	$t4,0x5c($sp)
.L0f02d25c:
/*  f02d25c:	0fc2cca0 */ 	jal	func0f0b3280
/*  f02d260:	8fa40050 */ 	lw	$a0,0x50($sp)
/*  f02d264:	afa2005c */ 	sw	$v0,0x5c($sp)
/*  f02d268:	8fac005c */ 	lw	$t4,0x5c($sp)
.L0f02d26c:
/*  f02d26c:	1180002d */ 	beqz	$t4,.L0f02d324
/*  f02d270:	01802025 */ 	or	$a0,$t4,$zero
/*  f02d274:	0c006bd6 */ 	jal	modelSetScale
/*  f02d278:	8fa50044 */ 	lw	$a1,0x44($sp)
/*  f02d27c:	8fa4005c */ 	lw	$a0,0x5c($sp)
/*  f02d280:	0c006bd9 */ 	jal	modelSetAnimScale
/*  f02d284:	8fa50040 */ 	lw	$a1,0x40($sp)
/*  f02d288:	8fa60054 */ 	lw	$a2,0x54($sp)
/*  f02d28c:	8fad001c */ 	lw	$t5,0x1c($sp)
/*  f02d290:	50c00025 */ 	beqzl	$a2,.L0f02d328
/*  f02d294:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f02d298:	8dae0000 */ 	lw	$t6,0x0($t5)
/*  f02d29c:	8fb90050 */ 	lw	$t9,0x50($sp)
/*  f02d2a0:	000e5840 */ 	sll	$t3,$t6,0x1
/*  f02d2a4:	05620020 */ 	bltzl	$t3,.L0f02d328
/*  f02d2a8:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f02d2ac:	87280014 */ 	lh	$t0,0x14($t9)
/*  f02d2b0:	84c90014 */ 	lh	$t1,0x14($a2)
/*  f02d2b4:	01097823 */ 	subu	$t7,$t0,$t1
/*  f02d2b8:	a72f0014 */ 	sh	$t7,0x14($t9)
/*  f02d2bc:	8fa5003c */ 	lw	$a1,0x3c($sp)
/*  f02d2c0:	0fc2cca8 */ 	jal	func0f0b32a0
/*  f02d2c4:	8fa4005c */ 	lw	$a0,0x5c($sp)
/*  f02d2c8:	8faa0054 */ 	lw	$t2,0x54($sp)
/*  f02d2cc:	2401000d */ 	addiu	$at,$zero,0xd
/*  f02d2d0:	8fad0058 */ 	lw	$t5,0x58($sp)
/*  f02d2d4:	854c0006 */ 	lh	$t4,0x6($t2)
/*  f02d2d8:	55810013 */ 	bnel	$t4,$at,.L0f02d328
/*  f02d2dc:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f02d2e0:	15a00008 */ 	bnez	$t5,.L0f02d304
/*  f02d2e4:	01402025 */ 	or	$a0,$t2,$zero
/*  f02d2e8:	0c006a47 */ 	jal	modelGetPart
/*  f02d2ec:	00002825 */ 	or	$a1,$zero,$zero
/*  f02d2f0:	10400004 */ 	beqz	$v0,.L0f02d304
/*  f02d2f4:	00402825 */ 	or	$a1,$v0,$zero
/*  f02d2f8:	0c006a87 */ 	jal	modelGetNodeRwData
/*  f02d2fc:	8fa4005c */ 	lw	$a0,0x5c($sp)
/*  f02d300:	ac400000 */ 	sw	$zero,0x0($v0)
.L0f02d304:
/*  f02d304:	8fa40054 */ 	lw	$a0,0x54($sp)
/*  f02d308:	0c006a47 */ 	jal	modelGetPart
/*  f02d30c:	24050004 */ 	addiu	$a1,$zero,0x4
/*  f02d310:	10400004 */ 	beqz	$v0,.L0f02d324
/*  f02d314:	00402825 */ 	or	$a1,$v0,$zero
/*  f02d318:	0c006a87 */ 	jal	modelGetNodeRwData
/*  f02d31c:	8fa4005c */ 	lw	$a0,0x5c($sp)
/*  f02d320:	ac400000 */ 	sw	$zero,0x0($v0)
.L0f02d324:
/*  f02d324:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f02d328:
/*  f02d328:	8fa2005c */ 	lw	$v0,0x5c($sp)
/*  f02d32c:	27bd0048 */ 	addiu	$sp,$sp,0x48
/*  f02d330:	03e00008 */ 	jr	$ra
/*  f02d334:	00000000 */ 	nop
);

// Mismatch: The model->unk02 < headfiledata->rwdatalen statement needs to use
// bodyfiledata instead of headfiledata, but the extra reference to bodyfiledata
// causes bodyfiledata to be promoted from t registers to a registers, which
// causes significant codegen changes.
//struct model *func0f02ce8c(s32 bodynum, s32 headnum, struct modelfiledata *bodyfiledata, struct modelfiledata *headfiledata, bool sunglasses, struct model *model, bool isplayer, u8 varyheight)
//{
//	f32 scale = g_HeadsAndBodies[bodynum].scale * 0.1f;
//	f32 animscale = g_HeadsAndBodies[bodynum].animscale;
//	struct modelnode *node = NULL;
//	u32 stack[2];
//
//	if (cheatIsActive(CHEAT_DKMODE)) {
//		scale *= 0.8f;
//	}
//
//	if (bodyfiledata == NULL) {
//		if (g_HeadsAndBodies[bodynum].filedata == NULL) {
//			g_HeadsAndBodies[bodynum].filedata = fileLoad(g_HeadsAndBodies[bodynum].filenum);
//		}
//
//		bodyfiledata = g_HeadsAndBodies[bodynum].filedata;
//	}
//
//	modelCalculateRwDataLen(bodyfiledata);
//
//	if (!g_HeadsAndBodies[bodynum].unk00_01) {
//		if (bodyfiledata->type == &g_ModelTypeChr) {
//			node = modelGetPart(bodyfiledata, MODELPART_CHR_04);
//
//			if (node != NULL) {
//				if (headnum < 0) {
//					headfiledata = func0f18e57c(-1 - headnum, &headnum);
//					bodyfiledata->rwdatalen += headfiledata->rwdatalen;
//				} else if (headnum > 0) {
//					if (headfiledata == NULL) {
//						if (g_Vars.normmplayerisrunning && !IS4MB()) {
//							headfiledata = fileLoad(g_HeadsAndBodies[headnum].filenum);
//							g_HeadsAndBodies[headnum].filedata = headfiledata;
//							g_FileInfo[g_HeadsAndBodies[headnum].filenum].size = 0;
//							func0f02ddbc(headfiledata, headnum, bodynum);
//						} else {
//							if (g_HeadsAndBodies[headnum].filedata == NULL) {
//								g_HeadsAndBodies[headnum].filedata = fileLoad(g_HeadsAndBodies[headnum].filenum);
//							}
//
//							headfiledata = g_HeadsAndBodies[headnum].filedata;
//						}
//					}
//
//					modelCalculateRwDataLen(headfiledata);
//
//					bodyfiledata->rwdatalen += headfiledata->rwdatalen;
//
//					if (g_HeadsAndBodies[bodynum].canvaryheight && varyheight) {
//						// Set height to between 95% and 115%
//						f32 frac = random() * (1.0f / U32_MAX) * 0.05f;
//						scale *= 2.0f * frac - 0.05f + 1.0f;
//					}
//				}
//
//				if (!isplayer) {
//					if (cheatIsActive(CHEAT_SMALLCHARACTERS)) {
//						scale *= 0.4f;
//					}
//
//					if (cheatIsActive(CHEAT_DKMODE)) {
//						scale *= 1.25f;
//					}
//				} else {
//					if (cheatIsActive(CHEAT_SMALLJO)) {
//						scale *= 0.4f;
//					}
//				}
//			}
//		} else if (bodyfiledata->type == &g_ModelTypeSkedar) {
//			if (g_HeadsAndBodies[bodynum].canvaryheight && varyheight && bodynum == BODY_SKEDAR) {
//				// Set height to between 65% and 85%
//				f32 frac = random() * (1.0f / U32_MAX);
//				scale *= 2.0f * (0.1f * frac) - 0.1f + 0.75f;
//			}
//		}
//	}
//
//	if (model) {
//		if (model->unk02 < bodyfiledata->rwdatalen) {
//			// empty
//		}
//	} else {
//		model = func0f0b3280(bodyfiledata);
//	}
//
//	if (model) {
//		modelSetScale(model, scale);
//		modelSetAnimScale(model, animscale);
//
//		if (headfiledata && !g_HeadsAndBodies[bodynum].unk00_01) {
//			bodyfiledata->rwdatalen -= headfiledata->rwdatalen;
//
//			func0f0b32a0(model, node, headfiledata);
//
//			if ((s16)*(s32 *)&headfiledata->type == MODELTYPE_HEAD) {
//				struct modelnode *node2;
//
//				if (!sunglasses) {
//					node2 = modelGetPart(headfiledata, MODELPART_HEAD_SUNGLASSES);
//
//					if (node2) {
//						union modelrwdata *rwdata = modelGetNodeRwData(model, node2);
//						rwdata->toggle.visible = false;
//					}
//				}
//
//				node2 = modelGetPart(headfiledata, MODELPART_HEAD_HUDPIECE);
//
//				if (node2) {
//					union modelrwdata *rwdata = modelGetNodeRwData(model, node2);
//					rwdata->toggle.visible = false;
//				}
//			}
//		}
//	}
//
//	return model;
//}

struct model *func0f02d338(s32 bodynum, s32 headnum, struct modelfiledata *bodyfiledata, struct modelfiledata *headfiledata, bool sunglasses, u8 varyheight)
{
	return func0f02ce8c(bodynum, headnum, bodyfiledata, headfiledata, sunglasses, NULL, false, varyheight);
}

struct model *modelAllocateChr(s32 bodynum, s32 headnum, u32 spawnflags)
{
	bool sunglasses = false;
	u8 varyheight = true;

	if (spawnflags & SPAWNFLAG_FORCESUNGLASSES) {
		sunglasses = true;
	} else if (spawnflags & SPAWNFLAG_MAYBESUNGLASSES) {
		sunglasses = random() % 2 == 0;
	}

	if (spawnflags & SPAWNFLAG_FIXEDHEIGHT) {
		varyheight = false;
	}

	return func0f02d338(bodynum, headnum, NULL, NULL, sunglasses, varyheight);
}

s32 func0f02d3f8(void)
{
	return g_BondBodies[var80062c80];
}

s32 bodyChooseHead(s32 bodynum)
{
	s32 head;

	if (g_HeadsAndBodies[bodynum].ismale) {
		head = g_ActiveMaleHeads[g_ActiveMaleHeadsIndex++];

		if (g_ActiveMaleHeadsIndex == g_NumActiveHeadsPerGender) {
			g_ActiveMaleHeadsIndex = 0;
		}
	} else if (bodynum == BODY_FEM_GUARD) {
		head = g_FemGuardHeads[random() % 3];
	} else {
		head = g_ActiveFemaleHeads[g_ActiveFemaleHeadsIndex++];

		if (g_ActiveFemaleHeadsIndex == g_NumActiveHeadsPerGender) {
			g_ActiveFemaleHeadsIndex = 0;
		}
	}

	return head;
}

/**
 * Read a "packed" chr definition and create a runtime chr from it.
 *
 * Chr definitions are stored in a packed format in each stage's setup file.
 * The packed format is used for space saving reasons.
 */
void chrUnpack(s32 stagenum, struct packedchr *packed, s32 cmdindex)
{
	struct pad pad;
	s16 rooms[2];
	struct chrdata *chr;
	struct modelfiledata *headfiledata;
	struct model *model;
	struct prop *prop;
	s32 bodynum;
	s32 headnum;
	f32 angle;
	s32 index;

	padUnpack(packed->padnum, PADFIELD_POS | PADFIELD_LOOK | PADFIELD_ROOM, &pad);

	rooms[0] = pad.room;
	rooms[1] = -1;

	if (cdTestVolume(&pad.pos, 20, rooms, CDTYPE_ALL, 1, 200, -200) == CDRESULT_COLLISION
			&& packed->chair == -1
			&& (packed->spawnflags & SPAWNFLAG_IGNORECOLLISION) == 0) {
		return;
	}

	if (packed->spawnflags & (SPAWNFLAG_ONLYONA | SPAWNFLAG_ONLYONSA | SPAWNFLAG_ONLYONPA)) {
		if ((packed->spawnflags & (SPAWNFLAG_ONLYONA | SPAWNFLAG_ONLYONSA | SPAWNFLAG_ONLYONPA)) == 0) {
			return;
		}

		if (((packed->spawnflags & SPAWNFLAG_ONLYONA) && lvGetDifficulty() == DIFF_A)
				|| ((packed->spawnflags & SPAWNFLAG_ONLYONSA) && lvGetDifficulty() == DIFF_SA)
				|| ((packed->spawnflags & SPAWNFLAG_ONLYONPA) && lvGetDifficulty() == DIFF_PA)) {
			// ok
		} else {
			return;
		}
	}

	headnum = -55555;
	headfiledata = NULL;

	if (packed->bodynum == 255) {
		bodynum = func0f02d3f8();
	} else {
		bodynum = packed->bodynum;
	}

	if (!g_HeadsAndBodies[bodynum].unk00_01) {
		if (packed->headnum >= 0) {
			headnum = packed->headnum;
		} else if (headnum == -55555) {
			headnum = bodyChooseHead(bodynum);
		}
	}

	if (headnum < 0) {
		index = -1 - headnum;

		if (index >= 0 && index < 22) {
			headfiledata = func0f18e57c(index, &headnum);
		}

		model = func0f02ce8c(bodynum, headnum, NULL, headfiledata, false, NULL, false, false);
	} else {
		model = modelAllocateChr(bodynum, headnum, packed->spawnflags);
	}

	if (model != NULL) {
		angle = atan2f(pad.look.x, pad.look.z);
		prop = propAllocateChr(model, &pad.pos, rooms, angle, ailistFindById(packed->ailistnum));

		if (prop != NULL) {
			propPrependToList1(prop);
			propShow(prop);

			chr = prop->chr;
			chrSetChrnum(chr, packed->chrnum);
			chr->hearingscale = packed->hearscale / 1000.0f;
			chr->visionrange = packed->viewdist;
			chr->padpreset1 = packed->padpreset;
			chr->chrpreset1 = packed->chrpreset;
			chr->headnum = headnum;
			chr->bodynum = bodynum;
			chr->race = bodyGetRace(chr->bodynum);

			chr->rtracked = false;

			if (bodynum == BODY_DRCAROLL) {
				chr->drcarollimage_left = 0;
				chr->drcarollimage_right = 0;
				chr->chrheight = 185;
				chr->chrwidth = 30;
			} else if (bodynum == BODY_CHICROB) {
				chr->unk348 = malloc(sizeof(struct fireslotthing), MEMPOOL_STAGE);
				chr->unk34c = malloc(sizeof(struct fireslotthing), MEMPOOL_STAGE);
				chr->unk348->beam = malloc(ALIGN16(sizeof(struct beam)), MEMPOOL_STAGE);
				chr->unk34c->beam = malloc(ALIGN16(sizeof(struct beam)), MEMPOOL_STAGE);
				chr->unk348->beam->age = -1;
				chr->unk34c->beam->age = -1;
				chr->chrheight = 200;
				chr->chrwidth = 42;
			}

			if (packed->spawnflags & SPAWNFLAG_INVINCIBLE) {
				chr->chrflags |= CHRCFLAG_INVINCIBLE;
			}

			if (packed->spawnflags & SPAWNFLAG_00000200) {
				chr->hidden |= CHRHFLAG_00400000;
			}

			if (packed->spawnflags & SPAWNFLAG_ANTINONINTERACTABLE) {
				chr->hidden |= CHRHFLAG_ANTINONINTERACTABLE;
			}

			if (packed->spawnflags & SPAWNFLAG_00000800) {
				chr->hidden |= CHRHFLAG_08000000;
			}

			if (packed->spawnflags & SPAWNFLAG_HIDDEN) {
				chr->chrflags |= CHRCFLAG_HIDDEN;
			}

			if (packed->spawnflags & SPAWNFLAG_RTRACKED) {
				chr->rtracked = true;
			}

			if (packed->spawnflags & SPAWNFLAG_NOBLOOD) {
				chr->noblood = true;
			}

			if (packed->spawnflags & SPAWNFLAG_BLUESIGHT) {
				chr->hidden2 |= CHRH2FLAG_BLUESIGHT;
			}

			chr->flags = packed->flags;
			chr->flags2 = packed->flags2;

			if (cheatIsActive(CHEAT_MARQUIS)) {
				chr->flags2 &= ~CHRFLAG1_00001000;
				chr->flags2 |= CHRFLAG1_00000001;
			}

			chr->team = packed->team;
			chr->squadron = packed->squadron;
			chr->aibot = NULL;

			if (packed->tude != 4) {
				chr->tude = packed->tude;
			} else {
				chr->tude = random() % 4;
			}

			chr->voicebox = random() % 3;

			if (!g_HeadsAndBodies[chr->bodynum].ismale) {
				chr->voicebox = VOICEBOX_FEMALE;
			}

			chr->naturalanim = packed->naturalanim;
			chr->myspecial = packed->chair;
			chr->yvisang = packed->yvisang;

			packed->chrindex = chr - g_ChrSlots;

			chr->teamscandist = packed->teamscandist;
			chr->convtalk = packed->convtalk;

			if (chr->flags & CHRFLAG0_CAN_HEARSPAWN) {
				chr->chrflags |= CHRCFLAG_CLONEABLE;
			}

			if (!g_Vars.normmplayerisrunning && g_MissionConfig.iscoop && g_Vars.numaibuddies > 0) {
				chr->flags |= CHRFLAG0_AIVSAI;
			}

			if (random() % 5 == 0) {
				chr->flags2 |= CHRFLAG1_00000080;
			}

			if (CHRRACE(chr) == RACE_SKEDAR) {
				chr->chrflags |= CHRCFLAG_FORCEAUTOAIM;
			}
		}
	}
}

struct prop *propAllocateEyespy(struct pad *pad, s16 room)
{
	s16 rooms[2];
	struct prop *prop;
	struct chrdata *chr;
	struct model *model;
	s32 inlift;
	struct prop *lift;
	f32 ground;
	u32 stack[2];

	rooms[0] = room;
	rooms[1] = -1;

#if PIRACYCHECKS
	{
		u32 checksum = 0;
		s32 *ptr = (s32 *)&lvInit;
		s32 *end = (s32 *)&lvConfigureFade;

		while (ptr < end) {
			checksum <<= 1;
			checksum ^= *ptr;
			ptr++;
		}

		if (checksum != CHECKSUM_PLACEHOLDER) {
			s32 *ptr2 = (s32 *)func00012914;
			s32 *end2 = (s32 *)func00012a0c;

			while (ptr2 < end2) {
				ptr2[0] = 0;
				ptr2++;
			}
		}
	}
#endif

	model = modelAllocateChr(BODY_EYESPY, 0, 0);

	if (model) {
		prop = propAllocateChr(model, &pad->pos, rooms, 0, ailistFindById(GAILIST_IDLE));

		if (prop) {
			propPrependToList1(prop);
			propShow(prop);
			chr = prop->chr;
			chrSetChrnum(chr, getNextUnusedChrnum());
			chr->bodynum = BODY_EYESPY;
			chr->padpreset1 = 0;
			chr->chrpreset1 = 0;
			chr->headnum = 0;
			chr->hearingscale = 0;
			chr->visionrange = 0;
			chr->race = bodyGetRace(chr->bodynum);

			ground = cdFindGroundY(&pad->pos, 30, rooms, NULL, NULL, NULL, NULL, &inlift, &lift);
			chr->ground = ground;
			chr->manground = ground;

			chr->flags = 0;
			chr->flags2 = 0;
			chr->team = 0;
			chr->squadron = 0;
			chr->maxdamage = 2;
			chr->tude = random() & 3;
			chr->voicebox = random() % 3;
			chr->naturalanim = 0;
			chr->myspecial = 0;
			chr->yvisang = 0;
			chr->teamscandist = 0;
			chr->convtalk = 0;
			chr->chrwidth = 26;
			chr->chrheight = 200;
			func0f02e9a0(chr, 0);
			chr->chrflags |= CHRCFLAG_HIDDEN;

#if VERSION >= VERSION_NTSC_1_0
			chr->hidden2 |= CHRH2FLAG_0040;
#else
			chr->hidden |= CHRHFLAG_00000200;
#endif

			return prop;
		}
	}

	return NULL;
}

void func0f02ddbf(void)
{
	// empty
}

GLOBAL_ASM(
glabel func0f02ddbc
.late_rodata
glabel var7f1a8a88
.word func0f02ddbc+0x94 # f02de50
glabel var7f1a8a8c
.word func0f02ddbc+0x84 # f02de40
glabel var7f1a8a90
.word func0f02ddbc+0xac # f02de68
glabel var7f1a8a94
.word func0f02ddbc+0x8c # f02de48
glabel var7f1a8a98
.word func0f02ddbc+0xa4 # f02de60
glabel var7f1a8a9c
.word func0f02ddbc+0x9c # f02de58
glabel var7f1a8aa0
.word func0f02ddbc+0xd8 # f02de94
glabel var7f1a8aa4
.word func0f02ddbc+0xec # f02dea8
glabel var7f1a8aa8
.word func0f02ddbc+0xe8 # f02dea4
glabel var7f1a8aac
.word func0f02ddbc+0xd0 # f02de8c
glabel var7f1a8ab0
.word func0f02ddbc+0xe0 # f02de9c
glabel var7f1a8ab4
.word func0f02ddbc+0xec # f02dea8
.text
/*  f02ddbc:	27bdffb8 */ 	addiu	$sp,$sp,-72
/*  f02ddc0:	afbf001c */ 	sw	$ra,0x1c($sp)
/*  f02ddc4:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f02ddc8:	848e0006 */ 	lh	$t6,0x6($a0)
/*  f02ddcc:	00a03825 */ 	or	$a3,$a1,$zero
/*  f02ddd0:	2401000d */ 	addiu	$at,$zero,0xd
/*  f02ddd4:	15c10081 */ 	bne	$t6,$at,.L0f02dfdc
/*  f02ddd8:	24050014 */ 	addiu	$a1,$zero,0x14
/*  f02dddc:	00e50019 */ 	multu	$a3,$a1
/*  f02dde0:	3c038008 */ 	lui	$v1,%hi(g_HeadsAndBodies)
/*  f02dde4:	2463cf04 */ 	addiu	$v1,$v1,%lo(g_HeadsAndBodies)
/*  f02dde8:	00007812 */ 	mflo	$t7
/*  f02ddec:	006fc021 */ 	addu	$t8,$v1,$t7
/*  f02ddf0:	8f020000 */ 	lw	$v0,0x0($t8)
/*  f02ddf4:	00c50019 */ 	multu	$a2,$a1
/*  f02ddf8:	0002c8c0 */ 	sll	$t9,$v0,0x3
/*  f02ddfc:	00194742 */ 	srl	$t0,$t9,0x1d
/*  f02de00:	01001025 */ 	or	$v0,$t0,$zero
/*  f02de04:	2d010006 */ 	sltiu	$at,$t0,0x6
/*  f02de08:	00004812 */ 	mflo	$t1
/*  f02de0c:	00695021 */ 	addu	$t2,$v1,$t1
/*  f02de10:	8d460000 */ 	lw	$a2,0x0($t2)
/*  f02de14:	000658c0 */ 	sll	$t3,$a2,0x3
/*  f02de18:	000b3742 */ 	srl	$a2,$t3,0x1d
/*  f02de1c:	51060070 */ 	beql	$t0,$a2,.L0f02dfe0
/*  f02de20:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f02de24:	10200006 */ 	beqz	$at,.L0f02de40
/*  f02de28:	00086880 */ 	sll	$t5,$t0,0x2
/*  f02de2c:	3c017f1b */ 	lui	$at,%hi(var7f1a8a88)
/*  f02de30:	002d0821 */ 	addu	$at,$at,$t5
/*  f02de34:	8c2d8a88 */ 	lw	$t5,%lo(var7f1a8a88)($at)
/*  f02de38:	01a00008 */ 	jr	$t5
/*  f02de3c:	00000000 */ 	nop
.L0f02de40:
/*  f02de40:	1000000a */ 	b	.L0f02de6c
/*  f02de44:	00003825 */ 	or	$a3,$zero,$zero
/*  f02de48:	10000008 */ 	b	.L0f02de6c
/*  f02de4c:	00003825 */ 	or	$a3,$zero,$zero
/*  f02de50:	10000006 */ 	b	.L0f02de6c
/*  f02de54:	2407ffdd */ 	addiu	$a3,$zero,-35
/*  f02de58:	10000004 */ 	b	.L0f02de6c
/*  f02de5c:	00003825 */ 	or	$a3,$zero,$zero
/*  f02de60:	10000002 */ 	b	.L0f02de6c
/*  f02de64:	2407ffec */ 	addiu	$a3,$zero,-20
/*  f02de68:	2407ffd8 */ 	addiu	$a3,$zero,-40
.L0f02de6c:
/*  f02de6c:	2cc10006 */ 	sltiu	$at,$a2,0x6
/*  f02de70:	1020000d */ 	beqz	$at,.L0f02dea8
/*  f02de74:	00067080 */ 	sll	$t6,$a2,0x2
/*  f02de78:	3c017f1b */ 	lui	$at,%hi(var7f1a8aa0)
/*  f02de7c:	002e0821 */ 	addu	$at,$at,$t6
/*  f02de80:	8c2e8aa0 */ 	lw	$t6,%lo(var7f1a8aa0)($at)
/*  f02de84:	01c00008 */ 	jr	$t6
/*  f02de88:	00000000 */ 	nop
/*  f02de8c:	10000006 */ 	b	.L0f02dea8
/*  f02de90:	24e7ffe2 */ 	addiu	$a3,$a3,-30
/*  f02de94:	10000004 */ 	b	.L0f02dea8
/*  f02de98:	24e70023 */ 	addiu	$a3,$a3,0x23
/*  f02de9c:	10000002 */ 	b	.L0f02dea8
/*  f02dea0:	24e70014 */ 	addiu	$a3,$a3,0x14
/*  f02dea4:	24e70028 */ 	addiu	$a3,$a3,0x28
.L0f02dea8:
/*  f02dea8:	24010001 */ 	addiu	$at,$zero,0x1
/*  f02deac:	54c1000f */ 	bnel	$a2,$at,.L0f02deec
/*  f02deb0:	24010004 */ 	addiu	$at,$zero,0x4
/*  f02deb4:	10400003 */ 	beqz	$v0,.L0f02dec4
/*  f02deb8:	24010005 */ 	addiu	$at,$zero,0x5
/*  f02debc:	54410004 */ 	bnel	$v0,$at,.L0f02ded0
/*  f02dec0:	24010004 */ 	addiu	$at,$zero,0x4
.L0f02dec4:
/*  f02dec4:	10000010 */ 	b	.L0f02df08
/*  f02dec8:	24e7fff6 */ 	addiu	$a3,$a3,-10
/*  f02decc:	24010004 */ 	addiu	$at,$zero,0x4
.L0f02ded0:
/*  f02ded0:	10410003 */ 	beq	$v0,$at,.L0f02dee0
/*  f02ded4:	24010002 */ 	addiu	$at,$zero,0x2
/*  f02ded8:	1441000b */ 	bne	$v0,$at,.L0f02df08
/*  f02dedc:	00000000 */ 	nop
.L0f02dee0:
/*  f02dee0:	10000009 */ 	b	.L0f02df08
/*  f02dee4:	24e7fffb */ 	addiu	$a3,$a3,-5
/*  f02dee8:	24010004 */ 	addiu	$at,$zero,0x4
.L0f02deec:
/*  f02deec:	14c10006 */ 	bne	$a2,$at,.L0f02df08
/*  f02def0:	00000000 */ 	nop
/*  f02def4:	10400003 */ 	beqz	$v0,.L0f02df04
/*  f02def8:	24010005 */ 	addiu	$at,$zero,0x5
/*  f02defc:	14410002 */ 	bne	$v0,$at,.L0f02df08
/*  f02df00:	00000000 */ 	nop
.L0f02df04:
/*  f02df04:	24e7fffb */ 	addiu	$a3,$a3,-5
.L0f02df08:
/*  f02df08:	50e00035 */ 	beqzl	$a3,.L0f02dfe0
/*  f02df0c:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f02df10:	afa00044 */ 	sw	$zero,0x44($sp)
/*  f02df14:	afa40048 */ 	sw	$a0,0x48($sp)
/*  f02df18:	8fa40048 */ 	lw	$a0,0x48($sp)
.L0f02df1c:
/*  f02df1c:	8fb00044 */ 	lw	$s0,0x44($sp)
/*  f02df20:	27a50044 */ 	addiu	$a1,$sp,0x44
/*  f02df24:	27a6003c */ 	addiu	$a2,$sp,0x3c
/*  f02df28:	0c008c67 */ 	jal	func0002319c
/*  f02df2c:	afa70038 */ 	sw	$a3,0x38($sp)
/*  f02df30:	8faf0044 */ 	lw	$t7,0x44($sp)
/*  f02df34:	8fa70038 */ 	lw	$a3,0x38($sp)
/*  f02df38:	51e00019 */ 	beqzl	$t7,.L0f02dfa0
/*  f02df3c:	8fac0044 */ 	lw	$t4,0x44($sp)
/*  f02df40:	51f00017 */ 	beql	$t7,$s0,.L0f02dfa0
/*  f02df44:	8fac0044 */ 	lw	$t4,0x44($sp)
/*  f02df48:	95f80000 */ 	lhu	$t8,0x0($t7)
/*  f02df4c:	24010018 */ 	addiu	$at,$zero,0x18
/*  f02df50:	57010013 */ 	bnel	$t8,$at,.L0f02dfa0
/*  f02df54:	8fac0044 */ 	lw	$t4,0x44($sp)
/*  f02df58:	8de50004 */ 	lw	$a1,0x4($t7)
/*  f02df5c:	00001825 */ 	or	$v1,$zero,$zero
/*  f02df60:	00002025 */ 	or	$a0,$zero,$zero
/*  f02df64:	84b90010 */ 	lh	$t9,0x10($a1)
/*  f02df68:	5b20000d */ 	blezl	$t9,.L0f02dfa0
/*  f02df6c:	8fac0044 */ 	lw	$t4,0x44($sp)
/*  f02df70:	8ca8000c */ 	lw	$t0,0xc($a1)
.L0f02df74:
/*  f02df74:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f02df78:	01041021 */ 	addu	$v0,$t0,$a0
/*  f02df7c:	84490002 */ 	lh	$t1,0x2($v0)
/*  f02df80:	2484000c */ 	addiu	$a0,$a0,0xc
/*  f02df84:	01275021 */ 	addu	$t2,$t1,$a3
/*  f02df88:	a44a0002 */ 	sh	$t2,0x2($v0)
/*  f02df8c:	84ab0010 */ 	lh	$t3,0x10($a1)
/*  f02df90:	006b082a */ 	slt	$at,$v1,$t3
/*  f02df94:	5420fff7 */ 	bnezl	$at,.L0f02df74
/*  f02df98:	8ca8000c */ 	lw	$t0,0xc($a1)
/*  f02df9c:	8fac0044 */ 	lw	$t4,0x44($sp)
.L0f02dfa0:
/*  f02dfa0:	5580ffde */ 	bnezl	$t4,.L0f02df1c
/*  f02dfa4:	8fa40048 */ 	lw	$a0,0x48($sp)
/*  f02dfa8:	8fa40048 */ 	lw	$a0,0x48($sp)
/*  f02dfac:	0fc1a25b */ 	jal	func0f06896c
/*  f02dfb0:	afa70038 */ 	sw	$a3,0x38($sp)
/*  f02dfb4:	10400009 */ 	beqz	$v0,.L0f02dfdc
/*  f02dfb8:	8fa70038 */ 	lw	$a3,0x38($sp)
/*  f02dfbc:	44872000 */ 	mtc1	$a3,$f4
/*  f02dfc0:	c446000c */ 	lwc1	$f6,0xc($v0)
/*  f02dfc4:	c44a0010 */ 	lwc1	$f10,0x10($v0)
/*  f02dfc8:	46802020 */ 	cvt.s.w	$f0,$f4
/*  f02dfcc:	46003200 */ 	add.s	$f8,$f6,$f0
/*  f02dfd0:	46005400 */ 	add.s	$f16,$f10,$f0
/*  f02dfd4:	e448000c */ 	swc1	$f8,0xc($v0)
/*  f02dfd8:	e4500010 */ 	swc1	$f16,0x10($v0)
.L0f02dfdc:
/*  f02dfdc:	8fbf001c */ 	lw	$ra,0x1c($sp)
.L0f02dfe0:
/*  f02dfe0:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f02dfe4:	27bd0048 */ 	addiu	$sp,$sp,0x48
/*  f02dfe8:	03e00008 */ 	jr	$ra
/*  f02dfec:	00000000 */ 	nop
);
