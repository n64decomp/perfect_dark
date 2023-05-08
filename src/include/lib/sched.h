#ifndef _IN_BOOT_SCHED_H
#define _IN_BOOT_SCHED_H
#include <ultra64.h>
#include <sched.h>

void schedSubmitAudTask(OSSched *sc, OSScTask *t);
void schedSubmitGfxTask(OSSched *sc, OSScTask *t);
void schedInitArtifacts(void);
void schedResetArtifacts(void);
void schedUpdatePendingArtifacts(void);

#endif
