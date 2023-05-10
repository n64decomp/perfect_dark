#ifndef _IN_LIB_MODEL_H
#define _IN_LIB_MODEL_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

extern bool (*var8005efc4)(struct model *model, struct modelnode *node);
extern struct gfxvtx *(*g_ModelVtxAllocatorFunc)(s32 numvertices);
extern void (*g_ModelJointPositionedFunc)(s32 mtxindex, Mtxf *mtx);
extern bool var8005efdc;

bool model00018680(struct modelrenderdata *renderdata, struct model *model);
s32 model0001a524(struct modelnode *node, s32 arg1);
Mtxf *model0001a5cc(struct model *model, struct modelnode *node, s32 arg2);
Mtxf *model0001a60c(struct model *model);
struct modelnode *model0001a634(struct model *model, s32 mtxindex);
struct modelnode *model0001a740(struct modelnode *node);
struct modelnode *model0001a784(struct modelnode *node);
struct modelnode *model0001a7cc(struct modelnode *node);
struct modelnode *model0001a85c(struct modelnode *node);
struct modelnode *modelGetPart(struct modelfiledata *arg0, s32 partnum);
void *modelGetPartRodata(struct modelfiledata *modelfiledata, s32 partnum);
f32 model0001a9e8(struct model *model);
void *modelGetNodeRwData(struct model *model, struct modelnode *node);
void modelNodeGetPosition(struct model *model, struct modelnode *node, struct coord *pos);
void modelGetRootPosition(struct model *model, struct coord *pos);
void modelSetRootPosition(struct model *model, struct coord *pos);
void modelNodeGetModelRelativePosition(struct model *model, struct modelnode *node, struct coord *pos);
f32 model0001ae44(struct model *model);
void model0001ae90(struct model *model, f32 angle);
void modelSetAnimScale(struct model *model, f32 scale);
f32 model0001af80(struct model *model);
f32 model0001afe8(f32 arg0, f32 angle, f32 frac);
void model0001b3bc(struct model *model);
void model0001c784(struct model *model, struct modelnode *node);
void model0001c7d0(struct model *model, struct modelnode *node);
void modelAttachHead(struct model *model, struct modelnode *node);
void model0001cb0c(struct model *model, struct modelnode *node);
void model0001cc20(struct model *model);
void model0001ce64(struct modelrenderdata *arg0, struct model *model);
void model0001cebc(struct modelrenderdata *renderdata, struct model *model);
s16 modelGetAnimNum(struct model *model);
bool modelIsFlipped(struct model *model);
f32 modelGetCurAnimFrame(struct model *model);
f32 modelGetAnimEndFrame(struct model *model);
s32 modelGetNumAnimFrames(struct model *model);
f32 modelGetAnimSpeed(struct model *model);
f32 modelGetAbsAnimSpeed(struct model *model);
bool modelIsAnimMerging(struct model *model);
void modelSetAnimationWithMerge(struct model *model, s16 animnum, u32 flip, f32 startframe, f32 speed, f32 timemerge, bool domerge);
void modelSetAnimation(struct model *model, s16 animnum, s32 flip, f32 fstartframe, f32 speed, f32 merge);
void modelCopyAnimData(struct model *src, struct model *dst);
void modelSetAnimLooping(struct model *model, f32 loopframe, f32 loopmerge);
void modelSetAnimEndFrame(struct model *model, f32 endframe);
void modelSetAnimFlipFunction(struct model *model, void *callback);
void modelSetAnimSpeed(struct model *model, f32 speed, f32 startframe);
void modelSetAnimSpeedAuto(struct model *model, f32 arg1, f32 startframe);
void modelSetAnimPlaySpeed(struct model *model, f32 speed, f32 frame);
void modelSetAnim70(struct model *model, void *callback);
void model0001e018(struct model *model, f32 startframe);
void model0001ee18(struct model *model, s32 lvupdate240, bool arg2);
void model0001f314(struct model *model, s32 lvupdate240, bool arg2);
void modelRender(struct modelrenderdata *renderdata, struct model *model);
bool model000220fc(struct modelrodata_bbox *bbox, Mtxf *mtx, struct coord *arg2, struct coord *arg3);
s32 model000225d4(struct model *model, struct coord *arg1, struct coord *arg2, struct modelnode **startnode);
void modelPromoteOffsetsToPointers(struct modelfiledata *filedata, u32 arg1, u32 arg2);
void modelCalculateRwDataLen(struct modelfiledata *filedata);
void modelInitRwData(struct model *model, struct modelnode *node);
void modelInit(struct model *model, struct modelfiledata *filedata, union modelrwdata **rwdatas, bool resetanim);
void animInit(struct anim *anim);
void model00023108(struct model *model, struct modelfiledata *arg1, struct modelnode *node, struct modelfiledata *arg3);
void modelIterateDisplayLists(struct modelfiledata *filedata, struct modelnode **nodeptr, Gfx **gdlptr);
void modelNodeReplaceGdl(struct modelfiledata *modeldef, struct modelnode *node, Gfx *find, Gfx *replacement);

#endif
