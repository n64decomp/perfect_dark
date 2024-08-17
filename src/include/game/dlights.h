#ifndef IN_GAME_DLIGHTS_H
#define IN_GAME_DLIGHTS_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

u32 func0f000920(s32 portalnum1, s32 portalnum2);
struct light *room_get_light(s32 roomnum, s32 lightnum);
u8 room_get_final_brightness(s32 roomnum);
u8 room_get_final_brightness_for_player(s32 roomnum);
u8 room_get_settled_regional_brightness_for_player(s32 roomnum);
u8 room_get_settled_local_brightness(s32 room);
s32 room_get_flash_brightness(s32 roomnum);
f32 room_get_light_op_cur_frac(s32 roomnum);
f32 room_get_settled_local_brightness_frac(s32 roomnum);
bool light_get_bbox_centre(s32 roomnum, u32 lightnum, struct coord *pos);
bool light_is_healthy(s32 roomnum, s32 lightnum);
bool light_is_vulnerable(s32 roomnum, s32 lightnum);
bool light_is_on(s32 roomnum, s32 lightnum);
void room_set_flash_brightness(s32 roomnum, s32 value);
void room_set_defaults(struct room *room);
Gfx *lights_set_for_room(Gfx *gdl, RoomNum roomnum);
Gfx *lights_set_default(Gfx *gdl);
void room_init_lights(s32 roomnum);
bool lights_handle_hit(struct coord *gunpos, struct coord *hitpos, s32 roomnum);
void room_set_lights_faulty(s32 roomnum, s32 chance);
void room_set_light_broken(s32 roomnum, s32 lightnum);
void lights_reset(void);
void func0f001c0c(void);
void func0f00215c(u8 *arg0);
void lights_calculate_room_dimensions(void);
void func0f00259c(s32 roomnum);
void func0f002844(s32 roomnum, f32 arg1, s32 arg2, s32 portalnum);
void func0f002a98(void);
void room_set_lights_on(s32 roomnum, s32 enable);
void room_set_light_op(s32 roomnum, s32 operation, u8 br_to, u8 br_from, u8 duration60);
bool light_tick_broken(s32 roomnum, s32 lightnum);
void lighting_tick(void);
void lights_configure_for_perfect_darkness_cutscene(void);
void lights_configure_for_perfect_darkness_gameplay(void);
void lights_tick_perfect_darkness(void);
void rooms_tick_lighting(void);
void lights_tick(void);
void room_flash_lighting(s32 roomnum, s32 start, s32 limit);
void room_flash_local_lighting(s32 roomnum, s32 increment, s32 limit);
void room_highlight(s32 roomnum);
void func0f004c6c(void);
void func0f00505c(void);
f32 func0f0053d0(s32 room1, struct coord *arg1, s32 portal1, s32 room2, struct coord *arg4, s32 portal2, f32 *arg6);
void func0f0056f4(s32 room1, struct coord *coord1, s32 room2, struct coord *coord2, s32 arg4, f32 *arg5, s32 arg6);
void func0f005bb0(void);

#endif
