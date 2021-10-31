#ifndef _IN_LIB_MUSIC_H
#define _IN_LIB_MUSIC_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

s32 musicHandleStartEvent(struct musicevent *event, u32 arg1);
s32 musicHandleStopEvent(struct musicevent *event, u32 arg1);
s32 musicHandleFadeEvent(struct musicevent *event, u32 arg1);
s32 musicHandleStopAllEvent(u32 arg0);
s32 musicHandleEvent5(struct musicevent *event, u32 arg1);
void musicTickEvents(void);
void musicTick(void);

#endif
