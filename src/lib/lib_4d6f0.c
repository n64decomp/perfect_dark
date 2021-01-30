#include <ultra64.h>
#include "constants.h"
#include "game/data/data_000000.h"
#include "game/data/data_0083d0.h"
#include "game/data/data_00e460.h"
#include "game/data/data_0160b0.h"
#include "game/data/data_01a3a0.h"
#include "game/data/data_020df0.h"
#include "game/data/data_02da90.h"
#include "gvars/gvars.h"
#include "lib/libc/ll.h"
#include "lib/lib_4c090.h"
#include "lib/lib_4d6f0.h"
#include "types.h"

GLOBAL_ASM(
glabel func0004d6f0
/*    4d6f0:	27bdfb38 */ 	addiu	$sp,$sp,-1224
/*    4d6f4:	afbf0044 */ 	sw	$ra,0x44($sp)
/*    4d6f8:	afbe0040 */ 	sw	$s8,0x40($sp)
/*    4d6fc:	afb3002c */ 	sw	$s3,0x2c($sp)
/*    4d700:	00809825 */ 	or	$s3,$a0,$zero
/*    4d704:	afb7003c */ 	sw	$s7,0x3c($sp)
/*    4d708:	afb60038 */ 	sw	$s6,0x38($sp)
/*    4d70c:	afb50034 */ 	sw	$s5,0x34($sp)
/*    4d710:	afb40030 */ 	sw	$s4,0x30($sp)
/*    4d714:	afb20028 */ 	sw	$s2,0x28($sp)
/*    4d718:	afb10024 */ 	sw	$s1,0x24($sp)
/*    4d71c:	afb00020 */ 	sw	$s0,0x20($sp)
/*    4d720:	afa00074 */ 	sw	$zero,0x74($sp)
/*    4d724:	0c013218 */ 	jal	func0004c860
/*    4d728:	241e00fe */ 	addiu	$s8,$zero,0xfe
/*    4d72c:	24010002 */ 	addiu	$at,$zero,0x2
/*    4d730:	14410004 */ 	bne	$v0,$at,.L0004d744
/*    4d734:	0040b825 */ 	or	$s7,$v0,$zero
/*    4d738:	0c0131ad */ 	jal	func0004c6b4
/*    4d73c:	02602025 */ 	or	$a0,$s3,$zero
/*    4d740:	0040b825 */ 	or	$s7,$v0,$zero
.L0004d744:
/*    4d744:	10400003 */ 	beqz	$v0,.L0004d754
/*    4d748:	02602025 */ 	or	$a0,$s3,$zero
/*    4d74c:	1000012a */ 	b	.L0004dbf8
/*    4d750:	02e01025 */ 	or	$v0,$s7,$zero
.L0004d754:
/*    4d754:	0c01370a */ 	jal	func0004dc28
/*    4d758:	27a50078 */ 	addiu	$a1,$sp,0x78
/*    4d75c:	50400004 */ 	beqzl	$v0,.L0004d770
/*    4d760:	8e620050 */ 	lw	$v0,0x50($s3)
/*    4d764:	10000125 */ 	b	.L0004dbfc
/*    4d768:	8fbf0044 */ 	lw	$ra,0x44($sp)
/*    4d76c:	8e620050 */ 	lw	$v0,0x50($s3)
.L0004d770:
/*    4d770:	0000a025 */ 	or	$s4,$zero,$zero
/*    4d774:	27b502bc */ 	addiu	$s5,$sp,0x2bc
/*    4d778:	18400082 */ 	blez	$v0,.L0004d984
/*    4d77c:	27b204bc */ 	addiu	$s2,$sp,0x4bc
/*    4d780:	8e6e005c */ 	lw	$t6,0x5c($s3)
.L0004d784:
/*    4d784:	8e640004 */ 	lw	$a0,0x4($s3)
/*    4d788:	8e650008 */ 	lw	$a1,0x8($s3)
/*    4d78c:	01d43021 */ 	addu	$a2,$t6,$s4
/*    4d790:	30cfffff */ 	andi	$t7,$a2,0xffff
/*    4d794:	01e03025 */ 	or	$a2,$t7,$zero
/*    4d798:	0c012e18 */ 	jal	__osContRamRead
/*    4d79c:	27a7029c */ 	addiu	$a3,$sp,0x29c
/*    4d7a0:	10400003 */ 	beqz	$v0,.L0004d7b0
/*    4d7a4:	0040b825 */ 	or	$s7,$v0,$zero
/*    4d7a8:	10000114 */ 	b	.L0004dbfc
/*    4d7ac:	8fbf0044 */ 	lw	$ra,0x44($sp)
.L0004d7b0:
/*    4d7b0:	97a202a0 */ 	lhu	$v0,0x2a0($sp)
/*    4d7b4:	8fb8029c */ 	lw	$t8,0x29c($sp)
/*    4d7b8:	14400003 */ 	bnez	$v0,.L0004d7c8
/*    4d7bc:	00000000 */ 	nop
/*    4d7c0:	5300006b */ 	beqzl	$t8,.L0004d970
/*    4d7c4:	8e620050 */ 	lw	$v0,0x50($s3)
.L0004d7c8:
/*    4d7c8:	10400003 */ 	beqz	$v0,.L0004d7d8
/*    4d7cc:	8fb9029c */ 	lw	$t9,0x29c($sp)
/*    4d7d0:	17200003 */ 	bnez	$t9,.L0004d7e0
/*    4d7d4:	27a902a2 */ 	addiu	$t1,$sp,0x2a2
.L0004d7d8:
/*    4d7d8:	10000044 */ 	b	.L0004d8ec
/*    4d7dc:	2404ffff */ 	addiu	$a0,$zero,-1
.L0004d7e0:
/*    4d7e0:	95210000 */ 	lhu	$at,0x0($t1)
/*    4d7e4:	00002025 */ 	or	$a0,$zero,$zero
/*    4d7e8:	00008025 */ 	or	$s0,$zero,$zero
/*    4d7ec:	a6410000 */ 	sh	$at,0x0($s2)
/*    4d7f0:	8e6d0060 */ 	lw	$t5,0x60($s3)
/*    4d7f4:	97ac04bc */ 	lhu	$t4,0x4bc($sp)
/*    4d7f8:	241600ff */ 	addiu	$s6,$zero,0xff
/*    4d7fc:	93ae04bc */ 	lbu	$t6,0x4bc($sp)
/*    4d800:	018d082a */ 	slt	$at,$t4,$t5
/*    4d804:	14200039 */ 	bnez	$at,.L0004d8ec
/*    4d808:	00000000 */ 	nop
/*    4d80c:	926f0064 */ 	lbu	$t7,0x64($s3)
/*    4d810:	93b804bd */ 	lbu	$t8,0x4bd($sp)
/*    4d814:	01cf082a */ 	slt	$at,$t6,$t7
/*    4d818:	10200034 */ 	beqz	$at,.L0004d8ec
/*    4d81c:	00000000 */ 	nop
/*    4d820:	1b000032 */ 	blez	$t8,.L0004d8ec
/*    4d824:	2b010080 */ 	slti	$at,$t8,0x80
/*    4d828:	10200030 */ 	beqz	$at,.L0004d8ec
/*    4d82c:	02c08825 */ 	or	$s1,$s6,$zero
/*    4d830:	93b904bc */ 	lbu	$t9,0x4bc($sp)
.L0004d834:
/*    4d834:	13310010 */ 	beq	$t9,$s1,.L0004d878
/*    4d838:	0320b025 */ 	or	$s6,$t9,$zero
/*    4d83c:	133e0008 */ 	beq	$t9,$s8,.L0004d860
/*    4d840:	03208825 */ 	or	$s1,$t9,$zero
/*    4d844:	02602025 */ 	or	$a0,$s3,$zero
/*    4d848:	02a02825 */ 	or	$a1,$s5,$zero
/*    4d84c:	00003025 */ 	or	$a2,$zero,$zero
/*    4d850:	0c01324d */ 	jal	func0004c934
/*    4d854:	332700ff */ 	andi	$a3,$t9,0xff
/*    4d858:	0040b825 */ 	or	$s7,$v0,$zero
/*    4d85c:	32de00ff */ 	andi	$s8,$s6,0xff
.L0004d860:
/*    4d860:	12e00005 */ 	beqz	$s7,.L0004d878
/*    4d864:	24010003 */ 	addiu	$at,$zero,0x3
/*    4d868:	52e10004 */ 	beql	$s7,$at,.L0004d87c
/*    4d86c:	96410000 */ 	lhu	$at,0x0($s2)
/*    4d870:	100000e1 */ 	b	.L0004dbf8
/*    4d874:	02e01025 */ 	or	$v0,$s7,$zero
.L0004d878:
/*    4d878:	96410000 */ 	lhu	$at,0x0($s2)
.L0004d87c:
/*    4d87c:	02602025 */ 	or	$a0,$s3,$zero
/*    4d880:	27a60078 */ 	addiu	$a2,$sp,0x78
/*    4d884:	a7a10004 */ 	sh	$at,0x4($sp)
/*    4d888:	0c0137bd */ 	jal	func0004def4
/*    4d88c:	8fa50004 */ 	lw	$a1,0x4($sp)
/*    4d890:	00502023 */ 	subu	$a0,$v0,$s0
/*    4d894:	14800015 */ 	bnez	$a0,.L0004d8ec
/*    4d898:	93ab04bd */ 	lbu	$t3,0x4bd($sp)
/*    4d89c:	000b6040 */ 	sll	$t4,$t3,0x1
/*    4d8a0:	02ac6821 */ 	addu	$t5,$s5,$t4
/*    4d8a4:	95a10000 */ 	lhu	$at,0x0($t5)
/*    4d8a8:	24100001 */ 	addiu	$s0,$zero,0x1
/*    4d8ac:	a6410000 */ 	sh	$at,0x0($s2)
/*    4d8b0:	8e790060 */ 	lw	$t9,0x60($s3)
/*    4d8b4:	97b804bc */ 	lhu	$t8,0x4bc($sp)
/*    4d8b8:	93ab04bd */ 	lbu	$t3,0x4bd($sp)
/*    4d8bc:	93aa04bc */ 	lbu	$t2,0x4bc($sp)
/*    4d8c0:	0319082a */ 	slt	$at,$t8,$t9
/*    4d8c4:	14200009 */ 	bnez	$at,.L0004d8ec
/*    4d8c8:	00000000 */ 	nop
/*    4d8cc:	92690064 */ 	lbu	$t1,0x64($s3)
/*    4d8d0:	0149082a */ 	slt	$at,$t2,$t1
/*    4d8d4:	10200005 */ 	beqz	$at,.L0004d8ec
/*    4d8d8:	00000000 */ 	nop
/*    4d8dc:	19600003 */ 	blez	$t3,.L0004d8ec
/*    4d8e0:	29610080 */ 	slti	$at,$t3,0x80
/*    4d8e4:	5420ffd3 */ 	bnezl	$at,.L0004d834
/*    4d8e8:	93b904bc */ 	lbu	$t9,0x4bc($sp)
.L0004d8ec:
/*    4d8ec:	14800003 */ 	bnez	$a0,.L0004d8fc
/*    4d8f0:	97ac04bc */ 	lhu	$t4,0x4bc($sp)
/*    4d8f4:	24010001 */ 	addiu	$at,$zero,0x1
/*    4d8f8:	1181001c */ 	beq	$t4,$at,.L0004d96c
.L0004d8fc:
/*    4d8fc:	27a4029c */ 	addiu	$a0,$sp,0x29c
/*    4d900:	0c012c30 */ 	jal	bzero
/*    4d904:	24050020 */ 	addiu	$a1,$zero,0x20
/*    4d908:	926e0065 */ 	lbu	$t6,0x65($s3)
/*    4d90c:	02602025 */ 	or	$a0,$s3,$zero
/*    4d910:	51c00008 */ 	beqzl	$t6,.L0004d934
/*    4d914:	8e6d005c */ 	lw	$t5,0x5c($s3)
/*    4d918:	0c013378 */ 	jal	__osPfsSelectBank
/*    4d91c:	00002825 */ 	or	$a1,$zero,$zero
/*    4d920:	50400004 */ 	beqzl	$v0,.L0004d934
/*    4d924:	8e6d005c */ 	lw	$t5,0x5c($s3)
/*    4d928:	100000b4 */ 	b	.L0004dbfc
/*    4d92c:	8fbf0044 */ 	lw	$ra,0x44($sp)
/*    4d930:	8e6d005c */ 	lw	$t5,0x5c($s3)
.L0004d934:
/*    4d934:	8e640004 */ 	lw	$a0,0x4($s3)
/*    4d938:	8e650008 */ 	lw	$a1,0x8($s3)
/*    4d93c:	01b43021 */ 	addu	$a2,$t5,$s4
/*    4d940:	30cfffff */ 	andi	$t7,$a2,0xffff
/*    4d944:	01e03025 */ 	or	$a2,$t7,$zero
/*    4d948:	afa00010 */ 	sw	$zero,0x10($sp)
/*    4d94c:	0c012d84 */ 	jal	__osContRamWrite
/*    4d950:	27a7029c */ 	addiu	$a3,$sp,0x29c
/*    4d954:	10400003 */ 	beqz	$v0,.L0004d964
/*    4d958:	8fb80074 */ 	lw	$t8,0x74($sp)
/*    4d95c:	100000a7 */ 	b	.L0004dbfc
/*    4d960:	8fbf0044 */ 	lw	$ra,0x44($sp)
.L0004d964:
/*    4d964:	27190001 */ 	addiu	$t9,$t8,0x1
/*    4d968:	afb90074 */ 	sw	$t9,0x74($sp)
.L0004d96c:
/*    4d96c:	8e620050 */ 	lw	$v0,0x50($s3)
.L0004d970:
/*    4d970:	26940001 */ 	addiu	$s4,$s4,0x1
/*    4d974:	0282082a */ 	slt	$at,$s4,$v0
/*    4d978:	5420ff82 */ 	bnezl	$at,.L0004d784
/*    4d97c:	8e6e005c */ 	lw	$t6,0x5c($s3)
/*    4d980:	0000a025 */ 	or	$s4,$zero,$zero
.L0004d984:
/*    4d984:	18400021 */ 	blez	$v0,.L0004da0c
/*    4d988:	27b502bc */ 	addiu	$s5,$sp,0x2bc
/*    4d98c:	8e6a005c */ 	lw	$t2,0x5c($s3)
.L0004d990:
/*    4d990:	8e640004 */ 	lw	$a0,0x4($s3)
/*    4d994:	8e650008 */ 	lw	$a1,0x8($s3)
/*    4d998:	01543021 */ 	addu	$a2,$t2,$s4
/*    4d99c:	30c9ffff */ 	andi	$t1,$a2,0xffff
/*    4d9a0:	01203025 */ 	or	$a2,$t1,$zero
/*    4d9a4:	0c012e18 */ 	jal	__osContRamRead
/*    4d9a8:	27a7029c */ 	addiu	$a3,$sp,0x29c
/*    4d9ac:	10400003 */ 	beqz	$v0,.L0004d9bc
/*    4d9b0:	97ae02a0 */ 	lhu	$t6,0x2a0($sp)
/*    4d9b4:	10000091 */ 	b	.L0004dbfc
/*    4d9b8:	8fbf0044 */ 	lw	$ra,0x44($sp)
.L0004d9bc:
/*    4d9bc:	00145840 */ 	sll	$t3,$s4,0x1
/*    4d9c0:	27ac027c */ 	addiu	$t4,$sp,0x27c
/*    4d9c4:	11c0000b */ 	beqz	$t6,.L0004d9f4
/*    4d9c8:	016c2021 */ 	addu	$a0,$t3,$t4
/*    4d9cc:	8fad029c */ 	lw	$t5,0x29c($sp)
/*    4d9d0:	97af02a2 */ 	lhu	$t7,0x2a2($sp)
/*    4d9d4:	51a00008 */ 	beqzl	$t5,.L0004d9f8
/*    4d9d8:	a4800000 */ 	sh	$zero,0x0($a0)
/*    4d9dc:	96780062 */ 	lhu	$t8,0x62($s3)
/*    4d9e0:	01f8082a */ 	slt	$at,$t7,$t8
/*    4d9e4:	54200004 */ 	bnezl	$at,.L0004d9f8
/*    4d9e8:	a4800000 */ 	sh	$zero,0x0($a0)
/*    4d9ec:	10000002 */ 	b	.L0004d9f8
/*    4d9f0:	a48f0000 */ 	sh	$t7,0x0($a0)
.L0004d9f4:
/*    4d9f4:	a4800000 */ 	sh	$zero,0x0($a0)
.L0004d9f8:
/*    4d9f8:	8e790050 */ 	lw	$t9,0x50($s3)
/*    4d9fc:	26940001 */ 	addiu	$s4,$s4,0x1
/*    4da00:	0299082a */ 	slt	$at,$s4,$t9
/*    4da04:	5420ffe2 */ 	bnezl	$at,.L0004d990
/*    4da08:	8e6a005c */ 	lw	$t2,0x5c($s3)
.L0004da0c:
/*    4da0c:	926a0064 */ 	lbu	$t2,0x64($s3)
/*    4da10:	0000b025 */ 	or	$s6,$zero,$zero
/*    4da14:	241e0003 */ 	addiu	$s8,$zero,0x3
/*    4da18:	1940006b */ 	blez	$t2,.L0004dbc8
/*    4da1c:	27b203bc */ 	addiu	$s2,$sp,0x3bc
/*    4da20:	27b00060 */ 	addiu	$s0,$sp,0x60
.L0004da24:
/*    4da24:	02602025 */ 	or	$a0,$s3,$zero
/*    4da28:	02a02825 */ 	or	$a1,$s5,$zero
/*    4da2c:	00003025 */ 	or	$a2,$zero,$zero
/*    4da30:	0c01324d */ 	jal	func0004c934
/*    4da34:	32c700ff */ 	andi	$a3,$s6,0xff
/*    4da38:	10400006 */ 	beqz	$v0,.L0004da54
/*    4da3c:	27a804bc */ 	addiu	$t0,$sp,0x4bc
/*    4da40:	24010003 */ 	addiu	$at,$zero,0x3
/*    4da44:	50410004 */ 	beql	$v0,$at,.L0004da58
/*    4da48:	02c08825 */ 	or	$s1,$s6,$zero
/*    4da4c:	1000006b */ 	b	.L0004dbfc
/*    4da50:	8fbf0044 */ 	lw	$ra,0x44($sp)
.L0004da54:
/*    4da54:	02c08825 */ 	or	$s1,$s6,$zero
.L0004da58:
/*    4da58:	1ac00003 */ 	blez	$s6,.L0004da68
/*    4da5c:	0000a025 */ 	or	$s4,$zero,$zero
/*    4da60:	10000002 */ 	b	.L0004da6c
/*    4da64:	24050001 */ 	addiu	$a1,$zero,0x1
.L0004da68:
/*    4da68:	8e650060 */ 	lw	$a1,0x60($s3)
.L0004da6c:
/*    4da6c:	18a0001c */ 	blez	$a1,.L0004dae0
/*    4da70:	30a70003 */ 	andi	$a3,$a1,0x3
/*    4da74:	10e0000b */ 	beqz	$a3,.L0004daa4
/*    4da78:	00e02025 */ 	or	$a0,$a3,$zero
/*    4da7c:	00143040 */ 	sll	$a2,$s4,0x1
/*    4da80:	02461821 */ 	addu	$v1,$s2,$a2
/*    4da84:	02a61021 */ 	addu	$v0,$s5,$a2
.L0004da88:
/*    4da88:	94490000 */ 	lhu	$t1,0x0($v0)
/*    4da8c:	26940001 */ 	addiu	$s4,$s4,0x1
/*    4da90:	24630002 */ 	addiu	$v1,$v1,0x2
/*    4da94:	24420002 */ 	addiu	$v0,$v0,0x2
/*    4da98:	1494fffb */ 	bne	$a0,$s4,.L0004da88
/*    4da9c:	a469fffe */ 	sh	$t1,-0x2($v1)
/*    4daa0:	1285000f */ 	beq	$s4,$a1,.L0004dae0
.L0004daa4:
/*    4daa4:	00143040 */ 	sll	$a2,$s4,0x1
/*    4daa8:	02461821 */ 	addu	$v1,$s2,$a2
/*    4daac:	02a61021 */ 	addu	$v0,$s5,$a2
.L0004dab0:
/*    4dab0:	944c0002 */ 	lhu	$t4,0x2($v0)
/*    4dab4:	944e0004 */ 	lhu	$t6,0x4($v0)
/*    4dab8:	944d0006 */ 	lhu	$t5,0x6($v0)
/*    4dabc:	944b0000 */ 	lhu	$t3,0x0($v0)
/*    4dac0:	26940004 */ 	addiu	$s4,$s4,0x4
/*    4dac4:	24630008 */ 	addiu	$v1,$v1,0x8
/*    4dac8:	24420008 */ 	addiu	$v0,$v0,0x8
/*    4dacc:	a46cfffa */ 	sh	$t4,-0x6($v1)
/*    4dad0:	a46efffc */ 	sh	$t6,-0x4($v1)
/*    4dad4:	a46dfffe */ 	sh	$t5,-0x2($v1)
/*    4dad8:	1685fff5 */ 	bne	$s4,$a1,.L0004dab0
/*    4dadc:	a46bfff8 */ 	sh	$t3,-0x8($v1)
.L0004dae0:
/*    4dae0:	2a810080 */ 	slti	$at,$s4,0x80
/*    4dae4:	10200007 */ 	beqz	$at,.L0004db04
/*    4dae8:	02402825 */ 	or	$a1,$s2,$zero
/*    4daec:	0014c040 */ 	sll	$t8,$s4,0x1
/*    4daf0:	02581821 */ 	addu	$v1,$s2,$t8
.L0004daf4:
/*    4daf4:	24630002 */ 	addiu	$v1,$v1,0x2
/*    4daf8:	0068082b */ 	sltu	$at,$v1,$t0
/*    4dafc:	1420fffd */ 	bnez	$at,.L0004daf4
/*    4db00:	a47efffe */ 	sh	$s8,-0x2($v1)
.L0004db04:
/*    4db04:	8e6f0050 */ 	lw	$t7,0x50($s3)
/*    4db08:	0000a025 */ 	or	$s4,$zero,$zero
/*    4db0c:	24060001 */ 	addiu	$a2,$zero,0x1
/*    4db10:	19e00021 */ 	blez	$t7,.L0004db98
/*    4db14:	32c700ff */ 	andi	$a3,$s6,0xff
/*    4db18:	27a4027c */ 	addiu	$a0,$sp,0x27c
/*    4db1c:	90990000 */ 	lbu	$t9,0x0($a0)
.L0004db20:
/*    4db20:	56390018 */ 	bnel	$s1,$t9,.L0004db84
/*    4db24:	8e6e0050 */ 	lw	$t6,0x50($s3)
/*    4db28:	948a0000 */ 	lhu	$t2,0x0($a0)
/*    4db2c:	96690062 */ 	lhu	$t1,0x62($s3)
/*    4db30:	0149082a */ 	slt	$at,$t2,$t1
/*    4db34:	54200013 */ 	bnezl	$at,.L0004db84
/*    4db38:	8e6e0050 */ 	lw	$t6,0x50($s3)
/*    4db3c:	90830001 */ 	lbu	$v1,0x1($a0)
.L0004db40:
/*    4db40:	00031040 */ 	sll	$v0,$v1,0x1
/*    4db44:	02a25821 */ 	addu	$t3,$s5,$v0
/*    4db48:	95610000 */ 	lhu	$at,0x0($t3)
/*    4db4c:	02426821 */ 	addu	$t5,$s2,$v0
/*    4db50:	a6010000 */ 	sh	$at,0x0($s0)
/*    4db54:	a5a10000 */ 	sh	$at,0x0($t5)
/*    4db58:	96010000 */ 	lhu	$at,0x0($s0)
/*    4db5c:	a4810000 */ 	sh	$at,0x0($a0)
/*    4db60:	90890000 */ 	lbu	$t1,0x0($a0)
/*    4db64:	56290007 */ 	bnel	$s1,$t1,.L0004db84
/*    4db68:	8e6e0050 */ 	lw	$t6,0x50($s3)
/*    4db6c:	966b0062 */ 	lhu	$t3,0x62($s3)
/*    4db70:	302cffff */ 	andi	$t4,$at,0xffff
/*    4db74:	018b082a */ 	slt	$at,$t4,$t3
/*    4db78:	5020fff1 */ 	beqzl	$at,.L0004db40
/*    4db7c:	90830001 */ 	lbu	$v1,0x1($a0)
/*    4db80:	8e6e0050 */ 	lw	$t6,0x50($s3)
.L0004db84:
/*    4db84:	26940001 */ 	addiu	$s4,$s4,0x1
/*    4db88:	24840002 */ 	addiu	$a0,$a0,0x2
/*    4db8c:	028e082a */ 	slt	$at,$s4,$t6
/*    4db90:	5420ffe3 */ 	bnezl	$at,.L0004db20
/*    4db94:	90990000 */ 	lbu	$t9,0x0($a0)
.L0004db98:
/*    4db98:	0c01324d */ 	jal	func0004c934
/*    4db9c:	02602025 */ 	or	$a0,$s3,$zero
/*    4dba0:	50400004 */ 	beqzl	$v0,.L0004dbb4
/*    4dba4:	926d0064 */ 	lbu	$t5,0x64($s3)
/*    4dba8:	10000014 */ 	b	.L0004dbfc
/*    4dbac:	8fbf0044 */ 	lw	$ra,0x44($sp)
/*    4dbb0:	926d0064 */ 	lbu	$t5,0x64($s3)
.L0004dbb4:
/*    4dbb4:	26d60001 */ 	addiu	$s6,$s6,0x1
/*    4dbb8:	32d800ff */ 	andi	$t8,$s6,0xff
/*    4dbbc:	030d082a */ 	slt	$at,$t8,$t5
/*    4dbc0:	1420ff98 */ 	bnez	$at,.L0004da24
/*    4dbc4:	0300b025 */ 	or	$s6,$t8,$zero
.L0004dbc8:
/*    4dbc8:	8faf0074 */ 	lw	$t7,0x74($sp)
/*    4dbcc:	00001025 */ 	or	$v0,$zero,$zero
/*    4dbd0:	51e00006 */ 	beqzl	$t7,.L0004dbec
/*    4dbd4:	8e690000 */ 	lw	$t1,0x0($s3)
/*    4dbd8:	8e790000 */ 	lw	$t9,0x0($s3)
/*    4dbdc:	372a0002 */ 	ori	$t2,$t9,0x2
/*    4dbe0:	10000005 */ 	b	.L0004dbf8
/*    4dbe4:	ae6a0000 */ 	sw	$t2,0x0($s3)
/*    4dbe8:	8e690000 */ 	lw	$t1,0x0($s3)
.L0004dbec:
/*    4dbec:	2401fffd */ 	addiu	$at,$zero,-3
/*    4dbf0:	01216024 */ 	and	$t4,$t1,$at
/*    4dbf4:	ae6c0000 */ 	sw	$t4,0x0($s3)
.L0004dbf8:
/*    4dbf8:	8fbf0044 */ 	lw	$ra,0x44($sp)
.L0004dbfc:
/*    4dbfc:	8fb00020 */ 	lw	$s0,0x20($sp)
/*    4dc00:	8fb10024 */ 	lw	$s1,0x24($sp)
/*    4dc04:	8fb20028 */ 	lw	$s2,0x28($sp)
/*    4dc08:	8fb3002c */ 	lw	$s3,0x2c($sp)
/*    4dc0c:	8fb40030 */ 	lw	$s4,0x30($sp)
/*    4dc10:	8fb50034 */ 	lw	$s5,0x34($sp)
/*    4dc14:	8fb60038 */ 	lw	$s6,0x38($sp)
/*    4dc18:	8fb7003c */ 	lw	$s7,0x3c($sp)
/*    4dc1c:	8fbe0040 */ 	lw	$s8,0x40($sp)
/*    4dc20:	03e00008 */ 	jr	$ra
/*    4dc24:	27bd04c8 */ 	addiu	$sp,$sp,0x4c8
);

GLOBAL_ASM(
glabel func0004dc28
/*    4dc28:	27bdfe98 */ 	addiu	$sp,$sp,-360
/*    4dc2c:	afb30024 */ 	sw	$s3,0x24($sp)
/*    4dc30:	00809825 */ 	or	$s3,$a0,$zero
/*    4dc34:	afb40028 */ 	sw	$s4,0x28($sp)
/*    4dc38:	00a0a025 */ 	or	$s4,$a1,$zero
/*    4dc3c:	afbf003c */ 	sw	$ra,0x3c($sp)
/*    4dc40:	afbe0038 */ 	sw	$s8,0x38($sp)
/*    4dc44:	afb70034 */ 	sw	$s7,0x34($sp)
/*    4dc48:	afb60030 */ 	sw	$s6,0x30($sp)
/*    4dc4c:	afb5002c */ 	sw	$s5,0x2c($sp)
/*    4dc50:	afb20020 */ 	sw	$s2,0x20($sp)
/*    4dc54:	afb1001c */ 	sw	$s1,0x1c($sp)
/*    4dc58:	afb00018 */ 	sw	$s0,0x18($sp)
/*    4dc5c:	24040100 */ 	addiu	$a0,$zero,0x100
/*    4dc60:	00001025 */ 	or	$v0,$zero,$zero
/*    4dc64:	00a01825 */ 	or	$v1,$a1,$zero
.L0004dc68:
/*    4dc68:	24420004 */ 	addiu	$v0,$v0,0x4
/*    4dc6c:	a0600102 */ 	sb	$zero,0x102($v1)
/*    4dc70:	a0600103 */ 	sb	$zero,0x103($v1)
/*    4dc74:	a0600104 */ 	sb	$zero,0x104($v1)
/*    4dc78:	24630004 */ 	addiu	$v1,$v1,0x4
/*    4dc7c:	1444fffa */ 	bne	$v0,$a0,.L0004dc68
/*    4dc80:	a06000fd */ 	sb	$zero,0xfd($v1)
/*    4dc84:	240e00ff */ 	addiu	$t6,$zero,0xff
/*    4dc88:	a28e0100 */ 	sb	$t6,0x100($s4)
/*    4dc8c:	926f0064 */ 	lbu	$t7,0x64($s3)
/*    4dc90:	0000b825 */ 	or	$s7,$zero,$zero
/*    4dc94:	00008025 */ 	or	$s0,$zero,$zero
/*    4dc98:	19e00089 */ 	blez	$t7,.L0004dec0
/*    4dc9c:	241e0080 */ 	addiu	$s8,$zero,0x80
/*    4dca0:	27b6015a */ 	addiu	$s6,$sp,0x15a
/*    4dca4:	27b50058 */ 	addiu	$s5,$sp,0x58
/*    4dca8:	27b20158 */ 	addiu	$s2,$sp,0x158
.L0004dcac:
/*    4dcac:	1a000003 */ 	blez	$s0,.L0004dcbc
/*    4dcb0:	02602025 */ 	or	$a0,$s3,$zero
/*    4dcb4:	10000002 */ 	b	.L0004dcc0
/*    4dcb8:	24110001 */ 	addiu	$s1,$zero,0x1
.L0004dcbc:
/*    4dcbc:	8e710060 */ 	lw	$s1,0x60($s3)
.L0004dcc0:
/*    4dcc0:	02a02825 */ 	or	$a1,$s5,$zero
/*    4dcc4:	00003025 */ 	or	$a2,$zero,$zero
/*    4dcc8:	0c01324d */ 	jal	func0004c934
/*    4dccc:	32e700ff */ 	andi	$a3,$s7,0xff
/*    4dcd0:	10400005 */ 	beqz	$v0,.L0004dce8
/*    4dcd4:	24010003 */ 	addiu	$at,$zero,0x3
/*    4dcd8:	50410004 */ 	beql	$v0,$at,.L0004dcec
/*    4dcdc:	2a210080 */ 	slti	$at,$s1,0x80
/*    4dce0:	10000079 */ 	b	.L0004dec8
/*    4dce4:	8fbf003c */ 	lw	$ra,0x3c($sp)
.L0004dce8:
/*    4dce8:	2a210080 */ 	slti	$at,$s1,0x80
.L0004dcec:
/*    4dcec:	1020006e */ 	beqz	$at,.L0004dea8
/*    4dcf0:	02201025 */ 	or	$v0,$s1,$zero
/*    4dcf4:	03d11823 */ 	subu	$v1,$s8,$s1
/*    4dcf8:	30780001 */ 	andi	$t8,$v1,0x1
/*    4dcfc:	13000024 */ 	beqz	$t8,.L0004dd90
/*    4dd00:	0011c840 */ 	sll	$t9,$s1,0x1
/*    4dd04:	02b94021 */ 	addu	$t0,$s5,$t9
/*    4dd08:	95010000 */ 	lhu	$at,0x0($t0)
/*    4dd0c:	a6410000 */ 	sh	$at,0x0($s2)
/*    4dd10:	8e6c0060 */ 	lw	$t4,0x60($s3)
/*    4dd14:	97ab0158 */ 	lhu	$t3,0x158($sp)
/*    4dd18:	93ad0158 */ 	lbu	$t5,0x158($sp)
/*    4dd1c:	016c082a */ 	slt	$at,$t3,$t4
/*    4dd20:	5420001a */ 	bnezl	$at,.L0004dd8c
/*    4dd24:	26220001 */ 	addiu	$v0,$s1,0x1
/*    4dd28:	120d0017 */ 	beq	$s0,$t5,.L0004dd88
/*    4dd2c:	93ae0159 */ 	lbu	$t6,0x159($sp)
/*    4dd30:	05c10003 */ 	bgez	$t6,.L0004dd40
/*    4dd34:	000e7883 */ 	sra	$t7,$t6,0x2
/*    4dd38:	25c10003 */ 	addiu	$at,$t6,0x3
/*    4dd3c:	00017883 */ 	sra	$t7,$at,0x2
.L0004dd40:
/*    4dd40:	05a10004 */ 	bgez	$t5,.L0004dd54
/*    4dd44:	31b80007 */ 	andi	$t8,$t5,0x7
/*    4dd48:	13000002 */ 	beqz	$t8,.L0004dd54
/*    4dd4c:	00000000 */ 	nop
/*    4dd50:	2718fff8 */ 	addiu	$t8,$t8,-8
.L0004dd54:
/*    4dd54:	0018c940 */ 	sll	$t9,$t8,0x5
/*    4dd58:	01f91821 */ 	addu	$v1,$t7,$t9
/*    4dd5c:	02831021 */ 	addu	$v0,$s4,$v1
/*    4dd60:	90490101 */ 	lbu	$t1,0x101($v0)
/*    4dd64:	06010004 */ 	bgez	$s0,.L0004dd78
/*    4dd68:	32080007 */ 	andi	$t0,$s0,0x7
/*    4dd6c:	11000002 */ 	beqz	$t0,.L0004dd78
/*    4dd70:	00000000 */ 	nop
/*    4dd74:	2508fff8 */ 	addiu	$t0,$t0,-8
.L0004dd78:
/*    4dd78:	240a0001 */ 	addiu	$t2,$zero,0x1
/*    4dd7c:	010a5804 */ 	sllv	$t3,$t2,$t0
/*    4dd80:	012b6025 */ 	or	$t4,$t1,$t3
/*    4dd84:	a04c0101 */ 	sb	$t4,0x101($v0)
.L0004dd88:
/*    4dd88:	26220001 */ 	addiu	$v0,$s1,0x1
.L0004dd8c:
/*    4dd8c:	105e0046 */ 	beq	$v0,$s8,.L0004dea8
.L0004dd90:
/*    4dd90:	00027040 */ 	sll	$t6,$v0,0x1
/*    4dd94:	02ae2821 */ 	addu	$a1,$s5,$t6
/*    4dd98:	24a40002 */ 	addiu	$a0,$a1,0x2
.L0004dd9c:
/*    4dd9c:	94a10000 */ 	lhu	$at,0x0($a1)
/*    4dda0:	a6410000 */ 	sh	$at,0x0($s2)
/*    4dda4:	8e790060 */ 	lw	$t9,0x60($s3)
/*    4dda8:	97af0158 */ 	lhu	$t7,0x158($sp)
/*    4ddac:	93aa0158 */ 	lbu	$t2,0x158($sp)
/*    4ddb0:	01f9082a */ 	slt	$at,$t7,$t9
/*    4ddb4:	5420001a */ 	bnezl	$at,.L0004de20
/*    4ddb8:	94810000 */ 	lhu	$at,0x0($a0)
/*    4ddbc:	120a0017 */ 	beq	$s0,$t2,.L0004de1c
/*    4ddc0:	93a80159 */ 	lbu	$t0,0x159($sp)
/*    4ddc4:	05010003 */ 	bgez	$t0,.L0004ddd4
/*    4ddc8:	00084883 */ 	sra	$t1,$t0,0x2
/*    4ddcc:	25010003 */ 	addiu	$at,$t0,0x3
/*    4ddd0:	00014883 */ 	sra	$t1,$at,0x2
.L0004ddd4:
/*    4ddd4:	05410004 */ 	bgez	$t2,.L0004dde8
/*    4ddd8:	314b0007 */ 	andi	$t3,$t2,0x7
/*    4dddc:	11600002 */ 	beqz	$t3,.L0004dde8
/*    4dde0:	00000000 */ 	nop
/*    4dde4:	256bfff8 */ 	addiu	$t3,$t3,-8
.L0004dde8:
/*    4dde8:	000b6140 */ 	sll	$t4,$t3,0x5
/*    4ddec:	012c1821 */ 	addu	$v1,$t1,$t4
/*    4ddf0:	02831021 */ 	addu	$v0,$s4,$v1
/*    4ddf4:	904e0101 */ 	lbu	$t6,0x101($v0)
/*    4ddf8:	06010004 */ 	bgez	$s0,.L0004de0c
/*    4ddfc:	320d0007 */ 	andi	$t5,$s0,0x7
/*    4de00:	11a00002 */ 	beqz	$t5,.L0004de0c
/*    4de04:	00000000 */ 	nop
/*    4de08:	25adfff8 */ 	addiu	$t5,$t5,-8
.L0004de0c:
/*    4de0c:	24180001 */ 	addiu	$t8,$zero,0x1
/*    4de10:	01b87804 */ 	sllv	$t7,$t8,$t5
/*    4de14:	01cfc825 */ 	or	$t9,$t6,$t7
/*    4de18:	a0590101 */ 	sb	$t9,0x101($v0)
.L0004de1c:
/*    4de1c:	94810000 */ 	lhu	$at,0x0($a0)
.L0004de20:
/*    4de20:	24840004 */ 	addiu	$a0,$a0,0x4
/*    4de24:	a6410000 */ 	sh	$at,0x0($s2)
/*    4de28:	8e690060 */ 	lw	$t1,0x60($s3)
/*    4de2c:	97ab0158 */ 	lhu	$t3,0x158($sp)
/*    4de30:	93ac0158 */ 	lbu	$t4,0x158($sp)
/*    4de34:	0169082a */ 	slt	$at,$t3,$t1
/*    4de38:	14200019 */ 	bnez	$at,.L0004dea0
/*    4de3c:	00000000 */ 	nop
/*    4de40:	120c0017 */ 	beq	$s0,$t4,.L0004dea0
/*    4de44:	93b80159 */ 	lbu	$t8,0x159($sp)
/*    4de48:	07010003 */ 	bgez	$t8,.L0004de58
/*    4de4c:	00186883 */ 	sra	$t5,$t8,0x2
/*    4de50:	27010003 */ 	addiu	$at,$t8,0x3
/*    4de54:	00016883 */ 	sra	$t5,$at,0x2
.L0004de58:
/*    4de58:	05810004 */ 	bgez	$t4,.L0004de6c
/*    4de5c:	318e0007 */ 	andi	$t6,$t4,0x7
/*    4de60:	11c00002 */ 	beqz	$t6,.L0004de6c
/*    4de64:	00000000 */ 	nop
/*    4de68:	25cefff8 */ 	addiu	$t6,$t6,-8
.L0004de6c:
/*    4de6c:	000e7940 */ 	sll	$t7,$t6,0x5
/*    4de70:	01af1821 */ 	addu	$v1,$t5,$t7
/*    4de74:	02831021 */ 	addu	$v0,$s4,$v1
/*    4de78:	90590101 */ 	lbu	$t9,0x101($v0)
/*    4de7c:	06010004 */ 	bgez	$s0,.L0004de90
/*    4de80:	32080007 */ 	andi	$t0,$s0,0x7
/*    4de84:	11000002 */ 	beqz	$t0,.L0004de90
/*    4de88:	00000000 */ 	nop
/*    4de8c:	2508fff8 */ 	addiu	$t0,$t0,-8
.L0004de90:
/*    4de90:	240a0001 */ 	addiu	$t2,$zero,0x1
/*    4de94:	010a5804 */ 	sllv	$t3,$t2,$t0
/*    4de98:	032b4825 */ 	or	$t1,$t9,$t3
/*    4de9c:	a0490101 */ 	sb	$t1,0x101($v0)
.L0004dea0:
/*    4dea0:	1496ffbe */ 	bne	$a0,$s6,.L0004dd9c
/*    4dea4:	24a50004 */ 	addiu	$a1,$a1,0x4
.L0004dea8:
/*    4dea8:	926c0064 */ 	lbu	$t4,0x64($s3)
/*    4deac:	26f70001 */ 	addiu	$s7,$s7,0x1
/*    4deb0:	32f000ff */ 	andi	$s0,$s7,0xff
/*    4deb4:	020c082a */ 	slt	$at,$s0,$t4
/*    4deb8:	1420ff7c */ 	bnez	$at,.L0004dcac
/*    4debc:	0200b825 */ 	or	$s7,$s0,$zero
.L0004dec0:
/*    4dec0:	00001025 */ 	or	$v0,$zero,$zero
/*    4dec4:	8fbf003c */ 	lw	$ra,0x3c($sp)
.L0004dec8:
/*    4dec8:	8fb00018 */ 	lw	$s0,0x18($sp)
/*    4decc:	8fb1001c */ 	lw	$s1,0x1c($sp)
/*    4ded0:	8fb20020 */ 	lw	$s2,0x20($sp)
/*    4ded4:	8fb30024 */ 	lw	$s3,0x24($sp)
/*    4ded8:	8fb40028 */ 	lw	$s4,0x28($sp)
/*    4dedc:	8fb5002c */ 	lw	$s5,0x2c($sp)
/*    4dee0:	8fb60030 */ 	lw	$s6,0x30($sp)
/*    4dee4:	8fb70034 */ 	lw	$s7,0x34($sp)
/*    4dee8:	8fbe0038 */ 	lw	$s8,0x38($sp)
/*    4deec:	03e00008 */ 	jr	$ra
/*    4def0:	27bd0168 */ 	addiu	$sp,$sp,0x168
);

GLOBAL_ASM(
glabel func0004def4
/*    4def4:	27bdffc8 */ 	addiu	$sp,$sp,-56
/*    4def8:	afa5003c */ 	sw	$a1,0x3c($sp)
/*    4defc:	93b8003c */ 	lbu	$t8,0x3c($sp)
/*    4df00:	afb40028 */ 	sw	$s4,0x28($sp)
/*    4df04:	93ae003d */ 	lbu	$t6,0x3d($sp)
/*    4df08:	0080a025 */ 	or	$s4,$a0,$zero
/*    4df0c:	afbf0034 */ 	sw	$ra,0x34($sp)
/*    4df10:	afb60030 */ 	sw	$s6,0x30($sp)
/*    4df14:	afb5002c */ 	sw	$s5,0x2c($sp)
/*    4df18:	afb30024 */ 	sw	$s3,0x24($sp)
/*    4df1c:	afb20020 */ 	sw	$s2,0x20($sp)
/*    4df20:	afb1001c */ 	sw	$s1,0x1c($sp)
/*    4df24:	afb00018 */ 	sw	$s0,0x18($sp)
/*    4df28:	92890064 */ 	lbu	$t1,0x64($s4)
/*    4df2c:	00c09825 */ 	or	$s3,$a2,$zero
/*    4df30:	00008025 */ 	or	$s0,$zero,$zero
/*    4df34:	05c10003 */ 	bgez	$t6,.L0004df44
/*    4df38:	000e7883 */ 	sra	$t7,$t6,0x2
/*    4df3c:	25c10003 */ 	addiu	$at,$t6,0x3
/*    4df40:	00017883 */ 	sra	$t7,$at,0x2
.L0004df44:
/*    4df44:	07010004 */ 	bgez	$t8,.L0004df58
/*    4df48:	33190007 */ 	andi	$t9,$t8,0x7
/*    4df4c:	13200002 */ 	beqz	$t9,.L0004df58
/*    4df50:	00000000 */ 	nop
/*    4df54:	2739fff8 */ 	addiu	$t9,$t9,-8
.L0004df58:
/*    4df58:	00194140 */ 	sll	$t0,$t9,0x5
/*    4df5c:	01e8b021 */ 	addu	$s6,$t7,$t0
/*    4df60:	19200040 */ 	blez	$t1,.L0004e064
/*    4df64:	00009025 */ 	or	$s2,$zero,$zero
/*    4df68:	00001025 */ 	or	$v0,$zero,$zero
/*    4df6c:	24150003 */ 	addiu	$s5,$zero,0x3
.L0004df70:
/*    4df70:	18400003 */ 	blez	$v0,.L0004df80
/*    4df74:	93aa003c */ 	lbu	$t2,0x3c($sp)
/*    4df78:	10000002 */ 	b	.L0004df84
/*    4df7c:	24110001 */ 	addiu	$s1,$zero,0x1
.L0004df80:
/*    4df80:	8e910060 */ 	lw	$s1,0x60($s4)
.L0004df84:
/*    4df84:	1142000c */ 	beq	$t2,$v0,.L0004dfb8
/*    4df88:	02765821 */ 	addu	$t3,$s3,$s6
/*    4df8c:	916c0101 */ 	lbu	$t4,0x101($t3)
/*    4df90:	04410004 */ 	bgez	$v0,.L0004dfa4
/*    4df94:	304d0007 */ 	andi	$t5,$v0,0x7
/*    4df98:	11a00002 */ 	beqz	$t5,.L0004dfa4
/*    4df9c:	00000000 */ 	nop
/*    4dfa0:	25adfff8 */ 	addiu	$t5,$t5,-8
.L0004dfa4:
/*    4dfa4:	240e0001 */ 	addiu	$t6,$zero,0x1
/*    4dfa8:	01aec004 */ 	sllv	$t8,$t6,$t5
/*    4dfac:	0198c824 */ 	and	$t9,$t4,$t8
/*    4dfb0:	53200027 */ 	beqzl	$t9,.L0004e050
/*    4dfb4:	928b0064 */ 	lbu	$t3,0x64($s4)
.L0004dfb8:
/*    4dfb8:	926f0100 */ 	lbu	$t7,0x100($s3)
/*    4dfbc:	02802025 */ 	or	$a0,$s4,$zero
/*    4dfc0:	02602825 */ 	or	$a1,$s3,$zero
/*    4dfc4:	11e2000a */ 	beq	$t7,$v0,.L0004dff0
/*    4dfc8:	00003025 */ 	or	$a2,$zero,$zero
/*    4dfcc:	0c01324d */ 	jal	func0004c934
/*    4dfd0:	324700ff */ 	andi	$a3,$s2,0xff
/*    4dfd4:	50400006 */ 	beqzl	$v0,.L0004dff0
/*    4dfd8:	a2720100 */ 	sb	$s2,0x100($s3)
/*    4dfdc:	50550004 */ 	beql	$v0,$s5,.L0004dff0
/*    4dfe0:	a2720100 */ 	sb	$s2,0x100($s3)
/*    4dfe4:	10000021 */ 	b	.L0004e06c
/*    4dfe8:	8fbf0034 */ 	lw	$ra,0x34($sp)
/*    4dfec:	a2720100 */ 	sb	$s2,0x100($s3)
.L0004dff0:
/*    4dff0:	2a010002 */ 	slti	$at,$s0,0x2
/*    4dff4:	10200010 */ 	beqz	$at,.L0004e038
/*    4dff8:	2a210080 */ 	slti	$at,$s1,0x80
/*    4dffc:	1020000e */ 	beqz	$at,.L0004e038
/*    4e000:	00111040 */ 	sll	$v0,$s1,0x1
/*    4e004:	02621821 */ 	addu	$v1,$s3,$v0
/*    4e008:	97a8003c */ 	lhu	$t0,0x3c($sp)
.L0004e00c:
/*    4e00c:	94690000 */ 	lhu	$t1,0x0($v1)
/*    4e010:	24420002 */ 	addiu	$v0,$v0,0x2
/*    4e014:	55090003 */ 	bnel	$t0,$t1,.L0004e024
/*    4e018:	2a010002 */ 	slti	$at,$s0,0x2
/*    4e01c:	26100001 */ 	addiu	$s0,$s0,0x1
/*    4e020:	2a010002 */ 	slti	$at,$s0,0x2
.L0004e024:
/*    4e024:	10200004 */ 	beqz	$at,.L0004e038
/*    4e028:	24630002 */ 	addiu	$v1,$v1,0x2
/*    4e02c:	28410100 */ 	slti	$at,$v0,0x100
/*    4e030:	5420fff6 */ 	bnezl	$at,.L0004e00c
/*    4e034:	97a8003c */ 	lhu	$t0,0x3c($sp)
.L0004e038:
/*    4e038:	2a010002 */ 	slti	$at,$s0,0x2
/*    4e03c:	54200004 */ 	bnezl	$at,.L0004e050
/*    4e040:	928b0064 */ 	lbu	$t3,0x64($s4)
/*    4e044:	10000008 */ 	b	.L0004e068
/*    4e048:	24020002 */ 	addiu	$v0,$zero,0x2
/*    4e04c:	928b0064 */ 	lbu	$t3,0x64($s4)
.L0004e050:
/*    4e050:	26520001 */ 	addiu	$s2,$s2,0x1
/*    4e054:	324200ff */ 	andi	$v0,$s2,0xff
/*    4e058:	004b082a */ 	slt	$at,$v0,$t3
/*    4e05c:	1420ffc4 */ 	bnez	$at,.L0004df70
/*    4e060:	00409025 */ 	or	$s2,$v0,$zero
.L0004e064:
/*    4e064:	02001025 */ 	or	$v0,$s0,$zero
.L0004e068:
/*    4e068:	8fbf0034 */ 	lw	$ra,0x34($sp)
.L0004e06c:
/*    4e06c:	8fb00018 */ 	lw	$s0,0x18($sp)
/*    4e070:	8fb1001c */ 	lw	$s1,0x1c($sp)
/*    4e074:	8fb20020 */ 	lw	$s2,0x20($sp)
/*    4e078:	8fb30024 */ 	lw	$s3,0x24($sp)
/*    4e07c:	8fb40028 */ 	lw	$s4,0x28($sp)
/*    4e080:	8fb5002c */ 	lw	$s5,0x2c($sp)
/*    4e084:	8fb60030 */ 	lw	$s6,0x30($sp)
/*    4e088:	03e00008 */ 	jr	$ra
/*    4e08c:	27bd0038 */ 	addiu	$sp,$sp,0x38
);

GLOBAL_ASM(
glabel func0004e090
/*    4e090:	28c10010 */ 	slti	$at,$a2,0x10
/*    4e094:	14200037 */ 	bnez	$at,.L0004e174
/*    4e098:	00851026 */ 	xor	$v0,$a0,$a1
/*    4e09c:	30420003 */ 	andi	$v0,$v0,0x3
/*    4e0a0:	14400019 */ 	bnez	$v0,.L0004e108
/*    4e0a4:	0004c023 */ 	negu	$t8,$a0
/*    4e0a8:	33180003 */ 	andi	$t8,$t8,0x3
/*    4e0ac:	13000007 */ 	beqz	$t8,.L0004e0cc
/*    4e0b0:	00d83023 */ 	subu	$a2,$a2,$t8
/*    4e0b4:	00601025 */ 	or	$v0,$v1,$zero
/*    4e0b8:	88820000 */ 	lwl	$v0,0x0($a0)
/*    4e0bc:	88a30000 */ 	lwl	$v1,0x0($a1)
/*    4e0c0:	00982021 */ 	addu	$a0,$a0,$t8
/*    4e0c4:	00b82821 */ 	addu	$a1,$a1,$t8
/*    4e0c8:	14430036 */ 	bne	$v0,$v1,.L0004e1a4
.L0004e0cc:
/*    4e0cc:	2401fffc */ 	addiu	$at,$zero,-4
/*    4e0d0:	00c13824 */ 	and	$a3,$a2,$at
/*    4e0d4:	10e00027 */ 	beqz	$a3,.L0004e174
/*    4e0d8:	00c73023 */ 	subu	$a2,$a2,$a3
/*    4e0dc:	00e43821 */ 	addu	$a3,$a3,$a0
/*    4e0e0:	8c820000 */ 	lw	$v0,0x0($a0)
.L0004e0e4:
/*    4e0e4:	8ca30000 */ 	lw	$v1,0x0($a1)
/*    4e0e8:	24840004 */ 	addiu	$a0,$a0,0x4
/*    4e0ec:	24a50004 */ 	addiu	$a1,$a1,0x4
/*    4e0f0:	1443002c */ 	bne	$v0,$v1,.L0004e1a4
/*    4e0f4:	00000000 */ 	nop
/*    4e0f8:	5487fffa */ 	bnel	$a0,$a3,.L0004e0e4
/*    4e0fc:	8c820000 */ 	lw	$v0,0x0($a0)
/*    4e100:	1000001c */ 	b	.L0004e174
/*    4e104:	00000000 */ 	nop
.L0004e108:
/*    4e108:	00053823 */ 	negu	$a3,$a1
/*    4e10c:	30e70003 */ 	andi	$a3,$a3,0x3
/*    4e110:	10e0000a */ 	beqz	$a3,.L0004e13c
/*    4e114:	00c73023 */ 	subu	$a2,$a2,$a3
/*    4e118:	00e43821 */ 	addu	$a3,$a3,$a0
/*    4e11c:	90820000 */ 	lbu	$v0,0x0($a0)
.L0004e120:
/*    4e120:	90a30000 */ 	lbu	$v1,0x0($a1)
/*    4e124:	24840001 */ 	addiu	$a0,$a0,0x1
/*    4e128:	24a50001 */ 	addiu	$a1,$a1,0x1
/*    4e12c:	1443001d */ 	bne	$v0,$v1,.L0004e1a4
/*    4e130:	00000000 */ 	nop
/*    4e134:	5487fffa */ 	bnel	$a0,$a3,.L0004e120
/*    4e138:	90820000 */ 	lbu	$v0,0x0($a0)
.L0004e13c:
/*    4e13c:	2401fffc */ 	addiu	$at,$zero,-4
/*    4e140:	00c13824 */ 	and	$a3,$a2,$at
/*    4e144:	10e0000b */ 	beqz	$a3,.L0004e174
/*    4e148:	00c73023 */ 	subu	$a2,$a2,$a3
/*    4e14c:	00e43821 */ 	addu	$a3,$a3,$a0
/*    4e150:	88820000 */ 	lwl	$v0,0x0($a0)
.L0004e154:
/*    4e154:	8ca30000 */ 	lw	$v1,0x0($a1)
/*    4e158:	98820003 */ 	lwr	$v0,0x3($a0)
/*    4e15c:	24840004 */ 	addiu	$a0,$a0,0x4
/*    4e160:	24a50004 */ 	addiu	$a1,$a1,0x4
/*    4e164:	1443000f */ 	bne	$v0,$v1,.L0004e1a4
/*    4e168:	00000000 */ 	nop
/*    4e16c:	5487fff9 */ 	bnel	$a0,$a3,.L0004e154
/*    4e170:	88820000 */ 	lwl	$v0,0x0($a0)
.L0004e174:
/*    4e174:	18c00009 */ 	blez	$a2,.L0004e19c
/*    4e178:	00c43821 */ 	addu	$a3,$a2,$a0
/*    4e17c:	90820000 */ 	lbu	$v0,0x0($a0)
.L0004e180:
/*    4e180:	90a30000 */ 	lbu	$v1,0x0($a1)
/*    4e184:	24840001 */ 	addiu	$a0,$a0,0x1
/*    4e188:	24a50001 */ 	addiu	$a1,$a1,0x1
/*    4e18c:	14430005 */ 	bne	$v0,$v1,.L0004e1a4
/*    4e190:	00000000 */ 	nop
/*    4e194:	5487fffa */ 	bnel	$a0,$a3,.L0004e180
/*    4e198:	90820000 */ 	lbu	$v0,0x0($a0)
.L0004e19c:
/*    4e19c:	03e00008 */ 	jr	$ra
/*    4e1a0:	00001025 */ 	or	$v0,$zero,$zero
.L0004e1a4:
/*    4e1a4:	03e00008 */ 	jr	$ra
/*    4e1a8:	24020001 */ 	addiu	$v0,$zero,0x1
/*    4e1ac:	00000000 */ 	nop
);
