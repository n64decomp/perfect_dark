#ifndef IN_GAME_DEBUG_H
#define IN_GAME_DEBUG_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

void debug0f119a80nb(void);
u32 dprint();
s32 debug_get_profile_mode(void);
bool debug_is_bg_rendering_enabled(void);
bool debug_is_prop_rendering_enabled(void);
bool debug0f11ed88(void);
bool debug_is_man_pos_enabled(void);
bool debug_is_room_gfx_extra_mem_enabled(void);
bool debug_is_obj_deform_debug_enabled(void);
bool debug_is_room_state_debug_enabled(void);
s32 debug_is_turbo_mode_enabled(void);
bool debug_force_all_objectives_complete(void);
bool debug_is_z_buffer_disabled(void);
bool debug0f11ee40(void);
bool debug0f1199f0nb(void);
bool debug0f119a14nb(void);
s32 debug_get_slow_motion(void);
s32 debug_get_tiles_debug_mode(void);
s32 debug_get_pads_debug_mode(void);
bool debug0f11eea8(void);
bool debug_dangerous_props(void);
s32 debug_get_motion_blur(void);
bool debug_is_footsteps_enabled(void);
bool debug_is_all_challenges_enabled(void);
bool debug_is_all_buddies_enabled(void);
bool debug_is_set_complete_enabled(void);
bool debug_is_all_training_enabled(void);
bool debug_allow_end_level(void);
bool debug_is_chr_stats_enabled(void);
bool debug0f11ef80(void);
bool debug_is_mem_info_enabled(void);

s32 dmenu_get_selected_option(void);
void dmenu_set_selected_option(s32 option);
void dmenu_set_menu(char **labels, s32 (*positions)[2], s32 *offsets);
void dmenu_navigate_right(void);
void dmenu_navigate_left(void);
void dmenu_navigate_up(void);
void dmenu_navigate_down(void);
Gfx *dmenu_render(Gfx *gdl);

void debug_update_menu(void);
bool debug_process_input(s8 stickx, s8 sticky, u16 buttons, u16 buttonsthisframe);
bool debug_is_line_mode_enabled(void);

extern s32 var800786f4nb;
extern s32 g_DebugMenuPositions[][2];
extern char *g_DebugMenuLabels[];

#endif
