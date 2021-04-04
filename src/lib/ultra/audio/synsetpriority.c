#include <ultra64.h>
#include "constants.h"
#include "bss.h"
#include "lib/lib_37b00.h"
#include "lib/lib_3a100.h"
#include "data.h"
#include "types.h"

void n_alSynSetPriority(ALVoice *voice, s16 priority)
{
	voice->priority = priority;
}
