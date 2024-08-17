#ifndef _IN_GAME_TITLE_H
#define _IN_GAME_TITLE_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

#define TITLE_ALLOCSIZE 1024 * 286

extern u32 var800624d4;
extern u32 var800624d8;
extern u32 var800624dc;

void title_init(void);

void title_reset(void);

Gfx *title_clear(Gfx *gdl);

char *mp_player_get_weapon_of_choice_name(u32 playernum, u32 slot);
void title_set_light(Lights1 *light, u8 r, u8 g, u8 b, f32 luminosity, struct coord *dir);
void title_init_legal(void);
void title_tick_legal(void);
void title_init_check_controllers(void);
void title_exit_check_controllers(void);
void title_tick_check_controllers(void);
Gfx *title_render_check_controllers(Gfx *gdl);
Gfx *title_render_legal(Gfx *gdl);
void title_init_pd_logo(void);
void title_exit_pd_logo(void);
void title_tick_pd_logo(void);
Gfx *title_render_pd_logo_model(Gfx *gdl, struct model *model, s32 arg2, f32 arg3, s32 arg4, f32 arg5, Mtxf *arg6, Vtx *vertices, Col *colours);
void title_skip_to_pd_title(void);
Gfx *title_render_pd_logo(Gfx *gdl);
void title_init_rare_presents(void);
void title_exit_rare_presents(void);
void title_tick_rare_presents(void);
Gfx *title_render_typewriter_text(Gfx *gdl, s32 *x, s32 *y, u16 textnum, s32 timer, s32 *colourcomponent);
Gfx *title_render_rare_presents(Gfx *gdl);
void title_init_nintendo_logo(void);
void title_exit_nintendo_logo(void);
void title_tick_nintendo_logo(void);
Gfx *title_render_nintendo_logo(Gfx *gdl);
void title_init_rare_logo(void);
void title_exit_rare_logo(void);
void title_tick_rare_logo(void);
f32 func0f019d0c(f32 arg0);
Gfx *title_render_rare_logo(Gfx *gdl);
void title_init_skip(void);
void title_init_no_controller(void);
void title_tick_no_controller(void);
Gfx *title_render_no_controller(Gfx *gdl);
void title_set_next_mode(s32 mode);
void title_tick(void);
bool title_is_changing_mode(void);
bool title_is_keeping_mode(void);
void title_exit(void);
void title_init_from_ai_cmd(u32 arg0);
bool func0f01ad5c(void);
void func0f01adb8(void);
void title_tick_old(void);
Gfx *title_render(Gfx *gdl);
void title_exit_legal(void);
s32 get_num_players(void);
void set_num_players(s32 numplayers);
void title_exit_no_controller(void);

#endif
