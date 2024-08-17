#ifndef IN_GAME_SETUPUTILS_H
#define IN_GAME_SETUPUTILS_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

u32 setup_get_cmd_length(u32 *cmd);
u32 *setup_get_cmd_by_index(s32 cmdindex);
s32 setup_get_cmd_index_by_tag(struct tag *tag);
u32 setup_get_cmd_index_by_prop(struct prop *prop);
bool setup_load_modeldef(s32 modelnum);
bool setup_get_obj_bbox(struct defaultobj *obj, struct coord *pos, f32 realrot[3][3], struct coord *arg3, struct coord *arg4);
bool setup0f092304(struct defaultobj *obj, struct coord *arg1, struct coord *arg2);
void setup0f09233c(struct defaultobj *obj, struct coord *pos, f32 realrot[3][3], RoomNum *rooms);
void setup0f0923d4(struct defaultobj *obj);
struct defaultobj *setup_get_obj_by_cmd_index(u32 cmdindex);
struct defaultobj *setup_find_obj_for_reuse(s32 type, struct defaultobj **arg1, struct defaultobj **arg2, bool musthaveprop, bool musthavemodel, struct modeldef *modeldef);

#endif
