#ifndef _IN_LIB_AUDIODMA_H
#define _IN_LIB_AUDIODMA_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

struct admastate;

void adma_init(void);
void *adma_new(struct admastate **state);
void adma_begin_frame(void);
void adma_receive_all(void);

#endif
