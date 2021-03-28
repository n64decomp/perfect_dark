#include <ultra64.h>
#include "constants.h"
#include "bss.h"
#include "lib/lib_30ce0.h"
#include "lib/lib_39fc0.h"
#include "data.h"
#include "types.h"

ALGlobals *var8005f110 = NULL;
ALGlobals *alGlobals = NULL;

void n_alInit(ALGlobals *g, ALSynConfig *c)
{
	if (!var8005f110) {
		var8005f110 = g;

		if (!alGlobals) {
			alGlobals = var8005f110;
			n_alSynNew(c);
		}
	}
}

void n_alClose(ALGlobals *g)
{
	if (var8005f110) {
		n_alSynDelete();
		var8005f110 = NULL;
		alGlobals = NULL;
	}
}
