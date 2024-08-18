#include <ultra64.h>
#include "constants.h"
#include "constants.h"
#include "game/bondmove.h"
#include "game/cheats.h"
#include "game/inv.h"
#include "game/playerreset.h"
#include "game/chr.h"
#include "game/body.h"
#include "game/prop.h"
#include "game/setuputils.h"
#include "game/bondgun.h"
#include "game/player.h"
#include "game/inv.h"
#include "game/stagetable.h"
#include "game/mplayer/scenarios.h"
#include "game/mplayer/mplayer.h"
#include "game/pad.h"
#include "bss.h"
#include "lib/collision.h"
#include "lib/memp.h"
#include "lib/mtx.h"
#include "lib/anim.h"
#include "data.h"
#include "types.h"

void player_init_eyespy(void)
{
	struct prop *prop;
	struct pad pad;
	struct chrdata *propchr;
	struct chrdata *playerchr;
	static u8 nextpad = 0;

	if (g_Vars.currentplayer->eyespy == NULL) {
		/**
		 * To create the eyespy's prop, a pad must be passed to body_instantiate_eyespy.
		 * However the eyespy doesn't have a pad because it's held by the
		 * player, so it needs to choose one from the stage. The method used
		 * will increment the chosen pad number each time the stage is loaded
		 * and wrap at 256.
		 *
		 * @bug: This method means if you play G5 Building enough times then
		 * the camspy will start in a trigger point for the mid cutscene,
		 * causing the mid cutscene to play instead of the intro.
		 */
		pad_unpack(nextpad++, PADFIELD_ROOM | PADFIELD_POS, &pad);
		prop = body_instantiate_eyespy(&pad, pad.room);

		if (prop) {
			g_Vars.currentplayer->eyespy = memp_alloc(sizeof(struct eyespy), MEMPOOL_STAGE);

			if (g_Vars.currentplayer->eyespy) {
				g_Vars.currentplayer->eyespy->prop = prop;
				g_Vars.currentplayer->eyespy->look.x = 0;
				g_Vars.currentplayer->eyespy->look.y = 0;
				g_Vars.currentplayer->eyespy->look.z = 1;
				g_Vars.currentplayer->eyespy->up.x = 0;
				g_Vars.currentplayer->eyespy->up.y = 1;
				g_Vars.currentplayer->eyespy->up.z = 0;
				g_Vars.currentplayer->eyespy->theta = 0;
				g_Vars.currentplayer->eyespy->costheta = 1;
				g_Vars.currentplayer->eyespy->sintheta = 0;
				g_Vars.currentplayer->eyespy->verta = 0;
				g_Vars.currentplayer->eyespy->cosverta = 1;
				g_Vars.currentplayer->eyespy->sinverta = 0;
				g_Vars.currentplayer->eyespy->held = true;
				g_Vars.currentplayer->eyespy->deployed = false;
				g_Vars.currentplayer->eyespy->active = false;
				g_Vars.currentplayer->eyespy->buttonheld = false;
				g_Vars.currentplayer->eyespy->camerabuttonheld = false;
				g_Vars.currentplayer->eyespy->bobdir = 1;
				g_Vars.currentplayer->eyespy->bobtimer = 0;
				g_Vars.currentplayer->eyespy->bobactive = true;
				g_Vars.currentplayer->eyespy->vel.x = 0;
				g_Vars.currentplayer->eyespy->vel.y = 0;
				g_Vars.currentplayer->eyespy->vel.z = 0;
				g_Vars.currentplayer->eyespy->speed = 0;
				g_Vars.currentplayer->eyespy->oldground = 0;
				g_Vars.currentplayer->eyespy->height = 0;
				g_Vars.currentplayer->eyespy->gravity = 0;
				g_Vars.currentplayer->eyespy->hit = EYESPYHIT_NONE;
				g_Vars.currentplayer->eyespy->opendoor = false;
				g_Vars.currentplayer->eyespy->mode = EYESPYMODE_CAMSPY;
				propchr = prop->chr;
				playerchr = g_Vars.currentplayer->prop->chr;
				propchr->team = playerchr->team;

				if (stage_get_index(g_Vars.stagenum) == STAGEINDEX_AIRBASE) {
					g_Vars.currentplayer->eyespy->mode = EYESPYMODE_DRUGSPY;
					g_Weapons[WEAPON_EYESPY]->name = L_GUN_061; // "DrugSpy"
					g_Weapons[WEAPON_EYESPY]->shortname = L_GUN_061; // "DrugSpy"
				} else if (stage_get_index(g_Vars.stagenum) == STAGEINDEX_MBR || stage_get_index(g_Vars.stagenum) == STAGEINDEX_CHICAGO) {
					g_Vars.currentplayer->eyespy->mode = EYESPYMODE_BOMBSPY;
				} else {
					g_Vars.currentplayer->eyespy->mode = EYESPYMODE_CAMSPY;
				}
			}
		}
	}
}

struct cmd32 {
	s32 type;
	s32 param1;
	s32 param2;
	s32 param3;
};

void player_reset(void)
{
	struct coord pos = {0, 0, 0};
	RoomNum rooms[8];
	f32 turnanglerad = 0;
	f32 groundy;
	bool hasdefaultweapon = false;
	struct cmd32 *cmd = (struct cmd32 *)g_StageSetup.intro;
	u8 haseyespy = false;
	s32 stack[7];
	s32 i;
	s32 numchrs;
	struct gecreditsdata *thing;
	struct chrdata *chr;
	s32 bodynum;
	s32 headnum;

	player_reset_lo_res_if_4mb();
	func0f18e558();

	g_InCutscene = false;

#if PAL
	var8009e388pf = 0;
#else
	g_CutsceneFrameOverrun240 = 0;
#endif

	var8007072c = 1;
	var80070738 = 0;
	var8007073c = 0;

	g_CurrentGeCreditsData = NULL;
	g_Vars.currentplayer->bondexploding = false;
	g_NumSpawnPoints = 0;
	g_Vars.currentplayer->bondtankexplode = false;
	g_Vars.currentplayer->gunmem2 = NULL;
	g_PlayersWithControl[0] = true;
	g_PlayersWithControl[1] = true;
	g_PlayersWithControl[2] = true;
	g_PlayersWithControl[3] = true;
	g_PlayerInvincible = false;

	player_set_tick_mode(TICKMODE_GE_FADEIN);

	g_PlayerTriggerGeFadeIn = 0;
	var80070748 = 0;
	var8007074c = 0;

	g_Vars.currentplayer->bondviewlevtime60 = 0;
	g_Vars.currentplayer->bondwatchtime60 = 0;
	g_Vars.currentplayer->introanimnum = 0;

	g_DefaultWeapons[HAND_LEFT] = 0;
	g_DefaultWeapons[HAND_RIGHT] = 0;

	if (cmd) {
		while (cmd->type != INTROCMD_END) {
			switch (cmd->type) {
			case INTROCMD_SPAWN:
				if (cmd->param2 == 0) {
					g_SpawnPoints[g_NumSpawnPoints++] = cmd->param1;
				}
				cmd = (struct cmd32 *)((uintptr_t)cmd + 12);
				break;
			case INTROCMD_CASE:
			case INTROCMD_CASERESPAWN:
				cmd = (struct cmd32 *)((uintptr_t)cmd + 12);
				break;
			case INTROCMD_HILL:
				cmd = (struct cmd32 *)((uintptr_t)cmd + 8);
				break;
			case INTROCMD_WEAPON:
				if (cmd->param3 == 0 && g_Vars.currentplayer != g_Vars.anti) {
					modelmgr_load_projectile_modeldefs(cmd->param1);

					if (cmd->param2 >= 0) {
						modelmgr_load_projectile_modeldefs(cmd->param2);
						inv_give_double_weapon(cmd->param1, cmd->param2);
					} else {
						inv_give_single_weapon(cmd->param1);
					}

					if (!hasdefaultweapon) {
						g_DefaultWeapons[HAND_RIGHT] = cmd->param1;

						if (cmd->param2 >= 0) {
							g_DefaultWeapons[HAND_LEFT] = cmd->param2;
						}

						hasdefaultweapon = true;
					}

					if (cmd->param1 == WEAPON_EYESPY) {
						haseyespy = true;
					}
				}
				cmd = (struct cmd32 *)((uintptr_t)cmd + 16);
				break;
			case INTROCMD_AMMO:
				if (cmd->param3 == 0 && g_Vars.currentplayer != g_Vars.anti) {
					bgun_set_ammo_quantity(cmd->param1, cmd->param2);
				}
				cmd = (struct cmd32 *)((uintptr_t)cmd + 16);
				break;
			case INTROCMD_3:
				cmd = (struct cmd32 *)((uintptr_t)cmd + 32);
				break;
			case INTROCMD_4:
				cmd = (struct cmd32 *)((uintptr_t)cmd + 8);
				break;
			case INTROCMD_OUTFIT:
				g_Vars.currentplayer->bondtype = cmd->param1;
				cmd = (struct cmd32 *)((uintptr_t)cmd + 8);
				break;
			case INTROCMD_6:
				cmd = (struct cmd32 *)((uintptr_t)cmd + 40);
				break;
			case INTROCMD_WATCHTIME:
				g_Vars.currentplayer->bondwatchtime60 = 0;
				if (cmd->param2 > 0) {
					g_Vars.currentplayer->bondwatchtime60 += (cmd->param2 % 60) * 3600;
				}
				if (cmd->param1 > 0) {
					g_Vars.currentplayer->bondwatchtime60 += (cmd->param1 % 12) * 3600 * 60;
				}
				cmd = (struct cmd32 *)((uintptr_t)cmd + 12);
				break;
			case INTROCMD_CREDITOFFSET:
				thing = (struct gecreditsdata *)((s32)g_GeCreditsData + cmd->param1);
				g_CurrentGeCreditsData = thing;
				while (thing->text1 || thing->text2) {
					thing++;
				}
				cmd = (struct cmd32 *)((uintptr_t)cmd + 8);
				break;
			default:
				cmd = (struct cmd32 *)((uintptr_t)cmd + 4);
			}
		}
	}

	inv_give_single_weapon(WEAPON_UNARMED);

	if (cheat_is_active(CHEAT_TRENTSMAGNUM)) {
		inv_give_single_weapon(WEAPON_DY357LX);
		bgun_set_ammo_quantity(AMMOTYPE_MAGNUM, 80);
	}

	if (cheat_is_active(CHEAT_FARSIGHT)) {
		inv_give_single_weapon(WEAPON_FARSIGHT);
		bgun_set_ammo_quantity(AMMOTYPE_FARSIGHT, 80);
	}

	if (cheat_is_active(CHEAT_CLOAKINGDEVICE)) {
		inv_give_single_weapon(WEAPON_CLOAKINGDEVICE);
#if VERSION >= VERSION_PAL_FINAL
		bgun_set_ammo_quantity(AMMOTYPE_CLOAK, TICKS(7200));
#else
		bgun_set_ammo_quantity(AMMOTYPE_CLOAK, 7200);
#endif
	}

	if (cheat_is_active(CHEAT_PERFECTDARKNESS)) {
		inv_give_single_weapon(WEAPON_NIGHTVISION);
	}

	if (cheat_is_active(CHEAT_RTRACKER)) {
		inv_give_single_weapon(WEAPON_RTRACKER);
	}

	if (cheat_is_active(CHEAT_ROCKETLAUNCHER)) {
		inv_give_single_weapon(WEAPON_ROCKETLAUNCHER);
		bgun_set_ammo_quantity(AMMOTYPE_ROCKET, 10);
	}

	if (cheat_is_active(CHEAT_SNIPERRIFLE)) {
		inv_give_single_weapon(WEAPON_SNIPERRIFLE);
		bgun_set_ammo_quantity(AMMOTYPE_RIFLE, 200);
	}

	if (cheat_is_active(CHEAT_XRAYSCANNER)) {
		inv_give_single_weapon(WEAPON_XRAYSCANNER);
	}

	if (cheat_is_active(CHEAT_SUPERDRAGON)) {
		inv_give_single_weapon(WEAPON_SUPERDRAGON);
		bgun_set_ammo_quantity(AMMOTYPE_RIFLE, 200);
		bgun_set_ammo_quantity(AMMOTYPE_DEVASTATOR, 20);
	}

	if (cheat_is_active(CHEAT_LAPTOPGUN)) {
		inv_give_single_weapon(WEAPON_LAPTOPGUN);
		bgun_set_ammo_quantity(AMMOTYPE_SMG, 200);
	}

	if (cheat_is_active(CHEAT_PHOENIX)) {
		inv_give_single_weapon(WEAPON_PHOENIX);
		bgun_set_ammo_quantity(AMMOTYPE_PISTOL, 200);
	}

#if VERSION >= VERSION_NTSC_1_0
	if (cheat_is_active(CHEAT_PSYCHOSISGUN) || cheat_is_active(CHEAT_ALLGUNS)) {
		bgun_set_ammo_quantity(AMMOTYPE_PSYCHOSIS, 4);

		if (cheat_is_active(CHEAT_PSYCHOSISGUN)) {
			inv_give_single_weapon(WEAPON_PSYCHOSISGUN);
		}
	}
#else
	if (cheat_is_active(CHEAT_PSYCHOSISGUN)) {
		inv_give_single_weapon(WEAPON_PSYCHOSISGUN);
		bgun_set_ammo_quantity(AMMOTYPE_PSYCHOSIS, 4);
	}
#endif

	if (cheat_is_active(CHEAT_PP9I)) {
		inv_give_single_weapon(WEAPON_PP9I);
		bgun_set_ammo_quantity(AMMOTYPE_PISTOL, 200);
	}

	if (cheat_is_active(CHEAT_CC13)) {
		inv_give_single_weapon(WEAPON_CC13);
		bgun_set_ammo_quantity(AMMOTYPE_RIFLE, 200);
	}

	if (cheat_is_active(CHEAT_KL01313)) {
		inv_give_single_weapon(WEAPON_KL01313);
		bgun_set_ammo_quantity(AMMOTYPE_SMG, 200);
	}

	if (cheat_is_active(CHEAT_KF7SPECIAL)) {
		inv_give_single_weapon(WEAPON_KF7SPECIAL);
		bgun_set_ammo_quantity(AMMOTYPE_RIFLE, 200);
	}

	if (cheat_is_active(CHEAT_ZZT)) {
		inv_give_single_weapon(WEAPON_ZZT);
		bgun_set_ammo_quantity(AMMOTYPE_SMG, 200);
	}

	if (cheat_is_active(CHEAT_DMC)) {
		inv_give_single_weapon(WEAPON_DMC);
		bgun_set_ammo_quantity(AMMOTYPE_SMG, 200);
	}

	if (cheat_is_active(CHEAT_AR53)) {
		inv_give_single_weapon(WEAPON_AR53);
		bgun_set_ammo_quantity(AMMOTYPE_RIFLE, 200);
	}

	if (cheat_is_active(CHEAT_RCP45)) {
		inv_give_single_weapon(WEAPON_RCP45);
		bgun_set_ammo_quantity(AMMOTYPE_SMG, 200);
	}

	if (!hasdefaultweapon) {
		g_DefaultWeapons[HAND_RIGHT] = WEAPON_UNARMED;
	}

	g_Vars.currentplayer->prop = prop_allocate();
	g_Vars.currentplayer->prop->chr = NULL;
	g_Vars.currentplayer->prop->type = PROPTYPE_PLAYER;

	prop_activate(g_Vars.currentplayer->prop);
	prop_enable(g_Vars.currentplayer->prop);
	chr_allocate(g_Vars.currentplayer->prop, NULL);

	if (g_Vars.coopplayernum >= 0) {
		g_Vars.currentplayer->prop->chr->team = TEAM_ALLY;
	} else if (g_Vars.antiplayernum >= 0) {
		if (g_Vars.currentplayer == g_Vars.bond) {
			g_Vars.currentplayer->prop->chr->team = TEAM_ALLY;
		} else {
			g_Vars.currentplayer->prop->chr->team = TEAM_ENEMY;
		}
	} else {
		if (g_Vars.mplayerisrunning) {
			g_Vars.currentplayer->prop->chr->team = 1 << g_PlayerConfigsArray[g_Vars.currentplayerstats->mpindex].base.team;
		} else {
			g_Vars.currentplayer->prop->chr->team = TEAM_ALLY;
		}
	}

	if (haseyespy) {
		player_init_eyespy();
	}

	if (g_NumSpawnPoints > 0) {
		if (g_Vars.coopplayernum >= 0) {
			turnanglerad = M_BADTAU - scenario_choose_spawn_location(30, &pos, rooms, g_Vars.currentplayer->prop);
		} else if (g_Vars.antiplayernum >= 0) {
			turnanglerad = M_BADTAU - scenario_choose_spawn_location(30, &pos, rooms, g_Vars.currentplayer->prop);
		} else {
			if (g_Vars.mplayerisrunning == 0) {
				g_NumSpawnPoints = 1;
			}

			turnanglerad = M_BADTAU - scenario_choose_spawn_location(30, &pos, rooms, g_Vars.currentplayer->prop);
		}
	}

	groundy = cd_find_ground_info_at_cyl(&pos, 30, rooms,
			&g_Vars.currentplayer->floorcol,
			&g_Vars.currentplayer->floortype,
			&g_Vars.currentplayer->floorflags,
			&g_Vars.currentplayer->floorroom,
			0, 0);

	pos.y = g_Vars.currentplayer->vv_eyeheight + groundy;
	g_Vars.currentplayer->vv_manground = groundy;
	g_Vars.currentplayer->vv_ground = groundy;
	g_Vars.currentplayer->vv_theta = (turnanglerad * 360.0f) / M_BADTAU;

	player_reset_bond(&g_Vars.currentplayer->bond2, &pos);

	g_Vars.currentplayer->bond2.unk00.x = -sinf(turnanglerad);
	g_Vars.currentplayer->bond2.unk00.y = 0;
	g_Vars.currentplayer->bond2.unk00.z = cosf(turnanglerad);

	g_Vars.currentplayer->prop->pos.f[0] = g_Vars.currentplayer->bondprevpos.f[0] = pos.f[0];
	g_Vars.currentplayer->prop->pos.f[1] = g_Vars.currentplayer->bondprevpos.f[1] = pos.f[1];
	g_Vars.currentplayer->prop->pos.f[2] = g_Vars.currentplayer->bondprevpos.f[2] = pos.f[2];

	prop_deregister_rooms(g_Vars.currentplayer->prop);

	g_Vars.currentplayer->prop->rooms[0] = rooms[0];
	g_Vars.currentplayer->prop->rooms[1] = -1;

	player_set_cam_properties_in_bounds(&pos,
			&g_Vars.currentplayer->bond2.unk28,
			&g_Vars.currentplayer->bond2.unk1c, rooms[0]);

	numchrs = chrs_get_num_slots();

	for (i = 0; i < numchrs; i++) {
		chr = &g_ChrSlots[i];

		if (chr->target == -2) {
			chr->target = g_Vars.currentplayer->prop - g_Vars.props;
		}
	}

	bmove_update_rooms(g_Vars.currentplayer);

	if (g_Vars.normmplayerisrunning) {
		players_begin_mp_swirl();
	} else {
		player0f0b9a20();
	}

	g_NumDeathAnimations = 0;

	while (g_DeathAnimations[g_NumDeathAnimations] > 0) {
		g_NumDeathAnimations++;
	}

	g_Vars.currentplayer->tickdiefinished = false;
	g_Vars.currentplayer->chokehandle = NULL;

	for (i = 0; i < ARRAYCOUNT(g_Vars.aibuddies); i++) {
		g_Vars.aibuddies[i] = NULL;
	}

	player_choose_body_and_head(&bodynum, &headnum, 0);
	g_Vars.currentplayer->prop->chr->bodynum = bodynum;
	g_Vars.currentplayer->prop->chr->headnum = headnum;
}
