#ifndef _IN_GAME_GAME_19AA80_H
#define _IN_GAME_GAME_19AA80_H
#include <ultra64.h>
#include "types.h"

extern u32 g_MpChallengeIndex;
extern struct mpconfigfull *g_MpCurrentChallengeConfig;
extern struct challenge g_MpChallenges[NUM_CHALLENGES];

bool ai0176(void);
u32 func0f19ab70(void);
void func0f19afdc(void);
void func0f19b540(void);
char *mpGetChallengeNameBySlot(s32 slot);
bool mpIsChallengeCompletedByAnyChrWithNumPlayersBySlot(s32 slot, s32 numplayers);
struct mpconfigfull *mpLoadConfig(s32 confignum, u8 *buffer, s32 len);
s32 func0f19bb50(s32 unlockvalue, u8 *array, s32 index, s32 len);
s32 func0f19bb98(struct mpsetup *mpsetup, u8 *array, s32 len);
u32 func0f19bd4c(void);
void func0f19bfa0(void);
void func0f19c1cc(void);
char *mpGetCurrentChallengeDescription(void);
char *mpconfigGetDescription(struct mpconfigfull *mpconfig);
bool mpIsChallengeCompleteForEndscreen(void);
bool aiMpInitSimulants(void);
void func0f19ab40(void);
bool func0f19af3c(s32 chrnum, s32 challengeindex);
bool mpIsChallengeAvailable(s32 challengeindex);
s32 mpGetNumAvailableChallenges(void);
char *mpChallengeGetName(s32 challengeindex);
void mpSetCurrentChallenge(s32 slotnum);
s32 mpGetCurrentChallengeIndex(void);
struct mpconfigfull *mpLoadChallenge(s32 challengeindex, u8 *buffer, s32 len);
struct mpconfigfull *mpGetNthAvailableChallengeSomething(s32 n, u8 *buffer, s32 len);
struct mpconfigfull *mpLoadCurrentChallenge(u8 *buffer, s32 len);
void func0f19c190(void);
s32 mpRemoveLock(void);
void mpLoadAndStoreCurrentChallenge(u8 *buffer, s32 len);
void mpClearCurrentChallenge(void);
bool mpIsChallengeLoaded(void);
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
