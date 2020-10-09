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
/*  f010a3c:	3c01800a */ 	lui	$at,%hi(var8009d0b4)
/*  f010a40:	ac20d0b4 */ 	sw	$zero,%lo(var8009d0b4)($at)
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

GLOBAL_ASM(
glabel func0f010a68
/*  f010a68:	3c02800a */ 	lui	$v0,%hi(g_TagsLinkedList)
/*  f010a6c:	2442d0b0 */ 	addiu	$v0,$v0,%lo(g_TagsLinkedList)
/*  f010a70:	8c4e0000 */ 	lw	$t6,0x0($v0)
/*  f010a74:	ac8e0008 */ 	sw	$t6,0x8($a0)
/*  f010a78:	03e00008 */ 	jr	$ra
/*  f010a7c:	ac440000 */ 	sw	$a0,0x0($v0)
);

GLOBAL_ASM(
glabel func0f010a80
/*  f010a80:	3c02800a */ 	lui	$v0,%hi(var8009d0b4)
/*  f010a84:	2442d0b4 */ 	addiu	$v0,$v0,%lo(var8009d0b4)
/*  f010a88:	8c4e0000 */ 	lw	$t6,0x0($v0)
/*  f010a8c:	ac8e000c */ 	sw	$t6,0xc($a0)
/*  f010a90:	03e00008 */ 	jr	$ra
/*  f010a94:	ac440000 */ 	sw	$a0,0x0($v0)
);

GLOBAL_ASM(
glabel func0f010a98
/*  f010a98:	8c8e0004 */ 	lw	$t6,0x4($a0)
/*  f010a9c:	3c01800a */ 	lui	$at,%hi(g_Objectives)
/*  f010aa0:	3c038007 */ 	lui	$v1,%hi(g_ObjectiveLastIndex)
/*  f010aa4:	000e7880 */ 	sll	$t7,$t6,0x2
/*  f010aa8:	002f0821 */ 	addu	$at,$at,$t7
/*  f010aac:	ac24d060 */ 	sw	$a0,%lo(g_Objectives)($at)
/*  f010ab0:	2463ae70 */ 	addiu	$v1,$v1,%lo(g_ObjectiveLastIndex)
/*  f010ab4:	8c780000 */ 	lw	$t8,0x0($v1)
/*  f010ab8:	8c820004 */ 	lw	$v0,0x4($a0)
/*  f010abc:	0302082a */ 	slt	$at,$t8,$v0
/*  f010ac0:	10200002 */ 	beqz	$at,.L0f010acc
/*  f010ac4:	00000000 */ 	nop
/*  f010ac8:	ac620000 */ 	sw	$v0,0x0($v1)
.L0f010acc:
/*  f010acc:	03e00008 */ 	jr	$ra
/*  f010ad0:	00000000 */ 	nop
);

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
