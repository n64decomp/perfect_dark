#ifndef _IN_GAME_CHALLENGE_H
#define _IN_GAME_CHALLENGE_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

extern u32 g_MpChallengeIndex;
extern struct mpconfigfull *g_MpCurrentChallengeConfig;
extern struct challenge g_MpChallenges[NUM_CHALLENGES];

void challengesInit(void);

void challengeDetermineUnlockedFeatures(void);
void challengePerformSanityChecks(void);
char *challengeGetNameBySlot(s32 slot);
bool challengeIsCompletedByAnyChrWithNumPlayersBySlot(s32 slot, s32 numplayers);
struct mpconfigfull *challengeLoadConfig(s32 confignum, u8 *buffer, s32 len);
s32 challengeForceUnlockFeature(s32 featurenum, u8 *array, s32 tail, s32 len);
s32 challengeForceUnlockSetupFeatures(struct mpsetup *mpsetup, u8 *array, s32 len);
void challengeForceUnlockConfigFeatures(struct mpconfig *config, u8 *array, s32 len, s32 challengeindex);
void challengeForceUnlockBotFeatures(void);
void challengeApply(void);
char *challengeGetCurrentDescription(void);
char *challengeGetConfigDescription(struct mpconfigfull *mpconfig);
bool challengeIsCompleteForEndscreen(void);
u8 *aiMpInitSimulants(u8 *cmd);
void vmPrintStatsIfEnabled(void);
bool ChallengeIsAvailableToPlayer(s32 chrnum, s32 challengeindex);
bool challengeIsAvailableToAnyPlayer(s32 challengeindex);
s32 challengeGetNumAvailable(void);
char *challengeGetName(s32 challengeindex);
void challengeSetCurrentBySlot(s32 slotnum);
s32 challengeGetCurrent(void);
struct mpconfigfull *challengeLoad(s32 challengeindex, u8 *buffer, s32 len);
struct mpconfigfull *challengeLoadBySlot(s32 n, u8 *buffer, s32 len);
struct mpconfigfull *challengeLoadCurrent(u8 *buffer, s32 len);
void challengeRemoveForceUnlocks(void);
s32 challengeRemovePlayerLock(void);
void challengeLoadAndStoreCurrent(u8 *buffer, s32 len);
void challengeUnsetCurrent(void);
bool challengeIsLoaded(void);
s32 challengeGetAutoFocusedIndex(s32 mpchrnum);
char *xhallengeGetName(s32 playernum, s32 challengeindex);
bool challengeIsCompletedByPlayerWithNumPlayers2(s32 mpchrnum, s32 index, s32 numplayers);
bool challengeIsCompletedByAnyPlayerWithNumPlayers(s32 index, s32 numplayers);
void challengeSetCompletedByAnyPlayerWithNumPlayers(s32 index, s32 numplayers, bool completed);
bool challengeIsCompletedByPlayerWithNumPlayers(s32 mpchrnum, s32 index, s32 numplayers);
void challengeSetCompletedByPlayerWithNumPlayers(u32 mpchrnum, s32 index, s32 numplayers, bool completed);
void challengeConsiderMarkingComplete(void);
bool challengeIsFeatureUnlocked(s32 feature);

#endif
