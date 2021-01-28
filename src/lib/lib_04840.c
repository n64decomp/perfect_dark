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

void guPerspective(Mtx *m, u16 *perspNorm, float fovy, float aspect, float near, float far, float scale)
{
	float mf[4][4];

	guPerspectiveF(mf, perspNorm, fovy, aspect, near, far, scale);

	guMtxF2L(mf, m);
}
