#include <ultra64.h>
#include "constants.h"
#include "game/data/data_000000.h"
#include "game/data/data_0083d0.h"
#include "game/data/data_00e460.h"
#include "game/data/data_0160b0.h"
#include "game/data/data_01a3a0.h"
#include "game/data/data_020df0.h"
#include "game/game_0147d0.h"
#include "game/game_01e250.h"
#include "game/game_02cde0.h"
#include "game/game_0601b0.h"
#include "game/mplayer.h"
#include "game/game_197600.h"
#include "gvars/gvars.h"
#include "lib/lib_121e0.h"
#include "lib/lib_12dc0.h"
#include "lib/lib_16110.h"
#include "lib/lib_1a500.h"
#include "types.h"

GLOBAL_ASM(
glabel func0f0147d0
/*  f0147d0:	3c03800a */ 	lui	$v1,%hi(var8009da60)
/*  f0147d4:	3c04800a */ 	lui	$a0,%hi(var8009dbe0)
/*  f0147d8:	2484dbe0 */ 	addiu	$a0,$a0,%lo(var8009dbe0)
/*  f0147dc:	2463da60 */ 	addiu	$v1,$v1,%lo(var8009da60)
/*  f0147e0:	2402ffff */ 	addiu	$v0,$zero,-1
.L0f0147e4:
/*  f0147e4:	24630030 */ 	addiu	$v1,$v1,0x30
/*  f0147e8:	1464fffe */ 	bne	$v1,$a0,.L0f0147e4
/*  f0147ec:	ac62ffd0 */ 	sw	$v0,-0x30($v1)
/*  f0147f0:	03e00008 */ 	jr	$ra
/*  f0147f4:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f0147f8
/*  f0147f8:	3c03800a */ 	lui	$v1,%hi(var8009dbe0)
/*  f0147fc:	3c04800a */ 	lui	$a0,%hi(var8009dd00)
/*  f014800:	2484dd00 */ 	addiu	$a0,$a0,%lo(var8009dd00)
/*  f014804:	2463dbe0 */ 	addiu	$v1,$v1,%lo(var8009dbe0)
/*  f014808:	2402ffff */ 	addiu	$v0,$zero,-1
.L0f01480c:
/*  f01480c:	24630048 */ 	addiu	$v1,$v1,0x48
/*  f014810:	1464fffe */ 	bne	$v1,$a0,.L0f01480c
/*  f014814:	ac62ffb8 */ 	sw	$v0,-0x48($v1)
/*  f014818:	03e00008 */ 	jr	$ra
/*  f01481c:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f014820
/*  f014820:	3c03800b */ 	lui	$v1,%hi(g_MpSimulantChrs)
/*  f014824:	3c02800b */ 	lui	$v0,%hi(var800acca0)
/*  f014828:	2442cca0 */ 	addiu	$v0,$v0,%lo(var800acca0)
/*  f01482c:	2463cc80 */ 	addiu	$v1,$v1,%lo(g_MpSimulantChrs)
.L0f014830:
/*  f014830:	24630004 */ 	addiu	$v1,$v1,0x4
/*  f014834:	1462fffe */ 	bne	$v1,$v0,.L0f014830
/*  f014838:	ac60fffc */ 	sw	$zero,-0x4($v1)
/*  f01483c:	3c018008 */ 	lui	$at,0x8008
/*  f014840:	03e00008 */ 	jr	$ra
/*  f014844:	a0207d10 */ 	sb	$zero,0x7d10($at)
);

GLOBAL_ASM(
glabel func0f014848
.late_rodata
glabel var7f1a82a0
.word func0f014848+0x2f0 # f014b38
glabel var7f1a82a4
.word func0f014848+0x2f8 # f014b40
glabel var7f1a82a8
.word func0f014848+0x304 # f014b4c
glabel var7f1a82ac
.word func0f014848+0x310 # f014b58
glabel var7f1a82b0
.word func0f014848+0x31c # f014b64
glabel var7f1a82b4
.word func0f014848+0x328 # f014b70
.text
/*  f014848:	27bdff88 */ 	addiu	$sp,$sp,-120
/*  f01484c:	0005c080 */ 	sll	$t8,$a1,0x2
/*  f014850:	0305c021 */ 	addu	$t8,$t8,$a1
/*  f014854:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f014858:	0305c023 */ 	subu	$t8,$t8,$a1
/*  f01485c:	3c19800b */ 	lui	$t9,%hi(g_MpSimulants)
/*  f014860:	2739c538 */ 	addiu	$t9,$t9,%lo(g_MpSimulants)
/*  f014864:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f014868:	afbf002c */ 	sw	$ra,0x2c($sp)
/*  f01486c:	afa40078 */ 	sw	$a0,0x78($sp)
/*  f014870:	240effff */ 	addiu	$t6,$zero,-1
/*  f014874:	03191021 */ 	addu	$v0,$t8,$t9
/*  f014878:	afb00028 */ 	sw	$s0,0x28($sp)
/*  f01487c:	f7b40020 */ 	sdc1	$f20,0x20($sp)
/*  f014880:	afa5007c */ 	sw	$a1,0x7c($sp)
/*  f014884:	a7ae0074 */ 	sh	$t6,0x74($sp)
/*  f014888:	9044000f */ 	lbu	$a0,0xf($v0)
/*  f01488c:	0fc62ecb */ 	jal	mpGetHeadId
/*  f014890:	afa2003c */ 	sw	$v0,0x3c($sp)
/*  f014894:	8fa9003c */ 	lw	$t1,0x3c($sp)
/*  f014898:	afa20058 */ 	sw	$v0,0x58($sp)
/*  f01489c:	0fc62ee4 */ 	jal	mpGetBodyId
/*  f0148a0:	91240010 */ 	lbu	$a0,0x10($t1)
/*  f0148a4:	3c0a8009 */ 	lui	$t2,%hi(g_Is4Mb)
/*  f0148a8:	914a0af0 */ 	lbu	$t2,%lo(g_Is4Mb)($t2)
/*  f0148ac:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0148b0:	00402025 */ 	or	$a0,$v0,$zero
/*  f0148b4:	15410004 */ 	bne	$t2,$at,.L0f0148c8
/*  f0148b8:	00003025 */ 	or	$a2,$zero,$zero
/*  f0148bc:	240b000a */ 	addiu	$t3,$zero,0xa
/*  f0148c0:	afab0058 */ 	sw	$t3,0x58($sp)
/*  f0148c4:	2404005e */ 	addiu	$a0,$zero,0x5e
.L0f0148c8:
/*  f0148c8:	8fa50058 */ 	lw	$a1,0x58($sp)
/*  f0148cc:	0fc0b4db */ 	jal	func0f02d36c
/*  f0148d0:	afa4005c */ 	sw	$a0,0x5c($sp)
/*  f0148d4:	10400169 */ 	beqz	$v0,.L0f014e7c
/*  f0148d8:	00408025 */ 	or	$s0,$v0,$zero
/*  f0148dc:	3c0d8006 */ 	lui	$t5,%hi(var80062400)
/*  f0148e0:	25ad2400 */ 	addiu	$t5,$t5,%lo(var80062400)
/*  f0148e4:	8da10000 */ 	lw	$at,0x0($t5)
/*  f0148e8:	27ac004c */ 	addiu	$t4,$sp,0x4c
/*  f0148ec:	8daf0004 */ 	lw	$t7,0x4($t5)
/*  f0148f0:	ad810000 */ 	sw	$at,0x0($t4)
/*  f0148f4:	8da10008 */ 	lw	$at,0x8($t5)
/*  f0148f8:	24040029 */ 	addiu	$a0,$zero,0x29
/*  f0148fc:	ad8f0004 */ 	sw	$t7,0x4($t4)
/*  f014900:	0c006134 */ 	jal	ailistFindById
/*  f014904:	ad810008 */ 	sw	$at,0x8($t4)
/*  f014908:	4480a000 */ 	mtc1	$zero,$f20
/*  f01490c:	02002025 */ 	or	$a0,$s0,$zero
/*  f014910:	27a5004c */ 	addiu	$a1,$sp,0x4c
/*  f014914:	4407a000 */ 	mfc1	$a3,$f20
/*  f014918:	27a60074 */ 	addiu	$a2,$sp,0x74
/*  f01491c:	0fc08332 */ 	jal	func0f020cc8
/*  f014920:	afa20010 */ 	sw	$v0,0x10($sp)
/*  f014924:	10400155 */ 	beqz	$v0,.L0f014e7c
/*  f014928:	00402025 */ 	or	$a0,$v0,$zero
/*  f01492c:	0fc1812f */ 	jal	func0f0604bc
/*  f014930:	afa20070 */ 	sw	$v0,0x70($sp)
/*  f014934:	0fc180bc */ 	jal	propHide
/*  f014938:	8fa40070 */ 	lw	$a0,0x70($sp)
/*  f01493c:	8fb80070 */ 	lw	$t8,0x70($sp)
/*  f014940:	87a5007a */ 	lh	$a1,0x7a($sp)
/*  f014944:	8f100004 */ 	lw	$s0,0x4($t8)
/*  f014948:	0fc07937 */ 	jal	chrSetChrnum
/*  f01494c:	02002025 */ 	or	$a0,$s0,$zero
/*  f014950:	3c013f80 */ 	lui	$at,0x3f80
/*  f014954:	8fb90078 */ 	lw	$t9,0x78($sp)
/*  f014958:	44812000 */ 	mtc1	$at,$f4
/*  f01495c:	3c0142a0 */ 	lui	$at,0x42a0
/*  f014960:	44813000 */ 	mtc1	$at,$f6
/*  f014964:	2407ffff */ 	addiu	$a3,$zero,-1
/*  f014968:	a6070128 */ 	sh	$a3,0x128($s0)
/*  f01496c:	a607012a */ 	sh	$a3,0x12a($s0)
/*  f014970:	a6190000 */ 	sh	$t9,0x0($s0)
/*  f014974:	e60400f0 */ 	swc1	$f4,0xf0($s0)
/*  f014978:	e60600dc */ 	swc1	$f6,0xdc($s0)
/*  f01497c:	8fa90058 */ 	lw	$t1,0x58($sp)
/*  f014980:	a2090006 */ 	sb	$t1,0x6($s0)
/*  f014984:	8faa005c */ 	lw	$t2,0x5c($sp)
/*  f014988:	a60a0010 */ 	sh	$t2,0x10($s0)
/*  f01498c:	0fc0b378 */ 	jal	bodyGetRace
/*  f014990:	86040010 */ 	lh	$a0,0x10($s0)
/*  f014994:	240b0008 */ 	addiu	$t3,$zero,0x8
/*  f014998:	a20202fe */ 	sb	$v0,0x2fe($s0)
/*  f01499c:	ae0b0114 */ 	sw	$t3,0x114($s0)
/*  f0149a0:	ae000118 */ 	sw	$zero,0x118($s0)
/*  f0149a4:	8fae003c */ 	lw	$t6,0x3c($sp)
/*  f0149a8:	240d0001 */ 	addiu	$t5,$zero,0x1
/*  f0149ac:	3c088008 */ 	lui	$t0,%hi(g_NumMpSimulantChrs)
/*  f0149b0:	91cc0011 */ 	lbu	$t4,0x11($t6)
/*  f0149b4:	25087d10 */ 	addiu	$t0,$t0,%lo(g_NumMpSimulantChrs)
/*  f0149b8:	a20002a2 */ 	sb	$zero,0x2a2($s0)
/*  f0149bc:	018d7804 */ 	sllv	$t7,$t5,$t4
/*  f0149c0:	a20f0125 */ 	sb	$t7,0x125($s0)
/*  f0149c4:	91030000 */ 	lbu	$v1,0x0($t0)
/*  f0149c8:	240402e0 */ 	addiu	$a0,$zero,0x2e0
/*  f0149cc:	24050004 */ 	addiu	$a1,$zero,0x4
/*  f0149d0:	28610008 */ 	slti	$at,$v1,0x8
/*  f0149d4:	10200129 */ 	beqz	$at,.L0f014e7c
/*  f0149d8:	0003c080 */ 	sll	$t8,$v1,0x2
/*  f0149dc:	3c01800b */ 	lui	$at,0x800b
/*  f0149e0:	00380821 */ 	addu	$at,$at,$t8
/*  f0149e4:	ac30cc80 */ 	sw	$s0,-0x3380($at)
/*  f0149e8:	24790001 */ 	addiu	$t9,$v1,0x1
/*  f0149ec:	0c0048f2 */ 	jal	malloc
/*  f0149f0:	a1190000 */ 	sb	$t9,0x0($t0)
/*  f0149f4:	3c088008 */ 	lui	$t0,%hi(g_NumMpSimulantChrs)
/*  f0149f8:	25087d10 */ 	addiu	$t0,$t0,%lo(g_NumMpSimulantChrs)
/*  f0149fc:	10400113 */ 	beqz	$v0,.L0f014e4c
/*  f014a00:	ae0202d4 */ 	sw	$v0,0x2d4($s0)
/*  f014a04:	a20002b0 */ 	sb	$zero,0x2b0($s0)
/*  f014a08:	0c004b70 */ 	jal	random
/*  f014a0c:	afa20068 */ 	sw	$v0,0x68($sp)
/*  f014a10:	24030003 */ 	addiu	$v1,$zero,0x3
/*  f014a14:	0043001b */ 	divu	$zero,$v0,$v1
/*  f014a18:	860a0010 */ 	lh	$t2,0x10($s0)
/*  f014a1c:	00004810 */ 	mfhi	$t1
/*  f014a20:	8fa60068 */ 	lw	$a2,0x68($sp)
/*  f014a24:	000a5880 */ 	sll	$t3,$t2,0x2
/*  f014a28:	016a5821 */ 	addu	$t3,$t3,$t2
/*  f014a2c:	000b5880 */ 	sll	$t3,$t3,0x2
/*  f014a30:	3c0e8008 */ 	lui	$t6,%hi(g_Bodies)
/*  f014a34:	a20902b1 */ 	sb	$t1,0x2b1($s0)
/*  f014a38:	01cb7021 */ 	addu	$t6,$t6,$t3
/*  f014a3c:	8dcecf04 */ 	lw	$t6,%lo(g_Bodies)($t6)
/*  f014a40:	2407ffff */ 	addiu	$a3,$zero,-1
/*  f014a44:	14600002 */ 	bnez	$v1,.L0f014a50
/*  f014a48:	00000000 */ 	sll	$zero,$zero,0x0
/*  f014a4c:	0007000d */ 	break	0x7
.L0f014a50:
/*  f014a50:	000e6fc2 */ 	srl	$t5,$t6,0x1f
/*  f014a54:	15a00002 */ 	bnez	$t5,.L0f014a60
/*  f014a58:	3c08800b */ 	lui	$t0,%hi(g_MpNumPlayers)
/*  f014a5c:	a20302b1 */ 	sb	$v1,0x2b1($s0)
.L0f014a60:
/*  f014a60:	240c0029 */ 	addiu	$t4,$zero,0x29
/*  f014a64:	a607017e */ 	sh	$a3,0x17e($s0)
/*  f014a68:	a20002e3 */ 	sb	$zero,0x2e3($s0)
/*  f014a6c:	ae0702e4 */ 	sw	$a3,0x2e4($s0)
/*  f014a70:	a20002fc */ 	sb	$zero,0x2fc($s0)
/*  f014a74:	a20002e2 */ 	sb	$zero,0x2e2($s0)
/*  f014a78:	ae0002a4 */ 	sw	$zero,0x2a4($s0)
/*  f014a7c:	a20c02a0 */ 	sb	$t4,0x2a0($s0)
/*  f014a80:	8faf007c */ 	lw	$t7,0x7c($sp)
/*  f014a84:	2508c530 */ 	addiu	$t0,$t0,%lo(g_MpNumPlayers)
/*  f014a88:	8d020000 */ 	lw	$v0,0x0($t0)
/*  f014a8c:	000fc080 */ 	sll	$t8,$t7,0x2
/*  f014a90:	3c01800b */ 	lui	$at,0x800b
/*  f014a94:	030fc021 */ 	addu	$t8,$t8,$t7
/*  f014a98:	00021880 */ 	sll	$v1,$v0,0x2
/*  f014a9c:	00230821 */ 	addu	$at,$at,$v1
/*  f014aa0:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f014aa4:	ac30c4d0 */ 	sw	$s0,-0x3b30($at)
/*  f014aa8:	3c19800b */ 	lui	$t9,%hi(g_MpSimulants)
/*  f014aac:	030fc023 */ 	subu	$t8,$t8,$t7
/*  f014ab0:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f014ab4:	2739c538 */ 	addiu	$t9,$t9,%lo(g_MpSimulants)
/*  f014ab8:	3c01800b */ 	lui	$at,0x800b
/*  f014abc:	00230821 */ 	addu	$at,$at,$v1
/*  f014ac0:	03194821 */ 	addu	$t1,$t8,$t9
/*  f014ac4:	ac29c500 */ 	sw	$t1,-0x3b00($at)
/*  f014ac8:	244a0001 */ 	addiu	$t2,$v0,0x1
/*  f014acc:	ad0a0000 */ 	sw	$t2,0x0($t0)
/*  f014ad0:	afa60068 */ 	sw	$a2,0x68($sp)
/*  f014ad4:	24040090 */ 	addiu	$a0,$zero,0x90
/*  f014ad8:	0c0048f2 */ 	jal	malloc
/*  f014adc:	24050004 */ 	addiu	$a1,$zero,0x4
/*  f014ae0:	8fa60068 */ 	lw	$a2,0x68($sp)
/*  f014ae4:	2407ffff */ 	addiu	$a3,$zero,-1
/*  f014ae8:	00001825 */ 	or	$v1,$zero,$zero
/*  f014aec:	acc2001c */ 	sw	$v0,0x1c($a2)
.L0f014af0:
/*  f014af0:	8ccb001c */ 	lw	$t3,0x1c($a2)
/*  f014af4:	01637021 */ 	addu	$t6,$t3,$v1
/*  f014af8:	24630004 */ 	addiu	$v1,$v1,0x4
/*  f014afc:	28610084 */ 	slti	$at,$v1,0x84
/*  f014b00:	1420fffb */ 	bnez	$at,.L0f014af0
/*  f014b04:	adc00000 */ 	sw	$zero,0x0($t6)
/*  f014b08:	8fad003c */ 	lw	$t5,0x3c($sp)
/*  f014b0c:	accd0004 */ 	sw	$t5,0x4($a2)
/*  f014b10:	8fac003c */ 	lw	$t4,0x3c($sp)
/*  f014b14:	918f0048 */ 	lbu	$t7,0x48($t4)
/*  f014b18:	2de10006 */ 	sltiu	$at,$t7,0x6
/*  f014b1c:	1020000b */ 	beqz	$at,.L0f014b4c
/*  f014b20:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f014b24:	3c017f1b */ 	lui	$at,%hi(var7f1a82a0)
/*  f014b28:	002f0821 */ 	addu	$at,$at,$t7
/*  f014b2c:	8c2f82a0 */ 	lw	$t7,%lo(var7f1a82a0)($at)
/*  f014b30:	01e00008 */ 	jr	$t7
/*  f014b34:	00000000 */ 	sll	$zero,$zero,0x0
/*  f014b38:	1000000e */ 	beqz	$zero,.L0f014b74
/*  f014b3c:	a0c00000 */ 	sb	$zero,0x0($a2)
/*  f014b40:	2418000a */ 	addiu	$t8,$zero,0xa
/*  f014b44:	1000000b */ 	beqz	$zero,.L0f014b74
/*  f014b48:	a0d80000 */ 	sb	$t8,0x0($a2)
.L0f014b4c:
/*  f014b4c:	24190014 */ 	addiu	$t9,$zero,0x14
/*  f014b50:	10000008 */ 	beqz	$zero,.L0f014b74
/*  f014b54:	a0d90000 */ 	sb	$t9,0x0($a2)
/*  f014b58:	24090028 */ 	addiu	$t1,$zero,0x28
/*  f014b5c:	10000005 */ 	beqz	$zero,.L0f014b74
/*  f014b60:	a0c90000 */ 	sb	$t1,0x0($a2)
/*  f014b64:	240a003c */ 	addiu	$t2,$zero,0x3c
/*  f014b68:	10000002 */ 	beqz	$zero,.L0f014b74
/*  f014b6c:	a0ca0000 */ 	sb	$t2,0x0($a2)
/*  f014b70:	a0c00000 */ 	sb	$zero,0x0($a2)
.L0f014b74:
/*  f014b74:	8fab007c */ 	lw	$t3,0x7c($sp)
/*  f014b78:	240e012d */ 	addiu	$t6,$zero,0x12d
/*  f014b7c:	240d0004 */ 	addiu	$t5,$zero,0x4
/*  f014b80:	a4c00064 */ 	sh	$zero,0x64($a2)
/*  f014b84:	acc00010 */ 	sw	$zero,0x10($a2)
/*  f014b88:	a4c0002c */ 	sh	$zero,0x2c($a2)
/*  f014b8c:	a4c0002e */ 	sh	$zero,0x2e($a2)
/*  f014b90:	acc00034 */ 	sw	$zero,0x34($a2)
/*  f014b94:	e4d40040 */ 	swc1	$f20,0x40($a2)
/*  f014b98:	acc00024 */ 	sw	$zero,0x24($a2)
/*  f014b9c:	acc00028 */ 	sw	$zero,0x28($a2)
/*  f014ba0:	a0c00058 */ 	sb	$zero,0x58($a2)
/*  f014ba4:	a0c00059 */ 	sb	$zero,0x59($a2)
/*  f014ba8:	acc0005c */ 	sw	$zero,0x5c($a2)
/*  f014bac:	acc00060 */ 	sw	$zero,0x60($a2)
/*  f014bb0:	acce0030 */ 	sw	$t6,0x30($a2)
/*  f014bb4:	acc00038 */ 	sw	$zero,0x38($a2)
/*  f014bb8:	a4c7003e */ 	sh	$a3,0x3e($a2)
/*  f014bbc:	a4c0003c */ 	sh	$zero,0x3c($a2)
/*  f014bc0:	a4c70008 */ 	sh	$a3,0x8($a2)
/*  f014bc4:	a4c7000a */ 	sh	$a3,0xa($a2)
/*  f014bc8:	a4c7000c */ 	sh	$a3,0xc($a2)
/*  f014bcc:	acc00068 */ 	sw	$zero,0x68($a2)
/*  f014bd0:	e4d4006c */ 	swc1	$f20,0x6c($a2)
/*  f014bd4:	e4d40070 */ 	swc1	$f20,0x70($a2)
/*  f014bd8:	a0c70074 */ 	sb	$a3,0x74($a2)
/*  f014bdc:	a4c70076 */ 	sh	$a3,0x76($a2)
/*  f014be0:	acc70114 */ 	sw	$a3,0x114($a2)
/*  f014be4:	a0cd0079 */ 	sb	$t5,0x79($a2)
/*  f014be8:	e4d40098 */ 	swc1	$f20,0x98($a2)
/*  f014bec:	a4cb0002 */ 	sh	$t3,0x2($a2)
/*  f014bf0:	c7a8004c */ 	lwc1	$f8,0x4c($sp)
/*  f014bf4:	90cf004c */ 	lbu	$t7,0x4c($a2)
/*  f014bf8:	90cb004f */ 	lbu	$t3,0x4f($a2)
/*  f014bfc:	e4c8008c */ 	swc1	$f8,0x8c($a2)
/*  f014c00:	c7aa0050 */ 	lwc1	$f10,0x50($sp)
/*  f014c04:	90cd009c */ 	lbu	$t5,0x9c($a2)
/*  f014c08:	31e9ffdf */ 	andi	$t1,$t7,0xffdf
/*  f014c0c:	e4ca0090 */ 	swc1	$f10,0x90($a2)
/*  f014c10:	c7b00054 */ 	lwc1	$f16,0x54($sp)
/*  f014c14:	316eff7f */ 	andi	$t6,$t3,0xff7f
/*  f014c18:	240c0001 */ 	addiu	$t4,$zero,0x1
/*  f014c1c:	35390040 */ 	ori	$t9,$t1,0x40
/*  f014c20:	a0ce004f */ 	sb	$t6,0x4f($a2)
/*  f014c24:	accc0020 */ 	sw	$t4,0x20($a2)
/*  f014c28:	a0c9004c */ 	sb	$t1,0x4c($a2)
/*  f014c2c:	332e00fd */ 	andi	$t6,$t9,0xfd
/*  f014c30:	a0d9004c */ 	sb	$t9,0x4c($a2)
/*  f014c34:	31cc00f7 */ 	andi	$t4,$t6,0xf7
/*  f014c38:	31afff7f */ 	andi	$t7,$t5,0xff7f
/*  f014c3c:	31ea00bf */ 	andi	$t2,$t7,0xbf
/*  f014c40:	a0ce004c */ 	sb	$t6,0x4c($a2)
/*  f014c44:	319800ef */ 	andi	$t8,$t4,0xef
/*  f014c48:	a0cf009c */ 	sb	$t7,0x9c($a2)
/*  f014c4c:	a0cc004c */ 	sb	$t4,0x4c($a2)
/*  f014c50:	330900fb */ 	andi	$t1,$t8,0xfb
/*  f014c54:	a0ca009c */ 	sb	$t2,0x9c($a2)
/*  f014c58:	314b00df */ 	andi	$t3,$t2,0xdf
/*  f014c5c:	a0d8004c */ 	sb	$t8,0x4c($a2)
/*  f014c60:	a0c9004c */ 	sb	$t1,0x4c($a2)
/*  f014c64:	312a007f */ 	andi	$t2,$t1,0x7f
/*  f014c68:	a0c0004d */ 	sb	$zero,0x4d($a2)
/*  f014c6c:	a0c0004e */ 	sb	$zero,0x4e($a2)
/*  f014c70:	acc00044 */ 	sw	$zero,0x44($a2)
/*  f014c74:	acc000a0 */ 	sw	$zero,0xa0($a2)
/*  f014c78:	a0cb009c */ 	sb	$t3,0x9c($a2)
/*  f014c7c:	a0ca004c */ 	sb	$t2,0x4c($a2)
/*  f014c80:	a4c70048 */ 	sh	$a3,0x48($a2)
/*  f014c84:	a4c7004a */ 	sh	$a3,0x4a($a2)
/*  f014c88:	acc700bc */ 	sw	$a3,0xbc($a2)
/*  f014c8c:	acc000c8 */ 	sw	$zero,0xc8($a2)
/*  f014c90:	acc000c4 */ 	sw	$zero,0xc4($a2)
/*  f014c94:	acc000cc */ 	sw	$zero,0xcc($a2)
/*  f014c98:	acc000d0 */ 	sw	$zero,0xd0($a2)
/*  f014c9c:	acc000d8 */ 	sw	$zero,0xd8($a2)
/*  f014ca0:	acc000dc */ 	sw	$zero,0xdc($a2)
/*  f014ca4:	a4c000e2 */ 	sh	$zero,0xe2($a2)
/*  f014ca8:	a4c000e0 */ 	sh	$zero,0xe0($a2)
/*  f014cac:	e4d400e8 */ 	swc1	$f20,0xe8($a2)
/*  f014cb0:	e4d400e4 */ 	swc1	$f20,0xe4($a2)
/*  f014cb4:	e4d00094 */ 	swc1	$f16,0x94($a2)
/*  f014cb8:	8e040020 */ 	lw	$a0,0x20($s0)
/*  f014cbc:	0c006b91 */ 	jal	func0001ae44
/*  f014cc0:	afa60068 */ 	sw	$a2,0x68($sp)
/*  f014cc4:	8fa60068 */ 	lw	$a2,0x68($sp)
/*  f014cc8:	e4c000a4 */ 	swc1	$f0,0xa4($a2)
/*  f014ccc:	e4d400a8 */ 	swc1	$f20,0xa8($a2)
/*  f014cd0:	e4d400ac */ 	swc1	$f20,0xac($a2)
/*  f014cd4:	0c006b91 */ 	jal	func0001ae44
/*  f014cd8:	8e040020 */ 	lw	$a0,0x20($s0)
/*  f014cdc:	8fa60068 */ 	lw	$a2,0x68($sp)
/*  f014ce0:	2407ffff */ 	addiu	$a3,$zero,-1
/*  f014ce4:	3c014f80 */ 	lui	$at,0x4f80
/*  f014ce8:	e4c000b0 */ 	swc1	$f0,0xb0($a2)
/*  f014cec:	44810000 */ 	mtc1	$at,$f0
/*  f014cf0:	00002825 */ 	or	$a1,$zero,$zero
/*  f014cf4:	e4d400b4 */ 	swc1	$f20,0xb4($a2)
/*  f014cf8:	e4d400b8 */ 	swc1	$f20,0xb8($a2)
/*  f014cfc:	e4d40108 */ 	swc1	$f20,0x108($a2)
/*  f014d00:	e4d4010c */ 	swc1	$f20,0x10c($a2)
/*  f014d04:	e4d40110 */ 	swc1	$f20,0x110($a2)
/*  f014d08:	acc00118 */ 	sw	$zero,0x118($a2)
/*  f014d0c:	acc0011c */ 	sw	$zero,0x11c($a2)
/*  f014d10:	acc70120 */ 	sw	$a3,0x120($a2)
/*  f014d14:	acc70124 */ 	sw	$a3,0x124($a2)
/*  f014d18:	acc00128 */ 	sw	$zero,0x128($a2)
/*  f014d1c:	acc0012c */ 	sw	$zero,0x12c($a2)
/*  f014d20:	00c01025 */ 	or	$v0,$a2,$zero
/*  f014d24:	00c02025 */ 	or	$a0,$a2,$zero
/*  f014d28:	00c01825 */ 	or	$v1,$a2,$zero
.L0f014d2c:
/*  f014d2c:	a0470130 */ 	sb	$a3,0x130($v0)
/*  f014d30:	e480013c */ 	swc1	$f0,0x13c($a0)
/*  f014d34:	24a50001 */ 	addiu	$a1,$a1,0x1
/*  f014d38:	a040016c */ 	sb	$zero,0x16c($v0)
/*  f014d3c:	28a1000c */ 	slti	$at,$a1,0xc
/*  f014d40:	ac870178 */ 	sw	$a3,0x178($a0)
/*  f014d44:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f014d48:	24840004 */ 	addiu	$a0,$a0,0x4
/*  f014d4c:	24630002 */ 	addiu	$v1,$v1,0x2
/*  f014d50:	1420fff6 */ 	bnez	$at,.L0f014d2c
/*  f014d54:	a46701a6 */ 	sh	$a3,0x1a6($v1)
/*  f014d58:	e4d401c0 */ 	swc1	$f20,0x1c0($a2)
/*  f014d5c:	e4d401c4 */ 	swc1	$f20,0x1c4($a2)
/*  f014d60:	e4d401c8 */ 	swc1	$f20,0x1c8($a2)
/*  f014d64:	acc701cc */ 	sw	$a3,0x1cc($a2)
/*  f014d68:	acc001d0 */ 	sw	$zero,0x1d0($a2)
/*  f014d6c:	e4d401d4 */ 	swc1	$f20,0x1d4($a2)
/*  f014d70:	acc701e4 */ 	sw	$a3,0x1e4($a2)
/*  f014d74:	acc001e8 */ 	sw	$zero,0x1e8($a2)
/*  f014d78:	acc00208 */ 	sw	$zero,0x208($a2)
/*  f014d7c:	0c004b70 */ 	jal	random
/*  f014d80:	afa60068 */ 	sw	$a2,0x68($sp)
/*  f014d84:	8fa60068 */ 	lw	$a2,0x68($sp)
/*  f014d88:	00002825 */ 	or	$a1,$zero,$zero
/*  f014d8c:	acc20210 */ 	sw	$v0,0x210($a2)
/*  f014d90:	24020006 */ 	addiu	$v0,$zero,0x6
/*  f014d94:	acc0020c */ 	sw	$zero,0x20c($a2)
/*  f014d98:	00c02025 */ 	or	$a0,$a2,$zero
/*  f014d9c:	00c01825 */ 	or	$v1,$a2,$zero
.L0f014da0:
/*  f014da0:	24a50001 */ 	addiu	$a1,$a1,0x1
/*  f014da4:	e4740214 */ 	swc1	$f20,0x214($v1)
/*  f014da8:	e4740218 */ 	swc1	$f20,0x218($v1)
/*  f014dac:	e4740244 */ 	swc1	$f20,0x244($v1)
/*  f014db0:	e4740248 */ 	swc1	$f20,0x248($v1)
/*  f014db4:	ac600274 */ 	sw	$zero,0x274($v1)
/*  f014db8:	ac600278 */ 	sw	$zero,0x278($v1)
/*  f014dbc:	24840004 */ 	addiu	$a0,$a0,0x4
/*  f014dc0:	24630008 */ 	addiu	$v1,$v1,0x8
/*  f014dc4:	14a2fff6 */ 	bne	$a1,$v0,.L0f014da0
/*  f014dc8:	ac8002a4 */ 	sw	$zero,0x2a4($a0)
/*  f014dcc:	90cb009c */ 	lbu	$t3,0x9c($a2)
/*  f014dd0:	acc002a4 */ 	sw	$zero,0x2a4($a2)
/*  f014dd4:	acc002c0 */ 	sw	$zero,0x2c0($a2)
/*  f014dd8:	316effef */ 	andi	$t6,$t3,0xffef
/*  f014ddc:	e4d402c4 */ 	swc1	$f20,0x2c4($a2)
/*  f014de0:	acc002c8 */ 	sw	$zero,0x2c8($a2)
/*  f014de4:	a0ce009c */ 	sb	$t6,0x9c($a2)
/*  f014de8:	acc002cc */ 	sw	$zero,0x2cc($a2)
/*  f014dec:	0c004b70 */ 	jal	random
/*  f014df0:	afa60068 */ 	sw	$a2,0x68($sp)
/*  f014df4:	8fa60068 */ 	lw	$a2,0x68($sp)
/*  f014df8:	0c004b70 */ 	jal	random
/*  f014dfc:	acc202d0 */ 	sw	$v0,0x2d0($a2)
/*  f014e00:	44829000 */ 	mtc1	$v0,$f18
/*  f014e04:	8fa60068 */ 	lw	$a2,0x68($sp)
/*  f014e08:	04410005 */ 	bgez	$v0,.L0f014e20
/*  f014e0c:	46809120 */ 	cvt.s.w	$f4,$f18
/*  f014e10:	3c014f80 */ 	lui	$at,0x4f80
/*  f014e14:	44813000 */ 	mtc1	$at,$f6
/*  f014e18:	00000000 */ 	sll	$zero,$zero,0x0
/*  f014e1c:	46062100 */ 	add.s	$f4,$f4,$f6
.L0f014e20:
/*  f014e20:	3c012f80 */ 	lui	$at,0x2f80
/*  f014e24:	44814000 */ 	mtc1	$at,$f8
/*  f014e28:	90cd009c */ 	lbu	$t5,0x9c($a2)
/*  f014e2c:	a0c00078 */ 	sb	$zero,0x78($a2)
/*  f014e30:	46082282 */ 	mul.s	$f10,$f4,$f8
/*  f014e34:	31acfffe */ 	andi	$t4,$t5,0xfffe
/*  f014e38:	a0cc009c */ 	sb	$t4,0x9c($a2)
/*  f014e3c:	acc00050 */ 	sw	$zero,0x50($a2)
/*  f014e40:	a0c0009d */ 	sb	$zero,0x9d($a2)
/*  f014e44:	1000000a */ 	beqz	$zero,.L0f014e70
/*  f014e48:	e4ca02d4 */ 	swc1	$f10,0x2d4($a2)
.L0f014e4c:
/*  f014e4c:	91020000 */ 	lbu	$v0,0x0($t0)
/*  f014e50:	3c01800b */ 	lui	$at,0x800b
/*  f014e54:	2442ffff */ 	addiu	$v0,$v0,-1
/*  f014e58:	304f00ff */ 	andi	$t7,$v0,0xff
/*  f014e5c:	000fc080 */ 	sll	$t8,$t7,0x2
/*  f014e60:	00380821 */ 	addu	$at,$at,$t8
/*  f014e64:	a10f0000 */ 	sb	$t7,0x0($t0)
/*  f014e68:	10000004 */ 	beqz	$zero,.L0f014e7c
/*  f014e6c:	ac20cc80 */ 	sw	$zero,-0x3380($at)
.L0f014e70:
/*  f014e70:	02002025 */ 	or	$a0,$s0,$zero
/*  f014e74:	0fc053a4 */ 	jal	func0f014e90
/*  f014e78:	2405000a */ 	addiu	$a1,$zero,0xa
.L0f014e7c:
/*  f014e7c:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*  f014e80:	d7b40020 */ 	ldc1	$f20,0x20($sp)
/*  f014e84:	8fb00028 */ 	lw	$s0,0x28($sp)
/*  f014e88:	03e00008 */ 	jr	$ra
/*  f014e8c:	27bd0078 */ 	addiu	$sp,$sp,0x78
);

GLOBAL_ASM(
glabel func0f014e90
/*  f014e90:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f014e94:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f014e98:	00803825 */ 	or	$a3,$a0,$zero
/*  f014e9c:	10800016 */ 	beqz	$a0,.L0f014ef8
/*  f014ea0:	00a03025 */ 	or	$a2,$a1,$zero
/*  f014ea4:	8c8202d4 */ 	lw	$v0,0x2d4($a0)
/*  f014ea8:	50400014 */ 	beqzl	$v0,.L0f014efc
/*  f014eac:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f014eb0:	18a00011 */ 	blez	$a1,.L0f014ef8
/*  f014eb4:	28a10100 */ 	slti	$at,$a1,0x100
/*  f014eb8:	14200002 */ 	bnez	$at,.L0f014ec4
/*  f014ebc:	24050004 */ 	addiu	$a1,$zero,0x4
/*  f014ec0:	240600ff */ 	addiu	$a2,$zero,0xff
.L0f014ec4:
/*  f014ec4:	00062080 */ 	sll	$a0,$a2,0x2
/*  f014ec8:	00862021 */ 	addu	$a0,$a0,$a2
/*  f014ecc:	00042080 */ 	sll	$a0,$a0,0x2
/*  f014ed0:	2484000f */ 	addiu	$a0,$a0,0xf
/*  f014ed4:	a0460018 */ 	sb	$a2,0x18($v0)
/*  f014ed8:	348e000f */ 	ori	$t6,$a0,0xf
/*  f014edc:	39c4000f */ 	xori	$a0,$t6,0xf
/*  f014ee0:	0c0048f2 */ 	jal	malloc
/*  f014ee4:	afa70018 */ 	sw	$a3,0x18($sp)
/*  f014ee8:	8fa40018 */ 	lw	$a0,0x18($sp)
/*  f014eec:	8c9802d4 */ 	lw	$t8,0x2d4($a0)
/*  f014ef0:	0fc65f00 */ 	jal	func0f197c00
/*  f014ef4:	af020014 */ 	sw	$v0,0x14($t8)
.L0f014ef8:
/*  f014ef8:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f014efc:
/*  f014efc:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f014f00:	03e00008 */ 	jr	$ra
/*  f014f04:	00000000 */ 	sll	$zero,$zero,0x0
/*  f014f08:	00000000 */ 	sll	$zero,$zero,0x0
/*  f014f0c:	00000000 */ 	sll	$zero,$zero,0x0
);
