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

GLOBAL_ASM(
glabel objectiveCheckHolograph
/*  f096088:	27bdff50 */ 	addiu	$sp,$sp,-176
/*  f09608c:	afb10034 */ 	sw	$s1,0x34($sp)
/*  f096090:	3c11800a */ 	lui	$s1,%hi(g_HolographCriterias)
/*  f096094:	8e31d0c0 */ 	lw	$s1,%lo(g_HolographCriterias)($s1)
/*  f096098:	f7b60028 */ 	sdc1	$f22,0x28($sp)
/*  f09609c:	46006586 */ 	mov.s	$f22,$f12
/*  f0960a0:	afbf004c */ 	sw	$ra,0x4c($sp)
/*  f0960a4:	afb60048 */ 	sw	$s6,0x48($sp)
/*  f0960a8:	afb50044 */ 	sw	$s5,0x44($sp)
/*  f0960ac:	afb40040 */ 	sw	$s4,0x40($sp)
/*  f0960b0:	afb3003c */ 	sw	$s3,0x3c($sp)
/*  f0960b4:	afb20038 */ 	sw	$s2,0x38($sp)
/*  f0960b8:	afb00030 */ 	sw	$s0,0x30($sp)
/*  f0960bc:	1220009a */ 	beqz	$s1,.L0f096328
/*  f0960c0:	f7b40020 */ 	sdc1	$f20,0x20($sp)
/*  f0960c4:	3c12800a */ 	lui	$s2,%hi(g_Vars)
/*  f0960c8:	26529fc0 */ 	addiu	$s2,$s2,%lo(g_Vars)
/*  f0960cc:	27b6008c */ 	addiu	$s6,$sp,0x8c
/*  f0960d0:	27b50094 */ 	addiu	$s5,$sp,0x94
/*  f0960d4:	27b4009c */ 	addiu	$s4,$sp,0x9c
/*  f0960d8:	24130026 */ 	addiu	$s3,$zero,0x26
/*  f0960dc:	8e4e04b4 */ 	lw	$t6,0x4b4($s2)
.L0f0960e0:
/*  f0960e0:	566e0003 */ 	bnel	$s3,$t6,.L0f0960f0
/*  f0960e4:	8e2f0008 */ 	lw	$t7,0x8($s1)
/*  f0960e8:	ae200008 */ 	sw	$zero,0x8($s1)
/*  f0960ec:	8e2f0008 */ 	lw	$t7,0x8($s1)
.L0f0960f0:
/*  f0960f0:	55e0008b */ 	bnezl	$t7,.L0f096320
/*  f0960f4:	8e31000c */ 	lw	$s1,0xc($s1)
/*  f0960f8:	0fc2556c */ 	jal	objFindByTagId
/*  f0960fc:	8e240004 */ 	lw	$a0,0x4($s1)
/*  f096100:	10400086 */ 	beqz	$v0,.L0f09631c
/*  f096104:	00408025 */ 	or	$s0,$v0,$zero
/*  f096108:	8c430014 */ 	lw	$v1,0x14($v0)
/*  f09610c:	50600084 */ 	beqzl	$v1,.L0f096320
/*  f096110:	8e31000c */ 	lw	$s1,0xc($s1)
/*  f096114:	90780001 */ 	lbu	$t8,0x1($v1)
/*  f096118:	33190002 */ 	andi	$t9,$t8,0x2
/*  f09611c:	53200080 */ 	beqzl	$t9,.L0f096320
/*  f096120:	8e31000c */ 	lw	$s1,0xc($s1)
/*  f096124:	c4640014 */ 	lwc1	$f4,0x14($v1)
/*  f096128:	44803000 */ 	mtc1	$zero,$f6
/*  f09612c:	00000000 */ 	nop
/*  f096130:	4604303e */ 	c.le.s	$f6,$f4
/*  f096134:	00000000 */ 	nop
/*  f096138:	45020079 */ 	bc1fl	.L0f096320
/*  f09613c:	8e31000c */ 	lw	$s1,0xc($s1)
/*  f096140:	0fc21a6a */ 	jal	objIsHealthy
/*  f096144:	00402025 */ 	or	$a0,$v0,$zero
/*  f096148:	50400075 */ 	beqzl	$v0,.L0f096320
/*  f09614c:	8e31000c */ 	lw	$s1,0xc($s1)
/*  f096150:	44804000 */ 	mtc1	$zero,$f8
/*  f096154:	3c01bf80 */ 	lui	$at,0xbf80
/*  f096158:	44816000 */ 	mtc1	$at,$f12
/*  f09615c:	4608b032 */ 	c.eq.s	$f22,$f8
/*  f096160:	02802825 */ 	or	$a1,$s4,$zero
/*  f096164:	02a03025 */ 	or	$a2,$s5,$zero
/*  f096168:	02c03825 */ 	or	$a3,$s6,$zero
/*  f09616c:	45030010 */ 	bc1tl	.L0f0961b0
/*  f096170:	4616603c */ 	c.lt.s	$f12,$f22
/*  f096174:	8e020014 */ 	lw	$v0,0x14($s0)
/*  f096178:	8e430284 */ 	lw	$v1,0x284($s2)
/*  f09617c:	c44a0008 */ 	lwc1	$f10,0x8($v0)
/*  f096180:	c4701bb0 */ 	lwc1	$f16,0x1bb0($v1)
/*  f096184:	c4520010 */ 	lwc1	$f18,0x10($v0)
/*  f096188:	c4641bb8 */ 	lwc1	$f4,0x1bb8($v1)
/*  f09618c:	46105001 */ 	sub.s	$f0,$f10,$f16
/*  f096190:	46049081 */ 	sub.s	$f2,$f18,$f4
/*  f096194:	46000182 */ 	mul.s	$f6,$f0,$f0
/*  f096198:	00000000 */ 	nop
/*  f09619c:	46021202 */ 	mul.s	$f8,$f2,$f2
/*  f0961a0:	46083300 */ 	add.s	$f12,$f6,$f8
/*  f0961a4:	4616b582 */ 	mul.s	$f22,$f22,$f22
/*  f0961a8:	00000000 */ 	nop
/*  f0961ac:	4616603c */ 	c.lt.s	$f12,$f22
.L0f0961b0:
/*  f0961b0:	00000000 */ 	nop
/*  f0961b4:	4502005a */ 	bc1fl	.L0f096320
/*  f0961b8:	8e31000c */ 	lw	$s1,0xc($s1)
/*  f0961bc:	0fc22677 */ 	jal	func0f0899dc
/*  f0961c0:	8e040014 */ 	lw	$a0,0x14($s0)
/*  f0961c4:	10400055 */ 	beqz	$v0,.L0f09631c
/*  f0961c8:	02802025 */ 	or	$a0,$s4,$zero
/*  f0961cc:	27a80070 */ 	addiu	$t0,$sp,0x70
/*  f0961d0:	afa80010 */ 	sw	$t0,0x10($sp)
/*  f0961d4:	02a02825 */ 	or	$a1,$s5,$zero
/*  f0961d8:	02c03025 */ 	or	$a2,$s6,$zero
/*  f0961dc:	0fc1a00f */ 	jal	func0f06803c
/*  f0961e0:	27a70078 */ 	addiu	$a3,$sp,0x78
/*  f0961e4:	0fc2d5fe */ 	jal	currentPlayerGetScreenLeft
/*  f0961e8:	00000000 */ 	nop
/*  f0961ec:	c7aa0078 */ 	lwc1	$f10,0x78($sp)
/*  f0961f0:	460a003c */ 	c.lt.s	$f0,$f10
/*  f0961f4:	00000000 */ 	nop
/*  f0961f8:	45020049 */ 	bc1fl	.L0f096320
/*  f0961fc:	8e31000c */ 	lw	$s1,0xc($s1)
/*  f096200:	0fc2d5fe */ 	jal	currentPlayerGetScreenLeft
/*  f096204:	00000000 */ 	nop
/*  f096208:	0fc2d5f6 */ 	jal	currentPlayerGetScreenWidth
/*  f09620c:	46000506 */ 	mov.s	$f20,$f0
/*  f096210:	46140480 */ 	add.s	$f18,$f0,$f20
/*  f096214:	c7b00078 */ 	lwc1	$f16,0x78($sp)
/*  f096218:	4612803c */ 	c.lt.s	$f16,$f18
/*  f09621c:	00000000 */ 	nop
/*  f096220:	4502003f */ 	bc1fl	.L0f096320
/*  f096224:	8e31000c */ 	lw	$s1,0xc($s1)
/*  f096228:	0fc2d5fe */ 	jal	currentPlayerGetScreenLeft
/*  f09622c:	00000000 */ 	nop
/*  f096230:	c7a40070 */ 	lwc1	$f4,0x70($sp)
/*  f096234:	4604003c */ 	c.lt.s	$f0,$f4
/*  f096238:	00000000 */ 	nop
/*  f09623c:	45020038 */ 	bc1fl	.L0f096320
/*  f096240:	8e31000c */ 	lw	$s1,0xc($s1)
/*  f096244:	0fc2d5fe */ 	jal	currentPlayerGetScreenLeft
/*  f096248:	00000000 */ 	nop
/*  f09624c:	0fc2d5f6 */ 	jal	currentPlayerGetScreenWidth
/*  f096250:	46000506 */ 	mov.s	$f20,$f0
/*  f096254:	46140200 */ 	add.s	$f8,$f0,$f20
/*  f096258:	c7a60070 */ 	lwc1	$f6,0x70($sp)
/*  f09625c:	4608303c */ 	c.lt.s	$f6,$f8
/*  f096260:	00000000 */ 	nop
/*  f096264:	4502002e */ 	bc1fl	.L0f096320
/*  f096268:	8e31000c */ 	lw	$s1,0xc($s1)
/*  f09626c:	0fc2d602 */ 	jal	currentPlayerGetScreenTop
/*  f096270:	00000000 */ 	nop
/*  f096274:	c7aa007c */ 	lwc1	$f10,0x7c($sp)
/*  f096278:	460a003c */ 	c.lt.s	$f0,$f10
/*  f09627c:	00000000 */ 	nop
/*  f096280:	45020027 */ 	bc1fl	.L0f096320
/*  f096284:	8e31000c */ 	lw	$s1,0xc($s1)
/*  f096288:	0fc2d602 */ 	jal	currentPlayerGetScreenTop
/*  f09628c:	00000000 */ 	nop
/*  f096290:	0fc2d5fa */ 	jal	currentPlayerGetScreenHeight
/*  f096294:	46000506 */ 	mov.s	$f20,$f0
/*  f096298:	46140480 */ 	add.s	$f18,$f0,$f20
/*  f09629c:	c7b0007c */ 	lwc1	$f16,0x7c($sp)
/*  f0962a0:	4612803c */ 	c.lt.s	$f16,$f18
/*  f0962a4:	00000000 */ 	nop
/*  f0962a8:	4502001d */ 	bc1fl	.L0f096320
/*  f0962ac:	8e31000c */ 	lw	$s1,0xc($s1)
/*  f0962b0:	0fc2d602 */ 	jal	currentPlayerGetScreenTop
/*  f0962b4:	00000000 */ 	nop
/*  f0962b8:	c7a40074 */ 	lwc1	$f4,0x74($sp)
/*  f0962bc:	4604003c */ 	c.lt.s	$f0,$f4
/*  f0962c0:	00000000 */ 	nop
/*  f0962c4:	45020016 */ 	bc1fl	.L0f096320
/*  f0962c8:	8e31000c */ 	lw	$s1,0xc($s1)
/*  f0962cc:	0fc2d602 */ 	jal	currentPlayerGetScreenTop
/*  f0962d0:	00000000 */ 	nop
/*  f0962d4:	0fc2d5fa */ 	jal	currentPlayerGetScreenHeight
/*  f0962d8:	46000506 */ 	mov.s	$f20,$f0
/*  f0962dc:	46140200 */ 	add.s	$f8,$f0,$f20
/*  f0962e0:	c7a60074 */ 	lwc1	$f6,0x74($sp)
/*  f0962e4:	24090001 */ 	addiu	$t1,$zero,0x1
/*  f0962e8:	4608303c */ 	c.lt.s	$f6,$f8
/*  f0962ec:	00000000 */ 	nop
/*  f0962f0:	4502000b */ 	bc1fl	.L0f096320
/*  f0962f4:	8e31000c */ 	lw	$s1,0xc($s1)
/*  f0962f8:	ae290008 */ 	sw	$t1,0x8($s1)
/*  f0962fc:	8e4a04b4 */ 	lw	$t2,0x4b4($s2)
/*  f096300:	566a0007 */ 	bnel	$s3,$t2,.L0f096320
/*  f096304:	8e31000c */ 	lw	$s1,0xc($s1)
/*  f096308:	0fc68606 */ 	jal	dtGetData
/*  f09630c:	00000000 */ 	nop
/*  f096310:	904c0000 */ 	lbu	$t4,0x0($v0)
/*  f096314:	358d0008 */ 	ori	$t5,$t4,0x8
/*  f096318:	a04d0000 */ 	sb	$t5,0x0($v0)
.L0f09631c:
/*  f09631c:	8e31000c */ 	lw	$s1,0xc($s1)
.L0f096320:
/*  f096320:	5620ff6f */ 	bnezl	$s1,.L0f0960e0
/*  f096324:	8e4e04b4 */ 	lw	$t6,0x4b4($s2)
.L0f096328:
/*  f096328:	8fbf004c */ 	lw	$ra,0x4c($sp)
/*  f09632c:	d7b40020 */ 	ldc1	$f20,0x20($sp)
/*  f096330:	d7b60028 */ 	ldc1	$f22,0x28($sp)
/*  f096334:	8fb00030 */ 	lw	$s0,0x30($sp)
/*  f096338:	8fb10034 */ 	lw	$s1,0x34($sp)
/*  f09633c:	8fb20038 */ 	lw	$s2,0x38($sp)
/*  f096340:	8fb3003c */ 	lw	$s3,0x3c($sp)
/*  f096344:	8fb40040 */ 	lw	$s4,0x40($sp)
/*  f096348:	8fb50044 */ 	lw	$s5,0x44($sp)
/*  f09634c:	8fb60048 */ 	lw	$s6,0x48($sp)
/*  f096350:	03e00008 */ 	jr	$ra
/*  f096354:	27bd00b0 */ 	addiu	$sp,$sp,0xb0
/*  f096358:	00000000 */ 	nop
/*  f09635c:	00000000 */ 	nop
);
