#include <ultra64.h>
#include "constants.h"
#include "bss.h"
#include "lib/pimgr.h"
#include "data.h"
#include "types.h"

OSMesg var80099900[64];
OSMesgQueue g_PimgrMesgQueue;

void pimgrCreate(void)
{
	osCreatePiManager(150, &g_PimgrMesgQueue, var80099900, 64);
}
