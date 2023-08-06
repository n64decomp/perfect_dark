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

}

void func00047550(struct asistream_4f64 *arg0, s32 arg1, struct asistream_4f64 *arg2, struct asistream_4f64 *arg3)
{

}
