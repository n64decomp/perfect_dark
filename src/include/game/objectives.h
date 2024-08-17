#ifndef IN_GAME_OBJECTIVES_H
#define IN_GAME_OBJECTIVES_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

void objectives_stop(void);

void objectives_reset(void);
void tag_insert(struct tag *tag);
void briefing_insert(struct briefingobj *obj);
void objective_insert(struct objective *objective);
void objective_add_room_entered_criteria(struct criteria_roomentered *criteria);
void objective_add_throw_in_room_criteria(struct criteria_throwinroom *criteria);
void objective_add_holograph_criteria(struct criteria_holograph *criteria);

u32 xor_baffbeff(u32 value);
u32 xor_babeffff(u32 value);
u32 xor_boobless(u32 value);
void tags_reset(void);
s32 obj_get_tag_num(struct defaultobj *obj);
s32 objective_get_count(void);
u32 objective_get_difficulty_bits(s32 index);
s32 objective_check(s32 index);
bool objective_is_all_complete(void);
void objectives_disable_checking(void);
void objectives_show_hudmsg(char *buffer, s32 hudmsgtype);
void objectives_check_all(void);
void objective_check_room_entered(s32 currentroom);
void objective_check_throw_in_room(s32 arg0, RoomNum *requiredrooms);
void objective_check_holograph(f32 sqdist);
struct prop *chopper_get_target_prop(struct chopperobj *heli);
struct defaultobj *obj_find_by_tag_id(s32 tag_id);
struct tag *tag_find_by_id(s32 tag_id);

#endif
