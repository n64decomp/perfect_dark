#include <ultra64.h>
#include "constants.h"
#include "game/inv.h"
#include "bss.h"
#include "lib/main.h"
#include "data.h"
#include "types.h"

void objectivesReset(void)
{
	s32 i;

	if (g_StageNum < STAGE_TITLE) {
		g_ObjectiveLastIndex = -1;

		for (i = 0; i < ARRAYCOUNT(g_ObjectiveStatuses); i++) {
			g_ObjectiveStatuses[i] = OBJECTIVE_INCOMPLETE;
		}
	}

	g_ObjectiveChecksDisabled = false;

	for (i = 0; i < ARRAYCOUNT(g_Objectives); i++) {
		g_Objectives[i] = NULL;
	}

	g_TagsLinkedList = NULL;
	g_BriefingObjs = NULL;
	g_HolographCriterias = NULL;

	g_ObjectivesDirty = true;
	g_AnyObjectiveFailed = false;
}

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

void objectiveAddHolographCriteria(struct criteria_holograph *criteria)
{
	criteria->next = g_HolographCriterias;
	g_HolographCriterias = criteria;
}
