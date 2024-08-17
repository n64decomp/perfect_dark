#ifndef IN_GAME_BODY_H
#define IN_GAME_BODY_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

void bodies_init(void);

void bodies_reset(s32 stagenum);

u32 body_get_race(s32 bodynum);
bool body_load(s32 bodynum);
struct model *body0f02ce8c(s32 bodynum, s32 headnum, struct modeldef *bodymodeldef, struct modeldef *headmodeldef, bool sunglasses, struct model *model, bool isplayer, u8 varyheight);
struct model *body0f02d338(s32 bodynum, s32 headnum, struct modeldef *bodymodeldef, struct modeldef *headmodeldef, bool sunglasses, u8 varyheight);
struct model *body_allocate_model(s32 bodynum, s32 headnum, u32 spawnflags);
s32 body0f02d3f8(void);
s32 body_choose_head(s32 bodynum);
void body_allocate_chr(s32 stagenum, struct packedchr *packed, s32 cmdindex);
struct prop *body_allocate_eyespy(struct pad *pad, RoomNum room);
void body_calculate_head_offset(struct modeldef *headmodeldef, s32 headnum, s32 bodynum);

#endif
