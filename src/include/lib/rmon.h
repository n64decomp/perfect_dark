#ifndef _IN_LIB_RMON_H
#define _IN_LIB_RMON_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

void rmonproc();
void rmon0002fa30(u32 *arg0, s32 arg1);
void rmon0002fa38(s32 arg0);
void rmon0002fa40(void);
bool rmon_is_disabled(void);
void rmon_printf(const char *format, ...);

#endif
