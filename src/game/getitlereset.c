#include <ultra64.h>
#include "constants.h"
#include "game/file.h"
#include "game/lang.h"
#include "bss.h"
#include "lib/memp.h"
#include "data.h"
#include "types.h"

void getitleReset(void)
{
	var80062410 = 0;
	var8009cc80 = mempAlloc(2 * sizeof(Mtx), MEMPOOL_STAGE);
	var8009cc84 = mempAlloc(2 * sizeof(Mtx), MEMPOOL_STAGE);
	var8009cc88 = mempAlloc(2 * sizeof(Mtx), MEMPOOL_STAGE);
}
