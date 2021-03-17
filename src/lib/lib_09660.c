#include <ultra64.h>
#include "constants.h"
#include "game/game_0b3350.h"
#include "game/game_0b69d0.h"
#include "game/file.h"
#include "game/game_176080.h"
#include "game/options.h"
#include "bss.h"
#include "lib/lib_09660.h"
#include "lib/memory.h"
#include "lib/lib_159b0.h"
#include "lib/lib_2faf0.h"
#include "lib/lib_30ce0.h"
#include "lib/lib_4b170.h"
#include "data.h"
#include "types.h"

u32 var8005d520 = 0;

u32 var80091900[4];
u32 var80091910[400];
u32 var80091f50[480];
OSMesgQueue var800926d0;
u32 var800926e8[80];
u32 var80092828;

GLOBAL_ASM(
glabel func00009660
/*     9660:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*     9664:	afbf0014 */ 	sw	$ra,0x14($sp)
/*     9668:	3c048009 */ 	lui	$a0,%hi(var800926d0)
/*     966c:	3c058009 */ 	lui	$a1,%hi(var800926e8)
/*     9670:	24a526e8 */ 	addiu	$a1,$a1,%lo(var800926e8)
/*     9674:	248426d0 */ 	addiu	$a0,$a0,%lo(var800926d0)
/*     9678:	0c0120d0 */ 	jal	osCreateMesgQueue
/*     967c:	24060050 */ 	addiu	$a2,$zero,0x50
/*     9680:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*     9684:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*     9688:	03e00008 */ 	jr	$ra
/*     968c:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel func00009690
/*     9690:	27bdffc0 */ 	addiu	$sp,$sp,-64
/*     9694:	3c088009 */ 	lui	$t0,%hi(var80091900)
/*     9698:	25081900 */ 	addiu	$t0,$t0,%lo(var80091900)
/*     969c:	afb10028 */ 	sw	$s1,0x28($sp)
/*     96a0:	8d110004 */ 	lw	$s1,0x4($t0)
/*     96a4:	afb00024 */ 	sw	$s0,0x24($sp)
/*     96a8:	afa60048 */ 	sw	$a2,0x48($sp)
/*     96ac:	afbf002c */ 	sw	$ra,0x2c($sp)
/*     96b0:	00803825 */ 	or	$a3,$a0,$zero
/*     96b4:	00008025 */ 	or	$s0,$zero,$zero
/*     96b8:	12200015 */ 	beqz	$s1,.L00009710
/*     96bc:	02203025 */ 	or	$a2,$s1,$zero
/*     96c0:	8cc20008 */ 	lw	$v0,0x8($a2)
.L000096c4:
/*     96c4:	00e57021 */ 	addu	$t6,$a3,$a1
/*     96c8:	00e2082a */ 	slt	$at,$a3,$v0
/*     96cc:	14200010 */ 	bnez	$at,.L00009710
/*     96d0:	24430400 */ 	addiu	$v1,$v0,0x400
/*     96d4:	006e082a */ 	slt	$at,$v1,$t6
/*     96d8:	1420000a */ 	bnez	$at,.L00009704
/*     96dc:	00c08025 */ 	or	$s0,$a2,$zero
/*     96e0:	8cd80010 */ 	lw	$t8,0x10($a2)
/*     96e4:	3c0f8009 */ 	lui	$t7,%hi(var80092828)
/*     96e8:	8def2828 */ 	lw	$t7,%lo(var80092828)($t7)
/*     96ec:	0307c821 */ 	addu	$t9,$t8,$a3
/*     96f0:	03222023 */ 	subu	$a0,$t9,$v0
/*     96f4:	0c012d20 */ 	jal	osVirtualToPhysical
/*     96f8:	accf000c */ 	sw	$t7,0xc($a2)
/*     96fc:	1000004d */ 	b	.L00009834
/*     9700:	8fbf002c */ 	lw	$ra,0x2c($sp)
.L00009704:
/*     9704:	8cc60000 */ 	lw	$a2,0x0($a2)
/*     9708:	54c0ffee */ 	bnezl	$a2,.L000096c4
/*     970c:	8cc20008 */ 	lw	$v0,0x8($a2)
.L00009710:
/*     9710:	8d060008 */ 	lw	$a2,0x8($t0)
/*     9714:	14c00005 */ 	bnez	$a2,.L0000972c
/*     9718:	00c02025 */ 	or	$a0,$a2,$zero
/*     971c:	0c012d20 */ 	jal	osVirtualToPhysical
/*     9720:	02202025 */ 	or	$a0,$s1,$zero
/*     9724:	10000043 */ 	b	.L00009834
/*     9728:	8fbf002c */ 	lw	$ra,0x2c($sp)
.L0000972c:
/*     972c:	8cc90000 */ 	lw	$t1,0x0($a2)
/*     9730:	afa70040 */ 	sw	$a3,0x40($sp)
/*     9734:	afa60034 */ 	sw	$a2,0x34($sp)
/*     9738:	0c00c5e9 */ 	jal	alUnlink
/*     973c:	ad090008 */ 	sw	$t1,0x8($t0)
/*     9740:	3c088009 */ 	lui	$t0,%hi(var80091900)
/*     9744:	25081900 */ 	addiu	$t0,$t0,%lo(var80091900)
/*     9748:	8fa60034 */ 	lw	$a2,0x34($sp)
/*     974c:	12000009 */ 	beqz	$s0,.L00009774
/*     9750:	8fa70040 */ 	lw	$a3,0x40($sp)
/*     9754:	00c02025 */ 	or	$a0,$a2,$zero
/*     9758:	02002825 */ 	or	$a1,$s0,$zero
/*     975c:	afa60034 */ 	sw	$a2,0x34($sp)
/*     9760:	0c00c5dc */ 	jal	alLink
/*     9764:	afa70040 */ 	sw	$a3,0x40($sp)
/*     9768:	8fa60034 */ 	lw	$a2,0x34($sp)
/*     976c:	1000000c */ 	b	.L000097a0
/*     9770:	8fa70040 */ 	lw	$a3,0x40($sp)
.L00009774:
/*     9774:	8d110004 */ 	lw	$s1,0x4($t0)
/*     9778:	52200007 */ 	beqzl	$s1,.L00009798
/*     977c:	ad060004 */ 	sw	$a2,0x4($t0)
/*     9780:	ad060004 */ 	sw	$a2,0x4($t0)
/*     9784:	acd10000 */ 	sw	$s1,0x0($a2)
/*     9788:	acc00004 */ 	sw	$zero,0x4($a2)
/*     978c:	10000004 */ 	b	.L000097a0
/*     9790:	ae260004 */ 	sw	$a2,0x4($s1)
/*     9794:	ad060004 */ 	sw	$a2,0x4($t0)
.L00009798:
/*     9798:	acc00000 */ 	sw	$zero,0x0($a2)
/*     979c:	acc00004 */ 	sw	$zero,0x4($a2)
.L000097a0:
/*     97a0:	30f10001 */ 	andi	$s1,$a3,0x1
/*     97a4:	00f13823 */ 	subu	$a3,$a3,$s1
/*     97a8:	acc70008 */ 	sw	$a3,0x8($a2)
/*     97ac:	3c0a8009 */ 	lui	$t2,%hi(var80092828)
/*     97b0:	8d4a2828 */ 	lw	$t2,%lo(var80092828)($t2)
/*     97b4:	8cd00010 */ 	lw	$s0,0x10($a2)
/*     97b8:	3c018000 */ 	lui	$at,0x8000
/*     97bc:	acca000c */ 	sw	$t2,0xc($a2)
/*     97c0:	afa70040 */ 	sw	$a3,0x40($sp)
/*     97c4:	00e12025 */ 	or	$a0,$a3,$at
/*     97c8:	0c013920 */ 	jal	osInvalDCache
/*     97cc:	24050400 */ 	addiu	$a1,$zero,0x400
/*     97d0:	3c038006 */ 	lui	$v1,%hi(var8005d520)
/*     97d4:	2463d520 */ 	addiu	$v1,$v1,%lo(var8005d520)
/*     97d8:	8c620000 */ 	lw	$v0,0x0($v1)
/*     97dc:	3c0c8009 */ 	lui	$t4,%hi(var80091f50)
/*     97e0:	3c0e8009 */ 	lui	$t6,%hi(var800926d0)
/*     97e4:	00025880 */ 	sll	$t3,$v0,0x2
/*     97e8:	01625823 */ 	subu	$t3,$t3,$v0
/*     97ec:	000b58c0 */ 	sll	$t3,$t3,0x3
/*     97f0:	25ce26d0 */ 	addiu	$t6,$t6,%lo(var800926d0)
/*     97f4:	258c1f50 */ 	addiu	$t4,$t4,%lo(var80091f50)
/*     97f8:	240d0400 */ 	addiu	$t5,$zero,0x400
/*     97fc:	244f0001 */ 	addiu	$t7,$v0,0x1
/*     9800:	8fa70040 */ 	lw	$a3,0x40($sp)
/*     9804:	ac6f0000 */ 	sw	$t7,0x0($v1)
/*     9808:	afad0014 */ 	sw	$t5,0x14($sp)
/*     980c:	016c2021 */ 	addu	$a0,$t3,$t4
/*     9810:	afae0018 */ 	sw	$t6,0x18($sp)
/*     9814:	24050001 */ 	addiu	$a1,$zero,0x1
/*     9818:	00003025 */ 	or	$a2,$zero,$zero
/*     981c:	0c01394c */ 	jal	osPiStartDma
/*     9820:	afb00010 */ 	sw	$s0,0x10($sp)
/*     9824:	0c012d20 */ 	jal	osVirtualToPhysical
/*     9828:	02002025 */ 	or	$a0,$s0,$zero
/*     982c:	00511021 */ 	addu	$v0,$v0,$s1
/*     9830:	8fbf002c */ 	lw	$ra,0x2c($sp)
.L00009834:
/*     9834:	8fb00024 */ 	lw	$s0,0x24($sp)
/*     9838:	8fb10028 */ 	lw	$s1,0x28($sp)
/*     983c:	03e00008 */ 	jr	$ra
/*     9840:	27bd0040 */ 	addiu	$sp,$sp,0x40
);

#if VERSION >= VERSION_PAL_FINAL
GLOBAL_ASM(
glabel func00009844
/*     9754:	27bdffc8 */ 	addiu	$sp,$sp,-56
/*     9758:	3c038009 */ 	lui	$v1,0x8009
/*     975c:	24631e50 */ 	addiu	$v1,$v1,0x1e50
/*     9760:	906e0000 */ 	lbu	$t6,0x0($v1)
/*     9764:	afbf0034 */ 	sw	$ra,0x34($sp)
/*     9768:	afb40030 */ 	sw	$s4,0x30($sp)
/*     976c:	afb3002c */ 	sw	$s3,0x2c($sp)
/*     9770:	afb20028 */ 	sw	$s2,0x28($sp)
/*     9774:	afb10024 */ 	sw	$s1,0x24($sp)
/*     9778:	afb00020 */ 	sw	$s0,0x20($sp)
/*     977c:	afa40038 */ 	sw	$a0,0x38($sp)
/*     9780:	15c0001f */ 	bnez	$t6,.PF00009800
/*     9784:	24020050 */ 	li	$v0,0x50
/*     9788:	3c0f8009 */ 	lui	$t7,0x8009
/*     978c:	25ef1e60 */ 	addiu	$t7,$t7,0x1e60
/*     9790:	3c108009 */ 	lui	$s0,0x8009
/*     9794:	3c128009 */ 	lui	$s2,0x8009
/*     9798:	3c148009 */ 	lui	$s4,0x8009
/*     979c:	ac6f0008 */ 	sw	$t7,0x8($v1)
/*     97a0:	26945740 */ 	addiu	$s4,$s4,0x5740
/*     97a4:	26521e74 */ 	addiu	$s2,$s2,0x1e74
/*     97a8:	26101e60 */ 	addiu	$s0,$s0,0x1e60
/*     97ac:	00008825 */ 	move	$s1,$zero
/*     97b0:	2453ffff */ 	addiu	$s3,$v0,-1
.PF000097b4:
/*     97b4:	02402025 */ 	move	$a0,$s2
/*     97b8:	0c00c41c */ 	jal	alLink
/*     97bc:	02002825 */ 	move	$a1,$s0
/*     97c0:	24180400 */ 	li	$t8,0x400
/*     97c4:	afb80010 */ 	sw	$t8,0x10($sp)
/*     97c8:	00002025 */ 	move	$a0,$zero
/*     97cc:	00002825 */ 	move	$a1,$zero
/*     97d0:	02803025 */ 	move	$a2,$s4
/*     97d4:	0c00bd05 */ 	jal	func0002fb14
/*     97d8:	24070001 */ 	li	$a3,0x1
/*     97dc:	26310001 */ 	addiu	$s1,$s1,0x1
/*     97e0:	26100014 */ 	addiu	$s0,$s0,0x14
/*     97e4:	26520014 */ 	addiu	$s2,$s2,0x14
/*     97e8:	1633fff2 */ 	bne	$s1,$s3,.PF000097b4
/*     97ec:	ae02fffc */ 	sw	$v0,-0x4($s0)
/*     97f0:	3c038009 */ 	lui	$v1,0x8009
/*     97f4:	24631e50 */ 	addiu	$v1,$v1,0x1e50
/*     97f8:	24190001 */ 	li	$t9,0x1
/*     97fc:	a0790000 */ 	sb	$t9,0x0($v1)
.PF00009800:
/*     9800:	8fa80038 */ 	lw	$t0,0x38($sp)
/*     9804:	3c027001 */ 	lui	$v0,0x7001
/*     9808:	244295a0 */ 	addiu	$v0,$v0,-27232
/*     980c:	ad030000 */ 	sw	$v1,0x0($t0)
/*     9810:	8fbf0034 */ 	lw	$ra,0x34($sp)
/*     9814:	8fb40030 */ 	lw	$s4,0x30($sp)
/*     9818:	8fb3002c */ 	lw	$s3,0x2c($sp)
/*     981c:	8fb20028 */ 	lw	$s2,0x28($sp)
/*     9820:	8fb10024 */ 	lw	$s1,0x24($sp)
/*     9824:	8fb00020 */ 	lw	$s0,0x20($sp)
/*     9828:	03e00008 */ 	jr	$ra
/*     982c:	27bd0038 */ 	addiu	$sp,$sp,0x38
);
#else
GLOBAL_ASM(
glabel func00009844
/*     9844:	27bdffc8 */ 	addiu	$sp,$sp,-56
/*     9848:	3c0e8009 */ 	lui	$t6,%hi(g_Is4Mb)
/*     984c:	91ce0af0 */ 	lbu	$t6,%lo(g_Is4Mb)($t6)
/*     9850:	24010001 */ 	addiu	$at,$zero,0x1
/*     9854:	afbf0034 */ 	sw	$ra,0x34($sp)
/*     9858:	afb40030 */ 	sw	$s4,0x30($sp)
/*     985c:	afb3002c */ 	sw	$s3,0x2c($sp)
/*     9860:	afb20028 */ 	sw	$s2,0x28($sp)
/*     9864:	afb10024 */ 	sw	$s1,0x24($sp)
/*     9868:	afb00020 */ 	sw	$s0,0x20($sp)
/*     986c:	15c10003 */ 	bne	$t6,$at,.L0000987c
/*     9870:	afa40038 */ 	sw	$a0,0x38($sp)
/*     9874:	10000002 */ 	b	.L00009880
/*     9878:	2402003c */ 	addiu	$v0,$zero,0x3c
.L0000987c:
/*     987c:	24020050 */ 	addiu	$v0,$zero,0x50
.L00009880:
/*     9880:	3c038009 */ 	lui	$v1,%hi(var80091900)
/*     9884:	24631900 */ 	addiu	$v1,$v1,%lo(var80091900)
/*     9888:	906f0000 */ 	lbu	$t7,0x0($v1)
/*     988c:	3c188009 */ 	lui	$t8,%hi(var80091910)
/*     9890:	27181910 */ 	addiu	$t8,$t8,%lo(var80091910)
/*     9894:	15e0001d */ 	bnez	$t7,.L0000990c
/*     9898:	00008825 */ 	or	$s1,$zero,$zero
/*     989c:	2453ffff */ 	addiu	$s3,$v0,-1
/*     98a0:	1a600018 */ 	blez	$s3,.L00009904
/*     98a4:	ac780008 */ 	sw	$t8,0x8($v1)
/*     98a8:	3c108009 */ 	lui	$s0,%hi(var80091910)
/*     98ac:	3c128009 */ 	lui	$s2,%hi(var80091910+0x14)
/*     98b0:	3c148009 */ 	lui	$s4,%hi(var800951f0)
/*     98b4:	269451f0 */ 	addiu	$s4,$s4,%lo(var800951f0)
/*     98b8:	26521924 */ 	addiu	$s2,$s2,%lo(var80091910+0x14)
/*     98bc:	26101910 */ 	addiu	$s0,$s0,%lo(var80091910)
.L000098c0:
/*     98c0:	02402025 */ 	or	$a0,$s2,$zero
/*     98c4:	0c00c5dc */ 	jal	alLink
/*     98c8:	02002825 */ 	or	$a1,$s0,$zero
/*     98cc:	24190400 */ 	addiu	$t9,$zero,0x400
/*     98d0:	afb90010 */ 	sw	$t9,0x10($sp)
/*     98d4:	00002025 */ 	or	$a0,$zero,$zero
/*     98d8:	00002825 */ 	or	$a1,$zero,$zero
/*     98dc:	02803025 */ 	or	$a2,$s4,$zero
/*     98e0:	0c00bec5 */ 	jal	func0002fb14
/*     98e4:	24070001 */ 	addiu	$a3,$zero,0x1
/*     98e8:	26310001 */ 	addiu	$s1,$s1,0x1
/*     98ec:	26100014 */ 	addiu	$s0,$s0,0x14
/*     98f0:	26520014 */ 	addiu	$s2,$s2,0x14
/*     98f4:	1633fff2 */ 	bne	$s1,$s3,.L000098c0
/*     98f8:	ae02fffc */ 	sw	$v0,-0x4($s0)
/*     98fc:	3c038009 */ 	lui	$v1,%hi(var80091900)
/*     9900:	24631900 */ 	addiu	$v1,$v1,%lo(var80091900)
.L00009904:
/*     9904:	24080001 */ 	addiu	$t0,$zero,0x1
/*     9908:	a0680000 */ 	sb	$t0,0x0($v1)
.L0000990c:
/*     990c:	8fa90038 */ 	lw	$t1,0x38($sp)
/*     9910:	3c027001 */ 	lui	$v0,%hi(func00009690)
/*     9914:	24429690 */ 	addiu	$v0,$v0,%lo(func00009690)
/*     9918:	ad230000 */ 	sw	$v1,0x0($t1)
/*     991c:	8fbf0034 */ 	lw	$ra,0x34($sp)
/*     9920:	8fb40030 */ 	lw	$s4,0x30($sp)
/*     9924:	8fb3002c */ 	lw	$s3,0x2c($sp)
/*     9928:	8fb20028 */ 	lw	$s2,0x28($sp)
/*     992c:	8fb10024 */ 	lw	$s1,0x24($sp)
/*     9930:	8fb00020 */ 	lw	$s0,0x20($sp)
/*     9934:	03e00008 */ 	jr	$ra
/*     9938:	27bd0038 */ 	addiu	$sp,$sp,0x38
);
#endif

GLOBAL_ASM(
glabel amgrClearDmaBuffers
/*     993c:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*     9940:	afb2001c */ 	sw	$s2,0x1c($sp)
/*     9944:	3c128009 */ 	lui	$s2,%hi(var80091900)
/*     9948:	26521900 */ 	addiu	$s2,$s2,%lo(var80091900)
/*     994c:	afb00014 */ 	sw	$s0,0x14($sp)
/*     9950:	8e500004 */ 	lw	$s0,0x4($s2)
/*     9954:	afbf0024 */ 	sw	$ra,0x24($sp)
/*     9958:	afb30020 */ 	sw	$s3,0x20($sp)
/*     995c:	1200001c */ 	beqz	$s0,.L000099d0
/*     9960:	afb10018 */ 	sw	$s1,0x18($sp)
/*     9964:	3c138009 */ 	lui	$s3,%hi(var80092828)
/*     9968:	26732828 */ 	addiu	$s3,$s3,%lo(var80092828)
.L0000996c:
/*     996c:	8e0f000c */ 	lw	$t7,0xc($s0)
/*     9970:	8e6e0000 */ 	lw	$t6,0x0($s3)
/*     9974:	8e020000 */ 	lw	$v0,0x0($s0)
/*     9978:	25f80001 */ 	addiu	$t8,$t7,0x1
/*     997c:	030e082b */ 	sltu	$at,$t8,$t6
/*     9980:	10200011 */ 	beqz	$at,.L000099c8
/*     9984:	00408825 */ 	or	$s1,$v0,$zero
/*     9988:	8e590004 */ 	lw	$t9,0x4($s2)
/*     998c:	16190002 */ 	bne	$s0,$t9,.L00009998
/*     9990:	00000000 */ 	nop
/*     9994:	ae420004 */ 	sw	$v0,0x4($s2)
.L00009998:
/*     9998:	0c00c5e9 */ 	jal	alUnlink
/*     999c:	02002025 */ 	or	$a0,$s0,$zero
/*     99a0:	8e450008 */ 	lw	$a1,0x8($s2)
/*     99a4:	50a00006 */ 	beqzl	$a1,.L000099c0
/*     99a8:	ae500008 */ 	sw	$s0,0x8($s2)
/*     99ac:	0c00c5dc */ 	jal	alLink
/*     99b0:	02002025 */ 	or	$a0,$s0,$zero
/*     99b4:	10000004 */ 	b	.L000099c8
/*     99b8:	00000000 */ 	nop
/*     99bc:	ae500008 */ 	sw	$s0,0x8($s2)
.L000099c0:
/*     99c0:	ae000000 */ 	sw	$zero,0x0($s0)
/*     99c4:	ae000004 */ 	sw	$zero,0x4($s0)
.L000099c8:
/*     99c8:	1620ffe8 */ 	bnez	$s1,.L0000996c
/*     99cc:	02208025 */ 	or	$s0,$s1,$zero
.L000099d0:
/*     99d0:	3c138009 */ 	lui	$s3,%hi(var80092828)
/*     99d4:	26732828 */ 	addiu	$s3,$s3,%lo(var80092828)
/*     99d8:	8e680000 */ 	lw	$t0,0x0($s3)
/*     99dc:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*     99e0:	3c018006 */ 	lui	$at,%hi(var8005d520)
/*     99e4:	25090001 */ 	addiu	$t1,$t0,0x1
/*     99e8:	ae690000 */ 	sw	$t1,0x0($s3)
/*     99ec:	8fb30020 */ 	lw	$s3,0x20($sp)
/*     99f0:	8fb00014 */ 	lw	$s0,0x14($sp)
/*     99f4:	8fb10018 */ 	lw	$s1,0x18($sp)
/*     99f8:	8fb2001c */ 	lw	$s2,0x1c($sp)
/*     99fc:	ac20d520 */ 	sw	$zero,%lo(var8005d520)($at)
/*     9a00:	03e00008 */ 	jr	$ra
/*     9a04:	27bd0028 */ 	addiu	$sp,$sp,0x28
);

GLOBAL_ASM(
glabel func00009a08
/*     9a08:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*     9a0c:	afb30020 */ 	sw	$s3,0x20($sp)
/*     9a10:	3c138006 */ 	lui	$s3,%hi(var8005d520)
/*     9a14:	2673d520 */ 	addiu	$s3,$s3,%lo(var8005d520)
/*     9a18:	8e6e0000 */ 	lw	$t6,0x0($s3)
/*     9a1c:	afb00014 */ 	sw	$s0,0x14($sp)
/*     9a20:	afbf0024 */ 	sw	$ra,0x24($sp)
/*     9a24:	afb2001c */ 	sw	$s2,0x1c($sp)
/*     9a28:	afb10018 */ 	sw	$s1,0x18($sp)
/*     9a2c:	19c0000c */ 	blez	$t6,.L00009a60
/*     9a30:	00008025 */ 	or	$s0,$zero,$zero
/*     9a34:	3c118009 */ 	lui	$s1,%hi(var800926d0)
/*     9a38:	263126d0 */ 	addiu	$s1,$s1,%lo(var800926d0)
/*     9a3c:	02202025 */ 	or	$a0,$s1,$zero
.L00009a40:
/*     9a40:	00002825 */ 	or	$a1,$zero,$zero
/*     9a44:	0c0121bc */ 	jal	osRecvMesg
/*     9a48:	00003025 */ 	or	$a2,$zero,$zero
/*     9a4c:	8e6f0000 */ 	lw	$t7,0x0($s3)
/*     9a50:	26100001 */ 	addiu	$s0,$s0,0x1
/*     9a54:	020f082a */ 	slt	$at,$s0,$t7
/*     9a58:	5420fff9 */ 	bnezl	$at,.L00009a40
/*     9a5c:	02202025 */ 	or	$a0,$s1,$zero
.L00009a60:
/*     9a60:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*     9a64:	8fb00014 */ 	lw	$s0,0x14($sp)
/*     9a68:	8fb10018 */ 	lw	$s1,0x18($sp)
/*     9a6c:	8fb2001c */ 	lw	$s2,0x1c($sp)
/*     9a70:	8fb30020 */ 	lw	$s3,0x20($sp)
/*     9a74:	03e00008 */ 	jr	$ra
/*     9a78:	27bd0028 */ 	addiu	$sp,$sp,0x28
);
