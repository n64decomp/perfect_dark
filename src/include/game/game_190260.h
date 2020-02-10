#ifndef GAME_GAME_190260
#define GAME_GAME_190260

u32 func0f190260(void);
void mpChrReset(struct chrdata *chr, u8 full);
u32 func0f1905f0(void);
u32 func0f190708(void);
u32 func0f190774(void);
u32 func0f190784(void);
u32 func0f190be4(void);
u32 func0f19124c(void);
u32 func0f1913f8(void);
u32 func0f191448(void);
u32 func0f191638(void);
u32 func0f1918d0(void);
u32 func0f191fa4(void);
u32 func0f1921f8(void);
u32 func0f192628(void);
u32 func0f19277c(void);
u32 func0f19294c(void);
u32 func0f192a48(void);
u32 func0f192a74(void);
u32 func0f192d64(void);
u32 func0f192dc0(void);
u32 func0f192e90(void);
u32 func0f19369c(void);
s32 func0f1937a4(struct chrdata *chr, s32 arg1);
u32 func0f194990(void);
u32 func0f194b40(void);
s32 mpObjIsSafe(struct defaultobj *obj);
u32 func0f1915b4(struct chrdata *chr);
u8 func0f191600(struct chrdata *chr);
char *mpGetBotCommandName(s32 command);
void func0f192438(struct chrdata *chr, struct prop *prop);
void func0f192474(struct chrdata *chr, struct prop *prop);
void func0f1924ac(struct chrdata *chr, struct prop *prop);
void func0f1924e8(struct chrdata *chr, struct coord *pos, s16 *room, f32 arg3);
void func0f19257c(struct chrdata *chr, struct coord *pos, s16 *room, f32 arg3);
void func0f192610(struct chrdata *chr, s32 arg1);
bool mpIsChrFollowedByChr(struct chrdata *leader, struct chrdata *follower);
s32 func0f193530(struct chrdata *chr, f32 arg1);
bool func0f194670(struct chrdata *chr);
s32 func0f194694(struct chrdata *chr);
s32 func0f1946b4(struct chrdata *chr);
s32 mpGetNumPlayerTeammates(struct chrdata *chr);
s32 func0f194724(struct chrdata *self, s32 arg1, bool includeself);
s32 scenarioCtcIsChrsTokenHeld(struct chrdata *chr);
bool func0f19489c(struct chrdata *chr);
s32 mpGetNumTeammatesInRoomDoingSomething(struct chrdata *bot);
void func0f197544(struct chrdata *chr);

#endif
