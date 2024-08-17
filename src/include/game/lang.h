#ifndef IN_GAME_LANG_H
#define IN_GAME_LANG_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

extern u8 *g_LangBuffer;

void lang_init(void);
void lang_reset(s32 stagenum);
void lang_tick(void);

u32 lang_get_lang_bank_index_from_stagenum(s32 stagenum);
struct jpncharpixels *lang_get_jpn_char_pixels(s32 codepoint);
s32 lang_get_file_num_offset(void);
s32 lang_get_file_id(s32 bank);
void lang_load(s32 bank);
void lang_load_to_addr(s32 bank, u8 *dst, s32 size);
void lang_clear_bank(s32 bank);
char *lang_get(s32 textid);
void lang_reload(void);
void lang_set_european(u32 arg0);
void lang_set_jpn_enabled(bool enable);

#endif
