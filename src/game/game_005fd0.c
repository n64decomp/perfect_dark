#include <ultra64.h>
#include "constants.h"
#include "game/debug.h"
#include "game/game_006900.h"
#include "game/game_092610.h"
#include "game/room.h"
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

struct footstepframe g_FootstepFrames[] = {
	{ 0x002b, 0x08, 0x19 },
	{ 0x0029, 0x05, 0x0e },
	{ 0x006b, 0x08, 0x19 },
	{ 0x0028, 0x1b, 0x08 },
	{ 0x002a, 0x12, 0x06 },
	{ 0x0052, 0x08, 0x19 },
	{ 0x0053, 0x19, 0x08 },
	{ 0x0054, 0x19, 0x08 },
	{ 0x0055, 0x07, 0x12 },
	{ 0x0056, 0x07, 0x12 },
	{ 0x0057, 0x12, 0x07 },
	{ 0x0058, 0x0f, 0x05 },
	{ 0x0059, 0x08, 0x14 },
	{ 0x005a, 0x06, 0x0f },
	{ 0x006c, 0x19, 0x08 },
	{ 0x006d, 0x19, 0x08 },
	{ 0x006e, 0x08, 0x13 },
	{ 0x006f, 0x15, 0x08 },
	{ 0x0070, 0x0f, 0x05 },
	{ 0x0071, 0x0f, 0x05 },
	{ 0x0072, 0x17, 0x08 },
	{ 0x0073, 0x08, 0x13 },
	{ 0x0093, 0x17, 0x0a },
	{ 0x0094, 0x0f, 0x05 },
	{ 0x005f, 0x0e, 0x01 },
	{ 0x0016, 0x1d, 0x0a },
	{ 0x0018, 0x18, 0x2e },
	{ 0x001b, 0x0a, 0x1c },
	{ 0x001d, 0x0d, 0x02 },
	{ 0x001e, 0x0c, 0x01 },
	{ 0x005c, 0x13, 0x2a },
	{ 0x005d, 0x0f, 0x05 },
	{ 0x005e, 0x04, 0x0c },
	{ 0x0392, 0x05, 0x14 },
	{ 0x0394, 0x00, 0x00 },
};

bool func0f005fd0(s32 arg0)
{
	switch (arg0) {
	case 29:
	case 30:
	case 41:
	case 42:
	case 85:
	case 86:
	case 87:
	case 88:
	case 89:
	case 90:
	case 93:
	case 94:
	case 95:
	case 110:
	case 111:
	case 112:
	case 113:
	case 115:
	case 147:
	case 148:
	case 916:
		return true;
	}

	return false;
}

s32 chrChooseFootstepSound(struct chrdata *chr, u32 arg1)
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

	which = func0f005fd0(g_FootstepFrames[arg1].animnum);

	do {
		rand = random() & 7;
		index = (which ? 2 : 0) + (rand & 5) + floortype * 8;
	} while (index == chr->lastfootsample);

	chr->lastfootsample = index;

	return g_FootstepSounds[index];
}

#if VERSION >= VERSION_PAL_FINAL
GLOBAL_ASM(
glabel func0f0061dc
/*  f0061dc:	27bdff88 */ 	addiu	$sp,$sp,-120
/*  f0061e0:	afbf004c */ 	sw	$ra,0x4c($sp)
/*  f0061e4:	afb10048 */ 	sw	$s1,0x48($sp)
/*  f0061e8:	00808825 */ 	move	$s1,$a0
/*  f0061ec:	0fc47e7e */ 	jal	0xf11f9f8
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
/*  f0062c4:	0c0073c3 */ 	jal	0x1cf0c
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
/*  f006460:	0fc0181d */ 	jal	0xf006074
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
/*  f0064d4:	0fc24e3a */ 	jal	0xf0938e8
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
#else
GLOBAL_ASM(
glabel func0f0061dc
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
/*  f0062a4:	3c038006 */ 	lui	$v1,%hi(g_FootstepFrames)
/*  f0062a8:	246315a0 */ 	addiu	$v1,$v1,%lo(g_FootstepFrames)
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
#endif

// Mismatch: load of 10.0f into $at is swapped with load of prevframe from stack
//void func0f0061dc(struct chrdata *chr)
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
//			for (i = 0; i < ARRAYCOUNT(g_FootstepFrames); i++) {
//				if (modelGetAnimNum(chr->model) == g_FootstepFrames[i].animnum) {
//					if (CHRRACE(chr) == RACE_SKEDAR && g_FootstepFrames[i].animnum == 0x394) {
//						if ((frame >= 2 && prevframe < 2) || (frame >= 17 && prevframe < 17)) {
//							chr->footstep = 1;
//						} else if ((frame >= 10 && prevframe < 10) || (frame >= 25 && prevframe < 25)) {
//							chr->footstep = 2;
//						}
//					} else {
//						if (frame >= g_FootstepFrames[i].frame1 && prevframe < g_FootstepFrames[i].frame1) {
//							chr->footstep = 1;
//						} else if (frame >= g_FootstepFrames[i].frame2 && prevframe < g_FootstepFrames[i].frame2) {
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

#if VERSION >= VERSION_PAL_FINAL
GLOBAL_ASM(
glabel func0f006520
.late_rodata
glabel var7f1a7e6c
.word 0x4a371b00
.text
/*  f006514:	3c05800a */ 	lui	$a1,0x800a
/*  f006518:	24a5a510 */ 	addiu	$a1,$a1,-23280
/*  f00651c:	8cae0284 */ 	lw	$t6,0x284($a1)
/*  f006520:	27bdffa0 */ 	addiu	$sp,$sp,-96
/*  f006524:	afbf004c */ 	sw	$ra,0x4c($sp)
/*  f006528:	afb00048 */ 	sw	$s0,0x48($sp)
/*  f00652c:	8dc700bc */ 	lw	$a3,0xbc($t6)
/*  f006530:	00808025 */ 	move	$s0,$a0
/*  f006534:	0fc47e7e */ 	jal	0xf11f9f8
/*  f006538:	afa70050 */ 	sw	$a3,0x50($sp)
/*  f00653c:	3c05800a */ 	lui	$a1,0x800a
/*  f006540:	24a5a510 */ 	addiu	$a1,$a1,-23280
/*  f006544:	104000e4 */ 	beqz	$v0,.PF0f0068d8
/*  f006548:	8fa70050 */ 	lw	$a3,0x50($sp)
/*  f00654c:	8caf006c */ 	lw	$t7,0x6c($a1)
/*  f006550:	24080001 */ 	li	$t0,0x1
/*  f006554:	00003025 */ 	move	$a2,$zero
/*  f006558:	11e00003 */ 	beqz	$t7,.PF0f006568
/*  f00655c:	00001825 */ 	move	$v1,$zero
/*  f006560:	10000001 */ 	b	.PF0f006568
/*  f006564:	24060001 */ 	li	$a2,0x1
.PF0f006568:
/*  f006568:	8cb80068 */ 	lw	$t8,0x68($a1)
/*  f00656c:	00002025 */ 	move	$a0,$zero
/*  f006570:	00001025 */ 	move	$v0,$zero
/*  f006574:	13000003 */ 	beqz	$t8,.PF0f006584
/*  f006578:	00000000 */ 	nop
/*  f00657c:	10000001 */ 	b	.PF0f006584
/*  f006580:	24030001 */ 	li	$v1,0x1
.PF0f006584:
/*  f006584:	8cb90064 */ 	lw	$t9,0x64($a1)
/*  f006588:	13200003 */ 	beqz	$t9,.PF0f006598
/*  f00658c:	00000000 */ 	nop
/*  f006590:	10000001 */ 	b	.PF0f006598
/*  f006594:	24040001 */ 	li	$a0,0x1
.PF0f006598:
/*  f006598:	8ca90070 */ 	lw	$t1,0x70($a1)
/*  f00659c:	11200003 */ 	beqz	$t1,.PF0f0065ac
/*  f0065a0:	00000000 */ 	nop
/*  f0065a4:	10000001 */ 	b	.PF0f0065ac
/*  f0065a8:	24020001 */ 	li	$v0,0x1
.PF0f0065ac:
/*  f0065ac:	00445021 */ 	addu	$t2,$v0,$a0
/*  f0065b0:	01435821 */ 	addu	$t3,$t2,$v1
/*  f0065b4:	01666021 */ 	addu	$t4,$t3,$a2
/*  f0065b8:	550c00c8 */ 	bnel	$t0,$t4,.PF0f0068dc
/*  f0065bc:	8fbf004c */ 	lw	$ra,0x4c($sp)
/*  f0065c0:	860d019c */ 	lh	$t5,0x19c($s0)
/*  f0065c4:	05a200c5 */ 	bltzl	$t5,.PF0f0068dc
/*  f0065c8:	8fbf004c */ 	lw	$ra,0x4c($sp)
/*  f0065cc:	c4a4004c */ 	lwc1	$f4,0x4c($a1)
/*  f0065d0:	c6060198 */ 	lwc1	$f6,0x198($s0)
/*  f0065d4:	c60a0194 */ 	lwc1	$f10,0x194($s0)
/*  f0065d8:	8e02001c */ 	lw	$v0,0x1c($s0)
/*  f0065dc:	46062202 */ 	mul.s	$f8,$f4,$f6
/*  f0065e0:	3c01437a */ 	lui	$at,0x437a
/*  f0065e4:	46085480 */ 	add.s	$f18,$f10,$f8
/*  f0065e8:	104000bb */ 	beqz	$v0,.PF0f0068d8
/*  f0065ec:	e6120194 */ 	swc1	$f18,0x194($s0)
/*  f0065f0:	c4ea000c */ 	lwc1	$f10,0xc($a3)
/*  f0065f4:	c448000c */ 	lwc1	$f8,0xc($v0)
/*  f0065f8:	44809000 */ 	mtc1	$zero,$f18
/*  f0065fc:	c4e40008 */ 	lwc1	$f4,0x8($a3)
/*  f006600:	46085001 */ 	sub.s	$f0,$f10,$f8
/*  f006604:	c4460008 */ 	lwc1	$f6,0x8($v0)
/*  f006608:	44815000 */ 	mtc1	$at,$f10
/*  f00660c:	4612003c */ 	c.lt.s	$f0,$f18
/*  f006610:	46062081 */ 	sub.s	$f2,$f4,$f6
/*  f006614:	45020003 */ 	bc1fl	.PF0f006624
/*  f006618:	460a003c */ 	c.lt.s	$f0,$f10
/*  f00661c:	46000007 */ 	neg.s	$f0,$f0
/*  f006620:	460a003c */ 	c.lt.s	$f0,$f10
.PF0f006624:
/*  f006624:	c4e40010 */ 	lwc1	$f4,0x10($a3)
/*  f006628:	c4460010 */ 	lwc1	$f6,0x10($v0)
/*  f00662c:	c60e0194 */ 	lwc1	$f14,0x194($s0)
/*  f006630:	8605019c */ 	lh	$a1,0x19c($s0)
/*  f006634:	c610018c */ 	lwc1	$f16,0x18c($s0)
/*  f006638:	a2000190 */ 	sb	$zero,0x190($s0)
/*  f00663c:	e60e018c */ 	swc1	$f14,0x18c($s0)
/*  f006640:	46062301 */ 	sub.s	$f12,$f4,$f6
/*  f006644:	4500008a */ 	bc1f	.PF0f006870
/*  f006648:	afa5005c */ 	sw	$a1,0x5c($sp)
/*  f00664c:	46021202 */ 	mul.s	$f8,$f2,$f2
/*  f006650:	3c017f1b */ 	lui	$at,0x7f1b
/*  f006654:	c426906c */ 	lwc1	$f6,-0x6f94($at)
/*  f006658:	460c6482 */ 	mul.s	$f18,$f12,$f12
/*  f00665c:	afa5005c */ 	sw	$a1,0x5c($sp)
/*  f006660:	02002025 */ 	move	$a0,$s0
/*  f006664:	46124100 */ 	add.s	$f4,$f8,$f18
/*  f006668:	4606203c */ 	c.lt.s	$f4,$f6
/*  f00666c:	00000000 */ 	nop
/*  f006670:	45020080 */ 	bc1fl	.PF0f006874
/*  f006674:	8fa5005c */ 	lw	$a1,0x5c($sp)
/*  f006678:	12000003 */ 	beqz	$s0,.PF0f006688
/*  f00667c:	00001025 */ 	move	$v0,$zero
/*  f006680:	10000001 */ 	b	.PF0f006688
/*  f006684:	920202fe */ 	lbu	$v0,0x2fe($s0)
.PF0f006688:
/*  f006688:	14480033 */ 	bne	$v0,$t0,.PF0f006758
/*  f00668c:	00057080 */ 	sll	$t6,$a1,0x2
/*  f006690:	3c0f8006 */ 	lui	$t7,0x8006
/*  f006694:	01ee7821 */ 	addu	$t7,$t7,$t6
/*  f006698:	95ef1270 */ 	lhu	$t7,0x1270($t7)
/*  f00669c:	24010394 */ 	li	$at,0x394
/*  f0066a0:	15e1002d */ 	bne	$t7,$at,.PF0f006758
/*  f0066a4:	3c014000 */ 	lui	$at,0x4000
/*  f0066a8:	44810000 */ 	mtc1	$at,$f0
/*  f0066ac:	3c014188 */ 	lui	$at,0x4188
/*  f0066b0:	460e003e */ 	c.le.s	$f0,$f14
/*  f0066b4:	00000000 */ 	nop
/*  f0066b8:	45020006 */ 	bc1fl	.PF0f0066d4
/*  f0066bc:	44810000 */ 	mtc1	$at,$f0
/*  f0066c0:	4600803c */ 	c.lt.s	$f16,$f0
/*  f0066c4:	00000000 */ 	nop
/*  f0066c8:	4501000b */ 	bc1t	.PF0f0066f8
/*  f0066cc:	00000000 */ 	nop
/*  f0066d0:	44810000 */ 	mtc1	$at,$f0
.PF0f0066d4:
/*  f0066d4:	3c014120 */ 	lui	$at,0x4120
/*  f0066d8:	460e003e */ 	c.le.s	$f0,$f14
/*  f0066dc:	00000000 */ 	nop
/*  f0066e0:	45020008 */ 	bc1fl	.PF0f006704
/*  f0066e4:	44810000 */ 	mtc1	$at,$f0
/*  f0066e8:	4600803c */ 	c.lt.s	$f16,$f0
/*  f0066ec:	00000000 */ 	nop
/*  f0066f0:	45020004 */ 	bc1fl	.PF0f006704
/*  f0066f4:	44810000 */ 	mtc1	$at,$f0
.PF0f0066f8:
/*  f0066f8:	1000003e */ 	b	.PF0f0067f4
/*  f0066fc:	a2080190 */ 	sb	$t0,0x190($s0)
/*  f006700:	44810000 */ 	mtc1	$at,$f0
.PF0f006704:
/*  f006704:	3c0141c8 */ 	lui	$at,0x41c8
/*  f006708:	460e003e */ 	c.le.s	$f0,$f14
/*  f00670c:	00000000 */ 	nop
/*  f006710:	45020006 */ 	bc1fl	.PF0f00672c
/*  f006714:	44810000 */ 	mtc1	$at,$f0
/*  f006718:	4600803c */ 	c.lt.s	$f16,$f0
/*  f00671c:	00000000 */ 	nop
/*  f006720:	4503000b */ 	bc1tl	.PF0f006750
/*  f006724:	24180002 */ 	li	$t8,0x2
/*  f006728:	44810000 */ 	mtc1	$at,$f0
.PF0f00672c:
/*  f00672c:	00000000 */ 	nop
/*  f006730:	460e003e */ 	c.le.s	$f0,$f14
/*  f006734:	00000000 */ 	nop
/*  f006738:	4500002e */ 	bc1f	.PF0f0067f4
/*  f00673c:	00000000 */ 	nop
/*  f006740:	4600803c */ 	c.lt.s	$f16,$f0
/*  f006744:	00000000 */ 	nop
/*  f006748:	4500002a */ 	bc1f	.PF0f0067f4
/*  f00674c:	24180002 */ 	li	$t8,0x2
.PF0f006750:
/*  f006750:	10000028 */ 	b	.PF0f0067f4
/*  f006754:	a2180190 */ 	sb	$t8,0x190($s0)
.PF0f006758:
/*  f006758:	3c098006 */ 	lui	$t1,0x8006
/*  f00675c:	25291270 */ 	addiu	$t1,$t1,0x1270
/*  f006760:	0005c880 */ 	sll	$t9,$a1,0x2
/*  f006764:	03291021 */ 	addu	$v0,$t9,$t1
/*  f006768:	904a0002 */ 	lbu	$t2,0x2($v0)
/*  f00676c:	3c014f80 */ 	lui	$at,0x4f80
/*  f006770:	448a5000 */ 	mtc1	$t2,$f10
/*  f006774:	05410004 */ 	bgez	$t2,.PF0f006788
/*  f006778:	46805020 */ 	cvt.s.w	$f0,$f10
/*  f00677c:	44814000 */ 	mtc1	$at,$f8
/*  f006780:	00000000 */ 	nop
/*  f006784:	46080000 */ 	add.s	$f0,$f0,$f8
.PF0f006788:
/*  f006788:	460e003e */ 	c.le.s	$f0,$f14
/*  f00678c:	00000000 */ 	nop
/*  f006790:	45020008 */ 	bc1fl	.PF0f0067b4
/*  f006794:	904b0003 */ 	lbu	$t3,0x3($v0)
/*  f006798:	4600803c */ 	c.lt.s	$f16,$f0
/*  f00679c:	00000000 */ 	nop
/*  f0067a0:	45020004 */ 	bc1fl	.PF0f0067b4
/*  f0067a4:	904b0003 */ 	lbu	$t3,0x3($v0)
/*  f0067a8:	10000012 */ 	b	.PF0f0067f4
/*  f0067ac:	a2080190 */ 	sb	$t0,0x190($s0)
/*  f0067b0:	904b0003 */ 	lbu	$t3,0x3($v0)
.PF0f0067b4:
/*  f0067b4:	3c014f80 */ 	lui	$at,0x4f80
/*  f0067b8:	448b9000 */ 	mtc1	$t3,$f18
/*  f0067bc:	05610004 */ 	bgez	$t3,.PF0f0067d0
/*  f0067c0:	46809020 */ 	cvt.s.w	$f0,$f18
/*  f0067c4:	44812000 */ 	mtc1	$at,$f4
/*  f0067c8:	00000000 */ 	nop
/*  f0067cc:	46040000 */ 	add.s	$f0,$f0,$f4
.PF0f0067d0:
/*  f0067d0:	460e003e */ 	c.le.s	$f0,$f14
/*  f0067d4:	00000000 */ 	nop
/*  f0067d8:	45000006 */ 	bc1f	.PF0f0067f4
/*  f0067dc:	00000000 */ 	nop
/*  f0067e0:	4600803c */ 	c.lt.s	$f16,$f0
/*  f0067e4:	240c0002 */ 	li	$t4,0x2
/*  f0067e8:	45000002 */ 	bc1f	.PF0f0067f4
/*  f0067ec:	00000000 */ 	nop
/*  f0067f0:	a20c0190 */ 	sb	$t4,0x190($s0)
.PF0f0067f4:
/*  f0067f4:	0fc0181d */ 	jal	0xf006074
/*  f0067f8:	afa5005c */ 	sw	$a1,0x5c($sp)
/*  f0067fc:	2401ffff */ 	li	$at,-1
/*  f006800:	5041001c */ 	beql	$v0,$at,.PF0f006874
/*  f006804:	8fa5005c */ 	lw	$a1,0x5c($sp)
/*  f006808:	820d0190 */ 	lb	$t5,0x190($s0)
/*  f00680c:	3c01bf80 */ 	lui	$at,0xbf80
/*  f006810:	00002025 */ 	move	$a0,$zero
/*  f006814:	11a00016 */ 	beqz	$t5,.PF0f006870
/*  f006818:	00023400 */ 	sll	$a2,$v0,0x10
/*  f00681c:	8e05001c */ 	lw	$a1,0x1c($s0)
/*  f006820:	44810000 */ 	mtc1	$at,$f0
/*  f006824:	00067403 */ 	sra	$t6,$a2,0x10
/*  f006828:	240fffff */ 	li	$t7,-1
/*  f00682c:	24180400 */ 	li	$t8,0x400
/*  f006830:	24190010 */ 	li	$t9,0x10
/*  f006834:	2409ffff */ 	li	$t1,-1
/*  f006838:	afa9002c */ 	sw	$t1,0x2c($sp)
/*  f00683c:	afb9001c */ 	sw	$t9,0x1c($sp)
/*  f006840:	afb80014 */ 	sw	$t8,0x14($sp)
/*  f006844:	afaf0010 */ 	sw	$t7,0x10($sp)
/*  f006848:	01c03025 */ 	move	$a2,$t6
/*  f00684c:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f006850:	afa00020 */ 	sw	$zero,0x20($sp)
/*  f006854:	afa00018 */ 	sw	$zero,0x18($sp)
/*  f006858:	2407ffff */ 	li	$a3,-1
/*  f00685c:	e7a00024 */ 	swc1	$f0,0x24($sp)
/*  f006860:	e7a00030 */ 	swc1	$f0,0x30($sp)
/*  f006864:	e7a00034 */ 	swc1	$f0,0x34($sp)
/*  f006868:	0fc24e3a */ 	jal	0xf0938e8
/*  f00686c:	e7a00038 */ 	swc1	$f0,0x38($sp)
.PF0f006870:
/*  f006870:	8fa5005c */ 	lw	$a1,0x5c($sp)
.PF0f006874:
/*  f006874:	3c048006 */ 	lui	$a0,0x8006
/*  f006878:	00055080 */ 	sll	$t2,$a1,0x2
/*  f00687c:	008a2021 */ 	addu	$a0,$a0,$t2
/*  f006880:	0fc017f4 */ 	jal	0xf005fd0
/*  f006884:	94841270 */ 	lhu	$a0,0x1270($a0)
/*  f006888:	1040000b */ 	beqz	$v0,.PF0f0068b8
/*  f00688c:	3c014208 */ 	lui	$at,0x4208
/*  f006890:	3c0141b0 */ 	lui	$at,0x41b0
/*  f006894:	44811000 */ 	mtc1	$at,$f2
/*  f006898:	c6000194 */ 	lwc1	$f0,0x194($s0)
/*  f00689c:	4600103c */ 	c.lt.s	$f2,$f0
/*  f0068a0:	00000000 */ 	nop
/*  f0068a4:	4502000d */ 	bc1fl	.PF0f0068dc
/*  f0068a8:	8fbf004c */ 	lw	$ra,0x4c($sp)
/*  f0068ac:	46020181 */ 	sub.s	$f6,$f0,$f2
/*  f0068b0:	10000009 */ 	b	.PF0f0068d8
/*  f0068b4:	e6060194 */ 	swc1	$f6,0x194($s0)
.PF0f0068b8:
/*  f0068b8:	44811000 */ 	mtc1	$at,$f2
/*  f0068bc:	c6000194 */ 	lwc1	$f0,0x194($s0)
/*  f0068c0:	4600103c */ 	c.lt.s	$f2,$f0
/*  f0068c4:	00000000 */ 	nop
/*  f0068c8:	45020004 */ 	bc1fl	.PF0f0068dc
/*  f0068cc:	8fbf004c */ 	lw	$ra,0x4c($sp)
/*  f0068d0:	46020281 */ 	sub.s	$f10,$f0,$f2
/*  f0068d4:	e60a0194 */ 	swc1	$f10,0x194($s0)
.PF0f0068d8:
/*  f0068d8:	8fbf004c */ 	lw	$ra,0x4c($sp)
.PF0f0068dc:
/*  f0068dc:	8fb00048 */ 	lw	$s0,0x48($sp)
/*  f0068e0:	27bd0060 */ 	addiu	$sp,$sp,0x60
/*  f0068e4:	03e00008 */ 	jr	$ra
/*  f0068e8:	00000000 */ 	nop
);
#else
GLOBAL_ASM(
glabel func0f006520
.late_rodata
glabel var7f1a7e6c
.word 0x4a371b00
.text
/*  f006520:	3c05800a */ 	lui	$a1,%hi(g_Vars)
/*  f006524:	24a59fc0 */ 	addiu	$a1,$a1,%lo(g_Vars)
/*  f006528:	8cae0284 */ 	lw	$t6,0x284($a1)
/*  f00652c:	27bdffa0 */ 	addiu	$sp,$sp,-96
/*  f006530:	afbf004c */ 	sw	$ra,0x4c($sp)
/*  f006534:	afb00048 */ 	sw	$s0,0x48($sp)
/*  f006538:	8dc700bc */ 	lw	$a3,0xbc($t6)
/*  f00653c:	00808025 */ 	or	$s0,$a0,$zero
/*  f006540:	0fc47bbe */ 	jal	debugEnableFootsteps
/*  f006544:	afa70050 */ 	sw	$a3,0x50($sp)
/*  f006548:	3c05800a */ 	lui	$a1,%hi(g_Vars)
/*  f00654c:	24a59fc0 */ 	addiu	$a1,$a1,%lo(g_Vars)
/*  f006550:	104000e6 */ 	beqz	$v0,.L0f0068ec
/*  f006554:	8fa70050 */ 	lw	$a3,0x50($sp)
/*  f006558:	8caf006c */ 	lw	$t7,0x6c($a1)
/*  f00655c:	24080001 */ 	addiu	$t0,$zero,0x1
/*  f006560:	00003025 */ 	or	$a2,$zero,$zero
/*  f006564:	11e00003 */ 	beqz	$t7,.L0f006574
/*  f006568:	00001825 */ 	or	$v1,$zero,$zero
/*  f00656c:	10000001 */ 	b	.L0f006574
/*  f006570:	24060001 */ 	addiu	$a2,$zero,0x1
.L0f006574:
/*  f006574:	8cb80068 */ 	lw	$t8,0x68($a1)
/*  f006578:	00002025 */ 	or	$a0,$zero,$zero
/*  f00657c:	00001025 */ 	or	$v0,$zero,$zero
/*  f006580:	13000003 */ 	beqz	$t8,.L0f006590
/*  f006584:	00000000 */ 	nop
/*  f006588:	10000001 */ 	b	.L0f006590
/*  f00658c:	24030001 */ 	addiu	$v1,$zero,0x1
.L0f006590:
/*  f006590:	8cb90064 */ 	lw	$t9,0x64($a1)
/*  f006594:	13200003 */ 	beqz	$t9,.L0f0065a4
/*  f006598:	00000000 */ 	nop
/*  f00659c:	10000001 */ 	b	.L0f0065a4
/*  f0065a0:	24040001 */ 	addiu	$a0,$zero,0x1
.L0f0065a4:
/*  f0065a4:	8ca90070 */ 	lw	$t1,0x70($a1)
/*  f0065a8:	11200003 */ 	beqz	$t1,.L0f0065b8
/*  f0065ac:	00000000 */ 	nop
/*  f0065b0:	10000001 */ 	b	.L0f0065b8
/*  f0065b4:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f0065b8:
/*  f0065b8:	00445021 */ 	addu	$t2,$v0,$a0
/*  f0065bc:	01435821 */ 	addu	$t3,$t2,$v1
/*  f0065c0:	01666021 */ 	addu	$t4,$t3,$a2
/*  f0065c4:	550c00ca */ 	bnel	$t0,$t4,.L0f0068f0
/*  f0065c8:	8fbf004c */ 	lw	$ra,0x4c($sp)
/*  f0065cc:	860d019c */ 	lh	$t5,0x19c($s0)
/*  f0065d0:	05a200c7 */ 	bltzl	$t5,.L0f0068f0
/*  f0065d4:	8fbf004c */ 	lw	$ra,0x4c($sp)
/*  f0065d8:	8cae0034 */ 	lw	$t6,0x34($a1)
/*  f0065dc:	c6080198 */ 	lwc1	$f8,0x198($s0)
/*  f0065e0:	c6120194 */ 	lwc1	$f18,0x194($s0)
/*  f0065e4:	448e2000 */ 	mtc1	$t6,$f4
/*  f0065e8:	8e02001c */ 	lw	$v0,0x1c($s0)
/*  f0065ec:	3c01437a */ 	lui	$at,0x437a
/*  f0065f0:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f0065f4:	46083282 */ 	mul.s	$f10,$f6,$f8
/*  f0065f8:	460a9100 */ 	add.s	$f4,$f18,$f10
/*  f0065fc:	104000bb */ 	beqz	$v0,.L0f0068ec
/*  f006600:	e6040194 */ 	swc1	$f4,0x194($s0)
/*  f006604:	c4f2000c */ 	lwc1	$f18,0xc($a3)
/*  f006608:	c44a000c */ 	lwc1	$f10,0xc($v0)
/*  f00660c:	44802000 */ 	mtc1	$zero,$f4
/*  f006610:	c4e60008 */ 	lwc1	$f6,0x8($a3)
/*  f006614:	460a9001 */ 	sub.s	$f0,$f18,$f10
/*  f006618:	c4480008 */ 	lwc1	$f8,0x8($v0)
/*  f00661c:	44819000 */ 	mtc1	$at,$f18
/*  f006620:	4604003c */ 	c.lt.s	$f0,$f4
/*  f006624:	46083081 */ 	sub.s	$f2,$f6,$f8
/*  f006628:	45020003 */ 	bc1fl	.L0f006638
/*  f00662c:	4612003c */ 	c.lt.s	$f0,$f18
/*  f006630:	46000007 */ 	neg.s	$f0,$f0
/*  f006634:	4612003c */ 	c.lt.s	$f0,$f18
.L0f006638:
/*  f006638:	c4e60010 */ 	lwc1	$f6,0x10($a3)
/*  f00663c:	c4480010 */ 	lwc1	$f8,0x10($v0)
/*  f006640:	c60e0194 */ 	lwc1	$f14,0x194($s0)
/*  f006644:	8605019c */ 	lh	$a1,0x19c($s0)
/*  f006648:	c610018c */ 	lwc1	$f16,0x18c($s0)
/*  f00664c:	a2000190 */ 	sb	$zero,0x190($s0)
/*  f006650:	e60e018c */ 	swc1	$f14,0x18c($s0)
/*  f006654:	46083301 */ 	sub.s	$f12,$f6,$f8
/*  f006658:	4500008a */ 	bc1f	.L0f006884
/*  f00665c:	afa5005c */ 	sw	$a1,0x5c($sp)
/*  f006660:	46021282 */ 	mul.s	$f10,$f2,$f2
/*  f006664:	3c017f1a */ 	lui	$at,%hi(var7f1a7e6c)
/*  f006668:	c4287e6c */ 	lwc1	$f8,%lo(var7f1a7e6c)($at)
/*  f00666c:	460c6102 */ 	mul.s	$f4,$f12,$f12
/*  f006670:	afa5005c */ 	sw	$a1,0x5c($sp)
/*  f006674:	02002025 */ 	or	$a0,$s0,$zero
/*  f006678:	46045180 */ 	add.s	$f6,$f10,$f4
/*  f00667c:	4608303c */ 	c.lt.s	$f6,$f8
/*  f006680:	00000000 */ 	nop
/*  f006684:	45020080 */ 	bc1fl	.L0f006888
/*  f006688:	8fa5005c */ 	lw	$a1,0x5c($sp)
/*  f00668c:	12000003 */ 	beqz	$s0,.L0f00669c
/*  f006690:	00001025 */ 	or	$v0,$zero,$zero
/*  f006694:	10000001 */ 	b	.L0f00669c
/*  f006698:	920202fe */ 	lbu	$v0,0x2fe($s0)
.L0f00669c:
/*  f00669c:	14480033 */ 	bne	$v0,$t0,.L0f00676c
/*  f0066a0:	00057880 */ 	sll	$t7,$a1,0x2
/*  f0066a4:	3c188006 */ 	lui	$t8,%hi(g_FootstepFrames)
/*  f0066a8:	030fc021 */ 	addu	$t8,$t8,$t7
/*  f0066ac:	971815a0 */ 	lhu	$t8,%lo(g_FootstepFrames)($t8)
/*  f0066b0:	24010394 */ 	addiu	$at,$zero,0x394
/*  f0066b4:	1701002d */ 	bne	$t8,$at,.L0f00676c
/*  f0066b8:	3c014000 */ 	lui	$at,0x4000
/*  f0066bc:	44810000 */ 	mtc1	$at,$f0
/*  f0066c0:	3c014188 */ 	lui	$at,0x4188
/*  f0066c4:	460e003e */ 	c.le.s	$f0,$f14
/*  f0066c8:	00000000 */ 	nop
/*  f0066cc:	45020006 */ 	bc1fl	.L0f0066e8
/*  f0066d0:	44810000 */ 	mtc1	$at,$f0
/*  f0066d4:	4600803c */ 	c.lt.s	$f16,$f0
/*  f0066d8:	00000000 */ 	nop
/*  f0066dc:	4501000b */ 	bc1t	.L0f00670c
/*  f0066e0:	00000000 */ 	nop
/*  f0066e4:	44810000 */ 	mtc1	$at,$f0
.L0f0066e8:
/*  f0066e8:	3c014120 */ 	lui	$at,0x4120
/*  f0066ec:	460e003e */ 	c.le.s	$f0,$f14
/*  f0066f0:	00000000 */ 	nop
/*  f0066f4:	45020008 */ 	bc1fl	.L0f006718
/*  f0066f8:	44810000 */ 	mtc1	$at,$f0
/*  f0066fc:	4600803c */ 	c.lt.s	$f16,$f0
/*  f006700:	00000000 */ 	nop
/*  f006704:	45020004 */ 	bc1fl	.L0f006718
/*  f006708:	44810000 */ 	mtc1	$at,$f0
.L0f00670c:
/*  f00670c:	1000003e */ 	b	.L0f006808
/*  f006710:	a2080190 */ 	sb	$t0,0x190($s0)
/*  f006714:	44810000 */ 	mtc1	$at,$f0
.L0f006718:
/*  f006718:	3c0141c8 */ 	lui	$at,0x41c8
/*  f00671c:	460e003e */ 	c.le.s	$f0,$f14
/*  f006720:	00000000 */ 	nop
/*  f006724:	45020006 */ 	bc1fl	.L0f006740
/*  f006728:	44810000 */ 	mtc1	$at,$f0
/*  f00672c:	4600803c */ 	c.lt.s	$f16,$f0
/*  f006730:	00000000 */ 	nop
/*  f006734:	4503000b */ 	bc1tl	.L0f006764
/*  f006738:	24190002 */ 	addiu	$t9,$zero,0x2
/*  f00673c:	44810000 */ 	mtc1	$at,$f0
.L0f006740:
/*  f006740:	00000000 */ 	nop
/*  f006744:	460e003e */ 	c.le.s	$f0,$f14
/*  f006748:	00000000 */ 	nop
/*  f00674c:	4500002e */ 	bc1f	.L0f006808
/*  f006750:	00000000 */ 	nop
/*  f006754:	4600803c */ 	c.lt.s	$f16,$f0
/*  f006758:	00000000 */ 	nop
/*  f00675c:	4500002a */ 	bc1f	.L0f006808
/*  f006760:	24190002 */ 	addiu	$t9,$zero,0x2
.L0f006764:
/*  f006764:	10000028 */ 	b	.L0f006808
/*  f006768:	a2190190 */ 	sb	$t9,0x190($s0)
.L0f00676c:
/*  f00676c:	3c0a8006 */ 	lui	$t2,%hi(g_FootstepFrames)
/*  f006770:	254a15a0 */ 	addiu	$t2,$t2,%lo(g_FootstepFrames)
/*  f006774:	00054880 */ 	sll	$t1,$a1,0x2
/*  f006778:	012a1021 */ 	addu	$v0,$t1,$t2
/*  f00677c:	904b0002 */ 	lbu	$t3,0x2($v0)
/*  f006780:	3c014f80 */ 	lui	$at,0x4f80
/*  f006784:	448b9000 */ 	mtc1	$t3,$f18
/*  f006788:	05610004 */ 	bgez	$t3,.L0f00679c
/*  f00678c:	46809020 */ 	cvt.s.w	$f0,$f18
/*  f006790:	44815000 */ 	mtc1	$at,$f10
/*  f006794:	00000000 */ 	nop
/*  f006798:	460a0000 */ 	add.s	$f0,$f0,$f10
.L0f00679c:
/*  f00679c:	460e003e */ 	c.le.s	$f0,$f14
/*  f0067a0:	00000000 */ 	nop
/*  f0067a4:	45020008 */ 	bc1fl	.L0f0067c8
/*  f0067a8:	904c0003 */ 	lbu	$t4,0x3($v0)
/*  f0067ac:	4600803c */ 	c.lt.s	$f16,$f0
/*  f0067b0:	00000000 */ 	nop
/*  f0067b4:	45020004 */ 	bc1fl	.L0f0067c8
/*  f0067b8:	904c0003 */ 	lbu	$t4,0x3($v0)
/*  f0067bc:	10000012 */ 	b	.L0f006808
/*  f0067c0:	a2080190 */ 	sb	$t0,0x190($s0)
/*  f0067c4:	904c0003 */ 	lbu	$t4,0x3($v0)
.L0f0067c8:
/*  f0067c8:	3c014f80 */ 	lui	$at,0x4f80
/*  f0067cc:	448c2000 */ 	mtc1	$t4,$f4
/*  f0067d0:	05810004 */ 	bgez	$t4,.L0f0067e4
/*  f0067d4:	46802020 */ 	cvt.s.w	$f0,$f4
/*  f0067d8:	44813000 */ 	mtc1	$at,$f6
/*  f0067dc:	00000000 */ 	nop
/*  f0067e0:	46060000 */ 	add.s	$f0,$f0,$f6
.L0f0067e4:
/*  f0067e4:	460e003e */ 	c.le.s	$f0,$f14
/*  f0067e8:	00000000 */ 	nop
/*  f0067ec:	45000006 */ 	bc1f	.L0f006808
/*  f0067f0:	00000000 */ 	nop
/*  f0067f4:	4600803c */ 	c.lt.s	$f16,$f0
/*  f0067f8:	240d0002 */ 	addiu	$t5,$zero,0x2
/*  f0067fc:	45000002 */ 	bc1f	.L0f006808
/*  f006800:	00000000 */ 	nop
/*  f006804:	a20d0190 */ 	sb	$t5,0x190($s0)
.L0f006808:
/*  f006808:	0fc0181d */ 	jal	chrChooseFootstepSound
/*  f00680c:	afa5005c */ 	sw	$a1,0x5c($sp)
/*  f006810:	2401ffff */ 	addiu	$at,$zero,-1
/*  f006814:	5041001c */ 	beql	$v0,$at,.L0f006888
/*  f006818:	8fa5005c */ 	lw	$a1,0x5c($sp)
/*  f00681c:	820e0190 */ 	lb	$t6,0x190($s0)
/*  f006820:	3c01bf80 */ 	lui	$at,0xbf80
/*  f006824:	00002025 */ 	or	$a0,$zero,$zero
/*  f006828:	11c00016 */ 	beqz	$t6,.L0f006884
/*  f00682c:	00023400 */ 	sll	$a2,$v0,0x10
/*  f006830:	8e05001c */ 	lw	$a1,0x1c($s0)
/*  f006834:	44810000 */ 	mtc1	$at,$f0
/*  f006838:	00067c03 */ 	sra	$t7,$a2,0x10
/*  f00683c:	2418ffff */ 	addiu	$t8,$zero,-1
/*  f006840:	24190400 */ 	addiu	$t9,$zero,0x400
/*  f006844:	24090010 */ 	addiu	$t1,$zero,0x10
/*  f006848:	240affff */ 	addiu	$t2,$zero,-1
/*  f00684c:	afaa002c */ 	sw	$t2,0x2c($sp)
/*  f006850:	afa9001c */ 	sw	$t1,0x1c($sp)
/*  f006854:	afb90014 */ 	sw	$t9,0x14($sp)
/*  f006858:	afb80010 */ 	sw	$t8,0x10($sp)
/*  f00685c:	01e03025 */ 	or	$a2,$t7,$zero
/*  f006860:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f006864:	afa00020 */ 	sw	$zero,0x20($sp)
/*  f006868:	afa00018 */ 	sw	$zero,0x18($sp)
/*  f00686c:	2407ffff */ 	addiu	$a3,$zero,-1
/*  f006870:	e7a00024 */ 	swc1	$f0,0x24($sp)
/*  f006874:	e7a00030 */ 	swc1	$f0,0x30($sp)
/*  f006878:	e7a00034 */ 	swc1	$f0,0x34($sp)
/*  f00687c:	0fc24e7e */ 	jal	func0f0939f8
/*  f006880:	e7a00038 */ 	swc1	$f0,0x38($sp)
.L0f006884:
/*  f006884:	8fa5005c */ 	lw	$a1,0x5c($sp)
.L0f006888:
/*  f006888:	3c048006 */ 	lui	$a0,%hi(g_FootstepFrames)
/*  f00688c:	00055880 */ 	sll	$t3,$a1,0x2
/*  f006890:	008b2021 */ 	addu	$a0,$a0,$t3
/*  f006894:	0fc017f4 */ 	jal	func0f005fd0
/*  f006898:	948415a0 */ 	lhu	$a0,%lo(g_FootstepFrames)($a0)
/*  f00689c:	1040000b */ 	beqz	$v0,.L0f0068cc
/*  f0068a0:	3c014208 */ 	lui	$at,0x4208
/*  f0068a4:	3c0141b0 */ 	lui	$at,0x41b0
/*  f0068a8:	44811000 */ 	mtc1	$at,$f2
/*  f0068ac:	c6000194 */ 	lwc1	$f0,0x194($s0)
/*  f0068b0:	4600103c */ 	c.lt.s	$f2,$f0
/*  f0068b4:	00000000 */ 	nop
/*  f0068b8:	4502000d */ 	bc1fl	.L0f0068f0
/*  f0068bc:	8fbf004c */ 	lw	$ra,0x4c($sp)
/*  f0068c0:	46020201 */ 	sub.s	$f8,$f0,$f2
/*  f0068c4:	10000009 */ 	b	.L0f0068ec
/*  f0068c8:	e6080194 */ 	swc1	$f8,0x194($s0)
.L0f0068cc:
/*  f0068cc:	44811000 */ 	mtc1	$at,$f2
/*  f0068d0:	c6000194 */ 	lwc1	$f0,0x194($s0)
/*  f0068d4:	4600103c */ 	c.lt.s	$f2,$f0
/*  f0068d8:	00000000 */ 	nop
/*  f0068dc:	45020004 */ 	bc1fl	.L0f0068f0
/*  f0068e0:	8fbf004c */ 	lw	$ra,0x4c($sp)
/*  f0068e4:	46020481 */ 	sub.s	$f18,$f0,$f2
/*  f0068e8:	e6120194 */ 	swc1	$f18,0x194($s0)
.L0f0068ec:
/*  f0068ec:	8fbf004c */ 	lw	$ra,0x4c($sp)
.L0f0068f0:
/*  f0068f0:	8fb00048 */ 	lw	$s0,0x48($sp)
/*  f0068f4:	27bd0060 */ 	addiu	$sp,$sp,0x60
/*  f0068f8:	03e00008 */ 	jr	$ra
/*  f0068fc:	00000000 */ 	nop
);
#endif
