#include <ultra64.h>
#include "constants.h"
#include "bss.h"
#include "lib/mtx.h"
#include "data.h"
#include "types.h"

signed short coss(unsigned short x)
{
	return sins ((unsigned short) (x + 0x4000));
}
