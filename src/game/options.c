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

s32 optionsGetControlMode(s32 mpchrnum)
{
	return g_MpPlayers[mpchrnum].base.controlmode;
}

void optionsSetControlMode(s32 mpchrnum, s32 mode)
{
	g_MpPlayers[mpchrnum].base.controlmode = mode;
}

s32 optionsGetContpadNum1(s32 mpchrnum)
{
	return g_MpPlayers[mpchrnum].base.contpad1;
}

s32 optionsGetContpadNum2(s32 mpchrnum)
{
	return g_MpPlayers[mpchrnum].base.contpad2;
}

s32 optionsGetForwardPitch(s32 mpchrnum)
{
	return (g_MpPlayers[mpchrnum].options & OPTION_FORWARDPITCH) != 0;
}

s32 optionsGetAutoAim(s32 mpchrnum)
{
	return (g_MpPlayers[mpchrnum].options & OPTION_AUTOAIM) != 0;
}

s32 optionsGetLookAhead(s32 mpchrnum)
{
	return (g_MpPlayers[mpchrnum].options & OPTION_LOOKAHEAD) != 0;
}

s32 optionsGetAimControl(s32 mpchrnum)
{
	return (g_MpPlayers[mpchrnum].options & OPTION_AIMCONTROL) != 0;
}

s32 optionsGetSightOnScreen(s32 mpchrnum)
{
	return (g_MpPlayers[mpchrnum].options & OPTION_SIGHTONSCREEN) != 0;
}

s32 optionsGetAmmoOnScreen(s32 mpchrnum)
{
	return (g_MpPlayers[mpchrnum].options & OPTION_AMMOONSCREEN) != 0;
}

s32 optionsGetShowGunFunction(s32 mpchrnum)
{
	return (g_MpPlayers[mpchrnum].options & OPTION_SHOWGUNFUNCTION) != 0;
}

s32 optionsGetAlwaysShowTarget(s32 mpchrnum)
{
	return (g_MpPlayers[mpchrnum].options & OPTION_ALWAYSSHOWTARGET) != 0;
}

s32 optionsGetShowZoomRange(s32 mpchrnum)
{
	return (g_MpPlayers[mpchrnum].options & OPTION_SHOWZOOMRANGE) != 0;
}

s32 optionsGetPaintball(s32 mpchrnum)
{
	return (g_MpPlayers[mpchrnum].options & OPTION_PAINTBALL) != 0;
}

s32 optionsGetShowMissionTime(s32 mpchrnum)
{
	return (g_MpPlayers[mpchrnum].options & OPTION_SHOWMISSIONTIME) != 0;
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
	return (g_MpPlayers[mpchrnum].options & OPTION_HEADROLL) != 0;
}

void optionsSetForwardPitch(s32 mpchrnum, bool enable)
{
	if (enable) {
		g_MpPlayers[mpchrnum].options |= OPTION_FORWARDPITCH;
	} else {
		g_MpPlayers[mpchrnum].options &= ~OPTION_FORWARDPITCH;
	}
}

void optionsSetAutoAim(s32 mpchrnum, bool enable)
{
	if (enable) {
		g_MpPlayers[mpchrnum].options |= OPTION_AUTOAIM;
	} else {
		g_MpPlayers[mpchrnum].options &= ~OPTION_AUTOAIM;
	}
}

void optionsSetLookAhead(s32 mpchrnum, bool enable)
{
	if (enable) {
		g_MpPlayers[mpchrnum].options |= OPTION_LOOKAHEAD;
	} else {
		g_MpPlayers[mpchrnum].options &= ~OPTION_LOOKAHEAD;
	}
}

void optionsSetAimControl(s32 mpchrnum, s32 index)
{
	if (index) {
		g_MpPlayers[mpchrnum].options |= OPTION_AIMCONTROL;
	} else {
		g_MpPlayers[mpchrnum].options &= ~OPTION_AIMCONTROL;
	}
}

void optionsSetSightOnScreen(s32 mpchrnum, bool enable)
{
	if (enable) {
		g_MpPlayers[mpchrnum].options |= OPTION_SIGHTONSCREEN;
	} else {
		g_MpPlayers[mpchrnum].options &= ~OPTION_SIGHTONSCREEN;
	}
}

void optionsSetAmmoOnScreen(s32 mpchrnum, bool enable)
{
	if (enable) {
		g_MpPlayers[mpchrnum].options |= OPTION_AMMOONSCREEN;
	} else {
		g_MpPlayers[mpchrnum].options &= ~OPTION_AMMOONSCREEN;
	}
}

void optionsSetShowGunFunction(s32 mpchrnum, bool enable)
{
	if (enable) {
		g_MpPlayers[mpchrnum].options |= OPTION_SHOWGUNFUNCTION;
	} else {
		g_MpPlayers[mpchrnum].options &= ~OPTION_SHOWGUNFUNCTION;
	}
}

void optionsSetAlwaysShowTarget(s32 mpchrnum, bool enable)
{
	if (enable) {
		g_MpPlayers[mpchrnum].options |= OPTION_ALWAYSSHOWTARGET;
	} else {
		g_MpPlayers[mpchrnum].options &= ~OPTION_ALWAYSSHOWTARGET;
	}
}

void optionsSetShowZoomRange(s32 mpchrnum, bool enable)
{
	if (enable) {
		g_MpPlayers[mpchrnum].options |= OPTION_SHOWZOOMRANGE;
	} else {
		g_MpPlayers[mpchrnum].options &= ~OPTION_SHOWZOOMRANGE;
	}
}

void optionsSetPaintball(s32 mpchrnum, bool enable)
{
	if (enable) {
		g_MpPlayers[mpchrnum].options |= OPTION_PAINTBALL;
	} else {
		g_MpPlayers[mpchrnum].options &= ~OPTION_PAINTBALL;
	}
}

void optionsSetShowMissionTime(s32 mpchrnum, bool enable)
{
	if (enable) {
		g_MpPlayers[mpchrnum].options |= OPTION_SHOWMISSIONTIME;
	} else {
		g_MpPlayers[mpchrnum].options &= ~OPTION_SHOWMISSIONTIME;
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
		g_MpPlayers[mpchrnum].options |= OPTION_HEADROLL;
	} else {
		g_MpPlayers[mpchrnum].options &= ~OPTION_HEADROLL;
	}
}

#if VERSION >= VERSION_NTSC_1_0
s32 optionsGetEffectiveScreenSize(void)
{
	if (IS4MB()) {
		return SCREENSIZE_FULL;
	}

	if (g_MenuData.root == MENUROOT_TRAINING) {
		g_MpPlayerNum = 0;

		if (g_Menus[g_MpPlayerNum].curframe && var8009dfc0) {
			return SCREENSIZE_FULL;
		}
	}

	if (g_Menus[g_MpPlayerNum].curframe && (
				g_Menus[g_MpPlayerNum].curframe->dialog == &g_CiControlStylePlayer2MenuDialog ||
				g_Menus[g_MpPlayerNum].curframe->dialog == &g_CiControlStyleMenuDialog ||
				g_Menus[g_MpPlayerNum].curframe->dialog == &g_SoloMissionControlStyleMenuDialog)) {
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

#if VERSION >= VERSION_NTSC_1_0
u16 optionsGetMusicVolume(void)
{
	return musicGetVolume();
}
#else
GLOBAL_ASM(
glabel optionsGetMusicVolume
/*  f14d63c:	3c0e800a */ 	lui	$t6,0x800a
/*  f14d640:	8dceeb74 */ 	lw	$t6,-0x148c($t6)
/*  f14d644:	2401005c */ 	addiu	$at,$zero,0x5c
/*  f14d648:	3c028008 */ 	lui	$v0,0x8008
/*  f14d64c:	15c10003 */ 	bne	$t6,$at,.NB0f14d65c
/*  f14d650:	00000000 */ 	sll	$zero,$zero,0x0
/*  f14d654:	03e00008 */ 	jr	$ra
/*  f14d658:	24027fff */ 	addiu	$v0,$zero,0x7fff
.NB0f14d65c:
/*  f14d65c:	9442231c */ 	lhu	$v0,0x231c($v0)
/*  f14d660:	03e00008 */ 	jr	$ra
/*  f14d664:	00000000 */ 	sll	$zero,$zero,0x0
);
#endif

#if VERSION >= VERSION_NTSC_1_0
void optionsSetMusicVolume(u16 volume)
{
	musicSetVolume(volume);
}
#else
GLOBAL_ASM(
glabel optionsSetMusicVolume
/*  f14d668:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f14d66c:	3c028008 */ 	lui	$v0,0x8008
/*  f14d670:	2442231c */ 	addiu	$v0,$v0,0x231c
/*  f14d674:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f14d678:	afa40018 */ 	sw	$a0,0x18($sp)
/*  f14d67c:	00802825 */ 	or	$a1,$a0,$zero
/*  f14d680:	a4450000 */ 	sh	$a1,0x0($v0)
/*  f14d684:	0fc59f5c */ 	jal	0xf167d70
/*  f14d688:	30a4ffff */ 	andi	$a0,$a1,0xffff
/*  f14d68c:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f14d690:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f14d694:	03e00008 */ 	jr	$ra
/*  f14d698:	00000000 */ 	sll	$zero,$zero,0x0
);
#endif
