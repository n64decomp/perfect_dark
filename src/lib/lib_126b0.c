#include <ultra64.h>
#include "constants.h"
#include "bss.h"
#include "lib/lib_126b0.h"
#include "data.h"
#include "types.h"

u32 var80099470;
u32 var80099474;
u32 var80099478[249];
u32 var8009985c;
u32 var80099860;
u32 var80099864;
u32 var80099868;
u32 var8009986c;
u32 var80099870;

GLOBAL_ASM(
glabel func000126b0
/*    126b0:	8cae0000 */ 	lw	$t6,0x0($a1)
/*    126b4:	8c820000 */ 	lw	$v0,0x0($a0)
/*    126b8:	8c830004 */ 	lw	$v1,0x4($a0)
/*    126bc:	ac8e0000 */ 	sw	$t6,0x0($a0)
/*    126c0:	8caf0004 */ 	lw	$t7,0x4($a1)
/*    126c4:	ac8f0004 */ 	sw	$t7,0x4($a0)
/*    126c8:	aca20000 */ 	sw	$v0,0x0($a1)
/*    126cc:	03e00008 */ 	jr	$ra
/*    126d0:	aca30004 */ 	sw	$v1,0x4($a1)
);

GLOBAL_ASM(
glabel func000126d4
/*    126d4:	8c8e0004 */ 	lw	$t6,0x4($a0)
/*    126d8:	8caf0004 */ 	lw	$t7,0x4($a1)
/*    126dc:	01cfc021 */ 	addu	$t8,$t6,$t7
/*    126e0:	ac980004 */ 	sw	$t8,0x4($a0)
/*    126e4:	aca00000 */ 	sw	$zero,0x0($a1)
/*    126e8:	03e00008 */ 	jr	$ra
/*    126ec:	aca00004 */ 	sw	$zero,0x4($a1)
);

GLOBAL_ASM(
glabel func000126f0
/*    126f0:	27bdffd0 */ 	addiu	$sp,$sp,-48
/*    126f4:	afb40028 */ 	sw	$s4,0x28($sp)
/*    126f8:	afb00018 */ 	sw	$s0,0x18($sp)
/*    126fc:	2490000c */ 	addiu	$s0,$a0,0xc
/*    12700:	249403e4 */ 	addiu	$s4,$a0,0x3e4
/*    12704:	afb30024 */ 	sw	$s3,0x24($sp)
/*    12708:	afb20020 */ 	sw	$s2,0x20($sp)
/*    1270c:	afb1001c */ 	sw	$s1,0x1c($sp)
/*    12710:	0290082b */ 	sltu	$at,$s4,$s0
/*    12714:	afbf002c */ 	sw	$ra,0x2c($sp)
/*    12718:	00009825 */ 	or	$s3,$zero,$zero
/*    1271c:	24910004 */ 	addiu	$s1,$a0,0x4
/*    12720:	1420001c */ 	bnez	$at,.L00012794
/*    12724:	00009025 */ 	or	$s2,$zero,$zero
/*    12728:	8e0e0004 */ 	lw	$t6,0x4($s0)
.L0001272c:
/*    1272c:	51c00016 */ 	beqzl	$t6,.L00012788
/*    12730:	26100008 */ 	addiu	$s0,$s0,0x8
/*    12734:	8e020000 */ 	lw	$v0,0x0($s0)
/*    12738:	02002025 */ 	or	$a0,$s0,$zero
/*    1273c:	0052082b */ 	sltu	$at,$v0,$s2
/*    12740:	50200005 */ 	beqzl	$at,.L00012758
/*    12744:	8e2f0004 */ 	lw	$t7,0x4($s1)
/*    12748:	0c0049ac */ 	jal	func000126b0
/*    1274c:	02202825 */ 	or	$a1,$s1,$zero
/*    12750:	8e020000 */ 	lw	$v0,0x0($s0)
/*    12754:	8e2f0004 */ 	lw	$t7,0x4($s1)
.L00012758:
/*    12758:	02202025 */ 	or	$a0,$s1,$zero
/*    1275c:	02002825 */ 	or	$a1,$s0,$zero
/*    12760:	01f2c021 */ 	addu	$t8,$t7,$s2
/*    12764:	54580006 */ 	bnel	$v0,$t8,.L00012780
/*    12768:	02008825 */ 	or	$s1,$s0,$zero
/*    1276c:	0c0049b5 */ 	jal	func000126d4
/*    12770:	24130001 */ 	addiu	$s3,$zero,0x1
/*    12774:	02208025 */ 	or	$s0,$s1,$zero
/*    12778:	8e220000 */ 	lw	$v0,0x0($s1)
/*    1277c:	02008825 */ 	or	$s1,$s0,$zero
.L00012780:
/*    12780:	00409025 */ 	or	$s2,$v0,$zero
/*    12784:	26100008 */ 	addiu	$s0,$s0,0x8
.L00012788:
/*    12788:	0290082b */ 	sltu	$at,$s4,$s0
/*    1278c:	5020ffe7 */ 	beqzl	$at,.L0001272c
/*    12790:	8e0e0004 */ 	lw	$t6,0x4($s0)
.L00012794:
/*    12794:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*    12798:	02601025 */ 	or	$v0,$s3,$zero
/*    1279c:	8fb30024 */ 	lw	$s3,0x24($sp)
/*    127a0:	8fb00018 */ 	lw	$s0,0x18($sp)
/*    127a4:	8fb1001c */ 	lw	$s1,0x1c($sp)
/*    127a8:	8fb20020 */ 	lw	$s2,0x20($sp)
/*    127ac:	8fb40028 */ 	lw	$s4,0x28($sp)
/*    127b0:	03e00008 */ 	jr	$ra
/*    127b4:	27bd0030 */ 	addiu	$sp,$sp,0x30
);

GLOBAL_ASM(
glabel func000127b8
/*    127b8:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*    127bc:	afb00018 */ 	sw	$s0,0x18($sp)
/*    127c0:	3c10800a */ 	lui	$s0,%hi(var80099478)
/*    127c4:	26109478 */ 	addiu	$s0,$s0,%lo(var80099478)
/*    127c8:	afbf001c */ 	sw	$ra,0x1c($sp)
/*    127cc:	0c0049bc */ 	jal	func000126f0
/*    127d0:	02002025 */ 	or	$a0,$s0,$zero
/*    127d4:	50400006 */ 	beqzl	$v0,.L000127f0
/*    127d8:	8fbf001c */ 	lw	$ra,0x1c($sp)
.L000127dc:
/*    127dc:	0c0049bc */ 	jal	func000126f0
/*    127e0:	02002025 */ 	or	$a0,$s0,$zero
/*    127e4:	1440fffd */ 	bnez	$v0,.L000127dc
/*    127e8:	00000000 */ 	nop
/*    127ec:	8fbf001c */ 	lw	$ra,0x1c($sp)
.L000127f0:
/*    127f0:	8fb00018 */ 	lw	$s0,0x18($sp)
/*    127f4:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*    127f8:	03e00008 */ 	jr	$ra
/*    127fc:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel func00012800
/*    12800:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*    12804:	afb2001c */ 	sw	$s2,0x1c($sp)
/*    12808:	afb30020 */ 	sw	$s3,0x20($sp)
/*    1280c:	afb10018 */ 	sw	$s1,0x18($sp)
/*    12810:	afb00014 */ 	sw	$s0,0x14($sp)
/*    12814:	2492000c */ 	addiu	$s2,$a0,0xc
/*    12818:	afbf0024 */ 	sw	$ra,0x24($sp)
/*    1281c:	02408025 */ 	or	$s0,$s2,$zero
/*    12820:	249103e4 */ 	addiu	$s1,$a0,0x3e4
/*    12824:	00009825 */ 	or	$s3,$zero,$zero
/*    12828:	0232082b */ 	sltu	$at,$s1,$s2
.L0001282c:
/*    1282c:	54200020 */ 	bnezl	$at,.L000128b0
/*    12830:	26730001 */ 	addiu	$s3,$s3,0x1
.L00012834:
/*    12834:	8e040004 */ 	lw	$a0,0x4($s0)
/*    12838:	26050008 */ 	addiu	$a1,$s0,0x8
/*    1283c:	54800004 */ 	bnezl	$a0,.L00012850
/*    12840:	8e020008 */ 	lw	$v0,0x8($s0)
/*    12844:	1000002c */ 	b	.L000128f8
/*    12848:	02001025 */ 	or	$v0,$s0,$zero
/*    1284c:	8e020008 */ 	lw	$v0,0x8($s0)
.L00012850:
/*    12850:	8e030000 */ 	lw	$v1,0x0($s0)
/*    12854:	0043082b */ 	sltu	$at,$v0,$v1
/*    12858:	50200007 */ 	beqzl	$at,.L00012878
/*    1285c:	00647021 */ 	addu	$t6,$v1,$a0
/*    12860:	0c0049ac */ 	jal	func000126b0
/*    12864:	02002025 */ 	or	$a0,$s0,$zero
/*    12868:	8e040004 */ 	lw	$a0,0x4($s0)
/*    1286c:	8e020008 */ 	lw	$v0,0x8($s0)
/*    12870:	8e030000 */ 	lw	$v1,0x0($s0)
/*    12874:	00647021 */ 	addu	$t6,$v1,$a0
.L00012878:
/*    12878:	144e0008 */ 	bne	$v0,$t6,.L0001289c
/*    1287c:	26050008 */ 	addiu	$a1,$s0,0x8
/*    12880:	8e0f000c */ 	lw	$t7,0xc($s0)
/*    12884:	ae000008 */ 	sw	$zero,0x8($s0)
/*    12888:	ae00000c */ 	sw	$zero,0xc($s0)
/*    1288c:	008fc021 */ 	addu	$t8,$a0,$t7
/*    12890:	ae180004 */ 	sw	$t8,0x4($s0)
/*    12894:	10000018 */ 	b	.L000128f8
/*    12898:	00a01025 */ 	or	$v0,$a1,$zero
.L0001289c:
/*    1289c:	0225082b */ 	sltu	$at,$s1,$a1
/*    128a0:	1020ffe4 */ 	beqz	$at,.L00012834
/*    128a4:	00a08025 */ 	or	$s0,$a1,$zero
/*    128a8:	02408025 */ 	or	$s0,$s2,$zero
/*    128ac:	26730001 */ 	addiu	$s3,$s3,0x1
.L000128b0:
/*    128b0:	2a61007c */ 	slti	$at,$s3,0x7c
/*    128b4:	5420ffdd */ 	bnezl	$at,.L0001282c
/*    128b8:	0232082b */ 	sltu	$at,$s1,$s2
/*    128bc:	0232082b */ 	sltu	$at,$s1,$s2
/*    128c0:	2402ffff */ 	addiu	$v0,$zero,-1
/*    128c4:	1420000b */ 	bnez	$at,.L000128f4
/*    128c8:	02401825 */ 	or	$v1,$s2,$zero
/*    128cc:	8e040004 */ 	lw	$a0,0x4($s0)
.L000128d0:
/*    128d0:	0082082b */ 	sltu	$at,$a0,$v0
/*    128d4:	50200004 */ 	beqzl	$at,.L000128e8
/*    128d8:	26100008 */ 	addiu	$s0,$s0,0x8
/*    128dc:	02001825 */ 	or	$v1,$s0,$zero
/*    128e0:	00801025 */ 	or	$v0,$a0,$zero
/*    128e4:	26100008 */ 	addiu	$s0,$s0,0x8
.L000128e8:
/*    128e8:	0230082b */ 	sltu	$at,$s1,$s0
/*    128ec:	5020fff8 */ 	beqzl	$at,.L000128d0
/*    128f0:	8e040004 */ 	lw	$a0,0x4($s0)
.L000128f4:
/*    128f4:	00601025 */ 	or	$v0,$v1,$zero
.L000128f8:
/*    128f8:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*    128fc:	8fb00014 */ 	lw	$s0,0x14($sp)
/*    12900:	8fb10018 */ 	lw	$s1,0x18($sp)
/*    12904:	8fb2001c */ 	lw	$s2,0x1c($sp)
/*    12908:	8fb30020 */ 	lw	$s3,0x20($sp)
/*    1290c:	03e00008 */ 	jr	$ra
/*    12910:	27bd0028 */ 	addiu	$sp,$sp,0x28
);

GLOBAL_ASM(
glabel func00012914
/*    12914:	3c0f800a */ 	lui	$t7,%hi(var80099470)
/*    12918:	8def9470 */ 	lw	$t7,%lo(var80099470)($t7)
/*    1291c:	3c09800a */ 	lui	$t1,%hi(var80099474)
/*    12920:	8d299474 */ 	lw	$t1,%lo(var80099474)($t1)
/*    12924:	008fc023 */ 	subu	$t8,$a0,$t7
/*    12928:	0018c940 */ 	sll	$t9,$t8,0x5
/*    1292c:	0338c823 */ 	subu	$t9,$t9,$t8
/*    12930:	0019c880 */ 	sll	$t9,$t9,0x2
/*    12934:	0329001a */ 	div	$zero,$t9,$t1
/*    12938:	00003012 */ 	mflo	$a2
/*    1293c:	3c0b800a */ 	lui	$t3,%hi(var80099478)
/*    12940:	256b9478 */ 	addiu	$t3,$t3,%lo(var80099478)
/*    12944:	000650c0 */ 	sll	$t2,$a2,0x3
/*    12948:	014b1021 */ 	addu	$v0,$t2,$t3
/*    1294c:	8c480010 */ 	lw	$t0,0x10($v0)
/*    12950:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*    12954:	2447000c */ 	addiu	$a3,$v0,0xc
/*    12958:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    1295c:	afa40018 */ 	sw	$a0,0x18($sp)
/*    12960:	afa5001c */ 	sw	$a1,0x1c($sp)
/*    12964:	00807025 */ 	or	$t6,$a0,$zero
/*    12968:	15200002 */ 	bnez	$t1,.L00012974
/*    1296c:	00000000 */ 	nop
/*    12970:	0007000d */ 	break	0x7
.L00012974:
/*    12974:	2401ffff */ 	addiu	$at,$zero,-1
/*    12978:	15210004 */ 	bne	$t1,$at,.L0001298c
/*    1297c:	3c018000 */ 	lui	$at,0x8000
/*    12980:	17210002 */ 	bne	$t9,$at,.L0001298c
/*    12984:	00000000 */ 	nop
/*    12988:	0006000d */ 	break	0x6
.L0001298c:
/*    1298c:	00e01825 */ 	or	$v1,$a3,$zero
/*    12990:	51000006 */ 	beqzl	$t0,.L000129ac
/*    12994:	8c6d0000 */ 	lw	$t5,0x0($v1)
/*    12998:	8c6c000c */ 	lw	$t4,0xc($v1)
.L0001299c:
/*    1299c:	24630008 */ 	addiu	$v1,$v1,0x8
/*    129a0:	5580fffe */ 	bnezl	$t4,.L0001299c
/*    129a4:	8c6c000c */ 	lw	$t4,0xc($v1)
/*    129a8:	8c6d0000 */ 	lw	$t5,0x0($v1)
.L000129ac:
/*    129ac:	2401ffff */ 	addiu	$at,$zero,-1
/*    129b0:	55a1000f */ 	bnel	$t5,$at,.L000129f0
/*    129b4:	8fb80018 */ 	lw	$t8,0x18($sp)
/*    129b8:	11000005 */ 	beqz	$t0,.L000129d0
/*    129bc:	00e01825 */ 	or	$v1,$a3,$zero
/*    129c0:	8c6efffc */ 	lw	$t6,-0x4($v1)
.L000129c4:
/*    129c4:	2463fff8 */ 	addiu	$v1,$v1,-8
/*    129c8:	55c0fffe */ 	bnezl	$t6,.L000129c4
/*    129cc:	8c6efffc */ 	lw	$t6,-0x4($v1)
.L000129d0:
/*    129d0:	8c6f0000 */ 	lw	$t7,0x0($v1)
/*    129d4:	3c04800a */ 	lui	$a0,%hi(var80099478)
/*    129d8:	55e00005 */ 	bnezl	$t7,.L000129f0
/*    129dc:	8fb80018 */ 	lw	$t8,0x18($sp)
/*    129e0:	0c004a00 */ 	jal	func00012800
/*    129e4:	24849478 */ 	addiu	$a0,$a0,%lo(var80099478)
/*    129e8:	00401825 */ 	or	$v1,$v0,$zero
/*    129ec:	8fb80018 */ 	lw	$t8,0x18($sp)
.L000129f0:
/*    129f0:	ac780000 */ 	sw	$t8,0x0($v1)
/*    129f4:	8fb9001c */ 	lw	$t9,0x1c($sp)
/*    129f8:	ac790004 */ 	sw	$t9,0x4($v1)
/*    129fc:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    12a00:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*    12a04:	03e00008 */ 	jr	$ra
/*    12a08:	00000000 */ 	nop
);

void func00012a0c(void)
{
	// empty
}

#if VERSION >= VERSION_NTSC_1_0
GLOBAL_ASM(
glabel func00012a14
/*    12a14:	3c03800a */ 	lui	$v1,%hi(var80099478)
/*    12a18:	24639478 */ 	addiu	$v1,$v1,%lo(var80099478)
/*    12a1c:	2406ffff */ 	addiu	$a2,$zero,-1
/*    12a20:	ac6603ec */ 	sw	$a2,0x3ec($v1)
/*    12a24:	ac6603f4 */ 	sw	$a2,0x3f4($v1)
/*    12a28:	240effff */ 	addiu	$t6,$zero,-1
/*    12a2c:	3c06800a */ 	lui	$a2,%hi(var8009985c)
/*    12a30:	3c02800a */ 	lui	$v0,%hi(var80099478+0xc)
/*    12a34:	24a508e0 */ 	addiu	$a1,$a1,0x8e0
/*    12a38:	ac600000 */ 	sw	$zero,0x0($v1)
/*    12a3c:	ac600004 */ 	sw	$zero,0x4($v1)
/*    12a40:	ac600008 */ 	sw	$zero,0x8($v1)
/*    12a44:	ac6003f0 */ 	sw	$zero,0x3f0($v1)
/*    12a48:	ac6e03f8 */ 	sw	$t6,0x3f8($v1)
/*    12a4c:	24429484 */ 	addiu	$v0,$v0,%lo(var80099478+0xc)
/*    12a50:	24c6985c */ 	addiu	$a2,$a2,%lo(var8009985c)
.L00012a54:
/*    12a54:	24420008 */ 	addiu	$v0,$v0,0x8
/*    12a58:	00c2082b */ 	sltu	$at,$a2,$v0
/*    12a5c:	ac40fff8 */ 	sw	$zero,-0x8($v0)
/*    12a60:	1020fffc */ 	beqz	$at,.L00012a54
/*    12a64:	ac40fffc */ 	sw	$zero,-0x4($v0)
/*    12a68:	3c02800a */ 	lui	$v0,%hi(var80099470)
/*    12a6c:	3c06800a */ 	lui	$a2,%hi(var80099474)
/*    12a70:	24c69474 */ 	addiu	$a2,$a2,%lo(var80099474)
/*    12a74:	24429470 */ 	addiu	$v0,$v0,%lo(var80099470)
/*    12a78:	ac440000 */ 	sw	$a0,0x0($v0)
/*    12a7c:	ac64000c */ 	sw	$a0,0xc($v1)
/*    12a80:	acc50000 */ 	sw	$a1,0x0($a2)
/*    12a84:	03e00008 */ 	jr	$ra
/*    12a88:	ac650010 */ 	sw	$a1,0x10($v1)
);
#else
GLOBAL_ASM(
glabel func00012a14
/*    12fb4:	3c03800a */ 	lui	$v1,0x800a
/*    12fb8:	2463c3f8 */ 	addiu	$v1,$v1,-15368
/*    12fbc:	2406ffff */ 	addiu	$a2,$zero,-1
/*    12fc0:	ac6603ec */ 	sw	$a2,0x3ec($v1)
/*    12fc4:	ac6603f4 */ 	sw	$a2,0x3f4($v1)
/*    12fc8:	240effff */ 	addiu	$t6,$zero,-1
/*    12fcc:	3c06800a */ 	lui	$a2,0x800a
/*    12fd0:	3c02800a */ 	lui	$v0,0x800a
/*    12fd4:	ac600000 */ 	sw	$zero,0x0($v1)
/*    12fd8:	ac600004 */ 	sw	$zero,0x4($v1)
/*    12fdc:	ac600008 */ 	sw	$zero,0x8($v1)
/*    12fe0:	ac6003f0 */ 	sw	$zero,0x3f0($v1)
/*    12fe4:	ac6e03f8 */ 	sw	$t6,0x3f8($v1)
/*    12fe8:	2442c404 */ 	addiu	$v0,$v0,-15356
/*    12fec:	24c6c7dc */ 	addiu	$a2,$a2,-14372
.NB00012ff0:
/*    12ff0:	24420008 */ 	addiu	$v0,$v0,0x8
/*    12ff4:	00c2082b */ 	sltu	$at,$a2,$v0
/*    12ff8:	ac40fff8 */ 	sw	$zero,-0x8($v0)
/*    12ffc:	1020fffc */ 	beqz	$at,.NB00012ff0
/*    13000:	ac40fffc */ 	sw	$zero,-0x4($v0)
/*    13004:	3c02800a */ 	lui	$v0,0x800a
/*    13008:	3c06800a */ 	lui	$a2,0x800a
/*    1300c:	24c6c3f4 */ 	addiu	$a2,$a2,-15372
/*    13010:	2442c3f0 */ 	addiu	$v0,$v0,-15376
/*    13014:	ac440000 */ 	sw	$a0,0x0($v0)
/*    13018:	ac64000c */ 	sw	$a0,0xc($v1)
/*    1301c:	acc50000 */ 	sw	$a1,0x0($a2)
/*    13020:	03e00008 */ 	jr	$ra
/*    13024:	ac650010 */ 	sw	$a1,0x10($v1)
);
#endif

#if VERSION >= VERSION_NTSC_1_0
GLOBAL_ASM(
glabel func00012a8c
/*    12a8c:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*    12a90:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    12a94:	3c04800a */ 	lui	$a0,%hi(var80099478)
/*    12a98:	0c0049bc */ 	jal	func000126f0
/*    12a9c:	24849478 */ 	addiu	$a0,$a0,%lo(var80099478)
/*    12aa0:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    12aa4:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*    12aa8:	03e00008 */ 	jr	$ra
/*    12aac:	00000000 */ 	nop
);
#else
GLOBAL_ASM(
glabel func00012a8c
/*    13028:	27bdff48 */ 	addiu	$sp,$sp,-184
/*    1302c:	afbf001c */ 	sw	$ra,0x1c($sp)
/*    13030:	3c04800a */ 	lui	$a0,0x800a
/*    13034:	afb00018 */ 	sw	$s0,0x18($sp)
/*    13038:	0c004b24 */ 	jal	func000126f0
/*    1303c:	2484c3f8 */ 	addiu	$a0,$a0,-15368
/*    13040:	0fc466e4 */ 	jal	debug0f119b90nb
/*    13044:	00000000 */ 	sll	$zero,$zero,0x0
/*    13048:	104000b1 */ 	beqz	$v0,.NB00013310
/*    1304c:	240400ff */ 	addiu	$a0,$zero,0xff
/*    13050:	240500ff */ 	addiu	$a1,$zero,0xff
/*    13054:	240600ff */ 	addiu	$a2,$zero,0xff
/*    13058:	0c005106 */ 	jal	func000137bc
/*    1305c:	240700ff */ 	addiu	$a3,$zero,0xff
/*    13060:	00002025 */ 	or	$a0,$zero,$zero
/*    13064:	00002825 */ 	or	$a1,$zero,$zero
/*    13068:	00003025 */ 	or	$a2,$zero,$zero
/*    1306c:	0c005115 */ 	jal	func000137d0
/*    13070:	240700ff */ 	addiu	$a3,$zero,0xff
/*    13074:	2404001e */ 	addiu	$a0,$zero,0x1e
/*    13078:	0c0050df */ 	jal	func000137b0
/*    1307c:	24050001 */ 	addiu	$a1,$zero,0x1
/*    13080:	3c047005 */ 	lui	$a0,0x7005
/*    13084:	0c005175 */ 	jal	func000137fc
/*    13088:	24845730 */ 	addiu	$a0,$a0,0x5730
/*    1308c:	24100002 */ 	addiu	$s0,$zero,0x2
/*    13090:	02002825 */ 	or	$a1,$s0,$zero
/*    13094:	0c0050df */ 	jal	func000137b0
/*    13098:	2404001e */ 	addiu	$a0,$zero,0x1e
/*    1309c:	3c047005 */ 	lui	$a0,0x7005
/*    130a0:	0c005175 */ 	jal	func000137fc
/*    130a4:	2484573c */ 	addiu	$a0,$a0,0x573c
/*    130a8:	26100001 */ 	addiu	$s0,$s0,0x1
/*    130ac:	24040004 */ 	addiu	$a0,$zero,0x4
/*    130b0:	0c004a7c */ 	jal	memGetFree
/*    130b4:	00002825 */ 	or	$a1,$zero,$zero
/*    130b8:	afa200b4 */ 	sw	$v0,0xb4($sp)
/*    130bc:	24040004 */ 	addiu	$a0,$zero,0x4
/*    130c0:	0c004a7c */ 	jal	memGetFree
/*    130c4:	24050001 */ 	addiu	$a1,$zero,0x1
/*    130c8:	3c057005 */ 	lui	$a1,0x7005
/*    130cc:	24a5574c */ 	addiu	$a1,$a1,0x574c
/*    130d0:	27a4002c */ 	addiu	$a0,$sp,0x2c
/*    130d4:	8fa600b4 */ 	lw	$a2,0xb4($sp)
/*    130d8:	0c004fc1 */ 	jal	sprintf
/*    130dc:	00403825 */ 	or	$a3,$v0,$zero
/*    130e0:	2404001f */ 	addiu	$a0,$zero,0x1f
/*    130e4:	0c0050df */ 	jal	func000137b0
/*    130e8:	02002825 */ 	or	$a1,$s0,$zero
/*    130ec:	0c005175 */ 	jal	func000137fc
/*    130f0:	27a4002c */ 	addiu	$a0,$sp,0x2c
/*    130f4:	26100001 */ 	addiu	$s0,$s0,0x1
/*    130f8:	24040004 */ 	addiu	$a0,$zero,0x4
/*    130fc:	0c004a91 */ 	jal	func00012a44nb
/*    13100:	00002825 */ 	or	$a1,$zero,$zero
/*    13104:	afa200b4 */ 	sw	$v0,0xb4($sp)
/*    13108:	24040004 */ 	addiu	$a0,$zero,0x4
/*    1310c:	0c004a91 */ 	jal	func00012a44nb
/*    13110:	24050001 */ 	addiu	$a1,$zero,0x1
/*    13114:	3c057005 */ 	lui	$a1,0x7005
/*    13118:	24a55758 */ 	addiu	$a1,$a1,0x5758
/*    1311c:	27a4002c */ 	addiu	$a0,$sp,0x2c
/*    13120:	8fa600b4 */ 	lw	$a2,0xb4($sp)
/*    13124:	0c004fc1 */ 	jal	sprintf
/*    13128:	00403825 */ 	or	$a3,$v0,$zero
/*    1312c:	2404001f */ 	addiu	$a0,$zero,0x1f
/*    13130:	0c0050df */ 	jal	func000137b0
/*    13134:	02002825 */ 	or	$a1,$s0,$zero
/*    13138:	0c005175 */ 	jal	func000137fc
/*    1313c:	27a4002c */ 	addiu	$a0,$sp,0x2c
/*    13140:	26100001 */ 	addiu	$s0,$s0,0x1
/*    13144:	24040004 */ 	addiu	$a0,$zero,0x4
/*    13148:	0c004a7c */ 	jal	memGetFree
/*    1314c:	24050001 */ 	addiu	$a1,$zero,0x1
/*    13150:	afa20024 */ 	sw	$v0,0x24($sp)
/*    13154:	24040004 */ 	addiu	$a0,$zero,0x4
/*    13158:	0c004a91 */ 	jal	func00012a44nb
/*    1315c:	24050001 */ 	addiu	$a1,$zero,0x1
/*    13160:	afa20028 */ 	sw	$v0,0x28($sp)
/*    13164:	24040004 */ 	addiu	$a0,$zero,0x4
/*    13168:	0c004a7c */ 	jal	memGetFree
/*    1316c:	00002825 */ 	or	$a1,$zero,$zero
/*    13170:	8fae0028 */ 	lw	$t6,0x28($sp)
/*    13174:	8faf0024 */ 	lw	$t7,0x24($sp)
/*    13178:	01cfc023 */ 	subu	$t8,$t6,$t7
/*    1317c:	03021823 */ 	subu	$v1,$t8,$v0
/*    13180:	04600008 */ 	bltz	$v1,.NB000131a4
/*    13184:	00603825 */ 	or	$a3,$v1,$zero
/*    13188:	3c057005 */ 	lui	$a1,0x7005
/*    1318c:	24a55764 */ 	addiu	$a1,$a1,0x5764
/*    13190:	27a4002c */ 	addiu	$a0,$sp,0x2c
/*    13194:	0c004fc1 */ 	jal	sprintf
/*    13198:	00603025 */ 	or	$a2,$v1,$zero
/*    1319c:	10000007 */ 	beqz	$zero,.NB000131bc
/*    131a0:	2404001f */ 	addiu	$a0,$zero,0x1f
.NB000131a4:
/*    131a4:	3c057005 */ 	lui	$a1,0x7005
/*    131a8:	24a55770 */ 	addiu	$a1,$a1,0x5770
/*    131ac:	27a4002c */ 	addiu	$a0,$sp,0x2c
/*    131b0:	0c004fc1 */ 	jal	sprintf
/*    131b4:	00073023 */ 	negu	$a2,$a3
/*    131b8:	2404001f */ 	addiu	$a0,$zero,0x1f
.NB000131bc:
/*    131bc:	0c0050df */ 	jal	func000137b0
/*    131c0:	02002825 */ 	or	$a1,$s0,$zero
/*    131c4:	0c005175 */ 	jal	func000137fc
/*    131c8:	27a4002c */ 	addiu	$a0,$sp,0x2c
/*    131cc:	26100001 */ 	addiu	$s0,$s0,0x1
/*    131d0:	02002825 */ 	or	$a1,$s0,$zero
/*    131d4:	0c0050df */ 	jal	func000137b0
/*    131d8:	2404001e */ 	addiu	$a0,$zero,0x1e
/*    131dc:	3c047005 */ 	lui	$a0,0x7005
/*    131e0:	0c005175 */ 	jal	func000137fc
/*    131e4:	2484577c */ 	addiu	$a0,$a0,0x577c
/*    131e8:	26100001 */ 	addiu	$s0,$s0,0x1
/*    131ec:	24040006 */ 	addiu	$a0,$zero,0x6
/*    131f0:	0c004a7c */ 	jal	memGetFree
/*    131f4:	00002825 */ 	or	$a1,$zero,$zero
/*    131f8:	afa200b4 */ 	sw	$v0,0xb4($sp)
/*    131fc:	24040006 */ 	addiu	$a0,$zero,0x6
/*    13200:	0c004a7c */ 	jal	memGetFree
/*    13204:	24050001 */ 	addiu	$a1,$zero,0x1
/*    13208:	3c057005 */ 	lui	$a1,0x7005
/*    1320c:	24a55790 */ 	addiu	$a1,$a1,0x5790
/*    13210:	27a4002c */ 	addiu	$a0,$sp,0x2c
/*    13214:	8fa600b4 */ 	lw	$a2,0xb4($sp)
/*    13218:	0c004fc1 */ 	jal	sprintf
/*    1321c:	00403825 */ 	or	$a3,$v0,$zero
/*    13220:	2404001f */ 	addiu	$a0,$zero,0x1f
/*    13224:	0c0050df */ 	jal	func000137b0
/*    13228:	02002825 */ 	or	$a1,$s0,$zero
/*    1322c:	0c005175 */ 	jal	func000137fc
/*    13230:	27a4002c */ 	addiu	$a0,$sp,0x2c
/*    13234:	26100001 */ 	addiu	$s0,$s0,0x1
/*    13238:	24040006 */ 	addiu	$a0,$zero,0x6
/*    1323c:	0c004a91 */ 	jal	func00012a44nb
/*    13240:	00002825 */ 	or	$a1,$zero,$zero
/*    13244:	afa200b4 */ 	sw	$v0,0xb4($sp)
/*    13248:	24040006 */ 	addiu	$a0,$zero,0x6
/*    1324c:	0c004a91 */ 	jal	func00012a44nb
/*    13250:	24050001 */ 	addiu	$a1,$zero,0x1
/*    13254:	3c057005 */ 	lui	$a1,0x7005
/*    13258:	24a5579c */ 	addiu	$a1,$a1,0x579c
/*    1325c:	27a4002c */ 	addiu	$a0,$sp,0x2c
/*    13260:	8fa600b4 */ 	lw	$a2,0xb4($sp)
/*    13264:	0c004fc1 */ 	jal	sprintf
/*    13268:	00403825 */ 	or	$a3,$v0,$zero
/*    1326c:	2404001f */ 	addiu	$a0,$zero,0x1f
/*    13270:	0c0050df */ 	jal	func000137b0
/*    13274:	02002825 */ 	or	$a1,$s0,$zero
/*    13278:	0c005175 */ 	jal	func000137fc
/*    1327c:	27a4002c */ 	addiu	$a0,$sp,0x2c
/*    13280:	26100001 */ 	addiu	$s0,$s0,0x1
/*    13284:	02002825 */ 	or	$a1,$s0,$zero
/*    13288:	0c0050df */ 	jal	func000137b0
/*    1328c:	2404001e */ 	addiu	$a0,$zero,0x1e
/*    13290:	3c047005 */ 	lui	$a0,0x7005
/*    13294:	0c005175 */ 	jal	func000137fc
/*    13298:	248457a8 */ 	addiu	$a0,$a0,0x57a8
/*    1329c:	0c004d4e */ 	jal	func00012cdc
/*    132a0:	26100001 */ 	addiu	$s0,$s0,0x1
/*    132a4:	3c057005 */ 	lui	$a1,0x7005
/*    132a8:	24a557b0 */ 	addiu	$a1,$a1,0x57b0
/*    132ac:	27a4002c */ 	addiu	$a0,$sp,0x2c
/*    132b0:	0c004fc1 */ 	jal	sprintf
/*    132b4:	00403025 */ 	or	$a2,$v0,$zero
/*    132b8:	2404001f */ 	addiu	$a0,$zero,0x1f
/*    132bc:	0c0050df */ 	jal	func000137b0
/*    132c0:	02002825 */ 	or	$a1,$s0,$zero
/*    132c4:	0c005175 */ 	jal	func000137fc
/*    132c8:	27a4002c */ 	addiu	$a0,$sp,0x2c
/*    132cc:	3c02800a */ 	lui	$v0,0x800a
/*    132d0:	24428170 */ 	addiu	$v0,$v0,-32400
/*    132d4:	8c590008 */ 	lw	$t9,0x8($v0)
/*    132d8:	8c480004 */ 	lw	$t0,0x4($v0)
/*    132dc:	8c4a0000 */ 	lw	$t2,0x0($v0)
/*    132e0:	3c057005 */ 	lui	$a1,0x7005
/*    132e4:	03284823 */ 	subu	$t1,$t9,$t0
/*    132e8:	26100001 */ 	addiu	$s0,$s0,0x1
/*    132ec:	24a557b8 */ 	addiu	$a1,$a1,0x57b8
/*    132f0:	27a4002c */ 	addiu	$a0,$sp,0x2c
/*    132f4:	0c004fc1 */ 	jal	sprintf
/*    132f8:	012a3021 */ 	addu	$a2,$t1,$t2
/*    132fc:	2404001e */ 	addiu	$a0,$zero,0x1e
/*    13300:	0c0050df */ 	jal	func000137b0
/*    13304:	02002825 */ 	or	$a1,$s0,$zero
/*    13308:	0c005175 */ 	jal	func000137fc
/*    1330c:	27a4002c */ 	addiu	$a0,$sp,0x2c
.NB00013310:
/*    13310:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*    13314:	8fb00018 */ 	lw	$s0,0x18($sp)
/*    13318:	27bd00b8 */ 	addiu	$sp,$sp,0xb8
/*    1331c:	03e00008 */ 	jr	$ra
/*    13320:	00000000 */ 	sll	$zero,$zero,0x0
);
#endif

#if VERSION >= VERSION_NTSC_1_0
GLOBAL_ASM(
glabel func00012ab0
/*    12ab0:	27bdffd0 */ 	addiu	$sp,$sp,-48
/*    12ab4:	afb2001c */ 	sw	$s2,0x1c($sp)
/*    12ab8:	afb10018 */ 	sw	$s1,0x18($sp)
/*    12abc:	00809025 */ 	or	$s2,$a0,$zero
/*    12ac0:	afb50028 */ 	sw	$s5,0x28($sp)
/*    12ac4:	afb00014 */ 	sw	$s0,0x14($sp)
/*    12ac8:	3c11800a */ 	lui	$s1,%hi(var80099478+0xc)
/*    12acc:	3c078009 */ 	lui	$a3,%hi(g_Is4Mb)
/*    12ad0:	afbf002c */ 	sw	$ra,0x2c($sp)
/*    12ad4:	afb40024 */ 	sw	$s4,0x24($sp)
/*    12ad8:	afb30020 */ 	sw	$s3,0x20($sp)
/*    12adc:	26319484 */ 	addiu	$s1,$s1,%lo(var80099478+0xc)
/*    12ae0:	2404ffff */ 	addiu	$a0,$zero,-1
/*    12ae4:	00004025 */ 	or	$t0,$zero,$zero
/*    12ae8:	24e70af0 */ 	addiu	$a3,$a3,%lo(g_Is4Mb)
/*    12aec:	00008025 */ 	or	$s0,$zero,$zero
/*    12af0:	2415ffff */ 	addiu	$s5,$zero,-1
/*    12af4:	24060001 */ 	addiu	$a2,$zero,0x1
/*    12af8:	24050010 */ 	addiu	$a1,$zero,0x10
.L00012afc:
/*    12afc:	8e230004 */ 	lw	$v1,0x4($s1)
/*    12b00:	26100001 */ 	addiu	$s0,$s0,0x1
/*    12b04:	0072082b */ 	sltu	$at,$v1,$s2
/*    12b08:	14200011 */ 	bnez	$at,.L00012b50
/*    12b0c:	00721023 */ 	subu	$v0,$v1,$s2
/*    12b10:	8e2e0000 */ 	lw	$t6,0x0($s1)
/*    12b14:	0044082b */ 	sltu	$at,$v0,$a0
/*    12b18:	12ae000f */ 	beq	$s5,$t6,.L00012b58
/*    12b1c:	00000000 */ 	nop
/*    12b20:	1020000b */ 	beqz	$at,.L00012b50
/*    12b24:	2c410040 */ 	sltiu	$at,$v0,0x40
/*    12b28:	00402025 */ 	or	$a0,$v0,$zero
/*    12b2c:	1420000a */ 	bnez	$at,.L00012b58
/*    12b30:	02204025 */ 	or	$t0,$s1,$zero
/*    12b34:	90ef0000 */ 	lbu	$t7,0x0($a3)
/*    12b38:	0012c082 */ 	srl	$t8,$s2,0x2
/*    12b3c:	0058082b */ 	sltu	$at,$v0,$t8
/*    12b40:	10cf0003 */ 	beq	$a2,$t7,.L00012b50
/*    12b44:	00000000 */ 	nop
/*    12b48:	14200003 */ 	bnez	$at,.L00012b58
/*    12b4c:	00000000 */ 	nop
.L00012b50:
/*    12b50:	1605ffea */ 	bne	$s0,$a1,.L00012afc
/*    12b54:	26310008 */ 	addiu	$s1,$s1,0x8
.L00012b58:
/*    12b58:	55000027 */ 	bnezl	$t0,.L00012bf8
/*    12b5c:	8d030000 */ 	lw	$v1,0x0($t0)
/*    12b60:	8e390004 */ 	lw	$t9,0x4($s1)
/*    12b64:	00008025 */ 	or	$s0,$zero,$zero
/*    12b68:	24140008 */ 	addiu	$s4,$zero,0x8
/*    12b6c:	0332082b */ 	sltu	$at,$t9,$s2
/*    12b70:	10200006 */ 	beqz	$at,.L00012b8c
/*    12b74:	3c13800a */ 	lui	$s3,%hi(var80099478)
/*    12b78:	8e29000c */ 	lw	$t1,0xc($s1)
.L00012b7c:
/*    12b7c:	26310008 */ 	addiu	$s1,$s1,0x8
/*    12b80:	0132082b */ 	sltu	$at,$t1,$s2
/*    12b84:	5420fffd */ 	bnezl	$at,.L00012b7c
/*    12b88:	8e29000c */ 	lw	$t1,0xc($s1)
.L00012b8c:
/*    12b8c:	8e2a0000 */ 	lw	$t2,0x0($s1)
/*    12b90:	26739478 */ 	addiu	$s3,$s3,%lo(var80099478)
/*    12b94:	56aa0017 */ 	bnel	$s5,$t2,.L00012bf4
/*    12b98:	02204025 */ 	or	$t0,$s1,$zero
/*    12b9c:	3c11800a */ 	lui	$s1,%hi(var80099478+0xc)
/*    12ba0:	26319484 */ 	addiu	$s1,$s1,%lo(var80099478+0xc)
.L00012ba4:
/*    12ba4:	0c0049bc */ 	jal	func000126f0
/*    12ba8:	02602025 */ 	or	$a0,$s3,$zero
/*    12bac:	26100001 */ 	addiu	$s0,$s0,0x1
/*    12bb0:	1614fffc */ 	bne	$s0,$s4,.L00012ba4
/*    12bb4:	00000000 */ 	nop
/*    12bb8:	8e6b0010 */ 	lw	$t3,0x10($s3)
/*    12bbc:	0172082b */ 	sltu	$at,$t3,$s2
/*    12bc0:	50200007 */ 	beqzl	$at,.L00012be0
/*    12bc4:	8e2d0000 */ 	lw	$t5,0x0($s1)
/*    12bc8:	8e2c000c */ 	lw	$t4,0xc($s1)
.L00012bcc:
/*    12bcc:	26310008 */ 	addiu	$s1,$s1,0x8
/*    12bd0:	0192082b */ 	sltu	$at,$t4,$s2
/*    12bd4:	5420fffd */ 	bnezl	$at,.L00012bcc
/*    12bd8:	8e2c000c */ 	lw	$t4,0xc($s1)
/*    12bdc:	8e2d0000 */ 	lw	$t5,0x0($s1)
.L00012be0:
/*    12be0:	56ad0004 */ 	bnel	$s5,$t5,.L00012bf4
/*    12be4:	02204025 */ 	or	$t0,$s1,$zero
/*    12be8:	1000000b */ 	b	.L00012c18
/*    12bec:	00001025 */ 	or	$v0,$zero,$zero
/*    12bf0:	02204025 */ 	or	$t0,$s1,$zero
.L00012bf4:
/*    12bf4:	8d030000 */ 	lw	$v1,0x0($t0)
.L00012bf8:
/*    12bf8:	8d0f0004 */ 	lw	$t7,0x4($t0)
/*    12bfc:	00727021 */ 	addu	$t6,$v1,$s2
/*    12c00:	01f2c023 */ 	subu	$t8,$t7,$s2
/*    12c04:	ad0e0000 */ 	sw	$t6,0x0($t0)
/*    12c08:	17000002 */ 	bnez	$t8,.L00012c14
/*    12c0c:	ad180004 */ 	sw	$t8,0x4($t0)
/*    12c10:	ad000000 */ 	sw	$zero,0x0($t0)
.L00012c14:
/*    12c14:	00601025 */ 	or	$v0,$v1,$zero
.L00012c18:
/*    12c18:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*    12c1c:	8fb00014 */ 	lw	$s0,0x14($sp)
/*    12c20:	8fb10018 */ 	lw	$s1,0x18($sp)
/*    12c24:	8fb2001c */ 	lw	$s2,0x1c($sp)
/*    12c28:	8fb30020 */ 	lw	$s3,0x20($sp)
/*    12c2c:	8fb40024 */ 	lw	$s4,0x24($sp)
/*    12c30:	8fb50028 */ 	lw	$s5,0x28($sp)
/*    12c34:	03e00008 */ 	jr	$ra
/*    12c38:	27bd0030 */ 	addiu	$sp,$sp,0x30
);
#else
GLOBAL_ASM(
glabel func00012ab0
/*    13324:	27bdffd0 */ 	addiu	$sp,$sp,-48
/*    13328:	afb2001c */ 	sw	$s2,0x1c($sp)
/*    1332c:	afb10018 */ 	sw	$s1,0x18($sp)
/*    13330:	00809025 */ 	or	$s2,$a0,$zero
/*    13334:	afb50028 */ 	sw	$s5,0x28($sp)
/*    13338:	afb00014 */ 	sw	$s0,0x14($sp)
/*    1333c:	3c11800a */ 	lui	$s1,0x800a
/*    13340:	afbf002c */ 	sw	$ra,0x2c($sp)
/*    13344:	afb40024 */ 	sw	$s4,0x24($sp)
/*    13348:	afb30020 */ 	sw	$s3,0x20($sp)
/*    1334c:	2631c404 */ 	addiu	$s1,$s1,-15356
/*    13350:	2404ffff */ 	addiu	$a0,$zero,-1
/*    13354:	00002825 */ 	or	$a1,$zero,$zero
/*    13358:	00008025 */ 	or	$s0,$zero,$zero
/*    1335c:	2415ffff */ 	addiu	$s5,$zero,-1
/*    13360:	24060010 */ 	addiu	$a2,$zero,0x10
.NB00013364:
/*    13364:	8e230004 */ 	lw	$v1,0x4($s1)
/*    13368:	26100001 */ 	addiu	$s0,$s0,0x1
/*    1336c:	0072082b */ 	sltu	$at,$v1,$s2
/*    13370:	1420000e */ 	bnez	$at,.NB000133ac
/*    13374:	00721023 */ 	subu	$v0,$v1,$s2
/*    13378:	8e2e0000 */ 	lw	$t6,0x0($s1)
/*    1337c:	0044082b */ 	sltu	$at,$v0,$a0
/*    13380:	00127882 */ 	srl	$t7,$s2,0x2
/*    13384:	12ae000b */ 	beq	$s5,$t6,.NB000133b4
/*    13388:	00000000 */ 	sll	$zero,$zero,0x0
/*    1338c:	10200007 */ 	beqz	$at,.NB000133ac
/*    13390:	2c410040 */ 	sltiu	$at,$v0,0x40
/*    13394:	00402025 */ 	or	$a0,$v0,$zero
/*    13398:	14200006 */ 	bnez	$at,.NB000133b4
/*    1339c:	02202825 */ 	or	$a1,$s1,$zero
/*    133a0:	004f082b */ 	sltu	$at,$v0,$t7
/*    133a4:	14200003 */ 	bnez	$at,.NB000133b4
/*    133a8:	00000000 */ 	sll	$zero,$zero,0x0
.NB000133ac:
/*    133ac:	1606ffed */ 	bne	$s0,$a2,.NB00013364
/*    133b0:	26310008 */ 	addiu	$s1,$s1,0x8
.NB000133b4:
/*    133b4:	54a00027 */ 	bnezl	$a1,.NB00013454
/*    133b8:	8ca30000 */ 	lw	$v1,0x0($a1)
/*    133bc:	8e380004 */ 	lw	$t8,0x4($s1)
/*    133c0:	00008025 */ 	or	$s0,$zero,$zero
/*    133c4:	24140008 */ 	addiu	$s4,$zero,0x8
/*    133c8:	0312082b */ 	sltu	$at,$t8,$s2
/*    133cc:	10200006 */ 	beqz	$at,.NB000133e8
/*    133d0:	3c13800a */ 	lui	$s3,0x800a
/*    133d4:	8e39000c */ 	lw	$t9,0xc($s1)
.NB000133d8:
/*    133d8:	26310008 */ 	addiu	$s1,$s1,0x8
/*    133dc:	0332082b */ 	sltu	$at,$t9,$s2
/*    133e0:	5420fffd */ 	bnezl	$at,.NB000133d8
/*    133e4:	8e39000c */ 	lw	$t9,0xc($s1)
.NB000133e8:
/*    133e8:	8e280000 */ 	lw	$t0,0x0($s1)
/*    133ec:	2673c3f8 */ 	addiu	$s3,$s3,-15368
/*    133f0:	56a80017 */ 	bnel	$s5,$t0,.NB00013450
/*    133f4:	02202825 */ 	or	$a1,$s1,$zero
/*    133f8:	3c11800a */ 	lui	$s1,0x800a
/*    133fc:	2631c404 */ 	addiu	$s1,$s1,-15356
.NB00013400:
/*    13400:	0c004b24 */ 	jal	func000126f0
/*    13404:	02602025 */ 	or	$a0,$s3,$zero
/*    13408:	26100001 */ 	addiu	$s0,$s0,0x1
/*    1340c:	1614fffc */ 	bne	$s0,$s4,.NB00013400
/*    13410:	00000000 */ 	sll	$zero,$zero,0x0
/*    13414:	8e690010 */ 	lw	$t1,0x10($s3)
/*    13418:	0132082b */ 	sltu	$at,$t1,$s2
/*    1341c:	50200007 */ 	beqzl	$at,.NB0001343c
/*    13420:	8e2b0000 */ 	lw	$t3,0x0($s1)
/*    13424:	8e2a000c */ 	lw	$t2,0xc($s1)
.NB00013428:
/*    13428:	26310008 */ 	addiu	$s1,$s1,0x8
/*    1342c:	0152082b */ 	sltu	$at,$t2,$s2
/*    13430:	5420fffd */ 	bnezl	$at,.NB00013428
/*    13434:	8e2a000c */ 	lw	$t2,0xc($s1)
/*    13438:	8e2b0000 */ 	lw	$t3,0x0($s1)
.NB0001343c:
/*    1343c:	56ab0004 */ 	bnel	$s5,$t3,.NB00013450
/*    13440:	02202825 */ 	or	$a1,$s1,$zero
/*    13444:	1000000b */ 	beqz	$zero,.NB00013474
/*    13448:	00001025 */ 	or	$v0,$zero,$zero
/*    1344c:	02202825 */ 	or	$a1,$s1,$zero
.NB00013450:
/*    13450:	8ca30000 */ 	lw	$v1,0x0($a1)
.NB00013454:
/*    13454:	8cad0004 */ 	lw	$t5,0x4($a1)
/*    13458:	00726021 */ 	addu	$t4,$v1,$s2
/*    1345c:	01b27023 */ 	subu	$t6,$t5,$s2
/*    13460:	acac0000 */ 	sw	$t4,0x0($a1)
/*    13464:	15c00002 */ 	bnez	$t6,.NB00013470
/*    13468:	acae0004 */ 	sw	$t6,0x4($a1)
/*    1346c:	aca00000 */ 	sw	$zero,0x0($a1)
.NB00013470:
/*    13470:	00601025 */ 	or	$v0,$v1,$zero
.NB00013474:
/*    13474:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*    13478:	8fb00014 */ 	lw	$s0,0x14($sp)
/*    1347c:	8fb10018 */ 	lw	$s1,0x18($sp)
/*    13480:	8fb2001c */ 	lw	$s2,0x1c($sp)
/*    13484:	8fb30020 */ 	lw	$s3,0x20($sp)
/*    13488:	8fb40024 */ 	lw	$s4,0x24($sp)
/*    1348c:	8fb50028 */ 	lw	$s5,0x28($sp)
/*    13490:	03e00008 */ 	jr	$ra
/*    13494:	27bd0030 */ 	addiu	$sp,$sp,0x30
);
#endif

GLOBAL_ASM(
glabel func00012c3c
/*    12c3c:	3c0f800a */ 	lui	$t7,%hi(var80099478+0xc)
/*    12c40:	8def9484 */ 	lw	$t7,%lo(var80099478+0xc)($t7)
/*    12c44:	3c0e800a */ 	lui	$t6,%hi(var80099478+0xc)
/*    12c48:	2407ffff */ 	addiu	$a3,$zero,-1
/*    12c4c:	25ce9484 */ 	addiu	$t6,$t6,%lo(var80099478+0xc)
/*    12c50:	00a03025 */ 	or	$a2,$a1,$zero
/*    12c54:	10ef000c */ 	beq	$a3,$t7,.L00012c88
/*    12c58:	01c01025 */ 	or	$v0,$t6,$zero
/*    12c5c:	8dc30000 */ 	lw	$v1,0x0($t6)
.L00012c60:
/*    12c60:	54830006 */ 	bnel	$a0,$v1,.L00012c7c
/*    12c64:	8c430008 */ 	lw	$v1,0x8($v0)
/*    12c68:	8c450004 */ 	lw	$a1,0x4($v0)
/*    12c6c:	00a6082b */ 	sltu	$at,$a1,$a2
/*    12c70:	50200008 */ 	beqzl	$at,.L00012c94
/*    12c74:	0066c021 */ 	addu	$t8,$v1,$a2
/*    12c78:	8c430008 */ 	lw	$v1,0x8($v0)
.L00012c7c:
/*    12c7c:	24420008 */ 	addiu	$v0,$v0,0x8
/*    12c80:	14e3fff7 */ 	bne	$a3,$v1,.L00012c60
/*    12c84:	00000000 */ 	nop
.L00012c88:
/*    12c88:	03e00008 */ 	jr	$ra
/*    12c8c:	00001025 */ 	or	$v0,$zero,$zero
/*    12c90:	0066c021 */ 	addu	$t8,$v1,$a2
.L00012c94:
/*    12c94:	00a6c823 */ 	subu	$t9,$a1,$a2
/*    12c98:	ac580000 */ 	sw	$t8,0x0($v0)
/*    12c9c:	17200002 */ 	bnez	$t9,.L00012ca8
/*    12ca0:	ac590004 */ 	sw	$t9,0x4($v0)
/*    12ca4:	ac400000 */ 	sw	$zero,0x0($v0)
.L00012ca8:
/*    12ca8:	00801025 */ 	or	$v0,$a0,$zero
/*    12cac:	03e00008 */ 	jr	$ra
/*    12cb0:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel func00012cb4
/*    12cb4:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*    12cb8:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    12cbc:	0c004a45 */ 	jal	func00012914
/*    12cc0:	00000000 */ 	nop
/*    12cc4:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    12cc8:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*    12ccc:	03e00008 */ 	jr	$ra
/*    12cd0:	00000000 */ 	nop
/*    12cd4:	03e00008 */ 	jr	$ra
/*    12cd8:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel func00012cdc
/*    12cdc:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*    12ce0:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    12ce4:	0c0049ee */ 	jal	func000127b8
/*    12ce8:	afa00018 */ 	sw	$zero,0x18($sp)
/*    12cec:	3c0e800a */ 	lui	$t6,%hi(var80099478+0xc)
/*    12cf0:	8dce9484 */ 	lw	$t6,%lo(var80099478+0xc)($t6)
/*    12cf4:	2405ffff */ 	addiu	$a1,$zero,-1
/*    12cf8:	3c02800a */ 	lui	$v0,%hi(var80099478+0xc)
/*    12cfc:	8fa40018 */ 	lw	$a0,0x18($sp)
/*    12d00:	10ae000a */ 	beq	$a1,$t6,.L00012d2c
/*    12d04:	24429484 */ 	addiu	$v0,$v0,%lo(var80099478+0xc)
/*    12d08:	8c430004 */ 	lw	$v1,0x4($v0)
.L00012d0c:
/*    12d0c:	0083082b */ 	sltu	$at,$a0,$v1
/*    12d10:	50200003 */ 	beqzl	$at,.L00012d20
/*    12d14:	8c4f0008 */ 	lw	$t7,0x8($v0)
/*    12d18:	00602025 */ 	or	$a0,$v1,$zero
/*    12d1c:	8c4f0008 */ 	lw	$t7,0x8($v0)
.L00012d20:
/*    12d20:	24420008 */ 	addiu	$v0,$v0,0x8
/*    12d24:	54affff9 */ 	bnel	$a1,$t7,.L00012d0c
/*    12d28:	8c430004 */ 	lw	$v1,0x4($v0)
.L00012d2c:
/*    12d2c:	10800003 */ 	beqz	$a0,.L00012d3c
/*    12d30:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    12d34:	10000002 */ 	b	.L00012d40
/*    12d38:	00801025 */ 	or	$v0,$a0,$zero
.L00012d3c:
/*    12d3c:	00001025 */ 	or	$v0,$zero,$zero
.L00012d40:
/*    12d40:	03e00008 */ 	jr	$ra
/*    12d44:	27bd0020 */ 	addiu	$sp,$sp,0x20
);

GLOBAL_ASM(
glabel func00012d48
/*    12d48:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*    12d4c:	00a6082b */ 	sltu	$at,$a1,$a2
/*    12d50:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    12d54:	afa40018 */ 	sw	$a0,0x18($sp)
/*    12d58:	10200008 */ 	beqz	$at,.L00012d7c
/*    12d5c:	00a03825 */ 	or	$a3,$a1,$zero
/*    12d60:	00852021 */ 	addu	$a0,$a0,$a1
/*    12d64:	0c004b0f */ 	jal	func00012c3c
/*    12d68:	00c52823 */ 	subu	$a1,$a2,$a1
/*    12d6c:	5440000a */ 	bnezl	$v0,.L00012d98
/*    12d70:	24020001 */ 	addiu	$v0,$zero,0x1
/*    12d74:	10000008 */ 	b	.L00012d98
/*    12d78:	00001025 */ 	or	$v0,$zero,$zero
.L00012d7c:
/*    12d7c:	00c7082b */ 	sltu	$at,$a2,$a3
/*    12d80:	10200004 */ 	beqz	$at,.L00012d94
/*    12d84:	8faf0018 */ 	lw	$t7,0x18($sp)
/*    12d88:	01e62021 */ 	addu	$a0,$t7,$a2
/*    12d8c:	0c004b2d */ 	jal	func00012cb4
/*    12d90:	00e62823 */ 	subu	$a1,$a3,$a2
.L00012d94:
/*    12d94:	24020001 */ 	addiu	$v0,$zero,0x1
.L00012d98:
/*    12d98:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    12d9c:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*    12da0:	03e00008 */ 	jr	$ra
/*    12da4:	00000000 */ 	nop
/*    12da8:	3c02800a */ 	lui	$v0,%hi(var80099474)
/*    12dac:	03e00008 */ 	jr	$ra
/*    12db0:	8c429474 */ 	lw	$v0,%lo(var80099474)($v0)
);
