#ifndef IN_GAME_PAK_H
#define IN_GAME_PAK_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

bool mempak_is_okay(s8 device);
s32 pak_get_file_ids_by_type(s8 device, u32 filetype, u32 *fileids);
s32 pak0f1167d8(s8 device);
s32 pak_read_body_at_guid(s8 device, s32 fileid, u8 *body, s32 arg3);
s32 pak_save_at_guid(s8 device, s32 fileid, s32 filetype, u8 *body, s32 *outfileid, u8 *olddata);
bool pak_delete_file(s8 device, s32 fileid);
PakErr1 pak_delete_game_note(s8 device, u16 company_code, u32 game_code, char *game_name, char *ext_name);
PakErr1 pak0f1168c4(s8 device, struct pakdata **arg1);
s32 pak_get_type(s8 device);
s32 pak_get_serial(s8 device);
void pak0f11698c(s8 device);
void pak0f116994(void);
void pak0f1169c8(s8 device, bool tick);
void pak_set_state(s8 device, s32 value);
s32 pak_get_plug_count(s8 device);
void pak0f117150(s8 device, u8 *ptr);
void pak0f1171b4(s8 device, s32 arg1, s32 arg2);
s32 pak_get_unk008(s8 device);

#if VERSION >= VERSION_NTSC_1_0
#else
#endif

s32 pak_get_num_free_camera_spaces_in_pak(s8 device);
void pak0f1189d0(void);
void paks_init(void);
s32 pak_find_file(s8 device, u32 fileid, struct pakfileheader *header);
#if VERSION >= VERSION_NTSC_FINAL
#endif

#if VERSION >= VERSION_NTSC_1_0
#else
#endif

void paks_reset(void);
bool pak_repair(s8 device);
void paks_tick(void);
void pak0f11c6d0(void);
void pak_execute_debug_operations(void);
s32 pak0f11d3f8(s8 device);
bool pak0f11d478(s8 device);
bool pak0f11d4dc(s8 device);
s32 pak0f11d540(s8 device, s32 arg1);
s32 pak0f11d5b0(s8 device);
void pak0f11d620(s8 device);
void pak0f11d9c4(s8 device, u8 *arg1, u8 *arg2, u32 arg3);

#if VERSION >= VERSION_NTSC_1_0
void pak_rumble(s32 device, f32 numsecs, s32 onduration, s32 offduration);
#else
void pak_rumble(s8 device, f32 numsecs, s32 onduration, s32 offduration);
#endif

void paks_stop(bool disablepolling);
void pak_disable_rumble_for_player(s8 playernum);
void pak_enable_rumble_for_player(s8 playernum);
void pak_disable_rumble_for_all_players(void);
void pak_enable_rumble_for_all_players(void);
void pak0f11e3bc(s8 device);
void pak_set_bitflag(s32 flagnum, u8 *bitstream, bool set);
bool pak_has_bitflag(u32 flagnum, u8 *stream);
void pak_clear_all_bitflags(u8 *flags);
void pak_n64_font_code_to_ascii(char *src, char *dst, s32 len);
s8 pak_find_by_serial(s32 deviceserial);
bool gbpak_is_any_perfect_dark(void);

extern const char var7f1b423c[];
extern const char var7f1b4244[];
extern const char var7f1b424c[];
extern const char var7f1b4254[];
extern const char var7f1b425c[];

#endif
