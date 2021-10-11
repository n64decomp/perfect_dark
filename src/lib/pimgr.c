#include <ultra64.h>
#include "constants.h"
#include "bss.h"
#include "lib/pimgr.h"
#include "data.h"
#include "types.h"

OSMesg var80099900[64];
OSMesgQueue var80099a00;

void pimgrCreate(void)
{
	osCreatePiManager(150, &var80099a00, var80099900, 64);
}
