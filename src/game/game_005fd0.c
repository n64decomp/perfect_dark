#include <ultra64.h>
#include "constants.h"
#include "game/debug.h"
#include "game/game_006900.h"
#include "game/game_092610.h"
#include "game/bg.h"
#include "bss.h"
#include "lib/rng.h"
#include "lib/lib_159b0.h"
#include "lib/lib_16110.h"
#include "data.h"
#include "types.h"

s32 g_FootstepSounds[] = {
	/* none   */ -1,                -1,                -1,                -1,                -1,                -1,                -1,                -1,
	/* wood   */ SFX_FOOTSTEP_80DC, SFX_FOOTSTEP_80DD, SFX_FOOTSTEP_80E0, SFX_FOOTSTEP_80E1, SFX_FOOTSTEP_80DE, SFX_FOOTSTEP_80DF, SFX_FOOTSTEP_80E2, SFX_FOOTSTEP_80E3,
	/* stone  */ SFX_FOOTSTEP_80C4, SFX_FOOTSTEP_80C5, SFX_FOOTSTEP_80C8, SFX_FOOTSTEP_80C9, SFX_FOOTSTEP_80C6, SFX_FOOTSTEP_80C7, SFX_FOOTSTEP_80CA, SFX_FOOTSTEP_80CB,
	/* carpet */ SFX_FOOTSTEP_80E6, SFX_FOOTSTEP_80E7, SFX_FOOTSTEP_80EA, SFX_FOOTSTEP_80EB, SFX_FOOTSTEP_80E8, SFX_FOOTSTEP_80E9, SFX_FOOTSTEP_80EC, SFX_FOOTSTEP_80ED,
	/* metal  */ SFX_FOOTSTEP_80D4, SFX_FOOTSTEP_80D5, SFX_FOOTSTEP_80D8, SFX_FOOTSTEP_80D9, SFX_FOOTSTEP_80D6, SFX_FOOTSTEP_80D7, SFX_FOOTSTEP_80DA, SFX_FOOTSTEP_80DB,
	/* mud    */ SFX_FOOTSTEP_80EE, SFX_FOOTSTEP_80EF, SFX_FOOTSTEP_80F2, SFX_FOOTSTEP_80F3, SFX_FOOTSTEP_80F0, SFX_FOOTSTEP_80F1, SFX_FOOTSTEP_80F4, SFX_FOOTSTEP_80F5,
	/* water  */ SFX_FOOTSTEP_80E4, SFX_FOOTSTEP_80E5, SFX_FOOTSTEP_80E4, SFX_FOOTSTEP_80E5, SFX_FOOTSTEP_80E4, SFX_FOOTSTEP_80E5, SFX_FOOTSTEP_80E4, SFX_FOOTSTEP_80E5,
	/* dirt   */ SFX_FOOTSTEP_80CC, SFX_FOOTSTEP_80CD, SFX_FOOTSTEP_80D0, SFX_FOOTSTEP_80D1, SFX_FOOTSTEP_80CE, SFX_FOOTSTEP_80CF, SFX_FOOTSTEP_80D2, SFX_FOOTSTEP_80D3,
	/* snow   */ SFX_FOOTSTEP_8187, SFX_FOOTSTEP_8188, SFX_FOOTSTEP_818B, SFX_FOOTSTEP_818C, SFX_FOOTSTEP_8189, SFX_FOOTSTEP_818A, SFX_FOOTSTEP_818D, SFX_FOOTSTEP_818E,
};

struct footstepframe {
	u16 animnum;
	u8 frame1;
	u8 frame2;
};

struct footstepframe g_FootstepAnims[] = {
	{ ANIM_002B,               0x08, 0x19 },
	{ ANIM_0029,               0x05, 0x0e },
	{ ANIM_006B,               0x08, 0x19 },
	{ ANIM_0028,               0x1b, 0x08 },
	{ ANIM_RUNNING_TWOHANDGUN, 0x12, 0x06 },
	{ ANIM_0052,               0x08, 0x19 },
	{ ANIM_0053,               0x19, 0x08 },
	{ ANIM_0054,               0x19, 0x08 },
	{ ANIM_0055,               0x07, 0x12 },
	{ ANIM_0056,               0x07, 0x12 },
	{ ANIM_0057,               0x12, 0x07 },
	{ ANIM_0058,               0x0f, 0x05 },
	{ ANIM_RUNNING_ONEHANDGUN, 0x08, 0x14 },
	{ ANIM_005A,               0x06, 0x0f },
	{ ANIM_006C,               0x19, 0x08 },
	{ ANIM_006D,               0x19, 0x08 },
	{ ANIM_006E,               0x08, 0x13 },
	{ ANIM_006F,               0x15, 0x08 },
	{ ANIM_0070,               0x0f, 0x05 },
	{ ANIM_0071,               0x0f, 0x05 },
	{ ANIM_0072,               0x17, 0x08 },
	{ ANIM_0073,               0x08, 0x13 },
	{ ANIM_0093,               0x17, 0x0a },
	{ ANIM_0094,               0x0f, 0x05 },
	{ ANIM_005F,               0x0e, 0x01 },
	{ ANIM_0016,               0x1d, 0x0a },
	{ ANIM_0018,               0x18, 0x2e },
	{ ANIM_001B,               0x0a, 0x1c },
	{ ANIM_001D,               0x0d, 0x02 },
	{ ANIM_001E,               0x0c, 0x01 },
	{ ANIM_005C,               0x13, 0x2a },
	{ ANIM_005D,               0x0f, 0x05 },
	{ ANIM_005E,               0x04, 0x0c },
	{ ANIM_0392,               0x05, 0x14 },
	{ ANIM_SKEDAR_RUNNING,     0x00, 0x00 },
};

bool func0f005fd0(s32 animnum)
{
	switch (animnum) {
	case ANIM_001D:
	case ANIM_001E:
	case ANIM_0029:
	case ANIM_RUNNING_TWOHANDGUN:
	case ANIM_0055:
	case ANIM_0056:
	case ANIM_0057:
	case ANIM_0058:
	case ANIM_RUNNING_ONEHANDGUN:
	case ANIM_005A:
	case ANIM_005D:
	case ANIM_005E:
	case ANIM_005F:
	case ANIM_006E:
	case ANIM_006F:
	case ANIM_0070:
	case ANIM_0071:
	case ANIM_0073:
	case ANIM_0093:
	case ANIM_0094:
	case ANIM_SKEDAR_RUNNING:
		return true;
	}

	return false;
}

s32 chrChooseFootstepSound(struct chrdata *chr, s32 footstepindex)
{
	s32 floortype;
	s32 which;
	s32 rand;
	s32 index;

	if (chr->footstep == 0) {
		return 0;
	}

	floortype = chr->floortype <= FLOORTYPE_SNOW ? chr->floortype : 0;

	if (floortype == -1) {
		return 0;
	}

	if (CHRRACE(chr) == RACE_SKEDAR && chr->bodynum != BODY_MINISKEDAR) {
		u32 result;
		chr->lastfootsample ^= 1;

		if (floortype == FLOORTYPE_METAL) {
			if (chr->lastfootsample) {
				result = SFX_FOOTSTEP_8191;
			} else {
				result = SFX_FOOTSTEP_8192;
			}
		} else {
			if (chr->lastfootsample) {
				result = SFX_FOOTSTEP_818F;
			} else {
				result = SFX_FOOTSTEP_8190;
			}
		}

		return result;
	}

	which = func0f005fd0(g_FootstepAnims[footstepindex].animnum);

	do {
		rand = random() % 8;
		index = (which ? 2 : 0) + (rand & 5) + floortype * 8;
	} while (index == chr->lastfootsample);

	chr->lastfootsample = index;

	return g_FootstepSounds[index];
}

#if VERSION >= VERSION_PAL_FINAL
GLOBAL_ASM(
glabel chrCheckFootstep
/*  f0061dc:	27bdff88 */ 	addiu	$sp,$sp,-120
/*  f0061e0:	afbf004c */ 	sw	$ra,0x4c($sp)
/*  f0061e4:	afb10048 */ 	sw	$s1,0x48($sp)
/*  f0061e8:	00808825 */ 	move	$s1,$a0
/*  f0061ec:	0fc47e7e */ 	jal	debugEnableFootsteps
/*  f0061f0:	afb00044 */ 	sw	$s0,0x44($sp)
/*  f0061f4:	104000c2 */ 	beqz	$v0,.PF0f006500
/*  f0061f8:	24010001 */ 	li	$at,0x1
/*  f0061fc:	3c02800a */ 	lui	$v0,0x800a
/*  f006200:	2442a510 */ 	addiu	$v0,$v0,-23280
/*  f006204:	8c4e006c */ 	lw	$t6,0x6c($v0)
/*  f006208:	00002825 */ 	move	$a1,$zero
/*  f00620c:	00001825 */ 	move	$v1,$zero
/*  f006210:	11c00003 */ 	beqz	$t6,.PF0f006220
/*  f006214:	00002025 */ 	move	$a0,$zero
/*  f006218:	10000001 */ 	b	.PF0f006220
/*  f00621c:	24050001 */ 	li	$a1,0x1
.PF0f006220:
/*  f006220:	8c4f0068 */ 	lw	$t7,0x68($v0)
/*  f006224:	11e00003 */ 	beqz	$t7,.PF0f006234
/*  f006228:	00000000 */ 	nop
/*  f00622c:	10000001 */ 	b	.PF0f006234
/*  f006230:	24030001 */ 	li	$v1,0x1
.PF0f006234:
/*  f006234:	8c580064 */ 	lw	$t8,0x64($v0)
/*  f006238:	13000003 */ 	beqz	$t8,.PF0f006248
/*  f00623c:	00000000 */ 	nop
/*  f006240:	10000001 */ 	b	.PF0f006248
/*  f006244:	24040001 */ 	li	$a0,0x1
.PF0f006248:
/*  f006248:	8c590070 */ 	lw	$t9,0x70($v0)
/*  f00624c:	00001025 */ 	move	$v0,$zero
/*  f006250:	13200003 */ 	beqz	$t9,.PF0f006260
/*  f006254:	00000000 */ 	nop
/*  f006258:	10000001 */ 	b	.PF0f006260
/*  f00625c:	24020001 */ 	li	$v0,0x1
.PF0f006260:
/*  f006260:	00444021 */ 	addu	$t0,$v0,$a0
/*  f006264:	01034821 */ 	addu	$t1,$t0,$v1
/*  f006268:	01255021 */ 	addu	$t2,$t1,$a1
/*  f00626c:	554100a5 */ 	bnel	$t2,$at,.PF0f006504
/*  f006270:	8fbf004c */ 	lw	$ra,0x4c($sp)
/*  f006274:	122000a2 */ 	beqz	$s1,.PF0f006500
/*  f006278:	240bffff */ 	li	$t3,-1
/*  f00627c:	8e220020 */ 	lw	$v0,0x20($s1)
/*  f006280:	44802000 */ 	mtc1	$zero,$f4
/*  f006284:	a2200190 */ 	sb	$zero,0x190($s1)
/*  f006288:	a62b019c */ 	sh	$t3,0x19c($s1)
/*  f00628c:	1040009c */ 	beqz	$v0,.PF0f006500
/*  f006290:	e6240194 */ 	swc1	$f4,0x194($s1)
/*  f006294:	8c440020 */ 	lw	$a0,0x20($v0)
/*  f006298:	5080009a */ 	beqzl	$a0,.PF0f006504
/*  f00629c:	8fbf004c */ 	lw	$ra,0x4c($sp)
/*  f0062a0:	c626018c */ 	lwc1	$f6,0x18c($s1)
/*  f0062a4:	3c038006 */ 	lui	$v1,0x8006
/*  f0062a8:	24631270 */ 	addiu	$v1,$v1,0x1270
/*  f0062ac:	e7a60070 */ 	swc1	$f6,0x70($sp)
/*  f0062b0:	c480000c */ 	lwc1	$f0,0xc($a0)
/*  f0062b4:	00008025 */ 	move	$s0,$zero
/*  f0062b8:	e620018c */ 	swc1	$f0,0x18c($s1)
/*  f0062bc:	e7a0006c */ 	swc1	$f0,0x6c($sp)
.PF0f0062c0:
/*  f0062c0:	8e240020 */ 	lw	$a0,0x20($s1)
/*  f0062c4:	0c0073c3 */ 	jal	modelGetAnimNum
/*  f0062c8:	afa30050 */ 	sw	$v1,0x50($sp)
/*  f0062cc:	8fa30050 */ 	lw	$v1,0x50($sp)
/*  f0062d0:	24010023 */ 	li	$at,0x23
/*  f0062d4:	94640000 */ 	lhu	$a0,0x0($v1)
/*  f0062d8:	54440087 */ 	bnel	$v0,$a0,.PF0f0064f8
/*  f0062dc:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f0062e0:	12200003 */ 	beqz	$s1,.PF0f0062f0
/*  f0062e4:	24010001 */ 	li	$at,0x1
/*  f0062e8:	10000002 */ 	b	.PF0f0062f4
/*  f0062ec:	922202fe */ 	lbu	$v0,0x2fe($s1)
.PF0f0062f0:
/*  f0062f0:	00001025 */ 	move	$v0,$zero
.PF0f0062f4:
/*  f0062f4:	14410034 */ 	bne	$v0,$at,.PF0f0063c8
/*  f0062f8:	02002825 */ 	move	$a1,$s0
/*  f0062fc:	24010394 */ 	li	$at,0x394
/*  f006300:	14810031 */ 	bne	$a0,$at,.PF0f0063c8
/*  f006304:	c7a8006c */ 	lwc1	$f8,0x6c($sp)
/*  f006308:	3c014000 */ 	lui	$at,0x4000
/*  f00630c:	44810000 */ 	mtc1	$at,$f0
/*  f006310:	3c014188 */ 	lui	$at,0x4188
/*  f006314:	c7aa0070 */ 	lwc1	$f10,0x70($sp)
/*  f006318:	4608003e */ 	c.le.s	$f0,$f8
/*  f00631c:	c7b0006c */ 	lwc1	$f16,0x6c($sp)
/*  f006320:	45020006 */ 	bc1fl	.PF0f00633c
/*  f006324:	44810000 */ 	mtc1	$at,$f0
/*  f006328:	4600503c */ 	c.lt.s	$f10,$f0
/*  f00632c:	00000000 */ 	nop
/*  f006330:	4503000c */ 	bc1tl	.PF0f006364
/*  f006334:	240c0001 */ 	li	$t4,0x1
/*  f006338:	44810000 */ 	mtc1	$at,$f0
.PF0f00633c:
/*  f00633c:	3c014120 */ 	lui	$at,0x4120
/*  f006340:	c7b20070 */ 	lwc1	$f18,0x70($sp)
/*  f006344:	4610003e */ 	c.le.s	$f0,$f16
/*  f006348:	c7a4006c */ 	lwc1	$f4,0x6c($sp)
/*  f00634c:	45020008 */ 	bc1fl	.PF0f006370
/*  f006350:	44810000 */ 	mtc1	$at,$f0
/*  f006354:	4600903c */ 	c.lt.s	$f18,$f0
/*  f006358:	00000000 */ 	nop
/*  f00635c:	45000003 */ 	bc1f	.PF0f00636c
/*  f006360:	240c0001 */ 	li	$t4,0x1
.PF0f006364:
/*  f006364:	1000003e */ 	b	.PF0f006460
/*  f006368:	a22c0190 */ 	sb	$t4,0x190($s1)
.PF0f00636c:
/*  f00636c:	44810000 */ 	mtc1	$at,$f0
.PF0f006370:
/*  f006370:	3c0141c8 */ 	lui	$at,0x41c8
/*  f006374:	c7a60070 */ 	lwc1	$f6,0x70($sp)
/*  f006378:	4604003e */ 	c.le.s	$f0,$f4
/*  f00637c:	c7a8006c */ 	lwc1	$f8,0x6c($sp)
/*  f006380:	45020006 */ 	bc1fl	.PF0f00639c
/*  f006384:	44810000 */ 	mtc1	$at,$f0
/*  f006388:	4600303c */ 	c.lt.s	$f6,$f0
/*  f00638c:	00000000 */ 	nop
/*  f006390:	4503000b */ 	bc1tl	.PF0f0063c0
/*  f006394:	240d0002 */ 	li	$t5,0x2
/*  f006398:	44810000 */ 	mtc1	$at,$f0
.PF0f00639c:
/*  f00639c:	c7aa0070 */ 	lwc1	$f10,0x70($sp)
/*  f0063a0:	4608003e */ 	c.le.s	$f0,$f8
/*  f0063a4:	00000000 */ 	nop
/*  f0063a8:	4500002d */ 	bc1f	.PF0f006460
/*  f0063ac:	00000000 */ 	nop
/*  f0063b0:	4600503c */ 	c.lt.s	$f10,$f0
/*  f0063b4:	00000000 */ 	nop
/*  f0063b8:	45000029 */ 	bc1f	.PF0f006460
/*  f0063bc:	240d0002 */ 	li	$t5,0x2
.PF0f0063c0:
/*  f0063c0:	10000027 */ 	b	.PF0f006460
/*  f0063c4:	a22d0190 */ 	sb	$t5,0x190($s1)
.PF0f0063c8:
/*  f0063c8:	906e0002 */ 	lbu	$t6,0x2($v1)
/*  f0063cc:	c7a4006c */ 	lwc1	$f4,0x6c($sp)
/*  f0063d0:	3c014f80 */ 	lui	$at,0x4f80
/*  f0063d4:	448e8000 */ 	mtc1	$t6,$f16
/*  f0063d8:	c7a60070 */ 	lwc1	$f6,0x70($sp)
/*  f0063dc:	05c10004 */ 	bgez	$t6,.PF0f0063f0
/*  f0063e0:	46808020 */ 	cvt.s.w	$f0,$f16
/*  f0063e4:	44819000 */ 	mtc1	$at,$f18
/*  f0063e8:	00000000 */ 	nop
/*  f0063ec:	46120000 */ 	add.s	$f0,$f0,$f18
.PF0f0063f0:
/*  f0063f0:	4604003e */ 	c.le.s	$f0,$f4
/*  f0063f4:	c7b0006c */ 	lwc1	$f16,0x6c($sp)
/*  f0063f8:	45020008 */ 	bc1fl	.PF0f00641c
/*  f0063fc:	90780003 */ 	lbu	$t8,0x3($v1)
/*  f006400:	4600303c */ 	c.lt.s	$f6,$f0
/*  f006404:	240f0001 */ 	li	$t7,0x1
/*  f006408:	45020004 */ 	bc1fl	.PF0f00641c
/*  f00640c:	90780003 */ 	lbu	$t8,0x3($v1)
/*  f006410:	10000013 */ 	b	.PF0f006460
/*  f006414:	a22f0190 */ 	sb	$t7,0x190($s1)
/*  f006418:	90780003 */ 	lbu	$t8,0x3($v1)
.PF0f00641c:
/*  f00641c:	3c014f80 */ 	lui	$at,0x4f80
/*  f006420:	c7b20070 */ 	lwc1	$f18,0x70($sp)
/*  f006424:	44984000 */ 	mtc1	$t8,$f8
/*  f006428:	07010004 */ 	bgez	$t8,.PF0f00643c
/*  f00642c:	46804020 */ 	cvt.s.w	$f0,$f8
/*  f006430:	44815000 */ 	mtc1	$at,$f10
/*  f006434:	00000000 */ 	nop
/*  f006438:	460a0000 */ 	add.s	$f0,$f0,$f10
.PF0f00643c:
/*  f00643c:	4610003e */ 	c.le.s	$f0,$f16
/*  f006440:	00000000 */ 	nop
/*  f006444:	45000006 */ 	bc1f	.PF0f006460
/*  f006448:	00000000 */ 	nop
/*  f00644c:	4600903c */ 	c.lt.s	$f18,$f0
/*  f006450:	24190002 */ 	li	$t9,0x2
/*  f006454:	45000002 */ 	bc1f	.PF0f006460
/*  f006458:	00000000 */ 	nop
/*  f00645c:	a2390190 */ 	sb	$t9,0x190($s1)
.PF0f006460:
/*  f006460:	0fc0181d */ 	jal	chrChooseFootstepSound
/*  f006464:	02202025 */ 	move	$a0,$s1
/*  f006468:	2401ffff */ 	li	$at,-1
/*  f00646c:	5041001c */ 	beql	$v0,$at,.PF0f0064e0
/*  f006470:	8e2e0020 */ 	lw	$t6,0x20($s1)
/*  f006474:	82280190 */ 	lb	$t0,0x190($s1)
/*  f006478:	3c01bf80 */ 	lui	$at,0xbf80
/*  f00647c:	00002025 */ 	move	$a0,$zero
/*  f006480:	11000016 */ 	beqz	$t0,.PF0f0064dc
/*  f006484:	00023400 */ 	sll	$a2,$v0,0x10
/*  f006488:	8e25001c */ 	lw	$a1,0x1c($s1)
/*  f00648c:	44810000 */ 	mtc1	$at,$f0
/*  f006490:	00064c03 */ 	sra	$t1,$a2,0x10
/*  f006494:	240affff */ 	li	$t2,-1
/*  f006498:	240b0400 */ 	li	$t3,0x400
/*  f00649c:	240c0010 */ 	li	$t4,0x10
/*  f0064a0:	240dffff */ 	li	$t5,-1
/*  f0064a4:	afad002c */ 	sw	$t5,0x2c($sp)
/*  f0064a8:	afac001c */ 	sw	$t4,0x1c($sp)
/*  f0064ac:	afab0014 */ 	sw	$t3,0x14($sp)
/*  f0064b0:	afaa0010 */ 	sw	$t2,0x10($sp)
/*  f0064b4:	01203025 */ 	move	$a2,$t1
/*  f0064b8:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f0064bc:	afa00020 */ 	sw	$zero,0x20($sp)
/*  f0064c0:	afa00018 */ 	sw	$zero,0x18($sp)
/*  f0064c4:	2407ffff */ 	li	$a3,-1
/*  f0064c8:	e7a00024 */ 	swc1	$f0,0x24($sp)
/*  f0064cc:	e7a00030 */ 	swc1	$f0,0x30($sp)
/*  f0064d0:	e7a00034 */ 	swc1	$f0,0x34($sp)
/*  f0064d4:	0fc24e3a */ 	jal	func0f0939f8
/*  f0064d8:	e7a00038 */ 	swc1	$f0,0x38($sp)
.PF0f0064dc:
/*  f0064dc:	8e2e0020 */ 	lw	$t6,0x20($s1)
.PF0f0064e0:
/*  f0064e0:	a630019c */ 	sh	$s0,0x19c($s1)
/*  f0064e4:	8dcf0020 */ 	lw	$t7,0x20($t6)
/*  f0064e8:	c5e4001c */ 	lwc1	$f4,0x1c($t7)
/*  f0064ec:	10000004 */ 	b	.PF0f006500
/*  f0064f0:	e6240198 */ 	swc1	$f4,0x198($s1)
/*  f0064f4:	26100001 */ 	addiu	$s0,$s0,0x1
.PF0f0064f8:
/*  f0064f8:	1601ff71 */ 	bne	$s0,$at,.PF0f0062c0
/*  f0064fc:	24630004 */ 	addiu	$v1,$v1,0x4
.PF0f006500:
/*  f006500:	8fbf004c */ 	lw	$ra,0x4c($sp)
.PF0f006504:
/*  f006504:	8fb00044 */ 	lw	$s0,0x44($sp)
/*  f006508:	8fb10048 */ 	lw	$s1,0x48($sp)
/*  f00650c:	03e00008 */ 	jr	$ra
/*  f006510:	27bd0078 */ 	addiu	$sp,$sp,0x78
);
#elif VERSION >= VERSION_NTSC_1_0
GLOBAL_ASM(
glabel chrCheckFootstep
/*  f0061dc:	27bdff88 */ 	addiu	$sp,$sp,-120
/*  f0061e0:	afbf004c */ 	sw	$ra,0x4c($sp)
/*  f0061e4:	afb10048 */ 	sw	$s1,0x48($sp)
/*  f0061e8:	00808825 */ 	or	$s1,$a0,$zero
/*  f0061ec:	0fc47bbe */ 	jal	debugEnableFootsteps
/*  f0061f0:	afb00044 */ 	sw	$s0,0x44($sp)
/*  f0061f4:	104000c5 */ 	beqz	$v0,.L0f00650c
/*  f0061f8:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0061fc:	3c02800a */ 	lui	$v0,%hi(g_Vars)
/*  f006200:	24429fc0 */ 	addiu	$v0,$v0,%lo(g_Vars)
/*  f006204:	8c4e006c */ 	lw	$t6,0x6c($v0)
/*  f006208:	00002825 */ 	or	$a1,$zero,$zero
/*  f00620c:	00001825 */ 	or	$v1,$zero,$zero
/*  f006210:	11c00003 */ 	beqz	$t6,.L0f006220
/*  f006214:	00002025 */ 	or	$a0,$zero,$zero
/*  f006218:	10000001 */ 	b	.L0f006220
/*  f00621c:	24050001 */ 	addiu	$a1,$zero,0x1
.L0f006220:
/*  f006220:	8c4f0068 */ 	lw	$t7,0x68($v0)
/*  f006224:	11e00003 */ 	beqz	$t7,.L0f006234
/*  f006228:	00000000 */ 	nop
/*  f00622c:	10000001 */ 	b	.L0f006234
/*  f006230:	24030001 */ 	addiu	$v1,$zero,0x1
.L0f006234:
/*  f006234:	8c580064 */ 	lw	$t8,0x64($v0)
/*  f006238:	13000003 */ 	beqz	$t8,.L0f006248
/*  f00623c:	00000000 */ 	nop
/*  f006240:	10000001 */ 	b	.L0f006248
/*  f006244:	24040001 */ 	addiu	$a0,$zero,0x1
.L0f006248:
/*  f006248:	8c590070 */ 	lw	$t9,0x70($v0)
/*  f00624c:	00001025 */ 	or	$v0,$zero,$zero
/*  f006250:	13200003 */ 	beqz	$t9,.L0f006260
/*  f006254:	00000000 */ 	nop
/*  f006258:	10000001 */ 	b	.L0f006260
/*  f00625c:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f006260:
/*  f006260:	00444021 */ 	addu	$t0,$v0,$a0
/*  f006264:	01034821 */ 	addu	$t1,$t0,$v1
/*  f006268:	01255021 */ 	addu	$t2,$t1,$a1
/*  f00626c:	554100a8 */ 	bnel	$t2,$at,.L0f006510
/*  f006270:	8fbf004c */ 	lw	$ra,0x4c($sp)
/*  f006274:	122000a5 */ 	beqz	$s1,.L0f00650c
/*  f006278:	240bffff */ 	addiu	$t3,$zero,-1
/*  f00627c:	8e220020 */ 	lw	$v0,0x20($s1)
/*  f006280:	44802000 */ 	mtc1	$zero,$f4
/*  f006284:	a2200190 */ 	sb	$zero,0x190($s1)
/*  f006288:	a62b019c */ 	sh	$t3,0x19c($s1)
/*  f00628c:	1040009f */ 	beqz	$v0,.L0f00650c
/*  f006290:	e6240194 */ 	swc1	$f4,0x194($s1)
/*  f006294:	8c440020 */ 	lw	$a0,0x20($v0)
/*  f006298:	5080009d */ 	beqzl	$a0,.L0f006510
/*  f00629c:	8fbf004c */ 	lw	$ra,0x4c($sp)
/*  f0062a0:	c626018c */ 	lwc1	$f6,0x18c($s1)
/*  f0062a4:	3c038006 */ 	lui	$v1,%hi(g_FootstepAnims)
/*  f0062a8:	246315a0 */ 	addiu	$v1,$v1,%lo(g_FootstepAnims)
/*  f0062ac:	e7a60070 */ 	swc1	$f6,0x70($sp)
/*  f0062b0:	c480000c */ 	lwc1	$f0,0xc($a0)
/*  f0062b4:	00008025 */ 	or	$s0,$zero,$zero
/*  f0062b8:	e620018c */ 	swc1	$f0,0x18c($s1)
/*  f0062bc:	e7a0006c */ 	swc1	$f0,0x6c($sp)
.L0f0062c0:
/*  f0062c0:	8e240020 */ 	lw	$a0,0x20($s1)
/*  f0062c4:	0c00744f */ 	jal	modelGetAnimNum
/*  f0062c8:	afa30050 */ 	sw	$v1,0x50($sp)
/*  f0062cc:	8fa30050 */ 	lw	$v1,0x50($sp)
/*  f0062d0:	24010023 */ 	addiu	$at,$zero,0x23
/*  f0062d4:	94640000 */ 	lhu	$a0,0x0($v1)
/*  f0062d8:	5444008a */ 	bnel	$v0,$a0,.L0f006504
/*  f0062dc:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f0062e0:	12200003 */ 	beqz	$s1,.L0f0062f0
/*  f0062e4:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0062e8:	10000002 */ 	b	.L0f0062f4
/*  f0062ec:	922202fe */ 	lbu	$v0,0x2fe($s1)
.L0f0062f0:
/*  f0062f0:	00001025 */ 	or	$v0,$zero,$zero
.L0f0062f4:
/*  f0062f4:	14410034 */ 	bne	$v0,$at,.L0f0063c8
/*  f0062f8:	02002825 */ 	or	$a1,$s0,$zero
/*  f0062fc:	24010394 */ 	addiu	$at,$zero,0x394
/*  f006300:	14810031 */ 	bne	$a0,$at,.L0f0063c8
/*  f006304:	c7a8006c */ 	lwc1	$f8,0x6c($sp)
/*  f006308:	3c014000 */ 	lui	$at,0x4000
/*  f00630c:	44810000 */ 	mtc1	$at,$f0
/*  f006310:	3c014188 */ 	lui	$at,0x4188
/*  f006314:	c7aa0070 */ 	lwc1	$f10,0x70($sp)
/*  f006318:	4608003e */ 	c.le.s	$f0,$f8
/*  f00631c:	c7b0006c */ 	lwc1	$f16,0x6c($sp)
/*  f006320:	45020006 */ 	bc1fl	.L0f00633c
/*  f006324:	44810000 */ 	mtc1	$at,$f0
/*  f006328:	4600503c */ 	c.lt.s	$f10,$f0
/*  f00632c:	00000000 */ 	nop
/*  f006330:	4503000c */ 	bc1tl	.L0f006364
/*  f006334:	240c0001 */ 	addiu	$t4,$zero,0x1
/*  f006338:	44810000 */ 	mtc1	$at,$f0
.L0f00633c:
/*  f00633c:	3c014120 */ 	lui	$at,0x4120
/*  f006340:	c7b20070 */ 	lwc1	$f18,0x70($sp)
/*  f006344:	4610003e */ 	c.le.s	$f0,$f16
/*  f006348:	c7a4006c */ 	lwc1	$f4,0x6c($sp)
/*  f00634c:	45020008 */ 	bc1fl	.L0f006370
/*  f006350:	44810000 */ 	mtc1	$at,$f0
/*  f006354:	4600903c */ 	c.lt.s	$f18,$f0
/*  f006358:	00000000 */ 	nop
/*  f00635c:	45000003 */ 	bc1f	.L0f00636c
/*  f006360:	240c0001 */ 	addiu	$t4,$zero,0x1
.L0f006364:
/*  f006364:	1000003e */ 	b	.L0f006460
/*  f006368:	a22c0190 */ 	sb	$t4,0x190($s1)
.L0f00636c:
/*  f00636c:	44810000 */ 	mtc1	$at,$f0
.L0f006370:
/*  f006370:	3c0141c8 */ 	lui	$at,0x41c8
/*  f006374:	c7a60070 */ 	lwc1	$f6,0x70($sp)
/*  f006378:	4604003e */ 	c.le.s	$f0,$f4
/*  f00637c:	c7a8006c */ 	lwc1	$f8,0x6c($sp)
/*  f006380:	45020006 */ 	bc1fl	.L0f00639c
/*  f006384:	44810000 */ 	mtc1	$at,$f0
/*  f006388:	4600303c */ 	c.lt.s	$f6,$f0
/*  f00638c:	00000000 */ 	nop
/*  f006390:	4503000b */ 	bc1tl	.L0f0063c0
/*  f006394:	240d0002 */ 	addiu	$t5,$zero,0x2
/*  f006398:	44810000 */ 	mtc1	$at,$f0
.L0f00639c:
/*  f00639c:	c7aa0070 */ 	lwc1	$f10,0x70($sp)
/*  f0063a0:	4608003e */ 	c.le.s	$f0,$f8
/*  f0063a4:	00000000 */ 	nop
/*  f0063a8:	4500002d */ 	bc1f	.L0f006460
/*  f0063ac:	00000000 */ 	nop
/*  f0063b0:	4600503c */ 	c.lt.s	$f10,$f0
/*  f0063b4:	00000000 */ 	nop
/*  f0063b8:	45000029 */ 	bc1f	.L0f006460
/*  f0063bc:	240d0002 */ 	addiu	$t5,$zero,0x2
.L0f0063c0:
/*  f0063c0:	10000027 */ 	b	.L0f006460
/*  f0063c4:	a22d0190 */ 	sb	$t5,0x190($s1)
.L0f0063c8:
/*  f0063c8:	906e0002 */ 	lbu	$t6,0x2($v1)
/*  f0063cc:	c7a4006c */ 	lwc1	$f4,0x6c($sp)
/*  f0063d0:	3c014f80 */ 	lui	$at,0x4f80
/*  f0063d4:	448e8000 */ 	mtc1	$t6,$f16
/*  f0063d8:	c7a60070 */ 	lwc1	$f6,0x70($sp)
/*  f0063dc:	05c10004 */ 	bgez	$t6,.L0f0063f0
/*  f0063e0:	46808020 */ 	cvt.s.w	$f0,$f16
/*  f0063e4:	44819000 */ 	mtc1	$at,$f18
/*  f0063e8:	00000000 */ 	nop
/*  f0063ec:	46120000 */ 	add.s	$f0,$f0,$f18
.L0f0063f0:
/*  f0063f0:	4604003e */ 	c.le.s	$f0,$f4
/*  f0063f4:	c7b0006c */ 	lwc1	$f16,0x6c($sp)
/*  f0063f8:	45020008 */ 	bc1fl	.L0f00641c
/*  f0063fc:	90780003 */ 	lbu	$t8,0x3($v1)
/*  f006400:	4600303c */ 	c.lt.s	$f6,$f0
/*  f006404:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f006408:	45020004 */ 	bc1fl	.L0f00641c
/*  f00640c:	90780003 */ 	lbu	$t8,0x3($v1)
/*  f006410:	10000013 */ 	b	.L0f006460
/*  f006414:	a22f0190 */ 	sb	$t7,0x190($s1)
/*  f006418:	90780003 */ 	lbu	$t8,0x3($v1)
.L0f00641c:
/*  f00641c:	3c014f80 */ 	lui	$at,0x4f80
/*  f006420:	c7b20070 */ 	lwc1	$f18,0x70($sp)
/*  f006424:	44984000 */ 	mtc1	$t8,$f8
/*  f006428:	07010004 */ 	bgez	$t8,.L0f00643c
/*  f00642c:	46804020 */ 	cvt.s.w	$f0,$f8
/*  f006430:	44815000 */ 	mtc1	$at,$f10
/*  f006434:	00000000 */ 	nop
/*  f006438:	460a0000 */ 	add.s	$f0,$f0,$f10
.L0f00643c:
/*  f00643c:	4610003e */ 	c.le.s	$f0,$f16
/*  f006440:	00000000 */ 	nop
/*  f006444:	45000006 */ 	bc1f	.L0f006460
/*  f006448:	00000000 */ 	nop
/*  f00644c:	4600903c */ 	c.lt.s	$f18,$f0
/*  f006450:	24190002 */ 	addiu	$t9,$zero,0x2
/*  f006454:	45000002 */ 	bc1f	.L0f006460
/*  f006458:	00000000 */ 	nop
/*  f00645c:	a2390190 */ 	sb	$t9,0x190($s1)
.L0f006460:
/*  f006460:	0fc0181d */ 	jal	chrChooseFootstepSound
/*  f006464:	02202025 */ 	or	$a0,$s1,$zero
/*  f006468:	2401ffff */ 	addiu	$at,$zero,-1
/*  f00646c:	5041001c */ 	beql	$v0,$at,.L0f0064e0
/*  f006470:	8e2e0020 */ 	lw	$t6,0x20($s1)
/*  f006474:	82280190 */ 	lb	$t0,0x190($s1)
/*  f006478:	3c01bf80 */ 	lui	$at,0xbf80
/*  f00647c:	00002025 */ 	or	$a0,$zero,$zero
/*  f006480:	11000016 */ 	beqz	$t0,.L0f0064dc
/*  f006484:	00023400 */ 	sll	$a2,$v0,0x10
/*  f006488:	8e25001c */ 	lw	$a1,0x1c($s1)
/*  f00648c:	44810000 */ 	mtc1	$at,$f0
/*  f006490:	00064c03 */ 	sra	$t1,$a2,0x10
/*  f006494:	240affff */ 	addiu	$t2,$zero,-1
/*  f006498:	240b0400 */ 	addiu	$t3,$zero,0x400
/*  f00649c:	240c0010 */ 	addiu	$t4,$zero,0x10
/*  f0064a0:	240dffff */ 	addiu	$t5,$zero,-1
/*  f0064a4:	afad002c */ 	sw	$t5,0x2c($sp)
/*  f0064a8:	afac001c */ 	sw	$t4,0x1c($sp)
/*  f0064ac:	afab0014 */ 	sw	$t3,0x14($sp)
/*  f0064b0:	afaa0010 */ 	sw	$t2,0x10($sp)
/*  f0064b4:	01203025 */ 	or	$a2,$t1,$zero
/*  f0064b8:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f0064bc:	afa00020 */ 	sw	$zero,0x20($sp)
/*  f0064c0:	afa00018 */ 	sw	$zero,0x18($sp)
/*  f0064c4:	2407ffff */ 	addiu	$a3,$zero,-1
/*  f0064c8:	e7a00024 */ 	swc1	$f0,0x24($sp)
/*  f0064cc:	e7a00030 */ 	swc1	$f0,0x30($sp)
/*  f0064d0:	e7a00034 */ 	swc1	$f0,0x34($sp)
/*  f0064d4:	0fc24e7e */ 	jal	func0f0939f8
/*  f0064d8:	e7a00038 */ 	swc1	$f0,0x38($sp)
.L0f0064dc:
/*  f0064dc:	8e2e0020 */ 	lw	$t6,0x20($s1)
.L0f0064e0:
/*  f0064e0:	a630019c */ 	sh	$s0,0x19c($s1)
/*  f0064e4:	3c013e80 */ 	lui	$at,0x3e80
/*  f0064e8:	8dcf0020 */ 	lw	$t7,0x20($t6)
/*  f0064ec:	44813000 */ 	mtc1	$at,$f6
/*  f0064f0:	c5e4001c */ 	lwc1	$f4,0x1c($t7)
/*  f0064f4:	46062202 */ 	mul.s	$f8,$f4,$f6
/*  f0064f8:	10000004 */ 	b	.L0f00650c
/*  f0064fc:	e6280198 */ 	swc1	$f8,0x198($s1)
/*  f006500:	26100001 */ 	addiu	$s0,$s0,0x1
.L0f006504:
/*  f006504:	1601ff6e */ 	bne	$s0,$at,.L0f0062c0
/*  f006508:	24630004 */ 	addiu	$v1,$v1,0x4
.L0f00650c:
/*  f00650c:	8fbf004c */ 	lw	$ra,0x4c($sp)
.L0f006510:
/*  f006510:	8fb00044 */ 	lw	$s0,0x44($sp)
/*  f006514:	8fb10048 */ 	lw	$s1,0x48($sp)
/*  f006518:	03e00008 */ 	jr	$ra
/*  f00651c:	27bd0078 */ 	addiu	$sp,$sp,0x78
);
#else
GLOBAL_ASM(
glabel chrCheckFootstep
/*  f005f2c:	27bdff88 */ 	addiu	$sp,$sp,-120
/*  f005f30:	afbf004c */ 	sw	$ra,0x4c($sp)
/*  f005f34:	afb10048 */ 	sw	$s1,0x48($sp)
/*  f005f38:	00808825 */ 	or	$s1,$a0,$zero
/*  f005f3c:	0fc466d2 */ 	jal	debugEnableFootsteps
/*  f005f40:	afb00044 */ 	sw	$s0,0x44($sp)
/*  f005f44:	104000c3 */ 	beqz	$v0,.NB0f006254
/*  f005f48:	24010001 */ 	addiu	$at,$zero,0x1
/*  f005f4c:	3c02800a */ 	lui	$v0,0x800a
/*  f005f50:	2442e6c0 */ 	addiu	$v0,$v0,-6464
/*  f005f54:	8c4e006c */ 	lw	$t6,0x6c($v0)
/*  f005f58:	00002825 */ 	or	$a1,$zero,$zero
/*  f005f5c:	00001825 */ 	or	$v1,$zero,$zero
/*  f005f60:	11c00003 */ 	beqz	$t6,.NB0f005f70
/*  f005f64:	00002025 */ 	or	$a0,$zero,$zero
/*  f005f68:	10000001 */ 	beqz	$zero,.NB0f005f70
/*  f005f6c:	24050001 */ 	addiu	$a1,$zero,0x1
.NB0f005f70:
/*  f005f70:	8c4f0068 */ 	lw	$t7,0x68($v0)
/*  f005f74:	11e00003 */ 	beqz	$t7,.NB0f005f84
/*  f005f78:	00000000 */ 	sll	$zero,$zero,0x0
/*  f005f7c:	10000001 */ 	beqz	$zero,.NB0f005f84
/*  f005f80:	24030001 */ 	addiu	$v1,$zero,0x1
.NB0f005f84:
/*  f005f84:	8c580064 */ 	lw	$t8,0x64($v0)
/*  f005f88:	13000003 */ 	beqz	$t8,.NB0f005f98
/*  f005f8c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f005f90:	10000001 */ 	beqz	$zero,.NB0f005f98
/*  f005f94:	24040001 */ 	addiu	$a0,$zero,0x1
.NB0f005f98:
/*  f005f98:	8c590070 */ 	lw	$t9,0x70($v0)
/*  f005f9c:	00001025 */ 	or	$v0,$zero,$zero
/*  f005fa0:	13200003 */ 	beqz	$t9,.NB0f005fb0
/*  f005fa4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f005fa8:	10000001 */ 	beqz	$zero,.NB0f005fb0
/*  f005fac:	24020001 */ 	addiu	$v0,$zero,0x1
.NB0f005fb0:
/*  f005fb0:	00444021 */ 	addu	$t0,$v0,$a0
/*  f005fb4:	01034821 */ 	addu	$t1,$t0,$v1
/*  f005fb8:	01255021 */ 	addu	$t2,$t1,$a1
/*  f005fbc:	554100a6 */ 	bnel	$t2,$at,.NB0f006258
/*  f005fc0:	8fbf004c */ 	lw	$ra,0x4c($sp)
/*  f005fc4:	122000a3 */ 	beqz	$s1,.NB0f006254
/*  f005fc8:	240bffff */ 	addiu	$t3,$zero,-1
/*  f005fcc:	8e220020 */ 	lw	$v0,0x20($s1)
/*  f005fd0:	44802000 */ 	mtc1	$zero,$f4
/*  f005fd4:	a2200190 */ 	sb	$zero,0x190($s1)
/*  f005fd8:	ae2b019c */ 	sw	$t3,0x19c($s1)
/*  f005fdc:	1040009d */ 	beqz	$v0,.NB0f006254
/*  f005fe0:	e6240194 */ 	swc1	$f4,0x194($s1)
/*  f005fe4:	8c440020 */ 	lw	$a0,0x20($v0)
/*  f005fe8:	5080009b */ 	beqzl	$a0,.NB0f006258
/*  f005fec:	8fbf004c */ 	lw	$ra,0x4c($sp)
/*  f005ff0:	c626018c */ 	lwc1	$f6,0x18c($s1)
/*  f005ff4:	3c038006 */ 	lui	$v1,0x8006
/*  f005ff8:	24633ab0 */ 	addiu	$v1,$v1,0x3ab0
/*  f005ffc:	e7a60070 */ 	swc1	$f6,0x70($sp)
/*  f006000:	c480000c */ 	lwc1	$f0,0xc($a0)
/*  f006004:	00008025 */ 	or	$s0,$zero,$zero
/*  f006008:	e620018c */ 	swc1	$f0,0x18c($s1)
/*  f00600c:	e7a0006c */ 	swc1	$f0,0x6c($sp)
.NB0f006010:
/*  f006010:	8e240020 */ 	lw	$a0,0x20($s1)
/*  f006014:	0c00786f */ 	jal	modelGetAnimNum
/*  f006018:	afa30050 */ 	sw	$v1,0x50($sp)
/*  f00601c:	8fa30050 */ 	lw	$v1,0x50($sp)
/*  f006020:	24010023 */ 	addiu	$at,$zero,0x23
/*  f006024:	94640000 */ 	lhu	$a0,0x0($v1)
/*  f006028:	54440088 */ 	bnel	$v0,$a0,.NB0f00624c
/*  f00602c:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f006030:	12200003 */ 	beqz	$s1,.NB0f006040
/*  f006034:	24010001 */ 	addiu	$at,$zero,0x1
/*  f006038:	10000002 */ 	beqz	$zero,.NB0f006044
/*  f00603c:	922202fe */ 	lbu	$v0,0x2fe($s1)
.NB0f006040:
/*  f006040:	00001025 */ 	or	$v0,$zero,$zero
.NB0f006044:
/*  f006044:	14410034 */ 	bne	$v0,$at,.NB0f006118
/*  f006048:	02002825 */ 	or	$a1,$s0,$zero
/*  f00604c:	24010394 */ 	addiu	$at,$zero,0x394
/*  f006050:	14810031 */ 	bne	$a0,$at,.NB0f006118
/*  f006054:	c7a8006c */ 	lwc1	$f8,0x6c($sp)
/*  f006058:	3c014000 */ 	lui	$at,0x4000
/*  f00605c:	44810000 */ 	mtc1	$at,$f0
/*  f006060:	3c014188 */ 	lui	$at,0x4188
/*  f006064:	c7aa0070 */ 	lwc1	$f10,0x70($sp)
/*  f006068:	4608003e */ 	c.le.s	$f0,$f8
/*  f00606c:	c7b0006c */ 	lwc1	$f16,0x6c($sp)
/*  f006070:	45020006 */ 	bc1fl	.NB0f00608c
/*  f006074:	44810000 */ 	mtc1	$at,$f0
/*  f006078:	4600503c */ 	c.lt.s	$f10,$f0
/*  f00607c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f006080:	4503000c */ 	bc1tl	.NB0f0060b4
/*  f006084:	240c0001 */ 	addiu	$t4,$zero,0x1
/*  f006088:	44810000 */ 	mtc1	$at,$f0
.NB0f00608c:
/*  f00608c:	3c014120 */ 	lui	$at,0x4120
/*  f006090:	c7b20070 */ 	lwc1	$f18,0x70($sp)
/*  f006094:	4610003e */ 	c.le.s	$f0,$f16
/*  f006098:	c7a4006c */ 	lwc1	$f4,0x6c($sp)
/*  f00609c:	45020008 */ 	bc1fl	.NB0f0060c0
/*  f0060a0:	44810000 */ 	mtc1	$at,$f0
/*  f0060a4:	4600903c */ 	c.lt.s	$f18,$f0
/*  f0060a8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0060ac:	45000003 */ 	bc1f	.NB0f0060bc
/*  f0060b0:	240c0001 */ 	addiu	$t4,$zero,0x1
.NB0f0060b4:
/*  f0060b4:	1000003e */ 	beqz	$zero,.NB0f0061b0
/*  f0060b8:	a22c0190 */ 	sb	$t4,0x190($s1)
.NB0f0060bc:
/*  f0060bc:	44810000 */ 	mtc1	$at,$f0
.NB0f0060c0:
/*  f0060c0:	3c0141c8 */ 	lui	$at,0x41c8
/*  f0060c4:	c7a60070 */ 	lwc1	$f6,0x70($sp)
/*  f0060c8:	4604003e */ 	c.le.s	$f0,$f4
/*  f0060cc:	c7a8006c */ 	lwc1	$f8,0x6c($sp)
/*  f0060d0:	45020006 */ 	bc1fl	.NB0f0060ec
/*  f0060d4:	44810000 */ 	mtc1	$at,$f0
/*  f0060d8:	4600303c */ 	c.lt.s	$f6,$f0
/*  f0060dc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0060e0:	4503000b */ 	bc1tl	.NB0f006110
/*  f0060e4:	240d0002 */ 	addiu	$t5,$zero,0x2
/*  f0060e8:	44810000 */ 	mtc1	$at,$f0
.NB0f0060ec:
/*  f0060ec:	c7aa0070 */ 	lwc1	$f10,0x70($sp)
/*  f0060f0:	4608003e */ 	c.le.s	$f0,$f8
/*  f0060f4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0060f8:	4500002d */ 	bc1f	.NB0f0061b0
/*  f0060fc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f006100:	4600503c */ 	c.lt.s	$f10,$f0
/*  f006104:	00000000 */ 	sll	$zero,$zero,0x0
/*  f006108:	45000029 */ 	bc1f	.NB0f0061b0
/*  f00610c:	240d0002 */ 	addiu	$t5,$zero,0x2
.NB0f006110:
/*  f006110:	10000027 */ 	beqz	$zero,.NB0f0061b0
/*  f006114:	a22d0190 */ 	sb	$t5,0x190($s1)
.NB0f006118:
/*  f006118:	906e0002 */ 	lbu	$t6,0x2($v1)
/*  f00611c:	c7a4006c */ 	lwc1	$f4,0x6c($sp)
/*  f006120:	3c014f80 */ 	lui	$at,0x4f80
/*  f006124:	448e8000 */ 	mtc1	$t6,$f16
/*  f006128:	c7a60070 */ 	lwc1	$f6,0x70($sp)
/*  f00612c:	05c10004 */ 	bgez	$t6,.NB0f006140
/*  f006130:	46808020 */ 	cvt.s.w	$f0,$f16
/*  f006134:	44819000 */ 	mtc1	$at,$f18
/*  f006138:	00000000 */ 	sll	$zero,$zero,0x0
/*  f00613c:	46120000 */ 	add.s	$f0,$f0,$f18
.NB0f006140:
/*  f006140:	4604003e */ 	c.le.s	$f0,$f4
/*  f006144:	c7b0006c */ 	lwc1	$f16,0x6c($sp)
/*  f006148:	45020008 */ 	bc1fl	.NB0f00616c
/*  f00614c:	90780003 */ 	lbu	$t8,0x3($v1)
/*  f006150:	4600303c */ 	c.lt.s	$f6,$f0
/*  f006154:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f006158:	45020004 */ 	bc1fl	.NB0f00616c
/*  f00615c:	90780003 */ 	lbu	$t8,0x3($v1)
/*  f006160:	10000013 */ 	beqz	$zero,.NB0f0061b0
/*  f006164:	a22f0190 */ 	sb	$t7,0x190($s1)
/*  f006168:	90780003 */ 	lbu	$t8,0x3($v1)
.NB0f00616c:
/*  f00616c:	3c014f80 */ 	lui	$at,0x4f80
/*  f006170:	c7b20070 */ 	lwc1	$f18,0x70($sp)
/*  f006174:	44984000 */ 	mtc1	$t8,$f8
/*  f006178:	07010004 */ 	bgez	$t8,.NB0f00618c
/*  f00617c:	46804020 */ 	cvt.s.w	$f0,$f8
/*  f006180:	44815000 */ 	mtc1	$at,$f10
/*  f006184:	00000000 */ 	sll	$zero,$zero,0x0
/*  f006188:	460a0000 */ 	add.s	$f0,$f0,$f10
.NB0f00618c:
/*  f00618c:	4610003e */ 	c.le.s	$f0,$f16
/*  f006190:	00000000 */ 	sll	$zero,$zero,0x0
/*  f006194:	45000006 */ 	bc1f	.NB0f0061b0
/*  f006198:	00000000 */ 	sll	$zero,$zero,0x0
/*  f00619c:	4600903c */ 	c.lt.s	$f18,$f0
/*  f0061a0:	24190002 */ 	addiu	$t9,$zero,0x2
/*  f0061a4:	45000002 */ 	bc1f	.NB0f0061b0
/*  f0061a8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0061ac:	a2390190 */ 	sb	$t9,0x190($s1)
.NB0f0061b0:
/*  f0061b0:	0fc01771 */ 	jal	chrChooseFootstepSound
/*  f0061b4:	02202025 */ 	or	$a0,$s1,$zero
/*  f0061b8:	2401ffff */ 	addiu	$at,$zero,-1
/*  f0061bc:	5041001a */ 	beql	$v0,$at,.NB0f006228
/*  f0061c0:	8e2c0020 */ 	lw	$t4,0x20($s1)
/*  f0061c4:	82280190 */ 	lb	$t0,0x190($s1)
/*  f0061c8:	3c01bf80 */ 	lui	$at,0xbf80
/*  f0061cc:	00002025 */ 	or	$a0,$zero,$zero
/*  f0061d0:	11000014 */ 	beqz	$t0,.NB0f006224
/*  f0061d4:	00023400 */ 	sll	$a2,$v0,0x10
/*  f0061d8:	8e25001c */ 	lw	$a1,0x1c($s1)
/*  f0061dc:	44810000 */ 	mtc1	$at,$f0
/*  f0061e0:	00064c03 */ 	sra	$t1,$a2,0x10
/*  f0061e4:	240affff */ 	addiu	$t2,$zero,-1
/*  f0061e8:	240bffff */ 	addiu	$t3,$zero,-1
/*  f0061ec:	afab002c */ 	sw	$t3,0x2c($sp)
/*  f0061f0:	afaa0010 */ 	sw	$t2,0x10($sp)
/*  f0061f4:	01203025 */ 	or	$a2,$t1,$zero
/*  f0061f8:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f0061fc:	afa00020 */ 	sw	$zero,0x20($sp)
/*  f006200:	afa0001c */ 	sw	$zero,0x1c($sp)
/*  f006204:	afa00018 */ 	sw	$zero,0x18($sp)
/*  f006208:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f00620c:	2407ffff */ 	addiu	$a3,$zero,-1
/*  f006210:	e7a00024 */ 	swc1	$f0,0x24($sp)
/*  f006214:	e7a00030 */ 	swc1	$f0,0x30($sp)
/*  f006218:	e7a00034 */ 	swc1	$f0,0x34($sp)
/*  f00621c:	0fc24762 */ 	jal	func0f0939f8
/*  f006220:	e7a00038 */ 	swc1	$f0,0x38($sp)
.NB0f006224:
/*  f006224:	8e2c0020 */ 	lw	$t4,0x20($s1)
.NB0f006228:
/*  f006228:	ae30019c */ 	sw	$s0,0x19c($s1)
/*  f00622c:	3c013e80 */ 	lui	$at,0x3e80
/*  f006230:	8d8d0020 */ 	lw	$t5,0x20($t4)
/*  f006234:	44813000 */ 	mtc1	$at,$f6
/*  f006238:	c5a4001c */ 	lwc1	$f4,0x1c($t5)
/*  f00623c:	46062202 */ 	mul.s	$f8,$f4,$f6
/*  f006240:	10000004 */ 	beqz	$zero,.NB0f006254
/*  f006244:	e6280198 */ 	swc1	$f8,0x198($s1)
/*  f006248:	26100001 */ 	addiu	$s0,$s0,0x1
.NB0f00624c:
/*  f00624c:	1601ff70 */ 	bne	$s0,$at,.NB0f006010
/*  f006250:	24630004 */ 	addiu	$v1,$v1,0x4
.NB0f006254:
/*  f006254:	8fbf004c */ 	lw	$ra,0x4c($sp)
.NB0f006258:
/*  f006258:	8fb00044 */ 	lw	$s0,0x44($sp)
/*  f00625c:	8fb10048 */ 	lw	$s1,0x48($sp)
/*  f006260:	03e00008 */ 	jr	$ra
/*  f006264:	27bd0078 */ 	addiu	$sp,$sp,0x78
);
#endif

/**
 * Check if a footstep sound should play for the given chr and play it if so.
 *
 * It is assumed that the chr is moving normally and not via magic.
 */
// Mismatch: load of 10.0f into $at is swapped with load of prevframe from stack
//void chrCheckFootstep(struct chrdata *chr)
//{
//	if (debugEnableFootsteps() && PLAYERCOUNT() == 1 && chr) {
//		chr->footstep = 0;
//		chr->magicanim = -1;
//		chr->magicframe = 0;
//
//		if (chr->model && chr->model->anim) {
//			s32 soundnum;
//			f32 prevframe = chr->oldframe; // 70
//			f32 frame = chr->model->anim->frame;
//			f32 stack;
//			s32 i;
//
//			chr->oldframe = frame;
//
//			for (i = 0; i < ARRAYCOUNT(g_FootstepAnims); i++) {
//				if (modelGetAnimNum(chr->model) == g_FootstepAnims[i].animnum) {
//					if (CHRRACE(chr) == RACE_SKEDAR && g_FootstepAnims[i].animnum == ANIM_SKEDAR_RUNNING) {
//						if ((frame >= 2 && prevframe < 2) || (frame >= 17 && prevframe < 17)) {
//							chr->footstep = 1;
//						} else if ((frame >= 10 && prevframe < 10) || (frame >= 25 && prevframe < 25)) {
//							chr->footstep = 2;
//						}
//					} else {
//						if (frame >= g_FootstepAnims[i].frame1 && prevframe < g_FootstepAnims[i].frame1) {
//							chr->footstep = 1;
//						} else if (frame >= g_FootstepAnims[i].frame2 && prevframe < g_FootstepAnims[i].frame2) {
//							chr->footstep = 2;
//						}
//					}
//
//					soundnum = chrChooseFootstepSound(chr, i);
//
//					if (soundnum != -1 && chr->footstep != 0) {
//						func0f0939f8(NULL, chr->prop, soundnum, -1,
//								-1, 1024, 0, 16, NULL, -1, NULL, -1, -1, -1, -1);
//					}
//
//					chr->magicanim = i;
//#if VERSION >= VERSION_PAL_FINAL
//					chr->magicspeed = chr->model->anim->speed;
//#else
//					chr->magicspeed = chr->model->anim->speed * 0.25f;
//#endif
//					return;
//				}
//			}
//		}
//	}
//}

/**
 * Assuming the given chr is moving using magic, check if a footstep sound
 * should play and play it if so.
 *
 * The "magic" method of movement applies when the chr is off-screen.
 * It uses a computationally simple approach to movement.
 */
void chrCheckFootstepMagic(struct chrdata *chr)
{
	s32 index;
	f32 frame;
	f32 prevframe;
	struct prop *playerprop = g_Vars.currentplayer->prop;
	f32 xdiff;
	f32 ydiff;
	f32 zdiff;
	s32 soundnum;

	if (debugEnableFootsteps() && PLAYERCOUNT() == 1 && chr->magicanim >= 0) {
#if VERSION >= VERSION_PAL_FINAL
		chr->magicframe += g_Vars.lvupdate240freal * chr->magicspeed;
#else
		chr->magicframe += g_Vars.lvupdate240 * chr->magicspeed;
#endif

		if (chr->prop) {
			xdiff = playerprop->pos.x - chr->prop->pos.x;
			ydiff = playerprop->pos.y - chr->prop->pos.y;

			if (ydiff < 0.0f) {
				ydiff = -ydiff;
			}

			zdiff = playerprop->pos.z - chr->prop->pos.z;

			frame = chr->magicframe;
			index = chr->magicanim;
			prevframe = chr->oldframe;

			chr->footstep = 0;
			chr->oldframe = frame;

			if (ydiff < 250 && xdiff * xdiff + zdiff * zdiff < 3000000) {
				if (CHRRACE(chr) == RACE_SKEDAR && g_FootstepAnims[index].animnum == ANIM_SKEDAR_RUNNING) {
					if ((frame >= 2 && prevframe < 2) || (frame >= 17 && prevframe < 17)) {
						chr->footstep = 1;
					} else if ((frame >= 10 && prevframe < 10) || (frame >= 25 && prevframe < 25)) {
						chr->footstep = 2;
					}
				} else {
					if (frame >= g_FootstepAnims[index].frame1 && prevframe < g_FootstepAnims[index].frame1) {
						chr->footstep = 1;
					} else if (frame >= g_FootstepAnims[index].frame2 && prevframe < g_FootstepAnims[index].frame2) {
						chr->footstep = 2;
					}
				}

				soundnum = chrChooseFootstepSound(chr, index);

				if (soundnum != -1 && chr->footstep != 0) {
#if VERSION >= VERSION_NTSC_1_0
					func0f0939f8(NULL, chr->prop, soundnum, -1,
							-1, 1024, 0, 16, NULL, -1, NULL, -1, -1, -1, -1);
#else
					func0f0939f8(NULL, chr->prop, soundnum, -1,
							-1, 0, 0, 0, NULL, -1, NULL, -1, -1, -1, -1);
#endif
				}
			}

			if (func0f005fd0(g_FootstepAnims[index].animnum)) {
				if (chr->magicframe > 22) {
					chr->magicframe -= 22;
				}
			} else {
				if (chr->magicframe > 34) {
					chr->magicframe -= 34;
				}
			}
		}
	}
}
