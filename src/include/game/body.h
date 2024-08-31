#ifndef IN_GAME_BODY_H
#define IN_GAME_BODY_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

void bodies_init(void);

void bodies_reset(s32 stagenum);

u32 body_get_race(s32 bodynum);
bool body_load_modeldef(s32 bodynum);
struct model *body_instantiate_model_to_addr(s32 bodynum, s32 headnum, struct modeldef *bodymodeldef, struct modeldef *headmodeldef, bool sunglasses, struct model *model, bool isplayer, u8 varyheight);
struct model *body_instantiate_model_with_spawnflags(s32 bodynum, s32 headnum, u32 spawnflags);
s32 body_choose_head(s32 bodynum);
void body_instantiate_chr(s32 stagenum, struct packedchr *packed, s32 cmdindex);
struct prop *body_instantiate_eyespy(struct pad *pad, RoomNum room);
void body_calculate_head_offset(struct modeldef *headmodeldef, s32 headnum, s32 bodynum);

#endif
