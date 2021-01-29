#include <ultra64.h>
#include "constants.h"
#include "game/data/data_000000.h"
#include "game/data/data_0083d0.h"
#include "game/data/data_00e460.h"
#include "game/data/data_0160b0.h"
#include "game/data/data_01a3a0.h"
#include "game/data/data_020df0.h"
#include "game/data/data_02da90.h"
#include "gvars/gvars.h"
#include "lib/lib_04790.h"
#include "lib/lib_04a80.h"
#include "lib/lib_16110.h"
#include "lib/lib_48150.h"
#include "lib/lib_4a360.h"
#include "lib/lib_4a5e0.h"
#include "lib/libc/ldiv.h"
#include "lib/libc/ll.h"
#include "types.h"

void guRotateF(float mf[4][4], float a, float x, float y, float z)
{
	float sine;
	float cosine;
	float ab, bc, ca, t;

	scaleTo1(&x, &y, &z);
	a *= 3.1415926f / 180.0f;
	sine = sinf(a);
	cosine = cosf(a);
	t = 1 - cosine;
	ab = x * y * t;
	bc = y * z * t;
	ca = z * x * t;

	guMtxIdentF(mf);

	t = x * x;
	mf[0][0] = t + cosine * (1 - t);
	mf[2][1] = bc - x * sine;
	mf[1][2] = bc + x * sine;

	t = y * y;
	mf[1][1] = t + cosine * (1 - t);
	mf[2][0] = ca + y * sine;
	mf[0][2] = ca - y * sine;

	t = z * z;
	mf[2][2] = t + cosine * (1 - t);
	mf[1][0] = ab - z * sine;
	mf[0][1] = ab + z * sine;
}

GLOBAL_ASM(
glabel func00004c04
/*     4c04:	27bdffa0 */ 	addiu	$sp,$sp,-96
/*     4c08:	44856000 */ 	mtc1	$a1,$f12
/*     4c0c:	44867000 */ 	mtc1	$a2,$f14
/*     4c10:	c7a40070 */ 	lwc1	$f4,0x70($sp)
/*     4c14:	afbf001c */ 	sw	$ra,0x1c($sp)
/*     4c18:	afa40060 */ 	sw	$a0,0x60($sp)
/*     4c1c:	44056000 */ 	mfc1	$a1,$f12
/*     4c20:	44067000 */ 	mfc1	$a2,$f14
/*     4c24:	afa7006c */ 	sw	$a3,0x6c($sp)
/*     4c28:	27a40020 */ 	addiu	$a0,$sp,0x20
/*     4c2c:	0c0012a0 */ 	jal	guRotateF
/*     4c30:	e7a40010 */ 	swc1	$f4,0x10($sp)
/*     4c34:	27a40020 */ 	addiu	$a0,$sp,0x20
/*     4c38:	0c0128d8 */ 	jal	guMtxF2L
/*     4c3c:	8fa50060 */ 	lw	$a1,0x60($sp)
/*     4c40:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*     4c44:	27bd0060 */ 	addiu	$sp,$sp,0x60
/*     4c48:	03e00008 */ 	jr	$ra
/*     4c4c:	00000000 */ 	nop
);
