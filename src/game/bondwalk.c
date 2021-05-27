#include <ultra64.h>
#include "constants.h"
#include "game/bondmove.h"
#include "game/bondwalk.h"
#include "game/cheats.h"
#include "game/chr/chraction.h"
#include "game/debug.h"
#include "game/game_006900.h"
#include "game/chr/chr.h"
#include "game/prop.h"
#include "game/game_092610.h"
#include "game/game_095320.h"
#include "game/game_097ba0.h"
#include "game/game_0b69d0.h"
#include "game/inventory/inventory.h"
#include "game/bondhead.h"
#include "game/game_127910.h"
#include "game/propobj.h"
#include "bss.h"
#include "lib/snd.h"
#include "lib/rng.h"
#include "lib/lib_16110.h"
#include "lib/lib_233c0.h"
#include "lib/lib_24e40.h"
#include "data.h"
#include "types.h"

#if VERSION >= VERSION_NTSC_1_0
void bwalkInit(void)
{
	u32 prevmode = g_Vars.currentplayer->bondmovemode;
	s32 i;

	g_Vars.currentplayer->bondmovemode = MOVEMODE_WALK;
	g_Vars.currentplayer->bondonground = 0;
	g_Vars.currentplayer->tank = NULL;
	g_Vars.currentplayer->unk1af0 = NULL;
	g_Vars.currentplayer->bondonturret = false;

	g_Vars.currentplayer->swaypos = 0;
	g_Vars.currentplayer->swayoffset = 0;
	g_Vars.currentplayer->swaytarget = 0;
	g_Vars.currentplayer->swayoffset0 = 0;
	g_Vars.currentplayer->swayoffset2 = 0;

	g_Vars.currentplayer->bdeltapos.x = 0;
	g_Vars.currentplayer->bdeltapos.y = -0.0001f;
	g_Vars.currentplayer->bdeltapos.z = 0;

	g_Vars.currentplayer->isfalling = false;
	g_Vars.currentplayer->fallstart = 0;

	g_Vars.currentplayer->gunextraaimx = 0;
	g_Vars.currentplayer->gunextraaimy = 0;

	g_Vars.currentplayer->bondforcespeed.x = 0;
	g_Vars.currentplayer->bondforcespeed.y = 0;
	g_Vars.currentplayer->bondforcespeed.z = 0;

	if (prevmode != MOVEMODE_WALK && prevmode != MOVEMODE_CUTSCENE) {
		g_Vars.currentplayer->sumcrouch = 0;
		g_Vars.currentplayer->crouchheight = 0;
		g_Vars.currentplayer->crouchtime240 = 0;
		g_Vars.currentplayer->crouchfall = 0;
		g_Vars.currentplayer->crouchpos = CROUCHPOS_STAND;
		g_Vars.currentplayer->autocrouchpos = CROUCHPOS_STAND;
		g_Vars.currentplayer->crouchspeed = 0;
		g_Vars.currentplayer->crouchoffset = 0;
		g_Vars.currentplayer->guncloseroffset = 0;
	}

	bwalkUpdateCrouchOffsetReal();

	if (prevmode != MOVEMODE_GRAB && prevmode != MOVEMODE_WALK) {
		for (i = 0; i != 3; i++) {
			g_Vars.currentplayer->bondshotspeed[i] = 0;
		}

		g_Vars.currentplayer->speedsideways = 0;
		g_Vars.currentplayer->speedstrafe = 0;
		g_Vars.currentplayer->speedgo = 0;
		g_Vars.currentplayer->speedboost = 1;
		g_Vars.currentplayer->speedmaxtime60 = 0;
		g_Vars.currentplayer->speedforwards = 0;
		g_Vars.currentplayer->speedtheta = 0;
		g_Vars.currentplayer->speedthetacontrol = 0;
	}

	if (g_Vars.currentplayer->walkinitmove) {
		struct coord delta;
		func00016b58(&g_Vars.currentplayer->walkinitmtx,
				0, 0, 0,
				-g_Vars.currentplayer->bond2.unk1c.x, -g_Vars.currentplayer->bond2.unk1c.y, -g_Vars.currentplayer->bond2.unk1c.z,
				g_Vars.currentplayer->bond2.unk28.x, g_Vars.currentplayer->bond2.unk28.y, g_Vars.currentplayer->bond2.unk28.z);
		g_Vars.currentplayer->walkinitt = 0;
		g_Vars.currentplayer->walkinitt2 = 0;
		g_Vars.currentplayer->walkinitstart.x = g_Vars.currentplayer->prop->pos.x;
		g_Vars.currentplayer->walkinitstart.y = g_Vars.currentplayer->prop->pos.y;
		g_Vars.currentplayer->walkinitstart.z = g_Vars.currentplayer->prop->pos.z;

		delta.x = g_Vars.currentplayer->walkinitpos.x - g_Vars.currentplayer->prop->pos.x;
		delta.y = 0;
		delta.z = g_Vars.currentplayer->walkinitpos.z - g_Vars.currentplayer->prop->pos.z;

		propSetCollisionsEnabled(g_Vars.currentplayer->hoverbike, false);
		bwalkCalculateNewPositionWithPush(&delta, 0, true, 0, CDTYPE_ALL);
		propSetCollisionsEnabled(g_Vars.currentplayer->hoverbike, true);
	} else if (prevmode != MOVEMODE_GRAB && prevmode != MOVEMODE_WALK) {
		g_Vars.currentplayer->moveinitspeed.x = 0;
		g_Vars.currentplayer->moveinitspeed.y = 0;
		g_Vars.currentplayer->moveinitspeed.z = 0;
	}
}
#else
GLOBAL_ASM(
glabel bwalkInit
.late_rodata
glabel var7f1a7ad0
.word 0xb8d1b717
.text
/*  f0c13a0:	27bdffa8 */ 	addiu	$sp,$sp,-88
/*  f0c13a4:	afb00038 */ 	sw	$s0,0x38($sp)
/*  f0c13a8:	3c10800a */ 	lui	$s0,0x800a
/*  f0c13ac:	2610e6c0 */ 	addiu	$s0,$s0,-6464
/*  f0c13b0:	8e020284 */ 	lw	$v0,0x284($s0)
/*  f0c13b4:	afbf003c */ 	sw	$ra,0x3c($sp)
/*  f0c13b8:	f7b40030 */ 	sdc1	$f20,0x30($sp)
/*  f0c13bc:	8c4401b0 */ 	lw	$a0,0x1b0($v0)
/*  f0c13c0:	ac4001b0 */ 	sw	$zero,0x1b0($v0)
/*  f0c13c4:	4480a000 */ 	mtc1	$zero,$f20
/*  f0c13c8:	8e0e0284 */ 	lw	$t6,0x284($s0)
/*  f0c13cc:	3c017f1a */ 	lui	$at,0x7f1a
/*  f0c13d0:	e5d41ae8 */ 	swc1	$f20,0x1ae8($t6)
/*  f0c13d4:	8e0f0284 */ 	lw	$t7,0x284($s0)
/*  f0c13d8:	ade01aec */ 	sw	$zero,0x1aec($t7)
/*  f0c13dc:	8e180284 */ 	lw	$t8,0x284($s0)
/*  f0c13e0:	af001af0 */ 	sw	$zero,0x1af0($t8)
/*  f0c13e4:	8e190284 */ 	lw	$t9,0x284($s0)
/*  f0c13e8:	af201af4 */ 	sw	$zero,0x1af4($t9)
/*  f0c13ec:	8e080284 */ 	lw	$t0,0x284($s0)
/*  f0c13f0:	ad000098 */ 	sw	$zero,0x98($t0)
/*  f0c13f4:	8e090284 */ 	lw	$t1,0x284($s0)
/*  f0c13f8:	e534009c */ 	swc1	$f20,0x9c($t1)
/*  f0c13fc:	8e0a0284 */ 	lw	$t2,0x284($s0)
/*  f0c1400:	e55400a0 */ 	swc1	$f20,0xa0($t2)
/*  f0c1404:	8e0b0284 */ 	lw	$t3,0x284($s0)
/*  f0c1408:	e57400a4 */ 	swc1	$f20,0xa4($t3)
/*  f0c140c:	8e0c0284 */ 	lw	$t4,0x284($s0)
/*  f0c1410:	e59400a8 */ 	swc1	$f20,0xa8($t4)
/*  f0c1414:	8e0d0284 */ 	lw	$t5,0x284($s0)
/*  f0c1418:	e5b4007c */ 	swc1	$f20,0x7c($t5)
/*  f0c141c:	8e0e0284 */ 	lw	$t6,0x284($s0)
/*  f0c1420:	c4247ad0 */ 	lwc1	$f4,0x7ad0($at)
/*  f0c1424:	24010005 */ 	addiu	$at,$zero,0x5
/*  f0c1428:	e5c40080 */ 	swc1	$f4,0x80($t6)
/*  f0c142c:	8e0f0284 */ 	lw	$t7,0x284($s0)
/*  f0c1430:	e5f40084 */ 	swc1	$f20,0x84($t7)
/*  f0c1434:	8e180284 */ 	lw	$t8,0x284($s0)
/*  f0c1438:	af000030 */ 	sw	$zero,0x30($t8)
/*  f0c143c:	8e190284 */ 	lw	$t9,0x284($s0)
/*  f0c1440:	af200034 */ 	sw	$zero,0x34($t9)
/*  f0c1444:	8e080284 */ 	lw	$t0,0x284($s0)
/*  f0c1448:	e51401b4 */ 	swc1	$f20,0x1b4($t0)
/*  f0c144c:	8e090284 */ 	lw	$t1,0x284($s0)
/*  f0c1450:	e53401b8 */ 	swc1	$f20,0x1b8($t1)
/*  f0c1454:	8e0a0284 */ 	lw	$t2,0x284($s0)
/*  f0c1458:	e5541b6c */ 	swc1	$f20,0x1b6c($t2)
/*  f0c145c:	8e0b0284 */ 	lw	$t3,0x284($s0)
/*  f0c1460:	e5741b70 */ 	swc1	$f20,0x1b70($t3)
/*  f0c1464:	8e0c0284 */ 	lw	$t4,0x284($s0)
/*  f0c1468:	10800019 */ 	beqz	$a0,.NB0f0c14d0
/*  f0c146c:	e5941b74 */ 	swc1	$f20,0x1b74($t4)
/*  f0c1470:	50810018 */ 	beql	$a0,$at,.NB0f0c14d4
/*  f0c1474:	24050004 */ 	addiu	$a1,$zero,0x4
/*  f0c1478:	8e0d0284 */ 	lw	$t5,0x284($s0)
/*  f0c147c:	24020002 */ 	addiu	$v0,$zero,0x2
/*  f0c1480:	e5b40088 */ 	swc1	$f20,0x88($t5)
/*  f0c1484:	8e0e0284 */ 	lw	$t6,0x284($s0)
/*  f0c1488:	e5d4008c */ 	swc1	$f20,0x8c($t6)
/*  f0c148c:	8e0f0284 */ 	lw	$t7,0x284($s0)
/*  f0c1490:	ade00090 */ 	sw	$zero,0x90($t7)
/*  f0c1494:	8e180284 */ 	lw	$t8,0x284($s0)
/*  f0c1498:	e7140094 */ 	swc1	$f20,0x94($t8)
/*  f0c149c:	8e190284 */ 	lw	$t9,0x284($s0)
/*  f0c14a0:	af2200ac */ 	sw	$v0,0xac($t9)
/*  f0c14a4:	8e080284 */ 	lw	$t0,0x284($s0)
/*  f0c14a8:	ad0200b0 */ 	sw	$v0,0xb0($t0)
/*  f0c14ac:	8e090284 */ 	lw	$t1,0x284($s0)
/*  f0c14b0:	e53400b8 */ 	swc1	$f20,0xb8($t1)
/*  f0c14b4:	8e0a0284 */ 	lw	$t2,0x284($s0)
/*  f0c14b8:	e55400b4 */ 	swc1	$f20,0xb4($t2)
/*  f0c14bc:	0fc30e79 */ 	jal	bwalkUpdateCrouchOffsetReal
/*  f0c14c0:	afa40054 */ 	sw	$a0,0x54($sp)
/*  f0c14c4:	8e0b0284 */ 	lw	$t3,0x284($s0)
/*  f0c14c8:	8fa40054 */ 	lw	$a0,0x54($sp)
/*  f0c14cc:	e5741968 */ 	swc1	$f20,0x1968($t3)
.NB0f0c14d0:
/*  f0c14d0:	24050004 */ 	addiu	$a1,$zero,0x4
.NB0f0c14d4:
/*  f0c14d4:	5085001c */ 	beql	$a0,$a1,.NB0f0c1548
/*  f0c14d8:	8e020284 */ 	lw	$v0,0x284($s0)
/*  f0c14dc:	10800019 */ 	beqz	$a0,.NB0f0c1544
/*  f0c14e0:	00001025 */ 	or	$v0,$zero,$zero
/*  f0c14e4:	2403000c */ 	addiu	$v1,$zero,0xc
.NB0f0c14e8:
/*  f0c14e8:	8e0c0284 */ 	lw	$t4,0x284($s0)
/*  f0c14ec:	01826821 */ 	addu	$t5,$t4,$v0
/*  f0c14f0:	24420004 */ 	addiu	$v0,$v0,0x4
/*  f0c14f4:	1443fffc */ 	bne	$v0,$v1,.NB0f0c14e8
/*  f0c14f8:	e5b4017c */ 	swc1	$f20,0x17c($t5)
/*  f0c14fc:	8e0e0284 */ 	lw	$t6,0x284($s0)
/*  f0c1500:	3c013f80 */ 	lui	$at,0x3f80
/*  f0c1504:	44813000 */ 	mtc1	$at,$f6
/*  f0c1508:	e5d40168 */ 	swc1	$f20,0x168($t6)
/*  f0c150c:	8e0f0284 */ 	lw	$t7,0x284($s0)
/*  f0c1510:	e5f4016c */ 	swc1	$f20,0x16c($t7)
/*  f0c1514:	8e180284 */ 	lw	$t8,0x284($s0)
/*  f0c1518:	e71419a4 */ 	swc1	$f20,0x19a4($t8)
/*  f0c151c:	8e190284 */ 	lw	$t9,0x284($s0)
/*  f0c1520:	e7260174 */ 	swc1	$f6,0x174($t9)
/*  f0c1524:	8e080284 */ 	lw	$t0,0x284($s0)
/*  f0c1528:	ad000178 */ 	sw	$zero,0x178($t0)
/*  f0c152c:	8e090284 */ 	lw	$t1,0x284($s0)
/*  f0c1530:	e5340170 */ 	swc1	$f20,0x170($t1)
/*  f0c1534:	8e0a0284 */ 	lw	$t2,0x284($s0)
/*  f0c1538:	e5540148 */ 	swc1	$f20,0x148($t2)
/*  f0c153c:	8e0b0284 */ 	lw	$t3,0x284($s0)
/*  f0c1540:	e5741b9c */ 	swc1	$f20,0x1b9c($t3)
.NB0f0c1544:
/*  f0c1544:	8e020284 */ 	lw	$v0,0x284($s0)
.NB0f0c1548:
/*  f0c1548:	8c4c1af8 */ 	lw	$t4,0x1af8($v0)
/*  f0c154c:	11800041 */ 	beqz	$t4,.NB0f0c1654
/*  f0c1550:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c1554:	c4480388 */ 	lwc1	$f8,0x388($v0)
/*  f0c1558:	4405a000 */ 	mfc1	$a1,$f20
/*  f0c155c:	4406a000 */ 	mfc1	$a2,$f20
/*  f0c1560:	46004287 */ 	neg.s	$f10,$f8
/*  f0c1564:	4407a000 */ 	mfc1	$a3,$f20
/*  f0c1568:	e7aa0010 */ 	swc1	$f10,0x10($sp)
/*  f0c156c:	c450038c */ 	lwc1	$f16,0x38c($v0)
/*  f0c1570:	24441b08 */ 	addiu	$a0,$v0,0x1b08
/*  f0c1574:	46008487 */ 	neg.s	$f18,$f16
/*  f0c1578:	e7b20014 */ 	swc1	$f18,0x14($sp)
/*  f0c157c:	c4440390 */ 	lwc1	$f4,0x390($v0)
/*  f0c1580:	46002187 */ 	neg.s	$f6,$f4
/*  f0c1584:	e7a60018 */ 	swc1	$f6,0x18($sp)
/*  f0c1588:	c4480394 */ 	lwc1	$f8,0x394($v0)
/*  f0c158c:	e7a8001c */ 	swc1	$f8,0x1c($sp)
/*  f0c1590:	c44a0398 */ 	lwc1	$f10,0x398($v0)
/*  f0c1594:	e7aa0020 */ 	swc1	$f10,0x20($sp)
/*  f0c1598:	c450039c */ 	lwc1	$f16,0x39c($v0)
/*  f0c159c:	0c005eba */ 	jal	func00016b58
/*  f0c15a0:	e7b00024 */ 	swc1	$f16,0x24($sp)
/*  f0c15a4:	8e0d0284 */ 	lw	$t5,0x284($s0)
/*  f0c15a8:	00002825 */ 	or	$a1,$zero,$zero
/*  f0c15ac:	e5b41b48 */ 	swc1	$f20,0x1b48($t5)
/*  f0c15b0:	8e0e0284 */ 	lw	$t6,0x284($s0)
/*  f0c15b4:	e5d41b4c */ 	swc1	$f20,0x1b4c($t6)
/*  f0c15b8:	8e020284 */ 	lw	$v0,0x284($s0)
/*  f0c15bc:	8c4f00bc */ 	lw	$t7,0xbc($v0)
/*  f0c15c0:	c5f20008 */ 	lwc1	$f18,0x8($t7)
/*  f0c15c4:	e4521b50 */ 	swc1	$f18,0x1b50($v0)
/*  f0c15c8:	8e020284 */ 	lw	$v0,0x284($s0)
/*  f0c15cc:	8c5800bc */ 	lw	$t8,0xbc($v0)
/*  f0c15d0:	c704000c */ 	lwc1	$f4,0xc($t8)
/*  f0c15d4:	e4441b54 */ 	swc1	$f4,0x1b54($v0)
/*  f0c15d8:	8e020284 */ 	lw	$v0,0x284($s0)
/*  f0c15dc:	8c5900bc */ 	lw	$t9,0xbc($v0)
/*  f0c15e0:	c7260010 */ 	lwc1	$f6,0x10($t9)
/*  f0c15e4:	e4461b58 */ 	swc1	$f6,0x1b58($v0)
/*  f0c15e8:	8e020284 */ 	lw	$v0,0x284($s0)
/*  f0c15ec:	8c4800bc */ 	lw	$t0,0xbc($v0)
/*  f0c15f0:	c4481afc */ 	lwc1	$f8,0x1afc($v0)
/*  f0c15f4:	c50a0008 */ 	lwc1	$f10,0x8($t0)
/*  f0c15f8:	e7b40048 */ 	swc1	$f20,0x48($sp)
/*  f0c15fc:	460a4401 */ 	sub.s	$f16,$f8,$f10
/*  f0c1600:	e7b00044 */ 	swc1	$f16,0x44($sp)
/*  f0c1604:	8c4900bc */ 	lw	$t1,0xbc($v0)
/*  f0c1608:	c4521b04 */ 	lwc1	$f18,0x1b04($v0)
/*  f0c160c:	c5240010 */ 	lwc1	$f4,0x10($t1)
/*  f0c1610:	46049181 */ 	sub.s	$f6,$f18,$f4
/*  f0c1614:	e7a6004c */ 	swc1	$f6,0x4c($sp)
/*  f0c1618:	0fc18cfb */ 	jal	propSetCollisionsEnabled
/*  f0c161c:	8c441a6c */ 	lw	$a0,0x1a6c($v0)
/*  f0c1620:	4405a000 */ 	mfc1	$a1,$f20
/*  f0c1624:	4407a000 */ 	mfc1	$a3,$f20
/*  f0c1628:	240a003f */ 	addiu	$t2,$zero,0x3f
/*  f0c162c:	afaa0010 */ 	sw	$t2,0x10($sp)
/*  f0c1630:	27a40044 */ 	addiu	$a0,$sp,0x44
/*  f0c1634:	0fc30794 */ 	jal	bwalkCalculateNewPositionWithPush
/*  f0c1638:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f0c163c:	8e0b0284 */ 	lw	$t3,0x284($s0)
/*  f0c1640:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f0c1644:	0fc18cfb */ 	jal	propSetCollisionsEnabled
/*  f0c1648:	8d641a6c */ 	lw	$a0,0x1a6c($t3)
/*  f0c164c:	1000000b */ 	beqz	$zero,.NB0f0c167c
/*  f0c1650:	8fbf003c */ 	lw	$ra,0x3c($sp)
.NB0f0c1654:
/*  f0c1654:	50850009 */ 	beql	$a0,$a1,.NB0f0c167c
/*  f0c1658:	8fbf003c */ 	lw	$ra,0x3c($sp)
/*  f0c165c:	50800007 */ 	beqzl	$a0,.NB0f0c167c
/*  f0c1660:	8fbf003c */ 	lw	$ra,0x3c($sp)
/*  f0c1664:	e45401a4 */ 	swc1	$f20,0x1a4($v0)
/*  f0c1668:	8e0c0284 */ 	lw	$t4,0x284($s0)
/*  f0c166c:	e59401a8 */ 	swc1	$f20,0x1a8($t4)
/*  f0c1670:	8e0d0284 */ 	lw	$t5,0x284($s0)
/*  f0c1674:	e5b401ac */ 	swc1	$f20,0x1ac($t5)
/*  f0c1678:	8fbf003c */ 	lw	$ra,0x3c($sp)
.NB0f0c167c:
/*  f0c167c:	d7b40030 */ 	ldc1	$f20,0x30($sp)
/*  f0c1680:	8fb00038 */ 	lw	$s0,0x38($sp)
/*  f0c1684:	03e00008 */ 	jr	$ra
/*  f0c1688:	27bd0058 */ 	addiu	$sp,$sp,0x58
);
#endif

void bwalkSetSwayTarget(s32 value)
{
	g_Vars.currentplayer->swaytarget = value * 75.0f;
}

void bwalkAdjustCrouchPos(s32 value)
{
	g_Vars.currentplayer->crouchpos += value;

	if (g_Vars.currentplayer->crouchpos < CROUCHPOS_SQUAT) {
		g_Vars.currentplayer->crouchpos = CROUCHPOS_SQUAT;
	} else if (g_Vars.currentplayer->crouchpos > CROUCHPOS_STAND) {
		g_Vars.currentplayer->crouchpos = CROUCHPOS_STAND;
	}
}

void bwalk0f0c3b38(struct coord *reltarget, struct defaultobj *obj)
{
	struct coord posunk;
	struct coord vector;
	struct coord tween;
	struct coord globalthinga;
	struct coord globalthingb;
	struct coord abstarget;

	abstarget.x = reltarget->x + g_Vars.currentplayer->prop->pos.x;
	abstarget.y = g_Vars.currentplayer->prop->pos.y;
	abstarget.z = reltarget->z + g_Vars.currentplayer->prop->pos.z;

	func00024e4c(&globalthinga, &globalthingb, 223, "bondwalk.c");

	vector.x = globalthingb.z - globalthinga.z;
	vector.y = 0;
	vector.z = globalthinga.x - globalthingb.x;

	if (vector.f[0] != 0 || vector.f[2] != 0) {
		guNormalize(&vector.x, &vector.y, &vector.z);
	} else {
		vector.z = 1;
	}

	func0f02e3dc(&globalthinga, &globalthingb, &abstarget, &vector, &posunk);

	tween.x = (abstarget.x - g_Vars.currentplayer->prop->pos.x) / g_Vars.lvupdate240freal;
	tween.y = 0;
	tween.z = (abstarget.z - g_Vars.currentplayer->prop->pos.z) / g_Vars.lvupdate240freal;

	func0f082e84(obj, &posunk, &vector, &tween, false);
}

/**
 * Attempt to move the current player up vertically by the given amount.
 *
 * Collision checks are done for the new location, and if successful the
 * player's positional values are updated.
 *
 * The function is called with amount = 0 when attempting to stand up from a
 * crouch, after increasing the player's bbox to the standing size.
 */
s32 bwalkTryMoveUpwards(f32 amount)
{
	bool result;
	struct coord newpos;
	s16 rooms[8];
	u32 stack;
	u32 types;
	f32 ymax;
	f32 ymin;
	f32 width;

	if (g_Vars.currentplayer->floorflags & TILEFLAG_0100) {
		g_Vars.enableslopes = false;
	} else {
		g_Vars.enableslopes = true;
	}

	newpos.x = g_Vars.currentplayer->prop->pos.x;
	newpos.y = g_Vars.currentplayer->prop->pos.y + amount;
	newpos.z = g_Vars.currentplayer->prop->pos.z;

	types = g_Vars.bondcollisions ? CDTYPE_ALL : CDTYPE_BG;

	propPlayerGetBbox(g_Vars.currentplayer->prop, &width, &ymax, &ymin);
	func0f065e74(&g_Vars.currentplayer->prop->pos, g_Vars.currentplayer->prop->rooms, &newpos, rooms);
	bmove0f0cb79c(g_Vars.currentplayer, &newpos, rooms);
	propSetCollisionsEnabled(g_Vars.currentplayer->prop, false);

	ymin -= 0.1f;

	result = cdTestVolume(&newpos, width, rooms, types, 1,
			ymax - g_Vars.currentplayer->prop->pos.y,
			ymin - g_Vars.currentplayer->prop->pos.y);

	propSetCollisionsEnabled(g_Vars.currentplayer->prop, true);

	if (result == CDRESULT_NOCOLLISION) {
		g_Vars.currentplayer->prop->pos.y = newpos.y;
		func0f065c44(g_Vars.currentplayer->prop);
		roomsCopy(rooms, g_Vars.currentplayer->prop->rooms);
	}

	g_Vars.enableslopes = true;

	return result;
}

#if VERSION >= VERSION_NTSC_1_0
bool bwalkCalculateNewPosition(struct coord *vel, f32 rotateamount, bool apply, f32 extrawidth, s32 checktypes)
{
	s32 result = CDRESULT_NOCOLLISION;
	f32 halfwidth;
	struct coord dstpos;
	s16 dstrooms[8];
	bool copyrooms = false;
	s16 sp64[22];
	s32 types;
	f32 ymax;
	f32 ymin;
	f32 width;
	f32 xdiff;
	f32 zdiff;
	u32 stack;

	if (g_Vars.currentplayer->floorflags & TILEFLAG_0100) {
		g_Vars.enableslopes = false;
	} else {
		g_Vars.enableslopes = true;
	}

	dstpos.x = g_Vars.currentplayer->prop->pos.x;
	dstpos.y = g_Vars.currentplayer->prop->pos.y;
	dstpos.z = g_Vars.currentplayer->prop->pos.z;

	if (vel->x || vel->y || vel->z) {
		if (g_Vars.currentplayer->tank) {
			propSetCollisionsEnabled(g_Vars.currentplayer->tank, false);
		}

		propSetCollisionsEnabled(g_Vars.currentplayer->prop, false);

		dstpos.x += vel->x;
		dstpos.y += vel->y;
		dstpos.z += vel->z;

		types = g_Vars.bondcollisions ? checktypes : CDTYPE_BG;

		propPlayerGetBbox(g_Vars.currentplayer->prop, &width, &ymax, &ymin);
		width += extrawidth;

		func0f065dfc(&g_Vars.currentplayer->prop->pos, g_Vars.currentplayer->prop->rooms,
				&dstpos, dstrooms, sp64, 20);
		bmove0f0cb79c(g_Vars.currentplayer, &dstpos, dstrooms);

		copyrooms = true;

		// Check if the player is moving at least half their width along the
		// X or Z axis in a single frame. If less, only do a collision check for
		// the dst position. If more, do a halfway check too?
		xdiff = dstpos.x - g_Vars.currentplayer->prop->pos.x;
		zdiff = dstpos.z - g_Vars.currentplayer->prop->pos.z;
		halfwidth = width * 0.5f;

		if (xdiff > halfwidth || zdiff > halfwidth || xdiff < -halfwidth || zdiff < -halfwidth) {
			result = cdTestAToB3(&g_Vars.currentplayer->prop->pos,
					g_Vars.currentplayer->prop->rooms,
					&dstpos, dstrooms, width, types, 1,
					ymax - g_Vars.currentplayer->prop->pos.y,
					ymin - g_Vars.currentplayer->prop->pos.y);

			if (result == CDRESULT_NOCOLLISION) {
				result = cdTestAToB1(&g_Vars.currentplayer->prop->pos,
						&dstpos, width, dstrooms, types, 1,
						ymax - g_Vars.currentplayer->prop->pos.y,
						ymin - g_Vars.currentplayer->prop->pos.y);
			}
		} else {
			result = cdTestAToB1(&g_Vars.currentplayer->prop->pos,
					&dstpos, width, sp64, types, 1,
					ymax - g_Vars.currentplayer->prop->pos.y,
					ymin - g_Vars.currentplayer->prop->pos.y);
		}

		propSetCollisionsEnabled(g_Vars.currentplayer->prop, true);

		if (g_Vars.currentplayer->tank) {
			propSetCollisionsEnabled(g_Vars.currentplayer->tank, true);
		}
	}

	if (result == CDRESULT_NOCOLLISION && apply) {
		f32 angle = g_Vars.currentplayer->vv_theta + (rotateamount * 360) / M_BADTAU;

		while (angle < 0) {
			angle += 360;
		}

		while (angle >= 360) {
			angle -= 360;
		}

		g_Vars.currentplayer->vv_theta = angle;

		g_Vars.currentplayer->prop->pos.x = dstpos.x;
		g_Vars.currentplayer->prop->pos.y = dstpos.y;
		g_Vars.currentplayer->prop->pos.z = dstpos.z;

		if (copyrooms) {
			func0f065c44(g_Vars.currentplayer->prop);
			roomsCopy(dstrooms, g_Vars.currentplayer->prop->rooms);
		}
	}

	g_Vars.enableslopes = true;

	return result;
}
#else
GLOBAL_ASM(
glabel bwalkCalculateNewPosition
.late_rodata
glabel var7f1a7ad8nb
.word 0x40c907a9
.text
/*  f0c19d0:	27bdff48 */ 	addiu	$sp,$sp,-184
/*  f0c19d4:	afb00030 */ 	sw	$s0,0x30($sp)
/*  f0c19d8:	3c10800a */ 	lui	$s0,0x800a
/*  f0c19dc:	2610e6c0 */ 	addiu	$s0,$s0,-6464
/*  f0c19e0:	8e020284 */ 	lw	$v0,0x284($s0)
/*  f0c19e4:	afbf0034 */ 	sw	$ra,0x34($sp)
/*  f0c19e8:	afa400b8 */ 	sw	$a0,0xb8($sp)
/*  f0c19ec:	afa500bc */ 	sw	$a1,0xbc($sp)
/*  f0c19f0:	afa600c0 */ 	sw	$a2,0xc0($sp)
/*  f0c19f4:	afa700c4 */ 	sw	$a3,0xc4($sp)
/*  f0c19f8:	afa00090 */ 	sw	$zero,0x90($sp)
/*  f0c19fc:	944e161c */ 	lhu	$t6,0x161c($v0)
/*  f0c1a00:	00803825 */ 	or	$a3,$a0,$zero
/*  f0c1a04:	24030001 */ 	addiu	$v1,$zero,0x1
/*  f0c1a08:	31cf0100 */ 	andi	$t7,$t6,0x100
/*  f0c1a0c:	11e00003 */ 	beqz	$t7,.NB0f0c1a1c
/*  f0c1a10:	24180001 */ 	addiu	$t8,$zero,0x1
/*  f0c1a14:	10000002 */ 	beqz	$zero,.NB0f0c1a20
/*  f0c1a18:	ae00032c */ 	sw	$zero,0x32c($s0)
.NB0f0c1a1c:
/*  f0c1a1c:	ae18032c */ 	sw	$t8,0x32c($s0)
.NB0f0c1a20:
/*  f0c1a20:	8c5900bc */ 	lw	$t9,0xbc($v0)
/*  f0c1a24:	44808000 */ 	mtc1	$zero,$f16
/*  f0c1a28:	c7240008 */ 	lwc1	$f4,0x8($t9)
/*  f0c1a2c:	e7a400a4 */ 	swc1	$f4,0xa4($sp)
/*  f0c1a30:	8c4800bc */ 	lw	$t0,0xbc($v0)
/*  f0c1a34:	c506000c */ 	lwc1	$f6,0xc($t0)
/*  f0c1a38:	e7a600a8 */ 	swc1	$f6,0xa8($sp)
/*  f0c1a3c:	8c4900bc */ 	lw	$t1,0xbc($v0)
/*  f0c1a40:	c5280010 */ 	lwc1	$f8,0x10($t1)
/*  f0c1a44:	e7a800ac */ 	swc1	$f8,0xac($sp)
/*  f0c1a48:	c4ea0000 */ 	lwc1	$f10,0x0($a3)
/*  f0c1a4c:	460a8032 */ 	c.eq.s	$f16,$f10
/*  f0c1a50:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c1a54:	4502000c */ 	bc1fl	.NB0f0c1a88
/*  f0c1a58:	8c441aec */ 	lw	$a0,0x1aec($v0)
/*  f0c1a5c:	c4f20004 */ 	lwc1	$f18,0x4($a3)
/*  f0c1a60:	46128032 */ 	c.eq.s	$f16,$f18
/*  f0c1a64:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c1a68:	45020007 */ 	bc1fl	.NB0f0c1a88
/*  f0c1a6c:	8c441aec */ 	lw	$a0,0x1aec($v0)
/*  f0c1a70:	c4e40008 */ 	lwc1	$f4,0x8($a3)
/*  f0c1a74:	46048032 */ 	c.eq.s	$f16,$f4
/*  f0c1a78:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c1a7c:	450300b4 */ 	bc1tl	.NB0f0c1d50
/*  f0c1a80:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0c1a84:	8c441aec */ 	lw	$a0,0x1aec($v0)
.NB0f0c1a88:
/*  f0c1a88:	00002825 */ 	or	$a1,$zero,$zero
/*  f0c1a8c:	50800006 */ 	beqzl	$a0,.NB0f0c1aa8
/*  f0c1a90:	8c4400bc */ 	lw	$a0,0xbc($v0)
/*  f0c1a94:	0fc18cfb */ 	jal	propSetCollisionsEnabled
/*  f0c1a98:	afa700b8 */ 	sw	$a3,0xb8($sp)
/*  f0c1a9c:	8fa700b8 */ 	lw	$a3,0xb8($sp)
/*  f0c1aa0:	8e020284 */ 	lw	$v0,0x284($s0)
/*  f0c1aa4:	8c4400bc */ 	lw	$a0,0xbc($v0)
.NB0f0c1aa8:
/*  f0c1aa8:	afa700b8 */ 	sw	$a3,0xb8($sp)
/*  f0c1aac:	0fc18cfb */ 	jal	propSetCollisionsEnabled
/*  f0c1ab0:	00002825 */ 	or	$a1,$zero,$zero
/*  f0c1ab4:	8fa700b8 */ 	lw	$a3,0xb8($sp)
/*  f0c1ab8:	c7a600a4 */ 	lwc1	$f6,0xa4($sp)
/*  f0c1abc:	c7b200a8 */ 	lwc1	$f18,0xa8($sp)
/*  f0c1ac0:	c4e80000 */ 	lwc1	$f8,0x0($a3)
/*  f0c1ac4:	8e0a0328 */ 	lw	$t2,0x328($s0)
/*  f0c1ac8:	240c0020 */ 	addiu	$t4,$zero,0x20
/*  f0c1acc:	46083280 */ 	add.s	$f10,$f6,$f8
/*  f0c1ad0:	c7a800ac */ 	lwc1	$f8,0xac($sp)
/*  f0c1ad4:	8fab00c8 */ 	lw	$t3,0xc8($sp)
/*  f0c1ad8:	27a50054 */ 	addiu	$a1,$sp,0x54
/*  f0c1adc:	e7aa00a4 */ 	swc1	$f10,0xa4($sp)
/*  f0c1ae0:	c4e40004 */ 	lwc1	$f4,0x4($a3)
/*  f0c1ae4:	27a6005c */ 	addiu	$a2,$sp,0x5c
/*  f0c1ae8:	46049180 */ 	add.s	$f6,$f18,$f4
/*  f0c1aec:	e7a600a8 */ 	swc1	$f6,0xa8($sp)
/*  f0c1af0:	c4ea0008 */ 	lwc1	$f10,0x8($a3)
/*  f0c1af4:	460a4480 */ 	add.s	$f18,$f8,$f10
/*  f0c1af8:	11400003 */ 	beqz	$t2,.NB0f0c1b08
/*  f0c1afc:	e7b200ac */ 	swc1	$f18,0xac($sp)
/*  f0c1b00:	10000002 */ 	beqz	$zero,.NB0f0c1b0c
/*  f0c1b04:	afab0060 */ 	sw	$t3,0x60($sp)
.NB0f0c1b08:
/*  f0c1b08:	afac0060 */ 	sw	$t4,0x60($sp)
.NB0f0c1b0c:
/*  f0c1b0c:	8e0d0284 */ 	lw	$t5,0x284($s0)
/*  f0c1b10:	27a70058 */ 	addiu	$a3,$sp,0x58
/*  f0c1b14:	0fc2ff20 */ 	jal	propPlayerGetBbox
/*  f0c1b18:	8da400bc */ 	lw	$a0,0xbc($t5)
/*  f0c1b1c:	c7a40054 */ 	lwc1	$f4,0x54($sp)
/*  f0c1b20:	c7a600c4 */ 	lwc1	$f6,0xc4($sp)
/*  f0c1b24:	8e0e0284 */ 	lw	$t6,0x284($s0)
/*  f0c1b28:	27af0064 */ 	addiu	$t7,$sp,0x64
/*  f0c1b2c:	46062200 */ 	add.s	$f8,$f4,$f6
/*  f0c1b30:	24180014 */ 	addiu	$t8,$zero,0x14
/*  f0c1b34:	27a600a4 */ 	addiu	$a2,$sp,0xa4
/*  f0c1b38:	27a70094 */ 	addiu	$a3,$sp,0x94
/*  f0c1b3c:	e7a80054 */ 	swc1	$f8,0x54($sp)
/*  f0c1b40:	8dc200bc */ 	lw	$v0,0xbc($t6)
/*  f0c1b44:	afb80014 */ 	sw	$t8,0x14($sp)
/*  f0c1b48:	afaf0010 */ 	sw	$t7,0x10($sp)
/*  f0c1b4c:	24440008 */ 	addiu	$a0,$v0,0x8
/*  f0c1b50:	0fc19419 */ 	jal	func0f065dfc
/*  f0c1b54:	24450028 */ 	addiu	$a1,$v0,0x28
/*  f0c1b58:	87b90094 */ 	lh	$t9,0x94($sp)
/*  f0c1b5c:	2405ffff */ 	addiu	$a1,$zero,-1
/*  f0c1b60:	240affff */ 	addiu	$t2,$zero,-1
/*  f0c1b64:	10b9000e */ 	beq	$a1,$t9,.NB0f0c1ba0
/*  f0c1b68:	27a60094 */ 	addiu	$a2,$sp,0x94
/*  f0c1b6c:	8e080284 */ 	lw	$t0,0x284($s0)
/*  f0c1b70:	27a20094 */ 	addiu	$v0,$sp,0x94
/*  f0c1b74:	84430000 */ 	lh	$v1,0x0($v0)
/*  f0c1b78:	850419b0 */ 	lh	$a0,0x19b0($t0)
.NB0f0c1b7c:
/*  f0c1b7c:	54830005 */ 	bnel	$a0,$v1,.NB0f0c1b94
/*  f0c1b80:	84430002 */ 	lh	$v1,0x2($v0)
/*  f0c1b84:	a7a40094 */ 	sh	$a0,0x94($sp)
/*  f0c1b88:	10000005 */ 	beqz	$zero,.NB0f0c1ba0
/*  f0c1b8c:	a7aa0096 */ 	sh	$t2,0x96($sp)
/*  f0c1b90:	84430002 */ 	lh	$v1,0x2($v0)
.NB0f0c1b94:
/*  f0c1b94:	24420002 */ 	addiu	$v0,$v0,0x2
/*  f0c1b98:	14a3fff8 */ 	bne	$a1,$v1,.NB0f0c1b7c
/*  f0c1b9c:	00000000 */ 	sll	$zero,$zero,0x0
.NB0f0c1ba0:
/*  f0c1ba0:	8e040284 */ 	lw	$a0,0x284($s0)
/*  f0c1ba4:	0fc323f3 */ 	jal	bmove0f0cb79c
/*  f0c1ba8:	27a500a4 */ 	addiu	$a1,$sp,0xa4
/*  f0c1bac:	8e0c0284 */ 	lw	$t4,0x284($s0)
/*  f0c1bb0:	240b0001 */ 	addiu	$t3,$zero,0x1
/*  f0c1bb4:	afab0090 */ 	sw	$t3,0x90($sp)
/*  f0c1bb8:	8d8200bc */ 	lw	$v0,0xbc($t4)
/*  f0c1bbc:	c7aa00a4 */ 	lwc1	$f10,0xa4($sp)
/*  f0c1bc0:	3c013f00 */ 	lui	$at,0x3f00
/*  f0c1bc4:	c4520008 */ 	lwc1	$f18,0x8($v0)
/*  f0c1bc8:	c7a80054 */ 	lwc1	$f8,0x54($sp)
/*  f0c1bcc:	c7a400ac */ 	lwc1	$f4,0xac($sp)
/*  f0c1bd0:	46125081 */ 	sub.s	$f2,$f10,$f18
/*  f0c1bd4:	44815000 */ 	mtc1	$at,$f10
/*  f0c1bd8:	c4460010 */ 	lwc1	$f6,0x10($v0)
/*  f0c1bdc:	c7b20054 */ 	lwc1	$f18,0x54($sp)
/*  f0c1be0:	460a4002 */ 	mul.s	$f0,$f8,$f10
/*  f0c1be4:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f0c1be8:	46062301 */ 	sub.s	$f12,$f4,$f6
/*  f0c1bec:	4602003c */ 	c.lt.s	$f0,$f2
/*  f0c1bf0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c1bf4:	45030010 */ 	bc1tl	.NB0f0c1c38
/*  f0c1bf8:	8fad0060 */ 	lw	$t5,0x60($sp)
/*  f0c1bfc:	460c003c */ 	c.lt.s	$f0,$f12
/*  f0c1c00:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c1c04:	4503000c */ 	bc1tl	.NB0f0c1c38
/*  f0c1c08:	8fad0060 */ 	lw	$t5,0x60($sp)
/*  f0c1c0c:	46000387 */ 	neg.s	$f14,$f0
/*  f0c1c10:	460e103c */ 	c.lt.s	$f2,$f14
/*  f0c1c14:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c1c18:	45030007 */ 	bc1tl	.NB0f0c1c38
/*  f0c1c1c:	8fad0060 */ 	lw	$t5,0x60($sp)
/*  f0c1c20:	460e603c */ 	c.lt.s	$f12,$f14
/*  f0c1c24:	8fa80060 */ 	lw	$t0,0x60($sp)
/*  f0c1c28:	24090001 */ 	addiu	$t1,$zero,0x1
/*  f0c1c2c:	45020029 */ 	bc1fl	.NB0f0c1cd4
/*  f0c1c30:	afa80010 */ 	sw	$t0,0x10($sp)
/*  f0c1c34:	8fad0060 */ 	lw	$t5,0x60($sp)
.NB0f0c1c38:
/*  f0c1c38:	e7b20010 */ 	swc1	$f18,0x10($sp)
/*  f0c1c3c:	afae0018 */ 	sw	$t6,0x18($sp)
/*  f0c1c40:	afad0014 */ 	sw	$t5,0x14($sp)
/*  f0c1c44:	c440000c */ 	lwc1	$f0,0xc($v0)
/*  f0c1c48:	c7a4005c */ 	lwc1	$f4,0x5c($sp)
/*  f0c1c4c:	c7a80058 */ 	lwc1	$f8,0x58($sp)
/*  f0c1c50:	24440008 */ 	addiu	$a0,$v0,0x8
/*  f0c1c54:	46002181 */ 	sub.s	$f6,$f4,$f0
/*  f0c1c58:	24450028 */ 	addiu	$a1,$v0,0x28
/*  f0c1c5c:	27a600a4 */ 	addiu	$a2,$sp,0xa4
/*  f0c1c60:	46004281 */ 	sub.s	$f10,$f8,$f0
/*  f0c1c64:	e7a6001c */ 	swc1	$f6,0x1c($sp)
/*  f0c1c68:	27a70094 */ 	addiu	$a3,$sp,0x94
/*  f0c1c6c:	0c00bb59 */ 	jal	cdTestAToB3
/*  f0c1c70:	e7aa0020 */ 	swc1	$f10,0x20($sp)
/*  f0c1c74:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0c1c78:	14410024 */ 	bne	$v0,$at,.NB0f0c1d0c
/*  f0c1c7c:	00401825 */ 	or	$v1,$v0,$zero
/*  f0c1c80:	8e0f0284 */ 	lw	$t7,0x284($s0)
/*  f0c1c84:	8fb80060 */ 	lw	$t8,0x60($sp)
/*  f0c1c88:	24190001 */ 	addiu	$t9,$zero,0x1
/*  f0c1c8c:	8de200bc */ 	lw	$v0,0xbc($t7)
/*  f0c1c90:	afb90014 */ 	sw	$t9,0x14($sp)
/*  f0c1c94:	afb80010 */ 	sw	$t8,0x10($sp)
/*  f0c1c98:	c440000c */ 	lwc1	$f0,0xc($v0)
/*  f0c1c9c:	c7b2005c */ 	lwc1	$f18,0x5c($sp)
/*  f0c1ca0:	c7a60058 */ 	lwc1	$f6,0x58($sp)
/*  f0c1ca4:	27a500a4 */ 	addiu	$a1,$sp,0xa4
/*  f0c1ca8:	46009101 */ 	sub.s	$f4,$f18,$f0
/*  f0c1cac:	8fa60054 */ 	lw	$a2,0x54($sp)
/*  f0c1cb0:	27a70094 */ 	addiu	$a3,$sp,0x94
/*  f0c1cb4:	46003201 */ 	sub.s	$f8,$f6,$f0
/*  f0c1cb8:	e7a40018 */ 	swc1	$f4,0x18($sp)
/*  f0c1cbc:	24440008 */ 	addiu	$a0,$v0,0x8
/*  f0c1cc0:	0c00af7e */ 	jal	cdTestAToB1
/*  f0c1cc4:	e7a8001c */ 	swc1	$f8,0x1c($sp)
/*  f0c1cc8:	10000010 */ 	beqz	$zero,.NB0f0c1d0c
/*  f0c1ccc:	00401825 */ 	or	$v1,$v0,$zero
/*  f0c1cd0:	afa80010 */ 	sw	$t0,0x10($sp)
.NB0f0c1cd4:
/*  f0c1cd4:	afa90014 */ 	sw	$t1,0x14($sp)
/*  f0c1cd8:	c440000c */ 	lwc1	$f0,0xc($v0)
/*  f0c1cdc:	c7aa005c */ 	lwc1	$f10,0x5c($sp)
/*  f0c1ce0:	c7a40058 */ 	lwc1	$f4,0x58($sp)
/*  f0c1ce4:	24440008 */ 	addiu	$a0,$v0,0x8
/*  f0c1ce8:	46005481 */ 	sub.s	$f18,$f10,$f0
/*  f0c1cec:	27a500a4 */ 	addiu	$a1,$sp,0xa4
/*  f0c1cf0:	8fa60054 */ 	lw	$a2,0x54($sp)
/*  f0c1cf4:	46002181 */ 	sub.s	$f6,$f4,$f0
/*  f0c1cf8:	e7b20018 */ 	swc1	$f18,0x18($sp)
/*  f0c1cfc:	27a70064 */ 	addiu	$a3,$sp,0x64
/*  f0c1d00:	0c00af7e */ 	jal	cdTestAToB1
/*  f0c1d04:	e7a6001c */ 	swc1	$f6,0x1c($sp)
/*  f0c1d08:	00401825 */ 	or	$v1,$v0,$zero
.NB0f0c1d0c:
/*  f0c1d0c:	8e0a0284 */ 	lw	$t2,0x284($s0)
/*  f0c1d10:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f0c1d14:	8d4400bc */ 	lw	$a0,0xbc($t2)
/*  f0c1d18:	0fc18cfb */ 	jal	propSetCollisionsEnabled
/*  f0c1d1c:	afa300b4 */ 	sw	$v1,0xb4($sp)
/*  f0c1d20:	8e0b0284 */ 	lw	$t3,0x284($s0)
/*  f0c1d24:	44808000 */ 	mtc1	$zero,$f16
/*  f0c1d28:	8fa300b4 */ 	lw	$v1,0xb4($sp)
/*  f0c1d2c:	8d641aec */ 	lw	$a0,0x1aec($t3)
/*  f0c1d30:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f0c1d34:	50800006 */ 	beqzl	$a0,.NB0f0c1d50
/*  f0c1d38:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0c1d3c:	0fc18cfb */ 	jal	propSetCollisionsEnabled
/*  f0c1d40:	afa300b4 */ 	sw	$v1,0xb4($sp)
/*  f0c1d44:	44808000 */ 	mtc1	$zero,$f16
/*  f0c1d48:	8fa300b4 */ 	lw	$v1,0xb4($sp)
/*  f0c1d4c:	24010001 */ 	addiu	$at,$zero,0x1
.NB0f0c1d50:
/*  f0c1d50:	14610038 */ 	bne	$v1,$at,.NB0f0c1e34
/*  f0c1d54:	8fac00c0 */ 	lw	$t4,0xc0($sp)
/*  f0c1d58:	11800036 */ 	beqz	$t4,.NB0f0c1e34
/*  f0c1d5c:	3c0143b4 */ 	lui	$at,0x43b4
/*  f0c1d60:	44811000 */ 	mtc1	$at,$f2
/*  f0c1d64:	c7a800bc */ 	lwc1	$f8,0xbc($sp)
/*  f0c1d68:	3c017f1a */ 	lui	$at,0x7f1a
/*  f0c1d6c:	c4327ad8 */ 	lwc1	$f18,0x7ad8($at)
/*  f0c1d70:	46024282 */ 	mul.s	$f10,$f8,$f2
/*  f0c1d74:	8e020284 */ 	lw	$v0,0x284($s0)
/*  f0c1d78:	c4460144 */ 	lwc1	$f6,0x144($v0)
/*  f0c1d7c:	46125103 */ 	div.s	$f4,$f10,$f18
/*  f0c1d80:	46043000 */ 	add.s	$f0,$f6,$f4
/*  f0c1d84:	4610003c */ 	c.lt.s	$f0,$f16
/*  f0c1d88:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c1d8c:	45020007 */ 	bc1fl	.NB0f0c1dac
/*  f0c1d90:	4600103e */ 	c.le.s	$f2,$f0
/*  f0c1d94:	46020000 */ 	add.s	$f0,$f0,$f2
.NB0f0c1d98:
/*  f0c1d98:	4610003c */ 	c.lt.s	$f0,$f16
/*  f0c1d9c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c1da0:	4503fffd */ 	bc1tl	.NB0f0c1d98
/*  f0c1da4:	46020000 */ 	add.s	$f0,$f0,$f2
/*  f0c1da8:	4600103e */ 	c.le.s	$f2,$f0
.NB0f0c1dac:
/*  f0c1dac:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c1db0:	45020007 */ 	bc1fl	.NB0f0c1dd0
/*  f0c1db4:	e4400144 */ 	swc1	$f0,0x144($v0)
/*  f0c1db8:	46020001 */ 	sub.s	$f0,$f0,$f2
.NB0f0c1dbc:
/*  f0c1dbc:	4600103e */ 	c.le.s	$f2,$f0
/*  f0c1dc0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c1dc4:	4503fffd */ 	bc1tl	.NB0f0c1dbc
/*  f0c1dc8:	46020001 */ 	sub.s	$f0,$f0,$f2
/*  f0c1dcc:	e4400144 */ 	swc1	$f0,0x144($v0)
.NB0f0c1dd0:
/*  f0c1dd0:	8e0d0284 */ 	lw	$t5,0x284($s0)
/*  f0c1dd4:	c7a800a4 */ 	lwc1	$f8,0xa4($sp)
/*  f0c1dd8:	8dae00bc */ 	lw	$t6,0xbc($t5)
/*  f0c1ddc:	e5c80008 */ 	swc1	$f8,0x8($t6)
/*  f0c1de0:	8e0f0284 */ 	lw	$t7,0x284($s0)
/*  f0c1de4:	c7aa00a8 */ 	lwc1	$f10,0xa8($sp)
/*  f0c1de8:	8df800bc */ 	lw	$t8,0xbc($t7)
/*  f0c1dec:	e70a000c */ 	swc1	$f10,0xc($t8)
/*  f0c1df0:	8e190284 */ 	lw	$t9,0x284($s0)
/*  f0c1df4:	c7b200ac */ 	lwc1	$f18,0xac($sp)
/*  f0c1df8:	8f2800bc */ 	lw	$t0,0xbc($t9)
/*  f0c1dfc:	e5120010 */ 	swc1	$f18,0x10($t0)
/*  f0c1e00:	8fa90090 */ 	lw	$t1,0x90($sp)
/*  f0c1e04:	5120000c */ 	beqzl	$t1,.NB0f0c1e38
/*  f0c1e08:	8fbf0034 */ 	lw	$ra,0x34($sp)
/*  f0c1e0c:	8e0a0284 */ 	lw	$t2,0x284($s0)
/*  f0c1e10:	8d4400bc */ 	lw	$a0,0xbc($t2)
/*  f0c1e14:	0fc193ab */ 	jal	func0f065c44
/*  f0c1e18:	afa300b4 */ 	sw	$v1,0xb4($sp)
/*  f0c1e1c:	8e0b0284 */ 	lw	$t3,0x284($s0)
/*  f0c1e20:	27a40094 */ 	addiu	$a0,$sp,0x94
/*  f0c1e24:	8d6500bc */ 	lw	$a1,0xbc($t3)
/*  f0c1e28:	0fc19283 */ 	jal	roomsCopy
/*  f0c1e2c:	24a50028 */ 	addiu	$a1,$a1,0x28
/*  f0c1e30:	8fa300b4 */ 	lw	$v1,0xb4($sp)
.NB0f0c1e34:
/*  f0c1e34:	8fbf0034 */ 	lw	$ra,0x34($sp)
.NB0f0c1e38:
/*  f0c1e38:	240c0001 */ 	addiu	$t4,$zero,0x1
/*  f0c1e3c:	ae0c032c */ 	sw	$t4,0x32c($s0)
/*  f0c1e40:	8fb00030 */ 	lw	$s0,0x30($sp)
/*  f0c1e44:	27bd00b8 */ 	addiu	$sp,$sp,0xb8
/*  f0c1e48:	03e00008 */ 	jr	$ra
/*  f0c1e4c:	00601025 */ 	or	$v0,$v1,$zero
);
#endif

const char var7f1ad75c[] = "bondwalk.c";

#if VERSION >= VERSION_PAL_FINAL
GLOBAL_ASM(
glabel bwalkCalculateNewPositionWithPush
/*  f0c4250:	27bdff58 */ 	addiu	$sp,$sp,-168
/*  f0c4254:	8fae00b8 */ 	lw	$t6,0xb8($sp)
/*  f0c4258:	afbf0024 */ 	sw	$ra,0x24($sp)
/*  f0c425c:	afa400a8 */ 	sw	$a0,0xa8($sp)
/*  f0c4260:	afa500ac */ 	sw	$a1,0xac($sp)
/*  f0c4264:	afa600b0 */ 	sw	$a2,0xb0($sp)
/*  f0c4268:	afa700b4 */ 	sw	$a3,0xb4($sp)
/*  f0c426c:	0fc30f85 */ 	jal	bwalkCalculateNewPosition
/*  f0c4270:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f0c4274:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0c4278:	10410135 */ 	beq	$v0,$at,.L0f0c4750
/*  f0c427c:	afa200a4 */ 	sw	$v0,0xa4($sp)
/*  f0c4280:	0c0093ac */ 	jal	cdGetObstacle
/*  f0c4284:	00000000 */ 	nop
/*  f0c4288:	10400131 */ 	beqz	$v0,.L0f0c4750
/*  f0c428c:	afa200a0 */ 	sw	$v0,0xa0($sp)
/*  f0c4290:	3c08800a */ 	lui	$t0,%hi(g_Vars)
/*  f0c4294:	25089fc0 */ 	addiu	$t0,$t0,%lo(g_Vars)
/*  f0c4298:	8d0f0034 */ 	lw	$t7,0x34($t0)
/*  f0c429c:	59e0012d */ 	blezl	$t7,.L0f0c4754
/*  f0c42a0:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*  f0c42a4:	90430000 */ 	lbu	$v1,0x0($v0)
/*  f0c42a8:	24010002 */ 	addiu	$at,$zero,0x2
/*  f0c42ac:	54610046 */ 	bnel	$v1,$at,.L0f0c43c8
/*  f0c42b0:	24010003 */ 	addiu	$at,$zero,0x3
/*  f0c42b4:	8c430004 */ 	lw	$v1,0x4($v0)
/*  f0c42b8:	94780070 */ 	lhu	$t8,0x70($v1)
/*  f0c42bc:	33190400 */ 	andi	$t9,$t8,0x400
/*  f0c42c0:	53200124 */ 	beqzl	$t9,.L0f0c4754
/*  f0c42c4:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*  f0c42c8:	8d090284 */ 	lw	$t1,0x284($t0)
/*  f0c42cc:	27a40084 */ 	addiu	$a0,$sp,0x84
/*  f0c42d0:	27a50078 */ 	addiu	$a1,$sp,0x78
/*  f0c42d4:	8d2a00d8 */ 	lw	$t2,0xd8($t1)
/*  f0c42d8:	240601d1 */ 	addiu	$a2,$zero,0x1d1
/*  f0c42dc:	3c077f1b */ 	lui	$a3,%hi(var7f1ad75c)
/*  f0c42e0:	5540011c */ 	bnezl	$t2,.L0f0c4754
/*  f0c42e4:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*  f0c42e8:	0c009393 */ 	jal	func00024e4c
/*  f0c42ec:	24e7d75c */ 	addiu	$a3,$a3,%lo(var7f1ad75c)
/*  f0c42f0:	c7a40080 */ 	lwc1	$f4,0x80($sp)
/*  f0c42f4:	c7a6008c */ 	lwc1	$f6,0x8c($sp)
/*  f0c42f8:	44801000 */ 	mtc1	$zero,$f2
/*  f0c42fc:	c7a80084 */ 	lwc1	$f8,0x84($sp)
/*  f0c4300:	46062001 */ 	sub.s	$f0,$f4,$f6
/*  f0c4304:	c7aa0078 */ 	lwc1	$f10,0x78($sp)
/*  f0c4308:	3c08800a */ 	lui	$t0,%hi(g_Vars)
/*  f0c430c:	25089fc0 */ 	addiu	$t0,$t0,%lo(g_Vars)
/*  f0c4310:	46001032 */ 	c.eq.s	$f2,$f0
/*  f0c4314:	e7a00090 */ 	swc1	$f0,0x90($sp)
/*  f0c4318:	460a4101 */ 	sub.s	$f4,$f8,$f10
/*  f0c431c:	27a40090 */ 	addiu	$a0,$sp,0x90
/*  f0c4320:	e7a20094 */ 	swc1	$f2,0x94($sp)
/*  f0c4324:	45000004 */ 	bc1f	.L0f0c4338
/*  f0c4328:	e7a40098 */ 	swc1	$f4,0x98($sp)
/*  f0c432c:	46041032 */ 	c.eq.s	$f2,$f4
/*  f0c4330:	3c013f80 */ 	lui	$at,0x3f80
/*  f0c4334:	45010006 */ 	bc1t	.L0f0c4350
.L0f0c4338:
/*  f0c4338:	27a50094 */ 	addiu	$a1,$sp,0x94
/*  f0c433c:	0c0011e4 */ 	jal	guNormalize
/*  f0c4340:	27a60098 */ 	addiu	$a2,$sp,0x98
/*  f0c4344:	3c08800a */ 	lui	$t0,%hi(g_Vars)
/*  f0c4348:	10000004 */ 	b	.L0f0c435c
/*  f0c434c:	25089fc0 */ 	addiu	$t0,$t0,%lo(g_Vars)
.L0f0c4350:
/*  f0c4350:	44813000 */ 	mtc1	$at,$f6
/*  f0c4354:	00000000 */ 	nop
/*  f0c4358:	e7a60098 */ 	swc1	$f6,0x98($sp)
.L0f0c435c:
/*  f0c435c:	8d0b0284 */ 	lw	$t3,0x284($t0)
/*  f0c4360:	3c053ecc */ 	lui	$a1,0x3ecc
/*  f0c4364:	34a5cccd */ 	ori	$a1,$a1,0xcccd
/*  f0c4368:	8d6200bc */ 	lw	$v0,0xbc($t3)
/*  f0c436c:	27a60090 */ 	addiu	$a2,$sp,0x90
/*  f0c4370:	00003825 */ 	or	$a3,$zero,$zero
/*  f0c4374:	8c440004 */ 	lw	$a0,0x4($v0)
/*  f0c4378:	0fc0d05f */ 	jal	chrDamageByLaser
/*  f0c437c:	afa20010 */ 	sw	$v0,0x10($sp)
/*  f0c4380:	3c01bf80 */ 	lui	$at,0xbf80
/*  f0c4384:	44814000 */ 	mtc1	$at,$f8
/*  f0c4388:	3c048009 */ 	lui	$a0,%hi(var80095200)
/*  f0c438c:	240cffff */ 	addiu	$t4,$zero,-1
/*  f0c4390:	240dffff */ 	addiu	$t5,$zero,-1
/*  f0c4394:	240effff */ 	addiu	$t6,$zero,-1
/*  f0c4398:	afae001c */ 	sw	$t6,0x1c($sp)
/*  f0c439c:	afad0018 */ 	sw	$t5,0x18($sp)
/*  f0c43a0:	afac0010 */ 	sw	$t4,0x10($sp)
/*  f0c43a4:	8c845200 */ 	lw	$a0,%lo(var80095200)($a0)
/*  f0c43a8:	240500f2 */ 	addiu	$a1,$zero,0xf2
/*  f0c43ac:	00003025 */ 	or	$a2,$zero,$zero
/*  f0c43b0:	2407ffff */ 	addiu	$a3,$zero,-1
/*  f0c43b4:	0c004241 */ 	jal	sndStart
/*  f0c43b8:	e7a80014 */ 	swc1	$f8,0x14($sp)
/*  f0c43bc:	100000e5 */ 	b	.L0f0c4754
/*  f0c43c0:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*  f0c43c4:	24010003 */ 	addiu	$at,$zero,0x3
.L0f0c43c8:
/*  f0c43c8:	5461008b */ 	bnel	$v1,$at,.L0f0c45f8
/*  f0c43cc:	24010006 */ 	addiu	$at,$zero,0x6
/*  f0c43d0:	8d180318 */ 	lw	$t8,0x318($t0)
/*  f0c43d4:	8c4f0004 */ 	lw	$t7,0x4($v0)
/*  f0c43d8:	00001825 */ 	or	$v1,$zero,$zero
/*  f0c43dc:	1300000c */ 	beqz	$t8,.L0f0c4410
/*  f0c43e0:	afaf0074 */ 	sw	$t7,0x74($sp)
/*  f0c43e4:	8d190284 */ 	lw	$t9,0x284($t0)
/*  f0c43e8:	01e02825 */ 	or	$a1,$t7,$zero
/*  f0c43ec:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f0c43f0:	8f2900bc */ 	lw	$t1,0xbc($t9)
/*  f0c43f4:	8d240004 */ 	lw	$a0,0x4($t1)
/*  f0c43f8:	0fc12aa3 */ 	jal	chrCompareTeams
/*  f0c43fc:	afa00044 */ 	sw	$zero,0x44($sp)
/*  f0c4400:	10400014 */ 	beqz	$v0,.L0f0c4454
/*  f0c4404:	8fa30044 */ 	lw	$v1,0x44($sp)
/*  f0c4408:	10000012 */ 	b	.L0f0c4454
/*  f0c440c:	24030001 */ 	addiu	$v1,$zero,0x1
.L0f0c4410:
/*  f0c4410:	8faa0074 */ 	lw	$t2,0x74($sp)
/*  f0c4414:	8d4b0018 */ 	lw	$t3,0x18($t2)
/*  f0c4418:	000b61c0 */ 	sll	$t4,$t3,0x7
/*  f0c441c:	0581000d */ 	bgez	$t4,.L0f0c4454
/*  f0c4420:	00000000 */ 	nop
/*  f0c4424:	8d0d029c */ 	lw	$t5,0x29c($t0)
/*  f0c4428:	05a2000a */ 	bltzl	$t5,.L0f0c4454
/*  f0c442c:	24030001 */ 	addiu	$v1,$zero,0x1
/*  f0c4430:	8d0e02a8 */ 	lw	$t6,0x2a8($t0)
/*  f0c4434:	8d0f0284 */ 	lw	$t7,0x284($t0)
/*  f0c4438:	55cf0006 */ 	bnel	$t6,$t7,.L0f0c4454
/*  f0c443c:	24030001 */ 	addiu	$v1,$zero,0x1
/*  f0c4440:	8d580014 */ 	lw	$t8,0x14($t2)
/*  f0c4444:	0018c840 */ 	sll	$t9,$t8,0x1
/*  f0c4448:	07200002 */ 	bltz	$t9,.L0f0c4454
/*  f0c444c:	00000000 */ 	nop
/*  f0c4450:	24030001 */ 	addiu	$v1,$zero,0x1
.L0f0c4454:
/*  f0c4454:	106000be */ 	beqz	$v1,.L0f0c4750
/*  f0c4458:	8fa200a8 */ 	lw	$v0,0xa8($sp)
/*  f0c445c:	c4400008 */ 	lwc1	$f0,0x8($v0)
/*  f0c4460:	c4420000 */ 	lwc1	$f2,0x0($v0)
/*  f0c4464:	46000282 */ 	mul.s	$f10,$f0,$f0
/*  f0c4468:	00000000 */ 	nop
/*  f0c446c:	46021102 */ 	mul.s	$f4,$f2,$f2
/*  f0c4470:	0c012974 */ 	jal	sqrtf
/*  f0c4474:	46045300 */ 	add.s	$f12,$f10,$f4
/*  f0c4478:	3c08800a */ 	lui	$t0,%hi(g_Vars)
/*  f0c447c:	25089fc0 */ 	addiu	$t0,$t0,%lo(g_Vars)
/*  f0c4480:	c5060044 */ 	lwc1	$f6,0x4c($t0)
/*  f0c4484:	8d090284 */ 	lw	$t1,0x284($t0)
/*  f0c4488:	8fa300a0 */ 	lw	$v1,0xa0($sp)
/*  f0c448c:	46060203 */ 	div.s	$f8,$f0,$f6
/*  f0c4490:	44801000 */ 	mtc1	$zero,$f2
/*  f0c4494:	e7a80054 */ 	swc1	$f8,0x54($sp)
/*  f0c4498:	8d2200bc */ 	lw	$v0,0xbc($t1)
/*  f0c449c:	c46a0008 */ 	lwc1	$f10,0x8($v1)
/*  f0c44a0:	c4660010 */ 	lwc1	$f6,0x10($v1)
/*  f0c44a4:	c4440008 */ 	lwc1	$f4,0x8($v0)
/*  f0c44a8:	c4480010 */ 	lwc1	$f8,0x10($v0)
/*  f0c44ac:	46045381 */ 	sub.s	$f14,$f10,$f4
/*  f0c44b0:	46083401 */ 	sub.s	$f16,$f6,$f8
/*  f0c44b4:	46027032 */ 	c.eq.s	$f14,$f2
/*  f0c44b8:	00000000 */ 	nop
/*  f0c44bc:	45000005 */ 	bc1f	.L0f0c44d4
/*  f0c44c0:	00000000 */ 	nop
/*  f0c44c4:	46028032 */ 	c.eq.s	$f16,$f2
/*  f0c44c8:	00000000 */ 	nop
/*  f0c44cc:	450300a1 */ 	bc1tl	.L0f0c4754
/*  f0c44d0:	8fbf0024 */ 	lw	$ra,0x24($sp)
.L0f0c44d4:
/*  f0c44d4:	460e7282 */ 	mul.s	$f10,$f14,$f14
/*  f0c44d8:	e7ae0050 */ 	swc1	$f14,0x50($sp)
/*  f0c44dc:	e7b0004c */ 	swc1	$f16,0x4c($sp)
/*  f0c44e0:	46108102 */ 	mul.s	$f4,$f16,$f16
/*  f0c44e4:	0c012974 */ 	jal	sqrtf
/*  f0c44e8:	46045300 */ 	add.s	$f12,$f10,$f4
/*  f0c44ec:	44801000 */ 	mtc1	$zero,$f2
/*  f0c44f0:	3c08800a */ 	lui	$t0,%hi(g_Vars)
/*  f0c44f4:	25089fc0 */ 	addiu	$t0,$t0,%lo(g_Vars)
/*  f0c44f8:	4600103c */ 	c.lt.s	$f2,$f0
/*  f0c44fc:	c7ae0050 */ 	lwc1	$f14,0x50($sp)
/*  f0c4500:	c7b0004c */ 	lwc1	$f16,0x4c($sp)
/*  f0c4504:	c7a60054 */ 	lwc1	$f6,0x54($sp)
/*  f0c4508:	45020092 */ 	bc1fl	.L0f0c4754
/*  f0c450c:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*  f0c4510:	46003303 */ 	div.s	$f12,$f6,$f0
/*  f0c4514:	3c013f00 */ 	lui	$at,0x3f00
/*  f0c4518:	44819000 */ 	mtc1	$at,$f18
/*  f0c451c:	8fa40074 */ 	lw	$a0,0x74($sp)
/*  f0c4520:	8fa200a0 */ 	lw	$v0,0xa0($sp)
/*  f0c4524:	27a50068 */ 	addiu	$a1,$sp,0x68
/*  f0c4528:	27a60058 */ 	addiu	$a2,$sp,0x58
/*  f0c452c:	00003825 */ 	or	$a3,$zero,$zero
/*  f0c4530:	460c7382 */ 	mul.s	$f14,$f14,$f12
/*  f0c4534:	00000000 */ 	nop
/*  f0c4538:	460c8402 */ 	mul.s	$f16,$f16,$f12
/*  f0c453c:	00000000 */ 	nop
/*  f0c4540:	460e9082 */ 	mul.s	$f2,$f18,$f14
/*  f0c4544:	00000000 */ 	nop
/*  f0c4548:	46109202 */ 	mul.s	$f8,$f18,$f16
/*  f0c454c:	e4820304 */ 	swc1	$f2,0x304($a0)
/*  f0c4550:	e4880308 */ 	swc1	$f8,0x308($a0)
/*  f0c4554:	c5000044 */ 	lwc1	$f0,0x4c($t0)
/*  f0c4558:	c4440008 */ 	lwc1	$f4,0x8($v0)
/*  f0c455c:	46001282 */ 	mul.s	$f10,$f2,$f0
/*  f0c4560:	46045180 */ 	add.s	$f6,$f10,$f4
/*  f0c4564:	e7a60068 */ 	swc1	$f6,0x68($sp)
/*  f0c4568:	c448000c */ 	lwc1	$f8,0xc($v0)
/*  f0c456c:	e7a8006c */ 	swc1	$f8,0x6c($sp)
/*  f0c4570:	c48a0308 */ 	lwc1	$f10,0x308($a0)
/*  f0c4574:	c4460010 */ 	lwc1	$f6,0x10($v0)
/*  f0c4578:	46005102 */ 	mul.s	$f4,$f10,$f0
/*  f0c457c:	46062200 */ 	add.s	$f8,$f4,$f6
/*  f0c4580:	0fc079fd */ 	jal	chrCalculatePushPos
/*  f0c4584:	e7a80070 */ 	swc1	$f8,0x70($sp)
/*  f0c4588:	8fa400a0 */ 	lw	$a0,0xa0($sp)
/*  f0c458c:	c7aa0068 */ 	lwc1	$f10,0x68($sp)
/*  f0c4590:	e48a0008 */ 	swc1	$f10,0x8($a0)
/*  f0c4594:	c7a4006c */ 	lwc1	$f4,0x6c($sp)
/*  f0c4598:	e484000c */ 	swc1	$f4,0xc($a0)
/*  f0c459c:	c7a60070 */ 	lwc1	$f6,0x70($sp)
/*  f0c45a0:	0fc19711 */ 	jal	func0f065c44
/*  f0c45a4:	e4860010 */ 	swc1	$f6,0x10($a0)
/*  f0c45a8:	8fa500a0 */ 	lw	$a1,0xa0($sp)
/*  f0c45ac:	27a40058 */ 	addiu	$a0,$sp,0x58
/*  f0c45b0:	0fc195e9 */ 	jal	roomsCopy
/*  f0c45b4:	24a50028 */ 	addiu	$a1,$a1,0x28
/*  f0c45b8:	0fc0882b */ 	jal	func0f0220ac
/*  f0c45bc:	8fa40074 */ 	lw	$a0,0x74($sp)
/*  f0c45c0:	8fab0074 */ 	lw	$t3,0x74($sp)
/*  f0c45c4:	27a50068 */ 	addiu	$a1,$sp,0x68
/*  f0c45c8:	0c006b4d */ 	jal	modelSetRootPosition
/*  f0c45cc:	8d640020 */ 	lw	$a0,0x20($t3)
/*  f0c45d0:	8fac00b8 */ 	lw	$t4,0xb8($sp)
/*  f0c45d4:	8fa400a8 */ 	lw	$a0,0xa8($sp)
/*  f0c45d8:	8fa500ac */ 	lw	$a1,0xac($sp)
/*  f0c45dc:	8fa600b0 */ 	lw	$a2,0xb0($sp)
/*  f0c45e0:	8fa700b4 */ 	lw	$a3,0xb4($sp)
/*  f0c45e4:	0fc30f85 */ 	jal	bwalkCalculateNewPosition
/*  f0c45e8:	afac0010 */ 	sw	$t4,0x10($sp)
/*  f0c45ec:	10000058 */ 	b	.L0f0c4750
/*  f0c45f0:	afa200a4 */ 	sw	$v0,0xa4($sp)
/*  f0c45f4:	24010006 */ 	addiu	$at,$zero,0x6
.L0f0c45f8:
/*  f0c45f8:	10610055 */ 	beq	$v1,$at,.L0f0c4750
/*  f0c45fc:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0c4600:	54610054 */ 	bnel	$v1,$at,.L0f0c4754
/*  f0c4604:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*  f0c4608:	8c460004 */ 	lw	$a2,0x4($v0)
/*  f0c460c:	8cc30040 */ 	lw	$v1,0x40($a2)
/*  f0c4610:	00036940 */ 	sll	$t5,$v1,0x5
/*  f0c4614:	05a0004e */ 	bltz	$t5,.L0f0c4750
/*  f0c4618:	00037100 */ 	sll	$t6,$v1,0x4
/*  f0c461c:	05c2004d */ 	bltzl	$t6,.L0f0c4754
/*  f0c4620:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*  f0c4624:	8d030284 */ 	lw	$v1,0x284($t0)
/*  f0c4628:	8c6f1af0 */ 	lw	$t7,0x1af0($v1)
/*  f0c462c:	55e00008 */ 	bnezl	$t7,.L0f0c4650
/*  f0c4630:	8cd80010 */ 	lw	$t8,0x10($a2)
/*  f0c4634:	90ca0003 */ 	lbu	$t2,0x3($a2)
/*  f0c4638:	2401002d */ 	addiu	$at,$zero,0x2d
/*  f0c463c:	55410004 */ 	bnel	$t2,$at,.L0f0c4650
/*  f0c4640:	8cd80010 */ 	lw	$t8,0x10($a2)
/*  f0c4644:	10000042 */ 	b	.L0f0c4750
/*  f0c4648:	ac621aec */ 	sw	$v0,0x1aec($v1)
/*  f0c464c:	8cd80010 */ 	lw	$t8,0x10($a2)
.L0f0c4650:
/*  f0c4650:	33190001 */ 	andi	$t9,$t8,0x1
/*  f0c4654:	5320003f */ 	beqzl	$t9,.L0f0c4754
/*  f0c4658:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*  f0c465c:	ac600178 */ 	sw	$zero,0x178($v1)
/*  f0c4660:	8cc90040 */ 	lw	$t1,0x40($a2)
/*  f0c4664:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f0c4668:	8fa400a8 */ 	lw	$a0,0xa8($sp)
/*  f0c466c:	312b0080 */ 	andi	$t3,$t1,0x80
/*  f0c4670:	11600007 */ 	beqz	$t3,.L0f0c4690
/*  f0c4674:	00c02825 */ 	or	$a1,$a2,$zero
/*  f0c4678:	8ccc0048 */ 	lw	$t4,0x48($a2)
/*  f0c467c:	8d8d0000 */ 	lw	$t5,0x0($t4)
/*  f0c4680:	31ae1000 */ 	andi	$t6,$t5,0x1000
/*  f0c4684:	11c00002 */ 	beqz	$t6,.L0f0c4690
/*  f0c4688:	00000000 */ 	nop
/*  f0c468c:	00001025 */ 	or	$v0,$zero,$zero
.L0f0c4690:
/*  f0c4690:	50400030 */ 	beqzl	$v0,.L0f0c4754
/*  f0c4694:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*  f0c4698:	0fc30ece */ 	jal	bwalk0f0c3b38
/*  f0c469c:	afa60040 */ 	sw	$a2,0x40($sp)
/*  f0c46a0:	8fa60040 */ 	lw	$a2,0x40($sp)
/*  f0c46a4:	8ccf0040 */ 	lw	$t7,0x40($a2)
/*  f0c46a8:	31ea0080 */ 	andi	$t2,$t7,0x80
/*  f0c46ac:	51400029 */ 	beqzl	$t2,.L0f0c4754
/*  f0c46b0:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*  f0c46b4:	8cd80048 */ 	lw	$t8,0x48($a2)
/*  f0c46b8:	00c02025 */ 	or	$a0,$a2,$zero
/*  f0c46bc:	27a50034 */ 	addiu	$a1,$sp,0x34
/*  f0c46c0:	8f190000 */ 	lw	$t9,0x0($t8)
/*  f0c46c4:	33290800 */ 	andi	$t1,$t9,0x800
/*  f0c46c8:	51200022 */ 	beqzl	$t1,.L0f0c4754
/*  f0c46cc:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*  f0c46d0:	afa00034 */ 	sw	$zero,0x34($sp)
/*  f0c46d4:	0fc1cf1b */ 	jal	func0f073c6c
/*  f0c46d8:	afa60040 */ 	sw	$a2,0x40($sp)
/*  f0c46dc:	8fa60040 */ 	lw	$a2,0x40($sp)
/*  f0c46e0:	8ccb0040 */ 	lw	$t3,0x40($a2)
/*  f0c46e4:	316c0080 */ 	andi	$t4,$t3,0x80
/*  f0c46e8:	11800010 */ 	beqz	$t4,.L0f0c472c
/*  f0c46ec:	00000000 */ 	nop
/*  f0c46f0:	8cc30048 */ 	lw	$v1,0x48($a2)
/*  f0c46f4:	8c6d0000 */ 	lw	$t5,0x0($v1)
/*  f0c46f8:	35ae1000 */ 	ori	$t6,$t5,0x1000
/*  f0c46fc:	10400006 */ 	beqz	$v0,.L0f0c4718
/*  f0c4700:	ac6e0000 */ 	sw	$t6,0x0($v1)
/*  f0c4704:	8cc30048 */ 	lw	$v1,0x48($a2)
/*  f0c4708:	8c6f0000 */ 	lw	$t7,0x0($v1)
/*  f0c470c:	35ea2000 */ 	ori	$t2,$t7,0x2000
/*  f0c4710:	10000006 */ 	b	.L0f0c472c
/*  f0c4714:	ac6a0000 */ 	sw	$t2,0x0($v1)
.L0f0c4718:
/*  f0c4718:	8cc30048 */ 	lw	$v1,0x48($a2)
/*  f0c471c:	2401dfff */ 	addiu	$at,$zero,-8193
/*  f0c4720:	8c780000 */ 	lw	$t8,0x0($v1)
/*  f0c4724:	0301c824 */ 	and	$t9,$t8,$at
/*  f0c4728:	ac790000 */ 	sw	$t9,0x0($v1)
.L0f0c472c:
/*  f0c472c:	10400008 */ 	beqz	$v0,.L0f0c4750
/*  f0c4730:	8fa400a8 */ 	lw	$a0,0xa8($sp)
/*  f0c4734:	8fa900b8 */ 	lw	$t1,0xb8($sp)
/*  f0c4738:	8fa500ac */ 	lw	$a1,0xac($sp)
/*  f0c473c:	8fa600b0 */ 	lw	$a2,0xb0($sp)
/*  f0c4740:	8fa700b4 */ 	lw	$a3,0xb4($sp)
/*  f0c4744:	0fc30f85 */ 	jal	bwalkCalculateNewPosition
/*  f0c4748:	afa90010 */ 	sw	$t1,0x10($sp)
/*  f0c474c:	afa200a4 */ 	sw	$v0,0xa4($sp)
.L0f0c4750:
/*  f0c4750:	8fbf0024 */ 	lw	$ra,0x24($sp)
.L0f0c4754:
/*  f0c4754:	8fa200a4 */ 	lw	$v0,0xa4($sp)
/*  f0c4758:	27bd00a8 */ 	addiu	$sp,$sp,0xa8
/*  f0c475c:	03e00008 */ 	jr	$ra
/*  f0c4760:	00000000 */ 	nop
);
#else
GLOBAL_ASM(
glabel bwalkCalculateNewPositionWithPush
/*  f0c4250:	27bdff58 */ 	addiu	$sp,$sp,-168
/*  f0c4254:	8fae00b8 */ 	lw	$t6,0xb8($sp)
/*  f0c4258:	afbf0024 */ 	sw	$ra,0x24($sp)
/*  f0c425c:	afa400a8 */ 	sw	$a0,0xa8($sp)
/*  f0c4260:	afa500ac */ 	sw	$a1,0xac($sp)
/*  f0c4264:	afa600b0 */ 	sw	$a2,0xb0($sp)
/*  f0c4268:	afa700b4 */ 	sw	$a3,0xb4($sp)
/*  f0c426c:	0fc30f85 */ 	jal	bwalkCalculateNewPosition
/*  f0c4270:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f0c4274:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0c4278:	10410135 */ 	beq	$v0,$at,.L0f0c4750
/*  f0c427c:	afa200a4 */ 	sw	$v0,0xa4($sp)
/*  f0c4280:	0c0093ac */ 	jal	cdGetObstacle
/*  f0c4284:	00000000 */ 	nop
/*  f0c4288:	10400131 */ 	beqz	$v0,.L0f0c4750
/*  f0c428c:	afa200a0 */ 	sw	$v0,0xa0($sp)
/*  f0c4290:	3c08800a */ 	lui	$t0,%hi(g_Vars)
/*  f0c4294:	25089fc0 */ 	addiu	$t0,$t0,%lo(g_Vars)
/*  f0c4298:	8d0f0034 */ 	lw	$t7,0x34($t0)
/*  f0c429c:	59e0012d */ 	blezl	$t7,.L0f0c4754
/*  f0c42a0:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*  f0c42a4:	90430000 */ 	lbu	$v1,0x0($v0)
/*  f0c42a8:	24010002 */ 	addiu	$at,$zero,0x2
/*  f0c42ac:	54610046 */ 	bnel	$v1,$at,.L0f0c43c8
/*  f0c42b0:	24010003 */ 	addiu	$at,$zero,0x3
/*  f0c42b4:	8c430004 */ 	lw	$v1,0x4($v0)
/*  f0c42b8:	94780070 */ 	lhu	$t8,0x70($v1)
/*  f0c42bc:	33190400 */ 	andi	$t9,$t8,0x400
/*  f0c42c0:	53200124 */ 	beqzl	$t9,.L0f0c4754
/*  f0c42c4:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*  f0c42c8:	8d090284 */ 	lw	$t1,0x284($t0)
/*  f0c42cc:	27a40084 */ 	addiu	$a0,$sp,0x84
/*  f0c42d0:	27a50078 */ 	addiu	$a1,$sp,0x78
/*  f0c42d4:	8d2a00d8 */ 	lw	$t2,0xd8($t1)
/*  f0c42d8:	240601d1 */ 	addiu	$a2,$zero,0x1d1
/*  f0c42dc:	3c077f1b */ 	lui	$a3,%hi(var7f1ad75c)
/*  f0c42e0:	5540011c */ 	bnezl	$t2,.L0f0c4754
/*  f0c42e4:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*  f0c42e8:	0c009393 */ 	jal	func00024e4c
/*  f0c42ec:	24e7d75c */ 	addiu	$a3,$a3,%lo(var7f1ad75c)
/*  f0c42f0:	c7a40080 */ 	lwc1	$f4,0x80($sp)
/*  f0c42f4:	c7a6008c */ 	lwc1	$f6,0x8c($sp)
/*  f0c42f8:	44801000 */ 	mtc1	$zero,$f2
/*  f0c42fc:	c7a80084 */ 	lwc1	$f8,0x84($sp)
/*  f0c4300:	46062001 */ 	sub.s	$f0,$f4,$f6
/*  f0c4304:	c7aa0078 */ 	lwc1	$f10,0x78($sp)
/*  f0c4308:	3c08800a */ 	lui	$t0,%hi(g_Vars)
/*  f0c430c:	25089fc0 */ 	addiu	$t0,$t0,%lo(g_Vars)
/*  f0c4310:	46001032 */ 	c.eq.s	$f2,$f0
/*  f0c4314:	e7a00090 */ 	swc1	$f0,0x90($sp)
/*  f0c4318:	460a4101 */ 	sub.s	$f4,$f8,$f10
/*  f0c431c:	27a40090 */ 	addiu	$a0,$sp,0x90
/*  f0c4320:	e7a20094 */ 	swc1	$f2,0x94($sp)
/*  f0c4324:	45000004 */ 	bc1f	.L0f0c4338
/*  f0c4328:	e7a40098 */ 	swc1	$f4,0x98($sp)
/*  f0c432c:	46041032 */ 	c.eq.s	$f2,$f4
/*  f0c4330:	3c013f80 */ 	lui	$at,0x3f80
/*  f0c4334:	45010006 */ 	bc1t	.L0f0c4350
.L0f0c4338:
/*  f0c4338:	27a50094 */ 	addiu	$a1,$sp,0x94
/*  f0c433c:	0c0011e4 */ 	jal	guNormalize
/*  f0c4340:	27a60098 */ 	addiu	$a2,$sp,0x98
/*  f0c4344:	3c08800a */ 	lui	$t0,%hi(g_Vars)
/*  f0c4348:	10000004 */ 	b	.L0f0c435c
/*  f0c434c:	25089fc0 */ 	addiu	$t0,$t0,%lo(g_Vars)
.L0f0c4350:
/*  f0c4350:	44813000 */ 	mtc1	$at,$f6
/*  f0c4354:	00000000 */ 	nop
/*  f0c4358:	e7a60098 */ 	swc1	$f6,0x98($sp)
.L0f0c435c:
/*  f0c435c:	8d0b0284 */ 	lw	$t3,0x284($t0)
/*  f0c4360:	3c053ecc */ 	lui	$a1,0x3ecc
/*  f0c4364:	34a5cccd */ 	ori	$a1,$a1,0xcccd
/*  f0c4368:	8d6200bc */ 	lw	$v0,0xbc($t3)
/*  f0c436c:	27a60090 */ 	addiu	$a2,$sp,0x90
/*  f0c4370:	00003825 */ 	or	$a3,$zero,$zero
/*  f0c4374:	8c440004 */ 	lw	$a0,0x4($v0)
/*  f0c4378:	0fc0d05f */ 	jal	chrDamageByLaser
/*  f0c437c:	afa20010 */ 	sw	$v0,0x10($sp)
/*  f0c4380:	3c01bf80 */ 	lui	$at,0xbf80
/*  f0c4384:	44814000 */ 	mtc1	$at,$f8
/*  f0c4388:	3c048009 */ 	lui	$a0,%hi(var80095200)
/*  f0c438c:	240cffff */ 	addiu	$t4,$zero,-1
/*  f0c4390:	240dffff */ 	addiu	$t5,$zero,-1
/*  f0c4394:	240effff */ 	addiu	$t6,$zero,-1
/*  f0c4398:	afae001c */ 	sw	$t6,0x1c($sp)
/*  f0c439c:	afad0018 */ 	sw	$t5,0x18($sp)
/*  f0c43a0:	afac0010 */ 	sw	$t4,0x10($sp)
/*  f0c43a4:	8c845200 */ 	lw	$a0,%lo(var80095200)($a0)
/*  f0c43a8:	240500f2 */ 	addiu	$a1,$zero,0xf2
/*  f0c43ac:	00003025 */ 	or	$a2,$zero,$zero
/*  f0c43b0:	2407ffff */ 	addiu	$a3,$zero,-1
/*  f0c43b4:	0c004241 */ 	jal	sndStart
/*  f0c43b8:	e7a80014 */ 	swc1	$f8,0x14($sp)
/*  f0c43bc:	100000e5 */ 	b	.L0f0c4754
/*  f0c43c0:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*  f0c43c4:	24010003 */ 	addiu	$at,$zero,0x3
.L0f0c43c8:
/*  f0c43c8:	5461008b */ 	bnel	$v1,$at,.L0f0c45f8
/*  f0c43cc:	24010006 */ 	addiu	$at,$zero,0x6
/*  f0c43d0:	8d180318 */ 	lw	$t8,0x318($t0)
/*  f0c43d4:	8c4f0004 */ 	lw	$t7,0x4($v0)
/*  f0c43d8:	00001825 */ 	or	$v1,$zero,$zero
/*  f0c43dc:	1300000c */ 	beqz	$t8,.L0f0c4410
/*  f0c43e0:	afaf0074 */ 	sw	$t7,0x74($sp)
/*  f0c43e4:	8d190284 */ 	lw	$t9,0x284($t0)
/*  f0c43e8:	01e02825 */ 	or	$a1,$t7,$zero
/*  f0c43ec:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f0c43f0:	8f2900bc */ 	lw	$t1,0xbc($t9)
/*  f0c43f4:	8d240004 */ 	lw	$a0,0x4($t1)
/*  f0c43f8:	0fc12aa3 */ 	jal	chrCompareTeams
/*  f0c43fc:	afa00044 */ 	sw	$zero,0x44($sp)
/*  f0c4400:	10400014 */ 	beqz	$v0,.L0f0c4454
/*  f0c4404:	8fa30044 */ 	lw	$v1,0x44($sp)
/*  f0c4408:	10000012 */ 	b	.L0f0c4454
/*  f0c440c:	24030001 */ 	addiu	$v1,$zero,0x1
.L0f0c4410:
/*  f0c4410:	8faa0074 */ 	lw	$t2,0x74($sp)
/*  f0c4414:	8d4b0018 */ 	lw	$t3,0x18($t2)
/*  f0c4418:	000b61c0 */ 	sll	$t4,$t3,0x7
/*  f0c441c:	0581000d */ 	bgez	$t4,.L0f0c4454
/*  f0c4420:	00000000 */ 	nop
/*  f0c4424:	8d0d029c */ 	lw	$t5,0x29c($t0)
/*  f0c4428:	05a2000a */ 	bltzl	$t5,.L0f0c4454
/*  f0c442c:	24030001 */ 	addiu	$v1,$zero,0x1
/*  f0c4430:	8d0e02a8 */ 	lw	$t6,0x2a8($t0)
/*  f0c4434:	8d0f0284 */ 	lw	$t7,0x284($t0)
/*  f0c4438:	55cf0006 */ 	bnel	$t6,$t7,.L0f0c4454
/*  f0c443c:	24030001 */ 	addiu	$v1,$zero,0x1
/*  f0c4440:	8d580014 */ 	lw	$t8,0x14($t2)
/*  f0c4444:	0018c840 */ 	sll	$t9,$t8,0x1
/*  f0c4448:	07200002 */ 	bltz	$t9,.L0f0c4454
/*  f0c444c:	00000000 */ 	nop
/*  f0c4450:	24030001 */ 	addiu	$v1,$zero,0x1
.L0f0c4454:
/*  f0c4454:	106000be */ 	beqz	$v1,.L0f0c4750
/*  f0c4458:	8fa200a8 */ 	lw	$v0,0xa8($sp)
/*  f0c445c:	c4400008 */ 	lwc1	$f0,0x8($v0)
/*  f0c4460:	c4420000 */ 	lwc1	$f2,0x0($v0)
/*  f0c4464:	46000282 */ 	mul.s	$f10,$f0,$f0
/*  f0c4468:	00000000 */ 	nop
/*  f0c446c:	46021102 */ 	mul.s	$f4,$f2,$f2
/*  f0c4470:	0c012974 */ 	jal	sqrtf
/*  f0c4474:	46045300 */ 	add.s	$f12,$f10,$f4
/*  f0c4478:	3c08800a */ 	lui	$t0,%hi(g_Vars)
/*  f0c447c:	25089fc0 */ 	addiu	$t0,$t0,%lo(g_Vars)
/*  f0c4480:	c5060044 */ 	lwc1	$f6,0x44($t0)
/*  f0c4484:	8d090284 */ 	lw	$t1,0x284($t0)
/*  f0c4488:	8fa300a0 */ 	lw	$v1,0xa0($sp)
/*  f0c448c:	46060203 */ 	div.s	$f8,$f0,$f6
/*  f0c4490:	44801000 */ 	mtc1	$zero,$f2
/*  f0c4494:	e7a80054 */ 	swc1	$f8,0x54($sp)
/*  f0c4498:	8d2200bc */ 	lw	$v0,0xbc($t1)
/*  f0c449c:	c46a0008 */ 	lwc1	$f10,0x8($v1)
/*  f0c44a0:	c4660010 */ 	lwc1	$f6,0x10($v1)
/*  f0c44a4:	c4440008 */ 	lwc1	$f4,0x8($v0)
/*  f0c44a8:	c4480010 */ 	lwc1	$f8,0x10($v0)
/*  f0c44ac:	46045381 */ 	sub.s	$f14,$f10,$f4
/*  f0c44b0:	46083401 */ 	sub.s	$f16,$f6,$f8
/*  f0c44b4:	46027032 */ 	c.eq.s	$f14,$f2
/*  f0c44b8:	00000000 */ 	nop
/*  f0c44bc:	45000005 */ 	bc1f	.L0f0c44d4
/*  f0c44c0:	00000000 */ 	nop
/*  f0c44c4:	46028032 */ 	c.eq.s	$f16,$f2
/*  f0c44c8:	00000000 */ 	nop
/*  f0c44cc:	450300a1 */ 	bc1tl	.L0f0c4754
/*  f0c44d0:	8fbf0024 */ 	lw	$ra,0x24($sp)
.L0f0c44d4:
/*  f0c44d4:	460e7282 */ 	mul.s	$f10,$f14,$f14
/*  f0c44d8:	e7ae0050 */ 	swc1	$f14,0x50($sp)
/*  f0c44dc:	e7b0004c */ 	swc1	$f16,0x4c($sp)
/*  f0c44e0:	46108102 */ 	mul.s	$f4,$f16,$f16
/*  f0c44e4:	0c012974 */ 	jal	sqrtf
/*  f0c44e8:	46045300 */ 	add.s	$f12,$f10,$f4
/*  f0c44ec:	44801000 */ 	mtc1	$zero,$f2
/*  f0c44f0:	3c08800a */ 	lui	$t0,%hi(g_Vars)
/*  f0c44f4:	25089fc0 */ 	addiu	$t0,$t0,%lo(g_Vars)
/*  f0c44f8:	4600103c */ 	c.lt.s	$f2,$f0
/*  f0c44fc:	c7ae0050 */ 	lwc1	$f14,0x50($sp)
/*  f0c4500:	c7b0004c */ 	lwc1	$f16,0x4c($sp)
/*  f0c4504:	c7a60054 */ 	lwc1	$f6,0x54($sp)
/*  f0c4508:	45020092 */ 	bc1fl	.L0f0c4754
/*  f0c450c:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*  f0c4510:	46003303 */ 	div.s	$f12,$f6,$f0
/*  f0c4514:	3c013f00 */ 	lui	$at,0x3f00
/*  f0c4518:	44819000 */ 	mtc1	$at,$f18
/*  f0c451c:	8fa40074 */ 	lw	$a0,0x74($sp)
/*  f0c4520:	8fa200a0 */ 	lw	$v0,0xa0($sp)
/*  f0c4524:	27a50068 */ 	addiu	$a1,$sp,0x68
/*  f0c4528:	27a60058 */ 	addiu	$a2,$sp,0x58
/*  f0c452c:	00003825 */ 	or	$a3,$zero,$zero
/*  f0c4530:	460c7382 */ 	mul.s	$f14,$f14,$f12
/*  f0c4534:	00000000 */ 	nop
/*  f0c4538:	460c8402 */ 	mul.s	$f16,$f16,$f12
/*  f0c453c:	00000000 */ 	nop
/*  f0c4540:	460e9082 */ 	mul.s	$f2,$f18,$f14
/*  f0c4544:	00000000 */ 	nop
/*  f0c4548:	46109202 */ 	mul.s	$f8,$f18,$f16
/*  f0c454c:	e4820304 */ 	swc1	$f2,0x304($a0)
/*  f0c4550:	e4880308 */ 	swc1	$f8,0x308($a0)
/*  f0c4554:	c5000044 */ 	lwc1	$f0,0x44($t0)
/*  f0c4558:	c4440008 */ 	lwc1	$f4,0x8($v0)
/*  f0c455c:	46001282 */ 	mul.s	$f10,$f2,$f0
/*  f0c4560:	46045180 */ 	add.s	$f6,$f10,$f4
/*  f0c4564:	e7a60068 */ 	swc1	$f6,0x68($sp)
/*  f0c4568:	c448000c */ 	lwc1	$f8,0xc($v0)
/*  f0c456c:	e7a8006c */ 	swc1	$f8,0x6c($sp)
/*  f0c4570:	c48a0308 */ 	lwc1	$f10,0x308($a0)
/*  f0c4574:	c4460010 */ 	lwc1	$f6,0x10($v0)
/*  f0c4578:	46005102 */ 	mul.s	$f4,$f10,$f0
/*  f0c457c:	46062200 */ 	add.s	$f8,$f4,$f6
/*  f0c4580:	0fc079fd */ 	jal	chrCalculatePushPos
/*  f0c4584:	e7a80070 */ 	swc1	$f8,0x70($sp)
/*  f0c4588:	8fa400a0 */ 	lw	$a0,0xa0($sp)
/*  f0c458c:	c7aa0068 */ 	lwc1	$f10,0x68($sp)
/*  f0c4590:	e48a0008 */ 	swc1	$f10,0x8($a0)
/*  f0c4594:	c7a4006c */ 	lwc1	$f4,0x6c($sp)
/*  f0c4598:	e484000c */ 	swc1	$f4,0xc($a0)
/*  f0c459c:	c7a60070 */ 	lwc1	$f6,0x70($sp)
/*  f0c45a0:	0fc19711 */ 	jal	func0f065c44
/*  f0c45a4:	e4860010 */ 	swc1	$f6,0x10($a0)
/*  f0c45a8:	8fa500a0 */ 	lw	$a1,0xa0($sp)
/*  f0c45ac:	27a40058 */ 	addiu	$a0,$sp,0x58
/*  f0c45b0:	0fc195e9 */ 	jal	roomsCopy
/*  f0c45b4:	24a50028 */ 	addiu	$a1,$a1,0x28
/*  f0c45b8:	0fc0882b */ 	jal	func0f0220ac
/*  f0c45bc:	8fa40074 */ 	lw	$a0,0x74($sp)
/*  f0c45c0:	8fab0074 */ 	lw	$t3,0x74($sp)
/*  f0c45c4:	27a50068 */ 	addiu	$a1,$sp,0x68
/*  f0c45c8:	0c006b4d */ 	jal	modelSetRootPosition
/*  f0c45cc:	8d640020 */ 	lw	$a0,0x20($t3)
/*  f0c45d0:	8fac00b8 */ 	lw	$t4,0xb8($sp)
/*  f0c45d4:	8fa400a8 */ 	lw	$a0,0xa8($sp)
/*  f0c45d8:	8fa500ac */ 	lw	$a1,0xac($sp)
/*  f0c45dc:	8fa600b0 */ 	lw	$a2,0xb0($sp)
/*  f0c45e0:	8fa700b4 */ 	lw	$a3,0xb4($sp)
/*  f0c45e4:	0fc30f85 */ 	jal	bwalkCalculateNewPosition
/*  f0c45e8:	afac0010 */ 	sw	$t4,0x10($sp)
/*  f0c45ec:	10000058 */ 	b	.L0f0c4750
/*  f0c45f0:	afa200a4 */ 	sw	$v0,0xa4($sp)
/*  f0c45f4:	24010006 */ 	addiu	$at,$zero,0x6
.L0f0c45f8:
/*  f0c45f8:	10610055 */ 	beq	$v1,$at,.L0f0c4750
/*  f0c45fc:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0c4600:	54610054 */ 	bnel	$v1,$at,.L0f0c4754
/*  f0c4604:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*  f0c4608:	8c460004 */ 	lw	$a2,0x4($v0)
/*  f0c460c:	8cc30040 */ 	lw	$v1,0x40($a2)
/*  f0c4610:	00036940 */ 	sll	$t5,$v1,0x5
/*  f0c4614:	05a0004e */ 	bltz	$t5,.L0f0c4750
/*  f0c4618:	00037100 */ 	sll	$t6,$v1,0x4
/*  f0c461c:	05c2004d */ 	bltzl	$t6,.L0f0c4754
/*  f0c4620:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*  f0c4624:	8d030284 */ 	lw	$v1,0x284($t0)
/*  f0c4628:	8c6f1af0 */ 	lw	$t7,0x1af0($v1)
/*  f0c462c:	55e00008 */ 	bnezl	$t7,.L0f0c4650
/*  f0c4630:	8cd80010 */ 	lw	$t8,0x10($a2)
/*  f0c4634:	90ca0003 */ 	lbu	$t2,0x3($a2)
/*  f0c4638:	2401002d */ 	addiu	$at,$zero,0x2d
/*  f0c463c:	55410004 */ 	bnel	$t2,$at,.L0f0c4650
/*  f0c4640:	8cd80010 */ 	lw	$t8,0x10($a2)
/*  f0c4644:	10000042 */ 	b	.L0f0c4750
/*  f0c4648:	ac621aec */ 	sw	$v0,0x1aec($v1)
/*  f0c464c:	8cd80010 */ 	lw	$t8,0x10($a2)
.L0f0c4650:
/*  f0c4650:	33190001 */ 	andi	$t9,$t8,0x1
/*  f0c4654:	5320003f */ 	beqzl	$t9,.L0f0c4754
/*  f0c4658:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*  f0c465c:	ac600178 */ 	sw	$zero,0x178($v1)
/*  f0c4660:	8cc90040 */ 	lw	$t1,0x40($a2)
/*  f0c4664:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f0c4668:	8fa400a8 */ 	lw	$a0,0xa8($sp)
/*  f0c466c:	312b0080 */ 	andi	$t3,$t1,0x80
/*  f0c4670:	11600007 */ 	beqz	$t3,.L0f0c4690
/*  f0c4674:	00c02825 */ 	or	$a1,$a2,$zero
/*  f0c4678:	8ccc0048 */ 	lw	$t4,0x48($a2)
/*  f0c467c:	8d8d0000 */ 	lw	$t5,0x0($t4)
/*  f0c4680:	31ae1000 */ 	andi	$t6,$t5,0x1000
/*  f0c4684:	11c00002 */ 	beqz	$t6,.L0f0c4690
/*  f0c4688:	00000000 */ 	nop
/*  f0c468c:	00001025 */ 	or	$v0,$zero,$zero
.L0f0c4690:
/*  f0c4690:	50400030 */ 	beqzl	$v0,.L0f0c4754
/*  f0c4694:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*  f0c4698:	0fc30ece */ 	jal	bwalk0f0c3b38
/*  f0c469c:	afa60040 */ 	sw	$a2,0x40($sp)
/*  f0c46a0:	8fa60040 */ 	lw	$a2,0x40($sp)
/*  f0c46a4:	8ccf0040 */ 	lw	$t7,0x40($a2)
/*  f0c46a8:	31ea0080 */ 	andi	$t2,$t7,0x80
/*  f0c46ac:	51400029 */ 	beqzl	$t2,.L0f0c4754
/*  f0c46b0:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*  f0c46b4:	8cd80048 */ 	lw	$t8,0x48($a2)
/*  f0c46b8:	00c02025 */ 	or	$a0,$a2,$zero
/*  f0c46bc:	27a50034 */ 	addiu	$a1,$sp,0x34
/*  f0c46c0:	8f190000 */ 	lw	$t9,0x0($t8)
/*  f0c46c4:	33290800 */ 	andi	$t1,$t9,0x800
/*  f0c46c8:	51200022 */ 	beqzl	$t1,.L0f0c4754
/*  f0c46cc:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*  f0c46d0:	afa00034 */ 	sw	$zero,0x34($sp)
/*  f0c46d4:	0fc1cf1b */ 	jal	func0f073c6c
/*  f0c46d8:	afa60040 */ 	sw	$a2,0x40($sp)
/*  f0c46dc:	8fa60040 */ 	lw	$a2,0x40($sp)
/*  f0c46e0:	8ccb0040 */ 	lw	$t3,0x40($a2)
/*  f0c46e4:	316c0080 */ 	andi	$t4,$t3,0x80
/*  f0c46e8:	11800010 */ 	beqz	$t4,.L0f0c472c
/*  f0c46ec:	00000000 */ 	nop
/*  f0c46f0:	8cc30048 */ 	lw	$v1,0x48($a2)
/*  f0c46f4:	8c6d0000 */ 	lw	$t5,0x0($v1)
/*  f0c46f8:	35ae1000 */ 	ori	$t6,$t5,0x1000
/*  f0c46fc:	10400006 */ 	beqz	$v0,.L0f0c4718
/*  f0c4700:	ac6e0000 */ 	sw	$t6,0x0($v1)
/*  f0c4704:	8cc30048 */ 	lw	$v1,0x48($a2)
/*  f0c4708:	8c6f0000 */ 	lw	$t7,0x0($v1)
/*  f0c470c:	35ea2000 */ 	ori	$t2,$t7,0x2000
/*  f0c4710:	10000006 */ 	b	.L0f0c472c
/*  f0c4714:	ac6a0000 */ 	sw	$t2,0x0($v1)
.L0f0c4718:
/*  f0c4718:	8cc30048 */ 	lw	$v1,0x48($a2)
/*  f0c471c:	2401dfff */ 	addiu	$at,$zero,-8193
/*  f0c4720:	8c780000 */ 	lw	$t8,0x0($v1)
/*  f0c4724:	0301c824 */ 	and	$t9,$t8,$at
/*  f0c4728:	ac790000 */ 	sw	$t9,0x0($v1)
.L0f0c472c:
/*  f0c472c:	10400008 */ 	beqz	$v0,.L0f0c4750
/*  f0c4730:	8fa400a8 */ 	lw	$a0,0xa8($sp)
/*  f0c4734:	8fa900b8 */ 	lw	$t1,0xb8($sp)
/*  f0c4738:	8fa500ac */ 	lw	$a1,0xac($sp)
/*  f0c473c:	8fa600b0 */ 	lw	$a2,0xb0($sp)
/*  f0c4740:	8fa700b4 */ 	lw	$a3,0xb4($sp)
/*  f0c4744:	0fc30f85 */ 	jal	bwalkCalculateNewPosition
/*  f0c4748:	afa90010 */ 	sw	$t1,0x10($sp)
/*  f0c474c:	afa200a4 */ 	sw	$v0,0xa4($sp)
.L0f0c4750:
/*  f0c4750:	8fbf0024 */ 	lw	$ra,0x24($sp)
.L0f0c4754:
/*  f0c4754:	8fa200a4 */ 	lw	$v0,0xa4($sp)
/*  f0c4758:	27bd00a8 */ 	addiu	$sp,$sp,0xa8
/*  f0c475c:	03e00008 */ 	jr	$ra
/*  f0c4760:	00000000 */ 	nop
);
#endif

// Mismatch: The below loads 0.5f twice in the chr push code while goal reuses it.
//bool bwalkCalculateNewPositionWithPush(struct coord *delta, f32 rotateamount, bool apply, f32 extrawidth, s32 types)
//{
//	s32 result = bwalkCalculateNewPosition(delta, rotateamount, apply, extrawidth, types);
//
//	if (result != CDRESULT_NOCOLLISION) {
//		struct prop *obstacle = cdGetObstacle();
//
//		if (obstacle && g_Vars.lvupdate240 > 0) {
//			if (obstacle->type == PROPTYPE_DOOR) {
//				struct doorobj *door = obstacle->door;
//				struct coord sp90;
//				struct coord sp84;
//				struct coord sp78;
//
//				if (door->doorflags & DOORFLAG_DAMAGEONCONTACT) {
//					if (!g_Vars.currentplayer->isdead) {
//						func00024e4c(&sp84, &sp78, 465, "bondwalk.c");
//
//						sp90.x = sp78.f[2] - sp84.f[2];
//						sp90.y = 0;
//						sp90.z = sp84.f[0] - sp78.f[0];
//
//						if (sp90.f[0] || sp90.f[2]) {
//							guNormalize(&sp90.x, &sp90.y, &sp90.z);
//						} else {
//							sp90.z = 1;
//						}
//
//						chrDamageByLaser(g_Vars.currentplayer->prop->chr, 0.4f, &sp90, 0, g_Vars.currentplayer->prop);
//
//						// Laser zap sound
//						sndStart(var80095200, SFX_PICKUP_LASER, 0, -1, -1, -1, -1, -1);
//					}
//				}
//			} else if (obstacle->type == PROPTYPE_CHR) {
//				struct chrdata *chr = obstacle->chr;
//				struct coord newpos;
//				s16 newrooms[8];
//				f32 movingdist;
//				f32 xdist;
//				f32 zdist;
//				f32 disttochr;
//				bool canpush = false;
//
//				if (g_Vars.normmplayerisrunning) {
//					if (chrCompareTeams(g_Vars.currentplayer->prop->chr, chr, COMPARE_FRIENDS)) {
//						// AI bot on same team
//						canpush = true;
//					}
//				} else if (chr->chrflags & CHRCFLAG_PUSHABLE) {
//					if (g_Vars.antiplayernum < 0
//							|| g_Vars.currentplayer != g_Vars.anti
//							|| (chr->hidden & CHRHFLAG_ANTINONINTERACTABLE) == 0) {
//						canpush = true;
//					}
//				}
//
//				if (canpush) {
//					movingdist = sqrtf(delta->f[0] * delta->f[0] + delta->f[2] * delta->f[2]) / g_Vars.lvupdate240f;
//
//					xdist = obstacle->pos.x - g_Vars.currentplayer->prop->pos.x;
//					zdist = obstacle->pos.z - g_Vars.currentplayer->prop->pos.z;
//
//					if (xdist || zdist) {
//						disttochr = sqrtf(xdist * xdist + zdist * zdist);
//
//						if (disttochr > 0) {
//							xdist *= (movingdist / disttochr);
//							zdist *= (movingdist / disttochr);
//
//							chr->pushspeed[0] = 0.5f * xdist;
//							chr->pushspeed[1] = 0.5f * zdist;
//
//							newpos.x = obstacle->pos.x + chr->pushspeed[0] * g_Vars.lvupdate240f;
//							newpos.y = obstacle->pos.y;
//							newpos.z = obstacle->pos.z + chr->pushspeed[1] * g_Vars.lvupdate240f;
//
//							chrCalculatePushPos(chr, &newpos, newrooms, false);
//
//							obstacle->pos.x = newpos.x;
//							obstacle->pos.y = newpos.y;
//							obstacle->pos.z = newpos.z;
//
//							func0f065c44(obstacle);
//							roomsCopy(newrooms, obstacle->rooms);
//							func0f0220ac(chr);
//							modelSetRootPosition(chr->model, &newpos);
//
//							result = bwalkCalculateNewPosition(delta, rotateamount, apply, extrawidth, types);
//						}
//					}
//				}
//			} else if (obstacle->type == PROPTYPE_PLAYER) {
//				// empty
//			} else if (obstacle->type == PROPTYPE_OBJ) {
//				struct defaultobj *obj = obstacle->obj;
//				bool dothething;
//
//				if ((obj->hidden & OBJHFLAG_MOUNTED) == 0 && (obj->hidden & OBJHFLAG_GRABBED) == 0) {
//					if (g_Vars.currentplayer->unk1af0 == 0 && obj->type == OBJTYPE_TANK) {
//						g_Vars.currentplayer->tank = obstacle;
//					} else if (obj->flags3 & OBJFLAG3_PUSHABLE) {
//						g_Vars.currentplayer->speedmaxtime60 = 0;
//						dothething = true;
//
//						if ((obj->hidden & OBJHFLAG_AIRBORNE) &&
//								(obj->projectile->flags & PROJECTILEFLAG_00001000)) {
//							dothething = false;
//						}
//
//						if (dothething) {
//							bwalk0f0c3b38(delta, obj);
//
//							if (obj->hidden & OBJHFLAG_AIRBORNE && (obj->projectile->flags & PROJECTILEFLAG_00000800)) {
//								bool somevalue;
//								bool somebool = false;
//								somevalue = func0f073c6c(obj, &somebool);
//
//								if (obj->hidden & OBJHFLAG_AIRBORNE) {
//									obj->projectile->flags |= PROJECTILEFLAG_00001000;
//
//									if (somevalue) {
//										obj->projectile->flags |= PROJECTILEFLAG_00002000;
//									} else {
//										obj->projectile->flags &= ~PROJECTILEFLAG_00002000;
//									}
//								}
//
//								if (somevalue) {
//									result = bwalkCalculateNewPosition(delta, rotateamount, apply, extrawidth, types);
//								}
//							}
//						}
//					}
//				}
//			}
//		}
//	}
//
//	return result;
//}

s32 bwalk0f0c4764(struct coord *delta, struct coord *arg1, struct coord *arg2, s32 types)
{
	s32 result = bwalkCalculateNewPositionWithPush(delta, 0, true, 0, types);

	if (result == CDRESULT_COLLISION) {
		func00024e4c(arg1, arg2, 0x25f, "bondwalk.c");
	}

	return result;
}

s32 bwalk0f0c47d0(struct coord *a, struct coord *b, struct coord *c,
		struct coord *d, struct coord *e, s32 types)
{
	struct coord quarter;
	bool result;

	if (func00024ea4()) {
		f32 mult = func00024e98();
		quarter.x = a->x * mult * 0.25f;
		quarter.y = a->y * mult * 0.25f;
		quarter.z = a->z * mult * 0.25f;
		result = bwalkCalculateNewPositionWithPush(&quarter, 0, true, 0, types);

		if (result == CDRESULT_NOCOLLISION) {
			return CDRESULT_NOCOLLISION;
		}

		if (result == CDRESULT_COLLISION) {
			func00024e4c(d, e, 0x27b, "bondwalk.c");

			if (b->x != d->x
					|| b->y != d->y
					|| b->z != d->z
					|| c->x != e->x
					|| c->y != e->y
					|| c->z != e->z) {
				return CDRESULT_COLLISION;
			}
		}
	}

	return CDRESULT_ERROR;
}

s32 bwalk0f0c494c(struct coord *a, struct coord *b, struct coord *c, s32 types)
{
	if (b->f[0] != c->f[0] || b->f[2] != c->f[2]) {
		f32 tmp;
		struct coord sp38;
		struct coord sp2c;

		sp38.x = c->x - b->x;
		sp38.y = 0;
		sp38.z = c->z - b->z;

		tmp = sqrtf(sp38.f[0] * sp38.f[0] + sp38.f[2] * sp38.f[2]);

		sp38.x *= 1.0f / tmp;
		sp38.z *= 1.0f / tmp;

		tmp = a->f[0] * sp38.f[0] + a->f[2] * sp38.f[2];

		sp2c.x = sp38.x * tmp;
		sp2c.y = 0;
		sp2c.z = sp38.z * tmp;

		return bwalkCalculateNewPositionWithPush(&sp2c, 0, true, 0, types);
	}

	return -1;
}

s32 bwalk0f0c4a5c(struct coord *arg0, struct coord *arg1, struct coord *arg2, s32 types)
{
	struct coord sp34;
	struct coord sp28;
	f32 ymax;
	f32 ymin;
	f32 tmp;
	f32 width;

	propPlayerGetBbox(g_Vars.currentplayer->prop, &width, &ymax, &ymin);

	sp34.x = arg1->x - (g_Vars.currentplayer->prop->pos.x + arg0->f[0]);
	sp34.z = arg1->z - (g_Vars.currentplayer->prop->pos.z + arg0->f[2]);

	if (sp34.f[0] * sp34.f[0] + sp34.f[2] * sp34.f[2] <= width * width) {
		if (arg1->f[0] != g_Vars.currentplayer->prop->pos.f[0] || arg1->f[2] != g_Vars.currentplayer->prop->pos.f[2]) {
			sp34.x = -(arg1->z - g_Vars.currentplayer->prop->pos.z);
			sp34.y = 0;
			sp34.z = arg1->x - g_Vars.currentplayer->prop->pos.x;

			tmp = sqrtf(sp34.f[0] * sp34.f[0] + sp34.f[2] * sp34.f[2]);

			sp34.x = sp34.f[0] * (1.0f / tmp);
			sp34.z = sp34.f[2] * (1.0f / tmp);

			tmp = arg0->f[0] * sp34.f[0] + arg0->f[2] * sp34.f[2];

			sp34.x = sp34.x * tmp;
			sp34.z = sp34.z * tmp;

			sp28.x = sp34.x;
			sp28.y = 0;
			sp28.z = sp34.z;

			if (bwalkCalculateNewPositionWithPush(&sp28, 0, true, 0, types) == CDRESULT_NOCOLLISION) {
				return true;
			}
		}
	} else {
		sp34.x = arg2->x - (g_Vars.currentplayer->prop->pos.x + arg0->f[0]);
		sp34.z = arg2->z - (g_Vars.currentplayer->prop->pos.z + arg0->f[2]);

		if (sp34.f[0] * sp34.f[0] + sp34.f[2] * sp34.f[2] <= width * width) {
			if (arg2->f[0] != g_Vars.currentplayer->prop->pos.f[0] || arg2->f[2] != g_Vars.currentplayer->prop->pos.f[2]) {
				sp34.x = -(arg2->z - g_Vars.currentplayer->prop->pos.z);
				sp34.y = 0;
				sp34.z = arg2->x - g_Vars.currentplayer->prop->pos.x;

				tmp = sqrtf(sp34.f[0] * sp34.f[0] + sp34.f[2] * sp34.f[2]);

				sp34.x = sp34.f[0] * (1.0f / tmp);
				sp34.z = sp34.f[2] * (1.0f / tmp);

				tmp = arg0->f[0] * sp34.f[0] + arg0->f[2] * sp34.f[2];

				sp34.x = sp34.x * tmp;
				sp34.z = sp34.z * tmp;

				sp28.x = sp34.x;
				sp28.y = 0;
				sp28.z = sp34.z;

				if (bwalkCalculateNewPositionWithPush(&sp28, 0, true, 0, types) == CDRESULT_NOCOLLISION) {
					return true;
				}
			}
		}
	}

	return false;
}

void bwalk0f0c4d98(void)
{
	// empty
}

void bwalkUpdateSpeedSideways(f32 targetspeed, f32 accelspeed, s32 mult)
{
	if (g_Vars.normmplayerisrunning) {
		targetspeed = (g_MpPlayers[g_Vars.currentplayerstats->mpindex].base.unk1c + 25.0f) / 100 * targetspeed;
	}

	if (g_Vars.currentplayer->speedstrafe > targetspeed) {
		g_Vars.currentplayer->speedstrafe -= PALUPF(accelspeed * mult);

		if (g_Vars.currentplayer->speedstrafe < targetspeed) {
			g_Vars.currentplayer->speedstrafe = targetspeed;
		}
	} else if (g_Vars.currentplayer->speedstrafe < targetspeed) {
		g_Vars.currentplayer->speedstrafe += PALUPF(accelspeed * mult);

		if (g_Vars.currentplayer->speedstrafe > targetspeed) {
			g_Vars.currentplayer->speedstrafe = targetspeed;
		}
	}

	g_Vars.currentplayer->speedsideways = g_Vars.currentplayer->speedstrafe;
}

void bwalkUpdateSpeedForwards(f32 targetspeed, f32 accelspeed)
{
	if (g_Vars.normmplayerisrunning) {
		targetspeed = (g_MpPlayers[g_Vars.currentplayerstats->mpindex].base.unk1c + 25.0f) / 100 * targetspeed;
	}

	if (g_Vars.currentplayer->speedgo < targetspeed) {
		g_Vars.currentplayer->speedgo += accelspeed * g_Vars.lvupdate240freal;

		if (g_Vars.currentplayer->speedgo > targetspeed) {
			g_Vars.currentplayer->speedgo = targetspeed;
		}
	} else if (g_Vars.currentplayer->speedgo > targetspeed) {
		g_Vars.currentplayer->speedgo -= accelspeed * g_Vars.lvupdate240freal;

		if (g_Vars.currentplayer->speedgo < targetspeed) {
			g_Vars.currentplayer->speedgo = targetspeed;
		}
	}

	g_Vars.currentplayer->speedforwards = g_Vars.currentplayer->speedgo;
}

#if VERSION >= VERSION_NTSC_1_0
void bwalkUpdateVertical(void)
{
	s32 i;
	struct defaultobj *obj;
	f32 width;
	f32 ymax;
	f32 ymin;
	f32 ground;
	bool onladder;
	bool onladder2 = false;
	s16 rooms[8];
	struct coord testpos;
	struct coord newpos;
	s16 newrooms[8];
	s32 newinlift;
	struct prop *lift = NULL;
	f32 sumground;
	f32 moveamount;
	f32 clearance;
	f32 limit;
	f32 amount;
	f32 newmanground;
	f32 fallspeed;
	f32 multiplier;
	f32 newfallspeed;
	struct prop *prop;

	propPlayerGetBbox(g_Vars.currentplayer->prop, &width, &ymax, &ymin);

	// Maybe reset counter-op's width - not sure why
	// Maybe it gets set to 0 when they die?
	if (g_Vars.antiplayernum >= 0
			&& g_Vars.currentplayer == g_Vars.anti
			&& g_Vars.currentplayer->bond2.width != 30
			&& cdTestVolume(&g_Vars.currentplayer->prop->pos, 30, g_Vars.currentplayer->prop->rooms, CDTYPE_ALL, 1, ymax - g_Vars.currentplayer->prop->pos.y, ymin - g_Vars.currentplayer->prop->pos.y)) {
		g_Vars.currentplayer->prop->chr->chrwidth = 30;
		g_Vars.currentplayer->bond2.width = 30;
		width = 30;
	}

	// Determine if player is on a ladder
	// If this comes up false, a second check is done... maybe checking if the
	// player is touching a ladder from a room which shares the same coordinate
	// space?
	onladder = func00029ffc(&g_Vars.currentplayer->prop->pos,
			width * 1.2f, ymax - g_Vars.currentplayer->prop->pos.y,
			g_Vars.currentplayer->vv_manground - g_Vars.currentplayer->prop->pos.y + 1,
			g_Vars.currentplayer->prop->rooms, 0x8040, &g_Vars.currentplayer->laddernormal);

	if (!onladder) {
		testpos.x = g_Vars.currentplayer->prop->pos.x;
		testpos.y = g_Vars.currentplayer->prop->pos.y - 10;
		testpos.z = g_Vars.currentplayer->prop->pos.z;
		roomsCopy(g_Vars.currentplayer->prop->rooms, rooms);
		bmove0f0cb79c(g_Vars.currentplayer, &testpos, rooms);
		onladder2 = func00029ffc(&g_Vars.currentplayer->prop->pos,
				width * 1.1f, ymax - g_Vars.currentplayer->prop->pos.y,
				g_Vars.currentplayer->vv_manground - g_Vars.currentplayer->prop->pos.y - 10,
				rooms, 0x8040, &g_Vars.currentplayer->laddernormal);
	}

	testpos.x = g_Vars.currentplayer->prop->pos.x;
	testpos.y = g_Vars.currentplayer->prop->pos.y;
	testpos.z = g_Vars.currentplayer->prop->pos.z;

	if (g_Vars.currentplayer->inlift) {
		testpos.y -= g_Vars.currentplayer->crouchheight + g_Vars.currentplayer->crouchoffsetrealsmall;
	}

	roomsCopy(g_Vars.currentplayer->prop->rooms, rooms);
	bmove0f0cb79c(g_Vars.currentplayer, &testpos, rooms);
	ground = cdFindGroundY(&testpos, g_Vars.currentplayer->bond2.width, rooms,
			&g_Vars.currentplayer->floorcol, &g_Vars.currentplayer->floortype,
			&g_Vars.currentplayer->floorflags, &g_Vars.currentplayer->floorroom,
			&newinlift, &lift);
	ground += g_Vars.currentplayer->bondonground;

	if (ground < -30000) {
		ground = -30000;
	}

	if (g_Vars.currentplayer->inlift && newinlift == false) {
		// Exiting a lift
		piracyRestore();
	}

	if (g_Vars.currentplayer->inlift && newinlift && g_Vars.currentplayer->onladder == false) {
		// Remaining in a lift
		moveamount = ground - g_Vars.currentplayer->vv_ground;

		if (moveamount != 0) {
			// The lift is moving
			if (g_Vars.currentplayer->isfalling == false && lift == g_Vars.currentplayer->lift) {
				clearance = g_Vars.currentplayer->liftground - g_Vars.currentplayer->vv_manground;

				if (clearance < 1.0f && clearance > -1.0f) {
					// It's actually moving, and not a floating point precision issue
					g_Vars.currentplayer->vv_ground += moveamount;

					if (moveamount > 0
							|| lift == NULL
							|| lift->obj == NULL
							|| (lift->obj->flags & OBJFLAG_CHOPPER_INACTIVE) == 0
							|| bwalkTryMoveUpwards(moveamount) == CDRESULT_NOCOLLISION) {
						// Going up
						g_Vars.currentplayer->vv_manground += moveamount;
						g_Vars.currentplayer->sumground = g_Vars.currentplayer->vv_manground / (PAL ? 0.054400026798248f : 0.045499980449677f);
					}
				}
			}

			if (g_Vars.currentplayer->walkinitmove) {
				g_Vars.currentplayer->walkinitstart.y += moveamount;
			}
		}
	} else {
		lift = NULL;
	}

	g_Vars.currentplayer->inlift = newinlift;

	if (newinlift) {
		g_Vars.currentplayer->liftground = ground;
	}

	g_Vars.currentplayer->lift = lift;

	// Ladders
	if (g_Vars.currentplayer->onladder) {
		if (g_Vars.currentplayer->ladderupdown >= 0 ||
				(ground <= g_Vars.currentplayer->vv_manground &&
				 ground <= g_Vars.currentplayer->vv_manground + g_Vars.currentplayer->ladderupdown)) {
			// Still on ladder
			if (bwalkTryMoveUpwards(g_Vars.currentplayer->ladderupdown) == CDRESULT_NOCOLLISION) {
				g_Vars.currentplayer->vv_manground += g_Vars.currentplayer->ladderupdown;
			}
		} else {
			if (bwalkTryMoveUpwards(ground - g_Vars.currentplayer->vv_manground) == CDRESULT_NOCOLLISION) {
				g_Vars.currentplayer->vv_manground = ground;
				onladder = false;
			}
		}
	}

	g_Vars.currentplayer->onladder = onladder;

	if (g_Vars.currentplayer->onladder) {
		g_Vars.currentplayer->vv_ground = g_Vars.currentplayer->vv_manground;
	} else if (onladder2 == false) {
		g_Vars.currentplayer->vv_ground = ground;
	}

	// Standing on flat ground, or going up stairs, ledges or ramps
	// In other words, not falling
	if (g_Vars.currentplayer->bdeltapos.y >= 0.0f
			|| g_Vars.currentplayer->vv_ground > g_Vars.currentplayer->vv_manground) {
		g_Vars.currentplayer->sumground = g_Vars.currentplayer->vv_manground / (PAL ? 0.054400026798248f : 0.045499980449677f);

		for (i = 0; i < g_Vars.lvupdate240; i++) {
			g_Vars.currentplayer->sumground =
				g_Vars.currentplayer->sumground * (PAL ? 0.94559997320175f : 0.9545f) + g_Vars.currentplayer->vv_ground;
		}

		if (g_Vars.currentplayer->vv_manground < g_Vars.currentplayer->vv_ground) {
			// Feet are lower than the ground
			sumground = g_Vars.currentplayer->sumground * (PAL ? 0.054400026798248f : 0.045499980449677f);
			limit = g_Vars.currentplayer->vv_ground - 50;

			if (sumground < limit) {
				sumground = limit;
			}

			if (bwalkTryMoveUpwards(sumground - g_Vars.currentplayer->vv_manground) == CDRESULT_NOCOLLISION) {
				g_Vars.currentplayer->vv_manground = sumground;
			} else {
				// Not enough room above. If on a hoverbike, blow it up
				prop = cdGetObstacle();

				if (prop
						&& g_Vars.currentplayer->prop->pos.y < prop->pos.y
						&& prop->type == PROPTYPE_OBJ) {
					obj = prop->obj;

					if (obj->modelnum == MODEL_HOVBIKE) {
						amount = (obj->maxdamage - obj->damage + 1) / 250.0f;
						obj->flags &= ~OBJFLAG_INVINCIBLE;
						func0f0852ac(obj, amount, &obj->prop->pos, 0x22, -1);
					}
				}
			}
		}

		// Kill player if standing on tile with TILEFLAG_DIE
		if ((g_Vars.currentplayer->floorflags & TILEFLAG_DIE)
				&& g_Vars.currentplayer->vv_manground - 20.0f < g_Vars.currentplayer->vv_ground
				&& g_Vars.currentplayer->onladder == false
				&& onladder2 == false) {
			currentPlayerDie(true);
		}
	}

	if (g_Vars.currentplayer->vv_manground > g_Vars.currentplayer->vv_ground) {
		// Not standing on ground - probably falling, or on an object of some sort
		fallspeed = g_Vars.currentplayer->bdeltapos.y;
		newmanground = g_Vars.currentplayer->vv_manground;

		if (debugIsTurboModeEnabled()
				&& g_Vars.currentplayer->bondforcespeed.x == 0
				&& g_Vars.currentplayer->bondforcespeed.z == 0) {
			multiplier = 0.277777777f * 5;
		} else {
			multiplier = 0.277777777f;
		}

		newfallspeed = fallspeed - g_Vars.lvupdate240freal * multiplier;
		newmanground += g_Vars.lvupdate240freal * (fallspeed + newfallspeed) * 0.5f;
		fallspeed = newfallspeed;

		if (newmanground < g_Vars.currentplayer->vv_ground) {
			newfallspeed = g_Vars.currentplayer->vv_manground - g_Vars.currentplayer->vv_ground;
			newmanground = g_Vars.currentplayer->vv_ground;

			fallspeed = sqrtf(g_Vars.currentplayer->bdeltapos.y *
					g_Vars.currentplayer->bdeltapos.y +
					(((newfallspeed + newfallspeed) * 0.277777777f) / 60.0f) * 60.0f);
			fallspeed = -fallspeed;
		}

		if (bwalkTryMoveUpwards(newmanground - g_Vars.currentplayer->vv_manground) == CDRESULT_NOCOLLISION) {
			// Falling
			g_Vars.currentplayer->vv_manground = newmanground;
			g_Vars.currentplayer->bdeltapos.y = fallspeed;

			if (g_Vars.currentplayer->isfalling == false) {
				// Just started falling
				g_Vars.currentplayer->isfalling = true;
				g_Vars.currentplayer->fallstart = g_Vars.lvframe60;
			} else {
				if (g_Vars.lvframe60 - g_Vars.currentplayer->fallstart > PALDOWN(240)) {
					// Have been falling for 4 seconds
					currentPlayerDie(true);
				}
			}
		} else {
			// Not falling
			if (g_Vars.normmplayerisrunning == false
					&& g_Vars.currentplayer->vv_ground < g_Vars.currentplayer->vv_manground - 30) {
				// Not falling - but still at least 30 units off the ground.
				// Must be something in the way...
				prop = cdGetObstacle();

				if (prop) {
					if (prop->type == PROPTYPE_CHR) {
						// Landed on top of a chr
						if (prop->chr->inlift) {
							chrYeetFromPos(prop->chr, &g_Vars.currentplayer->prop->pos, 0);
						}
					} else if (prop->type == PROPTYPE_PLAYER) {
						// Landed on top of a player
						u32 prevplayernum = g_Vars.currentplayernum;
						setCurrentPlayerNum(propGetPlayerNum(prop));

						if (g_Vars.currentplayer->inlift) {
							currentPlayerDieByShooter(prevplayernum, true);
						}

						setCurrentPlayerNum(prevplayernum);
					}
				}
			}

			g_Vars.currentplayer->bdeltapos.y = 0.0f;

			if (g_Vars.currentplayer->isfalling) {
				g_Vars.currentplayer->isfalling = false;
			}

			if (g_Vars.currentplayer->vv_manground <= -30000) {
				currentPlayerDie(true);
			}
		}
	} else {
		// Not falling
		if (g_Vars.currentplayer->isfalling) {
			g_Vars.currentplayer->isfalling = false;
		}

		if (g_Vars.currentplayer->vv_manground <= -30000) {
			currentPlayerDie(true);
		}
	}

	if (g_Vars.currentplayer->bdeltapos.y < 0 &&
			g_Vars.currentplayer->vv_manground <= g_Vars.currentplayer->vv_ground) {
		// Landing after a fall
		if (g_Vars.currentplayer->isfalling) {
			g_Vars.currentplayer->isfalling = false;
		}

		// I suspect these crouch fields are related to the recovery during
		// landing. Eg. The faster the fall speed, the longer Jo will take to
		// stand back to full height again.
		if (g_Vars.currentplayer->bdeltapos.y < -13.333333f) {
			g_Vars.currentplayer->crouchtime240 = PALDOWN(60);
			g_Vars.currentplayer->crouchfall = -90;
		} else if (g_Vars.currentplayer->bdeltapos.y < -5.0f) {
			g_Vars.currentplayer->crouchtime240 = PALDOWN(60);
			g_Vars.currentplayer->crouchfall =
				(-5.0f - g_Vars.currentplayer->bdeltapos.y) * -90.0f / 8.333333f;
		}

		if (g_Vars.currentplayer->bdeltapos.y < -6.0f) {
			// Play footstep sounds
			s32 sound;
			struct chrdata *chr = g_Vars.currentplayer->prop->chr;
			chr->floortype = g_Vars.currentplayer->floortype;
			chr->footstep = 1;

			sound = chrChooseFootstepSound(chr, true);

			if (sound != -1) {
				if (sound != -1) {
					func0f0939f8(NULL, g_Vars.currentplayer->prop, sound,
							-1, -1, 0x8400, 0, 0, 0, -1, 0, -1, -1, -1, -1);
				}

				chr->footstep = 2;
				sound = chrChooseFootstepSound(chr, true);

				if (sound != -1) {
					func0f0939f8(NULL, g_Vars.currentplayer->prop, sound,
							-1, -1, 0x8400, 0, 0, 0, -1, 0, -1, -1, -1, -1);
				}
			}

			if (g_Vars.mplayerisrunning == false
					&& (chr->headnum == HEAD_DARK_COMBAT || chr->headnum == HEAD_DARK_FROCK)
					&& g_Vars.lvframe60 - g_Vars.currentplayer->fallstart > PALDOWN(40)) {
				// Play Jo landing grunt
				s32 sounds[] = {
					SFX_JO_LANDING_046F,
					SFX_JO_LANDING_05B6,
					SFX_JO_LANDING_05B7
				};

				func0f0939f8(NULL, g_Vars.currentplayer->prop, sounds[random() % 3],
						-1, -1, 0x8400, 0, 0, 0, -1, 0, -1, -1, -1, -1);
			}
		}

		g_Vars.currentplayer->bdeltapos.y = 0;
	}

	// Decrease crouchtime240 for this tick.
	// If reached 0 and crouchfall is negative, start increasing
	// crouchfall over the next several ticks until it reaches 0.
	for (i = 0; i < g_Vars.lvupdate240; i++) {
		if (g_Vars.currentplayer->crouchtime240 > 0) {
			g_Vars.currentplayer->sumcrouch =
				g_Vars.currentplayer->sumcrouch * (PAL ? 0.93540000915527f : 0.9456f) + g_Vars.currentplayer->crouchfall;
			g_Vars.currentplayer->crouchtime240--;
		} else {
			if (g_Vars.currentplayer->crouchfall < 0) {
				g_Vars.currentplayer->crouchfall -= (PAL ? -1.3636363744736f : -1.125f);

				if (g_Vars.currentplayer->crouchfall >= 0) {
					g_Vars.currentplayer->crouchfall = 0;
				}
			}

			g_Vars.currentplayer->sumcrouch =
				g_Vars.currentplayer->sumcrouch * (PAL ? 0.93540000915527f : 0.9456f) + g_Vars.currentplayer->crouchfall;
		}
	}

	{
		f32 eyeheight;
		g_Vars.currentplayer->crouchheight = g_Vars.currentplayer->sumcrouch * (PAL ? 0.064599990844727f : 0.054400026798248f);
		g_Vars.currentplayer->vv_height =
			(g_Vars.currentplayer->headpos.y / g_Vars.currentplayer->standheight)
			* g_Vars.currentplayer->vv_eyeheight;

		eyeheight = g_Vars.currentplayer->vv_height +
			g_Vars.currentplayer->crouchoffsetrealsmall +
			g_Vars.currentplayer->crouchheight *
			g_Vars.currentplayer->vv_eyeheight * 0.0062893079593778f;

		if (eyeheight < 30) {
			eyeheight = 30;
		}

		newpos.x = g_Vars.currentplayer->prop->pos.x;
		newpos.y = g_Vars.currentplayer->vv_manground + eyeheight;
		newpos.z = g_Vars.currentplayer->prop->pos.z;
	}

	if (newpos.y < g_Vars.currentplayer->vv_ground + 10) {
		newpos.y = g_Vars.currentplayer->vv_ground + 10;
	}

	if (newpos.x != g_Vars.currentplayer->prop->pos.x
			|| newpos.y != g_Vars.currentplayer->prop->pos.y
			|| newpos.z != g_Vars.currentplayer->prop->pos.z) {
		func0f065e74(&g_Vars.currentplayer->prop->pos, g_Vars.currentplayer->prop->rooms, &newpos, newrooms);

		g_Vars.currentplayer->prop->pos.x = newpos.x;
		g_Vars.currentplayer->prop->pos.y = newpos.y;
		g_Vars.currentplayer->prop->pos.z = newpos.z;

		func0f065c44(g_Vars.currentplayer->prop);
		roomsCopy(newrooms, g_Vars.currentplayer->prop->rooms);
	}
}
#else
GLOBAL_ASM(
glabel bwalkUpdateVertical
.late_rodata
glabel var7f1a7adcnb
.word 0x3f99999a
glabel var7f1a7ae0nb
.word 0x3f8ccccd
glabel var7f1a7ae4nb
.word 0xc6ea6000
glabel var7f1a7ae8nb
.word 0xc6ea6000
glabel var7f1a7aecnb
.word 0x3d3a5e30
glabel var7f1a7af0nb
.word 0x3d3a5e30
glabel var7f1a7af4nb
.word 0x3f745a1d
glabel var7f1a7af8nb
.word 0x3d3a5e30
glabel var7f1a7afcnb
.word 0x3fb1c71d
glabel var7f1a7b00nb
.word 0x3e8e38e4
glabel var7f1a7b04nb
.word 0x3e8e38e4
glabel var7f1a7b08nb
.word 0xc6ea6000
glabel var7f1a7b0cnb
.word 0xc6ea6000
glabel var7f1a7b10nb
.word 0xc1555555
glabel var7f1a7b14nb
.word 0x41055555
glabel var7f1a7b18nb
.word 0x3f7212d7
glabel var7f1a7b1cnb
.word 0x3d5ed290
glabel var7f1a7b20nb
.word 0x3bce168a
.text
/*  f0c2bd8:	27bdff10 */ 	addiu	$sp,$sp,-240
/*  f0c2bdc:	afb00048 */ 	sw	$s0,0x48($sp)
/*  f0c2be0:	3c10800a */ 	lui	$s0,0x800a
/*  f0c2be4:	2610e6c0 */ 	addiu	$s0,$s0,-6464
/*  f0c2be8:	8e0e0284 */ 	lw	$t6,0x284($s0)
/*  f0c2bec:	afbf004c */ 	sw	$ra,0x4c($sp)
/*  f0c2bf0:	afa000d0 */ 	sw	$zero,0xd0($sp)
/*  f0c2bf4:	afa00090 */ 	sw	$zero,0x90($sp)
/*  f0c2bf8:	27a500e4 */ 	addiu	$a1,$sp,0xe4
/*  f0c2bfc:	27a600e0 */ 	addiu	$a2,$sp,0xe0
/*  f0c2c00:	27a700dc */ 	addiu	$a3,$sp,0xdc
/*  f0c2c04:	0fc2ff20 */ 	jal	propPlayerGetBbox
/*  f0c2c08:	8dc400bc */ 	lw	$a0,0xbc($t6)
/*  f0c2c0c:	3c017f1a */ 	lui	$at,0x7f1a
/*  f0c2c10:	c4267adc */ 	lwc1	$f6,0x7adc($at)
/*  f0c2c14:	c7a400e4 */ 	lwc1	$f4,0xe4($sp)
/*  f0c2c18:	8e020284 */ 	lw	$v0,0x284($s0)
/*  f0c2c1c:	c7aa00e0 */ 	lwc1	$f10,0xe0($sp)
/*  f0c2c20:	46062202 */ 	mul.s	$f8,$f4,$f6
/*  f0c2c24:	8c4300bc */ 	lw	$v1,0xbc($v0)
/*  f0c2c28:	c4460074 */ 	lwc1	$f6,0x74($v0)
/*  f0c2c2c:	3c013f80 */ 	lui	$at,0x3f80
/*  f0c2c30:	c460000c */ 	lwc1	$f0,0xc($v1)
/*  f0c2c34:	34188040 */ 	dli	$t8,0x8040
/*  f0c2c38:	245902a0 */ 	addiu	$t9,$v0,0x2a0
/*  f0c2c3c:	46005101 */ 	sub.s	$f4,$f10,$f0
/*  f0c2c40:	44054000 */ 	mfc1	$a1,$f8
/*  f0c2c44:	44815000 */ 	mtc1	$at,$f10
/*  f0c2c48:	46003201 */ 	sub.s	$f8,$f6,$f0
/*  f0c2c4c:	44062000 */ 	mfc1	$a2,$f4
/*  f0c2c50:	246f0028 */ 	addiu	$t7,$v1,0x28
/*  f0c2c54:	afaf0010 */ 	sw	$t7,0x10($sp)
/*  f0c2c58:	460a4100 */ 	add.s	$f4,$f8,$f10
/*  f0c2c5c:	afb90018 */ 	sw	$t9,0x18($sp)
/*  f0c2c60:	afb80014 */ 	sw	$t8,0x14($sp)
/*  f0c2c64:	24640008 */ 	addiu	$a0,$v1,0x8
/*  f0c2c68:	44072000 */ 	mfc1	$a3,$f4
/*  f0c2c6c:	0c00ad11 */ 	jal	func00029ffc
/*  f0c2c70:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c2c74:	14400031 */ 	bnez	$v0,.NB0f0c2d3c
/*  f0c2c78:	afa200d4 */ 	sw	$v0,0xd4($sp)
/*  f0c2c7c:	8e020284 */ 	lw	$v0,0x284($s0)
/*  f0c2c80:	3c014120 */ 	lui	$at,0x4120
/*  f0c2c84:	44815000 */ 	mtc1	$at,$f10
/*  f0c2c88:	8c4900bc */ 	lw	$t1,0xbc($v0)
/*  f0c2c8c:	27a500c0 */ 	addiu	$a1,$sp,0xc0
/*  f0c2c90:	c5260008 */ 	lwc1	$f6,0x8($t1)
/*  f0c2c94:	e7a600b4 */ 	swc1	$f6,0xb4($sp)
/*  f0c2c98:	8c4a00bc */ 	lw	$t2,0xbc($v0)
/*  f0c2c9c:	c548000c */ 	lwc1	$f8,0xc($t2)
/*  f0c2ca0:	460a4101 */ 	sub.s	$f4,$f8,$f10
/*  f0c2ca4:	e7a400b8 */ 	swc1	$f4,0xb8($sp)
/*  f0c2ca8:	8c4b00bc */ 	lw	$t3,0xbc($v0)
/*  f0c2cac:	c5660010 */ 	lwc1	$f6,0x10($t3)
/*  f0c2cb0:	e7a600bc */ 	swc1	$f6,0xbc($sp)
/*  f0c2cb4:	8c4400bc */ 	lw	$a0,0xbc($v0)
/*  f0c2cb8:	0fc19283 */ 	jal	roomsCopy
/*  f0c2cbc:	24840028 */ 	addiu	$a0,$a0,0x28
/*  f0c2cc0:	8e040284 */ 	lw	$a0,0x284($s0)
/*  f0c2cc4:	27a500b4 */ 	addiu	$a1,$sp,0xb4
/*  f0c2cc8:	0fc323f3 */ 	jal	bmove0f0cb79c
/*  f0c2ccc:	27a600c0 */ 	addiu	$a2,$sp,0xc0
/*  f0c2cd0:	3c017f1a */ 	lui	$at,0x7f1a
/*  f0c2cd4:	c42a7ae0 */ 	lwc1	$f10,0x7ae0($at)
/*  f0c2cd8:	c7a800e4 */ 	lwc1	$f8,0xe4($sp)
/*  f0c2cdc:	8e020284 */ 	lw	$v0,0x284($s0)
/*  f0c2ce0:	c7a600e0 */ 	lwc1	$f6,0xe0($sp)
/*  f0c2ce4:	460a4102 */ 	mul.s	$f4,$f8,$f10
/*  f0c2ce8:	8c4300bc */ 	lw	$v1,0xbc($v0)
/*  f0c2cec:	c44a0074 */ 	lwc1	$f10,0x74($v0)
/*  f0c2cf0:	3c014120 */ 	lui	$at,0x4120
/*  f0c2cf4:	c460000c */ 	lwc1	$f0,0xc($v1)
/*  f0c2cf8:	27ac00c0 */ 	addiu	$t4,$sp,0xc0
/*  f0c2cfc:	340d8040 */ 	dli	$t5,0x8040
/*  f0c2d00:	46003201 */ 	sub.s	$f8,$f6,$f0
/*  f0c2d04:	44052000 */ 	mfc1	$a1,$f4
/*  f0c2d08:	44813000 */ 	mtc1	$at,$f6
/*  f0c2d0c:	46005101 */ 	sub.s	$f4,$f10,$f0
/*  f0c2d10:	44064000 */ 	mfc1	$a2,$f8
/*  f0c2d14:	244e02a0 */ 	addiu	$t6,$v0,0x2a0
/*  f0c2d18:	afae0018 */ 	sw	$t6,0x18($sp)
/*  f0c2d1c:	46062201 */ 	sub.s	$f8,$f4,$f6
/*  f0c2d20:	afad0014 */ 	sw	$t5,0x14($sp)
/*  f0c2d24:	afac0010 */ 	sw	$t4,0x10($sp)
/*  f0c2d28:	24640008 */ 	addiu	$a0,$v1,0x8
/*  f0c2d2c:	44074000 */ 	mfc1	$a3,$f8
/*  f0c2d30:	0c00ad11 */ 	jal	func00029ffc
/*  f0c2d34:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c2d38:	afa200d0 */ 	sw	$v0,0xd0($sp)
.NB0f0c2d3c:
/*  f0c2d3c:	8e020284 */ 	lw	$v0,0x284($s0)
/*  f0c2d40:	8c4f00bc */ 	lw	$t7,0xbc($v0)
/*  f0c2d44:	c5ea0008 */ 	lwc1	$f10,0x8($t7)
/*  f0c2d48:	e7aa00b4 */ 	swc1	$f10,0xb4($sp)
/*  f0c2d4c:	8c5800bc */ 	lw	$t8,0xbc($v0)
/*  f0c2d50:	c704000c */ 	lwc1	$f4,0xc($t8)
/*  f0c2d54:	e7a400b8 */ 	swc1	$f4,0xb8($sp)
/*  f0c2d58:	8c5900bc */ 	lw	$t9,0xbc($v0)
/*  f0c2d5c:	c7260010 */ 	lwc1	$f6,0x10($t9)
/*  f0c2d60:	e7a600bc */ 	swc1	$f6,0xbc($sp)
/*  f0c2d64:	8c4902b0 */ 	lw	$t1,0x2b0($v0)
/*  f0c2d68:	5120000b */ 	beqzl	$t1,.NB0f0c2d98
/*  f0c2d6c:	8c4400bc */ 	lw	$a0,0xbc($v0)
/*  f0c2d70:	8c4a19b8 */ 	lw	$t2,0x19b8($v0)
/*  f0c2d74:	c448008c */ 	lwc1	$f8,0x8c($v0)
/*  f0c2d78:	448a5000 */ 	mtc1	$t2,$f10
/*  f0c2d7c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c2d80:	46805120 */ 	cvt.s.w	$f4,$f10
/*  f0c2d84:	c7aa00b8 */ 	lwc1	$f10,0xb8($sp)
/*  f0c2d88:	46044180 */ 	add.s	$f6,$f8,$f4
/*  f0c2d8c:	46065201 */ 	sub.s	$f8,$f10,$f6
/*  f0c2d90:	e7a800b8 */ 	swc1	$f8,0xb8($sp)
/*  f0c2d94:	8c4400bc */ 	lw	$a0,0xbc($v0)
.NB0f0c2d98:
/*  f0c2d98:	27a500c0 */ 	addiu	$a1,$sp,0xc0
/*  f0c2d9c:	0fc19283 */ 	jal	roomsCopy
/*  f0c2da0:	24840028 */ 	addiu	$a0,$a0,0x28
/*  f0c2da4:	8e040284 */ 	lw	$a0,0x284($s0)
/*  f0c2da8:	27a500b4 */ 	addiu	$a1,$sp,0xb4
/*  f0c2dac:	0fc323f3 */ 	jal	bmove0f0cb79c
/*  f0c2db0:	27a600c0 */ 	addiu	$a2,$sp,0xc0
/*  f0c2db4:	8e020284 */ 	lw	$v0,0x284($s0)
/*  f0c2db8:	27ae0094 */ 	addiu	$t6,$sp,0x94
/*  f0c2dbc:	27af0090 */ 	addiu	$t7,$sp,0x90
/*  f0c2dc0:	8c450378 */ 	lw	$a1,0x378($v0)
/*  f0c2dc4:	244b161e */ 	addiu	$t3,$v0,0x161e
/*  f0c2dc8:	244c161c */ 	addiu	$t4,$v0,0x161c
/*  f0c2dcc:	244d19b0 */ 	addiu	$t5,$v0,0x19b0
/*  f0c2dd0:	afad0018 */ 	sw	$t5,0x18($sp)
/*  f0c2dd4:	afac0014 */ 	sw	$t4,0x14($sp)
/*  f0c2dd8:	afab0010 */ 	sw	$t3,0x10($sp)
/*  f0c2ddc:	afaf0020 */ 	sw	$t7,0x20($sp)
/*  f0c2de0:	afae001c */ 	sw	$t6,0x1c($sp)
/*  f0c2de4:	27a400b4 */ 	addiu	$a0,$sp,0xb4
/*  f0c2de8:	27a600c0 */ 	addiu	$a2,$sp,0xc0
/*  f0c2dec:	0c00ad7e */ 	jal	cdFindGroundY
/*  f0c2df0:	2447161a */ 	addiu	$a3,$v0,0x161a
/*  f0c2df4:	8e020284 */ 	lw	$v0,0x284($s0)
/*  f0c2df8:	3c017f1a */ 	lui	$at,0x7f1a
/*  f0c2dfc:	c42a7ae4 */ 	lwc1	$f10,0x7ae4($at)
/*  f0c2e00:	c4441ae8 */ 	lwc1	$f4,0x1ae8($v0)
/*  f0c2e04:	46040380 */ 	add.s	$f14,$f0,$f4
/*  f0c2e08:	460a703c */ 	c.lt.s	$f14,$f10
/*  f0c2e0c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c2e10:	45000002 */ 	bc1f	.NB0f0c2e1c
/*  f0c2e14:	3c017f1a */ 	lui	$at,0x7f1a
/*  f0c2e18:	c42e7ae8 */ 	lwc1	$f14,0x7ae8($at)
.NB0f0c2e1c:
/*  f0c2e1c:	8c5802b0 */ 	lw	$t8,0x2b0($v0)
/*  f0c2e20:	8fb90094 */ 	lw	$t9,0x94($sp)
/*  f0c2e24:	53000049 */ 	beqzl	$t8,.NB0f0c2f4c
/*  f0c2e28:	afa00090 */ 	sw	$zero,0x90($sp)
/*  f0c2e2c:	53200047 */ 	beqzl	$t9,.NB0f0c2f4c
/*  f0c2e30:	afa00090 */ 	sw	$zero,0x90($sp)
/*  f0c2e34:	8c4902ac */ 	lw	$t1,0x2ac($v0)
/*  f0c2e38:	55200044 */ 	bnezl	$t1,.NB0f0c2f4c
/*  f0c2e3c:	afa00090 */ 	sw	$zero,0x90($sp)
/*  f0c2e40:	8c4a0030 */ 	lw	$t2,0x30($v0)
/*  f0c2e44:	c4400078 */ 	lwc1	$f0,0x78($v0)
/*  f0c2e48:	8fab0090 */ 	lw	$t3,0x90($sp)
/*  f0c2e4c:	15400035 */ 	bnez	$t2,.NB0f0c2f24
/*  f0c2e50:	46007301 */ 	sub.s	$f12,$f14,$f0
/*  f0c2e54:	8c4c0298 */ 	lw	$t4,0x298($v0)
/*  f0c2e58:	556c0033 */ 	bnel	$t3,$t4,.NB0f0c2f28
/*  f0c2e5c:	8e020284 */ 	lw	$v0,0x284($s0)
/*  f0c2e60:	c4460294 */ 	lwc1	$f6,0x294($v0)
/*  f0c2e64:	c4480074 */ 	lwc1	$f8,0x74($v0)
/*  f0c2e68:	3c013f80 */ 	lui	$at,0x3f80
/*  f0c2e6c:	44812000 */ 	mtc1	$at,$f4
/*  f0c2e70:	46083081 */ 	sub.s	$f2,$f6,$f8
/*  f0c2e74:	3c01bf80 */ 	lui	$at,0xbf80
/*  f0c2e78:	4604103c */ 	c.lt.s	$f2,$f4
/*  f0c2e7c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c2e80:	45020029 */ 	bc1fl	.NB0f0c2f28
/*  f0c2e84:	8e020284 */ 	lw	$v0,0x284($s0)
/*  f0c2e88:	44815000 */ 	mtc1	$at,$f10
/*  f0c2e8c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c2e90:	4602503c */ 	c.lt.s	$f10,$f2
/*  f0c2e94:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c2e98:	45020023 */ 	bc1fl	.NB0f0c2f28
/*  f0c2e9c:	8e020284 */ 	lw	$v0,0x284($s0)
/*  f0c2ea0:	44804000 */ 	mtc1	$zero,$f8
/*  f0c2ea4:	460c0180 */ 	add.s	$f6,$f0,$f12
/*  f0c2ea8:	460c403c */ 	c.lt.s	$f8,$f12
/*  f0c2eac:	e4460078 */ 	swc1	$f6,0x78($v0)
/*  f0c2eb0:	8fad0090 */ 	lw	$t5,0x90($sp)
/*  f0c2eb4:	45030012 */ 	bc1tl	.NB0f0c2f00
/*  f0c2eb8:	8e020284 */ 	lw	$v0,0x284($s0)
/*  f0c2ebc:	51a00010 */ 	beqzl	$t5,.NB0f0c2f00
/*  f0c2ec0:	8e020284 */ 	lw	$v0,0x284($s0)
/*  f0c2ec4:	8da20004 */ 	lw	$v0,0x4($t5)
/*  f0c2ec8:	5040000d */ 	beqzl	$v0,.NB0f0c2f00
/*  f0c2ecc:	8e020284 */ 	lw	$v0,0x284($s0)
/*  f0c2ed0:	8c4e0008 */ 	lw	$t6,0x8($v0)
/*  f0c2ed4:	000e7800 */ 	sll	$t7,$t6,0x0
/*  f0c2ed8:	05e30009 */ 	bgezl	$t7,.NB0f0c2f00
/*  f0c2edc:	8e020284 */ 	lw	$v0,0x284($s0)
/*  f0c2ee0:	e7ac0088 */ 	swc1	$f12,0x88($sp)
/*  f0c2ee4:	0fc30612 */ 	jal	bwalkTryMoveUpwards
/*  f0c2ee8:	e7ae00d8 */ 	swc1	$f14,0xd8($sp)
/*  f0c2eec:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0c2ef0:	c7ac0088 */ 	lwc1	$f12,0x88($sp)
/*  f0c2ef4:	1441000b */ 	bne	$v0,$at,.NB0f0c2f24
/*  f0c2ef8:	c7ae00d8 */ 	lwc1	$f14,0xd8($sp)
/*  f0c2efc:	8e020284 */ 	lw	$v0,0x284($s0)
.NB0f0c2f00:
/*  f0c2f00:	3c017f1a */ 	lui	$at,0x7f1a
/*  f0c2f04:	c4440074 */ 	lwc1	$f4,0x74($v0)
/*  f0c2f08:	460c2280 */ 	add.s	$f10,$f4,$f12
/*  f0c2f0c:	e44a0074 */ 	swc1	$f10,0x74($v0)
/*  f0c2f10:	8e020284 */ 	lw	$v0,0x284($s0)
/*  f0c2f14:	c4287aec */ 	lwc1	$f8,0x7aec($at)
/*  f0c2f18:	c4460074 */ 	lwc1	$f6,0x74($v0)
/*  f0c2f1c:	46083103 */ 	div.s	$f4,$f6,$f8
/*  f0c2f20:	e4440070 */ 	swc1	$f4,0x70($v0)
.NB0f0c2f24:
/*  f0c2f24:	8e020284 */ 	lw	$v0,0x284($s0)
.NB0f0c2f28:
/*  f0c2f28:	8c581af8 */ 	lw	$t8,0x1af8($v0)
/*  f0c2f2c:	53000008 */ 	beqzl	$t8,.NB0f0c2f50
/*  f0c2f30:	8fb90094 */ 	lw	$t9,0x94($sp)
/*  f0c2f34:	c44a1b54 */ 	lwc1	$f10,0x1b54($v0)
/*  f0c2f38:	460c5180 */ 	add.s	$f6,$f10,$f12
/*  f0c2f3c:	e4461b54 */ 	swc1	$f6,0x1b54($v0)
/*  f0c2f40:	10000002 */ 	beqz	$zero,.NB0f0c2f4c
/*  f0c2f44:	8e020284 */ 	lw	$v0,0x284($s0)
/*  f0c2f48:	afa00090 */ 	sw	$zero,0x90($sp)
.NB0f0c2f4c:
/*  f0c2f4c:	8fb90094 */ 	lw	$t9,0x94($sp)
.NB0f0c2f50:
/*  f0c2f50:	ac5902b0 */ 	sw	$t9,0x2b0($v0)
/*  f0c2f54:	8fa90094 */ 	lw	$t1,0x94($sp)
/*  f0c2f58:	51200004 */ 	beqzl	$t1,.NB0f0c2f6c
/*  f0c2f5c:	8fab0090 */ 	lw	$t3,0x90($sp)
/*  f0c2f60:	8e0a0284 */ 	lw	$t2,0x284($s0)
/*  f0c2f64:	e54e0294 */ 	swc1	$f14,0x294($t2)
/*  f0c2f68:	8fab0090 */ 	lw	$t3,0x90($sp)
.NB0f0c2f6c:
/*  f0c2f6c:	8e0c0284 */ 	lw	$t4,0x284($s0)
/*  f0c2f70:	ad8b0298 */ 	sw	$t3,0x298($t4)
/*  f0c2f74:	8e020284 */ 	lw	$v0,0x284($s0)
/*  f0c2f78:	8c4d02ac */ 	lw	$t5,0x2ac($v0)
/*  f0c2f7c:	51a00027 */ 	beqzl	$t5,.NB0f0c301c
/*  f0c2f80:	8faf00d4 */ 	lw	$t7,0xd4($sp)
/*  f0c2f84:	c44c029c */ 	lwc1	$f12,0x29c($v0)
/*  f0c2f88:	44804000 */ 	mtc1	$zero,$f8
/*  f0c2f8c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c2f90:	460c403e */ 	c.le.s	$f8,$f12
/*  f0c2f94:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c2f98:	4501000b */ 	bc1t	.NB0f0c2fc8
/*  f0c2f9c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c2fa0:	c4420074 */ 	lwc1	$f2,0x74($v0)
/*  f0c2fa4:	4602703e */ 	c.le.s	$f14,$f2
/*  f0c2fa8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c2fac:	45020012 */ 	bc1fl	.NB0f0c2ff8
/*  f0c2fb0:	46027301 */ 	sub.s	$f12,$f14,$f2
/*  f0c2fb4:	460c1100 */ 	add.s	$f4,$f2,$f12
/*  f0c2fb8:	4604703e */ 	c.le.s	$f14,$f4
/*  f0c2fbc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c2fc0:	4502000d */ 	bc1fl	.NB0f0c2ff8
/*  f0c2fc4:	46027301 */ 	sub.s	$f12,$f14,$f2
.NB0f0c2fc8:
/*  f0c2fc8:	0fc30612 */ 	jal	bwalkTryMoveUpwards
/*  f0c2fcc:	e7ae00d8 */ 	swc1	$f14,0xd8($sp)
/*  f0c2fd0:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0c2fd4:	14410010 */ 	bne	$v0,$at,.NB0f0c3018
/*  f0c2fd8:	c7ae00d8 */ 	lwc1	$f14,0xd8($sp)
/*  f0c2fdc:	8e020284 */ 	lw	$v0,0x284($s0)
/*  f0c2fe0:	c44a0074 */ 	lwc1	$f10,0x74($v0)
/*  f0c2fe4:	c446029c */ 	lwc1	$f6,0x29c($v0)
/*  f0c2fe8:	46065200 */ 	add.s	$f8,$f10,$f6
/*  f0c2fec:	1000000a */ 	beqz	$zero,.NB0f0c3018
/*  f0c2ff0:	e4480074 */ 	swc1	$f8,0x74($v0)
/*  f0c2ff4:	46027301 */ 	sub.s	$f12,$f14,$f2
.NB0f0c2ff8:
/*  f0c2ff8:	0fc30612 */ 	jal	bwalkTryMoveUpwards
/*  f0c2ffc:	e7ae00d8 */ 	swc1	$f14,0xd8($sp)
/*  f0c3000:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0c3004:	14410004 */ 	bne	$v0,$at,.NB0f0c3018
/*  f0c3008:	c7ae00d8 */ 	lwc1	$f14,0xd8($sp)
/*  f0c300c:	8e0e0284 */ 	lw	$t6,0x284($s0)
/*  f0c3010:	e5ce0074 */ 	swc1	$f14,0x74($t6)
/*  f0c3014:	afa000d4 */ 	sw	$zero,0xd4($sp)
.NB0f0c3018:
/*  f0c3018:	8faf00d4 */ 	lw	$t7,0xd4($sp)
.NB0f0c301c:
/*  f0c301c:	8e180284 */ 	lw	$t8,0x284($s0)
/*  f0c3020:	44803000 */ 	mtc1	$zero,$f6
/*  f0c3024:	3c017f1a */ 	lui	$at,0x7f1a
/*  f0c3028:	af0f02ac */ 	sw	$t7,0x2ac($t8)
/*  f0c302c:	8e020284 */ 	lw	$v0,0x284($s0)
/*  f0c3030:	8fa900d0 */ 	lw	$t1,0xd0($sp)
/*  f0c3034:	8c5902ac */ 	lw	$t9,0x2ac($v0)
/*  f0c3038:	13200005 */ 	beqz	$t9,.NB0f0c3050
/*  f0c303c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c3040:	c4440074 */ 	lwc1	$f4,0x74($v0)
/*  f0c3044:	e4440078 */ 	swc1	$f4,0x78($v0)
/*  f0c3048:	10000005 */ 	beqz	$zero,.NB0f0c3060
/*  f0c304c:	8e020284 */ 	lw	$v0,0x284($s0)
.NB0f0c3050:
/*  f0c3050:	55200004 */ 	bnezl	$t1,.NB0f0c3064
/*  f0c3054:	c44a0080 */ 	lwc1	$f10,0x80($v0)
/*  f0c3058:	e44e0078 */ 	swc1	$f14,0x78($v0)
/*  f0c305c:	8e020284 */ 	lw	$v0,0x284($s0)
.NB0f0c3060:
/*  f0c3060:	c44a0080 */ 	lwc1	$f10,0x80($v0)
.NB0f0c3064:
/*  f0c3064:	460a303e */ 	c.le.s	$f6,$f10
/*  f0c3068:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c306c:	45030008 */ 	bc1tl	.NB0f0c3090
/*  f0c3070:	c4480074 */ 	lwc1	$f8,0x74($v0)
/*  f0c3074:	c4420074 */ 	lwc1	$f2,0x74($v0)
/*  f0c3078:	c4400078 */ 	lwc1	$f0,0x78($v0)
/*  f0c307c:	4600103c */ 	c.lt.s	$f2,$f0
/*  f0c3080:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c3084:	4502004c */ 	bc1fl	.NB0f0c31b8
/*  f0c3088:	4602003c */ 	c.lt.s	$f0,$f2
/*  f0c308c:	c4480074 */ 	lwc1	$f8,0x74($v0)
.NB0f0c3090:
/*  f0c3090:	c4247af0 */ 	lwc1	$f4,0x7af0($at)
/*  f0c3094:	3c017f1a */ 	lui	$at,0x7f1a
/*  f0c3098:	00001825 */ 	or	$v1,$zero,$zero
/*  f0c309c:	46044283 */ 	div.s	$f10,$f8,$f4
/*  f0c30a0:	e44a0070 */ 	swc1	$f10,0x70($v0)
/*  f0c30a4:	8e0a0034 */ 	lw	$t2,0x34($s0)
/*  f0c30a8:	5940000e */ 	blezl	$t2,.NB0f0c30e4
/*  f0c30ac:	8e020284 */ 	lw	$v0,0x284($s0)
/*  f0c30b0:	c4207af4 */ 	lwc1	$f0,0x7af4($at)
/*  f0c30b4:	8e020284 */ 	lw	$v0,0x284($s0)
.NB0f0c30b8:
/*  f0c30b8:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f0c30bc:	c4460070 */ 	lwc1	$f6,0x70($v0)
/*  f0c30c0:	c4440078 */ 	lwc1	$f4,0x78($v0)
/*  f0c30c4:	46003202 */ 	mul.s	$f8,$f6,$f0
/*  f0c30c8:	46044280 */ 	add.s	$f10,$f8,$f4
/*  f0c30cc:	e44a0070 */ 	swc1	$f10,0x70($v0)
/*  f0c30d0:	8e0b0034 */ 	lw	$t3,0x34($s0)
/*  f0c30d4:	006b082a */ 	slt	$at,$v1,$t3
/*  f0c30d8:	5420fff7 */ 	bnezl	$at,.NB0f0c30b8
/*  f0c30dc:	8e020284 */ 	lw	$v0,0x284($s0)
/*  f0c30e0:	8e020284 */ 	lw	$v0,0x284($s0)
.NB0f0c30e4:
/*  f0c30e4:	3c017f1a */ 	lui	$at,0x7f1a
/*  f0c30e8:	c4420074 */ 	lwc1	$f2,0x74($v0)
/*  f0c30ec:	c4400078 */ 	lwc1	$f0,0x78($v0)
/*  f0c30f0:	4600103c */ 	c.lt.s	$f2,$f0
/*  f0c30f4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c30f8:	45020015 */ 	bc1fl	.NB0f0c3150
/*  f0c30fc:	8e020284 */ 	lw	$v0,0x284($s0)
/*  f0c3100:	c4460070 */ 	lwc1	$f6,0x70($v0)
/*  f0c3104:	c4287af8 */ 	lwc1	$f8,0x7af8($at)
/*  f0c3108:	3c014248 */ 	lui	$at,0x4248
/*  f0c310c:	44812000 */ 	mtc1	$at,$f4
/*  f0c3110:	46083382 */ 	mul.s	$f14,$f6,$f8
/*  f0c3114:	46040301 */ 	sub.s	$f12,$f0,$f4
/*  f0c3118:	460c703c */ 	c.lt.s	$f14,$f12
/*  f0c311c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c3120:	45020003 */ 	bc1fl	.NB0f0c3130
/*  f0c3124:	46027301 */ 	sub.s	$f12,$f14,$f2
/*  f0c3128:	46006386 */ 	mov.s	$f14,$f12
/*  f0c312c:	46027301 */ 	sub.s	$f12,$f14,$f2
.NB0f0c3130:
/*  f0c3130:	0fc30612 */ 	jal	bwalkTryMoveUpwards
/*  f0c3134:	e7ae008c */ 	swc1	$f14,0x8c($sp)
/*  f0c3138:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0c313c:	14410003 */ 	bne	$v0,$at,.NB0f0c314c
/*  f0c3140:	c7ae008c */ 	lwc1	$f14,0x8c($sp)
/*  f0c3144:	8e0c0284 */ 	lw	$t4,0x284($s0)
/*  f0c3148:	e58e0074 */ 	swc1	$f14,0x74($t4)
.NB0f0c314c:
/*  f0c314c:	8e020284 */ 	lw	$v0,0x284($s0)
.NB0f0c3150:
/*  f0c3150:	3c0141a0 */ 	lui	$at,0x41a0
/*  f0c3154:	944d161c */ 	lhu	$t5,0x161c($v0)
/*  f0c3158:	c4420074 */ 	lwc1	$f2,0x74($v0)
/*  f0c315c:	c4400078 */ 	lwc1	$f0,0x78($v0)
/*  f0c3160:	31ae4000 */ 	andi	$t6,$t5,0x4000
/*  f0c3164:	51c00014 */ 	beqzl	$t6,.NB0f0c31b8
/*  f0c3168:	4602003c */ 	c.lt.s	$f0,$f2
/*  f0c316c:	44815000 */ 	mtc1	$at,$f10
/*  f0c3170:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c3174:	460a1181 */ 	sub.s	$f6,$f2,$f10
/*  f0c3178:	4600303c */ 	c.lt.s	$f6,$f0
/*  f0c317c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c3180:	4502000d */ 	bc1fl	.NB0f0c31b8
/*  f0c3184:	4602003c */ 	c.lt.s	$f0,$f2
/*  f0c3188:	8c4f02ac */ 	lw	$t7,0x2ac($v0)
/*  f0c318c:	8fb800d0 */ 	lw	$t8,0xd0($sp)
/*  f0c3190:	55e00009 */ 	bnezl	$t7,.NB0f0c31b8
/*  f0c3194:	4602003c */ 	c.lt.s	$f0,$f2
/*  f0c3198:	57000007 */ 	bnezl	$t8,.NB0f0c31b8
/*  f0c319c:	4602003c */ 	c.lt.s	$f0,$f2
/*  f0c31a0:	0fc2fbde */ 	jal	currentPlayerDie
/*  f0c31a4:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f0c31a8:	8e020284 */ 	lw	$v0,0x284($s0)
/*  f0c31ac:	c4420074 */ 	lwc1	$f2,0x74($v0)
/*  f0c31b0:	c4400078 */ 	lwc1	$f0,0x78($v0)
/*  f0c31b4:	4602003c */ 	c.lt.s	$f0,$f2
.NB0f0c31b8:
/*  f0c31b8:	00001825 */ 	or	$v1,$zero,$zero
/*  f0c31bc:	3c017f1a */ 	lui	$at,0x7f1a
/*  f0c31c0:	4502007f */ 	bc1fl	.NB0f0c33c0
/*  f0c31c4:	8c4a0030 */ 	lw	$t2,0x30($v0)
/*  f0c31c8:	c44e0080 */ 	lwc1	$f14,0x80($v0)
/*  f0c31cc:	e7a20084 */ 	swc1	$f2,0x84($sp)
/*  f0c31d0:	afa000ec */ 	sw	$zero,0xec($sp)
/*  f0c31d4:	0fc46661 */ 	jal	debug0f119984nb
/*  f0c31d8:	e7ae0080 */ 	swc1	$f14,0x80($sp)
/*  f0c31dc:	8fa300ec */ 	lw	$v1,0xec($sp)
/*  f0c31e0:	c7ae0080 */ 	lwc1	$f14,0x80($sp)
/*  f0c31e4:	10400011 */ 	beqz	$v0,.NB0f0c322c
/*  f0c31e8:	c7b00084 */ 	lwc1	$f16,0x84($sp)
/*  f0c31ec:	8e020284 */ 	lw	$v0,0x284($s0)
/*  f0c31f0:	44804000 */ 	mtc1	$zero,$f8
/*  f0c31f4:	c4441b6c */ 	lwc1	$f4,0x1b6c($v0)
/*  f0c31f8:	46044032 */ 	c.eq.s	$f8,$f4
/*  f0c31fc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c3200:	4500000a */ 	bc1f	.NB0f0c322c
/*  f0c3204:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c3208:	44805000 */ 	mtc1	$zero,$f10
/*  f0c320c:	c4461b74 */ 	lwc1	$f6,0x1b74($v0)
/*  f0c3210:	3c017f1a */ 	lui	$at,0x7f1a
/*  f0c3214:	46065032 */ 	c.eq.s	$f10,$f6
/*  f0c3218:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c321c:	45000003 */ 	bc1f	.NB0f0c322c
/*  f0c3220:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c3224:	10000004 */ 	beqz	$zero,.NB0f0c3238
/*  f0c3228:	c4327afc */ 	lwc1	$f18,0x7afc($at)
.NB0f0c322c:
/*  f0c322c:	3c017f1a */ 	lui	$at,0x7f1a
/*  f0c3230:	c4327b00 */ 	lwc1	$f18,0x7b00($at)
/*  f0c3234:	8e020284 */ 	lw	$v0,0x284($s0)
.NB0f0c3238:
/*  f0c3238:	c60c004c */ 	lwc1	$f12,0x4c($s0)
/*  f0c323c:	3c013f00 */ 	lui	$at,0x3f00
/*  f0c3240:	44813000 */ 	mtc1	$at,$f6
/*  f0c3244:	46126202 */ 	mul.s	$f8,$f12,$f18
/*  f0c3248:	c4400078 */ 	lwc1	$f0,0x78($v0)
/*  f0c324c:	46087081 */ 	sub.s	$f2,$f14,$f8
/*  f0c3250:	46027100 */ 	add.s	$f4,$f14,$f2
/*  f0c3254:	46001386 */ 	mov.s	$f14,$f2
/*  f0c3258:	46046282 */ 	mul.s	$f10,$f12,$f4
/*  f0c325c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c3260:	46065202 */ 	mul.s	$f8,$f10,$f6
/*  f0c3264:	46088400 */ 	add.s	$f16,$f16,$f8
/*  f0c3268:	4600803c */ 	c.lt.s	$f16,$f0
/*  f0c326c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c3270:	45000016 */ 	bc1f	.NB0f0c32cc
/*  f0c3274:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c3278:	c4440074 */ 	lwc1	$f4,0x74($v0)
/*  f0c327c:	3c014270 */ 	lui	$at,0x4270
/*  f0c3280:	44819000 */ 	mtc1	$at,$f18
/*  f0c3284:	46002081 */ 	sub.s	$f2,$f4,$f0
/*  f0c3288:	3c017f1a */ 	lui	$at,0x7f1a
/*  f0c328c:	c4267b04 */ 	lwc1	$f6,0x7b04($at)
/*  f0c3290:	c44e0080 */ 	lwc1	$f14,0x80($v0)
/*  f0c3294:	46021280 */ 	add.s	$f10,$f2,$f2
/*  f0c3298:	e7a00084 */ 	swc1	$f0,0x84($sp)
/*  f0c329c:	afa300ec */ 	sw	$v1,0xec($sp)
/*  f0c32a0:	46065202 */ 	mul.s	$f8,$f10,$f6
/*  f0c32a4:	46124103 */ 	div.s	$f4,$f8,$f18
/*  f0c32a8:	46122282 */ 	mul.s	$f10,$f4,$f18
/*  f0c32ac:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c32b0:	460e7182 */ 	mul.s	$f6,$f14,$f14
/*  f0c32b4:	0c012e84 */ 	jal	sqrtf
/*  f0c32b8:	460a3300 */ 	add.s	$f12,$f6,$f10
/*  f0c32bc:	8fa300ec */ 	lw	$v1,0xec($sp)
/*  f0c32c0:	c7b00084 */ 	lwc1	$f16,0x84($sp)
/*  f0c32c4:	46000387 */ 	neg.s	$f14,$f0
/*  f0c32c8:	8e020284 */ 	lw	$v0,0x284($s0)
.NB0f0c32cc:
/*  f0c32cc:	c4480074 */ 	lwc1	$f8,0x74($v0)
/*  f0c32d0:	e7b00084 */ 	swc1	$f16,0x84($sp)
/*  f0c32d4:	e7ae0080 */ 	swc1	$f14,0x80($sp)
/*  f0c32d8:	afa300ec */ 	sw	$v1,0xec($sp)
/*  f0c32dc:	0fc30612 */ 	jal	bwalkTryMoveUpwards
/*  f0c32e0:	46088301 */ 	sub.s	$f12,$f16,$f8
/*  f0c32e4:	44809000 */ 	mtc1	$zero,$f18
/*  f0c32e8:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0c32ec:	8fa300ec */ 	lw	$v1,0xec($sp)
/*  f0c32f0:	c7ae0080 */ 	lwc1	$f14,0x80($sp)
/*  f0c32f4:	1441001c */ 	bne	$v0,$at,.NB0f0c3368
/*  f0c32f8:	c7b00084 */ 	lwc1	$f16,0x84($sp)
/*  f0c32fc:	8e190284 */ 	lw	$t9,0x284($s0)
/*  f0c3300:	240b0001 */ 	addiu	$t3,$zero,0x1
/*  f0c3304:	e7300074 */ 	swc1	$f16,0x74($t9)
/*  f0c3308:	8e090284 */ 	lw	$t1,0x284($s0)
/*  f0c330c:	e52e0080 */ 	swc1	$f14,0x80($t1)
/*  f0c3310:	8e020284 */ 	lw	$v0,0x284($s0)
/*  f0c3314:	8c4a0030 */ 	lw	$t2,0x30($v0)
/*  f0c3318:	55400008 */ 	bnezl	$t2,.NB0f0c333c
/*  f0c331c:	8e0e0008 */ 	lw	$t6,0x8($s0)
/*  f0c3320:	ac4b0030 */ 	sw	$t3,0x30($v0)
/*  f0c3324:	8e0d0284 */ 	lw	$t5,0x284($s0)
/*  f0c3328:	8e0c0008 */ 	lw	$t4,0x8($s0)
/*  f0c332c:	adac0034 */ 	sw	$t4,0x34($t5)
/*  f0c3330:	10000032 */ 	beqz	$zero,.NB0f0c33fc
/*  f0c3334:	8e020284 */ 	lw	$v0,0x284($s0)
/*  f0c3338:	8e0e0008 */ 	lw	$t6,0x8($s0)
.NB0f0c333c:
/*  f0c333c:	8c4f0034 */ 	lw	$t7,0x34($v0)
/*  f0c3340:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f0c3344:	01cfc023 */ 	subu	$t8,$t6,$t7
/*  f0c3348:	2b0100f1 */ 	slti	$at,$t8,0xf1
/*  f0c334c:	5420002c */ 	bnezl	$at,.NB0f0c3400
/*  f0c3350:	c44e0080 */ 	lwc1	$f14,0x80($v0)
/*  f0c3354:	0fc2fbde */ 	jal	currentPlayerDie
/*  f0c3358:	afa300ec */ 	sw	$v1,0xec($sp)
/*  f0c335c:	8fa300ec */ 	lw	$v1,0xec($sp)
/*  f0c3360:	10000026 */ 	beqz	$zero,.NB0f0c33fc
/*  f0c3364:	8e020284 */ 	lw	$v0,0x284($s0)
.NB0f0c3368:
/*  f0c3368:	8e190284 */ 	lw	$t9,0x284($s0)
/*  f0c336c:	3c017f1a */ 	lui	$at,0x7f1a
/*  f0c3370:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f0c3374:	e7320080 */ 	swc1	$f18,0x80($t9)
/*  f0c3378:	8e020284 */ 	lw	$v0,0x284($s0)
/*  f0c337c:	8c490030 */ 	lw	$t1,0x30($v0)
/*  f0c3380:	11200003 */ 	beqz	$t1,.NB0f0c3390
/*  f0c3384:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c3388:	ac400030 */ 	sw	$zero,0x30($v0)
/*  f0c338c:	8e020284 */ 	lw	$v0,0x284($s0)
.NB0f0c3390:
/*  f0c3390:	c4247b08 */ 	lwc1	$f4,0x7b08($at)
/*  f0c3394:	c4460074 */ 	lwc1	$f6,0x74($v0)
/*  f0c3398:	4604303e */ 	c.le.s	$f6,$f4
/*  f0c339c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c33a0:	45020017 */ 	bc1fl	.NB0f0c3400
/*  f0c33a4:	c44e0080 */ 	lwc1	$f14,0x80($v0)
/*  f0c33a8:	0fc2fbde */ 	jal	currentPlayerDie
/*  f0c33ac:	afa300ec */ 	sw	$v1,0xec($sp)
/*  f0c33b0:	8fa300ec */ 	lw	$v1,0xec($sp)
/*  f0c33b4:	10000011 */ 	beqz	$zero,.NB0f0c33fc
/*  f0c33b8:	8e020284 */ 	lw	$v0,0x284($s0)
/*  f0c33bc:	8c4a0030 */ 	lw	$t2,0x30($v0)
.NB0f0c33c0:
/*  f0c33c0:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f0c33c4:	11400004 */ 	beqz	$t2,.NB0f0c33d8
/*  f0c33c8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c33cc:	ac400030 */ 	sw	$zero,0x30($v0)
/*  f0c33d0:	8e020284 */ 	lw	$v0,0x284($s0)
/*  f0c33d4:	c4420074 */ 	lwc1	$f2,0x74($v0)
.NB0f0c33d8:
/*  f0c33d8:	c42a7b0c */ 	lwc1	$f10,0x7b0c($at)
/*  f0c33dc:	460a103e */ 	c.le.s	$f2,$f10
/*  f0c33e0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c33e4:	45020006 */ 	bc1fl	.NB0f0c3400
/*  f0c33e8:	c44e0080 */ 	lwc1	$f14,0x80($v0)
/*  f0c33ec:	0fc2fbde */ 	jal	currentPlayerDie
/*  f0c33f0:	afa300ec */ 	sw	$v1,0xec($sp)
/*  f0c33f4:	8fa300ec */ 	lw	$v1,0xec($sp)
/*  f0c33f8:	8e020284 */ 	lw	$v0,0x284($s0)
.NB0f0c33fc:
/*  f0c33fc:	c44e0080 */ 	lwc1	$f14,0x80($v0)
.NB0f0c3400:
/*  f0c3400:	44804000 */ 	mtc1	$zero,$f8
/*  f0c3404:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c3408:	4608703c */ 	c.lt.s	$f14,$f8
/*  f0c340c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c3410:	450200c5 */ 	bc1fl	.NB0f0c3728
/*  f0c3414:	8e090034 */ 	lw	$t1,0x34($s0)
/*  f0c3418:	c4440078 */ 	lwc1	$f4,0x78($v0)
/*  f0c341c:	c4460074 */ 	lwc1	$f6,0x74($v0)
/*  f0c3420:	3c017f1a */ 	lui	$at,0x7f1a
/*  f0c3424:	4604303e */ 	c.le.s	$f6,$f4
/*  f0c3428:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c342c:	450200be */ 	bc1fl	.NB0f0c3728
/*  f0c3430:	8e090034 */ 	lw	$t1,0x34($s0)
/*  f0c3434:	8c4b0030 */ 	lw	$t3,0x30($v0)
/*  f0c3438:	240c003c */ 	addiu	$t4,$zero,0x3c
/*  f0c343c:	11600004 */ 	beqz	$t3,.NB0f0c3450
/*  f0c3440:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c3444:	ac400030 */ 	sw	$zero,0x30($v0)
/*  f0c3448:	8e020284 */ 	lw	$v0,0x284($s0)
/*  f0c344c:	c44e0080 */ 	lwc1	$f14,0x80($v0)
.NB0f0c3450:
/*  f0c3450:	c42a7b10 */ 	lwc1	$f10,0x7b10($at)
/*  f0c3454:	3c01c0a0 */ 	lui	$at,0xc0a0
/*  f0c3458:	460a703c */ 	c.lt.s	$f14,$f10
/*  f0c345c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c3460:	4502000a */ 	bc1fl	.NB0f0c348c
/*  f0c3464:	44810000 */ 	mtc1	$at,$f0
/*  f0c3468:	ac4c0090 */ 	sw	$t4,0x90($v0)
/*  f0c346c:	3c01c2b4 */ 	lui	$at,0xc2b4
/*  f0c3470:	44814000 */ 	mtc1	$at,$f8
/*  f0c3474:	8e0d0284 */ 	lw	$t5,0x284($s0)
/*  f0c3478:	e5a80094 */ 	swc1	$f8,0x94($t5)
/*  f0c347c:	8e020284 */ 	lw	$v0,0x284($s0)
/*  f0c3480:	10000014 */ 	beqz	$zero,.NB0f0c34d4
/*  f0c3484:	c44e0080 */ 	lwc1	$f14,0x80($v0)
/*  f0c3488:	44810000 */ 	mtc1	$at,$f0
.NB0f0c348c:
/*  f0c348c:	240e003c */ 	addiu	$t6,$zero,0x3c
/*  f0c3490:	4600703c */ 	c.lt.s	$f14,$f0
/*  f0c3494:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c3498:	4502000f */ 	bc1fl	.NB0f0c34d8
/*  f0c349c:	3c01c0c0 */ 	lui	$at,0xc0c0
/*  f0c34a0:	ac4e0090 */ 	sw	$t6,0x90($v0)
/*  f0c34a4:	8e020284 */ 	lw	$v0,0x284($s0)
/*  f0c34a8:	3c01c2b4 */ 	lui	$at,0xc2b4
/*  f0c34ac:	44815000 */ 	mtc1	$at,$f10
/*  f0c34b0:	c4440080 */ 	lwc1	$f4,0x80($v0)
/*  f0c34b4:	3c017f1a */ 	lui	$at,0x7f1a
/*  f0c34b8:	46040181 */ 	sub.s	$f6,$f0,$f4
/*  f0c34bc:	c4247b14 */ 	lwc1	$f4,0x7b14($at)
/*  f0c34c0:	460a3202 */ 	mul.s	$f8,$f6,$f10
/*  f0c34c4:	46044183 */ 	div.s	$f6,$f8,$f4
/*  f0c34c8:	e4460094 */ 	swc1	$f6,0x94($v0)
/*  f0c34cc:	8e020284 */ 	lw	$v0,0x284($s0)
/*  f0c34d0:	c44e0080 */ 	lwc1	$f14,0x80($v0)
.NB0f0c34d4:
/*  f0c34d4:	3c01c0c0 */ 	lui	$at,0xc0c0
.NB0f0c34d8:
/*  f0c34d8:	44815000 */ 	mtc1	$at,$f10
/*  f0c34dc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c34e0:	460a703c */ 	c.lt.s	$f14,$f10
/*  f0c34e4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c34e8:	4502008c */ 	bc1fl	.NB0f0c371c
/*  f0c34ec:	44804000 */ 	mtc1	$zero,$f8
/*  f0c34f0:	8c4f00bc */ 	lw	$t7,0xbc($v0)
/*  f0c34f4:	9058161e */ 	lbu	$t8,0x161e($v0)
/*  f0c34f8:	24190001 */ 	addiu	$t9,$zero,0x1
/*  f0c34fc:	8de40004 */ 	lw	$a0,0x4($t7)
/*  f0c3500:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f0c3504:	a0980191 */ 	sb	$t8,0x191($a0)
/*  f0c3508:	a0990190 */ 	sb	$t9,0x190($a0)
/*  f0c350c:	afa300ec */ 	sw	$v1,0xec($sp)
/*  f0c3510:	0fc01771 */ 	jal	chrChooseFootstepSound
/*  f0c3514:	afa40070 */ 	sw	$a0,0x70($sp)
/*  f0c3518:	2401ffff */ 	addiu	$at,$zero,-1
/*  f0c351c:	10410043 */ 	beq	$v0,$at,.NB0f0c362c
/*  f0c3520:	8fa300ec */ 	lw	$v1,0xec($sp)
/*  f0c3524:	2401ffff */ 	addiu	$at,$zero,-1
/*  f0c3528:	1041001a */ 	beq	$v0,$at,.NB0f0c3594
/*  f0c352c:	00002025 */ 	or	$a0,$zero,$zero
/*  f0c3530:	8e090284 */ 	lw	$t1,0x284($s0)
/*  f0c3534:	3c01bf80 */ 	lui	$at,0xbf80
/*  f0c3538:	44810000 */ 	mtc1	$at,$f0
/*  f0c353c:	8d2500bc */ 	lw	$a1,0xbc($t1)
/*  f0c3540:	00023400 */ 	sll	$a2,$v0,0x10
/*  f0c3544:	00065403 */ 	sra	$t2,$a2,0x10
/*  f0c3548:	240bffff */ 	addiu	$t3,$zero,-1
/*  f0c354c:	340c8400 */ 	dli	$t4,0x8400
/*  f0c3550:	240dffff */ 	addiu	$t5,$zero,-1
/*  f0c3554:	afad002c */ 	sw	$t5,0x2c($sp)
/*  f0c3558:	afac0014 */ 	sw	$t4,0x14($sp)
/*  f0c355c:	afab0010 */ 	sw	$t3,0x10($sp)
/*  f0c3560:	01403025 */ 	or	$a2,$t2,$zero
/*  f0c3564:	afa300ec */ 	sw	$v1,0xec($sp)
/*  f0c3568:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f0c356c:	afa00020 */ 	sw	$zero,0x20($sp)
/*  f0c3570:	afa0001c */ 	sw	$zero,0x1c($sp)
/*  f0c3574:	afa00018 */ 	sw	$zero,0x18($sp)
/*  f0c3578:	2407ffff */ 	addiu	$a3,$zero,-1
/*  f0c357c:	e7a00038 */ 	swc1	$f0,0x38($sp)
/*  f0c3580:	e7a00034 */ 	swc1	$f0,0x34($sp)
/*  f0c3584:	e7a00030 */ 	swc1	$f0,0x30($sp)
/*  f0c3588:	0fc24762 */ 	jal	func0f0939f8
/*  f0c358c:	e7a00024 */ 	swc1	$f0,0x24($sp)
/*  f0c3590:	8fa300ec */ 	lw	$v1,0xec($sp)
.NB0f0c3594:
/*  f0c3594:	8fa40070 */ 	lw	$a0,0x70($sp)
/*  f0c3598:	240e0002 */ 	addiu	$t6,$zero,0x2
/*  f0c359c:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f0c35a0:	a08e0190 */ 	sb	$t6,0x190($a0)
/*  f0c35a4:	0fc01771 */ 	jal	chrChooseFootstepSound
/*  f0c35a8:	afa300ec */ 	sw	$v1,0xec($sp)
/*  f0c35ac:	2401ffff */ 	addiu	$at,$zero,-1
/*  f0c35b0:	1041001e */ 	beq	$v0,$at,.NB0f0c362c
/*  f0c35b4:	8fa300ec */ 	lw	$v1,0xec($sp)
/*  f0c35b8:	8e0f0284 */ 	lw	$t7,0x284($s0)
/*  f0c35bc:	3c01bf80 */ 	lui	$at,0xbf80
/*  f0c35c0:	44814000 */ 	mtc1	$at,$f8
/*  f0c35c4:	8de500bc */ 	lw	$a1,0xbc($t7)
/*  f0c35c8:	44812000 */ 	mtc1	$at,$f4
/*  f0c35cc:	44813000 */ 	mtc1	$at,$f6
/*  f0c35d0:	44815000 */ 	mtc1	$at,$f10
/*  f0c35d4:	00023400 */ 	sll	$a2,$v0,0x10
/*  f0c35d8:	0006c403 */ 	sra	$t8,$a2,0x10
/*  f0c35dc:	2419ffff */ 	addiu	$t9,$zero,-1
/*  f0c35e0:	34098400 */ 	dli	$t1,0x8400
/*  f0c35e4:	240affff */ 	addiu	$t2,$zero,-1
/*  f0c35e8:	afaa002c */ 	sw	$t2,0x2c($sp)
/*  f0c35ec:	afa90014 */ 	sw	$t1,0x14($sp)
/*  f0c35f0:	afb90010 */ 	sw	$t9,0x10($sp)
/*  f0c35f4:	03003025 */ 	or	$a2,$t8,$zero
/*  f0c35f8:	afa300ec */ 	sw	$v1,0xec($sp)
/*  f0c35fc:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f0c3600:	afa00020 */ 	sw	$zero,0x20($sp)
/*  f0c3604:	afa0001c */ 	sw	$zero,0x1c($sp)
/*  f0c3608:	afa00018 */ 	sw	$zero,0x18($sp)
/*  f0c360c:	00002025 */ 	or	$a0,$zero,$zero
/*  f0c3610:	2407ffff */ 	addiu	$a3,$zero,-1
/*  f0c3614:	e7a80024 */ 	swc1	$f8,0x24($sp)
/*  f0c3618:	e7a40030 */ 	swc1	$f4,0x30($sp)
/*  f0c361c:	e7a60034 */ 	swc1	$f6,0x34($sp)
/*  f0c3620:	0fc24762 */ 	jal	func0f0939f8
/*  f0c3624:	e7aa0038 */ 	swc1	$f10,0x38($sp)
/*  f0c3628:	8fa300ec */ 	lw	$v1,0xec($sp)
.NB0f0c362c:
/*  f0c362c:	8e0b0314 */ 	lw	$t3,0x314($s0)
/*  f0c3630:	8fac0070 */ 	lw	$t4,0x70($sp)
/*  f0c3634:	55600039 */ 	bnezl	$t3,.NB0f0c371c
/*  f0c3638:	44804000 */ 	mtc1	$zero,$f8
/*  f0c363c:	81820006 */ 	lb	$v0,0x6($t4)
/*  f0c3640:	24010004 */ 	addiu	$at,$zero,0x4
/*  f0c3644:	10410003 */ 	beq	$v0,$at,.NB0f0c3654
/*  f0c3648:	2401000c */ 	addiu	$at,$zero,0xc
/*  f0c364c:	54410033 */ 	bnel	$v0,$at,.NB0f0c371c
/*  f0c3650:	44804000 */ 	mtc1	$zero,$f8
.NB0f0c3654:
/*  f0c3654:	8e0e0284 */ 	lw	$t6,0x284($s0)
/*  f0c3658:	8e0d0008 */ 	lw	$t5,0x8($s0)
/*  f0c365c:	3c098007 */ 	lui	$t1,0x8007
/*  f0c3660:	8dcf0034 */ 	lw	$t7,0x34($t6)
/*  f0c3664:	25293510 */ 	addiu	$t1,$t1,0x3510
/*  f0c3668:	01afc023 */ 	subu	$t8,$t5,$t7
/*  f0c366c:	2b010029 */ 	slti	$at,$t8,0x29
/*  f0c3670:	5420002a */ 	bnezl	$at,.NB0f0c371c
/*  f0c3674:	44804000 */ 	mtc1	$zero,$f8
/*  f0c3678:	8d210000 */ 	lw	$at,0x0($t1)
/*  f0c367c:	27b90064 */ 	addiu	$t9,$sp,0x64
/*  f0c3680:	8d2b0004 */ 	lw	$t3,0x4($t1)
/*  f0c3684:	af210000 */ 	sw	$at,0x0($t9)
/*  f0c3688:	8d210008 */ 	lw	$at,0x8($t1)
/*  f0c368c:	af2b0004 */ 	sw	$t3,0x4($t9)
/*  f0c3690:	af210008 */ 	sw	$at,0x8($t9)
/*  f0c3694:	0c004d84 */ 	jal	random
/*  f0c3698:	afa300ec */ 	sw	$v1,0xec($sp)
/*  f0c369c:	24010003 */ 	addiu	$at,$zero,0x3
/*  f0c36a0:	0041001b */ 	divu	$zero,$v0,$at
/*  f0c36a4:	8e0c0284 */ 	lw	$t4,0x284($s0)
/*  f0c36a8:	00007010 */ 	mfhi	$t6
/*  f0c36ac:	000e6880 */ 	sll	$t5,$t6,0x2
/*  f0c36b0:	03ad3021 */ 	addu	$a2,$sp,$t5
/*  f0c36b4:	84c60066 */ 	lh	$a2,0x66($a2)
/*  f0c36b8:	8d8500bc */ 	lw	$a1,0xbc($t4)
/*  f0c36bc:	3c01bf80 */ 	lui	$at,0xbf80
/*  f0c36c0:	44814000 */ 	mtc1	$at,$f8
/*  f0c36c4:	44812000 */ 	mtc1	$at,$f4
/*  f0c36c8:	44813000 */ 	mtc1	$at,$f6
/*  f0c36cc:	44815000 */ 	mtc1	$at,$f10
/*  f0c36d0:	240fffff */ 	addiu	$t7,$zero,-1
/*  f0c36d4:	34188400 */ 	dli	$t8,0x8400
/*  f0c36d8:	240affff */ 	addiu	$t2,$zero,-1
/*  f0c36dc:	afaa002c */ 	sw	$t2,0x2c($sp)
/*  f0c36e0:	afb80014 */ 	sw	$t8,0x14($sp)
/*  f0c36e4:	afaf0010 */ 	sw	$t7,0x10($sp)
/*  f0c36e8:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f0c36ec:	afa00020 */ 	sw	$zero,0x20($sp)
/*  f0c36f0:	afa0001c */ 	sw	$zero,0x1c($sp)
/*  f0c36f4:	afa00018 */ 	sw	$zero,0x18($sp)
/*  f0c36f8:	00002025 */ 	or	$a0,$zero,$zero
/*  f0c36fc:	2407ffff */ 	addiu	$a3,$zero,-1
/*  f0c3700:	e7a80024 */ 	swc1	$f8,0x24($sp)
/*  f0c3704:	e7a40030 */ 	swc1	$f4,0x30($sp)
/*  f0c3708:	e7a60034 */ 	swc1	$f6,0x34($sp)
/*  f0c370c:	0fc24762 */ 	jal	func0f0939f8
/*  f0c3710:	e7aa0038 */ 	swc1	$f10,0x38($sp)
/*  f0c3714:	8fa300ec */ 	lw	$v1,0xec($sp)
/*  f0c3718:	44804000 */ 	mtc1	$zero,$f8
.NB0f0c371c:
/*  f0c371c:	8e190284 */ 	lw	$t9,0x284($s0)
/*  f0c3720:	e7280080 */ 	swc1	$f8,0x80($t9)
/*  f0c3724:	8e090034 */ 	lw	$t1,0x34($s0)
.NB0f0c3728:
/*  f0c3728:	3c01bf90 */ 	lui	$at,0xbf90
/*  f0c372c:	27a600a8 */ 	addiu	$a2,$sp,0xa8
/*  f0c3730:	1920002c */ 	blez	$t1,.NB0f0c37e4
/*  f0c3734:	27a70098 */ 	addiu	$a3,$sp,0x98
/*  f0c3738:	44816000 */ 	mtc1	$at,$f12
/*  f0c373c:	3c017f1a */ 	lui	$at,0x7f1a
/*  f0c3740:	44809000 */ 	mtc1	$zero,$f18
/*  f0c3744:	c4227b18 */ 	lwc1	$f2,0x7b18($at)
/*  f0c3748:	8e020284 */ 	lw	$v0,0x284($s0)
.NB0f0c374c:
/*  f0c374c:	8c4b0090 */ 	lw	$t3,0x90($v0)
/*  f0c3750:	5960000c */ 	blezl	$t3,.NB0f0c3784
/*  f0c3754:	c4400094 */ 	lwc1	$f0,0x94($v0)
/*  f0c3758:	c4440088 */ 	lwc1	$f4,0x88($v0)
/*  f0c375c:	c44a0094 */ 	lwc1	$f10,0x94($v0)
/*  f0c3760:	46022182 */ 	mul.s	$f6,$f4,$f2
/*  f0c3764:	460a3200 */ 	add.s	$f8,$f6,$f10
/*  f0c3768:	e4480088 */ 	swc1	$f8,0x88($v0)
/*  f0c376c:	8e020284 */ 	lw	$v0,0x284($s0)
/*  f0c3770:	8c4c0090 */ 	lw	$t4,0x90($v0)
/*  f0c3774:	258effff */ 	addiu	$t6,$t4,-1
/*  f0c3778:	10000015 */ 	beqz	$zero,.NB0f0c37d0
/*  f0c377c:	ac4e0090 */ 	sw	$t6,0x90($v0)
/*  f0c3780:	c4400094 */ 	lwc1	$f0,0x94($v0)
.NB0f0c3784:
/*  f0c3784:	4612003c */ 	c.lt.s	$f0,$f18
/*  f0c3788:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c378c:	4502000d */ 	bc1fl	.NB0f0c37c4
/*  f0c3790:	c4460088 */ 	lwc1	$f6,0x88($v0)
/*  f0c3794:	460c0101 */ 	sub.s	$f4,$f0,$f12
/*  f0c3798:	e4440094 */ 	swc1	$f4,0x94($v0)
/*  f0c379c:	8e020284 */ 	lw	$v0,0x284($s0)
/*  f0c37a0:	c4400094 */ 	lwc1	$f0,0x94($v0)
/*  f0c37a4:	4600903e */ 	c.le.s	$f18,$f0
/*  f0c37a8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c37ac:	45020005 */ 	bc1fl	.NB0f0c37c4
/*  f0c37b0:	c4460088 */ 	lwc1	$f6,0x88($v0)
/*  f0c37b4:	e4520094 */ 	swc1	$f18,0x94($v0)
/*  f0c37b8:	8e020284 */ 	lw	$v0,0x284($s0)
/*  f0c37bc:	c4400094 */ 	lwc1	$f0,0x94($v0)
/*  f0c37c0:	c4460088 */ 	lwc1	$f6,0x88($v0)
.NB0f0c37c4:
/*  f0c37c4:	46023282 */ 	mul.s	$f10,$f6,$f2
/*  f0c37c8:	46005200 */ 	add.s	$f8,$f10,$f0
/*  f0c37cc:	e4480088 */ 	swc1	$f8,0x88($v0)
.NB0f0c37d0:
/*  f0c37d0:	8e0d0034 */ 	lw	$t5,0x34($s0)
/*  f0c37d4:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f0c37d8:	006d082a */ 	slt	$at,$v1,$t5
/*  f0c37dc:	5420ffdb */ 	bnezl	$at,.NB0f0c374c
/*  f0c37e0:	8e020284 */ 	lw	$v0,0x284($s0)
.NB0f0c37e4:
/*  f0c37e4:	8e020284 */ 	lw	$v0,0x284($s0)
/*  f0c37e8:	3c0141f0 */ 	lui	$at,0x41f0
/*  f0c37ec:	44811000 */ 	mtc1	$at,$f2
/*  f0c37f0:	3c017f1a */ 	lui	$at,0x7f1a
/*  f0c37f4:	c4267b1c */ 	lwc1	$f6,0x7b1c($at)
/*  f0c37f8:	c4440088 */ 	lwc1	$f4,0x88($v0)
/*  f0c37fc:	3c017f1a */ 	lui	$at,0x7f1a
/*  f0c3800:	46062282 */ 	mul.s	$f10,$f4,$f6
/*  f0c3804:	e44a008c */ 	swc1	$f10,0x8c($v0)
/*  f0c3808:	8e020284 */ 	lw	$v0,0x284($s0)
/*  f0c380c:	c44803c4 */ 	lwc1	$f8,0x3c4($v0)
/*  f0c3810:	c4440414 */ 	lwc1	$f4,0x414($v0)
/*  f0c3814:	c44a19c4 */ 	lwc1	$f10,0x19c4($v0)
/*  f0c3818:	46044183 */ 	div.s	$f6,$f8,$f4
/*  f0c381c:	460a3202 */ 	mul.s	$f8,$f6,$f10
/*  f0c3820:	e44819bc */ 	swc1	$f8,0x19bc($v0)
/*  f0c3824:	8e020284 */ 	lw	$v0,0x284($s0)
/*  f0c3828:	8c4f19b8 */ 	lw	$t7,0x19b8($v0)
/*  f0c382c:	c44419bc */ 	lwc1	$f4,0x19bc($v0)
/*  f0c3830:	448f3000 */ 	mtc1	$t7,$f6
/*  f0c3834:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c3838:	468032a0 */ 	cvt.s.w	$f10,$f6
/*  f0c383c:	c446008c */ 	lwc1	$f6,0x8c($v0)
/*  f0c3840:	460a2200 */ 	add.s	$f8,$f4,$f10
/*  f0c3844:	c44419c4 */ 	lwc1	$f4,0x19c4($v0)
/*  f0c3848:	46043282 */ 	mul.s	$f10,$f6,$f4
/*  f0c384c:	c4267b20 */ 	lwc1	$f6,0x7b20($at)
/*  f0c3850:	46065102 */ 	mul.s	$f4,$f10,$f6
/*  f0c3854:	46044000 */ 	add.s	$f0,$f8,$f4
/*  f0c3858:	4602003c */ 	c.lt.s	$f0,$f2
/*  f0c385c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c3860:	45020003 */ 	bc1fl	.NB0f0c3870
/*  f0c3864:	8c5800bc */ 	lw	$t8,0xbc($v0)
/*  f0c3868:	46001006 */ 	mov.s	$f0,$f2
/*  f0c386c:	8c5800bc */ 	lw	$t8,0xbc($v0)
.NB0f0c3870:
/*  f0c3870:	c70a0008 */ 	lwc1	$f10,0x8($t8)
/*  f0c3874:	e7aa00a8 */ 	swc1	$f10,0xa8($sp)
/*  f0c3878:	c4460074 */ 	lwc1	$f6,0x74($v0)
/*  f0c387c:	c7aa00a8 */ 	lwc1	$f10,0xa8($sp)
/*  f0c3880:	46003200 */ 	add.s	$f8,$f6,$f0
/*  f0c3884:	e7a800ac */ 	swc1	$f8,0xac($sp)
/*  f0c3888:	8c4a00bc */ 	lw	$t2,0xbc($v0)
/*  f0c388c:	c7a800ac */ 	lwc1	$f8,0xac($sp)
/*  f0c3890:	c5440010 */ 	lwc1	$f4,0x10($t2)
/*  f0c3894:	e7a400b0 */ 	swc1	$f4,0xb0($sp)
/*  f0c3898:	8c4300bc */ 	lw	$v1,0xbc($v0)
/*  f0c389c:	c4660008 */ 	lwc1	$f6,0x8($v1)
/*  f0c38a0:	24640008 */ 	addiu	$a0,$v1,0x8
/*  f0c38a4:	46065032 */ 	c.eq.s	$f10,$f6
/*  f0c38a8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c38ac:	4500000c */ 	bc1f	.NB0f0c38e0
/*  f0c38b0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c38b4:	c464000c */ 	lwc1	$f4,0xc($v1)
/*  f0c38b8:	c7aa00b0 */ 	lwc1	$f10,0xb0($sp)
/*  f0c38bc:	46044032 */ 	c.eq.s	$f8,$f4
/*  f0c38c0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c38c4:	45000006 */ 	bc1f	.NB0f0c38e0
/*  f0c38c8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c38cc:	c4660010 */ 	lwc1	$f6,0x10($v1)
/*  f0c38d0:	46065032 */ 	c.eq.s	$f10,$f6
/*  f0c38d4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c38d8:	45030018 */ 	bc1tl	.NB0f0c393c
/*  f0c38dc:	8fbf004c */ 	lw	$ra,0x4c($sp)
.NB0f0c38e0:
/*  f0c38e0:	0fc19437 */ 	jal	func0f065e74
/*  f0c38e4:	24650028 */ 	addiu	$a1,$v1,0x28
/*  f0c38e8:	8e190284 */ 	lw	$t9,0x284($s0)
/*  f0c38ec:	c7a800a8 */ 	lwc1	$f8,0xa8($sp)
/*  f0c38f0:	8f2900bc */ 	lw	$t1,0xbc($t9)
/*  f0c38f4:	e5280008 */ 	swc1	$f8,0x8($t1)
/*  f0c38f8:	8e0b0284 */ 	lw	$t3,0x284($s0)
/*  f0c38fc:	c7a400ac */ 	lwc1	$f4,0xac($sp)
/*  f0c3900:	8d6c00bc */ 	lw	$t4,0xbc($t3)
/*  f0c3904:	e584000c */ 	swc1	$f4,0xc($t4)
/*  f0c3908:	8e0e0284 */ 	lw	$t6,0x284($s0)
/*  f0c390c:	c7aa00b0 */ 	lwc1	$f10,0xb0($sp)
/*  f0c3910:	8dcd00bc */ 	lw	$t5,0xbc($t6)
/*  f0c3914:	e5aa0010 */ 	swc1	$f10,0x10($t5)
/*  f0c3918:	8e0f0284 */ 	lw	$t7,0x284($s0)
/*  f0c391c:	0fc193ab */ 	jal	func0f065c44
/*  f0c3920:	8de400bc */ 	lw	$a0,0xbc($t7)
/*  f0c3924:	8e180284 */ 	lw	$t8,0x284($s0)
/*  f0c3928:	27a40098 */ 	addiu	$a0,$sp,0x98
/*  f0c392c:	8f0500bc */ 	lw	$a1,0xbc($t8)
/*  f0c3930:	0fc19283 */ 	jal	roomsCopy
/*  f0c3934:	24a50028 */ 	addiu	$a1,$a1,0x28
/*  f0c3938:	8fbf004c */ 	lw	$ra,0x4c($sp)
.NB0f0c393c:
/*  f0c393c:	8fb00048 */ 	lw	$s0,0x48($sp)
/*  f0c3940:	27bd00f0 */ 	addiu	$sp,$sp,0xf0
/*  f0c3944:	03e00008 */ 	jr	$ra
/*  f0c3948:	00000000 */ 	sll	$zero,$zero,0x0
);
#endif

void bwalkApplyCrouchSpeed(void)
{
	if (bmoveGetCrouchPos() == CROUCHPOS_DUCK) {
		g_Vars.currentplayer->speedforwards *= 0.5f;
		g_Vars.currentplayer->speedsideways *= 0.5f;
	} else if (bmoveGetCrouchPos() == CROUCHPOS_SQUAT) {
		g_Vars.currentplayer->speedforwards *= 0.35f;
		g_Vars.currentplayer->speedsideways *= 0.35f;
	}
}

void bwalkUpdateCrouchOffsetReal(void)
{
	if (g_Vars.currentplayer->vv_eyeheight + -90.0f * g_Vars.currentplayer->vv_eyeheight * (1.0f / 159.0f) < 69.0f) {
		g_Vars.currentplayer->crouchoffsetreal = g_Vars.currentplayer->crouchoffset * ((69.0f - g_Vars.currentplayer->vv_eyeheight) / -90.0f);
	} else {
		g_Vars.currentplayer->crouchoffsetreal = g_Vars.currentplayer->crouchoffset * g_Vars.currentplayer->vv_eyeheight * (1.0f / 159.0f);
	}

	if (cheatIsActive(CHEAT_SMALLJO)) {
		g_Vars.currentplayer->crouchoffsetsmall = 69.0f - g_Vars.currentplayer->vv_eyeheight;
		g_Vars.currentplayer->crouchoffsetrealsmall = 69.0f - g_Vars.currentplayer->vv_eyeheight;
	} else {
		g_Vars.currentplayer->crouchoffsetsmall = g_Vars.currentplayer->crouchoffset;
		g_Vars.currentplayer->crouchoffsetrealsmall = g_Vars.currentplayer->crouchoffsetreal;
	}
}

void bwalkUpdateCrouchOffset(void)
{
	f32 targetoffset = 0;

	if (bmoveGetCrouchPos() == CROUCHPOS_SQUAT) {
		targetoffset = -90;
	} else if (bmoveGetCrouchPos() == CROUCHPOS_DUCK) {
		targetoffset = -45;
	} else if (bmoveGetCrouchPos() == CROUCHPOS_STAND) {
		// empty
	}

	if (targetoffset != g_Vars.currentplayer->crouchoffset) {
		f32 prevcrouchoffset = g_Vars.currentplayer->crouchoffset;
		f32 prevcrouchoffsetreal = g_Vars.currentplayer->crouchoffsetreal;
		f32 prevcrouchoffsetsmall = g_Vars.currentplayer->crouchoffsetsmall;
		f32 prevcrouchoffsetrealsmall = g_Vars.currentplayer->crouchoffsetrealsmall;

		// f32 *frac, f32 maxfrac, f32 *fracspeed, f32 accel, f32 decel, f32 maxspeed
		applySpeed(&g_Vars.currentplayer->crouchoffset, targetoffset,
				&g_Vars.currentplayer->crouchspeed, PALUPF(0.5f), PALUPF(0.5f), PALUPF(5.0f));

		bwalkUpdateCrouchOffsetReal();

		if (bwalkTryMoveUpwards(0) == CDRESULT_COLLISION) {
			// Crouch adjustment is blocked by ceiling
			g_Vars.currentplayer->crouchoffset = prevcrouchoffset;
			g_Vars.currentplayer->crouchoffsetreal = prevcrouchoffsetreal;
			g_Vars.currentplayer->crouchoffsetsmall = prevcrouchoffsetsmall;
			g_Vars.currentplayer->crouchoffsetrealsmall = prevcrouchoffsetrealsmall;
			g_Vars.currentplayer->crouchspeed = 0;
			bwalkAdjustCrouchPos(-1);
		}
	}

	if (targetoffset == g_Vars.currentplayer->crouchoffset) {
		g_Vars.currentplayer->crouchspeed = 0;
	}

	g_Vars.currentplayer->guncloseroffset = g_Vars.currentplayer->crouchoffset / -90;
}

void bwalkUpdateTheta(void)
{
	f32 mult;
	f32 rotateamount;
	struct coord delta = {0, 0, 0};

	// Turn speed is calculated from the chr's height
	mult = 159.0f / g_Vars.currentplayer->vv_eyeheight;
	rotateamount = g_Vars.currentplayer->speedtheta * mult
		* g_Vars.lvupdate240freal * 0.0174505133f * 3.5f;

	bwalkCalculateNewPositionWithPush(&delta, rotateamount, true, 0, CDTYPE_ALL);
}

u32 var80070e68 = 0x00000000;
u32 var80070e6c = 0x00000000;
u32 var80070e70 = 0x00000000;
u32 var80070e74 = 0x00000000;
u32 var80070e78 = 0x00000000;
u32 var80070e7c = 0x00000000;

void bwalk0f0c63bc(struct coord *arg0, u32 arg1, s32 types)
{
	struct coord sp100;
	struct coord sp88;

	g_Vars.currentplayer->bondonturret = false;
	g_Vars.currentplayer->autocrouchpos = CROUCHPOS_STAND;

	bwalk0f0c4d98();

	if (bwalk0f0c4764(arg0, &sp100, &sp88, types) == CDRESULT_COLLISION) {
		struct coord sp76;
		struct coord sp64;

		s32 result = bwalk0f0c47d0(arg0, &sp100, &sp88, &sp76, &sp64, types);

		if (result >= CDRESULT_NOCOLLISION || result <= CDRESULT_ERROR) {
			if (result >= CDRESULT_NOCOLLISION) {
				bwalk0f0c4d98();
			}

			if (arg1
					&& bwalk0f0c494c(arg0, &sp100, &sp88, types) <= CDRESULT_COLLISION
					&& bwalk0f0c4a5c(arg0, &sp100, &sp88, types) <= CDRESULT_COLLISION) {
				// empty
			}
		} else if (result == CDRESULT_COLLISION) {
			struct coord sp48;
			struct coord sp36;

			if (bwalk0f0c47d0(arg0, &sp76, &sp64, &sp48, &sp36, types) >= CDRESULT_NOCOLLISION) {
				bwalk0f0c4d98();
			}

			if (arg1
					&& bwalk0f0c494c(arg0, &sp76, &sp64, types) <= CDRESULT_COLLISION
					&& bwalk0f0c494c(arg0, &sp100, &sp88, types) <= CDRESULT_COLLISION
					&& bwalk0f0c4a5c(arg0, &sp76, &sp64, types) <= CDRESULT_COLLISION) {
				bwalk0f0c4a5c(arg0, &sp100, &sp88, types);
			}
		}
	}

	bwalk0f0c4d98();
}

void bwalkUpdatePrevPos(void)
{
	g_Vars.currentplayer->bondprevpos.x = g_Vars.currentplayer->prop->pos.x;
	g_Vars.currentplayer->bondprevpos.y = g_Vars.currentplayer->prop->pos.y;
	g_Vars.currentplayer->bondprevpos.z = g_Vars.currentplayer->prop->pos.z;

	roomsCopy(g_Vars.currentplayer->prop->rooms, g_Vars.currentplayer->bondprevrooms);
}

void bwalkHandleActivate(void)
{
	if (g_Vars.currentplayer->walkinitmove) {
		g_Vars.currentplayer->bondactivateorreload = 0;
	}
}

void bwalkApplyMoveData(struct movedata *data)
{
	if (g_Vars.currentplayer->walkinitmove == false) {
		// Sideways
		if (data->digitalstepleft) {
			bwalkUpdateSpeedSideways(-1, 0.2f, data->digitalstepleft);
		} else if (data->digitalstepright) {
			bwalkUpdateSpeedSideways(1, 0.2f, data->digitalstepright);
		} else if (data->unk14 == false) {
			bwalkUpdateSpeedSideways(0, 0.2f, g_Vars.lvupdate240_60);
		}

		if (data->unk14) {
			bwalkUpdateSpeedSideways(data->analogstrafe * 0.014285714365542f, 0.2f, g_Vars.lvupdate240_60);
		}

		// Forward/back
		if (data->digitalstepforward) {
			bwalkUpdateSpeedForwards(1, 1);
			g_Vars.currentplayer->speedmaxtime60 += g_Vars.lvupdate240_60;
		} else if (data->digitalstepback) {
			bwalkUpdateSpeedForwards(-1, 1);
		} else if (data->canlookahead == false) {
			bwalkUpdateSpeedForwards(0, 1);
		}

		if (data->canlookahead) {
			bwalkUpdateSpeedForwards(data->analogwalk * 0.014285714365542f, 1);

			if (data->analogwalk > 60) {
				g_Vars.currentplayer->speedmaxtime60 += g_Vars.lvupdate240_60;
			} else {
				g_Vars.currentplayer->speedmaxtime60 = 0;
			}
		}

		// Force speeds to range -1 to 1
		if (g_Vars.currentplayer->speedforwards > 1) {
			g_Vars.currentplayer->speedforwards = 1;
		}

		if (g_Vars.currentplayer->speedforwards < -1) {
			g_Vars.currentplayer->speedforwards = -1;
		}

		if (g_Vars.currentplayer->speedsideways > 1) {
			g_Vars.currentplayer->speedsideways = 1;
		}

		if (g_Vars.currentplayer->speedsideways < -1) {
			g_Vars.currentplayer->speedsideways = -1;
		}

		g_Vars.currentplayer->speedforwards *= 1.08f;
		g_Vars.currentplayer->speedforwards *= g_Vars.currentplayer->speedboost;

		if ((data->canlookahead == false && data->digitalstepforward == false) ||
				bmoveGetCrouchPos() != CROUCHPOS_STAND) {
			g_Vars.currentplayer->speedmaxtime60 = 0;
		}

		if (data->rleanleft) {
			bwalkSetSwayTarget(-1);
		} else if (data->rleanright) {
			bwalkSetSwayTarget(1);
		} else {
			bwalkSetSwayTarget(0);
		}

		while (data->crouchdown-- > 0) {
			bwalkAdjustCrouchPos(-1);
		}

		while (data->crouchup-- > 0) {
			bwalkAdjustCrouchPos(1);
		}

		g_Vars.currentplayer->eyesshut = data->eyesshut;
	}
}

void bwalkUpdateSpeedTheta(void)
{
	if (bmoveGetCrouchPos() == CROUCHPOS_SQUAT) {
		g_Vars.currentplayer->speedtheta *= 0.5f;
	} else if (bmoveGetCrouchPos() == CROUCHPOS_DUCK) {
		g_Vars.currentplayer->speedtheta *= 0.75f;
	}
}

#if VERSION >= VERSION_PAL_FINAL
GLOBAL_ASM(
glabel bwalk0f0c69b8
.late_rodata
glabel var7f1ad7fc
.word 0xc27e6668
glabel var7f1ad800
.word 0x43b0aaaa
glabel var7f1ad804
.word 0x3ecccccd
glabel var7f1ad808
.word 0x3c888889
glabel var7f1ad80c
.word 0x404907a9
glabel var7f1ad810
.word 0x3eb33333
glabel var7f1ad814
.word 0x3eb33333
glabel var7f1ad818
.word 0x4099999a
glabel var7f1ad81c
.word 0x3df5c290
glabel var7f1ad820
.word 0x3eb33333
glabel var7f1ad824
.word 0x3f4ccccd
glabel var7f1ad828
.word 0x3dcccccd
glabel var7f1ad82c
.word 0x3f4ccccd
glabel var7f1ad830
.word 0x4528c000
glabel var7f1ad834
.word 0x3ecccccd
glabel var7f1ad838
.word 0x3ecccccd
glabel var7f1ad83c
.word 0x3e99999a
glabel var7f1ad840
.word 0x3f8ccccd
glabel var7f1ad844
.word 0x3e99999a
glabel var7f1ad848
.word 0x3e99999a
glabel var7f1ad84c
.word 0x3f333333
glabel var7f1ad850
.word 0x3f99999a
glabel var7f1ad854
.word 0x3c8ef461
.text
/*  f0c6f60:	27bdff18 */ 	addiu	$sp,$sp,-232
/*  f0c6f64:	3c0f8007 */ 	lui	$t7,0x8007
/*  f0c6f68:	afbf0024 */ 	sw	$ra,0x24($sp)
/*  f0c6f6c:	f7b40018 */ 	sdc1	$f20,0x18($sp)
/*  f0c6f70:	25ef1148 */ 	addiu	$t7,$t7,0x1148
/*  f0c6f74:	8de10000 */ 	lw	$at,0x0($t7)
/*  f0c6f78:	27ae00cc */ 	addiu	$t6,$sp,0xcc
/*  f0c6f7c:	8de90004 */ 	lw	$t1,0x4($t7)
/*  f0c6f80:	adc10000 */ 	sw	$at,0x0($t6)
/*  f0c6f84:	8de10008 */ 	lw	$at,0x8($t7)
/*  f0c6f88:	3c08800a */ 	lui	$t0,0x800a
/*  f0c6f8c:	2508a510 */ 	addiu	$t0,$t0,-23280
/*  f0c6f90:	adc90004 */ 	sw	$t1,0x4($t6)
/*  f0c6f94:	adc10008 */ 	sw	$at,0x8($t6)
/*  f0c6f98:	8d0a0284 */ 	lw	$t2,0x284($t0)
/*  f0c6f9c:	3c01431f */ 	lui	$at,0x431f
/*  f0c6fa0:	44813000 */ 	mtc1	$at,$f6
/*  f0c6fa4:	c54419c4 */ 	lwc1	$f4,0x19c4($t2)
/*  f0c6fa8:	46062201 */ 	sub.s	$f8,$f4,$f6
/*  f0c6fac:	0fc44cc9 */ 	jal	invHasBriefcase
/*  f0c6fb0:	e7a800c0 */ 	swc1	$f8,0xc0($sp)
/*  f0c6fb4:	3c08800a */ 	lui	$t0,0x800a
/*  f0c6fb8:	1040000a */ 	beqz	$v0,.PF0f0c6fe4
/*  f0c6fbc:	2508a510 */ 	addiu	$t0,$t0,-23280
/*  f0c6fc0:	3c02800b */ 	lui	$v0,0x800b
/*  f0c6fc4:	9042d138 */ 	lbu	$v0,-0x2ec8($v0)
/*  f0c6fc8:	24010001 */ 	li	$at,0x1
/*  f0c6fcc:	10410002 */ 	beq	$v0,$at,.PF0f0c6fd8
/*  f0c6fd0:	24010005 */ 	li	$at,0x5
/*  f0c6fd4:	14410003 */ 	bne	$v0,$at,.PF0f0c6fe4
.PF0f0c6fd8:
/*  f0c6fd8:	3c017f1b */ 	lui	$at,0x7f1b
/*  f0c6fdc:	c420eacc */ 	lwc1	$f0,-0x1534($at)
/*  f0c6fe0:	e7a000c0 */ 	swc1	$f0,0xc0($sp)
.PF0f0c6fe4:
/*  f0c6fe4:	3c017f1b */ 	lui	$at,0x7f1b
/*  f0c6fe8:	c7a000c0 */ 	lwc1	$f0,0xc0($sp)
/*  f0c6fec:	c42aead0 */ 	lwc1	$f10,-0x1530($at)
/*  f0c6ff0:	8d0b0318 */ 	lw	$t3,0x318($t0)
/*  f0c6ff4:	3c013f80 */ 	lui	$at,0x3f80
/*  f0c6ff8:	460a0103 */ 	div.s	$f4,$f0,$f10
/*  f0c6ffc:	44813000 */ 	mtc1	$at,$f6
/*  f0c7000:	3c0c800b */ 	lui	$t4,0x800b
/*  f0c7004:	2404000a */ 	li	$a0,0xa
/*  f0c7008:	1160000a */ 	beqz	$t3,.PF0f0c7034
/*  f0c700c:	46062000 */ 	add.s	$f0,$f4,$f6
/*  f0c7010:	8d8cd134 */ 	lw	$t4,-0x2ecc($t4)
/*  f0c7014:	3c013fa0 */ 	lui	$at,0x3fa0
/*  f0c7018:	318d0100 */ 	andi	$t5,$t4,0x100
/*  f0c701c:	11a00005 */ 	beqz	$t5,.PF0f0c7034
/*  f0c7020:	00000000 */ 	nop
/*  f0c7024:	44814000 */ 	mtc1	$at,$f8
/*  f0c7028:	00000000 */ 	nop
/*  f0c702c:	46080002 */ 	mul.s	$f0,$f0,$f8
/*  f0c7030:	00000000 */ 	nop
.PF0f0c7034:
/*  f0c7034:	0fc41dd5 */ 	jal	cheatIsActive
/*  f0c7038:	e7a000c0 */ 	swc1	$f0,0xc0($sp)
/*  f0c703c:	3c08800a */ 	lui	$t0,0x800a
/*  f0c7040:	10400006 */ 	beqz	$v0,.PF0f0c705c
/*  f0c7044:	2508a510 */ 	addiu	$t0,$t0,-23280
/*  f0c7048:	3c017f1b */ 	lui	$at,0x7f1b
/*  f0c704c:	c424ead4 */ 	lwc1	$f4,-0x152c($at)
/*  f0c7050:	c7aa00c0 */ 	lwc1	$f10,0xc0($sp)
/*  f0c7054:	46045182 */ 	mul.s	$f6,$f10,$f4
/*  f0c7058:	e7a600c0 */ 	swc1	$f6,0xc0($sp)
.PF0f0c705c:
/*  f0c705c:	8d030284 */ 	lw	$v1,0x284($t0)
/*  f0c7060:	8c791af8 */ 	lw	$t9,0x1af8($v1)
/*  f0c7064:	1320003f */ 	beqz	$t9,.PF0f0c7164
/*  f0c7068:	3c013f80 */ 	lui	$at,0x3f80
/*  f0c706c:	44811000 */ 	mtc1	$at,$f2
/*  f0c7070:	3c017f1b */ 	lui	$at,0x7f1b
/*  f0c7074:	c42aead8 */ 	lwc1	$f10,-0x1528($at)
/*  f0c7078:	c508004c */ 	lwc1	$f8,0x4c($t0)
/*  f0c707c:	c4661b48 */ 	lwc1	$f6,0x1b48($v1)
/*  f0c7080:	3c017f1b */ 	lui	$at,0x7f1b
/*  f0c7084:	460a4102 */ 	mul.s	$f4,$f8,$f10
/*  f0c7088:	46043200 */ 	add.s	$f8,$f6,$f4
/*  f0c708c:	e4681b48 */ 	swc1	$f8,0x1b48($v1)
/*  f0c7090:	8d030284 */ 	lw	$v1,0x284($t0)
/*  f0c7094:	c4601b48 */ 	lwc1	$f0,0x1b48($v1)
/*  f0c7098:	4600103e */ 	c.le.s	$f2,$f0
/*  f0c709c:	00000000 */ 	nop
/*  f0c70a0:	45000006 */ 	bc1f	.PF0f0c70bc
/*  f0c70a4:	00000000 */ 	nop
/*  f0c70a8:	e4621b48 */ 	swc1	$f2,0x1b48($v1)
/*  f0c70ac:	8d180284 */ 	lw	$t8,0x284($t0)
/*  f0c70b0:	af001af8 */ 	sw	$zero,0x1af8($t8)
/*  f0c70b4:	8d0e0284 */ 	lw	$t6,0x284($t0)
/*  f0c70b8:	c5c01b48 */ 	lwc1	$f0,0x1b48($t6)
.PF0f0c70bc:
/*  f0c70bc:	c42aeadc */ 	lwc1	$f10,-0x1524($at)
/*  f0c70c0:	460a0302 */ 	mul.s	$f12,$f0,$f10
/*  f0c70c4:	0c006858 */ 	jal	cosf
/*  f0c70c8:	00000000 */ 	nop
/*  f0c70cc:	3c013f80 */ 	lui	$at,0x3f80
/*  f0c70d0:	44811000 */ 	mtc1	$at,$f2
/*  f0c70d4:	3c013f00 */ 	lui	$at,0x3f00
/*  f0c70d8:	44812000 */ 	mtc1	$at,$f4
/*  f0c70dc:	46020180 */ 	add.s	$f6,$f0,$f2
/*  f0c70e0:	3c08800a */ 	lui	$t0,0x800a
/*  f0c70e4:	2508a510 */ 	addiu	$t0,$t0,-23280
/*  f0c70e8:	8d0f0284 */ 	lw	$t7,0x284($t0)
/*  f0c70ec:	46043202 */ 	mul.s	$f8,$f6,$f4
/*  f0c70f0:	4480a000 */ 	mtc1	$zero,$f20
/*  f0c70f4:	00000000 */ 	nop
/*  f0c70f8:	4406a000 */ 	mfc1	$a2,$f20
/*  f0c70fc:	4600a306 */ 	mov.s	$f12,$f20
/*  f0c7100:	4600a386 */ 	mov.s	$f14,$f20
/*  f0c7104:	46081281 */ 	sub.s	$f10,$f2,$f8
/*  f0c7108:	e5ea1b4c */ 	swc1	$f10,0x1b4c($t7)
/*  f0c710c:	8d030284 */ 	lw	$v1,0x284($t0)
/*  f0c7110:	c4661b4c */ 	lwc1	$f6,0x1b4c($v1)
/*  f0c7114:	24671b08 */ 	addiu	$a3,$v1,0x1b08
/*  f0c7118:	46061101 */ 	sub.s	$f4,$f2,$f6
/*  f0c711c:	0fc33252 */ 	jal	bmoveUpdateHead
/*  f0c7120:	e7a40010 */ 	swc1	$f4,0x10($sp)
/*  f0c7124:	3c08800a */ 	lui	$t0,0x800a
/*  f0c7128:	2508a510 */ 	addiu	$t0,$t0,-23280
/*  f0c712c:	8d090284 */ 	lw	$t1,0x284($t0)
/*  f0c7130:	27a400cc */ 	addiu	$a0,$sp,0xcc
/*  f0c7134:	0fc33036 */ 	jal	bmoveUpdateMoveInitSpeed
/*  f0c7138:	e53400cc */ 	swc1	$f20,0xcc($t1)
/*  f0c713c:	4405a000 */ 	mfc1	$a1,$f20
/*  f0c7140:	4407a000 */ 	mfc1	$a3,$f20
/*  f0c7144:	240a003f */ 	li	$t2,0x3f
/*  f0c7148:	afaa0010 */ 	sw	$t2,0x10($sp)
/*  f0c714c:	27a400cc */ 	addiu	$a0,$sp,0xcc
/*  f0c7150:	0fc311f8 */ 	jal	bwalkCalculateNewPositionWithPush
/*  f0c7154:	24060001 */ 	li	$a2,0x1
/*  f0c7158:	3c08800a */ 	lui	$t0,0x800a
/*  f0c715c:	100002e6 */ 	b	.PF0f0c7cf8
/*  f0c7160:	2508a510 */ 	addiu	$t0,$t0,-23280
.PF0f0c7164:
/*  f0c7164:	0fc31964 */ 	jal	bwalkApplyCrouchSpeed
/*  f0c7168:	00000000 */ 	nop
/*  f0c716c:	0fc319ca */ 	jal	bwalkUpdateCrouchOffset
/*  f0c7170:	00000000 */ 	nop
/*  f0c7174:	3c08800a */ 	lui	$t0,0x800a
/*  f0c7178:	2508a510 */ 	addiu	$t0,$t0,-23280
/*  f0c717c:	8d030284 */ 	lw	$v1,0x284($t0)
/*  f0c7180:	27a400c8 */ 	addiu	$a0,$sp,0xc8
/*  f0c7184:	27a500c4 */ 	addiu	$a1,$sp,0xc4
/*  f0c7188:	c468014c */ 	lwc1	$f8,0x14c($v1)
/*  f0c718c:	8c670150 */ 	lw	$a3,0x150($v1)
/*  f0c7190:	2466017c */ 	addiu	$a2,$v1,0x17c
/*  f0c7194:	0fc33006 */ 	jal	bmove0f0cba88
/*  f0c7198:	e7a80010 */ 	swc1	$f8,0x10($sp)
/*  f0c719c:	3c08800a */ 	lui	$t0,0x800a
/*  f0c71a0:	2508a510 */ 	addiu	$t0,$t0,-23280
/*  f0c71a4:	8d030284 */ 	lw	$v1,0x284($t0)
/*  f0c71a8:	3c01c234 */ 	lui	$at,0xc234
/*  f0c71ac:	c7a800c0 */ 	lwc1	$f8,0xc0($sp)
/*  f0c71b0:	c46c00a0 */ 	lwc1	$f12,0xa0($v1)
/*  f0c71b4:	c46a0374 */ 	lwc1	$f10,0x374($v1)
/*  f0c71b8:	c464036c */ 	lwc1	$f4,0x36c($v1)
/*  f0c71bc:	46006187 */ 	neg.s	$f6,$f12
/*  f0c71c0:	c47000b4 */ 	lwc1	$f16,0xb4($v1)
/*  f0c71c4:	46065002 */ 	mul.s	$f0,$f10,$f6
/*  f0c71c8:	44815000 */ 	mtc1	$at,$f10
/*  f0c71cc:	4480a000 */ 	mtc1	$zero,$f20
/*  f0c71d0:	460c2082 */ 	mul.s	$f2,$f4,$f12
/*  f0c71d4:	460a803c */ 	c.lt.s	$f16,$f10
/*  f0c71d8:	4600a386 */ 	mov.s	$f14,$f20
/*  f0c71dc:	46080002 */ 	mul.s	$f0,$f0,$f8
/*  f0c71e0:	00000000 */ 	nop
/*  f0c71e4:	46081082 */ 	mul.s	$f2,$f2,$f8
/*  f0c71e8:	4500000a */ 	bc1f	.PF0f0c7214
/*  f0c71ec:	00000000 */ 	nop
/*  f0c71f0:	3c017f1b */ 	lui	$at,0x7f1b
/*  f0c71f4:	c426eae0 */ 	lwc1	$f6,-0x1520($at)
/*  f0c71f8:	3c017f1b */ 	lui	$at,0x7f1b
/*  f0c71fc:	c424eae4 */ 	lwc1	$f4,-0x151c($at)
/*  f0c7200:	46060002 */ 	mul.s	$f0,$f0,$f6
/*  f0c7204:	00000000 */ 	nop
/*  f0c7208:	46041082 */ 	mul.s	$f2,$f2,$f4
/*  f0c720c:	1000000b */ 	b	.PF0f0c723c
/*  f0c7210:	00000000 */ 	nop
.PF0f0c7214:
/*  f0c7214:	4614803c */ 	c.lt.s	$f16,$f20
/*  f0c7218:	3c013f00 */ 	lui	$at,0x3f00
/*  f0c721c:	45020008 */ 	bc1fl	.PF0f0c7240
/*  f0c7220:	c46600a4 */ 	lwc1	$f6,0xa4($v1)
/*  f0c7224:	44814000 */ 	mtc1	$at,$f8
/*  f0c7228:	44815000 */ 	mtc1	$at,$f10
/*  f0c722c:	46080002 */ 	mul.s	$f0,$f0,$f8
/*  f0c7230:	00000000 */ 	nop
/*  f0c7234:	460a1082 */ 	mul.s	$f2,$f2,$f10
/*  f0c7238:	00000000 */ 	nop
.PF0f0c723c:
/*  f0c723c:	c46600a4 */ 	lwc1	$f6,0xa4($v1)
.PF0f0c7240:
/*  f0c7240:	c46400a8 */ 	lwc1	$f4,0xa8($v1)
/*  f0c7244:	e7ae00a8 */ 	swc1	$f14,0xa8($sp)
/*  f0c7248:	46060401 */ 	sub.s	$f16,$f0,$f6
/*  f0c724c:	46041481 */ 	sub.s	$f18,$f2,$f4
/*  f0c7250:	46108202 */ 	mul.s	$f8,$f16,$f16
/*  f0c7254:	e7b000b4 */ 	swc1	$f16,0xb4($sp)
/*  f0c7258:	46129282 */ 	mul.s	$f10,$f18,$f18
/*  f0c725c:	e7b200b0 */ 	swc1	$f18,0xb0($sp)
/*  f0c7260:	0c0127b4 */ 	jal	sqrtf
/*  f0c7264:	460a4300 */ 	add.s	$f12,$f8,$f10
/*  f0c7268:	3c08800a */ 	lui	$t0,0x800a
/*  f0c726c:	2508a510 */ 	addiu	$t0,$t0,-23280
/*  f0c7270:	3c017f1b */ 	lui	$at,0x7f1b
/*  f0c7274:	c422eae8 */ 	lwc1	$f2,-0x1518($at)
/*  f0c7278:	c512004c */ 	lwc1	$f18,0x4c($t0)
/*  f0c727c:	c7ae00a8 */ 	lwc1	$f14,0xa8($sp)
/*  f0c7280:	4612103c */ 	c.lt.s	$f2,$f18
/*  f0c7284:	00000000 */ 	nop
/*  f0c7288:	45020005 */ 	bc1fl	.PF0f0c72a0
/*  f0c728c:	46009306 */ 	mov.s	$f12,$f18
/*  f0c7290:	46001306 */ 	mov.s	$f12,$f2
/*  f0c7294:	10000003 */ 	b	.PF0f0c72a4
/*  f0c7298:	24030004 */ 	li	$v1,0x4
/*  f0c729c:	46009306 */ 	mov.s	$f12,$f18
.PF0f0c72a0:
/*  f0c72a0:	8d030038 */ 	lw	$v1,0x38($t0)
.PF0f0c72a4:
/*  f0c72a4:	18600008 */ 	blez	$v1,.PF0f0c72c8
/*  f0c72a8:	00001025 */ 	move	$v0,$zero
/*  f0c72ac:	3c017f1b */ 	lui	$at,0x7f1b
/*  f0c72b0:	c422eaec */ 	lwc1	$f2,-0x1514($at)
.PF0f0c72b4:
/*  f0c72b4:	460e0181 */ 	sub.s	$f6,$f0,$f14
/*  f0c72b8:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f0c72bc:	46023102 */ 	mul.s	$f4,$f6,$f2
/*  f0c72c0:	1443fffc */ 	bne	$v0,$v1,.PF0f0c72b4
/*  f0c72c4:	46047380 */ 	add.s	$f14,$f14,$f4
.PF0f0c72c8:
/*  f0c72c8:	3c014070 */ 	lui	$at,0x4070
/*  f0c72cc:	44814000 */ 	mtc1	$at,$f8
/*  f0c72d0:	8d030284 */ 	lw	$v1,0x284($t0)
/*  f0c72d4:	3c01c234 */ 	lui	$at,0xc234
/*  f0c72d8:	44813000 */ 	mtc1	$at,$f6
/*  f0c72dc:	c47000b4 */ 	lwc1	$f16,0xb4($v1)
/*  f0c72e0:	460c4282 */ 	mul.s	$f10,$f8,$f12
/*  f0c72e4:	4606803c */ 	c.lt.s	$f16,$f6
/*  f0c72e8:	00000000 */ 	nop
/*  f0c72ec:	45000006 */ 	bc1f	.PF0f0c7308
/*  f0c72f0:	460a7380 */ 	add.s	$f14,$f14,$f10
/*  f0c72f4:	3c017f1b */ 	lui	$at,0x7f1b
/*  f0c72f8:	c424eaf0 */ 	lwc1	$f4,-0x1510($at)
/*  f0c72fc:	46047382 */ 	mul.s	$f14,$f14,$f4
/*  f0c7300:	1000000a */ 	b	.PF0f0c732c
/*  f0c7304:	4600703c */ 	c.lt.s	$f14,$f0
.PF0f0c7308:
/*  f0c7308:	4614803c */ 	c.lt.s	$f16,$f20
/*  f0c730c:	3c013f00 */ 	lui	$at,0x3f00
/*  f0c7310:	45020006 */ 	bc1fl	.PF0f0c732c
/*  f0c7314:	4600703c */ 	c.lt.s	$f14,$f0
/*  f0c7318:	44814000 */ 	mtc1	$at,$f8
/*  f0c731c:	00000000 */ 	nop
/*  f0c7320:	46087382 */ 	mul.s	$f14,$f14,$f8
/*  f0c7324:	00000000 */ 	nop
/*  f0c7328:	4600703c */ 	c.lt.s	$f14,$f0
.PF0f0c732c:
/*  f0c732c:	00000000 */ 	nop
/*  f0c7330:	4502000a */ 	bc1fl	.PF0f0c735c
/*  f0c7334:	c46a0168 */ 	lwc1	$f10,0x168($v1)
/*  f0c7338:	46007383 */ 	div.s	$f14,$f14,$f0
/*  f0c733c:	c7aa00b4 */ 	lwc1	$f10,0xb4($sp)
/*  f0c7340:	c7a400b0 */ 	lwc1	$f4,0xb0($sp)
/*  f0c7344:	460e5182 */ 	mul.s	$f6,$f10,$f14
/*  f0c7348:	00000000 */ 	nop
/*  f0c734c:	460e2202 */ 	mul.s	$f8,$f4,$f14
/*  f0c7350:	e7a600b4 */ 	swc1	$f6,0xb4($sp)
/*  f0c7354:	e7a800b0 */ 	swc1	$f8,0xb0($sp)
/*  f0c7358:	c46a0168 */ 	lwc1	$f10,0x168($v1)
.PF0f0c735c:
/*  f0c735c:	c7a600c4 */ 	lwc1	$f6,0xc4($sp)
/*  f0c7360:	3c017f1b */ 	lui	$at,0x7f1b
/*  f0c7364:	c42eeaf4 */ 	lwc1	$f14,-0x150c($at)
/*  f0c7368:	46065100 */ 	add.s	$f4,$f10,$f6
/*  f0c736c:	c4660148 */ 	lwc1	$f6,0x148($v1)
/*  f0c7370:	c7aa00c8 */ 	lwc1	$f10,0xc8($sp)
/*  f0c7374:	c4680170 */ 	lwc1	$f8,0x170($v1)
/*  f0c7378:	460e2082 */ 	mul.s	$f2,$f4,$f14
/*  f0c737c:	3c017f1b */ 	lui	$at,0x7f1b
/*  f0c7380:	460a4300 */ 	add.s	$f12,$f8,$f10
/*  f0c7384:	460e3402 */ 	mul.s	$f16,$f6,$f14
/*  f0c7388:	4614103c */ 	c.lt.s	$f2,$f20
/*  f0c738c:	00000000 */ 	nop
/*  f0c7390:	45020003 */ 	bc1fl	.PF0f0c73a0
/*  f0c7394:	4614603c */ 	c.lt.s	$f12,$f20
/*  f0c7398:	46001087 */ 	neg.s	$f2,$f2
/*  f0c739c:	4614603c */ 	c.lt.s	$f12,$f20
.PF0f0c73a0:
/*  f0c73a0:	00000000 */ 	nop
/*  f0c73a4:	45020003 */ 	bc1fl	.PF0f0c73b4
/*  f0c73a8:	4614803c */ 	c.lt.s	$f16,$f20
/*  f0c73ac:	46006307 */ 	neg.s	$f12,$f12
/*  f0c73b0:	4614803c */ 	c.lt.s	$f16,$f20
.PF0f0c73b4:
/*  f0c73b4:	00000000 */ 	nop
/*  f0c73b8:	45020003 */ 	bc1fl	.PF0f0c73c8
/*  f0c73bc:	4602603c */ 	c.lt.s	$f12,$f2
/*  f0c73c0:	46008407 */ 	neg.s	$f16,$f16
/*  f0c73c4:	4602603c */ 	c.lt.s	$f12,$f2
.PF0f0c73c8:
/*  f0c73c8:	46006386 */ 	mov.s	$f14,$f12
/*  f0c73cc:	45020003 */ 	bc1fl	.PF0f0c73dc
/*  f0c73d0:	4610703c */ 	c.lt.s	$f14,$f16
/*  f0c73d4:	46001386 */ 	mov.s	$f14,$f2
/*  f0c73d8:	4610703c */ 	c.lt.s	$f14,$f16
.PF0f0c73dc:
/*  f0c73dc:	00000000 */ 	nop
/*  f0c73e0:	45000002 */ 	bc1f	.PF0f0c73ec
/*  f0c73e4:	00000000 */ 	nop
/*  f0c73e8:	46008386 */ 	mov.s	$f14,$f16
.PF0f0c73ec:
/*  f0c73ec:	c424eaf8 */ 	lwc1	$f4,-0x1508($at)
/*  f0c73f0:	4600203e */ 	c.le.s	$f4,$f0
/*  f0c73f4:	00000000 */ 	nop
/*  f0c73f8:	45000007 */ 	bc1f	.PF0f0c7418
/*  f0c73fc:	3c017f1b */ 	lui	$at,0x7f1b
/*  f0c7400:	c420eafc */ 	lwc1	$f0,-0x1504($at)
/*  f0c7404:	4600703c */ 	c.lt.s	$f14,$f0
/*  f0c7408:	00000000 */ 	nop
/*  f0c740c:	45020003 */ 	bc1fl	.PF0f0c741c
/*  f0c7410:	3c013f40 */ 	lui	$at,0x3f40
/*  f0c7414:	46000386 */ 	mov.s	$f14,$f0
.PF0f0c7418:
/*  f0c7418:	3c013f40 */ 	lui	$at,0x3f40
.PF0f0c741c:
/*  f0c741c:	44810000 */ 	mtc1	$at,$f0
/*  f0c7420:	00000000 */ 	nop
/*  f0c7424:	460e003e */ 	c.le.s	$f0,$f14
/*  f0c7428:	00000000 */ 	nop
/*  f0c742c:	4502000b */ 	bc1fl	.PF0f0c745c
/*  f0c7430:	460e0181 */ 	sub.s	$f6,$f0,$f14
/*  f0c7434:	46007201 */ 	sub.s	$f8,$f14,$f0
/*  f0c7438:	3c014461 */ 	lui	$at,0x4461
/*  f0c743c:	44813000 */ 	mtc1	$at,$f6
/*  f0c7440:	46124282 */ 	mul.s	$f10,$f8,$f18
/*  f0c7444:	c4680198 */ 	lwc1	$f8,0x198($v1)
/*  f0c7448:	46065103 */ 	div.s	$f4,$f10,$f6
/*  f0c744c:	46044280 */ 	add.s	$f10,$f8,$f4
/*  f0c7450:	10000009 */ 	b	.PF0f0c7478
/*  f0c7454:	e46a0198 */ 	swc1	$f10,0x198($v1)
/*  f0c7458:	460e0181 */ 	sub.s	$f6,$f0,$f14
.PF0f0c745c:
/*  f0c745c:	3c017f1b */ 	lui	$at,0x7f1b
/*  f0c7460:	c424eb00 */ 	lwc1	$f4,-0x1500($at)
/*  f0c7464:	46123202 */ 	mul.s	$f8,$f6,$f18
/*  f0c7468:	c4660198 */ 	lwc1	$f6,0x198($v1)
/*  f0c746c:	46044283 */ 	div.s	$f10,$f8,$f4
/*  f0c7470:	460a3201 */ 	sub.s	$f8,$f6,$f10
/*  f0c7474:	e4680198 */ 	swc1	$f8,0x198($v1)
.PF0f0c7478:
/*  f0c7478:	8d030284 */ 	lw	$v1,0x284($t0)
/*  f0c747c:	c4600198 */ 	lwc1	$f0,0x198($v1)
/*  f0c7480:	4614003c */ 	c.lt.s	$f0,$f20
/*  f0c7484:	00000000 */ 	nop
/*  f0c7488:	45020005 */ 	bc1fl	.PF0f0c74a0
/*  f0c748c:	3c013f80 */ 	lui	$at,0x3f80
/*  f0c7490:	e4740198 */ 	swc1	$f20,0x198($v1)
/*  f0c7494:	1000000c */ 	b	.PF0f0c74c8
/*  f0c7498:	8d030284 */ 	lw	$v1,0x284($t0)
/*  f0c749c:	3c013f80 */ 	lui	$at,0x3f80
.PF0f0c74a0:
/*  f0c74a0:	44812000 */ 	mtc1	$at,$f4
/*  f0c74a4:	3c013f80 */ 	lui	$at,0x3f80
/*  f0c74a8:	4600203c */ 	c.lt.s	$f4,$f0
/*  f0c74ac:	00000000 */ 	nop
/*  f0c74b0:	45000005 */ 	bc1f	.PF0f0c74c8
/*  f0c74b4:	00000000 */ 	nop
/*  f0c74b8:	44813000 */ 	mtc1	$at,$f6
/*  f0c74bc:	00000000 */ 	nop
/*  f0c74c0:	e4660198 */ 	swc1	$f6,0x198($v1)
/*  f0c74c4:	8d030284 */ 	lw	$v1,0x284($t0)
.PF0f0c74c8:
/*  f0c74c8:	3c018007 */ 	lui	$at,0x8007
/*  f0c74cc:	c42a60f4 */ 	lwc1	$f10,0x60f4($at)
/*  f0c74d0:	3c013f00 */ 	lui	$at,0x3f00
/*  f0c74d4:	44814000 */ 	mtc1	$at,$f8
/*  f0c74d8:	c506004c */ 	lwc1	$f6,0x4c($t0)
/*  f0c74dc:	2404000a */ 	li	$a0,0xa
/*  f0c74e0:	46085102 */ 	mul.s	$f4,$f10,$f8
/*  f0c74e4:	c7a800c0 */ 	lwc1	$f8,0xc0($sp)
/*  f0c74e8:	c46a0168 */ 	lwc1	$f10,0x168($v1)
/*  f0c74ec:	e7ae0078 */ 	swc1	$f14,0x78($sp)
/*  f0c74f0:	46062002 */ 	mul.s	$f0,$f4,$f6
/*  f0c74f4:	c7a600c4 */ 	lwc1	$f6,0xc4($sp)
/*  f0c74f8:	46085102 */ 	mul.s	$f4,$f10,$f8
/*  f0c74fc:	46062280 */ 	add.s	$f10,$f4,$f6
/*  f0c7500:	46005082 */ 	mul.s	$f2,$f10,$f0
/*  f0c7504:	0fc41dd5 */ 	jal	cheatIsActive
/*  f0c7508:	e7a200e0 */ 	swc1	$f2,0xe0($sp)
/*  f0c750c:	3c08800a */ 	lui	$t0,0x800a
/*  f0c7510:	2508a510 */ 	addiu	$t0,$t0,-23280
/*  f0c7514:	10400004 */ 	beqz	$v0,.PF0f0c7528
/*  f0c7518:	c7a200e0 */ 	lwc1	$f2,0xe0($sp)
/*  f0c751c:	3c017f1b */ 	lui	$at,0x7f1b
/*  f0c7520:	c428eb04 */ 	lwc1	$f8,-0x14fc($at)
/*  f0c7524:	46081083 */ 	div.s	$f2,$f2,$f8
.PF0f0c7528:
/*  f0c7528:	8d0b0284 */ 	lw	$t3,0x284($t0)
/*  f0c752c:	c7a600c0 */ 	lwc1	$f6,0xc0($sp)
/*  f0c7530:	c7a800c8 */ 	lwc1	$f8,0xc8($sp)
/*  f0c7534:	c5640170 */ 	lwc1	$f4,0x170($t3)
/*  f0c7538:	44061000 */ 	mfc1	$a2,$f2
/*  f0c753c:	c7ac0078 */ 	lwc1	$f12,0x78($sp)
/*  f0c7540:	46062282 */ 	mul.s	$f10,$f4,$f6
/*  f0c7544:	0fc332f9 */ 	jal	bmove0f0cc654
/*  f0c7548:	46085380 */ 	add.s	$f14,$f10,$f8
/*  f0c754c:	3c08800a */ 	lui	$t0,0x800a
/*  f0c7550:	2508a510 */ 	addiu	$t0,$t0,-23280
/*  f0c7554:	8d0c0284 */ 	lw	$t4,0x284($t0)
/*  f0c7558:	c7a40078 */ 	lwc1	$f4,0x78($sp)
/*  f0c755c:	2404000a */ 	li	$a0,0xa
/*  f0c7560:	e58400cc */ 	swc1	$f4,0xcc($t4)
/*  f0c7564:	8d030284 */ 	lw	$v1,0x284($t0)
/*  f0c7568:	c46003c0 */ 	lwc1	$f0,0x3c0($v1)
/*  f0c756c:	c46203c8 */ 	lwc1	$f2,0x3c8($v1)
/*  f0c7570:	e7a000dc */ 	swc1	$f0,0xdc($sp)
/*  f0c7574:	0fc41dd5 */ 	jal	cheatIsActive
/*  f0c7578:	e7a200d8 */ 	swc1	$f2,0xd8($sp)
/*  f0c757c:	3c08800a */ 	lui	$t0,0x800a
/*  f0c7580:	2508a510 */ 	addiu	$t0,$t0,-23280
/*  f0c7584:	c7a000dc */ 	lwc1	$f0,0xdc($sp)
/*  f0c7588:	10400005 */ 	beqz	$v0,.PF0f0c75a0
/*  f0c758c:	c7a200d8 */ 	lwc1	$f2,0xd8($sp)
/*  f0c7590:	3c017f1b */ 	lui	$at,0x7f1b
/*  f0c7594:	c426eb08 */ 	lwc1	$f6,-0x14f8($at)
/*  f0c7598:	46060002 */ 	mul.s	$f0,$f0,$f6
/*  f0c759c:	00000000 */ 	nop
.PF0f0c75a0:
/*  f0c75a0:	8d030284 */ 	lw	$v1,0x284($t0)
/*  f0c75a4:	c512004c */ 	lwc1	$f18,0x4c($t0)
/*  f0c75a8:	27a400cc */ 	addiu	$a0,$sp,0xcc
/*  f0c75ac:	c46a036c */ 	lwc1	$f10,0x36c($v1)
/*  f0c75b0:	c4640374 */ 	lwc1	$f4,0x374($v1)
/*  f0c75b4:	460a1202 */ 	mul.s	$f8,$f2,$f10
/*  f0c75b8:	00000000 */ 	nop
/*  f0c75bc:	46040182 */ 	mul.s	$f6,$f0,$f4
/*  f0c75c0:	46064281 */ 	sub.s	$f10,$f8,$f6
/*  f0c75c4:	c7a800cc */ 	lwc1	$f8,0xcc($sp)
/*  f0c75c8:	46125102 */ 	mul.s	$f4,$f10,$f18
/*  f0c75cc:	46044180 */ 	add.s	$f6,$f8,$f4
/*  f0c75d0:	e7a600cc */ 	swc1	$f6,0xcc($sp)
/*  f0c75d4:	c46a0374 */ 	lwc1	$f10,0x374($v1)
/*  f0c75d8:	c464036c */ 	lwc1	$f4,0x36c($v1)
/*  f0c75dc:	460a1202 */ 	mul.s	$f8,$f2,$f10
/*  f0c75e0:	00000000 */ 	nop
/*  f0c75e4:	46040282 */ 	mul.s	$f10,$f0,$f4
/*  f0c75e8:	460a4100 */ 	add.s	$f4,$f8,$f10
/*  f0c75ec:	c7aa00d4 */ 	lwc1	$f10,0xd4($sp)
/*  f0c75f0:	46122202 */ 	mul.s	$f8,$f4,$f18
/*  f0c75f4:	46085100 */ 	add.s	$f4,$f10,$f8
/*  f0c75f8:	c7aa00b4 */ 	lwc1	$f10,0xb4($sp)
/*  f0c75fc:	460a3200 */ 	add.s	$f8,$f6,$f10
/*  f0c7600:	c7a600b0 */ 	lwc1	$f6,0xb0($sp)
/*  f0c7604:	e7a400d4 */ 	swc1	$f4,0xd4($sp)
/*  f0c7608:	46062280 */ 	add.s	$f10,$f4,$f6
/*  f0c760c:	e7a800cc */ 	swc1	$f8,0xcc($sp)
/*  f0c7610:	0fc33036 */ 	jal	bmoveUpdateMoveInitSpeed
/*  f0c7614:	e7aa00d4 */ 	swc1	$f10,0xd4($sp)
/*  f0c7618:	0fc47e42 */ 	jal	debugIsTurboModeEnabled
/*  f0c761c:	00000000 */ 	nop
/*  f0c7620:	3c08800a */ 	lui	$t0,0x800a
/*  f0c7624:	1040001f */ 	beqz	$v0,.PF0f0c76a4
/*  f0c7628:	2508a510 */ 	addiu	$t0,$t0,-23280
/*  f0c762c:	8d030284 */ 	lw	$v1,0x284($t0)
/*  f0c7630:	c512004c */ 	lwc1	$f18,0x4c($t0)
/*  f0c7634:	3c014120 */ 	lui	$at,0x4120
/*  f0c7638:	c468036c */ 	lwc1	$f8,0x36c($v1)
/*  f0c763c:	c4640170 */ 	lwc1	$f4,0x170($v1)
/*  f0c7640:	c46a0374 */ 	lwc1	$f10,0x374($v1)
/*  f0c7644:	44810000 */ 	mtc1	$at,$f0
/*  f0c7648:	46044182 */ 	mul.s	$f6,$f8,$f4
/*  f0c764c:	c4680168 */ 	lwc1	$f8,0x168($v1)
/*  f0c7650:	46085102 */ 	mul.s	$f4,$f10,$f8
/*  f0c7654:	46043281 */ 	sub.s	$f10,$f6,$f4
/*  f0c7658:	c7a400cc */ 	lwc1	$f4,0xcc($sp)
/*  f0c765c:	46125202 */ 	mul.s	$f8,$f10,$f18
/*  f0c7660:	00000000 */ 	nop
/*  f0c7664:	46004182 */ 	mul.s	$f6,$f8,$f0
/*  f0c7668:	46062280 */ 	add.s	$f10,$f4,$f6
/*  f0c766c:	e7aa00cc */ 	swc1	$f10,0xcc($sp)
/*  f0c7670:	c4640170 */ 	lwc1	$f4,0x170($v1)
/*  f0c7674:	c4680374 */ 	lwc1	$f8,0x374($v1)
/*  f0c7678:	c46a036c */ 	lwc1	$f10,0x36c($v1)
/*  f0c767c:	46044182 */ 	mul.s	$f6,$f8,$f4
/*  f0c7680:	c4680168 */ 	lwc1	$f8,0x168($v1)
/*  f0c7684:	46085102 */ 	mul.s	$f4,$f10,$f8
/*  f0c7688:	46043280 */ 	add.s	$f10,$f6,$f4
/*  f0c768c:	c7a400d4 */ 	lwc1	$f4,0xd4($sp)
/*  f0c7690:	46125202 */ 	mul.s	$f8,$f10,$f18
/*  f0c7694:	00000000 */ 	nop
/*  f0c7698:	46004182 */ 	mul.s	$f6,$f8,$f0
/*  f0c769c:	46062280 */ 	add.s	$f10,$f4,$f6
/*  f0c76a0:	e7aa00d4 */ 	swc1	$f10,0xd4($sp)
.PF0f0c76a4:
/*  f0c76a4:	8d030284 */ 	lw	$v1,0x284($t0)
/*  f0c76a8:	c4601b6c */ 	lwc1	$f0,0x1b6c($v1)
/*  f0c76ac:	4600a032 */ 	c.eq.s	$f20,$f0
/*  f0c76b0:	00000000 */ 	nop
/*  f0c76b4:	45020007 */ 	bc1fl	.PF0f0c76d4
/*  f0c76b8:	c512004c */ 	lwc1	$f18,0x4c($t0)
/*  f0c76bc:	c4681b74 */ 	lwc1	$f8,0x1b74($v1)
/*  f0c76c0:	4608a032 */ 	c.eq.s	$f20,$f8
/*  f0c76c4:	00000000 */ 	nop
/*  f0c76c8:	4503000c */ 	bc1tl	.PF0f0c76fc
/*  f0c76cc:	8c6d02ac */ 	lw	$t5,0x2ac($v1)
/*  f0c76d0:	c512004c */ 	lwc1	$f18,0x4c($t0)
.PF0f0c76d4:
/*  f0c76d4:	c7a400cc */ 	lwc1	$f4,0xcc($sp)
/*  f0c76d8:	c7a800d4 */ 	lwc1	$f8,0xd4($sp)
/*  f0c76dc:	46120182 */ 	mul.s	$f6,$f0,$f18
/*  f0c76e0:	46062280 */ 	add.s	$f10,$f4,$f6
/*  f0c76e4:	e7aa00cc */ 	swc1	$f10,0xcc($sp)
/*  f0c76e8:	c4641b74 */ 	lwc1	$f4,0x1b74($v1)
/*  f0c76ec:	46122182 */ 	mul.s	$f6,$f4,$f18
/*  f0c76f0:	46064280 */ 	add.s	$f10,$f8,$f6
/*  f0c76f4:	e7aa00d4 */ 	swc1	$f10,0xd4($sp)
/*  f0c76f8:	8c6d02ac */ 	lw	$t5,0x2ac($v1)
.PF0f0c76fc:
/*  f0c76fc:	246402a0 */ 	addiu	$a0,$v1,0x2a0
/*  f0c7700:	246502a4 */ 	addiu	$a1,$v1,0x2a4
/*  f0c7704:	51a0006a */ 	beqzl	$t5,.PF0f0c78b0
/*  f0c7708:	8c640298 */ 	lw	$a0,0x298($v1)
/*  f0c770c:	0c0011d8 */ 	jal	guNormalize
/*  f0c7710:	246602a8 */ 	addiu	$a2,$v1,0x2a8
/*  f0c7714:	3c08800a */ 	lui	$t0,0x800a
/*  f0c7718:	2508a510 */ 	addiu	$t0,$t0,-23280
/*  f0c771c:	8d030284 */ 	lw	$v1,0x284($t0)
/*  f0c7720:	c7a800d4 */ 	lwc1	$f8,0xd4($sp)
/*  f0c7724:	c7aa00cc */ 	lwc1	$f10,0xcc($sp)
/*  f0c7728:	c46402a8 */ 	lwc1	$f4,0x2a8($v1)
/*  f0c772c:	c46202a0 */ 	lwc1	$f2,0x2a0($v1)
/*  f0c7730:	3c01c080 */ 	lui	$at,0xc080
/*  f0c7734:	46082182 */ 	mul.s	$f6,$f4,$f8
/*  f0c7738:	00000000 */ 	nop
/*  f0c773c:	46025102 */ 	mul.s	$f4,$f10,$f2
/*  f0c7740:	46043000 */ 	add.s	$f0,$f6,$f4
/*  f0c7744:	c504004c */ 	lwc1	$f4,0x4c($t0)
/*  f0c7748:	44813000 */ 	mtc1	$at,$f6
/*  f0c774c:	46000007 */ 	neg.s	$f0,$f0
/*  f0c7750:	46043182 */ 	mul.s	$f6,$f6,$f4
/*  f0c7754:	4600303c */ 	c.lt.s	$f6,$f0
/*  f0c7758:	00000000 */ 	nop
/*  f0c775c:	45000051 */ 	bc1f	.PF0f0c78a4
/*  f0c7760:	00000000 */ 	nop
/*  f0c7764:	4614003c */ 	c.lt.s	$f0,$f20
/*  f0c7768:	27a50070 */ 	addiu	$a1,$sp,0x70
/*  f0c776c:	27a6006c */ 	addiu	$a2,$sp,0x6c
/*  f0c7770:	27a70068 */ 	addiu	$a3,$sp,0x68
/*  f0c7774:	4502000e */ 	bc1fl	.PF0f0c77b0
/*  f0c7778:	8c6400bc */ 	lw	$a0,0xbc($v1)
/*  f0c777c:	46020102 */ 	mul.s	$f4,$f0,$f2
/*  f0c7780:	3c017f1b */ 	lui	$at,0x7f1b
/*  f0c7784:	c42ceb0c */ 	lwc1	$f12,-0x14f4($at)
/*  f0c7788:	46045180 */ 	add.s	$f6,$f10,$f4
/*  f0c778c:	e7a600cc */ 	swc1	$f6,0xcc($sp)
/*  f0c7790:	c46a02a8 */ 	lwc1	$f10,0x2a8($v1)
/*  f0c7794:	460a0102 */ 	mul.s	$f4,$f0,$f10
/*  f0c7798:	46044180 */ 	add.s	$f6,$f8,$f4
/*  f0c779c:	460c0282 */ 	mul.s	$f10,$f0,$f12
/*  f0c77a0:	e7a600d4 */ 	swc1	$f6,0xd4($sp)
/*  f0c77a4:	10000036 */ 	b	.PF0f0c7880
/*  f0c77a8:	e46a029c */ 	swc1	$f10,0x29c($v1)
/*  f0c77ac:	8c6400bc */ 	lw	$a0,0xbc($v1)
.PF0f0c77b0:
/*  f0c77b0:	0fc30989 */ 	jal	propPlayerGetBbox
/*  f0c77b4:	e7a00074 */ 	swc1	$f0,0x74($sp)
/*  f0c77b8:	3c08800a */ 	lui	$t0,0x800a
/*  f0c77bc:	3c017f1b */ 	lui	$at,0x7f1b
/*  f0c77c0:	c424eb10 */ 	lwc1	$f4,-0x14f0($at)
/*  f0c77c4:	c7a80070 */ 	lwc1	$f8,0x70($sp)
/*  f0c77c8:	2508a510 */ 	addiu	$t0,$t0,-23280
/*  f0c77cc:	8d030284 */ 	lw	$v1,0x284($t0)
/*  f0c77d0:	46044182 */ 	mul.s	$f6,$f8,$f4
/*  f0c77d4:	c7aa006c */ 	lwc1	$f10,0x6c($sp)
/*  f0c77d8:	8c6200bc */ 	lw	$v0,0xbc($v1)
/*  f0c77dc:	c4640074 */ 	lwc1	$f4,0x74($v1)
/*  f0c77e0:	3c013f80 */ 	lui	$at,0x3f80
/*  f0c77e4:	c442000c */ 	lwc1	$f2,0xc($v0)
/*  f0c77e8:	34188040 */ 	li	$t8,0x8040
/*  f0c77ec:	44053000 */ 	mfc1	$a1,$f6
/*  f0c77f0:	46025201 */ 	sub.s	$f8,$f10,$f2
/*  f0c77f4:	44815000 */ 	mtc1	$at,$f10
/*  f0c77f8:	24590028 */ 	addiu	$t9,$v0,0x28
/*  f0c77fc:	46022181 */ 	sub.s	$f6,$f4,$f2
/*  f0c7800:	44064000 */ 	mfc1	$a2,$f8
/*  f0c7804:	afb90010 */ 	sw	$t9,0x10($sp)
/*  f0c7808:	afb80014 */ 	sw	$t8,0x14($sp)
/*  f0c780c:	460a3200 */ 	add.s	$f8,$f6,$f10
/*  f0c7810:	24440008 */ 	addiu	$a0,$v0,0x8
/*  f0c7814:	44074000 */ 	mfc1	$a3,$f8
/*  f0c7818:	0c00a68f */ 	jal	func0002a13c
/*  f0c781c:	00000000 */ 	nop
/*  f0c7820:	3c08800a */ 	lui	$t0,0x800a
/*  f0c7824:	2508a510 */ 	addiu	$t0,$t0,-23280
/*  f0c7828:	14400006 */ 	bnez	$v0,.PF0f0c7844
/*  f0c782c:	c7a00074 */ 	lwc1	$f0,0x74($sp)
/*  f0c7830:	8d0e0284 */ 	lw	$t6,0x284($t0)
/*  f0c7834:	3c017f1b */ 	lui	$at,0x7f1b
/*  f0c7838:	e5d4029c */ 	swc1	$f20,0x29c($t6)
/*  f0c783c:	10000010 */ 	b	.PF0f0c7880
/*  f0c7840:	c42ceb14 */ 	lwc1	$f12,-0x14ec($at)
.PF0f0c7844:
/*  f0c7844:	8d030284 */ 	lw	$v1,0x284($t0)
/*  f0c7848:	c7a400cc */ 	lwc1	$f4,0xcc($sp)
/*  f0c784c:	3c017f1b */ 	lui	$at,0x7f1b
/*  f0c7850:	c46602a0 */ 	lwc1	$f6,0x2a0($v1)
/*  f0c7854:	c42ceb18 */ 	lwc1	$f12,-0x14e8($at)
/*  f0c7858:	46060282 */ 	mul.s	$f10,$f0,$f6
/*  f0c785c:	c7a600d4 */ 	lwc1	$f6,0xd4($sp)
/*  f0c7860:	460a2200 */ 	add.s	$f8,$f4,$f10
/*  f0c7864:	e7a800cc */ 	swc1	$f8,0xcc($sp)
/*  f0c7868:	c46402a8 */ 	lwc1	$f4,0x2a8($v1)
/*  f0c786c:	46040282 */ 	mul.s	$f10,$f0,$f4
/*  f0c7870:	460a3200 */ 	add.s	$f8,$f6,$f10
/*  f0c7874:	460c0102 */ 	mul.s	$f4,$f0,$f12
/*  f0c7878:	e7a800d4 */ 	swc1	$f8,0xd4($sp)
/*  f0c787c:	e464029c */ 	swc1	$f4,0x29c($v1)
.PF0f0c7880:
/*  f0c7880:	c7a600cc */ 	lwc1	$f6,0xcc($sp)
/*  f0c7884:	c7a800d4 */ 	lwc1	$f8,0xd4($sp)
/*  f0c7888:	8d030284 */ 	lw	$v1,0x284($t0)
/*  f0c788c:	460c3282 */ 	mul.s	$f10,$f6,$f12
/*  f0c7890:	00000000 */ 	nop
/*  f0c7894:	460c4102 */ 	mul.s	$f4,$f8,$f12
/*  f0c7898:	e7aa00cc */ 	swc1	$f10,0xcc($sp)
/*  f0c789c:	10000003 */ 	b	.PF0f0c78ac
/*  f0c78a0:	e7a400d4 */ 	swc1	$f4,0xd4($sp)
.PF0f0c78a4:
/*  f0c78a4:	e474029c */ 	swc1	$f20,0x29c($v1)
/*  f0c78a8:	8d030284 */ 	lw	$v1,0x284($t0)
.PF0f0c78ac:
/*  f0c78ac:	8c640298 */ 	lw	$a0,0x298($v1)
.PF0f0c78b0:
/*  f0c78b0:	50800015 */ 	beqzl	$a0,.PF0f0c7908
/*  f0c78b4:	8c6200bc */ 	lw	$v0,0xbc($v1)
/*  f0c78b8:	8c820004 */ 	lw	$v0,0x4($a0)
/*  f0c78bc:	2401003b */ 	li	$at,0x3b
/*  f0c78c0:	904f0003 */ 	lbu	$t7,0x3($v0)
/*  f0c78c4:	55e10010 */ 	bnel	$t7,$at,.PF0f0c7908
/*  f0c78c8:	8c6200bc */ 	lw	$v0,0xbc($v1)
/*  f0c78cc:	8c490014 */ 	lw	$t1,0x14($v0)
/*  f0c78d0:	c44a0060 */ 	lwc1	$f10,0x60($v0)
/*  f0c78d4:	c7a400cc */ 	lwc1	$f4,0xcc($sp)
/*  f0c78d8:	c5260008 */ 	lwc1	$f6,0x8($t1)
/*  f0c78dc:	460a3201 */ 	sub.s	$f8,$f6,$f10
/*  f0c78e0:	46082180 */ 	add.s	$f6,$f4,$f8
/*  f0c78e4:	e7a600cc */ 	swc1	$f6,0xcc($sp)
/*  f0c78e8:	8c4a0014 */ 	lw	$t2,0x14($v0)
/*  f0c78ec:	c4440068 */ 	lwc1	$f4,0x68($v0)
/*  f0c78f0:	c7a600d4 */ 	lwc1	$f6,0xd4($sp)
/*  f0c78f4:	c54a0010 */ 	lwc1	$f10,0x10($t2)
/*  f0c78f8:	46045201 */ 	sub.s	$f8,$f10,$f4
/*  f0c78fc:	46083280 */ 	add.s	$f10,$f6,$f8
/*  f0c7900:	e7aa00d4 */ 	swc1	$f10,0xd4($sp)
/*  f0c7904:	8c6200bc */ 	lw	$v0,0xbc($v1)
.PF0f0c7908:
/*  f0c7908:	27a400cc */ 	addiu	$a0,$sp,0xcc
/*  f0c790c:	00002825 */ 	move	$a1,$zero
/*  f0c7910:	c4440008 */ 	lwc1	$f4,0x8($v0)
/*  f0c7914:	e7a4008c */ 	swc1	$f4,0x8c($sp)
/*  f0c7918:	c4460010 */ 	lwc1	$f6,0x10($v0)
/*  f0c791c:	e7a60088 */ 	swc1	$f6,0x88($sp)
/*  f0c7920:	c46800a0 */ 	lwc1	$f8,0xa0($v1)
/*  f0c7924:	4608a032 */ 	c.eq.s	$f20,$f8
/*  f0c7928:	00000000 */ 	nop
/*  f0c792c:	45000002 */ 	bc1f	.PF0f0c7938
/*  f0c7930:	00000000 */ 	nop
/*  f0c7934:	24050001 */ 	li	$a1,0x1
.PF0f0c7938:
/*  f0c7938:	0fc31a59 */ 	jal	bwalk0f0c63bc
/*  f0c793c:	2406003f */ 	li	$a2,0x3f
/*  f0c7940:	3c08800a */ 	lui	$t0,0x800a
/*  f0c7944:	2508a510 */ 	addiu	$t0,$t0,-23280
/*  f0c7948:	8d030284 */ 	lw	$v1,0x284($t0)
/*  f0c794c:	8c6200bc */ 	lw	$v0,0xbc($v1)
/*  f0c7950:	c4680318 */ 	lwc1	$f8,0x318($v1)
/*  f0c7954:	c4640310 */ 	lwc1	$f4,0x310($v1)
/*  f0c7958:	c4460010 */ 	lwc1	$f6,0x10($v0)
/*  f0c795c:	c44a0008 */ 	lwc1	$f10,0x8($v0)
/*  f0c7960:	c462036c */ 	lwc1	$f2,0x36c($v1)
/*  f0c7964:	46083381 */ 	sub.s	$f14,$f6,$f8
/*  f0c7968:	c4600374 */ 	lwc1	$f0,0x374($v1)
/*  f0c796c:	46045301 */ 	sub.s	$f12,$f10,$f4
/*  f0c7970:	460e1282 */ 	mul.s	$f10,$f2,$f14
/*  f0c7974:	46006107 */ 	neg.s	$f4,$f12
/*  f0c7978:	46002182 */ 	mul.s	$f6,$f4,$f0
/*  f0c797c:	460ca03e */ 	c.le.s	$f20,$f12
/*  f0c7980:	460e0202 */ 	mul.s	$f8,$f0,$f14
/*  f0c7984:	00000000 */ 	nop
/*  f0c7988:	46026102 */ 	mul.s	$f4,$f12,$f2
/*  f0c798c:	46065400 */ 	add.s	$f16,$f10,$f6
/*  f0c7990:	c7aa00d4 */ 	lwc1	$f10,0xd4($sp)
/*  f0c7994:	460a1182 */ 	mul.s	$f6,$f2,$f10
/*  f0c7998:	46044480 */ 	add.s	$f18,$f8,$f4
/*  f0c799c:	c7a800cc */ 	lwc1	$f8,0xcc($sp)
/*  f0c79a0:	46004107 */ 	neg.s	$f4,$f8
/*  f0c79a4:	46002102 */ 	mul.s	$f4,$f4,$f0
/*  f0c79a8:	46043180 */ 	add.s	$f6,$f6,$f4
/*  f0c79ac:	460a0102 */ 	mul.s	$f4,$f0,$f10
/*  f0c79b0:	00000000 */ 	nop
/*  f0c79b4:	46024282 */ 	mul.s	$f10,$f8,$f2
/*  f0c79b8:	e7a6004c */ 	swc1	$f6,0x4c($sp)
/*  f0c79bc:	460a2100 */ 	add.s	$f4,$f4,$f10
/*  f0c79c0:	4500001c */ 	bc1f	.PF0f0c7a34
/*  f0c79c4:	e7a40048 */ 	swc1	$f4,0x48($sp)
/*  f0c79c8:	c460017c */ 	lwc1	$f0,0x17c($v1)
/*  f0c79cc:	46003086 */ 	mov.s	$f2,$f6
/*  f0c79d0:	c7a600cc */ 	lwc1	$f6,0xcc($sp)
/*  f0c79d4:	4600a03c */ 	c.lt.s	$f20,$f0
/*  f0c79d8:	00000000 */ 	nop
/*  f0c79dc:	4502000f */ 	bc1fl	.PF0f0c7a1c
/*  f0c79e0:	4614303c */ 	c.lt.s	$f6,$f20
/*  f0c79e4:	4608a03e */ 	c.le.s	$f20,$f8
/*  f0c79e8:	00000000 */ 	nop
/*  f0c79ec:	4502002c */ 	bc1fl	.PF0f0c7aa0
/*  f0c79f0:	460ea03e */ 	c.le.s	$f20,$f14
/*  f0c79f4:	4608603c */ 	c.lt.s	$f12,$f8
/*  f0c79f8:	00000000 */ 	nop
/*  f0c79fc:	45020028 */ 	bc1fl	.PF0f0c7aa0
/*  f0c7a00:	460ea03e */ 	c.le.s	$f20,$f14
/*  f0c7a04:	46086283 */ 	div.s	$f10,$f12,$f8
/*  f0c7a08:	460a0102 */ 	mul.s	$f4,$f0,$f10
/*  f0c7a0c:	e464017c */ 	swc1	$f4,0x17c($v1)
/*  f0c7a10:	10000022 */ 	b	.PF0f0c7a9c
/*  f0c7a14:	8d030284 */ 	lw	$v1,0x284($t0)
/*  f0c7a18:	4614303c */ 	c.lt.s	$f6,$f20
.PF0f0c7a1c:
/*  f0c7a1c:	00000000 */ 	nop
/*  f0c7a20:	4502001f */ 	bc1fl	.PF0f0c7aa0
/*  f0c7a24:	460ea03e */ 	c.le.s	$f20,$f14
/*  f0c7a28:	e474017c */ 	swc1	$f20,0x17c($v1)
/*  f0c7a2c:	1000001b */ 	b	.PF0f0c7a9c
/*  f0c7a30:	8d030284 */ 	lw	$v1,0x284($t0)
.PF0f0c7a34:
/*  f0c7a34:	c460017c */ 	lwc1	$f0,0x17c($v1)
/*  f0c7a38:	c7a2004c */ 	lwc1	$f2,0x4c($sp)
/*  f0c7a3c:	c7a800cc */ 	lwc1	$f8,0xcc($sp)
/*  f0c7a40:	4614003c */ 	c.lt.s	$f0,$f20
/*  f0c7a44:	c7a600cc */ 	lwc1	$f6,0xcc($sp)
/*  f0c7a48:	4502000f */ 	bc1fl	.PF0f0c7a88
/*  f0c7a4c:	4606a03c */ 	c.lt.s	$f20,$f6
/*  f0c7a50:	4614403e */ 	c.le.s	$f8,$f20
/*  f0c7a54:	00000000 */ 	nop
/*  f0c7a58:	45020011 */ 	bc1fl	.PF0f0c7aa0
/*  f0c7a5c:	460ea03e */ 	c.le.s	$f20,$f14
/*  f0c7a60:	460c403c */ 	c.lt.s	$f8,$f12
/*  f0c7a64:	00000000 */ 	nop
/*  f0c7a68:	4502000d */ 	bc1fl	.PF0f0c7aa0
/*  f0c7a6c:	460ea03e */ 	c.le.s	$f20,$f14
/*  f0c7a70:	46086283 */ 	div.s	$f10,$f12,$f8
/*  f0c7a74:	460a0102 */ 	mul.s	$f4,$f0,$f10
/*  f0c7a78:	e464017c */ 	swc1	$f4,0x17c($v1)
/*  f0c7a7c:	10000007 */ 	b	.PF0f0c7a9c
/*  f0c7a80:	8d030284 */ 	lw	$v1,0x284($t0)
/*  f0c7a84:	4606a03c */ 	c.lt.s	$f20,$f6
.PF0f0c7a88:
/*  f0c7a88:	00000000 */ 	nop
/*  f0c7a8c:	45020004 */ 	bc1fl	.PF0f0c7aa0
/*  f0c7a90:	460ea03e */ 	c.le.s	$f20,$f14
/*  f0c7a94:	e474017c */ 	swc1	$f20,0x17c($v1)
/*  f0c7a98:	8d030284 */ 	lw	$v1,0x284($t0)
.PF0f0c7a9c:
/*  f0c7a9c:	460ea03e */ 	c.le.s	$f20,$f14
.PF0f0c7aa0:
/*  f0c7aa0:	00000000 */ 	nop
/*  f0c7aa4:	4502001d */ 	bc1fl	.PF0f0c7b1c
/*  f0c7aa8:	c4600184 */ 	lwc1	$f0,0x184($v1)
/*  f0c7aac:	c4600184 */ 	lwc1	$f0,0x184($v1)
/*  f0c7ab0:	c7a800d4 */ 	lwc1	$f8,0xd4($sp)
/*  f0c7ab4:	c7a600d4 */ 	lwc1	$f6,0xd4($sp)
/*  f0c7ab8:	4600a03c */ 	c.lt.s	$f20,$f0
/*  f0c7abc:	00000000 */ 	nop
/*  f0c7ac0:	4502000f */ 	bc1fl	.PF0f0c7b00
/*  f0c7ac4:	4614303c */ 	c.lt.s	$f6,$f20
/*  f0c7ac8:	4608a03e */ 	c.le.s	$f20,$f8
/*  f0c7acc:	00000000 */ 	nop
/*  f0c7ad0:	4502002c */ 	bc1fl	.PF0f0c7b84
/*  f0c7ad4:	46141032 */ 	c.eq.s	$f2,$f20
/*  f0c7ad8:	4608703c */ 	c.lt.s	$f14,$f8
/*  f0c7adc:	00000000 */ 	nop
/*  f0c7ae0:	45020028 */ 	bc1fl	.PF0f0c7b84
/*  f0c7ae4:	46141032 */ 	c.eq.s	$f2,$f20
/*  f0c7ae8:	46087283 */ 	div.s	$f10,$f14,$f8
/*  f0c7aec:	460a0102 */ 	mul.s	$f4,$f0,$f10
/*  f0c7af0:	e4640184 */ 	swc1	$f4,0x184($v1)
/*  f0c7af4:	10000022 */ 	b	.PF0f0c7b80
/*  f0c7af8:	8d030284 */ 	lw	$v1,0x284($t0)
/*  f0c7afc:	4614303c */ 	c.lt.s	$f6,$f20
.PF0f0c7b00:
/*  f0c7b00:	00000000 */ 	nop
/*  f0c7b04:	4502001f */ 	bc1fl	.PF0f0c7b84
/*  f0c7b08:	46141032 */ 	c.eq.s	$f2,$f20
/*  f0c7b0c:	e4740184 */ 	swc1	$f20,0x184($v1)
/*  f0c7b10:	1000001b */ 	b	.PF0f0c7b80
/*  f0c7b14:	8d030284 */ 	lw	$v1,0x284($t0)
/*  f0c7b18:	c4600184 */ 	lwc1	$f0,0x184($v1)
.PF0f0c7b1c:
/*  f0c7b1c:	c7a800d4 */ 	lwc1	$f8,0xd4($sp)
/*  f0c7b20:	c7a600d4 */ 	lwc1	$f6,0xd4($sp)
/*  f0c7b24:	4614003c */ 	c.lt.s	$f0,$f20
/*  f0c7b28:	00000000 */ 	nop
/*  f0c7b2c:	4502000f */ 	bc1fl	.PF0f0c7b6c
/*  f0c7b30:	4606a03c */ 	c.lt.s	$f20,$f6
/*  f0c7b34:	4614403e */ 	c.le.s	$f8,$f20
/*  f0c7b38:	00000000 */ 	nop
/*  f0c7b3c:	45020011 */ 	bc1fl	.PF0f0c7b84
/*  f0c7b40:	46141032 */ 	c.eq.s	$f2,$f20
/*  f0c7b44:	460e403c */ 	c.lt.s	$f8,$f14
/*  f0c7b48:	00000000 */ 	nop
/*  f0c7b4c:	4502000d */ 	bc1fl	.PF0f0c7b84
/*  f0c7b50:	46141032 */ 	c.eq.s	$f2,$f20
/*  f0c7b54:	46087283 */ 	div.s	$f10,$f14,$f8
/*  f0c7b58:	460a0102 */ 	mul.s	$f4,$f0,$f10
/*  f0c7b5c:	e4640184 */ 	swc1	$f4,0x184($v1)
/*  f0c7b60:	10000007 */ 	b	.PF0f0c7b80
/*  f0c7b64:	8d030284 */ 	lw	$v1,0x284($t0)
/*  f0c7b68:	4606a03c */ 	c.lt.s	$f20,$f6
.PF0f0c7b6c:
/*  f0c7b6c:	00000000 */ 	nop
/*  f0c7b70:	45020004 */ 	bc1fl	.PF0f0c7b84
/*  f0c7b74:	46141032 */ 	c.eq.s	$f2,$f20
/*  f0c7b78:	e4740184 */ 	swc1	$f20,0x184($v1)
/*  f0c7b7c:	8d030284 */ 	lw	$v1,0x284($t0)
.PF0f0c7b80:
/*  f0c7b80:	46141032 */ 	c.eq.s	$f2,$f20
.PF0f0c7b84:
/*  f0c7b84:	00000000 */ 	nop
/*  f0c7b88:	4503001a */ 	bc1tl	.PF0f0c7bf4
/*  f0c7b8c:	c7a20048 */ 	lwc1	$f2,0x48($sp)
/*  f0c7b90:	c460016c */ 	lwc1	$f0,0x16c($v1)
/*  f0c7b94:	46020202 */ 	mul.s	$f8,$f0,$f2
/*  f0c7b98:	4608a03c */ 	c.lt.s	$f20,$f8
/*  f0c7b9c:	00000000 */ 	nop
/*  f0c7ba0:	45020014 */ 	bc1fl	.PF0f0c7bf4
/*  f0c7ba4:	c7a20048 */ 	lwc1	$f2,0x48($sp)
/*  f0c7ba8:	46028403 */ 	div.s	$f16,$f16,$f2
/*  f0c7bac:	3c013f80 */ 	lui	$at,0x3f80
/*  f0c7bb0:	4614803e */ 	c.le.s	$f16,$f20
/*  f0c7bb4:	00000000 */ 	nop
/*  f0c7bb8:	45020005 */ 	bc1fl	.PF0f0c7bd0
/*  f0c7bbc:	44815000 */ 	mtc1	$at,$f10
/*  f0c7bc0:	e474016c */ 	swc1	$f20,0x16c($v1)
/*  f0c7bc4:	1000000a */ 	b	.PF0f0c7bf0
/*  f0c7bc8:	8d030284 */ 	lw	$v1,0x284($t0)
/*  f0c7bcc:	44815000 */ 	mtc1	$at,$f10
.PF0f0c7bd0:
/*  f0c7bd0:	00000000 */ 	nop
/*  f0c7bd4:	460a803c */ 	c.lt.s	$f16,$f10
/*  f0c7bd8:	00000000 */ 	nop
/*  f0c7bdc:	45020005 */ 	bc1fl	.PF0f0c7bf4
/*  f0c7be0:	c7a20048 */ 	lwc1	$f2,0x48($sp)
/*  f0c7be4:	46100102 */ 	mul.s	$f4,$f0,$f16
/*  f0c7be8:	e464016c */ 	swc1	$f4,0x16c($v1)
/*  f0c7bec:	8d030284 */ 	lw	$v1,0x284($t0)
.PF0f0c7bf0:
/*  f0c7bf0:	c7a20048 */ 	lwc1	$f2,0x48($sp)
.PF0f0c7bf4:
/*  f0c7bf4:	46141032 */ 	c.eq.s	$f2,$f20
/*  f0c7bf8:	00000000 */ 	nop
/*  f0c7bfc:	4503001a */ 	bc1tl	.PF0f0c7c68
/*  f0c7c00:	8c6200bc */ 	lw	$v0,0xbc($v1)
/*  f0c7c04:	c46019a4 */ 	lwc1	$f0,0x19a4($v1)
/*  f0c7c08:	46020182 */ 	mul.s	$f6,$f0,$f2
/*  f0c7c0c:	4606a03c */ 	c.lt.s	$f20,$f6
/*  f0c7c10:	00000000 */ 	nop
/*  f0c7c14:	45020014 */ 	bc1fl	.PF0f0c7c68
/*  f0c7c18:	8c6200bc */ 	lw	$v0,0xbc($v1)
/*  f0c7c1c:	46029483 */ 	div.s	$f18,$f18,$f2
/*  f0c7c20:	3c013f80 */ 	lui	$at,0x3f80
/*  f0c7c24:	4614903e */ 	c.le.s	$f18,$f20
/*  f0c7c28:	00000000 */ 	nop
/*  f0c7c2c:	45020005 */ 	bc1fl	.PF0f0c7c44
/*  f0c7c30:	44814000 */ 	mtc1	$at,$f8
/*  f0c7c34:	e47419a4 */ 	swc1	$f20,0x19a4($v1)
/*  f0c7c38:	1000000a */ 	b	.PF0f0c7c64
/*  f0c7c3c:	8d030284 */ 	lw	$v1,0x284($t0)
/*  f0c7c40:	44814000 */ 	mtc1	$at,$f8
.PF0f0c7c44:
/*  f0c7c44:	00000000 */ 	nop
/*  f0c7c48:	4608903c */ 	c.lt.s	$f18,$f8
/*  f0c7c4c:	00000000 */ 	nop
/*  f0c7c50:	45020005 */ 	bc1fl	.PF0f0c7c68
/*  f0c7c54:	8c6200bc */ 	lw	$v0,0xbc($v1)
/*  f0c7c58:	46120282 */ 	mul.s	$f10,$f0,$f18
/*  f0c7c5c:	e46a19a4 */ 	swc1	$f10,0x19a4($v1)
/*  f0c7c60:	8d030284 */ 	lw	$v1,0x284($t0)
.PF0f0c7c64:
/*  f0c7c64:	8c6200bc */ 	lw	$v0,0xbc($v1)
.PF0f0c7c68:
/*  f0c7c68:	c7a6008c */ 	lwc1	$f6,0x8c($sp)
/*  f0c7c6c:	c7aa0088 */ 	lwc1	$f10,0x88($sp)
/*  f0c7c70:	c4440008 */ 	lwc1	$f4,0x8($v0)
/*  f0c7c74:	c4480010 */ 	lwc1	$f8,0x10($v0)
/*  f0c7c78:	46062001 */ 	sub.s	$f0,$f4,$f6
/*  f0c7c7c:	c7a400d4 */ 	lwc1	$f4,0xd4($sp)
/*  f0c7c80:	460a4081 */ 	sub.s	$f2,$f8,$f10
/*  f0c7c84:	46042182 */ 	mul.s	$f6,$f4,$f4
/*  f0c7c88:	c7a800cc */ 	lwc1	$f8,0xcc($sp)
/*  f0c7c8c:	46084282 */ 	mul.s	$f10,$f8,$f8
/*  f0c7c90:	460a3380 */ 	add.s	$f14,$f6,$f10
/*  f0c7c94:	46147032 */ 	c.eq.s	$f14,$f20
/*  f0c7c98:	46007306 */ 	mov.s	$f12,$f14
/*  f0c7c9c:	45010006 */ 	bc1t	.PF0f0c7cb8
/*  f0c7ca0:	00000000 */ 	nop
/*  f0c7ca4:	46000102 */ 	mul.s	$f4,$f0,$f0
/*  f0c7ca8:	00000000 */ 	nop
/*  f0c7cac:	46021202 */ 	mul.s	$f8,$f2,$f2
/*  f0c7cb0:	46082180 */ 	add.s	$f6,$f4,$f8
/*  f0c7cb4:	460e3303 */ 	div.s	$f12,$f6,$f14
.PF0f0c7cb8:
/*  f0c7cb8:	0c0127b4 */ 	jal	sqrtf
/*  f0c7cbc:	00000000 */ 	nop
/*  f0c7cc0:	c7a400b4 */ 	lwc1	$f4,0xb4($sp)
/*  f0c7cc4:	3c08800a */ 	lui	$t0,0x800a
/*  f0c7cc8:	2508a510 */ 	addiu	$t0,$t0,-23280
/*  f0c7ccc:	46040202 */ 	mul.s	$f8,$f0,$f4
/*  f0c7cd0:	8d030284 */ 	lw	$v1,0x284($t0)
/*  f0c7cd4:	c46a00a4 */ 	lwc1	$f10,0xa4($v1)
/*  f0c7cd8:	46085180 */ 	add.s	$f6,$f10,$f8
/*  f0c7cdc:	e46600a4 */ 	swc1	$f6,0xa4($v1)
/*  f0c7ce0:	c7aa00b0 */ 	lwc1	$f10,0xb0($sp)
/*  f0c7ce4:	8d030284 */ 	lw	$v1,0x284($t0)
/*  f0c7ce8:	460a0202 */ 	mul.s	$f8,$f0,$f10
/*  f0c7cec:	c46400a8 */ 	lwc1	$f4,0xa8($v1)
/*  f0c7cf0:	46082180 */ 	add.s	$f6,$f4,$f8
/*  f0c7cf4:	e46600a8 */ 	swc1	$f6,0xa8($v1)
.PF0f0c7cf8:
/*  f0c7cf8:	8d030284 */ 	lw	$v1,0x284($t0)
/*  f0c7cfc:	3c017f1b */ 	lui	$at,0x7f1b
/*  f0c7d00:	c428eb1c */ 	lwc1	$f8,-0x14e4($at)
/*  f0c7d04:	c46a0148 */ 	lwc1	$f10,0x148($v1)
/*  f0c7d08:	3c0140c0 */ 	lui	$at,0x40c0
/*  f0c7d0c:	e7aa0044 */ 	swc1	$f10,0x44($sp)
/*  f0c7d10:	c464015c */ 	lwc1	$f4,0x15c($v1)
/*  f0c7d14:	c46a00b8 */ 	lwc1	$f10,0xb8($v1)
/*  f0c7d18:	46082183 */ 	div.s	$f6,$f4,$f8
/*  f0c7d1c:	44812000 */ 	mtc1	$at,$f4
/*  f0c7d20:	00000000 */ 	nop
/*  f0c7d24:	46045203 */ 	div.s	$f8,$f10,$f4
/*  f0c7d28:	c46a00cc */ 	lwc1	$f10,0xcc($v1)
/*  f0c7d2c:	e7aa003c */ 	swc1	$f10,0x3c($sp)
/*  f0c7d30:	46083080 */ 	add.s	$f2,$f6,$f8
/*  f0c7d34:	0fc45313 */ 	jal	bheadGetBreathingValue
/*  f0c7d38:	e7a20040 */ 	swc1	$f2,0x40($sp)
/*  f0c7d3c:	3c013f80 */ 	lui	$at,0x3f80
/*  f0c7d40:	44817000 */ 	mtc1	$at,$f14
/*  f0c7d44:	c7a20040 */ 	lwc1	$f2,0x40($sp)
/*  f0c7d48:	3c08800a */ 	lui	$t0,0x800a
/*  f0c7d4c:	2508a510 */ 	addiu	$t0,$t0,-23280
/*  f0c7d50:	4602703c */ 	c.lt.s	$f14,$f2
/*  f0c7d54:	46000306 */ 	mov.s	$f12,$f0
/*  f0c7d58:	3c01bf80 */ 	lui	$at,0xbf80
/*  f0c7d5c:	8fa70044 */ 	lw	$a3,0x44($sp)
/*  f0c7d60:	45020004 */ 	bc1fl	.PF0f0c7d74
/*  f0c7d64:	44817000 */ 	mtc1	$at,$f14
/*  f0c7d68:	10000008 */ 	b	.PF0f0c7d8c
/*  f0c7d6c:	46007086 */ 	mov.s	$f2,$f14
/*  f0c7d70:	44817000 */ 	mtc1	$at,$f14
.PF0f0c7d74:
/*  f0c7d74:	00000000 */ 	nop
/*  f0c7d78:	460e103c */ 	c.lt.s	$f2,$f14
/*  f0c7d7c:	00000000 */ 	nop
/*  f0c7d80:	45020003 */ 	bc1fl	.PF0f0c7d90
/*  f0c7d84:	8d0b0284 */ 	lw	$t3,0x284($t0)
/*  f0c7d88:	46007086 */ 	mov.s	$f2,$f14
.PF0f0c7d8c:
/*  f0c7d8c:	8d0b0284 */ 	lw	$t3,0x284($t0)
.PF0f0c7d90:
/*  f0c7d90:	24010001 */ 	li	$at,0x1
/*  f0c7d94:	44061000 */ 	mfc1	$a2,$f2
/*  f0c7d98:	8d6c03ac */ 	lw	$t4,0x3ac($t3)
/*  f0c7d9c:	c7ae003c */ 	lwc1	$f14,0x3c($sp)
/*  f0c7da0:	15810004 */ 	bne	$t4,$at,.PF0f0c7db4
/*  f0c7da4:	3c017f1b */ 	lui	$at,0x7f1b
/*  f0c7da8:	c424eb20 */ 	lwc1	$f4,-0x14e0($at)
/*  f0c7dac:	46040302 */ 	mul.s	$f12,$f0,$f4
/*  f0c7db0:	00000000 */ 	nop
.PF0f0c7db4:
/*  f0c7db4:	0fc276e4 */ 	jal	func0f09d8dc
/*  f0c7db8:	e7b40010 */ 	swc1	$f20,0x10($sp)
/*  f0c7dbc:	3c08800a */ 	lui	$t0,0x800a
/*  f0c7dc0:	2508a510 */ 	addiu	$t0,$t0,-23280
/*  f0c7dc4:	8d0d0284 */ 	lw	$t5,0x284($t0)
/*  f0c7dc8:	3c017f1b */ 	lui	$at,0x7f1b
/*  f0c7dcc:	c428eb24 */ 	lwc1	$f8,-0x14dc($at)
/*  f0c7dd0:	c5a60158 */ 	lwc1	$f6,0x158($t5)
/*  f0c7dd4:	46083302 */ 	mul.s	$f12,$f6,$f8
/*  f0c7dd8:	0fc28971 */ 	jal	handSetAdjustPos
/*  f0c7ddc:	00000000 */ 	nop
/*  f0c7de0:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*  f0c7de4:	d7b40018 */ 	ldc1	$f20,0x18($sp)
/*  f0c7de8:	27bd00e8 */ 	addiu	$sp,$sp,0xe8
/*  f0c7dec:	03e00008 */ 	jr	$ra
/*  f0c7df0:	00000000 */ 	nop
);
#elif VERSION >= VERSION_NTSC_1_0
GLOBAL_ASM(
glabel bwalk0f0c69b8
.late_rodata
glabel var7f1ad7fc
.word 0xc27e6668
glabel var7f1ad800
.word 0x43b0aaaa
glabel var7f1ad804
.word 0x3ecccccd
glabel var7f1ad808
.word 0x3c888889
glabel var7f1ad80c
.word 0x404907a9
glabel var7f1ad810
.word 0x3eb33333
glabel var7f1ad814
.word 0x3eb33333
glabel var7f1ad818
.word 0x3dcccccd
glabel var7f1ad81c
.word 0x3dcccccd
glabel var7f1ad820
.word 0x3eb33333
glabel var7f1ad824
.word 0x3f4ccccd
glabel var7f1ad828
.word 0x3f4ccccd
glabel var7f1ad82c
.word 0x3f4ccccd
glabel var7f1ad830
.word 0x4528c000
glabel var7f1ad834
.word 0x3ecccccd
glabel var7f1ad838
.word 0x3ecccccd
glabel var7f1ad83c
.word 0x3e99999a
glabel var7f1ad840
.word 0x3f8ccccd
glabel var7f1ad844
.word 0x3e99999a
glabel var7f1ad848
.word 0x3e99999a
glabel var7f1ad84c
.word 0x3f333333
glabel var7f1ad850
.word 0x3f99999a
glabel var7f1ad854
.word 0x3c8ef461
.text
/*  f0c69b8:	27bdff18 */ 	addiu	$sp,$sp,-232
/*  f0c69bc:	3c0f8007 */ 	lui	$t7,%hi(var80070e68)
/*  f0c69c0:	afbf0024 */ 	sw	$ra,0x24($sp)
/*  f0c69c4:	f7b40018 */ 	sdc1	$f20,0x18($sp)
/*  f0c69c8:	25ef0e68 */ 	addiu	$t7,$t7,%lo(var80070e68)
/*  f0c69cc:	8de10000 */ 	lw	$at,0x0($t7)
/*  f0c69d0:	27ae00cc */ 	addiu	$t6,$sp,0xcc
/*  f0c69d4:	8de90004 */ 	lw	$t1,0x4($t7)
/*  f0c69d8:	adc10000 */ 	sw	$at,0x0($t6)
/*  f0c69dc:	8de10008 */ 	lw	$at,0x8($t7)
/*  f0c69e0:	3c08800a */ 	lui	$t0,%hi(g_Vars)
/*  f0c69e4:	25089fc0 */ 	addiu	$t0,$t0,%lo(g_Vars)
/*  f0c69e8:	adc90004 */ 	sw	$t1,0x4($t6)
/*  f0c69ec:	adc10008 */ 	sw	$at,0x8($t6)
/*  f0c69f0:	8d0a0284 */ 	lw	$t2,0x284($t0)
/*  f0c69f4:	3c01431f */ 	lui	$at,0x431f
/*  f0c69f8:	44813000 */ 	mtc1	$at,$f6
/*  f0c69fc:	c54419c4 */ 	lwc1	$f4,0x19c4($t2)
/*  f0c6a00:	46062201 */ 	sub.s	$f8,$f4,$f6
/*  f0c6a04:	0fc44a11 */ 	jal	invHasBriefcase
/*  f0c6a08:	e7a800c0 */ 	swc1	$f8,0xc0($sp)
/*  f0c6a0c:	3c08800a */ 	lui	$t0,%hi(g_Vars)
/*  f0c6a10:	1040000a */ 	beqz	$v0,.L0f0c6a3c
/*  f0c6a14:	25089fc0 */ 	addiu	$t0,$t0,%lo(g_Vars)
/*  f0c6a18:	3c02800b */ 	lui	$v0,%hi(g_MpSetup+0x10)
/*  f0c6a1c:	9042cb98 */ 	lbu	$v0,%lo(g_MpSetup+0x10)($v0)
/*  f0c6a20:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0c6a24:	10410002 */ 	beq	$v0,$at,.L0f0c6a30
/*  f0c6a28:	24010005 */ 	addiu	$at,$zero,0x5
/*  f0c6a2c:	14410003 */ 	bne	$v0,$at,.L0f0c6a3c
.L0f0c6a30:
/*  f0c6a30:	3c017f1b */ 	lui	$at,%hi(var7f1ad7fc)
/*  f0c6a34:	c420d7fc */ 	lwc1	$f0,%lo(var7f1ad7fc)($at)
/*  f0c6a38:	e7a000c0 */ 	swc1	$f0,0xc0($sp)
.L0f0c6a3c:
/*  f0c6a3c:	3c017f1b */ 	lui	$at,%hi(var7f1ad800)
/*  f0c6a40:	c7a000c0 */ 	lwc1	$f0,0xc0($sp)
/*  f0c6a44:	c42ad800 */ 	lwc1	$f10,%lo(var7f1ad800)($at)
/*  f0c6a48:	8d0b0318 */ 	lw	$t3,0x318($t0)
/*  f0c6a4c:	3c013f80 */ 	lui	$at,0x3f80
/*  f0c6a50:	460a0103 */ 	div.s	$f4,$f0,$f10
/*  f0c6a54:	44813000 */ 	mtc1	$at,$f6
/*  f0c6a58:	3c0c800b */ 	lui	$t4,%hi(g_MpSetup+0xc)
/*  f0c6a5c:	2404000a */ 	addiu	$a0,$zero,0xa
/*  f0c6a60:	1160000a */ 	beqz	$t3,.L0f0c6a8c
/*  f0c6a64:	46062000 */ 	add.s	$f0,$f4,$f6
/*  f0c6a68:	8d8ccb94 */ 	lw	$t4,%lo(g_MpSetup+0xc)($t4)
/*  f0c6a6c:	3c013fa0 */ 	lui	$at,0x3fa0
/*  f0c6a70:	318d0100 */ 	andi	$t5,$t4,0x100
/*  f0c6a74:	11a00005 */ 	beqz	$t5,.L0f0c6a8c
/*  f0c6a78:	00000000 */ 	nop
/*  f0c6a7c:	44814000 */ 	mtc1	$at,$f8
/*  f0c6a80:	00000000 */ 	nop
/*  f0c6a84:	46080002 */ 	mul.s	$f0,$f0,$f8
/*  f0c6a88:	00000000 */ 	nop
.L0f0c6a8c:
/*  f0c6a8c:	0fc41b99 */ 	jal	cheatIsActive
/*  f0c6a90:	e7a000c0 */ 	swc1	$f0,0xc0($sp)
/*  f0c6a94:	3c08800a */ 	lui	$t0,%hi(g_Vars)
/*  f0c6a98:	10400006 */ 	beqz	$v0,.L0f0c6ab4
/*  f0c6a9c:	25089fc0 */ 	addiu	$t0,$t0,%lo(g_Vars)
/*  f0c6aa0:	3c017f1b */ 	lui	$at,%hi(var7f1ad804)
/*  f0c6aa4:	c424d804 */ 	lwc1	$f4,%lo(var7f1ad804)($at)
/*  f0c6aa8:	c7aa00c0 */ 	lwc1	$f10,0xc0($sp)
/*  f0c6aac:	46045182 */ 	mul.s	$f6,$f10,$f4
/*  f0c6ab0:	e7a600c0 */ 	swc1	$f6,0xc0($sp)
.L0f0c6ab4:
/*  f0c6ab4:	8d030284 */ 	lw	$v1,0x284($t0)
/*  f0c6ab8:	8c791af8 */ 	lw	$t9,0x1af8($v1)
/*  f0c6abc:	1320003f */ 	beqz	$t9,.L0f0c6bbc
/*  f0c6ac0:	3c013f80 */ 	lui	$at,0x3f80
/*  f0c6ac4:	44811000 */ 	mtc1	$at,$f2
/*  f0c6ac8:	3c017f1b */ 	lui	$at,%hi(var7f1ad808)
/*  f0c6acc:	c42ad808 */ 	lwc1	$f10,%lo(var7f1ad808)($at)
/*  f0c6ad0:	c508004c */ 	lwc1	$f8,0x4c($t0)
/*  f0c6ad4:	c4661b48 */ 	lwc1	$f6,0x1b48($v1)
/*  f0c6ad8:	3c017f1b */ 	lui	$at,%hi(var7f1ad80c)
/*  f0c6adc:	460a4102 */ 	mul.s	$f4,$f8,$f10
/*  f0c6ae0:	46043200 */ 	add.s	$f8,$f6,$f4
/*  f0c6ae4:	e4681b48 */ 	swc1	$f8,0x1b48($v1)
/*  f0c6ae8:	8d030284 */ 	lw	$v1,0x284($t0)
/*  f0c6aec:	c4601b48 */ 	lwc1	$f0,0x1b48($v1)
/*  f0c6af0:	4600103e */ 	c.le.s	$f2,$f0
/*  f0c6af4:	00000000 */ 	nop
/*  f0c6af8:	45000006 */ 	bc1f	.L0f0c6b14
/*  f0c6afc:	00000000 */ 	nop
/*  f0c6b00:	e4621b48 */ 	swc1	$f2,0x1b48($v1)
/*  f0c6b04:	8d180284 */ 	lw	$t8,0x284($t0)
/*  f0c6b08:	af001af8 */ 	sw	$zero,0x1af8($t8)
/*  f0c6b0c:	8d0e0284 */ 	lw	$t6,0x284($t0)
/*  f0c6b10:	c5c01b48 */ 	lwc1	$f0,0x1b48($t6)
.L0f0c6b14:
/*  f0c6b14:	c42ad80c */ 	lwc1	$f10,%lo(var7f1ad80c)($at)
/*  f0c6b18:	460a0302 */ 	mul.s	$f12,$f0,$f10
/*  f0c6b1c:	0c0068f4 */ 	jal	cosf
/*  f0c6b20:	00000000 */ 	nop
/*  f0c6b24:	3c013f80 */ 	lui	$at,0x3f80
/*  f0c6b28:	44811000 */ 	mtc1	$at,$f2
/*  f0c6b2c:	3c013f00 */ 	lui	$at,0x3f00
/*  f0c6b30:	44812000 */ 	mtc1	$at,$f4
/*  f0c6b34:	46020180 */ 	add.s	$f6,$f0,$f2
/*  f0c6b38:	3c08800a */ 	lui	$t0,%hi(g_Vars)
/*  f0c6b3c:	25089fc0 */ 	addiu	$t0,$t0,%lo(g_Vars)
/*  f0c6b40:	8d0f0284 */ 	lw	$t7,0x284($t0)
/*  f0c6b44:	46043202 */ 	mul.s	$f8,$f6,$f4
/*  f0c6b48:	4480a000 */ 	mtc1	$zero,$f20
/*  f0c6b4c:	00000000 */ 	nop
/*  f0c6b50:	4406a000 */ 	mfc1	$a2,$f20
/*  f0c6b54:	4600a306 */ 	mov.s	$f12,$f20
/*  f0c6b58:	4600a386 */ 	mov.s	$f14,$f20
/*  f0c6b5c:	46081281 */ 	sub.s	$f10,$f2,$f8
/*  f0c6b60:	e5ea1b4c */ 	swc1	$f10,0x1b4c($t7)
/*  f0c6b64:	8d030284 */ 	lw	$v1,0x284($t0)
/*  f0c6b68:	c4661b4c */ 	lwc1	$f6,0x1b4c($v1)
/*  f0c6b6c:	24671b08 */ 	addiu	$a3,$v1,0x1b08
/*  f0c6b70:	46061101 */ 	sub.s	$f4,$f2,$f6
/*  f0c6b74:	0fc330ee */ 	jal	bmoveUpdateHead
/*  f0c6b78:	e7a40010 */ 	swc1	$f4,0x10($sp)
/*  f0c6b7c:	3c08800a */ 	lui	$t0,%hi(g_Vars)
/*  f0c6b80:	25089fc0 */ 	addiu	$t0,$t0,%lo(g_Vars)
/*  f0c6b84:	8d090284 */ 	lw	$t1,0x284($t0)
/*  f0c6b88:	27a400cc */ 	addiu	$a0,$sp,0xcc
/*  f0c6b8c:	0fc32ed2 */ 	jal	bmoveUpdateMoveInitSpeed
/*  f0c6b90:	e53400cc */ 	swc1	$f20,0xcc($t1)
/*  f0c6b94:	4405a000 */ 	mfc1	$a1,$f20
/*  f0c6b98:	4407a000 */ 	mfc1	$a3,$f20
/*  f0c6b9c:	240a003f */ 	addiu	$t2,$zero,0x3f
/*  f0c6ba0:	afaa0010 */ 	sw	$t2,0x10($sp)
/*  f0c6ba4:	27a400cc */ 	addiu	$a0,$sp,0xcc
/*  f0c6ba8:	0fc31094 */ 	jal	bwalkCalculateNewPositionWithPush
/*  f0c6bac:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f0c6bb0:	3c08800a */ 	lui	$t0,%hi(g_Vars)
/*  f0c6bb4:	100002ea */ 	b	.L0f0c7760
/*  f0c6bb8:	25089fc0 */ 	addiu	$t0,$t0,%lo(g_Vars)
.L0f0c6bbc:
/*  f0c6bbc:	0fc317fa */ 	jal	bwalkApplyCrouchSpeed
/*  f0c6bc0:	00000000 */ 	nop
/*  f0c6bc4:	0fc31860 */ 	jal	bwalkUpdateCrouchOffset
/*  f0c6bc8:	00000000 */ 	nop
/*  f0c6bcc:	3c08800a */ 	lui	$t0,%hi(g_Vars)
/*  f0c6bd0:	25089fc0 */ 	addiu	$t0,$t0,%lo(g_Vars)
/*  f0c6bd4:	8d030284 */ 	lw	$v1,0x284($t0)
/*  f0c6bd8:	27a400c8 */ 	addiu	$a0,$sp,0xc8
/*  f0c6bdc:	27a500c4 */ 	addiu	$a1,$sp,0xc4
/*  f0c6be0:	c468014c */ 	lwc1	$f8,0x14c($v1)
/*  f0c6be4:	8c670150 */ 	lw	$a3,0x150($v1)
/*  f0c6be8:	2466017c */ 	addiu	$a2,$v1,0x17c
/*  f0c6bec:	0fc32ea2 */ 	jal	bmove0f0cba88
/*  f0c6bf0:	e7a80010 */ 	swc1	$f8,0x10($sp)
/*  f0c6bf4:	3c08800a */ 	lui	$t0,%hi(g_Vars)
/*  f0c6bf8:	25089fc0 */ 	addiu	$t0,$t0,%lo(g_Vars)
/*  f0c6bfc:	8d030284 */ 	lw	$v1,0x284($t0)
/*  f0c6c00:	3c01c234 */ 	lui	$at,0xc234
/*  f0c6c04:	c7a800c0 */ 	lwc1	$f8,0xc0($sp)
/*  f0c6c08:	c46c00a0 */ 	lwc1	$f12,0xa0($v1)
/*  f0c6c0c:	c46a0374 */ 	lwc1	$f10,0x374($v1)
/*  f0c6c10:	c464036c */ 	lwc1	$f4,0x36c($v1)
/*  f0c6c14:	46006187 */ 	neg.s	$f6,$f12
/*  f0c6c18:	c47000b4 */ 	lwc1	$f16,0xb4($v1)
/*  f0c6c1c:	46065002 */ 	mul.s	$f0,$f10,$f6
/*  f0c6c20:	44815000 */ 	mtc1	$at,$f10
/*  f0c6c24:	4480a000 */ 	mtc1	$zero,$f20
/*  f0c6c28:	460c2382 */ 	mul.s	$f14,$f4,$f12
/*  f0c6c2c:	460a803c */ 	c.lt.s	$f16,$f10
/*  f0c6c30:	4600a086 */ 	mov.s	$f2,$f20
/*  f0c6c34:	46080002 */ 	mul.s	$f0,$f0,$f8
/*  f0c6c38:	00000000 */ 	nop
/*  f0c6c3c:	46087382 */ 	mul.s	$f14,$f14,$f8
/*  f0c6c40:	4500000a */ 	bc1f	.L0f0c6c6c
/*  f0c6c44:	00000000 */ 	nop
/*  f0c6c48:	3c017f1b */ 	lui	$at,%hi(var7f1ad810)
/*  f0c6c4c:	c426d810 */ 	lwc1	$f6,%lo(var7f1ad810)($at)
/*  f0c6c50:	3c017f1b */ 	lui	$at,%hi(var7f1ad814)
/*  f0c6c54:	c424d814 */ 	lwc1	$f4,%lo(var7f1ad814)($at)
/*  f0c6c58:	46060002 */ 	mul.s	$f0,$f0,$f6
/*  f0c6c5c:	00000000 */ 	nop
/*  f0c6c60:	46047382 */ 	mul.s	$f14,$f14,$f4
/*  f0c6c64:	1000000b */ 	b	.L0f0c6c94
/*  f0c6c68:	00000000 */ 	nop
.L0f0c6c6c:
/*  f0c6c6c:	4614803c */ 	c.lt.s	$f16,$f20
/*  f0c6c70:	3c013f00 */ 	lui	$at,0x3f00
/*  f0c6c74:	45020008 */ 	bc1fl	.L0f0c6c98
/*  f0c6c78:	c46600a4 */ 	lwc1	$f6,0xa4($v1)
/*  f0c6c7c:	44814000 */ 	mtc1	$at,$f8
/*  f0c6c80:	44815000 */ 	mtc1	$at,$f10
/*  f0c6c84:	46080002 */ 	mul.s	$f0,$f0,$f8
/*  f0c6c88:	00000000 */ 	nop
/*  f0c6c8c:	460a7382 */ 	mul.s	$f14,$f14,$f10
/*  f0c6c90:	00000000 */ 	nop
.L0f0c6c94:
/*  f0c6c94:	c46600a4 */ 	lwc1	$f6,0xa4($v1)
.L0f0c6c98:
/*  f0c6c98:	c46400a8 */ 	lwc1	$f4,0xa8($v1)
/*  f0c6c9c:	e7a200a8 */ 	swc1	$f2,0xa8($sp)
/*  f0c6ca0:	46060401 */ 	sub.s	$f16,$f0,$f6
/*  f0c6ca4:	46047481 */ 	sub.s	$f18,$f14,$f4
/*  f0c6ca8:	46108202 */ 	mul.s	$f8,$f16,$f16
/*  f0c6cac:	e7b000b4 */ 	swc1	$f16,0xb4($sp)
/*  f0c6cb0:	46129282 */ 	mul.s	$f10,$f18,$f18
/*  f0c6cb4:	e7b200b0 */ 	swc1	$f18,0xb0($sp)
/*  f0c6cb8:	0c012974 */ 	jal	sqrtf
/*  f0c6cbc:	460a4300 */ 	add.s	$f12,$f8,$f10
/*  f0c6cc0:	3c08800a */ 	lui	$t0,%hi(g_Vars)
/*  f0c6cc4:	25089fc0 */ 	addiu	$t0,$t0,%lo(g_Vars)
/*  f0c6cc8:	3c014080 */ 	lui	$at,0x4080
/*  f0c6ccc:	44817000 */ 	mtc1	$at,$f14
/*  f0c6cd0:	c512004c */ 	lwc1	$f18,0x4c($t0)
/*  f0c6cd4:	c7a200a8 */ 	lwc1	$f2,0xa8($sp)
/*  f0c6cd8:	4612703c */ 	c.lt.s	$f14,$f18
/*  f0c6cdc:	00000000 */ 	nop
/*  f0c6ce0:	45020005 */ 	bc1fl	.L0f0c6cf8
/*  f0c6ce4:	46009306 */ 	mov.s	$f12,$f18
/*  f0c6ce8:	46007306 */ 	mov.s	$f12,$f14
/*  f0c6cec:	10000003 */ 	b	.L0f0c6cfc
/*  f0c6cf0:	24030004 */ 	addiu	$v1,$zero,0x4
/*  f0c6cf4:	46009306 */ 	mov.s	$f12,$f18
.L0f0c6cf8:
/*  f0c6cf8:	8d030038 */ 	lw	$v1,0x38($t0)
.L0f0c6cfc:
/*  f0c6cfc:	18600008 */ 	blez	$v1,.L0f0c6d20
/*  f0c6d00:	00001025 */ 	or	$v0,$zero,$zero
/*  f0c6d04:	3c017f1b */ 	lui	$at,%hi(var7f1ad818)
/*  f0c6d08:	c42ed818 */ 	lwc1	$f14,%lo(var7f1ad818)($at)
.L0f0c6d0c:
/*  f0c6d0c:	46020181 */ 	sub.s	$f6,$f0,$f2
/*  f0c6d10:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f0c6d14:	460e3102 */ 	mul.s	$f4,$f6,$f14
/*  f0c6d18:	1443fffc */ 	bne	$v0,$v1,.L0f0c6d0c
/*  f0c6d1c:	46041080 */ 	add.s	$f2,$f2,$f4
.L0f0c6d20:
/*  f0c6d20:	3c017f1b */ 	lui	$at,%hi(var7f1ad81c)
/*  f0c6d24:	c42ed81c */ 	lwc1	$f14,%lo(var7f1ad81c)($at)
/*  f0c6d28:	3c014070 */ 	lui	$at,0x4070
/*  f0c6d2c:	44814000 */ 	mtc1	$at,$f8
/*  f0c6d30:	8d030284 */ 	lw	$v1,0x284($t0)
/*  f0c6d34:	3c01c234 */ 	lui	$at,0xc234
/*  f0c6d38:	44813000 */ 	mtc1	$at,$f6
/*  f0c6d3c:	c47000b4 */ 	lwc1	$f16,0xb4($v1)
/*  f0c6d40:	460c4282 */ 	mul.s	$f10,$f8,$f12
/*  f0c6d44:	4606803c */ 	c.lt.s	$f16,$f6
/*  f0c6d48:	00000000 */ 	nop
/*  f0c6d4c:	45000006 */ 	bc1f	.L0f0c6d68
/*  f0c6d50:	460a1080 */ 	add.s	$f2,$f2,$f10
/*  f0c6d54:	3c017f1b */ 	lui	$at,%hi(var7f1ad820)
/*  f0c6d58:	c424d820 */ 	lwc1	$f4,%lo(var7f1ad820)($at)
/*  f0c6d5c:	46041082 */ 	mul.s	$f2,$f2,$f4
/*  f0c6d60:	1000000a */ 	b	.L0f0c6d8c
/*  f0c6d64:	4600103c */ 	c.lt.s	$f2,$f0
.L0f0c6d68:
/*  f0c6d68:	4614803c */ 	c.lt.s	$f16,$f20
/*  f0c6d6c:	3c013f00 */ 	lui	$at,0x3f00
/*  f0c6d70:	45020006 */ 	bc1fl	.L0f0c6d8c
/*  f0c6d74:	4600103c */ 	c.lt.s	$f2,$f0
/*  f0c6d78:	44814000 */ 	mtc1	$at,$f8
/*  f0c6d7c:	00000000 */ 	nop
/*  f0c6d80:	46081082 */ 	mul.s	$f2,$f2,$f8
/*  f0c6d84:	00000000 */ 	nop
/*  f0c6d88:	4600103c */ 	c.lt.s	$f2,$f0
.L0f0c6d8c:
/*  f0c6d8c:	00000000 */ 	nop
/*  f0c6d90:	4502000a */ 	bc1fl	.L0f0c6dbc
/*  f0c6d94:	c46a0168 */ 	lwc1	$f10,0x168($v1)
/*  f0c6d98:	46001083 */ 	div.s	$f2,$f2,$f0
/*  f0c6d9c:	c7aa00b4 */ 	lwc1	$f10,0xb4($sp)
/*  f0c6da0:	c7a400b0 */ 	lwc1	$f4,0xb0($sp)
/*  f0c6da4:	46025182 */ 	mul.s	$f6,$f10,$f2
/*  f0c6da8:	00000000 */ 	nop
/*  f0c6dac:	46022202 */ 	mul.s	$f8,$f4,$f2
/*  f0c6db0:	e7a600b4 */ 	swc1	$f6,0xb4($sp)
/*  f0c6db4:	e7a800b0 */ 	swc1	$f8,0xb0($sp)
/*  f0c6db8:	c46a0168 */ 	lwc1	$f10,0x168($v1)
.L0f0c6dbc:
/*  f0c6dbc:	c7a600c4 */ 	lwc1	$f6,0xc4($sp)
/*  f0c6dc0:	3c017f1b */ 	lui	$at,%hi(var7f1ad824)
/*  f0c6dc4:	c428d824 */ 	lwc1	$f8,%lo(var7f1ad824)($at)
/*  f0c6dc8:	46065100 */ 	add.s	$f4,$f10,$f6
/*  f0c6dcc:	3c017f1b */ 	lui	$at,%hi(var7f1ad828)
/*  f0c6dd0:	c7a600c8 */ 	lwc1	$f6,0xc8($sp)
/*  f0c6dd4:	c46a0170 */ 	lwc1	$f10,0x170($v1)
/*  f0c6dd8:	46082082 */ 	mul.s	$f2,$f4,$f8
/*  f0c6ddc:	c428d828 */ 	lwc1	$f8,%lo(var7f1ad828)($at)
/*  f0c6de0:	c4640148 */ 	lwc1	$f4,0x148($v1)
/*  f0c6de4:	46082402 */ 	mul.s	$f16,$f4,$f8
/*  f0c6de8:	46065300 */ 	add.s	$f12,$f10,$f6
/*  f0c6dec:	4614103c */ 	c.lt.s	$f2,$f20
/*  f0c6df0:	00000000 */ 	nop
/*  f0c6df4:	45020003 */ 	bc1fl	.L0f0c6e04
/*  f0c6df8:	4614603c */ 	c.lt.s	$f12,$f20
/*  f0c6dfc:	46001087 */ 	neg.s	$f2,$f2
/*  f0c6e00:	4614603c */ 	c.lt.s	$f12,$f20
.L0f0c6e04:
/*  f0c6e04:	00000000 */ 	nop
/*  f0c6e08:	45020003 */ 	bc1fl	.L0f0c6e18
/*  f0c6e0c:	4614803c */ 	c.lt.s	$f16,$f20
/*  f0c6e10:	46006307 */ 	neg.s	$f12,$f12
/*  f0c6e14:	4614803c */ 	c.lt.s	$f16,$f20
.L0f0c6e18:
/*  f0c6e18:	e7b0007c */ 	swc1	$f16,0x7c($sp)
/*  f0c6e1c:	45020004 */ 	bc1fl	.L0f0c6e30
/*  f0c6e20:	4602603c */ 	c.lt.s	$f12,$f2
/*  f0c6e24:	46008407 */ 	neg.s	$f16,$f16
/*  f0c6e28:	e7b0007c */ 	swc1	$f16,0x7c($sp)
/*  f0c6e2c:	4602603c */ 	c.lt.s	$f12,$f2
.L0f0c6e30:
/*  f0c6e30:	46006406 */ 	mov.s	$f16,$f12
/*  f0c6e34:	45020003 */ 	bc1fl	.L0f0c6e44
/*  f0c6e38:	c7a2007c */ 	lwc1	$f2,0x7c($sp)
/*  f0c6e3c:	46001406 */ 	mov.s	$f16,$f2
/*  f0c6e40:	c7a2007c */ 	lwc1	$f2,0x7c($sp)
.L0f0c6e44:
/*  f0c6e44:	4602803c */ 	c.lt.s	$f16,$f2
/*  f0c6e48:	00000000 */ 	nop
/*  f0c6e4c:	45020003 */ 	bc1fl	.L0f0c6e5c
/*  f0c6e50:	4600703e */ 	c.le.s	$f14,$f0
/*  f0c6e54:	46001406 */ 	mov.s	$f16,$f2
/*  f0c6e58:	4600703e */ 	c.le.s	$f14,$f0
.L0f0c6e5c:
/*  f0c6e5c:	00000000 */ 	nop
/*  f0c6e60:	45000007 */ 	bc1f	.L0f0c6e80
/*  f0c6e64:	3c017f1b */ 	lui	$at,%hi(var7f1ad82c)
/*  f0c6e68:	c420d82c */ 	lwc1	$f0,%lo(var7f1ad82c)($at)
/*  f0c6e6c:	4600803c */ 	c.lt.s	$f16,$f0
/*  f0c6e70:	00000000 */ 	nop
/*  f0c6e74:	45020003 */ 	bc1fl	.L0f0c6e84
/*  f0c6e78:	3c013f40 */ 	lui	$at,0x3f40
/*  f0c6e7c:	46000406 */ 	mov.s	$f16,$f0
.L0f0c6e80:
/*  f0c6e80:	3c013f40 */ 	lui	$at,0x3f40
.L0f0c6e84:
/*  f0c6e84:	44810000 */ 	mtc1	$at,$f0
/*  f0c6e88:	00000000 */ 	nop
/*  f0c6e8c:	4610003e */ 	c.le.s	$f0,$f16
/*  f0c6e90:	00000000 */ 	nop
/*  f0c6e94:	4502000b */ 	bc1fl	.L0f0c6ec4
/*  f0c6e98:	46100101 */ 	sub.s	$f4,$f0,$f16
/*  f0c6e9c:	46008281 */ 	sub.s	$f10,$f16,$f0
/*  f0c6ea0:	3c014461 */ 	lui	$at,0x4461
/*  f0c6ea4:	44812000 */ 	mtc1	$at,$f4
/*  f0c6ea8:	46125182 */ 	mul.s	$f6,$f10,$f18
/*  f0c6eac:	c46a0198 */ 	lwc1	$f10,0x198($v1)
/*  f0c6eb0:	46043203 */ 	div.s	$f8,$f6,$f4
/*  f0c6eb4:	46085180 */ 	add.s	$f6,$f10,$f8
/*  f0c6eb8:	10000009 */ 	b	.L0f0c6ee0
/*  f0c6ebc:	e4660198 */ 	swc1	$f6,0x198($v1)
/*  f0c6ec0:	46100101 */ 	sub.s	$f4,$f0,$f16
.L0f0c6ec4:
/*  f0c6ec4:	3c017f1b */ 	lui	$at,%hi(var7f1ad830)
/*  f0c6ec8:	c428d830 */ 	lwc1	$f8,%lo(var7f1ad830)($at)
/*  f0c6ecc:	46122282 */ 	mul.s	$f10,$f4,$f18
/*  f0c6ed0:	c4640198 */ 	lwc1	$f4,0x198($v1)
/*  f0c6ed4:	46085183 */ 	div.s	$f6,$f10,$f8
/*  f0c6ed8:	46062281 */ 	sub.s	$f10,$f4,$f6
/*  f0c6edc:	e46a0198 */ 	swc1	$f10,0x198($v1)
.L0f0c6ee0:
/*  f0c6ee0:	8d030284 */ 	lw	$v1,0x284($t0)
/*  f0c6ee4:	c4600198 */ 	lwc1	$f0,0x198($v1)
/*  f0c6ee8:	4614003c */ 	c.lt.s	$f0,$f20
/*  f0c6eec:	00000000 */ 	nop
/*  f0c6ef0:	45020005 */ 	bc1fl	.L0f0c6f08
/*  f0c6ef4:	3c013f80 */ 	lui	$at,0x3f80
/*  f0c6ef8:	e4740198 */ 	swc1	$f20,0x198($v1)
/*  f0c6efc:	1000000c */ 	b	.L0f0c6f30
/*  f0c6f00:	8d030284 */ 	lw	$v1,0x284($t0)
/*  f0c6f04:	3c013f80 */ 	lui	$at,0x3f80
.L0f0c6f08:
/*  f0c6f08:	44814000 */ 	mtc1	$at,$f8
/*  f0c6f0c:	3c013f80 */ 	lui	$at,0x3f80
/*  f0c6f10:	4600403c */ 	c.lt.s	$f8,$f0
/*  f0c6f14:	00000000 */ 	nop
/*  f0c6f18:	45000005 */ 	bc1f	.L0f0c6f30
/*  f0c6f1c:	00000000 */ 	nop
/*  f0c6f20:	44812000 */ 	mtc1	$at,$f4
/*  f0c6f24:	00000000 */ 	nop
/*  f0c6f28:	e4640198 */ 	swc1	$f4,0x198($v1)
/*  f0c6f2c:	8d030284 */ 	lw	$v1,0x284($t0)
.L0f0c6f30:
/*  f0c6f30:	3c018007 */ 	lui	$at,%hi(var80075c00+0x24)
/*  f0c6f34:	c4265c24 */ 	lwc1	$f6,%lo(var80075c00+0x24)($at)
/*  f0c6f38:	3c013f00 */ 	lui	$at,0x3f00
/*  f0c6f3c:	44815000 */ 	mtc1	$at,$f10
/*  f0c6f40:	c504004c */ 	lwc1	$f4,0x4c($t0)
/*  f0c6f44:	2404000a */ 	addiu	$a0,$zero,0xa
/*  f0c6f48:	460a3202 */ 	mul.s	$f8,$f6,$f10
/*  f0c6f4c:	c7aa00c0 */ 	lwc1	$f10,0xc0($sp)
/*  f0c6f50:	c4660168 */ 	lwc1	$f6,0x168($v1)
/*  f0c6f54:	e7b00078 */ 	swc1	$f16,0x78($sp)
/*  f0c6f58:	46044002 */ 	mul.s	$f0,$f8,$f4
/*  f0c6f5c:	c7a400c4 */ 	lwc1	$f4,0xc4($sp)
/*  f0c6f60:	460a3202 */ 	mul.s	$f8,$f6,$f10
/*  f0c6f64:	46044180 */ 	add.s	$f6,$f8,$f4
/*  f0c6f68:	46003082 */ 	mul.s	$f2,$f6,$f0
/*  f0c6f6c:	0fc41b99 */ 	jal	cheatIsActive
/*  f0c6f70:	e7a200e0 */ 	swc1	$f2,0xe0($sp)
/*  f0c6f74:	3c08800a */ 	lui	$t0,%hi(g_Vars)
/*  f0c6f78:	25089fc0 */ 	addiu	$t0,$t0,%lo(g_Vars)
/*  f0c6f7c:	10400004 */ 	beqz	$v0,.L0f0c6f90
/*  f0c6f80:	c7a200e0 */ 	lwc1	$f2,0xe0($sp)
/*  f0c6f84:	3c017f1b */ 	lui	$at,%hi(var7f1ad834)
/*  f0c6f88:	c42ad834 */ 	lwc1	$f10,%lo(var7f1ad834)($at)
/*  f0c6f8c:	460a1083 */ 	div.s	$f2,$f2,$f10
.L0f0c6f90:
/*  f0c6f90:	8d0b0284 */ 	lw	$t3,0x284($t0)
/*  f0c6f94:	c7a400c0 */ 	lwc1	$f4,0xc0($sp)
/*  f0c6f98:	c7aa00c8 */ 	lwc1	$f10,0xc8($sp)
/*  f0c6f9c:	c5680170 */ 	lwc1	$f8,0x170($t3)
/*  f0c6fa0:	44061000 */ 	mfc1	$a2,$f2
/*  f0c6fa4:	c7ac0078 */ 	lwc1	$f12,0x78($sp)
/*  f0c6fa8:	46044182 */ 	mul.s	$f6,$f8,$f4
/*  f0c6fac:	0fc33195 */ 	jal	bmove0f0cc654
/*  f0c6fb0:	460a3380 */ 	add.s	$f14,$f6,$f10
/*  f0c6fb4:	3c08800a */ 	lui	$t0,%hi(g_Vars)
/*  f0c6fb8:	25089fc0 */ 	addiu	$t0,$t0,%lo(g_Vars)
/*  f0c6fbc:	8d0c0284 */ 	lw	$t4,0x284($t0)
/*  f0c6fc0:	c7a80078 */ 	lwc1	$f8,0x78($sp)
/*  f0c6fc4:	2404000a */ 	addiu	$a0,$zero,0xa
/*  f0c6fc8:	e58800cc */ 	swc1	$f8,0xcc($t4)
/*  f0c6fcc:	8d030284 */ 	lw	$v1,0x284($t0)
/*  f0c6fd0:	c46003c0 */ 	lwc1	$f0,0x3c0($v1)
/*  f0c6fd4:	c46203c8 */ 	lwc1	$f2,0x3c8($v1)
/*  f0c6fd8:	e7a000dc */ 	swc1	$f0,0xdc($sp)
/*  f0c6fdc:	0fc41b99 */ 	jal	cheatIsActive
/*  f0c6fe0:	e7a200d8 */ 	swc1	$f2,0xd8($sp)
/*  f0c6fe4:	3c08800a */ 	lui	$t0,%hi(g_Vars)
/*  f0c6fe8:	25089fc0 */ 	addiu	$t0,$t0,%lo(g_Vars)
/*  f0c6fec:	c7a000dc */ 	lwc1	$f0,0xdc($sp)
/*  f0c6ff0:	10400005 */ 	beqz	$v0,.L0f0c7008
/*  f0c6ff4:	c7a200d8 */ 	lwc1	$f2,0xd8($sp)
/*  f0c6ff8:	3c017f1b */ 	lui	$at,%hi(var7f1ad838)
/*  f0c6ffc:	c424d838 */ 	lwc1	$f4,%lo(var7f1ad838)($at)
/*  f0c7000:	46040002 */ 	mul.s	$f0,$f0,$f4
/*  f0c7004:	00000000 */ 	nop
.L0f0c7008:
/*  f0c7008:	8d030284 */ 	lw	$v1,0x284($t0)
/*  f0c700c:	c512004c */ 	lwc1	$f18,0x4c($t0)
/*  f0c7010:	27a400cc */ 	addiu	$a0,$sp,0xcc
/*  f0c7014:	c466036c */ 	lwc1	$f6,0x36c($v1)
/*  f0c7018:	c4680374 */ 	lwc1	$f8,0x374($v1)
/*  f0c701c:	46061282 */ 	mul.s	$f10,$f2,$f6
/*  f0c7020:	00000000 */ 	nop
/*  f0c7024:	46080102 */ 	mul.s	$f4,$f0,$f8
/*  f0c7028:	46045181 */ 	sub.s	$f6,$f10,$f4
/*  f0c702c:	c7aa00cc */ 	lwc1	$f10,0xcc($sp)
/*  f0c7030:	46123202 */ 	mul.s	$f8,$f6,$f18
/*  f0c7034:	46085100 */ 	add.s	$f4,$f10,$f8
/*  f0c7038:	e7a400cc */ 	swc1	$f4,0xcc($sp)
/*  f0c703c:	c4660374 */ 	lwc1	$f6,0x374($v1)
/*  f0c7040:	c468036c */ 	lwc1	$f8,0x36c($v1)
/*  f0c7044:	46061282 */ 	mul.s	$f10,$f2,$f6
/*  f0c7048:	00000000 */ 	nop
/*  f0c704c:	46080182 */ 	mul.s	$f6,$f0,$f8
/*  f0c7050:	46065200 */ 	add.s	$f8,$f10,$f6
/*  f0c7054:	c7a600d4 */ 	lwc1	$f6,0xd4($sp)
/*  f0c7058:	46124282 */ 	mul.s	$f10,$f8,$f18
/*  f0c705c:	460a3200 */ 	add.s	$f8,$f6,$f10
/*  f0c7060:	c7a600b4 */ 	lwc1	$f6,0xb4($sp)
/*  f0c7064:	46062280 */ 	add.s	$f10,$f4,$f6
/*  f0c7068:	c7a400b0 */ 	lwc1	$f4,0xb0($sp)
/*  f0c706c:	e7a800d4 */ 	swc1	$f8,0xd4($sp)
/*  f0c7070:	46044180 */ 	add.s	$f6,$f8,$f4
/*  f0c7074:	e7aa00cc */ 	swc1	$f10,0xcc($sp)
/*  f0c7078:	0fc32ed2 */ 	jal	bmoveUpdateMoveInitSpeed
/*  f0c707c:	e7a600d4 */ 	swc1	$f6,0xd4($sp)
/*  f0c7080:	0fc47b82 */ 	jal	debugIsTurboModeEnabled
/*  f0c7084:	00000000 */ 	nop
/*  f0c7088:	3c08800a */ 	lui	$t0,%hi(g_Vars)
/*  f0c708c:	1040001f */ 	beqz	$v0,.L0f0c710c
/*  f0c7090:	25089fc0 */ 	addiu	$t0,$t0,%lo(g_Vars)
/*  f0c7094:	8d030284 */ 	lw	$v1,0x284($t0)
/*  f0c7098:	c512004c */ 	lwc1	$f18,0x4c($t0)
/*  f0c709c:	3c014120 */ 	lui	$at,0x4120
/*  f0c70a0:	c46a036c */ 	lwc1	$f10,0x36c($v1)
/*  f0c70a4:	c4680170 */ 	lwc1	$f8,0x170($v1)
/*  f0c70a8:	c4660374 */ 	lwc1	$f6,0x374($v1)
/*  f0c70ac:	44810000 */ 	mtc1	$at,$f0
/*  f0c70b0:	46085102 */ 	mul.s	$f4,$f10,$f8
/*  f0c70b4:	c46a0168 */ 	lwc1	$f10,0x168($v1)
/*  f0c70b8:	460a3202 */ 	mul.s	$f8,$f6,$f10
/*  f0c70bc:	46082181 */ 	sub.s	$f6,$f4,$f8
/*  f0c70c0:	c7a800cc */ 	lwc1	$f8,0xcc($sp)
/*  f0c70c4:	46123282 */ 	mul.s	$f10,$f6,$f18
/*  f0c70c8:	00000000 */ 	nop
/*  f0c70cc:	46005102 */ 	mul.s	$f4,$f10,$f0
/*  f0c70d0:	46044180 */ 	add.s	$f6,$f8,$f4
/*  f0c70d4:	e7a600cc */ 	swc1	$f6,0xcc($sp)
/*  f0c70d8:	c4680170 */ 	lwc1	$f8,0x170($v1)
/*  f0c70dc:	c46a0374 */ 	lwc1	$f10,0x374($v1)
/*  f0c70e0:	c466036c */ 	lwc1	$f6,0x36c($v1)
/*  f0c70e4:	46085102 */ 	mul.s	$f4,$f10,$f8
/*  f0c70e8:	c46a0168 */ 	lwc1	$f10,0x168($v1)
/*  f0c70ec:	460a3202 */ 	mul.s	$f8,$f6,$f10
/*  f0c70f0:	46082180 */ 	add.s	$f6,$f4,$f8
/*  f0c70f4:	c7a800d4 */ 	lwc1	$f8,0xd4($sp)
/*  f0c70f8:	46123282 */ 	mul.s	$f10,$f6,$f18
/*  f0c70fc:	00000000 */ 	nop
/*  f0c7100:	46005102 */ 	mul.s	$f4,$f10,$f0
/*  f0c7104:	46044180 */ 	add.s	$f6,$f8,$f4
/*  f0c7108:	e7a600d4 */ 	swc1	$f6,0xd4($sp)
.L0f0c710c:
/*  f0c710c:	8d030284 */ 	lw	$v1,0x284($t0)
/*  f0c7110:	c4601b6c */ 	lwc1	$f0,0x1b6c($v1)
/*  f0c7114:	4600a032 */ 	c.eq.s	$f20,$f0
/*  f0c7118:	00000000 */ 	nop
/*  f0c711c:	45020007 */ 	bc1fl	.L0f0c713c
/*  f0c7120:	c512004c */ 	lwc1	$f18,0x4c($t0)
/*  f0c7124:	c46a1b74 */ 	lwc1	$f10,0x1b74($v1)
/*  f0c7128:	460aa032 */ 	c.eq.s	$f20,$f10
/*  f0c712c:	00000000 */ 	nop
/*  f0c7130:	4503000c */ 	bc1tl	.L0f0c7164
/*  f0c7134:	8c6d02ac */ 	lw	$t5,0x2ac($v1)
/*  f0c7138:	c512004c */ 	lwc1	$f18,0x4c($t0)
.L0f0c713c:
/*  f0c713c:	c7a800cc */ 	lwc1	$f8,0xcc($sp)
/*  f0c7140:	c7aa00d4 */ 	lwc1	$f10,0xd4($sp)
/*  f0c7144:	46120102 */ 	mul.s	$f4,$f0,$f18
/*  f0c7148:	46044180 */ 	add.s	$f6,$f8,$f4
/*  f0c714c:	e7a600cc */ 	swc1	$f6,0xcc($sp)
/*  f0c7150:	c4681b74 */ 	lwc1	$f8,0x1b74($v1)
/*  f0c7154:	46124102 */ 	mul.s	$f4,$f8,$f18
/*  f0c7158:	46045180 */ 	add.s	$f6,$f10,$f4
/*  f0c715c:	e7a600d4 */ 	swc1	$f6,0xd4($sp)
/*  f0c7160:	8c6d02ac */ 	lw	$t5,0x2ac($v1)
.L0f0c7164:
/*  f0c7164:	246402a0 */ 	addiu	$a0,$v1,0x2a0
/*  f0c7168:	246502a4 */ 	addiu	$a1,$v1,0x2a4
/*  f0c716c:	51a0006a */ 	beqzl	$t5,.L0f0c7318
/*  f0c7170:	8c640298 */ 	lw	$a0,0x298($v1)
/*  f0c7174:	0c0011e4 */ 	jal	guNormalize
/*  f0c7178:	246602a8 */ 	addiu	$a2,$v1,0x2a8
/*  f0c717c:	3c08800a */ 	lui	$t0,%hi(g_Vars)
/*  f0c7180:	25089fc0 */ 	addiu	$t0,$t0,%lo(g_Vars)
/*  f0c7184:	8d030284 */ 	lw	$v1,0x284($t0)
/*  f0c7188:	c7aa00d4 */ 	lwc1	$f10,0xd4($sp)
/*  f0c718c:	c7a600cc */ 	lwc1	$f6,0xcc($sp)
/*  f0c7190:	c46802a8 */ 	lwc1	$f8,0x2a8($v1)
/*  f0c7194:	c46202a0 */ 	lwc1	$f2,0x2a0($v1)
/*  f0c7198:	3c01c080 */ 	lui	$at,0xc080
/*  f0c719c:	460a4102 */ 	mul.s	$f4,$f8,$f10
/*  f0c71a0:	00000000 */ 	nop
/*  f0c71a4:	46023202 */ 	mul.s	$f8,$f6,$f2
/*  f0c71a8:	46082000 */ 	add.s	$f0,$f4,$f8
/*  f0c71ac:	c508004c */ 	lwc1	$f8,0x4c($t0)
/*  f0c71b0:	44812000 */ 	mtc1	$at,$f4
/*  f0c71b4:	46000007 */ 	neg.s	$f0,$f0
/*  f0c71b8:	46082102 */ 	mul.s	$f4,$f4,$f8
/*  f0c71bc:	4600203c */ 	c.lt.s	$f4,$f0
/*  f0c71c0:	00000000 */ 	nop
/*  f0c71c4:	45000051 */ 	bc1f	.L0f0c730c
/*  f0c71c8:	00000000 */ 	nop
/*  f0c71cc:	4614003c */ 	c.lt.s	$f0,$f20
/*  f0c71d0:	27a50070 */ 	addiu	$a1,$sp,0x70
/*  f0c71d4:	27a6006c */ 	addiu	$a2,$sp,0x6c
/*  f0c71d8:	27a70068 */ 	addiu	$a3,$sp,0x68
/*  f0c71dc:	4502000e */ 	bc1fl	.L0f0c7218
/*  f0c71e0:	8c6400bc */ 	lw	$a0,0xbc($v1)
/*  f0c71e4:	46020202 */ 	mul.s	$f8,$f0,$f2
/*  f0c71e8:	3c017f1b */ 	lui	$at,%hi(var7f1ad83c)
/*  f0c71ec:	c42cd83c */ 	lwc1	$f12,%lo(var7f1ad83c)($at)
/*  f0c71f0:	46083100 */ 	add.s	$f4,$f6,$f8
/*  f0c71f4:	e7a400cc */ 	swc1	$f4,0xcc($sp)
/*  f0c71f8:	c46602a8 */ 	lwc1	$f6,0x2a8($v1)
/*  f0c71fc:	46060202 */ 	mul.s	$f8,$f0,$f6
/*  f0c7200:	46085100 */ 	add.s	$f4,$f10,$f8
/*  f0c7204:	460c0182 */ 	mul.s	$f6,$f0,$f12
/*  f0c7208:	e7a400d4 */ 	swc1	$f4,0xd4($sp)
/*  f0c720c:	10000036 */ 	b	.L0f0c72e8
/*  f0c7210:	e466029c */ 	swc1	$f6,0x29c($v1)
/*  f0c7214:	8c6400bc */ 	lw	$a0,0xbc($v1)
.L0f0c7218:
/*  f0c7218:	0fc3082e */ 	jal	propPlayerGetBbox
/*  f0c721c:	e7a00074 */ 	swc1	$f0,0x74($sp)
/*  f0c7220:	3c08800a */ 	lui	$t0,%hi(g_Vars)
/*  f0c7224:	3c017f1b */ 	lui	$at,%hi(var7f1ad840)
/*  f0c7228:	c428d840 */ 	lwc1	$f8,%lo(var7f1ad840)($at)
/*  f0c722c:	c7aa0070 */ 	lwc1	$f10,0x70($sp)
/*  f0c7230:	25089fc0 */ 	addiu	$t0,$t0,%lo(g_Vars)
/*  f0c7234:	8d030284 */ 	lw	$v1,0x284($t0)
/*  f0c7238:	46085102 */ 	mul.s	$f4,$f10,$f8
/*  f0c723c:	c7a6006c */ 	lwc1	$f6,0x6c($sp)
/*  f0c7240:	8c6200bc */ 	lw	$v0,0xbc($v1)
/*  f0c7244:	c4680074 */ 	lwc1	$f8,0x74($v1)
/*  f0c7248:	3c013f80 */ 	lui	$at,0x3f80
/*  f0c724c:	c442000c */ 	lwc1	$f2,0xc($v0)
/*  f0c7250:	34188040 */ 	dli	$t8,0x8040
/*  f0c7254:	44052000 */ 	mfc1	$a1,$f4
/*  f0c7258:	46023281 */ 	sub.s	$f10,$f6,$f2
/*  f0c725c:	44813000 */ 	mtc1	$at,$f6
/*  f0c7260:	24590028 */ 	addiu	$t9,$v0,0x28
/*  f0c7264:	46024101 */ 	sub.s	$f4,$f8,$f2
/*  f0c7268:	44065000 */ 	mfc1	$a2,$f10
/*  f0c726c:	afb90010 */ 	sw	$t9,0x10($sp)
/*  f0c7270:	afb80014 */ 	sw	$t8,0x14($sp)
/*  f0c7274:	46062280 */ 	add.s	$f10,$f4,$f6
/*  f0c7278:	24440008 */ 	addiu	$a0,$v0,0x8
/*  f0c727c:	44075000 */ 	mfc1	$a3,$f10
/*  f0c7280:	0c00a84f */ 	jal	func0002a13c
/*  f0c7284:	00000000 */ 	nop
/*  f0c7288:	3c08800a */ 	lui	$t0,%hi(g_Vars)
/*  f0c728c:	25089fc0 */ 	addiu	$t0,$t0,%lo(g_Vars)
/*  f0c7290:	14400006 */ 	bnez	$v0,.L0f0c72ac
/*  f0c7294:	c7a00074 */ 	lwc1	$f0,0x74($sp)
/*  f0c7298:	8d0e0284 */ 	lw	$t6,0x284($t0)
/*  f0c729c:	3c017f1b */ 	lui	$at,%hi(var7f1ad844)
/*  f0c72a0:	e5d4029c */ 	swc1	$f20,0x29c($t6)
/*  f0c72a4:	10000010 */ 	b	.L0f0c72e8
/*  f0c72a8:	c42cd844 */ 	lwc1	$f12,%lo(var7f1ad844)($at)
.L0f0c72ac:
/*  f0c72ac:	8d030284 */ 	lw	$v1,0x284($t0)
/*  f0c72b0:	c7a800cc */ 	lwc1	$f8,0xcc($sp)
/*  f0c72b4:	3c017f1b */ 	lui	$at,%hi(var7f1ad848)
/*  f0c72b8:	c46402a0 */ 	lwc1	$f4,0x2a0($v1)
/*  f0c72bc:	c42cd848 */ 	lwc1	$f12,%lo(var7f1ad848)($at)
/*  f0c72c0:	46040182 */ 	mul.s	$f6,$f0,$f4
/*  f0c72c4:	c7a400d4 */ 	lwc1	$f4,0xd4($sp)
/*  f0c72c8:	46064280 */ 	add.s	$f10,$f8,$f6
/*  f0c72cc:	e7aa00cc */ 	swc1	$f10,0xcc($sp)
/*  f0c72d0:	c46802a8 */ 	lwc1	$f8,0x2a8($v1)
/*  f0c72d4:	46080182 */ 	mul.s	$f6,$f0,$f8
/*  f0c72d8:	46062280 */ 	add.s	$f10,$f4,$f6
/*  f0c72dc:	460c0202 */ 	mul.s	$f8,$f0,$f12
/*  f0c72e0:	e7aa00d4 */ 	swc1	$f10,0xd4($sp)
/*  f0c72e4:	e468029c */ 	swc1	$f8,0x29c($v1)
.L0f0c72e8:
/*  f0c72e8:	c7a400cc */ 	lwc1	$f4,0xcc($sp)
/*  f0c72ec:	c7aa00d4 */ 	lwc1	$f10,0xd4($sp)
/*  f0c72f0:	8d030284 */ 	lw	$v1,0x284($t0)
/*  f0c72f4:	460c2182 */ 	mul.s	$f6,$f4,$f12
/*  f0c72f8:	00000000 */ 	nop
/*  f0c72fc:	460c5202 */ 	mul.s	$f8,$f10,$f12
/*  f0c7300:	e7a600cc */ 	swc1	$f6,0xcc($sp)
/*  f0c7304:	10000003 */ 	b	.L0f0c7314
/*  f0c7308:	e7a800d4 */ 	swc1	$f8,0xd4($sp)
.L0f0c730c:
/*  f0c730c:	e474029c */ 	swc1	$f20,0x29c($v1)
/*  f0c7310:	8d030284 */ 	lw	$v1,0x284($t0)
.L0f0c7314:
/*  f0c7314:	8c640298 */ 	lw	$a0,0x298($v1)
.L0f0c7318:
/*  f0c7318:	50800015 */ 	beqzl	$a0,.L0f0c7370
/*  f0c731c:	8c6200bc */ 	lw	$v0,0xbc($v1)
/*  f0c7320:	8c820004 */ 	lw	$v0,0x4($a0)
/*  f0c7324:	2401003b */ 	addiu	$at,$zero,0x3b
/*  f0c7328:	904f0003 */ 	lbu	$t7,0x3($v0)
/*  f0c732c:	55e10010 */ 	bnel	$t7,$at,.L0f0c7370
/*  f0c7330:	8c6200bc */ 	lw	$v0,0xbc($v1)
/*  f0c7334:	8c490014 */ 	lw	$t1,0x14($v0)
/*  f0c7338:	c4460060 */ 	lwc1	$f6,0x60($v0)
/*  f0c733c:	c7a800cc */ 	lwc1	$f8,0xcc($sp)
/*  f0c7340:	c5240008 */ 	lwc1	$f4,0x8($t1)
/*  f0c7344:	46062281 */ 	sub.s	$f10,$f4,$f6
/*  f0c7348:	460a4100 */ 	add.s	$f4,$f8,$f10
/*  f0c734c:	e7a400cc */ 	swc1	$f4,0xcc($sp)
/*  f0c7350:	8c4a0014 */ 	lw	$t2,0x14($v0)
/*  f0c7354:	c4480068 */ 	lwc1	$f8,0x68($v0)
/*  f0c7358:	c7a400d4 */ 	lwc1	$f4,0xd4($sp)
/*  f0c735c:	c5460010 */ 	lwc1	$f6,0x10($t2)
/*  f0c7360:	46083281 */ 	sub.s	$f10,$f6,$f8
/*  f0c7364:	460a2180 */ 	add.s	$f6,$f4,$f10
/*  f0c7368:	e7a600d4 */ 	swc1	$f6,0xd4($sp)
/*  f0c736c:	8c6200bc */ 	lw	$v0,0xbc($v1)
.L0f0c7370:
/*  f0c7370:	27a400cc */ 	addiu	$a0,$sp,0xcc
/*  f0c7374:	00002825 */ 	or	$a1,$zero,$zero
/*  f0c7378:	c4480008 */ 	lwc1	$f8,0x8($v0)
/*  f0c737c:	e7a8008c */ 	swc1	$f8,0x8c($sp)
/*  f0c7380:	c4440010 */ 	lwc1	$f4,0x10($v0)
/*  f0c7384:	e7a40088 */ 	swc1	$f4,0x88($sp)
/*  f0c7388:	c46a00a0 */ 	lwc1	$f10,0xa0($v1)
/*  f0c738c:	460aa032 */ 	c.eq.s	$f20,$f10
/*  f0c7390:	00000000 */ 	nop
/*  f0c7394:	45000002 */ 	bc1f	.L0f0c73a0
/*  f0c7398:	00000000 */ 	nop
/*  f0c739c:	24050001 */ 	addiu	$a1,$zero,0x1
.L0f0c73a0:
/*  f0c73a0:	0fc318ef */ 	jal	bwalk0f0c63bc
/*  f0c73a4:	2406003f */ 	addiu	$a2,$zero,0x3f
/*  f0c73a8:	3c08800a */ 	lui	$t0,%hi(g_Vars)
/*  f0c73ac:	25089fc0 */ 	addiu	$t0,$t0,%lo(g_Vars)
/*  f0c73b0:	8d030284 */ 	lw	$v1,0x284($t0)
/*  f0c73b4:	8c6200bc */ 	lw	$v0,0xbc($v1)
/*  f0c73b8:	c46a0318 */ 	lwc1	$f10,0x318($v1)
/*  f0c73bc:	c4680310 */ 	lwc1	$f8,0x310($v1)
/*  f0c73c0:	c4440010 */ 	lwc1	$f4,0x10($v0)
/*  f0c73c4:	c4460008 */ 	lwc1	$f6,0x8($v0)
/*  f0c73c8:	c462036c */ 	lwc1	$f2,0x36c($v1)
/*  f0c73cc:	460a2381 */ 	sub.s	$f14,$f4,$f10
/*  f0c73d0:	c4600374 */ 	lwc1	$f0,0x374($v1)
/*  f0c73d4:	46083301 */ 	sub.s	$f12,$f6,$f8
/*  f0c73d8:	460e1182 */ 	mul.s	$f6,$f2,$f14
/*  f0c73dc:	46006207 */ 	neg.s	$f8,$f12
/*  f0c73e0:	46004102 */ 	mul.s	$f4,$f8,$f0
/*  f0c73e4:	460ca03e */ 	c.le.s	$f20,$f12
/*  f0c73e8:	460e0282 */ 	mul.s	$f10,$f0,$f14
/*  f0c73ec:	00000000 */ 	nop
/*  f0c73f0:	46026202 */ 	mul.s	$f8,$f12,$f2
/*  f0c73f4:	46043400 */ 	add.s	$f16,$f6,$f4
/*  f0c73f8:	c7a600d4 */ 	lwc1	$f6,0xd4($sp)
/*  f0c73fc:	46061102 */ 	mul.s	$f4,$f2,$f6
/*  f0c7400:	46085480 */ 	add.s	$f18,$f10,$f8
/*  f0c7404:	c7aa00cc */ 	lwc1	$f10,0xcc($sp)
/*  f0c7408:	46005207 */ 	neg.s	$f8,$f10
/*  f0c740c:	46004202 */ 	mul.s	$f8,$f8,$f0
/*  f0c7410:	46082100 */ 	add.s	$f4,$f4,$f8
/*  f0c7414:	46060202 */ 	mul.s	$f8,$f0,$f6
/*  f0c7418:	00000000 */ 	nop
/*  f0c741c:	46025182 */ 	mul.s	$f6,$f10,$f2
/*  f0c7420:	e7a4004c */ 	swc1	$f4,0x4c($sp)
/*  f0c7424:	46064200 */ 	add.s	$f8,$f8,$f6
/*  f0c7428:	4500001c */ 	bc1f	.L0f0c749c
/*  f0c742c:	e7a80048 */ 	swc1	$f8,0x48($sp)
/*  f0c7430:	c460017c */ 	lwc1	$f0,0x17c($v1)
/*  f0c7434:	46002086 */ 	mov.s	$f2,$f4
/*  f0c7438:	c7a400cc */ 	lwc1	$f4,0xcc($sp)
/*  f0c743c:	4600a03c */ 	c.lt.s	$f20,$f0
/*  f0c7440:	00000000 */ 	nop
/*  f0c7444:	4502000f */ 	bc1fl	.L0f0c7484
/*  f0c7448:	4614203c */ 	c.lt.s	$f4,$f20
/*  f0c744c:	460aa03e */ 	c.le.s	$f20,$f10
/*  f0c7450:	00000000 */ 	nop
/*  f0c7454:	4502002c */ 	bc1fl	.L0f0c7508
/*  f0c7458:	460ea03e */ 	c.le.s	$f20,$f14
/*  f0c745c:	460a603c */ 	c.lt.s	$f12,$f10
/*  f0c7460:	00000000 */ 	nop
/*  f0c7464:	45020028 */ 	bc1fl	.L0f0c7508
/*  f0c7468:	460ea03e */ 	c.le.s	$f20,$f14
/*  f0c746c:	460a6183 */ 	div.s	$f6,$f12,$f10
/*  f0c7470:	46060202 */ 	mul.s	$f8,$f0,$f6
/*  f0c7474:	e468017c */ 	swc1	$f8,0x17c($v1)
/*  f0c7478:	10000022 */ 	b	.L0f0c7504
/*  f0c747c:	8d030284 */ 	lw	$v1,0x284($t0)
/*  f0c7480:	4614203c */ 	c.lt.s	$f4,$f20
.L0f0c7484:
/*  f0c7484:	00000000 */ 	nop
/*  f0c7488:	4502001f */ 	bc1fl	.L0f0c7508
/*  f0c748c:	460ea03e */ 	c.le.s	$f20,$f14
/*  f0c7490:	e474017c */ 	swc1	$f20,0x17c($v1)
/*  f0c7494:	1000001b */ 	b	.L0f0c7504
/*  f0c7498:	8d030284 */ 	lw	$v1,0x284($t0)
.L0f0c749c:
/*  f0c749c:	c460017c */ 	lwc1	$f0,0x17c($v1)
/*  f0c74a0:	c7a2004c */ 	lwc1	$f2,0x4c($sp)
/*  f0c74a4:	c7aa00cc */ 	lwc1	$f10,0xcc($sp)
/*  f0c74a8:	4614003c */ 	c.lt.s	$f0,$f20
/*  f0c74ac:	c7a400cc */ 	lwc1	$f4,0xcc($sp)
/*  f0c74b0:	4502000f */ 	bc1fl	.L0f0c74f0
/*  f0c74b4:	4604a03c */ 	c.lt.s	$f20,$f4
/*  f0c74b8:	4614503e */ 	c.le.s	$f10,$f20
/*  f0c74bc:	00000000 */ 	nop
/*  f0c74c0:	45020011 */ 	bc1fl	.L0f0c7508
/*  f0c74c4:	460ea03e */ 	c.le.s	$f20,$f14
/*  f0c74c8:	460c503c */ 	c.lt.s	$f10,$f12
/*  f0c74cc:	00000000 */ 	nop
/*  f0c74d0:	4502000d */ 	bc1fl	.L0f0c7508
/*  f0c74d4:	460ea03e */ 	c.le.s	$f20,$f14
/*  f0c74d8:	460a6183 */ 	div.s	$f6,$f12,$f10
/*  f0c74dc:	46060202 */ 	mul.s	$f8,$f0,$f6
/*  f0c74e0:	e468017c */ 	swc1	$f8,0x17c($v1)
/*  f0c74e4:	10000007 */ 	b	.L0f0c7504
/*  f0c74e8:	8d030284 */ 	lw	$v1,0x284($t0)
/*  f0c74ec:	4604a03c */ 	c.lt.s	$f20,$f4
.L0f0c74f0:
/*  f0c74f0:	00000000 */ 	nop
/*  f0c74f4:	45020004 */ 	bc1fl	.L0f0c7508
/*  f0c74f8:	460ea03e */ 	c.le.s	$f20,$f14
/*  f0c74fc:	e474017c */ 	swc1	$f20,0x17c($v1)
/*  f0c7500:	8d030284 */ 	lw	$v1,0x284($t0)
.L0f0c7504:
/*  f0c7504:	460ea03e */ 	c.le.s	$f20,$f14
.L0f0c7508:
/*  f0c7508:	00000000 */ 	nop
/*  f0c750c:	4502001d */ 	bc1fl	.L0f0c7584
/*  f0c7510:	c4600184 */ 	lwc1	$f0,0x184($v1)
/*  f0c7514:	c4600184 */ 	lwc1	$f0,0x184($v1)
/*  f0c7518:	c7aa00d4 */ 	lwc1	$f10,0xd4($sp)
/*  f0c751c:	c7a400d4 */ 	lwc1	$f4,0xd4($sp)
/*  f0c7520:	4600a03c */ 	c.lt.s	$f20,$f0
/*  f0c7524:	00000000 */ 	nop
/*  f0c7528:	4502000f */ 	bc1fl	.L0f0c7568
/*  f0c752c:	4614203c */ 	c.lt.s	$f4,$f20
/*  f0c7530:	460aa03e */ 	c.le.s	$f20,$f10
/*  f0c7534:	00000000 */ 	nop
/*  f0c7538:	4502002c */ 	bc1fl	.L0f0c75ec
/*  f0c753c:	46141032 */ 	c.eq.s	$f2,$f20
/*  f0c7540:	460a703c */ 	c.lt.s	$f14,$f10
/*  f0c7544:	00000000 */ 	nop
/*  f0c7548:	45020028 */ 	bc1fl	.L0f0c75ec
/*  f0c754c:	46141032 */ 	c.eq.s	$f2,$f20
/*  f0c7550:	460a7183 */ 	div.s	$f6,$f14,$f10
/*  f0c7554:	46060202 */ 	mul.s	$f8,$f0,$f6
/*  f0c7558:	e4680184 */ 	swc1	$f8,0x184($v1)
/*  f0c755c:	10000022 */ 	b	.L0f0c75e8
/*  f0c7560:	8d030284 */ 	lw	$v1,0x284($t0)
/*  f0c7564:	4614203c */ 	c.lt.s	$f4,$f20
.L0f0c7568:
/*  f0c7568:	00000000 */ 	nop
/*  f0c756c:	4502001f */ 	bc1fl	.L0f0c75ec
/*  f0c7570:	46141032 */ 	c.eq.s	$f2,$f20
/*  f0c7574:	e4740184 */ 	swc1	$f20,0x184($v1)
/*  f0c7578:	1000001b */ 	b	.L0f0c75e8
/*  f0c757c:	8d030284 */ 	lw	$v1,0x284($t0)
/*  f0c7580:	c4600184 */ 	lwc1	$f0,0x184($v1)
.L0f0c7584:
/*  f0c7584:	c7aa00d4 */ 	lwc1	$f10,0xd4($sp)
/*  f0c7588:	c7a400d4 */ 	lwc1	$f4,0xd4($sp)
/*  f0c758c:	4614003c */ 	c.lt.s	$f0,$f20
/*  f0c7590:	00000000 */ 	nop
/*  f0c7594:	4502000f */ 	bc1fl	.L0f0c75d4
/*  f0c7598:	4604a03c */ 	c.lt.s	$f20,$f4
/*  f0c759c:	4614503e */ 	c.le.s	$f10,$f20
/*  f0c75a0:	00000000 */ 	nop
/*  f0c75a4:	45020011 */ 	bc1fl	.L0f0c75ec
/*  f0c75a8:	46141032 */ 	c.eq.s	$f2,$f20
/*  f0c75ac:	460e503c */ 	c.lt.s	$f10,$f14
/*  f0c75b0:	00000000 */ 	nop
/*  f0c75b4:	4502000d */ 	bc1fl	.L0f0c75ec
/*  f0c75b8:	46141032 */ 	c.eq.s	$f2,$f20
/*  f0c75bc:	460a7183 */ 	div.s	$f6,$f14,$f10
/*  f0c75c0:	46060202 */ 	mul.s	$f8,$f0,$f6
/*  f0c75c4:	e4680184 */ 	swc1	$f8,0x184($v1)
/*  f0c75c8:	10000007 */ 	b	.L0f0c75e8
/*  f0c75cc:	8d030284 */ 	lw	$v1,0x284($t0)
/*  f0c75d0:	4604a03c */ 	c.lt.s	$f20,$f4
.L0f0c75d4:
/*  f0c75d4:	00000000 */ 	nop
/*  f0c75d8:	45020004 */ 	bc1fl	.L0f0c75ec
/*  f0c75dc:	46141032 */ 	c.eq.s	$f2,$f20
/*  f0c75e0:	e4740184 */ 	swc1	$f20,0x184($v1)
/*  f0c75e4:	8d030284 */ 	lw	$v1,0x284($t0)
.L0f0c75e8:
/*  f0c75e8:	46141032 */ 	c.eq.s	$f2,$f20
.L0f0c75ec:
/*  f0c75ec:	00000000 */ 	nop
/*  f0c75f0:	4503001a */ 	bc1tl	.L0f0c765c
/*  f0c75f4:	c7a20048 */ 	lwc1	$f2,0x48($sp)
/*  f0c75f8:	c460016c */ 	lwc1	$f0,0x16c($v1)
/*  f0c75fc:	46020282 */ 	mul.s	$f10,$f0,$f2
/*  f0c7600:	460aa03c */ 	c.lt.s	$f20,$f10
/*  f0c7604:	00000000 */ 	nop
/*  f0c7608:	45020014 */ 	bc1fl	.L0f0c765c
/*  f0c760c:	c7a20048 */ 	lwc1	$f2,0x48($sp)
/*  f0c7610:	46028403 */ 	div.s	$f16,$f16,$f2
/*  f0c7614:	3c013f80 */ 	lui	$at,0x3f80
/*  f0c7618:	4614803e */ 	c.le.s	$f16,$f20
/*  f0c761c:	00000000 */ 	nop
/*  f0c7620:	45020005 */ 	bc1fl	.L0f0c7638
/*  f0c7624:	44813000 */ 	mtc1	$at,$f6
/*  f0c7628:	e474016c */ 	swc1	$f20,0x16c($v1)
/*  f0c762c:	1000000a */ 	b	.L0f0c7658
/*  f0c7630:	8d030284 */ 	lw	$v1,0x284($t0)
/*  f0c7634:	44813000 */ 	mtc1	$at,$f6
.L0f0c7638:
/*  f0c7638:	00000000 */ 	nop
/*  f0c763c:	4606803c */ 	c.lt.s	$f16,$f6
/*  f0c7640:	00000000 */ 	nop
/*  f0c7644:	45020005 */ 	bc1fl	.L0f0c765c
/*  f0c7648:	c7a20048 */ 	lwc1	$f2,0x48($sp)
/*  f0c764c:	46100202 */ 	mul.s	$f8,$f0,$f16
/*  f0c7650:	e468016c */ 	swc1	$f8,0x16c($v1)
/*  f0c7654:	8d030284 */ 	lw	$v1,0x284($t0)
.L0f0c7658:
/*  f0c7658:	c7a20048 */ 	lwc1	$f2,0x48($sp)
.L0f0c765c:
/*  f0c765c:	46141032 */ 	c.eq.s	$f2,$f20
/*  f0c7660:	00000000 */ 	nop
/*  f0c7664:	4503001a */ 	bc1tl	.L0f0c76d0
/*  f0c7668:	8c6200bc */ 	lw	$v0,0xbc($v1)
/*  f0c766c:	c46019a4 */ 	lwc1	$f0,0x19a4($v1)
/*  f0c7670:	46020102 */ 	mul.s	$f4,$f0,$f2
/*  f0c7674:	4604a03c */ 	c.lt.s	$f20,$f4
/*  f0c7678:	00000000 */ 	nop
/*  f0c767c:	45020014 */ 	bc1fl	.L0f0c76d0
/*  f0c7680:	8c6200bc */ 	lw	$v0,0xbc($v1)
/*  f0c7684:	46029483 */ 	div.s	$f18,$f18,$f2
/*  f0c7688:	3c013f80 */ 	lui	$at,0x3f80
/*  f0c768c:	4614903e */ 	c.le.s	$f18,$f20
/*  f0c7690:	00000000 */ 	nop
/*  f0c7694:	45020005 */ 	bc1fl	.L0f0c76ac
/*  f0c7698:	44815000 */ 	mtc1	$at,$f10
/*  f0c769c:	e47419a4 */ 	swc1	$f20,0x19a4($v1)
/*  f0c76a0:	1000000a */ 	b	.L0f0c76cc
/*  f0c76a4:	8d030284 */ 	lw	$v1,0x284($t0)
/*  f0c76a8:	44815000 */ 	mtc1	$at,$f10
.L0f0c76ac:
/*  f0c76ac:	00000000 */ 	nop
/*  f0c76b0:	460a903c */ 	c.lt.s	$f18,$f10
/*  f0c76b4:	00000000 */ 	nop
/*  f0c76b8:	45020005 */ 	bc1fl	.L0f0c76d0
/*  f0c76bc:	8c6200bc */ 	lw	$v0,0xbc($v1)
/*  f0c76c0:	46120182 */ 	mul.s	$f6,$f0,$f18
/*  f0c76c4:	e46619a4 */ 	swc1	$f6,0x19a4($v1)
/*  f0c76c8:	8d030284 */ 	lw	$v1,0x284($t0)
.L0f0c76cc:
/*  f0c76cc:	8c6200bc */ 	lw	$v0,0xbc($v1)
.L0f0c76d0:
/*  f0c76d0:	c7a4008c */ 	lwc1	$f4,0x8c($sp)
/*  f0c76d4:	c7a60088 */ 	lwc1	$f6,0x88($sp)
/*  f0c76d8:	c4480008 */ 	lwc1	$f8,0x8($v0)
/*  f0c76dc:	c44a0010 */ 	lwc1	$f10,0x10($v0)
/*  f0c76e0:	46044001 */ 	sub.s	$f0,$f8,$f4
/*  f0c76e4:	c7a800d4 */ 	lwc1	$f8,0xd4($sp)
/*  f0c76e8:	46065081 */ 	sub.s	$f2,$f10,$f6
/*  f0c76ec:	46084102 */ 	mul.s	$f4,$f8,$f8
/*  f0c76f0:	c7aa00cc */ 	lwc1	$f10,0xcc($sp)
/*  f0c76f4:	460a5182 */ 	mul.s	$f6,$f10,$f10
/*  f0c76f8:	46062380 */ 	add.s	$f14,$f4,$f6
/*  f0c76fc:	46147032 */ 	c.eq.s	$f14,$f20
/*  f0c7700:	46007306 */ 	mov.s	$f12,$f14
/*  f0c7704:	45010006 */ 	bc1t	.L0f0c7720
/*  f0c7708:	00000000 */ 	nop
/*  f0c770c:	46000202 */ 	mul.s	$f8,$f0,$f0
/*  f0c7710:	00000000 */ 	nop
/*  f0c7714:	46021282 */ 	mul.s	$f10,$f2,$f2
/*  f0c7718:	460a4100 */ 	add.s	$f4,$f8,$f10
/*  f0c771c:	460e2303 */ 	div.s	$f12,$f4,$f14
.L0f0c7720:
/*  f0c7720:	0c012974 */ 	jal	sqrtf
/*  f0c7724:	00000000 */ 	nop
/*  f0c7728:	c7a800b4 */ 	lwc1	$f8,0xb4($sp)
/*  f0c772c:	3c08800a */ 	lui	$t0,%hi(g_Vars)
/*  f0c7730:	25089fc0 */ 	addiu	$t0,$t0,%lo(g_Vars)
/*  f0c7734:	46080282 */ 	mul.s	$f10,$f0,$f8
/*  f0c7738:	8d030284 */ 	lw	$v1,0x284($t0)
/*  f0c773c:	c46600a4 */ 	lwc1	$f6,0xa4($v1)
/*  f0c7740:	460a3100 */ 	add.s	$f4,$f6,$f10
/*  f0c7744:	e46400a4 */ 	swc1	$f4,0xa4($v1)
/*  f0c7748:	c7a600b0 */ 	lwc1	$f6,0xb0($sp)
/*  f0c774c:	8d030284 */ 	lw	$v1,0x284($t0)
/*  f0c7750:	46060282 */ 	mul.s	$f10,$f0,$f6
/*  f0c7754:	c46800a8 */ 	lwc1	$f8,0xa8($v1)
/*  f0c7758:	460a4100 */ 	add.s	$f4,$f8,$f10
/*  f0c775c:	e46400a8 */ 	swc1	$f4,0xa8($v1)
.L0f0c7760:
/*  f0c7760:	8d030284 */ 	lw	$v1,0x284($t0)
/*  f0c7764:	3c017f1b */ 	lui	$at,%hi(var7f1ad84c)
/*  f0c7768:	c42ad84c */ 	lwc1	$f10,%lo(var7f1ad84c)($at)
/*  f0c776c:	c4660148 */ 	lwc1	$f6,0x148($v1)
/*  f0c7770:	3c0140a0 */ 	lui	$at,0x40a0
/*  f0c7774:	e7a60044 */ 	swc1	$f6,0x44($sp)
/*  f0c7778:	c468015c */ 	lwc1	$f8,0x15c($v1)
/*  f0c777c:	c46600b8 */ 	lwc1	$f6,0xb8($v1)
/*  f0c7780:	460a4103 */ 	div.s	$f4,$f8,$f10
/*  f0c7784:	44814000 */ 	mtc1	$at,$f8
/*  f0c7788:	00000000 */ 	nop
/*  f0c778c:	46083283 */ 	div.s	$f10,$f6,$f8
/*  f0c7790:	c46600cc */ 	lwc1	$f6,0xcc($v1)
/*  f0c7794:	e7a6003c */ 	swc1	$f6,0x3c($sp)
/*  f0c7798:	460a2080 */ 	add.s	$f2,$f4,$f10
/*  f0c779c:	0fc4505b */ 	jal	bheadGetBreathingValue
/*  f0c77a0:	e7a20040 */ 	swc1	$f2,0x40($sp)
/*  f0c77a4:	3c013f80 */ 	lui	$at,0x3f80
/*  f0c77a8:	44817000 */ 	mtc1	$at,$f14
/*  f0c77ac:	c7a20040 */ 	lwc1	$f2,0x40($sp)
/*  f0c77b0:	3c08800a */ 	lui	$t0,%hi(g_Vars)
/*  f0c77b4:	25089fc0 */ 	addiu	$t0,$t0,%lo(g_Vars)
/*  f0c77b8:	4602703c */ 	c.lt.s	$f14,$f2
/*  f0c77bc:	46000306 */ 	mov.s	$f12,$f0
/*  f0c77c0:	3c01bf80 */ 	lui	$at,0xbf80
/*  f0c77c4:	8fa70044 */ 	lw	$a3,0x44($sp)
/*  f0c77c8:	45020004 */ 	bc1fl	.L0f0c77dc
/*  f0c77cc:	44817000 */ 	mtc1	$at,$f14
/*  f0c77d0:	10000008 */ 	b	.L0f0c77f4
/*  f0c77d4:	46007086 */ 	mov.s	$f2,$f14
/*  f0c77d8:	44817000 */ 	mtc1	$at,$f14
.L0f0c77dc:
/*  f0c77dc:	00000000 */ 	nop
/*  f0c77e0:	460e103c */ 	c.lt.s	$f2,$f14
/*  f0c77e4:	00000000 */ 	nop
/*  f0c77e8:	45020003 */ 	bc1fl	.L0f0c77f8
/*  f0c77ec:	8d0b0284 */ 	lw	$t3,0x284($t0)
/*  f0c77f0:	46007086 */ 	mov.s	$f2,$f14
.L0f0c77f4:
/*  f0c77f4:	8d0b0284 */ 	lw	$t3,0x284($t0)
.L0f0c77f8:
/*  f0c77f8:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0c77fc:	44061000 */ 	mfc1	$a2,$f2
/*  f0c7800:	8d6c03ac */ 	lw	$t4,0x3ac($t3)
/*  f0c7804:	c7ae003c */ 	lwc1	$f14,0x3c($sp)
/*  f0c7808:	15810004 */ 	bne	$t4,$at,.L0f0c781c
/*  f0c780c:	3c017f1b */ 	lui	$at,%hi(var7f1ad850)
/*  f0c7810:	c428d850 */ 	lwc1	$f8,%lo(var7f1ad850)($at)
/*  f0c7814:	46080302 */ 	mul.s	$f12,$f0,$f8
/*  f0c7818:	00000000 */ 	nop
.L0f0c781c:
/*  f0c781c:	0fc27637 */ 	jal	func0f09d8dc
/*  f0c7820:	e7b40010 */ 	swc1	$f20,0x10($sp)
/*  f0c7824:	3c08800a */ 	lui	$t0,%hi(g_Vars)
/*  f0c7828:	25089fc0 */ 	addiu	$t0,$t0,%lo(g_Vars)
/*  f0c782c:	8d0d0284 */ 	lw	$t5,0x284($t0)
/*  f0c7830:	3c017f1b */ 	lui	$at,%hi(var7f1ad854)
/*  f0c7834:	c42ad854 */ 	lwc1	$f10,%lo(var7f1ad854)($at)
/*  f0c7838:	c5a40158 */ 	lwc1	$f4,0x158($t5)
/*  f0c783c:	460a2302 */ 	mul.s	$f12,$f4,$f10
/*  f0c7840:	0fc288a4 */ 	jal	handSetAdjustPos
/*  f0c7844:	00000000 */ 	nop
/*  f0c7848:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*  f0c784c:	d7b40018 */ 	ldc1	$f20,0x18($sp)
/*  f0c7850:	27bd00e8 */ 	addiu	$sp,$sp,0xe8
/*  f0c7854:	03e00008 */ 	jr	$ra
/*  f0c7858:	00000000 */ 	nop
);
#else
GLOBAL_ASM(
glabel bwalk0f0c69b8
.late_rodata
glabel var7f1ad7fc
.word 0xc27e6668
glabel var7f1ad800
.word 0x43b0aaaa
glabel var7f1ad808
.word 0x3c888889
glabel var7f1ad80c
.word 0x404907a9
glabel var7f1ad810
.word 0x3eb33333
glabel var7f1ad814
.word 0x3eb33333
glabel var7f1ad818
.word 0x3dcccccd
glabel var7f1ad81c
.word 0x3dcccccd
glabel var7f1ad820
.word 0x3eb33333
glabel var7f1ad824
.word 0x3f4ccccd
glabel var7f1ad828
.word 0x3f4ccccd
glabel var7f1ad82c
.word 0x4528c000
glabel var7f1ad83c
.word 0x3e99999a
glabel var7f1ad840
.word 0x3f8ccccd
glabel var7f1ad844
.word 0x3e99999a
glabel var7f1ad848
.word 0x3e99999a
glabel var7f1ad84c
.word 0x3f333333
glabel var7f1ad850
.word 0x3f99999a
glabel var7f1ad854
.word 0x3c8ef461
.text
/*  f0c431c:	27bdff18 */ 	addiu	$sp,$sp,-232
/*  f0c4320:	3c0f8007 */ 	lui	$t7,0x8007
/*  f0c4324:	afbf0024 */ 	sw	$ra,0x24($sp)
/*  f0c4328:	f7b40018 */ 	sdc1	$f20,0x18($sp)
/*  f0c432c:	25ef3528 */ 	addiu	$t7,$t7,0x3528
/*  f0c4330:	8de10000 */ 	lw	$at,0x0($t7)
/*  f0c4334:	27ae00cc */ 	addiu	$t6,$sp,0xcc
/*  f0c4338:	8de90004 */ 	lw	$t1,0x4($t7)
/*  f0c433c:	adc10000 */ 	sw	$at,0x0($t6)
/*  f0c4340:	8de10008 */ 	lw	$at,0x8($t7)
/*  f0c4344:	3c08800a */ 	lui	$t0,0x800a
/*  f0c4348:	2508e6c0 */ 	addiu	$t0,$t0,-6464
/*  f0c434c:	adc90004 */ 	sw	$t1,0x4($t6)
/*  f0c4350:	adc10008 */ 	sw	$at,0x8($t6)
/*  f0c4354:	8d0a0284 */ 	lw	$t2,0x284($t0)
/*  f0c4358:	3c01431f */ 	lui	$at,0x431f
/*  f0c435c:	44813000 */ 	mtc1	$at,$f6
/*  f0c4360:	c54419c4 */ 	lwc1	$f4,0x19c4($t2)
/*  f0c4364:	46062201 */ 	sub.s	$f8,$f4,$f6
/*  f0c4368:	0fc43329 */ 	jal	invHasBriefcase
/*  f0c436c:	e7a800c0 */ 	swc1	$f8,0xc0($sp)
/*  f0c4370:	3c08800a */ 	lui	$t0,0x800a
/*  f0c4374:	1040000a */ 	beqz	$v0,.NB0f0c43a0
/*  f0c4378:	2508e6c0 */ 	addiu	$t0,$t0,-6464
/*  f0c437c:	3c02800b */ 	lui	$v0,0x800b
/*  f0c4380:	90421448 */ 	lbu	$v0,0x1448($v0)
/*  f0c4384:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0c4388:	10410002 */ 	beq	$v0,$at,.NB0f0c4394
/*  f0c438c:	24010005 */ 	addiu	$at,$zero,0x5
/*  f0c4390:	14410003 */ 	bne	$v0,$at,.NB0f0c43a0
.NB0f0c4394:
/*  f0c4394:	3c017f1a */ 	lui	$at,0x7f1a
/*  f0c4398:	c4207b4c */ 	lwc1	$f0,0x7b4c($at)
/*  f0c439c:	e7a000c0 */ 	swc1	$f0,0xc0($sp)
.NB0f0c43a0:
/*  f0c43a0:	3c013f80 */ 	lui	$at,0x3f80
/*  f0c43a4:	44811000 */ 	mtc1	$at,$f2
/*  f0c43a8:	3c017f1a */ 	lui	$at,0x7f1a
/*  f0c43ac:	c7a000c0 */ 	lwc1	$f0,0xc0($sp)
/*  f0c43b0:	c42a7b50 */ 	lwc1	$f10,0x7b50($at)
/*  f0c43b4:	8d0b0318 */ 	lw	$t3,0x318($t0)
/*  f0c43b8:	3c0c800b */ 	lui	$t4,0x800b
/*  f0c43bc:	460a0103 */ 	div.s	$f4,$f0,$f10
/*  f0c43c0:	1160000a */ 	beqz	$t3,.NB0f0c43ec
/*  f0c43c4:	46022000 */ 	add.s	$f0,$f4,$f2
/*  f0c43c8:	8d8c1444 */ 	lw	$t4,0x1444($t4)
/*  f0c43cc:	3c013fa0 */ 	lui	$at,0x3fa0
/*  f0c43d0:	318d0100 */ 	andi	$t5,$t4,0x100
/*  f0c43d4:	51a00006 */ 	beqzl	$t5,.NB0f0c43f0
/*  f0c43d8:	8d030284 */ 	lw	$v1,0x284($t0)
/*  f0c43dc:	44813000 */ 	mtc1	$at,$f6
/*  f0c43e0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c43e4:	46060002 */ 	mul.s	$f0,$f0,$f6
/*  f0c43e8:	00000000 */ 	sll	$zero,$zero,0x0
.NB0f0c43ec:
/*  f0c43ec:	8d030284 */ 	lw	$v1,0x284($t0)
.NB0f0c43f0:
/*  f0c43f0:	8c791af8 */ 	lw	$t9,0x1af8($v1)
/*  f0c43f4:	1320003d */ 	beqz	$t9,.NB0f0c44ec
/*  f0c43f8:	3c017f1a */ 	lui	$at,0x7f1a
/*  f0c43fc:	c42a7b54 */ 	lwc1	$f10,0x7b54($at)
/*  f0c4400:	c508004c */ 	lwc1	$f8,0x4c($t0)
/*  f0c4404:	c4661b48 */ 	lwc1	$f6,0x1b48($v1)
/*  f0c4408:	3c017f1a */ 	lui	$at,0x7f1a
/*  f0c440c:	460a4102 */ 	mul.s	$f4,$f8,$f10
/*  f0c4410:	46043200 */ 	add.s	$f8,$f6,$f4
/*  f0c4414:	e4681b48 */ 	swc1	$f8,0x1b48($v1)
/*  f0c4418:	8d030284 */ 	lw	$v1,0x284($t0)
/*  f0c441c:	c4601b48 */ 	lwc1	$f0,0x1b48($v1)
/*  f0c4420:	4600103e */ 	c.le.s	$f2,$f0
/*  f0c4424:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c4428:	45000006 */ 	bc1f	.NB0f0c4444
/*  f0c442c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c4430:	e4621b48 */ 	swc1	$f2,0x1b48($v1)
/*  f0c4434:	8d180284 */ 	lw	$t8,0x284($t0)
/*  f0c4438:	af001af8 */ 	sw	$zero,0x1af8($t8)
/*  f0c443c:	8d0e0284 */ 	lw	$t6,0x284($t0)
/*  f0c4440:	c5c01b48 */ 	lwc1	$f0,0x1b48($t6)
.NB0f0c4444:
/*  f0c4444:	c42a7b58 */ 	lwc1	$f10,0x7b58($at)
/*  f0c4448:	460a0302 */ 	mul.s	$f12,$f0,$f10
/*  f0c444c:	0c006d52 */ 	jal	cosf
/*  f0c4450:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c4454:	3c013f80 */ 	lui	$at,0x3f80
/*  f0c4458:	44811000 */ 	mtc1	$at,$f2
/*  f0c445c:	3c013f00 */ 	lui	$at,0x3f00
/*  f0c4460:	44812000 */ 	mtc1	$at,$f4
/*  f0c4464:	46020180 */ 	add.s	$f6,$f0,$f2
/*  f0c4468:	3c08800a */ 	lui	$t0,0x800a
/*  f0c446c:	2508e6c0 */ 	addiu	$t0,$t0,-6464
/*  f0c4470:	8d0f0284 */ 	lw	$t7,0x284($t0)
/*  f0c4474:	46043202 */ 	mul.s	$f8,$f6,$f4
/*  f0c4478:	4480a000 */ 	mtc1	$zero,$f20
/*  f0c447c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c4480:	4406a000 */ 	mfc1	$a2,$f20
/*  f0c4484:	4600a306 */ 	mov.s	$f12,$f20
/*  f0c4488:	4600a386 */ 	mov.s	$f14,$f20
/*  f0c448c:	46081281 */ 	sub.s	$f10,$f2,$f8
/*  f0c4490:	e5ea1b4c */ 	swc1	$f10,0x1b4c($t7)
/*  f0c4494:	8d030284 */ 	lw	$v1,0x284($t0)
/*  f0c4498:	c4661b4c */ 	lwc1	$f6,0x1b4c($v1)
/*  f0c449c:	24671b08 */ 	addiu	$a3,$v1,0x1b08
/*  f0c44a0:	46061101 */ 	sub.s	$f4,$f2,$f6
/*  f0c44a4:	0fc326f9 */ 	jal	bmoveUpdateHead
/*  f0c44a8:	e7a40010 */ 	swc1	$f4,0x10($sp)
/*  f0c44ac:	3c08800a */ 	lui	$t0,0x800a
/*  f0c44b0:	2508e6c0 */ 	addiu	$t0,$t0,-6464
/*  f0c44b4:	8d090284 */ 	lw	$t1,0x284($t0)
/*  f0c44b8:	27a400cc */ 	addiu	$a0,$sp,0xcc
/*  f0c44bc:	0fc324de */ 	jal	bmoveUpdateMoveInitSpeed
/*  f0c44c0:	e53400cc */ 	swc1	$f20,0xcc($t1)
/*  f0c44c4:	4405a000 */ 	mfc1	$a1,$f20
/*  f0c44c8:	4407a000 */ 	mfc1	$a3,$f20
/*  f0c44cc:	240a003f */ 	addiu	$t2,$zero,0x3f
/*  f0c44d0:	afaa0010 */ 	sw	$t2,0x10($sp)
/*  f0c44d4:	27a400cc */ 	addiu	$a0,$sp,0xcc
/*  f0c44d8:	0fc30794 */ 	jal	bwalkCalculateNewPositionWithPush
/*  f0c44dc:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f0c44e0:	3c08800a */ 	lui	$t0,0x800a
/*  f0c44e4:	100002d1 */ 	beqz	$zero,.NB0f0c502c
/*  f0c44e8:	2508e6c0 */ 	addiu	$t0,$t0,-6464
.NB0f0c44ec:
/*  f0c44ec:	0fc30e53 */ 	jal	bwalkApplyCrouchSpeed
/*  f0c44f0:	e7a000c0 */ 	swc1	$f0,0xc0($sp)
/*  f0c44f4:	0fc30eb9 */ 	jal	bwalkUpdateCrouchOffset
/*  f0c44f8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c44fc:	3c08800a */ 	lui	$t0,0x800a
/*  f0c4500:	2508e6c0 */ 	addiu	$t0,$t0,-6464
/*  f0c4504:	8d030284 */ 	lw	$v1,0x284($t0)
/*  f0c4508:	27a400c8 */ 	addiu	$a0,$sp,0xc8
/*  f0c450c:	27a500c4 */ 	addiu	$a1,$sp,0xc4
/*  f0c4510:	c468014c */ 	lwc1	$f8,0x14c($v1)
/*  f0c4514:	8c670150 */ 	lw	$a3,0x150($v1)
/*  f0c4518:	2466017c */ 	addiu	$a2,$v1,0x17c
/*  f0c451c:	0fc324ae */ 	jal	bmove0f0cba88
/*  f0c4520:	e7a80010 */ 	swc1	$f8,0x10($sp)
/*  f0c4524:	3c08800a */ 	lui	$t0,0x800a
/*  f0c4528:	2508e6c0 */ 	addiu	$t0,$t0,-6464
/*  f0c452c:	8d030284 */ 	lw	$v1,0x284($t0)
/*  f0c4530:	3c01c234 */ 	lui	$at,0xc234
/*  f0c4534:	c7a800c0 */ 	lwc1	$f8,0xc0($sp)
/*  f0c4538:	c46c00a0 */ 	lwc1	$f12,0xa0($v1)
/*  f0c453c:	c46a0374 */ 	lwc1	$f10,0x374($v1)
/*  f0c4540:	c464036c */ 	lwc1	$f4,0x36c($v1)
/*  f0c4544:	46006187 */ 	neg.s	$f6,$f12
/*  f0c4548:	c47000b4 */ 	lwc1	$f16,0xb4($v1)
/*  f0c454c:	46065002 */ 	mul.s	$f0,$f10,$f6
/*  f0c4550:	44815000 */ 	mtc1	$at,$f10
/*  f0c4554:	4480a000 */ 	mtc1	$zero,$f20
/*  f0c4558:	460c2382 */ 	mul.s	$f14,$f4,$f12
/*  f0c455c:	460a803c */ 	c.lt.s	$f16,$f10
/*  f0c4560:	4600a086 */ 	mov.s	$f2,$f20
/*  f0c4564:	46080002 */ 	mul.s	$f0,$f0,$f8
/*  f0c4568:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c456c:	46087382 */ 	mul.s	$f14,$f14,$f8
/*  f0c4570:	4500000a */ 	bc1f	.NB0f0c459c
/*  f0c4574:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c4578:	3c017f1a */ 	lui	$at,0x7f1a
/*  f0c457c:	c4267b5c */ 	lwc1	$f6,0x7b5c($at)
/*  f0c4580:	3c017f1a */ 	lui	$at,0x7f1a
/*  f0c4584:	c4247b60 */ 	lwc1	$f4,0x7b60($at)
/*  f0c4588:	46060002 */ 	mul.s	$f0,$f0,$f6
/*  f0c458c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c4590:	46047382 */ 	mul.s	$f14,$f14,$f4
/*  f0c4594:	1000000b */ 	beqz	$zero,.NB0f0c45c4
/*  f0c4598:	00000000 */ 	sll	$zero,$zero,0x0
.NB0f0c459c:
/*  f0c459c:	4614803c */ 	c.lt.s	$f16,$f20
/*  f0c45a0:	3c013f00 */ 	lui	$at,0x3f00
/*  f0c45a4:	45020008 */ 	bc1fl	.NB0f0c45c8
/*  f0c45a8:	c46600a4 */ 	lwc1	$f6,0xa4($v1)
/*  f0c45ac:	44814000 */ 	mtc1	$at,$f8
/*  f0c45b0:	44815000 */ 	mtc1	$at,$f10
/*  f0c45b4:	46080002 */ 	mul.s	$f0,$f0,$f8
/*  f0c45b8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c45bc:	460a7382 */ 	mul.s	$f14,$f14,$f10
/*  f0c45c0:	00000000 */ 	sll	$zero,$zero,0x0
.NB0f0c45c4:
/*  f0c45c4:	c46600a4 */ 	lwc1	$f6,0xa4($v1)
.NB0f0c45c8:
/*  f0c45c8:	c46400a8 */ 	lwc1	$f4,0xa8($v1)
/*  f0c45cc:	e7a200a8 */ 	swc1	$f2,0xa8($sp)
/*  f0c45d0:	46060401 */ 	sub.s	$f16,$f0,$f6
/*  f0c45d4:	46047481 */ 	sub.s	$f18,$f14,$f4
/*  f0c45d8:	46108202 */ 	mul.s	$f8,$f16,$f16
/*  f0c45dc:	e7b000b4 */ 	swc1	$f16,0xb4($sp)
/*  f0c45e0:	46129282 */ 	mul.s	$f10,$f18,$f18
/*  f0c45e4:	e7b200b0 */ 	swc1	$f18,0xb0($sp)
/*  f0c45e8:	0c012e84 */ 	jal	sqrtf
/*  f0c45ec:	460a4300 */ 	add.s	$f12,$f8,$f10
/*  f0c45f0:	3c08800a */ 	lui	$t0,0x800a
/*  f0c45f4:	2508e6c0 */ 	addiu	$t0,$t0,-6464
/*  f0c45f8:	3c014080 */ 	lui	$at,0x4080
/*  f0c45fc:	44817000 */ 	mtc1	$at,$f14
/*  f0c4600:	c510004c */ 	lwc1	$f16,0x4c($t0)
/*  f0c4604:	c7a200a8 */ 	lwc1	$f2,0xa8($sp)
/*  f0c4608:	00001025 */ 	or	$v0,$zero,$zero
/*  f0c460c:	4610703c */ 	c.lt.s	$f14,$f16
/*  f0c4610:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c4614:	45020005 */ 	bc1fl	.NB0f0c462c
/*  f0c4618:	46008306 */ 	mov.s	$f12,$f16
/*  f0c461c:	46007306 */ 	mov.s	$f12,$f14
/*  f0c4620:	10000003 */ 	beqz	$zero,.NB0f0c4630
/*  f0c4624:	24030004 */ 	addiu	$v1,$zero,0x4
/*  f0c4628:	46008306 */ 	mov.s	$f12,$f16
.NB0f0c462c:
/*  f0c462c:	8d030038 */ 	lw	$v1,0x38($t0)
.NB0f0c4630:
/*  f0c4630:	18600009 */ 	blez	$v1,.NB0f0c4658
/*  f0c4634:	e7b00030 */ 	swc1	$f16,0x30($sp)
/*  f0c4638:	3c017f1a */ 	lui	$at,0x7f1a
/*  f0c463c:	c4327b64 */ 	lwc1	$f18,0x7b64($at)
.NB0f0c4640:
/*  f0c4640:	46020181 */ 	sub.s	$f6,$f0,$f2
/*  f0c4644:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f0c4648:	46123102 */ 	mul.s	$f4,$f6,$f18
/*  f0c464c:	1443fffc */ 	bne	$v0,$v1,.NB0f0c4640
/*  f0c4650:	46041080 */ 	add.s	$f2,$f2,$f4
/*  f0c4654:	e7b00030 */ 	swc1	$f16,0x30($sp)
.NB0f0c4658:
/*  f0c4658:	3c017f1a */ 	lui	$at,0x7f1a
/*  f0c465c:	c4327b68 */ 	lwc1	$f18,0x7b68($at)
/*  f0c4660:	3c014070 */ 	lui	$at,0x4070
/*  f0c4664:	44814000 */ 	mtc1	$at,$f8
/*  f0c4668:	8d030284 */ 	lw	$v1,0x284($t0)
/*  f0c466c:	3c01c234 */ 	lui	$at,0xc234
/*  f0c4670:	44813000 */ 	mtc1	$at,$f6
/*  f0c4674:	c47000b4 */ 	lwc1	$f16,0xb4($v1)
/*  f0c4678:	460c4282 */ 	mul.s	$f10,$f8,$f12
/*  f0c467c:	4606803c */ 	c.lt.s	$f16,$f6
/*  f0c4680:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c4684:	45000006 */ 	bc1f	.NB0f0c46a0
/*  f0c4688:	460a1080 */ 	add.s	$f2,$f2,$f10
/*  f0c468c:	3c017f1a */ 	lui	$at,0x7f1a
/*  f0c4690:	c4247b6c */ 	lwc1	$f4,0x7b6c($at)
/*  f0c4694:	46041082 */ 	mul.s	$f2,$f2,$f4
/*  f0c4698:	1000000a */ 	beqz	$zero,.NB0f0c46c4
/*  f0c469c:	4600103c */ 	c.lt.s	$f2,$f0
.NB0f0c46a0:
/*  f0c46a0:	4614803c */ 	c.lt.s	$f16,$f20
/*  f0c46a4:	3c013f00 */ 	lui	$at,0x3f00
/*  f0c46a8:	45020006 */ 	bc1fl	.NB0f0c46c4
/*  f0c46ac:	4600103c */ 	c.lt.s	$f2,$f0
/*  f0c46b0:	44814000 */ 	mtc1	$at,$f8
/*  f0c46b4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c46b8:	46081082 */ 	mul.s	$f2,$f2,$f8
/*  f0c46bc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c46c0:	4600103c */ 	c.lt.s	$f2,$f0
.NB0f0c46c4:
/*  f0c46c4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c46c8:	4502000a */ 	bc1fl	.NB0f0c46f4
/*  f0c46cc:	c46a0168 */ 	lwc1	$f10,0x168($v1)
/*  f0c46d0:	46001083 */ 	div.s	$f2,$f2,$f0
/*  f0c46d4:	c7aa00b4 */ 	lwc1	$f10,0xb4($sp)
/*  f0c46d8:	c7a400b0 */ 	lwc1	$f4,0xb0($sp)
/*  f0c46dc:	46025182 */ 	mul.s	$f6,$f10,$f2
/*  f0c46e0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c46e4:	46022202 */ 	mul.s	$f8,$f4,$f2
/*  f0c46e8:	e7a600b4 */ 	swc1	$f6,0xb4($sp)
/*  f0c46ec:	e7a800b0 */ 	swc1	$f8,0xb0($sp)
/*  f0c46f0:	c46a0168 */ 	lwc1	$f10,0x168($v1)
.NB0f0c46f4:
/*  f0c46f4:	c7a600c4 */ 	lwc1	$f6,0xc4($sp)
/*  f0c46f8:	3c017f1a */ 	lui	$at,0x7f1a
/*  f0c46fc:	c42c7b70 */ 	lwc1	$f12,0x7b70($at)
/*  f0c4700:	46065100 */ 	add.s	$f4,$f10,$f6
/*  f0c4704:	c4660148 */ 	lwc1	$f6,0x148($v1)
/*  f0c4708:	c7aa00c8 */ 	lwc1	$f10,0xc8($sp)
/*  f0c470c:	c4680170 */ 	lwc1	$f8,0x170($v1)
/*  f0c4710:	460c2082 */ 	mul.s	$f2,$f4,$f12
/*  f0c4714:	c7b00030 */ 	lwc1	$f16,0x30($sp)
/*  f0c4718:	460a4380 */ 	add.s	$f14,$f8,$f10
/*  f0c471c:	460c3102 */ 	mul.s	$f4,$f6,$f12
/*  f0c4720:	4614103c */ 	c.lt.s	$f2,$f20
/*  f0c4724:	e7a4007c */ 	swc1	$f4,0x7c($sp)
/*  f0c4728:	c7a8007c */ 	lwc1	$f8,0x7c($sp)
/*  f0c472c:	45020003 */ 	bc1fl	.NB0f0c473c
/*  f0c4730:	4614703c */ 	c.lt.s	$f14,$f20
/*  f0c4734:	46001087 */ 	neg.s	$f2,$f2
/*  f0c4738:	4614703c */ 	c.lt.s	$f14,$f20
.NB0f0c473c:
/*  f0c473c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c4740:	45020003 */ 	bc1fl	.NB0f0c4750
/*  f0c4744:	4614403c */ 	c.lt.s	$f8,$f20
/*  f0c4748:	46007387 */ 	neg.s	$f14,$f14
/*  f0c474c:	4614403c */ 	c.lt.s	$f8,$f20
.NB0f0c4750:
/*  f0c4750:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c4754:	45020004 */ 	bc1fl	.NB0f0c4768
/*  f0c4758:	4602703c */ 	c.lt.s	$f14,$f2
/*  f0c475c:	46004287 */ 	neg.s	$f10,$f8
/*  f0c4760:	e7aa007c */ 	swc1	$f10,0x7c($sp)
/*  f0c4764:	4602703c */ 	c.lt.s	$f14,$f2
.NB0f0c4768:
/*  f0c4768:	46007306 */ 	mov.s	$f12,$f14
/*  f0c476c:	c7a6007c */ 	lwc1	$f6,0x7c($sp)
/*  f0c4770:	45020003 */ 	bc1fl	.NB0f0c4780
/*  f0c4774:	4606603c */ 	c.lt.s	$f12,$f6
/*  f0c4778:	46001306 */ 	mov.s	$f12,$f2
/*  f0c477c:	4606603c */ 	c.lt.s	$f12,$f6
.NB0f0c4780:
/*  f0c4780:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c4784:	45020003 */ 	bc1fl	.NB0f0c4794
/*  f0c4788:	4600903e */ 	c.le.s	$f18,$f0
/*  f0c478c:	46003306 */ 	mov.s	$f12,$f6
/*  f0c4790:	4600903e */ 	c.le.s	$f18,$f0
.NB0f0c4794:
/*  f0c4794:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c4798:	45000007 */ 	bc1f	.NB0f0c47b8
/*  f0c479c:	3c017f1a */ 	lui	$at,0x7f1a
/*  f0c47a0:	c4207b74 */ 	lwc1	$f0,0x7b74($at)
/*  f0c47a4:	4600603c */ 	c.lt.s	$f12,$f0
/*  f0c47a8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c47ac:	45020003 */ 	bc1fl	.NB0f0c47bc
/*  f0c47b0:	3c013f40 */ 	lui	$at,0x3f40
/*  f0c47b4:	46000306 */ 	mov.s	$f12,$f0
.NB0f0c47b8:
/*  f0c47b8:	3c013f40 */ 	lui	$at,0x3f40
.NB0f0c47bc:
/*  f0c47bc:	44810000 */ 	mtc1	$at,$f0
/*  f0c47c0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c47c4:	460c003e */ 	c.le.s	$f0,$f12
/*  f0c47c8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c47cc:	4502000b */ 	bc1fl	.NB0f0c47fc
/*  f0c47d0:	460c0281 */ 	sub.s	$f10,$f0,$f12
/*  f0c47d4:	46006101 */ 	sub.s	$f4,$f12,$f0
/*  f0c47d8:	3c014461 */ 	lui	$at,0x4461
/*  f0c47dc:	44815000 */ 	mtc1	$at,$f10
/*  f0c47e0:	46102202 */ 	mul.s	$f8,$f4,$f16
/*  f0c47e4:	c4640198 */ 	lwc1	$f4,0x198($v1)
/*  f0c47e8:	460a4183 */ 	div.s	$f6,$f8,$f10
/*  f0c47ec:	46062200 */ 	add.s	$f8,$f4,$f6
/*  f0c47f0:	10000009 */ 	beqz	$zero,.NB0f0c4818
/*  f0c47f4:	e4680198 */ 	swc1	$f8,0x198($v1)
/*  f0c47f8:	460c0281 */ 	sub.s	$f10,$f0,$f12
.NB0f0c47fc:
/*  f0c47fc:	3c017f1a */ 	lui	$at,0x7f1a
/*  f0c4800:	c4267b78 */ 	lwc1	$f6,0x7b78($at)
/*  f0c4804:	46105102 */ 	mul.s	$f4,$f10,$f16
/*  f0c4808:	c46a0198 */ 	lwc1	$f10,0x198($v1)
/*  f0c480c:	46062203 */ 	div.s	$f8,$f4,$f6
/*  f0c4810:	46085101 */ 	sub.s	$f4,$f10,$f8
/*  f0c4814:	e4640198 */ 	swc1	$f4,0x198($v1)
.NB0f0c4818:
/*  f0c4818:	8d030284 */ 	lw	$v1,0x284($t0)
/*  f0c481c:	c4600198 */ 	lwc1	$f0,0x198($v1)
/*  f0c4820:	4614003c */ 	c.lt.s	$f0,$f20
/*  f0c4824:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c4828:	45020005 */ 	bc1fl	.NB0f0c4840
/*  f0c482c:	3c013f80 */ 	lui	$at,0x3f80
/*  f0c4830:	e4740198 */ 	swc1	$f20,0x198($v1)
/*  f0c4834:	1000000c */ 	beqz	$zero,.NB0f0c4868
/*  f0c4838:	8d030284 */ 	lw	$v1,0x284($t0)
/*  f0c483c:	3c013f80 */ 	lui	$at,0x3f80
.NB0f0c4840:
/*  f0c4840:	44813000 */ 	mtc1	$at,$f6
/*  f0c4844:	3c013f80 */ 	lui	$at,0x3f80
/*  f0c4848:	4600303c */ 	c.lt.s	$f6,$f0
/*  f0c484c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c4850:	45000005 */ 	bc1f	.NB0f0c4868
/*  f0c4854:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c4858:	44815000 */ 	mtc1	$at,$f10
/*  f0c485c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c4860:	e46a0198 */ 	swc1	$f10,0x198($v1)
/*  f0c4864:	8d030284 */ 	lw	$v1,0x284($t0)
.NB0f0c4868:
/*  f0c4868:	3c018007 */ 	lui	$at,0x8007
/*  f0c486c:	c4287fc4 */ 	lwc1	$f8,0x7fc4($at)
/*  f0c4870:	3c013f00 */ 	lui	$at,0x3f00
/*  f0c4874:	44812000 */ 	mtc1	$at,$f4
/*  f0c4878:	c50a004c */ 	lwc1	$f10,0x4c($t0)
/*  f0c487c:	46044182 */ 	mul.s	$f6,$f8,$f4
/*  f0c4880:	c7a400c0 */ 	lwc1	$f4,0xc0($sp)
/*  f0c4884:	c4680168 */ 	lwc1	$f8,0x168($v1)
/*  f0c4888:	460a3002 */ 	mul.s	$f0,$f6,$f10
/*  f0c488c:	c7aa00c4 */ 	lwc1	$f10,0xc4($sp)
/*  f0c4890:	46044182 */ 	mul.s	$f6,$f8,$f4
/*  f0c4894:	460a3200 */ 	add.s	$f8,$f6,$f10
/*  f0c4898:	c4660170 */ 	lwc1	$f6,0x170($v1)
/*  f0c489c:	e7ac0078 */ 	swc1	$f12,0x78($sp)
/*  f0c48a0:	46004082 */ 	mul.s	$f2,$f8,$f0
/*  f0c48a4:	c7a800c8 */ 	lwc1	$f8,0xc8($sp)
/*  f0c48a8:	46043282 */ 	mul.s	$f10,$f6,$f4
/*  f0c48ac:	44061000 */ 	mfc1	$a2,$f2
/*  f0c48b0:	0fc327a0 */ 	jal	bmove0f0cc654
/*  f0c48b4:	46085380 */ 	add.s	$f14,$f10,$f8
/*  f0c48b8:	3c08800a */ 	lui	$t0,0x800a
/*  f0c48bc:	2508e6c0 */ 	addiu	$t0,$t0,-6464
/*  f0c48c0:	c7ac0078 */ 	lwc1	$f12,0x78($sp)
/*  f0c48c4:	8d0b0284 */ 	lw	$t3,0x284($t0)
/*  f0c48c8:	27a400cc */ 	addiu	$a0,$sp,0xcc
/*  f0c48cc:	e56c00cc */ 	swc1	$f12,0xcc($t3)
/*  f0c48d0:	8d030284 */ 	lw	$v1,0x284($t0)
/*  f0c48d4:	c510004c */ 	lwc1	$f16,0x4c($t0)
/*  f0c48d8:	c46203c8 */ 	lwc1	$f2,0x3c8($v1)
/*  f0c48dc:	c466036c */ 	lwc1	$f6,0x36c($v1)
/*  f0c48e0:	c46003c0 */ 	lwc1	$f0,0x3c0($v1)
/*  f0c48e4:	c46a0374 */ 	lwc1	$f10,0x374($v1)
/*  f0c48e8:	46061102 */ 	mul.s	$f4,$f2,$f6
/*  f0c48ec:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c48f0:	460a0202 */ 	mul.s	$f8,$f0,$f10
/*  f0c48f4:	46082181 */ 	sub.s	$f6,$f4,$f8
/*  f0c48f8:	c7a400cc */ 	lwc1	$f4,0xcc($sp)
/*  f0c48fc:	46103282 */ 	mul.s	$f10,$f6,$f16
/*  f0c4900:	460a2200 */ 	add.s	$f8,$f4,$f10
/*  f0c4904:	e7a800cc */ 	swc1	$f8,0xcc($sp)
/*  f0c4908:	c4660374 */ 	lwc1	$f6,0x374($v1)
/*  f0c490c:	c46a036c */ 	lwc1	$f10,0x36c($v1)
/*  f0c4910:	46061102 */ 	mul.s	$f4,$f2,$f6
/*  f0c4914:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c4918:	460a0182 */ 	mul.s	$f6,$f0,$f10
/*  f0c491c:	46062280 */ 	add.s	$f10,$f4,$f6
/*  f0c4920:	c7a600d4 */ 	lwc1	$f6,0xd4($sp)
/*  f0c4924:	46105102 */ 	mul.s	$f4,$f10,$f16
/*  f0c4928:	46043280 */ 	add.s	$f10,$f6,$f4
/*  f0c492c:	c7a600b4 */ 	lwc1	$f6,0xb4($sp)
/*  f0c4930:	46064100 */ 	add.s	$f4,$f8,$f6
/*  f0c4934:	c7a800b0 */ 	lwc1	$f8,0xb0($sp)
/*  f0c4938:	e7aa00d4 */ 	swc1	$f10,0xd4($sp)
/*  f0c493c:	46085180 */ 	add.s	$f6,$f10,$f8
/*  f0c4940:	e7a400cc */ 	swc1	$f4,0xcc($sp)
/*  f0c4944:	0fc324de */ 	jal	bmoveUpdateMoveInitSpeed
/*  f0c4948:	e7a600d4 */ 	swc1	$f6,0xd4($sp)
/*  f0c494c:	0fc46661 */ 	jal	debug0f119984nb
/*  f0c4950:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c4954:	3c08800a */ 	lui	$t0,0x800a
/*  f0c4958:	1040001f */ 	beqz	$v0,.NB0f0c49d8
/*  f0c495c:	2508e6c0 */ 	addiu	$t0,$t0,-6464
/*  f0c4960:	8d030284 */ 	lw	$v1,0x284($t0)
/*  f0c4964:	c510004c */ 	lwc1	$f16,0x4c($t0)
/*  f0c4968:	3c014120 */ 	lui	$at,0x4120
/*  f0c496c:	c464036c */ 	lwc1	$f4,0x36c($v1)
/*  f0c4970:	c46a0170 */ 	lwc1	$f10,0x170($v1)
/*  f0c4974:	c4660374 */ 	lwc1	$f6,0x374($v1)
/*  f0c4978:	44810000 */ 	mtc1	$at,$f0
/*  f0c497c:	460a2202 */ 	mul.s	$f8,$f4,$f10
/*  f0c4980:	c4640168 */ 	lwc1	$f4,0x168($v1)
/*  f0c4984:	46043282 */ 	mul.s	$f10,$f6,$f4
/*  f0c4988:	460a4181 */ 	sub.s	$f6,$f8,$f10
/*  f0c498c:	c7aa00cc */ 	lwc1	$f10,0xcc($sp)
/*  f0c4990:	46103102 */ 	mul.s	$f4,$f6,$f16
/*  f0c4994:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c4998:	46002202 */ 	mul.s	$f8,$f4,$f0
/*  f0c499c:	46085180 */ 	add.s	$f6,$f10,$f8
/*  f0c49a0:	e7a600cc */ 	swc1	$f6,0xcc($sp)
/*  f0c49a4:	c46a0170 */ 	lwc1	$f10,0x170($v1)
/*  f0c49a8:	c4640374 */ 	lwc1	$f4,0x374($v1)
/*  f0c49ac:	c466036c */ 	lwc1	$f6,0x36c($v1)
/*  f0c49b0:	460a2202 */ 	mul.s	$f8,$f4,$f10
/*  f0c49b4:	c4640168 */ 	lwc1	$f4,0x168($v1)
/*  f0c49b8:	46043282 */ 	mul.s	$f10,$f6,$f4
/*  f0c49bc:	460a4180 */ 	add.s	$f6,$f8,$f10
/*  f0c49c0:	c7aa00d4 */ 	lwc1	$f10,0xd4($sp)
/*  f0c49c4:	46103102 */ 	mul.s	$f4,$f6,$f16
/*  f0c49c8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c49cc:	46002202 */ 	mul.s	$f8,$f4,$f0
/*  f0c49d0:	46085180 */ 	add.s	$f6,$f10,$f8
/*  f0c49d4:	e7a600d4 */ 	swc1	$f6,0xd4($sp)
.NB0f0c49d8:
/*  f0c49d8:	8d030284 */ 	lw	$v1,0x284($t0)
/*  f0c49dc:	c4601b6c */ 	lwc1	$f0,0x1b6c($v1)
/*  f0c49e0:	4600a032 */ 	c.eq.s	$f20,$f0
/*  f0c49e4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c49e8:	45020007 */ 	bc1fl	.NB0f0c4a08
/*  f0c49ec:	c510004c */ 	lwc1	$f16,0x4c($t0)
/*  f0c49f0:	c4641b74 */ 	lwc1	$f4,0x1b74($v1)
/*  f0c49f4:	4604a032 */ 	c.eq.s	$f20,$f4
/*  f0c49f8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c49fc:	4503000c */ 	bc1tl	.NB0f0c4a30
/*  f0c4a00:	8c6c02ac */ 	lw	$t4,0x2ac($v1)
/*  f0c4a04:	c510004c */ 	lwc1	$f16,0x4c($t0)
.NB0f0c4a08:
/*  f0c4a08:	c7aa00cc */ 	lwc1	$f10,0xcc($sp)
/*  f0c4a0c:	c7a400d4 */ 	lwc1	$f4,0xd4($sp)
/*  f0c4a10:	46100202 */ 	mul.s	$f8,$f0,$f16
/*  f0c4a14:	46085180 */ 	add.s	$f6,$f10,$f8
/*  f0c4a18:	e7a600cc */ 	swc1	$f6,0xcc($sp)
/*  f0c4a1c:	c46a1b74 */ 	lwc1	$f10,0x1b74($v1)
/*  f0c4a20:	46105202 */ 	mul.s	$f8,$f10,$f16
/*  f0c4a24:	46082180 */ 	add.s	$f6,$f4,$f8
/*  f0c4a28:	e7a600d4 */ 	swc1	$f6,0xd4($sp)
/*  f0c4a2c:	8c6c02ac */ 	lw	$t4,0x2ac($v1)
.NB0f0c4a30:
/*  f0c4a30:	246402a0 */ 	addiu	$a0,$v1,0x2a0
/*  f0c4a34:	246502a4 */ 	addiu	$a1,$v1,0x2a4
/*  f0c4a38:	5180006a */ 	beqzl	$t4,.NB0f0c4be4
/*  f0c4a3c:	8c640298 */ 	lw	$a0,0x298($v1)
/*  f0c4a40:	0c0012a8 */ 	jal	guNormalize
/*  f0c4a44:	246602a8 */ 	addiu	$a2,$v1,0x2a8
/*  f0c4a48:	3c08800a */ 	lui	$t0,0x800a
/*  f0c4a4c:	2508e6c0 */ 	addiu	$t0,$t0,-6464
/*  f0c4a50:	8d030284 */ 	lw	$v1,0x284($t0)
/*  f0c4a54:	c7a400d4 */ 	lwc1	$f4,0xd4($sp)
/*  f0c4a58:	c7a600cc */ 	lwc1	$f6,0xcc($sp)
/*  f0c4a5c:	c46a02a8 */ 	lwc1	$f10,0x2a8($v1)
/*  f0c4a60:	c46202a0 */ 	lwc1	$f2,0x2a0($v1)
/*  f0c4a64:	3c01c080 */ 	lui	$at,0xc080
/*  f0c4a68:	46045202 */ 	mul.s	$f8,$f10,$f4
/*  f0c4a6c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c4a70:	46023282 */ 	mul.s	$f10,$f6,$f2
/*  f0c4a74:	460a4000 */ 	add.s	$f0,$f8,$f10
/*  f0c4a78:	c50a004c */ 	lwc1	$f10,0x4c($t0)
/*  f0c4a7c:	44814000 */ 	mtc1	$at,$f8
/*  f0c4a80:	46000007 */ 	neg.s	$f0,$f0
/*  f0c4a84:	460a4202 */ 	mul.s	$f8,$f8,$f10
/*  f0c4a88:	4600403c */ 	c.lt.s	$f8,$f0
/*  f0c4a8c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c4a90:	45000051 */ 	bc1f	.NB0f0c4bd8
/*  f0c4a94:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c4a98:	4614003c */ 	c.lt.s	$f0,$f20
/*  f0c4a9c:	27a50070 */ 	addiu	$a1,$sp,0x70
/*  f0c4aa0:	27a6006c */ 	addiu	$a2,$sp,0x6c
/*  f0c4aa4:	27a70068 */ 	addiu	$a3,$sp,0x68
/*  f0c4aa8:	4502000e */ 	bc1fl	.NB0f0c4ae4
/*  f0c4aac:	8c6400bc */ 	lw	$a0,0xbc($v1)
/*  f0c4ab0:	46020282 */ 	mul.s	$f10,$f0,$f2
/*  f0c4ab4:	3c017f1a */ 	lui	$at,0x7f1a
/*  f0c4ab8:	c42c7b7c */ 	lwc1	$f12,0x7b7c($at)
/*  f0c4abc:	460a3200 */ 	add.s	$f8,$f6,$f10
/*  f0c4ac0:	e7a800cc */ 	swc1	$f8,0xcc($sp)
/*  f0c4ac4:	c46602a8 */ 	lwc1	$f6,0x2a8($v1)
/*  f0c4ac8:	46060282 */ 	mul.s	$f10,$f0,$f6
/*  f0c4acc:	460a2200 */ 	add.s	$f8,$f4,$f10
/*  f0c4ad0:	460c0182 */ 	mul.s	$f6,$f0,$f12
/*  f0c4ad4:	e7a800d4 */ 	swc1	$f8,0xd4($sp)
/*  f0c4ad8:	10000036 */ 	beqz	$zero,.NB0f0c4bb4
/*  f0c4adc:	e466029c */ 	swc1	$f6,0x29c($v1)
/*  f0c4ae0:	8c6400bc */ 	lw	$a0,0xbc($v1)
.NB0f0c4ae4:
/*  f0c4ae4:	0fc2ff20 */ 	jal	propPlayerGetBbox
/*  f0c4ae8:	e7a00074 */ 	swc1	$f0,0x74($sp)
/*  f0c4aec:	3c08800a */ 	lui	$t0,0x800a
/*  f0c4af0:	3c017f1a */ 	lui	$at,0x7f1a
/*  f0c4af4:	c42a7b80 */ 	lwc1	$f10,0x7b80($at)
/*  f0c4af8:	c7a40070 */ 	lwc1	$f4,0x70($sp)
/*  f0c4afc:	2508e6c0 */ 	addiu	$t0,$t0,-6464
/*  f0c4b00:	8d030284 */ 	lw	$v1,0x284($t0)
/*  f0c4b04:	460a2202 */ 	mul.s	$f8,$f4,$f10
/*  f0c4b08:	c7a6006c */ 	lwc1	$f6,0x6c($sp)
/*  f0c4b0c:	8c6200bc */ 	lw	$v0,0xbc($v1)
/*  f0c4b10:	c46a0074 */ 	lwc1	$f10,0x74($v1)
/*  f0c4b14:	3c013f80 */ 	lui	$at,0x3f80
/*  f0c4b18:	c442000c */ 	lwc1	$f2,0xc($v0)
/*  f0c4b1c:	34198040 */ 	dli	$t9,0x8040
/*  f0c4b20:	44054000 */ 	mfc1	$a1,$f8
/*  f0c4b24:	46023101 */ 	sub.s	$f4,$f6,$f2
/*  f0c4b28:	44813000 */ 	mtc1	$at,$f6
/*  f0c4b2c:	244d0028 */ 	addiu	$t5,$v0,0x28
/*  f0c4b30:	46025201 */ 	sub.s	$f8,$f10,$f2
/*  f0c4b34:	44062000 */ 	mfc1	$a2,$f4
/*  f0c4b38:	afad0010 */ 	sw	$t5,0x10($sp)
/*  f0c4b3c:	afb90014 */ 	sw	$t9,0x14($sp)
/*  f0c4b40:	46064100 */ 	add.s	$f4,$f8,$f6
/*  f0c4b44:	24440008 */ 	addiu	$a0,$v0,0x8
/*  f0c4b48:	44072000 */ 	mfc1	$a3,$f4
/*  f0c4b4c:	0c00ad61 */ 	jal	func0002a13c
/*  f0c4b50:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c4b54:	3c08800a */ 	lui	$t0,0x800a
/*  f0c4b58:	2508e6c0 */ 	addiu	$t0,$t0,-6464
/*  f0c4b5c:	14400006 */ 	bnez	$v0,.NB0f0c4b78
/*  f0c4b60:	c7a00074 */ 	lwc1	$f0,0x74($sp)
/*  f0c4b64:	8d180284 */ 	lw	$t8,0x284($t0)
/*  f0c4b68:	3c017f1a */ 	lui	$at,0x7f1a
/*  f0c4b6c:	e714029c */ 	swc1	$f20,0x29c($t8)
/*  f0c4b70:	10000010 */ 	beqz	$zero,.NB0f0c4bb4
/*  f0c4b74:	c42c7b84 */ 	lwc1	$f12,0x7b84($at)
.NB0f0c4b78:
/*  f0c4b78:	8d030284 */ 	lw	$v1,0x284($t0)
/*  f0c4b7c:	c7aa00cc */ 	lwc1	$f10,0xcc($sp)
/*  f0c4b80:	3c017f1a */ 	lui	$at,0x7f1a
/*  f0c4b84:	c46802a0 */ 	lwc1	$f8,0x2a0($v1)
/*  f0c4b88:	c42c7b88 */ 	lwc1	$f12,0x7b88($at)
/*  f0c4b8c:	46080182 */ 	mul.s	$f6,$f0,$f8
/*  f0c4b90:	c7a800d4 */ 	lwc1	$f8,0xd4($sp)
/*  f0c4b94:	46065100 */ 	add.s	$f4,$f10,$f6
/*  f0c4b98:	e7a400cc */ 	swc1	$f4,0xcc($sp)
/*  f0c4b9c:	c46a02a8 */ 	lwc1	$f10,0x2a8($v1)
/*  f0c4ba0:	460a0182 */ 	mul.s	$f6,$f0,$f10
/*  f0c4ba4:	46064100 */ 	add.s	$f4,$f8,$f6
/*  f0c4ba8:	460c0282 */ 	mul.s	$f10,$f0,$f12
/*  f0c4bac:	e7a400d4 */ 	swc1	$f4,0xd4($sp)
/*  f0c4bb0:	e46a029c */ 	swc1	$f10,0x29c($v1)
.NB0f0c4bb4:
/*  f0c4bb4:	c7a800cc */ 	lwc1	$f8,0xcc($sp)
/*  f0c4bb8:	c7a400d4 */ 	lwc1	$f4,0xd4($sp)
/*  f0c4bbc:	8d030284 */ 	lw	$v1,0x284($t0)
/*  f0c4bc0:	460c4182 */ 	mul.s	$f6,$f8,$f12
/*  f0c4bc4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c4bc8:	460c2282 */ 	mul.s	$f10,$f4,$f12
/*  f0c4bcc:	e7a600cc */ 	swc1	$f6,0xcc($sp)
/*  f0c4bd0:	10000003 */ 	beqz	$zero,.NB0f0c4be0
/*  f0c4bd4:	e7aa00d4 */ 	swc1	$f10,0xd4($sp)
.NB0f0c4bd8:
/*  f0c4bd8:	e474029c */ 	swc1	$f20,0x29c($v1)
/*  f0c4bdc:	8d030284 */ 	lw	$v1,0x284($t0)
.NB0f0c4be0:
/*  f0c4be0:	8c640298 */ 	lw	$a0,0x298($v1)
.NB0f0c4be4:
/*  f0c4be4:	50800015 */ 	beqzl	$a0,.NB0f0c4c3c
/*  f0c4be8:	8c6200bc */ 	lw	$v0,0xbc($v1)
/*  f0c4bec:	8c820004 */ 	lw	$v0,0x4($a0)
/*  f0c4bf0:	2401003b */ 	addiu	$at,$zero,0x3b
/*  f0c4bf4:	904e0003 */ 	lbu	$t6,0x3($v0)
/*  f0c4bf8:	55c10010 */ 	bnel	$t6,$at,.NB0f0c4c3c
/*  f0c4bfc:	8c6200bc */ 	lw	$v0,0xbc($v1)
/*  f0c4c00:	8c4f0014 */ 	lw	$t7,0x14($v0)
/*  f0c4c04:	c4460060 */ 	lwc1	$f6,0x60($v0)
/*  f0c4c08:	c7aa00cc */ 	lwc1	$f10,0xcc($sp)
/*  f0c4c0c:	c5e80008 */ 	lwc1	$f8,0x8($t7)
/*  f0c4c10:	46064101 */ 	sub.s	$f4,$f8,$f6
/*  f0c4c14:	46045200 */ 	add.s	$f8,$f10,$f4
/*  f0c4c18:	e7a800cc */ 	swc1	$f8,0xcc($sp)
/*  f0c4c1c:	8c490014 */ 	lw	$t1,0x14($v0)
/*  f0c4c20:	c44a0068 */ 	lwc1	$f10,0x68($v0)
/*  f0c4c24:	c7a800d4 */ 	lwc1	$f8,0xd4($sp)
/*  f0c4c28:	c5260010 */ 	lwc1	$f6,0x10($t1)
/*  f0c4c2c:	460a3101 */ 	sub.s	$f4,$f6,$f10
/*  f0c4c30:	46044180 */ 	add.s	$f6,$f8,$f4
/*  f0c4c34:	e7a600d4 */ 	swc1	$f6,0xd4($sp)
/*  f0c4c38:	8c6200bc */ 	lw	$v0,0xbc($v1)
.NB0f0c4c3c:
/*  f0c4c3c:	27a400cc */ 	addiu	$a0,$sp,0xcc
/*  f0c4c40:	00002825 */ 	or	$a1,$zero,$zero
/*  f0c4c44:	c44a0008 */ 	lwc1	$f10,0x8($v0)
/*  f0c4c48:	e7aa008c */ 	swc1	$f10,0x8c($sp)
/*  f0c4c4c:	c4480010 */ 	lwc1	$f8,0x10($v0)
/*  f0c4c50:	e7a80088 */ 	swc1	$f8,0x88($sp)
/*  f0c4c54:	c46400a0 */ 	lwc1	$f4,0xa0($v1)
/*  f0c4c58:	4604a032 */ 	c.eq.s	$f20,$f4
/*  f0c4c5c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c4c60:	45000002 */ 	bc1f	.NB0f0c4c6c
/*  f0c4c64:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c4c68:	24050001 */ 	addiu	$a1,$zero,0x1
.NB0f0c4c6c:
/*  f0c4c6c:	0fc30f48 */ 	jal	bwalk0f0c63bc
/*  f0c4c70:	2406003f */ 	addiu	$a2,$zero,0x3f
/*  f0c4c74:	3c08800a */ 	lui	$t0,0x800a
/*  f0c4c78:	2508e6c0 */ 	addiu	$t0,$t0,-6464
/*  f0c4c7c:	8d030284 */ 	lw	$v1,0x284($t0)
/*  f0c4c80:	8c6200bc */ 	lw	$v0,0xbc($v1)
/*  f0c4c84:	c4640318 */ 	lwc1	$f4,0x318($v1)
/*  f0c4c88:	c46a0310 */ 	lwc1	$f10,0x310($v1)
/*  f0c4c8c:	c4480010 */ 	lwc1	$f8,0x10($v0)
/*  f0c4c90:	c4460008 */ 	lwc1	$f6,0x8($v0)
/*  f0c4c94:	c462036c */ 	lwc1	$f2,0x36c($v1)
/*  f0c4c98:	46044381 */ 	sub.s	$f14,$f8,$f4
/*  f0c4c9c:	c4600374 */ 	lwc1	$f0,0x374($v1)
/*  f0c4ca0:	460a3301 */ 	sub.s	$f12,$f6,$f10
/*  f0c4ca4:	460e1182 */ 	mul.s	$f6,$f2,$f14
/*  f0c4ca8:	46006287 */ 	neg.s	$f10,$f12
/*  f0c4cac:	46005202 */ 	mul.s	$f8,$f10,$f0
/*  f0c4cb0:	460ca03e */ 	c.le.s	$f20,$f12
/*  f0c4cb4:	460e0102 */ 	mul.s	$f4,$f0,$f14
/*  f0c4cb8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c4cbc:	46026282 */ 	mul.s	$f10,$f12,$f2
/*  f0c4cc0:	46083400 */ 	add.s	$f16,$f6,$f8
/*  f0c4cc4:	c7a600d4 */ 	lwc1	$f6,0xd4($sp)
/*  f0c4cc8:	46061202 */ 	mul.s	$f8,$f2,$f6
/*  f0c4ccc:	460a2480 */ 	add.s	$f18,$f4,$f10
/*  f0c4cd0:	c7a400cc */ 	lwc1	$f4,0xcc($sp)
/*  f0c4cd4:	46002287 */ 	neg.s	$f10,$f4
/*  f0c4cd8:	46005282 */ 	mul.s	$f10,$f10,$f0
/*  f0c4cdc:	460a4200 */ 	add.s	$f8,$f8,$f10
/*  f0c4ce0:	46060282 */ 	mul.s	$f10,$f0,$f6
/*  f0c4ce4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c4ce8:	46022182 */ 	mul.s	$f6,$f4,$f2
/*  f0c4cec:	e7a8004c */ 	swc1	$f8,0x4c($sp)
/*  f0c4cf0:	46065280 */ 	add.s	$f10,$f10,$f6
/*  f0c4cf4:	4500001c */ 	bc1f	.NB0f0c4d68
/*  f0c4cf8:	e7aa0048 */ 	swc1	$f10,0x48($sp)
/*  f0c4cfc:	c460017c */ 	lwc1	$f0,0x17c($v1)
/*  f0c4d00:	46004086 */ 	mov.s	$f2,$f8
/*  f0c4d04:	c7a800cc */ 	lwc1	$f8,0xcc($sp)
/*  f0c4d08:	4600a03c */ 	c.lt.s	$f20,$f0
/*  f0c4d0c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c4d10:	4502000f */ 	bc1fl	.NB0f0c4d50
/*  f0c4d14:	4614403c */ 	c.lt.s	$f8,$f20
/*  f0c4d18:	4604a03e */ 	c.le.s	$f20,$f4
/*  f0c4d1c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c4d20:	4502002c */ 	bc1fl	.NB0f0c4dd4
/*  f0c4d24:	460ea03e */ 	c.le.s	$f20,$f14
/*  f0c4d28:	4604603c */ 	c.lt.s	$f12,$f4
/*  f0c4d2c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c4d30:	45020028 */ 	bc1fl	.NB0f0c4dd4
/*  f0c4d34:	460ea03e */ 	c.le.s	$f20,$f14
/*  f0c4d38:	46046183 */ 	div.s	$f6,$f12,$f4
/*  f0c4d3c:	46060282 */ 	mul.s	$f10,$f0,$f6
/*  f0c4d40:	e46a017c */ 	swc1	$f10,0x17c($v1)
/*  f0c4d44:	10000022 */ 	beqz	$zero,.NB0f0c4dd0
/*  f0c4d48:	8d030284 */ 	lw	$v1,0x284($t0)
/*  f0c4d4c:	4614403c */ 	c.lt.s	$f8,$f20
.NB0f0c4d50:
/*  f0c4d50:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c4d54:	4502001f */ 	bc1fl	.NB0f0c4dd4
/*  f0c4d58:	460ea03e */ 	c.le.s	$f20,$f14
/*  f0c4d5c:	e474017c */ 	swc1	$f20,0x17c($v1)
/*  f0c4d60:	1000001b */ 	beqz	$zero,.NB0f0c4dd0
/*  f0c4d64:	8d030284 */ 	lw	$v1,0x284($t0)
.NB0f0c4d68:
/*  f0c4d68:	c460017c */ 	lwc1	$f0,0x17c($v1)
/*  f0c4d6c:	c7a2004c */ 	lwc1	$f2,0x4c($sp)
/*  f0c4d70:	c7a400cc */ 	lwc1	$f4,0xcc($sp)
/*  f0c4d74:	4614003c */ 	c.lt.s	$f0,$f20
/*  f0c4d78:	c7a800cc */ 	lwc1	$f8,0xcc($sp)
/*  f0c4d7c:	4502000f */ 	bc1fl	.NB0f0c4dbc
/*  f0c4d80:	4608a03c */ 	c.lt.s	$f20,$f8
/*  f0c4d84:	4614203e */ 	c.le.s	$f4,$f20
/*  f0c4d88:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c4d8c:	45020011 */ 	bc1fl	.NB0f0c4dd4
/*  f0c4d90:	460ea03e */ 	c.le.s	$f20,$f14
/*  f0c4d94:	460c203c */ 	c.lt.s	$f4,$f12
/*  f0c4d98:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c4d9c:	4502000d */ 	bc1fl	.NB0f0c4dd4
/*  f0c4da0:	460ea03e */ 	c.le.s	$f20,$f14
/*  f0c4da4:	46046183 */ 	div.s	$f6,$f12,$f4
/*  f0c4da8:	46060282 */ 	mul.s	$f10,$f0,$f6
/*  f0c4dac:	e46a017c */ 	swc1	$f10,0x17c($v1)
/*  f0c4db0:	10000007 */ 	beqz	$zero,.NB0f0c4dd0
/*  f0c4db4:	8d030284 */ 	lw	$v1,0x284($t0)
/*  f0c4db8:	4608a03c */ 	c.lt.s	$f20,$f8
.NB0f0c4dbc:
/*  f0c4dbc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c4dc0:	45020004 */ 	bc1fl	.NB0f0c4dd4
/*  f0c4dc4:	460ea03e */ 	c.le.s	$f20,$f14
/*  f0c4dc8:	e474017c */ 	swc1	$f20,0x17c($v1)
/*  f0c4dcc:	8d030284 */ 	lw	$v1,0x284($t0)
.NB0f0c4dd0:
/*  f0c4dd0:	460ea03e */ 	c.le.s	$f20,$f14
.NB0f0c4dd4:
/*  f0c4dd4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c4dd8:	4502001d */ 	bc1fl	.NB0f0c4e50
/*  f0c4ddc:	c4600184 */ 	lwc1	$f0,0x184($v1)
/*  f0c4de0:	c4600184 */ 	lwc1	$f0,0x184($v1)
/*  f0c4de4:	c7a400d4 */ 	lwc1	$f4,0xd4($sp)
/*  f0c4de8:	c7a800d4 */ 	lwc1	$f8,0xd4($sp)
/*  f0c4dec:	4600a03c */ 	c.lt.s	$f20,$f0
/*  f0c4df0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c4df4:	4502000f */ 	bc1fl	.NB0f0c4e34
/*  f0c4df8:	4614403c */ 	c.lt.s	$f8,$f20
/*  f0c4dfc:	4604a03e */ 	c.le.s	$f20,$f4
/*  f0c4e00:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c4e04:	4502002c */ 	bc1fl	.NB0f0c4eb8
/*  f0c4e08:	46141032 */ 	c.eq.s	$f2,$f20
/*  f0c4e0c:	4604703c */ 	c.lt.s	$f14,$f4
/*  f0c4e10:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c4e14:	45020028 */ 	bc1fl	.NB0f0c4eb8
/*  f0c4e18:	46141032 */ 	c.eq.s	$f2,$f20
/*  f0c4e1c:	46047183 */ 	div.s	$f6,$f14,$f4
/*  f0c4e20:	46060282 */ 	mul.s	$f10,$f0,$f6
/*  f0c4e24:	e46a0184 */ 	swc1	$f10,0x184($v1)
/*  f0c4e28:	10000022 */ 	beqz	$zero,.NB0f0c4eb4
/*  f0c4e2c:	8d030284 */ 	lw	$v1,0x284($t0)
/*  f0c4e30:	4614403c */ 	c.lt.s	$f8,$f20
.NB0f0c4e34:
/*  f0c4e34:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c4e38:	4502001f */ 	bc1fl	.NB0f0c4eb8
/*  f0c4e3c:	46141032 */ 	c.eq.s	$f2,$f20
/*  f0c4e40:	e4740184 */ 	swc1	$f20,0x184($v1)
/*  f0c4e44:	1000001b */ 	beqz	$zero,.NB0f0c4eb4
/*  f0c4e48:	8d030284 */ 	lw	$v1,0x284($t0)
/*  f0c4e4c:	c4600184 */ 	lwc1	$f0,0x184($v1)
.NB0f0c4e50:
/*  f0c4e50:	c7a400d4 */ 	lwc1	$f4,0xd4($sp)
/*  f0c4e54:	c7a800d4 */ 	lwc1	$f8,0xd4($sp)
/*  f0c4e58:	4614003c */ 	c.lt.s	$f0,$f20
/*  f0c4e5c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c4e60:	4502000f */ 	bc1fl	.NB0f0c4ea0
/*  f0c4e64:	4608a03c */ 	c.lt.s	$f20,$f8
/*  f0c4e68:	4614203e */ 	c.le.s	$f4,$f20
/*  f0c4e6c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c4e70:	45020011 */ 	bc1fl	.NB0f0c4eb8
/*  f0c4e74:	46141032 */ 	c.eq.s	$f2,$f20
/*  f0c4e78:	460e203c */ 	c.lt.s	$f4,$f14
/*  f0c4e7c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c4e80:	4502000d */ 	bc1fl	.NB0f0c4eb8
/*  f0c4e84:	46141032 */ 	c.eq.s	$f2,$f20
/*  f0c4e88:	46047183 */ 	div.s	$f6,$f14,$f4
/*  f0c4e8c:	46060282 */ 	mul.s	$f10,$f0,$f6
/*  f0c4e90:	e46a0184 */ 	swc1	$f10,0x184($v1)
/*  f0c4e94:	10000007 */ 	beqz	$zero,.NB0f0c4eb4
/*  f0c4e98:	8d030284 */ 	lw	$v1,0x284($t0)
/*  f0c4e9c:	4608a03c */ 	c.lt.s	$f20,$f8
.NB0f0c4ea0:
/*  f0c4ea0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c4ea4:	45020004 */ 	bc1fl	.NB0f0c4eb8
/*  f0c4ea8:	46141032 */ 	c.eq.s	$f2,$f20
/*  f0c4eac:	e4740184 */ 	swc1	$f20,0x184($v1)
/*  f0c4eb0:	8d030284 */ 	lw	$v1,0x284($t0)
.NB0f0c4eb4:
/*  f0c4eb4:	46141032 */ 	c.eq.s	$f2,$f20
.NB0f0c4eb8:
/*  f0c4eb8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c4ebc:	4503001a */ 	bc1tl	.NB0f0c4f28
/*  f0c4ec0:	c7a20048 */ 	lwc1	$f2,0x48($sp)
/*  f0c4ec4:	c460016c */ 	lwc1	$f0,0x16c($v1)
/*  f0c4ec8:	46020102 */ 	mul.s	$f4,$f0,$f2
/*  f0c4ecc:	4604a03c */ 	c.lt.s	$f20,$f4
/*  f0c4ed0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c4ed4:	45020014 */ 	bc1fl	.NB0f0c4f28
/*  f0c4ed8:	c7a20048 */ 	lwc1	$f2,0x48($sp)
/*  f0c4edc:	46028403 */ 	div.s	$f16,$f16,$f2
/*  f0c4ee0:	3c013f80 */ 	lui	$at,0x3f80
/*  f0c4ee4:	4614803e */ 	c.le.s	$f16,$f20
/*  f0c4ee8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c4eec:	45020005 */ 	bc1fl	.NB0f0c4f04
/*  f0c4ef0:	44813000 */ 	mtc1	$at,$f6
/*  f0c4ef4:	e474016c */ 	swc1	$f20,0x16c($v1)
/*  f0c4ef8:	1000000a */ 	beqz	$zero,.NB0f0c4f24
/*  f0c4efc:	8d030284 */ 	lw	$v1,0x284($t0)
/*  f0c4f00:	44813000 */ 	mtc1	$at,$f6
.NB0f0c4f04:
/*  f0c4f04:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c4f08:	4606803c */ 	c.lt.s	$f16,$f6
/*  f0c4f0c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c4f10:	45020005 */ 	bc1fl	.NB0f0c4f28
/*  f0c4f14:	c7a20048 */ 	lwc1	$f2,0x48($sp)
/*  f0c4f18:	46100282 */ 	mul.s	$f10,$f0,$f16
/*  f0c4f1c:	e46a016c */ 	swc1	$f10,0x16c($v1)
/*  f0c4f20:	8d030284 */ 	lw	$v1,0x284($t0)
.NB0f0c4f24:
/*  f0c4f24:	c7a20048 */ 	lwc1	$f2,0x48($sp)
.NB0f0c4f28:
/*  f0c4f28:	46141032 */ 	c.eq.s	$f2,$f20
/*  f0c4f2c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c4f30:	4503001a */ 	bc1tl	.NB0f0c4f9c
/*  f0c4f34:	8c6200bc */ 	lw	$v0,0xbc($v1)
/*  f0c4f38:	c46019a4 */ 	lwc1	$f0,0x19a4($v1)
/*  f0c4f3c:	46020202 */ 	mul.s	$f8,$f0,$f2
/*  f0c4f40:	4608a03c */ 	c.lt.s	$f20,$f8
/*  f0c4f44:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c4f48:	45020014 */ 	bc1fl	.NB0f0c4f9c
/*  f0c4f4c:	8c6200bc */ 	lw	$v0,0xbc($v1)
/*  f0c4f50:	46029483 */ 	div.s	$f18,$f18,$f2
/*  f0c4f54:	3c013f80 */ 	lui	$at,0x3f80
/*  f0c4f58:	4614903e */ 	c.le.s	$f18,$f20
/*  f0c4f5c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c4f60:	45020005 */ 	bc1fl	.NB0f0c4f78
/*  f0c4f64:	44812000 */ 	mtc1	$at,$f4
/*  f0c4f68:	e47419a4 */ 	swc1	$f20,0x19a4($v1)
/*  f0c4f6c:	1000000a */ 	beqz	$zero,.NB0f0c4f98
/*  f0c4f70:	8d030284 */ 	lw	$v1,0x284($t0)
/*  f0c4f74:	44812000 */ 	mtc1	$at,$f4
.NB0f0c4f78:
/*  f0c4f78:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c4f7c:	4604903c */ 	c.lt.s	$f18,$f4
/*  f0c4f80:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c4f84:	45020005 */ 	bc1fl	.NB0f0c4f9c
/*  f0c4f88:	8c6200bc */ 	lw	$v0,0xbc($v1)
/*  f0c4f8c:	46120182 */ 	mul.s	$f6,$f0,$f18
/*  f0c4f90:	e46619a4 */ 	swc1	$f6,0x19a4($v1)
/*  f0c4f94:	8d030284 */ 	lw	$v1,0x284($t0)
.NB0f0c4f98:
/*  f0c4f98:	8c6200bc */ 	lw	$v0,0xbc($v1)
.NB0f0c4f9c:
/*  f0c4f9c:	c7a8008c */ 	lwc1	$f8,0x8c($sp)
/*  f0c4fa0:	c7a60088 */ 	lwc1	$f6,0x88($sp)
/*  f0c4fa4:	c44a0008 */ 	lwc1	$f10,0x8($v0)
/*  f0c4fa8:	c4440010 */ 	lwc1	$f4,0x10($v0)
/*  f0c4fac:	46085001 */ 	sub.s	$f0,$f10,$f8
/*  f0c4fb0:	c7aa00d4 */ 	lwc1	$f10,0xd4($sp)
/*  f0c4fb4:	46062081 */ 	sub.s	$f2,$f4,$f6
/*  f0c4fb8:	460a5202 */ 	mul.s	$f8,$f10,$f10
/*  f0c4fbc:	c7a400cc */ 	lwc1	$f4,0xcc($sp)
/*  f0c4fc0:	46042182 */ 	mul.s	$f6,$f4,$f4
/*  f0c4fc4:	46064380 */ 	add.s	$f14,$f8,$f6
/*  f0c4fc8:	46147032 */ 	c.eq.s	$f14,$f20
/*  f0c4fcc:	46007306 */ 	mov.s	$f12,$f14
/*  f0c4fd0:	45010006 */ 	bc1t	.NB0f0c4fec
/*  f0c4fd4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c4fd8:	46000282 */ 	mul.s	$f10,$f0,$f0
/*  f0c4fdc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c4fe0:	46021102 */ 	mul.s	$f4,$f2,$f2
/*  f0c4fe4:	46045200 */ 	add.s	$f8,$f10,$f4
/*  f0c4fe8:	460e4303 */ 	div.s	$f12,$f8,$f14
.NB0f0c4fec:
/*  f0c4fec:	0c012e84 */ 	jal	sqrtf
/*  f0c4ff0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c4ff4:	c7aa00b4 */ 	lwc1	$f10,0xb4($sp)
/*  f0c4ff8:	3c08800a */ 	lui	$t0,0x800a
/*  f0c4ffc:	2508e6c0 */ 	addiu	$t0,$t0,-6464
/*  f0c5000:	460a0102 */ 	mul.s	$f4,$f0,$f10
/*  f0c5004:	8d030284 */ 	lw	$v1,0x284($t0)
/*  f0c5008:	c46600a4 */ 	lwc1	$f6,0xa4($v1)
/*  f0c500c:	46043200 */ 	add.s	$f8,$f6,$f4
/*  f0c5010:	e46800a4 */ 	swc1	$f8,0xa4($v1)
/*  f0c5014:	c7a600b0 */ 	lwc1	$f6,0xb0($sp)
/*  f0c5018:	8d030284 */ 	lw	$v1,0x284($t0)
/*  f0c501c:	46060102 */ 	mul.s	$f4,$f0,$f6
/*  f0c5020:	c46a00a8 */ 	lwc1	$f10,0xa8($v1)
/*  f0c5024:	46045200 */ 	add.s	$f8,$f10,$f4
/*  f0c5028:	e46800a8 */ 	swc1	$f8,0xa8($v1)
.NB0f0c502c:
/*  f0c502c:	8d030284 */ 	lw	$v1,0x284($t0)
/*  f0c5030:	3c017f1a */ 	lui	$at,0x7f1a
/*  f0c5034:	c4247b8c */ 	lwc1	$f4,0x7b8c($at)
/*  f0c5038:	c4660148 */ 	lwc1	$f6,0x148($v1)
/*  f0c503c:	3c0140a0 */ 	lui	$at,0x40a0
/*  f0c5040:	e7a60044 */ 	swc1	$f6,0x44($sp)
/*  f0c5044:	c46a015c */ 	lwc1	$f10,0x15c($v1)
/*  f0c5048:	c46600b8 */ 	lwc1	$f6,0xb8($v1)
/*  f0c504c:	46045203 */ 	div.s	$f8,$f10,$f4
/*  f0c5050:	44815000 */ 	mtc1	$at,$f10
/*  f0c5054:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c5058:	460a3103 */ 	div.s	$f4,$f6,$f10
/*  f0c505c:	c46600cc */ 	lwc1	$f6,0xcc($v1)
/*  f0c5060:	e7a6003c */ 	swc1	$f6,0x3c($sp)
/*  f0c5064:	46044080 */ 	add.s	$f2,$f8,$f4
/*  f0c5068:	0fc43973 */ 	jal	bheadGetBreathingValue
/*  f0c506c:	e7a20040 */ 	swc1	$f2,0x40($sp)
/*  f0c5070:	3c013f80 */ 	lui	$at,0x3f80
/*  f0c5074:	44817000 */ 	mtc1	$at,$f14
/*  f0c5078:	c7a20040 */ 	lwc1	$f2,0x40($sp)
/*  f0c507c:	3c08800a */ 	lui	$t0,0x800a
/*  f0c5080:	2508e6c0 */ 	addiu	$t0,$t0,-6464
/*  f0c5084:	4602703c */ 	c.lt.s	$f14,$f2
/*  f0c5088:	46000306 */ 	mov.s	$f12,$f0
/*  f0c508c:	3c01bf80 */ 	lui	$at,0xbf80
/*  f0c5090:	8fa70044 */ 	lw	$a3,0x44($sp)
/*  f0c5094:	45020004 */ 	bc1fl	.NB0f0c50a8
/*  f0c5098:	44817000 */ 	mtc1	$at,$f14
/*  f0c509c:	10000008 */ 	beqz	$zero,.NB0f0c50c0
/*  f0c50a0:	46007086 */ 	mov.s	$f2,$f14
/*  f0c50a4:	44817000 */ 	mtc1	$at,$f14
.NB0f0c50a8:
/*  f0c50a8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c50ac:	460e103c */ 	c.lt.s	$f2,$f14
/*  f0c50b0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c50b4:	45020003 */ 	bc1fl	.NB0f0c50c4
/*  f0c50b8:	8d0a0284 */ 	lw	$t2,0x284($t0)
/*  f0c50bc:	46007086 */ 	mov.s	$f2,$f14
.NB0f0c50c0:
/*  f0c50c0:	8d0a0284 */ 	lw	$t2,0x284($t0)
.NB0f0c50c4:
/*  f0c50c4:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0c50c8:	44061000 */ 	mfc1	$a2,$f2
/*  f0c50cc:	8d4b03ac */ 	lw	$t3,0x3ac($t2)
/*  f0c50d0:	c7ae003c */ 	lwc1	$f14,0x3c($sp)
/*  f0c50d4:	15610004 */ 	bne	$t3,$at,.NB0f0c50e8
/*  f0c50d8:	3c017f1a */ 	lui	$at,0x7f1a
/*  f0c50dc:	c42a7b90 */ 	lwc1	$f10,0x7b90($at)
/*  f0c50e0:	460a0302 */ 	mul.s	$f12,$f0,$f10
/*  f0c50e4:	00000000 */ 	sll	$zero,$zero,0x0
.NB0f0c50e8:
/*  f0c50e8:	0fc26dfe */ 	jal	func0f09d8dc
/*  f0c50ec:	e7b40010 */ 	swc1	$f20,0x10($sp)
/*  f0c50f0:	3c08800a */ 	lui	$t0,0x800a
/*  f0c50f4:	2508e6c0 */ 	addiu	$t0,$t0,-6464
/*  f0c50f8:	8d0c0284 */ 	lw	$t4,0x284($t0)
/*  f0c50fc:	3c017f1a */ 	lui	$at,0x7f1a
/*  f0c5100:	c4247b94 */ 	lwc1	$f4,0x7b94($at)
/*  f0c5104:	c5880158 */ 	lwc1	$f8,0x158($t4)
/*  f0c5108:	46044302 */ 	mul.s	$f12,$f8,$f4
/*  f0c510c:	0fc28003 */ 	jal	handSetAdjustPos
/*  f0c5110:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c5114:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*  f0c5118:	d7b40018 */ 	ldc1	$f20,0x18($sp)
/*  f0c511c:	27bd00e8 */ 	addiu	$sp,$sp,0xe8
/*  f0c5120:	03e00008 */ 	jr	$ra
/*  f0c5124:	00000000 */ 	sll	$zero,$zero,0x0
);
#endif

void bwalkTick(void)
{
	s32 i;
	struct coord sStack16;

	bwalkUpdatePrevPos();
	bwalkUpdateTheta();
	bmoveUpdateVerta();
	bwalk0f0c69b8();
	bwalkUpdateVertical();

#if VERSION >= VERSION_NTSC_1_0
	for (i = 0; g_Vars.currentplayer->prop->rooms[i] != -1; i++) {
		if (g_Vars.currentplayer->floorroom == g_Vars.currentplayer->prop->rooms[i]) {
			func0f065c44(g_Vars.currentplayer->prop);
			g_Vars.currentplayer->prop->rooms[0] = g_Vars.currentplayer->floorroom;
			g_Vars.currentplayer->prop->rooms[1] = -1;
			break;
		}
	}
#endif

	bmove0f0cb8c4(g_Vars.currentplayer);
	objectiveCheckRoomEntered(g_Vars.currentplayer->prop->rooms[0]);

	if (g_Vars.currentplayer->walkinitmove) {
		sStack16.x = (g_Vars.currentplayer->walkinitstart.x - g_Vars.currentplayer->walkinitpos.x)
			* (1.0f - g_Vars.currentplayer->walkinitt2) + g_Vars.currentplayer->prop->pos.x;

		sStack16.y = (g_Vars.currentplayer->walkinitstart.y - g_Vars.currentplayer->prop->pos.y)
			* (1.0f - g_Vars.currentplayer->walkinitt2) + g_Vars.currentplayer->prop->pos.y;

		sStack16.z = (g_Vars.currentplayer->walkinitstart.z - g_Vars.currentplayer->walkinitpos.z)
			* (1.0f - g_Vars.currentplayer->walkinitt2) + g_Vars.currentplayer->prop->pos.z;

		bmove0f0cc19c(&sStack16);
	} else {
		bmove0f0cc19c(&g_Vars.currentplayer->prop->pos);
	}

	currentPlayerUpdatePerimInfo();
	doorsCheckAutomatic();
}
