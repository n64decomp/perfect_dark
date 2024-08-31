#ifndef IN_GAME_GAMEFILE_H
#define IN_GAME_GAMEFILE_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

u32 gamefile_has_flag(u32 value);
void gamefile_set_flag(u32 value);
void gamefile_unset_flag(u32 value);
void gamefile_apply_options(struct gamefile *file);
void gamefile_load_defaults(struct gamefile *file);
s32 gamefile_load(s32 device);
s32 gamefile_save(s32 device, s32 filenum, u16 deviceserial);
void gamefile_get_overview(char *arg0, char *name, u8 *stage, u8 *difficulty, u32 *time);

#endif
