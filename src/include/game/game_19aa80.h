#ifndef _IN_GAME_GAME_19AA80_H
#define _IN_GAME_GAME_19AA80_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

extern u32 g_MpChallengeIndex;
extern struct mpconfigfull *g_MpCurrentChallengeConfig;
extern struct challenge g_MpChallenges[NUM_CHALLENGES];

bool ai0176(void);
u32 func0f19ab70(void);
void mpDetermineUnlockedFeatures(void);
void mpPerformSanityChecks(void);
char *mpGetChallengeNameBySlot(s32 slot);
bool mpIsChallengeCompletedByAnyChrWithNumPlayersBySlot(s32 slot, s32 numplayers);
struct mpconfigfull *mpLoadConfig(s32 confignum, u8 *buffer, s32 len);
s32 mpForceUnlockFeature(s32 featurenum, u8 *array, s32 tail, s32 len);
s32 mpForceUnlockSetupFeatures(struct mpsetup *mpsetup, u8 *array, s32 len);
void mpForceUnlockConfigFeatures(struct mpconfig *config, u8 *array, s32 len, s32 challengeindex);
void mpForceUnlockSimulantFeatures(void);
void func0f19c1cc(void);
char *mpGetCurrentChallengeDescription(void);
char *mpconfigGetDescription(struct mpconfigfull *mpconfig);
bool mpIsChallengeCompleteForEndscreen(void);
bool aiMpInitSimulants(void);
void func0f19ab40(void);
bool mpIsChallengeAvailableToPlayer(s32 chrnum, s32 challengeindex);
bool mpIsChallengeAvailableToAnyPlayer(s32 challengeindex);
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
s32 mpGetAutoFocusedChallengeIndex(s32 mpchrnum);
char *mpChallengeGetNameWithArg(s32 playernum, s32 challengeindex);
bool mpIsChallengeCompletedByPlayerWithNumPlayers2(s32 mpchrnum, s32 index, s32 numplayers);
bool mpIsChallengeCompletedByAnyPlayerWithNumPlayers(s32 index, s32 numplayers);
void mpSetChallengeCompletedByAnyPlayerWithNumPlayers(s32 index, s32 numplayers, bool completed);
bool mpIsChallengeCompletedByPlayerWithNumPlayers(s32 mpchrnum, s32 index, s32 numplayers);
void mpSetChallengeCompletedByPlayerWithNumPlayers(u32 mpchrnum, s32 index, s32 numplayers, bool completed);
void mpConsiderMarkingCurrentChallengeComplete(void);
bool mpIsFeatureUnlocked(s32 feature);

#endif
