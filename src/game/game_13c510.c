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

void artifactsClear(void)
{
	struct artifact *artifacts = g_ArtifactLists[g_SchedWriteArtifactsIndex];
	s32 i;

	for (i = 0; i < MAX_ARTIFACTS; i++) {
		artifacts[i].type = ARTIFACTTYPE_FREE;
	}
}

void artifactsTick(void)
{
	g_SchedWriteArtifactsIndex++;
	g_SchedFrontArtifactsIndex++;
	WRAP(g_SchedWriteArtifactsIndex, 3);
	WRAP(g_SchedFrontArtifactsIndex, 3);
}

static u16 func0f13c574(f32 arg0)
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

static s32 func0f13c710(f32 arg0)
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

void artifactsCalculateGlaresForRoom(s32 roomnum)
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
	struct artifact *artifacts = g_ArtifactLists[g_SchedWriteArtifactsIndex];
	struct coord *campos = &g_Vars.currentplayer->cam_pos;
	struct artifact *artifact;

	if (g_Rooms[roomnum].gfxdata != NULL && g_Rooms[roomnum].loaded240) {
		numlights = g_Rooms[roomnum].gfxdata->numlights;

		if (numlights != 0) {
			roomlights = (struct light *)&g_BgLightsFileData[g_Rooms[roomnum].gfxdata->lightsindex * 0x22];
			s1 = &var800a41a0[g_Rooms[roomnum].gfxdata->lightsindex * 3];

			roomPopulateMtx(&sp138, roomnum);
			mtx00015f88(g_Vars.currentplayerstats->scale_bg2gfx, &sp138);
			mtx4MultMtx4(g_Vars.currentplayer->mtxf006c, &sp138, &spf8);

			viewwidth = g_ViBackData->viewx;
			viewheight = g_ViBackData->viewy;
			viewleft = g_ViBackData->viewleft;
			viewtop = g_ViBackData->viewtop;

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
								index = g_Env.numsuns;
								index *= 8;
								artifact = artifacts;
								artifact += index;

								while (artifact->type != ARTIFACTTYPE_FREE) {
									index++;
									artifact++;
								}

								if (index < MAX_ARTIFACTS) {
									artifact->unk04 = func0f13c574(f0) >> 2;
									artifact->unk08 = &var800844f0[g_ViBackData->x * yi + xi];
									artifact->light = &roomlights[i];
									artifact->type = ARTIFACTTYPE_GLARE;
									artifact->unk0c.u16_2 = xi;
									artifact->unk0c.u16_1 = yi;
								}
							}
						}
					}
				}
			}
		}
	}
}

static u8 func0f13d3c4(u8 arg0, u8 arg1)
{
	if (arg1 >= arg0 + 7) {
		return arg0 + 7;
	}

	if (arg1 <= arg0 - 7) {
		return arg0 - 7;
	}

	return arg1;
}

Gfx *artifactsConfigureForGlares(Gfx *gdl)
{
	texSelect(&gdl, &g_TexLightGlareConfigs[g_CurrentStage->light_type], 4, 0, 2, 1, NULL);

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

Gfx *artifactsUnconfigureForGlares(Gfx *gdl)
{
	gDPSetTexturePersp(gdl++, G_TP_PERSP);

	return gdl;
}

Gfx *artifactsRenderGlaresForRoom(Gfx *gdl, s32 roomnum)
{
	s32 i;
	s32 j;
	s32 lightindex;
	struct artifact *artifacts;
	u16 min;
	u16 max;
	f32 f30;
	s32 t2;
	struct light *light;
	u8 *s3;
	s32 k;
	s32 count;
	u16 t4;
	f32 add;
	s32 l;
	f32 brightness;
	s32 avg;
	f32 f0;
	s32 v1;
	s32 r;
	s32 g;
	s32 b;
	s32 stack;
	u8 colour[4];
	s16 lightroompos[3];
	struct coord lightworldpos;
	struct coord lightscreenpos;
	f32 spdc[2];
	f32 spd4[2];
	f32 f24;
	bool extra;
	f32 f26;

	artifacts = g_ArtifactLists[g_SchedFrontArtifactsIndex];
	f30 = g_Rooms[roomnum].unk5c;

	if (g_Rooms[roomnum].gfxdata == NULL || g_Rooms[roomnum].loaded240 == 0) {
		return gdl;
	}

	for (i = g_Env.numsuns * 8; i < MAX_ARTIFACTS; i++) {
		struct light *light2 = artifacts[i].light;
		count = 0;

		for (j = i; j < MAX_ARTIFACTS && artifacts[j].type == ARTIFACTTYPE_GLARE && artifacts[j].light == light2; j++) {
			count++;
		}

		light = artifacts[i].light;

		if (count > 0) {
			if (roomnum == light->roomnum) {
				lightindex = ((u32)light - (u32)g_BgLightsFileData) / sizeof(struct light);
				s3 = &var800a41a0[lightindex * 3];
				t2 = 0;
				min = 0xffff;
				max = 0;

				for (k = i; k < i + count; k++) {
					if (artifacts[k].unk04 > max) {
						max = artifacts[k].unk04;
					}

					if (artifacts[k].unk04 < min) {
						min = artifacts[k].unk04;
					}
				}

				avg = (max - min) >> 1;

				if (avg < 25) {
					avg = 25;
				}

				for (k = i; k < i + count; k++) {
					u16 tmp;
					t4 = (artifacts[k].unk02 & 0xfffc) >> 2;
					tmp = artifacts[k].unk04;

					if (tmp < t4) {
						v1 = t4 - tmp;
					} else {
						v1 = tmp - t4;
					}

					if (avg >= v1) {
						t2++;
					}

					artifacts[k].type = ARTIFACTTYPE_FREE;
				}

				s3[0] = func0f13d3c4(s3[0], t2 * 2);

				if (t2 > 0) {
					brightness = g_ViBackData->fovy * 0.017453292f;
					add = cosf(brightness) / sinf(brightness) * 14.6f;

					if (lightIsHealthy(roomnum, lightindex - g_Rooms[roomnum].gfxdata->lightsindex)) {
						if (!lightIsOn(roomnum, lightindex - g_Rooms[roomnum].gfxdata->lightsindex)) {
							continue;
						}

						brightness = 1.0f;
					} else if (lightTickBroken(roomnum, lightindex - g_Rooms[roomnum].gfxdata->lightsindex)) {
						brightness = 0.4f;
					} else {
						continue;
					}

					r = ((light->colour >> 12) & 0xf) * 17;
					g = ((light->colour >> 8) & 0xf) * 17;
					b = ((light->colour >> 4) & 0xf) * 17;

					if ((r == 0xff && g == 0xff && b == 0xff) || (r == 0xff && g + b < 35)) {
						extra = false;
					} else {
						extra = true;
					}

					if (USINGDEVICE(DEVICE_NIGHTVISION)) {
						s3[2] *= (s32) (f30 * 7.0f);
					}

					f0 = s3[2] * (1.0f / 255.0f);

					sky0f127334((s32) ((f32)f0 * r), (s32) ((f32)f0 * g), (s32) ((f32)f0 * b));

					for (l = 0; l < 3; l++) {
						lightroompos[l] = (light->bbox[0].s[l] + light->bbox[1].s[l] + light->bbox[2].s[l] + light->bbox[3].s[l]) / 4;
						lightworldpos.f[l] = lightroompos[l] + g_BgRooms[roomnum].pos.f[l];
						lightscreenpos.f[l] = lightworldpos.f[l] - g_Vars.currentplayer->cam_pos.f[l];
					}

					mtx4RotateVecInPlace(g_Vars.currentplayer->worldtoscreenmtx, &lightscreenpos);

					cam0f0b4d04(&lightscreenpos, spdc);

					brightness *= 27500.0f / (-lightscreenpos.z < 1.0f ? 1.0f : -lightscreenpos.z);

					if (light->unk06 != 0) {
						brightness *= light->unk06 * (1.0f / 32.0f);
					}

					brightness *= s3[1] * (1.0f / 255.0f);

					if (USINGDEVICE(DEVICE_NIGHTVISION)) {
						brightness *= 14.0f * f30;
					}

					brightness += add;
					brightness *= 2.0f * func0f000dbc(roomnum);

					if (brightness > 750.0f) {
						brightness = 750.0f;
					}

					f24 = g_CurrentStage->light_width * brightness * 0.01f;
					f26 = g_CurrentStage->light_height * brightness * 0.01f;

					f24 *= g_ViBackData->viewx * (1.0f / 240.0f) / g_Vars.currentplayer->c_perspaspect;
					f26 *= g_ViBackData->viewy * (1.0f / 240.0f);

					if (brightness > 3.0f) {
						f32 alpha = (light->colour & 0xf) * 17;

						colour[0] = r;
						colour[1] = g;
						colour[2] = b;

						alpha *= g_CurrentStage->light_alpha / 255.0f;
						alpha *= (s3[1] / 255.0f);
						alpha *= (s3[0] / 8.0f);

						if (USINGDEVICE(DEVICE_NIGHTVISION)) {
							alpha *= f30 * 7.0f;
						}

						if (alpha > 255.0f) {
							alpha = 255.0f;
						}

						colour[3] = alpha;

						gDPSetEnvColor(gdl++, colour[0], colour[1], colour[2], colour[3]);

						spd4[0] = f24;
						spd4[1] = f26;

						func0f0b2740(&gdl, spdc, spd4, 64, 64, false, false, false, 1);

						if (extra) {
							colour[0] = 0xff;
							colour[1] = 0xff;
							colour[2] = 0xff;
							colour[3] = g_CurrentStage->light_alpha;
							colour[3] = s3[0] * colour[3] / 8;

							gDPSetEnvColor(gdl++, colour[0], colour[1], colour[2], colour[3]);

							spd4[0] = f24 * 0.4f;
							spd4[1] = f26 * 0.4f;

							func0f0b2740(&gdl, spdc, spd4, 64, 64, false, false, false, 1);
						}
					}
				}

				s3[1] = 0;
				s3[2] = 0;
			}

			// This is incrementing i past all the artifacts for this particular
			// light, then subtracting 1 because the for loop will add 1.
			i = i + count - 1;
		}
	}

	return gdl;
}
