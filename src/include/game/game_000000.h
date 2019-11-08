#ifndef _IN_GAME_000000_H
#define _IN_GAME_000000_H
#include <ultra64.h>
#include "constants.h"

struct chrdata *chrFindByLiteralId(u8 chrnum);
struct chrdata *chrFindById(struct chrdata *data, u32 chrnum);
struct position *chrGetTargetPosition(struct chrdata *chr);

float chrGetTimer(struct chrdata *chr);

s32 padResolve(struct chrdata *chr, s32 pad_id);

u32 func0f000000(void);
u32 func0f000090(void);
u32 func0f000100(void);
u32 func0f000130(void);
bool func0f04a76c(struct chrdata *chr, float distance);
u32 func0f000840(void);
u32 func0f000850(void);
u32 func0f000860(void);
u32 func0f000870(void);
u32 func0f000880(void);
u32 func0f0008e0(void);
u32 func0f0008f0(void);
u32 func0f000900(void);
u32 func0f000910(void);
u32 func0f00b180(void);
u32 func0f00b190(void);
u32 func0f00b200(void);
u32 func0f00b210(void);
u32 func0f00b320(void);
u32 func0f01a348(void);
u32 func0f01aba8(void);
u32 func0f01b148(void);
u32 func0f01b154(void);
void func0f03af44(struct chrdata *chr, u32 anim_id, float fstartframe, float fendframe, u8 flags, u8 transition, float result);
u32 func0f048f20(struct chrdata *chr, u8 b);
float chrGetDistanceToChr(struct chrdata *chr1, s32 chr2num);
float chrGetDistanceToPad(struct chrdata *chr, s32 pad_id);
float chrGetDistanceToTarget(struct chrdata *chr);
float positionGetDistanceToPosition(struct position *a, struct position *b);

#endif
