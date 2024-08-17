#include <ultra64.h>
#include "constants.h"
#include "game/chr.h"
#include "game/prop.h"
#include "game/propobj.h"
#include "bss.h"
#include "data.h"
#include "types.h"

void props_stop(void)
{
	alarm_deactivate();
	gas_stop_audio();
}
