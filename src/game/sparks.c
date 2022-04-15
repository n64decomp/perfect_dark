#include <ultra64.h>
#include "constants.h"
#include "game/dlights.h"
#include "game/chr.h"
#include "game/tex.h"
#include "game/sparks.h"
#include "game/file.h"
#include "bss.h"
#include "lib/vi.h"
#include "lib/rng.h"
#include "lib/mtx.h"
#include "data.h"
#include "types.h"

struct spark g_Sparks[100];
s32 g_NextSparkIndex;
u32 var800a3fc4;
struct sparkgroup g_SparkGroups[10];
s32 g_NextSparkGroupIndex;
u32 var800a4134;
u32 var800a4138;
u32 var800a413c;
u32 var800a4140;
u32 var800a4144;
u32 var800a4148;
u32 var800a414c;

struct sparktype g_SparkTypes[] = {
	//                                     weight
	//                                     |     max age
	//                                     |     |                                        decel
	//                                     |     |                                        |
#if PAL
	/*0x00*/ { 100, 28,  100,  1,   0,  0, 2.4,              50,  50,  15, 1, 0xffff80ff, 0xffffffff, 0.024 },
	/*0x00*/ { 100, 28,  100,  1,   0,  0, 2.4,              50,  50,  15, 1, 0x80ffffff, 0xffffffff, 0.024 },
	/*0x00*/ { 40,  -1,  30,   30,  0,  0, 2.4,              29,  29,  5,  1, 0x301010ff, 0x401010ff, 0.024 },
	/*0x00*/ { 40,  -1,  300,  200, 0,  0, 0.18,             5,   5,   4,  1, 0xffffff40, 0x560011a0, 0.024 },
	/*0x00*/ { 10,  1,   1200, 400, 0,  0, 0.18,             5,   5,   5,  1, 0xa0a0e000, 0xffffffff, 0.024 },
	/*0x00*/ { 40,  10,  10,   10,  0,  0, 3.6000001430511,  150, 75,  5,  1, 0x00ff6aff, 0xffffffff, 0.024 },
	/*0x00*/ { 15,  10,  20,   20,  0,  0, 0.78000003099442, 150, 75,  5,  1, 0xa0a0e0ff, 0xffffffff, 0.024 },
	/*0x00*/ { 1,   1,   120,  2,   0,  0, 0,                50,  50,  5,  1, 0xffff80ff, 0xffffffff, 0.024 },
	/*0x00*/ { 1,   1,   300,  50,  0,  0, 0,                5,   5,   5,  1, 0xffff8000, 0xffffffff, 0.024 },
	/*0x00*/ { 1,   1,   400,  100, 0,  0, 0,                8,   8,   5,  1, 0xffff8000, 0xffffffff, 0.024 },
	/*0x00*/ { 75,  100, 100,  1,   0,  0, 2.4,              50,  50,  15, 1, 0xffff80ff, 0xffffffff, 0.024 },
	/*0x00*/ { 75,  100, 20,   5,   0,  0, 1.8000000715256,  50,  50,  20, 1, 0xa0a0e0ff, 0xffffffff, 0.024 },
	/*0x00*/ { 20,  10,  100,  1,   0,  0, 2.4,              50,  50,  15, 1, 0xffff80ff, 0xffffffff, 0.024 },
	/*0x00*/ { 20,  10,  20,   5,   0,  0, 1.8000000715256,  50,  50,  20, 1, 0xa0a0e0ff, 0xffffffff, 0.024 },
	/*0x00*/ { 1,   0,   80,   1,   36, 6, 0,                100, 75,  15, 0, 0x0808f000, 0xffffffff, 0.024 },
	/*0x00*/ { 70,  0,   150,  15,  0,  0, 7.2000002861023,  33,  8,   3,  0, 0x11112880, 0xaaaaaa40, 0.024 },
	/*0x00*/ { 50,  28,  100,  1,   0,  0, 1.2,              50,  25,  10, 1, 0xffff80ff, 0xffffffff, 0.024 },
	/*0x00*/ { 300, 100, 100,  2,   0,  0, 0.36,             25,  1,   40, 2, 0xffff80ff, 0xffffffff, 0.119 },
	/*0x00*/ { 170, 80,  60,   5,   0,  0, 0.48000001907349, 25,  5,   10, 3, 0xa0a0e0ff, 0xffffffff, 0.119 },
	/*0x00*/ { 120, 40,  30,   7,   0,  0, 0.24000000953674, 50,  5,   15, 3, 0xffff80ff, 0xffffffff, 0.119 },
	/*0x00*/ { 80,  10,  10,   9,   0,  0, 0.12000000476837, 25,  5,   20, 3, 0xa0a0e0ff, 0xffffffff, 0.119 },
	/*0x00*/ { 100, 1,   100,  50,  0,  0, 2.4,              25,  16,  15, 1, 0xffff80ff, 0xffffffff, 0.024 },
	/*0x00*/ { 100, 28,  100,  1,   0,  0, 2.4,              100, 100, 30, 1, 0xff8080ff, 0xffff80ff, 0.024 },
	/*0x00*/ { 100, 28,  100,  1,   0,  0, 2.4,              50,  50,  15, 1, 0x4fff4fff, 0xffffffff, 0.024 },
	/*0x00*/ { 100, 28,  100,  1,   0,  0, 2.4,              50,  50,  15, 1, 0xffff7f7f, 0xffffffff, 0.024 },
	/*0x00*/ { 40,  -1,  30,   10,  0,  0, 2.4,              41,  29,  10, 1, 0x301010ff, 0x401010ff, 0.024 },
	/*0x00*/ { 70,  0,   150,  15,  0,  0, 7.2000002861023,  33,  8,   3,  0, 0x1111a880, 0xaaaaff40, 0.024 },
#else
	/*0x00*/ { 100, 28,  100,  1,   0,  0, 2,                60,  60,  15, 1, 0xffff80ff, 0xffffffff, 0.02 },
	/*0x01*/ { 100, 28,  100,  1,   0,  0, 2,                60,  60,  15, 1, 0x80ffffff, 0xffffffff, 0.02 },
	/*0x02*/ { 40,  -1,  30,   30,  0,  0, 2,                35,  35,  5,  1, 0x301010ff, 0x401010ff, 0.02 },
	/*0x03*/ { 40,  -1,  300,  200, 0,  0, 0.15,             5,   5,   4,  1, 0xffffff40, 0x560011a0, 0.02 },
	/*0x04*/ { 10,  1,   1200, 400, 0,  0, 0.15,             5,   5,   5,  1, 0xa0a0e000, 0xffffffff, 0.02 },
	/*0x05*/ { 40,  10,  10,   10,  0,  0, 3,                180, 90,  5,  1, 0x00ff6aff, 0xffffffff, 0.02 },
	/*0x06*/ { 15,  10,  20,   20,  0,  0, 0.65,             180, 90,  5,  1, 0xa0a0e0ff, 0xffffffff, 0.02 },
	/*0x07*/ { 1,   1,   120,  2,   0,  0, 0,                60,  60,  5,  1, 0xffff80ff, 0xffffffff, 0.02 },
	/*0x08*/ { 1,   1,   300,  50,  0,  0, 0,                5,   5,   5,  1, 0xffff8000, 0xffffffff, 0.02 },
	/*0x09*/ { 1,   1,   400,  100, 0,  0, 0,                10,  10,  5,  1, 0xffff8000, 0xffffffff, 0.02 },
	/*0x0a*/ { 75,  100, 100,  1,   0,  0, 2,                60,  60,  15, 1, 0xffff80ff, 0xffffffff, 0.02 },
	/*0x0b*/ { 75,  100, 20,   5,   0,  0, 1.5,              60,  60,  20, 1, 0xa0a0e0ff, 0xffffffff, 0.02 },
	/*0x0c*/ { 20,  10,  100,  1,   0,  0, 2,                60,  60,  15, 1, 0xffff80ff, 0xffffffff, 0.02 },
	/*0x0d*/ { 20,  10,  20,   5,   0,  0, 1.5,              60,  60,  20, 1, 0xa0a0e0ff, 0xffffffff, 0.02 },
	/*0x0e*/ { 1,   0,   80,   1,   30, 5, 0,                120, 90,  15, 0, 0x0808f000, 0xffffffff, 0.02 },
	/*0x0f*/ { 70,  0,   150,  15,  0,  0, 6,                40,  10,  3,  0, 0x11112880, 0xaaaaaa40, 0.02 },
	/*0x10*/ { 50,  28,  100,  1,   0,  0, 1,                60,  30,  10, 1, 0xffff80ff, 0xffffffff, 0.02 },
	/*0x11*/ { 300, 100, 100,  2,   0,  0, 0.3,              30,  1,   40, 2, 0xffff80ff, 0xffffffff, 0.1  },
	/*0x12*/ { 170, 80,  60,   5,   0,  0, 0.4,              30,  5,   10, 3, 0xa0a0e0ff, 0xffffffff, 0.1  },
	/*0x13*/ { 120, 40,  30,   7,   0,  0, 0.2,              60,  5,   15, 3, 0xffff80ff, 0xffffffff, 0.1  },
	/*0x14*/ { 80,  10,  10,   9,   0,  0, 0.1,              30,  5,   20, 3, 0xa0a0e0ff, 0xffffffff, 0.1  },
	/*0x15*/ { 100, 1,   100,  50,  0,  0, 2,                30,  20,  15, 1, 0xffff80ff, 0xffffffff, 0.02 },
	/*0x16*/ { 100, 28,  100,  1,   0,  0, 2,                120, 120, 30, 1, 0xff8080ff, 0xffff80ff, 0.02 },
	/*0x17*/ { 100, 28,  100,  1,   0,  0, 2,                60,  60,  15, 1, 0x4fff4fff, 0xffffffff, 0.02 },
	/*0x18*/ { 100, 28,  100,  1,   0,  0, 2,                60,  60,  15, 1, 0xffff7f7f, 0xffffffff, 0.02 },
	/*0x19*/ { 40,  -1,  30,   10,  0,  0, 2,                50,  35,  10, 1, 0x301010ff, 0x401010ff, 0.02 },
	/*0x1a*/ { 70,  0,   150,  15,  0,  0, 6,                40,  10,  3,  0, 0x1111a880, 0xaaaaff40, 0.02 },
#endif
};

s32 g_SparksAreActive = false;

void sparkCreate(struct coord *pos, struct sparktype *type)
{
	f32 tmp;
	f32 maxspeed = 0.0f;
	s32 i;
	struct spark *spark;

	spark = &g_Sparks[g_NextSparkIndex];
	g_NextSparkIndex = (g_NextSparkIndex + 1) % 100;

	spark->pos.x = 0.0f;
	spark->pos.y = 0.0f;
	spark->pos.z = 0.0f;

	spark->speed.x = (s32)(random() % (type->unk00 * 2 + 1)) - type->unk00;
	spark->speed.y = (s32)(random() % (type->unk00 * 2 + 1)) - type->unk00;
	spark->speed.z = (s32)(random() % (type->unk00 * 2 + 1)) - type->unk00;

	if (spark->speed.y == 0.0f) {
		spark->speed.y = -0.0001f;
	}

	for (i = 0; i < 3; i++) {
		if (spark->speed.f[i] > maxspeed) {
			maxspeed = spark->speed.f[i];
		}

		if (-spark->speed.f[i] > maxspeed) {
			maxspeed = -spark->speed.f[i];
		}
	}

	tmp = sqrtf(spark->speed.f[0] * spark->speed.f[0] + spark->speed.f[1] * spark->speed.f[1] + spark->speed.f[2] * spark->speed.f[2]);

	spark->speed.x *= maxspeed / tmp;
	spark->speed.y *= maxspeed / tmp;
	spark->speed.z *= maxspeed / tmp;

	spark->speed.y += type->unk00 / 2;

	spark->speed.x += pos->x;
	spark->speed.y += pos->y;
	spark->speed.z += pos->z;

#if PAL
	spark->speed.x *= 1.2f;
	spark->speed.y *= 1.2f;
	spark->speed.z *= 1.2f;
#endif

	if (spark->speed.y == 0.0f) {
		spark->speed.y = -0.0001f;
	}

	if (type->unk18 % 2) {
		spark->ttl = random() % type->maxage;
	} else {
		spark->ttl = type->maxage;
	}
}

/**
 * This function handles an out-of-memory situation when creating a spark, by
 * shrinking whichever spark group was about to be overwritten.
 */
void sparkgroupEnsureFreeSparkSlot(struct sparkgroup *group)
{
	s32 i;

	for (i = 0; i < 10; i++) {
		if (&g_SparkGroups[i] != group && g_SparkGroups[i].startindex == g_NextSparkIndex) {
			g_SparkGroups[i].startindex = (g_SparkGroups[i].startindex + 1) % 100;
			g_SparkGroups[i].numsparks--;

			if (g_SparkGroups[i].numsparks == 0) {
				g_SparkGroups[i].age = 0;
			}
		}
	}
}

void sparksCreate(s32 room, struct prop *prop, struct coord *pos, struct coord *arg3, struct coord *arg4, s32 typenum)
{
	struct sparkgroup *group = &g_SparkGroups[g_NextSparkGroupIndex];
	struct sparktype *type = &g_SparkTypes[typenum];
	struct coord grouppos;
	s32 i;

	if ((typenum == SPARKTYPE_02 || typenum == SPARKTYPE_03) && prop && prop->type == PROPTYPE_CHR) {
		struct chrdata *chr = prop->chr;
		u32 colours[3];
		u32 stack;

		chrGetBloodColour(chr->bodynum, NULL, colours);

		if (typenum == SPARKTYPE_02) {
			type->unk1c = colours[0];
			type->unk20 = colours[1];
		} else if (typenum == SPARKTYPE_03) {
			type->unk20 = colours[2];
		}
	} else if (typenum == SPARKTYPE_19) {
		type->unk1c = (random() % 2 ? 0xff000000 : 0) | (random() % 2 ? 0x00ff0000 : 0) | (random() % 2 ? 0x0000ff00 : 0) | 0xff;

		if (type->unk1c == 0x000000ff) {
			type->unk1c |= 0x0000ff00 << ((random() % 3) * 8);
		}

		type->unk20 = (random() % 2 ? 0xff000000 : 0) | (random() % 2 ? 0x00ff0000 : 0) | (random() % 2 ? 0x0000ff00 : 0) | 0xff;

		if (type->unk20 == 0xff) {
			type->unk20 |= 0x0000ff00 << ((random() % 3) * 8);
		}
	}

	g_NextSparkGroupIndex = (g_NextSparkGroupIndex + 1) % 10;

	if (typenum == SPARKTYPE_0F) {
		if (group->age != 0) {
			s32 newindex = -1;

			for (i = 0; i < 10 && newindex < 0; i++) {
				if (g_SparkGroups[i].age == 0) {
					newindex = i;
				}
			}

			if (newindex == -1) {
				return;
			}

			group = &g_SparkGroups[newindex];
		}
	}

	if (arg3 != NULL && arg4 != NULL) {
		f32 f0 = sqrtf(arg4->f[0] * arg4->f[0] + arg4->f[1] * arg4->f[1] + arg4->f[2] * arg4->f[2]);

		arg4->x /= f0;
		arg4->y /= f0;
		arg4->z /= f0;

		f0 = -2.0f * (arg3->f[0] * arg4->f[0] + arg3->f[1] * arg4->f[1] + arg3->f[2] * arg4->f[2]);

		grouppos.x = arg3->x + f0 * arg4->f[0];
		grouppos.y = arg3->y + f0 * arg4->f[1];
		grouppos.z = arg3->z + f0 * arg4->f[2];

		f0 = sqrtf(grouppos.f[0] * grouppos.f[0] + grouppos.f[1] * grouppos.f[1] + grouppos.f[2] * grouppos.f[2]);

		if (f0 == 0.0f) {
			f0 = 1.0f;
		}

		grouppos.x *= type->unk02 / f0;
		grouppos.y *= type->unk02 / f0;
		grouppos.z *= type->unk02 / f0;
	} else if (arg3 != NULL && type->unk02 >= -1 && type->unk02 < 2) {
		grouppos.x = arg3->x * 10.0f * type->unk02;
		grouppos.y = arg3->y * 10.0f * type->unk02;
		grouppos.z = arg3->z * 10.0f * type->unk02;
	} else {
		grouppos.x = 0.0f;
		grouppos.y = 0.0f;
		grouppos.z = 0.0f;
	}

	group->type = typenum;
	group->age = 1;
	group->startindex = g_NextSparkIndex;
	group->numsparks = type->numsparks;
	group->pos.x = pos->x;
	group->pos.y = pos->y;
	group->pos.z = pos->z;
	group->room = room;
	group->prop = prop;

	for (i = 0; i < type->numsparks; i++) {
		sparkgroupEnsureFreeSparkSlot(group);
		sparkCreate(&grouppos, type);
	}

	switch (typenum) {
	case SPARKTYPE_00:
		roomAdjustLighting(group->room, 24, 32);
		break;
	case SPARKTYPE_09:
		if (g_Vars.stagenum != STAGE_CRASHSITE) {
			roomAdjustLighting(group->room, 32, 128);
		}
		break;
	case SPARKTYPE_0A:
		if (g_Vars.stagenum != STAGE_CRASHSITE) {
			roomAdjustLighting(group->room, 64, 128);
		}
		break;
	case SPARKTYPE_0B:
		if (g_Vars.stagenum != STAGE_CRASHSITE) {
			roomAdjustLighting(group->room, 200, 255);
		}
		break;
	}

	g_SparksAreActive = true;
}

GLOBAL_ASM(
glabel sparksRender
.late_rodata
glabel var7f1b5608
.word 0x3d4ccccd
glabel var7f1b560c
.word 0x469c4000
glabel var7f1b5610
.word 0x3e4ccccd
.text
/*  f130044:	27bdfe90 */ 	addiu	$sp,$sp,-368
/*  f130048:	3c0e8008 */ 	lui	$t6,%hi(g_SparksAreActive)
/*  f13004c:	8dcef0b8 */ 	lw	$t6,%lo(g_SparksAreActive)($t6)
/*  f130050:	afbf0074 */ 	sw	$ra,0x74($sp)
/*  f130054:	afbe0070 */ 	sw	$s8,0x70($sp)
/*  f130058:	afb7006c */ 	sw	$s7,0x6c($sp)
/*  f13005c:	afb60068 */ 	sw	$s6,0x68($sp)
/*  f130060:	afb50064 */ 	sw	$s5,0x64($sp)
/*  f130064:	afb40060 */ 	sw	$s4,0x60($sp)
/*  f130068:	afb3005c */ 	sw	$s3,0x5c($sp)
/*  f13006c:	afb20058 */ 	sw	$s2,0x58($sp)
/*  f130070:	afb10054 */ 	sw	$s1,0x54($sp)
/*  f130074:	afb00050 */ 	sw	$s0,0x50($sp)
/*  f130078:	f7bc0048 */ 	sdc1	$f28,0x48($sp)
/*  f13007c:	f7ba0040 */ 	sdc1	$f26,0x40($sp)
/*  f130080:	f7b80038 */ 	sdc1	$f24,0x38($sp)
/*  f130084:	f7b60030 */ 	sdc1	$f22,0x30($sp)
/*  f130088:	f7b40028 */ 	sdc1	$f20,0x28($sp)
/*  f13008c:	11c003e0 */ 	beqz	$t6,.L0f131010
/*  f130090:	afa40170 */ 	sw	$a0,0x170($sp)
/*  f130094:	3c10800a */ 	lui	$s0,%hi(g_Vars+0x284)
/*  f130098:	8e10a244 */ 	lw	$s0,%lo(g_Vars+0x284)($s0)
/*  f13009c:	4480a000 */ 	mtc1	$zero,$f20
/*  f1300a0:	27a40170 */ 	addiu	$a0,$sp,0x170
/*  f1300a4:	c6021bc0 */ 	lwc1	$f2,0x1bc0($s0)
/*  f1300a8:	3c05800b */ 	lui	$a1,%hi(g_TexSparkConfigs)
/*  f1300ac:	24060004 */ 	addiu	$a2,$zero,0x4
/*  f1300b0:	4602a03c */ 	c.lt.s	$f20,$f2
/*  f1300b4:	00003825 */ 	or	$a3,$zero,$zero
/*  f1300b8:	240f0002 */ 	addiu	$t7,$zero,0x2
/*  f1300bc:	24180001 */ 	addiu	$t8,$zero,0x1
/*  f1300c0:	45020004 */ 	bc1fl	.L0f1300d4
/*  f1300c4:	46001407 */ 	neg.s	$f16,$f2
/*  f1300c8:	10000002 */ 	b	.L0f1300d4
/*  f1300cc:	46001406 */ 	mov.s	$f16,$f2
/*  f1300d0:	46001407 */ 	neg.s	$f16,$f2
.L0f1300d4:
/*  f1300d4:	c60e1bbc */ 	lwc1	$f14,0x1bbc($s0)
/*  f1300d8:	460ea03c */ 	c.lt.s	$f20,$f14
/*  f1300dc:	00000000 */ 	nop
/*  f1300e0:	45020004 */ 	bc1fl	.L0f1300f4
/*  f1300e4:	46007307 */ 	neg.s	$f12,$f14
/*  f1300e8:	10000002 */ 	b	.L0f1300f4
/*  f1300ec:	46007306 */ 	mov.s	$f12,$f14
/*  f1300f0:	46007307 */ 	neg.s	$f12,$f14
.L0f1300f4:
/*  f1300f4:	4610603c */ 	c.lt.s	$f12,$f16
/*  f1300f8:	00000000 */ 	nop
/*  f1300fc:	45020019 */ 	bc1fl	.L0f130164
/*  f130100:	c6001bc4 */ 	lwc1	$f0,0x1bc4($s0)
/*  f130104:	c6001bc4 */ 	lwc1	$f0,0x1bc4($s0)
/*  f130108:	4600a03c */ 	c.lt.s	$f20,$f0
/*  f13010c:	00000000 */ 	nop
/*  f130110:	45020004 */ 	bc1fl	.L0f130124
/*  f130114:	46000407 */ 	neg.s	$f16,$f0
/*  f130118:	10000002 */ 	b	.L0f130124
/*  f13011c:	46000406 */ 	mov.s	$f16,$f0
/*  f130120:	46000407 */ 	neg.s	$f16,$f0
.L0f130124:
/*  f130124:	4602a03c */ 	c.lt.s	$f20,$f2
/*  f130128:	00000000 */ 	nop
/*  f13012c:	45020004 */ 	bc1fl	.L0f130140
/*  f130130:	46001307 */ 	neg.s	$f12,$f2
/*  f130134:	10000002 */ 	b	.L0f130140
/*  f130138:	46001306 */ 	mov.s	$f12,$f2
/*  f13013c:	46001307 */ 	neg.s	$f12,$f2
.L0f130140:
/*  f130140:	4610603c */ 	c.lt.s	$f12,$f16
/*  f130144:	00000000 */ 	nop
/*  f130148:	45000003 */ 	bc1f	.L0f130158
/*  f13014c:	00000000 */ 	nop
/*  f130150:	10000019 */ 	b	.L0f1301b8
/*  f130154:	24170002 */ 	addiu	$s7,$zero,0x2
.L0f130158:
/*  f130158:	10000017 */ 	b	.L0f1301b8
/*  f13015c:	24170001 */ 	addiu	$s7,$zero,0x1
/*  f130160:	c6001bc4 */ 	lwc1	$f0,0x1bc4($s0)
.L0f130164:
/*  f130164:	0000b825 */ 	or	$s7,$zero,$zero
/*  f130168:	4600a03c */ 	c.lt.s	$f20,$f0
/*  f13016c:	00000000 */ 	nop
/*  f130170:	45020004 */ 	bc1fl	.L0f130184
/*  f130174:	46000407 */ 	neg.s	$f16,$f0
/*  f130178:	10000002 */ 	b	.L0f130184
/*  f13017c:	46000406 */ 	mov.s	$f16,$f0
/*  f130180:	46000407 */ 	neg.s	$f16,$f0
.L0f130184:
/*  f130184:	460ea03c */ 	c.lt.s	$f20,$f14
/*  f130188:	00000000 */ 	nop
/*  f13018c:	45020004 */ 	bc1fl	.L0f1301a0
/*  f130190:	46007307 */ 	neg.s	$f12,$f14
/*  f130194:	10000002 */ 	b	.L0f1301a0
/*  f130198:	46007306 */ 	mov.s	$f12,$f14
/*  f13019c:	46007307 */ 	neg.s	$f12,$f14
.L0f1301a0:
/*  f1301a0:	4610603c */ 	c.lt.s	$f12,$f16
/*  f1301a4:	00000000 */ 	nop
/*  f1301a8:	45000003 */ 	bc1f	.L0f1301b8
/*  f1301ac:	00000000 */ 	nop
/*  f1301b0:	10000001 */ 	b	.L0f1301b8
/*  f1301b4:	24170002 */ 	addiu	$s7,$zero,0x2
.L0f1301b8:
/*  f1301b8:	8ca5b5a4 */ 	lw	$a1,%lo(g_TexSparkConfigs)($a1)
/*  f1301bc:	afaf0010 */ 	sw	$t7,0x10($sp)
/*  f1301c0:	afb80014 */ 	sw	$t8,0x14($sp)
/*  f1301c4:	0fc2ce70 */ 	jal	tex0f0b39c0
/*  f1301c8:	afa00018 */ 	sw	$zero,0x18($sp)
/*  f1301cc:	8fb90170 */ 	lw	$t9,0x170($sp)
/*  f1301d0:	3c09ba00 */ 	lui	$t1,0xba00
/*  f1301d4:	35291402 */ 	ori	$t1,$t1,0x1402
/*  f1301d8:	27280008 */ 	addiu	$t0,$t9,0x8
/*  f1301dc:	afa80170 */ 	sw	$t0,0x170($sp)
/*  f1301e0:	af200004 */ 	sw	$zero,0x4($t9)
/*  f1301e4:	af290000 */ 	sw	$t1,0x0($t9)
/*  f1301e8:	8faa0170 */ 	lw	$t2,0x170($sp)
/*  f1301ec:	3c0cba00 */ 	lui	$t4,0xba00
/*  f1301f0:	358c0602 */ 	ori	$t4,$t4,0x602
/*  f1301f4:	254b0008 */ 	addiu	$t3,$t2,0x8
/*  f1301f8:	afab0170 */ 	sw	$t3,0x170($sp)
/*  f1301fc:	240d00c0 */ 	addiu	$t5,$zero,0xc0
/*  f130200:	ad4d0004 */ 	sw	$t5,0x4($t2)
/*  f130204:	ad4c0000 */ 	sw	$t4,0x0($t2)
/*  f130208:	8fae0170 */ 	lw	$t6,0x170($sp)
/*  f13020c:	3c190040 */ 	lui	$t9,0x40
/*  f130210:	3c18b900 */ 	lui	$t8,0xb900
/*  f130214:	25cf0008 */ 	addiu	$t7,$t6,0x8
/*  f130218:	afaf0170 */ 	sw	$t7,0x170($sp)
/*  f13021c:	3718031d */ 	ori	$t8,$t8,0x31d
/*  f130220:	373949d8 */ 	ori	$t9,$t9,0x49d8
/*  f130224:	add90004 */ 	sw	$t9,0x4($t6)
/*  f130228:	add80000 */ 	sw	$t8,0x0($t6)
/*  f13022c:	8fa80170 */ 	lw	$t0,0x170($sp)
/*  f130230:	3c0ab900 */ 	lui	$t2,0xb900
/*  f130234:	354a0002 */ 	ori	$t2,$t2,0x2
/*  f130238:	25090008 */ 	addiu	$t1,$t0,0x8
/*  f13023c:	afa90170 */ 	sw	$t1,0x170($sp)
/*  f130240:	ad000004 */ 	sw	$zero,0x4($t0)
/*  f130244:	ad0a0000 */ 	sw	$t2,0x0($t0)
/*  f130248:	8fab0170 */ 	lw	$t3,0x170($sp)
/*  f13024c:	3c0dba00 */ 	lui	$t5,0xba00
/*  f130250:	35ad1001 */ 	ori	$t5,$t5,0x1001
/*  f130254:	256c0008 */ 	addiu	$t4,$t3,0x8
/*  f130258:	afac0170 */ 	sw	$t4,0x170($sp)
/*  f13025c:	ad600004 */ 	sw	$zero,0x4($t3)
/*  f130260:	ad6d0000 */ 	sw	$t5,0x0($t3)
/*  f130264:	8fae0170 */ 	lw	$t6,0x170($sp)
/*  f130268:	3c18ba00 */ 	lui	$t8,0xba00
/*  f13026c:	37180903 */ 	ori	$t8,$t8,0x903
/*  f130270:	25cf0008 */ 	addiu	$t7,$t6,0x8
/*  f130274:	afaf0170 */ 	sw	$t7,0x170($sp)
/*  f130278:	24190c00 */ 	addiu	$t9,$zero,0xc00
/*  f13027c:	add90004 */ 	sw	$t9,0x4($t6)
/*  f130280:	add80000 */ 	sw	$t8,0x0($t6)
/*  f130284:	8fa80170 */ 	lw	$t0,0x170($sp)
/*  f130288:	3c0bff32 */ 	lui	$t3,0xff32
/*  f13028c:	3c0afcff */ 	lui	$t2,0xfcff
/*  f130290:	25090008 */ 	addiu	$t1,$t0,0x8
/*  f130294:	afa90170 */ 	sw	$t1,0x170($sp)
/*  f130298:	354a99ff */ 	ori	$t2,$t2,0x99ff
/*  f13029c:	356b7f3f */ 	ori	$t3,$t3,0x7f3f
/*  f1302a0:	3c017f1b */ 	lui	$at,%hi(var7f1b5608)
/*  f1302a4:	ad0b0004 */ 	sw	$t3,0x4($t0)
/*  f1302a8:	ad0a0000 */ 	sw	$t2,0x0($t0)
/*  f1302ac:	c43c5608 */ 	lwc1	$f28,%lo(var7f1b5608)($at)
/*  f1302b0:	3c013f80 */ 	lui	$at,0x3f80
/*  f1302b4:	3c13800a */ 	lui	$s3,%hi(g_SparkGroups)
/*  f1302b8:	4481c000 */ 	mtc1	$at,$f24
/*  f1302bc:	26733fc8 */ 	addiu	$s3,$s3,%lo(g_SparkGroups)
/*  f1302c0:	c7b60120 */ 	lwc1	$f22,0x120($sp)
/*  f1302c4:	c7ba013c */ 	lwc1	$f26,0x13c($sp)
/*  f1302c8:	241e01f0 */ 	addiu	$s8,$zero,0x1f0
/*  f1302cc:	24140003 */ 	addiu	$s4,$zero,0x3
/*  f1302d0:	8e6c0008 */ 	lw	$t4,0x8($s3)
.L0f1302d4:
/*  f1302d4:	afb3016c */ 	sw	$s3,0x16c($sp)
/*  f1302d8:	24110001 */ 	addiu	$s1,$zero,0x1
/*  f1302dc:	11800345 */ 	beqz	$t4,.L0f130ff4
/*  f1302e0:	3c10800a */ 	lui	$s0,%hi(g_Vars+0x284)
/*  f1302e4:	8e620014 */ 	lw	$v0,0x14($s3)
/*  f1302e8:	8e10a244 */ 	lw	$s0,%lo(g_Vars+0x284)($s0)
/*  f1302ec:	4600c406 */ 	mov.s	$f16,$f24
/*  f1302f0:	10400007 */ 	beqz	$v0,.L0f130310
/*  f1302f4:	96030010 */ 	lhu	$v1,0x10($s0)
/*  f1302f8:	904d0001 */ 	lbu	$t5,0x1($v0)
/*  f1302fc:	31ae0002 */ 	andi	$t6,$t5,0x2
/*  f130300:	55c00012 */ 	bnezl	$t6,.L0f13034c
/*  f130304:	24010001 */ 	addiu	$at,$zero,0x1
/*  f130308:	1000000f */ 	b	.L0f130348
/*  f13030c:	00008825 */ 	or	$s1,$zero,$zero
.L0f130310:
/*  f130310:	8e780010 */ 	lw	$t8,0x10($s3)
/*  f130314:	3c0f800a */ 	lui	$t7,%hi(g_Rooms)
/*  f130318:	8def4928 */ 	lw	$t7,%lo(g_Rooms)($t7)
/*  f13031c:	0018c8c0 */ 	sll	$t9,$t8,0x3
/*  f130320:	0338c821 */ 	addu	$t9,$t9,$t8
/*  f130324:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f130328:	0338c823 */ 	subu	$t9,$t9,$t8
/*  f13032c:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f130330:	01f94021 */ 	addu	$t0,$t7,$t9
/*  f130334:	95090000 */ 	lhu	$t1,0x0($t0)
/*  f130338:	312a0004 */ 	andi	$t2,$t1,0x4
/*  f13033c:	55400003 */ 	bnezl	$t2,.L0f13034c
/*  f130340:	24010001 */ 	addiu	$at,$zero,0x1
/*  f130344:	00008825 */ 	or	$s1,$zero,$zero
.L0f130348:
/*  f130348:	24010001 */ 	addiu	$at,$zero,0x1
.L0f13034c:
/*  f13034c:	1461002c */ 	bne	$v1,$at,.L0f130400
/*  f130350:	00000000 */ 	nop
/*  f130354:	c6640020 */ 	lwc1	$f4,0x20($s3)
/*  f130358:	c6060020 */ 	lwc1	$f6,0x20($s0)
/*  f13035c:	c6680018 */ 	lwc1	$f8,0x18($s3)
/*  f130360:	c60a0018 */ 	lwc1	$f10,0x18($s0)
/*  f130364:	46062001 */ 	sub.s	$f0,$f4,$f6
/*  f130368:	c604001c */ 	lwc1	$f4,0x1c($s0)
/*  f13036c:	c672001c */ 	lwc1	$f18,0x1c($s3)
/*  f130370:	460a4081 */ 	sub.s	$f2,$f8,$f10
/*  f130374:	e7b00138 */ 	swc1	$f16,0x138($sp)
/*  f130378:	46049381 */ 	sub.s	$f14,$f18,$f4
/*  f13037c:	46021182 */ 	mul.s	$f6,$f2,$f2
/*  f130380:	00000000 */ 	nop
/*  f130384:	460e7202 */ 	mul.s	$f8,$f14,$f14
/*  f130388:	46083280 */ 	add.s	$f10,$f6,$f8
/*  f13038c:	46000482 */ 	mul.s	$f18,$f0,$f0
/*  f130390:	0c012974 */ 	jal	sqrtf
/*  f130394:	460a9300 */ 	add.s	$f12,$f18,$f10
/*  f130398:	3c10800a */ 	lui	$s0,%hi(g_Vars+0x284)
/*  f13039c:	8e10a244 */ 	lw	$s0,%lo(g_Vars+0x284)($s0)
/*  f1303a0:	3c014316 */ 	lui	$at,0x4316
/*  f1303a4:	44812000 */ 	mtc1	$at,$f4
/*  f1303a8:	c6020024 */ 	lwc1	$f2,0x24($s0)
/*  f1303ac:	c7b00138 */ 	lwc1	$f16,0x138($sp)
/*  f1303b0:	3c014316 */ 	lui	$at,0x4316
/*  f1303b4:	4600103c */ 	c.lt.s	$f2,$f0
/*  f1303b8:	46041301 */ 	sub.s	$f12,$f2,$f4
/*  f1303bc:	45000002 */ 	bc1f	.L0f1303c8
/*  f1303c0:	46020683 */ 	div.s	$f26,$f0,$f2
/*  f1303c4:	00008825 */ 	or	$s1,$zero,$zero
.L0f1303c8:
/*  f1303c8:	4600603c */ 	c.lt.s	$f12,$f0
/*  f1303cc:	00000000 */ 	nop
/*  f1303d0:	45020007 */ 	bc1fl	.L0f1303f0
/*  f1303d4:	461ac03c */ 	c.lt.s	$f24,$f26
/*  f1303d8:	460c0181 */ 	sub.s	$f6,$f0,$f12
/*  f1303dc:	44814000 */ 	mtc1	$at,$f8
/*  f1303e0:	00000000 */ 	nop
/*  f1303e4:	46083483 */ 	div.s	$f18,$f6,$f8
/*  f1303e8:	4612c401 */ 	sub.s	$f16,$f24,$f18
/*  f1303ec:	461ac03c */ 	c.lt.s	$f24,$f26
.L0f1303f0:
/*  f1303f0:	00000000 */ 	nop
/*  f1303f4:	45000002 */ 	bc1f	.L0f130400
/*  f1303f8:	00000000 */ 	nop
/*  f1303fc:	4600c686 */ 	mov.s	$f26,$f24
.L0f130400:
/*  f130400:	12200020 */ 	beqz	$s1,.L0f130484
/*  f130404:	26021bb0 */ 	addiu	$v0,$s0,0x1bb0
/*  f130408:	c44a0000 */ 	lwc1	$f10,0x0($v0)
/*  f13040c:	c6640018 */ 	lwc1	$f4,0x18($s3)
/*  f130410:	c672001c */ 	lwc1	$f18,0x1c($s3)
/*  f130414:	46045181 */ 	sub.s	$f6,$f10,$f4
/*  f130418:	e7a60124 */ 	swc1	$f6,0x124($sp)
/*  f13041c:	c4480004 */ 	lwc1	$f8,0x4($v0)
/*  f130420:	c6660020 */ 	lwc1	$f6,0x20($s3)
/*  f130424:	46124281 */ 	sub.s	$f10,$f8,$f18
/*  f130428:	c7b20124 */ 	lwc1	$f18,0x124($sp)
/*  f13042c:	e7aa0128 */ 	swc1	$f10,0x128($sp)
/*  f130430:	c4440008 */ 	lwc1	$f4,0x8($v0)
/*  f130434:	46129282 */ 	mul.s	$f10,$f18,$f18
/*  f130438:	e7b00138 */ 	swc1	$f16,0x138($sp)
/*  f13043c:	46062201 */ 	sub.s	$f8,$f4,$f6
/*  f130440:	c7a40128 */ 	lwc1	$f4,0x128($sp)
/*  f130444:	46042182 */ 	mul.s	$f6,$f4,$f4
/*  f130448:	e7a8012c */ 	swc1	$f8,0x12c($sp)
/*  f13044c:	c7b2012c */ 	lwc1	$f18,0x12c($sp)
/*  f130450:	46129102 */ 	mul.s	$f4,$f18,$f18
/*  f130454:	46065200 */ 	add.s	$f8,$f10,$f6
/*  f130458:	0c012974 */ 	jal	sqrtf
/*  f13045c:	46082300 */ 	add.s	$f12,$f4,$f8
/*  f130460:	3c017f1b */ 	lui	$at,%hi(var7f1b560c)
/*  f130464:	c42a560c */ 	lwc1	$f10,%lo(var7f1b560c)($at)
/*  f130468:	c7b00138 */ 	lwc1	$f16,0x138($sp)
/*  f13046c:	46000586 */ 	mov.s	$f22,$f0
/*  f130470:	4600503c */ 	c.lt.s	$f10,$f0
/*  f130474:	00000000 */ 	nop
/*  f130478:	45000002 */ 	bc1f	.L0f130484
/*  f13047c:	00000000 */ 	nop
/*  f130480:	00008825 */ 	or	$s1,$zero,$zero
.L0f130484:
/*  f130484:	122002db */ 	beqz	$s1,.L0f130ff4
/*  f130488:	3c0d8008 */ 	lui	$t5,%hi(g_SparkTypes)
/*  f13048c:	8e6b0000 */ 	lw	$t3,0x0($s3)
/*  f130490:	25adec80 */ 	addiu	$t5,$t5,%lo(g_SparkTypes)
/*  f130494:	24040002 */ 	addiu	$a0,$zero,0x2
/*  f130498:	000b6080 */ 	sll	$t4,$t3,0x2
/*  f13049c:	018b6021 */ 	addu	$t4,$t4,$t3
/*  f1304a0:	000c60c0 */ 	sll	$t4,$t4,0x3
/*  f1304a4:	018d9021 */ 	addu	$s2,$t4,$t5
/*  f1304a8:	0000b025 */ 	or	$s6,$zero,$zero
/*  f1304ac:	26750018 */ 	addiu	$s5,$s3,0x18
/*  f1304b0:	0fc59e73 */ 	jal	gfxAllocateColours
/*  f1304b4:	e7b00138 */ 	swc1	$f16,0x138($sp)
/*  f1304b8:	3c10800a */ 	lui	$s0,%hi(g_Vars+0x284)
/*  f1304bc:	8e10a244 */ 	lw	$s0,%lo(g_Vars+0x284)($s0)
/*  f1304c0:	c7b00138 */ 	lwc1	$f16,0x138($sp)
/*  f1304c4:	00408825 */ 	or	$s1,$v0,$zero
/*  f1304c8:	8e0400d8 */ 	lw	$a0,0xd8($s0)
/*  f1304cc:	3c0e8007 */ 	lui	$t6,%hi(g_InCutscene)
/*  f1304d0:	14800013 */ 	bnez	$a0,.L0f130520
/*  f1304d4:	00000000 */ 	nop
/*  f1304d8:	8dce0764 */ 	lw	$t6,%lo(g_InCutscene)($t6)
/*  f1304dc:	15c00010 */ 	bnez	$t6,.L0f130520
/*  f1304e0:	00000000 */ 	nop
/*  f1304e4:	8e030480 */ 	lw	$v1,0x480($s0)
/*  f1304e8:	50600007 */ 	beqzl	$v1,.L0f130508
/*  f1304ec:	8e191c54 */ 	lw	$t9,0x1c54($s0)
/*  f1304f0:	1060000b */ 	beqz	$v1,.L0f130520
/*  f1304f4:	00000000 */ 	nop
/*  f1304f8:	80780037 */ 	lb	$t8,0x37($v1)
/*  f1304fc:	17000008 */ 	bnez	$t8,.L0f130520
/*  f130500:	00000000 */ 	nop
/*  f130504:	8e191c54 */ 	lw	$t9,0x1c54($s0)
.L0f130508:
/*  f130508:	8e0f00c4 */ 	lw	$t7,0xc4($s0)
/*  f13050c:	03204027 */ 	nor	$t0,$t9,$zero
/*  f130510:	01e84824 */ 	and	$t1,$t7,$t0
/*  f130514:	312a0001 */ 	andi	$t2,$t1,0x1
/*  f130518:	55400016 */ 	bnezl	$t2,.L0f130574
/*  f13051c:	8e48001c */ 	lw	$t0,0x1c($s2)
.L0f130520:
/*  f130520:	14800018 */ 	bnez	$a0,.L0f130584
/*  f130524:	3c0b8007 */ 	lui	$t3,%hi(g_InCutscene)
/*  f130528:	8d6b0764 */ 	lw	$t3,%lo(g_InCutscene)($t3)
/*  f13052c:	55600016 */ 	bnezl	$t3,.L0f130588
/*  f130530:	960a0010 */ 	lhu	$t2,0x10($s0)
/*  f130534:	8e030480 */ 	lw	$v1,0x480($s0)
/*  f130538:	50600007 */ 	beqzl	$v1,.L0f130558
/*  f13053c:	8e0e1c54 */ 	lw	$t6,0x1c54($s0)
/*  f130540:	50600011 */ 	beqzl	$v1,.L0f130588
/*  f130544:	960a0010 */ 	lhu	$t2,0x10($s0)
/*  f130548:	806c0037 */ 	lb	$t4,0x37($v1)
/*  f13054c:	5580000e */ 	bnezl	$t4,.L0f130588
/*  f130550:	960a0010 */ 	lhu	$t2,0x10($s0)
/*  f130554:	8e0e1c54 */ 	lw	$t6,0x1c54($s0)
.L0f130558:
/*  f130558:	8e0d00c4 */ 	lw	$t5,0xc4($s0)
/*  f13055c:	01c0c027 */ 	nor	$t8,$t6,$zero
/*  f130560:	01b8c824 */ 	and	$t9,$t5,$t8
/*  f130564:	332f0008 */ 	andi	$t7,$t9,0x8
/*  f130568:	51e00007 */ 	beqzl	$t7,.L0f130588
/*  f13056c:	960a0010 */ 	lhu	$t2,0x10($s0)
/*  f130570:	8e48001c */ 	lw	$t0,0x1c($s2)
.L0f130574:
/*  f130574:	ac480000 */ 	sw	$t0,0x0($v0)
/*  f130578:	8e490020 */ 	lw	$t1,0x20($s2)
/*  f13057c:	100000b2 */ 	b	.L0f130848
/*  f130580:	ac490004 */ 	sw	$t1,0x4($v0)
.L0f130584:
/*  f130584:	960a0010 */ 	lhu	$t2,0x10($s0)
.L0f130588:
/*  f130588:	24010001 */ 	addiu	$at,$zero,0x1
/*  f13058c:	554100ab */ 	bnel	$t2,$at,.L0f13083c
/*  f130590:	8e49001c */ 	lw	$t1,0x1c($s2)
/*  f130594:	461ac181 */ 	sub.s	$f6,$f24,$f26
/*  f130598:	3c01437f */ 	lui	$at,0x437f
/*  f13059c:	44819000 */ 	mtc1	$at,$f18
/*  f1305a0:	240c0001 */ 	addiu	$t4,$zero,0x1
/*  f1305a4:	3c014f00 */ 	lui	$at,0x4f00
/*  f1305a8:	46123102 */ 	mul.s	$f4,$f6,$f18
/*  f1305ac:	444bf800 */ 	cfc1	$t3,$31
/*  f1305b0:	44ccf800 */ 	ctc1	$t4,$31
/*  f1305b4:	00000000 */ 	nop
/*  f1305b8:	46002224 */ 	cvt.w.s	$f8,$f4
/*  f1305bc:	444cf800 */ 	cfc1	$t4,$31
/*  f1305c0:	00000000 */ 	nop
/*  f1305c4:	318c0078 */ 	andi	$t4,$t4,0x78
/*  f1305c8:	51800013 */ 	beqzl	$t4,.L0f130618
/*  f1305cc:	440c4000 */ 	mfc1	$t4,$f8
/*  f1305d0:	44814000 */ 	mtc1	$at,$f8
/*  f1305d4:	240c0001 */ 	addiu	$t4,$zero,0x1
/*  f1305d8:	46082201 */ 	sub.s	$f8,$f4,$f8
/*  f1305dc:	44ccf800 */ 	ctc1	$t4,$31
/*  f1305e0:	00000000 */ 	nop
/*  f1305e4:	46004224 */ 	cvt.w.s	$f8,$f8
/*  f1305e8:	444cf800 */ 	cfc1	$t4,$31
/*  f1305ec:	00000000 */ 	nop
/*  f1305f0:	318c0078 */ 	andi	$t4,$t4,0x78
/*  f1305f4:	15800005 */ 	bnez	$t4,.L0f13060c
/*  f1305f8:	00000000 */ 	nop
/*  f1305fc:	440c4000 */ 	mfc1	$t4,$f8
/*  f130600:	3c018000 */ 	lui	$at,0x8000
/*  f130604:	10000007 */ 	b	.L0f130624
/*  f130608:	01816025 */ 	or	$t4,$t4,$at
.L0f13060c:
/*  f13060c:	10000005 */ 	b	.L0f130624
/*  f130610:	240cffff */ 	addiu	$t4,$zero,-1
/*  f130614:	440c4000 */ 	mfc1	$t4,$f8
.L0f130618:
/*  f130618:	00000000 */ 	nop
/*  f13061c:	0580fffb */ 	bltz	$t4,.L0f13060c
/*  f130620:	00000000 */ 	nop
.L0f130624:
/*  f130624:	3c01437f */ 	lui	$at,0x437f
/*  f130628:	44cbf800 */ 	ctc1	$t3,$31
/*  f13062c:	44815000 */ 	mtc1	$at,$f10
/*  f130630:	24180001 */ 	addiu	$t8,$zero,0x1
/*  f130634:	3c014f00 */ 	lui	$at,0x4f00
/*  f130638:	460ad182 */ 	mul.s	$f6,$f26,$f10
/*  f13063c:	000c7400 */ 	sll	$t6,$t4,0x10
/*  f130640:	444df800 */ 	cfc1	$t5,$31
/*  f130644:	44d8f800 */ 	ctc1	$t8,$31
/*  f130648:	00000000 */ 	nop
/*  f13064c:	460034a4 */ 	cvt.w.s	$f18,$f6
/*  f130650:	4458f800 */ 	cfc1	$t8,$31
/*  f130654:	00000000 */ 	nop
/*  f130658:	33180078 */ 	andi	$t8,$t8,0x78
/*  f13065c:	53000013 */ 	beqzl	$t8,.L0f1306ac
/*  f130660:	44189000 */ 	mfc1	$t8,$f18
/*  f130664:	44819000 */ 	mtc1	$at,$f18
/*  f130668:	24180001 */ 	addiu	$t8,$zero,0x1
/*  f13066c:	46123481 */ 	sub.s	$f18,$f6,$f18
/*  f130670:	44d8f800 */ 	ctc1	$t8,$31
/*  f130674:	00000000 */ 	nop
/*  f130678:	460094a4 */ 	cvt.w.s	$f18,$f18
/*  f13067c:	4458f800 */ 	cfc1	$t8,$31
/*  f130680:	00000000 */ 	nop
/*  f130684:	33180078 */ 	andi	$t8,$t8,0x78
/*  f130688:	17000005 */ 	bnez	$t8,.L0f1306a0
/*  f13068c:	00000000 */ 	nop
/*  f130690:	44189000 */ 	mfc1	$t8,$f18
/*  f130694:	3c018000 */ 	lui	$at,0x8000
/*  f130698:	10000007 */ 	b	.L0f1306b8
/*  f13069c:	0301c025 */ 	or	$t8,$t8,$at
.L0f1306a0:
/*  f1306a0:	10000005 */ 	b	.L0f1306b8
/*  f1306a4:	2418ffff */ 	addiu	$t8,$zero,-1
/*  f1306a8:	44189000 */ 	mfc1	$t8,$f18
.L0f1306ac:
/*  f1306ac:	00000000 */ 	nop
/*  f1306b0:	0700fffb */ 	bltz	$t8,.L0f1306a0
/*  f1306b4:	00000000 */ 	nop
.L0f1306b8:
/*  f1306b8:	8e4f001c */ 	lw	$t7,0x1c($s2)
/*  f1306bc:	44cdf800 */ 	ctc1	$t5,$31
/*  f1306c0:	0018ce00 */ 	sll	$t9,$t8,0x18
/*  f1306c4:	31e800ff */ 	andi	$t0,$t7,0xff
/*  f1306c8:	44882000 */ 	mtc1	$t0,$f4
/*  f1306cc:	032e1825 */ 	or	$v1,$t9,$t6
/*  f1306d0:	05010005 */ 	bgez	$t0,.L0f1306e8
/*  f1306d4:	46802220 */ 	cvt.s.w	$f8,$f4
/*  f1306d8:	3c014f80 */ 	lui	$at,0x4f80
/*  f1306dc:	44815000 */ 	mtc1	$at,$f10
/*  f1306e0:	00000000 */ 	nop
/*  f1306e4:	460a4200 */ 	add.s	$f8,$f8,$f10
.L0f1306e8:
/*  f1306e8:	46088182 */ 	mul.s	$f6,$f16,$f8
/*  f1306ec:	240a0001 */ 	addiu	$t2,$zero,0x1
/*  f1306f0:	3c014f00 */ 	lui	$at,0x4f00
/*  f1306f4:	4449f800 */ 	cfc1	$t1,$31
/*  f1306f8:	44caf800 */ 	ctc1	$t2,$31
/*  f1306fc:	00000000 */ 	nop
/*  f130700:	460034a4 */ 	cvt.w.s	$f18,$f6
/*  f130704:	444af800 */ 	cfc1	$t2,$31
/*  f130708:	00000000 */ 	nop
/*  f13070c:	314a0078 */ 	andi	$t2,$t2,0x78
/*  f130710:	51400013 */ 	beqzl	$t2,.L0f130760
/*  f130714:	440a9000 */ 	mfc1	$t2,$f18
/*  f130718:	44819000 */ 	mtc1	$at,$f18
/*  f13071c:	240a0001 */ 	addiu	$t2,$zero,0x1
/*  f130720:	46123481 */ 	sub.s	$f18,$f6,$f18
/*  f130724:	44caf800 */ 	ctc1	$t2,$31
/*  f130728:	00000000 */ 	nop
/*  f13072c:	460094a4 */ 	cvt.w.s	$f18,$f18
/*  f130730:	444af800 */ 	cfc1	$t2,$31
/*  f130734:	00000000 */ 	nop
/*  f130738:	314a0078 */ 	andi	$t2,$t2,0x78
/*  f13073c:	15400005 */ 	bnez	$t2,.L0f130754
/*  f130740:	00000000 */ 	nop
/*  f130744:	440a9000 */ 	mfc1	$t2,$f18
/*  f130748:	3c018000 */ 	lui	$at,0x8000
/*  f13074c:	10000007 */ 	b	.L0f13076c
/*  f130750:	01415025 */ 	or	$t2,$t2,$at
.L0f130754:
/*  f130754:	10000005 */ 	b	.L0f13076c
/*  f130758:	240affff */ 	addiu	$t2,$zero,-1
/*  f13075c:	440a9000 */ 	mfc1	$t2,$f18
.L0f130760:
/*  f130760:	00000000 */ 	nop
/*  f130764:	0540fffb */ 	bltz	$t2,.L0f130754
/*  f130768:	00000000 */ 	nop
.L0f13076c:
/*  f13076c:	006a5825 */ 	or	$t3,$v1,$t2
/*  f130770:	356c3f00 */ 	ori	$t4,$t3,0x3f00
/*  f130774:	ac4c0000 */ 	sw	$t4,0x0($v0)
/*  f130778:	8e4d001c */ 	lw	$t5,0x1c($s2)
/*  f13077c:	44c9f800 */ 	ctc1	$t1,$31
/*  f130780:	3c014f80 */ 	lui	$at,0x4f80
/*  f130784:	31b800ff */ 	andi	$t8,$t5,0xff
/*  f130788:	44982000 */ 	mtc1	$t8,$f4
/*  f13078c:	07010004 */ 	bgez	$t8,.L0f1307a0
/*  f130790:	468022a0 */ 	cvt.s.w	$f10,$f4
/*  f130794:	44814000 */ 	mtc1	$at,$f8
/*  f130798:	00000000 */ 	nop
/*  f13079c:	46085280 */ 	add.s	$f10,$f10,$f8
.L0f1307a0:
/*  f1307a0:	460a8182 */ 	mul.s	$f6,$f16,$f10
/*  f1307a4:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f1307a8:	3c014f00 */ 	lui	$at,0x4f00
/*  f1307ac:	4459f800 */ 	cfc1	$t9,$31
/*  f1307b0:	44cef800 */ 	ctc1	$t6,$31
/*  f1307b4:	00000000 */ 	nop
/*  f1307b8:	460034a4 */ 	cvt.w.s	$f18,$f6
/*  f1307bc:	444ef800 */ 	cfc1	$t6,$31
/*  f1307c0:	00000000 */ 	nop
/*  f1307c4:	31ce0078 */ 	andi	$t6,$t6,0x78
/*  f1307c8:	51c00013 */ 	beqzl	$t6,.L0f130818
/*  f1307cc:	440e9000 */ 	mfc1	$t6,$f18
/*  f1307d0:	44819000 */ 	mtc1	$at,$f18
/*  f1307d4:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f1307d8:	46123481 */ 	sub.s	$f18,$f6,$f18
/*  f1307dc:	44cef800 */ 	ctc1	$t6,$31
/*  f1307e0:	00000000 */ 	nop
/*  f1307e4:	460094a4 */ 	cvt.w.s	$f18,$f18
/*  f1307e8:	444ef800 */ 	cfc1	$t6,$31
/*  f1307ec:	00000000 */ 	nop
/*  f1307f0:	31ce0078 */ 	andi	$t6,$t6,0x78
/*  f1307f4:	15c00005 */ 	bnez	$t6,.L0f13080c
/*  f1307f8:	00000000 */ 	nop
/*  f1307fc:	440e9000 */ 	mfc1	$t6,$f18
/*  f130800:	3c018000 */ 	lui	$at,0x8000
/*  f130804:	10000007 */ 	b	.L0f130824
/*  f130808:	01c17025 */ 	or	$t6,$t6,$at
.L0f13080c:
/*  f13080c:	10000005 */ 	b	.L0f130824
/*  f130810:	240effff */ 	addiu	$t6,$zero,-1
/*  f130814:	440e9000 */ 	mfc1	$t6,$f18
.L0f130818:
/*  f130818:	00000000 */ 	nop
/*  f13081c:	05c0fffb */ 	bltz	$t6,.L0f13080c
/*  f130820:	00000000 */ 	nop
.L0f130824:
/*  f130824:	006e7825 */ 	or	$t7,$v1,$t6
/*  f130828:	35e83f00 */ 	ori	$t0,$t7,0x3f00
/*  f13082c:	44d9f800 */ 	ctc1	$t9,$31
/*  f130830:	10000005 */ 	b	.L0f130848
/*  f130834:	ac480004 */ 	sw	$t0,0x4($v0)
/*  f130838:	8e49001c */ 	lw	$t1,0x1c($s2)
.L0f13083c:
/*  f13083c:	ac490000 */ 	sw	$t1,0x0($v0)
/*  f130840:	8e4a0020 */ 	lw	$t2,0x20($s2)
/*  f130844:	ac4a0004 */ 	sw	$t2,0x4($v0)
.L0f130848:
/*  f130848:	96440012 */ 	lhu	$a0,0x12($s2)
/*  f13084c:	96470010 */ 	lhu	$a3,0x10($s2)
/*  f130850:	3c0a0704 */ 	lui	$t2,0x704
/*  f130854:	0087082a */ 	slt	$at,$a0,$a3
/*  f130858:	50200064 */ 	beqzl	$at,.L0f1309ec
/*  f13085c:	8fb00170 */ 	lw	$s0,0x170($sp)
/*  f130860:	8e660008 */ 	lw	$a2,0x8($s3)
/*  f130864:	00e41823 */ 	subu	$v1,$a3,$a0
/*  f130868:	0086082a */ 	slt	$at,$a0,$a2
/*  f13086c:	1020005e */ 	beqz	$at,.L0f1309e8
/*  f130870:	00c42823 */ 	subu	$a1,$a2,$a0
/*  f130874:	00655823 */ 	subu	$t3,$v1,$a1
/*  f130878:	448b2000 */ 	mtc1	$t3,$f4
/*  f13087c:	44835000 */ 	mtc1	$v1,$f10
/*  f130880:	904c0003 */ 	lbu	$t4,0x3($v0)
/*  f130884:	46802220 */ 	cvt.s.w	$f8,$f4
/*  f130888:	3c014f80 */ 	lui	$at,0x4f80
/*  f13088c:	448c9000 */ 	mtc1	$t4,$f18
/*  f130890:	468051a0 */ 	cvt.s.w	$f6,$f10
/*  f130894:	46809120 */ 	cvt.s.w	$f4,$f18
/*  f130898:	05810004 */ 	bgez	$t4,.L0f1308ac
/*  f13089c:	46064003 */ 	div.s	$f0,$f8,$f6
/*  f1308a0:	44815000 */ 	mtc1	$at,$f10
/*  f1308a4:	00000000 */ 	nop
/*  f1308a8:	460a2100 */ 	add.s	$f4,$f4,$f10
.L0f1308ac:
/*  f1308ac:	46002202 */ 	mul.s	$f8,$f4,$f0
/*  f1308b0:	24180001 */ 	addiu	$t8,$zero,0x1
/*  f1308b4:	3c014f00 */ 	lui	$at,0x4f00
/*  f1308b8:	444df800 */ 	cfc1	$t5,$31
/*  f1308bc:	44d8f800 */ 	ctc1	$t8,$31
/*  f1308c0:	00000000 */ 	nop
/*  f1308c4:	460041a4 */ 	cvt.w.s	$f6,$f8
/*  f1308c8:	4458f800 */ 	cfc1	$t8,$31
/*  f1308cc:	00000000 */ 	nop
/*  f1308d0:	33180078 */ 	andi	$t8,$t8,0x78
/*  f1308d4:	53000013 */ 	beqzl	$t8,.L0f130924
/*  f1308d8:	44183000 */ 	mfc1	$t8,$f6
/*  f1308dc:	44813000 */ 	mtc1	$at,$f6
/*  f1308e0:	24180001 */ 	addiu	$t8,$zero,0x1
/*  f1308e4:	46064181 */ 	sub.s	$f6,$f8,$f6
/*  f1308e8:	44d8f800 */ 	ctc1	$t8,$31
/*  f1308ec:	00000000 */ 	nop
/*  f1308f0:	460031a4 */ 	cvt.w.s	$f6,$f6
/*  f1308f4:	4458f800 */ 	cfc1	$t8,$31
/*  f1308f8:	00000000 */ 	nop
/*  f1308fc:	33180078 */ 	andi	$t8,$t8,0x78
/*  f130900:	17000005 */ 	bnez	$t8,.L0f130918
/*  f130904:	00000000 */ 	nop
/*  f130908:	44183000 */ 	mfc1	$t8,$f6
/*  f13090c:	3c018000 */ 	lui	$at,0x8000
/*  f130910:	10000007 */ 	b	.L0f130930
/*  f130914:	0301c025 */ 	or	$t8,$t8,$at
.L0f130918:
/*  f130918:	10000005 */ 	b	.L0f130930
/*  f13091c:	2418ffff */ 	addiu	$t8,$zero,-1
/*  f130920:	44183000 */ 	mfc1	$t8,$f6
.L0f130924:
/*  f130924:	00000000 */ 	nop
/*  f130928:	0700fffb */ 	bltz	$t8,.L0f130918
/*  f13092c:	00000000 */ 	nop
.L0f130930:
/*  f130930:	90590007 */ 	lbu	$t9,0x7($v0)
/*  f130934:	44cdf800 */ 	ctc1	$t5,$31
/*  f130938:	a0580003 */ 	sb	$t8,0x3($v0)
/*  f13093c:	44999000 */ 	mtc1	$t9,$f18
/*  f130940:	3c014f80 */ 	lui	$at,0x4f80
/*  f130944:	07210004 */ 	bgez	$t9,.L0f130958
/*  f130948:	468092a0 */ 	cvt.s.w	$f10,$f18
/*  f13094c:	44812000 */ 	mtc1	$at,$f4
/*  f130950:	00000000 */ 	nop
/*  f130954:	46045280 */ 	add.s	$f10,$f10,$f4
.L0f130958:
/*  f130958:	46005202 */ 	mul.s	$f8,$f10,$f0
/*  f13095c:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f130960:	3c014f00 */ 	lui	$at,0x4f00
/*  f130964:	444ef800 */ 	cfc1	$t6,$31
/*  f130968:	44cff800 */ 	ctc1	$t7,$31
/*  f13096c:	00000000 */ 	nop
/*  f130970:	460041a4 */ 	cvt.w.s	$f6,$f8
/*  f130974:	444ff800 */ 	cfc1	$t7,$31
/*  f130978:	00000000 */ 	nop
/*  f13097c:	31ef0078 */ 	andi	$t7,$t7,0x78
/*  f130980:	51e00013 */ 	beqzl	$t7,.L0f1309d0
/*  f130984:	440f3000 */ 	mfc1	$t7,$f6
/*  f130988:	44813000 */ 	mtc1	$at,$f6
/*  f13098c:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f130990:	46064181 */ 	sub.s	$f6,$f8,$f6
/*  f130994:	44cff800 */ 	ctc1	$t7,$31
/*  f130998:	00000000 */ 	nop
/*  f13099c:	460031a4 */ 	cvt.w.s	$f6,$f6
/*  f1309a0:	444ff800 */ 	cfc1	$t7,$31
/*  f1309a4:	00000000 */ 	nop
/*  f1309a8:	31ef0078 */ 	andi	$t7,$t7,0x78
/*  f1309ac:	15e00005 */ 	bnez	$t7,.L0f1309c4
/*  f1309b0:	00000000 */ 	nop
/*  f1309b4:	440f3000 */ 	mfc1	$t7,$f6
/*  f1309b8:	3c018000 */ 	lui	$at,0x8000
/*  f1309bc:	10000007 */ 	b	.L0f1309dc
/*  f1309c0:	01e17825 */ 	or	$t7,$t7,$at
.L0f1309c4:
/*  f1309c4:	10000005 */ 	b	.L0f1309dc
/*  f1309c8:	240fffff */ 	addiu	$t7,$zero,-1
/*  f1309cc:	440f3000 */ 	mfc1	$t7,$f6
.L0f1309d0:
/*  f1309d0:	00000000 */ 	nop
/*  f1309d4:	05e0fffb */ 	bltz	$t7,.L0f1309c4
/*  f1309d8:	00000000 */ 	nop
.L0f1309dc:
/*  f1309dc:	44cef800 */ 	ctc1	$t6,$31
/*  f1309e0:	a04f0007 */ 	sb	$t7,0x7($v0)
/*  f1309e4:	00000000 */ 	nop
.L0f1309e8:
/*  f1309e8:	8fb00170 */ 	lw	$s0,0x170($sp)
.L0f1309ec:
/*  f1309ec:	354a0008 */ 	ori	$t2,$t2,0x8
/*  f1309f0:	02202025 */ 	or	$a0,$s1,$zero
/*  f1309f4:	26090008 */ 	addiu	$t1,$s0,0x8
/*  f1309f8:	afa90170 */ 	sw	$t1,0x170($sp)
/*  f1309fc:	0c012d20 */ 	jal	osVirtualToPhysical
/*  f130a00:	ae0a0000 */ 	sw	$t2,0x0($s0)
/*  f130a04:	ae020004 */ 	sw	$v0,0x4($s0)
/*  f130a08:	3c017f1b */ 	lui	$at,%hi(var7f1b5610)
/*  f130a0c:	c4325610 */ 	lwc1	$f18,%lo(var7f1b5610)($at)
/*  f130a10:	4612b582 */ 	mul.s	$f22,$f22,$f18
/*  f130a14:	0c002f9d */ 	jal	viGetFovY
/*  f130a18:	00000000 */ 	nop
/*  f130a1c:	3c014270 */ 	lui	$at,0x4270
/*  f130a20:	44812000 */ 	mtc1	$at,$f4
/*  f130a24:	27a400d4 */ 	addiu	$a0,$sp,0xd4
/*  f130a28:	46040283 */ 	div.s	$f10,$f0,$f4
/*  f130a2c:	460ab582 */ 	mul.s	$f22,$f22,$f10
/*  f130a30:	0c00566c */ 	jal	mtx4LoadIdentity
/*  f130a34:	00000000 */ 	nop
/*  f130a38:	e7bc00d4 */ 	swc1	$f28,0xd4($sp)
/*  f130a3c:	e7bc00e8 */ 	swc1	$f28,0xe8($sp)
/*  f130a40:	e7bc00fc */ 	swc1	$f28,0xfc($sp)
/*  f130a44:	e7bc0110 */ 	swc1	$f28,0x110($sp)
/*  f130a48:	02a02025 */ 	or	$a0,$s5,$zero
/*  f130a4c:	0c005775 */ 	jal	mtx4SetTranslation
/*  f130a50:	27a500d4 */ 	addiu	$a1,$sp,0xd4
/*  f130a54:	0fc2d5be */ 	jal	camGetMatrix1740
/*  f130a58:	00000000 */ 	nop
/*  f130a5c:	00402025 */ 	or	$a0,$v0,$zero
/*  f130a60:	0c0056f8 */ 	jal	mtx00015be0
/*  f130a64:	27a500d4 */ 	addiu	$a1,$sp,0xd4
/*  f130a68:	0fc59e66 */ 	jal	gfxAllocateMatrix
/*  f130a6c:	00000000 */ 	nop
/*  f130a70:	00408825 */ 	or	$s1,$v0,$zero
/*  f130a74:	27a400d4 */ 	addiu	$a0,$sp,0xd4
/*  f130a78:	0c005815 */ 	jal	mtx00016054
/*  f130a7c:	00402825 */ 	or	$a1,$v0,$zero
/*  f130a80:	8fb00170 */ 	lw	$s0,0x170($sp)
/*  f130a84:	3c0d0102 */ 	lui	$t5,0x102
/*  f130a88:	35ad0040 */ 	ori	$t5,$t5,0x40
/*  f130a8c:	260c0008 */ 	addiu	$t4,$s0,0x8
/*  f130a90:	afac0170 */ 	sw	$t4,0x170($sp)
/*  f130a94:	02202025 */ 	or	$a0,$s1,$zero
/*  f130a98:	0c012d20 */ 	jal	osVirtualToPhysical
/*  f130a9c:	ae0d0000 */ 	sw	$t5,0x0($s0)
/*  f130aa0:	ae020004 */ 	sw	$v0,0x4($s0)
/*  f130aa4:	8e780004 */ 	lw	$t8,0x4($s3)
/*  f130aa8:	8e75000c */ 	lw	$s5,0xc($s3)
/*  f130aac:	1b000151 */ 	blez	$t8,.L0f130ff4
/*  f130ab0:	0015c8c0 */ 	sll	$t9,$s5,0x3
.L0f130ab4:
/*  f130ab4:	0335c823 */ 	subu	$t9,$t9,$s5
/*  f130ab8:	3c0e800a */ 	lui	$t6,%hi(g_Sparks)
/*  f130abc:	25ce34d0 */ 	addiu	$t6,$t6,%lo(g_Sparks)
/*  f130ac0:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f130ac4:	032e8821 */ 	addu	$s1,$t9,$t6
/*  f130ac8:	8e2f0018 */ 	lw	$t7,0x18($s1)
/*  f130acc:	51e00140 */ 	beqzl	$t7,.L0f130fd0
/*  f130ad0:	26b50001 */ 	addiu	$s5,$s5,0x1
/*  f130ad4:	0fc59e59 */ 	jal	gfxAllocateVertices
/*  f130ad8:	24040003 */ 	addiu	$a0,$zero,0x3
/*  f130adc:	00408025 */ 	or	$s0,$v0,$zero
/*  f130ae0:	00002025 */ 	or	$a0,$zero,$zero
/*  f130ae4:	00401825 */ 	or	$v1,$v0,$zero
.L0f130ae8:
/*  f130ae8:	24840001 */ 	addiu	$a0,$a0,0x1
/*  f130aec:	2463000c */ 	addiu	$v1,$v1,0xc
/*  f130af0:	a460fffc */ 	sh	$zero,-0x4($v1)
/*  f130af4:	1494fffc */ 	bne	$a0,$s4,.L0f130ae8
/*  f130af8:	a460fffe */ 	sh	$zero,-0x2($v1)
/*  f130afc:	c62e000c */ 	lwc1	$f14,0xc($s1)
/*  f130b00:	c6220010 */ 	lwc1	$f2,0x10($s1)
/*  f130b04:	c6200014 */ 	lwc1	$f0,0x14($s1)
/*  f130b08:	460e7202 */ 	mul.s	$f8,$f14,$f14
/*  f130b0c:	00000000 */ 	nop
/*  f130b10:	46021182 */ 	mul.s	$f6,$f2,$f2
/*  f130b14:	46064480 */ 	add.s	$f18,$f8,$f6
/*  f130b18:	46000102 */ 	mul.s	$f4,$f0,$f0
/*  f130b1c:	0c012974 */ 	jal	sqrtf
/*  f130b20:	46122300 */ 	add.s	$f12,$f4,$f18
/*  f130b24:	8e680008 */ 	lw	$t0,0x8($s3)
/*  f130b28:	96490008 */ 	lhu	$t1,0x8($s2)
/*  f130b2c:	964b0004 */ 	lhu	$t3,0x4($s2)
/*  f130b30:	c6240000 */ 	lwc1	$f4,0x0($s1)
/*  f130b34:	01090019 */ 	multu	$t0,$t1
/*  f130b38:	24090004 */ 	addiu	$t1,$zero,0x4
/*  f130b3c:	4600248d */ 	trunc.w.s	$f18,$f4
/*  f130b40:	24010001 */ 	addiu	$at,$zero,0x1
/*  f130b44:	02002025 */ 	or	$a0,$s0,$zero
/*  f130b48:	44189000 */ 	mfc1	$t8,$f18
/*  f130b4c:	00000000 */ 	nop
/*  f130b50:	a6180000 */ 	sh	$t8,0x0($s0)
/*  f130b54:	00005012 */ 	mflo	$t2
/*  f130b58:	016a6021 */ 	addu	$t4,$t3,$t2
/*  f130b5c:	448c5000 */ 	mtc1	$t4,$f10
/*  f130b60:	240c0080 */ 	addiu	$t4,$zero,0x80
/*  f130b64:	2418ffe0 */ 	addiu	$t8,$zero,-32
/*  f130b68:	46805220 */ 	cvt.s.w	$f8,$f10
/*  f130b6c:	c62a0004 */ 	lwc1	$f10,0x4($s1)
/*  f130b70:	46164180 */ 	add.s	$f6,$f8,$f22
/*  f130b74:	4600520d */ 	trunc.w.s	$f8,$f10
/*  f130b78:	46003083 */ 	div.s	$f2,$f6,$f0
/*  f130b7c:	440e4000 */ 	mfc1	$t6,$f8
/*  f130b80:	00000000 */ 	nop
/*  f130b84:	a60e0002 */ 	sh	$t6,0x2($s0)
/*  f130b88:	c6260008 */ 	lwc1	$f6,0x8($s1)
/*  f130b8c:	a2090007 */ 	sb	$t1,0x7($s0)
/*  f130b90:	4600310d */ 	trunc.w.s	$f4,$f6
/*  f130b94:	44082000 */ 	mfc1	$t0,$f4
/*  f130b98:	00000000 */ 	nop
/*  f130b9c:	a6080004 */ 	sh	$t0,0x4($s0)
/*  f130ba0:	c632000c */ 	lwc1	$f18,0xc($s1)
/*  f130ba4:	c6280000 */ 	lwc1	$f8,0x0($s1)
/*  f130ba8:	46029282 */ 	mul.s	$f10,$f18,$f2
/*  f130bac:	46085180 */ 	add.s	$f6,$f10,$f8
/*  f130bb0:	4600310d */ 	trunc.w.s	$f4,$f6
/*  f130bb4:	440a2000 */ 	mfc1	$t2,$f4
/*  f130bb8:	00000000 */ 	nop
/*  f130bbc:	a60a000c */ 	sh	$t2,0xc($s0)
/*  f130bc0:	c6320010 */ 	lwc1	$f18,0x10($s1)
/*  f130bc4:	c6280004 */ 	lwc1	$f8,0x4($s1)
/*  f130bc8:	46029282 */ 	mul.s	$f10,$f18,$f2
/*  f130bcc:	46085180 */ 	add.s	$f6,$f10,$f8
/*  f130bd0:	4600310d */ 	trunc.w.s	$f4,$f6
/*  f130bd4:	440d2000 */ 	mfc1	$t5,$f4
/*  f130bd8:	00000000 */ 	nop
/*  f130bdc:	a60d000e */ 	sh	$t5,0xe($s0)
/*  f130be0:	c6320014 */ 	lwc1	$f18,0x14($s1)
/*  f130be4:	c6280008 */ 	lwc1	$f8,0x8($s1)
/*  f130be8:	a2000013 */ 	sb	$zero,0x13($s0)
/*  f130bec:	46029282 */ 	mul.s	$f10,$f18,$f2
/*  f130bf0:	240dff00 */ 	addiu	$t5,$zero,-256
/*  f130bf4:	46085180 */ 	add.s	$f6,$f10,$f8
/*  f130bf8:	4600310d */ 	trunc.w.s	$f4,$f6
/*  f130bfc:	44192000 */ 	mfc1	$t9,$f4
/*  f130c00:	00000000 */ 	nop
/*  f130c04:	a6190010 */ 	sh	$t9,0x10($s0)
/*  f130c08:	c632000c */ 	lwc1	$f18,0xc($s1)
/*  f130c0c:	c6280000 */ 	lwc1	$f8,0x0($s1)
/*  f130c10:	24190120 */ 	addiu	$t9,$zero,0x120
/*  f130c14:	46029282 */ 	mul.s	$f10,$f18,$f2
/*  f130c18:	46085180 */ 	add.s	$f6,$f10,$f8
/*  f130c1c:	4600310d */ 	trunc.w.s	$f4,$f6
/*  f130c20:	440f2000 */ 	mfc1	$t7,$f4
/*  f130c24:	00000000 */ 	nop
/*  f130c28:	a60f0018 */ 	sh	$t7,0x18($s0)
/*  f130c2c:	c6320010 */ 	lwc1	$f18,0x10($s1)
/*  f130c30:	c6280004 */ 	lwc1	$f8,0x4($s1)
/*  f130c34:	46029282 */ 	mul.s	$f10,$f18,$f2
/*  f130c38:	46085180 */ 	add.s	$f6,$f10,$f8
/*  f130c3c:	4600310d */ 	trunc.w.s	$f4,$f6
/*  f130c40:	44092000 */ 	mfc1	$t1,$f4
/*  f130c44:	00000000 */ 	nop
/*  f130c48:	a609001a */ 	sh	$t1,0x1a($s0)
/*  f130c4c:	c6320014 */ 	lwc1	$f18,0x14($s1)
/*  f130c50:	c6280008 */ 	lwc1	$f8,0x8($s1)
/*  f130c54:	a200001f */ 	sb	$zero,0x1f($s0)
/*  f130c58:	46029282 */ 	mul.s	$f10,$f18,$f2
/*  f130c5c:	a60c0008 */ 	sh	$t4,0x8($s0)
/*  f130c60:	a60d000a */ 	sh	$t5,0xa($s0)
/*  f130c64:	a6180014 */ 	sh	$t8,0x14($s0)
/*  f130c68:	a61e0016 */ 	sh	$s8,0x16($s0)
/*  f130c6c:	a6190020 */ 	sh	$t9,0x20($s0)
/*  f130c70:	a61e0022 */ 	sh	$s8,0x22($s0)
/*  f130c74:	46085180 */ 	add.s	$f6,$f10,$f8
/*  f130c78:	4600310d */ 	trunc.w.s	$f4,$f6
/*  f130c7c:	440a2000 */ 	mfc1	$t2,$f4
/*  f130c80:	12e00007 */ 	beqz	$s7,.L0f130ca0
/*  f130c84:	a60a001c */ 	sh	$t2,0x1c($s0)
/*  f130c88:	12e10044 */ 	beq	$s7,$at,.L0f130d9c
/*  f130c8c:	24010002 */ 	addiu	$at,$zero,0x2
/*  f130c90:	52e10082 */ 	beql	$s7,$at,.L0f130e9c
/*  f130c94:	c62e000c */ 	lwc1	$f14,0xc($s1)
/*  f130c98:	100000be */ 	b	.L0f130f94
/*  f130c9c:	8fb10170 */ 	lw	$s1,0x170($sp)
.L0f130ca0:
/*  f130ca0:	c6200014 */ 	lwc1	$f0,0x14($s1)
/*  f130ca4:	4600b48d */ 	trunc.w.s	$f18,$f22
/*  f130ca8:	4600a03c */ 	c.lt.s	$f20,$f0
/*  f130cac:	44029000 */ 	mfc1	$v0,$f18
/*  f130cb0:	45020004 */ 	bc1fl	.L0f130cc4
/*  f130cb4:	46000407 */ 	neg.s	$f16,$f0
/*  f130cb8:	10000002 */ 	b	.L0f130cc4
/*  f130cbc:	46000406 */ 	mov.s	$f16,$f0
/*  f130cc0:	46000407 */ 	neg.s	$f16,$f0
.L0f130cc4:
/*  f130cc4:	c6220010 */ 	lwc1	$f2,0x10($s1)
/*  f130cc8:	4602a03c */ 	c.lt.s	$f20,$f2
/*  f130ccc:	00000000 */ 	nop
/*  f130cd0:	45020004 */ 	bc1fl	.L0f130ce4
/*  f130cd4:	46001307 */ 	neg.s	$f12,$f2
/*  f130cd8:	10000002 */ 	b	.L0f130ce4
/*  f130cdc:	46001306 */ 	mov.s	$f12,$f2
/*  f130ce0:	46001307 */ 	neg.s	$f12,$f2
.L0f130ce4:
/*  f130ce4:	4610603c */ 	c.lt.s	$f12,$f16
/*  f130ce8:	00000000 */ 	nop
/*  f130cec:	45020017 */ 	bc1fl	.L0f130d4c
/*  f130cf0:	8e6e0008 */ 	lw	$t6,0x8($s3)
/*  f130cf4:	8e6b0008 */ 	lw	$t3,0x8($s3)
/*  f130cf8:	964a000a */ 	lhu	$t2,0xa($s2)
/*  f130cfc:	860f000e */ 	lh	$t7,0xe($s0)
/*  f130d00:	96480006 */ 	lhu	$t0,0x6($s2)
/*  f130d04:	016a0019 */ 	multu	$t3,$t2
/*  f130d08:	8619001a */ 	lh	$t9,0x1a($s0)
/*  f130d0c:	01e84823 */ 	subu	$t1,$t7,$t0
/*  f130d10:	00006012 */ 	mflo	$t4
/*  f130d14:	012c6823 */ 	subu	$t5,$t1,$t4
/*  f130d18:	01a2c023 */ 	subu	$t8,$t5,$v0
/*  f130d1c:	a618000e */ 	sh	$t8,0xe($s0)
/*  f130d20:	964b000a */ 	lhu	$t3,0xa($s2)
/*  f130d24:	8e680008 */ 	lw	$t0,0x8($s3)
/*  f130d28:	964e0006 */ 	lhu	$t6,0x6($s2)
/*  f130d2c:	010b0019 */ 	multu	$t0,$t3
/*  f130d30:	032e7821 */ 	addu	$t7,$t9,$t6
/*  f130d34:	00005012 */ 	mflo	$t2
/*  f130d38:	01ea4821 */ 	addu	$t1,$t7,$t2
/*  f130d3c:	01226021 */ 	addu	$t4,$t1,$v0
/*  f130d40:	10000093 */ 	b	.L0f130f90
/*  f130d44:	a60c001a */ 	sh	$t4,0x1a($s0)
/*  f130d48:	8e6e0008 */ 	lw	$t6,0x8($s3)
.L0f130d4c:
/*  f130d4c:	9648000a */ 	lhu	$t0,0xa($s2)
/*  f130d50:	860d0010 */ 	lh	$t5,0x10($s0)
/*  f130d54:	96580006 */ 	lhu	$t8,0x6($s2)
/*  f130d58:	01c80019 */ 	multu	$t6,$t0
/*  f130d5c:	8609001c */ 	lh	$t1,0x1c($s0)
/*  f130d60:	01b8c823 */ 	subu	$t9,$t5,$t8
/*  f130d64:	00005812 */ 	mflo	$t3
/*  f130d68:	032b7823 */ 	subu	$t7,$t9,$t3
/*  f130d6c:	01e25023 */ 	subu	$t2,$t7,$v0
/*  f130d70:	a60a0010 */ 	sh	$t2,0x10($s0)
/*  f130d74:	964e000a */ 	lhu	$t6,0xa($s2)
/*  f130d78:	8e780008 */ 	lw	$t8,0x8($s3)
/*  f130d7c:	964c0006 */ 	lhu	$t4,0x6($s2)
/*  f130d80:	030e0019 */ 	multu	$t8,$t6
/*  f130d84:	012c6821 */ 	addu	$t5,$t1,$t4
/*  f130d88:	00004012 */ 	mflo	$t0
/*  f130d8c:	01a8c821 */ 	addu	$t9,$t5,$t0
/*  f130d90:	03225821 */ 	addu	$t3,$t9,$v0
/*  f130d94:	1000007e */ 	b	.L0f130f90
/*  f130d98:	a60b001c */ 	sh	$t3,0x1c($s0)
.L0f130d9c:
/*  f130d9c:	c62e000c */ 	lwc1	$f14,0xc($s1)
/*  f130da0:	4600b28d */ 	trunc.w.s	$f10,$f22
/*  f130da4:	460ea03c */ 	c.lt.s	$f20,$f14
/*  f130da8:	44025000 */ 	mfc1	$v0,$f10
/*  f130dac:	45020004 */ 	bc1fl	.L0f130dc0
/*  f130db0:	46007407 */ 	neg.s	$f16,$f14
/*  f130db4:	10000002 */ 	b	.L0f130dc0
/*  f130db8:	46007406 */ 	mov.s	$f16,$f14
/*  f130dbc:	46007407 */ 	neg.s	$f16,$f14
.L0f130dc0:
/*  f130dc0:	c6200014 */ 	lwc1	$f0,0x14($s1)
/*  f130dc4:	4600a03c */ 	c.lt.s	$f20,$f0
/*  f130dc8:	00000000 */ 	nop
/*  f130dcc:	45020004 */ 	bc1fl	.L0f130de0
/*  f130dd0:	46000307 */ 	neg.s	$f12,$f0
/*  f130dd4:	10000002 */ 	b	.L0f130de0
/*  f130dd8:	46000306 */ 	mov.s	$f12,$f0
/*  f130ddc:	46000307 */ 	neg.s	$f12,$f0
.L0f130de0:
/*  f130de0:	4610603c */ 	c.lt.s	$f12,$f16
/*  f130de4:	00000000 */ 	nop
/*  f130de8:	45020017 */ 	bc1fl	.L0f130e48
/*  f130dec:	8e6f0008 */ 	lw	$t7,0x8($s3)
/*  f130df0:	8e780008 */ 	lw	$t8,0x8($s3)
/*  f130df4:	964e000a */ 	lhu	$t6,0xa($s2)
/*  f130df8:	860a0010 */ 	lh	$t2,0x10($s0)
/*  f130dfc:	96490006 */ 	lhu	$t1,0x6($s2)
/*  f130e00:	030e0019 */ 	multu	$t8,$t6
/*  f130e04:	860b001c */ 	lh	$t3,0x1c($s0)
/*  f130e08:	01496023 */ 	subu	$t4,$t2,$t1
/*  f130e0c:	00006812 */ 	mflo	$t5
/*  f130e10:	018d4023 */ 	subu	$t0,$t4,$t5
/*  f130e14:	0102c823 */ 	subu	$t9,$t0,$v0
/*  f130e18:	a6190010 */ 	sh	$t9,0x10($s0)
/*  f130e1c:	9658000a */ 	lhu	$t8,0xa($s2)
/*  f130e20:	8e690008 */ 	lw	$t1,0x8($s3)
/*  f130e24:	964f0006 */ 	lhu	$t7,0x6($s2)
/*  f130e28:	01380019 */ 	multu	$t1,$t8
/*  f130e2c:	016f5021 */ 	addu	$t2,$t3,$t7
/*  f130e30:	00007012 */ 	mflo	$t6
/*  f130e34:	014e6021 */ 	addu	$t4,$t2,$t6
/*  f130e38:	01826821 */ 	addu	$t5,$t4,$v0
/*  f130e3c:	10000054 */ 	b	.L0f130f90
/*  f130e40:	a60d001c */ 	sh	$t5,0x1c($s0)
/*  f130e44:	8e6f0008 */ 	lw	$t7,0x8($s3)
.L0f130e48:
/*  f130e48:	9649000a */ 	lhu	$t1,0xa($s2)
/*  f130e4c:	8608000c */ 	lh	$t0,0xc($s0)
/*  f130e50:	96590006 */ 	lhu	$t9,0x6($s2)
/*  f130e54:	01e90019 */ 	multu	$t7,$t1
/*  f130e58:	860c0018 */ 	lh	$t4,0x18($s0)
/*  f130e5c:	01195823 */ 	subu	$t3,$t0,$t9
/*  f130e60:	0000c012 */ 	mflo	$t8
/*  f130e64:	01785023 */ 	subu	$t2,$t3,$t8
/*  f130e68:	01427023 */ 	subu	$t6,$t2,$v0
/*  f130e6c:	a60e000c */ 	sh	$t6,0xc($s0)
/*  f130e70:	964f000a */ 	lhu	$t7,0xa($s2)
/*  f130e74:	8e790008 */ 	lw	$t9,0x8($s3)
/*  f130e78:	964d0006 */ 	lhu	$t5,0x6($s2)
/*  f130e7c:	032f0019 */ 	multu	$t9,$t7
/*  f130e80:	018d4021 */ 	addu	$t0,$t4,$t5
/*  f130e84:	00004812 */ 	mflo	$t1
/*  f130e88:	01095821 */ 	addu	$t3,$t0,$t1
/*  f130e8c:	0162c021 */ 	addu	$t8,$t3,$v0
/*  f130e90:	1000003f */ 	b	.L0f130f90
/*  f130e94:	a6180018 */ 	sh	$t8,0x18($s0)
/*  f130e98:	c62e000c */ 	lwc1	$f14,0xc($s1)
.L0f130e9c:
/*  f130e9c:	4600b20d */ 	trunc.w.s	$f8,$f22
/*  f130ea0:	460ea03c */ 	c.lt.s	$f20,$f14
/*  f130ea4:	44024000 */ 	mfc1	$v0,$f8
/*  f130ea8:	45020004 */ 	bc1fl	.L0f130ebc
/*  f130eac:	46007407 */ 	neg.s	$f16,$f14
/*  f130eb0:	10000002 */ 	b	.L0f130ebc
/*  f130eb4:	46007406 */ 	mov.s	$f16,$f14
/*  f130eb8:	46007407 */ 	neg.s	$f16,$f14
.L0f130ebc:
/*  f130ebc:	c6220010 */ 	lwc1	$f2,0x10($s1)
/*  f130ec0:	4602a03c */ 	c.lt.s	$f20,$f2
/*  f130ec4:	00000000 */ 	nop
/*  f130ec8:	45020004 */ 	bc1fl	.L0f130edc
/*  f130ecc:	46001307 */ 	neg.s	$f12,$f2
/*  f130ed0:	10000002 */ 	b	.L0f130edc
/*  f130ed4:	46001306 */ 	mov.s	$f12,$f2
/*  f130ed8:	46001307 */ 	neg.s	$f12,$f2
.L0f130edc:
/*  f130edc:	4610603c */ 	c.lt.s	$f12,$f16
/*  f130ee0:	00000000 */ 	nop
/*  f130ee4:	45020017 */ 	bc1fl	.L0f130f44
/*  f130ee8:	8e6a0008 */ 	lw	$t2,0x8($s3)
/*  f130eec:	8e790008 */ 	lw	$t9,0x8($s3)
/*  f130ef0:	964f000a */ 	lhu	$t7,0xa($s2)
/*  f130ef4:	860e000e */ 	lh	$t6,0xe($s0)
/*  f130ef8:	964c0006 */ 	lhu	$t4,0x6($s2)
/*  f130efc:	032f0019 */ 	multu	$t9,$t7
/*  f130f00:	8618001a */ 	lh	$t8,0x1a($s0)
/*  f130f04:	01cc6823 */ 	subu	$t5,$t6,$t4
/*  f130f08:	00004012 */ 	mflo	$t0
/*  f130f0c:	01a84823 */ 	subu	$t1,$t5,$t0
/*  f130f10:	01225823 */ 	subu	$t3,$t1,$v0
/*  f130f14:	a60b000e */ 	sh	$t3,0xe($s0)
/*  f130f18:	9659000a */ 	lhu	$t9,0xa($s2)
/*  f130f1c:	8e6c0008 */ 	lw	$t4,0x8($s3)
/*  f130f20:	964a0006 */ 	lhu	$t2,0x6($s2)
/*  f130f24:	01990019 */ 	multu	$t4,$t9
/*  f130f28:	030a7021 */ 	addu	$t6,$t8,$t2
/*  f130f2c:	00007812 */ 	mflo	$t7
/*  f130f30:	01cf6821 */ 	addu	$t5,$t6,$t7
/*  f130f34:	01a24021 */ 	addu	$t0,$t5,$v0
/*  f130f38:	10000015 */ 	b	.L0f130f90
/*  f130f3c:	a608001a */ 	sh	$t0,0x1a($s0)
/*  f130f40:	8e6a0008 */ 	lw	$t2,0x8($s3)
.L0f130f44:
/*  f130f44:	964c000a */ 	lhu	$t4,0xa($s2)
/*  f130f48:	8609000c */ 	lh	$t1,0xc($s0)
/*  f130f4c:	964b0006 */ 	lhu	$t3,0x6($s2)
/*  f130f50:	014c0019 */ 	multu	$t2,$t4
/*  f130f54:	860d0018 */ 	lh	$t5,0x18($s0)
/*  f130f58:	012bc023 */ 	subu	$t8,$t1,$t3
/*  f130f5c:	0000c812 */ 	mflo	$t9
/*  f130f60:	03197023 */ 	subu	$t6,$t8,$t9
/*  f130f64:	01c27823 */ 	subu	$t7,$t6,$v0
/*  f130f68:	a60f000c */ 	sh	$t7,0xc($s0)
/*  f130f6c:	964a000a */ 	lhu	$t2,0xa($s2)
/*  f130f70:	8e6b0008 */ 	lw	$t3,0x8($s3)
/*  f130f74:	96480006 */ 	lhu	$t0,0x6($s2)
/*  f130f78:	016a0019 */ 	multu	$t3,$t2
/*  f130f7c:	01a84821 */ 	addu	$t1,$t5,$t0
/*  f130f80:	00006012 */ 	mflo	$t4
/*  f130f84:	012cc021 */ 	addu	$t8,$t1,$t4
/*  f130f88:	0302c821 */ 	addu	$t9,$t8,$v0
/*  f130f8c:	a6190018 */ 	sh	$t9,0x18($s0)
.L0f130f90:
/*  f130f90:	8fb10170 */ 	lw	$s1,0x170($sp)
.L0f130f94:
/*  f130f94:	3c0d0420 */ 	lui	$t5,0x420
/*  f130f98:	35ad0024 */ 	ori	$t5,$t5,0x24
/*  f130f9c:	262f0008 */ 	addiu	$t7,$s1,0x8
/*  f130fa0:	afaf0170 */ 	sw	$t7,0x170($sp)
/*  f130fa4:	0c012d20 */ 	jal	osVirtualToPhysical
/*  f130fa8:	ae2d0000 */ 	sw	$t5,0x0($s1)
/*  f130fac:	ae220004 */ 	sw	$v0,0x4($s1)
/*  f130fb0:	8fa80170 */ 	lw	$t0,0x170($sp)
/*  f130fb4:	3c0abf00 */ 	lui	$t2,0xbf00
/*  f130fb8:	24090a14 */ 	addiu	$t1,$zero,0xa14
/*  f130fbc:	250b0008 */ 	addiu	$t3,$t0,0x8
/*  f130fc0:	afab0170 */ 	sw	$t3,0x170($sp)
/*  f130fc4:	ad090004 */ 	sw	$t1,0x4($t0)
/*  f130fc8:	ad0a0000 */ 	sw	$t2,0x0($t0)
/*  f130fcc:	26b50001 */ 	addiu	$s5,$s5,0x1
.L0f130fd0:
/*  f130fd0:	24010064 */ 	addiu	$at,$zero,0x64
/*  f130fd4:	02a1001a */ 	div	$zero,$s5,$at
/*  f130fd8:	8fb8016c */ 	lw	$t8,0x16c($sp)
/*  f130fdc:	26d60001 */ 	addiu	$s6,$s6,0x1
/*  f130fe0:	0000a810 */ 	mfhi	$s5
/*  f130fe4:	8f190004 */ 	lw	$t9,0x4($t8)
/*  f130fe8:	02d9082a */ 	slt	$at,$s6,$t9
/*  f130fec:	5420feb1 */ 	bnezl	$at,.L0f130ab4
/*  f130ff0:	0015c8c0 */ 	sll	$t9,$s5,0x3
.L0f130ff4:
/*  f130ff4:	3c0e800a */ 	lui	$t6,%hi(g_NextSparkGroupIndex)
/*  f130ff8:	25ce4130 */ 	addiu	$t6,$t6,%lo(g_NextSparkGroupIndex)
/*  f130ffc:	26730024 */ 	addiu	$s3,$s3,0x24
/*  f131000:	566efcb4 */ 	bnel	$s3,$t6,.L0f1302d4
/*  f131004:	8e6c0008 */ 	lw	$t4,0x8($s3)
/*  f131008:	e7ba013c */ 	swc1	$f26,0x13c($sp)
/*  f13100c:	e7b60120 */ 	swc1	$f22,0x120($sp)
.L0f131010:
/*  f131010:	8fbf0074 */ 	lw	$ra,0x74($sp)
/*  f131014:	8fa20170 */ 	lw	$v0,0x170($sp)
/*  f131018:	d7b40028 */ 	ldc1	$f20,0x28($sp)
/*  f13101c:	d7b60030 */ 	ldc1	$f22,0x30($sp)
/*  f131020:	d7b80038 */ 	ldc1	$f24,0x38($sp)
/*  f131024:	d7ba0040 */ 	ldc1	$f26,0x40($sp)
/*  f131028:	d7bc0048 */ 	ldc1	$f28,0x48($sp)
/*  f13102c:	8fb00050 */ 	lw	$s0,0x50($sp)
/*  f131030:	8fb10054 */ 	lw	$s1,0x54($sp)
/*  f131034:	8fb20058 */ 	lw	$s2,0x58($sp)
/*  f131038:	8fb3005c */ 	lw	$s3,0x5c($sp)
/*  f13103c:	8fb40060 */ 	lw	$s4,0x60($sp)
/*  f131040:	8fb50064 */ 	lw	$s5,0x64($sp)
/*  f131044:	8fb60068 */ 	lw	$s6,0x68($sp)
/*  f131048:	8fb7006c */ 	lw	$s7,0x6c($sp)
/*  f13104c:	8fbe0070 */ 	lw	$s8,0x70($sp)
/*  f131050:	03e00008 */ 	jr	$ra
/*  f131054:	27bd0170 */ 	addiu	$sp,$sp,0x170
);
