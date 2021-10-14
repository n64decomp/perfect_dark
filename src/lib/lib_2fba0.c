#include <ultra64.h>
#include "constants.h"
#include "bss.h"
#include "lib/lib_39fc0.h"
#include "data.h"
#include "types.h"

N_ALGlobals *n_alGlobals = NULL;
N_ALSynth *n_syn = NULL;

void n_alInit(N_ALGlobals *g, ALSynConfig *c)
{
	if (!n_alGlobals) {
		n_alGlobals = g;

		if (!n_syn) {
			n_syn = &n_alGlobals->drvr;
			n_alSynNew(c);
		}
	}
}

void n_alClose(N_ALGlobals *g)
{
	if (n_alGlobals) {
		n_alSynDelete();
		n_alGlobals = NULL;
		n_syn = NULL;
	}
}
