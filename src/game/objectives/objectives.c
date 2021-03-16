#include <ultra64.h>
#include "constants.h"
#include "game/chr/chraction.h"
#include "game/debug.h"
#include "game/prop.h"
#include "game/game_091e10.h"
#include "game/game_095320.h"
#include "game/game_0b3350.h"
#include "game/game_0b4950.h"
#include "game/hudmsg.h"
#include "game/inventory/inventory.h"
#include "game/game_127910.h"
#include "game/core.h"
#include "game/training/training.h"
#include "game/lang.h"
#include "game/propobj.h"
#include "bss.h"
#include "lib/dma.h"
#include "lib/memory.h"
#include "lib/rng.h"
#include "lib/lib_159b0.h"
#include "data.h"
#include "types.h"

struct objective *g_Objectives[MAX_OBJECTIVES];
u32 g_ObjectiveStatuses[MAX_OBJECTIVES];
struct tag *g_TagsLinkedList;
struct briefingobj *g_BriefingObjs;
struct criteria_roomentered *g_RoomEnteredCriterias;
struct criteria_multiroomentered *g_MultiroomEnteredCriterias;
struct criteria_holograph *g_HolographCriterias;
s32 g_NumTags;
struct tag **g_TagPtrs;
u32 var8009d0cc;

s32 g_ObjectiveLastIndex = -1;
bool g_ObjectiveChecksDisabled = false;

u32 xorBaffbeff(u32 value)
{
	return value ^ 0xbaffbeff;
}

u32 xorBabeffff(u32 value)
{
	return value ^ 0xbabeffff;
}

u32 xorBoobless(u32 value)
{
	return value ^ 0xb00b1e55;
}

/**
 * This is very likely to be an unused piracy check.
 * This function is never called.
 */
void func0f095350(u32 arg0, u32 *arg1)
{
	volatile u32 *ptr;
	u32 value;

	__osPiGetAccess();

	ptr = (u32 *)(xorBoobless(0x04600010 ^ 0xb00b1e55) | 0xa0000000);

	value = *ptr;

	while (value & 3) {
		value = *ptr;
	}

	*arg1 = *(u32 *)(osRomBase | arg0 | 0xa0000000);

	__osPiRelAccess();
}

void tagsAllocatePtrs(void)
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
		g_TagPtrs = malloc(ALIGN16(size), MEMPOOL_STAGE);

		for (index = 0; index < g_NumTags; index++) {
			g_TagPtrs[index] = NULL;
		}
	}

	tag = g_TagsLinkedList;

	while (tag) {
		g_TagPtrs[tag->tagnum] = tag;
		tag = tag->next;
	}

#if PIRACYCHECKS
	{
		u32 a = xorBaffbeff(0xb0000a5c ^ 0xbaffbeff);
		u32 b = xorBabeffff(0x1740fff9 ^ 0xbabeffff);

		if (func00015fd0() != b) {
			// Read 4KB from a random ROM location within 128KB from the start of
			// the ROM, and write it to a random memory location between 0x80010000
			// and 0x80030ff8. This will corrupt instructions in the lib segment.
			dmaExec((u8 *)((random() & 0x1fff8) + 0x80010000), (u8 *)(random() & 0x1fffe), 0x1000);
		}
	}
#endif
}

struct tag *tagFindById(s32 tag_id)
{
	struct tag *tag = NULL;

	if (tag_id >= 0 && tag_id < g_NumTags) {
		tag = g_TagPtrs[tag_id];
	}

	return tag;
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

struct defaultobj *objFindByTagId(s32 tag_id)
{
	struct tag *tag = tagFindById(tag_id);
	struct defaultobj *obj = NULL;

	if (tag) {
		obj = tag->obj;
	}

	if (obj && (obj->hidden & OBJHFLAG_TAGGED) == 0) {
		obj = NULL;
	}

	return obj;
}

s32 objectiveGetCount(void)
{
	return g_ObjectiveLastIndex + 1;
}

char *objectiveGetText(s32 index)
{
	if (index < 10 && g_Objectives[index]) {
		return langGet(g_Objectives[index]->text);
	}

	return NULL;
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
			// Note: This is setting the cmd pointer to the start of the
			// beginobjective macro in the stage's setup file. The first
			// iteration of the while loop below will skip past it.
			u32 *cmd = (u32 *)g_Objectives[index];

			while ((u8)cmd[0] != OBJTYPE_ENDOBJECTIVE) {
				// The status of this requirement
				s32 reqstatus = OBJECTIVE_COMPLETE;

				switch ((u8)cmd[0]) {
				case OBJECTIVETYPE_DESTROYOBJ:
					{
						struct defaultobj *obj = objFindByTagId(cmd[1]);
						if (obj && obj->prop && objIsHealthy(obj)) {
							reqstatus = OBJECTIVE_INCOMPLETE;
						}
					}
					break;
				case OBJECTIVETYPE_COMPFLAGS:
					if (!chrHasStageFlag(NULL, cmd[1])) {
						reqstatus = OBJECTIVE_INCOMPLETE;
					}
					break;
				case OBJECTIVETYPE_FAILFLAGS:
					if (chrHasStageFlag(NULL, cmd[1])) {
						reqstatus = OBJECTIVE_FAILED;
					}
					break;
				case OBJECTIVETYPE_COLLECTOBJ:
					{
						struct defaultobj *obj = objFindByTagId(cmd[1]);
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
				case OBJECTIVETYPE_THROWOBJ:
					{
						struct defaultobj *obj = objFindByTagId(cmd[1]);

						if (obj && obj->prop) {
							s32 i;
							s32 prevplayernum = g_Vars.currentplayernum;

							for (i = 0; i < PLAYERCOUNT(); i++) {
								if (g_Vars.players[i] == g_Vars.bond || g_Vars.players[i] == g_Vars.coop) {
									setCurrentPlayerNum(i);

									if (invHasProp(obj->prop)) {
										reqstatus = OBJECTIVE_INCOMPLETE;
										break;
									}
								}
							}

							setCurrentPlayerNum(prevplayernum);
						}
					}
					break;
				case OBJECTIVETYPE_HOLOGRAPH:
					{
						struct defaultobj *obj = objFindByTagId(cmd[1]);

						if (cmd[2] == 0) {
							if (!obj || !obj->prop || !objIsHealthy(obj)) {
								reqstatus = OBJECTIVE_FAILED;
							} else {
								reqstatus = OBJECTIVE_INCOMPLETE;
							}
						}
					}
					break;
				case OBJECTIVETYPE_ENTERROOM:
					if (cmd[2] == 0) {
						reqstatus = OBJECTIVE_INCOMPLETE;
					}
					break;
				case OBJECTIVETYPE_ATTACHOBJ:
					if (cmd[3] == 0) {
						reqstatus = OBJECTIVE_INCOMPLETE;
					}
					break;
				case OBJTYPE_BEGINOBJECTIVE:
				case OBJTYPE_ENDOBJECTIVE:
					break;
				}

				if (objstatus == OBJECTIVE_COMPLETE) {
					if (reqstatus != OBJECTIVE_COMPLETE) {
						// This is the first requirement that is causing the
						// objective to not be complete, so apply it.
						objstatus = reqstatus;
					}
				} else if (objstatus == OBJECTIVE_INCOMPLETE) {
					if (reqstatus == OBJECTIVE_FAILED) {
						// An earlier requirement was incomplete,
						// and this requirement is failed.
						objstatus = reqstatus;
					}
				}

				cmd = cmd + setupGetCommandLength(cmd);
			}
		}
	}

	if (debugForceAllObjectivesComplete()) {
		objstatus = OBJECTIVE_COMPLETE;
	}

	return objstatus;
}

bool objectiveIsAllComplete(void)
{
	s32 i;

	for (i = 0; i < objectiveGetCount(); i++) {
		u32 diffbits = objectiveGetDifficultyBits(i);

		if ((1 << coreGetDifficulty() & diffbits) &&
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

void objectivesShowHudmsg(char *buffer, s32 hudmsgtype)
{
	s32 prevplayernum = g_Vars.currentplayernum;
	s32 i;

	for (i = 0; i < PLAYERCOUNT(); i++) {
		setCurrentPlayerNum(i);

		if (g_Vars.currentplayer == g_Vars.bond || g_Vars.currentplayer == g_Vars.coop) {
			func0f0ddfa4(buffer, hudmsgtype, 24);
		}
	}

	setCurrentPlayerNum(prevplayernum);
}

void objectivesCheckAll(void)
{
	s32 availableindex = 0;
	s32 i;
	char buffer[50] = "";

	if (!g_ObjectiveChecksDisabled) {
		for (i = 0; i <= g_ObjectiveLastIndex; i++) {
			s32 status = objectiveCheck(i);

			if (g_ObjectiveStatuses[i] != status) {
				g_ObjectiveStatuses[i] = status;

				if (objectiveGetDifficultyBits(i) & (1 << coreGetDifficulty())) {
					sprintf(buffer, "%s %d: ", langGet(L_MISC_044), availableindex + 1); // "Objective"

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

			if (objectiveGetDifficultyBits(i) & (1 << coreGetDifficulty())) {
				availableindex++;
			}
		}
	}
}

void objectiveCheckRoomEntered(s32 currentroom)
{
	struct criteria_roomentered *criteria = g_RoomEnteredCriterias;

	while (criteria) {
		if (criteria->status == OBJECTIVE_INCOMPLETE) {
			s32 room = chrGetPadRoom(NULL, criteria->pad);

			if (room >= 0 && room == currentroom) {
				criteria->status = OBJECTIVE_COMPLETE;
			}
		}

		criteria = criteria->next;
	}
}

void objectiveCheckMultiroomEntered(s32 arg0, s16 *requiredrooms)
{
	struct criteria_multiroomentered *criteria = g_MultiroomEnteredCriterias;

	while (criteria) {
		if (criteria->status == OBJECTIVE_INCOMPLETE && criteria->unk04 == arg0) {
			s32 room = chrGetPadRoom(NULL, criteria->pad);

			if (room >= 0) {
				s16 objectiverooms[2];
				objectiverooms[0] = room;
				objectiverooms[1] = -1;

				if (arrayIntersects(objectiverooms, requiredrooms)) {
					criteria->status = OBJECTIVE_COMPLETE;
				}
			}
		}

		criteria = criteria->next;
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
			struct defaultobj *obj = objFindByTagId(criteria->obj);
			u32 stack;

			if (obj && obj->prop
					&& (obj->prop->flags & PROPFLAG_02)
					&& obj->prop->z >= 0
					&& objIsHealthy(obj)) {
				f32 sp9c[2];
				f32 sp94[2];
				f32 sp8c[2];
				f32 dist = -1;

				if (maxdist != 0.0f) {
					f32 xdiff = obj->prop->pos.x - g_Vars.currentplayer->cam_pos.x;
					f32 zdiff = obj->prop->pos.z - g_Vars.currentplayer->cam_pos.z;
					dist = xdiff * xdiff + zdiff * zdiff;
					maxdist = maxdist * maxdist;
				}

				if (dist < maxdist && func0f0899dc(obj->prop, sp9c, sp94, sp8c)) {
					f32 sp78[2];
					f32 sp70[2];
					func0f06803c(sp9c, sp94, sp8c, sp78, sp70);

					if (sp78[0] > currentPlayerGetScreenLeft()
							&& sp78[0] < currentPlayerGetScreenLeft() + currentPlayerGetScreenWidth()
							&& sp70[0] > currentPlayerGetScreenLeft()
							&& sp70[0] < currentPlayerGetScreenLeft() + currentPlayerGetScreenWidth()
							&& sp78[1] > currentPlayerGetScreenTop()
							&& sp78[1] < currentPlayerGetScreenTop() + currentPlayerGetScreenHeight()
							&& sp70[1] > currentPlayerGetScreenTop()
							&& sp70[1] < currentPlayerGetScreenTop() + currentPlayerGetScreenHeight()) {
						criteria->status = OBJECTIVE_COMPLETE;

						if (g_Vars.stagenum == STAGE_CITRAINING) {
							struct trainingdata *data = dtGetData();
							data->holographedpc = true;
						}
					}
				}
			}
		}

		criteria = criteria->next;
	}
}

// Too much stack usage and unknown functions to decompile this accurately
// at the moment.
//void objectiveCheckHolograph(s32 arg0)
//{
//	struct criteria_holograph *criteria = g_HolographCriterias;
//
//	while (criteria) {
//		if (g_Vars.stagenum == STAGE_CITRAINING) {
//			criteria->status = OBJECTIVE_INCOMPLETE;
//		}
//
//		if (criteria->status == OBJECTIVE_INCOMPLETE) {
//			struct defaultobj *obj = objFindByTagId(criteria->obj);
//
//			if (obj && obj->prop && obj->prop->flags & 2 && obj->prop->z > 0 && func0f0869a8(obj)) {
//				f32 fVar11 = arg0;
//				s32 a[2];
//				s32 b[2];
//				s32 c[2];
//
//				if (fVar11 != 0.00000000) {
//					float xdiff = obj->prop->pos.x - g_Vars.currentplayer->cam_pos.x;
//					float zdiff = obj->prop->pos.z - g_Vars.currentplayer->cam_pos.z;
//					pass = xdiff * xdiff + zdiff * zdiff < fVar11 * fVar11;
//				} else {
//					pass = fVar11 > -1;
//				}
//
//				if (pass && func0f0899dc(obj->prop, a, b, c))  {
//					func0f06803c(a, b, c, &fStack56);
//
//					if (currentPlayerGetScreenLeft() < fStack56 && fStack56 < currentPlayerGetScreenWidth() + currentPlayerGetScreenLeft() &&
//							currentPlayerGetScreenLeft() < fStack64 && fStack64 < currentPlayerGetScreenWidth() + currentPlayerGetScreenLeft() &&
//							currentPlayerGetScreenTop() < fStack52 && fStack52 < currentPlayerGetScreenHeight() + currentPlayerGetScreenTop() &&
//							currentPlayerGetScreenTop() < fStack60 && fStack60 < currentPlayerGetScreenHeight() + currentPlayerGetScreenTop()) {
//						criteria->status = OBJECTIVE_COMPLETE;
//
//						if (g_Vars.stagenum == STAGE_CITRAINING) {
//							struct trainingdata *data = dtGetData();
//							data->holographedpc = true;
//						}
//					}
//				}
//			}
//		}
//
//		criteria = criteria->next;
//	}
//}
