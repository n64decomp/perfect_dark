#include <ultra64.h>
#include "constants.h"
#include "../lib/naudio/n_sndp.h"
#include "game/bondmove.h"
#include "game/cheats.h"
#include "game/chraction.h"
#include "game/inv.h"
#include "game/game_006900.h"
#include "game/chr.h"
#include "game/prop.h"
#include "game/propsnd.h"
#include "game/projectile.h"
#include "game/acosfasinf.h"
#include "game/game_096b20.h"
#include "game/quaternion.h"
#include "game/game_097aa0.h"
#include "game/bondgun.h"
#include "game/gunfx.h"
#include "game/gset.h"
#include "game/modeldef.h"
#include "game/modelmgr.h"
#include "game/tex.h"
#include "game/camera.h"
#include "game/player.h"
#include "game/mtxf2lbulk.h"
#include "game/gfxmemory.h"
#include "game/sight.h"
#include "game/inv.h"
#include "game/playermgr.h"
#include "game/smoke.h"
#include "game/text.h"
#include "game/file.h"
#include "game/lv.h"
#include "game/texdecompress.h"
#include "game/zbuf.h"
#include "game/training.h"
#include "game/lang.h"
#include "game/mplayer/mplayer.h"
#include "game/pak.h"
#include "game/options.h"
#include "game/propobj.h"
#include "game/objectives.h"
#include "bss.h"
#include "lib/collision.h"
#include "lib/vi.h"
#include "lib/joy.h"
#include "lib/main.h"
#include "lib/model.h"
#include "lib/snd.h"
#include "lib/rng.h"
#include "lib/mtx.h"
#include "lib/anim.h"
#include "lib/lib_317f0.h"
#include "data.h"
#include "types.h"

#define GUNLOADSTATE_FLUX     0
#define GUNLOADSTATE_MODEL    1
#define GUNLOADSTATE_TEXTURES 2
#define GUNLOADSTATE_DLS      3
#define GUNLOADSTATE_LOADED   4

#define MASTERLOADSTATE_FLUX   0
#define MASTERLOADSTATE_HANDS  1
#define MASTERLOADSTATE_GUN    2
#define MASTERLOADSTATE_CARTS  3
#define MASTERLOADSTATE_LOADED 4

// Max downwards pitch when changing guns or reloading a classic gun
#define MAX_PITCH BADDTOR(50)

#if VERSION >= VERSION_PAL_BETA
struct sndstate *g_CasingAudioHandles[2];
s32 var8009d0d8;
u32 fill2;
struct sndstate *g_BgunAudioHandles[MAX_PLAYERS];
s32 var8009d0dc;
u32 fill2_2;
s32 var8009d0f0[3];
u32 var8009d0fc;
u32 var8009d100;
u32 var8009d104;
u32 var8009d108;
u32 var8009d10c;
u32 var8009d110;
u32 var8009d114;
u32 var8009d118;
u32 var8009d11c;
u32 var8009d120;
u32 var8009d124;
u32 var8009d128;
u32 var8009d12c;
u32 var8009d130;
u32 var8009d134;
u32 var8009d138;
u32 var8009d13c;
f32 var8009d140;
struct hand *var8009d144;
s32 var8009d148;
u32 var8009d14c;
struct fireslot g_Fireslots[20];
#elif VERSION >= VERSION_NTSC_1_0
struct sndstate *g_CasingAudioHandles[2];
s32 var8009d0d8;
s32 var8009d0dc;
struct sndstate *g_BgunAudioHandles[MAX_PLAYERS];
s32 var8009d0f0[3];
u32 var8009d0fc;
u32 var8009d100;
u32 var8009d104;
u32 var8009d108;
u32 var8009d10c;
u32 var8009d110;
u32 var8009d114;
u32 var8009d118;
u32 var8009d11c;
u32 var8009d120;
u32 var8009d124;
u32 var8009d128;
u32 var8009d12c;
u32 var8009d130;
u32 var8009d134;
u32 var8009d138;
u32 var8009d13c;
f32 var8009d140;
struct hand *var8009d144;
s32 var8009d148;
u32 var8009d14c;
struct fireslot g_Fireslots[20];
#else
s32 var8009d0dc;
u32 var800a1800nb;
s32 var8009d0f0[3];
u32 var8009d0fc;
u32 var8009d100;
u32 var8009d104;
u32 var8009d108;
u32 var8009d10c;
u32 var8009d110;
u32 var8009d114;
u32 var8009d118;
u32 var8009d11c;
u32 var8009d120;
u32 var8009d124;
u32 var8009d128;
u32 var8009d12c;
u32 var8009d130;
u32 var8009d134;
u32 var8009d138;
u32 var8009d13c;
f32 var8009d140;
struct hand *var8009d144;
s32 var8009d148;
u32 var8009d14c;
struct sndstate *g_CasingAudioHandles[2];
s32 var8009d0d8;
struct sndstate *g_BgunAudioHandles[MAX_PLAYERS];
struct fireslot g_Fireslots[20];
u32 fill2[1];
#endif

Lights1 var80070090 = gdSPDefLights1(0x96, 0x96, 0x96, 0xff, 0xff, 0xff, 0xb2, 0x4d, 0x2e);

u32 g_BgunGunMemBaseSizeDefault = 150 * 1024;
u32 g_BgunGunMemBaseSize4Mb2P = 120 * 1024;

u16 g_CartFileNums[] = {
	FILE_GCARTRIDGE,
	FILE_GCARTRIFLE,
	FILE_GCARTBLUE,
	FILE_GCARTSHELL,
};

u32 var800700b8 = 0x00000000;

char var800700bc[][10] = {
	{ 'i','d','l','e'                     }, // "idle"
	{ 'p','r','e','p','a','r','e'         }, // "prepare"
	{ 'c','a','n','t','u','s','e'         }, // "cantuse"
	{ 'n','o','a','m','m','o'             }, // "noammo"
	{ 'u','s','e','2'                     }, // "use2"
	{ 'c','h','a','n','g','e'             }, // "change"
	{ 'u','p','g','r','a','d','e'         }, // "upgrade"
	{ 'c','h','a','n','g','e','f','n'     }, // "changefn"
	{ 'i','d','l','e','s','t','u','c','k' }, // "idlestuck"
	{ 'x','x','x'                         }, // "xxx"
};

void bgun_free_held_rocket(s32 handnum);
void bgun_free_weapon(s32 handnum);
void bgun_tick_switch2(void);
void bgun_switch_to_previous(void);
void bgun_auto_switch_weapon(void);
void bgun_start_slide(s32 handnum);
void bgun_set_aim_pos(struct coord *coord);
void bgun0f0abd30(s32 handnum);
bool bgun_is_using_secondary_function(void);
bool bgun_is_ready_to_switch(s32 handnum);
bool bgun_set_state(s32 handnum, s32 state);
bool bgun_is_loaded(void);
s32 bgun_create_model_cmd_list(struct model *model, struct modelnode *nodearg, s32 *ptr);
bool bgun_ammotype_allows_unlimited_ammo(u32 ammotype);

void bgun_rumble(s32 handnum, s32 weaponnum)
{
	u32 stack[3];
	bool singlewield = false;
#if VERSION >= VERSION_NTSC_1_0
	s32 contpad1;
	s32 contpad2;
#endif
	s32 contpad1hasrumble;
	s32 contpad2hasrumble;
	s32 contpadtouse;

#if VERSION >= VERSION_NTSC_1_0
	joy_get_contpad_nums_for_player(g_Vars.currentplayernum, &contpad1, &contpad2);

	if (options_get_control_mode(g_Vars.currentplayerstats->mpindex) >= CONTROLMODE_21 && contpad1 >= 0 && contpad2 >= 0) {
		contpad1hasrumble = pak_get_type(contpad1) == PAKTYPE_RUMBLE;
		contpad2hasrumble = pak_get_type(contpad2) == PAKTYPE_RUMBLE;

		if (!gset_has_weapon_flag(weaponnum, WEAPONFLAG_DUALWIELD)) {
			singlewield = true;
		}

		if (contpad1hasrumble && contpad2hasrumble) {
			if (singlewield) {
				pak_rumble(contpad1, 0.2f, 2, 4);
				pak_rumble(contpad2, 0.2f, 2, 4);
			} else {
				contpadtouse = contpad1;

				if (handnum == HAND_LEFT) {
					contpadtouse = contpad2;
				}

				pak_rumble(contpadtouse, 0.2f, 2, 4);
			}
		} else {
			contpadtouse = contpad1;

			if (contpad2hasrumble) {
				contpadtouse = contpad2;
			}

			pak_rumble(contpadtouse, 0.2f, 2, 4);
		}
	} else {
		if (contpad1 >= 0) {
			pak_rumble(contpad1, 0.2f, 2, 4);
		}
	}
#else
	// NTSC beta uses a different controller mapping.
	// It also never sets singlewield to true, causing that block to optimise out.
	if (options_get_control_mode(g_Vars.currentplayerstats->mpindex) >= CONTROLMODE_21) {
		contpad1hasrumble = pak_get_type(g_Vars.currentplayernum) == PAKTYPE_RUMBLE;
		contpad2hasrumble = pak_get_type(g_Vars.currentplayernum + PLAYERCOUNT()) == PAKTYPE_RUMBLE;

		if (contpad1hasrumble && contpad2hasrumble) {
			if (singlewield) {
				pak_rumble(g_Vars.currentplayernum, 0.2f, 2, 4);
				pak_rumble(g_Vars.currentplayernum + PLAYERCOUNT(), 0.2f, 2, 4);
			} else {
				contpadtouse = g_Vars.currentplayernum;

				if (handnum == HAND_LEFT) {
					contpadtouse += PLAYERCOUNT();
				}

				pak_rumble(contpadtouse, 0.2f, 2, 4);
			}
		} else {
			contpadtouse = g_Vars.currentplayernum;

			if (contpad2hasrumble) {
				contpadtouse += PLAYERCOUNT();
			}

			pak_rumble(contpadtouse, 0.2f, 2, 4);
		}
	} else {
		pak_rumble(g_Vars.currentplayernum, 0.2f, 2, 4);
	}
#endif
}

s32 bgun_get_unequipped_reload_index(s32 weaponnum)
{
	if (weaponnum == WEAPON_CROSSBOW) {
		return 0;
	}

	if (weaponnum == WEAPON_SHOTGUN) {
		return 1;
	}

	if (weaponnum == WEAPON_DY357MAGNUM) {
		return 2;
	}

	if (weaponnum == WEAPON_DY357LX) {
		return 3;
	}

	return -1;
}

/**
 * The magnums, shotgun and crossbow are special because that the game remembers
 * how much ammo is loaded in their clips when the weapon is not being used.
 * Their clips are gradually reloaded while the weapon is not in use, and that
 * gradual reloading is handled by this function.
 *
 * The gunroundsspent value is actually a countdown timer,
 * not the number of rounds as the name suggests.
 */
void bgun_tick_unequipped_reload(void)
{
	s32 i;
	s32 j;

	for (i = 0; i < 2; i++) {
		for (j = 0; j < ARRAYCOUNT(g_Vars.currentplayer->hands[i].gunroundsspent); j++) {
			u16 spent = g_Vars.currentplayer->hands[i].gunroundsspent[j];

			if (spent > g_Vars.lvupdate60) {
				spent -= g_Vars.lvupdate60;
			} else {
				spent = 0;
			}

			g_Vars.currentplayer->hands[i].gunroundsspent[j] = spent;
		}
	}
}

bool bgun_test_gun_vis_command(struct gunviscmd *cmd, struct hand *hand)
{
	bool result = true;

	switch (cmd->type) {
	case GUNVISCMD_CHECKUPGRADE:
		if (((hand->gset.upgradewant >> cmd->param) & 1) == 0) {
			result = false;
		}
		break;
	case GUNVISCMD_CHECKINLEFTHAND:
		if (hand != &g_Vars.currentplayer->hands[HAND_LEFT]) {
			result = false;
		}
		break;
	case GUNVISCMD_CHECKINRIGHTHAND:
		if (hand != &g_Vars.currentplayer->hands[HAND_RIGHT]) {
			result = false;
		}
		break;
	}

	return result;
}

void bgun_set_part_visible(s16 partnum, bool visible, struct hand *hand, struct modeldef *modeldef)
{
	struct modelnode *node;

	if (partnum == MODELPART_HAND_LEFT || partnum == MODELPART_HAND_RIGHT) {
		if (g_Vars.currentplayer->gunctrl.handmodeldef) {
			node = model_get_part(g_Vars.currentplayer->gunctrl.handmodeldef, partnum);

			if (node) {
				struct modelrodata_toggle *rodata = &node->rodata->toggle;
				u32 *ptr = &hand->handsavedata[rodata->rwdataindex];
				*ptr = visible;
			}
		}
	} else {
		node = model_get_part(modeldef, partnum);

		if (node) {
			struct modelrodata_toggle *rodata = &node->rodata->toggle;
			u32 *ptr = &hand->unk0a6c[rodata->rwdataindex];
			*ptr = visible;
		}
	}
}

void bgun_execute_gun_vis_commands(struct hand *hand, struct modeldef *modeldef, struct gunviscmd *commands)
{
	struct gunviscmd *cmd = commands;
	bool done = false;

	if (cmd == NULL) {
		return;
	}

	while (!done) {
		if (bgun_test_gun_vis_command(cmd, hand)) {
			if (cmd->op == GUNVISOP_IFTRUE_SETVISIBLE) {
				bgun_set_part_visible(cmd->partnum, true, hand, modeldef);
			}

			if (cmd->op == GUNVISOP_IFTRUE_SETHIDDEN) {
				bgun_set_part_visible(cmd->partnum, false, hand, modeldef);
			}

			if (cmd->op == GUNVISOP_SETVISIBILITY) {
				bgun_set_part_visible(cmd->partnum, true, hand, modeldef);
			}
		} else {
			if (cmd->op == GUNVISOP_SETVISIBILITY) {
				bgun_set_part_visible(cmd->partnum, false, hand, modeldef);
			}
		}

		cmd++;

		if (cmd->type == GUNVISCMD_END) {
			done = true;
		}
	}
}

void bgun_update_ammo_visibility(struct hand *hand, struct modeldef *modeldef)
{
	struct weapondef *weapon = gset_get_weapondef(hand->gset.weaponnum);
	s32 i;
	s32 j;

	bgun_execute_gun_vis_commands(hand, modeldef, weapon->gunviscmds);
	bgun_set_part_visible(MODELPART_0042, false, hand, modeldef);

	for (i = 0; i < 2; i++) {
		if (weapon->ammos[i] && (weapon->ammos[i]->flags & AMMOFLAG_QTYAFFECTSPARTVIS)) {
			for (j = 0; j < hand->clipsizes[i]; j++) {
				if (j >= hand->loadedammo[i]) {
					bgun_set_part_visible(j + 100, false, hand, modeldef);
				} else {
					bgun_set_part_visible(j + 100, true, hand, modeldef);
				}
			}
		}
	}
}

f32 bgun_get_current_keyframe(struct hand *hand)
{
	if (hand->animmode == HANDANIMMODE_BUSY && hand->animcmd != NULL) {
		if (hand->animcmd->animparams < 0) { // if reverse animation
			return model_get_num_anim_frames(&hand->gunmodel) - model_get_cur_anim_frame(&hand->gunmodel);
		}

		return model_get_cur_anim_frame(&hand->gunmodel);
	}

	return 0;
}

void bgun_tick_anim(struct hand *hand, struct modeldef *modeldef)
{
#if VERSION >= VERSION_PAL_BETA
	f32 oldkeyframe;
	f32 newkeyframe;
#else
	s32 newkeyframe;
	s32 oldkeyframe;
#endif
	struct guncmd *cmd;
	f32 animspeed;
	bool done;
	f32 animspeedmult;
	s32 partnums[15];
	bool partsvisible[15];
	s32 partframes[15];
	s32 numparts;
	s32 index;

	hand->ejectcount = 0;

	if (hand->animmode == HANDANIMMODE_BUSY && bgun_get_current_keyframe(hand) >= model_get_num_anim_frames(&hand->gunmodel) - 1) {
		hand->animmode = HANDANIMMODE_IDLE;
	}

	// This condition looks like a bug (using | instead of ||), but it happens
	// to make no difference anyway. Brackets added for clarity.
	if ((hand->animmode == (u32)HANDANIMMODE_BUSY) | (hand->animload >= 0)) {
		if (hand->gangstarot > 0.0f) {
			hand->animframeinc = 0;
#if VERSION >= VERSION_PAL_BETA
			hand->animframeincfreal = 0.0f;
#endif
		}

		if (hand->animload >= 0) {
			animspeedmult = 1.0f;
			animspeed = hand->animcmd->animparams / 10000.0f;

			if (hand->unk0d0e_07 && g_Vars.currentplayer->hands[HAND_LEFT].inuse) {
				animspeedmult = RANDOMFRAC() * 0.77f + 0.7f;
			}

			if (hand->animcmd && animspeed < 0.0f) {
				model_set_animation(&hand->gunmodel, hand->animload, false, 0.0f, animspeedmult * animspeed, 0.0f);
				model_set_anim_frame(&hand->gunmodel, model_get_num_anim_frames(&hand->gunmodel));
			} else {
				model_set_animation(&hand->gunmodel, hand->animload, false, 0.0f, animspeedmult * animspeed, 0.0f);
			}

			hand->animload = -1;
			hand->animmode = HANDANIMMODE_BUSY;
#if VERSION >= VERSION_PAL_BETA
			hand->animframeincfreal = model_get_abs_anim_speed(&hand->gunmodel) * PALUPF(hand->animframeinc);
#endif
		}

		if (hand->unk0cc8_02) {
			hand->animframeinc = 0;
#if VERSION >= VERSION_PAL_BETA
			hand->animframeincfreal = 0.0f;
#endif
		}

		oldkeyframe = bgun_get_current_keyframe(hand);

#if VERSION >= VERSION_PAL_BETA
		newkeyframe = oldkeyframe + hand->animframeincfreal;
#else
		newkeyframe = oldkeyframe + hand->animframeinc;
#endif

		if (oldkeyframe == 0 && newkeyframe > 0) {
			oldkeyframe--;
		}

		// This loop processes guncmds *prior* to incrementing the model's animation.
		// Commands in this loop are able to adjust the keyframe in order to loop or pause a frame.
		if (hand->animcmd) {
			done = false;
			cmd = hand->animcmd;

			if (cmd) {
				numparts = 0;

				do {
					if (cmd->type == GUNCMD_END) {
						done = true;
					} else if (cmd->type == GUNCMD_SHOWPART || cmd->type == GUNCMD_HIDEPART) {
						if (newkeyframe >= cmd->keyframe) {
							s32 i;

							// Find in partnums list or append
							index = -1;

							for (i = 0; i < numparts; i++) {
								if (cmd->partnum == partnums[i]) {
									index = i;
								}
							}

							if (index == -1) {
								index = numparts;
								numparts++;

								if (1);

								partnums[index] = cmd->partnum;
								partframes[index] = -1;
							}

							if (cmd->keyframe > partframes[index]) {
								partframes[index] = cmd->keyframe;
								partsvisible[index] = cmd->type == GUNCMD_SHOWPART ? true : false;
							}
						}
					} else {
						switch (cmd->type) {
						case GUNCMD_WAITFORZRELEASED:
							if (hand->unk0cc8_01) {
								if (newkeyframe >= cmd->keyframe && oldkeyframe < cmd->keyframe && oldkeyframe < newkeyframe) {
#if VERSION >= VERSION_PAL_BETA
									f32 tmp = cmd->keyframe - bgun_get_current_keyframe(hand);
									tmp /= 2;

									if (hand->animframeincfreal > tmp) {
#if PAL
										hand->animframeinc = tmp * 0.83333333f / model_get_abs_anim_speed(&hand->gunmodel);
#else
										hand->animframeinc = tmp / model_get_abs_anim_speed(&hand->gunmodel);
#endif
										hand->animframeincfreal = model_get_abs_anim_speed(&hand->gunmodel) * PALUPF(hand->animframeinc);
									}

									newkeyframe = oldkeyframe + hand->animframeincfreal;
#else
									s32 tmp = cmd->keyframe - (s32) bgun_get_current_keyframe(hand);
									tmp /= 2;

									if (hand->animframeinc > tmp) {
										hand->animframeinc = tmp;
									}

									newkeyframe = oldkeyframe + hand->animframeinc;
#endif
								}
							}
							break;
						case GUNCMD_REPEATUNTILFULL:
							if (hand->incrementalreloading && newkeyframe >= cmd->keyframe && oldkeyframe < cmd->keyframe && oldkeyframe < newkeyframe) {
#if VERSION >= VERSION_PAL_BETA
								f32 foundkeyframe = newkeyframe;

								while (foundkeyframe >= cmd->keyframe) {
									foundkeyframe += cmd->gotokeyframe - cmd->keyframe;
								}

								oldkeyframe = foundkeyframe;
								hand->animframeinc = 0;
								hand->animframeincfreal = 0;
#else
								s32 foundkeyframe = cmd->gotokeyframe + ((newkeyframe - cmd->keyframe) % ((cmd->keyframe - cmd->gotokeyframe) + 1));
								oldkeyframe = foundkeyframe;
								hand->animframeinc = 0;
#endif

								model_set_anim_frame(&hand->gunmodel, foundkeyframe);
								hand->animloopcount++;
								newkeyframe = foundkeyframe;
							}
							break;
						}
					}

					cmd++;
				} while (!done);

				if (numparts > 0) {
					s32 i;

					for (i = 0; i < numparts; i++) {
						bgun_set_part_visible(partnums[i], partsvisible[i], hand, modeldef);
					}
				}
			}
		}

		// Apply the keyframe to the model
#if VERSION >= VERSION_PAL_BETA
		model_set_anim_play_speed(&hand->gunmodel, PALUPF(4.0f), 0);
		model_tick_anim_quarter_speed(&hand->gunmodel, hand->animframeinc, true);
#else
		model_tick_anim(&hand->gunmodel, hand->animframeinc, true);
#endif

		// Run post-anim gun commands
		newkeyframe = bgun_get_current_keyframe(hand);

		if (hand->animcmd) {
			bool done = false;
			struct guncmd *cmd = hand->animcmd;
			f32 speed = 1.0f;
			bool hasspeed = false;
#if VERSION < VERSION_NTSC_1_0
			struct sndstate *audiohandle;
#endif

			if (cmd) {
				do {
					if (cmd->type == GUNCMD_END) {
						done = true;
					} else {
						if (newkeyframe >= cmd->keyframe && oldkeyframe < cmd->keyframe && oldkeyframe < newkeyframe) {
							switch (cmd->type) {
							case GUNCMD_PLAYSOUND:
#if VERSION >= VERSION_NTSC_1_0
								if (hasspeed) {
									snd00010718(0, 0, AL_VOL_FULL, AL_PAN_CENTER, cmd->soundnum, speed, 1, -1, 1);
									hasspeed = false;
								} else {
									snd00010718(0, 0, AL_VOL_FULL, AL_PAN_CENTER, cmd->soundnum, 1.0f, 1, -1, 1);
								}
#else
								audiohandle = snd_start(var80095200, cmd->soundnum, NULL, -1, -1, -1, -1, -1);

								if (hasspeed && audiohandle) {
									hasspeed = false;
									audioPostEvent(audiohandle, AL_SNDP_PITCH_EVT, *(s32 *)&speed);
								}
#endif
								break;
							case GUNCMD_SETSOUNDSPEED:
								speed = cmd->soundspeed / 1000.0f;
								hasspeed = true;
								break;
							case GUNCMD_POPOUTSACKOFPILLS:
								hand->ejectcount++;
								break;
							}
						}
					}

					cmd++;
				} while (!done);
			}
		}
	}
}

bool bgun_test_condition(struct guncmd *cmd, struct gset *gset)
{
	s32 result = false;

	if (cmd->condition == 0) {
		return true;
	}

	if (cmd->condition == 1 && g_Vars.currentplayer->hands[HAND_LEFT].inuse == true) {
		result = true;
	}

	if (cmd->condition == 2 && gset->weaponfunc == FUNC_SECONDARY) {
		result = true;
	}

	return result;
}

void bgun_start_animation(struct guncmd *cmd, s32 handnum, struct hand *hand)
{
	if (cmd->type != GUNCMD_PLAYANIMATION) {
		struct guncmd *loopcmd = cmd;
		s32 done = false;
		u32 rand = random() % 100;

		while (loopcmd->type != GUNCMD_END) {
			if (bgun_test_condition(loopcmd, &hand->gset) && !done) {
				if (loopcmd->type == GUNCMD_INCLUDE) {
					done = true;
					bgun_start_animation(loopcmd->targetcmd, handnum, hand);
				} else if (loopcmd->type == GUNCMD_RANDOM) {
					if (loopcmd->targetcmd != hand->animcmd2 && rand < loopcmd->probability) {
						done = true;
						bgun_start_animation(loopcmd->targetcmd, handnum, hand);
					}
				}
			}

			loopcmd++;
		}
	} else {
		hand->animload = cmd->animnum;
		hand->animmode = HANDANIMMODE_IDLE;
		hand->unk0cc8_01 = 0;
		hand->incrementalreloading = false;
		hand->animcmd = cmd;
		hand->animloopcount = 0;
		hand->unk0cc8_02 = false;
		hand->unk0d0e_07 = false;
		hand->animcmd2 = cmd;
	}
}

bool bgun_anim_allows_feature(struct hand *hand, s32 feature)
{
	struct guncmd *cmd = hand->animcmd;
	s32 allowkeyframe = -1;
	s32 zreleasekeyframe = -1;

	if (hand->animmode == HANDANIMMODE_IDLE) {
		return (hand->animload == -1);
	}

	while (cmd->type != GUNCMD_END && allowkeyframe == -1) {
		if (cmd->type == GUNCMD_WAITFORZRELEASED) {
			zreleasekeyframe = cmd->keyframe;
		}

		if (cmd->type == GUNCMD_ALLOWFEATURE && cmd->feature == feature) {
			allowkeyframe = cmd->keyframe;
		}

		cmd++;
	}

	if (allowkeyframe >= 0) {
#if VERSION >= VERSION_PAL_BETA
		if (hand->unk0cc8_01 && bgun_get_current_keyframe(hand) <= zreleasekeyframe) {
			return false;
		}

		return (bgun_get_current_keyframe(hand) + hand->animframeincfreal >= allowkeyframe);
#else
		if (hand->unk0cc8_01 && (s32)bgun_get_current_keyframe(hand) <= zreleasekeyframe) {
			return false;
		}

		return (bgun_get_current_keyframe(hand) + hand->animframeinc >= allowkeyframe);
#endif
	}

	return true;
}

s32 bgun_find_allowfeature(struct hand *hand, s32 feature)
{
	struct guncmd *cmd = hand->animcmd;
	s32 keyframe = -1;

	if (hand->animmode == HANDANIMMODE_IDLE) {
		return 0;
	}

	while (cmd->type != GUNCMD_END && keyframe == -1) {
		if (cmd->type == GUNCMD_ALLOWFEATURE && cmd->feature == feature) {
			keyframe = cmd->keyframe;
		}

		cmd++;
	}

	if (keyframe == -1) {
		keyframe = 0;
	}

	return keyframe;
}

bool bgun_is_anim_busy(struct hand *hand)
{
	return hand->animmode != HANDANIMMODE_IDLE;
}

void bgun_reset_anim(struct hand *hand)
{
	hand->animload = -1;
	hand->animmode = HANDANIMMODE_IDLE;
	hand->unk0cc8_01 = false;
	hand->incrementalreloading = false;
	hand->animcmd = NULL;
	hand->animloopcount = 0;
	hand->unk0cc8_02 = false;
	hand->unk0d0e_07 = false;
}

void bgun_get_weapon_info(struct handweaponinfo *info, s32 handnum)
{
	s32 weaponnum = bgun_get_weapon_num2(handnum);

	info->weaponnum = weaponnum;
	info->definition = g_Weapons[weaponnum];
	info->gunctrl = &g_Vars.currentplayer->gunctrl;
}

/**
 * Return values:
 * -1 = gun function doesn't exist or ammo fully depleted
 * 0 = trigger reload
 * 1 = has ammo in clip and ammo in reserve
 * 2 = has ammo in clip but none in reserve
 * 3 = gun doesn't use ammo or clip is full
 */
s32 bgun_get_ammo_state(s32 funcnum, struct handweaponinfo *info, struct hand *hand)
{
	s32 state = GUNAMMOSTATE_CLIPFULL;
	struct funcdef *func = gset_get_funcdef_by_gset_funcnum(&hand->gset, funcnum);

	if (!func) {
		return GUNAMMOSTATE_DEPLETED;
	}

	if (func->ammoindex != -1) {
		s32 ammoindex = func->ammoindex;

		if (info->gunctrl->ammotypes[ammoindex] >= 0 && hand->loadedammo[ammoindex] < hand->clipsizes[ammoindex]) {
			s32 minqty = 1;

			if (info->weaponnum == WEAPON_SHOTGUN && funcnum == FUNC_SECONDARY) {
				minqty = 2;
			}

			if (info->weaponnum == WEAPON_TRANQUILIZER && funcnum == FUNC_SECONDARY) {
				minqty = bgun_get_min_clip_qty(WEAPON_TRANQUILIZER, FUNC_SECONDARY);
			}

			state = GUNAMMOSTATE_CLIPYES_HELDYES;

			if (hand->loadedammo[ammoindex] < minqty) {
				state = GUNAMMOSTATE_NEEDRELOAD;

				if (g_Vars.currentplayer->ammoheldarr[info->gunctrl->ammotypes[ammoindex]] == 0) {
					state = GUNAMMOSTATE_DEPLETED;
				}
			} else {
				if (g_Vars.currentplayer->ammoheldarr[info->gunctrl->ammotypes[ammoindex]] == 0) {
					state = GUNAMMOSTATE_CLIPYES_HELDNO;
				}
			}
		}
	}

	return state;
}

void bgun0f098df8(s32 weaponfunc, struct handweaponinfo *info, struct hand *hand, u8 onebullet, u8 checkunequipped)
{
	struct funcdef *func = gset_get_funcdef_by_gset_funcnum(&hand->gset, weaponfunc);

	if (func && func->ammoindex != -1) {
		s32 ammoindex = func->ammoindex;

		if (info->gunctrl->ammotypes[ammoindex] >= 0) {
			s32 amount = hand->clipsizes[ammoindex] - hand->loadedammo[ammoindex];

			s32 reloadindex = bgun_get_unequipped_reload_index(info->weaponnum);

			if (g_FrIsValidWeapon) {
				reloadindex = -1;
			}

			if (checkunequipped && reloadindex >= 0) {
#if VERSION >= VERSION_PAL_BETA
				amount -= hand->gunroundsspent[reloadindex] / TICKS(256);
#else
				amount -= hand->gunroundsspent[reloadindex] >> 8;
#endif
			}

			if (onebullet) {
				amount = 1;
			}

			if (amount > g_Vars.currentplayer->ammoheldarr[info->gunctrl->ammotypes[ammoindex]]) {
				amount = g_Vars.currentplayer->ammoheldarr[info->gunctrl->ammotypes[ammoindex]];
			}

#if VERSION >= VERSION_JPN_FINAL
			// In most versions of the game, reloading the shotgun while going
			// through a teleport in Deep Sea will cause the shotgun to load
			// more ammo than its capacity. JPN Final fixes this here.
			if (amount > hand->clipsizes[ammoindex] - hand->loadedammo[ammoindex]) {
				amount = hand->clipsizes[ammoindex] - hand->loadedammo[ammoindex];
			}
#endif

			hand->loadedammo[ammoindex] += amount;
			g_Vars.currentplayer->ammoheldarr[info->gunctrl->ammotypes[ammoindex]] -= amount;

			if (info->definition->ammos[ammoindex]->flags & AMMOFLAG_NORESERVE) {
				g_Vars.currentplayer->ammoheldarr[info->gunctrl->ammotypes[ammoindex]] = 0;
			}

			if (func);
		}
	}
}

void bgun0f098f8c(struct handweaponinfo *info, struct hand *hand)
{
	s32 i;

	for (i = 0; i < 2; i++) {
		if (gset_get_funcdef_by_gset_funcnum(&hand->gset, i)) {
			bgun0f098df8(i, info, hand, 0, 1);
		}
	}
}

bool bgun_clip_has_ammo(s32 handnum)
{
	struct handweaponinfo info;

	bgun_get_weapon_info(&info, handnum);

	if (bgun_get_ammo_state(FUNC_PRIMARY, &info, &g_Vars.currentplayer->hands[handnum]) > GUNAMMOSTATE_NEEDRELOAD) {
		return true;
	}

	if (bgun_get_ammo_state(FUNC_SECONDARY, &info, &g_Vars.currentplayer->hands[handnum]) > GUNAMMOSTATE_NEEDRELOAD) {
		return true;
	}

	return false;
}

bool bgun0f0990b0(struct funcdef *basefunc, struct weapondef *weapon)
{
	if (!basefunc) {
		return true;
	}

	if (basefunc->type == INVENTORYFUNCTYPE_NONE) {
		return true;
	}

	if ((basefunc->type & 0xff) == INVENTORYFUNCTYPE_MELEE) {
		return true;
	}

	if ((basefunc->type & 0xff) == INVENTORYFUNCTYPE_SPECIAL) {
		struct funcdef_special *func = (struct funcdef_special *)basefunc;

		if (func->specialfunc != HANDATTACKTYPE_DETONATE
				&& func->specialfunc != HANDATTACKTYPE_BOOST
				&& func->specialfunc != HANDATTACKTYPE_REVERTBOOST) {
			return true;
		}
	}

	if ((basefunc->type & 0xff) == INVENTORYFUNCTYPE_THROW) {
		if (basefunc->ammoindex <= -1) {
			return true;
		}
	}

	if (basefunc->ammoindex >= 0
			&& weapon->ammos[basefunc->ammoindex]
			&& bgun_get_ammo_count(weapon->ammos[basefunc->ammoindex]->type) <= 0) {
		return true;
	}

	return false;
}

bool bgun0f099188(struct hand *hand, s32 gunfunc)
{
	struct funcdef *func = gset_get_funcdef_by_gset_funcnum(&hand->gset, gunfunc);
	struct weapondef *weapon = gset_get_weapondef(hand->gset.weaponnum);

	if (bgun_is_using_secondary_function() == gunfunc) {
		return false;
	}

	return bgun0f0990b0(func, weapon);
}

s32 bgun_tick_inc_idle(struct handweaponinfo *info, s32 handnum, struct hand *hand, s32 lvupdate)
{
	bool usesec;
	s32 gunfunc = bgun_is_using_secondary_function();
	s32 ammostate;
	s32 ammostate2;
	bool changefunc;
	s32 next;
	struct hand *lhand;
	struct funcdef *func;

	hand->lastdirvalid = false;
	hand->burstbullets = 0;
#if VERSION < VERSION_PAL_BETA
	hand->animframeincfreal = hand->animframeinc;
#endif
	hand->shotremainder = 0;

	// If ready to change gun due to manual switch, just do that
	if (bgun_is_ready_to_switch(handnum) && bgun_set_state(handnum, HANDSTATE_CHANGEGUN)) {
		return lvupdate;
	}

	if (gunfunc == hand->gset.weaponfunc) {
		hand->unk0cc8_07 = false;
	}

	hand->unk0cc8_08 = false;

	if (hand->inuse) {
		ammostate = bgun_get_ammo_state(hand->gset.weaponfunc, info, hand);

		// Handle changing gun function
		if (gunfunc != hand->gset.weaponfunc && hand->modenext != HANDMODE_RELOAD) {
			changefunc = true;

			if (hand->unk0cc8_07 && bgun_get_ammo_state(1 - hand->gset.weaponfunc, info, hand) < 0) {
				changefunc = false;
			}

			if (changefunc && info->weaponnum == WEAPON_COMBATKNIFE) {
				if (ammostate == GUNAMMOSTATE_NEEDRELOAD) {
					hand->count60 = 0;
					hand->count = 0;
					hand->gset.weaponfunc = gunfunc;

					if (bgun_set_state(handnum, HANDSTATE_RELOAD)) {
						return lvupdate;
					}
				} else {
					if (ammostate <= GUNAMMOSTATE_DEPLETED) {
						changefunc = false;
					}
				}
			}

			if (changefunc) {
				hand->unk0cc8_07 = false;

				if (bgun_set_state(handnum, HANDSTATE_CHANGEFUNC)) {
					return lvupdate;
				}
			}
		}

		if (ammostate <= GUNAMMOSTATE_DEPLETED) {
			// Attempted to shoot with no ammo

			// Consider switching to another weapon
			if (gset_has_weapon_flag(info->weaponnum, WEAPONFLAG_THROWABLE)
					&& (info->weaponnum != WEAPON_REMOTEMINE || handnum != HAND_LEFT)
					&& bgun_set_state(handnum, HANDSTATE_AUTOSWITCH)) {
				return lvupdate;
			}

			// Consider switching to other gun function
			usesec = FUNCISSEC();

			if (usesec == gunfunc) {
				ammostate2 = bgun_get_ammo_state(1 - hand->gset.weaponfunc, info, hand);

				if (bgun0f099188(hand, 1 - hand->gset.weaponfunc) && info->weaponnum != WEAPON_REAPER) {
					if (info->gunctrl->wantammo) {
						func = gset_get_funcdef_by_gset_funcnum(&hand->gset, 1 - hand->gset.weaponfunc);

						if ((func->type & 0xff) != INVENTORYFUNCTYPE_MELEE) {
							ammostate2 = GUNAMMOSTATE_DEPLETED;
						}
					} else {
						ammostate2 = GUNAMMOSTATE_DEPLETED;
					}
				}

				if (ammostate2 <= GUNAMMOSTATE_DEPLETED) {
					hand->unk0cc8_08 = true;
				} else {
					if (!gset_has_weapon_flag(info->weaponnum, WEAPONFLAG_KEEPFUNCWHENEMPTY) || hand->gset.weaponfunc == FUNC_SECONDARY) {
						hand->unk0cc8_07 = true;

						if (bgun_set_state(handnum, HANDSTATE_CHANGEFUNC)) {
							return lvupdate;
						}
					}
				}
			}
		} else if (ammostate == GUNAMMOSTATE_NEEDRELOAD) {
			// Clip is empty
			if (hand->triggeron && info->weaponnum != WEAPON_NONE) {
				hand->unk0cc8_01 = false;

				if (bgun_set_state(handnum, HANDSTATE_ATTACKEMPTY)) {
					return lvupdate;
				}
			} else {
				hand->count60 = 0;
				hand->count = 0;

				if (bgun_set_state(handnum, HANDSTATE_RELOAD)) {
					return lvupdate;
				}
			}
		} else {
			// Clip has ammo
			if (hand->triggeron || (hand->activatesecondary && hand->gset.weaponfunc == FUNC_SECONDARY)) {
				if (info->weaponnum != WEAPON_NONE) {
					g_Vars.currentplayer->doautoselect = false;

					hand->mode = HANDMODE_ATTACK;
					hand->count = 0;
					hand->count60 = 0;
					hand->triggerreleased = false;
					hand->activatesecondary = false;

					if (bgun_set_state(handnum, HANDSTATE_ATTACK)) {
						return lvupdate;
					}
				}
			}

			// Not attacking, but the player may have attempted
			// to change guns or reload while firing
			if (hand->modenext != HANDMODE_NONE) {
				next = hand->modenext;

				hand->mode = hand->modenext;
				hand->count60 = 0;
				hand->count = 0;
				hand->modenext = HANDMODE_NONE;

				if (next == HANDMODE_RELOAD && ammostate < GUNAMMOSTATE_CLIPYES_HELDNO && ammostate >= GUNAMMOSTATE_NEEDRELOAD) {
					if (bgun_set_state(handnum, HANDSTATE_RELOAD)) {
						if (handnum && handnum && handnum);
						return lvupdate;
					}
				}
			}
		}
	}

	if (handnum == HAND_RIGHT) {
		if (info->gunctrl->wantammo) {
			bgun_auto_switch_weapon();
		} else {
			lhand = &g_Vars.currentplayer->hands[1] - handnum;

			if ((hand->unk0cc8_08 || !hand->inuse)
					&& (lhand->unk0cc8_08 || !lhand->inuse)
					&& (hand->triggeron || lhand->triggeron)) {
				bgun_auto_switch_weapon();
			}

			hand->unk0cc8_08 = lhand->unk0cc8_08 = false;
		}
	}

	return 0;
}

void bgun_set_arm_pitch(struct hand *hand, f32 angle)
{
	hand->useposrot = true;

	mtx4_load_x_rotation(angle, &hand->posrotmtx);

	hand->posrotmtx.m[3][0] = 0;
	hand->posrotmtx.m[3][1] = (1.0f - cosf(angle)) * -80.0f;
	hand->posrotmtx.m[3][2] = sinf(angle) * 15.0f;
}

s32 bgun_tick_inc_autoswitch(struct handweaponinfo *info, s32 handnum, struct hand *hand, s32 lvupdate)
{
	u32 stack;
	s32 ammostate;
	s32 gunfunc = bgun_is_using_secondary_function();

	if (!hand->inuse && bgun_set_state(handnum, HANDSTATE_IDLE)) {
		return lvupdate;
	}

	if (hand->stateminor == HANDSTATEMINOR_AUTOSWITCH_UNEQUIP) {
		s32 delay = TICKS(16);

		if (g_Vars.normmplayerisrunning) {
			delay = TICKS(12);
		}

		if (hand->stateframes >= delay) {
			hand->stateminor++; // to HANDSTATEMINOR_AUTOSWITCH_DELETE
		} else {
			bgun_set_arm_pitch(hand, hand->stateframes * MAX_PITCH / delay);
		}
	}

	if (hand->stateminor == HANDSTATEMINOR_AUTOSWITCH_DELETE) {
		hand->lastdirvalid = false;
#if VERSION < VERSION_PAL_BETA
		hand->animframeincfreal = hand->animframeinc;
#endif
		hand->shotremainder = 0;

		if (bgun_is_ready_to_switch(handnum) && bgun_set_state(handnum, HANDSTATE_CHANGEGUN)) {
			if (g_Vars.mplayerisrunning && (IS8MB() || PLAYERCOUNT() != 1)) {
				playermgr_delete_weapon(handnum);
			}

			bgun_free_held_rocket(handnum);

			hand->mode = HANDMODE_6;
			hand->stateminor = HANDSTATEMINOR_AUTOSWITCH_2;
			hand->count = 0;
			return 0;
		}

		if (hand->inuse) {
			ammostate = bgun_get_ammo_state(gunfunc, info, hand);

			if (info->weaponnum == WEAPON_TIMEDMINE || info->weaponnum == WEAPON_PROXIMITYMINE) {
				hand->gset.weaponfunc = gunfunc;
			}

			if (info->weaponnum == WEAPON_REMOTEMINE
					&& gunfunc != hand->gset.weaponfunc
					&& bgun_set_state(handnum, HANDSTATE_CHANGEFUNC)) {
				return lvupdate;
			}

			if (g_Vars.currentplayer->doautoselect) {
				struct hand *otherhand = &g_Vars.currentplayer->hands[1 - handnum];
				struct handweaponinfo otherinfo;
				bool ready = true;

				bgun_get_weapon_info(&otherinfo, 1 - handnum);

				if (otherhand->inuse) {
					if (bgun_get_ammo_state(FUNC_PRIMARY, &otherinfo, otherhand) > GUNAMMOSTATE_DEPLETED) {
						ready = false;
					}

					if (bgun_get_ammo_state(FUNC_SECONDARY, &otherinfo, otherhand) > GUNAMMOSTATE_DEPLETED) {
						ready = false;
					}

					if (bgun0f099188(otherhand, otherhand->gset.weaponfunc)) {
						ready = true;
					}
				}

				if (otherhand->state != HANDSTATE_IDLE && otherhand->state != HANDSTATE_AUTOSWITCH) {
					ready = false;
				}

				if (ready) {
					bgun_auto_switch_weapon();
				}
			}

			if (ammostate <= GUNAMMOSTATE_CLIPYES_HELDYES && ammostate >= GUNAMMOSTATE_NEEDRELOAD) {
				if (g_Vars.currentplayer->hands[1 - handnum].state != HANDSTATE_RELOAD) {
					hand->count60 = 0;
					hand->count = 0;

					if (bgun_set_state(handnum, HANDSTATE_RELOAD)) {
						if (info->weaponnum == WEAPON_COMBATKNIFE) {
							hand->mode = HANDMODE_11;
							hand->pausetime60 = TICKS(17);
							hand->count60 = 0;
							hand->count = -1;
							hand->stateminor = HANDSTATEMINOR_AUTOSWITCH_2;
						}

						return lvupdate;
					}
				}
			}

			if (hand->modenext) {
				hand->mode = hand->modenext;
				hand->count60 = 0;
				hand->count = 0;
				hand->modenext = HANDMODE_NONE;
			}
		}

		bgun_set_arm_pitch(hand, MAX_PITCH);
	}

	return 0;
}

bool bgun_is_reloading(struct hand *hand)
{
	if (hand->state == HANDSTATE_RELOAD) {
		return true;
	}

	return false;
}

s32 bgun_tick_inc_reload(struct handweaponinfo *info, s32 handnum, struct hand *hand, s32 lvupdate)
{
	u32 stack;
	struct funcdef *func = gset_get_funcdef_by_gset(&hand->gset);

	if (g_Vars.currentplayer->isdead) {
		hand->animmode = HANDANIMMODE_IDLE;
		hand->animload = -1;

		if (bgun_set_state(handnum, HANDSTATE_IDLE)) {
			return lvupdate;
		}
	}

	if (hand->statecycles == 0) {
		struct hand *otherhand = &g_Vars.currentplayer->hands[1 - handnum];

		hand->gs_int1 = -1;
		hand->gs_int2 = 0;

		if (otherhand->state == HANDSTATE_RELOAD && otherhand->stateframes < TICKS(20)) {
			hand->stateminor = HANDSTATEMINOR_RELOAD_WAIT;
		}
	}

	if (hand->stateminor == HANDSTATEMINOR_RELOAD_WAIT) {
		struct hand *otherhand = &g_Vars.currentplayer->hands[1 - handnum];

		if (otherhand->state == HANDSTATE_RELOAD && otherhand->stateframes < TICKS(20)) {
			return 0;
		}

		hand->stateframes = 0;
		hand->statecycles = 0;
		hand->stateminor = HANDSTATEMINOR_RELOAD_MAIN;
		hand->statelastframe = 0;
	}

	if (hand->stateminor == HANDSTATEMINOR_RELOAD_MAIN) {
		if (hand->statecycles == 0) {
			if (func && (func->ammoindex == 0 || func->ammoindex == 1)) {
				if (info->definition->ammos[func->ammoindex]->reload_animation
						&& info->weaponnum != WEAPON_COMBATKNIFE) {
					bgun_start_animation(info->definition->ammos[func->ammoindex]->reload_animation, handnum, hand);

					hand->unk0d0e_07 = true;

					if (info->definition->ammos[func->ammoindex]->flags & AMMOFLAG_INCREMENTALRELOAD) {
						hand->incrementalreloading = true;
					}

					if (info->weaponnum == WEAPON_GRENADE || info->weaponnum == WEAPON_NBOMB) {
						hand->ejectstate = EJECTSTATE_INACTIVE;
					}
				} else {
					hand->stateminor++; // to HANDSTATEMINOR_RELOAD_LOWER
				}
			} else {
				if (bgun_set_state(handnum, HANDSTATE_IDLE)) {
					return lvupdate;
				}
			}
		} else {
			if (info->definition->ammos[func->ammoindex]->flags & AMMOFLAG_INCREMENTALRELOAD) {
				if (bgun_anim_allows_feature(hand, GUNFEATURE_RELOAD)) {
					if ((hand->stateflags & HANDSTATEFLAG_BUSY) == 0) {
						s32 ammostate;

						bgun0f098df8(hand->gset.weaponfunc, info, hand, 1, 0);

						hand->stateflags |= HANDSTATEFLAG_BUSY;

						ammostate = bgun_get_ammo_state(hand->gset.weaponfunc, info, hand);

						if (ammostate >= GUNAMMOSTATE_CLIPYES_HELDNO) {
							hand->incrementalreloading = false;
						}

						if (ammostate == GUNAMMOSTATE_DEPLETED) {
							hand->incrementalreloading = false;
						}
					}
				} else {
					hand->stateflags = 0;
				}

				if (hand->triggeron) {
					hand->incrementalreloading = false;
				}

#if VERSION >= VERSION_JPN_FINAL
				if (g_Vars.currentplayer->devicesactive & ~g_Vars.currentplayer->devicesinhibit & DEVICE_EYESPY) {
					hand->incrementalreloading = false;
				}
#endif
			} else {
				if ((hand->stateflags & HANDSTATEFLAG_BUSY) == 0) {
					if (bgun_anim_allows_feature(hand, GUNFEATURE_RELOAD)) {
						bgun0f098df8(hand->gset.weaponfunc, info, hand, 0, 0);
						hand->stateflags |= HANDSTATEFLAG_BUSY;
					}
				}
			}

			if (hand->animmode != HANDANIMMODE_BUSY) {
				if (bgun_set_state(handnum, HANDSTATE_IDLE)) {
					return lvupdate;
				}
			}

			if (1);
		}
	}

	if (hand->stateminor == HANDSTATEMINOR_RELOAD_LOWER) {
		if (hand->count60 > TICKS(15) || !hand->visible) {
			hand->mode = HANDMODE_11;
			hand->stateminor++; // to HANDSTATEMINOR_RELOAD_SOUND
			hand->pausetime60 = TICKS(17);
			hand->count60 = 0;
			hand->count = 0;
		} else {
			bgun_set_arm_pitch(hand, hand->count60 * MAX_PITCH / TICKS(16));
		}
	}

	if (hand->stateminor == HANDSTATEMINOR_RELOAD_SOUND) {
		if (hand->count == 0) {
			if (info->weaponnum == WEAPON_COMBATKNIFE
					&& func->ammoindex >= 0
					&& info->definition->ammos[func->ammoindex]->reload_animation) {
				bgun_start_animation(info->definition->ammos[func->ammoindex]->reload_animation, handnum, hand);
				hand->unk0cc8_02 = true;
			}

			if ((hand->stateflags & HANDSTATEFLAG_BUSY) == 0) {
				bgun0f098df8(hand->gset.weaponfunc, info, hand, 0, 0);
			}

			if (g_Vars.lvupdate240 > 0
					&& g_Vars.currentplayer->cameramode != CAMERAMODE_THIRDPERSON
					&& bgun_is_loaded()
					&& !g_PlayerInvincible
					&& !g_Vars.currentplayer->isdead) {
				switch (info->weaponnum) {
				case WEAPON_NONE:
				case WEAPON_UNARMED:
				case WEAPON_COMBATKNIFE:
				case WEAPON_LASER:
				case WEAPON_GRENADE:
				case WEAPON_TIMEDMINE:
				case WEAPON_PROXIMITYMINE:
				case WEAPON_REMOTEMINE:
				case WEAPON_ECMMINE:
				case WEAPON_COMMSRIDER:
				case WEAPON_TRACERBUG:
				case WEAPON_TARGETAMPLIFIER:
				case WEAPON_BRIEFCASE2:
					// No reload sound
					break;
				default:
					snd_start(var80095200, SFX_RELOAD_DEFAULT, 0, -1, -1, -1, -1, -1);
					break;
				}
			}
		}

		if (hand->count60 >= hand->pausetime60 && hand->count >= 2) {
			hand->mode = HANDMODE_12;
			hand->stateminor++; // to HANDSTATEMINOR_RELOAD_RAISE
			hand->count60 = 0;
			hand->count = 0;
		} else {
			bgun_set_arm_pitch(hand, MAX_PITCH);
		}
	}

	if (hand->stateminor == HANDSTATEMINOR_RELOAD_RAISE) {
		if (info->weaponnum == WEAPON_COMBATKNIFE) {
			hand->animmode = HANDANIMMODE_IDLE;
		}

		if (hand->count == 0) {
			g_Vars.currentplayer->doautoselect = false;
		}

		if (hand->count60 >= TICKS(23)
				|| !gset_get_filenum2(info->weaponnum)
				|| !gset_has_weapon_flag(info->weaponnum, WEAPONFLAG_00000040)
				|| gset_has_weapon_flag(info->weaponnum, WEAPONFLAG_00000080)) {
			hand->mode = HANDMODE_NONE;
			hand->count60 = 0;
			hand->count = 0;

			if (bgun_set_state(handnum, HANDSTATE_IDLE)) {
				return lvupdate;
			}
		} else {
			bgun_set_arm_pitch(hand, (TICKS(23) - hand->count60) * MAX_PITCH / TICKS(23));
		}
	}

	return 0;
}

s32 bgun_tick_inc_changefunc(struct handweaponinfo *info, s32 handnum, struct hand *hand, s32 lvupdate)
{
	struct guncmd *cmd;
	bool more = false;

	if (hand->statecycles == 0) {
		if (hand->gset.weaponfunc == FUNC_PRIMARY) {
			cmd = gset_get_pritosec_anim(&hand->gset);
			hand->gset.weaponfunc = FUNC_SECONDARY;
		} else {
			cmd = gset_get_sectopri_anim(&hand->gset);
			hand->gset.weaponfunc = FUNC_PRIMARY;
		}

		more = false;

		if (cmd != NULL) {
			bgun_start_animation(cmd, handnum, hand);
			more = true;
			g_Vars.currentplayer->hands[HAND_RIGHT].unk0dd4 = -1;
		}
	} else {
		if (hand->animmode == HANDANIMMODE_BUSY) {
			more = true;
		}
	}

	if (!more && bgun_set_state(handnum, HANDSTATE_IDLE)) {
		return lvupdate;
	}

	return 0;
}

s32 bgun0f09a3f8(struct hand *hand, struct funcdef *func)
{
	bool burst = false;
	bool smallburst = false;
	struct gunctrl *ctrl = &g_Vars.currentplayer->gunctrl;

	if ((func->flags & FUNCFLAG_BURST3) && hand->burstbullets < 3) {
		// Make automatics do single shot when holding aim
		if (!g_Vars.currentplayer->insightaimmode || (func->type & 0xff00) != 0x100) {
			// Not aiming and not an automatic weapon
			smallburst = true;
		}
	}

	if ((func->flags & FUNCFLAG_BURST2) && hand->burstbullets < 2) {
		smallburst = true;
	}

	if ((func->flags & FUNCFLAG_BURST5) && hand->burstbullets < 5) {
		smallburst = true;
	}

	if ((func->flags & FUNCFLAG_BURST50) && hand->burstbullets < 50) {
		burst = true;
	}

	if (smallburst) {
		burst = true;
	}

	if (hand->triggeron || (hand->stateflags & HANDSTATEFLAG_BUSY) == 0 || burst) {
		if (func->ammoindex >= 0
				&& hand->loadedammo[func->ammoindex] == 0
				&& ctrl->ammotypes[func->ammoindex] >= 0) {
			// Clip is empty
			return -1;
		}

		if ((func->type & 0xff00) == 0x100) {
			struct funcdef_shootauto *autofunc = (struct funcdef_shootauto *) func;

			if (autofunc->turretaccel > 0) { // reaper
				if (hand->gs_barrelspeedfrac < 1) {
					hand->gs_barrelspeedfrac += LVUPDATE60FREAL() / autofunc->turretaccel;

					if (hand->gs_barrelspeedfrac > 1) {
						hand->gs_barrelspeedfrac = 1;
					}
				}
			} else {
				hand->gs_barrelspeedfrac = 1;
			}

			return 1;
		}

		hand->gs_barrelspeedfrac = 1;

		if (smallburst) {
			if (hand->burstbullets > 0) {
				s32 delay = 3;

				if (hand->gset.weaponnum == WEAPON_SHOTGUN) {
					delay = TICKS(13);
				}

				if (hand->stateframes < delay) {
					return 0;
				}
			}

			hand->stateframes = 0;
		}

		if ((func->flags & FUNCFLAG_BURST3) && hand->burstbullets == 2) {
			smallburst = false;
		}

		if ((func->flags & FUNCFLAG_BURST2) && hand->burstbullets == 1) {
			smallburst = false;
		}

		if ((func->flags & FUNCFLAG_BURST5) && hand->burstbullets == 4) {
			smallburst = false;
		}

		if (smallburst) {
			return 1;
		}

		return 2;
	}

	if ((func->type & 0xff00) == (INVENTORYFUNCTYPE_SHOOT_AUTOMATIC & 0xff00)) {
		struct funcdef_shootauto *autofunc = (struct funcdef_shootauto *) func;

		if (autofunc->turretdecel > 0) { // reaper
			if (hand->gs_barrelspeedfrac > 0) {
				hand->gs_barrelspeedfrac -= LVUPDATE60FREAL() / autofunc->turretdecel;

				if (hand->gs_barrelspeedfrac < 0) {
					hand->gs_barrelspeedfrac = 0;
					return -1;
				}

				return 1;
			}
		} else {
			hand->gs_barrelspeedfrac = 0;
		}

		return -1;
	}

	return -1;
}

void bgun0f09a6f8(struct handweaponinfo *info, s32 handnum, struct hand *hand, struct funcdef *func)
{
	bool usesammo = true;

	static u32 rontime = 2;
	static u32 rofftime = 4;

	main_override_variable("rontime", &rontime);
	main_override_variable("rofftime", &rofftime);

	hand->firing = true;

	if ((func->type & 0xff00) == 0x100) {
		struct funcdef_shootauto *autofunc = (struct funcdef_shootauto *) func;
		f32 tmp;
		f32 tmp2;

		tmp = autofunc->initialrpm + (autofunc->maxrpm - autofunc->initialrpm) * hand->gs_barrelspeedfrac;
		tmp2 = tmp / 60.0f * (LVUPDATE60FREAL() / 60.0f) + hand->shotremainder;

		hand->shotstotake = tmp2;
		hand->shotremainder = tmp2 - hand->shotstotake;

		if (hand->shotstotake <= 0) {
			if ((hand->stateflags & HANDSTATEFLAG_BUSY) == 0) {
				hand->shotstotake++;
			} else {
				hand->firing = false;
			}
		}
	} else {
		hand->shotstotake = 1;

		if (hand->gset.weaponnum == WEAPON_LASER) {
			usesammo = false;
		}
	}

	hand->burstbullets += hand->shotstotake;

	if (func->flags & FUNCFLAG_NOMUZZLEFLASH) {
		hand->flashon = false;
	} else {
		hand->flashon = true;
	}

	bgun_start_slide(handnum);

	hand->loadslide = 0;

	if (hand->firing) {
		hand->statevar1 = hand->stateframes;
		hand->stateflags |= HANDSTATEFLAG_FIRED;
		hand->stateflags |= HANDSTATEFLAG_BUSY;

		bgun_rumble(handnum, info->weaponnum);

		if (usesammo && func->ammoindex >= 0) {
			hand->loadedammo[func->ammoindex] -= hand->shotstotake;

			if (hand->loadedammo[func->ammoindex] < 0) {
				// Note: loadedammo is negative
				hand->shotstotake += hand->loadedammo[func->ammoindex];
				hand->loadedammo[func->ammoindex] = 0;
			}
		}

		switch (func->type & 0xff00) {
		case 0:
		case 0x100:
			hand->attacktype = HANDATTACKTYPE_SHOOT;
			break;
		case 0x200:
			hand->attacktype = HANDATTACKTYPE_SHOOTPROJECTILE;
			break;
		}
	}

	if (hand->firing) {
		bool playsound = false;

		if (gset_get_fireslot_duration(&hand->gset) > 0) {
			if (g_Vars.lvframe60 != g_Vars.currentplayer->hands[1 - handnum].lastshootframe60
					&& g_Vars.lvframe60 > hand->allowshootframe) {
				hand->allowshootframe = g_Vars.lvframe60 + gset_get_fireslot_duration(&hand->gset);
				playsound = true;
			}
		} else {
			if (hand->firing) {
				playsound = true;
			}
		}

		if (playsound) {
#if VERSION >= VERSION_NTSC_1_0
			OSPri prevpri = osGetThreadPri(0);
			osSetThreadPri(0, osGetThreadPri(&g_AudioManager.thread) + 1);
#endif

			if (hand->audiohandle2 && sndGetState(hand->audiohandle2) != AL_STOPPED) {
				audioStop(hand->audiohandle2);
			}

			if (hand->audiohandle3 && sndGetState(hand->audiohandle3) != AL_STOPPED) {
				audioStop(hand->audiohandle3);
			}

			if (gset_get_single_shoot_sound(&hand->gset)) {
				struct sndstate *handle = NULL;

				if (hand->audiohandle2 == NULL) {
					handle = snd_start(var80095200, gset_get_single_shoot_sound(&hand->gset), &hand->audiohandle2, -1, -1, -1, -1, -1);
				} else if (hand->audiohandle3 == NULL) {
					handle = snd_start(var80095200, gset_get_single_shoot_sound(&hand->gset), &hand->audiohandle3, -1, -1, -1, -1, -1);
				}

				hand->lastshootframe60 = g_Vars.lvframe60;

				if (hand->gset.weaponnum == WEAPON_MAULER && handle) {
					s32 charge = hand->mm_maulercharge;
					f32 tmp;
					f32 frac = charge / 3.0f;

					if (frac > 1.0f) {
						frac = 1.0f;
					}

					tmp = 1.0f - frac * 0.4f;

					audioPostEvent(handle, AL_SNDP_PITCH_EVT, *(s32 *) &tmp);
				}

			}

#if VERSION >= VERSION_NTSC_1_0
			osSetThreadPri(0, prevpri);
#endif
		}
	}
}

bool bgun_tick_recoil(struct hand *hand, struct handweaponinfo *info, s32 handnum, struct funcdef_shoot *func)
{
	s32 unk24;
	s32 unk25;
	s32 sum;
	s32 unk26;
	s32 unk27;
	s32 recoverytime60;
	s32 curframe;
	struct weapondef *weapondef;
	f32 mult1;
	f32 recoildist;
	f32 recoilangle;
	f32 mult2;
	u32 stack;

#if PAL
	unk24 = func->unk24;
	unk25 = func->unk25;
	unk26 = func->unk26;
	unk27 = func->unk27;
	recoverytime60 = func->recoverytime60;
	weapondef = info->definition;

	if (unk24 >= 4) {
		unk24 = TICKS(unk24);
	}

	if (unk25 >= 4) {
		unk25 = TICKS(unk25);
	}

	if (unk26 >= 4) {
		unk26 = TICKS(unk26);
	}

	if (unk27 >= 4) {
		unk27 = TICKS(unk27);
	}

	if (recoverytime60 >= 4) {
		recoverytime60 = TICKS(recoverytime60);
	}

	sum = unk24 + unk25;
#elif VERSION >= VERSION_JPN_FINAL
	unk24 = func->unk24;
	unk25 = func->unk25;
	unk26 = func->unk26;
	unk27 = func->unk27;
	recoverytime60 = func->recoverytime60;
	weapondef = info->definition;
	sum = unk24 + unk25;
#else
	unk24 = func->unk24;
	unk25 = func->unk25;
	sum = unk24 + unk25;
	unk26 = func->unk26; // refire
	unk27 = func->unk27; // refire
	recoverytime60 = func->recoverytime60;
	weapondef = info->definition;
#endif

	curframe = hand->stateframes - hand->statevar1;

	if (sum <= 0) {
		sum = 0;
	} else {
		if (hand->triggerreleased
				&& hand->triggeron
				&& curframe >= unk26
				&& unk26 > 0
				&& unk27 >= 0
				&& (hand->stateflags & HANDSTATEFLAG_00000040) == 0
				&& curframe + unk27 < sum) {
			// Fired during recoil
			hand->stateflags |= HANDSTATEFLAG_00000040;
			hand->statevar1 = curframe;

			hand->rotxstart = hand->rotxoffset;
			hand->rotxend = 0;

			hand->posend.x = 0;
			hand->posend.y = 0;
			hand->posend.z = 0;

			hand->posstart.x = hand->posoffset.x;
			hand->posstart.y = hand->posoffset.y;
			hand->posstart.z = hand->posoffset.z;
		}

		if (hand->stateflags & HANDSTATEFLAG_00000040) {
			if (curframe - hand->statevar1 < unk27) {
				mult1 = cosf((f32)(unk27 - curframe + hand->statevar1) * DTOR(90) / (f32)unk27) * 0.5f + 0.5f;

				hand->rotxoffset = model_tween_rot_axis(hand->rotxstart, hand->rotxend, mult1);
				hand->useposrot = true;

				hand->posoffset.x = (hand->posend.x - hand->posstart.x) * mult1 + hand->posstart.x;
				hand->posoffset.y = (hand->posend.y - hand->posstart.y) * mult1 + hand->posstart.y;
				hand->posoffset.z = (hand->posend.z - hand->posstart.z) * mult1 + hand->posstart.z;

				mtx4_load_x_rotation(hand->rotxoffset, &hand->posrotmtx);
				mtx4_set_translation(&hand->posoffset, &hand->posrotmtx);
			} else {
				mtx4_load_identity(&hand->posrotmtx);
				hand->useposrot = false;
				return true;
			}
		}

		if (curframe < sum && (hand->stateflags & HANDSTATEFLAG_00000040) == 0) {
			recoildist = func->recoildist;
			recoilangle = func->recoilangle;

			if ((hand->stateflags & HANDSTATEFLAG_00000080) == 0) {
				hand->stateflags |= HANDSTATEFLAG_00000080;
				hand->rotxstart = hand->rotxoffset;
				hand->posstart.x = hand->posoffset.x;
				hand->posstart.y = hand->posoffset.y;
				hand->posstart.z = hand->posoffset.z;
			}

			hand->rotxend = BADDTOR(360) - BADDTOR3(recoilangle);

			hand->posend.x = (gset_get_xpos(handnum) - hand->aimpos.x) * recoildist / 1000.0f;
			hand->posend.y = 0;
			hand->posend.z = (weapondef->posz - hand->aimpos.z) * recoildist / 1000.0f;

			if (curframe < unk24) {
				mult2 = sinf(curframe * DTOR(90) / (f32)unk24);
			} else {
				mult2 = cosf((f32)(curframe - unk24) * DTOR(180) / (f32)unk25) * 0.5f + 0.5f;
			}

			hand->rotxoffset = model_tween_rot_axis(hand->rotxstart, hand->rotxend, mult2);
			hand->useposrot = true;

			hand->posoffset.x = (hand->posend.x - hand->posstart.x) * mult2 + hand->posstart.x;
			hand->posoffset.y = (hand->posend.y - hand->posstart.y) * mult2 + hand->posstart.y;
			hand->posoffset.z = (hand->posend.z - hand->posstart.z) * mult2 + hand->posstart.z;

			mtx4_load_x_rotation(hand->rotxoffset, &hand->posrotmtx);
			mtx4_set_translation(&hand->posoffset, &hand->posrotmtx);
		}
	}

	if (curframe >= sum) {
		if (unk27 >= 0 && hand->triggerreleased && hand->triggeron) {
			return true;
		} else if (sum + recoverytime60 <= curframe) {
			return true;
		}
	}

	return false;
}

bool bgun_tick_inc_attacking_shoot(struct handweaponinfo *info, s32 handnum, struct hand *hand)
{
	static u32 var80070128 = 99;

	struct funcdef *func = gset_get_funcdef_by_gset(&hand->gset);
	bool canfireagain;
	s32 sp64;
	s32 sp60;

	if (func == NULL) {
		return true;
	}

	if (hand->stateminor == HANDSTATEMINOR_ATTACK_SHOOT_0) {
		sp64 = 1;

		main_override_variable("gkef", &var80070128);

		if (hand->statecycles == 0) {
			hand->gs_barrelspeedfrac = 0;

			if (func->fire_animation) {
				bgun_start_animation(func->fire_animation, handnum, hand);
				hand->unk0cc8_01 = true;
			}

			hand->burstbullets = 0;
		}

		if (!bgun_anim_allows_feature(hand, GUNFEATURE_ATTACK)) {
			sp64 = 0;
		}

		if (sp64) {
			hand->stateminor = HANDSTATEMINOR_ATTACK_SHOOT_1;
		}

		hand->mm_reaperspeedaim = hand->gs_barrelspeedfrac;
	}

	if (hand->stateminor == HANDSTATEMINOR_ATTACK_SHOOT_1) {
		sp60 = bgun0f09a3f8(hand, func);

		if ((func->type & 0xff00) == 0x100) {
			struct funcdef_shootauto *autofunc = (struct funcdef_shootauto *) func;
			f32 floats[12];

			if (autofunc->vibrationstart != NULL && autofunc->vibrationmax != NULL) {
				func0f097b64(autofunc->vibrationstart, autofunc->vibrationmax, hand->gs_barrelspeedfrac, floats);
				func0f097b40(hand->upgrademult, floats, hand->finalmult);
			}
		}

		if (sp60 > 0) {
			bgun0f09a6f8(info, handnum, hand, func);
		}

		if (sp60 < 0 || sp60 == 2) {
			hand->stateminor = HANDSTATEMINOR_ATTACK_SHOOT_2;
		}

		hand->mm_reaperspeedaim = hand->gs_barrelspeedfrac;

		if (hand->triggeron && hand->mm_reaperspeedaim < 0.4f) {
			hand->mm_reaperspeedaim = 0.4f;
		}

		if (hand->triggerreleased) {
			hand->unk0cc8_01 = false;
		}

		return false;
	}

	if (hand->stateminor == HANDSTATEMINOR_ATTACK_SHOOT_2) {
		if (hand->stateflags & HANDSTATEFLAG_FIRED) {
			canfireagain = bgun_tick_recoil(hand, info, handnum, (struct funcdef_shoot *) func);
		} else {
			canfireagain = true;
		}

		if (hand->gset.weaponnum == WEAPON_SHOTGUN && hand->animmode == HANDANIMMODE_BUSY) {
			canfireagain = false;
		}

		hand->mm_reaperspeedaim = hand->gs_barrelspeedfrac;

		if (canfireagain && !hand->triggeron) {
			hand->mm_reaperspeedaim = 0;
		}

		if (hand->gset.weaponnum == WEAPON_MAULER) {
			hand->mm_maulercharge = 0;
		}

		return canfireagain;
	}

	return false;
}

bool bgun_tick_inc_attacking_throw(s32 handnum, struct hand *hand)
{
	struct funcdef_throw *func = (struct funcdef_throw *) gset_get_funcdef_by_gset(&hand->gset);

	if (func == NULL) {
		return true;
	}

	if (hand->stateminor == HANDSTATEMINOR_ATTACK_THROW_0) {
		if (hand->statecycles == 0) {
			if (func->base.flags & FUNCFLAG_DISCARDWEAPON) {
				inv_remove_item_by_num(hand->gset.weaponnum);
				g_Vars.currentplayer->gunctrl.throwing = true;
#if VERSION >= VERSION_NTSC_1_0
				bgun_switch_to_previous();
#else
				bgun_auto_switch_weapon();
#endif
				hand->primetimer60 = 0;
				return true;
			}

			if (func->base.fire_animation) {
				bgun_start_animation(func->base.fire_animation, handnum, hand);
				hand->unk0cc8_01 = true;
			}
		}

		if (func->base.fire_animation) {
			if (hand->triggerreleased) {
				hand->unk0cc8_01 = false;
			}

			if (bgun_anim_allows_feature(hand, GUNFEATURE_ATTACK)) {
				hand->stateminor = HANDSTATEMINOR_ATTACK_THROW_1;
				hand->unk0cc8_01 = false;
			}
		} else {
			hand->stateminor = HANDSTATEMINOR_ATTACK_THROW_1;
		}
	}

	if (hand->stateminor == HANDSTATEMINOR_ATTACK_THROW_1) {
		hand->firing = true;
		hand->attacktype = HANDATTACKTYPE_THROWPROJECTILE;
		hand->loadedammo[func->base.ammoindex]--;
		hand->stateminor = HANDSTATEMINOR_ATTACK_THROW_2;
		return false;
	}

	if (hand->stateminor == HANDSTATEMINOR_ATTACK_THROW_2) {
		if (hand->stateframes > TICKS(func->recoverytime60)) {
			return true;
		}

		if (hand->gset.weaponnum == WEAPON_REMOTEMINE
				&& bgun_is_using_secondary_function() == true
				&& hand->triggerreleased
				&& hand->triggeron) {
			return true;
		}

		return false;
	}

	// This state is only used after having a grenade explode in the player's
	// hand. It waits 4 seconds before finishing, which means the player won't
	// pull out another grenade until the flames have cleared.
	if (hand->stateminor == HANDSTATEMINOR_ATTACK_THROW_GRENADEWAIT) {
		bgun_reset_anim(hand);

		if (hand->stateframes > TICKS(func->activatetime60 + 240)) {
			return true;
		}

		return false;
	}

	hand->primetimer60 = hand->stateframes;

	// If held a grenade too long, force throw it and enter the wait state
	if (hand->gset.weaponnum == WEAPON_GRENADE
			&& hand->gset.weaponfunc == FUNC_PRIMARY
			&& hand->primetimer60 > TICKS(func->activatetime60)) {
		hand->firing = true;
		hand->attacktype = HANDATTACKTYPE_THROWPROJECTILE;
		hand->loadedammo[func->base.ammoindex]--;
		hand->stateminor = HANDSTATEMINOR_ATTACK_THROW_GRENADEWAIT;

		return false;
	}

	return false;
}

s32 bgun_get_min_clip_qty(s32 weaponnum, s32 funcnum)
{
	if (weaponnum == WEAPON_TRANQUILIZER && funcnum == FUNC_SECONDARY) {
		return 4;
	}

	return 1;
}

const char var7f1ab8ac[] = "changegunmem type %d CurrentPlayer->gunctrl.gunmemtype %d\n";
const char var7f1ab8e8[] = "LockTimer: %d\n";
const char var7f1ab8f8[] = "BriGun: Releasing gunmem - current gunmemtype %d gunmemnew %d\n";
const char var7f1ab938[] = "GiveMem: %d\n";

u32 var8007012c = 0x00000000;
u32 var80070130 = 0x00000000;

bool bgun_tick_inc_attacking_melee(s32 handnum, struct hand *hand)
{
	struct funcdef *func = gset_get_funcdef_by_gset(&hand->gset);

	if (func == NULL) {
		return true;
	}

	if (hand->gset.weaponnum == WEAPON_REAPER) {
		if (hand->statecycles == 0) {
			hand->mm_reaperspeedaim = 0.1f;
			hand->burstbullets = 0;
		}

		hand->firing = true;
		hand->attacktype = HANDATTACKTYPE_MELEE;
		hand->burstbullets++;

		if (hand->triggeron) {
			hand->mm_reaperspeedaim += 0.01f * LVUPDATE60FREAL();

			if (hand->mm_reaperspeedaim > 1) {
				hand->mm_reaperspeedaim = 1;
			}
		} else {
			hand->mm_reaperspeedaim = 0;
			return true;
		}

		return false;
	}

	if (hand->stateminor == HANDSTATEMINOR_ATTACK_MELEE_0) {
		if (hand->statecycles == 0) {
			hand->firing = true;
			hand->attacktype = HANDATTACKTYPE_MELEENOUNCLOAK;

			if (func->fire_animation) {
				bgun_start_animation(func->fire_animation, handnum, hand);
				hand->unk0cc8_01 = true;
			}
		}

		if (func->fire_animation) {
			if (hand->triggerreleased) {
				hand->unk0cc8_01 = false;
			}

			if (bgun_anim_allows_feature(hand, GUNFEATURE_ATTACK)) {
				hand->stateminor = HANDSTATEMINOR_ATTACK_MELEE_1;
				hand->unk0cc8_01 = false;
			}
		} else {
			hand->stateminor = HANDSTATEMINOR_ATTACK_MELEE_1;
		}
	}

	if (hand->stateminor == HANDSTATEMINOR_ATTACK_MELEE_3 && bgun_anim_allows_feature(hand, GUNFEATURE_ATTACKAGAIN)) {
		hand->stateminor = HANDSTATEMINOR_ATTACK_MELEE_1;
		hand->unk0cc8_01 = false;
	}

	if (hand->stateminor == HANDSTATEMINOR_ATTACK_MELEE_1) {
		hand->firing = true;
		hand->attacktype = HANDATTACKTYPE_MELEE;

		if (hand->gset.weaponnum == WEAPON_TRANQUILIZER && func->ammoindex >= 0) {
			if (hand->loadedammo[func->ammoindex] > bgun_get_min_clip_qty(WEAPON_TRANQUILIZER, FUNC_SECONDARY)) {
				hand->loadedammo[func->ammoindex] -= bgun_get_min_clip_qty(WEAPON_TRANQUILIZER, FUNC_SECONDARY);
			} else {
				hand->loadedammo[func->ammoindex] = 0;
			}
		}

		if (func->fire_animation) {
			if (func->fire_animation && !bgun_anim_allows_feature(hand, GUNFEATURE_ATTACKAGAIN)) {
				hand->stateminor = HANDSTATEMINOR_ATTACK_MELEE_3;
			} else {
				hand->stateminor = HANDSTATEMINOR_ATTACK_MELEE_2;
			}
		}

		if (cheat_is_active(CHEAT_HURRICANEFISTS)) {
			hand->stateminor = HANDSTATEMINOR_ATTACK_MELEE_2;
		}

		return false;
	}

	if (hand->stateminor == HANDSTATEMINOR_ATTACK_MELEE_2) {
		if (!bgun_is_anim_busy(hand)) {
			return true;
		}

		if (cheat_is_active(CHEAT_HURRICANEFISTS) && hand->gset.weaponnum == WEAPON_UNARMED) {
			return true;
		}

		if (hand->stateframes > TICKS(60)) {
			return true;
		}

		return false;
	}

	return false;
}

bool bgun_tick_inc_attacking_special(struct hand *hand)
{
	struct funcdef_special *func = (struct funcdef_special *) gset_get_funcdef_by_gset(&hand->gset);

	if (!func) {
		return true;
	}

	if (hand->stateminor == HANDSTATEMINOR_ATTACK_SPECIAL_START) {
		hand->stateminor = HANDSTATEMINOR_ATTACK_SPECIAL_EXECUTE;
	}

	if (hand->stateminor == HANDSTATEMINOR_ATTACK_SPECIAL_EXECUTE) {
		hand->firing = true;
		hand->attacktype = func->specialfunc;

		if (func->base.ammoindex >= 0) {
			hand->loadedammo[func->base.ammoindex]--;
		}

		hand->stateminor = HANDSTATEMINOR_ATTACK_SPECIAL_RECOVER;
		return false;
	}

	if (hand->stateminor == HANDSTATEMINOR_ATTACK_SPECIAL_RECOVER) {
		if (hand->stateframes > TICKS(func->recoverytime60)) {
			return true;
		}

		return false;
	}

	return false;
}

s32 bgun_tick_inc_attackempty(struct handweaponinfo *info, s32 handnum, struct hand *hand, s32 lvupdate)
{
	u32 stack;
	bool playsound = false;

	switch (info->weaponnum) {
	case WEAPON_FALCON2:
	case WEAPON_FALCON2_SILENCER:
	case WEAPON_FALCON2_SCOPE:
	case WEAPON_MAGSEC4:
	case WEAPON_MAULER:
	case WEAPON_PHOENIX:
	case WEAPON_DY357MAGNUM:
	case WEAPON_DY357LX:
	case WEAPON_CMP150:
	case WEAPON_CYCLONE:
	case WEAPON_CALLISTO:
	case WEAPON_RCP120:
	case WEAPON_LAPTOPGUN:
	case WEAPON_REAPER:
	case WEAPON_TRANQUILIZER:
	case WEAPON_PP9I:
	case WEAPON_CC13:
		// These weapons are weapons with visible finger trigger animations
		if (hand->stateframes > TICKS(25)) {
			hand->stateframes -= TICKS(25);
			hand->stateflags = 0;

			bgun_reset_anim(hand);
		}

		if (hand->animmode != HANDANIMMODE_BUSY) {
			bool restartedanim = false;

			if ((hand->stateflags & HANDSTATEFLAG_BUSY) == 0) {
				struct funcdef *func = NULL;

				if (info->definition) {
					func = gset_get_funcdef_by_gset(&hand->gset);
				}

				if (func && func->fire_animation) {
					bgun_start_animation(func->fire_animation, handnum, hand);
					restartedanim = true;
				}
			}

			if (!restartedanim && hand->stateframes > TICKS(25)) {
				playsound = true;
			}
		} else if (bgun_anim_allows_feature(hand, GUNFEATURE_CLICK)) {
			playsound = true;
		}
		break;
	default:
		// Weapons without visible trigger animations must
		// still play the click sound every 25 frames
		if (hand->stateframes > TICKS(25)) {
			playsound = true;

			hand->stateframes -= TICKS(25);
			hand->stateflags = 0;

			bgun_reset_anim(hand);
		}
	}

	hand->mode = HANDMODE_13;
	hand->count60 = 0;
	hand->count = 0;

	if (playsound && (hand->stateflags & HANDSTATEFLAG_BUSY) == 0) {
		hand->stateflags |= HANDSTATEFLAG_BUSY;

		switch (info->weaponnum) {
		case WEAPON_PHOENIX:
		case WEAPON_CALLISTO:
		case WEAPON_FARSIGHT:
			{
				// Maian weapons have a wet sounding click effect
				f32 speed = 2.07f;

#if VERSION >= VERSION_NTSC_1_0
				OSPri prevpri = osGetThreadPri(0);
				struct sndstate *handle;
				osSetThreadPri(0, osGetThreadPri(&g_AudioManager.thread) + 1);
#else
				struct sndstate *handle;
#endif

				handle = snd_start(var80095200, SFX_HIT_WATER, NULL, -1, -1, -1, -1, -1);

				if (handle) {
					audioPostEvent(handle, AL_SNDP_PITCH_EVT, *(s32 *)&speed);
				}

#if VERSION >= VERSION_NTSC_1_0
				osSetThreadPri(0, prevpri);
#endif
			}
			// fall-through - unsure if intentional
		case WEAPON_TRANQUILIZER:
		case WEAPON_PSYCHOSISGUN:
			{
				// The tranquliser and psychosis gun use the standard click
				// effect but slightly faster.
				f32 speed = 1.5f;

#if VERSION >= VERSION_NTSC_1_0
				OSPri prevpri = osGetThreadPri(0);
				struct sndstate *handle;
				osSetThreadPri(0, osGetThreadPri(&g_AudioManager.thread) + 1);
#else
				struct sndstate *handle;
#endif

				handle = snd_start(var80095200, SFX_FIREEMPTY, NULL, -1, -1, -1, -1, -1);

				if (handle) {
					audioPostEvent(handle, AL_SNDP_PITCH_EVT, *(s32 *)&speed);
				}

#if VERSION >= VERSION_NTSC_1_0
				osSetThreadPri(0, prevpri);
#endif
			}
			break;
		case WEAPON_UNARMED:
		case WEAPON_COMBATKNIFE:
		case WEAPON_GRENADE:
		case WEAPON_NBOMB:
		case WEAPON_TIMEDMINE:
		case WEAPON_PROXIMITYMINE:
		case WEAPON_REMOTEMINE:
		case WEAPON_COMBATBOOST:
			// No sound effect
			break;
		default:
			// Default click sound effect
			snd_start(var80095200, SFX_FIREEMPTY, NULL, -1, -1, -1, -1, -1);
			break;
		}
	}

	// Handle releasing trigger
	if (!hand->triggeron) {
		hand->mode = HANDMODE_NONE;
		hand->count60 = 0;
		hand->count = 0;

		if (bgun_set_state(handnum, HANDSTATE_IDLE)) {
			return lvupdate;
		}

		bgun_reset_anim(hand);
	}

	return 0;
}

s32 bgun_tick_inc_attack(struct handweaponinfo *info, s32 handnum, struct hand *hand, s32 lvupdate)
{
	u32 stack;
	struct funcdef *func = NULL;
	bool finished = true;
	u32 stack2;

	if (info->definition) {
		func = gset_get_funcdef_by_gset(&hand->gset);
	}

	if (func != NULL) {
		switch (func->type & 0xff) {
		case INVENTORYFUNCTYPE_SHOOT:
			finished = bgun_tick_inc_attacking_shoot(info, handnum, hand);
			break;
		case INVENTORYFUNCTYPE_THROW:
			finished = bgun_tick_inc_attacking_throw(handnum, hand);
			break;
		case INVENTORYFUNCTYPE_MELEE:
			finished = bgun_tick_inc_attacking_melee(handnum, hand);
			break;
		case INVENTORYFUNCTYPE_SPECIAL:
			finished = bgun_tick_inc_attacking_special(hand);
			break;
		}
	}

	if (finished) {
		if (hand->gset.weaponnum == WEAPON_REAPER && hand->triggeron) {
			hand->gset.weaponfunc = FUNC_SECONDARY;
			finished = false;
		}

		if (finished && bgun_set_state(handnum, HANDSTATE_IDLE)) {
			return lvupdate;
		}
	}

	if (1);
	if (1);

	return 0;
}

bool bgun_is_ready_to_switch(s32 handnum)
{
	struct player *player = g_Vars.currentplayer;

	// Dont switch if... something firing range related
	if (g_FrIsValidWeapon
			&& fr_get_weapon_by_slot(fr_get_slot()) == player->hands[HAND_RIGHT].gset.weaponnum
			&& g_Vars.currentplayer->gunctrl.throwing == false) {
		return false;
	}

	// Don't switch right hand if left hand is about to auto switch
	if (handnum == HAND_RIGHT
			&& player->hands[HAND_LEFT].inuse
			&& player->hands[HAND_LEFT].state == HANDSTATE_AUTOSWITCH
			&& player->hands[HAND_LEFT].stateminor == HANDSTATEMINOR_AUTOSWITCH_UNEQUIP) {
		return false;
	}

	if (player->gunctrl.switchtoweaponnum >= 0) {
		return true;
	}

	if (handnum == HAND_LEFT) {
		if (handnum == HAND_LEFT) {
			if (player->hands[HAND_RIGHT].state == HANDSTATE_RELOAD) {
				return false;
			}

			if (player->hands[HAND_RIGHT].state == HANDSTATE_CHANGEFUNC) {
				return false;
			}

			if (player->hands[HAND_RIGHT].state == HANDSTATE_ATTACK) {
				return false;
			}
		}

		if (player->hands[handnum].inuse && !player->gunctrl.dualwielding) {
			return true;
		}

		if (!player->hands[handnum].inuse && player->gunctrl.dualwielding) {
			return true;
		}
	}

	return false;
}

bool bgun_can_free_weapon(s32 handnum)
{
	struct player *player = g_Vars.currentplayer;

	if (player->hands[handnum].state == HANDSTATE_CHANGEGUN
			&& player->hands[handnum].stateminor == HANDSTATEMINOR_CHANGEGUN_LOAD
			&& player->hands[handnum].count >= 3
			&& player->gunctrl.throwing == false) {
		return true;
	}

	return false;
}

bool bgun0f09bf44(s32 handnum)
{
	bool result = true;
	struct player *player = g_Vars.currentplayer;

	if (!bgun_is_loaded()) {
		result = false;
	}

	if (player->gunctrl.switchtoweaponnum != -1) {
		result = false;
	}

	if (handnum == HAND_LEFT && player->gunctrl.dualwielding != player->hands[handnum].inuse) {
		result = false;
	}

	if (player->gunctrl.gunmemnew >= 0) {
		result = false;
	}

	if (player->hands[1 - handnum].state == HANDSTATE_RELOAD) {
		result = false;
	}

	return result;
}

s32 bgun_tick_inc_changegun(struct handweaponinfo *info, s32 handnum, struct hand *hand, s32 lvupdate)
{
	u32 stack;
	struct weapondef *weapon = info->definition;

	if (hand->statecycles == 0) {
		if (g_Vars.normmplayerisrunning == false) {
			hand->pausetime60 = 0;
		} else {
			hand->pausetime60 = 0;
		}
	}

	// Handle unequip animation. Wait in this state until the animation is
	// finished, or skip this state if there is no animation to play.
	if (hand->stateminor == HANDSTATEMINOR_CHANGEGUN_UNEQUIP) {
		bool skipanim = false;

		if (gset_has_weapon_flag(info->weaponnum, WEAPONFLAG_THROWABLE)
				&& !(info->weaponnum == WEAPON_REMOTEMINE && handnum == HAND_LEFT)
				&& bgun_get_ammo_state(FUNC_PRIMARY, info, hand) <= GUNAMMOSTATE_DEPLETED) {
			skipanim = true;
		}

		hand->count = 0;

		if (!skipanim) {
			if (weapon->unequip_animation
					&& hand->inuse == true
					&& !(hand->ejectstate != EJECTSTATE_INACTIVE && hand->ejecttype == EJECTTYPE_GUN)) {
				if (hand->statecycles == 0) {
					bgun_start_animation(weapon->unequip_animation, handnum, hand);
				} else if (hand->animmode == HANDANIMMODE_IDLE) {
					hand->stateminor++; // to HANDSTATEMINOR_CHANGEGUN_LOWER
				}
			} else {
				hand->stateflags |= HANDSTATEFLAG_00000001;

				if (hand->ejectstate == EJECTSTATE_INIT) {
					return 0;
				}

				hand->stateminor++; // to HANDSTATEMINOR_CHANGEGUN_LOWER
			}
		} else {
			hand->stateminor++; // to HANDSTATEMINOR_CHANGEGUN_LOWER
		}

		if (hand->stateminor == HANDSTATEMINOR_CHANGEGUN_LOWER) {
			hand->stateframes = 0;
		}
	}

	// For classic guns, handle lowering it to offscreen.
	// Throw the gun if that's what the player is doing.
	if (hand->stateminor == HANDSTATEMINOR_CHANGEGUN_LOWER) {
		s32 delay = TICKS(16);
		bool throwing = false;
		u32 stack2;

		hand->count = 0;

		if (g_Vars.normmplayerisrunning) {
			delay = TICKS(12);
		}

		if (weapon->unequip_animation && (hand->stateflags & HANDSTATEFLAG_00000001) == 0) {
			delay = 1;
		}

		if (!hand->inuse) {
			delay = 1;
		}

		if (hand->ejecttype == EJECTTYPE_GUN
				&& (hand->ejectstate == EJECTSTATE_INIT || hand->ejectstate == EJECTSTATE_AIRBORNE)) {
			throwing = true;
		}

		if (g_Vars.currentplayer->gunctrl.throwing == true) {
			throwing = true;
		}

		if (hand->stateframes >= delay) {
			if (!throwing) {
				if (g_Vars.mplayerisrunning && (IS8MB() || PLAYERCOUNT() != 1)) {
					playermgr_delete_weapon(handnum);
				}

				bgun_free_held_rocket(handnum);
				hand->mode = HANDMODE_6;
				hand->stateminor++; // to HANDSTATEMINOR_CHANGEGUN_LOAD
			} else {
				bgun_set_arm_pitch(hand, MAX_PITCH);

				if (g_Vars.currentplayer->gunctrl.throwing == true && hand->inuse) {
					hand->firing = true;
					hand->attacktype = HANDATTACKTYPE_THROWPROJECTILE;
					hand->gset.weaponfunc = FUNC_SECONDARY;
				}
			}
		} else {
			bgun_set_arm_pitch(hand, hand->stateframes * MAX_PITCH / delay);
		}
	}

	// Wait for the new gun to be loaded, then start its equip animation
	// (if any) and move on to the next state.
	if (hand->stateminor == HANDSTATEMINOR_CHANGEGUN_LOAD) {
		hand->animmode = HANDANIMMODE_IDLE;

		if (hand->pausechange == 0 || hand->pausetime60 <= hand->count60) {
			if (hand->mode == HANDMODE_6) {
				if (bgun0f09bf44(handnum)) {
					hand->mode = HANDMODE_7;

					if (!hand->inuse && bgun_set_state(handnum, HANDSTATE_IDLE)) {
						return lvupdate;
					}
				}
			} else {
				if (bgun_is_loaded()) {
					if (info->definition->equip_animation) {
						bgun_start_animation(info->definition->equip_animation, handnum, hand);
						hand->unk0cc8_02 = true;
					}

					hand->mode = HANDMODE_EQUIP;
					hand->stateminor++; // to HANDSTATEMINOR_CHANGEGUN_RAISE
					hand->count60 = 0;
					hand->count = 0;
				}
			}
		}

		if (hand->mode == HANDMODE_6 || hand->mode == HANDMODE_7) {
			bgun_set_arm_pitch(hand, MAX_PITCH);
		}
	}

	// Handle raising the new gun and playing the equipped sound effect.
	if (hand->stateminor == HANDSTATEMINOR_CHANGEGUN_RAISE) {
		s32 delay = TICKS(23);

		if (g_Vars.normmplayerisrunning) {
			delay = TICKS(12);
		}

		if (gset_has_weapon_flag(hand->gset.weaponnum, WEAPONFLAG_00004000)) {
			hand->animmode = HANDANIMMODE_IDLE;
		} else if (weapon->equip_animation) {
			delay = 1;
		}

		if (hand->count == 0) {
			if (g_Vars.mplayerisrunning && (IS8MB() || PLAYERCOUNT() != 1)) {
				playermgr_create_weapon(handnum);
			}

			bgun0f098f8c(info, hand);

			if (gset_has_weapon_flag(info->weaponnum, WEAPONFLAG_THROWABLE)
					&& (info->weaponnum != WEAPON_REMOTEMINE || handnum != HAND_LEFT)
					&& bgun_get_ammo_state(FUNC_PRIMARY, info, hand) <= GUNAMMOSTATE_DEPLETED
					&& bgun_set_state(handnum, HANDSTATE_AUTOSWITCH)) {
				hand->stateminor = HANDSTATEMINOR_AUTOSWITCH_DELETE;
				return lvupdate;
			}

			g_Vars.currentplayer->doautoselect = false;

			if (g_Vars.lvupdate240 > 0
					&& g_Vars.currentplayer->cameramode != CAMERAMODE_THIRDPERSON
					&& bgun_is_loaded()
					&& !g_PlayerInvincible
					&& !g_Vars.currentplayer->isdead) {
#if VERSION >= VERSION_NTSC_1_0
				struct sndstate *handle1;
				f32 speed1;
				struct sndstate *handle2;
				OSPri prevpri1;
				f32 speed2;
				OSPri prevpri2;
				struct sndstate *handle3;
				f32 speed3;
				OSPri prevpri3;
#else
				struct sndstate *handle1;
				f32 speed1;
				struct sndstate *handle2;
				f32 speed2;
				struct sndstate *handle3;
				f32 speed3;
#endif

				switch (info->weaponnum) {
				case WEAPON_HORIZONSCANNER:
					speed1 = 3.5f;

#if VERSION >= VERSION_NTSC_1_0
					prevpri1 = osGetThreadPri(0);
					osSetThreadPri(0, osGetThreadPri(&g_AudioManager.thread) + 1);
#endif
					handle1 = snd_start(var80095200, SFX_EQUIP_HORIZONSCANNER, 0, -1, -1, -1, -1, -1);

					if (handle1) {
						audioPostEvent(handle1, AL_SNDP_PITCH_EVT, *(s32 *)&speed1);
					}

#if VERSION >= VERSION_NTSC_1_0
					osSetThreadPri(0, prevpri1);
#endif
					break;
				case WEAPON_LASER:
					snd_start(var80095200, SFX_PICKUP_LASER, 0, -1, -1, -1, -1, -1);
					break;
				case WEAPON_COMBATKNIFE:
					snd_start(var80095200, SFX_PICKUP_KNIFE, 0, -1, -1, -1, -1, -1);
					break;
				case WEAPON_REMOTEMINE:
					if (handnum == HAND_RIGHT) {
						snd_start(var80095200, SFX_PICKUP_MINE, 0, -1, -1, -1, -1, -1);
					}
					break;
				case WEAPON_TIMEDMINE:
				case WEAPON_PROXIMITYMINE:
				case WEAPON_ECMMINE:
				case WEAPON_DATAUPLINK:
				case WEAPON_RTRACKER:
				case WEAPON_PRESIDENTSCANNER:
				case WEAPON_DOORDECODER:
				case WEAPON_AUTOSURGEON:
				case WEAPON_COMMSRIDER:
				case WEAPON_TRACERBUG:
				case WEAPON_TARGETAMPLIFIER:
					snd_start(var80095200, SFX_PICKUP_MINE, 0, -1, -1, -1, -1, -1);
					break;
				case WEAPON_TRANQUILIZER:
				case WEAPON_PSYCHOSISGUN:
					speed2 = 1.5f;

#if VERSION >= VERSION_NTSC_1_0
					prevpri2 = osGetThreadPri(0);
					osSetThreadPri(0, osGetThreadPri(&g_AudioManager.thread) + 1);
#endif

					handle2 = snd_start(var80095200, SFX_PICKUP_GUN, 0, -1, -1, -1, -1, -1);

					if (handle2) {
						audioPostEvent(handle2, AL_SNDP_PITCH_EVT, *(s32 *)&speed2);
					}

#if VERSION >= VERSION_NTSC_1_0
					osSetThreadPri(0, prevpri2);
#endif
					break;
				case WEAPON_REAPER:
					speed3 = 0.85f;

#if VERSION >= VERSION_NTSC_1_0
					prevpri3 = osGetThreadPri(0);
					osSetThreadPri(0, osGetThreadPri(&g_AudioManager.thread) + 1);
#endif

					handle3 = snd_start(var80095200, SFX_PICKUP_GUN, 0, -1, -1, -1, -1, -1);

					if (handle3) {
						audioPostEvent(handle3, AL_SNDP_PITCH_EVT, *(s32 *)&speed3);
					}

#if VERSION >= VERSION_NTSC_1_0
					osSetThreadPri(0, prevpri3);
#endif
					break;
				case WEAPON_NONE:
				case WEAPON_UNARMED:
				case WEAPON_LAPTOPGUN:
				case WEAPON_CROSSBOW:
				case WEAPON_GRENADE:
				case WEAPON_NBOMB:
				case WEAPON_COMBATBOOST:
				case WEAPON_CLOAKINGDEVICE:
				case WEAPON_EXPLOSIVES:
				case WEAPON_SKEDARBOMB:
				case WEAPON_DISGUISE40:
				case WEAPON_DISGUISE41:
				case WEAPON_FLIGHTPLANS:
				case WEAPON_RESEARCHTAPE:
				case WEAPON_BACKUPDISK:
				case WEAPON_KEYCARD45:
				case WEAPON_KEYCARD46:
				case WEAPON_KEYCARD47:
				case WEAPON_KEYCARD48:
				case WEAPON_KEYCARD49:
				case WEAPON_KEYCARD4A:
				case WEAPON_KEYCARD4B:
				case WEAPON_KEYCARD4C:
				case WEAPON_SUITCASE:
				case WEAPON_BRIEFCASE:
				case WEAPON_NECKLACE:
				case WEAPON_BRIEFCASE2:
					// No equip sound
					break;
				default:
					snd_start(var80095200, SFX_PICKUP_GUN, 0, -1, -1, -1, -1, -1);
					break;
				}
			}
		}

		if (hand->count60 >= delay
				|| !gset_get_filenum2(info->weaponnum)
				|| !gset_has_weapon_flag(info->weaponnum, WEAPONFLAG_00000040)
				|| gset_has_weapon_flag(info->weaponnum, WEAPONFLAG_00000080)) {
			hand->mode = HANDMODE_NONE;
			hand->stateminor++; // to HANDSTATEMINOR_CHANGEGUN_EQUIP

			if (gset_has_weapon_flag(hand->gset.weaponnum, WEAPONFLAG_00004000) == 0) {
				hand->unk0cc8_02 = false;
			}

			hand->count60 = 0;
			hand->count = 0;
		} else {
			bgun_set_arm_pitch(hand, (delay - hand->count60) * MAX_PITCH / delay);
		}
	}

	// Wait for equip animation to finish then go to idle state
	if (hand->stateminor == HANDSTATEMINOR_CHANGEGUN_EQUIP) {
		if (info->definition->equip_animation && !gset_has_weapon_flag(hand->gset.weaponnum, WEAPONFLAG_00004000)) {
			if (hand->animmode == HANDANIMMODE_IDLE) {
				if (bgun_set_state(handnum, HANDSTATE_IDLE)) {
					return lvupdate;
				}
			}
		} else {
			if (bgun_set_state(handnum, HANDSTATE_IDLE)) {
				return lvupdate;
			}
		}
	}

	return 0;
}

/**
 * This function may have implemented an early beta feature where the gun could
 * be held at the side of the screen, pointed upwards. The feature was shown in
 * a demo video but doesn't exist in any public version of the game.
 */
s32 bgun_tick_inc_state2(struct handweaponinfo *info, s32 handnum, struct hand *hand, s32 lvupdate)
{
	return 0;
}

s32 bgun_tick_inc(struct handweaponinfo *info, s32 handnum, s32 lvupdate)
{
	s32 result = 0;
	struct hand *hand = &g_Vars.currentplayer->hands[handnum];
	s32 prevstate = hand->state;

	hand->firing = false;
	hand->flashon = false;
	hand->stateframes += lvupdate;

	if (g_Vars.lvupdate240 > 0) {
		hand->count60 += g_Vars.lvupdate60;
		hand->count++;
	}

	hand->useposrot = false;

	switch (hand->state) {
	case HANDSTATE_IDLE:
		result = bgun_tick_inc_idle(info, handnum, hand, lvupdate);
		break;
	case HANDSTATE_RELOAD:
		result = bgun_tick_inc_reload(info, handnum, hand, lvupdate);
		break;
	case HANDSTATE_ATTACK:
		result = bgun_tick_inc_attack(info, handnum, hand, lvupdate);
		break;
	case HANDSTATE_2:
		result = bgun_tick_inc_state2(info, handnum, hand, lvupdate);
		break;
	case HANDSTATE_CHANGEGUN:
		result = bgun_tick_inc_changegun(info, handnum, hand, lvupdate);
		break;
	case HANDSTATE_ATTACKEMPTY:
		result = bgun_tick_inc_attackempty(info, handnum, hand, lvupdate);
		break;
	case HANDSTATE_AUTOSWITCH:
		result = bgun_tick_inc_autoswitch(info, handnum, hand, lvupdate);
		break;
	case HANDSTATE_CHANGEFUNC:
		result = bgun_tick_inc_changefunc(info, handnum, hand, lvupdate);
		break;
	}

	hand->statelastframe = hand->stateframes;

	if (hand->state != prevstate) {
		hand->statelastframe = -result;
	} else {
		hand->stateframes -= result;
		hand->statecycles++;
	}

	return result;
}

bool bgun_set_state(s32 handnum, s32 state)
{
	bool valid = true;
	struct hand *hand = &g_Vars.currentplayer->hands[handnum];

	// Sanity check - don't allow changing function if there is no other
	if (state == HANDSTATE_CHANGEFUNC && gset_get_funcdef_by_gset_funcnum(&hand->gset, 1 - hand->gset.weaponfunc) == NULL) {
		valid = false;
	}

	if (valid) {
		hand->state = state;
		hand->stateframes = 0;
		hand->stateflags = 0;
		hand->statecycles = 0;
		hand->stateminor = 0;
		hand->statelastframe = 0;
	}

	return valid;
}

void bgun_tick_hand(s32 handnum)
{
	struct hand *hand = &g_Vars.currentplayer->hands[handnum];
	struct handweaponinfo info;
	s32 lvupdate;
	s32 i = 20;

	if (handnum);
	if (handnum);
	if (handnum);
	if (handnum);

#if VERSION >= VERSION_PAL_BETA
	if (handnum);
#endif

	bgun_get_weapon_info(&info, handnum);

	lvupdate = g_Vars.lvupdate60;

	hand->animframeinc = g_Vars.lvupdate60;
#if VERSION >= VERSION_PAL_BETA
	hand->animframeincfreal = model_get_abs_anim_speed(&hand->gunmodel) * PALUPF(hand->animframeinc);
#else
	hand->animframeincfreal += PALUPF(g_Vars.lvupdate60);
#endif

	while (i >= 0) {
		lvupdate = bgun_tick_inc(&info, handnum, lvupdate);
		i--;

		if (lvupdate <= 0) {
			break;
		}
	}
}

void bgun_tick_switch(void)
{
	bgun_tick_switch2();
}

void bgun_init_hand_anims(void)
{
	struct hand *hand;
	s32 i;

	for (i = 0; i < 2; i++) {
		if (i == 0) {
			hand = &g_Vars.currentplayer->hands[1];
		} else {
			hand = &g_Vars.currentplayer->hands[0];
		}

		hand->gangstarot = 0;
		hand->state = HANDSTATE_IDLE;
		hand->animload = -1;
		hand->animmode = HANDANIMMODE_IDLE;

		anim_init(&hand->anim);

		hand->gunmodel.anim = &hand->anim;
		hand->handmodel.anim = &hand->anim;
	}
}

f32 bgun_get_noise_radius(s32 handnum)
{
	return g_Vars.currentplayer->hands[handnum].noiseradius;
}

void bgun_decrease_noise_radius(void)
{
	struct player *player = g_Vars.currentplayer;
	f32 consideramount;
	struct gset gsetleft;
	struct gset gsetright;
	struct noisesettings noisesettingsleft;
	struct noisesettings noisesettingsright;
	f32 subamount;

	gset_populate(HAND_LEFT, &gsetleft);
	gset_populate(HAND_RIGHT, &gsetright);

	gset_get_noise_settings(&gsetleft, &noisesettingsleft);
	gset_get_noise_settings(&gsetright, &noisesettingsright);

	// Right hand
	if (bgun_is_firing(HAND_RIGHT)) {
		player->hands[HAND_RIGHT].noiseradius += noisesettingsright.incradius;

		if (player->hands[HAND_RIGHT].noiseradius > noisesettingsright.maxradius) {
			player->hands[HAND_RIGHT].noiseradius = noisesettingsright.maxradius;
		}
	}

	subamount = g_Vars.lvupdate60freal * noisesettingsright.incradius / (noisesettingsright.decbasespeed * 60.0f);
	consideramount = (player->hands[HAND_RIGHT].noiseradius - noisesettingsright.minradius) * g_Vars.lvupdate60freal / (noisesettingsright.decremspeed * 60.0f);

	if (consideramount > subamount) {
		subamount = consideramount;
	}

	player->hands[HAND_RIGHT].noiseradius -= subamount;

	if (player->hands[HAND_RIGHT].noiseradius < noisesettingsright.minradius) {
		player->hands[HAND_RIGHT].noiseradius = noisesettingsright.minradius;
	}

	// Left hand
	if (bgun_is_firing(HAND_LEFT)) {
		player->hands[HAND_LEFT].noiseradius += noisesettingsleft.incradius;

		if (player->hands[HAND_LEFT].noiseradius > noisesettingsleft.maxradius) {
			player->hands[HAND_LEFT].noiseradius = noisesettingsleft.maxradius;
		}
	}

	subamount = g_Vars.lvupdate60freal * noisesettingsleft.incradius / (noisesettingsleft.decbasespeed * 60.0f);
	consideramount = (player->hands[HAND_LEFT].noiseradius - noisesettingsleft.minradius) * g_Vars.lvupdate60freal / (noisesettingsleft.decremspeed * 60.0f);

	if (consideramount > subamount) {
		subamount = consideramount;
	}

	player->hands[HAND_LEFT].noiseradius -= subamount;

	if (player->hands[HAND_LEFT].noiseradius < noisesettingsleft.minradius) {
		player->hands[HAND_LEFT].noiseradius = noisesettingsleft.minradius;
	}
}

void bgun_calculate_blend(s32 handnum)
{
	s32 sp60[2];
	s32 sp58[2];
	struct weapondef *weapon = gset_get_weapondef(bgun_get_weapon_num(handnum));
	f32 sway = weapon->sway;
	struct player *player = g_Vars.currentplayer;

	sp60[handnum] = (player->hands[handnum].curblendpos + 2) % 4;
	sp58[handnum] = (player->hands[handnum].curblendpos + 1) % 4;
	player->hands[handnum].curblendpos = sp58[handnum];

	player->hands[handnum].blendlook[sp60[handnum]].x = (RANDOMFRAC() - 0.5f) * 0.08f * sway;
	player->hands[handnum].blendlook[sp60[handnum]].y = (RANDOMFRAC() - 0.5f) * 0.1f * sway;
	player->hands[handnum].blendlook[sp60[handnum]].z = -1;

	player->hands[handnum].blendup[sp60[handnum]].x = (RANDOMFRAC() - 0.5f) * 0.1f * sway;
	player->hands[handnum].blendup[sp60[handnum]].y = 1;
	player->hands[handnum].blendup[sp60[handnum]].z = (RANDOMFRAC() - 0.5f) * 0.1f * sway;

	player->hands[handnum].blendpos[sp60[handnum]].x = (RANDOMFRAC() * 0.75f) + 1.5f;
	player->hands[handnum].blendpos[sp60[handnum]].y = (2 + RANDOMFRAC()) * player->hands[handnum].blendscale1;
	player->hands[handnum].blendpos[sp60[handnum]].z = (RANDOMFRAC() - 0.5f) * 2.5f;

	if (player->hands[handnum].sideflag < 0) {
		player->hands[handnum].blendpos[sp60[handnum]].x *= -1;

		if (player->hands[handnum].sideflag == -2) {
			player->hands[handnum].sideflag = 1;
		} else {
			player->hands[handnum].sideflag = -2;
		}
	} else {
		if (player->hands[handnum].sideflag == 2) {
			player->hands[handnum].sideflag = -1;
		} else {
			player->hands[handnum].sideflag = 2;
		}
	}

	player->hands[handnum].blendscale1 = -player->hands[handnum].blendscale1;
}

void bgun_update_blend(struct hand *hand, s32 handnum)
{
	u32 stack[3];
	s32 i;
	struct coord sp5c = {0, 0, 0};
	struct coord sp50 = {0, 0, -1};
	struct coord sp44 = {0, 1, 0};
	s32 pos = hand->curblendpos;
	struct player *player = g_Vars.currentplayer;

	func0f096b70(&hand->blendpos[(pos + 3) % 4], &hand->blendpos[pos], &hand->blendpos[(pos + 1) % 4], &hand->blendpos[(pos + 2) % 4], hand->dampt, &sp5c);
	func0f096b70(&hand->blendlook[(pos + 3) % 4], &hand->blendlook[pos], &hand->blendlook[(pos + 1) % 4], &hand->blendlook[(pos + 2) % 4], hand->dampt, &sp50);
	func0f096b70(&hand->blendup[(pos + 3) % 4], &hand->blendup[pos], &hand->blendup[(pos + 1) % 4], &hand->blendup[(pos + 2) % 4], hand->dampt, &sp44);

	sp5c.x *= player->gunposamplitude;
	sp5c.y *= player->gunposamplitude;
	sp5c.z *= player->gunposamplitude;

	sp5c.x += hand->adjustdamp.x;
	sp5c.y += hand->adjustdamp.y;

	sp5c.x += gset_get_xshift(handnum);

	for (i = 0; i < g_Vars.lvupdate240; i++) {
		hand->damppossum.x = (PAL ? 0.9847f : 0.9872f) * hand->damppossum.x + sp5c.f[0];
		hand->damppossum.y = (PAL ? 0.9847f : 0.9872f) * hand->damppossum.y + sp5c.f[1];
		hand->damppossum.z = (PAL ? 0.9847f : 0.9872f) * hand->damppossum.z + sp5c.f[2];

		hand->damplooksum.x = (PAL ? 0.9847f : 0.9872f) * hand->damplooksum.x + sp50.f[0];
		hand->damplooksum.y = (PAL ? 0.9847f : 0.9872f) * hand->damplooksum.y + sp50.f[1];
		hand->damplooksum.z = (PAL ? 0.9847f : 0.9872f) * hand->damplooksum.z + sp50.f[2];

		hand->dampupsum.x = (PAL ? 0.9847f : 0.9872f) * hand->dampupsum.x + sp44.f[0];
		hand->dampupsum.y = (PAL ? 0.9847f : 0.9872f) * hand->dampupsum.y + sp44.f[1];
		hand->dampupsum.z = (PAL ? 0.9847f : 0.9872f) * hand->dampupsum.z + sp44.f[2];
	}

	hand->damppos.x = hand->damppossum.x * (PAL ? 0.01529997587204f : 0.012799978f) * 2;
	hand->damppos.y = hand->damppossum.y * (PAL ? 0.01529997587204f : 0.012799978f) * 2;
	hand->damppos.z = hand->damppossum.z * (PAL ? 0.01529997587204f : 0.012799978f) * 2;

	hand->damplook.x = hand->damplooksum.x * (PAL ? 0.01529997587204f : 0.012799978f);
	hand->damplook.y = hand->damplooksum.y * (PAL ? 0.01529997587204f : 0.012799978f);
	hand->damplook.z = hand->damplooksum.z * (PAL ? 0.01529997587204f : 0.012799978f);

	hand->dampup.x = hand->dampupsum.x * (PAL ? 0.01529997587204f : 0.012799978f);
	hand->dampup.y = hand->dampupsum.y * (PAL ? 0.01529997587204f : 0.012799978f);
	hand->dampup.z = hand->dampupsum.z * (PAL ? 0.01529997587204f : 0.012799978f);
}

u32 var80070158 = 0x04e50764;
u32 var8007015c = 0x05360529;
u32 var80070160 = 0x0531052a;
u32 var80070164 = 0x052b052c;
u32 var80070168 = 0x052c052d;
u32 var8007016c = 0x052b052b;
u32 var80070170 = 0x052e052f;
u32 var80070174 = 0x052f0530;
u32 var80070178 = 0x05310532;
u32 var8007017c = 0x05320533;
u32 var80070180 = 0x05340535;
u32 var80070184 = 0x05360537;
u32 var80070188 = 0x05380530;
u32 var8007018c = 0x0539053a;
u32 var80070190 = 0x0532053b;
u32 var80070194 = 0x05310766;
u32 var80070198 = 0x07670768;
u32 var8007019c = 0x0769076a;
u32 var800701a0 = 0x076b076c;
u32 var800701a4 = 0x076d0000;
u32 var800701a8 = 0x0000ffff;

void bgun0f09d8dc(f32 breathing, f32 arg1, f32 arg2, f32 arg3, f32 arg4)
{
	f32 dampt[2];
	struct player *player = g_Vars.currentplayer;
	u32 stack;
	s32 i;
	f32 sp50 = arg2;
	f32 sp4c;
	u32 stack2;

	if (sp50 < 0.0f) {
		sp50 = -sp50;
	}

	if (arg1 > 0.8f) {
		player->gunposamplitude = 1.0f;
	} else {
		if (arg1 > 0.1f) {
			f32 tmp = 1.0f - cosf((arg1 - 0.1f) * BADDTOR(360) / 2.8f);
			player->gunposamplitude = 0.8f * tmp + 0.2f;
		} else {
			player->gunposamplitude = 0.1f;
		}
	}

	if (bmove_get_crouch_pos() != CROUCHPOS_SQUAT) {
		if (player->gunposamplitude < 0.3f * g_Vars.currentplayer->bondbreathing) {
			player->gunposamplitude = 0.3f * g_Vars.currentplayer->bondbreathing;
		}
	}

	if (player->gunposamplitude < 0.5f * sp50) {
		player->gunposamplitude = 0.5f * sp50;
	}

	for (i = 0; i < g_Vars.lvupdate240; i++) {
		player->gunampsum = (PAL ? 0.9847f : 0.9872f) * player->gunampsum + player->gunposamplitude;
	}

	player->gunposamplitude = (PAL ? 0.01529997587204f : 0.012799978256226f) * player->gunampsum;

	if (breathing < (1.0f / 60.0f) * sp50) {
		breathing = (1.0f / 60.0f) * sp50;
	}

	for (i = 0; i < g_Vars.lvupdate240; i++) {
		player->cyclesum = (PAL ? 0.9847f : 0.9872f) * player->cyclesum + breathing;
	}

	breathing = player->cyclesum * (PAL ? 0.01529997587204f : 0.012799978256226f);
	sp4c = breathing * g_Vars.lvupdate60freal;
	dampt[0] = player->hands[0].dampt + sp4c;

	while (dampt[0] >= 1.0f) {
		bgun_calculate_blend(HAND_RIGHT);
		dampt[0] -= 1.0f;
		player->syncoffset++;
	}

	player->synccount += g_Vars.lvupdate60freal;

	if (player->synccount > 60.0f) {
		player->synccount = 0.0f;
		player->syncchange = (RANDOMFRAC() - 0.5f) * 0.2f / 60.0f;
	}

	if (player->syncchange + sp4c > 0.0f) {
		player->gunsync += player->syncchange;
	}

	if (player->gunsync > 0.5f) {
		player->gunsync = 0.5f;
	} else if (player->gunsync < -0.5f) {
		player->gunsync = -0.5f;
	} else if (player->gunsync < 0.1f && player->gunsync > -0.1f) {
		if (player->gunsync > 0.0f) {
			player->gunsync = -0.1f;
		} else {
			player->gunsync = 0.1f;
		}
	}

	dampt[1] = dampt[0] + player->syncoffset + player->gunsync;

	while (dampt[1] >= 1.0f) {
		bgun_calculate_blend(HAND_LEFT);
		dampt[1] -= 1.0f;
		player->syncoffset--;
	}

	for (i = 0; i < 2; i++) {
		player->hands[i].dampt = dampt[i];
		player->hands[i].adjustdamp.x = -1.75f * arg3 + -0.8f * arg4;
		player->hands[i].adjustdamp.y = -2.0f * arg2;
	}
}

bool bgun_is_loaded(void)
{
	if (g_Vars.currentplayer->gunctrl.gunmemowner != GUNMEMOWNER_BONDGUN) {
		return false;
	}

	return g_Vars.currentplayer->gunctrl.gunmemtype == WEAPON_NONE
		|| (g_Vars.currentplayer->gunctrl.gunmemnew < 0
				&& g_Vars.currentplayer->gunctrl.masterloadstate == MASTERLOADSTATE_LOADED);
}

u32 bgun_get_gun_mem_type(void)
{
	return g_Vars.currentplayer->gunctrl.gunmemtype;
}

struct modeldef *bgun_get_gun_modeldef(void)
{
	return g_Vars.currentplayer->gunctrl.gunmodeldef;
}

u8 *bgun_get_gun_mem(void)
{
	return g_Vars.currentplayer->gunctrl.gunmem;
}

u32 bgun_calculate_gun_mem_capacity(void)
{
	if (IS4MB() && PLAYERCOUNT() == 2) {
		return g_BgunGunMemBaseSize4Mb2P;
	}

	if (PLAYERCOUNT() == 1) {
		switch (g_Vars.stagenum) {
		case STAGE_CHICAGO:
		case STAGE_AIRBASE:
		case STAGE_VILLA:
		case STAGE_AIRFORCEONE:
		case STAGE_ATTACKSHIP:
			 return g_BgunGunMemBaseSizeDefault + 25 * 1024;
		}
	}

	return g_BgunGunMemBaseSizeDefault;
}

void bgun_free_gun_mem(void)
{
	g_Vars.currentplayer->gunctrl.gunmemowner = GUNMEMOWNER_FREE;
}

void bgun_set_gun_mem_weapon(s32 weaponnum)
{
	struct player *player = g_Vars.currentplayer;

	if (player->gunctrl.gunmemowner == GUNMEMOWNER_BONDGUN) {
		player->gunctrl.masterloadstate = MASTERLOADSTATE_FLUX;
		player->gunctrl.gunloadstate = GUNLOADSTATE_FLUX;
		player->gunctrl.gunmemnew = weaponnum;
		player->gunctrl.gunlocktimer = -1;
	} else {
		player->gunctrl.gunmemnew = weaponnum;
	}
}

void bgun_enter_flux(void)
{
	s32 i;
	struct casing *end;
	struct casing *casing;

	g_Vars.currentplayer->gunctrl.handfilenum = 0xffff;
	g_Vars.currentplayer->gunctrl.handmodeldef = NULL;
	g_Vars.currentplayer->gunctrl.handmemloadptr = 0;
	g_Vars.currentplayer->gunctrl.handmemloadremaining = 0;
	g_Vars.currentplayer->gunctrl.masterloadstate = MASTERLOADSTATE_FLUX;
	g_Vars.currentplayer->gunctrl.gunloadstate = GUNLOADSTATE_FLUX;

	end = g_Casings + ARRAYCOUNT(g_Casings);
	casing = g_Casings;

	while (casing < end) {
		casing->modeldef = NULL;
		casing++;
	}

	g_CasingsActive = false;
}

bool bgun_change_gun_mem(s32 newowner)
{
	struct player *player = g_Vars.currentplayer;

	if (player->gunctrl.gunmemowner == newowner) {
		return true;
	}

	if (player->gunctrl.gunlocktimer < 0) {
		player->gunctrl.gunlocktimer--;

		if (player->gunctrl.gunlocktimer < -2) {
			player->gunctrl.gunlocktimer = 0;
			player->gunctrl.gunmemowner = newowner;
			return true;
		}
	} else {
		bool unlock = false;

		switch (player->gunctrl.gunmemowner) {
		case GUNMEMOWNER_BONDGUN:
			if (player->gunctrl.gunmemtype != -1) {
				player->gunctrl.gunmemnew = player->gunctrl.gunmemtype;
			}

			player->gunctrl.gunmemtype = -1;
			bgun_enter_flux();
			player->gunctrl.loadall = true;
			unlock = true;
			break;
		case GUNMEMOWNER_CHRBODY:
			if (g_Vars.mplayerisrunning) {
				unlock = true;
			}

			if (!player->haschrbody) {
				unlock = true;
			}

			if (newowner == GUNMEMOWNER_INVMENU && var8009dfc0 != 0) {
				unlock = true;
				player_remove_chr_body();
			}
			break;
		case GUNMEMOWNER_3:
			unlock = true;
			break;
		case GUNMEMOWNER_CHANGING:
		case GUNMEMOWNER_FREE:
			unlock = true;
			break;
		}

		if (unlock) {
			player->gunctrl.gunlocktimer = -1;
			player->gunctrl.gunmemowner = GUNMEMOWNER_CHANGING;
		}
	}

	return false;
}

/**
 * This function loads resources for a gun change.
 *
 * The caller sets properties in the player's gunctrl struct which tell this
 * function what to load, where the gunmem is that it can use, and how much
 * gunmem there is. This function is then called a couple of times on subsequent
 * ticks, loading data incrementally to avoid a significant lag spike.
 *
 * The function keeps track of its progress in the gunloadstate property, and
 * updates the gunmem properties to reflect its usage.
 *
 * The first call loads the model definition from the ROM and decompresses it.
 * The second call loads and decompress to 3 textures.
 * This continues on further calls until all textures are loaded.
 * The final call does some one-off processing on the model's display lists.
 *
 * Although the name contains "Gun", it's used for more than just the gun model.
 * It's used for the hand model, the gun model and the cartridge model.
 */
void bgun_tick_gun_load(void)
{
	s32 i;
	s32 numthistick;
	u32 remaining;
	s32 padding;
	u32 allocsize;
	u32 loadsize;
	u32 ptr;
	struct player *player = g_Vars.currentplayer;
	struct modeldef *modeldef;
	struct fileinfo *fileinfo;
	struct fileinfo *gunfileinfo;
	s32 newvalue;
	u32 end;
	u32 stack;
#if VERSION >= VERSION_NTSC_1_0
	u32 stack2;
#endif

	if (player->gunctrl.gunloadstate == GUNLOADSTATE_MODEL) {
		osSyncPrintf("BriGun:  BriGunLoadTick process GUN_LOADSTATE_LOAD_OBJ\n");

		ptr = *player->gunctrl.loadmemptr;
		remaining = *player->gunctrl.loadmemremaining;

		// Align ptr to the next 16 byte boundary
		if (ptr % 16) {
			padding = 16 - (ptr % 16);
			ptr += padding;
			remaining -= padding;
		}

		*player->gunctrl.loadmemptr = ptr;
		*player->gunctrl.loadmemremaining = remaining;

		loadsize = ALIGN64(file_get_inflated_size(player->gunctrl.loadfilenum)) + 0x8000;

		osSyncPrintf("BriGun:  Loading - %s, pMem 0x%08x Size %d\n");

		if (loadsize > remaining) {
			osSyncPrintf("BriGun:  Warning: LoadSize > MemSize, clamping decomp. buffer from %d to %d (%d Bytes)\n", allocsize, remaining, remaining);
			loadsize = remaining;
		}

		// Load the model file to ptr
		g_LoadType = LOADTYPE_GUN;

		osSyncPrintf("BriGun:  obLoadto at 0x%08x, size %d\n", ptr, loadsize);

		modeldef = file_load_to_addr(player->gunctrl.loadfilenum, FILELOADMETHOD_EXTRAMEM, (u8 *)ptr, loadsize);

		// Reserve some space for textures
		allocsize = file_get_loaded_size(player->gunctrl.loadfilenum) + 0xe00;

		osSyncPrintf("BriGun:  Used size %d (Ob Size %d)\n");
		osSyncPrintf("BriGun:  block len %d usedsize %d\n");
		osSyncPrintf("BriGun:  obln ram_len %d block_len %d\n");
		osSyncPrintf("BriGun:  new used size %d\n");

		file_get_loaded_size(player->gunctrl.loadfilenum);

		fileinfo = &g_FileInfo[player->gunctrl.loadfilenum];
		fileinfo->allocsize = allocsize;
		end = ALIGN16((s32)ptr + allocsize);
		allocsize = end - ptr;
		if (1);
		remaining -= allocsize;

		osSyncPrintf("BriGun:  Texture Block at 0x%08x size %d, endp 0x%08x\n");

		tex_init_pool(&player->gunctrl.texpool, (u8 *)end, remaining);

		// Tidy up the model
		model_promote_type_to_pointer(modeldef);
		model_promote_offsets_to_pointers(modeldef, 0x05000000, (uintptr_t)modeldef);

		*player->gunctrl.loadtomodeldef = modeldef;

		player->gunctrl.nexttexturetoload = 0;
		player->gunctrl.fileinfo = *fileinfo;

		osSyncPrintf("BriGun:  Set Load State: GUN_LOADSTATE_DECOMPRESS_TEXTURES\n");
		player->gunctrl.gunloadstate = GUNLOADSTATE_TEXTURES;
		return;
	}

	if (player->gunctrl.gunloadstate == GUNLOADSTATE_TEXTURES) {
		osSyncPrintf("BriGun:  BriGunLoadTick process GUN_LOADSTATE_DECOMPRESS_TEXTURES\n");

		gunfileinfo = &player->gunctrl.fileinfo;
		fileinfo = &g_FileInfo[player->gunctrl.loadfilenum];
		*fileinfo = *gunfileinfo;
		modeldef = *player->gunctrl.loadtomodeldef;

		// Load textures - up to 3 per call
		numthistick = 0;

		for (i = player->gunctrl.nexttexturetoload; i < modeldef->numtexconfigs; i++) {
			osSyncPrintf("BriGun:  at texture %d\n", i);

			if (modeldef->texconfigs[i].texturenum < NUM_TEXTURES) {
				osSyncPrintf("BriGun:  Uncompress %d of %d\n", i, modeldef->numtexconfigs);
				tex_load(&modeldef->texconfigs[i].texturenum, &player->gunctrl.texpool, true);
				modeldef->texconfigs[i].unk0b = 1;
			}

			numthistick++;

			if (numthistick == 3) {
				return;
			}

			// @bug: This should be incremented prior to the return, otherwise
			// subsequent ticks will waste time loading a texture that's already
			// been loaded.
			player->gunctrl.nexttexturetoload++;
		}

		*gunfileinfo = *fileinfo;

		osSyncPrintf("BriGun:  Set Load State: GUN_LOADSTATE_DECOMPRESS_DLS\n");
		player->gunctrl.gunloadstate = GUNLOADSTATE_DLS;
		return;
	}

	if (player->gunctrl.gunloadstate == GUNLOADSTATE_DLS) {
		osSyncPrintf("BriGun:  BriGunLoadTick process GUN_LOADSTATE_DECOMPRESS_DLS\n");

		fileinfo = &g_FileInfo[player->gunctrl.loadfilenum];
		*fileinfo = player->gunctrl.fileinfo;
		modeldef = *player->gunctrl.loadtomodeldef;

		modeldef0f1a7560(modeldef, player->gunctrl.loadfilenum, 0x05000000, modeldef, &player->gunctrl.texpool, false);

		file_get_inflated_size(player->gunctrl.loadfilenum);
		file_get_loaded_size(player->gunctrl.loadfilenum);
		file_get_loaded_size(player->gunctrl.loadfilenum);
		file_get_loaded_size(player->gunctrl.loadfilenum);

		model_allocate_rw_data(modeldef);

		osSyncPrintf("BriGun:  propgfx_decompress 0x%08x\n");
		osSyncPrintf("BriGun:  DL waste space %d from %d (Used %d, Ramlen %d, ObSize %d)\n");
		osSyncPrintf("Increase GUNSAVESIZE to %d!!!\n");

		newvalue = ALIGN64(tex_get_pool_left_pos(&player->gunctrl.texpool));
		remaining = *player->gunctrl.loadmemremaining;
		remaining -= (s32)(newvalue - *player->gunctrl.loadmemptr);

		*player->gunctrl.loadmemptr = newvalue;
		*player->gunctrl.loadmemremaining = remaining;

		osSyncPrintf("BriGun:  Set Load State: GUN_LOADSTATE_LOADED\n");
		player->gunctrl.gunloadstate = GUNLOADSTATE_LOADED;

#if PIRACYCHECKS
		{
			s32 *ptr = (s32 *)&tags_reset;
			s32 *end = (s32 *)&tag_find_by_id;
			u32 checksum = 0;

			while (ptr < end) {
				checksum -= ~*ptr;
				ptr++;
			}

			if (checksum != CHECKSUM_PLACEHOLDER) {
				ptr = (s32 *)&tags_reset + 3;

				if (1);
				end = &ptr[7];

				while (ptr < end) {
					*ptr |= 0xff;
					ptr++;
				}
			}
		}
#endif
	}
}

const char var7f1abcd8[] = "need a new gun loading (lock %d gunmemnew %d)\n";
const char var7f1abd08[] = "loading gun file: %d type: %d\n";
const char var7f1abd28[] = "BriGun: Process MASTER_GUN_LOADSTATE_FLUX\n";
const char var7f1abd54[] = "BriGun: Set Master State: MASTER_GUN_LOADSTATE_HANDS\n";
const char var7f1abd8c[] = "BriGun: Process MASTER_GUN_LOADSTATE_HANDS\n";
const char var7f1abdb8[] = "BriGun: Setup Hand Load\n";
const char var7f1abdd4[] = "Hand  : Using cached hands\n";
const char var7f1abdf0[] = "Hand  : Look ma no hands!\n";
const char var7f1abe0c[] = "BriGun: Set Master State: MASTER_GUN_LOADSTATE_GUN\n";
const char var7f1abe40[] = "BriGun: Process MASTER_GUN_LOADSTATE_GUN\n";
const char var7f1abe6c[] = "BriGun: Setup Gun Load\n";
const char var7f1abe84[] = "BriGun: Set Master State: MASTER_GUN_LOADSTATE_CARTS\n";
const char var7f1abebc[] = "BriGun: Process MASTER_GUN_LOADSTATE_CARTS\n";
const char var7f1abee8[] = "BriGun: Cart Loaded setting GUN_LOADSTATE_FLUX\n";
const char var7f1abf18[] = "BriGun: Cart loading - looking for carts\n";
const char var7f1abf44[] = "BriGun: Loading cart %d\n";
const char var7f1abf60[] = "BriGun: Request for cart %d ignored - cart already loaded\n";
const char var7f1abf9c[] = "BriGun: Compile Hand 0x%08x Gun 0x%0x8\n";
const char var7f1abfc4[] = "Gun   : Compiled Gun 0x%08x\n";
const char var7f1abfe4[] = "Gun   : Compiled Size %d\n";
const char var7f1ac000[] = "Hand  : Compiled Hand 0x%08x\n";
const char var7f1ac020[] = "Hand  : Compiled Size %d\n";
const char var7f1ac03c[] = "Gun   : Compile overhead %d bytes\n";
const char var7f1ac060[] = "Hand  : Hand Obj 0x%08x Gun Obj 0x%08x \n";
const char var7f1ac08c[] = "Gun   : After Comp : Base 0x%08x Free %d\n";
const char var7f1ac0b8[] = "Gun   : After Cached Setup : Base 0x%08x Free %d\n";
const char var7f1ac0ec[] = "Gun   : TotalUsed %d, Free %d\n";
const char var7f1ac10c[] = "BriGun: Set Master State: MASTER_GUN_LOADSTATE_LOADED\n";
const char var7f1ac144[] = "GunLockTimer: %d\n";

void bgun_tick_master_load(void)
{
	s32 newweaponnum;
	struct player *player = g_Vars.currentplayer;
	bool hashands;
	u16 handfilenum;
	s32 sum;
	u16 filenum;
	s32 i;
	struct casing *casing;
	struct hand *hand;
	struct funcdef *func;
	struct funcdef *shootfunc;
	struct weapondef *weapondef;
	s32 casingindex;
	struct ammodef *ammodef;
	s32 value;
	s32 bodynum;
	s32 headnum;

	if ((player->gunctrl.gunmemowner == GUNMEMOWNER_BONDGUN || bgun_change_gun_mem(GUNMEMOWNER_BONDGUN)) && player->gunctrl.gunmemnew >= 0) {
		if (player->gunctrl.gunlocktimer == 0) {
			newweaponnum = player->gunctrl.gunmemnew;

			player_choose_body_and_head(&bodynum, &headnum, NULL);

			handfilenum = g_HeadsAndBodies[bodynum].handfilenum;

			if (IS4MB()) {
				handfilenum = FILE_GCOMBATHANDSLOD;
			}

			filenum = gset_get_filenum(newweaponnum);

			if (player->gunctrl.masterloadstate != MASTERLOADSTATE_LOADED || newweaponnum != player->gunctrl.gunmemtype) {
				if (filenum) {
					hashands = false;

					if (gset_has_weapon_flag(newweaponnum, WEAPONFLAG_HASHANDS)) {
						hashands = true;
					}

					if (newweaponnum == WEAPON_UNARMED) {
						// For unarmed, the fists are implemented
						// as weapon models rather than hand models
						filenum = handfilenum;
						handfilenum = 0 * (player->gunctrl.gunloadstate == 4);
						hashands = false;
					}

					if (player->gunctrl.masterloadstate == MASTERLOADSTATE_FLUX) {
						casing = g_Casings;

						while (casing < &g_Casings[ARRAYCOUNT(g_Casings)]) {
							if (casing->modeldef == player->gunctrl.cartmodeldef) {
								casing->modeldef = NULL;
							}

							casing++;
						}

						g_CasingsActive = false;

						casing = g_Casings;

						while (casing < &g_Casings[ARRAYCOUNT(g_Casings)]) {
							if (casing->modeldef != NULL) {
								g_CasingsActive = true;
							}

							casing++;
						}

						player->gunctrl.cartmodeldef = NULL;
						player->gunctrl.masterloadstate = MASTERLOADSTATE_HANDS;
					} else if (player->gunctrl.masterloadstate == MASTERLOADSTATE_HANDS) {
						if (hashands) {
							if (handfilenum != player->gunctrl.handfilenum) {
								if (player->gunctrl.gunloadstate == GUNLOADSTATE_FLUX) {
									player->gunctrl.handmemloadptr = bgun_get_gun_mem();
									player->gunctrl.handmemloadremaining = bgun_calculate_gun_mem_capacity();
									player->gunctrl.gunloadstate = GUNLOADSTATE_MODEL;
									player->gunctrl.loadfilenum = handfilenum;
									player->gunctrl.loadtomodeldef = &player->gunctrl.handmodeldef;
									player->gunctrl.loadmemptr = (u32 *) &player->gunctrl.handmemloadptr;
									player->gunctrl.loadmemremaining = (u32 *) &player->gunctrl.handmemloadremaining;
								}

								bgun_tick_gun_load();

								if (player->gunctrl.gunloadstate == GUNLOADSTATE_LOADED) {
									player->gunctrl.handfilenum = handfilenum;
								} else {
									return;
								}
							}
						} else {
							player->gunctrl.handfilenum = 0;
							player->gunctrl.handmodeldef = NULL;
							player->gunctrl.handmemloadptr = bgun_get_gun_mem();
							player->gunctrl.handmemloadremaining = bgun_calculate_gun_mem_capacity();
						}

						player->gunctrl.masterloadstate = MASTERLOADSTATE_GUN;
						player->gunctrl.gunloadstate = GUNLOADSTATE_FLUX;
					} else if (player->gunctrl.masterloadstate == MASTERLOADSTATE_GUN) {
						if (player->gunctrl.gunloadstate == GUNLOADSTATE_FLUX) {
							player->gunctrl.memloadptr = (u8 *) player->gunctrl.handmemloadptr;
							player->gunctrl.memloadremaining = player->gunctrl.handmemloadremaining;
							player->gunctrl.gunloadstate = GUNLOADSTATE_MODEL;
							player->gunctrl.loadfilenum = filenum;
							player->gunctrl.loadtomodeldef = &player->gunctrl.gunmodeldef;
							player->gunctrl.loadmemptr = (u32 *) &player->gunctrl.memloadptr;
							player->gunctrl.loadmemremaining = (u32 *) &player->gunctrl.memloadremaining;
						}

						bgun_tick_gun_load();

						if (player->gunctrl.gunloadstate == GUNLOADSTATE_LOADED) {
							player->gunctrl.masterloadstate = MASTERLOADSTATE_CARTS;
							player->gunctrl.gunloadstate = GUNLOADSTATE_FLUX;
						}
					} else if (player->gunctrl.masterloadstate == MASTERLOADSTATE_CARTS) {
						if (player->gunctrl.gunloadstate == GUNLOADSTATE_LOADED) {
							player->gunctrl.gunloadstate = GUNLOADSTATE_FLUX;
						}

						if (player->gunctrl.gunloadstate == GUNLOADSTATE_FLUX && player->gunctrl.cartmodeldef == NULL && PLAYERCOUNT() == 1) {
							for (i = 0; i < 2; i++) {
								hand = player->hands + i;
								func = gset_get_funcdef_by_gset2(&hand->gset);
								shootfunc = NULL;
								weapondef = gset_get_weapondef(player->gunctrl.weaponnum);
								casingindex = -1;

								if (func != NULL) {
									if ((func->type & 0xff) == INVENTORYFUNCTYPE_SHOOT) {
										shootfunc = func;
									}

									if (weapondef && shootfunc) {
										ammodef = func->ammoindex >= 0 ? weapondef->ammos[func->ammoindex] : NULL;

										if (ammodef) {
											casingindex = ammodef->casingeject;
										}
									}

									if (casingindex >= 0) {
										if (player->gunctrl.cartmodeldef == NULL) {
											filenum = g_CartFileNums[casingindex];
											player->gunctrl.loadfilenum = filenum;
											player->gunctrl.gunloadstate = GUNLOADSTATE_MODEL;
											player->gunctrl.loadtomodeldef = &player->gunctrl.cartmodeldef;
											player->gunctrl.loadmemptr = (u32 *) &player->gunctrl.memloadptr;
											player->gunctrl.loadmemremaining = (u32 *) &player->gunctrl.memloadremaining;
											break;
										}

										break;
									}
								}
							}
						}

						if (player->gunctrl.gunloadstate != GUNLOADSTATE_FLUX) {
							bgun_tick_gun_load();
							return;
						}

						sum = 0;

						for (i = 0; i < 2; i++) {
							hand = &player->hands[i];

							model_init(&hand->gunmodel, player->gunctrl.gunmodeldef, hand->unk0a6c, 0);

							if (player->gunctrl.handmodeldef != 0) {
								model_init(&hand->handmodel, player->gunctrl.handmodeldef, hand->handsavedata, false);
							}

							hand->compiledgunmodelcmds = (s32 *) player->gunctrl.memloadptr;

							value = bgun_create_model_cmd_list(&hand->gunmodel, player->gunctrl.gunmodeldef->rootnode, (s32 *) player->gunctrl.memloadptr);

							sum += value;
							player->gunctrl.memloadptr += value;
							player->gunctrl.memloadremaining -= value;

							if (player->gunctrl.handmodeldef != 0) {
								hand->compiledhandmodelcmds = (s32 *) player->gunctrl.memloadptr;

								value = bgun_create_model_cmd_list(&hand->handmodel, player->gunctrl.handmodeldef->rootnode, (s32 *) player->gunctrl.memloadptr);

								sum += value;
								player->gunctrl.memloadptr += value;
								player->gunctrl.memloadremaining -= value;
							}
						}

						hand = &player->hands[0];
						hand->unk0dd4 = -1;

						if (player->gunctrl.memloadremaining > 50 * sizeof(Mtxf)) {
							hand->unk0dd8 = (Mtxf *) player->gunctrl.memloadptr;
							player->gunctrl.memloadptr += 50 * sizeof(Mtxf);
							player->gunctrl.memloadremaining -= 50 * sizeof(Mtxf);
						} else {
							hand->unk0dd8 = NULL;
						}

						bgun_calculate_gun_mem_capacity();

						player->gunctrl.masterloadstate = MASTERLOADSTATE_LOADED;
						player->gunctrl.gunmemtype = newweaponnum;
						player->gunctrl.gunmemnew = -1;
					}
				}
#if VERSION >= VERSION_NTSC_1_0
				else {
					player->gunctrl.masterloadstate = MASTERLOADSTATE_LOADED;
					player->gunctrl.gunmemtype = newweaponnum;
					player->gunctrl.gunmemnew = -1;
				}
#endif
			}
		} else {
			player->gunctrl.gunlocktimer--;

			if (player->gunctrl.gunlocktimer < -2) {
				player->gunctrl.gunlocktimer = 0;
			}
		}
	}
}

void bgun_tick_load(void)
{
	s32 i;

	for (i = 0; i < g_Vars.lvupdate240; i += 8) {
		bgun_tick_master_load();
	}
}

/**
 * Load all gun data (models, hands etc) again after returning from a different
 * gunmem type. For example, after returning from a cutscene, pause menu or from
 * controlling the eyespy.
 *
 * Gun data is typically loaded over several frames when switching, but that
 * cannot happen here as the gun must be available for the next frame.
 *
 * If the previous gun mem owner cannot release its memory right now,
 * lockscreen will be set. This causes the game to repaint the previous frame.
 *
 * Return false on success, or true if the load all should be retried on the
 * next frame.
 */
bool bgun_load_all(void)
{
	// PAL adds a check for the eyespy being used
#if VERSION >= VERSION_PAL_BETA
	if ((g_Vars.currentplayer->devicesactive & ~g_Vars.currentplayer->devicesinhibit & DEVICE_EYESPY)) {
		g_Vars.currentplayer->gunctrl.loadall = false;
		return false;
	}
#endif

	bgun_enter_flux();

	if (g_Vars.currentplayer->gunctrl.weaponnum != WEAPON_NONE) {
		g_Vars.currentplayer->gunctrl.gunmemnew = g_Vars.currentplayer->gunctrl.weaponnum;
	} else {
		return false;
	}

	if (g_Vars.currentplayer->gunctrl.gunmemtype != -1) {
		return false;
	}

	if (g_Vars.currentplayer->gunctrl.gunmemowner != GUNMEMOWNER_BONDGUN) {
		bgun_change_gun_mem(GUNMEMOWNER_BONDGUN);

		if (g_Vars.currentplayer->gunctrl.gunmemowner != GUNMEMOWNER_BONDGUN) {
			g_Vars.lockscreen = true;
			return true;
		}
	}

	bgun_enter_flux();

	do {
		bgun_tick_master_load();
	} while (!bgun_is_loaded());

	g_Vars.currentplayer->gunctrl.loadall = false;

	return false;
}

struct modeldef *bgun_get_cart_modeldef(void)
{
	return g_Vars.currentplayer->gunctrl.cartmodeldef;
}

void bgun0f09ebcc(struct defaultobj *obj, struct coord *coord, RoomNum *rooms, Mtxf *matrix1, struct coord *velocity, Mtxf *matrix2, struct prop *prop, struct coord *pos)
{
	struct prop *objprop = obj->prop;

	if (objprop) {
		prop_activate(objprop);
		prop_enable(objprop);
		mtx00015f04(obj->model->scale, matrix1);
		func0f06a580(obj, coord, matrix1, rooms);

		if (obj->type == OBJTYPE_WEAPON && ((struct weaponobj *) obj)->weaponnum == WEAPON_BOLT) {
			s32 beamnum = boltbeam_find_by_prop(objprop);

			if (beamnum == -1) {
				beamnum = boltbeam_create(objprop);
			}

			if (beamnum != -1) {
				boltbeam_set_head_pos(beamnum, pos);
				boltbeam_set_tail_pos(beamnum, pos);
			}
		}

		func0f0685e4(objprop);

		if (obj->hidden & OBJHFLAG_PROJECTILE) {
			obj->projectile->flags |= PROJECTILEFLAG_AIRBORNE;
			obj->projectile->ownerprop = prop;

			projectile_set_sticky(objprop);
			mtx4_copy(matrix2, (Mtxf *)&obj->projectile->mtx);

			obj->projectile->speed.x = velocity->x;
			obj->projectile->speed.y = velocity->y;
			obj->projectile->speed.z = velocity->z;
			obj->projectile->obj = obj;
			obj->projectile->unk0d8 = g_Vars.lvframenum;
		}
	}
}

void bgun0f09ed2c(struct defaultobj *obj, struct coord *newpos, Mtxf *arg2, struct coord *velocity, Mtxf *arg4)
{
	struct prop *objprop = obj->prop;
	struct coord pos;
	RoomNum rooms[8];

	if (objprop) {
		struct prop *playerprop = g_Vars.currentplayer->prop;

		pos.x = playerprop->pos.x;
		pos.y = playerprop->pos.y;
		pos.z = playerprop->pos.z;

		rooms_copy(playerprop->rooms, rooms);

		bgun0f09ebcc(obj, &pos, rooms, arg2, velocity, arg4, playerprop, newpos);

		if (obj->hidden & OBJHFLAG_PROJECTILE) {
			obj->projectile->flags |= PROJECTILEFLAG_LAUNCHING;

			obj->projectile->nextsteppos.x = newpos->x;
			obj->projectile->nextsteppos.y = newpos->y;
			obj->projectile->nextsteppos.z = newpos->z;
		}
	}
}

struct defaultobj *bgun_create_thrown_projectile2(struct chrdata *chr, struct gset *gset, struct coord *pos, RoomNum *rooms, Mtxf *arg4, struct coord *velocity)
{
	struct defaultobj *obj = NULL;
	struct funcdef *basefunc;
	struct funcdef_throw *func;
	struct weapondef *weapon = gset_get_weapondef(gset->weaponnum);
	struct weaponobj *weaponobj;
	struct autogunobj *autogun;
	Mtxf mtx;
	s32 playernum;

	if (weapon == NULL) {
		return false;
	}

	basefunc = weapon->functions[gset->weaponfunc];
	func = (struct funcdef_throw *) basefunc;

	if (func == NULL) {
		return false;
	}

	if (gset->weaponnum == WEAPON_COMBATKNIFE) {
		guRotateF(mtx.m, 90.0f / (RANDOMFRAC() + 12.1f),
				arg4->m[1][0], arg4->m[1][1], arg4->m[1][2]);
	} else {
		projectile_load_random_rotation(&mtx);
	}

	if (gset->weaponnum == WEAPON_LAPTOPGUN) {
		autogun = laptop_deploy(func->projectilemodelnum, gset, chr);

		if (autogun != NULL) {
			obj = &autogun->base;
		}
	} else {
		weaponobj = weapon_create_projectile_from_gset(func->projectilemodelnum, gset, chr);

		if (weaponobj != NULL) {
			obj = &weaponobj->base;

			// Note this timer is converted to 240 time immediately below
			weaponobj->timer240 = func->activatetime60;

			if (weaponobj->timer240 >= 2) {
				weaponobj->timer240 = TICKS(weaponobj->timer240 * 4);
			}

			if (weaponobj->weaponnum == WEAPON_GRENADE || weaponobj->weaponnum == WEAPON_NBOMB) {
				prop_set_dangerous(weaponobj->base.prop);
			}

			if (func->projectilemodelnum == MODEL_CHRREMOTEMINE
					|| func->projectilemodelnum == MODEL_CHRTIMEDMINE
					|| func->projectilemodelnum == MODEL_CHRPROXIMITYMINE
					|| func->projectilemodelnum == MODEL_CHRECMMINE) {
				weaponobj->base.flags3 |= OBJFLAG3_00000008;
			}
		}
	}

	if (obj != NULL) {
		bgun0f09ebcc(obj, pos, rooms, arg4, velocity, &mtx, chr->prop, pos);

		obj->hidden &= 0x0fffffff;

		if (g_Vars.normmplayerisrunning) {
			playernum = mp_player_get_index(chr);
		} else {
			playernum = playermgr_get_player_num_by_prop(chr->prop);
		}

		obj->hidden |= playernum << 28;

		if (obj->hidden & OBJHFLAG_PROJECTILE) {
			obj->projectile->flags |= PROJECTILEFLAG_00000002;
			obj->projectile->unk08c = 0.1f;
			obj->projectile->pickuptimer240 = TICKS(240);

			ps_create(NULL, obj->prop, SFX_THROW, -1,
					-1, 0, 0, PSTYPE_NONE, NULL, -1, NULL, -1, -1, -1, -1);
		}
	}

	return obj;
}

/**
 * handnum supports some unusual values:
 *
 * 0 = right hand
 * 1 = left hand
 * 2 = fumbling grenade from right hand (due to nbomb)
 * 3 = fumbling grenade from left hand (actually not possible)
 */
void bgun_create_thrown_projectile(s32 handnum, struct gset *gset)
{
	struct coord velocity = {0, 0, 0};
	Mtxf sp1f4;
	struct coord gunpos;
	struct coord gundir;
	struct prop *playerprop = g_Vars.currentplayer->prop;
	struct coord *prevpos = &g_Vars.currentplayer->bondprevpos;
	struct coord *extrapos = &g_Vars.currentplayer->bondextrapos;
	Mtxf sp190;
	struct defaultobj *obj;
	struct weaponobj *weapon;
	struct coord muzzlepos;
	struct coord spawnpos;
	RoomNum spawnrooms[8];
	bool droppinggrenade = false;
	struct hand *hand;
	struct coord aimpos;
	struct coord sp140;
	f32 frac;
	f32 radians;
	Mtxf spf8;
	Mtxf spb8;
	Mtxf sp78;
	f32 sp68[4];
	f32 sp58[4];
	f32 sp48[4];
	struct trainingdata *data;
	u32 stack;

	if (handnum >= 2) {
		droppinggrenade = true;
		handnum -= 2;
	}

	hand = g_Vars.currentplayer->hands + handnum;

	muzzlepos.x = g_Vars.currentplayer->hands[handnum].muzzlepos.x;
	muzzlepos.y = g_Vars.currentplayer->hands[handnum].muzzlepos.y;
	muzzlepos.z = g_Vars.currentplayer->hands[handnum].muzzlepos.z;

	mtx4_load_identity(&sp1f4);

	if (gset->weaponnum == WEAPON_COMBATKNIFE) {
		mtx4_load_z_rotation(BADDTOR(270), &sp1f4);
		mtx4_load_x_rotation(BADDTOR(180), &sp190);
		mtx4_mult_mtx4_in_place(&sp190, &sp1f4);
	}

	mtx4_copy(&g_Vars.currentplayer->hands[handnum].muzzlemat, &sp190);

	guNormalize(&sp190.m[0][0], &sp190.m[0][1], &sp190.m[0][2]);
	guNormalize(&sp190.m[1][0], &sp190.m[1][1], &sp190.m[1][2]);
	guNormalize(&sp190.m[2][0], &sp190.m[2][1], &sp190.m[2][2]);

	sp190.m[3][0] = 0.0f;
	sp190.m[3][1] = 0.0f;
	sp190.m[3][2] = 0.0f;

	mtx4_mult_mtx4_in_place(&sp190, &sp1f4);

	player_set_perim_enabled(playerprop, false);

	if (cd_test_los11(&playerprop->pos, playerprop->rooms, &muzzlepos, spawnrooms, CDTYPE_ALL) != CDRESULT_COLLISION) {
		spawnpos.x = muzzlepos.x;
		spawnpos.y = muzzlepos.y;
		spawnpos.z = muzzlepos.z;
	} else {
		spawnpos.x = playerprop->pos.x;
		spawnpos.y = playerprop->pos.y;
		spawnpos.z = playerprop->pos.z;

		rooms_copy(playerprop->rooms, spawnrooms);
	}

	player_set_perim_enabled(playerprop, true);

	bgun_calculate_player_shot_spread(&gunpos, &gundir, handnum, true);
	mtx4_rotate_vec_in_place(cam_get_projection_mtxf(), &gundir);

	if (droppinggrenade) {
		// Dropping a grenade because player is in an nbomb storm
		velocity.x = gundir.x * 1.6666666f;
		velocity.y = gundir.y * 1.6666666f;
		velocity.z = gundir.z * 1.6666666f;
	} else if (gset_has_function_flags(&hand->gset, FUNCFLAG_CALCULATETRAJECTORY)) {
		// Calculate the velocity based on the trajectory to the aimpos
		prop_find_aiming_at(HAND_RIGHT, false, FINDPROPCONTEXT_QUERY);

		if (hand->hasdotinfo) {
			aimpos.x = hand->dotpos.x;
			aimpos.y = hand->dotpos.y;
			aimpos.z = hand->dotpos.z;

			chr_calculate_trajectory(&spawnpos, 21.666666f, &aimpos, &sp140);

			radians = acosf(gundir.f[0] * sp140.f[0] + gundir.f[1] * sp140.f[1] + gundir.f[2] * sp140.f[2]);

			if (radians > BADDTOR2(20) || radians < BADDTOR2(-20)) {
				mtx00016b58(&spf8, 0, 0, 0, gundir.x, gundir.y, gundir.z, 0, 1, 0);
				mtx00016b58(&spb8, 0, 0, 0, sp140.x, sp140.y, sp140.z, 0, 1, 0);

				quaternion0f097044(&spf8, sp68);
				quaternion0f097044(&spb8, sp58);
				quaternion0f0976c0(sp68, sp58);

				frac = BADDTOR2(20) / radians;

				if (frac < 0.0f) {
					frac = -frac;
				}

				quaternion_slerp(sp68, sp58, frac, sp48);
				quaternion_to_mtx(sp48, &sp78);

				gundir.x = -sp78.m[2][0];
				gundir.y = -sp78.m[2][1];
				gundir.z = -sp78.m[2][2];
			} else {
				gundir.x = sp140.x;
				gundir.y = sp140.y;
				gundir.z = sp140.z;
			}
		}

		velocity.x = gundir.x * 21.666666f;
		velocity.y = gundir.y * 21.666666f;
		velocity.z = gundir.z * 21.666666f;
	} else {
		// Simple velocity
		velocity.x = gundir.x * 16.666666f;
		velocity.y = gundir.y * 16.666666f;
		velocity.z = gundir.z * 16.666666f;

		if (gset->weaponnum == WEAPON_GRENADE || gset->weaponnum == WEAPON_NBOMB) {
			velocity.y += 1.6666666f;
		} else {
			velocity.y += 5.0f;
		}
	}

	if (gset->weaponnum == WEAPON_LAPTOPGUN) {
		bgun_free_weapon(handnum);
	}

	// Add player movement to velocity
	if (g_Vars.lvupdate240 > 0) {
		velocity.x += (playerprop->pos.x - prevpos->x + extrapos->x) / g_Vars.lvupdate60freal;
		velocity.y += (playerprop->pos.y - prevpos->y + extrapos->y) / g_Vars.lvupdate60freal;
		velocity.z += (playerprop->pos.z - prevpos->z + extrapos->z) / g_Vars.lvupdate60freal;
	}

	obj = bgun_create_thrown_projectile2(g_Vars.currentplayer->prop->chr, gset, &spawnpos, spawnrooms, &sp1f4, &velocity);

	if (obj) {
		if (obj->type == OBJTYPE_WEAPON) {
			weapon = (struct weaponobj *)obj;

			if (gset->weaponnum == WEAPON_GRENADE && gset->weaponfunc == FUNC_PRIMARY) {
				if (weapon->timer240 < hand->primetimer60 * 4) {
					weapon->timer240 = 0;
				} else {
					weapon->timer240 -= hand->primetimer60 * 4;
				}

				weapon->gunfunc = gset->weaponfunc;
			} else if (gset->weaponnum == WEAPON_ECMMINE && g_Vars.stagenum == STAGE_CITRAINING) {
				data = dt_get_data();

				if (data->intraining) {
					data->obj = obj;
				}
			}
		}

		if (obj->hidden & OBJHFLAG_PROJECTILE) {
			obj->projectile->flags |= PROJECTILEFLAG_LAUNCHING;
			obj->projectile->nextsteppos.x = muzzlepos.x;
			obj->projectile->nextsteppos.y = muzzlepos.y;
			obj->projectile->nextsteppos.z = muzzlepos.z;

			if (gset->weaponnum == WEAPON_GRENADE && gset->weaponfunc == FUNC_SECONDARY) {
				obj->projectile->unk08c = 1.0f;
			}

			if (gset->weaponnum == WEAPON_COMBATKNIFE) {
				// In theory, weapon can be uninitialised here,
				// but in practice it's always set.
				weapon->base.projectile->flags |= PROJECTILEFLAG_00000002;
				weapon->base.projectile->unk08c = 0.1f;
				weapon->base.projectile->pickuptimer240 = TICKS(240);
				weapon->base.hidden |= OBJHFLAG_THROWNKNIFE;
			}
		}
	}
}

void bgun_update_held_rocket(s32 handnum)
{
	struct hand *hand = &g_Vars.currentplayer->hands[handnum];
	struct defaultobj *obj = &hand->rocket->base;

	if (obj) {
		struct prop *objprop = obj->prop;
		Mtxf mtx;

		if (objprop) {
			struct prop *playerprop = g_Vars.currentplayer->prop;
			struct model *model = obj->model;

			if (!hand->firedrocket) {
				mtx4_copy(&hand->posmtx, &mtx);

				mtx.m[3][0] = 0;
				mtx.m[3][1] = 0;
				mtx.m[3][2] = 0;

				mtx00015f04(obj->model->scale, &mtx);
				func0f06a580(obj, &hand->muzzlepos, &mtx, playerprop->rooms);
				prop_deregister_rooms(objprop);
			}

			model->matrices = gfx_allocate(model->definition->nummatrices * sizeof(Mtxf));

			mtx4_copy(&hand->muzzlemat, &model->matrices[0]);
			model_update_relations_quick(model, model->definition->rootnode);

			objprop->flags |= PROPFLAG_ONANYSCREENTHISTICK | PROPFLAG_ONTHISSCREENTHISTICK;
			objprop->z = -model->matrices[0].m[3][2];
		}
	}
}

void bgun_create_held_rocket(s32 handnum, struct funcdef_shootprojectile *func)
{
	struct hand *hand = &g_Vars.currentplayer->hands[handnum];
	struct weaponobj *obj;

	if (hand->rocket == NULL) {
#if VERSION >= VERSION_NTSC_1_0
		hand->firedrocket = false;
#endif

		obj = weapon_create_projectile_from_weapon_num(func->projectilemodelnum, WEAPON_ROCKET, g_Vars.currentplayer->prop->chr);

		if (obj != NULL) {
			hand->rocket = obj;
			hand->firedrocket = false;

			obj->timer240 = 1;
#if VERSION >= VERSION_NTSC_1_0
			obj->base.flags |= OBJFLAG_HELDROCKET;
#endif
			obj->base.flags2 |= OBJFLAG2_THROWTHROUGH;
		}
	}
}

void bgun_free_held_rocket(s32 handnum)
{
	struct hand *hand = &g_Vars.currentplayer->hands[handnum];

	if (hand->rocket) {
		obj_free_permanently(&hand->rocket->base, true);
		hand->rocket = NULL;
	}
}

void bgun_create_fired_projectile(s32 handnum)
{
	struct weapondef *weapondef;
	struct hand *hand;
	Mtxf sp270;
	struct coord sp264;
	f32 sp260;
	f32 sp25c;
	struct coord sp250;
	Mtxf sp210;
	struct coord gunpos;
	struct coord gundir;
	struct prop *playerprop;
	struct coord *prevpos;
	struct coord *extrapos;
	struct coord spawnpos;
	struct weaponobj *weapon;
	struct funcdef *tmp;
	struct funcdef_shootprojectile *funcdef;
	struct coord aimpos;
	struct coord sp1bc;
	f32 frac;
	f32 radians;
	Mtxf sp174;
	Mtxf sp134;
	Mtxf spf4;
	f32 spe4[4];
	f32 spd4[4];
	f32 spc4[4];

	hand = g_Vars.currentplayer->hands + handnum;

	playerprop = g_Vars.currentplayer->prop;
	prevpos = &g_Vars.currentplayer->bondprevpos;
	extrapos = &g_Vars.currentplayer->bondextrapos;

	weapondef = gset_get_weapondef(hand->gset.weaponnum);

	if (weapondef) {
		tmp = weapondef->functions[hand->gset.weaponfunc];

		if (tmp && tmp->type == INVENTORYFUNCTYPE_SHOOT_PROJECTILE) {
			funcdef = (struct funcdef_shootprojectile *)tmp;

			mtx4_load_identity(&sp270);
			bgun_calculate_player_shot_spread(&gunpos, &gundir, handnum, true);
			mtx4_rotate_vec_in_place(cam_get_projection_mtxf(), &gundir);

			spawnpos.x = hand->muzzlepos.x;
			spawnpos.y = hand->muzzlepos.y;
			spawnpos.z = hand->muzzlepos.z;

			if (hand->gset.weaponnum == WEAPON_SLAYER && hand->gset.weaponfunc == FUNC_SECONDARY) {
				spawnpos.x += 50.0f * gundir.x;
				spawnpos.y += 50.0f * gundir.y;
				spawnpos.z += 50.0f * gundir.z;
			}

			sp260 = funcdef->speed * 1.6666666f / 60.0f;
			sp25c = funcdef->traveldist * 1.6666666f;

			if (gset_has_function_flags(&hand->gset, FUNCFLAG_CALCULATETRAJECTORY)) {
				prop_find_aiming_at(HAND_RIGHT, false, FINDPROPCONTEXT_QUERY);

				if (hand->hasdotinfo) {
					aimpos.x = hand->dotpos.x;
					aimpos.y = hand->dotpos.y;
					aimpos.z = hand->dotpos.z;

					chr_calculate_trajectory(&spawnpos, sp25c, &aimpos, &sp1bc);

					radians = acosf(gundir.f[0] * sp1bc.f[0] + gundir.f[1] * sp1bc.f[1] + gundir.f[2] * sp1bc.f[2]);

					if (radians > BADDTOR2(10) || radians < BADDTOR2(-10)) {
						mtx00016b58(&sp174, 0.0f, 0.0f, 0.0f, gundir.x, gundir.y, gundir.z, 0.0f, 1.0f, 0.0f);
						mtx00016b58(&sp134, 0.0f, 0.0f, 0.0f, sp1bc.x, sp1bc.y, sp1bc.z, 0.0f, 1.0f, 0.0f);

						quaternion0f097044(&sp174, spe4);
						quaternion0f097044(&sp134, spd4);
						quaternion0f0976c0(spe4, spd4);

						frac = BADDTOR2(10) / radians;

						if (frac < 0.0f) {
							frac = -frac;
						}

						quaternion_slerp(spe4, spd4, frac, spc4);
						quaternion_to_mtx(spc4, &spf4);

						gundir.x = -spf4.m[2][0];
						gundir.y = -spf4.m[2][1];
						gundir.z = -spf4.m[2][2];
					} else {
						gundir.x = sp1bc.x;
						gundir.y = sp1bc.y;
						gundir.z = sp1bc.z;
					}
				}
			}

			sp250.x = gundir.x * sp260;
			sp250.y = gundir.y * sp260;
			sp250.z = gundir.z * sp260;

			sp264.x = sp250.f[0] * g_Vars.lvupdate60freal + gundir.f[0] * sp25c;
			sp264.y = sp250.f[1] * g_Vars.lvupdate60freal + gundir.f[1] * sp25c;
			sp264.z = sp250.f[2] * g_Vars.lvupdate60freal + gundir.f[2] * sp25c;

			if ((funcdef->base.base.flags & FUNCFLAG_FLYBYWIRE) == 0 && g_Vars.lvupdate240 > 0) {
				sp264.x += (playerprop->pos.x - prevpos->x + extrapos->x) / g_Vars.lvupdate60freal;
				sp264.y += (playerprop->pos.y - prevpos->y + extrapos->y) / g_Vars.lvupdate60freal;
				sp264.z += (playerprop->pos.z - prevpos->z + extrapos->z) / g_Vars.lvupdate60freal;
			}

			mtx4_copy(&g_Vars.currentplayer->hands[handnum].posmtx, &sp210);

			sp210.m[3][0] = 0.0f;
			sp210.m[3][1] = 0.0f;
			sp210.m[3][2] = 0.0f;

			if (hand->rocket) {
				hand->firedrocket = true;

				weapon = hand->rocket;
				weapon->base.flags2 &= ~OBJFLAG2_THROWTHROUGH;
#if VERSION >= VERSION_NTSC_1_0
				weapon->base.flags &= ~OBJFLAG_HELDROCKET;
#endif

				if (funcdef->base.base.flags & FUNCFLAG_HOMINGROCKET) {
					weapon->weaponnum = WEAPON_HOMINGROCKET;
				}
			} else if (hand->gset.weaponnum == WEAPON_ROCKETLAUNCHER || hand->gset.weaponnum == WEAPON_SLAYER) {
				u32 stack;
				s32 weaponnum = WEAPON_ROCKET;

				if (funcdef->base.base.flags & FUNCFLAG_HOMINGROCKET) {
					weaponnum = WEAPON_HOMINGROCKET;
				}

				weapon = weapon_create_projectile_from_weapon_num(funcdef->projectilemodelnum, weaponnum, g_Vars.currentplayer->prop->chr);
			} else if (hand->gset.weaponnum == WEAPON_CROSSBOW) {
				weapon = weapon_create_projectile_from_weapon_num(funcdef->projectilemodelnum, WEAPON_BOLT, g_Vars.currentplayer->prop->chr);

				if (weapon) {
					weapon->gunfunc = hand->gset.weaponfunc;
				}
			} else if (hand->gset.weaponnum == WEAPON_DEVASTATOR) {
				weapon = weapon_create_projectile_from_weapon_num(funcdef->projectilemodelnum, WEAPON_GRENADEROUND, g_Vars.currentplayer->prop->chr);

				if (weapon) {
					weapon->gunfunc = hand->gset.weaponfunc;
				}
			} else if (hand->gset.weaponnum == WEAPON_SUPERDRAGON) {
				weapon = weapon_create_projectile_from_weapon_num(funcdef->projectilemodelnum, WEAPON_GRENADEROUND, g_Vars.currentplayer->prop->chr);

				if (weapon) {
					weapon->gunfunc = FUNC_2;
				}
			} else {
				weapon = weapon_create_projectile_from_gset(funcdef->projectilemodelnum, &hand->gset, g_Vars.currentplayer->prop->chr);
			}

			if (weapon) {
#if VERSION >= VERSION_NTSC_1_0
				bool failed = false;
				Mtxf sp78;
				struct coord sp6c;
				struct coord sp60;

				if (weapon->base.model && weapon->base.model->definition) {
					weapon->timer240 = funcdef->timer60;

					if (weapon->timer240 != -1) {
						weapon->timer240 = TICKS(weapon->timer240 * 4);
					}

					weapon->base.hidden &= 0x0fffffff;
					weapon->base.hidden |= g_Vars.currentplayernum << 28;

					bgun0f09ed2c(&weapon->base, &spawnpos, &sp210, &sp264, &sp270);

					if (weapon->base.hidden & OBJHFLAG_PROJECTILE) {
						if (funcdef->base.base.flags & FUNCFLAG_PROJECTILE_LIGHTWEIGHT) {
							weapon->base.projectile->flags |= PROJECTILEFLAG_LIGHTWEIGHT;
						} else if (funcdef->base.base.flags & FUNCFLAG_PROJECTILE_POWERED) {
							weapon->base.projectile->flags |= PROJECTILEFLAG_POWERED;
						}

						weapon->base.projectile->targetprop = g_Vars.currentplayer->trackedprops[0].prop;

						if (funcdef->scale != 1.0f) {
							weapon->base.model->scale *= funcdef->scale;

							mtx3_to_mtx4(weapon->base.realrot, &sp78);
							mtx00015f04(funcdef->scale, &sp78);
							mtx4_to_mtx3(&sp78, weapon->base.realrot);
						}

						weapon->base.projectile->powerlimit240 = TICKS(1200);
						weapon->base.projectile->unk0a8 = weapon->base.prop->pos.y;
						weapon->base.projectile->unk0ac = weapon->base.projectile->speed.y;
						weapon->base.projectile->unk010 = sp250.x;
						weapon->base.projectile->unk014 = sp250.y;
						weapon->base.projectile->unk018 = sp250.z;
						weapon->base.projectile->pickuptimer240 = TICKS(240);
						weapon->base.projectile->unk08c = funcdef->reflectangle;
						weapon->base.projectile->unk098 = funcdef->unk50 * 1.6666666f;

						if (funcdef->soundnum > 0) {
							ps_create(NULL, weapon->base.prop, funcdef->soundnum, -1, -1, 0, 0, PSTYPE_NONE, 0, -1.0f, 0, -1, -1.0f, -1.0f, -1.0f);
						}

						if (funcdef->base.base.flags & FUNCFLAG_FLYBYWIRE) {
							player_launch_slayer_rocket(weapon);
						}

						if (weapon->base.projectile->flags & PROJECTILEFLAG_LAUNCHING) {
							projectile_launch(&weapon->base, weapon->base.projectile, &sp6c, &sp60);
						}
					} else {
						failed = true;
					}
				} else {
					failed = true;
				}

				if (failed) {
					weapon->timer240 = -1;

					if (weapon->base.prop) {
						prop_free(weapon->base.prop);
					}

					if (weapon->base.model) {
						modelmgr_free_model(weapon->base.model);
					}

					weapon->base.prop = NULL;
					weapon->base.model = NULL;
				}
#else
				// NTSC beta doesn't have any of the failure checks
				Mtxf sp78;
				struct coord sp6c;
				struct coord sp60;

				weapon->timer240 = funcdef->timer60;

				if (weapon->timer240 != -1) {
					weapon->timer240 = TICKS(weapon->timer240 * 4);
				}

				weapon->base.hidden &= 0x0fffffff;
				weapon->base.hidden |= g_Vars.currentplayernum << 28;

				bgun0f09ed2c(&weapon->base, &spawnpos, &sp210, &sp264, &sp270);

				if (weapon->base.hidden & OBJHFLAG_PROJECTILE) {
					if (funcdef->base.base.flags & FUNCFLAG_PROJECTILE_LIGHTWEIGHT) {
						weapon->base.projectile->flags |= PROJECTILEFLAG_LIGHTWEIGHT;
					} else if (funcdef->base.base.flags & FUNCFLAG_PROJECTILE_POWERED) {
						weapon->base.projectile->flags |= PROJECTILEFLAG_POWERED;
					}

					weapon->base.projectile->targetprop = g_Vars.currentplayer->trackedprops[0].prop;

					if (funcdef->scale != 1.0f) {
						weapon->base.model->scale *= funcdef->scale;

						mtx3_to_mtx4(weapon->base.realrot, &sp78);
						mtx00015f04(funcdef->scale, &sp78);
						mtx4_to_mtx3(&sp78, weapon->base.realrot);
					}

					weapon->base.projectile->powerlimit240 = TICKS(1200);
					weapon->base.projectile->unk0a8 = weapon->base.prop->pos.y;
					weapon->base.projectile->unk0ac = weapon->base.projectile->speed.y;
					weapon->base.projectile->unk010 = sp250.x;
					weapon->base.projectile->unk014 = sp250.y;
					weapon->base.projectile->unk018 = sp250.z;
					weapon->base.projectile->pickuptimer240 = TICKS(240);
					weapon->base.projectile->unk08c = funcdef->reflectangle;
					weapon->base.projectile->unk098 = funcdef->unk50 * 1.6666666f;

					if (funcdef->soundnum > 0) {
						ps_create(NULL, weapon->base.prop, funcdef->soundnum, -1, -1, 0, 0, PSTYPE_NONE, 0, -1.0f, 0, -1, -1.0f, -1.0f, -1.0f);
					}

					if (funcdef->base.base.flags & FUNCFLAG_FLYBYWIRE) {
						player_launch_slayer_rocket(weapon);
					}

					if (weapon->base.projectile->flags & PROJECTILEFLAG_LAUNCHING) {
						projectile_launch(&weapon->base, weapon->base.projectile, &sp6c, &sp60);
					}
				}
#endif
			}
		}
	}
}

void bgun_swivel(f32 screenx, f32 screeny, f32 crossdamp, f32 aimdamp)
{
	f32 screenwidth = cam_get_screen_width();
	f32 screenheight = cam_get_screen_height();
	struct player *player = g_Vars.currentplayer;
	struct coord aimpos;
	s32 l;
	s32 h;
	f32 x[2];
	f32 y[2];
	bool ignore[2] = {false, false};
	s32 numframes;
	struct hand *hand;
	struct coord sp94;
	f32 sp8c[2];

	x[HAND_RIGHT] = x[HAND_LEFT] = screenx;
	y[HAND_RIGHT] = y[HAND_LEFT] = screeny;

	ignore[HAND_LEFT] = !player->hands[HAND_LEFT].inuse;
	ignore[HAND_RIGHT] = !player->hands[HAND_RIGHT].inuse;

	// If using right hand only and reloading,
	// recentre until the reload animation is almost complete
	if (!player->hands[HAND_LEFT].inuse
			&& player->hands[HAND_RIGHT].state == HANDSTATE_RELOAD
			&& player->hands[HAND_RIGHT].animcmd) {
		numframes = 25;

		if (player->hands[HAND_RIGHT].gset.weaponnum == WEAPON_CROSSBOW) {
			numframes = 5;
		}

		if ((s32)bgun_get_current_keyframe(&player->hands[HAND_RIGHT]) < model_get_num_anim_frames(&player->hands[HAND_RIGHT].gunmodel) - numframes) {
			x[HAND_RIGHT] = 0.0f;
			y[HAND_RIGHT] = 0.0f;
			ignore[HAND_RIGHT] = true;
		}
	}

	if (player->hands[HAND_LEFT].gset.weaponnum == WEAPON_REMOTEMINE) {
		x[HAND_LEFT] = g_Vars.currentplayer->speedtheta * 0.3f + g_Vars.currentplayer->gunextraaimx;
		y[HAND_LEFT] = -g_Vars.currentplayer->speedverta * 0.1f + g_Vars.currentplayer->gunextraaimy;
		ignore[HAND_LEFT] = true;
	}

	if (player->hands[HAND_RIGHT].gset.weaponnum == WEAPON_UNARMED) {
		x[HAND_RIGHT] = g_Vars.currentplayer->speedtheta * 0.3f + g_Vars.currentplayer->gunextraaimx;
		y[HAND_RIGHT] = -g_Vars.currentplayer->speedverta * 0.1f + g_Vars.currentplayer->gunextraaimy;
		ignore[HAND_RIGHT] = true;
	}

	if (g_Vars.currentplayer->teleportstate != TELEPORTSTATE_INACTIVE) {
		ignore[HAND_LEFT] = ignore[HAND_RIGHT] = true;
	}

	// This loop only iterates once
	for (h = 0; h < 1; h++) {
		if (!ignore[h]) {
			hand = &player->hands[h];

			if (hand->hasdotinfo && !g_Vars.mplayerisrunning) {
				sp94.x = hand->dotpos.x;
				sp94.y = hand->dotpos.y;
				sp94.z = hand->dotpos.z;

				mtx4_transform_vec_in_place(cam_get_world_to_screen_mtxf(), &sp94);

				if (!(sp94.z < 0.0000001f) || !(sp94.z > -0.0000001f)) {
					if (sp94.z > -6000.0f) {
						cam0f0b4d04(&sp94, sp8c);

						x[h] = sp8c[0];
						y[h] = sp8c[1];

						x[h] = 2.0f * (x[h] / vi_get_view_width()) - 1.0f;
						y[h] = 2.0f * (y[h] / vi_get_view_height()) - 1.0f;
					}
				}
			}
		}
	}

	player->oldcrosspos[0] = player->crosspos[0];
	player->oldcrosspos[1] = player->crosspos[1];

	if (crossdamp != player->guncrossdamp) {
		player->crosspossum[0] = player->crosspossum[0] * (1.0f - player->guncrossdamp) / (1.0f - crossdamp);
		player->crosspossum[1] = player->crosspossum[1] * (1.0f - player->guncrossdamp) / (1.0f - crossdamp);
		player->guncrossdamp = crossdamp;
	}

	if (aimdamp != player->gunaimdamp) {
		player->crosssum2[0] = player->crosssum2[0] * (1.0f - player->gunaimdamp) / (1.0f - aimdamp);
		player->crosssum2[1] = player->crosssum2[1] * (1.0f - player->gunaimdamp) / (1.0f - aimdamp);
		player->gunaimdamp = aimdamp;
	}

	for (l = 0; l < g_Vars.lvupdate240; l++) {
		player->crosspossum[0] = player->crosspossum[0] * crossdamp + screenx;
		player->crosspossum[1] = player->crosspossum[1] * crossdamp + screeny;

		for (h = 0; h < 2; h++) {
			hand = &player->hands[h];
			hand->guncrosspossum[0] = (PAL ? 0.913f : 0.9269697f) * hand->guncrosspossum[0] + x[h];
			hand->guncrosspossum[1] = (PAL ? 0.913f : 0.9269697f) * hand->guncrosspossum[1] + y[h];
		}
	}

	player->crosspos[0] = player->crosspossum[0] * (1.0f - crossdamp) * screenwidth * 0.5f + screenwidth * 0.5f;
	player->crosspos[1] = player->crosspossum[1] * (1.0f - crossdamp) * screenheight * 0.5f + screenheight * 0.5f;

	if (player->crosspos[0] < 3.0f) {
		player->crosspos[0] = 3.0f;
	} else if (player->crosspos[0] > screenwidth - 4.0f) {
		player->crosspos[0] = screenwidth - 4.0f;
	}

	if (player->crosspos[1] < 3.0f) {
		player->crosspos[1] = 3.0f;
	} else if (player->crosspos[1] > screenheight - 4.0f) {
		player->crosspos[1] = screenheight - 4.0f;
	}

	player->crosspos[0] += cam_get_screen_left();
	player->crosspos[1] += cam_get_screen_top();

	for (h = 0; h < 2; h++) {
		player->hands[h].crosspos[0] = player->hands[h].guncrosspossum[0] * (PAL ? 0.08700001f : 0.07303029f) * screenwidth * 0.5f + screenwidth * 0.5f;
		player->hands[h].crosspos[1] = player->hands[h].guncrosspossum[1] * (PAL ? 0.08700001f : 0.07303029f) * screenheight * 0.5f + screenheight * 0.5f;

		if (player->hands[h].crosspos[0] < 3.0f) {
			player->hands[h].crosspos[0] = 3.0f;
		} else if (player->hands[h].crosspos[0] > screenwidth - 4.0f) {
			player->hands[h].crosspos[0] = screenwidth - 4.0f;
		}

		if (player->hands[h].crosspos[1] < 3.0f) {
			player->hands[h].crosspos[1] = 3.0f;
		} else if (player->hands[h].crosspos[1] > screenheight - 4.0f) {
			player->hands[h].crosspos[1] = screenheight - 4.0f;
		}

		player->hands[h].crosspos[0] += cam_get_screen_left();
		player->hands[h].crosspos[1] += cam_get_screen_top();
	}

	for (l = 0; l < g_Vars.lvupdate240; l++) {
		player->crosssum2[0] = player->crosssum2[0] * aimdamp + screenx;
		player->crosssum2[1] = player->crosssum2[1] * aimdamp + screeny;
	}

	player->crosspos2[0] = player->crosssum2[0] * (1.0f - aimdamp) * screenwidth * 0.5f + screenwidth * 0.5f;
	player->crosspos2[1] = player->crosssum2[1] * (1.0f - aimdamp) * screenheight * 0.5f + screenheight * 0.5f;
	player->crosspos2[0] += cam_get_screen_left();
	player->crosspos2[1] += cam_get_screen_top();

	cam0f0b4c3c(player->crosspos2, &aimpos, 1000);

	bgun_set_aim_pos(&aimpos);
}

/**
 * Swivel the gun towards the given screen coordinates, dampening the movement
 * speed as it reaches the target.
 *
 * This is used for auto aim, the CMP's follow lock-on, and general turning.
 */
void bgun_swivel_with_damp(f32 screenx, f32 screeny, f32 crossdamp)
{
	struct weapondef *weapon = gset_get_weapondef(bgun_get_weapon_num(HAND_RIGHT));
	f32 aimdamp = PAL ? weapon->aimsettings->aimdamppal : weapon->aimsettings->aimdamp;

	if (aimdamp < crossdamp) {
		aimdamp = crossdamp;
	}

	bgun_swivel(screenx, screeny, crossdamp, aimdamp);
}

/**
 * Swivel the gun towards the given screen coordinates without slowing the speed
 * speed as it reaches the target.
 *
 * This is used when manual aiming.
 */
void bgun_swivel_without_damp(f32 screenx, f32 screeny)
{
	struct weapondef *weapon = gset_get_weapondef(bgun_get_weapon_num(HAND_RIGHT));
	f32 aimdamp = PAL ? weapon->aimsettings->aimdamppal : weapon->aimsettings->aimdamp;

	bgun_swivel(screenx, screeny, PAL ? 0.935f : 0.945f, aimdamp);
}

void bgun_get_cross_pos(f32 *x, f32 *y)
{
	struct player *player = g_Vars.currentplayer;

	*x = player->crosspos[0];
	*y = player->crosspos[1];
}

void bgun0f0a0c08(struct coord *arg0, struct coord *arg1)
{
	arg0->x = 0;
	arg0->y = 0;
	arg0->z = 0;

	cam0f0b4c3c(g_Vars.currentplayer->crosspos, arg1, 1);
}

void bgun0f0a0c44(s32 handnum, struct coord *arg1, struct coord *arg2)
{
	arg1->x = 0;
	arg1->y = 0;
	arg1->z = 0;

	cam0f0b4c3c(g_Vars.currentplayer->hands[handnum].crosspos, arg2, 1);
}

void bgun_calculate_player_shot_spread(struct coord *gunpos2d, struct coord *gundir2d, s32 handnum, bool dorandom)
{
	f32 crosspos[2];
	f32 spread = 0;
	f32 scaledspread;
	f32 randfactor;
	struct funcdef *func = gset_get_current_funcdef(handnum);
	struct player *player = g_Vars.currentplayer;

	if (func != NULL && (func->type & 0xff) == INVENTORYFUNCTYPE_SHOOT) {
		struct funcdef_shoot *shootfunc = (struct funcdef_shoot *) func;
		spread = shootfunc->spread;
	}

	if (gset_has_aim_flag(bgun_get_weapon_num2(handnum), INVAIMFLAG_ACCURATESINGLESHOT)
			&& player->hands[handnum].burstbullets == 1) {
		spread *= 0.25f;
	}

	// Decrease spread if double crouched
	if (bmove_get_crouch_pos() == CROUCHPOS_SQUAT) {
		spread *= 0.5f;
	}

	// Increase spread if dual wielding
	if (player->hands[HAND_LEFT].inuse) {
		spread *= 1.5f;
	}

	scaledspread = 120.0f * spread / vi_get_fov_y();

	if (dorandom) {
		randfactor = (RANDOMFRAC() - 0.5f) * RANDOMFRAC();
	} else {
		randfactor = 0;
	}

	crosspos[0] = player->crosspos[0] + randfactor * scaledspread * cam_get_screen_width()
		/ (vi_get_height() * cam_get_persp_aspect());

	if (dorandom) {
		randfactor = (RANDOMFRAC() - 0.5f) * RANDOMFRAC();
	} else {
		randfactor = 0;
	}

	crosspos[1] = player->crosspos[1] + (randfactor * scaledspread * cam_get_screen_height())
		/ vi_get_height();

	gunpos2d->x = 0;
	gunpos2d->y = 0;
	gunpos2d->z = 0;

	cam0f0b4c3c(crosspos, gundir2d, 1);
}

void bgun_calculate_bot_shot_spread(struct coord *arg0, s32 weaponnum, s32 funcnum, bool arg3, s32 crouchpos, bool dual)
{
	f32 spread = 0.0f;
	f32 radius;
	struct weapondef *weapondef = gset_get_weapondef(weaponnum);
	f32 x;
	f32 y;
	Mtxf mtx;
	struct coord sp48;
	u32 stack;

	if (weapondef) {
		struct funcdef *funcdef = weapondef->functions[funcnum];

		if (funcdef && (funcdef->type & 0xff) == INVENTORYFUNCTYPE_SHOOT) {
			struct funcdef_shoot *shootfunc = (struct funcdef_shoot *)funcdef;
			spread = shootfunc->spread;
		}
	}

	if (arg3 && gset_has_aim_flag(weaponnum, INVAIMFLAG_ACCURATESINGLESHOT)) {
		spread *= 0.25f;
	}

	if (crouchpos == CROUCHPOS_SQUAT) {
		spread *= 0.5f;
	}

	if (dual) {
		spread *= 1.5f;
	}

	radius = 120.0f * spread / vi_get_fov_y();
	x = (RANDOMFRAC() - 0.5f) * RANDOMFRAC() * radius;
	y = (RANDOMFRAC() - 0.5f) * RANDOMFRAC() * radius;

	sp48.x = g_Vars.currentplayer->c_scalex * x;
	sp48.y = g_Vars.currentplayer->c_scaley * y;
	sp48.z = -1.0f;

	guNormalize(&sp48.x, &sp48.y, &sp48.z);
	mtx00016b58(&mtx, 0.0f, 0.0f, 0.0f, arg0->x, arg0->y, arg0->z, 0.0f, -1.0f, 0.0f);
	mtx4_rotate_vec(&mtx, &sp48, arg0);
}

bool bgun_get_last_shoot_info(struct coord *pos, struct coord *dir, s32 handnum)
{
	struct hand *hand = &g_Vars.currentplayer->hands[handnum];

	if (!hand->lastdirvalid) {
		return false;
	}

	pos->x = hand->lastshootpos.x;
	pos->y = hand->lastshootpos.y;
	pos->z = hand->lastshootpos.z;

	dir->x = hand->lastshootdir.x;
	dir->y = hand->lastshootdir.y;
	dir->z = hand->lastshootdir.z;

	return true;
}

void bgun_set_last_shoot_info(struct coord *pos, struct coord *dir, s32 handnum)
{
	struct hand *hand = &g_Vars.currentplayer->hands[handnum];

	hand->lastdirvalid = true;

	hand->lastshootpos.x = pos->x;
	hand->lastshootpos.y = pos->y;
	hand->lastshootpos.z = pos->z;

	hand->lastshootdir.x = dir->x;
	hand->lastshootdir.y = dir->y;
	hand->lastshootdir.z = dir->z;
}

s32 bgun_get_shots_to_take(s32 handnum)
{
	struct hand *hand = &g_Vars.currentplayer->hands[handnum];

	return hand->shotstotake;
}

void bgun_free_weapon(s32 handnum)
{
	struct player *player = g_Vars.currentplayer;
	s32 i;

	if (player->hands[handnum].inuse) {
		for (i = 0; i < 2; i++) {
			if (player->gunctrl.ammotypes[i] >= 0) {
				s32 spaceinclip = player->hands[handnum].clipsizes[i] - player->hands[handnum].loadedammo[i];
				s32 index = bgun_get_unequipped_reload_index(player->gunctrl.weaponnum);

				if (index != -1) {
#if VERSION >= VERSION_JPN_FINAL
					player->hands[handnum].gunroundsspent[index] = (spaceinclip << 8) + 0xff;
#elif VERSION >= VERSION_PAL_BETA
					player->hands[handnum].gunroundsspent[index] = spaceinclip * 213 + 212;
#else
					player->hands[handnum].gunroundsspent[index] = (spaceinclip << 8) | 0xff;
#endif
				}

				if (player->hands[handnum].loadedammo[i] > 0) {
					player->ammoheldarr[player->gunctrl.ammotypes[i]] += player->hands[handnum].loadedammo[i];
				}

				player->hands[handnum].loadedammo[i] = 0;
			}
		}
	}

	if (g_Vars.mplayerisrunning && (IS8MB() || PLAYERCOUNT() != 1)) {
		playermgr_delete_weapon(handnum);
	}

	bgun_free_held_rocket(handnum);
}

void bgun_tick_switch2(void)
{
	struct player *player = g_Vars.currentplayer;
	struct gunctrl *ctrl = &g_Vars.currentplayer->gunctrl;
	s32 i;

	if (ctrl->switchtoweaponnum >= 0) {
		if (bgun_can_free_weapon(HAND_RIGHT) && bgun_can_free_weapon(HAND_LEFT)) {
			s32 weaponnum = player->gunctrl.weaponnum;
			s32 previnuse = player->hands[HAND_LEFT].inuse;
			struct hand *lefthand;
			struct hand *righthand;

			if (gset_get_device_state(ctrl->switchtoweaponnum) != DEVICESTATE_UNEQUIPPED) {
				ctrl->switchtoweaponnum = WEAPON_UNARMED;
			}

#if VERSION == VERSION_JPN_FINAL
			if (ctrl->switchtoweaponnum == WEAPON_COMBATKNIFE) {
				ctrl->switchtoweaponnum = WEAPON_UNARMED;
			}
#endif

			if (ctrl->dualwielding && !inv_has_double_weapon_inc_all_guns(ctrl->switchtoweaponnum, ctrl->switchtoweaponnum)) {
				ctrl->dualwielding = false;
			}

			func0f0d7364();

			bgun_free_weapon(HAND_LEFT);
			bgun_free_weapon(HAND_RIGHT);

			if (weaponnum == WEAPON_HORIZONSCANNER) {
				g_Vars.currentplayer->insightaimmode = false;
			}

			if (weaponnum == WEAPON_RCP120) {
				s32 amount = player->hands[HAND_RIGHT].mm_rcpremainder;

				if (amount > player->ammoheldarr[ctrl->ammotypes[0]]) {
					amount = player->ammoheldarr[ctrl->ammotypes[0]];
				}

				player->ammoheldarr[ctrl->ammotypes[0]] -= amount;
			}

			if (weaponnum == WEAPON_HORIZONSCANNER) {
				g_Vars.currentplayer->zoomintimemax = 0;
				g_Vars.currentplayer->zoomintime = g_Vars.currentplayer->zoomintimemax;
				g_Vars.currentplayer->zoominfovynew = 60;
				g_Vars.currentplayer->zoominfovy = g_Vars.currentplayer->zoominfovynew;
			}

			lefthand = &player->hands[HAND_LEFT];
			righthand = &player->hands[HAND_RIGHT];

			if (ctrl->switchtoweaponnum == WEAPON_NONE) {
				lefthand->inuse = false;
				righthand->inuse = false;
				ctrl->weaponnum = WEAPON_NONE;
			} else {
				bgun_set_gun_mem_weapon(ctrl->switchtoweaponnum);
				ctrl->weaponnum = ctrl->switchtoweaponnum;
				lefthand->inuse = true;
				righthand->inuse = true;
			}

			if (ctrl->weaponnum == WEAPON_REMOTEMINE) {
				ctrl->dualwielding = true;
			}

			if (!ctrl->dualwielding) {
				lefthand->inuse = false;
			}

			if (weaponnum <= WEAPON_PSYCHOSISGUN && weaponnum >= WEAPON_UNARMED) {
				player->gunctrl.prevweaponnum = weaponnum;
			}

			if (previnuse) {
				player->gunctrl.prevwasdualwielding = true;
			} else {
				player->gunctrl.prevwasdualwielding = false;
			}

			g_Vars.currentplayer->gunctrl.invertgunfunc = false;
			g_Vars.currentplayer->usedowntime = -1;

			for (i = 0; i < 2; i++) {
				player->hands[i].ejectstate = EJECTSTATE_INACTIVE;
				player->hands[i].ejecttype = EJECTTYPE_GUN;
				player->hands[i].unk0d0f_02 = false;
				player->hands[i].activatesecondary = false;

				player->hands[i].matmot1 = 0.0f;
				player->hands[i].matmot2 = 0.0f;
				player->hands[i].matmot3 = 0.0f;
				player->hands[i].angledamper = 0.0f;
				player->hands[i].gunsmokepoint = 0.0f;
				player->hands[i].burstbullets = 0;
				player->hands[i].loadslide = 0.0f;
				player->hands[i].allowshootframe = 0;
				player->hands[i].lastshootframe60 = 0;
				player->hands[i].gset.weaponfunc = FUNC_PRIMARY;
				player->hands[i].gset.weaponnum = ctrl->weaponnum;
				player->hands[i].gset.upgradewant = (ctrl->upgradewant >> (i * 4)) & 0xf;
				player->hands[i].gangstarot = 0.0f;

				bgun0f0abd30(i);

				anim_init(&player->hands[i].anim);

				if (player->hands[i].audiohandle && sndGetState(player->hands[i].audiohandle) != AL_STOPPED) {
					audioStop(player->hands[i].audiohandle);
				}
			}

			inv_calculate_current_index();

			ctrl->switchtoweaponnum = -1;
			ctrl->fnfader = 0;

			if (ctrl->weaponnum == WEAPON_DISGUISE40 || ctrl->weaponnum == WEAPON_DISGUISE41) {
				struct chrdata *chr = player->prop->chr;

				snd_start(var80095200, SFX_DISGUISE_ON, 0, -1, -1, -1, -1, -1);

				g_Vars.currentplayer->disguised = true;

				chr->hidden |= CHRHFLAG_DISGUISED;

				if (g_Vars.stagenum == STAGE_RESCUE) {
					chr->hidden |= CHRHFLAG_UNTARGETABLE;
				}

				inv_remove_item_by_num(ctrl->weaponnum);
				bgun_cycle_back();
			}

			ctrl->curfnstr = 0;
			ctrl->fnstrtimer = 0;
			ctrl->throwing = false;
		}
	} else {
		if (((player->hands[HAND_LEFT].inuse && !player->gunctrl.dualwielding)
					|| (!player->hands[HAND_LEFT].inuse && player->gunctrl.dualwielding))
				&& bgun_can_free_weapon(HAND_LEFT)) {
			bgun_free_weapon(HAND_LEFT);
			player->hands[HAND_LEFT].inuse = player->gunctrl.dualwielding;
		}
	}
}

void bgun_equip_weapon(s32 weaponnum)
{
	struct player *player = g_Vars.currentplayer;

	if (player->gunctrl.weaponnum == weaponnum && player->gunctrl.switchtoweaponnum == -1) {
		return;
	}

	player->gunctrl.switchtoweaponnum = weaponnum;
	player->gunctrl.wantammo = false;
}

s32 bgun_get_weapon_num(s32 handnum)
{
	if (!g_Vars.currentplayer->hands[handnum].inuse) {
		return WEAPON_NONE;
	}

	return g_Vars.currentplayer->gunctrl.weaponnum;
}

s32 bgun_get_weapon_num2(s32 handnum)
{
	return bgun_get_weapon_num(handnum);
}

bool bgun0f0a1a10(s32 weaponnum)
{
	if (gset_has_weapon_flag(weaponnum, WEAPONFLAG_00000400)
			&& (bgun_get_ammo_type_for_weapon(weaponnum, FUNC_PRIMARY) == 0 || bgun_get_ammo_qty_for_weapon(weaponnum, FUNC_PRIMARY) > 0)) {
		return true;
	}

	return false;
}

s32 bgun_get_switch_to_weapon(s32 handnum)
{
	s32 weaponnum;

	if (g_Vars.currentplayer->gunctrl.switchtoweaponnum >= 0) {
		weaponnum = g_Vars.currentplayer->gunctrl.switchtoweaponnum;
	} else {
		weaponnum = g_Vars.currentplayer->gunctrl.weaponnum;
	}

	if (!g_Vars.currentplayer->gunctrl.dualwielding && handnum == HAND_LEFT) {
		weaponnum = WEAPON_NONE;
	}

	return weaponnum;
}

void bgun_switch_to_previous(void)
{
	if (g_Vars.tickmode != TICKMODE_CUTSCENE) {
		struct player *player = g_Vars.currentplayer;
		s32 dualweaponnum;

#if VERSION >= VERSION_NTSC_1_0
		if (inv_has_single_weapon_inc_all_guns(player->gunctrl.prevweaponnum)) {
			bgun_equip_weapon2(HAND_RIGHT, player->gunctrl.prevweaponnum);

			dualweaponnum = inv_has_double_weapon_inc_all_guns(player->gunctrl.prevweaponnum, player->gunctrl.prevweaponnum)
				* player->gunctrl.prevweaponnum * player->gunctrl.prevwasdualwielding;
			bgun_equip_weapon2(HAND_LEFT, dualweaponnum);
		} else {
			bgun_auto_switch_weapon();
		}
#else
		bgun_equip_weapon2(HAND_RIGHT, player->gunctrl.prevweaponnum);
		bgun_equip_weapon2(HAND_LEFT, player->gunctrl.prevweaponnum * player->gunctrl.prevwasdualwielding);
#endif
	}
}

void bgun_cycle_forward(void)
{
	s32 weaponnum1;
	s32 weaponnum2;
	struct player *player = g_Vars.currentplayer;

	if (g_Vars.tickmode != TICKMODE_CUTSCENE) {
		weaponnum1 = bgun_get_switch_to_weapon(HAND_RIGHT);
		weaponnum2 = bgun_get_switch_to_weapon(HAND_LEFT);

		if (weaponnum1 > WEAPON_PSYCHOSISGUN || weaponnum2 > WEAPON_PSYCHOSISGUN) {
			weaponnum1 = player->gunctrl.prevweaponnum;
			weaponnum2 = player->gunctrl.prevweaponnum * player->gunctrl.prevwasdualwielding;
		} else {
			inv_choose_cycle_forward_weapon(&weaponnum1, &weaponnum2, false);
		}

		if (weaponnum2 != weaponnum1) {
			player->gunctrl.dualwielding = false;
		} else {
			player->gunctrl.dualwielding = true;
		}

		bgun_equip_weapon(weaponnum1);
	}
}

void bgun_cycle_back(void)
{
	s32 weaponnum1;
	s32 weaponnum2;
	struct player *player = g_Vars.currentplayer;

	if (g_Vars.tickmode != TICKMODE_CUTSCENE) {
		weaponnum1 = bgun_get_switch_to_weapon(HAND_RIGHT);
		weaponnum2 = bgun_get_switch_to_weapon(HAND_LEFT);

		if (weaponnum2 == WEAPON_REMOTEMINE) {
			weaponnum2 = WEAPON_NONE;
		}

		if (weaponnum1 > WEAPON_PSYCHOSISGUN || weaponnum2 > WEAPON_PSYCHOSISGUN) {
			weaponnum1 = player->gunctrl.prevweaponnum;
			weaponnum2 = player->gunctrl.prevweaponnum * player->gunctrl.prevwasdualwielding;
		} else {
			inv_choose_cycle_back_weapon(&weaponnum1, &weaponnum2, false);
		}

		if (weaponnum2 == WEAPON_NONE) {
			player->gunctrl.dualwielding = false;
		} else {
			player->gunctrl.dualwielding = true;
		}

		bgun_equip_weapon(weaponnum1);
	}
}

/**
 * Return true if the player has ammo for the given weapon (for either function)
 * or if the weapon doesn't support ammo.
 *
 * Used by the active menu to colour the slots.
 */
bool bgun_has_ammo_for_weapon(s32 weaponnum)
{
	bool ammodefexists = false;
	bool hasammo = false;
	struct weapondef *weapon = gset_get_weapondef(weaponnum);
	s32 i;

	if (weapon == NULL) {
		return true;
	}

	for (i = 0; i < 2; i++) {
		struct funcdef *func = gset_get_funcdef_by_weaponnum_funcnum(weaponnum, i);

		if (func && func->ammoindex >= 0) {
			struct ammodef *ammo = weapon->ammos[func->ammoindex];

			if (ammo) {
				ammodefexists = true;

				if (bgun_get_ammo_count(ammo->type) > 0) {
					hasammo = true;
				}
			}
		}
	}

	if (!ammodefexists) {
		return true;
	}

	if (hasammo == true) {
		return true;
	}

	return false;
}

u8 g_AutoSwitchWeaponsPrimary[] = {
	WEAPON_RCP120,
	WEAPON_SUPERDRAGON, // primary function
	WEAPON_K7AVENGER,
	WEAPON_AR34,
	WEAPON_CALLISTO,
	WEAPON_LAPTOPGUN,
	WEAPON_DRAGON,
	WEAPON_CMP150,
	WEAPON_CYCLONE,
	WEAPON_FARSIGHT,
	WEAPON_SHOTGUN,
	WEAPON_REAPER,
	WEAPON_DY357LX,
	WEAPON_MAULER,
	WEAPON_DY357MAGNUM,
	WEAPON_MAGSEC4,
	WEAPON_PHOENIX,
	WEAPON_FALCON2_SCOPE,
	WEAPON_FALCON2,
	WEAPON_FALCON2_SILENCER,
	WEAPON_SNIPERRIFLE,
	WEAPON_CROSSBOW,
	WEAPON_TRANQUILIZER,
	WEAPON_LASER,
	WEAPON_SUPERDRAGON, // secondary function
	WEAPON_DEVASTATOR,
	WEAPON_ROCKETLAUNCHER,
	WEAPON_SLAYER,
	WEAPON_GRENADE,
	WEAPON_NBOMB,
	WEAPON_PROXIMITYMINE,
	WEAPON_TIMEDMINE,
	WEAPON_REMOTEMINE,
	WEAPON_COMBATKNIFE,
	WEAPON_UNARMED,
};

u8 g_AutoSwitchWeaponsSecondary[] = {
	WEAPON_REAPER,
	WEAPON_DY357LX,
	WEAPON_DY357MAGNUM,
	WEAPON_FALCON2_SCOPE,
	WEAPON_FALCON2,
	WEAPON_FALCON2_SILENCER,
	WEAPON_UNARMED,
};

/**
 * Automatically choose and equip a new weapon after trying to fire a weapon
 * which is out of ammo.
 *
 * The weapon preference order is stored in two arrays; one for weapons which
 * should have their primary functions considered and which require ammo, and
 * another for weapons which should have their secondary functions considered
 * and don't require ammo for those functions. The second is only used if no
 * weapons are usable from the primary array.
 *
 * For the primary array, the weapon must not be out of ammo. If the player's
 * current weapon is not in the primary array then the first available primary
 * will be selected. If the player's current weapon is in the primary array then
 * the last available weapon earlier than their current weapon will be selected.
 * If there are no weapons earlier than their current weapon then the first
 * weapon after their current weapon is selected.
 *
 * In the primary array, the SuperDragon is a special case and appears twice.
 * The first use is for the primary function while the second use is for the
 * secondary function.
 *
 * For the secondary array, the player's current weapon must not be in the
 * array. The first available weapon is selected. The player's "wantammo" flag
 * will be set which will force the weapon onto the second function.
 */
void bgun_auto_switch_weapon(void)
{
	s32 i;
	struct weapondef *weapon;
	struct funcdef *func;
	s32 weaponnum;
	s32 newweaponnum = -1;
	s32 firstweaponnum = -1;
	s32 foundsuperdragon = 0;
	bool foundcurrent = false;
	s32 curweaponnum = g_Vars.currentplayer->gunctrl.weaponnum;
	bool wantammo = false;

	if (g_Vars.tickmode == TICKMODE_CUTSCENE) {
		return;
	}

	// Loop through g_AutoSwitchWeaponsPrimary, checking which weapons the
	// player has which are usable. Stop when both a usable weapon is found
	// and when the player's current weapon is found. Note the first and last
	// usable weapons.
	i = 0;

	do {
		bool usable = false;

		if (inv_has_single_weapon_inc_all_guns(g_AutoSwitchWeaponsPrimary[i])) {
			weaponnum = g_AutoSwitchWeaponsPrimary[i];
			weapon = gset_get_weapondef(weaponnum);
			func = gset_get_funcdef_by_weaponnum_funcnum(weaponnum, FUNC_PRIMARY);

			if (!bgun0f0990b0(func, weapon) && (func->flags & FUNCFLAG_AUTOSWITCHUNSELECTABLE) == 0) {
				usable = true;
			}

			if (weaponnum == WEAPON_SUPERDRAGON && !foundsuperdragon) {
				foundsuperdragon++;
			} else {
				func = gset_get_funcdef_by_weaponnum_funcnum(weaponnum, FUNC_SECONDARY);

				if (!bgun0f0990b0(func, weapon) && (func->flags & FUNCFLAG_AUTOSWITCHUNSELECTABLE) == 0) {
					usable = true;
				}
			}

			if (weaponnum == curweaponnum) {
				foundcurrent = true;
			} else if (usable) {
				newweaponnum = weaponnum;

				if (firstweaponnum == -1) {
					firstweaponnum = weaponnum;
				}
			}
		}

		if (++i >= ARRAYCOUNT(g_AutoSwitchWeaponsPrimary)) {
			break;
		}
	} while (newweaponnum == -1 || !foundcurrent);

	if (!foundcurrent) {
		newweaponnum = firstweaponnum;
	}

	if (newweaponnum == -1) {
		newweaponnum = WEAPON_UNARMED;
	}

	if (newweaponnum == WEAPON_UNARMED) {
		bool foundcurrent = false;
		s32 firstweaponnum = -1;
		s32 weaponnum;

		// No usable weapon was found in the primary array,
		// so search the secondary array.
		for (i = 0; i < ARRAYCOUNT(g_AutoSwitchWeaponsSecondary); i++) {
			weaponnum = g_AutoSwitchWeaponsSecondary[i];

			if (inv_has_single_weapon_inc_all_guns(weaponnum)) {
				if (weaponnum == curweaponnum) {
					foundcurrent = true;
				}

				if (firstweaponnum == -1) {
					firstweaponnum = weaponnum;
				}
			}
		}

		newweaponnum = firstweaponnum;

		if (newweaponnum == -1) {
			newweaponnum = WEAPON_UNARMED;
		}

		if (foundcurrent) {
			newweaponnum = -1;
		}

		wantammo = true;
	}

	// Switch to newweaponnum
	if (newweaponnum >= 0 && newweaponnum != curweaponnum) {
		if (inv_has_double_weapon_inc_all_guns(newweaponnum, newweaponnum)) {
			g_Vars.currentplayer->gunctrl.dualwielding = true;
		} else {
			g_Vars.currentplayer->gunctrl.dualwielding = false;
		}

		bgun_equip_weapon(newweaponnum);

		if (wantammo) {
			g_Vars.currentplayer->gunctrl.wantammo = true;
		}
	}
}

void bgun_equip_weapon2(s32 handnum, s32 weaponnum)
{
	if (handnum == HAND_LEFT) {
		if (weaponnum == WEAPON_NONE) {
			g_Vars.currentplayer->gunctrl.dualwielding = false;
		} else {
			g_Vars.currentplayer->gunctrl.dualwielding = true;
		}
	} else {
		if (weaponnum > WEAPON_SUICIDEPILL) {
			weaponnum = WEAPON_UNARMED;
		}

		bgun_equip_weapon(weaponnum);
	}
}

s32 bgun_is_firing(s32 handnum)
{
	return g_Vars.currentplayer->hands[handnum].firing;
}

s32 bgun_get_attack_type(s32 handnum)
{
	return g_Vars.currentplayer->hands[handnum].attacktype;
}

char *bgun_get_name(s32 weaponnum)
{
	struct weapondef *weapon = g_Weapons[weaponnum];

	if (weapon) {
		return lang_get(weapon->name);
	}

	return "** error\n";
}

u16 bgun_get_name_id(s32 weaponnum)
{
	struct weapondef *weapon = g_Weapons[weaponnum];

	if (weapon) {
		return weapon->name;
	}

	return 0;
}

char *bgun_get_short_name(s32 weaponnum)
{
	struct weapondef *weapon = g_Weapons[weaponnum];

	if (weapon) {
		return lang_get(weapon->shortname);
	}

	return "** error\n";
}

const char var7f1ac170[] = "wantedfn %d tiggle %d\n";

void bgun_reload_if_possible(s32 handnum)
{
	struct player *player = g_Vars.currentplayer;

	if (bgun_get_ammo_type_for_weapon(bgun_get_weapon_num(handnum), FUNC_PRIMARY)
			&& player->hands[handnum].modenext == HANDMODE_NONE) {
		player->hands[handnum].modenext = HANDMODE_RELOAD;
	}
}

void bgun_set_adjust_pos(f32 angle)
{
	struct player *player = g_Vars.currentplayer;

	player->hands[0].adjustpos.z = (1 - cosf(angle)) * 5;
	player->hands[1].adjustpos.z = (1 - cosf(angle)) * 5;
}

void bgun_start_slide(s32 handnum)
{
	g_Vars.currentplayer->hands[handnum].slideinc = true;
}

/**
 * Update the slide on weapons which have them (eg. Falcon 2).
 *
 * The slide moves back and then forward when firing. If the gun no longer has
 * any ammo loaded in it, the slide moves back and remains in the back position.
 */
void bgun_update_slide(s32 handnum)
{
	f32 slidemax = 0.0f;
	struct funcdef *funcdef = gset_get_current_funcdef(handnum);
	struct player *player = g_Vars.currentplayer;

	if (funcdef && ((funcdef->type & 0xff) == INVENTORYFUNCTYPE_SHOOT)) {
		struct funcdef_shoot *shootfunc = (struct funcdef_shoot *)funcdef;
		slidemax = shootfunc->slidemax;
	}

	if (player->hands[handnum].slideinc) {
		// Slide is moving backwards
		if (player->hands[handnum].slidetrans < slidemax) {
			player->hands[handnum].slidetrans += slidemax * 0.25f * g_Vars.lvupdate60freal;
		}

		if (player->hands[handnum].slidetrans >= slidemax) {
			player->hands[handnum].slidetrans = slidemax;
			player->hands[handnum].slideinc = false;
		}
	} else if (player->hands[handnum].loadedammo[FUNC_PRIMARY] > 0) {
		if (bgun_anim_allows_feature(&player->hands[handnum], GUNFEATURE_ATTACKAGAIN)) {
			// Slide is moving forwards
			if (player->hands[handnum].slidetrans > 0.0f) {
				player->hands[handnum].slidetrans -= slidemax * 0.16666667f * g_Vars.lvupdate60freal;
			}

			if (player->hands[handnum].slidetrans < 0.0f) {
				player->hands[handnum].slidetrans = 0.0f;
			}
		}
	}
}

f32 bgun0f0a2498(f32 arg0, f32 arg1, f32 arg2, f32 arg3)
{
	f32 a = arg0 - arg2;

	return asinf(a / sqrtf(a * a + (arg1 - arg3) * (arg1 - arg3)));
}

void bgun0f0a24f0(struct coord *arg0, s32 handnum)
{
	struct coord b;
	struct coord a;

	bgun0f0a0c44(handnum, &a, &b);

	b.x *= 1000;
	b.y *= 1000;
	b.z *= 1000;

	arg0->x = b.x;
	arg0->y = b.y;
	arg0->z = b.z;
}

/**
 * This function is a callback that is passed to model code.
 */
void bgun0f0a256c(s32 mtxindex, Mtxf *mtx)
{
	Mtxf sp78;
	Mtxf sp38;
	struct coord rot;

	if (mtxindex == var8009d148) {
		if (var8009d144->ejectstate == EJECTSTATE_INIT) {
			var8009d144->unk0d14 = mtx->m[3][0];
			var8009d144->unk0d18 = mtx->m[3][1];
			var8009d144->unk0d1c = mtx->m[3][2];

			var8009d144->unk0d2c[0][0] = mtx->m[0][0];
			var8009d144->unk0d2c[0][1] = mtx->m[0][1];
			var8009d144->unk0d2c[0][2] = mtx->m[0][2];
			var8009d144->unk0d2c[1][0] = mtx->m[1][0];
			var8009d144->unk0d2c[1][1] = mtx->m[1][1];
			var8009d144->unk0d2c[1][2] = mtx->m[1][2];
			var8009d144->unk0d2c[2][0] = mtx->m[2][0];
			var8009d144->unk0d2c[2][1] = mtx->m[2][1];
			var8009d144->unk0d2c[2][2] = mtx->m[2][2];
		} else if (var8009d144->ejectstate >= EJECTSTATE_AIRBORNE) {
			mtx->m[3][0] = var8009d144->unk0d14;
			mtx->m[3][1] = var8009d144->unk0d18;
			mtx->m[3][2] = var8009d144->unk0d1c;

			mtx->m[0][0] = var8009d144->unk0d2c[0][0];
			mtx->m[0][1] = var8009d144->unk0d2c[0][1];
			mtx->m[0][2] = var8009d144->unk0d2c[0][2];
			mtx->m[1][0] = var8009d144->unk0d2c[1][0];
			mtx->m[1][1] = var8009d144->unk0d2c[1][1];
			mtx->m[1][2] = var8009d144->unk0d2c[1][2];
			mtx->m[2][0] = var8009d144->unk0d2c[2][0];
			mtx->m[2][1] = var8009d144->unk0d2c[2][1];
			mtx->m[2][2] = var8009d144->unk0d2c[2][2];
		}
	}

	if (mtxindex == var8009d0dc) {
		rot.x = 0.0f;
		rot.y = 0.0f;
		rot.z = var8009d140;

		mtx4_load_identity(&sp78);
		mtx4_load_rotation(&rot, &sp78);
		mtx4_mult_mtx4(mtx, &sp78, &sp38);
		mtx4_copy(&sp38, mtx);
	}

	if (mtxindex == var8009d0f0[0] || mtxindex == var8009d0f0[1] || mtxindex == var8009d0f0[2]) {
		rot.x = 0.0f;
		rot.y = 0.0f;
		rot.z = 2.0f * -var8009d140;

		mtx4_load_identity(&sp78);
		mtx4_load_rotation(&rot, &sp78);
		mtx4_mult_mtx4(mtx, &sp78, &sp38);
		mtx4_copy(&sp38, mtx);
	}
}

bool bgun_allows_fullscreen_autoaim(void)
{
	struct hand *hand;
	struct funcdef *func;

	// Right hand
	hand = &g_Vars.currentplayer->hands[HAND_RIGHT];

	if (1) {
		func = gset_get_funcdef_by_gset2(&hand->gset);

		if (func
				&& (func->type & 0xff) == INVENTORYFUNCTYPE_MELEE
				&& hand->state == HANDSTATE_ATTACK
				&& hand->animcmd != NULL
				&& hand->animmode == HANDANIMMODE_BUSY
				&& !bgun_anim_allows_feature(hand, GUNFEATURE_ATTACK)) {
			return true;
		}
	}

	// Left hand
	hand = &g_Vars.currentplayer->hands[HAND_LEFT];

	if (hand->inuse) {
		func = gset_get_funcdef_by_gset2(&hand->gset);

		if (func
				&& (func->type & 0xff) == INVENTORYFUNCTYPE_MELEE
				&& hand->state == HANDSTATE_ATTACK
				&& hand->animcmd != NULL
				&& hand->animmode == HANDANIMMODE_BUSY
				&& !bgun_anim_allows_feature(hand, GUNFEATURE_ATTACK)) {
			return true;
		}
	}

	return false;
}

/**
 * This function is the same as above but it doesn't call bgun_anim_allows_feature().
 *
 * This function is unused.
 */
bool bgun_allows_fullscreen_autoaim2(void)
{
	struct hand *hand;
	struct funcdef *func;

	hand = &g_Vars.currentplayer->hands[HAND_RIGHT];
	func = gset_get_funcdef_by_gset2(&hand->gset);

	if (func
			&& (func->type & 0xff) == INVENTORYFUNCTYPE_MELEE
			&& hand->state == HANDSTATE_ATTACK
			&& hand->animcmd != NULL
			&& hand->animmode == HANDANIMMODE_BUSY) {
		return true;
	}

	hand = &g_Vars.currentplayer->hands[HAND_LEFT];

	if (hand->inuse) {
		func = gset_get_funcdef_by_gset2(&hand->gset);

		if (func
				&& (func->type & 0xff) == INVENTORYFUNCTYPE_MELEE
				&& hand->state == HANDSTATE_ATTACK
				&& hand->animcmd != NULL
				&& hand->animmode == HANDANIMMODE_BUSY) {
			return true;
		}
	}

	return false;
}

void bgun_handle_player_dead(void)
{
	struct player *player = g_Vars.currentplayer;
	s32 i;

	if (player->gunctrl.weaponnum != WEAPON_NONE && player->gunctrl.switchtoweaponnum != WEAPON_NONE) {
		// Eject held weapons
		if (player->hands[HAND_LEFT].inuse) {
			player->hands[HAND_LEFT].ejectstate = EJECTSTATE_INIT;
			player->hands[HAND_LEFT].ejecttype = EJECTTYPE_GUN;
		}

		if (player->hands[HAND_RIGHT].inuse) {
			player->hands[HAND_RIGHT].ejectstate = EJECTSTATE_INIT;
			player->hands[HAND_RIGHT].ejecttype = EJECTTYPE_GUN;
		}

		for (i = 0; i < 2; i++) {
			player->hands[i].matmot1 = 0;
			player->hands[i].matmot2 = 0;
			player->hands[i].matmot3 = 0;

			bgun_set_state(i, HANDSTATE_IDLE);
		}

		bgun_equip_weapon2(HAND_LEFT, WEAPON_NONE);
		bgun_equip_weapon2(HAND_RIGHT, WEAPON_NONE);
	}
}

#if VERSION >= VERSION_NTSC_1_0
bool bgun_is_mission_critical(s32 weaponnum)
{
	if (weaponnum == WEAPON_TIMEDMINE
			|| weaponnum == WEAPON_REMOTEMINE
			|| weaponnum == WEAPON_ECMMINE
			|| weaponnum == WEAPON_TRACERBUG) {
		return true;
	}

	return false;
}
#endif

void bgun_disarm(struct prop *attackerprop)
{
	struct player *player = g_Vars.currentplayer;
	s32 weaponnum = player->hands[0].gset.weaponnum;
	struct chrdata *chr;
	s32 modelnum;
	s32 i;
	bool drop;

	if (!gset_has_weapon_flag(weaponnum, WEAPONFLAG_UNDROPPABLE) && weaponnum <= WEAPON_RCP45) {
#if VERSION >= VERSION_NTSC_1_0
		// Coop must not allow player to drop a mission critical weapon
		// because AI lists can fail the mission if the player has zero
		// quantity.
		if (g_Vars.coopplayernum >= 0
				&& (attackerprop == g_Vars.bond->prop || attackerprop == g_Vars.coop->prop)
				&& bgun_is_mission_critical(weaponnum)) {
			return;
		}
#endif

		if (weaponnum <= WEAPON_UNARMED || player->gunctrl.switchtoweaponnum != -1) {
			return;
		}

		chr = player->prop->chr;
		drop = true;

		// RC-P120 and cloaking device: turn off cloak if active
		if (weaponnum == WEAPON_RCP120) {
			g_Vars.currentplayer->devicesactive &= ~DEVICE_CLOAKRCP120;
		}

		if (weaponnum == WEAPON_CLOAKINGDEVICE) {
			g_Vars.currentplayer->devicesactive &= ~DEVICE_CLOAKDEVICE;
		}

		// Grenade and nbomb: if pin is pulled, throw it?
		// Or drop it at player's feet with the pin pulled maybe...
		if (weaponnum == WEAPON_GRENADE || weaponnum == WEAPON_NBOMB) {
			for (i = 0; i < 2; i++) {
				struct funcdef *func = gset_get_funcdef_by_gset(&player->hands[i].gset);

				if ((func->type & 0xff) == INVENTORYFUNCTYPE_THROW
						&& player->hands[i].state == HANDSTATE_ATTACK
						&& player->hands[i].stateminor == HANDSTATEMINOR_ATTACK_THROW_0) {
					drop = false;
					bgun_create_thrown_projectile(i + 2, &player->hands[i].gset);
				}
			}
		}

		weapon_delete_from_chr(chr, HAND_RIGHT);
		weapon_delete_from_chr(chr, HAND_LEFT);

		// Actually drop the weapon
		modelnum = playermgr_get_model_of_weapon(weaponnum);

		if (modelnum >= 0 && drop) {
			struct prop *prop2 = weapon_create_for_chr(chr, modelnum, weaponnum, OBJFLAG_WEAPON_AICANNOTUSE, NULL, NULL);

			if (prop2 && prop2->obj) {
				struct defaultobj *obj = prop2->obj;
				obj_set_dropped(prop2, DROPTYPE_DEFAULT);

				if (obj->hidden & OBJHFLAG_PROJECTILE) {
					obj->projectile->pickuptimer240 = TICKS(240);
					obj->projectile->pickupby = attackerprop;
				}

				obj_drop(prop2, true);
			}
		}

		inv_remove_item_by_num(weaponnum);

		player->hands[1].state = HANDSTATE_IDLE;
		player->hands[1].ejectstate = EJECTSTATE_INIT;
		player->hands[1].ejecttype = EJECTTYPE_GUN;
		player->hands[0].ejectstate = EJECTSTATE_INIT;
		player->hands[0].ejecttype = EJECTTYPE_GUN;
		player->hands[0].state = HANDSTATE_IDLE;

		// Exit slayer rocket mode if player was using it
		if (player->visionmode == VISIONMODE_SLAYERROCKET) {
			struct weaponobj *rocket = g_Vars.currentplayer->slayerrocket;

			if (rocket && rocket->base.prop) {
				rocket->timer240 = 0;
			}

			player->visionmode = VISIONMODE_NORMAL;
		}

		bgun_equip_weapon2(HAND_RIGHT, WEAPON_UNARMED);
		bgun_equip_weapon2(HAND_LEFT, WEAPON_NONE);
	}
}

/**
 * Execute some sort of command list that was generated by the function below.
 *
 * With this function stubbed, part of the CMP150 model does not render.
 */
void bgun_execute_model_cmd_list(s32 *ptr)
{
	union modelrwdata *rwdata;
	struct modelnode *node;

	if (ptr != NULL) {
		while (*ptr != 6) {
			switch (*ptr) {
			case 0:
				rwdata = (union modelrwdata *)ptr[1];
				node = (struct modelnode *)ptr[2];
				rwdata->distance.visible = false;
				node->child = (struct modelnode *)ptr[3];
				ptr += 4;
				break;
			case 1:
				rwdata = (union modelrwdata *)ptr[1];
				node = (struct modelnode *)ptr[2];
				rwdata->toggle.visible = true;
				node->child = (struct modelnode *)ptr[3];
				ptr += 4;
				break;
			case 2:
				rwdata = (union modelrwdata *)ptr[1];
				rwdata->headspot.headmodeldef = NULL;
				rwdata->headspot.rwdatas = NULL;
				ptr += 2;
				break;
			case 3:
				rwdata = (union modelrwdata *)ptr[1];
				rwdata->type0b.unk00 = 0;
				ptr += 2;
				break;
			case 4:
				rwdata = (union modelrwdata *)ptr[1];
				rwdata->chrgunfire.visible = false;
				ptr += 2;
				break;
			case 5:
				rwdata = (union modelrwdata *)ptr[1];
				rwdata->dl.vertices = (Vtx *)ptr[2];
				rwdata->dl.gdl = (Gfx *)ptr[3];
				rwdata->dl.colours = (Col *)ptr[4];
				ptr += 5;
				break;
			}
		}
	}
}

/**
 * Generate some sort of command list to be executed by the function above.
 *
 * This appears to be a performance optimisation, so the tick code can quickly
 * iterate the command list to update part visibility rather than iterate the
 * full model tree.
 */
s32 bgun_create_model_cmd_list(struct model *model, struct modelnode *nodearg, s32 *ptr)
{
	s32 len = 0;
	struct modelnode *node = nodearg;
	union modelrodata *rodata;
	union modelrwdata *rwdata;

	while (node) {
		u32 type = node->type;

		switch ((u8)type) {
		case MODELNODETYPE_DISTANCE:
			rodata = node->rodata;
			rwdata = model_get_node_rw_data(model, node);
			rwdata->distance.visible = false;
			node->child = rodata->distance.target;
			ptr[0] = 0;
			ptr[1] = (s32)rwdata;
			ptr[2] = (s32)node;
			ptr[3] = (s32)rodata->distance.target;
			ptr += 4;
			len += 16;
			break;
		case MODELNODETYPE_TOGGLE:
			rodata = node->rodata;
			rwdata = model_get_node_rw_data(model, node);
			rwdata->toggle.visible = true;
			node->child = rodata->toggle.target;
			ptr[0] = 1;
			ptr[1] = (s32)rwdata;
			ptr[2] = (s32)node;
			ptr[3] = (s32)rodata->toggle.target;
			ptr += 4;
			len += 16;
			break;
		case MODELNODETYPE_HEADSPOT:
			rwdata = model_get_node_rw_data(model, node);
			rwdata->headspot.headmodeldef = NULL;
			rwdata->headspot.rwdatas = NULL;
			ptr[0] = 2;
			ptr[1] = (s32)rwdata;
			ptr += 2;
			len += 8;
			break;
		case MODELNODETYPE_0B:
			rwdata = model_get_node_rw_data(model, node);
			rwdata->type0b.unk00 = 0;
			ptr[0] = 3;
			ptr[1] = (s32)rwdata;
			ptr += 2;
			len += 8;
			break;
		case MODELNODETYPE_CHRGUNFIRE:
			rwdata = model_get_node_rw_data(model, node);
			rwdata->chrgunfire.visible = false;
			ptr[0] = 4;
			ptr[1] = (s32)rwdata;
			ptr += 2;
			len += 8;
			break;
		case MODELNODETYPE_DL:
			rodata = node->rodata;
			rwdata = model_get_node_rw_data(model, node);
			rwdata->dl.vertices = rodata->dl.vertices;
			rwdata->dl.gdl = rodata->dl.opagdl;
			rwdata->dl.colours = (void *)ALIGN8((uintptr_t)&rodata->dl.vertices[rodata->dl.numvertices]);
			ptr[0] = 5;
			ptr[1] = (s32)rwdata;
			ptr[2] = (s32)rwdata->dl.vertices;
			ptr[3] = (s32)rwdata->dl.gdl;
			ptr[4] = (s32)rwdata->dl.colours;
			ptr += 5;
			len += 20;
			break;
		}

		if (node->child) {
			node = node->child;
		} else {
			while (node) {
				if (node == nodearg->parent) {
					node = NULL;
					break;
				}

				if (node->next) {
					node = node->next;
					break;
				}

				node = node->parent;
			}
		}
	}

	*ptr = 6;
	len += 4;

	return len;
}

u32 var800701ec = 0x00000000;
u32 var800701f0 = 0x00000000;
u32 var800701f4 = 0x00000000;
u32 var800701f8 = 0x00000000;
u32 var800701fc = 0x00000000;

struct guncmd var80070200[2] = {
	{ GUNCMD_PLAYANIMATION, 0, ANIM_0434, 10000 },
	{ GUNCMD_END },
};

void bgun_start_detonate_animation(s32 playernum)
{
	s32 prevplayernum = g_Vars.currentplayernum;
	set_current_player_num(playernum);

	if (g_Vars.currentplayer->hands[HAND_LEFT].gset.weaponnum == WEAPON_REMOTEMINE) {
		bgun_start_animation(var80070200, 1, &g_Vars.currentplayer->hands[HAND_LEFT]);
	}

	set_current_player_num(prevplayernum);
}

/**
 * Update the gangsta-style rotation of the player's gun.
 *
 * When close to an enemy and aiming at them with a pistol, the gun is rotated
 * sideways. The enemy and aiming check is done elsewhere (autoaim code) and
 * sets the gunctrl's gangsta property to true or false based on whether this
 * criteria is met on the current (or previous?) frame.
 *
 * bgun_update_gangsta uses this property and increments the rotation of the gun
 * accordingly. It also checks that the gun is in a state that allows gangsta
 * rotation (reloading and equip/unequip do not). It also implements a delay on
 * reverting to the normal rotation.
 */
void bgun_update_gangsta(struct hand *hand, s32 handnum, struct coord *arg2, struct funcdef *funcdef, Mtxf *arg4, Mtxf *arg5)
{
	f32 tmp;
	struct coord sp38 = {0, 0, 0};

	if (g_Vars.currentplayer->gunctrl.gangsta
			&& funcdef
			&& (funcdef->type & 0xff) == INVENTORYFUNCTYPE_SHOOT
			&& (hand->state == HANDSTATE_IDLE
				|| hand->state == HANDSTATE_2
				|| hand->state == HANDSTATE_ATTACKEMPTY
				|| hand->state == HANDSTATE_ATTACK)) {
		if (hand->gangstarot < 1.0f) {
			// Rotate into gangsta position
			hand->ispare1 += g_Vars.lvupdate240;

			if (hand->ispare1 > TICKS(60)) {
				hand->gangstarot += LVUPDATE60FREAL() / 30.0f;

				if (hand->gangstarot > 1.0f) {
					hand->gangstarot = 1.0f;
				}
			}
		} else {
			// Already in gangsta position
			hand->ispare1 = 0;
		}
	} else {
		// At this point we don't want the gun to be in the gangsta position.
		// However we don't want it to revert immediately, so a timer is used.
		f32 inversespeed = 30.0f;

		if (hand->animmode == HANDANIMMODE_BUSY) {
			// Revert faster
			inversespeed = 15.0f;
		}

		if (hand->gangstarot > 0.0f) {
			bool revert = false;

			hand->ispare1 += g_Vars.lvupdate240;

			if (hand->gangstarot < 1.0f) {
				hand->ispare1 = TICKS(244);
			}

			if (hand->ispare1 > TICKS(120)) {
				revert = true;
			}

			if (hand->animmode == HANDANIMMODE_BUSY && funcdef && (funcdef->type & 0xff) != INVENTORYFUNCTYPE_SHOOT) {
				revert = true;
			}

			if (hand->state != HANDSTATE_IDLE
					&& hand->state != HANDSTATE_2
					&& hand->state != HANDSTATE_ATTACKEMPTY
					&& hand->state != HANDSTATE_ATTACK) {
				revert = true;
			}

			if (revert) {
				hand->gangstarot -= LVUPDATE60FREAL() / inversespeed;
			}

			if (hand->gangstarot < 0.0f) {
				hand->gangstarot = 0.0f;
			}
		} else {
			// Not rotated
			hand->ispare1 = 0;
		}
	}

	tmp = -cosf(hand->gangstarot * DTOR(180)) * 0.5f + 0.50f;
	sp38.z = (tmp * 66.6f * 0.017453292f) * (handnum != HAND_RIGHT ? 1.0f : -1.0f);

	mtx4_load_rotation(&sp38, arg4);
	mtx00015be0(arg4, arg5);

	arg2->y += 4.0f * hand->gangstarot;
	arg2->x += 2.0f * hand->gangstarot * (handnum != HAND_RIGHT ? 1.0f : -1.0f);
}

/**
 * Check if smoke needs to be created at the muzzle of the current weapon.
 *
 * gunsmokepoint is basically the temperature of the gun. It increases when
 * firing and cools down when idle. It's only used for pistols; automatics will
 * create smoke based on the number of shots in the current burst.
 *
 * createsmoke must be set to create any smoke at all.
 *
 * forcecreatesmoke controls whether smoke should be created while the gun is
 * still firing.
 */
void bgun_update_smoke(struct hand *hand, s32 handnum, s32 weaponnum, struct funcdef *funcdef)
{
	if (hand->firing) {
		if (weaponnum == WEAPON_DY357MAGNUM || weaponnum == WEAPON_DY357LX) {
			if ((funcdef->type & 0xff) == INVENTORYFUNCTYPE_SHOOT) {
				hand->gunsmokepoint += 0.6f;
			}
		} else {
			hand->gunsmokepoint += 0.2f;
		}
	}

	hand->gunsmokepoint -= LVUPDATE60FREAL() / 120.0f;

	if (hand->gunsmokepoint < 0.0f) {
		hand->gunsmokepoint = 0.0f;
	}

	if (funcdef && (funcdef->type & 0xff) == INVENTORYFUNCTYPE_SHOOT) {
		f32 mult = 1.0f;

		if (g_Vars.currentplayer->hands[HAND_LEFT].inuse) {
			mult = 1.5f;
		}

		hand->forcecreatesmoke = false;

		switch (weaponnum) {
		case WEAPON_FALCON2:
		case WEAPON_FALCON2_SCOPE:
			if (hand->gunsmokepoint * mult > 0.66f) {
				hand->createsmoke = true;
			}
			break;
		case WEAPON_MAGSEC4:
		case WEAPON_MAULER:
			if (hand->gunsmokepoint * mult > 0.75f) {
				hand->createsmoke = true;
			}
			break;
		case WEAPON_DY357MAGNUM:
		case WEAPON_DY357LX:
			if (hand->gunsmokepoint * mult > 0.9f) {
				hand->createsmoke = true;
			}
			break;
		case WEAPON_CMP150:
		case WEAPON_DRAGON:
		case WEAPON_K7AVENGER:
		case WEAPON_AR34:
		case WEAPON_SUPERDRAGON:
			hand->forcecreatesmoke = true;

			if (hand->burstbullets > 14) {
				hand->createsmoke = true;
			}
			break;
		case WEAPON_CYCLONE:
		case WEAPON_LAPTOPGUN:
			if (hand->burstbullets > 20) {
				hand->createsmoke = true;
			}

			hand->forcecreatesmoke = true;
			break;
		case WEAPON_RCP120:
			hand->forcecreatesmoke = true;

			if (hand->burstbullets > 25) {
				hand->createsmoke = true;
			}
			break;
		case WEAPON_REAPER:
			hand->forcecreatesmoke = true;
			// fall-through
		case WEAPON_SHOTGUN:
			if (hand->firing) {
				hand->createsmoke = true;
			}
			break;
		}
	}

	if (hand->createsmoke && (hand->state != HANDSTATE_ATTACK || hand->forcecreatesmoke)) {
		struct coord smokepos;
		RoomNum smokerooms[2];
		s32 smoketype = SMOKETYPE_MUZZLE_AUTOMATIC;

		switch (weaponnum) {
		case WEAPON_FALCON2:
		case WEAPON_FALCON2_SCOPE:
		case WEAPON_MAGSEC4:
		case WEAPON_MAULER:
		case WEAPON_DY357MAGNUM:
		case WEAPON_DY357LX:
			smoketype = SMOKETYPE_MUZZLE_PISTOL;
			break;
		case WEAPON_REAPER:
			smoketype = SMOKETYPE_MUZZLE_REAPER;
			break;
		case WEAPON_SHOTGUN:
			smoketype = SMOKETYPE_MUZZLE_SHOTGUN;
			break;
		}

		smokerooms[0] = g_Vars.currentplayer->cam_room;
		smokerooms[1] = -1;

		smokepos.x = hand->muzzlepos.x;
		smokepos.y = hand->muzzlepos.y;
		smokepos.z = hand->muzzlepos.z;

		hand->gunsmokepoint = 0.0f;

		if (smoke_create_for_hand(&smokepos, smokerooms, smoketype, handnum)) {
			hand->createsmoke = false;
		}
	}
}

/**
 * Update the red beam and dot (used by the Falcon 2 and its variants).
 */
void bgun_update_lasersight(struct hand *hand, struct modeldef *modeldef, s32 handnum, u8 *allocation)
{
	struct modelnode *node;
	struct coord beamfar;
	struct coord dotpos;
	struct coord dotrot;
	struct coord beamnear;
	s32 mtxindex;
	struct coord sp54;
	struct coord sp48;
	struct coord sp3c;
	struct coord sp30;
	bool busy;

	node = model_get_part(modeldef, MODELPART_GUN_LASERSIGHT);

	if (node) {
		mtxindex = model_find_node_mtx_index(node, 0);

		beamnear.x = ((Mtxf *)((uintptr_t)allocation + mtxindex * sizeof(Mtxf)))->m[3][0];
		beamnear.y = ((Mtxf *)((uintptr_t)allocation + mtxindex * sizeof(Mtxf)))->m[3][1];
		beamnear.z = ((Mtxf *)((uintptr_t)allocation + mtxindex * sizeof(Mtxf)))->m[3][2];

		mtx4_transform_vec_in_place(cam_get_projection_mtxf(), &beamnear);

		if (hand->useposrot
				|| (g_Vars.currentplayer->devicesactive & ~g_Vars.currentplayer->devicesinhibit & DEVICE_XRAYSCANNER)) {
			beamfar.x = 0.0f;
			beamfar.y = 0.0f;
			beamfar.z = 1.0f;

			mtx4_rotate_vec_in_place(&hand->cammtx, &beamfar);

			sp48.x = beamfar.x;
			sp48.y = beamfar.y;
			sp48.z = beamfar.z;

			sp3c.x = beamnear.x;
			sp3c.y = beamnear.y;
			sp3c.z = beamnear.z;

			mtx4_transform_vec(cam_get_world_to_screen_mtxf(), &sp3c, &sp54);
			mtx4_rotate_vec(cam_get_projection_mtxf(), &sp48, &sp30);

			beamfar.x *= 500.0f;
			beamfar.y *= 500.0f;
			beamfar.z *= 500.0f;

			mtx4_rotate_vec_in_place(cam_get_projection_mtxf(), &beamfar);

			beamfar.x += beamnear.x;
			beamfar.y += beamnear.y;
			beamfar.z += beamnear.z;

			lasersight_set_beam(handnum, 1, &beamnear, &beamfar);
			return;
		}

		busy = false;

		if (hand->animmode == HANDANIMMODE_BUSY) {
			busy = true;
		}

		if (busy) {
			mtxindex = model_find_node_mtx_index(node, 0);

			beamfar.x = 0.0f;
			beamfar.y = 0.0f;
			beamfar.z = 500.0f;

			mtx4_transform_vec_in_place((Mtxf *)((uintptr_t)allocation + mtxindex * sizeof(Mtxf)), &beamfar);
		} else {
			cam0f0b4c3c(g_Vars.currentplayer->crosspos, &beamfar, 1);

			beamfar.x *= 500.0f;
			beamfar.y *= 500.0f;
			beamfar.z *= 500.0f;
		}

		mtx4_transform_vec_in_place(cam_get_projection_mtxf(), &beamfar);
		lasersight_set_beam(handnum, 1, &beamnear, &beamfar);

		if (handnum == HAND_RIGHT && hand->hasdotinfo && !busy) {
			dotpos.x = hand->dotpos.x;
			dotpos.y = hand->dotpos.y;
			dotpos.z = hand->dotpos.z;

			dotrot.x = hand->dotrot.x;
			dotrot.y = hand->dotrot.y;
			dotrot.z = hand->dotrot.z;

			lasersight_set_dot(handnum, &dotpos, &dotrot);
		}
	}
}

/**
 * Increment the barrel spinning and play sounds.
 */
void bgun_update_reaper(struct hand *hand, struct modeldef *modeldef)
{
	struct modelnode *node;
	f32 f2;
	f32 f12;
	s32 tmp;

	node = model_get_part(modeldef, MODELPART_REAPER_002C);

	if (hand->mm_reaperspeedcur <= hand->mm_reaperspeedaim) {
		// The barrel is stopped, is accelerating, is at full speed,
		// or is going in reverse after decelerating past the zero point.
		if (hand->mm_reaperspeedaim < 0.0f) {
			// The barrel is in reverse, so manually move the aim speed up towards zero.
			hand->mm_reaperspeedaim += 0.01f * LVUPDATE60FREAL();

			if (hand->mm_reaperspeedaim > 0.0f) {
				hand->mm_reaperspeedaim = 0.0f;
			}
		}

		hand->mm_reaperspeedcur = hand->mm_reaperspeedaim;
	} else {
		// The barrel is decelerating.
		f12 = LVUPDATE60FREAL() * (1.0 / 200.0);

		if (hand->mm_reaperspeedaim < 0.0000001f) {
			// Make the barrel go backwards
			hand->mm_reaperspeedaim = -0.14f;

			if (hand->mm_reaperspeedcur < 0.15f) {
				f12 *= 4.0f;
			}
		}

		f2 = hand->mm_reaperspeedcur - hand->mm_reaperspeedaim;

		if (f12 < f2) {
			f2 = f12;
		}

		hand->mm_reaperspeedcur -= f2;
	}

	if (hand->mm_reaperspeedcur < 0.0f) {
		hand->mm_reaperrot = hand->mm_reaperrot - (1.0f - cosf(hand->mm_reaperspeedcur * DTOR(180))) * 0.5f * LVUPDATE60FREAL() * 0.2f;
	} else {
		hand->mm_reaperrot = hand->mm_reaperrot + (1.0f - cosf(hand->mm_reaperspeedcur * DTOR(180))) * 0.5f * LVUPDATE60FREAL() * 0.2f;
	}

	tmp = hand->mm_reaperrot / (3.14159f * 2);
	hand->mm_reaperrot -= tmp * (3.14159f * 2);
	var8009d140 = hand->mm_reaperrot;

	if (hand->audiohandle == NULL && hand->mm_reaperspeedcur > 0.1f && g_Vars.lvupdate240 != 0) {
		snd_start(var80095200, SFX_805E, &hand->audiohandle, -1, -1, -1.0f, -1, -1);
	}

	if (hand->audiohandle != NULL) {
		f32 sp34 = hand->mm_reaperspeedcur / 0.50f + 0.4f;
		s32 volume = AL_VOL_FULL;

		if (hand->mm_reaperspeedcur < 0.1f) {
			audioStop(hand->audiohandle);
		} else {
			if (hand->mm_reaperspeedcur < 0.6f) {
				volume = (hand->mm_reaperspeedcur - 0.1f) * AL_VOL_FULL / 0.5f;
			}

			audioPostEvent(hand->audiohandle, AL_SNDP_VOL_EVT, volume);
			audioPostEvent(hand->audiohandle, AL_SNDP_PITCH_EVT, *(s32 *)&sp34);
		}
	}

	if (node) {
		var8009d0dc = model_find_node_mtx_index(node, 0);
		g_ModelJointPositionedFunc = bgun0f0a256c;
		var8009d0f0[0] = var8009d0f0[1] = var8009d0f0[2] = -1;
	}

	node = model_get_part(modeldef, MODELPART_REAPER_002D);

	if (node) {
		var8009d0f0[0] = model_find_node_mtx_index(node, 0);
	}

	node = model_get_part(modeldef, MODELPART_REAPER_002E);

	if (node) {
		var8009d0f0[1] = model_find_node_mtx_index(node, 0);
	}

	node = model_get_part(modeldef, MODELPART_REAPER_002F);

	if (node) {
		var8009d0f0[2] = model_find_node_mtx_index(node, 0);
	}
}

/**
 * Move/extend the scope on the gun model when the zoom function is used.
 */
void bgun_update_sniper_rifle(struct modeldef *modeldef, u8 *allocation)
{
	struct modelnode *nodes[4];
	f32 sp88[4] = {0, 0, 0, 0};
	s32 i;
	f32 f26;
	s32 mtxindex;
	struct coord sp70;

	f26 = 1.0f - (gset_get_gun_zoom_fov() - 2.0f) / 58.0f;

	nodes[0] = model_get_part(modeldef, MODELPART_SNIPERRIFLE_SCOPE1);
	nodes[1] = model_get_part(modeldef, MODELPART_SNIPERRIFLE_SCOPE2);
	nodes[2] = model_get_part(modeldef, MODELPART_SNIPERRIFLE_SCOPE3);
	nodes[3] = model_get_part(modeldef, MODELPART_SNIPERRIFLE_SCOPE4);

	for (i = 0; i < ARRAYCOUNT(nodes); i++) {
		if (nodes[i]) {
			f32 f20 = f26 * 4.0f;
			mtxindex = model_find_node_mtx_index(nodes[i], 0);
			sp88[i] = f20 - i;

			if (f20 < i) {
				sp88[i] = 0.0f;
			}

			sp88[i] *= 100.0f;

			sp70.x = 0.0f;
			sp70.y = 0.0f;
			sp70.z = sp88[i];

			mtx4_rotate_vec_in_place((Mtxf *)((uintptr_t)allocation + mtxindex * sizeof(Mtxf)), &sp70);

			((Mtxf *)((uintptr_t)allocation + mtxindex * sizeof(Mtxf)))->m[3][0] += sp70.x;
			((Mtxf *)((uintptr_t)allocation + mtxindex * sizeof(Mtxf)))->m[3][1] += sp70.y;
			((Mtxf *)((uintptr_t)allocation + mtxindex * sizeof(Mtxf)))->m[3][2] += sp70.z;
		}
	}
}

/**
 * Animate the cartridge slider thing in the Devastator model.
 */
void bgun_update_devastator(struct hand *hand, u8 *allocation, struct modeldef *modeldef)
{
	struct modelnode *node = model_get_part(modeldef, MODELPART_DEVASTATOR_0028);

	if (node) {
		s32 mtxindex = model_find_node_mtx_index(node, 0);
		struct coord sp24;

		hand->loadslide += 0.01f * LVUPDATE60FREAL();

		if (hand->loadslide > 1.0f) {
			hand->loadslide = 1.0f;
		}

		sp24.x = hand->loadslide * -10.0f * 1.636f;
		sp24.y = 0.0f;
		sp24.z = 0.0f;

		mtx4_rotate_vec_in_place((Mtxf *)((uintptr_t)allocation + mtxindex * sizeof(Mtxf)), &sp24);

		((Mtxf *)((uintptr_t)allocation + mtxindex * sizeof(Mtxf)))->m[3][0] += sp24.x;
		((Mtxf *)((uintptr_t)allocation + mtxindex * sizeof(Mtxf)))->m[3][1] += sp24.y;
		((Mtxf *)((uintptr_t)allocation + mtxindex * sizeof(Mtxf)))->m[3][2] += sp24.z;
	}
}

/**
 * Display the shotgun's starburst when appropriate.
 *
 * This logic is different to most guns, likely because most guns display the
 * starburst when the trigger is pressed while the shotgun has the double blast
 * function.
 */
void bgun_update_shotgun(struct hand *hand, u8 *allocation, bool *arg2, struct modeldef *modeldef)
{
	if (hand->flashon) {
		hand->mm_shotgunfrac = 1.0f;
	}

	if (hand->mm_shotgunfrac > 0.0f) {
		hand->mm_shotgunfrac -= LVUPDATE60FREAL() / 6.0f;

		if (hand->mm_shotgunfrac < 0.01f) {
			hand->mm_shotgunfrac = 0.0f;
		}
	}

	if (hand->mm_shotgunfrac > 0.0f) {
		s32 sp34;
		s32 sp28[3] = {0, 0, 0};
		struct modelnode *node = model_get_part(modeldef, MODELPART_SHOTGUN_0050);

		*arg2 = true;

		if (node) {
			sp34 = model_find_node_mtx_index(node, 0);

			mtx00015ea8((1.0f - hand->mm_shotgunfrac) * 8.0f + 0.5f, (Mtxf *)((uintptr_t)allocation + sp34 * sizeof(Mtxf)));
			mtx00015df0((1.0f - hand->mm_shotgunfrac) * 3.0f + 1.0f, (Mtxf *)((uintptr_t)allocation + sp34 * sizeof(Mtxf)));
			mtx00015e4c((1.0f - hand->mm_shotgunfrac) * 3.0f + 1.0f, (Mtxf *)((uintptr_t)allocation + sp34 * sizeof(Mtxf)));
		}
	}
}

void bgun_update_laser(struct hand *hand)
{
	if (hand->firing && hand->gset.weaponfunc == FUNC_SECONDARY) {
		if (hand->audiohandle == NULL && g_Vars.lvupdate240 != 0) {
			snd_start(var80095200, SFX_LASER_STREAM, &hand->audiohandle, -1, -1, -1, -1, -1);
		}

		hand->mm_lasertype = 1;
	} else if (hand->mm_lasertype > 0) {
		hand->mm_lasertype -= LVUPDATE60FREAL() / 10.0f;
	} else if (hand->audiohandle != NULL && sndGetState(hand->audiohandle) != AL_STOPPED) {
		audioStop(hand->audiohandle);
	}
}

/**
 * Create ammo casing so they can be ejected during reload.
 */
void bgun_eject_magnum_casings(struct hand *hand, s32 handnum, struct modeldef *modeldef, Mtxf *mtx)
{
	f32 ground = g_Vars.currentplayer->vv_ground;
	s32 i;

	if (modeldef != NULL) {
		for (i = 0; i < hand->ejectcount; i++) {
			struct modelnode *node = model_get_part(modeldef, 0x0a + random() % 6);

			if (node) {
				s32 index = model_find_node_mtx_index(node, 0);
				Mtxf *tmp = mtx;
				Mtxf sp4c;

				tmp += index;

				mtx4_copy(tmp, &sp4c);
				mtx00015f04(9.999999f, &sp4c);
				mtx4_mult_mtx4_in_place(cam_get_projection_mtxf(), &sp4c);

				casing_create_for_hand(handnum, ground, &sp4c);
			}
		}
	}
}

/**
 * Create and/or update the rocket prop that sits inside the rocket launcher.
 */
void bgun_update_rocket_launcher(struct hand *hand, s32 handnum, struct funcdef_shootprojectile *func)
{
	if (hand->rocket == NULL && hand->loadedammo[0] > 0) {
		bgun_create_held_rocket(handnum, func);
	}

	if (hand->rocket) {
		bgun_update_held_rocket(handnum);
	}
}

void bgun0f0a45d0(struct hand *hand, struct modeldef *modeldef, bool isdetonator)
{
	struct modelnode *node = NULL;

	switch (hand->ejecttype) {
	case EJECTTYPE_GUN:
		if (isdetonator) {
			node = model_get_part(modeldef, 0x2a);
		} else {
			node = model_get_part(modeldef, 0x37);
		}
		break;
	case EJECTTYPE_GRENADEPIN:
		node = model_get_part(modeldef, 0x2b);
		break;
	case EJECTTYPE_TRANQCASE:
		node = model_get_part(modeldef, 0x2b);
		break;
	}

	if (node) {
		var8009d148 = model_find_node_mtx_index(node, 0);
		g_ModelJointPositionedFunc = bgun0f0a256c;
	} else {
		var8009d148 = -1;
	}
}

void bgun_tick_eject(struct hand *hand, struct modeldef *modeldef, bool isdetonator)
{
	f32 lvupdate;
	struct coord spd0;
	Mtxf sp90;
	struct coord sp84;
	Mtxf sp44;
	s32 i;
	f32 newval;
	f32 mult = 3;

	switch (hand->ejectstate) {
	case EJECTSTATE_INIT:
		switch (hand->ejecttype) {
		case EJECTTYPE_GUN:
			hand->unk0d20.f[0] = (RANDOMFRAC() - 0.5f) * 0.5333333f * (1.0f / 16.0f) + 0.5333333f;
			hand->unk0d20.f[1] = RANDOMFRAC() * 2.5f * (1.0f / 16.0f) + 2.5f;
			hand->unk0d20.f[2] = 0.0f;

#if VERSION >= VERSION_PAL_BETA
			spd0.f[0] = RANDOMFRAC() * PALUPF(2.0f * BADDTOR(360)) / 184.0f - 0.03414231f;
			spd0.f[1] = RANDOMFRAC() * PALUPF(2.0f * BADDTOR(360)) / 184.0f - 0.03414231f;
			spd0.f[2] = RANDOMFRAC() * PALUPF(2.0f * BADDTOR(360)) / 184.0f - 0.03414231f;
#else
			spd0.f[0] = RANDOMFRAC() * 2.0f * BADDTOR(360) / 184.0f - 0.03414231f;
			spd0.f[1] = RANDOMFRAC() * 2.0f * BADDTOR(360) / 184.0f - 0.03414231f;
			spd0.f[2] = RANDOMFRAC() * 2.0f * BADDTOR(360) / 184.0f - 0.03414231f;
#endif
			break;
		case EJECTTYPE_GRENADEPIN:
			hand->unk0d20.f[0] = -((RANDOMFRAC() - 0.5f) * 0.5333333f * (1.0f / 16.0f) + mult * 0.5333333f);
			hand->unk0d20.f[1] = RANDOMFRAC() * 2.5f * (1.0f / 8.0f) + 2.5f;
			hand->unk0d20.f[2] = -(RANDOMFRAC() + 1.0f);

			spd0.f[0] = (RANDOMFRAC() + 3.0f) * PALUPF(BADDTOR(360)) / 208.0f;
#if VERSION >= VERSION_PAL_BETA
			spd0.f[1] = RANDOMFRAC() * PALUPF(2.0f * BADDTOR(360)) / 544.0f - 0.0115481345f;
			spd0.f[2] = RANDOMFRAC() * PALUPF(2.0f * BADDTOR(360)) / 544.0f - 0.0115481345f;
#else
			spd0.f[1] = RANDOMFRAC() * 2.0f * BADDTOR(360) / 544.0f - 0.0115481345f;
			spd0.f[2] = RANDOMFRAC() * 2.0f * BADDTOR(360) / 544.0f - 0.0115481345f;
#endif
			break;
		case EJECTTYPE_TRANQCASE:
			hand->unk0d20.f[0] = 0.0f;
			hand->unk0d20.f[1] = RANDOMFRAC() * 2.5f * (1.0f / 8.0f) + 2.5f;
			hand->unk0d20.f[2] = (RANDOMFRAC() + 1.0f) * 0.25f;
			spd0.f[0] = (RANDOMFRAC() + 3.0f) * PALUPF(BADDTOR(360)) / 368.0f;
#if VERSION >= VERSION_PAL_BETA
			spd0.f[1] = RANDOMFRAC() * PALUPF(2.0f * BADDTOR(360)) / 944.0f - 0.006654857f;
			spd0.f[2] = RANDOMFRAC() * PALUPF(2.0f * BADDTOR(360)) / 944.0f - 0.006654857f;
#else
			spd0.f[1] = RANDOMFRAC() * 2.0f * BADDTOR(360) / 944.0f - 0.006654857f;
			spd0.f[2] = RANDOMFRAC() * 2.0f * BADDTOR(360) / 944.0f - 0.006654857f;
#endif
			break;
		}

		hand->unk0d10 = hand->unk0d14 - 200.0f;

		mtx4_load_rotation(&spd0, &sp90);
		mtx4_to_mtx3(&sp90, hand->unk0d50);

		if (g_Vars.lvupdate240 > 0 && hand->ejecttype != EJECTTYPE_GUN) {
			sp84.f[0] = (hand->posmtx.m[3][0] - hand->prevmtx.m[3][0]) / g_Vars.lvupdate60freal;
			sp84.f[1] = (hand->posmtx.m[3][1] - hand->prevmtx.m[3][1]) / g_Vars.lvupdate60freal;
			sp84.f[2] = (hand->posmtx.m[3][2] - hand->prevmtx.m[3][2]) / g_Vars.lvupdate60freal;

			mtx00017588(hand->posmtx.m, sp44.m);
			mtx4_rotate_vec_in_place(&sp44, &sp84);

			hand->unk0d20.f[0] += sp84.f[0] * 0.3f;
			hand->unk0d20.f[1] += sp84.f[1] * 0.3f;
			hand->unk0d20.f[2] += sp84.f[2] * 0.3f;
		}

		hand->ejectstate = EJECTSTATE_AIRBORNE;
		break;
	case EJECTSTATE_AIRBORNE:
		lvupdate = g_Vars.lvupdate60freal;

		if (g_Vars.currentplayer->isdead && lvupdate > 1.5f) {
			lvupdate = 1.5f;
		}

		newval = hand->unk0d20.f[1] - lvupdate * 0.2777778f;

		if (hand->unk0d18 < hand->unk0d10) {
			hand->ejectstate = EJECTSTATE_FINISHED;
			break;
		}

		hand->unk0d18 += lvupdate * 0.5f * (hand->unk0d20.f[1] + newval);
		hand->unk0d14 += lvupdate * hand->unk0d20.f[0];
		hand->unk0d1c += lvupdate * hand->unk0d20.f[2];

		hand->unk0d20.f[1] = newval;

		for (i = 0; i < g_Vars.lvupdate240; i++) {
			mtx00016110(hand->unk0d50, hand->unk0d2c);
		}

		break;
	}
}

void bgun0f0a4e44(struct hand *hand, struct weapondef *weapondef, struct modeldef *modeldef,
		struct funcdef *funcdef, s32 maxburst, u8 *allocation, s32 weaponnum,
		bool **arg7, s32 mtxindex, Mtxf *arg9, Mtxf *arg10)
{
	Mtxf spd8;
	s32 index;
	s32 shotstotake;
	bool spc4[3] = {false, false, false};
	Mtxf *mtx;
	s32 i;
	s32 partnum;
	f32 spb4;
	f32 muzzlez;
	Mtxf sp70;

	index = hand->burstbullets % maxburst;
	shotstotake = hand->shotstotake;

	spb4 = RANDOMFRAC() * 0.25f + 1.0f;
	muzzlez = weapondef->muzzlez;

	mtx4_load_identity(&spd8);

	if (funcdef && (funcdef->flags & FUNCFLAG_00000001)) {
		mtx4_load_z_rotation(RANDOMFRAC() * BADDTOR(360), &spd8);
	}

	mtx4_load_z_rotation((RANDOMFRAC() * 0.3 - 0.15), &spd8);

	mtx = (Mtxf *)allocation;
	mtx += mtxindex;

	mtx4_mult_mtx4_in_place(mtx, &spd8);
	mtx00015f04(spb4, &spd8);
	mtx00015ea8(muzzlez, &spd8);
	mtx4_copy(&spd8, mtx);

	if (shotstotake == 0 && weaponnum != WEAPON_REAPER) {
		shotstotake++;
	}

	for (i = 0; i < shotstotake; i++) {
		spc4[index] = true;
		index++;

		if (index >= maxburst) {
			index = 0;
		}
	}

	for (i = 0; i < maxburst; i++) {
		if (spc4[i] && arg7[i] != NULL) {
			*arg7[i] = true;
		}
	}

	for (partnum = 0x50; partnum <= 0x52; partnum++) {
		struct modelnode *node = model_get_part(modeldef, partnum);
		struct coord sp60;

		if (node && weaponnum != WEAPON_REAPER && weaponnum != WEAPON_SHOTGUN) {
			struct modelrodata_position *rodata = &node->rodata->position;
			s32 mtxindex = model_find_node_mtx_index(node, 0);

			sp60.x = rodata->pos.x * spd8.m[0][0] + rodata->pos.y * spd8.m[1][0] + rodata->pos.z * spd8.m[2][0] + spd8.m[3][0];
			sp60.y = rodata->pos.x * spd8.m[0][1] + rodata->pos.y * spd8.m[1][1] + rodata->pos.z * spd8.m[2][1] + spd8.m[3][1];
			sp60.z = rodata->pos.x * spd8.m[0][2] + rodata->pos.y * spd8.m[1][2] + rodata->pos.z * spd8.m[2][2] + spd8.m[3][2];

			mtx4_load_identity(&sp70);
			mtx4_align(sp70.m, RANDOMFRAC() * BADDTOR(360), -sp60.x, -sp60.y, -sp60.z);
			mtx00015f04(0.10000001f * spb4, &sp70);

			mtx = (Mtxf *)allocation;

			mtx00016e98(arg10->m, 0, mtx->m[3][0] - hand->aimpos.x, mtx->m[3][1] - hand->aimpos.y, mtx->m[3][2] - hand->aimpos.z);
			mtx4_mult_mtx4_in_place(arg10, &sp70);
			mtx00016710(muzzlez, sp70.m);
			mtx4_mult_mtx4_in_place(arg9, &sp70);
			mtx4_set_translation(&sp60, &sp70);

			mtx = (Mtxf *)allocation;
			mtx += mtxindex;

			mtx4_copy(&sp70, mtx);
		}
	}
}

/**
 * Create casing and beam for a fired weapon,
 * and uncloak if the weapon is a throwable or fired projectile.
 */
void bgun_create_fx(struct hand *hand, s32 handnum, struct funcdef *funcdef, s32 weaponnum, struct modeldef *modeldef, u8 *allocation)
{
	f32 ground;
	bool createbeam = true;

	g_Vars.currentplayer->gunctrl.throwing = false;

	if (funcdef) {
		ground = g_Vars.currentplayer->vv_ground;

		if (modeldef && weaponnum != WEAPON_DY357MAGNUM && weaponnum != WEAPON_DY357LX) {
			s32 partnum = MODELPART_GUN_CARTEJECTPOS;
			struct modelnode *node;

			if (weaponnum == WEAPON_REAPER) {
				partnum = (hand->burstbullets & 1) == 1 ? MODELPART_REAPER_CARTEJECTPOS1 : MODELPART_REAPER_CARTEJECTPOS2;
			}

			node = model_get_part(modeldef, partnum);

			if (node) {
				Mtxf *mtx = (Mtxf *)allocation;
				Mtxf sp24;

				mtx += model_find_node_mtx_index(node, 0);

				mtx4_copy(mtx, &sp24);
				mtx00015f04(9.999999f, &sp24);
				mtx4_mult_mtx4_in_place(cam_get_projection_mtxf(), &sp24);

				casing_create_for_hand(handnum, ground, &sp24);
			} else {
				casing_create_for_hand(handnum, ground, &hand->posmtx);
			}

			bgun_set_part_visible(MODELPART_GUN_CARTFLAPCLOSED, false, hand, modeldef);
			bgun_set_part_visible(MODELPART_GUN_CARTFLAPOPEN, true, hand, modeldef);
		}

		if (funcdef->type == INVENTORYFUNCTYPE_SHOOT_PROJECTILE) {
			chr_uncloak_temporarily(g_Vars.currentplayer->prop->chr);
		} else if ((funcdef->type & 0xff) == INVENTORYFUNCTYPE_THROW) {
			chr_uncloak_temporarily(g_Vars.currentplayer->prop->chr);
		}
	}

	if (funcdef) {
		if ((funcdef->type & 0xff) == INVENTORYFUNCTYPE_MELEE || (funcdef->type & INVENTORYFUNCTYPE_0200)) {
			createbeam = false;
		}

		if ((funcdef->type & 0xff) == INVENTORYFUNCTYPE_SPECIAL) {
			createbeam = false;
		}

		if ((funcdef->type & 0xff) == INVENTORYFUNCTYPE_THROW) {
			createbeam = false;
		}
	}

	if (createbeam) {
		switch (weaponnum) {
		case WEAPON_FALCON2:
		case WEAPON_FALCON2_SILENCER:
		case WEAPON_FALCON2_SCOPE:
		case WEAPON_MAGSEC4:
		case WEAPON_MAULER:
		case WEAPON_PHOENIX:
		case WEAPON_DY357MAGNUM:
		case WEAPON_DY357LX:
		case WEAPON_CMP150:
		case WEAPON_CYCLONE:
		case WEAPON_CALLISTO:
		case WEAPON_RCP120:
		case WEAPON_LAPTOPGUN:
		case WEAPON_DRAGON:
		case WEAPON_K7AVENGER:
		case WEAPON_AR34:
		case WEAPON_SUPERDRAGON:
		case WEAPON_REAPER:
		case WEAPON_SNIPERRIFLE:
		case WEAPON_FARSIGHT:
		case WEAPON_TRANQUILIZER:
		case WEAPON_PP9I:
		case WEAPON_CC13:
		case WEAPON_KL01313:
		case WEAPON_KF7SPECIAL:
		case WEAPON_ZZT:
		case WEAPON_DMC:
		case WEAPON_AR53:
		case WEAPON_RCP45:
			beam_create_for_hand(handnum);
			hand->numfires++;
			return;
		case WEAPON_LASER:
			hand->numfires++;
			beam_create_for_hand(handnum);
			break;
		}
	}
}

void bgun0f0a5550(s32 handnum)
{
	u8 *mtxallocation;
	Mtxf sp2c4;
	Mtxf sp284;
	struct modeldef *modeldef = NULL;
	struct coord sp274 = {0, 0, 0};
	Mtxf sp234;
	Mtxf sp1f4;
	union modelrodata *rodata;
	bool *sp1e4[3] = {NULL, NULL, NULL};
	s32 sp1e0 = 0;
	struct modelnode *node;
	struct player *player = g_Vars.currentplayer;
	struct hand *hand = player->hands + handnum;
	struct funcdef *funcdef;
	struct funcdef_shoot *shootfunc = NULL;
	s32 i;
	s32 weaponnum = bgun_get_weapon_num2(handnum);
	struct weapondef *weapondef;
	Mtxf *mtx;
	bool isdetonator = false;
	f32 fspare1;
	f32 fspare2;
	struct coord sp1a4;
	Mtxf sp164;
	Mtxf sp124;
	struct coord sp118;
	s32 j;

	weapondef = gset_get_weapondef(weaponnum);

	if (handnum == HAND_LEFT && weaponnum == WEAPON_REMOTEMINE) {
		isdetonator = true;
	}

	funcdef = gset_get_funcdef_by_gset2(&hand->gset);

	if (funcdef && (funcdef->type & 0xff) == INVENTORYFUNCTYPE_SHOOT) {
		shootfunc = (struct funcdef_shoot *)funcdef;
	}

	bgun_update_blend(hand, handnum);

	if (handnum == HAND_RIGHT) {
		if (gset_has_weapon_flag(bgun_get_weapon_num2(HAND_LEFT), WEAPONFLAG_00000040)) {
			hand->xshift += 2.0f * g_Vars.lvupdate60freal / 240.0f;

			if (hand->xshift > 2.0f) {
				hand->xshift = 2.0f;
			}
		} else {
			hand->xshift -= 2.0f * g_Vars.lvupdate60freal / 240.0f;

			if (hand->xshift < 0.0f) {
				hand->xshift = 0.0f;
			}
		}
	} else {
		if (gset_has_weapon_flag(bgun_get_weapon_num2(HAND_RIGHT), WEAPONFLAG_00000040)) {
			hand->xshift -= 2.0f * g_Vars.lvupdate60freal / 240.0f;

			if (hand->xshift < -2.0f) {
				hand->xshift = -2.0f;
			}
		} else {
			hand->xshift += 2.0f * g_Vars.lvupdate60freal / 240.0f;

			if (hand->xshift > 0.0f) {
				hand->xshift = 0.0f;
			}
		}
	}

	if (handnum == HAND_RIGHT) {
		sp274.x = gset_get_xpos(handnum) + hand->damppos.f[0] + hand->adjustpos.f[0];
		sp274.y = weapondef->posy + hand->damppos.f[1] + hand->adjustpos.f[1];
		sp274.z = weapondef->posz + hand->damppos.f[2] + hand->adjustpos.f[2];
	} else if (isdetonator) {
		sp274.x = 6.5f + hand->damppos.f[0] - hand->adjustpos.f[0];
		sp274.y = -16.5f + hand->damppos.f[1] + hand->adjustpos.f[1];
		sp274.z = -16.0f + hand->damppos.f[2] + hand->adjustpos.f[2];
	} else {
		sp274.x = gset_get_xpos(handnum) + hand->damppos.f[0] - hand->adjustpos.f[0];
		sp274.y = weapondef->posy + hand->damppos.f[1] + hand->adjustpos.f[1];
		sp274.z = weapondef->posz + hand->damppos.f[2] + hand->adjustpos.f[2];
	}

	sp274.y += player->guncloseroffset * 5.0f / -90.0f * 50.0f;
	sp274.z -= player->guncloseroffset * 15.0f / -90.0f * 50.0f;

	if (hand->firing && shootfunc && g_Vars.lvupdate240 != 0 && shootfunc->recoilsettings != NULL) {
		sp274.x += (RANDOMFRAC() - 0.5f) * shootfunc->recoilsettings->xrange * hand->finalmult[0];
		sp274.y += (RANDOMFRAC() - 0.5f) * shootfunc->recoilsettings->yrange * hand->finalmult[0];
		sp274.z += (RANDOMFRAC() - 0.5f) * shootfunc->recoilsettings->zrange * hand->finalmult[0];
	}

	hand->fspare1 = (player->crosspos2[0] - cam_get_screen_left() - cam_get_screen_width() * 0.5f) * weapondef->aimsettings->guntransside / (cam_get_screen_width() * 0.5f);

	if (player->crosspos2[1] - cam_get_screen_top() > cam_get_screen_height() * 0.5f) {
		hand->fspare2 = (player->crosspos2[1] - cam_get_screen_top() - cam_get_screen_height() * 0.5f) * weapondef->aimsettings->guntransdown / (cam_get_screen_height() * 0.5f);
	} else {
		hand->fspare2 = (player->crosspos2[1] - cam_get_screen_top() - cam_get_screen_height() * 0.5f) * weapondef->aimsettings->guntransup / (cam_get_screen_height() * 0.5f);
	}

	fspare1 = hand->fspare1;
	fspare2 = hand->fspare2;

	sp274.f[0] += fspare1;
	sp274.f[1] -= fspare2;

	hand->visible = true;

	if (!gset_has_weapon_flag(weaponnum, WEAPONFLAG_00000040)
			|| gset_has_weapon_flag(weaponnum, WEAPONFLAG_00000080)
			|| hand->mode == HANDMODE_6
			|| hand->mode == HANDMODE_7
			|| !bgun_is_loaded()
			|| hand->inuse == false
			|| bgun_get_gun_mem_type() == 0) {
		hand->visible = false;
	}

	if (hand->visible) {
		modeldef = player->gunctrl.gunmodeldef;
		mtxallocation = gfx_allocate(modeldef->nummatrices * sizeof(Mtxf));

		if (gset_has_weapon_flag(weaponnum, WEAPONFLAG_RESETMATRICES)) {
			for (i = 0; i < modeldef->nummatrices; i++) {
				mtx = (Mtxf *)(mtxallocation + i * sizeof(Mtxf));
				mtx4_load_identity(mtx);
			}
		}

		bgun_execute_model_cmd_list(hand->compiledgunmodelcmds);

		if (player->gunctrl.handmodeldef != NULL) {
			bgun_execute_model_cmd_list(hand->compiledhandmodelcmds);
		}

		bgun_update_ammo_visibility(hand, modeldef);

		if (gset_has_weapon_flag(weaponnum, WEAPONFLAG_HASGUNSCRIPT)) {
			bgun_tick_anim(hand, modeldef);
		}
	}

	mtx4_load_identity(&sp234);

	if (PLAYERCOUNT() == 1 && IS8MB() && gset_has_weapon_flag(weaponnum, WEAPONFLAG_GANGSTA)) {
		bgun_update_gangsta(hand, handnum, &sp274, funcdef, &sp284, &sp234);
	}

	if (hand->useposrot) {
		sp274.f[0] += hand->posrotmtx.m[3][0];
		sp274.f[1] += hand->posrotmtx.m[3][1];
		sp274.f[2] += hand->posrotmtx.m[3][2];

		mtx00015be0(&hand->posrotmtx, &sp234);

		sp234.m[3][0] = 0.0f;
		sp234.m[3][1] = 0.0f;
		sp234.m[3][2] = 0.0f;
	} else {
		hand->rotxoffset = 0.0f;
		hand->posoffset.x = 0.0f;
		hand->posoffset.y = 0.0f;
		hand->posoffset.z = 0.0f;
	}

	mtx00016d58(&sp284, 0.0f, 0.0f, 0.0f,
			hand->damplook.x, hand->damplook.y, hand->damplook.z,
			hand->dampup.x, hand->dampup.y, hand->dampup.z);

	mtx00015be0(&sp284, &sp234);

	sp1a4.x = 0.0f;
	sp1a4.y = DTOR(180);
	sp1a4.z = 0.0f;

	mtx4_load_rotation(&sp1a4, &sp164);

	sp1a4.y = 0.0f;

	bgun0f0a24f0(&sp118, handnum);

	sp1a4.y = -bgun0f0a2498(sp118.x, sp118.z, sp274.f[0], sp274.f[2]);
	sp1a4.x = bgun0f0a2498(sp118.y, sp118.z, sp274.f[1], sp274.f[2]);

	hand->lastrotangx = sp1a4.f[0];
	hand->lastrotangy = sp1a4.f[1];

	mtx4_load_rotation(&sp1a4, &sp124);
	mtx4_mult_mtx4(&sp124, &sp164, &sp284);
	mtx4_mult_mtx4_in_place(&sp284, &sp234);
	mtx4_copy(&sp234, &sp2c4);
	mtx4_set_translation(&sp274, &sp2c4);

	mtx4_copy(&sp2c4, &hand->cammtx);
	mtx4_copy(&hand->posmtx, &hand->prevmtx);

	mtx00015be4(cam_get_projection_mtxf(), &hand->cammtx, &hand->posmtx);

	if (hand->visible) {
		for (j = 0x5a; j < 0x5d; j++) {
			node = model_get_part(modeldef, j);

			if (node) {
				rodata = node->rodata;
				sp1e4[sp1e0] = (bool *)&hand->unk0a6c[rodata->toggle.rwdataindex];
				sp1e0++;
			}
		}

		hand->gunmodel.matrices = (Mtxf *)mtxallocation;
		hand->handmodel.matrices = (Mtxf *)mtxallocation;

		if (gset_has_weapon_flag(weaponnum, WEAPONFLAG_DUALFLIP) && handnum == HAND_LEFT) {
			mtx00015e24(-1, &sp2c4);
		}

		mtx00015f04(0.10000001f, &sp2c4);

		mtx4_copy(&sp2c4, (Mtxf *)mtxallocation);

		if (hand->ejectcount > 0) {
			switch (weaponnum) {
			case WEAPON_GRENADE:
			case WEAPON_NBOMB:
				hand->ejectstate = EJECTSTATE_INIT;
				hand->ejecttype = EJECTTYPE_GRENADEPIN;
				break;
			case WEAPON_TRANQUILIZER:
				hand->ejectstate = EJECTSTATE_INIT;
				hand->ejecttype = EJECTTYPE_TRANQCASE;
				break;
			}
		}

		var8009d144 = hand;

		if (hand->ejectstate > EJECTSTATE_INACTIVE) {
			bgun0f0a45d0(hand, modeldef, isdetonator);
		}

		var8009d0dc = -1;
		var8009d0f0[0] = var8009d0f0[1] = var8009d0f0[2] = -1;

		switch (weaponnum) {
		case WEAPON_LASER:
			bgun_update_laser(hand);
			break;
		case WEAPON_REAPER:
			bgun_update_reaper(hand, modeldef);
			break;
		}

		{
			bool a0 = true;
			struct modelrenderdata renderdata = {NULL, true, 3};
#if VERSION >= VERSION_PAL_BETA
			bool a3 = false;
#endif
			s32 spcc;
			Mtxf *spc8;
			Mtxf *spc4;
			Mtxf sp84;
			u32 sp80;
			struct coord sp74;
			s32 stack;
			s32 sp6c;

			renderdata.unk00 = &sp2c4;
			renderdata.unk10 = hand->gunmodel.matrices;

			if (hand->animmode != HANDANIMMODE_IDLE) {
				a0 = false;
			}

			switch (weaponnum) {
			case WEAPON_REAPER:
				a0 = false;
				break;
			case WEAPON_COMBATKNIFE:
				if (player->hands[HAND_LEFT].loadedammo[0] == 0) {
					a0 = false;
				}
				// fall through
			case WEAPON_GRENADE:
			case WEAPON_NBOMB:
			case WEAPON_TIMEDMINE:
			case WEAPON_PROXIMITYMINE:
			case WEAPON_REMOTEMINE:
			case WEAPON_ECMMINE:
				if (player->hands[HAND_RIGHT].loadedammo[0] == 0) {
					a0 = false;
				}

				if (player->hands[handnum].state == HANDSTATE_AUTOSWITCH) {
					a0 = false;
				}

				if (player->hands[handnum].state == HANDSTATE_ATTACK) {
					a0 = false;
				}
				break;
			}

			if (hand->ejectstate != EJECTSTATE_INACTIVE) {
				a0 = false;
			}

			if (player->hands[handnum].state == HANDSTATE_CHANGEGUN
					&& player->hands[handnum].stateminor <= HANDSTATEMINOR_CHANGEGUN_LOWER
					&& weapondef->unequip_animation != NULL) {
				a0 = false;
			}

#if VERSION >= VERSION_PAL_BETA
			switch (model_get_anim_num(&hand->gunmodel)) {
			case ANIM_GUN_CROSSBOW_EQUIP:
			case ANIM_GUN_LAPTOP_EQUIP:
			case ANIM_GUN_LAPTOP_UNEQUIP:
			case ANIM_GUN_LAPTOP_RELOAD:
			case ANIM_GUN_FALCON2_RELOAD:
			case ANIM_GUN_CMP150_RELOAD:
			case ANIM_GUN_FARSIGHT_SHOOT:
			case ANIM_GUN_SHOTGUN_SHOOT_SINGLE:
			case ANIM_GUN_REAPER_SHOOT:
			case ANIM_GUN_MAGSEC4_RELOAD:
			case ANIM_GUN_CYCLONE_RELOAD:
			case ANIM_GUN_SNIPER_RELOAD:
			case ANIM_GUN_PHOENIX_RELOAD:
			case ANIM_GUN_FALCON2_RELOAD_SCOPE:
			case ANIM_GUN_REMOTEMINE_EQUIP:
				a3 = 1;
				break;
			}
#endif

			if (a0) {
				if (player->hands[HAND_RIGHT].unk0dd4 == -1) {
					mtx4_load_identity(&sp84);

					spc4 = hand->gunmodel.matrices;

					renderdata.unk00 = &sp84;
					renderdata.unk10 = player->hands[HAND_RIGHT].unk0dd8;

#if VERSION >= VERSION_PAL_BETA
					var8005efd8_2 = true;

					if (a3) {
						var8005efb0_2 = true;
					}

					model_set_matrices_with_anim(&renderdata, &hand->gunmodel);

					var8005efd8_2 = false;

					if (a3) {
						var8005efb0_2 = false;
					}
#else
					model_set_matrices_with_anim(&renderdata, &hand->gunmodel);
#endif

					player->hands[HAND_RIGHT].unk0dd4 = 1;

					hand->gunmodel.matrices = spc4;
				}

				spc8 = player->hands[HAND_RIGHT].unk0dd8;
				spc4 = hand->gunmodel.matrices;

				for (spcc = 0; spcc < hand->gunmodel.definition->nummatrices; spcc++) {
					mtx00015be4(&sp2c4, spc8, spc4);
					spc8++;
					spc4++;
				}
			} else {
#if VERSION >= VERSION_PAL_BETA
				var8005efd8_2 = true;

				if (a3) {
					var8005efb0_2 = true;
				}

				model_set_matrices_with_anim(&renderdata, &hand->gunmodel);

				var8005efd8_2 = false;

				if (a3) {
					var8005efb0_2 = false;
				}
#else
				model_set_matrices_with_anim(&renderdata, &hand->gunmodel);
#endif
			}

			g_ModelJointPositionedFunc = 0;

			node = model_get_part(modeldef, MODELPART_GUN_SLIDE);

			if (node) {
				sp80 = model_find_node_mtx_index(node, 0);

				bgun_update_slide(handnum);

				sp74.f[0] = 0.0f;
				sp74.f[1] = 0.0f;
				sp74.f[2] = -hand->slidetrans;

				mtx = (Mtxf *)mtxallocation;
				mtx += sp80;

				mtx4_rotate_vec_in_place(mtx, &sp74);

				mtx->m[3][0] += sp74.f[0];
				mtx->m[3][1] += sp74.f[1];
				mtx->m[3][2] += sp74.f[2];
			}

			if (sp1e4[0] != NULL) {
				*sp1e4[0] = false;
			}

			if (sp1e4[1] != NULL) {
				*sp1e4[1] = false;
			}

			if (sp1e4[2] != NULL) {
				*sp1e4[2] = false;
			}

			switch (weaponnum) {
			case WEAPON_SNIPERRIFLE:
				bgun_update_sniper_rifle(modeldef, mtxallocation);
				break;
			case WEAPON_DEVASTATOR:
				bgun_update_devastator(hand, mtxallocation, modeldef);
				break;
			case WEAPON_SHOTGUN:
				bgun_update_shotgun(hand, mtxallocation, sp1e4[0], modeldef);
				break;
			}

			node = model_get_part(modeldef, MODELPART_GUN_MUZZLEPOS);

			if (weaponnum == WEAPON_REAPER) {
				if (hand->flashon || hand->firing) {
					node = model_get_part(modeldef, MODELPART_REAPER_001E + (hand->burstbullets % 3));
				} else {
					node = model_get_part(modeldef, MODELPART_REAPER_001E + (g_Vars.lvframenum % 3));
				}
			}

			if (node) {
				sp6c = model_find_node_mtx_index(node, 0);

				mtx = (Mtxf *)mtxallocation;
				mtx += sp6c;

				hand->muzzlepos.f[0] = mtx->m[3][0];
				hand->muzzlepos.f[1] = mtx->m[3][1];
				hand->muzzlepos.f[2] = mtx->m[3][2];

				mtx4_copy(mtx, &hand->muzzlemat);
				mtx4_transform_vec_in_place(cam_get_projection_mtxf(), &hand->muzzlepos);

				hand->muzzlez = -((Mtxf *)((uintptr_t)mtxallocation + sp6c * sizeof(Mtxf)))->m[3][2];

				if (hand->flashon && sp1e0 > 0 && weaponnum != WEAPON_SHOTGUN && g_Vars.lvupdate240 != 0) {
					bgun0f0a4e44(hand, weapondef, modeldef, funcdef, sp1e0, mtxallocation, weaponnum, sp1e4, sp6c, &sp234, &sp1f4);
				}
			} else if (weaponnum == WEAPON_GRENADE
					|| weaponnum == WEAPON_TIMEDMINE
					|| weaponnum == WEAPON_REMOTEMINE
					|| weaponnum == WEAPON_PROXIMITYMINE
					|| weaponnum == WEAPON_NBOMB) {
				sp6c = model_find_node_mtx_index(model_get_part(modeldef, MODELPART_GUN_HOLDPOS), 0);

				mtx = (Mtxf *)mtxallocation;
				mtx += sp6c;

				hand->muzzlepos.x = mtx->m[3][0];
				hand->muzzlepos.y = mtx->m[3][1];
				hand->muzzlepos.z = mtx->m[3][2];

				mtx4_copy(mtx, &hand->muzzlemat);
				mtx4_transform_vec_in_place(cam_get_projection_mtxf(), &hand->muzzlepos);

				hand->muzzlez = -((Mtxf *)((uintptr_t)mtxallocation + sp6c * sizeof(Mtxf)))->m[3][2];
			} else {
				hand->muzzlepos.x = hand->posmtx.m[3][0];
				hand->muzzlepos.y = hand->posmtx.m[3][1];
				hand->muzzlepos.z = hand->posmtx.m[3][2];

				mtx4_copy(&hand->posmtx, &hand->muzzlemat);

				hand->muzzlez = -hand->cammtx.m[3][2];
			}
		}
	} else {
		hand->muzzlepos.x = hand->posmtx.m[3][0];
		hand->muzzlepos.y = hand->posmtx.m[3][1];
		hand->muzzlepos.z = hand->posmtx.m[3][2];

		mtx4_copy(&hand->posmtx, &hand->muzzlemat);

		hand->muzzlez = -hand->cammtx.m[3][2];
	}

	switch (weaponnum) {
	case WEAPON_ROCKETLAUNCHER:
		bgun_update_rocket_launcher(hand, handnum, (struct funcdef_shootprojectile *)funcdef);
		break;
	case WEAPON_DY357MAGNUM:
	case WEAPON_DY357LX:
		if (hand->ejectcount > 0) {
			bgun_eject_magnum_casings(hand, handnum, modeldef, (Mtxf *)mtxallocation);
		}
		break;
	}

	if (hand->firing && g_Vars.lvupdate240 != 0) {
		bgun_create_fx(hand, handnum, funcdef, weaponnum, modeldef, mtxallocation);
	}

	if (PLAYERCOUNT() == 1 && IS8MB() && g_Vars.lvupdate240 != 0) {
		bgun_update_smoke(hand, handnum, weaponnum, funcdef);
	}

	if (hand->ejectstate > EJECTSTATE_INACTIVE) {
		bgun_tick_eject(hand, modeldef, isdetonator);
	}

	if (PLAYERCOUNT() == 1 && IS8MB() && hand->visible
			&& weaponnum >= WEAPON_FALCON2 && weaponnum <= WEAPON_FALCON2_SCOPE) {
		bgun_update_lasersight(hand, modeldef, handnum, mtxallocation);
	} else {
		lasersight_free(handnum);
	}

	hand->animframeinc = 0;

#if VERSION >= VERSION_PAL_BETA
	hand->animframeincfreal = 0;
#endif
}

void bgun_tick_mauler_charge(void)
{
	struct player *player = g_Vars.currentplayer;
	s32 i;

	for (i = 0; i < 2; i++) {
		struct hand *hand = &player->hands[i];
		u32 charging = false;

		if (hand->inuse) {
			if (bgun_is_reloading(hand)) {
				// Reloading - reset charge amount
				hand->mm_maulercharge = 0;
			} else if (hand->gset.weaponfunc == FUNC_SECONDARY) {
				// Charging or fully charged
				s32 oldvalue = hand->mm_maulercharge;
				s32 newvalue;

				if (hand->loadedammo[0] >= 2 && hand->mm_maulercharge < 5) {
					charging = true;
					hand->mm_maulercharge += g_Vars.lvupdate60freal * 0.05f;
				}

				if (hand->mm_maulercharge > 5) {
					hand->mm_maulercharge = 5;
				}

				newvalue = hand->mm_maulercharge;

				if (oldvalue != newvalue && hand->loadedammo[0] >= 2) {
					hand->loadedammo[0]--;
				}
			} else {
				// Using primary function - make the charge wear off slowly
				hand->mm_maulercharge -= g_Vars.lvupdate60freal * 0.005f;

				if (hand->mm_maulercharge < 0) {
					hand->mm_maulercharge = 0;
				}
			}

			/**
			 * Probable @bug: In other places where audio is started and then
			 * its speed is adjusted, the game raises the priority of the main
			 * thread (this thread) to above the audio thread's priority so that
			 * the audio thread cannot execute and start playing the audio
			 * between the calls to snd_start and audioPostEvent. But this pattern
			 * is not done here.
			 *
			 * There is a known issue where the Mauler charge sound is played
			 * correctly then the game proceeds to play other unrelated sound
			 * effects before eventually crashing. It's suspected that this lack
			 * of thread priority adjusting is the root cause. Perhaps a race
			 * condition exists where the audio thread does something with the
			 * sound while this thread is in the middle of reconfiguring it.
			 * This is not yet confirmed.
			 */
			if (hand->audiohandle == NULL
					&& hand->mm_maulercharge > 0.1f
					&& charging
					&& g_Vars.lvupdate240 != 0) {
				snd_start(var80095200, SFX_MAULER_CHARGE, &hand->audiohandle, -1, -1, -1, -1, -1);
			}

			if (hand->audiohandle) {
				f32 speed = 0.5f + hand->mm_maulercharge / 3.0f + sinf(g_20SecIntervalFrac * DTOR(180) * 32.0f) * 0.03f;

				if (hand->mm_maulercharge < 0.1f || !charging) {
					audioStop(hand->audiohandle);
				} else {
					audioPostEvent(hand->audiohandle, AL_SNDP_PITCH_EVT, *(s32 *)&speed);
				}
			}
		}
	}
}

void bgun_tick_gameplay2(void)
{
	struct player *player = g_Vars.currentplayer;
	struct hand *hand;
	u32 stack[3];
	s32 i;

#if VERSION >= VERSION_NTSC_1_0
	if (g_Vars.currentplayernum == 0) {
		projectiles_debug();
	}
#endif

	if (player->gunctrl.loadall) {
		// empty
	} else {
		bgun_tick_load();
	}

	// Return control to Jo if eyespy has been deselected
	if ((g_Vars.currentplayer->devicesactive & ~g_Vars.currentplayer->devicesinhibit & DEVICE_EYESPY) == 0
			&& player->eyespy) {
		player->eyespy->active = false;
	}

	if ((g_Vars.currentplayer->devicesactive & ~g_Vars.currentplayer->devicesinhibit & DEVICE_XRAYSCANNER)
			&& (bgun_get_weapon_num(HAND_RIGHT) != WEAPON_FARSIGHT || player->gunsightoff)) {
		// Using normal xray scanner (not Farsight zoom)
		if (player->visionmode != VISIONMODE_XRAY) {
			player->erasertime = 0;
		} else {
			player->erasertime += g_Vars.lvupdate240;
		}

		player->visionmode = VISIONMODE_XRAY;
		player->ecol_1 = 24;
		player->ecol_2 = 8;
		player->ecol_3 = 24;
		player->epcol_0 = 2;
		player->epcol_1 = 0;
		player->epcol_2 = 1;
	} else {
		if (player->gunsightoff == 0) {
			if (player->hands[HAND_RIGHT].gset.weaponnum == WEAPON_FARSIGHT) {
				// Aiming with the Farsight
				if (player->visionmode != VISIONMODE_XRAY) {
					player->erasertime = 0;
				} else {
					player->erasertime += g_Vars.lvupdate240;
				}

				player->visionmode = VISIONMODE_XRAY;
				player->ecol_1 = 16;
				player->ecol_2 = 24;
				player->ecol_3 = 8;
				player->epcol_0 = 0;
				player->epcol_1 = 1;
				player->epcol_2 = 2;
			} else {
				// Aiming with non-Farsight
				if (player->visionmode != VISIONMODE_SLAYERROCKET) {
					player->visionmode = VISIONMODE_NORMAL;
				}
			}
		} else {
			// Not aiming
			if (player->visionmode != VISIONMODE_SLAYERROCKET) {
				player->visionmode = VISIONMODE_NORMAL;
			}
		}
	}

	if (player->gunctrl.weaponnum == WEAPON_MAULER) {
		bgun_tick_mauler_charge();
	}

	if (g_Vars.lvupdate240 == 0) {
		for (i = 0; i < 2; i++) {
			hand = &player->hands[i];

			if (hand->audiohandle) {
				audioStop(hand->audiohandle);
			}
		}
	}

	if (g_Vars.currentplayer->devicesactive &
			~g_Vars.currentplayer->devicesinhibit & DEVICE_CLOAKRCP120) {
		if (player->gunctrl.weaponnum == WEAPON_RCP120) {
			struct chrdata *chr = player->prop->chr;

			// Handle RCP120 cloak ammo usage
			if ((chr->hidden & CHRHFLAG_CLOAKED) && chr->cloakfadefinished == true) {
				hand = &player->hands[HAND_RIGHT];
				hand->mm_rcpremainder += LVUPDATE60FREAL() * 0.4f;

				if (hand->mm_rcpremainder > 1.0f) {
					s32 usedqty = hand->mm_rcpremainder;

					if (usedqty > hand->loadedammo[0]) {
						usedqty = hand->loadedammo[0];
					}

					hand->mm_rcpremainder -= usedqty;
					hand->loadedammo[0] -= usedqty;

					// If out of ammo, turn off cloak
					if (hand->loadedammo[0] == 0 && hand->state != HANDSTATE_RELOAD) {
						s32 stilltogo = hand->mm_rcpremainder;

						if (stilltogo > player->ammoheldarr[player->gunctrl.ammotypes[0]]) {
							g_Vars.currentplayer->devicesactive &= ~DEVICE_CLOAKRCP120;
						}
					}
				}
			}
		} else {
			// No longer using RCP120, so turn off cloak
			player->devicesactive &= ~DEVICE_CLOAKRCP120;
		}
	} else if (player->gunctrl.weaponnum == WEAPON_RCP120) {
		hand = &player->hands[HAND_RIGHT];

		// I think this is handling situations where the player has turned off
		// RCP120 cloak but there's still a bit of ammo to be subtracted on
		// this tick.
		if (hand->mm_rcpremainder > 1.0f) {
			s32 usedqty = hand->mm_rcpremainder;

			if (usedqty > hand->loadedammo[0]) {
				usedqty = hand->loadedammo[0];
			}

			hand->mm_rcpremainder -= usedqty;
			hand->loadedammo[0] -= usedqty;

			if (hand->mm_rcpremainder > 1.0f) {
				s32 usedqty = hand->mm_rcpremainder;

				if (usedqty > player->ammoheldarr[player->gunctrl.ammotypes[0]]) {
					usedqty = player->ammoheldarr[player->gunctrl.ammotypes[0]];
				}

				player->ammoheldarr[player->gunctrl.ammotypes[0]] -= usedqty;
				hand->mm_rcpremainder = 0;
			}
		}
	}

	bgun_tick_unequipped_reload();
	bgun0f0a5550(HAND_RIGHT);

	if (player->hands[HAND_LEFT].inuse) {
		bgun0f0a5550(HAND_LEFT);
	} else {
		player->hands[HAND_LEFT].ejectstate = EJECTSTATE_INACTIVE;
	}

	bgun_is_using_secondary_function();
}

s8 bgun_free_fireslot_wrapper(s32 slotnum)
{
#if VERSION < VERSION_NTSC_1_0
	if (slotnum >= 0) {
		if (g_Fireslots[slotnum].unk04nb && sndGetState(g_Fireslots[slotnum].unk04nb) != AL_STOPPED) {
			audioStop(g_Fireslots[slotnum].unk04nb);
		}

		if (g_Fireslots[slotnum].unk08nb && sndGetState(g_Fireslots[slotnum].unk08nb) != AL_STOPPED) {
			audioStop(g_Fireslots[slotnum].unk08nb);
		}
	}
#endif

	return bgun_free_fireslot(slotnum);
}

s8 bgun_free_fireslot(s32 fireslot_id)
{
#if VERSION >= VERSION_NTSC_1_0
	if (fireslot_id >= 0 && fireslot_id < ARRAYCOUNT(g_Fireslots)) {
		g_Fireslots[fireslot_id].endlvframe = -1;
	}
#else
	if (fireslot_id >= 0) {
		g_Fireslots[fireslot_id].endlvframe = -1;
	}
#endif

	return -1;
}

s32 bgun_allocate_fireslot(void)
{
	s32 index = -1;
	s32 i;

	for (i = 0; i < ARRAYCOUNT(g_Fireslots); i++) {
		if (g_Fireslots[i].endlvframe < 0) {
			g_Fireslots[i].endlvframe = 0;

#if VERSION < VERSION_NTSC_1_0
			g_Fireslots[i].unk04nb = 0;
			g_Fireslots[i].unk08nb = 0;
#endif

			g_Fireslots[i].beam.age = -1;
			index = i;
			break;
		}
	}

	return index;
}

void bgun_render(Gfx **gdlptr)
{
	Gfx *gdl = *gdlptr;
	struct modelrenderdata renderdata = {NULL, true, 3};
	struct player *player;
	s32 handnum;

	static bool renderhand = true;

	player = g_Vars.currentplayer;

	if (player->visionmode == VISIONMODE_XRAY) {
		for (handnum = 0; handnum < 2; handnum++) {
			if (g_Vars.currentplayer->hands[handnum].firedrocket) {
				g_Vars.currentplayer->hands[handnum].rocket = NULL;
			}
		}
		return;
	}

	gdl = zbuf_save_artifact_depths(gdl);
	gdl = vi_prepare_zbuf(gdl);
	gdl = vi0000b1d0(gdl);

	gDPSetScissor(gdl++, G_SC_NON_INTERLACE, vi_get_view_left(), vi_get_view_top(),
			vi_get_view_left() + vi_get_view_width(), vi_get_view_top() + vi_get_view_height());

	gdl = vi0000aca4(gdl, 1.5, 1000);

	if (g_Vars.currentplayer->teleportstate != TELEPORTSTATE_INACTIVE) {
		f32 f2;

		if (options_get_screen_ratio() == SCREENRATIO_16_9) {
			f2 = player_get_aspect_ratio() * 1.3333334f;
		} else {
			f2 = player_get_aspect_ratio();
		}

		gdl = vi0000b0e8(gdl, 60, f2);
	}

	if (PLAYERCOUNT() == 1 && IS8MB()) {
		gdl = lasersight_render_beam(gdl);
	}

	for (handnum = 0; handnum < 2; handnum++) {
		struct hand *hand;
		s32 stack;
		s32 alpha;
		s32 weaponnum;
		struct modelnode *node;
		u32 colour;

		hand = &player->hands[handnum];

		weaponnum = bgun_get_weapon_num2(handnum);

		if (hand->visible) {
			gdl = beam_render(gdl, &hand->beam, 0, TEX_BEAM_ORANGE);

			if (gset_has_weapon_flag(hand->gset.weaponnum, WEAPONFLAG_BRIGHTER)) {
				gSPSetLights1(gdl++, var80070090);
				gSPLookAt(gdl++, cam_get_look_at());
			}

			gSPPerspNormalize(gdl++, mtx00016dcc(0, 300));

			// There is support for guns having a TV screen on them
			// but no guns have this model part so it's not used.
			node = model_get_part(hand->gunmodel.definition, MODELPART_0010);

			if (node) {
				union modelrwdata *rwdata = model_get_node_rw_data(&hand->gunmodel, model_get_part(hand->gunmodel.definition, MODELPART_0011));

				if (rwdata) {
					rwdata->toggle.visible = true;
				}

				gdl = tvscreen_render(&hand->gunmodel, node, &g_TvCmdlistBondPanCopy, gdl, 0, 1);
			}

			renderdata.gdl = gdl;
			renderdata.unk30 = 4;

			if (USINGDEVICE(DEVICE_NIGHTVISION) || USINGDEVICE(DEVICE_IRSCANNER)) {
				u8 *col = player->gunshadecol;
				u32 shade;
				s32 spb0[4];
				s32 spa0[4];

				shade = (col[0] > col[1] && col[0] > col[2])
					? col[0]
					: (col[1] > col[2]) ? col[1] : col[2];

				renderdata.envcolour = (shade << 24 | shade << 16 | shade << 8) + col[3];

				if (USINGDEVICE(DEVICE_NIGHTVISION)) {
					spb0[0] = g_GogglesChrColourIntensity;
					spb0[1] = g_GogglesChrColourIntensity;
					spb0[2] = g_GogglesChrColourIntensity;
					spb0[3] = g_GogglesChrColourAlpha;

					colour = (spb0[0] << 24 | spb0[1] << 16 | spb0[2] << 8) + spb0[3];
				} else if (USINGDEVICE(DEVICE_IRSCANNER)) {
					spa0[0] = 0xff;
					spa0[1] = 0;
					spa0[2] = 0;
					spa0[3] = 0x80;

					colour = (spa0[0] << 24 | spa0[1] << 16 | spa0[2] << 8) + spa0[3];
				}

				if (weaponnum == WEAPON_UNARMED) {
					renderdata.envcolour = colour;
				}
			} else {
				renderdata.envcolour = player->gunshadecol[0] << 24 | player->gunshadecol[1] << 16 | player->gunshadecol[2] << 8 | player->gunshadecol[3];
				colour = renderdata.envcolour;

				if (hand->gset.weaponnum == WEAPON_MAULER) {
					u32 weight = hand->mm_maulercharge * 50.0f;
					renderdata.envcolour = colour_blend(0xff00007f, renderdata.envcolour, weight);
				}
			}

			// Apply transparency based on player's cloak
			alpha = chr_get_cloak_alpha(player->prop->chr);

			if (alpha < 255) {
				alpha *= 0.74509805f;
				renderdata.fogcolour = renderdata.envcolour;
				renderdata.envcolour = 65 + alpha;
				renderdata.unk30 = 5;
				colour = renderdata.envcolour;
			}

			renderdata.zbufferenabled = true;

			mtx00016760();

			// Render rocket launcher's rocket if it's in Jo's hand or in the launcher
			if (hand->rocket) {
				struct model *rocketmodel = hand->rocket->base.model;

#if VERSION >= VERSION_NTSC_1_0
				bool sp94 = false;

				if (rocketmodel && rocketmodel->definition) {
					sp94 = true;

					model_render(&renderdata, rocketmodel);

					mtx_f2l_bulk(rocketmodel->matrices, rocketmodel->definition->nummatrices);

					if (hand->firedrocket) {
						hand->rocket = NULL;
					}
				}

				if (sp94);
#else
				model_render(&renderdata, rocketmodel);

				mtx_f2l_bulk(rocketmodel->matrices, rocketmodel->definition->nummatrices);

				if (hand->firedrocket) {
					hand->rocket = NULL;
				}
#endif
			}

			if (gset_has_weapon_flag(weaponnum, WEAPONFLAG_DUALFLIP)) {
				gSPClearGeometryMode(renderdata.gdl++, G_CULL_BOTH);

				if (handnum == HAND_RIGHT) {
					renderdata.cullmode = CULLMODE_BACK;
				} else {
					renderdata.cullmode = CULLMODE_FRONT;
				}
			}

			// Slide the laser's liquid texture
			if (PLAYERCOUNT() == 1) {
				s32 axis;
				s32 i;
				s32 j;

				node = model_get_part(hand->gunmodel.definition, MODELPART_GUN_LASERLIQUID);

				if (node) {
					struct modelrodata_gundl *rodata = &node->rodata->gundl;

					for (axis = 1; axis < 2; axis++) {
						for (i = 0; i < rodata->numvertices; i++) {
							rodata->vertices[i].tc[axis] -= g_Vars.lvupdate240 * PALUP(25);

							if (rodata->vertices[i].tc[axis] < -0x6000) {
								for (j = 0; j < rodata->numvertices; j++) {
									rodata->vertices[j].tc[axis] += 0x2000;
								}
							}
						}
						break;
					}
				}
			}

			// Render the gun
			model_render(&renderdata, &hand->gunmodel);

			// Render the hand
			if (player->gunctrl.handmodeldef && renderhand) {
				u32 prevcolour = renderdata.envcolour;

				hand->handmodel.matrices = hand->gunmodel.matrices;

				model_update_relations(&hand->handmodel);

				renderdata.envcolour = colour;
				model_render(&renderdata, &hand->handmodel);
				renderdata.envcolour = prevcolour;
			}

			// Clean up
			gdl = renderdata.gdl;

			if (gset_has_weapon_flag(weaponnum, WEAPONFLAG_DUALFLIP)) {
				gSPClearGeometryMode(gdl++, G_CULL_BOTH);
			}

			mtx_f2l_bulk(hand->gunmodel.matrices, hand->gunmodel.definition->nummatrices);
			mtx00016784();

			gSPPerspNormalize(gdl++, vi_get_persp_scale());
		}
	}

	casings_render(&gdl);
	zbuf_swap();

	gdl = zbuf_configure_rdp(gdl);
	gdl = vi0000b1d0(gdl);

	gDPSetScissor(gdl++, G_SC_NON_INTERLACE, vi_get_view_left(), vi_get_view_top(),
			vi_get_view_left() + vi_get_view_width(), vi_get_view_top() + vi_get_view_height());

	*gdlptr = gdl;
}

/**
 * Find and return an available audio handle out of a pool of four.
 */
struct sndstate **bgun_allocate_audio_handle(void)
{
	s32 i;

	for (i = 0; i < ARRAYCOUNT(g_BgunAudioHandles); i++) {
		if (g_BgunAudioHandles[i] == NULL) {
			return &g_BgunAudioHandles[i];
		}
	}

	return NULL;
}

void bgun_play_prop_hit_sound(struct gset *gset, struct prop *prop, s32 texturenum)
{
#if VERSION >= VERSION_NTSC_1_0
	u32 rand1 = random();
	u32 rand2 = random();
	struct sndstate **handle;

	if (g_Vars.lvupdate240 <= 0) {
		return;
	}

	if (texturenum >= 0 && texturenum < NUM_TEXTURES
			&& g_SurfaceTypes[g_Textures[texturenum].soundsurfacetype]->numsounds == 0) {
		return;
	}

	if (gset->weaponnum == WEAPON_REMOTEMINE
			|| gset->weaponnum == WEAPON_PROXIMITYMINE
			|| gset->weaponnum == WEAPON_TIMEDMINE
			|| gset->weaponnum == WEAPON_COMMSRIDER
			|| gset->weaponnum == WEAPON_TRACERBUG
			|| gset->weaponnum == WEAPON_TARGETAMPLIFIER
			|| gset->weaponnum == WEAPON_ECMMINE) {
		ps_create(NULL, prop, SFX_80AA, -1, -1, 0, 0, PSTYPE_NONE, NULL, -1, NULL, -1, -1, -1, -1);
		return;
	}

	handle = bgun_allocate_audio_handle();

	if (handle) {
		if (prop->type == PROPTYPE_CHR || prop->type == PROPTYPE_PLAYER) {
			struct chrdata *chr = prop->chr;
			s16 soundnum = -1;
			bool overridden = false;
			s32 vol;
			s32 pan;

			if (chr_get_shield(chr) > 0) {
				soundnum = SFX_SHIELD_DAMAGE;
			} else if (gset->weaponnum == WEAPON_COMBATKNIFE
					|| gset->weaponnum == WEAPON_COMBATKNIFE // duplicate
					|| gset->weaponnum == WEAPON_BOLT) {
				soundnum = SFX_05F6;
				overridden = true;
			} else if (gset->weaponnum == WEAPON_UNARMED
					|| (gset->weaponfunc == FUNC_SECONDARY
						&& (gset->weaponnum == WEAPON_FALCON2
							|| gset->weaponnum == WEAPON_FALCON2_SILENCER
							|| gset->weaponnum == WEAPON_FALCON2_SCOPE
							|| gset->weaponnum == WEAPON_DY357MAGNUM
							|| gset->weaponnum == WEAPON_DY357LX))) {
				s16 sounds[] = { SFX_002F, SFX_0030, SFX_0031 };
				soundnum = sounds[rand1 % ARRAYCOUNT(sounds)];
			} else {
				s16 sounds[] = { SFX_HIT_CHR, SFX_HIT_CHR };
				soundnum = sounds[rand1 % ARRAYCOUNT(sounds)];
			}

			if (soundnum != -1) {
				ps_get_theoretical_vol_pan(&prop->pos, prop->rooms, soundnum, &vol, &pan);

				if (vol) {
					snd_start(var80095200, soundnum, handle, -1, -1, -1, -1, -1);

					if (*handle) {
						snd_adjust(handle, 0, vol, pan, soundnum, 1, 1, -1, 1);
					}
				}
			}

			if (overridden) {
				return;
			}
		} else {
			s16 soundnum = -1;
			bool overridden = false;
			s32 vol;
			s32 pan;
			u32 stack;

			if (texturenum == 10000) {
				soundnum = SFX_SHIELD_DAMAGE;
			} else if (gset->weaponnum == WEAPON_LASER) {
				if (gset->weaponfunc == FUNC_PRIMARY || ((gset->lasershots % 4) == 0 && (random() % 2))) {
					if ((random() % 2) == 0) {
						soundnum = SFX_CLOAK_ON;
					} else {
						soundnum = SFX_CLOAK_OFF;
					}
				}

				overridden = true;
			} else {
				if (gset->weaponnum == WEAPON_COMBATKNIFE || gset->weaponnum == WEAPON_BOLT) {
					soundnum = SFX_HIT_METAL_8079;
					overridden = true;
				} else {
					s16 sounds[] = {
						SFX_001B, SFX_001C, SFX_001D, SFX_001E,
						SFX_001B, SFX_001C, SFX_001D, SFX_001E,
						SFX_001B, SFX_001C, SFX_001D, SFX_001E,
						SFX_0023, SFX_0024, SFX_0025, SFX_0026,
						SFX_0027, SFX_0028, SFX_0029, SFX_002A,
					};

					soundnum = sounds[rand1 % ARRAYCOUNT(sounds)];
				}
			}

			if (soundnum != -1) {
				ps_get_theoretical_vol_pan(&prop->pos, prop->rooms, soundnum, &vol, &pan);

				if (vol) {
					snd_start(var80095200, soundnum, handle, -1, -1, -1, -1, -1);

					if (*handle) {
						snd_adjust(handle, 0, vol, pan, soundnum, 1, 1, -1, 1);
					}
				}
			}

			if (overridden) {
				return;
			}
		}
	}

	if (texturenum >= 0 && texturenum < NUM_TEXTURES && g_SurfaceTypes[g_Textures[texturenum].soundsurfacetype]) {
		s16 soundnum = -1;

		handle = bgun_allocate_audio_handle();

		if (handle) {
			if (g_SurfaceTypes[g_Textures[texturenum].soundsurfacetype]->numsounds > 0) {
				s32 index = rand2 % g_SurfaceTypes[g_Textures[texturenum].soundsurfacetype]->numsounds;
				soundnum = g_SurfaceTypes[g_Textures[texturenum].soundsurfacetype]->sounds[index];

				if (soundnum != -1) {
					snd_start(var80095200, soundnum, handle, -1, -1, -1, -1, -1);
				}
			}

			if (*handle && soundnum != -1) {
				ps_apply_vol_pan(*handle, &prop->pos, 400, 2500, 3000, prop->rooms, soundnum, AL_VOL_FULL, 0);
			}
		}
	}
#else
	u32 rand1 = random();
	u32 rand2 = random();
	struct sndstate **handle;

	if (g_Vars.lvupdate240 <= 0) {
		return;
	}

	if (texturenum >= 0 && texturenum < NUM_TEXTURES
			&& g_SurfaceTypes[g_Textures[texturenum].soundsurfacetype]->numsounds == 0) {
		return;
	}

	if (gset->weaponnum == WEAPON_REMOTEMINE
			|| gset->weaponnum == WEAPON_PROXIMITYMINE
			|| gset->weaponnum == WEAPON_TIMEDMINE
			|| gset->weaponnum == WEAPON_COMMSRIDER
			|| gset->weaponnum == WEAPON_TRACERBUG
			|| gset->weaponnum == WEAPON_TARGETAMPLIFIER
			|| gset->weaponnum == WEAPON_ECMMINE) {
		ps_create(NULL, prop, SFX_80AA, -1, -1, 0, 0, PSTYPE_NONE, NULL, -1, NULL, -1, -1, -1, -1);
		return;
	}

	handle = bgun_allocate_audio_handle();

	if (handle) {
		if (prop->type == PROPTYPE_CHR || prop->type == PROPTYPE_PLAYER) {
			struct chrdata *chr = prop->chr;
			s16 soundnum;
			bool overridden = false;

			if (chr_get_shield(chr) > 0) {
				snd_start(var80095200, SFX_SHIELD_DAMAGE, handle, -1, -1, -1, -1, -1);
				soundnum = SFX_SHIELD_DAMAGE;
			} else if (gset->weaponnum == WEAPON_COMBATKNIFE
					|| gset->weaponnum == WEAPON_COMBATKNIFE // duplicate
					|| gset->weaponnum == WEAPON_BOLT) {
				snd_start(var80095200, SFX_05F6, handle, -1, -1, -1, -1, -1);
				soundnum = SFX_05F6;
				overridden = true;
			} else if (gset->weaponnum == WEAPON_UNARMED
					|| (gset->weaponfunc == FUNC_SECONDARY
						&& (gset->weaponnum == WEAPON_FALCON2
							|| gset->weaponnum == WEAPON_FALCON2_SILENCER
							|| gset->weaponnum == WEAPON_FALCON2_SCOPE
							|| gset->weaponnum == WEAPON_DY357MAGNUM
							|| gset->weaponnum == WEAPON_DY357LX))) {
				s16 sounds[] = { SFX_002F, SFX_0030, SFX_0031 };
				soundnum = sounds[rand1 % ARRAYCOUNT(sounds)];
				snd_start(var80095200, soundnum, handle, -1, -1, -1, -1, -1);
			} else {
				s16 sounds[] = { SFX_HIT_CHR, SFX_HIT_CHR };
				soundnum = sounds[rand1 % ARRAYCOUNT(sounds)];
				snd_start(var80095200, soundnum, handle, -1, -1, -1, -1, -1);
			}

			if (*handle) {
				ps_apply_vol_pan(*handle, &prop->pos, 400, 2500, 3000, prop->rooms, soundnum, AL_VOL_FULL, 0);
			}

			if (overridden) {
				return;
			}
		} else {
			s16 soundnum;
			bool overridden = false;
			u32 stack;

			if (texturenum == 10000) {
				snd_start(var80095200, SFX_SHIELD_DAMAGE, handle, -1, -1, -1, -1, -1);
				soundnum = SFX_SHIELD_DAMAGE;
			} else if (gset->weaponnum == WEAPON_LASER) {
				if (gset->weaponfunc == FUNC_PRIMARY || (gset->lasershots % 8) == 0) {
					if ((random() % 2) == 0) {
						soundnum = SFX_CLOAK_ON;
					} else {
						soundnum = SFX_CLOAK_OFF;
					}

					snd_start(var80095200, soundnum, handle, -1, -1, -1, -1, -1);
					overridden = true;
				}
			} else {
				if (gset->weaponnum == WEAPON_COMBATKNIFE || gset->weaponnum == WEAPON_BOLT) {
					soundnum = SFX_HIT_METAL_8079;
					snd_start(var80095200, soundnum, handle, -1, -1, -1, -1, -1);
					overridden = true;
				} else {
					s16 sounds[] = {
						SFX_001B, SFX_001C, SFX_001D, SFX_001E,
						SFX_001B, SFX_001C, SFX_001D, SFX_001E,
						SFX_001B, SFX_001C, SFX_001D, SFX_001E,
						SFX_0023, SFX_0024, SFX_0025, SFX_0026,
						SFX_0027, SFX_0028, SFX_0029, SFX_002A,
					};

					soundnum = sounds[rand1 % ARRAYCOUNT(sounds)];
					snd_start(var80095200, soundnum, handle, -1, -1, -1, -1, -1);
				}
			}

			if (*handle) {
				ps_apply_vol_pan(*handle, &prop->pos, 400, 2500, 3000, prop->rooms, soundnum, AL_VOL_FULL, 0);
			}

			if (overridden) {
				return;
			}
		}
	}

	if (texturenum >= 0 && texturenum < NUM_TEXTURES && g_SurfaceTypes[g_Textures[texturenum].soundsurfacetype]) {
		s16 soundnum = -1;

		handle = bgun_allocate_audio_handle();

		if (handle) {
			if (g_SurfaceTypes[g_Textures[texturenum].soundsurfacetype]->numsounds > 0) {
				s32 index = rand2 % g_SurfaceTypes[g_Textures[texturenum].soundsurfacetype]->numsounds;
				soundnum = g_SurfaceTypes[g_Textures[texturenum].soundsurfacetype]->sounds[index];

				snd_start(var80095200, soundnum, handle, -1, -1, -1, -1, -1);
			}

			if (*handle) {
				ps_apply_vol_pan(*handle, &prop->pos, 400, 2500, 3000, prop->rooms, soundnum, AL_VOL_FULL, 0);
			}
		}
	}
#endif
}

void bgun_play_glass_hit_sound(struct coord *pos, RoomNum *rooms, s32 texturenum)
{
	if (g_Vars.lvupdate240 > 0) {
		struct sndstate **handle = bgun_allocate_audio_handle();

		if (handle) {
			snd_start(var80095200, SFX_HIT_GLASS, handle, -1, -1, -1, -1, -1);

			if (*handle) {
				ps_apply_vol_pan(*handle, pos, 400, 2500, 3000, rooms, SFX_HIT_GLASS, AL_VOL_FULL, 0);
			}
		}
	}
}

void bgun_play_bg_hit_sound(struct gset *gset, struct coord *hitpos, s32 texturenum, RoomNum *rooms)
{
#if VERSION >= VERSION_NTSC_1_0
	struct sndstate **handle;
	u32 rand1 = random();
	u32 rand2 = random();
	bool playdefault;
	s16 soundnum;
	bool overridden;

	if (g_Vars.lvupdate240 <= 0) {
		return;
	}

	if (texturenum >= 0 && texturenum < NUM_TEXTURES && g_SurfaceTypes[g_Textures[texturenum].soundsurfacetype]->numsounds == 0) {
		return;
	}

	playdefault = true;
	handle = bgun_allocate_audio_handle();

	if (handle) {
		soundnum = -1;
		overridden = false;

		if (gset->weaponnum == WEAPON_LASER) {
			playdefault = false;

			if (gset->weaponfunc == FUNC_PRIMARY || ((gset->lasershots % 4) == 0 && (random() % 2))) {
				// Laser sounds
				s16 sounds[] = {SFX_CLOAK_ON, SFX_CLOAK_OFF};
				soundnum = sounds[rand1 % ARRAYCOUNT(sounds)];
				snd_start(var80095200, soundnum, handle, -1, -1, -1, -1, -1);
				overridden = true;
			}
		} else if (gset->weaponnum == WEAPON_COMBATKNIFE || gset->weaponnum == WEAPON_BOLT) {
			// Knives and bolts make a metal sound
			soundnum = SFX_HIT_METAL_8079;
			snd_start(var80095200, soundnum, handle, -1, -1, -1, -1, -1);
			overridden = true;
		} else if (gset->weaponnum == WEAPON_REMOTEMINE
				|| gset->weaponnum == WEAPON_PROXIMITYMINE
				|| gset->weaponnum == WEAPON_TIMEDMINE
				|| gset->weaponnum == WEAPON_COMMSRIDER
				|| gset->weaponnum == WEAPON_TRACERBUG
				|| gset->weaponnum == WEAPON_TARGETAMPLIFIER
				|| gset->weaponnum == WEAPON_ECMMINE) {
			// Mine landing/activation sound
			soundnum = SFX_80AA;
			snd_start(var80095200, soundnum, handle, -1, -1, -1, -1, -1);
			overridden = true;
		} else {
			// Ricochet sounds
			s16 sounds[] = {
				SFX_0013, SFX_0014, SFX_0015, SFX_0016,
				SFX_0017, SFX_0018, SFX_0019, SFX_001A,
				SFX_0017, SFX_0018, SFX_0019, SFX_001A,
				SFX_0017, SFX_0018, SFX_0019, SFX_001A,
				SFX_001F, SFX_0020, SFX_0020, SFX_0021,
				SFX_001F, SFX_0020, SFX_0020, SFX_0021,
				SFX_001F, SFX_0020, SFX_0020, SFX_0021,
				SFX_0023, SFX_0024, SFX_0025, SFX_0026,
				SFX_0027, SFX_0028, SFX_0029, SFX_002A,
			};

			soundnum = sounds[rand1 % ARRAYCOUNT(sounds)];
			snd_start(var80095200, soundnum, handle, -1, -1, -1, -1, -1);
			overridden = false;
		}

		if (*handle != NULL) {
			ps_apply_vol_pan(*handle, hitpos, 400, 2500, 3000, rooms, soundnum, AL_VOL_FULL, 0);
		}

		if (overridden) {
			return;
		}
	}

	if (playdefault) {
		handle = bgun_allocate_audio_handle();

		if (handle != NULL && texturenum >= 0 && texturenum < NUM_TEXTURES) {
			s16 soundnum;
			struct surfacetype *type = g_SurfaceTypes[g_Textures[texturenum].soundsurfacetype];

			if (type->numsounds > 0) {
				soundnum = -1;

				if (type != NULL) {
					s32 index = rand2 % type->numsounds;
					soundnum = type->sounds[index];
					snd_start(var80095200, soundnum, handle, -1, -1, -1, -1, -1);
				}

				if (*handle != NULL) {
					ps_apply_vol_pan(*handle, hitpos, 400, 2500, 3000, rooms, soundnum, AL_VOL_FULL, 0);
				}
			}
		}
	}
#else
	struct sndstate **handle;
	u32 rand1 = random();
	u32 rand2 = random();
	s16 soundnum;
	bool overridden;

	if (g_Vars.lvupdate240 <= 0) {
		return;
	}

	if (texturenum >= 0 && texturenum < NUM_TEXTURES && g_SurfaceTypes[g_Textures[texturenum].soundsurfacetype]->numsounds == 0) {
		return;
	}

	handle = bgun_allocate_audio_handle();

	if (handle) {
		overridden = false;

		if (gset->weaponnum == WEAPON_LASER) {
			if (gset->weaponfunc == FUNC_PRIMARY || (gset->lasershots % 8) == 0) {
				// Laser sounds
				s16 sounds[] = {SFX_CLOAK_ON, SFX_CLOAK_OFF};
				soundnum = sounds[rand1 % ARRAYCOUNT(sounds)];
				snd_start(var80095200, soundnum, handle, -1, -1, -1, -1, -1);
				overridden = true;
			}
		} else if (gset->weaponnum == WEAPON_COMBATKNIFE || gset->weaponnum == WEAPON_BOLT) {
			// Knives and bolts make a metal sound
			soundnum = SFX_HIT_METAL_8079;
			snd_start(var80095200, soundnum, handle, -1, -1, -1, -1, -1);
			overridden = true;
		} else if (gset->weaponnum == WEAPON_REMOTEMINE
				|| gset->weaponnum == WEAPON_PROXIMITYMINE
				|| gset->weaponnum == WEAPON_TIMEDMINE
				|| gset->weaponnum == WEAPON_COMMSRIDER
				|| gset->weaponnum == WEAPON_TRACERBUG
				|| gset->weaponnum == WEAPON_TARGETAMPLIFIER
				|| gset->weaponnum == WEAPON_ECMMINE) {
			// Mine landing/activation sound
			snd_start(var80095200, SFX_80AA, handle, -1, -1, -1, -1, -1);
			overridden = true;
		} else {
			// Ricochet sounds
			s16 sounds[] = {
				SFX_0013, SFX_0014, SFX_0015, SFX_0016,
				SFX_0017, SFX_0018, SFX_0019, SFX_001A,
				SFX_0017, SFX_0018, SFX_0019, SFX_001A,
				SFX_0017, SFX_0018, SFX_0019, SFX_001A,
				SFX_001F, SFX_0020, SFX_0020, SFX_0021,
				SFX_001F, SFX_0020, SFX_0020, SFX_0021,
				SFX_001F, SFX_0020, SFX_0020, SFX_0021,
				SFX_0023, SFX_0024, SFX_0025, SFX_0026,
				SFX_0027, SFX_0028, SFX_0029, SFX_002A,
			};

			soundnum = sounds[rand1 % ARRAYCOUNT(sounds)];
			snd_start(var80095200, soundnum, handle, -1, -1, -1, -1, -1);
			overridden = false;
		}

		if (*handle != NULL) {
			ps_apply_vol_pan(*handle, hitpos, 400, 2500, 3000, rooms, soundnum, AL_VOL_FULL, 0);
		}

		if (overridden) {
			return;
		}
	}

	// Play default surface hit sound
	handle = bgun_allocate_audio_handle();

	if (handle != NULL && texturenum >= 0 && texturenum < NUM_TEXTURES) {
		s16 soundnum;
		struct surfacetype *type = g_SurfaceTypes[g_Textures[texturenum].soundsurfacetype];

		if (type->numsounds > 0) {
			soundnum = -1;

			if (type != NULL) {
				s32 index = rand2 % type->numsounds;
				soundnum = type->sounds[index];
				snd_start(var80095200, soundnum, handle, -1, -1, -1, -1, -1);
			}

			if (*handle != NULL) {
				ps_apply_vol_pan(*handle, hitpos, 400, 2500, 3000, rooms, soundnum, AL_VOL_FULL, 0);
			}
		}
	}
#endif
}

void bgun_set_trigger_on(s32 handnum, bool on)
{
	struct hand *hand = &g_Vars.currentplayer->hands[handnum];

	hand->triggerprev = hand->triggeron;
	hand->triggeron = on;

	if (!on) {
		hand->triggerreleased = true;
	}
}

#define SETFUNCPRI() g_PlayerConfigsArray[g_Vars.currentplayerstats->mpindex].gunfuncs[(g_Vars.currentplayer->gunctrl.weaponnum - 1) >> 3] &= ~(1 << ((g_Vars.currentplayer->gunctrl.weaponnum - 1) & 7))
#define SETFUNCSEC() g_PlayerConfigsArray[g_Vars.currentplayerstats->mpindex].gunfuncs[(g_Vars.currentplayer->gunctrl.weaponnum - 1) >> 3] |= 1 << ((g_Vars.currentplayer->gunctrl.weaponnum - 1) & 7)

/**
 * This is called once B has been held for 25 ticks, or earlier if pressing B+Z.
 *
 * The function may choose whether to change the gun function,
 * or activate the secondary function without switching to it.
 *
 * Return the following;
 * - USETIMER_CONTINUE if the B button timer should continue incrementing.
 * - USETIMER_STOP if the B button timer should stop (ie. the B press is consumed)
 * - USETIMER_REPEAT if this function should be called again on each frame until B is released.
 */
s32 bgun_consider_toggle_gun_function(s32 usedowntime, bool trigpressed, bool fromactivemenu)
{
	switch (bgun_get_weapon_num(HAND_RIGHT)) {
	case WEAPON_SNIPERRIFLE:
		// At 25 ticks (or B+Z), start showing the new function
		g_Vars.currentplayer->gunctrl.invertgunfunc = true;

		// B+Z immediately triggers crouch or stand
		if (trigpressed) {
			return USETIMER_STOP;
		}

		// Don't do anything if B hasn't been held for 50/60ths of a second
		if (usedowntime < TICKS(50)) {
			return USETIMER_CONTINUE;
		}

		if (g_Vars.currentplayer->hands[HAND_RIGHT].gset.weaponfunc != FUNC_SECONDARY) {
			return USETIMER_CONTINUE;
		}

		// Do crouch or stand
		g_Vars.currentplayer->hands[HAND_RIGHT].activatesecondary = true;
		return USETIMER_REPEAT;
	case WEAPON_RCP120:
	case WEAPON_LAPTOPGUN:
	case WEAPON_DRAGON:
	case WEAPON_REMOTEMINE:
		// These weapons use temporary alt functions
		g_Vars.currentplayer->gunctrl.invertgunfunc = true;

		if (fromactivemenu && bgun_is_using_secondary_function() == true) {
			g_Vars.currentplayer->hands[HAND_RIGHT].activatesecondary = true;
		}

		return USETIMER_STOP;
	case WEAPON_MAULER:
	case WEAPON_CMP150:
	case WEAPON_K7AVENGER:
	case WEAPON_AR34:
	case WEAPON_FARSIGHT:
	case WEAPON_TIMEDMINE:
		// These weapons disallow B+Z
		if (!trigpressed) {
			if (VALIDWEAPON()) {
				if (1 - FUNCISSEC()) {
					SETFUNCSEC();
				} else {
					SETFUNCPRI();
				}
			}

			return USETIMER_STOP;
		}

		return USETIMER_CONTINUE;
	default:
		if (trigpressed) {
			g_Vars.currentplayer->gunctrl.invertgunfunc = true;
		} else {
			if (VALIDWEAPON()) {
				if (!FUNCISSEC()) {
					SETFUNCSEC();
				} else {
					SETFUNCPRI();
				}
			}
		}

		return USETIMER_STOP;
	}
}

void bgun0f0a8c50(void)
{
	if (g_Vars.currentplayer->hands[HAND_RIGHT].activatesecondary == false) {
		g_Vars.currentplayer->gunctrl.invertgunfunc = false;
	}
}

bool bgun_is_using_secondary_function(void)
{
	struct player *player = g_Vars.currentplayer;
	s32 weaponnum = player->gunctrl.weaponnum;

	if (weaponnum >= WEAPON_UNARMED && weaponnum <= WEAPON_COMBATBOOST) {
		s32 index = (weaponnum - 1) >> 3;
		s32 value = 1 << ((weaponnum - 1) & 7);

		if (g_PlayerConfigsArray[g_Vars.currentplayerstats->mpindex].gunfuncs[index] & value) {
			if (player->gunctrl.invertgunfunc == true) {
				return false;
			}

			return true;
		}
	}

	if (player->gunctrl.invertgunfunc == true) {
		return true;
	}

	return false;
}

/**
 * Tick gun-related things during first-person gameplay.
 *
 * This function is not called during cutscenes.
 */
void bgun_tick_gameplay(bool triggeron)
{
	s32 gunsfiring[2] = {false, false};
	struct player *player = g_Vars.currentplayer;
	s32 i;

	// Remove weapons if in passive mode
	if (g_Vars.currentplayer->gunctrl.passivemode) {
		struct chrdata *chr = g_Vars.currentplayer->prop->chr;
		triggeron = false;

		if (inv_get_count() > 1) {
			inv_clear();
			inv_give_single_weapon(WEAPON_UNARMED);
		}

		if (g_Vars.currentplayer->gunctrl.weaponnum != WEAPON_UNARMED
				&& g_Vars.currentplayer->gunctrl.switchtoweaponnum != WEAPON_UNARMED) {
			bgun_equip_weapon(WEAPON_UNARMED);
		}

		g_Vars.currentplayer->gunctrl.dualwielding = false;
		g_Vars.currentplayer->devicesactive = 0;

		chr->cloakpause = 0;
		chr->cloakfadefrac = 0;
		chr->cloakfadefinished = false;
		chr->hidden &= ~CHRHFLAG_CLOAKED;
	}

	// Remove throwable items from inventory if there's no more left
	for (i = 0; i < inv_get_count(); i++) {
		struct weapondef *weapon;
		s32 weaponnum = inv_get_weapon_num_by_index(i);
		s32 equippedweaponnum;

		switch (weaponnum) {
		case WEAPON_COMBATKNIFE:
		case WEAPON_GRENADE:
		case WEAPON_NBOMB:
		case WEAPON_COMBATBOOST:
		case WEAPON_CLOAKINGDEVICE:
		case WEAPON_ECMMINE:
		case WEAPON_COMMSRIDER:
		case WEAPON_TRACERBUG:
		case WEAPON_TARGETAMPLIFIER:
			weapon = gset_get_weapondef(weaponnum);

			if (weapon && weapon->ammos[0]
					&& bgun_get_ammo_count(weapon->ammos[0]->type) == 0) {
				equippedweaponnum = bgun_get_weapon_num(HAND_RIGHT);
				inv_remove_item_by_num(weaponnum);

				if (weaponnum == equippedweaponnum && !inv_has_single_weapon_inc_all_guns(weaponnum)) {
					inv_calculate_current_index();
					bgun_equip_weapon(inv_get_weapon_num_by_index(g_Vars.currentplayer->equipcuritem));
				}
			}
		}
	}

	if (g_Vars.tickmode == TICKMODE_CUTSCENE) {
		triggeron = false;
		g_Vars.currentplayer->hands[HAND_LEFT].firing = false;
		g_Vars.currentplayer->hands[HAND_RIGHT].firing = false;
	}

	player->playertriggerprev = player->playertriggeron;
	player->playertriggeron = triggeron;

	if (triggeron == false && player->playertriggerprev) {
		// Releasing trigger
		player->doautoselect = true;
	}

	// Handle gun firing - particularly alternating
	// between left and right if dual wielding
	if (player->playertriggeron) {
		player->playertrigtime240 += g_Vars.lvupdate240;

		if (player->hands[HAND_LEFT].inuse
				&& player->hands[HAND_RIGHT].inuse
				&& player->gunctrl.weaponnum != WEAPON_REMOTEMINE) {
			if (player->playertrigtime240 > TICKS(80)) {
				gunsfiring[player->curguntofire] = 1;

				if (bgun_clip_has_ammo(1 - player->curguntofire) || player->hands[1 - player->curguntofire].triggeron) {
					gunsfiring[1 - player->curguntofire] = 1;
				}
			} else {
				if (player->playertriggerprev == false &&
						(bgun_clip_has_ammo(1 - player->curguntofire) || !bgun_clip_has_ammo(player->curguntofire))) {
					player->curguntofire = 1 - player->curguntofire;
				}

				gunsfiring[player->curguntofire] = 1;
				gunsfiring[1 - player->curguntofire] = 0;
			}
		} else {
			if (!player->hands[player->curguntofire].inuse
					&& player->hands[1 - player->curguntofire].inuse) {
				player->curguntofire = 1 - player->curguntofire;
			}

			if (player->gunctrl.weaponnum == WEAPON_REMOTEMINE) {
				player->curguntofire = 0;
			}

			gunsfiring[player->curguntofire] = 1;
			gunsfiring[1 - player->curguntofire] = 0;
		}
	} else {
		player->playertrigtime240 = 0;
	}

	bgun_set_trigger_on(HAND_RIGHT, gunsfiring[0]);
	bgun_set_trigger_on(HAND_LEFT, gunsfiring[1]);

	if (g_Vars.tickmode == TICKMODE_NORMAL && g_Vars.lvupdate240 > 0) {
		bgun_tick_hand(HAND_RIGHT);
		bgun_tick_hand(HAND_LEFT);
		bgun_tick_switch();

		if (cheat_is_active(CHEAT_UNLIMITEDAMMONORELOADS)) {
			s32 i;
			struct weapondef *weapon;
			struct hand *lhand = &g_Vars.currentplayer->hands[HAND_LEFT];
			struct hand *rhand = &g_Vars.currentplayer->hands[HAND_RIGHT];

			weapon = gset_get_weapondef(rhand->gset.weaponnum);

			for (i = 0; i != 2; i++) {
				if (weapon && weapon->ammos[i] &&
						bgun_ammotype_allows_unlimited_ammo(weapon->ammos[i]->type)) {
					rhand->loadedammo[i] = rhand->clipsizes[i];
					lhand->loadedammo[i] = lhand->clipsizes[i];
				}
			}

			bgun_give_max_ammo(false);
		} else if (cheat_is_active(CHEAT_UNLIMITEDAMMO)) {
			bgun_give_max_ammo(false);
		}
	}

	bgun_decrease_noise_radius();

	if (player->resetshadecol) {
		prop_calculate_shade_colour(g_Vars.currentplayer->prop, player->gunshadecol, player->floorcol);
		player->resetshadecol = 0;
	} else {
		u8 shadecol[4];
		prop_calculate_shade_colour(g_Vars.currentplayer->prop, shadecol, player->floorcol);
		colour_tween(player->gunshadecol, shadecol);
	}

	inv_increment_held_time(bgun_get_weapon_num(HAND_RIGHT), bgun_get_weapon_num(HAND_LEFT));
}

void bgun_set_passive_mode(bool enable)
{
	s32 i;

	for (i = 0; i < PLAYERCOUNT(); i++) {
		g_Vars.players[i]->gunctrl.passivemode = enable;
	}
}

void bgun_set_aim_type(u32 aimtype)
{
	g_Vars.currentplayer->aimtype = aimtype;
}

void bgun_set_aim_pos(struct coord *coord)
{
	struct player *player = g_Vars.currentplayer;

	player->hands[HAND_RIGHT].aimpos.x = gset_get_xshift(HAND_RIGHT) + coord->x;
	player->hands[HAND_RIGHT].aimpos.y = coord->y;
	player->hands[HAND_RIGHT].aimpos.z = coord->z;

	player->hands[HAND_LEFT].aimpos.x = gset_get_xshift(HAND_LEFT) + coord->x;
	player->hands[HAND_LEFT].aimpos.y = coord->y;
	player->hands[HAND_LEFT].aimpos.z = coord->z;
}

void bgun_set_hit_pos(struct coord *coord)
{
	struct player *player = g_Vars.currentplayer;

	player->hands[HAND_LEFT].hitpos.x = player->hands[HAND_RIGHT].hitpos.x = coord->x;
	player->hands[HAND_LEFT].hitpos.y = player->hands[HAND_RIGHT].hitpos.y = coord->y;
	player->hands[HAND_LEFT].hitpos.z = player->hands[HAND_RIGHT].hitpos.z = coord->z;
}

void bgun0f0a9494(u32 operation)
{
	switch (operation) {
	case 0:
		g_Vars.currentplayer->hands[HAND_LEFT].hasdotinfo = g_Vars.currentplayer->hands[HAND_RIGHT].hasdotinfo = false;
		break;
	case 1:
		break;
	}
}

void bgun0f0a94d0(u32 operation, struct coord *pos, struct coord *rot)
{
	struct player *player = g_Vars.currentplayer;

	switch (operation) {
	case 0:
		if (pos->x > -100000.0f && pos->x < 100000.0f
				&& pos->y > -100000.0f && pos->y < 100000.0f
				&& pos->z > -100000.0f && pos->z < 100000.0f) {
			player->hands[HAND_RIGHT].hasdotinfo = true;
			player->hands[HAND_LEFT].hasdotinfo = true;

			player->hands[HAND_LEFT].dotpos.x = player->hands[HAND_RIGHT].dotpos.x = pos->x;
			player->hands[HAND_LEFT].dotpos.y = player->hands[HAND_RIGHT].dotpos.y = pos->y;
			player->hands[HAND_LEFT].dotpos.z = player->hands[HAND_RIGHT].dotpos.z = pos->z;

			player->hands[HAND_LEFT].dotrot.x = player->hands[HAND_RIGHT].dotrot.x = rot->x;
			player->hands[HAND_LEFT].dotrot.y = player->hands[HAND_RIGHT].dotrot.y = rot->y;
			player->hands[HAND_LEFT].dotrot.z = player->hands[HAND_RIGHT].dotrot.z = rot->z;
		}
		break;
	case 1:
	case 2:
		lasersight_set_dot(operation - 1, pos, rot);
		break;
	}
}

void bgun_set_gun_ammo_visible(u32 reason, bool enable)
{
	if (enable) {
		g_Vars.currentplayer->gunammooff &= ~reason;
	} else {
		g_Vars.currentplayer->gunammooff |= reason;
	}
}

struct ammotype g_AmmoTypes[] = {
	{ 0,            0, 0  },
	{ 800,          0, 0  }, // AMMOTYPE_PISTOL
	{ 800,          0, 0  }, // AMMOTYPE_SMG
	{ 69,           0, 0  }, // AMMOTYPE_CROSSBOW
	{ 400,          0, -2 }, // AMMOTYPE_RIFLE
	{ 100,          0, 0  }, // AMMOTYPE_SHOTGUN
	{ 100,          0, 0  }, // AMMOTYPE_FARSIGHT
	{ 12,           0, 0  }, // AMMOTYPE_GRENADE
	{ 3,            0, -2 }, // AMMOTYPE_ROCKET
	{ 10,           0, 0  }, // AMMOTYPE_KNIFE
	{ 200,          0, 0  }, // AMMOTYPE_MAGNUM
	{ 40,           0, 0  }, // AMMOTYPE_DEVASTATOR
	{ 10,           0, 1  }, // AMMOTYPE_REMOTE_MINE
	{ 10,           0, 1  }, // AMMOTYPE_PROXY_MINE
	{ 10,           0, 1  }, // AMMOTYPE_TIMED_MINE
	{ 800,          0, 0  }, // AMMOTYPE_REAPER
	{ 15,           0, -2 }, // AMMOTYPE_HOMINGROCKET
	{ 50,           0, 0  }, // AMMOTYPE_DART
	{ 10,           0, 0  }, // AMMOTYPE_NBOMB
	{ 200,          0, 0  }, // AMMOTYPE_SEDATIVE
	{ TICKS(18000), 0, 0  }, // AMMOTYPE_CLOAK
	{ 4,            0, 0  }, // AMMOTYPE_BOOST
	{ 200,          0, 0  }, // AMMOTYPE_PSYCHOSIS
	{ 2,            0, 0  }, // AMMOTYPE_17
	{ 10,           0, 0  }, // AMMOTYPE_BUG
	{ 10,           0, 0  }, // AMMOTYPE_MICROCAMERA
	{ 10,           0, 0  }, // AMMOTYPE_PLASTIQUE
	{ 1000,         0, 0  }, // AMMOTYPE_1B
	{ 10,           0, 0  }, // AMMOTYPE_1C
	{ 50,           0, -1 }, // AMMOTYPE_1D
	{ 1,            0, 0  }, // AMMOTYPE_TOKEN
	{ 200,          0, 0  }, // AMMOTYPE_1F
	{ 10,           0, 0  }, // AMMOTYPE_ECM_MINE
};

void bgun_set_ammo_quantity(s32 ammotype, s32 quantity)
{
	struct player *player = g_Vars.currentplayer;
	s32 weaponnum = bgun_get_weapon_num(HAND_RIGHT);
	s32 funcnum = -1;
	s32 magamount;

	// Check if this ammo type applies to the player's equipped weapon
	if (bgun_get_ammo_type_for_weapon(weaponnum, FUNC_PRIMARY) == ammotype) {
		funcnum = FUNC_PRIMARY;
	}

	if (bgun_get_ammo_type_for_weapon(weaponnum, FUNC_SECONDARY) == ammotype) {
		funcnum = FUNC_SECONDARY;
	}

	if (funcnum != -1 && gset_has_ammo_flag(weaponnum, funcnum, AMMOFLAG_NORESERVE)) {
		// For cloak and combat boost, ammo cannot be held outside of the weapon.
		// So just add it to the loaded clip.
		player->hands[0].loadedammo[funcnum] += quantity;

		if (player->hands[0].loadedammo[funcnum] > player->hands[0].clipsizes[funcnum]) {
			player->hands[0].loadedammo[funcnum] = player->hands[0].clipsizes[funcnum];
		}

		player->ammoheldarr[ammotype] = 0;
		return;
	}

	magamount = 0;

	// For throwable items, the capacity applies to reserve + loaded
	if (funcnum != -1 && gset_has_ammo_flag(weaponnum, funcnum, AMMOFLAG_EQUIPPEDISRESERVE)) {
		magamount = player->hands[0].loadedammo[funcnum] + player->hands[1].loadedammo[funcnum];
	}

	if (quantity > g_AmmoTypes[ammotype].capacity - magamount) {
		player->ammoheldarr[ammotype] = g_AmmoTypes[ammotype].capacity - magamount;
	} else {
		player->ammoheldarr[ammotype] = quantity;
	}
}

s32 bgun_get_reserved_ammo_count(s32 ammotype)
{
	s32 i;
	s32 j;
	s32 total = g_Vars.currentplayer->ammoheldarr[ammotype];
	struct player *player = g_Vars.currentplayer;

	for (i = 0; i < 2; i++) {
		if (player->hands[i].inuse) {
			for (j = 0; j < 2; j++) {
				if (player->gunctrl.ammotypes[j] == ammotype && gset_has_ammo_flag(player->hands[i].gset.weaponnum, j, AMMOFLAG_NORESERVE)) {
					total = total + player->hands[i].loadedammo[j];
				}
			}
		}
	}

	return total;
}

s32 bgun_get_ammo_count(s32 ammotype)
{
	s32 i;
	s32 j;
	s32 total = g_Vars.currentplayer->ammoheldarr[ammotype];
	struct player *player = g_Vars.currentplayer;

	for (i = 0; i < 2; i++) {
		if (player->hands[i].inuse) {
			for (j = 0; j < 2; j++) {
				if (player->gunctrl.ammotypes[j] == ammotype) {
					total = total + player->hands[i].loadedammo[j];
				}
			}
		}
	}

	return total;
}

s32 bgun_get_capacity_by_ammotype(s32 ammotype)
{
	return g_AmmoTypes[ammotype].capacity;
}

bool bgun_ammotype_allows_unlimited_ammo(u32 ammotype)
{
	switch (ammotype) {
	case AMMOTYPE_REMOTE_MINE:
		if (g_Vars.stagenum == STAGE_CHICAGO) {
			return false;
		}
		break;
	case AMMOTYPE_TIMED_MINE:
		if (g_Vars.stagenum == STAGE_AIRFORCEONE) {
			return false;
		}
		break;
	case AMMOTYPE_PSYCHOSIS:
	case AMMOTYPE_17:
	case AMMOTYPE_BUG:
	case AMMOTYPE_MICROCAMERA:
	case AMMOTYPE_PLASTIQUE:
	case AMMOTYPE_1B:
	case AMMOTYPE_1C:
	case AMMOTYPE_1D:
	case AMMOTYPE_TOKEN:
	case AMMOTYPE_1F:
	case AMMOTYPE_ECM_MINE:
		return false;
	}

	return true;
}

void bgun_give_max_ammo(bool force)
{
	s32 i;

	for (i = 0; i < ARRAYCOUNT(g_AmmoTypes); i++) {
		bool give = true;

		if (!force) {
			give = bgun_ammotype_allows_unlimited_ammo(i);
		}

		if (give) {
			bgun_set_ammo_quantity(i, g_AmmoTypes[i].capacity);
		}
	}
}

u32 bgun_get_ammo_type_for_weapon(u32 weaponnum, u32 func)
{
	struct weapondef *weapon = gset_get_weapondef(weaponnum);

	if (!weapon) {
		return 0;
	}

	if (!weapon->ammos[func]) {
		return 0;
	}

	return weapon->ammos[func]->type;
}

s32 bgun_get_ammo_qty_for_weapon(u32 weaponnum, u32 func)
{
	struct weapondef *weapon = gset_get_weapondef(weaponnum);

	if (weapon) {
		struct ammodef *ammo = weapon->ammos[func];

		if (ammo) {
			return bgun_get_reserved_ammo_count(ammo->type);
		}
	}

	return 0;
}

void bgun_set_ammo_qty_for_weapon(u32 weaponnum, u32 func, u32 quantity)
{
	struct weapondef *weapon = gset_get_weapondef(weaponnum);

	if (weapon) {
		struct ammodef *ammo = weapon->ammos[func];

		if (ammo) {
			bgun_set_ammo_quantity(ammo->type, quantity);
		}
	}
}

s32 bgun_get_ammo_capacity_for_weapon(s32 weaponnum, s32 func)
{
	struct weapondef *weapon = gset_get_weapondef(weaponnum);
	struct ammodef *ammo = weapon->ammos[func];

	if (ammo) {
		return g_AmmoTypes[ammo->type].capacity;
	}

	return 0;
}

Gfx *bgun_draw_hud_string(Gfx *gdl, char *text, s32 x, bool halign, s32 y, s32 valign, u32 colour)
{
	s32 x1 = 0;
	s32 y1 = 0;
	s32 x2 = 0;
	s32 y2 = 0;
	s32 textheight;
	s32 textwidth;

	textwidth = 0;
	textheight = 0;

#if VERSION >= VERSION_JPN_FINAL
	text_measure(&textheight, &textwidth, text, g_CharsNumeric, g_FontNumeric, -1);
#else
	text_measure(&textheight, &textwidth, text, g_CharsNumeric, g_FontNumeric, 0);
#endif

	if (halign == HUDHALIGN_LEFT) { // left
		x2 = x + textwidth;
		x1 = x;
	} else if (halign == HUDHALIGN_RIGHT) { // right
		x1 = x - textwidth;
		x2 = x;
	} else if (halign == HUDHALIGN_MIDDLE) { // middle
		x2 = x + textwidth / 2;
		x1 = x2 - textwidth;
	}

	if (valign == HUDVALIGN_TOP) { // top
		y2 = y + textheight;
		y1 = y;
	} else if (valign == HUDVALIGN_BOTTOM) { // bottom
		y1 = y - textheight;
		y2 = y;
	} else if (valign == HUDVALIGN_MIDDLE) { // middle
		y2 = y + textheight / 2;
		y1 = y2 - textheight;
	}

	gdl = text_draw_black_box(gdl, &x1, &y1, &x2, &y2);
	gdl = text_render_v1(gdl, &x1, &y1, text, g_CharsNumeric, g_FontNumeric, colour, 0x000000a0, vi_get_width(), vi_get_height(), 0, 0);

	return gdl;
}

Gfx *bgun_draw_hud_integer(Gfx *gdl, s32 value, s32 x, bool halign, s32 y, s32 valign, u32 colour)
{
	char buffer[12];

	sprintf(buffer, "%d\n", value);
	gdl = bgun_draw_hud_string(gdl, buffer, x, halign, y, valign, colour);

	return gdl;
}

void bgun_reset_abmag(struct abmag *abmag)
{
	abmag->loadedammo = 0;
	abmag->change = 0;
	abmag->ref = 0;
	abmag->timer60 = 0;
}

void bgun0f0a9da8(struct abmag *mag, s32 remaining, s32 capacity, s32 height)
{
	s32 newchange;

	if (capacity > 20) {
		s32 newremaining = height * remaining / capacity;

		if (remaining > 0 && newremaining < 1) {
			newremaining = 1;
		}

		capacity = height;

		if (newremaining == mag->ref && mag->loadedammo > remaining) {
			mag->ref++;
		}

		mag->loadedammo = remaining;
		remaining = newremaining;
	}

	newchange = remaining - mag->ref;

	if ((mag->change < 0 && newchange > 0) || (mag->change > 0 && newchange < 0)) {
		mag->ref += mag->change;
		mag->change = 0;
		mag->timer60 = 0;

		newchange = remaining - mag->ref;
	}

	if (mag->change < 0 && mag->change > newchange) {
		if (mag->timer60 > -mag->change * TICKS(64)) {
			mag->timer60 = -mag->change * TICKS(64);
		}
	}

	mag->change = newchange;

	if (mag->change > 0) {
		height = capacity;

		if (capacity < 6) {
			height = 6;
		}
	} else {
		height = 8;

		if (mag->change < -3) {
			height += -mag->change * 2;
		}
	}

	if (mag->change != 0) {
		mag->timer60 += (s16)g_Vars.lvupdate60 * height;

		if (mag->timer60 > TICKS(255)) {
			if (mag->change > 0) {
				while (mag->timer60 > TICKS(255) && mag->change > 0) {
					mag->change--;
					mag->ref++;
					mag->timer60 -= TICKS(64);
				}
			} else {
				while (mag->timer60 > TICKS(255) && mag->change < 0) {
					mag->change++;
					mag->ref--;
					mag->timer60 -= TICKS(64);
				}
			}
		}
	} else {
		mag->timer60 = 0;
	}
}

/**
 * Render an ammo gauge on the HUD.
 *
 * Ammo gauges can be displayed in two ways. If the capacity is less than 20,
 * each bullet is displayed as a separate block with a gap between each. If the
 * capacity is 20 or more, a single block covers the whole gauge and the block
 * is partitioned into two (filled and empty).
 *
 * For the separated mode, a unit refers to a single bullet/block.
 * For the merged mode, a unit refers to a single 1px high line in the gauge.
 */
Gfx *bgun_draw_hud_gauge(Gfx *gdl, s32 x1, s32 y1, s32 x2, s32 y2, struct abmag *abmag, s32 remaining, s32 capacity, u32 emptycolour, u32 filledcolour, bool flip)
{
	s32 gaugeheight = y2 - y1;
	s32 unitheight;
	s32 remainder1;
	s32 remainder2;
	s32 gaugetop;
	f32 ref;
	s32 numunits = capacity;
	s32 i;

	bgun0f0a9da8(abmag, remaining, numunits, gaugeheight);

	if (numunits > 20) {
		// Use a single merged bar
		ref = abmag->ref;
		unitheight = 1;
		numunits = gaugeheight;
		gaugetop = y2 - gaugeheight;
	} else {
		// Use a separate block for each bullet
		ref = abmag->ref;
		unitheight = gaugeheight / numunits;
		remainder1 = unitheight * numunits - gaugeheight;
		remainder2 = (unitheight + 1) * numunits - gaugeheight;

		if (remainder1 < 0) {
			remainder1 = -remainder1;
		}

		if (remainder2 < 0) {
			remainder2 = -remainder2;
		}

		if (remainder2 < remainder1) {
			unitheight++;
		}

		gaugetop = y2 - unitheight * capacity + 1;

		if (unitheight <= 2) {
			gaugetop--;
		}
	}

	if (unitheight == 0) {
		/**
		 * Using separate blocks, but the clip capacity is more than the gauge
		 * height meaning each block is less than 1px. This is impossible
		 * because the gauge switches modes away from separate blocks at 20,
		 * therefore this code is unreachable.
		 *
		 * This code renders the gauge in the merged style, but uses 1px per
		 * bullet and truncates the gauge at the gaugetop if needed. This is
		 * clearly an early revision of the code, as it is visually misleading
		 * and also lacks the transition effect.
		 */
		s32 partitiony;
		s32 tmp;

		gaugeheight = y2 - gaugetop;
		partitiony = y2 - gaugeheight * ref / numunits;
		tmp = y2;

		if (partitiony > gaugetop) {
			// Render empty partition
			gdl = text_begin_boxmode(gdl, emptycolour);

			if (flip) {
				gDPFillRectangleScaled(gdl++, x1, y2 - partitiony + y1, x2, gaugeheight + y1);
			} else {
				gDPFillRectangleScaled(gdl++, x1, gaugetop, x2, partitiony);
			}

			gdl = text_end_boxmode(gdl);
		}

		// Render filled partition
		gdl = text_begin_boxmode(gdl, filledcolour);

		if (flip) {
			gDPFillRectangleScaled(gdl++, x1, y2 - tmp + y1, x2, y2 - partitiony + y1);
		} else {
			gDPFillRectangleScaled(gdl++, x1, partitiony, x2, y2);
		}
	} else {
		u32 colour;
		s32 unittop;
		s32 unitbottom;

		gdl = text_begin_boxmode(gdl, emptycolour);

		unittop = gaugetop;
		unitbottom = -1;

		for (i = 0; i < numunits; i++) {
			bool newstate = false;
			u32 weight;

			if (1);

			if (abmag->change > 0) {
				// Loading or reloading
				if (i >= numunits - (s32)ref - abmag->change && i < numunits - (s32)ref) {
					// Unit is potentially unsettled
					s32 fadeamount = abmag->timer60 - (numunits - (s32)ref - i - 1) * TICKS(64);

					if (fadeamount >= 0) {
						if (fadeamount >= TICKS(64)) {
							// Unit is transitioning to filled
#if PAL
							weight = (fadeamount * 4 - TICKS(250)) / 3;
#else
							weight = (fadeamount * 4 - TICKS(252)) / 3;
#endif
							weight = PALUP(weight);

							if (weight > 255) {
								weight = 255;
							}

							colour = colour_blend(filledcolour, 0xffffffbf, weight);
						} else {
							// Unit is bright and has not started transitioning to filled yet
							weight = fadeamount * 4;
							weight = PALUP(weight);

#if VERSION >= VERSION_PAL_BETA
							if (weight > 255) {
								weight = 255;
							}
#endif

							colour = colour_blend(0xffffffbf, emptycolour, weight);
						}

						newstate = true;
					}
				}
			} else if (abmag->change < 0) {
				// Firing
				if (i < numunits - (s32)ref - abmag->change && i >= numunits - (s32) ref) {
					s32 fadeamount = abmag->timer60 - (i - numunits + (s32) ref) * TICKS(64);

					if (fadeamount >= 0) {
						weight = PALUP(fadeamount);

						if (weight > 255) {
							colour = emptycolour;
						} else {
							// Unit was recently emptied
							colour = colour_blend(emptycolour, filledcolour | 0xff, weight);
						}

						newstate = true;
					}
				}
			}

			// Special case for units which are one after the last one being
			// faded. I think their colour is calculated incorrectly by the code
			// above and this is resetting them to the normal filled colour.
			if (abmag->change < 0) {
				// Firing
				if (i == numunits - (s32) ref - abmag->change) {
					colour = filledcolour;
					newstate = true;
				}
			} else {
				if (i == numunits - (s32) ref) {
					colour = filledcolour;
					newstate = true;
				}
			}

			// Calculate unittop and unitbottom. For merged gauges keep unittop
			// as it is if possible, so the empty and filled partitions can be
			// drawn whenever the state is changed in order to save gfx calls.
			if (unitheight <= 2) {
				if (newstate) {
					if (unitbottom >= 0) {
						// Render empty or transitioning unit of merged gauge
						if (flip) {
							gDPFillRectangleScaled(gdl++, x1, y2 - unitbottom + y1, x2, y2 - unittop + y1);
						} else {
							gDPFillRectangleScaled(gdl++, x1, unittop, x2, unitbottom);
						}
					}

					unittop = gaugetop + i * unitheight;
				}

				unitbottom = gaugetop + i * unitheight + unitheight;
			} else {
				// Separate blocks - reduce unitbottom by 1 to make a gap
				unittop = gaugetop + i * unitheight;
				unitbottom = gaugetop + i * unitheight + unitheight - 1;
			}

			if (newstate) {
				gDPSetPrimColorViaWord(gdl++, 0, 0, colour);
			}

			// For separate blocks, clip the unit bottom to the bottom of the gauge
			if (unitbottom >= y2 - 1 && unitheight >= 2) {
				unitbottom = y2;
			}

			// Render separated blocks
			if (unitheight >= 3) {
				if (flip) {
					gDPFillRectangleScaled(gdl++, x1, y2 - unitbottom + y1, x2, y2 - unittop + y1);
				} else {
					gDPFillRectangleScaled(gdl++, x1, unittop, x2, unitbottom);
				}
			}
		} // end loop

		// For merged gauges, render the final partition
		if (unitheight <= 2) {
			s32 stack;

			if (flip) {
				gDPFillRectangleScaled(gdl++, x1, y2 - unitbottom + y1, x2, y2 - unittop + y1);
			} else {
				gDPFillRectangleScaled(gdl++, x1, unittop, x2, unitbottom);
			}
		}
	}

	gdl = text_end_boxmode(gdl);

	gDPSetRenderMode(gdl++, G_RM_AA_XLU_SURF, G_RM_AA_XLU_SURF2);

	return gdl;
}

Gfx *bgun_draw_hud(Gfx *gdl)
{
	struct player *player = g_Vars.currentplayer;
	s32 bottom = vi_get_view_top() + vi_get_view_height() - 13;
	s32 playercount = PLAYERCOUNT();
	s32 playernum = g_Vars.currentplayernum;
	struct gunctrl *ctrl;
	s32 secs60;
	s32 speedpilltime;
	s32 ammoindex = 0;
	s32 barwidth = 9;
	s32 reserveheight = 36;
	s32 clipheight = 57;
	s32 xpos;
	struct weapondef *weapon = gset_get_weapondef(player->gunctrl.weaponnum);
	u32 alpha;
	u32 fncolour;
	s32 funcnum;
	s32 fnfaderinc;
#if VERSION >= VERSION_NTSC_1_0
	s32 tmpfuncnum;
	struct handweaponinfo info;
#endif
	struct hand *hand = &player->hands[HAND_RIGHT];
	char *str;
	u32 colour;
	s32 x;
	s32 y;
	s32 textheight;
	s32 textwidth;
	struct funcdef *func;
	u16 nameid;
	struct hand *lefthand = &player->hands[HAND_LEFT];

	ctrl = &player->gunctrl;

	if (player->isdead) {
		return gdl;
	}

	if (g_Vars.currentplayer->gunctrl.passivemode) {
		return gdl;
	}

	if (g_Vars.lvframenum < 5) {
		return gdl;
	}

#if PAL
	g_UiScaleX = 1;
#else
	g_UiScaleX = g_ViRes == VIRES_HI ? 2 : 1;
#endif

	gdl = text_begin(gdl);

	if (playercount >= 2) {
		barwidth = 5;
		reserveheight = 26;
		clipheight = 47;

		if (playercount == 2) {
			if (IS4MB() || (options_get_screen_split() != SCREENSPLIT_VERTICAL && playernum == 0)) {
				bottom += 10;
			} else {
				bottom += 2;
			}
		} else if (playercount >= 3) {
			if (playernum < 2) {
				bottom += 10;
			} else {
				bottom += 2;
			}
		}
	} else if (options_get_effective_screen_size() != SCREENSIZE_FULL) {
		bottom += 8;
	}

	fncolour = 0xff000040;
	funcnum = hand->gset.weaponfunc;
	fnfaderinc = PALUP(g_Vars.lvupdate240 * 2);

#if VERSION >= VERSION_NTSC_1_0
	bgun_get_weapon_info(&info, HAND_RIGHT);
	tmpfuncnum = bgun_is_using_secondary_function();

	if (bgun_get_ammo_state(tmpfuncnum, &info, hand) > GUNAMMOSTATE_DEPLETED) {
		funcnum = tmpfuncnum;
	}
#endif

	xpos = (vi_get_view_left() + vi_get_view_width()) / g_UiScaleX - barwidth - 24;

	if (playercount == 2 && (options_get_screen_split() == SCREENSPLIT_VERTICAL || IS4MB()) && playernum == 0) {
		xpos += 15;
	} else if (playercount >= 3 && (playernum % 2) == 0) {
		xpos += 15;
	}

	// Draw function square
	if (funcnum == FUNC_SECONDARY && ctrl->fnfader < 255) {
		if (ctrl->fnfader < 128) {
			ctrl->fnfader = 128;
		}

		if (ctrl->fnfader + fnfaderinc > 255) {
			ctrl->fnfader = 255;
		} else {
			ctrl->fnfader += fnfaderinc;
		}
	}

	if (funcnum == FUNC_PRIMARY && ctrl->fnfader > 0) {
		if (ctrl->fnfader - fnfaderinc < 0) {
			ctrl->fnfader = 0;
		} else {
			ctrl->fnfader -= fnfaderinc;
		}
	}

	if (ctrl->fnfader > 128) {
		fncolour = ((ctrl->fnfader * 2) - 256) << 16 | 0xff000040;
	}

	gdl = text_begin_boxmode(gdl, fncolour);

	gDPFillRectangleScaled(gdl++, xpos - 13, bottom - 11, xpos - 2, bottom);

	gdl = text_end_boxmode(gdl);

	// Draw weapon name and function name
	if (options_get_show_gun_function(g_Vars.currentplayerstats->mpindex)) {
#if VERSION >= VERSION_NTSC_1_0
		func = gset_get_funcdef_by_weaponnum_funcnum(hand->gset.weaponnum, funcnum);
#else
		func = gset_get_funcdef_by_weaponnum_funcnum(hand->gset.weaponnum, hand->gset.weaponfunc);
#endif
		nameid = inv_get_name_id_by_index(inv_get_current_index());
		str = lang_get(nameid);

		if (ctrl->curgunstr != nameid) {
			ctrl->guntypetimer = 0;
			ctrl->curgunstr = nameid;
		}

		if (ctrl->guntypetimer < 255) {
			colour = 0x55ffffff;

			if (ctrl->guntypetimer);

			if (ctrl->guntypetimer + g_Vars.lvupdate60 > 255) {
				ctrl->guntypetimer = 255;
			} else {
				ctrl->guntypetimer += (u16) g_Vars.lvupdate60;
			}

			text_measure(&textheight, &textwidth, str, g_CharsHandelGothicXs, g_FontHandelGothicXs, 0);
			textwidth += 2;

			if (textwidth > ctrl->guntypetimer * 3) {
				textwidth = ctrl->guntypetimer * 3;
			}

			if (playercount >= 2) {
				x = xpos - textwidth - 13;
			} else {
				x = xpos - textwidth - 2;
			}

#if VERSION == VERSION_JPN_FINAL
			y = bottom - textheight - 10;
#else
			y = bottom - textheight - 15;
#endif

			if (ctrl->guntypetimer > 192) {
				alpha = 255 - (ctrl->guntypetimer - 192) * 255 / 63U;
				colour = (colour & 0xffffff00) | alpha;
				if (0xffffff00);
			}

			gdl = text_begin_boxmode(gdl, 0);

			gDPFillRectangleScaled(gdl++, x - 1, y - 1, xpos - 11, bottom);

			gdl = text_end_boxmode(gdl);
			text_set_wave_blend(g_20SecIntervalFrac * 50.0f, 0, 50);
			text_set_wave_colours(0xffffffff, 0xffffffff);
			gdl = text_render_v2(gdl, &x, &y, str, g_CharsHandelGothicXs, g_FontHandelGothicXs, colour, textwidth, 1000, 0, 0);
			text_reset_blends();
		}

		if (func) {
			lang_get(func->name);

			colour = 0xff5555ff;

			if ((ctrl->curfnstr != func->name && ctrl->fnfader > 128) || ctrl->curfnstr == 0) {
				ctrl->fnstrtimer = 0;
				ctrl->curfnstr = func->name;
			}

			str = lang_get(ctrl->curfnstr);

			if (ctrl->fnstrtimer < 255) {
				if (ctrl->fnstrtimer + g_Vars.lvupdate60 > 255) {
					ctrl->fnstrtimer = 255;
				} else {
					ctrl->fnstrtimer += (u16) g_Vars.lvupdate60;
				}

#if VERSION >= VERSION_NTSC_1_0
				if (funcnum == FUNC_SECONDARY && func->name == ctrl->curfnstr) {
					colour |= 0x00ff0000;
				}

				if (funcnum == FUNC_PRIMARY && func->name != ctrl->curfnstr) {
					colour |= 0x00ff0000;
				}
#else
				if (hand->gset.weaponfunc == FUNC_SECONDARY && func->name == ctrl->curfnstr) {
					colour |= 0x00ff0000;
				}

				if (hand->gset.weaponfunc == FUNC_PRIMARY && func->name != ctrl->curfnstr) {
					colour |= 0x00ff0000;
				}
#endif

				text_measure(&textheight, &textwidth, str, g_CharsHandelGothicXs, g_FontHandelGothicXs, 0);
				textwidth += 2;

				if (textwidth > ctrl->fnstrtimer * 3) {
					textwidth = ctrl->fnstrtimer * 3;
				}

				x = xpos - textwidth - 13;
#if VERSION == VERSION_JPN_FINAL
				y = bottom - textheight + 3;
#else
				y = bottom - textheight - 1;
#endif

				if (ctrl->fnstrtimer > 192) {
					alpha = 255 - (ctrl->fnstrtimer - 192) * 255 / 63U;
					colour = (colour & 0xffffff00) | alpha;
				}

				gdl = text_begin_boxmode(gdl, 0);

				gDPFillRectangleScaled(gdl++, x - 1, y - 1, xpos - 11, bottom + 3);

				gdl = text_end_boxmode(gdl);

				text_set_wave_blend(g_20SecIntervalFrac * 50.0f, 0, 50);
				text_set_wave_colours(0xffffffff, 0xffffffff);

				gdl = text_render_v2(gdl, &x, &y, str,
						g_CharsHandelGothicXs, g_FontHandelGothicXs, colour, textwidth,
						1000, 0, 0);

				text_reset_blends();
			}
		}
	}

	if (weapon && weapon->functions[hand->gset.weaponfunc] != NULL) {
		ammoindex = ((struct funcdef *)(weapon->functions[hand->gset.weaponfunc]))->ammoindex;
	}

	if (ammoindex == -1) {
		if (weapon->functions[1 - hand->gset.weaponfunc] != NULL) {
			ammoindex = ((struct funcdef *)(weapon->functions[1 - hand->gset.weaponfunc]))->ammoindex;
		}

		if (ammoindex == -1) {
			gdl = text_end(gdl);
			g_UiScaleX = 1;
			return gdl;
		}
	}

	if (ammoindex != ctrl->lastmag) {
		bgun_reset_abmag(&player->hands[HAND_LEFT].abmag);
		bgun_reset_abmag(&hand->abmag);
		bgun_reset_abmag(&ctrl->abmag);
		ctrl->lastmag = ammoindex;
	}

	// Left hand - mag
	if (lefthand->inuse
			&& weapon->ammos[ammoindex] != NULL
			&& lefthand->gset.weaponnum != WEAPON_REMOTEMINE) {
		xpos = vi_get_view_left() / g_UiScaleX + 24;

		if (playercount == 2 && (options_get_screen_split() == SCREENSPLIT_VERTICAL || IS4MB()) && playernum == 1) {
			xpos -= 14;
		} else if (playercount >= 3 && (playernum & 1) == 1) {
			xpos -= 14;
		}

		if (lefthand->clipsizes[ammoindex] > 0 && (weapon->ammos[ammoindex]->flags & AMMOFLAG_EQUIPPEDISRESERVE) == 0) {
			gdl = bgun_draw_hud_gauge(gdl,
					xpos, bottom - reserveheight - clipheight - 3, xpos + barwidth, bottom - reserveheight - 3,
					&lefthand->abmag, lefthand->loadedammo[ammoindex], lefthand->clipsizes[ammoindex],
					0x00300080, 0x00ff0040, false);
			gdl = bgun_draw_hud_integer(gdl, lefthand->loadedammo[ammoindex], xpos + barwidth + 2, true,
					bottom - reserveheight - 8, 0, 0x00ff00a0);
		}
	}

	// Right hand - mag, reserve and combat boost timer
	if (hand->inuse && ctrl->ammotypes[ammoindex] >= 0) {
		s32 ammotype;
		s32 ammoheld;
		s32 ammototal;

		ammotype = player->gunctrl.ammotypes[ammoindex];

#if VERSION >= VERSION_NTSC_1_0
		xpos = (vi_get_view_left() + vi_get_view_width()) / g_UiScaleX - barwidth - 24;
#else
		// NTSC Beta omits the brackets here. This would normally cause the
		// ammo info to be misaligned for players on the right side of the
		// screen and when using hi-res, but I'm not sure if hi-res can even be
		// active when using multiple players...
		xpos = vi_get_view_left() + vi_get_view_width() / g_UiScaleX - barwidth - 24;
#endif

		if (playercount == 2 && (options_get_screen_split() == SCREENSPLIT_VERTICAL || IS4MB()) && playernum == 0) {
			xpos += 15;
		} else if (playercount >= 3 && (playernum % 2) == 0) {
			xpos += 15;
		}

		// Mag
		ammoheld = player->ammoheldarr[ammotype];

		if (hand->clipsizes[ammoindex] > 0
				&& weapon->ammos[ammoindex] != NULL
				&& (weapon->ammos[ammoindex]->flags & AMMOFLAG_EQUIPPEDISRESERVE) == 0) {
			gdl = bgun_draw_hud_gauge(gdl, xpos, bottom - reserveheight - clipheight - 3, xpos + barwidth,
					bottom - reserveheight - 3, &hand->abmag, hand->loadedammo[ammoindex], hand->clipsizes[ammoindex],
					0x00300080, 0x00ff0040, false);
			gdl = bgun_draw_hud_integer(gdl, hand->loadedammo[ammoindex], xpos - 2, false,
					bottom - reserveheight - 8, 0, 0x00ff00a0);
		}

		// Reserve
		if (g_AmmoTypes[ammotype].capacity > 0
				&& (weapon->ammos[ammoindex]->flags & AMMOFLAG_NORESERVE) == 0) {
			ammototal = ammoheld;

			if (weapon->ammos[ammoindex]->flags & AMMOFLAG_EQUIPPEDISRESERVE) {
				if (hand->clipsizes[ammoindex] > 0) {
					ammototal += hand->loadedammo[ammoindex];
				}

				if (lefthand->clipsizes[ammoindex] > 0) {
					ammototal += lefthand->loadedammo[ammoindex];
				}
			}

			gdl = bgun_draw_hud_gauge(gdl, xpos, bottom - reserveheight, xpos + barwidth,
					bottom, &ctrl->abmag, ammototal, g_AmmoTypes[ammotype].capacity,
					0x00403080, 0x00ffc040, true);
			gdl = bgun_draw_hud_integer(gdl, ammototal, xpos - 2, false, bottom - reserveheight + 1, 0, 0x00ffc0a0);
		}

		// Combat boost timer
		if (hand->gset.weaponnum == WEAPON_COMBATBOOST) {
			s32 mins;
			char text[32];

			speedpilltime = g_Vars.speedpilltime;
			mins = speedpilltime / TICKS(3600);
			secs60 = speedpilltime - mins * TICKS(3600);

			if (mins >= 1) {
				sprintf(text, "%02d:%02d:%02d\n", mins, secs60 / TICKS(60), (secs60 - (secs60 / TICKS(60)) * TICKS(60)) * 100 / TICKS(60));
			} else {
				sprintf(text, "%02d:%02d\n", secs60 / TICKS(60), (secs60 - (secs60 / TICKS(60)) * TICKS(60)) * 100 / TICKS(60));
			}

			gdl = bgun_draw_hud_string(gdl, text, xpos + barwidth - 2, false, bottom - reserveheight + 1, 0, 0x00ffc0a0);
		}
	}

	gdl = text_end(gdl);

	g_UiScaleX = 1;

	return gdl;
}

void bgun_add_boost(s32 amount)
{
	g_Vars.speedpilltime += amount;

	if (g_Vars.speedpilltime > 5 * 60 * TICKS(60)) { // 5 minutes
		g_Vars.speedpilltime = 5 * 60 * TICKS(60);
	}

	if (!g_Vars.speedpillwant) {
		u32 sound = lv_get_slow_motion_type() ? SFX_ARGH_JO_02AD : SFX_JO_BOOST_ACTIVATE;

		snd_start(var80095200, sound, 0, -1, -1, -1, -1, -1);
	}

	g_Vars.speedpillwant = true;
}

void bgun_subtract_boost(s32 amount)
{
	g_Vars.speedpilltime -= amount;

	if (g_Vars.speedpilltime <= 0) {
		g_Vars.speedpilltime = 0;
		g_Vars.speedpillwant = false;
	}
}

void bgun_apply_boost(void)
{
	if (lv_get_slow_motion_type() != SLOWMOTION_OFF) {
		bgun_subtract_boost(TICKS(1200));
	} else {
		bgun_add_boost(TICKS(600));
	}
}

void bgun_revert_boost(void)
{
	if (lv_get_slow_motion_type() != SLOWMOTION_OFF) {
		bgun_add_boost(TICKS(1200));
	} else {
		bgun_subtract_boost(TICKS(600));
	}
}

/**
 * The main tick function as called from lv_tick.
 *
 * This function doesn't do much because it's called during both cutscenes and
 * gameplay, while most gun tick operations happen during gameplay only.
 * See bgun_tick_gameplay for that.
 */
void bgun_tick_boost(void)
{
	if (g_Vars.speedpillon && g_Vars.speedpilltime > 0 && !g_Vars.in_cutscene) {
		g_Vars.speedpilltime -= g_Vars.lvupdate60;

		if (g_Vars.speedpilltime <= 0) {
			g_Vars.speedpilltime = 0;
			g_Vars.speedpillwant = false;
		}
	}
}

/**
 * gunsightoff is 0 if the full sight is visible, ie. player is holding R.
 *
 * Otherwise, gunsightoff holds bit values for reasons why the sight is off.
 * This is typically 2, which is GUNSIGHTREASON_NOTAIMING.
 *
 * If the visible argument is true, it removes the reason from the field, thus
 * making the sight visible if there are no other reasons.
 */
void bgun_set_sight_visible(u32 reason, bool visible)
{
	if (visible) {
		g_Vars.currentplayer->gunsightoff &= ~reason;
		return;
	}

	g_Vars.currentplayer->gunsightoff |= reason;
}

Gfx *bgun_draw_sight(Gfx *gdl)
{
	if (g_Vars.currentplayer->gunsightoff == 0 && !g_Vars.currentplayer->mpmenuon) {
		// Player is aiming with R
		gdl = sight_draw(gdl, true, gset_get_sight());
	} else {
		gdl = sight_draw(gdl, false, gset_get_sight());
	}

	return gdl;
}

void bgun0f0abd30(s32 handnum)
{
	struct player *player = g_Vars.currentplayer;
	struct hand *hand = &player->hands[handnum];
	struct gunctrl *gunctrl = &player->gunctrl;
	struct weapondef *weapon = gset_get_weapondef(hand->gset.weaponnum);
	s32 i;

	for (i = 0; i < 2; i++) {
		if (handnum == HAND_RIGHT) {
			gunctrl->ammotypes[i] = -1;
		}

		if (weapon && weapon->ammos[i]) {
			if (handnum == HAND_RIGHT) {
				gunctrl->ammotypes[i] = weapon->ammos[i]->type;
			}

			hand->clipsizes[i] = weapon->ammos[i]->clipsize;

			if (handnum == HAND_LEFT && hand->gset.weaponnum == WEAPON_REMOTEMINE) {
				hand->clipsizes[i] = 0;
			}

			hand->loadedammo[i] = 0;
		}
	}

	hand->upgrademult[0] = 1;
	hand->upgrademult[1] = 1;
	hand->finalmult[0] = 1;
	hand->finalmult[1] = 1;

	if (gunctrl->ammotypes[0] >= 0) {
		bgun_reset_abmag(&hand->abmag);

		if (handnum == HAND_RIGHT) {
			bgun_reset_abmag(&gunctrl->abmag);
		}

		gunctrl->lastmag = false;
	}
}
