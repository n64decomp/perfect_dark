#include <ultra64.h>
#include "constants.h"
#include "game/inv.h"
#include "bss.h"
#include "lib/main.h"
#include "data.h"
#include "types.h"

void objectives_reset(void)
{
	s32 i;

	if (main_get_stage_num() < STAGE_TITLE) {
		g_ObjectiveLastIndex = -1;

		for (i = 0; i < ARRAYCOUNT(g_ObjectiveStatuses); i++) {
			g_ObjectiveStatuses[i] = 0;
		}
	}

	g_ObjectiveChecksDisabled = false;

	for (i = 0; i < ARRAYCOUNT(g_Objectives); i++) {
		g_Objectives[i] = NULL;
	}

	g_TagsLinkedList = NULL;
	g_BriefingObjs = NULL;
	g_RoomEnteredCriterias = NULL;
	g_ThrowInRoomCriterias = NULL;
	g_HolographCriterias = NULL;
}

void tag_insert(struct tag *tag)
{
	tag->next = g_TagsLinkedList;
	g_TagsLinkedList = tag;
}

void briefing_insert(struct briefingobj *briefing)
{
	briefing->next = g_BriefingObjs;
	g_BriefingObjs = briefing;
}

void objective_insert(struct objective *objective)
{
	g_Objectives[objective->index] = objective;

	if (g_ObjectiveLastIndex < objective->index) {
		g_ObjectiveLastIndex = objective->index;
	}
}

void objective_add_room_entered_criteria(struct criteria_roomentered *criteria)
{
	criteria->next = g_RoomEnteredCriterias;
	g_RoomEnteredCriterias = criteria;
}

void objective_add_throw_in_room_criteria(struct criteria_throwinroom *criteria)
{
	criteria->next = g_ThrowInRoomCriterias;
	g_ThrowInRoomCriterias = criteria;
}

void objective_add_holograph_criteria(struct criteria_holograph *criteria)
{
	criteria->next = g_HolographCriterias;
	g_HolographCriterias = criteria;
}
