#include <ultra64.h>
#include "constants.h"
#include "game/chraction.h"
#include "game/prop.h"
#include "game/setuputils.h"
#include "game/objectives.h"
#include "game/tex.h"
#include "game/camera.h"
#include "game/hudmsg.h"
#include "game/inv.h"
#include "game/playermgr.h"
#include "game/lv.h"
#include "game/training.h"
#include "game/lang.h"
#include "game/propobj.h"
#include "bss.h"
#include "lib/dma.h"
#include "lib/memp.h"
#include "lib/rng.h"
#include "lib/str.h"
#include "lib/mtx.h"
#include "data.h"
#include "types.h"

struct objective *g_Objectives[MAX_OBJECTIVES];
u32 g_ObjectiveStatuses[MAX_OBJECTIVES];
struct defaultobj **g_ObjsByTag;
struct tag *g_TagsLinkedList;
struct briefingobj *g_BriefingObjs;
struct criteria_holograph *g_HolographCriterias;
s32 g_NumTags;
bool g_ObjectivesDirty;
bool g_AnyObjectiveFailed;

s32 g_ObjectiveLastIndex = -1;
bool g_ObjectiveChecksDisabled = false;

void tagsReset(void)
{
	s32 index = 0;
	struct tag *tag = g_TagsLinkedList;

	while (tag) {
		if (tag->tagnum >= index) {
			index = tag->tagnum + 1;
		}

		tag = tag->next;
	}

	g_NumTags = index;

	if (g_NumTags) {
		u32 size = index * 4;
		g_ObjsByTag = mempAlloc(ALIGN16(size), MEMPOOL_STAGE);

		for (index = 0; index < g_NumTags; index++) {
			g_ObjsByTag[index] = NULL;
		}
	}

	tag = g_TagsLinkedList;

	while (tag) {
		g_ObjsByTag[tag->tagnum] = tag->obj;
		tag = tag->next;
	}
}

s32 objGetTagNum(struct defaultobj *obj)
{
	struct tag *tag = g_TagsLinkedList;

	if (obj && (obj->hidden & OBJHFLAG_TAGGED)) {
		while (tag) {
			if (obj == tag->obj) {
				return tag->tagnum;
			}

			tag = tag->next;
		}
	}

	return -1;
}

u32 objectiveGetDifficultyBits(s32 index)
{
	if (index < 10 && g_Objectives[index]) {
		return g_Objectives[index]->difficulties;
	}

	return DIFFBIT_A | DIFFBIT_SA | DIFFBIT_PA | DIFFBIT_PD;
}

/**
 * Check if an objective is complete.
 *
 * It starts be setting the objective's status to complete, then iterates each
 * requirement in the objective to decide whether to change it to incomplete or
 * failed.
 */
s32 objectiveCheck(s32 index)
{
	u32 stack[5];
	s32 objstatus = OBJECTIVE_COMPLETE;

	if (index < ARRAYCOUNT(g_Objectives)) {
		if (g_Objectives[index] == NULL) {
			objstatus = g_ObjectiveStatuses[index];
		} else {
			u32 *cmd = (u32 *)g_Objectives[index];

			// Move past beginobjective
			cmd = cmd + setupGetCmdLength(cmd);

			while ((u8)cmd[0] != OBJTYPE_ENDOBJECTIVE) {
				// The status of this requirement
				s32 reqstatus = OBJECTIVE_COMPLETE;

				switch ((u8)cmd[0]) {
				case OBJECTIVETYPE_COMPFLAGS:
					if ((g_StageFlags & cmd[1]) != cmd[1]) {
						reqstatus = OBJECTIVE_INCOMPLETE;
					}
					break;
				case OBJECTIVETYPE_FAILFLAGS:
					if (g_StageFlags & cmd[1]) {
						reqstatus = OBJECTIVE_FAILED;
					}
					break;
				case OBJECTIVETYPE_COLLECTOBJ:
					{
						struct defaultobj *obj = g_ObjsByTag[cmd[1]];
						s32 prevplayernum;
						s32 collected = false;
						s32 i;

						if (!obj || !obj->prop || !objIsHealthy(obj)) {
							reqstatus = OBJECTIVE_FAILED;
						} else {
							prevplayernum = g_Vars.currentplayernum;

							for (i = 0; i < PLAYERCOUNT(); i++) {
								if (g_Vars.players[i] == g_Vars.bond || g_Vars.players[i] == g_Vars.coop) {
									setCurrentPlayerNum(i);

									if (invHasProp(obj->prop)) {
										collected = true;
										break;
									}
								}
							}

							setCurrentPlayerNum(prevplayernum);

							if (!collected) {
						  	reqstatus = OBJECTIVE_INCOMPLETE;
							}
						}
					}
					break;
				case OBJECTIVETYPE_HOLOGRAPH:
					if (cmd[2] == OBJECTIVE_INCOMPLETE) {
						struct defaultobj *obj = g_ObjsByTag[cmd[1]];

						if (!obj || !obj->prop || !objIsHealthy(obj)) {
							reqstatus = OBJECTIVE_FAILED;
						} else {
							reqstatus = OBJECTIVE_INCOMPLETE;
						}
					}
					break;
				}

				if (reqstatus < objstatus) {
					objstatus = reqstatus;
				}

				cmd = cmd + setupGetCmdLength(cmd);
			}
		}
	}

	return objstatus;
}

bool objectiveIsAllComplete(void)
{
	s32 i;

	for (i = 0; i < (g_ObjectiveLastIndex + 1); i++) {
		u32 diffbits = objectiveGetDifficultyBits(i);

		if ((1 << g_Difficulty & diffbits) &&
				objectiveCheck(i) != OBJECTIVE_COMPLETE) {
			return false;
		}
	}

	return true;
}

void objectivesDisableChecking(void)
{
	g_ObjectiveChecksDisabled = true;
}

static void objectivesShowHudmsg(char *buffer, s32 hudmsgtype)
{
	s32 prevplayernum = g_Vars.currentplayernum;
	s32 i;

	for (i = 0; i < PLAYERCOUNT(); i++) {
		setCurrentPlayerNum(i);

		if (g_Vars.currentplayer == g_Vars.bond || g_Vars.currentplayer == g_Vars.coop) {
			hudmsgCreateWithFlags(buffer, hudmsgtype, HUDMSGFLAG_DELAY | HUDMSGFLAG_ALLOWDUPES);
		}
	}

	setCurrentPlayerNum(prevplayernum);
}

void objectivesCheckAll(void)
{
	s32 availableindex = 0;
	s32 i;
	char buffer[50];
	bool anyfailed = false;

	if (g_ObjectivesDirty && !g_ObjectiveChecksDisabled) {
		for (i = 0; i <= g_ObjectiveLastIndex; i++) {
			s32 status = objectiveCheck(i);

			if (g_ObjectiveStatuses[i] != status) {
				g_ObjectiveStatuses[i] = status;

				if (objectiveGetDifficultyBits(i) & (1 << g_Difficulty)) {
					sprintf(buffer, "%s %d: ", langGet(L_MISC_044), availableindex + 1); // "Objective"

					// NTSC 1.0 and above shows objective messages to everyone,
					// while beta only shows them to the current player.
					if (status == OBJECTIVE_COMPLETE) {
						strcat(buffer, langGet(L_MISC_045)); // "Completed"
						objectivesShowHudmsg(buffer, HUDMSGTYPE_OBJECTIVECOMPLETE);
					} else if (status == OBJECTIVE_INCOMPLETE) {
						strcat(buffer, langGet(L_MISC_046)); // "Incomplete"
						objectivesShowHudmsg(buffer, HUDMSGTYPE_OBJECTIVECOMPLETE);
					} else if (status == OBJECTIVE_FAILED) {
						strcat(buffer, langGet(L_MISC_047)); // "Failed"
						objectivesShowHudmsg(buffer, HUDMSGTYPE_OBJECTIVEFAILED);
					}
				}
			}

			if (status == OBJECTIVE_FAILED) {
				anyfailed = true;
			}

			if (objectiveGetDifficultyBits(i) & (1 << g_Difficulty)) {
				availableindex++;
			}
		}

		g_AnyObjectiveFailed = anyfailed;
		g_ObjectivesDirty = false;
	}
}

void objectiveCheckHolograph(f32 maxdist)
{
	struct criteria_holograph *criteria = g_HolographCriterias;

	while (criteria) {
		if (g_Vars.stagenum == STAGE_CITRAINING) {
			criteria->status = OBJECTIVE_INCOMPLETE;
		}

		if (criteria->status == OBJECTIVE_INCOMPLETE) {
			struct defaultobj *obj = g_ObjsByTag[criteria->obj];

			if (obj && obj->prop
					&& (obj->prop->flags & PROPFLAG_ONTHISSCREENTHISTICK)
					&& obj->prop->z >= 0
					&& objIsHealthy(obj)) {
				struct coord sp9c;
				f32 sp94[2];
				f32 sp8c[2];
				f32 dist = -1;

				if (maxdist != 0.0f) {
					f32 xdiff = obj->prop->pos.x - g_Vars.currentplayer->cam_pos.x;
					f32 zdiff = obj->prop->pos.z - g_Vars.currentplayer->cam_pos.z;
					dist = xdiff * xdiff + zdiff * zdiff;
					maxdist = maxdist * maxdist;
				}

				if (dist < maxdist && func0f0899dc(obj->prop, &sp9c, sp94, sp8c)) {
					f32 sp78[2];
					f32 sp70[2];
					func0f06803c(&sp9c, sp94, sp8c, sp78, sp70);

					if (sp78[0] > g_Vars.currentplayer->c_screenleft
							&& sp78[0] < g_Vars.currentplayer->c_screenleft + g_Vars.currentplayer->c_screenwidth
							&& sp70[0] > g_Vars.currentplayer->c_screenleft
							&& sp70[0] < g_Vars.currentplayer->c_screenleft + g_Vars.currentplayer->c_screenwidth
							&& sp78[1] > g_Vars.currentplayer->c_screentop
							&& sp78[1] < g_Vars.currentplayer->c_screentop + g_Vars.currentplayer->c_screenheight
							&& sp70[1] > g_Vars.currentplayer->c_screentop
							&& sp70[1] < g_Vars.currentplayer->c_screentop + g_Vars.currentplayer->c_screenheight) {
						criteria->status = OBJECTIVE_COMPLETE;

						if (g_Vars.stagenum == STAGE_CITRAINING) {
							struct trainingdata *data = dtGetData();
							data->holographedpc = true;
						}

						g_ObjectivesDirty = true;
					}
				}
			}
		}

		criteria = criteria->next;
	}
}
