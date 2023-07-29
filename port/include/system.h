#ifndef _IN_SYSTEM_H
#define _IN_SYSTEM_H

#include <PR/ultratypes.h>

u64 sysGetTicks(void);
u64 sysGetTicksPerSecond(void);

void sysFatalError(const char *fmt, ...) __attribute__((noreturn));

#endif
