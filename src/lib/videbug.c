#include <ultra64.h>
#include "constants.h"
#include "bss.h"
#include "data.h"
#include "types.h"
#include "lib/videbug.h"

OSMesg g_ViDebugMesgs[8];
OSMesgQueue g_ViDebugMesgQueue;

void videbug_create(void)
{
	// empty
}

void videbug_init(void)
{
	osCreateMesgQueue(&g_ViDebugMesgQueue, g_ViDebugMesgs, ARRAYCOUNT(g_ViDebugMesgs));
}
