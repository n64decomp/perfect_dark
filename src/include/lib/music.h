#ifndef _IN_LIB_MUSIC_H
#define _IN_LIB_MUSIC_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

u32 music00011420(void);
bool musicStopByTrackType(s32 *arg0, u32 arg1);
bool music00011780(s32 *arg0, u32 arg1);
bool musicStopAll(u32 arg0);
bool music000118f4(s32 *arg0, u32 arg1);
void music0001190c(void);
void musicTick(void);

#endif
