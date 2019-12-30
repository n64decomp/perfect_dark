#include <ultra64.h>
#include "constants.h"
#include "gvars/gvars.h"
#include "setup/setup_000000.h"
#include "setup/setup_0160b0.h"
#include "setup/setup_020df0.h"
#include "types.h"
#include "game/game_16cfa0.h"

GLOBAL_ASM(
glabel optionsGetControlMode
/*  f152710:	00047080 */ 	sll	$t6,$a0,0x2
/*  f152714:	01c47021 */ 	addu	$t6,$t6,$a0
/*  f152718:	000e7140 */ 	sll	$t6,$t6,0x5
/*  f15271c:	3c02800b */ 	lui	$v0,0x800b
/*  f152720:	004e1021 */ 	addu	$v0,$v0,$t6
/*  f152724:	03e00008 */ 	jr	$ra
/*  f152728:	9042c7fc */ 	lbu	$v0,-0x3804($v0)
);

GLOBAL_ASM(
glabel optionsSetControlMode
/*  f15272c:	00047080 */ 	sll	$t6,$a0,0x2
/*  f152730:	01c47021 */ 	addu	$t6,$t6,$a0
/*  f152734:	000e7140 */ 	sll	$t6,$t6,0x5
/*  f152738:	3c01800b */ 	lui	$at,0x800b
/*  f15273c:	002e0821 */ 	addu	$at,$at,$t6
/*  f152740:	03e00008 */ 	jr	$ra
/*  f152744:	a025c7fc */ 	sb	$a1,-0x3804($at)
);

GLOBAL_ASM(
glabel func0f152748
/*  f152748:	00047080 */ 	sll	$t6,$a0,0x2
/*  f15274c:	01c47021 */ 	addu	$t6,$t6,$a0
/*  f152750:	000e7140 */ 	sll	$t6,$t6,0x5
/*  f152754:	3c02800b */ 	lui	$v0,0x800b
/*  f152758:	004e1021 */ 	addu	$v0,$v0,$t6
/*  f15275c:	03e00008 */ 	jr	$ra
/*  f152760:	8042c7fd */ 	lb	$v0,-0x3803($v0)
);

GLOBAL_ASM(
glabel func0f152764
/*  f152764:	00047080 */ 	sll	$t6,$a0,0x2
/*  f152768:	01c47021 */ 	addu	$t6,$t6,$a0
/*  f15276c:	000e7140 */ 	sll	$t6,$t6,0x5
/*  f152770:	3c02800b */ 	lui	$v0,0x800b
/*  f152774:	004e1021 */ 	addu	$v0,$v0,$t6
/*  f152778:	03e00008 */ 	jr	$ra
/*  f15277c:	8042c7fe */ 	lb	$v0,-0x3802($v0)
);

s32 optionsGetForwardPitch(s32 optionsindex)
{
	return (g_Options[optionsindex].unk48 & OPTION_FORWARDPITCH) != 0;
}

s32 optionsGetAutoAim(s32 optionsindex)
{
	return (g_Options[optionsindex].unk48 & OPTION_AUTOAIM) != 0;
}

s32 optionsGetLookAhead(s32 optionsindex)
{
	return (g_Options[optionsindex].unk48 & OPTION_LOOKAHEAD) != 0;
}

s32 optionsGetAimControl(s32 optionsindex)
{
	return (g_Options[optionsindex].unk48 & OPTION_AIMCONTROL) != 0;
}

s32 optionsGetSightOnScreen(s32 optionsindex)
{
	return (g_Options[optionsindex].unk48 & OPTION_SIGHTONSCREEN) != 0;
}

s32 optionsGetAmmoOnScreen(s32 optionsindex)
{
	return (g_Options[optionsindex].unk48 & OPTION_AMMOONSCREEN) != 0;
}

s32 optionsGetShowGunFunction(s32 optionsindex)
{
	return (g_Options[optionsindex].unk48 & OPTION_SHOWGUNFUNCTION) != 0;
}

s32 optionsGetAlwaysShowTarget(s32 optionsindex)
{
	return (g_Options[optionsindex].unk48 & OPTION_ALWAYSSHOWTARGET) != 0;
}

s32 optionsGetShowZoomRange(s32 optionsindex)
{
	return (g_Options[optionsindex].unk48 & OPTION_SHOWZOOMRANGE) != 0;
}

s32 optionsGetPaintball(s32 optionsindex)
{
	return (g_Options[optionsindex].unk48 & OPTION_PAINTBALL) != 0;
}

s32 optionsGetShowMissionTime(s32 optionsindex)
{
	return (g_Options[optionsindex].unk48 & OPTION_SHOWMISSIONTIME) != 0;
}

u8 optionsGetInGameSubtitles(void)
{
	return g_InGameSubtitles;
}

u8 optionsGetCutsceneSubtitles(void)
{
	return g_CutsceneSubtitles;
}

s32 optionsGetHeadRoll(s32 optionsindex)
{
	return (g_Options[optionsindex].unk48 & OPTION_HEADROLL) != 0;
}

void optionsSetForwardPitch(s32 optionsindex, bool enable)
{
	if (enable) {
		g_Options[optionsindex].unk48 |= OPTION_FORWARDPITCH;
	} else {
		g_Options[optionsindex].unk48 &= ~OPTION_FORWARDPITCH;
	}
}

void optionsSetAutoAim(s32 optionsindex, bool enable)
{
	if (enable) {
		g_Options[optionsindex].unk48 |= OPTION_AUTOAIM;
	} else {
		g_Options[optionsindex].unk48 &= ~OPTION_AUTOAIM;
	}
}

void optionsSetLookAhead(s32 optionsindex, bool enable)
{
	if (enable) {
		g_Options[optionsindex].unk48 |= OPTION_LOOKAHEAD;
	} else {
		g_Options[optionsindex].unk48 &= ~OPTION_LOOKAHEAD;
	}
}

void optionsSetAimControl(s32 optionsindex, s32 index)
{
	if (index) {
		g_Options[optionsindex].unk48 |= OPTION_AIMCONTROL;
	} else {
		g_Options[optionsindex].unk48 &= ~OPTION_AIMCONTROL;
	}
}

void optionsSetSightOnScreen(s32 optionsindex, bool enable)
{
	if (enable) {
		g_Options[optionsindex].unk48 |= OPTION_SIGHTONSCREEN;
	} else {
		g_Options[optionsindex].unk48 &= ~OPTION_SIGHTONSCREEN;
	}
}

void optionsSetAmmoOnScreen(s32 optionsindex, bool enable)
{
	if (enable) {
		g_Options[optionsindex].unk48 |= OPTION_AMMOONSCREEN;
	} else {
		g_Options[optionsindex].unk48 &= ~OPTION_AMMOONSCREEN;
	}
}

void optionsSetShowGunFunction(s32 optionsindex, bool enable)
{
	if (enable) {
		g_Options[optionsindex].unk48 |= OPTION_SHOWGUNFUNCTION;
	} else {
		g_Options[optionsindex].unk48 &= ~OPTION_SHOWGUNFUNCTION;
	}
}

void optionsSetAlwaysShowTarget(s32 optionsindex, bool enable)
{
	if (enable) {
		g_Options[optionsindex].unk48 |= OPTION_ALWAYSSHOWTARGET;
	} else {
		g_Options[optionsindex].unk48 &= ~OPTION_ALWAYSSHOWTARGET;
	}
}

void optionsSetShowZoomRange(s32 optionsindex, bool enable)
{
	if (enable) {
		g_Options[optionsindex].unk48 |= OPTION_SHOWZOOMRANGE;
	} else {
		g_Options[optionsindex].unk48 &= ~OPTION_SHOWZOOMRANGE;
	}
}

void optionsSetPaintball(s32 optionsindex, bool enable)
{
	if (enable) {
		g_Options[optionsindex].unk48 |= OPTION_PAINTBALL;
	} else {
		g_Options[optionsindex].unk48 &= ~OPTION_PAINTBALL;
	}
}

void optionsSetShowMissionTime(s32 optionsindex, bool enable)
{
	if (enable) {
		g_Options[optionsindex].unk48 |= OPTION_SHOWMISSIONTIME;
	} else {
		g_Options[optionsindex].unk48 &= ~OPTION_SHOWMISSIONTIME;
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

void optionsSetHeadRoll(s32 optionsindex, bool enable)
{
	if (enable) {
		g_Options[optionsindex].unk48 |= OPTION_HEADROLL;
	} else {
		g_Options[optionsindex].unk48 &= ~OPTION_HEADROLL;
	}
}

GLOBAL_ASM(
glabel func0f152d80
/*  f152d80:	3c0e8009 */ 	lui	$t6,0x8009
/*  f152d84:	91ce0af0 */ 	lbu	$t6,0xaf0($t6)
/*  f152d88:	24010001 */ 	addiu	$at,$zero,0x1
/*  f152d8c:	3c02800a */ 	lui	$v0,0x800a
/*  f152d90:	15c10003 */ 	bne	$t6,$at,.L0f152da0
/*  f152d94:	00000000 */ 	sll	$zero,$zero,0x0
/*  f152d98:	03e00008 */ 	jr	$ra
/*  f152d9c:	00001025 */ 	or	$v0,$zero,$zero
.L0f152da0:
/*  f152da0:	8c4219c4 */ 	lw	$v0,0x19c4($v0)
/*  f152da4:	2401000d */ 	addiu	$at,$zero,0xd
/*  f152da8:	3c048007 */ 	lui	$a0,%hi(g_MenuStackDepth)
/*  f152dac:	14410012 */ 	bne	$v0,$at,.L0f152df8
/*  f152db0:	24841448 */ 	addiu	$a0,$a0,%lo(g_MenuStackDepth)
/*  f152db4:	0000c0c0 */ 	sll	$t8,$zero,0x3
/*  f152db8:	0300c023 */ 	subu	$t8,$t8,$zero
/*  f152dbc:	0018c140 */ 	sll	$t8,$t8,0x5
/*  f152dc0:	0300c023 */ 	subu	$t8,$t8,$zero
/*  f152dc4:	0018c100 */ 	sll	$t8,$t8,0x4
/*  f152dc8:	3c19800a */ 	lui	$t9,0x800a
/*  f152dcc:	ac800000 */ 	sw	$zero,0x0($a0)
/*  f152dd0:	0338c821 */ 	addu	$t9,$t9,$t8
/*  f152dd4:	8f39e4f8 */ 	lw	$t9,-0x1b08($t9)
/*  f152dd8:	3c08800a */ 	lui	$t0,0x800a
/*  f152ddc:	13200006 */ 	beqz	$t9,.L0f152df8
/*  f152de0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f152de4:	8d08dfc0 */ 	lw	$t0,-0x2040($t0)
/*  f152de8:	11000003 */ 	beqz	$t0,.L0f152df8
/*  f152dec:	00000000 */ 	sll	$zero,$zero,0x0
/*  f152df0:	03e00008 */ 	jr	$ra
/*  f152df4:	00001025 */ 	or	$v0,$zero,$zero
.L0f152df8:
/*  f152df8:	3c048007 */ 	lui	$a0,%hi(g_MenuStackDepth)
/*  f152dfc:	24841448 */ 	addiu	$a0,$a0,%lo(g_MenuStackDepth)
/*  f152e00:	8c890000 */ 	lw	$t1,0x0($a0)
/*  f152e04:	3c03800a */ 	lui	$v1,0x800a
/*  f152e08:	3c06800a */ 	lui	$a2,%hi(g_Vars)
/*  f152e0c:	000950c0 */ 	sll	$t2,$t1,0x3
/*  f152e10:	01495023 */ 	subu	$t2,$t2,$t1
/*  f152e14:	000a5080 */ 	sll	$t2,$t2,0x2
/*  f152e18:	01495021 */ 	addu	$t2,$t2,$t1
/*  f152e1c:	000a50c0 */ 	sll	$t2,$t2,0x3
/*  f152e20:	01495023 */ 	subu	$t2,$t2,$t1
/*  f152e24:	000a5100 */ 	sll	$t2,$t2,0x4
/*  f152e28:	006a1821 */ 	addu	$v1,$v1,$t2
/*  f152e2c:	8c63e4f8 */ 	lw	$v1,-0x1b08($v1)
/*  f152e30:	24c69fc0 */ 	addiu	$a2,$a2,%lo(g_Vars)
/*  f152e34:	5060000f */ 	beqzl	$v1,.L0f152e74
/*  f152e38:	8cce006c */ 	lw	$t6,0x6c($a2)
/*  f152e3c:	8c640000 */ 	lw	$a0,0x0($v1)
/*  f152e40:	3c0b8007 */ 	lui	$t3,%hi(menudialog_control4)
/*  f152e44:	256b2174 */ 	addiu	$t3,$t3,%lo(menudialog_control4)
/*  f152e48:	11640007 */ 	beq	$t3,$a0,.L0f152e68
/*  f152e4c:	3c0c8007 */ 	lui	$t4,%hi(menudialog_control3)
/*  f152e50:	258c2120 */ 	addiu	$t4,$t4,%lo(menudialog_control3)
/*  f152e54:	11840004 */ 	beq	$t4,$a0,.L0f152e68
/*  f152e58:	3c0d8007 */ 	lui	$t5,%hi(menudialog_control2)
/*  f152e5c:	25ad20cc */ 	addiu	$t5,$t5,%lo(menudialog_control2)
/*  f152e60:	55a40004 */ 	bnel	$t5,$a0,.L0f152e74
/*  f152e64:	8cce006c */ 	lw	$t6,0x6c($a2)
.L0f152e68:
/*  f152e68:	03e00008 */ 	jr	$ra
/*  f152e6c:	00001025 */ 	or	$v0,$zero,$zero
/*  f152e70:	8cce006c */ 	lw	$t6,0x6c($a2)
.L0f152e74:
/*  f152e74:	00001825 */ 	or	$v1,$zero,$zero
/*  f152e78:	00002025 */ 	or	$a0,$zero,$zero
/*  f152e7c:	11c00003 */ 	beqz	$t6,.L0f152e8c
/*  f152e80:	00002825 */ 	or	$a1,$zero,$zero
/*  f152e84:	10000001 */ 	beqz	$zero,.L0f152e8c
/*  f152e88:	24030001 */ 	addiu	$v1,$zero,0x1
.L0f152e8c:
/*  f152e8c:	8ccf0068 */ 	lw	$t7,0x68($a2)
/*  f152e90:	11e00003 */ 	beqz	$t7,.L0f152ea0
/*  f152e94:	00000000 */ 	sll	$zero,$zero,0x0
/*  f152e98:	10000001 */ 	beqz	$zero,.L0f152ea0
/*  f152e9c:	24040001 */ 	addiu	$a0,$zero,0x1
.L0f152ea0:
/*  f152ea0:	8cd80064 */ 	lw	$t8,0x64($a2)
/*  f152ea4:	13000003 */ 	beqz	$t8,.L0f152eb4
/*  f152ea8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f152eac:	10000001 */ 	beqz	$zero,.L0f152eb4
/*  f152eb0:	24050001 */ 	addiu	$a1,$zero,0x1
.L0f152eb4:
/*  f152eb4:	8cd90070 */ 	lw	$t9,0x70($a2)
/*  f152eb8:	00003025 */ 	or	$a2,$zero,$zero
/*  f152ebc:	13200003 */ 	beqz	$t9,.L0f152ecc
/*  f152ec0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f152ec4:	10000001 */ 	beqz	$zero,.L0f152ecc
/*  f152ec8:	24060001 */ 	addiu	$a2,$zero,0x1
.L0f152ecc:
/*  f152ecc:	00c54021 */ 	addu	$t0,$a2,$a1
/*  f152ed0:	01044821 */ 	addu	$t1,$t0,$a0
/*  f152ed4:	01235021 */ 	addu	$t2,$t1,$v1
/*  f152ed8:	29410002 */ 	slti	$at,$t2,0x2
/*  f152edc:	10200003 */ 	beqz	$at,.L0f152eec
/*  f152ee0:	24010003 */ 	addiu	$at,$zero,0x3
/*  f152ee4:	14410003 */ 	bne	$v0,$at,.L0f152ef4
/*  f152ee8:	00000000 */ 	sll	$zero,$zero,0x0
.L0f152eec:
/*  f152eec:	03e00008 */ 	jr	$ra
/*  f152ef0:	00001025 */ 	or	$v0,$zero,$zero
.L0f152ef4:
/*  f152ef4:	3c028008 */ 	lui	$v0,0x8008
/*  f152ef8:	8c42fab0 */ 	lw	$v0,-0x550($v0)
/*  f152efc:	03e00008 */ 	jr	$ra
/*  f152f00:	00000000 */ 	sll	$zero,$zero,0x0
);

s32 optionsGetScreenSize(void)
{
	return g_ScreenSize;
}

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

s32 optionsGetMusicVolume(void)
{
	return func0f16cfa0();
}

void optionsSetMusicVolume(u16 volume)
{
	func0f16cfe8(volume);
}
