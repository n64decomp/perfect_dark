#include <ultra64.h>
#include "constants.h"
#include "game/bondbike.h"
#include "game/bondgrab.h"
#include "game/bondmove.h"
#include "game/bondwalk.h"
#include "game/cheats.h"
#include "game/chr/chraction.h"
#include "game/game_006900.h"
#include "game/chr/chr.h"
#include "game/prop.h"
#include "game/atan2f.h"
#include "game/game_096ca0.h"
#include "game/bondgun.h"
#include "game/game_0b0fd0.h"
#include "game/game_0b3350.h"
#include "game/game_0b69d0.h"
#include "game/bondcutscene.h"
#include "game/bondhead.h"
#include "game/game_127910.h"
#include "game/bg.h"
#include "game/lv.h"
#include "game/mplayer/ingame.h"
#include "game/mplayer/mplayer.h"
#include "game/options.h"
#include "game/propobj.h"
#include "bss.h"
#include "lib/lib_09a80.h"
#include "lib/lib_24e40.h"
#include "lib/snd.h"
#include "lib/rng.h"
#include "lib/lib_159b0.h"
#include "lib/lib_16110.h"
#include "lib/lib_233c0.h"
#include "data.h"
#include "types.h"

void bmoveSetControlDef(u32 controldef)
{
	g_Vars.currentplayer->controldef = controldef;
}

void bmoveSetAutoMoveCentreEnabled(bool enabled)
{
	g_Vars.currentplayer->automovecentreenabled = enabled;
}

bool bmoveIsAutoMoveCentreEnabled(void)
{
	return g_Vars.currentplayer->automovecentreenabled;
}

void bmoveSetAutoAimY(bool enabled)
{
	g_Vars.currentplayer->autoyaimenabled = enabled;
}

bool bmoveIsAutoAimYEnabled(void)
{
	if (!g_Vars.normmplayerisrunning) {
		return g_Vars.currentplayer->autoyaimenabled;
	}

	if (g_MpSetup.options & MPOPTION_NOAUTOAIM) {
		return false;
	}

	return optionsGetAutoAim(g_Vars.currentplayerstats->mpindex);
}

bool bmoveIsAutoAimYEnabledForCurrentWeapon(void)
{
	struct weaponfunc *func = currentPlayerGetWeaponFunction(0);

	if (func) {
		if (func->flags & FUNCFLAG_NOAUTOAIM) {
			return false;
		}

		if ((func->type & 0xff) == INVENTORYFUNCTYPE_CLOSE) {
			return true;
		}
	}

	return bmoveIsAutoAimYEnabled();
}

bool bmoveIsInSightAimMode(void)
{
	return g_Vars.currentplayer->insightaimmode;
}

void bmoveUpdateAutoAimYProp(struct prop *prop, f32 autoaimy)
{
	if (g_Vars.currentplayer->autoyaimtime60 >= 0) {
		g_Vars.currentplayer->autoyaimtime60 -= g_Vars.lvupdate240_60;
	}

	if (prop != g_Vars.currentplayer->autoyaimprop) {
		if (g_Vars.currentplayer->autoyaimtime60 < 0) {
			g_Vars.currentplayer->autoyaimtime60 = PALDOWN(30);
			g_Vars.currentplayer->autoyaimprop = prop;
		} else {
			return;
		}
	}

	g_Vars.currentplayer->autoaimy = autoaimy;
}

void bmoveSetAutoAimX(bool enabled)
{
	g_Vars.currentplayer->autoxaimenabled = enabled;
}

bool bmoveIsAutoAimXEnabled(void)
{
	if (!g_Vars.normmplayerisrunning) {
		return g_Vars.currentplayer->autoxaimenabled;
	}

	if (g_MpSetup.options & MPOPTION_NOAUTOAIM) {
		return false;
	}

	return optionsGetAutoAim(g_Vars.currentplayerstats->mpindex);
}

bool bmoveIsAutoAimXEnabledForCurrentWeapon(void)
{
	struct weaponfunc *func = currentPlayerGetWeaponFunction(0);

	if (func) {
		if (func->flags & FUNCFLAG_NOAUTOAIM) {
			return false;
		}

		if ((func->type & 0xff) == INVENTORYFUNCTYPE_CLOSE) {
			return true;
		}
	}

	return bmoveIsAutoAimXEnabled();
}

void bmoveUpdateAutoAimXProp(struct prop *prop, f32 autoaimx)
{
	if (g_Vars.currentplayer->autoxaimtime60 >= 0) {
		g_Vars.currentplayer->autoxaimtime60 -= g_Vars.lvupdate240_60;
	}

	if (prop != g_Vars.currentplayer->autoxaimprop) {
		if (g_Vars.currentplayer->autoxaimtime60 < 0) {
			g_Vars.currentplayer->autoxaimtime60 = PALDOWN(30);
			g_Vars.currentplayer->autoxaimprop = prop;
		} else {
			return;
		}
	}

	g_Vars.currentplayer->autoaimx = autoaimx;
}

struct prop *bmoveGetHoverbike(void)
{
	if (g_Vars.currentplayer->bondmovemode == MOVEMODE_BIKE) {
		return g_Vars.currentplayer->hoverbike;
	}

	return NULL;
}

struct prop *bmoveGetGrabbedProp(void)
{
	if (g_Vars.currentplayer->bondmovemode == MOVEMODE_GRAB) {
		return g_Vars.currentplayer->grabbedprop;
	}

	return NULL;
}

void bmoveGrabProp(struct prop *prop)
{
	struct defaultobj *obj = prop->obj;

	if ((obj->hidden & OBJHFLAG_MOUNTED) == 0 && (obj->hidden & OBJHFLAG_GRABBED) == 0) {
		g_Vars.currentplayer->grabbedprop = prop;
		bgrabInit();
	}
}

void bmoveSetMode(u32 movemode)
{
	if (g_Vars.currentplayer->bondmovemode == MOVEMODE_GRAB) {
		bgrabExit();
	} else if (g_Vars.currentplayer->bondmovemode == MOVEMODE_BIKE) {
		bbikeExit();
	}

	if (movemode == MOVEMODE_BIKE) {
		bbikeInit();
	} else if (movemode == MOVEMODE_GRAB) {
		bgrabInit();
	} else if (movemode == MOVEMODE_CUTSCENE) {
		bcutsceneInit();
	} else if (movemode == MOVEMODE_WALK) {
		bwalkInit();
	}
}

void bmoveSetModeForAllPlayers(u32 movemode)
{
	u32 prevplayernum = g_Vars.currentplayernum;
	s32 i;

	for (i = 0; i < PLAYERCOUNT(); i++) {
		setCurrentPlayerNum(i);
		bmoveSetMode(movemode);
	}

	setCurrentPlayerNum(prevplayernum);
}

void bmoveHandleActivate(void)
{
	if (g_Vars.currentplayer->bondmovemode == MOVEMODE_BIKE) {
		bbikeHandleActivate();
	} else if (g_Vars.currentplayer->bondmovemode == MOVEMODE_GRAB) {
		bgrabHandleActivate();
	} else if (g_Vars.currentplayer->bondmovemode == MOVEMODE_WALK) {
		bwalkHandleActivate();
	}
}

void bmoveApplyMoveData(struct movedata *data)
{
	if (g_Vars.currentplayer->bondmovemode == MOVEMODE_BIKE) {
		bbikeApplyMoveData(data);
	} else if (g_Vars.currentplayer->bondmovemode == MOVEMODE_GRAB) {
		bgrabApplyMoveData(data);
	} else if (g_Vars.currentplayer->bondmovemode == MOVEMODE_WALK) {
		bwalkApplyMoveData(data);
	}
}

void bmoveUpdateSpeedTheta(void)
{
	if (g_Vars.currentplayer->bondmovemode == MOVEMODE_BIKE) {
		// empty
	} else if (g_Vars.currentplayer->bondmovemode == MOVEMODE_GRAB) {
		bgrabUpdateSpeedTheta();
	} else if (g_Vars.currentplayer->bondmovemode == MOVEMODE_WALK) {
		bwalkUpdateSpeedTheta();
	}
}

f32 bmoveGetSpeedVertaLimit(f32 value)
{
	if (value > 0) {
		return (viGetFovY() * value * -0.7f) / 60.0f;
	}

	if (value < 0) {
		return (viGetFovY() * -value * 0.7f) / 60.0f;
	}

	return 0;
}

void bmoveUpdateSpeedVerta(f32 value)
{
	f32 mult = viGetFovY() / 60.0f;
	f32 limit = bmoveGetSpeedVertaLimit(value);

	if (value > 0) {
		if (g_Vars.currentplayer->speedverta > 0) {
			g_Vars.currentplayer->speedverta -= 0.05f * g_Vars.lvupdate240freal * mult;
		} else {
			g_Vars.currentplayer->speedverta -= 0.0125f * g_Vars.lvupdate240freal * mult;
		}

		if (g_Vars.currentplayer->speedverta < limit) {
			g_Vars.currentplayer->speedverta = limit;
		}
	} else if (value < 0) {
		if (g_Vars.currentplayer->speedverta < 0) {
			g_Vars.currentplayer->speedverta += 0.05f * g_Vars.lvupdate240freal * mult;
		} else {
			g_Vars.currentplayer->speedverta += 0.0125f * g_Vars.lvupdate240freal * mult;
		}

		if (g_Vars.currentplayer->speedverta > limit) {
			g_Vars.currentplayer->speedverta = limit;
		}
	} else {
		if (g_Vars.currentplayer->speedverta > limit) {
			g_Vars.currentplayer->speedverta -= 0.05f * g_Vars.lvupdate240freal * mult;

			if (g_Vars.currentplayer->speedverta < limit) {
				g_Vars.currentplayer->speedverta = limit;
			}
		} else {
			g_Vars.currentplayer->speedverta += 0.05f * g_Vars.lvupdate240freal * mult;

			if (g_Vars.currentplayer->speedverta > limit) {
				g_Vars.currentplayer->speedverta = limit;
			}
		}
	}
}

f32 bmoveGetSpeedThetaControlLimit(f32 value)
{
	if (value > 0) {
		return (viGetFovY() * value * -0.7f) / 60.0f;
	}

	if (value < 0) {
		return (viGetFovY() * -value * 0.7f) / 60.0f;
	}

	return 0;
}

void bmoveUpdateSpeedThetaControl(f32 value)
{
	f32 mult = viGetFovY() / 60.0f;
	f32 limit = bmoveGetSpeedThetaControlLimit(value);

	if (value > 0) {
		if (g_Vars.currentplayer->speedthetacontrol > 0) {
			g_Vars.currentplayer->speedthetacontrol -= 0.05f * g_Vars.lvupdate240freal * mult;
		} else {
			g_Vars.currentplayer->speedthetacontrol -= 0.0125f * g_Vars.lvupdate240freal * mult;
		}

		if (g_Vars.currentplayer->speedthetacontrol < limit) {
			g_Vars.currentplayer->speedthetacontrol = limit;
		}
	} else if (value < 0) {
		if (g_Vars.currentplayer->speedthetacontrol < 0.0f) {
			g_Vars.currentplayer->speedthetacontrol += 0.05f * g_Vars.lvupdate240freal * mult;
		} else {
			g_Vars.currentplayer->speedthetacontrol += 0.0125f * g_Vars.lvupdate240freal * mult;
		}

		if (g_Vars.currentplayer->speedthetacontrol > limit) {
			g_Vars.currentplayer->speedthetacontrol = limit;
		}
	} else {
		if (g_Vars.currentplayer->speedthetacontrol > limit) {
			g_Vars.currentplayer->speedthetacontrol -= 0.05f * g_Vars.lvupdate240freal * mult;

			if (g_Vars.currentplayer->speedthetacontrol < limit) {
				g_Vars.currentplayer->speedthetacontrol = limit;
			}
		} else {
			g_Vars.currentplayer->speedthetacontrol += 0.05f * g_Vars.lvupdate240freal * mult;

			if (g_Vars.currentplayer->speedthetacontrol > limit) {
				g_Vars.currentplayer->speedthetacontrol = limit;
			}
		}
	}
}

/**
 * Calculate the lookahead angle.
 *
 * The return value is the intended vertical angle to look at.
 * 90 = straight up
 * 0 = horizontal
 * -90 = straight down
 */
f32 bmoveCalculateLookahead(void)
{
	f32 result = -4.0f;
	f32 sp160 = 400.0f;
	f32 ground = g_Vars.currentplayer->vv_ground;
	struct coord sp150;
	f32 ymax;
	f32 ymin;
	f32 width;
	u32 stack2;
	f32 angles[5];
	bool populated[5];
	s32 numpopulated = 0;
	u16 flags = 0;
	u32 stack3;
	struct coord sp100;
	u32 stack;
	struct coord spf0;
	s16 spe0[8];
	s32 i;
	f32 angle;
	f32 value;
	u32 stack4;
	u32 stack5;
	u32 stack6;
	struct coord spbc;
	struct coord spb0;
	s16 spa0[8];
	s16 sp90[8];
	s16 sp80[8];
	s32 j;
	f32 sp78;
	s32 indextoremove;
	f32 angletoremove;

	if (g_Vars.currentplayer->inlift) {
		return result;
	}

	propPlayerGetBbox(g_Vars.currentplayer->prop, &width, &ymax, &ymin);

	sp100.x = g_Vars.currentplayer->bond2.unk00.x;
	sp100.y = g_Vars.currentplayer->bond2.unk00.y;
	sp100.z = g_Vars.currentplayer->bond2.unk00.z;

	spf0.x = g_Vars.currentplayer->prop->pos.x;
	spf0.y = g_Vars.currentplayer->prop->pos.y - 30;
	spf0.z = g_Vars.currentplayer->prop->pos.z;

	func00018148(&g_Vars.currentplayer->prop->pos, &spf0,
			g_Vars.currentplayer->prop->rooms, spe0, NULL, 0);

	sp150.x = sp100.x * 400 + spf0.x;
	sp150.y = sp100.y * 400 + spf0.y;
	sp150.z = sp100.z * 400 + spf0.z;

	if (cdTestAToB4(&spf0, spe0, &sp150, CDTYPE_BG | CDTYPE_CLOSEDDOORS, 0xf) == CDRESULT_COLLISION) {
		cdGetPos(&sp150, 455, "bondmove.c");
		flags = cdGetTileFlags();

		sp160 = sqrtf((sp150.x - spf0.x) * (sp150.x - spf0.x)
				+ (sp150.y - spf0.y) * (sp150.y - spf0.y)
				+ (sp150.z - spf0.z) * (sp150.z - spf0.z));
	}

	if (sp160 > 60.0f || (flags & TILEFLAG_0001)) {
		for (i = 0; i < 5; i++) {
			populated[i] = false;
			value = (i + 1) * sp160 * 0.2f;

			spbc.x = sp100.x * value + spf0.x;
			spbc.y = sp100.y * value + spf0.y;
			spbc.z = sp100.z * value + spf0.z;

			func00018148(&spf0, &spbc, spe0, spa0, NULL, 0);

			spb0.x = spbc.x;
			spb0.y = spbc.y - 400;
			spb0.z = spbc.z;

			func00018148(&spbc, &spb0, spa0, sp90, sp80, 7);

			if (
#if VERSION >= VERSION_NTSC_1_0
					func0002a440(&spbc, sp80, &sp78, NULL, NULL) > 0
#else
					func0002a440(&spbc, sp80, &sp78, NULL) > 0
#endif
					&& sp78 - ground < 200
					&& sp78 - ground > -200) {
				angle = atan2f(sp78 - g_Vars.currentplayer->vv_ground, value);
				angle = (angle * 360) / M_BADTAU + -4;

				if (angle >= 180) {
					angle -= 360;
				}

				if (angle >= -50 && angle <= 40) {
					populated[i] = true;
					angles[i] = angle;
					numpopulated++;
					ground = sp78;
				}
			}
		}

		for (i = 0; i < numpopulated - 1; i++) {
			indextoremove = -1;

			for (j = 0; j < 5; j++) {
				if (populated[j]) {
					if (indextoremove < 0) {
						indextoremove = j;
						angletoremove = angles[j];
					} else if (i & 1) {
						if (angletoremove > angles[j]) {
							indextoremove = j;
							angletoremove = angles[j];
						}
					} else {
						if (angletoremove < angles[j]) {
							indextoremove = j;
							angletoremove = angles[j];
						}
					}
				}
			}

			if (indextoremove >= 0) {
				populated[indextoremove] = false;
			}
		}

		for (i = 0; i < 5; i++) {
			if (populated[i]) {
				result = angles[i];
				break;
			}
		}
	}

	if (result > 0.0f) {
		result *= 0.86666667461395f;
	}

	return result;
}

void bmoveResetMoveData(struct movedata *data)
{
	data->canswivelgun = 0;
	data->canmanualaim = 0;
	data->triggeron = false;
	data->btapcount = 0;
	data->canlookahead = false;
	data->unk14 = 0;
	data->cannaturalturn = false;
	data->cannaturalpitch = false;
	data->digitalstepforward = false;
	data->digitalstepback = false;
	data->digitalstepleft = false;
	data->digitalstepright = false;
	data->weaponbackoffset = 0;
	data->weaponforwardoffset = 0;
	data->unk50 = 0;
	data->unk54 = 0;
	data->unk58 = 0;
	data->crouchdown = false;
	data->crouchup = false;
	data->rleanleft = false;
	data->rleanright = false;
	data->detonating = false;
	data->canautoaim = false;
	data->farsighttempautoseek = false;
	data->eyesshut = false;
	data->unk30 = 0;
	data->unk34 = 0;
	data->speedvertadown = 0;
	data->speedvertaup = 0;
	data->aimturnleftspeed = 0;
	data->aimturnrightspeed = 0;
	data->zoomoutfovpersec = 0;
	data->zoominfovpersec = 0;
	data->invertpitch = !optionsGetForwardPitch(g_Vars.currentplayerstats->mpindex);
	data->disablelookahead = false;
	data->c1stickxsafe = 0;
	data->c1stickysafe = 0;
	data->c1stickxraw = 0;
	data->c1stickyraw = 0;
	data->analogturn = 0;
	data->analogpitch = 0;
	data->analogstrafe = 0;
	data->analogwalk = 0;
}

#if VERSION >= VERSION_PAL_FINAL
GLOBAL_ASM(
glabel bmoveProcessInput
.late_rodata
glabel var7f1ad8b8
.word 0x3c23d70a
glabel var7f1ad8bc
.word 0x3c23d70a
glabel var7f1ad8c0
.word 0x3d4ccccd
glabel var7f1ad8c4
.word 0x3f747ae1
glabel var7f1ad8c8
.word 0x39c73ab8
glabel var7f1ad8cc
.word 0x3f6624dd
glabel var7f1ad8d0
.word 0x3f795810
glabel var7f1ad8d4
.word 0x39c73ab8
glabel var7f1ad8d8
.word 0x3f747ae1
glabel var7f1ad8dc
.word 0x3e99999a
glabel var7f1ad8e0
.word 0x3dcccccd
glabel var7f1ad8e4
.word 0x3f266666
.text
/*  f0c8b90:	27bdfda0 */ 	addiu	$sp,$sp,-608
/*  f0c8b94:	afb2001c */ 	sw	$s2,0x1c($sp)
/*  f0c8b98:	3c12800a */ 	lui	$s2,%hi(g_Vars)
/*  f0c8b9c:	26529fc0 */ 	addiu	$s2,$s2,%lo(g_Vars)
/*  f0c8ba0:	8e4e0288 */ 	lw	$t6,0x288($s2)
/*  f0c8ba4:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f0c8ba8:	00808025 */ 	or	$s0,$a0,$zero
/*  f0c8bac:	afbf0034 */ 	sw	$ra,0x34($sp)
/*  f0c8bb0:	afb70030 */ 	sw	$s7,0x30($sp)
/*  f0c8bb4:	afb6002c */ 	sw	$s6,0x2c($sp)
/*  f0c8bb8:	afb50028 */ 	sw	$s5,0x28($sp)
/*  f0c8bbc:	afb40024 */ 	sw	$s4,0x24($sp)
/*  f0c8bc0:	afb30020 */ 	sw	$s3,0x20($sp)
/*  f0c8bc4:	afb10018 */ 	sw	$s1,0x18($sp)
/*  f0c8bc8:	afa7026c */ 	sw	$a3,0x26c($sp)
/*  f0c8bcc:	00a08825 */ 	or	$s1,$a1,$zero
/*  f0c8bd0:	00c0b025 */ 	or	$s6,$a2,$zero
/*  f0c8bd4:	0fc549c4 */ 	jal	optionsGetControlMode
/*  f0c8bd8:	8dc40070 */ 	lw	$a0,0x70($t6)
/*  f0c8bdc:	afa201b0 */ 	sw	$v0,0x1b0($sp)
/*  f0c8be0:	0fc2866a */ 	jal	bgunGetWeaponNum
/*  f0c8be4:	00002025 */ 	or	$a0,$zero,$zero
/*  f0c8be8:	afa201ac */ 	sw	$v0,0x1ac($sp)
/*  f0c8bec:	00402025 */ 	or	$a0,$v0,$zero
/*  f0c8bf0:	0fc2c601 */ 	jal	weaponHasClassFlag
/*  f0c8bf4:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f0c8bf8:	8e4f0288 */ 	lw	$t7,0x288($s2)
/*  f0c8bfc:	afa201a8 */ 	sw	$v0,0x1a8($sp)
/*  f0c8c00:	0fc549d2 */ 	jal	optionsGetContpadNum1
/*  f0c8c04:	8de40070 */ 	lw	$a0,0x70($t7)
/*  f0c8c08:	0002ae00 */ 	sll	$s5,$v0,0x18
/*  f0c8c0c:	0015c603 */ 	sra	$t8,$s5,0x18
/*  f0c8c10:	12000009 */ 	beqz	$s0,.L0f0c8c38
/*  f0c8c14:	0300a825 */ 	or	$s5,$t8,$zero
/*  f0c8c18:	00182600 */ 	sll	$a0,$t8,0x18
/*  f0c8c1c:	0004ce03 */ 	sra	$t9,$a0,0x18
/*  f0c8c20:	0c005384 */ 	jal	joyGetStickX
/*  f0c8c24:	03202025 */ 	or	$a0,$t9,$zero
/*  f0c8c28:	0002a600 */ 	sll	$s4,$v0,0x18
/*  f0c8c2c:	00144603 */ 	sra	$t0,$s4,0x18
/*  f0c8c30:	10000002 */ 	b	.L0f0c8c3c
/*  f0c8c34:	0100a025 */ 	or	$s4,$t0,$zero
.L0f0c8c38:
/*  f0c8c38:	0000a025 */ 	or	$s4,$zero,$zero
.L0f0c8c3c:
/*  f0c8c3c:	12200008 */ 	beqz	$s1,.L0f0c8c60
/*  f0c8c40:	00152600 */ 	sll	$a0,$s5,0x18
/*  f0c8c44:	00044e03 */ 	sra	$t1,$a0,0x18
/*  f0c8c48:	0c0053ae */ 	jal	joyGetStickY
/*  f0c8c4c:	01202025 */ 	or	$a0,$t1,$zero
/*  f0c8c50:	00029e00 */ 	sll	$s3,$v0,0x18
/*  f0c8c54:	00135603 */ 	sra	$t2,$s3,0x18
/*  f0c8c58:	10000002 */ 	b	.L0f0c8c64
/*  f0c8c5c:	01409825 */ 	or	$s3,$t2,$zero
.L0f0c8c60:
/*  f0c8c60:	00009825 */ 	or	$s3,$zero,$zero
.L0f0c8c64:
/*  f0c8c64:	0016b82b */ 	sltu	$s7,$zero,$s6
/*  f0c8c68:	12e00007 */ 	beqz	$s7,.L0f0c8c88
/*  f0c8c6c:	00152600 */ 	sll	$a0,$s5,0x18
/*  f0c8c70:	00045e03 */ 	sra	$t3,$a0,0x18
/*  f0c8c74:	01602025 */ 	or	$a0,$t3,$zero
/*  f0c8c78:	0c0053d8 */ 	jal	joyGetButtons
/*  f0c8c7c:	3405ffff */ 	dli	$a1,0xffff
/*  f0c8c80:	10000002 */ 	b	.L0f0c8c8c
/*  f0c8c84:	a7a201a2 */ 	sh	$v0,0x1a2($sp)
.L0f0c8c88:
/*  f0c8c88:	a7a001a2 */ 	sh	$zero,0x1a2($sp)
.L0f0c8c8c:
/*  f0c8c8c:	12e00007 */ 	beqz	$s7,.L0f0c8cac
/*  f0c8c90:	00152600 */ 	sll	$a0,$s5,0x18
/*  f0c8c94:	00046603 */ 	sra	$t4,$a0,0x18
/*  f0c8c98:	01802025 */ 	or	$a0,$t4,$zero
/*  f0c8c9c:	0c005408 */ 	jal	joyGetButtonsPressedThisFrame
/*  f0c8ca0:	3405ffff */ 	dli	$a1,0xffff
/*  f0c8ca4:	10000002 */ 	b	.L0f0c8cb0
/*  f0c8ca8:	a7a201a0 */ 	sh	$v0,0x1a0($sp)
.L0f0c8cac:
/*  f0c8cac:	a7a001a0 */ 	sh	$zero,0x1a0($sp)
.L0f0c8cb0:
/*  f0c8cb0:	8e4e0284 */ 	lw	$t6,0x284($s2)
/*  f0c8cb4:	340dffff */ 	dli	$t5,0xffff
/*  f0c8cb8:	a7ad019e */ 	sh	$t5,0x19e($sp)
/*  f0c8cbc:	8dc21c40 */ 	lw	$v0,0x1c40($t6)
/*  f0c8cc0:	304fffff */ 	andi	$t7,$v0,0xffff
/*  f0c8cc4:	11e00017 */ 	beqz	$t7,.L0f0c8d24
/*  f0c8cc8:	31f0ffff */ 	andi	$s0,$t7,0xffff
/*  f0c8ccc:	00152600 */ 	sll	$a0,$s5,0x18
/*  f0c8cd0:	0200c027 */ 	nor	$t8,$s0,$zero
/*  f0c8cd4:	0004ce03 */ 	sra	$t9,$a0,0x18
/*  f0c8cd8:	a7b8019e */ 	sh	$t8,0x19e($sp)
/*  f0c8cdc:	03202025 */ 	or	$a0,$t9,$zero
/*  f0c8ce0:	0c0053d8 */ 	jal	joyGetButtons
/*  f0c8ce4:	3405ffff */ 	dli	$a1,0xffff
/*  f0c8ce8:	00508824 */ 	and	$s1,$v0,$s0
/*  f0c8cec:	97a901a2 */ 	lhu	$t1,0x1a2($sp)
/*  f0c8cf0:	97ab01a0 */ 	lhu	$t3,0x1a0($sp)
/*  f0c8cf4:	3228ffff */ 	andi	$t0,$s1,0xffff
/*  f0c8cf8:	01001827 */ 	nor	$v1,$t0,$zero
/*  f0c8cfc:	8e450284 */ 	lw	$a1,0x284($s2)
/*  f0c8d00:	01235024 */ 	and	$t2,$t1,$v1
/*  f0c8d04:	01636024 */ 	and	$t4,$t3,$v1
/*  f0c8d08:	a7aa01a2 */ 	sh	$t2,0x1a2($sp)
/*  f0c8d0c:	a7ac01a0 */ 	sh	$t4,0x1a0($sp)
/*  f0c8d10:	8cad1c40 */ 	lw	$t5,0x1c40($a1)
/*  f0c8d14:	3c01ffff */ 	lui	$at,0xffff
/*  f0c8d18:	01a17024 */ 	and	$t6,$t5,$at
/*  f0c8d1c:	01c87825 */ 	or	$t7,$t6,$t0
/*  f0c8d20:	acaf1c40 */ 	sw	$t7,0x1c40($a1)
.L0f0c8d24:
/*  f0c8d24:	0c005207 */ 	jal	joyGetNumSamples
/*  f0c8d28:	00000000 */ 	nop
/*  f0c8d2c:	0040b025 */ 	or	$s6,$v0,$zero
/*  f0c8d30:	0fc322aa */ 	jal	bmoveResetMoveData
/*  f0c8d34:	27a401b4 */ 	addiu	$a0,$sp,0x1b4
/*  f0c8d38:	2a81fffb */ 	slti	$at,$s4,-5
/*  f0c8d3c:	10200003 */ 	beqz	$at,.L0f0c8d4c
/*  f0c8d40:	26980005 */ 	addiu	$t8,$s4,0x5
/*  f0c8d44:	10000007 */ 	b	.L0f0c8d64
/*  f0c8d48:	afb80240 */ 	sw	$t8,0x240($sp)
.L0f0c8d4c:
/*  f0c8d4c:	2a810006 */ 	slti	$at,$s4,0x6
/*  f0c8d50:	14200003 */ 	bnez	$at,.L0f0c8d60
/*  f0c8d54:	2699fffb */ 	addiu	$t9,$s4,-5
/*  f0c8d58:	10000002 */ 	b	.L0f0c8d64
/*  f0c8d5c:	afb90240 */ 	sw	$t9,0x240($sp)
.L0f0c8d60:
/*  f0c8d60:	afa00240 */ 	sw	$zero,0x240($sp)
.L0f0c8d64:
/*  f0c8d64:	2a61fffb */ 	slti	$at,$s3,-5
/*  f0c8d68:	10200003 */ 	beqz	$at,.L0f0c8d78
/*  f0c8d6c:	26680005 */ 	addiu	$t0,$s3,0x5
/*  f0c8d70:	10000007 */ 	b	.L0f0c8d90
/*  f0c8d74:	afa80244 */ 	sw	$t0,0x244($sp)
.L0f0c8d78:
/*  f0c8d78:	2a610006 */ 	slti	$at,$s3,0x6
/*  f0c8d7c:	14200003 */ 	bnez	$at,.L0f0c8d8c
/*  f0c8d80:	2669fffb */ 	addiu	$t1,$s3,-5
/*  f0c8d84:	10000002 */ 	b	.L0f0c8d90
/*  f0c8d88:	afa90244 */ 	sw	$t1,0x244($sp)
.L0f0c8d8c:
/*  f0c8d8c:	afa00244 */ 	sw	$zero,0x244($sp)
.L0f0c8d90:
/*  f0c8d90:	8faa0240 */ 	lw	$t2,0x240($sp)
/*  f0c8d94:	8fab0244 */ 	lw	$t3,0x244($sp)
/*  f0c8d98:	8e450284 */ 	lw	$a1,0x284($s2)
/*  f0c8d9c:	afb40248 */ 	sw	$s4,0x248($sp)
/*  f0c8da0:	afb3024c */ 	sw	$s3,0x24c($sp)
/*  f0c8da4:	afaa0250 */ 	sw	$t2,0x250($sp)
/*  f0c8da8:	afaa0258 */ 	sw	$t2,0x258($sp)
/*  f0c8dac:	afab0254 */ 	sw	$t3,0x254($sp)
/*  f0c8db0:	afab025c */ 	sw	$t3,0x25c($sp)
/*  f0c8db4:	8cac00d8 */ 	lw	$t4,0xd8($a1)
/*  f0c8db8:	55800017 */ 	bnezl	$t4,.L0f0c8e18
/*  f0c8dbc:	8e480314 */ 	lw	$t0,0x314($s2)
/*  f0c8dc0:	8cad1a24 */ 	lw	$t5,0x1a24($a1)
/*  f0c8dc4:	97ae01a0 */ 	lhu	$t6,0x1a0($sp)
/*  f0c8dc8:	15a0004a */ 	bnez	$t5,.L0f0c8ef4
/*  f0c8dcc:	31cf1000 */ 	andi	$t7,$t6,0x1000
/*  f0c8dd0:	51e00049 */ 	beqzl	$t7,.L0f0c8ef8
/*  f0c8dd4:	8e450284 */ 	lw	$a1,0x284($s2)
/*  f0c8dd8:	8e580314 */ 	lw	$t8,0x314($s2)
/*  f0c8ddc:	17000009 */ 	bnez	$t8,.L0f0c8e04
/*  f0c8de0:	00000000 */ 	nop
/*  f0c8de4:	8e59000c */ 	lw	$t9,0xc($s2)
/*  f0c8de8:	2b210010 */ 	slti	$at,$t9,0x10
/*  f0c8dec:	54200042 */ 	bnezl	$at,.L0f0c8ef8
/*  f0c8df0:	8e450284 */ 	lw	$a1,0x284($s2)
/*  f0c8df4:	0fc2ebc3 */ 	jal	currentPlayerPause
/*  f0c8df8:	24040002 */ 	addiu	$a0,$zero,0x2
/*  f0c8dfc:	1000003e */ 	b	.L0f0c8ef8
/*  f0c8e00:	8e450284 */ 	lw	$a1,0x284($s2)
.L0f0c8e04:
/*  f0c8e04:	0fc5e36f */ 	jal	mpPushPauseDialog
/*  f0c8e08:	00000000 */ 	nop
/*  f0c8e0c:	1000003a */ 	b	.L0f0c8ef8
/*  f0c8e10:	8e450284 */ 	lw	$a1,0x284($s2)
/*  f0c8e14:	8e480314 */ 	lw	$t0,0x314($s2)
.L0f0c8e18:
/*  f0c8e18:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0c8e1c:	51000036 */ 	beqzl	$t0,.L0f0c8ef8
/*  f0c8e20:	8e450284 */ 	lw	$a1,0x284($s2)
/*  f0c8e24:	8e49006c */ 	lw	$t1,0x6c($s2)
/*  f0c8e28:	00002825 */ 	or	$a1,$zero,$zero
/*  f0c8e2c:	00001025 */ 	or	$v0,$zero,$zero
/*  f0c8e30:	11200003 */ 	beqz	$t1,.L0f0c8e40
/*  f0c8e34:	00001825 */ 	or	$v1,$zero,$zero
/*  f0c8e38:	10000001 */ 	b	.L0f0c8e40
/*  f0c8e3c:	24050001 */ 	addiu	$a1,$zero,0x1
.L0f0c8e40:
/*  f0c8e40:	8e4a0068 */ 	lw	$t2,0x68($s2)
/*  f0c8e44:	00002025 */ 	or	$a0,$zero,$zero
/*  f0c8e48:	11400003 */ 	beqz	$t2,.L0f0c8e58
/*  f0c8e4c:	00000000 */ 	nop
/*  f0c8e50:	10000001 */ 	b	.L0f0c8e58
/*  f0c8e54:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f0c8e58:
/*  f0c8e58:	8e4b0064 */ 	lw	$t3,0x64($s2)
/*  f0c8e5c:	11600003 */ 	beqz	$t3,.L0f0c8e6c
/*  f0c8e60:	00000000 */ 	nop
/*  f0c8e64:	10000001 */ 	b	.L0f0c8e6c
/*  f0c8e68:	24030001 */ 	addiu	$v1,$zero,0x1
.L0f0c8e6c:
/*  f0c8e6c:	8e4c0070 */ 	lw	$t4,0x70($s2)
/*  f0c8e70:	11800003 */ 	beqz	$t4,.L0f0c8e80
/*  f0c8e74:	00000000 */ 	nop
/*  f0c8e78:	10000001 */ 	b	.L0f0c8e80
/*  f0c8e7c:	24040001 */ 	addiu	$a0,$zero,0x1
.L0f0c8e80:
/*  f0c8e80:	00836821 */ 	addu	$t5,$a0,$v1
/*  f0c8e84:	01a27021 */ 	addu	$t6,$t5,$v0
/*  f0c8e88:	01c57821 */ 	addu	$t7,$t6,$a1
/*  f0c8e8c:	15e10010 */ 	bne	$t7,$at,.L0f0c8ed0
/*  f0c8e90:	00000000 */ 	nop
/*  f0c8e94:	0fc62590 */ 	jal	mpIsPaused
/*  f0c8e98:	00000000 */ 	nop
/*  f0c8e9c:	10400015 */ 	beqz	$v0,.L0f0c8ef4
/*  f0c8ea0:	97b801a0 */ 	lhu	$t8,0x1a0($sp)
/*  f0c8ea4:	33191000 */ 	andi	$t9,$t8,0x1000
/*  f0c8ea8:	13200012 */ 	beqz	$t9,.L0f0c8ef4
/*  f0c8eac:	3c08800b */ 	lui	$t0,%hi(g_MpSetup+0x1e)
/*  f0c8eb0:	9108cba6 */ 	lbu	$t0,%lo(g_MpSetup+0x1e)($t0)
/*  f0c8eb4:	24010002 */ 	addiu	$at,$zero,0x2
/*  f0c8eb8:	5101000f */ 	beql	$t0,$at,.L0f0c8ef8
/*  f0c8ebc:	8e450284 */ 	lw	$a1,0x284($s2)
/*  f0c8ec0:	0fc625cb */ 	jal	mpSetPaused
/*  f0c8ec4:	00002025 */ 	or	$a0,$zero,$zero
/*  f0c8ec8:	1000000b */ 	b	.L0f0c8ef8
/*  f0c8ecc:	8e450284 */ 	lw	$a1,0x284($s2)
.L0f0c8ed0:
/*  f0c8ed0:	0fc62590 */ 	jal	mpIsPaused
/*  f0c8ed4:	00000000 */ 	nop
/*  f0c8ed8:	10400006 */ 	beqz	$v0,.L0f0c8ef4
/*  f0c8edc:	97a901a0 */ 	lhu	$t1,0x1a0($sp)
/*  f0c8ee0:	312a1000 */ 	andi	$t2,$t1,0x1000
/*  f0c8ee4:	51400004 */ 	beqzl	$t2,.L0f0c8ef8
/*  f0c8ee8:	8e450284 */ 	lw	$a1,0x284($s2)
/*  f0c8eec:	0fc5e36f */ 	jal	mpPushPauseDialog
/*  f0c8ef0:	00000000 */ 	nop
.L0f0c8ef4:
/*  f0c8ef4:	8e450284 */ 	lw	$a1,0x284($s2)
.L0f0c8ef8:
/*  f0c8ef8:	8cab1a24 */ 	lw	$t3,0x1a24($a1)
/*  f0c8efc:	55600675 */ 	bnezl	$t3,.L0f0ca8d4
/*  f0c8f00:	aca000d0 */ 	sw	$zero,0xd0($a1)
/*  f0c8f04:	8cac00d8 */ 	lw	$t4,0xd8($a1)
/*  f0c8f08:	8fa201b0 */ 	lw	$v0,0x1b0($sp)
/*  f0c8f0c:	24010006 */ 	addiu	$at,$zero,0x6
/*  f0c8f10:	55800670 */ 	bnezl	$t4,.L0f0ca8d4
/*  f0c8f14:	aca000d0 */ 	sw	$zero,0xd0($a1)
/*  f0c8f18:	10410007 */ 	beq	$v0,$at,.L0f0c8f38
/*  f0c8f1c:	24010007 */ 	addiu	$at,$zero,0x7
/*  f0c8f20:	10410005 */ 	beq	$v0,$at,.L0f0c8f38
/*  f0c8f24:	24010005 */ 	addiu	$at,$zero,0x5
/*  f0c8f28:	10410003 */ 	beq	$v0,$at,.L0f0c8f38
/*  f0c8f2c:	24010004 */ 	addiu	$at,$zero,0x4
/*  f0c8f30:	5441033f */ 	bnel	$v0,$at,.L0f0c9c30
/*  f0c8f34:	24010002 */ 	addiu	$at,$zero,0x2
.L0f0c8f38:
/*  f0c8f38:	8e4d0288 */ 	lw	$t5,0x288($s2)
/*  f0c8f3c:	0fc549d9 */ 	jal	optionsGetContpadNum2
/*  f0c8f40:	8da40070 */ 	lw	$a0,0x70($t5)
/*  f0c8f44:	0002a600 */ 	sll	$s4,$v0,0x18
/*  f0c8f48:	00022600 */ 	sll	$a0,$v0,0x18
/*  f0c8f4c:	00147603 */ 	sra	$t6,$s4,0x18
/*  f0c8f50:	00047e03 */ 	sra	$t7,$a0,0x18
/*  f0c8f54:	01c0a025 */ 	or	$s4,$t6,$zero
/*  f0c8f58:	0c005384 */ 	jal	joyGetStickX
/*  f0c8f5c:	01e02025 */ 	or	$a0,$t7,$zero
/*  f0c8f60:	00142600 */ 	sll	$a0,$s4,0x18
/*  f0c8f64:	0004c603 */ 	sra	$t8,$a0,0x18
/*  f0c8f68:	a3a200e9 */ 	sb	$v0,0xe9($sp)
/*  f0c8f6c:	0c0053ae */ 	jal	joyGetStickY
/*  f0c8f70:	03002025 */ 	or	$a0,$t8,$zero
/*  f0c8f74:	00028600 */ 	sll	$s0,$v0,0x18
/*  f0c8f78:	00142600 */ 	sll	$a0,$s4,0x18
/*  f0c8f7c:	0010ce03 */ 	sra	$t9,$s0,0x18
/*  f0c8f80:	00044603 */ 	sra	$t0,$a0,0x18
/*  f0c8f84:	03208025 */ 	or	$s0,$t9,$zero
/*  f0c8f88:	01002025 */ 	or	$a0,$t0,$zero
/*  f0c8f8c:	0c0053d8 */ 	jal	joyGetButtons
/*  f0c8f90:	3405ffff */ 	dli	$a1,0xffff
/*  f0c8f94:	00142600 */ 	sll	$a0,$s4,0x18
/*  f0c8f98:	00044e03 */ 	sra	$t1,$a0,0x18
/*  f0c8f9c:	a7a200e6 */ 	sh	$v0,0xe6($sp)
/*  f0c8fa0:	01202025 */ 	or	$a0,$t1,$zero
/*  f0c8fa4:	0c005408 */ 	jal	joyGetButtonsPressedThisFrame
/*  f0c8fa8:	3405ffff */ 	dli	$a1,0xffff
/*  f0c8fac:	8e4b0284 */ 	lw	$t3,0x284($s2)
/*  f0c8fb0:	340affff */ 	dli	$t2,0xffff
/*  f0c8fb4:	a7a200e4 */ 	sh	$v0,0xe4($sp)
/*  f0c8fb8:	a7aa00da */ 	sh	$t2,0xda($sp)
/*  f0c8fbc:	8d631c40 */ 	lw	$v1,0x1c40($t3)
/*  f0c8fc0:	83b300e9 */ 	lb	$s3,0xe9($sp)
/*  f0c8fc4:	02002025 */ 	or	$a0,$s0,$zero
/*  f0c8fc8:	00036402 */ 	srl	$t4,$v1,0x10
/*  f0c8fcc:	5180001b */ 	beqzl	$t4,.L0f0c903c
/*  f0c8fd0:	8faf026c */ 	lw	$t7,0x26c($sp)
/*  f0c8fd4:	afb000dc */ 	sw	$s0,0xdc($sp)
/*  f0c8fd8:	00038c02 */ 	srl	$s1,$v1,0x10
/*  f0c8fdc:	3230ffff */ 	andi	$s0,$s1,0xffff
/*  f0c8fe0:	00142600 */ 	sll	$a0,$s4,0x18
/*  f0c8fe4:	02007027 */ 	nor	$t6,$s0,$zero
/*  f0c8fe8:	00047e03 */ 	sra	$t7,$a0,0x18
/*  f0c8fec:	a7ae00da */ 	sh	$t6,0xda($sp)
/*  f0c8ff0:	01e02025 */ 	or	$a0,$t7,$zero
/*  f0c8ff4:	0c0053d8 */ 	jal	joyGetButtons
/*  f0c8ff8:	3405ffff */ 	dli	$a1,0xffff
/*  f0c8ffc:	97b900e6 */ 	lhu	$t9,0xe6($sp)
/*  f0c9000:	97a900e4 */ 	lhu	$t1,0xe4($sp)
/*  f0c9004:	0050c024 */ 	and	$t8,$v0,$s0
/*  f0c9008:	03001827 */ 	nor	$v1,$t8,$zero
/*  f0c900c:	8e450284 */ 	lw	$a1,0x284($s2)
/*  f0c9010:	03234024 */ 	and	$t0,$t9,$v1
/*  f0c9014:	01235024 */ 	and	$t2,$t1,$v1
/*  f0c9018:	a7a800e6 */ 	sh	$t0,0xe6($sp)
/*  f0c901c:	a7aa00e4 */ 	sh	$t2,0xe4($sp)
/*  f0c9020:	8cab1c40 */ 	lw	$t3,0x1c40($a1)
/*  f0c9024:	00186c00 */ 	sll	$t5,$t8,0x10
/*  f0c9028:	316cffff */ 	andi	$t4,$t3,0xffff
/*  f0c902c:	018d7025 */ 	or	$t6,$t4,$t5
/*  f0c9030:	acae1c40 */ 	sw	$t6,0x1c40($a1)
/*  f0c9034:	8fa400dc */ 	lw	$a0,0xdc($sp)
/*  f0c9038:	8faf026c */ 	lw	$t7,0x26c($sp)
.L0f0c903c:
/*  f0c903c:	51e00007 */ 	beqzl	$t7,.L0f0c905c
/*  f0c9040:	2a61fffb */ 	slti	$at,$s3,-5
/*  f0c9044:	a3a000e9 */ 	sb	$zero,0xe9($sp)
/*  f0c9048:	a7a000e6 */ 	sh	$zero,0xe6($sp)
/*  f0c904c:	00009825 */ 	or	$s3,$zero,$zero
/*  f0c9050:	00002025 */ 	or	$a0,$zero,$zero
/*  f0c9054:	a7a000e4 */ 	sh	$zero,0xe4($sp)
/*  f0c9058:	2a61fffb */ 	slti	$at,$s3,-5
.L0f0c905c:
/*  f0c905c:	10200003 */ 	beqz	$at,.L0f0c906c
/*  f0c9060:	8fa201b0 */ 	lw	$v0,0x1b0($sp)
/*  f0c9064:	10000007 */ 	b	.L0f0c9084
/*  f0c9068:	26730005 */ 	addiu	$s3,$s3,0x5
.L0f0c906c:
/*  f0c906c:	2a610006 */ 	slti	$at,$s3,0x6
/*  f0c9070:	54200004 */ 	bnezl	$at,.L0f0c9084
/*  f0c9074:	00009825 */ 	or	$s3,$zero,$zero
/*  f0c9078:	10000002 */ 	b	.L0f0c9084
/*  f0c907c:	2673fffb */ 	addiu	$s3,$s3,-5
/*  f0c9080:	00009825 */ 	or	$s3,$zero,$zero
.L0f0c9084:
/*  f0c9084:	2881fffb */ 	slti	$at,$a0,-5
/*  f0c9088:	50200004 */ 	beqzl	$at,.L0f0c909c
/*  f0c908c:	28810006 */ 	slti	$at,$a0,0x6
/*  f0c9090:	10000007 */ 	b	.L0f0c90b0
/*  f0c9094:	24840005 */ 	addiu	$a0,$a0,0x5
/*  f0c9098:	28810006 */ 	slti	$at,$a0,0x6
.L0f0c909c:
/*  f0c909c:	54200004 */ 	bnezl	$at,.L0f0c90b0
/*  f0c90a0:	00002025 */ 	or	$a0,$zero,$zero
/*  f0c90a4:	10000002 */ 	b	.L0f0c90b0
/*  f0c90a8:	2484fffb */ 	addiu	$a0,$a0,-5
/*  f0c90ac:	00002025 */ 	or	$a0,$zero,$zero
.L0f0c90b0:
/*  f0c90b0:	24010004 */ 	addiu	$at,$zero,0x4
/*  f0c90b4:	10410003 */ 	beq	$v0,$at,.L0f0c90c4
/*  f0c90b8:	24010006 */ 	addiu	$at,$zero,0x6
/*  f0c90bc:	54410005 */ 	bnel	$v0,$at,.L0f0c90d4
/*  f0c90c0:	afb30258 */ 	sw	$s3,0x258($sp)
.L0f0c90c4:
/*  f0c90c4:	afb30258 */ 	sw	$s3,0x258($sp)
/*  f0c90c8:	10000003 */ 	b	.L0f0c90d8
/*  f0c90cc:	afa40254 */ 	sw	$a0,0x254($sp)
/*  f0c90d0:	afb30258 */ 	sw	$s3,0x258($sp)
.L0f0c90d4:
/*  f0c90d4:	afa4025c */ 	sw	$a0,0x25c($sp)
.L0f0c90d8:
/*  f0c90d8:	8e5802ac */ 	lw	$t8,0x2ac($s2)
/*  f0c90dc:	24010007 */ 	addiu	$at,$zero,0x7
/*  f0c90e0:	afa400dc */ 	sw	$a0,0xdc($sp)
/*  f0c90e4:	5701000b */ 	bnel	$t8,$at,.L0f0c9114
/*  f0c90e8:	24010004 */ 	addiu	$at,$zero,0x4
/*  f0c90ec:	8e450284 */ 	lw	$a1,0x284($s2)
/*  f0c90f0:	afa001d4 */ 	sw	$zero,0x1d4($sp)
/*  f0c90f4:	afa001d8 */ 	sw	$zero,0x1d8($sp)
/*  f0c90f8:	afa00258 */ 	sw	$zero,0x258($sp)
/*  f0c90fc:	8cb91bdc */ 	lw	$t9,0x1bdc($a1)
/*  f0c9100:	afb9025c */ 	sw	$t9,0x25c($sp)
/*  f0c9104:	8ca81bd8 */ 	lw	$t0,0x1bd8($a1)
/*  f0c9108:	afa00254 */ 	sw	$zero,0x254($sp)
/*  f0c910c:	afa80250 */ 	sw	$t0,0x250($sp)
/*  f0c9110:	24010004 */ 	addiu	$at,$zero,0x4
.L0f0c9114:
/*  f0c9114:	10410005 */ 	beq	$v0,$at,.L0f0c912c
/*  f0c9118:	8fa400dc */ 	lw	$a0,0xdc($sp)
/*  f0c911c:	24010005 */ 	addiu	$at,$zero,0x5
/*  f0c9120:	1441000b */ 	bne	$v0,$at,.L0f0c9150
/*  f0c9124:	00158e00 */ 	sll	$s1,$s5,0x18
/*  f0c9128:	afa400dc */ 	sw	$a0,0xdc($sp)
.L0f0c912c:
/*  f0c912c:	97aa00da */ 	lhu	$t2,0xda($sp)
/*  f0c9130:	97ab019e */ 	lhu	$t3,0x19e($sp)
/*  f0c9134:	00148e00 */ 	sll	$s1,$s4,0x18
/*  f0c9138:	00114e03 */ 	sra	$t1,$s1,0x18
/*  f0c913c:	01208825 */ 	or	$s1,$t1,$zero
/*  f0c9140:	a3b500ef */ 	sb	$s5,0xef($sp)
/*  f0c9144:	a7aa00ec */ 	sh	$t2,0xec($sp)
/*  f0c9148:	10000009 */ 	b	.L0f0c9170
/*  f0c914c:	a7ab00ea */ 	sh	$t3,0xea($sp)
.L0f0c9150:
/*  f0c9150:	97ad019e */ 	lhu	$t5,0x19e($sp)
/*  f0c9154:	97ae00da */ 	lhu	$t6,0xda($sp)
/*  f0c9158:	00116603 */ 	sra	$t4,$s1,0x18
/*  f0c915c:	afa400dc */ 	sw	$a0,0xdc($sp)
/*  f0c9160:	01808825 */ 	or	$s1,$t4,$zero
/*  f0c9164:	a3b400ef */ 	sb	$s4,0xef($sp)
/*  f0c9168:	a7ad00ec */ 	sh	$t5,0xec($sp)
/*  f0c916c:	a7ae00ea */ 	sh	$t6,0xea($sp)
.L0f0c9170:
/*  f0c9170:	8e4f0288 */ 	lw	$t7,0x288($s2)
/*  f0c9174:	0fc549fb */ 	jal	optionsGetAimControl
/*  f0c9178:	8de40070 */ 	lw	$a0,0x70($t7)
/*  f0c917c:	1440001f */ 	bnez	$v0,.L0f0c91fc
/*  f0c9180:	00000000 */ 	nop
/*  f0c9184:	1ac00018 */ 	blez	$s6,.L0f0c91e8
/*  f0c9188:	00008025 */ 	or	$s0,$zero,$zero
/*  f0c918c:	27a3014c */ 	addiu	$v1,$sp,0x14c
/*  f0c9190:	27a700fc */ 	addiu	$a3,$sp,0xfc
.L0f0c9194:
/*  f0c9194:	12e0000d */ 	beqz	$s7,.L0f0c91cc
/*  f0c9198:	02e02025 */ 	or	$a0,$s7,$zero
/*  f0c919c:	97b900ec */ 	lhu	$t9,0xec($sp)
/*  f0c91a0:	00112e00 */ 	sll	$a1,$s1,0x18
/*  f0c91a4:	0005c603 */ 	sra	$t8,$a1,0x18
/*  f0c91a8:	03002825 */ 	or	$a1,$t8,$zero
/*  f0c91ac:	02002025 */ 	or	$a0,$s0,$zero
/*  f0c91b0:	afa3004c */ 	sw	$v1,0x4c($sp)
/*  f0c91b4:	afa70048 */ 	sw	$a3,0x48($sp)
/*  f0c91b8:	0c00529e */ 	jal	joyGetButtonsOnSample
/*  f0c91bc:	33262000 */ 	andi	$a2,$t9,0x2000
/*  f0c91c0:	8fa3004c */ 	lw	$v1,0x4c($sp)
/*  f0c91c4:	8fa70048 */ 	lw	$a3,0x48($sp)
/*  f0c91c8:	0002202b */ 	sltu	$a0,$zero,$v0
.L0f0c91cc:
/*  f0c91cc:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f0c91d0:	2c890001 */ 	sltiu	$t1,$a0,0x1
/*  f0c91d4:	24630004 */ 	addiu	$v1,$v1,0x4
/*  f0c91d8:	24e70004 */ 	addiu	$a3,$a3,0x4
/*  f0c91dc:	ac64fffc */ 	sw	$a0,-0x4($v1)
/*  f0c91e0:	1616ffec */ 	bne	$s0,$s6,.L0f0c9194
/*  f0c91e4:	ace9fffc */ 	sw	$t1,-0x4($a3)
.L0f0c91e8:
/*  f0c91e8:	00165080 */ 	sll	$t2,$s6,0x2
/*  f0c91ec:	03aa5821 */ 	addu	$t3,$sp,$t2
/*  f0c91f0:	8d6b0148 */ 	lw	$t3,0x148($t3)
/*  f0c91f4:	8e4c0284 */ 	lw	$t4,0x284($s2)
/*  f0c91f8:	ad8b0120 */ 	sw	$t3,0x120($t4)
.L0f0c91fc:
/*  f0c91fc:	0fc5b364 */ 	jal	lvIsPaused
/*  f0c9200:	00000000 */ 	nop
/*  f0c9204:	54400243 */ 	bnezl	$v0,.L0f0c9b14
/*  f0c9208:	8e450284 */ 	lw	$a1,0x284($s2)
/*  f0c920c:	8e4d0288 */ 	lw	$t5,0x288($s2)
/*  f0c9210:	0fc549fb */ 	jal	optionsGetAimControl
/*  f0c9214:	8da40070 */ 	lw	$a0,0x70($t5)
/*  f0c9218:	1040001f */ 	beqz	$v0,.L0f0c9298
/*  f0c921c:	00000000 */ 	nop
/*  f0c9220:	1ac0001d */ 	blez	$s6,.L0f0c9298
/*  f0c9224:	00008025 */ 	or	$s0,$zero,$zero
/*  f0c9228:	27a3014c */ 	addiu	$v1,$sp,0x14c
/*  f0c922c:	27a700fc */ 	addiu	$a3,$sp,0xfc
.L0f0c9230:
/*  f0c9230:	12e00010 */ 	beqz	$s7,.L0f0c9274
/*  f0c9234:	02002025 */ 	or	$a0,$s0,$zero
/*  f0c9238:	97af00ec */ 	lhu	$t7,0xec($sp)
/*  f0c923c:	00112e00 */ 	sll	$a1,$s1,0x18
/*  f0c9240:	00057603 */ 	sra	$t6,$a1,0x18
/*  f0c9244:	01c02825 */ 	or	$a1,$t6,$zero
/*  f0c9248:	afa3004c */ 	sw	$v1,0x4c($sp)
/*  f0c924c:	afa70048 */ 	sw	$a3,0x48($sp)
/*  f0c9250:	0c0052d4 */ 	jal	joyGetButtonsPressedOnSample
/*  f0c9254:	31e62000 */ 	andi	$a2,$t7,0x2000
/*  f0c9258:	8fa3004c */ 	lw	$v1,0x4c($sp)
/*  f0c925c:	10400005 */ 	beqz	$v0,.L0f0c9274
/*  f0c9260:	8fa70048 */ 	lw	$a3,0x48($sp)
/*  f0c9264:	8e450284 */ 	lw	$a1,0x284($s2)
/*  f0c9268:	8ca40120 */ 	lw	$a0,0x120($a1)
/*  f0c926c:	2c990001 */ 	sltiu	$t9,$a0,0x1
/*  f0c9270:	acb90120 */ 	sw	$t9,0x120($a1)
.L0f0c9274:
/*  f0c9274:	8e480284 */ 	lw	$t0,0x284($s2)
/*  f0c9278:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f0c927c:	24630004 */ 	addiu	$v1,$v1,0x4
/*  f0c9280:	8d090120 */ 	lw	$t1,0x120($t0)
/*  f0c9284:	24e70004 */ 	addiu	$a3,$a3,0x4
/*  f0c9288:	2d2a0001 */ 	sltiu	$t2,$t1,0x1
/*  f0c928c:	aceafffc */ 	sw	$t2,-0x4($a3)
/*  f0c9290:	1616ffe7 */ 	bne	$s0,$s6,.L0f0c9230
/*  f0c9294:	ac69fffc */ 	sw	$t1,-0x4($v1)
.L0f0c9298:
/*  f0c9298:	0fc2866a */ 	jal	bgunGetWeaponNum
/*  f0c929c:	00002025 */ 	or	$a0,$zero,$zero
/*  f0c92a0:	24010032 */ 	addiu	$at,$zero,0x32
/*  f0c92a4:	54410005 */ 	bnel	$v0,$at,.L0f0c92bc
/*  f0c92a8:	8e450284 */ 	lw	$a1,0x284($s2)
/*  f0c92ac:	8e4c0284 */ 	lw	$t4,0x284($s2)
/*  f0c92b0:	240b0001 */ 	addiu	$t3,$zero,0x1
/*  f0c92b4:	ad8b0120 */ 	sw	$t3,0x120($t4)
/*  f0c92b8:	8e450284 */ 	lw	$a1,0x284($s2)
.L0f0c92bc:
/*  f0c92bc:	24190001 */ 	addiu	$t9,$zero,0x1
/*  f0c92c0:	8ca40120 */ 	lw	$a0,0x120($a1)
/*  f0c92c4:	2c8d0001 */ 	sltiu	$t5,$a0,0x1
/*  f0c92c8:	afad01b4 */ 	sw	$t5,0x1b4($sp)
/*  f0c92cc:	8cae0120 */ 	lw	$t6,0x120($a1)
/*  f0c92d0:	afae01b8 */ 	sw	$t6,0x1b8($sp)
/*  f0c92d4:	8ca40120 */ 	lw	$a0,0x120($a1)
/*  f0c92d8:	afa001d4 */ 	sw	$zero,0x1d4($sp)
/*  f0c92dc:	afa001d8 */ 	sw	$zero,0x1d8($sp)
/*  f0c92e0:	2c8f0001 */ 	sltiu	$t7,$a0,0x1
/*  f0c92e4:	afaf022c */ 	sw	$t7,0x22c($sp)
/*  f0c92e8:	afa001dc */ 	sw	$zero,0x1dc($sp)
/*  f0c92ec:	afa001e0 */ 	sw	$zero,0x1e0($sp)
/*  f0c92f0:	8ca40120 */ 	lw	$a0,0x120($a1)
/*  f0c92f4:	afb901c8 */ 	sw	$t9,0x1c8($sp)
/*  f0c92f8:	2c980001 */ 	sltiu	$t8,$a0,0x1
/*  f0c92fc:	afb801c4 */ 	sw	$t8,0x1c4($sp)
/*  f0c9300:	8ca40120 */ 	lw	$a0,0x120($a1)
/*  f0c9304:	2c880001 */ 	sltiu	$t0,$a0,0x1
/*  f0c9308:	afa801cc */ 	sw	$t0,0x1cc($sp)
/*  f0c930c:	8ca40120 */ 	lw	$a0,0x120($a1)
/*  f0c9310:	2c890001 */ 	sltiu	$t1,$a0,0x1
/*  f0c9314:	afa901d0 */ 	sw	$t1,0x1d0($sp)
/*  f0c9318:	8caa0120 */ 	lw	$t2,0x120($a1)
/*  f0c931c:	51400015 */ 	beqzl	$t2,.L0f0c9374
/*  f0c9320:	44809000 */ 	mtc1	$zero,$f18
/*  f0c9324:	8fa4024c */ 	lw	$a0,0x24c($sp)
/*  f0c9328:	2881003d */ 	slti	$at,$a0,0x3d
/*  f0c932c:	14200010 */ 	bnez	$at,.L0f0c9370
/*  f0c9330:	248bffc4 */ 	addiu	$t3,$a0,-60
/*  f0c9334:	448b2000 */ 	mtc1	$t3,$f4
/*  f0c9338:	3c014120 */ 	lui	$at,0x4120
/*  f0c933c:	44811000 */ 	mtc1	$at,$f2
/*  f0c9340:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f0c9344:	3c013f80 */ 	lui	$at,0x3f80
/*  f0c9348:	44815000 */ 	mtc1	$at,$f10
/*  f0c934c:	3c013f80 */ 	lui	$at,0x3f80
/*  f0c9350:	46023203 */ 	div.s	$f8,$f6,$f2
/*  f0c9354:	4608503c */ 	c.lt.s	$f10,$f8
/*  f0c9358:	e7a801ec */ 	swc1	$f8,0x1ec($sp)
/*  f0c935c:	45020009 */ 	bc1fl	.L0f0c9384
/*  f0c9360:	8cac0120 */ 	lw	$t4,0x120($a1)
/*  f0c9364:	44818000 */ 	mtc1	$at,$f16
/*  f0c9368:	10000005 */ 	b	.L0f0c9380
/*  f0c936c:	e7b001ec */ 	swc1	$f16,0x1ec($sp)
.L0f0c9370:
/*  f0c9370:	44809000 */ 	mtc1	$zero,$f18
.L0f0c9374:
/*  f0c9374:	3c014120 */ 	lui	$at,0x4120
/*  f0c9378:	44811000 */ 	mtc1	$at,$f2
/*  f0c937c:	e7b201ec */ 	swc1	$f18,0x1ec($sp)
.L0f0c9380:
/*  f0c9380:	8cac0120 */ 	lw	$t4,0x120($a1)
.L0f0c9384:
/*  f0c9384:	51800014 */ 	beqzl	$t4,.L0f0c93d8
/*  f0c9388:	44809000 */ 	mtc1	$zero,$f18
/*  f0c938c:	8fa4024c */ 	lw	$a0,0x24c($sp)
/*  f0c9390:	240dffc4 */ 	addiu	$t5,$zero,-60
/*  f0c9394:	2881ffc4 */ 	slti	$at,$a0,-60
/*  f0c9398:	1020000e */ 	beqz	$at,.L0f0c93d4
/*  f0c939c:	01a47023 */ 	subu	$t6,$t5,$a0
/*  f0c93a0:	448e2000 */ 	mtc1	$t6,$f4
/*  f0c93a4:	3c013f80 */ 	lui	$at,0x3f80
/*  f0c93a8:	44814000 */ 	mtc1	$at,$f8
/*  f0c93ac:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f0c93b0:	3c013f80 */ 	lui	$at,0x3f80
/*  f0c93b4:	46023283 */ 	div.s	$f10,$f6,$f2
/*  f0c93b8:	460a403c */ 	c.lt.s	$f8,$f10
/*  f0c93bc:	e7aa01f0 */ 	swc1	$f10,0x1f0($sp)
/*  f0c93c0:	45020008 */ 	bc1fl	.L0f0c93e4
/*  f0c93c4:	8caf0120 */ 	lw	$t7,0x120($a1)
/*  f0c93c8:	44818000 */ 	mtc1	$at,$f16
/*  f0c93cc:	10000004 */ 	b	.L0f0c93e0
/*  f0c93d0:	e7b001f0 */ 	swc1	$f16,0x1f0($sp)
.L0f0c93d4:
/*  f0c93d4:	44809000 */ 	mtc1	$zero,$f18
.L0f0c93d8:
/*  f0c93d8:	00000000 */ 	nop
/*  f0c93dc:	e7b201f0 */ 	swc1	$f18,0x1f0($sp)
.L0f0c93e0:
/*  f0c93e0:	8caf0120 */ 	lw	$t7,0x120($a1)
.L0f0c93e4:
/*  f0c93e4:	8fa30248 */ 	lw	$v1,0x248($sp)
/*  f0c93e8:	11e00011 */ 	beqz	$t7,.L0f0c9430
/*  f0c93ec:	2861ffc4 */ 	slti	$at,$v1,-60
/*  f0c93f0:	1020000f */ 	beqz	$at,.L0f0c9430
/*  f0c93f4:	2418ffc4 */ 	addiu	$t8,$zero,-60
/*  f0c93f8:	0303c823 */ 	subu	$t9,$t8,$v1
/*  f0c93fc:	44992000 */ 	mtc1	$t9,$f4
/*  f0c9400:	3c013f80 */ 	lui	$at,0x3f80
/*  f0c9404:	44814000 */ 	mtc1	$at,$f8
/*  f0c9408:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f0c940c:	3c013f80 */ 	lui	$at,0x3f80
/*  f0c9410:	46023303 */ 	div.s	$f12,$f6,$f2
/*  f0c9414:	460c403c */ 	c.lt.s	$f8,$f12
/*  f0c9418:	e7ac01f4 */ 	swc1	$f12,0x1f4($sp)
/*  f0c941c:	45020008 */ 	bc1fl	.L0f0c9440
/*  f0c9420:	8ca80120 */ 	lw	$t0,0x120($a1)
/*  f0c9424:	44816000 */ 	mtc1	$at,$f12
/*  f0c9428:	10000004 */ 	b	.L0f0c943c
/*  f0c942c:	e7ac01f4 */ 	swc1	$f12,0x1f4($sp)
.L0f0c9430:
/*  f0c9430:	44806000 */ 	mtc1	$zero,$f12
/*  f0c9434:	00000000 */ 	nop
/*  f0c9438:	e7ac01f4 */ 	swc1	$f12,0x1f4($sp)
.L0f0c943c:
/*  f0c943c:	8ca80120 */ 	lw	$t0,0x120($a1)
.L0f0c9440:
/*  f0c9440:	8fa30248 */ 	lw	$v1,0x248($sp)
/*  f0c9444:	11000010 */ 	beqz	$t0,.L0f0c9488
/*  f0c9448:	2861003d */ 	slti	$at,$v1,0x3d
/*  f0c944c:	1420000e */ 	bnez	$at,.L0f0c9488
/*  f0c9450:	2469ffc4 */ 	addiu	$t1,$v1,-60
/*  f0c9454:	44895000 */ 	mtc1	$t1,$f10
/*  f0c9458:	3c013f80 */ 	lui	$at,0x3f80
/*  f0c945c:	44819000 */ 	mtc1	$at,$f18
/*  f0c9460:	46805420 */ 	cvt.s.w	$f16,$f10
/*  f0c9464:	3c013f80 */ 	lui	$at,0x3f80
/*  f0c9468:	46028003 */ 	div.s	$f0,$f16,$f2
/*  f0c946c:	4600903c */ 	c.lt.s	$f18,$f0
/*  f0c9470:	e7a001f8 */ 	swc1	$f0,0x1f8($sp)
/*  f0c9474:	45000007 */ 	bc1f	.L0f0c9494
/*  f0c9478:	00000000 */ 	nop
/*  f0c947c:	44810000 */ 	mtc1	$at,$f0
/*  f0c9480:	10000004 */ 	b	.L0f0c9494
/*  f0c9484:	e7a001f8 */ 	swc1	$f0,0x1f8($sp)
.L0f0c9488:
/*  f0c9488:	44800000 */ 	mtc1	$zero,$f0
/*  f0c948c:	00000000 */ 	nop
/*  f0c9490:	e7a001f8 */ 	swc1	$f0,0x1f8($sp)
.L0f0c9494:
/*  f0c9494:	12e0005c */ 	beqz	$s7,.L0f0c9608
/*  f0c9498:	00000000 */ 	nop
/*  f0c949c:	84a2024c */ 	lh	$v0,0x24c($a1)
/*  f0c94a0:	2841fffe */ 	slti	$at,$v0,-2
/*  f0c94a4:	10200009 */ 	beqz	$at,.L0f0c94cc
/*  f0c94a8:	00565021 */ 	addu	$t2,$v0,$s6
/*  f0c94ac:	a4aa024c */ 	sh	$t2,0x24c($a1)
/*  f0c94b0:	8e450284 */ 	lw	$a1,0x284($s2)
/*  f0c94b4:	84ab024c */ 	lh	$t3,0x24c($a1)
/*  f0c94b8:	2961fffe */ 	slti	$at,$t3,-2
/*  f0c94bc:	14200052 */ 	bnez	$at,.L0f0c9608
/*  f0c94c0:	00000000 */ 	nop
/*  f0c94c4:	10000050 */ 	b	.L0f0c9608
/*  f0c94c8:	a4a0024c */ 	sh	$zero,0x24c($a1)
.L0f0c94cc:
/*  f0c94cc:	1ac0004e */ 	blez	$s6,.L0f0c9608
/*  f0c94d0:	00008025 */ 	or	$s0,$zero,$zero
/*  f0c94d4:	97ac019e */ 	lhu	$t4,0x19e($sp)
/*  f0c94d8:	2413ffff */ 	addiu	$s3,$zero,-1
/*  f0c94dc:	31918000 */ 	andi	$s1,$t4,0x8000
/*  f0c94e0:	00152e00 */ 	sll	$a1,$s5,0x18
.L0f0c94e4:
/*  f0c94e4:	00057603 */ 	sra	$t6,$a1,0x18
/*  f0c94e8:	01c02825 */ 	or	$a1,$t6,$zero
/*  f0c94ec:	02002025 */ 	or	$a0,$s0,$zero
/*  f0c94f0:	0c00529e */ 	jal	joyGetButtonsOnSample
/*  f0c94f4:	3226ffff */ 	andi	$a2,$s1,0xffff
/*  f0c94f8:	14400009 */ 	bnez	$v0,.L0f0c9520
/*  f0c94fc:	02002025 */ 	or	$a0,$s0,$zero
/*  f0c9500:	97b800da */ 	lhu	$t8,0xda($sp)
/*  f0c9504:	00142e00 */ 	sll	$a1,$s4,0x18
/*  f0c9508:	00057e03 */ 	sra	$t7,$a1,0x18
/*  f0c950c:	01e02825 */ 	or	$a1,$t7,$zero
/*  f0c9510:	0c00529e */ 	jal	joyGetButtonsOnSample
/*  f0c9514:	33068000 */ 	andi	$a2,$t8,0x8000
/*  f0c9518:	50400028 */ 	beqzl	$v0,.L0f0c95bc
/*  f0c951c:	8e490284 */ 	lw	$t1,0x284($s2)
.L0f0c9520:
/*  f0c9520:	8e480284 */ 	lw	$t0,0x284($s2)
/*  f0c9524:	97aa00ea */ 	lhu	$t2,0xea($sp)
/*  f0c9528:	8509024c */ 	lh	$t1,0x24c($t0)
/*  f0c952c:	31462000 */ 	andi	$a2,$t2,0x2000
/*  f0c9530:	2921ffff */ 	slti	$at,$t1,-1
/*  f0c9534:	14200031 */ 	bnez	$at,.L0f0c95fc
/*  f0c9538:	02002025 */ 	or	$a0,$s0,$zero
/*  f0c953c:	83a500ef */ 	lb	$a1,0xef($sp)
/*  f0c9540:	0c0052d4 */ 	jal	joyGetButtonsPressedOnSample
/*  f0c9544:	afa6004c */ 	sw	$a2,0x4c($sp)
/*  f0c9548:	10400006 */ 	beqz	$v0,.L0f0c9564
/*  f0c954c:	8fa6004c */ 	lw	$a2,0x4c($sp)
/*  f0c9550:	8fac01fc */ 	lw	$t4,0x1fc($sp)
/*  f0c9554:	8e4e0284 */ 	lw	$t6,0x284($s2)
/*  f0c9558:	258d0001 */ 	addiu	$t5,$t4,0x1
/*  f0c955c:	afad01fc */ 	sw	$t5,0x1fc($sp)
/*  f0c9560:	a5d3024c */ 	sh	$s3,0x24c($t6)
.L0f0c9564:
/*  f0c9564:	8e4f0284 */ 	lw	$t7,0x284($s2)
/*  f0c9568:	02002025 */ 	or	$a0,$s0,$zero
/*  f0c956c:	85f8024c */ 	lh	$t8,0x24c($t7)
/*  f0c9570:	07020023 */ 	bltzl	$t8,.L0f0c9600
/*  f0c9574:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f0c9578:	0c00529e */ 	jal	joyGetButtonsOnSample
/*  f0c957c:	83a500ef */ 	lb	$a1,0xef($sp)
/*  f0c9580:	5440001f */ 	bnezl	$v0,.L0f0c9600
/*  f0c9584:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f0c9588:	8e450284 */ 	lw	$a1,0x284($s2)
/*  f0c958c:	84a2024c */ 	lh	$v0,0x24c($a1)
/*  f0c9590:	28410010 */ 	slti	$at,$v0,0xd
/*  f0c9594:	14200006 */ 	bnez	$at,.L0f0c95b0
/*  f0c9598:	24480001 */ 	addiu	$t0,$v0,0x1
/*  f0c959c:	0fc3fbda */ 	jal	amOpen
/*  f0c95a0:	00000000 */ 	nop
/*  f0c95a4:	8e590284 */ 	lw	$t9,0x284($s2)
/*  f0c95a8:	10000014 */ 	b	.L0f0c95fc
/*  f0c95ac:	a733024c */ 	sh	$s3,0x24c($t9)
.L0f0c95b0:
/*  f0c95b0:	10000012 */ 	b	.L0f0c95fc
/*  f0c95b4:	a4a8024c */ 	sh	$t0,0x24c($a1)
/*  f0c95b8:	8e490284 */ 	lw	$t1,0x284($s2)
.L0f0c95bc:
/*  f0c95bc:	852a024c */ 	lh	$t2,0x24c($t1)
/*  f0c95c0:	5940000d */ 	blezl	$t2,.L0f0c95f8
/*  f0c95c4:	8e4d0284 */ 	lw	$t5,0x284($s2)
/*  f0c95c8:	12e00007 */ 	beqz	$s7,.L0f0c95e8
/*  f0c95cc:	02002025 */ 	or	$a0,$s0,$zero
/*  f0c95d0:	97ab00ea */ 	lhu	$t3,0xea($sp)
/*  f0c95d4:	83a500ef */ 	lb	$a1,0xef($sp)
/*  f0c95d8:	0c00529e */ 	jal	joyGetButtonsOnSample
/*  f0c95dc:	31662000 */ 	andi	$a2,$t3,0x2000
/*  f0c95e0:	54400005 */ 	bnezl	$v0,.L0f0c95f8
/*  f0c95e4:	8e4d0284 */ 	lw	$t5,0x284($s2)
.L0f0c95e8:
/*  f0c95e8:	8fa20200 */ 	lw	$v0,0x200($sp)
/*  f0c95ec:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f0c95f0:	afa20200 */ 	sw	$v0,0x200($sp)
/*  f0c95f4:	8e4d0284 */ 	lw	$t5,0x284($s2)
.L0f0c95f8:
/*  f0c95f8:	a5a0024c */ 	sh	$zero,0x24c($t5)
.L0f0c95fc:
/*  f0c95fc:	26100001 */ 	addiu	$s0,$s0,0x1
.L0f0c9600:
/*  f0c9600:	5616ffb8 */ 	bnel	$s0,$s6,.L0f0c94e4
/*  f0c9604:	00152e00 */ 	sll	$a1,$s5,0x18
.L0f0c9608:
/*  f0c9608:	12e0005e */ 	beqz	$s7,.L0f0c9784
/*  f0c960c:	2413ffff */ 	addiu	$s3,$zero,-1
/*  f0c9610:	1ac0005c */ 	blez	$s6,.L0f0c9784
/*  f0c9614:	00008025 */ 	or	$s0,$zero,$zero
/*  f0c9618:	97ae019e */ 	lhu	$t6,0x19e($sp)
/*  f0c961c:	31cf4000 */ 	andi	$t7,$t6,0x4000
/*  f0c9620:	afaf0044 */ 	sw	$t7,0x44($sp)
/*  f0c9624:	00152e00 */ 	sll	$a1,$s5,0x18
.L0f0c9628:
/*  f0c9628:	0005c603 */ 	sra	$t8,$a1,0x18
/*  f0c962c:	8fa60044 */ 	lw	$a2,0x44($sp)
/*  f0c9630:	03002825 */ 	or	$a1,$t8,$zero
/*  f0c9634:	0c00529e */ 	jal	joyGetButtonsOnSample
/*  f0c9638:	02002025 */ 	or	$a0,$s0,$zero
/*  f0c963c:	14400009 */ 	bnez	$v0,.L0f0c9664
/*  f0c9640:	02002025 */ 	or	$a0,$s0,$zero
/*  f0c9644:	97a800da */ 	lhu	$t0,0xda($sp)
/*  f0c9648:	00142e00 */ 	sll	$a1,$s4,0x18
/*  f0c964c:	0005ce03 */ 	sra	$t9,$a1,0x18
/*  f0c9650:	03202825 */ 	or	$a1,$t9,$zero
/*  f0c9654:	0c00529e */ 	jal	joyGetButtonsOnSample
/*  f0c9658:	31064000 */ 	andi	$a2,$t0,0x4000
/*  f0c965c:	5040003e */ 	beqzl	$v0,.L0f0c9758
/*  f0c9660:	8e450284 */ 	lw	$a1,0x284($s2)
.L0f0c9664:
/*  f0c9664:	8e4a0284 */ 	lw	$t2,0x284($s2)
/*  f0c9668:	97ab00ea */ 	lhu	$t3,0xea($sp)
/*  f0c966c:	83a500ef */ 	lb	$a1,0xef($sp)
/*  f0c9670:	8544024e */ 	lh	$a0,0x24e($t2)
/*  f0c9674:	31662000 */ 	andi	$a2,$t3,0x2000
/*  f0c9678:	2881ffff */ 	slti	$at,$a0,-1
/*  f0c967c:	5420002f */ 	bnezl	$at,.L0f0c973c
/*  f0c9680:	2881fffe */ 	slti	$at,$a0,-2
/*  f0c9684:	0c0052d4 */ 	jal	joyGetButtonsPressedOnSample
/*  f0c9688:	02002025 */ 	or	$a0,$s0,$zero
/*  f0c968c:	5040000e */ 	beqzl	$v0,.L0f0c96c8
/*  f0c9690:	8e450284 */ 	lw	$a1,0x284($s2)
/*  f0c9694:	8e4d0284 */ 	lw	$t5,0x284($s2)
/*  f0c9698:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f0c969c:	85a4024e */ 	lh	$a0,0x24e($t5)
/*  f0c96a0:	04820009 */ 	bltzl	$a0,.L0f0c96c8
/*  f0c96a4:	8e450284 */ 	lw	$a1,0x284($s2)
/*  f0c96a8:	0fc2a257 */ 	jal	bgunConsiderToggleGunFunction
/*  f0c96ac:	00003025 */ 	or	$a2,$zero,$zero
/*  f0c96b0:	50400005 */ 	beqzl	$v0,.L0f0c96c8
/*  f0c96b4:	8e450284 */ 	lw	$a1,0x284($s2)
/*  f0c96b8:	8e4f0284 */ 	lw	$t7,0x284($s2)
/*  f0c96bc:	240efffd */ 	addiu	$t6,$zero,-3
/*  f0c96c0:	a5ee024e */ 	sh	$t6,0x24e($t7)
/*  f0c96c4:	8e450284 */ 	lw	$a1,0x284($s2)
.L0f0c96c8:
/*  f0c96c8:	84a4024e */ 	lh	$a0,0x24e($a1)
/*  f0c96cc:	0480002a */ 	bltz	$a0,.L0f0c9778
/*  f0c96d0:	2881001a */ 	slti	$at,$a0,0x15
/*  f0c96d4:	14200016 */ 	bnez	$at,.L0f0c9730
/*  f0c96d8:	248b0001 */ 	addiu	$t3,$a0,0x1
/*  f0c96dc:	00002825 */ 	or	$a1,$zero,$zero
/*  f0c96e0:	0fc2a257 */ 	jal	bgunConsiderToggleGunFunction
/*  f0c96e4:	00003025 */ 	or	$a2,$zero,$zero
/*  f0c96e8:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0c96ec:	54410005 */ 	bnel	$v0,$at,.L0f0c9704
/*  f0c96f0:	24010002 */ 	addiu	$at,$zero,0x2
/*  f0c96f4:	8e580284 */ 	lw	$t8,0x284($s2)
/*  f0c96f8:	1000001f */ 	b	.L0f0c9778
/*  f0c96fc:	a713024e */ 	sh	$s3,0x24e($t8)
/*  f0c9700:	24010002 */ 	addiu	$at,$zero,0x2
.L0f0c9704:
/*  f0c9704:	54410006 */ 	bnel	$v0,$at,.L0f0c9720
/*  f0c9708:	8e450284 */ 	lw	$a1,0x284($s2)
/*  f0c970c:	8e480284 */ 	lw	$t0,0x284($s2)
/*  f0c9710:	2419fffe */ 	addiu	$t9,$zero,-2
/*  f0c9714:	10000018 */ 	b	.L0f0c9778
/*  f0c9718:	a519024e */ 	sh	$t9,0x24e($t0)
/*  f0c971c:	8e450284 */ 	lw	$a1,0x284($s2)
.L0f0c9720:
/*  f0c9720:	84a9024e */ 	lh	$t1,0x24e($a1)
/*  f0c9724:	252a0001 */ 	addiu	$t2,$t1,0x1
/*  f0c9728:	10000013 */ 	b	.L0f0c9778
/*  f0c972c:	a4aa024e */ 	sh	$t2,0x24e($a1)
.L0f0c9730:
/*  f0c9730:	10000011 */ 	b	.L0f0c9778
/*  f0c9734:	a4ab024e */ 	sh	$t3,0x24e($a1)
/*  f0c9738:	2881fffe */ 	slti	$at,$a0,-2
.L0f0c973c:
/*  f0c973c:	1420000e */ 	bnez	$at,.L0f0c9778
/*  f0c9740:	00002825 */ 	or	$a1,$zero,$zero
/*  f0c9744:	0fc2a257 */ 	jal	bgunConsiderToggleGunFunction
/*  f0c9748:	00003025 */ 	or	$a2,$zero,$zero
/*  f0c974c:	1000000b */ 	b	.L0f0c977c
/*  f0c9750:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f0c9754:	8e450284 */ 	lw	$a1,0x284($s2)
.L0f0c9758:
/*  f0c9758:	8fad01c0 */ 	lw	$t5,0x1c0($sp)
/*  f0c975c:	84ac024e */ 	lh	$t4,0x24e($a1)
/*  f0c9760:	25ae0001 */ 	addiu	$t6,$t5,0x1
/*  f0c9764:	19800002 */ 	blez	$t4,.L0f0c9770
/*  f0c9768:	00000000 */ 	nop
/*  f0c976c:	afae01c0 */ 	sw	$t6,0x1c0($sp)
.L0f0c9770:
/*  f0c9770:	0fc2a314 */ 	jal	bgun0f0a8c50
/*  f0c9774:	a4a0024e */ 	sh	$zero,0x24e($a1)
.L0f0c9778:
/*  f0c9778:	26100001 */ 	addiu	$s0,$s0,0x1
.L0f0c977c:
/*  f0c977c:	5616ffaa */ 	bnel	$s0,$s6,.L0f0c9628
/*  f0c9780:	00152e00 */ 	sll	$a1,$s5,0x18
.L0f0c9784:
/*  f0c9784:	8faf01a8 */ 	lw	$t7,0x1a8($sp)
/*  f0c9788:	11e0002b */ 	beqz	$t7,.L0f0c9838
/*  f0c978c:	00000000 */ 	nop
/*  f0c9790:	8e580284 */ 	lw	$t8,0x284($s2)
/*  f0c9794:	8fa800dc */ 	lw	$t0,0xdc($sp)
/*  f0c9798:	8f190120 */ 	lw	$t9,0x120($t8)
/*  f0c979c:	13200026 */ 	beqz	$t9,.L0f0c9838
/*  f0c97a0:	00000000 */ 	nop
/*  f0c97a4:	05010011 */ 	bgez	$t0,.L0f0c97ec
/*  f0c97a8:	00084823 */ 	negu	$t1,$t0
/*  f0c97ac:	44892000 */ 	mtc1	$t1,$f4
/*  f0c97b0:	3c01428c */ 	lui	$at,0x428c
/*  f0c97b4:	44814000 */ 	mtc1	$at,$f8
/*  f0c97b8:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f0c97bc:	3c013f80 */ 	lui	$at,0x3f80
/*  f0c97c0:	44815000 */ 	mtc1	$at,$f10
/*  f0c97c4:	3c013f80 */ 	lui	$at,0x3f80
/*  f0c97c8:	46083303 */ 	div.s	$f12,$f6,$f8
/*  f0c97cc:	460c503c */ 	c.lt.s	$f10,$f12
/*  f0c97d0:	00000000 */ 	nop
/*  f0c97d4:	45020004 */ 	bc1fl	.L0f0c97e8
/*  f0c97d8:	460c6300 */ 	add.s	$f12,$f12,$f12
/*  f0c97dc:	44816000 */ 	mtc1	$at,$f12
/*  f0c97e0:	00000000 */ 	nop
/*  f0c97e4:	460c6300 */ 	add.s	$f12,$f12,$f12
.L0f0c97e8:
/*  f0c97e8:	e7ac0210 */ 	swc1	$f12,0x210($sp)
.L0f0c97ec:
/*  f0c97ec:	8faa00dc */ 	lw	$t2,0xdc($sp)
/*  f0c97f0:	19400011 */ 	blez	$t2,.L0f0c9838
/*  f0c97f4:	00000000 */ 	nop
/*  f0c97f8:	448a8000 */ 	mtc1	$t2,$f16
/*  f0c97fc:	3c01428c */ 	lui	$at,0x428c
/*  f0c9800:	44812000 */ 	mtc1	$at,$f4
/*  f0c9804:	468084a0 */ 	cvt.s.w	$f18,$f16
/*  f0c9808:	3c013f80 */ 	lui	$at,0x3f80
/*  f0c980c:	44813000 */ 	mtc1	$at,$f6
/*  f0c9810:	3c013f80 */ 	lui	$at,0x3f80
/*  f0c9814:	46049303 */ 	div.s	$f12,$f18,$f4
/*  f0c9818:	460c303c */ 	c.lt.s	$f6,$f12
/*  f0c981c:	00000000 */ 	nop
/*  f0c9820:	45020004 */ 	bc1fl	.L0f0c9834
/*  f0c9824:	460c6300 */ 	add.s	$f12,$f12,$f12
/*  f0c9828:	44816000 */ 	mtc1	$at,$f12
/*  f0c982c:	00000000 */ 	nop
/*  f0c9830:	460c6300 */ 	add.s	$f12,$f12,$f12
.L0f0c9834:
/*  f0c9834:	e7ac0214 */ 	swc1	$f12,0x214($sp)
.L0f0c9838:
/*  f0c9838:	12e0005a */ 	beqz	$s7,.L0f0c99a4
/*  f0c983c:	00000000 */ 	nop
/*  f0c9840:	1ac00058 */ 	blez	$s6,.L0f0c99a4
/*  f0c9844:	00008025 */ 	or	$s0,$zero,$zero
/*  f0c9848:	8fab01a8 */ 	lw	$t3,0x1a8($sp)
.L0f0c984c:
/*  f0c984c:	00106080 */ 	sll	$t4,$s0,0x2
/*  f0c9850:	03ac6821 */ 	addu	$t5,$sp,$t4
/*  f0c9854:	55600034 */ 	bnezl	$t3,.L0f0c9928
/*  f0c9858:	8e4a0288 */ 	lw	$t2,0x288($s2)
/*  f0c985c:	8dad014c */ 	lw	$t5,0x14c($t5)
/*  f0c9860:	00142e00 */ 	sll	$a1,$s4,0x18
/*  f0c9864:	00057603 */ 	sra	$t6,$a1,0x18
/*  f0c9868:	11a0002e */ 	beqz	$t5,.L0f0c9924
/*  f0c986c:	02002025 */ 	or	$a0,$s0,$zero
/*  f0c9870:	0c005241 */ 	jal	joyGetStickYOnSample
/*  f0c9874:	01c02825 */ 	or	$a1,$t6,$zero
/*  f0c9878:	2841001f */ 	slti	$at,$v0,0x1f
/*  f0c987c:	14200011 */ 	bnez	$at,.L0f0c98c4
/*  f0c9880:	02002025 */ 	or	$a0,$s0,$zero
/*  f0c9884:	00142e00 */ 	sll	$a1,$s4,0x18
/*  f0c9888:	00057e03 */ 	sra	$t7,$a1,0x18
/*  f0c988c:	0c005270 */ 	jal	joyGetStickYOnSampleIndex
/*  f0c9890:	01e02825 */ 	or	$a1,$t7,$zero
/*  f0c9894:	2841001f */ 	slti	$at,$v0,0x1f
/*  f0c9898:	1020000a */ 	beqz	$at,.L0f0c98c4
/*  f0c989c:	8fa20218 */ 	lw	$v0,0x218($sp)
/*  f0c98a0:	10400003 */ 	beqz	$v0,.L0f0c98b0
/*  f0c98a4:	2442ffff */ 	addiu	$v0,$v0,-1
/*  f0c98a8:	10000004 */ 	b	.L0f0c98bc
/*  f0c98ac:	afa20218 */ 	sw	$v0,0x218($sp)
.L0f0c98b0:
/*  f0c98b0:	8fa2021c */ 	lw	$v0,0x21c($sp)
/*  f0c98b4:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f0c98b8:	afa2021c */ 	sw	$v0,0x21c($sp)
.L0f0c98bc:
/*  f0c98bc:	8e580284 */ 	lw	$t8,0x284($s2)
/*  f0c98c0:	af130260 */ 	sw	$s3,0x260($t8)
.L0f0c98c4:
/*  f0c98c4:	00142e00 */ 	sll	$a1,$s4,0x18
/*  f0c98c8:	0005ce03 */ 	sra	$t9,$a1,0x18
/*  f0c98cc:	03202825 */ 	or	$a1,$t9,$zero
/*  f0c98d0:	0c005241 */ 	jal	joyGetStickYOnSample
/*  f0c98d4:	02002025 */ 	or	$a0,$s0,$zero
/*  f0c98d8:	2841ffe2 */ 	slti	$at,$v0,-30
/*  f0c98dc:	10200011 */ 	beqz	$at,.L0f0c9924
/*  f0c98e0:	02002025 */ 	or	$a0,$s0,$zero
/*  f0c98e4:	00142e00 */ 	sll	$a1,$s4,0x18
/*  f0c98e8:	00054603 */ 	sra	$t0,$a1,0x18
/*  f0c98ec:	0c005270 */ 	jal	joyGetStickYOnSampleIndex
/*  f0c98f0:	01002825 */ 	or	$a1,$t0,$zero
/*  f0c98f4:	2841ffe2 */ 	slti	$at,$v0,-30
/*  f0c98f8:	1420000a */ 	bnez	$at,.L0f0c9924
/*  f0c98fc:	8fa2021c */ 	lw	$v0,0x21c($sp)
/*  f0c9900:	10400003 */ 	beqz	$v0,.L0f0c9910
/*  f0c9904:	2442ffff */ 	addiu	$v0,$v0,-1
/*  f0c9908:	10000004 */ 	b	.L0f0c991c
/*  f0c990c:	afa2021c */ 	sw	$v0,0x21c($sp)
.L0f0c9910:
/*  f0c9910:	8fa20218 */ 	lw	$v0,0x218($sp)
/*  f0c9914:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f0c9918:	afa20218 */ 	sw	$v0,0x218($sp)
.L0f0c991c:
/*  f0c991c:	8e490284 */ 	lw	$t1,0x284($s2)
/*  f0c9920:	ad330260 */ 	sw	$s3,0x260($t1)
.L0f0c9924:
/*  f0c9924:	8e4a0288 */ 	lw	$t2,0x288($s2)
.L0f0c9928:
/*  f0c9928:	0fc549fb */ 	jal	optionsGetAimControl
/*  f0c992c:	8d440070 */ 	lw	$a0,0x70($t2)
/*  f0c9930:	14400019 */ 	bnez	$v0,.L0f0c9998
/*  f0c9934:	00105880 */ 	sll	$t3,$s0,0x2
/*  f0c9938:	03ab6021 */ 	addu	$t4,$sp,$t3
/*  f0c993c:	8d8c014c */ 	lw	$t4,0x14c($t4)
/*  f0c9940:	51800008 */ 	beqzl	$t4,.L0f0c9964
/*  f0c9944:	8e450284 */ 	lw	$a1,0x284($s2)
/*  f0c9948:	8e450284 */ 	lw	$a1,0x284($s2)
/*  f0c994c:	8ca20260 */ 	lw	$v0,0x260($a1)
/*  f0c9950:	04400011 */ 	bltz	$v0,.L0f0c9998
/*  f0c9954:	244d0001 */ 	addiu	$t5,$v0,0x1
/*  f0c9958:	1000000f */ 	b	.L0f0c9998
/*  f0c995c:	acad0260 */ 	sw	$t5,0x260($a1)
/*  f0c9960:	8e450284 */ 	lw	$a1,0x284($s2)
.L0f0c9964:
/*  f0c9964:	8ca20260 */ 	lw	$v0,0x260($a1)
/*  f0c9968:	1840000a */ 	blez	$v0,.L0f0c9994
/*  f0c996c:	2841000f */ 	slti	$at,$v0,0xc
/*  f0c9970:	10200008 */ 	beqz	$at,.L0f0c9994
/*  f0c9974:	8fa20218 */ 	lw	$v0,0x218($sp)
/*  f0c9978:	10400003 */ 	beqz	$v0,.L0f0c9988
/*  f0c997c:	2442ffff */ 	addiu	$v0,$v0,-1
/*  f0c9980:	10000004 */ 	b	.L0f0c9994
/*  f0c9984:	afa20218 */ 	sw	$v0,0x218($sp)
.L0f0c9988:
/*  f0c9988:	8fa2021c */ 	lw	$v0,0x21c($sp)
/*  f0c998c:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f0c9990:	afa2021c */ 	sw	$v0,0x21c($sp)
.L0f0c9994:
/*  f0c9994:	aca00260 */ 	sw	$zero,0x260($a1)
.L0f0c9998:
/*  f0c9998:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f0c999c:	5616ffab */ 	bnel	$s0,$s6,.L0f0c984c
/*  f0c99a0:	8fab01a8 */ 	lw	$t3,0x1a8($sp)
.L0f0c99a4:
/*  f0c99a4:	0fc331a0 */ 	jal	bmoveGetCrouchPos
/*  f0c99a8:	00000000 */ 	nop
/*  f0c99ac:	1440001d */ 	bnez	$v0,.L0f0c9a24
/*  f0c99b0:	00000000 */ 	nop
/*  f0c99b4:	8e450284 */ 	lw	$a1,0x284($s2)
/*  f0c99b8:	3c01c2b4 */ 	lui	$at,0xc2b4
/*  f0c99bc:	44814000 */ 	mtc1	$at,$f8
/*  f0c99c0:	c4aa00b4 */ 	lwc1	$f10,0xb4($a1)
/*  f0c99c4:	460a4032 */ 	c.eq.s	$f8,$f10
/*  f0c99c8:	00000000 */ 	nop
/*  f0c99cc:	45000015 */ 	bc1f	.L0f0c9a24
/*  f0c99d0:	00000000 */ 	nop
/*  f0c99d4:	8e4e0314 */ 	lw	$t6,0x314($s2)
/*  f0c99d8:	11c00012 */ 	beqz	$t6,.L0f0c9a24
/*  f0c99dc:	00000000 */ 	nop
/*  f0c99e0:	8e4f0298 */ 	lw	$t7,0x298($s2)
/*  f0c99e4:	05e1000f */ 	bgez	$t7,.L0f0c9a24
/*  f0c99e8:	00000000 */ 	nop
/*  f0c99ec:	8ca40120 */ 	lw	$a0,0x120($a1)
/*  f0c99f0:	8fa201a8 */ 	lw	$v0,0x1a8($sp)
/*  f0c99f4:	0004c02b */ 	sltu	$t8,$zero,$a0
/*  f0c99f8:	13000009 */ 	beqz	$t8,.L0f0c9a20
/*  f0c99fc:	03002025 */ 	or	$a0,$t8,$zero
/*  f0c9a00:	2c440001 */ 	sltiu	$a0,$v0,0x1
/*  f0c9a04:	50800007 */ 	beqzl	$a0,.L0f0c9a24
/*  f0c9a08:	afa40234 */ 	sw	$a0,0x234($sp)
/*  f0c9a0c:	00142600 */ 	sll	$a0,$s4,0x18
/*  f0c9a10:	00044603 */ 	sra	$t0,$a0,0x18
/*  f0c9a14:	0c0053ae */ 	jal	joyGetStickY
/*  f0c9a18:	01002025 */ 	or	$a0,$t0,$zero
/*  f0c9a1c:	2844ffe2 */ 	slti	$a0,$v0,-30
.L0f0c9a20:
/*  f0c9a20:	afa40234 */ 	sw	$a0,0x234($sp)
.L0f0c9a24:
/*  f0c9a24:	0fc2866a */ 	jal	bgunGetWeaponNum
/*  f0c9a28:	00002025 */ 	or	$a0,$zero,$zero
/*  f0c9a2c:	24010016 */ 	addiu	$at,$zero,0x16
/*  f0c9a30:	54410011 */ 	bnel	$v0,$at,.L0f0c9a78
/*  f0c9a34:	97a201a2 */ 	lhu	$v0,0x1a2($sp)
/*  f0c9a38:	8e450284 */ 	lw	$a1,0x284($s2)
/*  f0c9a3c:	8ca20120 */ 	lw	$v0,0x120($a1)
/*  f0c9a40:	50400004 */ 	beqzl	$v0,.L0f0c9a54
/*  f0c9a44:	0002202b */ 	sltu	$a0,$zero,$v0
/*  f0c9a48:	afa001c8 */ 	sw	$zero,0x1c8($sp)
/*  f0c9a4c:	8ca20120 */ 	lw	$v0,0x120($a1)
/*  f0c9a50:	0002202b */ 	sltu	$a0,$zero,$v0
.L0f0c9a54:
/*  f0c9a54:	10800006 */ 	beqz	$a0,.L0f0c9a70
/*  f0c9a58:	83a900e9 */ 	lb	$t1,0xe9($sp)
/*  f0c9a5c:	2924ffe2 */ 	slti	$a0,$t1,-30
/*  f0c9a60:	54800004 */ 	bnezl	$a0,.L0f0c9a74
/*  f0c9a64:	afa40230 */ 	sw	$a0,0x230($sp)
/*  f0c9a68:	2924001f */ 	slti	$a0,$t1,0x1f
/*  f0c9a6c:	38840001 */ 	xori	$a0,$a0,0x1
.L0f0c9a70:
/*  f0c9a70:	afa40230 */ 	sw	$a0,0x230($sp)
.L0f0c9a74:
/*  f0c9a74:	97a201a2 */ 	lhu	$v0,0x1a2($sp)
.L0f0c9a78:
/*  f0c9a78:	afa00220 */ 	sw	$zero,0x220($sp)
/*  f0c9a7c:	afa00224 */ 	sw	$zero,0x224($sp)
/*  f0c9a80:	304a8000 */ 	andi	$t2,$v0,0x8000
/*  f0c9a84:	11400003 */ 	beqz	$t2,.L0f0c9a94
/*  f0c9a88:	97ab01a0 */ 	lhu	$t3,0x1a0($sp)
/*  f0c9a8c:	316c4000 */ 	andi	$t4,$t3,0x4000
/*  f0c9a90:	15800012 */ 	bnez	$t4,.L0f0c9adc
.L0f0c9a94:
/*  f0c9a94:	304d4000 */ 	andi	$t5,$v0,0x4000
/*  f0c9a98:	11a00004 */ 	beqz	$t5,.L0f0c9aac
/*  f0c9a9c:	97ae01a0 */ 	lhu	$t6,0x1a0($sp)
/*  f0c9aa0:	31cf8000 */ 	andi	$t7,$t6,0x8000
/*  f0c9aa4:	55e0000e */ 	bnezl	$t7,.L0f0c9ae0
/*  f0c9aa8:	8fac01ac */ 	lw	$t4,0x1ac($sp)
.L0f0c9aac:
/*  f0c9aac:	97a200e6 */ 	lhu	$v0,0xe6($sp)
/*  f0c9ab0:	97b900e4 */ 	lhu	$t9,0xe4($sp)
/*  f0c9ab4:	30588000 */ 	andi	$t8,$v0,0x8000
/*  f0c9ab8:	13000002 */ 	beqz	$t8,.L0f0c9ac4
/*  f0c9abc:	33284000 */ 	andi	$t0,$t9,0x4000
/*  f0c9ac0:	15000006 */ 	bnez	$t0,.L0f0c9adc
.L0f0c9ac4:
/*  f0c9ac4:	30494000 */ 	andi	$t1,$v0,0x4000
/*  f0c9ac8:	11200011 */ 	beqz	$t1,.L0f0c9b10
/*  f0c9acc:	97aa00e4 */ 	lhu	$t2,0xe4($sp)
/*  f0c9ad0:	314b8000 */ 	andi	$t3,$t2,0x8000
/*  f0c9ad4:	5160000f */ 	beqzl	$t3,.L0f0c9b14
/*  f0c9ad8:	8e450284 */ 	lw	$a1,0x284($s2)
.L0f0c9adc:
/*  f0c9adc:	8fac01ac */ 	lw	$t4,0x1ac($sp)
.L0f0c9ae0:
/*  f0c9ae0:	24010022 */ 	addiu	$at,$zero,0x22
/*  f0c9ae4:	2402fffe */ 	addiu	$v0,$zero,-2
/*  f0c9ae8:	15810009 */ 	bne	$t4,$at,.L0f0c9b10
/*  f0c9aec:	240d0001 */ 	addiu	$t5,$zero,0x1
/*  f0c9af0:	8e4e0284 */ 	lw	$t6,0x284($s2)
/*  f0c9af4:	afad0228 */ 	sw	$t5,0x228($sp)
/*  f0c9af8:	afa001fc */ 	sw	$zero,0x1fc($sp)
/*  f0c9afc:	afa00200 */ 	sw	$zero,0x200($sp)
/*  f0c9b00:	afa001c0 */ 	sw	$zero,0x1c0($sp)
/*  f0c9b04:	a5c2024c */ 	sh	$v0,0x24c($t6)
/*  f0c9b08:	8e4f0284 */ 	lw	$t7,0x284($s2)
/*  f0c9b0c:	a5e2024e */ 	sh	$v0,0x24e($t7)
.L0f0c9b10:
/*  f0c9b10:	8e450284 */ 	lw	$a1,0x284($s2)
.L0f0c9b14:
/*  f0c9b14:	97a900ea */ 	lhu	$t1,0xea($sp)
/*  f0c9b18:	8cb80120 */ 	lw	$t8,0x120($a1)
/*  f0c9b1c:	afb80208 */ 	sw	$t8,0x208($sp)
/*  f0c9b20:	8cb90120 */ 	lw	$t9,0x120($a1)
/*  f0c9b24:	afb9020c */ 	sw	$t9,0x20c($sp)
/*  f0c9b28:	8ca80274 */ 	lw	$t0,0x274($a1)
/*  f0c9b2c:	31252000 */ 	andi	$a1,$t1,0x2000
/*  f0c9b30:	11000007 */ 	beqz	$t0,.L0f0c9b50
/*  f0c9b34:	00000000 */ 	nop
/*  f0c9b38:	0c0053d8 */ 	jal	joyGetButtons
/*  f0c9b3c:	83a400ef */ 	lb	$a0,0xef($sp)
/*  f0c9b40:	14400003 */ 	bnez	$v0,.L0f0c9b50
/*  f0c9b44:	00000000 */ 	nop
/*  f0c9b48:	8e4b0284 */ 	lw	$t3,0x284($s2)
/*  f0c9b4c:	ad600274 */ 	sw	$zero,0x274($t3)
.L0f0c9b50:
/*  f0c9b50:	0fc2866a */ 	jal	bgunGetWeaponNum
/*  f0c9b54:	00002025 */ 	or	$a0,$zero,$zero
/*  f0c9b58:	00402025 */ 	or	$a0,$v0,$zero
/*  f0c9b5c:	0fc2c5f0 */ 	jal	weaponHasFlag
/*  f0c9b60:	3c058000 */ 	lui	$a1,0x8000
/*  f0c9b64:	50400012 */ 	beqzl	$v0,.L0f0c9bb0
/*  f0c9b68:	8e480284 */ 	lw	$t0,0x284($s2)
/*  f0c9b6c:	12e0000d */ 	beqz	$s7,.L0f0c9ba4
/*  f0c9b70:	97ac00ea */ 	lhu	$t4,0xea($sp)
/*  f0c9b74:	83a400ef */ 	lb	$a0,0xef($sp)
/*  f0c9b78:	0c005408 */ 	jal	joyGetButtonsPressedThisFrame
/*  f0c9b7c:	31852000 */ 	andi	$a1,$t4,0x2000
/*  f0c9b80:	10400008 */ 	beqz	$v0,.L0f0c9ba4
/*  f0c9b84:	00000000 */ 	nop
/*  f0c9b88:	8e4e0284 */ 	lw	$t6,0x284($s2)
/*  f0c9b8c:	8fb801c0 */ 	lw	$t8,0x1c0($sp)
/*  f0c9b90:	8dcf1a24 */ 	lw	$t7,0x1a24($t6)
/*  f0c9b94:	27190001 */ 	addiu	$t9,$t8,0x1
/*  f0c9b98:	15e00002 */ 	bnez	$t7,.L0f0c9ba4
/*  f0c9b9c:	00000000 */ 	nop
/*  f0c9ba0:	afb901c0 */ 	sw	$t9,0x1c0($sp)
.L0f0c9ba4:
/*  f0c9ba4:	1000001e */ 	b	.L0f0c9c20
/*  f0c9ba8:	8e450284 */ 	lw	$a1,0x284($s2)
/*  f0c9bac:	8e480284 */ 	lw	$t0,0x284($s2)
.L0f0c9bb0:
/*  f0c9bb0:	8d040274 */ 	lw	$a0,0x274($t0)
/*  f0c9bb4:	2c890001 */ 	sltiu	$t1,$a0,0x1
/*  f0c9bb8:	11200017 */ 	beqz	$t1,.L0f0c9c18
/*  f0c9bbc:	01202025 */ 	or	$a0,$t1,$zero
/*  f0c9bc0:	12e00015 */ 	beqz	$s7,.L0f0c9c18
/*  f0c9bc4:	02e02025 */ 	or	$a0,$s7,$zero
/*  f0c9bc8:	97aa00ea */ 	lhu	$t2,0xea($sp)
/*  f0c9bcc:	83a400ef */ 	lb	$a0,0xef($sp)
/*  f0c9bd0:	0c0053d8 */ 	jal	joyGetButtons
/*  f0c9bd4:	31452000 */ 	andi	$a1,$t2,0x2000
/*  f0c9bd8:	0002202b */ 	sltu	$a0,$zero,$v0
/*  f0c9bdc:	5080000f */ 	beqzl	$a0,.L0f0c9c1c
/*  f0c9be0:	afa401bc */ 	sw	$a0,0x1bc($sp)
/*  f0c9be4:	8e4c0284 */ 	lw	$t4,0x284($s2)
/*  f0c9be8:	97a201a2 */ 	lhu	$v0,0x1a2($sp)
/*  f0c9bec:	8d841a24 */ 	lw	$a0,0x1a24($t4)
/*  f0c9bf0:	304e8000 */ 	andi	$t6,$v0,0x8000
/*  f0c9bf4:	2c8d0001 */ 	sltiu	$t5,$a0,0x1
/*  f0c9bf8:	11a00007 */ 	beqz	$t5,.L0f0c9c18
/*  f0c9bfc:	01a02025 */ 	or	$a0,$t5,$zero
/*  f0c9c00:	2dc40001 */ 	sltiu	$a0,$t6,0x1
/*  f0c9c04:	50800005 */ 	beqzl	$a0,.L0f0c9c1c
/*  f0c9c08:	afa401bc */ 	sw	$a0,0x1bc($sp)
/*  f0c9c0c:	97a400e6 */ 	lhu	$a0,0xe6($sp)
/*  f0c9c10:	30988000 */ 	andi	$t8,$a0,0x8000
/*  f0c9c14:	2f040001 */ 	sltiu	$a0,$t8,0x1
.L0f0c9c18:
/*  f0c9c18:	afa401bc */ 	sw	$a0,0x1bc($sp)
.L0f0c9c1c:
/*  f0c9c1c:	8e450284 */ 	lw	$a1,0x284($s2)
.L0f0c9c20:
/*  f0c9c20:	24080001 */ 	addiu	$t0,$zero,0x1
/*  f0c9c24:	1000032a */ 	b	.L0f0ca8d0
/*  f0c9c28:	afa8023c */ 	sw	$t0,0x23c($sp)
/*  f0c9c2c:	24010002 */ 	addiu	$at,$zero,0x2
.L0f0c9c30:
/*  f0c9c30:	10410004 */ 	beq	$v0,$at,.L0f0c9c44
/*  f0c9c34:	34148000 */ 	dli	$s4,0x8000
/*  f0c9c38:	24010003 */ 	addiu	$at,$zero,0x3
/*  f0c9c3c:	14410005 */ 	bne	$v0,$at,.L0f0c9c54
/*  f0c9c40:	24110030 */ 	addiu	$s1,$zero,0x30
.L0f0c9c44:
/*  f0c9c44:	24090030 */ 	addiu	$t1,$zero,0x30
/*  f0c9c48:	24112000 */ 	addiu	$s1,$zero,0x2000
/*  f0c9c4c:	10000004 */ 	b	.L0f0c9c60
/*  f0c9c50:	a7a900ca */ 	sh	$t1,0xca($sp)
.L0f0c9c54:
/*  f0c9c54:	340a8000 */ 	dli	$t2,0x8000
/*  f0c9c58:	24142000 */ 	addiu	$s4,$zero,0x2000
/*  f0c9c5c:	a7aa00ca */ 	sh	$t2,0xca($sp)
.L0f0c9c60:
/*  f0c9c60:	8e4b0288 */ 	lw	$t3,0x288($s2)
/*  f0c9c64:	0fc549fb */ 	jal	optionsGetAimControl
/*  f0c9c68:	8d640070 */ 	lw	$a0,0x70($t3)
/*  f0c9c6c:	14400021 */ 	bnez	$v0,.L0f0c9cf4
/*  f0c9c70:	00000000 */ 	nop
/*  f0c9c74:	1ac0001a */ 	blez	$s6,.L0f0c9ce0
/*  f0c9c78:	00008025 */ 	or	$s0,$zero,$zero
/*  f0c9c7c:	27a3014c */ 	addiu	$v1,$sp,0x14c
/*  f0c9c80:	27a700fc */ 	addiu	$a3,$sp,0xfc
.L0f0c9c84:
/*  f0c9c84:	12e0000f */ 	beqz	$s7,.L0f0c9cc4
/*  f0c9c88:	02e02025 */ 	or	$a0,$s7,$zero
/*  f0c9c8c:	97ad019e */ 	lhu	$t5,0x19e($sp)
/*  f0c9c90:	00152e00 */ 	sll	$a1,$s5,0x18
/*  f0c9c94:	00056603 */ 	sra	$t4,$a1,0x18
/*  f0c9c98:	022d3024 */ 	and	$a2,$s1,$t5
/*  f0c9c9c:	30ceffff */ 	andi	$t6,$a2,0xffff
/*  f0c9ca0:	01c03025 */ 	or	$a2,$t6,$zero
/*  f0c9ca4:	01802825 */ 	or	$a1,$t4,$zero
/*  f0c9ca8:	02002025 */ 	or	$a0,$s0,$zero
/*  f0c9cac:	afa3004c */ 	sw	$v1,0x4c($sp)
/*  f0c9cb0:	0c00529e */ 	jal	joyGetButtonsOnSample
/*  f0c9cb4:	afa70048 */ 	sw	$a3,0x48($sp)
/*  f0c9cb8:	8fa3004c */ 	lw	$v1,0x4c($sp)
/*  f0c9cbc:	8fa70048 */ 	lw	$a3,0x48($sp)
/*  f0c9cc0:	0002202b */ 	sltu	$a0,$zero,$v0
.L0f0c9cc4:
/*  f0c9cc4:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f0c9cc8:	2c8f0001 */ 	sltiu	$t7,$a0,0x1
/*  f0c9ccc:	24630004 */ 	addiu	$v1,$v1,0x4
/*  f0c9cd0:	24e70004 */ 	addiu	$a3,$a3,0x4
/*  f0c9cd4:	ac64fffc */ 	sw	$a0,-0x4($v1)
/*  f0c9cd8:	1616ffea */ 	bne	$s0,$s6,.L0f0c9c84
/*  f0c9cdc:	aceffffc */ 	sw	$t7,-0x4($a3)
.L0f0c9ce0:
/*  f0c9ce0:	0016c080 */ 	sll	$t8,$s6,0x2
/*  f0c9ce4:	03b8c821 */ 	addu	$t9,$sp,$t8
/*  f0c9ce8:	8f390148 */ 	lw	$t9,0x148($t9)
/*  f0c9cec:	8e480284 */ 	lw	$t0,0x284($s2)
/*  f0c9cf0:	ad190120 */ 	sw	$t9,0x120($t0)
.L0f0c9cf4:
/*  f0c9cf4:	0fc5b364 */ 	jal	lvIsPaused
/*  f0c9cf8:	00000000 */ 	nop
/*  f0c9cfc:	544002ba */ 	bnezl	$v0,.L0f0ca7e8
/*  f0c9d00:	8e450284 */ 	lw	$a1,0x284($s2)
/*  f0c9d04:	8e490288 */ 	lw	$t1,0x288($s2)
/*  f0c9d08:	0fc549fb */ 	jal	optionsGetAimControl
/*  f0c9d0c:	8d240070 */ 	lw	$a0,0x70($t1)
/*  f0c9d10:	10400021 */ 	beqz	$v0,.L0f0c9d98
/*  f0c9d14:	00000000 */ 	nop
/*  f0c9d18:	1ac0001f */ 	blez	$s6,.L0f0c9d98
/*  f0c9d1c:	00008025 */ 	or	$s0,$zero,$zero
/*  f0c9d20:	27a3014c */ 	addiu	$v1,$sp,0x14c
/*  f0c9d24:	27a700fc */ 	addiu	$a3,$sp,0xfc
.L0f0c9d28:
/*  f0c9d28:	12e00012 */ 	beqz	$s7,.L0f0c9d74
/*  f0c9d2c:	02002025 */ 	or	$a0,$s0,$zero
/*  f0c9d30:	97ab019e */ 	lhu	$t3,0x19e($sp)
/*  f0c9d34:	00152e00 */ 	sll	$a1,$s5,0x18
/*  f0c9d38:	00055603 */ 	sra	$t2,$a1,0x18
/*  f0c9d3c:	022b3024 */ 	and	$a2,$s1,$t3
/*  f0c9d40:	30ccffff */ 	andi	$t4,$a2,0xffff
/*  f0c9d44:	01803025 */ 	or	$a2,$t4,$zero
/*  f0c9d48:	01402825 */ 	or	$a1,$t2,$zero
/*  f0c9d4c:	afa3004c */ 	sw	$v1,0x4c($sp)
/*  f0c9d50:	0c0052d4 */ 	jal	joyGetButtonsPressedOnSample
/*  f0c9d54:	afa70048 */ 	sw	$a3,0x48($sp)
/*  f0c9d58:	8fa3004c */ 	lw	$v1,0x4c($sp)
/*  f0c9d5c:	10400005 */ 	beqz	$v0,.L0f0c9d74
/*  f0c9d60:	8fa70048 */ 	lw	$a3,0x48($sp)
/*  f0c9d64:	8e450284 */ 	lw	$a1,0x284($s2)
/*  f0c9d68:	8ca40120 */ 	lw	$a0,0x120($a1)
/*  f0c9d6c:	2c8d0001 */ 	sltiu	$t5,$a0,0x1
/*  f0c9d70:	acad0120 */ 	sw	$t5,0x120($a1)
.L0f0c9d74:
/*  f0c9d74:	8e4e0284 */ 	lw	$t6,0x284($s2)
/*  f0c9d78:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f0c9d7c:	24630004 */ 	addiu	$v1,$v1,0x4
/*  f0c9d80:	8dcf0120 */ 	lw	$t7,0x120($t6)
/*  f0c9d84:	24e70004 */ 	addiu	$a3,$a3,0x4
/*  f0c9d88:	2df80001 */ 	sltiu	$t8,$t7,0x1
/*  f0c9d8c:	acf8fffc */ 	sw	$t8,-0x4($a3)
/*  f0c9d90:	1616ffe5 */ 	bne	$s0,$s6,.L0f0c9d28
/*  f0c9d94:	ac6ffffc */ 	sw	$t7,-0x4($v1)
.L0f0c9d98:
/*  f0c9d98:	0fc2866a */ 	jal	bgunGetWeaponNum
/*  f0c9d9c:	00002025 */ 	or	$a0,$zero,$zero
/*  f0c9da0:	24010032 */ 	addiu	$at,$zero,0x32
/*  f0c9da4:	54410005 */ 	bnel	$v0,$at,.L0f0c9dbc
/*  f0c9da8:	8e450284 */ 	lw	$a1,0x284($s2)
/*  f0c9dac:	8e480284 */ 	lw	$t0,0x284($s2)
/*  f0c9db0:	24190001 */ 	addiu	$t9,$zero,0x1
/*  f0c9db4:	ad190120 */ 	sw	$t9,0x120($t0)
/*  f0c9db8:	8e450284 */ 	lw	$a1,0x284($s2)
.L0f0c9dbc:
/*  f0c9dbc:	8fac01b0 */ 	lw	$t4,0x1b0($sp)
/*  f0c9dc0:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0c9dc4:	8ca40120 */ 	lw	$a0,0x120($a1)
/*  f0c9dc8:	2c890001 */ 	sltiu	$t1,$a0,0x1
/*  f0c9dcc:	afa901b4 */ 	sw	$t1,0x1b4($sp)
/*  f0c9dd0:	8caa0120 */ 	lw	$t2,0x120($a1)
/*  f0c9dd4:	afaa01b8 */ 	sw	$t2,0x1b8($sp)
/*  f0c9dd8:	8ca40120 */ 	lw	$a0,0x120($a1)
/*  f0c9ddc:	2c8b0001 */ 	sltiu	$t3,$a0,0x1
/*  f0c9de0:	11810004 */ 	beq	$t4,$at,.L0f0c9df4
/*  f0c9de4:	afab022c */ 	sw	$t3,0x22c($sp)
/*  f0c9de8:	24010003 */ 	addiu	$at,$zero,0x3
/*  f0c9dec:	15810054 */ 	bne	$t4,$at,.L0f0c9f40
/*  f0c9df0:	97af01a2 */ 	lhu	$t7,0x1a2($sp)
.L0f0c9df4:
/*  f0c9df4:	8cad0120 */ 	lw	$t5,0x120($a1)
/*  f0c9df8:	97a201a2 */ 	lhu	$v0,0x1a2($sp)
/*  f0c9dfc:	15a0001a */ 	bnez	$t5,.L0f0c9e68
/*  f0c9e00:	30490202 */ 	andi	$t1,$v0,0x202
/*  f0c9e04:	12e00015 */ 	beqz	$s7,.L0f0c9e5c
/*  f0c9e08:	27b000fc */ 	addiu	$s0,$sp,0xfc
/*  f0c9e0c:	97b1019e */ 	lhu	$s1,0x19e($sp)
/*  f0c9e10:	00152e00 */ 	sll	$a1,$s5,0x18
/*  f0c9e14:	00057603 */ 	sra	$t6,$a1,0x18
/*  f0c9e18:	02203025 */ 	or	$a2,$s1,$zero
/*  f0c9e1c:	30cf0202 */ 	andi	$t7,$a2,0x202
/*  f0c9e20:	01e03025 */ 	or	$a2,$t7,$zero
/*  f0c9e24:	01c02825 */ 	or	$a1,$t6,$zero
/*  f0c9e28:	0c005326 */ 	jal	joyCountButtonsOnSpecificSamples
/*  f0c9e2c:	02002025 */ 	or	$a0,$s0,$zero
/*  f0c9e30:	00152e00 */ 	sll	$a1,$s5,0x18
/*  f0c9e34:	02203025 */ 	or	$a2,$s1,$zero
/*  f0c9e38:	30d90101 */ 	andi	$t9,$a2,0x101
/*  f0c9e3c:	0005c603 */ 	sra	$t8,$a1,0x18
/*  f0c9e40:	afa201dc */ 	sw	$v0,0x1dc($sp)
/*  f0c9e44:	03002825 */ 	or	$a1,$t8,$zero
/*  f0c9e48:	03203025 */ 	or	$a2,$t9,$zero
/*  f0c9e4c:	0c005326 */ 	jal	joyCountButtonsOnSpecificSamples
/*  f0c9e50:	02002025 */ 	or	$a0,$s0,$zero
/*  f0c9e54:	afa201e0 */ 	sw	$v0,0x1e0($sp)
/*  f0c9e58:	8e450284 */ 	lw	$a1,0x284($s2)
.L0f0c9e5c:
/*  f0c9e5c:	97a801a2 */ 	lhu	$t0,0x1a2($sp)
/*  f0c9e60:	1000000d */ 	b	.L0f0c9e98
/*  f0c9e64:	afa80048 */ 	sw	$t0,0x48($sp)
.L0f0c9e68:
/*  f0c9e68:	11200005 */ 	beqz	$t1,.L0f0c9e80
/*  f0c9e6c:	304a0101 */ 	andi	$t2,$v0,0x101
/*  f0c9e70:	3c013f80 */ 	lui	$at,0x3f80
/*  f0c9e74:	44818000 */ 	mtc1	$at,$f16
/*  f0c9e78:	00000000 */ 	nop
/*  f0c9e7c:	e7b001e4 */ 	swc1	$f16,0x1e4($sp)
.L0f0c9e80:
/*  f0c9e80:	11400005 */ 	beqz	$t2,.L0f0c9e98
/*  f0c9e84:	afa20048 */ 	sw	$v0,0x48($sp)
/*  f0c9e88:	3c013f80 */ 	lui	$at,0x3f80
/*  f0c9e8c:	44819000 */ 	mtc1	$at,$f18
/*  f0c9e90:	afa20048 */ 	sw	$v0,0x48($sp)
/*  f0c9e94:	e7b201e8 */ 	swc1	$f18,0x1e8($sp)
.L0f0c9e98:
/*  f0c9e98:	8ca40120 */ 	lw	$a0,0x120($a1)
/*  f0c9e9c:	44802000 */ 	mtc1	$zero,$f4
/*  f0c9ea0:	44803000 */ 	mtc1	$zero,$f6
/*  f0c9ea4:	2c8b0001 */ 	sltiu	$t3,$a0,0x1
/*  f0c9ea8:	11600004 */ 	beqz	$t3,.L0f0c9ebc
/*  f0c9eac:	01602025 */ 	or	$a0,$t3,$zero
/*  f0c9eb0:	8fa40048 */ 	lw	$a0,0x48($sp)
/*  f0c9eb4:	308c0808 */ 	andi	$t4,$a0,0x808
/*  f0c9eb8:	000c202b */ 	sltu	$a0,$zero,$t4
.L0f0c9ebc:
/*  f0c9ebc:	afa401d4 */ 	sw	$a0,0x1d4($sp)
/*  f0c9ec0:	8ca40120 */ 	lw	$a0,0x120($a1)
/*  f0c9ec4:	2c8e0001 */ 	sltiu	$t6,$a0,0x1
/*  f0c9ec8:	11c00004 */ 	beqz	$t6,.L0f0c9edc
/*  f0c9ecc:	01c02025 */ 	or	$a0,$t6,$zero
/*  f0c9ed0:	8fa40048 */ 	lw	$a0,0x48($sp)
/*  f0c9ed4:	308f0404 */ 	andi	$t7,$a0,0x404
/*  f0c9ed8:	000f202b */ 	sltu	$a0,$zero,$t7
.L0f0c9edc:
/*  f0c9edc:	afa401d8 */ 	sw	$a0,0x1d8($sp)
/*  f0c9ee0:	afa001c4 */ 	sw	$zero,0x1c4($sp)
/*  f0c9ee4:	8ca40120 */ 	lw	$a0,0x120($a1)
/*  f0c9ee8:	e7a401ec */ 	swc1	$f4,0x1ec($sp)
/*  f0c9eec:	e7a601f0 */ 	swc1	$f6,0x1f0($sp)
/*  f0c9ef0:	2c990001 */ 	sltiu	$t9,$a0,0x1
/*  f0c9ef4:	afb901d0 */ 	sw	$t9,0x1d0($sp)
/*  f0c9ef8:	8ca40120 */ 	lw	$a0,0x120($a1)
/*  f0c9efc:	8e4902ac */ 	lw	$t1,0x2ac($s2)
/*  f0c9f00:	24010007 */ 	addiu	$at,$zero,0x7
/*  f0c9f04:	2c880001 */ 	sltiu	$t0,$a0,0x1
/*  f0c9f08:	1521005b */ 	bne	$t1,$at,.L0f0ca078
/*  f0c9f0c:	afa801cc */ 	sw	$t0,0x1cc($sp)
/*  f0c9f10:	8caa1bdc */ 	lw	$t2,0x1bdc($a1)
/*  f0c9f14:	000a582a */ 	slt	$t3,$zero,$t2
/*  f0c9f18:	afab01d4 */ 	sw	$t3,0x1d4($sp)
/*  f0c9f1c:	8cac1bdc */ 	lw	$t4,0x1bdc($a1)
/*  f0c9f20:	afa00258 */ 	sw	$zero,0x258($sp)
/*  f0c9f24:	afa0025c */ 	sw	$zero,0x25c($sp)
/*  f0c9f28:	298d0000 */ 	slti	$t5,$t4,0x0
/*  f0c9f2c:	afad01d8 */ 	sw	$t5,0x1d8($sp)
/*  f0c9f30:	8cae1bd8 */ 	lw	$t6,0x1bd8($a1)
/*  f0c9f34:	afa00254 */ 	sw	$zero,0x254($sp)
/*  f0c9f38:	1000004f */ 	b	.L0f0ca078
/*  f0c9f3c:	afae0250 */ 	sw	$t6,0x250($sp)
.L0f0c9f40:
/*  f0c9f40:	31f80202 */ 	andi	$t8,$t7,0x202
/*  f0c9f44:	13000005 */ 	beqz	$t8,.L0f0c9f5c
/*  f0c9f48:	afaf0048 */ 	sw	$t7,0x48($sp)
/*  f0c9f4c:	3c013f80 */ 	lui	$at,0x3f80
/*  f0c9f50:	44814000 */ 	mtc1	$at,$f8
/*  f0c9f54:	00000000 */ 	nop
/*  f0c9f58:	e7a801e4 */ 	swc1	$f8,0x1e4($sp)
.L0f0c9f5c:
/*  f0c9f5c:	8fb90048 */ 	lw	$t9,0x48($sp)
/*  f0c9f60:	3c013f80 */ 	lui	$at,0x3f80
/*  f0c9f64:	33280101 */ 	andi	$t0,$t9,0x101
/*  f0c9f68:	51000005 */ 	beqzl	$t0,.L0f0c9f80
/*  f0c9f6c:	8ca90120 */ 	lw	$t1,0x120($a1)
/*  f0c9f70:	44815000 */ 	mtc1	$at,$f10
/*  f0c9f74:	00000000 */ 	nop
/*  f0c9f78:	e7aa01e8 */ 	swc1	$f10,0x1e8($sp)
/*  f0c9f7c:	8ca90120 */ 	lw	$t1,0x120($a1)
.L0f0c9f80:
/*  f0c9f80:	55200018 */ 	bnezl	$t1,.L0f0c9fe4
/*  f0c9f84:	afa001d4 */ 	sw	$zero,0x1d4($sp)
/*  f0c9f88:	12e00015 */ 	beqz	$s7,.L0f0c9fe0
/*  f0c9f8c:	27b000fc */ 	addiu	$s0,$sp,0xfc
/*  f0c9f90:	97b1019e */ 	lhu	$s1,0x19e($sp)
/*  f0c9f94:	00152e00 */ 	sll	$a1,$s5,0x18
/*  f0c9f98:	00055603 */ 	sra	$t2,$a1,0x18
/*  f0c9f9c:	02203025 */ 	or	$a2,$s1,$zero
/*  f0c9fa0:	30cb0202 */ 	andi	$t3,$a2,0x202
/*  f0c9fa4:	01603025 */ 	or	$a2,$t3,$zero
/*  f0c9fa8:	01402825 */ 	or	$a1,$t2,$zero
/*  f0c9fac:	0c005326 */ 	jal	joyCountButtonsOnSpecificSamples
/*  f0c9fb0:	02002025 */ 	or	$a0,$s0,$zero
/*  f0c9fb4:	00152e00 */ 	sll	$a1,$s5,0x18
/*  f0c9fb8:	02203025 */ 	or	$a2,$s1,$zero
/*  f0c9fbc:	30cd0101 */ 	andi	$t5,$a2,0x101
/*  f0c9fc0:	00056603 */ 	sra	$t4,$a1,0x18
/*  f0c9fc4:	afa201dc */ 	sw	$v0,0x1dc($sp)
/*  f0c9fc8:	01802825 */ 	or	$a1,$t4,$zero
/*  f0c9fcc:	01a03025 */ 	or	$a2,$t5,$zero
/*  f0c9fd0:	0c005326 */ 	jal	joyCountButtonsOnSpecificSamples
/*  f0c9fd4:	02002025 */ 	or	$a0,$s0,$zero
/*  f0c9fd8:	afa201e0 */ 	sw	$v0,0x1e0($sp)
/*  f0c9fdc:	8e450284 */ 	lw	$a1,0x284($s2)
.L0f0c9fe0:
/*  f0c9fe0:	afa001d4 */ 	sw	$zero,0x1d4($sp)
.L0f0c9fe4:
/*  f0c9fe4:	afa001d8 */ 	sw	$zero,0x1d8($sp)
/*  f0c9fe8:	8ca40120 */ 	lw	$a0,0x120($a1)
/*  f0c9fec:	afa001d0 */ 	sw	$zero,0x1d0($sp)
/*  f0c9ff0:	8faf0048 */ 	lw	$t7,0x48($sp)
/*  f0c9ff4:	2c8e0001 */ 	sltiu	$t6,$a0,0x1
/*  f0c9ff8:	afae01c4 */ 	sw	$t6,0x1c4($sp)
/*  f0c9ffc:	8ca20120 */ 	lw	$v0,0x120($a1)
/*  f0ca000:	31f80808 */ 	andi	$t8,$t7,0x808
/*  f0ca004:	14400007 */ 	bnez	$v0,.L0f0ca024
/*  f0ca008:	00000000 */ 	nop
/*  f0ca00c:	13000005 */ 	beqz	$t8,.L0f0ca024
/*  f0ca010:	3c013f80 */ 	lui	$at,0x3f80
/*  f0ca014:	44818000 */ 	mtc1	$at,$f16
/*  f0ca018:	00000000 */ 	nop
/*  f0ca01c:	e7b001ec */ 	swc1	$f16,0x1ec($sp)
/*  f0ca020:	8ca20120 */ 	lw	$v0,0x120($a1)
.L0f0ca024:
/*  f0ca024:	14400008 */ 	bnez	$v0,.L0f0ca048
/*  f0ca028:	8fb90048 */ 	lw	$t9,0x48($sp)
/*  f0ca02c:	33280404 */ 	andi	$t0,$t9,0x404
/*  f0ca030:	11000005 */ 	beqz	$t0,.L0f0ca048
/*  f0ca034:	3c013f80 */ 	lui	$at,0x3f80
/*  f0ca038:	44819000 */ 	mtc1	$at,$f18
/*  f0ca03c:	00000000 */ 	nop
/*  f0ca040:	e7b201f0 */ 	swc1	$f18,0x1f0($sp)
/*  f0ca044:	8ca20120 */ 	lw	$v0,0x120($a1)
.L0f0ca048:
/*  f0ca048:	8e4902ac */ 	lw	$t1,0x2ac($s2)
/*  f0ca04c:	2c440001 */ 	sltiu	$a0,$v0,0x1
/*  f0ca050:	24010007 */ 	addiu	$at,$zero,0x7
/*  f0ca054:	afa401cc */ 	sw	$a0,0x1cc($sp)
/*  f0ca058:	15210007 */ 	bne	$t1,$at,.L0f0ca078
/*  f0ca05c:	afa001c8 */ 	sw	$zero,0x1c8($sp)
/*  f0ca060:	afa00258 */ 	sw	$zero,0x258($sp)
/*  f0ca064:	8caa1bdc */ 	lw	$t2,0x1bdc($a1)
/*  f0ca068:	afaa025c */ 	sw	$t2,0x25c($sp)
/*  f0ca06c:	8cab1bd8 */ 	lw	$t3,0x1bd8($a1)
/*  f0ca070:	afa00254 */ 	sw	$zero,0x254($sp)
/*  f0ca074:	afab0250 */ 	sw	$t3,0x250($sp)
.L0f0ca078:
/*  f0ca078:	8ca20120 */ 	lw	$v0,0x120($a1)
/*  f0ca07c:	8fa4024c */ 	lw	$a0,0x24c($sp)
/*  f0ca080:	10400012 */ 	beqz	$v0,.L0f0ca0cc
/*  f0ca084:	2881003d */ 	slti	$at,$a0,0x3d
/*  f0ca088:	14200010 */ 	bnez	$at,.L0f0ca0cc
/*  f0ca08c:	248cffc4 */ 	addiu	$t4,$a0,-60
/*  f0ca090:	448c2000 */ 	mtc1	$t4,$f4
/*  f0ca094:	3c014120 */ 	lui	$at,0x4120
/*  f0ca098:	44811000 */ 	mtc1	$at,$f2
/*  f0ca09c:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f0ca0a0:	3c013f80 */ 	lui	$at,0x3f80
/*  f0ca0a4:	44815000 */ 	mtc1	$at,$f10
/*  f0ca0a8:	3c013f80 */ 	lui	$at,0x3f80
/*  f0ca0ac:	46023203 */ 	div.s	$f8,$f6,$f2
/*  f0ca0b0:	4608503c */ 	c.lt.s	$f10,$f8
/*  f0ca0b4:	e7a801ec */ 	swc1	$f8,0x1ec($sp)
/*  f0ca0b8:	4502001a */ 	bc1fl	.L0f0ca124
/*  f0ca0bc:	8ca20120 */ 	lw	$v0,0x120($a1)
/*  f0ca0c0:	44818000 */ 	mtc1	$at,$f16
/*  f0ca0c4:	10000016 */ 	b	.L0f0ca120
/*  f0ca0c8:	e7b001ec */ 	swc1	$f16,0x1ec($sp)
.L0f0ca0cc:
/*  f0ca0cc:	10400014 */ 	beqz	$v0,.L0f0ca120
/*  f0ca0d0:	8fa4024c */ 	lw	$a0,0x24c($sp)
/*  f0ca0d4:	2881ffc4 */ 	slti	$at,$a0,-60
/*  f0ca0d8:	10200011 */ 	beqz	$at,.L0f0ca120
/*  f0ca0dc:	240dffc4 */ 	addiu	$t5,$zero,-60
/*  f0ca0e0:	01a47023 */ 	subu	$t6,$t5,$a0
/*  f0ca0e4:	448e9000 */ 	mtc1	$t6,$f18
/*  f0ca0e8:	3c014120 */ 	lui	$at,0x4120
/*  f0ca0ec:	44811000 */ 	mtc1	$at,$f2
/*  f0ca0f0:	46809120 */ 	cvt.s.w	$f4,$f18
/*  f0ca0f4:	3c013f80 */ 	lui	$at,0x3f80
/*  f0ca0f8:	44815000 */ 	mtc1	$at,$f10
/*  f0ca0fc:	3c013f80 */ 	lui	$at,0x3f80
/*  f0ca100:	46022183 */ 	div.s	$f6,$f4,$f2
/*  f0ca104:	4606503c */ 	c.lt.s	$f10,$f6
/*  f0ca108:	e7a601f0 */ 	swc1	$f6,0x1f0($sp)
/*  f0ca10c:	45020005 */ 	bc1fl	.L0f0ca124
/*  f0ca110:	8ca20120 */ 	lw	$v0,0x120($a1)
/*  f0ca114:	44814000 */ 	mtc1	$at,$f8
/*  f0ca118:	00000000 */ 	nop
/*  f0ca11c:	e7a801f0 */ 	swc1	$f8,0x1f0($sp)
.L0f0ca120:
/*  f0ca120:	8ca20120 */ 	lw	$v0,0x120($a1)
.L0f0ca124:
/*  f0ca124:	3c014120 */ 	lui	$at,0x4120
/*  f0ca128:	44811000 */ 	mtc1	$at,$f2
/*  f0ca12c:	10400012 */ 	beqz	$v0,.L0f0ca178
/*  f0ca130:	8fa30248 */ 	lw	$v1,0x248($sp)
/*  f0ca134:	2861ffc4 */ 	slti	$at,$v1,-60
/*  f0ca138:	1020000f */ 	beqz	$at,.L0f0ca178
/*  f0ca13c:	240fffc4 */ 	addiu	$t7,$zero,-60
/*  f0ca140:	01e3c023 */ 	subu	$t8,$t7,$v1
/*  f0ca144:	44988000 */ 	mtc1	$t8,$f16
/*  f0ca148:	3c013f80 */ 	lui	$at,0x3f80
/*  f0ca14c:	44812000 */ 	mtc1	$at,$f4
/*  f0ca150:	468084a0 */ 	cvt.s.w	$f18,$f16
/*  f0ca154:	3c013f80 */ 	lui	$at,0x3f80
/*  f0ca158:	46029303 */ 	div.s	$f12,$f18,$f2
/*  f0ca15c:	460c203c */ 	c.lt.s	$f4,$f12
/*  f0ca160:	e7ac01f4 */ 	swc1	$f12,0x1f4($sp)
/*  f0ca164:	45000016 */ 	bc1f	.L0f0ca1c0
/*  f0ca168:	00000000 */ 	nop
/*  f0ca16c:	44816000 */ 	mtc1	$at,$f12
/*  f0ca170:	10000013 */ 	b	.L0f0ca1c0
/*  f0ca174:	e7ac01f4 */ 	swc1	$f12,0x1f4($sp)
.L0f0ca178:
/*  f0ca178:	10400011 */ 	beqz	$v0,.L0f0ca1c0
/*  f0ca17c:	8fa30248 */ 	lw	$v1,0x248($sp)
/*  f0ca180:	2861003d */ 	slti	$at,$v1,0x3d
/*  f0ca184:	1420000e */ 	bnez	$at,.L0f0ca1c0
/*  f0ca188:	2479ffc4 */ 	addiu	$t9,$v1,-60
/*  f0ca18c:	44995000 */ 	mtc1	$t9,$f10
/*  f0ca190:	3c013f80 */ 	lui	$at,0x3f80
/*  f0ca194:	44814000 */ 	mtc1	$at,$f8
/*  f0ca198:	468051a0 */ 	cvt.s.w	$f6,$f10
/*  f0ca19c:	3c013f80 */ 	lui	$at,0x3f80
/*  f0ca1a0:	46023003 */ 	div.s	$f0,$f6,$f2
/*  f0ca1a4:	4600403c */ 	c.lt.s	$f8,$f0
/*  f0ca1a8:	e7a001f8 */ 	swc1	$f0,0x1f8($sp)
/*  f0ca1ac:	45000004 */ 	bc1f	.L0f0ca1c0
/*  f0ca1b0:	00000000 */ 	nop
/*  f0ca1b4:	44810000 */ 	mtc1	$at,$f0
/*  f0ca1b8:	00000000 */ 	nop
/*  f0ca1bc:	e7a001f8 */ 	swc1	$f0,0x1f8($sp)
.L0f0ca1c0:
/*  f0ca1c0:	52e00060 */ 	beqzl	$s7,.L0f0ca344
/*  f0ca1c4:	97aa00ca */ 	lhu	$t2,0xca($sp)
/*  f0ca1c8:	84a2024c */ 	lh	$v0,0x24c($a1)
/*  f0ca1cc:	2841fffe */ 	slti	$at,$v0,-2
/*  f0ca1d0:	10200009 */ 	beqz	$at,.L0f0ca1f8
/*  f0ca1d4:	00564021 */ 	addu	$t0,$v0,$s6
/*  f0ca1d8:	a4a8024c */ 	sh	$t0,0x24c($a1)
/*  f0ca1dc:	8e450284 */ 	lw	$a1,0x284($s2)
/*  f0ca1e0:	84a9024c */ 	lh	$t1,0x24c($a1)
/*  f0ca1e4:	2921fffe */ 	slti	$at,$t1,-2
/*  f0ca1e8:	54200056 */ 	bnezl	$at,.L0f0ca344
/*  f0ca1ec:	97aa00ca */ 	lhu	$t2,0xca($sp)
/*  f0ca1f0:	10000053 */ 	b	.L0f0ca340
/*  f0ca1f4:	a4a0024c */ 	sh	$zero,0x24c($a1)
.L0f0ca1f8:
/*  f0ca1f8:	1ac00051 */ 	blez	$s6,.L0f0ca340
/*  f0ca1fc:	00008025 */ 	or	$s0,$zero,$zero
/*  f0ca200:	97b1019e */ 	lhu	$s1,0x19e($sp)
/*  f0ca204:	97aa00ca */ 	lhu	$t2,0xca($sp)
/*  f0ca208:	2413ffff */ 	addiu	$s3,$zero,-1
/*  f0ca20c:	01513024 */ 	and	$a2,$t2,$s1
/*  f0ca210:	30cbffff */ 	andi	$t3,$a2,0xffff
/*  f0ca214:	afab003c */ 	sw	$t3,0x3c($sp)
/*  f0ca218:	00152e00 */ 	sll	$a1,$s5,0x18
.L0f0ca21c:
/*  f0ca21c:	00056603 */ 	sra	$t4,$a1,0x18
/*  f0ca220:	8fa6003c */ 	lw	$a2,0x3c($sp)
/*  f0ca224:	01802825 */ 	or	$a1,$t4,$zero
/*  f0ca228:	0c00529e */ 	jal	joyGetButtonsOnSample
/*  f0ca22c:	02002025 */ 	or	$a0,$s0,$zero
/*  f0ca230:	5040002d */ 	beqzl	$v0,.L0f0ca2e8
/*  f0ca234:	8e4f0284 */ 	lw	$t7,0x284($s2)
/*  f0ca238:	8e4d0284 */ 	lw	$t5,0x284($s2)
/*  f0ca23c:	00152e00 */ 	sll	$a1,$s5,0x18
/*  f0ca240:	00057e03 */ 	sra	$t7,$a1,0x18
/*  f0ca244:	85ae024c */ 	lh	$t6,0x24c($t5)
/*  f0ca248:	01e02825 */ 	or	$a1,$t7,$zero
/*  f0ca24c:	02002025 */ 	or	$a0,$s0,$zero
/*  f0ca250:	29c1ffff */ 	slti	$at,$t6,-1
/*  f0ca254:	14200037 */ 	bnez	$at,.L0f0ca334
/*  f0ca258:	02913024 */ 	and	$a2,$s4,$s1
/*  f0ca25c:	30d8ffff */ 	andi	$t8,$a2,0xffff
/*  f0ca260:	03003025 */ 	or	$a2,$t8,$zero
/*  f0ca264:	0c0052d4 */ 	jal	joyGetButtonsPressedOnSample
/*  f0ca268:	afb8004c */ 	sw	$t8,0x4c($sp)
/*  f0ca26c:	10400006 */ 	beqz	$v0,.L0f0ca288
/*  f0ca270:	8fa6004c */ 	lw	$a2,0x4c($sp)
/*  f0ca274:	8fb901fc */ 	lw	$t9,0x1fc($sp)
/*  f0ca278:	8e490284 */ 	lw	$t1,0x284($s2)
/*  f0ca27c:	27280001 */ 	addiu	$t0,$t9,0x1
/*  f0ca280:	afa801fc */ 	sw	$t0,0x1fc($sp)
/*  f0ca284:	a533024c */ 	sh	$s3,0x24c($t1)
.L0f0ca288:
/*  f0ca288:	8e4a0284 */ 	lw	$t2,0x284($s2)
/*  f0ca28c:	00152e00 */ 	sll	$a1,$s5,0x18
/*  f0ca290:	00056603 */ 	sra	$t4,$a1,0x18
/*  f0ca294:	854b024c */ 	lh	$t3,0x24c($t2)
/*  f0ca298:	02002025 */ 	or	$a0,$s0,$zero
/*  f0ca29c:	05620026 */ 	bltzl	$t3,.L0f0ca338
/*  f0ca2a0:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f0ca2a4:	0c00529e */ 	jal	joyGetButtonsOnSample
/*  f0ca2a8:	01802825 */ 	or	$a1,$t4,$zero
/*  f0ca2ac:	54400022 */ 	bnezl	$v0,.L0f0ca338
/*  f0ca2b0:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f0ca2b4:	8e450284 */ 	lw	$a1,0x284($s2)
/*  f0ca2b8:	84a2024c */ 	lh	$v0,0x24c($a1)
/*  f0ca2bc:	28410010 */ 	slti	$at,$v0,0xd
/*  f0ca2c0:	14200006 */ 	bnez	$at,.L0f0ca2dc
/*  f0ca2c4:	244e0001 */ 	addiu	$t6,$v0,0x1
/*  f0ca2c8:	0fc3fbda */ 	jal	amOpen
/*  f0ca2cc:	00000000 */ 	nop
/*  f0ca2d0:	8e4d0284 */ 	lw	$t5,0x284($s2)
/*  f0ca2d4:	10000017 */ 	b	.L0f0ca334
/*  f0ca2d8:	a5b3024c */ 	sh	$s3,0x24c($t5)
.L0f0ca2dc:
/*  f0ca2dc:	10000015 */ 	b	.L0f0ca334
/*  f0ca2e0:	a4ae024c */ 	sh	$t6,0x24c($a1)
/*  f0ca2e4:	8e4f0284 */ 	lw	$t7,0x284($s2)
.L0f0ca2e8:
/*  f0ca2e8:	85f8024c */ 	lh	$t8,0x24c($t7)
/*  f0ca2ec:	5b000010 */ 	blezl	$t8,.L0f0ca330
/*  f0ca2f0:	8e490284 */ 	lw	$t1,0x284($s2)
/*  f0ca2f4:	12e0000a */ 	beqz	$s7,.L0f0ca320
/*  f0ca2f8:	02002025 */ 	or	$a0,$s0,$zero
/*  f0ca2fc:	00152e00 */ 	sll	$a1,$s5,0x18
/*  f0ca300:	02913024 */ 	and	$a2,$s4,$s1
/*  f0ca304:	30c8ffff */ 	andi	$t0,$a2,0xffff
/*  f0ca308:	0005ce03 */ 	sra	$t9,$a1,0x18
/*  f0ca30c:	03202825 */ 	or	$a1,$t9,$zero
/*  f0ca310:	0c00529e */ 	jal	joyGetButtonsOnSample
/*  f0ca314:	01003025 */ 	or	$a2,$t0,$zero
/*  f0ca318:	54400005 */ 	bnezl	$v0,.L0f0ca330
/*  f0ca31c:	8e490284 */ 	lw	$t1,0x284($s2)
.L0f0ca320:
/*  f0ca320:	8fa20200 */ 	lw	$v0,0x200($sp)
/*  f0ca324:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f0ca328:	afa20200 */ 	sw	$v0,0x200($sp)
/*  f0ca32c:	8e490284 */ 	lw	$t1,0x284($s2)
.L0f0ca330:
/*  f0ca330:	a520024c */ 	sh	$zero,0x24c($t1)
.L0f0ca334:
/*  f0ca334:	26100001 */ 	addiu	$s0,$s0,0x1
.L0f0ca338:
/*  f0ca338:	5616ffb8 */ 	bnel	$s0,$s6,.L0f0ca21c
/*  f0ca33c:	00152e00 */ 	sll	$a1,$s5,0x18
.L0f0ca340:
/*  f0ca340:	97aa00ca */ 	lhu	$t2,0xca($sp)
.L0f0ca344:
/*  f0ca344:	2413ffff */ 	addiu	$s3,$zero,-1
/*  f0ca348:	12e00058 */ 	beqz	$s7,.L0f0ca4ac
/*  f0ca34c:	afaa0038 */ 	sw	$t2,0x38($sp)
/*  f0ca350:	1ac00056 */ 	blez	$s6,.L0f0ca4ac
/*  f0ca354:	00008025 */ 	or	$s0,$zero,$zero
/*  f0ca358:	97b1019e */ 	lhu	$s1,0x19e($sp)
/*  f0ca35c:	322c4000 */ 	andi	$t4,$s1,0x4000
/*  f0ca360:	afac0044 */ 	sw	$t4,0x44($sp)
/*  f0ca364:	00152e00 */ 	sll	$a1,$s5,0x18
.L0f0ca368:
/*  f0ca368:	00056e03 */ 	sra	$t5,$a1,0x18
/*  f0ca36c:	01a02825 */ 	or	$a1,$t5,$zero
/*  f0ca370:	02002025 */ 	or	$a0,$s0,$zero
/*  f0ca374:	0c00529e */ 	jal	joyGetButtonsOnSample
/*  f0ca378:	97a60046 */ 	lhu	$a2,0x46($sp)
/*  f0ca37c:	50400040 */ 	beqzl	$v0,.L0f0ca480
/*  f0ca380:	8e450284 */ 	lw	$a1,0x284($s2)
/*  f0ca384:	8e4e0284 */ 	lw	$t6,0x284($s2)
/*  f0ca388:	00152e00 */ 	sll	$a1,$s5,0x18
/*  f0ca38c:	00057e03 */ 	sra	$t7,$a1,0x18
/*  f0ca390:	85c4024e */ 	lh	$a0,0x24e($t6)
/*  f0ca394:	02913024 */ 	and	$a2,$s4,$s1
/*  f0ca398:	30d8ffff */ 	andi	$t8,$a2,0xffff
/*  f0ca39c:	2881ffff */ 	slti	$at,$a0,-1
/*  f0ca3a0:	1420002f */ 	bnez	$at,.L0f0ca460
/*  f0ca3a4:	01e02825 */ 	or	$a1,$t7,$zero
/*  f0ca3a8:	02002025 */ 	or	$a0,$s0,$zero
/*  f0ca3ac:	0c0052d4 */ 	jal	joyGetButtonsPressedOnSample
/*  f0ca3b0:	03003025 */ 	or	$a2,$t8,$zero
/*  f0ca3b4:	5040000e */ 	beqzl	$v0,.L0f0ca3f0
/*  f0ca3b8:	8e450284 */ 	lw	$a1,0x284($s2)
/*  f0ca3bc:	8e590284 */ 	lw	$t9,0x284($s2)
/*  f0ca3c0:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f0ca3c4:	8724024e */ 	lh	$a0,0x24e($t9)
/*  f0ca3c8:	04820009 */ 	bltzl	$a0,.L0f0ca3f0
/*  f0ca3cc:	8e450284 */ 	lw	$a1,0x284($s2)
/*  f0ca3d0:	0fc2a257 */ 	jal	bgunConsiderToggleGunFunction
/*  f0ca3d4:	00003025 */ 	or	$a2,$zero,$zero
/*  f0ca3d8:	50400005 */ 	beqzl	$v0,.L0f0ca3f0
/*  f0ca3dc:	8e450284 */ 	lw	$a1,0x284($s2)
/*  f0ca3e0:	8e490284 */ 	lw	$t1,0x284($s2)
/*  f0ca3e4:	2408fffd */ 	addiu	$t0,$zero,-3
/*  f0ca3e8:	a528024e */ 	sh	$t0,0x24e($t1)
/*  f0ca3ec:	8e450284 */ 	lw	$a1,0x284($s2)
.L0f0ca3f0:
/*  f0ca3f0:	84a4024e */ 	lh	$a0,0x24e($a1)
/*  f0ca3f4:	0480002a */ 	bltz	$a0,.L0f0ca4a0
/*  f0ca3f8:	2881001a */ 	slti	$at,$a0,0x15
/*  f0ca3fc:	14200016 */ 	bnez	$at,.L0f0ca458
/*  f0ca400:	248f0001 */ 	addiu	$t7,$a0,0x1
/*  f0ca404:	00002825 */ 	or	$a1,$zero,$zero
/*  f0ca408:	0fc2a257 */ 	jal	bgunConsiderToggleGunFunction
/*  f0ca40c:	00003025 */ 	or	$a2,$zero,$zero
/*  f0ca410:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0ca414:	54410005 */ 	bnel	$v0,$at,.L0f0ca42c
/*  f0ca418:	24010002 */ 	addiu	$at,$zero,0x2
/*  f0ca41c:	8e4a0284 */ 	lw	$t2,0x284($s2)
/*  f0ca420:	1000001f */ 	b	.L0f0ca4a0
/*  f0ca424:	a553024e */ 	sh	$s3,0x24e($t2)
/*  f0ca428:	24010002 */ 	addiu	$at,$zero,0x2
.L0f0ca42c:
/*  f0ca42c:	54410006 */ 	bnel	$v0,$at,.L0f0ca448
/*  f0ca430:	8e450284 */ 	lw	$a1,0x284($s2)
/*  f0ca434:	8e4c0284 */ 	lw	$t4,0x284($s2)
/*  f0ca438:	240bfffe */ 	addiu	$t3,$zero,-2
/*  f0ca43c:	10000018 */ 	b	.L0f0ca4a0
/*  f0ca440:	a58b024e */ 	sh	$t3,0x24e($t4)
/*  f0ca444:	8e450284 */ 	lw	$a1,0x284($s2)
.L0f0ca448:
/*  f0ca448:	84ad024e */ 	lh	$t5,0x24e($a1)
/*  f0ca44c:	25ae0001 */ 	addiu	$t6,$t5,0x1
/*  f0ca450:	10000013 */ 	b	.L0f0ca4a0
/*  f0ca454:	a4ae024e */ 	sh	$t6,0x24e($a1)
.L0f0ca458:
/*  f0ca458:	10000011 */ 	b	.L0f0ca4a0
/*  f0ca45c:	a4af024e */ 	sh	$t7,0x24e($a1)
.L0f0ca460:
/*  f0ca460:	2881fffe */ 	slti	$at,$a0,-2
/*  f0ca464:	1420000e */ 	bnez	$at,.L0f0ca4a0
/*  f0ca468:	00002825 */ 	or	$a1,$zero,$zero
/*  f0ca46c:	0fc2a257 */ 	jal	bgunConsiderToggleGunFunction
/*  f0ca470:	00003025 */ 	or	$a2,$zero,$zero
/*  f0ca474:	1000000b */ 	b	.L0f0ca4a4
/*  f0ca478:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f0ca47c:	8e450284 */ 	lw	$a1,0x284($s2)
.L0f0ca480:
/*  f0ca480:	8fb901c0 */ 	lw	$t9,0x1c0($sp)
/*  f0ca484:	84b8024e */ 	lh	$t8,0x24e($a1)
/*  f0ca488:	27280001 */ 	addiu	$t0,$t9,0x1
/*  f0ca48c:	1b000002 */ 	blez	$t8,.L0f0ca498
/*  f0ca490:	00000000 */ 	nop
/*  f0ca494:	afa801c0 */ 	sw	$t0,0x1c0($sp)
.L0f0ca498:
/*  f0ca498:	0fc2a314 */ 	jal	bgun0f0a8c50
/*  f0ca49c:	a4a0024e */ 	sh	$zero,0x24e($a1)
.L0f0ca4a0:
/*  f0ca4a0:	26100001 */ 	addiu	$s0,$s0,0x1
.L0f0ca4a4:
/*  f0ca4a4:	5616ffb0 */ 	bnel	$s0,$s6,.L0f0ca368
/*  f0ca4a8:	00152e00 */ 	sll	$a1,$s5,0x18
.L0f0ca4ac:
/*  f0ca4ac:	8fa901a8 */ 	lw	$t1,0x1a8($sp)
/*  f0ca4b0:	1120001c */ 	beqz	$t1,.L0f0ca524
/*  f0ca4b4:	00000000 */ 	nop
/*  f0ca4b8:	8e4a0284 */ 	lw	$t2,0x284($s2)
/*  f0ca4bc:	8fa20048 */ 	lw	$v0,0x48($sp)
/*  f0ca4c0:	3c013f80 */ 	lui	$at,0x3f80
/*  f0ca4c4:	8d4b0120 */ 	lw	$t3,0x120($t2)
/*  f0ca4c8:	30510808 */ 	andi	$s1,$v0,0x808
/*  f0ca4cc:	0011602b */ 	sltu	$t4,$zero,$s1
/*  f0ca4d0:	11600014 */ 	beqz	$t3,.L0f0ca524
/*  f0ca4d4:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f0ca4d8:	44810000 */ 	mtc1	$at,$f0
/*  f0ca4dc:	30500404 */ 	andi	$s0,$v0,0x404
/*  f0ca4e0:	0010682b */ 	sltu	$t5,$zero,$s0
/*  f0ca4e4:	01a08025 */ 	or	$s0,$t5,$zero
/*  f0ca4e8:	01808825 */ 	or	$s1,$t4,$zero
/*  f0ca4ec:	0fc2866a */ 	jal	bgunGetWeaponNum
/*  f0ca4f0:	e7a000bc */ 	swc1	$f0,0xbc($sp)
/*  f0ca4f4:	24010016 */ 	addiu	$at,$zero,0x16
/*  f0ca4f8:	14410004 */ 	bne	$v0,$at,.L0f0ca50c
/*  f0ca4fc:	c7a000bc */ 	lwc1	$f0,0xbc($sp)
/*  f0ca500:	3c013f00 */ 	lui	$at,0x3f00
/*  f0ca504:	44810000 */ 	mtc1	$at,$f0
/*  f0ca508:	00000000 */ 	nop
.L0f0ca50c:
/*  f0ca50c:	12000002 */ 	beqz	$s0,.L0f0ca518
/*  f0ca510:	00000000 */ 	nop
/*  f0ca514:	e7a00210 */ 	swc1	$f0,0x210($sp)
.L0f0ca518:
/*  f0ca518:	12200002 */ 	beqz	$s1,.L0f0ca524
/*  f0ca51c:	00000000 */ 	nop
/*  f0ca520:	e7a00214 */ 	swc1	$f0,0x214($sp)
.L0f0ca524:
/*  f0ca524:	12e00052 */ 	beqz	$s7,.L0f0ca670
/*  f0ca528:	00000000 */ 	nop
/*  f0ca52c:	1ac00050 */ 	blez	$s6,.L0f0ca670
/*  f0ca530:	00008025 */ 	or	$s0,$zero,$zero
/*  f0ca534:	8fae01a8 */ 	lw	$t6,0x1a8($sp)
.L0f0ca538:
/*  f0ca538:	00107880 */ 	sll	$t7,$s0,0x2
/*  f0ca53c:	03afc021 */ 	addu	$t8,$sp,$t7
/*  f0ca540:	55c0002c */ 	bnezl	$t6,.L0f0ca5f4
/*  f0ca544:	8e4e0288 */ 	lw	$t6,0x288($s2)
/*  f0ca548:	8f18014c */ 	lw	$t8,0x14c($t8)
/*  f0ca54c:	02002025 */ 	or	$a0,$s0,$zero
/*  f0ca550:	00152e00 */ 	sll	$a1,$s5,0x18
/*  f0ca554:	13000026 */ 	beqz	$t8,.L0f0ca5f0
/*  f0ca558:	97b1019e */ 	lhu	$s1,0x19e($sp)
/*  f0ca55c:	02203025 */ 	or	$a2,$s1,$zero
/*  f0ca560:	30c80808 */ 	andi	$t0,$a2,0x808
/*  f0ca564:	0005ce03 */ 	sra	$t9,$a1,0x18
/*  f0ca568:	322a0404 */ 	andi	$t2,$s1,0x404
/*  f0ca56c:	afaa0050 */ 	sw	$t2,0x50($sp)
/*  f0ca570:	03202825 */ 	or	$a1,$t9,$zero
/*  f0ca574:	0c0052d4 */ 	jal	joyGetButtonsPressedOnSample
/*  f0ca578:	01003025 */ 	or	$a2,$t0,$zero
/*  f0ca57c:	1040000b */ 	beqz	$v0,.L0f0ca5ac
/*  f0ca580:	02002025 */ 	or	$a0,$s0,$zero
/*  f0ca584:	8fa20218 */ 	lw	$v0,0x218($sp)
/*  f0ca588:	10400003 */ 	beqz	$v0,.L0f0ca598
/*  f0ca58c:	2442ffff */ 	addiu	$v0,$v0,-1
/*  f0ca590:	10000004 */ 	b	.L0f0ca5a4
/*  f0ca594:	afa20218 */ 	sw	$v0,0x218($sp)
.L0f0ca598:
/*  f0ca598:	8fa2021c */ 	lw	$v0,0x21c($sp)
/*  f0ca59c:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f0ca5a0:	afa2021c */ 	sw	$v0,0x21c($sp)
.L0f0ca5a4:
/*  f0ca5a4:	8e4b0284 */ 	lw	$t3,0x284($s2)
/*  f0ca5a8:	ad730260 */ 	sw	$s3,0x260($t3)
.L0f0ca5ac:
/*  f0ca5ac:	00152e00 */ 	sll	$a1,$s5,0x18
/*  f0ca5b0:	00056603 */ 	sra	$t4,$a1,0x18
/*  f0ca5b4:	01802825 */ 	or	$a1,$t4,$zero
/*  f0ca5b8:	0c0052d4 */ 	jal	joyGetButtonsPressedOnSample
/*  f0ca5bc:	97a60052 */ 	lhu	$a2,0x52($sp)
/*  f0ca5c0:	5040000c */ 	beqzl	$v0,.L0f0ca5f4
/*  f0ca5c4:	8e4e0288 */ 	lw	$t6,0x288($s2)
/*  f0ca5c8:	8fa2021c */ 	lw	$v0,0x21c($sp)
/*  f0ca5cc:	10400003 */ 	beqz	$v0,.L0f0ca5dc
/*  f0ca5d0:	2442ffff */ 	addiu	$v0,$v0,-1
/*  f0ca5d4:	10000004 */ 	b	.L0f0ca5e8
/*  f0ca5d8:	afa2021c */ 	sw	$v0,0x21c($sp)
.L0f0ca5dc:
/*  f0ca5dc:	8fa20218 */ 	lw	$v0,0x218($sp)
/*  f0ca5e0:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f0ca5e4:	afa20218 */ 	sw	$v0,0x218($sp)
.L0f0ca5e8:
/*  f0ca5e8:	8e4d0284 */ 	lw	$t5,0x284($s2)
/*  f0ca5ec:	adb30260 */ 	sw	$s3,0x260($t5)
.L0f0ca5f0:
/*  f0ca5f0:	8e4e0288 */ 	lw	$t6,0x288($s2)
.L0f0ca5f4:
/*  f0ca5f4:	0fc549fb */ 	jal	optionsGetAimControl
/*  f0ca5f8:	8dc40070 */ 	lw	$a0,0x70($t6)
/*  f0ca5fc:	14400019 */ 	bnez	$v0,.L0f0ca664
/*  f0ca600:	00107880 */ 	sll	$t7,$s0,0x2
/*  f0ca604:	03afc021 */ 	addu	$t8,$sp,$t7
/*  f0ca608:	8f18014c */ 	lw	$t8,0x14c($t8)
/*  f0ca60c:	53000008 */ 	beqzl	$t8,.L0f0ca630
/*  f0ca610:	8e450284 */ 	lw	$a1,0x284($s2)
/*  f0ca614:	8e450284 */ 	lw	$a1,0x284($s2)
/*  f0ca618:	8ca20260 */ 	lw	$v0,0x260($a1)
/*  f0ca61c:	04400011 */ 	bltz	$v0,.L0f0ca664
/*  f0ca620:	24590001 */ 	addiu	$t9,$v0,0x1
/*  f0ca624:	1000000f */ 	b	.L0f0ca664
/*  f0ca628:	acb90260 */ 	sw	$t9,0x260($a1)
/*  f0ca62c:	8e450284 */ 	lw	$a1,0x284($s2)
.L0f0ca630:
/*  f0ca630:	8ca20260 */ 	lw	$v0,0x260($a1)
/*  f0ca634:	1840000a */ 	blez	$v0,.L0f0ca660
/*  f0ca638:	2841000f */ 	slti	$at,$v0,0xc
/*  f0ca63c:	10200008 */ 	beqz	$at,.L0f0ca660
/*  f0ca640:	8fa20218 */ 	lw	$v0,0x218($sp)
/*  f0ca644:	10400003 */ 	beqz	$v0,.L0f0ca654
/*  f0ca648:	2442ffff */ 	addiu	$v0,$v0,-1
/*  f0ca64c:	10000004 */ 	b	.L0f0ca660
/*  f0ca650:	afa20218 */ 	sw	$v0,0x218($sp)
.L0f0ca654:
/*  f0ca654:	8fa2021c */ 	lw	$v0,0x21c($sp)
/*  f0ca658:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f0ca65c:	afa2021c */ 	sw	$v0,0x21c($sp)
.L0f0ca660:
/*  f0ca660:	aca00260 */ 	sw	$zero,0x260($a1)
.L0f0ca664:
/*  f0ca664:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f0ca668:	5616ffb3 */ 	bnel	$s0,$s6,.L0f0ca538
/*  f0ca66c:	8fae01a8 */ 	lw	$t6,0x1a8($sp)
.L0f0ca670:
/*  f0ca670:	0fc331a0 */ 	jal	bmoveGetCrouchPos
/*  f0ca674:	00000000 */ 	nop
/*  f0ca678:	1440001e */ 	bnez	$v0,.L0f0ca6f4
/*  f0ca67c:	00000000 */ 	nop
/*  f0ca680:	8e450284 */ 	lw	$a1,0x284($s2)
/*  f0ca684:	3c01c2b4 */ 	lui	$at,0xc2b4
/*  f0ca688:	44818000 */ 	mtc1	$at,$f16
/*  f0ca68c:	c4b200b4 */ 	lwc1	$f18,0xb4($a1)
/*  f0ca690:	46128032 */ 	c.eq.s	$f16,$f18
/*  f0ca694:	00000000 */ 	nop
/*  f0ca698:	45000016 */ 	bc1f	.L0f0ca6f4
/*  f0ca69c:	00000000 */ 	nop
/*  f0ca6a0:	8e480314 */ 	lw	$t0,0x314($s2)
/*  f0ca6a4:	11000013 */ 	beqz	$t0,.L0f0ca6f4
/*  f0ca6a8:	00000000 */ 	nop
/*  f0ca6ac:	8e490298 */ 	lw	$t1,0x298($s2)
/*  f0ca6b0:	05210010 */ 	bgez	$t1,.L0f0ca6f4
/*  f0ca6b4:	00000000 */ 	nop
/*  f0ca6b8:	8ca40120 */ 	lw	$a0,0x120($a1)
/*  f0ca6bc:	8fa201a8 */ 	lw	$v0,0x1a8($sp)
/*  f0ca6c0:	0004502b */ 	sltu	$t2,$zero,$a0
/*  f0ca6c4:	1140000a */ 	beqz	$t2,.L0f0ca6f0
/*  f0ca6c8:	01402025 */ 	or	$a0,$t2,$zero
/*  f0ca6cc:	2c440001 */ 	sltiu	$a0,$v0,0x1
/*  f0ca6d0:	10800007 */ 	beqz	$a0,.L0f0ca6f0
/*  f0ca6d4:	97ad019e */ 	lhu	$t5,0x19e($sp)
/*  f0ca6d8:	00152600 */ 	sll	$a0,$s5,0x18
/*  f0ca6dc:	00046603 */ 	sra	$t4,$a0,0x18
/*  f0ca6e0:	01802025 */ 	or	$a0,$t4,$zero
/*  f0ca6e4:	0c0053d8 */ 	jal	joyGetButtons
/*  f0ca6e8:	31a50404 */ 	andi	$a1,$t5,0x404
/*  f0ca6ec:	0002202b */ 	sltu	$a0,$zero,$v0
.L0f0ca6f0:
/*  f0ca6f0:	afa40234 */ 	sw	$a0,0x234($sp)
.L0f0ca6f4:
/*  f0ca6f4:	0fc2866a */ 	jal	bgunGetWeaponNum
/*  f0ca6f8:	00002025 */ 	or	$a0,$zero,$zero
/*  f0ca6fc:	24010016 */ 	addiu	$at,$zero,0x16
/*  f0ca700:	5441000c */ 	bnel	$v0,$at,.L0f0ca734
/*  f0ca704:	8e450284 */ 	lw	$a1,0x284($s2)
/*  f0ca708:	8e450284 */ 	lw	$a1,0x284($s2)
/*  f0ca70c:	8ca40120 */ 	lw	$a0,0x120($a1)
/*  f0ca710:	0004782b */ 	sltu	$t7,$zero,$a0
/*  f0ca714:	11e00004 */ 	beqz	$t7,.L0f0ca728
/*  f0ca718:	01e02025 */ 	or	$a0,$t7,$zero
/*  f0ca71c:	8fa40048 */ 	lw	$a0,0x48($sp)
/*  f0ca720:	30980303 */ 	andi	$t8,$a0,0x303
/*  f0ca724:	0018202b */ 	sltu	$a0,$zero,$t8
.L0f0ca728:
/*  f0ca728:	10000012 */ 	b	.L0f0ca774
/*  f0ca72c:	afa40230 */ 	sw	$a0,0x230($sp)
/*  f0ca730:	8e450284 */ 	lw	$a1,0x284($s2)
.L0f0ca734:
/*  f0ca734:	8ca40120 */ 	lw	$a0,0x120($a1)
/*  f0ca738:	0004402b */ 	sltu	$t0,$zero,$a0
/*  f0ca73c:	11000004 */ 	beqz	$t0,.L0f0ca750
/*  f0ca740:	01002025 */ 	or	$a0,$t0,$zero
/*  f0ca744:	8fa40048 */ 	lw	$a0,0x48($sp)
/*  f0ca748:	30890202 */ 	andi	$t1,$a0,0x202
/*  f0ca74c:	0009202b */ 	sltu	$a0,$zero,$t1
.L0f0ca750:
/*  f0ca750:	afa40220 */ 	sw	$a0,0x220($sp)
/*  f0ca754:	8ca40120 */ 	lw	$a0,0x120($a1)
/*  f0ca758:	0004582b */ 	sltu	$t3,$zero,$a0
/*  f0ca75c:	11600004 */ 	beqz	$t3,.L0f0ca770
/*  f0ca760:	01602025 */ 	or	$a0,$t3,$zero
/*  f0ca764:	8fa40048 */ 	lw	$a0,0x48($sp)
/*  f0ca768:	308c0101 */ 	andi	$t4,$a0,0x101
/*  f0ca76c:	000c202b */ 	sltu	$a0,$zero,$t4
.L0f0ca770:
/*  f0ca770:	afa40224 */ 	sw	$a0,0x224($sp)
.L0f0ca774:
/*  f0ca774:	8fae0048 */ 	lw	$t6,0x48($sp)
/*  f0ca778:	8faf0038 */ 	lw	$t7,0x38($sp)
/*  f0ca77c:	97b901a0 */ 	lhu	$t9,0x1a0($sp)
/*  f0ca780:	8fa90048 */ 	lw	$t1,0x48($sp)
/*  f0ca784:	01cfc024 */ 	and	$t8,$t6,$t7
/*  f0ca788:	13000002 */ 	beqz	$t8,.L0f0ca794
/*  f0ca78c:	33284000 */ 	andi	$t0,$t9,0x4000
/*  f0ca790:	15000007 */ 	bnez	$t0,.L0f0ca7b0
.L0f0ca794:
/*  f0ca794:	312a4000 */ 	andi	$t2,$t1,0x4000
/*  f0ca798:	11400012 */ 	beqz	$t2,.L0f0ca7e4
/*  f0ca79c:	97ab01a0 */ 	lhu	$t3,0x1a0($sp)
/*  f0ca7a0:	8fac0038 */ 	lw	$t4,0x38($sp)
/*  f0ca7a4:	016c6824 */ 	and	$t5,$t3,$t4
/*  f0ca7a8:	51a0000f */ 	beqzl	$t5,.L0f0ca7e8
/*  f0ca7ac:	8e450284 */ 	lw	$a1,0x284($s2)
.L0f0ca7b0:
/*  f0ca7b0:	8fae01ac */ 	lw	$t6,0x1ac($sp)
/*  f0ca7b4:	24010022 */ 	addiu	$at,$zero,0x22
/*  f0ca7b8:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f0ca7bc:	15c10009 */ 	bne	$t6,$at,.L0f0ca7e4
/*  f0ca7c0:	2418fffe */ 	addiu	$t8,$zero,-2
/*  f0ca7c4:	afaf0228 */ 	sw	$t7,0x228($sp)
/*  f0ca7c8:	afa001fc */ 	sw	$zero,0x1fc($sp)
/*  f0ca7cc:	afa00200 */ 	sw	$zero,0x200($sp)
/*  f0ca7d0:	afa001c0 */ 	sw	$zero,0x1c0($sp)
/*  f0ca7d4:	a4b8024c */ 	sh	$t8,0x24c($a1)
/*  f0ca7d8:	8e480284 */ 	lw	$t0,0x284($s2)
/*  f0ca7dc:	2419fffe */ 	addiu	$t9,$zero,-2
/*  f0ca7e0:	a519024e */ 	sh	$t9,0x24e($t0)
.L0f0ca7e4:
/*  f0ca7e4:	8e450284 */ 	lw	$a1,0x284($s2)
.L0f0ca7e8:
/*  f0ca7e8:	97ac01a2 */ 	lhu	$t4,0x1a2($sp)
/*  f0ca7ec:	8ca90120 */ 	lw	$t1,0x120($a1)
/*  f0ca7f0:	01946824 */ 	and	$t5,$t4,$s4
/*  f0ca7f4:	afa90208 */ 	sw	$t1,0x208($sp)
/*  f0ca7f8:	8caa0120 */ 	lw	$t2,0x120($a1)
/*  f0ca7fc:	afaa020c */ 	sw	$t2,0x20c($sp)
/*  f0ca800:	8cab0274 */ 	lw	$t3,0x274($a1)
/*  f0ca804:	11600004 */ 	beqz	$t3,.L0f0ca818
/*  f0ca808:	00000000 */ 	nop
/*  f0ca80c:	15a00002 */ 	bnez	$t5,.L0f0ca818
/*  f0ca810:	00000000 */ 	nop
/*  f0ca814:	aca00274 */ 	sw	$zero,0x274($a1)
.L0f0ca818:
/*  f0ca818:	0fc2866a */ 	jal	bgunGetWeaponNum
/*  f0ca81c:	00002025 */ 	or	$a0,$zero,$zero
/*  f0ca820:	00402025 */ 	or	$a0,$v0,$zero
/*  f0ca824:	0fc2c5f0 */ 	jal	weaponHasFlag
/*  f0ca828:	3c058000 */ 	lui	$a1,0x8000
/*  f0ca82c:	1040000d */ 	beqz	$v0,.L0f0ca864
/*  f0ca830:	97ae01a0 */ 	lhu	$t6,0x1a0($sp)
/*  f0ca834:	01d47824 */ 	and	$t7,$t6,$s4
/*  f0ca838:	11e00008 */ 	beqz	$t7,.L0f0ca85c
/*  f0ca83c:	00000000 */ 	nop
/*  f0ca840:	8e580284 */ 	lw	$t8,0x284($s2)
/*  f0ca844:	8fa801c0 */ 	lw	$t0,0x1c0($sp)
/*  f0ca848:	8f191a24 */ 	lw	$t9,0x1a24($t8)
/*  f0ca84c:	25090001 */ 	addiu	$t1,$t0,0x1
/*  f0ca850:	17200002 */ 	bnez	$t9,.L0f0ca85c
/*  f0ca854:	00000000 */ 	nop
/*  f0ca858:	afa901c0 */ 	sw	$t1,0x1c0($sp)
.L0f0ca85c:
/*  f0ca85c:	10000014 */ 	b	.L0f0ca8b0
/*  f0ca860:	8e450284 */ 	lw	$a1,0x284($s2)
.L0f0ca864:
/*  f0ca864:	8e450284 */ 	lw	$a1,0x284($s2)
/*  f0ca868:	97a301a2 */ 	lhu	$v1,0x1a2($sp)
/*  f0ca86c:	8ca40274 */ 	lw	$a0,0x274($a1)
/*  f0ca870:	00741024 */ 	and	$v0,$v1,$s4
/*  f0ca874:	2c8a0001 */ 	sltiu	$t2,$a0,0x1
/*  f0ca878:	1140000c */ 	beqz	$t2,.L0f0ca8ac
/*  f0ca87c:	01402025 */ 	or	$a0,$t2,$zero
/*  f0ca880:	0002202b */ 	sltu	$a0,$zero,$v0
/*  f0ca884:	5080000a */ 	beqzl	$a0,.L0f0ca8b0
/*  f0ca888:	afa401bc */ 	sw	$a0,0x1bc($sp)
/*  f0ca88c:	8ca41a24 */ 	lw	$a0,0x1a24($a1)
/*  f0ca890:	97ad00ca */ 	lhu	$t5,0xca($sp)
/*  f0ca894:	2c8c0001 */ 	sltiu	$t4,$a0,0x1
/*  f0ca898:	11800004 */ 	beqz	$t4,.L0f0ca8ac
/*  f0ca89c:	01802025 */ 	or	$a0,$t4,$zero
/*  f0ca8a0:	006d2024 */ 	and	$a0,$v1,$t5
/*  f0ca8a4:	2c8e0001 */ 	sltiu	$t6,$a0,0x1
/*  f0ca8a8:	01c02025 */ 	or	$a0,$t6,$zero
.L0f0ca8ac:
/*  f0ca8ac:	afa401bc */ 	sw	$a0,0x1bc($sp)
.L0f0ca8b0:
/*  f0ca8b0:	8faf01b0 */ 	lw	$t7,0x1b0($sp)
/*  f0ca8b4:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0ca8b8:	24180001 */ 	addiu	$t8,$zero,0x1
/*  f0ca8bc:	11e10003 */ 	beq	$t7,$at,.L0f0ca8cc
/*  f0ca8c0:	24010003 */ 	addiu	$at,$zero,0x3
/*  f0ca8c4:	55e10003 */ 	bnel	$t7,$at,.L0f0ca8d4
/*  f0ca8c8:	aca000d0 */ 	sw	$zero,0xd0($a1)
.L0f0ca8cc:
/*  f0ca8cc:	afb8023c */ 	sw	$t8,0x23c($sp)
.L0f0ca8d0:
/*  f0ca8d0:	aca000d0 */ 	sw	$zero,0xd0($a1)
.L0f0ca8d4:
/*  f0ca8d4:	8fb901c0 */ 	lw	$t9,0x1c0($sp)
/*  f0ca8d8:	5320000c */ 	beqzl	$t9,.L0f0ca90c
/*  f0ca8dc:	8fad0238 */ 	lw	$t5,0x238($sp)
/*  f0ca8e0:	8e450284 */ 	lw	$a1,0x284($s2)
/*  f0ca8e4:	8ca801a0 */ 	lw	$t0,0x1a0($a1)
/*  f0ca8e8:	aca8019c */ 	sw	$t0,0x19c($a1)
/*  f0ca8ec:	8e4a0284 */ 	lw	$t2,0x284($s2)
/*  f0ca8f0:	8e490008 */ 	lw	$t1,0x8($s2)
/*  f0ca8f4:	ad4901a0 */ 	sw	$t1,0x1a0($t2)
/*  f0ca8f8:	8e4c0284 */ 	lw	$t4,0x284($s2)
/*  f0ca8fc:	8fab01c0 */ 	lw	$t3,0x1c0($sp)
/*  f0ca900:	0fc31fcb */ 	jal	bmoveHandleActivate
/*  f0ca904:	ad8b00d0 */ 	sw	$t3,0xd0($t4)
/*  f0ca908:	8fad0238 */ 	lw	$t5,0x238($sp)
.L0f0ca90c:
/*  f0ca90c:	15a0000b */ 	bnez	$t5,.L0f0ca93c
/*  f0ca910:	00000000 */ 	nop
/*  f0ca914:	8fa4024c */ 	lw	$a0,0x24c($sp)
/*  f0ca918:	8fae0254 */ 	lw	$t6,0x254($sp)
/*  f0ca91c:	c7a001ec */ 	lwc1	$f0,0x1ec($sp)
/*  f0ca920:	c7a401f0 */ 	lwc1	$f4,0x1f0($sp)
/*  f0ca924:	00042023 */ 	negu	$a0,$a0
/*  f0ca928:	000e7823 */ 	negu	$t7,$t6
/*  f0ca92c:	afaf0254 */ 	sw	$t7,0x254($sp)
/*  f0ca930:	afa4024c */ 	sw	$a0,0x24c($sp)
/*  f0ca934:	e7a001f0 */ 	swc1	$f0,0x1f0($sp)
/*  f0ca938:	e7a401ec */ 	swc1	$f4,0x1ec($sp)
.L0f0ca93c:
/*  f0ca93c:	0fc2a34d */ 	jal	bgunsTick
/*  f0ca940:	8fa401bc */ 	lw	$a0,0x1bc($sp)
/*  f0ca944:	8e580324 */ 	lw	$t8,0x324($s2)
/*  f0ca948:	5300002b */ 	beqzl	$t8,.L0f0ca9f8
/*  f0ca94c:	24040002 */ 	addiu	$a0,$zero,0x2
/*  f0ca950:	0fc2883f */ 	jal	bgunIsFiring
/*  f0ca954:	00002025 */ 	or	$a0,$zero,$zero
/*  f0ca958:	54400006 */ 	bnezl	$v0,.L0f0ca974
/*  f0ca95c:	44805000 */ 	mtc1	$zero,$f10
/*  f0ca960:	0fc2883f */ 	jal	bgunIsFiring
/*  f0ca964:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f0ca968:	50400023 */ 	beqzl	$v0,.L0f0ca9f8
/*  f0ca96c:	24040002 */ 	addiu	$a0,$zero,0x2
/*  f0ca970:	44805000 */ 	mtc1	$zero,$f10
.L0f0ca974:
/*  f0ca974:	00002025 */ 	or	$a0,$zero,$zero
/*  f0ca978:	0fc2883f */ 	jal	bgunIsFiring
/*  f0ca97c:	e7aa00b4 */ 	swc1	$f10,0xb4($sp)
/*  f0ca980:	1040000c */ 	beqz	$v0,.L0f0ca9b4
/*  f0ca984:	00000000 */ 	nop
/*  f0ca988:	0fc273d6 */ 	jal	bgunGetNoiseRadius
/*  f0ca98c:	00002025 */ 	or	$a0,$zero,$zero
/*  f0ca990:	44803000 */ 	mtc1	$zero,$f6
/*  f0ca994:	00000000 */ 	nop
/*  f0ca998:	4600303c */ 	c.lt.s	$f6,$f0
/*  f0ca99c:	00000000 */ 	nop
/*  f0ca9a0:	45000004 */ 	bc1f	.L0f0ca9b4
/*  f0ca9a4:	00000000 */ 	nop
/*  f0ca9a8:	0fc273d6 */ 	jal	bgunGetNoiseRadius
/*  f0ca9ac:	00002025 */ 	or	$a0,$zero,$zero
/*  f0ca9b0:	e7a000b4 */ 	swc1	$f0,0xb4($sp)
.L0f0ca9b4:
/*  f0ca9b4:	0fc2883f */ 	jal	bgunIsFiring
/*  f0ca9b8:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f0ca9bc:	1040000b */ 	beqz	$v0,.L0f0ca9ec
/*  f0ca9c0:	00000000 */ 	nop
/*  f0ca9c4:	0fc273d6 */ 	jal	bgunGetNoiseRadius
/*  f0ca9c8:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f0ca9cc:	c7a800b4 */ 	lwc1	$f8,0xb4($sp)
/*  f0ca9d0:	4600403c */ 	c.lt.s	$f8,$f0
/*  f0ca9d4:	00000000 */ 	nop
/*  f0ca9d8:	45000004 */ 	bc1f	.L0f0ca9ec
/*  f0ca9dc:	00000000 */ 	nop
/*  f0ca9e0:	0fc273d6 */ 	jal	bgunGetNoiseRadius
/*  f0ca9e4:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f0ca9e8:	e7a000b4 */ 	swc1	$f0,0xb4($sp)
.L0f0ca9ec:
/*  f0ca9ec:	0fc0a164 */ 	jal	func0f028590
/*  f0ca9f0:	c7ac00b4 */ 	lwc1	$f12,0xb4($sp)
/*  f0ca9f4:	24040002 */ 	addiu	$a0,$zero,0x2
.L0f0ca9f8:
/*  f0ca9f8:	0fc2af1d */ 	jal	bgunSetSightVisible
/*  f0ca9fc:	8fa50208 */ 	lw	$a1,0x208($sp)
/*  f0caa00:	c7ac0210 */ 	lwc1	$f12,0x210($sp)
/*  f0caa04:	44808000 */ 	mtc1	$zero,$f16
/*  f0caa08:	00000000 */ 	nop
/*  f0caa0c:	460c803c */ 	c.lt.s	$f16,$f12
/*  f0caa10:	00000000 */ 	nop
/*  f0caa14:	45020004 */ 	bc1fl	.L0f0caa28
/*  f0caa18:	c7ac0214 */ 	lwc1	$f12,0x214($sp)
/*  f0caa1c:	0fc2c562 */ 	jal	currentPlayerZoomOut
/*  f0caa20:	e7ac0210 */ 	swc1	$f12,0x210($sp)
/*  f0caa24:	c7ac0214 */ 	lwc1	$f12,0x214($sp)
.L0f0caa28:
/*  f0caa28:	44809000 */ 	mtc1	$zero,$f18
/*  f0caa2c:	00000000 */ 	nop
/*  f0caa30:	460c903c */ 	c.lt.s	$f18,$f12
/*  f0caa34:	00000000 */ 	nop
/*  f0caa38:	45020004 */ 	bc1fl	.L0f0caa4c
/*  f0caa3c:	8e590284 */ 	lw	$t9,0x284($s2)
/*  f0caa40:	0fc2c5a9 */ 	jal	currentPlayerZoomIn
/*  f0caa44:	e7ac0214 */ 	swc1	$f12,0x214($sp)
/*  f0caa48:	8e590284 */ 	lw	$t9,0x284($s2)
.L0f0caa4c:
/*  f0caa4c:	8f281a24 */ 	lw	$t0,0x1a24($t9)
/*  f0caa50:	150000b5 */ 	bnez	$t0,.L0f0cad28
/*  f0caa54:	3c098006 */ 	lui	$t1,%hi(g_MainIsEndscreen)
/*  f0caa58:	8d29d9d0 */ 	lw	$t1,%lo(g_MainIsEndscreen)($t1)
/*  f0caa5c:	3c014270 */ 	lui	$at,0x4270
/*  f0caa60:	152000b1 */ 	bnez	$t1,.L0f0cad28
/*  f0caa64:	00000000 */ 	nop
/*  f0caa68:	44812000 */ 	mtc1	$at,$f4
/*  f0caa6c:	00002025 */ 	or	$a0,$zero,$zero
/*  f0caa70:	0fc2866a */ 	jal	bgunGetWeaponNum
/*  f0caa74:	e7a400b0 */ 	swc1	$f4,0xb0($sp)
/*  f0caa78:	24010016 */ 	addiu	$at,$zero,0x16
/*  f0caa7c:	5441008b */ 	bnel	$v0,$at,.L0f0cacac
/*  f0caa80:	8fb8020c */ 	lw	$t8,0x20c($sp)
/*  f0caa84:	8e450284 */ 	lw	$a1,0x284($s2)
/*  f0caa88:	8fab0230 */ 	lw	$t3,0x230($sp)
/*  f0caa8c:	8caa0120 */ 	lw	$t2,0x120($a1)
/*  f0caa90:	51400086 */ 	beqzl	$t2,.L0f0cacac
/*  f0caa94:	8fb8020c */ 	lw	$t8,0x20c($sp)
/*  f0caa98:	55600006 */ 	bnezl	$t3,.L0f0caab4
/*  f0caa9c:	c4a00258 */ 	lwc1	$f0,0x258($a1)
/*  f0caaa0:	90ac063b */ 	lbu	$t4,0x63b($a1)
/*  f0caaa4:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0caaa8:	55810080 */ 	bnel	$t4,$at,.L0f0cacac
/*  f0caaac:	8fb8020c */ 	lw	$t8,0x20c($sp)
/*  f0caab0:	c4a00258 */ 	lwc1	$f0,0x258($a1)
.L0f0caab4:
/*  f0caab4:	44805000 */ 	mtc1	$zero,$f10
/*  f0caab8:	3c0143fa */ 	lui	$at,0x43fa
/*  f0caabc:	4600503c */ 	c.lt.s	$f10,$f0
/*  f0caac0:	00000000 */ 	nop
/*  f0caac4:	45020079 */ 	bc1fl	.L0f0cacac
/*  f0caac8:	8fb8020c */ 	lw	$t8,0x20c($sp)
/*  f0caacc:	44813000 */ 	mtc1	$at,$f6
/*  f0caad0:	0fc2d26e */ 	jal	func0f0b49b8
/*  f0caad4:	46003303 */ 	div.s	$f12,$f6,$f0
/*  f0caad8:	3c014270 */ 	lui	$at,0x4270
/*  f0caadc:	44816000 */ 	mtc1	$at,$f12
/*  f0caae0:	46000086 */ 	mov.s	$f2,$f0
/*  f0caae4:	3c014000 */ 	lui	$at,0x4000
/*  f0caae8:	4600603c */ 	c.lt.s	$f12,$f0
/*  f0caaec:	44810000 */ 	mtc1	$at,$f0
/*  f0caaf0:	45020003 */ 	bc1fl	.L0f0cab00
/*  f0caaf4:	4600103c */ 	c.lt.s	$f2,$f0
/*  f0caaf8:	46006086 */ 	mov.s	$f2,$f12
/*  f0caafc:	4600103c */ 	c.lt.s	$f2,$f0
.L0f0cab00:
/*  f0cab00:	00000000 */ 	nop
/*  f0cab04:	45020003 */ 	bc1fl	.L0f0cab14
/*  f0cab08:	8e4d0284 */ 	lw	$t5,0x284($s2)
/*  f0cab0c:	46000086 */ 	mov.s	$f2,$f0
/*  f0cab10:	8e4d0284 */ 	lw	$t5,0x284($s2)
.L0f0cab14:
/*  f0cab14:	e5a216f8 */ 	swc1	$f2,0x16f8($t5)
/*  f0cab18:	0fc2d5be */ 	jal	currentPlayerGetMatrix1740
/*  f0cab1c:	e7a200ac */ 	swc1	$f2,0xac($sp)
/*  f0cab20:	8e4e0284 */ 	lw	$t6,0x284($s2)
/*  f0cab24:	27b000a0 */ 	addiu	$s0,$sp,0xa0
/*  f0cab28:	02003025 */ 	or	$a2,$s0,$zero
/*  f0cab2c:	8dc5025c */ 	lw	$a1,0x25c($t6)
/*  f0cab30:	00402025 */ 	or	$a0,$v0,$zero
/*  f0cab34:	0c0056da */ 	jal	func00015b68
/*  f0cab38:	24a50008 */ 	addiu	$a1,$a1,0x8
/*  f0cab3c:	c7a200ac */ 	lwc1	$f2,0xac($sp)
/*  f0cab40:	8e4f0284 */ 	lw	$t7,0x284($s2)
/*  f0cab44:	02002025 */ 	or	$a0,$s0,$zero
/*  f0cab48:	44061000 */ 	mfc1	$a2,$f2
/*  f0cab4c:	27a50098 */ 	addiu	$a1,$sp,0x98
/*  f0cab50:	0fc2d3ae */ 	jal	func0f0b4eb8
/*  f0cab54:	8de7171c */ 	lw	$a3,0x171c($t7)
/*  f0cab58:	0fc2d5fe */ 	jal	currentPlayerGetScreenLeft
/*  f0cab5c:	00000000 */ 	nop
/*  f0cab60:	0fc2d5f6 */ 	jal	currentPlayerGetScreenWidth
/*  f0cab64:	e7a00054 */ 	swc1	$f0,0x54($sp)
/*  f0cab68:	3c013f00 */ 	lui	$at,0x3f00
/*  f0cab6c:	44818000 */ 	mtc1	$at,$f16
/*  f0cab70:	c7a40054 */ 	lwc1	$f4,0x54($sp)
/*  f0cab74:	3c0141a0 */ 	lui	$at,0x41a0
/*  f0cab78:	46100482 */ 	mul.s	$f18,$f0,$f16
/*  f0cab7c:	44813000 */ 	mtc1	$at,$f6
/*  f0cab80:	c7a80098 */ 	lwc1	$f8,0x98($sp)
/*  f0cab84:	3c013e80 */ 	lui	$at,0x3e80
/*  f0cab88:	46049280 */ 	add.s	$f10,$f18,$f4
/*  f0cab8c:	46065401 */ 	sub.s	$f16,$f10,$f6
/*  f0cab90:	4610403c */ 	c.lt.s	$f8,$f16
/*  f0cab94:	00000000 */ 	nop
/*  f0cab98:	45000004 */ 	bc1f	.L0f0cabac
/*  f0cab9c:	00000000 */ 	nop
/*  f0caba0:	44816000 */ 	mtc1	$at,$f12
/*  f0caba4:	10000016 */ 	b	.L0f0cac00
/*  f0caba8:	e7ac01f4 */ 	swc1	$f12,0x1f4($sp)
.L0f0cabac:
/*  f0cabac:	0fc2d5fe */ 	jal	currentPlayerGetScreenLeft
/*  f0cabb0:	00000000 */ 	nop
/*  f0cabb4:	0fc2d5f6 */ 	jal	currentPlayerGetScreenWidth
/*  f0cabb8:	e7a00054 */ 	swc1	$f0,0x54($sp)
/*  f0cabbc:	3c013f00 */ 	lui	$at,0x3f00
/*  f0cabc0:	44819000 */ 	mtc1	$at,$f18
/*  f0cabc4:	c7aa0054 */ 	lwc1	$f10,0x54($sp)
/*  f0cabc8:	3c0141a0 */ 	lui	$at,0x41a0
/*  f0cabcc:	46120102 */ 	mul.s	$f4,$f0,$f18
/*  f0cabd0:	44814000 */ 	mtc1	$at,$f8
/*  f0cabd4:	c7b20098 */ 	lwc1	$f18,0x98($sp)
/*  f0cabd8:	3c013e80 */ 	lui	$at,0x3e80
/*  f0cabdc:	460a2180 */ 	add.s	$f6,$f4,$f10
/*  f0cabe0:	46083400 */ 	add.s	$f16,$f6,$f8
/*  f0cabe4:	4612803c */ 	c.lt.s	$f16,$f18
/*  f0cabe8:	00000000 */ 	nop
/*  f0cabec:	45000004 */ 	bc1f	.L0f0cac00
/*  f0cabf0:	00000000 */ 	nop
/*  f0cabf4:	44810000 */ 	mtc1	$at,$f0
/*  f0cabf8:	00000000 */ 	nop
/*  f0cabfc:	e7a001f8 */ 	swc1	$f0,0x1f8($sp)
.L0f0cac00:
/*  f0cac00:	0fc2d602 */ 	jal	currentPlayerGetScreenTop
/*  f0cac04:	00000000 */ 	nop
/*  f0cac08:	0fc2d5fa */ 	jal	currentPlayerGetScreenHeight
/*  f0cac0c:	e7a00054 */ 	swc1	$f0,0x54($sp)
/*  f0cac10:	3c013f00 */ 	lui	$at,0x3f00
/*  f0cac14:	44815000 */ 	mtc1	$at,$f10
/*  f0cac18:	c7a80054 */ 	lwc1	$f8,0x54($sp)
/*  f0cac1c:	3c0141a0 */ 	lui	$at,0x41a0
/*  f0cac20:	460a0182 */ 	mul.s	$f6,$f0,$f10
/*  f0cac24:	44819000 */ 	mtc1	$at,$f18
/*  f0cac28:	c7a4009c */ 	lwc1	$f4,0x9c($sp)
/*  f0cac2c:	3c013e80 */ 	lui	$at,0x3e80
/*  f0cac30:	46083400 */ 	add.s	$f16,$f6,$f8
/*  f0cac34:	46128281 */ 	sub.s	$f10,$f16,$f18
/*  f0cac38:	460a203c */ 	c.lt.s	$f4,$f10
/*  f0cac3c:	00000000 */ 	nop
/*  f0cac40:	45000004 */ 	bc1f	.L0f0cac54
/*  f0cac44:	00000000 */ 	nop
/*  f0cac48:	44813000 */ 	mtc1	$at,$f6
/*  f0cac4c:	10000016 */ 	b	.L0f0caca8
/*  f0cac50:	e7a601f0 */ 	swc1	$f6,0x1f0($sp)
.L0f0cac54:
/*  f0cac54:	0fc2d602 */ 	jal	currentPlayerGetScreenTop
/*  f0cac58:	00000000 */ 	nop
/*  f0cac5c:	0fc2d5fa */ 	jal	currentPlayerGetScreenHeight
/*  f0cac60:	e7a00054 */ 	swc1	$f0,0x54($sp)
/*  f0cac64:	3c013f00 */ 	lui	$at,0x3f00
/*  f0cac68:	44814000 */ 	mtc1	$at,$f8
/*  f0cac6c:	c7b20054 */ 	lwc1	$f18,0x54($sp)
/*  f0cac70:	3c0141a0 */ 	lui	$at,0x41a0
/*  f0cac74:	46080402 */ 	mul.s	$f16,$f0,$f8
/*  f0cac78:	44815000 */ 	mtc1	$at,$f10
/*  f0cac7c:	c7a8009c */ 	lwc1	$f8,0x9c($sp)
/*  f0cac80:	3c013e80 */ 	lui	$at,0x3e80
/*  f0cac84:	46128100 */ 	add.s	$f4,$f16,$f18
/*  f0cac88:	460a2180 */ 	add.s	$f6,$f4,$f10
/*  f0cac8c:	4608303c */ 	c.lt.s	$f6,$f8
/*  f0cac90:	00000000 */ 	nop
/*  f0cac94:	45020005 */ 	bc1fl	.L0f0cacac
/*  f0cac98:	8fb8020c */ 	lw	$t8,0x20c($sp)
/*  f0cac9c:	44818000 */ 	mtc1	$at,$f16
/*  f0caca0:	00000000 */ 	nop
/*  f0caca4:	e7b001ec */ 	swc1	$f16,0x1ec($sp)
.L0f0caca8:
/*  f0caca8:	8fb8020c */ 	lw	$t8,0x20c($sp)
.L0f0cacac:
/*  f0cacac:	13000004 */ 	beqz	$t8,.L0f0cacc0
/*  f0cacb0:	00000000 */ 	nop
/*  f0cacb4:	0fc2c536 */ 	jal	currentPlayerGetGunZoomFov
/*  f0cacb8:	00000000 */ 	nop
/*  f0cacbc:	e7a000b0 */ 	swc1	$f0,0xb0($sp)
.L0f0cacc0:
/*  f0cacc0:	0fc2866a */ 	jal	bgunGetWeaponNum
/*  f0cacc4:	00002025 */ 	or	$a0,$zero,$zero
/*  f0cacc8:	24010011 */ 	addiu	$at,$zero,0x11
/*  f0caccc:	5441000a */ 	bnel	$v0,$at,.L0f0cacf8
/*  f0cacd0:	c7ac00b0 */ 	lwc1	$f12,0xb0($sp)
/*  f0cacd4:	8e590284 */ 	lw	$t9,0x284($s2)
/*  f0cacd8:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0cacdc:	9328063b */ 	lbu	$t0,0x63b($t9)
/*  f0cace0:	55010005 */ 	bnel	$t0,$at,.L0f0cacf8
/*  f0cace4:	c7ac00b0 */ 	lwc1	$f12,0xb0($sp)
/*  f0cace8:	0fc2c536 */ 	jal	currentPlayerGetGunZoomFov
/*  f0cacec:	00000000 */ 	nop
/*  f0cacf0:	e7a000b0 */ 	swc1	$f0,0xb0($sp)
/*  f0cacf4:	c7ac00b0 */ 	lwc1	$f12,0xb0($sp)
.L0f0cacf8:
/*  f0cacf8:	44809000 */ 	mtc1	$zero,$f18
/*  f0cacfc:	3c014270 */ 	lui	$at,0x4270
/*  f0cad00:	4612603e */ 	c.le.s	$f12,$f18
/*  f0cad04:	00000000 */ 	nop
/*  f0cad08:	45000003 */ 	bc1f	.L0f0cad18
/*  f0cad0c:	00000000 */ 	nop
/*  f0cad10:	44816000 */ 	mtc1	$at,$f12
/*  f0cad14:	00000000 */ 	nop
.L0f0cad18:
/*  f0cad18:	0fc2ea2c */ 	jal	func0f0ba8b0
/*  f0cad1c:	00000000 */ 	nop
/*  f0cad20:	0fc2eab0 */ 	jal	currentPlayerUpdateZoom
/*  f0cad24:	00000000 */ 	nop
.L0f0cad28:
/*  f0cad28:	0fc31fe6 */ 	jal	bmoveApplyMoveData
/*  f0cad2c:	27a401b4 */ 	addiu	$a0,$sp,0x1b4
/*  f0cad30:	8e450284 */ 	lw	$a1,0x284($s2)
/*  f0cad34:	8ca90178 */ 	lw	$t1,0x178($a1)
/*  f0cad38:	292100b4 */ 	slti	$at,$t1,0x96
/*  f0cad3c:	1420001b */ 	bnez	$at,.L0f0cadac
/*  f0cad40:	3c013fa0 */ 	lui	$at,0x3fa0
/*  f0cad44:	44811000 */ 	mtc1	$at,$f2
/*  f0cad48:	c4a00174 */ 	lwc1	$f0,0x174($a1)
/*  f0cad4c:	3c017f1b */ 	lui	$at,%hi(var7f1ad8b8)
/*  f0cad50:	4602003c */ 	c.lt.s	$f0,$f2
/*  f0cad54:	00000000 */ 	nop
/*  f0cad58:	45020009 */ 	bc1fl	.L0f0cad80
/*  f0cad5c:	4600103c */ 	c.lt.s	$f2,$f0
/*  f0cad60:	c424d8b8 */ 	lwc1	$f4,%lo(var7f1ad8b8)($at)
/*  f0cad64:	c64a004c */ 	lwc1	$f10,0x4c($s2)
/*  f0cad68:	460a2182 */ 	mul.s	$f6,$f4,$f10
/*  f0cad6c:	46060200 */ 	add.s	$f8,$f0,$f6
/*  f0cad70:	e4a80174 */ 	swc1	$f8,0x174($a1)
/*  f0cad74:	8e450284 */ 	lw	$a1,0x284($s2)
/*  f0cad78:	c4a00174 */ 	lwc1	$f0,0x174($a1)
/*  f0cad7c:	4600103c */ 	c.lt.s	$f2,$f0
.L0f0cad80:
/*  f0cad80:	00000000 */ 	nop
/*  f0cad84:	45020024 */ 	bc1fl	.L0f0cae18
/*  f0cad88:	8cab1a24 */ 	lw	$t3,0x1a24($a1)
/*  f0cad8c:	0fc20b5d */ 	jal	piracyRestore
/*  f0cad90:	00000000 */ 	nop
/*  f0cad94:	3c013fa0 */ 	lui	$at,0x3fa0
/*  f0cad98:	44811000 */ 	mtc1	$at,$f2
/*  f0cad9c:	8e4a0284 */ 	lw	$t2,0x284($s2)
/*  f0cada0:	e5420174 */ 	swc1	$f2,0x174($t2)
/*  f0cada4:	1000001b */ 	b	.L0f0cae14
/*  f0cada8:	8e450284 */ 	lw	$a1,0x284($s2)
.L0f0cadac:
/*  f0cadac:	3c013f80 */ 	lui	$at,0x3f80
/*  f0cadb0:	44818000 */ 	mtc1	$at,$f16
/*  f0cadb4:	c4a00174 */ 	lwc1	$f0,0x174($a1)
/*  f0cadb8:	3c017f1b */ 	lui	$at,%hi(var7f1ad8bc)
/*  f0cadbc:	4600803c */ 	c.lt.s	$f16,$f0
/*  f0cadc0:	00000000 */ 	nop
/*  f0cadc4:	45020009 */ 	bc1fl	.L0f0cadec
/*  f0cadc8:	3c013f80 */ 	lui	$at,0x3f80
/*  f0cadcc:	c432d8bc */ 	lwc1	$f18,%lo(var7f1ad8bc)($at)
/*  f0cadd0:	c644004c */ 	lwc1	$f4,0x4c($s2)
/*  f0cadd4:	46049282 */ 	mul.s	$f10,$f18,$f4
/*  f0cadd8:	460a0181 */ 	sub.s	$f6,$f0,$f10
/*  f0caddc:	e4a60174 */ 	swc1	$f6,0x174($a1)
/*  f0cade0:	8e450284 */ 	lw	$a1,0x284($s2)
/*  f0cade4:	c4a00174 */ 	lwc1	$f0,0x174($a1)
/*  f0cade8:	3c013f80 */ 	lui	$at,0x3f80
.L0f0cadec:
/*  f0cadec:	44814000 */ 	mtc1	$at,$f8
/*  f0cadf0:	3c013f80 */ 	lui	$at,0x3f80
/*  f0cadf4:	4608003c */ 	c.lt.s	$f0,$f8
/*  f0cadf8:	00000000 */ 	nop
/*  f0cadfc:	45020006 */ 	bc1fl	.L0f0cae18
/*  f0cae00:	8cab1a24 */ 	lw	$t3,0x1a24($a1)
/*  f0cae04:	44818000 */ 	mtc1	$at,$f16
/*  f0cae08:	00000000 */ 	nop
/*  f0cae0c:	e4b00174 */ 	swc1	$f16,0x174($a1)
/*  f0cae10:	8e450284 */ 	lw	$a1,0x284($s2)
.L0f0cae14:
/*  f0cae14:	8cab1a24 */ 	lw	$t3,0x1a24($a1)
.L0f0cae18:
/*  f0cae18:	55600144 */ 	bnezl	$t3,.L0f0cb32c
/*  f0cae1c:	8faa01cc */ 	lw	$t2,0x1cc($sp)
/*  f0cae20:	8ca201b0 */ 	lw	$v0,0x1b0($a1)
/*  f0cae24:	3c01c080 */ 	lui	$at,0xc080
/*  f0cae28:	44817000 */ 	mtc1	$at,$f14
/*  f0cae2c:	2c440001 */ 	sltiu	$a0,$v0,0x1
/*  f0cae30:	54800004 */ 	bnezl	$a0,.L0f0cae44
/*  f0cae34:	8cac0110 */ 	lw	$t4,0x110($a1)
/*  f0cae38:	38440004 */ 	xori	$a0,$v0,0x4
/*  f0cae3c:	2c840001 */ 	sltiu	$a0,$a0,0x1
/*  f0cae40:	8cac0110 */ 	lw	$t4,0x110($a1)
.L0f0cae44:
/*  f0cae44:	51800011 */ 	beqzl	$t4,.L0f0cae8c
/*  f0cae48:	8cb9010c */ 	lw	$t9,0x10c($a1)
/*  f0cae4c:	8e42000c */ 	lw	$v0,0xc($s2)
/*  f0cae50:	94ad1be4 */ 	lhu	$t5,0x1be4($a1)
/*  f0cae54:	504d000c */ 	beql	$v0,$t5,.L0f0cae88
/*  f0cae58:	c4ae1be0 */ 	lwc1	$f14,0x1be0($a1)
/*  f0cae5c:	8e4e028c */ 	lw	$t6,0x28c($s2)
/*  f0cae60:	304f0003 */ 	andi	$t7,$v0,0x3
/*  f0cae64:	55cf0008 */ 	bnel	$t6,$t7,.L0f0cae88
/*  f0cae68:	c4ae1be0 */ 	lwc1	$f14,0x1be0($a1)
/*  f0cae6c:	0fc32166 */ 	jal	bmoveCalculateLookahead
/*  f0cae70:	afa40064 */ 	sw	$a0,0x64($sp)
/*  f0cae74:	8e580284 */ 	lw	$t8,0x284($s2)
/*  f0cae78:	8fa40064 */ 	lw	$a0,0x64($sp)
/*  f0cae7c:	e7001be0 */ 	swc1	$f0,0x1be0($t8)
/*  f0cae80:	8e450284 */ 	lw	$a1,0x284($s2)
/*  f0cae84:	c4ae1be0 */ 	lwc1	$f14,0x1be0($a1)
.L0f0cae88:
/*  f0cae88:	8cb9010c */ 	lw	$t9,0x10c($a1)
.L0f0cae8c:
/*  f0cae8c:	8fa8025c */ 	lw	$t0,0x25c($sp)
/*  f0cae90:	13200007 */ 	beqz	$t9,.L0f0caeb0
/*  f0cae94:	29010028 */ 	slti	$at,$t0,0x28
/*  f0cae98:	10200005 */ 	beqz	$at,.L0f0caeb0
/*  f0cae9c:	2901ffd9 */ 	slti	$at,$t0,-39
/*  f0caea0:	14200003 */ 	bnez	$at,.L0f0caeb0
/*  f0caea4:	00000000 */ 	nop
/*  f0caea8:	aca0010c */ 	sw	$zero,0x10c($a1)
/*  f0caeac:	8e450284 */ 	lw	$a1,0x284($s2)
.L0f0caeb0:
/*  f0caeb0:	10800064 */ 	beqz	$a0,.L0f0cb044
/*  f0caeb4:	c7a401ec */ 	lwc1	$f4,0x1ec($sp)
/*  f0caeb8:	44809000 */ 	mtc1	$zero,$f18
/*  f0caebc:	c7a601f0 */ 	lwc1	$f6,0x1f0($sp)
/*  f0caec0:	4604903c */ 	c.lt.s	$f18,$f4
/*  f0caec4:	00000000 */ 	nop
/*  f0caec8:	45030008 */ 	bc1tl	.L0f0caeec
/*  f0caecc:	aca00100 */ 	sw	$zero,0x100($a1)
/*  f0caed0:	44805000 */ 	mtc1	$zero,$f10
/*  f0caed4:	8fac023c */ 	lw	$t4,0x23c($sp)
/*  f0caed8:	4606503c */ 	c.lt.s	$f10,$f6
/*  f0caedc:	00000000 */ 	nop
/*  f0caee0:	45000009 */ 	bc1f	.L0f0caf08
/*  f0caee4:	00000000 */ 	nop
/*  f0caee8:	aca00100 */ 	sw	$zero,0x100($a1)
.L0f0caeec:
/*  f0caeec:	8e4a0284 */ 	lw	$t2,0x284($s2)
/*  f0caef0:	24090001 */ 	addiu	$t1,$zero,0x1
/*  f0caef4:	ad490108 */ 	sw	$t1,0x108($t2)
/*  f0caef8:	8e4b0284 */ 	lw	$t3,0x284($s2)
/*  f0caefc:	ad60011c */ 	sw	$zero,0x11c($t3)
/*  f0caf00:	10000050 */ 	b	.L0f0cb044
/*  f0caf04:	8e450284 */ 	lw	$a1,0x284($s2)
.L0f0caf08:
/*  f0caf08:	51800005 */ 	beqzl	$t4,.L0f0caf20
/*  f0caf0c:	8cad0114 */ 	lw	$t5,0x114($a1)
/*  f0caf10:	aca0011c */ 	sw	$zero,0x11c($a1)
/*  f0caf14:	10000049 */ 	b	.L0f0cb03c
/*  f0caf18:	8e450284 */ 	lw	$a1,0x284($s2)
/*  f0caf1c:	8cad0114 */ 	lw	$t5,0x114($a1)
.L0f0caf20:
/*  f0caf20:	8fae01c4 */ 	lw	$t6,0x1c4($sp)
/*  f0caf24:	51a00026 */ 	beqzl	$t5,.L0f0cafc0
/*  f0caf28:	8caa0118 */ 	lw	$t2,0x118($a1)
/*  f0caf2c:	11c00009 */ 	beqz	$t6,.L0f0caf54
/*  f0caf30:	8faf025c */ 	lw	$t7,0x25c($sp)
/*  f0caf34:	29e1003d */ 	slti	$at,$t7,0x3d
/*  f0caf38:	10200004 */ 	beqz	$at,.L0f0caf4c
/*  f0caf3c:	24180001 */ 	addiu	$t8,$zero,0x1
/*  f0caf40:	29e1ffc4 */ 	slti	$at,$t7,-60
/*  f0caf44:	50200004 */ 	beqzl	$at,.L0f0caf58
/*  f0caf48:	8cb9011c */ 	lw	$t9,0x11c($a1)
.L0f0caf4c:
/*  f0caf4c:	acb8011c */ 	sw	$t8,0x11c($a1)
/*  f0caf50:	8e450284 */ 	lw	$a1,0x284($s2)
.L0f0caf54:
/*  f0caf54:	8cb9011c */ 	lw	$t9,0x11c($a1)
.L0f0caf58:
/*  f0caf58:	3c0140a0 */ 	lui	$at,0x40a0
/*  f0caf5c:	53200038 */ 	beqzl	$t9,.L0f0cb040
/*  f0caf60:	aca00108 */ 	sw	$zero,0x108($a1)
/*  f0caf64:	44814000 */ 	mtc1	$at,$f8
/*  f0caf68:	c4a00154 */ 	lwc1	$f0,0x154($a1)
/*  f0caf6c:	3c01c120 */ 	lui	$at,0xc120
/*  f0caf70:	46087400 */ 	add.s	$f16,$f14,$f8
/*  f0caf74:	4600803c */ 	c.lt.s	$f16,$f0
/*  f0caf78:	00000000 */ 	nop
/*  f0caf7c:	45030009 */ 	bc1tl	.L0f0cafa4
/*  f0caf80:	8ca8010c */ 	lw	$t0,0x10c($a1)
/*  f0caf84:	44819000 */ 	mtc1	$at,$f18
/*  f0caf88:	00000000 */ 	nop
/*  f0caf8c:	46127100 */ 	add.s	$f4,$f14,$f18
/*  f0caf90:	4604003c */ 	c.lt.s	$f0,$f4
/*  f0caf94:	00000000 */ 	nop
/*  f0caf98:	45020029 */ 	bc1fl	.L0f0cb040
/*  f0caf9c:	aca00108 */ 	sw	$zero,0x108($a1)
/*  f0cafa0:	8ca8010c */ 	lw	$t0,0x10c($a1)
.L0f0cafa4:
/*  f0cafa4:	24090001 */ 	addiu	$t1,$zero,0x1
/*  f0cafa8:	55000025 */ 	bnezl	$t0,.L0f0cb040
/*  f0cafac:	aca00108 */ 	sw	$zero,0x108($a1)
/*  f0cafb0:	aca90100 */ 	sw	$t1,0x100($a1)
/*  f0cafb4:	10000021 */ 	b	.L0f0cb03c
/*  f0cafb8:	8e450284 */ 	lw	$a1,0x284($s2)
/*  f0cafbc:	8caa0118 */ 	lw	$t2,0x118($a1)
.L0f0cafc0:
/*  f0cafc0:	8fab01c4 */ 	lw	$t3,0x1c4($sp)
/*  f0cafc4:	5140001e */ 	beqzl	$t2,.L0f0cb040
/*  f0cafc8:	aca00108 */ 	sw	$zero,0x108($a1)
/*  f0cafcc:	1160001b */ 	beqz	$t3,.L0f0cb03c
/*  f0cafd0:	8fac025c */ 	lw	$t4,0x25c($sp)
/*  f0cafd4:	2981003d */ 	slti	$at,$t4,0x3d
/*  f0cafd8:	10200002 */ 	beqz	$at,.L0f0cafe4
/*  f0cafdc:	2981ffc4 */ 	slti	$at,$t4,-60
/*  f0cafe0:	10200016 */ 	beqz	$at,.L0f0cb03c
.L0f0cafe4:
/*  f0cafe4:	3c0140a0 */ 	lui	$at,0x40a0
/*  f0cafe8:	44815000 */ 	mtc1	$at,$f10
/*  f0cafec:	c4a00154 */ 	lwc1	$f0,0x154($a1)
/*  f0caff0:	3c01c120 */ 	lui	$at,0xc120
/*  f0caff4:	460a7180 */ 	add.s	$f6,$f14,$f10
/*  f0caff8:	4600303c */ 	c.lt.s	$f6,$f0
/*  f0caffc:	00000000 */ 	nop
/*  f0cb000:	45030009 */ 	bc1tl	.L0f0cb028
/*  f0cb004:	8cad010c */ 	lw	$t5,0x10c($a1)
/*  f0cb008:	44814000 */ 	mtc1	$at,$f8
/*  f0cb00c:	00000000 */ 	nop
/*  f0cb010:	46087400 */ 	add.s	$f16,$f14,$f8
/*  f0cb014:	4610003c */ 	c.lt.s	$f0,$f16
/*  f0cb018:	00000000 */ 	nop
/*  f0cb01c:	45020008 */ 	bc1fl	.L0f0cb040
/*  f0cb020:	aca00108 */ 	sw	$zero,0x108($a1)
/*  f0cb024:	8cad010c */ 	lw	$t5,0x10c($a1)
.L0f0cb028:
/*  f0cb028:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f0cb02c:	55a00004 */ 	bnezl	$t5,.L0f0cb040
/*  f0cb030:	aca00108 */ 	sw	$zero,0x108($a1)
/*  f0cb034:	acae0100 */ 	sw	$t6,0x100($a1)
/*  f0cb038:	8e450284 */ 	lw	$a1,0x284($s2)
.L0f0cb03c:
/*  f0cb03c:	aca00108 */ 	sw	$zero,0x108($a1)
.L0f0cb040:
/*  f0cb040:	8e450284 */ 	lw	$a1,0x284($s2)
.L0f0cb044:
/*  f0cb044:	8caf01b0 */ 	lw	$t7,0x1b0($a1)
/*  f0cb048:	24010003 */ 	addiu	$at,$zero,0x3
/*  f0cb04c:	55e10004 */ 	bnel	$t7,$at,.L0f0cb060
/*  f0cb050:	8cb80100 */ 	lw	$t8,0x100($a1)
/*  f0cb054:	aca00100 */ 	sw	$zero,0x100($a1)
/*  f0cb058:	8e450284 */ 	lw	$a1,0x284($s2)
/*  f0cb05c:	8cb80100 */ 	lw	$t8,0x100($a1)
.L0f0cb060:
/*  f0cb060:	8fa901d0 */ 	lw	$t1,0x1d0($sp)
/*  f0cb064:	1300004a */ 	beqz	$t8,.L0f0cb190
/*  f0cb068:	00000000 */ 	nop
/*  f0cb06c:	508000af */ 	beqzl	$a0,.L0f0cb32c
/*  f0cb070:	8faa01cc */ 	lw	$t2,0x1cc($sp)
/*  f0cb074:	c4a2015c */ 	lwc1	$f2,0x15c($a1)
/*  f0cb078:	3c013f00 */ 	lui	$at,0x3f00
/*  f0cb07c:	44812000 */ 	mtc1	$at,$f4
/*  f0cb080:	46021482 */ 	mul.s	$f18,$f2,$f2
/*  f0cb084:	3c017f1b */ 	lui	$at,%hi(var7f1ad8c0)
/*  f0cb088:	c426d8c0 */ 	lwc1	$f6,%lo(var7f1ad8c0)($at)
/*  f0cb08c:	c4a00154 */ 	lwc1	$f0,0x154($a1)
/*  f0cb090:	3c013f80 */ 	lui	$at,0x3f80
/*  f0cb094:	46049282 */ 	mul.s	$f10,$f18,$f4
/*  f0cb098:	46065303 */ 	div.s	$f12,$f10,$f6
/*  f0cb09c:	460c7200 */ 	add.s	$f8,$f14,$f12
/*  f0cb0a0:	4600403c */ 	c.lt.s	$f8,$f0
/*  f0cb0a4:	00000000 */ 	nop
/*  f0cb0a8:	45020007 */ 	bc1fl	.L0f0cb0c8
/*  f0cb0ac:	460c7401 */ 	sub.s	$f16,$f14,$f12
/*  f0cb0b0:	44816000 */ 	mtc1	$at,$f12
/*  f0cb0b4:	0fc3203e */ 	jal	bmoveUpdateSpeedVerta
/*  f0cb0b8:	e7ae0094 */ 	swc1	$f14,0x94($sp)
/*  f0cb0bc:	10000010 */ 	b	.L0f0cb100
/*  f0cb0c0:	c7ae0094 */ 	lwc1	$f14,0x94($sp)
/*  f0cb0c4:	460c7401 */ 	sub.s	$f16,$f14,$f12
.L0f0cb0c8:
/*  f0cb0c8:	3c01bf80 */ 	lui	$at,0xbf80
/*  f0cb0cc:	4610003c */ 	c.lt.s	$f0,$f16
/*  f0cb0d0:	00000000 */ 	nop
/*  f0cb0d4:	45020007 */ 	bc1fl	.L0f0cb0f4
/*  f0cb0d8:	44806000 */ 	mtc1	$zero,$f12
/*  f0cb0dc:	44816000 */ 	mtc1	$at,$f12
/*  f0cb0e0:	0fc3203e */ 	jal	bmoveUpdateSpeedVerta
/*  f0cb0e4:	e7ae0094 */ 	swc1	$f14,0x94($sp)
/*  f0cb0e8:	10000005 */ 	b	.L0f0cb100
/*  f0cb0ec:	c7ae0094 */ 	lwc1	$f14,0x94($sp)
/*  f0cb0f0:	44806000 */ 	mtc1	$zero,$f12
.L0f0cb0f4:
/*  f0cb0f4:	0fc3203e */ 	jal	bmoveUpdateSpeedVerta
/*  f0cb0f8:	e7ae0094 */ 	swc1	$f14,0x94($sp)
/*  f0cb0fc:	c7ae0094 */ 	lwc1	$f14,0x94($sp)
.L0f0cb100:
/*  f0cb100:	8e450284 */ 	lw	$a1,0x284($s2)
/*  f0cb104:	c644004c */ 	lwc1	$f4,0x4c($s2)
/*  f0cb108:	c4b2015c */ 	lwc1	$f18,0x15c($a1)
/*  f0cb10c:	c4a00154 */ 	lwc1	$f0,0x154($a1)
/*  f0cb110:	46049082 */ 	mul.s	$f2,$f18,$f4
/*  f0cb114:	4600703c */ 	c.lt.s	$f14,$f0
/*  f0cb118:	46021280 */ 	add.s	$f10,$f2,$f2
/*  f0cb11c:	45000007 */ 	bc1f	.L0f0cb13c
/*  f0cb120:	460a0300 */ 	add.s	$f12,$f0,$f10
/*  f0cb124:	460c703c */ 	c.lt.s	$f14,$f12
/*  f0cb128:	00000000 */ 	nop
/*  f0cb12c:	45020004 */ 	bc1fl	.L0f0cb140
/*  f0cb130:	460e003c */ 	c.lt.s	$f0,$f14
/*  f0cb134:	1000007c */ 	b	.L0f0cb328
/*  f0cb138:	e4ac0154 */ 	swc1	$f12,0x154($a1)
.L0f0cb13c:
/*  f0cb13c:	460e003c */ 	c.lt.s	$f0,$f14
.L0f0cb140:
/*  f0cb140:	00000000 */ 	nop
/*  f0cb144:	45020008 */ 	bc1fl	.L0f0cb168
/*  f0cb148:	e4ae0154 */ 	swc1	$f14,0x154($a1)
/*  f0cb14c:	460e603c */ 	c.lt.s	$f12,$f14
/*  f0cb150:	00000000 */ 	nop
/*  f0cb154:	45020004 */ 	bc1fl	.L0f0cb168
/*  f0cb158:	e4ae0154 */ 	swc1	$f14,0x154($a1)
/*  f0cb15c:	10000072 */ 	b	.L0f0cb328
/*  f0cb160:	e4ac0154 */ 	swc1	$f12,0x154($a1)
/*  f0cb164:	e4ae0154 */ 	swc1	$f14,0x154($a1)
.L0f0cb168:
/*  f0cb168:	8e590284 */ 	lw	$t9,0x284($s2)
/*  f0cb16c:	44803000 */ 	mtc1	$zero,$f6
/*  f0cb170:	00000000 */ 	nop
/*  f0cb174:	e726015c */ 	swc1	$f6,0x15c($t9)
/*  f0cb178:	8e450284 */ 	lw	$a1,0x284($s2)
/*  f0cb17c:	8ca80108 */ 	lw	$t0,0x108($a1)
/*  f0cb180:	5500006a */ 	bnezl	$t0,.L0f0cb32c
/*  f0cb184:	8faa01cc */ 	lw	$t2,0x1cc($sp)
/*  f0cb188:	10000067 */ 	b	.L0f0cb328
/*  f0cb18c:	aca00100 */ 	sw	$zero,0x100($a1)
.L0f0cb190:
/*  f0cb190:	1120002f */ 	beqz	$t1,.L0f0cb250
/*  f0cb194:	c7a601ec */ 	lwc1	$f6,0x1ec($sp)
/*  f0cb198:	0c002f9d */ 	jal	viGetFovY
/*  f0cb19c:	00000000 */ 	nop
/*  f0cb1a0:	8faa0254 */ 	lw	$t2,0x254($sp)
/*  f0cb1a4:	3c014270 */ 	lui	$at,0x4270
/*  f0cb1a8:	44814000 */ 	mtc1	$at,$f8
/*  f0cb1ac:	448a8000 */ 	mtc1	$t2,$f16
/*  f0cb1b0:	3c01428c */ 	lui	$at,0x428c
/*  f0cb1b4:	44812000 */ 	mtc1	$at,$f4
/*  f0cb1b8:	468084a0 */ 	cvt.s.w	$f18,$f16
/*  f0cb1bc:	3c013f80 */ 	lui	$at,0x3f80
/*  f0cb1c0:	44815000 */ 	mtc1	$at,$f10
/*  f0cb1c4:	3c01bf80 */ 	lui	$at,0xbf80
/*  f0cb1c8:	46080383 */ 	div.s	$f14,$f0,$f8
/*  f0cb1cc:	44804000 */ 	mtc1	$zero,$f8
/*  f0cb1d0:	46049303 */ 	div.s	$f12,$f18,$f4
/*  f0cb1d4:	460c503c */ 	c.lt.s	$f10,$f12
/*  f0cb1d8:	46006086 */ 	mov.s	$f2,$f12
/*  f0cb1dc:	45020006 */ 	bc1fl	.L0f0cb1f8
/*  f0cb1e0:	44813000 */ 	mtc1	$at,$f6
/*  f0cb1e4:	3c013f80 */ 	lui	$at,0x3f80
/*  f0cb1e8:	44811000 */ 	mtc1	$at,$f2
/*  f0cb1ec:	1000000a */ 	b	.L0f0cb218
/*  f0cb1f0:	4602403e */ 	c.le.s	$f8,$f2
/*  f0cb1f4:	44813000 */ 	mtc1	$at,$f6
.L0f0cb1f8:
/*  f0cb1f8:	3c01bf80 */ 	lui	$at,0xbf80
/*  f0cb1fc:	4606603c */ 	c.lt.s	$f12,$f6
/*  f0cb200:	00000000 */ 	nop
/*  f0cb204:	45020004 */ 	bc1fl	.L0f0cb218
/*  f0cb208:	4602403e */ 	c.le.s	$f8,$f2
/*  f0cb20c:	44811000 */ 	mtc1	$at,$f2
/*  f0cb210:	00000000 */ 	nop
/*  f0cb214:	4602403e */ 	c.le.s	$f8,$f2
.L0f0cb218:
/*  f0cb218:	00000000 */ 	nop
/*  f0cb21c:	45020005 */ 	bc1fl	.L0f0cb234
/*  f0cb220:	46001407 */ 	neg.s	$f16,$f2
/*  f0cb224:	46021082 */ 	mul.s	$f2,$f2,$f2
/*  f0cb228:	10000005 */ 	b	.L0f0cb240
/*  f0cb22c:	46001487 */ 	neg.s	$f18,$f2
/*  f0cb230:	46001407 */ 	neg.s	$f16,$f2
.L0f0cb234:
/*  f0cb234:	46101082 */ 	mul.s	$f2,$f2,$f16
/*  f0cb238:	00000000 */ 	nop
/*  f0cb23c:	46001487 */ 	neg.s	$f18,$f2
.L0f0cb240:
/*  f0cb240:	8e4b0284 */ 	lw	$t3,0x284($s2)
/*  f0cb244:	460e9102 */ 	mul.s	$f4,$f18,$f14
/*  f0cb248:	1000002c */ 	b	.L0f0cb2fc
/*  f0cb24c:	e564015c */ 	swc1	$f4,0x15c($t3)
.L0f0cb250:
/*  f0cb250:	44805000 */ 	mtc1	$zero,$f10
/*  f0cb254:	c7b001f0 */ 	lwc1	$f16,0x1f0($sp)
/*  f0cb258:	4606503c */ 	c.lt.s	$f10,$f6
/*  f0cb25c:	00000000 */ 	nop
/*  f0cb260:	45020010 */ 	bc1fl	.L0f0cb2a4
/*  f0cb264:	44804000 */ 	mtc1	$zero,$f8
/*  f0cb268:	0fc3203e */ 	jal	bmoveUpdateSpeedVerta
/*  f0cb26c:	46003306 */ 	mov.s	$f12,$f6
/*  f0cb270:	8fac01c4 */ 	lw	$t4,0x1c4($sp)
/*  f0cb274:	8fad025c */ 	lw	$t5,0x25c($sp)
/*  f0cb278:	11800020 */ 	beqz	$t4,.L0f0cb2fc
/*  f0cb27c:	29a1003d */ 	slti	$at,$t5,0x3d
/*  f0cb280:	10200003 */ 	beqz	$at,.L0f0cb290
/*  f0cb284:	29a1ffc4 */ 	slti	$at,$t5,-60
/*  f0cb288:	5020001d */ 	beqzl	$at,.L0f0cb300
/*  f0cb28c:	8e450284 */ 	lw	$a1,0x284($s2)
.L0f0cb290:
/*  f0cb290:	8e4f0284 */ 	lw	$t7,0x284($s2)
/*  f0cb294:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f0cb298:	10000018 */ 	b	.L0f0cb2fc
/*  f0cb29c:	adee010c */ 	sw	$t6,0x10c($t7)
/*  f0cb2a0:	44804000 */ 	mtc1	$zero,$f8
.L0f0cb2a4:
/*  f0cb2a4:	00000000 */ 	nop
/*  f0cb2a8:	4610403c */ 	c.lt.s	$f8,$f16
/*  f0cb2ac:	00000000 */ 	nop
/*  f0cb2b0:	45020010 */ 	bc1fl	.L0f0cb2f4
/*  f0cb2b4:	44806000 */ 	mtc1	$zero,$f12
/*  f0cb2b8:	0fc3203e */ 	jal	bmoveUpdateSpeedVerta
/*  f0cb2bc:	46008307 */ 	neg.s	$f12,$f16
/*  f0cb2c0:	8fb801c4 */ 	lw	$t8,0x1c4($sp)
/*  f0cb2c4:	8fb9025c */ 	lw	$t9,0x25c($sp)
/*  f0cb2c8:	1300000c */ 	beqz	$t8,.L0f0cb2fc
/*  f0cb2cc:	2b21003d */ 	slti	$at,$t9,0x3d
/*  f0cb2d0:	10200003 */ 	beqz	$at,.L0f0cb2e0
/*  f0cb2d4:	2b21ffc4 */ 	slti	$at,$t9,-60
/*  f0cb2d8:	50200009 */ 	beqzl	$at,.L0f0cb300
/*  f0cb2dc:	8e450284 */ 	lw	$a1,0x284($s2)
.L0f0cb2e0:
/*  f0cb2e0:	8e490284 */ 	lw	$t1,0x284($s2)
/*  f0cb2e4:	24080001 */ 	addiu	$t0,$zero,0x1
/*  f0cb2e8:	10000004 */ 	b	.L0f0cb2fc
/*  f0cb2ec:	ad28010c */ 	sw	$t0,0x10c($t1)
/*  f0cb2f0:	44806000 */ 	mtc1	$zero,$f12
.L0f0cb2f4:
/*  f0cb2f4:	0fc3203e */ 	jal	bmoveUpdateSpeedVerta
/*  f0cb2f8:	00000000 */ 	nop
.L0f0cb2fc:
/*  f0cb2fc:	8e450284 */ 	lw	$a1,0x284($s2)
.L0f0cb300:
/*  f0cb300:	c644004c */ 	lwc1	$f4,0x4c($s2)
/*  f0cb304:	3c014060 */ 	lui	$at,0x4060
/*  f0cb308:	c4b2015c */ 	lwc1	$f18,0x15c($a1)
/*  f0cb30c:	44813000 */ 	mtc1	$at,$f6
/*  f0cb310:	c4b00154 */ 	lwc1	$f16,0x154($a1)
/*  f0cb314:	46049282 */ 	mul.s	$f10,$f18,$f4
/*  f0cb318:	00000000 */ 	nop
/*  f0cb31c:	46065202 */ 	mul.s	$f8,$f10,$f6
/*  f0cb320:	46088480 */ 	add.s	$f18,$f16,$f8
/*  f0cb324:	e4b20154 */ 	swc1	$f18,0x154($a1)
.L0f0cb328:
/*  f0cb328:	8faa01cc */ 	lw	$t2,0x1cc($sp)
.L0f0cb32c:
/*  f0cb32c:	c7ac01f4 */ 	lwc1	$f12,0x1f4($sp)
/*  f0cb330:	5140002d */ 	beqzl	$t2,.L0f0cb3e8
/*  f0cb334:	44804000 */ 	mtc1	$zero,$f8
/*  f0cb338:	0c002f9d */ 	jal	viGetFovY
/*  f0cb33c:	00000000 */ 	nop
/*  f0cb340:	8fab0250 */ 	lw	$t3,0x250($sp)
/*  f0cb344:	3c01428c */ 	lui	$at,0x428c
/*  f0cb348:	44813000 */ 	mtc1	$at,$f6
/*  f0cb34c:	448b2000 */ 	mtc1	$t3,$f4
/*  f0cb350:	3c013f80 */ 	lui	$at,0x3f80
/*  f0cb354:	44818000 */ 	mtc1	$at,$f16
/*  f0cb358:	468022a0 */ 	cvt.s.w	$f10,$f4
/*  f0cb35c:	44809000 */ 	mtc1	$zero,$f18
/*  f0cb360:	3c01bf80 */ 	lui	$at,0xbf80
/*  f0cb364:	46065303 */ 	div.s	$f12,$f10,$f6
/*  f0cb368:	460c803c */ 	c.lt.s	$f16,$f12
/*  f0cb36c:	46006086 */ 	mov.s	$f2,$f12
/*  f0cb370:	45020006 */ 	bc1fl	.L0f0cb38c
/*  f0cb374:	44814000 */ 	mtc1	$at,$f8
/*  f0cb378:	3c013f80 */ 	lui	$at,0x3f80
/*  f0cb37c:	44811000 */ 	mtc1	$at,$f2
/*  f0cb380:	1000000a */ 	b	.L0f0cb3ac
/*  f0cb384:	4602903e */ 	c.le.s	$f18,$f2
/*  f0cb388:	44814000 */ 	mtc1	$at,$f8
.L0f0cb38c:
/*  f0cb38c:	3c01bf80 */ 	lui	$at,0xbf80
/*  f0cb390:	4608603c */ 	c.lt.s	$f12,$f8
/*  f0cb394:	00000000 */ 	nop
/*  f0cb398:	45020004 */ 	bc1fl	.L0f0cb3ac
/*  f0cb39c:	4602903e */ 	c.le.s	$f18,$f2
/*  f0cb3a0:	44811000 */ 	mtc1	$at,$f2
/*  f0cb3a4:	00000000 */ 	nop
/*  f0cb3a8:	4602903e */ 	c.le.s	$f18,$f2
.L0f0cb3ac:
/*  f0cb3ac:	3c014270 */ 	lui	$at,0x4270
/*  f0cb3b0:	44815000 */ 	mtc1	$at,$f10
/*  f0cb3b4:	45000004 */ 	bc1f	.L0f0cb3c8
/*  f0cb3b8:	460a0183 */ 	div.s	$f6,$f0,$f10
/*  f0cb3bc:	46021082 */ 	mul.s	$f2,$f2,$f2
/*  f0cb3c0:	10000004 */ 	b	.L0f0cb3d4
/*  f0cb3c4:	00000000 */ 	nop
.L0f0cb3c8:
/*  f0cb3c8:	46001107 */ 	neg.s	$f4,$f2
/*  f0cb3cc:	46041082 */ 	mul.s	$f2,$f2,$f4
/*  f0cb3d0:	00000000 */ 	nop
.L0f0cb3d4:
/*  f0cb3d4:	46061402 */ 	mul.s	$f16,$f2,$f6
/*  f0cb3d8:	8e4c0284 */ 	lw	$t4,0x284($s2)
/*  f0cb3dc:	10000019 */ 	b	.L0f0cb444
/*  f0cb3e0:	e5901b9c */ 	swc1	$f16,0x1b9c($t4)
/*  f0cb3e4:	44804000 */ 	mtc1	$zero,$f8
.L0f0cb3e8:
/*  f0cb3e8:	c7a001f8 */ 	lwc1	$f0,0x1f8($sp)
/*  f0cb3ec:	460c403c */ 	c.lt.s	$f8,$f12
/*  f0cb3f0:	00000000 */ 	nop
/*  f0cb3f4:	45020006 */ 	bc1fl	.L0f0cb410
/*  f0cb3f8:	44809000 */ 	mtc1	$zero,$f18
/*  f0cb3fc:	0fc320e5 */ 	jal	bmoveUpdateSpeedThetaControl
/*  f0cb400:	e7ac01f4 */ 	swc1	$f12,0x1f4($sp)
/*  f0cb404:	10000010 */ 	b	.L0f0cb448
/*  f0cb408:	8e450284 */ 	lw	$a1,0x284($s2)
/*  f0cb40c:	44809000 */ 	mtc1	$zero,$f18
.L0f0cb410:
/*  f0cb410:	00000000 */ 	nop
/*  f0cb414:	4600903c */ 	c.lt.s	$f18,$f0
/*  f0cb418:	00000000 */ 	nop
/*  f0cb41c:	45020007 */ 	bc1fl	.L0f0cb43c
/*  f0cb420:	44806000 */ 	mtc1	$zero,$f12
/*  f0cb424:	46000307 */ 	neg.s	$f12,$f0
/*  f0cb428:	0fc320e5 */ 	jal	bmoveUpdateSpeedThetaControl
/*  f0cb42c:	e7a001f8 */ 	swc1	$f0,0x1f8($sp)
/*  f0cb430:	10000005 */ 	b	.L0f0cb448
/*  f0cb434:	8e450284 */ 	lw	$a1,0x284($s2)
/*  f0cb438:	44806000 */ 	mtc1	$zero,$f12
.L0f0cb43c:
/*  f0cb43c:	0fc320e5 */ 	jal	bmoveUpdateSpeedThetaControl
/*  f0cb440:	00000000 */ 	nop
.L0f0cb444:
/*  f0cb444:	8e450284 */ 	lw	$a1,0x284($s2)
.L0f0cb448:
/*  f0cb448:	c4a41b9c */ 	lwc1	$f4,0x1b9c($a1)
/*  f0cb44c:	0fc32001 */ 	jal	bmoveUpdateSpeedTheta
/*  f0cb450:	e4a40148 */ 	swc1	$f4,0x148($a1)
/*  f0cb454:	8fad0228 */ 	lw	$t5,0x228($sp)
/*  f0cb458:	51a00008 */ 	beqzl	$t5,.L0f0cb47c
/*  f0cb45c:	8e5802ac */ 	lw	$t8,0x2ac($s2)
/*  f0cb460:	8e4e0284 */ 	lw	$t6,0x284($s2)
/*  f0cb464:	adc00658 */ 	sw	$zero,0x658($t6)
/*  f0cb468:	8e4f0284 */ 	lw	$t7,0x284($s2)
/*  f0cb46c:	ade0065c */ 	sw	$zero,0x65c($t7)
/*  f0cb470:	0fc22a7d */ 	jal	playerActivateRemoteMineDetonator
/*  f0cb474:	8e44028c */ 	lw	$a0,0x28c($s2)
/*  f0cb478:	8e5802ac */ 	lw	$t8,0x2ac($s2)
.L0f0cb47c:
/*  f0cb47c:	24010006 */ 	addiu	$at,$zero,0x6
/*  f0cb480:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f0cb484:	57010003 */ 	bnel	$t8,$at,.L0f0cb494
/*  f0cb488:	8e59000c */ 	lw	$t9,0xc($s2)
/*  f0cb48c:	00001025 */ 	or	$v0,$zero,$zero
/*  f0cb490:	8e59000c */ 	lw	$t9,0xc($s2)
.L0f0cb494:
/*  f0cb494:	2b21000a */ 	slti	$at,$t9,0xa
/*  f0cb498:	10200002 */ 	beqz	$at,.L0f0cb4a4
/*  f0cb49c:	00000000 */ 	nop
/*  f0cb4a0:	00001025 */ 	or	$v0,$zero,$zero
.L0f0cb4a4:
/*  f0cb4a4:	5040001a */ 	beqzl	$v0,.L0f0cb510
/*  f0cb4a8:	8e450284 */ 	lw	$a1,0x284($s2)
/*  f0cb4ac:	8fa201fc */ 	lw	$v0,0x1fc($sp)
/*  f0cb4b0:	0002202a */ 	slt	$a0,$zero,$v0
/*  f0cb4b4:	2442ffff */ 	addiu	$v0,$v0,-1
/*  f0cb4b8:	10800008 */ 	beqz	$a0,.L0f0cb4dc
/*  f0cb4bc:	afa201fc */ 	sw	$v0,0x1fc($sp)
.L0f0cb4c0:
/*  f0cb4c0:	0fc2870b */ 	jal	bgun0f0a1c2c
/*  f0cb4c4:	00000000 */ 	nop
/*  f0cb4c8:	8fa201fc */ 	lw	$v0,0x1fc($sp)
/*  f0cb4cc:	0002202a */ 	slt	$a0,$zero,$v0
/*  f0cb4d0:	2442ffff */ 	addiu	$v0,$v0,-1
/*  f0cb4d4:	1480fffa */ 	bnez	$a0,.L0f0cb4c0
/*  f0cb4d8:	afa201fc */ 	sw	$v0,0x1fc($sp)
.L0f0cb4dc:
/*  f0cb4dc:	8fa20200 */ 	lw	$v0,0x200($sp)
/*  f0cb4e0:	0002202a */ 	slt	$a0,$zero,$v0
/*  f0cb4e4:	2442ffff */ 	addiu	$v0,$v0,-1
/*  f0cb4e8:	10800008 */ 	beqz	$a0,.L0f0cb50c
/*  f0cb4ec:	afa20200 */ 	sw	$v0,0x200($sp)
.L0f0cb4f0:
/*  f0cb4f0:	0fc286d4 */ 	jal	bgun0f0a1b50
/*  f0cb4f4:	00000000 */ 	nop
/*  f0cb4f8:	8fa20200 */ 	lw	$v0,0x200($sp)
/*  f0cb4fc:	0002202a */ 	slt	$a0,$zero,$v0
/*  f0cb500:	2442ffff */ 	addiu	$v0,$v0,-1
/*  f0cb504:	1480fffa */ 	bnez	$a0,.L0f0cb4f0
/*  f0cb508:	afa20200 */ 	sw	$v0,0x200($sp)
.L0f0cb50c:
/*  f0cb50c:	8e450284 */ 	lw	$a1,0x284($s2)
.L0f0cb510:
/*  f0cb510:	8fa901b4 */ 	lw	$t1,0x1b4($sp)
/*  f0cb514:	8ca81c64 */ 	lw	$t0,0x1c64($a1)
/*  f0cb518:	11000003 */ 	beqz	$t0,.L0f0cb528
/*  f0cb51c:	00000000 */ 	nop
/*  f0cb520:	10000093 */ 	b	.L0f0cb770
/*  f0cb524:	aca01c64 */ 	sw	$zero,0x1c64($a1)
.L0f0cb528:
/*  f0cb528:	1120007d */ 	beqz	$t1,.L0f0cb720
/*  f0cb52c:	8fb901b8 */ 	lw	$t9,0x1b8($sp)
/*  f0cb530:	0fc2a4f4 */ 	jal	bgunSetAimType
/*  f0cb534:	00002025 */ 	or	$a0,$zero,$zero
/*  f0cb538:	8faa022c */ 	lw	$t2,0x22c($sp)
/*  f0cb53c:	11400015 */ 	beqz	$t2,.L0f0cb594
/*  f0cb540:	00000000 */ 	nop
/*  f0cb544:	0fc31ef4 */ 	jal	bmoveIsAutoAimXEnabledForCurrentWeapon
/*  f0cb548:	00000000 */ 	nop
/*  f0cb54c:	54400006 */ 	bnezl	$v0,.L0f0cb568
/*  f0cb550:	8e450284 */ 	lw	$a1,0x284($s2)
/*  f0cb554:	0fc31ea3 */ 	jal	bmoveIsAutoAimYEnabledForCurrentWeapon
/*  f0cb558:	00000000 */ 	nop
/*  f0cb55c:	1040000d */ 	beqz	$v0,.L0f0cb594
/*  f0cb560:	00000000 */ 	nop
/*  f0cb564:	8e450284 */ 	lw	$a1,0x284($s2)
.L0f0cb568:
/*  f0cb568:	8cab013c */ 	lw	$t3,0x13c($a1)
/*  f0cb56c:	11600009 */ 	beqz	$t3,.L0f0cb594
/*  f0cb570:	00000000 */ 	nop
/*  f0cb574:	8cac012c */ 	lw	$t4,0x12c($a1)
/*  f0cb578:	8fa401ac */ 	lw	$a0,0x1ac($sp)
/*  f0cb57c:	11800005 */ 	beqz	$t4,.L0f0cb594
/*  f0cb580:	00000000 */ 	nop
/*  f0cb584:	0fc2c601 */ 	jal	weaponHasClassFlag
/*  f0cb588:	24050002 */ 	addiu	$a1,$zero,0x2
/*  f0cb58c:	5440000b */ 	bnezl	$v0,.L0f0cb5bc
/*  f0cb590:	00008025 */ 	or	$s0,$zero,$zero
.L0f0cb594:
/*  f0cb594:	0fc2866a */ 	jal	bgunGetWeaponNum
/*  f0cb598:	00002025 */ 	or	$a0,$zero,$zero
/*  f0cb59c:	2401000a */ 	addiu	$at,$zero,0xa
/*  f0cb5a0:	54410037 */ 	bnel	$v0,$at,.L0f0cb680
/*  f0cb5a4:	8e450284 */ 	lw	$a1,0x284($s2)
/*  f0cb5a8:	8e4d0284 */ 	lw	$t5,0x284($s2)
/*  f0cb5ac:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0cb5b0:	91ae063b */ 	lbu	$t6,0x63b($t5)
/*  f0cb5b4:	15c10031 */ 	bne	$t6,$at,.L0f0cb67c
/*  f0cb5b8:	00008025 */ 	or	$s0,$zero,$zero
.L0f0cb5bc:
/*  f0cb5bc:	0fc2866a */ 	jal	bgunGetWeaponNum
/*  f0cb5c0:	00002025 */ 	or	$a0,$zero,$zero
/*  f0cb5c4:	2401000a */ 	addiu	$at,$zero,0xa
/*  f0cb5c8:	54410008 */ 	bnel	$v0,$at,.L0f0cb5ec
/*  f0cb5cc:	8e450284 */ 	lw	$a1,0x284($s2)
/*  f0cb5d0:	8e4f0284 */ 	lw	$t7,0x284($s2)
/*  f0cb5d4:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0cb5d8:	91f8063b */ 	lbu	$t8,0x63b($t7)
/*  f0cb5dc:	57010003 */ 	bnel	$t8,$at,.L0f0cb5ec
/*  f0cb5e0:	8e450284 */ 	lw	$a1,0x284($s2)
/*  f0cb5e4:	24100001 */ 	addiu	$s0,$zero,0x1
/*  f0cb5e8:	8e450284 */ 	lw	$a1,0x284($s2)
.L0f0cb5ec:
/*  f0cb5ec:	3c017f1b */ 	lui	$at,%hi(var7f1ad8c4)
/*  f0cb5f0:	c422d8c4 */ 	lwc1	$f2,%lo(var7f1ad8c4)($at)
/*  f0cb5f4:	c4a01b68 */ 	lwc1	$f0,0x1b68($a1)
/*  f0cb5f8:	3c017f1b */ 	lui	$at,%hi(var7f1ad8c8)
/*  f0cb5fc:	4600103c */ 	c.lt.s	$f2,$f0
/*  f0cb600:	00000000 */ 	nop
/*  f0cb604:	45020009 */ 	bc1fl	.L0f0cb62c
/*  f0cb608:	4602003c */ 	c.lt.s	$f0,$f2
/*  f0cb60c:	c42ad8c8 */ 	lwc1	$f10,%lo(var7f1ad8c8)($at)
/*  f0cb610:	c646004c */ 	lwc1	$f6,0x4c($s2)
/*  f0cb614:	46065402 */ 	mul.s	$f16,$f10,$f6
/*  f0cb618:	46100201 */ 	sub.s	$f8,$f0,$f16
/*  f0cb61c:	e4a81b68 */ 	swc1	$f8,0x1b68($a1)
/*  f0cb620:	8e450284 */ 	lw	$a1,0x284($s2)
/*  f0cb624:	c4a01b68 */ 	lwc1	$f0,0x1b68($a1)
/*  f0cb628:	4602003c */ 	c.lt.s	$f0,$f2
.L0f0cb62c:
/*  f0cb62c:	3c017f1b */ 	lui	$at,%hi(var7f1ad8cc)
/*  f0cb630:	45020005 */ 	bc1fl	.L0f0cb648
/*  f0cb634:	c4ac0138 */ 	lwc1	$f12,0x138($a1)
/*  f0cb638:	e4a21b68 */ 	swc1	$f2,0x1b68($a1)
/*  f0cb63c:	3c05800a */ 	lui	$a1,%hi(g_Vars+0x284)
/*  f0cb640:	8ca5a244 */ 	lw	$a1,%lo(g_Vars+0x284)($a1)
/*  f0cb644:	c4ac0138 */ 	lwc1	$f12,0x138($a1)
.L0f0cb648:
/*  f0cb648:	12000008 */ 	beqz	$s0,.L0f0cb66c
/*  f0cb64c:	c4ae0128 */ 	lwc1	$f14,0x128($a1)
/*  f0cb650:	c420d8cc */ 	lwc1	$f0,%lo(var7f1ad8cc)($at)
/*  f0cb654:	44060000 */ 	mfc1	$a2,$f0
/*  f0cb658:	44070000 */ 	mfc1	$a3,$f0
/*  f0cb65c:	0fc280e5 */ 	jal	bgun0f0a0394
/*  f0cb660:	00000000 */ 	nop
/*  f0cb664:	10000043 */ 	b	.L0f0cb774
/*  f0cb668:	8fbf0034 */ 	lw	$ra,0x34($sp)
.L0f0cb66c:
/*  f0cb66c:	0fc282cc */ 	jal	bgunSwivelTowards
/*  f0cb670:	8ca61b68 */ 	lw	$a2,0x1b68($a1)
/*  f0cb674:	1000003f */ 	b	.L0f0cb774
/*  f0cb678:	8fbf0034 */ 	lw	$ra,0x34($sp)
.L0f0cb67c:
/*  f0cb67c:	8e450284 */ 	lw	$a1,0x284($s2)
.L0f0cb680:
/*  f0cb680:	3c017f1b */ 	lui	$at,%hi(var7f1ad8d0)
/*  f0cb684:	c422d8d0 */ 	lwc1	$f2,%lo(var7f1ad8d0)($at)
/*  f0cb688:	c4a01b68 */ 	lwc1	$f0,0x1b68($a1)
/*  f0cb68c:	3c017f1b */ 	lui	$at,%hi(var7f1ad8d4)
/*  f0cb690:	4602003c */ 	c.lt.s	$f0,$f2
/*  f0cb694:	00000000 */ 	nop
/*  f0cb698:	45020009 */ 	bc1fl	.L0f0cb6c0
/*  f0cb69c:	4600103c */ 	c.lt.s	$f2,$f0
/*  f0cb6a0:	c432d8d4 */ 	lwc1	$f18,%lo(var7f1ad8d4)($at)
/*  f0cb6a4:	c644004c */ 	lwc1	$f4,0x4c($s2)
/*  f0cb6a8:	46049282 */ 	mul.s	$f10,$f18,$f4
/*  f0cb6ac:	460a0180 */ 	add.s	$f6,$f0,$f10
/*  f0cb6b0:	e4a61b68 */ 	swc1	$f6,0x1b68($a1)
/*  f0cb6b4:	8e450284 */ 	lw	$a1,0x284($s2)
/*  f0cb6b8:	c4a01b68 */ 	lwc1	$f0,0x1b68($a1)
/*  f0cb6bc:	4600103c */ 	c.lt.s	$f2,$f0
.L0f0cb6c0:
/*  f0cb6c0:	3c017f1b */ 	lui	$at,%hi(var7f1ad8d8)
/*  f0cb6c4:	45000004 */ 	bc1f	.L0f0cb6d8
/*  f0cb6c8:	00000000 */ 	nop
/*  f0cb6cc:	e4a21b68 */ 	swc1	$f2,0x1b68($a1)
/*  f0cb6d0:	3c05800a */ 	lui	$a1,%hi(g_Vars+0x284)
/*  f0cb6d4:	8ca5a244 */ 	lw	$a1,%lo(g_Vars+0x284)($a1)
.L0f0cb6d8:
/*  f0cb6d8:	c422d8d8 */ 	lwc1	$f2,%lo(var7f1ad8d8)($at)
/*  f0cb6dc:	3c017f1b */ 	lui	$at,%hi(var7f1ad8dc)
/*  f0cb6e0:	c428d8dc */ 	lwc1	$f8,%lo(var7f1ad8dc)($at)
/*  f0cb6e4:	c4b00148 */ 	lwc1	$f16,0x148($a1)
/*  f0cb6e8:	c4aa015c */ 	lwc1	$f10,0x15c($a1)
/*  f0cb6ec:	3c017f1b */ 	lui	$at,%hi(var7f1ad8e0)
/*  f0cb6f0:	46088482 */ 	mul.s	$f18,$f16,$f8
/*  f0cb6f4:	c430d8e0 */ 	lwc1	$f16,%lo(var7f1ad8e0)($at)
/*  f0cb6f8:	46005187 */ 	neg.s	$f6,$f10
/*  f0cb6fc:	c4a401b4 */ 	lwc1	$f4,0x1b4($a1)
/*  f0cb700:	46103202 */ 	mul.s	$f8,$f6,$f16
/*  f0cb704:	44061000 */ 	mfc1	$a2,$f2
/*  f0cb708:	46049300 */ 	add.s	$f12,$f18,$f4
/*  f0cb70c:	c4b201b8 */ 	lwc1	$f18,0x1b8($a1)
/*  f0cb710:	0fc282cc */ 	jal	bgunSwivelTowards
/*  f0cb714:	46124380 */ 	add.s	$f14,$f8,$f18
/*  f0cb718:	10000016 */ 	b	.L0f0cb774
/*  f0cb71c:	8fbf0034 */ 	lw	$ra,0x34($sp)
.L0f0cb720:
/*  f0cb720:	53200014 */ 	beqzl	$t9,.L0f0cb774
/*  f0cb724:	8fbf0034 */ 	lw	$ra,0x34($sp)
/*  f0cb728:	0fc2a4f4 */ 	jal	bgunSetAimType
/*  f0cb72c:	00002025 */ 	or	$a0,$zero,$zero
/*  f0cb730:	8fa30248 */ 	lw	$v1,0x248($sp)
/*  f0cb734:	8fa4024c */ 	lw	$a0,0x24c($sp)
/*  f0cb738:	3c017f1b */ 	lui	$at,%hi(var7f1ad8e4)
/*  f0cb73c:	44832000 */ 	mtc1	$v1,$f4
/*  f0cb740:	44848000 */ 	mtc1	$a0,$f16
/*  f0cb744:	c420d8e4 */ 	lwc1	$f0,%lo(var7f1ad8e4)($at)
/*  f0cb748:	468022a0 */ 	cvt.s.w	$f10,$f4
/*  f0cb74c:	3c0142a0 */ 	lui	$at,0x42a0
/*  f0cb750:	44811000 */ 	mtc1	$at,$f2
/*  f0cb754:	46808220 */ 	cvt.s.w	$f8,$f16
/*  f0cb758:	46005182 */ 	mul.s	$f6,$f10,$f0
/*  f0cb75c:	00000000 */ 	nop
/*  f0cb760:	46004482 */ 	mul.s	$f18,$f8,$f0
/*  f0cb764:	46023303 */ 	div.s	$f12,$f6,$f2
/*  f0cb768:	0fc282e6 */ 	jal	bgun0f0a0b98
/*  f0cb76c:	46029383 */ 	div.s	$f14,$f18,$f2
.L0f0cb770:
/*  f0cb770:	8fbf0034 */ 	lw	$ra,0x34($sp)
.L0f0cb774:
/*  f0cb774:	8fb00014 */ 	lw	$s0,0x14($sp)
/*  f0cb778:	8fb10018 */ 	lw	$s1,0x18($sp)
/*  f0cb77c:	8fb2001c */ 	lw	$s2,0x1c($sp)
/*  f0cb780:	8fb30020 */ 	lw	$s3,0x20($sp)
/*  f0cb784:	8fb40024 */ 	lw	$s4,0x24($sp)
/*  f0cb788:	8fb50028 */ 	lw	$s5,0x28($sp)
/*  f0cb78c:	8fb6002c */ 	lw	$s6,0x2c($sp)
/*  f0cb790:	8fb70030 */ 	lw	$s7,0x30($sp)
/*  f0cb794:	03e00008 */ 	jr	$ra
/*  f0cb798:	27bd0260 */ 	addiu	$sp,$sp,0x260
);
#elif VERSION >= VERSION_NTSC_1_0
GLOBAL_ASM(
glabel bmoveProcessInput
.late_rodata
glabel var7f1ad8b8
.word 0x3c23d70a
glabel var7f1ad8bc
.word 0x3c23d70a
glabel var7f1ad8c0
.word 0x3d4ccccd
glabel var7f1ad8c4
.word 0x3f76872b
glabel var7f1ad8c8
.word 0x39a7c599
glabel var7f1ad8cc
.word 0x3f6a3d71
glabel var7f1ad8d0
.word 0x3f7a9fbe
glabel var7f1ad8d4
.word 0x39a7c599
glabel var7f1ad8d8
.word 0x3f76872b
glabel var7f1ad8dc
.word 0x3e99999a
glabel var7f1ad8e0
.word 0x3dcccccd
glabel var7f1ad8e4
.word 0x3f266666
.text
/*  f0c8b90:	27bdfda0 */ 	addiu	$sp,$sp,-608
/*  f0c8b94:	afb2001c */ 	sw	$s2,0x1c($sp)
/*  f0c8b98:	3c12800a */ 	lui	$s2,%hi(g_Vars)
/*  f0c8b9c:	26529fc0 */ 	addiu	$s2,$s2,%lo(g_Vars)
/*  f0c8ba0:	8e4e0288 */ 	lw	$t6,0x288($s2)
/*  f0c8ba4:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f0c8ba8:	00808025 */ 	or	$s0,$a0,$zero
/*  f0c8bac:	afbf0034 */ 	sw	$ra,0x34($sp)
/*  f0c8bb0:	afb70030 */ 	sw	$s7,0x30($sp)
/*  f0c8bb4:	afb6002c */ 	sw	$s6,0x2c($sp)
/*  f0c8bb8:	afb50028 */ 	sw	$s5,0x28($sp)
/*  f0c8bbc:	afb40024 */ 	sw	$s4,0x24($sp)
/*  f0c8bc0:	afb30020 */ 	sw	$s3,0x20($sp)
/*  f0c8bc4:	afb10018 */ 	sw	$s1,0x18($sp)
/*  f0c8bc8:	afa7026c */ 	sw	$a3,0x26c($sp)
/*  f0c8bcc:	00a08825 */ 	or	$s1,$a1,$zero
/*  f0c8bd0:	00c0b025 */ 	or	$s6,$a2,$zero
/*  f0c8bd4:	0fc549c4 */ 	jal	optionsGetControlMode
/*  f0c8bd8:	8dc40070 */ 	lw	$a0,0x70($t6)
/*  f0c8bdc:	afa201b0 */ 	sw	$v0,0x1b0($sp)
/*  f0c8be0:	0fc2866a */ 	jal	bgunGetWeaponNum
/*  f0c8be4:	00002025 */ 	or	$a0,$zero,$zero
/*  f0c8be8:	afa201ac */ 	sw	$v0,0x1ac($sp)
/*  f0c8bec:	00402025 */ 	or	$a0,$v0,$zero
/*  f0c8bf0:	0fc2c601 */ 	jal	weaponHasClassFlag
/*  f0c8bf4:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f0c8bf8:	8e4f0288 */ 	lw	$t7,0x288($s2)
/*  f0c8bfc:	afa201a8 */ 	sw	$v0,0x1a8($sp)
/*  f0c8c00:	0fc549d2 */ 	jal	optionsGetContpadNum1
/*  f0c8c04:	8de40070 */ 	lw	$a0,0x70($t7)
/*  f0c8c08:	0002ae00 */ 	sll	$s5,$v0,0x18
/*  f0c8c0c:	0015c603 */ 	sra	$t8,$s5,0x18
/*  f0c8c10:	12000009 */ 	beqz	$s0,.L0f0c8c38
/*  f0c8c14:	0300a825 */ 	or	$s5,$t8,$zero
/*  f0c8c18:	00182600 */ 	sll	$a0,$t8,0x18
/*  f0c8c1c:	0004ce03 */ 	sra	$t9,$a0,0x18
/*  f0c8c20:	0c005384 */ 	jal	joyGetStickX
/*  f0c8c24:	03202025 */ 	or	$a0,$t9,$zero
/*  f0c8c28:	0002a600 */ 	sll	$s4,$v0,0x18
/*  f0c8c2c:	00144603 */ 	sra	$t0,$s4,0x18
/*  f0c8c30:	10000002 */ 	b	.L0f0c8c3c
/*  f0c8c34:	0100a025 */ 	or	$s4,$t0,$zero
.L0f0c8c38:
/*  f0c8c38:	0000a025 */ 	or	$s4,$zero,$zero
.L0f0c8c3c:
/*  f0c8c3c:	12200008 */ 	beqz	$s1,.L0f0c8c60
/*  f0c8c40:	00152600 */ 	sll	$a0,$s5,0x18
/*  f0c8c44:	00044e03 */ 	sra	$t1,$a0,0x18
/*  f0c8c48:	0c0053ae */ 	jal	joyGetStickY
/*  f0c8c4c:	01202025 */ 	or	$a0,$t1,$zero
/*  f0c8c50:	00029e00 */ 	sll	$s3,$v0,0x18
/*  f0c8c54:	00135603 */ 	sra	$t2,$s3,0x18
/*  f0c8c58:	10000002 */ 	b	.L0f0c8c64
/*  f0c8c5c:	01409825 */ 	or	$s3,$t2,$zero
.L0f0c8c60:
/*  f0c8c60:	00009825 */ 	or	$s3,$zero,$zero
.L0f0c8c64:
/*  f0c8c64:	0016b82b */ 	sltu	$s7,$zero,$s6
/*  f0c8c68:	12e00007 */ 	beqz	$s7,.L0f0c8c88
/*  f0c8c6c:	00152600 */ 	sll	$a0,$s5,0x18
/*  f0c8c70:	00045e03 */ 	sra	$t3,$a0,0x18
/*  f0c8c74:	01602025 */ 	or	$a0,$t3,$zero
/*  f0c8c78:	0c0053d8 */ 	jal	joyGetButtons
/*  f0c8c7c:	3405ffff */ 	dli	$a1,0xffff
/*  f0c8c80:	10000002 */ 	b	.L0f0c8c8c
/*  f0c8c84:	a7a201a2 */ 	sh	$v0,0x1a2($sp)
.L0f0c8c88:
/*  f0c8c88:	a7a001a2 */ 	sh	$zero,0x1a2($sp)
.L0f0c8c8c:
/*  f0c8c8c:	12e00007 */ 	beqz	$s7,.L0f0c8cac
/*  f0c8c90:	00152600 */ 	sll	$a0,$s5,0x18
/*  f0c8c94:	00046603 */ 	sra	$t4,$a0,0x18
/*  f0c8c98:	01802025 */ 	or	$a0,$t4,$zero
/*  f0c8c9c:	0c005408 */ 	jal	joyGetButtonsPressedThisFrame
/*  f0c8ca0:	3405ffff */ 	dli	$a1,0xffff
/*  f0c8ca4:	10000002 */ 	b	.L0f0c8cb0
/*  f0c8ca8:	a7a201a0 */ 	sh	$v0,0x1a0($sp)
.L0f0c8cac:
/*  f0c8cac:	a7a001a0 */ 	sh	$zero,0x1a0($sp)
.L0f0c8cb0:
/*  f0c8cb0:	8e4e0284 */ 	lw	$t6,0x284($s2)
/*  f0c8cb4:	340dffff */ 	dli	$t5,0xffff
/*  f0c8cb8:	a7ad019e */ 	sh	$t5,0x19e($sp)
/*  f0c8cbc:	8dc21c40 */ 	lw	$v0,0x1c40($t6)
/*  f0c8cc0:	304fffff */ 	andi	$t7,$v0,0xffff
/*  f0c8cc4:	11e00017 */ 	beqz	$t7,.L0f0c8d24
/*  f0c8cc8:	31f0ffff */ 	andi	$s0,$t7,0xffff
/*  f0c8ccc:	00152600 */ 	sll	$a0,$s5,0x18
/*  f0c8cd0:	0200c027 */ 	nor	$t8,$s0,$zero
/*  f0c8cd4:	0004ce03 */ 	sra	$t9,$a0,0x18
/*  f0c8cd8:	a7b8019e */ 	sh	$t8,0x19e($sp)
/*  f0c8cdc:	03202025 */ 	or	$a0,$t9,$zero
/*  f0c8ce0:	0c0053d8 */ 	jal	joyGetButtons
/*  f0c8ce4:	3405ffff */ 	dli	$a1,0xffff
/*  f0c8ce8:	00508824 */ 	and	$s1,$v0,$s0
/*  f0c8cec:	97a901a2 */ 	lhu	$t1,0x1a2($sp)
/*  f0c8cf0:	97ab01a0 */ 	lhu	$t3,0x1a0($sp)
/*  f0c8cf4:	3228ffff */ 	andi	$t0,$s1,0xffff
/*  f0c8cf8:	01001827 */ 	nor	$v1,$t0,$zero
/*  f0c8cfc:	8e450284 */ 	lw	$a1,0x284($s2)
/*  f0c8d00:	01235024 */ 	and	$t2,$t1,$v1
/*  f0c8d04:	01636024 */ 	and	$t4,$t3,$v1
/*  f0c8d08:	a7aa01a2 */ 	sh	$t2,0x1a2($sp)
/*  f0c8d0c:	a7ac01a0 */ 	sh	$t4,0x1a0($sp)
/*  f0c8d10:	8cad1c40 */ 	lw	$t5,0x1c40($a1)
/*  f0c8d14:	3c01ffff */ 	lui	$at,0xffff
/*  f0c8d18:	01a17024 */ 	and	$t6,$t5,$at
/*  f0c8d1c:	01c87825 */ 	or	$t7,$t6,$t0
/*  f0c8d20:	acaf1c40 */ 	sw	$t7,0x1c40($a1)
.L0f0c8d24:
/*  f0c8d24:	0c005207 */ 	jal	joyGetNumSamples
/*  f0c8d28:	00000000 */ 	nop
/*  f0c8d2c:	0040b025 */ 	or	$s6,$v0,$zero
/*  f0c8d30:	0fc322aa */ 	jal	bmoveResetMoveData
/*  f0c8d34:	27a401b4 */ 	addiu	$a0,$sp,0x1b4
/*  f0c8d38:	2a81fffb */ 	slti	$at,$s4,-5
/*  f0c8d3c:	10200003 */ 	beqz	$at,.L0f0c8d4c
/*  f0c8d40:	26980005 */ 	addiu	$t8,$s4,0x5
/*  f0c8d44:	10000007 */ 	b	.L0f0c8d64
/*  f0c8d48:	afb80240 */ 	sw	$t8,0x240($sp)
.L0f0c8d4c:
/*  f0c8d4c:	2a810006 */ 	slti	$at,$s4,0x6
/*  f0c8d50:	14200003 */ 	bnez	$at,.L0f0c8d60
/*  f0c8d54:	2699fffb */ 	addiu	$t9,$s4,-5
/*  f0c8d58:	10000002 */ 	b	.L0f0c8d64
/*  f0c8d5c:	afb90240 */ 	sw	$t9,0x240($sp)
.L0f0c8d60:
/*  f0c8d60:	afa00240 */ 	sw	$zero,0x240($sp)
.L0f0c8d64:
/*  f0c8d64:	2a61fffb */ 	slti	$at,$s3,-5
/*  f0c8d68:	10200003 */ 	beqz	$at,.L0f0c8d78
/*  f0c8d6c:	26680005 */ 	addiu	$t0,$s3,0x5
/*  f0c8d70:	10000007 */ 	b	.L0f0c8d90
/*  f0c8d74:	afa80244 */ 	sw	$t0,0x244($sp)
.L0f0c8d78:
/*  f0c8d78:	2a610006 */ 	slti	$at,$s3,0x6
/*  f0c8d7c:	14200003 */ 	bnez	$at,.L0f0c8d8c
/*  f0c8d80:	2669fffb */ 	addiu	$t1,$s3,-5
/*  f0c8d84:	10000002 */ 	b	.L0f0c8d90
/*  f0c8d88:	afa90244 */ 	sw	$t1,0x244($sp)
.L0f0c8d8c:
/*  f0c8d8c:	afa00244 */ 	sw	$zero,0x244($sp)
.L0f0c8d90:
/*  f0c8d90:	8faa0240 */ 	lw	$t2,0x240($sp)
/*  f0c8d94:	8fab0244 */ 	lw	$t3,0x244($sp)
/*  f0c8d98:	8e450284 */ 	lw	$a1,0x284($s2)
/*  f0c8d9c:	afb40248 */ 	sw	$s4,0x248($sp)
/*  f0c8da0:	afb3024c */ 	sw	$s3,0x24c($sp)
/*  f0c8da4:	afaa0250 */ 	sw	$t2,0x250($sp)
/*  f0c8da8:	afaa0258 */ 	sw	$t2,0x258($sp)
/*  f0c8dac:	afab0254 */ 	sw	$t3,0x254($sp)
/*  f0c8db0:	afab025c */ 	sw	$t3,0x25c($sp)
/*  f0c8db4:	8cac00d8 */ 	lw	$t4,0xd8($a1)
/*  f0c8db8:	55800017 */ 	bnezl	$t4,.L0f0c8e18
/*  f0c8dbc:	8e480314 */ 	lw	$t0,0x314($s2)
/*  f0c8dc0:	8cad1a24 */ 	lw	$t5,0x1a24($a1)
/*  f0c8dc4:	97ae01a0 */ 	lhu	$t6,0x1a0($sp)
/*  f0c8dc8:	15a0004a */ 	bnez	$t5,.L0f0c8ef4
/*  f0c8dcc:	31cf1000 */ 	andi	$t7,$t6,0x1000
/*  f0c8dd0:	51e00049 */ 	beqzl	$t7,.L0f0c8ef8
/*  f0c8dd4:	8e450284 */ 	lw	$a1,0x284($s2)
/*  f0c8dd8:	8e580314 */ 	lw	$t8,0x314($s2)
/*  f0c8ddc:	17000009 */ 	bnez	$t8,.L0f0c8e04
/*  f0c8de0:	00000000 */ 	nop
/*  f0c8de4:	8e59000c */ 	lw	$t9,0xc($s2)
/*  f0c8de8:	2b210010 */ 	slti	$at,$t9,0x10
/*  f0c8dec:	54200042 */ 	bnezl	$at,.L0f0c8ef8
/*  f0c8df0:	8e450284 */ 	lw	$a1,0x284($s2)
/*  f0c8df4:	0fc2ebc3 */ 	jal	currentPlayerPause
/*  f0c8df8:	24040002 */ 	addiu	$a0,$zero,0x2
/*  f0c8dfc:	1000003e */ 	b	.L0f0c8ef8
/*  f0c8e00:	8e450284 */ 	lw	$a1,0x284($s2)
.L0f0c8e04:
/*  f0c8e04:	0fc5e36f */ 	jal	mpPushPauseDialog
/*  f0c8e08:	00000000 */ 	nop
/*  f0c8e0c:	1000003a */ 	b	.L0f0c8ef8
/*  f0c8e10:	8e450284 */ 	lw	$a1,0x284($s2)
/*  f0c8e14:	8e480314 */ 	lw	$t0,0x314($s2)
.L0f0c8e18:
/*  f0c8e18:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0c8e1c:	51000036 */ 	beqzl	$t0,.L0f0c8ef8
/*  f0c8e20:	8e450284 */ 	lw	$a1,0x284($s2)
/*  f0c8e24:	8e49006c */ 	lw	$t1,0x6c($s2)
/*  f0c8e28:	00002825 */ 	or	$a1,$zero,$zero
/*  f0c8e2c:	00001025 */ 	or	$v0,$zero,$zero
/*  f0c8e30:	11200003 */ 	beqz	$t1,.L0f0c8e40
/*  f0c8e34:	00001825 */ 	or	$v1,$zero,$zero
/*  f0c8e38:	10000001 */ 	b	.L0f0c8e40
/*  f0c8e3c:	24050001 */ 	addiu	$a1,$zero,0x1
.L0f0c8e40:
/*  f0c8e40:	8e4a0068 */ 	lw	$t2,0x68($s2)
/*  f0c8e44:	00002025 */ 	or	$a0,$zero,$zero
/*  f0c8e48:	11400003 */ 	beqz	$t2,.L0f0c8e58
/*  f0c8e4c:	00000000 */ 	nop
/*  f0c8e50:	10000001 */ 	b	.L0f0c8e58
/*  f0c8e54:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f0c8e58:
/*  f0c8e58:	8e4b0064 */ 	lw	$t3,0x64($s2)
/*  f0c8e5c:	11600003 */ 	beqz	$t3,.L0f0c8e6c
/*  f0c8e60:	00000000 */ 	nop
/*  f0c8e64:	10000001 */ 	b	.L0f0c8e6c
/*  f0c8e68:	24030001 */ 	addiu	$v1,$zero,0x1
.L0f0c8e6c:
/*  f0c8e6c:	8e4c0070 */ 	lw	$t4,0x70($s2)
/*  f0c8e70:	11800003 */ 	beqz	$t4,.L0f0c8e80
/*  f0c8e74:	00000000 */ 	nop
/*  f0c8e78:	10000001 */ 	b	.L0f0c8e80
/*  f0c8e7c:	24040001 */ 	addiu	$a0,$zero,0x1
.L0f0c8e80:
/*  f0c8e80:	00836821 */ 	addu	$t5,$a0,$v1
/*  f0c8e84:	01a27021 */ 	addu	$t6,$t5,$v0
/*  f0c8e88:	01c57821 */ 	addu	$t7,$t6,$a1
/*  f0c8e8c:	15e10010 */ 	bne	$t7,$at,.L0f0c8ed0
/*  f0c8e90:	00000000 */ 	nop
/*  f0c8e94:	0fc62590 */ 	jal	mpIsPaused
/*  f0c8e98:	00000000 */ 	nop
/*  f0c8e9c:	10400015 */ 	beqz	$v0,.L0f0c8ef4
/*  f0c8ea0:	97b801a0 */ 	lhu	$t8,0x1a0($sp)
/*  f0c8ea4:	33191000 */ 	andi	$t9,$t8,0x1000
/*  f0c8ea8:	13200012 */ 	beqz	$t9,.L0f0c8ef4
/*  f0c8eac:	3c08800b */ 	lui	$t0,%hi(g_MpSetup+0x1e)
/*  f0c8eb0:	9108cba6 */ 	lbu	$t0,%lo(g_MpSetup+0x1e)($t0)
/*  f0c8eb4:	24010002 */ 	addiu	$at,$zero,0x2
/*  f0c8eb8:	5101000f */ 	beql	$t0,$at,.L0f0c8ef8
/*  f0c8ebc:	8e450284 */ 	lw	$a1,0x284($s2)
/*  f0c8ec0:	0fc625cb */ 	jal	mpSetPaused
/*  f0c8ec4:	00002025 */ 	or	$a0,$zero,$zero
/*  f0c8ec8:	1000000b */ 	b	.L0f0c8ef8
/*  f0c8ecc:	8e450284 */ 	lw	$a1,0x284($s2)
.L0f0c8ed0:
/*  f0c8ed0:	0fc62590 */ 	jal	mpIsPaused
/*  f0c8ed4:	00000000 */ 	nop
/*  f0c8ed8:	10400006 */ 	beqz	$v0,.L0f0c8ef4
/*  f0c8edc:	97a901a0 */ 	lhu	$t1,0x1a0($sp)
/*  f0c8ee0:	312a1000 */ 	andi	$t2,$t1,0x1000
/*  f0c8ee4:	51400004 */ 	beqzl	$t2,.L0f0c8ef8
/*  f0c8ee8:	8e450284 */ 	lw	$a1,0x284($s2)
/*  f0c8eec:	0fc5e36f */ 	jal	mpPushPauseDialog
/*  f0c8ef0:	00000000 */ 	nop
.L0f0c8ef4:
/*  f0c8ef4:	8e450284 */ 	lw	$a1,0x284($s2)
.L0f0c8ef8:
/*  f0c8ef8:	8cab1a24 */ 	lw	$t3,0x1a24($a1)
/*  f0c8efc:	55600675 */ 	bnezl	$t3,.L0f0ca8d4
/*  f0c8f00:	aca000d0 */ 	sw	$zero,0xd0($a1)
/*  f0c8f04:	8cac00d8 */ 	lw	$t4,0xd8($a1)
/*  f0c8f08:	8fa201b0 */ 	lw	$v0,0x1b0($sp)
/*  f0c8f0c:	24010006 */ 	addiu	$at,$zero,0x6
/*  f0c8f10:	55800670 */ 	bnezl	$t4,.L0f0ca8d4
/*  f0c8f14:	aca000d0 */ 	sw	$zero,0xd0($a1)
/*  f0c8f18:	10410007 */ 	beq	$v0,$at,.L0f0c8f38
/*  f0c8f1c:	24010007 */ 	addiu	$at,$zero,0x7
/*  f0c8f20:	10410005 */ 	beq	$v0,$at,.L0f0c8f38
/*  f0c8f24:	24010005 */ 	addiu	$at,$zero,0x5
/*  f0c8f28:	10410003 */ 	beq	$v0,$at,.L0f0c8f38
/*  f0c8f2c:	24010004 */ 	addiu	$at,$zero,0x4
/*  f0c8f30:	5441033f */ 	bnel	$v0,$at,.L0f0c9c30
/*  f0c8f34:	24010002 */ 	addiu	$at,$zero,0x2
.L0f0c8f38:
/*  f0c8f38:	8e4d0288 */ 	lw	$t5,0x288($s2)
/*  f0c8f3c:	0fc549d9 */ 	jal	optionsGetContpadNum2
/*  f0c8f40:	8da40070 */ 	lw	$a0,0x70($t5)
/*  f0c8f44:	0002a600 */ 	sll	$s4,$v0,0x18
/*  f0c8f48:	00022600 */ 	sll	$a0,$v0,0x18
/*  f0c8f4c:	00147603 */ 	sra	$t6,$s4,0x18
/*  f0c8f50:	00047e03 */ 	sra	$t7,$a0,0x18
/*  f0c8f54:	01c0a025 */ 	or	$s4,$t6,$zero
/*  f0c8f58:	0c005384 */ 	jal	joyGetStickX
/*  f0c8f5c:	01e02025 */ 	or	$a0,$t7,$zero
/*  f0c8f60:	00142600 */ 	sll	$a0,$s4,0x18
/*  f0c8f64:	0004c603 */ 	sra	$t8,$a0,0x18
/*  f0c8f68:	a3a200e9 */ 	sb	$v0,0xe9($sp)
/*  f0c8f6c:	0c0053ae */ 	jal	joyGetStickY
/*  f0c8f70:	03002025 */ 	or	$a0,$t8,$zero
/*  f0c8f74:	00028600 */ 	sll	$s0,$v0,0x18
/*  f0c8f78:	00142600 */ 	sll	$a0,$s4,0x18
/*  f0c8f7c:	0010ce03 */ 	sra	$t9,$s0,0x18
/*  f0c8f80:	00044603 */ 	sra	$t0,$a0,0x18
/*  f0c8f84:	03208025 */ 	or	$s0,$t9,$zero
/*  f0c8f88:	01002025 */ 	or	$a0,$t0,$zero
/*  f0c8f8c:	0c0053d8 */ 	jal	joyGetButtons
/*  f0c8f90:	3405ffff */ 	dli	$a1,0xffff
/*  f0c8f94:	00142600 */ 	sll	$a0,$s4,0x18
/*  f0c8f98:	00044e03 */ 	sra	$t1,$a0,0x18
/*  f0c8f9c:	a7a200e6 */ 	sh	$v0,0xe6($sp)
/*  f0c8fa0:	01202025 */ 	or	$a0,$t1,$zero
/*  f0c8fa4:	0c005408 */ 	jal	joyGetButtonsPressedThisFrame
/*  f0c8fa8:	3405ffff */ 	dli	$a1,0xffff
/*  f0c8fac:	8e4b0284 */ 	lw	$t3,0x284($s2)
/*  f0c8fb0:	340affff */ 	dli	$t2,0xffff
/*  f0c8fb4:	a7a200e4 */ 	sh	$v0,0xe4($sp)
/*  f0c8fb8:	a7aa00da */ 	sh	$t2,0xda($sp)
/*  f0c8fbc:	8d631c40 */ 	lw	$v1,0x1c40($t3)
/*  f0c8fc0:	83b300e9 */ 	lb	$s3,0xe9($sp)
/*  f0c8fc4:	02002025 */ 	or	$a0,$s0,$zero
/*  f0c8fc8:	00036402 */ 	srl	$t4,$v1,0x10
/*  f0c8fcc:	5180001b */ 	beqzl	$t4,.L0f0c903c
/*  f0c8fd0:	8faf026c */ 	lw	$t7,0x26c($sp)
/*  f0c8fd4:	afb000dc */ 	sw	$s0,0xdc($sp)
/*  f0c8fd8:	00038c02 */ 	srl	$s1,$v1,0x10
/*  f0c8fdc:	3230ffff */ 	andi	$s0,$s1,0xffff
/*  f0c8fe0:	00142600 */ 	sll	$a0,$s4,0x18
/*  f0c8fe4:	02007027 */ 	nor	$t6,$s0,$zero
/*  f0c8fe8:	00047e03 */ 	sra	$t7,$a0,0x18
/*  f0c8fec:	a7ae00da */ 	sh	$t6,0xda($sp)
/*  f0c8ff0:	01e02025 */ 	or	$a0,$t7,$zero
/*  f0c8ff4:	0c0053d8 */ 	jal	joyGetButtons
/*  f0c8ff8:	3405ffff */ 	dli	$a1,0xffff
/*  f0c8ffc:	97b900e6 */ 	lhu	$t9,0xe6($sp)
/*  f0c9000:	97a900e4 */ 	lhu	$t1,0xe4($sp)
/*  f0c9004:	0050c024 */ 	and	$t8,$v0,$s0
/*  f0c9008:	03001827 */ 	nor	$v1,$t8,$zero
/*  f0c900c:	8e450284 */ 	lw	$a1,0x284($s2)
/*  f0c9010:	03234024 */ 	and	$t0,$t9,$v1
/*  f0c9014:	01235024 */ 	and	$t2,$t1,$v1
/*  f0c9018:	a7a800e6 */ 	sh	$t0,0xe6($sp)
/*  f0c901c:	a7aa00e4 */ 	sh	$t2,0xe4($sp)
/*  f0c9020:	8cab1c40 */ 	lw	$t3,0x1c40($a1)
/*  f0c9024:	00186c00 */ 	sll	$t5,$t8,0x10
/*  f0c9028:	316cffff */ 	andi	$t4,$t3,0xffff
/*  f0c902c:	018d7025 */ 	or	$t6,$t4,$t5
/*  f0c9030:	acae1c40 */ 	sw	$t6,0x1c40($a1)
/*  f0c9034:	8fa400dc */ 	lw	$a0,0xdc($sp)
/*  f0c9038:	8faf026c */ 	lw	$t7,0x26c($sp)
.L0f0c903c:
/*  f0c903c:	51e00007 */ 	beqzl	$t7,.L0f0c905c
/*  f0c9040:	2a61fffb */ 	slti	$at,$s3,-5
/*  f0c9044:	a3a000e9 */ 	sb	$zero,0xe9($sp)
/*  f0c9048:	a7a000e6 */ 	sh	$zero,0xe6($sp)
/*  f0c904c:	00009825 */ 	or	$s3,$zero,$zero
/*  f0c9050:	00002025 */ 	or	$a0,$zero,$zero
/*  f0c9054:	a7a000e4 */ 	sh	$zero,0xe4($sp)
/*  f0c9058:	2a61fffb */ 	slti	$at,$s3,-5
.L0f0c905c:
/*  f0c905c:	10200003 */ 	beqz	$at,.L0f0c906c
/*  f0c9060:	8fa201b0 */ 	lw	$v0,0x1b0($sp)
/*  f0c9064:	10000007 */ 	b	.L0f0c9084
/*  f0c9068:	26730005 */ 	addiu	$s3,$s3,0x5
.L0f0c906c:
/*  f0c906c:	2a610006 */ 	slti	$at,$s3,0x6
/*  f0c9070:	54200004 */ 	bnezl	$at,.L0f0c9084
/*  f0c9074:	00009825 */ 	or	$s3,$zero,$zero
/*  f0c9078:	10000002 */ 	b	.L0f0c9084
/*  f0c907c:	2673fffb */ 	addiu	$s3,$s3,-5
/*  f0c9080:	00009825 */ 	or	$s3,$zero,$zero
.L0f0c9084:
/*  f0c9084:	2881fffb */ 	slti	$at,$a0,-5
/*  f0c9088:	50200004 */ 	beqzl	$at,.L0f0c909c
/*  f0c908c:	28810006 */ 	slti	$at,$a0,0x6
/*  f0c9090:	10000007 */ 	b	.L0f0c90b0
/*  f0c9094:	24840005 */ 	addiu	$a0,$a0,0x5
/*  f0c9098:	28810006 */ 	slti	$at,$a0,0x6
.L0f0c909c:
/*  f0c909c:	54200004 */ 	bnezl	$at,.L0f0c90b0
/*  f0c90a0:	00002025 */ 	or	$a0,$zero,$zero
/*  f0c90a4:	10000002 */ 	b	.L0f0c90b0
/*  f0c90a8:	2484fffb */ 	addiu	$a0,$a0,-5
/*  f0c90ac:	00002025 */ 	or	$a0,$zero,$zero
.L0f0c90b0:
/*  f0c90b0:	24010004 */ 	addiu	$at,$zero,0x4
/*  f0c90b4:	10410003 */ 	beq	$v0,$at,.L0f0c90c4
/*  f0c90b8:	24010006 */ 	addiu	$at,$zero,0x6
/*  f0c90bc:	54410005 */ 	bnel	$v0,$at,.L0f0c90d4
/*  f0c90c0:	afb30258 */ 	sw	$s3,0x258($sp)
.L0f0c90c4:
/*  f0c90c4:	afb30258 */ 	sw	$s3,0x258($sp)
/*  f0c90c8:	10000003 */ 	b	.L0f0c90d8
/*  f0c90cc:	afa40254 */ 	sw	$a0,0x254($sp)
/*  f0c90d0:	afb30258 */ 	sw	$s3,0x258($sp)
.L0f0c90d4:
/*  f0c90d4:	afa4025c */ 	sw	$a0,0x25c($sp)
.L0f0c90d8:
/*  f0c90d8:	8e5802ac */ 	lw	$t8,0x2ac($s2)
/*  f0c90dc:	24010007 */ 	addiu	$at,$zero,0x7
/*  f0c90e0:	afa400dc */ 	sw	$a0,0xdc($sp)
/*  f0c90e4:	5701000b */ 	bnel	$t8,$at,.L0f0c9114
/*  f0c90e8:	24010004 */ 	addiu	$at,$zero,0x4
/*  f0c90ec:	8e450284 */ 	lw	$a1,0x284($s2)
/*  f0c90f0:	afa001d4 */ 	sw	$zero,0x1d4($sp)
/*  f0c90f4:	afa001d8 */ 	sw	$zero,0x1d8($sp)
/*  f0c90f8:	afa00258 */ 	sw	$zero,0x258($sp)
/*  f0c90fc:	8cb91bdc */ 	lw	$t9,0x1bdc($a1)
/*  f0c9100:	afb9025c */ 	sw	$t9,0x25c($sp)
/*  f0c9104:	8ca81bd8 */ 	lw	$t0,0x1bd8($a1)
/*  f0c9108:	afa00254 */ 	sw	$zero,0x254($sp)
/*  f0c910c:	afa80250 */ 	sw	$t0,0x250($sp)
/*  f0c9110:	24010004 */ 	addiu	$at,$zero,0x4
.L0f0c9114:
/*  f0c9114:	10410005 */ 	beq	$v0,$at,.L0f0c912c
/*  f0c9118:	8fa400dc */ 	lw	$a0,0xdc($sp)
/*  f0c911c:	24010005 */ 	addiu	$at,$zero,0x5
/*  f0c9120:	1441000b */ 	bne	$v0,$at,.L0f0c9150
/*  f0c9124:	00158e00 */ 	sll	$s1,$s5,0x18
/*  f0c9128:	afa400dc */ 	sw	$a0,0xdc($sp)
.L0f0c912c:
/*  f0c912c:	97aa00da */ 	lhu	$t2,0xda($sp)
/*  f0c9130:	97ab019e */ 	lhu	$t3,0x19e($sp)
/*  f0c9134:	00148e00 */ 	sll	$s1,$s4,0x18
/*  f0c9138:	00114e03 */ 	sra	$t1,$s1,0x18
/*  f0c913c:	01208825 */ 	or	$s1,$t1,$zero
/*  f0c9140:	a3b500ef */ 	sb	$s5,0xef($sp)
/*  f0c9144:	a7aa00ec */ 	sh	$t2,0xec($sp)
/*  f0c9148:	10000009 */ 	b	.L0f0c9170
/*  f0c914c:	a7ab00ea */ 	sh	$t3,0xea($sp)
.L0f0c9150:
/*  f0c9150:	97ad019e */ 	lhu	$t5,0x19e($sp)
/*  f0c9154:	97ae00da */ 	lhu	$t6,0xda($sp)
/*  f0c9158:	00116603 */ 	sra	$t4,$s1,0x18
/*  f0c915c:	afa400dc */ 	sw	$a0,0xdc($sp)
/*  f0c9160:	01808825 */ 	or	$s1,$t4,$zero
/*  f0c9164:	a3b400ef */ 	sb	$s4,0xef($sp)
/*  f0c9168:	a7ad00ec */ 	sh	$t5,0xec($sp)
/*  f0c916c:	a7ae00ea */ 	sh	$t6,0xea($sp)
.L0f0c9170:
/*  f0c9170:	8e4f0288 */ 	lw	$t7,0x288($s2)
/*  f0c9174:	0fc549fb */ 	jal	optionsGetAimControl
/*  f0c9178:	8de40070 */ 	lw	$a0,0x70($t7)
/*  f0c917c:	1440001f */ 	bnez	$v0,.L0f0c91fc
/*  f0c9180:	00000000 */ 	nop
/*  f0c9184:	1ac00018 */ 	blez	$s6,.L0f0c91e8
/*  f0c9188:	00008025 */ 	or	$s0,$zero,$zero
/*  f0c918c:	27a3014c */ 	addiu	$v1,$sp,0x14c
/*  f0c9190:	27a700fc */ 	addiu	$a3,$sp,0xfc
.L0f0c9194:
/*  f0c9194:	12e0000d */ 	beqz	$s7,.L0f0c91cc
/*  f0c9198:	02e02025 */ 	or	$a0,$s7,$zero
/*  f0c919c:	97b900ec */ 	lhu	$t9,0xec($sp)
/*  f0c91a0:	00112e00 */ 	sll	$a1,$s1,0x18
/*  f0c91a4:	0005c603 */ 	sra	$t8,$a1,0x18
/*  f0c91a8:	03002825 */ 	or	$a1,$t8,$zero
/*  f0c91ac:	02002025 */ 	or	$a0,$s0,$zero
/*  f0c91b0:	afa3004c */ 	sw	$v1,0x4c($sp)
/*  f0c91b4:	afa70048 */ 	sw	$a3,0x48($sp)
/*  f0c91b8:	0c00529e */ 	jal	joyGetButtonsOnSample
/*  f0c91bc:	33262000 */ 	andi	$a2,$t9,0x2000
/*  f0c91c0:	8fa3004c */ 	lw	$v1,0x4c($sp)
/*  f0c91c4:	8fa70048 */ 	lw	$a3,0x48($sp)
/*  f0c91c8:	0002202b */ 	sltu	$a0,$zero,$v0
.L0f0c91cc:
/*  f0c91cc:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f0c91d0:	2c890001 */ 	sltiu	$t1,$a0,0x1
/*  f0c91d4:	24630004 */ 	addiu	$v1,$v1,0x4
/*  f0c91d8:	24e70004 */ 	addiu	$a3,$a3,0x4
/*  f0c91dc:	ac64fffc */ 	sw	$a0,-0x4($v1)
/*  f0c91e0:	1616ffec */ 	bne	$s0,$s6,.L0f0c9194
/*  f0c91e4:	ace9fffc */ 	sw	$t1,-0x4($a3)
.L0f0c91e8:
/*  f0c91e8:	00165080 */ 	sll	$t2,$s6,0x2
/*  f0c91ec:	03aa5821 */ 	addu	$t3,$sp,$t2
/*  f0c91f0:	8d6b0148 */ 	lw	$t3,0x148($t3)
/*  f0c91f4:	8e4c0284 */ 	lw	$t4,0x284($s2)
/*  f0c91f8:	ad8b0120 */ 	sw	$t3,0x120($t4)
.L0f0c91fc:
/*  f0c91fc:	0fc5b364 */ 	jal	lvIsPaused
/*  f0c9200:	00000000 */ 	nop
/*  f0c9204:	54400243 */ 	bnezl	$v0,.L0f0c9b14
/*  f0c9208:	8e450284 */ 	lw	$a1,0x284($s2)
/*  f0c920c:	8e4d0288 */ 	lw	$t5,0x288($s2)
/*  f0c9210:	0fc549fb */ 	jal	optionsGetAimControl
/*  f0c9214:	8da40070 */ 	lw	$a0,0x70($t5)
/*  f0c9218:	1040001f */ 	beqz	$v0,.L0f0c9298
/*  f0c921c:	00000000 */ 	nop
/*  f0c9220:	1ac0001d */ 	blez	$s6,.L0f0c9298
/*  f0c9224:	00008025 */ 	or	$s0,$zero,$zero
/*  f0c9228:	27a3014c */ 	addiu	$v1,$sp,0x14c
/*  f0c922c:	27a700fc */ 	addiu	$a3,$sp,0xfc
.L0f0c9230:
/*  f0c9230:	12e00010 */ 	beqz	$s7,.L0f0c9274
/*  f0c9234:	02002025 */ 	or	$a0,$s0,$zero
/*  f0c9238:	97af00ec */ 	lhu	$t7,0xec($sp)
/*  f0c923c:	00112e00 */ 	sll	$a1,$s1,0x18
/*  f0c9240:	00057603 */ 	sra	$t6,$a1,0x18
/*  f0c9244:	01c02825 */ 	or	$a1,$t6,$zero
/*  f0c9248:	afa3004c */ 	sw	$v1,0x4c($sp)
/*  f0c924c:	afa70048 */ 	sw	$a3,0x48($sp)
/*  f0c9250:	0c0052d4 */ 	jal	joyGetButtonsPressedOnSample
/*  f0c9254:	31e62000 */ 	andi	$a2,$t7,0x2000
/*  f0c9258:	8fa3004c */ 	lw	$v1,0x4c($sp)
/*  f0c925c:	10400005 */ 	beqz	$v0,.L0f0c9274
/*  f0c9260:	8fa70048 */ 	lw	$a3,0x48($sp)
/*  f0c9264:	8e450284 */ 	lw	$a1,0x284($s2)
/*  f0c9268:	8ca40120 */ 	lw	$a0,0x120($a1)
/*  f0c926c:	2c990001 */ 	sltiu	$t9,$a0,0x1
/*  f0c9270:	acb90120 */ 	sw	$t9,0x120($a1)
.L0f0c9274:
/*  f0c9274:	8e480284 */ 	lw	$t0,0x284($s2)
/*  f0c9278:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f0c927c:	24630004 */ 	addiu	$v1,$v1,0x4
/*  f0c9280:	8d090120 */ 	lw	$t1,0x120($t0)
/*  f0c9284:	24e70004 */ 	addiu	$a3,$a3,0x4
/*  f0c9288:	2d2a0001 */ 	sltiu	$t2,$t1,0x1
/*  f0c928c:	aceafffc */ 	sw	$t2,-0x4($a3)
/*  f0c9290:	1616ffe7 */ 	bne	$s0,$s6,.L0f0c9230
/*  f0c9294:	ac69fffc */ 	sw	$t1,-0x4($v1)
.L0f0c9298:
/*  f0c9298:	0fc2866a */ 	jal	bgunGetWeaponNum
/*  f0c929c:	00002025 */ 	or	$a0,$zero,$zero
/*  f0c92a0:	24010032 */ 	addiu	$at,$zero,0x32
/*  f0c92a4:	54410005 */ 	bnel	$v0,$at,.L0f0c92bc
/*  f0c92a8:	8e450284 */ 	lw	$a1,0x284($s2)
/*  f0c92ac:	8e4c0284 */ 	lw	$t4,0x284($s2)
/*  f0c92b0:	240b0001 */ 	addiu	$t3,$zero,0x1
/*  f0c92b4:	ad8b0120 */ 	sw	$t3,0x120($t4)
/*  f0c92b8:	8e450284 */ 	lw	$a1,0x284($s2)
.L0f0c92bc:
/*  f0c92bc:	24190001 */ 	addiu	$t9,$zero,0x1
/*  f0c92c0:	8ca40120 */ 	lw	$a0,0x120($a1)
/*  f0c92c4:	2c8d0001 */ 	sltiu	$t5,$a0,0x1
/*  f0c92c8:	afad01b4 */ 	sw	$t5,0x1b4($sp)
/*  f0c92cc:	8cae0120 */ 	lw	$t6,0x120($a1)
/*  f0c92d0:	afae01b8 */ 	sw	$t6,0x1b8($sp)
/*  f0c92d4:	8ca40120 */ 	lw	$a0,0x120($a1)
/*  f0c92d8:	afa001d4 */ 	sw	$zero,0x1d4($sp)
/*  f0c92dc:	afa001d8 */ 	sw	$zero,0x1d8($sp)
/*  f0c92e0:	2c8f0001 */ 	sltiu	$t7,$a0,0x1
/*  f0c92e4:	afaf022c */ 	sw	$t7,0x22c($sp)
/*  f0c92e8:	afa001dc */ 	sw	$zero,0x1dc($sp)
/*  f0c92ec:	afa001e0 */ 	sw	$zero,0x1e0($sp)
/*  f0c92f0:	8ca40120 */ 	lw	$a0,0x120($a1)
/*  f0c92f4:	afb901c8 */ 	sw	$t9,0x1c8($sp)
/*  f0c92f8:	2c980001 */ 	sltiu	$t8,$a0,0x1
/*  f0c92fc:	afb801c4 */ 	sw	$t8,0x1c4($sp)
/*  f0c9300:	8ca40120 */ 	lw	$a0,0x120($a1)
/*  f0c9304:	2c880001 */ 	sltiu	$t0,$a0,0x1
/*  f0c9308:	afa801cc */ 	sw	$t0,0x1cc($sp)
/*  f0c930c:	8ca40120 */ 	lw	$a0,0x120($a1)
/*  f0c9310:	2c890001 */ 	sltiu	$t1,$a0,0x1
/*  f0c9314:	afa901d0 */ 	sw	$t1,0x1d0($sp)
/*  f0c9318:	8caa0120 */ 	lw	$t2,0x120($a1)
/*  f0c931c:	51400015 */ 	beqzl	$t2,.L0f0c9374
/*  f0c9320:	44809000 */ 	mtc1	$zero,$f18
/*  f0c9324:	8fa4024c */ 	lw	$a0,0x24c($sp)
/*  f0c9328:	2881003d */ 	slti	$at,$a0,0x3d
/*  f0c932c:	14200010 */ 	bnez	$at,.L0f0c9370
/*  f0c9330:	248bffc4 */ 	addiu	$t3,$a0,-60
/*  f0c9334:	448b2000 */ 	mtc1	$t3,$f4
/*  f0c9338:	3c014120 */ 	lui	$at,0x4120
/*  f0c933c:	44811000 */ 	mtc1	$at,$f2
/*  f0c9340:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f0c9344:	3c013f80 */ 	lui	$at,0x3f80
/*  f0c9348:	44815000 */ 	mtc1	$at,$f10
/*  f0c934c:	3c013f80 */ 	lui	$at,0x3f80
/*  f0c9350:	46023203 */ 	div.s	$f8,$f6,$f2
/*  f0c9354:	4608503c */ 	c.lt.s	$f10,$f8
/*  f0c9358:	e7a801ec */ 	swc1	$f8,0x1ec($sp)
/*  f0c935c:	45020009 */ 	bc1fl	.L0f0c9384
/*  f0c9360:	8cac0120 */ 	lw	$t4,0x120($a1)
/*  f0c9364:	44818000 */ 	mtc1	$at,$f16
/*  f0c9368:	10000005 */ 	b	.L0f0c9380
/*  f0c936c:	e7b001ec */ 	swc1	$f16,0x1ec($sp)
.L0f0c9370:
/*  f0c9370:	44809000 */ 	mtc1	$zero,$f18
.L0f0c9374:
/*  f0c9374:	3c014120 */ 	lui	$at,0x4120
/*  f0c9378:	44811000 */ 	mtc1	$at,$f2
/*  f0c937c:	e7b201ec */ 	swc1	$f18,0x1ec($sp)
.L0f0c9380:
/*  f0c9380:	8cac0120 */ 	lw	$t4,0x120($a1)
.L0f0c9384:
/*  f0c9384:	51800014 */ 	beqzl	$t4,.L0f0c93d8
/*  f0c9388:	44809000 */ 	mtc1	$zero,$f18
/*  f0c938c:	8fa4024c */ 	lw	$a0,0x24c($sp)
/*  f0c9390:	240dffc4 */ 	addiu	$t5,$zero,-60
/*  f0c9394:	2881ffc4 */ 	slti	$at,$a0,-60
/*  f0c9398:	1020000e */ 	beqz	$at,.L0f0c93d4
/*  f0c939c:	01a47023 */ 	subu	$t6,$t5,$a0
/*  f0c93a0:	448e2000 */ 	mtc1	$t6,$f4
/*  f0c93a4:	3c013f80 */ 	lui	$at,0x3f80
/*  f0c93a8:	44814000 */ 	mtc1	$at,$f8
/*  f0c93ac:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f0c93b0:	3c013f80 */ 	lui	$at,0x3f80
/*  f0c93b4:	46023283 */ 	div.s	$f10,$f6,$f2
/*  f0c93b8:	460a403c */ 	c.lt.s	$f8,$f10
/*  f0c93bc:	e7aa01f0 */ 	swc1	$f10,0x1f0($sp)
/*  f0c93c0:	45020008 */ 	bc1fl	.L0f0c93e4
/*  f0c93c4:	8caf0120 */ 	lw	$t7,0x120($a1)
/*  f0c93c8:	44818000 */ 	mtc1	$at,$f16
/*  f0c93cc:	10000004 */ 	b	.L0f0c93e0
/*  f0c93d0:	e7b001f0 */ 	swc1	$f16,0x1f0($sp)
.L0f0c93d4:
/*  f0c93d4:	44809000 */ 	mtc1	$zero,$f18
.L0f0c93d8:
/*  f0c93d8:	00000000 */ 	nop
/*  f0c93dc:	e7b201f0 */ 	swc1	$f18,0x1f0($sp)
.L0f0c93e0:
/*  f0c93e0:	8caf0120 */ 	lw	$t7,0x120($a1)
.L0f0c93e4:
/*  f0c93e4:	8fa30248 */ 	lw	$v1,0x248($sp)
/*  f0c93e8:	11e00011 */ 	beqz	$t7,.L0f0c9430
/*  f0c93ec:	2861ffc4 */ 	slti	$at,$v1,-60
/*  f0c93f0:	1020000f */ 	beqz	$at,.L0f0c9430
/*  f0c93f4:	2418ffc4 */ 	addiu	$t8,$zero,-60
/*  f0c93f8:	0303c823 */ 	subu	$t9,$t8,$v1
/*  f0c93fc:	44992000 */ 	mtc1	$t9,$f4
/*  f0c9400:	3c013f80 */ 	lui	$at,0x3f80
/*  f0c9404:	44814000 */ 	mtc1	$at,$f8
/*  f0c9408:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f0c940c:	3c013f80 */ 	lui	$at,0x3f80
/*  f0c9410:	46023303 */ 	div.s	$f12,$f6,$f2
/*  f0c9414:	460c403c */ 	c.lt.s	$f8,$f12
/*  f0c9418:	e7ac01f4 */ 	swc1	$f12,0x1f4($sp)
/*  f0c941c:	45020008 */ 	bc1fl	.L0f0c9440
/*  f0c9420:	8ca80120 */ 	lw	$t0,0x120($a1)
/*  f0c9424:	44816000 */ 	mtc1	$at,$f12
/*  f0c9428:	10000004 */ 	b	.L0f0c943c
/*  f0c942c:	e7ac01f4 */ 	swc1	$f12,0x1f4($sp)
.L0f0c9430:
/*  f0c9430:	44806000 */ 	mtc1	$zero,$f12
/*  f0c9434:	00000000 */ 	nop
/*  f0c9438:	e7ac01f4 */ 	swc1	$f12,0x1f4($sp)
.L0f0c943c:
/*  f0c943c:	8ca80120 */ 	lw	$t0,0x120($a1)
.L0f0c9440:
/*  f0c9440:	8fa30248 */ 	lw	$v1,0x248($sp)
/*  f0c9444:	11000010 */ 	beqz	$t0,.L0f0c9488
/*  f0c9448:	2861003d */ 	slti	$at,$v1,0x3d
/*  f0c944c:	1420000e */ 	bnez	$at,.L0f0c9488
/*  f0c9450:	2469ffc4 */ 	addiu	$t1,$v1,-60
/*  f0c9454:	44895000 */ 	mtc1	$t1,$f10
/*  f0c9458:	3c013f80 */ 	lui	$at,0x3f80
/*  f0c945c:	44819000 */ 	mtc1	$at,$f18
/*  f0c9460:	46805420 */ 	cvt.s.w	$f16,$f10
/*  f0c9464:	3c013f80 */ 	lui	$at,0x3f80
/*  f0c9468:	46028003 */ 	div.s	$f0,$f16,$f2
/*  f0c946c:	4600903c */ 	c.lt.s	$f18,$f0
/*  f0c9470:	e7a001f8 */ 	swc1	$f0,0x1f8($sp)
/*  f0c9474:	45000007 */ 	bc1f	.L0f0c9494
/*  f0c9478:	00000000 */ 	nop
/*  f0c947c:	44810000 */ 	mtc1	$at,$f0
/*  f0c9480:	10000004 */ 	b	.L0f0c9494
/*  f0c9484:	e7a001f8 */ 	swc1	$f0,0x1f8($sp)
.L0f0c9488:
/*  f0c9488:	44800000 */ 	mtc1	$zero,$f0
/*  f0c948c:	00000000 */ 	nop
/*  f0c9490:	e7a001f8 */ 	swc1	$f0,0x1f8($sp)
.L0f0c9494:
/*  f0c9494:	12e0005c */ 	beqz	$s7,.L0f0c9608
/*  f0c9498:	00000000 */ 	nop
/*  f0c949c:	84a2024c */ 	lh	$v0,0x24c($a1)
/*  f0c94a0:	2841fffe */ 	slti	$at,$v0,-2
/*  f0c94a4:	10200009 */ 	beqz	$at,.L0f0c94cc
/*  f0c94a8:	00565021 */ 	addu	$t2,$v0,$s6
/*  f0c94ac:	a4aa024c */ 	sh	$t2,0x24c($a1)
/*  f0c94b0:	8e450284 */ 	lw	$a1,0x284($s2)
/*  f0c94b4:	84ab024c */ 	lh	$t3,0x24c($a1)
/*  f0c94b8:	2961fffe */ 	slti	$at,$t3,-2
/*  f0c94bc:	14200052 */ 	bnez	$at,.L0f0c9608
/*  f0c94c0:	00000000 */ 	nop
/*  f0c94c4:	10000050 */ 	b	.L0f0c9608
/*  f0c94c8:	a4a0024c */ 	sh	$zero,0x24c($a1)
.L0f0c94cc:
/*  f0c94cc:	1ac0004e */ 	blez	$s6,.L0f0c9608
/*  f0c94d0:	00008025 */ 	or	$s0,$zero,$zero
/*  f0c94d4:	97ac019e */ 	lhu	$t4,0x19e($sp)
/*  f0c94d8:	2413ffff */ 	addiu	$s3,$zero,-1
/*  f0c94dc:	31918000 */ 	andi	$s1,$t4,0x8000
/*  f0c94e0:	00152e00 */ 	sll	$a1,$s5,0x18
.L0f0c94e4:
/*  f0c94e4:	00057603 */ 	sra	$t6,$a1,0x18
/*  f0c94e8:	01c02825 */ 	or	$a1,$t6,$zero
/*  f0c94ec:	02002025 */ 	or	$a0,$s0,$zero
/*  f0c94f0:	0c00529e */ 	jal	joyGetButtonsOnSample
/*  f0c94f4:	3226ffff */ 	andi	$a2,$s1,0xffff
/*  f0c94f8:	14400009 */ 	bnez	$v0,.L0f0c9520
/*  f0c94fc:	02002025 */ 	or	$a0,$s0,$zero
/*  f0c9500:	97b800da */ 	lhu	$t8,0xda($sp)
/*  f0c9504:	00142e00 */ 	sll	$a1,$s4,0x18
/*  f0c9508:	00057e03 */ 	sra	$t7,$a1,0x18
/*  f0c950c:	01e02825 */ 	or	$a1,$t7,$zero
/*  f0c9510:	0c00529e */ 	jal	joyGetButtonsOnSample
/*  f0c9514:	33068000 */ 	andi	$a2,$t8,0x8000
/*  f0c9518:	50400028 */ 	beqzl	$v0,.L0f0c95bc
/*  f0c951c:	8e490284 */ 	lw	$t1,0x284($s2)
.L0f0c9520:
/*  f0c9520:	8e480284 */ 	lw	$t0,0x284($s2)
/*  f0c9524:	97aa00ea */ 	lhu	$t2,0xea($sp)
/*  f0c9528:	8509024c */ 	lh	$t1,0x24c($t0)
/*  f0c952c:	31462000 */ 	andi	$a2,$t2,0x2000
/*  f0c9530:	2921ffff */ 	slti	$at,$t1,-1
/*  f0c9534:	14200031 */ 	bnez	$at,.L0f0c95fc
/*  f0c9538:	02002025 */ 	or	$a0,$s0,$zero
/*  f0c953c:	83a500ef */ 	lb	$a1,0xef($sp)
/*  f0c9540:	0c0052d4 */ 	jal	joyGetButtonsPressedOnSample
/*  f0c9544:	afa6004c */ 	sw	$a2,0x4c($sp)
/*  f0c9548:	10400006 */ 	beqz	$v0,.L0f0c9564
/*  f0c954c:	8fa6004c */ 	lw	$a2,0x4c($sp)
/*  f0c9550:	8fac01fc */ 	lw	$t4,0x1fc($sp)
/*  f0c9554:	8e4e0284 */ 	lw	$t6,0x284($s2)
/*  f0c9558:	258d0001 */ 	addiu	$t5,$t4,0x1
/*  f0c955c:	afad01fc */ 	sw	$t5,0x1fc($sp)
/*  f0c9560:	a5d3024c */ 	sh	$s3,0x24c($t6)
.L0f0c9564:
/*  f0c9564:	8e4f0284 */ 	lw	$t7,0x284($s2)
/*  f0c9568:	02002025 */ 	or	$a0,$s0,$zero
/*  f0c956c:	85f8024c */ 	lh	$t8,0x24c($t7)
/*  f0c9570:	07020023 */ 	bltzl	$t8,.L0f0c9600
/*  f0c9574:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f0c9578:	0c00529e */ 	jal	joyGetButtonsOnSample
/*  f0c957c:	83a500ef */ 	lb	$a1,0xef($sp)
/*  f0c9580:	5440001f */ 	bnezl	$v0,.L0f0c9600
/*  f0c9584:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f0c9588:	8e450284 */ 	lw	$a1,0x284($s2)
/*  f0c958c:	84a2024c */ 	lh	$v0,0x24c($a1)
/*  f0c9590:	28410010 */ 	slti	$at,$v0,0x10
/*  f0c9594:	14200006 */ 	bnez	$at,.L0f0c95b0
/*  f0c9598:	24480001 */ 	addiu	$t0,$v0,0x1
/*  f0c959c:	0fc3fbda */ 	jal	amOpen
/*  f0c95a0:	00000000 */ 	nop
/*  f0c95a4:	8e590284 */ 	lw	$t9,0x284($s2)
/*  f0c95a8:	10000014 */ 	b	.L0f0c95fc
/*  f0c95ac:	a733024c */ 	sh	$s3,0x24c($t9)
.L0f0c95b0:
/*  f0c95b0:	10000012 */ 	b	.L0f0c95fc
/*  f0c95b4:	a4a8024c */ 	sh	$t0,0x24c($a1)
/*  f0c95b8:	8e490284 */ 	lw	$t1,0x284($s2)
.L0f0c95bc:
/*  f0c95bc:	852a024c */ 	lh	$t2,0x24c($t1)
/*  f0c95c0:	5940000d */ 	blezl	$t2,.L0f0c95f8
/*  f0c95c4:	8e4d0284 */ 	lw	$t5,0x284($s2)
/*  f0c95c8:	12e00007 */ 	beqz	$s7,.L0f0c95e8
/*  f0c95cc:	02002025 */ 	or	$a0,$s0,$zero
/*  f0c95d0:	97ab00ea */ 	lhu	$t3,0xea($sp)
/*  f0c95d4:	83a500ef */ 	lb	$a1,0xef($sp)
/*  f0c95d8:	0c00529e */ 	jal	joyGetButtonsOnSample
/*  f0c95dc:	31662000 */ 	andi	$a2,$t3,0x2000
/*  f0c95e0:	54400005 */ 	bnezl	$v0,.L0f0c95f8
/*  f0c95e4:	8e4d0284 */ 	lw	$t5,0x284($s2)
.L0f0c95e8:
/*  f0c95e8:	8fa20200 */ 	lw	$v0,0x200($sp)
/*  f0c95ec:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f0c95f0:	afa20200 */ 	sw	$v0,0x200($sp)
/*  f0c95f4:	8e4d0284 */ 	lw	$t5,0x284($s2)
.L0f0c95f8:
/*  f0c95f8:	a5a0024c */ 	sh	$zero,0x24c($t5)
.L0f0c95fc:
/*  f0c95fc:	26100001 */ 	addiu	$s0,$s0,0x1
.L0f0c9600:
/*  f0c9600:	5616ffb8 */ 	bnel	$s0,$s6,.L0f0c94e4
/*  f0c9604:	00152e00 */ 	sll	$a1,$s5,0x18
.L0f0c9608:
/*  f0c9608:	12e0005e */ 	beqz	$s7,.L0f0c9784
/*  f0c960c:	2413ffff */ 	addiu	$s3,$zero,-1
/*  f0c9610:	1ac0005c */ 	blez	$s6,.L0f0c9784
/*  f0c9614:	00008025 */ 	or	$s0,$zero,$zero
/*  f0c9618:	97ae019e */ 	lhu	$t6,0x19e($sp)
/*  f0c961c:	31cf4000 */ 	andi	$t7,$t6,0x4000
/*  f0c9620:	afaf0044 */ 	sw	$t7,0x44($sp)
/*  f0c9624:	00152e00 */ 	sll	$a1,$s5,0x18
.L0f0c9628:
/*  f0c9628:	0005c603 */ 	sra	$t8,$a1,0x18
/*  f0c962c:	8fa60044 */ 	lw	$a2,0x44($sp)
/*  f0c9630:	03002825 */ 	or	$a1,$t8,$zero
/*  f0c9634:	0c00529e */ 	jal	joyGetButtonsOnSample
/*  f0c9638:	02002025 */ 	or	$a0,$s0,$zero
/*  f0c963c:	14400009 */ 	bnez	$v0,.L0f0c9664
/*  f0c9640:	02002025 */ 	or	$a0,$s0,$zero
/*  f0c9644:	97a800da */ 	lhu	$t0,0xda($sp)
/*  f0c9648:	00142e00 */ 	sll	$a1,$s4,0x18
/*  f0c964c:	0005ce03 */ 	sra	$t9,$a1,0x18
/*  f0c9650:	03202825 */ 	or	$a1,$t9,$zero
/*  f0c9654:	0c00529e */ 	jal	joyGetButtonsOnSample
/*  f0c9658:	31064000 */ 	andi	$a2,$t0,0x4000
/*  f0c965c:	5040003e */ 	beqzl	$v0,.L0f0c9758
/*  f0c9660:	8e450284 */ 	lw	$a1,0x284($s2)
.L0f0c9664:
/*  f0c9664:	8e4a0284 */ 	lw	$t2,0x284($s2)
/*  f0c9668:	97ab00ea */ 	lhu	$t3,0xea($sp)
/*  f0c966c:	83a500ef */ 	lb	$a1,0xef($sp)
/*  f0c9670:	8544024e */ 	lh	$a0,0x24e($t2)
/*  f0c9674:	31662000 */ 	andi	$a2,$t3,0x2000
/*  f0c9678:	2881ffff */ 	slti	$at,$a0,-1
/*  f0c967c:	5420002f */ 	bnezl	$at,.L0f0c973c
/*  f0c9680:	2881fffe */ 	slti	$at,$a0,-2
/*  f0c9684:	0c0052d4 */ 	jal	joyGetButtonsPressedOnSample
/*  f0c9688:	02002025 */ 	or	$a0,$s0,$zero
/*  f0c968c:	5040000e */ 	beqzl	$v0,.L0f0c96c8
/*  f0c9690:	8e450284 */ 	lw	$a1,0x284($s2)
/*  f0c9694:	8e4d0284 */ 	lw	$t5,0x284($s2)
/*  f0c9698:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f0c969c:	85a4024e */ 	lh	$a0,0x24e($t5)
/*  f0c96a0:	04820009 */ 	bltzl	$a0,.L0f0c96c8
/*  f0c96a4:	8e450284 */ 	lw	$a1,0x284($s2)
/*  f0c96a8:	0fc2a257 */ 	jal	bgunConsiderToggleGunFunction
/*  f0c96ac:	00003025 */ 	or	$a2,$zero,$zero
/*  f0c96b0:	50400005 */ 	beqzl	$v0,.L0f0c96c8
/*  f0c96b4:	8e450284 */ 	lw	$a1,0x284($s2)
/*  f0c96b8:	8e4f0284 */ 	lw	$t7,0x284($s2)
/*  f0c96bc:	240efffd */ 	addiu	$t6,$zero,-3
/*  f0c96c0:	a5ee024e */ 	sh	$t6,0x24e($t7)
/*  f0c96c4:	8e450284 */ 	lw	$a1,0x284($s2)
.L0f0c96c8:
/*  f0c96c8:	84a4024e */ 	lh	$a0,0x24e($a1)
/*  f0c96cc:	0480002a */ 	bltz	$a0,.L0f0c9778
/*  f0c96d0:	2881001a */ 	slti	$at,$a0,0x1a
/*  f0c96d4:	14200016 */ 	bnez	$at,.L0f0c9730
/*  f0c96d8:	248b0001 */ 	addiu	$t3,$a0,0x1
/*  f0c96dc:	00002825 */ 	or	$a1,$zero,$zero
/*  f0c96e0:	0fc2a257 */ 	jal	bgunConsiderToggleGunFunction
/*  f0c96e4:	00003025 */ 	or	$a2,$zero,$zero
/*  f0c96e8:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0c96ec:	54410005 */ 	bnel	$v0,$at,.L0f0c9704
/*  f0c96f0:	24010002 */ 	addiu	$at,$zero,0x2
/*  f0c96f4:	8e580284 */ 	lw	$t8,0x284($s2)
/*  f0c96f8:	1000001f */ 	b	.L0f0c9778
/*  f0c96fc:	a713024e */ 	sh	$s3,0x24e($t8)
/*  f0c9700:	24010002 */ 	addiu	$at,$zero,0x2
.L0f0c9704:
/*  f0c9704:	54410006 */ 	bnel	$v0,$at,.L0f0c9720
/*  f0c9708:	8e450284 */ 	lw	$a1,0x284($s2)
/*  f0c970c:	8e480284 */ 	lw	$t0,0x284($s2)
/*  f0c9710:	2419fffe */ 	addiu	$t9,$zero,-2
/*  f0c9714:	10000018 */ 	b	.L0f0c9778
/*  f0c9718:	a519024e */ 	sh	$t9,0x24e($t0)
/*  f0c971c:	8e450284 */ 	lw	$a1,0x284($s2)
.L0f0c9720:
/*  f0c9720:	84a9024e */ 	lh	$t1,0x24e($a1)
/*  f0c9724:	252a0001 */ 	addiu	$t2,$t1,0x1
/*  f0c9728:	10000013 */ 	b	.L0f0c9778
/*  f0c972c:	a4aa024e */ 	sh	$t2,0x24e($a1)
.L0f0c9730:
/*  f0c9730:	10000011 */ 	b	.L0f0c9778
/*  f0c9734:	a4ab024e */ 	sh	$t3,0x24e($a1)
/*  f0c9738:	2881fffe */ 	slti	$at,$a0,-2
.L0f0c973c:
/*  f0c973c:	1420000e */ 	bnez	$at,.L0f0c9778
/*  f0c9740:	00002825 */ 	or	$a1,$zero,$zero
/*  f0c9744:	0fc2a257 */ 	jal	bgunConsiderToggleGunFunction
/*  f0c9748:	00003025 */ 	or	$a2,$zero,$zero
/*  f0c974c:	1000000b */ 	b	.L0f0c977c
/*  f0c9750:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f0c9754:	8e450284 */ 	lw	$a1,0x284($s2)
.L0f0c9758:
/*  f0c9758:	8fad01c0 */ 	lw	$t5,0x1c0($sp)
/*  f0c975c:	84ac024e */ 	lh	$t4,0x24e($a1)
/*  f0c9760:	25ae0001 */ 	addiu	$t6,$t5,0x1
/*  f0c9764:	19800002 */ 	blez	$t4,.L0f0c9770
/*  f0c9768:	00000000 */ 	nop
/*  f0c976c:	afae01c0 */ 	sw	$t6,0x1c0($sp)
.L0f0c9770:
/*  f0c9770:	0fc2a314 */ 	jal	bgun0f0a8c50
/*  f0c9774:	a4a0024e */ 	sh	$zero,0x24e($a1)
.L0f0c9778:
/*  f0c9778:	26100001 */ 	addiu	$s0,$s0,0x1
.L0f0c977c:
/*  f0c977c:	5616ffaa */ 	bnel	$s0,$s6,.L0f0c9628
/*  f0c9780:	00152e00 */ 	sll	$a1,$s5,0x18
.L0f0c9784:
/*  f0c9784:	8faf01a8 */ 	lw	$t7,0x1a8($sp)
/*  f0c9788:	11e0002b */ 	beqz	$t7,.L0f0c9838
/*  f0c978c:	00000000 */ 	nop
/*  f0c9790:	8e580284 */ 	lw	$t8,0x284($s2)
/*  f0c9794:	8fa800dc */ 	lw	$t0,0xdc($sp)
/*  f0c9798:	8f190120 */ 	lw	$t9,0x120($t8)
/*  f0c979c:	13200026 */ 	beqz	$t9,.L0f0c9838
/*  f0c97a0:	00000000 */ 	nop
/*  f0c97a4:	05010011 */ 	bgez	$t0,.L0f0c97ec
/*  f0c97a8:	00084823 */ 	negu	$t1,$t0
/*  f0c97ac:	44892000 */ 	mtc1	$t1,$f4
/*  f0c97b0:	3c01428c */ 	lui	$at,0x428c
/*  f0c97b4:	44814000 */ 	mtc1	$at,$f8
/*  f0c97b8:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f0c97bc:	3c013f80 */ 	lui	$at,0x3f80
/*  f0c97c0:	44815000 */ 	mtc1	$at,$f10
/*  f0c97c4:	3c013f80 */ 	lui	$at,0x3f80
/*  f0c97c8:	46083303 */ 	div.s	$f12,$f6,$f8
/*  f0c97cc:	460c503c */ 	c.lt.s	$f10,$f12
/*  f0c97d0:	00000000 */ 	nop
/*  f0c97d4:	45020004 */ 	bc1fl	.L0f0c97e8
/*  f0c97d8:	460c6300 */ 	add.s	$f12,$f12,$f12
/*  f0c97dc:	44816000 */ 	mtc1	$at,$f12
/*  f0c97e0:	00000000 */ 	nop
/*  f0c97e4:	460c6300 */ 	add.s	$f12,$f12,$f12
.L0f0c97e8:
/*  f0c97e8:	e7ac0210 */ 	swc1	$f12,0x210($sp)
.L0f0c97ec:
/*  f0c97ec:	8faa00dc */ 	lw	$t2,0xdc($sp)
/*  f0c97f0:	19400011 */ 	blez	$t2,.L0f0c9838
/*  f0c97f4:	00000000 */ 	nop
/*  f0c97f8:	448a8000 */ 	mtc1	$t2,$f16
/*  f0c97fc:	3c01428c */ 	lui	$at,0x428c
/*  f0c9800:	44812000 */ 	mtc1	$at,$f4
/*  f0c9804:	468084a0 */ 	cvt.s.w	$f18,$f16
/*  f0c9808:	3c013f80 */ 	lui	$at,0x3f80
/*  f0c980c:	44813000 */ 	mtc1	$at,$f6
/*  f0c9810:	3c013f80 */ 	lui	$at,0x3f80
/*  f0c9814:	46049303 */ 	div.s	$f12,$f18,$f4
/*  f0c9818:	460c303c */ 	c.lt.s	$f6,$f12
/*  f0c981c:	00000000 */ 	nop
/*  f0c9820:	45020004 */ 	bc1fl	.L0f0c9834
/*  f0c9824:	460c6300 */ 	add.s	$f12,$f12,$f12
/*  f0c9828:	44816000 */ 	mtc1	$at,$f12
/*  f0c982c:	00000000 */ 	nop
/*  f0c9830:	460c6300 */ 	add.s	$f12,$f12,$f12
.L0f0c9834:
/*  f0c9834:	e7ac0214 */ 	swc1	$f12,0x214($sp)
.L0f0c9838:
/*  f0c9838:	12e0005a */ 	beqz	$s7,.L0f0c99a4
/*  f0c983c:	00000000 */ 	nop
/*  f0c9840:	1ac00058 */ 	blez	$s6,.L0f0c99a4
/*  f0c9844:	00008025 */ 	or	$s0,$zero,$zero
/*  f0c9848:	8fab01a8 */ 	lw	$t3,0x1a8($sp)
.L0f0c984c:
/*  f0c984c:	00106080 */ 	sll	$t4,$s0,0x2
/*  f0c9850:	03ac6821 */ 	addu	$t5,$sp,$t4
/*  f0c9854:	55600034 */ 	bnezl	$t3,.L0f0c9928
/*  f0c9858:	8e4a0288 */ 	lw	$t2,0x288($s2)
/*  f0c985c:	8dad014c */ 	lw	$t5,0x14c($t5)
/*  f0c9860:	00142e00 */ 	sll	$a1,$s4,0x18
/*  f0c9864:	00057603 */ 	sra	$t6,$a1,0x18
/*  f0c9868:	11a0002e */ 	beqz	$t5,.L0f0c9924
/*  f0c986c:	02002025 */ 	or	$a0,$s0,$zero
/*  f0c9870:	0c005241 */ 	jal	joyGetStickYOnSample
/*  f0c9874:	01c02825 */ 	or	$a1,$t6,$zero
/*  f0c9878:	2841001f */ 	slti	$at,$v0,0x1f
/*  f0c987c:	14200011 */ 	bnez	$at,.L0f0c98c4
/*  f0c9880:	02002025 */ 	or	$a0,$s0,$zero
/*  f0c9884:	00142e00 */ 	sll	$a1,$s4,0x18
/*  f0c9888:	00057e03 */ 	sra	$t7,$a1,0x18
/*  f0c988c:	0c005270 */ 	jal	joyGetStickYOnSampleIndex
/*  f0c9890:	01e02825 */ 	or	$a1,$t7,$zero
/*  f0c9894:	2841001f */ 	slti	$at,$v0,0x1f
/*  f0c9898:	1020000a */ 	beqz	$at,.L0f0c98c4
/*  f0c989c:	8fa20218 */ 	lw	$v0,0x218($sp)
/*  f0c98a0:	10400003 */ 	beqz	$v0,.L0f0c98b0
/*  f0c98a4:	2442ffff */ 	addiu	$v0,$v0,-1
/*  f0c98a8:	10000004 */ 	b	.L0f0c98bc
/*  f0c98ac:	afa20218 */ 	sw	$v0,0x218($sp)
.L0f0c98b0:
/*  f0c98b0:	8fa2021c */ 	lw	$v0,0x21c($sp)
/*  f0c98b4:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f0c98b8:	afa2021c */ 	sw	$v0,0x21c($sp)
.L0f0c98bc:
/*  f0c98bc:	8e580284 */ 	lw	$t8,0x284($s2)
/*  f0c98c0:	af130260 */ 	sw	$s3,0x260($t8)
.L0f0c98c4:
/*  f0c98c4:	00142e00 */ 	sll	$a1,$s4,0x18
/*  f0c98c8:	0005ce03 */ 	sra	$t9,$a1,0x18
/*  f0c98cc:	03202825 */ 	or	$a1,$t9,$zero
/*  f0c98d0:	0c005241 */ 	jal	joyGetStickYOnSample
/*  f0c98d4:	02002025 */ 	or	$a0,$s0,$zero
/*  f0c98d8:	2841ffe2 */ 	slti	$at,$v0,-30
/*  f0c98dc:	10200011 */ 	beqz	$at,.L0f0c9924
/*  f0c98e0:	02002025 */ 	or	$a0,$s0,$zero
/*  f0c98e4:	00142e00 */ 	sll	$a1,$s4,0x18
/*  f0c98e8:	00054603 */ 	sra	$t0,$a1,0x18
/*  f0c98ec:	0c005270 */ 	jal	joyGetStickYOnSampleIndex
/*  f0c98f0:	01002825 */ 	or	$a1,$t0,$zero
/*  f0c98f4:	2841ffe2 */ 	slti	$at,$v0,-30
/*  f0c98f8:	1420000a */ 	bnez	$at,.L0f0c9924
/*  f0c98fc:	8fa2021c */ 	lw	$v0,0x21c($sp)
/*  f0c9900:	10400003 */ 	beqz	$v0,.L0f0c9910
/*  f0c9904:	2442ffff */ 	addiu	$v0,$v0,-1
/*  f0c9908:	10000004 */ 	b	.L0f0c991c
/*  f0c990c:	afa2021c */ 	sw	$v0,0x21c($sp)
.L0f0c9910:
/*  f0c9910:	8fa20218 */ 	lw	$v0,0x218($sp)
/*  f0c9914:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f0c9918:	afa20218 */ 	sw	$v0,0x218($sp)
.L0f0c991c:
/*  f0c991c:	8e490284 */ 	lw	$t1,0x284($s2)
/*  f0c9920:	ad330260 */ 	sw	$s3,0x260($t1)
.L0f0c9924:
/*  f0c9924:	8e4a0288 */ 	lw	$t2,0x288($s2)
.L0f0c9928:
/*  f0c9928:	0fc549fb */ 	jal	optionsGetAimControl
/*  f0c992c:	8d440070 */ 	lw	$a0,0x70($t2)
/*  f0c9930:	14400019 */ 	bnez	$v0,.L0f0c9998
/*  f0c9934:	00105880 */ 	sll	$t3,$s0,0x2
/*  f0c9938:	03ab6021 */ 	addu	$t4,$sp,$t3
/*  f0c993c:	8d8c014c */ 	lw	$t4,0x14c($t4)
/*  f0c9940:	51800008 */ 	beqzl	$t4,.L0f0c9964
/*  f0c9944:	8e450284 */ 	lw	$a1,0x284($s2)
/*  f0c9948:	8e450284 */ 	lw	$a1,0x284($s2)
/*  f0c994c:	8ca20260 */ 	lw	$v0,0x260($a1)
/*  f0c9950:	04400011 */ 	bltz	$v0,.L0f0c9998
/*  f0c9954:	244d0001 */ 	addiu	$t5,$v0,0x1
/*  f0c9958:	1000000f */ 	b	.L0f0c9998
/*  f0c995c:	acad0260 */ 	sw	$t5,0x260($a1)
/*  f0c9960:	8e450284 */ 	lw	$a1,0x284($s2)
.L0f0c9964:
/*  f0c9964:	8ca20260 */ 	lw	$v0,0x260($a1)
/*  f0c9968:	1840000a */ 	blez	$v0,.L0f0c9994
/*  f0c996c:	2841000f */ 	slti	$at,$v0,0xf
/*  f0c9970:	10200008 */ 	beqz	$at,.L0f0c9994
/*  f0c9974:	8fa20218 */ 	lw	$v0,0x218($sp)
/*  f0c9978:	10400003 */ 	beqz	$v0,.L0f0c9988
/*  f0c997c:	2442ffff */ 	addiu	$v0,$v0,-1
/*  f0c9980:	10000004 */ 	b	.L0f0c9994
/*  f0c9984:	afa20218 */ 	sw	$v0,0x218($sp)
.L0f0c9988:
/*  f0c9988:	8fa2021c */ 	lw	$v0,0x21c($sp)
/*  f0c998c:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f0c9990:	afa2021c */ 	sw	$v0,0x21c($sp)
.L0f0c9994:
/*  f0c9994:	aca00260 */ 	sw	$zero,0x260($a1)
.L0f0c9998:
/*  f0c9998:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f0c999c:	5616ffab */ 	bnel	$s0,$s6,.L0f0c984c
/*  f0c99a0:	8fab01a8 */ 	lw	$t3,0x1a8($sp)
.L0f0c99a4:
/*  f0c99a4:	0fc331a0 */ 	jal	bmoveGetCrouchPos
/*  f0c99a8:	00000000 */ 	nop
/*  f0c99ac:	1440001d */ 	bnez	$v0,.L0f0c9a24
/*  f0c99b0:	00000000 */ 	nop
/*  f0c99b4:	8e450284 */ 	lw	$a1,0x284($s2)
/*  f0c99b8:	3c01c2b4 */ 	lui	$at,0xc2b4
/*  f0c99bc:	44814000 */ 	mtc1	$at,$f8
/*  f0c99c0:	c4aa00b4 */ 	lwc1	$f10,0xb4($a1)
/*  f0c99c4:	460a4032 */ 	c.eq.s	$f8,$f10
/*  f0c99c8:	00000000 */ 	nop
/*  f0c99cc:	45000015 */ 	bc1f	.L0f0c9a24
/*  f0c99d0:	00000000 */ 	nop
/*  f0c99d4:	8e4e0314 */ 	lw	$t6,0x314($s2)
/*  f0c99d8:	11c00012 */ 	beqz	$t6,.L0f0c9a24
/*  f0c99dc:	00000000 */ 	nop
/*  f0c99e0:	8e4f0298 */ 	lw	$t7,0x298($s2)
/*  f0c99e4:	05e1000f */ 	bgez	$t7,.L0f0c9a24
/*  f0c99e8:	00000000 */ 	nop
/*  f0c99ec:	8ca40120 */ 	lw	$a0,0x120($a1)
/*  f0c99f0:	8fa201a8 */ 	lw	$v0,0x1a8($sp)
/*  f0c99f4:	0004c02b */ 	sltu	$t8,$zero,$a0
/*  f0c99f8:	13000009 */ 	beqz	$t8,.L0f0c9a20
/*  f0c99fc:	03002025 */ 	or	$a0,$t8,$zero
/*  f0c9a00:	2c440001 */ 	sltiu	$a0,$v0,0x1
/*  f0c9a04:	50800007 */ 	beqzl	$a0,.L0f0c9a24
/*  f0c9a08:	afa40234 */ 	sw	$a0,0x234($sp)
/*  f0c9a0c:	00142600 */ 	sll	$a0,$s4,0x18
/*  f0c9a10:	00044603 */ 	sra	$t0,$a0,0x18
/*  f0c9a14:	0c0053ae */ 	jal	joyGetStickY
/*  f0c9a18:	01002025 */ 	or	$a0,$t0,$zero
/*  f0c9a1c:	2844ffe2 */ 	slti	$a0,$v0,-30
.L0f0c9a20:
/*  f0c9a20:	afa40234 */ 	sw	$a0,0x234($sp)
.L0f0c9a24:
/*  f0c9a24:	0fc2866a */ 	jal	bgunGetWeaponNum
/*  f0c9a28:	00002025 */ 	or	$a0,$zero,$zero
/*  f0c9a2c:	24010016 */ 	addiu	$at,$zero,0x16
/*  f0c9a30:	54410011 */ 	bnel	$v0,$at,.L0f0c9a78
/*  f0c9a34:	97a201a2 */ 	lhu	$v0,0x1a2($sp)
/*  f0c9a38:	8e450284 */ 	lw	$a1,0x284($s2)
/*  f0c9a3c:	8ca20120 */ 	lw	$v0,0x120($a1)
/*  f0c9a40:	50400004 */ 	beqzl	$v0,.L0f0c9a54
/*  f0c9a44:	0002202b */ 	sltu	$a0,$zero,$v0
/*  f0c9a48:	afa001c8 */ 	sw	$zero,0x1c8($sp)
/*  f0c9a4c:	8ca20120 */ 	lw	$v0,0x120($a1)
/*  f0c9a50:	0002202b */ 	sltu	$a0,$zero,$v0
.L0f0c9a54:
/*  f0c9a54:	10800006 */ 	beqz	$a0,.L0f0c9a70
/*  f0c9a58:	83a900e9 */ 	lb	$t1,0xe9($sp)
/*  f0c9a5c:	2924ffe2 */ 	slti	$a0,$t1,-30
/*  f0c9a60:	54800004 */ 	bnezl	$a0,.L0f0c9a74
/*  f0c9a64:	afa40230 */ 	sw	$a0,0x230($sp)
/*  f0c9a68:	2924001f */ 	slti	$a0,$t1,0x1f
/*  f0c9a6c:	38840001 */ 	xori	$a0,$a0,0x1
.L0f0c9a70:
/*  f0c9a70:	afa40230 */ 	sw	$a0,0x230($sp)
.L0f0c9a74:
/*  f0c9a74:	97a201a2 */ 	lhu	$v0,0x1a2($sp)
.L0f0c9a78:
/*  f0c9a78:	afa00220 */ 	sw	$zero,0x220($sp)
/*  f0c9a7c:	afa00224 */ 	sw	$zero,0x224($sp)
/*  f0c9a80:	304a8000 */ 	andi	$t2,$v0,0x8000
/*  f0c9a84:	11400003 */ 	beqz	$t2,.L0f0c9a94
/*  f0c9a88:	97ab01a0 */ 	lhu	$t3,0x1a0($sp)
/*  f0c9a8c:	316c4000 */ 	andi	$t4,$t3,0x4000
/*  f0c9a90:	15800012 */ 	bnez	$t4,.L0f0c9adc
.L0f0c9a94:
/*  f0c9a94:	304d4000 */ 	andi	$t5,$v0,0x4000
/*  f0c9a98:	11a00004 */ 	beqz	$t5,.L0f0c9aac
/*  f0c9a9c:	97ae01a0 */ 	lhu	$t6,0x1a0($sp)
/*  f0c9aa0:	31cf8000 */ 	andi	$t7,$t6,0x8000
/*  f0c9aa4:	55e0000e */ 	bnezl	$t7,.L0f0c9ae0
/*  f0c9aa8:	8fac01ac */ 	lw	$t4,0x1ac($sp)
.L0f0c9aac:
/*  f0c9aac:	97a200e6 */ 	lhu	$v0,0xe6($sp)
/*  f0c9ab0:	97b900e4 */ 	lhu	$t9,0xe4($sp)
/*  f0c9ab4:	30588000 */ 	andi	$t8,$v0,0x8000
/*  f0c9ab8:	13000002 */ 	beqz	$t8,.L0f0c9ac4
/*  f0c9abc:	33284000 */ 	andi	$t0,$t9,0x4000
/*  f0c9ac0:	15000006 */ 	bnez	$t0,.L0f0c9adc
.L0f0c9ac4:
/*  f0c9ac4:	30494000 */ 	andi	$t1,$v0,0x4000
/*  f0c9ac8:	11200011 */ 	beqz	$t1,.L0f0c9b10
/*  f0c9acc:	97aa00e4 */ 	lhu	$t2,0xe4($sp)
/*  f0c9ad0:	314b8000 */ 	andi	$t3,$t2,0x8000
/*  f0c9ad4:	5160000f */ 	beqzl	$t3,.L0f0c9b14
/*  f0c9ad8:	8e450284 */ 	lw	$a1,0x284($s2)
.L0f0c9adc:
/*  f0c9adc:	8fac01ac */ 	lw	$t4,0x1ac($sp)
.L0f0c9ae0:
/*  f0c9ae0:	24010022 */ 	addiu	$at,$zero,0x22
/*  f0c9ae4:	2402fffe */ 	addiu	$v0,$zero,-2
/*  f0c9ae8:	15810009 */ 	bne	$t4,$at,.L0f0c9b10
/*  f0c9aec:	240d0001 */ 	addiu	$t5,$zero,0x1
/*  f0c9af0:	8e4e0284 */ 	lw	$t6,0x284($s2)
/*  f0c9af4:	afad0228 */ 	sw	$t5,0x228($sp)
/*  f0c9af8:	afa001fc */ 	sw	$zero,0x1fc($sp)
/*  f0c9afc:	afa00200 */ 	sw	$zero,0x200($sp)
/*  f0c9b00:	afa001c0 */ 	sw	$zero,0x1c0($sp)
/*  f0c9b04:	a5c2024c */ 	sh	$v0,0x24c($t6)
/*  f0c9b08:	8e4f0284 */ 	lw	$t7,0x284($s2)
/*  f0c9b0c:	a5e2024e */ 	sh	$v0,0x24e($t7)
.L0f0c9b10:
/*  f0c9b10:	8e450284 */ 	lw	$a1,0x284($s2)
.L0f0c9b14:
/*  f0c9b14:	97a900ea */ 	lhu	$t1,0xea($sp)
/*  f0c9b18:	8cb80120 */ 	lw	$t8,0x120($a1)
/*  f0c9b1c:	afb80208 */ 	sw	$t8,0x208($sp)
/*  f0c9b20:	8cb90120 */ 	lw	$t9,0x120($a1)
/*  f0c9b24:	afb9020c */ 	sw	$t9,0x20c($sp)
/*  f0c9b28:	8ca80274 */ 	lw	$t0,0x274($a1)
/*  f0c9b2c:	31252000 */ 	andi	$a1,$t1,0x2000
/*  f0c9b30:	11000007 */ 	beqz	$t0,.L0f0c9b50
/*  f0c9b34:	00000000 */ 	nop
/*  f0c9b38:	0c0053d8 */ 	jal	joyGetButtons
/*  f0c9b3c:	83a400ef */ 	lb	$a0,0xef($sp)
/*  f0c9b40:	14400003 */ 	bnez	$v0,.L0f0c9b50
/*  f0c9b44:	00000000 */ 	nop
/*  f0c9b48:	8e4b0284 */ 	lw	$t3,0x284($s2)
/*  f0c9b4c:	ad600274 */ 	sw	$zero,0x274($t3)
.L0f0c9b50:
/*  f0c9b50:	0fc2866a */ 	jal	bgunGetWeaponNum
/*  f0c9b54:	00002025 */ 	or	$a0,$zero,$zero
/*  f0c9b58:	00402025 */ 	or	$a0,$v0,$zero
/*  f0c9b5c:	0fc2c5f0 */ 	jal	weaponHasFlag
/*  f0c9b60:	3c058000 */ 	lui	$a1,0x8000
/*  f0c9b64:	50400012 */ 	beqzl	$v0,.L0f0c9bb0
/*  f0c9b68:	8e480284 */ 	lw	$t0,0x284($s2)
/*  f0c9b6c:	12e0000d */ 	beqz	$s7,.L0f0c9ba4
/*  f0c9b70:	97ac00ea */ 	lhu	$t4,0xea($sp)
/*  f0c9b74:	83a400ef */ 	lb	$a0,0xef($sp)
/*  f0c9b78:	0c005408 */ 	jal	joyGetButtonsPressedThisFrame
/*  f0c9b7c:	31852000 */ 	andi	$a1,$t4,0x2000
/*  f0c9b80:	10400008 */ 	beqz	$v0,.L0f0c9ba4
/*  f0c9b84:	00000000 */ 	nop
/*  f0c9b88:	8e4e0284 */ 	lw	$t6,0x284($s2)
/*  f0c9b8c:	8fb801c0 */ 	lw	$t8,0x1c0($sp)
/*  f0c9b90:	8dcf1a24 */ 	lw	$t7,0x1a24($t6)
/*  f0c9b94:	27190001 */ 	addiu	$t9,$t8,0x1
/*  f0c9b98:	15e00002 */ 	bnez	$t7,.L0f0c9ba4
/*  f0c9b9c:	00000000 */ 	nop
/*  f0c9ba0:	afb901c0 */ 	sw	$t9,0x1c0($sp)
.L0f0c9ba4:
/*  f0c9ba4:	1000001e */ 	b	.L0f0c9c20
/*  f0c9ba8:	8e450284 */ 	lw	$a1,0x284($s2)
/*  f0c9bac:	8e480284 */ 	lw	$t0,0x284($s2)
.L0f0c9bb0:
/*  f0c9bb0:	8d040274 */ 	lw	$a0,0x274($t0)
/*  f0c9bb4:	2c890001 */ 	sltiu	$t1,$a0,0x1
/*  f0c9bb8:	11200017 */ 	beqz	$t1,.L0f0c9c18
/*  f0c9bbc:	01202025 */ 	or	$a0,$t1,$zero
/*  f0c9bc0:	12e00015 */ 	beqz	$s7,.L0f0c9c18
/*  f0c9bc4:	02e02025 */ 	or	$a0,$s7,$zero
/*  f0c9bc8:	97aa00ea */ 	lhu	$t2,0xea($sp)
/*  f0c9bcc:	83a400ef */ 	lb	$a0,0xef($sp)
/*  f0c9bd0:	0c0053d8 */ 	jal	joyGetButtons
/*  f0c9bd4:	31452000 */ 	andi	$a1,$t2,0x2000
/*  f0c9bd8:	0002202b */ 	sltu	$a0,$zero,$v0
/*  f0c9bdc:	5080000f */ 	beqzl	$a0,.L0f0c9c1c
/*  f0c9be0:	afa401bc */ 	sw	$a0,0x1bc($sp)
/*  f0c9be4:	8e4c0284 */ 	lw	$t4,0x284($s2)
/*  f0c9be8:	97a201a2 */ 	lhu	$v0,0x1a2($sp)
/*  f0c9bec:	8d841a24 */ 	lw	$a0,0x1a24($t4)
/*  f0c9bf0:	304e8000 */ 	andi	$t6,$v0,0x8000
/*  f0c9bf4:	2c8d0001 */ 	sltiu	$t5,$a0,0x1
/*  f0c9bf8:	11a00007 */ 	beqz	$t5,.L0f0c9c18
/*  f0c9bfc:	01a02025 */ 	or	$a0,$t5,$zero
/*  f0c9c00:	2dc40001 */ 	sltiu	$a0,$t6,0x1
/*  f0c9c04:	50800005 */ 	beqzl	$a0,.L0f0c9c1c
/*  f0c9c08:	afa401bc */ 	sw	$a0,0x1bc($sp)
/*  f0c9c0c:	97a400e6 */ 	lhu	$a0,0xe6($sp)
/*  f0c9c10:	30988000 */ 	andi	$t8,$a0,0x8000
/*  f0c9c14:	2f040001 */ 	sltiu	$a0,$t8,0x1
.L0f0c9c18:
/*  f0c9c18:	afa401bc */ 	sw	$a0,0x1bc($sp)
.L0f0c9c1c:
/*  f0c9c1c:	8e450284 */ 	lw	$a1,0x284($s2)
.L0f0c9c20:
/*  f0c9c20:	24080001 */ 	addiu	$t0,$zero,0x1
/*  f0c9c24:	1000032a */ 	b	.L0f0ca8d0
/*  f0c9c28:	afa8023c */ 	sw	$t0,0x23c($sp)
/*  f0c9c2c:	24010002 */ 	addiu	$at,$zero,0x2
.L0f0c9c30:
/*  f0c9c30:	10410004 */ 	beq	$v0,$at,.L0f0c9c44
/*  f0c9c34:	34148000 */ 	dli	$s4,0x8000
/*  f0c9c38:	24010003 */ 	addiu	$at,$zero,0x3
/*  f0c9c3c:	14410005 */ 	bne	$v0,$at,.L0f0c9c54
/*  f0c9c40:	24110030 */ 	addiu	$s1,$zero,0x30
.L0f0c9c44:
/*  f0c9c44:	24090030 */ 	addiu	$t1,$zero,0x30
/*  f0c9c48:	24112000 */ 	addiu	$s1,$zero,0x2000
/*  f0c9c4c:	10000004 */ 	b	.L0f0c9c60
/*  f0c9c50:	a7a900ca */ 	sh	$t1,0xca($sp)
.L0f0c9c54:
/*  f0c9c54:	340a8000 */ 	dli	$t2,0x8000
/*  f0c9c58:	24142000 */ 	addiu	$s4,$zero,0x2000
/*  f0c9c5c:	a7aa00ca */ 	sh	$t2,0xca($sp)
.L0f0c9c60:
/*  f0c9c60:	8e4b0288 */ 	lw	$t3,0x288($s2)
/*  f0c9c64:	0fc549fb */ 	jal	optionsGetAimControl
/*  f0c9c68:	8d640070 */ 	lw	$a0,0x70($t3)
/*  f0c9c6c:	14400021 */ 	bnez	$v0,.L0f0c9cf4
/*  f0c9c70:	00000000 */ 	nop
/*  f0c9c74:	1ac0001a */ 	blez	$s6,.L0f0c9ce0
/*  f0c9c78:	00008025 */ 	or	$s0,$zero,$zero
/*  f0c9c7c:	27a3014c */ 	addiu	$v1,$sp,0x14c
/*  f0c9c80:	27a700fc */ 	addiu	$a3,$sp,0xfc
.L0f0c9c84:
/*  f0c9c84:	12e0000f */ 	beqz	$s7,.L0f0c9cc4
/*  f0c9c88:	02e02025 */ 	or	$a0,$s7,$zero
/*  f0c9c8c:	97ad019e */ 	lhu	$t5,0x19e($sp)
/*  f0c9c90:	00152e00 */ 	sll	$a1,$s5,0x18
/*  f0c9c94:	00056603 */ 	sra	$t4,$a1,0x18
/*  f0c9c98:	022d3024 */ 	and	$a2,$s1,$t5
/*  f0c9c9c:	30ceffff */ 	andi	$t6,$a2,0xffff
/*  f0c9ca0:	01c03025 */ 	or	$a2,$t6,$zero
/*  f0c9ca4:	01802825 */ 	or	$a1,$t4,$zero
/*  f0c9ca8:	02002025 */ 	or	$a0,$s0,$zero
/*  f0c9cac:	afa3004c */ 	sw	$v1,0x4c($sp)
/*  f0c9cb0:	0c00529e */ 	jal	joyGetButtonsOnSample
/*  f0c9cb4:	afa70048 */ 	sw	$a3,0x48($sp)
/*  f0c9cb8:	8fa3004c */ 	lw	$v1,0x4c($sp)
/*  f0c9cbc:	8fa70048 */ 	lw	$a3,0x48($sp)
/*  f0c9cc0:	0002202b */ 	sltu	$a0,$zero,$v0
.L0f0c9cc4:
/*  f0c9cc4:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f0c9cc8:	2c8f0001 */ 	sltiu	$t7,$a0,0x1
/*  f0c9ccc:	24630004 */ 	addiu	$v1,$v1,0x4
/*  f0c9cd0:	24e70004 */ 	addiu	$a3,$a3,0x4
/*  f0c9cd4:	ac64fffc */ 	sw	$a0,-0x4($v1)
/*  f0c9cd8:	1616ffea */ 	bne	$s0,$s6,.L0f0c9c84
/*  f0c9cdc:	aceffffc */ 	sw	$t7,-0x4($a3)
.L0f0c9ce0:
/*  f0c9ce0:	0016c080 */ 	sll	$t8,$s6,0x2
/*  f0c9ce4:	03b8c821 */ 	addu	$t9,$sp,$t8
/*  f0c9ce8:	8f390148 */ 	lw	$t9,0x148($t9)
/*  f0c9cec:	8e480284 */ 	lw	$t0,0x284($s2)
/*  f0c9cf0:	ad190120 */ 	sw	$t9,0x120($t0)
.L0f0c9cf4:
/*  f0c9cf4:	0fc5b364 */ 	jal	lvIsPaused
/*  f0c9cf8:	00000000 */ 	nop
/*  f0c9cfc:	544002ba */ 	bnezl	$v0,.L0f0ca7e8
/*  f0c9d00:	8e450284 */ 	lw	$a1,0x284($s2)
/*  f0c9d04:	8e490288 */ 	lw	$t1,0x288($s2)
/*  f0c9d08:	0fc549fb */ 	jal	optionsGetAimControl
/*  f0c9d0c:	8d240070 */ 	lw	$a0,0x70($t1)
/*  f0c9d10:	10400021 */ 	beqz	$v0,.L0f0c9d98
/*  f0c9d14:	00000000 */ 	nop
/*  f0c9d18:	1ac0001f */ 	blez	$s6,.L0f0c9d98
/*  f0c9d1c:	00008025 */ 	or	$s0,$zero,$zero
/*  f0c9d20:	27a3014c */ 	addiu	$v1,$sp,0x14c
/*  f0c9d24:	27a700fc */ 	addiu	$a3,$sp,0xfc
.L0f0c9d28:
/*  f0c9d28:	12e00012 */ 	beqz	$s7,.L0f0c9d74
/*  f0c9d2c:	02002025 */ 	or	$a0,$s0,$zero
/*  f0c9d30:	97ab019e */ 	lhu	$t3,0x19e($sp)
/*  f0c9d34:	00152e00 */ 	sll	$a1,$s5,0x18
/*  f0c9d38:	00055603 */ 	sra	$t2,$a1,0x18
/*  f0c9d3c:	022b3024 */ 	and	$a2,$s1,$t3
/*  f0c9d40:	30ccffff */ 	andi	$t4,$a2,0xffff
/*  f0c9d44:	01803025 */ 	or	$a2,$t4,$zero
/*  f0c9d48:	01402825 */ 	or	$a1,$t2,$zero
/*  f0c9d4c:	afa3004c */ 	sw	$v1,0x4c($sp)
/*  f0c9d50:	0c0052d4 */ 	jal	joyGetButtonsPressedOnSample
/*  f0c9d54:	afa70048 */ 	sw	$a3,0x48($sp)
/*  f0c9d58:	8fa3004c */ 	lw	$v1,0x4c($sp)
/*  f0c9d5c:	10400005 */ 	beqz	$v0,.L0f0c9d74
/*  f0c9d60:	8fa70048 */ 	lw	$a3,0x48($sp)
/*  f0c9d64:	8e450284 */ 	lw	$a1,0x284($s2)
/*  f0c9d68:	8ca40120 */ 	lw	$a0,0x120($a1)
/*  f0c9d6c:	2c8d0001 */ 	sltiu	$t5,$a0,0x1
/*  f0c9d70:	acad0120 */ 	sw	$t5,0x120($a1)
.L0f0c9d74:
/*  f0c9d74:	8e4e0284 */ 	lw	$t6,0x284($s2)
/*  f0c9d78:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f0c9d7c:	24630004 */ 	addiu	$v1,$v1,0x4
/*  f0c9d80:	8dcf0120 */ 	lw	$t7,0x120($t6)
/*  f0c9d84:	24e70004 */ 	addiu	$a3,$a3,0x4
/*  f0c9d88:	2df80001 */ 	sltiu	$t8,$t7,0x1
/*  f0c9d8c:	acf8fffc */ 	sw	$t8,-0x4($a3)
/*  f0c9d90:	1616ffe5 */ 	bne	$s0,$s6,.L0f0c9d28
/*  f0c9d94:	ac6ffffc */ 	sw	$t7,-0x4($v1)
.L0f0c9d98:
/*  f0c9d98:	0fc2866a */ 	jal	bgunGetWeaponNum
/*  f0c9d9c:	00002025 */ 	or	$a0,$zero,$zero
/*  f0c9da0:	24010032 */ 	addiu	$at,$zero,0x32
/*  f0c9da4:	54410005 */ 	bnel	$v0,$at,.L0f0c9dbc
/*  f0c9da8:	8e450284 */ 	lw	$a1,0x284($s2)
/*  f0c9dac:	8e480284 */ 	lw	$t0,0x284($s2)
/*  f0c9db0:	24190001 */ 	addiu	$t9,$zero,0x1
/*  f0c9db4:	ad190120 */ 	sw	$t9,0x120($t0)
/*  f0c9db8:	8e450284 */ 	lw	$a1,0x284($s2)
.L0f0c9dbc:
/*  f0c9dbc:	8fac01b0 */ 	lw	$t4,0x1b0($sp)
/*  f0c9dc0:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0c9dc4:	8ca40120 */ 	lw	$a0,0x120($a1)
/*  f0c9dc8:	2c890001 */ 	sltiu	$t1,$a0,0x1
/*  f0c9dcc:	afa901b4 */ 	sw	$t1,0x1b4($sp)
/*  f0c9dd0:	8caa0120 */ 	lw	$t2,0x120($a1)
/*  f0c9dd4:	afaa01b8 */ 	sw	$t2,0x1b8($sp)
/*  f0c9dd8:	8ca40120 */ 	lw	$a0,0x120($a1)
/*  f0c9ddc:	2c8b0001 */ 	sltiu	$t3,$a0,0x1
/*  f0c9de0:	11810004 */ 	beq	$t4,$at,.L0f0c9df4
/*  f0c9de4:	afab022c */ 	sw	$t3,0x22c($sp)
/*  f0c9de8:	24010003 */ 	addiu	$at,$zero,0x3
/*  f0c9dec:	15810054 */ 	bne	$t4,$at,.L0f0c9f40
/*  f0c9df0:	97af01a2 */ 	lhu	$t7,0x1a2($sp)
.L0f0c9df4:
/*  f0c9df4:	8cad0120 */ 	lw	$t5,0x120($a1)
/*  f0c9df8:	97a201a2 */ 	lhu	$v0,0x1a2($sp)
/*  f0c9dfc:	15a0001a */ 	bnez	$t5,.L0f0c9e68
/*  f0c9e00:	30490202 */ 	andi	$t1,$v0,0x202
/*  f0c9e04:	12e00015 */ 	beqz	$s7,.L0f0c9e5c
/*  f0c9e08:	27b000fc */ 	addiu	$s0,$sp,0xfc
/*  f0c9e0c:	97b1019e */ 	lhu	$s1,0x19e($sp)
/*  f0c9e10:	00152e00 */ 	sll	$a1,$s5,0x18
/*  f0c9e14:	00057603 */ 	sra	$t6,$a1,0x18
/*  f0c9e18:	02203025 */ 	or	$a2,$s1,$zero
/*  f0c9e1c:	30cf0202 */ 	andi	$t7,$a2,0x202
/*  f0c9e20:	01e03025 */ 	or	$a2,$t7,$zero
/*  f0c9e24:	01c02825 */ 	or	$a1,$t6,$zero
/*  f0c9e28:	0c005326 */ 	jal	joyCountButtonsOnSpecificSamples
/*  f0c9e2c:	02002025 */ 	or	$a0,$s0,$zero
/*  f0c9e30:	00152e00 */ 	sll	$a1,$s5,0x18
/*  f0c9e34:	02203025 */ 	or	$a2,$s1,$zero
/*  f0c9e38:	30d90101 */ 	andi	$t9,$a2,0x101
/*  f0c9e3c:	0005c603 */ 	sra	$t8,$a1,0x18
/*  f0c9e40:	afa201dc */ 	sw	$v0,0x1dc($sp)
/*  f0c9e44:	03002825 */ 	or	$a1,$t8,$zero
/*  f0c9e48:	03203025 */ 	or	$a2,$t9,$zero
/*  f0c9e4c:	0c005326 */ 	jal	joyCountButtonsOnSpecificSamples
/*  f0c9e50:	02002025 */ 	or	$a0,$s0,$zero
/*  f0c9e54:	afa201e0 */ 	sw	$v0,0x1e0($sp)
/*  f0c9e58:	8e450284 */ 	lw	$a1,0x284($s2)
.L0f0c9e5c:
/*  f0c9e5c:	97a801a2 */ 	lhu	$t0,0x1a2($sp)
/*  f0c9e60:	1000000d */ 	b	.L0f0c9e98
/*  f0c9e64:	afa80048 */ 	sw	$t0,0x48($sp)
.L0f0c9e68:
/*  f0c9e68:	11200005 */ 	beqz	$t1,.L0f0c9e80
/*  f0c9e6c:	304a0101 */ 	andi	$t2,$v0,0x101
/*  f0c9e70:	3c013f80 */ 	lui	$at,0x3f80
/*  f0c9e74:	44818000 */ 	mtc1	$at,$f16
/*  f0c9e78:	00000000 */ 	nop
/*  f0c9e7c:	e7b001e4 */ 	swc1	$f16,0x1e4($sp)
.L0f0c9e80:
/*  f0c9e80:	11400005 */ 	beqz	$t2,.L0f0c9e98
/*  f0c9e84:	afa20048 */ 	sw	$v0,0x48($sp)
/*  f0c9e88:	3c013f80 */ 	lui	$at,0x3f80
/*  f0c9e8c:	44819000 */ 	mtc1	$at,$f18
/*  f0c9e90:	afa20048 */ 	sw	$v0,0x48($sp)
/*  f0c9e94:	e7b201e8 */ 	swc1	$f18,0x1e8($sp)
.L0f0c9e98:
/*  f0c9e98:	8ca40120 */ 	lw	$a0,0x120($a1)
/*  f0c9e9c:	44802000 */ 	mtc1	$zero,$f4
/*  f0c9ea0:	44803000 */ 	mtc1	$zero,$f6
/*  f0c9ea4:	2c8b0001 */ 	sltiu	$t3,$a0,0x1
/*  f0c9ea8:	11600004 */ 	beqz	$t3,.L0f0c9ebc
/*  f0c9eac:	01602025 */ 	or	$a0,$t3,$zero
/*  f0c9eb0:	8fa40048 */ 	lw	$a0,0x48($sp)
/*  f0c9eb4:	308c0808 */ 	andi	$t4,$a0,0x808
/*  f0c9eb8:	000c202b */ 	sltu	$a0,$zero,$t4
.L0f0c9ebc:
/*  f0c9ebc:	afa401d4 */ 	sw	$a0,0x1d4($sp)
/*  f0c9ec0:	8ca40120 */ 	lw	$a0,0x120($a1)
/*  f0c9ec4:	2c8e0001 */ 	sltiu	$t6,$a0,0x1
/*  f0c9ec8:	11c00004 */ 	beqz	$t6,.L0f0c9edc
/*  f0c9ecc:	01c02025 */ 	or	$a0,$t6,$zero
/*  f0c9ed0:	8fa40048 */ 	lw	$a0,0x48($sp)
/*  f0c9ed4:	308f0404 */ 	andi	$t7,$a0,0x404
/*  f0c9ed8:	000f202b */ 	sltu	$a0,$zero,$t7
.L0f0c9edc:
/*  f0c9edc:	afa401d8 */ 	sw	$a0,0x1d8($sp)
/*  f0c9ee0:	afa001c4 */ 	sw	$zero,0x1c4($sp)
/*  f0c9ee4:	8ca40120 */ 	lw	$a0,0x120($a1)
/*  f0c9ee8:	e7a401ec */ 	swc1	$f4,0x1ec($sp)
/*  f0c9eec:	e7a601f0 */ 	swc1	$f6,0x1f0($sp)
/*  f0c9ef0:	2c990001 */ 	sltiu	$t9,$a0,0x1
/*  f0c9ef4:	afb901d0 */ 	sw	$t9,0x1d0($sp)
/*  f0c9ef8:	8ca40120 */ 	lw	$a0,0x120($a1)
/*  f0c9efc:	8e4902ac */ 	lw	$t1,0x2ac($s2)
/*  f0c9f00:	24010007 */ 	addiu	$at,$zero,0x7
/*  f0c9f04:	2c880001 */ 	sltiu	$t0,$a0,0x1
/*  f0c9f08:	1521005b */ 	bne	$t1,$at,.L0f0ca078
/*  f0c9f0c:	afa801cc */ 	sw	$t0,0x1cc($sp)
/*  f0c9f10:	8caa1bdc */ 	lw	$t2,0x1bdc($a1)
/*  f0c9f14:	000a582a */ 	slt	$t3,$zero,$t2
/*  f0c9f18:	afab01d4 */ 	sw	$t3,0x1d4($sp)
/*  f0c9f1c:	8cac1bdc */ 	lw	$t4,0x1bdc($a1)
/*  f0c9f20:	afa00258 */ 	sw	$zero,0x258($sp)
/*  f0c9f24:	afa0025c */ 	sw	$zero,0x25c($sp)
/*  f0c9f28:	298d0000 */ 	slti	$t5,$t4,0x0
/*  f0c9f2c:	afad01d8 */ 	sw	$t5,0x1d8($sp)
/*  f0c9f30:	8cae1bd8 */ 	lw	$t6,0x1bd8($a1)
/*  f0c9f34:	afa00254 */ 	sw	$zero,0x254($sp)
/*  f0c9f38:	1000004f */ 	b	.L0f0ca078
/*  f0c9f3c:	afae0250 */ 	sw	$t6,0x250($sp)
.L0f0c9f40:
/*  f0c9f40:	31f80202 */ 	andi	$t8,$t7,0x202
/*  f0c9f44:	13000005 */ 	beqz	$t8,.L0f0c9f5c
/*  f0c9f48:	afaf0048 */ 	sw	$t7,0x48($sp)
/*  f0c9f4c:	3c013f80 */ 	lui	$at,0x3f80
/*  f0c9f50:	44814000 */ 	mtc1	$at,$f8
/*  f0c9f54:	00000000 */ 	nop
/*  f0c9f58:	e7a801e4 */ 	swc1	$f8,0x1e4($sp)
.L0f0c9f5c:
/*  f0c9f5c:	8fb90048 */ 	lw	$t9,0x48($sp)
/*  f0c9f60:	3c013f80 */ 	lui	$at,0x3f80
/*  f0c9f64:	33280101 */ 	andi	$t0,$t9,0x101
/*  f0c9f68:	51000005 */ 	beqzl	$t0,.L0f0c9f80
/*  f0c9f6c:	8ca90120 */ 	lw	$t1,0x120($a1)
/*  f0c9f70:	44815000 */ 	mtc1	$at,$f10
/*  f0c9f74:	00000000 */ 	nop
/*  f0c9f78:	e7aa01e8 */ 	swc1	$f10,0x1e8($sp)
/*  f0c9f7c:	8ca90120 */ 	lw	$t1,0x120($a1)
.L0f0c9f80:
/*  f0c9f80:	55200018 */ 	bnezl	$t1,.L0f0c9fe4
/*  f0c9f84:	afa001d4 */ 	sw	$zero,0x1d4($sp)
/*  f0c9f88:	12e00015 */ 	beqz	$s7,.L0f0c9fe0
/*  f0c9f8c:	27b000fc */ 	addiu	$s0,$sp,0xfc
/*  f0c9f90:	97b1019e */ 	lhu	$s1,0x19e($sp)
/*  f0c9f94:	00152e00 */ 	sll	$a1,$s5,0x18
/*  f0c9f98:	00055603 */ 	sra	$t2,$a1,0x18
/*  f0c9f9c:	02203025 */ 	or	$a2,$s1,$zero
/*  f0c9fa0:	30cb0202 */ 	andi	$t3,$a2,0x202
/*  f0c9fa4:	01603025 */ 	or	$a2,$t3,$zero
/*  f0c9fa8:	01402825 */ 	or	$a1,$t2,$zero
/*  f0c9fac:	0c005326 */ 	jal	joyCountButtonsOnSpecificSamples
/*  f0c9fb0:	02002025 */ 	or	$a0,$s0,$zero
/*  f0c9fb4:	00152e00 */ 	sll	$a1,$s5,0x18
/*  f0c9fb8:	02203025 */ 	or	$a2,$s1,$zero
/*  f0c9fbc:	30cd0101 */ 	andi	$t5,$a2,0x101
/*  f0c9fc0:	00056603 */ 	sra	$t4,$a1,0x18
/*  f0c9fc4:	afa201dc */ 	sw	$v0,0x1dc($sp)
/*  f0c9fc8:	01802825 */ 	or	$a1,$t4,$zero
/*  f0c9fcc:	01a03025 */ 	or	$a2,$t5,$zero
/*  f0c9fd0:	0c005326 */ 	jal	joyCountButtonsOnSpecificSamples
/*  f0c9fd4:	02002025 */ 	or	$a0,$s0,$zero
/*  f0c9fd8:	afa201e0 */ 	sw	$v0,0x1e0($sp)
/*  f0c9fdc:	8e450284 */ 	lw	$a1,0x284($s2)
.L0f0c9fe0:
/*  f0c9fe0:	afa001d4 */ 	sw	$zero,0x1d4($sp)
.L0f0c9fe4:
/*  f0c9fe4:	afa001d8 */ 	sw	$zero,0x1d8($sp)
/*  f0c9fe8:	8ca40120 */ 	lw	$a0,0x120($a1)
/*  f0c9fec:	afa001d0 */ 	sw	$zero,0x1d0($sp)
/*  f0c9ff0:	8faf0048 */ 	lw	$t7,0x48($sp)
/*  f0c9ff4:	2c8e0001 */ 	sltiu	$t6,$a0,0x1
/*  f0c9ff8:	afae01c4 */ 	sw	$t6,0x1c4($sp)
/*  f0c9ffc:	8ca20120 */ 	lw	$v0,0x120($a1)
/*  f0ca000:	31f80808 */ 	andi	$t8,$t7,0x808
/*  f0ca004:	14400007 */ 	bnez	$v0,.L0f0ca024
/*  f0ca008:	00000000 */ 	nop
/*  f0ca00c:	13000005 */ 	beqz	$t8,.L0f0ca024
/*  f0ca010:	3c013f80 */ 	lui	$at,0x3f80
/*  f0ca014:	44818000 */ 	mtc1	$at,$f16
/*  f0ca018:	00000000 */ 	nop
/*  f0ca01c:	e7b001ec */ 	swc1	$f16,0x1ec($sp)
/*  f0ca020:	8ca20120 */ 	lw	$v0,0x120($a1)
.L0f0ca024:
/*  f0ca024:	14400008 */ 	bnez	$v0,.L0f0ca048
/*  f0ca028:	8fb90048 */ 	lw	$t9,0x48($sp)
/*  f0ca02c:	33280404 */ 	andi	$t0,$t9,0x404
/*  f0ca030:	11000005 */ 	beqz	$t0,.L0f0ca048
/*  f0ca034:	3c013f80 */ 	lui	$at,0x3f80
/*  f0ca038:	44819000 */ 	mtc1	$at,$f18
/*  f0ca03c:	00000000 */ 	nop
/*  f0ca040:	e7b201f0 */ 	swc1	$f18,0x1f0($sp)
/*  f0ca044:	8ca20120 */ 	lw	$v0,0x120($a1)
.L0f0ca048:
/*  f0ca048:	8e4902ac */ 	lw	$t1,0x2ac($s2)
/*  f0ca04c:	2c440001 */ 	sltiu	$a0,$v0,0x1
/*  f0ca050:	24010007 */ 	addiu	$at,$zero,0x7
/*  f0ca054:	afa401cc */ 	sw	$a0,0x1cc($sp)
/*  f0ca058:	15210007 */ 	bne	$t1,$at,.L0f0ca078
/*  f0ca05c:	afa001c8 */ 	sw	$zero,0x1c8($sp)
/*  f0ca060:	afa00258 */ 	sw	$zero,0x258($sp)
/*  f0ca064:	8caa1bdc */ 	lw	$t2,0x1bdc($a1)
/*  f0ca068:	afaa025c */ 	sw	$t2,0x25c($sp)
/*  f0ca06c:	8cab1bd8 */ 	lw	$t3,0x1bd8($a1)
/*  f0ca070:	afa00254 */ 	sw	$zero,0x254($sp)
/*  f0ca074:	afab0250 */ 	sw	$t3,0x250($sp)
.L0f0ca078:
/*  f0ca078:	8ca20120 */ 	lw	$v0,0x120($a1)
/*  f0ca07c:	8fa4024c */ 	lw	$a0,0x24c($sp)
/*  f0ca080:	10400012 */ 	beqz	$v0,.L0f0ca0cc
/*  f0ca084:	2881003d */ 	slti	$at,$a0,0x3d
/*  f0ca088:	14200010 */ 	bnez	$at,.L0f0ca0cc
/*  f0ca08c:	248cffc4 */ 	addiu	$t4,$a0,-60
/*  f0ca090:	448c2000 */ 	mtc1	$t4,$f4
/*  f0ca094:	3c014120 */ 	lui	$at,0x4120
/*  f0ca098:	44811000 */ 	mtc1	$at,$f2
/*  f0ca09c:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f0ca0a0:	3c013f80 */ 	lui	$at,0x3f80
/*  f0ca0a4:	44815000 */ 	mtc1	$at,$f10
/*  f0ca0a8:	3c013f80 */ 	lui	$at,0x3f80
/*  f0ca0ac:	46023203 */ 	div.s	$f8,$f6,$f2
/*  f0ca0b0:	4608503c */ 	c.lt.s	$f10,$f8
/*  f0ca0b4:	e7a801ec */ 	swc1	$f8,0x1ec($sp)
/*  f0ca0b8:	4502001a */ 	bc1fl	.L0f0ca124
/*  f0ca0bc:	8ca20120 */ 	lw	$v0,0x120($a1)
/*  f0ca0c0:	44818000 */ 	mtc1	$at,$f16
/*  f0ca0c4:	10000016 */ 	b	.L0f0ca120
/*  f0ca0c8:	e7b001ec */ 	swc1	$f16,0x1ec($sp)
.L0f0ca0cc:
/*  f0ca0cc:	10400014 */ 	beqz	$v0,.L0f0ca120
/*  f0ca0d0:	8fa4024c */ 	lw	$a0,0x24c($sp)
/*  f0ca0d4:	2881ffc4 */ 	slti	$at,$a0,-60
/*  f0ca0d8:	10200011 */ 	beqz	$at,.L0f0ca120
/*  f0ca0dc:	240dffc4 */ 	addiu	$t5,$zero,-60
/*  f0ca0e0:	01a47023 */ 	subu	$t6,$t5,$a0
/*  f0ca0e4:	448e9000 */ 	mtc1	$t6,$f18
/*  f0ca0e8:	3c014120 */ 	lui	$at,0x4120
/*  f0ca0ec:	44811000 */ 	mtc1	$at,$f2
/*  f0ca0f0:	46809120 */ 	cvt.s.w	$f4,$f18
/*  f0ca0f4:	3c013f80 */ 	lui	$at,0x3f80
/*  f0ca0f8:	44815000 */ 	mtc1	$at,$f10
/*  f0ca0fc:	3c013f80 */ 	lui	$at,0x3f80
/*  f0ca100:	46022183 */ 	div.s	$f6,$f4,$f2
/*  f0ca104:	4606503c */ 	c.lt.s	$f10,$f6
/*  f0ca108:	e7a601f0 */ 	swc1	$f6,0x1f0($sp)
/*  f0ca10c:	45020005 */ 	bc1fl	.L0f0ca124
/*  f0ca110:	8ca20120 */ 	lw	$v0,0x120($a1)
/*  f0ca114:	44814000 */ 	mtc1	$at,$f8
/*  f0ca118:	00000000 */ 	nop
/*  f0ca11c:	e7a801f0 */ 	swc1	$f8,0x1f0($sp)
.L0f0ca120:
/*  f0ca120:	8ca20120 */ 	lw	$v0,0x120($a1)
.L0f0ca124:
/*  f0ca124:	3c014120 */ 	lui	$at,0x4120
/*  f0ca128:	44811000 */ 	mtc1	$at,$f2
/*  f0ca12c:	10400012 */ 	beqz	$v0,.L0f0ca178
/*  f0ca130:	8fa30248 */ 	lw	$v1,0x248($sp)
/*  f0ca134:	2861ffc4 */ 	slti	$at,$v1,-60
/*  f0ca138:	1020000f */ 	beqz	$at,.L0f0ca178
/*  f0ca13c:	240fffc4 */ 	addiu	$t7,$zero,-60
/*  f0ca140:	01e3c023 */ 	subu	$t8,$t7,$v1
/*  f0ca144:	44988000 */ 	mtc1	$t8,$f16
/*  f0ca148:	3c013f80 */ 	lui	$at,0x3f80
/*  f0ca14c:	44812000 */ 	mtc1	$at,$f4
/*  f0ca150:	468084a0 */ 	cvt.s.w	$f18,$f16
/*  f0ca154:	3c013f80 */ 	lui	$at,0x3f80
/*  f0ca158:	46029303 */ 	div.s	$f12,$f18,$f2
/*  f0ca15c:	460c203c */ 	c.lt.s	$f4,$f12
/*  f0ca160:	e7ac01f4 */ 	swc1	$f12,0x1f4($sp)
/*  f0ca164:	45000016 */ 	bc1f	.L0f0ca1c0
/*  f0ca168:	00000000 */ 	nop
/*  f0ca16c:	44816000 */ 	mtc1	$at,$f12
/*  f0ca170:	10000013 */ 	b	.L0f0ca1c0
/*  f0ca174:	e7ac01f4 */ 	swc1	$f12,0x1f4($sp)
.L0f0ca178:
/*  f0ca178:	10400011 */ 	beqz	$v0,.L0f0ca1c0
/*  f0ca17c:	8fa30248 */ 	lw	$v1,0x248($sp)
/*  f0ca180:	2861003d */ 	slti	$at,$v1,0x3d
/*  f0ca184:	1420000e */ 	bnez	$at,.L0f0ca1c0
/*  f0ca188:	2479ffc4 */ 	addiu	$t9,$v1,-60
/*  f0ca18c:	44995000 */ 	mtc1	$t9,$f10
/*  f0ca190:	3c013f80 */ 	lui	$at,0x3f80
/*  f0ca194:	44814000 */ 	mtc1	$at,$f8
/*  f0ca198:	468051a0 */ 	cvt.s.w	$f6,$f10
/*  f0ca19c:	3c013f80 */ 	lui	$at,0x3f80
/*  f0ca1a0:	46023003 */ 	div.s	$f0,$f6,$f2
/*  f0ca1a4:	4600403c */ 	c.lt.s	$f8,$f0
/*  f0ca1a8:	e7a001f8 */ 	swc1	$f0,0x1f8($sp)
/*  f0ca1ac:	45000004 */ 	bc1f	.L0f0ca1c0
/*  f0ca1b0:	00000000 */ 	nop
/*  f0ca1b4:	44810000 */ 	mtc1	$at,$f0
/*  f0ca1b8:	00000000 */ 	nop
/*  f0ca1bc:	e7a001f8 */ 	swc1	$f0,0x1f8($sp)
.L0f0ca1c0:
/*  f0ca1c0:	52e00060 */ 	beqzl	$s7,.L0f0ca344
/*  f0ca1c4:	97aa00ca */ 	lhu	$t2,0xca($sp)
/*  f0ca1c8:	84a2024c */ 	lh	$v0,0x24c($a1)
/*  f0ca1cc:	2841fffe */ 	slti	$at,$v0,-2
/*  f0ca1d0:	10200009 */ 	beqz	$at,.L0f0ca1f8
/*  f0ca1d4:	00564021 */ 	addu	$t0,$v0,$s6
/*  f0ca1d8:	a4a8024c */ 	sh	$t0,0x24c($a1)
/*  f0ca1dc:	8e450284 */ 	lw	$a1,0x284($s2)
/*  f0ca1e0:	84a9024c */ 	lh	$t1,0x24c($a1)
/*  f0ca1e4:	2921fffe */ 	slti	$at,$t1,-2
/*  f0ca1e8:	54200056 */ 	bnezl	$at,.L0f0ca344
/*  f0ca1ec:	97aa00ca */ 	lhu	$t2,0xca($sp)
/*  f0ca1f0:	10000053 */ 	b	.L0f0ca340
/*  f0ca1f4:	a4a0024c */ 	sh	$zero,0x24c($a1)
.L0f0ca1f8:
/*  f0ca1f8:	1ac00051 */ 	blez	$s6,.L0f0ca340
/*  f0ca1fc:	00008025 */ 	or	$s0,$zero,$zero
/*  f0ca200:	97b1019e */ 	lhu	$s1,0x19e($sp)
/*  f0ca204:	97aa00ca */ 	lhu	$t2,0xca($sp)
/*  f0ca208:	2413ffff */ 	addiu	$s3,$zero,-1
/*  f0ca20c:	01513024 */ 	and	$a2,$t2,$s1
/*  f0ca210:	30cbffff */ 	andi	$t3,$a2,0xffff
/*  f0ca214:	afab003c */ 	sw	$t3,0x3c($sp)
/*  f0ca218:	00152e00 */ 	sll	$a1,$s5,0x18
.L0f0ca21c:
/*  f0ca21c:	00056603 */ 	sra	$t4,$a1,0x18
/*  f0ca220:	8fa6003c */ 	lw	$a2,0x3c($sp)
/*  f0ca224:	01802825 */ 	or	$a1,$t4,$zero
/*  f0ca228:	0c00529e */ 	jal	joyGetButtonsOnSample
/*  f0ca22c:	02002025 */ 	or	$a0,$s0,$zero
/*  f0ca230:	5040002d */ 	beqzl	$v0,.L0f0ca2e8
/*  f0ca234:	8e4f0284 */ 	lw	$t7,0x284($s2)
/*  f0ca238:	8e4d0284 */ 	lw	$t5,0x284($s2)
/*  f0ca23c:	00152e00 */ 	sll	$a1,$s5,0x18
/*  f0ca240:	00057e03 */ 	sra	$t7,$a1,0x18
/*  f0ca244:	85ae024c */ 	lh	$t6,0x24c($t5)
/*  f0ca248:	01e02825 */ 	or	$a1,$t7,$zero
/*  f0ca24c:	02002025 */ 	or	$a0,$s0,$zero
/*  f0ca250:	29c1ffff */ 	slti	$at,$t6,-1
/*  f0ca254:	14200037 */ 	bnez	$at,.L0f0ca334
/*  f0ca258:	02913024 */ 	and	$a2,$s4,$s1
/*  f0ca25c:	30d8ffff */ 	andi	$t8,$a2,0xffff
/*  f0ca260:	03003025 */ 	or	$a2,$t8,$zero
/*  f0ca264:	0c0052d4 */ 	jal	joyGetButtonsPressedOnSample
/*  f0ca268:	afb8004c */ 	sw	$t8,0x4c($sp)
/*  f0ca26c:	10400006 */ 	beqz	$v0,.L0f0ca288
/*  f0ca270:	8fa6004c */ 	lw	$a2,0x4c($sp)
/*  f0ca274:	8fb901fc */ 	lw	$t9,0x1fc($sp)
/*  f0ca278:	8e490284 */ 	lw	$t1,0x284($s2)
/*  f0ca27c:	27280001 */ 	addiu	$t0,$t9,0x1
/*  f0ca280:	afa801fc */ 	sw	$t0,0x1fc($sp)
/*  f0ca284:	a533024c */ 	sh	$s3,0x24c($t1)
.L0f0ca288:
/*  f0ca288:	8e4a0284 */ 	lw	$t2,0x284($s2)
/*  f0ca28c:	00152e00 */ 	sll	$a1,$s5,0x18
/*  f0ca290:	00056603 */ 	sra	$t4,$a1,0x18
/*  f0ca294:	854b024c */ 	lh	$t3,0x24c($t2)
/*  f0ca298:	02002025 */ 	or	$a0,$s0,$zero
/*  f0ca29c:	05620026 */ 	bltzl	$t3,.L0f0ca338
/*  f0ca2a0:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f0ca2a4:	0c00529e */ 	jal	joyGetButtonsOnSample
/*  f0ca2a8:	01802825 */ 	or	$a1,$t4,$zero
/*  f0ca2ac:	54400022 */ 	bnezl	$v0,.L0f0ca338
/*  f0ca2b0:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f0ca2b4:	8e450284 */ 	lw	$a1,0x284($s2)
/*  f0ca2b8:	84a2024c */ 	lh	$v0,0x24c($a1)
/*  f0ca2bc:	28410010 */ 	slti	$at,$v0,0x10
/*  f0ca2c0:	14200006 */ 	bnez	$at,.L0f0ca2dc
/*  f0ca2c4:	244e0001 */ 	addiu	$t6,$v0,0x1
/*  f0ca2c8:	0fc3fbda */ 	jal	amOpen
/*  f0ca2cc:	00000000 */ 	nop
/*  f0ca2d0:	8e4d0284 */ 	lw	$t5,0x284($s2)
/*  f0ca2d4:	10000017 */ 	b	.L0f0ca334
/*  f0ca2d8:	a5b3024c */ 	sh	$s3,0x24c($t5)
.L0f0ca2dc:
/*  f0ca2dc:	10000015 */ 	b	.L0f0ca334
/*  f0ca2e0:	a4ae024c */ 	sh	$t6,0x24c($a1)
/*  f0ca2e4:	8e4f0284 */ 	lw	$t7,0x284($s2)
.L0f0ca2e8:
/*  f0ca2e8:	85f8024c */ 	lh	$t8,0x24c($t7)
/*  f0ca2ec:	5b000010 */ 	blezl	$t8,.L0f0ca330
/*  f0ca2f0:	8e490284 */ 	lw	$t1,0x284($s2)
/*  f0ca2f4:	12e0000a */ 	beqz	$s7,.L0f0ca320
/*  f0ca2f8:	02002025 */ 	or	$a0,$s0,$zero
/*  f0ca2fc:	00152e00 */ 	sll	$a1,$s5,0x18
/*  f0ca300:	02913024 */ 	and	$a2,$s4,$s1
/*  f0ca304:	30c8ffff */ 	andi	$t0,$a2,0xffff
/*  f0ca308:	0005ce03 */ 	sra	$t9,$a1,0x18
/*  f0ca30c:	03202825 */ 	or	$a1,$t9,$zero
/*  f0ca310:	0c00529e */ 	jal	joyGetButtonsOnSample
/*  f0ca314:	01003025 */ 	or	$a2,$t0,$zero
/*  f0ca318:	54400005 */ 	bnezl	$v0,.L0f0ca330
/*  f0ca31c:	8e490284 */ 	lw	$t1,0x284($s2)
.L0f0ca320:
/*  f0ca320:	8fa20200 */ 	lw	$v0,0x200($sp)
/*  f0ca324:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f0ca328:	afa20200 */ 	sw	$v0,0x200($sp)
/*  f0ca32c:	8e490284 */ 	lw	$t1,0x284($s2)
.L0f0ca330:
/*  f0ca330:	a520024c */ 	sh	$zero,0x24c($t1)
.L0f0ca334:
/*  f0ca334:	26100001 */ 	addiu	$s0,$s0,0x1
.L0f0ca338:
/*  f0ca338:	5616ffb8 */ 	bnel	$s0,$s6,.L0f0ca21c
/*  f0ca33c:	00152e00 */ 	sll	$a1,$s5,0x18
.L0f0ca340:
/*  f0ca340:	97aa00ca */ 	lhu	$t2,0xca($sp)
.L0f0ca344:
/*  f0ca344:	2413ffff */ 	addiu	$s3,$zero,-1
/*  f0ca348:	12e00058 */ 	beqz	$s7,.L0f0ca4ac
/*  f0ca34c:	afaa0038 */ 	sw	$t2,0x38($sp)
/*  f0ca350:	1ac00056 */ 	blez	$s6,.L0f0ca4ac
/*  f0ca354:	00008025 */ 	or	$s0,$zero,$zero
/*  f0ca358:	97b1019e */ 	lhu	$s1,0x19e($sp)
/*  f0ca35c:	322c4000 */ 	andi	$t4,$s1,0x4000
/*  f0ca360:	afac0044 */ 	sw	$t4,0x44($sp)
/*  f0ca364:	00152e00 */ 	sll	$a1,$s5,0x18
.L0f0ca368:
/*  f0ca368:	00056e03 */ 	sra	$t5,$a1,0x18
/*  f0ca36c:	01a02825 */ 	or	$a1,$t5,$zero
/*  f0ca370:	02002025 */ 	or	$a0,$s0,$zero
/*  f0ca374:	0c00529e */ 	jal	joyGetButtonsOnSample
/*  f0ca378:	97a60046 */ 	lhu	$a2,0x46($sp)
/*  f0ca37c:	50400040 */ 	beqzl	$v0,.L0f0ca480
/*  f0ca380:	8e450284 */ 	lw	$a1,0x284($s2)
/*  f0ca384:	8e4e0284 */ 	lw	$t6,0x284($s2)
/*  f0ca388:	00152e00 */ 	sll	$a1,$s5,0x18
/*  f0ca38c:	00057e03 */ 	sra	$t7,$a1,0x18
/*  f0ca390:	85c4024e */ 	lh	$a0,0x24e($t6)
/*  f0ca394:	02913024 */ 	and	$a2,$s4,$s1
/*  f0ca398:	30d8ffff */ 	andi	$t8,$a2,0xffff
/*  f0ca39c:	2881ffff */ 	slti	$at,$a0,-1
/*  f0ca3a0:	1420002f */ 	bnez	$at,.L0f0ca460
/*  f0ca3a4:	01e02825 */ 	or	$a1,$t7,$zero
/*  f0ca3a8:	02002025 */ 	or	$a0,$s0,$zero
/*  f0ca3ac:	0c0052d4 */ 	jal	joyGetButtonsPressedOnSample
/*  f0ca3b0:	03003025 */ 	or	$a2,$t8,$zero
/*  f0ca3b4:	5040000e */ 	beqzl	$v0,.L0f0ca3f0
/*  f0ca3b8:	8e450284 */ 	lw	$a1,0x284($s2)
/*  f0ca3bc:	8e590284 */ 	lw	$t9,0x284($s2)
/*  f0ca3c0:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f0ca3c4:	8724024e */ 	lh	$a0,0x24e($t9)
/*  f0ca3c8:	04820009 */ 	bltzl	$a0,.L0f0ca3f0
/*  f0ca3cc:	8e450284 */ 	lw	$a1,0x284($s2)
/*  f0ca3d0:	0fc2a257 */ 	jal	bgunConsiderToggleGunFunction
/*  f0ca3d4:	00003025 */ 	or	$a2,$zero,$zero
/*  f0ca3d8:	50400005 */ 	beqzl	$v0,.L0f0ca3f0
/*  f0ca3dc:	8e450284 */ 	lw	$a1,0x284($s2)
/*  f0ca3e0:	8e490284 */ 	lw	$t1,0x284($s2)
/*  f0ca3e4:	2408fffd */ 	addiu	$t0,$zero,-3
/*  f0ca3e8:	a528024e */ 	sh	$t0,0x24e($t1)
/*  f0ca3ec:	8e450284 */ 	lw	$a1,0x284($s2)
.L0f0ca3f0:
/*  f0ca3f0:	84a4024e */ 	lh	$a0,0x24e($a1)
/*  f0ca3f4:	0480002a */ 	bltz	$a0,.L0f0ca4a0
/*  f0ca3f8:	2881001a */ 	slti	$at,$a0,0x1a
/*  f0ca3fc:	14200016 */ 	bnez	$at,.L0f0ca458
/*  f0ca400:	248f0001 */ 	addiu	$t7,$a0,0x1
/*  f0ca404:	00002825 */ 	or	$a1,$zero,$zero
/*  f0ca408:	0fc2a257 */ 	jal	bgunConsiderToggleGunFunction
/*  f0ca40c:	00003025 */ 	or	$a2,$zero,$zero
/*  f0ca410:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0ca414:	54410005 */ 	bnel	$v0,$at,.L0f0ca42c
/*  f0ca418:	24010002 */ 	addiu	$at,$zero,0x2
/*  f0ca41c:	8e4a0284 */ 	lw	$t2,0x284($s2)
/*  f0ca420:	1000001f */ 	b	.L0f0ca4a0
/*  f0ca424:	a553024e */ 	sh	$s3,0x24e($t2)
/*  f0ca428:	24010002 */ 	addiu	$at,$zero,0x2
.L0f0ca42c:
/*  f0ca42c:	54410006 */ 	bnel	$v0,$at,.L0f0ca448
/*  f0ca430:	8e450284 */ 	lw	$a1,0x284($s2)
/*  f0ca434:	8e4c0284 */ 	lw	$t4,0x284($s2)
/*  f0ca438:	240bfffe */ 	addiu	$t3,$zero,-2
/*  f0ca43c:	10000018 */ 	b	.L0f0ca4a0
/*  f0ca440:	a58b024e */ 	sh	$t3,0x24e($t4)
/*  f0ca444:	8e450284 */ 	lw	$a1,0x284($s2)
.L0f0ca448:
/*  f0ca448:	84ad024e */ 	lh	$t5,0x24e($a1)
/*  f0ca44c:	25ae0001 */ 	addiu	$t6,$t5,0x1
/*  f0ca450:	10000013 */ 	b	.L0f0ca4a0
/*  f0ca454:	a4ae024e */ 	sh	$t6,0x24e($a1)
.L0f0ca458:
/*  f0ca458:	10000011 */ 	b	.L0f0ca4a0
/*  f0ca45c:	a4af024e */ 	sh	$t7,0x24e($a1)
.L0f0ca460:
/*  f0ca460:	2881fffe */ 	slti	$at,$a0,-2
/*  f0ca464:	1420000e */ 	bnez	$at,.L0f0ca4a0
/*  f0ca468:	00002825 */ 	or	$a1,$zero,$zero
/*  f0ca46c:	0fc2a257 */ 	jal	bgunConsiderToggleGunFunction
/*  f0ca470:	00003025 */ 	or	$a2,$zero,$zero
/*  f0ca474:	1000000b */ 	b	.L0f0ca4a4
/*  f0ca478:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f0ca47c:	8e450284 */ 	lw	$a1,0x284($s2)
.L0f0ca480:
/*  f0ca480:	8fb901c0 */ 	lw	$t9,0x1c0($sp)
/*  f0ca484:	84b8024e */ 	lh	$t8,0x24e($a1)
/*  f0ca488:	27280001 */ 	addiu	$t0,$t9,0x1
/*  f0ca48c:	1b000002 */ 	blez	$t8,.L0f0ca498
/*  f0ca490:	00000000 */ 	nop
/*  f0ca494:	afa801c0 */ 	sw	$t0,0x1c0($sp)
.L0f0ca498:
/*  f0ca498:	0fc2a314 */ 	jal	bgun0f0a8c50
/*  f0ca49c:	a4a0024e */ 	sh	$zero,0x24e($a1)
.L0f0ca4a0:
/*  f0ca4a0:	26100001 */ 	addiu	$s0,$s0,0x1
.L0f0ca4a4:
/*  f0ca4a4:	5616ffb0 */ 	bnel	$s0,$s6,.L0f0ca368
/*  f0ca4a8:	00152e00 */ 	sll	$a1,$s5,0x18
.L0f0ca4ac:
/*  f0ca4ac:	8fa901a8 */ 	lw	$t1,0x1a8($sp)
/*  f0ca4b0:	1120001c */ 	beqz	$t1,.L0f0ca524
/*  f0ca4b4:	00000000 */ 	nop
/*  f0ca4b8:	8e4a0284 */ 	lw	$t2,0x284($s2)
/*  f0ca4bc:	8fa20048 */ 	lw	$v0,0x48($sp)
/*  f0ca4c0:	3c013f80 */ 	lui	$at,0x3f80
/*  f0ca4c4:	8d4b0120 */ 	lw	$t3,0x120($t2)
/*  f0ca4c8:	30510808 */ 	andi	$s1,$v0,0x808
/*  f0ca4cc:	0011602b */ 	sltu	$t4,$zero,$s1
/*  f0ca4d0:	11600014 */ 	beqz	$t3,.L0f0ca524
/*  f0ca4d4:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f0ca4d8:	44810000 */ 	mtc1	$at,$f0
/*  f0ca4dc:	30500404 */ 	andi	$s0,$v0,0x404
/*  f0ca4e0:	0010682b */ 	sltu	$t5,$zero,$s0
/*  f0ca4e4:	01a08025 */ 	or	$s0,$t5,$zero
/*  f0ca4e8:	01808825 */ 	or	$s1,$t4,$zero
/*  f0ca4ec:	0fc2866a */ 	jal	bgunGetWeaponNum
/*  f0ca4f0:	e7a000bc */ 	swc1	$f0,0xbc($sp)
/*  f0ca4f4:	24010016 */ 	addiu	$at,$zero,0x16
/*  f0ca4f8:	14410004 */ 	bne	$v0,$at,.L0f0ca50c
/*  f0ca4fc:	c7a000bc */ 	lwc1	$f0,0xbc($sp)
/*  f0ca500:	3c013f00 */ 	lui	$at,0x3f00
/*  f0ca504:	44810000 */ 	mtc1	$at,$f0
/*  f0ca508:	00000000 */ 	nop
.L0f0ca50c:
/*  f0ca50c:	12000002 */ 	beqz	$s0,.L0f0ca518
/*  f0ca510:	00000000 */ 	nop
/*  f0ca514:	e7a00210 */ 	swc1	$f0,0x210($sp)
.L0f0ca518:
/*  f0ca518:	12200002 */ 	beqz	$s1,.L0f0ca524
/*  f0ca51c:	00000000 */ 	nop
/*  f0ca520:	e7a00214 */ 	swc1	$f0,0x214($sp)
.L0f0ca524:
/*  f0ca524:	12e00052 */ 	beqz	$s7,.L0f0ca670
/*  f0ca528:	00000000 */ 	nop
/*  f0ca52c:	1ac00050 */ 	blez	$s6,.L0f0ca670
/*  f0ca530:	00008025 */ 	or	$s0,$zero,$zero
/*  f0ca534:	8fae01a8 */ 	lw	$t6,0x1a8($sp)
.L0f0ca538:
/*  f0ca538:	00107880 */ 	sll	$t7,$s0,0x2
/*  f0ca53c:	03afc021 */ 	addu	$t8,$sp,$t7
/*  f0ca540:	55c0002c */ 	bnezl	$t6,.L0f0ca5f4
/*  f0ca544:	8e4e0288 */ 	lw	$t6,0x288($s2)
/*  f0ca548:	8f18014c */ 	lw	$t8,0x14c($t8)
/*  f0ca54c:	02002025 */ 	or	$a0,$s0,$zero
/*  f0ca550:	00152e00 */ 	sll	$a1,$s5,0x18
/*  f0ca554:	13000026 */ 	beqz	$t8,.L0f0ca5f0
/*  f0ca558:	97b1019e */ 	lhu	$s1,0x19e($sp)
/*  f0ca55c:	02203025 */ 	or	$a2,$s1,$zero
/*  f0ca560:	30c80808 */ 	andi	$t0,$a2,0x808
/*  f0ca564:	0005ce03 */ 	sra	$t9,$a1,0x18
/*  f0ca568:	322a0404 */ 	andi	$t2,$s1,0x404
/*  f0ca56c:	afaa0050 */ 	sw	$t2,0x50($sp)
/*  f0ca570:	03202825 */ 	or	$a1,$t9,$zero
/*  f0ca574:	0c0052d4 */ 	jal	joyGetButtonsPressedOnSample
/*  f0ca578:	01003025 */ 	or	$a2,$t0,$zero
/*  f0ca57c:	1040000b */ 	beqz	$v0,.L0f0ca5ac
/*  f0ca580:	02002025 */ 	or	$a0,$s0,$zero
/*  f0ca584:	8fa20218 */ 	lw	$v0,0x218($sp)
/*  f0ca588:	10400003 */ 	beqz	$v0,.L0f0ca598
/*  f0ca58c:	2442ffff */ 	addiu	$v0,$v0,-1
/*  f0ca590:	10000004 */ 	b	.L0f0ca5a4
/*  f0ca594:	afa20218 */ 	sw	$v0,0x218($sp)
.L0f0ca598:
/*  f0ca598:	8fa2021c */ 	lw	$v0,0x21c($sp)
/*  f0ca59c:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f0ca5a0:	afa2021c */ 	sw	$v0,0x21c($sp)
.L0f0ca5a4:
/*  f0ca5a4:	8e4b0284 */ 	lw	$t3,0x284($s2)
/*  f0ca5a8:	ad730260 */ 	sw	$s3,0x260($t3)
.L0f0ca5ac:
/*  f0ca5ac:	00152e00 */ 	sll	$a1,$s5,0x18
/*  f0ca5b0:	00056603 */ 	sra	$t4,$a1,0x18
/*  f0ca5b4:	01802825 */ 	or	$a1,$t4,$zero
/*  f0ca5b8:	0c0052d4 */ 	jal	joyGetButtonsPressedOnSample
/*  f0ca5bc:	97a60052 */ 	lhu	$a2,0x52($sp)
/*  f0ca5c0:	5040000c */ 	beqzl	$v0,.L0f0ca5f4
/*  f0ca5c4:	8e4e0288 */ 	lw	$t6,0x288($s2)
/*  f0ca5c8:	8fa2021c */ 	lw	$v0,0x21c($sp)
/*  f0ca5cc:	10400003 */ 	beqz	$v0,.L0f0ca5dc
/*  f0ca5d0:	2442ffff */ 	addiu	$v0,$v0,-1
/*  f0ca5d4:	10000004 */ 	b	.L0f0ca5e8
/*  f0ca5d8:	afa2021c */ 	sw	$v0,0x21c($sp)
.L0f0ca5dc:
/*  f0ca5dc:	8fa20218 */ 	lw	$v0,0x218($sp)
/*  f0ca5e0:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f0ca5e4:	afa20218 */ 	sw	$v0,0x218($sp)
.L0f0ca5e8:
/*  f0ca5e8:	8e4d0284 */ 	lw	$t5,0x284($s2)
/*  f0ca5ec:	adb30260 */ 	sw	$s3,0x260($t5)
.L0f0ca5f0:
/*  f0ca5f0:	8e4e0288 */ 	lw	$t6,0x288($s2)
.L0f0ca5f4:
/*  f0ca5f4:	0fc549fb */ 	jal	optionsGetAimControl
/*  f0ca5f8:	8dc40070 */ 	lw	$a0,0x70($t6)
/*  f0ca5fc:	14400019 */ 	bnez	$v0,.L0f0ca664
/*  f0ca600:	00107880 */ 	sll	$t7,$s0,0x2
/*  f0ca604:	03afc021 */ 	addu	$t8,$sp,$t7
/*  f0ca608:	8f18014c */ 	lw	$t8,0x14c($t8)
/*  f0ca60c:	53000008 */ 	beqzl	$t8,.L0f0ca630
/*  f0ca610:	8e450284 */ 	lw	$a1,0x284($s2)
/*  f0ca614:	8e450284 */ 	lw	$a1,0x284($s2)
/*  f0ca618:	8ca20260 */ 	lw	$v0,0x260($a1)
/*  f0ca61c:	04400011 */ 	bltz	$v0,.L0f0ca664
/*  f0ca620:	24590001 */ 	addiu	$t9,$v0,0x1
/*  f0ca624:	1000000f */ 	b	.L0f0ca664
/*  f0ca628:	acb90260 */ 	sw	$t9,0x260($a1)
/*  f0ca62c:	8e450284 */ 	lw	$a1,0x284($s2)
.L0f0ca630:
/*  f0ca630:	8ca20260 */ 	lw	$v0,0x260($a1)
/*  f0ca634:	1840000a */ 	blez	$v0,.L0f0ca660
/*  f0ca638:	2841000f */ 	slti	$at,$v0,0xf
/*  f0ca63c:	10200008 */ 	beqz	$at,.L0f0ca660
/*  f0ca640:	8fa20218 */ 	lw	$v0,0x218($sp)
/*  f0ca644:	10400003 */ 	beqz	$v0,.L0f0ca654
/*  f0ca648:	2442ffff */ 	addiu	$v0,$v0,-1
/*  f0ca64c:	10000004 */ 	b	.L0f0ca660
/*  f0ca650:	afa20218 */ 	sw	$v0,0x218($sp)
.L0f0ca654:
/*  f0ca654:	8fa2021c */ 	lw	$v0,0x21c($sp)
/*  f0ca658:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f0ca65c:	afa2021c */ 	sw	$v0,0x21c($sp)
.L0f0ca660:
/*  f0ca660:	aca00260 */ 	sw	$zero,0x260($a1)
.L0f0ca664:
/*  f0ca664:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f0ca668:	5616ffb3 */ 	bnel	$s0,$s6,.L0f0ca538
/*  f0ca66c:	8fae01a8 */ 	lw	$t6,0x1a8($sp)
.L0f0ca670:
/*  f0ca670:	0fc331a0 */ 	jal	bmoveGetCrouchPos
/*  f0ca674:	00000000 */ 	nop
/*  f0ca678:	1440001e */ 	bnez	$v0,.L0f0ca6f4
/*  f0ca67c:	00000000 */ 	nop
/*  f0ca680:	8e450284 */ 	lw	$a1,0x284($s2)
/*  f0ca684:	3c01c2b4 */ 	lui	$at,0xc2b4
/*  f0ca688:	44818000 */ 	mtc1	$at,$f16
/*  f0ca68c:	c4b200b4 */ 	lwc1	$f18,0xb4($a1)
/*  f0ca690:	46128032 */ 	c.eq.s	$f16,$f18
/*  f0ca694:	00000000 */ 	nop
/*  f0ca698:	45000016 */ 	bc1f	.L0f0ca6f4
/*  f0ca69c:	00000000 */ 	nop
/*  f0ca6a0:	8e480314 */ 	lw	$t0,0x314($s2)
/*  f0ca6a4:	11000013 */ 	beqz	$t0,.L0f0ca6f4
/*  f0ca6a8:	00000000 */ 	nop
/*  f0ca6ac:	8e490298 */ 	lw	$t1,0x298($s2)
/*  f0ca6b0:	05210010 */ 	bgez	$t1,.L0f0ca6f4
/*  f0ca6b4:	00000000 */ 	nop
/*  f0ca6b8:	8ca40120 */ 	lw	$a0,0x120($a1)
/*  f0ca6bc:	8fa201a8 */ 	lw	$v0,0x1a8($sp)
/*  f0ca6c0:	0004502b */ 	sltu	$t2,$zero,$a0
/*  f0ca6c4:	1140000a */ 	beqz	$t2,.L0f0ca6f0
/*  f0ca6c8:	01402025 */ 	or	$a0,$t2,$zero
/*  f0ca6cc:	2c440001 */ 	sltiu	$a0,$v0,0x1
/*  f0ca6d0:	10800007 */ 	beqz	$a0,.L0f0ca6f0
/*  f0ca6d4:	97ad019e */ 	lhu	$t5,0x19e($sp)
/*  f0ca6d8:	00152600 */ 	sll	$a0,$s5,0x18
/*  f0ca6dc:	00046603 */ 	sra	$t4,$a0,0x18
/*  f0ca6e0:	01802025 */ 	or	$a0,$t4,$zero
/*  f0ca6e4:	0c0053d8 */ 	jal	joyGetButtons
/*  f0ca6e8:	31a50404 */ 	andi	$a1,$t5,0x404
/*  f0ca6ec:	0002202b */ 	sltu	$a0,$zero,$v0
.L0f0ca6f0:
/*  f0ca6f0:	afa40234 */ 	sw	$a0,0x234($sp)
.L0f0ca6f4:
/*  f0ca6f4:	0fc2866a */ 	jal	bgunGetWeaponNum
/*  f0ca6f8:	00002025 */ 	or	$a0,$zero,$zero
/*  f0ca6fc:	24010016 */ 	addiu	$at,$zero,0x16
/*  f0ca700:	5441000c */ 	bnel	$v0,$at,.L0f0ca734
/*  f0ca704:	8e450284 */ 	lw	$a1,0x284($s2)
/*  f0ca708:	8e450284 */ 	lw	$a1,0x284($s2)
/*  f0ca70c:	8ca40120 */ 	lw	$a0,0x120($a1)
/*  f0ca710:	0004782b */ 	sltu	$t7,$zero,$a0
/*  f0ca714:	11e00004 */ 	beqz	$t7,.L0f0ca728
/*  f0ca718:	01e02025 */ 	or	$a0,$t7,$zero
/*  f0ca71c:	8fa40048 */ 	lw	$a0,0x48($sp)
/*  f0ca720:	30980303 */ 	andi	$t8,$a0,0x303
/*  f0ca724:	0018202b */ 	sltu	$a0,$zero,$t8
.L0f0ca728:
/*  f0ca728:	10000012 */ 	b	.L0f0ca774
/*  f0ca72c:	afa40230 */ 	sw	$a0,0x230($sp)
/*  f0ca730:	8e450284 */ 	lw	$a1,0x284($s2)
.L0f0ca734:
/*  f0ca734:	8ca40120 */ 	lw	$a0,0x120($a1)
/*  f0ca738:	0004402b */ 	sltu	$t0,$zero,$a0
/*  f0ca73c:	11000004 */ 	beqz	$t0,.L0f0ca750
/*  f0ca740:	01002025 */ 	or	$a0,$t0,$zero
/*  f0ca744:	8fa40048 */ 	lw	$a0,0x48($sp)
/*  f0ca748:	30890202 */ 	andi	$t1,$a0,0x202
/*  f0ca74c:	0009202b */ 	sltu	$a0,$zero,$t1
.L0f0ca750:
/*  f0ca750:	afa40220 */ 	sw	$a0,0x220($sp)
/*  f0ca754:	8ca40120 */ 	lw	$a0,0x120($a1)
/*  f0ca758:	0004582b */ 	sltu	$t3,$zero,$a0
/*  f0ca75c:	11600004 */ 	beqz	$t3,.L0f0ca770
/*  f0ca760:	01602025 */ 	or	$a0,$t3,$zero
/*  f0ca764:	8fa40048 */ 	lw	$a0,0x48($sp)
/*  f0ca768:	308c0101 */ 	andi	$t4,$a0,0x101
/*  f0ca76c:	000c202b */ 	sltu	$a0,$zero,$t4
.L0f0ca770:
/*  f0ca770:	afa40224 */ 	sw	$a0,0x224($sp)
.L0f0ca774:
/*  f0ca774:	8fae0048 */ 	lw	$t6,0x48($sp)
/*  f0ca778:	8faf0038 */ 	lw	$t7,0x38($sp)
/*  f0ca77c:	97b901a0 */ 	lhu	$t9,0x1a0($sp)
/*  f0ca780:	8fa90048 */ 	lw	$t1,0x48($sp)
/*  f0ca784:	01cfc024 */ 	and	$t8,$t6,$t7
/*  f0ca788:	13000002 */ 	beqz	$t8,.L0f0ca794
/*  f0ca78c:	33284000 */ 	andi	$t0,$t9,0x4000
/*  f0ca790:	15000007 */ 	bnez	$t0,.L0f0ca7b0
.L0f0ca794:
/*  f0ca794:	312a4000 */ 	andi	$t2,$t1,0x4000
/*  f0ca798:	11400012 */ 	beqz	$t2,.L0f0ca7e4
/*  f0ca79c:	97ab01a0 */ 	lhu	$t3,0x1a0($sp)
/*  f0ca7a0:	8fac0038 */ 	lw	$t4,0x38($sp)
/*  f0ca7a4:	016c6824 */ 	and	$t5,$t3,$t4
/*  f0ca7a8:	51a0000f */ 	beqzl	$t5,.L0f0ca7e8
/*  f0ca7ac:	8e450284 */ 	lw	$a1,0x284($s2)
.L0f0ca7b0:
/*  f0ca7b0:	8fae01ac */ 	lw	$t6,0x1ac($sp)
/*  f0ca7b4:	24010022 */ 	addiu	$at,$zero,0x22
/*  f0ca7b8:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f0ca7bc:	15c10009 */ 	bne	$t6,$at,.L0f0ca7e4
/*  f0ca7c0:	2418fffe */ 	addiu	$t8,$zero,-2
/*  f0ca7c4:	afaf0228 */ 	sw	$t7,0x228($sp)
/*  f0ca7c8:	afa001fc */ 	sw	$zero,0x1fc($sp)
/*  f0ca7cc:	afa00200 */ 	sw	$zero,0x200($sp)
/*  f0ca7d0:	afa001c0 */ 	sw	$zero,0x1c0($sp)
/*  f0ca7d4:	a4b8024c */ 	sh	$t8,0x24c($a1)
/*  f0ca7d8:	8e480284 */ 	lw	$t0,0x284($s2)
/*  f0ca7dc:	2419fffe */ 	addiu	$t9,$zero,-2
/*  f0ca7e0:	a519024e */ 	sh	$t9,0x24e($t0)
.L0f0ca7e4:
/*  f0ca7e4:	8e450284 */ 	lw	$a1,0x284($s2)
.L0f0ca7e8:
/*  f0ca7e8:	97ac01a2 */ 	lhu	$t4,0x1a2($sp)
/*  f0ca7ec:	8ca90120 */ 	lw	$t1,0x120($a1)
/*  f0ca7f0:	01946824 */ 	and	$t5,$t4,$s4
/*  f0ca7f4:	afa90208 */ 	sw	$t1,0x208($sp)
/*  f0ca7f8:	8caa0120 */ 	lw	$t2,0x120($a1)
/*  f0ca7fc:	afaa020c */ 	sw	$t2,0x20c($sp)
/*  f0ca800:	8cab0274 */ 	lw	$t3,0x274($a1)
/*  f0ca804:	11600004 */ 	beqz	$t3,.L0f0ca818
/*  f0ca808:	00000000 */ 	nop
/*  f0ca80c:	15a00002 */ 	bnez	$t5,.L0f0ca818
/*  f0ca810:	00000000 */ 	nop
/*  f0ca814:	aca00274 */ 	sw	$zero,0x274($a1)
.L0f0ca818:
/*  f0ca818:	0fc2866a */ 	jal	bgunGetWeaponNum
/*  f0ca81c:	00002025 */ 	or	$a0,$zero,$zero
/*  f0ca820:	00402025 */ 	or	$a0,$v0,$zero
/*  f0ca824:	0fc2c5f0 */ 	jal	weaponHasFlag
/*  f0ca828:	3c058000 */ 	lui	$a1,0x8000
/*  f0ca82c:	1040000d */ 	beqz	$v0,.L0f0ca864
/*  f0ca830:	97ae01a0 */ 	lhu	$t6,0x1a0($sp)
/*  f0ca834:	01d47824 */ 	and	$t7,$t6,$s4
/*  f0ca838:	11e00008 */ 	beqz	$t7,.L0f0ca85c
/*  f0ca83c:	00000000 */ 	nop
/*  f0ca840:	8e580284 */ 	lw	$t8,0x284($s2)
/*  f0ca844:	8fa801c0 */ 	lw	$t0,0x1c0($sp)
/*  f0ca848:	8f191a24 */ 	lw	$t9,0x1a24($t8)
/*  f0ca84c:	25090001 */ 	addiu	$t1,$t0,0x1
/*  f0ca850:	17200002 */ 	bnez	$t9,.L0f0ca85c
/*  f0ca854:	00000000 */ 	nop
/*  f0ca858:	afa901c0 */ 	sw	$t1,0x1c0($sp)
.L0f0ca85c:
/*  f0ca85c:	10000014 */ 	b	.L0f0ca8b0
/*  f0ca860:	8e450284 */ 	lw	$a1,0x284($s2)
.L0f0ca864:
/*  f0ca864:	8e450284 */ 	lw	$a1,0x284($s2)
/*  f0ca868:	97a301a2 */ 	lhu	$v1,0x1a2($sp)
/*  f0ca86c:	8ca40274 */ 	lw	$a0,0x274($a1)
/*  f0ca870:	00741024 */ 	and	$v0,$v1,$s4
/*  f0ca874:	2c8a0001 */ 	sltiu	$t2,$a0,0x1
/*  f0ca878:	1140000c */ 	beqz	$t2,.L0f0ca8ac
/*  f0ca87c:	01402025 */ 	or	$a0,$t2,$zero
/*  f0ca880:	0002202b */ 	sltu	$a0,$zero,$v0
/*  f0ca884:	5080000a */ 	beqzl	$a0,.L0f0ca8b0
/*  f0ca888:	afa401bc */ 	sw	$a0,0x1bc($sp)
/*  f0ca88c:	8ca41a24 */ 	lw	$a0,0x1a24($a1)
/*  f0ca890:	97ad00ca */ 	lhu	$t5,0xca($sp)
/*  f0ca894:	2c8c0001 */ 	sltiu	$t4,$a0,0x1
/*  f0ca898:	11800004 */ 	beqz	$t4,.L0f0ca8ac
/*  f0ca89c:	01802025 */ 	or	$a0,$t4,$zero
/*  f0ca8a0:	006d2024 */ 	and	$a0,$v1,$t5
/*  f0ca8a4:	2c8e0001 */ 	sltiu	$t6,$a0,0x1
/*  f0ca8a8:	01c02025 */ 	or	$a0,$t6,$zero
.L0f0ca8ac:
/*  f0ca8ac:	afa401bc */ 	sw	$a0,0x1bc($sp)
.L0f0ca8b0:
/*  f0ca8b0:	8faf01b0 */ 	lw	$t7,0x1b0($sp)
/*  f0ca8b4:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0ca8b8:	24180001 */ 	addiu	$t8,$zero,0x1
/*  f0ca8bc:	11e10003 */ 	beq	$t7,$at,.L0f0ca8cc
/*  f0ca8c0:	24010003 */ 	addiu	$at,$zero,0x3
/*  f0ca8c4:	55e10003 */ 	bnel	$t7,$at,.L0f0ca8d4
/*  f0ca8c8:	aca000d0 */ 	sw	$zero,0xd0($a1)
.L0f0ca8cc:
/*  f0ca8cc:	afb8023c */ 	sw	$t8,0x23c($sp)
.L0f0ca8d0:
/*  f0ca8d0:	aca000d0 */ 	sw	$zero,0xd0($a1)
.L0f0ca8d4:
/*  f0ca8d4:	8fb901c0 */ 	lw	$t9,0x1c0($sp)
/*  f0ca8d8:	5320000c */ 	beqzl	$t9,.L0f0ca90c
/*  f0ca8dc:	8fad0238 */ 	lw	$t5,0x238($sp)
/*  f0ca8e0:	8e450284 */ 	lw	$a1,0x284($s2)
/*  f0ca8e4:	8ca801a0 */ 	lw	$t0,0x1a0($a1)
/*  f0ca8e8:	aca8019c */ 	sw	$t0,0x19c($a1)
/*  f0ca8ec:	8e4a0284 */ 	lw	$t2,0x284($s2)
/*  f0ca8f0:	8e490008 */ 	lw	$t1,0x8($s2)
/*  f0ca8f4:	ad4901a0 */ 	sw	$t1,0x1a0($t2)
/*  f0ca8f8:	8e4c0284 */ 	lw	$t4,0x284($s2)
/*  f0ca8fc:	8fab01c0 */ 	lw	$t3,0x1c0($sp)
/*  f0ca900:	0fc31fcb */ 	jal	bmoveHandleActivate
/*  f0ca904:	ad8b00d0 */ 	sw	$t3,0xd0($t4)
/*  f0ca908:	8fad0238 */ 	lw	$t5,0x238($sp)
.L0f0ca90c:
/*  f0ca90c:	15a0000b */ 	bnez	$t5,.L0f0ca93c
/*  f0ca910:	00000000 */ 	nop
/*  f0ca914:	8fa4024c */ 	lw	$a0,0x24c($sp)
/*  f0ca918:	8fae0254 */ 	lw	$t6,0x254($sp)
/*  f0ca91c:	c7a001ec */ 	lwc1	$f0,0x1ec($sp)
/*  f0ca920:	c7a401f0 */ 	lwc1	$f4,0x1f0($sp)
/*  f0ca924:	00042023 */ 	negu	$a0,$a0
/*  f0ca928:	000e7823 */ 	negu	$t7,$t6
/*  f0ca92c:	afaf0254 */ 	sw	$t7,0x254($sp)
/*  f0ca930:	afa4024c */ 	sw	$a0,0x24c($sp)
/*  f0ca934:	e7a001f0 */ 	swc1	$f0,0x1f0($sp)
/*  f0ca938:	e7a401ec */ 	swc1	$f4,0x1ec($sp)
.L0f0ca93c:
/*  f0ca93c:	0fc2a34d */ 	jal	bgunsTick
/*  f0ca940:	8fa401bc */ 	lw	$a0,0x1bc($sp)
/*  f0ca944:	8e580324 */ 	lw	$t8,0x324($s2)
/*  f0ca948:	5300002b */ 	beqzl	$t8,.L0f0ca9f8
/*  f0ca94c:	24040002 */ 	addiu	$a0,$zero,0x2
/*  f0ca950:	0fc2883f */ 	jal	bgunIsFiring
/*  f0ca954:	00002025 */ 	or	$a0,$zero,$zero
/*  f0ca958:	54400006 */ 	bnezl	$v0,.L0f0ca974
/*  f0ca95c:	44805000 */ 	mtc1	$zero,$f10
/*  f0ca960:	0fc2883f */ 	jal	bgunIsFiring
/*  f0ca964:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f0ca968:	50400023 */ 	beqzl	$v0,.L0f0ca9f8
/*  f0ca96c:	24040002 */ 	addiu	$a0,$zero,0x2
/*  f0ca970:	44805000 */ 	mtc1	$zero,$f10
.L0f0ca974:
/*  f0ca974:	00002025 */ 	or	$a0,$zero,$zero
/*  f0ca978:	0fc2883f */ 	jal	bgunIsFiring
/*  f0ca97c:	e7aa00b4 */ 	swc1	$f10,0xb4($sp)
/*  f0ca980:	1040000c */ 	beqz	$v0,.L0f0ca9b4
/*  f0ca984:	00000000 */ 	nop
/*  f0ca988:	0fc273d6 */ 	jal	bgunGetNoiseRadius
/*  f0ca98c:	00002025 */ 	or	$a0,$zero,$zero
/*  f0ca990:	44803000 */ 	mtc1	$zero,$f6
/*  f0ca994:	00000000 */ 	nop
/*  f0ca998:	4600303c */ 	c.lt.s	$f6,$f0
/*  f0ca99c:	00000000 */ 	nop
/*  f0ca9a0:	45000004 */ 	bc1f	.L0f0ca9b4
/*  f0ca9a4:	00000000 */ 	nop
/*  f0ca9a8:	0fc273d6 */ 	jal	bgunGetNoiseRadius
/*  f0ca9ac:	00002025 */ 	or	$a0,$zero,$zero
/*  f0ca9b0:	e7a000b4 */ 	swc1	$f0,0xb4($sp)
.L0f0ca9b4:
/*  f0ca9b4:	0fc2883f */ 	jal	bgunIsFiring
/*  f0ca9b8:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f0ca9bc:	1040000b */ 	beqz	$v0,.L0f0ca9ec
/*  f0ca9c0:	00000000 */ 	nop
/*  f0ca9c4:	0fc273d6 */ 	jal	bgunGetNoiseRadius
/*  f0ca9c8:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f0ca9cc:	c7a800b4 */ 	lwc1	$f8,0xb4($sp)
/*  f0ca9d0:	4600403c */ 	c.lt.s	$f8,$f0
/*  f0ca9d4:	00000000 */ 	nop
/*  f0ca9d8:	45000004 */ 	bc1f	.L0f0ca9ec
/*  f0ca9dc:	00000000 */ 	nop
/*  f0ca9e0:	0fc273d6 */ 	jal	bgunGetNoiseRadius
/*  f0ca9e4:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f0ca9e8:	e7a000b4 */ 	swc1	$f0,0xb4($sp)
.L0f0ca9ec:
/*  f0ca9ec:	0fc0a164 */ 	jal	func0f028590
/*  f0ca9f0:	c7ac00b4 */ 	lwc1	$f12,0xb4($sp)
/*  f0ca9f4:	24040002 */ 	addiu	$a0,$zero,0x2
.L0f0ca9f8:
/*  f0ca9f8:	0fc2af1d */ 	jal	bgunSetSightVisible
/*  f0ca9fc:	8fa50208 */ 	lw	$a1,0x208($sp)
/*  f0caa00:	c7ac0210 */ 	lwc1	$f12,0x210($sp)
/*  f0caa04:	44808000 */ 	mtc1	$zero,$f16
/*  f0caa08:	00000000 */ 	nop
/*  f0caa0c:	460c803c */ 	c.lt.s	$f16,$f12
/*  f0caa10:	00000000 */ 	nop
/*  f0caa14:	45020004 */ 	bc1fl	.L0f0caa28
/*  f0caa18:	c7ac0214 */ 	lwc1	$f12,0x214($sp)
/*  f0caa1c:	0fc2c562 */ 	jal	currentPlayerZoomOut
/*  f0caa20:	e7ac0210 */ 	swc1	$f12,0x210($sp)
/*  f0caa24:	c7ac0214 */ 	lwc1	$f12,0x214($sp)
.L0f0caa28:
/*  f0caa28:	44809000 */ 	mtc1	$zero,$f18
/*  f0caa2c:	00000000 */ 	nop
/*  f0caa30:	460c903c */ 	c.lt.s	$f18,$f12
/*  f0caa34:	00000000 */ 	nop
/*  f0caa38:	45020004 */ 	bc1fl	.L0f0caa4c
/*  f0caa3c:	8e590284 */ 	lw	$t9,0x284($s2)
/*  f0caa40:	0fc2c5a9 */ 	jal	currentPlayerZoomIn
/*  f0caa44:	e7ac0214 */ 	swc1	$f12,0x214($sp)
/*  f0caa48:	8e590284 */ 	lw	$t9,0x284($s2)
.L0f0caa4c:
/*  f0caa4c:	8f281a24 */ 	lw	$t0,0x1a24($t9)
/*  f0caa50:	150000b5 */ 	bnez	$t0,.L0f0cad28
/*  f0caa54:	3c098006 */ 	lui	$t1,%hi(g_MainIsEndscreen)
/*  f0caa58:	8d29d9d0 */ 	lw	$t1,%lo(g_MainIsEndscreen)($t1)
/*  f0caa5c:	3c014270 */ 	lui	$at,0x4270
/*  f0caa60:	152000b1 */ 	bnez	$t1,.L0f0cad28
/*  f0caa64:	00000000 */ 	nop
/*  f0caa68:	44812000 */ 	mtc1	$at,$f4
/*  f0caa6c:	00002025 */ 	or	$a0,$zero,$zero
/*  f0caa70:	0fc2866a */ 	jal	bgunGetWeaponNum
/*  f0caa74:	e7a400b0 */ 	swc1	$f4,0xb0($sp)
/*  f0caa78:	24010016 */ 	addiu	$at,$zero,0x16
/*  f0caa7c:	5441008b */ 	bnel	$v0,$at,.L0f0cacac
/*  f0caa80:	8fb8020c */ 	lw	$t8,0x20c($sp)
/*  f0caa84:	8e450284 */ 	lw	$a1,0x284($s2)
/*  f0caa88:	8fab0230 */ 	lw	$t3,0x230($sp)
/*  f0caa8c:	8caa0120 */ 	lw	$t2,0x120($a1)
/*  f0caa90:	51400086 */ 	beqzl	$t2,.L0f0cacac
/*  f0caa94:	8fb8020c */ 	lw	$t8,0x20c($sp)
/*  f0caa98:	55600006 */ 	bnezl	$t3,.L0f0caab4
/*  f0caa9c:	c4a00258 */ 	lwc1	$f0,0x258($a1)
/*  f0caaa0:	90ac063b */ 	lbu	$t4,0x63b($a1)
/*  f0caaa4:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0caaa8:	55810080 */ 	bnel	$t4,$at,.L0f0cacac
/*  f0caaac:	8fb8020c */ 	lw	$t8,0x20c($sp)
/*  f0caab0:	c4a00258 */ 	lwc1	$f0,0x258($a1)
.L0f0caab4:
/*  f0caab4:	44805000 */ 	mtc1	$zero,$f10
/*  f0caab8:	3c0143fa */ 	lui	$at,0x43fa
/*  f0caabc:	4600503c */ 	c.lt.s	$f10,$f0
/*  f0caac0:	00000000 */ 	nop
/*  f0caac4:	45020079 */ 	bc1fl	.L0f0cacac
/*  f0caac8:	8fb8020c */ 	lw	$t8,0x20c($sp)
/*  f0caacc:	44813000 */ 	mtc1	$at,$f6
/*  f0caad0:	0fc2d26e */ 	jal	func0f0b49b8
/*  f0caad4:	46003303 */ 	div.s	$f12,$f6,$f0
/*  f0caad8:	3c014270 */ 	lui	$at,0x4270
/*  f0caadc:	44816000 */ 	mtc1	$at,$f12
/*  f0caae0:	46000086 */ 	mov.s	$f2,$f0
/*  f0caae4:	3c014000 */ 	lui	$at,0x4000
/*  f0caae8:	4600603c */ 	c.lt.s	$f12,$f0
/*  f0caaec:	44810000 */ 	mtc1	$at,$f0
/*  f0caaf0:	45020003 */ 	bc1fl	.L0f0cab00
/*  f0caaf4:	4600103c */ 	c.lt.s	$f2,$f0
/*  f0caaf8:	46006086 */ 	mov.s	$f2,$f12
/*  f0caafc:	4600103c */ 	c.lt.s	$f2,$f0
.L0f0cab00:
/*  f0cab00:	00000000 */ 	nop
/*  f0cab04:	45020003 */ 	bc1fl	.L0f0cab14
/*  f0cab08:	8e4d0284 */ 	lw	$t5,0x284($s2)
/*  f0cab0c:	46000086 */ 	mov.s	$f2,$f0
/*  f0cab10:	8e4d0284 */ 	lw	$t5,0x284($s2)
.L0f0cab14:
/*  f0cab14:	e5a216f8 */ 	swc1	$f2,0x16f8($t5)
/*  f0cab18:	0fc2d5be */ 	jal	currentPlayerGetMatrix1740
/*  f0cab1c:	e7a200ac */ 	swc1	$f2,0xac($sp)
/*  f0cab20:	8e4e0284 */ 	lw	$t6,0x284($s2)
/*  f0cab24:	27b000a0 */ 	addiu	$s0,$sp,0xa0
/*  f0cab28:	02003025 */ 	or	$a2,$s0,$zero
/*  f0cab2c:	8dc5025c */ 	lw	$a1,0x25c($t6)
/*  f0cab30:	00402025 */ 	or	$a0,$v0,$zero
/*  f0cab34:	0c0056da */ 	jal	func00015b68
/*  f0cab38:	24a50008 */ 	addiu	$a1,$a1,0x8
/*  f0cab3c:	c7a200ac */ 	lwc1	$f2,0xac($sp)
/*  f0cab40:	8e4f0284 */ 	lw	$t7,0x284($s2)
/*  f0cab44:	02002025 */ 	or	$a0,$s0,$zero
/*  f0cab48:	44061000 */ 	mfc1	$a2,$f2
/*  f0cab4c:	27a50098 */ 	addiu	$a1,$sp,0x98
/*  f0cab50:	0fc2d3ae */ 	jal	func0f0b4eb8
/*  f0cab54:	8de7171c */ 	lw	$a3,0x171c($t7)
/*  f0cab58:	0fc2d5fe */ 	jal	currentPlayerGetScreenLeft
/*  f0cab5c:	00000000 */ 	nop
/*  f0cab60:	0fc2d5f6 */ 	jal	currentPlayerGetScreenWidth
/*  f0cab64:	e7a00054 */ 	swc1	$f0,0x54($sp)
/*  f0cab68:	3c013f00 */ 	lui	$at,0x3f00
/*  f0cab6c:	44818000 */ 	mtc1	$at,$f16
/*  f0cab70:	c7a40054 */ 	lwc1	$f4,0x54($sp)
/*  f0cab74:	3c0141a0 */ 	lui	$at,0x41a0
/*  f0cab78:	46100482 */ 	mul.s	$f18,$f0,$f16
/*  f0cab7c:	44813000 */ 	mtc1	$at,$f6
/*  f0cab80:	c7a80098 */ 	lwc1	$f8,0x98($sp)
/*  f0cab84:	3c013e80 */ 	lui	$at,0x3e80
/*  f0cab88:	46049280 */ 	add.s	$f10,$f18,$f4
/*  f0cab8c:	46065401 */ 	sub.s	$f16,$f10,$f6
/*  f0cab90:	4610403c */ 	c.lt.s	$f8,$f16
/*  f0cab94:	00000000 */ 	nop
/*  f0cab98:	45000004 */ 	bc1f	.L0f0cabac
/*  f0cab9c:	00000000 */ 	nop
/*  f0caba0:	44816000 */ 	mtc1	$at,$f12
/*  f0caba4:	10000016 */ 	b	.L0f0cac00
/*  f0caba8:	e7ac01f4 */ 	swc1	$f12,0x1f4($sp)
.L0f0cabac:
/*  f0cabac:	0fc2d5fe */ 	jal	currentPlayerGetScreenLeft
/*  f0cabb0:	00000000 */ 	nop
/*  f0cabb4:	0fc2d5f6 */ 	jal	currentPlayerGetScreenWidth
/*  f0cabb8:	e7a00054 */ 	swc1	$f0,0x54($sp)
/*  f0cabbc:	3c013f00 */ 	lui	$at,0x3f00
/*  f0cabc0:	44819000 */ 	mtc1	$at,$f18
/*  f0cabc4:	c7aa0054 */ 	lwc1	$f10,0x54($sp)
/*  f0cabc8:	3c0141a0 */ 	lui	$at,0x41a0
/*  f0cabcc:	46120102 */ 	mul.s	$f4,$f0,$f18
/*  f0cabd0:	44814000 */ 	mtc1	$at,$f8
/*  f0cabd4:	c7b20098 */ 	lwc1	$f18,0x98($sp)
/*  f0cabd8:	3c013e80 */ 	lui	$at,0x3e80
/*  f0cabdc:	460a2180 */ 	add.s	$f6,$f4,$f10
/*  f0cabe0:	46083400 */ 	add.s	$f16,$f6,$f8
/*  f0cabe4:	4612803c */ 	c.lt.s	$f16,$f18
/*  f0cabe8:	00000000 */ 	nop
/*  f0cabec:	45000004 */ 	bc1f	.L0f0cac00
/*  f0cabf0:	00000000 */ 	nop
/*  f0cabf4:	44810000 */ 	mtc1	$at,$f0
/*  f0cabf8:	00000000 */ 	nop
/*  f0cabfc:	e7a001f8 */ 	swc1	$f0,0x1f8($sp)
.L0f0cac00:
/*  f0cac00:	0fc2d602 */ 	jal	currentPlayerGetScreenTop
/*  f0cac04:	00000000 */ 	nop
/*  f0cac08:	0fc2d5fa */ 	jal	currentPlayerGetScreenHeight
/*  f0cac0c:	e7a00054 */ 	swc1	$f0,0x54($sp)
/*  f0cac10:	3c013f00 */ 	lui	$at,0x3f00
/*  f0cac14:	44815000 */ 	mtc1	$at,$f10
/*  f0cac18:	c7a80054 */ 	lwc1	$f8,0x54($sp)
/*  f0cac1c:	3c0141a0 */ 	lui	$at,0x41a0
/*  f0cac20:	460a0182 */ 	mul.s	$f6,$f0,$f10
/*  f0cac24:	44819000 */ 	mtc1	$at,$f18
/*  f0cac28:	c7a4009c */ 	lwc1	$f4,0x9c($sp)
/*  f0cac2c:	3c013e80 */ 	lui	$at,0x3e80
/*  f0cac30:	46083400 */ 	add.s	$f16,$f6,$f8
/*  f0cac34:	46128281 */ 	sub.s	$f10,$f16,$f18
/*  f0cac38:	460a203c */ 	c.lt.s	$f4,$f10
/*  f0cac3c:	00000000 */ 	nop
/*  f0cac40:	45000004 */ 	bc1f	.L0f0cac54
/*  f0cac44:	00000000 */ 	nop
/*  f0cac48:	44813000 */ 	mtc1	$at,$f6
/*  f0cac4c:	10000016 */ 	b	.L0f0caca8
/*  f0cac50:	e7a601f0 */ 	swc1	$f6,0x1f0($sp)
.L0f0cac54:
/*  f0cac54:	0fc2d602 */ 	jal	currentPlayerGetScreenTop
/*  f0cac58:	00000000 */ 	nop
/*  f0cac5c:	0fc2d5fa */ 	jal	currentPlayerGetScreenHeight
/*  f0cac60:	e7a00054 */ 	swc1	$f0,0x54($sp)
/*  f0cac64:	3c013f00 */ 	lui	$at,0x3f00
/*  f0cac68:	44814000 */ 	mtc1	$at,$f8
/*  f0cac6c:	c7b20054 */ 	lwc1	$f18,0x54($sp)
/*  f0cac70:	3c0141a0 */ 	lui	$at,0x41a0
/*  f0cac74:	46080402 */ 	mul.s	$f16,$f0,$f8
/*  f0cac78:	44815000 */ 	mtc1	$at,$f10
/*  f0cac7c:	c7a8009c */ 	lwc1	$f8,0x9c($sp)
/*  f0cac80:	3c013e80 */ 	lui	$at,0x3e80
/*  f0cac84:	46128100 */ 	add.s	$f4,$f16,$f18
/*  f0cac88:	460a2180 */ 	add.s	$f6,$f4,$f10
/*  f0cac8c:	4608303c */ 	c.lt.s	$f6,$f8
/*  f0cac90:	00000000 */ 	nop
/*  f0cac94:	45020005 */ 	bc1fl	.L0f0cacac
/*  f0cac98:	8fb8020c */ 	lw	$t8,0x20c($sp)
/*  f0cac9c:	44818000 */ 	mtc1	$at,$f16
/*  f0caca0:	00000000 */ 	nop
/*  f0caca4:	e7b001ec */ 	swc1	$f16,0x1ec($sp)
.L0f0caca8:
/*  f0caca8:	8fb8020c */ 	lw	$t8,0x20c($sp)
.L0f0cacac:
/*  f0cacac:	13000004 */ 	beqz	$t8,.L0f0cacc0
/*  f0cacb0:	00000000 */ 	nop
/*  f0cacb4:	0fc2c536 */ 	jal	currentPlayerGetGunZoomFov
/*  f0cacb8:	00000000 */ 	nop
/*  f0cacbc:	e7a000b0 */ 	swc1	$f0,0xb0($sp)
.L0f0cacc0:
/*  f0cacc0:	0fc2866a */ 	jal	bgunGetWeaponNum
/*  f0cacc4:	00002025 */ 	or	$a0,$zero,$zero
/*  f0cacc8:	24010011 */ 	addiu	$at,$zero,0x11
/*  f0caccc:	5441000a */ 	bnel	$v0,$at,.L0f0cacf8
/*  f0cacd0:	c7ac00b0 */ 	lwc1	$f12,0xb0($sp)
/*  f0cacd4:	8e590284 */ 	lw	$t9,0x284($s2)
/*  f0cacd8:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0cacdc:	9328063b */ 	lbu	$t0,0x63b($t9)
/*  f0cace0:	55010005 */ 	bnel	$t0,$at,.L0f0cacf8
/*  f0cace4:	c7ac00b0 */ 	lwc1	$f12,0xb0($sp)
/*  f0cace8:	0fc2c536 */ 	jal	currentPlayerGetGunZoomFov
/*  f0cacec:	00000000 */ 	nop
/*  f0cacf0:	e7a000b0 */ 	swc1	$f0,0xb0($sp)
/*  f0cacf4:	c7ac00b0 */ 	lwc1	$f12,0xb0($sp)
.L0f0cacf8:
/*  f0cacf8:	44809000 */ 	mtc1	$zero,$f18
/*  f0cacfc:	3c014270 */ 	lui	$at,0x4270
/*  f0cad00:	4612603e */ 	c.le.s	$f12,$f18
/*  f0cad04:	00000000 */ 	nop
/*  f0cad08:	45000003 */ 	bc1f	.L0f0cad18
/*  f0cad0c:	00000000 */ 	nop
/*  f0cad10:	44816000 */ 	mtc1	$at,$f12
/*  f0cad14:	00000000 */ 	nop
.L0f0cad18:
/*  f0cad18:	0fc2ea2c */ 	jal	func0f0ba8b0
/*  f0cad1c:	00000000 */ 	nop
/*  f0cad20:	0fc2eab0 */ 	jal	currentPlayerUpdateZoom
/*  f0cad24:	00000000 */ 	nop
.L0f0cad28:
/*  f0cad28:	0fc31fe6 */ 	jal	bmoveApplyMoveData
/*  f0cad2c:	27a401b4 */ 	addiu	$a0,$sp,0x1b4
/*  f0cad30:	8e450284 */ 	lw	$a1,0x284($s2)
/*  f0cad34:	8ca90178 */ 	lw	$t1,0x178($a1)
/*  f0cad38:	292100b4 */ 	slti	$at,$t1,0xb4
/*  f0cad3c:	1420001b */ 	bnez	$at,.L0f0cadac
/*  f0cad40:	3c013fa0 */ 	lui	$at,0x3fa0
/*  f0cad44:	44811000 */ 	mtc1	$at,$f2
/*  f0cad48:	c4a00174 */ 	lwc1	$f0,0x174($a1)
/*  f0cad4c:	3c017f1b */ 	lui	$at,%hi(var7f1ad8b8)
/*  f0cad50:	4602003c */ 	c.lt.s	$f0,$f2
/*  f0cad54:	00000000 */ 	nop
/*  f0cad58:	45020009 */ 	bc1fl	.L0f0cad80
/*  f0cad5c:	4600103c */ 	c.lt.s	$f2,$f0
/*  f0cad60:	c424d8b8 */ 	lwc1	$f4,%lo(var7f1ad8b8)($at)
/*  f0cad64:	c64a004c */ 	lwc1	$f10,0x4c($s2)
/*  f0cad68:	460a2182 */ 	mul.s	$f6,$f4,$f10
/*  f0cad6c:	46060200 */ 	add.s	$f8,$f0,$f6
/*  f0cad70:	e4a80174 */ 	swc1	$f8,0x174($a1)
/*  f0cad74:	8e450284 */ 	lw	$a1,0x284($s2)
/*  f0cad78:	c4a00174 */ 	lwc1	$f0,0x174($a1)
/*  f0cad7c:	4600103c */ 	c.lt.s	$f2,$f0
.L0f0cad80:
/*  f0cad80:	00000000 */ 	nop
/*  f0cad84:	45020024 */ 	bc1fl	.L0f0cae18
/*  f0cad88:	8cab1a24 */ 	lw	$t3,0x1a24($a1)
/*  f0cad8c:	0fc20b5d */ 	jal	piracyRestore
/*  f0cad90:	00000000 */ 	nop
/*  f0cad94:	3c013fa0 */ 	lui	$at,0x3fa0
/*  f0cad98:	44811000 */ 	mtc1	$at,$f2
/*  f0cad9c:	8e4a0284 */ 	lw	$t2,0x284($s2)
/*  f0cada0:	e5420174 */ 	swc1	$f2,0x174($t2)
/*  f0cada4:	1000001b */ 	b	.L0f0cae14
/*  f0cada8:	8e450284 */ 	lw	$a1,0x284($s2)
.L0f0cadac:
/*  f0cadac:	3c013f80 */ 	lui	$at,0x3f80
/*  f0cadb0:	44818000 */ 	mtc1	$at,$f16
/*  f0cadb4:	c4a00174 */ 	lwc1	$f0,0x174($a1)
/*  f0cadb8:	3c017f1b */ 	lui	$at,%hi(var7f1ad8bc)
/*  f0cadbc:	4600803c */ 	c.lt.s	$f16,$f0
/*  f0cadc0:	00000000 */ 	nop
/*  f0cadc4:	45020009 */ 	bc1fl	.L0f0cadec
/*  f0cadc8:	3c013f80 */ 	lui	$at,0x3f80
/*  f0cadcc:	c432d8bc */ 	lwc1	$f18,%lo(var7f1ad8bc)($at)
/*  f0cadd0:	c644004c */ 	lwc1	$f4,0x4c($s2)
/*  f0cadd4:	46049282 */ 	mul.s	$f10,$f18,$f4
/*  f0cadd8:	460a0181 */ 	sub.s	$f6,$f0,$f10
/*  f0caddc:	e4a60174 */ 	swc1	$f6,0x174($a1)
/*  f0cade0:	8e450284 */ 	lw	$a1,0x284($s2)
/*  f0cade4:	c4a00174 */ 	lwc1	$f0,0x174($a1)
/*  f0cade8:	3c013f80 */ 	lui	$at,0x3f80
.L0f0cadec:
/*  f0cadec:	44814000 */ 	mtc1	$at,$f8
/*  f0cadf0:	3c013f80 */ 	lui	$at,0x3f80
/*  f0cadf4:	4608003c */ 	c.lt.s	$f0,$f8
/*  f0cadf8:	00000000 */ 	nop
/*  f0cadfc:	45020006 */ 	bc1fl	.L0f0cae18
/*  f0cae00:	8cab1a24 */ 	lw	$t3,0x1a24($a1)
/*  f0cae04:	44818000 */ 	mtc1	$at,$f16
/*  f0cae08:	00000000 */ 	nop
/*  f0cae0c:	e4b00174 */ 	swc1	$f16,0x174($a1)
/*  f0cae10:	8e450284 */ 	lw	$a1,0x284($s2)
.L0f0cae14:
/*  f0cae14:	8cab1a24 */ 	lw	$t3,0x1a24($a1)
.L0f0cae18:
/*  f0cae18:	55600144 */ 	bnezl	$t3,.L0f0cb32c
/*  f0cae1c:	8faa01cc */ 	lw	$t2,0x1cc($sp)
/*  f0cae20:	8ca201b0 */ 	lw	$v0,0x1b0($a1)
/*  f0cae24:	3c01c080 */ 	lui	$at,0xc080
/*  f0cae28:	44817000 */ 	mtc1	$at,$f14
/*  f0cae2c:	2c440001 */ 	sltiu	$a0,$v0,0x1
/*  f0cae30:	54800004 */ 	bnezl	$a0,.L0f0cae44
/*  f0cae34:	8cac0110 */ 	lw	$t4,0x110($a1)
/*  f0cae38:	38440004 */ 	xori	$a0,$v0,0x4
/*  f0cae3c:	2c840001 */ 	sltiu	$a0,$a0,0x1
/*  f0cae40:	8cac0110 */ 	lw	$t4,0x110($a1)
.L0f0cae44:
/*  f0cae44:	51800011 */ 	beqzl	$t4,.L0f0cae8c
/*  f0cae48:	8cb9010c */ 	lw	$t9,0x10c($a1)
/*  f0cae4c:	8e42000c */ 	lw	$v0,0xc($s2)
/*  f0cae50:	94ad1be4 */ 	lhu	$t5,0x1be4($a1)
/*  f0cae54:	504d000c */ 	beql	$v0,$t5,.L0f0cae88
/*  f0cae58:	c4ae1be0 */ 	lwc1	$f14,0x1be0($a1)
/*  f0cae5c:	8e4e028c */ 	lw	$t6,0x28c($s2)
/*  f0cae60:	304f0003 */ 	andi	$t7,$v0,0x3
/*  f0cae64:	55cf0008 */ 	bnel	$t6,$t7,.L0f0cae88
/*  f0cae68:	c4ae1be0 */ 	lwc1	$f14,0x1be0($a1)
/*  f0cae6c:	0fc32166 */ 	jal	bmoveCalculateLookahead
/*  f0cae70:	afa40064 */ 	sw	$a0,0x64($sp)
/*  f0cae74:	8e580284 */ 	lw	$t8,0x284($s2)
/*  f0cae78:	8fa40064 */ 	lw	$a0,0x64($sp)
/*  f0cae7c:	e7001be0 */ 	swc1	$f0,0x1be0($t8)
/*  f0cae80:	8e450284 */ 	lw	$a1,0x284($s2)
/*  f0cae84:	c4ae1be0 */ 	lwc1	$f14,0x1be0($a1)
.L0f0cae88:
/*  f0cae88:	8cb9010c */ 	lw	$t9,0x10c($a1)
.L0f0cae8c:
/*  f0cae8c:	8fa8025c */ 	lw	$t0,0x25c($sp)
/*  f0cae90:	13200007 */ 	beqz	$t9,.L0f0caeb0
/*  f0cae94:	29010028 */ 	slti	$at,$t0,0x28
/*  f0cae98:	10200005 */ 	beqz	$at,.L0f0caeb0
/*  f0cae9c:	2901ffd9 */ 	slti	$at,$t0,-39
/*  f0caea0:	14200003 */ 	bnez	$at,.L0f0caeb0
/*  f0caea4:	00000000 */ 	nop
/*  f0caea8:	aca0010c */ 	sw	$zero,0x10c($a1)
/*  f0caeac:	8e450284 */ 	lw	$a1,0x284($s2)
.L0f0caeb0:
/*  f0caeb0:	10800064 */ 	beqz	$a0,.L0f0cb044
/*  f0caeb4:	c7a401ec */ 	lwc1	$f4,0x1ec($sp)
/*  f0caeb8:	44809000 */ 	mtc1	$zero,$f18
/*  f0caebc:	c7a601f0 */ 	lwc1	$f6,0x1f0($sp)
/*  f0caec0:	4604903c */ 	c.lt.s	$f18,$f4
/*  f0caec4:	00000000 */ 	nop
/*  f0caec8:	45030008 */ 	bc1tl	.L0f0caeec
/*  f0caecc:	aca00100 */ 	sw	$zero,0x100($a1)
/*  f0caed0:	44805000 */ 	mtc1	$zero,$f10
/*  f0caed4:	8fac023c */ 	lw	$t4,0x23c($sp)
/*  f0caed8:	4606503c */ 	c.lt.s	$f10,$f6
/*  f0caedc:	00000000 */ 	nop
/*  f0caee0:	45000009 */ 	bc1f	.L0f0caf08
/*  f0caee4:	00000000 */ 	nop
/*  f0caee8:	aca00100 */ 	sw	$zero,0x100($a1)
.L0f0caeec:
/*  f0caeec:	8e4a0284 */ 	lw	$t2,0x284($s2)
/*  f0caef0:	24090001 */ 	addiu	$t1,$zero,0x1
/*  f0caef4:	ad490108 */ 	sw	$t1,0x108($t2)
/*  f0caef8:	8e4b0284 */ 	lw	$t3,0x284($s2)
/*  f0caefc:	ad60011c */ 	sw	$zero,0x11c($t3)
/*  f0caf00:	10000050 */ 	b	.L0f0cb044
/*  f0caf04:	8e450284 */ 	lw	$a1,0x284($s2)
.L0f0caf08:
/*  f0caf08:	51800005 */ 	beqzl	$t4,.L0f0caf20
/*  f0caf0c:	8cad0114 */ 	lw	$t5,0x114($a1)
/*  f0caf10:	aca0011c */ 	sw	$zero,0x11c($a1)
/*  f0caf14:	10000049 */ 	b	.L0f0cb03c
/*  f0caf18:	8e450284 */ 	lw	$a1,0x284($s2)
/*  f0caf1c:	8cad0114 */ 	lw	$t5,0x114($a1)
.L0f0caf20:
/*  f0caf20:	8fae01c4 */ 	lw	$t6,0x1c4($sp)
/*  f0caf24:	51a00026 */ 	beqzl	$t5,.L0f0cafc0
/*  f0caf28:	8caa0118 */ 	lw	$t2,0x118($a1)
/*  f0caf2c:	11c00009 */ 	beqz	$t6,.L0f0caf54
/*  f0caf30:	8faf025c */ 	lw	$t7,0x25c($sp)
/*  f0caf34:	29e1003d */ 	slti	$at,$t7,0x3d
/*  f0caf38:	10200004 */ 	beqz	$at,.L0f0caf4c
/*  f0caf3c:	24180001 */ 	addiu	$t8,$zero,0x1
/*  f0caf40:	29e1ffc4 */ 	slti	$at,$t7,-60
/*  f0caf44:	50200004 */ 	beqzl	$at,.L0f0caf58
/*  f0caf48:	8cb9011c */ 	lw	$t9,0x11c($a1)
.L0f0caf4c:
/*  f0caf4c:	acb8011c */ 	sw	$t8,0x11c($a1)
/*  f0caf50:	8e450284 */ 	lw	$a1,0x284($s2)
.L0f0caf54:
/*  f0caf54:	8cb9011c */ 	lw	$t9,0x11c($a1)
.L0f0caf58:
/*  f0caf58:	3c0140a0 */ 	lui	$at,0x40a0
/*  f0caf5c:	53200038 */ 	beqzl	$t9,.L0f0cb040
/*  f0caf60:	aca00108 */ 	sw	$zero,0x108($a1)
/*  f0caf64:	44814000 */ 	mtc1	$at,$f8
/*  f0caf68:	c4a00154 */ 	lwc1	$f0,0x154($a1)
/*  f0caf6c:	3c01c120 */ 	lui	$at,0xc120
/*  f0caf70:	46087400 */ 	add.s	$f16,$f14,$f8
/*  f0caf74:	4600803c */ 	c.lt.s	$f16,$f0
/*  f0caf78:	00000000 */ 	nop
/*  f0caf7c:	45030009 */ 	bc1tl	.L0f0cafa4
/*  f0caf80:	8ca8010c */ 	lw	$t0,0x10c($a1)
/*  f0caf84:	44819000 */ 	mtc1	$at,$f18
/*  f0caf88:	00000000 */ 	nop
/*  f0caf8c:	46127100 */ 	add.s	$f4,$f14,$f18
/*  f0caf90:	4604003c */ 	c.lt.s	$f0,$f4
/*  f0caf94:	00000000 */ 	nop
/*  f0caf98:	45020029 */ 	bc1fl	.L0f0cb040
/*  f0caf9c:	aca00108 */ 	sw	$zero,0x108($a1)
/*  f0cafa0:	8ca8010c */ 	lw	$t0,0x10c($a1)
.L0f0cafa4:
/*  f0cafa4:	24090001 */ 	addiu	$t1,$zero,0x1
/*  f0cafa8:	55000025 */ 	bnezl	$t0,.L0f0cb040
/*  f0cafac:	aca00108 */ 	sw	$zero,0x108($a1)
/*  f0cafb0:	aca90100 */ 	sw	$t1,0x100($a1)
/*  f0cafb4:	10000021 */ 	b	.L0f0cb03c
/*  f0cafb8:	8e450284 */ 	lw	$a1,0x284($s2)
/*  f0cafbc:	8caa0118 */ 	lw	$t2,0x118($a1)
.L0f0cafc0:
/*  f0cafc0:	8fab01c4 */ 	lw	$t3,0x1c4($sp)
/*  f0cafc4:	5140001e */ 	beqzl	$t2,.L0f0cb040
/*  f0cafc8:	aca00108 */ 	sw	$zero,0x108($a1)
/*  f0cafcc:	1160001b */ 	beqz	$t3,.L0f0cb03c
/*  f0cafd0:	8fac025c */ 	lw	$t4,0x25c($sp)
/*  f0cafd4:	2981003d */ 	slti	$at,$t4,0x3d
/*  f0cafd8:	10200002 */ 	beqz	$at,.L0f0cafe4
/*  f0cafdc:	2981ffc4 */ 	slti	$at,$t4,-60
/*  f0cafe0:	10200016 */ 	beqz	$at,.L0f0cb03c
.L0f0cafe4:
/*  f0cafe4:	3c0140a0 */ 	lui	$at,0x40a0
/*  f0cafe8:	44815000 */ 	mtc1	$at,$f10
/*  f0cafec:	c4a00154 */ 	lwc1	$f0,0x154($a1)
/*  f0caff0:	3c01c120 */ 	lui	$at,0xc120
/*  f0caff4:	460a7180 */ 	add.s	$f6,$f14,$f10
/*  f0caff8:	4600303c */ 	c.lt.s	$f6,$f0
/*  f0caffc:	00000000 */ 	nop
/*  f0cb000:	45030009 */ 	bc1tl	.L0f0cb028
/*  f0cb004:	8cad010c */ 	lw	$t5,0x10c($a1)
/*  f0cb008:	44814000 */ 	mtc1	$at,$f8
/*  f0cb00c:	00000000 */ 	nop
/*  f0cb010:	46087400 */ 	add.s	$f16,$f14,$f8
/*  f0cb014:	4610003c */ 	c.lt.s	$f0,$f16
/*  f0cb018:	00000000 */ 	nop
/*  f0cb01c:	45020008 */ 	bc1fl	.L0f0cb040
/*  f0cb020:	aca00108 */ 	sw	$zero,0x108($a1)
/*  f0cb024:	8cad010c */ 	lw	$t5,0x10c($a1)
.L0f0cb028:
/*  f0cb028:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f0cb02c:	55a00004 */ 	bnezl	$t5,.L0f0cb040
/*  f0cb030:	aca00108 */ 	sw	$zero,0x108($a1)
/*  f0cb034:	acae0100 */ 	sw	$t6,0x100($a1)
/*  f0cb038:	8e450284 */ 	lw	$a1,0x284($s2)
.L0f0cb03c:
/*  f0cb03c:	aca00108 */ 	sw	$zero,0x108($a1)
.L0f0cb040:
/*  f0cb040:	8e450284 */ 	lw	$a1,0x284($s2)
.L0f0cb044:
/*  f0cb044:	8caf01b0 */ 	lw	$t7,0x1b0($a1)
/*  f0cb048:	24010003 */ 	addiu	$at,$zero,0x3
/*  f0cb04c:	55e10004 */ 	bnel	$t7,$at,.L0f0cb060
/*  f0cb050:	8cb80100 */ 	lw	$t8,0x100($a1)
/*  f0cb054:	aca00100 */ 	sw	$zero,0x100($a1)
/*  f0cb058:	8e450284 */ 	lw	$a1,0x284($s2)
/*  f0cb05c:	8cb80100 */ 	lw	$t8,0x100($a1)
.L0f0cb060:
/*  f0cb060:	8fa901d0 */ 	lw	$t1,0x1d0($sp)
/*  f0cb064:	1300004a */ 	beqz	$t8,.L0f0cb190
/*  f0cb068:	00000000 */ 	nop
/*  f0cb06c:	508000af */ 	beqzl	$a0,.L0f0cb32c
/*  f0cb070:	8faa01cc */ 	lw	$t2,0x1cc($sp)
/*  f0cb074:	c4a2015c */ 	lwc1	$f2,0x15c($a1)
/*  f0cb078:	3c013f00 */ 	lui	$at,0x3f00
/*  f0cb07c:	44812000 */ 	mtc1	$at,$f4
/*  f0cb080:	46021482 */ 	mul.s	$f18,$f2,$f2
/*  f0cb084:	3c017f1b */ 	lui	$at,%hi(var7f1ad8c0)
/*  f0cb088:	c426d8c0 */ 	lwc1	$f6,%lo(var7f1ad8c0)($at)
/*  f0cb08c:	c4a00154 */ 	lwc1	$f0,0x154($a1)
/*  f0cb090:	3c013f80 */ 	lui	$at,0x3f80
/*  f0cb094:	46049282 */ 	mul.s	$f10,$f18,$f4
/*  f0cb098:	46065303 */ 	div.s	$f12,$f10,$f6
/*  f0cb09c:	460c7200 */ 	add.s	$f8,$f14,$f12
/*  f0cb0a0:	4600403c */ 	c.lt.s	$f8,$f0
/*  f0cb0a4:	00000000 */ 	nop
/*  f0cb0a8:	45020007 */ 	bc1fl	.L0f0cb0c8
/*  f0cb0ac:	460c7401 */ 	sub.s	$f16,$f14,$f12
/*  f0cb0b0:	44816000 */ 	mtc1	$at,$f12
/*  f0cb0b4:	0fc3203e */ 	jal	bmoveUpdateSpeedVerta
/*  f0cb0b8:	e7ae0094 */ 	swc1	$f14,0x94($sp)
/*  f0cb0bc:	10000010 */ 	b	.L0f0cb100
/*  f0cb0c0:	c7ae0094 */ 	lwc1	$f14,0x94($sp)
/*  f0cb0c4:	460c7401 */ 	sub.s	$f16,$f14,$f12
.L0f0cb0c8:
/*  f0cb0c8:	3c01bf80 */ 	lui	$at,0xbf80
/*  f0cb0cc:	4610003c */ 	c.lt.s	$f0,$f16
/*  f0cb0d0:	00000000 */ 	nop
/*  f0cb0d4:	45020007 */ 	bc1fl	.L0f0cb0f4
/*  f0cb0d8:	44806000 */ 	mtc1	$zero,$f12
/*  f0cb0dc:	44816000 */ 	mtc1	$at,$f12
/*  f0cb0e0:	0fc3203e */ 	jal	bmoveUpdateSpeedVerta
/*  f0cb0e4:	e7ae0094 */ 	swc1	$f14,0x94($sp)
/*  f0cb0e8:	10000005 */ 	b	.L0f0cb100
/*  f0cb0ec:	c7ae0094 */ 	lwc1	$f14,0x94($sp)
/*  f0cb0f0:	44806000 */ 	mtc1	$zero,$f12
.L0f0cb0f4:
/*  f0cb0f4:	0fc3203e */ 	jal	bmoveUpdateSpeedVerta
/*  f0cb0f8:	e7ae0094 */ 	swc1	$f14,0x94($sp)
/*  f0cb0fc:	c7ae0094 */ 	lwc1	$f14,0x94($sp)
.L0f0cb100:
/*  f0cb100:	8e450284 */ 	lw	$a1,0x284($s2)
/*  f0cb104:	c644004c */ 	lwc1	$f4,0x4c($s2)
/*  f0cb108:	c4b2015c */ 	lwc1	$f18,0x15c($a1)
/*  f0cb10c:	c4a00154 */ 	lwc1	$f0,0x154($a1)
/*  f0cb110:	46049082 */ 	mul.s	$f2,$f18,$f4
/*  f0cb114:	4600703c */ 	c.lt.s	$f14,$f0
/*  f0cb118:	46021280 */ 	add.s	$f10,$f2,$f2
/*  f0cb11c:	45000007 */ 	bc1f	.L0f0cb13c
/*  f0cb120:	460a0300 */ 	add.s	$f12,$f0,$f10
/*  f0cb124:	460c703c */ 	c.lt.s	$f14,$f12
/*  f0cb128:	00000000 */ 	nop
/*  f0cb12c:	45020004 */ 	bc1fl	.L0f0cb140
/*  f0cb130:	460e003c */ 	c.lt.s	$f0,$f14
/*  f0cb134:	1000007c */ 	b	.L0f0cb328
/*  f0cb138:	e4ac0154 */ 	swc1	$f12,0x154($a1)
.L0f0cb13c:
/*  f0cb13c:	460e003c */ 	c.lt.s	$f0,$f14
.L0f0cb140:
/*  f0cb140:	00000000 */ 	nop
/*  f0cb144:	45020008 */ 	bc1fl	.L0f0cb168
/*  f0cb148:	e4ae0154 */ 	swc1	$f14,0x154($a1)
/*  f0cb14c:	460e603c */ 	c.lt.s	$f12,$f14
/*  f0cb150:	00000000 */ 	nop
/*  f0cb154:	45020004 */ 	bc1fl	.L0f0cb168
/*  f0cb158:	e4ae0154 */ 	swc1	$f14,0x154($a1)
/*  f0cb15c:	10000072 */ 	b	.L0f0cb328
/*  f0cb160:	e4ac0154 */ 	swc1	$f12,0x154($a1)
/*  f0cb164:	e4ae0154 */ 	swc1	$f14,0x154($a1)
.L0f0cb168:
/*  f0cb168:	8e590284 */ 	lw	$t9,0x284($s2)
/*  f0cb16c:	44803000 */ 	mtc1	$zero,$f6
/*  f0cb170:	00000000 */ 	nop
/*  f0cb174:	e726015c */ 	swc1	$f6,0x15c($t9)
/*  f0cb178:	8e450284 */ 	lw	$a1,0x284($s2)
/*  f0cb17c:	8ca80108 */ 	lw	$t0,0x108($a1)
/*  f0cb180:	5500006a */ 	bnezl	$t0,.L0f0cb32c
/*  f0cb184:	8faa01cc */ 	lw	$t2,0x1cc($sp)
/*  f0cb188:	10000067 */ 	b	.L0f0cb328
/*  f0cb18c:	aca00100 */ 	sw	$zero,0x100($a1)
.L0f0cb190:
/*  f0cb190:	1120002f */ 	beqz	$t1,.L0f0cb250
/*  f0cb194:	c7a601ec */ 	lwc1	$f6,0x1ec($sp)
/*  f0cb198:	0c002f9d */ 	jal	viGetFovY
/*  f0cb19c:	00000000 */ 	nop
/*  f0cb1a0:	8faa0254 */ 	lw	$t2,0x254($sp)
/*  f0cb1a4:	3c014270 */ 	lui	$at,0x4270
/*  f0cb1a8:	44814000 */ 	mtc1	$at,$f8
/*  f0cb1ac:	448a8000 */ 	mtc1	$t2,$f16
/*  f0cb1b0:	3c01428c */ 	lui	$at,0x428c
/*  f0cb1b4:	44812000 */ 	mtc1	$at,$f4
/*  f0cb1b8:	468084a0 */ 	cvt.s.w	$f18,$f16
/*  f0cb1bc:	3c013f80 */ 	lui	$at,0x3f80
/*  f0cb1c0:	44815000 */ 	mtc1	$at,$f10
/*  f0cb1c4:	3c01bf80 */ 	lui	$at,0xbf80
/*  f0cb1c8:	46080383 */ 	div.s	$f14,$f0,$f8
/*  f0cb1cc:	44804000 */ 	mtc1	$zero,$f8
/*  f0cb1d0:	46049303 */ 	div.s	$f12,$f18,$f4
/*  f0cb1d4:	460c503c */ 	c.lt.s	$f10,$f12
/*  f0cb1d8:	46006086 */ 	mov.s	$f2,$f12
/*  f0cb1dc:	45020006 */ 	bc1fl	.L0f0cb1f8
/*  f0cb1e0:	44813000 */ 	mtc1	$at,$f6
/*  f0cb1e4:	3c013f80 */ 	lui	$at,0x3f80
/*  f0cb1e8:	44811000 */ 	mtc1	$at,$f2
/*  f0cb1ec:	1000000a */ 	b	.L0f0cb218
/*  f0cb1f0:	4602403e */ 	c.le.s	$f8,$f2
/*  f0cb1f4:	44813000 */ 	mtc1	$at,$f6
.L0f0cb1f8:
/*  f0cb1f8:	3c01bf80 */ 	lui	$at,0xbf80
/*  f0cb1fc:	4606603c */ 	c.lt.s	$f12,$f6
/*  f0cb200:	00000000 */ 	nop
/*  f0cb204:	45020004 */ 	bc1fl	.L0f0cb218
/*  f0cb208:	4602403e */ 	c.le.s	$f8,$f2
/*  f0cb20c:	44811000 */ 	mtc1	$at,$f2
/*  f0cb210:	00000000 */ 	nop
/*  f0cb214:	4602403e */ 	c.le.s	$f8,$f2
.L0f0cb218:
/*  f0cb218:	00000000 */ 	nop
/*  f0cb21c:	45020005 */ 	bc1fl	.L0f0cb234
/*  f0cb220:	46001407 */ 	neg.s	$f16,$f2
/*  f0cb224:	46021082 */ 	mul.s	$f2,$f2,$f2
/*  f0cb228:	10000005 */ 	b	.L0f0cb240
/*  f0cb22c:	46001487 */ 	neg.s	$f18,$f2
/*  f0cb230:	46001407 */ 	neg.s	$f16,$f2
.L0f0cb234:
/*  f0cb234:	46101082 */ 	mul.s	$f2,$f2,$f16
/*  f0cb238:	00000000 */ 	nop
/*  f0cb23c:	46001487 */ 	neg.s	$f18,$f2
.L0f0cb240:
/*  f0cb240:	8e4b0284 */ 	lw	$t3,0x284($s2)
/*  f0cb244:	460e9102 */ 	mul.s	$f4,$f18,$f14
/*  f0cb248:	1000002c */ 	b	.L0f0cb2fc
/*  f0cb24c:	e564015c */ 	swc1	$f4,0x15c($t3)
.L0f0cb250:
/*  f0cb250:	44805000 */ 	mtc1	$zero,$f10
/*  f0cb254:	c7b001f0 */ 	lwc1	$f16,0x1f0($sp)
/*  f0cb258:	4606503c */ 	c.lt.s	$f10,$f6
/*  f0cb25c:	00000000 */ 	nop
/*  f0cb260:	45020010 */ 	bc1fl	.L0f0cb2a4
/*  f0cb264:	44804000 */ 	mtc1	$zero,$f8
/*  f0cb268:	0fc3203e */ 	jal	bmoveUpdateSpeedVerta
/*  f0cb26c:	46003306 */ 	mov.s	$f12,$f6
/*  f0cb270:	8fac01c4 */ 	lw	$t4,0x1c4($sp)
/*  f0cb274:	8fad025c */ 	lw	$t5,0x25c($sp)
/*  f0cb278:	11800020 */ 	beqz	$t4,.L0f0cb2fc
/*  f0cb27c:	29a1003d */ 	slti	$at,$t5,0x3d
/*  f0cb280:	10200003 */ 	beqz	$at,.L0f0cb290
/*  f0cb284:	29a1ffc4 */ 	slti	$at,$t5,-60
/*  f0cb288:	5020001d */ 	beqzl	$at,.L0f0cb300
/*  f0cb28c:	8e450284 */ 	lw	$a1,0x284($s2)
.L0f0cb290:
/*  f0cb290:	8e4f0284 */ 	lw	$t7,0x284($s2)
/*  f0cb294:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f0cb298:	10000018 */ 	b	.L0f0cb2fc
/*  f0cb29c:	adee010c */ 	sw	$t6,0x10c($t7)
/*  f0cb2a0:	44804000 */ 	mtc1	$zero,$f8
.L0f0cb2a4:
/*  f0cb2a4:	00000000 */ 	nop
/*  f0cb2a8:	4610403c */ 	c.lt.s	$f8,$f16
/*  f0cb2ac:	00000000 */ 	nop
/*  f0cb2b0:	45020010 */ 	bc1fl	.L0f0cb2f4
/*  f0cb2b4:	44806000 */ 	mtc1	$zero,$f12
/*  f0cb2b8:	0fc3203e */ 	jal	bmoveUpdateSpeedVerta
/*  f0cb2bc:	46008307 */ 	neg.s	$f12,$f16
/*  f0cb2c0:	8fb801c4 */ 	lw	$t8,0x1c4($sp)
/*  f0cb2c4:	8fb9025c */ 	lw	$t9,0x25c($sp)
/*  f0cb2c8:	1300000c */ 	beqz	$t8,.L0f0cb2fc
/*  f0cb2cc:	2b21003d */ 	slti	$at,$t9,0x3d
/*  f0cb2d0:	10200003 */ 	beqz	$at,.L0f0cb2e0
/*  f0cb2d4:	2b21ffc4 */ 	slti	$at,$t9,-60
/*  f0cb2d8:	50200009 */ 	beqzl	$at,.L0f0cb300
/*  f0cb2dc:	8e450284 */ 	lw	$a1,0x284($s2)
.L0f0cb2e0:
/*  f0cb2e0:	8e490284 */ 	lw	$t1,0x284($s2)
/*  f0cb2e4:	24080001 */ 	addiu	$t0,$zero,0x1
/*  f0cb2e8:	10000004 */ 	b	.L0f0cb2fc
/*  f0cb2ec:	ad28010c */ 	sw	$t0,0x10c($t1)
/*  f0cb2f0:	44806000 */ 	mtc1	$zero,$f12
.L0f0cb2f4:
/*  f0cb2f4:	0fc3203e */ 	jal	bmoveUpdateSpeedVerta
/*  f0cb2f8:	00000000 */ 	nop
.L0f0cb2fc:
/*  f0cb2fc:	8e450284 */ 	lw	$a1,0x284($s2)
.L0f0cb300:
/*  f0cb300:	c644004c */ 	lwc1	$f4,0x4c($s2)
/*  f0cb304:	3c014060 */ 	lui	$at,0x4060
/*  f0cb308:	c4b2015c */ 	lwc1	$f18,0x15c($a1)
/*  f0cb30c:	44813000 */ 	mtc1	$at,$f6
/*  f0cb310:	c4b00154 */ 	lwc1	$f16,0x154($a1)
/*  f0cb314:	46049282 */ 	mul.s	$f10,$f18,$f4
/*  f0cb318:	00000000 */ 	nop
/*  f0cb31c:	46065202 */ 	mul.s	$f8,$f10,$f6
/*  f0cb320:	46088480 */ 	add.s	$f18,$f16,$f8
/*  f0cb324:	e4b20154 */ 	swc1	$f18,0x154($a1)
.L0f0cb328:
/*  f0cb328:	8faa01cc */ 	lw	$t2,0x1cc($sp)
.L0f0cb32c:
/*  f0cb32c:	c7ac01f4 */ 	lwc1	$f12,0x1f4($sp)
/*  f0cb330:	5140002d */ 	beqzl	$t2,.L0f0cb3e8
/*  f0cb334:	44804000 */ 	mtc1	$zero,$f8
/*  f0cb338:	0c002f9d */ 	jal	viGetFovY
/*  f0cb33c:	00000000 */ 	nop
/*  f0cb340:	8fab0250 */ 	lw	$t3,0x250($sp)
/*  f0cb344:	3c01428c */ 	lui	$at,0x428c
/*  f0cb348:	44813000 */ 	mtc1	$at,$f6
/*  f0cb34c:	448b2000 */ 	mtc1	$t3,$f4
/*  f0cb350:	3c013f80 */ 	lui	$at,0x3f80
/*  f0cb354:	44818000 */ 	mtc1	$at,$f16
/*  f0cb358:	468022a0 */ 	cvt.s.w	$f10,$f4
/*  f0cb35c:	44809000 */ 	mtc1	$zero,$f18
/*  f0cb360:	3c01bf80 */ 	lui	$at,0xbf80
/*  f0cb364:	46065303 */ 	div.s	$f12,$f10,$f6
/*  f0cb368:	460c803c */ 	c.lt.s	$f16,$f12
/*  f0cb36c:	46006086 */ 	mov.s	$f2,$f12
/*  f0cb370:	45020006 */ 	bc1fl	.L0f0cb38c
/*  f0cb374:	44814000 */ 	mtc1	$at,$f8
/*  f0cb378:	3c013f80 */ 	lui	$at,0x3f80
/*  f0cb37c:	44811000 */ 	mtc1	$at,$f2
/*  f0cb380:	1000000a */ 	b	.L0f0cb3ac
/*  f0cb384:	4602903e */ 	c.le.s	$f18,$f2
/*  f0cb388:	44814000 */ 	mtc1	$at,$f8
.L0f0cb38c:
/*  f0cb38c:	3c01bf80 */ 	lui	$at,0xbf80
/*  f0cb390:	4608603c */ 	c.lt.s	$f12,$f8
/*  f0cb394:	00000000 */ 	nop
/*  f0cb398:	45020004 */ 	bc1fl	.L0f0cb3ac
/*  f0cb39c:	4602903e */ 	c.le.s	$f18,$f2
/*  f0cb3a0:	44811000 */ 	mtc1	$at,$f2
/*  f0cb3a4:	00000000 */ 	nop
/*  f0cb3a8:	4602903e */ 	c.le.s	$f18,$f2
.L0f0cb3ac:
/*  f0cb3ac:	3c014270 */ 	lui	$at,0x4270
/*  f0cb3b0:	44815000 */ 	mtc1	$at,$f10
/*  f0cb3b4:	45000004 */ 	bc1f	.L0f0cb3c8
/*  f0cb3b8:	460a0183 */ 	div.s	$f6,$f0,$f10
/*  f0cb3bc:	46021082 */ 	mul.s	$f2,$f2,$f2
/*  f0cb3c0:	10000004 */ 	b	.L0f0cb3d4
/*  f0cb3c4:	00000000 */ 	nop
.L0f0cb3c8:
/*  f0cb3c8:	46001107 */ 	neg.s	$f4,$f2
/*  f0cb3cc:	46041082 */ 	mul.s	$f2,$f2,$f4
/*  f0cb3d0:	00000000 */ 	nop
.L0f0cb3d4:
/*  f0cb3d4:	46061402 */ 	mul.s	$f16,$f2,$f6
/*  f0cb3d8:	8e4c0284 */ 	lw	$t4,0x284($s2)
/*  f0cb3dc:	10000019 */ 	b	.L0f0cb444
/*  f0cb3e0:	e5901b9c */ 	swc1	$f16,0x1b9c($t4)
/*  f0cb3e4:	44804000 */ 	mtc1	$zero,$f8
.L0f0cb3e8:
/*  f0cb3e8:	c7a001f8 */ 	lwc1	$f0,0x1f8($sp)
/*  f0cb3ec:	460c403c */ 	c.lt.s	$f8,$f12
/*  f0cb3f0:	00000000 */ 	nop
/*  f0cb3f4:	45020006 */ 	bc1fl	.L0f0cb410
/*  f0cb3f8:	44809000 */ 	mtc1	$zero,$f18
/*  f0cb3fc:	0fc320e5 */ 	jal	bmoveUpdateSpeedThetaControl
/*  f0cb400:	e7ac01f4 */ 	swc1	$f12,0x1f4($sp)
/*  f0cb404:	10000010 */ 	b	.L0f0cb448
/*  f0cb408:	8e450284 */ 	lw	$a1,0x284($s2)
/*  f0cb40c:	44809000 */ 	mtc1	$zero,$f18
.L0f0cb410:
/*  f0cb410:	00000000 */ 	nop
/*  f0cb414:	4600903c */ 	c.lt.s	$f18,$f0
/*  f0cb418:	00000000 */ 	nop
/*  f0cb41c:	45020007 */ 	bc1fl	.L0f0cb43c
/*  f0cb420:	44806000 */ 	mtc1	$zero,$f12
/*  f0cb424:	46000307 */ 	neg.s	$f12,$f0
/*  f0cb428:	0fc320e5 */ 	jal	bmoveUpdateSpeedThetaControl
/*  f0cb42c:	e7a001f8 */ 	swc1	$f0,0x1f8($sp)
/*  f0cb430:	10000005 */ 	b	.L0f0cb448
/*  f0cb434:	8e450284 */ 	lw	$a1,0x284($s2)
/*  f0cb438:	44806000 */ 	mtc1	$zero,$f12
.L0f0cb43c:
/*  f0cb43c:	0fc320e5 */ 	jal	bmoveUpdateSpeedThetaControl
/*  f0cb440:	00000000 */ 	nop
.L0f0cb444:
/*  f0cb444:	8e450284 */ 	lw	$a1,0x284($s2)
.L0f0cb448:
/*  f0cb448:	c4a41b9c */ 	lwc1	$f4,0x1b9c($a1)
/*  f0cb44c:	0fc32001 */ 	jal	bmoveUpdateSpeedTheta
/*  f0cb450:	e4a40148 */ 	swc1	$f4,0x148($a1)
/*  f0cb454:	8fad0228 */ 	lw	$t5,0x228($sp)
/*  f0cb458:	51a00008 */ 	beqzl	$t5,.L0f0cb47c
/*  f0cb45c:	8e5802ac */ 	lw	$t8,0x2ac($s2)
/*  f0cb460:	8e4e0284 */ 	lw	$t6,0x284($s2)
/*  f0cb464:	adc00658 */ 	sw	$zero,0x658($t6)
/*  f0cb468:	8e4f0284 */ 	lw	$t7,0x284($s2)
/*  f0cb46c:	ade0065c */ 	sw	$zero,0x65c($t7)
/*  f0cb470:	0fc22a7d */ 	jal	playerActivateRemoteMineDetonator
/*  f0cb474:	8e44028c */ 	lw	$a0,0x28c($s2)
/*  f0cb478:	8e5802ac */ 	lw	$t8,0x2ac($s2)
.L0f0cb47c:
/*  f0cb47c:	24010006 */ 	addiu	$at,$zero,0x6
/*  f0cb480:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f0cb484:	57010003 */ 	bnel	$t8,$at,.L0f0cb494
/*  f0cb488:	8e59000c */ 	lw	$t9,0xc($s2)
/*  f0cb48c:	00001025 */ 	or	$v0,$zero,$zero
/*  f0cb490:	8e59000c */ 	lw	$t9,0xc($s2)
.L0f0cb494:
/*  f0cb494:	2b21000a */ 	slti	$at,$t9,0xa
/*  f0cb498:	10200002 */ 	beqz	$at,.L0f0cb4a4
/*  f0cb49c:	00000000 */ 	nop
/*  f0cb4a0:	00001025 */ 	or	$v0,$zero,$zero
.L0f0cb4a4:
/*  f0cb4a4:	5040001a */ 	beqzl	$v0,.L0f0cb510
/*  f0cb4a8:	8e450284 */ 	lw	$a1,0x284($s2)
/*  f0cb4ac:	8fa201fc */ 	lw	$v0,0x1fc($sp)
/*  f0cb4b0:	0002202a */ 	slt	$a0,$zero,$v0
/*  f0cb4b4:	2442ffff */ 	addiu	$v0,$v0,-1
/*  f0cb4b8:	10800008 */ 	beqz	$a0,.L0f0cb4dc
/*  f0cb4bc:	afa201fc */ 	sw	$v0,0x1fc($sp)
.L0f0cb4c0:
/*  f0cb4c0:	0fc2870b */ 	jal	bgun0f0a1c2c
/*  f0cb4c4:	00000000 */ 	nop
/*  f0cb4c8:	8fa201fc */ 	lw	$v0,0x1fc($sp)
/*  f0cb4cc:	0002202a */ 	slt	$a0,$zero,$v0
/*  f0cb4d0:	2442ffff */ 	addiu	$v0,$v0,-1
/*  f0cb4d4:	1480fffa */ 	bnez	$a0,.L0f0cb4c0
/*  f0cb4d8:	afa201fc */ 	sw	$v0,0x1fc($sp)
.L0f0cb4dc:
/*  f0cb4dc:	8fa20200 */ 	lw	$v0,0x200($sp)
/*  f0cb4e0:	0002202a */ 	slt	$a0,$zero,$v0
/*  f0cb4e4:	2442ffff */ 	addiu	$v0,$v0,-1
/*  f0cb4e8:	10800008 */ 	beqz	$a0,.L0f0cb50c
/*  f0cb4ec:	afa20200 */ 	sw	$v0,0x200($sp)
.L0f0cb4f0:
/*  f0cb4f0:	0fc286d4 */ 	jal	bgun0f0a1b50
/*  f0cb4f4:	00000000 */ 	nop
/*  f0cb4f8:	8fa20200 */ 	lw	$v0,0x200($sp)
/*  f0cb4fc:	0002202a */ 	slt	$a0,$zero,$v0
/*  f0cb500:	2442ffff */ 	addiu	$v0,$v0,-1
/*  f0cb504:	1480fffa */ 	bnez	$a0,.L0f0cb4f0
/*  f0cb508:	afa20200 */ 	sw	$v0,0x200($sp)
.L0f0cb50c:
/*  f0cb50c:	8e450284 */ 	lw	$a1,0x284($s2)
.L0f0cb510:
/*  f0cb510:	8fa901b4 */ 	lw	$t1,0x1b4($sp)
/*  f0cb514:	8ca81c64 */ 	lw	$t0,0x1c64($a1)
/*  f0cb518:	11000003 */ 	beqz	$t0,.L0f0cb528
/*  f0cb51c:	00000000 */ 	nop
/*  f0cb520:	10000093 */ 	b	.L0f0cb770
/*  f0cb524:	aca01c64 */ 	sw	$zero,0x1c64($a1)
.L0f0cb528:
/*  f0cb528:	1120007d */ 	beqz	$t1,.L0f0cb720
/*  f0cb52c:	8fb901b8 */ 	lw	$t9,0x1b8($sp)
/*  f0cb530:	0fc2a4f4 */ 	jal	bgunSetAimType
/*  f0cb534:	00002025 */ 	or	$a0,$zero,$zero
/*  f0cb538:	8faa022c */ 	lw	$t2,0x22c($sp)
/*  f0cb53c:	11400015 */ 	beqz	$t2,.L0f0cb594
/*  f0cb540:	00000000 */ 	nop
/*  f0cb544:	0fc31ef4 */ 	jal	bmoveIsAutoAimXEnabledForCurrentWeapon
/*  f0cb548:	00000000 */ 	nop
/*  f0cb54c:	54400006 */ 	bnezl	$v0,.L0f0cb568
/*  f0cb550:	8e450284 */ 	lw	$a1,0x284($s2)
/*  f0cb554:	0fc31ea3 */ 	jal	bmoveIsAutoAimYEnabledForCurrentWeapon
/*  f0cb558:	00000000 */ 	nop
/*  f0cb55c:	1040000d */ 	beqz	$v0,.L0f0cb594
/*  f0cb560:	00000000 */ 	nop
/*  f0cb564:	8e450284 */ 	lw	$a1,0x284($s2)
.L0f0cb568:
/*  f0cb568:	8cab013c */ 	lw	$t3,0x13c($a1)
/*  f0cb56c:	11600009 */ 	beqz	$t3,.L0f0cb594
/*  f0cb570:	00000000 */ 	nop
/*  f0cb574:	8cac012c */ 	lw	$t4,0x12c($a1)
/*  f0cb578:	8fa401ac */ 	lw	$a0,0x1ac($sp)
/*  f0cb57c:	11800005 */ 	beqz	$t4,.L0f0cb594
/*  f0cb580:	00000000 */ 	nop
/*  f0cb584:	0fc2c601 */ 	jal	weaponHasClassFlag
/*  f0cb588:	24050002 */ 	addiu	$a1,$zero,0x2
/*  f0cb58c:	5440000b */ 	bnezl	$v0,.L0f0cb5bc
/*  f0cb590:	00008025 */ 	or	$s0,$zero,$zero
.L0f0cb594:
/*  f0cb594:	0fc2866a */ 	jal	bgunGetWeaponNum
/*  f0cb598:	00002025 */ 	or	$a0,$zero,$zero
/*  f0cb59c:	2401000a */ 	addiu	$at,$zero,0xa
/*  f0cb5a0:	54410037 */ 	bnel	$v0,$at,.L0f0cb680
/*  f0cb5a4:	8e450284 */ 	lw	$a1,0x284($s2)
/*  f0cb5a8:	8e4d0284 */ 	lw	$t5,0x284($s2)
/*  f0cb5ac:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0cb5b0:	91ae063b */ 	lbu	$t6,0x63b($t5)
/*  f0cb5b4:	15c10031 */ 	bne	$t6,$at,.L0f0cb67c
/*  f0cb5b8:	00008025 */ 	or	$s0,$zero,$zero
.L0f0cb5bc:
/*  f0cb5bc:	0fc2866a */ 	jal	bgunGetWeaponNum
/*  f0cb5c0:	00002025 */ 	or	$a0,$zero,$zero
/*  f0cb5c4:	2401000a */ 	addiu	$at,$zero,0xa
/*  f0cb5c8:	54410008 */ 	bnel	$v0,$at,.L0f0cb5ec
/*  f0cb5cc:	8e450284 */ 	lw	$a1,0x284($s2)
/*  f0cb5d0:	8e4f0284 */ 	lw	$t7,0x284($s2)
/*  f0cb5d4:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0cb5d8:	91f8063b */ 	lbu	$t8,0x63b($t7)
/*  f0cb5dc:	57010003 */ 	bnel	$t8,$at,.L0f0cb5ec
/*  f0cb5e0:	8e450284 */ 	lw	$a1,0x284($s2)
/*  f0cb5e4:	24100001 */ 	addiu	$s0,$zero,0x1
/*  f0cb5e8:	8e450284 */ 	lw	$a1,0x284($s2)
.L0f0cb5ec:
/*  f0cb5ec:	3c017f1b */ 	lui	$at,%hi(var7f1ad8c4)
/*  f0cb5f0:	c422d8c4 */ 	lwc1	$f2,%lo(var7f1ad8c4)($at)
/*  f0cb5f4:	c4a01b68 */ 	lwc1	$f0,0x1b68($a1)
/*  f0cb5f8:	3c017f1b */ 	lui	$at,%hi(var7f1ad8c8)
/*  f0cb5fc:	4600103c */ 	c.lt.s	$f2,$f0
/*  f0cb600:	00000000 */ 	nop
/*  f0cb604:	45020009 */ 	bc1fl	.L0f0cb62c
/*  f0cb608:	4602003c */ 	c.lt.s	$f0,$f2
/*  f0cb60c:	c42ad8c8 */ 	lwc1	$f10,%lo(var7f1ad8c8)($at)
/*  f0cb610:	c646004c */ 	lwc1	$f6,0x4c($s2)
/*  f0cb614:	46065402 */ 	mul.s	$f16,$f10,$f6
/*  f0cb618:	46100201 */ 	sub.s	$f8,$f0,$f16
/*  f0cb61c:	e4a81b68 */ 	swc1	$f8,0x1b68($a1)
/*  f0cb620:	8e450284 */ 	lw	$a1,0x284($s2)
/*  f0cb624:	c4a01b68 */ 	lwc1	$f0,0x1b68($a1)
/*  f0cb628:	4602003c */ 	c.lt.s	$f0,$f2
.L0f0cb62c:
/*  f0cb62c:	3c017f1b */ 	lui	$at,%hi(var7f1ad8cc)
/*  f0cb630:	45020005 */ 	bc1fl	.L0f0cb648
/*  f0cb634:	c4ac0138 */ 	lwc1	$f12,0x138($a1)
/*  f0cb638:	e4a21b68 */ 	swc1	$f2,0x1b68($a1)
/*  f0cb63c:	3c05800a */ 	lui	$a1,%hi(g_Vars+0x284)
/*  f0cb640:	8ca5a244 */ 	lw	$a1,%lo(g_Vars+0x284)($a1)
/*  f0cb644:	c4ac0138 */ 	lwc1	$f12,0x138($a1)
.L0f0cb648:
/*  f0cb648:	12000008 */ 	beqz	$s0,.L0f0cb66c
/*  f0cb64c:	c4ae0128 */ 	lwc1	$f14,0x128($a1)
/*  f0cb650:	c420d8cc */ 	lwc1	$f0,%lo(var7f1ad8cc)($at)
/*  f0cb654:	44060000 */ 	mfc1	$a2,$f0
/*  f0cb658:	44070000 */ 	mfc1	$a3,$f0
/*  f0cb65c:	0fc280e5 */ 	jal	bgun0f0a0394
/*  f0cb660:	00000000 */ 	nop
/*  f0cb664:	10000043 */ 	b	.L0f0cb774
/*  f0cb668:	8fbf0034 */ 	lw	$ra,0x34($sp)
.L0f0cb66c:
/*  f0cb66c:	0fc282cc */ 	jal	bgunSwivelTowards
/*  f0cb670:	8ca61b68 */ 	lw	$a2,0x1b68($a1)
/*  f0cb674:	1000003f */ 	b	.L0f0cb774
/*  f0cb678:	8fbf0034 */ 	lw	$ra,0x34($sp)
.L0f0cb67c:
/*  f0cb67c:	8e450284 */ 	lw	$a1,0x284($s2)
.L0f0cb680:
/*  f0cb680:	3c017f1b */ 	lui	$at,%hi(var7f1ad8d0)
/*  f0cb684:	c422d8d0 */ 	lwc1	$f2,%lo(var7f1ad8d0)($at)
/*  f0cb688:	c4a01b68 */ 	lwc1	$f0,0x1b68($a1)
/*  f0cb68c:	3c017f1b */ 	lui	$at,%hi(var7f1ad8d4)
/*  f0cb690:	4602003c */ 	c.lt.s	$f0,$f2
/*  f0cb694:	00000000 */ 	nop
/*  f0cb698:	45020009 */ 	bc1fl	.L0f0cb6c0
/*  f0cb69c:	4600103c */ 	c.lt.s	$f2,$f0
/*  f0cb6a0:	c432d8d4 */ 	lwc1	$f18,%lo(var7f1ad8d4)($at)
/*  f0cb6a4:	c644004c */ 	lwc1	$f4,0x4c($s2)
/*  f0cb6a8:	46049282 */ 	mul.s	$f10,$f18,$f4
/*  f0cb6ac:	460a0180 */ 	add.s	$f6,$f0,$f10
/*  f0cb6b0:	e4a61b68 */ 	swc1	$f6,0x1b68($a1)
/*  f0cb6b4:	8e450284 */ 	lw	$a1,0x284($s2)
/*  f0cb6b8:	c4a01b68 */ 	lwc1	$f0,0x1b68($a1)
/*  f0cb6bc:	4600103c */ 	c.lt.s	$f2,$f0
.L0f0cb6c0:
/*  f0cb6c0:	3c017f1b */ 	lui	$at,%hi(var7f1ad8d8)
/*  f0cb6c4:	45000004 */ 	bc1f	.L0f0cb6d8
/*  f0cb6c8:	00000000 */ 	nop
/*  f0cb6cc:	e4a21b68 */ 	swc1	$f2,0x1b68($a1)
/*  f0cb6d0:	3c05800a */ 	lui	$a1,%hi(g_Vars+0x284)
/*  f0cb6d4:	8ca5a244 */ 	lw	$a1,%lo(g_Vars+0x284)($a1)
.L0f0cb6d8:
/*  f0cb6d8:	c422d8d8 */ 	lwc1	$f2,%lo(var7f1ad8d8)($at)
/*  f0cb6dc:	3c017f1b */ 	lui	$at,%hi(var7f1ad8dc)
/*  f0cb6e0:	c428d8dc */ 	lwc1	$f8,%lo(var7f1ad8dc)($at)
/*  f0cb6e4:	c4b00148 */ 	lwc1	$f16,0x148($a1)
/*  f0cb6e8:	c4aa015c */ 	lwc1	$f10,0x15c($a1)
/*  f0cb6ec:	3c017f1b */ 	lui	$at,%hi(var7f1ad8e0)
/*  f0cb6f0:	46088482 */ 	mul.s	$f18,$f16,$f8
/*  f0cb6f4:	c430d8e0 */ 	lwc1	$f16,%lo(var7f1ad8e0)($at)
/*  f0cb6f8:	46005187 */ 	neg.s	$f6,$f10
/*  f0cb6fc:	c4a401b4 */ 	lwc1	$f4,0x1b4($a1)
/*  f0cb700:	46103202 */ 	mul.s	$f8,$f6,$f16
/*  f0cb704:	44061000 */ 	mfc1	$a2,$f2
/*  f0cb708:	46049300 */ 	add.s	$f12,$f18,$f4
/*  f0cb70c:	c4b201b8 */ 	lwc1	$f18,0x1b8($a1)
/*  f0cb710:	0fc282cc */ 	jal	bgunSwivelTowards
/*  f0cb714:	46124380 */ 	add.s	$f14,$f8,$f18
/*  f0cb718:	10000016 */ 	b	.L0f0cb774
/*  f0cb71c:	8fbf0034 */ 	lw	$ra,0x34($sp)
.L0f0cb720:
/*  f0cb720:	53200014 */ 	beqzl	$t9,.L0f0cb774
/*  f0cb724:	8fbf0034 */ 	lw	$ra,0x34($sp)
/*  f0cb728:	0fc2a4f4 */ 	jal	bgunSetAimType
/*  f0cb72c:	00002025 */ 	or	$a0,$zero,$zero
/*  f0cb730:	8fa30248 */ 	lw	$v1,0x248($sp)
/*  f0cb734:	8fa4024c */ 	lw	$a0,0x24c($sp)
/*  f0cb738:	3c017f1b */ 	lui	$at,%hi(var7f1ad8e4)
/*  f0cb73c:	44832000 */ 	mtc1	$v1,$f4
/*  f0cb740:	44848000 */ 	mtc1	$a0,$f16
/*  f0cb744:	c420d8e4 */ 	lwc1	$f0,%lo(var7f1ad8e4)($at)
/*  f0cb748:	468022a0 */ 	cvt.s.w	$f10,$f4
/*  f0cb74c:	3c0142a0 */ 	lui	$at,0x42a0
/*  f0cb750:	44811000 */ 	mtc1	$at,$f2
/*  f0cb754:	46808220 */ 	cvt.s.w	$f8,$f16
/*  f0cb758:	46005182 */ 	mul.s	$f6,$f10,$f0
/*  f0cb75c:	00000000 */ 	nop
/*  f0cb760:	46004482 */ 	mul.s	$f18,$f8,$f0
/*  f0cb764:	46023303 */ 	div.s	$f12,$f6,$f2
/*  f0cb768:	0fc282e6 */ 	jal	bgun0f0a0b98
/*  f0cb76c:	46029383 */ 	div.s	$f14,$f18,$f2
.L0f0cb770:
/*  f0cb770:	8fbf0034 */ 	lw	$ra,0x34($sp)
.L0f0cb774:
/*  f0cb774:	8fb00014 */ 	lw	$s0,0x14($sp)
/*  f0cb778:	8fb10018 */ 	lw	$s1,0x18($sp)
/*  f0cb77c:	8fb2001c */ 	lw	$s2,0x1c($sp)
/*  f0cb780:	8fb30020 */ 	lw	$s3,0x20($sp)
/*  f0cb784:	8fb40024 */ 	lw	$s4,0x24($sp)
/*  f0cb788:	8fb50028 */ 	lw	$s5,0x28($sp)
/*  f0cb78c:	8fb6002c */ 	lw	$s6,0x2c($sp)
/*  f0cb790:	8fb70030 */ 	lw	$s7,0x30($sp)
/*  f0cb794:	03e00008 */ 	jr	$ra
/*  f0cb798:	27bd0260 */ 	addiu	$sp,$sp,0x260
);
#else
GLOBAL_ASM(
glabel bmoveProcessInput
.late_rodata
glabel var7f1ad8b8
.word 0x3c23d70a
glabel var7f1ad8bc
.word 0x3c23d70a
glabel var7f1ad8c0
.word 0x3d4ccccd
glabel var7f1ad8c4
.word 0x3f76872b
glabel var7f1ad8c8
.word 0x39a7c599
glabel var7f1ad8cc
.word 0x3f6a3d71
glabel var7f1ad8d0
.word 0x3f7a9fbe
glabel var7f1ad8d4
.word 0x39a7c599
glabel var7f1ad8d8
.word 0x3f76872b
glabel var7f1ad8dc
.word 0x3e99999a
glabel var7f1ad8e0
.word 0x3dcccccd
glabel var7f1ad8e4
.word 0x3f266666
.text
/*  f0c63ec:	27bdfda0 */ 	addiu	$sp,$sp,-608
/*  f0c63f0:	afb2001c */ 	sw	$s2,0x1c($sp)
/*  f0c63f4:	3c12800a */ 	lui	$s2,0x800a
/*  f0c63f8:	2652e6c0 */ 	addiu	$s2,$s2,-6464
/*  f0c63fc:	8e4e0288 */ 	lw	$t6,0x288($s2)
/*  f0c6400:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f0c6404:	00808025 */ 	or	$s0,$a0,$zero
/*  f0c6408:	afbf0034 */ 	sw	$ra,0x34($sp)
/*  f0c640c:	afb70030 */ 	sw	$s7,0x30($sp)
/*  f0c6410:	afb6002c */ 	sw	$s6,0x2c($sp)
/*  f0c6414:	afb50028 */ 	sw	$s5,0x28($sp)
/*  f0c6418:	afb40024 */ 	sw	$s4,0x24($sp)
/*  f0c641c:	afb30020 */ 	sw	$s3,0x20($sp)
/*  f0c6420:	afb10018 */ 	sw	$s1,0x18($sp)
/*  f0c6424:	afa7026c */ 	sw	$a3,0x26c($sp)
/*  f0c6428:	00a08825 */ 	or	$s1,$a1,$zero
/*  f0c642c:	00c0b025 */ 	or	$s6,$a2,$zero
/*  f0c6430:	0fc53380 */ 	jal	optionsGetControlMode
/*  f0c6434:	8dc40070 */ 	lw	$a0,0x70($t6)
/*  f0c6438:	afa201b0 */ 	sw	$v0,0x1b0($sp)
/*  f0c643c:	0fc27dd7 */ 	jal	bgunGetWeaponNum
/*  f0c6440:	00002025 */ 	or	$a0,$zero,$zero
/*  f0c6444:	afa201ac */ 	sw	$v0,0x1ac($sp)
/*  f0c6448:	00402025 */ 	or	$a0,$v0,$zero
/*  f0c644c:	0fc2bd59 */ 	jal	weaponHasClassFlag
/*  f0c6450:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f0c6454:	8e4f0288 */ 	lw	$t7,0x288($s2)
/*  f0c6458:	afa201a8 */ 	sw	$v0,0x1a8($sp)
/*  f0c645c:	0fc5338e */ 	jal	optionsGetContpadNum1
/*  f0c6460:	8de40070 */ 	lw	$a0,0x70($t7)
/*  f0c6464:	0002ae00 */ 	sll	$s5,$v0,0x18
/*  f0c6468:	0015c603 */ 	sra	$t8,$s5,0x18
/*  f0c646c:	12000009 */ 	beqz	$s0,.NB0f0c6494
/*  f0c6470:	0300a825 */ 	or	$s5,$t8,$zero
/*  f0c6474:	00182600 */ 	sll	$a0,$t8,0x18
/*  f0c6478:	0004ce03 */ 	sra	$t9,$a0,0x18
/*  f0c647c:	0c00573c */ 	jal	joyGetStickX
/*  f0c6480:	03202025 */ 	or	$a0,$t9,$zero
/*  f0c6484:	0002a600 */ 	sll	$s4,$v0,0x18
/*  f0c6488:	00144603 */ 	sra	$t0,$s4,0x18
/*  f0c648c:	10000002 */ 	beqz	$zero,.NB0f0c6498
/*  f0c6490:	0100a025 */ 	or	$s4,$t0,$zero
.NB0f0c6494:
/*  f0c6494:	0000a025 */ 	or	$s4,$zero,$zero
.NB0f0c6498:
/*  f0c6498:	12200008 */ 	beqz	$s1,.NB0f0c64bc
/*  f0c649c:	00152600 */ 	sll	$a0,$s5,0x18
/*  f0c64a0:	00044e03 */ 	sra	$t1,$a0,0x18
/*  f0c64a4:	0c005766 */ 	jal	joyGetStickY
/*  f0c64a8:	01202025 */ 	or	$a0,$t1,$zero
/*  f0c64ac:	00029e00 */ 	sll	$s3,$v0,0x18
/*  f0c64b0:	00135603 */ 	sra	$t2,$s3,0x18
/*  f0c64b4:	10000002 */ 	beqz	$zero,.NB0f0c64c0
/*  f0c64b8:	01409825 */ 	or	$s3,$t2,$zero
.NB0f0c64bc:
/*  f0c64bc:	00009825 */ 	or	$s3,$zero,$zero
.NB0f0c64c0:
/*  f0c64c0:	0016b82b */ 	sltu	$s7,$zero,$s6
/*  f0c64c4:	12e00007 */ 	beqz	$s7,.NB0f0c64e4
/*  f0c64c8:	00152600 */ 	sll	$a0,$s5,0x18
/*  f0c64cc:	00045e03 */ 	sra	$t3,$a0,0x18
/*  f0c64d0:	01602025 */ 	or	$a0,$t3,$zero
/*  f0c64d4:	0c005790 */ 	jal	joyGetButtons
/*  f0c64d8:	3405ffff */ 	dli	$a1,0xffff
/*  f0c64dc:	10000002 */ 	beqz	$zero,.NB0f0c64e8
/*  f0c64e0:	a7a201a2 */ 	sh	$v0,0x1a2($sp)
.NB0f0c64e4:
/*  f0c64e4:	a7a001a2 */ 	sh	$zero,0x1a2($sp)
.NB0f0c64e8:
/*  f0c64e8:	12e00007 */ 	beqz	$s7,.NB0f0c6508
/*  f0c64ec:	00152600 */ 	sll	$a0,$s5,0x18
/*  f0c64f0:	00046603 */ 	sra	$t4,$a0,0x18
/*  f0c64f4:	01802025 */ 	or	$a0,$t4,$zero
/*  f0c64f8:	0c0057c0 */ 	jal	joyGetButtonsPressedThisFrame
/*  f0c64fc:	3405ffff */ 	dli	$a1,0xffff
/*  f0c6500:	10000002 */ 	beqz	$zero,.NB0f0c650c
/*  f0c6504:	a7a201a0 */ 	sh	$v0,0x1a0($sp)
.NB0f0c6508:
/*  f0c6508:	a7a001a0 */ 	sh	$zero,0x1a0($sp)
.NB0f0c650c:
/*  f0c650c:	8e4e0284 */ 	lw	$t6,0x284($s2)
/*  f0c6510:	340dffff */ 	dli	$t5,0xffff
/*  f0c6514:	a7ad019e */ 	sh	$t5,0x19e($sp)
/*  f0c6518:	8dc21c40 */ 	lw	$v0,0x1c40($t6)
/*  f0c651c:	304fffff */ 	andi	$t7,$v0,0xffff
/*  f0c6520:	11e00017 */ 	beqz	$t7,.NB0f0c6580
/*  f0c6524:	31f0ffff */ 	andi	$s0,$t7,0xffff
/*  f0c6528:	00152600 */ 	sll	$a0,$s5,0x18
/*  f0c652c:	0200c027 */ 	nor	$t8,$s0,$zero
/*  f0c6530:	0004ce03 */ 	sra	$t9,$a0,0x18
/*  f0c6534:	a7b8019e */ 	sh	$t8,0x19e($sp)
/*  f0c6538:	03202025 */ 	or	$a0,$t9,$zero
/*  f0c653c:	0c005790 */ 	jal	joyGetButtons
/*  f0c6540:	3405ffff */ 	dli	$a1,0xffff
/*  f0c6544:	00508824 */ 	and	$s1,$v0,$s0
/*  f0c6548:	97a901a2 */ 	lhu	$t1,0x1a2($sp)
/*  f0c654c:	97ab01a0 */ 	lhu	$t3,0x1a0($sp)
/*  f0c6550:	3228ffff */ 	andi	$t0,$s1,0xffff
/*  f0c6554:	01001827 */ 	nor	$v1,$t0,$zero
/*  f0c6558:	8e450284 */ 	lw	$a1,0x284($s2)
/*  f0c655c:	01235024 */ 	and	$t2,$t1,$v1
/*  f0c6560:	01636024 */ 	and	$t4,$t3,$v1
/*  f0c6564:	a7aa01a2 */ 	sh	$t2,0x1a2($sp)
/*  f0c6568:	a7ac01a0 */ 	sh	$t4,0x1a0($sp)
/*  f0c656c:	8cad1c40 */ 	lw	$t5,0x1c40($a1)
/*  f0c6570:	3c01ffff */ 	lui	$at,0xffff
/*  f0c6574:	01a17024 */ 	and	$t6,$t5,$at
/*  f0c6578:	01c87825 */ 	or	$t7,$t6,$t0
/*  f0c657c:	acaf1c40 */ 	sw	$t7,0x1c40($a1)
.NB0f0c6580:
/*  f0c6580:	0c0055bf */ 	jal	joyGetNumSamples
/*  f0c6584:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c6588:	0040b025 */ 	or	$s6,$v0,$zero
/*  f0c658c:	0fc318c1 */ 	jal	bmoveResetMoveData
/*  f0c6590:	27a401b4 */ 	addiu	$a0,$sp,0x1b4
/*  f0c6594:	2a81fffb */ 	slti	$at,$s4,-5
/*  f0c6598:	10200003 */ 	beqz	$at,.NB0f0c65a8
/*  f0c659c:	26980005 */ 	addiu	$t8,$s4,0x5
/*  f0c65a0:	10000007 */ 	beqz	$zero,.NB0f0c65c0
/*  f0c65a4:	afb80240 */ 	sw	$t8,0x240($sp)
.NB0f0c65a8:
/*  f0c65a8:	2a810006 */ 	slti	$at,$s4,0x6
/*  f0c65ac:	14200003 */ 	bnez	$at,.NB0f0c65bc
/*  f0c65b0:	2699fffb */ 	addiu	$t9,$s4,-5
/*  f0c65b4:	10000002 */ 	beqz	$zero,.NB0f0c65c0
/*  f0c65b8:	afb90240 */ 	sw	$t9,0x240($sp)
.NB0f0c65bc:
/*  f0c65bc:	afa00240 */ 	sw	$zero,0x240($sp)
.NB0f0c65c0:
/*  f0c65c0:	2a61fffb */ 	slti	$at,$s3,-5
/*  f0c65c4:	10200003 */ 	beqz	$at,.NB0f0c65d4
/*  f0c65c8:	26680005 */ 	addiu	$t0,$s3,0x5
/*  f0c65cc:	10000007 */ 	beqz	$zero,.NB0f0c65ec
/*  f0c65d0:	afa80244 */ 	sw	$t0,0x244($sp)
.NB0f0c65d4:
/*  f0c65d4:	2a610006 */ 	slti	$at,$s3,0x6
/*  f0c65d8:	14200003 */ 	bnez	$at,.NB0f0c65e8
/*  f0c65dc:	2669fffb */ 	addiu	$t1,$s3,-5
/*  f0c65e0:	10000002 */ 	beqz	$zero,.NB0f0c65ec
/*  f0c65e4:	afa90244 */ 	sw	$t1,0x244($sp)
.NB0f0c65e8:
/*  f0c65e8:	afa00244 */ 	sw	$zero,0x244($sp)
.NB0f0c65ec:
/*  f0c65ec:	8faa0240 */ 	lw	$t2,0x240($sp)
/*  f0c65f0:	8fab0244 */ 	lw	$t3,0x244($sp)
/*  f0c65f4:	8e450284 */ 	lw	$a1,0x284($s2)
/*  f0c65f8:	afb40248 */ 	sw	$s4,0x248($sp)
/*  f0c65fc:	afb3024c */ 	sw	$s3,0x24c($sp)
/*  f0c6600:	afaa0250 */ 	sw	$t2,0x250($sp)
/*  f0c6604:	afaa0258 */ 	sw	$t2,0x258($sp)
/*  f0c6608:	afab0254 */ 	sw	$t3,0x254($sp)
/*  f0c660c:	afab025c */ 	sw	$t3,0x25c($sp)
/*  f0c6610:	8cac00d8 */ 	lw	$t4,0xd8($a1)
/*  f0c6614:	55800017 */ 	bnezl	$t4,.NB0f0c6674
/*  f0c6618:	8e480314 */ 	lw	$t0,0x314($s2)
/*  f0c661c:	8cad1a24 */ 	lw	$t5,0x1a24($a1)
/*  f0c6620:	97ae01a0 */ 	lhu	$t6,0x1a0($sp)
/*  f0c6624:	15a0004a */ 	bnez	$t5,.NB0f0c6750
/*  f0c6628:	31cf1000 */ 	andi	$t7,$t6,0x1000
/*  f0c662c:	51e00049 */ 	beqzl	$t7,.NB0f0c6754
/*  f0c6630:	8e450284 */ 	lw	$a1,0x284($s2)
/*  f0c6634:	8e580314 */ 	lw	$t8,0x314($s2)
/*  f0c6638:	17000009 */ 	bnez	$t8,.NB0f0c6660
/*  f0c663c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c6640:	8e59000c */ 	lw	$t9,0xc($s2)
/*  f0c6644:	2b210010 */ 	slti	$at,$t9,0x10
/*  f0c6648:	54200042 */ 	bnezl	$at,.NB0f0c6754
/*  f0c664c:	8e450284 */ 	lw	$a1,0x284($s2)
/*  f0c6650:	0fc2e2f8 */ 	jal	currentPlayerPause
/*  f0c6654:	24040002 */ 	addiu	$a0,$zero,0x2
/*  f0c6658:	1000003e */ 	beqz	$zero,.NB0f0c6754
/*  f0c665c:	8e450284 */ 	lw	$a1,0x284($s2)
.NB0f0c6660:
/*  f0c6660:	0fc5ce24 */ 	jal	mpPushPauseDialog
/*  f0c6664:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c6668:	1000003a */ 	beqz	$zero,.NB0f0c6754
/*  f0c666c:	8e450284 */ 	lw	$a1,0x284($s2)
/*  f0c6670:	8e480314 */ 	lw	$t0,0x314($s2)
.NB0f0c6674:
/*  f0c6674:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0c6678:	51000036 */ 	beqzl	$t0,.NB0f0c6754
/*  f0c667c:	8e450284 */ 	lw	$a1,0x284($s2)
/*  f0c6680:	8e49006c */ 	lw	$t1,0x6c($s2)
/*  f0c6684:	00002825 */ 	or	$a1,$zero,$zero
/*  f0c6688:	00001025 */ 	or	$v0,$zero,$zero
/*  f0c668c:	11200003 */ 	beqz	$t1,.NB0f0c669c
/*  f0c6690:	00001825 */ 	or	$v1,$zero,$zero
/*  f0c6694:	10000001 */ 	beqz	$zero,.NB0f0c669c
/*  f0c6698:	24050001 */ 	addiu	$a1,$zero,0x1
.NB0f0c669c:
/*  f0c669c:	8e4a0068 */ 	lw	$t2,0x68($s2)
/*  f0c66a0:	00002025 */ 	or	$a0,$zero,$zero
/*  f0c66a4:	11400003 */ 	beqz	$t2,.NB0f0c66b4
/*  f0c66a8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c66ac:	10000001 */ 	beqz	$zero,.NB0f0c66b4
/*  f0c66b0:	24020001 */ 	addiu	$v0,$zero,0x1
.NB0f0c66b4:
/*  f0c66b4:	8e4b0064 */ 	lw	$t3,0x64($s2)
/*  f0c66b8:	11600003 */ 	beqz	$t3,.NB0f0c66c8
/*  f0c66bc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c66c0:	10000001 */ 	beqz	$zero,.NB0f0c66c8
/*  f0c66c4:	24030001 */ 	addiu	$v1,$zero,0x1
.NB0f0c66c8:
/*  f0c66c8:	8e4c0070 */ 	lw	$t4,0x70($s2)
/*  f0c66cc:	11800003 */ 	beqz	$t4,.NB0f0c66dc
/*  f0c66d0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c66d4:	10000001 */ 	beqz	$zero,.NB0f0c66dc
/*  f0c66d8:	24040001 */ 	addiu	$a0,$zero,0x1
.NB0f0c66dc:
/*  f0c66dc:	00836821 */ 	addu	$t5,$a0,$v1
/*  f0c66e0:	01a27021 */ 	addu	$t6,$t5,$v0
/*  f0c66e4:	01c57821 */ 	addu	$t7,$t6,$a1
/*  f0c66e8:	15e10010 */ 	bne	$t7,$at,.NB0f0c672c
/*  f0c66ec:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c66f0:	0fc60e8c */ 	jal	mpIsPaused
/*  f0c66f4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c66f8:	10400015 */ 	beqz	$v0,.NB0f0c6750
/*  f0c66fc:	97b801a0 */ 	lhu	$t8,0x1a0($sp)
/*  f0c6700:	33191000 */ 	andi	$t9,$t8,0x1000
/*  f0c6704:	13200012 */ 	beqz	$t9,.NB0f0c6750
/*  f0c6708:	3c08800b */ 	lui	$t0,0x800b
/*  f0c670c:	91081456 */ 	lbu	$t0,0x1456($t0)
/*  f0c6710:	24010002 */ 	addiu	$at,$zero,0x2
/*  f0c6714:	5101000f */ 	beql	$t0,$at,.NB0f0c6754
/*  f0c6718:	8e450284 */ 	lw	$a1,0x284($s2)
/*  f0c671c:	0fc60ec7 */ 	jal	mpSetPaused
/*  f0c6720:	00002025 */ 	or	$a0,$zero,$zero
/*  f0c6724:	1000000b */ 	beqz	$zero,.NB0f0c6754
/*  f0c6728:	8e450284 */ 	lw	$a1,0x284($s2)
.NB0f0c672c:
/*  f0c672c:	0fc60e8c */ 	jal	mpIsPaused
/*  f0c6730:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c6734:	10400006 */ 	beqz	$v0,.NB0f0c6750
/*  f0c6738:	97a901a0 */ 	lhu	$t1,0x1a0($sp)
/*  f0c673c:	312a1000 */ 	andi	$t2,$t1,0x1000
/*  f0c6740:	51400004 */ 	beqzl	$t2,.NB0f0c6754
/*  f0c6744:	8e450284 */ 	lw	$a1,0x284($s2)
/*  f0c6748:	0fc5ce24 */ 	jal	mpPushPauseDialog
/*  f0c674c:	00000000 */ 	sll	$zero,$zero,0x0
.NB0f0c6750:
/*  f0c6750:	8e450284 */ 	lw	$a1,0x284($s2)
.NB0f0c6754:
/*  f0c6754:	8cab1a24 */ 	lw	$t3,0x1a24($a1)
/*  f0c6758:	55600675 */ 	bnezl	$t3,.NB0f0c8130
/*  f0c675c:	aca000d0 */ 	sw	$zero,0xd0($a1)
/*  f0c6760:	8cac00d8 */ 	lw	$t4,0xd8($a1)
/*  f0c6764:	8fa201b0 */ 	lw	$v0,0x1b0($sp)
/*  f0c6768:	24010006 */ 	addiu	$at,$zero,0x6
/*  f0c676c:	55800670 */ 	bnezl	$t4,.NB0f0c8130
/*  f0c6770:	aca000d0 */ 	sw	$zero,0xd0($a1)
/*  f0c6774:	10410007 */ 	beq	$v0,$at,.NB0f0c6794
/*  f0c6778:	24010007 */ 	addiu	$at,$zero,0x7
/*  f0c677c:	10410005 */ 	beq	$v0,$at,.NB0f0c6794
/*  f0c6780:	24010005 */ 	addiu	$at,$zero,0x5
/*  f0c6784:	10410003 */ 	beq	$v0,$at,.NB0f0c6794
/*  f0c6788:	24010004 */ 	addiu	$at,$zero,0x4
/*  f0c678c:	5441033f */ 	bnel	$v0,$at,.NB0f0c748c
/*  f0c6790:	24010002 */ 	addiu	$at,$zero,0x2
.NB0f0c6794:
/*  f0c6794:	8e4d0288 */ 	lw	$t5,0x288($s2)
/*  f0c6798:	0fc53395 */ 	jal	optionsGetContpadNum2
/*  f0c679c:	8da40070 */ 	lw	$a0,0x70($t5)
/*  f0c67a0:	0002a600 */ 	sll	$s4,$v0,0x18
/*  f0c67a4:	00022600 */ 	sll	$a0,$v0,0x18
/*  f0c67a8:	00147603 */ 	sra	$t6,$s4,0x18
/*  f0c67ac:	00047e03 */ 	sra	$t7,$a0,0x18
/*  f0c67b0:	01c0a025 */ 	or	$s4,$t6,$zero
/*  f0c67b4:	0c00573c */ 	jal	joyGetStickX
/*  f0c67b8:	01e02025 */ 	or	$a0,$t7,$zero
/*  f0c67bc:	00142600 */ 	sll	$a0,$s4,0x18
/*  f0c67c0:	0004c603 */ 	sra	$t8,$a0,0x18
/*  f0c67c4:	a3a200e9 */ 	sb	$v0,0xe9($sp)
/*  f0c67c8:	0c005766 */ 	jal	joyGetStickY
/*  f0c67cc:	03002025 */ 	or	$a0,$t8,$zero
/*  f0c67d0:	00028600 */ 	sll	$s0,$v0,0x18
/*  f0c67d4:	00142600 */ 	sll	$a0,$s4,0x18
/*  f0c67d8:	0010ce03 */ 	sra	$t9,$s0,0x18
/*  f0c67dc:	00044603 */ 	sra	$t0,$a0,0x18
/*  f0c67e0:	03208025 */ 	or	$s0,$t9,$zero
/*  f0c67e4:	01002025 */ 	or	$a0,$t0,$zero
/*  f0c67e8:	0c005790 */ 	jal	joyGetButtons
/*  f0c67ec:	3405ffff */ 	dli	$a1,0xffff
/*  f0c67f0:	00142600 */ 	sll	$a0,$s4,0x18
/*  f0c67f4:	00044e03 */ 	sra	$t1,$a0,0x18
/*  f0c67f8:	a7a200e6 */ 	sh	$v0,0xe6($sp)
/*  f0c67fc:	01202025 */ 	or	$a0,$t1,$zero
/*  f0c6800:	0c0057c0 */ 	jal	joyGetButtonsPressedThisFrame
/*  f0c6804:	3405ffff */ 	dli	$a1,0xffff
/*  f0c6808:	8e4b0284 */ 	lw	$t3,0x284($s2)
/*  f0c680c:	340affff */ 	dli	$t2,0xffff
/*  f0c6810:	a7a200e4 */ 	sh	$v0,0xe4($sp)
/*  f0c6814:	a7aa00da */ 	sh	$t2,0xda($sp)
/*  f0c6818:	8d631c40 */ 	lw	$v1,0x1c40($t3)
/*  f0c681c:	83b300e9 */ 	lb	$s3,0xe9($sp)
/*  f0c6820:	02002025 */ 	or	$a0,$s0,$zero
/*  f0c6824:	00036402 */ 	srl	$t4,$v1,0x10
/*  f0c6828:	5180001b */ 	beqzl	$t4,.NB0f0c6898
/*  f0c682c:	8faf026c */ 	lw	$t7,0x26c($sp)
/*  f0c6830:	afb000dc */ 	sw	$s0,0xdc($sp)
/*  f0c6834:	00038c02 */ 	srl	$s1,$v1,0x10
/*  f0c6838:	3230ffff */ 	andi	$s0,$s1,0xffff
/*  f0c683c:	00142600 */ 	sll	$a0,$s4,0x18
/*  f0c6840:	02007027 */ 	nor	$t6,$s0,$zero
/*  f0c6844:	00047e03 */ 	sra	$t7,$a0,0x18
/*  f0c6848:	a7ae00da */ 	sh	$t6,0xda($sp)
/*  f0c684c:	01e02025 */ 	or	$a0,$t7,$zero
/*  f0c6850:	0c005790 */ 	jal	joyGetButtons
/*  f0c6854:	3405ffff */ 	dli	$a1,0xffff
/*  f0c6858:	97b900e6 */ 	lhu	$t9,0xe6($sp)
/*  f0c685c:	97a900e4 */ 	lhu	$t1,0xe4($sp)
/*  f0c6860:	0050c024 */ 	and	$t8,$v0,$s0
/*  f0c6864:	03001827 */ 	nor	$v1,$t8,$zero
/*  f0c6868:	8e450284 */ 	lw	$a1,0x284($s2)
/*  f0c686c:	03234024 */ 	and	$t0,$t9,$v1
/*  f0c6870:	01235024 */ 	and	$t2,$t1,$v1
/*  f0c6874:	a7a800e6 */ 	sh	$t0,0xe6($sp)
/*  f0c6878:	a7aa00e4 */ 	sh	$t2,0xe4($sp)
/*  f0c687c:	8cab1c40 */ 	lw	$t3,0x1c40($a1)
/*  f0c6880:	00186c00 */ 	sll	$t5,$t8,0x10
/*  f0c6884:	316cffff */ 	andi	$t4,$t3,0xffff
/*  f0c6888:	018d7025 */ 	or	$t6,$t4,$t5
/*  f0c688c:	acae1c40 */ 	sw	$t6,0x1c40($a1)
/*  f0c6890:	8fa400dc */ 	lw	$a0,0xdc($sp)
/*  f0c6894:	8faf026c */ 	lw	$t7,0x26c($sp)
.NB0f0c6898:
/*  f0c6898:	51e00007 */ 	beqzl	$t7,.NB0f0c68b8
/*  f0c689c:	2a61fffb */ 	slti	$at,$s3,-5
/*  f0c68a0:	a3a000e9 */ 	sb	$zero,0xe9($sp)
/*  f0c68a4:	a7a000e6 */ 	sh	$zero,0xe6($sp)
/*  f0c68a8:	00009825 */ 	or	$s3,$zero,$zero
/*  f0c68ac:	00002025 */ 	or	$a0,$zero,$zero
/*  f0c68b0:	a7a000e4 */ 	sh	$zero,0xe4($sp)
/*  f0c68b4:	2a61fffb */ 	slti	$at,$s3,-5
.NB0f0c68b8:
/*  f0c68b8:	10200003 */ 	beqz	$at,.NB0f0c68c8
/*  f0c68bc:	8fa201b0 */ 	lw	$v0,0x1b0($sp)
/*  f0c68c0:	10000007 */ 	beqz	$zero,.NB0f0c68e0
/*  f0c68c4:	26730005 */ 	addiu	$s3,$s3,0x5
.NB0f0c68c8:
/*  f0c68c8:	2a610006 */ 	slti	$at,$s3,0x6
/*  f0c68cc:	54200004 */ 	bnezl	$at,.NB0f0c68e0
/*  f0c68d0:	00009825 */ 	or	$s3,$zero,$zero
/*  f0c68d4:	10000002 */ 	beqz	$zero,.NB0f0c68e0
/*  f0c68d8:	2673fffb */ 	addiu	$s3,$s3,-5
/*  f0c68dc:	00009825 */ 	or	$s3,$zero,$zero
.NB0f0c68e0:
/*  f0c68e0:	2881fffb */ 	slti	$at,$a0,-5
/*  f0c68e4:	50200004 */ 	beqzl	$at,.NB0f0c68f8
/*  f0c68e8:	28810006 */ 	slti	$at,$a0,0x6
/*  f0c68ec:	10000007 */ 	beqz	$zero,.NB0f0c690c
/*  f0c68f0:	24840005 */ 	addiu	$a0,$a0,0x5
/*  f0c68f4:	28810006 */ 	slti	$at,$a0,0x6
.NB0f0c68f8:
/*  f0c68f8:	54200004 */ 	bnezl	$at,.NB0f0c690c
/*  f0c68fc:	00002025 */ 	or	$a0,$zero,$zero
/*  f0c6900:	10000002 */ 	beqz	$zero,.NB0f0c690c
/*  f0c6904:	2484fffb */ 	addiu	$a0,$a0,-5
/*  f0c6908:	00002025 */ 	or	$a0,$zero,$zero
.NB0f0c690c:
/*  f0c690c:	24010004 */ 	addiu	$at,$zero,0x4
/*  f0c6910:	10410003 */ 	beq	$v0,$at,.NB0f0c6920
/*  f0c6914:	24010006 */ 	addiu	$at,$zero,0x6
/*  f0c6918:	54410005 */ 	bnel	$v0,$at,.NB0f0c6930
/*  f0c691c:	afb30258 */ 	sw	$s3,0x258($sp)
.NB0f0c6920:
/*  f0c6920:	afb30258 */ 	sw	$s3,0x258($sp)
/*  f0c6924:	10000003 */ 	beqz	$zero,.NB0f0c6934
/*  f0c6928:	afa40254 */ 	sw	$a0,0x254($sp)
/*  f0c692c:	afb30258 */ 	sw	$s3,0x258($sp)
.NB0f0c6930:
/*  f0c6930:	afa4025c */ 	sw	$a0,0x25c($sp)
.NB0f0c6934:
/*  f0c6934:	8e5802ac */ 	lw	$t8,0x2ac($s2)
/*  f0c6938:	24010007 */ 	addiu	$at,$zero,0x7
/*  f0c693c:	afa400dc */ 	sw	$a0,0xdc($sp)
/*  f0c6940:	5701000b */ 	bnel	$t8,$at,.NB0f0c6970
/*  f0c6944:	24010004 */ 	addiu	$at,$zero,0x4
/*  f0c6948:	8e450284 */ 	lw	$a1,0x284($s2)
/*  f0c694c:	afa001d4 */ 	sw	$zero,0x1d4($sp)
/*  f0c6950:	afa001d8 */ 	sw	$zero,0x1d8($sp)
/*  f0c6954:	afa00258 */ 	sw	$zero,0x258($sp)
/*  f0c6958:	8cb91bdc */ 	lw	$t9,0x1bdc($a1)
/*  f0c695c:	afb9025c */ 	sw	$t9,0x25c($sp)
/*  f0c6960:	8ca81bd8 */ 	lw	$t0,0x1bd8($a1)
/*  f0c6964:	afa00254 */ 	sw	$zero,0x254($sp)
/*  f0c6968:	afa80250 */ 	sw	$t0,0x250($sp)
/*  f0c696c:	24010004 */ 	addiu	$at,$zero,0x4
.NB0f0c6970:
/*  f0c6970:	10410005 */ 	beq	$v0,$at,.NB0f0c6988
/*  f0c6974:	8fa400dc */ 	lw	$a0,0xdc($sp)
/*  f0c6978:	24010005 */ 	addiu	$at,$zero,0x5
/*  f0c697c:	1441000b */ 	bne	$v0,$at,.NB0f0c69ac
/*  f0c6980:	00158e00 */ 	sll	$s1,$s5,0x18
/*  f0c6984:	afa400dc */ 	sw	$a0,0xdc($sp)
.NB0f0c6988:
/*  f0c6988:	97aa00da */ 	lhu	$t2,0xda($sp)
/*  f0c698c:	97ab019e */ 	lhu	$t3,0x19e($sp)
/*  f0c6990:	00148e00 */ 	sll	$s1,$s4,0x18
/*  f0c6994:	00114e03 */ 	sra	$t1,$s1,0x18
/*  f0c6998:	01208825 */ 	or	$s1,$t1,$zero
/*  f0c699c:	a3b500ef */ 	sb	$s5,0xef($sp)
/*  f0c69a0:	a7aa00ec */ 	sh	$t2,0xec($sp)
/*  f0c69a4:	10000009 */ 	beqz	$zero,.NB0f0c69cc
/*  f0c69a8:	a7ab00ea */ 	sh	$t3,0xea($sp)
.NB0f0c69ac:
/*  f0c69ac:	97ad019e */ 	lhu	$t5,0x19e($sp)
/*  f0c69b0:	97ae00da */ 	lhu	$t6,0xda($sp)
/*  f0c69b4:	00116603 */ 	sra	$t4,$s1,0x18
/*  f0c69b8:	afa400dc */ 	sw	$a0,0xdc($sp)
/*  f0c69bc:	01808825 */ 	or	$s1,$t4,$zero
/*  f0c69c0:	a3b400ef */ 	sb	$s4,0xef($sp)
/*  f0c69c4:	a7ad00ec */ 	sh	$t5,0xec($sp)
/*  f0c69c8:	a7ae00ea */ 	sh	$t6,0xea($sp)
.NB0f0c69cc:
/*  f0c69cc:	8e4f0288 */ 	lw	$t7,0x288($s2)
/*  f0c69d0:	0fc533b7 */ 	jal	optionsGetAimControl
/*  f0c69d4:	8de40070 */ 	lw	$a0,0x70($t7)
/*  f0c69d8:	1440001f */ 	bnez	$v0,.NB0f0c6a58
/*  f0c69dc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c69e0:	1ac00018 */ 	blez	$s6,.NB0f0c6a44
/*  f0c69e4:	00008025 */ 	or	$s0,$zero,$zero
/*  f0c69e8:	27a3014c */ 	addiu	$v1,$sp,0x14c
/*  f0c69ec:	27a700fc */ 	addiu	$a3,$sp,0xfc
.NB0f0c69f0:
/*  f0c69f0:	12e0000d */ 	beqz	$s7,.NB0f0c6a28
/*  f0c69f4:	02e02025 */ 	or	$a0,$s7,$zero
/*  f0c69f8:	97b900ec */ 	lhu	$t9,0xec($sp)
/*  f0c69fc:	00112e00 */ 	sll	$a1,$s1,0x18
/*  f0c6a00:	0005c603 */ 	sra	$t8,$a1,0x18
/*  f0c6a04:	03002825 */ 	or	$a1,$t8,$zero
/*  f0c6a08:	02002025 */ 	or	$a0,$s0,$zero
/*  f0c6a0c:	afa3004c */ 	sw	$v1,0x4c($sp)
/*  f0c6a10:	afa70048 */ 	sw	$a3,0x48($sp)
/*  f0c6a14:	0c005656 */ 	jal	joyGetButtonsOnSample
/*  f0c6a18:	33262000 */ 	andi	$a2,$t9,0x2000
/*  f0c6a1c:	8fa3004c */ 	lw	$v1,0x4c($sp)
/*  f0c6a20:	8fa70048 */ 	lw	$a3,0x48($sp)
/*  f0c6a24:	0002202b */ 	sltu	$a0,$zero,$v0
.NB0f0c6a28:
/*  f0c6a28:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f0c6a2c:	2c890001 */ 	sltiu	$t1,$a0,0x1
/*  f0c6a30:	24630004 */ 	addiu	$v1,$v1,0x4
/*  f0c6a34:	24e70004 */ 	addiu	$a3,$a3,0x4
/*  f0c6a38:	ac64fffc */ 	sw	$a0,-0x4($v1)
/*  f0c6a3c:	1616ffec */ 	bne	$s0,$s6,.NB0f0c69f0
/*  f0c6a40:	ace9fffc */ 	sw	$t1,-0x4($a3)
.NB0f0c6a44:
/*  f0c6a44:	00165080 */ 	sll	$t2,$s6,0x2
/*  f0c6a48:	03aa5821 */ 	addu	$t3,$sp,$t2
/*  f0c6a4c:	8d6b0148 */ 	lw	$t3,0x148($t3)
/*  f0c6a50:	8e4c0284 */ 	lw	$t4,0x284($s2)
/*  f0c6a54:	ad8b0120 */ 	sw	$t3,0x120($t4)
.NB0f0c6a58:
/*  f0c6a58:	0fc59ed0 */ 	jal	lvIsPaused
/*  f0c6a5c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c6a60:	54400243 */ 	bnezl	$v0,.NB0f0c7370
/*  f0c6a64:	8e450284 */ 	lw	$a1,0x284($s2)
/*  f0c6a68:	8e4d0288 */ 	lw	$t5,0x288($s2)
/*  f0c6a6c:	0fc533b7 */ 	jal	optionsGetAimControl
/*  f0c6a70:	8da40070 */ 	lw	$a0,0x70($t5)
/*  f0c6a74:	1040001f */ 	beqz	$v0,.NB0f0c6af4
/*  f0c6a78:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c6a7c:	1ac0001d */ 	blez	$s6,.NB0f0c6af4
/*  f0c6a80:	00008025 */ 	or	$s0,$zero,$zero
/*  f0c6a84:	27a3014c */ 	addiu	$v1,$sp,0x14c
/*  f0c6a88:	27a700fc */ 	addiu	$a3,$sp,0xfc
.NB0f0c6a8c:
/*  f0c6a8c:	12e00010 */ 	beqz	$s7,.NB0f0c6ad0
/*  f0c6a90:	02002025 */ 	or	$a0,$s0,$zero
/*  f0c6a94:	97af00ec */ 	lhu	$t7,0xec($sp)
/*  f0c6a98:	00112e00 */ 	sll	$a1,$s1,0x18
/*  f0c6a9c:	00057603 */ 	sra	$t6,$a1,0x18
/*  f0c6aa0:	01c02825 */ 	or	$a1,$t6,$zero
/*  f0c6aa4:	afa3004c */ 	sw	$v1,0x4c($sp)
/*  f0c6aa8:	afa70048 */ 	sw	$a3,0x48($sp)
/*  f0c6aac:	0c00568c */ 	jal	joyGetButtonsPressedOnSample
/*  f0c6ab0:	31e62000 */ 	andi	$a2,$t7,0x2000
/*  f0c6ab4:	8fa3004c */ 	lw	$v1,0x4c($sp)
/*  f0c6ab8:	10400005 */ 	beqz	$v0,.NB0f0c6ad0
/*  f0c6abc:	8fa70048 */ 	lw	$a3,0x48($sp)
/*  f0c6ac0:	8e450284 */ 	lw	$a1,0x284($s2)
/*  f0c6ac4:	8ca40120 */ 	lw	$a0,0x120($a1)
/*  f0c6ac8:	2c990001 */ 	sltiu	$t9,$a0,0x1
/*  f0c6acc:	acb90120 */ 	sw	$t9,0x120($a1)
.NB0f0c6ad0:
/*  f0c6ad0:	8e480284 */ 	lw	$t0,0x284($s2)
/*  f0c6ad4:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f0c6ad8:	24630004 */ 	addiu	$v1,$v1,0x4
/*  f0c6adc:	8d090120 */ 	lw	$t1,0x120($t0)
/*  f0c6ae0:	24e70004 */ 	addiu	$a3,$a3,0x4
/*  f0c6ae4:	2d2a0001 */ 	sltiu	$t2,$t1,0x1
/*  f0c6ae8:	aceafffc */ 	sw	$t2,-0x4($a3)
/*  f0c6aec:	1616ffe7 */ 	bne	$s0,$s6,.NB0f0c6a8c
/*  f0c6af0:	ac69fffc */ 	sw	$t1,-0x4($v1)
.NB0f0c6af4:
/*  f0c6af4:	0fc27dd7 */ 	jal	bgunGetWeaponNum
/*  f0c6af8:	00002025 */ 	or	$a0,$zero,$zero
/*  f0c6afc:	24010032 */ 	addiu	$at,$zero,0x32
/*  f0c6b00:	54410005 */ 	bnel	$v0,$at,.NB0f0c6b18
/*  f0c6b04:	8e450284 */ 	lw	$a1,0x284($s2)
/*  f0c6b08:	8e4c0284 */ 	lw	$t4,0x284($s2)
/*  f0c6b0c:	240b0001 */ 	addiu	$t3,$zero,0x1
/*  f0c6b10:	ad8b0120 */ 	sw	$t3,0x120($t4)
/*  f0c6b14:	8e450284 */ 	lw	$a1,0x284($s2)
.NB0f0c6b18:
/*  f0c6b18:	24190001 */ 	addiu	$t9,$zero,0x1
/*  f0c6b1c:	8ca40120 */ 	lw	$a0,0x120($a1)
/*  f0c6b20:	2c8d0001 */ 	sltiu	$t5,$a0,0x1
/*  f0c6b24:	afad01b4 */ 	sw	$t5,0x1b4($sp)
/*  f0c6b28:	8cae0120 */ 	lw	$t6,0x120($a1)
/*  f0c6b2c:	afae01b8 */ 	sw	$t6,0x1b8($sp)
/*  f0c6b30:	8ca40120 */ 	lw	$a0,0x120($a1)
/*  f0c6b34:	afa001d4 */ 	sw	$zero,0x1d4($sp)
/*  f0c6b38:	afa001d8 */ 	sw	$zero,0x1d8($sp)
/*  f0c6b3c:	2c8f0001 */ 	sltiu	$t7,$a0,0x1
/*  f0c6b40:	afaf022c */ 	sw	$t7,0x22c($sp)
/*  f0c6b44:	afa001dc */ 	sw	$zero,0x1dc($sp)
/*  f0c6b48:	afa001e0 */ 	sw	$zero,0x1e0($sp)
/*  f0c6b4c:	8ca40120 */ 	lw	$a0,0x120($a1)
/*  f0c6b50:	afb901c8 */ 	sw	$t9,0x1c8($sp)
/*  f0c6b54:	2c980001 */ 	sltiu	$t8,$a0,0x1
/*  f0c6b58:	afb801c4 */ 	sw	$t8,0x1c4($sp)
/*  f0c6b5c:	8ca40120 */ 	lw	$a0,0x120($a1)
/*  f0c6b60:	2c880001 */ 	sltiu	$t0,$a0,0x1
/*  f0c6b64:	afa801cc */ 	sw	$t0,0x1cc($sp)
/*  f0c6b68:	8ca40120 */ 	lw	$a0,0x120($a1)
/*  f0c6b6c:	2c890001 */ 	sltiu	$t1,$a0,0x1
/*  f0c6b70:	afa901d0 */ 	sw	$t1,0x1d0($sp)
/*  f0c6b74:	8caa0120 */ 	lw	$t2,0x120($a1)
/*  f0c6b78:	51400015 */ 	beqzl	$t2,.NB0f0c6bd0
/*  f0c6b7c:	44809000 */ 	mtc1	$zero,$f18
/*  f0c6b80:	8fa4024c */ 	lw	$a0,0x24c($sp)
/*  f0c6b84:	2881003d */ 	slti	$at,$a0,0x3d
/*  f0c6b88:	14200010 */ 	bnez	$at,.NB0f0c6bcc
/*  f0c6b8c:	248bffc4 */ 	addiu	$t3,$a0,-60
/*  f0c6b90:	448b2000 */ 	mtc1	$t3,$f4
/*  f0c6b94:	3c014120 */ 	lui	$at,0x4120
/*  f0c6b98:	44811000 */ 	mtc1	$at,$f2
/*  f0c6b9c:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f0c6ba0:	3c013f80 */ 	lui	$at,0x3f80
/*  f0c6ba4:	44815000 */ 	mtc1	$at,$f10
/*  f0c6ba8:	3c013f80 */ 	lui	$at,0x3f80
/*  f0c6bac:	46023203 */ 	div.s	$f8,$f6,$f2
/*  f0c6bb0:	4608503c */ 	c.lt.s	$f10,$f8
/*  f0c6bb4:	e7a801ec */ 	swc1	$f8,0x1ec($sp)
/*  f0c6bb8:	45020009 */ 	bc1fl	.NB0f0c6be0
/*  f0c6bbc:	8cac0120 */ 	lw	$t4,0x120($a1)
/*  f0c6bc0:	44818000 */ 	mtc1	$at,$f16
/*  f0c6bc4:	10000005 */ 	beqz	$zero,.NB0f0c6bdc
/*  f0c6bc8:	e7b001ec */ 	swc1	$f16,0x1ec($sp)
.NB0f0c6bcc:
/*  f0c6bcc:	44809000 */ 	mtc1	$zero,$f18
.NB0f0c6bd0:
/*  f0c6bd0:	3c014120 */ 	lui	$at,0x4120
/*  f0c6bd4:	44811000 */ 	mtc1	$at,$f2
/*  f0c6bd8:	e7b201ec */ 	swc1	$f18,0x1ec($sp)
.NB0f0c6bdc:
/*  f0c6bdc:	8cac0120 */ 	lw	$t4,0x120($a1)
.NB0f0c6be0:
/*  f0c6be0:	51800014 */ 	beqzl	$t4,.NB0f0c6c34
/*  f0c6be4:	44809000 */ 	mtc1	$zero,$f18
/*  f0c6be8:	8fa4024c */ 	lw	$a0,0x24c($sp)
/*  f0c6bec:	240dffc4 */ 	addiu	$t5,$zero,-60
/*  f0c6bf0:	2881ffc4 */ 	slti	$at,$a0,-60
/*  f0c6bf4:	1020000e */ 	beqz	$at,.NB0f0c6c30
/*  f0c6bf8:	01a47023 */ 	subu	$t6,$t5,$a0
/*  f0c6bfc:	448e2000 */ 	mtc1	$t6,$f4
/*  f0c6c00:	3c013f80 */ 	lui	$at,0x3f80
/*  f0c6c04:	44814000 */ 	mtc1	$at,$f8
/*  f0c6c08:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f0c6c0c:	3c013f80 */ 	lui	$at,0x3f80
/*  f0c6c10:	46023283 */ 	div.s	$f10,$f6,$f2
/*  f0c6c14:	460a403c */ 	c.lt.s	$f8,$f10
/*  f0c6c18:	e7aa01f0 */ 	swc1	$f10,0x1f0($sp)
/*  f0c6c1c:	45020008 */ 	bc1fl	.NB0f0c6c40
/*  f0c6c20:	8caf0120 */ 	lw	$t7,0x120($a1)
/*  f0c6c24:	44818000 */ 	mtc1	$at,$f16
/*  f0c6c28:	10000004 */ 	beqz	$zero,.NB0f0c6c3c
/*  f0c6c2c:	e7b001f0 */ 	swc1	$f16,0x1f0($sp)
.NB0f0c6c30:
/*  f0c6c30:	44809000 */ 	mtc1	$zero,$f18
.NB0f0c6c34:
/*  f0c6c34:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c6c38:	e7b201f0 */ 	swc1	$f18,0x1f0($sp)
.NB0f0c6c3c:
/*  f0c6c3c:	8caf0120 */ 	lw	$t7,0x120($a1)
.NB0f0c6c40:
/*  f0c6c40:	8fa30248 */ 	lw	$v1,0x248($sp)
/*  f0c6c44:	11e00011 */ 	beqz	$t7,.NB0f0c6c8c
/*  f0c6c48:	2861ffc4 */ 	slti	$at,$v1,-60
/*  f0c6c4c:	1020000f */ 	beqz	$at,.NB0f0c6c8c
/*  f0c6c50:	2418ffc4 */ 	addiu	$t8,$zero,-60
/*  f0c6c54:	0303c823 */ 	subu	$t9,$t8,$v1
/*  f0c6c58:	44992000 */ 	mtc1	$t9,$f4
/*  f0c6c5c:	3c013f80 */ 	lui	$at,0x3f80
/*  f0c6c60:	44814000 */ 	mtc1	$at,$f8
/*  f0c6c64:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f0c6c68:	3c013f80 */ 	lui	$at,0x3f80
/*  f0c6c6c:	46023303 */ 	div.s	$f12,$f6,$f2
/*  f0c6c70:	460c403c */ 	c.lt.s	$f8,$f12
/*  f0c6c74:	e7ac01f4 */ 	swc1	$f12,0x1f4($sp)
/*  f0c6c78:	45020008 */ 	bc1fl	.NB0f0c6c9c
/*  f0c6c7c:	8ca80120 */ 	lw	$t0,0x120($a1)
/*  f0c6c80:	44816000 */ 	mtc1	$at,$f12
/*  f0c6c84:	10000004 */ 	beqz	$zero,.NB0f0c6c98
/*  f0c6c88:	e7ac01f4 */ 	swc1	$f12,0x1f4($sp)
.NB0f0c6c8c:
/*  f0c6c8c:	44806000 */ 	mtc1	$zero,$f12
/*  f0c6c90:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c6c94:	e7ac01f4 */ 	swc1	$f12,0x1f4($sp)
.NB0f0c6c98:
/*  f0c6c98:	8ca80120 */ 	lw	$t0,0x120($a1)
.NB0f0c6c9c:
/*  f0c6c9c:	8fa30248 */ 	lw	$v1,0x248($sp)
/*  f0c6ca0:	11000010 */ 	beqz	$t0,.NB0f0c6ce4
/*  f0c6ca4:	2861003d */ 	slti	$at,$v1,0x3d
/*  f0c6ca8:	1420000e */ 	bnez	$at,.NB0f0c6ce4
/*  f0c6cac:	2469ffc4 */ 	addiu	$t1,$v1,-60
/*  f0c6cb0:	44895000 */ 	mtc1	$t1,$f10
/*  f0c6cb4:	3c013f80 */ 	lui	$at,0x3f80
/*  f0c6cb8:	44819000 */ 	mtc1	$at,$f18
/*  f0c6cbc:	46805420 */ 	cvt.s.w	$f16,$f10
/*  f0c6cc0:	3c013f80 */ 	lui	$at,0x3f80
/*  f0c6cc4:	46028003 */ 	div.s	$f0,$f16,$f2
/*  f0c6cc8:	4600903c */ 	c.lt.s	$f18,$f0
/*  f0c6ccc:	e7a001f8 */ 	swc1	$f0,0x1f8($sp)
/*  f0c6cd0:	45000007 */ 	bc1f	.NB0f0c6cf0
/*  f0c6cd4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c6cd8:	44810000 */ 	mtc1	$at,$f0
/*  f0c6cdc:	10000004 */ 	beqz	$zero,.NB0f0c6cf0
/*  f0c6ce0:	e7a001f8 */ 	swc1	$f0,0x1f8($sp)
.NB0f0c6ce4:
/*  f0c6ce4:	44800000 */ 	mtc1	$zero,$f0
/*  f0c6ce8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c6cec:	e7a001f8 */ 	swc1	$f0,0x1f8($sp)
.NB0f0c6cf0:
/*  f0c6cf0:	12e0005c */ 	beqz	$s7,.NB0f0c6e64
/*  f0c6cf4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c6cf8:	84a2024c */ 	lh	$v0,0x24c($a1)
/*  f0c6cfc:	2841fffe */ 	slti	$at,$v0,-2
/*  f0c6d00:	10200009 */ 	beqz	$at,.NB0f0c6d28
/*  f0c6d04:	00565021 */ 	addu	$t2,$v0,$s6
/*  f0c6d08:	a4aa024c */ 	sh	$t2,0x24c($a1)
/*  f0c6d0c:	8e450284 */ 	lw	$a1,0x284($s2)
/*  f0c6d10:	84ab024c */ 	lh	$t3,0x24c($a1)
/*  f0c6d14:	2961fffe */ 	slti	$at,$t3,-2
/*  f0c6d18:	14200052 */ 	bnez	$at,.NB0f0c6e64
/*  f0c6d1c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c6d20:	10000050 */ 	beqz	$zero,.NB0f0c6e64
/*  f0c6d24:	a4a0024c */ 	sh	$zero,0x24c($a1)
.NB0f0c6d28:
/*  f0c6d28:	1ac0004e */ 	blez	$s6,.NB0f0c6e64
/*  f0c6d2c:	00008025 */ 	or	$s0,$zero,$zero
/*  f0c6d30:	97ac019e */ 	lhu	$t4,0x19e($sp)
/*  f0c6d34:	2413ffff */ 	addiu	$s3,$zero,-1
/*  f0c6d38:	31918000 */ 	andi	$s1,$t4,0x8000
/*  f0c6d3c:	00152e00 */ 	sll	$a1,$s5,0x18
.NB0f0c6d40:
/*  f0c6d40:	00057603 */ 	sra	$t6,$a1,0x18
/*  f0c6d44:	01c02825 */ 	or	$a1,$t6,$zero
/*  f0c6d48:	02002025 */ 	or	$a0,$s0,$zero
/*  f0c6d4c:	0c005656 */ 	jal	joyGetButtonsOnSample
/*  f0c6d50:	3226ffff */ 	andi	$a2,$s1,0xffff
/*  f0c6d54:	14400009 */ 	bnez	$v0,.NB0f0c6d7c
/*  f0c6d58:	02002025 */ 	or	$a0,$s0,$zero
/*  f0c6d5c:	97b800da */ 	lhu	$t8,0xda($sp)
/*  f0c6d60:	00142e00 */ 	sll	$a1,$s4,0x18
/*  f0c6d64:	00057e03 */ 	sra	$t7,$a1,0x18
/*  f0c6d68:	01e02825 */ 	or	$a1,$t7,$zero
/*  f0c6d6c:	0c005656 */ 	jal	joyGetButtonsOnSample
/*  f0c6d70:	33068000 */ 	andi	$a2,$t8,0x8000
/*  f0c6d74:	50400028 */ 	beqzl	$v0,.NB0f0c6e18
/*  f0c6d78:	8e490284 */ 	lw	$t1,0x284($s2)
.NB0f0c6d7c:
/*  f0c6d7c:	8e480284 */ 	lw	$t0,0x284($s2)
/*  f0c6d80:	97aa00ea */ 	lhu	$t2,0xea($sp)
/*  f0c6d84:	8509024c */ 	lh	$t1,0x24c($t0)
/*  f0c6d88:	31462000 */ 	andi	$a2,$t2,0x2000
/*  f0c6d8c:	2921ffff */ 	slti	$at,$t1,-1
/*  f0c6d90:	14200031 */ 	bnez	$at,.NB0f0c6e58
/*  f0c6d94:	02002025 */ 	or	$a0,$s0,$zero
/*  f0c6d98:	83a500ef */ 	lb	$a1,0xef($sp)
/*  f0c6d9c:	0c00568c */ 	jal	joyGetButtonsPressedOnSample
/*  f0c6da0:	afa6004c */ 	sw	$a2,0x4c($sp)
/*  f0c6da4:	10400006 */ 	beqz	$v0,.NB0f0c6dc0
/*  f0c6da8:	8fa6004c */ 	lw	$a2,0x4c($sp)
/*  f0c6dac:	8fac01fc */ 	lw	$t4,0x1fc($sp)
/*  f0c6db0:	8e4e0284 */ 	lw	$t6,0x284($s2)
/*  f0c6db4:	258d0001 */ 	addiu	$t5,$t4,0x1
/*  f0c6db8:	afad01fc */ 	sw	$t5,0x1fc($sp)
/*  f0c6dbc:	a5d3024c */ 	sh	$s3,0x24c($t6)
.NB0f0c6dc0:
/*  f0c6dc0:	8e4f0284 */ 	lw	$t7,0x284($s2)
/*  f0c6dc4:	02002025 */ 	or	$a0,$s0,$zero
/*  f0c6dc8:	85f8024c */ 	lh	$t8,0x24c($t7)
/*  f0c6dcc:	07020023 */ 	bltzl	$t8,.NB0f0c6e5c
/*  f0c6dd0:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f0c6dd4:	0c005656 */ 	jal	joyGetButtonsOnSample
/*  f0c6dd8:	83a500ef */ 	lb	$a1,0xef($sp)
/*  f0c6ddc:	5440001f */ 	bnezl	$v0,.NB0f0c6e5c
/*  f0c6de0:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f0c6de4:	8e450284 */ 	lw	$a1,0x284($s2)
/*  f0c6de8:	84a2024c */ 	lh	$v0,0x24c($a1)
/*  f0c6dec:	28410010 */ 	slti	$at,$v0,0x10
/*  f0c6df0:	14200006 */ 	bnez	$at,.NB0f0c6e0c
/*  f0c6df4:	24480001 */ 	addiu	$t0,$v0,0x1
/*  f0c6df8:	0fc3ecc4 */ 	jal	amOpen
/*  f0c6dfc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c6e00:	8e590284 */ 	lw	$t9,0x284($s2)
/*  f0c6e04:	10000014 */ 	beqz	$zero,.NB0f0c6e58
/*  f0c6e08:	a733024c */ 	sh	$s3,0x24c($t9)
.NB0f0c6e0c:
/*  f0c6e0c:	10000012 */ 	beqz	$zero,.NB0f0c6e58
/*  f0c6e10:	a4a8024c */ 	sh	$t0,0x24c($a1)
/*  f0c6e14:	8e490284 */ 	lw	$t1,0x284($s2)
.NB0f0c6e18:
/*  f0c6e18:	852a024c */ 	lh	$t2,0x24c($t1)
/*  f0c6e1c:	5940000d */ 	blezl	$t2,.NB0f0c6e54
/*  f0c6e20:	8e4d0284 */ 	lw	$t5,0x284($s2)
/*  f0c6e24:	12e00007 */ 	beqz	$s7,.NB0f0c6e44
/*  f0c6e28:	02002025 */ 	or	$a0,$s0,$zero
/*  f0c6e2c:	97ab00ea */ 	lhu	$t3,0xea($sp)
/*  f0c6e30:	83a500ef */ 	lb	$a1,0xef($sp)
/*  f0c6e34:	0c005656 */ 	jal	joyGetButtonsOnSample
/*  f0c6e38:	31662000 */ 	andi	$a2,$t3,0x2000
/*  f0c6e3c:	54400005 */ 	bnezl	$v0,.NB0f0c6e54
/*  f0c6e40:	8e4d0284 */ 	lw	$t5,0x284($s2)
.NB0f0c6e44:
/*  f0c6e44:	8fa20200 */ 	lw	$v0,0x200($sp)
/*  f0c6e48:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f0c6e4c:	afa20200 */ 	sw	$v0,0x200($sp)
/*  f0c6e50:	8e4d0284 */ 	lw	$t5,0x284($s2)
.NB0f0c6e54:
/*  f0c6e54:	a5a0024c */ 	sh	$zero,0x24c($t5)
.NB0f0c6e58:
/*  f0c6e58:	26100001 */ 	addiu	$s0,$s0,0x1
.NB0f0c6e5c:
/*  f0c6e5c:	5616ffb8 */ 	bnel	$s0,$s6,.NB0f0c6d40
/*  f0c6e60:	00152e00 */ 	sll	$a1,$s5,0x18
.NB0f0c6e64:
/*  f0c6e64:	12e0005e */ 	beqz	$s7,.NB0f0c6fe0
/*  f0c6e68:	2413ffff */ 	addiu	$s3,$zero,-1
/*  f0c6e6c:	1ac0005c */ 	blez	$s6,.NB0f0c6fe0
/*  f0c6e70:	00008025 */ 	or	$s0,$zero,$zero
/*  f0c6e74:	97ae019e */ 	lhu	$t6,0x19e($sp)
/*  f0c6e78:	31cf4000 */ 	andi	$t7,$t6,0x4000
/*  f0c6e7c:	afaf0044 */ 	sw	$t7,0x44($sp)
/*  f0c6e80:	00152e00 */ 	sll	$a1,$s5,0x18
.NB0f0c6e84:
/*  f0c6e84:	0005c603 */ 	sra	$t8,$a1,0x18
/*  f0c6e88:	8fa60044 */ 	lw	$a2,0x44($sp)
/*  f0c6e8c:	03002825 */ 	or	$a1,$t8,$zero
/*  f0c6e90:	0c005656 */ 	jal	joyGetButtonsOnSample
/*  f0c6e94:	02002025 */ 	or	$a0,$s0,$zero
/*  f0c6e98:	14400009 */ 	bnez	$v0,.NB0f0c6ec0
/*  f0c6e9c:	02002025 */ 	or	$a0,$s0,$zero
/*  f0c6ea0:	97a800da */ 	lhu	$t0,0xda($sp)
/*  f0c6ea4:	00142e00 */ 	sll	$a1,$s4,0x18
/*  f0c6ea8:	0005ce03 */ 	sra	$t9,$a1,0x18
/*  f0c6eac:	03202825 */ 	or	$a1,$t9,$zero
/*  f0c6eb0:	0c005656 */ 	jal	joyGetButtonsOnSample
/*  f0c6eb4:	31064000 */ 	andi	$a2,$t0,0x4000
/*  f0c6eb8:	5040003e */ 	beqzl	$v0,.NB0f0c6fb4
/*  f0c6ebc:	8e450284 */ 	lw	$a1,0x284($s2)
.NB0f0c6ec0:
/*  f0c6ec0:	8e4a0284 */ 	lw	$t2,0x284($s2)
/*  f0c6ec4:	97ab00ea */ 	lhu	$t3,0xea($sp)
/*  f0c6ec8:	83a500ef */ 	lb	$a1,0xef($sp)
/*  f0c6ecc:	8544024e */ 	lh	$a0,0x24e($t2)
/*  f0c6ed0:	31662000 */ 	andi	$a2,$t3,0x2000
/*  f0c6ed4:	2881ffff */ 	slti	$at,$a0,-1
/*  f0c6ed8:	5420002f */ 	bnezl	$at,.NB0f0c6f98
/*  f0c6edc:	2881fffe */ 	slti	$at,$a0,-2
/*  f0c6ee0:	0c00568c */ 	jal	joyGetButtonsPressedOnSample
/*  f0c6ee4:	02002025 */ 	or	$a0,$s0,$zero
/*  f0c6ee8:	5040000e */ 	beqzl	$v0,.NB0f0c6f24
/*  f0c6eec:	8e450284 */ 	lw	$a1,0x284($s2)
/*  f0c6ef0:	8e4d0284 */ 	lw	$t5,0x284($s2)
/*  f0c6ef4:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f0c6ef8:	85a4024e */ 	lh	$a0,0x24e($t5)
/*  f0c6efc:	04820009 */ 	bltzl	$a0,.NB0f0c6f24
/*  f0c6f00:	8e450284 */ 	lw	$a1,0x284($s2)
/*  f0c6f04:	0fc299bf */ 	jal	bgunConsiderToggleGunFunction
/*  f0c6f08:	00003025 */ 	or	$a2,$zero,$zero
/*  f0c6f0c:	50400005 */ 	beqzl	$v0,.NB0f0c6f24
/*  f0c6f10:	8e450284 */ 	lw	$a1,0x284($s2)
/*  f0c6f14:	8e4f0284 */ 	lw	$t7,0x284($s2)
/*  f0c6f18:	240efffd */ 	addiu	$t6,$zero,-3
/*  f0c6f1c:	a5ee024e */ 	sh	$t6,0x24e($t7)
/*  f0c6f20:	8e450284 */ 	lw	$a1,0x284($s2)
.NB0f0c6f24:
/*  f0c6f24:	84a4024e */ 	lh	$a0,0x24e($a1)
/*  f0c6f28:	0480002a */ 	bltz	$a0,.NB0f0c6fd4
/*  f0c6f2c:	2881001a */ 	slti	$at,$a0,0x1a
/*  f0c6f30:	14200016 */ 	bnez	$at,.NB0f0c6f8c
/*  f0c6f34:	248b0001 */ 	addiu	$t3,$a0,0x1
/*  f0c6f38:	00002825 */ 	or	$a1,$zero,$zero
/*  f0c6f3c:	0fc299bf */ 	jal	bgunConsiderToggleGunFunction
/*  f0c6f40:	00003025 */ 	or	$a2,$zero,$zero
/*  f0c6f44:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0c6f48:	54410005 */ 	bnel	$v0,$at,.NB0f0c6f60
/*  f0c6f4c:	24010002 */ 	addiu	$at,$zero,0x2
/*  f0c6f50:	8e580284 */ 	lw	$t8,0x284($s2)
/*  f0c6f54:	1000001f */ 	beqz	$zero,.NB0f0c6fd4
/*  f0c6f58:	a713024e */ 	sh	$s3,0x24e($t8)
/*  f0c6f5c:	24010002 */ 	addiu	$at,$zero,0x2
.NB0f0c6f60:
/*  f0c6f60:	54410006 */ 	bnel	$v0,$at,.NB0f0c6f7c
/*  f0c6f64:	8e450284 */ 	lw	$a1,0x284($s2)
/*  f0c6f68:	8e480284 */ 	lw	$t0,0x284($s2)
/*  f0c6f6c:	2419fffe */ 	addiu	$t9,$zero,-2
/*  f0c6f70:	10000018 */ 	beqz	$zero,.NB0f0c6fd4
/*  f0c6f74:	a519024e */ 	sh	$t9,0x24e($t0)
/*  f0c6f78:	8e450284 */ 	lw	$a1,0x284($s2)
.NB0f0c6f7c:
/*  f0c6f7c:	84a9024e */ 	lh	$t1,0x24e($a1)
/*  f0c6f80:	252a0001 */ 	addiu	$t2,$t1,0x1
/*  f0c6f84:	10000013 */ 	beqz	$zero,.NB0f0c6fd4
/*  f0c6f88:	a4aa024e */ 	sh	$t2,0x24e($a1)
.NB0f0c6f8c:
/*  f0c6f8c:	10000011 */ 	beqz	$zero,.NB0f0c6fd4
/*  f0c6f90:	a4ab024e */ 	sh	$t3,0x24e($a1)
/*  f0c6f94:	2881fffe */ 	slti	$at,$a0,-2
.NB0f0c6f98:
/*  f0c6f98:	1420000e */ 	bnez	$at,.NB0f0c6fd4
/*  f0c6f9c:	00002825 */ 	or	$a1,$zero,$zero
/*  f0c6fa0:	0fc299bf */ 	jal	bgunConsiderToggleGunFunction
/*  f0c6fa4:	00003025 */ 	or	$a2,$zero,$zero
/*  f0c6fa8:	1000000b */ 	beqz	$zero,.NB0f0c6fd8
/*  f0c6fac:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f0c6fb0:	8e450284 */ 	lw	$a1,0x284($s2)
.NB0f0c6fb4:
/*  f0c6fb4:	8fad01c0 */ 	lw	$t5,0x1c0($sp)
/*  f0c6fb8:	84ac024e */ 	lh	$t4,0x24e($a1)
/*  f0c6fbc:	25ae0001 */ 	addiu	$t6,$t5,0x1
/*  f0c6fc0:	19800002 */ 	blez	$t4,.NB0f0c6fcc
/*  f0c6fc4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c6fc8:	afae01c0 */ 	sw	$t6,0x1c0($sp)
.NB0f0c6fcc:
/*  f0c6fcc:	0fc29a7c */ 	jal	bgun0f0a8c50
/*  f0c6fd0:	a4a0024e */ 	sh	$zero,0x24e($a1)
.NB0f0c6fd4:
/*  f0c6fd4:	26100001 */ 	addiu	$s0,$s0,0x1
.NB0f0c6fd8:
/*  f0c6fd8:	5616ffaa */ 	bnel	$s0,$s6,.NB0f0c6e84
/*  f0c6fdc:	00152e00 */ 	sll	$a1,$s5,0x18
.NB0f0c6fe0:
/*  f0c6fe0:	8faf01a8 */ 	lw	$t7,0x1a8($sp)
/*  f0c6fe4:	11e0002b */ 	beqz	$t7,.NB0f0c7094
/*  f0c6fe8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c6fec:	8e580284 */ 	lw	$t8,0x284($s2)
/*  f0c6ff0:	8fa800dc */ 	lw	$t0,0xdc($sp)
/*  f0c6ff4:	8f190120 */ 	lw	$t9,0x120($t8)
/*  f0c6ff8:	13200026 */ 	beqz	$t9,.NB0f0c7094
/*  f0c6ffc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c7000:	05010011 */ 	bgez	$t0,.NB0f0c7048
/*  f0c7004:	00084823 */ 	negu	$t1,$t0
/*  f0c7008:	44892000 */ 	mtc1	$t1,$f4
/*  f0c700c:	3c01428c */ 	lui	$at,0x428c
/*  f0c7010:	44814000 */ 	mtc1	$at,$f8
/*  f0c7014:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f0c7018:	3c013f80 */ 	lui	$at,0x3f80
/*  f0c701c:	44815000 */ 	mtc1	$at,$f10
/*  f0c7020:	3c013f80 */ 	lui	$at,0x3f80
/*  f0c7024:	46083303 */ 	div.s	$f12,$f6,$f8
/*  f0c7028:	460c503c */ 	c.lt.s	$f10,$f12
/*  f0c702c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c7030:	45020004 */ 	bc1fl	.NB0f0c7044
/*  f0c7034:	460c6300 */ 	add.s	$f12,$f12,$f12
/*  f0c7038:	44816000 */ 	mtc1	$at,$f12
/*  f0c703c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c7040:	460c6300 */ 	add.s	$f12,$f12,$f12
.NB0f0c7044:
/*  f0c7044:	e7ac0210 */ 	swc1	$f12,0x210($sp)
.NB0f0c7048:
/*  f0c7048:	8faa00dc */ 	lw	$t2,0xdc($sp)
/*  f0c704c:	19400011 */ 	blez	$t2,.NB0f0c7094
/*  f0c7050:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c7054:	448a8000 */ 	mtc1	$t2,$f16
/*  f0c7058:	3c01428c */ 	lui	$at,0x428c
/*  f0c705c:	44812000 */ 	mtc1	$at,$f4
/*  f0c7060:	468084a0 */ 	cvt.s.w	$f18,$f16
/*  f0c7064:	3c013f80 */ 	lui	$at,0x3f80
/*  f0c7068:	44813000 */ 	mtc1	$at,$f6
/*  f0c706c:	3c013f80 */ 	lui	$at,0x3f80
/*  f0c7070:	46049303 */ 	div.s	$f12,$f18,$f4
/*  f0c7074:	460c303c */ 	c.lt.s	$f6,$f12
/*  f0c7078:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c707c:	45020004 */ 	bc1fl	.NB0f0c7090
/*  f0c7080:	460c6300 */ 	add.s	$f12,$f12,$f12
/*  f0c7084:	44816000 */ 	mtc1	$at,$f12
/*  f0c7088:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c708c:	460c6300 */ 	add.s	$f12,$f12,$f12
.NB0f0c7090:
/*  f0c7090:	e7ac0214 */ 	swc1	$f12,0x214($sp)
.NB0f0c7094:
/*  f0c7094:	12e0005a */ 	beqz	$s7,.NB0f0c7200
/*  f0c7098:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c709c:	1ac00058 */ 	blez	$s6,.NB0f0c7200
/*  f0c70a0:	00008025 */ 	or	$s0,$zero,$zero
/*  f0c70a4:	8fab01a8 */ 	lw	$t3,0x1a8($sp)
.NB0f0c70a8:
/*  f0c70a8:	00106080 */ 	sll	$t4,$s0,0x2
/*  f0c70ac:	03ac6821 */ 	addu	$t5,$sp,$t4
/*  f0c70b0:	55600034 */ 	bnezl	$t3,.NB0f0c7184
/*  f0c70b4:	8e4a0288 */ 	lw	$t2,0x288($s2)
/*  f0c70b8:	8dad014c */ 	lw	$t5,0x14c($t5)
/*  f0c70bc:	00142e00 */ 	sll	$a1,$s4,0x18
/*  f0c70c0:	00057603 */ 	sra	$t6,$a1,0x18
/*  f0c70c4:	11a0002e */ 	beqz	$t5,.NB0f0c7180
/*  f0c70c8:	02002025 */ 	or	$a0,$s0,$zero
/*  f0c70cc:	0c0055f9 */ 	jal	joyGetStickYOnSample
/*  f0c70d0:	01c02825 */ 	or	$a1,$t6,$zero
/*  f0c70d4:	2841001f */ 	slti	$at,$v0,0x1f
/*  f0c70d8:	14200011 */ 	bnez	$at,.NB0f0c7120
/*  f0c70dc:	02002025 */ 	or	$a0,$s0,$zero
/*  f0c70e0:	00142e00 */ 	sll	$a1,$s4,0x18
/*  f0c70e4:	00057e03 */ 	sra	$t7,$a1,0x18
/*  f0c70e8:	0c005628 */ 	jal	joyGetStickYOnSampleIndex
/*  f0c70ec:	01e02825 */ 	or	$a1,$t7,$zero
/*  f0c70f0:	2841001f */ 	slti	$at,$v0,0x1f
/*  f0c70f4:	1020000a */ 	beqz	$at,.NB0f0c7120
/*  f0c70f8:	8fa20218 */ 	lw	$v0,0x218($sp)
/*  f0c70fc:	10400003 */ 	beqz	$v0,.NB0f0c710c
/*  f0c7100:	2442ffff */ 	addiu	$v0,$v0,-1
/*  f0c7104:	10000004 */ 	beqz	$zero,.NB0f0c7118
/*  f0c7108:	afa20218 */ 	sw	$v0,0x218($sp)
.NB0f0c710c:
/*  f0c710c:	8fa2021c */ 	lw	$v0,0x21c($sp)
/*  f0c7110:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f0c7114:	afa2021c */ 	sw	$v0,0x21c($sp)
.NB0f0c7118:
/*  f0c7118:	8e580284 */ 	lw	$t8,0x284($s2)
/*  f0c711c:	af130260 */ 	sw	$s3,0x260($t8)
.NB0f0c7120:
/*  f0c7120:	00142e00 */ 	sll	$a1,$s4,0x18
/*  f0c7124:	0005ce03 */ 	sra	$t9,$a1,0x18
/*  f0c7128:	03202825 */ 	or	$a1,$t9,$zero
/*  f0c712c:	0c0055f9 */ 	jal	joyGetStickYOnSample
/*  f0c7130:	02002025 */ 	or	$a0,$s0,$zero
/*  f0c7134:	2841ffe2 */ 	slti	$at,$v0,-30
/*  f0c7138:	10200011 */ 	beqz	$at,.NB0f0c7180
/*  f0c713c:	02002025 */ 	or	$a0,$s0,$zero
/*  f0c7140:	00142e00 */ 	sll	$a1,$s4,0x18
/*  f0c7144:	00054603 */ 	sra	$t0,$a1,0x18
/*  f0c7148:	0c005628 */ 	jal	joyGetStickYOnSampleIndex
/*  f0c714c:	01002825 */ 	or	$a1,$t0,$zero
/*  f0c7150:	2841ffe2 */ 	slti	$at,$v0,-30
/*  f0c7154:	1420000a */ 	bnez	$at,.NB0f0c7180
/*  f0c7158:	8fa2021c */ 	lw	$v0,0x21c($sp)
/*  f0c715c:	10400003 */ 	beqz	$v0,.NB0f0c716c
/*  f0c7160:	2442ffff */ 	addiu	$v0,$v0,-1
/*  f0c7164:	10000004 */ 	beqz	$zero,.NB0f0c7178
/*  f0c7168:	afa2021c */ 	sw	$v0,0x21c($sp)
.NB0f0c716c:
/*  f0c716c:	8fa20218 */ 	lw	$v0,0x218($sp)
/*  f0c7170:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f0c7174:	afa20218 */ 	sw	$v0,0x218($sp)
.NB0f0c7178:
/*  f0c7178:	8e490284 */ 	lw	$t1,0x284($s2)
/*  f0c717c:	ad330260 */ 	sw	$s3,0x260($t1)
.NB0f0c7180:
/*  f0c7180:	8e4a0288 */ 	lw	$t2,0x288($s2)
.NB0f0c7184:
/*  f0c7184:	0fc533b7 */ 	jal	optionsGetAimControl
/*  f0c7188:	8d440070 */ 	lw	$a0,0x70($t2)
/*  f0c718c:	14400019 */ 	bnez	$v0,.NB0f0c71f4
/*  f0c7190:	00105880 */ 	sll	$t3,$s0,0x2
/*  f0c7194:	03ab6021 */ 	addu	$t4,$sp,$t3
/*  f0c7198:	8d8c014c */ 	lw	$t4,0x14c($t4)
/*  f0c719c:	51800008 */ 	beqzl	$t4,.NB0f0c71c0
/*  f0c71a0:	8e450284 */ 	lw	$a1,0x284($s2)
/*  f0c71a4:	8e450284 */ 	lw	$a1,0x284($s2)
/*  f0c71a8:	8ca20260 */ 	lw	$v0,0x260($a1)
/*  f0c71ac:	04400011 */ 	bltz	$v0,.NB0f0c71f4
/*  f0c71b0:	244d0001 */ 	addiu	$t5,$v0,0x1
/*  f0c71b4:	1000000f */ 	beqz	$zero,.NB0f0c71f4
/*  f0c71b8:	acad0260 */ 	sw	$t5,0x260($a1)
/*  f0c71bc:	8e450284 */ 	lw	$a1,0x284($s2)
.NB0f0c71c0:
/*  f0c71c0:	8ca20260 */ 	lw	$v0,0x260($a1)
/*  f0c71c4:	1840000a */ 	blez	$v0,.NB0f0c71f0
/*  f0c71c8:	2841000f */ 	slti	$at,$v0,0xf
/*  f0c71cc:	10200008 */ 	beqz	$at,.NB0f0c71f0
/*  f0c71d0:	8fa20218 */ 	lw	$v0,0x218($sp)
/*  f0c71d4:	10400003 */ 	beqz	$v0,.NB0f0c71e4
/*  f0c71d8:	2442ffff */ 	addiu	$v0,$v0,-1
/*  f0c71dc:	10000004 */ 	beqz	$zero,.NB0f0c71f0
/*  f0c71e0:	afa20218 */ 	sw	$v0,0x218($sp)
.NB0f0c71e4:
/*  f0c71e4:	8fa2021c */ 	lw	$v0,0x21c($sp)
/*  f0c71e8:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f0c71ec:	afa2021c */ 	sw	$v0,0x21c($sp)
.NB0f0c71f0:
/*  f0c71f0:	aca00260 */ 	sw	$zero,0x260($a1)
.NB0f0c71f4:
/*  f0c71f4:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f0c71f8:	5616ffab */ 	bnel	$s0,$s6,.NB0f0c70a8
/*  f0c71fc:	8fab01a8 */ 	lw	$t3,0x1a8($sp)
.NB0f0c7200:
/*  f0c7200:	0fc327ab */ 	jal	bmoveGetCrouchPos
/*  f0c7204:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c7208:	1440001d */ 	bnez	$v0,.NB0f0c7280
/*  f0c720c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c7210:	8e450284 */ 	lw	$a1,0x284($s2)
/*  f0c7214:	3c01c2b4 */ 	lui	$at,0xc2b4
/*  f0c7218:	44814000 */ 	mtc1	$at,$f8
/*  f0c721c:	c4aa00b4 */ 	lwc1	$f10,0xb4($a1)
/*  f0c7220:	460a4032 */ 	c.eq.s	$f8,$f10
/*  f0c7224:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c7228:	45000015 */ 	bc1f	.NB0f0c7280
/*  f0c722c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c7230:	8e4e0314 */ 	lw	$t6,0x314($s2)
/*  f0c7234:	11c00012 */ 	beqz	$t6,.NB0f0c7280
/*  f0c7238:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c723c:	8e4f0298 */ 	lw	$t7,0x298($s2)
/*  f0c7240:	05e1000f */ 	bgez	$t7,.NB0f0c7280
/*  f0c7244:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c7248:	8ca40120 */ 	lw	$a0,0x120($a1)
/*  f0c724c:	8fa201a8 */ 	lw	$v0,0x1a8($sp)
/*  f0c7250:	0004c02b */ 	sltu	$t8,$zero,$a0
/*  f0c7254:	13000009 */ 	beqz	$t8,.NB0f0c727c
/*  f0c7258:	03002025 */ 	or	$a0,$t8,$zero
/*  f0c725c:	2c440001 */ 	sltiu	$a0,$v0,0x1
/*  f0c7260:	50800007 */ 	beqzl	$a0,.NB0f0c7280
/*  f0c7264:	afa40234 */ 	sw	$a0,0x234($sp)
/*  f0c7268:	00142600 */ 	sll	$a0,$s4,0x18
/*  f0c726c:	00044603 */ 	sra	$t0,$a0,0x18
/*  f0c7270:	0c005766 */ 	jal	joyGetStickY
/*  f0c7274:	01002025 */ 	or	$a0,$t0,$zero
/*  f0c7278:	2844ffe2 */ 	slti	$a0,$v0,-30
.NB0f0c727c:
/*  f0c727c:	afa40234 */ 	sw	$a0,0x234($sp)
.NB0f0c7280:
/*  f0c7280:	0fc27dd7 */ 	jal	bgunGetWeaponNum
/*  f0c7284:	00002025 */ 	or	$a0,$zero,$zero
/*  f0c7288:	24010016 */ 	addiu	$at,$zero,0x16
/*  f0c728c:	54410011 */ 	bnel	$v0,$at,.NB0f0c72d4
/*  f0c7290:	97a201a2 */ 	lhu	$v0,0x1a2($sp)
/*  f0c7294:	8e450284 */ 	lw	$a1,0x284($s2)
/*  f0c7298:	8ca20120 */ 	lw	$v0,0x120($a1)
/*  f0c729c:	50400004 */ 	beqzl	$v0,.NB0f0c72b0
/*  f0c72a0:	0002202b */ 	sltu	$a0,$zero,$v0
/*  f0c72a4:	afa001c8 */ 	sw	$zero,0x1c8($sp)
/*  f0c72a8:	8ca20120 */ 	lw	$v0,0x120($a1)
/*  f0c72ac:	0002202b */ 	sltu	$a0,$zero,$v0
.NB0f0c72b0:
/*  f0c72b0:	10800006 */ 	beqz	$a0,.NB0f0c72cc
/*  f0c72b4:	83a900e9 */ 	lb	$t1,0xe9($sp)
/*  f0c72b8:	2924ffe2 */ 	slti	$a0,$t1,-30
/*  f0c72bc:	54800004 */ 	bnezl	$a0,.NB0f0c72d0
/*  f0c72c0:	afa40230 */ 	sw	$a0,0x230($sp)
/*  f0c72c4:	2924001f */ 	slti	$a0,$t1,0x1f
/*  f0c72c8:	38840001 */ 	xori	$a0,$a0,0x1
.NB0f0c72cc:
/*  f0c72cc:	afa40230 */ 	sw	$a0,0x230($sp)
.NB0f0c72d0:
/*  f0c72d0:	97a201a2 */ 	lhu	$v0,0x1a2($sp)
.NB0f0c72d4:
/*  f0c72d4:	afa00220 */ 	sw	$zero,0x220($sp)
/*  f0c72d8:	afa00224 */ 	sw	$zero,0x224($sp)
/*  f0c72dc:	304a8000 */ 	andi	$t2,$v0,0x8000
/*  f0c72e0:	11400003 */ 	beqz	$t2,.NB0f0c72f0
/*  f0c72e4:	97ab01a0 */ 	lhu	$t3,0x1a0($sp)
/*  f0c72e8:	316c4000 */ 	andi	$t4,$t3,0x4000
/*  f0c72ec:	15800012 */ 	bnez	$t4,.NB0f0c7338
.NB0f0c72f0:
/*  f0c72f0:	304d4000 */ 	andi	$t5,$v0,0x4000
/*  f0c72f4:	11a00004 */ 	beqz	$t5,.NB0f0c7308
/*  f0c72f8:	97ae01a0 */ 	lhu	$t6,0x1a0($sp)
/*  f0c72fc:	31cf8000 */ 	andi	$t7,$t6,0x8000
/*  f0c7300:	55e0000e */ 	bnezl	$t7,.NB0f0c733c
/*  f0c7304:	8fac01ac */ 	lw	$t4,0x1ac($sp)
.NB0f0c7308:
/*  f0c7308:	97a200e6 */ 	lhu	$v0,0xe6($sp)
/*  f0c730c:	97b900e4 */ 	lhu	$t9,0xe4($sp)
/*  f0c7310:	30588000 */ 	andi	$t8,$v0,0x8000
/*  f0c7314:	13000002 */ 	beqz	$t8,.NB0f0c7320
/*  f0c7318:	33284000 */ 	andi	$t0,$t9,0x4000
/*  f0c731c:	15000006 */ 	bnez	$t0,.NB0f0c7338
.NB0f0c7320:
/*  f0c7320:	30494000 */ 	andi	$t1,$v0,0x4000
/*  f0c7324:	11200011 */ 	beqz	$t1,.NB0f0c736c
/*  f0c7328:	97aa00e4 */ 	lhu	$t2,0xe4($sp)
/*  f0c732c:	314b8000 */ 	andi	$t3,$t2,0x8000
/*  f0c7330:	5160000f */ 	beqzl	$t3,.NB0f0c7370
/*  f0c7334:	8e450284 */ 	lw	$a1,0x284($s2)
.NB0f0c7338:
/*  f0c7338:	8fac01ac */ 	lw	$t4,0x1ac($sp)
.NB0f0c733c:
/*  f0c733c:	24010022 */ 	addiu	$at,$zero,0x22
/*  f0c7340:	2402fffe */ 	addiu	$v0,$zero,-2
/*  f0c7344:	15810009 */ 	bne	$t4,$at,.NB0f0c736c
/*  f0c7348:	240d0001 */ 	addiu	$t5,$zero,0x1
/*  f0c734c:	8e4e0284 */ 	lw	$t6,0x284($s2)
/*  f0c7350:	afad0228 */ 	sw	$t5,0x228($sp)
/*  f0c7354:	afa001fc */ 	sw	$zero,0x1fc($sp)
/*  f0c7358:	afa00200 */ 	sw	$zero,0x200($sp)
/*  f0c735c:	afa001c0 */ 	sw	$zero,0x1c0($sp)
/*  f0c7360:	a5c2024c */ 	sh	$v0,0x24c($t6)
/*  f0c7364:	8e4f0284 */ 	lw	$t7,0x284($s2)
/*  f0c7368:	a5e2024e */ 	sh	$v0,0x24e($t7)
.NB0f0c736c:
/*  f0c736c:	8e450284 */ 	lw	$a1,0x284($s2)
.NB0f0c7370:
/*  f0c7370:	97a900ea */ 	lhu	$t1,0xea($sp)
/*  f0c7374:	8cb80120 */ 	lw	$t8,0x120($a1)
/*  f0c7378:	afb80208 */ 	sw	$t8,0x208($sp)
/*  f0c737c:	8cb90120 */ 	lw	$t9,0x120($a1)
/*  f0c7380:	afb9020c */ 	sw	$t9,0x20c($sp)
/*  f0c7384:	8ca80274 */ 	lw	$t0,0x274($a1)
/*  f0c7388:	31252000 */ 	andi	$a1,$t1,0x2000
/*  f0c738c:	11000007 */ 	beqz	$t0,.NB0f0c73ac
/*  f0c7390:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c7394:	0c005790 */ 	jal	joyGetButtons
/*  f0c7398:	83a400ef */ 	lb	$a0,0xef($sp)
/*  f0c739c:	14400003 */ 	bnez	$v0,.NB0f0c73ac
/*  f0c73a0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c73a4:	8e4b0284 */ 	lw	$t3,0x284($s2)
/*  f0c73a8:	ad600274 */ 	sw	$zero,0x274($t3)
.NB0f0c73ac:
/*  f0c73ac:	0fc27dd7 */ 	jal	bgunGetWeaponNum
/*  f0c73b0:	00002025 */ 	or	$a0,$zero,$zero
/*  f0c73b4:	00402025 */ 	or	$a0,$v0,$zero
/*  f0c73b8:	0fc2bd48 */ 	jal	weaponHasFlag
/*  f0c73bc:	3c058000 */ 	lui	$a1,0x8000
/*  f0c73c0:	50400012 */ 	beqzl	$v0,.NB0f0c740c
/*  f0c73c4:	8e480284 */ 	lw	$t0,0x284($s2)
/*  f0c73c8:	12e0000d */ 	beqz	$s7,.NB0f0c7400
/*  f0c73cc:	97ac00ea */ 	lhu	$t4,0xea($sp)
/*  f0c73d0:	83a400ef */ 	lb	$a0,0xef($sp)
/*  f0c73d4:	0c0057c0 */ 	jal	joyGetButtonsPressedThisFrame
/*  f0c73d8:	31852000 */ 	andi	$a1,$t4,0x2000
/*  f0c73dc:	10400008 */ 	beqz	$v0,.NB0f0c7400
/*  f0c73e0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c73e4:	8e4e0284 */ 	lw	$t6,0x284($s2)
/*  f0c73e8:	8fb801c0 */ 	lw	$t8,0x1c0($sp)
/*  f0c73ec:	8dcf1a24 */ 	lw	$t7,0x1a24($t6)
/*  f0c73f0:	27190001 */ 	addiu	$t9,$t8,0x1
/*  f0c73f4:	15e00002 */ 	bnez	$t7,.NB0f0c7400
/*  f0c73f8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c73fc:	afb901c0 */ 	sw	$t9,0x1c0($sp)
.NB0f0c7400:
/*  f0c7400:	1000001e */ 	beqz	$zero,.NB0f0c747c
/*  f0c7404:	8e450284 */ 	lw	$a1,0x284($s2)
/*  f0c7408:	8e480284 */ 	lw	$t0,0x284($s2)
.NB0f0c740c:
/*  f0c740c:	8d040274 */ 	lw	$a0,0x274($t0)
/*  f0c7410:	2c890001 */ 	sltiu	$t1,$a0,0x1
/*  f0c7414:	11200017 */ 	beqz	$t1,.NB0f0c7474
/*  f0c7418:	01202025 */ 	or	$a0,$t1,$zero
/*  f0c741c:	12e00015 */ 	beqz	$s7,.NB0f0c7474
/*  f0c7420:	02e02025 */ 	or	$a0,$s7,$zero
/*  f0c7424:	97aa00ea */ 	lhu	$t2,0xea($sp)
/*  f0c7428:	83a400ef */ 	lb	$a0,0xef($sp)
/*  f0c742c:	0c005790 */ 	jal	joyGetButtons
/*  f0c7430:	31452000 */ 	andi	$a1,$t2,0x2000
/*  f0c7434:	0002202b */ 	sltu	$a0,$zero,$v0
/*  f0c7438:	5080000f */ 	beqzl	$a0,.NB0f0c7478
/*  f0c743c:	afa401bc */ 	sw	$a0,0x1bc($sp)
/*  f0c7440:	8e4c0284 */ 	lw	$t4,0x284($s2)
/*  f0c7444:	97a201a2 */ 	lhu	$v0,0x1a2($sp)
/*  f0c7448:	8d841a24 */ 	lw	$a0,0x1a24($t4)
/*  f0c744c:	304e8000 */ 	andi	$t6,$v0,0x8000
/*  f0c7450:	2c8d0001 */ 	sltiu	$t5,$a0,0x1
/*  f0c7454:	11a00007 */ 	beqz	$t5,.NB0f0c7474
/*  f0c7458:	01a02025 */ 	or	$a0,$t5,$zero
/*  f0c745c:	2dc40001 */ 	sltiu	$a0,$t6,0x1
/*  f0c7460:	50800005 */ 	beqzl	$a0,.NB0f0c7478
/*  f0c7464:	afa401bc */ 	sw	$a0,0x1bc($sp)
/*  f0c7468:	97a400e6 */ 	lhu	$a0,0xe6($sp)
/*  f0c746c:	30988000 */ 	andi	$t8,$a0,0x8000
/*  f0c7470:	2f040001 */ 	sltiu	$a0,$t8,0x1
.NB0f0c7474:
/*  f0c7474:	afa401bc */ 	sw	$a0,0x1bc($sp)
.NB0f0c7478:
/*  f0c7478:	8e450284 */ 	lw	$a1,0x284($s2)
.NB0f0c747c:
/*  f0c747c:	24080001 */ 	addiu	$t0,$zero,0x1
/*  f0c7480:	1000032a */ 	beqz	$zero,.NB0f0c812c
/*  f0c7484:	afa8023c */ 	sw	$t0,0x23c($sp)
/*  f0c7488:	24010002 */ 	addiu	$at,$zero,0x2
.NB0f0c748c:
/*  f0c748c:	10410004 */ 	beq	$v0,$at,.NB0f0c74a0
/*  f0c7490:	34148000 */ 	dli	$s4,0x8000
/*  f0c7494:	24010003 */ 	addiu	$at,$zero,0x3
/*  f0c7498:	14410005 */ 	bne	$v0,$at,.NB0f0c74b0
/*  f0c749c:	24110030 */ 	addiu	$s1,$zero,0x30
.NB0f0c74a0:
/*  f0c74a0:	24090030 */ 	addiu	$t1,$zero,0x30
/*  f0c74a4:	24112000 */ 	addiu	$s1,$zero,0x2000
/*  f0c74a8:	10000004 */ 	beqz	$zero,.NB0f0c74bc
/*  f0c74ac:	a7a900ca */ 	sh	$t1,0xca($sp)
.NB0f0c74b0:
/*  f0c74b0:	340a8000 */ 	dli	$t2,0x8000
/*  f0c74b4:	24142000 */ 	addiu	$s4,$zero,0x2000
/*  f0c74b8:	a7aa00ca */ 	sh	$t2,0xca($sp)
.NB0f0c74bc:
/*  f0c74bc:	8e4b0288 */ 	lw	$t3,0x288($s2)
/*  f0c74c0:	0fc533b7 */ 	jal	optionsGetAimControl
/*  f0c74c4:	8d640070 */ 	lw	$a0,0x70($t3)
/*  f0c74c8:	14400021 */ 	bnez	$v0,.NB0f0c7550
/*  f0c74cc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c74d0:	1ac0001a */ 	blez	$s6,.NB0f0c753c
/*  f0c74d4:	00008025 */ 	or	$s0,$zero,$zero
/*  f0c74d8:	27a3014c */ 	addiu	$v1,$sp,0x14c
/*  f0c74dc:	27a700fc */ 	addiu	$a3,$sp,0xfc
.NB0f0c74e0:
/*  f0c74e0:	12e0000f */ 	beqz	$s7,.NB0f0c7520
/*  f0c74e4:	02e02025 */ 	or	$a0,$s7,$zero
/*  f0c74e8:	97ad019e */ 	lhu	$t5,0x19e($sp)
/*  f0c74ec:	00152e00 */ 	sll	$a1,$s5,0x18
/*  f0c74f0:	00056603 */ 	sra	$t4,$a1,0x18
/*  f0c74f4:	022d3024 */ 	and	$a2,$s1,$t5
/*  f0c74f8:	30ceffff */ 	andi	$t6,$a2,0xffff
/*  f0c74fc:	01c03025 */ 	or	$a2,$t6,$zero
/*  f0c7500:	01802825 */ 	or	$a1,$t4,$zero
/*  f0c7504:	02002025 */ 	or	$a0,$s0,$zero
/*  f0c7508:	afa3004c */ 	sw	$v1,0x4c($sp)
/*  f0c750c:	0c005656 */ 	jal	joyGetButtonsOnSample
/*  f0c7510:	afa70048 */ 	sw	$a3,0x48($sp)
/*  f0c7514:	8fa3004c */ 	lw	$v1,0x4c($sp)
/*  f0c7518:	8fa70048 */ 	lw	$a3,0x48($sp)
/*  f0c751c:	0002202b */ 	sltu	$a0,$zero,$v0
.NB0f0c7520:
/*  f0c7520:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f0c7524:	2c8f0001 */ 	sltiu	$t7,$a0,0x1
/*  f0c7528:	24630004 */ 	addiu	$v1,$v1,0x4
/*  f0c752c:	24e70004 */ 	addiu	$a3,$a3,0x4
/*  f0c7530:	ac64fffc */ 	sw	$a0,-0x4($v1)
/*  f0c7534:	1616ffea */ 	bne	$s0,$s6,.NB0f0c74e0
/*  f0c7538:	aceffffc */ 	sw	$t7,-0x4($a3)
.NB0f0c753c:
/*  f0c753c:	0016c080 */ 	sll	$t8,$s6,0x2
/*  f0c7540:	03b8c821 */ 	addu	$t9,$sp,$t8
/*  f0c7544:	8f390148 */ 	lw	$t9,0x148($t9)
/*  f0c7548:	8e480284 */ 	lw	$t0,0x284($s2)
/*  f0c754c:	ad190120 */ 	sw	$t9,0x120($t0)
.NB0f0c7550:
/*  f0c7550:	0fc59ed0 */ 	jal	lvIsPaused
/*  f0c7554:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c7558:	544002ba */ 	bnezl	$v0,.NB0f0c8044
/*  f0c755c:	8e450284 */ 	lw	$a1,0x284($s2)
/*  f0c7560:	8e490288 */ 	lw	$t1,0x288($s2)
/*  f0c7564:	0fc533b7 */ 	jal	optionsGetAimControl
/*  f0c7568:	8d240070 */ 	lw	$a0,0x70($t1)
/*  f0c756c:	10400021 */ 	beqz	$v0,.NB0f0c75f4
/*  f0c7570:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c7574:	1ac0001f */ 	blez	$s6,.NB0f0c75f4
/*  f0c7578:	00008025 */ 	or	$s0,$zero,$zero
/*  f0c757c:	27a3014c */ 	addiu	$v1,$sp,0x14c
/*  f0c7580:	27a700fc */ 	addiu	$a3,$sp,0xfc
.NB0f0c7584:
/*  f0c7584:	12e00012 */ 	beqz	$s7,.NB0f0c75d0
/*  f0c7588:	02002025 */ 	or	$a0,$s0,$zero
/*  f0c758c:	97ab019e */ 	lhu	$t3,0x19e($sp)
/*  f0c7590:	00152e00 */ 	sll	$a1,$s5,0x18
/*  f0c7594:	00055603 */ 	sra	$t2,$a1,0x18
/*  f0c7598:	022b3024 */ 	and	$a2,$s1,$t3
/*  f0c759c:	30ccffff */ 	andi	$t4,$a2,0xffff
/*  f0c75a0:	01803025 */ 	or	$a2,$t4,$zero
/*  f0c75a4:	01402825 */ 	or	$a1,$t2,$zero
/*  f0c75a8:	afa3004c */ 	sw	$v1,0x4c($sp)
/*  f0c75ac:	0c00568c */ 	jal	joyGetButtonsPressedOnSample
/*  f0c75b0:	afa70048 */ 	sw	$a3,0x48($sp)
/*  f0c75b4:	8fa3004c */ 	lw	$v1,0x4c($sp)
/*  f0c75b8:	10400005 */ 	beqz	$v0,.NB0f0c75d0
/*  f0c75bc:	8fa70048 */ 	lw	$a3,0x48($sp)
/*  f0c75c0:	8e450284 */ 	lw	$a1,0x284($s2)
/*  f0c75c4:	8ca40120 */ 	lw	$a0,0x120($a1)
/*  f0c75c8:	2c8d0001 */ 	sltiu	$t5,$a0,0x1
/*  f0c75cc:	acad0120 */ 	sw	$t5,0x120($a1)
.NB0f0c75d0:
/*  f0c75d0:	8e4e0284 */ 	lw	$t6,0x284($s2)
/*  f0c75d4:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f0c75d8:	24630004 */ 	addiu	$v1,$v1,0x4
/*  f0c75dc:	8dcf0120 */ 	lw	$t7,0x120($t6)
/*  f0c75e0:	24e70004 */ 	addiu	$a3,$a3,0x4
/*  f0c75e4:	2df80001 */ 	sltiu	$t8,$t7,0x1
/*  f0c75e8:	acf8fffc */ 	sw	$t8,-0x4($a3)
/*  f0c75ec:	1616ffe5 */ 	bne	$s0,$s6,.NB0f0c7584
/*  f0c75f0:	ac6ffffc */ 	sw	$t7,-0x4($v1)
.NB0f0c75f4:
/*  f0c75f4:	0fc27dd7 */ 	jal	bgunGetWeaponNum
/*  f0c75f8:	00002025 */ 	or	$a0,$zero,$zero
/*  f0c75fc:	24010032 */ 	addiu	$at,$zero,0x32
/*  f0c7600:	54410005 */ 	bnel	$v0,$at,.NB0f0c7618
/*  f0c7604:	8e450284 */ 	lw	$a1,0x284($s2)
/*  f0c7608:	8e480284 */ 	lw	$t0,0x284($s2)
/*  f0c760c:	24190001 */ 	addiu	$t9,$zero,0x1
/*  f0c7610:	ad190120 */ 	sw	$t9,0x120($t0)
/*  f0c7614:	8e450284 */ 	lw	$a1,0x284($s2)
.NB0f0c7618:
/*  f0c7618:	8fac01b0 */ 	lw	$t4,0x1b0($sp)
/*  f0c761c:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0c7620:	8ca40120 */ 	lw	$a0,0x120($a1)
/*  f0c7624:	2c890001 */ 	sltiu	$t1,$a0,0x1
/*  f0c7628:	afa901b4 */ 	sw	$t1,0x1b4($sp)
/*  f0c762c:	8caa0120 */ 	lw	$t2,0x120($a1)
/*  f0c7630:	afaa01b8 */ 	sw	$t2,0x1b8($sp)
/*  f0c7634:	8ca40120 */ 	lw	$a0,0x120($a1)
/*  f0c7638:	2c8b0001 */ 	sltiu	$t3,$a0,0x1
/*  f0c763c:	11810004 */ 	beq	$t4,$at,.NB0f0c7650
/*  f0c7640:	afab022c */ 	sw	$t3,0x22c($sp)
/*  f0c7644:	24010003 */ 	addiu	$at,$zero,0x3
/*  f0c7648:	15810054 */ 	bne	$t4,$at,.NB0f0c779c
/*  f0c764c:	97af01a2 */ 	lhu	$t7,0x1a2($sp)
.NB0f0c7650:
/*  f0c7650:	8cad0120 */ 	lw	$t5,0x120($a1)
/*  f0c7654:	97a201a2 */ 	lhu	$v0,0x1a2($sp)
/*  f0c7658:	15a0001a */ 	bnez	$t5,.NB0f0c76c4
/*  f0c765c:	30490202 */ 	andi	$t1,$v0,0x202
/*  f0c7660:	12e00015 */ 	beqz	$s7,.NB0f0c76b8
/*  f0c7664:	27b000fc */ 	addiu	$s0,$sp,0xfc
/*  f0c7668:	97b1019e */ 	lhu	$s1,0x19e($sp)
/*  f0c766c:	00152e00 */ 	sll	$a1,$s5,0x18
/*  f0c7670:	00057603 */ 	sra	$t6,$a1,0x18
/*  f0c7674:	02203025 */ 	or	$a2,$s1,$zero
/*  f0c7678:	30cf0202 */ 	andi	$t7,$a2,0x202
/*  f0c767c:	01e03025 */ 	or	$a2,$t7,$zero
/*  f0c7680:	01c02825 */ 	or	$a1,$t6,$zero
/*  f0c7684:	0c0056de */ 	jal	joyCountButtonsOnSpecificSamples
/*  f0c7688:	02002025 */ 	or	$a0,$s0,$zero
/*  f0c768c:	00152e00 */ 	sll	$a1,$s5,0x18
/*  f0c7690:	02203025 */ 	or	$a2,$s1,$zero
/*  f0c7694:	30d90101 */ 	andi	$t9,$a2,0x101
/*  f0c7698:	0005c603 */ 	sra	$t8,$a1,0x18
/*  f0c769c:	afa201dc */ 	sw	$v0,0x1dc($sp)
/*  f0c76a0:	03002825 */ 	or	$a1,$t8,$zero
/*  f0c76a4:	03203025 */ 	or	$a2,$t9,$zero
/*  f0c76a8:	0c0056de */ 	jal	joyCountButtonsOnSpecificSamples
/*  f0c76ac:	02002025 */ 	or	$a0,$s0,$zero
/*  f0c76b0:	afa201e0 */ 	sw	$v0,0x1e0($sp)
/*  f0c76b4:	8e450284 */ 	lw	$a1,0x284($s2)
.NB0f0c76b8:
/*  f0c76b8:	97a801a2 */ 	lhu	$t0,0x1a2($sp)
/*  f0c76bc:	1000000d */ 	beqz	$zero,.NB0f0c76f4
/*  f0c76c0:	afa80048 */ 	sw	$t0,0x48($sp)
.NB0f0c76c4:
/*  f0c76c4:	11200005 */ 	beqz	$t1,.NB0f0c76dc
/*  f0c76c8:	304a0101 */ 	andi	$t2,$v0,0x101
/*  f0c76cc:	3c013f80 */ 	lui	$at,0x3f80
/*  f0c76d0:	44818000 */ 	mtc1	$at,$f16
/*  f0c76d4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c76d8:	e7b001e4 */ 	swc1	$f16,0x1e4($sp)
.NB0f0c76dc:
/*  f0c76dc:	11400005 */ 	beqz	$t2,.NB0f0c76f4
/*  f0c76e0:	afa20048 */ 	sw	$v0,0x48($sp)
/*  f0c76e4:	3c013f80 */ 	lui	$at,0x3f80
/*  f0c76e8:	44819000 */ 	mtc1	$at,$f18
/*  f0c76ec:	afa20048 */ 	sw	$v0,0x48($sp)
/*  f0c76f0:	e7b201e8 */ 	swc1	$f18,0x1e8($sp)
.NB0f0c76f4:
/*  f0c76f4:	8ca40120 */ 	lw	$a0,0x120($a1)
/*  f0c76f8:	44802000 */ 	mtc1	$zero,$f4
/*  f0c76fc:	44803000 */ 	mtc1	$zero,$f6
/*  f0c7700:	2c8b0001 */ 	sltiu	$t3,$a0,0x1
/*  f0c7704:	11600004 */ 	beqz	$t3,.NB0f0c7718
/*  f0c7708:	01602025 */ 	or	$a0,$t3,$zero
/*  f0c770c:	8fa40048 */ 	lw	$a0,0x48($sp)
/*  f0c7710:	308c0808 */ 	andi	$t4,$a0,0x808
/*  f0c7714:	000c202b */ 	sltu	$a0,$zero,$t4
.NB0f0c7718:
/*  f0c7718:	afa401d4 */ 	sw	$a0,0x1d4($sp)
/*  f0c771c:	8ca40120 */ 	lw	$a0,0x120($a1)
/*  f0c7720:	2c8e0001 */ 	sltiu	$t6,$a0,0x1
/*  f0c7724:	11c00004 */ 	beqz	$t6,.NB0f0c7738
/*  f0c7728:	01c02025 */ 	or	$a0,$t6,$zero
/*  f0c772c:	8fa40048 */ 	lw	$a0,0x48($sp)
/*  f0c7730:	308f0404 */ 	andi	$t7,$a0,0x404
/*  f0c7734:	000f202b */ 	sltu	$a0,$zero,$t7
.NB0f0c7738:
/*  f0c7738:	afa401d8 */ 	sw	$a0,0x1d8($sp)
/*  f0c773c:	afa001c4 */ 	sw	$zero,0x1c4($sp)
/*  f0c7740:	8ca40120 */ 	lw	$a0,0x120($a1)
/*  f0c7744:	e7a401ec */ 	swc1	$f4,0x1ec($sp)
/*  f0c7748:	e7a601f0 */ 	swc1	$f6,0x1f0($sp)
/*  f0c774c:	2c990001 */ 	sltiu	$t9,$a0,0x1
/*  f0c7750:	afb901d0 */ 	sw	$t9,0x1d0($sp)
/*  f0c7754:	8ca40120 */ 	lw	$a0,0x120($a1)
/*  f0c7758:	8e4902ac */ 	lw	$t1,0x2ac($s2)
/*  f0c775c:	24010007 */ 	addiu	$at,$zero,0x7
/*  f0c7760:	2c880001 */ 	sltiu	$t0,$a0,0x1
/*  f0c7764:	1521005b */ 	bne	$t1,$at,.NB0f0c78d4
/*  f0c7768:	afa801cc */ 	sw	$t0,0x1cc($sp)
/*  f0c776c:	8caa1bdc */ 	lw	$t2,0x1bdc($a1)
/*  f0c7770:	000a582a */ 	slt	$t3,$zero,$t2
/*  f0c7774:	afab01d4 */ 	sw	$t3,0x1d4($sp)
/*  f0c7778:	8cac1bdc */ 	lw	$t4,0x1bdc($a1)
/*  f0c777c:	afa00258 */ 	sw	$zero,0x258($sp)
/*  f0c7780:	afa0025c */ 	sw	$zero,0x25c($sp)
/*  f0c7784:	298d0000 */ 	slti	$t5,$t4,0x0
/*  f0c7788:	afad01d8 */ 	sw	$t5,0x1d8($sp)
/*  f0c778c:	8cae1bd8 */ 	lw	$t6,0x1bd8($a1)
/*  f0c7790:	afa00254 */ 	sw	$zero,0x254($sp)
/*  f0c7794:	1000004f */ 	beqz	$zero,.NB0f0c78d4
/*  f0c7798:	afae0250 */ 	sw	$t6,0x250($sp)
.NB0f0c779c:
/*  f0c779c:	31f80202 */ 	andi	$t8,$t7,0x202
/*  f0c77a0:	13000005 */ 	beqz	$t8,.NB0f0c77b8
/*  f0c77a4:	afaf0048 */ 	sw	$t7,0x48($sp)
/*  f0c77a8:	3c013f80 */ 	lui	$at,0x3f80
/*  f0c77ac:	44814000 */ 	mtc1	$at,$f8
/*  f0c77b0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c77b4:	e7a801e4 */ 	swc1	$f8,0x1e4($sp)
.NB0f0c77b8:
/*  f0c77b8:	8fb90048 */ 	lw	$t9,0x48($sp)
/*  f0c77bc:	3c013f80 */ 	lui	$at,0x3f80
/*  f0c77c0:	33280101 */ 	andi	$t0,$t9,0x101
/*  f0c77c4:	51000005 */ 	beqzl	$t0,.NB0f0c77dc
/*  f0c77c8:	8ca90120 */ 	lw	$t1,0x120($a1)
/*  f0c77cc:	44815000 */ 	mtc1	$at,$f10
/*  f0c77d0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c77d4:	e7aa01e8 */ 	swc1	$f10,0x1e8($sp)
/*  f0c77d8:	8ca90120 */ 	lw	$t1,0x120($a1)
.NB0f0c77dc:
/*  f0c77dc:	55200018 */ 	bnezl	$t1,.NB0f0c7840
/*  f0c77e0:	afa001d4 */ 	sw	$zero,0x1d4($sp)
/*  f0c77e4:	12e00015 */ 	beqz	$s7,.NB0f0c783c
/*  f0c77e8:	27b000fc */ 	addiu	$s0,$sp,0xfc
/*  f0c77ec:	97b1019e */ 	lhu	$s1,0x19e($sp)
/*  f0c77f0:	00152e00 */ 	sll	$a1,$s5,0x18
/*  f0c77f4:	00055603 */ 	sra	$t2,$a1,0x18
/*  f0c77f8:	02203025 */ 	or	$a2,$s1,$zero
/*  f0c77fc:	30cb0202 */ 	andi	$t3,$a2,0x202
/*  f0c7800:	01603025 */ 	or	$a2,$t3,$zero
/*  f0c7804:	01402825 */ 	or	$a1,$t2,$zero
/*  f0c7808:	0c0056de */ 	jal	joyCountButtonsOnSpecificSamples
/*  f0c780c:	02002025 */ 	or	$a0,$s0,$zero
/*  f0c7810:	00152e00 */ 	sll	$a1,$s5,0x18
/*  f0c7814:	02203025 */ 	or	$a2,$s1,$zero
/*  f0c7818:	30cd0101 */ 	andi	$t5,$a2,0x101
/*  f0c781c:	00056603 */ 	sra	$t4,$a1,0x18
/*  f0c7820:	afa201dc */ 	sw	$v0,0x1dc($sp)
/*  f0c7824:	01802825 */ 	or	$a1,$t4,$zero
/*  f0c7828:	01a03025 */ 	or	$a2,$t5,$zero
/*  f0c782c:	0c0056de */ 	jal	joyCountButtonsOnSpecificSamples
/*  f0c7830:	02002025 */ 	or	$a0,$s0,$zero
/*  f0c7834:	afa201e0 */ 	sw	$v0,0x1e0($sp)
/*  f0c7838:	8e450284 */ 	lw	$a1,0x284($s2)
.NB0f0c783c:
/*  f0c783c:	afa001d4 */ 	sw	$zero,0x1d4($sp)
.NB0f0c7840:
/*  f0c7840:	afa001d8 */ 	sw	$zero,0x1d8($sp)
/*  f0c7844:	8ca40120 */ 	lw	$a0,0x120($a1)
/*  f0c7848:	afa001d0 */ 	sw	$zero,0x1d0($sp)
/*  f0c784c:	8faf0048 */ 	lw	$t7,0x48($sp)
/*  f0c7850:	2c8e0001 */ 	sltiu	$t6,$a0,0x1
/*  f0c7854:	afae01c4 */ 	sw	$t6,0x1c4($sp)
/*  f0c7858:	8ca20120 */ 	lw	$v0,0x120($a1)
/*  f0c785c:	31f80808 */ 	andi	$t8,$t7,0x808
/*  f0c7860:	14400007 */ 	bnez	$v0,.NB0f0c7880
/*  f0c7864:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c7868:	13000005 */ 	beqz	$t8,.NB0f0c7880
/*  f0c786c:	3c013f80 */ 	lui	$at,0x3f80
/*  f0c7870:	44818000 */ 	mtc1	$at,$f16
/*  f0c7874:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c7878:	e7b001ec */ 	swc1	$f16,0x1ec($sp)
/*  f0c787c:	8ca20120 */ 	lw	$v0,0x120($a1)
.NB0f0c7880:
/*  f0c7880:	14400008 */ 	bnez	$v0,.NB0f0c78a4
/*  f0c7884:	8fb90048 */ 	lw	$t9,0x48($sp)
/*  f0c7888:	33280404 */ 	andi	$t0,$t9,0x404
/*  f0c788c:	11000005 */ 	beqz	$t0,.NB0f0c78a4
/*  f0c7890:	3c013f80 */ 	lui	$at,0x3f80
/*  f0c7894:	44819000 */ 	mtc1	$at,$f18
/*  f0c7898:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c789c:	e7b201f0 */ 	swc1	$f18,0x1f0($sp)
/*  f0c78a0:	8ca20120 */ 	lw	$v0,0x120($a1)
.NB0f0c78a4:
/*  f0c78a4:	8e4902ac */ 	lw	$t1,0x2ac($s2)
/*  f0c78a8:	2c440001 */ 	sltiu	$a0,$v0,0x1
/*  f0c78ac:	24010007 */ 	addiu	$at,$zero,0x7
/*  f0c78b0:	afa401cc */ 	sw	$a0,0x1cc($sp)
/*  f0c78b4:	15210007 */ 	bne	$t1,$at,.NB0f0c78d4
/*  f0c78b8:	afa001c8 */ 	sw	$zero,0x1c8($sp)
/*  f0c78bc:	afa00258 */ 	sw	$zero,0x258($sp)
/*  f0c78c0:	8caa1bdc */ 	lw	$t2,0x1bdc($a1)
/*  f0c78c4:	afaa025c */ 	sw	$t2,0x25c($sp)
/*  f0c78c8:	8cab1bd8 */ 	lw	$t3,0x1bd8($a1)
/*  f0c78cc:	afa00254 */ 	sw	$zero,0x254($sp)
/*  f0c78d0:	afab0250 */ 	sw	$t3,0x250($sp)
.NB0f0c78d4:
/*  f0c78d4:	8ca20120 */ 	lw	$v0,0x120($a1)
/*  f0c78d8:	8fa4024c */ 	lw	$a0,0x24c($sp)
/*  f0c78dc:	10400012 */ 	beqz	$v0,.NB0f0c7928
/*  f0c78e0:	2881003d */ 	slti	$at,$a0,0x3d
/*  f0c78e4:	14200010 */ 	bnez	$at,.NB0f0c7928
/*  f0c78e8:	248cffc4 */ 	addiu	$t4,$a0,-60
/*  f0c78ec:	448c2000 */ 	mtc1	$t4,$f4
/*  f0c78f0:	3c014120 */ 	lui	$at,0x4120
/*  f0c78f4:	44811000 */ 	mtc1	$at,$f2
/*  f0c78f8:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f0c78fc:	3c013f80 */ 	lui	$at,0x3f80
/*  f0c7900:	44815000 */ 	mtc1	$at,$f10
/*  f0c7904:	3c013f80 */ 	lui	$at,0x3f80
/*  f0c7908:	46023203 */ 	div.s	$f8,$f6,$f2
/*  f0c790c:	4608503c */ 	c.lt.s	$f10,$f8
/*  f0c7910:	e7a801ec */ 	swc1	$f8,0x1ec($sp)
/*  f0c7914:	4502001a */ 	bc1fl	.NB0f0c7980
/*  f0c7918:	8ca20120 */ 	lw	$v0,0x120($a1)
/*  f0c791c:	44818000 */ 	mtc1	$at,$f16
/*  f0c7920:	10000016 */ 	beqz	$zero,.NB0f0c797c
/*  f0c7924:	e7b001ec */ 	swc1	$f16,0x1ec($sp)
.NB0f0c7928:
/*  f0c7928:	10400014 */ 	beqz	$v0,.NB0f0c797c
/*  f0c792c:	8fa4024c */ 	lw	$a0,0x24c($sp)
/*  f0c7930:	2881ffc4 */ 	slti	$at,$a0,-60
/*  f0c7934:	10200011 */ 	beqz	$at,.NB0f0c797c
/*  f0c7938:	240dffc4 */ 	addiu	$t5,$zero,-60
/*  f0c793c:	01a47023 */ 	subu	$t6,$t5,$a0
/*  f0c7940:	448e9000 */ 	mtc1	$t6,$f18
/*  f0c7944:	3c014120 */ 	lui	$at,0x4120
/*  f0c7948:	44811000 */ 	mtc1	$at,$f2
/*  f0c794c:	46809120 */ 	cvt.s.w	$f4,$f18
/*  f0c7950:	3c013f80 */ 	lui	$at,0x3f80
/*  f0c7954:	44815000 */ 	mtc1	$at,$f10
/*  f0c7958:	3c013f80 */ 	lui	$at,0x3f80
/*  f0c795c:	46022183 */ 	div.s	$f6,$f4,$f2
/*  f0c7960:	4606503c */ 	c.lt.s	$f10,$f6
/*  f0c7964:	e7a601f0 */ 	swc1	$f6,0x1f0($sp)
/*  f0c7968:	45020005 */ 	bc1fl	.NB0f0c7980
/*  f0c796c:	8ca20120 */ 	lw	$v0,0x120($a1)
/*  f0c7970:	44814000 */ 	mtc1	$at,$f8
/*  f0c7974:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c7978:	e7a801f0 */ 	swc1	$f8,0x1f0($sp)
.NB0f0c797c:
/*  f0c797c:	8ca20120 */ 	lw	$v0,0x120($a1)
.NB0f0c7980:
/*  f0c7980:	3c014120 */ 	lui	$at,0x4120
/*  f0c7984:	44811000 */ 	mtc1	$at,$f2
/*  f0c7988:	10400012 */ 	beqz	$v0,.NB0f0c79d4
/*  f0c798c:	8fa30248 */ 	lw	$v1,0x248($sp)
/*  f0c7990:	2861ffc4 */ 	slti	$at,$v1,-60
/*  f0c7994:	1020000f */ 	beqz	$at,.NB0f0c79d4
/*  f0c7998:	240fffc4 */ 	addiu	$t7,$zero,-60
/*  f0c799c:	01e3c023 */ 	subu	$t8,$t7,$v1
/*  f0c79a0:	44988000 */ 	mtc1	$t8,$f16
/*  f0c79a4:	3c013f80 */ 	lui	$at,0x3f80
/*  f0c79a8:	44812000 */ 	mtc1	$at,$f4
/*  f0c79ac:	468084a0 */ 	cvt.s.w	$f18,$f16
/*  f0c79b0:	3c013f80 */ 	lui	$at,0x3f80
/*  f0c79b4:	46029303 */ 	div.s	$f12,$f18,$f2
/*  f0c79b8:	460c203c */ 	c.lt.s	$f4,$f12
/*  f0c79bc:	e7ac01f4 */ 	swc1	$f12,0x1f4($sp)
/*  f0c79c0:	45000016 */ 	bc1f	.NB0f0c7a1c
/*  f0c79c4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c79c8:	44816000 */ 	mtc1	$at,$f12
/*  f0c79cc:	10000013 */ 	beqz	$zero,.NB0f0c7a1c
/*  f0c79d0:	e7ac01f4 */ 	swc1	$f12,0x1f4($sp)
.NB0f0c79d4:
/*  f0c79d4:	10400011 */ 	beqz	$v0,.NB0f0c7a1c
/*  f0c79d8:	8fa30248 */ 	lw	$v1,0x248($sp)
/*  f0c79dc:	2861003d */ 	slti	$at,$v1,0x3d
/*  f0c79e0:	1420000e */ 	bnez	$at,.NB0f0c7a1c
/*  f0c79e4:	2479ffc4 */ 	addiu	$t9,$v1,-60
/*  f0c79e8:	44995000 */ 	mtc1	$t9,$f10
/*  f0c79ec:	3c013f80 */ 	lui	$at,0x3f80
/*  f0c79f0:	44814000 */ 	mtc1	$at,$f8
/*  f0c79f4:	468051a0 */ 	cvt.s.w	$f6,$f10
/*  f0c79f8:	3c013f80 */ 	lui	$at,0x3f80
/*  f0c79fc:	46023003 */ 	div.s	$f0,$f6,$f2
/*  f0c7a00:	4600403c */ 	c.lt.s	$f8,$f0
/*  f0c7a04:	e7a001f8 */ 	swc1	$f0,0x1f8($sp)
/*  f0c7a08:	45000004 */ 	bc1f	.NB0f0c7a1c
/*  f0c7a0c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c7a10:	44810000 */ 	mtc1	$at,$f0
/*  f0c7a14:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c7a18:	e7a001f8 */ 	swc1	$f0,0x1f8($sp)
.NB0f0c7a1c:
/*  f0c7a1c:	52e00060 */ 	beqzl	$s7,.NB0f0c7ba0
/*  f0c7a20:	97aa00ca */ 	lhu	$t2,0xca($sp)
/*  f0c7a24:	84a2024c */ 	lh	$v0,0x24c($a1)
/*  f0c7a28:	2841fffe */ 	slti	$at,$v0,-2
/*  f0c7a2c:	10200009 */ 	beqz	$at,.NB0f0c7a54
/*  f0c7a30:	00564021 */ 	addu	$t0,$v0,$s6
/*  f0c7a34:	a4a8024c */ 	sh	$t0,0x24c($a1)
/*  f0c7a38:	8e450284 */ 	lw	$a1,0x284($s2)
/*  f0c7a3c:	84a9024c */ 	lh	$t1,0x24c($a1)
/*  f0c7a40:	2921fffe */ 	slti	$at,$t1,-2
/*  f0c7a44:	54200056 */ 	bnezl	$at,.NB0f0c7ba0
/*  f0c7a48:	97aa00ca */ 	lhu	$t2,0xca($sp)
/*  f0c7a4c:	10000053 */ 	beqz	$zero,.NB0f0c7b9c
/*  f0c7a50:	a4a0024c */ 	sh	$zero,0x24c($a1)
.NB0f0c7a54:
/*  f0c7a54:	1ac00051 */ 	blez	$s6,.NB0f0c7b9c
/*  f0c7a58:	00008025 */ 	or	$s0,$zero,$zero
/*  f0c7a5c:	97b1019e */ 	lhu	$s1,0x19e($sp)
/*  f0c7a60:	97aa00ca */ 	lhu	$t2,0xca($sp)
/*  f0c7a64:	2413ffff */ 	addiu	$s3,$zero,-1
/*  f0c7a68:	01513024 */ 	and	$a2,$t2,$s1
/*  f0c7a6c:	30cbffff */ 	andi	$t3,$a2,0xffff
/*  f0c7a70:	afab003c */ 	sw	$t3,0x3c($sp)
/*  f0c7a74:	00152e00 */ 	sll	$a1,$s5,0x18
.NB0f0c7a78:
/*  f0c7a78:	00056603 */ 	sra	$t4,$a1,0x18
/*  f0c7a7c:	8fa6003c */ 	lw	$a2,0x3c($sp)
/*  f0c7a80:	01802825 */ 	or	$a1,$t4,$zero
/*  f0c7a84:	0c005656 */ 	jal	joyGetButtonsOnSample
/*  f0c7a88:	02002025 */ 	or	$a0,$s0,$zero
/*  f0c7a8c:	5040002d */ 	beqzl	$v0,.NB0f0c7b44
/*  f0c7a90:	8e4f0284 */ 	lw	$t7,0x284($s2)
/*  f0c7a94:	8e4d0284 */ 	lw	$t5,0x284($s2)
/*  f0c7a98:	00152e00 */ 	sll	$a1,$s5,0x18
/*  f0c7a9c:	00057e03 */ 	sra	$t7,$a1,0x18
/*  f0c7aa0:	85ae024c */ 	lh	$t6,0x24c($t5)
/*  f0c7aa4:	01e02825 */ 	or	$a1,$t7,$zero
/*  f0c7aa8:	02002025 */ 	or	$a0,$s0,$zero
/*  f0c7aac:	29c1ffff */ 	slti	$at,$t6,-1
/*  f0c7ab0:	14200037 */ 	bnez	$at,.NB0f0c7b90
/*  f0c7ab4:	02913024 */ 	and	$a2,$s4,$s1
/*  f0c7ab8:	30d8ffff */ 	andi	$t8,$a2,0xffff
/*  f0c7abc:	03003025 */ 	or	$a2,$t8,$zero
/*  f0c7ac0:	0c00568c */ 	jal	joyGetButtonsPressedOnSample
/*  f0c7ac4:	afb8004c */ 	sw	$t8,0x4c($sp)
/*  f0c7ac8:	10400006 */ 	beqz	$v0,.NB0f0c7ae4
/*  f0c7acc:	8fa6004c */ 	lw	$a2,0x4c($sp)
/*  f0c7ad0:	8fb901fc */ 	lw	$t9,0x1fc($sp)
/*  f0c7ad4:	8e490284 */ 	lw	$t1,0x284($s2)
/*  f0c7ad8:	27280001 */ 	addiu	$t0,$t9,0x1
/*  f0c7adc:	afa801fc */ 	sw	$t0,0x1fc($sp)
/*  f0c7ae0:	a533024c */ 	sh	$s3,0x24c($t1)
.NB0f0c7ae4:
/*  f0c7ae4:	8e4a0284 */ 	lw	$t2,0x284($s2)
/*  f0c7ae8:	00152e00 */ 	sll	$a1,$s5,0x18
/*  f0c7aec:	00056603 */ 	sra	$t4,$a1,0x18
/*  f0c7af0:	854b024c */ 	lh	$t3,0x24c($t2)
/*  f0c7af4:	02002025 */ 	or	$a0,$s0,$zero
/*  f0c7af8:	05620026 */ 	bltzl	$t3,.NB0f0c7b94
/*  f0c7afc:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f0c7b00:	0c005656 */ 	jal	joyGetButtonsOnSample
/*  f0c7b04:	01802825 */ 	or	$a1,$t4,$zero
/*  f0c7b08:	54400022 */ 	bnezl	$v0,.NB0f0c7b94
/*  f0c7b0c:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f0c7b10:	8e450284 */ 	lw	$a1,0x284($s2)
/*  f0c7b14:	84a2024c */ 	lh	$v0,0x24c($a1)
/*  f0c7b18:	28410010 */ 	slti	$at,$v0,0x10
/*  f0c7b1c:	14200006 */ 	bnez	$at,.NB0f0c7b38
/*  f0c7b20:	244e0001 */ 	addiu	$t6,$v0,0x1
/*  f0c7b24:	0fc3ecc4 */ 	jal	amOpen
/*  f0c7b28:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c7b2c:	8e4d0284 */ 	lw	$t5,0x284($s2)
/*  f0c7b30:	10000017 */ 	beqz	$zero,.NB0f0c7b90
/*  f0c7b34:	a5b3024c */ 	sh	$s3,0x24c($t5)
.NB0f0c7b38:
/*  f0c7b38:	10000015 */ 	beqz	$zero,.NB0f0c7b90
/*  f0c7b3c:	a4ae024c */ 	sh	$t6,0x24c($a1)
/*  f0c7b40:	8e4f0284 */ 	lw	$t7,0x284($s2)
.NB0f0c7b44:
/*  f0c7b44:	85f8024c */ 	lh	$t8,0x24c($t7)
/*  f0c7b48:	5b000010 */ 	blezl	$t8,.NB0f0c7b8c
/*  f0c7b4c:	8e490284 */ 	lw	$t1,0x284($s2)
/*  f0c7b50:	12e0000a */ 	beqz	$s7,.NB0f0c7b7c
/*  f0c7b54:	02002025 */ 	or	$a0,$s0,$zero
/*  f0c7b58:	00152e00 */ 	sll	$a1,$s5,0x18
/*  f0c7b5c:	02913024 */ 	and	$a2,$s4,$s1
/*  f0c7b60:	30c8ffff */ 	andi	$t0,$a2,0xffff
/*  f0c7b64:	0005ce03 */ 	sra	$t9,$a1,0x18
/*  f0c7b68:	03202825 */ 	or	$a1,$t9,$zero
/*  f0c7b6c:	0c005656 */ 	jal	joyGetButtonsOnSample
/*  f0c7b70:	01003025 */ 	or	$a2,$t0,$zero
/*  f0c7b74:	54400005 */ 	bnezl	$v0,.NB0f0c7b8c
/*  f0c7b78:	8e490284 */ 	lw	$t1,0x284($s2)
.NB0f0c7b7c:
/*  f0c7b7c:	8fa20200 */ 	lw	$v0,0x200($sp)
/*  f0c7b80:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f0c7b84:	afa20200 */ 	sw	$v0,0x200($sp)
/*  f0c7b88:	8e490284 */ 	lw	$t1,0x284($s2)
.NB0f0c7b8c:
/*  f0c7b8c:	a520024c */ 	sh	$zero,0x24c($t1)
.NB0f0c7b90:
/*  f0c7b90:	26100001 */ 	addiu	$s0,$s0,0x1
.NB0f0c7b94:
/*  f0c7b94:	5616ffb8 */ 	bnel	$s0,$s6,.NB0f0c7a78
/*  f0c7b98:	00152e00 */ 	sll	$a1,$s5,0x18
.NB0f0c7b9c:
/*  f0c7b9c:	97aa00ca */ 	lhu	$t2,0xca($sp)
.NB0f0c7ba0:
/*  f0c7ba0:	2413ffff */ 	addiu	$s3,$zero,-1
/*  f0c7ba4:	12e00058 */ 	beqz	$s7,.NB0f0c7d08
/*  f0c7ba8:	afaa0038 */ 	sw	$t2,0x38($sp)
/*  f0c7bac:	1ac00056 */ 	blez	$s6,.NB0f0c7d08
/*  f0c7bb0:	00008025 */ 	or	$s0,$zero,$zero
/*  f0c7bb4:	97b1019e */ 	lhu	$s1,0x19e($sp)
/*  f0c7bb8:	322c4000 */ 	andi	$t4,$s1,0x4000
/*  f0c7bbc:	afac0044 */ 	sw	$t4,0x44($sp)
/*  f0c7bc0:	00152e00 */ 	sll	$a1,$s5,0x18
.NB0f0c7bc4:
/*  f0c7bc4:	00056e03 */ 	sra	$t5,$a1,0x18
/*  f0c7bc8:	01a02825 */ 	or	$a1,$t5,$zero
/*  f0c7bcc:	02002025 */ 	or	$a0,$s0,$zero
/*  f0c7bd0:	0c005656 */ 	jal	joyGetButtonsOnSample
/*  f0c7bd4:	97a60046 */ 	lhu	$a2,0x46($sp)
/*  f0c7bd8:	50400040 */ 	beqzl	$v0,.NB0f0c7cdc
/*  f0c7bdc:	8e450284 */ 	lw	$a1,0x284($s2)
/*  f0c7be0:	8e4e0284 */ 	lw	$t6,0x284($s2)
/*  f0c7be4:	00152e00 */ 	sll	$a1,$s5,0x18
/*  f0c7be8:	00057e03 */ 	sra	$t7,$a1,0x18
/*  f0c7bec:	85c4024e */ 	lh	$a0,0x24e($t6)
/*  f0c7bf0:	02913024 */ 	and	$a2,$s4,$s1
/*  f0c7bf4:	30d8ffff */ 	andi	$t8,$a2,0xffff
/*  f0c7bf8:	2881ffff */ 	slti	$at,$a0,-1
/*  f0c7bfc:	1420002f */ 	bnez	$at,.NB0f0c7cbc
/*  f0c7c00:	01e02825 */ 	or	$a1,$t7,$zero
/*  f0c7c04:	02002025 */ 	or	$a0,$s0,$zero
/*  f0c7c08:	0c00568c */ 	jal	joyGetButtonsPressedOnSample
/*  f0c7c0c:	03003025 */ 	or	$a2,$t8,$zero
/*  f0c7c10:	5040000e */ 	beqzl	$v0,.NB0f0c7c4c
/*  f0c7c14:	8e450284 */ 	lw	$a1,0x284($s2)
/*  f0c7c18:	8e590284 */ 	lw	$t9,0x284($s2)
/*  f0c7c1c:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f0c7c20:	8724024e */ 	lh	$a0,0x24e($t9)
/*  f0c7c24:	04820009 */ 	bltzl	$a0,.NB0f0c7c4c
/*  f0c7c28:	8e450284 */ 	lw	$a1,0x284($s2)
/*  f0c7c2c:	0fc299bf */ 	jal	bgunConsiderToggleGunFunction
/*  f0c7c30:	00003025 */ 	or	$a2,$zero,$zero
/*  f0c7c34:	50400005 */ 	beqzl	$v0,.NB0f0c7c4c
/*  f0c7c38:	8e450284 */ 	lw	$a1,0x284($s2)
/*  f0c7c3c:	8e490284 */ 	lw	$t1,0x284($s2)
/*  f0c7c40:	2408fffd */ 	addiu	$t0,$zero,-3
/*  f0c7c44:	a528024e */ 	sh	$t0,0x24e($t1)
/*  f0c7c48:	8e450284 */ 	lw	$a1,0x284($s2)
.NB0f0c7c4c:
/*  f0c7c4c:	84a4024e */ 	lh	$a0,0x24e($a1)
/*  f0c7c50:	0480002a */ 	bltz	$a0,.NB0f0c7cfc
/*  f0c7c54:	2881001a */ 	slti	$at,$a0,0x1a
/*  f0c7c58:	14200016 */ 	bnez	$at,.NB0f0c7cb4
/*  f0c7c5c:	248f0001 */ 	addiu	$t7,$a0,0x1
/*  f0c7c60:	00002825 */ 	or	$a1,$zero,$zero
/*  f0c7c64:	0fc299bf */ 	jal	bgunConsiderToggleGunFunction
/*  f0c7c68:	00003025 */ 	or	$a2,$zero,$zero
/*  f0c7c6c:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0c7c70:	54410005 */ 	bnel	$v0,$at,.NB0f0c7c88
/*  f0c7c74:	24010002 */ 	addiu	$at,$zero,0x2
/*  f0c7c78:	8e4a0284 */ 	lw	$t2,0x284($s2)
/*  f0c7c7c:	1000001f */ 	beqz	$zero,.NB0f0c7cfc
/*  f0c7c80:	a553024e */ 	sh	$s3,0x24e($t2)
/*  f0c7c84:	24010002 */ 	addiu	$at,$zero,0x2
.NB0f0c7c88:
/*  f0c7c88:	54410006 */ 	bnel	$v0,$at,.NB0f0c7ca4
/*  f0c7c8c:	8e450284 */ 	lw	$a1,0x284($s2)
/*  f0c7c90:	8e4c0284 */ 	lw	$t4,0x284($s2)
/*  f0c7c94:	240bfffe */ 	addiu	$t3,$zero,-2
/*  f0c7c98:	10000018 */ 	beqz	$zero,.NB0f0c7cfc
/*  f0c7c9c:	a58b024e */ 	sh	$t3,0x24e($t4)
/*  f0c7ca0:	8e450284 */ 	lw	$a1,0x284($s2)
.NB0f0c7ca4:
/*  f0c7ca4:	84ad024e */ 	lh	$t5,0x24e($a1)
/*  f0c7ca8:	25ae0001 */ 	addiu	$t6,$t5,0x1
/*  f0c7cac:	10000013 */ 	beqz	$zero,.NB0f0c7cfc
/*  f0c7cb0:	a4ae024e */ 	sh	$t6,0x24e($a1)
.NB0f0c7cb4:
/*  f0c7cb4:	10000011 */ 	beqz	$zero,.NB0f0c7cfc
/*  f0c7cb8:	a4af024e */ 	sh	$t7,0x24e($a1)
.NB0f0c7cbc:
/*  f0c7cbc:	2881fffe */ 	slti	$at,$a0,-2
/*  f0c7cc0:	1420000e */ 	bnez	$at,.NB0f0c7cfc
/*  f0c7cc4:	00002825 */ 	or	$a1,$zero,$zero
/*  f0c7cc8:	0fc299bf */ 	jal	bgunConsiderToggleGunFunction
/*  f0c7ccc:	00003025 */ 	or	$a2,$zero,$zero
/*  f0c7cd0:	1000000b */ 	beqz	$zero,.NB0f0c7d00
/*  f0c7cd4:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f0c7cd8:	8e450284 */ 	lw	$a1,0x284($s2)
.NB0f0c7cdc:
/*  f0c7cdc:	8fb901c0 */ 	lw	$t9,0x1c0($sp)
/*  f0c7ce0:	84b8024e */ 	lh	$t8,0x24e($a1)
/*  f0c7ce4:	27280001 */ 	addiu	$t0,$t9,0x1
/*  f0c7ce8:	1b000002 */ 	blez	$t8,.NB0f0c7cf4
/*  f0c7cec:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c7cf0:	afa801c0 */ 	sw	$t0,0x1c0($sp)
.NB0f0c7cf4:
/*  f0c7cf4:	0fc29a7c */ 	jal	bgun0f0a8c50
/*  f0c7cf8:	a4a0024e */ 	sh	$zero,0x24e($a1)
.NB0f0c7cfc:
/*  f0c7cfc:	26100001 */ 	addiu	$s0,$s0,0x1
.NB0f0c7d00:
/*  f0c7d00:	5616ffb0 */ 	bnel	$s0,$s6,.NB0f0c7bc4
/*  f0c7d04:	00152e00 */ 	sll	$a1,$s5,0x18
.NB0f0c7d08:
/*  f0c7d08:	8fa901a8 */ 	lw	$t1,0x1a8($sp)
/*  f0c7d0c:	1120001c */ 	beqz	$t1,.NB0f0c7d80
/*  f0c7d10:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c7d14:	8e4a0284 */ 	lw	$t2,0x284($s2)
/*  f0c7d18:	8fa20048 */ 	lw	$v0,0x48($sp)
/*  f0c7d1c:	3c013f80 */ 	lui	$at,0x3f80
/*  f0c7d20:	8d4b0120 */ 	lw	$t3,0x120($t2)
/*  f0c7d24:	30510808 */ 	andi	$s1,$v0,0x808
/*  f0c7d28:	0011602b */ 	sltu	$t4,$zero,$s1
/*  f0c7d2c:	11600014 */ 	beqz	$t3,.NB0f0c7d80
/*  f0c7d30:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f0c7d34:	44810000 */ 	mtc1	$at,$f0
/*  f0c7d38:	30500404 */ 	andi	$s0,$v0,0x404
/*  f0c7d3c:	0010682b */ 	sltu	$t5,$zero,$s0
/*  f0c7d40:	01a08025 */ 	or	$s0,$t5,$zero
/*  f0c7d44:	01808825 */ 	or	$s1,$t4,$zero
/*  f0c7d48:	0fc27dd7 */ 	jal	bgunGetWeaponNum
/*  f0c7d4c:	e7a000bc */ 	swc1	$f0,0xbc($sp)
/*  f0c7d50:	24010016 */ 	addiu	$at,$zero,0x16
/*  f0c7d54:	14410004 */ 	bne	$v0,$at,.NB0f0c7d68
/*  f0c7d58:	c7a000bc */ 	lwc1	$f0,0xbc($sp)
/*  f0c7d5c:	3c013f00 */ 	lui	$at,0x3f00
/*  f0c7d60:	44810000 */ 	mtc1	$at,$f0
/*  f0c7d64:	00000000 */ 	sll	$zero,$zero,0x0
.NB0f0c7d68:
/*  f0c7d68:	12000002 */ 	beqz	$s0,.NB0f0c7d74
/*  f0c7d6c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c7d70:	e7a00210 */ 	swc1	$f0,0x210($sp)
.NB0f0c7d74:
/*  f0c7d74:	12200002 */ 	beqz	$s1,.NB0f0c7d80
/*  f0c7d78:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c7d7c:	e7a00214 */ 	swc1	$f0,0x214($sp)
.NB0f0c7d80:
/*  f0c7d80:	12e00052 */ 	beqz	$s7,.NB0f0c7ecc
/*  f0c7d84:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c7d88:	1ac00050 */ 	blez	$s6,.NB0f0c7ecc
/*  f0c7d8c:	00008025 */ 	or	$s0,$zero,$zero
/*  f0c7d90:	8fae01a8 */ 	lw	$t6,0x1a8($sp)
.NB0f0c7d94:
/*  f0c7d94:	00107880 */ 	sll	$t7,$s0,0x2
/*  f0c7d98:	03afc021 */ 	addu	$t8,$sp,$t7
/*  f0c7d9c:	55c0002c */ 	bnezl	$t6,.NB0f0c7e50
/*  f0c7da0:	8e4e0288 */ 	lw	$t6,0x288($s2)
/*  f0c7da4:	8f18014c */ 	lw	$t8,0x14c($t8)
/*  f0c7da8:	02002025 */ 	or	$a0,$s0,$zero
/*  f0c7dac:	00152e00 */ 	sll	$a1,$s5,0x18
/*  f0c7db0:	13000026 */ 	beqz	$t8,.NB0f0c7e4c
/*  f0c7db4:	97b1019e */ 	lhu	$s1,0x19e($sp)
/*  f0c7db8:	02203025 */ 	or	$a2,$s1,$zero
/*  f0c7dbc:	30c80808 */ 	andi	$t0,$a2,0x808
/*  f0c7dc0:	0005ce03 */ 	sra	$t9,$a1,0x18
/*  f0c7dc4:	322a0404 */ 	andi	$t2,$s1,0x404
/*  f0c7dc8:	afaa0050 */ 	sw	$t2,0x50($sp)
/*  f0c7dcc:	03202825 */ 	or	$a1,$t9,$zero
/*  f0c7dd0:	0c00568c */ 	jal	joyGetButtonsPressedOnSample
/*  f0c7dd4:	01003025 */ 	or	$a2,$t0,$zero
/*  f0c7dd8:	1040000b */ 	beqz	$v0,.NB0f0c7e08
/*  f0c7ddc:	02002025 */ 	or	$a0,$s0,$zero
/*  f0c7de0:	8fa20218 */ 	lw	$v0,0x218($sp)
/*  f0c7de4:	10400003 */ 	beqz	$v0,.NB0f0c7df4
/*  f0c7de8:	2442ffff */ 	addiu	$v0,$v0,-1
/*  f0c7dec:	10000004 */ 	beqz	$zero,.NB0f0c7e00
/*  f0c7df0:	afa20218 */ 	sw	$v0,0x218($sp)
.NB0f0c7df4:
/*  f0c7df4:	8fa2021c */ 	lw	$v0,0x21c($sp)
/*  f0c7df8:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f0c7dfc:	afa2021c */ 	sw	$v0,0x21c($sp)
.NB0f0c7e00:
/*  f0c7e00:	8e4b0284 */ 	lw	$t3,0x284($s2)
/*  f0c7e04:	ad730260 */ 	sw	$s3,0x260($t3)
.NB0f0c7e08:
/*  f0c7e08:	00152e00 */ 	sll	$a1,$s5,0x18
/*  f0c7e0c:	00056603 */ 	sra	$t4,$a1,0x18
/*  f0c7e10:	01802825 */ 	or	$a1,$t4,$zero
/*  f0c7e14:	0c00568c */ 	jal	joyGetButtonsPressedOnSample
/*  f0c7e18:	97a60052 */ 	lhu	$a2,0x52($sp)
/*  f0c7e1c:	5040000c */ 	beqzl	$v0,.NB0f0c7e50
/*  f0c7e20:	8e4e0288 */ 	lw	$t6,0x288($s2)
/*  f0c7e24:	8fa2021c */ 	lw	$v0,0x21c($sp)
/*  f0c7e28:	10400003 */ 	beqz	$v0,.NB0f0c7e38
/*  f0c7e2c:	2442ffff */ 	addiu	$v0,$v0,-1
/*  f0c7e30:	10000004 */ 	beqz	$zero,.NB0f0c7e44
/*  f0c7e34:	afa2021c */ 	sw	$v0,0x21c($sp)
.NB0f0c7e38:
/*  f0c7e38:	8fa20218 */ 	lw	$v0,0x218($sp)
/*  f0c7e3c:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f0c7e40:	afa20218 */ 	sw	$v0,0x218($sp)
.NB0f0c7e44:
/*  f0c7e44:	8e4d0284 */ 	lw	$t5,0x284($s2)
/*  f0c7e48:	adb30260 */ 	sw	$s3,0x260($t5)
.NB0f0c7e4c:
/*  f0c7e4c:	8e4e0288 */ 	lw	$t6,0x288($s2)
.NB0f0c7e50:
/*  f0c7e50:	0fc533b7 */ 	jal	optionsGetAimControl
/*  f0c7e54:	8dc40070 */ 	lw	$a0,0x70($t6)
/*  f0c7e58:	14400019 */ 	bnez	$v0,.NB0f0c7ec0
/*  f0c7e5c:	00107880 */ 	sll	$t7,$s0,0x2
/*  f0c7e60:	03afc021 */ 	addu	$t8,$sp,$t7
/*  f0c7e64:	8f18014c */ 	lw	$t8,0x14c($t8)
/*  f0c7e68:	53000008 */ 	beqzl	$t8,.NB0f0c7e8c
/*  f0c7e6c:	8e450284 */ 	lw	$a1,0x284($s2)
/*  f0c7e70:	8e450284 */ 	lw	$a1,0x284($s2)
/*  f0c7e74:	8ca20260 */ 	lw	$v0,0x260($a1)
/*  f0c7e78:	04400011 */ 	bltz	$v0,.NB0f0c7ec0
/*  f0c7e7c:	24590001 */ 	addiu	$t9,$v0,0x1
/*  f0c7e80:	1000000f */ 	beqz	$zero,.NB0f0c7ec0
/*  f0c7e84:	acb90260 */ 	sw	$t9,0x260($a1)
/*  f0c7e88:	8e450284 */ 	lw	$a1,0x284($s2)
.NB0f0c7e8c:
/*  f0c7e8c:	8ca20260 */ 	lw	$v0,0x260($a1)
/*  f0c7e90:	1840000a */ 	blez	$v0,.NB0f0c7ebc
/*  f0c7e94:	2841000f */ 	slti	$at,$v0,0xf
/*  f0c7e98:	10200008 */ 	beqz	$at,.NB0f0c7ebc
/*  f0c7e9c:	8fa20218 */ 	lw	$v0,0x218($sp)
/*  f0c7ea0:	10400003 */ 	beqz	$v0,.NB0f0c7eb0
/*  f0c7ea4:	2442ffff */ 	addiu	$v0,$v0,-1
/*  f0c7ea8:	10000004 */ 	beqz	$zero,.NB0f0c7ebc
/*  f0c7eac:	afa20218 */ 	sw	$v0,0x218($sp)
.NB0f0c7eb0:
/*  f0c7eb0:	8fa2021c */ 	lw	$v0,0x21c($sp)
/*  f0c7eb4:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f0c7eb8:	afa2021c */ 	sw	$v0,0x21c($sp)
.NB0f0c7ebc:
/*  f0c7ebc:	aca00260 */ 	sw	$zero,0x260($a1)
.NB0f0c7ec0:
/*  f0c7ec0:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f0c7ec4:	5616ffb3 */ 	bnel	$s0,$s6,.NB0f0c7d94
/*  f0c7ec8:	8fae01a8 */ 	lw	$t6,0x1a8($sp)
.NB0f0c7ecc:
/*  f0c7ecc:	0fc327ab */ 	jal	bmoveGetCrouchPos
/*  f0c7ed0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c7ed4:	1440001e */ 	bnez	$v0,.NB0f0c7f50
/*  f0c7ed8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c7edc:	8e450284 */ 	lw	$a1,0x284($s2)
/*  f0c7ee0:	3c01c2b4 */ 	lui	$at,0xc2b4
/*  f0c7ee4:	44818000 */ 	mtc1	$at,$f16
/*  f0c7ee8:	c4b200b4 */ 	lwc1	$f18,0xb4($a1)
/*  f0c7eec:	46128032 */ 	c.eq.s	$f16,$f18
/*  f0c7ef0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c7ef4:	45000016 */ 	bc1f	.NB0f0c7f50
/*  f0c7ef8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c7efc:	8e480314 */ 	lw	$t0,0x314($s2)
/*  f0c7f00:	11000013 */ 	beqz	$t0,.NB0f0c7f50
/*  f0c7f04:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c7f08:	8e490298 */ 	lw	$t1,0x298($s2)
/*  f0c7f0c:	05210010 */ 	bgez	$t1,.NB0f0c7f50
/*  f0c7f10:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c7f14:	8ca40120 */ 	lw	$a0,0x120($a1)
/*  f0c7f18:	8fa201a8 */ 	lw	$v0,0x1a8($sp)
/*  f0c7f1c:	0004502b */ 	sltu	$t2,$zero,$a0
/*  f0c7f20:	1140000a */ 	beqz	$t2,.NB0f0c7f4c
/*  f0c7f24:	01402025 */ 	or	$a0,$t2,$zero
/*  f0c7f28:	2c440001 */ 	sltiu	$a0,$v0,0x1
/*  f0c7f2c:	10800007 */ 	beqz	$a0,.NB0f0c7f4c
/*  f0c7f30:	97ad019e */ 	lhu	$t5,0x19e($sp)
/*  f0c7f34:	00152600 */ 	sll	$a0,$s5,0x18
/*  f0c7f38:	00046603 */ 	sra	$t4,$a0,0x18
/*  f0c7f3c:	01802025 */ 	or	$a0,$t4,$zero
/*  f0c7f40:	0c005790 */ 	jal	joyGetButtons
/*  f0c7f44:	31a50404 */ 	andi	$a1,$t5,0x404
/*  f0c7f48:	0002202b */ 	sltu	$a0,$zero,$v0
.NB0f0c7f4c:
/*  f0c7f4c:	afa40234 */ 	sw	$a0,0x234($sp)
.NB0f0c7f50:
/*  f0c7f50:	0fc27dd7 */ 	jal	bgunGetWeaponNum
/*  f0c7f54:	00002025 */ 	or	$a0,$zero,$zero
/*  f0c7f58:	24010016 */ 	addiu	$at,$zero,0x16
/*  f0c7f5c:	5441000c */ 	bnel	$v0,$at,.NB0f0c7f90
/*  f0c7f60:	8e450284 */ 	lw	$a1,0x284($s2)
/*  f0c7f64:	8e450284 */ 	lw	$a1,0x284($s2)
/*  f0c7f68:	8ca40120 */ 	lw	$a0,0x120($a1)
/*  f0c7f6c:	0004782b */ 	sltu	$t7,$zero,$a0
/*  f0c7f70:	11e00004 */ 	beqz	$t7,.NB0f0c7f84
/*  f0c7f74:	01e02025 */ 	or	$a0,$t7,$zero
/*  f0c7f78:	8fa40048 */ 	lw	$a0,0x48($sp)
/*  f0c7f7c:	30980303 */ 	andi	$t8,$a0,0x303
/*  f0c7f80:	0018202b */ 	sltu	$a0,$zero,$t8
.NB0f0c7f84:
/*  f0c7f84:	10000012 */ 	beqz	$zero,.NB0f0c7fd0
/*  f0c7f88:	afa40230 */ 	sw	$a0,0x230($sp)
/*  f0c7f8c:	8e450284 */ 	lw	$a1,0x284($s2)
.NB0f0c7f90:
/*  f0c7f90:	8ca40120 */ 	lw	$a0,0x120($a1)
/*  f0c7f94:	0004402b */ 	sltu	$t0,$zero,$a0
/*  f0c7f98:	11000004 */ 	beqz	$t0,.NB0f0c7fac
/*  f0c7f9c:	01002025 */ 	or	$a0,$t0,$zero
/*  f0c7fa0:	8fa40048 */ 	lw	$a0,0x48($sp)
/*  f0c7fa4:	30890202 */ 	andi	$t1,$a0,0x202
/*  f0c7fa8:	0009202b */ 	sltu	$a0,$zero,$t1
.NB0f0c7fac:
/*  f0c7fac:	afa40220 */ 	sw	$a0,0x220($sp)
/*  f0c7fb0:	8ca40120 */ 	lw	$a0,0x120($a1)
/*  f0c7fb4:	0004582b */ 	sltu	$t3,$zero,$a0
/*  f0c7fb8:	11600004 */ 	beqz	$t3,.NB0f0c7fcc
/*  f0c7fbc:	01602025 */ 	or	$a0,$t3,$zero
/*  f0c7fc0:	8fa40048 */ 	lw	$a0,0x48($sp)
/*  f0c7fc4:	308c0101 */ 	andi	$t4,$a0,0x101
/*  f0c7fc8:	000c202b */ 	sltu	$a0,$zero,$t4
.NB0f0c7fcc:
/*  f0c7fcc:	afa40224 */ 	sw	$a0,0x224($sp)
.NB0f0c7fd0:
/*  f0c7fd0:	8fae0048 */ 	lw	$t6,0x48($sp)
/*  f0c7fd4:	8faf0038 */ 	lw	$t7,0x38($sp)
/*  f0c7fd8:	97b901a0 */ 	lhu	$t9,0x1a0($sp)
/*  f0c7fdc:	8fa90048 */ 	lw	$t1,0x48($sp)
/*  f0c7fe0:	01cfc024 */ 	and	$t8,$t6,$t7
/*  f0c7fe4:	13000002 */ 	beqz	$t8,.NB0f0c7ff0
/*  f0c7fe8:	33284000 */ 	andi	$t0,$t9,0x4000
/*  f0c7fec:	15000007 */ 	bnez	$t0,.NB0f0c800c
.NB0f0c7ff0:
/*  f0c7ff0:	312a4000 */ 	andi	$t2,$t1,0x4000
/*  f0c7ff4:	11400012 */ 	beqz	$t2,.NB0f0c8040
/*  f0c7ff8:	97ab01a0 */ 	lhu	$t3,0x1a0($sp)
/*  f0c7ffc:	8fac0038 */ 	lw	$t4,0x38($sp)
/*  f0c8000:	016c6824 */ 	and	$t5,$t3,$t4
/*  f0c8004:	51a0000f */ 	beqzl	$t5,.NB0f0c8044
/*  f0c8008:	8e450284 */ 	lw	$a1,0x284($s2)
.NB0f0c800c:
/*  f0c800c:	8fae01ac */ 	lw	$t6,0x1ac($sp)
/*  f0c8010:	24010022 */ 	addiu	$at,$zero,0x22
/*  f0c8014:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f0c8018:	15c10009 */ 	bne	$t6,$at,.NB0f0c8040
/*  f0c801c:	2418fffe */ 	addiu	$t8,$zero,-2
/*  f0c8020:	afaf0228 */ 	sw	$t7,0x228($sp)
/*  f0c8024:	afa001fc */ 	sw	$zero,0x1fc($sp)
/*  f0c8028:	afa00200 */ 	sw	$zero,0x200($sp)
/*  f0c802c:	afa001c0 */ 	sw	$zero,0x1c0($sp)
/*  f0c8030:	a4b8024c */ 	sh	$t8,0x24c($a1)
/*  f0c8034:	8e480284 */ 	lw	$t0,0x284($s2)
/*  f0c8038:	2419fffe */ 	addiu	$t9,$zero,-2
/*  f0c803c:	a519024e */ 	sh	$t9,0x24e($t0)
.NB0f0c8040:
/*  f0c8040:	8e450284 */ 	lw	$a1,0x284($s2)
.NB0f0c8044:
/*  f0c8044:	97ac01a2 */ 	lhu	$t4,0x1a2($sp)
/*  f0c8048:	8ca90120 */ 	lw	$t1,0x120($a1)
/*  f0c804c:	01946824 */ 	and	$t5,$t4,$s4
/*  f0c8050:	afa90208 */ 	sw	$t1,0x208($sp)
/*  f0c8054:	8caa0120 */ 	lw	$t2,0x120($a1)
/*  f0c8058:	afaa020c */ 	sw	$t2,0x20c($sp)
/*  f0c805c:	8cab0274 */ 	lw	$t3,0x274($a1)
/*  f0c8060:	11600004 */ 	beqz	$t3,.NB0f0c8074
/*  f0c8064:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c8068:	15a00002 */ 	bnez	$t5,.NB0f0c8074
/*  f0c806c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c8070:	aca00274 */ 	sw	$zero,0x274($a1)
.NB0f0c8074:
/*  f0c8074:	0fc27dd7 */ 	jal	bgunGetWeaponNum
/*  f0c8078:	00002025 */ 	or	$a0,$zero,$zero
/*  f0c807c:	00402025 */ 	or	$a0,$v0,$zero
/*  f0c8080:	0fc2bd48 */ 	jal	weaponHasFlag
/*  f0c8084:	3c058000 */ 	lui	$a1,0x8000
/*  f0c8088:	1040000d */ 	beqz	$v0,.NB0f0c80c0
/*  f0c808c:	97ae01a0 */ 	lhu	$t6,0x1a0($sp)
/*  f0c8090:	01d47824 */ 	and	$t7,$t6,$s4
/*  f0c8094:	11e00008 */ 	beqz	$t7,.NB0f0c80b8
/*  f0c8098:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c809c:	8e580284 */ 	lw	$t8,0x284($s2)
/*  f0c80a0:	8fa801c0 */ 	lw	$t0,0x1c0($sp)
/*  f0c80a4:	8f191a24 */ 	lw	$t9,0x1a24($t8)
/*  f0c80a8:	25090001 */ 	addiu	$t1,$t0,0x1
/*  f0c80ac:	17200002 */ 	bnez	$t9,.NB0f0c80b8
/*  f0c80b0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c80b4:	afa901c0 */ 	sw	$t1,0x1c0($sp)
.NB0f0c80b8:
/*  f0c80b8:	10000014 */ 	beqz	$zero,.NB0f0c810c
/*  f0c80bc:	8e450284 */ 	lw	$a1,0x284($s2)
.NB0f0c80c0:
/*  f0c80c0:	8e450284 */ 	lw	$a1,0x284($s2)
/*  f0c80c4:	97a301a2 */ 	lhu	$v1,0x1a2($sp)
/*  f0c80c8:	8ca40274 */ 	lw	$a0,0x274($a1)
/*  f0c80cc:	00741024 */ 	and	$v0,$v1,$s4
/*  f0c80d0:	2c8a0001 */ 	sltiu	$t2,$a0,0x1
/*  f0c80d4:	1140000c */ 	beqz	$t2,.NB0f0c8108
/*  f0c80d8:	01402025 */ 	or	$a0,$t2,$zero
/*  f0c80dc:	0002202b */ 	sltu	$a0,$zero,$v0
/*  f0c80e0:	5080000a */ 	beqzl	$a0,.NB0f0c810c
/*  f0c80e4:	afa401bc */ 	sw	$a0,0x1bc($sp)
/*  f0c80e8:	8ca41a24 */ 	lw	$a0,0x1a24($a1)
/*  f0c80ec:	97ad00ca */ 	lhu	$t5,0xca($sp)
/*  f0c80f0:	2c8c0001 */ 	sltiu	$t4,$a0,0x1
/*  f0c80f4:	11800004 */ 	beqz	$t4,.NB0f0c8108
/*  f0c80f8:	01802025 */ 	or	$a0,$t4,$zero
/*  f0c80fc:	006d2024 */ 	and	$a0,$v1,$t5
/*  f0c8100:	2c8e0001 */ 	sltiu	$t6,$a0,0x1
/*  f0c8104:	01c02025 */ 	or	$a0,$t6,$zero
.NB0f0c8108:
/*  f0c8108:	afa401bc */ 	sw	$a0,0x1bc($sp)
.NB0f0c810c:
/*  f0c810c:	8faf01b0 */ 	lw	$t7,0x1b0($sp)
/*  f0c8110:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0c8114:	24180001 */ 	addiu	$t8,$zero,0x1
/*  f0c8118:	11e10003 */ 	beq	$t7,$at,.NB0f0c8128
/*  f0c811c:	24010003 */ 	addiu	$at,$zero,0x3
/*  f0c8120:	55e10003 */ 	bnel	$t7,$at,.NB0f0c8130
/*  f0c8124:	aca000d0 */ 	sw	$zero,0xd0($a1)
.NB0f0c8128:
/*  f0c8128:	afb8023c */ 	sw	$t8,0x23c($sp)
.NB0f0c812c:
/*  f0c812c:	aca000d0 */ 	sw	$zero,0xd0($a1)
.NB0f0c8130:
/*  f0c8130:	8fb901c0 */ 	lw	$t9,0x1c0($sp)
/*  f0c8134:	5320000c */ 	beqzl	$t9,.NB0f0c8168
/*  f0c8138:	8fad0238 */ 	lw	$t5,0x238($sp)
/*  f0c813c:	8e450284 */ 	lw	$a1,0x284($s2)
/*  f0c8140:	8ca801a0 */ 	lw	$t0,0x1a0($a1)
/*  f0c8144:	aca8019c */ 	sw	$t0,0x19c($a1)
/*  f0c8148:	8e4a0284 */ 	lw	$t2,0x284($s2)
/*  f0c814c:	8e490008 */ 	lw	$t1,0x8($s2)
/*  f0c8150:	ad4901a0 */ 	sw	$t1,0x1a0($t2)
/*  f0c8154:	8e4c0284 */ 	lw	$t4,0x284($s2)
/*  f0c8158:	8fab01c0 */ 	lw	$t3,0x1c0($sp)
/*  f0c815c:	0fc315e3 */ 	jal	bmoveHandleActivate
/*  f0c8160:	ad8b00d0 */ 	sw	$t3,0xd0($t4)
/*  f0c8164:	8fad0238 */ 	lw	$t5,0x238($sp)
.NB0f0c8168:
/*  f0c8168:	15a0000b */ 	bnez	$t5,.NB0f0c8198
/*  f0c816c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c8170:	8fa4024c */ 	lw	$a0,0x24c($sp)
/*  f0c8174:	8fae0254 */ 	lw	$t6,0x254($sp)
/*  f0c8178:	c7a001ec */ 	lwc1	$f0,0x1ec($sp)
/*  f0c817c:	c7a401f0 */ 	lwc1	$f4,0x1f0($sp)
/*  f0c8180:	00042023 */ 	negu	$a0,$a0
/*  f0c8184:	000e7823 */ 	negu	$t7,$t6
/*  f0c8188:	afaf0254 */ 	sw	$t7,0x254($sp)
/*  f0c818c:	afa4024c */ 	sw	$a0,0x24c($sp)
/*  f0c8190:	e7a001f0 */ 	swc1	$f0,0x1f0($sp)
/*  f0c8194:	e7a401ec */ 	swc1	$f4,0x1ec($sp)
.NB0f0c8198:
/*  f0c8198:	0fc29ab5 */ 	jal	bgunsTick
/*  f0c819c:	8fa401bc */ 	lw	$a0,0x1bc($sp)
/*  f0c81a0:	8e580324 */ 	lw	$t8,0x324($s2)
/*  f0c81a4:	5300002b */ 	beqzl	$t8,.NB0f0c8254
/*  f0c81a8:	24040002 */ 	addiu	$a0,$zero,0x2
/*  f0c81ac:	0fc27f9e */ 	jal	bgunIsFiring
/*  f0c81b0:	00002025 */ 	or	$a0,$zero,$zero
/*  f0c81b4:	54400006 */ 	bnezl	$v0,.NB0f0c81d0
/*  f0c81b8:	44805000 */ 	mtc1	$zero,$f10
/*  f0c81bc:	0fc27f9e */ 	jal	bgunIsFiring
/*  f0c81c0:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f0c81c4:	50400023 */ 	beqzl	$v0,.NB0f0c8254
/*  f0c81c8:	24040002 */ 	addiu	$a0,$zero,0x2
/*  f0c81cc:	44805000 */ 	mtc1	$zero,$f10
.NB0f0c81d0:
/*  f0c81d0:	00002025 */ 	or	$a0,$zero,$zero
/*  f0c81d4:	0fc27f9e */ 	jal	bgunIsFiring
/*  f0c81d8:	e7aa00b4 */ 	swc1	$f10,0xb4($sp)
/*  f0c81dc:	1040000c */ 	beqz	$v0,.NB0f0c8210
/*  f0c81e0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c81e4:	0fc26b9d */ 	jal	bgunGetNoiseRadius
/*  f0c81e8:	00002025 */ 	or	$a0,$zero,$zero
/*  f0c81ec:	44803000 */ 	mtc1	$zero,$f6
/*  f0c81f0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c81f4:	4600303c */ 	c.lt.s	$f6,$f0
/*  f0c81f8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c81fc:	45000004 */ 	bc1f	.NB0f0c8210
/*  f0c8200:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c8204:	0fc26b9d */ 	jal	bgunGetNoiseRadius
/*  f0c8208:	00002025 */ 	or	$a0,$zero,$zero
/*  f0c820c:	e7a000b4 */ 	swc1	$f0,0xb4($sp)
.NB0f0c8210:
/*  f0c8210:	0fc27f9e */ 	jal	bgunIsFiring
/*  f0c8214:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f0c8218:	1040000b */ 	beqz	$v0,.NB0f0c8248
/*  f0c821c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c8220:	0fc26b9d */ 	jal	bgunGetNoiseRadius
/*  f0c8224:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f0c8228:	c7a800b4 */ 	lwc1	$f8,0xb4($sp)
/*  f0c822c:	4600403c */ 	c.lt.s	$f8,$f0
/*  f0c8230:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c8234:	45000004 */ 	bc1f	.NB0f0c8248
/*  f0c8238:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c823c:	0fc26b9d */ 	jal	bgunGetNoiseRadius
/*  f0c8240:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f0c8244:	e7a000b4 */ 	swc1	$f0,0xb4($sp)
.NB0f0c8248:
/*  f0c8248:	0fc09fe6 */ 	jal	func0f028590
/*  f0c824c:	c7ac00b4 */ 	lwc1	$f12,0xb4($sp)
/*  f0c8250:	24040002 */ 	addiu	$a0,$zero,0x2
.NB0f0c8254:
/*  f0c8254:	0fc2a675 */ 	jal	bgunSetSightVisible
/*  f0c8258:	8fa50208 */ 	lw	$a1,0x208($sp)
/*  f0c825c:	c7ac0210 */ 	lwc1	$f12,0x210($sp)
/*  f0c8260:	44808000 */ 	mtc1	$zero,$f16
/*  f0c8264:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c8268:	460c803c */ 	c.lt.s	$f16,$f12
/*  f0c826c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c8270:	45020004 */ 	bc1fl	.NB0f0c8284
/*  f0c8274:	c7ac0214 */ 	lwc1	$f12,0x214($sp)
/*  f0c8278:	0fc2bcba */ 	jal	currentPlayerZoomOut
/*  f0c827c:	e7ac0210 */ 	swc1	$f12,0x210($sp)
/*  f0c8280:	c7ac0214 */ 	lwc1	$f12,0x214($sp)
.NB0f0c8284:
/*  f0c8284:	44809000 */ 	mtc1	$zero,$f18
/*  f0c8288:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c828c:	460c903c */ 	c.lt.s	$f18,$f12
/*  f0c8290:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c8294:	45020004 */ 	bc1fl	.NB0f0c82a8
/*  f0c8298:	8e590284 */ 	lw	$t9,0x284($s2)
/*  f0c829c:	0fc2bd01 */ 	jal	currentPlayerZoomIn
/*  f0c82a0:	e7ac0214 */ 	swc1	$f12,0x214($sp)
/*  f0c82a4:	8e590284 */ 	lw	$t9,0x284($s2)
.NB0f0c82a8:
/*  f0c82a8:	8f281a24 */ 	lw	$t0,0x1a24($t9)
/*  f0c82ac:	150000b5 */ 	bnez	$t0,.NB0f0c8584
/*  f0c82b0:	3c098006 */ 	lui	$t1,0x8006
/*  f0c82b4:	8d29f2f0 */ 	lw	$t1,-0xd10($t1)
/*  f0c82b8:	3c014270 */ 	lui	$at,0x4270
/*  f0c82bc:	152000b1 */ 	bnez	$t1,.NB0f0c8584
/*  f0c82c0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c82c4:	44812000 */ 	mtc1	$at,$f4
/*  f0c82c8:	00002025 */ 	or	$a0,$zero,$zero
/*  f0c82cc:	0fc27dd7 */ 	jal	bgunGetWeaponNum
/*  f0c82d0:	e7a400b0 */ 	swc1	$f4,0xb0($sp)
/*  f0c82d4:	24010016 */ 	addiu	$at,$zero,0x16
/*  f0c82d8:	5441008b */ 	bnel	$v0,$at,.NB0f0c8508
/*  f0c82dc:	8fb8020c */ 	lw	$t8,0x20c($sp)
/*  f0c82e0:	8e450284 */ 	lw	$a1,0x284($s2)
/*  f0c82e4:	8fab0230 */ 	lw	$t3,0x230($sp)
/*  f0c82e8:	8caa0120 */ 	lw	$t2,0x120($a1)
/*  f0c82ec:	51400086 */ 	beqzl	$t2,.NB0f0c8508
/*  f0c82f0:	8fb8020c */ 	lw	$t8,0x20c($sp)
/*  f0c82f4:	55600006 */ 	bnezl	$t3,.NB0f0c8310
/*  f0c82f8:	c4a00258 */ 	lwc1	$f0,0x258($a1)
/*  f0c82fc:	90ac063b */ 	lbu	$t4,0x63b($a1)
/*  f0c8300:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0c8304:	55810080 */ 	bnel	$t4,$at,.NB0f0c8508
/*  f0c8308:	8fb8020c */ 	lw	$t8,0x20c($sp)
/*  f0c830c:	c4a00258 */ 	lwc1	$f0,0x258($a1)
.NB0f0c8310:
/*  f0c8310:	44805000 */ 	mtc1	$zero,$f10
/*  f0c8314:	3c0143fa */ 	lui	$at,0x43fa
/*  f0c8318:	4600503c */ 	c.lt.s	$f10,$f0
/*  f0c831c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c8320:	45020079 */ 	bc1fl	.NB0f0c8508
/*  f0c8324:	8fb8020c */ 	lw	$t8,0x20c($sp)
/*  f0c8328:	44813000 */ 	mtc1	$at,$f6
/*  f0c832c:	0fc2c9c6 */ 	jal	func0f0b49b8
/*  f0c8330:	46003303 */ 	div.s	$f12,$f6,$f0
/*  f0c8334:	3c014270 */ 	lui	$at,0x4270
/*  f0c8338:	44816000 */ 	mtc1	$at,$f12
/*  f0c833c:	46000086 */ 	mov.s	$f2,$f0
/*  f0c8340:	3c014000 */ 	lui	$at,0x4000
/*  f0c8344:	4600603c */ 	c.lt.s	$f12,$f0
/*  f0c8348:	44810000 */ 	mtc1	$at,$f0
/*  f0c834c:	45020003 */ 	bc1fl	.NB0f0c835c
/*  f0c8350:	4600103c */ 	c.lt.s	$f2,$f0
/*  f0c8354:	46006086 */ 	mov.s	$f2,$f12
/*  f0c8358:	4600103c */ 	c.lt.s	$f2,$f0
.NB0f0c835c:
/*  f0c835c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c8360:	45020003 */ 	bc1fl	.NB0f0c8370
/*  f0c8364:	8e4d0284 */ 	lw	$t5,0x284($s2)
/*  f0c8368:	46000086 */ 	mov.s	$f2,$f0
/*  f0c836c:	8e4d0284 */ 	lw	$t5,0x284($s2)
.NB0f0c8370:
/*  f0c8370:	e5a216f8 */ 	swc1	$f2,0x16f8($t5)
/*  f0c8374:	0fc2cd16 */ 	jal	currentPlayerGetMatrix1740
/*  f0c8378:	e7a200ac */ 	swc1	$f2,0xac($sp)
/*  f0c837c:	8e4e0284 */ 	lw	$t6,0x284($s2)
/*  f0c8380:	27b000a0 */ 	addiu	$s0,$sp,0xa0
/*  f0c8384:	02003025 */ 	or	$a2,$s0,$zero
/*  f0c8388:	8dc5025c */ 	lw	$a1,0x25c($t6)
/*  f0c838c:	00402025 */ 	or	$a0,$v0,$zero
/*  f0c8390:	0c005a96 */ 	jal	func00015b68
/*  f0c8394:	24a50008 */ 	addiu	$a1,$a1,0x8
/*  f0c8398:	c7a200ac */ 	lwc1	$f2,0xac($sp)
/*  f0c839c:	8e4f0284 */ 	lw	$t7,0x284($s2)
/*  f0c83a0:	02002025 */ 	or	$a0,$s0,$zero
/*  f0c83a4:	44061000 */ 	mfc1	$a2,$f2
/*  f0c83a8:	27a50098 */ 	addiu	$a1,$sp,0x98
/*  f0c83ac:	0fc2cb06 */ 	jal	func0f0b4eb8
/*  f0c83b0:	8de7171c */ 	lw	$a3,0x171c($t7)
/*  f0c83b4:	0fc2cd56 */ 	jal	currentPlayerGetScreenLeft
/*  f0c83b8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c83bc:	0fc2cd4e */ 	jal	currentPlayerGetScreenWidth
/*  f0c83c0:	e7a00054 */ 	swc1	$f0,0x54($sp)
/*  f0c83c4:	3c013f00 */ 	lui	$at,0x3f00
/*  f0c83c8:	44818000 */ 	mtc1	$at,$f16
/*  f0c83cc:	c7a40054 */ 	lwc1	$f4,0x54($sp)
/*  f0c83d0:	3c0141a0 */ 	lui	$at,0x41a0
/*  f0c83d4:	46100482 */ 	mul.s	$f18,$f0,$f16
/*  f0c83d8:	44813000 */ 	mtc1	$at,$f6
/*  f0c83dc:	c7a80098 */ 	lwc1	$f8,0x98($sp)
/*  f0c83e0:	3c013e80 */ 	lui	$at,0x3e80
/*  f0c83e4:	46049280 */ 	add.s	$f10,$f18,$f4
/*  f0c83e8:	46065401 */ 	sub.s	$f16,$f10,$f6
/*  f0c83ec:	4610403c */ 	c.lt.s	$f8,$f16
/*  f0c83f0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c83f4:	45000004 */ 	bc1f	.NB0f0c8408
/*  f0c83f8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c83fc:	44816000 */ 	mtc1	$at,$f12
/*  f0c8400:	10000016 */ 	beqz	$zero,.NB0f0c845c
/*  f0c8404:	e7ac01f4 */ 	swc1	$f12,0x1f4($sp)
.NB0f0c8408:
/*  f0c8408:	0fc2cd56 */ 	jal	currentPlayerGetScreenLeft
/*  f0c840c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c8410:	0fc2cd4e */ 	jal	currentPlayerGetScreenWidth
/*  f0c8414:	e7a00054 */ 	swc1	$f0,0x54($sp)
/*  f0c8418:	3c013f00 */ 	lui	$at,0x3f00
/*  f0c841c:	44819000 */ 	mtc1	$at,$f18
/*  f0c8420:	c7aa0054 */ 	lwc1	$f10,0x54($sp)
/*  f0c8424:	3c0141a0 */ 	lui	$at,0x41a0
/*  f0c8428:	46120102 */ 	mul.s	$f4,$f0,$f18
/*  f0c842c:	44814000 */ 	mtc1	$at,$f8
/*  f0c8430:	c7b20098 */ 	lwc1	$f18,0x98($sp)
/*  f0c8434:	3c013e80 */ 	lui	$at,0x3e80
/*  f0c8438:	460a2180 */ 	add.s	$f6,$f4,$f10
/*  f0c843c:	46083400 */ 	add.s	$f16,$f6,$f8
/*  f0c8440:	4612803c */ 	c.lt.s	$f16,$f18
/*  f0c8444:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c8448:	45000004 */ 	bc1f	.NB0f0c845c
/*  f0c844c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c8450:	44810000 */ 	mtc1	$at,$f0
/*  f0c8454:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c8458:	e7a001f8 */ 	swc1	$f0,0x1f8($sp)
.NB0f0c845c:
/*  f0c845c:	0fc2cd5a */ 	jal	currentPlayerGetScreenTop
/*  f0c8460:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c8464:	0fc2cd52 */ 	jal	currentPlayerGetScreenHeight
/*  f0c8468:	e7a00054 */ 	swc1	$f0,0x54($sp)
/*  f0c846c:	3c013f00 */ 	lui	$at,0x3f00
/*  f0c8470:	44815000 */ 	mtc1	$at,$f10
/*  f0c8474:	c7a80054 */ 	lwc1	$f8,0x54($sp)
/*  f0c8478:	3c0141a0 */ 	lui	$at,0x41a0
/*  f0c847c:	460a0182 */ 	mul.s	$f6,$f0,$f10
/*  f0c8480:	44819000 */ 	mtc1	$at,$f18
/*  f0c8484:	c7a4009c */ 	lwc1	$f4,0x9c($sp)
/*  f0c8488:	3c013e80 */ 	lui	$at,0x3e80
/*  f0c848c:	46083400 */ 	add.s	$f16,$f6,$f8
/*  f0c8490:	46128281 */ 	sub.s	$f10,$f16,$f18
/*  f0c8494:	460a203c */ 	c.lt.s	$f4,$f10
/*  f0c8498:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c849c:	45000004 */ 	bc1f	.NB0f0c84b0
/*  f0c84a0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c84a4:	44813000 */ 	mtc1	$at,$f6
/*  f0c84a8:	10000016 */ 	beqz	$zero,.NB0f0c8504
/*  f0c84ac:	e7a601f0 */ 	swc1	$f6,0x1f0($sp)
.NB0f0c84b0:
/*  f0c84b0:	0fc2cd5a */ 	jal	currentPlayerGetScreenTop
/*  f0c84b4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c84b8:	0fc2cd52 */ 	jal	currentPlayerGetScreenHeight
/*  f0c84bc:	e7a00054 */ 	swc1	$f0,0x54($sp)
/*  f0c84c0:	3c013f00 */ 	lui	$at,0x3f00
/*  f0c84c4:	44814000 */ 	mtc1	$at,$f8
/*  f0c84c8:	c7b20054 */ 	lwc1	$f18,0x54($sp)
/*  f0c84cc:	3c0141a0 */ 	lui	$at,0x41a0
/*  f0c84d0:	46080402 */ 	mul.s	$f16,$f0,$f8
/*  f0c84d4:	44815000 */ 	mtc1	$at,$f10
/*  f0c84d8:	c7a8009c */ 	lwc1	$f8,0x9c($sp)
/*  f0c84dc:	3c013e80 */ 	lui	$at,0x3e80
/*  f0c84e0:	46128100 */ 	add.s	$f4,$f16,$f18
/*  f0c84e4:	460a2180 */ 	add.s	$f6,$f4,$f10
/*  f0c84e8:	4608303c */ 	c.lt.s	$f6,$f8
/*  f0c84ec:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c84f0:	45020005 */ 	bc1fl	.NB0f0c8508
/*  f0c84f4:	8fb8020c */ 	lw	$t8,0x20c($sp)
/*  f0c84f8:	44818000 */ 	mtc1	$at,$f16
/*  f0c84fc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c8500:	e7b001ec */ 	swc1	$f16,0x1ec($sp)
.NB0f0c8504:
/*  f0c8504:	8fb8020c */ 	lw	$t8,0x20c($sp)
.NB0f0c8508:
/*  f0c8508:	13000004 */ 	beqz	$t8,.NB0f0c851c
/*  f0c850c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c8510:	0fc2bc8e */ 	jal	currentPlayerGetGunZoomFov
/*  f0c8514:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c8518:	e7a000b0 */ 	swc1	$f0,0xb0($sp)
.NB0f0c851c:
/*  f0c851c:	0fc27dd7 */ 	jal	bgunGetWeaponNum
/*  f0c8520:	00002025 */ 	or	$a0,$zero,$zero
/*  f0c8524:	24010011 */ 	addiu	$at,$zero,0x11
/*  f0c8528:	5441000a */ 	bnel	$v0,$at,.NB0f0c8554
/*  f0c852c:	c7ac00b0 */ 	lwc1	$f12,0xb0($sp)
/*  f0c8530:	8e590284 */ 	lw	$t9,0x284($s2)
/*  f0c8534:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0c8538:	9328063b */ 	lbu	$t0,0x63b($t9)
/*  f0c853c:	55010005 */ 	bnel	$t0,$at,.NB0f0c8554
/*  f0c8540:	c7ac00b0 */ 	lwc1	$f12,0xb0($sp)
/*  f0c8544:	0fc2bc8e */ 	jal	currentPlayerGetGunZoomFov
/*  f0c8548:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c854c:	e7a000b0 */ 	swc1	$f0,0xb0($sp)
/*  f0c8550:	c7ac00b0 */ 	lwc1	$f12,0xb0($sp)
.NB0f0c8554:
/*  f0c8554:	44809000 */ 	mtc1	$zero,$f18
/*  f0c8558:	3c014270 */ 	lui	$at,0x4270
/*  f0c855c:	4612603e */ 	c.le.s	$f12,$f18
/*  f0c8560:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c8564:	45000003 */ 	bc1f	.NB0f0c8574
/*  f0c8568:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c856c:	44816000 */ 	mtc1	$at,$f12
/*  f0c8570:	00000000 */ 	sll	$zero,$zero,0x0
.NB0f0c8574:
/*  f0c8574:	0fc2e161 */ 	jal	func0f0ba8b0
/*  f0c8578:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c857c:	0fc2e1e5 */ 	jal	currentPlayerUpdateZoom
/*  f0c8580:	00000000 */ 	sll	$zero,$zero,0x0
.NB0f0c8584:
/*  f0c8584:	0fc315fe */ 	jal	bmoveApplyMoveData
/*  f0c8588:	27a401b4 */ 	addiu	$a0,$sp,0x1b4
/*  f0c858c:	8e450284 */ 	lw	$a1,0x284($s2)
/*  f0c8590:	8ca90178 */ 	lw	$t1,0x178($a1)
/*  f0c8594:	292100b4 */ 	slti	$at,$t1,0xb4
/*  f0c8598:	14200016 */ 	bnez	$at,.NB0f0c85f4
/*  f0c859c:	3c013fa0 */ 	lui	$at,0x3fa0
/*  f0c85a0:	44811000 */ 	mtc1	$at,$f2
/*  f0c85a4:	c4a00174 */ 	lwc1	$f0,0x174($a1)
/*  f0c85a8:	3c017f1a */ 	lui	$at,0x7f1a
/*  f0c85ac:	4602003c */ 	c.lt.s	$f0,$f2
/*  f0c85b0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c85b4:	45020009 */ 	bc1fl	.NB0f0c85dc
/*  f0c85b8:	4600103c */ 	c.lt.s	$f2,$f0
/*  f0c85bc:	c4247bf8 */ 	lwc1	$f4,0x7bf8($at)
/*  f0c85c0:	c64a004c */ 	lwc1	$f10,0x4c($s2)
/*  f0c85c4:	460a2182 */ 	mul.s	$f6,$f4,$f10
/*  f0c85c8:	46060200 */ 	add.s	$f8,$f0,$f6
/*  f0c85cc:	e4a80174 */ 	swc1	$f8,0x174($a1)
/*  f0c85d0:	8e450284 */ 	lw	$a1,0x284($s2)
/*  f0c85d4:	c4a00174 */ 	lwc1	$f0,0x174($a1)
/*  f0c85d8:	4600103c */ 	c.lt.s	$f2,$f0
.NB0f0c85dc:
/*  f0c85dc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c85e0:	4502001f */ 	bc1fl	.NB0f0c8660
/*  f0c85e4:	8caa1a24 */ 	lw	$t2,0x1a24($a1)
/*  f0c85e8:	e4a20174 */ 	swc1	$f2,0x174($a1)
/*  f0c85ec:	1000001b */ 	beqz	$zero,.NB0f0c865c
/*  f0c85f0:	8e450284 */ 	lw	$a1,0x284($s2)
.NB0f0c85f4:
/*  f0c85f4:	3c013f80 */ 	lui	$at,0x3f80
/*  f0c85f8:	44818000 */ 	mtc1	$at,$f16
/*  f0c85fc:	c4a00174 */ 	lwc1	$f0,0x174($a1)
/*  f0c8600:	3c017f1a */ 	lui	$at,0x7f1a
/*  f0c8604:	4600803c */ 	c.lt.s	$f16,$f0
/*  f0c8608:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c860c:	45020009 */ 	bc1fl	.NB0f0c8634
/*  f0c8610:	3c013f80 */ 	lui	$at,0x3f80
/*  f0c8614:	c4327bfc */ 	lwc1	$f18,0x7bfc($at)
/*  f0c8618:	c644004c */ 	lwc1	$f4,0x4c($s2)
/*  f0c861c:	46049282 */ 	mul.s	$f10,$f18,$f4
/*  f0c8620:	460a0181 */ 	sub.s	$f6,$f0,$f10
/*  f0c8624:	e4a60174 */ 	swc1	$f6,0x174($a1)
/*  f0c8628:	8e450284 */ 	lw	$a1,0x284($s2)
/*  f0c862c:	c4a00174 */ 	lwc1	$f0,0x174($a1)
/*  f0c8630:	3c013f80 */ 	lui	$at,0x3f80
.NB0f0c8634:
/*  f0c8634:	44814000 */ 	mtc1	$at,$f8
/*  f0c8638:	3c013f80 */ 	lui	$at,0x3f80
/*  f0c863c:	4608003c */ 	c.lt.s	$f0,$f8
/*  f0c8640:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c8644:	45020006 */ 	bc1fl	.NB0f0c8660
/*  f0c8648:	8caa1a24 */ 	lw	$t2,0x1a24($a1)
/*  f0c864c:	44818000 */ 	mtc1	$at,$f16
/*  f0c8650:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c8654:	e4b00174 */ 	swc1	$f16,0x174($a1)
/*  f0c8658:	8e450284 */ 	lw	$a1,0x284($s2)
.NB0f0c865c:
/*  f0c865c:	8caa1a24 */ 	lw	$t2,0x1a24($a1)
.NB0f0c8660:
/*  f0c8660:	5540013e */ 	bnezl	$t2,.NB0f0c8b5c
/*  f0c8664:	8fa801cc */ 	lw	$t0,0x1cc($sp)
/*  f0c8668:	8ca201b0 */ 	lw	$v0,0x1b0($a1)
/*  f0c866c:	3c01c080 */ 	lui	$at,0xc080
/*  f0c8670:	44817000 */ 	mtc1	$at,$f14
/*  f0c8674:	2c440001 */ 	sltiu	$a0,$v0,0x1
/*  f0c8678:	54800004 */ 	bnezl	$a0,.NB0f0c868c
/*  f0c867c:	8cab0110 */ 	lw	$t3,0x110($a1)
/*  f0c8680:	38440004 */ 	xori	$a0,$v0,0x4
/*  f0c8684:	2c840001 */ 	sltiu	$a0,$a0,0x1
/*  f0c8688:	8cab0110 */ 	lw	$t3,0x110($a1)
.NB0f0c868c:
/*  f0c868c:	51600011 */ 	beqzl	$t3,.NB0f0c86d4
/*  f0c8690:	8cb8010c */ 	lw	$t8,0x10c($a1)
/*  f0c8694:	8e42000c */ 	lw	$v0,0xc($s2)
/*  f0c8698:	94ac1be4 */ 	lhu	$t4,0x1be4($a1)
/*  f0c869c:	504c000c */ 	beql	$v0,$t4,.NB0f0c86d0
/*  f0c86a0:	c4ae1be0 */ 	lwc1	$f14,0x1be0($a1)
/*  f0c86a4:	8e4d028c */ 	lw	$t5,0x28c($s2)
/*  f0c86a8:	304e0003 */ 	andi	$t6,$v0,0x3
/*  f0c86ac:	55ae0008 */ 	bnel	$t5,$t6,.NB0f0c86d0
/*  f0c86b0:	c4ae1be0 */ 	lwc1	$f14,0x1be0($a1)
/*  f0c86b4:	0fc3177e */ 	jal	bmoveCalculateLookahead
/*  f0c86b8:	afa40064 */ 	sw	$a0,0x64($sp)
/*  f0c86bc:	8e4f0284 */ 	lw	$t7,0x284($s2)
/*  f0c86c0:	8fa40064 */ 	lw	$a0,0x64($sp)
/*  f0c86c4:	e5e01be0 */ 	swc1	$f0,0x1be0($t7)
/*  f0c86c8:	8e450284 */ 	lw	$a1,0x284($s2)
/*  f0c86cc:	c4ae1be0 */ 	lwc1	$f14,0x1be0($a1)
.NB0f0c86d0:
/*  f0c86d0:	8cb8010c */ 	lw	$t8,0x10c($a1)
.NB0f0c86d4:
/*  f0c86d4:	8fb9025c */ 	lw	$t9,0x25c($sp)
/*  f0c86d8:	13000007 */ 	beqz	$t8,.NB0f0c86f8
/*  f0c86dc:	2b210028 */ 	slti	$at,$t9,0x28
/*  f0c86e0:	10200005 */ 	beqz	$at,.NB0f0c86f8
/*  f0c86e4:	2b21ffd9 */ 	slti	$at,$t9,-39
/*  f0c86e8:	14200003 */ 	bnez	$at,.NB0f0c86f8
/*  f0c86ec:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c86f0:	aca0010c */ 	sw	$zero,0x10c($a1)
/*  f0c86f4:	8e450284 */ 	lw	$a1,0x284($s2)
.NB0f0c86f8:
/*  f0c86f8:	10800064 */ 	beqz	$a0,.NB0f0c888c
/*  f0c86fc:	c7a401ec */ 	lwc1	$f4,0x1ec($sp)
/*  f0c8700:	44809000 */ 	mtc1	$zero,$f18
/*  f0c8704:	c7a601f0 */ 	lwc1	$f6,0x1f0($sp)
/*  f0c8708:	4604903c */ 	c.lt.s	$f18,$f4
/*  f0c870c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c8710:	45030008 */ 	bc1tl	.NB0f0c8734
/*  f0c8714:	aca00100 */ 	sw	$zero,0x100($a1)
/*  f0c8718:	44805000 */ 	mtc1	$zero,$f10
/*  f0c871c:	8fab023c */ 	lw	$t3,0x23c($sp)
/*  f0c8720:	4606503c */ 	c.lt.s	$f10,$f6
/*  f0c8724:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c8728:	45000009 */ 	bc1f	.NB0f0c8750
/*  f0c872c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c8730:	aca00100 */ 	sw	$zero,0x100($a1)
.NB0f0c8734:
/*  f0c8734:	8e490284 */ 	lw	$t1,0x284($s2)
/*  f0c8738:	24080001 */ 	addiu	$t0,$zero,0x1
/*  f0c873c:	ad280108 */ 	sw	$t0,0x108($t1)
/*  f0c8740:	8e4a0284 */ 	lw	$t2,0x284($s2)
/*  f0c8744:	ad40011c */ 	sw	$zero,0x11c($t2)
/*  f0c8748:	10000050 */ 	beqz	$zero,.NB0f0c888c
/*  f0c874c:	8e450284 */ 	lw	$a1,0x284($s2)
.NB0f0c8750:
/*  f0c8750:	51600005 */ 	beqzl	$t3,.NB0f0c8768
/*  f0c8754:	8cac0114 */ 	lw	$t4,0x114($a1)
/*  f0c8758:	aca0011c */ 	sw	$zero,0x11c($a1)
/*  f0c875c:	10000049 */ 	beqz	$zero,.NB0f0c8884
/*  f0c8760:	8e450284 */ 	lw	$a1,0x284($s2)
/*  f0c8764:	8cac0114 */ 	lw	$t4,0x114($a1)
.NB0f0c8768:
/*  f0c8768:	8fad01c4 */ 	lw	$t5,0x1c4($sp)
/*  f0c876c:	51800026 */ 	beqzl	$t4,.NB0f0c8808
/*  f0c8770:	8ca90118 */ 	lw	$t1,0x118($a1)
/*  f0c8774:	11a00009 */ 	beqz	$t5,.NB0f0c879c
/*  f0c8778:	8fae025c */ 	lw	$t6,0x25c($sp)
/*  f0c877c:	29c1003d */ 	slti	$at,$t6,0x3d
/*  f0c8780:	10200004 */ 	beqz	$at,.NB0f0c8794
/*  f0c8784:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f0c8788:	29c1ffc4 */ 	slti	$at,$t6,-60
/*  f0c878c:	50200004 */ 	beqzl	$at,.NB0f0c87a0
/*  f0c8790:	8cb8011c */ 	lw	$t8,0x11c($a1)
.NB0f0c8794:
/*  f0c8794:	acaf011c */ 	sw	$t7,0x11c($a1)
/*  f0c8798:	8e450284 */ 	lw	$a1,0x284($s2)
.NB0f0c879c:
/*  f0c879c:	8cb8011c */ 	lw	$t8,0x11c($a1)
.NB0f0c87a0:
/*  f0c87a0:	3c0140a0 */ 	lui	$at,0x40a0
/*  f0c87a4:	53000038 */ 	beqzl	$t8,.NB0f0c8888
/*  f0c87a8:	aca00108 */ 	sw	$zero,0x108($a1)
/*  f0c87ac:	44814000 */ 	mtc1	$at,$f8
/*  f0c87b0:	c4a00154 */ 	lwc1	$f0,0x154($a1)
/*  f0c87b4:	3c01c120 */ 	lui	$at,0xc120
/*  f0c87b8:	46087400 */ 	add.s	$f16,$f14,$f8
/*  f0c87bc:	4600803c */ 	c.lt.s	$f16,$f0
/*  f0c87c0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c87c4:	45030009 */ 	bc1tl	.NB0f0c87ec
/*  f0c87c8:	8cb9010c */ 	lw	$t9,0x10c($a1)
/*  f0c87cc:	44819000 */ 	mtc1	$at,$f18
/*  f0c87d0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c87d4:	46127100 */ 	add.s	$f4,$f14,$f18
/*  f0c87d8:	4604003c */ 	c.lt.s	$f0,$f4
/*  f0c87dc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c87e0:	45020029 */ 	bc1fl	.NB0f0c8888
/*  f0c87e4:	aca00108 */ 	sw	$zero,0x108($a1)
/*  f0c87e8:	8cb9010c */ 	lw	$t9,0x10c($a1)
.NB0f0c87ec:
/*  f0c87ec:	24080001 */ 	addiu	$t0,$zero,0x1
/*  f0c87f0:	57200025 */ 	bnezl	$t9,.NB0f0c8888
/*  f0c87f4:	aca00108 */ 	sw	$zero,0x108($a1)
/*  f0c87f8:	aca80100 */ 	sw	$t0,0x100($a1)
/*  f0c87fc:	10000021 */ 	beqz	$zero,.NB0f0c8884
/*  f0c8800:	8e450284 */ 	lw	$a1,0x284($s2)
/*  f0c8804:	8ca90118 */ 	lw	$t1,0x118($a1)
.NB0f0c8808:
/*  f0c8808:	8faa01c4 */ 	lw	$t2,0x1c4($sp)
/*  f0c880c:	5120001e */ 	beqzl	$t1,.NB0f0c8888
/*  f0c8810:	aca00108 */ 	sw	$zero,0x108($a1)
/*  f0c8814:	1140001b */ 	beqz	$t2,.NB0f0c8884
/*  f0c8818:	8fab025c */ 	lw	$t3,0x25c($sp)
/*  f0c881c:	2961003d */ 	slti	$at,$t3,0x3d
/*  f0c8820:	10200002 */ 	beqz	$at,.NB0f0c882c
/*  f0c8824:	2961ffc4 */ 	slti	$at,$t3,-60
/*  f0c8828:	10200016 */ 	beqz	$at,.NB0f0c8884
.NB0f0c882c:
/*  f0c882c:	3c0140a0 */ 	lui	$at,0x40a0
/*  f0c8830:	44815000 */ 	mtc1	$at,$f10
/*  f0c8834:	c4a00154 */ 	lwc1	$f0,0x154($a1)
/*  f0c8838:	3c01c120 */ 	lui	$at,0xc120
/*  f0c883c:	460a7180 */ 	add.s	$f6,$f14,$f10
/*  f0c8840:	4600303c */ 	c.lt.s	$f6,$f0
/*  f0c8844:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c8848:	45030009 */ 	bc1tl	.NB0f0c8870
/*  f0c884c:	8cac010c */ 	lw	$t4,0x10c($a1)
/*  f0c8850:	44814000 */ 	mtc1	$at,$f8
/*  f0c8854:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c8858:	46087400 */ 	add.s	$f16,$f14,$f8
/*  f0c885c:	4610003c */ 	c.lt.s	$f0,$f16
/*  f0c8860:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c8864:	45020008 */ 	bc1fl	.NB0f0c8888
/*  f0c8868:	aca00108 */ 	sw	$zero,0x108($a1)
/*  f0c886c:	8cac010c */ 	lw	$t4,0x10c($a1)
.NB0f0c8870:
/*  f0c8870:	240d0001 */ 	addiu	$t5,$zero,0x1
/*  f0c8874:	55800004 */ 	bnezl	$t4,.NB0f0c8888
/*  f0c8878:	aca00108 */ 	sw	$zero,0x108($a1)
/*  f0c887c:	acad0100 */ 	sw	$t5,0x100($a1)
/*  f0c8880:	8e450284 */ 	lw	$a1,0x284($s2)
.NB0f0c8884:
/*  f0c8884:	aca00108 */ 	sw	$zero,0x108($a1)
.NB0f0c8888:
/*  f0c8888:	8e450284 */ 	lw	$a1,0x284($s2)
.NB0f0c888c:
/*  f0c888c:	8cae0100 */ 	lw	$t6,0x100($a1)
/*  f0c8890:	8fb901d0 */ 	lw	$t9,0x1d0($sp)
/*  f0c8894:	11c0004a */ 	beqz	$t6,.NB0f0c89c0
/*  f0c8898:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c889c:	508000af */ 	beqzl	$a0,.NB0f0c8b5c
/*  f0c88a0:	8fa801cc */ 	lw	$t0,0x1cc($sp)
/*  f0c88a4:	c4a2015c */ 	lwc1	$f2,0x15c($a1)
/*  f0c88a8:	3c013f00 */ 	lui	$at,0x3f00
/*  f0c88ac:	44812000 */ 	mtc1	$at,$f4
/*  f0c88b0:	46021482 */ 	mul.s	$f18,$f2,$f2
/*  f0c88b4:	3c017f1a */ 	lui	$at,0x7f1a
/*  f0c88b8:	c4267c00 */ 	lwc1	$f6,0x7c00($at)
/*  f0c88bc:	c4a00154 */ 	lwc1	$f0,0x154($a1)
/*  f0c88c0:	3c013f80 */ 	lui	$at,0x3f80
/*  f0c88c4:	46049282 */ 	mul.s	$f10,$f18,$f4
/*  f0c88c8:	46065303 */ 	div.s	$f12,$f10,$f6
/*  f0c88cc:	460c7200 */ 	add.s	$f8,$f14,$f12
/*  f0c88d0:	4600403c */ 	c.lt.s	$f8,$f0
/*  f0c88d4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c88d8:	45020007 */ 	bc1fl	.NB0f0c88f8
/*  f0c88dc:	460c7401 */ 	sub.s	$f16,$f14,$f12
/*  f0c88e0:	44816000 */ 	mtc1	$at,$f12
/*  f0c88e4:	0fc31656 */ 	jal	bmoveUpdateSpeedVerta
/*  f0c88e8:	e7ae0094 */ 	swc1	$f14,0x94($sp)
/*  f0c88ec:	10000010 */ 	beqz	$zero,.NB0f0c8930
/*  f0c88f0:	c7ae0094 */ 	lwc1	$f14,0x94($sp)
/*  f0c88f4:	460c7401 */ 	sub.s	$f16,$f14,$f12
.NB0f0c88f8:
/*  f0c88f8:	3c01bf80 */ 	lui	$at,0xbf80
/*  f0c88fc:	4610003c */ 	c.lt.s	$f0,$f16
/*  f0c8900:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c8904:	45020007 */ 	bc1fl	.NB0f0c8924
/*  f0c8908:	44806000 */ 	mtc1	$zero,$f12
/*  f0c890c:	44816000 */ 	mtc1	$at,$f12
/*  f0c8910:	0fc31656 */ 	jal	bmoveUpdateSpeedVerta
/*  f0c8914:	e7ae0094 */ 	swc1	$f14,0x94($sp)
/*  f0c8918:	10000005 */ 	beqz	$zero,.NB0f0c8930
/*  f0c891c:	c7ae0094 */ 	lwc1	$f14,0x94($sp)
/*  f0c8920:	44806000 */ 	mtc1	$zero,$f12
.NB0f0c8924:
/*  f0c8924:	0fc31656 */ 	jal	bmoveUpdateSpeedVerta
/*  f0c8928:	e7ae0094 */ 	swc1	$f14,0x94($sp)
/*  f0c892c:	c7ae0094 */ 	lwc1	$f14,0x94($sp)
.NB0f0c8930:
/*  f0c8930:	8e450284 */ 	lw	$a1,0x284($s2)
/*  f0c8934:	c644004c */ 	lwc1	$f4,0x4c($s2)
/*  f0c8938:	c4b2015c */ 	lwc1	$f18,0x15c($a1)
/*  f0c893c:	c4a00154 */ 	lwc1	$f0,0x154($a1)
/*  f0c8940:	46049082 */ 	mul.s	$f2,$f18,$f4
/*  f0c8944:	4600703c */ 	c.lt.s	$f14,$f0
/*  f0c8948:	46021280 */ 	add.s	$f10,$f2,$f2
/*  f0c894c:	45000007 */ 	bc1f	.NB0f0c896c
/*  f0c8950:	460a0300 */ 	add.s	$f12,$f0,$f10
/*  f0c8954:	460c703c */ 	c.lt.s	$f14,$f12
/*  f0c8958:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c895c:	45020004 */ 	bc1fl	.NB0f0c8970
/*  f0c8960:	460e003c */ 	c.lt.s	$f0,$f14
/*  f0c8964:	1000007c */ 	beqz	$zero,.NB0f0c8b58
/*  f0c8968:	e4ac0154 */ 	swc1	$f12,0x154($a1)
.NB0f0c896c:
/*  f0c896c:	460e003c */ 	c.lt.s	$f0,$f14
.NB0f0c8970:
/*  f0c8970:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c8974:	45020008 */ 	bc1fl	.NB0f0c8998
/*  f0c8978:	e4ae0154 */ 	swc1	$f14,0x154($a1)
/*  f0c897c:	460e603c */ 	c.lt.s	$f12,$f14
/*  f0c8980:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c8984:	45020004 */ 	bc1fl	.NB0f0c8998
/*  f0c8988:	e4ae0154 */ 	swc1	$f14,0x154($a1)
/*  f0c898c:	10000072 */ 	beqz	$zero,.NB0f0c8b58
/*  f0c8990:	e4ac0154 */ 	swc1	$f12,0x154($a1)
/*  f0c8994:	e4ae0154 */ 	swc1	$f14,0x154($a1)
.NB0f0c8998:
/*  f0c8998:	8e4f0284 */ 	lw	$t7,0x284($s2)
/*  f0c899c:	44803000 */ 	mtc1	$zero,$f6
/*  f0c89a0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c89a4:	e5e6015c */ 	swc1	$f6,0x15c($t7)
/*  f0c89a8:	8e450284 */ 	lw	$a1,0x284($s2)
/*  f0c89ac:	8cb80108 */ 	lw	$t8,0x108($a1)
/*  f0c89b0:	5700006a */ 	bnezl	$t8,.NB0f0c8b5c
/*  f0c89b4:	8fa801cc */ 	lw	$t0,0x1cc($sp)
/*  f0c89b8:	10000067 */ 	beqz	$zero,.NB0f0c8b58
/*  f0c89bc:	aca00100 */ 	sw	$zero,0x100($a1)
.NB0f0c89c0:
/*  f0c89c0:	1320002f */ 	beqz	$t9,.NB0f0c8a80
/*  f0c89c4:	c7a601ec */ 	lwc1	$f6,0x1ec($sp)
/*  f0c89c8:	0c003012 */ 	jal	viGetFovY
/*  f0c89cc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c89d0:	8fa80254 */ 	lw	$t0,0x254($sp)
/*  f0c89d4:	3c014270 */ 	lui	$at,0x4270
/*  f0c89d8:	44814000 */ 	mtc1	$at,$f8
/*  f0c89dc:	44888000 */ 	mtc1	$t0,$f16
/*  f0c89e0:	3c01428c */ 	lui	$at,0x428c
/*  f0c89e4:	44812000 */ 	mtc1	$at,$f4
/*  f0c89e8:	468084a0 */ 	cvt.s.w	$f18,$f16
/*  f0c89ec:	3c013f80 */ 	lui	$at,0x3f80
/*  f0c89f0:	44815000 */ 	mtc1	$at,$f10
/*  f0c89f4:	3c01bf80 */ 	lui	$at,0xbf80
/*  f0c89f8:	46080383 */ 	div.s	$f14,$f0,$f8
/*  f0c89fc:	44804000 */ 	mtc1	$zero,$f8
/*  f0c8a00:	46049303 */ 	div.s	$f12,$f18,$f4
/*  f0c8a04:	460c503c */ 	c.lt.s	$f10,$f12
/*  f0c8a08:	46006086 */ 	mov.s	$f2,$f12
/*  f0c8a0c:	45020006 */ 	bc1fl	.NB0f0c8a28
/*  f0c8a10:	44813000 */ 	mtc1	$at,$f6
/*  f0c8a14:	3c013f80 */ 	lui	$at,0x3f80
/*  f0c8a18:	44811000 */ 	mtc1	$at,$f2
/*  f0c8a1c:	1000000a */ 	beqz	$zero,.NB0f0c8a48
/*  f0c8a20:	4602403e */ 	c.le.s	$f8,$f2
/*  f0c8a24:	44813000 */ 	mtc1	$at,$f6
.NB0f0c8a28:
/*  f0c8a28:	3c01bf80 */ 	lui	$at,0xbf80
/*  f0c8a2c:	4606603c */ 	c.lt.s	$f12,$f6
/*  f0c8a30:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c8a34:	45020004 */ 	bc1fl	.NB0f0c8a48
/*  f0c8a38:	4602403e */ 	c.le.s	$f8,$f2
/*  f0c8a3c:	44811000 */ 	mtc1	$at,$f2
/*  f0c8a40:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c8a44:	4602403e */ 	c.le.s	$f8,$f2
.NB0f0c8a48:
/*  f0c8a48:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c8a4c:	45020005 */ 	bc1fl	.NB0f0c8a64
/*  f0c8a50:	46001407 */ 	neg.s	$f16,$f2
/*  f0c8a54:	46021082 */ 	mul.s	$f2,$f2,$f2
/*  f0c8a58:	10000005 */ 	beqz	$zero,.NB0f0c8a70
/*  f0c8a5c:	46001487 */ 	neg.s	$f18,$f2
/*  f0c8a60:	46001407 */ 	neg.s	$f16,$f2
.NB0f0c8a64:
/*  f0c8a64:	46101082 */ 	mul.s	$f2,$f2,$f16
/*  f0c8a68:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c8a6c:	46001487 */ 	neg.s	$f18,$f2
.NB0f0c8a70:
/*  f0c8a70:	8e490284 */ 	lw	$t1,0x284($s2)
/*  f0c8a74:	460e9102 */ 	mul.s	$f4,$f18,$f14
/*  f0c8a78:	1000002c */ 	beqz	$zero,.NB0f0c8b2c
/*  f0c8a7c:	e524015c */ 	swc1	$f4,0x15c($t1)
.NB0f0c8a80:
/*  f0c8a80:	44805000 */ 	mtc1	$zero,$f10
/*  f0c8a84:	c7b001f0 */ 	lwc1	$f16,0x1f0($sp)
/*  f0c8a88:	4606503c */ 	c.lt.s	$f10,$f6
/*  f0c8a8c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c8a90:	45020010 */ 	bc1fl	.NB0f0c8ad4
/*  f0c8a94:	44804000 */ 	mtc1	$zero,$f8
/*  f0c8a98:	0fc31656 */ 	jal	bmoveUpdateSpeedVerta
/*  f0c8a9c:	46003306 */ 	mov.s	$f12,$f6
/*  f0c8aa0:	8faa01c4 */ 	lw	$t2,0x1c4($sp)
/*  f0c8aa4:	8fab025c */ 	lw	$t3,0x25c($sp)
/*  f0c8aa8:	11400020 */ 	beqz	$t2,.NB0f0c8b2c
/*  f0c8aac:	2961003d */ 	slti	$at,$t3,0x3d
/*  f0c8ab0:	10200003 */ 	beqz	$at,.NB0f0c8ac0
/*  f0c8ab4:	2961ffc4 */ 	slti	$at,$t3,-60
/*  f0c8ab8:	5020001d */ 	beqzl	$at,.NB0f0c8b30
/*  f0c8abc:	8e450284 */ 	lw	$a1,0x284($s2)
.NB0f0c8ac0:
/*  f0c8ac0:	8e4d0284 */ 	lw	$t5,0x284($s2)
/*  f0c8ac4:	240c0001 */ 	addiu	$t4,$zero,0x1
/*  f0c8ac8:	10000018 */ 	beqz	$zero,.NB0f0c8b2c
/*  f0c8acc:	adac010c */ 	sw	$t4,0x10c($t5)
/*  f0c8ad0:	44804000 */ 	mtc1	$zero,$f8
.NB0f0c8ad4:
/*  f0c8ad4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c8ad8:	4610403c */ 	c.lt.s	$f8,$f16
/*  f0c8adc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c8ae0:	45020010 */ 	bc1fl	.NB0f0c8b24
/*  f0c8ae4:	44806000 */ 	mtc1	$zero,$f12
/*  f0c8ae8:	0fc31656 */ 	jal	bmoveUpdateSpeedVerta
/*  f0c8aec:	46008307 */ 	neg.s	$f12,$f16
/*  f0c8af0:	8fae01c4 */ 	lw	$t6,0x1c4($sp)
/*  f0c8af4:	8faf025c */ 	lw	$t7,0x25c($sp)
/*  f0c8af8:	11c0000c */ 	beqz	$t6,.NB0f0c8b2c
/*  f0c8afc:	29e1003d */ 	slti	$at,$t7,0x3d
/*  f0c8b00:	10200003 */ 	beqz	$at,.NB0f0c8b10
/*  f0c8b04:	29e1ffc4 */ 	slti	$at,$t7,-60
/*  f0c8b08:	50200009 */ 	beqzl	$at,.NB0f0c8b30
/*  f0c8b0c:	8e450284 */ 	lw	$a1,0x284($s2)
.NB0f0c8b10:
/*  f0c8b10:	8e590284 */ 	lw	$t9,0x284($s2)
/*  f0c8b14:	24180001 */ 	addiu	$t8,$zero,0x1
/*  f0c8b18:	10000004 */ 	beqz	$zero,.NB0f0c8b2c
/*  f0c8b1c:	af38010c */ 	sw	$t8,0x10c($t9)
/*  f0c8b20:	44806000 */ 	mtc1	$zero,$f12
.NB0f0c8b24:
/*  f0c8b24:	0fc31656 */ 	jal	bmoveUpdateSpeedVerta
/*  f0c8b28:	00000000 */ 	sll	$zero,$zero,0x0
.NB0f0c8b2c:
/*  f0c8b2c:	8e450284 */ 	lw	$a1,0x284($s2)
.NB0f0c8b30:
/*  f0c8b30:	c644004c */ 	lwc1	$f4,0x4c($s2)
/*  f0c8b34:	3c014060 */ 	lui	$at,0x4060
/*  f0c8b38:	c4b2015c */ 	lwc1	$f18,0x15c($a1)
/*  f0c8b3c:	44813000 */ 	mtc1	$at,$f6
/*  f0c8b40:	c4b00154 */ 	lwc1	$f16,0x154($a1)
/*  f0c8b44:	46049282 */ 	mul.s	$f10,$f18,$f4
/*  f0c8b48:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c8b4c:	46065202 */ 	mul.s	$f8,$f10,$f6
/*  f0c8b50:	46088480 */ 	add.s	$f18,$f16,$f8
/*  f0c8b54:	e4b20154 */ 	swc1	$f18,0x154($a1)
.NB0f0c8b58:
/*  f0c8b58:	8fa801cc */ 	lw	$t0,0x1cc($sp)
.NB0f0c8b5c:
/*  f0c8b5c:	c7ac01f4 */ 	lwc1	$f12,0x1f4($sp)
/*  f0c8b60:	5100002d */ 	beqzl	$t0,.NB0f0c8c18
/*  f0c8b64:	44804000 */ 	mtc1	$zero,$f8
/*  f0c8b68:	0c003012 */ 	jal	viGetFovY
/*  f0c8b6c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c8b70:	8fa90250 */ 	lw	$t1,0x250($sp)
/*  f0c8b74:	3c01428c */ 	lui	$at,0x428c
/*  f0c8b78:	44813000 */ 	mtc1	$at,$f6
/*  f0c8b7c:	44892000 */ 	mtc1	$t1,$f4
/*  f0c8b80:	3c013f80 */ 	lui	$at,0x3f80
/*  f0c8b84:	44818000 */ 	mtc1	$at,$f16
/*  f0c8b88:	468022a0 */ 	cvt.s.w	$f10,$f4
/*  f0c8b8c:	44809000 */ 	mtc1	$zero,$f18
/*  f0c8b90:	3c01bf80 */ 	lui	$at,0xbf80
/*  f0c8b94:	46065303 */ 	div.s	$f12,$f10,$f6
/*  f0c8b98:	460c803c */ 	c.lt.s	$f16,$f12
/*  f0c8b9c:	46006086 */ 	mov.s	$f2,$f12
/*  f0c8ba0:	45020006 */ 	bc1fl	.NB0f0c8bbc
/*  f0c8ba4:	44814000 */ 	mtc1	$at,$f8
/*  f0c8ba8:	3c013f80 */ 	lui	$at,0x3f80
/*  f0c8bac:	44811000 */ 	mtc1	$at,$f2
/*  f0c8bb0:	1000000a */ 	beqz	$zero,.NB0f0c8bdc
/*  f0c8bb4:	4602903e */ 	c.le.s	$f18,$f2
/*  f0c8bb8:	44814000 */ 	mtc1	$at,$f8
.NB0f0c8bbc:
/*  f0c8bbc:	3c01bf80 */ 	lui	$at,0xbf80
/*  f0c8bc0:	4608603c */ 	c.lt.s	$f12,$f8
/*  f0c8bc4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c8bc8:	45020004 */ 	bc1fl	.NB0f0c8bdc
/*  f0c8bcc:	4602903e */ 	c.le.s	$f18,$f2
/*  f0c8bd0:	44811000 */ 	mtc1	$at,$f2
/*  f0c8bd4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c8bd8:	4602903e */ 	c.le.s	$f18,$f2
.NB0f0c8bdc:
/*  f0c8bdc:	3c014270 */ 	lui	$at,0x4270
/*  f0c8be0:	44815000 */ 	mtc1	$at,$f10
/*  f0c8be4:	45000004 */ 	bc1f	.NB0f0c8bf8
/*  f0c8be8:	460a0183 */ 	div.s	$f6,$f0,$f10
/*  f0c8bec:	46021082 */ 	mul.s	$f2,$f2,$f2
/*  f0c8bf0:	10000004 */ 	beqz	$zero,.NB0f0c8c04
/*  f0c8bf4:	00000000 */ 	sll	$zero,$zero,0x0
.NB0f0c8bf8:
/*  f0c8bf8:	46001107 */ 	neg.s	$f4,$f2
/*  f0c8bfc:	46041082 */ 	mul.s	$f2,$f2,$f4
/*  f0c8c00:	00000000 */ 	sll	$zero,$zero,0x0
.NB0f0c8c04:
/*  f0c8c04:	46061402 */ 	mul.s	$f16,$f2,$f6
/*  f0c8c08:	8e4a0284 */ 	lw	$t2,0x284($s2)
/*  f0c8c0c:	10000019 */ 	beqz	$zero,.NB0f0c8c74
/*  f0c8c10:	e5501b9c */ 	swc1	$f16,0x1b9c($t2)
/*  f0c8c14:	44804000 */ 	mtc1	$zero,$f8
.NB0f0c8c18:
/*  f0c8c18:	c7a001f8 */ 	lwc1	$f0,0x1f8($sp)
/*  f0c8c1c:	460c403c */ 	c.lt.s	$f8,$f12
/*  f0c8c20:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c8c24:	45020006 */ 	bc1fl	.NB0f0c8c40
/*  f0c8c28:	44809000 */ 	mtc1	$zero,$f18
/*  f0c8c2c:	0fc316fd */ 	jal	bmoveUpdateSpeedThetaControl
/*  f0c8c30:	e7ac01f4 */ 	swc1	$f12,0x1f4($sp)
/*  f0c8c34:	10000010 */ 	beqz	$zero,.NB0f0c8c78
/*  f0c8c38:	8e450284 */ 	lw	$a1,0x284($s2)
/*  f0c8c3c:	44809000 */ 	mtc1	$zero,$f18
.NB0f0c8c40:
/*  f0c8c40:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c8c44:	4600903c */ 	c.lt.s	$f18,$f0
/*  f0c8c48:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c8c4c:	45020007 */ 	bc1fl	.NB0f0c8c6c
/*  f0c8c50:	44806000 */ 	mtc1	$zero,$f12
/*  f0c8c54:	46000307 */ 	neg.s	$f12,$f0
/*  f0c8c58:	0fc316fd */ 	jal	bmoveUpdateSpeedThetaControl
/*  f0c8c5c:	e7a001f8 */ 	swc1	$f0,0x1f8($sp)
/*  f0c8c60:	10000005 */ 	beqz	$zero,.NB0f0c8c78
/*  f0c8c64:	8e450284 */ 	lw	$a1,0x284($s2)
/*  f0c8c68:	44806000 */ 	mtc1	$zero,$f12
.NB0f0c8c6c:
/*  f0c8c6c:	0fc316fd */ 	jal	bmoveUpdateSpeedThetaControl
/*  f0c8c70:	00000000 */ 	sll	$zero,$zero,0x0
.NB0f0c8c74:
/*  f0c8c74:	8e450284 */ 	lw	$a1,0x284($s2)
.NB0f0c8c78:
/*  f0c8c78:	c4a41b9c */ 	lwc1	$f4,0x1b9c($a1)
/*  f0c8c7c:	0fc31619 */ 	jal	bmoveUpdateSpeedTheta
/*  f0c8c80:	e4a40148 */ 	swc1	$f4,0x148($a1)
/*  f0c8c84:	8fab0228 */ 	lw	$t3,0x228($sp)
/*  f0c8c88:	51600008 */ 	beqzl	$t3,.NB0f0c8cac
/*  f0c8c8c:	8e4e02ac */ 	lw	$t6,0x2ac($s2)
/*  f0c8c90:	8e4c0284 */ 	lw	$t4,0x284($s2)
/*  f0c8c94:	ad800658 */ 	sw	$zero,0x658($t4)
/*  f0c8c98:	8e4d0284 */ 	lw	$t5,0x284($s2)
/*  f0c8c9c:	ada0065c */ 	sw	$zero,0x65c($t5)
/*  f0c8ca0:	0fc2248f */ 	jal	playerActivateRemoteMineDetonator
/*  f0c8ca4:	8e44028c */ 	lw	$a0,0x28c($s2)
/*  f0c8ca8:	8e4e02ac */ 	lw	$t6,0x2ac($s2)
.NB0f0c8cac:
/*  f0c8cac:	24010006 */ 	addiu	$at,$zero,0x6
/*  f0c8cb0:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f0c8cb4:	55c10003 */ 	bnel	$t6,$at,.NB0f0c8cc4
/*  f0c8cb8:	8e4f000c */ 	lw	$t7,0xc($s2)
/*  f0c8cbc:	00001025 */ 	or	$v0,$zero,$zero
/*  f0c8cc0:	8e4f000c */ 	lw	$t7,0xc($s2)
.NB0f0c8cc4:
/*  f0c8cc4:	29e1000a */ 	slti	$at,$t7,0xa
/*  f0c8cc8:	10200002 */ 	beqz	$at,.NB0f0c8cd4
/*  f0c8ccc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c8cd0:	00001025 */ 	or	$v0,$zero,$zero
.NB0f0c8cd4:
/*  f0c8cd4:	5040001a */ 	beqzl	$v0,.NB0f0c8d40
/*  f0c8cd8:	8e450284 */ 	lw	$a1,0x284($s2)
/*  f0c8cdc:	8fa201fc */ 	lw	$v0,0x1fc($sp)
/*  f0c8ce0:	0002202a */ 	slt	$a0,$zero,$v0
/*  f0c8ce4:	2442ffff */ 	addiu	$v0,$v0,-1
/*  f0c8ce8:	10800008 */ 	beqz	$a0,.NB0f0c8d0c
/*  f0c8cec:	afa201fc */ 	sw	$v0,0x1fc($sp)
.NB0f0c8cf0:
/*  f0c8cf0:	0fc27e6a */ 	jal	bgun0f0a1c2c
/*  f0c8cf4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c8cf8:	8fa201fc */ 	lw	$v0,0x1fc($sp)
/*  f0c8cfc:	0002202a */ 	slt	$a0,$zero,$v0
/*  f0c8d00:	2442ffff */ 	addiu	$v0,$v0,-1
/*  f0c8d04:	1480fffa */ 	bnez	$a0,.NB0f0c8cf0
/*  f0c8d08:	afa201fc */ 	sw	$v0,0x1fc($sp)
.NB0f0c8d0c:
/*  f0c8d0c:	8fa20200 */ 	lw	$v0,0x200($sp)
/*  f0c8d10:	0002202a */ 	slt	$a0,$zero,$v0
/*  f0c8d14:	2442ffff */ 	addiu	$v0,$v0,-1
/*  f0c8d18:	10800008 */ 	beqz	$a0,.NB0f0c8d3c
/*  f0c8d1c:	afa20200 */ 	sw	$v0,0x200($sp)
.NB0f0c8d20:
/*  f0c8d20:	0fc27e33 */ 	jal	bgun0f0a1b50
/*  f0c8d24:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c8d28:	8fa20200 */ 	lw	$v0,0x200($sp)
/*  f0c8d2c:	0002202a */ 	slt	$a0,$zero,$v0
/*  f0c8d30:	2442ffff */ 	addiu	$v0,$v0,-1
/*  f0c8d34:	1480fffa */ 	bnez	$a0,.NB0f0c8d20
/*  f0c8d38:	afa20200 */ 	sw	$v0,0x200($sp)
.NB0f0c8d3c:
/*  f0c8d3c:	8e450284 */ 	lw	$a1,0x284($s2)
.NB0f0c8d40:
/*  f0c8d40:	8fb901b4 */ 	lw	$t9,0x1b4($sp)
/*  f0c8d44:	8cb81c64 */ 	lw	$t8,0x1c64($a1)
/*  f0c8d48:	13000003 */ 	beqz	$t8,.NB0f0c8d58
/*  f0c8d4c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c8d50:	10000093 */ 	beqz	$zero,.NB0f0c8fa0
/*  f0c8d54:	aca01c64 */ 	sw	$zero,0x1c64($a1)
.NB0f0c8d58:
/*  f0c8d58:	1320007d */ 	beqz	$t9,.NB0f0c8f50
/*  f0c8d5c:	8faf01b8 */ 	lw	$t7,0x1b8($sp)
/*  f0c8d60:	0fc29c5c */ 	jal	bgunSetAimType
/*  f0c8d64:	00002025 */ 	or	$a0,$zero,$zero
/*  f0c8d68:	8fa8022c */ 	lw	$t0,0x22c($sp)
/*  f0c8d6c:	11000015 */ 	beqz	$t0,.NB0f0c8dc4
/*  f0c8d70:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c8d74:	0fc3150c */ 	jal	bmoveIsAutoAimXEnabledForCurrentWeapon
/*  f0c8d78:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c8d7c:	54400006 */ 	bnezl	$v0,.NB0f0c8d98
/*  f0c8d80:	8e450284 */ 	lw	$a1,0x284($s2)
/*  f0c8d84:	0fc314bb */ 	jal	bmoveIsAutoAimYEnabledForCurrentWeapon
/*  f0c8d88:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c8d8c:	1040000d */ 	beqz	$v0,.NB0f0c8dc4
/*  f0c8d90:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c8d94:	8e450284 */ 	lw	$a1,0x284($s2)
.NB0f0c8d98:
/*  f0c8d98:	8ca9013c */ 	lw	$t1,0x13c($a1)
/*  f0c8d9c:	11200009 */ 	beqz	$t1,.NB0f0c8dc4
/*  f0c8da0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c8da4:	8caa012c */ 	lw	$t2,0x12c($a1)
/*  f0c8da8:	8fa401ac */ 	lw	$a0,0x1ac($sp)
/*  f0c8dac:	11400005 */ 	beqz	$t2,.NB0f0c8dc4
/*  f0c8db0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c8db4:	0fc2bd59 */ 	jal	weaponHasClassFlag
/*  f0c8db8:	24050002 */ 	addiu	$a1,$zero,0x2
/*  f0c8dbc:	5440000b */ 	bnezl	$v0,.NB0f0c8dec
/*  f0c8dc0:	00008025 */ 	or	$s0,$zero,$zero
.NB0f0c8dc4:
/*  f0c8dc4:	0fc27dd7 */ 	jal	bgunGetWeaponNum
/*  f0c8dc8:	00002025 */ 	or	$a0,$zero,$zero
/*  f0c8dcc:	2401000a */ 	addiu	$at,$zero,0xa
/*  f0c8dd0:	54410037 */ 	bnel	$v0,$at,.NB0f0c8eb0
/*  f0c8dd4:	8e450284 */ 	lw	$a1,0x284($s2)
/*  f0c8dd8:	8e4b0284 */ 	lw	$t3,0x284($s2)
/*  f0c8ddc:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0c8de0:	916c063b */ 	lbu	$t4,0x63b($t3)
/*  f0c8de4:	15810031 */ 	bne	$t4,$at,.NB0f0c8eac
/*  f0c8de8:	00008025 */ 	or	$s0,$zero,$zero
.NB0f0c8dec:
/*  f0c8dec:	0fc27dd7 */ 	jal	bgunGetWeaponNum
/*  f0c8df0:	00002025 */ 	or	$a0,$zero,$zero
/*  f0c8df4:	2401000a */ 	addiu	$at,$zero,0xa
/*  f0c8df8:	54410008 */ 	bnel	$v0,$at,.NB0f0c8e1c
/*  f0c8dfc:	8e450284 */ 	lw	$a1,0x284($s2)
/*  f0c8e00:	8e4d0284 */ 	lw	$t5,0x284($s2)
/*  f0c8e04:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0c8e08:	91ae063b */ 	lbu	$t6,0x63b($t5)
/*  f0c8e0c:	55c10003 */ 	bnel	$t6,$at,.NB0f0c8e1c
/*  f0c8e10:	8e450284 */ 	lw	$a1,0x284($s2)
/*  f0c8e14:	24100001 */ 	addiu	$s0,$zero,0x1
/*  f0c8e18:	8e450284 */ 	lw	$a1,0x284($s2)
.NB0f0c8e1c:
/*  f0c8e1c:	3c017f1a */ 	lui	$at,0x7f1a
/*  f0c8e20:	c4227c04 */ 	lwc1	$f2,0x7c04($at)
/*  f0c8e24:	c4a01b68 */ 	lwc1	$f0,0x1b68($a1)
/*  f0c8e28:	3c017f1a */ 	lui	$at,0x7f1a
/*  f0c8e2c:	4600103c */ 	c.lt.s	$f2,$f0
/*  f0c8e30:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c8e34:	45020009 */ 	bc1fl	.NB0f0c8e5c
/*  f0c8e38:	4602003c */ 	c.lt.s	$f0,$f2
/*  f0c8e3c:	c42a7c08 */ 	lwc1	$f10,0x7c08($at)
/*  f0c8e40:	c646004c */ 	lwc1	$f6,0x4c($s2)
/*  f0c8e44:	46065402 */ 	mul.s	$f16,$f10,$f6
/*  f0c8e48:	46100201 */ 	sub.s	$f8,$f0,$f16
/*  f0c8e4c:	e4a81b68 */ 	swc1	$f8,0x1b68($a1)
/*  f0c8e50:	8e450284 */ 	lw	$a1,0x284($s2)
/*  f0c8e54:	c4a01b68 */ 	lwc1	$f0,0x1b68($a1)
/*  f0c8e58:	4602003c */ 	c.lt.s	$f0,$f2
.NB0f0c8e5c:
/*  f0c8e5c:	3c017f1a */ 	lui	$at,0x7f1a
/*  f0c8e60:	45020005 */ 	bc1fl	.NB0f0c8e78
/*  f0c8e64:	c4ac0138 */ 	lwc1	$f12,0x138($a1)
/*  f0c8e68:	e4a21b68 */ 	swc1	$f2,0x1b68($a1)
/*  f0c8e6c:	3c05800a */ 	lui	$a1,0x800a
/*  f0c8e70:	8ca5e944 */ 	lw	$a1,-0x16bc($a1)
/*  f0c8e74:	c4ac0138 */ 	lwc1	$f12,0x138($a1)
.NB0f0c8e78:
/*  f0c8e78:	12000008 */ 	beqz	$s0,.NB0f0c8e9c
/*  f0c8e7c:	c4ae0128 */ 	lwc1	$f14,0x128($a1)
/*  f0c8e80:	c4207c0c */ 	lwc1	$f0,0x7c0c($at)
/*  f0c8e84:	44060000 */ 	mfc1	$a2,$f0
/*  f0c8e88:	44070000 */ 	mfc1	$a3,$f0
/*  f0c8e8c:	0fc27852 */ 	jal	bgun0f0a0394
/*  f0c8e90:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c8e94:	10000043 */ 	beqz	$zero,.NB0f0c8fa4
/*  f0c8e98:	8fbf0034 */ 	lw	$ra,0x34($sp)
.NB0f0c8e9c:
/*  f0c8e9c:	0fc27a39 */ 	jal	bgunSwivelTowards
/*  f0c8ea0:	8ca61b68 */ 	lw	$a2,0x1b68($a1)
/*  f0c8ea4:	1000003f */ 	beqz	$zero,.NB0f0c8fa4
/*  f0c8ea8:	8fbf0034 */ 	lw	$ra,0x34($sp)
.NB0f0c8eac:
/*  f0c8eac:	8e450284 */ 	lw	$a1,0x284($s2)
.NB0f0c8eb0:
/*  f0c8eb0:	3c017f1a */ 	lui	$at,0x7f1a
/*  f0c8eb4:	c4227c10 */ 	lwc1	$f2,0x7c10($at)
/*  f0c8eb8:	c4a01b68 */ 	lwc1	$f0,0x1b68($a1)
/*  f0c8ebc:	3c017f1a */ 	lui	$at,0x7f1a
/*  f0c8ec0:	4602003c */ 	c.lt.s	$f0,$f2
/*  f0c8ec4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c8ec8:	45020009 */ 	bc1fl	.NB0f0c8ef0
/*  f0c8ecc:	4600103c */ 	c.lt.s	$f2,$f0
/*  f0c8ed0:	c4327c14 */ 	lwc1	$f18,0x7c14($at)
/*  f0c8ed4:	c644004c */ 	lwc1	$f4,0x4c($s2)
/*  f0c8ed8:	46049282 */ 	mul.s	$f10,$f18,$f4
/*  f0c8edc:	460a0180 */ 	add.s	$f6,$f0,$f10
/*  f0c8ee0:	e4a61b68 */ 	swc1	$f6,0x1b68($a1)
/*  f0c8ee4:	8e450284 */ 	lw	$a1,0x284($s2)
/*  f0c8ee8:	c4a01b68 */ 	lwc1	$f0,0x1b68($a1)
/*  f0c8eec:	4600103c */ 	c.lt.s	$f2,$f0
.NB0f0c8ef0:
/*  f0c8ef0:	3c017f1a */ 	lui	$at,0x7f1a
/*  f0c8ef4:	45000004 */ 	bc1f	.NB0f0c8f08
/*  f0c8ef8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c8efc:	e4a21b68 */ 	swc1	$f2,0x1b68($a1)
/*  f0c8f00:	3c05800a */ 	lui	$a1,0x800a
/*  f0c8f04:	8ca5e944 */ 	lw	$a1,-0x16bc($a1)
.NB0f0c8f08:
/*  f0c8f08:	c4227c18 */ 	lwc1	$f2,0x7c18($at)
/*  f0c8f0c:	3c017f1a */ 	lui	$at,0x7f1a
/*  f0c8f10:	c4287c1c */ 	lwc1	$f8,0x7c1c($at)
/*  f0c8f14:	c4b00148 */ 	lwc1	$f16,0x148($a1)
/*  f0c8f18:	c4aa015c */ 	lwc1	$f10,0x15c($a1)
/*  f0c8f1c:	3c017f1a */ 	lui	$at,0x7f1a
/*  f0c8f20:	46088482 */ 	mul.s	$f18,$f16,$f8
/*  f0c8f24:	c4307c20 */ 	lwc1	$f16,0x7c20($at)
/*  f0c8f28:	46005187 */ 	neg.s	$f6,$f10
/*  f0c8f2c:	c4a401b4 */ 	lwc1	$f4,0x1b4($a1)
/*  f0c8f30:	46103202 */ 	mul.s	$f8,$f6,$f16
/*  f0c8f34:	44061000 */ 	mfc1	$a2,$f2
/*  f0c8f38:	46049300 */ 	add.s	$f12,$f18,$f4
/*  f0c8f3c:	c4b201b8 */ 	lwc1	$f18,0x1b8($a1)
/*  f0c8f40:	0fc27a39 */ 	jal	bgunSwivelTowards
/*  f0c8f44:	46124380 */ 	add.s	$f14,$f8,$f18
/*  f0c8f48:	10000016 */ 	beqz	$zero,.NB0f0c8fa4
/*  f0c8f4c:	8fbf0034 */ 	lw	$ra,0x34($sp)
.NB0f0c8f50:
/*  f0c8f50:	51e00014 */ 	beqzl	$t7,.NB0f0c8fa4
/*  f0c8f54:	8fbf0034 */ 	lw	$ra,0x34($sp)
/*  f0c8f58:	0fc29c5c */ 	jal	bgunSetAimType
/*  f0c8f5c:	00002025 */ 	or	$a0,$zero,$zero
/*  f0c8f60:	8fa30248 */ 	lw	$v1,0x248($sp)
/*  f0c8f64:	8fa4024c */ 	lw	$a0,0x24c($sp)
/*  f0c8f68:	3c017f1a */ 	lui	$at,0x7f1a
/*  f0c8f6c:	44832000 */ 	mtc1	$v1,$f4
/*  f0c8f70:	44848000 */ 	mtc1	$a0,$f16
/*  f0c8f74:	c4207c24 */ 	lwc1	$f0,0x7c24($at)
/*  f0c8f78:	468022a0 */ 	cvt.s.w	$f10,$f4
/*  f0c8f7c:	3c0142a0 */ 	lui	$at,0x42a0
/*  f0c8f80:	44811000 */ 	mtc1	$at,$f2
/*  f0c8f84:	46808220 */ 	cvt.s.w	$f8,$f16
/*  f0c8f88:	46005182 */ 	mul.s	$f6,$f10,$f0
/*  f0c8f8c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c8f90:	46004482 */ 	mul.s	$f18,$f8,$f0
/*  f0c8f94:	46023303 */ 	div.s	$f12,$f6,$f2
/*  f0c8f98:	0fc27a53 */ 	jal	bgun0f0a0b98
/*  f0c8f9c:	46029383 */ 	div.s	$f14,$f18,$f2
.NB0f0c8fa0:
/*  f0c8fa0:	8fbf0034 */ 	lw	$ra,0x34($sp)
.NB0f0c8fa4:
/*  f0c8fa4:	8fb00014 */ 	lw	$s0,0x14($sp)
/*  f0c8fa8:	8fb10018 */ 	lw	$s1,0x18($sp)
/*  f0c8fac:	8fb2001c */ 	lw	$s2,0x1c($sp)
/*  f0c8fb0:	8fb30020 */ 	lw	$s3,0x20($sp)
/*  f0c8fb4:	8fb40024 */ 	lw	$s4,0x24($sp)
/*  f0c8fb8:	8fb50028 */ 	lw	$s5,0x28($sp)
/*  f0c8fbc:	8fb6002c */ 	lw	$s6,0x2c($sp)
/*  f0c8fc0:	8fb70030 */ 	lw	$s7,0x30($sp)
/*  f0c8fc4:	03e00008 */ 	jr	$ra
/*  f0c8fc8:	27bd0260 */ 	addiu	$sp,$sp,0x260
);
#endif

/**
 * Called with these arguments:
 * 0, 0, 0, 1 = tickmode 6
 * 0, 0, 0, 1 = eyespy
 * 0, 0, 0, 1 = teleportstate 3
 * 0, 0, 0, 1 = slayerrocket
 * 0, 0, 0, 1 = tickmode 1 without control
 * 1, 1, ?, 0 = tickmode 1 with control
 * 1, 1, ?, 0 = tickmodes 0 and 5
 * 0, 0, 0, 1 = tickmode 4
 * 0, 0, 0, 1 = tickmode 3
 * 1, 1, 0, 1 = autowalk
 *
 * Not yet functionally identical:
 * - lookahead is applying when it shouldn't (eg. 1.2) and looks at the floor
 * - Farsight seek doesn't work
 */
//void bmoveProcessInput(s32 arg0, s32 arg1, s32 arg2, s32 arg3)
//{
//	struct movedata movedata; // 1b4 - 260
//	s32 controlmode; // 1b0
//	s32 weaponnum; // 1ac
//	s32 sp1a8;
//	s8 contpad1;
//	s8 contpad2;
//	u16 sp1a2;
//	u16 sp1a0;
//	u16 c1allowedbuttons; // 19e
//	u16 c1inhibitedbuttons;
//	u32 sp14c[20];
//	u32 spfc[20];
//	s8 shootpad;
//	u16 aimallowedbuttons;
//	u16 shootallowedbuttons;
//	s8 c2stickx; // e9
//	s8 c2stickx2;
//	s8 c2sticky2;
//	u16 spe6;
//	u16 spe4;
//	s8 c2sticky;
//	u16 c2allowedbuttons;
//	u16 c2inhibitedbuttons;
//	s32 spbc;
//	f32 spb4;
//	f32 spb0;
//	f32 spac;
//	struct coord spa0;
//	f32 sp98[2];
//	s8 c1stickx;
//	s8 c1sticky;
//	s32 numsamples;
//	s32 uVar18;
//	u16 inhibitedbuttons;
//	s32 lVar8;
//	s8 aimpad;
//	s32 uVar23;
//	f32 lookahead;
//	f32 fVar25;
//	f32 fVar26;
//	s32 offbike;
//	s32 cancycleweapons;
//	s32 i;
//
//	controlmode = optionsGetControlMode(g_Vars.currentplayerstats->mpindex);
//	weaponnum = bgunGetWeaponNum(HAND_RIGHT);
//	sp1a8 = weaponHasClassFlag(weaponnum, WEAPONCLASSFLAG_MANUALZOOM);
//	contpad1 = optionsGetContpadNum1(g_Vars.currentplayerstats->mpindex);
//
//	// 8c10
//	c1stickx = arg0 ? joyGetStickX(contpad1) : 0;
//
//	// 8c3c
//	c1sticky = arg1 ? joyGetStickY(contpad1) : 0;
//
//	// 8c68
//	sp1a2 = arg2 ? joyGetButtons(contpad1, 0xffff) : 0;
//
//	// 8c8c
//	sp1a0 = arg2 ? joyGetButtonsPressedThisFrame(contpad1, 0xffff) : 0;
//
//	// 8cb0
//	c1allowedbuttons = 0xffff;
//	c1inhibitedbuttons = g_Vars.currentplayer->joybutinhibit & 0xffff;
//
//	if (c1inhibitedbuttons) {
//		c1allowedbuttons = ~c1inhibitedbuttons;
//		inhibitedbuttons = joyGetButtons(contpad1, 0xffff) & (c1inhibitedbuttons & 0xffff);
//		sp1a2 &= ~inhibitedbuttons;
//		sp1a0 &= ~inhibitedbuttons;
//		g_Vars.currentplayer->joybutinhibit = (g_Vars.currentplayer->joybutinhibit & 0xffff0000) | inhibitedbuttons;
//	}
//
//	numsamples = joyGetNumSamples();
//	bmoveResetMoveData(&movedata);
//
//	// 8d3c
//	if (c1stickx < -5) {
//		movedata.c1stickxsafe = c1stickx + 5;
//	} else if (c1stickx > 5) {
//		movedata.c1stickxsafe = c1stickx - 5;
//	} else {
//		movedata.c1stickxsafe = 0;
//	}
//
//	// 8d64
//	if (c1sticky < -5) {
//		movedata.c1stickysafe = c1sticky + 5;
//	} else if (c1sticky > 5) {
//		movedata.c1stickysafe = c1sticky - 5;
//	} else {
//		movedata.c1stickysafe = 0;
//	}
//
//	// 8d90
//	movedata.c1stickxraw = c1stickx;
//	movedata.c1stickyraw = c1sticky;
//
//	// These are zeroed further down conditionally on control style
//	movedata.analogturn = movedata.c1stickxsafe;
//	movedata.analogstrafe = movedata.c1stickxsafe;
//	movedata.analogpitch = movedata.c1stickysafe;
//	movedata.analogwalk = movedata.c1stickysafe;
//
//	// Pausing
//	// 8db8
//	if (g_Vars.currentplayer->isdead == false) {
//		if (g_Vars.currentplayer->pausemode == PAUSEMODE_UNPAUSED && (sp1a0 & START_BUTTON)) {
//			if (g_Vars.mplayerisrunning == false) {
//				if (g_Vars.lvframenum > 15) {
//					currentPlayerPause(MENUROOT_MAINMENU);
//				}
//			} else {
//				mpPushPauseDialog();
//			}
//		}
//	} else {
//		// 8e14
//		if (g_Vars.mplayerisrunning) {
//			if (PLAYERCOUNT() == 1) {
//				if (mpIsPaused() && (sp1a0 & START_BUTTON) && g_MpSetup.paused != MPPAUSEMODE_GAMEOVER) {
//					mpSetPaused(MPPAUSEMODE_UNPAUSED);
//				}
//			} else {
//				if (mpIsPaused() && (sp1a0 & START_BUTTON)) {
//					mpPushPauseDialog();
//				}
//			}
//		}
//	}
//
//	// 8ef8
//	if (g_Vars.currentplayer->pausemode == PAUSEMODE_UNPAUSED) {
//		if (g_Vars.currentplayer->isdead == false) {
//			if (controlmode == CONTROLMODE_23 || controlmode == CONTROLMODE_24 || controlmode == CONTROLMODE_22 || controlmode == CONTROLMODE_21) {
//				// 2.1: ctrl1 stick = walk/turn, z = fire, ctrl2 stick = look/strafe, z = aim
//				// 2.2: ctrl1 stick = look,      z = fire, ctrl2 stick = walk/strafe, z = aim
//				// 2.3: ctrl1 stick = walk/turn, z = aim,  ctrl2 stick = look/strafe, z = fire
//				// 2.4: ctrl1 stick = look,      z = aim,  ctrl2 stick = walk/strafe, z = fire
//				// 8f38
//				contpad2 = optionsGetContpadNum2(g_Vars.currentplayerstats->mpindex); // shifted to s8 and stored in s4
//				// s4 shifted to s8 and stored in a0 for next jal
//				c2stickx = joyGetStickX(contpad2); // sb v0,0xe9(sp)
//				// s4 shifted to s8 and stored in a0 for next jal
//				c2sticky = joyGetStickY(contpad2); // shifted to s8 and stored in s0
//				// s4 shifted to s8 and stored in a0 for next jal
//				spe6 = joyGetButtons(contpad2, 0xffff); // sh v0,0xe6(sp)
//				// s4 shifted to s8 and stored in a0 for next jal
//				spe4 = joyGetButtonsPressedThisFrame(contpad2, 0xffff); // sh v0,0xe4(sp)
//				c2stickx2 = c2stickx; // s3 = spe9
//				c2sticky2 = c2sticky; // a0 = s0
//
//				c2allowedbuttons = 0xffff;
//				c2inhibitedbuttons = g_Vars.currentplayer->joybutinhibit >> 16;
//
//				// 8fac
//				if (c2inhibitedbuttons) {
//					c2allowedbuttons = ~c2inhibitedbuttons;
//					inhibitedbuttons = joyGetButtons(contpad2, 0xffff) & c2inhibitedbuttons;
//					spe6 &= ~inhibitedbuttons;
//					spe4 &= ~inhibitedbuttons;
//					g_Vars.currentplayer->joybutinhibit = (g_Vars.currentplayer->joybutinhibit & 0xffff) | (inhibitedbuttons << 16);
//				}
//
//				// 9038
//				if (arg3) {
//					c2stickx = 0;
//					spe6 = 0;
//					c2sticky = 0;
//					spe4 = 0;
//					c2stickx2 = 0;
//				}
//
//				// 9058
//				if (c2stickx2 < -5) {
//					c2stickx2 += 5;
//				} else if (c2stickx2 > 5) {
//					c2stickx2 -= 5;
//				} else {
//					c2stickx2 = 0;
//				}
//
//				// 9084
//				if (c2sticky2 < -5) {
//					c2sticky2 += 5;
//				} else if (c2sticky2 > 5) {
//					c2sticky2 -= 5;
//				} else {
//					c2sticky2 = 0;
//				}
//
//				// 90b0
//				if (controlmode == CONTROLMODE_21 || controlmode == CONTROLMODE_23) {
//					movedata.analogstrafe = c2stickx2;
//					movedata.analogpitch = c2sticky2;
//				} else {
//					movedata.analogstrafe = c2stickx2;
//					movedata.analogwalk = c2sticky2;
//				}
//
//				// 90d8
//				if (g_Vars.tickmode == TICKMODE_AUTOWALK) {
//					movedata.digitalstepforward = false;
//					movedata.digitalstepback = false;
//					movedata.analogstrafe = 0;
//					movedata.analogwalk = g_Vars.currentplayer->autocontrol_y;
//					movedata.analogpitch = 0;
//					movedata.analogturn = g_Vars.currentplayer->autocontrol_x;
//				}
//
//				// 9110
//				if (controlmode == CONTROLMODE_21 || controlmode == CONTROLMODE_22) {
//					aimallowedbuttons = c2allowedbuttons;
//					shootallowedbuttons = c1allowedbuttons;
//					aimpad = contpad2;
//					shootpad = contpad1;
//				} else {
//					// 9150
//					aimallowedbuttons = c1allowedbuttons;
//					shootallowedbuttons = c2allowedbuttons;
//					aimpad = contpad1;
//					shootpad = contpad2;
//				}
//
//				// 9170
//				if (optionsGetAimControl(g_Vars.currentplayerstats->mpindex) == AIMCONTROL_HOLD) {
//					for (i = 0; i < numsamples; i++) {
//						sp14c[i] = arg2 && joyGetButtonsOnSample(i, aimpad, aimallowedbuttons & Z_TRIG);
//						spfc[i] = !sp14c[i];
//					}
//
//					g_Vars.currentplayer->insightaimmode = sp14c[numsamples - 1];
//				}
//
//				// 91fc
//				if (lvIsPaused() == false) {
//					// 920c
//					if (optionsGetAimControl(g_Vars.currentplayerstats->mpindex) != AIMCONTROL_HOLD) {
//						for (i = 0; i < numsamples; i++) {
//							if (arg2 && joyGetButtonsPressedOnSample(i, aimpad, aimallowedbuttons & Z_TRIG)) {
//								g_Vars.currentplayer->insightaimmode = !g_Vars.currentplayer->insightaimmode;
//							}
//
//							sp14c[i] = g_Vars.currentplayer->insightaimmode;
//							spfc[i] = !g_Vars.currentplayer->insightaimmode;
//						}
//					}
//
//					// 9298
//					if (bgunGetWeaponNum(HAND_RIGHT) == WEAPON_HORIZONSCANNER) {
//						g_Vars.currentplayer->insightaimmode = true;
//					}
//
//					// 92b8
//					movedata.canswivelgun = !g_Vars.currentplayer->insightaimmode;
//					movedata.canmanualaim = g_Vars.currentplayer->insightaimmode;
//					movedata.digitalstepforward = false;
//					movedata.digitalstepback = false;
//					movedata.canautoaim = !g_Vars.currentplayer->insightaimmode;
//					movedata.digitalstepleft = false;
//					movedata.digitalstepright = false;
//					movedata.unk14 = 1;
//					movedata.canlookahead = !g_Vars.currentplayer->insightaimmode;
//					movedata.cannaturalturn = !g_Vars.currentplayer->insightaimmode;
//					movedata.cannaturalpitch = !g_Vars.currentplayer->insightaimmode;
//
//					// 931c
//					if (g_Vars.currentplayer->insightaimmode && movedata.c1stickyraw > 60) {
//						movedata.speedvertadown = (movedata.c1stickyraw - 60) / 10.0f;
//
//						if (movedata.speedvertadown > 1) {
//							movedata.speedvertadown = 1;
//						}
//					} else {
//						movedata.speedvertadown = 0;
//					}
//
//					// 9380
//					if (g_Vars.currentplayer->insightaimmode && movedata.c1stickyraw < -60) {
//						movedata.speedvertaup = (-60 - movedata.c1stickyraw) / 10.0f;
//
//						if (movedata.speedvertaup > 1) {
//							movedata.speedvertaup = 1;
//						}
//					} else {
//						movedata.speedvertaup = 0;
//					}
//
//					// 93e0
//					if (g_Vars.currentplayer->insightaimmode && movedata.c1stickxraw < -60) {
//						movedata.aimturnleftspeed = (-60 - movedata.c1stickxraw) / 10.0f;
//
//						if (movedata.aimturnleftspeed > 1) {
//							movedata.aimturnleftspeed = 1;
//						}
//					} else {
//						movedata.aimturnleftspeed = 0;
//					}
//
//					// 943c
//					if (g_Vars.currentplayer->insightaimmode && movedata.c1stickxraw > 60) {
//						movedata.aimturnrightspeed = (movedata.c1stickxraw - 60) / 10.0f;
//
//						if (movedata.aimturnrightspeed > 1) {
//							movedata.aimturnrightspeed = 1;
//						}
//					} else {
//						movedata.aimturnrightspeed = 0;
//					}
//
//					// 9494
//					if (arg2) {
//						if (g_Vars.currentplayer->invdowntime < -2) {
//							g_Vars.currentplayer->invdowntime += numsamples;
//
//							if (g_Vars.currentplayer->invdowntime > -3) {
//								g_Vars.currentplayer->invdowntime = 0;
//							}
//						} else {
//							for (i = 0; i < numsamples; i++) {
//								if (joyGetButtonsOnSample(i, contpad1, c1allowedbuttons & A_BUTTON)
//										|| joyGetButtonsOnSample(i, contpad2, c2allowedbuttons & A_BUTTON)) {
//									if (g_Vars.currentplayer->invdowntime > -2) {
//										if (joyGetButtonsPressedOnSample(i, shootpad, shootallowedbuttons & Z_TRIG)) {
//											movedata.weaponbackoffset++;
//											g_Vars.currentplayer->invdowntime = -1;
//										}
//
//										if (g_Vars.currentplayer->invdowntime > -1
//												&& joyGetButtonsOnSample(i, shootpad, shootallowedbuttons & Z_TRIG) == 0) {
//											if (g_Vars.currentplayer->invdowntime > 15) {
//												amOpen();
//												g_Vars.currentplayer->invdowntime = -1;
//											} else {
//												g_Vars.currentplayer->invdowntime++;
//											}
//										}
//									}
//								} else {
//									if (g_Vars.currentplayer->invdowntime > 0 &&
//											(!arg2 || joyGetButtonsOnSample(i, shootpad, shootallowedbuttons & Z_TRIG) == 0)) {
//										movedata.weaponforwardoffset++;
//									}
//
//									g_Vars.currentplayer->invdowntime = 0;
//								}
//							}
//						}
//					}
//
//					// 9608
//					if (arg2) {
//						for (i = 0; i < numsamples; i++) {
//							if (joyGetButtonsOnSample(i, contpad1, c1allowedbuttons & B_BUTTON)
//									|| joyGetButtonsOnSample(i, contpad2, c2allowedbuttons & B_BUTTON)) {
//								if (g_Vars.currentplayer->usedowntime >= -1) {
//									if (joyGetButtonsPressedOnSample(i, shootpad, shootallowedbuttons & Z_TRIG)
//											&& g_Vars.currentplayer->usedowntime > -1
//											&& bgunConsiderToggleGunFunction(g_Vars.currentplayer->usedowntime, 1, 0)) {
//										g_Vars.currentplayer->usedowntime = -3;
//									}
//
//									if (g_Vars.currentplayer->usedowntime > -1) {
//										if (g_Vars.currentplayer->usedowntime > 25) {
//											lVar8 = bgunConsiderToggleGunFunction(g_Vars.currentplayer->usedowntime, 0, 0);
//
//											if (lVar8 == 1) {
//												g_Vars.currentplayer->usedowntime = -1;
//											} else if (lVar8 == 2) {
//												g_Vars.currentplayer->usedowntime = -2;
//											} else {
//												g_Vars.currentplayer->usedowntime++;
//											}
//										} else {
//											g_Vars.currentplayer->usedowntime++;
//										}
//									}
//								} else if (g_Vars.currentplayer->usedowntime >= -2) {
//									bgunConsiderToggleGunFunction(g_Vars.currentplayer->usedowntime, 0, 0);
//								}
//							} else {
//								// Released B - activate or reload
//								if (g_Vars.currentplayer->usedowntime > 0) {
//									movedata.btapcount++;
//								}
//
//								g_Vars.currentplayer->usedowntime = 0;
//								bgun0f0a8c50();
//							}
//						}
//					}
//
//					// Zoom in and out - due to no buttons held?
//					// 9784
//					if (sp1a8 && g_Vars.currentplayer->insightaimmode) {
//						if (c2sticky < 0) {
//							movedata.zoomoutfovpersec = -c2sticky / 70.0f;
//
//							if (movedata.zoomoutfovpersec > 1) {
//								movedata.zoomoutfovpersec = 1;
//							}
//
//							movedata.zoomoutfovpersec = movedata.zoomoutfovpersec + movedata.zoomoutfovpersec;
//						}
//
//						if (c2sticky > 0) {
//							movedata.zoominfovpersec = c2sticky / 70.0f;
//
//							if (movedata.zoominfovpersec > 1) {
//								movedata.zoominfovpersec = 1;
//							}
//
//							movedata.zoominfovpersec = movedata.zoominfovpersec + movedata.zoominfovpersec;
//						}
//					}
//
//					// Crouch and uncrouch
//					// 9838
//					if (arg2) {
//						for (i = 0; i < numsamples; i++) {
//							if (sp1a8 == 0 && sp14c[i]) {
//								if (joyGetStickYOnSample(i, contpad2) > 30 && joyGetStickYOnSampleIndex(i, contpad2) <= 30) {
//									if (movedata.crouchdown) {
//										movedata.crouchdown--;
//									} else {
//										movedata.crouchup++;
//									}
//
//									g_Vars.currentplayer->aimtaptime = -1;
//								}
//
//								if (joyGetStickYOnSample(i, contpad2) < -30 && joyGetStickYOnSampleIndex(i, contpad2) >= -30) {
//									if (movedata.crouchup) {
//										movedata.crouchup--;
//									} else {
//										movedata.crouchdown++;
//									}
//
//									g_Vars.currentplayer->aimtaptime = -1;
//								}
//							}
//
//							if (optionsGetAimControl(g_Vars.currentplayerstats->mpindex) == AIMCONTROL_HOLD) {
//								if (sp14c[i]) {
//									if (g_Vars.currentplayer->aimtaptime > -1) {
//										g_Vars.currentplayer->aimtaptime++;
//									}
//								} else {
//									if (g_Vars.currentplayer->aimtaptime > 0
//											&& g_Vars.currentplayer->aimtaptime < 15) {
//										if (movedata.crouchdown) {
//											movedata.crouchdown--;
//										} else {
//											movedata.crouchup++;
//										}
//									}
//
//									g_Vars.currentplayer->aimtaptime = 0;
//								}
//							}
//						}
//					}
//
//					// 99a4
//					if (bmoveGetCrouchPos() == CROUCHPOS_SQUAT
//							&& g_Vars.currentplayer->crouchoffset == -90
//							&& g_Vars.mplayerisrunning
//							&& g_Vars.coopplayernum < 0) {
//						movedata.eyesshut = g_Vars.currentplayer->insightaimmode
//							&& !sp1a8
//							&& joyGetStickY(contpad2) < -30;
//					}
//
//					// 9a24
//					if (bgunGetWeaponNum(HAND_RIGHT) == WEAPON_FARSIGHT) {
//						if (g_Vars.currentplayer->insightaimmode) {
//							movedata.unk14 = 0;
//						}
//
//						movedata.farsighttempautoseek = g_Vars.currentplayer->insightaimmode
//							&& (c2stickx < -30 || c2stickx > 30);
//					}
//
//					// 9a78
//					movedata.rleanleft = 0;
//					movedata.rleanright = 0;
//
//					// Mine detonation
//					if ((((sp1a2 & A_BUTTON) && (sp1a0 & B_BUTTON))
//								|| ((sp1a2 & B_BUTTON) && (sp1a0 & A_BUTTON))
//								|| ((spe6 & A_BUTTON) && (spe4 & B_BUTTON))
//								|| ((spe6 & B_BUTTON) && (spe4 & A_BUTTON)))
//							&& weaponnum == WEAPON_REMOTEMINE) {
//						// 9af0
//						movedata.detonating = true;
//						movedata.weaponbackoffset = 0;
//						movedata.weaponforwardoffset = 0;
//						movedata.btapcount = 0;
//						g_Vars.currentplayer->invdowntime = -2;
//						g_Vars.currentplayer->usedowntime = -2;
//					}
//				}
//
//				// 9b10
//				movedata.unk54 = g_Vars.currentplayer->insightaimmode;
//				movedata.unk58 = g_Vars.currentplayer->insightaimmode;
//
//				if (g_Vars.currentplayer->waitforzrelease
//						&& joyGetButtons(shootpad, shootallowedbuttons & Z_TRIG) == 0) {
//					g_Vars.currentplayer->waitforzrelease = false;
//				}
//
//				if (weaponHasFlag(bgunGetWeaponNum(HAND_RIGHT), WEAPONFLAG_80000000)) {
//					if (arg2
//							&& joyGetButtonsPressedThisFrame(shootpad, shootallowedbuttons & Z_TRIG)
//							&& g_Vars.currentplayer->pausemode == PAUSEMODE_UNPAUSED) {
//						movedata.btapcount++;
//					}
//				} else {
//					movedata.triggeron = g_Vars.currentplayer->waitforzrelease == false
//						&& arg2
//						&& joyGetButtons(shootpad, shootallowedbuttons & Z_TRIG)
//						&& g_Vars.currentplayer->pausemode == PAUSEMODE_UNPAUSED
//						&& (sp1a2 & A_BUTTON) == 0
//						&& (spe6 & A_BUTTON) == 0;
//				}
//
//				movedata.disablelookahead = true;
//			} else {
//				// 9c2c
//				// 1.x control style
//				u16 shootbuttons; // s4
//				u16 aimbuttons; // s1
//				u16 invbuttons; // spca
//
//				if (controlmode == CONTROLMODE_13 || controlmode == CONTROLMODE_14) {
//					shootbuttons = A_BUTTON;
//					aimbuttons = Z_TRIG;
//					invbuttons = L_TRIG | R_TRIG;
//				} else {
//					shootbuttons = Z_TRIG;
//					aimbuttons = L_TRIG | R_TRIG;
//					invbuttons = A_BUTTON;
//				}
//
//				// 9c60
//				if (optionsGetAimControl(g_Vars.currentplayerstats->mpindex) == AIMCONTROL_HOLD) {
//					for (i = 0; i < numsamples; i++) {
//						sp14c[i] = arg2 && joyGetButtonsOnSample(i, contpad1, aimbuttons & c1allowedbuttons);
//						spfc[i] = !sp14c[i];
//					}
//
//					g_Vars.currentplayer->insightaimmode = sp14c[numsamples - 1];
//				}
//
//				// 9cf4
//				if (lvIsPaused() == false) {
//					// 9d04
//					if (optionsGetAimControl(g_Vars.currentplayerstats->mpindex) != AIMCONTROL_HOLD) {
//						for (i = 0; i < numsamples; i++) {
//							if (arg2 && joyGetButtonsPressedOnSample(i, contpad1, aimbuttons & c1allowedbuttons)) {
//								g_Vars.currentplayer->insightaimmode = !g_Vars.currentplayer->insightaimmode;
//							}
//
//							sp14c[i] = !g_Vars.currentplayer->insightaimmode;
//							spfc[i] = g_Vars.currentplayer->insightaimmode;
//						}
//					}
//
//					// 9d98
//					if (bgunGetWeaponNum(HAND_RIGHT) == WEAPON_HORIZONSCANNER) {
//						g_Vars.currentplayer->insightaimmode = true;
//					}
//
//					// 9db8
//					movedata.canswivelgun = !g_Vars.currentplayer->insightaimmode;
//					movedata.canmanualaim = g_Vars.currentplayer->insightaimmode;
//					movedata.canautoaim = !g_Vars.currentplayer->insightaimmode;
//
//					if (controlmode == CONTROLMODE_12 || controlmode == CONTROLMODE_14) {
//						// 9df4
//						// Side stepping
//						if (g_Vars.currentplayer->insightaimmode == false) {
//							if (arg2) {
//								movedata.digitalstepleft = joyCountButtonsOnSpecificSamples(spfc, contpad1, c1allowedbuttons & (L_JPAD | L_CBUTTONS));
//								movedata.digitalstepright = joyCountButtonsOnSpecificSamples(spfc, contpad1, c1allowedbuttons & (R_JPAD | R_CBUTTONS));
//							}
//						} else {
//							// This doesn't appear to be r-leaning.
//							// R-leaning still works when these are commented.
//							if (sp1a2 & (L_JPAD | L_CBUTTONS)) {
//								movedata.unk30 = 1;
//							}
//
//							if (sp1a2 & (R_JPAD | R_CBUTTONS)) {
//								movedata.unk34 = 1;
//							}
//						}
//
//						movedata.digitalstepforward = !g_Vars.currentplayer->insightaimmode && (sp1a2 & (U_JPAD | U_CBUTTONS));
//						movedata.digitalstepback = !g_Vars.currentplayer->insightaimmode && (sp1a2 & (D_JPAD | D_CBUTTONS));
//						movedata.canlookahead = false;
//						movedata.speedvertadown = 0;
//						movedata.speedvertaup = 0;
//						movedata.cannaturalpitch = !g_Vars.currentplayer->insightaimmode;
//						movedata.cannaturalturn = !g_Vars.currentplayer->insightaimmode;
//
//						if (g_Vars.tickmode == TICKMODE_AUTOWALK) {
//							movedata.digitalstepforward = (g_Vars.currentplayer->autocontrol_y > 0);
//							movedata.analogstrafe = 0;
//							movedata.analogwalk = 0;
//							movedata.digitalstepback = (g_Vars.currentplayer->autocontrol_y < 0);
//							movedata.analogpitch = 0;
//							movedata.analogturn = g_Vars.currentplayer->autocontrol_x;
//						}
//					} else {
//						// 1.1 or 1.3
//						// 9f40
//						if (sp1a2 & (L_JPAD | L_CBUTTONS)) {
//							movedata.unk30 = 1;
//						}
//
//						if (sp1a2 & (R_JPAD | R_CBUTTONS)) {
//							movedata.unk34 = 1;
//						}
//
//						if (!g_Vars.currentplayer->insightaimmode && arg2) {
//							movedata.digitalstepleft = joyCountButtonsOnSpecificSamples(spfc, contpad1, c1allowedbuttons & (L_JPAD | L_CBUTTONS));
//							movedata.digitalstepright = joyCountButtonsOnSpecificSamples(spfc, contpad1, c1allowedbuttons & (R_JPAD | R_CBUTTONS));
//						}
//
//						movedata.digitalstepforward = false;
//						movedata.digitalstepback = false;
//						movedata.cannaturalpitch = false;
//						movedata.canlookahead = !g_Vars.currentplayer->insightaimmode;
//
//						// Looking up/down
//						if (!g_Vars.currentplayer->insightaimmode && (sp1a2 & (U_JPAD | U_CBUTTONS))) {
//							movedata.speedvertadown = 1;
//						}
//
//						if (!g_Vars.currentplayer->insightaimmode && (sp1a2 & (D_JPAD | D_CBUTTONS))) {
//							movedata.speedvertaup = 1;
//						}
//
//						movedata.cannaturalturn = !g_Vars.currentplayer->insightaimmode;
//						movedata.unk14 = 0;
//
//						if (g_Vars.tickmode == TICKMODE_AUTOWALK) {
//							movedata.analogstrafe = 0;
//							movedata.analogwalk = g_Vars.currentplayer->autocontrol_y;
//							movedata.analogpitch = 0;
//							movedata.analogturn = g_Vars.currentplayer->autocontrol_x;
//						}
//					}
//
//					// a078
//					// Looking up/down while aiming
//					if (g_Vars.currentplayer->insightaimmode && movedata.c1stickyraw > 60) {
//						movedata.speedvertadown = (movedata.c1stickyraw - 60) / 10.0f;
//
//						if (movedata.speedvertadown > 1) {
//							movedata.speedvertadown = 1;
//						}
//					} else if (g_Vars.currentplayer->insightaimmode && movedata.c1stickyraw < -60) {
//						movedata.speedvertaup = (-60 - movedata.c1stickyraw) / 10.0f;
//
//						if (movedata.speedvertaup > 1) {
//							movedata.speedvertaup = 1;
//						}
//					}
//
//					// a120
//					// Looking left/right while aiming
//					if (g_Vars.currentplayer->insightaimmode && movedata.c1stickxraw < -60) {
//						movedata.aimturnleftspeed = (-60 - movedata.c1stickxraw) / 10.0f;
//
//						if (movedata.aimturnleftspeed > 1) {
//							movedata.aimturnleftspeed = 1;
//						}
//					} else if (g_Vars.currentplayer->insightaimmode && movedata.c1stickxraw > 60) {
//						movedata.aimturnrightspeed = (movedata.c1stickxraw - 60) / 10.0f;
//
//						if (movedata.aimturnrightspeed > 1) {
//							movedata.aimturnrightspeed = 1;
//						}
//					}
//
//					// Holding A
//					// a1c0
//					if (arg2) {
//						if (g_Vars.currentplayer->invdowntime < -2) {
//							g_Vars.currentplayer->invdowntime += numsamples;
//
//							if (g_Vars.currentplayer->invdowntime > -3) {
//								g_Vars.currentplayer->invdowntime = 0;
//							}
//						} else {
//							for (i = 0; i < numsamples; i++) {
//								if (joyGetButtonsOnSample(i, contpad1, invbuttons & c1allowedbuttons)) {
//									if (g_Vars.currentplayer->invdowntime > -2) {
//										if (joyGetButtonsPressedOnSample(i, contpad1, shootbuttons & c1allowedbuttons)) {
//											movedata.weaponbackoffset++;
//											g_Vars.currentplayer->invdowntime = -1;
//										}
//
//										if (g_Vars.currentplayer->invdowntime >= 0 && joyGetButtonsOnSample(i, contpad1, shootbuttons & c1allowedbuttons) == 0) {
//											// Holding A and haven't pressed Z
//											if (g_Vars.currentplayer->invdowntime > 15) {
//												amOpen();
//												g_Vars.currentplayer->invdowntime = -1;
//											} else {
//												g_Vars.currentplayer->invdowntime++;
//											}
//										}
//									}
//								} else {
//									// Wasn't holding A on this sample
//									if (g_Vars.currentplayer->invdowntime > 0 &&
//											(!arg2 || joyGetButtonsOnSample(i, contpad1, shootbuttons & c1allowedbuttons) == 0)) {
//										// But was on previous sample, so cycle weapon
//										movedata.weaponforwardoffset++;
//									}
//
//									g_Vars.currentplayer->invdowntime = 0;
//								}
//							}
//						}
//					}
//
//					// Holding B
//					// a340
//					if (arg2) {
//						for (i = 0; i < numsamples; i++) {
//							if (joyGetButtonsOnSample(i, contpad1, c1allowedbuttons & B_BUTTON)) {
//								if (g_Vars.currentplayer->usedowntime >= -1) {
//									if (joyGetButtonsPressedOnSample(i, contpad1, shootbuttons & c1allowedbuttons)
//											&& g_Vars.currentplayer->usedowntime >= 0
//											&& bgunConsiderToggleGunFunction(g_Vars.currentplayer->usedowntime, 1, 0)) {
//										g_Vars.currentplayer->usedowntime = -3;
//									}
//
//									if (g_Vars.currentplayer->usedowntime >= 0) {
//										if (g_Vars.currentplayer->usedowntime > 25) {
//											s32 result = bgunConsiderToggleGunFunction(g_Vars.currentplayer->usedowntime, 0, 0);
//
//											if (result == 1) {
//												g_Vars.currentplayer->usedowntime = -1;
//											} else if (result == 2) {
//												g_Vars.currentplayer->usedowntime = -2;
//											} else {
//												g_Vars.currentplayer->usedowntime++;
//											}
//										} else {
//											g_Vars.currentplayer->usedowntime++;
//										}
//									}
//								} else {
//									if (g_Vars.currentplayer->usedowntime >= -2) {
//										bgunConsiderToggleGunFunction(g_Vars.currentplayer->usedowntime, 0, 0);
//									}
//								}
//							} else {
//								// Released B
//								if (g_Vars.currentplayer->usedowntime > 0) {
//									movedata.btapcount++;
//								}
//
//								g_Vars.currentplayer->usedowntime = 0;
//								bgun0f0a8c50();
//							}
//						}
//					}
//
//					// Zoom in and out
//					// a4ac
//					if (sp1a8 && g_Vars.currentplayer->insightaimmode) {
//						f32 increment = 1;
//						spbc = 1;
//
//                      // @bug? Should this be HAND_RIGHT?
//						if (bgunGetWeaponNum(HAND_LEFT) == WEAPON_FARSIGHT) {
//							increment = 0.5f;
//						}
//
//						if (sp1a2 & (D_JPAD | D_CBUTTONS)) {
//							movedata.zoomoutfovpersec = increment;
//						}
//
//						if (sp1a2 & (U_JPAD | U_CBUTTONS)) {
//							movedata.zoominfovpersec = increment;
//						}
//					}
//
//					// Crouch and uncrouch
//					// a524
//					if (arg2) {
//						for (i = 0; i < numsamples; i++) {
//							if (sp1a8 == 0 && sp14c[i]) {
//								if (joyGetButtonsPressedOnSample(i, contpad1, c1allowedbuttons & (U_JPAD | U_CBUTTONS))) {
//									if (movedata.crouchdown) {
//										movedata.crouchdown--;
//									} else {
//										movedata.crouchup++;
//									}
//
//									g_Vars.currentplayer->aimtaptime = -1;
//								}
//
//								if (joyGetButtonsPressedOnSample(i, contpad1, c1allowedbuttons & (D_JPAD | D_CBUTTONS))) {
//									if (movedata.crouchup) {
//										movedata.crouchup--;
//									} else {
//										movedata.crouchdown++;
//									}
//
//									g_Vars.currentplayer->aimtaptime = -1;
//								}
//							}
//
//							if (optionsGetAimControl(g_Vars.currentplayerstats->mpindex) == AIMCONTROL_HOLD) {
//								if (sp14c[i]) {
//									if (g_Vars.currentplayer->aimtaptime >= 0) {
//										g_Vars.currentplayer->aimtaptime++;
//									}
//								} else {
//									// Released aim
//									if (g_Vars.currentplayer->aimtaptime > 0 && g_Vars.currentplayer->aimtaptime < 15) {
//										// Was only a tap, so uncrouch
//										if (movedata.crouchdown) {
//											movedata.crouchdown--;
//										} else {
//											movedata.crouchup++;
//										}
//									}
//
//									g_Vars.currentplayer->aimtaptime = 0;
//								}
//							}
//						}
//					}
//
//					// a670
//					// Handle shutting eyes in multiplayer
//					if (bmoveGetCrouchPos() == CROUCHPOS_SQUAT
//							&& g_Vars.currentplayer->crouchoffset == -90
//							&& g_Vars.mplayerisrunning
//							&& g_Vars.coopplayernum <= -1) {
//						movedata.eyesshut = g_Vars.currentplayer->insightaimmode
//							&& sp1a8 == 0
//							&& joyGetButtons(contpad1, c1allowedbuttons & (D_JPAD | D_CBUTTONS));
//					}
//
//					if (bgunGetWeaponNum(HAND_RIGHT) == WEAPON_FARSIGHT) {
//						movedata.farsighttempautoseek = g_Vars.currentplayer->insightaimmode && (sp1a2 & (L_TRIG | R_TRIG | L_CBUTTONS | R_CBUTTONS));
//					} else {
//						movedata.rleanleft = g_Vars.currentplayer->insightaimmode && (sp1a2 & (L_JPAD | L_CBUTTONS));
//						movedata.rleanright = g_Vars.currentplayer->insightaimmode && (sp1a2 & (R_JPAD | R_CBUTTONS));
//					}
//
//					// Mine detonation
//					if (((sp1a2 & invbuttons) && (sp1a0 & B_BUTTON))
//							|| ((sp1a2 & B_BUTTON) && (sp1a0 & invbuttons))
//							&& weaponnum == WEAPON_REMOTEMINE) {
//						movedata.detonating = true;
//						movedata.weaponbackoffset = 0;
//						movedata.weaponforwardoffset = 0;
//						movedata.btapcount = 0;
//						g_Vars.currentplayer->invdowntime = -2;
//						g_Vars.currentplayer->usedowntime = -2;
//					}
//				}
//
//				// a7e8
//				movedata.unk54 = g_Vars.currentplayer->insightaimmode;
//				movedata.unk58 = g_Vars.currentplayer->insightaimmode;
//
//				if (g_Vars.currentplayer->waitforzrelease
//						&& (sp1a2 & shootbuttons) == 0) {
//					g_Vars.currentplayer->waitforzrelease = false;
//				}
//
//				if (weaponHasFlag(bgunGetWeaponNum(HAND_RIGHT), WEAPONFLAG_80000000)) {
//					if ((sp1a0 & shootbuttons)
//							&& g_Vars.currentplayer->pausemode == PAUSEMODE_UNPAUSED) {
//						movedata.btapcount++;
//					}
//				} else {
//					movedata.triggeron = g_Vars.currentplayer->waitforzrelease == false
//						&& (sp1a2 & shootbuttons)
//						&& g_Vars.currentplayer->pausemode == PAUSEMODE_UNPAUSED
//						&& (sp1a2 & invbuttons) == 0;
//				}
//
//				if (controlmode == CONTROLMODE_12 || controlmode == CONTROLMODE_14) {
//					movedata.disablelookahead = true;
//				}
//			} // end 1.x
//		}
//	}
//
//	// a8d0
//	g_Vars.currentplayer->bondactivateorreload = 0;
//
//	if (movedata.btapcount) {
//		g_Vars.currentplayer->activatetimelast = g_Vars.currentplayer->activatetimethis;
//		g_Vars.currentplayer->activatetimethis = g_Vars.lvframe60;
//		g_Vars.currentplayer->bondactivateorreload = movedata.btapcount;
//
//		bmoveHandleActivate();
//	}
//
//	if (!movedata.invertpitch) {
//		f32 tmp = movedata.speedvertaup;
//		movedata.analogpitch = -movedata.analogpitch;
//		movedata.c1stickyraw = -movedata.c1stickyraw;
//		movedata.speedvertaup = movedata.speedvertadown;
//		movedata.speedvertadown = tmp;
//	}
//
//	bgunsTick(movedata.triggeron);
//
//	// a944
//	if (g_Vars.bondvisible && (bgunIsFiring(0) || bgunIsFiring(1))) {
//		spb4 = 0;
//
//		if (bgunIsFiring(0) && bgunGetNoiseRadius(0) > spb4) {
//			spb4 = bgunGetNoiseRadius(0);
//		}
//
//		if (bgunIsFiring(1) && bgunGetNoiseRadius(1) > spb4) {
//			spb4 = bgunGetNoiseRadius(1);
//		}
//
//		func0f028590(spb4);
//	}
//
//	bgunSetSightVisible(GUNSIGHTREASON_AIMING, movedata.unk54);
//
//	if (movedata.zoomoutfovpersec > 0) {
//		currentPlayerZoomOut(movedata.zoomoutfovpersec);
//	}
//
//	if (movedata.zoominfovpersec > 0) {
//		currentPlayerZoomIn(movedata.zoominfovpersec);
//	}
//
//	// aa48
//	if (g_Vars.currentplayer->pausemode == PAUSEMODE_UNPAUSED && g_MainIsEndscreen == 0) {
//		spb0 = 60;
//
//		// FarSight in secondary function
//		if (bgunGetWeaponNum(HAND_RIGHT) == WEAPON_FARSIGHT
//				&& g_Vars.currentplayer->insightaimmode
//				&& movedata.farsighttempautoseek == false
//				&& g_Vars.currentplayer->hands[HAND_RIGHT].weaponfunc == FUNC_SECONDARY
//				&& g_Vars.currentplayer->autoeraserdist > 0) {
//			spac = func0f0b49b8(500.0f / g_Vars.currentplayer->autoeraserdist);
//
//			if (spac > 60) {
//				spac = 60;
//			}
//
//			if (spac < 2) {
//				spac = 2;
//			}
//
//			g_Vars.currentplayer->gunzoomfovs[1] = spac;
//
//			func00015b68(currentPlayerGetMatrix1740(), &g_Vars.currentplayer->autoerasertarget->pos, &spa0);
//
//			func0f0b4eb8(&spa0, sp98, spac, g_Vars.currentplayer->c_perspaspect);
//
//			if (spa0.x < (currentPlayerGetScreenLeft() + currentPlayerGetScreenWidth() * 0.5f) - 20.0f) {
//				movedata.aimturnleftspeed = 0.25f;
//			} else if (spa0.x > currentPlayerGetScreenLeft() + currentPlayerGetScreenWidth() * 0.5f + 20.0f) {
//				movedata.aimturnrightspeed = 0.25f;
//			}
//
//			if (sp98[1] < (currentPlayerGetScreenTop() + currentPlayerGetScreenHeight() * 0.5f) - 20.0f) {
//				movedata.speedvertaup = 0.25f;
//			} else if (sp98[1] > currentPlayerGetScreenTop() + currentPlayerGetScreenHeight() * 0.5f + 20.0f) {
//				movedata.speedvertadown = 0.25f;
//			}
//		}
//
//		if (movedata.unk58) {
//			spb0 = currentPlayerGetGunZoomFov();
//		}
//
//		if (bgunGetWeaponNum(HAND_RIGHT) == WEAPON_AR34
//				&& g_Vars.currentplayer->hands[HAND_RIGHT].weaponfunc == FUNC_SECONDARY) {
//			spb0 = currentPlayerGetGunZoomFov();
//		}
//
//		if (spb0 <= 0) {
//			spb0 = 60;
//		}
//
//		func0f0ba8b0(spb0);
//		currentPlayerUpdateZoom();
//	}
//
//	// ad28
//	bmoveApplyMoveData(&movedata);
//
//	// Speed boost
//	// After 3 seconds of holding forward at max speed, apply boost multiplier.
//	// The multiplier starts at 1 and reaches 1.25 after about 0.1 seconds.
//	if (g_Vars.currentplayer->speedmaxtime60 >= 180) {
//		if (g_Vars.currentplayer->speedboost < 1.25f) {
//			g_Vars.currentplayer->speedboost += g_Vars.lvupdate240freal * 0.01f;
//		}
//
//		if (g_Vars.currentplayer->speedboost > 1.25f) {
//			piracyRestore();
//			g_Vars.currentplayer->speedboost = 1.25f;
//		}
//	} else {
//		if (g_Vars.currentplayer->speedboost > 1) {
//			g_Vars.currentplayer->speedboost -= g_Vars.lvupdate240freal * 0.01f;
//		}
//
//		if (g_Vars.currentplayer->speedboost < 1) {
//			g_Vars.currentplayer->speedboost = 1;
//		}
//	}
//
//	// Look ahead
//	// ae14
//	if (g_Vars.currentplayer->pausemode == PAUSEMODE_UNPAUSED) {
//		lookahead = -4;
//
//		offbike = g_Vars.currentplayer->bondmovemode == MOVEMODE_WALK
//			|| g_Vars.currentplayer->bondmovemode == MOVEMODE_GRAB;
//
//		if (g_Vars.currentplayer->lookaheadcentreenabled) {
//			if (g_Vars.lvframenum != g_Vars.currentplayer->lookaheadframe
//					&& g_Vars.currentplayernum == (g_Vars.lvframenum % 4)) {
//				g_Vars.currentplayer->cachedlookahead = bmoveCalculateLookahead();
//			}
//
//			lookahead = g_Vars.currentplayer->cachedlookahead;
//		}
//
//		// ae8c
//		if (g_Vars.currentplayer->movecentrerelease
//				&& movedata.analogwalk < 40 && movedata.analogwalk > -40) {
//			g_Vars.currentplayer->movecentrerelease = false;
//		}
//
//		// aeb0
//		if (offbike) {
//			if (movedata.speedvertadown > 0 || movedata.speedvertaup > 0) {
//				// aee8
//				g_Vars.currentplayer->docentreupdown = false;
//				g_Vars.currentplayer->prevupdown = true;
//				g_Vars.currentplayer->automovecentre = false;
//			} else {
//				// af08
//				if (movedata.disablelookahead) {
//					g_Vars.currentplayer->automovecentre = false;
//				} else if (g_Vars.currentplayer->automovecentreenabled) {
//					if (movedata.canlookahead && (movedata.analogwalk > 60 || movedata.analogwalk < -60)) {
//						g_Vars.currentplayer->automovecentre = true;
//					}
//
//					if (g_Vars.currentplayer->automovecentre
//							&& (g_Vars.currentplayer->vv_verta > lookahead + 5.0f || g_Vars.currentplayer->vv_verta < lookahead - 10.0f)
//							&& g_Vars.currentplayer->movecentrerelease == false) {
//						g_Vars.currentplayer->docentreupdown = true;
//					}
//				} else if (g_Vars.currentplayer->fastmovecentreenabled
//						&& movedata.canlookahead
//						&& (movedata.analogwalk > 60 || movedata.analogwalk < -60)
//						&& (g_Vars.currentplayer->vv_verta > lookahead + 5.0f || g_Vars.currentplayer->vv_verta < lookahead - 10.0f)
//						&& g_Vars.currentplayer->movecentrerelease == false) {
//					g_Vars.currentplayer->docentreupdown = true;
//				}
//
//				// b03c
//				g_Vars.currentplayer->prevupdown = false;
//			}
//		}
//
//		// b044
//		if (g_Vars.currentplayer->bondmovemode == MOVEMODE_BIKE) {
//			g_Vars.currentplayer->docentreupdown = false;
//		}
//
//		// b05c
//		if (g_Vars.currentplayer->docentreupdown) {
//			if (offbike) {
//				// Determine direction for lookahead increment
//				f32 increment = (g_Vars.currentplayer->speedverta * g_Vars.currentplayer->speedverta * 0.5f) / 0.05f;
//				f32 newverta;
//
//				// b0a8
//				if (g_Vars.currentplayer->vv_verta > lookahead + increment) {
//					bmoveUpdateSpeedVerta(1);
//				} else if (g_Vars.currentplayer->vv_verta < lookahead - increment) {
//					bmoveUpdateSpeedVerta(-1);
//				} else {
//					bmoveUpdateSpeedVerta(0);
//				}
//
//				// b100
//				// Calculate new verta
//				newverta = g_Vars.currentplayer->speedverta * g_Vars.lvupdate240freal;
//				newverta = g_Vars.currentplayer->vv_verta + newverta + newverta;
//
//				if (g_Vars.currentplayer->vv_verta > lookahead && newverta > lookahead) {
//					g_Vars.currentplayer->vv_verta = newverta;
//				} else if (g_Vars.currentplayer->vv_verta < lookahead && newverta < lookahead) {
//					g_Vars.currentplayer->vv_verta = newverta;
//				} else {
//					g_Vars.currentplayer->vv_verta = lookahead;
//					g_Vars.currentplayer->speedverta = 0;
//
//					if (g_Vars.currentplayer->prevupdown == false) {
//						g_Vars.currentplayer->docentreupdown = false;
//					}
//				}
//			}
//		} else {
//			// b190
//			if (movedata.cannaturalpitch) {
//				f32 fVar25 = movedata.analogpitch / 70.0f;
//				f32 fVar26;
//
//				if (fVar25 > 1) {
//					fVar25 = 1;
//				} else if (fVar25 < -1) {
//					fVar25 = -1;
//				}
//
//				fVar26 = fVar25 >= 0 ? fVar25 : -fVar25;
//
//				g_Vars.currentplayer->speedverta = -(fVar25 * fVar26) * (viGetFovY() / 60.0f);
//			} else if (movedata.speedvertadown > 0) {
//				bmoveUpdateSpeedVerta(movedata.speedvertadown);
//
//				if (movedata.canlookahead && (movedata.analogwalk > 60 || movedata.analogwalk < -60)) {
//					g_Vars.currentplayer->movecentrerelease = true;
//				}
//			} else if (movedata.speedvertaup > 0) {
//				bmoveUpdateSpeedVerta(-movedata.speedvertaup);
//
//				if (movedata.canlookahead && (movedata.analogwalk > 60 || movedata.analogwalk < -60)) {
//					g_Vars.currentplayer->movecentrerelease = true;
//				}
//			} else {
//				bmoveUpdateSpeedVerta(0);
//			}
//
//			g_Vars.currentplayer->vv_verta +=
//				g_Vars.currentplayer->speedverta * g_Vars.lvupdate240freal * 3.5f;
//		}
//	}
//
//	// b32c
//	if (movedata.cannaturalturn) {
//		fVar25 = movedata.analogturn / 70.0f;
//
//		if (fVar25 > 1) {
//			fVar25 = 1;
//		} else if (fVar25 < -1) {
//			fVar25 = -1;
//		}
//
//		fVar26 = fVar25 >= 0 ? fVar25 : -fVar25;
//
//		g_Vars.currentplayer->speedthetacontrol = fVar25 * fVar26 * (viGetFovY() / 60.0f);
//	} else if (movedata.aimturnleftspeed > 0) {
//		bmoveUpdateSpeedThetaControl(movedata.aimturnleftspeed);
//	} else if (movedata.aimturnrightspeed > 0) {
//		bmoveUpdateSpeedThetaControl(-movedata.aimturnrightspeed);
//	} else {
//		bmoveUpdateSpeedThetaControl(0);
//	}
//
//	// b444
//	g_Vars.currentplayer->speedtheta = g_Vars.currentplayer->speedthetacontrol;
//	bmoveUpdateSpeedTheta();
//
//	if (movedata.detonating) {
//		g_Vars.currentplayer->hands[HAND_RIGHT].mode = HANDMODE_NONE;
//		g_Vars.currentplayer->hands[HAND_RIGHT].modenext = HANDMODE_NONE;
//		playerActivateRemoteMineDetonator(g_Vars.currentplayernum);
//	}
//
//	// b478
//	cancycleweapons = true;
//
//	if (g_Vars.tickmode == TICKMODE_CUTSCENE) {
//		cancycleweapons = false;
//	}
//
//	if (g_Vars.lvframenum < 10) {
//		cancycleweapons = false;
//	}
//
//	// b4a4
//	if (cancycleweapons) {
//		while (movedata.weaponbackoffset--) {
//			bgun0f0a1c2c();
//		}
//
//		while (movedata.weaponforwardoffset--) {
//			bgun0f0a1b50();
//		}
//	}
//
//	// b50c
//	if (g_Vars.currentplayer->unk1c64) {
//		g_Vars.currentplayer->unk1c64 = 0;
//	} else /*b528*/ if (movedata.canswivelgun) {
//		bgunSetAimType(0);
//
//		// b538
//		if (
//				(
//				 movedata.canautoaim
//				 && (bmoveIsAutoAimXEnabledForCurrentWeapon() || bmoveIsAutoAimYEnabledForCurrentWeapon())
//				 && g_Vars.currentplayer->autoxaimprop
//				 && g_Vars.currentplayer->autoyaimprop
//				 && weaponHasClassFlag(weaponnum, WEAPONCLASSFLAG_AUTOAIM)
//				)
//				|| (bgunGetWeaponNum(HAND_RIGHT) == WEAPON_CMP150 && g_Vars.currentplayer->hands[HAND_RIGHT].weaponfunc == FUNC_SECONDARY)) {
//			// Auto aim - move crosshair towards target
//			s32 followlockon = false;
//
//			if (bgunGetWeaponNum(HAND_RIGHT) == WEAPON_CMP150
//					&& g_Vars.currentplayer->hands[HAND_RIGHT].weaponfunc == FUNC_SECONDARY) {
//				followlockon = true;
//			}
//
//			if (g_Vars.currentplayer->autoaimdamp > 0.963f) {
//				g_Vars.currentplayer->autoaimdamp -= g_Vars.lvupdate240freal * 0.00032f;
//			}
//
//			if (g_Vars.currentplayer->autoaimdamp < 0.963f) {
//				g_Vars.currentplayer->autoaimdamp = 0.963f;
//			}
//
//			if (followlockon) {
//				bgun0f0a0394(g_Vars.currentplayer->autoaimx, g_Vars.currentplayer->autoaimy,
//						0.915f, 0.915f);
//			} else {
//				bgunSwivelTowards(g_Vars.currentplayer->autoaimx, g_Vars.currentplayer->autoaimy,
//						g_Vars.currentplayer->autoaimdamp);
//			}
//		} else {
//			// This code moves the crosshair as the player turns and makes
//			// it return to the centre when not affected by anything else.
//			if (g_Vars.currentplayer->autoaimdamp < 0.979f) {
//				g_Vars.currentplayer->autoaimdamp += g_Vars.lvupdate240freal * 0.00032f;
//			}
//
//			if (g_Vars.currentplayer->autoaimdamp > 0.979f) {
//				g_Vars.currentplayer->autoaimdamp = 0.979f;
//			}
//
//			bgunSwivelTowards(
//					g_Vars.currentplayer->speedtheta * 0.3f + g_Vars.currentplayer->gunextraaimx,
//					-g_Vars.currentplayer->speedverta * 0.1f + g_Vars.currentplayer->gunextraaimy,
//					g_Vars.currentplayer->autoaimdamp);
//		}
//	} else if (movedata.canmanualaim) {
//		// Adjust crosshair's position on screen
//		// when holding aim and moving stick
//		bgunSetAimType(0);
//		bgun0f0a0b98(
//				(movedata.c1stickxraw * 0.65f) / 80.0f,
//				(movedata.c1stickyraw * 0.65f) / 80.0f);
//	}
//}

void bmove0f0cb79c(struct player *player, struct coord *mid, s16 *rooms)
{
	struct coord lower;
	struct coord upper;
	f32 eyeheight = g_Vars.players[propGetPlayerNum(player->prop)]->vv_eyeheight;
	f32 headheight = g_Vars.players[propGetPlayerNum(player->prop)]->vv_headheight;

	lower.x = mid->x - 50;
	lower.y = mid->y - player->crouchheight - eyeheight - 10;
	lower.z = mid->z - 50;

	upper.x = mid->x + 50;
	upper.y = mid->y - player->crouchheight - eyeheight + headheight + 10;
	upper.z = mid->z + 50;

	func0f1650d0(&lower, &upper, rooms, 7, 0);
}

void bmove0f0cb89c(struct player *player, s16 *rooms)
{
	bmove0f0cb79c(player, &player->prop->pos, rooms);
}

void bmove0f0cb8c4(struct player *player)
{
	propDeregisterRooms(player->prop);
	bmove0f0cb89c(player, player->prop->rooms);
	propRegisterRooms(player->prop);
}

void bmove0f0cb904(struct coord *arg0)
{
	if (arg0->f[0] || arg0->f[2]) {
		f32 hypotenuse = sqrtf(arg0->f[0] * arg0->f[0] + arg0->f[2] * arg0->f[2]);
		s32 i;

		if (hypotenuse > 1.5f) {
			arg0->x *= 1.5f / hypotenuse;
			arg0->z *= 1.5f / hypotenuse;
			hypotenuse = 1.5f;
		}

		for (i = 0; i < 3; i++) {
			if (hypotenuse > 0.0001f) {
				if (arg0->f[i] != 0) {
					if (arg0->f[i] > 0) {
						arg0->f[i] -= (1.0f / 30.0f) * g_Vars.lvupdate240freal * arg0->f[i] / hypotenuse;

						if (arg0->f[i] < 0) {
							arg0->f[i] = 0;
						}
					} else if (arg0->f[i] < 0) {
						arg0->f[i] -= (1.0f / 30.0f) * g_Vars.lvupdate240freal * arg0->f[i] / hypotenuse;

						if (arg0->f[i] > 0) {
							arg0->f[i] = 0;
						}
					}
				}
			} else {
				arg0->f[i] = 0;
			}
		}
	}
}

void bmove0f0cba88(f32 *a, f32 *b, struct coord *c, f32 mult1, f32 mult2)
{
	if (c->x != 0 || c->z != 0) {
		bmove0f0cb904(c);
		*a = c->z * mult2 + -c->x * mult1;
		*b = -c->x * mult2 - c->z * mult1;
	} else {
		*a = 0;
		*b = 0;
	}
}

void bmoveUpdateMoveInitSpeed(struct coord *newpos)
{
	if (g_Vars.currentplayer->moveinitspeed.x != 0) {
		if (g_Vars.currentplayer->moveinitspeed.x < 0.001f && g_Vars.currentplayer->moveinitspeed.x > -0.001f) {
			g_Vars.currentplayer->moveinitspeed.x = 0;
		} else {
			g_Vars.currentplayer->moveinitspeed.x *= 0.9f;
			newpos->x += g_Vars.currentplayer->moveinitspeed.x * g_Vars.lvupdate240freal;
		}
	}

	if (g_Vars.currentplayer->moveinitspeed.z != 0) {
		if (g_Vars.currentplayer->moveinitspeed.z < 0.001f && g_Vars.currentplayer->moveinitspeed.z > -0.001f) {
			g_Vars.currentplayer->moveinitspeed.z = 0;
		} else {
			g_Vars.currentplayer->moveinitspeed.z *= 0.9f;
			newpos->z += g_Vars.currentplayer->moveinitspeed.z * g_Vars.lvupdate240freal;
		}
	}
}

void bmoveTick(bool arg0, bool arg1, bool arg2, bool arg3)
{
	struct chrdata *chr;
	u8 foot;
	s32 sound;
	f32 xdiff;
	f32 ydiff;
	f32 zdiff;
	f32 distance;

	bmoveProcessInput(arg0, arg1, arg2, arg3);

	if (g_Vars.currentplayer->bondmovemode == MOVEMODE_BIKE) {
		bbikeTick();
	} else if (g_Vars.currentplayer->bondmovemode == MOVEMODE_GRAB) {
		bgrabTick();
	} else if (g_Vars.currentplayer->bondmovemode == MOVEMODE_CUTSCENE) {
		bcutsceneTick();
	} else if (g_Vars.currentplayer->bondmovemode == MOVEMODE_WALK) {
		bwalkTick();
	}

	// Update footstep sounds
	if ((g_Vars.currentplayer->bondmovemode == MOVEMODE_WALK || g_Vars.currentplayer->bondmovemode == MOVEMODE_GRAB)
			&& (g_Vars.currentplayer->speedforwards || g_Vars.currentplayer->speedsideways)
			&& (!g_Vars.normmplayerisrunning || PLAYERCOUNT() == 1)) {
		chr = g_Vars.currentplayer->prop->chr;

		if (g_Vars.currentplayer->cameramode == CAMERAMODE_DEFAULT
				&& g_Vars.currentplayer->bdeltapos.y >= -6.0f) {
			xdiff = g_Vars.currentplayer->bondprevpos.x - g_Vars.currentplayer->prop->pos.x;
			ydiff = g_Vars.currentplayer->bondprevpos.y - g_Vars.currentplayer->prop->pos.y;
			zdiff = g_Vars.currentplayer->bondprevpos.z - g_Vars.currentplayer->prop->pos.z;

			foot = 0;
			distance = sqrtf(xdiff * xdiff + ydiff * ydiff + zdiff * zdiff);

			g_Vars.currentplayer->footstepdist += distance;

			if (g_Vars.currentplayer->footstepdist >= 150.0f) {
				foot = 1;
				g_Vars.currentplayer->footstepdist = 0;
			}

			if (foot) {
				if (g_Vars.currentplayer->foot) {
					chr->footstep = 1;
				} else {
					chr->footstep = 2;
				}

				g_Vars.currentplayer->foot = 1 - g_Vars.currentplayer->foot;

				chr->floortype = g_Vars.currentplayer->floortype;

				sound = chrChooseFootstepSound(chr, distance > 10);

				if (sound != -1) {
					snd00010718(0, 0, 0x7fff, 0x40, sound, 1, 1, -1, 1);
				}
			}
		}
	}
}

void bmoveUpdateVerta(void)
{
	while (g_Vars.currentplayer->vv_verta < -180) {
		g_Vars.currentplayer->vv_verta += 360;
	}

	while (g_Vars.currentplayer->vv_verta >= 180) {
		g_Vars.currentplayer->vv_verta -= 360;
	}

	if (g_Vars.currentplayer->vv_verta > 90) {
		g_Vars.currentplayer->vv_verta = 90;
	} else if (g_Vars.currentplayer->vv_verta < -90) {
		g_Vars.currentplayer->vv_verta = -90;
	}

	g_Vars.currentplayer->vv_costheta = cosf(BADDEG2RAD(g_Vars.currentplayer->vv_theta));
	g_Vars.currentplayer->vv_sintheta = sinf(BADDEG2RAD(g_Vars.currentplayer->vv_theta));

	g_Vars.currentplayer->vv_verta360 = g_Vars.currentplayer->vv_verta;

	if (g_Vars.currentplayer->vv_verta360 < 0) {
		g_Vars.currentplayer->vv_verta360 += 360;
	}

	g_Vars.currentplayer->vv_cosverta = cosf(BADDEG2RAD(g_Vars.currentplayer->vv_verta360));
	g_Vars.currentplayer->vv_sinverta = sinf(BADDEG2RAD(g_Vars.currentplayer->vv_verta360));

	g_Vars.currentplayer->bond2.unk00.x = -g_Vars.currentplayer->vv_sintheta;
	g_Vars.currentplayer->bond2.unk00.y = 0;
	g_Vars.currentplayer->bond2.unk00.z = g_Vars.currentplayer->vv_costheta;

	if (g_Vars.currentplayer->prop) {
		struct chrdata *chr = g_Vars.currentplayer->prop->chr;

		if (chr && chr->model) {
			chrSetLookAngle(chr, BADDEG2RAD(360 - g_Vars.currentplayer->vv_theta));
		}
	}
}

void bmove0f0cc19c(struct coord *arg)
{
	f32 min;
	f32 mult;

	g_Vars.currentplayer->bond2.unk10.x = arg->x;
	g_Vars.currentplayer->bond2.unk10.y = arg->y;
	g_Vars.currentplayer->bond2.unk10.z = arg->z;

	if (g_Vars.currentplayer->isdead && g_Vars.currentplayer->bondleandown > 0) {
		g_Vars.currentplayer->bondleandown -= 0.25f;

		if (g_Vars.currentplayer->bondleandown < 0) {
			g_Vars.currentplayer->bondleandown = 0;
		}
	}

	if (g_Vars.currentplayer->vv_verta < 0) {
		g_Vars.currentplayer->bond2.unk10.y += -(1.0f - g_Vars.currentplayer->vv_cosverta) * g_Vars.currentplayer->bondleandown;
	}

	if (cheatIsActive(CHEAT_SMALLJO)) {
		if (g_Vars.currentplayer->bondmovemode == MOVEMODE_BIKE) {
			mult = g_Vars.currentplayer->bondentert * 0.6f + 0.4f;
		} else if (g_Vars.currentplayer->bondmovemode == MOVEMODE_WALK && g_Vars.currentplayer->walkinitmove) {
			mult = (1.0f - g_Vars.currentplayer->walkinitt) * 0.6f + 0.4f;
			g_Vars.currentplayer->bond2.unk10.y += (g_Vars.currentplayer->crouchoffsetreal - g_Vars.currentplayer->crouchoffsetrealsmall) * g_Vars.currentplayer->walkinitt;
		} else if (g_Vars.currentplayer->bondmovemode == MOVEMODE_WALK) {
			mult = 0.4f;
			g_Vars.currentplayer->bond2.unk10.y += (g_Vars.currentplayer->crouchoffsetreal - g_Vars.currentplayer->crouchoffsetrealsmall);
		} else {
			mult = 0.4f;
		}

		g_Vars.currentplayer->bond2.unk10.y = (g_Vars.currentplayer->bond2.unk10.y - g_Vars.currentplayer->vv_manground) * mult;

#if VERSION >= VERSION_NTSC_1_0
		g_Vars.currentplayer->bond2.unk10.y += g_Vars.currentplayer->vv_manground;
#else
		if (g_Vars.currentplayer->bond2.unk10.y < 30) {
			g_Vars.currentplayer->bond2.unk10.y = 30;
		}

		g_Vars.currentplayer->bond2.unk10.y += g_Vars.currentplayer->vv_ground;
#endif
	}

#if VERSION >= VERSION_NTSC_1_0
	min = g_Vars.currentplayer->vv_ground + 10;

	if (g_Vars.currentplayer->bond2.unk10.y < min) {
		g_Vars.currentplayer->bond2.unk10.y = min;
	}
#endif
}

void bmoveUpdateHead(f32 arg0, f32 arg1, f32 arg2, Mtxf *arg3, f32 arg4)
{
	f32 sp244 = 0;
	Mtxf sp180;
	Mtxf sp116;
	u32 stack;
	struct coord sp100;
	u32 stack2;
	struct coord sp84;
	f32 sp68[4];

	if (g_Vars.currentplayer->isdead == false) {
		bheadAdjustAnimation(arg0);

		if (arg0 != 0) {
			sp244 = arg1 / arg0;
		} else if (arg1 == 0) {
			arg0 = 0;
		}
	} else {
		if (g_Vars.currentplayer->startnewbonddie) {
			bheadStartDeathAnimation(g_DeathAnimations[random() % g_NumDeathAnimations], random() % 2, 0, 1);
			g_Vars.currentplayer->startnewbonddie = false;
		}

		bheadSetSpeed(0.5);
		arg2 = 0;
	}

	bheadUpdate(sp244, arg2);
	func000162e8(BADDEG2RAD(360 - g_Vars.currentplayer->vv_verta360), &sp180);

	if (optionsGetHeadRoll(g_Vars.currentplayerstats->mpindex)) {
		func00016d58(&sp116,
				0, 0, 0,
				-g_Vars.currentplayer->headlook.x, -g_Vars.currentplayer->headlook.y, -g_Vars.currentplayer->headlook.z,
				g_Vars.currentplayer->headup.x, g_Vars.currentplayer->headup.y, g_Vars.currentplayer->headup.z);
		func000159fc(&sp116, &sp180);
	}

	func00016374(BADDEG2RAD(360 - g_Vars.currentplayer->vv_theta), &sp116);
	func000159fc(&sp116, &sp180);

	if (arg3) {
		func0f097044(&sp180, &sp100);
		func0f097044(arg3, &sp84);
		func0f0976c0(&sp100, &sp84);
		func0f0972b8(&sp100, &sp84, arg4, sp68);
		func0f096ed4(sp68, &sp180);
	}

	g_Vars.currentplayer->bond2.unk1c.x = sp180.m[2][0];
	g_Vars.currentplayer->bond2.unk1c.y = sp180.m[2][1];
	g_Vars.currentplayer->bond2.unk1c.z = sp180.m[2][2];
	g_Vars.currentplayer->bond2.unk28.x = sp180.m[1][0];
	g_Vars.currentplayer->bond2.unk28.y = sp180.m[1][1];
	g_Vars.currentplayer->bond2.unk28.z = sp180.m[1][2];
}

void bmove0f0cc654(f32 arg0, f32 arg1, f32 arg2)
{
	bmoveUpdateHead(arg0, arg1, arg2, NULL, 0);
}

s32 bmoveGetCrouchPos(void)
{
	return (g_Vars.currentplayer->crouchpos < g_Vars.currentplayer->autocrouchpos)
		? g_Vars.currentplayer->crouchpos
		: g_Vars.currentplayer->autocrouchpos;
}

s32 bmoveGetCrouchPosByPlayer(s32 playernum)
{
	return (g_Vars.players[playernum]->crouchpos < g_Vars.players[playernum]->autocrouchpos)
		? g_Vars.players[playernum]->crouchpos
		: g_Vars.players[playernum]->autocrouchpos;
}
