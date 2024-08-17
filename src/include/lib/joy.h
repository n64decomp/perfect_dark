#ifndef _IN_LIB_JOY_H
#define _IN_LIB_JOY_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

void joy_lock_cyclic_polling(void);
void joy_unlock_cyclic_polling(void);
void joy_set_pfs_poll_enabled(bool enabled);
bool joy_is_pfs_poll_enabled(void);
void joy_set_pfs_poll_interval(s32 value);
void joy_set_default_pfs_poll_interval(void);
s32 joy_shift_pfs_states(void);
void joy_record_pfs_state(u8 pfsstate);
void joy_poll_pfs(s32 force);
void joy_set_pfs_temporarily_plugged(s8 index);
void joy_init(void);
void joy_disable_temporarily(void);
void joy_reset(void);
void joy00013e84(void);
u32 joy_get_connected_controllers(void);
void joy00014238(void);
void joy_debug_joy(void);
s32 joy_start_read_data(OSMesgQueue *mq);
void joy_read_data(void);
void joys_handle_retrace(void);
void joy00014810(bool value);
s32 joy_get_num_samples(void);
s32 joy_get_stick_x_on_sample(s32 samplenum, s8 contpadnum);
s32 joy_get_stick_y_on_sample(s32 samplenum, s8 contpadnum);
s32 joy_get_stick_y_on_sample_index(s32 samplenum, s8 contpadnum);
u16 joy_get_buttons_on_sample(s32 samplenum, s8 contpadnum, u16 mask);
u16 joy_get_buttons_pressed_on_sample(s32 samplenum, s8 contpadnum, u16 mask);
s32 joy_count_buttons_on_specific_samples(u32 *arg0, s8 contpadnum, u16 mask);
s8 joy_get_stick_x(s8 contpadnum);
s8 joy_get_stick_y(s8 contpadnum);
u16 joy_get_buttons(s8 contpadnum, u16 mask);
u16 joy_get_buttons_pressed_this_frame(s8 contpadnum, u16 mask);
bool joy_is_cyclic_polling_enabled(void);

#if VERSION >= VERSION_NTSC_1_0
void joy_disable_cyclic_polling(void);
void joy_enable_cyclic_polling(void);
#else
void joy_disable_cyclic_polling(s32 line, char *file);
void joy_enable_cyclic_polling(s32 line, char *file);
#endif

void joy_destroy(void);
void joy_get_contpad_nums_for_player(s8 playernum, s32 *pad1, s32 *pad2);
void joy_stop_rumble(s8 device, bool disablepolling);
s32 joy_get_pak_state(s8 device);
s32 joy_get_pak_state2(s8 device);
void joys_tick_rumble(void);

#endif
