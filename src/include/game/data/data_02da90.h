#ifndef IN_GAME_DATA_02DA90_H
#define IN_GAME_DATA_02DA90_H
#include <ultra64.h>
#include "game/data/data_020df0.h"

extern struct mptrack g_MpTracks[NUM_MPTRACKS];
extern struct mppreset g_MpPresets[NUM_MPPRESETS];
extern u32 g_TeamColours[MAX_TEAMS];
extern u8 g_NumMpSimulantChrs;
extern struct var80087d14 var80087d14[];
extern u32 g_MpBotCommands[NUM_MPBOTCOMMANDS];
extern u32 var80087e2c;
extern u32 var80087e50;
extern u32 var80087e98;
extern u32 var80087eb0;
extern u32 var80088490;
extern u32 var80088494;
extern u32 var800884a4;
extern u32 g_MpChallengeIndex;
extern u32 var800884b4;
extern struct challenge g_MpChallenges[NUM_CHALLENGES];
extern u32 var800887c4;

#endif
