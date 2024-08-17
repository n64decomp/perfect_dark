#ifndef _IN_LIB_AUDIOMGR_H
#define _IN_LIB_AUDIOMGR_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

void amgr_init(void);

#if VERSION >= VERSION_PAL_BETA
void amgr_create(ALSynConfig *config, u32 *settings);
#else
void amgr_create(ALSynConfig *config);
#endif

void amgr_start_thread(void);
OSMesgQueue *amgr_get_frame_mesg_queue(void);
void amgr_stop_thread(void);

#endif
