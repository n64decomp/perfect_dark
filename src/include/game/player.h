#ifndef _IN_GAME_PLAYER_H
#define _IN_GAME_PLAYER_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

extern struct vimode g_ViModes[];

f32 playerChooseSpawnLocation(f32 chrradius, struct coord *dstpos, s16 *dstrooms, struct prop *prop, s16 *spawnpads, s32 numspawnpads);
f32 playerChooseGeneralSpawnLocation(f32 chrradius, struct coord *pos, s16 *rooms, struct prop *prop);
void playerStartNewLife(void);
void playerLoadDefaults(void);
void playerSpawn(void);
void playerResetBond(struct playerbond *pb, struct coord *pos);
void playerChooseBodyAndHead(s32 *bodynum, s32 *headnum, s32 *arg2);
void playerRemoveChrBody(void);
void playerStartCutscene(s16 anim_id);
void playerReorientForCutsceneStop(u32 arg0);
f32 playerGetCutsceneBlurFrac(void);
void playerTweenFovY(f32 targetfovy);
void playerUpdateZoom(void);
void playerTickPauseMenu(void);
void playerPause(s32 root);
void playerUnpause(void);
Gfx *playerDrawFade(Gfx *gdl, u32 r, u32 g, u32 b, f32 frac);
void playerDisplayHealth(void);
void playerDisplayDamage(void);
Gfx *playerRenderHealthBar(Gfx *gdl);
void playerSurroundWithExplosions(s32 arg0);
void playerResetLoResIf4Mb(void);
bool playerHasSharedViewport(void);
f32 player0f0bd358(void);
void playerConfigureVi(void);
void playerTick(bool arg0);
Gfx *playerUpdateShootRot(Gfx *gdl);
void playerDisplayShield(void);
Gfx *playerRenderHud(Gfx *gdl);
void playerDie(bool force);
void playerDieByShooter(u32 shooter, bool force);
void playerCheckIfShotInBack(s32 attackerplayernum, f32 x, f32 z);
f32 playerGetHealthBarHeightFrac(void);
void playerSetPerimEnabled(struct prop *prop, bool enable);
bool playerUpdateGeometry(struct prop *prop, u8 **start, u8 **end);
void playerUpdatePerimInfo(void);
void playerGetBbox(struct prop *prop, f32 *radius, f32 *ymax, f32 *ymin);
f32 playerGetHealthFrac(void);
f32 playerGetShieldFrac(void);
void playerSetShieldFrac(f32 frac);
s32 playerGetMissionTime(void);
s32 playerTickBeams(struct prop *prop);
s32 playerTickThirdPerson(struct prop *prop);
void playerChooseThirdPersonAnimation(struct chrdata *chr, s32 crouchpos, f32 speedsideways, f32 speedforwards, f32 speedtheta, f32 *angleoffset, struct attackanimconfig **animcfg);
Gfx *playerRender(struct prop *prop, Gfx *gdl, bool xlupass);
Gfx *playerLoadMatrix(Gfx *gdl);
void player0f0c3320(Mtxf *matrices, s32 count);
void playerSetTickMode(s32 tickmode);
void playerBeginGeFadeIn(void);
void playersBeginMpSwirl(void);
void player0f0b9a20(void);
void playerEndCutscene(void);
void playerPrepareWarpType1(s16 pad_id);
void playerPrepareWarpType2(struct warpparams *cmd, bool hasdir, s32 arg2);
void playerPrepareWarpType3(f32 posangle, f32 rotangle, f32 range, f32 height1, f32 height2, s32 padnum);
void playerAutoWalk(s16 aimpad, u8 walkspeed, u8 turnspeed, u8 lookup, u8 dist);
void playerLaunchSlayerRocket(struct weaponobj *rocket);
void playerSetCamPropertiesWithRoom(struct coord *pos, struct coord *up, struct coord *look, s32 room);

#endif
