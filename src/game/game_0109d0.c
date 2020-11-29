#include <ultra64.h>
#include "constants.h"
#include "game/data/data_000000.h"
#include "game/data/data_0083d0.h"
#include "game/data/data_00e460.h"
#include "game/data/data_0160b0.h"
#include "game/data/data_01a3a0.h"
#include "game/data/data_020df0.h"
#include "game/data/data_02da90.h"
#include "game/data/inventory.h"
#include "gvars/gvars.h"
#include "lib/main.h"
#include "types.h"

GLOBAL_ASM(
glabel func0f0109d0
/*  f0109d0:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f0109d4:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f0109d8:	0c003a61 */ 	jal	mainGetStageNum
/*  f0109dc:	00000000 */ 	nop
/*  f0109e0:	2841005a */ 	slti	$at,$v0,0x5a
/*  f0109e4:	1020000a */ 	beqz	$at,.L0f010a10
/*  f0109e8:	240effff */ 	addiu	$t6,$zero,-1
/*  f0109ec:	3c018007 */ 	lui	$at,%hi(g_ObjectiveLastIndex)
/*  f0109f0:	3c02800a */ 	lui	$v0,%hi(g_ObjectiveStatuses)
/*  f0109f4:	3c03800a */ 	lui	$v1,%hi(g_TagsLinkedList)
/*  f0109f8:	ac2eae70 */ 	sw	$t6,%lo(g_ObjectiveLastIndex)($at)
/*  f0109fc:	2463d0b0 */ 	addiu	$v1,$v1,%lo(g_TagsLinkedList)
/*  f010a00:	2442d088 */ 	addiu	$v0,$v0,%lo(g_ObjectiveStatuses)
.L0f010a04:
/*  f010a04:	24420004 */ 	addiu	$v0,$v0,0x4
/*  f010a08:	1443fffe */ 	bne	$v0,$v1,.L0f010a04
/*  f010a0c:	ac40fffc */ 	sw	$zero,-0x4($v0)
.L0f010a10:
/*  f010a10:	3c018007 */ 	lui	$at,%hi(g_ObjectiveChecksDisabled)
/*  f010a14:	3c02800a */ 	lui	$v0,%hi(g_Objectives)
/*  f010a18:	3c03800a */ 	lui	$v1,%hi(g_ObjectiveStatuses)
/*  f010a1c:	ac20ae74 */ 	sw	$zero,%lo(g_ObjectiveChecksDisabled)($at)
/*  f010a20:	2463d088 */ 	addiu	$v1,$v1,%lo(g_ObjectiveStatuses)
/*  f010a24:	2442d060 */ 	addiu	$v0,$v0,%lo(g_Objectives)
.L0f010a28:
/*  f010a28:	24420004 */ 	addiu	$v0,$v0,0x4
/*  f010a2c:	1443fffe */ 	bne	$v0,$v1,.L0f010a28
/*  f010a30:	ac40fffc */ 	sw	$zero,-0x4($v0)
/*  f010a34:	3c01800a */ 	lui	$at,%hi(g_TagsLinkedList)
/*  f010a38:	ac20d0b0 */ 	sw	$zero,%lo(g_TagsLinkedList)($at)
/*  f010a3c:	3c01800a */ 	lui	$at,%hi(g_BriefingObjs)
/*  f010a40:	ac20d0b4 */ 	sw	$zero,%lo(g_BriefingObjs)($at)
/*  f010a44:	3c01800a */ 	lui	$at,%hi(g_RoomEnteredCriterias)
/*  f010a48:	ac20d0b8 */ 	sw	$zero,%lo(g_RoomEnteredCriterias)($at)
/*  f010a4c:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f010a50:	3c01800a */ 	lui	$at,%hi(g_MultiroomEnteredCriterias)
/*  f010a54:	ac20d0bc */ 	sw	$zero,%lo(g_MultiroomEnteredCriterias)($at)
/*  f010a58:	3c01800a */ 	lui	$at,%hi(g_HolographCriterias)
/*  f010a5c:	ac20d0c0 */ 	sw	$zero,%lo(g_HolographCriterias)($at)
/*  f010a60:	03e00008 */ 	jr	$ra
/*  f010a64:	27bd0018 */ 	addiu	$sp,$sp,0x18
);

void tagInsert(struct tag *tag)
{
	tag->next = g_TagsLinkedList;
	g_TagsLinkedList = tag;
}

void briefingInsert(struct briefingobj *briefing)
{
	briefing->next = g_BriefingObjs;
	g_BriefingObjs = briefing;
}

void objectiveInsert(struct objective *objective)
{
	g_Objectives[objective->index] = objective;

	if (g_ObjectiveLastIndex < objective->index) {
		g_ObjectiveLastIndex = objective->index;
	}
}

void objectiveAddRoomEnteredCriteria(struct criteria_roomentered *criteria)
{
	criteria->next = g_RoomEnteredCriterias;
	g_RoomEnteredCriterias = criteria;
}

void objectiveAddMultiroomEnteredCriteria(struct criteria_multiroomentered *criteria)
{
	criteria->next = g_MultiroomEnteredCriterias;
	g_MultiroomEnteredCriterias = criteria;
}

void objectiveAddHolographCriteria(struct criteria_holograph *criteria)
{
	criteria->next = g_HolographCriterias;
	g_HolographCriterias = criteria;
}
