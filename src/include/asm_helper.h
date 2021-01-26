#ifndef _ASM_HELPER_H
#define _ASM_HELPER_H
#include "PR/R4300.h"
#include "PR/sys/regdef.h"
#include "PR/sys/asm.h"
#include "PR/rcp.h"

#define STAY1(stmnt) .set noreorder; stmnt; .set reorder;
#define STAY2(stmnt, arg1) .set noreorder; stmnt, arg1; .set reorder;
#define STAY3(stmnt, arg1, arg2) .set noreorder; stmnt, arg1, arg2; .set reorder;
#define NOP .set noreorder; nop; .set reorder;
#define CACHE(op, reg) .set noreorder; cache op, reg; .set reorder;
#endif
