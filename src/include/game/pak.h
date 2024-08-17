#ifndef IN_GAME_PAK_H
#define IN_GAME_PAK_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

u32 pak_get_block_size(s8 device);
u32 pak_align(s8 device, u32 size);
s32 pak_get_aligned_file_len_by_body_len(s8 device, u32 bodylen);
u32 pak_get_body_len_by_file_len(u32 filelen);
u32 pak_generate_serial(s8 device);
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
bool mempak_is_ready(s8 device);
bool mempak_is_ready_or_full(s8 device);
void pak0f116bdc(s8 device, u8 *arg1, u8 *arg2);
u16 _pak_get_serial(s8 device);
u32 _pak_get_type(s8 device);
void pak_set_state(s8 device, s32 value);
s32 pak0f116df0(s8 device, struct pakdata **arg1);
s32 _pak_delete_game_note(s8 device, u16 company_code, u32 game_code, char *game_name, char *ext_name);
s32 _pak_delete_file(s8 device, s32 fileid);
s32 pak_get_plug_count(s8 device);
u32 pak_get_max_file_size(s8 device);
s32 pak_get_body_len_by_type(s8 device, u32 filetype);
void pak0f117150(s8 device, u8 *ptr);
void pak0f1171b4(s8 device, s32 arg1, s32 arg2);
s32 pak_get_unk008(s8 device);
bool pak_retrieve_block_from_cache(s8 device, u32 offset, u8 *dst);
PakErr2 pak_read_header_at_offset(s8 device, u32 offset, struct pakfileheader *header);
void pak_dump_buffer(u8 *buffer, u32 len, char *name);
void pak_dump_eeprom(void);
s32 _pak_save_at_guid(s8 device, s32 fileid, s32 filetype, u8 *newdata, s32 *outfileid, u8 *olddata);

#if VERSION >= VERSION_NTSC_1_0
PakErr1 pak_init_pak(OSMesgQueue *mq, OSPfs *pfs, s32 channel, s32 *arg3);
#else
PakErr1 pak_init_pak(OSMesgQueue *mq, OSPfs *pfs, s32 channel);
#endif

PakErr1 _pak_read_write_block(OSPfs *pfs, s32 file_no, u8 flag, u32 address, u32 len, u8 *buffer);
PakErr1 pak_query_num_notes(OSPfs *pfs, s32 *max_files, s32 *files_used);
PakErr1 pak_query_num_free_bytes(OSPfs *pfs, s32 *bytes_not_used);
PakErr1 pak_query_note_state(OSPfs *pfs, s32 file_no, OSPfsState *note);
PakErr1 pak_allocate_note(OSPfs *pfs, u16 company_code, u32 game_code, char *game_name, char *ext_name, s32 size, s32 *file_no);
PakErr1 pak_delete_game_note3(OSPfs *pfs, u16 company_code, u32 game_code, char *game_name, char *ext_name);
PakErr1 pak_find_note(OSPfs *pfs, u16 company_code, u32 game_code, char *game_name, char *ext_name, s32 *file_no);
PakErr1 _pak_resize_note(OSPfs *pfs, u16 company_code, u32 game_code, u8 *game_name, u8 *ext_name, u32 numbytes);
s32 pak_get_pd_num_pages(s8 device);
u32 pak_get_pd_num_bytes(s8 device);
s32 pak_query_num_free_pages(s8 device);
bool pak_can_fit_camera_file_in_pak(s8 device);
s32 pak_get_num_free_camera_spaces_in_pak(s8 device);
s32 _pak_create_camera_file(s8 device, s32 *outfileid);
bool pak_resize_note(s8 device, s32 numpages);
void pak0f1185e0(s8 device, s32 arg1, s32 arg2);
u32 pak0f118674(s8 device, u32 filetype, s32 *outfileid);
void pak0f1189d0(void);
void paks_init(void);
void pak_calculate_checksum(u8 *arg0, u8 *arg1, u16 *arg2);
s32 _pak_read_body_at_guid(s8 device, s32 fileid, u8 *body, s32 arg3);
s32 _pak_get_file_ids_by_type(s8 device, u32 filetype, u32 *fileids);
s32 pak_check_file_can_fit_in_note(s8 device, s32 filetype, s32 *numspaces);
u32 pak0f119298(s8 device);
void pak0f119340(u32 arg0);
s32 pak_find_file(s8 device, u32 fileid, struct pakfileheader *header);
#if VERSION >= VERSION_NTSC_FINAL
bool pak_write_blank_file(s8 device, u32 offset, struct pakfileheader *header);
#endif
bool pak_repair_as_blank(s8 device, u32 *offset, struct pakfileheader *header);
s32 pak_repair_filesystem(s8 device);
void pak_corrupt(void);

#if VERSION >= VERSION_NTSC_1_0
bool pak_create_initial_files(s8 device);
#else
void pak_create_initial_files(s8 device);
#endif

s32 pak_find_max_file_id(s8 device);
void pak_merge_blanks(s8 device);
void paks_reset(void);
void pak_set_features(s8 device, u8 features, u32 line, char *file);
void pak_set_defaults(s8 arg0);
PakErr1 pak_read_write_block(s8 device, OSPfs *pfs, s32 file_no, u8 flag, u32 address, u32 len, u8 *buffer);
bool pak_query_total_usage(s8 device);
void pak_query_pd_size(s8 device);
bool mempak_prepare(s8 device);
bool pak_probe(s8 device);
void pak_wipe(s8 device, u32 blocknumstart, u32 blocknumend);
void pak_save_header_to_cache(s8 device, s32 blocknum, struct pakfileheader *header);
bool pak_retrieve_header_from_cache(s8 device, s32 blocknum, struct pakfileheader *header);
s32 pak_create_filesystem(s8 device);
bool pak_get_filesystem_length(s8 device, u32 *outlen);
s32 pak0f11b86c(s8 device, u32 offset, u8 *data, struct pakfileheader *header, s32 arg4);
bool pak_replace_file_at_offset_with_blank(s8 device, u32 offset);
s32 pak_write_file_at_offset(s8 device, u32 offset, u32 filetype, u8 *newdata, s32 bodylen, s32 *outfileid, u8 *olddata, u32 fileid, u32 generation);
bool pak_repair(s8 device);
bool pak_handle_result(s32 err1, s8 device, bool arg2, u32 line);
void paks_tick(void);
void pak0f11c6d0(void);
void pak_execute_debug_operations(void);
void pak_check_plugged(void);
void gbpak_handle_error(u32 arg0);
bool gbpak_read(s8 device, u16 address, u8 *buffer, u16 size);
bool gbpak_write(s8 device, u16 address, u8 *buffer, u16 size);
bool pak0f11cd00(s8 device, u16 arg1, char *arg2, s32 arg3, s32 arg4);
bool pak0f11ce00(s8 device, u16 arg1, char *arg2, s32 arg3, bool arg4);
void pak0f11d118(u8 *arg0, u8 arg1, u32 arg2);
void pak0f11d174(s8 device, u8 *arg1);
void pak0f11d214(u8 *arg0, u32 arg1);
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
void pak_dump_pak(void);
void pak_tick_state(s8 device);
void pak0f11e3bc(s8 device);
void pak_probe_eeprom(void);
PakErr1 pak_read_eeprom(u8 address, u8 *buffer, u32 len);
PakErr1 pak_write_eeprom(u8 address, u8 *buffer, u32 len);
void pak_set_bitflag(s32 flagnum, u8 *bitstream, bool set);
bool pak_has_bitflag(u32 flagnum, u8 *stream);
void pak_clear_all_bitflags(u8 *flags);
void pak_n64_font_code_to_ascii(char *src, char *dst, s32 len);
s8 pak_find_by_serial(s32 deviceserial);
s32 pak0f11e750(s8 device);
bool gbpak_is_any_perfect_dark(void);
bool gbpak_strcmp(char *a, char *b);
s32 gbpak_identify_game(s8 device);
bool pak0f11ea34(s8 device);

extern const char var7f1b423c[];
extern const char var7f1b4244[];
extern const char var7f1b424c[];
extern const char var7f1b4254[];
extern const char var7f1b425c[];

#endif
