#ifndef _ASM_HELPER_H
#define _ASM_HELPER_H
#include <R4300.h>
#include <sys/regdef.h>
#include <sys/asm.h>
#include <rcp.h>

#define STAY1(stmnt) .set noreorder; stmnt; .set reorder;
#define STAY2(stmnt, arg1) .set noreorder; stmnt, arg1; .set reorder;
#define STAY3(stmnt, arg1, arg2) .set noreorder; stmnt, arg1, arg2; .set reorder;
#define NOP .set noreorder; nop; .set reorder;
#define CACHE(op, reg) .set noreorder; cache op, reg; .set reorder;
#endif
