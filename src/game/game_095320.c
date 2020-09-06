#include <ultra64.h>
#include "constants.h"
#include "game/chr/chraction.h"
#include "game/data/data_000000.h"
#include "game/data/data_0083d0.h"
#include "game/data/data_00e460.h"
#include "game/data/data_0160b0.h"
#include "game/data/data_01a3a0.h"
#include "game/data/data_020df0.h"
#include "game/data/data_02da90.h"
#include "game/debug.h"
#include "game/game_0601b0.h"
#include "game/game_091e10.h"
#include "game/game_095320.h"
#include "game/game_0b3350.h"
#include "game/game_0dcdb0.h"
#include "game/game_111600.h"
#include "game/game_127910.h"
#include "game/game_167ae0.h"
#include "game/training.h"
#include "game/lang.h"
#include "game/propobj.h"
#include "gvars/gvars.h"
#include "lib/lib_0d0a0.h"
#include "lib/lib_121e0.h"
#include "lib/lib_12dc0.h"
#include "lib/lib_13130.h"
#include "lib/lib_159b0.h"
#include "lib/lib_49a90.h"
#include "types.h"

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

	func00049ae0();

	ptr = (u32 *)(xorBoobless(0x04600010 ^ 0xb00b1e55) | 0xa0000000);

	value = *ptr;

	while (value & 3) {
		value = *ptr;
	}

	*arg1 = *(u32 *)(osRomBase | arg0 | 0xa0000000);

	func00049b24();
}

GLOBAL_ASM(
glabel func0f0953cc
/*  f0953cc:	3c02800a */ 	lui	$v0,%hi(var8009d0b0)
/*  f0953d0:	8c42d0b0 */ 	lw	$v0,%lo(var8009d0b0)($v0)
/*  f0953d4:	27bdffc8 */ 	addiu	$sp,$sp,-56
/*  f0953d8:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f0953dc:	10400009 */ 	beqz	$v0,.L0f095404
/*  f0953e0:	00003025 */ 	or	$a2,$zero,$zero
/*  f0953e4:	94430004 */ 	lhu	$v1,0x4($v0)
.L0f0953e8:
/*  f0953e8:	0066082a */ 	slt	$at,$v1,$a2
/*  f0953ec:	54200003 */ 	bnezl	$at,.L0f0953fc
/*  f0953f0:	8c420008 */ 	lw	$v0,0x8($v0)
/*  f0953f4:	24660001 */ 	addiu	$a2,$v1,0x1
/*  f0953f8:	8c420008 */ 	lw	$v0,0x8($v0)
.L0f0953fc:
/*  f0953fc:	5440fffa */ 	bnezl	$v0,.L0f0953e8
/*  f095400:	94430004 */ 	lhu	$v1,0x4($v0)
.L0f095404:
/*  f095404:	3c07800a */ 	lui	$a3,%hi(g_NumTags)
/*  f095408:	24e7d0c4 */ 	addiu	$a3,$a3,%lo(g_NumTags)
/*  f09540c:	10c0001b */ 	beqz	$a2,.L0f09547c
/*  f095410:	ace60000 */ 	sw	$a2,0x0($a3)
/*  f095414:	00062080 */ 	sll	$a0,$a2,0x2
/*  f095418:	2484000f */ 	addiu	$a0,$a0,0xf
/*  f09541c:	348f000f */ 	ori	$t7,$a0,0xf
/*  f095420:	39e4000f */ 	xori	$a0,$t7,0xf
/*  f095424:	00003025 */ 	or	$a2,$zero,$zero
/*  f095428:	24050004 */ 	addiu	$a1,$zero,0x4
/*  f09542c:	0c0048f2 */ 	jal	malloc
/*  f095430:	afa00034 */ 	sw	$zero,0x34($sp)
/*  f095434:	3c07800a */ 	lui	$a3,%hi(g_NumTags)
/*  f095438:	24e7d0c4 */ 	addiu	$a3,$a3,%lo(g_NumTags)
/*  f09543c:	8cf90000 */ 	lw	$t9,0x0($a3)
/*  f095440:	3c03800a */ 	lui	$v1,%hi(g_TagPtrs)
/*  f095444:	2463d0c8 */ 	addiu	$v1,$v1,%lo(g_TagPtrs)
/*  f095448:	ac620000 */ 	sw	$v0,0x0($v1)
/*  f09544c:	1b20000b */ 	blez	$t9,.L0f09547c
/*  f095450:	8fa60034 */ 	lw	$a2,0x34($sp)
/*  f095454:	00001025 */ 	or	$v0,$zero,$zero
/*  f095458:	8c680000 */ 	lw	$t0,0x0($v1)
.L0f09545c:
/*  f09545c:	24c60001 */ 	addiu	$a2,$a2,0x1
/*  f095460:	01024821 */ 	addu	$t1,$t0,$v0
/*  f095464:	ad200000 */ 	sw	$zero,0x0($t1)
/*  f095468:	8cea0000 */ 	lw	$t2,0x0($a3)
/*  f09546c:	24420004 */ 	addiu	$v0,$v0,4
/*  f095470:	00ca082a */ 	slt	$at,$a2,$t2
/*  f095474:	5420fff9 */ 	bnezl	$at,.L0f09545c
/*  f095478:	8c680000 */ 	lw	$t0,0x0($v1)
.L0f09547c:
/*  f09547c:	3c02800a */ 	lui	$v0,%hi(var8009d0b0)
/*  f095480:	8c42d0b0 */ 	lw	$v0,%lo(var8009d0b0)($v0)
/*  f095484:	3c03800a */ 	lui	$v1,%hi(g_TagPtrs)
/*  f095488:	2463d0c8 */ 	addiu	$v1,$v1,%lo(g_TagPtrs)
/*  f09548c:	10400009 */ 	beqz	$v0,.L0f0954b4
/*  f095490:	3c040aff */ 	lui	$a0,0xaff
/*  f095494:	944c0004 */ 	lhu	$t4,0x4($v0)
.L0f095498:
/*  f095498:	8c6b0000 */ 	lw	$t3,0x0($v1)
/*  f09549c:	000c6880 */ 	sll	$t5,$t4,0x2
/*  f0954a0:	016d7021 */ 	addu	$t6,$t3,$t5
/*  f0954a4:	adc20000 */ 	sw	$v0,0x0($t6)
/*  f0954a8:	8c420008 */ 	lw	$v0,0x8($v0)
/*  f0954ac:	5440fffa */ 	bnezl	$v0,.L0f095498
/*  f0954b0:	944c0004 */ 	lhu	$t4,0x4($v0)
.L0f0954b4:
/*  f0954b4:	0fc254c8 */ 	jal	xorBaffbeff
/*  f0954b8:	3484b4a3 */ 	ori	$a0,$a0,0xb4a3
/*  f0954bc:	3c04adfe */ 	lui	$a0,0xadfe
/*  f0954c0:	0fc254cc */ 	jal	xorBabeffff
/*  f0954c4:	34840006 */ 	ori	$a0,$a0,0x6
/*  f0954c8:	0c0057f4 */ 	jal	func00015fd0
/*  f0954cc:	afa20024 */ 	sw	$v0,0x24($sp)
/*  f0954d0:	8faf0024 */ 	lw	$t7,0x24($sp)
/*  f0954d4:	504f0011 */ 	beql	$v0,$t7,.L0f09551c
/*  f0954d8:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0954dc:	0c004b70 */ 	jal	random
/*  f0954e0:	00000000 */ 	nop
/*  f0954e4:	0c004b70 */ 	jal	random
/*  f0954e8:	afa2001c */ 	sw	$v0,0x1c($sp)
/*  f0954ec:	8fa4001c */ 	lw	$a0,0x1c($sp)
/*  f0954f0:	3c010001 */ 	lui	$at,0x1
/*  f0954f4:	3421fff8 */ 	ori	$at,$at,0xfff8
/*  f0954f8:	0081c024 */ 	and	$t8,$a0,$at
/*  f0954fc:	3c018001 */ 	lui	$at,0x8001
/*  f095500:	03012021 */ 	addu	$a0,$t8,$at
/*  f095504:	3c010001 */ 	lui	$at,0x1
/*  f095508:	3421fffe */ 	ori	$at,$at,0xfffe
/*  f09550c:	00412824 */ 	and	$a1,$v0,$at
/*  f095510:	0c003504 */ 	jal	func0000d410
/*  f095514:	24061000 */ 	addiu	$a2,$zero,0x1000
/*  f095518:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f09551c:
/*  f09551c:	27bd0038 */ 	addiu	$sp,$sp,0x38
/*  f095520:	03e00008 */ 	jr	$ra
/*  f095524:	00000000 */ 	nop
);

struct tag *tagFindById(s32 tag_id)
{
	struct tag *tag = NULL;

	if (tag_id >= 0 && tag_id < g_NumTags) {
		tag = g_TagPtrs[tag_id];
	}

	return tag;
}

s32 func0f095560(struct defaultobj *obj)
{
	struct var8009d0b0 *thing = var8009d0b0;

	if (obj && (obj->hidden & OBJHFLAG_00000010)) {
		while (thing) {
			if (obj == thing->obj) {
				return thing->unk04;
			}

			thing = thing->next;
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

	if (obj && (obj->hidden & OBJHFLAG_00000010) == 0) {
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

									if (currentPlayerHasProp(obj->prop)) {
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

									if (currentPlayerHasProp(obj->prop)) {
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

		if ((1 << getDifficulty() & diffbits) &&
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

				if (objectiveGetDifficultyBits(i) & (1 << getDifficulty())) {
					sprintf(buffer, "%s %d: ", langGet(L_MISC(44)), availableindex + 1); // "Objective"

					if (status == OBJECTIVE_COMPLETE) {
						strcat(buffer, langGet(L_MISC(45))); // "Completed"
						objectivesShowHudmsg(buffer, HUDMSGTYPE_OBJECTIVECOMPLETE);
					} else if (status == OBJECTIVE_INCOMPLETE) {
						strcat(buffer, langGet(L_MISC(46))); // "Incomplete"
						objectivesShowHudmsg(buffer, HUDMSGTYPE_OBJECTIVECOMPLETE);
					} else if (status == OBJECTIVE_FAILED) {
						strcat(buffer, langGet(L_MISC(47))); // "Failed"
						objectivesShowHudmsg(buffer, HUDMSGTYPE_OBJECTIVEFAILED);
					}
				}
			}

			if (objectiveGetDifficultyBits(i) & (1 << getDifficulty())) {
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
