#ifndef _IN_LIB_AUDIODMA_H
#define _IN_LIB_AUDIODMA_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

struct admastate;

void admaInit(void);
void *admaNew(struct admastate **state);
void admaBeginFrame(void);
void admaReceiveAll(void);

#endif
