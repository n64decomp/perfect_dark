#ifndef _IN_GAME_QUATERNION_H
#define _IN_GAME_QUATERNION_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

void quaternion0f096ca0(struct coord *arg0, f32 quat[4]);
void quaternionToMtx(f32 arg0[4], Mtxf *arg1);
void quaternion0f097044(Mtxf *matrix, f32 arg1[4]);
void quaternionToTransformMtx(struct coord *pos, f32 rot[4], Mtxf *matrix);
void quaternionSlerp(f32 q1[4], f32 q2[4], f32 t, f32 result[4]);
void quaternion0f097518(f32 q[4], f32 t, f32 result[4]);
void quaternion0f0976c0(f32 q1[4], f32 q2[4]);
void quaternionMultQuaternion(f32 a[4], f32 b[4], f32 result[4]);

#endif
