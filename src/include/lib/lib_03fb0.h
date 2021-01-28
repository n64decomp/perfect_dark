#ifndef _IN_LIB_LIB_03FB0_H
#define _IN_LIB_LIB_03FB0_H
#include <ultra64.h>
#include "types.h"

void guLookAtF(float mf[4][4], float xEye, float yEye, float zEye,
	       float xAt,  float yAt,  float zAt,
	       float xUp,  float yUp,  float zUp);

void guLookAt(Mtx *m, float xEye, float yEye, float zEye,
		float xAt,  float yAt,  float zAt,
		float xUp,  float yUp,  float zUp);

#endif
