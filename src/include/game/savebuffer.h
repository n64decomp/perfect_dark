#ifndef IN_GAME_SAVEBUFFER_H
#define IN_GAME_SAVEBUFFER_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

Gfx *ortho_begin(Gfx *gdl);
Gfx *ortho_end(Gfx *gdl);
Gfx *ortho_holoray_begin(Gfx *gdl, s32 type);
Gfx *ortho_holoray_end(Gfx *gdl);
Gfx *ortho_draw_holoray(Gfx *gdl, s32 x1, s32 y1, s32 x2, s32 y2, u32 colour1, u32 colour2, s32 type);
void savebuffer_write_bits(struct savebuffer *buffer, u32 arg1, s32 arg2);
u32 savebuffer_read_bits(struct savebuffer *buffer, s32 offset);
void savebuffer_reset(struct savebuffer *buffer);
void savebuffer_prepare_string(struct savebuffer *buffer, u8 *data, u8 len);
void savebuffer_print(struct savebuffer *buffer);
void savebuffer_read_string(struct savebuffer *buffer, char *dst, bool addlinebreak);
void savebuffer_write_string(struct savebuffer *buffer, char *src);
void savebuffer_bitstring_to_cstring(u8 *data, char *dst, bool addlinebreak);
void savebuffer_cstring_to_bitstring(u8 *dst, char *buffer);
void savebuffer_write_guid(struct savebuffer *buffer, struct fileguid *guid);
void savebuffer_read_guid(struct savebuffer *buffer, struct fileguid *guid);
void format_time(char *dst, s32 time60, s32 precision);
void ortho_reset(void);

#endif
