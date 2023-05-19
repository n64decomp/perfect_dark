#include <ultra64.h>

void guFrustumF(float mf[4][4], float l, float r, float b, float t, float n, float f, float scale)
{
	int i, j;

	mf[0][0] = 2 * n / (r - l) * scale;
	mf[0][1] = 0;
	mf[0][2] = 0;
	mf[0][3] = 0;

	mf[1][0] = 0;
	mf[1][1] = 2 * n / (t - b) * scale;
	mf[1][2] = 0;
	mf[1][3] = 0;

	mf[2][0] = (r + l) / (r - l) * scale;
	mf[2][1] = (t + b) / (t - b) * scale;
	mf[2][2] = -(f + n) / (f - n) * scale;
	mf[2][3] = -scale;

	mf[3][0] = 0;
	mf[3][1] = 0;
	mf[3][2] = -2 * f * n / (f - n) * scale;
	mf[3][3] = 0;
}
