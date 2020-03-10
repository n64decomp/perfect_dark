#ifndef _IN_LIB_LIB_03EE0_H
#define _IN_LIB_LIB_03EE0_H
#include <ultra64.h>
#include "types.h"

void osCreateThread(OSThread *thread, OSId id, void (*entry)(void *),
		void *arg, void *sp, OSPri pri);

#endif
