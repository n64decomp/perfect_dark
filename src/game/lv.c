#include <ultra64.h>
#include "constants.h"
#include "bss.h"
#include "data.h"
#include "game/activemenu.h"
#include "game/atan2f.h"
#include "game/bg.h"
#include "game/body.h"
#include "game/bondgun.h"
#include "game/bondhead.h"
#include "game/bondmove.h"
#include "game/bondview.h"
#include "game/camdraw.h"
#include "game/casing.h"
#include "game/cheats.h"
#include "game/chr.h"
#include "game/chraction.h"
#include "game/credits.h"
#include "game/debug.h"
#include "game/dlights.h"
#include "game/explosions.h"
#include "game/filemgr.h"
#include "game/game_006900.h"
#include "game/chraireset.h"
#include "game/gunfx.h"
#include "game/gset.h"
#include "game/modelmgr.h"
#include "game/portal.h"
#include "game/fmb.h"
#include "game/sky.h"
#include "game/artifact.h"
#include "game/text.h"
#include "game/zbuf.h"
#include "game/challenge.h"
#include "game/chrmgr.h"
#include "game/env.h"
#include "game/gfxmemory.h"
#include "game/gunfx.h"
#include "game/hudmsg.h"
#include "game/inv.h"
#include "game/lang.h"
#include "game/lv.h"
#include "game/menu.h"
#include "game/mplayer/mplayer.h"
#include "game/mplayer/scenarios.h"
#include "game/mplayer/setup.h"
#include "game/music.h"
#include "game/nbomb.h"
#include "game/objectives.h"
#include "game/pak.h"
#include "game/pdmode.h"
#include "game/player.h"
#include "game/playermgr.h"
#include "game/playerreset.h"
#include "game/prop.h"
#include "game/propobj.h"
#include "game/propobjstop.h"
#include "game/propsnd.h"
#include "game/room.h"
#include "game/savebuffer.h"
#include "game/setup.h"
#include "game/shards.h"
#include "game/sky.h"
#include "game/smoke.h"
#include "game/sparks.h"
#include "game/splat.h"
#include "game/stars.h"
#include "game/stubs/game_013540.h"
#include "game/stubs/game_015260.h"
#include "game/stubs/game_015270.h"
#include "game/stubs/game_0153f0.h"
#include "game/stubs/game_015400.h"
#include "game/stubs/game_015410.h"
#include "game/tex.h"
#include "game/texdecompress.h"
#include "game/tiles.h"
#include "game/title.h"
#include "game/training.h"
#include "game/utils.h"
#include "game/vtxstore.h"
#include "game/wallhit.h"
#include "game/weather.h"
#include "lib/anim.h"
#include "lib/args.h"
#include "lib/collision.h"
#include "lib/crash.h"
#include "lib/joy.h"
#include "lib/lib_06440.h"
#include "lib/lib_317f0.h"
#include "lib/main.h"
#include "lib/mtx.h"
#include "lib/music.h"
#include "lib/rng.h"
#include "lib/sched.h"
#include "lib/snd.h"
#include "lib/vars.h"
#include "lib/vi.h"
#include "types.h"

struct sndstate *g_MiscSfxAudioHandles[3];
u32 var800aa5bc;
s32 g_MiscSfxActiveTypes[3];

u32 var80084010 = 0;
bool var80084014 = false;
f32 var80084018 = 1;
u32 var8008401c = 0x00000001;

s32 g_Difficulty = DIFF_A;

s32 g_StageTimeElapsed60 = 0;
s32 g_MpTimeLimit60 = SECSTOTIME60(60 * 10); // 10 minutes
s32 g_MpScoreLimit = 10;
s32 g_MpTeamScoreLimit = 20;
struct sndstate *g_MiscAudioHandle = NULL;
s32 g_NumReasonsToEndMpMatch = 0;
f32 g_StageTimeElapsed1f = 0;
bool var80084040 = true;

u32 g_MiscSfxSounds[] = {
	SFX_HEARTBEAT,
	SFX_SLAYER_WHIR,
	SFX_SLAYER_BEEP,
};

s32 var80084050 = 0;

s16 g_FadeNumFrames = 0;
f32 g_FadeFrac = -1;
u32 g_FadePrevColour = 0;
u32 g_FadeColour = 0;
s16 g_FadeDelay = 0;

void lv_fade_reset(void);
void lv_check_pause_state_changed(void);

u32 get_var80084040(void)
{
	return var80084040;
}

void set_var80084040(u32 value)
{
	var80084040 = value;
}

void lv_init(void)
{
	g_Vars.lockscreen = 0;
	g_Vars.joydisableframestogo = -1;
}

void lv_reset_misc_sfx(void)
{
	s32 i;

	for (i = 0; i != ARRAYCOUNT(g_MiscSfxAudioHandles); i++) {
		g_MiscSfxAudioHandles[i] = NULL;
		g_MiscSfxActiveTypes[i] = -1;
	}
}

s32 lv_get_misc_sfx_index(u32 type)
{
	s32 i;

	for (i = 0; i != ARRAYCOUNT(g_MiscSfxActiveTypes); i++) {
		if (g_MiscSfxActiveTypes[i] == type) {
			return i;
		}
	}

	return -1;
}

void lv_set_misc_sfx_state(u32 type, bool play)
{
	if (play) {
		if (lv_get_misc_sfx_index(type) == -1) {
			s32 index = lv_get_misc_sfx_index(-1);

#if VERSION >= VERSION_NTSC_1_0
			if (index != -1 && g_MiscSfxAudioHandles[index] == NULL)
#else
			if (index != -1)
#endif
			{
				snd_start(var80095200, g_MiscSfxSounds[type], &g_MiscSfxAudioHandles[index], -1, -1, -1, -1, -1);
				g_MiscSfxActiveTypes[index] = type;
			}
		}
	} else {
		u32 stack;
		s32 index = lv_get_misc_sfx_index(type);

		if (index != -1) {
			audioStop(g_MiscSfxAudioHandles[index]);
#if VERSION < VERSION_NTSC_1_0
			g_MiscSfxAudioHandles[index] = 0;
#endif
			g_MiscSfxActiveTypes[index] = -1;
		}
	}
}

void lv_update_misc_sfx(void)
{
	s32 i;

	if (g_Vars.lvupdate240 == 0) {
		for (i = 0; i != ARRAYCOUNT(g_MiscSfxActiveTypes); i++) {
			lv_set_misc_sfx_state(i, false);
		}
	} else {
		bool usingboost = g_Vars.speedpillon
			&& lv_get_slow_motion_type() == SLOWMOTION_OFF
			&& g_Vars.in_cutscene == false;
		bool usingrocket;

		lv_set_misc_sfx_state(MISCSFX_BOOSTHEARTBEAT, usingboost);

		usingrocket = false;

		for (i = 0; i < PLAYERCOUNT(); i++) {
			if (g_Vars.players[i]->visionmode == VISIONMODE_SLAYERROCKET) {
				usingrocket = true;
			}
		}

		lv_set_misc_sfx_state(MISCSFX_SLAYERROCKETHUM, usingrocket);
		lv_set_misc_sfx_state(MISCSFX_SLAYERROCKETBEEP, usingrocket);
	}

	if (g_Vars.lvupdate240 == 0 && g_MiscAudioHandle && sndGetState(g_MiscAudioHandle) != AL_STOPPED) {
		audioStop(g_MiscAudioHandle);
	}
}

void lv_reset(s32 stagenum)
{
	lv_fade_reset();

	var80084014 = false;
	var80084010 = 0;

#if VERSION >= VERSION_NTSC_1_0
	joy_lock_cyclic_polling();

	g_Vars.joydisableframestogo = 10;
#else
	if (joy_is_cyclic_polling_enabled()) {
		joy_disable_cyclic_polling(760, "lv.c");

		g_Vars.joydisableframestogo = 10;
	}
#endif

	g_Vars.paksneededforgame = 0;
	g_Vars.paksneededformenu = 0;
	g_Vars.stagenum = stagenum;

	cheats_reset();

	var80084040 = true;
	g_Vars.lvframenum = 0;
	var80084050 = 0;

	g_Vars.lvframe60 = 0;
	g_Vars.lvupdate240 = 4;

#if VERSION >= VERSION_NTSC_1_0
	g_Vars.lvupdate60f = 1.0f;
	g_Vars.lvupdate60frealprev = PALUPF(1);
#else
	g_Vars.lvupdate60frealprev = PALUPF(1);
	g_Vars.lvupdate60f = 1.0f;
#endif

	g_Vars.lvupdate60freal = g_Vars.lvupdate60frealprev;

	g_StageTimeElapsed60 = 0;
	g_StageTimeElapsed1f = 0;

	g_Vars.speedpilltime = 0;
	g_Vars.speedpillchange = 0;
	g_Vars.speedpillwant = 0;
	g_Vars.speedpillon = false;

	g_Vars.restartlevel = false;
	g_Vars.aibuddiesspawned = false;
	g_Vars.totalkills = 0;
	g_Vars.antiheadnum = -1;
	g_Vars.antibodynum = -1;
	g_Vars.dontplaynrg = false;
	g_Vars.in_cutscene = false;
	g_Vars.autocutplaying = false;
	g_Vars.autocutfinished = false;
	g_Vars.autocutgroupskip = false;

	g_MiscAudioHandle = NULL;

	music_reset();
	modelmgr_set_lv_resetting(true);
	surface_reset();
	tex_reset();
	text_reset();
	hudmsgs_reset();

	if (stagenum == STAGE_TEST_OLD) {
		title_reset();
	}

	if (stagenum == STAGE_TITLE) {
		title_reset();
	} else if (stagenum == STAGE_BOOTPAKMENU) {
		// empty
	} else if (stagenum == STAGE_CREDITS) {
		// empty
	} else if (stagenum == STAGE_4MBMENU) {
		// empty
	} else {
		s32 i;
		s32 j;

		tiles_reset();
		bg_reset(g_Vars.stagenum);
		bg_build_tables(g_Vars.stagenum);
		sky_reset(g_Vars.stagenum);

		if (g_Vars.normmplayerisrunning) {
			music_set_stage_and_start_music(stagenum);
		} else {
			music_set_stage(stagenum);
		}

		if (g_Vars.normmplayerisrunning) {
			mp_apply_limits();
		}

		if (g_Vars.mplayerisrunning == false) {
			g_Vars.playerstats[0].mpindex = 4;
			g_PlayerConfigsArray[4].contpad1 = 0;
			g_PlayerConfigsArray[4].contpad2 = 1;
		}

		for (i = 0; i != ARRAYCOUNT(g_Vars.playerstats); i++) {
			g_Vars.playerstats[i].damagescale = 1;
			g_Vars.playerstats[i].drawplayercount = 0;
			g_Vars.playerstats[i].distance = 0;
			g_Vars.playerstats[i].backshotcount = 0;
			g_Vars.playerstats[i].armourcount = 0;
			g_Vars.playerstats[i].fastest2kills = S32_MAX;
			g_Vars.playerstats[i].slowest2kills = 0;
			g_Vars.playerstats[i].maxkills = 0;
			g_Vars.playerstats[i].maxsimulkills = 0;
			g_Vars.playerstats[i].longestlife = 0;
			g_Vars.playerstats[i].shortestlife = S32_MAX;
			g_Vars.playerstats[i].tokenheldtime = 0;
			g_Vars.playerstats[i].damreceived = 0;
			g_Vars.playerstats[i].damtransmitted = 0;

			for (j = 0; j != ARRAYCOUNT(g_Vars.playerstats[i].kills); j++) {
				g_Vars.playerstats[i].kills[j] = 0;
			}
		}
	}

	mp_set_default_names_if_empty();
	anims_reset();
	objectives_reset();
	vtxstore_reset();
	modelmgr_reset();
	ps_reset();
	setup_load_files(stagenum);
	scenario_reset();
	vars_reset();
	props_reset();
	chrmgr_reset();
	bodies_reset(stagenum);
	setup_create_props(stagenum);
	tags_reset();
	explosions_reset();
	smoke_reset();
	sparks_reset();
	weather_reset();
	lv_reset_misc_sfx();

	switch (g_Vars.stagenum) {
	case STAGE_ESCAPE:
	case STAGE_EXTRACTION:
	case STAGE_INFILTRATION:
	case STAGE_DEFECTION:
	case STAGE_ATTACKSHIP:
	case STAGE_TEST_OLD:
		stars_reset();
		break;
	}

	func0f0099a4();
	boltbeams_reset();
	lasersights_reset();
	stub0f013540();
	shards_reset();
	fr_reset();

	if (g_Vars.stagenum == STAGE_TITLE) {
		// empty
	} else if (stagenum == STAGE_BOOTPAKMENU) {
		set_current_player_num(0);
		menu_reset();
	} else if (stagenum == STAGE_4MBMENU) {
		set_current_player_num(0);
		menu_reset();
	} else if (stagenum == STAGE_CREDITS) {
		credits_reset();
	} else {
		s32 i;

		utils_reset();
		casings_reset();

		for (i = 0; i < PLAYERCOUNT(); i++) {
			set_current_player_num(i);
			g_Vars.currentplayer->usedowntime = 0;
			g_Vars.currentplayer->invdowntime = g_Vars.currentplayer->usedowntime;

			menu_reset();
			am_reset();
			inv_reset();
			bgun_reset();
			player_load_defaults();
			player_reset();
			player_spawn();
			bhead_reset();

			if (g_Vars.normmplayerisrunning && (g_MpSetup.options & MPOPTION_TEAMSENABLED)) {
				playermgr_calculate_ai_buddy_nums();
			}
		}

		acoustic_reset();
		portals_reset();
		lights_reset();
		set_current_player_num(0);
	}

	if (g_Vars.lvmpbotlevel) {
		mp_calculate_team_is_only_ai();
	}

	paks_reset();
	snd_reset_cur_mp3();

	if (stagenum == STAGE_BOOTPAKMENU) {
		bootmenu_reset();
	}

	if (stagenum == STAGE_4MBMENU) {
		fmb_reset();
	}

	if (IS8MB()) {
		camdraw_reset();
	}

	modelmgr_set_lv_resetting(false);
	var80084018 = 1;
	sched_reset_artifacts();
	lv_set_paused(0);

#if PIRACYCHECKS
	{
		u32 checksum = 0;
		s32 *i = (s32 *)&lv_get_slow_motion_type;
		s32 *end = (s32 *)&lv_tick;

		while (i < end) {
			checksum += *i;
			i++;
		}

		if (checksum != CHECKSUM_PLACEHOLDER) {
			// This is writing a file to the start of the EEPROM data.
			// The file is PAKFILETYPE_TERMINATOR, which is used internally to
			// mark the end of the usable space. This effectively deletes all
			// save data on the game pak and makes it permanently unusable.
			u32 address = 0;
			u32 buffer[4];
			buffer[0] = 0xbb8b80bd;
			buffer[1] = 0xffffffff;
			buffer[2] = 0x020f0100;
			buffer[3] = 0xcd31100b;
			osEepromLongWrite(&g_PiMesgQueue, address, (u8 *)&buffer, 0x10);
			g_Paks[SAVEDEVICE_GAMEPAK].headercachecount = 0;
		}
	}
#endif
}

void lv_configure_fade(u32 color, s16 num_frames)
{
	g_FadeNumFrames = num_frames;
	g_FadePrevColour = g_FadeColour;

	if (g_FadeNumFrames == 0) {
		g_FadeColour = color;
		g_FadeFrac = -1;
		return;
	}

	g_FadeFrac = 0;
	g_FadeColour = color;
	g_FadeDelay = 2;
}

Gfx *lv_render_fade(Gfx *gdl)
{
	u32 colour = g_FadeColour;
	u32 inset = 0;

	if (g_Vars.stagenum == STAGE_TEST_OLD) {
		inset = 61;
	}

	if (g_FadeFrac >= 0) {
		if (g_FadeDelay > 0) {
			g_FadeDelay--;
		} else {
#if VERSION >= VERSION_PAL_BETA
			g_FadeFrac += g_Vars.diffframe60freal / g_FadeNumFrames;
#else
			g_FadeFrac += g_Vars.diffframe60f / g_FadeNumFrames;
#endif

			if (g_FadeFrac >= 1) {
				g_FadeFrac = -1;
			}
		}
	}

	if (g_FadeFrac < 0) {
		if ((g_FadeColour & 0xff) == 0) {
			return gdl;
		}
	} else {
		colour = colour_blend(g_FadeColour, g_FadePrevColour, g_FadeFrac * 255);
	}

	if ((colour & 0xff) == 0) {
		return gdl;
	}

	gDPPipeSync(gdl++);
	gDPSetRenderMode(gdl++, G_RM_CLD_SURF, G_RM_CLD_SURF2);
	gDPSetCombineMode(gdl++, G_CC_PRIMITIVE, G_CC_PRIMITIVE);
	gDPSetPrimColorViaWord(gdl++, 0, 0, colour);

	gDPFillRectangle(gdl++,
			vi_get_view_left(),
			vi_get_view_top() + inset,
			vi_get_view_left() + vi_get_view_width() + 1,
			vi_get_view_top() + vi_get_view_height() - inset + 2);

	return text0f153838(gdl);
}

bool lv_is_fade_active(void)
{
	return g_FadeFrac >= 0;
}

void lv_fade_reset(void)
{
	g_FadeNumFrames = 0;
	g_FadeFrac = -1;
	g_FadePrevColour = 0;
	g_FadeColour = 0;
	g_FadeDelay = 0;
}

bool lv_update_tracked_prop(struct trackedprop *trackedprop, s32 index)
{
	f32 y1;
	f32 x1;
	f32 y2;
	f32 x2;
	struct prop *prop = trackedprop->prop;
	struct chrdata *chr;

	if (trackedprop->prop && prop->chr) {
		switch (trackedprop->prop->type) {
		case PROPTYPE_PLAYER:
			if (playermgr_get_player_num_by_prop(prop) == g_Vars.currentplayernum) {
				return false;
			}
			// fall through
		case PROPTYPE_CHR:
			chr = trackedprop->prop->chr;

			if (chr_is_dead(trackedprop->prop->chr)) {
				if (index >= 0) {
					// Existing trackedprop
					if (g_Vars.currentplayer->targetset[index] < TICKS(129)) {
						g_Vars.currentplayer->targetset[index] = TICKS(129);
					}

					if (g_Vars.currentplayer->targetset[index] >= (PAL ? 146 : 175)) {
						trackedprop->prop = NULL;
						return false;
					}
				} else {
					// lookingatprop
					trackedprop->prop = NULL;
					return false;
				}
			}

			if ((trackedprop->prop->flags & PROPFLAG_ONTHISSCREENTHISTICK)
					&& (chr->chrflags & CHRCFLAG_NOAUTOAIM) == 0) {
				struct model *model = chr->model;
				x1 = -1;
				y1 = -1;
				x2 = -2;
				y2 = -2;

				if (model_get_screen_coords(model, &x2, &x1, &y2, &y1)) {
					break;
				}
				return false;
			}
			return false;
		case PROPTYPE_OBJ:
		case PROPTYPE_WEAPON:
			if (trackedprop->prop->flags & PROPFLAG_ONTHISSCREENTHISTICK) {
				struct defaultobj *obj = trackedprop->prop->obj;
				struct model *model = obj->model;
				x1 = -1;
				y1 = -1;
				x2 = -2;
				y2 = -2;

				if (model_get_screen_coords(model, &x2, &x1, &y2, &y1)) {
					break;
				}
				return false;
			}
			return false;
		case PROPTYPE_DOOR:
		case PROPTYPE_EYESPY:
		case PROPTYPE_EXPLOSION:
		case PROPTYPE_SMOKE:
		default:
			return false;
		}

		trackedprop->x1 = x1 - 2;
		trackedprop->x2 = x2 + 2;
		trackedprop->y1 = y1 - 2;
		trackedprop->y2 = y2 + 2;
	}

	return true;
}

#ifdef DEBUG
Gfx *lv_render_man_pos_if_enabled(Gfx *gdl)
{
	char bufroom[16];
	char bufx[16];
	char bufy[16];
	char bufz[16];
	char bufdir[16];
	s32 x;
	s32 y;
	s32 y2;

	if (debug_is_man_pos_enabled()) {
		f32 xfrac = g_Vars.currentplayer->bond2.theta.x;
		f32 zfrac = g_Vars.currentplayer->bond2.theta.z;

		char directions[][3] = {
			{'n', '\0', '\0'},
			{'n', 'e',  '\0'},
			{'e', '\0', '\0'},
			{'s', 'e',  '\0'},
			{'s', '\0', '\0'},
			{'s', 'w',  '\0'},
			{'w', '\0', '\0'},
			{'n', 'w',  '\0'},
			{'n', '\0', '\0'},
		};

		s32 degrees = RTOD(atan2f(-xfrac, zfrac));

		sprintf(bufroom, "R=%d(%d)", g_Vars.currentplayer->prop->rooms[0], g_Vars.currentplayer->cam_room);
		sprintf(bufx, "%s%sx %4.0f", "", "", g_Vars.currentplayer->prop->pos.x);
		sprintf(bufy, "%s%sy %4.0f", "", "", g_Vars.currentplayer->prop->pos.y);
		sprintf(bufz, "%s%sz %4.0f", "", "", g_Vars.currentplayer->prop->pos.z);
		sprintf(bufdir, "%s %3d", &directions[(degrees + 22) / 45], degrees);

		x = vi_get_view_left() + 17;
		y = vi_get_view_top() + 17;
		y2 = y + 10;

		gdl = text0f153628(gdl);
		gdl = text0f153a34(gdl, 0, y - 1, vi_get_width(), y2 + 1, 0x00000064);

		gdl = text_render_projected(gdl, &x, &y, bufroom, g_CharsHandelGothicSm, g_FontHandelGothicSm, 0xffffffff, vi_get_width(), vi_get_height(), 0, 0);

		x = vi_get_view_left() + 87;
		gdl = text_render_projected(gdl, &x, &y, bufx, g_CharsHandelGothicSm, g_FontHandelGothicSm, 0xffffffff, vi_get_width(), vi_get_height(), 0, 0);

		x = vi_get_view_left() + 141;
		gdl = text_render_projected(gdl, &x, &y, bufy, g_CharsHandelGothicSm, g_FontHandelGothicSm, 0xffffffff, vi_get_width(), vi_get_height(), 0, 0);

		x = vi_get_view_left() + 195;
		gdl = text_render_projected(gdl, &x, &y, bufz, g_CharsHandelGothicSm, g_FontHandelGothicSm, 0xffffffff, vi_get_width(), vi_get_height(), 0, 0);

		x = vi_get_view_left() + 249;
		gdl = text_render_projected(gdl, &x, &y, bufdir, g_CharsHandelGothicSm, g_FontHandelGothicSm, 0xffffffff, vi_get_width(), vi_get_height(), 0, 0);

		gdl = text0f153780(gdl);
	}

	return gdl;
}
#endif

void lv_find_threats_for_prop(struct prop *prop, bool inchild, struct coord *playerpos, bool *activeslots, f32 *distances)
{
	bool condition = true;
	struct defaultobj *obj;
	bool pass;
	f32 sp88;
	f32 sp84;
	f32 sp80;
	f32 sp76;
	s32 i;
	struct model *model;
	struct weaponobj *weapon;

	if (!inchild && prop->z < 0) {
		condition = false;
	}

	if (prop->obj
			&& (prop->flags & PROPFLAG_ONTHISSCREENTHISTICK)
			&& (prop->type == PROPTYPE_OBJ || prop->type == PROPTYPE_WEAPON)
			&& condition) {
		pass = false;
		obj = prop->obj;
		model = prop->obj->model;

		if (obj
				&& obj->type == OBJTYPE_AUTOGUN
				&& (obj->flags2 & (OBJFLAG2_AUTOGUN_MALFUNCTIONING | OBJFLAG2_AUTOGUN_WINDMILL)) == 0) {
			pass = true;
		}

		if (obj && obj->modelnum == MODEL_SK_SHUTTLE) {
			pass = true;
		}

		weapon = (struct weaponobj *)prop->obj;

		if (weapon && prop->obj->type == OBJTYPE_WEAPON) {
			switch (weapon->weaponnum) {
			case WEAPON_GRENADE:
			case WEAPON_NBOMB:
			case WEAPON_TIMEDMINE:
			case WEAPON_PROXIMITYMINE:
			case WEAPON_REMOTEMINE:
				pass = true;
				break;
			case WEAPON_DRAGON:
				if (weapon->gunfunc == (u32)FUNC_SECONDARY) {
					pass = true;
				}
				break;
			}
		}

		if (obj->modelnum == MODEL_TARGET && fr_is_target_one_hit_explodable(prop)) {
			pass = true;
		}

		if (pass) {
			for (i = 0; i < ARRAYCOUNT(g_Vars.currentplayer->trackedprops); i++) {
				if (g_Vars.currentplayer->trackedprops[i].prop == prop) {
					pass = false;
				}
			}
		}

		if (pass) {
			sp84 = -1;
			sp88 = -1;
			sp76 = -2;
			sp80 = -2;

			if (!model_get_screen_coords(model, &sp76, &sp84, &sp80, &sp88)) {
				pass = false;
			}
		}

		if (pass) {
			f32 furtherestdist = 0;
			s32 index = -1;

			f32 sqdist =
				(prop->pos.f[0] - playerpos->f[0]) * (prop->pos.f[0] - playerpos->f[0]) +
				(prop->pos.f[1] - playerpos->f[1]) * (prop->pos.f[1] - playerpos->f[1]) +
				(prop->pos.f[2] - playerpos->f[2]) * (prop->pos.f[2] - playerpos->f[2]);

			for (i = 0; i < ARRAYCOUNT(g_Vars.currentplayer->trackedprops); i++) {
				if (!activeslots[i]) {
					index = i;
				}
			}

			if (index == -1) {
				// No slots available - consider replacing the furtherest
				for (i = 0; i < ARRAYCOUNT(g_Vars.currentplayer->trackedprops); i++) {
					if (distances[i] > furtherestdist) {
						furtherestdist = distances[i];
						index = i;
					}
				}

				if (sqdist >= furtherestdist) {
					index = -1;
				}
			}

			if (index >= 0) {
				g_Vars.currentplayer->trackedprops[index].prop = prop;
				g_Vars.currentplayer->trackedprops[index].x1 = sp84 - 2;
				g_Vars.currentplayer->trackedprops[index].x2 = sp76 + 2;
				g_Vars.currentplayer->trackedprops[index].y1 = sp88 - 2;
				g_Vars.currentplayer->trackedprops[index].y2 = sp80 + 2;
				g_Vars.currentplayer->targetset[index] = 0;
				activeslots[index] = true;
				distances[index] = sqdist;
			}
		}
	}

	if (prop->child) {
		lv_find_threats_for_prop(prop->child, true, playerpos, activeslots, distances);
	}

	if (inchild && prop->next) {
		lv_find_threats_for_prop(prop->next, inchild, playerpos, activeslots, distances);
	}
}

void func0f168f24(struct prop *prop, bool inchild, struct coord *playerpos, s32 *activeslots, f32 *distances)
{
	s32 i;
	f32 sp128;
	f32 sp124;
	f32 sp120;
	f32 sp116;
	struct model *model;

	for (i = 0; i != 4; i++) {
		if (g_Vars.currentplayer->trackedprops[i].prop == prop
				&& (prop->flags & PROPFLAG_ONTHISSCREENTHISTICK)) {
			model = NULL;

			if (prop->type == PROPTYPE_OBJ
					|| prop->type == PROPTYPE_WEAPON
					|| prop->type == PROPTYPE_DOOR) {
				model = g_Vars.currentplayer->trackedprops[i].prop->obj->model;
			} else {
				if (prop->type == PROPTYPE_CHR
						|| (prop->type == PROPTYPE_PLAYER
							&& playermgr_get_player_num_by_prop(prop) != g_Vars.currentplayernum)) {
					model = g_Vars.currentplayer->trackedprops[i].prop->chr->model;
				}
			}

			if (model) {
				sp124 = -1;
				sp128 = -1;
				sp116 = -2;
				sp120 = -2;

				if (model_get_screen_coords(model, &sp116, &sp124, &sp120, &sp128)) {
					activeslots[i] = true;
					g_Vars.currentplayer->trackedprops[i].x1 = sp124 - 2;
					g_Vars.currentplayer->trackedprops[i].x2 = sp116 + 2;
					g_Vars.currentplayer->trackedprops[i].y1 = sp128 - 2;
					g_Vars.currentplayer->trackedprops[i].y2 = sp120 + 2;

					distances[i] =
						(prop->pos.f[0] - playerpos->f[0]) * (prop->pos.f[0] - playerpos->f[0]) +
						(prop->pos.f[1] - playerpos->f[1]) * (prop->pos.f[1] - playerpos->f[1]) +
						(prop->pos.f[2] - playerpos->f[2]) * (prop->pos.f[2] - playerpos->f[2]);
				}
			}
		}
	}

	if (prop->child) {
		func0f168f24(prop->child, true, playerpos, activeslots, distances);
	}

	if (inchild && prop->next) {
		func0f168f24(prop->next, inchild, playerpos, activeslots, distances);
	}
}

void lv_find_threats(void)
{
	s32 i;
	struct prop *prop;
	f32 distances[ARRAYCOUNT(g_Vars.currentplayer->trackedprops)] = {0};
	s32 activeslots[ARRAYCOUNT(g_Vars.currentplayer->trackedprops)] = {false};
	struct prop **propptr = g_Vars.endonscreenprops - 1;
	struct coord campos;

	campos.x = g_Vars.currentplayer->cam_pos.x;
	campos.y = g_Vars.currentplayer->cam_pos.y;
	campos.z = g_Vars.currentplayer->cam_pos.z;

	while (propptr >= g_Vars.onscreenprops) {
		prop = *propptr;

		if (prop) {
			func0f168f24(prop, false, &campos, activeslots, distances);
		}

		propptr--;
	}

	for (i = 0; i != ARRAYCOUNT(activeslots); i++) {
		if (!activeslots[i]) {
			g_Vars.currentplayer->trackedprops[i].prop = NULL;
			g_Vars.currentplayer->trackedprops[i].x1 = -1;
			g_Vars.currentplayer->trackedprops[i].x2 = -2;
		}
	}

	propptr = g_Vars.endonscreenprops - 1;

	while (propptr >= g_Vars.onscreenprops) {
		prop = *propptr;

		if (prop) {
			lv_find_threats_for_prop(prop, false, &campos, activeslots, distances);
		}

		propptr--;
	}
}

/**
 * Renders a complete frame for all players, and also does some other game logic
 * that really doesn't belong here.
 *
 * This function is pretty big, so here's an overview of its structure:
 *
 * if (stage == STAGE_TITLE) {
 *     // title screen rendering
 * } else if (stage == STAGE_BOOTPAKMENU) {
 *     // boot pak menu rendering
 * } else if (stage == STAGE_4MBMENU) {
 *     // 4MB menu rendering
 * } else if (stage == STAGE_CREDITS) {
 *     // credits rendering
 * } else {
 *     for (i = 0; i < numplayers; i++) {
 *         // rendering and logic per player
 *     }
 * }
 * // logic for auto-playing cutscene advancement
 *
 * The player loop takes up the majority of the function. In addition to
 * rendering the scene and HUD, it also handles the following logic:
 * - decreasing dizziness
 * - detecting if the prop being looked at is still valid
 * - pressing Z when using eyespy
 * - opening doors and reloading
 * - random static in the Infiltration intro cutscene
 * - combat boost activation and reverting
 */
Gfx *lv_render(Gfx *gdl)
{
	gSPSegment(gdl++, SPSEGMENT_PHYSICAL, 0x00000000);

#if VERSION >= VERSION_NTSC_1_0
	func0f0d5a7c();
#endif

	if (g_Vars.stagenum == STAGE_TITLE
			|| (g_Vars.stagenum == STAGE_TEST_OLD && title_is_keeping_mode())) {
		gSPDisplayList(gdl++, &var800613a0);

		if (debug_is_z_buffer_disabled()) {
			gSPDisplayList(gdl++, &var80061360);
		} else {
			gSPDisplayList(gdl++, &var80061380);
		}

		gdl = vi_prepare_zbuf(gdl);
		gdl = vi0000b1d0(gdl);

		gDPSetScissorFrac(gdl++, 0,
				vi_get_view_left() * 4.0f, vi_get_view_top() * 4.0f,
				(vi_get_view_left() + vi_get_view_width()) * 4.0f,
				(vi_get_view_top() + vi_get_view_height()) * 4.0f);

		gdl = title_render(gdl);
		gdl = lv_render_fade(gdl);
	} else if (g_Vars.stagenum == STAGE_BOOTPAKMENU) {
		gSPClipRatio(gdl++, FRUSTRATIO_2);
		gSPDisplayList(gdl++, &var800613a0);
		gSPDisplayList(gdl++, &var80061380);

		set_current_player_num(0);
		vi_set_view_position(g_Vars.currentplayer->viewleft, g_Vars.currentplayer->viewtop);
		vi_set_fov_aspect_and_size(g_Vars.currentplayer->fovy, g_Vars.currentplayer->aspect,
				g_Vars.currentplayer->viewwidth, g_Vars.currentplayer->viewheight);
		mtx00016748(1);

		gdl = vi0000b1d0(gdl);
		gdl = vi_render_viewport_edges(gdl);
		gdl = bg_scissor_to_viewport(gdl);
		gdl = menu_render(gdl);
	} else if (g_Vars.stagenum == STAGE_4MBMENU) {
		gSPClipRatio(gdl++, FRUSTRATIO_2);
		gSPDisplayList(gdl++, &var800613a0);
		gSPDisplayList(gdl++, &var80061380);

		set_current_player_num(0);

#if VERSION >= VERSION_PAL_BETA
		vi_set_mode(VIMODE_LO);
		vi_set_view_position(g_Vars.currentplayer->viewleft, g_Vars.currentplayer->viewtop);
		vi_set_size(player_get_fb_width(), player_get_fb_height());
		vi_set_buf_size(player_get_fb_width(), player_get_fb_height());
		vi_set_view_size(player_get_fb_width(), player_get_fb_height());
#else
		vi_set_view_position(g_Vars.currentplayer->viewleft, g_Vars.currentplayer->viewtop);
#endif

		vi_set_fov_aspect_and_size(g_Vars.currentplayer->fovy, g_Vars.currentplayer->aspect,
				g_Vars.currentplayer->viewwidth, g_Vars.currentplayer->viewheight);

		mtx00016748(1);

		gdl = vi0000b1d0(gdl);
		gdl = bg_scissor_to_viewport(gdl);
		gdl = menu_render(gdl);

		if (g_Vars.currentplayer->pausemode != PAUSEMODE_UNPAUSED) {
			player_tick_pause_menu();
		}
	} else if (g_Vars.stagenum == STAGE_CREDITS) {
		gSPClipRatio(gdl++, FRUSTRATIO_2);
		gSPDisplayList(gdl++, &var800613a0);
		gSPDisplayList(gdl++, &var80061380);

		set_current_player_num(0);
		vi_set_view_position(g_Vars.currentplayer->viewleft, g_Vars.currentplayer->viewtop);
		vi_set_fov_aspect_and_size(g_Vars.currentplayer->fovy, g_Vars.currentplayer->aspect,
				g_Vars.currentplayer->viewwidth, g_Vars.currentplayer->viewheight);
		mtx00016748(1);

		gdl = vi0000b1a8(gdl);
		gdl = vi0000b1d0(gdl);
		gdl = vi_render_viewport_edges(gdl);
		gdl = credits_draw(gdl);
	} else {
		// Normal stages
		s32 i;
		s32 playercount;
		Gfx *savedgdl;
#if VERSION >= VERSION_NTSC_1_0
		bool forcesingleplayer = (g_Vars.coopplayernum >= 0 || g_Vars.antiplayernum >= 0)
			&& player_has_shared_viewport();
#else
		bool forcesingleplayer = (g_Vars.coopplayernum >= 0 || g_Vars.antiplayernum >= 0)
			&& ((g_InCutscene && !g_MainIsEndscreen) || menu_get_root() == MENUROOT_COOPCONTINUE);
#endif
		struct player *player;
		struct chrdata *chr;

		playercount = forcesingleplayer ? 1 : PLAYERCOUNT();

		gSPClipRatio(gdl++, FRUSTRATIO_2);

		for (i = 0; i < playercount; i++) {
			bool islastplayer;
			u32 bluramount = 0;

			savedgdl = gdl;

			if (forcesingleplayer) {
				set_current_player_num(0);
				g_Vars.currentplayerindex = 0;
				islastplayer = true;
			} else {
				s32 nextplayernum = i + 1;
				set_current_player_num(playermgr_get_player_at_order(i));
				islastplayer = playercount == nextplayernum;
			}

			// Calculate bluramount - this will be used later
			if (g_Vars.tickmode != TICKMODE_CUTSCENE) {
				player = g_Vars.currentplayer;
				chr = player->prop->chr;

				if (chr->blurdrugamount > 0
						&& !g_Vars.currentplayer->invincible
						&& !g_Vars.currentplayer->training) {
					bluramount = (chr->blurdrugamount * 130) / TICKS(5000) + 100;

					if (bluramount > 230) {
						bluramount = 230;
					}

					if (chr->blurdrugamount > TICKS(5000)) {
						chr->blurdrugamount = TICKS(5000);
					}

					chr->blurdrugamount -= g_Vars.lvupdate60 * (chr->blurnumtimesdied + 1);

					if (chr->blurdrugamount < 1) {
						chr->blurdrugamount = 0;
						chr->blurnumtimesdied = 0;
					}
				}
			}

			bview_set_motion_blur(bluramount);

			gSPDisplayList(gdl++, &var800613a0);

			if (debug_is_z_buffer_disabled()) {
				gSPDisplayList(gdl++, &var80061360);
			} else {
				gSPDisplayList(gdl++, &var80061380);
			}

			vi_set_view_position(g_Vars.currentplayer->viewleft, g_Vars.currentplayer->viewtop);
			vi_set_fov_aspect_and_size(g_Vars.currentplayer->fovy, g_Vars.currentplayer->aspect,
					g_Vars.currentplayer->viewwidth, g_Vars.currentplayer->viewheight);
			mtx00016748(g_Vars.currentplayerstats->scale_bg2gfx);
			env_tick();
			zbuf_swap();
			gdl = vi_prepare_zbuf(gdl);
			gdl = vi0000b1d0(gdl);
			gdl = bg_scissor_to_viewport(gdl);
			artifacts_clear();

			if ((g_Vars.stagenum != STAGE_CITRAINING || (var80087260 <= 0 && g_MenuData.root != MENUROOT_MPSETUP))
					&& g_Vars.lvframenum <= 5
					&& !g_Vars.normmplayerisrunning
					&& g_Vars.tickmode != TICKMODE_CUTSCENE) {
				if (var80084050 < 6) {
					g_Vars.lockscreen = 1;
				}

				var80084050++;
			} else if (g_Vars.currentplayer->gunctrl.loadall
					&& var80075d60 == 2
					&& g_Vars.currentplayer->cameramode != CAMERAMODE_THIRDPERSON
					&& g_Vars.currentplayer->cameramode != CAMERAMODE_EYESPY
					&& var8009dfc0 == 0) {
				g_Vars.currentplayer->gunctrl.loadall = bgun_load_all();
			}

			if (g_Vars.lockscreen) {
				gdl = bview_draw_motion_blur(gdl, 0xffffffff, 255);
				g_Vars.lockscreen--;
			} else if (var8009dfc0) {
				gdl = vi_render_viewport_edges(gdl);
				gdl = bg_scissor_to_viewport(gdl);
				mtx00016748(1);

				if (g_Vars.currentplayer->menuisactive) {
					gdl = menu_render(gdl);
				}
			} else {
				if (var80075d60 == 2) {
					gdl = player_update_shoot_rot(gdl);
				}

				gdl = vi_render_viewport_edges(gdl);
				gdl = sky_render(gdl);
				bg_tick();
				lights_tick();
				props_tick_player(islastplayer);
				scenario_tick_chr(NULL);
				props_sort();
				autoaim_tick();
				hands_tick_attack();

				// Calculate lookingatprop
				if (PLAYERCOUNT() == 1
						|| g_Vars.coopplayernum >= 0
						|| g_Vars.antiplayernum >= 0
						|| (weapon_has_flag(bgun_get_weapon_num(HAND_RIGHT), WEAPONFLAG_AIMTRACK) && bmove_is_in_sight_aim_mode())) {
					g_Vars.currentplayer->lookingatprop.prop = prop_find_aiming_at(HAND_RIGHT, false, FINDPROPCONTEXT_QUERY);

					if (g_Vars.currentplayer->lookingatprop.prop) {
						if (g_Vars.currentplayer->lookingatprop.prop->type == PROPTYPE_CHR
								|| g_Vars.currentplayer->lookingatprop.prop->type == PROPTYPE_PLAYER) {
							chr = g_Vars.currentplayer->lookingatprop.prop->chr;

							if ((chr->hidden & CHRHFLAG_CLOAKED) && !USINGDEVICE(DEVICE_IRSCANNER)) {
								g_Vars.currentplayer->lookingatprop.prop = NULL;
							}
						} else if (g_Vars.currentplayer->lookingatprop.prop->type == PROPTYPE_OBJ
								|| g_Vars.currentplayer->lookingatprop.prop->type == PROPTYPE_WEAPON
								|| g_Vars.currentplayer->lookingatprop.prop->type == PROPTYPE_DOOR) {
							struct defaultobj *obj = g_Vars.currentplayer->lookingatprop.prop->obj;

							if ((obj->flags3 & OBJFLAG3_REACTTOSIGHT) == 0) {
								if (g_Vars.stagenum != STAGE_CITRAINING
										|| (obj->modelnum != MODEL_TARGET
											&& obj->modelnum != MODEL_CIHUB
											&& obj->modelnum != MODEL_COMHUB)) {
									g_Vars.currentplayer->lookingatprop.prop = NULL;
								}
							}
						} else {
							g_Vars.currentplayer->lookingatprop.prop = NULL;
						}
					}
				} else {
					g_Vars.currentplayer->lookingatprop.prop = NULL;
				}

				if (gset_has_function_flags(&g_Vars.currentplayer->hands[0].gset, FUNCFLAG_THREATDETECTOR)) {
					lv_find_threats();
				} else if (weapon_has_flag(bgun_get_weapon_num(HAND_RIGHT), WEAPONFLAG_AIMTRACK)) {
					s32 j;

					if (fr_is_in_training()
							&& g_Vars.currentplayer->lookingatprop.prop
							&& bmove_is_in_sight_aim_mode()) {
						func0f1a0924(g_Vars.currentplayer->lookingatprop.prop);
					} else if (lv_update_tracked_prop(&g_Vars.currentplayer->lookingatprop, -1) == 0) {
						g_Vars.currentplayer->lookingatprop.prop = NULL;
					}

					for (j = 0; j < ARRAYCOUNT(g_Vars.currentplayer->trackedprops); j++) {
						if (!lv_update_tracked_prop(&g_Vars.currentplayer->trackedprops[j], j)) {
							g_Vars.currentplayer->trackedprops[j].x1 = -1;
							g_Vars.currentplayer->trackedprops[j].x2 = -2;
						}
					}
				}

				// Handle eyespy Z presses
				if (g_Vars.currentplayer->eyespy
						&& (g_Vars.currentplayer->devicesactive & ~g_Vars.currentplayer->devicesinhibit & DEVICE_EYESPY)
						&& g_Vars.currentplayer->eyespy->camerabuttonheld) {
					if (g_Vars.currentplayer->eyespy->mode == EYESPYMODE_CAMSPY) {
						objective_check_holograph(400);
						snd_start(var80095200, SFX_CAMSPY_SHUTTER, 0, -1, -1, -1, -1, -1);
					} else if (g_Vars.currentplayer->eyespy->mode == EYESPYMODE_DRUGSPY) {
						if (g_Vars.currentplayer->eyespydarts) {
							// Fire dart
							struct coord direction;
							snd_start(var80095200, SFX_DRUGSPY_FIREDART, 0, -1, -1, -1, -1, -1);
							g_Vars.currentplayer->eyespydarts--;

							direction.x = g_Vars.currentplayer->eyespy->look.x;
							direction.y = g_Vars.currentplayer->eyespy->look.y;
							direction.z = g_Vars.currentplayer->eyespy->look.z;

							projectile_create(g_Vars.currentplayer->eyespy->prop, 0,
									&g_Vars.currentplayer->eyespy->prop->pos, &direction, WEAPON_TRANQUILIZER, NULL);
						} else {
							// No dart ammo
							snd_start(var80095200, SFX_FIREEMPTY, 0, -1, -1, -1, -1, -1);
						}
					} else { // EYESPYMODE_BOMBSPY
						struct coord vel = {0, 0, 0};
						struct gset gset = {WEAPON_GRENADE, 0, 0, FUNC_PRIMARY};
						explosion_create_simple(g_Vars.currentplayer->eyespy->prop,
								&g_Vars.currentplayer->eyespy->prop->pos,
								g_Vars.currentplayer->eyespy->prop->rooms,
								EXPLOSIONTYPE_DRAGONBOMBSPY, 0);
						chr_begin_death(g_Vars.currentplayer->eyespy->prop->chr, &vel, 0, 0, &gset, false, 0);
					}
				}

				// Handle opening doors and reloading
				if (g_Vars.currentplayer->bondactivateorreload) {
					if (current_player_interact(false)) {
						bgun_reload_if_possible(HAND_RIGHT);
						bgun_reload_if_possible(HAND_LEFT);
					}
				} else if (g_Vars.currentplayer->eyespy
						&& g_Vars.currentplayer->eyespy->active
						&& g_Vars.currentplayer->eyespy->opendoor) {
					current_player_interact(true);
				}

				props_test_for_pickup();
				gdl = bg_render(gdl);
				chranimdebug_everyone(var80075d68 == 15 || g_AnimHostEnabled);
				gdl = props_render_beams(gdl);
				gdl = shards_render(gdl);
				gdl = sparks_render(gdl);
				gdl = weather_render(gdl);

				if (g_NbombsActive) {
					gdl = nbombs_render(gdl);
				}

				if (var80075d60 == 2) {
					gdl = player_render_hud(gdl);

#ifdef DEBUG
					gdl = lv_render_man_pos_if_enabled(gdl);
#endif
				} else {
					gdl = boltbeams_render(gdl);

					if (g_Vars.currentplayer->visionmode != VISIONMODE_XRAY) {
						gdl = bg_render_artifacts(gdl);
					}
				}

				if (g_DebugScreenshotRgb <= 0) {
					static struct sndstate *g_CutsceneStaticAudioHandle = NULL;
					static s32 g_CutsceneStaticTimer = 100;
					static u8 g_CutsceneStaticActive = false;
					bool cutscenehasstatic = false;
					u32 alpha;

					if (g_Vars.tickmode == TICKMODE_CUTSCENE) {
						// This chunk of code is unreachable
						// (STAGE_TEST_OLD is not used)
#if VERSION < VERSION_PAL_BETA
						if (g_Vars.stagenum == STAGE_TEST_OLD) {
							f32 frac = 0;
							u32 colour;
							s32 endframe = anim_get_num_frames(g_CutsceneAnimNum) - 1;

							colour = 0;

							if (g_CutsceneCurAnimFrame60 < 90) {
								frac = 1.0f - (f32)g_CutsceneCurAnimFrame60 / 90.0f;
							}

							if (g_CutsceneAnimNum != ANIM_CUT_OLD_TITLE_CAM_04) {
								if (g_CutsceneCurAnimFrame60 > endframe - 90) {
									frac = (g_CutsceneCurAnimFrame60 - endframe + 90) / 90.0f;
								}
							} else {
								if (g_CutsceneCurAnimFrame60 > endframe - 30) {
									colour = 0xffffff00;
									frac = (g_CutsceneCurAnimFrame60 - endframe + 30) / 30.0f;
								}
							}

							if (frac > 0) {
								alpha = 255 * frac;

								gDPPipeSync(gdl++);
								gDPSetRenderMode(gdl++, G_RM_CLD_SURF, G_RM_CLD_SURF2);
								gDPSetCombineMode(gdl++, G_CC_PRIMITIVE, G_CC_PRIMITIVE);
								gDPSetPrimColorViaWord(gdl++, 0, 0, colour | alpha);

								gDPFillRectangle(gdl++,
									vi_get_view_left(),
									vi_get_view_top(),
									vi_get_view_left() + vi_get_view_width(),
									vi_get_view_top() + vi_get_view_height());

								gdl = text0f153838(gdl);
							}
						}
#endif

						// Handle visual effects in cutscenes
						switch (g_CutsceneAnimNum) {
						case ANIM_CUT_CAVE_INTRO_CAM:
							// Horizon scanner in Air Base intro
							if (g_CutsceneCurAnimFrame60 > 839 && g_CutsceneCurAnimFrame60 < 1411) {
								gdl = bview_draw_horizon_scanner(gdl);
							}
							break;
						case ANIM_CUT_LUE_INTRO_CAM_01:
						case ANIM_CUT_LUE_INTRO_CAM_02:
						case ANIM_CUT_LUE_INTRO_CAM_03:
							{
								// Show static randomly in Infiltration intro
								s32 cutscenestatic = 0;
								cutscenehasstatic = true;

								if (g_CutsceneStaticAudioHandle == NULL) {
									snd_start(var80095200, SFX_INFIL_STATIC_LONG, &g_CutsceneStaticAudioHandle, -1, -1, -1, -1, -1);
								}

								g_CutsceneStaticTimer -= g_Vars.diffframe60;

								if (g_CutsceneStaticTimer < 0) {
									g_CutsceneStaticTimer = random() % TICKS(200) + TICKS(40);
									g_CutsceneStaticActive = false;
								}

								gdl = bview_draw_film_interlace(gdl, 0xffffffff, 0xffffffff);

								if (g_CutsceneStaticTimer < TICKS(15)) {
									if (g_CutsceneStaticActive == false) {
										g_CutsceneStaticActive = true;
										snd_start(var80095200, SFX_INFIL_STATIC_MEDIUM, NULL, -1, -1, -1, -1, -1);
									}

									cutscenestatic = 225 - g_CutsceneStaticTimer * PALUP(10);
								}

								// Consider a single frame of static, separate
								// to the main static above
								if (random() % 60 == 1) {
									cutscenestatic = 255;
									snd_start(var80095200, SFX_INFIL_STATIC_SHORT, NULL, -1, -1, -1, -1, -1);
								}

								if (cutscenestatic) {
									gdl = bview_draw_static(gdl, 0xffffffff, cutscenestatic);
								}
							}
							break;
						}
					}

					if (g_CutsceneStaticAudioHandle && !cutscenehasstatic) {
						audioStop(g_CutsceneStaticAudioHandle);
					}

					// Slayer rocket shows static when flying out of bounds
					if (g_Vars.currentplayer->visionmode == VISIONMODE_SLAYERROCKET
							&& g_Vars.tickmode != TICKMODE_CUTSCENE) {
						gdl = bview_draw_slayer_rocket_interlace(gdl, 0xffffffff, 0xffffffff);

						if (g_Vars.currentplayer->badrockettime > 0) {
							u32 slayerstatic = g_Vars.currentplayer->badrockettime * 255 / TICKS(90);

							if (slayerstatic > 255) {
								slayerstatic = 255;
							}

							gdl = bview_draw_static(gdl, 0x4fffffff, slayerstatic);
						}
					}

#if VERSION >= VERSION_NTSC_1_0
					if (g_Vars.currentplayer->visionmode == VISIONMODE_SLAYERROCKETSTATIC) {
						gdl = bview_draw_static(gdl, 0x4fffffff, 255);
						g_Vars.currentplayer->visionmode = VISIONMODE_NORMAL;
					}
#endif

					if (g_Vars.currentplayer->visionmode == VISIONMODE_XRAY
							&& g_Vars.tickmode != TICKMODE_CUTSCENE) {
						s32 xraything = 99;

						if (g_Vars.currentplayer->erasertime < TICKS(200)) {
#if PAL
							xraything = 249 - ((g_Vars.currentplayer->erasertime * 180 / 50) >> 2);
#else
							xraything = 249 - (g_Vars.currentplayer->erasertime * 3 >> 2);
#endif
						}

						gdl = bview_draw_zoom_blur(gdl, 0xffffffff, xraything, 1.05f, 1.05f);
					}

					// Handle combat boosts
					if ((g_Vars.speedpillchange > 0 && g_Vars.speedpillchange < (PAL ? 26 : 30))
							|| (g_Vars.speedpillwant && !g_Vars.speedpillon)
							|| (!g_Vars.speedpillwant && g_Vars.speedpillon)) {
						if (g_Vars.speedpillchange == (PAL ? 26 : 30) && !g_Vars.speedpillwant) {
							snd_start(var80095200, lv_get_slow_motion_type() ? SFX_JO_BOOST_ACTIVATE : SFX_ARGH_JO_02AD, 0, -1, -1, -1, -1, -1);
						}

						if (g_Vars.speedpillchange < (PAL ? 13 : 15)) {
							gdl = bview_draw_zoom_blur(gdl, 0xffffffff,
									g_Vars.speedpillchange * 180 / (PAL ? 13 : 15),
									(f32)g_Vars.speedpillchange * (PAL ? 0.023076923564076f : 0.02000000141561f) + 1.1f,
									(f32)g_Vars.speedpillchange * (PAL ? 0.023076923564076f : 0.02000000141561f) + 1.1f);
							gdl = player_draw_fade(gdl, 0xff, 0xff, 0xff,
									g_Vars.speedpillchange * (PAL ? 0.0076923076994717f : 0.0066666668280959f));
						} else {
							gdl = bview_draw_zoom_blur(gdl, 0xffffffff,
									((PAL ? 26 : 30) - g_Vars.speedpillchange) * 180 / (PAL ? 13 : 15),
									(f32)((PAL ? 26 : 30) - g_Vars.speedpillchange) * (PAL ? 0.023076923564076f : 0.02000000141561f) + 1.1f,
									(f32)((PAL ? 26 : 30) - g_Vars.speedpillchange) * (PAL ? 0.023076923564076f : 0.02000000141561f) + 1.1f);
							gdl = player_draw_fade(gdl, 0xff, 0xff, 0xff,
									((PAL ? 26.0f : 30.0f) - g_Vars.speedpillchange) * (PAL ? 0.0076923076994717f : 0.0066666668280959f));
						}

						if (g_Vars.currentplayernum == 0) {
							if (g_Vars.speedpillwant) {
								g_Vars.speedpillchange++;
							} else {
								g_Vars.speedpillchange--;
							}
						}

						if (g_Vars.speedpillchange > (PAL ? 26 : 30)) {
							g_Vars.speedpillchange = (PAL ? 26 : 30);
						} else if (g_Vars.speedpillchange < 0) {
							g_Vars.speedpillchange = 0;
						}
					}

					if (g_Vars.speedpillchange > (PAL ? 13 : 15)) {
						g_Vars.speedpillon = true;
					} else {
						g_Vars.speedpillon = false;
					}

					if (bluramount) {
						bview_clear_motion_blur();
						gdl = bview_draw_motion_blur(gdl, 0xffffffff, bluramount);
					}

					// Handle blur effect in cutscenes (Extraction intro?)
					if (g_Vars.tickmode == TICKMODE_CUTSCENE) {
						f32 cutsceneblurfrac = player_get_cutscene_blur_frac();

						if (cutsceneblurfrac > 0) {
#if VERSION < VERSION_PAL_BETA
							u32 stack;
#endif
							gdl = bview_draw_motion_blur(gdl, 0xffffff00, cutsceneblurfrac * 255);
						}
					}

#if VERSION >= VERSION_PAL_FINAL
					if (bluramount);
					if (bluramount);
					if (bluramount);
#elif VERSION >= VERSION_NTSC_1_0
					if (bluramount);
					if (bluramount);
#else
					if (bluramount);
					if (bluramount);
					if (bluramount);
#endif

					if (debug_get_motion_blur() == 1) {
						gdl = bview_draw_motion_blur(gdl, 0xffffff00, 128);
					} else if (debug_get_motion_blur() == 2) {
						gdl = bview_draw_motion_blur(gdl, 0xffffff00, 192);
					} else if (debug_get_motion_blur() == 3) {
						gdl = bview_draw_motion_blur(gdl, 0xffffff00, 230);
					}

					// Render white when teleporting
					if (g_Vars.currentplayer->teleportstate > TELEPORTSTATE_INACTIVE) {
						alpha = 0;

						if (g_Vars.currentplayer->teleportstate == TELEPORTSTATE_WHITE) {
							alpha = 255;
						}

						if (g_Vars.currentplayer->teleportstate == TELEPORTSTATE_EXITING
								&& g_Vars.currentplayer->teleporttime < 16) {
							alpha = -g_Vars.currentplayer->teleporttime * 16 + 240;
						}

						if (g_Vars.currentplayer->teleportstate == TELEPORTSTATE_ENTERING) {
							if (g_Vars.currentplayer->teleporttime > 32) {
								alpha = g_Vars.currentplayer->teleporttime * 16 - 512;
							}

							if (g_Vars.currentplayer->teleporttime == 48) {
								alpha = 255;
							}
						}

						if (alpha) {
							gdl = text0f153628(gdl);
							gdl = text0f153a34(gdl,
									vi_get_view_left(), vi_get_view_top(),
									vi_get_view_left() + vi_get_view_width(),
									vi_get_view_top() + vi_get_view_height(), 0xffffff00 | alpha);
							gdl = text0f153780(gdl);
						}
					}
				}

#if VERSION >= VERSION_NTSC_1_0
				gdl = scenario_render_hud(gdl);
				gdl = lv_render_fade(gdl);
#else
				gdl = lv_render_fade(gdl);
				gdl = scenario_render_hud(gdl);
#endif

				if (g_FrIsValidWeapon) {
					gdl = fr_render_hud(gdl);
				}

				if (debug_get_tiles_debug_mode() != 0
						|| debug_get_pads_debug_mode() != 0
						|| debug0f11eea8()
						|| debug0f11ef80()
						|| debug_is_chr_stats_enabled()
						|| debug0f11ee40()) {
#if VERSION < VERSION_NTSC_1_0
					RoomNum spc8[21];
					RoomNum spb0[11];
					RoomNum sp9c[10];
					s32 j;

					sp9c[0] = g_Vars.currentplayer->memcamroom;
					sp9c[1] = -1;

					for (j = 0; sp9c[j] != -1; j++) {
						spc8[j] = sp9c[j];
					}

					spc8[j] = -1;

					for (j = 0; sp9c[j] != -1; j++) {
						bg_room_get_neighbours(sp9c[j], spb0, 10);
						rooms_append(spb0, spc8, 20);
					}

					if (debug_is_chr_stats_enabled()) {
						gdl = chrs_render_chr_stats(gdl, spc8);
					}
#endif
				}

				gdl = sky_render_overexposure(gdl);
				gdl = am_render(gdl);
				mtx00016748(1);

				if (g_Vars.currentplayer->menuisactive) {
					gdl = menu_render(gdl);
				}

				mtx00016748(g_Vars.currentplayerstats->scale_bg2gfx);

				if (g_Vars.mplayerisrunning) {
					gdl = mp_render_modal_text(gdl);
				}

				if (g_Vars.currentplayer->dostartnewlife) {
					player_start_new_life();
				}
			}

			artifacts_tick();

			if ((g_Vars.coopplayernum >= 0 || g_Vars.antiplayernum >= 0)
#if VERSION >= VERSION_NTSC_1_0
					&& player_has_shared_viewport()
#else
					&& ((g_InCutscene && !g_MainIsEndscreen) || menu_get_root() == MENUROOT_COOPCONTINUE)
#endif
					&& g_Vars.currentplayernum != 0) {
				gdl = savedgdl;
			}
		} // end of player loop
	} // end of stage if-statements

	if (g_Vars.autocutplaying && g_Vars.autocutfinished) {
		g_Vars.autocutplaying = false;
		g_Vars.autocutfinished = false;

		if (g_Vars.autocutgroupskip) {
			g_Vars.autocutgroupcur = -1;
			g_Vars.autocutgroupleft = 0;
		}

		if (g_Vars.autocutgroupcur < 0 && g_Vars.autocutgroupleft <= 0) {
			main_change_to_stage(STAGE_TITLE);
		}
	}

	// Advance the cutscenes when autoplaying
	if (!g_Vars.autocutplaying && g_Vars.autocutgroupcur >= 0 && g_Vars.autocutgroupleft > 0) {
		hudmsg_remove_all();

		g_Vars.autocutnum = g_Cutscenes[g_Vars.autocutgroupcur].scene;

#if VERSION < VERSION_NTSC_1_0
		if (main_get_stage_num() != g_Cutscenes[g_Vars.autocutgroupcur].stage)
#endif
		{
			g_MissionConfig.iscoop = false;
			g_Vars.mplayerisrunning = false;
			g_Vars.normmplayerisrunning = false;
			g_Vars.bondplayernum = 0;
			g_Vars.coopplayernum = -1;
			g_Vars.antiplayernum = -1;
			g_MissionConfig.isanti = false;
			set_num_players(1);
			title_set_next_mode(TITLEMODE_SKIP);
			g_MissionConfig.difficulty = DIFF_A;
			lv_set_difficulty(DIFF_A);
			g_MissionConfig.stageindex = g_Cutscenes[g_Vars.autocutgroupcur].mission;
			g_MissionConfig.stagenum = g_Cutscenes[g_Vars.autocutgroupcur].stage;
			title_set_next_stage(g_Cutscenes[g_Vars.autocutgroupcur].stage);
			main_change_to_stage(g_Cutscenes[g_Vars.autocutgroupcur].stage);
		}

		g_Vars.autocutgroupleft--;

		if (g_Vars.autocutgroupleft > 0) {
			g_Vars.autocutgroupcur++;
		} else {
			g_Vars.autocutgroupcur = -1;
		}
	}

	gDPSetScissor(gdl++, G_SC_NON_INTERLACE, 0, 0, vi_get_width(), vi_get_height());

#if VERSION < VERSION_NTSC_1_0
	if ((uintptr_t)gdl < (uintptr_t)g_GfxBuffers[g_GfxActiveBufferIndex]
			|| (uintptr_t)gdl > (uintptr_t)g_GfxBuffers[g_GfxActiveBufferIndex + 1]) {
		crash_set_message("lv.c Master DL overrun!");
		CRASH();
	}
#endif

	return gdl;
}

const char var7f1b7730[] = "fr: %d\n";

u32 g_CutsceneTime240_60 = 0;

#if VERSION >= VERSION_NTSC_1_0
u32 var800840a8 = 0;
u32 var800840ac = 0;
u32 var800840b0 = 0;
#else
u32 var80086930nb = 0;
u32 var800840a8 = 0;
u32 var800840ac = 0;
u32 var800840b0 = 0;
#endif

u32 var800840b4 = 0;

void lv_update_solo_handicaps(void)
{
	if (g_Vars.antiplayernum >= 0) {
		if (g_Difficulty == DIFF_A) {
			g_CctvWaitScale = 2;
			g_CctvDamageRxScale = 2;
			g_AutogunAccuracyScale = 0.5f;
			g_AutogunDamageTxScale = 0.5f;
			g_AutogunDamageRxScale = 2;
			g_EnemyAccuracyScale = 0.5f;
			g_PlayerDamageRxScale = 0.35f;
			g_PlayerDamageTxScale = 4;
			g_ExplosionDamageTxScale = 0.25f;
			g_AutoAimScale = 1.5f;
			g_AmmoQuantityScale = 3;
			g_AttackWalkDurationScale = 0.2f;
		} else if (g_Difficulty == DIFF_SA) {
			g_CctvWaitScale = 2;
			g_CctvDamageRxScale = 1.5f;
			g_AutogunAccuracyScale = 0.5f;
			g_AutogunDamageTxScale = 0.5f;
			g_AutogunDamageRxScale = 1.5f;
			g_EnemyAccuracyScale = 0.6f;
			g_PlayerDamageRxScale = 0.5f;
			g_PlayerDamageTxScale = 3;
			g_ExplosionDamageTxScale = 0.25f;
			g_AutoAimScale = 1.1f;
			g_AmmoQuantityScale = 2.5f;
			g_AttackWalkDurationScale = 0.5f;
		} else {
			g_CctvWaitScale = 2;
			g_CctvDamageRxScale = 1;
			g_AutogunAccuracyScale = 0.5f;
			g_AutogunDamageTxScale = 0.5f;
			g_AutogunDamageRxScale = 1;
			g_EnemyAccuracyScale = 0.7f;
			g_PlayerDamageRxScale = 0.65f;
			g_PlayerDamageTxScale = 2;
			g_ExplosionDamageTxScale = 0.25f;
			g_AutoAimScale = 0.75f;
			g_AmmoQuantityScale = 2;
			g_AttackWalkDurationScale = 1;
		}
	} else if (g_Vars.coopplayernum >= 0) {
		if (g_Difficulty == DIFF_A) {
			g_CctvWaitScale = 2;
			g_CctvDamageRxScale = 2;
			g_AutogunAccuracyScale = 0.5f;
			g_AutogunDamageTxScale = 0.5f;
			g_AutogunDamageRxScale = 2;
			g_EnemyAccuracyScale = 0.6f;
			g_PlayerDamageRxScale = 0.5f;
			g_PlayerDamageTxScale = 2;
			g_ExplosionDamageTxScale = 0.25f;
			g_AutoAimScale = 1.5f;
			g_AmmoQuantityScale = 2;
			g_AttackWalkDurationScale = 0.2f;
		} else if (g_Difficulty == DIFF_SA) {
			g_CctvWaitScale = 1;
			g_CctvDamageRxScale = 1;
			g_AutogunAccuracyScale = 0.75f;
			g_AutogunDamageTxScale = 1;
			g_AutogunDamageRxScale = 1;
			g_EnemyAccuracyScale = 0.75f;
			g_PlayerDamageRxScale = 1;
			g_PlayerDamageTxScale = 1;
			g_ExplosionDamageTxScale = 1;
#if VERSION >= VERSION_JPN_FINAL
			g_AutoAimScale = 0.75f;
#else
			g_AutoAimScale = g_Jpn ? 1.1f : 0.75f;
#endif
			g_AmmoQuantityScale = 1.5f;
			g_AttackWalkDurationScale = 0.5f;
		} else {
			g_CctvWaitScale = 1;
			g_CctvDamageRxScale = 1;
			g_AutogunAccuracyScale = 1;
			g_AutogunDamageTxScale = 1.5f;
			g_AutogunDamageRxScale = 1;
			g_EnemyAccuracyScale = 1.5f;
			g_PlayerDamageRxScale = 1.5f;
			g_PlayerDamageTxScale = 1;
			g_ExplosionDamageTxScale = 1.5f;
#if VERSION >= VERSION_JPN_FINAL
			g_AutoAimScale = 0.2f;
#else
			g_AutoAimScale = g_Jpn ? 0.75f : 0.2f;
#endif
			g_AmmoQuantityScale = 1;
			g_AttackWalkDurationScale = 1;
		}
	} else {
		if (g_Difficulty == DIFF_A) {
			f32 totalhealth;
			f32 frac = 1;

			if (g_Vars.coopplayernum < 0 && g_Vars.antiplayernum < 0) {
				totalhealth = player_get_health_frac() + player_get_shield_frac();

				if (totalhealth <= 0.125f) {
					frac = 0.5f;
				} else if (totalhealth <= 0.6f) {
					frac = (totalhealth - 0.125f) * 0.5f / 0.47500002384186f + 0.5f;
				}
			}

			g_CctvWaitScale = 2;
			g_CctvDamageRxScale = 2;
			g_AutogunAccuracyScale = 0.5f * frac;
			g_AutogunDamageTxScale = 0.5f * frac;
			g_AutogunDamageRxScale = 2;
			g_EnemyAccuracyScale = 0.6f;
			g_PlayerDamageRxScale = 0.5f * frac;
			g_PlayerDamageTxScale = 2;
			g_ExplosionDamageTxScale = 0.25f * frac;
			g_AutoAimScale = 1.5f;
			g_AmmoQuantityScale = 2;
			g_AttackWalkDurationScale = 0.2f;
		} else if (g_Difficulty == DIFF_SA) {
			g_CctvWaitScale = 1;
			g_CctvDamageRxScale = 1;
			g_AutogunAccuracyScale = 0.75f;
			g_AutogunDamageTxScale = 0.75f;
			g_AutogunDamageRxScale = 1;
			g_EnemyAccuracyScale = 0.8f;
			g_PlayerDamageRxScale = 0.6f;
			g_PlayerDamageTxScale = 1;
			g_ExplosionDamageTxScale = 0.75f;
#if VERSION >= VERSION_JPN_FINAL
			g_AutoAimScale = 0.75f;
#else
			g_AutoAimScale = g_Jpn ? 1.1f : 0.75f;
#endif
			g_AmmoQuantityScale = 1.5f;
			g_AttackWalkDurationScale = 0.5f;
		} else if (g_Difficulty == DIFF_PA) {
			g_CctvWaitScale = 1;
			g_CctvDamageRxScale = 1;
			g_AutogunAccuracyScale = 1;
			g_AutogunDamageTxScale = 1;
			g_AutogunDamageRxScale = 1;
			g_EnemyAccuracyScale = 1.175f;
			g_PlayerDamageRxScale = 1;
			g_PlayerDamageTxScale = 1;
			g_ExplosionDamageTxScale = 1;
#if VERSION >= VERSION_JPN_FINAL
			g_AutoAimScale = 0.2f;
#else
			g_AutoAimScale = g_Jpn ? 0.75f : 0.2f;
#endif
			g_AmmoQuantityScale = 1;
			g_AttackWalkDurationScale = 1;
		} else if (g_Difficulty == DIFF_PD) {
			g_CctvWaitScale = 1;
			g_CctvDamageRxScale = 1;
			g_AutogunAccuracyScale = 1;
			g_AutogunDamageTxScale = 1;
			g_AutogunDamageRxScale = 1;
			g_EnemyAccuracyScale = 1.1f;
			g_PlayerDamageRxScale = 1;
			g_PlayerDamageTxScale = 1;
			g_ExplosionDamageTxScale = 1;
			g_AutoAimScale = 1;
			g_AmmoQuantityScale = 1;
			g_AttackWalkDurationScale = 1;
		}
	}
}

#if PIRACYCHECKS

#if PAL
#define SUBAMOUNT 6661
#else
#define SUBAMOUNT 54321
#endif

s32 sub54321(s32 value)
{
	return value - SUBAMOUNT;
}
#endif

void lv_update_cutscene_time(void)
{
	if (g_Vars.in_cutscene) {
		g_CutsceneTime240_60 += g_Vars.lvupdate60;
		return;
	}

	g_CutsceneTime240_60 = 0;
}

s32 lv_get_slow_motion_type(void)
{
#if PIRACYCHECKS
#if PAL
	u32 addr = sub54321(0xb0000340 + SUBAMOUNT);
	u32 actual;
	u32 expected = sub54321(0x0330c820 + SUBAMOUNT);
#else
	u32 addr = sub54321(0xb0000a5c + SUBAMOUNT);
	u32 actual;
	u32 expected = sub54321(0x1740fff9 + SUBAMOUNT);
#endif

	osPiReadIo(addr, &actual);

	if (actual != expected) {
		u32 *ptr = (u32 *)&rspbootTextStart;
		u32 *end = (u32 *)(uintptr_t)ptr + 1024;

		while (ptr < end) {
			*ptr += 8;
			ptr++;
		}
	}
#endif

	if (g_Vars.normmplayerisrunning) {
		if (g_MpSetup.options & MPOPTION_SLOWMOTION_ON) {
			return SLOWMOTION_ON;
		}
		if (g_MpSetup.options & MPOPTION_SLOWMOTION_SMART) {
			return SLOWMOTION_SMART;
		}
	} else {
		if (cheat_is_active(CHEAT_SLOMO)) {
			return SLOWMOTION_ON;
		}
		if (debug_get_slow_motion() == SLOWMOTION_ON) {
			return SLOWMOTION_ON;
		}
		if (debug_get_slow_motion() == SLOWMOTION_SMART) {
			return SLOWMOTION_SMART;
		}
	}

	return SLOWMOTION_OFF;
}

void lv_tick(void)
{
	s32 j;
	s32 i;

	lv_check_pause_state_changed();

#if VERSION >= VERSION_NTSC_1_0
	if (g_Vars.pakstocheck) {
		paks_tick();
	}
#endif

	if (g_Vars.joydisableframestogo > 0) {
		g_Vars.joydisableframestogo--;
	} else if (g_Vars.joydisableframestogo == 0) {
#if VERSION >= VERSION_NTSC_1_0
		joy_unlock_cyclic_polling();
#else
		if (!joy_is_cyclic_polling_enabled()) {
			joy_enable_cyclic_polling(3278, "lv.c");
		}
#endif

		if (g_Vars.stagenum == STAGE_TITLE
				|| g_Vars.stagenum == STAGE_BOOTPAKMENU
				|| g_Vars.stagenum == STAGE_CREDITS
				|| g_Vars.stagenum == STAGE_4MBMENU) {
			g_Vars.paksneededforgame = 0;
		} else {
			g_Vars.paksneededforgame = 0x1f;
			pak_enable_rumble_for_all_players();
		}

		g_Vars.joydisableframestogo = -1;
	}

	if (IS4MB()) {
		vm_print_stats_if_enabled();
	}

	for (j = 0; j < PLAYERCOUNT(); j++) {
		g_Vars.players[j]->hands[HAND_LEFT].hasdotinfo = false;
		g_Vars.players[j]->hands[HAND_RIGHT].hasdotinfo = false;
	}

	if (lv_is_paused()) {
		g_Vars.lvupdate240 = 0;
	} else if (mp_is_paused()) {
		g_Vars.lvupdate240 = 0;

		for (j = 0; j < PLAYERCOUNT(); j++) {
			g_Vars.players[j]->joybutinhibit = 0xefffefff;
		}
	} else {
		s32 slowmo = lv_get_slow_motion_type();
		g_Vars.lvupdate240 = g_Vars.diffframe240;

		if (slowmo == SLOWMOTION_ON) {
			if (g_Vars.speedpillon == false || g_Vars.in_cutscene) {
				if (g_Vars.lvupdate240 > 4) {
					g_Vars.lvupdate240 = 4;
				}
			}
		} else if (slowmo == SLOWMOTION_SMART) {
			// Smart slow motion - activates if an enemy chr is nearby
			if (g_Vars.speedpillon == false || g_Vars.in_cutscene) {
				if (g_Vars.mplayerisrunning) {
					bool foundnearbychr = false;
					s32 playernum;

					// Check if another player is in a nearby room
					for (playernum = 0; playernum < PLAYERCOUNT() && !foundnearbychr; playernum++) {
						if (g_Vars.players[playernum]->isdead == false) {
							RoomNum *rooms = g_Vars.players[playernum]->prop->rooms;
							s32 r;

							for (r = 0; rooms[r] != -1 && !foundnearbychr; r++) {
								s32 otherplayernum;
								for (otherplayernum = 0; otherplayernum < PLAYERCOUNT(); otherplayernum++) {
									if (playernum != otherplayernum
											&& g_Vars.players[otherplayernum]->isdead == false
											&& bg_room_is_on_player_screen(rooms[r], otherplayernum)) {
										foundnearbychr = true;
									}
								}
							}
						}
					}

					if (foundnearbychr) {
						if (g_Vars.lvupdate240 > 4) {
							g_Vars.lvupdate240 = 4;
						}
					} else {
						if (g_Vars.lvupdate240 > 8) {
							g_Vars.lvupdate240 = 8;
						}
					}
				} else {
					if (g_Vars.lvupdate240 > 4) {
						g_Vars.lvupdate240 = 4;
					}
				}
			}
		} else {
			// Slow motion settings are off
			if (g_Vars.speedpillon && g_Vars.in_cutscene == false) {
				if (g_Vars.lvupdate240 > 4) {
					g_Vars.lvupdate240 = 4;
				}
			}
		}
	}

	g_Vars.lvupdate60 = g_Vars.lvupdate240 + g_Vars.lvupdate240rem;
	g_Vars.lvupdate240rem = g_Vars.lvupdate60 & 3;
	g_Vars.lvupdate60 >>= 2;

	if (g_Vars.lvupdate240 > 0) {
		g_Vars.lvframenum++;
	}

	g_Vars.lvupdate60f = g_Vars.lvupdate240 * 0.25f;
	g_Vars.lvframe60 += g_Vars.lvupdate60;
	g_Vars.lvframe240 += g_Vars.lvupdate240;
	g_Vars.lvupdate60frealprev = g_Vars.lvupdate60freal;
	g_Vars.lvupdate60freal = PALUPF(g_Vars.lvupdate60f);

	bgun_tick_boost();
	hudmsgs_tick();

	if ((joy_get_buttons_pressed_this_frame(0, 0xffff) != 0
				|| joy_get_stick_x(0) > 10
				|| joy_get_stick_x(0) < -10
				|| joy_get_stick_y(0) > 10
				|| joy_get_stick_y(0) < -10
				|| joy_get_buttons_pressed_this_frame(1, 0xffff) != 0
				|| joy_get_stick_x(1) > 10
				|| joy_get_stick_x(1) < -10
				|| joy_get_stick_y(1) > 10
				|| joy_get_stick_y(1) < -10
				|| joy_get_buttons_pressed_this_frame(2, 0xffff) != 0
				|| joy_get_stick_x(2) > 10
				|| joy_get_stick_x(2) < -10
				|| joy_get_stick_y(2) > 10
				|| joy_get_stick_y(2) < -10
				|| joy_get_buttons_pressed_this_frame(3, 0xffff) != 0
				|| joy_get_stick_x(3) > 10
				|| joy_get_stick_x(3) < -10
				|| joy_get_stick_y(3) > 10
				|| joy_get_stick_y(3) < -10) && g_IsTitleDemo) {
		if (g_Vars.stagenum != STAGE_TITLE) {
			title_set_next_mode(TITLEMODE_SKIP);
			main_change_to_stage(STAGE_TITLE);
		}

		g_IsTitleDemo = false;
	}

	if (g_Vars.stagenum < STAGE_TITLE && !g_IsTitleDemo && !g_Vars.in_cutscene) {
		if (joy_get_buttons(0, 0xffff) == 0
				&& joy_get_stick_x(0) < 10
				&& joy_get_stick_x(0) > -10
				&& joy_get_stick_y(0) < 10
				&& joy_get_stick_y(0) > -10
				&& joy_get_buttons(1, 0xffff) == 0
				&& joy_get_stick_x(1) < 10
				&& joy_get_stick_x(1) > -10
				&& joy_get_stick_y(1) < 10
				&& joy_get_stick_y(1) > -10
				&& joy_get_buttons(2, 0xffff) == 0
				&& joy_get_stick_x(2) < 10
				&& joy_get_stick_x(2) > -10
				&& joy_get_stick_y(2) < 10
				&& joy_get_stick_y(2) > -10
				&& joy_get_buttons(3, 0xffff) == 0
				&& joy_get_stick_x(3) < 10
				&& joy_get_stick_x(3) > -10
				&& joy_get_stick_y(3) < 10
				&& joy_get_stick_y(3) > -10) {
			g_TitleIdleTime60 += g_Vars.diffframe60;
		} else {
			g_TitleIdleTime60 = 0;
		}
	} else {
		g_TitleIdleTime60 = 0;
	}

	g_NumReasonsToEndMpMatch = 0;

	// Handle MP match ending
	if (g_Vars.normmplayerisrunning && g_Vars.stagenum < STAGE_TITLE) {
		if (g_MpTimeLimit60 > 0) {
			s32 elapsed = g_StageTimeElapsed60;
			s32 nexttime = g_Vars.lvupdate60 + g_StageTimeElapsed60;
			s32 warntime = TICKS(g_MpTimeLimit60) - TICKS(3600);

			// Show HUD message at one minute remaining
			if (elapsed < warntime && nexttime >= warntime) {
				s32 i;

				for (i = 0; i < PLAYERCOUNT(); i++) {
					set_current_player_num(i);
					hudmsg_create(lang_get(L_MISC_068), HUDMSGTYPE_DEFAULT); // "One minute left."
				}
			}

			if (elapsed < TICKS(g_MpTimeLimit60) && nexttime >= TICKS(g_MpTimeLimit60)) {
				// Match is ending due to time limit reached
				main_end_stage();
			}

			// Sound alarm at 10 seconds remaining
			if (nexttime >= TICKS(g_MpTimeLimit60) - TICKS(600)
					&& g_MiscAudioHandle == NULL
					&& !lv_is_paused()
					&& nexttime < TICKS(g_MpTimeLimit60)) {
				snd00010718(&g_MiscAudioHandle, 0, AL_VOL_FULL, AL_PAN_CENTER, SFX_ALARM_DEFAULT, 1, 1, -1, true);
			}
		}

		if (g_Vars.lvupdate240 != 0) {
			s32 numdying = 0;

			for (i = 0; i < PLAYERCOUNT(); i++) {
				if (g_Vars.players[i]->isdead) {
					if (g_Vars.players[i]->redbloodfinished == false
							|| g_Vars.players[i]->deathanimfinished == false
							|| g_Vars.players[i]->colourfadetimemax60 >= 0) {
						numdying++;
					}
				}
			}

			for (i = 0; i < g_MpNumChrs; i++) {
				if (g_MpAllChrPtrs[i]->actiontype == ACT_DIE) {
					numdying++;
				}
			}

			if (g_MpScoreLimit > 0) {
				struct ranking rankings[MAX_MPCHRS];
				s32 count = mp_get_player_rankings(rankings);

				for (i = 0; i < count; i++) {
					if (rankings[i].score >= g_MpScoreLimit) {
						g_NumReasonsToEndMpMatch++;
					}
				}
			}

			if (g_MpTeamScoreLimit > 0) {
				struct ranking rankings[MAX_MPCHRS];
				s32 count = mp_get_team_rankings(rankings);

				for (i = 0; i < count; i++) {
					if (rankings[i].score >= g_MpTeamScoreLimit) {
						g_NumReasonsToEndMpMatch++;
					}
				}
			}

			if (g_NumReasonsToEndMpMatch > 0 && numdying == 0) {
				main_end_stage();
			}
		}
	}

	g_StageTimeElapsed60 += g_Vars.lvupdate60;
	g_StageTimeElapsed1f = g_StageTimeElapsed60 / TICKS(60.0f);

	vi_set_use_z_buf(true);

	if (g_Vars.stagenum == STAGE_TEST_OLD) {
		title_tick_old();
		music_tick();
	}

	if (g_Vars.stagenum == STAGE_TITLE) {
		title_tick();
		lang_tick();
		music_tick();
	} else if (g_Vars.stagenum == STAGE_BOOTPAKMENU) {
		set_current_player_num(0);
#if VERSION >= VERSION_PAL_BETA
		player_configure_vi();
#endif
		menu_tick();
		music_tick();
		lang_tick();
		pak_execute_debug_operations();
	} else if (g_Vars.stagenum == STAGE_4MBMENU) {
		menu_tick();
		music_tick();
		lang_tick();
		pak_execute_debug_operations();
	} else if (g_Vars.stagenum == STAGE_CREDITS) {
		music_tick();
		lang_tick();
	} else {
		lv_update_cutscene_time();
		vtxstore_tick();
		lv_update_solo_handicaps();
		rooms_tick();
		sky_tick();
		casings_tick();
		shards_tick();
		sparks_tick();
		wallhits_tick();
		splats_tick();

		if (g_WeatherActive) {
			weather_tick();
		}

		if (g_NbombsActive) {
			nbombs_tick();
		}

		lv_update_misc_sfx();
		snd_tick();
		pak_execute_debug_operations();
		lighting_tick();
		modelmgr_print_counts();
		boltbeams_tick();
		am_tick();
		menu_tick();
		scenario_tick();

		if (!g_MainIsEndscreen) {
			props_tick();
		}

		music_tick();
		lang_tick();
		props_tick_pad_effects();

		if (main_get_stage_num() == STAGE_CITRAINING) {
			struct trainingdata *trainingdata = dt_get_data();

			if ((g_Vars.currentplayer->prop->rooms[0] < ROOM_DISH_HOLO1 || g_Vars.currentplayer->prop->rooms[0] > ROOM_DISH_HOLO4)
					&& g_Vars.currentplayer->prop->rooms[0] != ROOM_DISH_FIRINGRANGE
					&& (trainingdata == NULL || trainingdata->intraining == false)) {
				chr_unset_stage_flag(NULL, STAGEFLAG_CI_IN_TRAINING);
			}

			fr_tick();

			if (g_Vars.lvupdate240 != 0) {
				dt_tick();
				ht_tick();
			}
		}
	}
}

const char var7f1b7738[] = "cutsceneframe: %d\n";
const char var7f1b774c[] = "pos:%s%s %.2f %.2f %.2f\n";
const char var7f1b7768[] = "";
const char var7f1b776c[] = "";

void lv_tick_player(void)
{
	f32 xdiff;
	f32 zdiff;

	if (var80075d64 == 2) {
		if (var80075d68 == 2) {
			player_tick(true);
		} else {
			player_tick(false);
		}
	}

	xdiff = g_Vars.currentplayer->prop->pos.x - g_Vars.currentplayer->bondprevpos.x;
	zdiff = g_Vars.currentplayer->prop->pos.z - g_Vars.currentplayer->bondprevpos.z;

	g_Vars.currentplayerstats->distance += sqrtf(xdiff * xdiff + zdiff * zdiff);
}

void lv_stop(void)
{
	paks_stop(true);

	if (g_MiscAudioHandle && sndGetState(g_MiscAudioHandle)) {
		audioStop(g_MiscAudioHandle);
	}

	if (g_Vars.stagenum < STAGE_TITLE) {
		s32 bank = lang_get_lang_bank_index_from_stagenum(g_Vars.stagenum);
		lang_clear_bank(bank);
		stub0f015270();
	}

	chrmgr_stop();
	explosions_stop();
	smoke_stop();
	stub0f015400();
	stub0f015410();
	shards_stop();
	stub0f0153f0();
	props_stop();
	objs_stop();
	weather_stop();
	objectives_stop();
	stub0f015260();
	bgun_stop();
	ps_stop();
	music_stop();
	hudmsgs_stop();

	if (g_Vars.stagenum < STAGE_TITLE) {
		bg_stop();
	}

	func00033dd8();

	if (g_FileState == FILESTATE_CHANGINGAGENT) {
		menu_play_sound(MENUSOUND_EXPLOSION);
		g_FileState = FILESTATE_UNSELECTED;
	}

#if VERSION >= VERSION_NTSC_1_0
	menu_stop();
#endif
}

void lv_check_pause_state_changed(void)
{
	u32 paused = mp_is_paused();

	if (paused != var80084010) {
		if (paused) {
			pak_disable_rumble_for_all_players();
		} else {
			pak_enable_rumble_for_all_players();
		}
	}

	var80084010 = paused;
}

void lv_set_paused(bool paused)
{
	if (paused) {
		pak_disable_rumble_for_all_players();
		snd0000fe20();
	} else {
		snd0000fe50();
		pak_enable_rumble_for_all_players();
	}

	var80084014 = paused;
}

bool lv_is_paused(void)
{
	return var80084014;
}

s32 lv_get_difficulty(void)
{
	return g_Difficulty;
}

void lv_set_difficulty(s32 difficulty)
{
	if (difficulty < DIFF_A || difficulty > DIFF_PD) {
		difficulty = DIFF_A;
	}

	g_Difficulty = difficulty;
}

void lv_set_mp_time_limit60(u32 limit)
{
	g_MpTimeLimit60 = limit;
}

void lv_set_mp_score_limit(u32 limit)
{
	g_MpScoreLimit = limit;
}

void lv_set_mp_team_score_limit(u32 limit)
{
	g_MpTeamScoreLimit = limit;
}

f32 lv_get_stage_time_in_seconds(void)
{
	return g_StageTimeElapsed1f;
}

s32 lv_get_stage_time60(void)
{
	return g_StageTimeElapsed60;
}

u32 func0f16ce04(u32 arg0)
{
	return arg0;
}
