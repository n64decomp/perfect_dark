#include <libultra_internal.h>
#include "data.h"

u32 var800907f0;
u32 var800907f4;
u32 var800907f8;
u32 var800907fc;
u32 var80090800;
u32 var80090804;
u32 var80090808;
u32 var8009080c;
u32 var80090810;
u32 var80090814;
u32 var80090818;
u32 var8009081c;
u32 var80090820;
u32 var80090824;
u32 var80090828;
u32 var8009082c;
u32 var80090830;
u32 var80090834;
u32 var80090838;
u32 var8009083c;
u32 var80090840;
u32 var80090844;
u32 var80090848;
u32 var8009084c;
u32 var80090850;
u32 var80090854;
u32 var80090858;
u32 var8009085c;
u32 var80090860;
u32 var80090864;
u32 var80090868;
u32 var8009086c;
u32 var80090870;
u32 var80090874;
u32 var80090878;
u32 var8009087c;
u32 var80090880;
u32 var80090884;
u32 var80090888;
u32 var8009088c;
u32 var80090890;
u32 var80090894;
u32 var80090898;
u32 var8009089c;
u32 var800908a0;
u32 var800908a4;
u32 var800908a8;
u32 var800908ac;
u32 var800908b0;
u32 var800908b4;
u32 var800908b8;
u32 var800908bc;
u32 var800908c0;
u32 var800908c4;
u32 var800908c8;
u32 var800908cc;
u32 var800908d0;
u32 var800908d4;
u32 var800908d8;
u32 var800908dc;
u32 var800908e0;
u32 var800908e4;
u32 var800908e8;
u32 var800908ec;
u32 var800908f0;
u32 var800908f4;
u32 var800908f8;
u32 var800908fc;
u32 var80090900;
u32 var80090904;
u32 var80090908;
u32 var8009090c;
u32 var80090910;
u32 var80090914;
u32 var80090918;
u32 var8009091c;
u32 var80090920;
u32 var80090924;
u32 var80090928;
u32 var8009092c;
u32 var80090930;
u32 var80090934;
u32 var80090938;
u32 var8009093c;
u32 var80090940;
u32 var80090944;
u32 var80090948;
u32 var8009094c;
u32 var80090950;
u32 var80090954;
u32 var80090958;
u32 var8009095c;
u32 var80090960;
u32 var80090964;
u32 var80090968;
u32 var8009096c;
u32 var80090970;
u32 var80090974;
u32 var80090978;
u32 var8009097c;
u32 var80090980;
u32 var80090984;
u32 var80090988;
u32 var8009098c;
u32 var80090990;
u32 var80090994;
u32 var80090998;
u32 var8009099c;
u32 var800909a0;
u32 var800909a4;
u32 var800909a8;
u32 var800909ac;
u32 var800909b0;
u32 var800909b4;
u32 var800909b8;
u32 var800909bc;
u32 var800909c0;
u32 var800909c4;
u32 var800909c8;
u32 var800909cc;
u32 var800909d0;
u32 var800909d4;
u32 var800909d8;
u32 var800909dc;
u32 var800909e0;
u32 var800909e4;
u32 var800909e8;
u32 var800909ec;
u32 var800909f0;
u32 var800909f4;
u32 var800909f8;
u32 var800909fc;
u32 var80090a00;
u32 var80090a04;
u32 var80090a08;
u32 var80090a0c;
u32 var80090a10;
u32 var80090a14;
u32 var80090a18;
u32 var80090a1c;

u32 var8005cf30 = 0;
u32 var8005cf34 = 0;
u32 var8005cf38 = 0;
u32 var8005cf3c = 0;
u32 var8005cf40 = 0;
u32 var8005cf44 = 0;
u32 var8005cf48 = 0;
u32 var8005cf4c = 0;
u32 var8005cf50 = 0;
u32 var8005cf54 = 0;
u32 var8005cf58 = 0;
u32 var8005cf5c = 0;

const u32 var70052450[] = {0x00141818};
const u32 var70052454[] = {0x1c1c1c1c};
const u32 var70052458[] = {0x20202020};
const u32 var7005245c[] = {0x20202020};
const u32 var70052460[] = {0x00040808};
const u32 var70052464[] = {0x0c0c0c0c};
const u32 var70052468[] = {0x10101010};
const u32 var7005246c[] = {0x10101010};

GLOBAL_ASM(
glabel __osExceptionPreamble
/*     34f0:	3c1a7000 */ 	lui	$k0,%hi(__osException)
/*     34f4:	275a3500 */ 	addiu	$k0,$k0,%lo(__osException)
/*     34f8:	03400008 */ 	jr	$k0
/*     34fc:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel __osException
.late_rodata
glabel var70052470
.word __osException+0x53c
glabel var70052474
.word __osException+0x4c8
glabel var70052478
.word __osException+0x4a8
glabel var7005247c
.word __osException+0x30c
glabel var70052480
.word __osException+0x2c8
glabel var70052484
.word __osException+0x44c
glabel var70052488
.word __osException+0x290
glabel var7005248c
.word __osException+0x29c
glabel var70052490
.word __osException+0x2a8
.text
/*     3500:	3c1a8009 */ 	lui	$k0,%hi(var800907f0)
/*     3504:	275a07f0 */ 	addiu	$k0,$k0,%lo(var800907f0)
/*     3508:	ff410020 */ 	sd	$at,0x20($k0)
/*     350c:	401b6000 */ 	mfc0	$k1,$12
/*     3510:	af5b0118 */ 	sw	$k1,0x118($k0)
/*     3514:	2401fffc */ 	addiu	$at,$zero,-4
/*     3518:	0361d824 */ 	and	$k1,$k1,$at
/*     351c:	409b6000 */ 	mtc0	$k1,$12
/*     3520:	ff480058 */ 	sd	$t0,0x58($k0)
/*     3524:	ff490060 */ 	sd	$t1,0x60($k0)
/*     3528:	ff4a0068 */ 	sd	$t2,0x68($k0)
/*     352c:	af400018 */ 	sw	$zero,0x18($k0)
/*     3530:	40086800 */ 	mfc0	$t0,$13
/*     3534:	03404025 */ 	or	$t0,$k0,$zero
/*     3538:	3c1a8006 */ 	lui	$k0,%hi(__osRunningThread)
/*     353c:	8f5a0940 */ 	lw	$k0,%lo(__osRunningThread)($k0)
/*     3540:	dd090020 */ 	ld	$t1,0x20($t0)
/*     3544:	ff490020 */ 	sd	$t1,0x20($k0)
/*     3548:	dd090118 */ 	ld	$t1,0x118($t0)
/*     354c:	ff490118 */ 	sd	$t1,0x118($k0)
/*     3550:	dd090058 */ 	ld	$t1,0x58($t0)
/*     3554:	ff490058 */ 	sd	$t1,0x58($k0)
/*     3558:	dd090060 */ 	ld	$t1,0x60($t0)
/*     355c:	ff490060 */ 	sd	$t1,0x60($k0)
/*     3560:	dd090068 */ 	ld	$t1,0x68($t0)
/*     3564:	ff490068 */ 	sd	$t1,0x68($k0)
/*     3568:	8f5b0118 */ 	lw	$k1,0x118($k0)
/*     356c:	00004012 */ 	mflo	$t0
/*     3570:	ff480108 */ 	sd	$t0,0x108($k0)
/*     3574:	00004010 */ 	mfhi	$t0
/*     3578:	3369ff00 */ 	andi	$t1,$k1,0xff00
/*     357c:	ff420028 */ 	sd	$v0,0x28($k0)
/*     3580:	ff430030 */ 	sd	$v1,0x30($k0)
/*     3584:	ff440038 */ 	sd	$a0,0x38($k0)
/*     3588:	ff450040 */ 	sd	$a1,0x40($k0)
/*     358c:	ff460048 */ 	sd	$a2,0x48($k0)
/*     3590:	ff470050 */ 	sd	$a3,0x50($k0)
/*     3594:	ff4b0070 */ 	sd	$t3,0x70($k0)
/*     3598:	ff4c0078 */ 	sd	$t4,0x78($k0)
/*     359c:	ff4d0080 */ 	sd	$t5,0x80($k0)
/*     35a0:	ff4e0088 */ 	sd	$t6,0x88($k0)
/*     35a4:	ff4f0090 */ 	sd	$t7,0x90($k0)
/*     35a8:	ff500098 */ 	sd	$s0,0x98($k0)
/*     35ac:	ff5100a0 */ 	sd	$s1,0xa0($k0)
/*     35b0:	ff5200a8 */ 	sd	$s2,0xa8($k0)
/*     35b4:	ff5300b0 */ 	sd	$s3,0xb0($k0)
/*     35b8:	ff5400b8 */ 	sd	$s4,0xb8($k0)
/*     35bc:	ff5500c0 */ 	sd	$s5,0xc0($k0)
/*     35c0:	ff5600c8 */ 	sd	$s6,0xc8($k0)
/*     35c4:	ff5700d0 */ 	sd	$s7,0xd0($k0)
/*     35c8:	ff5800d8 */ 	sd	$t8,0xd8($k0)
/*     35cc:	ff5900e0 */ 	sd	$t9,0xe0($k0)
/*     35d0:	ff5c00e8 */ 	sd	$gp,0xe8($k0)
/*     35d4:	ff5d00f0 */ 	sd	$sp,0xf0($k0)
/*     35d8:	ff5e00f8 */ 	sd	$s8,0xf8($k0)
/*     35dc:	ff5f0100 */ 	sd	$ra,0x100($k0)
/*     35e0:	11200011 */ 	beqz	$t1,.L00003628
/*     35e4:	ff480110 */ 	sd	$t0,0x110($k0)
/*     35e8:	3c088006 */ 	lui	$t0,%hi(__osGlobalIntMask)
/*     35ec:	2508cf70 */ 	addiu	$t0,$t0,%lo(__osGlobalIntMask)
/*     35f0:	8d080000 */ 	lw	$t0,0x0($t0)
/*     35f4:	2401ffff */ 	addiu	$at,$zero,-1
/*     35f8:	01015026 */ 	xor	$t2,$t0,$at
/*     35fc:	3c01ffff */ 	lui	$at,0xffff
/*     3600:	314aff00 */ 	andi	$t2,$t2,0xff00
/*     3604:	342100ff */ 	ori	$at,$at,0xff
/*     3608:	012a6025 */ 	or	$t4,$t1,$t2
/*     360c:	03615824 */ 	and	$t3,$k1,$at
/*     3610:	3108ff00 */ 	andi	$t0,$t0,0xff00
/*     3614:	016c5825 */ 	or	$t3,$t3,$t4
/*     3618:	01284824 */ 	and	$t1,$t1,$t0
/*     361c:	0361d824 */ 	and	$k1,$k1,$at
/*     3620:	af4b0118 */ 	sw	$t3,0x118($k0)
/*     3624:	0369d825 */ 	or	$k1,$k1,$t1
.L00003628:
/*     3628:	3c09a430 */ 	lui	$t1,0xa430
/*     362c:	8d29000c */ 	lw	$t1,0xc($t1)
/*     3630:	5120000c */ 	beqzl	$t1,.L00003664
/*     3634:	af490128 */ 	sw	$t1,0x128($k0)
/*     3638:	3c088006 */ 	lui	$t0,%hi(__osGlobalIntMask)
/*     363c:	2508cf70 */ 	addiu	$t0,$t0,%lo(__osGlobalIntMask)
/*     3640:	8d080000 */ 	lw	$t0,0x0($t0)
/*     3644:	8f4c0128 */ 	lw	$t4,0x128($k0)
/*     3648:	2401ffff */ 	addiu	$at,$zero,-1
/*     364c:	00084402 */ 	srl	$t0,$t0,0x10
/*     3650:	01014026 */ 	xor	$t0,$t0,$at
/*     3654:	3108003f */ 	andi	$t0,$t0,0x3f
/*     3658:	010c4024 */ 	and	$t0,$t0,$t4
/*     365c:	01284825 */ 	or	$t1,$t1,$t0
/*     3660:	af490128 */ 	sw	$t1,0x128($k0)
.L00003664:
/*     3664:	40087000 */ 	mfc0	$t0,$14
/*     3668:	af48011c */ 	sw	$t0,0x11c($k0)
/*     366c:	8f480018 */ 	lw	$t0,0x18($k0)
/*     3670:	11000024 */ 	beqz	$t0,.L00003704
/*     3674:	00000000 */ 	nop
/*     3678:	4448f800 */ 	cfc1	$t0,$31
/*     367c:	00000000 */ 	nop
/*     3680:	af48012c */ 	sw	$t0,0x12c($k0)
/*     3684:	f7400130 */ 	sdc1	$f0,0x130($k0)
/*     3688:	f7410138 */ 	sdc1	$f1,0x138($k0)
/*     368c:	f7420140 */ 	sdc1	$f2,0x140($k0)
/*     3690:	f7430148 */ 	sdc1	$f3,0x148($k0)
/*     3694:	f7440150 */ 	sdc1	$f4,0x150($k0)
/*     3698:	f7450158 */ 	sdc1	$f5,0x158($k0)
/*     369c:	f7460160 */ 	sdc1	$f6,0x160($k0)
/*     36a0:	f7470168 */ 	sdc1	$f7,0x168($k0)
/*     36a4:	f7480170 */ 	sdc1	$f8,0x170($k0)
/*     36a8:	f7490178 */ 	sdc1	$f9,0x178($k0)
/*     36ac:	f74a0180 */ 	sdc1	$f10,0x180($k0)
/*     36b0:	f74b0188 */ 	sdc1	$f11,0x188($k0)
/*     36b4:	f74c0190 */ 	sdc1	$f12,0x190($k0)
/*     36b8:	f74d0198 */ 	sdc1	$f13,0x198($k0)
/*     36bc:	f74e01a0 */ 	sdc1	$f14,0x1a0($k0)
/*     36c0:	f74f01a8 */ 	sdc1	$f15,0x1a8($k0)
/*     36c4:	f75001b0 */ 	sdc1	$f16,0x1b0($k0)
/*     36c8:	f75101b8 */ 	sdc1	$f17,0x1b8($k0)
/*     36cc:	f75201c0 */ 	sdc1	$f18,0x1c0($k0)
/*     36d0:	f75301c8 */ 	sdc1	$f19,0x1c8($k0)
/*     36d4:	f75401d0 */ 	sdc1	$f20,0x1d0($k0)
/*     36d8:	f75501d8 */ 	sdc1	$f21,0x1d8($k0)
/*     36dc:	f75601e0 */ 	sdc1	$f22,0x1e0($k0)
/*     36e0:	f75701e8 */ 	sdc1	$f23,0x1e8($k0)
/*     36e4:	f75801f0 */ 	sdc1	$f24,0x1f0($k0)
/*     36e8:	f75901f8 */ 	sdc1	$f25,0x1f8($k0)
/*     36ec:	f75a0200 */ 	sdc1	$f26,0x200($k0)
/*     36f0:	f75b0208 */ 	sdc1	$f27,0x208($k0)
/*     36f4:	f75c0210 */ 	sdc1	$f28,0x210($k0)
/*     36f8:	f75d0218 */ 	sdc1	$f29,0x218($k0)
/*     36fc:	f75e0220 */ 	sdc1	$f30,0x220($k0)
/*     3700:	f75f0228 */ 	sdc1	$f31,0x228($k0)
.L00003704:
/*     3704:	40086800 */ 	mfc0	$t0,$13
/*     3708:	af480120 */ 	sw	$t0,0x120($k0)
/*     370c:	24090002 */ 	addiu	$t1,$zero,0x2
/*     3710:	a7490010 */ 	sh	$t1,0x10($k0)
/*     3714:	3109007c */ 	andi	$t1,$t0,0x7c
/*     3718:	240a0008 */ 	addiu	$t2,$zero,0x8
/*     371c:	112a00b2 */ 	beq	$t1,$t2,.L000039e8
/*     3720:	00000000 */ 	nop
/*     3724:	240a000c */ 	addiu	$t2,$zero,0xc
/*     3728:	112a00b3 */ 	beq	$t1,$t2,.L000039f8
/*     372c:	00000000 */ 	nop
/*     3730:	240a0024 */ 	addiu	$t2,$zero,0x24
/*     3734:	512a00b3 */ 	beql	$t1,$t2,.L00003a04
/*     3738:	24090001 */ 	addiu	$t1,$zero,0x1
/*     373c:	240a002c */ 	addiu	$t2,$zero,0x2c
/*     3740:	112a010a */ 	beq	$t1,$t2,.L00003b6c
/*     3744:	00000000 */ 	nop
/*     3748:	240a0000 */ 	addiu	$t2,$zero,0x0
/*     374c:	152a00ce */ 	bne	$t1,$t2,.L00003a88
/*     3750:	00000000 */ 	nop
/*     3754:	03688024 */ 	and	$s0,$k1,$t0
.L00003758:
/*     3758:	3209ff00 */ 	andi	$t1,$s0,0xff00
.L0000375c:
/*     375c:	00095302 */ 	srl	$t2,$t1,0xc
/*     3760:	15400003 */ 	bnez	$t2,.L00003770
/*     3764:	00000000 */ 	nop
/*     3768:	00095202 */ 	srl	$t2,$t1,0x8
/*     376c:	214a0010 */ 	addi	$t2,$t2,0x10
.L00003770:
/*     3770:	3c017005 */ 	lui	$at,%hi(var70052450)
/*     3774:	002a0821 */ 	addu	$at,$at,$t2
/*     3778:	902a2450 */ 	lbu	$t2,%lo(var70052450)($at)
/*     377c:	3c017005 */ 	lui	$at,%hi(var70052470)
/*     3780:	002a0821 */ 	addu	$at,$at,$t2
/*     3784:	8c2a2470 */ 	lw	$t2,%lo(var70052470)($at)
/*     3788:	01400008 */ 	jr	$t2
/*     378c:	00000000 */ 	nop
/*     3790:	2401dfff */ 	addiu	$at,$zero,-8193
/*     3794:	1000fff0 */ 	b	.L00003758
/*     3798:	02018024 */ 	and	$s0,$s0,$at
/*     379c:	2401bfff */ 	addiu	$at,$zero,-16385
/*     37a0:	1000ffed */ 	b	.L00003758
/*     37a4:	02018024 */ 	and	$s0,$s0,$at
/*     37a8:	40095800 */ 	mfc0	$t1,$11
/*     37ac:	40895800 */ 	mtc0	$t1,$11
/*     37b0:	0c000eae */ 	jal	send_mesg
/*     37b4:	24040018 */ 	addiu	$a0,$zero,0x18
/*     37b8:	3c01ffff */ 	lui	$at,0xffff
/*     37bc:	34217fff */ 	ori	$at,$at,0x7fff
/*     37c0:	1000ffe5 */ 	b	.L00003758
/*     37c4:	02018024 */ 	and	$s0,$s0,$at
/*     37c8:	3c098006 */ 	lui	$t1,%hi(var8005cf30)
/*     37cc:	2529cf30 */ 	addiu	$t1,$t1,%lo(var8005cf30)
/*     37d0:	8d2a0008 */ 	lw	$t2,0x8($t1)
/*     37d4:	2401f7ff */ 	addiu	$at,$zero,-2049
/*     37d8:	02018024 */ 	and	$s0,$s0,$at
/*     37dc:	11400007 */ 	beqz	$t2,.L000037fc
/*     37e0:	21290008 */ 	addi	$t1,$t1,0x8
/*     37e4:	0140f809 */ 	jalr	$t2
/*     37e8:	8d3d0004 */ 	lw	$sp,0x4($t1)
/*     37ec:	10400003 */ 	beqz	$v0,.L000037fc
/*     37f0:	00000000 */ 	nop
/*     37f4:	10000091 */ 	b	.L00003a3c
/*     37f8:	00000000 */ 	nop
.L000037fc:
/*     37fc:	0c000eae */ 	jal	send_mesg
/*     3800:	24040010 */ 	addiu	$a0,$zero,0x10
/*     3804:	1000ffd5 */ 	b	.L0000375c
/*     3808:	3209ff00 */ 	andi	$t1,$s0,0xff00
/*     380c:	3c088006 */ 	lui	$t0,%hi(__osGlobalIntMask)
/*     3810:	2508cf70 */ 	addiu	$t0,$t0,%lo(__osGlobalIntMask)
/*     3814:	8d080000 */ 	lw	$t0,0x0($t0)
/*     3818:	3c11a430 */ 	lui	$s1,0xa430
/*     381c:	8e310008 */ 	lw	$s1,0x8($s1)
/*     3820:	00084402 */ 	srl	$t0,$t0,0x10
/*     3824:	02288824 */ 	and	$s1,$s1,$t0
/*     3828:	32290001 */ 	andi	$t1,$s1,0x1
/*     382c:	51200014 */ 	beqzl	$t1,.L00003880
/*     3830:	32290008 */ 	andi	$t1,$s1,0x8
/*     3834:	3c0ca404 */ 	lui	$t4,0xa404
/*     3838:	8d8c0010 */ 	lw	$t4,0x10($t4)
/*     383c:	34098008 */ 	dli	$t1,0x8008
/*     3840:	3c01a404 */ 	lui	$at,0xa404
/*     3844:	318c0300 */ 	andi	$t4,$t4,0x300
/*     3848:	3231003e */ 	andi	$s1,$s1,0x3e
/*     384c:	11800007 */ 	beqz	$t4,.L0000386c
/*     3850:	ac290010 */ 	sw	$t1,0x10($at)
/*     3854:	0c000eae */ 	jal	send_mesg
/*     3858:	24040020 */ 	addiu	$a0,$zero,0x20
/*     385c:	52200039 */ 	beqzl	$s1,.L00003944
/*     3860:	2401fbff */ 	addiu	$at,$zero,-1025
/*     3864:	10000006 */ 	b	.L00003880
/*     3868:	32290008 */ 	andi	$t1,$s1,0x8
.L0000386c:
/*     386c:	0c000eae */ 	jal	send_mesg
/*     3870:	24040058 */ 	addiu	$a0,$zero,0x58
/*     3874:	52200033 */ 	beqzl	$s1,.L00003944
/*     3878:	2401fbff */ 	addiu	$at,$zero,-1025
/*     387c:	32290008 */ 	andi	$t1,$s1,0x8
.L00003880:
/*     3880:	11200007 */ 	beqz	$t1,.L000038a0
/*     3884:	3c01a440 */ 	lui	$at,0xa440
/*     3888:	32310037 */ 	andi	$s1,$s1,0x37
/*     388c:	ac200010 */ 	sw	$zero,0x10($at)
/*     3890:	0c000eae */ 	jal	send_mesg
/*     3894:	24040038 */ 	addiu	$a0,$zero,0x38
/*     3898:	5220002a */ 	beqzl	$s1,.L00003944
/*     389c:	2401fbff */ 	addiu	$at,$zero,-1025
.L000038a0:
/*     38a0:	32290004 */ 	andi	$t1,$s1,0x4
/*     38a4:	5120000a */ 	beqzl	$t1,.L000038d0
/*     38a8:	32290002 */ 	andi	$t1,$s1,0x2
/*     38ac:	24090001 */ 	addiu	$t1,$zero,0x1
/*     38b0:	3c01a450 */ 	lui	$at,0xa450
/*     38b4:	3231003b */ 	andi	$s1,$s1,0x3b
/*     38b8:	ac29000c */ 	sw	$t1,0xc($at)
/*     38bc:	0c000eae */ 	jal	send_mesg
/*     38c0:	24040030 */ 	addiu	$a0,$zero,0x30
/*     38c4:	5220001f */ 	beqzl	$s1,.L00003944
/*     38c8:	2401fbff */ 	addiu	$at,$zero,-1025
/*     38cc:	32290002 */ 	andi	$t1,$s1,0x2
.L000038d0:
/*     38d0:	11200007 */ 	beqz	$t1,.L000038f0
/*     38d4:	3c01a480 */ 	lui	$at,0xa480
/*     38d8:	3231003d */ 	andi	$s1,$s1,0x3d
/*     38dc:	ac200018 */ 	sw	$zero,0x18($at)
/*     38e0:	0c000eae */ 	jal	send_mesg
/*     38e4:	24040028 */ 	addiu	$a0,$zero,0x28
/*     38e8:	52200016 */ 	beqzl	$s1,.L00003944
/*     38ec:	2401fbff */ 	addiu	$at,$zero,-1025
.L000038f0:
/*     38f0:	32290010 */ 	andi	$t1,$s1,0x10
/*     38f4:	5120000a */ 	beqzl	$t1,.L00003920
/*     38f8:	32290020 */ 	andi	$t1,$s1,0x20
/*     38fc:	24090002 */ 	addiu	$t1,$zero,0x2
/*     3900:	3c01a460 */ 	lui	$at,0xa460
/*     3904:	3231002f */ 	andi	$s1,$s1,0x2f
/*     3908:	ac290010 */ 	sw	$t1,0x10($at)
/*     390c:	0c000eae */ 	jal	send_mesg
/*     3910:	24040040 */ 	addiu	$a0,$zero,0x40
/*     3914:	5220000b */ 	beqzl	$s1,.L00003944
/*     3918:	2401fbff */ 	addiu	$at,$zero,-1025
/*     391c:	32290020 */ 	andi	$t1,$s1,0x20
.L00003920:
/*     3920:	51200008 */ 	beqzl	$t1,.L00003944
/*     3924:	2401fbff */ 	addiu	$at,$zero,-1025
/*     3928:	24090800 */ 	addiu	$t1,$zero,0x800
/*     392c:	3c01a430 */ 	lui	$at,0xa430
/*     3930:	3231001f */ 	andi	$s1,$s1,0x1f
/*     3934:	ac290000 */ 	sw	$t1,0x0($at)
/*     3938:	0c000eae */ 	jal	send_mesg
/*     393c:	24040048 */ 	addiu	$a0,$zero,0x48
/*     3940:	2401fbff */ 	addiu	$at,$zero,-1025
.L00003944:
/*     3944:	1000ff84 */ 	b	.L00003758
/*     3948:	02018024 */ 	and	$s0,$s0,$at
/*     394c:	8f5b0118 */ 	lw	$k1,0x118($k0)
/*     3950:	2401efff */ 	addiu	$at,$zero,-4097
/*     3954:	3c098006 */ 	lui	$t1,%hi(_osShutdown)
/*     3958:	0361d824 */ 	and	$k1,$k1,$at
/*     395c:	af5b0118 */ 	sw	$k1,0x118($k0)
/*     3960:	2529cf6c */ 	addiu	$t1,$t1,%lo(_osShutdown)
/*     3964:	8d2a0000 */ 	lw	$t2,0x0($t1)
/*     3968:	11400003 */ 	beqz	$t2,.L00003978
/*     396c:	2401efff */ 	addiu	$at,$zero,-4097
/*     3970:	10000032 */ 	b	.L00003a3c
/*     3974:	02018024 */ 	and	$s0,$s0,$at
.L00003978:
/*     3978:	240a0001 */ 	addiu	$t2,$zero,0x1
/*     397c:	ad2a0000 */ 	sw	$t2,0x0($t1)
/*     3980:	0c000eae */ 	jal	send_mesg
/*     3984:	24040070 */ 	addiu	$a0,$zero,0x70
/*     3988:	3c0a8006 */ 	lui	$t2,%hi(__osRunQueue)
/*     398c:	8d4a0938 */ 	lw	$t2,%lo(__osRunQueue)($t2)
/*     3990:	2401efff */ 	addiu	$at,$zero,-4097
/*     3994:	02018024 */ 	and	$s0,$s0,$at
/*     3998:	8d5b0118 */ 	lw	$k1,0x118($t2)
/*     399c:	0361d824 */ 	and	$k1,$k1,$at
/*     39a0:	10000026 */ 	b	.L00003a3c
/*     39a4:	ad5b0118 */ 	sw	$k1,0x118($t2)
/*     39a8:	2401fdff */ 	addiu	$at,$zero,-513
/*     39ac:	01014024 */ 	and	$t0,$t0,$at
/*     39b0:	40886800 */ 	mtc0	$t0,$13
/*     39b4:	0c000eae */ 	jal	send_mesg
/*     39b8:	24040008 */ 	addiu	$a0,$zero,0x8
/*     39bc:	2401fdff */ 	addiu	$at,$zero,-513
/*     39c0:	1000ff65 */ 	b	.L00003758
/*     39c4:	02018024 */ 	and	$s0,$s0,$at
/*     39c8:	2401feff */ 	addiu	$at,$zero,-257
/*     39cc:	01014024 */ 	and	$t0,$t0,$at
/*     39d0:	40886800 */ 	mtc0	$t0,$13
/*     39d4:	0c000eae */ 	jal	send_mesg
/*     39d8:	24040000 */ 	addiu	$a0,$zero,0x0
/*     39dc:	2401feff */ 	addiu	$at,$zero,-257
/*     39e0:	1000ff5d */ 	b	.L00003758
/*     39e4:	02018024 */ 	and	$s0,$s0,$at
.L000039e8:
/*     39e8:	0c000460 */ 	jal	boot00001180
/*     39ec:	00000000 */ 	nop
/*     39f0:	10000012 */ 	b	.L00003a3c
/*     39f4:	00000000 */ 	nop
.L000039f8:
/*     39f8:	08000ea2 */ 	j	.L00003a88
/*     39fc:	00000000 */ 	nop
/*     3a00:	24090001 */ 	addiu	$t1,$zero,0x1
.L00003a04:
/*     3a04:	a7490012 */ 	sh	$t1,0x12($k0)
/*     3a08:	8f49011c */ 	lw	$t1,0x11c($k0)
/*     3a0c:	24010006 */ 	addiu	$at,$zero,0x6
/*     3a10:	8d290000 */ 	lw	$t1,0x0($t1)
/*     3a14:	00094c02 */ 	srl	$t1,$t1,0x10
/*     3a18:	312900ff */ 	andi	$t1,$t1,0xff
/*     3a1c:	1121001a */ 	beq	$t1,$at,.L00003a88
/*     3a20:	24010007 */ 	addiu	$at,$zero,0x7
/*     3a24:	11210018 */ 	beq	$t1,$at,.L00003a88
/*     3a28:	00000000 */ 	nop
/*     3a2c:	0c000eae */ 	jal	send_mesg
/*     3a30:	24040050 */ 	addiu	$a0,$zero,0x50
/*     3a34:	10000001 */ 	b	.L00003a3c
/*     3a38:	00000000 */ 	nop
.L00003a3c:
/*     3a3c:	3c0a8006 */ 	lui	$t2,%hi(__osRunQueue)
/*     3a40:	8d4a0938 */ 	lw	$t2,%lo(__osRunQueue)($t2)
/*     3a44:	8f490004 */ 	lw	$t1,0x4($k0)
/*     3a48:	8d4b0004 */ 	lw	$t3,0x4($t2)
/*     3a4c:	012b082a */ 	slt	$at,$t1,$t3
/*     3a50:	10200007 */ 	beqz	$at,.L00003a70
/*     3a54:	00000000 */ 	nop
/*     3a58:	3c048006 */ 	lui	$a0,%hi(__osRunQueue)
/*     3a5c:	03402825 */ 	or	$a1,$k0,$zero
/*     3a60:	0c000f2e */ 	jal	__osEnqueueThread
/*     3a64:	24840938 */ 	addiu	$a0,$a0,%lo(__osRunQueue)
/*     3a68:	08000f44 */ 	j	.L00003d10
/*     3a6c:	00000000 */ 	nop
.L00003a70:
/*     3a70:	3c098006 */ 	lui	$t1,%hi(__osRunQueue)
/*     3a74:	25290938 */ 	addiu	$t1,$t1,%lo(__osRunQueue)
/*     3a78:	8d2a0000 */ 	lw	$t2,0x0($t1)
/*     3a7c:	af4a0000 */ 	sw	$t2,0x0($k0)
/*     3a80:	08000f44 */ 	j	.L00003d10
/*     3a84:	ad3a0000 */ 	sw	$k0,0x0($t1)
.L00003a88:
/*     3a88:	3c018006 */ 	lui	$at,%hi(__osFaultedThread)
/*     3a8c:	ac3a0944 */ 	sw	$k0,%lo(__osFaultedThread)($at)
/*     3a90:	24090001 */ 	addiu	$t1,$zero,0x1
/*     3a94:	a7490010 */ 	sh	$t1,0x10($k0)
/*     3a98:	24090002 */ 	addiu	$t1,$zero,0x2
/*     3a9c:	a7490012 */ 	sh	$t1,0x12($k0)
/*     3aa0:	400a4000 */ 	mfc0	$t2,$8
/*     3aa4:	af4a0124 */ 	sw	$t2,0x124($k0)
/*     3aa8:	0c000eae */ 	jal	send_mesg
/*     3aac:	24040060 */ 	addiu	$a0,$zero,0x60
/*     3ab0:	08000f44 */ 	j	.L00003d10
/*     3ab4:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel send_mesg
/*     3ab8:	3c0a800a */ 	lui	$t2,%hi(__osEventStateTab)
/*     3abc:	254ac6e0 */ 	addiu	$t2,$t2,%lo(__osEventStateTab)
/*     3ac0:	01445021 */ 	addu	$t2,$t2,$a0
/*     3ac4:	8d490000 */ 	lw	$t1,0x0($t2)
/*     3ac8:	03e09025 */ 	or	$s2,$ra,$zero
/*     3acc:	11200025 */ 	beqz	$t1,.L00003b64
/*     3ad0:	00000000 */ 	nop
/*     3ad4:	8d2b0008 */ 	lw	$t3,0x8($t1)
/*     3ad8:	8d2c0010 */ 	lw	$t4,0x10($t1)
/*     3adc:	016c082a */ 	slt	$at,$t3,$t4
/*     3ae0:	10200020 */ 	beqz	$at,.L00003b64
/*     3ae4:	00000000 */ 	nop
/*     3ae8:	8d2d000c */ 	lw	$t5,0xc($t1)
/*     3aec:	01ab6821 */ 	addu	$t5,$t5,$t3
/*     3af0:	01ac001a */ 	div	$zero,$t5,$t4
/*     3af4:	15800002 */ 	bnez	$t4,.L00003b00
/*     3af8:	00000000 */ 	nop
/*     3afc:	0007000d */ 	break	0x7
.L00003b00:
/*     3b00:	2401ffff */ 	addiu	$at,$zero,-1
/*     3b04:	15810004 */ 	bne	$t4,$at,.L00003b18
/*     3b08:	3c018000 */ 	lui	$at,0x8000
/*     3b0c:	15a10002 */ 	bne	$t5,$at,.L00003b18
/*     3b10:	00000000 */ 	nop
/*     3b14:	0006000d */ 	break	0x6
.L00003b18:
/*     3b18:	8d2c0014 */ 	lw	$t4,0x14($t1)
/*     3b1c:	00006810 */ 	mfhi	$t5
/*     3b20:	000d6880 */ 	sll	$t5,$t5,0x2
/*     3b24:	018d6021 */ 	addu	$t4,$t4,$t5
/*     3b28:	8d4d0004 */ 	lw	$t5,0x4($t2)
/*     3b2c:	256a0001 */ 	addiu	$t2,$t3,0x1
/*     3b30:	ad8d0000 */ 	sw	$t5,0x0($t4)
/*     3b34:	ad2a0008 */ 	sw	$t2,0x8($t1)
/*     3b38:	8d2a0000 */ 	lw	$t2,0x0($t1)
/*     3b3c:	8d4b0000 */ 	lw	$t3,0x0($t2)
/*     3b40:	11600008 */ 	beqz	$t3,.L00003b64
/*     3b44:	00000000 */ 	nop
/*     3b48:	0c000f40 */ 	jal	__osPopThread
/*     3b4c:	01202025 */ 	or	$a0,$t1,$zero
/*     3b50:	00405025 */ 	or	$t2,$v0,$zero
/*     3b54:	3c048006 */ 	lui	$a0,%hi(__osRunQueue)
/*     3b58:	01402825 */ 	or	$a1,$t2,$zero
/*     3b5c:	0c000f2e */ 	jal	__osEnqueueThread
/*     3b60:	24840938 */ 	addiu	$a0,$a0,%lo(__osRunQueue)
.L00003b64:
/*     3b64:	02400008 */ 	jr	$s2
/*     3b68:	00000000 */ 	nop
.L00003b6c:
/*     3b6c:	3c013000 */ 	lui	$at,0x3000
/*     3b70:	01014824 */ 	and	$t1,$t0,$at
/*     3b74:	00094f02 */ 	srl	$t1,$t1,0x1c
/*     3b78:	240a0001 */ 	addiu	$t2,$zero,0x1
/*     3b7c:	152affc2 */ 	bne	$t1,$t2,.L00003a88
/*     3b80:	00000000 */ 	nop
/*     3b84:	8f5b0118 */ 	lw	$k1,0x118($k0)
/*     3b88:	3c012000 */ 	lui	$at,0x2000
/*     3b8c:	24090001 */ 	addiu	$t1,$zero,0x1
/*     3b90:	0361d825 */ 	or	$k1,$k1,$at
/*     3b94:	af490018 */ 	sw	$t1,0x18($k0)
/*     3b98:	1000ffb5 */ 	b	.L00003a70
/*     3b9c:	af5b0118 */ 	sw	$k1,0x118($k0)
);

GLOBAL_ASM(
glabel __osEnqueueAndYield
/*     3ba0:	3c058006 */ 	lui	$a1,%hi(__osRunningThread)
/*     3ba4:	8ca50940 */ 	lw	$a1,%lo(__osRunningThread)($a1)
/*     3ba8:	40086000 */ 	mfc0	$t0,$12
/*     3bac:	8cbb0018 */ 	lw	$k1,0x18($a1)
/*     3bb0:	35080002 */ 	ori	$t0,$t0,0x2
/*     3bb4:	aca80118 */ 	sw	$t0,0x118($a1)
/*     3bb8:	fcb00098 */ 	sd	$s0,0x98($a1)
/*     3bbc:	fcb100a0 */ 	sd	$s1,0xa0($a1)
/*     3bc0:	fcb200a8 */ 	sd	$s2,0xa8($a1)
/*     3bc4:	fcb300b0 */ 	sd	$s3,0xb0($a1)
/*     3bc8:	fcb400b8 */ 	sd	$s4,0xb8($a1)
/*     3bcc:	fcb500c0 */ 	sd	$s5,0xc0($a1)
/*     3bd0:	fcb600c8 */ 	sd	$s6,0xc8($a1)
/*     3bd4:	fcb700d0 */ 	sd	$s7,0xd0($a1)
/*     3bd8:	fcbc00e8 */ 	sd	$gp,0xe8($a1)
/*     3bdc:	fcbd00f0 */ 	sd	$sp,0xf0($a1)
/*     3be0:	fcbe00f8 */ 	sd	$s8,0xf8($a1)
/*     3be4:	fcbf0100 */ 	sd	$ra,0x100($a1)
/*     3be8:	1360000f */ 	beqz	$k1,.L00003c28
/*     3bec:	acbf011c */ 	sw	$ra,0x11c($a1)
/*     3bf0:	445bf800 */ 	cfc1	$k1,$31
/*     3bf4:	f4b401d0 */ 	sdc1	$f20,0x1d0($a1)
/*     3bf8:	f4b501d8 */ 	sdc1	$f21,0x1d8($a1)
/*     3bfc:	f4b601e0 */ 	sdc1	$f22,0x1e0($a1)
/*     3c00:	f4b701e8 */ 	sdc1	$f23,0x1e8($a1)
/*     3c04:	f4b801f0 */ 	sdc1	$f24,0x1f0($a1)
/*     3c08:	f4b901f8 */ 	sdc1	$f25,0x1f8($a1)
/*     3c0c:	f4ba0200 */ 	sdc1	$f26,0x200($a1)
/*     3c10:	f4bb0208 */ 	sdc1	$f27,0x208($a1)
/*     3c14:	f4bc0210 */ 	sdc1	$f28,0x210($a1)
/*     3c18:	f4bd0218 */ 	sdc1	$f29,0x218($a1)
/*     3c1c:	f4be0220 */ 	sdc1	$f30,0x220($a1)
/*     3c20:	f4bf0228 */ 	sdc1	$f31,0x228($a1)
/*     3c24:	acbb012c */ 	sw	$k1,0x12c($a1)
.L00003c28:
/*     3c28:	8cbb0118 */ 	lw	$k1,0x118($a1)
/*     3c2c:	3369ff00 */ 	andi	$t1,$k1,0xff00
/*     3c30:	5120000e */ 	beqzl	$t1,.L00003c6c
/*     3c34:	3c1ba430 */ 	lui	$k1,0xa430
/*     3c38:	3c088006 */ 	lui	$t0,%hi(__osGlobalIntMask)
/*     3c3c:	2508cf70 */ 	addiu	$t0,$t0,%lo(__osGlobalIntMask)
/*     3c40:	8d080000 */ 	lw	$t0,0x0($t0)
/*     3c44:	2401ffff */ 	addiu	$at,$zero,-1
/*     3c48:	01014026 */ 	xor	$t0,$t0,$at
/*     3c4c:	3c01ffff */ 	lui	$at,0xffff
/*     3c50:	3108ff00 */ 	andi	$t0,$t0,0xff00
/*     3c54:	342100ff */ 	ori	$at,$at,0xff
/*     3c58:	01284825 */ 	or	$t1,$t1,$t0
/*     3c5c:	0361d824 */ 	and	$k1,$k1,$at
/*     3c60:	0369d825 */ 	or	$k1,$k1,$t1
/*     3c64:	acbb0118 */ 	sw	$k1,0x118($a1)
/*     3c68:	3c1ba430 */ 	lui	$k1,0xa430
.L00003c6c:
/*     3c6c:	8f7b000c */ 	lw	$k1,0xc($k1)
/*     3c70:	1360000b */ 	beqz	$k1,.L00003ca0
/*     3c74:	00000000 */ 	nop
/*     3c78:	3c1a8006 */ 	lui	$k0,%hi(__osGlobalIntMask)
/*     3c7c:	275acf70 */ 	addiu	$k0,$k0,%lo(__osGlobalIntMask)
/*     3c80:	8f5a0000 */ 	lw	$k0,0x0($k0)
/*     3c84:	8ca80128 */ 	lw	$t0,0x128($a1)
/*     3c88:	2401ffff */ 	addiu	$at,$zero,-1
/*     3c8c:	001ad402 */ 	srl	$k0,$k0,0x10
/*     3c90:	0341d026 */ 	xor	$k0,$k0,$at
/*     3c94:	335a003f */ 	andi	$k0,$k0,0x3f
/*     3c98:	0348d024 */ 	and	$k0,$k0,$t0
/*     3c9c:	037ad825 */ 	or	$k1,$k1,$k0
.L00003ca0:
/*     3ca0:	10800003 */ 	beqz	$a0,.L00003cb0
/*     3ca4:	acbb0128 */ 	sw	$k1,0x128($a1)
/*     3ca8:	0c000f2e */ 	jal	__osEnqueueThread
/*     3cac:	00000000 */ 	nop
.L00003cb0:
/*     3cb0:	08000f44 */ 	j	.L00003d10
/*     3cb4:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel __osEnqueueThread
/*     3cb8:	8c980000 */ 	lw	$t8,0x0($a0)
/*     3cbc:	8caf0004 */ 	lw	$t7,0x4($a1)
/*     3cc0:	0080c825 */ 	or	$t9,$a0,$zero
/*     3cc4:	8f0e0004 */ 	lw	$t6,0x4($t8)
/*     3cc8:	01cf082a */ 	slt	$at,$t6,$t7
/*     3ccc:	54200008 */ 	bnezl	$at,.L00003cf0
/*     3cd0:	8f380000 */ 	lw	$t8,0x0($t9)
/*     3cd4:	0300c825 */ 	or	$t9,$t8,$zero
.L00003cd8:
/*     3cd8:	8f180000 */ 	lw	$t8,0x0($t8)
/*     3cdc:	8f0e0004 */ 	lw	$t6,0x4($t8)
/*     3ce0:	01cf082a */ 	slt	$at,$t6,$t7
/*     3ce4:	5020fffc */ 	beqzl	$at,.L00003cd8
/*     3ce8:	0300c825 */ 	or	$t9,$t8,$zero
/*     3cec:	8f380000 */ 	lw	$t8,0x0($t9)
.L00003cf0:
/*     3cf0:	acb80000 */ 	sw	$t8,0x0($a1)
/*     3cf4:	af250000 */ 	sw	$a1,0x0($t9)
/*     3cf8:	03e00008 */ 	jr	$ra
/*     3cfc:	aca40008 */ 	sw	$a0,0x8($a1)
);

GLOBAL_ASM(
glabel __osPopThread
/*     3d00:	8c820000 */ 	lw	$v0,0x0($a0)
/*     3d04:	8c590000 */ 	lw	$t9,0x0($v0)
/*     3d08:	03e00008 */ 	jr	$ra
/*     3d0c:	ac990000 */ 	sw	$t9,0x0($a0)
);

GLOBAL_ASM(
glabel __osDispatchThread
.L00003d10:
/*     3d10:	3c048006 */ 	lui	$a0,%hi(__osRunQueue)
/*     3d14:	0c000f40 */ 	jal	__osPopThread
/*     3d18:	24840938 */ 	addiu	$a0,$a0,%lo(__osRunQueue)
/*     3d1c:	3c018006 */ 	lui	$at,%hi(__osRunningThread)
/*     3d20:	ac220940 */ 	sw	$v0,%lo(__osRunningThread)($at)
/*     3d24:	24080004 */ 	addiu	$t0,$zero,0x4
/*     3d28:	a4480010 */ 	sh	$t0,0x10($v0)
/*     3d2c:	0040d025 */ 	or	$k0,$v0,$zero
/*     3d30:	3c088006 */ 	lui	$t0,%hi(__osGlobalIntMask)
/*     3d34:	8f5b0118 */ 	lw	$k1,0x118($k0)
/*     3d38:	2508cf70 */ 	addiu	$t0,$t0,%lo(__osGlobalIntMask)
/*     3d3c:	8d080000 */ 	lw	$t0,0x0($t0)
/*     3d40:	3c01ffff */ 	lui	$at,0xffff
/*     3d44:	3369ff00 */ 	andi	$t1,$k1,0xff00
/*     3d48:	342100ff */ 	ori	$at,$at,0xff
/*     3d4c:	3108ff00 */ 	andi	$t0,$t0,0xff00
/*     3d50:	01284824 */ 	and	$t1,$t1,$t0
/*     3d54:	0361d824 */ 	and	$k1,$k1,$at
/*     3d58:	0369d825 */ 	or	$k1,$k1,$t1
/*     3d5c:	409b6000 */ 	mtc0	$k1,$12
/*     3d60:	df5b0108 */ 	ld	$k1,0x108($k0)
/*     3d64:	df410020 */ 	ld	$at,0x20($k0)
/*     3d68:	df420028 */ 	ld	$v0,0x28($k0)
/*     3d6c:	03600013 */ 	mtlo	$k1
/*     3d70:	df5b0110 */ 	ld	$k1,0x110($k0)
/*     3d74:	df430030 */ 	ld	$v1,0x30($k0)
/*     3d78:	df440038 */ 	ld	$a0,0x38($k0)
/*     3d7c:	df450040 */ 	ld	$a1,0x40($k0)
/*     3d80:	df460048 */ 	ld	$a2,0x48($k0)
/*     3d84:	df470050 */ 	ld	$a3,0x50($k0)
/*     3d88:	df480058 */ 	ld	$t0,0x58($k0)
/*     3d8c:	df490060 */ 	ld	$t1,0x60($k0)
/*     3d90:	df4a0068 */ 	ld	$t2,0x68($k0)
/*     3d94:	df4b0070 */ 	ld	$t3,0x70($k0)
/*     3d98:	df4c0078 */ 	ld	$t4,0x78($k0)
/*     3d9c:	df4d0080 */ 	ld	$t5,0x80($k0)
/*     3da0:	df4e0088 */ 	ld	$t6,0x88($k0)
/*     3da4:	df4f0090 */ 	ld	$t7,0x90($k0)
/*     3da8:	df500098 */ 	ld	$s0,0x98($k0)
/*     3dac:	df5100a0 */ 	ld	$s1,0xa0($k0)
/*     3db0:	df5200a8 */ 	ld	$s2,0xa8($k0)
/*     3db4:	df5300b0 */ 	ld	$s3,0xb0($k0)
/*     3db8:	df5400b8 */ 	ld	$s4,0xb8($k0)
/*     3dbc:	df5500c0 */ 	ld	$s5,0xc0($k0)
/*     3dc0:	df5600c8 */ 	ld	$s6,0xc8($k0)
/*     3dc4:	df5700d0 */ 	ld	$s7,0xd0($k0)
/*     3dc8:	df5800d8 */ 	ld	$t8,0xd8($k0)
/*     3dcc:	df5900e0 */ 	ld	$t9,0xe0($k0)
/*     3dd0:	df5c00e8 */ 	ld	$gp,0xe8($k0)
/*     3dd4:	03600011 */ 	mthi	$k1
/*     3dd8:	df5d00f0 */ 	ld	$sp,0xf0($k0)
/*     3ddc:	df5e00f8 */ 	ld	$s8,0xf8($k0)
/*     3de0:	df5f0100 */ 	ld	$ra,0x100($k0)
/*     3de4:	8f5b011c */ 	lw	$k1,0x11c($k0)
/*     3de8:	409b7000 */ 	mtc0	$k1,$14
/*     3dec:	8f5b0018 */ 	lw	$k1,0x18($k0)
/*     3df0:	13600023 */ 	beqz	$k1,.L00003e80
/*     3df4:	00000000 */ 	nop
/*     3df8:	8f5b012c */ 	lw	$k1,0x12c($k0)
/*     3dfc:	44dbf800 */ 	ctc1	$k1,$31
/*     3e00:	d7400130 */ 	ldc1	$f0,0x130($k0)
/*     3e04:	d7410138 */ 	ldc1	$f1,0x138($k0)
/*     3e08:	d7420140 */ 	ldc1	$f2,0x140($k0)
/*     3e0c:	d7430148 */ 	ldc1	$f3,0x148($k0)
/*     3e10:	d7440150 */ 	ldc1	$f4,0x150($k0)
/*     3e14:	d7450158 */ 	ldc1	$f5,0x158($k0)
/*     3e18:	d7460160 */ 	ldc1	$f6,0x160($k0)
/*     3e1c:	d7470168 */ 	ldc1	$f7,0x168($k0)
/*     3e20:	d7480170 */ 	ldc1	$f8,0x170($k0)
/*     3e24:	d7490178 */ 	ldc1	$f9,0x178($k0)
/*     3e28:	d74a0180 */ 	ldc1	$f10,0x180($k0)
/*     3e2c:	d74b0188 */ 	ldc1	$f11,0x188($k0)
/*     3e30:	d74c0190 */ 	ldc1	$f12,0x190($k0)
/*     3e34:	d74d0198 */ 	ldc1	$f13,0x198($k0)
/*     3e38:	d74e01a0 */ 	ldc1	$f14,0x1a0($k0)
/*     3e3c:	d74f01a8 */ 	ldc1	$f15,0x1a8($k0)
/*     3e40:	d75001b0 */ 	ldc1	$f16,0x1b0($k0)
/*     3e44:	d75101b8 */ 	ldc1	$f17,0x1b8($k0)
/*     3e48:	d75201c0 */ 	ldc1	$f18,0x1c0($k0)
/*     3e4c:	d75301c8 */ 	ldc1	$f19,0x1c8($k0)
/*     3e50:	d75401d0 */ 	ldc1	$f20,0x1d0($k0)
/*     3e54:	d75501d8 */ 	ldc1	$f21,0x1d8($k0)
/*     3e58:	d75601e0 */ 	ldc1	$f22,0x1e0($k0)
/*     3e5c:	d75701e8 */ 	ldc1	$f23,0x1e8($k0)
/*     3e60:	d75801f0 */ 	ldc1	$f24,0x1f0($k0)
/*     3e64:	d75901f8 */ 	ldc1	$f25,0x1f8($k0)
/*     3e68:	d75a0200 */ 	ldc1	$f26,0x200($k0)
/*     3e6c:	d75b0208 */ 	ldc1	$f27,0x208($k0)
/*     3e70:	d75c0210 */ 	ldc1	$f28,0x210($k0)
/*     3e74:	d75d0218 */ 	ldc1	$f29,0x218($k0)
/*     3e78:	d75e0220 */ 	ldc1	$f30,0x220($k0)
/*     3e7c:	d75f0228 */ 	ldc1	$f31,0x228($k0)
.L00003e80:
/*     3e80:	8f5b0128 */ 	lw	$k1,0x128($k0)
/*     3e84:	3c1a8006 */ 	lui	$k0,%hi(__osGlobalIntMask)
/*     3e88:	275acf70 */ 	addiu	$k0,$k0,%lo(__osGlobalIntMask)
/*     3e8c:	8f5a0000 */ 	lw	$k0,0x0($k0)
/*     3e90:	001ad402 */ 	srl	$k0,$k0,0x10
/*     3e94:	037ad824 */ 	and	$k1,$k1,$k0
/*     3e98:	001bd840 */ 	sll	$k1,$k1,0x1
/*     3e9c:	3c1a7006 */ 	lui	$k0,%hi(var70059e30)
/*     3ea0:	275a9e30 */ 	addiu	$k0,$k0,%lo(var70059e30)
/*     3ea4:	037ad821 */ 	addu	$k1,$k1,$k0
/*     3ea8:	977b0000 */ 	lhu	$k1,0x0($k1)
/*     3eac:	3c1aa430 */ 	lui	$k0,0xa430
/*     3eb0:	275a000c */ 	addiu	$k0,$k0,0xc
/*     3eb4:	af5b0000 */ 	sw	$k1,0x0($k0)
/*     3eb8:	00000000 */ 	nop
/*     3ebc:	00000000 */ 	nop
/*     3ec0:	00000000 */ 	nop
/*     3ec4:	00000000 */ 	nop
/*     3ec8:	42000018 */ 	eret
);

GLOBAL_ASM(
glabel __osCleanupThread
/*     3ecc:	0c012894 */ 	jal	osDestroyThread
/*     3ed0:	00002025 */ 	or	$a0,$zero,$zero
/*     3ed4:	00000000 */ 	nop
/*     3ed8:	00000000 */ 	nop
/*     3edc:	00000000 */ 	nop
);
