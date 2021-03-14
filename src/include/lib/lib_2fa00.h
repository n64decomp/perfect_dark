#ifndef _IN_LIB_LIB_2FA00_H
#define _IN_LIB_LIB_2FA00_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

void rmonproc();
bool rmonIsDisabled(void);
void crashPrint(char *format, ...);

#endif
