#ifndef _IN_VIDEO_H
#define _IN_VIDEO_H

#include <PR/ultratypes.h>
#include <PR/gbi.h>

s32 videoInit(void);
void videoStartFrame(void);
void videoSubmitCommands(Gfx *cmds);
void videoClearScreen(void);
void videoEndFrame(void);

void *videoGetWindowHandle(void);

void videoUpdateNativeResolution(const int w, const int h);

s32 videoGetWidth(void);
s32 videoGetHeight(void);
f32 videoGetAspect(void);

void videoResetTextureCache(void);

#endif
