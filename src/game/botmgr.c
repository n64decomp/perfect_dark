#include <ultra64.h>
#include "constants.h"
#include "game/game_0147d0.h"
#include "game/chr/chr.h"
#include "game/game_02cde0.h"
#include "game/prop.h"
#include "game/botcmd.h"
#include "game/mplayer/mplayer.h"
#include "bss.h"
#include "lib/memp.h"
#include "lib/model.h"
#include "lib/rng.h"
#include "lib/ailist.h"
#include "data.h"
#include "types.h"

void botmgrRemoveAll(void)
{
	s32 i;

	for (i = 0; i < 8; i++) {
		g_MpBotChrPtrs[i] = NULL;
	}

	g_BotCount = 0;
}

void botmgrAllocateBot(s32 chrnum, s32 aibotnum)
{
	s16 rooms[1];
	struct prop *prop;
	struct chrdata *chr;
	struct aibot *aibot;
	struct model *model;
	s32 i;
	s32 bodynum;
	s32 headnum;

	rooms[0] = -1;

	headnum = mpGetHeadId(g_BotConfigsArray[aibotnum].base.mpheadnum);
	bodynum = mpGetBodyId(g_BotConfigsArray[aibotnum].base.mpbodynum);

	if (IS4MB()) {
		headnum = HEAD_DDSHOCK;
		bodynum = BODY_DDSHOCK;
	}

	model = modelAllocateChr(bodynum, headnum, 0);

	if (model != NULL) {
		struct coord pos = {0.0f, 0.0f, 0.0f};
		u32 stack;

		prop = chrAllocate(model, &pos, rooms, 0.0f, ailistFindById(GAILIST_AIBOT_INIT));

		if (prop != NULL) {
			propActivate(prop);
			propEnable(prop);

			chr = prop->chr;

			chrSetChrnum(chr, chrnum);

			chr->chrnum = chrnum;
			chr->padpreset1 = -1;
			chr->chrpreset1 = -1;
			chr->hearingscale = 1;
			chr->visionrange = 80;
			chr->headnum = headnum;
			chr->bodynum = bodynum;
			chr->race = bodyGetRace(chr->bodynum);
			chr->flags = CHRFLAG0_CAN_EXAMINE_BODY; // reused flag?
			chr->flags2 = 0;
			chr->team = 1 << g_BotConfigsArray[aibotnum].base.team;
			chr->squadron = 0;

			if (g_BotCount < 8) {
				g_MpBotChrPtrs[g_BotCount] = chr;
				g_BotCount++;

				aibot = mempAlloc(sizeof(struct aibot), MEMPOOL_STAGE);
				chr->aibot = aibot;

				if (aibot != NULL) {
					chr->tude = 0;
					chr->voicebox = random() % 3;

					if (g_HeadsAndBodies[chr->bodynum].ismale == false) {
						chr->voicebox = VOICEBOX_FEMALE;
					}

					chr->target = -1;
					chr->naturalanim = 0;
					chr->myspecial = -1;
					chr->yvisang = 0;
					chr->teamscandist = 0;
					chr->convtalk = 0;
					chr->myaction = MA_AIBOTMAINLOOP;

					g_MpAllChrPtrs[g_MpNumChrs] = chr;
					g_MpAllChrConfigPtrs[g_MpNumChrs] = &g_BotConfigsArray[aibotnum].base;
					g_MpNumChrs++;

					aibot->ammoheld = mempAlloc(36 * sizeof(s32), MEMPOOL_STAGE);

					for (i = 0; i < 33; i++) {
						aibot->ammoheld[i] = 0;
					}

					aibot->config = &g_BotConfigsArray[aibotnum];

					switch (g_BotConfigsArray[aibotnum].difficulty) {
					case BOTDIFF_MEAT:
						aibot->unk000 = 0;
						break;
					case BOTDIFF_EASY:
						aibot->unk000 = 10;
						break;
					default:
					case BOTDIFF_NORMAL:
						aibot->unk000 = 20;
						break;
					case BOTDIFF_HARD:
						aibot->unk000 = 40;
						break;
					case BOTDIFF_PERFECT:
						aibot->unk000 = 60;
						break;
					case BOTDIFF_DARK:
						aibot->unk000 = 0;
						break;
					}

					aibot->aibotnum = aibotnum;
					aibot->unk064 = 0;
					aibot->fetchprop = NULL;
					aibot->unk02c[0] = 0;
					aibot->unk02c[1] = 0;
					aibot->unk034 = 0;
					aibot->unk040 = 0.0f;
					aibot->loadedammo[0] = 0;
					aibot->loadedammo[1] = 0;
					aibot->unk058 = 0;
					aibot->unk059 = 0;
					aibot->unk05c = 0;
					aibot->unk060 = 0;
#if !PAL
					aibot->unk030 = 301;
#endif
					aibot->unk038 = 0;
					aibot->unk03e = -1;
					aibot->unk03c = 0;
					aibot->attackingplayernum = -1;
					aibot->followingplayernum = -1;
					aibot->dangerouspropnum = -1;
					aibot->unk068 = 0;
					aibot->unk06c = 0.0f;
					aibot->unk070 = 0.0f;
					aibot->distmode = -1;
					aibot->lastkilledbyplayernum = -1;
					aibot->unk114 = -1;
					aibot->command = AIBOTCMD_NORMAL;
					aibot->unk098 = 0.0f;

					aibot->defendholdpos.x = pos.x;
					aibot->defendholdpos.y = pos.y;
					aibot->defendholdpos.z = pos.z;

					aibot->weaponnum = WEAPON_UNARMED;

					aibot->unk04d[0] = 0;
					aibot->unk04d[1] = 0;
					aibot->skrocket = NULL;
					aibot->unk0a0 = 0;

					aibot->gunfunc = 0;
					aibot->iscloserangeweapon = true;
					aibot->teamisonlyai = 0;
					aibot->unk09c_00 = 0;
					aibot->unk09c_01 = 0;
					aibot->cloakdeviceenabled = false;
					aibot->rcp120cloakenabled = false;
					aibot->unk04c_04 = 0;
					aibot->unk04c_03 = 0;
					aibot->unk04c_05 = 0;
					aibot->unk04c_00 = 0;

					aibot->unk048 = -1;
					aibot->unk04a = -1;

					aibot->unk0bc = -1;
					aibot->unk0c4[HAND_LEFT] = 0;
					aibot->unk0c4[HAND_RIGHT] = 0;
					aibot->unk0cc = 0;
					aibot->distmodettl60 = 0;
					aibot->unk0d8 = 0;
					aibot->unk0dc = 0;
					aibot->unk0e0[HAND_LEFT] = 0;
					aibot->unk0e0[HAND_RIGHT] = 0;
					aibot->maulercharge[HAND_LEFT] = 0.0f;
					aibot->maulercharge[HAND_RIGHT] = 0.0f;
					aibot->unk0a4 = model0001ae44(chr->model);
					aibot->angleoffset = 0.0f;
					aibot->speedtheta = 0.0f;
					aibot->unk0b0 = model0001ae44(chr->model);

					aibot->unk0b4 = 0.0f;
					aibot->unk0b8 = 0.0f;
					aibot->shotspeed.x = 0.0f;
					aibot->shotspeed.y = 0.0f;
					aibot->shotspeed.z = 0.0f;
					aibot->unk118 = 0;
					aibot->unk11c = 0;
					aibot->unk120 = -1;
					aibot->unk124 = -1;
					aibot->unk128 = 0;
					aibot->unk12c = 0;

					for (i = 0; i < 12; i++) {
						aibot->unk130[i] = -1;
						aibot->playerdistances[i] = U32_MAX;
						aibot->unk16c[i] = 0;
						aibot->unk178[i] = -1;
						aibot->unk1a8[i] = -1;
					}

					aibot->unk1c0 = 0.0f;
					aibot->unk1c4 = 0.0f;
					aibot->unk1c8 = 0.0f;
					aibot->unk1cc = -1;
					aibot->unk1d0 = 0;
					aibot->unk1d4 = 0.0f;
					aibot->unk1e4 = -1;
					aibot->unk1e8 = 0;
					aibot->unk208 = 0;
					aibot->rand = random();
					aibot->randttl60 = 0;

					for (i = 0; i < 6; i++) {
						aibot->killsbygunfunc[i][0] = 0.0f;
						aibot->killsbygunfunc[i][1] = 0.0f;

						aibot->suicidesbygunfunc[i][0] = 0.0f;
						aibot->suicidesbygunfunc[i][1] = 0.0f;

						aibot->equipdurations60[i][0] = 0;
						aibot->equipdurations60[i][1] = 0;

						aibot->unk2a8[i] = 0;
					}

					aibot->unk2a4 = 0;
					aibot->dampensuicidesttl60 = 0;
					aibot->unk2c4 = 0.0f;
					aibot->unk2c8 = 0;

					aibot->unk09c_03 = 0;

					aibot->unk2cc = 0;
					aibot->unk2d0 = random();
					aibot->unk2d4 = random() * (1.0f / U32_MAX);
					aibot->cheap = false;
#if VERSION >= VERSION_NTSC_1_0
					aibot->unk078 = 0;
					aibot->unk050 = 0;
					aibot->unk09d = 0;
#endif
				} else {
					g_MpBotChrPtrs[--g_BotCount] = NULL;
					return;
				}

				botinvInit(chr, 10);
			}
		}
	}
}
