#include <ultra64.h>
#include "constants.h"
#include "game/game_006900.h"
#include "game/tex.h"
#include "game/stars.h"
#include "game/game_1531a0.h"
#include "game/camera.h"
#include "bss.h"
#include "lib/vi.h"
#include "lib/memp.h"
#include "lib/rng.h"
#include "lib/mtx.h"
#include "data.h"
#include "types.h"

s32 g_StarCount;
s8 *g_StarPositions = NULL;
f32 *g_StarData3;
s32 g_StarGridSize;
s32 *g_StarPosIndexes;

bool g_StarsBelowHorizon = false;

void stars0f135c70(void)
{
	u32 stack[4];
	struct coord coord;
	f32 mult;
	s32 i;
	s32 j;
	s32 k;
	f32 tmp = g_StarGridSize * 0.5f;

	for (i = 0; i < 6; i++) {
		for (j = 0; j <= g_StarGridSize; j++) {
			for (k = 0; k <= g_StarGridSize; k++) {
				s32 index = ((i * (g_StarGridSize + 1) * (g_StarGridSize + 1)) + k + (j * (g_StarGridSize + 1))) * 3;

				switch (i) {
				case 0:
				case 1:
					coord.x = (i == 0 ? -1.0f : 1.0f);
					coord.y = k / tmp - 1;
					coord.z = j / tmp - 1;
					break;
				case 2:
				case 3:
					coord.y = (i == 2 ? -1.0f : 1.0f);
					coord.x = j / tmp - 1;
					coord.z = k / tmp - 1;
					break;
				case 4:
				case 5:
					coord.z = (i == 4 ? -1.0f : 1.0f);
					coord.x = k / tmp - 1;
					coord.y = j / tmp - 1;
					break;
				}

				mult = 1.0f / sqrtf(coord.f[0] * coord.f[0] + coord.f[1] * coord.f[1] + coord.f[2] * coord.f[2]);

				g_StarData3[index + 0] = coord.x * mult;
				g_StarData3[index + 1] = coord.y * mult;
				g_StarData3[index + 2] = coord.z * mult;
			}
		}
	}
}

/**
 * Insert a star position *after* the given index.
 */
void starInsert(s32 index, struct coord *arg1)
{
	s32 i;

	// Shuffle g_StarPositions forward after the insertion point
	for (i = g_StarPosIndexes[g_StarGridSize * 6 * g_StarGridSize] - 1; i >= g_StarPosIndexes[index + 1]; i--) {
		g_StarPositions[i * 3 + 3] = g_StarPositions[i * 3 + 0];
		g_StarPositions[i * 3 + 4] = g_StarPositions[i * 3 + 1];
		g_StarPositions[i * 3 + 5] = g_StarPositions[i * 3 + 2];
	}

	// Write new data
	g_StarPositions[g_StarPosIndexes[index + 1] * 3 + 0] = arg1->x * 127;
	g_StarPositions[g_StarPosIndexes[index + 1] * 3 + 1] = arg1->y * 127;
	g_StarPositions[g_StarPosIndexes[index + 1] * 3 + 2] = arg1->z * 127;

	// Increment indexes after the insertion point
	for (i = index + 1; i <= g_StarGridSize * 6 * g_StarGridSize; i++) {
		g_StarPosIndexes[i]++;
	}
}

GLOBAL_ASM(
glabel starsReset
/*  f1360e8:	27bdff18 */ 	addiu	$sp,$sp,-232
/*  f1360ec:	3c05800a */ 	lui	$a1,%hi(g_Vars)
/*  f1360f0:	24a59fc0 */ 	addiu	$a1,$a1,%lo(g_Vars)
/*  f1360f4:	8cae006c */ 	lw	$t6,0x6c($a1)
/*  f1360f8:	afb00044 */ 	sw	$s0,0x44($sp)
/*  f1360fc:	3c108008 */ 	lui	$s0,%hi(g_StarPositions)
/*  f136100:	2610f120 */ 	addiu	$s0,$s0,%lo(g_StarPositions)
/*  f136104:	afbf004c */ 	sw	$ra,0x4c($sp)
/*  f136108:	afb10048 */ 	sw	$s1,0x48($sp)
/*  f13610c:	f7be0038 */ 	sdc1	$f30,0x38($sp)
/*  f136110:	f7bc0030 */ 	sdc1	$f28,0x30($sp)
/*  f136114:	f7ba0028 */ 	sdc1	$f26,0x28($sp)
/*  f136118:	f7b80020 */ 	sdc1	$f24,0x20($sp)
/*  f13611c:	f7b60018 */ 	sdc1	$f22,0x18($sp)
/*  f136120:	f7b40010 */ 	sdc1	$f20,0x10($sp)
/*  f136124:	11c00003 */ 	beqz	$t6,.L0f136134
/*  f136128:	ae000000 */ 	sw	$zero,0x0($s0)
/*  f13612c:	10000002 */ 	b	.L0f136138
/*  f136130:	24060001 */ 	addiu	$a2,$zero,0x1
.L0f136134:
/*  f136134:	00003025 */ 	or	$a2,$zero,$zero
.L0f136138:
/*  f136138:	8caf0068 */ 	lw	$t7,0x68($a1)
/*  f13613c:	00001825 */ 	or	$v1,$zero,$zero
/*  f136140:	00002025 */ 	or	$a0,$zero,$zero
/*  f136144:	11e00003 */ 	beqz	$t7,.L0f136154
/*  f136148:	00001025 */ 	or	$v0,$zero,$zero
/*  f13614c:	10000001 */ 	b	.L0f136154
/*  f136150:	24030001 */ 	addiu	$v1,$zero,0x1
.L0f136154:
/*  f136154:	8cb80064 */ 	lw	$t8,0x64($a1)
/*  f136158:	3c088008 */ 	lui	$t0,%hi(g_StarsBelowHorizon)
/*  f13615c:	2508f124 */ 	addiu	$t0,$t0,%lo(g_StarsBelowHorizon)
/*  f136160:	13000003 */ 	beqz	$t8,.L0f136170
/*  f136164:	240c0003 */ 	addiu	$t4,$zero,0x3
/*  f136168:	10000001 */ 	b	.L0f136170
/*  f13616c:	24040001 */ 	addiu	$a0,$zero,0x1
.L0f136170:
/*  f136170:	8cb90070 */ 	lw	$t9,0x70($a1)
/*  f136174:	13200003 */ 	beqz	$t9,.L0f136184
/*  f136178:	00000000 */ 	nop
/*  f13617c:	10000001 */ 	b	.L0f136184
/*  f136180:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f136184:
/*  f136184:	00444821 */ 	addu	$t1,$v0,$a0
/*  f136188:	01235021 */ 	addu	$t2,$t1,$v1
/*  f13618c:	01465821 */ 	addu	$t3,$t2,$a2
/*  f136190:	29610002 */ 	slti	$at,$t3,0x2
/*  f136194:	102001ae */ 	beqz	$at,.L0f136850
/*  f136198:	3c03800a */ 	lui	$v1,%hi(g_StarGridSize)
/*  f13619c:	8ca204b4 */ 	lw	$v0,0x4b4($a1)
/*  f1361a0:	24634158 */ 	addiu	$v1,$v1,%lo(g_StarGridSize)
/*  f1361a4:	2401004e */ 	addiu	$at,$zero,0x4e
/*  f1361a8:	ad000000 */ 	sw	$zero,0x0($t0)
/*  f1361ac:	14410007 */ 	bne	$v0,$at,.L0f1361cc
/*  f1361b0:	ac6c0000 */ 	sw	$t4,0x0($v1)
/*  f1361b4:	240d0001 */ 	addiu	$t5,$zero,0x1
/*  f1361b8:	ad0d0000 */ 	sw	$t5,0x0($t0)
/*  f1361bc:	240e0640 */ 	addiu	$t6,$zero,0x640
/*  f1361c0:	3c01800a */ 	lui	$at,%hi(g_StarCount)
/*  f1361c4:	10000018 */ 	b	.L0f136228
/*  f1361c8:	ac2e4150 */ 	sw	$t6,%lo(g_StarCount)($at)
.L0f1361cc:
/*  f1361cc:	24010030 */ 	addiu	$at,$zero,0x30
/*  f1361d0:	10410003 */ 	beq	$v0,$at,.L0f1361e0
/*  f1361d4:	240f00c8 */ 	addiu	$t7,$zero,0xc8
/*  f1361d8:	24010022 */ 	addiu	$at,$zero,0x22
/*  f1361dc:	14410005 */ 	bne	$v0,$at,.L0f1361f4
.L0f1361e0:
/*  f1361e0:	3c01800a */ 	lui	$at,%hi(g_StarCount)
/*  f1361e4:	ac2f4150 */ 	sw	$t7,%lo(g_StarCount)($at)
/*  f1361e8:	24180002 */ 	addiu	$t8,$zero,0x2
/*  f1361ec:	1000000e */ 	b	.L0f136228
/*  f1361f0:	ac780000 */ 	sw	$t8,0x0($v1)
.L0f1361f4:
/*  f1361f4:	24010034 */ 	addiu	$at,$zero,0x34
/*  f1361f8:	14410007 */ 	bne	$v0,$at,.L0f136218
/*  f1361fc:	240a00c8 */ 	addiu	$t2,$zero,0xc8
/*  f136200:	24190001 */ 	addiu	$t9,$zero,0x1
/*  f136204:	ad190000 */ 	sw	$t9,0x0($t0)
/*  f136208:	240904b0 */ 	addiu	$t1,$zero,0x4b0
/*  f13620c:	3c01800a */ 	lui	$at,%hi(g_StarCount)
/*  f136210:	10000005 */ 	b	.L0f136228
/*  f136214:	ac294150 */ 	sw	$t1,%lo(g_StarCount)($at)
.L0f136218:
/*  f136218:	3c01800a */ 	lui	$at,%hi(g_StarCount)
/*  f13621c:	ac2a4150 */ 	sw	$t2,%lo(g_StarCount)($at)
/*  f136220:	240b0002 */ 	addiu	$t3,$zero,0x2
/*  f136224:	ac6b0000 */ 	sw	$t3,0x0($v1)
.L0f136228:
/*  f136228:	8c670000 */ 	lw	$a3,0x0($v1)
/*  f13622c:	24060006 */ 	addiu	$a2,$zero,0x6
/*  f136230:	3c0c800a */ 	lui	$t4,%hi(g_StarCount)
/*  f136234:	24e20001 */ 	addiu	$v0,$a3,0x1
/*  f136238:	000270c0 */ 	sll	$t6,$v0,0x3
/*  f13623c:	01c27021 */ 	addu	$t6,$t6,$v0
/*  f136240:	000e70c0 */ 	sll	$t6,$t6,0x3
/*  f136244:	01c20019 */ 	multu	$t6,$v0
/*  f136248:	8d8c4150 */ 	lw	$t4,%lo(g_StarCount)($t4)
/*  f13624c:	24050004 */ 	addiu	$a1,$zero,0x4
/*  f136250:	000c6880 */ 	sll	$t5,$t4,0x2
/*  f136254:	01ac6823 */ 	subu	$t5,$t5,$t4
/*  f136258:	00007812 */ 	mflo	$t7
/*  f13625c:	01afc021 */ 	addu	$t8,$t5,$t7
/*  f136260:	00000000 */ 	nop
/*  f136264:	00e60019 */ 	multu	$a3,$a2
/*  f136268:	0000c812 */ 	mflo	$t9
/*  f13626c:	00000000 */ 	nop
/*  f136270:	00000000 */ 	nop
/*  f136274:	03270019 */ 	multu	$t9,$a3
/*  f136278:	00004812 */ 	mflo	$t1
/*  f13627c:	00095080 */ 	sll	$t2,$t1,0x2
/*  f136280:	030a2021 */ 	addu	$a0,$t8,$t2
/*  f136284:	24840043 */ 	addiu	$a0,$a0,0x43
/*  f136288:	348b003f */ 	ori	$t3,$a0,0x3f
/*  f13628c:	0c0048f2 */ 	jal	mempAlloc
/*  f136290:	3964003f */ 	xori	$a0,$t3,0x3f
/*  f136294:	24060006 */ 	addiu	$a2,$zero,0x6
/*  f136298:	1040016d */ 	beqz	$v0,.L0f136850
/*  f13629c:	ae020000 */ 	sw	$v0,0x0($s0)
/*  f1362a0:	3c08800a */ 	lui	$t0,%hi(g_StarGridSize)
/*  f1362a4:	25084158 */ 	addiu	$t0,$t0,%lo(g_StarGridSize)
/*  f1362a8:	8d070000 */ 	lw	$a3,0x0($t0)
/*  f1362ac:	3c0e800a */ 	lui	$t6,%hi(g_StarCount)
/*  f1362b0:	8dce4150 */ 	lw	$t6,%lo(g_StarCount)($t6)
/*  f1362b4:	00e60019 */ 	multu	$a3,$a2
/*  f1362b8:	3c04800a */ 	lui	$a0,%hi(g_StarPosIndexes)
/*  f1362bc:	000e6880 */ 	sll	$t5,$t6,0x2
/*  f1362c0:	01ae6823 */ 	subu	$t5,$t5,$t6
/*  f1362c4:	2484415c */ 	addiu	$a0,$a0,%lo(g_StarPosIndexes)
/*  f1362c8:	01a27821 */ 	addu	$t7,$t5,$v0
/*  f1362cc:	ac8f0000 */ 	sw	$t7,0x0($a0)
/*  f1362d0:	00001025 */ 	or	$v0,$zero,$zero
/*  f1362d4:	00008825 */ 	or	$s1,$zero,$zero
/*  f1362d8:	0000c812 */ 	mflo	$t9
/*  f1362dc:	00000000 */ 	nop
/*  f1362e0:	00000000 */ 	nop
/*  f1362e4:	03270019 */ 	multu	$t9,$a3
/*  f1362e8:	00001812 */ 	mflo	$v1
/*  f1362ec:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f1362f0:	58600013 */ 	blezl	$v1,.L0f136340
/*  f1362f4:	8c8c0000 */ 	lw	$t4,0x0($a0)
/*  f1362f8:	8c890000 */ 	lw	$t1,0x0($a0)
.L0f1362fc:
/*  f1362fc:	26310001 */ 	addiu	$s1,$s1,0x1
/*  f136300:	0122c021 */ 	addu	$t8,$t1,$v0
/*  f136304:	af000000 */ 	sw	$zero,0x0($t8)
/*  f136308:	8d070000 */ 	lw	$a3,0x0($t0)
/*  f13630c:	24420004 */ 	addiu	$v0,$v0,0x4
/*  f136310:	00e60019 */ 	multu	$a3,$a2
/*  f136314:	00005012 */ 	mflo	$t2
/*  f136318:	00000000 */ 	nop
/*  f13631c:	00000000 */ 	nop
/*  f136320:	01470019 */ 	multu	$t2,$a3
/*  f136324:	00001812 */ 	mflo	$v1
/*  f136328:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f13632c:	0223082a */ 	slt	$at,$s1,$v1
/*  f136330:	5420fff2 */ 	bnezl	$at,.L0f1362fc
/*  f136334:	8c890000 */ 	lw	$t1,0x0($a0)
/*  f136338:	00008825 */ 	or	$s1,$zero,$zero
/*  f13633c:	8c8c0000 */ 	lw	$t4,0x0($a0)
.L0f136340:
/*  f136340:	00035880 */ 	sll	$t3,$v1,0x2
/*  f136344:	3c01800a */ 	lui	$at,%hi(g_StarData3)
/*  f136348:	016c7021 */ 	addu	$t6,$t3,$t4
/*  f13634c:	0fc4d71c */ 	jal	stars0f135c70
/*  f136350:	ac2e4154 */ 	sw	$t6,%lo(g_StarData3)($at)
/*  f136354:	3c0d800a */ 	lui	$t5,%hi(g_StarCount)
/*  f136358:	8dad4150 */ 	lw	$t5,%lo(g_StarCount)($t5)
/*  f13635c:	3c013f80 */ 	lui	$at,0x3f80
/*  f136360:	c7b800bc */ 	lwc1	$f24,0xbc($sp)
/*  f136364:	19a0013a */ 	blez	$t5,.L0f136850
/*  f136368:	c7b600c0 */ 	lwc1	$f22,0xc0($sp)
/*  f13636c:	4481f000 */ 	mtc1	$at,$f30
/*  f136370:	3c012f80 */ 	lui	$at,0x2f80
/*  f136374:	4481e000 */ 	mtc1	$at,$f28
/*  f136378:	3c01bf80 */ 	lui	$at,0xbf80
/*  f13637c:	4481d000 */ 	mtc1	$at,$f26
/*  f136380:	4480a000 */ 	mtc1	$zero,$f20
/*  f136384:	8fb000b0 */ 	lw	$s0,0xb0($sp)
.L0f136388:
/*  f136388:	0c004b70 */ 	jal	random
/*  f13638c:	00000000 */ 	nop
/*  f136390:	44822000 */ 	mtc1	$v0,$f4
/*  f136394:	3c014f80 */ 	lui	$at,0x4f80
/*  f136398:	04410004 */ 	bgez	$v0,.L0f1363ac
/*  f13639c:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f1363a0:	44814000 */ 	mtc1	$at,$f8
/*  f1363a4:	00000000 */ 	nop
/*  f1363a8:	46083180 */ 	add.s	$f6,$f6,$f8
.L0f1363ac:
/*  f1363ac:	461c3002 */ 	mul.s	$f0,$f6,$f28
/*  f1363b0:	3c0f8008 */ 	lui	$t7,%hi(g_StarsBelowHorizon)
/*  f1363b4:	8deff124 */ 	lw	$t7,%lo(g_StarsBelowHorizon)($t7)
/*  f1363b8:	46000280 */ 	add.s	$f10,$f0,$f0
/*  f1363bc:	461e5381 */ 	sub.s	$f14,$f10,$f30
/*  f1363c0:	11e0000f */ 	beqz	$t7,.L0f136400
/*  f1363c4:	e7ae00d4 */ 	swc1	$f14,0xd4($sp)
/*  f1363c8:	0c004b70 */ 	jal	random
/*  f1363cc:	00000000 */ 	nop
/*  f1363d0:	44822000 */ 	mtc1	$v0,$f4
/*  f1363d4:	3c014f80 */ 	lui	$at,0x4f80
/*  f1363d8:	04410004 */ 	bgez	$v0,.L0f1363ec
/*  f1363dc:	46802220 */ 	cvt.s.w	$f8,$f4
/*  f1363e0:	44813000 */ 	mtc1	$at,$f6
/*  f1363e4:	00000000 */ 	nop
/*  f1363e8:	46064200 */ 	add.s	$f8,$f8,$f6
.L0f1363ec:
/*  f1363ec:	461c4002 */ 	mul.s	$f0,$f8,$f28
/*  f1363f0:	46000280 */ 	add.s	$f10,$f0,$f0
/*  f1363f4:	461e5401 */ 	sub.s	$f16,$f10,$f30
/*  f1363f8:	1000000c */ 	b	.L0f13642c
/*  f1363fc:	e7b000d8 */ 	swc1	$f16,0xd8($sp)
.L0f136400:
/*  f136400:	0c004b70 */ 	jal	random
/*  f136404:	00000000 */ 	nop
/*  f136408:	44822000 */ 	mtc1	$v0,$f4
/*  f13640c:	3c014f80 */ 	lui	$at,0x4f80
/*  f136410:	04410004 */ 	bgez	$v0,.L0f136424
/*  f136414:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f136418:	44814000 */ 	mtc1	$at,$f8
/*  f13641c:	00000000 */ 	nop
/*  f136420:	46083180 */ 	add.s	$f6,$f6,$f8
.L0f136424:
/*  f136424:	461c3402 */ 	mul.s	$f16,$f6,$f28
/*  f136428:	e7b000d8 */ 	swc1	$f16,0xd8($sp)
.L0f13642c:
/*  f13642c:	0c004b70 */ 	jal	random
/*  f136430:	00000000 */ 	nop
/*  f136434:	44825000 */ 	mtc1	$v0,$f10
/*  f136438:	3c014f80 */ 	lui	$at,0x4f80
/*  f13643c:	04410004 */ 	bgez	$v0,.L0f136450
/*  f136440:	46805120 */ 	cvt.s.w	$f4,$f10
/*  f136444:	44814000 */ 	mtc1	$at,$f8
/*  f136448:	00000000 */ 	nop
/*  f13644c:	46082100 */ 	add.s	$f4,$f4,$f8
.L0f136450:
/*  f136450:	461c2002 */ 	mul.s	$f0,$f4,$f28
/*  f136454:	27a400d4 */ 	addiu	$a0,$sp,0xd4
/*  f136458:	27a500d8 */ 	addiu	$a1,$sp,0xd8
/*  f13645c:	27a600dc */ 	addiu	$a2,$sp,0xdc
/*  f136460:	46000180 */ 	add.s	$f6,$f0,$f0
/*  f136464:	461e3301 */ 	sub.s	$f12,$f6,$f30
/*  f136468:	0c0011e4 */ 	jal	guNormalize
/*  f13646c:	e7ac00dc */ 	swc1	$f12,0xdc($sp)
/*  f136470:	c7ae00d4 */ 	lwc1	$f14,0xd4($sp)
/*  f136474:	c7b000d8 */ 	lwc1	$f16,0xd8($sp)
/*  f136478:	c7ac00dc */ 	lwc1	$f12,0xdc($sp)
/*  f13647c:	4614703c */ 	c.lt.s	$f14,$f20
/*  f136480:	00000000 */ 	nop
/*  f136484:	45020004 */ 	bc1fl	.L0f136498
/*  f136488:	46007086 */ 	mov.s	$f2,$f14
/*  f13648c:	10000002 */ 	b	.L0f136498
/*  f136490:	46007087 */ 	neg.s	$f2,$f14
/*  f136494:	46007086 */ 	mov.s	$f2,$f14
.L0f136498:
/*  f136498:	4614803c */ 	c.lt.s	$f16,$f20
/*  f13649c:	00000000 */ 	nop
/*  f1364a0:	45020004 */ 	bc1fl	.L0f1364b4
/*  f1364a4:	46008006 */ 	mov.s	$f0,$f16
/*  f1364a8:	10000002 */ 	b	.L0f1364b4
/*  f1364ac:	46008007 */ 	neg.s	$f0,$f16
/*  f1364b0:	46008006 */ 	mov.s	$f0,$f16
.L0f1364b4:
/*  f1364b4:	4602003c */ 	c.lt.s	$f0,$f2
/*  f1364b8:	00000000 */ 	nop
/*  f1364bc:	45020027 */ 	bc1fl	.L0f13655c
/*  f1364c0:	4614803c */ 	c.lt.s	$f16,$f20
/*  f1364c4:	4614703c */ 	c.lt.s	$f14,$f20
/*  f1364c8:	c7ac00dc */ 	lwc1	$f12,0xdc($sp)
/*  f1364cc:	45020004 */ 	bc1fl	.L0f1364e0
/*  f1364d0:	46007086 */ 	mov.s	$f2,$f14
/*  f1364d4:	10000002 */ 	b	.L0f1364e0
/*  f1364d8:	46007087 */ 	neg.s	$f2,$f14
/*  f1364dc:	46007086 */ 	mov.s	$f2,$f14
.L0f1364e0:
/*  f1364e0:	4614603c */ 	c.lt.s	$f12,$f20
/*  f1364e4:	00000000 */ 	nop
/*  f1364e8:	45020004 */ 	bc1fl	.L0f1364fc
/*  f1364ec:	46006006 */ 	mov.s	$f0,$f12
/*  f1364f0:	10000002 */ 	b	.L0f1364fc
/*  f1364f4:	46006007 */ 	neg.s	$f0,$f12
/*  f1364f8:	46006006 */ 	mov.s	$f0,$f12
.L0f1364fc:
/*  f1364fc:	4602003c */ 	c.lt.s	$f0,$f2
/*  f136500:	00000000 */ 	nop
/*  f136504:	4502000b */ 	bc1fl	.L0f136534
/*  f136508:	4614603c */ 	c.lt.s	$f12,$f20
/*  f13650c:	4614703c */ 	c.lt.s	$f14,$f20
/*  f136510:	00000000 */ 	nop
/*  f136514:	45020004 */ 	bc1fl	.L0f136528
/*  f136518:	46007006 */ 	mov.s	$f0,$f14
/*  f13651c:	10000032 */ 	b	.L0f1365e8
/*  f136520:	46007007 */ 	neg.s	$f0,$f14
/*  f136524:	46007006 */ 	mov.s	$f0,$f14
.L0f136528:
/*  f136528:	10000030 */ 	b	.L0f1365ec
/*  f13652c:	46007483 */ 	div.s	$f18,$f14,$f0
/*  f136530:	4614603c */ 	c.lt.s	$f12,$f20
.L0f136534:
/*  f136534:	00000000 */ 	nop
/*  f136538:	45020004 */ 	bc1fl	.L0f13654c
/*  f13653c:	46006006 */ 	mov.s	$f0,$f12
/*  f136540:	10000002 */ 	b	.L0f13654c
/*  f136544:	46006007 */ 	neg.s	$f0,$f12
/*  f136548:	46006006 */ 	mov.s	$f0,$f12
.L0f13654c:
/*  f13654c:	46000086 */ 	mov.s	$f2,$f0
/*  f136550:	10000025 */ 	b	.L0f1365e8
/*  f136554:	46001006 */ 	mov.s	$f0,$f2
/*  f136558:	4614803c */ 	c.lt.s	$f16,$f20
.L0f13655c:
/*  f13655c:	00000000 */ 	nop
/*  f136560:	45020004 */ 	bc1fl	.L0f136574
/*  f136564:	46008086 */ 	mov.s	$f2,$f16
/*  f136568:	10000002 */ 	b	.L0f136574
/*  f13656c:	46008087 */ 	neg.s	$f2,$f16
/*  f136570:	46008086 */ 	mov.s	$f2,$f16
.L0f136574:
/*  f136574:	4614603c */ 	c.lt.s	$f12,$f20
/*  f136578:	00000000 */ 	nop
/*  f13657c:	45020004 */ 	bc1fl	.L0f136590
/*  f136580:	46006006 */ 	mov.s	$f0,$f12
/*  f136584:	10000002 */ 	b	.L0f136590
/*  f136588:	46006007 */ 	neg.s	$f0,$f12
/*  f13658c:	46006006 */ 	mov.s	$f0,$f12
.L0f136590:
/*  f136590:	4602003c */ 	c.lt.s	$f0,$f2
/*  f136594:	00000000 */ 	nop
/*  f136598:	4502000b */ 	bc1fl	.L0f1365c8
/*  f13659c:	4614603c */ 	c.lt.s	$f12,$f20
/*  f1365a0:	4614803c */ 	c.lt.s	$f16,$f20
/*  f1365a4:	00000000 */ 	nop
/*  f1365a8:	45020004 */ 	bc1fl	.L0f1365bc
/*  f1365ac:	46008006 */ 	mov.s	$f0,$f16
/*  f1365b0:	1000000c */ 	b	.L0f1365e4
/*  f1365b4:	46008087 */ 	neg.s	$f2,$f16
/*  f1365b8:	46008006 */ 	mov.s	$f0,$f16
.L0f1365bc:
/*  f1365bc:	10000009 */ 	b	.L0f1365e4
/*  f1365c0:	46000086 */ 	mov.s	$f2,$f0
/*  f1365c4:	4614603c */ 	c.lt.s	$f12,$f20
.L0f1365c8:
/*  f1365c8:	00000000 */ 	nop
/*  f1365cc:	45020004 */ 	bc1fl	.L0f1365e0
/*  f1365d0:	46006006 */ 	mov.s	$f0,$f12
/*  f1365d4:	10000002 */ 	b	.L0f1365e0
/*  f1365d8:	46006007 */ 	neg.s	$f0,$f12
/*  f1365dc:	46006006 */ 	mov.s	$f0,$f12
.L0f1365e0:
/*  f1365e0:	46000086 */ 	mov.s	$f2,$f0
.L0f1365e4:
/*  f1365e4:	46001006 */ 	mov.s	$f0,$f2
.L0f1365e8:
/*  f1365e8:	46007483 */ 	div.s	$f18,$f14,$f0
.L0f1365ec:
/*  f1365ec:	3c07800a */ 	lui	$a3,%hi(g_StarGridSize)
/*  f1365f0:	8ce74158 */ 	lw	$a3,%lo(g_StarGridSize)($a3)
/*  f1365f4:	3c013f80 */ 	lui	$at,0x3f80
/*  f1365f8:	44812000 */ 	mtc1	$at,$f4
/*  f1365fc:	00e70019 */ 	multu	$a3,$a3
/*  f136600:	e7ac00dc */ 	swc1	$f12,0xdc($sp)
/*  f136604:	e7ae00d4 */ 	swc1	$f14,0xd4($sp)
/*  f136608:	e7b000d8 */ 	swc1	$f16,0xd8($sp)
/*  f13660c:	3c013f80 */ 	lui	$at,0x3f80
/*  f136610:	00004012 */ 	mflo	$t0
/*  f136614:	46008283 */ 	div.s	$f10,$f16,$f0
/*  f136618:	46122032 */ 	c.eq.s	$f4,$f18
/*  f13661c:	46006203 */ 	div.s	$f8,$f12,$f0
/*  f136620:	e7aa00cc */ 	swc1	$f10,0xcc($sp)
/*  f136624:	45010006 */ 	bc1t	.L0f136640
/*  f136628:	e7a800d0 */ 	swc1	$f8,0xd0($sp)
/*  f13662c:	4612d032 */ 	c.eq.s	$f26,$f18
/*  f136630:	c7a000cc */ 	lwc1	$f0,0xcc($sp)
/*  f136634:	c7ae00d0 */ 	lwc1	$f14,0xd0($sp)
/*  f136638:	45020018 */ 	bc1fl	.L0f13669c
/*  f13663c:	3c013f80 */ 	lui	$at,0x3f80
.L0f136640:
/*  f136640:	4612d032 */ 	c.eq.s	$f26,$f18
/*  f136644:	44813000 */ 	mtc1	$at,$f6
/*  f136648:	c7a000cc */ 	lwc1	$f0,0xcc($sp)
/*  f13664c:	c7ae00d0 */ 	lwc1	$f14,0xd0($sp)
/*  f136650:	45000003 */ 	bc1f	.L0f136660
/*  f136654:	e7b200c8 */ 	swc1	$f18,0xc8($sp)
/*  f136658:	10000002 */ 	b	.L0f136664
/*  f13665c:	00008025 */ 	or	$s0,$zero,$zero
.L0f136660:
/*  f136660:	24100001 */ 	addiu	$s0,$zero,0x1
.L0f136664:
/*  f136664:	3c014000 */ 	lui	$at,0x4000
/*  f136668:	44814000 */ 	mtc1	$at,$f8
/*  f13666c:	46060280 */ 	add.s	$f10,$f0,$f6
/*  f136670:	3c013f80 */ 	lui	$at,0x3f80
/*  f136674:	44812000 */ 	mtc1	$at,$f4
/*  f136678:	3c014000 */ 	lui	$at,0x4000
/*  f13667c:	46085083 */ 	div.s	$f2,$f10,$f8
/*  f136680:	44815000 */ 	mtc1	$at,$f10
/*  f136684:	46000586 */ 	mov.s	$f22,$f0
/*  f136688:	46007606 */ 	mov.s	$f24,$f14
/*  f13668c:	46047180 */ 	add.s	$f6,$f14,$f4
/*  f136690:	1000004c */ 	b	.L0f1367c4
/*  f136694:	460a3303 */ 	div.s	$f12,$f6,$f10
/*  f136698:	3c013f80 */ 	lui	$at,0x3f80
.L0f13669c:
/*  f13669c:	44814000 */ 	mtc1	$at,$f8
/*  f1366a0:	3c013f80 */ 	lui	$at,0x3f80
/*  f1366a4:	46004032 */ 	c.eq.s	$f8,$f0
/*  f1366a8:	00000000 */ 	nop
/*  f1366ac:	45030006 */ 	bc1tl	.L0f1366c8
/*  f1366b0:	4600d032 */ 	c.eq.s	$f26,$f0
/*  f1366b4:	4600d032 */ 	c.eq.s	$f26,$f0
/*  f1366b8:	00000000 */ 	nop
/*  f1366bc:	45020016 */ 	bc1fl	.L0f136718
/*  f1366c0:	3c013f80 */ 	lui	$at,0x3f80
/*  f1366c4:	4600d032 */ 	c.eq.s	$f26,$f0
.L0f1366c8:
/*  f1366c8:	44812000 */ 	mtc1	$at,$f4
/*  f1366cc:	3c014000 */ 	lui	$at,0x4000
/*  f1366d0:	44815000 */ 	mtc1	$at,$f10
/*  f1366d4:	45000003 */ 	bc1f	.L0f1366e4
/*  f1366d8:	46047180 */ 	add.s	$f6,$f14,$f4
/*  f1366dc:	10000002 */ 	b	.L0f1366e8
/*  f1366e0:	24100002 */ 	addiu	$s0,$zero,0x2
.L0f1366e4:
/*  f1366e4:	24100003 */ 	addiu	$s0,$zero,0x3
.L0f1366e8:
/*  f1366e8:	3c013f80 */ 	lui	$at,0x3f80
/*  f1366ec:	44814000 */ 	mtc1	$at,$f8
/*  f1366f0:	3c014000 */ 	lui	$at,0x4000
/*  f1366f4:	460a3083 */ 	div.s	$f2,$f6,$f10
/*  f1366f8:	44813000 */ 	mtc1	$at,$f6
/*  f1366fc:	46007586 */ 	mov.s	$f22,$f14
/*  f136700:	46009606 */ 	mov.s	$f24,$f18
/*  f136704:	46089100 */ 	add.s	$f4,$f18,$f8
/*  f136708:	e7b200c8 */ 	swc1	$f18,0xc8($sp)
/*  f13670c:	1000002d */ 	b	.L0f1367c4
/*  f136710:	46062303 */ 	div.s	$f12,$f4,$f6
/*  f136714:	3c013f80 */ 	lui	$at,0x3f80
.L0f136718:
/*  f136718:	44815000 */ 	mtc1	$at,$f10
/*  f13671c:	3c013f80 */ 	lui	$at,0x3f80
/*  f136720:	460e5032 */ 	c.eq.s	$f10,$f14
/*  f136724:	00000000 */ 	nop
/*  f136728:	45030006 */ 	bc1tl	.L0f136744
/*  f13672c:	460ed032 */ 	c.eq.s	$f26,$f14
/*  f136730:	460ed032 */ 	c.eq.s	$f26,$f14
/*  f136734:	00000000 */ 	nop
/*  f136738:	45020016 */ 	bc1fl	.L0f136794
/*  f13673c:	3c013f80 */ 	lui	$at,0x3f80
/*  f136740:	460ed032 */ 	c.eq.s	$f26,$f14
.L0f136744:
/*  f136744:	44814000 */ 	mtc1	$at,$f8
/*  f136748:	3c014000 */ 	lui	$at,0x4000
/*  f13674c:	44813000 */ 	mtc1	$at,$f6
/*  f136750:	45000003 */ 	bc1f	.L0f136760
/*  f136754:	46089100 */ 	add.s	$f4,$f18,$f8
/*  f136758:	10000002 */ 	b	.L0f136764
/*  f13675c:	24100004 */ 	addiu	$s0,$zero,0x4
.L0f136760:
/*  f136760:	24100005 */ 	addiu	$s0,$zero,0x5
.L0f136764:
/*  f136764:	3c013f80 */ 	lui	$at,0x3f80
/*  f136768:	44815000 */ 	mtc1	$at,$f10
/*  f13676c:	3c014000 */ 	lui	$at,0x4000
/*  f136770:	46062083 */ 	div.s	$f2,$f4,$f6
/*  f136774:	44812000 */ 	mtc1	$at,$f4
/*  f136778:	46009586 */ 	mov.s	$f22,$f18
/*  f13677c:	46000606 */ 	mov.s	$f24,$f0
/*  f136780:	460a0200 */ 	add.s	$f8,$f0,$f10
/*  f136784:	e7b200c8 */ 	swc1	$f18,0xc8($sp)
/*  f136788:	1000000e */ 	b	.L0f1367c4
/*  f13678c:	46044303 */ 	div.s	$f12,$f8,$f4
/*  f136790:	3c013f80 */ 	lui	$at,0x3f80
.L0f136794:
/*  f136794:	44813000 */ 	mtc1	$at,$f6
/*  f136798:	3c014000 */ 	lui	$at,0x4000
/*  f13679c:	44814000 */ 	mtc1	$at,$f8
/*  f1367a0:	4606b280 */ 	add.s	$f10,$f22,$f6
/*  f1367a4:	3c013f80 */ 	lui	$at,0x3f80
/*  f1367a8:	44812000 */ 	mtc1	$at,$f4
/*  f1367ac:	3c014000 */ 	lui	$at,0x4000
/*  f1367b0:	46085083 */ 	div.s	$f2,$f10,$f8
/*  f1367b4:	44815000 */ 	mtc1	$at,$f10
/*  f1367b8:	e7b200c8 */ 	swc1	$f18,0xc8($sp)
/*  f1367bc:	4604c180 */ 	add.s	$f6,$f24,$f4
/*  f1367c0:	460a3303 */ 	div.s	$f12,$f6,$f10
.L0f1367c4:
/*  f1367c4:	44874000 */ 	mtc1	$a3,$f8
/*  f1367c8:	00000000 */ 	nop
/*  f1367cc:	46804020 */ 	cvt.s.w	$f0,$f8
/*  f1367d0:	46001102 */ 	mul.s	$f4,$f2,$f0
/*  f1367d4:	00000000 */ 	nop
/*  f1367d8:	46006282 */ 	mul.s	$f10,$f12,$f0
/*  f1367dc:	4600218d */ 	trunc.w.s	$f6,$f4
/*  f1367e0:	4600520d */ 	trunc.w.s	$f8,$f10
/*  f1367e4:	44023000 */ 	mfc1	$v0,$f6
/*  f1367e8:	44034000 */ 	mfc1	$v1,$f8
/*  f1367ec:	14470002 */ 	bne	$v0,$a3,.L0f1367f8
/*  f1367f0:	00000000 */ 	nop
/*  f1367f4:	2442ffff */ 	addiu	$v0,$v0,-1
.L0f1367f8:
/*  f1367f8:	14670002 */ 	bne	$v1,$a3,.L0f136804
/*  f1367fc:	00000000 */ 	nop
/*  f136800:	2463ffff */ 	addiu	$v1,$v1,-1
.L0f136804:
/*  f136804:	00e30019 */ 	multu	$a3,$v1
/*  f136808:	27a500d4 */ 	addiu	$a1,$sp,0xd4
/*  f13680c:	0000c012 */ 	mflo	$t8
/*  f136810:	03023021 */ 	addu	$a2,$t8,$v0
/*  f136814:	00000000 */ 	nop
/*  f136818:	02080019 */ 	multu	$s0,$t0
/*  f13681c:	00005012 */ 	mflo	$t2
/*  f136820:	01462021 */ 	addu	$a0,$t2,$a2
/*  f136824:	0fc4d7c2 */ 	jal	starInsert
/*  f136828:	00000000 */ 	nop
/*  f13682c:	3c0b800a */ 	lui	$t3,%hi(g_StarCount)
/*  f136830:	8d6b4150 */ 	lw	$t3,%lo(g_StarCount)($t3)
/*  f136834:	26310001 */ 	addiu	$s1,$s1,0x1
/*  f136838:	022b082a */ 	slt	$at,$s1,$t3
/*  f13683c:	1420fed2 */ 	bnez	$at,.L0f136388
/*  f136840:	00000000 */ 	nop
/*  f136844:	e7b800bc */ 	swc1	$f24,0xbc($sp)
/*  f136848:	e7b600c0 */ 	swc1	$f22,0xc0($sp)
/*  f13684c:	afb000b0 */ 	sw	$s0,0xb0($sp)
.L0f136850:
/*  f136850:	8fbf004c */ 	lw	$ra,0x4c($sp)
/*  f136854:	d7b40010 */ 	ldc1	$f20,0x10($sp)
/*  f136858:	d7b60018 */ 	ldc1	$f22,0x18($sp)
/*  f13685c:	d7b80020 */ 	ldc1	$f24,0x20($sp)
/*  f136860:	d7ba0028 */ 	ldc1	$f26,0x28($sp)
/*  f136864:	d7bc0030 */ 	ldc1	$f28,0x30($sp)
/*  f136868:	d7be0038 */ 	ldc1	$f30,0x38($sp)
/*  f13686c:	8fb00044 */ 	lw	$s0,0x44($sp)
/*  f136870:	8fb10048 */ 	lw	$s1,0x48($sp)
/*  f136874:	03e00008 */ 	jr	$ra
/*  f136878:	27bd00e8 */ 	addiu	$sp,$sp,0xe8
);

#define ABS2(value) ((value) < 0 ? -(value) : (value))

//void starsReset(void)
//{
//	struct coord spd4;
//	struct coord spc8;
//	f32 spbc[2];
//	s32 spb0;
//	f32 f12;
//	f32 f0;
//	f32 f2;
//	s32 v0;
//	s32 v1;
//	s32 i;
//	s32 tmp;
//
//	g_StarPositions = NULL;
//
//	if (PLAYERCOUNT() < 2) {
//		g_StarsBelowHorizon = false;
//		g_StarGridSize = 3;
//
//		if (g_Vars.stagenum == STAGE_TEST_OLD) {
//			g_StarsBelowHorizon = true;
//			g_StarCount = 1600;
//		} else if (g_Vars.stagenum == STAGE_DEFECTION || g_Vars.stagenum == STAGE_EXTRACTION) {
//			g_StarCount = 200;
//			g_StarGridSize = 2;
//		} else if (g_Vars.stagenum == STAGE_ATTACKSHIP) {
//			g_StarsBelowHorizon = true;
//			g_StarCount = 1200;
//		} else {
//			g_StarCount = 200;
//			g_StarGridSize = 2;
//		}
//
//		tmp = g_StarGridSize + 1;
//		g_StarPositions = mempAlloc(ALIGN64(g_StarCount * 3 + tmp * 72 * tmp + g_StarGridSize * 6 * g_StarGridSize * 4 + 4), MEMPOOL_STAGE);
//
//		if (g_StarPositions != NULL) {
//			s32 tmp;
//			g_StarPosIndexes = (s32 *)(g_StarPositions + g_StarCount * 3);
//
//			for (i = 0; i < (g_StarGridSize * 6 * g_StarGridSize + 1); i++) {
//				g_StarPosIndexes[i] = 0;
//			}
//
//			g_StarData3 = (f32 *)((u32)g_StarPosIndexes + (g_StarGridSize * 6 * g_StarGridSize + 1) * sizeof(f32));
//
//			stars0f135c70();
//
//			for (i = 0; i < g_StarCount; i++) {
//				spd4.f[0] = 2.0f * RANDOMFRAC() - 1.0f;
//
//				if (g_StarsBelowHorizon) {
//					spd4.f[1] = 2.0f * RANDOMFRAC() - 1.0f;
//				} else {
//					spd4.f[1] = RANDOMFRAC();
//				}
//
//				spd4.f[2] = 2.0f * RANDOMFRAC() - 1.0f;
//
//				guNormalize(&spd4.f[0], &spd4.f[1], &spd4.f[2]);
//
//				if (ABS2(spd4.f[1]) < ABS2(spd4.f[0])) {
//					f0 = ABS2(spd4.f[2]) < ABS2(spd4.f[0]) ? ABS2(spd4.f[0]) : ABS2(spd4.f[2]);
//				} else {
//					f0 = ABS2(spd4.f[2]) < ABS2(spd4.f[1]) ? ABS2(spd4.f[1]) : ABS2(spd4.f[2]);
//				}
//
//				// 5e0
//				tmp = g_StarGridSize * g_StarGridSize;
//
//				spc8.f[0] = spd4.f[0] / f0;
//				spc8.f[1] = spd4.f[1] / f0;
//				spc8.f[2] = spd4.f[2] / f0;
//
//				if (spc8.f[0] == 1.0f || spc8.f[0] == -1.0f) {
//					spb0 = spc8.f[0] == -1.0f ? 0 : 1;
//					spbc[0] = spc8.f[2];
//					spbc[1] = spc8.f[1];
//					f12 = (spbc[0] + 1.0f) / 2.0f;
//					f2 = (spbc[1] + 1.0f) / 2.0f;
//				} else if (spc8.f[1] == 1.0f || spc8.f[1] == -1.0f) {
//					spb0 = spc8.f[1] == -1.0f ? 2 : 3;
//					spbc[0] = spc8.f[0];
//					spbc[1] = spc8.f[2];
//					f12 = (spbc[0] + 1.0f) / 2.0f;
//					f2 = (spbc[1] + 1.0f) / 2.0f;
//				} else if (spc8.f[2] == 1.0f || spc8.f[2] == -1.0f) {
//					spb0 = spc8.f[2] == -1.0f ? 4 : 5;
//					spbc[0] = spc8.f[1];
//					spbc[1] = spc8.f[0];
//					f12 = (spbc[0] + 1.0f) / 2.0f;
//					f2 = (spbc[1] + 1.0f) / 2.0f;
//				} else{
//					f12 = (spbc[0] + 1.0f) / 2.0f;
//					f2 = (spbc[1] + 1.0f) / 2.0f;
//				}
//
//				v0 = f2 * g_StarGridSize;
//				v1 = f12 * g_StarGridSize;
//
//				if (v0 == g_StarGridSize) {
//					v0--;
//				}
//
//				if (v1 == g_StarGridSize) {
//					v1--;
//				}
//
//				starInsert(spb0 * tmp + (g_StarGridSize * v1) + v0, spd4.f);
//			}
//		}
//	}
//}

Gfx *starsRender(Gfx *gdl)
{
	bool isddtower = false;
	Mtxf mtx;
	f32 viewleft = viGetViewLeft();
	f32 viewright = viewleft + viGetViewWidth();
	f32 viewtop = viGetViewTop();
	f32 viewbottom = viewtop + viGetViewHeight();
	s32 i;
	f32 sp154;
	struct coord sp148;
	f32 screenmidx = g_Vars.currentplayer->c_screenleft + g_Vars.currentplayer->c_halfwidth;
	f32 screenmidy = g_Vars.currentplayer->c_screentop + g_Vars.currentplayer->c_halfheight;
	s32 j;
	s32 k;
	s32 l;
	u32 stack;
	s32 tmp;
	u32 colours[4];

	if (g_StarPositions == NULL) {
		return gdl;
	}

	if (g_Vars.stagenum == STAGE_DEFECTION || g_Vars.stagenum == STAGE_EXTRACTION) {
		isddtower = true;
	}

	colours[0] = colourBlend(0xffffff7f, 0x7777777f, func0f006b08(2) * 255);
	colours[1] = colourBlend(0x0000aa7f, 0x2222ff7f, func0f006b08(4) * 255);
	colours[2] = colourBlend(0x0000ff7f, 0x5555ff7f, func0f006b54(2) * 255);
	colours[3] = colourBlend(0xaaaaff7f, 0x7777ff7f, func0f006b54(4) * 255);

	if (isddtower) {
		for (i = 0; i < 3; i++) {
			// Nothing is done with the return value here, so this has no
			// effect. Maybe the original code incorrectly did a comparison
			// instead of an assign? eg. colours[i] == colourBlend(...)
			// Doing this would make the stars more transparent.
			colourBlend(colours[i], colours[i] & 0xff, 0x5f);
		}
	}

	sp154 = cosf(0.017453199252486f * (90.0f - viGetFovY() / viGetAspect() * 0.5f));

	mtx4LoadIdentity(&mtx);
	mtx00015be0(camGetMatrix1740(), &mtx);

	mtx.m[3][0] = 0.0f;
	mtx.m[3][1] = 0.0f;
	mtx.m[3][2] = 0.0f;

	mtx00015f88(262.9f, &mtx);

	mtx.m[0][1] *= g_Vars.currentplayer->c_recipscaley;
	mtx.m[1][1] *= g_Vars.currentplayer->c_recipscaley;
	mtx.m[2][1] *= g_Vars.currentplayer->c_recipscaley;

	mtx.m[0][0] *= g_Vars.currentplayer->c_recipscalex;
	mtx.m[1][0] *= g_Vars.currentplayer->c_recipscalex;
	mtx.m[2][0] *= g_Vars.currentplayer->c_recipscalex;

	sp148.f[0] = g_Vars.currentplayer->cam_look.f[0];
	sp148.f[1] = g_Vars.currentplayer->cam_look.f[1];
	sp148.f[2] = g_Vars.currentplayer->cam_look.f[2];

	gdl = textSetPrimColour(gdl, 0xffffffff);

	gDPSetRenderMode(gdl++, G_RM_CLD_SURF, G_RM_CLD_SURF2);

	for (i = 0; i < 6; i++) {
		if (g_StarsBelowHorizon || i != 2) {
			f32 f0;
			f32 f0_2;
			bool spd0[4][4];
			struct coord spc4;

			for (j = 0; j <= g_StarGridSize; j++) {
				for (k = 0; k <= g_StarGridSize; k++) {
					tmp = ((g_StarGridSize + 1) * i * (g_StarGridSize + 1) + k + j * (g_StarGridSize + 1)) * 3;
					f0 = sp148.f[0] * g_StarData3[tmp] + sp148.f[1] * g_StarData3[tmp + 1] + sp148.f[2] * g_StarData3[tmp + 2];

					if (f0 <= sp154) {
						spd0[k][j] = true;
					} else {
						spd0[k][j] = false;
					}
				}
			}

			for (j = 0; j < g_StarGridSize; j++) {
				for (k = 0; k < g_StarGridSize; k++) {
					if (spd0[k][j] == 0 || spd0[k + 1][j] == 0 || spd0[k][j + 1] == 0 || spd0[k + 1][j + 1] == 0) {
						s32 tmp = g_StarGridSize * g_StarGridSize * i + k + j * g_StarGridSize;
						s32 colourindex = 0;
						f32 screenpos[2];
						s32 drawpos[2];
						s32 nextgroupstart = g_StarPosIndexes[tmp];
						s32 groupsize = (g_StarPosIndexes[tmp + 1] - g_StarPosIndexes[tmp]) / 4 + 1;
						s8 *pos = &g_StarPositions[g_StarPosIndexes[tmp] * 3];

						for (l = g_StarPosIndexes[tmp]; l < g_StarPosIndexes[tmp + 1]; l++) {
							if (nextgroupstart == l) {
								gDPSetPrimColorViaWord(gdl++, 0, 0, colours[colourindex]);

								colourindex++;
								nextgroupstart += groupsize;
							}

							spc4.f[0] = pos[0];
							spc4.f[1] = pos[1];
							spc4.f[2] = pos[2];
							pos += 3;

							f0_2 = 1.0f / (mtx.m[0][2] * spc4.f[0] + mtx.m[1][2] * spc4.f[1] + mtx.m[2][2] * spc4.f[2]);
							screenpos[1] = screenmidy + (mtx.m[0][1] * spc4.f[0] + mtx.m[1][1] * spc4.f[1] + mtx.m[2][1] * spc4.f[2]) * f0_2;

							if (screenpos[1] > viewtop && screenpos[1] < viewbottom) {
								screenpos[0] = screenmidx - (mtx.m[0][0] * spc4.f[0] + mtx.m[1][0] * spc4.f[1] + mtx.m[2][0] * spc4.f[2]) * f0_2;

								if (screenpos[0] > viewleft && screenpos[0] < viewright) {
									drawpos[0] = screenpos[0];
									drawpos[1] = screenpos[1];

									gDPFillRectangle(gdl++, drawpos[0], drawpos[1], drawpos[0] + 1, drawpos[1] + 1);
								}
							}
						}
					}
				}
			}
		}
	}

	gdl = text0f153838(gdl);

	return gdl;
}
