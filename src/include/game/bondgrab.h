#ifndef IN_GAME_BONDGRAB_H
#define IN_GAME_BONDGRAB_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

void bgrab_init(void);
void bgrab_exit(void);
void bgrab_handle_activate(void);
void bgrab_apply_move_data(struct movedata *data);
void bgrab_update_speed_theta(void);
void bgrab_tick(void);

#endif
