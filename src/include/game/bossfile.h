#ifndef IN_GAME_BOSSFILE_H
#define IN_GAME_BOSSFILE_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

bool bossfile_load_full(void);
u32 bossfile_find_file_id(void);
void bossfile_load(void);
void bossfile_save(void);
void bossfile_set_defaults(void);

#endif
