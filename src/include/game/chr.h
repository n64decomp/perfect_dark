#ifndef _IN_GAME_CHR_CHR_H
#define _IN_GAME_CHR_CHR_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

void chr_set_chrnum(struct chrdata *chr, s16 chrnum);
void chr_deregister(s32 chrnum);
void chr_calculate_push_pos(struct chrdata *chr, struct coord *pos, RoomNum *rooms, bool arg3);

#if VERSION >= VERSION_NTSC_1_0
bool chr_ascend(struct chrdata *chr, struct coord *pos, RoomNum *rooms, f32 amount, bool writerooms);
#else
bool chr_ascend(struct chrdata *chr, struct coord *pos, RoomNum *rooms, f32 amount);
#endif

bool chr_update_position(struct model *model, struct coord *arg1, struct coord *arg2, f32 *mangroundptr);
s32 chrs_get_num_free(void);
s16 chrs_get_next_unused_chrnum(void);
struct prop *chr_place(struct prop *prop, struct model *model, struct coord *pos, RoomNum *rooms, f32 arg3, u8 *ailist);
void chr_remove(struct prop *prop, bool free);
void chr_update_aim_properties(struct chrdata *chr);
void chr_flinch_body(struct chrdata *chr);
void chr_flinch_head(struct chrdata *chr, f32 arg1);
f32 chr_get_flinch_amount(struct chrdata *chr);
void chr_find_entered_rooms_at_pos(struct chrdata *chr, struct coord *pos, RoomNum *rooms);
void chr_update_anim(struct chrdata *chr, s32 lvupdate240, bool arg2);
void chr_tick_child(struct chrdata *chr, struct prop *child, bool fulltick);
void chr_update_cloak(struct chrdata *chr);
s32 chr_get_cloak_alpha(struct chrdata *chr);
void chr_set_poisoned(struct chrdata *chr, struct prop *poisonprop);
void chr_tick_poisoned(struct chrdata *chr);
bool chr_tick_beams(struct prop *prop);
s32 chr_tick(struct prop *prop);
void chr_drop_concealed_items(struct chrdata *chr);
void chr_set_hudpiece_visible(struct chrdata *chr, bool visible);
void chr_drop_items_for_owner_reap(struct chrdata *chr);
void chrs_set_blood_colour(u8 *rgb);
bool chr_find_onscreen_doors(struct chrdata *chr);
bool chr_should_render_gundl(struct model *model, struct modelnode *node);
void chr_render_attached_object(struct prop *prop, struct modelrenderdata *renderdata, bool xlupass, struct chrdata *chr);
void chr_get_blood_colour(s16 bodynum, u8 *colour1, u32 *colour2);
Gfx *chr_render(struct prop *prop, Gfx *gdl, bool xlupass);
void chr_emit_sparks(struct chrdata *chr, struct prop *prop, s32 hitpart, struct coord *coord, struct coord *coord2, struct chrdata *chr2);
void chr_bruise_from_stabby_projectile(struct model *model, s32 hitpart, struct modelnode *node, struct coord *arg3);
void chr_bruise(struct model *model, s32 hitpart, struct modelnode *node, struct coord *arg3);
void chr_disfigure(struct chrdata *chr, struct coord *exppos, f32 damageradius);
f32 chr_get_hit_radius(struct chrdata *chr);
void chr_test_hit(struct prop *prop, struct shotdata *shotdata, bool isshooting, bool cheap);
void chr_hit(struct shotdata *shotdata, struct hit *hit);
void chranimdebug_everyone(bool enable);
void chrs_check_for_noise(f32 noiseradius);
bool chr_calculate_auto_aim(struct prop *prop, struct coord *arg1, f32 *arg2, f32 *arg3);
s32 shieldhit_node_to_cmnum(struct prop *arg0, struct modelnode *node, struct model *model, struct prop *arg3);
bool shieldhit_cmnum_to_node(s32 arg0, struct prop *prop, struct prop **propptr, struct modelnode **nodeptr, struct model **modelptr);
void shieldhit_create(struct prop *rootprop, f32 shield, struct prop *hitprop, struct modelnode *node, struct model *model, s32 side, s16 *arg6);
void shieldhit_remove(struct shieldhit *shieldhit);
void shieldhits_remove_by_prop(struct prop *prop);
s32 shieldhit_find_parentnode_cmnum(struct prop *prop, s32 prevcmnum);
s32 shieldhit_find_childnode_cmnum(struct prop *prop, s32 prevcmnum);
s32 shieldhit_find_anynode_cmnum(struct prop *prop, s32 prevcmnum);
void shieldhit_health_to_rgb(f32 health, s32 *r, s32 *g, s32 *b);
f32 shieldhit_get_health(struct prop **propptr);
Gfx *shieldhit_render_component(Gfx *gdl, struct shieldhit *hit, struct prop *prop, struct model *model, struct modelnode *node, s32 side, s32 arg6, s32 arg7, s32 alpha);
Gfx *shieldhit_render(Gfx *gdl, struct prop *prop1, struct prop *prop2, s32 alpha, bool arg4, s32 cmnum1, s32 cmnum2, s32 cmnum3, s32 cmnum4);
Gfx *chr_render_cloak(Gfx *gdl, struct prop *chr1, struct prop *chr2);
Gfx *chr_render_shield(Gfx *gdl, struct chrdata *chr, u32 alpha);
void shieldhits_tick(void);
void chr_set_drcaroll_images(struct chrdata *drcaroll, s32 imageleft, s32 imageright);
s32 chrs_get_num_slots(void);
void chr_register(s32 chrnum, s32 chrindex);
Vtx *chr_allocate_vertices(s32 numvertices);
void chr_set_perim_enabled(struct chrdata *chr, bool enable);
void chr_set_max_damage(struct chrdata *chr, f32 maxdamage);
f32 chr_get_max_damage(struct chrdata *chr);
void chr_add_health(struct chrdata *chr, f32 health);
f32 chr_get_armor(struct chrdata *chr);
void chr_allocate(struct prop *prop, u8 *ailist);
struct prop *chr_create_with_model(struct model *model, struct coord *pos, RoomNum *rooms, f32 faceangle, u8 *ailist);
void chr_clear_references(s32 propnum);
void chr_find_entered_rooms(struct chrdata *chr, RoomNum *room);
void chr_detect_rooms(struct chrdata *chr);
void chr_cloak(struct chrdata *chr, bool arg1);
void chr_uncloak(struct chrdata *chr, bool value);
void chr_uncloak_temporarily(struct chrdata *chr);
void chrs_reset_onscreen_doors(void);
void chrs_set_stage_translation_thing(f32 arg1);
struct chrdata *chr_find_by_literal_id(s32 chrnum);
struct prop *chr_get_held_prop(struct chrdata *chr, s32 hand);
struct prop *chr_get_held_usable_prop(struct chrdata *chr, s32 hand);
struct prop *chr_get_target_prop(struct chrdata *chr);
bool chr_update_geometry(struct prop *prop, u8 **start, u8 **end);
void chr_get_bbox(struct prop *prop, f32 *radius, f32 *ymax, f32 *ymin);

#endif
