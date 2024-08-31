#ifndef IN_GAME_BONDBIKE_H
#define IN_GAME_BONDBIKE_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

void bbike_init(void);
void bbike_exit(void);
void bbike_handle_activate(void);
void bbike_apply_move_data(struct movedata *data);
void bbike_tick(void);

#endif
