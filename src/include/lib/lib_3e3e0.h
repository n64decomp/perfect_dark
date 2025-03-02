#ifndef _IN_LIB_LIB_3E3E0_H
#define _IN_LIB_LIB_3E3E0_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

ALFxRef n_alSynGetFXRef(s16 index);
ALFxRef n_alSynGetOutputLPRef(s16 index);
void n_alSynSetOutputLPParam(struct fx *fx, s16 arg1, void *param);

#endif
