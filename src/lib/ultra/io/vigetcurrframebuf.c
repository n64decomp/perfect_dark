#include <ultra64.h>
#include "game/data/data_000000.h"

void *osViGetCurrentFramebuffer(void)
{
    register u32 saveMask;
    void *framep;

    saveMask = __osDisableInt();

    framep = __osViCurr->framep;

    __osRestoreInt(saveMask);

    return framep;
}
