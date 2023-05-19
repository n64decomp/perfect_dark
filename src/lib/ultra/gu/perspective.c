#include <ultra64.h>

void guPerspectiveF(float mf[4][4], u16 *perspNorm, float fovy, float aspect, float near, float far, float scale)
{
	float cot;
	int	i, j;

	fovy *= 3.1415926f / 180.0f;
	cot = cosf(fovy * 0.5f) / sinf(fovy * 0.5f);

	mf[0][0] = cot / aspect * scale;
	mf[0][1] = 0;
	mf[0][2] = 0;
	mf[0][3] = 0;

	mf[1][0] = 0;
	mf[1][1] = cot * scale;
	mf[1][2] = 0;
	mf[1][3] = 0;

	mf[2][0] = 0;
	mf[2][1] = 0;
	mf[2][2] = (near + far) / (near - far) * scale;
	mf[2][3] = -scale;

	mf[3][0] = 0;
	mf[3][1] = 0;
	mf[3][2] = (2.0f * near * far) / (near - far) * scale;
	mf[3][3] = 0;

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
