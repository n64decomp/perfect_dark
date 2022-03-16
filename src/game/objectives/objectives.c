#include <ultra64.h>
#include "constants.h"
#include "game/chr/chraction.h"
#include "game/debug.h"
#include "game/prop.h"
#include "game/game_091e10.h"
#include "game/objectives.h"
#include "game/game_0b3350.h"
#include "game/game_0b4950.h"
#include "game/hudmsg.h"
#include "game/inventory/inventory.h"
#include "game/playermgr.h"
#include "game/lv.h"
#include "game/training/training.h"
#include "game/lang.h"
#include "game/propobj.h"
#include "bss.h"
#include "lib/dma.h"
#include "lib/memp.h"
#include "lib/rng.h"
#include "lib/mtx.h"
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

#if PIRACYCHECKS
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

	*arg1 = *(u32 *)((u32)osRomBase | arg0 | 0xa0000000);

	__osPiRelAccess();
}
#endif

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
		g_TagPtrs = mempAlloc(ALIGN16(size), MEMPOOL_STAGE);

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

		if (mtxGetObfuscatedRomBase() != b) {
			// Read 4KB from a random ROM location within 128KB from the start of
			// the ROM, and write it to a random memory location between 0x80010000
			// and 0x80030ff8. This will corrupt instructions in the lib segment.
			dmaExec((u8 *)((random() & 0x1fff8) + 0x80010000), random() & 0x1fffe, 0x1000);
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

		if ((1 << lvGetDifficulty() & diffbits) &&
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

#if VERSION >= VERSION_NTSC_1_0
void objectivesShowHudmsg(char *buffer, s32 hudmsgtype)
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
#endif

#if VERSION >= VERSION_JPN_FINAL
const char var7f1ac410jf[50] = "";
const char var7f1ac444jf[] = "%s %s: ";

GLOBAL_ASM(
glabel objectivesCheckAll
/*  f096ae4:	27bdff70 */ 	addiu	$sp,$sp,-144
/*  f096ae8:	afb20020 */ 	sw	$s2,0x20($sp)
/*  f096aec:	3c0e7f1b */ 	lui	$t6,0x7f1b
/*  f096af0:	27b20054 */ 	addiu	$s2,$sp,0x54
/*  f096af4:	afb5002c */ 	sw	$s5,0x2c($sp)
/*  f096af8:	25cec410 */ 	addiu	$t6,$t6,-15344
/*  f096afc:	afbf003c */ 	sw	$ra,0x3c($sp)
/*  f096b00:	afbe0038 */ 	sw	$s8,0x38($sp)
/*  f096b04:	afb70034 */ 	sw	$s7,0x34($sp)
/*  f096b08:	afb60030 */ 	sw	$s6,0x30($sp)
/*  f096b0c:	afb40028 */ 	sw	$s4,0x28($sp)
/*  f096b10:	afb30024 */ 	sw	$s3,0x24($sp)
/*  f096b14:	afb1001c */ 	sw	$s1,0x1c($sp)
/*  f096b18:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f096b1c:	0000a825 */ 	move	$s5,$zero
/*  f096b20:	25d90030 */ 	addiu	$t9,$t6,0x30
/*  f096b24:	02404025 */ 	move	$t0,$s2
.JF0f096b28:
/*  f096b28:	8dc10000 */ 	lw	$at,0x0($t6)
/*  f096b2c:	25ce000c */ 	addiu	$t6,$t6,0xc
/*  f096b30:	2508000c */ 	addiu	$t0,$t0,0xc
/*  f096b34:	ad01fff4 */ 	sw	$at,-0xc($t0)
/*  f096b38:	8dc1fff8 */ 	lw	$at,-0x8($t6)
/*  f096b3c:	ad01fff8 */ 	sw	$at,-0x8($t0)
/*  f096b40:	8dc1fffc */ 	lw	$at,-0x4($t6)
/*  f096b44:	15d9fff8 */ 	bne	$t6,$t9,.JF0f096b28
/*  f096b48:	ad01fffc */ 	sw	$at,-0x4($t0)
/*  f096b4c:	95c10000 */ 	lhu	$at,0x0($t6)
/*  f096b50:	3c098007 */ 	lui	$t1,0x8007
/*  f096b54:	3c178007 */ 	lui	$s7,0x8007
/*  f096b58:	a5010000 */ 	sh	$at,0x0($t0)
/*  f096b5c:	8d29b474 */ 	lw	$t1,-0x4b8c($t1)
/*  f096b60:	26f7b470 */ 	addiu	$s7,$s7,-19344
/*  f096b64:	5520005b */ 	bnezl	$t1,.JF0f096cd4
/*  f096b68:	8fbf003c */ 	lw	$ra,0x3c($sp)
/*  f096b6c:	8eea0000 */ 	lw	$t2,0x0($s7)
/*  f096b70:	3c14800a */ 	lui	$s4,0x800a
/*  f096b74:	2694d748 */ 	addiu	$s4,$s4,-10424
/*  f096b78:	05400055 */ 	bltz	$t2,.JF0f096cd0
/*  f096b7c:	00009825 */ 	move	$s3,$zero
/*  f096b80:	3c1e8007 */ 	lui	$s8,0x8007
/*  f096b84:	27deb478 */ 	addiu	$s8,$s8,-19336
/*  f096b88:	27b6004c */ 	addiu	$s6,$sp,0x4c
.JF0f096b8c:
/*  f096b8c:	0fc25901 */ 	jal	0xf096404
/*  f096b90:	02602025 */ 	move	$a0,$s3
/*  f096b94:	8e8b0000 */ 	lw	$t3,0x0($s4)
/*  f096b98:	00408825 */ 	move	$s1,$v0
/*  f096b9c:	02602025 */ 	move	$a0,$s3
/*  f096ba0:	104b003b */ 	beq	$v0,$t3,.JF0f096c90
/*  f096ba4:	00000000 */ 	nop
/*  f096ba8:	0fc258f4 */ 	jal	0xf0963d0
/*  f096bac:	ae820000 */ 	sw	$v0,0x0($s4)
/*  f096bb0:	0fc5b3cf */ 	jal	0xf16cf3c
/*  f096bb4:	00408025 */ 	move	$s0,$v0
/*  f096bb8:	240c0001 */ 	li	$t4,0x1
/*  f096bbc:	004c6804 */ 	sllv	$t5,$t4,$v0
/*  f096bc0:	01b0c024 */ 	and	$t8,$t5,$s0
/*  f096bc4:	13000032 */ 	beqz	$t8,.JF0f096c90
/*  f096bc8:	240e0080 */ 	li	$t6,0x80
/*  f096bcc:	9bc10002 */ 	lwr	$at,0x2($s8)
/*  f096bd0:	26a80011 */ 	addiu	$t0,$s5,0x11
/*  f096bd4:	35090080 */ 	ori	$t1,$t0,0x80
/*  f096bd8:	bac10002 */ 	swr	$at,0x2($s6)
/*  f096bdc:	a3ae004c */ 	sb	$t6,0x4c($sp)
/*  f096be0:	a3a9004d */ 	sb	$t1,0x4d($sp)
/*  f096be4:	0fc5baa5 */ 	jal	0xf16ea94
/*  f096be8:	24045803 */ 	li	$a0,0x5803
/*  f096bec:	3c057f1b */ 	lui	$a1,0x7f1b
/*  f096bf0:	24a5c444 */ 	addiu	$a1,$a1,-15292
/*  f096bf4:	02402025 */ 	move	$a0,$s2
/*  f096bf8:	00403025 */ 	move	$a2,$v0
/*  f096bfc:	0c004d95 */ 	jal	0x13654
/*  f096c00:	02c03825 */ 	move	$a3,$s6
/*  f096c04:	24010001 */ 	li	$at,0x1
/*  f096c08:	1621000b */ 	bne	$s1,$at,.JF0f096c38
/*  f096c0c:	00000000 */ 	nop
/*  f096c10:	0fc5baa5 */ 	jal	0xf16ea94
/*  f096c14:	24045804 */ 	li	$a0,0x5804
/*  f096c18:	02402025 */ 	move	$a0,$s2
/*  f096c1c:	0c004c71 */ 	jal	0x131c4
/*  f096c20:	00402825 */ 	move	$a1,$v0
/*  f096c24:	02402025 */ 	move	$a0,$s2
/*  f096c28:	0fc25a61 */ 	jal	0xf096984
/*  f096c2c:	24050001 */ 	li	$a1,0x1
/*  f096c30:	10000017 */ 	b	.JF0f096c90
/*  f096c34:	00000000 */ 	nop
.JF0f096c38:
/*  f096c38:	1620000b */ 	bnez	$s1,.JF0f096c68
/*  f096c3c:	24010002 */ 	li	$at,0x2
/*  f096c40:	0fc5baa5 */ 	jal	0xf16ea94
/*  f096c44:	24045805 */ 	li	$a0,0x5805
/*  f096c48:	02402025 */ 	move	$a0,$s2
/*  f096c4c:	0c004c71 */ 	jal	0x131c4
/*  f096c50:	00402825 */ 	move	$a1,$v0
/*  f096c54:	02402025 */ 	move	$a0,$s2
/*  f096c58:	0fc25a61 */ 	jal	0xf096984
/*  f096c5c:	24050001 */ 	li	$a1,0x1
/*  f096c60:	1000000b */ 	b	.JF0f096c90
/*  f096c64:	00000000 */ 	nop
.JF0f096c68:
/*  f096c68:	16210009 */ 	bne	$s1,$at,.JF0f096c90
/*  f096c6c:	00000000 */ 	nop
/*  f096c70:	0fc5baa5 */ 	jal	0xf16ea94
/*  f096c74:	24045806 */ 	li	$a0,0x5806
/*  f096c78:	02402025 */ 	move	$a0,$s2
/*  f096c7c:	0c004c71 */ 	jal	0x131c4
/*  f096c80:	00402825 */ 	move	$a1,$v0
/*  f096c84:	02402025 */ 	move	$a0,$s2
/*  f096c88:	0fc25a61 */ 	jal	0xf096984
/*  f096c8c:	24050002 */ 	li	$a1,0x2
.JF0f096c90:
/*  f096c90:	0fc258f4 */ 	jal	0xf0963d0
/*  f096c94:	02602025 */ 	move	$a0,$s3
/*  f096c98:	0fc5b3cf */ 	jal	0xf16cf3c
/*  f096c9c:	00408025 */ 	move	$s0,$v0
/*  f096ca0:	240a0001 */ 	li	$t2,0x1
/*  f096ca4:	004a5804 */ 	sllv	$t3,$t2,$v0
/*  f096ca8:	01706024 */ 	and	$t4,$t3,$s0
/*  f096cac:	51800003 */ 	beqzl	$t4,.JF0f096cbc
/*  f096cb0:	8eed0000 */ 	lw	$t5,0x0($s7)
/*  f096cb4:	26b50001 */ 	addiu	$s5,$s5,0x1
/*  f096cb8:	8eed0000 */ 	lw	$t5,0x0($s7)
.JF0f096cbc:
/*  f096cbc:	26730001 */ 	addiu	$s3,$s3,0x1
/*  f096cc0:	26940004 */ 	addiu	$s4,$s4,0x4
/*  f096cc4:	01b3082a */ 	slt	$at,$t5,$s3
/*  f096cc8:	1020ffb0 */ 	beqz	$at,.JF0f096b8c
/*  f096ccc:	00000000 */ 	nop
.JF0f096cd0:
/*  f096cd0:	8fbf003c */ 	lw	$ra,0x3c($sp)
.JF0f096cd4:
/*  f096cd4:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f096cd8:	8fb1001c */ 	lw	$s1,0x1c($sp)
/*  f096cdc:	8fb20020 */ 	lw	$s2,0x20($sp)
/*  f096ce0:	8fb30024 */ 	lw	$s3,0x24($sp)
/*  f096ce4:	8fb40028 */ 	lw	$s4,0x28($sp)
/*  f096ce8:	8fb5002c */ 	lw	$s5,0x2c($sp)
/*  f096cec:	8fb60030 */ 	lw	$s6,0x30($sp)
/*  f096cf0:	8fb70034 */ 	lw	$s7,0x34($sp)
/*  f096cf4:	8fbe0038 */ 	lw	$s8,0x38($sp)
/*  f096cf8:	03e00008 */ 	jr	$ra
/*  f096cfc:	27bd0090 */ 	addiu	$sp,$sp,0x90
);
#else
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

				if (objectiveGetDifficultyBits(i) & (1 << lvGetDifficulty())) {
					sprintf(buffer, "%s %d: ", langGet(L_MISC_044), availableindex + 1); // "Objective"

#if VERSION >= VERSION_NTSC_1_0
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
#else
					if (status == OBJECTIVE_COMPLETE) {
						strcat(buffer, langGet(L_MISC_045)); // "Completed"
						hudmsgCreateWithFlags(buffer, HUDMSGTYPE_OBJECTIVECOMPLETE, HUDMSGFLAG_ALLOWDUPES);
					} else if (status == OBJECTIVE_INCOMPLETE) {
						strcat(buffer, langGet(L_MISC_046)); // "Incomplete"
						hudmsgCreateWithFlags(buffer, HUDMSGTYPE_OBJECTIVECOMPLETE, HUDMSGFLAG_ALLOWDUPES);
					} else if (status == OBJECTIVE_FAILED) {
						strcat(buffer, langGet(L_MISC_047)); // "Failed"
						hudmsgCreateWithFlags(buffer, HUDMSGTYPE_OBJECTIVEFAILED, HUDMSGFLAG_ALLOWDUPES);
					}
#endif
				}
			}

			if (objectiveGetDifficultyBits(i) & (1 << lvGetDifficulty())) {
				availableindex++;
			}
		}
	}
}
#endif

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
