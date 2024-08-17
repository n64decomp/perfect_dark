#ifndef IN_GAME_ENV_H
#define IN_GAME_ENV_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

struct distfadesettings {
    f32 opaperc;
    f32 xluperc;
    f32 refdist;
};

struct environment *env_get_current(void);
f32 env_get_squared_fog_max(void);
void env_tick(void);
void env_apply_fog_environment(struct fogenvironment *sky);
void env_apply_no_fog_environment(struct nofogenvironment *sky);
void env_set_stage_num(s32 stagenum);
void env_choose_and_apply(s32 stagenum, bool allowoverride);
void env_apply_transition_frac(f32 arg0);
Gfx *env_start_fog(Gfx *gdl, bool xlupass);
Gfx *env_stop_fog(Gfx *gdl);
bool env_is_pos_in_fog_max_distance(struct coord *pos, f32 tolerance);
struct distfadesettings *env_get_dist_fade_settings(void);
s32 env_get_obj_shade_mode(struct prop *prop, f32 arg1[4]);

#endif
