#include <ultra64.h>
#include "constants.h"
#include "game/data/data_000000.h"
#include "game/data/data_0083d0.h"
#include "game/data/data_00e460.h"
#include "game/data/data_0160b0.h"
#include "game/data/data_01a3a0.h"
#include "game/data/data_020df0.h"
#include "game/data/data_02da90.h"
#include "game/game_00b320.h"
#include "game/game_00b820.h"
#include "game/title.h"
#include "gvars/gvars.h"
#include "lib/lib_121e0.h"
#include "types.h"

void func0f00b480(void)
{
	g_TitleMode = -1;
	var800624d4 = 0;
	var800624d8 = 0;
	var800624dc = 0;
	g_TitleDelayedTimer = 2;
	g_TitleDelayedMode = -1;
	var800624f4 = 1;

	if (var800624f0) {
		g_TitleNextMode = TITLEMODE_SKIP;
	}

	var8009cca0 = malloc(0x47800, 4);

	func0f00b420();
}

void func0f00b510(void)
{
	s32 i;

	var80062968 = 1;
	var8006296c = 0;
	var80062970 = 0;
	var80062974 = 0;
	var80062978 = 0;
	var8006297c = 0;
	g_NextChrId = 5000;
	g_ChrsA = NULL;
	g_NumChrsA = 0;

	var80062a8c = malloc(sizeof(struct var80062a8c) * 20, 4);

	for (i = 0; i < 20; i++) {
		var80062a8c[i].prop = NULL;
	}

	var80062a90 = 0;
	g_NumChrsC = 0;
	g_ChrnumsC = NULL;
	g_ChrIndexesC = NULL;
	var80062960 = malloc(0x1470, 4);

	for (i = 0; i < 20; i++) {
		// @bug? Should the ALIGN64 should surely be applied before malloc...?
		// Not a bug if only 0x200 bytes are being used
		var8009ccc0[i] = (void *)ALIGN64(malloc(0x240, 4));
	}

	resetSomeStageThings();
}

void func0f00b62c(s32 numchrs)
{
	s32 i;

	g_NumChrsA = PLAYERCOUNT() + numchrs + 10;
	g_ChrsA = malloc(ALIGN16(g_NumChrsA * sizeof(struct chrdata)), 4);

	for (i = 0; i < g_NumChrsA; i++) {
		g_ChrsA[i].chrnum = -1;
		g_ChrsA[i].model = NULL;
		g_ChrsA[i].prop = NULL;
	}

	g_NumChrsC = 0;
	g_ChrnumsC = malloc(ALIGN16(g_NumChrsA * 2), 4);
	g_ChrIndexesC = malloc(ALIGN16(g_NumChrsA * 2), 4);

	for (i = 0; i < g_NumChrsA; i++) {
		g_ChrnumsC[i] = -1;
		g_ChrIndexesC[i] = -1;
	}
}
