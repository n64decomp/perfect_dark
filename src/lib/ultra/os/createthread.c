#include <os_internal.h>
#include <R4300.h>
#include "osint.h"

void __osCleanupThread(void);

void osCreateThread(OSThread *t, OSId id, void (*entry)(void *), void *arg, void *sp, OSPri p)
{
	register u32 saveMask;

	t->id = id;
	t->priority = p;
	t->next = NULL;
	t->queue = NULL;
	t->context.pc = (u32) entry;
	t->context.a0 = (u64) arg;
	t->context.sp = (u64) sp - 16;
	t->context.ra = (u64) __osCleanupThread;
	t->context.sr = SR_FR | SR_IMASK | SR_EXL | SR_IE;
	t->context.rcp = (OS_IM_ALL & RCP_IMASK) >> RCP_IMASKSHIFT;
	t->context.fpcsr = (u32) (FPCSR_FS | FPCSR_EV);
	t->fp = 0;
	t->state = OS_STATE_STOPPED;
	t->flags = 0;

	saveMask = __osDisableInt();

	t->tlnext = __osActiveQueue;
	__osActiveQueue = t;

	__osRestoreInt(saveMask);
}
