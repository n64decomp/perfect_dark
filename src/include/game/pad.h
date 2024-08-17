#ifndef IN_GAME_PAD_H
#define IN_GAME_PAD_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

void pad_unpack(s32 padnum, u32 fields, struct pad *pad);
bool pad_has_bbox_data(s32 padnum);
void pad_get_centre(s32 padnum, struct coord *coord);
void pad_rotate_for_door(s32 padnum);
void pad_copy_bbox_from_pad(s32 padnum, struct pad *src);
void pad_set_flag(s32 padnum, u32 flag);
void pad_unset_flag(s32 padnum, u32 flag);
s32 cover_get_count(void);
bool cover_unpack(s32 covernum, struct cover *cover);
bool cover_is_in_use(s32 covernum);
void cover_set_in_use(s32 covernum, bool enable);
void cover_set_flag(s32 covernum, u32 flag);
void cover_unset_flag(s32 covernum, u32 flag);
void cover_set_out_of_sight(s32 covernum, bool enable);
bool cover_is_special(struct cover *cover);

#endif
