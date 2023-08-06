#include <ultra64.h>
#include "internal.h"
#include "mp3.h"
#include "data.h"
#include "platform.h"

extern struct mp3decfourbytes *var8009c650[];

s32 mp3util000461c0(u8 *buffer, s32 *a2, s32 a3, struct mp3decfourbytes *v8, s32 t0)
{
	s32 v4 = t0;
	s32 v5 = *buffer;
	s32 v6 = (a3 << 8) + (u8)(((v5 << 8) | (u32)buffer[1]) >> (8 - (v4 & 7)));
	if (*(u8 *)(var8005f6fc + v6)) {
		return *(u8 *)(var8005f6f8 + v6) & 0xF;
	}
	u32 v9 = 0x80u >> (v4 & 7);

	do {
		s32 v10;
		if ((v5 & v9) != 0) {
			v10 = v8->bytes[1];
		} else {
			v10 = v8->bytes[0];
		}
		v9 >>= 1;
		v8 += v10;
		if (!v9) {
			v9 = 128;
			v5 = *++buffer;
		}
		++v4;
	} while (v8->unk02 == -1);

	return v8->unk02;
}

s32 mp3util00046290(u32 *ptr, u8 s1, u8 t0)
{
	return *ptr << (t0 & 7) >> (32 - s1);
}

s32 mp3utilGetBits(u8 *buffer, s32 *count, s32 numbits)
{
	const s32 result = PD_BE32(*(u32 *)(buffer + (*count >> 3))) << (*count & 7) >> (32 - numbits);
	*count += numbits;
	return result;
}

s32 mp3util000462f8(u8 *arg0, s32 *arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s16 **arg6, u8 **arg7)
{
	s8 cVar1;
	u32 uVar2;
	u32 uVar3;
	s32 *piVar4;
	u32 uVar5;
	s16 *puVar6;
	u8 *puVar7;
	s32 iVar8;

	struct mp3decfourbytes *s0 = var8009c650[arg2];

	uVar5 = *arg1;
	puVar6 = (s16 *)*arg6;
	puVar7 = (u8 *)*arg7;
	piVar4 = (s32 *)(arg0 + (uVar5 >> 3));
	iVar8 = -arg3;

	while (iVar8 = arg5 + iVar8, iVar8 > 0) {
		uVar2 = mp3util000461c0((u8 *)piVar4, arg1, arg2, s0, uVar5);
		if ((arg4 != 0) && (uVar2 == 0xf)) {
			uVar2 = mp3util00046290(piVar4, arg4, uVar5);
			uVar2 = uVar2 + 0xf;
		}
		if (uVar2 == 0) {
			*puVar7 = 0;
		} else {
			cVar1 = *(s8 *)piVar4;
			uVar3 = uVar5 & 7;
			piVar4 = (s32 *)((u8 *)piVar4 + (uVar3 + 1 >> 3));
			uVar5 = uVar5 + 1;
			if (((u32)cVar1 >> (7 - uVar3 & 0x1f) & 1) == 0) {
				*puVar7 = 0;
			} else {
				*puVar7 = 1;
			}
		}
		if ((arg4 != 0) && (iVar8 == 0xf)) {
			uVar3 = mp3util00046290(piVar4, arg4, uVar5);
			iVar8 = uVar3 + 0xf;
		}
		*puVar6 = (s16)uVar2;
		puVar6[1] = (s16)iVar8;
		puVar6 = puVar6 + 2;
		if (iVar8 == 0) {
			puVar7[1] = 0;
		} else {
			cVar1 = *(s8 *)piVar4;
			uVar2 = uVar5 & 7;
			piVar4 = (s32 *)((u8 *)piVar4 + (uVar2 + 1 >> 3));
			uVar5 = uVar5 + 1;
			if (((u32)cVar1 >> (7 - uVar2 & 0x1f) & 1) == 0) {
				puVar7[1] = 0;
			} else {
				puVar7[1] = 1;
			}
		}
		arg3 = arg3 + 2;
		puVar7 = puVar7 + 2;
		iVar8 = -arg3;
	}

	*arg1 = uVar5;
	*arg6 = puVar6;
	*arg7 = puVar7;

	return arg3;
}

s32 mp3util000464a8(u8 *arg0, s32 *arg1, s32 arg2, s32 arg3, s32 arg4, s16 **arg5, u8 **arg6)
{
	u32 uVar1;
	u32 uVar2;
	s32 *piVar3;
	s32 iVar4;
	u32 uVar5;
	u32 uVar6;
	u32 uVar7;
	u32 uVar8;
	u32 uVar9;
	s16 *puVar10;
	u8 *puVar11;

	struct mp3decfourbytes *s0 = var8009c650[arg2];

	uVar5 = *arg1;
	puVar10 = *arg5;
	puVar11 = *arg6;
	piVar3 = (s32 *)(arg0 + (uVar5 >> 3));

	if (((s32)(arg4 - uVar5) > 0) && (iVar4 = arg3, arg3 + -0x240 < 0)) {
		do {
			uVar1 = mp3util000461c0((u8 *)piVar3, arg1, arg2, s0, uVar5);
			uVar6 = uVar1 >> 3 & 1;
			uVar7 = uVar1 >> 2 & 1;
			uVar8 = uVar1 >> 1 & 1;
			uVar1 = uVar1 & 1;
			*puVar10 = (s16)uVar6;
			puVar10[1] = (s16)uVar7;
			puVar10[2] = (s16)uVar8;
			puVar10[3] = (s16)uVar1;
			uVar2 = mp3util00046290(piVar3, 4, uVar5);
			uVar9 = 3;
			*puVar11 = (u8)uVar2;
			if (uVar6 != 0) {
				uVar6 = uVar6 & uVar2 >> 3;
				uVar9 = 2;
			}
			*puVar11 = (u8)uVar6;
			if (uVar7 != 0) {
				uVar7 = uVar7 & uVar2 >> uVar9;
				uVar9 = uVar9 - 1;
			}
			puVar11[1] = (u8)uVar7;
			if (uVar8 != 0) {
				uVar8 = uVar8 & uVar2 >> (uVar9 & 0x1f);
				uVar9 = uVar9 - 1;
			}
			puVar11[2] = (u8)uVar8;
			if (uVar1 != 0) {
				uVar1 = uVar1 & uVar2 >> (uVar9 & 0x1f);
				uVar9 = uVar9 - 1;
			}
			puVar11[3] = (u8)uVar1;
			uVar1 = uVar5 & 7;
			uVar5 = uVar5 - (uVar9 + 1);
			if ((s32)(uVar1 - (uVar9 + 1)) < 0) {
				piVar3 = (s32 *)((u8 *)piVar3 - 1);
			}
			puVar10 = puVar10 + 4;
			puVar11 = puVar11 + 4;
			arg3 = iVar4 + 4;
		} while ((iVar4 + -0x23c < 0) && (iVar4 = arg3, (s32)(arg4 - uVar5) > 0));
	}

	*arg1 = uVar5;
	*arg5 = puVar10;
	*arg6 = puVar11;

	return arg4;
}

void func00046650(struct asistream_4f64 *arg0, s32 arg1, struct asistream_4f64 *arg2, struct asistream_4f64 *arg3, void *arg4)
{
	f32 fVar1;
	f32 fVar2;
	f32 fVar3;
	f32 fVar4;
	f32 fVar5;
	f32 fVar6;
	f32 fVar7;
	f32 fVar8;
	f32 fVar9;
	f32 fVar10;
	f32 fVar11;
	f32 fVar12;
	f32 fVar13;
	f32 fVar14;
	f32 fVar15;
	f32 fVar16;
	f32 fVar17;
	f32 fVar18;
	f32 fVar19;
	f32 fVar20;
	f32 fVar21;
	f32 fVar22;
	f32 fVar23;
	f32 fVar24;
	f32 fVar25;
	f32 fVar26;
	f32 fVar27;

	// TODO: can't be arsed to figure out proper types for now

	f32 *param1 = (f32 *)arg0;
	f32 *param3 = (f32 *)arg2;
	f32 *param4 = (f32 *)arg3;
	f32 *param5 = (f32 *)arg4;

	fVar17 = param1[0x10];
	param1[0x10] = param1[0xf] + fVar17;
	param1[0x11] = fVar17 + param1[0x11];
	fVar17 = param1[0xe];
	param1[0xe] = param1[0xd] + fVar17;
	param1[0xf] = fVar17 + param1[0xf];
	fVar17 = param1[0xc];
	param1[0xc] = param1[0xb] + fVar17;
	param1[0xd] = fVar17 + param1[0xd];
	fVar17 = param1[10];
	param1[10] = param1[9] + fVar17;
	param1[0xb] = fVar17 + param1[0xb];
	fVar17 = param1[8];
	param1[8] = param1[7] + fVar17;
	param1[9] = fVar17 + param1[9];
	fVar17 = param1[6];
	param1[6] = param1[5] + fVar17;
	param1[7] = fVar17 + param1[7];
	fVar17 = param1[4];
	param1[4] = param1[3] + fVar17;
	param1[5] = fVar17 + param1[5];
	fVar17 = param1[2];
	param1[2] = param1[1] + fVar17;
	param1[3] = fVar17 + param1[3];
	param1[1] = *param1 + param1[1];
	fVar17 = param1[0xf];
	param1[0xf] = param1[0xd] + fVar17;
	param1[0x11] = fVar17 + param1[0x11];
	fVar17 = param1[0xb];
	param1[0xb] = param1[9] + fVar17;
	param1[0xd] = fVar17 + param1[0xd];
	fVar17 = param1[7];
	param1[7] = param1[5] + fVar17;
	param1[9] = fVar17 + param1[9];
	fVar17 = param1[3];
	param1[3] = param1[1] + fVar17;
	param1[5] = fVar17 + param1[5];
	fVar1 = *param1 + *param1;
	fVar17 = fVar1 + param1[0xc];
	fVar6 = param1[4] * 1.879385 + param1[8] * 1.532089 + param1[0x10] * 0.3472964 + fVar17;
	fVar7 = param1[4] * -0.3472964 + param1[8] * -1.879385 + param1[0x10] * 1.532089 + fVar17;
	fVar17 = param1[4] * -1.532089 + param1[8] * 0.3472964 + param1[0x10] * -1.879385 + fVar17;
	fVar18 = param1[0xc];
	fVar2 = ((((fVar1 + param1[4]) - param1[8]) - fVar18) - fVar18) - param1[0x10];
	fVar3 = (((*param1 - param1[4]) + param1[8]) - fVar18) + param1[0x10];
	fVar8 = param1[2] * 1.969615 + param1[10] * 1.285575 + param1[0xe] * 0.6840403 +
					param1[6] * 1.732051;
	fVar1 = -(param1[6] * 1.732051);
	fVar9 = param1[2] * 1.285575 + param1[10] * -0.6840403 + param1[0xe] * 1.969615 + fVar1;
	fVar1 = param1[2] * 0.6840403 + param1[10] * 1.969615 + param1[0xe] * -1.285575 + fVar1;
	fVar10 = ((param1[2] - param1[10]) - param1[0xe]) * 1.732051;
	fVar4 = param1[1] + param1[1];
	fVar18 = fVar4 + param1[0xd];
	fVar11 = param1[5] * 1.879385 + param1[9] * 1.532089 + param1[0x11] * 0.3472964 + fVar18;
	fVar12 = param1[5] * -0.3472964 + param1[9] * -1.879385 + param1[0x11] * 1.532089 + fVar18;
	fVar18 = param1[5] * -1.532089 + param1[9] * 0.3472964 + param1[0x11] * -1.879385 + fVar18;
	fVar19 = param1[0xd];
	fVar5 = ((((fVar4 + param1[5]) - param1[9]) - fVar19) - fVar19) - param1[0x11];
	fVar13 = param1[3] * 1.969615 + param1[0xb] * 1.285575 + param1[0xf] * 0.6840403 +
						param1[7] * 1.732051;
	fVar4 = -(param1[7] * 1.732051);
	fVar14 = param1[3] * 1.285575 + param1[0xb] * -0.6840403 + param1[0xf] * 1.969615 + fVar4;
	fVar4 = param1[3] * 0.6840403 + param1[0xb] * 1.969615 + param1[0xf] * -1.285575 + fVar4;
	fVar15 = ((param1[3] - param1[0xb]) - param1[0xf]) * 1.732051;
	fVar16 = fVar6 + fVar8;
	fVar20 = (fVar11 + fVar13) * 0.5019099;
	fVar24 = (fVar16 + fVar20) * -0.2502382;
	fVar16 = (fVar16 - fVar20) * -5.731396;
	fVar20 = fVar2 + fVar10;
	fVar21 = (fVar5 + fVar15) * 0.5176381;
	fVar25 = (fVar20 + fVar21) * -0.2521572;
	fVar20 = (fVar20 - fVar21) * -1.915324;
	fVar21 = fVar7 + fVar9;
	fVar22 = (fVar12 + fVar14) * 0.551689;
	fVar26 = (fVar21 + fVar22) * -0.2560699;
	fVar21 = (fVar21 - fVar22) * -1.155057;
	fVar22 = fVar17 + fVar1;
	fVar23 = (fVar18 + fVar4) * 0.6103873;
	fVar27 = (fVar22 + fVar23) * -0.2621323;
	fVar22 = (fVar22 - fVar23) * -0.8313774;
	fVar17 = fVar17 - fVar1;
	fVar1 = (fVar18 - fVar4) * 0.8717234;
	fVar23 = (fVar17 + fVar1) * -0.2818455;
	fVar17 = (fVar17 - fVar1) * -0.5414202;
	fVar7 = fVar7 - fVar9;
	fVar1 = (fVar12 - fVar14) * 1.183101;
	fVar9 = (fVar7 + fVar1) * -0.2964223;
	fVar1 = (fVar7 - fVar1) * -0.4652897;
	fVar2 = fVar2 - fVar10;
	fVar18 = (fVar5 - fVar15) * 1.931852;
	fVar10 = (fVar2 + fVar18) * -0.3151181;
	fVar18 = (fVar2 - fVar18) * -0.4106699;
	fVar6 = fVar6 - fVar8;
	fVar4 = (fVar11 - fVar13) * 5.736856;
	fVar8 = (fVar6 + fVar4) * -0.3390854;
	fVar4 = (fVar6 - fVar4) * -0.3700468;
	fVar2 = ((((param1[1] - param1[5]) + param1[9]) - fVar19) + param1[0x11]) * 0.7071068;
	fVar5 = (fVar3 + fVar2) * -0.5411961;
	fVar2 = (fVar3 - fVar2) * -1.306563;
	if ((arg1 & 1) == 0) {
		*param3 = -fVar4 * *param5 + *param4;
		param3[1] = -fVar18 * param5[1] + param4[1];
		param3[2] = -fVar1 * param5[2] + param4[2];
		param3[3] = -fVar17 * param5[3] + param4[3];
		param3[4] = -fVar2 * param5[4] + param4[4];
		param3[5] = -fVar22 * param5[5] + param4[5];
		param3[6] = -fVar21 * param5[6] + param4[6];
		param3[7] = -fVar20 * param5[7] + param4[7];
		param3[8] = -fVar16 * param5[8] + param4[8];
		param3[9] = fVar16 * param5[9] + param4[9];
		param3[10] = fVar20 * param5[10] + param4[10];
		param3[0xb] = fVar21 * param5[0xb] + param4[0xb];
		param3[0xc] = fVar22 * param5[0xc] + param4[0xc];
		param3[0xd] = fVar2 * param5[0xd] + param4[0xd];
		param3[0xe] = fVar17 * param5[0xe] + param4[0xe];
		param3[0xf] = fVar1 * param5[0xf] + param4[0xf];
		param3[0x10] = fVar18 * param5[0x10] + param4[0x10];
		param3[0x11] = fVar4 * param5[0x11] + param4[0x11];
	} else {
		*param3 = -fVar4 * *param5 + *param4;
		param3[1] = fVar18 * param5[1] - param4[1];
		param3[2] = -fVar1 * param5[2] + param4[2];
		param3[3] = fVar17 * param5[3] - param4[3];
		param3[4] = -fVar2 * param5[4] + param4[4];
		param3[5] = fVar22 * param5[5] - param4[5];
		param3[6] = -fVar21 * param5[6] + param4[6];
		param3[7] = fVar20 * param5[7] - param4[7];
		param3[8] = -fVar16 * param5[8] + param4[8];
		param3[9] = -fVar16 * param5[9] - param4[9];
		param3[10] = fVar20 * param5[10] + param4[10];
		param3[0xb] = -fVar21 * param5[0xb] - param4[0xb];
		param3[0xc] = fVar22 * param5[0xc] + param4[0xc];
		param3[0xd] = -fVar2 * param5[0xd] - param4[0xd];
		param3[0xe] = fVar17 * param5[0xe] + param4[0xe];
		param3[0xf] = -fVar1 * param5[0xf] - param4[0xf];
		param3[0x10] = fVar18 * param5[0x10] + param4[0x10];
		param3[0x11] = -fVar4 * param5[0x11] - param4[0x11];
	}
	fVar17 = param5[0x13];
	*param4 = fVar8 * param5[0x12];
	param4[1] = fVar10 * fVar17;
	fVar17 = param5[0x15];
	param4[2] = fVar9 * param5[0x14];
	param4[3] = fVar23 * fVar17;
	fVar17 = param5[0x17];
	param4[4] = fVar5 * param5[0x16];
	param4[5] = fVar27 * fVar17;
	fVar17 = param5[0x19];
	param4[6] = fVar26 * param5[0x18];
	param4[7] = fVar25 * fVar17;
	fVar17 = param5[0x1b];
	param4[8] = fVar24 * param5[0x1a];
	param4[9] = fVar24 * fVar17;
	fVar17 = param5[0x1d];
	param4[10] = fVar25 * param5[0x1c];
	param4[0xb] = fVar26 * fVar17;
	fVar17 = param5[0x1f];
	param4[0xc] = fVar27 * param5[0x1e];
	param4[0xd] = fVar5 * fVar17;
	fVar17 = param5[0x21];
	param4[0xe] = fVar23 * param5[0x20];
	param4[0xf] = fVar9 * fVar17;
	fVar17 = param5[0x23];
	param4[0x10] = fVar10 * param5[0x22];
	param4[0x11] = fVar8 * fVar17;
}

void func00047550(struct asistream_4f64 *arg0, s32 arg1, struct asistream_4f64 *arg2, struct asistream_4f64 *arg3)
{
	f32 *pfVar1;
	f32 *pfVar2;
	s32 iVar3;
	f32 fVar4;
	f32 fVar5;
	f32 fVar6;
	f32 fVar7;
	f32 fVar8;
	f32 fVar9;
	f32 fVar10;
	f32 fVar11;
	f32 fVar12;
	f32 locald0[52];

	// TODO: can't be arsed to figure out proper types
	f32 *param1 = (f32 *)arg0;
	f32 *param3 = (f32 *)arg2;
	f32 *param4 = (f32 *)arg3;

	pfVar1 = locald0;
	for (s32 i = 0; i < ARRAYCOUNT(locald0); i += 4) {
		pfVar1[0] = 0.0;
		pfVar1[1] = 0.0;
		pfVar1[2] = 0.0;
		pfVar1[3] = 0.0;
		pfVar1 = pfVar1 + 4;
	}
	pfVar2 = locald0 + 0x10;
	iVar3 = 3;
	pfVar1 = pfVar2;
	do {
		param1[5] = param1[5] + param1[4];
		param1[4] = param1[4] + param1[3];
		param1[3] = param1[3] + param1[2];
		param1[2] = param1[2] + param1[1];
		param1[1] = param1[1] + *param1;
		param1[5] = param1[5] + param1[3];
		param1[3] = param1[3] + param1[1];
		fVar11 = *param1 + param1[4] * 0.5;
		fVar4 = *param1 - param1[4];
		fVar5 = fVar11 + param1[2] * 0.8660254;
		fVar11 = fVar11 - param1[2] * 0.8660254;
		fVar12 = param1[1] + param1[5] * 0.5;
		fVar6 = (fVar12 - param1[3] * 0.8660254) * 1.931852;
		fVar9 = (param1[1] - param1[5]) * 0.7071068;
		fVar12 = (fVar12 + param1[3] * 0.8660254) * 0.5176381;
		fVar7 = (fVar5 + fVar12) * 0.5043145;
		fVar10 = (fVar4 + fVar9) * 0.5411961;
		fVar8 = (fVar11 + fVar6) * 0.6302362;
		fVar4 = (fVar4 - fVar9) * 1.306563;
		fVar12 = (fVar5 - fVar12) * 3.830649;
		fVar5 = (fVar11 - fVar6) * 0.8213398 * 1.0;
		pfVar1[6] = pfVar1[6] + fVar5 * 0.1305262;
		pfVar1[7] = pfVar1[7] + fVar4 * 0.3826834;
		pfVar1[8] = pfVar1[8] + fVar12 * 0.6087614;
		pfVar1[9] = pfVar1[9] + fVar12 * -0.7933533;
		pfVar1[10] = pfVar1[10] + fVar4 * -0.9238795;
		pfVar1[0xb] = pfVar1[0xb] + fVar5 * -0.9914449;
		pfVar1[0xc] = pfVar1[0xc] + fVar8 * -0.9914449;
		pfVar1[0xd] = pfVar1[0xd] + fVar10 * -0.9238795;
		pfVar1[0xe] = pfVar1[0xe] + fVar7 * -0.7933533;
		pfVar1[0xf] = pfVar1[0xf] + fVar7 * -0.6087614;
		pfVar1[0x10] = pfVar1[0x10] + fVar10 * -0.3826834;
		pfVar1[0x11] = pfVar1[0x11] + fVar8 * -0.1305262;
		param1 = param1 + 6;
		pfVar1 = pfVar1 + 6;
		iVar3 = iVar3 + -1;
	} while (iVar3 != 0);
	if ((arg1 & 1) == 0) {
		iVar3 = 0x12;
		pfVar1 = param4;
		do {
			*param3 = *pfVar2 + *pfVar1;
			param3 = param3 + 1;
			pfVar1 = pfVar1 + 1;
			pfVar2 = pfVar2 + 1;
			iVar3 = iVar3 + -1;
		} while (iVar3 != 0);
	} else {
		iVar3 = 9;
		pfVar1 = param4;
		do {
			fVar4 = pfVar2[1];
			fVar5 = pfVar1[1];
			*param3 = *pfVar2 + *pfVar1;
			param3[1] = -fVar4 - fVar5;
			param3 = param3 + 2;
			pfVar1 = pfVar1 + 2;
			pfVar2 = pfVar2 + 2;
			iVar3 = iVar3 + -1;
		} while (iVar3 != 0);
	}
	pfVar1 = locald0 + 0x22;
	iVar3 = 0x12;
	do {
		*param4 = *pfVar1;
		param4 = param4 + 1;
		pfVar1 = pfVar1 + 1;
		iVar3 = iVar3 + -1;
	} while (iVar3 != 0);
}
