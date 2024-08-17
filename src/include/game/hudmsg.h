#ifndef IN_GAME_HUDMSG_H
#define IN_GAME_HUDMSG_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

u8 hudmsgs_are_active(void);
s32 hudmsg_is_zoom_range_visible(void);
Gfx *hudmsg_render_mission_timer(Gfx *gdl, u32 alpha);
Gfx *hudmsg_render_zoom_range(Gfx *gdl, u32 alpha);
Gfx *hudmsg_render_box(Gfx *gdl, s32 x1, s32 y1, s32 x2, s32 y2, f32 bgopacity, u32 bordercolour, f32 textopacity);
s32 hudmsg0f0ddb1c(s32 *arg0, s32 arg1);
void hudmsgs_hide_by_channel(s32 value);
void hudmsgs_reset(void);
void hudmsg_remove_all(void);
s32 hudmsg_get_next(s32 refid);
void hudmsg_create(char *text, s32 type);
void hudmsg_create_with_flags(char *text, s32 type, u32 flags);
void hudmsg_create_with_colour(char *text, s32 type, u8 colour);
void hudmsg_create_with_duration(char *text, s32 type, struct hudmsgtype *config, s32 duration60);
void hudmsg_create_as_subtitle(char *text, s32 type, u8 colourindex, s32 audiochannelnum);
void hudmsg_calculate_position(struct hudmessage *msg);
void hudmsg_create_from_args(char *text, s32 type, s32 conf00, s32 conf01, s32 conf02,
		struct fontchar **conf04, struct font **conf08,
		u32 textcolour, u32 shadowcolour,
		u32 alignh, s32 conf16, u32 alignv, s32 conf18, s32 arg14, u32 flags);
void hudmsgs_tick(void);
void hudmsgs_set_on(u32 reason);
void hudmsgs_set_off(u32 reason);
void hudmsgs_remove_for_dead_player(s32 playernum);
Gfx *hudmsgs_render(Gfx *gdl);
void hudmsgs_stop(void);

#endif
