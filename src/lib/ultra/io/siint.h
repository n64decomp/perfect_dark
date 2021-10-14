#ifndef _SIINT_H
#define _SIINT_H
#include <os_internal.h>
#include <rcp.h>

void __osSiGetAccess(void);
void __osSiRelAccess(void);
int __osSiDeviceBusy(void);
void __osSiCreateAccessQueue(void);
#endif
