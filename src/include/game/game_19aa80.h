#ifndef _IN_GAME_GAME_19AA80_H
#define _IN_GAME_GAME_19AA80_H
#include <ultra64.h>
#include "types.h"

bool ai0176(void);
u32 func0f19ab70(void);
void func0f19afdc(void);
void func0f19b540(void);
u32 func0f19b6f8(void);
u32 func0f19b800(void);
s32 mpLoadConfig(s16 arg0, char *buffer, s32 len);
u32 func0f19bb50(void);
u32 func0f19bb98(void);
u32 func0f19bd4c(void);
u32 func0f19bfa0(void);
void func0f19c1cc(void);
u32 func0f19c288(void);
u32 func0f19c2b0(void);
bool mpIsChallengeCompleteForEndscreen(void);
bool aiMpInitSimulants(void);
void func0f19ab40(void);
bool func0f19af3c(s32 chrnum, s32 challengeindex);
bool mpIsChallengeAvailable(s32 challengeindex);
s32 mpGetNumAvailableChallenges(void);
char *mpChallengeGetName(s32 challengeindex);
void mpSetCurrentChallenge(s32 slotnum);
s32 mpGetCurrentChallengeIndex(void);
s32 mpLoadChallenge(s32 challengeindex, char *buffer, s32 len);
s32 mpGetNthAvailableChallengeSomething(s32 n, char *buffer, s32 len);
s32 mpLoadCurrentChallenge(char *buffer, s32 len);
void func0f19c190(void);
s32 mpRemoveLock(void);
void mpCalculateVar800884b4(char *buffer, s32 len);
void mpResetVar800884b4(void);
bool mpIsVar800884b4NonZero(void);
s32 mpGetNumChallengesAvailable(s32 mpchrnum);
char *mpChallengeGetNameWithArg(s32 arg0, s32 challengeindex);
bool func0f19c3bc(s32 mpchrnum, s32 index, s32 numplayers);
bool mpIsChallengeCompletedByAnyChrWithNumPlayers(s32 index, s32 numplayers);
void mpSetChallengeCompletedByAnyChrWithNumPlayers(s32 index, s32 numplayers, bool completed);
bool mpIsChallengeCompletedByChrWithNumPlayers(s32 mpchrnum, s32 index, s32 numplayers);
void mpSetChallengeCompletedByChrWithNumPlayers(u32 mpchrnum, s32 index, s32 numplayers, bool completed);
void mpConsiderMarkingCurrentChallengeComplete(void);
bool mpIsChallengeComplete(s32 challenge);

#endif
