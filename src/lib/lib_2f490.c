#include <ultra64.h>
#include "constants.h"
#include "types.h"
#include "data.h"
#include "bss.h"
#include "lib/memory.h"

u8 var8009ad70[0xb00];

u16 *var8005f040 = NULL;
u16 *var8005f044 = NULL;
u32 var8005f048 = 0x00000000;
u32 var8005f04c = 0x00000000;
u32 var8005f050 = 0x00000000;
u32 var8005f054 = 0x00000000;
u32 var8005f058 = 0x00000001;
u32 var8005f05c = 0x00000002;
u32 var8005f060 = 0x00000000;
u32 var8005f064 = 0x00000000;
u32 var8005f068 = 0x00000000;
u32 var8005f06c = 0x00001000;
u32 var8005f070 = 0x00000000;
u32 var8005f074 = 0x00000800;
u32 var8005f078 = (u32) &var8009a970;
u32 var8005f07c = 0x00000400;
u32 var8005f080 = 0x00000000;
u32 var8005f084 = 0x00000000;
u32 var8005f088 = 0x00000000;
u32 var8005f08c = 0x00000000;
u32 var8005f090 = 0x00000000;
u32 var8005f094 = 0x00000000;
u32 var8005f098 = 0x00000000;
u32 var8005f09c = 0x00000000;
u32 var8005f0a0 = 0x00000000;
u32 var8005f0a4 = 0x00000000;
u32 var8005f0a8 = 0x00000000;
u32 var8005f0ac = 0x00000000;
u32 var8005f0b0 = 0x00000000;
u32 var8005f0b4 = 0x00000000;
u32 var8005f0b8 = 0x00000001;
u32 var8005f0bc = 0x00000002;
u32 var8005f0c0 = 0x00000000;
u32 var8005f0c4 = 0x00000000;
u32 var8005f0c8 = 0x00000000;
u32 var8005f0cc = 0x00001000;
u32 var8005f0d0 = 0x00000000;
u32 var8005f0d4 = 0x00000800;
u32 var8005f0d8 = (u32) &var8009a970;
u32 var8005f0dc = 0x00000400;
u32 var8005f0e0 = 0x00000000;
u32 var8005f0e4 = 0x00000000;
u32 var8005f0e8 = 0x00000000;
u32 var8005f0ec = 0x00000000;
u32 var8005f0f0 = 0x00000000;
u32 var8005f0f4 = 0x00000000;
u32 var8005f0f8 = 0x00000000;
u32 var8005f0fc = 0x00000000;
u32 var8005f100 = 0x00000000;
u32 var8005f104 = 0x00000000;
u32 var8005f108 = (u32) &var8005f048;

GLOBAL_ASM(
glabel func0002f490
/*    2f490:	8fa80010 */ 	lw	$t0,0x10($sp)
/*    2f494:	8fa90014 */ 	lw	$t1,0x14($sp)
/*    2f498:	8faa0018 */ 	lw	$t2,0x18($sp)
/*    2f49c:	8fab001c */ 	lw	$t3,0x1c($sp)
/*    2f4a0:	8fac0020 */ 	lw	$t4,0x20($sp)
/*    2f4a4:	848d0000 */ 	lh	$t5,0x0($a0)
/*    2f4a8:	848e0002 */ 	lh	$t6,0x2($a0)
/*    2f4ac:	848f0004 */ 	lh	$t7,0x4($a0)
/*    2f4b0:	448d0000 */ 	mtc1	$t5,$f0
/*    2f4b4:	448e0800 */ 	mtc1	$t6,$f1
/*    2f4b8:	448f1000 */ 	mtc1	$t7,$f2
/*    2f4bc:	46800020 */ 	cvt.s.w	$f0,$f0
/*    2f4c0:	46800860 */ 	cvt.s.w	$f1,$f1
/*    2f4c4:	468010a0 */ 	cvt.s.w	$f2,$f2
/*    2f4c8:	84ad0000 */ 	lh	$t5,0x0($a1)
/*    2f4cc:	84ae0002 */ 	lh	$t6,0x2($a1)
/*    2f4d0:	84af0004 */ 	lh	$t7,0x4($a1)
/*    2f4d4:	448d6000 */ 	mtc1	$t5,$f12
/*    2f4d8:	448e6800 */ 	mtc1	$t6,$f13
/*    2f4dc:	448f7000 */ 	mtc1	$t7,$f14
/*    2f4e0:	46806320 */ 	cvt.s.w	$f12,$f12
/*    2f4e4:	46806b60 */ 	cvt.s.w	$f13,$f13
/*    2f4e8:	468073a0 */ 	cvt.s.w	$f14,$f14
/*    2f4ec:	84cd0000 */ 	lh	$t5,0x0($a2)
/*    2f4f0:	84ce0002 */ 	lh	$t6,0x2($a2)
/*    2f4f4:	84cf0004 */ 	lh	$t7,0x4($a2)
/*    2f4f8:	448d7800 */ 	mtc1	$t5,$f15
/*    2f4fc:	448e8000 */ 	mtc1	$t6,$f16
/*    2f500:	448f8800 */ 	mtc1	$t7,$f17
/*    2f504:	46807be0 */ 	cvt.s.w	$f15,$f15
/*    2f508:	46808420 */ 	cvt.s.w	$f16,$f16
/*    2f50c:	46808c60 */ 	cvt.s.w	$f17,$f17
/*    2f510:	460060c1 */ 	sub.s	$f3,$f12,$f0
/*    2f514:	46016901 */ 	sub.s	$f4,$f13,$f1
/*    2f518:	46027141 */ 	sub.s	$f5,$f14,$f2
/*    2f51c:	460c7981 */ 	sub.s	$f6,$f15,$f12
/*    2f520:	460d81c1 */ 	sub.s	$f7,$f16,$f13
/*    2f524:	460e8a01 */ 	sub.s	$f8,$f17,$f14
/*    2f528:	46007a41 */ 	sub.s	$f9,$f15,$f0
/*    2f52c:	46018281 */ 	sub.s	$f10,$f16,$f1
/*    2f530:	10e00007 */ 	beqz	$a3,.L0002f550
/*    2f534:	46028ac1 */ 	sub.s	$f11,$f17,$f2
/*    2f538:	c4ec0000 */ 	lwc1	$f12,0x0($a3)
/*    2f53c:	c4ed0004 */ 	lwc1	$f13,0x4($a3)
/*    2f540:	c4ee0008 */ 	lwc1	$f14,0x8($a3)
/*    2f544:	460c0000 */ 	add.s	$f0,$f0,$f12
/*    2f548:	460d0840 */ 	add.s	$f1,$f1,$f13
/*    2f54c:	460e1080 */ 	add.s	$f2,$f2,$f14
.L0002f550:
/*    2f550:	3c0d7003 */ 	lui	$t5,%hi(func0002f5d8)
/*    2f554:	25adf5d8 */ 	addiu	$t5,$t5,%lo(func0002f5d8)
/*    2f558:	01a00008 */ 	jr	$t5
/*    2f55c:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel func0002f560
/*    2f560:	8fa80010 */ 	lw	$t0,0x10($sp)
/*    2f564:	8fa90014 */ 	lw	$t1,0x14($sp)
/*    2f568:	8faa0018 */ 	lw	$t2,0x18($sp)
/*    2f56c:	8fab001c */ 	lw	$t3,0x1c($sp)
/*    2f570:	8fac0020 */ 	lw	$t4,0x20($sp)
/*    2f574:	c4800000 */ 	lwc1	$f0,0x0($a0)
/*    2f578:	c4810004 */ 	lwc1	$f1,0x4($a0)
/*    2f57c:	c4820008 */ 	lwc1	$f2,0x8($a0)
/*    2f580:	c4ac0000 */ 	lwc1	$f12,0x0($a1)
/*    2f584:	c4ad0004 */ 	lwc1	$f13,0x4($a1)
/*    2f588:	c4ae0008 */ 	lwc1	$f14,0x8($a1)
/*    2f58c:	c4cf0000 */ 	lwc1	$f15,0x0($a2)
/*    2f590:	c4d00004 */ 	lwc1	$f16,0x4($a2)
/*    2f594:	c4d10008 */ 	lwc1	$f17,0x8($a2)
/*    2f598:	460060c1 */ 	sub.s	$f3,$f12,$f0
/*    2f59c:	46016901 */ 	sub.s	$f4,$f13,$f1
/*    2f5a0:	46027141 */ 	sub.s	$f5,$f14,$f2
/*    2f5a4:	460c7981 */ 	sub.s	$f6,$f15,$f12
/*    2f5a8:	460d81c1 */ 	sub.s	$f7,$f16,$f13
/*    2f5ac:	460e8a01 */ 	sub.s	$f8,$f17,$f14
/*    2f5b0:	46007a41 */ 	sub.s	$f9,$f15,$f0
/*    2f5b4:	46018281 */ 	sub.s	$f10,$f16,$f1
/*    2f5b8:	10e00007 */ 	beqz	$a3,.L0002f5d8
/*    2f5bc:	46028ac1 */ 	sub.s	$f11,$f17,$f2
/*    2f5c0:	c4ec0000 */ 	lwc1	$f12,0x0($a3)
/*    2f5c4:	c4ed0004 */ 	lwc1	$f13,0x4($a3)
/*    2f5c8:	c4ee0008 */ 	lwc1	$f14,0x8($a3)
/*    2f5cc:	460c0000 */ 	add.s	$f0,$f0,$f12
/*    2f5d0:	460d0840 */ 	add.s	$f1,$f1,$f13
/*    2f5d4:	460e1080 */ 	add.s	$f2,$f2,$f14
.L0002f5d8:
);

GLOBAL_ASM(
glabel func0002f5d8
/*    2f5d8:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*    2f5dc:	e7b40000 */ 	swc1	$f20,0x0($sp)
/*    2f5e0:	e7b50004 */ 	swc1	$f21,0x4($sp)
/*    2f5e4:	e7b60008 */ 	swc1	$f22,0x8($sp)
/*    2f5e8:	e7b7000c */ 	swc1	$f23,0xc($sp)
/*    2f5ec:	e7b80010 */ 	swc1	$f24,0x10($sp)
/*    2f5f0:	e7b90014 */ 	swc1	$f25,0x14($sp)
/*    2f5f4:	46082302 */ 	mul.s	$f12,$f4,$f8
/*    2f5f8:	e7b90014 */ 	swc1	$f25,0x14($sp)
/*    2f5fc:	46053b42 */ 	mul.s	$f13,$f7,$f5
/*    2f600:	e7ba0018 */ 	swc1	$f26,0x18($sp)
/*    2f604:	46062b82 */ 	mul.s	$f14,$f5,$f6
/*    2f608:	460d6301 */ 	sub.s	$f12,$f12,$f13
/*    2f60c:	460343c2 */ 	mul.s	$f15,$f8,$f3
/*    2f610:	e7bb001c */ 	swc1	$f27,0x1c($sp)
/*    2f614:	46071c02 */ 	mul.s	$f16,$f3,$f7
/*    2f618:	460f7341 */ 	sub.s	$f13,$f14,$f15
/*    2f61c:	46043382 */ 	mul.s	$f14,$f6,$f4
/*    2f620:	440ee000 */ 	mfc1	$t6,$f28
/*    2f624:	460e8381 */ 	sub.s	$f14,$f16,$f14
/*    2f628:	460063c2 */ 	mul.s	$f15,$f12,$f0
/*    2f62c:	440fe800 */ 	mfc1	$t7,$f29
/*    2f630:	46016c02 */ 	mul.s	$f16,$f13,$f1
/*    2f634:	4418f000 */ 	mfc1	$t8,$f30
/*    2f638:	46027442 */ 	mul.s	$f17,$f14,$f2
/*    2f63c:	46107bc0 */ 	add.s	$f15,$f15,$f16
/*    2f640:	4419f800 */ 	mfc1	$t9,$f31
/*    2f644:	46117bc0 */ 	add.s	$f15,$f15,$f17
/*    2f648:	c5500000 */ 	lwc1	$f16,0x0($t2)
/*    2f64c:	c5510004 */ 	lwc1	$f17,0x4($t2)
/*    2f650:	461064c2 */ 	mul.s	$f19,$f12,$f16
/*    2f654:	c5520008 */ 	lwc1	$f18,0x8($t2)
/*    2f658:	46116d02 */ 	mul.s	$f20,$f13,$f17
/*    2f65c:	46149cc0 */ 	add.s	$f19,$f19,$f20
/*    2f660:	46127502 */ 	mul.s	$f20,$f14,$f18
/*    2f664:	4480f800 */ 	mtc1	$zero,$f31
/*    2f668:	46149cc0 */ 	add.s	$f19,$f19,$f20
/*    2f66c:	461f9832 */ 	c.eq.s	$f19,$f31
/*    2f670:	4501007c */ 	bc1t	.L0002f864
/*    2f674:	20020000 */ 	addi	$v0,$zero,0x0
/*    2f678:	c5340000 */ 	lwc1	$f20,0x0($t1)
/*    2f67c:	c5350004 */ 	lwc1	$f21,0x4($t1)
/*    2f680:	461465c2 */ 	mul.s	$f23,$f12,$f20
/*    2f684:	c5360008 */ 	lwc1	$f22,0x8($t1)
/*    2f688:	46156e02 */ 	mul.s	$f24,$f13,$f21
/*    2f68c:	46177dc1 */ 	sub.s	$f23,$f15,$f23
/*    2f690:	46167642 */ 	mul.s	$f25,$f14,$f22
/*    2f694:	4618bdc1 */ 	sub.s	$f23,$f23,$f24
/*    2f698:	4619bdc1 */ 	sub.s	$f23,$f23,$f25
/*    2f69c:	4613bcc3 */ 	div.s	$f19,$f23,$f19
/*    2f6a0:	46109dc2 */ 	mul.s	$f23,$f19,$f16
/*    2f6a4:	00000000 */ 	nop
/*    2f6a8:	46119e02 */ 	mul.s	$f24,$f19,$f17
/*    2f6ac:	4617a5c0 */ 	add.s	$f23,$f20,$f23
/*    2f6b0:	46129e42 */ 	mul.s	$f25,$f19,$f18
/*    2f6b4:	4618ae00 */ 	add.s	$f24,$f21,$f24
/*    2f6b8:	4619b640 */ 	add.s	$f25,$f22,$f25
/*    2f6bc:	4614be81 */ 	sub.s	$f26,$f23,$f20
/*    2f6c0:	461a8682 */ 	mul.s	$f26,$f16,$f26
/*    2f6c4:	4615c6c1 */ 	sub.s	$f27,$f24,$f21
/*    2f6c8:	461b8ec2 */ 	mul.s	$f27,$f17,$f27
/*    2f6cc:	4616cf01 */ 	sub.s	$f28,$f25,$f22
/*    2f6d0:	461bd680 */ 	add.s	$f26,$f26,$f27
/*    2f6d4:	461c96c2 */ 	mul.s	$f27,$f18,$f28
/*    2f6d8:	461bd680 */ 	add.s	$f26,$f26,$f27
/*    2f6dc:	461af83c */ 	c.lt.s	$f31,$f26
/*    2f6e0:	45000003 */ 	bc1f	.L0002f6f0
/*    2f6e4:	00000000 */ 	nop
/*    2f6e8:	1000005e */ 	b	.L0002f864
/*    2f6ec:	20020000 */ 	addi	$v0,$zero,0x0
.L0002f6f0:
/*    2f6f0:	c5140000 */ 	lwc1	$f20,0x0($t0)
/*    2f6f4:	4614be81 */ 	sub.s	$f26,$f23,$f20
/*    2f6f8:	c5150004 */ 	lwc1	$f21,0x4($t0)
/*    2f6fc:	461a8682 */ 	mul.s	$f26,$f16,$f26
/*    2f700:	4615c6c1 */ 	sub.s	$f27,$f24,$f21
/*    2f704:	c5160008 */ 	lwc1	$f22,0x8($t0)
/*    2f708:	461b8ec2 */ 	mul.s	$f27,$f17,$f27
/*    2f70c:	4616cf01 */ 	sub.s	$f28,$f25,$f22
/*    2f710:	461bd680 */ 	add.s	$f26,$f26,$f27
/*    2f714:	461c96c2 */ 	mul.s	$f27,$f18,$f28
/*    2f718:	461bd680 */ 	add.s	$f26,$f26,$f27
/*    2f71c:	461fd03c */ 	c.lt.s	$f26,$f31
/*    2f720:	45000003 */ 	bc1f	.L0002f730
/*    2f724:	00000000 */ 	nop
/*    2f728:	1000004e */ 	b	.L0002f864
/*    2f72c:	20020000 */ 	addi	$v0,$zero,0x0
.L0002f730:
/*    2f730:	4600b801 */ 	sub.s	$f0,$f23,$f0
/*    2f734:	4601c041 */ 	sub.s	$f1,$f24,$f1
/*    2f738:	4602c881 */ 	sub.s	$f2,$f25,$f2
/*    2f73c:	46043682 */ 	mul.s	$f26,$f6,$f4
/*    2f740:	00000000 */ 	nop
/*    2f744:	46071ec2 */ 	mul.s	$f27,$f3,$f7
/*    2f748:	461bd681 */ 	sub.s	$f26,$f26,$f27
/*    2f74c:	461fd032 */ 	c.eq.s	$f26,$f31
/*    2f750:	45010007 */ 	bc1t	.L0002f770
/*    2f754:	00000000 */ 	nop
/*    2f758:	460406c2 */ 	mul.s	$f27,$f0,$f4
/*    2f75c:	00000000 */ 	nop
/*    2f760:	46030f02 */ 	mul.s	$f28,$f1,$f3
/*    2f764:	461cdec1 */ 	sub.s	$f27,$f27,$f28
/*    2f768:	10000017 */ 	b	.L0002f7c8
/*    2f76c:	461adec3 */ 	div.s	$f27,$f27,$f26
.L0002f770:
/*    2f770:	46053e82 */ 	mul.s	$f26,$f7,$f5
/*    2f774:	00000000 */ 	nop
/*    2f778:	460826c2 */ 	mul.s	$f27,$f4,$f8
/*    2f77c:	461bd681 */ 	sub.s	$f26,$f26,$f27
/*    2f780:	461fd032 */ 	c.eq.s	$f26,$f31
/*    2f784:	45010007 */ 	bc1t	.L0002f7a4
/*    2f788:	00000000 */ 	nop
/*    2f78c:	46050ec2 */ 	mul.s	$f27,$f1,$f5
/*    2f790:	00000000 */ 	nop
/*    2f794:	46041702 */ 	mul.s	$f28,$f2,$f4
/*    2f798:	461cdec1 */ 	sub.s	$f27,$f27,$f28
/*    2f79c:	1000000a */ 	b	.L0002f7c8
/*    2f7a0:	461adec3 */ 	div.s	$f27,$f27,$f26
.L0002f7a4:
/*    2f7a4:	46034682 */ 	mul.s	$f26,$f8,$f3
/*    2f7a8:	00000000 */ 	nop
/*    2f7ac:	46062ec2 */ 	mul.s	$f27,$f5,$f6
/*    2f7b0:	461bd681 */ 	sub.s	$f26,$f26,$f27
/*    2f7b4:	460316c2 */ 	mul.s	$f27,$f2,$f3
/*    2f7b8:	00000000 */ 	nop
/*    2f7bc:	46050702 */ 	mul.s	$f28,$f0,$f5
/*    2f7c0:	461cdec1 */ 	sub.s	$f27,$f27,$f28
/*    2f7c4:	461adec3 */ 	div.s	$f27,$f27,$f26
.L0002f7c8:
/*    2f7c8:	461fd83c */ 	c.lt.s	$f27,$f31
/*    2f7cc:	45010025 */ 	bc1t	.L0002f864
/*    2f7d0:	20020000 */ 	addi	$v0,$zero,0x0
/*    2f7d4:	461f1832 */ 	c.eq.s	$f3,$f31
/*    2f7d8:	45010005 */ 	bc1t	.L0002f7f0
/*    2f7dc:	00000000 */ 	nop
/*    2f7e0:	4609df02 */ 	mul.s	$f28,$f27,$f9
/*    2f7e4:	461c0701 */ 	sub.s	$f28,$f0,$f28
/*    2f7e8:	1000000b */ 	b	.L0002f818
/*    2f7ec:	4603e703 */ 	div.s	$f28,$f28,$f3
.L0002f7f0:
/*    2f7f0:	461f2032 */ 	c.eq.s	$f4,$f31
/*    2f7f4:	45010005 */ 	bc1t	.L0002f80c
/*    2f7f8:	00000000 */ 	nop
/*    2f7fc:	460adf02 */ 	mul.s	$f28,$f27,$f10
/*    2f800:	461c0f01 */ 	sub.s	$f28,$f1,$f28
/*    2f804:	10000004 */ 	b	.L0002f818
/*    2f808:	4604e703 */ 	div.s	$f28,$f28,$f4
.L0002f80c:
/*    2f80c:	460bdf02 */ 	mul.s	$f28,$f27,$f11
/*    2f810:	461c1701 */ 	sub.s	$f28,$f2,$f28
/*    2f814:	4605e703 */ 	div.s	$f28,$f28,$f5
.L0002f818:
/*    2f818:	461fe03c */ 	c.lt.s	$f28,$f31
/*    2f81c:	45010011 */ 	bc1t	.L0002f864
/*    2f820:	20020000 */ 	addi	$v0,$zero,0x0
/*    2f824:	3c013f80 */ 	lui	$at,0x3f80
/*    2f828:	4481e800 */ 	mtc1	$at,$f29
/*    2f82c:	461be6c0 */ 	add.s	$f27,$f28,$f27
/*    2f830:	461dd83e */ 	c.le.s	$f27,$f29
/*    2f834:	4500000b */ 	bc1f	.L0002f864
/*    2f838:	20020000 */ 	addi	$v0,$zero,0x0
/*    2f83c:	11600004 */ 	beqz	$t3,.L0002f850
/*    2f840:	20020001 */ 	addi	$v0,$zero,0x1
/*    2f844:	e5770000 */ 	swc1	$f23,0x0($t3)
/*    2f848:	e5780004 */ 	swc1	$f24,0x4($t3)
/*    2f84c:	e5790008 */ 	swc1	$f25,0x8($t3)
.L0002f850:
/*    2f850:	11800004 */ 	beqz	$t4,.L0002f864
/*    2f854:	00000000 */ 	nop
/*    2f858:	e58c0000 */ 	swc1	$f12,0x0($t4)
/*    2f85c:	e58d0004 */ 	swc1	$f13,0x4($t4)
/*    2f860:	e58e0008 */ 	swc1	$f14,0x8($t4)
.L0002f864:
/*    2f864:	c7b40000 */ 	lwc1	$f20,0x0($sp)
/*    2f868:	c7b50004 */ 	lwc1	$f21,0x4($sp)
/*    2f86c:	c7b60008 */ 	lwc1	$f22,0x8($sp)
/*    2f870:	c7b7000c */ 	lwc1	$f23,0xc($sp)
/*    2f874:	c7b80010 */ 	lwc1	$f24,0x10($sp)
/*    2f878:	c7b90014 */ 	lwc1	$f25,0x14($sp)
/*    2f87c:	c7ba0018 */ 	lwc1	$f26,0x18($sp)
/*    2f880:	c7bb001c */ 	lwc1	$f27,0x1c($sp)
/*    2f884:	448ee000 */ 	mtc1	$t6,$f28
/*    2f888:	448fe800 */ 	mtc1	$t7,$f29
/*    2f88c:	4498f000 */ 	mtc1	$t8,$f30
/*    2f890:	4499f800 */ 	mtc1	$t9,$f31
/*    2f894:	03e00008 */ 	jr	$ra
/*    2f898:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*    2f89c:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel func0002f8a0
/*    2f8a0:	3c0e8009 */ 	lui	$t6,%hi(g_Is4Mb)
/*    2f8a4:	91ce0af0 */ 	lbu	$t6,%lo(g_Is4Mb)($t6)
/*    2f8a8:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*    2f8ac:	24010001 */ 	addiu	$at,$zero,0x1
/*    2f8b0:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    2f8b4:	15c10002 */ 	bne	$t6,$at,.L0002f8c0
/*    2f8b8:	3c040001 */ 	lui	$a0,0x1
/*    2f8bc:	34048000 */ 	dli	$a0,0x8000
.L0002f8c0:
/*    2f8c0:	24050006 */ 	addiu	$a1,$zero,0x6
/*    2f8c4:	0c0048f2 */ 	jal	malloc
/*    2f8c8:	afa4001c */ 	sw	$a0,0x1c($sp)
/*    2f8cc:	8fa4001c */ 	lw	$a0,0x1c($sp)
/*    2f8d0:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    2f8d4:	3c038006 */ 	lui	$v1,%hi(var8005f044)
/*    2f8d8:	2463f044 */ 	addiu	$v1,$v1,%lo(var8005f044)
/*    2f8dc:	ac620000 */ 	sw	$v0,0x0($v1)
/*    2f8e0:	3c018006 */ 	lui	$at,%hi(var8005f040)
/*    2f8e4:	0044c021 */ 	addu	$t8,$v0,$a0
/*    2f8e8:	ac38f040 */ 	sw	$t8,%lo(var8005f040)($at)
/*    2f8ec:	03e00008 */ 	jr	$ra
/*    2f8f0:	27bd0020 */ 	addiu	$sp,$sp,0x20
);

GLOBAL_ASM(
glabel func0002f8f4
/*    2f8f4:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*    2f8f8:	3c038006 */ 	lui	$v1,%hi(var8005f108)
/*    2f8fc:	2463f108 */ 	addiu	$v1,$v1,%lo(var8005f108)
/*    2f900:	afa60028 */ 	sw	$a2,0x28($sp)
/*    2f904:	8c660000 */ 	lw	$a2,0x0($v1)
/*    2f908:	3c028006 */ 	lui	$v0,%hi(rspbootTextStart)
/*    2f90c:	3c0e8006 */ 	lui	$t6,%hi(rspbootTextEnd)
/*    2f910:	24429fe0 */ 	addiu	$v0,$v0,%lo(rspbootTextStart)
/*    2f914:	25cea0b0 */ 	addiu	$t6,$t6,%lo(rspbootTextEnd)
/*    2f918:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    2f91c:	01c27823 */ 	subu	$t7,$t6,$v0
/*    2f920:	acc20018 */ 	sw	$v0,0x18($a2)
/*    2f924:	3c188006 */ 	lui	$t8,%hi(gspTextStart)
/*    2f928:	3c198009 */ 	lui	$t9,%hi(gspDataStart)
/*    2f92c:	accf001c */ 	sw	$t7,0x1c($a2)
/*    2f930:	24c20010 */ 	addiu	$v0,$a2,0x10
/*    2f934:	2718a0b0 */ 	addiu	$t8,$t8,%lo(gspTextStart)
/*    2f938:	27399ad0 */ 	addiu	$t9,$t9,%lo(gspDataStart)
/*    2f93c:	ac580010 */ 	sw	$t8,0x10($v0)
/*    2f940:	ac590018 */ 	sw	$t9,0x18($v0)
/*    2f944:	3c088006 */ 	lui	$t0,%hi(var8005f044)
/*    2f948:	8d08f044 */ 	lw	$t0,%lo(var8005f044)($t0)
/*    2f94c:	3c098006 */ 	lui	$t1,%hi(var8005f040)
/*    2f950:	00a45023 */ 	subu	$t2,$a1,$a0
/*    2f954:	ac480028 */ 	sw	$t0,0x28($v0)
/*    2f958:	8d29f040 */ 	lw	$t1,%lo(var8005f040)($t1)
/*    2f95c:	000a58c3 */ 	sra	$t3,$t2,0x3
/*    2f960:	3c0d800a */ 	lui	$t5,%hi(var8009ad70)
/*    2f964:	000b60c0 */ 	sll	$t4,$t3,0x3
/*    2f968:	25adad70 */ 	addiu	$t5,$t5,%lo(var8009ad70)
/*    2f96c:	240e0b00 */ 	addiu	$t6,$zero,0xb00
/*    2f970:	ac440030 */ 	sw	$a0,0x30($v0)
/*    2f974:	ac4c0034 */ 	sw	$t4,0x34($v0)
/*    2f978:	ac4d0038 */ 	sw	$t5,0x38($v0)
/*    2f97c:	ac4e003c */ 	sw	$t6,0x3c($v0)
/*    2f980:	ac49002c */ 	sw	$t1,0x2c($v0)
/*    2f984:	3c188009 */ 	lui	$t8,%hi(var8008db30)
/*    2f988:	240f0063 */ 	addiu	$t7,$zero,0x63
/*    2f98c:	2718db30 */ 	addiu	$t8,$t8,%lo(var8008db30)
/*    2f990:	acc00000 */ 	sw	$zero,0x0($a2)
/*    2f994:	accf0008 */ 	sw	$t7,0x8($a2)
/*    2f998:	acd80050 */ 	sw	$t8,0x50($a2)
/*    2f99c:	acc70054 */ 	sw	$a3,0x54($a2)
/*    2f9a0:	8c790000 */ 	lw	$t9,0x0($v1)
/*    2f9a4:	8f280058 */ 	lw	$t0,0x58($t9)
/*    2f9a8:	acc8000c */ 	sw	$t0,0xc($a2)
/*    2f9ac:	0c012048 */ 	jal	osWritebackDCacheAll
/*    2f9b0:	afa6001c */ 	sw	$a2,0x1c($sp)
/*    2f9b4:	3c048009 */ 	lui	$a0,%hi(g_SchedThread)
/*    2f9b8:	8fa5001c */ 	lw	$a1,0x1c($sp)
/*    2f9bc:	0c0007ea */ 	jal	__scHandleRetraceViaPri
/*    2f9c0:	2484dbd0 */ 	addiu	$a0,$a0,%lo(g_SchedThread)
/*    2f9c4:	3c028006 */ 	lui	$v0,%hi(var8005f108)
/*    2f9c8:	2442f108 */ 	addiu	$v0,$v0,%lo(var8005f108)
/*    2f9cc:	8c490000 */ 	lw	$t1,0x0($v0)
/*    2f9d0:	3c0a8006 */ 	lui	$t2,%hi(var8005f048)
/*    2f9d4:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    2f9d8:	254af048 */ 	addiu	$t2,$t2,%lo(var8005f048)
/*    2f9dc:	3c0c8006 */ 	lui	$t4,%hi(var8005f0a8)
/*    2f9e0:	258cf0a8 */ 	addiu	$t4,$t4,%lo(var8005f0a8)
/*    2f9e4:	012a5826 */ 	xor	$t3,$t1,$t2
/*    2f9e8:	016c6826 */ 	xor	$t5,$t3,$t4
/*    2f9ec:	ac4d0000 */ 	sw	$t5,0x0($v0)
/*    2f9f0:	03e00008 */ 	jr	$ra
/*    2f9f4:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*    2f9f8:	00000000 */ 	nop
/*    2f9fc:	00000000 */ 	nop
);
