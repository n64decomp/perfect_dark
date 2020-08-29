#ifndef IN_GAME_MUSIC_H
#define IN_GAME_MUSIC_H
#include <ultra64.h>
#include "types.h"

u16 musicGetVolume(void);
void musicSetVolume(u16 volume);
bool func0f16d0a8(s32 tracktype, s32 arg1);
s32 func0f16d124(s32 tracktype);
void musicStart(u32 tracktype, u32 tracknum, f32 arg2, u16 volume);
void musicEnd(s32 tracktype);
void func0f16d2ac(s32 tracktype, f32 arg1, s32 arg2);
void func0f16d324(void);
void func0f16d3d0(void);
void func0f16d430(void);
void func0f16d44c(void);
void musicStartPrimary(f32 arg0);
void musicStartAmbient(f32 arg0);
bool musicIsAnyPlayerInAmbientRoom(void);
void musicStartX(f32 arg0);
void musicStartMenu2(s32 tracknum);
void musicSetStageAndStartMusic(s32 stagenum);
void musicSetStage(s32 stagenum);
void func0f16d9fc(void);
void func0f16da2c(void);
void func0f16daa4(void);
void musicStartForMenu(void);
void func0f16db3c(void);
void musicStartSoloDeath(void);
void musicStartMpDeath(f32 arg0);
void func0f16dd14(void);
void func0f16ddb0(void);
void musicPlayTrackIsolated(s32 tracknum);
void musicPlayDefaultTracks(void);
void musicStartTemporaryPrimary(s32 tracknum);
void musicStartCutscene(s32 tracknum);
void musicEndCutscene(void);
void musicStartTemporary(s32 tracknum);
void musicEndAmbient(void);
void musicSetXReason(s32 index, u32 arg1, u32 duration);
void musicUnsetXReason(s32 reason);
void func0f16e138(void);

#endif
