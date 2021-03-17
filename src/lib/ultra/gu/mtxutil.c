#include <ultra64.h>

void guMtxF2L(f32 mf[4][4], Mtx *m)
{
	int	i, j;
	int	e1, e2;
	int	*ai, *af;

	ai = (int *) &m->m[0][0];
	af = (int *) &m->m[2][0];

	for (i = 0; i < 4; i++) {
		for (j = 0; j < 2; j++) {
			e1 = FTOFIX32(mf[i][j * 2]);
			e2 = FTOFIX32(mf[i][j * 2 + 1]);

			*(ai++) = (e1 & 0xffff0000) | ((e2 >> 16) & 0xffff);
			*(af++) = ((e1 << 16) & 0xffff0000) | (e2 & 0xffff);
		}
	}
}

void guMtxIdentF(float mf[4][4])
{
	int	i, j;

	for (i = 0; i < 4; i++) {
		for (j = 0; j < 4; j++) {
			mf[i][j] = i == j ? 1 : 0;
		}
	}
}

void guMtxIdent(Mtx *m)
{
	float mf[4][4];

	guMtxIdentF(mf);

	guMtxF2L(mf, m);
}

void guMtxL2F(float mf[4][4], Mtx *m)
{
	int i, j;
	unsigned int e1,e2;
	unsigned int *ai,*af;
	int q1,q2;

	ai = (unsigned int *) &m->m[0][0];
	af = (unsigned int *) &m->m[2][0];

	for (i = 0; i < 4; i++) {
		for (j = 0; j < 2; j++) {
			e1 = (*ai & 0xffff0000) | ((*af >> 16) & 0xffff);
			e2 = ((*(ai++) << 16) & 0xffff0000) | (*(af++) & 0xffff);
			q1 = *((int *) &e1);
			q2 = *((int *) &e2);

			mf[i][j*2] = FIX32TOF(q1);
			mf[i][j*2+1] = FIX32TOF(q2);
		}
	}
}
