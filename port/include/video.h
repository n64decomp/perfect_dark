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

void videoUpdateNativeResolution(s32 w, s32 h);
s32 videoGetNativeWidth(void);
s32 videoGetNativeHeight(void);

s32 videoGetWidth(void);
s32 videoGetHeight(void);
f32 videoGetAspect(void);
f32 videoGetPlayerFovY(void);

s32 videoCreateFramebuffer(u32 w, u32 h);
void videoSetFramebuffer(s32 target);
void videoResetFramebuffer(void);
void videoCopyFramebuffer(s32 dst, s32 src, s32 left, s32 top);

void videoResetTextureCache(void);

#endif
