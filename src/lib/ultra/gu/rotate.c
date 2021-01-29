#include <ultra64.h>
#include "lib/lib_16110.h"

void guRotateF(float mf[4][4], float a, float x, float y, float z)
{
	float sine;
	float cosine;
	float ab, bc, ca, t;

	guNormalize(&x, &y, &z);
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

void guRotate(Mtx *m, float a, float x, float y, float z)
{
	f32 mf[4][4];

	guRotateF(mf, a, x, y, z);

	guMtxF2L(mf, m);
}
