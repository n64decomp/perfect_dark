#include <ultra64.h>
#include "constants.h"
#include "game/data/data_000000.h"
#include "game/data/data_0083d0.h"
#include "game/data/data_00e460.h"
#include "game/data/data_0160b0.h"
#include "game/data/data_01a3a0.h"
#include "game/data/data_020df0.h"
#include "game/data/data_02da90.h"
#include "gvars/gvars.h"
#include "lib/lib_317f0.h"
#include "types.h"

void currentPlayerSetMoveModeCutscene(void)
{
	s32 i;
	s32 j;

	g_Vars.currentplayer->bondmovemode = MOVEMODE_CUTSCENE;

	for (i = 0; i < PLAYERCOUNT(); i++) {
		g_Vars.players[i]->joybutinhibit = 0xffffffff;

		// @bug? Should this be < 2?
		for (j = 0; j < 1; j++) {
			struct player638 *thing = &g_Vars.players[i]->unk0638[j];

			if (thing->unk0d84 && func000337f0(thing->unk0d84)) {
				func00033b24(thing->unk0d84);
				thing->unk0d84 = NULL;
			}

			thing->unk063c = 0;
		}
	}
}

GLOBAL_ASM(
glabel func0f0c37c0
/*  f0c37c0:	03e00008 */ 	jr	$ra
/*  f0c37c4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c37c8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c37cc:	00000000 */ 	sll	$zero,$zero,0x0
);
