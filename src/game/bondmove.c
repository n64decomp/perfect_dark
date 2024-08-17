#include <ultra64.h>
#include "constants.h"
#include "game/activemenu.h"
#include "game/bondbike.h"
#include "game/bondgrab.h"
#include "game/bondmove.h"
#include "game/bondwalk.h"
#include "game/cheats.h"
#include "game/chraction.h"
#include "game/footstep.h"
#include "game/game_006900.h"
#include "game/chr.h"
#include "game/prop.h"
#include "game/atan2f.h"
#include "game/quaternion.h"
#include "game/bondgun.h"
#include "game/game_0b0fd0.h"
#include "game/tex.h"
#include "game/camera.h"
#include "game/player.h"
#include "game/bondcutscene.h"
#include "game/bondhead.h"
#include "game/playermgr.h"
#include "game/bg.h"
#include "game/lv.h"
#include "game/mplayer/ingame.h"
#include "game/mplayer/mplayer.h"
#include "game/options.h"
#include "game/propobj.h"
#include "bss.h"
#include "lib/lib_17ce0.h"
#include "lib/vi.h"
#include "lib/collision.h"
#include "lib/joy.h"
#include "lib/snd.h"
#include "lib/rng.h"
#include "lib/mtx.h"
#include "lib/anim.h"
#include "data.h"
#include "types.h"

void bmove_set_control_def(u32 controldef)
{
	g_Vars.currentplayer->controldef = controldef;
}

void bmove_set_auto_move_centre_enabled(bool enabled)
{
	g_Vars.currentplayer->automovecentreenabled = enabled;
}

bool bmove_is_auto_move_centre_enabled(void)
{
	return g_Vars.currentplayer->automovecentreenabled;
}

void bmove_set_auto_aim_y(bool enabled)
{
	g_Vars.currentplayer->autoyaimenabled = enabled;
}

bool bmove_is_auto_aim_y_enabled(void)
{
	if (!g_Vars.normmplayerisrunning) {
		return g_Vars.currentplayer->autoyaimenabled;
	}

	if (g_MpSetup.options & MPOPTION_NOAUTOAIM) {
		return false;
	}

	return options_get_auto_aim(g_Vars.currentplayerstats->mpindex);
}

bool bmove_is_auto_aim_y_enabled_for_current_weapon(void)
{
	struct weaponfunc *func = current_player_get_weapon_function(0);

	if (func) {
		if (func->flags & FUNCFLAG_NOAUTOAIM) {
			return false;
		}

		if ((func->type & 0xff) == INVENTORYFUNCTYPE_MELEE) {
			return true;
		}
	}

	return bmove_is_auto_aim_y_enabled();
}

bool bmove_is_in_sight_aim_mode(void)
{
	return g_Vars.currentplayer->insightaimmode;
}

void bmove_update_auto_aim_y_prop(struct prop *prop, f32 autoaimy)
{
	if (g_Vars.currentplayer->autoyaimtime60 >= 0) {
		g_Vars.currentplayer->autoyaimtime60 -= g_Vars.lvupdate60;
	}

	if (prop != g_Vars.currentplayer->autoyaimprop) {
		if (g_Vars.currentplayer->autoyaimtime60 < 0) {
			g_Vars.currentplayer->autoyaimtime60 = TICKS(30);
			g_Vars.currentplayer->autoyaimprop = prop;
		} else {
			return;
		}
	}

	g_Vars.currentplayer->autoaimy = autoaimy;
}

void bmove_set_auto_aim_x(bool enabled)
{
	g_Vars.currentplayer->autoxaimenabled = enabled;
}

bool bmove_is_auto_aim_x_enabled(void)
{
	if (!g_Vars.normmplayerisrunning) {
		return g_Vars.currentplayer->autoxaimenabled;
	}

	if (g_MpSetup.options & MPOPTION_NOAUTOAIM) {
		return false;
	}

	return options_get_auto_aim(g_Vars.currentplayerstats->mpindex);
}

bool bmove_is_auto_aim_x_enabled_for_current_weapon(void)
{
	struct weaponfunc *func = current_player_get_weapon_function(0);

	if (func) {
		if (func->flags & FUNCFLAG_NOAUTOAIM) {
			return false;
		}

		if ((func->type & 0xff) == INVENTORYFUNCTYPE_MELEE) {
			return true;
		}
	}

	return bmove_is_auto_aim_x_enabled();
}

void bmove_update_auto_aim_x_prop(struct prop *prop, f32 autoaimx)
{
	if (g_Vars.currentplayer->autoxaimtime60 >= 0) {
		g_Vars.currentplayer->autoxaimtime60 -= g_Vars.lvupdate60;
	}

	if (prop != g_Vars.currentplayer->autoxaimprop) {
		if (g_Vars.currentplayer->autoxaimtime60 < 0) {
			g_Vars.currentplayer->autoxaimtime60 = TICKS(30);
			g_Vars.currentplayer->autoxaimprop = prop;
		} else {
			return;
		}
	}

	g_Vars.currentplayer->autoaimx = autoaimx;
}

struct prop *bmove_get_hoverbike(void)
{
	if (g_Vars.currentplayer->bondmovemode == MOVEMODE_BIKE) {
		return g_Vars.currentplayer->hoverbike;
	}

	return NULL;
}

struct prop *bmove_get_grabbed_prop(void)
{
	if (g_Vars.currentplayer->bondmovemode == MOVEMODE_GRAB) {
		return g_Vars.currentplayer->grabbedprop;
	}

	return NULL;
}

void bmove_grab_prop(struct prop *prop)
{
	struct defaultobj *obj = prop->obj;

	if ((obj->hidden & OBJHFLAG_MOUNTED) == 0 && (obj->hidden & OBJHFLAG_GRABBED) == 0) {
		g_Vars.currentplayer->grabbedprop = prop;
		bgrab_init();
	}
}

void bmove_set_mode(u32 movemode)
{
	if (g_Vars.currentplayer->bondmovemode == MOVEMODE_GRAB) {
		bgrab_exit();
	} else if (g_Vars.currentplayer->bondmovemode == MOVEMODE_BIKE) {
		bbike_exit();
	}

	if (movemode == MOVEMODE_BIKE) {
		bbike_init();
	} else if (movemode == MOVEMODE_GRAB) {
		bgrab_init();
	} else if (movemode == MOVEMODE_CUTSCENE) {
		bcutscene_init();
	} else if (movemode == MOVEMODE_WALK) {
		bwalk_init();
	}
}

void bmove_set_mode_for_all_players(u32 movemode)
{
	u32 prevplayernum = g_Vars.currentplayernum;
	s32 i;

	for (i = 0; i < PLAYERCOUNT(); i++) {
		set_current_player_num(i);
		bmove_set_mode(movemode);
	}

	set_current_player_num(prevplayernum);
}

void bmove_handle_activate(void)
{
	if (g_Vars.currentplayer->bondmovemode == MOVEMODE_BIKE) {
		bbike_handle_activate();
	} else if (g_Vars.currentplayer->bondmovemode == MOVEMODE_GRAB) {
		bgrab_handle_activate();
	} else if (g_Vars.currentplayer->bondmovemode == MOVEMODE_WALK) {
		bwalk_handle_activate();
	}
}

void bmove_apply_move_data(struct movedata *data)
{
	if (g_Vars.currentplayer->bondmovemode == MOVEMODE_BIKE) {
		bbike_apply_move_data(data);
	} else if (g_Vars.currentplayer->bondmovemode == MOVEMODE_GRAB) {
		bgrab_apply_move_data(data);
	} else if (g_Vars.currentplayer->bondmovemode == MOVEMODE_WALK) {
		bwalk_apply_move_data(data);
	}
}

void bmove_update_speed_theta(void)
{
	if (g_Vars.currentplayer->bondmovemode == MOVEMODE_BIKE) {
		// empty
	} else if (g_Vars.currentplayer->bondmovemode == MOVEMODE_GRAB) {
		bgrab_update_speed_theta();
	} else if (g_Vars.currentplayer->bondmovemode == MOVEMODE_WALK) {
		bwalk_update_speed_theta();
	}
}

f32 bmove_get_speed_verta_limit(f32 value)
{
	if (value > 0) {
		return (vi_get_fov_y() * value * -0.7f) / 60.0f;
	}

	if (value < 0) {
		return (vi_get_fov_y() * -value * 0.7f) / 60.0f;
	}

	return 0;
}

void bmove_update_speed_verta(f32 value)
{
	f32 mult = vi_get_fov_y() / 60.0f;
	f32 limit = bmove_get_speed_verta_limit(value);

	if (value > 0) {
		if (g_Vars.currentplayer->speedverta > 0) {
			g_Vars.currentplayer->speedverta -= 0.05f * g_Vars.lvupdate60freal * mult;
		} else {
			g_Vars.currentplayer->speedverta -= 0.0125f * g_Vars.lvupdate60freal * mult;
		}

		if (g_Vars.currentplayer->speedverta < limit) {
			g_Vars.currentplayer->speedverta = limit;
		}
	} else if (value < 0) {
		if (g_Vars.currentplayer->speedverta < 0) {
			g_Vars.currentplayer->speedverta += 0.05f * g_Vars.lvupdate60freal * mult;
		} else {
			g_Vars.currentplayer->speedverta += 0.0125f * g_Vars.lvupdate60freal * mult;
		}

		if (g_Vars.currentplayer->speedverta > limit) {
			g_Vars.currentplayer->speedverta = limit;
		}
	} else {
		if (g_Vars.currentplayer->speedverta > limit) {
			g_Vars.currentplayer->speedverta -= 0.05f * g_Vars.lvupdate60freal * mult;

			if (g_Vars.currentplayer->speedverta < limit) {
				g_Vars.currentplayer->speedverta = limit;
			}
		} else {
			g_Vars.currentplayer->speedverta += 0.05f * g_Vars.lvupdate60freal * mult;

			if (g_Vars.currentplayer->speedverta > limit) {
				g_Vars.currentplayer->speedverta = limit;
			}
		}
	}
}

f32 bmove_get_speed_theta_control_limit(f32 value)
{
	if (value > 0) {
		return (vi_get_fov_y() * value * -0.7f) / 60.0f;
	}

	if (value < 0) {
		return (vi_get_fov_y() * -value * 0.7f) / 60.0f;
	}

	return 0;
}

void bmove_update_speed_theta_control(f32 value)
{
	f32 mult = vi_get_fov_y() / 60.0f;
	f32 limit = bmove_get_speed_theta_control_limit(value);

	if (value > 0) {
		if (g_Vars.currentplayer->speedthetacontrol > 0) {
			g_Vars.currentplayer->speedthetacontrol -= 0.05f * g_Vars.lvupdate60freal * mult;
		} else {
			g_Vars.currentplayer->speedthetacontrol -= 0.0125f * g_Vars.lvupdate60freal * mult;
		}

		if (g_Vars.currentplayer->speedthetacontrol < limit) {
			g_Vars.currentplayer->speedthetacontrol = limit;
		}
	} else if (value < 0) {
		if (g_Vars.currentplayer->speedthetacontrol < 0.0f) {
			g_Vars.currentplayer->speedthetacontrol += 0.05f * g_Vars.lvupdate60freal * mult;
		} else {
			g_Vars.currentplayer->speedthetacontrol += 0.0125f * g_Vars.lvupdate60freal * mult;
		}

		if (g_Vars.currentplayer->speedthetacontrol > limit) {
			g_Vars.currentplayer->speedthetacontrol = limit;
		}
	} else {
		if (g_Vars.currentplayer->speedthetacontrol > limit) {
			g_Vars.currentplayer->speedthetacontrol -= 0.05f * g_Vars.lvupdate60freal * mult;

			if (g_Vars.currentplayer->speedthetacontrol < limit) {
				g_Vars.currentplayer->speedthetacontrol = limit;
			}
		} else {
			g_Vars.currentplayer->speedthetacontrol += 0.05f * g_Vars.lvupdate60freal * mult;

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
f32 bmove_calculate_lookahead(void)
{
	f32 result = -4.0f;
	f32 sp160 = 400.0f;
	f32 ground = g_Vars.currentplayer->vv_ground;
	struct coord sp150;
	f32 ymax;
	f32 ymin;
	f32 radius;
	u32 stack2;
	f32 angles[5];
	bool populated[5];
	s32 numpopulated = 0;
	u16 flags = 0;
	u32 stack3;
	struct coord sp100;
	u32 stack;
	struct coord spf0;
	RoomNum spe0[8];
	s32 i;
	f32 angle;
	f32 value;
	u32 stack4;
	u32 stack5;
	u32 stack6;
	struct coord spbc;
	struct coord spb0;
	RoomNum spa0[8];
	RoomNum sp90[8];
	RoomNum sp80[8];
	s32 j;
	f32 sp78;
	s32 indextoremove;
	f32 angletoremove;

	if (g_Vars.currentplayer->inlift) {
		return result;
	}

	player_get_bbox(g_Vars.currentplayer->prop, &radius, &ymax, &ymin);

	sp100.x = g_Vars.currentplayer->bond2.unk00.x;
	sp100.y = g_Vars.currentplayer->bond2.unk00.y;
	sp100.z = g_Vars.currentplayer->bond2.unk00.z;

	spf0.x = g_Vars.currentplayer->prop->pos.x;
	spf0.y = g_Vars.currentplayer->prop->pos.y - 30;
	spf0.z = g_Vars.currentplayer->prop->pos.z;

	portal_find_rooms(&g_Vars.currentplayer->prop->pos, &spf0,
			g_Vars.currentplayer->prop->rooms, spe0, NULL, 0);

	sp150.x = sp100.x * 400 + spf0.x;
	sp150.y = sp100.y * 400 + spf0.y;
	sp150.z = sp100.z * 400 + spf0.z;

	if (cd_exam_los08(&spf0, spe0, &sp150,
				CDTYPE_BG | CDTYPE_CLOSEDDOORS,
				GEOFLAG_FLOOR1 | GEOFLAG_FLOOR2 | GEOFLAG_WALL | GEOFLAG_BLOCK_SIGHT) == CDRESULT_COLLISION) {
		cd_get_pos(&sp150, 455, "bondmove.c");
		flags = cd_get_geo_flags();

		sp160 = sqrtf((sp150.x - spf0.x) * (sp150.x - spf0.x)
				+ (sp150.y - spf0.y) * (sp150.y - spf0.y)
				+ (sp150.z - spf0.z) * (sp150.z - spf0.z));
	}

	if (sp160 > 60.0f || (flags & GEOFLAG_FLOOR1)) {
		for (i = 0; i < ARRAYCOUNT(populated); i++) {
			populated[i] = false;
			value = (i + 1) * sp160 * 0.2f;

			spbc.x = sp100.x * value + spf0.x;
			spbc.y = sp100.y * value + spf0.y;
			spbc.z = sp100.z * value + spf0.z;

			portal_find_rooms(&spf0, &spbc, spe0, spa0, NULL, 0);

			spb0.x = spbc.x;
			spb0.y = spbc.y - 400;
			spb0.z = spbc.z;

			portal_find_rooms(&spbc, &spb0, spa0, sp90, sp80, 7);

			if (
#if VERSION >= VERSION_NTSC_1_0
					cd_find_floor_room_y_colour_flags_at_pos(&spbc, sp80, &sp78, NULL, NULL) > 0
#else
					cd_find_floor_room_y_colour_flags_at_pos(&spbc, sp80, &sp78, NULL) > 0
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

			for (j = 0; j < ARRAYCOUNT(populated); j++) {
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

		for (i = 0; i < ARRAYCOUNT(populated); i++) {
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

void bmove_reset_move_data(struct movedata *data)
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
	data->aiming = false;
	data->zooming = false;
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
	data->invertpitch = !options_get_forward_pitch(g_Vars.currentplayerstats->mpindex);
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

/**
 * Called with these arguments:
 * 0, 0, 0, 1 = tickmode 6
 * 0, 0, 0, 1 = eyespy
 * 0, 0, 0, 1 = teleportstate 3
 * 0, 0, 0, 1 = slayerrocket
 * 0, 0, 0, 1 = tickmode normal without control
 * 1, 1, ?, 0 = tickmode normal with control
 * 1, 1, ?, 0 = tickmodes 0 and 5
 * 0, 0, 0, 1 = tickmode mpswirl
 * 0, 0, 0, 1 = tickmode warp
 * 1, 1, 0, 1 = autowalk
 */
void bmove_process_input(bool allowc1x, bool allowc1y, bool allowc1buttons, bool ignorec2)
{
	struct movedata movedata;
	s32 controlmode;
	s32 weaponnum;
	bool canmanualzoom;
	s32 result;
	u16 c1buttons;
	u16 c1buttonsthisframe;
	u16 c1allowedbuttons;
	u16 c1inhibitedbuttons;
	u32 aimonhist[20];
	u32 aimoffhist[20];
	s32 numsamples;
	f32 tmp;
	f32 fVar25;
	s8 shootpad;
	s8 aimpad;
	u16 aimallowedbuttons;
	u16 shootallowedbuttons;
	s8 c2stickx;
	u16 c2buttons;
	u16 c2buttonsthisframe;
	s32 i;
	s32 tmpc2sticky;
	u16 c2allowedbuttons;
	s32 tmpc2stickx;
	s32 c2sticky;
	u16 shootbuttons;
	u16 aimbuttons;
	u16 invbuttons;
	bool zoomout;
	bool zoomin;
	f32 increment;
	f32 savedverta;
	f32 noiseradius;
	f32 zoomfov;
	f32 eraserfov;
	struct coord spa0;
	f32 crosspos[2];
	f32 lookahead;
	s8 contpad1;
	s8 contpad2;
	s8 c1stickx;
	s8 c1sticky;
	u16 inhibitedbuttons;
	bool offbike;
	bool cancycleweapons;
	u32 stack;
	f32 increment2;
	f32 newverta;

	controlmode = options_get_control_mode(g_Vars.currentplayerstats->mpindex);
	weaponnum = bgun_get_weapon_num(HAND_RIGHT);
	canmanualzoom = weapon_has_aim_flag(weaponnum, INVAIMFLAG_MANUALZOOM);
	contpad1 = options_get_contpad_num1(g_Vars.currentplayerstats->mpindex);

	c1stickx = allowc1x ? joy_get_stick_x(contpad1) : 0;
	c1sticky = allowc1y ? joy_get_stick_y(contpad1) : 0;

	c1buttons = allowc1buttons ? joy_get_buttons(contpad1, 0xffff) : 0;
	c1buttonsthisframe = allowc1buttons ? joy_get_buttons_pressed_this_frame(contpad1, 0xffff) : 0;

	c1allowedbuttons = 0xffff;

	if (g_Vars.currentplayer->joybutinhibit & 0xffff) {
		inhibitedbuttons = g_Vars.currentplayer->joybutinhibit & 0xffff;
		c1allowedbuttons = ~inhibitedbuttons;
		inhibitedbuttons = joy_get_buttons(contpad1, 0xffff) & inhibitedbuttons;
		c1buttons &= ~inhibitedbuttons;
		c1buttonsthisframe &= ~inhibitedbuttons;
		g_Vars.currentplayer->joybutinhibit = (g_Vars.currentplayer->joybutinhibit & 0xffff0000) | inhibitedbuttons;
	}

	numsamples = joy_get_num_samples();
	bmove_reset_move_data(&movedata);

	if (c1stickx < -5) {
		movedata.c1stickxsafe = c1stickx + 5;
	} else if (c1stickx > 5) {
		movedata.c1stickxsafe = c1stickx - 5;
	} else {
		movedata.c1stickxsafe = 0;
	}

	if (c1sticky < -5) {
		movedata.c1stickysafe = c1sticky + 5;
	} else if (c1sticky > 5) {
		movedata.c1stickysafe = c1sticky - 5;
	} else {
		movedata.c1stickysafe = 0;
	}

	movedata.c1stickxraw = c1stickx;
	movedata.c1stickyraw = c1sticky;

	// These are zeroed further down conditionally on control style
	movedata.analogturn = movedata.c1stickxsafe;
	movedata.analogstrafe = movedata.c1stickxsafe;
	movedata.analogpitch = movedata.c1stickysafe;
	movedata.analogwalk = movedata.c1stickysafe;

	// Pausing
	if (g_Vars.currentplayer->isdead == false) {
		if (g_Vars.currentplayer->pausemode == PAUSEMODE_UNPAUSED && (c1buttonsthisframe & START_BUTTON)) {
			if (g_Vars.mplayerisrunning == false) {
				if (g_Vars.lvframenum > 15) {
					player_pause(MENUROOT_MAINMENU);
				}
			} else {
				mp_push_pause_dialog();
			}
		}
	} else {
		if (g_Vars.mplayerisrunning) {
			if (PLAYERCOUNT() == 1) {
				if (mp_is_paused() && (c1buttonsthisframe & START_BUTTON) && g_MpSetup.paused != MPPAUSEMODE_GAMEOVER) {
					mp_set_paused(MPPAUSEMODE_UNPAUSED);
				}
			} else {
				if (mp_is_paused() && (c1buttonsthisframe & START_BUTTON)) {
					mp_push_pause_dialog();
				}
			}
		}
	}

	if (g_Vars.currentplayer->pausemode == PAUSEMODE_UNPAUSED) {
		if (g_Vars.currentplayer->isdead == false) {
			if (controlmode == CONTROLMODE_23 || controlmode == CONTROLMODE_24 || controlmode == CONTROLMODE_22 || controlmode == CONTROLMODE_21) {
				// 2.1: ctrl1 stick = walk/turn, z = fire, ctrl2 stick = look/strafe, z = aim
				// 2.2: ctrl1 stick = look,      z = fire, ctrl2 stick = walk/strafe, z = aim
				// 2.3: ctrl1 stick = walk/turn, z = aim,  ctrl2 stick = look/strafe, z = fire
				// 2.4: ctrl1 stick = look,      z = aim,  ctrl2 stick = walk/strafe, z = fire
				contpad2 = (s8) options_get_contpad_num2(g_Vars.currentplayerstats->mpindex);
				c2stickx = (s8) joy_get_stick_x(contpad2);
				c2sticky = (joy_get_stick_y(contpad2) << 24) >> 24;
				c2buttons = joy_get_buttons(contpad2, 0xffff);
				c2buttonsthisframe = joy_get_buttons_pressed_this_frame(contpad2, 0xffff);

				tmpc2stickx = c2stickx;
				tmpc2sticky = c2sticky;

				c2allowedbuttons = 0xffff;

				if (g_Vars.currentplayer->joybutinhibit << 0 >> 16) {
					inhibitedbuttons = g_Vars.currentplayer->joybutinhibit >> 16;
					c2allowedbuttons = ~inhibitedbuttons;
					inhibitedbuttons = joy_get_buttons(contpad2, 0xffff) & inhibitedbuttons;
					c2buttons &= ~inhibitedbuttons;
					c2buttonsthisframe &= ~inhibitedbuttons;
					g_Vars.currentplayer->joybutinhibit = (g_Vars.currentplayer->joybutinhibit & 0xffff) | (inhibitedbuttons << 16);
				}

				if (ignorec2) {
					c2stickx = 0;
					c2buttons = 0;
					tmpc2stickx = 0;
					tmpc2sticky = 0;
					c2buttonsthisframe = 0;
				}

				if (tmpc2stickx < -5) {
					tmpc2stickx += 5;
				} else if (tmpc2stickx > 5) {
					tmpc2stickx -= 5;
				} else {
					tmpc2stickx = 0;
				}

				if (tmpc2sticky < -5) {
					tmpc2sticky += 5;
				} else if (tmpc2sticky > 5) {
					tmpc2sticky -= 5;
				} else {
					tmpc2sticky = 0;
				}

				if (controlmode == CONTROLMODE_21 || controlmode == CONTROLMODE_23) {
					movedata.analogstrafe = tmpc2stickx;
					movedata.analogpitch = tmpc2sticky;
				} else {
					movedata.analogstrafe = tmpc2stickx;
					movedata.analogwalk = tmpc2sticky;
				}

				c2sticky = tmpc2sticky;

				if (g_Vars.tickmode == TICKMODE_AUTOWALK) {
					movedata.digitalstepforward = false;
					movedata.digitalstepback = false;
					movedata.analogstrafe = 0;
					movedata.analogwalk = g_Vars.currentplayer->autocontrol_y;
					movedata.analogturn = g_Vars.currentplayer->autocontrol_x;
					movedata.analogpitch = 0;
				}

				if (controlmode == CONTROLMODE_21 || controlmode == CONTROLMODE_22) {
					aimpad = contpad2;
					shootpad = contpad1;
					aimallowedbuttons = c2allowedbuttons;
					shootallowedbuttons = c1allowedbuttons;
				} else {
					aimpad = contpad1;
					shootpad = contpad2;
					aimallowedbuttons = c1allowedbuttons;
					shootallowedbuttons = c2allowedbuttons;
				}

				if (options_get_aim_control(g_Vars.currentplayerstats->mpindex) == AIMCONTROL_HOLD) {
					for (i = 0; i < numsamples; i++) {
						aimonhist[i] = allowc1buttons && joy_get_buttons_on_sample(i, aimpad, aimallowedbuttons & Z_TRIG);
						aimoffhist[i] = !aimonhist[i];
					}

					g_Vars.currentplayer->insightaimmode = aimonhist[numsamples - 1];
				}

				if (!lv_is_paused()) {
					// Handle aiming
					if (options_get_aim_control(g_Vars.currentplayerstats->mpindex) != AIMCONTROL_HOLD) {
						for (i = 0; i < numsamples; i++) {
							if (allowc1buttons && joy_get_buttons_pressed_on_sample(i, aimpad, aimallowedbuttons & Z_TRIG)) {
								g_Vars.currentplayer->insightaimmode = !g_Vars.currentplayer->insightaimmode;
							}

							aimonhist[i] = g_Vars.currentplayer->insightaimmode;
							aimoffhist[i] = !aimonhist[i];
						}
					}

					if (bgun_get_weapon_num(HAND_RIGHT) == WEAPON_HORIZONSCANNER) {
						g_Vars.currentplayer->insightaimmode = true;
					}

					movedata.canswivelgun = !g_Vars.currentplayer->insightaimmode;
					movedata.canmanualaim = g_Vars.currentplayer->insightaimmode;
					movedata.canautoaim = !g_Vars.currentplayer->insightaimmode;
					movedata.digitalstepforward = false;
					movedata.digitalstepback = false;
					movedata.digitalstepleft = false;
					movedata.digitalstepright = false;
					movedata.canlookahead = !g_Vars.currentplayer->insightaimmode;
					movedata.unk14 = 1;
					movedata.cannaturalturn = !g_Vars.currentplayer->insightaimmode;
					movedata.cannaturalpitch = !g_Vars.currentplayer->insightaimmode;

					// Handle turning while aiming
					if (g_Vars.currentplayer->insightaimmode && movedata.c1stickyraw > 60) {
						movedata.speedvertadown = (movedata.c1stickyraw - 60) / 10.0f;

						if (movedata.speedvertadown > 1) {
							movedata.speedvertadown = 1;
						}
					} else {
						movedata.speedvertadown = 0;
					}

					if (g_Vars.currentplayer->insightaimmode && movedata.c1stickyraw < -60) {
						movedata.speedvertaup = (-60 - movedata.c1stickyraw) / 10.0f;

						if (movedata.speedvertaup > 1) {
							movedata.speedvertaup = 1;
						}
					} else {
						movedata.speedvertaup = 0;
					}

					if (g_Vars.currentplayer->insightaimmode && movedata.c1stickxraw < -60) {
						movedata.aimturnleftspeed = (-60 - movedata.c1stickxraw) / 10.0f;

						if (movedata.aimturnleftspeed > 1) {
							movedata.aimturnleftspeed = 1;
						}
					} else {
						movedata.aimturnleftspeed = 0;
					}

					if (g_Vars.currentplayer->insightaimmode && movedata.c1stickxraw > 60) {
						movedata.aimturnrightspeed = (movedata.c1stickxraw - 60) / 10.0f;

						if (movedata.aimturnrightspeed > 1) {
							movedata.aimturnrightspeed = 1;
						}
					} else {
						movedata.aimturnrightspeed = 0;
					}

					// Handle weapon switching
					if (allowc1buttons) {
						if (g_Vars.currentplayer->invdowntime < -2) {
							g_Vars.currentplayer->invdowntime += numsamples;

							if (g_Vars.currentplayer->invdowntime > -3) {
								g_Vars.currentplayer->invdowntime = 0;
							}
						} else {
							for (i = 0; i < numsamples; i++) {
								if (joy_get_buttons_on_sample(i, contpad1, c1allowedbuttons & A_BUTTON)
										|| joy_get_buttons_on_sample(i, contpad2, c2allowedbuttons & A_BUTTON)) {
									if (g_Vars.currentplayer->invdowntime > -2) {
										if (joy_get_buttons_pressed_on_sample(i, shootpad, shootallowedbuttons & Z_TRIG)) {
											movedata.weaponbackoffset++;
											g_Vars.currentplayer->invdowntime = -1;
										}

										if (g_Vars.currentplayer->invdowntime > -1
												&& joy_get_buttons_on_sample(i, shootpad, shootallowedbuttons & Z_TRIG) == 0) {
											if (g_Vars.currentplayer->invdowntime > TICKS(15)) {
												am_open();
												g_Vars.currentplayer->invdowntime = -1;
											} else {
												g_Vars.currentplayer->invdowntime++;
											}
										}
									}
								} else {
									if (g_Vars.currentplayer->invdowntime > 0 &&
											(!allowc1buttons || joy_get_buttons_on_sample(i, shootpad, shootallowedbuttons & Z_TRIG) == 0)) {
										movedata.weaponforwardoffset++;
									}

									g_Vars.currentplayer->invdowntime = 0;
								}
							}
						}
					}

					// Handle B button activation
					if (allowc1buttons) {
						for (i = 0; i < numsamples; i++) {
							if (joy_get_buttons_on_sample(i, contpad1, c1allowedbuttons & B_BUTTON)
									|| joy_get_buttons_on_sample(i, contpad2, c2allowedbuttons & B_BUTTON)) {
								if (g_Vars.currentplayer->usedowntime >= -1) {
									if (joy_get_buttons_pressed_on_sample(i, shootpad, shootallowedbuttons & Z_TRIG)
											&& g_Vars.currentplayer->usedowntime > -1
											&& bgun_consider_toggle_gun_function(g_Vars.currentplayer->usedowntime, true, false) != USETIMER_CONTINUE) {
										g_Vars.currentplayer->usedowntime = -3;
									}

									if (g_Vars.currentplayer->usedowntime > -1) {
										if (g_Vars.currentplayer->usedowntime > TICKS(25)) {
											result = bgun_consider_toggle_gun_function(g_Vars.currentplayer->usedowntime, false, false);

											if (result == USETIMER_STOP) {
												g_Vars.currentplayer->usedowntime = -1;
											} else if (result == USETIMER_REPEAT) {
												g_Vars.currentplayer->usedowntime = -2;
											} else {
												g_Vars.currentplayer->usedowntime++;
											}
										} else {
											g_Vars.currentplayer->usedowntime++;
										}
									}
								} else if (g_Vars.currentplayer->usedowntime >= -2) {
									bgun_consider_toggle_gun_function(g_Vars.currentplayer->usedowntime, false, false);
								}
							} else {
								// Released B - activate or reload
								if (g_Vars.currentplayer->usedowntime > 0) {
									movedata.btapcount++;
								}

								g_Vars.currentplayer->usedowntime = 0;
								bgun0f0a8c50();
							}
						}
					}

					// Handle manual zoom in and out (sniper, farsight and horizon scanner)
					if (canmanualzoom && g_Vars.currentplayer->insightaimmode) {
						if (c2sticky < 0) {
							movedata.zoomoutfovpersec = -c2sticky / 70.0f;

							if (movedata.zoomoutfovpersec > 1) {
								movedata.zoomoutfovpersec = 1;
							}

							movedata.zoomoutfovpersec = movedata.zoomoutfovpersec + movedata.zoomoutfovpersec;
						}

						if (c2sticky > 0) {
							movedata.zoominfovpersec = c2sticky / 70.0f;

							if (movedata.zoominfovpersec > 1) {
								movedata.zoominfovpersec = 1;
							}

							movedata.zoominfovpersec = movedata.zoominfovpersec + movedata.zoominfovpersec;
						}
					}

					// Handle crouch and uncrouch
					if (allowc1buttons) {
						for (i = 0; i < numsamples; i++) {
							if (!canmanualzoom && aimonhist[i]) {
								if (joy_get_stick_y_on_sample(i, contpad2) > 30 && joy_get_stick_y_on_sample_index(i, contpad2) <= 30) {
									if (movedata.crouchdown) {
										movedata.crouchdown--;
									} else {
										movedata.crouchup++;
									}

									g_Vars.currentplayer->aimtaptime = -1;
								}

								if (joy_get_stick_y_on_sample(i, contpad2) < -30 && joy_get_stick_y_on_sample_index(i, contpad2) >= -30) {
									if (movedata.crouchup) {
										movedata.crouchup--;
									} else {
										movedata.crouchdown++;
									}

									g_Vars.currentplayer->aimtaptime = -1;
								}
							}

							if (options_get_aim_control(g_Vars.currentplayerstats->mpindex) == AIMCONTROL_HOLD) {
								if (aimonhist[i]) {
									if (g_Vars.currentplayer->aimtaptime > -1) {
										g_Vars.currentplayer->aimtaptime++;
									}
								} else {
									if (g_Vars.currentplayer->aimtaptime > 0
											&& g_Vars.currentplayer->aimtaptime < TICKS(15)) {
										if (movedata.crouchdown) {
											movedata.crouchdown--;
										} else {
											movedata.crouchup++;
										}
									}

									g_Vars.currentplayer->aimtaptime = 0;
								}
							}
						}
					}

					// Handle shutting eyes in multiplayer
					if (bmove_get_crouch_pos() == CROUCHPOS_SQUAT
							&& g_Vars.currentplayer->crouchoffset == -90
							&& g_Vars.mplayerisrunning
							&& g_Vars.coopplayernum < 0) {
						movedata.eyesshut = g_Vars.currentplayer->insightaimmode
							&& !canmanualzoom
							&& joy_get_stick_y(contpad2) < -30;
					}

					if (bgun_get_weapon_num(HAND_RIGHT) == WEAPON_FARSIGHT) {
						if (g_Vars.currentplayer->insightaimmode) {
							movedata.unk14 = 0;
						}

						movedata.farsighttempautoseek = g_Vars.currentplayer->insightaimmode
							&& (c2stickx < -30 || c2stickx > 30);
					}

					movedata.rleanleft = false;
					movedata.rleanright = false;

					// Handle mine detonation
					if ((((c1buttons & A_BUTTON) && (c1buttonsthisframe & B_BUTTON))
								|| ((c1buttons & B_BUTTON) && (c1buttonsthisframe & A_BUTTON))
								|| ((c2buttons & A_BUTTON) && (c2buttonsthisframe & B_BUTTON))
								|| ((c2buttons & B_BUTTON) && (c2buttonsthisframe & A_BUTTON)))
							&& weaponnum == WEAPON_REMOTEMINE) {
						movedata.detonating = true;
						movedata.weaponbackoffset = 0;
						movedata.weaponforwardoffset = 0;
						movedata.btapcount = 0;
						g_Vars.currentplayer->invdowntime = -2;
						g_Vars.currentplayer->usedowntime = -2;
					}
				}

				movedata.aiming = g_Vars.currentplayer->insightaimmode;
				movedata.zooming = g_Vars.currentplayer->insightaimmode;

				if (g_Vars.currentplayer->waitforzrelease
						&& joy_get_buttons(shootpad, shootallowedbuttons & Z_TRIG) == 0) {
					g_Vars.currentplayer->waitforzrelease = false;
				}

				if (weapon_has_flag(bgun_get_weapon_num(HAND_RIGHT), WEAPONFLAG_FIRETOACTIVATE)) {
					if (allowc1buttons
							&& joy_get_buttons_pressed_this_frame(shootpad, shootallowedbuttons & Z_TRIG)
							&& g_Vars.currentplayer->pausemode == PAUSEMODE_UNPAUSED) {
						movedata.btapcount++;
					}
				} else {
					movedata.triggeron = g_Vars.currentplayer->waitforzrelease == false
						&& allowc1buttons
						&& joy_get_buttons(shootpad, shootallowedbuttons & Z_TRIG)
						&& g_Vars.currentplayer->pausemode == PAUSEMODE_UNPAUSED
						&& (c1buttons & A_BUTTON) == 0
						&& (c2buttons & A_BUTTON) == 0;
				}

				movedata.disablelookahead = true;
			} else {
				// 1.x control style
				if (controlmode == CONTROLMODE_13 || controlmode == CONTROLMODE_14) {
					shootbuttons = A_BUTTON;
					aimbuttons = Z_TRIG;
					invbuttons = L_TRIG | R_TRIG;
				} else {
					shootbuttons = Z_TRIG;
					aimbuttons = L_TRIG | R_TRIG;
					invbuttons = A_BUTTON;
				}

				if (options_get_aim_control(g_Vars.currentplayerstats->mpindex) == AIMCONTROL_HOLD) {
					for (i = 0; i < numsamples; i++) {
						aimonhist[i] = allowc1buttons && joy_get_buttons_on_sample(i, contpad1, aimbuttons & c1allowedbuttons);
						aimoffhist[i] = !aimonhist[i];
					}

					g_Vars.currentplayer->insightaimmode = aimonhist[numsamples - 1];
				}

				if (!lv_is_paused()) {
					// Handle aiming
					if (options_get_aim_control(g_Vars.currentplayerstats->mpindex) != AIMCONTROL_HOLD) {
						for (i = 0; i < numsamples; i++) {
							if (allowc1buttons && joy_get_buttons_pressed_on_sample(i, contpad1, aimbuttons & c1allowedbuttons)) {
								g_Vars.currentplayer->insightaimmode = !g_Vars.currentplayer->insightaimmode;
							}

							aimonhist[i] = g_Vars.currentplayer->insightaimmode;
							aimoffhist[i] = !aimonhist[i];
						}
					}

					if (bgun_get_weapon_num(HAND_RIGHT) == WEAPON_HORIZONSCANNER) {
						g_Vars.currentplayer->insightaimmode = true;
					}

					movedata.canswivelgun = !g_Vars.currentplayer->insightaimmode;
					movedata.canmanualaim = g_Vars.currentplayer->insightaimmode;
					movedata.canautoaim = !g_Vars.currentplayer->insightaimmode;

					if (controlmode == CONTROLMODE_12 || controlmode == CONTROLMODE_14) {
						// Handle side stepping
						if (g_Vars.currentplayer->insightaimmode == false) {
							if (allowc1buttons) {
								movedata.digitalstepleft = joy_count_buttons_on_specific_samples(aimoffhist, contpad1, c1allowedbuttons & (L_JPAD | L_CBUTTONS));
								movedata.digitalstepright = joy_count_buttons_on_specific_samples(aimoffhist, contpad1, c1allowedbuttons & (R_JPAD | R_CBUTTONS));
							}
						} else {
							// This doesn't appear to be r-leaning.
							// R-leaning still works when these are commented.
							if (c1buttons & (L_JPAD | L_CBUTTONS)) {
								movedata.unk30 = 1;
							}

							if (c1buttons & (R_JPAD | R_CBUTTONS)) {
								movedata.unk34 = 1;
							}
						}

						movedata.digitalstepforward = !g_Vars.currentplayer->insightaimmode && (c1buttons & (U_JPAD | U_CBUTTONS));
						movedata.digitalstepback = !g_Vars.currentplayer->insightaimmode && (c1buttons & (D_JPAD | D_CBUTTONS));
						movedata.canlookahead = false;
						movedata.cannaturalpitch = !g_Vars.currentplayer->insightaimmode;
						movedata.speedvertadown = 0;
						movedata.speedvertaup = 0;
						movedata.cannaturalturn = !g_Vars.currentplayer->insightaimmode;

						if (g_Vars.tickmode == TICKMODE_AUTOWALK) {
							movedata.digitalstepforward = (g_Vars.currentplayer->autocontrol_y > 0);
							movedata.digitalstepback = (g_Vars.currentplayer->autocontrol_y < 0);
							movedata.analogstrafe = 0;
							movedata.analogwalk = 0;
							movedata.analogturn = g_Vars.currentplayer->autocontrol_x;
							movedata.analogpitch = 0;
						}
					} else {
						// 1.1 or 1.3
						if (c1buttons & (L_JPAD | L_CBUTTONS)) {
							movedata.unk30 = 1;
						}

						if (c1buttons & (R_JPAD | R_CBUTTONS)) {
							movedata.unk34 = 1;
						}

						if (!g_Vars.currentplayer->insightaimmode && allowc1buttons) {
							movedata.digitalstepleft = joy_count_buttons_on_specific_samples(aimoffhist, contpad1, c1allowedbuttons & (L_JPAD | L_CBUTTONS));
							movedata.digitalstepright = joy_count_buttons_on_specific_samples(aimoffhist, contpad1, c1allowedbuttons & (R_JPAD | R_CBUTTONS));
						}

						movedata.digitalstepforward = false;
						movedata.digitalstepback = false;
						movedata.canlookahead = !g_Vars.currentplayer->insightaimmode;
						movedata.cannaturalpitch = false;

						// Looking up/down
						if (!g_Vars.currentplayer->insightaimmode && (c1buttons & (U_JPAD | U_CBUTTONS))) {
							movedata.speedvertadown = 1;
						}

						if (!g_Vars.currentplayer->insightaimmode && (c1buttons & (D_JPAD | D_CBUTTONS))) {
							movedata.speedvertaup = 1;
						}

						movedata.cannaturalturn = !g_Vars.currentplayer->insightaimmode;
						movedata.unk14 = 0;

						if (g_Vars.tickmode == TICKMODE_AUTOWALK) {
							movedata.analogstrafe = 0;
							movedata.analogwalk = g_Vars.currentplayer->autocontrol_y;
							movedata.analogturn = g_Vars.currentplayer->autocontrol_x;
							movedata.analogpitch = 0;
						}
					}

					// Handle looking up/down while aiming
					if (g_Vars.currentplayer->insightaimmode && movedata.c1stickyraw > 60) {
						movedata.speedvertadown = (movedata.c1stickyraw - 60) / 10.0f;

						if (movedata.speedvertadown > 1) {
							movedata.speedvertadown = 1;
						}
					} else if (g_Vars.currentplayer->insightaimmode && movedata.c1stickyraw < -60) {
						movedata.speedvertaup = (-60 - movedata.c1stickyraw) / 10.0f;

						if (movedata.speedvertaup > 1) {
							movedata.speedvertaup = 1;
						}
					}

					// Handle looking left/right while aiming
					if (g_Vars.currentplayer->insightaimmode && movedata.c1stickxraw < -60) {
						movedata.aimturnleftspeed = (-60 - movedata.c1stickxraw) / 10.0f;

						if (movedata.aimturnleftspeed > 1) {
							movedata.aimturnleftspeed = 1;
						}
					} else if (g_Vars.currentplayer->insightaimmode && movedata.c1stickxraw > 60) {
						movedata.aimturnrightspeed = (movedata.c1stickxraw - 60) / 10.0f;

						if (movedata.aimturnrightspeed > 1) {
							movedata.aimturnrightspeed = 1;
						}
					}

					// Handle A button
					if (allowc1buttons) {
						if (g_Vars.currentplayer->invdowntime < -2) {
							g_Vars.currentplayer->invdowntime += numsamples;

							if (g_Vars.currentplayer->invdowntime > -3) {
								g_Vars.currentplayer->invdowntime = 0;
							}
						} else {
							for (i = 0; i < numsamples; i++) {
								if (joy_get_buttons_on_sample(i, contpad1, invbuttons & c1allowedbuttons)) {
									if (g_Vars.currentplayer->invdowntime > -2) {
										if (joy_get_buttons_pressed_on_sample(i, contpad1, shootbuttons & c1allowedbuttons)) {
											movedata.weaponbackoffset++;
											g_Vars.currentplayer->invdowntime = -1;
										}

										if (g_Vars.currentplayer->invdowntime >= 0 && joy_get_buttons_on_sample(i, contpad1, shootbuttons & c1allowedbuttons) == 0) {
											// Holding A and haven't pressed Z
											if (g_Vars.currentplayer->invdowntime > TICKS(15)) {
												am_open();
												g_Vars.currentplayer->invdowntime = -1;
											} else {
												g_Vars.currentplayer->invdowntime++;
											}
										}
									}
								} else {
									// Wasn't holding A on this sample
									if (g_Vars.currentplayer->invdowntime > 0 &&
											(!allowc1buttons || joy_get_buttons_on_sample(i, contpad1, shootbuttons & c1allowedbuttons) == 0)) {
										// But was on previous sample, so cycle weapon
										movedata.weaponforwardoffset++;
									}

									g_Vars.currentplayer->invdowntime = 0;
								}
							}
						}
					}

					// Handle B button
					if (allowc1buttons) {
						for (i = 0; i < numsamples; i++) {
							if (joy_get_buttons_on_sample(i, contpad1, c1allowedbuttons & B_BUTTON)) {
								if (g_Vars.currentplayer->usedowntime >= -1) {
									if (joy_get_buttons_pressed_on_sample(i, contpad1, shootbuttons & c1allowedbuttons)
											&& g_Vars.currentplayer->usedowntime >= 0
											&& bgun_consider_toggle_gun_function(g_Vars.currentplayer->usedowntime, true, false) != USETIMER_CONTINUE) {
										g_Vars.currentplayer->usedowntime = -3;
									}

									if (g_Vars.currentplayer->usedowntime >= 0) {
										if (g_Vars.currentplayer->usedowntime > TICKS(25)) {
											s32 result = bgun_consider_toggle_gun_function(g_Vars.currentplayer->usedowntime, false, false);

											if (result == USETIMER_STOP) {
												g_Vars.currentplayer->usedowntime = -1;
											} else if (result == USETIMER_REPEAT) {
												g_Vars.currentplayer->usedowntime = -2;
											} else {
												g_Vars.currentplayer->usedowntime++;
											}
										} else {
											g_Vars.currentplayer->usedowntime++;
										}
									}
								} else {
									if (g_Vars.currentplayer->usedowntime >= -2) {
										bgun_consider_toggle_gun_function(g_Vars.currentplayer->usedowntime, false, false);
									}
								}
							} else {
								// Released B
								if (g_Vars.currentplayer->usedowntime > 0) {
									movedata.btapcount++;
								}

								g_Vars.currentplayer->usedowntime = 0;
								bgun0f0a8c50();
							}
						}
					}

					// Handle manual zoom in and out (sniper, farsight and horizon scanner)
					if (canmanualzoom && g_Vars.currentplayer->insightaimmode) {
						increment = 1;
						zoomout = c1buttons & (D_JPAD | D_CBUTTONS);
						zoomin = c1buttons & (U_JPAD | U_CBUTTONS);

						// @bug? Should this be HAND_RIGHT?
						if (bgun_get_weapon_num(HAND_LEFT) == WEAPON_FARSIGHT) {
							increment = 0.5f;
						}

						if (zoomout) {
							movedata.zoomoutfovpersec = increment;
						}

						if (zoomin) {
							movedata.zoominfovpersec = increment;
						}
					}

					// Handle crouch and uncrouch
					if (allowc1buttons) {
						for (i = 0; i < numsamples; i++) {
							if (!canmanualzoom && aimonhist[i]) {
								if (joy_get_buttons_pressed_on_sample(i, contpad1, c1allowedbuttons & (U_JPAD | U_CBUTTONS))) {
									if (movedata.crouchdown) {
										movedata.crouchdown--;
									} else {
										movedata.crouchup++;
									}

									g_Vars.currentplayer->aimtaptime = -1;
								}

								if (joy_get_buttons_pressed_on_sample(i, contpad1, c1allowedbuttons & (D_JPAD | D_CBUTTONS))) {
									if (movedata.crouchup) {
										movedata.crouchup--;
									} else {
										movedata.crouchdown++;
									}

									g_Vars.currentplayer->aimtaptime = -1;
								}
							}

							if (options_get_aim_control(g_Vars.currentplayerstats->mpindex) == AIMCONTROL_HOLD) {
								if (aimonhist[i]) {
									if (g_Vars.currentplayer->aimtaptime >= 0) {
										g_Vars.currentplayer->aimtaptime++;
									}
								} else {
									// Released aim
									if (g_Vars.currentplayer->aimtaptime > 0 && g_Vars.currentplayer->aimtaptime < TICKS(15)) {
										// Was only a tap, so uncrouch
										if (movedata.crouchdown) {
											movedata.crouchdown--;
										} else {
											movedata.crouchup++;
										}
									}

									g_Vars.currentplayer->aimtaptime = 0;
								}
							}
						}
					}

					// Handle shutting eyes in multiplayer
					if (bmove_get_crouch_pos() == CROUCHPOS_SQUAT
							&& g_Vars.currentplayer->crouchoffset == -90
							&& g_Vars.mplayerisrunning
							&& g_Vars.coopplayernum <= -1) {
						movedata.eyesshut = g_Vars.currentplayer->insightaimmode
							&& !canmanualzoom
							&& joy_get_buttons(contpad1, c1allowedbuttons & (D_JPAD | D_CBUTTONS));
					}

					if (bgun_get_weapon_num(HAND_RIGHT) == WEAPON_FARSIGHT) {
						movedata.farsighttempautoseek = g_Vars.currentplayer->insightaimmode && (c1buttons & (L_CBUTTONS | R_CBUTTONS | L_JPAD | R_JPAD));
					} else {
						movedata.rleanleft = g_Vars.currentplayer->insightaimmode && (c1buttons & (L_JPAD | L_CBUTTONS));
						movedata.rleanright = g_Vars.currentplayer->insightaimmode && (c1buttons & (R_JPAD | R_CBUTTONS));
					}

					// Handle mine detonation
					if ((((c1buttons & invbuttons) && (c1buttonsthisframe & B_BUTTON))
							|| ((c1buttons & B_BUTTON) && (c1buttonsthisframe & invbuttons)))
							&& weaponnum == WEAPON_REMOTEMINE) {
						movedata.detonating = true;
						movedata.weaponbackoffset = 0;
						movedata.weaponforwardoffset = 0;
						movedata.btapcount = 0;
						g_Vars.currentplayer->invdowntime = -2;
						g_Vars.currentplayer->usedowntime = -2;
					}
				}

				movedata.aiming = g_Vars.currentplayer->insightaimmode;
				movedata.zooming = g_Vars.currentplayer->insightaimmode;

				if (g_Vars.currentplayer->waitforzrelease
						&& (c1buttons & shootbuttons) == 0) {
					g_Vars.currentplayer->waitforzrelease = false;
				}

				if (weapon_has_flag(bgun_get_weapon_num(HAND_RIGHT), WEAPONFLAG_FIRETOACTIVATE)) {
					if ((c1buttonsthisframe & shootbuttons)
							&& g_Vars.currentplayer->pausemode == PAUSEMODE_UNPAUSED) {
						movedata.btapcount++;
					}
				} else {
					movedata.triggeron = g_Vars.currentplayer->waitforzrelease == false
						&& (c1buttons & shootbuttons)
						&& g_Vars.currentplayer->pausemode == PAUSEMODE_UNPAUSED
						&& (c1buttons & invbuttons) == 0;
				}

				if (controlmode == CONTROLMODE_12 || controlmode == CONTROLMODE_14) {
					movedata.disablelookahead = true;
				}
			} // end 1.x
		}
	}

	g_Vars.currentplayer->bondactivateorreload = 0;

	if (movedata.btapcount) {
		g_Vars.currentplayer->activatetimelast = g_Vars.currentplayer->activatetimethis;
		g_Vars.currentplayer->activatetimethis = g_Vars.lvframe60;
		g_Vars.currentplayer->bondactivateorreload = movedata.btapcount;

		bmove_handle_activate();
	}

	if (!movedata.invertpitch) {
		savedverta = movedata.speedvertadown;
		movedata.analogpitch = -movedata.analogpitch;
		movedata.c1stickyraw = -movedata.c1stickyraw;
		movedata.speedvertadown = movedata.speedvertaup;
		movedata.speedvertaup = savedverta;
	}

	bgun_tick_gameplay(movedata.triggeron);

	if (g_Vars.bondvisible && (bgun_is_firing(HAND_RIGHT) || bgun_is_firing(HAND_LEFT))) {
		noiseradius = 0;

		if (bgun_is_firing(HAND_RIGHT) && bgun_get_noise_radius(HAND_RIGHT) > noiseradius) {
			noiseradius = bgun_get_noise_radius(HAND_RIGHT);
		}

		if (bgun_is_firing(HAND_LEFT) && bgun_get_noise_radius(HAND_LEFT) > noiseradius) {
			noiseradius = bgun_get_noise_radius(HAND_LEFT);
		}

		chrs_check_for_noise(noiseradius);
	}

	bgun_set_sight_visible(GUNSIGHTREASON_NOTAIMING, movedata.aiming);

	if (movedata.zoomoutfovpersec > 0) {
		current_player_zoom_out(movedata.zoomoutfovpersec);
	}

	if (movedata.zoominfovpersec > 0) {
		current_player_zoom_in(movedata.zoominfovpersec);
	}

	if (g_Vars.currentplayer->pausemode == PAUSEMODE_UNPAUSED && !g_MainIsEndscreen) {
		zoomfov = 60;

		// FarSight in secondary function
		if (bgun_get_weapon_num(HAND_RIGHT) == WEAPON_FARSIGHT
				&& g_Vars.currentplayer->insightaimmode
				&& (movedata.farsighttempautoseek || g_Vars.currentplayer->hands[HAND_RIGHT].gset.weaponfunc == FUNC_SECONDARY)
				&& g_Vars.currentplayer->autoeraserdist > 0) {
			eraserfov = cam0f0b49b8(500.0f / g_Vars.currentplayer->autoeraserdist);

			if (eraserfov > 60) {
				eraserfov = 60;
			}

			if (eraserfov < 2) {
				eraserfov = 2;
			}

			g_Vars.currentplayer->gunzoomfovs[1] = eraserfov;

			mtx4_transform_vec(cam_get_world_to_screen_mtxf(), &g_Vars.currentplayer->autoerasertarget->pos, &spa0);

			cam0f0b4eb8(&spa0, crosspos, eraserfov, g_Vars.currentplayer->c_perspaspect);

			if (crosspos[0] < (cam_get_screen_left() + cam_get_screen_width() * 0.5f) - 20.0f) {
				movedata.aimturnleftspeed = 0.25f;
			} else if (crosspos[0] > cam_get_screen_left() + cam_get_screen_width() * 0.5f + 20.0f) {
				movedata.aimturnrightspeed = 0.25f;
			}

			if (crosspos[1] < (cam_get_screen_top() + cam_get_screen_height() * 0.5f) - 20.0f) {
				movedata.speedvertaup = 0.25f;
			} else if (crosspos[1] > cam_get_screen_top() + cam_get_screen_height() * 0.5f + 20.0f) {
				movedata.speedvertadown = 0.25f;
			}
		}

		if (movedata.zooming) {
			zoomfov = current_player_get_gun_zoom_fov();
		}

		if (bgun_get_weapon_num(HAND_RIGHT) == WEAPON_AR34
				&& g_Vars.currentplayer->hands[HAND_RIGHT].gset.weaponfunc == FUNC_SECONDARY) {
			zoomfov = current_player_get_gun_zoom_fov();
		}

		if (zoomfov <= 0) {
			zoomfov = 60;
		}

		player_tween_fov_y(zoomfov);
		player_update_zoom();
	}

	bmove_apply_move_data(&movedata);

	// Speed boost
	// After 3 seconds of holding forward at max speed, apply boost multiplier.
	// The multiplier starts at 1 and reaches 1.25 after about 0.1 seconds.
	if (g_Vars.currentplayer->speedmaxtime60 >= TICKS(180)) {
		if (g_Vars.currentplayer->speedboost < 1.25f) {
			g_Vars.currentplayer->speedboost += 0.01f * g_Vars.lvupdate60freal;
		}

		if (g_Vars.currentplayer->speedboost > 1.25f) {
#if PIRACYCHECKS
			piracy_restore();
#endif
			g_Vars.currentplayer->speedboost = 1.25f;
		}
	} else {
		if (g_Vars.currentplayer->speedboost > 1) {
			g_Vars.currentplayer->speedboost -= 0.01f * g_Vars.lvupdate60freal;
		}

		if (g_Vars.currentplayer->speedboost < 1) {
			g_Vars.currentplayer->speedboost = 1;
		}
	}

	// Look ahead
	if (g_Vars.currentplayer->pausemode == PAUSEMODE_UNPAUSED) {
		lookahead = -4;

		offbike = g_Vars.currentplayer->bondmovemode == MOVEMODE_WALK
			|| g_Vars.currentplayer->bondmovemode == MOVEMODE_GRAB;

		if (g_Vars.currentplayer->lookaheadcentreenabled) {
			if (g_Vars.lvframenum != g_Vars.currentplayer->lookaheadframe
					&& g_Vars.currentplayernum == (g_Vars.lvframenum & 3)) {
				g_Vars.currentplayer->cachedlookahead = bmove_calculate_lookahead();
			}

			lookahead = g_Vars.currentplayer->cachedlookahead;
		}

		if (g_Vars.currentplayer->movecentrerelease
				&& movedata.analogwalk < 40 && movedata.analogwalk > -40) {
			g_Vars.currentplayer->movecentrerelease = false;
		}

		if (offbike) {
			if (movedata.speedvertadown > 0 || movedata.speedvertaup > 0) {
				g_Vars.currentplayer->docentreupdown = false;
				g_Vars.currentplayer->prevupdown = true;
				g_Vars.currentplayer->automovecentre = false;
			} else {
				if (movedata.disablelookahead) {
					g_Vars.currentplayer->automovecentre = false;
				} else if (g_Vars.currentplayer->automovecentreenabled) {
					if (movedata.canlookahead && (movedata.analogwalk > 60 || movedata.analogwalk < -60)) {
						g_Vars.currentplayer->automovecentre = true;
					}

					if (g_Vars.currentplayer->automovecentre
							&& (g_Vars.currentplayer->vv_verta > lookahead + 5.0f || g_Vars.currentplayer->vv_verta < lookahead + -10.0f)
							&& g_Vars.currentplayer->movecentrerelease == false) {
						g_Vars.currentplayer->docentreupdown = true;
					}
				} else if (g_Vars.currentplayer->fastmovecentreenabled
						&& movedata.canlookahead
						&& (movedata.analogwalk > 60 || movedata.analogwalk < -60)
						&& (g_Vars.currentplayer->vv_verta > lookahead + 5.0f || g_Vars.currentplayer->vv_verta < lookahead + -10.0f)
						&& g_Vars.currentplayer->movecentrerelease == false) {
					g_Vars.currentplayer->docentreupdown = true;
				}

				g_Vars.currentplayer->prevupdown = false;
			}
		}

#if VERSION >= VERSION_NTSC_1_0
		if (g_Vars.currentplayer->bondmovemode == MOVEMODE_BIKE) {
			g_Vars.currentplayer->docentreupdown = false;
		}
#endif

		if (g_Vars.currentplayer->docentreupdown) {
			if (offbike) {
				// Determine direction for lookahead increment
				increment2 = (g_Vars.currentplayer->speedverta * g_Vars.currentplayer->speedverta * 0.5f) / 0.05f;

				if (g_Vars.currentplayer->vv_verta > lookahead + increment2) {
					bmove_update_speed_verta(1);
				} else if (g_Vars.currentplayer->vv_verta < lookahead - increment2) {
					bmove_update_speed_verta(-1);
				} else {
					bmove_update_speed_verta(0);
				}

				// Calculate new verta
				newverta = g_Vars.currentplayer->vv_verta + (g_Vars.currentplayer->speedverta * g_Vars.lvupdate60freal + g_Vars.currentplayer->speedverta * g_Vars.lvupdate60freal);

				if (g_Vars.currentplayer->vv_verta > lookahead && newverta > lookahead) {
					g_Vars.currentplayer->vv_verta = newverta;
				} else if (g_Vars.currentplayer->vv_verta < lookahead && newverta < lookahead) {
					g_Vars.currentplayer->vv_verta = newverta;
				} else {
					g_Vars.currentplayer->vv_verta = lookahead;
					g_Vars.currentplayer->speedverta = 0;

					if (g_Vars.currentplayer->prevupdown == false) {
						g_Vars.currentplayer->docentreupdown = false;
					}
				}
			}
		} else {
			if (movedata.cannaturalpitch) {
				tmp = vi_get_fov_y() / 60.0f;
				fVar25 = movedata.analogpitch / 70.0f;

				if (fVar25 > 1) {
					fVar25 = 1;
				} else if (fVar25 < -1) {
					fVar25 = -1;
				}

				if (fVar25 >= 0) {
					fVar25 *= fVar25;
				} else {
					fVar25 *= -fVar25;
				}

				g_Vars.currentplayer->speedverta = -fVar25 * tmp;
			} else if (movedata.speedvertadown > 0) {
				bmove_update_speed_verta(movedata.speedvertadown);

				if (movedata.canlookahead && (movedata.analogwalk > 60 || movedata.analogwalk < -60)) {
					g_Vars.currentplayer->movecentrerelease = true;
				}
			} else if (movedata.speedvertaup > 0) {
				bmove_update_speed_verta(-movedata.speedvertaup);

				if (movedata.canlookahead && (movedata.analogwalk > 60 || movedata.analogwalk < -60)) {
					g_Vars.currentplayer->movecentrerelease = true;
				}
			} else {
				bmove_update_speed_verta(0);
			}

			g_Vars.currentplayer->vv_verta += g_Vars.currentplayer->speedverta * g_Vars.lvupdate60freal * 3.5f;
		}
	}

	if (movedata.cannaturalturn) {
		tmp = vi_get_fov_y() / 60.0f;
		fVar25 = movedata.analogturn / 70.0f;

		if (fVar25 > 1) {
			fVar25 = 1;
		} else if (fVar25 < -1) {
			fVar25 = -1;
		}

		if (fVar25 >= 0) {
			fVar25 *= fVar25;
		} else {
			fVar25 *= -fVar25;
		}

		g_Vars.currentplayer->speedthetacontrol = fVar25 * tmp;
	} else if (movedata.aimturnleftspeed > 0) {
		bmove_update_speed_theta_control(movedata.aimturnleftspeed);
	} else if (movedata.aimturnrightspeed > 0) {
		bmove_update_speed_theta_control(-movedata.aimturnrightspeed);
	} else {
		bmove_update_speed_theta_control(0);
	}

	g_Vars.currentplayer->speedtheta = g_Vars.currentplayer->speedthetacontrol;
	bmove_update_speed_theta();

	if (movedata.detonating) {
		g_Vars.currentplayer->hands[HAND_RIGHT].mode = HANDMODE_NONE;
		g_Vars.currentplayer->hands[HAND_RIGHT].modenext = HANDMODE_NONE;
		player_activate_remote_mine_detonator(g_Vars.currentplayernum);
	}

	cancycleweapons = true;

	if (g_Vars.tickmode == TICKMODE_CUTSCENE) {
		cancycleweapons = false;
	}

	if (g_Vars.lvframenum < 10) {
		cancycleweapons = false;
	}

	if (cancycleweapons) {
		while (movedata.weaponbackoffset-- > 0) {
			bgun_cycle_back();
		}

		while (movedata.weaponforwardoffset-- > 0) {
			bgun_cycle_forward();
		}
	}

	if (g_Vars.currentplayer->unk1c64) {
		g_Vars.currentplayer->unk1c64 = 0;
	} else if (movedata.canswivelgun) {
		f32 x;
		f32 y;

		bgun_set_aim_type(0);

		if (
				(
				 movedata.canautoaim
				 && (bmove_is_auto_aim_x_enabled_for_current_weapon() || bmove_is_auto_aim_y_enabled_for_current_weapon())
				 && g_Vars.currentplayer->autoxaimprop
				 && g_Vars.currentplayer->autoyaimprop
				 && weapon_has_aim_flag(weaponnum, INVAIMFLAG_AUTOAIM)
				)
				|| (bgun_get_weapon_num(HAND_RIGHT) == WEAPON_CMP150 && g_Vars.currentplayer->hands[HAND_RIGHT].gset.weaponfunc == FUNC_SECONDARY)) {
			// Auto aim - move crosshair towards target
			s32 followlockon = false;

			if (bgun_get_weapon_num(HAND_RIGHT) == WEAPON_CMP150
					&& g_Vars.currentplayer->hands[HAND_RIGHT].gset.weaponfunc == FUNC_SECONDARY) {
				followlockon = true;
			}

			if (g_Vars.currentplayer->autoaimdamp > (PAL ? 0.955f : 0.963f)) {
				g_Vars.currentplayer->autoaimdamp -= (PAL ? 0.00037999986670911f : 0.00031999943894334f) * g_Vars.lvupdate60freal;
			}

			if (g_Vars.currentplayer->autoaimdamp < (PAL ? 0.955f : 0.963f)) {
				g_Vars.currentplayer->autoaimdamp = (PAL ? 0.955f : 0.963f);
			}

			x = g_Vars.currentplayer->autoaimx;
			y = g_Vars.currentplayer->autoaimy;

			if (followlockon) {
				bgun_swivel(x, y, PAL ? 0.899f : 0.915f, PAL ? 0.899f : 0.915f);
			} else {
				bgun_swivel_with_damp(x, y, g_Vars.currentplayer->autoaimdamp);
			}
		} else {
			// This code moves the crosshair as the player turns and makes
			// it return to the centre when not affected by anything else.
			if (g_Vars.currentplayer->autoaimdamp < (PAL ? 0.974f : 0.979f)) {
				g_Vars.currentplayer->autoaimdamp += (PAL ? 0.00037999986670911f : 0.00031999943894334f) * g_Vars.lvupdate60freal;
			}

			if (g_Vars.currentplayer->autoaimdamp > (PAL ? 0.974f : 0.979f)) {
				g_Vars.currentplayer->autoaimdamp = (PAL ? 0.974f : 0.979f);
			}

			x = g_Vars.currentplayer->speedtheta * 0.3f + g_Vars.currentplayer->gunextraaimx;
			y = -g_Vars.currentplayer->speedverta * 0.1f + g_Vars.currentplayer->gunextraaimy;

			bgun_swivel_with_damp(x, y, PAL ? 0.955f : 0.963f);
		}
	} else if (movedata.canmanualaim) {
		// Adjust crosshair's position on screen
		// when holding aim and moving stick
		bgun_set_aim_type(0);
		bgun_swivel_without_damp((movedata.c1stickxraw * 0.65f) / 80.0f, (movedata.c1stickyraw * 0.65f) / 80.0f);
	}
}

void bmove_find_entered_rooms_by_pos(struct player *player, struct coord *mid, RoomNum *rooms)
{
	struct coord bbmin;
	struct coord bbmax;
	f32 eyeheight = g_Vars.players[playermgr_get_player_num_by_prop(player->prop)]->vv_eyeheight;
	f32 headheight = g_Vars.players[playermgr_get_player_num_by_prop(player->prop)]->vv_headheight;

	bbmin.x = mid->x - 50;
	bbmin.y = mid->y - player->crouchheight - eyeheight - 10;
	bbmin.z = mid->z - 50;

	bbmax.x = mid->x + 50;
	bbmax.y = mid->y - player->crouchheight - eyeheight + headheight + 10;
	bbmax.z = mid->z + 50;

	bg_find_entered_rooms(&bbmin, &bbmax, rooms, 7, false);
}

void bmove_find_entered_rooms(struct player *player, RoomNum *rooms)
{
	bmove_find_entered_rooms_by_pos(player, &player->prop->pos, rooms);
}

void bmove_update_rooms(struct player *player)
{
	prop_deregister_rooms(player->prop);
	bmove_find_entered_rooms(player, player->prop->rooms);
	prop_register_rooms(player->prop);
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
						arg0->f[i] -= (1.0f / 30.0f) * g_Vars.lvupdate60freal * arg0->f[i] / hypotenuse;

						if (arg0->f[i] < 0) {
							arg0->f[i] = 0;
						}
					} else if (arg0->f[i] < 0) {
						arg0->f[i] -= (1.0f / 30.0f) * g_Vars.lvupdate60freal * arg0->f[i] / hypotenuse;

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

void bmove_update_move_init_speed(struct coord *newpos)
{
	if (g_Vars.currentplayer->moveinitspeed.x != 0) {
		if (g_Vars.currentplayer->moveinitspeed.x < 0.001f && g_Vars.currentplayer->moveinitspeed.x > -0.001f) {
			g_Vars.currentplayer->moveinitspeed.x = 0;
		} else {
			g_Vars.currentplayer->moveinitspeed.x *= 0.9f;
			newpos->x += g_Vars.currentplayer->moveinitspeed.x * g_Vars.lvupdate60freal;
		}
	}

	if (g_Vars.currentplayer->moveinitspeed.z != 0) {
		if (g_Vars.currentplayer->moveinitspeed.z < 0.001f && g_Vars.currentplayer->moveinitspeed.z > -0.001f) {
			g_Vars.currentplayer->moveinitspeed.z = 0;
		} else {
			g_Vars.currentplayer->moveinitspeed.z *= 0.9f;
			newpos->z += g_Vars.currentplayer->moveinitspeed.z * g_Vars.lvupdate60freal;
		}
	}
}

void bmove_tick(bool allowc1x, bool allowc1y, bool allowc1buttons, bool ignorec2)
{
	struct chrdata *chr;
	u8 foot;
	s32 sound;
	f32 xdiff;
	f32 ydiff;
	f32 zdiff;
	f32 distance;

	bmove_process_input(allowc1x, allowc1y, allowc1buttons, ignorec2);

	if (g_Vars.currentplayer->bondmovemode == MOVEMODE_BIKE) {
		bbike_tick();
	} else if (g_Vars.currentplayer->bondmovemode == MOVEMODE_GRAB) {
		bgrab_tick();
	} else if (g_Vars.currentplayer->bondmovemode == MOVEMODE_CUTSCENE) {
		bcutscene_tick();
	} else if (g_Vars.currentplayer->bondmovemode == MOVEMODE_WALK) {
		bwalk_tick();
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

				sound = footstep_choose_sound(chr, distance > 10);

				if (sound != -1) {
					snd00010718(0, 0, AL_VOL_FULL, AL_PAN_CENTER, sound, 1, 1, -1, true);
				}
			}
		}
	}
}

void bmove_update_verta(void)
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
			chr_set_look_angle(chr, BADDEG2RAD(360 - g_Vars.currentplayer->vv_theta));
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

	if (cheat_is_active(CHEAT_SMALLJO)) {
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

#if VERSION < VERSION_NTSC_1_0
		if (g_Vars.currentplayer->bond2.unk10.y < 30) {
			g_Vars.currentplayer->bond2.unk10.y = 30;
		}
#endif

		g_Vars.currentplayer->bond2.unk10.y += g_Vars.currentplayer->vv_manground;
	}

#if VERSION >= VERSION_NTSC_1_0
	min = g_Vars.currentplayer->vv_ground + 10;

	if (g_Vars.currentplayer->bond2.unk10.y < min) {
		g_Vars.currentplayer->bond2.unk10.y = min;
	}
#endif
}

void bmove_update_head(f32 arg0, f32 arg1, f32 arg2, Mtxf *arg3, f32 arg4)
{
	f32 sp244 = 0;
	Mtxf sp180;
	Mtxf sp116;
	f32 sp100[4];
	f32 sp84[4];
	f32 sp68[4];

	if (g_Vars.currentplayer->isdead == false) {
		bhead_adjust_animation(arg0);

		if (arg0 != 0) {
			sp244 = arg1 / arg0;
		} else if (arg1 == 0) {
			arg0 = 0;
		}
	} else {
		if (g_Vars.currentplayer->startnewbonddie) {
			bhead_start_death_animation(g_DeathAnimations[random() % g_NumDeathAnimations], random() % 2, 0, 1);
			g_Vars.currentplayer->startnewbonddie = false;
		}

		bhead_set_speed(0.5);
		arg2 = 0;
	}

	bhead_update(sp244, arg2);
	mtx4_load_x_rotation(BADDEG2RAD(360 - g_Vars.currentplayer->vv_verta360), &sp180);

	if (options_get_head_roll(g_Vars.currentplayerstats->mpindex)) {
		mtx00016d58(&sp116,
				0, 0, 0,
				-g_Vars.currentplayer->headlook.x, -g_Vars.currentplayer->headlook.y, -g_Vars.currentplayer->headlook.z,
				g_Vars.currentplayer->headup.x, g_Vars.currentplayer->headup.y, g_Vars.currentplayer->headup.z);
		mtx4_mult_mtx4_in_place(&sp116, &sp180);
	}

	mtx4_load_y_rotation(BADDEG2RAD(360 - g_Vars.currentplayer->vv_theta), &sp116);
	mtx4_mult_mtx4_in_place(&sp116, &sp180);

	if (arg3) {
		quaternion0f097044(&sp180, sp100);
		quaternion0f097044(arg3, sp84);
		quaternion0f0976c0(sp100, sp84);
		quaternion_slerp(sp100, sp84, arg4, sp68);
		quaternion_to_mtx(sp68, &sp180);
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
	bmove_update_head(arg0, arg1, arg2, NULL, 0);
}

s32 bmove_get_crouch_pos(void)
{
	return (g_Vars.currentplayer->crouchpos < g_Vars.currentplayer->autocrouchpos)
		? g_Vars.currentplayer->crouchpos
		: g_Vars.currentplayer->autocrouchpos;
}

s32 bmove_get_crouch_pos_by_player(s32 playernum)
{
	return (g_Vars.players[playernum]->crouchpos < g_Vars.players[playernum]->autocrouchpos)
		? g_Vars.players[playernum]->crouchpos
		: g_Vars.players[playernum]->autocrouchpos;
}
