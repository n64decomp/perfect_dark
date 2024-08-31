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
s32 get_num_players(void);
void set_num_players(s32 numplayers);

#endif
