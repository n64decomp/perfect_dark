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
#include "lib/lib_04840.h"
#include "lib/lib_16110.h"
#include "lib/lib_4a360.h"
#include "types.h"

void guPerspectiveF(float mf[4][4], u16 *perspNorm, float fovy, float aspect, float near, float far, float scale)
{
	float cot;
	int	i, j;

	guMtxIdentF(mf);

	fovy *= 3.1415926f / 180.0f;
	cot = cosf(fovy * 0.5f) / sinf(fovy * 0.5f);

	mf[0][0] = cot / aspect;
	mf[1][1] = cot;
	mf[2][2] = (near + far) / (near - far);
	mf[2][3] = -1;
	mf[3][2] = (2.0f * near * far) / (near - far);
	mf[3][3] = 0;

	for (i = 0; i < 4; i++) {
		for (j = 0; j < 4; j++) {
			mf[i][j] *= scale;
		}
	}

	if (perspNorm != (u16 *) NULL) {
		if (near + far <= 2.0f) {
			*perspNorm = (u16) 0xFFFF;
		} else {
			*perspNorm = (u16) ((2.0f * 65536.0f) / (near + far));

			if (*perspNorm <= 0) {
				*perspNorm = (u16) 0x0001;
			}
		}
	}
}

GLOBAL_ASM(
glabel func00004a24
/*     4a24:	27bdff98 */ 	addiu	$sp,$sp,-104
/*     4a28:	44866000 */ 	mtc1	$a2,$f12
/*     4a2c:	44877000 */ 	mtc1	$a3,$f14
/*     4a30:	c7a40078 */ 	lwc1	$f4,0x78($sp)
/*     4a34:	c7a6007c */ 	lwc1	$f6,0x7c($sp)
/*     4a38:	c7a80080 */ 	lwc1	$f8,0x80($sp)
/*     4a3c:	afbf0024 */ 	sw	$ra,0x24($sp)
/*     4a40:	afa40068 */ 	sw	$a0,0x68($sp)
/*     4a44:	44066000 */ 	mfc1	$a2,$f12
/*     4a48:	44077000 */ 	mfc1	$a3,$f14
/*     4a4c:	27a40028 */ 	addiu	$a0,$sp,0x28
/*     4a50:	e7a40010 */ 	swc1	$f4,0x10($sp)
/*     4a54:	e7a60014 */ 	swc1	$f6,0x14($sp)
/*     4a58:	0c001210 */ 	jal	guPerspectiveF
/*     4a5c:	e7a80018 */ 	swc1	$f8,0x18($sp)
/*     4a60:	27a40028 */ 	addiu	$a0,$sp,0x28
/*     4a64:	0c0128d8 */ 	jal	guMtxF2L
/*     4a68:	8fa50068 */ 	lw	$a1,0x68($sp)
/*     4a6c:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*     4a70:	27bd0068 */ 	addiu	$sp,$sp,0x68
/*     4a74:	03e00008 */ 	jr	$ra
/*     4a78:	00000000 */ 	nop
/*     4a7c:	00000000 */ 	nop
);
