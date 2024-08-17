#ifndef _IN_GAME_MPLAYER_SCENARIOS_H
#define _IN_GAME_MPLAYER_SCENARIOS_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

extern struct menudialogdef g_MpScenarioMenuDialog;
extern struct menudialogdef g_MpQuickTeamScenarioMenuDialog;

struct mpscenariooverview {
	u16 name;
	u16 shortname;
	u8 requirefeature;
	u8 teamonly;
};

extern struct mpscenariooverview g_MpScenarioOverviews[6];

MenuItemHandlerResult menuhandler_mp_open_options(s32 operation, struct menuitem *item, union handlerdata *data);
void scenario_read_save(struct savebuffer *buffer);
void scenario_write_save(struct savebuffer *buffer);
void scenario_init(void);
s32 scenario_num_props(void);
void scenario_init_props(void);
void scenario_tick(void);
void scenario_tick_chr(struct chrdata *chr);
Gfx *scenario_radar_extra(Gfx *gdl);
bool scenario_radar_chr(Gfx **gdl, struct prop *prop);
f32 scenario_choose_spawn_location(f32 chrradius, struct coord *pos, RoomNum *rooms, struct prop *prop);
s32 scenario_get_max_teams(void);
void scenario_highlight_room(RoomNum room, s32 *arg1, s32 *arg2, s32 *arg3);

#endif
