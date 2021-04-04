#include <ultra64.h>
#include "constants.h"
#include "bss.h"
#include "lib/lib_30ce0.h"
#include "lib/lib_39fc0.h"
#include "data.h"
#include "types.h"

ALGlobals *n_alGlobals = NULL;
ALGlobals *n_syn = NULL;

void n_alInit(ALGlobals *g, ALSynConfig *c)
{
	if (!n_alGlobals) {
		n_alGlobals = g;

		if (!n_syn) {
			n_syn = n_alGlobals;
			n_alSynNew(c);
		}
	}
}

void n_alClose(ALGlobals *g)
{
	if (n_alGlobals) {
		n_alSynDelete();
		n_alGlobals = NULL;
		n_syn = NULL;
	}
}
