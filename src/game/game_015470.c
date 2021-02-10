#include <ultra64.h>
#include "constants.h"
#include "game/data/data_000000.h"
#include "game/data/data_0083d0.h"
#include "game/data/data_00e460.h"
#include "game/data/data_0160b0.h"
#include "game/data/data_01a3a0.h"
#include "game/data/data_020df0.h"
#include "game/data/data_02da90.h"
#include "game/game_015470.h"
#include "game/game_01afc0.h"
#include "gvars/gvars.h"
#include "lib/lib_09660.h"
#include "lib/lib_0d0a0.h"
#include "lib/lib_317f0.h"
#include "types.h"

const u32 var7f1a83b0[] = {0x459c4000};
const u32 var7f1a83b4[] = {0x00000000};
const u32 var7f1a83b8[] = {0x00000000};
const u32 var7f1a83bc[] = {0x00000000};

u32 var80062410 = 0x00000000;
u8 var80062414 = 3;
u32 var80062418 = 0x00dc0000;
u32 var8006241c = 0x00dc0000;
u32 var80062420 = 0x00ff0000;
u32 var80062424 = 0x00ff0000;
u32 var80062428 = 0x007f0000;
u32 var8006242c = 0x00000000;
u32 var80062430 = 0xdcdcdc00;
u32 var80062434 = 0xdcdcdc00;
u32 var80062438 = 0xffffff00;
u32 var8006243c = 0xffffff00;
u32 var80062440 = 0x007f0000;
u32 var80062444 = 0x00000000;
u32 var80062448 = 0xffffff00;
u32 var8006244c = 0xffffff00;
u32 var80062450 = 0x00000000;
u32 var80062454 = 0x00000000;
u32 var80062458 = 0x00000000;
u32 var8006245c = 0x00000000;
u32 var80062460 = 0x00000000;
u32 var80062464 = 0x00000000;
u32 var80062468 = 0x45989800;
u32 var8006246c = 0x00000000;
u32 var80062470 = 0x00000000;
u32 var80062474 = 0xbf800000;
u32 var80062478 = 0x00000000;
u32 var8006247c = 0x3f800000;
u32 var80062480 = 0x00000000;
f32 var80062484 = 0;
u32 var80062488 = 0x3f800000;
u32 var8006248c = 0x00000000;
u32 var80062490 = 0x00000000;
u32 var80062494 = 0x00000001;
s32 var80062498 = 0;
u32 var8006249c = 0x00000000;

void func0f015470(void)
{
	s32 i;
	s32 j;

	for (i = 0; i < PLAYERCOUNT(); i++) {
		for (j = 0; j < 2; j++) {
			struct hand *hand = &g_Vars.players[i]->hands[j];

			if (hand->audiohandle2 && audioIsPlaying(hand->audiohandle2)) {
				audioStop(hand->audiohandle2);
			}
		}
	}
}

Gfx *func0f0155f0(Gfx *gdl, s32 arg1, u32 arg2);

GLOBAL_ASM(
glabel func0f0155f0
/*  f0155f0:	44852000 */ 	mtc1	$a1,$f4
/*  f0155f4:	27bdfef8 */ 	addiu	$sp,$sp,-264
/*  f0155f8:	3c018006 */ 	lui	$at,%hi(var80062468)
/*  f0155fc:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f015600:	afbf0034 */ 	sw	$ra,0x34($sp)
/*  f015604:	afb00030 */ 	sw	$s0,0x30($sp)
/*  f015608:	afa60110 */ 	sw	$a2,0x110($sp)
/*  f01560c:	3c0f8006 */ 	lui	$t7,%hi(var80061360)
/*  f015610:	25ef1360 */ 	addiu	$t7,$t7,%lo(var80061360)
/*  f015614:	e4262468 */ 	swc1	$f6,%lo(var80062468)($at)
/*  f015618:	3c0e0600 */ 	lui	$t6,0x600
/*  f01561c:	ac8e0000 */ 	sw	$t6,0x0($a0)
/*  f015620:	ac8f0004 */ 	sw	$t7,0x4($a0)
/*  f015624:	3c188006 */ 	lui	$t8,%hi(var80062494)
/*  f015628:	8f182494 */ 	lw	$t8,%lo(var80062494)($t8)
/*  f01562c:	24900008 */ 	addiu	$s0,$a0,0x8
/*  f015630:	02001025 */ 	or	$v0,$s0,$zero
/*  f015634:	13000007 */ 	beqz	$t8,.L0f015654
/*  f015638:	3c19ba00 */ 	lui	$t9,0xba00
/*  f01563c:	0fc06bf0 */ 	jal	func0f01afc0
/*  f015640:	02002025 */ 	or	$a0,$s0,$zero
/*  f015644:	3c018006 */ 	lui	$at,%hi(var80062494)
/*  f015648:	00408025 */ 	or	$s0,$v0,$zero
/*  f01564c:	10000023 */ 	b	.L0f0156dc
/*  f015650:	ac202494 */ 	sw	$zero,%lo(var80062494)($at)
.L0f015654:
/*  f015654:	37391402 */ 	ori	$t9,$t9,0x1402
/*  f015658:	3c0e0030 */ 	lui	$t6,0x30
/*  f01565c:	ac4e0004 */ 	sw	$t6,0x4($v0)
/*  f015660:	ac590000 */ 	sw	$t9,0x0($v0)
/*  f015664:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f015668:	afb000fc */ 	sw	$s0,0xfc($sp)
/*  f01566c:	0c002f02 */ 	jal	viGetX
/*  f015670:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f015674:	244fffff */ 	addiu	$t7,$v0,-1
/*  f015678:	8fae00fc */ 	lw	$t6,0xfc($sp)
/*  f01567c:	31f80fff */ 	andi	$t8,$t7,0xfff
/*  f015680:	3c01ff10 */ 	lui	$at,0xff10
/*  f015684:	0301c825 */ 	or	$t9,$t8,$at
/*  f015688:	0c002ac7 */ 	jal	viGetUnk28
/*  f01568c:	add90000 */ 	sw	$t9,0x0($t6)
/*  f015690:	0c012d20 */ 	jal	osVirtualToPhysical
/*  f015694:	00402025 */ 	or	$a0,$v0,$zero
/*  f015698:	8faf00fc */ 	lw	$t7,0xfc($sp)
/*  f01569c:	02001825 */ 	or	$v1,$s0,$zero
/*  f0156a0:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f0156a4:	ade20004 */ 	sw	$v0,0x4($t7)
/*  f0156a8:	3c190001 */ 	lui	$t9,0x1
/*  f0156ac:	37390001 */ 	ori	$t9,$t9,0x1
/*  f0156b0:	3c18f700 */ 	lui	$t8,0xf700
/*  f0156b4:	02002025 */ 	or	$a0,$s0,$zero
/*  f0156b8:	ac780000 */ 	sw	$t8,0x0($v1)
/*  f0156bc:	ac790004 */ 	sw	$t9,0x4($v1)
/*  f0156c0:	3c0f0032 */ 	lui	$t7,0x32
/*  f0156c4:	3c0ef66d */ 	lui	$t6,0xf66d
/*  f0156c8:	35cec5ec */ 	ori	$t6,$t6,0xc5ec
/*  f0156cc:	35ef0190 */ 	ori	$t7,$t7,0x190
/*  f0156d0:	ac8f0004 */ 	sw	$t7,0x4($a0)
/*  f0156d4:	ac8e0000 */ 	sw	$t6,0x0($a0)
/*  f0156d8:	26100008 */ 	addiu	$s0,$s0,0x8
.L0f0156dc:
/*  f0156dc:	3c0142c8 */ 	lui	$at,0x42c8
/*  f0156e0:	44814000 */ 	mtc1	$at,$f8
/*  f0156e4:	3c017f1b */ 	lui	$at,%hi(var7f1a83b0)
/*  f0156e8:	3c188006 */ 	lui	$t8,%hi(var80062410)
/*  f0156ec:	8f182410 */ 	lw	$t8,%lo(var80062410)($t8)
/*  f0156f0:	c42a83b0 */ 	lwc1	$f10,%lo(var7f1a83b0)($at)
/*  f0156f4:	3c013f80 */ 	lui	$at,0x3f80
/*  f0156f8:	3c0e800a */ 	lui	$t6,%hi(var8009cc80)
/*  f0156fc:	8dcecc80 */ 	lw	$t6,%lo(var8009cc80)($t6)
/*  f015700:	44818000 */ 	mtc1	$at,$f16
/*  f015704:	3c073faa */ 	lui	$a3,0x3faa
/*  f015708:	0018c980 */ 	sll	$t9,$t8,0x6
/*  f01570c:	34e7aaab */ 	ori	$a3,$a3,0xaaab
/*  f015710:	27a500f2 */ 	addiu	$a1,$sp,0xf2
/*  f015714:	3c064270 */ 	lui	$a2,0x4270
/*  f015718:	e7a80010 */ 	swc1	$f8,0x10($sp)
/*  f01571c:	e7aa0014 */ 	swc1	$f10,0x14($sp)
/*  f015720:	032e2021 */ 	addu	$a0,$t9,$t6
/*  f015724:	0c001289 */ 	jal	guPerspective
/*  f015728:	e7b00018 */ 	swc1	$f16,0x18($sp)
/*  f01572c:	3c0fbc00 */ 	lui	$t7,0xbc00
/*  f015730:	35ef000e */ 	ori	$t7,$t7,0xe
/*  f015734:	02001025 */ 	or	$v0,$s0,$zero
/*  f015738:	ac4f0000 */ 	sw	$t7,0x0($v0)
/*  f01573c:	97b800f2 */ 	lhu	$t8,0xf2($sp)
/*  f015740:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f015744:	3c190103 */ 	lui	$t9,0x103
/*  f015748:	37390040 */ 	ori	$t9,$t9,0x40
/*  f01574c:	02005825 */ 	or	$t3,$s0,$zero
/*  f015750:	ac580004 */ 	sw	$t8,0x4($v0)
/*  f015754:	ad790000 */ 	sw	$t9,0x0($t3)
/*  f015758:	3c0e8006 */ 	lui	$t6,%hi(var80062410)
/*  f01575c:	8dce2410 */ 	lw	$t6,%lo(var80062410)($t6)
/*  f015760:	3c18800a */ 	lui	$t8,%hi(var8009cc80)
/*  f015764:	8f18cc80 */ 	lw	$t8,%lo(var8009cc80)($t8)
/*  f015768:	000e7980 */ 	sll	$t7,$t6,0x6
/*  f01576c:	afab00e8 */ 	sw	$t3,0xe8($sp)
/*  f015770:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f015774:	0c012d20 */ 	jal	osVirtualToPhysical
/*  f015778:	01f82021 */ 	addu	$a0,$t7,$t8
/*  f01577c:	8fab00e8 */ 	lw	$t3,0xe8($sp)
/*  f015780:	02001825 */ 	or	$v1,$s0,$zero
/*  f015784:	3c19b600 */ 	lui	$t9,0xb600
/*  f015788:	ad620004 */ 	sw	$v0,0x4($t3)
/*  f01578c:	240effff */ 	addiu	$t6,$zero,-1
/*  f015790:	ac6e0004 */ 	sw	$t6,0x4($v1)
/*  f015794:	ac790000 */ 	sw	$t9,0x0($v1)
/*  f015798:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f01579c:	02004025 */ 	or	$t0,$s0,$zero
/*  f0157a0:	3c0fb700 */ 	lui	$t7,0xb700
/*  f0157a4:	3c180006 */ 	lui	$t8,0x6
/*  f0157a8:	37182204 */ 	ori	$t8,$t8,0x2204
/*  f0157ac:	ad0f0000 */ 	sw	$t7,0x0($t0)
/*  f0157b0:	ad180004 */ 	sw	$t8,0x4($t0)
/*  f0157b4:	3c098006 */ 	lui	$t1,%hi(var8006246c)
/*  f0157b8:	3c0c8006 */ 	lui	$t4,%hi(var80062460)
/*  f0157bc:	258c2460 */ 	addiu	$t4,$t4,%lo(var80062460)
/*  f0157c0:	2529246c */ 	addiu	$t1,$t1,%lo(var8006246c)
/*  f0157c4:	c5320000 */ 	lwc1	$f18,0x0($t1)
/*  f0157c8:	c5800000 */ 	lwc1	$f0,0x0($t4)
/*  f0157cc:	c5260004 */ 	lwc1	$f6,0x4($t1)
/*  f0157d0:	c5820004 */ 	lwc1	$f2,0x4($t4)
/*  f0157d4:	46009100 */ 	add.s	$f4,$f18,$f0
/*  f0157d8:	c52a0008 */ 	lwc1	$f10,0x8($t1)
/*  f0157dc:	c58c0008 */ 	lwc1	$f12,0x8($t4)
/*  f0157e0:	3c0a8006 */ 	lui	$t2,%hi(var80062478)
/*  f0157e4:	254a2478 */ 	addiu	$t2,$t2,%lo(var80062478)
/*  f0157e8:	3c198006 */ 	lui	$t9,%hi(var80062410)
/*  f0157ec:	46023200 */ 	add.s	$f8,$f6,$f2
/*  f0157f0:	8f392410 */ 	lw	$t9,%lo(var80062410)($t9)
/*  f0157f4:	e7a40010 */ 	swc1	$f4,0x10($sp)
/*  f0157f8:	460c5400 */ 	add.s	$f16,$f10,$f12
/*  f0157fc:	3c0f800a */ 	lui	$t7,%hi(var8009cc84)
/*  f015800:	8defcc84 */ 	lw	$t7,%lo(var8009cc84)($t7)
/*  f015804:	c5440004 */ 	lwc1	$f4,0x4($t2)
/*  f015808:	c5460008 */ 	lwc1	$f6,0x8($t2)
/*  f01580c:	c5520000 */ 	lwc1	$f18,0x0($t2)
/*  f015810:	44050000 */ 	mfc1	$a1,$f0
/*  f015814:	44061000 */ 	mfc1	$a2,$f2
/*  f015818:	44076000 */ 	mfc1	$a3,$f12
/*  f01581c:	00197180 */ 	sll	$t6,$t9,0x6
/*  f015820:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f015824:	e7b00018 */ 	swc1	$f16,0x18($sp)
/*  f015828:	e7a80014 */ 	swc1	$f8,0x14($sp)
/*  f01582c:	01cf2021 */ 	addu	$a0,$t6,$t7
/*  f015830:	e7a40020 */ 	swc1	$f4,0x20($sp)
/*  f015834:	e7a60024 */ 	swc1	$f6,0x24($sp)
/*  f015838:	0c0010a9 */ 	jal	guLookAt
/*  f01583c:	e7b2001c */ 	swc1	$f18,0x1c($sp)
/*  f015840:	3c180102 */ 	lui	$t8,0x102
/*  f015844:	37180040 */ 	ori	$t8,$t8,0x40
/*  f015848:	02001825 */ 	or	$v1,$s0,$zero
/*  f01584c:	ac780000 */ 	sw	$t8,0x0($v1)
/*  f015850:	3c198006 */ 	lui	$t9,%hi(var80062410)
/*  f015854:	8f392410 */ 	lw	$t9,%lo(var80062410)($t9)
/*  f015858:	3c0f800a */ 	lui	$t7,%hi(var8009cc84)
/*  f01585c:	8defcc84 */ 	lw	$t7,%lo(var8009cc84)($t7)
/*  f015860:	00197180 */ 	sll	$t6,$t9,0x6
/*  f015864:	afa300dc */ 	sw	$v1,0xdc($sp)
/*  f015868:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f01586c:	0c012d20 */ 	jal	osVirtualToPhysical
/*  f015870:	01cf2021 */ 	addu	$a0,$t6,$t7
/*  f015874:	8fa300dc */ 	lw	$v1,0xdc($sp)
/*  f015878:	3c180100 */ 	lui	$t8,0x100
/*  f01587c:	37180040 */ 	ori	$t8,$t8,0x40
/*  f015880:	02005025 */ 	or	$t2,$s0,$zero
/*  f015884:	ac620004 */ 	sw	$v0,0x4($v1)
/*  f015888:	ad580000 */ 	sw	$t8,0x0($t2)
/*  f01588c:	3c198006 */ 	lui	$t9,%hi(var80062410)
/*  f015890:	8f392410 */ 	lw	$t9,%lo(var80062410)($t9)
/*  f015894:	3c0f800a */ 	lui	$t7,%hi(var8009cc88)
/*  f015898:	8defcc88 */ 	lw	$t7,%lo(var8009cc88)($t7)
/*  f01589c:	00197180 */ 	sll	$t6,$t9,0x6
/*  f0158a0:	afaa00d8 */ 	sw	$t2,0xd8($sp)
/*  f0158a4:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f0158a8:	0c012d20 */ 	jal	osVirtualToPhysical
/*  f0158ac:	01cf2021 */ 	addu	$a0,$t6,$t7
/*  f0158b0:	8faa00d8 */ 	lw	$t2,0xd8($sp)
/*  f0158b4:	02003825 */ 	or	$a3,$s0,$zero
/*  f0158b8:	3c18bc00 */ 	lui	$t8,0xbc00
/*  f0158bc:	3c198000 */ 	lui	$t9,0x8000
/*  f0158c0:	ad420004 */ 	sw	$v0,0x4($t2)
/*  f0158c4:	37390040 */ 	ori	$t9,$t9,0x40
/*  f0158c8:	37180002 */ 	ori	$t8,$t8,0x2
/*  f0158cc:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f0158d0:	02004025 */ 	or	$t0,$s0,$zero
/*  f0158d4:	acf80000 */ 	sw	$t8,0x0($a3)
/*  f0158d8:	acf90004 */ 	sw	$t9,0x4($a3)
/*  f0158dc:	3c0e0386 */ 	lui	$t6,0x386
/*  f0158e0:	3c0f8006 */ 	lui	$t7,%hi(var80062450)
/*  f0158e4:	25ef2450 */ 	addiu	$t7,$t7,%lo(var80062450)
/*  f0158e8:	35ce0010 */ 	ori	$t6,$t6,0x10
/*  f0158ec:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f0158f0:	3c038006 */ 	lui	$v1,%hi(var80062448)
/*  f0158f4:	02004825 */ 	or	$t1,$s0,$zero
/*  f0158f8:	ad0e0000 */ 	sw	$t6,0x0($t0)
/*  f0158fc:	ad0f0004 */ 	sw	$t7,0x4($t0)
/*  f015900:	3c180388 */ 	lui	$t8,0x388
/*  f015904:	24632448 */ 	addiu	$v1,$v1,%lo(var80062448)
/*  f015908:	37180010 */ 	ori	$t8,$t8,0x10
/*  f01590c:	3c198006 */ 	lui	$t9,%hi(var80062488)
/*  f015910:	ad380000 */ 	sw	$t8,0x0($t1)
/*  f015914:	ad230004 */ 	sw	$v1,0x4($t1)
/*  f015918:	27392488 */ 	addiu	$t9,$t9,%lo(var80062488)
/*  f01591c:	8f210000 */ 	lw	$at,0x0($t9)
/*  f015920:	27a400c0 */ 	addiu	$a0,$sp,0xc0
/*  f015924:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f015928:	ac810000 */ 	sw	$at,0x0($a0)
/*  f01592c:	8f2f0004 */ 	lw	$t7,0x4($t9)
/*  f015930:	27a500c4 */ 	addiu	$a1,$sp,0xc4
/*  f015934:	27a600c8 */ 	addiu	$a2,$sp,0xc8
/*  f015938:	ac8f0004 */ 	sw	$t7,0x4($a0)
/*  f01593c:	8f210008 */ 	lw	$at,0x8($t9)
/*  f015940:	0c0011e4 */ 	jal	guNormalize
/*  f015944:	ac810008 */ 	sw	$at,0x8($a0)
/*  f015948:	3c0142fe */ 	lui	$at,0x42fe
/*  f01594c:	44810000 */ 	mtc1	$at,$f0
/*  f015950:	c7a800c0 */ 	lwc1	$f8,0xc0($sp)
/*  f015954:	3c038006 */ 	lui	$v1,%hi(var80062448)
/*  f015958:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f01595c:	46004282 */ 	mul.s	$f10,$f8,$f0
/*  f015960:	24632448 */ 	addiu	$v1,$v1,%lo(var80062448)
/*  f015964:	93a20113 */ 	lbu	$v0,0x113($sp)
/*  f015968:	3c07e700 */ 	lui	$a3,0xe700
/*  f01596c:	a0600000 */ 	sb	$zero,0x0($v1)
/*  f015970:	a0600001 */ 	sb	$zero,0x1($v1)
/*  f015974:	a0600002 */ 	sb	$zero,0x2($v1)
/*  f015978:	4458f800 */ 	cfc1	$t8,$31
/*  f01597c:	44cef800 */ 	ctc1	$t6,$31
/*  f015980:	a0600004 */ 	sb	$zero,0x4($v1)
/*  f015984:	a0600005 */ 	sb	$zero,0x5($v1)
/*  f015988:	46005424 */ 	cvt.w.s	$f16,$f10
/*  f01598c:	a0600006 */ 	sb	$zero,0x6($v1)
/*  f015990:	a0620008 */ 	sb	$v0,0x8($v1)
/*  f015994:	a0620009 */ 	sb	$v0,0x9($v1)
/*  f015998:	444ef800 */ 	cfc1	$t6,$31
/*  f01599c:	a062000a */ 	sb	$v0,0xa($v1)
/*  f0159a0:	a062000c */ 	sb	$v0,0xc($v1)
/*  f0159a4:	31ce0078 */ 	andi	$t6,$t6,0x78
/*  f0159a8:	a062000d */ 	sb	$v0,0xd($v1)
/*  f0159ac:	11c00013 */ 	beqz	$t6,.L0f0159fc
/*  f0159b0:	a062000e */ 	sb	$v0,0xe($v1)
/*  f0159b4:	3c014f00 */ 	lui	$at,0x4f00
/*  f0159b8:	44818000 */ 	mtc1	$at,$f16
/*  f0159bc:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f0159c0:	46105401 */ 	sub.s	$f16,$f10,$f16
/*  f0159c4:	44cef800 */ 	ctc1	$t6,$31
/*  f0159c8:	00000000 */ 	nop
/*  f0159cc:	46008424 */ 	cvt.w.s	$f16,$f16
/*  f0159d0:	444ef800 */ 	cfc1	$t6,$31
/*  f0159d4:	00000000 */ 	nop
/*  f0159d8:	31ce0078 */ 	andi	$t6,$t6,0x78
/*  f0159dc:	15c00005 */ 	bnez	$t6,.L0f0159f4
/*  f0159e0:	00000000 */ 	nop
/*  f0159e4:	440e8000 */ 	mfc1	$t6,$f16
/*  f0159e8:	3c018000 */ 	lui	$at,0x8000
/*  f0159ec:	10000007 */ 	b	.L0f015a0c
/*  f0159f0:	01c17025 */ 	or	$t6,$t6,$at
.L0f0159f4:
/*  f0159f4:	10000005 */ 	b	.L0f015a0c
/*  f0159f8:	240effff */ 	addiu	$t6,$zero,-1
.L0f0159fc:
/*  f0159fc:	440e8000 */ 	mfc1	$t6,$f16
/*  f015a00:	00000000 */ 	nop
/*  f015a04:	05c0fffb */ 	bltz	$t6,.L0f0159f4
/*  f015a08:	00000000 */ 	nop
.L0f015a0c:
/*  f015a0c:	44d8f800 */ 	ctc1	$t8,$31
/*  f015a10:	c7b200c4 */ 	lwc1	$f18,0xc4($sp)
/*  f015a14:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f015a18:	02002025 */ 	or	$a0,$s0,$zero
/*  f015a1c:	46009102 */ 	mul.s	$f4,$f18,$f0
/*  f015a20:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f015a24:	02002825 */ 	or	$a1,$s0,$zero
/*  f015a28:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f015a2c:	02003025 */ 	or	$a2,$s0,$zero
/*  f015a30:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f015a34:	02004025 */ 	or	$t0,$s0,$zero
/*  f015a38:	4459f800 */ 	cfc1	$t9,$31
/*  f015a3c:	44cff800 */ 	ctc1	$t7,$31
/*  f015a40:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f015a44:	02001025 */ 	or	$v0,$s0,$zero
/*  f015a48:	460021a4 */ 	cvt.w.s	$f6,$f4
/*  f015a4c:	3c0b0701 */ 	lui	$t3,0x701
/*  f015a50:	a06e0010 */ 	sb	$t6,0x10($v1)
/*  f015a54:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f015a58:	444ff800 */ 	cfc1	$t7,$31
/*  f015a5c:	3c09fd10 */ 	lui	$t1,0xfd10
/*  f015a60:	356b4050 */ 	ori	$t3,$t3,0x4050
/*  f015a64:	31ef0078 */ 	andi	$t7,$t7,0x78
/*  f015a68:	11e00013 */ 	beqz	$t7,.L0f015ab8
/*  f015a6c:	3c0af510 */ 	lui	$t2,0xf510
/*  f015a70:	3c014f00 */ 	lui	$at,0x4f00
/*  f015a74:	44813000 */ 	mtc1	$at,$f6
/*  f015a78:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f015a7c:	46062181 */ 	sub.s	$f6,$f4,$f6
/*  f015a80:	44cff800 */ 	ctc1	$t7,$31
/*  f015a84:	00000000 */ 	nop
/*  f015a88:	460031a4 */ 	cvt.w.s	$f6,$f6
/*  f015a8c:	444ff800 */ 	cfc1	$t7,$31
/*  f015a90:	00000000 */ 	nop
/*  f015a94:	31ef0078 */ 	andi	$t7,$t7,0x78
/*  f015a98:	15e00005 */ 	bnez	$t7,.L0f015ab0
/*  f015a9c:	00000000 */ 	nop
/*  f015aa0:	440f3000 */ 	mfc1	$t7,$f6
/*  f015aa4:	3c018000 */ 	lui	$at,0x8000
/*  f015aa8:	10000007 */ 	b	.L0f015ac8
/*  f015aac:	01e17825 */ 	or	$t7,$t7,$at
.L0f015ab0:
/*  f015ab0:	10000005 */ 	b	.L0f015ac8
/*  f015ab4:	240fffff */ 	addiu	$t7,$zero,-1
.L0f015ab8:
/*  f015ab8:	440f3000 */ 	mfc1	$t7,$f6
/*  f015abc:	00000000 */ 	nop
/*  f015ac0:	05e0fffb */ 	bltz	$t7,.L0f015ab0
/*  f015ac4:	00000000 */ 	nop
.L0f015ac8:
/*  f015ac8:	44d9f800 */ 	ctc1	$t9,$31
/*  f015acc:	c7a800c8 */ 	lwc1	$f8,0xc8($sp)
/*  f015ad0:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f015ad4:	a06f0011 */ 	sb	$t7,0x11($v1)
/*  f015ad8:	46004282 */ 	mul.s	$f10,$f8,$f0
/*  f015adc:	3c19fc12 */ 	lui	$t9,0xfc12
/*  f015ae0:	3c1f073f */ 	lui	$ra,0x73f
/*  f015ae4:	3c014f00 */ 	lui	$at,0x4f00
/*  f015ae8:	37397e24 */ 	ori	$t9,$t9,0x7e24
/*  f015aec:	240ff9fc */ 	addiu	$t7,$zero,-1540
/*  f015af0:	37fff100 */ 	ori	$ra,$ra,0xf100
/*  f015af4:	4458f800 */ 	cfc1	$t8,$31
/*  f015af8:	44cef800 */ 	ctc1	$t6,$31
/*  f015afc:	3c0ce600 */ 	lui	$t4,0xe600
/*  f015b00:	3c0df300 */ 	lui	$t5,0xf300
/*  f015b04:	46005424 */ 	cvt.w.s	$f16,$f10
/*  f015b08:	444ef800 */ 	cfc1	$t6,$31
/*  f015b0c:	00000000 */ 	nop
/*  f015b10:	31ce0078 */ 	andi	$t6,$t6,0x78
/*  f015b14:	51c00013 */ 	beqzl	$t6,.L0f015b64
/*  f015b18:	440e8000 */ 	mfc1	$t6,$f16
/*  f015b1c:	44818000 */ 	mtc1	$at,$f16
/*  f015b20:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f015b24:	46105401 */ 	sub.s	$f16,$f10,$f16
/*  f015b28:	44cef800 */ 	ctc1	$t6,$31
/*  f015b2c:	00000000 */ 	nop
/*  f015b30:	46008424 */ 	cvt.w.s	$f16,$f16
/*  f015b34:	444ef800 */ 	cfc1	$t6,$31
/*  f015b38:	00000000 */ 	nop
/*  f015b3c:	31ce0078 */ 	andi	$t6,$t6,0x78
/*  f015b40:	15c00005 */ 	bnez	$t6,.L0f015b58
/*  f015b44:	00000000 */ 	nop
/*  f015b48:	440e8000 */ 	mfc1	$t6,$f16
/*  f015b4c:	3c018000 */ 	lui	$at,0x8000
/*  f015b50:	10000007 */ 	b	.L0f015b70
/*  f015b54:	01c17025 */ 	or	$t6,$t6,$at
.L0f015b58:
/*  f015b58:	10000005 */ 	b	.L0f015b70
/*  f015b5c:	240effff */ 	addiu	$t6,$zero,-1
/*  f015b60:	440e8000 */ 	mfc1	$t6,$f16
.L0f015b64:
/*  f015b64:	00000000 */ 	nop
/*  f015b68:	05c0fffb */ 	bltz	$t6,.L0f015b58
/*  f015b6c:	00000000 */ 	nop
.L0f015b70:
/*  f015b70:	a06e0012 */ 	sb	$t6,0x12($v1)
/*  f015b74:	ac800004 */ 	sw	$zero,0x4($a0)
/*  f015b78:	ac870000 */ 	sw	$a3,0x0($a0)
/*  f015b7c:	aca00004 */ 	sw	$zero,0x4($a1)
/*  f015b80:	aca70000 */ 	sw	$a3,0x0($a1)
/*  f015b84:	44d8f800 */ 	ctc1	$t8,$31
/*  f015b88:	acd90000 */ 	sw	$t9,0x0($a2)
/*  f015b8c:	accf0004 */ 	sw	$t7,0x4($a2)
/*  f015b90:	3c18ba00 */ 	lui	$t8,0xba00
/*  f015b94:	37181301 */ 	ori	$t8,$t8,0x1301
/*  f015b98:	3c0e0008 */ 	lui	$t6,0x8
/*  f015b9c:	ad0e0004 */ 	sw	$t6,0x4($t0)
/*  f015ba0:	ad180000 */ 	sw	$t8,0x0($t0)
/*  f015ba4:	3c19ba00 */ 	lui	$t9,0xba00
/*  f015ba8:	37391102 */ 	ori	$t9,$t9,0x1102
/*  f015bac:	ac590000 */ 	sw	$t9,0x0($v0)
/*  f015bb0:	02001825 */ 	or	$v1,$s0,$zero
/*  f015bb4:	ac400004 */ 	sw	$zero,0x4($v0)
/*  f015bb8:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f015bbc:	3c0fba00 */ 	lui	$t7,0xba00
/*  f015bc0:	35ef1001 */ 	ori	$t7,$t7,0x1001
/*  f015bc4:	02002025 */ 	or	$a0,$s0,$zero
/*  f015bc8:	ac6f0000 */ 	sw	$t7,0x0($v1)
/*  f015bcc:	ac600004 */ 	sw	$zero,0x4($v1)
/*  f015bd0:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f015bd4:	3c18ba00 */ 	lui	$t8,0xba00
/*  f015bd8:	37180e02 */ 	ori	$t8,$t8,0xe02
/*  f015bdc:	02002825 */ 	or	$a1,$s0,$zero
/*  f015be0:	ac980000 */ 	sw	$t8,0x0($a0)
/*  f015be4:	ac800004 */ 	sw	$zero,0x4($a0)
/*  f015be8:	3c0eba00 */ 	lui	$t6,0xba00
/*  f015bec:	35ce0c02 */ 	ori	$t6,$t6,0xc02
/*  f015bf0:	24192000 */ 	addiu	$t9,$zero,0x2000
/*  f015bf4:	acb90004 */ 	sw	$t9,0x4($a1)
/*  f015bf8:	acae0000 */ 	sw	$t6,0x0($a1)
/*  f015bfc:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f015c00:	02003025 */ 	or	$a2,$s0,$zero
/*  f015c04:	3c0fba00 */ 	lui	$t7,0xba00
/*  f015c08:	35ef0903 */ 	ori	$t7,$t7,0x903
/*  f015c0c:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f015c10:	accf0000 */ 	sw	$t7,0x0($a2)
/*  f015c14:	24180c00 */ 	addiu	$t8,$zero,0xc00
/*  f015c18:	02001025 */ 	or	$v0,$s0,$zero
/*  f015c1c:	acd80004 */ 	sw	$t8,0x4($a2)
/*  f015c20:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f015c24:	02001825 */ 	or	$v1,$s0,$zero
/*  f015c28:	ac400004 */ 	sw	$zero,0x4($v0)
/*  f015c2c:	ac470000 */ 	sw	$a3,0x0($v0)
/*  f015c30:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f015c34:	02002025 */ 	or	$a0,$s0,$zero
/*  f015c38:	ac600004 */ 	sw	$zero,0x4($v1)
/*  f015c3c:	ac670000 */ 	sw	$a3,0x0($v1)
/*  f015c40:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f015c44:	3c0ebb00 */ 	lui	$t6,0xbb00
/*  f015c48:	3c190800 */ 	lui	$t9,0x800
/*  f015c4c:	37390800 */ 	ori	$t9,$t9,0x800
/*  f015c50:	35ce0001 */ 	ori	$t6,$t6,0x1
/*  f015c54:	02002825 */ 	or	$a1,$s0,$zero
/*  f015c58:	ac8e0000 */ 	sw	$t6,0x0($a0)
/*  f015c5c:	ac990004 */ 	sw	$t9,0x4($a0)
/*  f015c60:	3c0f0200 */ 	lui	$t7,0x200
/*  f015c64:	25ef4dc8 */ 	addiu	$t7,$t7,0x4dc8
/*  f015c68:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f015c6c:	02004025 */ 	or	$t0,$s0,$zero
/*  f015c70:	acaf0004 */ 	sw	$t7,0x4($a1)
/*  f015c74:	aca90000 */ 	sw	$t1,0x0($a1)
/*  f015c78:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f015c7c:	02001025 */ 	or	$v0,$s0,$zero
/*  f015c80:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f015c84:	ad0b0004 */ 	sw	$t3,0x4($t0)
/*  f015c88:	ad0a0000 */ 	sw	$t2,0x0($t0)
/*  f015c8c:	02001825 */ 	or	$v1,$s0,$zero
/*  f015c90:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f015c94:	ac400004 */ 	sw	$zero,0x4($v0)
/*  f015c98:	ac4c0000 */ 	sw	$t4,0x0($v0)
/*  f015c9c:	02002025 */ 	or	$a0,$s0,$zero
/*  f015ca0:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f015ca4:	ac7f0004 */ 	sw	$ra,0x4($v1)
/*  f015ca8:	ac6d0000 */ 	sw	$t5,0x0($v1)
/*  f015cac:	02002825 */ 	or	$a1,$s0,$zero
/*  f015cb0:	ac800004 */ 	sw	$zero,0x4($a0)
/*  f015cb4:	ac870000 */ 	sw	$a3,0x0($a0)
/*  f015cb8:	3c0e0001 */ 	lui	$t6,0x1
/*  f015cbc:	3c18f510 */ 	lui	$t8,0xf510
/*  f015cc0:	37181000 */ 	ori	$t8,$t8,0x1000
/*  f015cc4:	35ce4050 */ 	ori	$t6,$t6,0x4050
/*  f015cc8:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f015ccc:	02003025 */ 	or	$a2,$s0,$zero
/*  f015cd0:	acae0004 */ 	sw	$t6,0x4($a1)
/*  f015cd4:	acb80000 */ 	sw	$t8,0x0($a1)
/*  f015cd8:	3c0f0007 */ 	lui	$t7,0x7
/*  f015cdc:	35efc07c */ 	ori	$t7,$t7,0xc07c
/*  f015ce0:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f015ce4:	3c19f200 */ 	lui	$t9,0xf200
/*  f015ce8:	acd90000 */ 	sw	$t9,0x0($a2)
/*  f015cec:	accf0004 */ 	sw	$t7,0x4($a2)
/*  f015cf0:	02001025 */ 	or	$v0,$s0,$zero
/*  f015cf4:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f015cf8:	3c180600 */ 	lui	$t8,0x600
/*  f015cfc:	3c0e0200 */ 	lui	$t6,0x200
/*  f015d00:	25ce43f8 */ 	addiu	$t6,$t6,0x43f8
/*  f015d04:	ac580000 */ 	sw	$t8,0x0($v0)
/*  f015d08:	02001825 */ 	or	$v1,$s0,$zero
/*  f015d0c:	ac4e0004 */ 	sw	$t6,0x4($v0)
/*  f015d10:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f015d14:	3c0f0200 */ 	lui	$t7,0x200
/*  f015d18:	25ef4468 */ 	addiu	$t7,$t7,0x4468
/*  f015d1c:	3c190600 */ 	lui	$t9,0x600
/*  f015d20:	02002025 */ 	or	$a0,$s0,$zero
/*  f015d24:	ac790000 */ 	sw	$t9,0x0($v1)
/*  f015d28:	ac6f0004 */ 	sw	$t7,0x4($v1)
/*  f015d2c:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f015d30:	3c180200 */ 	lui	$t8,0x200
/*  f015d34:	27185dd0 */ 	addiu	$t8,$t8,0x5dd0
/*  f015d38:	02002825 */ 	or	$a1,$s0,$zero
/*  f015d3c:	ac980004 */ 	sw	$t8,0x4($a0)
/*  f015d40:	ac890000 */ 	sw	$t1,0x0($a0)
/*  f015d44:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f015d48:	02004025 */ 	or	$t0,$s0,$zero
/*  f015d4c:	acab0004 */ 	sw	$t3,0x4($a1)
/*  f015d50:	acaa0000 */ 	sw	$t2,0x0($a1)
/*  f015d54:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f015d58:	02001025 */ 	or	$v0,$s0,$zero
/*  f015d5c:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f015d60:	ad000004 */ 	sw	$zero,0x4($t0)
/*  f015d64:	ad0c0000 */ 	sw	$t4,0x0($t0)
/*  f015d68:	02001825 */ 	or	$v1,$s0,$zero
/*  f015d6c:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f015d70:	ac5f0004 */ 	sw	$ra,0x4($v0)
/*  f015d74:	ac4d0000 */ 	sw	$t5,0x0($v0)
/*  f015d78:	02002025 */ 	or	$a0,$s0,$zero
/*  f015d7c:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f015d80:	ac600004 */ 	sw	$zero,0x4($v1)
/*  f015d84:	ac670000 */ 	sw	$a3,0x0($v1)
/*  f015d88:	3c190001 */ 	lui	$t9,0x1
/*  f015d8c:	3c0ef510 */ 	lui	$t6,0xf510
/*  f015d90:	35ce1000 */ 	ori	$t6,$t6,0x1000
/*  f015d94:	37394050 */ 	ori	$t9,$t9,0x4050
/*  f015d98:	02002825 */ 	or	$a1,$s0,$zero
/*  f015d9c:	ac990004 */ 	sw	$t9,0x4($a0)
/*  f015da0:	ac8e0000 */ 	sw	$t6,0x0($a0)
/*  f015da4:	3c180007 */ 	lui	$t8,0x7
/*  f015da8:	3718c07c */ 	ori	$t8,$t8,0xc07c
/*  f015dac:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f015db0:	3c0ff200 */ 	lui	$t7,0xf200
/*  f015db4:	acaf0000 */ 	sw	$t7,0x0($a1)
/*  f015db8:	acb80004 */ 	sw	$t8,0x4($a1)
/*  f015dbc:	02003025 */ 	or	$a2,$s0,$zero
/*  f015dc0:	3c190200 */ 	lui	$t9,0x200
/*  f015dc4:	27394700 */ 	addiu	$t9,$t9,0x4700
/*  f015dc8:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f015dcc:	3c0e0600 */ 	lui	$t6,0x600
/*  f015dd0:	acce0000 */ 	sw	$t6,0x0($a2)
/*  f015dd4:	acd90004 */ 	sw	$t9,0x4($a2)
/*  f015dd8:	02001825 */ 	or	$v1,$s0,$zero
/*  f015ddc:	3c180200 */ 	lui	$t8,0x200
/*  f015de0:	27184d28 */ 	addiu	$t8,$t8,0x4d28
/*  f015de4:	3c0f0600 */ 	lui	$t7,0x600
/*  f015de8:	ac6f0000 */ 	sw	$t7,0x0($v1)
/*  f015dec:	ac780004 */ 	sw	$t8,0x4($v1)
/*  f015df0:	8fbf0034 */ 	lw	$ra,0x34($sp)
/*  f015df4:	26020008 */ 	addiu	$v0,$s0,0x8
/*  f015df8:	8fb00030 */ 	lw	$s0,0x30($sp)
/*  f015dfc:	03e00008 */ 	jr	$ra
/*  f015e00:	27bd0108 */ 	addiu	$sp,$sp,0x108
);

extern u8 _unknown2SegmentRomStart;
extern u8 _unknown2SegmentStart;
extern u8 _unknown2SegmentEnd;

void getitleInit(void *addr, u32 arg1)
{
	u32 len = (u32)&_unknown2SegmentEnd - (u32)&_unknown2SegmentStart;

	var80062414 = 0;
	var8009cc8c = 880;
	var80062484 = -40;
	var80062498 = 0;
	var8009cc90 = addr;

	func0000d410(var8009cc90, &_unknown2SegmentRomStart, ALIGN64(len));
}

Gfx *getitleRender(Gfx *gdl)
{
	var80062410 = 1 - var80062410;

	gSPSegment(gdl++, 0x02, osVirtualToPhysical(var8009cc90));

	if (var80062414 == 0 || var80062414 == 1) {
		s32 sp30;
		s32 sp2c;

		var80062498 += g_Vars.lvupdate240;

		sp30 = (var80062498 * 255) / 280;

		if (sp30 > 255) {
			sp30 = 255;
		}

		if (sp30 < 0) {
			sp30 = 0;
		}

		sp2c = 255 - (var80062498 * 255 - 163200) / 280;

		if (sp2c > 255) {
			sp2c = 255;
		}

		if (sp2c < 0) {
			sp2c = 0;
		}

		var80062484 += g_Vars.lvupdate240f + g_Vars.lvupdate240f;

		guRotate(&var8009cc88[var80062410], var80062484, 0, 1, 0);

		gdl = func0f0155f0(gdl, var8009cc8c, (sp30 * sp2c) / 255);

		if (var80062498 >= 1040 && var80062498 >= 1160) {
			var80062498 = 0;
			var80062414++;
			var80062414++;
		}
	}

	return gdl;
}

bool func0f0160e8(void)
{
	return (var80062414 ^ 2) == 0;
}
