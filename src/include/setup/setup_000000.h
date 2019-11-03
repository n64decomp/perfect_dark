#ifndef IN_SETUP_000000_H
#define IN_SETUP_000000_H
#include <ultra64.h>
#include "types.h"

extern s32 levelnum;
extern u64 rand_seed;

extern struct chrdata *g_Chrs; // pointer to first element of chrs array
extern u32 g_NumChrs;
extern u32 var8005ce60;
extern u32 var8005ce64;
extern u32 var8005ce68;
extern u32 var8005ce6c;
extern u32 var8005ce70;
extern u32 var80065be0;
extern u32 var80067aa0;
extern u32 var80067ae8;
extern u32 var800656c0;
extern u32 var80067a10;
extern u32 var80067a58;
extern u32 var800663d8;
extern u32 var80067b30;
extern u32 var80067b78;
extern u32 g_CountdownTimerVisible;
extern bool g_CountdownTimerRunning;
extern float g_CountdownTimerValue;
extern u32 g_StageFlags;

extern struct audiodefinition audiodefinitions[];
extern struct audioconfig audioconfigs[];

extern bool (*g_CommandPointers[])(void);
extern u16 g_CommandLengths[];

extern struct coord var80068fec;

extern u32 g_TintedGlassEnabled;
extern s32 g_AlarmActive;

#endif
