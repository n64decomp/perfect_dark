#ifndef _IN_GAME_CAMERA_H
#define _IN_GAME_CAMERA_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

void cam_set_screen_size(f32 width, f32 height);
void cam_set_screen_position(f32 left, f32 top);
void cam_set_perspective(f32 near, f32 fovy, f32 aspect);
f32 cam0f0b49b8(f32 arg0);
void cam_set_scale(void);
void cam0f0b4c3c(f32 pos2d[2], struct coord *dir2d, f32 arg2);
void cam0f0b4d04(struct coord *in, f32 *out);
void cam0f0b4d68(struct coord *in, f32 out[2]);
void cam0f0b4dec(struct coord *in, f32 out[2]);
void cam0f0b4e68(f32 in[2], f32 divisor, f32 out[2]);
void cam0f0b4eb8(struct coord *arg0, f32 arg1[2], f32 zoom, f32 aspect);
void cam_set_mtxl1738(Mtx *mtx);
void cam_set_mtxl173c(Mtx *mtx);
Mtx *cam_get_mtxl173c(void);
void cam_set_mtxf006c(Mtxf *mtx);
Mtxf *cam_get_mtxf006c(void);
void cam_set_perspective_mtxl(Mtx *value);
Mtx *cam_get_perspective_mtxl(void);
void cam_set_orthogonal_mtxl(Mtx *mtx);
Mtx *cam_get_orthogonal_mtxl(void);
void cam_set_world_to_screen_mtxf(Mtxf *mtx);
Mtxf *cam0f0b5050(u8 *arg0);
Mtxf *cam0f0b53a4(u8 *arg0);
Mtxf *cam_get_world_to_screen_mtxf(void);
void cam_set_mtxf1754(Mtxf *mtx);
Mtxf *cam_get_mtxf1754(void);
void cam_set_projection_mtxf(Mtxf *mtx);
Mtxf *cam_get_projection_mtxf(void);
void cam_set_look_at(LookAt *lookat);
LookAt *cam_get_look_at(void);
f32 cam_get_lod_scale_z(void);
f32 cam_get_screen_width(void);
f32 cam_get_screen_height(void);
f32 cam_get_screen_left(void);
f32 cam_get_screen_top(void);
f32 cam_get_persp_aspect(void);
void cam0f0b5838(void);
bool cam0f0b5b9c(struct coord *arg0, f32 arg1);
bool cam_is_pos_in_screen_box(struct coord *pos, f32 arg1, struct drawslot *drawslot);
bool cam_is_pos_in_fov_and_visible_room(RoomNum *rooms, struct coord *pos, f32 arg2);

#endif
