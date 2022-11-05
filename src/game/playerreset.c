#include <ultra64.h>
#include "constants.h"
#include "constants.h"
#include "game/bondmove.h"
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

struct cmd32 {
	s32 type;
	s32 param1;
	s32 param2;
	s32 param3;
};

void playerReset(void)
{
	struct coord pos = {0, 0, 0};
	s16 rooms[8];
	f32 turnanglerad = 0;
	f32 groundy;
	bool hasdefaultweapon = false;
	struct cmd32 *cmd = (struct cmd32 *)g_StageSetup.intro;
	s32 stack[7];
	s32 i;
	s32 numchrs;
	struct gecreditsdata *thing;
	struct chrdata *chr;
	s32 bodynum;
	s32 headnum;

	func0f18e558();

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

	playerSetTickMode(TICKMODE_GE_FADEIN);

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
				cmd = (struct cmd32 *)((u32)cmd + 12);
				break;
			case INTROCMD_CASE:
			case INTROCMD_CASERESPAWN:
				cmd = (struct cmd32 *)((u32)cmd + 12);
				break;
			case INTROCMD_HILL:
				cmd = (struct cmd32 *)((u32)cmd + 8);
				break;
			case INTROCMD_WEAPON:
				if (cmd->param3 == 0 && g_Vars.currentplayer != g_Vars.anti) {
					modelmgrLoadProjectileModeldefs(cmd->param1);

					if (cmd->param2 >= 0) {
						modelmgrLoadProjectileModeldefs(cmd->param2);
						invGiveDoubleWeapon(cmd->param1, cmd->param2);
					} else {
						invGiveSingleWeapon(cmd->param1);
					}

					if (!hasdefaultweapon) {
						g_DefaultWeapons[HAND_RIGHT] = cmd->param1;

						if (cmd->param2 >= 0) {
							g_DefaultWeapons[HAND_LEFT] = cmd->param2;
						}

						hasdefaultweapon = true;
					}
				}
				cmd = (struct cmd32 *)((u32)cmd + 16);
				break;
			case INTROCMD_AMMO:
				if (cmd->param3 == 0 && g_Vars.currentplayer != g_Vars.anti) {
					bgunSetAmmoQuantity(cmd->param1, cmd->param2);
				}
				cmd = (struct cmd32 *)((u32)cmd + 16);
				break;
			case INTROCMD_3:
				cmd = (struct cmd32 *)((u32)cmd + 32);
				break;
			case INTROCMD_4:
				cmd = (struct cmd32 *)((u32)cmd + 8);
				break;
			case INTROCMD_OUTFIT:
				g_Vars.currentplayer->bondtype = cmd->param1;
				cmd = (struct cmd32 *)((u32)cmd + 8);
				break;
			case INTROCMD_6:
				cmd = (struct cmd32 *)((u32)cmd + 40);
				break;
			case INTROCMD_WATCHTIME:
				g_Vars.currentplayer->bondwatchtime60 = 0;
				if (cmd->param2 > 0) {
					g_Vars.currentplayer->bondwatchtime60 += (cmd->param2 % 60) * 3600;
				}
				if (cmd->param1 > 0) {
					g_Vars.currentplayer->bondwatchtime60 += (cmd->param1 % 12) * 3600 * 60;
				}
				cmd = (struct cmd32 *)((u32)cmd + 12);
				break;
			case INTROCMD_CREDITOFFSET:
				thing = (struct gecreditsdata *)((s32)g_GeCreditsData + cmd->param1);
				g_CurrentGeCreditsData = thing;
				while (thing->text1 || thing->text2) {
					thing++;
				}
				cmd = (struct cmd32 *)((u32)cmd + 8);
				break;
			default:
				cmd = (struct cmd32 *)((u32)cmd + 4);
			}
		}
	}

	invGiveSingleWeapon(WEAPON_UNARMED);

	if (!hasdefaultweapon) {
		g_DefaultWeapons[HAND_RIGHT] = WEAPON_UNARMED;
	}

	g_Vars.currentplayer->prop = propAllocate();
	g_Vars.currentplayer->prop->chr = NULL;
	g_Vars.currentplayer->prop->type = PROPTYPE_PLAYER;

	propActivate(g_Vars.currentplayer->prop);
	propEnable(g_Vars.currentplayer->prop);
	chrInit(g_Vars.currentplayer->prop);

	g_Vars.currentplayer->prop->chr->team = 1 << g_PlayerConfigsArray[g_Vars.currentplayerstats->mpindex].base.team;

	if (g_NumSpawnPoints > 0) {
		turnanglerad = M_BADTAU - scenarioChooseSpawnLocation(30, &pos, rooms, g_Vars.currentplayer->prop);
	}

	groundy = cdFindGroundInfoAtCyl(&pos, 30, rooms,
			&g_Vars.currentplayer->floorcol,
			&g_Vars.currentplayer->floortype,
			&g_Vars.currentplayer->floorflags,
			&g_Vars.currentplayer->floorroom,
			0, 0);

	pos.y = g_Vars.currentplayer->vv_eyeheight + groundy;
	g_Vars.currentplayer->vv_manground = groundy;
	g_Vars.currentplayer->vv_ground = groundy;
	g_Vars.currentplayer->vv_theta = (turnanglerad * 360.0f) / M_BADTAU;

	playerResetBond(&g_Vars.currentplayer->bond2, &pos);

	g_Vars.currentplayer->bond2.unk00.x = -sinf(turnanglerad);
	g_Vars.currentplayer->bond2.unk00.y = 0;
	g_Vars.currentplayer->bond2.unk00.z = cosf(turnanglerad);

	g_Vars.currentplayer->prop->pos.f[0] = g_Vars.currentplayer->bondprevpos.f[0] = pos.f[0];
	g_Vars.currentplayer->prop->pos.f[1] = g_Vars.currentplayer->bondprevpos.f[1] = pos.f[1];
	g_Vars.currentplayer->prop->pos.f[2] = g_Vars.currentplayer->bondprevpos.f[2] = pos.f[2];

	propDeregisterRooms(g_Vars.currentplayer->prop);

	g_Vars.currentplayer->prop->rooms[0] = rooms[0];
	g_Vars.currentplayer->prop->rooms[1] = -1;

	playerSetCamPropertiesWithRoom(&pos,
			&g_Vars.currentplayer->bond2.unk28,
			&g_Vars.currentplayer->bond2.unk1c, rooms[0]);

	numchrs = chrsGetNumSlots();

	for (i = 0; i < numchrs; i++) {
		chr = &g_ChrSlots[i];

		if (chr->target == -2) {
			chr->target = g_Vars.currentplayer->prop - g_Vars.props;
		}
	}

	bmoveUpdateRooms(g_Vars.currentplayer);

	if (g_Vars.normmplayerisrunning) {
		playersBeginMpSwirl();
	} else {
		player0f0b9a20();
	}

	g_NumDeathAnimations = 0;

	while (g_DeathAnimations[g_NumDeathAnimations] > 0) {
		g_NumDeathAnimations++;
	}

	g_Vars.currentplayer->tickdiefinished = false;
	g_Vars.currentplayer->chokehandle = NULL;

	for (i = 0; i != 4; i++) {
		g_Vars.aibuddies[i] = 0;
	}

	playerChooseBodyAndHead(&bodynum, &headnum, 0);
	g_Vars.currentplayer->prop->chr->bodynum = bodynum;
	g_Vars.currentplayer->prop->chr->headnum = headnum;
}
