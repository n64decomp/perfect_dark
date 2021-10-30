#include <ultra64.h>
#include "constants.h"
#include "bss.h"
#include "data.h"
#include "types.h"
#include "lib/videbug.h"

OSMesg g_ViDebugMesgs[8];
OSMesgQueue g_ViDebugMesgQueue;

void videbugInit(void)
{
	// empty
}

void videbugCreateMesgQueue(void)
{
	osCreateMesgQueue(&g_ViDebugMesgQueue, g_ViDebugMesgs, ARRAYCOUNT(g_ViDebugMesgs));
}
