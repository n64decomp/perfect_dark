#ifndef _IN_LIB_OSC_H
#define _IN_LIB_OSC_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

f32 _depth2Cents(u8 arg0);
void osc_build_linkedlist(s32 arg0, s32 arg1);
void osc_set_handlers(ALSeqpConfig *config);

#endif
