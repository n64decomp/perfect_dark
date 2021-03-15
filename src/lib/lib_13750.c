#include <ultra64.h>
#include "constants.h"
#include "bss.h"
#include "lib/lib_13750.h"
#include "data.h"
#include "types.h"

OSMesg var80099a20[8];
OSMesgQueue var80099a40;

void func00013750(void)
{
	// empty
}

void func00013758(void)
{
	osCreateMesgQueue(&var80099a40, var80099a20, 8);
}
