#ifndef _IN_LIB_RMON_H
#define _IN_LIB_RMON_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

void rmonproc();
bool rmonIsDisabled(void);
void rmonPrint(const char *format, ...);

#endif
