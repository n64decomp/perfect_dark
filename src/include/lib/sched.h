#ifndef _IN_BOOT_SCHED_H
#define _IN_BOOT_SCHED_H
#include <ultra64.h>
#include <sched.h>
#include "types.h"

void sched_set_crash_enable2(s32 enable);
void sched_submit_task(OSSched *sc, OSScTask *t);
void __scHandleRetrace(OSSched *sc);
void __scHandleRSP(OSSched *sc);
void __scHandleRDP(OSSched *sc);
void __scHandleTasks(OSSched *sc);
void __scAppendList(OSSched *sc, OSScTask *t);
void __scExec(OSSched *sc, OSScTask *sp, OSScTask *dp);
void __scMain(void *arg);
void __scYield(OSSched *sc);
void sched_init_artifacts(void);
void sched_reset_artifacts(void);
struct artifact *sched_get_write_artifacts(void);
struct artifact *sched_get_front_artifacts(void);
void sched_increment_write_artifacts(void);
void sched_increment_front_artifacts(void);
void sched_update_pending_artifacts(void);
void sched_consider_screenshot(void);
void sched_set_crashed_unexpectedly(bool enable);

#endif
