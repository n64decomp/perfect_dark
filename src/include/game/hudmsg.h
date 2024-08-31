#ifndef IN_GAME_HUDMSG_H
#define IN_GAME_HUDMSG_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

void hudmsgs_hide_by_channel(s32 value);
void hudmsgs_reset(void);
void hudmsg_remove_all(void);
void hudmsg_create(char *text, s32 type);
void hudmsg_create_with_flags(char *text, s32 type, u32 flags);
void hudmsg_create_with_colour(char *text, s32 type, u8 colour);
void hudmsg_create_as_subtitle(char *text, s32 type, u8 colourindex, s32 audiochannelnum);
void hudmsgs_tick(void);
void hudmsgs_set_on(u32 reason);
void hudmsgs_set_off(u32 reason);
void hudmsgs_remove_for_dead_player(s32 playernum);
Gfx *hudmsgs_render(Gfx *gdl);
void hudmsgs_stop(void);

#endif
