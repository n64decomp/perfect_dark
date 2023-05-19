#include <ultra64.h>

void guScale(Mtx *m, float x, float y, float z)
{
	f32 mf[4][4];

	guScaleF(mf, x, y, z);

	guMtxF2L(mf, m);
}
