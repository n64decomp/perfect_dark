#include <ultra64.h>
#include "constants.h"
#include "game/file.h"
#include "game/lang.h"
#include "bss.h"
#include "lib/memp.h"
#include "data.h"
#include "types.h"

void getitle_reset(void)
{
	var80062410 = 0;
	var8009cc80 = memp_alloc(2 * sizeof(Mtx), MEMPOOL_STAGE);
	var8009cc84 = memp_alloc(2 * sizeof(Mtx), MEMPOOL_STAGE);
	var8009cc88 = memp_alloc(2 * sizeof(Mtx), MEMPOOL_STAGE);
}
