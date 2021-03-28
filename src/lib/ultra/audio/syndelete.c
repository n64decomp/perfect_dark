#include <ultra64.h>
#include "constants.h"
#include "bss.h"
#include "data.h"
#include "types.h"

void n_alSynDelete(void)
{
	alGlobals->drvr.head = NULL;
}
