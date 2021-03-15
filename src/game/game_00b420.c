#include <ultra64.h>
#include "constants.h"
#include "game/file.h"
#include "game/lang.h"
#include "bss.h"
#include "lib/memory.h"
#include "data.h"
#include "types.h"

void func0f00b420(void)
{
	var80062410 = 0;
	var8009cc80 = malloc(2 * sizeof(Mtx), MEMPOOL_STAGE);
	var8009cc84 = malloc(2 * sizeof(Mtx), MEMPOOL_STAGE);
	var8009cc88 = malloc(2 * sizeof(Mtx), MEMPOOL_STAGE);
}
