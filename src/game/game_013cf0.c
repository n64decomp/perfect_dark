#include <ultra64.h>
#include "constants.h"
#include "game/data/data_000000.h"
#include "game/data/data_0083d0.h"
#include "game/data/data_00e460.h"
#include "game/data/data_0160b0.h"
#include "game/data/data_01a3a0.h"
#include "game/data/data_020df0.h"
#include "game/game_013cf0.h"
#include "game/game_157db0.h"
#include "game/game_166e40.h"
#include "gvars/gvars.h"
#include "types.h"

GLOBAL_ASM(
glabel func0f013cf0
/*  f013cf0:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f013cf4:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f013cf8:	3c04800a */ 	lui	$a0,%hi(g_Vars+0x4b4)
/*  f013cfc:	0fc56c8f */ 	jal	func0f15b23c
/*  f013d00:	8c84a474 */ 	lw	$a0,%lo(g_Vars+0x4b4)($a0)
/*  f013d04:	04410002 */ 	bgez	$v0,.L0f013d10
/*  f013d08:	00401825 */ 	or	$v1,$v0,$zero
/*  f013d0c:	00001825 */ 	or	$v1,$zero,$zero
.L0f013d10:
/*  f013d10:	000378c0 */ 	sll	$t7,$v1,0x3
/*  f013d14:	01e37823 */ 	subu	$t7,$t7,$v1
/*  f013d18:	000f78c0 */ 	sll	$t7,$t7,0x3
/*  f013d1c:	3c048008 */ 	lui	$a0,%hi(g_Stages+0xa)
/*  f013d20:	240e0002 */ 	addiu	$t6,$zero,0x2
/*  f013d24:	3c018006 */ 	lui	$at,%hi(var8005d9a0)
/*  f013d28:	008f2021 */ 	addu	$a0,$a0,$t7
/*  f013d2c:	a02ed9a0 */ 	sb	$t6,%lo(var8005d9a0)($at)
/*  f013d30:	9484fcca */ 	lhu	$a0,%lo(g_Stages+0xa)($a0)
/*  f013d34:	0fc59c3f */ 	jal	func0f1670fc
/*  f013d38:	24050022 */ 	addiu	$a1,$zero,0x22
/*  f013d3c:	3c04800a */ 	lui	$a0,%hi(var8009a8a0)
/*  f013d40:	2484a8a0 */ 	addiu	$a0,$a0,%lo(var8009a8a0)
/*  f013d44:	ac820000 */ 	sw	$v0,0x0($a0)
/*  f013d48:	8c580000 */ 	lw	$t8,0x0($v0)
/*  f013d4c:	3c01800a */ 	lui	$at,%hi(var8009a8a4)
/*  f013d50:	24590004 */ 	addiu	$t9,$v0,0x4
/*  f013d54:	ac38a8a4 */ 	sw	$t8,%lo(var8009a8a4)($at)
/*  f013d58:	3c01800a */ 	lui	$at,%hi(var8009a8a8)
/*  f013d5c:	0fc04f5d */ 	jal	func0f013d74
/*  f013d60:	ac39a8a8 */ 	sw	$t9,%lo(var8009a8a8)($at)
/*  f013d64:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f013d68:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f013d6c:	03e00008 */ 	jr	$ra
/*  f013d70:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f013d74
/*  f013d74:	3c03800a */ 	lui	$v1,%hi(var8009a8a8)
/*  f013d78:	8c63a8a8 */ 	lw	$v1,%lo(var8009a8a8)($v1)
/*  f013d7c:	27bdfff8 */ 	addiu	$sp,$sp,-8
/*  f013d80:	3c0f800a */ 	lui	$t7,%hi(var8009a8a4)
/*  f013d84:	8defa8a4 */ 	lw	$t7,%lo(var8009a8a4)($t7)
/*  f013d88:	afb00004 */ 	sw	$s0,0x4($sp)
/*  f013d8c:	3c04800a */ 	lui	$a0,%hi(var8009a8a0)
/*  f013d90:	8c84a8a0 */ 	lw	$a0,%lo(var8009a8a0)($a0)
/*  f013d94:	8c6e0000 */ 	lw	$t6,0x0($v1)
/*  f013d98:	000fc080 */ 	sll	$t8,$t7,0x2
/*  f013d9c:	0078c821 */ 	addu	$t9,$v1,$t8
/*  f013da0:	01c41021 */ 	addu	$v0,$t6,$a0
/*  f013da4:	8f2e0000 */ 	lw	$t6,0x0($t9)
/*  f013da8:	24100003 */ 	addiu	$s0,$zero,0x3
/*  f013dac:	240d0002 */ 	addiu	$t5,$zero,0x2
/*  f013db0:	01c42821 */ 	addu	$a1,$t6,$a0
/*  f013db4:	0045082b */ 	sltu	$at,$v0,$a1
/*  f013db8:	10200044 */ 	beqz	$at,.L0f013ecc
/*  f013dbc:	240c000c */ 	addiu	$t4,$zero,0xc
/*  f013dc0:	240b0001 */ 	addiu	$t3,$zero,0x1
/*  f013dc4:	240a0006 */ 	addiu	$t2,$zero,0x6
/*  f013dc8:	90430000 */ 	lbu	$v1,0x0($v0)
.L0f013dcc:
/*  f013dcc:	1460002c */ 	bnez	$v1,.L0f013e80
/*  f013dd0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f013dd4:	90430006 */ 	lbu	$v1,0x6($v0)
/*  f013dd8:	90440009 */ 	lbu	$a0,0x9($v0)
/*  f013ddc:	90460007 */ 	lbu	$a2,0x7($v0)
/*  f013de0:	00037840 */ 	sll	$t7,$v1,0x1
/*  f013de4:	0003c080 */ 	sll	$t8,$v1,0x2
/*  f013de8:	01f8c821 */ 	addu	$t9,$t7,$t8
/*  f013dec:	272e000e */ 	addiu	$t6,$t9,0xe
/*  f013df0:	0004c080 */ 	sll	$t8,$a0,0x2
/*  f013df4:	00047840 */ 	sll	$t7,$a0,0x1
/*  f013df8:	01f8c821 */ 	addu	$t9,$t7,$t8
/*  f013dfc:	a04e0006 */ 	sb	$t6,0x6($v0)
/*  f013e00:	9047000a */ 	lbu	$a3,0xa($v0)
/*  f013e04:	272e000e */ 	addiu	$t6,$t9,0xe
/*  f013e08:	0006c080 */ 	sll	$t8,$a2,0x2
/*  f013e0c:	00067840 */ 	sll	$t7,$a2,0x1
/*  f013e10:	01f8c821 */ 	addu	$t9,$t7,$t8
/*  f013e14:	a04e0009 */ 	sb	$t6,0x9($v0)
/*  f013e18:	90480008 */ 	lbu	$t0,0x8($v0)
/*  f013e1c:	272e0010 */ 	addiu	$t6,$t9,0x10
/*  f013e20:	0007c080 */ 	sll	$t8,$a3,0x2
/*  f013e24:	00077840 */ 	sll	$t7,$a3,0x1
/*  f013e28:	01f8c821 */ 	addu	$t9,$t7,$t8
/*  f013e2c:	a04e0007 */ 	sb	$t6,0x7($v0)
/*  f013e30:	9049000b */ 	lbu	$t1,0xb($v0)
/*  f013e34:	272e0010 */ 	addiu	$t6,$t9,0x10
/*  f013e38:	0008c080 */ 	sll	$t8,$t0,0x2
/*  f013e3c:	00087840 */ 	sll	$t7,$t0,0x1
/*  f013e40:	01f8c821 */ 	addu	$t9,$t7,$t8
/*  f013e44:	a04e000a */ 	sb	$t6,0xa($v0)
/*  f013e48:	272e0012 */ 	addiu	$t6,$t9,0x12
/*  f013e4c:	0009c080 */ 	sll	$t8,$t1,0x2
/*  f013e50:	00097840 */ 	sll	$t7,$t1,0x1
/*  f013e54:	01f8c821 */ 	addu	$t9,$t7,$t8
/*  f013e58:	904f0001 */ 	lbu	$t7,0x1($v0)
/*  f013e5c:	a04e0008 */ 	sb	$t6,0x8($v0)
/*  f013e60:	272e0012 */ 	addiu	$t6,$t9,0x12
/*  f013e64:	25f8ffc0 */ 	addiu	$t8,$t7,-64
/*  f013e68:	030a0019 */ 	multu	$t8,$t2
/*  f013e6c:	a04e000b */ 	sb	$t6,0xb($v0)
/*  f013e70:	0000c812 */ 	mflo	$t9
/*  f013e74:	00591021 */ 	addu	$v0,$v0,$t9
/*  f013e78:	10000011 */ 	beqz	$zero,.L0f013ec0
/*  f013e7c:	2442018e */ 	addiu	$v0,$v0,0x18e
.L0f013e80:
/*  f013e80:	15630008 */ 	bne	$t3,$v1,.L0f013ea4
/*  f013e84:	00000000 */ 	sll	$zero,$zero,0x0
/*  f013e88:	904e0001 */ 	lbu	$t6,0x1($v0)
/*  f013e8c:	25cfffc0 */ 	addiu	$t7,$t6,-64
/*  f013e90:	01ec0019 */ 	multu	$t7,$t4
/*  f013e94:	0000c012 */ 	mflo	$t8
/*  f013e98:	00581021 */ 	addu	$v0,$v0,$t8
/*  f013e9c:	10000008 */ 	beqz	$zero,.L0f013ec0
/*  f013ea0:	24420310 */ 	addiu	$v0,$v0,0x310
.L0f013ea4:
/*  f013ea4:	15a30003 */ 	bne	$t5,$v1,.L0f013eb4
/*  f013ea8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f013eac:	10000004 */ 	beqz	$zero,.L0f013ec0
/*  f013eb0:	2442004c */ 	addiu	$v0,$v0,0x4c
.L0f013eb4:
/*  f013eb4:	56030003 */ 	bnel	$s0,$v1,.L0f013ec4
/*  f013eb8:	0045082b */ 	sltu	$at,$v0,$a1
/*  f013ebc:	24420018 */ 	addiu	$v0,$v0,0x18
.L0f013ec0:
/*  f013ec0:	0045082b */ 	sltu	$at,$v0,$a1
.L0f013ec4:
/*  f013ec4:	5420ffc1 */ 	bnezl	$at,.L0f013dcc
/*  f013ec8:	90430000 */ 	lbu	$v1,0x0($v0)
.L0f013ecc:
/*  f013ecc:	8fb00004 */ 	lw	$s0,0x4($sp)
/*  f013ed0:	03e00008 */ 	jr	$ra
/*  f013ed4:	27bd0008 */ 	addiu	$sp,$sp,0x8
/*  f013ed8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f013edc:	00000000 */ 	sll	$zero,$zero,0x0
);
