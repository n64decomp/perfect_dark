#ifndef _IN_LIB_MUSIC_H
#define _IN_LIB_MUSIC_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

s32 musicHandlePlayEvent(struct musicevent *event, s32 result);
s32 musicHandleStopEvent(struct musicevent *event, s32 result);
s32 musicHandleFadeEvent(struct musicevent *event, s32 result);
s32 musicHandleStopAllEvent(s32 result);
s32 musicHandleEvent5(struct musicevent *event, s32 result);
void musicTickEvents(void);
void musicTick(void);

#endif
