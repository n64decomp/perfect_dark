#include <ultra64.h>
#include "constants.h"
#include "bss.h"
#include "data.h"
#include "types.h"

void guTranslateF(float mf[4][4], float x, float y, float z)
{
	guMtxIdentF(mf);

	mf[3][0] = x;
	mf[3][1] = y;
	mf[3][2] = z;
}

void guTranslate(Mtx *m, float x, float y, float z)
{
	f32 mf[4][4];
	u32 stack[4];

	guMtxIdentF(mf);

	mf[3][0] = x;
	mf[3][1] = y;
	mf[3][2] = z;

	guMtxF2L(mf, m);
}
