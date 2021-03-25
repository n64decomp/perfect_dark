#ifndef _ULTRA64_GU_H_
#define _ULTRA64_GU_H_

#define GU_PI 3.1415926

#define	FTOFIX32(x)	(long)((x) * (float)0x00010000)
#define	FIX32TOF(x)	((float)(x) * (1.0f / (float)0x00010000))
#define	FTOFRAC8(x)	((int) MIN(((x) * (128.0f)), 127.0f) & 0xff)

/* Functions */

void guPerspectiveF(float mf[4][4], u16 *perspNorm, float fovy, float aspect,
                    float near, float far, float scale);
void guPerspective(Mtx *m, u16 *perspNorm, float fovy, float aspect, float near,
                   float far, float scale);
void guOrtho(Mtx *m, float left, float right, float bottom, float top,
             float near, float far, float scale);
void guTranslate(Mtx *m, float x, float y, float z);
void guRotate(Mtx *m, float a, float x, float y, float z);
void guScale(Mtx *m, float x, float y, float z);
void guMtxF2L(float mf[4][4], Mtx *m);
void guMtxIdent(Mtx *m);
void guMtxIdentF(float mf[4][4]);
void guMtxL2F(float mf[4][4], Mtx *m);
void guNormalize(float *, float *, float *);
void guAlignF(float mf[4][4], float a, float x, float y, float z);

void guLookAt(Mtx *m, float xEye, float yEye, float zEye,
		float xAt,  float yAt,  float zAt,
		float xUp,  float yUp,  float zUp);

signed short coss(unsigned short x);
signed short sins(unsigned short x);

/* Used only in Fast3DEX2 */
void guLookAtReflect (Mtx *m, LookAt *l, float xEye, float yEye, float zEye,
                    float xAt,  float yAt,  float zAt,
                    float xUp,  float yUp,  float zUp);
#endif
