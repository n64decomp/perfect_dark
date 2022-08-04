#include <ultra64.h>
#include "lib/sched.h"
#include "constants.h"
#include "game/camera.h"
#include "game/dlights.h"
#include "game/env.h"
#include "game/game_0b2150.h"
#include "game/tex.h"
#include "game/sky.h"
#include "game/game_13c510.h"
#include "game/bg.h"
#include "game/stagetable.h"
#include "game/room.h"
#include "bss.h"
#include "lib/vi.h"
#include "lib/mtx.h"
#include "data.h"
#include "types.h"

u8 *var800a41a0;
u32 var800a41a4;
u32 var800a41a8;
u32 var800a41ac;

void func0f13c510(void)
{
	struct bootbufferthing *thing = bbufGetIndex0Buffer();
	s32 i;

	for (i = 0; i < 120; i++) {
		thing->unk00[0].unk00[i].unk00 = 0;
	}
}

void func0f13c54c(void)
{
	bbufIncIndex0();
	bbufIncIndex1();
}

u16 func0f13c574(f32 arg0)
{
	u32 value = arg0 * 8.0f;
	u32 left;
	u32 right = value;

	if (value > 0x3f800) {
		right = value & 0x7ff;
		right &= 0x7ff;
		left = 7;
	} else if (value > 0x3f000) {
		right = value & 0x7ff;
		right &= 0x7ff;
		left = 6;
	} else if (value > 0x3e000) {
		right = (value >> 1) & 0x7ff;
		right &= 0x7ff;
		left = 5;
	} else if (value > 0x3c000) {
		right = (value >> 2) & 0x7ff;
		right &= 0x7ff;
		left = 4;
	} else if (value > 0x38000) {
		right = (value >> 3) & 0x7ff;
		right &= 0x7ff;
		left = 3;
	} else if (value > 0x30000) {
		right = (value >> 4) & 0x7ff;
		right &= 0x7ff;
		left = 2;
	} else if (value > 0x20000) {
		right = (value >> 5) & 0x7ff;
		right &= 0x7ff;
		left = 1;
	} else {
		right = (value >> 6) & 0x7ff;
		right &= 0x7ff;
		left = 0;
	}

	return left << 13 | (right << 2);
}

s32 func0f13c710(f32 arg0)
{
	if (arg0 > 0.0f) {
		if (arg0 > 2147483520.0f) {
			arg0 = 2147483520;
		}
	} else {
		if (arg0 < -2147483520) {
			arg0 = -2147483520;
		}
	}

	return arg0;
}

void lightsCalculateGlareBrightness(s32 roomnum)
{
	s32 i;
	s32 j;
	s32 k;
	s32 l;
	f32 f0;
	s32 numlights;
	f32 viewwidth;
	f32 viewheight;
	f32 viewleft;
	f32 viewtop;
	u8 *s1;
	f32 x;
	f32 y;
	f32 f16;
	f32 f20;
	s32 xi;
	s32 yi;
	f32 sp190;
	f32 brightnessfrac;
	f32 thisfrac;
	f32 tmp;
	f32 tmp2;
	f32 tmp3;
	f32 sp178;
	Mtxf sp138;
	Mtxf spf8;
	struct coord spec;
	f32 spdc[4];
	struct coord origin;
	struct coord spc4;
	struct light *roomlights;
	s32 index;
	struct bootbufferthing *spb8 = bbufGetIndex0Buffer();
	struct coord *campos = &g_Vars.currentplayer->cam_pos;
	struct bootbufferthingdeep *ptr;

	if (g_Rooms[roomnum].gfxdata != NULL && g_Rooms[roomnum].loaded240) {
		numlights = g_Rooms[roomnum].gfxdata->numlights;

		if (numlights != 0) {
			roomlights = (struct light *)&g_BgLightsFileData[g_Rooms[roomnum].gfxdata->lightsindex * 0x22];
			s1 = &var800a41a0[g_Rooms[roomnum].gfxdata->lightsindex * 3];

			room0f166a6c(&sp138, roomnum);
			mtx00015f88(currentPlayerGetScaleBg2Gfx(), &sp138);
			mtx4MultMtx4(camGetMtxF006c(), &sp138, &spf8);

			viewwidth = viGetViewWidth();
			viewheight = viGetViewHeight();
			viewleft = viGetViewLeft();
			viewtop = viGetViewTop();

			for (i = 0; i < numlights; i++) {
				origin.x = 0.0f;
				origin.y = 0.0f;
				origin.z = 0.0f;

				for (j = 0; j < 4; j++) {
					origin.x += roomlights[i].bbox[j].x;
					origin.y += roomlights[i].bbox[j].y;
					origin.z += roomlights[i].bbox[j].z;
				}

				origin.x /= 4.0f;
				origin.y /= 4.0f;
				origin.z /= 4.0f;

				for (j = 0; j != 3; j++) {
					spc4.f[j] = origin.f[j] - (campos->f[j] - g_BgRooms[roomnum].pos.f[j]);
				}

				s1[i * 3 + 1] = 0;
				s1[i * 3 + 2] = 0;

				tmp = roomlights[i].unk07 * roomlights[i].unk07 + roomlights[i].unk08 * roomlights[i].unk08 + roomlights[i].unk09 * roomlights[i].unk09;
				f16 = spc4.f[0] * spc4.f[0] + spc4.f[1] * spc4.f[1] + spc4.f[2] * spc4.f[2];

				if (tmp > 0.0001f && f16 > 0.0001f) {
					sp190 = -((roomlights[i].unk07 * spc4.f[0] + roomlights[i].unk08 * spc4.f[1] + roomlights[i].unk09 * spc4.f[2]) / sqrtf(tmp * f16));

					if (sp190 > 0.4f) {
						sp190 = 0.4f;
					}

					sp190 *= 2.5f;
				} else {
					sp190 = 0.0f;
				}

				if (sp190 > 0.0f) {
					for (l = 3; l >= 0; l--) {
						spdc[l] = origin.f[0] * spf8.m[0][l] + origin.f[1] * spf8.m[1][l] + origin.f[2] * spf8.m[2][l] + spf8.m[3][l];

						if (l == 3 && spdc[l] <= 0.0f) {
							break;
						}
					}

					if (spdc[3] > 0.0001f) {
						f20 = 1.0f / spdc[3];
						x = func0f13c710(viewleft + (1.0f + spdc[0] * f20) * (viewwidth * 0.5f));
						y = func0f13c710(viewtop + (1.0f - spdc[1] * f20) * (viewheight * 0.5f));
						f0 = (spdc[2] * f20 * 511.0f + 511.0f) * 32.0f;

						if (f0 < 32576.0f) {
							brightnessfrac = 1.0f;
							tmp2 = (brightnessfrac - 1.00f);

							if (x <= 10.0f + viewleft) {
								brightnessfrac = 0.0f;
							} else if (y <= 30.0f + viewtop) {
								brightnessfrac = 0.0f;
							} else if (x >= -10.0f + viewleft + viewwidth) {
								brightnessfrac = 0.0f;
							} else if (y >= -30.0f + viewtop + viewheight) {
								brightnessfrac = 0.0f;
							}

							sp178 = 1.0f - 2.0f * tmp2;

							if (brightnessfrac != 0.0f) {
								brightnessfrac = 1.0f;

								if (x < viewleft + 90.0f) {
									thisfrac = (x - (10.0f + viewleft)) / 80.0f;

									if (thisfrac < brightnessfrac) {
										brightnessfrac = thisfrac;
									}
								}

								if (y < viewtop + 100.0f) {
									thisfrac = (y - (viewtop + 30.0f)) / 70.0f;

									if (thisfrac < brightnessfrac) {
										brightnessfrac = thisfrac;
									}
								}

								if (x > viewleft + viewwidth - 90.0f) {
									thisfrac = (viewleft + viewwidth - 10.0f - x) / 80.0f;

									if (thisfrac < brightnessfrac) {
										brightnessfrac = thisfrac;
									}
								}

								if (y > viewtop + viewheight - 100.0f) {
									thisfrac = (viewtop + viewheight - 30.0f - y) / 70.0f;

									if (thisfrac < brightnessfrac) {
										brightnessfrac = thisfrac;
									}
								}
							}

							tmp3 = 32300.0f - f0;

							if (tmp3 < 0.0f) {
								tmp3 = 0.0f;
							}

							if (tmp3 > 1300.0f) {
								tmp3 = 1300.0f;
							}

							tmp3 *= 1.0f / 1300.0f;

							if (2.0f * tmp2 > 1.0f) {
								sp178 = 0.0f;
							}

							s1[i * 3 + 1] = sp190 * 255.0f * sp178;
							s1[i * 3 + 2] = brightnessfrac * tmp3 * sp190 * 64.0f * 1;
						}
					}
				}

				if (s1[i * 3 + 1] > 0) {
					for (j = 0; j < 4; j++) {
						spec.x = origin.x + (roomlights[i].bbox[j].x - origin.x) * 0.6f;
						spec.y = origin.y + (roomlights[i].bbox[j].y - origin.y) * 0.6f;
						spec.z = origin.z + (roomlights[i].bbox[j].z - origin.z) * 0.6f;

						for (k = 3; k >= 0; k--) {
							spdc[k] = spec.f[0] * spf8.m[0][k] + spec.f[1] * spf8.m[1][k] + spec.f[2] * spf8.m[2][k] + spf8.m[3][k];

							if (k == 3 && spdc[k] <= 0.0f) {
								break;
							}
						}

						if (spdc[3] > 0.0f) {
							f20 = 1.0f / spdc[3];

							if (f20 > 9999.0f) {
								f20 = 9999.0f;
							}

							if (f20 < -9999.0f) {
								f20 = -9999.0f;
							}

							xi = func0f13c710(viewleft + (1.0f + spdc[0] * f20) * (viewwidth * 0.5f));
							yi = func0f13c710(viewtop + (1.0f - spdc[1] * f20) * (viewheight * 0.5f));
							f0 = (spdc[2] * f20 * 511.0f + 511.0f) * 32.0f;

							if (var800844f0
									&& xi >= (s32)viewleft
									&& xi < (s32)(viewleft + viewwidth)
									&& yi >= (s32)viewtop
									&& yi < (s32)(viewtop + viewheight)
									&& f0 < 32576.0f) {
								index = envGetCurrent()->numsuns;
								index *= 8;
								ptr = &spb8->unk00[0].unk00[index];

								while (ptr->unk00) {
									index++;
									ptr++;
								}

								if (index < 120) {
									ptr->unk04 = func0f13c574(f0) >> 2;
									ptr->unk08 = &var800844f0[viGetWidth() * yi + xi];
									ptr->light = &roomlights[i];
									ptr->unk00 = 2;
									ptr->unk0c.u16_2 = xi;
									ptr->unk0c.u16_1 = yi;
								}
							}
						}
					}
				}
			}
		}
	}
}

u8 func0f13d3c4(u8 arg0, u8 arg1)
{
	if (arg1 >= arg0 + 7) {
		return arg0 + 7;
	}

	if (arg1 <= arg0 - 7) {
		return arg0 - 7;
	}

	return arg1;
}

Gfx *func0f13d40c(Gfx *gdl)
{
	struct stagetableentry *stage = stageGetCurrent();

	texSelect(&gdl, &g_TexLightGlareConfigs[stage->light_type], 4, 0, 2, 1, NULL);

	gDPSetCycleType(gdl++, G_CYC_1CYCLE);
	gDPSetRenderMode(gdl++, G_RM_CLD_SURF, G_RM_CLD_SURF2);
	gDPSetTextureFilter(gdl++, G_TF_BILERP);
	gDPSetCombineLERP(gdl++,
			0, 0, 0, ENVIRONMENT, TEXEL0, 0, ENVIRONMENT, 0,
			0, 0, 0, ENVIRONMENT, TEXEL0, 0, ENVIRONMENT, 0);
	gDPSetColorDither(gdl++, G_CD_BAYER);
	gDPSetAlphaDither(gdl++, G_AD_PATTERN);
	gDPSetTexturePersp(gdl++, G_TP_NONE);

	return gdl;
}

Gfx *func0f13d54c(Gfx *gdl)
{
	gDPSetTexturePersp(gdl++, G_TP_PERSP);

	return gdl;
}

GLOBAL_ASM(
glabel func0f13d568
.late_rodata
glabel var7f1b59e0
.word 0x3c8efa35
glabel var7f1b59e4
.word 0x4169999a
glabel var7f1b59e8
.word 0x3ecccccd
glabel var7f1b59ec
.word 0x3b808081
glabel var7f1b59f0
.word 0x46d6d800
glabel var7f1b59f4
.word 0x3b808081
glabel var7f1b59f8
.word 0x443b8000
glabel var7f1b59fc
.word 0x3c23d70a
glabel var7f1b5a00
.word 0x3c23d70a
glabel var7f1b5a04
.word 0x3b888889
glabel var7f1b5a08
.word 0x3b888889
glabel var7f1b5a0c
.word 0x3ecccccd
.text
/*  f13d568:	27bdfea0 */ 	addiu	$sp,$sp,-352
/*  f13d56c:	afbf0084 */ 	sw	$ra,0x84($sp)
/*  f13d570:	afbe0080 */ 	sw	$s8,0x80($sp)
/*  f13d574:	afb7007c */ 	sw	$s7,0x7c($sp)
/*  f13d578:	afb60078 */ 	sw	$s6,0x78($sp)
/*  f13d57c:	afb50074 */ 	sw	$s5,0x74($sp)
/*  f13d580:	afb40070 */ 	sw	$s4,0x70($sp)
/*  f13d584:	afb3006c */ 	sw	$s3,0x6c($sp)
/*  f13d588:	afb20068 */ 	sw	$s2,0x68($sp)
/*  f13d58c:	afb10064 */ 	sw	$s1,0x64($sp)
/*  f13d590:	afb00060 */ 	sw	$s0,0x60($sp)
/*  f13d594:	f7be0058 */ 	sdc1	$f30,0x58($sp)
/*  f13d598:	f7bc0050 */ 	sdc1	$f28,0x50($sp)
/*  f13d59c:	f7ba0048 */ 	sdc1	$f26,0x48($sp)
/*  f13d5a0:	f7b80040 */ 	sdc1	$f24,0x40($sp)
/*  f13d5a4:	f7b60038 */ 	sdc1	$f22,0x38($sp)
/*  f13d5a8:	f7b40030 */ 	sdc1	$f20,0x30($sp)
/*  f13d5ac:	afa40160 */ 	sw	$a0,0x160($sp)
/*  f13d5b0:	0c000920 */ 	jal	bbufGetIndex1Buffer
/*  f13d5b4:	afa50164 */ 	sw	$a1,0x164($sp)
/*  f13d5b8:	0040a025 */ 	or	$s4,$v0,$zero
/*  f13d5bc:	0fc00331 */ 	jal	roomGetUnk5c
/*  f13d5c0:	8fa40164 */ 	lw	$a0,0x164($sp)
/*  f13d5c4:	8fa30164 */ 	lw	$v1,0x164($sp)
/*  f13d5c8:	3c0f800a */ 	lui	$t7,%hi(g_Rooms)
/*  f13d5cc:	8def4928 */ 	lw	$t7,%lo(g_Rooms)($t7)
/*  f13d5d0:	000370c0 */ 	sll	$t6,$v1,0x3
/*  f13d5d4:	01c37021 */ 	addu	$t6,$t6,$v1
/*  f13d5d8:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f13d5dc:	01c37023 */ 	subu	$t6,$t6,$v1
/*  f13d5e0:	000e1880 */ 	sll	$v1,$t6,0x2
/*  f13d5e4:	01e31021 */ 	addu	$v0,$t7,$v1
/*  f13d5e8:	8c580014 */ 	lw	$t8,0x14($v0)
/*  f13d5ec:	46000786 */ 	mov.s	$f30,$f0
/*  f13d5f0:	13000004 */ 	beqz	$t8,.L0f13d604
/*  f13d5f4:	00000000 */ 	nop
/*  f13d5f8:	84590002 */ 	lh	$t9,0x2($v0)
/*  f13d5fc:	17200003 */ 	bnez	$t9,.L0f13d60c
/*  f13d600:	00000000 */ 	nop
.L0f13d604:
/*  f13d604:	100002a2 */ 	b	.L0f13e090
/*  f13d608:	8fa20160 */ 	lw	$v0,0x160($sp)
.L0f13d60c:
/*  f13d60c:	0fc595f3 */ 	jal	envGetCurrent
/*  f13d610:	afa300a4 */ 	sw	$v1,0xa4($sp)
/*  f13d614:	9052000b */ 	lbu	$s2,0xb($v0)
/*  f13d618:	241e0002 */ 	addiu	$s8,$zero,0x2
/*  f13d61c:	001260c0 */ 	sll	$t4,$s2,0x3
/*  f13d620:	29810078 */ 	slti	$at,$t4,0x78
/*  f13d624:	10200299 */ 	beqz	$at,.L0f13e08c
/*  f13d628:	01809025 */ 	or	$s2,$t4,$zero
/*  f13d62c:	3c01437f */ 	lui	$at,0x437f
/*  f13d630:	4481e000 */ 	mtc1	$at,$f28
/*  f13d634:	24170014 */ 	addiu	$s7,$zero,0x14
.L0f13d638:
/*  f13d638:	02570019 */ 	multu	$s2,$s7
/*  f13d63c:	2a410078 */ 	slti	$at,$s2,0x78
/*  f13d640:	00008025 */ 	or	$s0,$zero,$zero
/*  f13d644:	02401825 */ 	or	$v1,$s2,$zero
/*  f13d648:	00006812 */ 	mflo	$t5
/*  f13d64c:	028d1021 */ 	addu	$v0,$s4,$t5
/*  f13d650:	8c450010 */ 	lw	$a1,0x10($v0)
/*  f13d654:	10200012 */ 	beqz	$at,.L0f13d6a0
/*  f13d658:	00a02025 */ 	or	$a0,$a1,$zero
/*  f13d65c:	944e0000 */ 	lhu	$t6,0x0($v0)
/*  f13d660:	17ce000f */ 	bne	$s8,$t6,.L0f13d6a0
/*  f13d664:	00000000 */ 	nop
/*  f13d668:	1485000d */ 	bne	$a0,$a1,.L0f13d6a0
/*  f13d66c:	24630001 */ 	addiu	$v1,$v1,0x1
.L0f13d670:
/*  f13d670:	28610078 */ 	slti	$at,$v1,0x78
/*  f13d674:	1020000a */ 	beqz	$at,.L0f13d6a0
/*  f13d678:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f13d67c:	00770019 */ 	multu	$v1,$s7
/*  f13d680:	00007812 */ 	mflo	$t7
/*  f13d684:	028f1021 */ 	addu	$v0,$s4,$t7
/*  f13d688:	94580000 */ 	lhu	$t8,0x0($v0)
/*  f13d68c:	17d80004 */ 	bne	$s8,$t8,.L0f13d6a0
/*  f13d690:	00000000 */ 	nop
/*  f13d694:	8c590010 */ 	lw	$t9,0x10($v0)
/*  f13d698:	5099fff5 */ 	beql	$a0,$t9,.L0f13d670
/*  f13d69c:	24630001 */ 	addiu	$v1,$v1,0x1
.L0f13d6a0:
/*  f13d6a0:	5a000277 */ 	blezl	$s0,.L0f13e080
/*  f13d6a4:	26520001 */ 	addiu	$s2,$s2,0x1
/*  f13d6a8:	afa50140 */ 	sw	$a1,0x140($sp)
/*  f13d6ac:	94ad0000 */ 	lhu	$t5,0x0($a1)
/*  f13d6b0:	8fac0164 */ 	lw	$t4,0x164($sp)
/*  f13d6b4:	3c0f800a */ 	lui	$t7,%hi(g_BgLightsFileData)
/*  f13d6b8:	24010022 */ 	addiu	$at,$zero,0x22
/*  f13d6bc:	158d026d */ 	bne	$t4,$t5,.L0f13e074
/*  f13d6c0:	00005025 */ 	or	$t2,$zero,$zero
/*  f13d6c4:	8def4cd8 */ 	lw	$t7,%lo(g_BgLightsFileData)($t7)
/*  f13d6c8:	3c0c800a */ 	lui	$t4,%hi(var800a41a0)
/*  f13d6cc:	8d8c41a0 */ 	lw	$t4,%lo(var800a41a0)($t4)
/*  f13d6d0:	00af8823 */ 	subu	$s1,$a1,$t7
/*  f13d6d4:	0221001b */ 	divu	$zero,$s1,$at
/*  f13d6d8:	00008812 */ 	mflo	$s1
/*  f13d6dc:	0011c880 */ 	sll	$t9,$s1,0x2
/*  f13d6e0:	02504821 */ 	addu	$t1,$s2,$s0
/*  f13d6e4:	0331c823 */ 	subu	$t9,$t9,$s1
/*  f13d6e8:	0249082a */ 	slt	$at,$s2,$t1
/*  f13d6ec:	3406ffff */ 	dli	$a2,0xffff
/*  f13d6f0:	00004025 */ 	or	$t0,$zero,$zero
/*  f13d6f4:	02403825 */ 	or	$a3,$s2,$zero
/*  f13d6f8:	10200013 */ 	beqz	$at,.L0f13d748
/*  f13d6fc:	032c9821 */ 	addu	$s3,$t9,$t4
/*  f13d700:	00076880 */ 	sll	$t5,$a3,0x2
/*  f13d704:	01a76821 */ 	addu	$t5,$t5,$a3
/*  f13d708:	000d6880 */ 	sll	$t5,$t5,0x2
/*  f13d70c:	028d1021 */ 	addu	$v0,$s4,$t5
.L0f13d710:
/*  f13d710:	94430004 */ 	lhu	$v1,0x4($v0)
/*  f13d714:	24e70001 */ 	addiu	$a3,$a3,0x1
/*  f13d718:	00c02825 */ 	or	$a1,$a2,$zero
/*  f13d71c:	0103082a */ 	slt	$at,$t0,$v1
/*  f13d720:	10200002 */ 	beqz	$at,.L0f13d72c
/*  f13d724:	00602025 */ 	or	$a0,$v1,$zero
/*  f13d728:	3068ffff */ 	andi	$t0,$v1,0xffff
.L0f13d72c:
/*  f13d72c:	0085082a */ 	slt	$at,$a0,$a1
/*  f13d730:	10200002 */ 	beqz	$at,.L0f13d73c
/*  f13d734:	00000000 */ 	nop
/*  f13d738:	3066ffff */ 	andi	$a2,$v1,0xffff
.L0f13d73c:
/*  f13d73c:	14e9fff4 */ 	bne	$a3,$t1,.L0f13d710
/*  f13d740:	24420014 */ 	addiu	$v0,$v0,0x14
/*  f13d744:	02403825 */ 	or	$a3,$s2,$zero
.L0f13d748:
/*  f13d748:	01061023 */ 	subu	$v0,$t0,$a2
/*  f13d74c:	00025843 */ 	sra	$t3,$v0,0x1
/*  f13d750:	29610019 */ 	slti	$at,$t3,0x19
/*  f13d754:	10200002 */ 	beqz	$at,.L0f13d760
/*  f13d758:	00077880 */ 	sll	$t7,$a3,0x2
/*  f13d75c:	240b0019 */ 	addiu	$t3,$zero,0x19
.L0f13d760:
/*  f13d760:	0249082a */ 	slt	$at,$s2,$t1
/*  f13d764:	10200017 */ 	beqz	$at,.L0f13d7c4
/*  f13d768:	01e77821 */ 	addu	$t7,$t7,$a3
/*  f13d76c:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f13d770:	028f1021 */ 	addu	$v0,$s4,$t7
.L0f13d774:
/*  f13d774:	94430002 */ 	lhu	$v1,0x2($v0)
/*  f13d778:	94440004 */ 	lhu	$a0,0x4($v0)
/*  f13d77c:	24e70001 */ 	addiu	$a3,$a3,0x1
/*  f13d780:	3078fffc */ 	andi	$t8,$v1,0xfffc
/*  f13d784:	0018c883 */ 	sra	$t9,$t8,0x2
/*  f13d788:	332cffff */ 	andi	$t4,$t9,0xffff
/*  f13d78c:	008c082a */ 	slt	$at,$a0,$t4
/*  f13d790:	01803025 */ 	or	$a2,$t4,$zero
/*  f13d794:	10200003 */ 	beqz	$at,.L0f13d7a4
/*  f13d798:	00802825 */ 	or	$a1,$a0,$zero
/*  f13d79c:	10000002 */ 	b	.L0f13d7a8
/*  f13d7a0:	01841823 */ 	subu	$v1,$t4,$a0
.L0f13d7a4:
/*  f13d7a4:	00a61823 */ 	subu	$v1,$a1,$a2
.L0f13d7a8:
/*  f13d7a8:	0163082a */ 	slt	$at,$t3,$v1
/*  f13d7ac:	54200003 */ 	bnezl	$at,.L0f13d7bc
/*  f13d7b0:	24420014 */ 	addiu	$v0,$v0,0x14
/*  f13d7b4:	254a0001 */ 	addiu	$t2,$t2,0x1
/*  f13d7b8:	24420014 */ 	addiu	$v0,$v0,0x14
.L0f13d7bc:
/*  f13d7bc:	14e9ffed */ 	bne	$a3,$t1,.L0f13d774
/*  f13d7c0:	a440ffec */ 	sh	$zero,-0x14($v0)
.L0f13d7c4:
/*  f13d7c4:	92640000 */ 	lbu	$a0,0x0($s3)
/*  f13d7c8:	000a1840 */ 	sll	$v1,$t2,0x1
/*  f13d7cc:	306500ff */ 	andi	$a1,$v1,0xff
/*  f13d7d0:	0fc4f4f1 */ 	jal	func0f13d3c4
/*  f13d7d4:	afa300a0 */ 	sw	$v1,0xa0($sp)
/*  f13d7d8:	8fa300a0 */ 	lw	$v1,0xa0($sp)
/*  f13d7dc:	a2620000 */ 	sb	$v0,0x0($s3)
/*  f13d7e0:	28610002 */ 	slti	$at,$v1,0x2
/*  f13d7e4:	54200222 */ 	bnezl	$at,.L0f13e070
/*  f13d7e8:	a2600001 */ 	sb	$zero,0x1($s3)
/*  f13d7ec:	0c002f9d */ 	jal	viGetFovY
/*  f13d7f0:	00000000 */ 	nop
/*  f13d7f4:	3c017f1b */ 	lui	$at,%hi(var7f1b59e0)
/*  f13d7f8:	c42459e0 */ 	lwc1	$f4,%lo(var7f1b59e0)($at)
/*  f13d7fc:	46040302 */ 	mul.s	$f12,$f0,$f4
/*  f13d800:	0c0068f4 */ 	jal	cosf
/*  f13d804:	46006586 */ 	mov.s	$f22,$f12
/*  f13d808:	46000506 */ 	mov.s	$f20,$f0
/*  f13d80c:	0c0068f7 */ 	jal	sinf
/*  f13d810:	4600b306 */ 	mov.s	$f12,$f22
/*  f13d814:	4600a183 */ 	div.s	$f6,$f20,$f0
/*  f13d818:	3c0d800a */ 	lui	$t5,%hi(g_Rooms)
/*  f13d81c:	8dad4928 */ 	lw	$t5,%lo(g_Rooms)($t5)
/*  f13d820:	8fae00a4 */ 	lw	$t6,0xa4($sp)
/*  f13d824:	3c017f1b */ 	lui	$at,%hi(var7f1b59e4)
/*  f13d828:	c42859e4 */ 	lwc1	$f8,%lo(var7f1b59e4)($at)
/*  f13d82c:	01ae7821 */ 	addu	$t7,$t5,$t6
/*  f13d830:	8df80014 */ 	lw	$t8,0x14($t7)
/*  f13d834:	8fa40164 */ 	lw	$a0,0x164($sp)
/*  f13d838:	87190010 */ 	lh	$t9,0x10($t8)
/*  f13d83c:	02392823 */ 	subu	$a1,$s1,$t9
/*  f13d840:	46083602 */ 	mul.s	$f24,$f6,$f8
/*  f13d844:	0fc003d4 */ 	jal	lightIsHealthy
/*  f13d848:	00000000 */ 	nop
/*  f13d84c:	1040000f */ 	beqz	$v0,.L0f13d88c
/*  f13d850:	3c19800a */ 	lui	$t9,%hi(g_Rooms)
/*  f13d854:	3c0c800a */ 	lui	$t4,%hi(g_Rooms)
/*  f13d858:	8d8c4928 */ 	lw	$t4,%lo(g_Rooms)($t4)
/*  f13d85c:	8fad00a4 */ 	lw	$t5,0xa4($sp)
/*  f13d860:	8fa40164 */ 	lw	$a0,0x164($sp)
/*  f13d864:	018d7021 */ 	addu	$t6,$t4,$t5
/*  f13d868:	8dcf0014 */ 	lw	$t7,0x14($t6)
/*  f13d86c:	85f80010 */ 	lh	$t8,0x10($t7)
/*  f13d870:	0fc003ef */ 	jal	lightIsOn
/*  f13d874:	02382823 */ 	subu	$a1,$s1,$t8
/*  f13d878:	10400200 */ 	beqz	$v0,.L0f13e07c
/*  f13d87c:	3c013f80 */ 	lui	$at,0x3f80
/*  f13d880:	4481b000 */ 	mtc1	$at,$f22
/*  f13d884:	1000000d */ 	b	.L0f13d8bc
/*  f13d888:	8fb80140 */ 	lw	$t8,0x140($sp)
.L0f13d88c:
/*  f13d88c:	8f394928 */ 	lw	$t9,%lo(g_Rooms)($t9)
/*  f13d890:	8fac00a4 */ 	lw	$t4,0xa4($sp)
/*  f13d894:	8fa40164 */ 	lw	$a0,0x164($sp)
/*  f13d898:	032c6821 */ 	addu	$t5,$t9,$t4
/*  f13d89c:	8dae0014 */ 	lw	$t6,0x14($t5)
/*  f13d8a0:	85cf0010 */ 	lh	$t7,0x10($t6)
/*  f13d8a4:	0fc00bbe */ 	jal	lightTickBroken
/*  f13d8a8:	022f2823 */ 	subu	$a1,$s1,$t7
/*  f13d8ac:	104001f3 */ 	beqz	$v0,.L0f13e07c
/*  f13d8b0:	3c017f1b */ 	lui	$at,%hi(var7f1b59e8)
/*  f13d8b4:	c43659e8 */ 	lwc1	$f22,%lo(var7f1b59e8)($at)
/*  f13d8b8:	8fb80140 */ 	lw	$t8,0x140($sp)
.L0f13d8bc:
/*  f13d8bc:	24030011 */ 	addiu	$v1,$zero,0x11
/*  f13d8c0:	240100ff */ 	addiu	$at,$zero,0xff
/*  f13d8c4:	97020002 */ 	lhu	$v0,0x2($t8)
/*  f13d8c8:	0002cb03 */ 	sra	$t9,$v0,0xc
/*  f13d8cc:	332c000f */ 	andi	$t4,$t9,0xf
/*  f13d8d0:	01830019 */ 	multu	$t4,$v1
/*  f13d8d4:	00026a03 */ 	sra	$t5,$v0,0x8
/*  f13d8d8:	31ae000f */ 	andi	$t6,$t5,0xf
/*  f13d8dc:	00027903 */ 	sra	$t7,$v0,0x4
/*  f13d8e0:	31f8000f */ 	andi	$t8,$t7,0xf
/*  f13d8e4:	00008812 */ 	mflo	$s1
/*  f13d8e8:	00000000 */ 	nop
/*  f13d8ec:	00000000 */ 	nop
/*  f13d8f0:	01c30019 */ 	multu	$t6,$v1
/*  f13d8f4:	3c0e8007 */ 	lui	$t6,%hi(g_InCutscene)
/*  f13d8f8:	0000a812 */ 	mflo	$s5
/*  f13d8fc:	00000000 */ 	nop
/*  f13d900:	00000000 */ 	nop
/*  f13d904:	03030019 */ 	multu	$t8,$v1
/*  f13d908:	3c03800a */ 	lui	$v1,%hi(g_Vars+0x284)
/*  f13d90c:	0000b012 */ 	mflo	$s6
/*  f13d910:	16210004 */ 	bne	$s1,$at,.L0f13d924
/*  f13d914:	240100ff */ 	addiu	$at,$zero,0xff
/*  f13d918:	16a10002 */ 	bne	$s5,$at,.L0f13d924
/*  f13d91c:	240100ff */ 	addiu	$at,$zero,0xff
/*  f13d920:	12c10006 */ 	beq	$s6,$at,.L0f13d93c
.L0f13d924:
/*  f13d924:	240100ff */ 	addiu	$at,$zero,0xff
/*  f13d928:	16210006 */ 	bne	$s1,$at,.L0f13d944
/*  f13d92c:	02b6c821 */ 	addu	$t9,$s5,$s6
/*  f13d930:	2b210023 */ 	slti	$at,$t9,0x23
/*  f13d934:	50200004 */ 	beqzl	$at,.L0f13d948
/*  f13d938:	240c0001 */ 	addiu	$t4,$zero,0x1
.L0f13d93c:
/*  f13d93c:	10000003 */ 	b	.L0f13d94c
/*  f13d940:	afa000cc */ 	sw	$zero,0xcc($sp)
.L0f13d944:
/*  f13d944:	240c0001 */ 	addiu	$t4,$zero,0x1
.L0f13d948:
/*  f13d948:	afac00cc */ 	sw	$t4,0xcc($sp)
.L0f13d94c:
/*  f13d94c:	8c63a244 */ 	lw	$v1,%lo(g_Vars+0x284)($v1)
/*  f13d950:	8c6d00d8 */ 	lw	$t5,0xd8($v1)
/*  f13d954:	55a0001f */ 	bnezl	$t5,.L0f13d9d4
/*  f13d958:	926d0002 */ 	lbu	$t5,0x2($s3)
/*  f13d95c:	8dce0764 */ 	lw	$t6,%lo(g_InCutscene)($t6)
/*  f13d960:	55c0001c */ 	bnezl	$t6,.L0f13d9d4
/*  f13d964:	926d0002 */ 	lbu	$t5,0x2($s3)
/*  f13d968:	8c620480 */ 	lw	$v0,0x480($v1)
/*  f13d96c:	50400007 */ 	beqzl	$v0,.L0f13d98c
/*  f13d970:	8c791c54 */ 	lw	$t9,0x1c54($v1)
/*  f13d974:	50400017 */ 	beqzl	$v0,.L0f13d9d4
/*  f13d978:	926d0002 */ 	lbu	$t5,0x2($s3)
/*  f13d97c:	804f0037 */ 	lb	$t7,0x37($v0)
/*  f13d980:	55e00014 */ 	bnezl	$t7,.L0f13d9d4
/*  f13d984:	926d0002 */ 	lbu	$t5,0x2($s3)
/*  f13d988:	8c791c54 */ 	lw	$t9,0x1c54($v1)
.L0f13d98c:
/*  f13d98c:	8c7800c4 */ 	lw	$t8,0xc4($v1)
/*  f13d990:	3c0140e0 */ 	lui	$at,0x40e0
/*  f13d994:	03206027 */ 	nor	$t4,$t9,$zero
/*  f13d998:	030c6824 */ 	and	$t5,$t8,$t4
/*  f13d99c:	31ae0001 */ 	andi	$t6,$t5,0x1
/*  f13d9a0:	51c0000c */ 	beqzl	$t6,.L0f13d9d4
/*  f13d9a4:	926d0002 */ 	lbu	$t5,0x2($s3)
/*  f13d9a8:	44815000 */ 	mtc1	$at,$f10
/*  f13d9ac:	926f0002 */ 	lbu	$t7,0x2($s3)
/*  f13d9b0:	460af402 */ 	mul.s	$f16,$f30,$f10
/*  f13d9b4:	4600848d */ 	trunc.w.s	$f18,$f16
/*  f13d9b8:	44189000 */ 	mfc1	$t8,$f18
/*  f13d9bc:	00000000 */ 	nop
/*  f13d9c0:	01f80019 */ 	multu	$t7,$t8
/*  f13d9c4:	00006012 */ 	mflo	$t4
/*  f13d9c8:	a26c0002 */ 	sb	$t4,0x2($s3)
/*  f13d9cc:	00000000 */ 	nop
/*  f13d9d0:	926d0002 */ 	lbu	$t5,0x2($s3)
.L0f13d9d4:
/*  f13d9d4:	44918000 */ 	mtc1	$s1,$f16
/*  f13d9d8:	3c014f80 */ 	lui	$at,0x4f80
/*  f13d9dc:	448d2000 */ 	mtc1	$t5,$f4
/*  f13d9e0:	05a10004 */ 	bgez	$t5,.L0f13d9f4
/*  f13d9e4:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f13d9e8:	44814000 */ 	mtc1	$at,$f8
/*  f13d9ec:	00000000 */ 	nop
/*  f13d9f0:	46083180 */ 	add.s	$f6,$f6,$f8
.L0f13d9f4:
/*  f13d9f4:	3c017f1b */ 	lui	$at,%hi(var7f1b59ec)
/*  f13d9f8:	c42a59ec */ 	lwc1	$f10,%lo(var7f1b59ec)($at)
/*  f13d9fc:	468084a0 */ 	cvt.s.w	$f18,$f16
/*  f13da00:	460a3002 */ 	mul.s	$f0,$f6,$f10
/*  f13da04:	44953000 */ 	mtc1	$s5,$f6
/*  f13da08:	00000000 */ 	nop
/*  f13da0c:	468032a0 */ 	cvt.s.w	$f10,$f6
/*  f13da10:	46120102 */ 	mul.s	$f4,$f0,$f18
/*  f13da14:	4600220d */ 	trunc.w.s	$f8,$f4
/*  f13da18:	44962000 */ 	mtc1	$s6,$f4
/*  f13da1c:	460a0402 */ 	mul.s	$f16,$f0,$f10
/*  f13da20:	44044000 */ 	mfc1	$a0,$f8
/*  f13da24:	46802220 */ 	cvt.s.w	$f8,$f4
/*  f13da28:	4600848d */ 	trunc.w.s	$f18,$f16
/*  f13da2c:	46080182 */ 	mul.s	$f6,$f0,$f8
/*  f13da30:	44059000 */ 	mfc1	$a1,$f18
/*  f13da34:	4600328d */ 	trunc.w.s	$f10,$f6
/*  f13da38:	44065000 */ 	mfc1	$a2,$f10
/*  f13da3c:	0fc49ccd */ 	jal	sky0f127334
/*  f13da40:	00000000 */ 	nop
/*  f13da44:	8fac0164 */ 	lw	$t4,0x164($sp)
/*  f13da48:	3c18800a */ 	lui	$t8,%hi(g_BgRooms)
/*  f13da4c:	8f184cc4 */ 	lw	$t8,%lo(g_BgRooms)($t8)
/*  f13da50:	000c6880 */ 	sll	$t5,$t4,0x2
/*  f13da54:	01ac6821 */ 	addu	$t5,$t5,$t4
/*  f13da58:	000d6880 */ 	sll	$t5,$t5,0x2
/*  f13da5c:	3c07800a */ 	lui	$a3,%hi(g_Vars+0x284)
/*  f13da60:	8ce7a244 */ 	lw	$a3,%lo(g_Vars+0x284)($a3)
/*  f13da64:	27a300fc */ 	addiu	$v1,$sp,0xfc
/*  f13da68:	8fa20140 */ 	lw	$v0,0x140($sp)
/*  f13da6c:	27a400f0 */ 	addiu	$a0,$sp,0xf0
/*  f13da70:	27a500e4 */ 	addiu	$a1,$sp,0xe4
/*  f13da74:	27a800f0 */ 	addiu	$t0,$sp,0xf0
/*  f13da78:	030d3021 */ 	addu	$a2,$t8,$t5
.L0f13da7c:
/*  f13da7c:	844e001c */ 	lh	$t6,0x1c($v0)
/*  f13da80:	8459000a */ 	lh	$t9,0xa($v0)
/*  f13da84:	844c0010 */ 	lh	$t4,0x10($v0)
/*  f13da88:	844d0016 */ 	lh	$t5,0x16($v0)
/*  f13da8c:	01d97821 */ 	addu	$t7,$t6,$t9
/*  f13da90:	01ecc021 */ 	addu	$t8,$t7,$t4
/*  f13da94:	030d7021 */ 	addu	$t6,$t8,$t5
/*  f13da98:	05c10003 */ 	bgez	$t6,.L0f13daa8
/*  f13da9c:	000ec883 */ 	sra	$t9,$t6,0x2
/*  f13daa0:	25c10003 */ 	addiu	$at,$t6,0x3
/*  f13daa4:	0001c883 */ 	sra	$t9,$at,0x2
.L0f13daa8:
/*  f13daa8:	a4790000 */ 	sh	$t9,0x0($v1)
/*  f13daac:	846f0000 */ 	lh	$t7,0x0($v1)
/*  f13dab0:	c4d00004 */ 	lwc1	$f16,0x4($a2)
/*  f13dab4:	24a50004 */ 	addiu	$a1,$a1,0x4
/*  f13dab8:	448f9000 */ 	mtc1	$t7,$f18
/*  f13dabc:	24630002 */ 	addiu	$v1,$v1,0x2
/*  f13dac0:	24420002 */ 	addiu	$v0,$v0,0x2
/*  f13dac4:	46809120 */ 	cvt.s.w	$f4,$f18
/*  f13dac8:	24840004 */ 	addiu	$a0,$a0,0x4
/*  f13dacc:	24c60004 */ 	addiu	$a2,$a2,0x4
/*  f13dad0:	24e70004 */ 	addiu	$a3,$a3,4
/*  f13dad4:	46048200 */ 	add.s	$f8,$f16,$f4
/*  f13dad8:	e488fffc */ 	swc1	$f8,-0x4($a0)
/*  f13dadc:	c4ea1bac */ 	lwc1	$f10,0x1bac($a3)
/*  f13dae0:	c486fffc */ 	lwc1	$f6,-0x4($a0)
/*  f13dae4:	460a3481 */ 	sub.s	$f18,$f6,$f10
/*  f13dae8:	14a8ffe4 */ 	bne	$a1,$t0,.L0f13da7c
/*  f13daec:	e4b2fffc */ 	swc1	$f18,-0x4($a1)
/*  f13daf0:	0fc2d5be */ 	jal	camGetWorldToScreenMtxf
/*  f13daf4:	00000000 */ 	nop
/*  f13daf8:	00402025 */ 	or	$a0,$v0,$zero
/*  f13dafc:	0c0056c4 */ 	jal	mtx4RotateVecInPlace
/*  f13db00:	27a500e4 */ 	addiu	$a1,$sp,0xe4
/*  f13db04:	27a400e4 */ 	addiu	$a0,$sp,0xe4
/*  f13db08:	0fc2d341 */ 	jal	cam0f0b4d04
/*  f13db0c:	27a500dc */ 	addiu	$a1,$sp,0xdc
/*  f13db10:	c7a000ec */ 	lwc1	$f0,0xec($sp)
/*  f13db14:	3c013f80 */ 	lui	$at,0x3f80
/*  f13db18:	44818000 */ 	mtc1	$at,$f16
/*  f13db1c:	46000007 */ 	neg.s	$f0,$f0
/*  f13db20:	3c013f80 */ 	lui	$at,0x3f80
/*  f13db24:	4610003c */ 	c.lt.s	$f0,$f16
/*  f13db28:	3c0e8007 */ 	lui	$t6,%hi(g_InCutscene)
/*  f13db2c:	8fa40164 */ 	lw	$a0,0x164($sp)
/*  f13db30:	45020005 */ 	bc1fl	.L0f13db48
/*  f13db34:	46000506 */ 	mov.s	$f20,$f0
/*  f13db38:	4481a000 */ 	mtc1	$at,$f20
/*  f13db3c:	10000002 */ 	b	.L0f13db48
/*  f13db40:	00000000 */ 	nop
/*  f13db44:	46000506 */ 	mov.s	$f20,$f0
.L0f13db48:
/*  f13db48:	3c017f1b */ 	lui	$at,%hi(var7f1b59f0)
/*  f13db4c:	c42459f0 */ 	lwc1	$f4,%lo(var7f1b59f0)($at)
/*  f13db50:	8fac0140 */ 	lw	$t4,0x140($sp)
/*  f13db54:	46142203 */ 	div.s	$f8,$f4,$f20
/*  f13db58:	91820006 */ 	lbu	$v0,0x6($t4)
/*  f13db5c:	4608b582 */ 	mul.s	$f22,$f22,$f8
/*  f13db60:	50400010 */ 	beqzl	$v0,.L0f13dba4
/*  f13db64:	92780001 */ 	lbu	$t8,0x1($s3)
/*  f13db68:	44823000 */ 	mtc1	$v0,$f6
/*  f13db6c:	3c014f80 */ 	lui	$at,0x4f80
/*  f13db70:	04410004 */ 	bgez	$v0,.L0f13db84
/*  f13db74:	468032a0 */ 	cvt.s.w	$f10,$f6
/*  f13db78:	44819000 */ 	mtc1	$at,$f18
/*  f13db7c:	00000000 */ 	nop
/*  f13db80:	46125280 */ 	add.s	$f10,$f10,$f18
.L0f13db84:
/*  f13db84:	3c013d00 */ 	lui	$at,0x3d00
/*  f13db88:	44818000 */ 	mtc1	$at,$f16
/*  f13db8c:	00000000 */ 	nop
/*  f13db90:	46105102 */ 	mul.s	$f4,$f10,$f16
/*  f13db94:	00000000 */ 	nop
/*  f13db98:	4604b582 */ 	mul.s	$f22,$f22,$f4
/*  f13db9c:	00000000 */ 	nop
/*  f13dba0:	92780001 */ 	lbu	$t8,0x1($s3)
.L0f13dba4:
/*  f13dba4:	3c014f80 */ 	lui	$at,0x4f80
/*  f13dba8:	44984000 */ 	mtc1	$t8,$f8
/*  f13dbac:	07010004 */ 	bgez	$t8,.L0f13dbc0
/*  f13dbb0:	468041a0 */ 	cvt.s.w	$f6,$f8
/*  f13dbb4:	44819000 */ 	mtc1	$at,$f18
/*  f13dbb8:	00000000 */ 	nop
/*  f13dbbc:	46123180 */ 	add.s	$f6,$f6,$f18
.L0f13dbc0:
/*  f13dbc0:	3c017f1b */ 	lui	$at,%hi(var7f1b59f4)
/*  f13dbc4:	c42a59f4 */ 	lwc1	$f10,%lo(var7f1b59f4)($at)
/*  f13dbc8:	3c03800a */ 	lui	$v1,%hi(g_Vars+0x284)
/*  f13dbcc:	8c63a244 */ 	lw	$v1,%lo(g_Vars+0x284)($v1)
/*  f13dbd0:	460a3402 */ 	mul.s	$f16,$f6,$f10
/*  f13dbd4:	8c6d00d8 */ 	lw	$t5,0xd8($v1)
/*  f13dbd8:	4610b582 */ 	mul.s	$f22,$f22,$f16
/*  f13dbdc:	15a0001a */ 	bnez	$t5,.L0f13dc48
/*  f13dbe0:	00000000 */ 	nop
/*  f13dbe4:	8dce0764 */ 	lw	$t6,%lo(g_InCutscene)($t6)
/*  f13dbe8:	15c00017 */ 	bnez	$t6,.L0f13dc48
/*  f13dbec:	00000000 */ 	nop
/*  f13dbf0:	8c620480 */ 	lw	$v0,0x480($v1)
/*  f13dbf4:	50400007 */ 	beqzl	$v0,.L0f13dc14
/*  f13dbf8:	8c6c1c54 */ 	lw	$t4,0x1c54($v1)
/*  f13dbfc:	10400012 */ 	beqz	$v0,.L0f13dc48
/*  f13dc00:	00000000 */ 	nop
/*  f13dc04:	80590037 */ 	lb	$t9,0x37($v0)
/*  f13dc08:	1720000f */ 	bnez	$t9,.L0f13dc48
/*  f13dc0c:	00000000 */ 	nop
/*  f13dc10:	8c6c1c54 */ 	lw	$t4,0x1c54($v1)
.L0f13dc14:
/*  f13dc14:	8c6f00c4 */ 	lw	$t7,0xc4($v1)
/*  f13dc18:	3c014160 */ 	lui	$at,0x4160
/*  f13dc1c:	0180c027 */ 	nor	$t8,$t4,$zero
/*  f13dc20:	01f86824 */ 	and	$t5,$t7,$t8
/*  f13dc24:	31ae0001 */ 	andi	$t6,$t5,0x1
/*  f13dc28:	11c00007 */ 	beqz	$t6,.L0f13dc48
/*  f13dc2c:	00000000 */ 	nop
/*  f13dc30:	44812000 */ 	mtc1	$at,$f4
/*  f13dc34:	00000000 */ 	nop
/*  f13dc38:	461e2202 */ 	mul.s	$f8,$f4,$f30
/*  f13dc3c:	00000000 */ 	nop
/*  f13dc40:	4608b582 */ 	mul.s	$f22,$f22,$f8
/*  f13dc44:	00000000 */ 	nop
.L0f13dc48:
/*  f13dc48:	0fc0036f */ 	jal	func0f000dbc
/*  f13dc4c:	4618b580 */ 	add.s	$f22,$f22,$f24
/*  f13dc50:	46000480 */ 	add.s	$f18,$f0,$f0
/*  f13dc54:	3c017f1b */ 	lui	$at,%hi(var7f1b59f8)
/*  f13dc58:	c42259f8 */ 	lwc1	$f2,%lo(var7f1b59f8)($at)
/*  f13dc5c:	4612b582 */ 	mul.s	$f22,$f22,$f18
/*  f13dc60:	4616103c */ 	c.lt.s	$f2,$f22
/*  f13dc64:	00000000 */ 	nop
/*  f13dc68:	45000002 */ 	bc1f	.L0f13dc74
/*  f13dc6c:	00000000 */ 	nop
/*  f13dc70:	46001586 */ 	mov.s	$f22,$f2
.L0f13dc74:
/*  f13dc74:	0fc59570 */ 	jal	stageGetCurrent
/*  f13dc78:	00000000 */ 	nop
/*  f13dc7c:	90590004 */ 	lbu	$t9,0x4($v0)
/*  f13dc80:	3c014f80 */ 	lui	$at,0x4f80
/*  f13dc84:	44993000 */ 	mtc1	$t9,$f6
/*  f13dc88:	07210004 */ 	bgez	$t9,.L0f13dc9c
/*  f13dc8c:	468032a0 */ 	cvt.s.w	$f10,$f6
/*  f13dc90:	44818000 */ 	mtc1	$at,$f16
/*  f13dc94:	00000000 */ 	nop
/*  f13dc98:	46105280 */ 	add.s	$f10,$f10,$f16
.L0f13dc9c:
/*  f13dc9c:	46165102 */ 	mul.s	$f4,$f10,$f22
/*  f13dca0:	3c017f1b */ 	lui	$at,%hi(var7f1b59fc)
/*  f13dca4:	c42859fc */ 	lwc1	$f8,%lo(var7f1b59fc)($at)
/*  f13dca8:	46082602 */ 	mul.s	$f24,$f4,$f8
/*  f13dcac:	0fc59570 */ 	jal	stageGetCurrent
/*  f13dcb0:	00000000 */ 	nop
/*  f13dcb4:	904c0005 */ 	lbu	$t4,0x5($v0)
/*  f13dcb8:	3c014f80 */ 	lui	$at,0x4f80
/*  f13dcbc:	448c9000 */ 	mtc1	$t4,$f18
/*  f13dcc0:	05810004 */ 	bgez	$t4,.L0f13dcd4
/*  f13dcc4:	468091a0 */ 	cvt.s.w	$f6,$f18
/*  f13dcc8:	44818000 */ 	mtc1	$at,$f16
/*  f13dccc:	00000000 */ 	nop
/*  f13dcd0:	46103180 */ 	add.s	$f6,$f6,$f16
.L0f13dcd4:
/*  f13dcd4:	46163282 */ 	mul.s	$f10,$f6,$f22
/*  f13dcd8:	3c017f1b */ 	lui	$at,%hi(var7f1b5a00)
/*  f13dcdc:	c4245a00 */ 	lwc1	$f4,%lo(var7f1b5a00)($at)
/*  f13dce0:	46045682 */ 	mul.s	$f26,$f10,$f4
/*  f13dce4:	0fc2d60a */ 	jal	camGetPerspAspect
/*  f13dce8:	00000000 */ 	nop
/*  f13dcec:	0c002f22 */ 	jal	viGetViewWidth
/*  f13dcf0:	46000506 */ 	mov.s	$f20,$f0
/*  f13dcf4:	44824000 */ 	mtc1	$v0,$f8
/*  f13dcf8:	3c017f1b */ 	lui	$at,%hi(var7f1b5a04)
/*  f13dcfc:	c4305a04 */ 	lwc1	$f16,%lo(var7f1b5a04)($at)
/*  f13dd00:	468044a0 */ 	cvt.s.w	$f18,$f8
/*  f13dd04:	46109182 */ 	mul.s	$f6,$f18,$f16
/*  f13dd08:	46143283 */ 	div.s	$f10,$f6,$f20
/*  f13dd0c:	460ac602 */ 	mul.s	$f24,$f24,$f10
/*  f13dd10:	0c002f26 */ 	jal	viGetViewHeight
/*  f13dd14:	00000000 */ 	nop
/*  f13dd18:	44822000 */ 	mtc1	$v0,$f4
/*  f13dd1c:	3c017f1b */ 	lui	$at,%hi(var7f1b5a08)
/*  f13dd20:	c4325a08 */ 	lwc1	$f18,%lo(var7f1b5a08)($at)
/*  f13dd24:	46802220 */ 	cvt.s.w	$f8,$f4
/*  f13dd28:	3c014040 */ 	lui	$at,0x4040
/*  f13dd2c:	44813000 */ 	mtc1	$at,$f6
/*  f13dd30:	8faf0140 */ 	lw	$t7,0x140($sp)
/*  f13dd34:	4616303c */ 	c.lt.s	$f6,$f22
/*  f13dd38:	46124402 */ 	mul.s	$f16,$f8,$f18
/*  f13dd3c:	00000000 */ 	nop
/*  f13dd40:	4610d682 */ 	mul.s	$f26,$f26,$f16
/*  f13dd44:	450000c9 */ 	bc1f	.L0f13e06c
/*  f13dd48:	00000000 */ 	nop
/*  f13dd4c:	95f80002 */ 	lhu	$t8,0x2($t7)
/*  f13dd50:	a3b10104 */ 	sb	$s1,0x104($sp)
/*  f13dd54:	a3b50105 */ 	sb	$s5,0x105($sp)
/*  f13dd58:	330d000f */ 	andi	$t5,$t8,0xf
/*  f13dd5c:	000d7100 */ 	sll	$t6,$t5,0x4
/*  f13dd60:	01cd7021 */ 	addu	$t6,$t6,$t5
/*  f13dd64:	448e5000 */ 	mtc1	$t6,$f10
/*  f13dd68:	a3b60106 */ 	sb	$s6,0x106($sp)
/*  f13dd6c:	46805020 */ 	cvt.s.w	$f0,$f10
/*  f13dd70:	0fc59570 */ 	jal	stageGetCurrent
/*  f13dd74:	e7a000bc */ 	swc1	$f0,0xbc($sp)
/*  f13dd78:	90590003 */ 	lbu	$t9,0x3($v0)
/*  f13dd7c:	c7a000bc */ 	lwc1	$f0,0xbc($sp)
/*  f13dd80:	27a40160 */ 	addiu	$a0,$sp,0x160
/*  f13dd84:	44992000 */ 	mtc1	$t9,$f4
/*  f13dd88:	27a500dc */ 	addiu	$a1,$sp,0xdc
/*  f13dd8c:	07210005 */ 	bgez	$t9,.L0f13dda4
/*  f13dd90:	46802220 */ 	cvt.s.w	$f8,$f4
/*  f13dd94:	3c014f80 */ 	lui	$at,0x4f80
/*  f13dd98:	44819000 */ 	mtc1	$at,$f18
/*  f13dd9c:	00000000 */ 	nop
/*  f13dda0:	46124200 */ 	add.s	$f8,$f8,$f18
.L0f13dda4:
/*  f13dda4:	461c4403 */ 	div.s	$f16,$f8,$f28
/*  f13dda8:	926c0001 */ 	lbu	$t4,0x1($s3)
/*  f13ddac:	3c014f80 */ 	lui	$at,0x4f80
/*  f13ddb0:	3c0d8007 */ 	lui	$t5,%hi(g_InCutscene)
/*  f13ddb4:	448c3000 */ 	mtc1	$t4,$f6
/*  f13ddb8:	27a600d4 */ 	addiu	$a2,$sp,0xd4
/*  f13ddbc:	24070040 */ 	addiu	$a3,$zero,0x40
/*  f13ddc0:	468032a0 */ 	cvt.s.w	$f10,$f6
/*  f13ddc4:	46100002 */ 	mul.s	$f0,$f0,$f16
/*  f13ddc8:	05830005 */ 	bgezl	$t4,.L0f13dde0
/*  f13ddcc:	461c5483 */ 	div.s	$f18,$f10,$f28
/*  f13ddd0:	44812000 */ 	mtc1	$at,$f4
/*  f13ddd4:	00000000 */ 	nop
/*  f13ddd8:	46045280 */ 	add.s	$f10,$f10,$f4
/*  f13dddc:	461c5483 */ 	div.s	$f18,$f10,$f28
.L0f13dde0:
/*  f13dde0:	926f0000 */ 	lbu	$t7,0x0($s3)
/*  f13dde4:	3c014f80 */ 	lui	$at,0x4f80
/*  f13dde8:	448f4000 */ 	mtc1	$t7,$f8
/*  f13ddec:	00000000 */ 	nop
/*  f13ddf0:	46804420 */ 	cvt.s.w	$f16,$f8
/*  f13ddf4:	46120002 */ 	mul.s	$f0,$f0,$f18
/*  f13ddf8:	05e30005 */ 	bgezl	$t7,.L0f13de10
/*  f13ddfc:	3c013e00 */ 	lui	$at,0x3e00
/*  f13de00:	44813000 */ 	mtc1	$at,$f6
/*  f13de04:	00000000 */ 	nop
/*  f13de08:	46068400 */ 	add.s	$f16,$f16,$f6
/*  f13de0c:	3c013e00 */ 	lui	$at,0x3e00
.L0f13de10:
/*  f13de10:	44812000 */ 	mtc1	$at,$f4
/*  f13de14:	3c03800a */ 	lui	$v1,%hi(g_Vars+0x284)
/*  f13de18:	8c63a244 */ 	lw	$v1,%lo(g_Vars+0x284)($v1)
/*  f13de1c:	46048282 */ 	mul.s	$f10,$f16,$f4
/*  f13de20:	8c7800d8 */ 	lw	$t8,0xd8($v1)
/*  f13de24:	460a0002 */ 	mul.s	$f0,$f0,$f10
/*  f13de28:	5700001b */ 	bnezl	$t8,.L0f13de98
/*  f13de2c:	4600e03c */ 	c.lt.s	$f28,$f0
/*  f13de30:	8dad0764 */ 	lw	$t5,%lo(g_InCutscene)($t5)
/*  f13de34:	55a00018 */ 	bnezl	$t5,.L0f13de98
/*  f13de38:	4600e03c */ 	c.lt.s	$f28,$f0
/*  f13de3c:	8c620480 */ 	lw	$v0,0x480($v1)
/*  f13de40:	50400007 */ 	beqzl	$v0,.L0f13de60
/*  f13de44:	8c6c1c54 */ 	lw	$t4,0x1c54($v1)
/*  f13de48:	50400013 */ 	beqzl	$v0,.L0f13de98
/*  f13de4c:	4600e03c */ 	c.lt.s	$f28,$f0
/*  f13de50:	804e0037 */ 	lb	$t6,0x37($v0)
/*  f13de54:	55c00010 */ 	bnezl	$t6,.L0f13de98
/*  f13de58:	4600e03c */ 	c.lt.s	$f28,$f0
/*  f13de5c:	8c6c1c54 */ 	lw	$t4,0x1c54($v1)
.L0f13de60:
/*  f13de60:	8c7900c4 */ 	lw	$t9,0xc4($v1)
/*  f13de64:	3c0140e0 */ 	lui	$at,0x40e0
/*  f13de68:	01807827 */ 	nor	$t7,$t4,$zero
/*  f13de6c:	032fc024 */ 	and	$t8,$t9,$t7
/*  f13de70:	330d0001 */ 	andi	$t5,$t8,0x1
/*  f13de74:	51a00008 */ 	beqzl	$t5,.L0f13de98
/*  f13de78:	4600e03c */ 	c.lt.s	$f28,$f0
/*  f13de7c:	44819000 */ 	mtc1	$at,$f18
/*  f13de80:	00000000 */ 	nop
/*  f13de84:	4612f202 */ 	mul.s	$f8,$f30,$f18
/*  f13de88:	00000000 */ 	nop
/*  f13de8c:	46080002 */ 	mul.s	$f0,$f0,$f8
/*  f13de90:	00000000 */ 	nop
/*  f13de94:	4600e03c */ 	c.lt.s	$f28,$f0
.L0f13de98:
/*  f13de98:	240c0001 */ 	addiu	$t4,$zero,0x1
/*  f13de9c:	3c014f00 */ 	lui	$at,0x4f00
/*  f13dea0:	3c18fb00 */ 	lui	$t8,0xfb00
/*  f13dea4:	45020003 */ 	bc1fl	.L0f13deb4
/*  f13dea8:	444ef800 */ 	cfc1	$t6,$31
/*  f13deac:	4600e006 */ 	mov.s	$f0,$f28
/*  f13deb0:	444ef800 */ 	cfc1	$t6,$31
.L0f13deb4:
/*  f13deb4:	44ccf800 */ 	ctc1	$t4,$31
/*  f13deb8:	00000000 */ 	nop
/*  f13debc:	460001a4 */ 	cvt.w.s	$f6,$f0
/*  f13dec0:	444cf800 */ 	cfc1	$t4,$31
/*  f13dec4:	00000000 */ 	nop
/*  f13dec8:	318c0078 */ 	andi	$t4,$t4,0x78
/*  f13decc:	51800013 */ 	beqzl	$t4,.L0f13df1c
/*  f13ded0:	440c3000 */ 	mfc1	$t4,$f6
/*  f13ded4:	44813000 */ 	mtc1	$at,$f6
/*  f13ded8:	240c0001 */ 	addiu	$t4,$zero,0x1
/*  f13dedc:	46060181 */ 	sub.s	$f6,$f0,$f6
/*  f13dee0:	44ccf800 */ 	ctc1	$t4,$31
/*  f13dee4:	00000000 */ 	nop
/*  f13dee8:	460031a4 */ 	cvt.w.s	$f6,$f6
/*  f13deec:	444cf800 */ 	cfc1	$t4,$31
/*  f13def0:	00000000 */ 	nop
/*  f13def4:	318c0078 */ 	andi	$t4,$t4,0x78
/*  f13def8:	15800005 */ 	bnez	$t4,.L0f13df10
/*  f13defc:	00000000 */ 	nop
/*  f13df00:	440c3000 */ 	mfc1	$t4,$f6
/*  f13df04:	3c018000 */ 	lui	$at,0x8000
/*  f13df08:	10000007 */ 	b	.L0f13df28
/*  f13df0c:	01816025 */ 	or	$t4,$t4,$at
.L0f13df10:
/*  f13df10:	10000005 */ 	b	.L0f13df28
/*  f13df14:	240cffff */ 	addiu	$t4,$zero,-1
/*  f13df18:	440c3000 */ 	mfc1	$t4,$f6
.L0f13df1c:
/*  f13df1c:	00000000 */ 	nop
/*  f13df20:	0580fffb */ 	bltz	$t4,.L0f13df10
/*  f13df24:	00000000 */ 	nop
.L0f13df28:
/*  f13df28:	8fa20160 */ 	lw	$v0,0x160($sp)
/*  f13df2c:	a3ac0107 */ 	sb	$t4,0x107($sp)
/*  f13df30:	44cef800 */ 	ctc1	$t6,$31
/*  f13df34:	244f0008 */ 	addiu	$t7,$v0,0x8
/*  f13df38:	afaf0160 */ 	sw	$t7,0x160($sp)
/*  f13df3c:	ac580000 */ 	sw	$t8,0x0($v0)
/*  f13df40:	93b90104 */ 	lbu	$t9,0x104($sp)
/*  f13df44:	93ac0105 */ 	lbu	$t4,0x105($sp)
/*  f13df48:	93ae0107 */ 	lbu	$t6,0x107($sp)
/*  f13df4c:	93ad0106 */ 	lbu	$t5,0x106($sp)
/*  f13df50:	00197e00 */ 	sll	$t7,$t9,0x18
/*  f13df54:	000ccc00 */ 	sll	$t9,$t4,0x10
/*  f13df58:	01cfc025 */ 	or	$t8,$t6,$t7
/*  f13df5c:	03197025 */ 	or	$t6,$t8,$t9
/*  f13df60:	000d6200 */ 	sll	$t4,$t5,0x8
/*  f13df64:	01ccc025 */ 	or	$t8,$t6,$t4
/*  f13df68:	ac580004 */ 	sw	$t8,0x4($v0)
/*  f13df6c:	24190040 */ 	addiu	$t9,$zero,0x40
/*  f13df70:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f13df74:	e7b800d4 */ 	swc1	$f24,0xd4($sp)
/*  f13df78:	e7ba00d8 */ 	swc1	$f26,0xd8($sp)
/*  f13df7c:	afaf0020 */ 	sw	$t7,0x20($sp)
/*  f13df80:	afb90010 */ 	sw	$t9,0x10($sp)
/*  f13df84:	afa0001c */ 	sw	$zero,0x1c($sp)
/*  f13df88:	afa00018 */ 	sw	$zero,0x18($sp)
/*  f13df8c:	0fc2c9d0 */ 	jal	func0f0b2740
/*  f13df90:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f13df94:	8fad00cc */ 	lw	$t5,0xcc($sp)
/*  f13df98:	240e00ff */ 	addiu	$t6,$zero,0xff
/*  f13df9c:	240c00ff */ 	addiu	$t4,$zero,0xff
/*  f13dfa0:	11a00032 */ 	beqz	$t5,.L0f13e06c
/*  f13dfa4:	241800ff */ 	addiu	$t8,$zero,0xff
/*  f13dfa8:	a3ae0104 */ 	sb	$t6,0x104($sp)
/*  f13dfac:	a3ac0105 */ 	sb	$t4,0x105($sp)
/*  f13dfb0:	0fc59570 */ 	jal	stageGetCurrent
/*  f13dfb4:	a3b80106 */ 	sb	$t8,0x106($sp)
/*  f13dfb8:	90590003 */ 	lbu	$t9,0x3($v0)
/*  f13dfbc:	3c017f1b */ 	lui	$at,%hi(var7f1b5a0c)
/*  f13dfc0:	c4205a0c */ 	lwc1	$f0,%lo(var7f1b5a0c)($at)
/*  f13dfc4:	a3b90107 */ 	sb	$t9,0x107($sp)
/*  f13dfc8:	926d0000 */ 	lbu	$t5,0x0($s3)
/*  f13dfcc:	332f00ff */ 	andi	$t7,$t9,0xff
/*  f13dfd0:	8fa30160 */ 	lw	$v1,0x160($sp)
/*  f13dfd4:	01ed0019 */ 	multu	$t7,$t5
/*  f13dfd8:	3c0ffb00 */ 	lui	$t7,0xfb00
/*  f13dfdc:	24790008 */ 	addiu	$t9,$v1,0x8
/*  f13dfe0:	afb90160 */ 	sw	$t9,0x160($sp)
/*  f13dfe4:	4600c402 */ 	mul.s	$f16,$f24,$f0
/*  f13dfe8:	27a40160 */ 	addiu	$a0,$sp,0x160
/*  f13dfec:	27a500dc */ 	addiu	$a1,$sp,0xdc
/*  f13dff0:	4600d102 */ 	mul.s	$f4,$f26,$f0
/*  f13dff4:	27a600d4 */ 	addiu	$a2,$sp,0xd4
/*  f13dff8:	24070040 */ 	addiu	$a3,$zero,0x40
/*  f13dffc:	00007012 */ 	mflo	$t6
/*  f13e000:	05c10003 */ 	bgez	$t6,.L0f13e010
/*  f13e004:	000e60c3 */ 	sra	$t4,$t6,0x3
/*  f13e008:	25c10007 */ 	addiu	$at,$t6,0x7
/*  f13e00c:	000160c3 */ 	sra	$t4,$at,0x3
.L0f13e010:
/*  f13e010:	a3ac0107 */ 	sb	$t4,0x107($sp)
/*  f13e014:	ac6f0000 */ 	sw	$t7,0x0($v1)
/*  f13e018:	93b80104 */ 	lbu	$t8,0x104($sp)
/*  f13e01c:	93ac0105 */ 	lbu	$t4,0x105($sp)
/*  f13e020:	93ae0107 */ 	lbu	$t6,0x107($sp)
/*  f13e024:	93ad0106 */ 	lbu	$t5,0x106($sp)
/*  f13e028:	0018ce00 */ 	sll	$t9,$t8,0x18
/*  f13e02c:	000cc400 */ 	sll	$t8,$t4,0x10
/*  f13e030:	01d97825 */ 	or	$t7,$t6,$t9
/*  f13e034:	01f87025 */ 	or	$t6,$t7,$t8
/*  f13e038:	000d6200 */ 	sll	$t4,$t5,0x8
/*  f13e03c:	01cc7825 */ 	or	$t7,$t6,$t4
/*  f13e040:	ac6f0004 */ 	sw	$t7,0x4($v1)
/*  f13e044:	24180040 */ 	addiu	$t8,$zero,0x40
/*  f13e048:	24190001 */ 	addiu	$t9,$zero,0x1
/*  f13e04c:	e7b000d4 */ 	swc1	$f16,0xd4($sp)
/*  f13e050:	e7a400d8 */ 	swc1	$f4,0xd8($sp)
/*  f13e054:	afb90020 */ 	sw	$t9,0x20($sp)
/*  f13e058:	afb80010 */ 	sw	$t8,0x10($sp)
/*  f13e05c:	afa0001c */ 	sw	$zero,0x1c($sp)
/*  f13e060:	afa00018 */ 	sw	$zero,0x18($sp)
/*  f13e064:	0fc2c9d0 */ 	jal	func0f0b2740
/*  f13e068:	afa00014 */ 	sw	$zero,0x14($sp)
.L0f13e06c:
/*  f13e06c:	a2600001 */ 	sb	$zero,0x1($s3)
.L0f13e070:
/*  f13e070:	a2600002 */ 	sb	$zero,0x2($s3)
.L0f13e074:
/*  f13e074:	02509021 */ 	addu	$s2,$s2,$s0
/*  f13e078:	2652ffff */ 	addiu	$s2,$s2,-1
.L0f13e07c:
/*  f13e07c:	26520001 */ 	addiu	$s2,$s2,0x1
.L0f13e080:
/*  f13e080:	2a410078 */ 	slti	$at,$s2,0x78
/*  f13e084:	1420fd6c */ 	bnez	$at,.L0f13d638
/*  f13e088:	00000000 */ 	nop
.L0f13e08c:
/*  f13e08c:	8fa20160 */ 	lw	$v0,0x160($sp)
.L0f13e090:
/*  f13e090:	8fbf0084 */ 	lw	$ra,0x84($sp)
/*  f13e094:	d7b40030 */ 	ldc1	$f20,0x30($sp)
/*  f13e098:	d7b60038 */ 	ldc1	$f22,0x38($sp)
/*  f13e09c:	d7b80040 */ 	ldc1	$f24,0x40($sp)
/*  f13e0a0:	d7ba0048 */ 	ldc1	$f26,0x48($sp)
/*  f13e0a4:	d7bc0050 */ 	ldc1	$f28,0x50($sp)
/*  f13e0a8:	d7be0058 */ 	ldc1	$f30,0x58($sp)
/*  f13e0ac:	8fb00060 */ 	lw	$s0,0x60($sp)
/*  f13e0b0:	8fb10064 */ 	lw	$s1,0x64($sp)
/*  f13e0b4:	8fb20068 */ 	lw	$s2,0x68($sp)
/*  f13e0b8:	8fb3006c */ 	lw	$s3,0x6c($sp)
/*  f13e0bc:	8fb40070 */ 	lw	$s4,0x70($sp)
/*  f13e0c0:	8fb50074 */ 	lw	$s5,0x74($sp)
/*  f13e0c4:	8fb60078 */ 	lw	$s6,0x78($sp)
/*  f13e0c8:	8fb7007c */ 	lw	$s7,0x7c($sp)
/*  f13e0cc:	8fbe0080 */ 	lw	$s8,0x80($sp)
/*  f13e0d0:	03e00008 */ 	jr	$ra
/*  f13e0d4:	27bd0160 */ 	addiu	$sp,$sp,0x160
);
