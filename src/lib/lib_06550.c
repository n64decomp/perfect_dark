#include <ultra64.h>
#include "libultra_internal.h"
#include "constants.h"
#include "bss.h"
#include "lib/lib_06550.h"
#include "lib/lib_4b170.h"
#include "lib/lib_4cc10.h"
#include "lib/lib_4d000.h"
#include "lib/lib_4d480.h"
#include "lib/lib_4e090.h"
#include "data.h"
#include "types.h"

GLOBAL_ASM(
glabel func00006550
/*     6550:	27bdfd30 */ 	addiu	$sp,$sp,-720
/*     6554:	afb00024 */ 	sw	$s0,0x24($sp)
/*     6558:	30b0ffff */ 	andi	$s0,$a1,0xffff
/*     655c:	afb50038 */ 	sw	$s5,0x38($sp)
/*     6560:	afb30030 */ 	sw	$s3,0x30($sp)
/*     6564:	afb2002c */ 	sw	$s2,0x2c($sp)
/*     6568:	00c09025 */ 	or	$s2,$a2,$zero
/*     656c:	00e09825 */ 	or	$s3,$a3,$zero
/*     6570:	0080a825 */ 	or	$s5,$a0,$zero
/*     6574:	afbf0044 */ 	sw	$ra,0x44($sp)
/*     6578:	afb70040 */ 	sw	$s7,0x40($sp)
/*     657c:	afb6003c */ 	sw	$s6,0x3c($sp)
/*     6580:	afb40034 */ 	sw	$s4,0x34($sp)
/*     6584:	afb10028 */ 	sw	$s1,0x28($sp)
/*     6588:	afa502d4 */ 	sw	$a1,0x2d4($sp)
/*     658c:	afa0007c */ 	sw	$zero,0x7c($sp)
/*     6590:	afa00078 */ 	sw	$zero,0x78($sp)
/*     6594:	12000003 */ 	beqz	$s0,.L000065a4
/*     6598:	afa00060 */ 	sw	$zero,0x60($sp)
/*     659c:	14c00003 */ 	bnez	$a2,.L000065ac
/*     65a0:	8fa202e4 */ 	lw	$v0,0x2e4($sp)
.L000065a4:
/*     65a4:	100001e3 */ 	b	.L00006d34
/*     65a8:	24020005 */ 	addiu	$v0,$zero,0x5
.L000065ac:
/*     65ac:	8eaf0000 */ 	lw	$t7,0x0($s5)
/*     65b0:	244200ff */ 	addiu	$v0,$v0,0xff
/*     65b4:	04410003 */ 	bgez	$v0,.L000065c4
/*     65b8:	00027203 */ 	sra	$t6,$v0,0x8
/*     65bc:	244100ff */ 	addiu	$at,$v0,0xff
/*     65c0:	00017203 */ 	sra	$t6,$at,0x8
.L000065c4:
/*     65c4:	31f80001 */ 	andi	$t8,$t7,0x1
/*     65c8:	01c01025 */ 	or	$v0,$t6,$zero
/*     65cc:	17000003 */ 	bnez	$t8,.L000065dc
/*     65d0:	01c08825 */ 	or	$s1,$t6,$zero
/*     65d4:	100001d7 */ 	b	.L00006d34
/*     65d8:	24020005 */ 	addiu	$v0,$zero,0x5
.L000065dc:
/*     65dc:	02a02025 */ 	or	$a0,$s5,$zero
/*     65e0:	0c013218 */ 	jal	__osCheckId
/*     65e4:	afa20054 */ 	sw	$v0,0x54($sp)
/*     65e8:	24010002 */ 	addiu	$at,$zero,0x2
/*     65ec:	14410003 */ 	bne	$v0,$at,.L000065fc
/*     65f0:	02a02025 */ 	or	$a0,$s5,$zero
/*     65f4:	100001cf */ 	b	.L00006d34
/*     65f8:	24020002 */ 	addiu	$v0,$zero,0x2
.L000065fc:
/*     65fc:	8fb902e0 */ 	lw	$t9,0x2e0($sp)
/*     6600:	27a800a0 */ 	addiu	$t0,$sp,0xa0
/*     6604:	afa80014 */ 	sw	$t0,0x14($sp)
/*     6608:	3205ffff */ 	andi	$a1,$s0,0xffff
/*     660c:	02403025 */ 	or	$a2,$s2,$zero
/*     6610:	02603825 */ 	or	$a3,$s3,$zero
/*     6614:	0c013304 */ 	jal	func0004cc10
/*     6618:	afb90010 */ 	sw	$t9,0x10($sp)
/*     661c:	10400005 */ 	beqz	$v0,.L00006634
/*     6620:	24010005 */ 	addiu	$at,$zero,0x5
/*     6624:	50410004 */ 	beql	$v0,$at,.L00006638
/*     6628:	8fa900a0 */ 	lw	$t1,0xa0($sp)
/*     662c:	100001c2 */ 	b	.L00006d38
/*     6630:	8fbf0044 */ 	lw	$ra,0x44($sp)
.L00006634:
/*     6634:	8fa900a0 */ 	lw	$t1,0xa0($sp)
.L00006638:
/*     6638:	2401ffff */ 	addiu	$at,$zero,-1
/*     663c:	8faa0054 */ 	lw	$t2,0x54($sp)
/*     6640:	15210003 */ 	bne	$t1,$at,.L00006650
/*     6644:	00000000 */ 	nop
/*     6648:	100001ba */ 	b	.L00006d34
/*     664c:	24020005 */ 	addiu	$v0,$zero,0x5
.L00006650:
/*     6650:	114001b8 */ 	beqz	$t2,.L00006d34
/*     6654:	24020005 */ 	addiu	$v0,$zero,0x5
/*     6658:	92ab0065 */ 	lbu	$t3,0x65($s5)
/*     665c:	02a02025 */ 	or	$a0,$s5,$zero
/*     6660:	00002825 */ 	or	$a1,$zero,$zero
/*     6664:	51600008 */ 	beqzl	$t3,.L00006688
/*     6668:	8eac005c */ 	lw	$t4,0x5c($s5)
/*     666c:	0c013378 */ 	jal	__osPfsSelectBank
/*     6670:	a2a00065 */ 	sb	$zero,0x65($s5)
/*     6674:	50400004 */ 	beqzl	$v0,.L00006688
/*     6678:	8eac005c */ 	lw	$t4,0x5c($s5)
/*     667c:	100001ae */ 	b	.L00006d38
/*     6680:	8fbf0044 */ 	lw	$ra,0x44($sp)
/*     6684:	8eac005c */ 	lw	$t4,0x5c($s5)
.L00006688:
/*     6688:	8fad00a0 */ 	lw	$t5,0xa0($sp)
/*     668c:	8ea40004 */ 	lw	$a0,0x4($s5)
/*     6690:	8ea50008 */ 	lw	$a1,0x8($s5)
/*     6694:	018d3021 */ 	addu	$a2,$t4,$t5
/*     6698:	30ceffff */ 	andi	$t6,$a2,0xffff
/*     669c:	01c03025 */ 	or	$a2,$t6,$zero
/*     66a0:	0c012e18 */ 	jal	__osContRamRead
/*     66a4:	27a700a4 */ 	addiu	$a3,$sp,0xa4
/*     66a8:	10400003 */ 	beqz	$v0,.L000066b8
/*     66ac:	00402025 */ 	or	$a0,$v0,$zero
/*     66b0:	100001a1 */ 	b	.L00006d38
/*     66b4:	8fbf0044 */ 	lw	$ra,0x44($sp)
.L000066b8:
/*     66b8:	97af00aa */ 	lhu	$t7,0xaa($sp)
/*     66bc:	8eb80060 */ 	lw	$t8,0x60($s5)
/*     66c0:	93b300ab */ 	lbu	$s3,0xab($sp)
/*     66c4:	01f8082a */ 	slt	$at,$t7,$t8
/*     66c8:	50200004 */ 	beqzl	$at,.L000066dc
/*     66cc:	afb302cc */ 	sw	$s3,0x2cc($sp)
/*     66d0:	10000198 */ 	b	.L00006d34
/*     66d4:	24020003 */ 	addiu	$v0,$zero,0x3
/*     66d8:	afb302cc */ 	sw	$s3,0x2cc($sp)
.L000066dc:
/*     66dc:	92a20064 */ 	lbu	$v0,0x64($s5)
/*     66e0:	93b600aa */ 	lbu	$s6,0xaa($sp)
/*     66e4:	00001825 */ 	or	$v1,$zero,$zero
/*     66e8:	24170001 */ 	addiu	$s7,$zero,0x1
/*     66ec:	02c2082a */ 	slt	$at,$s6,$v0
/*     66f0:	10200035 */ 	beqz	$at,.L000067c8
/*     66f4:	02c09025 */ 	or	$s2,$s6,$zero
/*     66f8:	27b401c4 */ 	addiu	$s4,$sp,0x1c4
/*     66fc:	27b00094 */ 	addiu	$s0,$sp,0x94
/*     6700:	02a02025 */ 	or	$a0,$s5,$zero
.L00006704:
/*     6704:	02802825 */ 	or	$a1,$s4,$zero
/*     6708:	00003025 */ 	or	$a2,$zero,$zero
/*     670c:	32c700ff */ 	andi	$a3,$s6,0xff
/*     6710:	0c01324d */ 	jal	__osPfsRWInode
/*     6714:	afa3009c */ 	sw	$v1,0x9c($sp)
/*     6718:	8fa3009c */ 	lw	$v1,0x9c($sp)
/*     671c:	10400003 */ 	beqz	$v0,.L0000672c
/*     6720:	00402025 */ 	or	$a0,$v0,$zero
/*     6724:	10000184 */ 	b	.L00006d38
/*     6728:	8fbf0044 */ 	lw	$ra,0x44($sp)
.L0000672c:
/*     672c:	8fa802cc */ 	lw	$t0,0x2cc($sp)
/*     6730:	00084840 */ 	sll	$t1,$t0,0x1
/*     6734:	02895021 */ 	addu	$t2,$s4,$t1
/*     6738:	95410000 */ 	lhu	$at,0x0($t2)
/*     673c:	a6010000 */ 	sh	$at,0x0($s0)
/*     6740:	8eae0060 */ 	lw	$t6,0x60($s5)
/*     6744:	97ad0094 */ 	lhu	$t5,0x94($sp)
/*     6748:	01ae082a */ 	slt	$at,$t5,$t6
/*     674c:	54200015 */ 	bnezl	$at,.L000067a4
/*     6750:	97ae0094 */ 	lhu	$t6,0x94($sp)
/*     6754:	93b30095 */ 	lbu	$s3,0x95($sp)
.L00006758:
/*     6758:	24630001 */ 	addiu	$v1,$v1,0x1
/*     675c:	0013c040 */ 	sll	$t8,$s3,0x1
/*     6760:	0298c821 */ 	addu	$t9,$s4,$t8
/*     6764:	97210000 */ 	lhu	$at,0x0($t9)
/*     6768:	a6010000 */ 	sh	$at,0x0($s0)
/*     676c:	93ab0094 */ 	lbu	$t3,0x94($sp)
/*     6770:	97ac0094 */ 	lhu	$t4,0x94($sp)
/*     6774:	524b0007 */ 	beql	$s2,$t3,.L00006794
/*     6778:	8ead0060 */ 	lw	$t5,0x60($s5)
/*     677c:	93b30095 */ 	lbu	$s3,0x95($sp)
/*     6780:	0160b025 */ 	or	$s6,$t3,$zero
/*     6784:	01609025 */ 	or	$s2,$t3,$zero
/*     6788:	10000005 */ 	b	.L000067a0
/*     678c:	afb302cc */ 	sw	$s3,0x2cc($sp)
/*     6790:	8ead0060 */ 	lw	$t5,0x60($s5)
.L00006794:
/*     6794:	018d082a */ 	slt	$at,$t4,$t5
/*     6798:	5020ffef */ 	beqzl	$at,.L00006758
/*     679c:	93b30095 */ 	lbu	$s3,0x95($sp)
.L000067a0:
/*     67a0:	97ae0094 */ 	lhu	$t6,0x94($sp)
.L000067a4:
/*     67a4:	56ee0005 */ 	bnel	$s7,$t6,.L000067bc
/*     67a8:	92a20064 */ 	lbu	$v0,0x64($s5)
/*     67ac:	24630001 */ 	addiu	$v1,$v1,0x1
/*     67b0:	10000005 */ 	b	.L000067c8
/*     67b4:	92a20064 */ 	lbu	$v0,0x64($s5)
/*     67b8:	92a20064 */ 	lbu	$v0,0x64($s5)
.L000067bc:
/*     67bc:	0242082a */ 	slt	$at,$s2,$v0
/*     67c0:	5420ffd0 */ 	bnezl	$at,.L00006704
/*     67c4:	02a02025 */ 	or	$a0,$s5,$zero
.L000067c8:
/*     67c8:	0242082a */ 	slt	$at,$s2,$v0
/*     67cc:	27b00094 */ 	addiu	$s0,$sp,0x94
/*     67d0:	27b401c4 */ 	addiu	$s4,$sp,0x1c4
/*     67d4:	24170001 */ 	addiu	$s7,$zero,0x1
/*     67d8:	14200003 */ 	bnez	$at,.L000067e8
/*     67dc:	a3b60066 */ 	sb	$s6,0x66($sp)
/*     67e0:	10000154 */ 	b	.L00006d34
/*     67e4:	24020003 */ 	addiu	$v0,$zero,0x3
.L000067e8:
/*     67e8:	8faf0054 */ 	lw	$t7,0x54($sp)
/*     67ec:	27a5008c */ 	addiu	$a1,$sp,0x8c
/*     67f0:	8fa90054 */ 	lw	$t1,0x54($sp)
/*     67f4:	006f082a */ 	slt	$at,$v1,$t7
/*     67f8:	5020007c */ 	beqzl	$at,.L000069ec
/*     67fc:	0123082a */ 	slt	$at,$t1,$v1
/*     6800:	01e38023 */ 	subu	$s0,$t7,$v1
/*     6804:	02008825 */ 	or	$s1,$s0,$zero
/*     6808:	0c013398 */ 	jal	osPfsFreeBlocks
/*     680c:	02a02025 */ 	or	$a0,$s5,$zero
/*     6810:	8fb8008c */ 	lw	$t8,0x8c($sp)
/*     6814:	32d200ff */ 	andi	$s2,$s6,0xff
/*     6818:	27a300c4 */ 	addiu	$v1,$sp,0xc4
/*     681c:	07010003 */ 	bgez	$t8,.L0000682c
/*     6820:	00184203 */ 	sra	$t0,$t8,0x8
/*     6824:	270100ff */ 	addiu	$at,$t8,0xff
/*     6828:	00014203 */ 	sra	$t0,$at,0x8
.L0000682c:
/*     682c:	0110082a */ 	slt	$at,$t0,$s0
/*     6830:	10200003 */ 	beqz	$at,.L00006840
/*     6834:	27a201c4 */ 	addiu	$v0,$sp,0x1c4
/*     6838:	1000013e */ 	b	.L00006d34
/*     683c:	24020007 */ 	addiu	$v0,$zero,0x7
.L00006840:
/*     6840:	27a402c4 */ 	addiu	$a0,$sp,0x2c4
.L00006844:
/*     6844:	94590000 */ 	lhu	$t9,0x0($v0)
/*     6848:	24420002 */ 	addiu	$v0,$v0,0x2
/*     684c:	24630002 */ 	addiu	$v1,$v1,0x2
/*     6850:	1444fffc */ 	bne	$v0,$a0,.L00006844
/*     6854:	a479fffe */ 	sh	$t9,-0x2($v1)
/*     6858:	92a90064 */ 	lbu	$t1,0x64($s5)
/*     685c:	0000b025 */ 	or	$s6,$zero,$zero
/*     6860:	27b702cc */ 	addiu	$s7,$sp,0x2cc
/*     6864:	19200049 */ 	blez	$t1,.L0000698c
/*     6868:	27b002c4 */ 	addiu	$s0,$sp,0x2c4
.L0000686c:
/*     686c:	02a02025 */ 	or	$a0,$s5,$zero
/*     6870:	02802825 */ 	or	$a1,$s4,$zero
/*     6874:	00003025 */ 	or	$a2,$zero,$zero
/*     6878:	0c01324d */ 	jal	__osPfsRWInode
/*     687c:	32c700ff */ 	andi	$a3,$s6,0xff
/*     6880:	10400003 */ 	beqz	$v0,.L00006890
/*     6884:	02a02025 */ 	or	$a0,$s5,$zero
/*     6888:	1000012b */ 	b	.L00006d38
/*     688c:	8fbf0044 */ 	lw	$ra,0x44($sp)
.L00006890:
/*     6890:	27ab0080 */ 	addiu	$t3,$sp,0x80
/*     6894:	27aa006c */ 	addiu	$t2,$sp,0x6c
/*     6898:	afaa0018 */ 	sw	$t2,0x18($sp)
/*     689c:	afab0014 */ 	sw	$t3,0x14($sp)
/*     68a0:	02802825 */ 	or	$a1,$s4,$zero
/*     68a4:	02203025 */ 	or	$a2,$s1,$zero
/*     68a8:	02e03825 */ 	or	$a3,$s7,$zero
/*     68ac:	0c0134cd */ 	jal	func0004d334
/*     68b0:	afb60010 */ 	sw	$s6,0x10($sp)
/*     68b4:	10400003 */ 	beqz	$v0,.L000068c4
/*     68b8:	8fac02cc */ 	lw	$t4,0x2cc($sp)
/*     68bc:	1000011e */ 	b	.L00006d38
/*     68c0:	8fbf0044 */ 	lw	$ra,0x44($sp)
.L000068c4:
/*     68c4:	2401ffff */ 	addiu	$at,$zero,-1
/*     68c8:	1181002a */ 	beq	$t4,$at,.L00006974
/*     68cc:	8fad007c */ 	lw	$t5,0x7c($sp)
/*     68d0:	15a00003 */ 	bnez	$t5,.L000068e0
/*     68d4:	93ae0066 */ 	lbu	$t6,0x66($sp)
/*     68d8:	52ce0013 */ 	beql	$s6,$t6,.L00006928
/*     68dc:	27a300c4 */ 	addiu	$v1,$sp,0xc4
.L000068e0:
/*     68e0:	8faf0078 */ 	lw	$t7,0x78($sp)
/*     68e4:	27a500c4 */ 	addiu	$a1,$sp,0xc4
/*     68e8:	00134040 */ 	sll	$t0,$s3,0x1
/*     68ec:	25f80001 */ 	addiu	$t8,$t7,0x1
/*     68f0:	afb80078 */ 	sw	$t8,0x78($sp)
/*     68f4:	00a81021 */ 	addu	$v0,$a1,$t0
/*     68f8:	a0560000 */ 	sb	$s6,0x0($v0)
/*     68fc:	8fb902cc */ 	lw	$t9,0x2cc($sp)
/*     6900:	02a02025 */ 	or	$a0,$s5,$zero
/*     6904:	24060001 */ 	addiu	$a2,$zero,0x1
/*     6908:	324700ff */ 	andi	$a3,$s2,0xff
/*     690c:	0c01324d */ 	jal	__osPfsRWInode
/*     6910:	a0590001 */ 	sb	$t9,0x1($v0)
/*     6914:	50400004 */ 	beqzl	$v0,.L00006928
/*     6918:	27a300c4 */ 	addiu	$v1,$sp,0xc4
/*     691c:	10000106 */ 	b	.L00006d38
/*     6920:	8fbf0044 */ 	lw	$ra,0x44($sp)
/*     6924:	27a300c4 */ 	addiu	$v1,$sp,0xc4
.L00006928:
/*     6928:	27a201c4 */ 	addiu	$v0,$sp,0x1c4
.L0000692c:
/*     692c:	94490000 */ 	lhu	$t1,0x0($v0)
/*     6930:	24420002 */ 	addiu	$v0,$v0,0x2
/*     6934:	24630002 */ 	addiu	$v1,$v1,0x2
/*     6938:	1450fffc */ 	bne	$v0,$s0,.L0000692c
/*     693c:	a469fffe */ 	sh	$t1,-0x2($v1)
/*     6940:	8fa20080 */ 	lw	$v0,0x80($sp)
/*     6944:	8fab007c */ 	lw	$t3,0x7c($sp)
/*     6948:	0051082a */ 	slt	$at,$v0,$s1
/*     694c:	10200003 */ 	beqz	$at,.L0000695c
/*     6950:	256a0001 */ 	addiu	$t2,$t3,0x1
/*     6954:	10000004 */ 	b	.L00006968
/*     6958:	02228823 */ 	subu	$s1,$s1,$v0
.L0000695c:
/*     695c:	00008825 */ 	or	$s1,$zero,$zero
/*     6960:	1000000a */ 	b	.L0000698c
/*     6964:	32d200ff */ 	andi	$s2,$s6,0xff
.L00006968:
/*     6968:	8fb3006c */ 	lw	$s3,0x6c($sp)
/*     696c:	32d200ff */ 	andi	$s2,$s6,0xff
/*     6970:	afaa007c */ 	sw	$t2,0x7c($sp)
.L00006974:
/*     6974:	92ad0064 */ 	lbu	$t5,0x64($s5)
/*     6978:	26d60001 */ 	addiu	$s6,$s6,0x1
/*     697c:	32cc00ff */ 	andi	$t4,$s6,0xff
/*     6980:	018d082a */ 	slt	$at,$t4,$t5
/*     6984:	1420ffb9 */ 	bnez	$at,.L0000686c
/*     6988:	0180b025 */ 	or	$s6,$t4,$zero
.L0000698c:
/*     698c:	1e200004 */ 	bgtz	$s1,.L000069a0
/*     6990:	8fae02cc */ 	lw	$t6,0x2cc($sp)
/*     6994:	2401ffff */ 	addiu	$at,$zero,-1
/*     6998:	15c10003 */ 	bne	$t6,$at,.L000069a8
/*     699c:	8faf0078 */ 	lw	$t7,0x78($sp)
.L000069a0:
/*     69a0:	100000e4 */ 	b	.L00006d34
/*     69a4:	24020003 */ 	addiu	$v0,$zero,0x3
.L000069a8:
/*     69a8:	15e00007 */ 	bnez	$t7,.L000069c8
/*     69ac:	02a02025 */ 	or	$a0,$s5,$zero
/*     69b0:	0013c040 */ 	sll	$t8,$s3,0x1
/*     69b4:	27a800c4 */ 	addiu	$t0,$sp,0xc4
/*     69b8:	03081021 */ 	addu	$v0,$t8,$t0
/*     69bc:	a0560000 */ 	sb	$s6,0x0($v0)
/*     69c0:	8fb902cc */ 	lw	$t9,0x2cc($sp)
/*     69c4:	a0590001 */ 	sb	$t9,0x1($v0)
.L000069c8:
/*     69c8:	27a500c4 */ 	addiu	$a1,$sp,0xc4
/*     69cc:	24060001 */ 	addiu	$a2,$zero,0x1
/*     69d0:	0c01324d */ 	jal	__osPfsRWInode
/*     69d4:	324700ff */ 	andi	$a3,$s2,0xff
/*     69d8:	104000d4 */ 	beqz	$v0,.L00006d2c
/*     69dc:	00402025 */ 	or	$a0,$v0,$zero
/*     69e0:	100000d5 */ 	b	.L00006d38
/*     69e4:	8fbf0044 */ 	lw	$ra,0x44($sp)
/*     69e8:	0123082a */ 	slt	$at,$t1,$v1
.L000069ec:
/*     69ec:	102000cf */ 	beqz	$at,.L00006d2c
/*     69f0:	97ab00aa */ 	lhu	$t3,0xaa($sp)
/*     69f4:	a7ab005c */ 	sh	$t3,0x5c($sp)
/*     69f8:	92a20064 */ 	lbu	$v0,0x64($s5)
/*     69fc:	93b600aa */ 	lbu	$s6,0xaa($sp)
/*     6a00:	27b30098 */ 	addiu	$s3,$sp,0x98
/*     6a04:	02c2082a */ 	slt	$at,$s6,$v0
/*     6a08:	1020005e */ 	beqz	$at,.L00006b84
/*     6a0c:	02c09025 */ 	or	$s2,$s6,$zero
/*     6a10:	02a02025 */ 	or	$a0,$s5,$zero
.L00006a14:
/*     6a14:	02802825 */ 	or	$a1,$s4,$zero
/*     6a18:	00003025 */ 	or	$a2,$zero,$zero
/*     6a1c:	0c01324d */ 	jal	__osPfsRWInode
/*     6a20:	32c700ff */ 	andi	$a3,$s6,0xff
/*     6a24:	10400003 */ 	beqz	$v0,.L00006a34
/*     6a28:	27aa005c */ 	addiu	$t2,$sp,0x5c
/*     6a2c:	100000c2 */ 	b	.L00006d38
/*     6a30:	8fbf0044 */ 	lw	$ra,0x44($sp)
.L00006a34:
/*     6a34:	95410000 */ 	lhu	$at,0x0($t2)
/*     6a38:	2631ffff */ 	addiu	$s1,$s1,-1
/*     6a3c:	a6610000 */ 	sh	$at,0x0($s3)
/*     6a40:	93ae005d */ 	lbu	$t6,0x5d($sp)
/*     6a44:	000e7840 */ 	sll	$t7,$t6,0x1
/*     6a48:	028fc021 */ 	addu	$t8,$s4,$t7
/*     6a4c:	97010000 */ 	lhu	$at,0x0($t8)
/*     6a50:	a6010000 */ 	sh	$at,0x0($s0)
/*     6a54:	1a400003 */ 	blez	$s2,.L00006a64
/*     6a58:	93a90095 */ 	lbu	$t1,0x95($sp)
/*     6a5c:	10000002 */ 	b	.L00006a68
/*     6a60:	02e01025 */ 	or	$v0,$s7,$zero
.L00006a64:
/*     6a64:	8ea20060 */ 	lw	$v0,0x60($s5)
.L00006a68:
/*     6a68:	0122082a */ 	slt	$at,$t1,$v0
/*     6a6c:	10200005 */ 	beqz	$at,.L00006a84
/*     6a70:	97ab0094 */ 	lhu	$t3,0x94($sp)
/*     6a74:	12eb0003 */ 	beq	$s7,$t3,.L00006a84
/*     6a78:	00000000 */ 	nop
/*     6a7c:	100000ad */ 	b	.L00006d34
/*     6a80:	24020003 */ 	addiu	$v0,$zero,0x3
.L00006a84:
/*     6a84:	1a200037 */ 	blez	$s1,.L00006b64
/*     6a88:	97ac0094 */ 	lhu	$t4,0x94($sp)
/*     6a8c:	8eaa0060 */ 	lw	$t2,0x60($s5)
/*     6a90:	02a02025 */ 	or	$a0,$s5,$zero
/*     6a94:	02802825 */ 	or	$a1,$s4,$zero
/*     6a98:	018a082a */ 	slt	$at,$t4,$t2
/*     6a9c:	14200031 */ 	bnez	$at,.L00006b64
/*     6aa0:	240c0001 */ 	addiu	$t4,$zero,0x1
/*     6aa4:	96010000 */ 	lhu	$at,0x0($s0)
.L00006aa8:
/*     6aa8:	2631ffff */ 	addiu	$s1,$s1,-1
/*     6aac:	a6610000 */ 	sh	$at,0x0($s3)
/*     6ab0:	93af0095 */ 	lbu	$t7,0x95($sp)
/*     6ab4:	000f4040 */ 	sll	$t0,$t7,0x1
/*     6ab8:	0288c021 */ 	addu	$t8,$s4,$t0
/*     6abc:	97010000 */ 	lhu	$at,0x0($t8)
/*     6ac0:	a6010000 */ 	sh	$at,0x0($s0)
/*     6ac4:	93ab0094 */ 	lbu	$t3,0x94($sp)
/*     6ac8:	97aa0094 */ 	lhu	$t2,0x94($sp)
/*     6acc:	124b001f */ 	beq	$s2,$t3,.L00006b4c
/*     6ad0:	00000000 */ 	nop
/*     6ad4:	1637000b */ 	bne	$s1,$s7,.L00006b04
/*     6ad8:	93aa0099 */ 	lbu	$t2,0x99($sp)
/*     6adc:	000a6840 */ 	sll	$t5,$t2,0x1
/*     6ae0:	028d7021 */ 	addu	$t6,$s4,$t5
/*     6ae4:	a5cc0000 */ 	sh	$t4,0x0($t6)
/*     6ae8:	24060001 */ 	addiu	$a2,$zero,0x1
/*     6aec:	0c01324d */ 	jal	__osPfsRWInode
/*     6af0:	32c700ff */ 	andi	$a3,$s6,0xff
/*     6af4:	50400004 */ 	beqzl	$v0,.L00006b08
/*     6af8:	8faf0060 */ 	lw	$t7,0x60($sp)
/*     6afc:	1000008e */ 	b	.L00006d38
/*     6b00:	8fbf0044 */ 	lw	$ra,0x44($sp)
.L00006b04:
/*     6b04:	8faf0060 */ 	lw	$t7,0x60($sp)
.L00006b08:
/*     6b08:	27b9005c */ 	addiu	$t9,$sp,0x5c
/*     6b0c:	02a02025 */ 	or	$a0,$s5,$zero
/*     6b10:	25e80001 */ 	addiu	$t0,$t7,0x1
/*     6b14:	afa80060 */ 	sw	$t0,0x60($sp)
/*     6b18:	96010000 */ 	lhu	$at,0x0($s0)
/*     6b1c:	02802825 */ 	or	$a1,$s4,$zero
/*     6b20:	00003025 */ 	or	$a2,$zero,$zero
/*     6b24:	a7210000 */ 	sh	$at,0x0($t9)
/*     6b28:	93b60094 */ 	lbu	$s6,0x94($sp)
/*     6b2c:	0c01324d */ 	jal	__osPfsRWInode
/*     6b30:	02c03825 */ 	or	$a3,$s6,$zero
/*     6b34:	10400003 */ 	beqz	$v0,.L00006b44
/*     6b38:	00000000 */ 	nop
/*     6b3c:	1000007e */ 	b	.L00006d38
/*     6b40:	8fbf0044 */ 	lw	$ra,0x44($sp)
.L00006b44:
/*     6b44:	10000007 */ 	b	.L00006b64
/*     6b48:	02c09025 */ 	or	$s2,$s6,$zero
.L00006b4c:
/*     6b4c:	1a200005 */ 	blez	$s1,.L00006b64
/*     6b50:	00000000 */ 	nop
/*     6b54:	8ead0060 */ 	lw	$t5,0x60($s5)
/*     6b58:	014d082a */ 	slt	$at,$t2,$t5
/*     6b5c:	5020ffd2 */ 	beqzl	$at,.L00006aa8
/*     6b60:	96010000 */ 	lhu	$at,0x0($s0)
.L00006b64:
/*     6b64:	56200004 */ 	bnezl	$s1,.L00006b78
/*     6b68:	92a20064 */ 	lbu	$v0,0x64($s5)
/*     6b6c:	10000005 */ 	b	.L00006b84
/*     6b70:	92a20064 */ 	lbu	$v0,0x64($s5)
/*     6b74:	92a20064 */ 	lbu	$v0,0x64($s5)
.L00006b78:
/*     6b78:	0242082a */ 	slt	$at,$s2,$v0
/*     6b7c:	5420ffa5 */ 	bnezl	$at,.L00006a14
/*     6b80:	02a02025 */ 	or	$a0,$s5,$zero
.L00006b84:
/*     6b84:	0242082a */ 	slt	$at,$s2,$v0
/*     6b88:	14200003 */ 	bnez	$at,.L00006b98
/*     6b8c:	8fac0060 */ 	lw	$t4,0x60($sp)
/*     6b90:	10000068 */ 	b	.L00006d34
/*     6b94:	24020003 */ 	addiu	$v0,$zero,0x3
.L00006b98:
/*     6b98:	15800007 */ 	bnez	$t4,.L00006bb8
/*     6b9c:	93b90095 */ 	lbu	$t9,0x95($sp)
/*     6ba0:	93af0099 */ 	lbu	$t7,0x99($sp)
/*     6ba4:	240e0001 */ 	addiu	$t6,$zero,0x1
/*     6ba8:	000f4040 */ 	sll	$t0,$t7,0x1
/*     6bac:	02884821 */ 	addu	$t1,$s4,$t0
/*     6bb0:	10000005 */ 	b	.L00006bc8
/*     6bb4:	a52e0000 */ 	sh	$t6,0x0($t1)
.L00006bb8:
/*     6bb8:	00195840 */ 	sll	$t3,$t9,0x1
/*     6bbc:	028b5021 */ 	addu	$t2,$s4,$t3
/*     6bc0:	24180001 */ 	addiu	$t8,$zero,0x1
/*     6bc4:	a5580000 */ 	sh	$t8,0x0($t2)
.L00006bc8:
/*     6bc8:	97ad0094 */ 	lhu	$t5,0x94($sp)
/*     6bcc:	93af0099 */ 	lbu	$t7,0x99($sp)
/*     6bd0:	240c0003 */ 	addiu	$t4,$zero,0x3
/*     6bd4:	16ed000c */ 	bne	$s7,$t5,.L00006c08
/*     6bd8:	000f4040 */ 	sll	$t0,$t7,0x1
/*     6bdc:	02887021 */ 	addu	$t6,$s4,$t0
/*     6be0:	a5cc0000 */ 	sh	$t4,0x0($t6)
/*     6be4:	02a02025 */ 	or	$a0,$s5,$zero
/*     6be8:	02802825 */ 	or	$a1,$s4,$zero
/*     6bec:	24060001 */ 	addiu	$a2,$zero,0x1
/*     6bf0:	0c01324d */ 	jal	__osPfsRWInode
/*     6bf4:	32c700ff */ 	andi	$a3,$s6,0xff
/*     6bf8:	50400039 */ 	beqzl	$v0,.L00006ce0
/*     6bfc:	97a200ae */ 	lhu	$v0,0xae($sp)
/*     6c00:	1000004d */ 	b	.L00006d38
/*     6c04:	8fbf0044 */ 	lw	$ra,0x44($sp)
.L00006c08:
/*     6c08:	96010000 */ 	lhu	$at,0x0($s0)
/*     6c0c:	27a9005c */ 	addiu	$t1,$sp,0x5c
/*     6c10:	27b00070 */ 	addiu	$s0,$sp,0x70
/*     6c14:	a5210000 */ 	sh	$at,0x0($t1)
/*     6c18:	92a20064 */ 	lbu	$v0,0x64($s5)
/*     6c1c:	93b60094 */ 	lbu	$s6,0x94($sp)
/*     6c20:	02c2082a */ 	slt	$at,$s6,$v0
/*     6c24:	10200028 */ 	beqz	$at,.L00006cc8
/*     6c28:	02c09025 */ 	or	$s2,$s6,$zero
/*     6c2c:	02a02025 */ 	or	$a0,$s5,$zero
.L00006c30:
/*     6c30:	02802825 */ 	or	$a1,$s4,$zero
/*     6c34:	93a6005d */ 	lbu	$a2,0x5d($sp)
/*     6c38:	32c700ff */ 	andi	$a3,$s6,0xff
/*     6c3c:	0c013596 */ 	jal	func0004d658
/*     6c40:	afb00010 */ 	sw	$s0,0x10($sp)
/*     6c44:	10400003 */ 	beqz	$v0,.L00006c54
/*     6c48:	02a02025 */ 	or	$a0,$s5,$zero
/*     6c4c:	1000003a */ 	b	.L00006d38
/*     6c50:	8fbf0044 */ 	lw	$ra,0x44($sp)
.L00006c54:
/*     6c54:	02802825 */ 	or	$a1,$s4,$zero
/*     6c58:	24060001 */ 	addiu	$a2,$zero,0x1
/*     6c5c:	0c01324d */ 	jal	__osPfsRWInode
/*     6c60:	32c700ff */ 	andi	$a3,$s6,0xff
/*     6c64:	10400003 */ 	beqz	$v0,.L00006c74
/*     6c68:	97b80070 */ 	lhu	$t8,0x70($sp)
/*     6c6c:	10000032 */ 	b	.L00006d38
/*     6c70:	8fbf0044 */ 	lw	$ra,0x44($sp)
.L00006c74:
/*     6c74:	16f80003 */ 	bne	$s7,$t8,.L00006c84
/*     6c78:	93b60070 */ 	lbu	$s6,0x70($sp)
/*     6c7c:	10000012 */ 	b	.L00006cc8
/*     6c80:	92a20064 */ 	lbu	$v0,0x64($s5)
.L00006c84:
/*     6c84:	96010000 */ 	lhu	$at,0x0($s0)
/*     6c88:	27aa005c */ 	addiu	$t2,$sp,0x5c
/*     6c8c:	02a02025 */ 	or	$a0,$s5,$zero
/*     6c90:	02802825 */ 	or	$a1,$s4,$zero
/*     6c94:	00003025 */ 	or	$a2,$zero,$zero
/*     6c98:	02c03825 */ 	or	$a3,$s6,$zero
/*     6c9c:	0c01324d */ 	jal	__osPfsRWInode
/*     6ca0:	a5410000 */ 	sh	$at,0x0($t2)
/*     6ca4:	50400004 */ 	beqzl	$v0,.L00006cb8
/*     6ca8:	92a20064 */ 	lbu	$v0,0x64($s5)
/*     6cac:	10000022 */ 	b	.L00006d38
/*     6cb0:	8fbf0044 */ 	lw	$ra,0x44($sp)
/*     6cb4:	92a20064 */ 	lbu	$v0,0x64($s5)
.L00006cb8:
/*     6cb8:	02c09025 */ 	or	$s2,$s6,$zero
/*     6cbc:	02c2082a */ 	slt	$at,$s6,$v0
/*     6cc0:	5420ffdb */ 	bnezl	$at,.L00006c30
/*     6cc4:	02a02025 */ 	or	$a0,$s5,$zero
.L00006cc8:
/*     6cc8:	0242082a */ 	slt	$at,$s2,$v0
/*     6ccc:	54200004 */ 	bnezl	$at,.L00006ce0
/*     6cd0:	97a200ae */ 	lhu	$v0,0xae($sp)
/*     6cd4:	10000017 */ 	b	.L00006d34
/*     6cd8:	24020003 */ 	addiu	$v0,$zero,0x3
/*     6cdc:	97a200ae */ 	lhu	$v0,0xae($sp)
.L00006ce0:
/*     6ce0:	27a700a4 */ 	addiu	$a3,$sp,0xa4
/*     6ce4:	18400003 */ 	blez	$v0,.L00006cf4
/*     6ce8:	00024023 */ 	negu	$t0,$v0
/*     6cec:	10000002 */ 	b	.L00006cf8
/*     6cf0:	a7a200ae */ 	sh	$v0,0xae($sp)
.L00006cf4:
/*     6cf4:	a7a800ae */ 	sh	$t0,0xae($sp)
.L00006cf8:
/*     6cf8:	8eac005c */ 	lw	$t4,0x5c($s5)
/*     6cfc:	8fae00a0 */ 	lw	$t6,0xa0($sp)
/*     6d00:	8ea40004 */ 	lw	$a0,0x4($s5)
/*     6d04:	8ea50008 */ 	lw	$a1,0x8($s5)
/*     6d08:	018e3021 */ 	addu	$a2,$t4,$t6
/*     6d0c:	30d9ffff */ 	andi	$t9,$a2,0xffff
/*     6d10:	03203025 */ 	or	$a2,$t9,$zero
/*     6d14:	0c012d84 */ 	jal	__osContRamWrite
/*     6d18:	afa00010 */ 	sw	$zero,0x10($sp)
/*     6d1c:	10400003 */ 	beqz	$v0,.L00006d2c
/*     6d20:	00402025 */ 	or	$a0,$v0,$zero
/*     6d24:	10000004 */ 	b	.L00006d38
/*     6d28:	8fbf0044 */ 	lw	$ra,0x44($sp)
.L00006d2c:
/*     6d2c:	10000001 */ 	b	.L00006d34
/*     6d30:	00801025 */ 	or	$v0,$a0,$zero
.L00006d34:
/*     6d34:	8fbf0044 */ 	lw	$ra,0x44($sp)
.L00006d38:
/*     6d38:	8fb00024 */ 	lw	$s0,0x24($sp)
/*     6d3c:	8fb10028 */ 	lw	$s1,0x28($sp)
/*     6d40:	8fb2002c */ 	lw	$s2,0x2c($sp)
/*     6d44:	8fb30030 */ 	lw	$s3,0x30($sp)
/*     6d48:	8fb40034 */ 	lw	$s4,0x34($sp)
/*     6d4c:	8fb50038 */ 	lw	$s5,0x38($sp)
/*     6d50:	8fb6003c */ 	lw	$s6,0x3c($sp)
/*     6d54:	8fb70040 */ 	lw	$s7,0x40($sp)
/*     6d58:	03e00008 */ 	jr	$ra
/*     6d5c:	27bd02d0 */ 	addiu	$sp,$sp,0x2d0
);

s32 __osPfsCheckRamArea(OSPfs* pfs);

#if VERSION >= VERSION_NTSC_1_0
s32 osPfsInitPak(OSMesgQueue *queue, OSPfs *pfs, s32 channel, s32 *arg3)
#else
s32 osPfsInitPak(OSMesgQueue *queue, OSPfs *pfs, s32 channel)
#endif
{
	s32 ret;
	u16 sum;
	u16 isum;
	u8 temp[32];
	__OSPackId *id;
	__OSPackId newid;

	ret = 0;

    __osSiGetAccess();
    ret = __osPfsGetStatus(queue, channel);
    __osSiRelAccess();

    if (ret != 0) {
        return ret;
	}

	pfs->queue = queue;
	pfs->channel = channel;
	pfs->status = 0;

	ERRCK(__osPfsCheckRamArea(pfs));
	ERRCK(__osPfsSelectBank(pfs, 0));
	ERRCK(__osContRamRead(pfs->queue, pfs->channel, 1, (u8*)temp));
	__osIdCheckSum((u16*)temp, &sum, &isum);

	id = (__OSPackId *)temp;

	if (id->checksum != sum || id->inverted_checksum != isum) {
		ret = __osCheckPackId(pfs, id);

		if (ret != 0) {
			pfs->status |= 4;
			return ret;
		}
	}

	if ((id->deviceid & 1) == 0) {
		ret = __osRepairPackId(pfs, id, &newid);

		if (ret != 0) {
			if (ret == 10) {
				pfs->status |= 4;
			}

			return ret;
		}

		id = &newid;

		if ((id->deviceid & 1) == 0) {
			return PFS_ERR_DEVICE;
		}
	}

	bcopy(id, pfs->id, 0x20);

	pfs->version = id->version;
	pfs->banks = id->banks;
	pfs->inode_start_page = pfs->banks * 2 + 3;
	pfs->dir_size = 0x10;
	pfs->inode_table = 8;
	pfs->minode_table = pfs->banks * PFS_ONE_PAGE + 8;
	pfs->dir_table = pfs->minode_table + pfs->banks * PFS_ONE_PAGE;

#if VERSION >= VERSION_NTSC_1_0
	ERRCK(__osContRamRead(pfs->queue, pfs->channel, 7, pfs->label));
	ret = osPfsChecker(pfs);
	pfs->status |= PFS_INITIALIZED;

	if (arg3 != NULL) {
		*arg3 = func00007084(pfs);
	}
#else

	ret = __osContRamRead(pfs->queue, pfs->channel, 7, pfs->label);

	if (ret != 0) {
		return ret;
	}

	crashPrint("pfsinitpak.c -> ret = %d\n", ret);
	ret = osPfsChecker(pfs);
	pfs->status |= PFS_INITIALIZED;
#endif

	return ret;
}

s32 __osPfsCheckRamArea(OSPfs* pfs)
{
	s32 i = 0;
	s32 ret = 0;
	u8 temp1[BLOCKSIZE];
	u8 temp2[BLOCKSIZE];
	u8 saveReg[BLOCKSIZE];

	if ((ret = __osPfsSelectBank(pfs, 0)) != 0) {
		return ret;
	}

	if ((ret = __osContRamRead(pfs->queue, pfs->channel, 0, saveReg)) != 0) {
		return ret;
	}

	for (i = 0; i < BLOCKSIZE; i++) {
		temp1[i] = i;
	}

	if ((ret = __osContRamWrite(pfs->queue, pfs->channel, 0, temp1, 0)) != 0) {
		return ret;
	}

	if ((ret = __osContRamRead(pfs->queue, pfs->channel, 0, temp2)) != 0) {
		return ret;
	}

	if (bcmp(temp1, temp2, BLOCKSIZE) != 0) {
		return PFS_ERR_DEVICE;
	}

	return __osContRamWrite(pfs->queue, pfs->channel, 0, saveReg, 0);
}

#if VERSION >= VERSION_NTSC_1_0
GLOBAL_ASM(
glabel func00007084
/*     7084:	27bdffc8 */ 	addiu	$sp,$sp,-56
/*     7088:	afbf0014 */ 	sw	$ra,0x14($sp)
/*     708c:	afa40038 */ 	sw	$a0,0x38($sp)
/*     7090:	00807025 */ 	or	$t6,$a0,$zero
/*     7094:	8dc50008 */ 	lw	$a1,0x8($t6)
/*     7098:	8c840004 */ 	lw	$a0,0x4($a0)
/*     709c:	27a70018 */ 	addiu	$a3,$sp,0x18
/*     70a0:	0c012e18 */ 	jal	__osContRamRead
/*     70a4:	24060001 */ 	addiu	$a2,$zero,0x1
/*     70a8:	10400003 */ 	beqz	$v0,.L000070b8
/*     70ac:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*     70b0:	10000002 */ 	b	.L000070bc
/*     70b4:	00001025 */ 	or	$v0,$zero,$zero
.L000070b8:
/*     70b8:	8fa2001c */ 	lw	$v0,0x1c($sp)
.L000070bc:
/*     70bc:	03e00008 */ 	jr	$ra
/*     70c0:	27bd0038 */ 	addiu	$sp,$sp,0x38
);
#else
GLOBAL_ASM(
glabel func00007084
/*     71a0:	03e00008 */ 	jr	$ra
/*     71a4:	00000000 */ 	sll	$zero,$zero,0x0
);
#endif
