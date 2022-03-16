#include <ultra64.h>
#include "constants.h"
#include "game/music.h"
#include "game/options.h"
#include "bss.h"
#include "data.h"
#include "types.h"

u8 g_InGameSubtitles = 1;
u8 g_CutsceneSubtitles = 0;
u32 var8007fa98 = 0x00000000;
u32 var8007fa9c = 0x00000001;
u32 var8007faa0 = 0x00000000;
u32 var8007faa4 = 0x00000001;
u32 var8007faa8 = 0x00000001;
u32 var8007faac = 0x00000001;
s32 g_ScreenSize = SCREENSIZE_FULL;
s32 g_ScreenRatio = SCREENRATIO_NORMAL;
u8 g_ScreenSplit = SCREENSPLIT_HORIZONTAL;

#if VERSION < VERSION_NTSC_1_0
u16 var8008231cnb = 0x7fff;
#endif

s32 optionsGetControlMode(s32 mpchrnum)
{
	return g_PlayerConfigsArray[mpchrnum].controlmode;
}

void optionsSetControlMode(s32 mpchrnum, s32 mode)
{
	g_PlayerConfigsArray[mpchrnum].controlmode = mode;
}

s32 optionsGetContpadNum1(s32 mpchrnum)
{
	return g_PlayerConfigsArray[mpchrnum].contpad1;
}

s32 optionsGetContpadNum2(s32 mpchrnum)
{
	return g_PlayerConfigsArray[mpchrnum].contpad2;
}

s32 optionsGetForwardPitch(s32 mpchrnum)
{
	return (g_PlayerConfigsArray[mpchrnum].options & OPTION_FORWARDPITCH) != 0;
}

s32 optionsGetAutoAim(s32 mpchrnum)
{
	return (g_PlayerConfigsArray[mpchrnum].options & OPTION_AUTOAIM) != 0;
}

s32 optionsGetLookAhead(s32 mpchrnum)
{
	return (g_PlayerConfigsArray[mpchrnum].options & OPTION_LOOKAHEAD) != 0;
}

s32 optionsGetAimControl(s32 mpchrnum)
{
	return (g_PlayerConfigsArray[mpchrnum].options & OPTION_AIMCONTROL) != 0;
}

s32 optionsGetSightOnScreen(s32 mpchrnum)
{
	return (g_PlayerConfigsArray[mpchrnum].options & OPTION_SIGHTONSCREEN) != 0;
}

s32 optionsGetAmmoOnScreen(s32 mpchrnum)
{
	return (g_PlayerConfigsArray[mpchrnum].options & OPTION_AMMOONSCREEN) != 0;
}

s32 optionsGetShowGunFunction(s32 mpchrnum)
{
	return (g_PlayerConfigsArray[mpchrnum].options & OPTION_SHOWGUNFUNCTION) != 0;
}

s32 optionsGetAlwaysShowTarget(s32 mpchrnum)
{
	return (g_PlayerConfigsArray[mpchrnum].options & OPTION_ALWAYSSHOWTARGET) != 0;
}

s32 optionsGetShowZoomRange(s32 mpchrnum)
{
	return (g_PlayerConfigsArray[mpchrnum].options & OPTION_SHOWZOOMRANGE) != 0;
}

s32 optionsGetPaintball(s32 mpchrnum)
{
	return (g_PlayerConfigsArray[mpchrnum].options & OPTION_PAINTBALL) != 0;
}

s32 optionsGetShowMissionTime(s32 mpchrnum)
{
	return (g_PlayerConfigsArray[mpchrnum].options & OPTION_SHOWMISSIONTIME) != 0;
}

u8 optionsGetInGameSubtitles(void)
{
	return g_InGameSubtitles;
}

u8 optionsGetCutsceneSubtitles(void)
{
	return g_CutsceneSubtitles;
}

s32 optionsGetHeadRoll(s32 mpchrnum)
{
	return (g_PlayerConfigsArray[mpchrnum].options & OPTION_HEADROLL) != 0;
}

void optionsSetForwardPitch(s32 mpchrnum, bool enable)
{
	if (enable) {
		g_PlayerConfigsArray[mpchrnum].options |= OPTION_FORWARDPITCH;
	} else {
		g_PlayerConfigsArray[mpchrnum].options &= ~OPTION_FORWARDPITCH;
	}
}

void optionsSetAutoAim(s32 mpchrnum, bool enable)
{
	if (enable) {
		g_PlayerConfigsArray[mpchrnum].options |= OPTION_AUTOAIM;
	} else {
		g_PlayerConfigsArray[mpchrnum].options &= ~OPTION_AUTOAIM;
	}
}

void optionsSetLookAhead(s32 mpchrnum, bool enable)
{
	if (enable) {
		g_PlayerConfigsArray[mpchrnum].options |= OPTION_LOOKAHEAD;
	} else {
		g_PlayerConfigsArray[mpchrnum].options &= ~OPTION_LOOKAHEAD;
	}
}

void optionsSetAimControl(s32 mpchrnum, s32 index)
{
	if (index) {
		g_PlayerConfigsArray[mpchrnum].options |= OPTION_AIMCONTROL;
	} else {
		g_PlayerConfigsArray[mpchrnum].options &= ~OPTION_AIMCONTROL;
	}
}

void optionsSetSightOnScreen(s32 mpchrnum, bool enable)
{
	if (enable) {
		g_PlayerConfigsArray[mpchrnum].options |= OPTION_SIGHTONSCREEN;
	} else {
		g_PlayerConfigsArray[mpchrnum].options &= ~OPTION_SIGHTONSCREEN;
	}
}

void optionsSetAmmoOnScreen(s32 mpchrnum, bool enable)
{
	if (enable) {
		g_PlayerConfigsArray[mpchrnum].options |= OPTION_AMMOONSCREEN;
	} else {
		g_PlayerConfigsArray[mpchrnum].options &= ~OPTION_AMMOONSCREEN;
	}
}

void optionsSetShowGunFunction(s32 mpchrnum, bool enable)
{
	if (enable) {
		g_PlayerConfigsArray[mpchrnum].options |= OPTION_SHOWGUNFUNCTION;
	} else {
		g_PlayerConfigsArray[mpchrnum].options &= ~OPTION_SHOWGUNFUNCTION;
	}
}

void optionsSetAlwaysShowTarget(s32 mpchrnum, bool enable)
{
	if (enable) {
		g_PlayerConfigsArray[mpchrnum].options |= OPTION_ALWAYSSHOWTARGET;
	} else {
		g_PlayerConfigsArray[mpchrnum].options &= ~OPTION_ALWAYSSHOWTARGET;
	}
}

void optionsSetShowZoomRange(s32 mpchrnum, bool enable)
{
	if (enable) {
		g_PlayerConfigsArray[mpchrnum].options |= OPTION_SHOWZOOMRANGE;
	} else {
		g_PlayerConfigsArray[mpchrnum].options &= ~OPTION_SHOWZOOMRANGE;
	}
}

void optionsSetPaintball(s32 mpchrnum, bool enable)
{
	if (enable) {
		g_PlayerConfigsArray[mpchrnum].options |= OPTION_PAINTBALL;
	} else {
		g_PlayerConfigsArray[mpchrnum].options &= ~OPTION_PAINTBALL;
	}
}

void optionsSetShowMissionTime(s32 mpchrnum, bool enable)
{
	if (enable) {
		g_PlayerConfigsArray[mpchrnum].options |= OPTION_SHOWMISSIONTIME;
	} else {
		g_PlayerConfigsArray[mpchrnum].options &= ~OPTION_SHOWMISSIONTIME;
	}
}

void optionsSetInGameSubtitles(s32 enable)
{
	g_InGameSubtitles = enable;
}

void optionsSetCutsceneSubtitles(s32 enable)
{
	g_CutsceneSubtitles = enable;
}

void optionsSetHeadRoll(s32 mpchrnum, bool enable)
{
	if (enable) {
		g_PlayerConfigsArray[mpchrnum].options |= OPTION_HEADROLL;
	} else {
		g_PlayerConfigsArray[mpchrnum].options &= ~OPTION_HEADROLL;
	}
}

#if VERSION >= VERSION_JPN_FINAL
GLOBAL_ASM(
glabel optionsGetEffectiveScreenSize
/*  f1523a0:	3c0e8009 */ 	lui	$t6,0x8009
/*  f1523a4:	91ce1160 */ 	lbu	$t6,0x1160($t6)
/*  f1523a8:	24010001 */ 	li	$at,0x1
/*  f1523ac:	3c02800a */ 	lui	$v0,0x800a
/*  f1523b0:	15c10003 */ 	bne	$t6,$at,.JF0f1523c0
/*  f1523b4:	00000000 */ 	nop
/*  f1523b8:	03e00008 */ 	jr	$ra
/*  f1523bc:	00001025 */ 	move	$v0,$zero
.JF0f1523c0:
/*  f1523c0:	8c4220c4 */ 	lw	$v0,0x20c4($v0)
/*  f1523c4:	2401000d */ 	li	$at,0xd
/*  f1523c8:	3c048007 */ 	lui	$a0,0x8007
/*  f1523cc:	14410012 */ 	bne	$v0,$at,.JF0f152418
/*  f1523d0:	24841998 */ 	addiu	$a0,$a0,0x1998
/*  f1523d4:	0000c0c0 */ 	sll	$t8,$zero,0x3
/*  f1523d8:	0300c023 */ 	subu	$t8,$t8,$zero
/*  f1523dc:	0018c140 */ 	sll	$t8,$t8,0x5
/*  f1523e0:	0300c023 */ 	subu	$t8,$t8,$zero
/*  f1523e4:	0018c100 */ 	sll	$t8,$t8,0x4
/*  f1523e8:	3c19800a */ 	lui	$t9,0x800a
/*  f1523ec:	ac800000 */ 	sw	$zero,0x0($a0)
/*  f1523f0:	0338c821 */ 	addu	$t9,$t9,$t8
/*  f1523f4:	8f39ebf8 */ 	lw	$t9,-0x1408($t9)
/*  f1523f8:	3c08800a */ 	lui	$t0,0x800a
/*  f1523fc:	13200006 */ 	beqz	$t9,.JF0f152418
/*  f152400:	00000000 */ 	nop
/*  f152404:	8d08e6c0 */ 	lw	$t0,-0x1940($t0)
/*  f152408:	11000003 */ 	beqz	$t0,.JF0f152418
/*  f15240c:	00000000 */ 	nop
/*  f152410:	03e00008 */ 	jr	$ra
/*  f152414:	00001025 */ 	move	$v0,$zero
.JF0f152418:
/*  f152418:	3c048007 */ 	lui	$a0,0x8007
/*  f15241c:	24841998 */ 	addiu	$a0,$a0,0x1998
/*  f152420:	8c890000 */ 	lw	$t1,0x0($a0)
/*  f152424:	3c03800a */ 	lui	$v1,0x800a
/*  f152428:	3c06800a */ 	lui	$a2,0x800a
/*  f15242c:	000950c0 */ 	sll	$t2,$t1,0x3
/*  f152430:	01495023 */ 	subu	$t2,$t2,$t1
/*  f152434:	000a5080 */ 	sll	$t2,$t2,0x2
/*  f152438:	01495021 */ 	addu	$t2,$t2,$t1
/*  f15243c:	000a50c0 */ 	sll	$t2,$t2,0x3
/*  f152440:	01495023 */ 	subu	$t2,$t2,$t1
/*  f152444:	000a5100 */ 	sll	$t2,$t2,0x4
/*  f152448:	006a1821 */ 	addu	$v1,$v1,$t2
/*  f15244c:	8c63ebf8 */ 	lw	$v1,-0x1408($v1)
/*  f152450:	24c6a630 */ 	addiu	$a2,$a2,-22992
/*  f152454:	50600032 */ 	beqzl	$v1,.JF0f152520
/*  f152458:	8ccf006c */ 	lw	$t7,0x6c($a2)
/*  f15245c:	8c640000 */ 	lw	$a0,0x0($v1)
/*  f152460:	3c0b8007 */ 	lui	$t3,0x8007
/*  f152464:	256b26a8 */ 	addiu	$t3,$t3,0x26a8
/*  f152468:	11640007 */ 	beq	$t3,$a0,.JF0f152488
/*  f15246c:	3c0c8007 */ 	lui	$t4,0x8007
/*  f152470:	258c2654 */ 	addiu	$t4,$t4,0x2654
/*  f152474:	11840004 */ 	beq	$t4,$a0,.JF0f152488
/*  f152478:	3c0d8007 */ 	lui	$t5,0x8007
/*  f15247c:	25ad2600 */ 	addiu	$t5,$t5,0x2600
/*  f152480:	15a40003 */ 	bne	$t5,$a0,.JF0f152490
/*  f152484:	3c0e8007 */ 	lui	$t6,0x8007
.JF0f152488:
/*  f152488:	03e00008 */ 	jr	$ra
/*  f15248c:	00001025 */ 	move	$v0,$zero
.JF0f152490:
/*  f152490:	25ce430c */ 	addiu	$t6,$t6,0x430c
/*  f152494:	11c4001f */ 	beq	$t6,$a0,.JF0f152514
/*  f152498:	3c0f8007 */ 	lui	$t7,0x8007
/*  f15249c:	25ef4428 */ 	addiu	$t7,$t7,0x4428
/*  f1524a0:	11e4001c */ 	beq	$t7,$a0,.JF0f152514
/*  f1524a4:	3c188007 */ 	lui	$t8,0x8007
/*  f1524a8:	27184544 */ 	addiu	$t8,$t8,0x4544
/*  f1524ac:	13040019 */ 	beq	$t8,$a0,.JF0f152514
/*  f1524b0:	3c198007 */ 	lui	$t9,0x8007
/*  f1524b4:	27394660 */ 	addiu	$t9,$t9,0x4660
/*  f1524b8:	13240016 */ 	beq	$t9,$a0,.JF0f152514
/*  f1524bc:	3c088007 */ 	lui	$t0,0x8007
/*  f1524c0:	2508477c */ 	addiu	$t0,$t0,0x477c
/*  f1524c4:	11040013 */ 	beq	$t0,$a0,.JF0f152514
/*  f1524c8:	3c098007 */ 	lui	$t1,0x8007
/*  f1524cc:	2529485c */ 	addiu	$t1,$t1,0x485c
/*  f1524d0:	11240010 */ 	beq	$t1,$a0,.JF0f152514
/*  f1524d4:	3c0a8007 */ 	lui	$t2,0x8007
/*  f1524d8:	254a4950 */ 	addiu	$t2,$t2,0x4950
/*  f1524dc:	1144000d */ 	beq	$t2,$a0,.JF0f152514
/*  f1524e0:	3c0b8007 */ 	lui	$t3,0x8007
/*  f1524e4:	256b1fc4 */ 	addiu	$t3,$t3,0x1fc4
/*  f1524e8:	1164000a */ 	beq	$t3,$a0,.JF0f152514
/*  f1524ec:	3c0c8007 */ 	lui	$t4,0x8007
/*  f1524f0:	258c1f5c */ 	addiu	$t4,$t4,0x1f5c
/*  f1524f4:	11840007 */ 	beq	$t4,$a0,.JF0f152514
/*  f1524f8:	3c0d8007 */ 	lui	$t5,0x8007
/*  f1524fc:	25ad5b90 */ 	addiu	$t5,$t5,0x5b90
/*  f152500:	11a40004 */ 	beq	$t5,$a0,.JF0f152514
/*  f152504:	3c0e8007 */ 	lui	$t6,0x8007
/*  f152508:	25ce5c20 */ 	addiu	$t6,$t6,0x5c20
/*  f15250c:	55c40004 */ 	bnel	$t6,$a0,.JF0f152520
/*  f152510:	8ccf006c */ 	lw	$t7,0x6c($a2)
.JF0f152514:
/*  f152514:	03e00008 */ 	jr	$ra
/*  f152518:	00001025 */ 	move	$v0,$zero
/*  f15251c:	8ccf006c */ 	lw	$t7,0x6c($a2)
.JF0f152520:
/*  f152520:	00001825 */ 	move	$v1,$zero
/*  f152524:	00002025 */ 	move	$a0,$zero
/*  f152528:	11e00003 */ 	beqz	$t7,.JF0f152538
/*  f15252c:	00002825 */ 	move	$a1,$zero
/*  f152530:	10000001 */ 	b	.JF0f152538
/*  f152534:	24030001 */ 	li	$v1,0x1
.JF0f152538:
/*  f152538:	8cd80068 */ 	lw	$t8,0x68($a2)
/*  f15253c:	13000003 */ 	beqz	$t8,.JF0f15254c
/*  f152540:	00000000 */ 	nop
/*  f152544:	10000001 */ 	b	.JF0f15254c
/*  f152548:	24040001 */ 	li	$a0,0x1
.JF0f15254c:
/*  f15254c:	8cd90064 */ 	lw	$t9,0x64($a2)
/*  f152550:	13200003 */ 	beqz	$t9,.JF0f152560
/*  f152554:	00000000 */ 	nop
/*  f152558:	10000001 */ 	b	.JF0f152560
/*  f15255c:	24050001 */ 	li	$a1,0x1
.JF0f152560:
/*  f152560:	8cc80070 */ 	lw	$t0,0x70($a2)
/*  f152564:	00003025 */ 	move	$a2,$zero
/*  f152568:	11000003 */ 	beqz	$t0,.JF0f152578
/*  f15256c:	00000000 */ 	nop
/*  f152570:	10000001 */ 	b	.JF0f152578
/*  f152574:	24060001 */ 	li	$a2,0x1
.JF0f152578:
/*  f152578:	00c54821 */ 	addu	$t1,$a2,$a1
/*  f15257c:	01245021 */ 	addu	$t2,$t1,$a0
/*  f152580:	01435821 */ 	addu	$t3,$t2,$v1
/*  f152584:	29610002 */ 	slti	$at,$t3,0x2
/*  f152588:	10200003 */ 	beqz	$at,.JF0f152598
/*  f15258c:	24010003 */ 	li	$at,0x3
/*  f152590:	14410003 */ 	bne	$v0,$at,.JF0f1525a0
/*  f152594:	00000000 */ 	nop
.JF0f152598:
/*  f152598:	03e00008 */ 	jr	$ra
/*  f15259c:	00001025 */ 	move	$v0,$zero
.JF0f1525a0:
/*  f1525a0:	3c028008 */ 	lui	$v0,0x8008
/*  f1525a4:	8c4200e0 */ 	lw	$v0,0xe0($v0)
/*  f1525a8:	03e00008 */ 	jr	$ra
/*  f1525ac:	00000000 */ 	nop
);
#elif VERSION >= VERSION_NTSC_1_0
s32 optionsGetEffectiveScreenSize(void)
{
	if (IS4MB()) {
		return SCREENSIZE_FULL;
	}

	if (g_MenuData.root == MENUROOT_TRAINING) {
		g_MpPlayerNum = 0;

		if (g_Menus[g_MpPlayerNum].curdialog && var8009dfc0) {
			return SCREENSIZE_FULL;
		}
	}

	if (g_Menus[g_MpPlayerNum].curdialog && (
				g_Menus[g_MpPlayerNum].curdialog->definition == &g_CiControlStylePlayer2MenuDialog ||
				g_Menus[g_MpPlayerNum].curdialog->definition == &g_CiControlStyleMenuDialog ||
				g_Menus[g_MpPlayerNum].curdialog->definition == &g_SoloMissionControlStyleMenuDialog)) {
		return SCREENSIZE_FULL;
	}

	if (PLAYERCOUNT() >= 2 || g_MenuData.root == MENUROOT_MPSETUP) {
		return SCREENSIZE_FULL;
	}

	return g_ScreenSize;
}
#else
GLOBAL_ASM(
glabel optionsGetEffectiveScreenSize
/*  f14d470:	3c0e8009 */ 	lui	$t6,0x8009
/*  f14d474:	91ce30e0 */ 	lbu	$t6,0x30e0($t6)
/*  f14d478:	24010001 */ 	addiu	$at,$zero,0x1
/*  f14d47c:	3c02800a */ 	lui	$v0,0x800a
/*  f14d480:	15c10003 */ 	bne	$t6,$at,.NB0f14d490
/*  f14d484:	00000000 */ 	sll	$zero,$zero,0x0
/*  f14d488:	03e00008 */ 	jr	$ra
/*  f14d48c:	00001025 */ 	or	$v0,$zero,$zero
.NB0f14d490:
/*  f14d490:	8c425eb4 */ 	lw	$v0,0x5eb4($v0)
/*  f14d494:	2401000d */ 	addiu	$at,$zero,0xd
/*  f14d498:	3c048007 */ 	lui	$a0,0x8007
/*  f14d49c:	14410014 */ 	bne	$v0,$at,.NB0f14d4f0
/*  f14d4a0:	24843af0 */ 	addiu	$a0,$a0,0x3af0
/*  f14d4a4:	0000c0c0 */ 	sll	$t8,$zero,0x3
/*  f14d4a8:	0300c023 */ 	subu	$t8,$t8,$zero
/*  f14d4ac:	0018c0c0 */ 	sll	$t8,$t8,0x3
/*  f14d4b0:	0300c023 */ 	subu	$t8,$t8,$zero
/*  f14d4b4:	0018c100 */ 	sll	$t8,$t8,0x4
/*  f14d4b8:	0300c023 */ 	subu	$t8,$t8,$zero
/*  f14d4bc:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f14d4c0:	3c19800a */ 	lui	$t9,0x800a
/*  f14d4c4:	ac800000 */ 	sw	$zero,0x0($a0)
/*  f14d4c8:	0338c821 */ 	addu	$t9,$t9,$t8
/*  f14d4cc:	8f392c48 */ 	lw	$t9,0x2c48($t9)
/*  f14d4d0:	3c08800a */ 	lui	$t0,0x800a
/*  f14d4d4:	13200006 */ 	beqz	$t9,.NB0f14d4f0
/*  f14d4d8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f14d4dc:	8d082780 */ 	lw	$t0,0x2780($t0)
/*  f14d4e0:	11000003 */ 	beqz	$t0,.NB0f14d4f0
/*  f14d4e4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f14d4e8:	03e00008 */ 	jr	$ra
/*  f14d4ec:	00001025 */ 	or	$v0,$zero,$zero
.NB0f14d4f0:
/*  f14d4f0:	3c048007 */ 	lui	$a0,0x8007
/*  f14d4f4:	24843af0 */ 	addiu	$a0,$a0,0x3af0
/*  f14d4f8:	8c890000 */ 	lw	$t1,0x0($a0)
/*  f14d4fc:	3c03800a */ 	lui	$v1,0x800a
/*  f14d500:	3c06800a */ 	lui	$a2,0x800a
/*  f14d504:	000950c0 */ 	sll	$t2,$t1,0x3
/*  f14d508:	01495023 */ 	subu	$t2,$t2,$t1
/*  f14d50c:	000a50c0 */ 	sll	$t2,$t2,0x3
/*  f14d510:	01495023 */ 	subu	$t2,$t2,$t1
/*  f14d514:	000a5100 */ 	sll	$t2,$t2,0x4
/*  f14d518:	01495023 */ 	subu	$t2,$t2,$t1
/*  f14d51c:	000a5080 */ 	sll	$t2,$t2,0x2
/*  f14d520:	006a1821 */ 	addu	$v1,$v1,$t2
/*  f14d524:	8c632c48 */ 	lw	$v1,0x2c48($v1)
/*  f14d528:	24c6e6c0 */ 	addiu	$a2,$a2,-6464
/*  f14d52c:	5060000f */ 	beqzl	$v1,.NB0f14d56c
/*  f14d530:	8cce006c */ 	lw	$t6,0x6c($a2)
/*  f14d534:	8c640000 */ 	lw	$a0,0x0($v1)
/*  f14d538:	3c0b8007 */ 	lui	$t3,0x8007
/*  f14d53c:	256b4704 */ 	addiu	$t3,$t3,0x4704
/*  f14d540:	11640007 */ 	beq	$t3,$a0,.NB0f14d560
/*  f14d544:	3c0c8007 */ 	lui	$t4,0x8007
/*  f14d548:	258c46b0 */ 	addiu	$t4,$t4,0x46b0
/*  f14d54c:	11840004 */ 	beq	$t4,$a0,.NB0f14d560
/*  f14d550:	3c0d8007 */ 	lui	$t5,0x8007
/*  f14d554:	25ad465c */ 	addiu	$t5,$t5,0x465c
/*  f14d558:	55a40004 */ 	bnel	$t5,$a0,.NB0f14d56c
/*  f14d55c:	8cce006c */ 	lw	$t6,0x6c($a2)
.NB0f14d560:
/*  f14d560:	03e00008 */ 	jr	$ra
/*  f14d564:	00001025 */ 	or	$v0,$zero,$zero
/*  f14d568:	8cce006c */ 	lw	$t6,0x6c($a2)
.NB0f14d56c:
/*  f14d56c:	00001825 */ 	or	$v1,$zero,$zero
/*  f14d570:	00002025 */ 	or	$a0,$zero,$zero
/*  f14d574:	11c00003 */ 	beqz	$t6,.NB0f14d584
/*  f14d578:	00002825 */ 	or	$a1,$zero,$zero
/*  f14d57c:	10000001 */ 	beqz	$zero,.NB0f14d584
/*  f14d580:	24030001 */ 	addiu	$v1,$zero,0x1
.NB0f14d584:
/*  f14d584:	8ccf0068 */ 	lw	$t7,0x68($a2)
/*  f14d588:	11e00003 */ 	beqz	$t7,.NB0f14d598
/*  f14d58c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f14d590:	10000001 */ 	beqz	$zero,.NB0f14d598
/*  f14d594:	24040001 */ 	addiu	$a0,$zero,0x1
.NB0f14d598:
/*  f14d598:	8cd80064 */ 	lw	$t8,0x64($a2)
/*  f14d59c:	13000003 */ 	beqz	$t8,.NB0f14d5ac
/*  f14d5a0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f14d5a4:	10000001 */ 	beqz	$zero,.NB0f14d5ac
/*  f14d5a8:	24050001 */ 	addiu	$a1,$zero,0x1
.NB0f14d5ac:
/*  f14d5ac:	8cd90070 */ 	lw	$t9,0x70($a2)
/*  f14d5b0:	00003025 */ 	or	$a2,$zero,$zero
/*  f14d5b4:	13200003 */ 	beqz	$t9,.NB0f14d5c4
/*  f14d5b8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f14d5bc:	10000001 */ 	beqz	$zero,.NB0f14d5c4
/*  f14d5c0:	24060001 */ 	addiu	$a2,$zero,0x1
.NB0f14d5c4:
/*  f14d5c4:	00c54021 */ 	addu	$t0,$a2,$a1
/*  f14d5c8:	01044821 */ 	addu	$t1,$t0,$a0
/*  f14d5cc:	01235021 */ 	addu	$t2,$t1,$v1
/*  f14d5d0:	29410002 */ 	slti	$at,$t2,0x2
/*  f14d5d4:	10200003 */ 	beqz	$at,.NB0f14d5e4
/*  f14d5d8:	24010003 */ 	addiu	$at,$zero,0x3
/*  f14d5dc:	14410003 */ 	bne	$v0,$at,.NB0f14d5ec
/*  f14d5e0:	00000000 */ 	sll	$zero,$zero,0x0
.NB0f14d5e4:
/*  f14d5e4:	03e00008 */ 	jr	$ra
/*  f14d5e8:	00001025 */ 	or	$v0,$zero,$zero
.NB0f14d5ec:
/*  f14d5ec:	3c028008 */ 	lui	$v0,0x8008
/*  f14d5f0:	8c422310 */ 	lw	$v0,0x2310($v0)
/*  f14d5f4:	03e00008 */ 	jr	$ra
/*  f14d5f8:	00000000 */ 	sll	$zero,$zero,0x0
);
#endif

#if VERSION >= VERSION_NTSC_1_0
s32 optionsGetScreenSize(void)
{
	return g_ScreenSize;
}
#endif

void optionsSetScreenSize(s32 size)
{
	g_ScreenSize = size;
}

s32 optionsGetScreenRatio(void)
{
	return g_ScreenRatio;
}

void optionsSetScreenRatio(s32 ratio)
{
	g_ScreenRatio = ratio;
}

u8 optionsGetScreenSplit(void)
{
	return g_ScreenSplit;
}

void optionsSetScreenSplit(u8 split)
{
	g_ScreenSplit = split;
}

u16 optionsGetMusicVolume(void)
{
#if VERSION >= VERSION_NTSC_1_0
	return musicGetVolume();
#else
	if (g_Vars.stagenum == STAGE_CREDITS) {
		return 0x7fff;
	}

	return var8008231cnb;
#endif
}

void optionsSetMusicVolume(u16 volume)
{
#if VERSION >= VERSION_NTSC_1_0
	musicSetVolume(volume);
#else
	var8008231cnb = volume;
	musicSetVolume(var8008231cnb);
#endif
}
