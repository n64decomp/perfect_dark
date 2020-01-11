#include <ultra64.h>
#include "constants.h"
#include "gvars/gvars.h"
#include "setup/setup_000000.h"
#include "setup/setup_0160b0.h"
#include "setup/setup_020df0.h"
#include "types.h"
#include "game/chr/chr.h"
#include "game/game_0601b0.h"
#include "game/game_066310.h"
#include "game/game_096750.h"
#include "game/game_097a50.h"
#include "game/game_0b0420.h"
#include "game/game_114240.h"
#include "game/game_115ab0.h"
#include "game/game_11ecf0.h"
#include "game/game_16cfa0.h"
#include "game/game_176d70.h"
#include "game/game_187770.h"
#include "game/game_1999b0.h"
#include "game/game_19c990.h"
#include "library/library_12dc0.h"

const u32 var7f1b90a0[] = {0x3d4ccccd};
const u32 var7f1b90a4[] = {0x7f19a2c0};
const u32 var7f1b90a8[] = {0x7f19a2c0};
const u32 var7f1b90ac[] = {0x7f19a2d0};
const u32 var7f1b90b0[] = {0x7f19a2d0};
const u32 var7f1b90b4[] = {0x7f19a2d0};
const u32 var7f1b90b8[] = {0x7f19a2d0};
const u32 var7f1b90bc[] = {0x7f19a2d0};
const u32 var7f1b90c0[] = {0x7f19a2d0};
const u32 var7f1b90c4[] = {0x7f19a2d0};
const u32 var7f1b90c8[] = {0x7f19a2d0};
const u32 var7f1b90cc[] = {0x7f19a2d0};
const u32 var7f1b90d0[] = {0x7f19a2d0};
const u32 var7f1b90d4[] = {0x7f19a2c0};
const u32 var7f1b90d8[] = {0x7f19a2d0};
const u32 var7f1b90dc[] = {0x7f19a2d0};
const u32 var7f1b90e0[] = {0x7f19a2d0};
const u32 var7f1b90e4[] = {0x7f19a2c8};
const u32 var7f1b90e8[] = {0x7f19a2c8};
const u32 var7f1b90ec[] = {0x7f19a2c8};
const u32 var7f1b90f0[] = {0x7f19a2c8};
const u32 var7f1b90f4[] = {0x7f19a2c8};
const u32 var7f1b90f8[] = {0x7f19a300};
const u32 var7f1b90fc[] = {0x7f19a310};
const u32 var7f1b9100[] = {0x7f19a310};
const u32 var7f1b9104[] = {0x7f19a310};
const u32 var7f1b9108[] = {0x7f19a308};
const u32 var7f1b910c[] = {0x7f19a308};
const u32 var7f1b9110[] = {0x7f19a310};
const u32 var7f1b9114[] = {0x7f19a310};
const u32 var7f1b9118[] = {0x7f19a310};
const u32 var7f1b911c[] = {0x7f19a348};
const u32 var7f1b9120[] = {0x7f19a370};
const u32 var7f1b9124[] = {0x7f19a350};
const u32 var7f1b9128[] = {0x7f19a370};
const u32 var7f1b912c[] = {0x7f19a370};
const u32 var7f1b9130[] = {0x7f19a358};
const u32 var7f1b9134[] = {0x7f19a360};
const u32 var7f1b9138[] = {0x7f19a368};
const u32 var7f1b913c[] = {0x7f19a370};
const u32 var7f1b9140[] = {0x7f19a370};
const u32 var7f1b9144[] = {0x7f19a370};
const u32 var7f1b9148[] = {0x7f19a340};
const u32 var7f1b914c[] = {0x41855555};
const u32 var7f1b9150[] = {0x3eb2b17a};
const u32 var7f1b9154[] = {0x3eb2b17a};
const u32 var7f1b9158[] = {0x3eb2b17a};
const u32 var7f1b915c[] = {0x41855555};
const u32 var7f1b9160[] = {0x4096c5bf};
const u32 var7f1b9164[] = {0x404907a9};
const u32 var7f1b9168[] = {0x3eb2b17a};
const u32 var7f1b916c[] = {0x00000000};
const u32 var7f1b9170[] = {0x00000000};
const u32 var7f1b9174[] = {0x00000000};
const u32 var7f1b9178[] = {0x00000000};
const u32 var7f1b917c[] = {0x00000000};

const char var7f1b9180[] = "%s %d\n";
const char var7f1b9188[] = "%02d\n";
const char var7f1b9190[] = "%03d\n";
const char var7f1b9198[] = "%s %d\n";
const char var7f1b91a0[] = "";
const char var7f1b91a4[] = "%s%s%.2f%%\n";
const char var7f1b91b0[] = "";
const char var7f1b91b4[] = "";
const char var7f1b91b8[] = "%s %d%%\n";
const char var7f1b91c4[] = "%02d:%02d\n";
const char var7f1b91d0[] = "%s";
const char var7f1b91d4[] = "%s";
const char var7f1b91d8[] = "%s %02d:%02d\n";
const char var7f1b91e8[] = "010\n";
const char var7f1b91f0[] = "%03d\n";
const char var7f1b91f8[] = "%s";
const char var7f1b91fc[] = "%s";
const char var7f1b9200[] = "%s";
const char var7f1b9204[] = "%s";
const char var7f1b9208[] = "%s";
const char var7f1b920c[] = "\n";

GLOBAL_ASM(
glabel func0f1999b0
/*  f1999b0:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f1999b4:	28810002 */ 	slti	$at,$a0,0x2
/*  f1999b8:	1420000a */ 	bnez	$at,.L0f1999e4
/*  f1999bc:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f1999c0:	2881005e */ 	slti	$at,$a0,0x5e
/*  f1999c4:	50200008 */ 	beqzl	$at,.L0f1999e8
/*  f1999c8:	00001025 */ 	or	$v0,$zero,$zero
/*  f1999cc:	0fc2c47b */ 	jal	func0f0b11ec
/*  f1999d0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1999d4:	50400004 */ 	beqzl	$v0,.L0f1999e8
/*  f1999d8:	00001025 */ 	or	$v0,$zero,$zero
/*  f1999dc:	10000002 */ 	beqz	$zero,.L0f1999e8
/*  f1999e0:	8c420000 */ 	lw	$v0,0x0($v0)
.L0f1999e4:
/*  f1999e4:	00001025 */ 	or	$v0,$zero,$zero
.L0f1999e8:
/*  f1999e8:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f1999ec:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f1999f0:	03e00008 */ 	jr	$ra
/*  f1999f4:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f1999f8
/*  f1999f8:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f1999fc:	28810002 */ 	slti	$at,$a0,0x2
/*  f199a00:	1420000a */ 	bnez	$at,.L0f199a2c
/*  f199a04:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f199a08:	2881005e */ 	slti	$at,$a0,0x5e
/*  f199a0c:	50200008 */ 	beqzl	$at,.L0f199a30
/*  f199a10:	00001025 */ 	or	$v0,$zero,$zero
/*  f199a14:	0fc2c47b */ 	jal	func0f0b11ec
/*  f199a18:	00000000 */ 	sll	$zero,$zero,0x0
/*  f199a1c:	50400004 */ 	beqzl	$v0,.L0f199a30
/*  f199a20:	00001025 */ 	or	$v0,$zero,$zero
/*  f199a24:	10000002 */ 	beqz	$zero,.L0f199a30
/*  f199a28:	84420008 */ 	lh	$v0,0x8($v0)
.L0f199a2c:
/*  f199a2c:	00001025 */ 	or	$v0,$zero,$zero
.L0f199a30:
/*  f199a30:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f199a34:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f199a38:	03e00008 */ 	jr	$ra
/*  f199a3c:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f199a40
/*  f199a40:	27bdff98 */ 	addiu	$sp,$sp,-104
/*  f199a44:	afbf004c */ 	sw	$ra,0x4c($sp)
/*  f199a48:	afb00048 */ 	sw	$s0,0x48($sp)
/*  f199a4c:	afa60070 */ 	sw	$a2,0x70($sp)
/*  f199a50:	8c9002d4 */ 	lw	$s0,0x2d4($a0)
/*  f199a54:	44802000 */ 	mtc1	$zero,$f4
/*  f199a58:	00057040 */ 	sll	$t6,$a1,0x1
/*  f199a5c:	00051080 */ 	sll	$v0,$a1,0x2
/*  f199a60:	020e7821 */ 	addu	$t7,$s0,$t6
/*  f199a64:	a5e0002c */ 	sh	$zero,0x2c($t7)
/*  f199a68:	02021821 */ 	addu	$v1,$s0,$v0
/*  f199a6c:	0082c021 */ 	addu	$t8,$a0,$v0
/*  f199a70:	e46400e4 */ 	swc1	$f4,0xe4($v1)
/*  f199a74:	8f190170 */ 	lw	$t9,0x170($t8)
/*  f199a78:	00803825 */ 	or	$a3,$a0,$zero
/*  f199a7c:	53200055 */ 	beqzl	$t9,.L0f199bd4
/*  f199a80:	8fbf004c */ 	lw	$ra,0x4c($sp)
/*  f199a84:	8e05004c */ 	lw	$a1,0x4c($s0)
/*  f199a88:	8e040020 */ 	lw	$a0,0x20($s0)
/*  f199a8c:	afa70068 */ 	sw	$a3,0x68($sp)
/*  f199a90:	00054880 */ 	sll	$t1,$a1,0x2
/*  f199a94:	00092fc2 */ 	srl	$a1,$t1,0x1f
/*  f199a98:	0fc668a7 */ 	jal	func0f19a29c
/*  f199a9c:	afa30054 */ 	sw	$v1,0x54($sp)
/*  f199aa0:	1440004b */ 	bnez	$v0,.L0f199bd0
/*  f199aa4:	8fa30054 */ 	lw	$v1,0x54($sp)
/*  f199aa8:	8e05004c */ 	lw	$a1,0x4c($s0)
/*  f199aac:	8e040020 */ 	lw	$a0,0x20($s0)
/*  f199ab0:	afa30054 */ 	sw	$v1,0x54($sp)
/*  f199ab4:	00055880 */ 	sll	$t3,$a1,0x2
/*  f199ab8:	0fc6667e */ 	jal	func0f1999f8
/*  f199abc:	000b2fc2 */ 	srl	$a1,$t3,0x1f
/*  f199ac0:	18400043 */ 	blez	$v0,.L0f199bd0
/*  f199ac4:	8fa30054 */ 	lw	$v1,0x54($sp)
/*  f199ac8:	8e06004c */ 	lw	$a2,0x4c($s0)
/*  f199acc:	8c6d0024 */ 	lw	$t5,0x24($v1)
/*  f199ad0:	8e050020 */ 	lw	$a1,0x20($s0)
/*  f199ad4:	00067080 */ 	sll	$t6,$a2,0x2
/*  f199ad8:	000e37c2 */ 	srl	$a2,$t6,0x1f
/*  f199adc:	afa30054 */ 	sw	$v1,0x54($sp)
/*  f199ae0:	02002025 */ 	or	$a0,$s0,$zero
/*  f199ae4:	0fc6675c */ 	jal	func0f199d70
/*  f199ae8:	004d3823 */ 	subu	$a3,$v0,$t5
/*  f199aec:	18400038 */ 	blez	$v0,.L0f199bd0
/*  f199af0:	8fa30054 */ 	lw	$v1,0x54($sp)
/*  f199af4:	8c780024 */ 	lw	$t8,0x24($v1)
/*  f199af8:	0302c821 */ 	addu	$t9,$t8,$v0
/*  f199afc:	ac790024 */ 	sw	$t9,0x24($v1)
/*  f199b00:	8fa90070 */ 	lw	$t1,0x70($sp)
/*  f199b04:	51200033 */ 	beqzl	$t1,.L0f199bd4
/*  f199b08:	8fbf004c */ 	lw	$ra,0x4c($sp)
/*  f199b0c:	8e0a0020 */ 	lw	$t2,0x20($s0)
/*  f199b10:	24010016 */ 	addiu	$at,$zero,0x16
/*  f199b14:	00002025 */ 	or	$a0,$zero,$zero
/*  f199b18:	15410019 */ 	bne	$t2,$at,.L0f199b80
/*  f199b1c:	8faf0068 */ 	lw	$t7,0x68($sp)
/*  f199b20:	8fab0068 */ 	lw	$t3,0x68($sp)
/*  f199b24:	3c01bf80 */ 	lui	$at,0xbf80
/*  f199b28:	44810000 */ 	mtc1	$at,$f0
/*  f199b2c:	8d65001c */ 	lw	$a1,0x1c($t3)
/*  f199b30:	240cffff */ 	addiu	$t4,$zero,-1
/*  f199b34:	240d0400 */ 	addiu	$t5,$zero,0x400
/*  f199b38:	240effff */ 	addiu	$t6,$zero,-1
/*  f199b3c:	afae002c */ 	sw	$t6,0x2c($sp)
/*  f199b40:	afad0014 */ 	sw	$t5,0x14($sp)
/*  f199b44:	afac0010 */ 	sw	$t4,0x10($sp)
/*  f199b48:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f199b4c:	afa00020 */ 	sw	$zero,0x20($sp)
/*  f199b50:	afa0001c */ 	sw	$zero,0x1c($sp)
/*  f199b54:	afa00018 */ 	sw	$zero,0x18($sp)
/*  f199b58:	00002025 */ 	or	$a0,$zero,$zero
/*  f199b5c:	24060433 */ 	addiu	$a2,$zero,0x433
/*  f199b60:	2407ffff */ 	addiu	$a3,$zero,-1
/*  f199b64:	e7a00038 */ 	swc1	$f0,0x38($sp)
/*  f199b68:	e7a00034 */ 	swc1	$f0,0x34($sp)
/*  f199b6c:	e7a00030 */ 	swc1	$f0,0x30($sp)
/*  f199b70:	0fc24e7e */ 	jal	func0f0939f8
/*  f199b74:	e7a00024 */ 	swc1	$f0,0x24($sp)
/*  f199b78:	10000016 */ 	beqz	$zero,.L0f199bd4
/*  f199b7c:	8fbf004c */ 	lw	$ra,0x4c($sp)
.L0f199b80:
/*  f199b80:	8de5001c */ 	lw	$a1,0x1c($t7)
/*  f199b84:	3c01bf80 */ 	lui	$at,0xbf80
/*  f199b88:	44810000 */ 	mtc1	$at,$f0
/*  f199b8c:	2418ffff */ 	addiu	$t8,$zero,-1
/*  f199b90:	24190400 */ 	addiu	$t9,$zero,0x400
/*  f199b94:	2409ffff */ 	addiu	$t1,$zero,-1
/*  f199b98:	afa9002c */ 	sw	$t1,0x2c($sp)
/*  f199b9c:	afb90014 */ 	sw	$t9,0x14($sp)
/*  f199ba0:	afb80010 */ 	sw	$t8,0x10($sp)
/*  f199ba4:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f199ba8:	afa00020 */ 	sw	$zero,0x20($sp)
/*  f199bac:	afa0001c */ 	sw	$zero,0x1c($sp)
/*  f199bb0:	afa00018 */ 	sw	$zero,0x18($sp)
/*  f199bb4:	2406804f */ 	addiu	$a2,$zero,-32689
/*  f199bb8:	2407ffff */ 	addiu	$a3,$zero,-1
/*  f199bbc:	e7a00024 */ 	swc1	$f0,0x24($sp)
/*  f199bc0:	e7a00030 */ 	swc1	$f0,0x30($sp)
/*  f199bc4:	e7a00034 */ 	swc1	$f0,0x34($sp)
/*  f199bc8:	0fc24e7e */ 	jal	func0f0939f8
/*  f199bcc:	e7a00038 */ 	swc1	$f0,0x38($sp)
.L0f199bd0:
/*  f199bd0:	8fbf004c */ 	lw	$ra,0x4c($sp)
.L0f199bd4:
/*  f199bd4:	8fb00048 */ 	lw	$s0,0x48($sp)
/*  f199bd8:	27bd0068 */ 	addiu	$sp,$sp,0x68
/*  f199bdc:	03e00008 */ 	jr	$ra
/*  f199be0:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f199be4
/*  f199be4:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*  f199be8:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f199bec:	00808025 */ 	or	$s0,$a0,$zero
/*  f199bf0:	afbf001c */ 	sw	$ra,0x1c($sp)
/*  f199bf4:	afa5002c */ 	sw	$a1,0x2c($sp)
/*  f199bf8:	afa60030 */ 	sw	$a2,0x30($sp)
/*  f199bfc:	afa70034 */ 	sw	$a3,0x34($sp)
/*  f199c00:	10800028 */ 	beqz	$a0,.L0f199ca4
/*  f199c04:	00001825 */ 	or	$v1,$zero,$zero
/*  f199c08:	948e0064 */ 	lhu	$t6,0x64($a0)
/*  f199c0c:	8fa4002c */ 	lw	$a0,0x2c($sp)
/*  f199c10:	31cf0001 */ 	andi	$t7,$t6,0x1
/*  f199c14:	11e00008 */ 	beqz	$t7,.L0f199c38
/*  f199c18:	00000000 */ 	sll	$zero,$zero,0x0
/*  f199c1c:	00a02025 */ 	or	$a0,$a1,$zero
/*  f199c20:	0fc6666c */ 	jal	func0f1999b0
/*  f199c24:	00c02825 */ 	or	$a1,$a2,$zero
/*  f199c28:	0fc2a63d */ 	jal	func0f0a98f4
/*  f199c2c:	00402025 */ 	or	$a0,$v0,$zero
/*  f199c30:	10000007 */ 	beqz	$zero,.L0f199c50
/*  f199c34:	00401825 */ 	or	$v1,$v0,$zero
.L0f199c38:
/*  f199c38:	0fc6666c */ 	jal	func0f1999b0
/*  f199c3c:	8fa50030 */ 	lw	$a1,0x30($sp)
/*  f199c40:	8e18001c */ 	lw	$t8,0x1c($s0)
/*  f199c44:	0002c880 */ 	sll	$t9,$v0,0x2
/*  f199c48:	03194021 */ 	addu	$t0,$t8,$t9
/*  f199c4c:	8d030000 */ 	lw	$v1,0x0($t0)
.L0f199c50:
/*  f199c50:	8fa90034 */ 	lw	$t1,0x34($sp)
/*  f199c54:	8fa4002c */ 	lw	$a0,0x2c($sp)
/*  f199c58:	8fa50030 */ 	lw	$a1,0x30($sp)
/*  f199c5c:	51200012 */ 	beqzl	$t1,.L0f199ca8
/*  f199c60:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f199c64:	0fc6666c */ 	jal	func0f1999b0
/*  f199c68:	afa30024 */ 	sw	$v1,0x24($sp)
/*  f199c6c:	afa20020 */ 	sw	$v0,0x20($sp)
/*  f199c70:	8e05004c */ 	lw	$a1,0x4c($s0)
/*  f199c74:	8e040020 */ 	lw	$a0,0x20($s0)
/*  f199c78:	00055080 */ 	sll	$t2,$a1,0x2
/*  f199c7c:	0fc6666c */ 	jal	func0f1999b0
/*  f199c80:	000a2fc2 */ 	srl	$a1,$t2,0x1f
/*  f199c84:	8fac0020 */ 	lw	$t4,0x20($sp)
/*  f199c88:	8fa30024 */ 	lw	$v1,0x24($sp)
/*  f199c8c:	544c0006 */ 	bnel	$v0,$t4,.L0f199ca8
/*  f199c90:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f199c94:	8e0d0028 */ 	lw	$t5,0x28($s0)
/*  f199c98:	8e0f0024 */ 	lw	$t7,0x24($s0)
/*  f199c9c:	006d7021 */ 	addu	$t6,$v1,$t5
/*  f199ca0:	01cf1821 */ 	addu	$v1,$t6,$t7
.L0f199ca4:
/*  f199ca4:	8fbf001c */ 	lw	$ra,0x1c($sp)
.L0f199ca8:
/*  f199ca8:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f199cac:	27bd0028 */ 	addiu	$sp,$sp,0x28
/*  f199cb0:	03e00008 */ 	jr	$ra
/*  f199cb4:	00601025 */ 	or	$v0,$v1,$zero
);

GLOBAL_ASM(
glabel func0f199cb8
/*  f199cb8:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*  f199cbc:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f199cc0:	afa50024 */ 	sw	$a1,0x24($sp)
/*  f199cc4:	afa60028 */ 	sw	$a2,0x28($sp)
/*  f199cc8:	00803825 */ 	or	$a3,$a0,$zero
/*  f199ccc:	10800023 */ 	beqz	$a0,.L0f199d5c
/*  f199cd0:	00001825 */ 	or	$v1,$zero,$zero
/*  f199cd4:	948e0064 */ 	lhu	$t6,0x64($a0)
/*  f199cd8:	00a02025 */ 	or	$a0,$a1,$zero
/*  f199cdc:	8fb90024 */ 	lw	$t9,0x24($sp)
/*  f199ce0:	31cf0001 */ 	andi	$t7,$t6,0x1
/*  f199ce4:	51e00007 */ 	beqzl	$t7,.L0f199d04
/*  f199ce8:	8cf8001c */ 	lw	$t8,0x1c($a3)
/*  f199cec:	0fc2a63d */ 	jal	func0f0a98f4
/*  f199cf0:	afa70020 */ 	sw	$a3,0x20($sp)
/*  f199cf4:	8fa70020 */ 	lw	$a3,0x20($sp)
/*  f199cf8:	10000005 */ 	beqz	$zero,.L0f199d10
/*  f199cfc:	00401825 */ 	or	$v1,$v0,$zero
/*  f199d00:	8cf8001c */ 	lw	$t8,0x1c($a3)
.L0f199d04:
/*  f199d04:	00194080 */ 	sll	$t0,$t9,0x2
/*  f199d08:	03084821 */ 	addu	$t1,$t8,$t0
/*  f199d0c:	8d230000 */ 	lw	$v1,0x0($t1)
.L0f199d10:
/*  f199d10:	8faa0028 */ 	lw	$t2,0x28($sp)
/*  f199d14:	51400012 */ 	beqzl	$t2,.L0f199d60
/*  f199d18:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f199d1c:	8ce5004c */ 	lw	$a1,0x4c($a3)
/*  f199d20:	8ce40020 */ 	lw	$a0,0x20($a3)
/*  f199d24:	afa70020 */ 	sw	$a3,0x20($sp)
/*  f199d28:	00055880 */ 	sll	$t3,$a1,0x2
/*  f199d2c:	000b2fc2 */ 	srl	$a1,$t3,0x1f
/*  f199d30:	0fc6666c */ 	jal	func0f1999b0
/*  f199d34:	afa3001c */ 	sw	$v1,0x1c($sp)
/*  f199d38:	8fad0024 */ 	lw	$t5,0x24($sp)
/*  f199d3c:	8fa3001c */ 	lw	$v1,0x1c($sp)
/*  f199d40:	8fa70020 */ 	lw	$a3,0x20($sp)
/*  f199d44:	544d0006 */ 	bnel	$v0,$t5,.L0f199d60
/*  f199d48:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f199d4c:	8cee0028 */ 	lw	$t6,0x28($a3)
/*  f199d50:	8cf90024 */ 	lw	$t9,0x24($a3)
/*  f199d54:	006e7821 */ 	addu	$t7,$v1,$t6
/*  f199d58:	01f91821 */ 	addu	$v1,$t7,$t9
.L0f199d5c:
/*  f199d5c:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f199d60:
/*  f199d60:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*  f199d64:	00601025 */ 	or	$v0,$v1,$zero
/*  f199d68:	03e00008 */ 	jr	$ra
/*  f199d6c:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f199d70
/*  f199d70:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*  f199d74:	afa40020 */ 	sw	$a0,0x20($sp)
/*  f199d78:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f199d7c:	afa50024 */ 	sw	$a1,0x24($sp)
/*  f199d80:	00a02025 */ 	or	$a0,$a1,$zero
/*  f199d84:	00c02825 */ 	or	$a1,$a2,$zero
/*  f199d88:	0fc6666c */ 	jal	func0f1999b0
/*  f199d8c:	afa7002c */ 	sw	$a3,0x2c($sp)
/*  f199d90:	8fa40020 */ 	lw	$a0,0x20($sp)
/*  f199d94:	00027080 */ 	sll	$t6,$v0,0x2
/*  f199d98:	8fa7002c */ 	lw	$a3,0x2c($sp)
/*  f199d9c:	8c8f001c */ 	lw	$t7,0x1c($a0)
/*  f199da0:	10800006 */ 	beqz	$a0,.L0f199dbc
/*  f199da4:	01cf1821 */ 	addu	$v1,$t6,$t7
/*  f199da8:	8c780000 */ 	lw	$t8,0x0($v1)
/*  f199dac:	1b000003 */ 	blez	$t8,.L0f199dbc
/*  f199db0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f199db4:	5ce00004 */ 	bgtzl	$a3,.L0f199dc8
/*  f199db8:	94990064 */ 	lhu	$t9,0x64($a0)
.L0f199dbc:
/*  f199dbc:	1000001b */ 	beqz	$zero,.L0f199e2c
/*  f199dc0:	00001025 */ 	or	$v0,$zero,$zero
/*  f199dc4:	94990064 */ 	lhu	$t9,0x64($a0)
.L0f199dc8:
/*  f199dc8:	33280001 */ 	andi	$t0,$t9,0x1
/*  f199dcc:	51000004 */ 	beqzl	$t0,.L0f199de0
/*  f199dd0:	afa30018 */ 	sw	$v1,0x18($sp)
/*  f199dd4:	10000015 */ 	beqz	$zero,.L0f199e2c
/*  f199dd8:	00e01025 */ 	or	$v0,$a3,$zero
/*  f199ddc:	afa30018 */ 	sw	$v1,0x18($sp)
.L0f199de0:
/*  f199de0:	0fc47bba */ 	jal	dprint
/*  f199de4:	afa7002c */ 	sw	$a3,0x2c($sp)
/*  f199de8:	8fa30018 */ 	lw	$v1,0x18($sp)
/*  f199dec:	8fa7002c */ 	lw	$a3,0x2c($sp)
/*  f199df0:	8c690000 */ 	lw	$t1,0x0($v1)
/*  f199df4:	01275023 */ 	subu	$t2,$t1,$a3
/*  f199df8:	05410009 */ 	bgez	$t2,.L0f199e20
/*  f199dfc:	ac6a0000 */ 	sw	$t2,0x0($v1)
/*  f199e00:	01475821 */ 	addu	$t3,$t2,$a3
/*  f199e04:	afab001c */ 	sw	$t3,0x1c($sp)
/*  f199e08:	0fc47bba */ 	jal	dprint
/*  f199e0c:	ac600000 */ 	sw	$zero,0x0($v1)
/*  f199e10:	50400006 */ 	beqzl	$v0,.L0f199e2c
/*  f199e14:	8fa2001c */ 	lw	$v0,0x1c($sp)
/*  f199e18:	10000004 */ 	beqz	$zero,.L0f199e2c
/*  f199e1c:	8fa2001c */ 	lw	$v0,0x1c($sp)
.L0f199e20:
/*  f199e20:	0fc47bba */ 	jal	dprint
/*  f199e24:	afa7001c */ 	sw	$a3,0x1c($sp)
/*  f199e28:	8fa2001c */ 	lw	$v0,0x1c($sp)
.L0f199e2c:
/*  f199e2c:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f199e30:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*  f199e34:	03e00008 */ 	jr	$ra
/*  f199e38:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f199e3c
/*  f199e3c:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*  f199e40:	afa40020 */ 	sw	$a0,0x20($sp)
/*  f199e44:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f199e48:	afa50024 */ 	sw	$a1,0x24($sp)
/*  f199e4c:	00a02025 */ 	or	$a0,$a1,$zero
/*  f199e50:	afa60028 */ 	sw	$a2,0x28($sp)
/*  f199e54:	afa7002c */ 	sw	$a3,0x2c($sp)
/*  f199e58:	0fc6666c */ 	jal	func0f1999b0
/*  f199e5c:	00c02825 */ 	or	$a1,$a2,$zero
/*  f199e60:	8fa40020 */ 	lw	$a0,0x20($sp)
/*  f199e64:	00027080 */ 	sll	$t6,$v0,0x2
/*  f199e68:	8c8f001c */ 	lw	$t7,0x1c($a0)
/*  f199e6c:	1080001d */ 	beqz	$a0,.L0f199ee4
/*  f199e70:	01cf1821 */ 	addu	$v1,$t6,$t7
/*  f199e74:	94980064 */ 	lhu	$t8,0x64($a0)
/*  f199e78:	8fa8002c */ 	lw	$t0,0x2c($sp)
/*  f199e7c:	33190001 */ 	andi	$t9,$t8,0x1
/*  f199e80:	57200019 */ 	bnezl	$t9,.L0f199ee8
/*  f199e84:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f199e88:	59000017 */ 	blezl	$t0,.L0f199ee8
/*  f199e8c:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f199e90:	0fc47bba */ 	jal	dprint
/*  f199e94:	afa30018 */ 	sw	$v1,0x18($sp)
/*  f199e98:	8fa30018 */ 	lw	$v1,0x18($sp)
/*  f199e9c:	8faa002c */ 	lw	$t2,0x2c($sp)
/*  f199ea0:	8c690000 */ 	lw	$t1,0x0($v1)
/*  f199ea4:	012a5821 */ 	addu	$t3,$t1,$t2
/*  f199ea8:	ac6b0000 */ 	sw	$t3,0x0($v1)
/*  f199eac:	8fa50028 */ 	lw	$a1,0x28($sp)
/*  f199eb0:	8fa40024 */ 	lw	$a0,0x24($sp)
/*  f199eb4:	0fc6666c */ 	jal	func0f1999b0
/*  f199eb8:	afa30018 */ 	sw	$v1,0x18($sp)
/*  f199ebc:	0fc2a63d */ 	jal	func0f0a98f4
/*  f199ec0:	00402025 */ 	or	$a0,$v0,$zero
/*  f199ec4:	8fa30018 */ 	lw	$v1,0x18($sp)
/*  f199ec8:	8c6c0000 */ 	lw	$t4,0x0($v1)
/*  f199ecc:	004c082a */ 	slt	$at,$v0,$t4
/*  f199ed0:	10200002 */ 	beqz	$at,.L0f199edc
/*  f199ed4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f199ed8:	ac620000 */ 	sw	$v0,0x0($v1)
.L0f199edc:
/*  f199edc:	0fc47bba */ 	jal	dprint
/*  f199ee0:	00000000 */ 	sll	$zero,$zero,0x0
.L0f199ee4:
/*  f199ee4:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f199ee8:
/*  f199ee8:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*  f199eec:	03e00008 */ 	jr	$ra
/*  f199ef0:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f199ef4
/*  f199ef4:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*  f199ef8:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f199efc:	8c8e001c */ 	lw	$t6,0x1c($a0)
/*  f199f00:	00057880 */ 	sll	$t7,$a1,0x2
/*  f199f04:	1080001b */ 	beqz	$a0,.L0f199f74
/*  f199f08:	01cf1821 */ 	addu	$v1,$t6,$t7
/*  f199f0c:	94980064 */ 	lhu	$t8,0x64($a0)
/*  f199f10:	33190001 */ 	andi	$t9,$t8,0x1
/*  f199f14:	57200018 */ 	bnezl	$t9,.L0f199f78
/*  f199f18:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f199f1c:	58c00016 */ 	blezl	$a2,.L0f199f78
/*  f199f20:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f199f24:	afa30018 */ 	sw	$v1,0x18($sp)
/*  f199f28:	afa50024 */ 	sw	$a1,0x24($sp)
/*  f199f2c:	0fc47bba */ 	jal	dprint
/*  f199f30:	afa60028 */ 	sw	$a2,0x28($sp)
/*  f199f34:	8fa30018 */ 	lw	$v1,0x18($sp)
/*  f199f38:	8fa60028 */ 	lw	$a2,0x28($sp)
/*  f199f3c:	8fa40024 */ 	lw	$a0,0x24($sp)
/*  f199f40:	8c680000 */ 	lw	$t0,0x0($v1)
/*  f199f44:	01064821 */ 	addu	$t1,$t0,$a2
/*  f199f48:	ac690000 */ 	sw	$t1,0x0($v1)
/*  f199f4c:	0fc2a63d */ 	jal	func0f0a98f4
/*  f199f50:	afa30018 */ 	sw	$v1,0x18($sp)
/*  f199f54:	8fa30018 */ 	lw	$v1,0x18($sp)
/*  f199f58:	8c6a0000 */ 	lw	$t2,0x0($v1)
/*  f199f5c:	004a082a */ 	slt	$at,$v0,$t2
/*  f199f60:	10200002 */ 	beqz	$at,.L0f199f6c
/*  f199f64:	00000000 */ 	sll	$zero,$zero,0x0
/*  f199f68:	ac620000 */ 	sw	$v0,0x0($v1)
.L0f199f6c:
/*  f199f6c:	0fc47bba */ 	jal	dprint
/*  f199f70:	00000000 */ 	sll	$zero,$zero,0x0
.L0f199f74:
/*  f199f74:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f199f78:
/*  f199f78:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*  f199f7c:	03e00008 */ 	jr	$ra
/*  f199f80:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f199f84
/*  f199f84:	27bdff38 */ 	addiu	$sp,$sp,-200
/*  f199f88:	afb7006c */ 	sw	$s7,0x6c($sp)
/*  f199f8c:	afb3005c */ 	sw	$s3,0x5c($sp)
/*  f199f90:	00c09825 */ 	or	$s3,$a2,$zero
/*  f199f94:	0080b825 */ 	or	$s7,$a0,$zero
/*  f199f98:	afbf0074 */ 	sw	$ra,0x74($sp)
/*  f199f9c:	afbe0070 */ 	sw	$s8,0x70($sp)
/*  f199fa0:	afb60068 */ 	sw	$s6,0x68($sp)
/*  f199fa4:	afb50064 */ 	sw	$s5,0x64($sp)
/*  f199fa8:	afb40060 */ 	sw	$s4,0x60($sp)
/*  f199fac:	afb20058 */ 	sw	$s2,0x58($sp)
/*  f199fb0:	afb10054 */ 	sw	$s1,0x54($sp)
/*  f199fb4:	afb00050 */ 	sw	$s0,0x50($sp)
/*  f199fb8:	f7b80048 */ 	sdc1	$f24,0x48($sp)
/*  f199fbc:	f7b60040 */ 	sdc1	$f22,0x40($sp)
/*  f199fc0:	f7b40038 */ 	sdc1	$f20,0x38($sp)
/*  f199fc4:	afa500cc */ 	sw	$a1,0xcc($sp)
/*  f199fc8:	10800004 */ 	beqz	$a0,.L0f199fdc
/*  f199fcc:	afa700d4 */ 	sw	$a3,0xd4($sp)
/*  f199fd0:	8c8302d4 */ 	lw	$v1,0x2d4($a0)
/*  f199fd4:	54600004 */ 	bnezl	$v1,.L0f199fe8
/*  f199fd8:	8c6e0020 */ 	lw	$t6,0x20($v1)
.L0f199fdc:
/*  f199fdc:	10000098 */ 	beqz	$zero,.L0f19a240
/*  f199fe0:	00001025 */ 	or	$v0,$zero,$zero
/*  f199fe4:	8c6e0020 */ 	lw	$t6,0x20($v1)
.L0f199fe8:
/*  f199fe8:	24010016 */ 	addiu	$at,$zero,0x16
/*  f199fec:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f199ff0:	15c10093 */ 	bne	$t6,$at,.L0f19a240
/*  f199ff4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f199ff8:	0c004b70 */ 	jal	random
/*  f199ffc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f19a000:	24010064 */ 	addiu	$at,$zero,0x64
/*  f19a004:	0041001b */ 	divu	$zero,$v0,$at
/*  f19a008:	00001810 */ 	mfhi	$v1
/*  f19a00c:	2861001e */ 	slti	$at,$v1,0x1e
/*  f19a010:	10200089 */ 	beqz	$at,.L0f19a238
/*  f19a014:	afa300b4 */ 	sw	$v1,0xb4($sp)
/*  f19a018:	240fffff */ 	addiu	$t7,$zero,-1
/*  f19a01c:	241800c8 */ 	addiu	$t8,$zero,0xc8
/*  f19a020:	3c198009 */ 	lui	$t9,%hi(var80088490)
/*  f19a024:	afa000ac */ 	sw	$zero,0xac($sp)
/*  f19a028:	afa000a8 */ 	sw	$zero,0xa8($sp)
/*  f19a02c:	afaf00a4 */ 	sw	$t7,0xa4($sp)
/*  f19a030:	afb800a0 */ 	sw	$t8,0xa0($sp)
/*  f19a034:	27398490 */ 	addiu	$t9,$t9,%lo(var80088490)
/*  f19a038:	8f210000 */ 	lw	$at,0x0($t9)
/*  f19a03c:	27be009c */ 	addiu	$s8,$sp,0x9c
/*  f19a040:	03c02025 */ 	or	$a0,$s8,$zero
/*  f19a044:	0fc2c74a */ 	jal	func0f0b1d28
/*  f19a048:	afc10000 */ 	sw	$at,0x0($s8)
/*  f19a04c:	3c0b800b */ 	lui	$t3,0x800b
/*  f19a050:	8d6bc530 */ 	lw	$t3,-0x3ad0($t3)
/*  f19a054:	46000606 */ 	mov.s	$f24,$f0
/*  f19a058:	2414001e */ 	addiu	$s4,$zero,0x1e
/*  f19a05c:	19600074 */ 	blez	$t3,.L0f19a230
/*  f19a060:	0000a825 */ 	or	$s5,$zero,$zero
/*  f19a064:	3c16800b */ 	lui	$s6,%hi(g_MpPlayerChrs)
/*  f19a068:	3c017f1c */ 	lui	$at,%hi(var7f1b90a0)
/*  f19a06c:	4480a000 */ 	mtc1	$zero,$f20
/*  f19a070:	c43690a0 */ 	lwc1	$f22,%lo(var7f1b90a0)($at)
/*  f19a074:	26d6c4d0 */ 	addiu	$s6,$s6,%lo(g_MpPlayerChrs)
/*  f19a078:	8ed00000 */ 	lw	$s0,0x0($s6)
.L0f19a07c:
/*  f19a07c:	24010006 */ 	addiu	$at,$zero,0x6
/*  f19a080:	8e12001c */ 	lw	$s2,0x1c($s0)
/*  f19a084:	924c0000 */ 	lbu	$t4,0x0($s2)
/*  f19a088:	5581001b */ 	bnel	$t4,$at,.L0f19a0f8
/*  f19a08c:	82180007 */ 	lb	$t8,0x7($s0)
/*  f19a090:	0fc4a25f */ 	jal	propGetPlayerNum
/*  f19a094:	02402025 */ 	or	$a0,$s2,$zero
/*  f19a098:	00026880 */ 	sll	$t5,$v0,0x2
/*  f19a09c:	3c03800a */ 	lui	$v1,0x800a
/*  f19a0a0:	006d1821 */ 	addu	$v1,$v1,$t5
/*  f19a0a4:	8c63a024 */ 	lw	$v1,-0x5fdc($v1)
/*  f19a0a8:	240e001e */ 	addiu	$t6,$zero,0x1e
/*  f19a0ac:	c4600170 */ 	lwc1	$f0,0x170($v1)
/*  f19a0b0:	c4620168 */ 	lwc1	$f2,0x168($v1)
/*  f19a0b4:	46000102 */ 	mul.s	$f4,$f0,$f0
/*  f19a0b8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f19a0bc:	46021182 */ 	mul.s	$f6,$f2,$f2
/*  f19a0c0:	46062300 */ 	add.s	$f12,$f4,$f6
/*  f19a0c4:	460ca03c */ 	c.lt.s	$f20,$f12
/*  f19a0c8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f19a0cc:	45000015 */ 	bc1f	.L0f19a124
/*  f19a0d0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f19a0d4:	448e4000 */ 	mtc1	$t6,$f8
/*  f19a0d8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f19a0dc:	468042a0 */ 	cvt.s.w	$f10,$f8
/*  f19a0e0:	46165402 */ 	mul.s	$f16,$f10,$f22
/*  f19a0e4:	4600848d */ 	trunc.w.s	$f18,$f16
/*  f19a0e8:	44149000 */ 	mfc1	$s4,$f18
/*  f19a0ec:	1000000d */ 	beqz	$zero,.L0f19a124
/*  f19a0f0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f19a0f4:	82180007 */ 	lb	$t8,0x7($s0)
.L0f19a0f8:
/*  f19a0f8:	24010001 */ 	addiu	$at,$zero,0x1
/*  f19a0fc:	2409001e */ 	addiu	$t1,$zero,0x1e
/*  f19a100:	13010008 */ 	beq	$t8,$at,.L0f19a124
/*  f19a104:	00000000 */ 	sll	$zero,$zero,0x0
/*  f19a108:	44892000 */ 	mtc1	$t1,$f4
/*  f19a10c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f19a110:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f19a114:	46163202 */ 	mul.s	$f8,$f6,$f22
/*  f19a118:	4600428d */ 	trunc.w.s	$f10,$f8
/*  f19a11c:	44145000 */ 	mfc1	$s4,$f10
/*  f19a120:	00000000 */ 	sll	$zero,$zero,0x0
.L0f19a124:
/*  f19a124:	1217003b */ 	beq	$s0,$s7,.L0f19a214
/*  f19a128:	8fb900b4 */ 	lw	$t9,0xb4($sp)
/*  f19a12c:	0334082a */ 	slt	$at,$t9,$s4
/*  f19a130:	10200038 */ 	beqz	$at,.L0f19a214
/*  f19a134:	00000000 */ 	sll	$zero,$zero,0x0
/*  f19a138:	0fc09e29 */ 	jal	func0f0278a4
/*  f19a13c:	02002025 */ 	or	$a0,$s0,$zero
/*  f19a140:	26510008 */ 	addiu	$s1,$s2,0x8
/*  f19a144:	44070000 */ 	mfc1	$a3,$f0
/*  f19a148:	02203025 */ 	or	$a2,$s1,$zero
/*  f19a14c:	8fa400d4 */ 	lw	$a0,0xd4($sp)
/*  f19a150:	0fc1ace7 */ 	jal	func0f06b39c
/*  f19a154:	02602825 */ 	or	$a1,$s3,$zero
/*  f19a158:	1040002e */ 	beqz	$v0,.L0f19a214
/*  f19a15c:	03c02025 */ 	or	$a0,$s8,$zero
/*  f19a160:	02402825 */ 	or	$a1,$s2,$zero
/*  f19a164:	0fc29f66 */ 	jal	func0f0a7d98
/*  f19a168:	2406ffff */ 	addiu	$a2,$zero,-1
/*  f19a16c:	8e0a0020 */ 	lw	$t2,0x20($s0)
/*  f19a170:	51400011 */ 	beqzl	$t2,.L0f19a1b8
/*  f19a174:	02002025 */ 	or	$a0,$s0,$zero
/*  f19a178:	0fc0cfe8 */ 	jal	chrGetShield
/*  f19a17c:	02002025 */ 	or	$a0,$s0,$zero
/*  f19a180:	4600a03c */ 	c.lt.s	$f20,$f0
/*  f19a184:	02002025 */ 	or	$a0,$s0,$zero
/*  f19a188:	02202825 */ 	or	$a1,$s1,$zero
/*  f19a18c:	02603025 */ 	or	$a2,$s3,$zero
/*  f19a190:	45000008 */ 	bc1f	.L0f19a1b4
/*  f19a194:	27a700ac */ 	addiu	$a3,$sp,0xac
/*  f19a198:	27ab00a0 */ 	addiu	$t3,$sp,0xa0
/*  f19a19c:	27ac00a8 */ 	addiu	$t4,$sp,0xa8
/*  f19a1a0:	27ad00a4 */ 	addiu	$t5,$sp,0xa4
/*  f19a1a4:	afad0018 */ 	sw	$t5,0x18($sp)
/*  f19a1a8:	afac0014 */ 	sw	$t4,0x14($sp)
/*  f19a1ac:	0fc0ffcb */ 	jal	func0f03ff2c
/*  f19a1b0:	afab0010 */ 	sw	$t3,0x10($sp)
.L0f19a1b4:
/*  f19a1b4:	02002025 */ 	or	$a0,$s0,$zero
.L0f19a1b8:
/*  f19a1b8:	02402825 */ 	or	$a1,$s2,$zero
/*  f19a1bc:	8fa600a0 */ 	lw	$a2,0xa0($sp)
/*  f19a1c0:	02203825 */ 	or	$a3,$s1,$zero
/*  f19a1c4:	afb30010 */ 	sw	$s3,0x10($sp)
/*  f19a1c8:	0fc097a9 */ 	jal	func0f025ea4
/*  f19a1cc:	afb70014 */ 	sw	$s7,0x14($sp)
/*  f19a1d0:	8eee001c */ 	lw	$t6,0x1c($s7)
/*  f19a1d4:	8fb800ac */ 	lw	$t8,0xac($sp)
/*  f19a1d8:	8fa900a8 */ 	lw	$t1,0xa8($sp)
/*  f19a1dc:	8fa800a4 */ 	lw	$t0,0xa4($sp)
/*  f19a1e0:	4405c000 */ 	mfc1	$a1,$f24
/*  f19a1e4:	240f00c8 */ 	addiu	$t7,$zero,0xc8
/*  f19a1e8:	afaf0014 */ 	sw	$t7,0x14($sp)
/*  f19a1ec:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f19a1f0:	afb20018 */ 	sw	$s2,0x18($sp)
/*  f19a1f4:	02002025 */ 	or	$a0,$s0,$zero
/*  f19a1f8:	02603025 */ 	or	$a2,$s3,$zero
/*  f19a1fc:	03c03825 */ 	or	$a3,$s8,$zero
/*  f19a200:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f19a204:	afb8001c */ 	sw	$t8,0x1c($sp)
/*  f19a208:	afa90020 */ 	sw	$t1,0x20($sp)
/*  f19a20c:	0fc0d077 */ 	jal	func0f0341dc
/*  f19a210:	afa80024 */ 	sw	$t0,0x24($sp)
.L0f19a214:
/*  f19a214:	3c19800b */ 	lui	$t9,0x800b
/*  f19a218:	8f39c530 */ 	lw	$t9,-0x3ad0($t9)
/*  f19a21c:	26b50001 */ 	addiu	$s5,$s5,0x1
/*  f19a220:	26d60004 */ 	addiu	$s6,$s6,0x4
/*  f19a224:	02b9082a */ 	slt	$at,$s5,$t9
/*  f19a228:	5420ff94 */ 	bnezl	$at,.L0f19a07c
/*  f19a22c:	8ed00000 */ 	lw	$s0,0x0($s6)
.L0f19a230:
/*  f19a230:	10000003 */ 	beqz	$zero,.L0f19a240
/*  f19a234:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f19a238:
/*  f19a238:	10000001 */ 	beqz	$zero,.L0f19a240
/*  f19a23c:	00001025 */ 	or	$v0,$zero,$zero
.L0f19a240:
/*  f19a240:	8fbf0074 */ 	lw	$ra,0x74($sp)
/*  f19a244:	d7b40038 */ 	ldc1	$f20,0x38($sp)
/*  f19a248:	d7b60040 */ 	ldc1	$f22,0x40($sp)
/*  f19a24c:	d7b80048 */ 	ldc1	$f24,0x48($sp)
/*  f19a250:	8fb00050 */ 	lw	$s0,0x50($sp)
/*  f19a254:	8fb10054 */ 	lw	$s1,0x54($sp)
/*  f19a258:	8fb20058 */ 	lw	$s2,0x58($sp)
/*  f19a25c:	8fb3005c */ 	lw	$s3,0x5c($sp)
/*  f19a260:	8fb40060 */ 	lw	$s4,0x60($sp)
/*  f19a264:	8fb50064 */ 	lw	$s5,0x64($sp)
/*  f19a268:	8fb60068 */ 	lw	$s6,0x68($sp)
/*  f19a26c:	8fb7006c */ 	lw	$s7,0x6c($sp)
/*  f19a270:	8fbe0070 */ 	lw	$s8,0x70($sp)
/*  f19a274:	03e00008 */ 	jr	$ra
/*  f19a278:	27bd00c8 */ 	addiu	$sp,$sp,0xc8
/*  f19a27c:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f19a280:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f19a284:	0fc4a2bd */ 	jal	func0f128af4
/*  f19a288:	00000000 */ 	sll	$zero,$zero,0x0
/*  f19a28c:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f19a290:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f19a294:	03e00008 */ 	jr	$ra
/*  f19a298:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f19a29c
/*  f19a29c:	248efff2 */ 	addiu	$t6,$a0,-14
/*  f19a2a0:	2dc10015 */ 	sltiu	$at,$t6,0x15
/*  f19a2a4:	1020000a */ 	beqz	$at,.L0f19a2d0
/*  f19a2a8:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f19a2ac:	3c017f1c */ 	lui	$at,%hi(var7f1b90a4)
/*  f19a2b0:	002e0821 */ 	addu	$at,$at,$t6
/*  f19a2b4:	8c2e90a4 */ 	lw	$t6,%lo(var7f1b90a4)($at)
/*  f19a2b8:	01c00008 */ 	jr	$t6
/*  f19a2bc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f19a2c0:	03e00008 */ 	jr	$ra
/*  f19a2c4:	00a01025 */ 	or	$v0,$a1,$zero
/*  f19a2c8:	03e00008 */ 	jr	$ra
/*  f19a2cc:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f19a2d0:
/*  f19a2d0:	00001025 */ 	or	$v0,$zero,$zero
/*  f19a2d4:	03e00008 */ 	jr	$ra
/*  f19a2d8:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f19a2dc
/*  f19a2dc:	248effe6 */ 	addiu	$t6,$a0,-26
/*  f19a2e0:	2dc10009 */ 	sltiu	$at,$t6,0x9
/*  f19a2e4:	1020000a */ 	beqz	$at,.L0f19a310
/*  f19a2e8:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f19a2ec:	3c017f1c */ 	lui	$at,%hi(var7f1b90f8)
/*  f19a2f0:	002e0821 */ 	addu	$at,$at,$t6
/*  f19a2f4:	8c2e90f8 */ 	lw	$t6,%lo(var7f1b90f8)($at)
/*  f19a2f8:	01c00008 */ 	jr	$t6
/*  f19a2fc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f19a300:	03e00008 */ 	jr	$ra
/*  f19a304:	24020078 */ 	addiu	$v0,$zero,0x78
/*  f19a308:	03e00008 */ 	jr	$ra
/*  f19a30c:	2402005a */ 	addiu	$v0,$zero,0x5a
.L0f19a310:
/*  f19a310:	2402003c */ 	addiu	$v0,$zero,0x3c
/*  f19a314:	03e00008 */ 	jr	$ra
/*  f19a318:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f19a31c
/*  f19a31c:	248efff9 */ 	addiu	$t6,$a0,-7
/*  f19a320:	2dc1000c */ 	sltiu	$at,$t6,0xc
/*  f19a324:	10200012 */ 	beqz	$at,.L0f19a370
/*  f19a328:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f19a32c:	3c017f1c */ 	lui	$at,%hi(var7f1b911c)
/*  f19a330:	002e0821 */ 	addu	$at,$at,$t6
/*  f19a334:	8c2e911c */ 	lw	$t6,%lo(var7f1b911c)($at)
/*  f19a338:	01c00008 */ 	jr	$t6
/*  f19a33c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f19a340:	03e00008 */ 	jr	$ra
/*  f19a344:	2402001f */ 	addiu	$v0,$zero,0x1f
/*  f19a348:	03e00008 */ 	jr	$ra
/*  f19a34c:	2402001e */ 	addiu	$v0,$zero,0x1e
/*  f19a350:	03e00008 */ 	jr	$ra
/*  f19a354:	2402001a */ 	addiu	$v0,$zero,0x1a
/*  f19a358:	03e00008 */ 	jr	$ra
/*  f19a35c:	24020022 */ 	addiu	$v0,$zero,0x22
/*  f19a360:	03e00008 */ 	jr	$ra
/*  f19a364:	24020021 */ 	addiu	$v0,$zero,0x21
/*  f19a368:	03e00008 */ 	jr	$ra
/*  f19a36c:	24020020 */ 	addiu	$v0,$zero,0x20
.L0f19a370:
/*  f19a370:	00001025 */ 	or	$v0,$zero,$zero
/*  f19a374:	03e00008 */ 	jr	$ra
/*  f19a378:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f19a37c
/*  f19a37c:	27bdff10 */ 	addiu	$sp,$sp,-240
/*  f19a380:	3c0f8009 */ 	lui	$t7,%hi(var80088494)
/*  f19a384:	afbf0024 */ 	sw	$ra,0x24($sp)
/*  f19a388:	afb00020 */ 	sw	$s0,0x20($sp)
/*  f19a38c:	25ef8494 */ 	addiu	$t7,$t7,%lo(var80088494)
/*  f19a390:	8de10000 */ 	lw	$at,0x0($t7)
/*  f19a394:	27ae00e4 */ 	addiu	$t6,$sp,0xe4
/*  f19a398:	8de80004 */ 	lw	$t0,0x4($t7)
/*  f19a39c:	adc10000 */ 	sw	$at,0x0($t6)
/*  f19a3a0:	8de10008 */ 	lw	$at,0x8($t7)
/*  f19a3a4:	adc80004 */ 	sw	$t0,0x4($t6)
/*  f19a3a8:	00808025 */ 	or	$s0,$a0,$zero
/*  f19a3ac:	adc10008 */ 	sw	$at,0x8($t6)
/*  f19a3b0:	8c89001c */ 	lw	$t1,0x1c($a0)
/*  f19a3b4:	0fc0f97c */ 	jal	func0f03e5f0
/*  f19a3b8:	afa90094 */ 	sw	$t1,0x94($sp)
/*  f19a3bc:	3c0a8009 */ 	lui	$t2,0x8009
/*  f19a3c0:	8d4a84a0 */ 	lw	$t2,-0x7b60($t2)
/*  f19a3c4:	e7a00050 */ 	swc1	$f0,0x50($sp)
/*  f19a3c8:	02002025 */ 	or	$a0,$s0,$zero
/*  f19a3cc:	0fc0a221 */ 	jal	chrGetTargetProp
/*  f19a3d0:	afaa0048 */ 	sw	$t2,0x48($sp)
/*  f19a3d4:	8e0b02d4 */ 	lw	$t3,0x2d4($s0)
/*  f19a3d8:	02002025 */ 	or	$a0,$s0,$zero
/*  f19a3dc:	2405001e */ 	addiu	$a1,$zero,0x1e
/*  f19a3e0:	8d6c0020 */ 	lw	$t4,0x20($t3)
/*  f19a3e4:	00003025 */ 	or	$a2,$zero,$zero
/*  f19a3e8:	a3ac0048 */ 	sb	$t4,0x48($sp)
/*  f19a3ec:	8e0d02d4 */ 	lw	$t5,0x2d4($s0)
/*  f19a3f0:	8db9004c */ 	lw	$t9,0x4c($t5)
/*  f19a3f4:	afa20044 */ 	sw	$v0,0x44($sp)
/*  f19a3f8:	0019c080 */ 	sll	$t8,$t9,0x2
/*  f19a3fc:	001877c2 */ 	srl	$t6,$t8,0x1f
/*  f19a400:	0fc1241a */ 	jal	func0f049068
/*  f19a404:	a3ae004b */ 	sb	$t6,0x4b($sp)
/*  f19a408:	10400026 */ 	beqz	$v0,.L0f19a4a4
/*  f19a40c:	8fa30044 */ 	lw	$v1,0x44($sp)
/*  f19a410:	c4640008 */ 	lwc1	$f4,0x8($v1)
/*  f19a414:	2401001e */ 	addiu	$at,$zero,0x1e
/*  f19a418:	3c054185 */ 	lui	$a1,0x4185
/*  f19a41c:	e7a40038 */ 	swc1	$f4,0x38($sp)
/*  f19a420:	c4660010 */ 	lwc1	$f6,0x10($v1)
/*  f19a424:	34a55555 */ 	ori	$a1,$a1,0x5555
/*  f19a428:	e7a60040 */ 	swc1	$f6,0x40($sp)
/*  f19a42c:	8e0f02d4 */ 	lw	$t7,0x2d4($s0)
/*  f19a430:	8de20020 */ 	lw	$v0,0x20($t7)
/*  f19a434:	10410003 */ 	beq	$v0,$at,.L0f19a444
/*  f19a438:	2401001f */ 	addiu	$at,$zero,0x1f
/*  f19a43c:	54410006 */ 	bnel	$v0,$at,.L0f19a458
/*  f19a440:	c46a000c */ 	lwc1	$f10,0xc($v1)
.L0f19a444:
/*  f19a444:	8c680004 */ 	lw	$t0,0x4($v1)
/*  f19a448:	c50800b4 */ 	lwc1	$f8,0xb4($t0)
/*  f19a44c:	1000000c */ 	beqz	$zero,.L0f19a480
/*  f19a450:	e7a8003c */ 	swc1	$f8,0x3c($sp)
/*  f19a454:	c46a000c */ 	lwc1	$f10,0xc($v1)
.L0f19a458:
/*  f19a458:	24010006 */ 	addiu	$at,$zero,0x6
/*  f19a45c:	e7aa003c */ 	swc1	$f10,0x3c($sp)
/*  f19a460:	90690000 */ 	lbu	$t1,0x0($v1)
/*  f19a464:	c7b0003c */ 	lwc1	$f16,0x3c($sp)
/*  f19a468:	15210005 */ 	bne	$t1,$at,.L0f19a480
/*  f19a46c:	3c0141c8 */ 	lui	$at,0x41c8
/*  f19a470:	44819000 */ 	mtc1	$at,$f18
/*  f19a474:	00000000 */ 	sll	$zero,$zero,0x0
/*  f19a478:	46128101 */ 	sub.s	$f4,$f16,$f18
/*  f19a47c:	e7a4003c */ 	swc1	$f4,0x3c($sp)
.L0f19a480:
/*  f19a480:	8fa40094 */ 	lw	$a0,0x94($sp)
/*  f19a484:	27a60038 */ 	addiu	$a2,$sp,0x38
/*  f19a488:	27a70098 */ 	addiu	$a3,$sp,0x98
/*  f19a48c:	24840008 */ 	addiu	$a0,$a0,0x8
/*  f19a490:	0fc100c7 */ 	jal	func0f04031c
/*  f19a494:	afa4002c */ 	sw	$a0,0x2c($sp)
/*  f19a498:	3c017f1c */ 	lui	$at,%hi(var7f1b914c)
/*  f19a49c:	1000001c */ 	beqz	$zero,.L0f19a510
/*  f19a4a0:	c420914c */ 	lwc1	$f0,%lo(var7f1b914c)($at)
.L0f19a4a4:
/*  f19a4a4:	3c017f1c */ 	lui	$at,%hi(var7f1b9150)
/*  f19a4a8:	0c0068f4 */ 	jal	func0001a3d0
/*  f19a4ac:	c42c9150 */ 	lwc1	$f12,%lo(var7f1b9150)($at)
/*  f19a4b0:	e7a00030 */ 	swc1	$f0,0x30($sp)
/*  f19a4b4:	0c0068f7 */ 	jal	func0001a3dc
/*  f19a4b8:	c7ac0050 */ 	lwc1	$f12,0x50($sp)
/*  f19a4bc:	c7a60030 */ 	lwc1	$f6,0x30($sp)
/*  f19a4c0:	3c017f1c */ 	lui	$at,%hi(var7f1b9154)
/*  f19a4c4:	c42c9154 */ 	lwc1	$f12,%lo(var7f1b9154)($at)
/*  f19a4c8:	46060202 */ 	mul.s	$f8,$f0,$f6
/*  f19a4cc:	0c0068f7 */ 	jal	func0001a3dc
/*  f19a4d0:	e7a80098 */ 	swc1	$f8,0x98($sp)
/*  f19a4d4:	3c017f1c */ 	lui	$at,%hi(var7f1b9158)
/*  f19a4d8:	e7a0009c */ 	swc1	$f0,0x9c($sp)
/*  f19a4dc:	0c0068f4 */ 	jal	func0001a3d0
/*  f19a4e0:	c42c9158 */ 	lwc1	$f12,%lo(var7f1b9158)($at)
/*  f19a4e4:	e7a00030 */ 	swc1	$f0,0x30($sp)
/*  f19a4e8:	0c0068f4 */ 	jal	func0001a3d0
/*  f19a4ec:	c7ac0050 */ 	lwc1	$f12,0x50($sp)
/*  f19a4f0:	c7aa0030 */ 	lwc1	$f10,0x30($sp)
/*  f19a4f4:	8faa0094 */ 	lw	$t2,0x94($sp)
/*  f19a4f8:	3c017f1c */ 	lui	$at,%hi(var7f1b915c)
/*  f19a4fc:	460a0402 */ 	mul.s	$f16,$f0,$f10
/*  f19a500:	254b0008 */ 	addiu	$t3,$t2,0x8
/*  f19a504:	afab002c */ 	sw	$t3,0x2c($sp)
/*  f19a508:	c420915c */ 	lwc1	$f0,%lo(var7f1b915c)($at)
/*  f19a50c:	e7b000a0 */ 	swc1	$f16,0xa0($sp)
.L0f19a510:
/*  f19a510:	c7b20098 */ 	lwc1	$f18,0x98($sp)
/*  f19a514:	c7a6009c */ 	lwc1	$f6,0x9c($sp)
/*  f19a518:	c7aa00a0 */ 	lwc1	$f10,0xa0($sp)
/*  f19a51c:	46009102 */ 	mul.s	$f4,$f18,$f0
/*  f19a520:	27a400a4 */ 	addiu	$a0,$sp,0xa4
/*  f19a524:	46003202 */ 	mul.s	$f8,$f6,$f0
/*  f19a528:	00000000 */ 	sll	$zero,$zero,0x0
/*  f19a52c:	46005402 */ 	mul.s	$f16,$f10,$f0
/*  f19a530:	e7a400e4 */ 	swc1	$f4,0xe4($sp)
/*  f19a534:	e7a800e8 */ 	swc1	$f8,0xe8($sp)
/*  f19a538:	0c00566c */ 	jal	func000159b0
/*  f19a53c:	e7b000ec */ 	swc1	$f16,0xec($sp)
/*  f19a540:	8e0c02d4 */ 	lw	$t4,0x2d4($s0)
/*  f19a544:	2401001a */ 	addiu	$at,$zero,0x1a
/*  f19a548:	27a500a4 */ 	addiu	$a1,$sp,0xa4
/*  f19a54c:	8d8d0020 */ 	lw	$t5,0x20($t4)
/*  f19a550:	15a1000a */ 	bne	$t5,$at,.L0f19a57c
/*  f19a554:	3c017f1c */ 	lui	$at,%hi(var7f1b9160)
/*  f19a558:	0c005900 */ 	jal	func00016400
/*  f19a55c:	c42c9160 */ 	lwc1	$f12,%lo(var7f1b9160)($at)
/*  f19a560:	3c017f1c */ 	lui	$at,%hi(var7f1b9164)
/*  f19a564:	c42c9164 */ 	lwc1	$f12,%lo(var7f1b9164)($at)
/*  f19a568:	0c0058ba */ 	jal	func000162e8
/*  f19a56c:	27a50054 */ 	addiu	$a1,$sp,0x54
/*  f19a570:	27a40054 */ 	addiu	$a0,$sp,0x54
/*  f19a574:	0c00567f */ 	jal	func000159fc
/*  f19a578:	27a500a4 */ 	addiu	$a1,$sp,0xa4
.L0f19a57c:
/*  f19a57c:	3c017f1c */ 	lui	$at,%hi(var7f1b9168)
/*  f19a580:	c42c9168 */ 	lwc1	$f12,%lo(var7f1b9168)($at)
/*  f19a584:	0c0058ba */ 	jal	func000162e8
/*  f19a588:	27a50054 */ 	addiu	$a1,$sp,0x54
/*  f19a58c:	27a40054 */ 	addiu	$a0,$sp,0x54
/*  f19a590:	0c0056f8 */ 	jal	func00015be0
/*  f19a594:	27a500a4 */ 	addiu	$a1,$sp,0xa4
/*  f19a598:	c7ac0050 */ 	lwc1	$f12,0x50($sp)
/*  f19a59c:	0c0058dd */ 	jal	func00016374
/*  f19a5a0:	27a50054 */ 	addiu	$a1,$sp,0x54
/*  f19a5a4:	27a40054 */ 	addiu	$a0,$sp,0x54
/*  f19a5a8:	0c0056f8 */ 	jal	func00015be0
/*  f19a5ac:	27a500a4 */ 	addiu	$a1,$sp,0xa4
/*  f19a5b0:	8fa70094 */ 	lw	$a3,0x94($sp)
/*  f19a5b4:	27b900a4 */ 	addiu	$t9,$sp,0xa4
/*  f19a5b8:	27b800e4 */ 	addiu	$t8,$sp,0xe4
/*  f19a5bc:	afb80014 */ 	sw	$t8,0x14($sp)
/*  f19a5c0:	afb90010 */ 	sw	$t9,0x10($sp)
/*  f19a5c4:	02002025 */ 	or	$a0,$s0,$zero
/*  f19a5c8:	27a50048 */ 	addiu	$a1,$sp,0x48
/*  f19a5cc:	8fa6002c */ 	lw	$a2,0x2c($sp)
/*  f19a5d0:	0fc27b86 */ 	jal	func0f09ee18
/*  f19a5d4:	24e70028 */ 	addiu	$a3,$a3,0x28
/*  f19a5d8:	93ae0048 */ 	lbu	$t6,0x48($sp)
/*  f19a5dc:	24010022 */ 	addiu	$at,$zero,0x22
/*  f19a5e0:	55c10006 */ 	bnel	$t6,$at,.L0f19a5fc
/*  f19a5e4:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*  f19a5e8:	8e0202d4 */ 	lw	$v0,0x2d4($s0)
/*  f19a5ec:	944f0064 */ 	lhu	$t7,0x64($v0)
/*  f19a5f0:	35e81000 */ 	ori	$t0,$t7,0x1000
/*  f19a5f4:	a4480064 */ 	sh	$t0,0x64($v0)
/*  f19a5f8:	8fbf0024 */ 	lw	$ra,0x24($sp)
.L0f19a5fc:
/*  f19a5fc:	8fb00020 */ 	lw	$s0,0x20($sp)
/*  f19a600:	27bd00f0 */ 	addiu	$sp,$sp,0xf0
/*  f19a604:	03e00008 */ 	jr	$ra
/*  f19a608:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f19a60c
/*  f19a60c:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*  f19a610:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f19a614:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f19a618:	afa40028 */ 	sw	$a0,0x28($sp)
/*  f19a61c:	afa5002c */ 	sw	$a1,0x2c($sp)
/*  f19a620:	0fc2c3f4 */ 	jal	weaponFindById
/*  f19a624:	afa6001c */ 	sw	$a2,0x1c($sp)
/*  f19a628:	10400024 */ 	beqz	$v0,.L0f19a6bc
/*  f19a62c:	8fa6001c */ 	lw	$a2,0x1c($sp)
/*  f19a630:	8fae002c */ 	lw	$t6,0x2c($sp)
/*  f19a634:	000e7880 */ 	sll	$t7,$t6,0x2
/*  f19a638:	004fc021 */ 	addu	$t8,$v0,$t7
/*  f19a63c:	8f030014 */ 	lw	$v1,0x14($t8)
/*  f19a640:	5060001f */ 	beqzl	$v1,.L0f19a6c0
/*  f19a644:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f19a648:	8c620000 */ 	lw	$v0,0x0($v1)
/*  f19a64c:	24010001 */ 	addiu	$at,$zero,0x1
/*  f19a650:	54410006 */ 	bnel	$v0,$at,.L0f19a66c
/*  f19a654:	24010101 */ 	addiu	$at,$zero,0x101
/*  f19a658:	80790024 */ 	lb	$t9,0x24($v1)
/*  f19a65c:	80680025 */ 	lb	$t0,0x25($v1)
/*  f19a660:	10000016 */ 	beqz	$zero,.L0f19a6bc
/*  f19a664:	03283021 */ 	addu	$a2,$t9,$t0
/*  f19a668:	24010101 */ 	addiu	$at,$zero,0x101
.L0f19a66c:
/*  f19a66c:	54410006 */ 	bnel	$v0,$at,.L0f19a688
/*  f19a670:	24010201 */ 	addiu	$at,$zero,0x201
/*  f19a674:	80690024 */ 	lb	$t1,0x24($v1)
/*  f19a678:	806a0025 */ 	lb	$t2,0x25($v1)
/*  f19a67c:	1000000f */ 	beqz	$zero,.L0f19a6bc
/*  f19a680:	012a3021 */ 	addu	$a2,$t1,$t2
/*  f19a684:	24010201 */ 	addiu	$at,$zero,0x201
.L0f19a688:
/*  f19a688:	54410006 */ 	bnel	$v0,$at,.L0f19a6a4
/*  f19a68c:	24010003 */ 	addiu	$at,$zero,0x3
/*  f19a690:	806b0024 */ 	lb	$t3,0x24($v1)
/*  f19a694:	806c0025 */ 	lb	$t4,0x25($v1)
/*  f19a698:	10000008 */ 	beqz	$zero,.L0f19a6bc
/*  f19a69c:	016c3021 */ 	addu	$a2,$t3,$t4
/*  f19a6a0:	24010003 */ 	addiu	$at,$zero,0x3
.L0f19a6a4:
/*  f19a6a4:	14410005 */ 	bne	$v0,$at,.L0f19a6bc
/*  f19a6a8:	8fad0028 */ 	lw	$t5,0x28($sp)
/*  f19a6ac:	24010014 */ 	addiu	$at,$zero,0x14
/*  f19a6b0:	51a10003 */ 	beql	$t5,$at,.L0f19a6c0
/*  f19a6b4:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f19a6b8:	2406003c */ 	addiu	$a2,$zero,0x3c
.L0f19a6bc:
/*  f19a6bc:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f19a6c0:
/*  f19a6c0:	27bd0028 */ 	addiu	$sp,$sp,0x28
/*  f19a6c4:	00c01025 */ 	or	$v0,$a2,$zero
/*  f19a6c8:	03e00008 */ 	jr	$ra
/*  f19a6cc:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f19a6d0
/*  f19a6d0:	27bdffb0 */ 	addiu	$sp,$sp,-80
/*  f19a6d4:	afa40050 */ 	sw	$a0,0x50($sp)
/*  f19a6d8:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f19a6dc:	afa50054 */ 	sw	$a1,0x54($sp)
/*  f19a6e0:	00a02025 */ 	or	$a0,$a1,$zero
/*  f19a6e4:	afa60058 */ 	sw	$a2,0x58($sp)
/*  f19a6e8:	0fc45095 */ 	jal	func0f114254
/*  f19a6ec:	00e02825 */ 	or	$a1,$a3,$zero
/*  f19a6f0:	afa2004c */ 	sw	$v0,0x4c($sp)
/*  f19a6f4:	8fa40058 */ 	lw	$a0,0x58($sp)
/*  f19a6f8:	0fc45095 */ 	jal	func0f114254
/*  f19a6fc:	8fa50060 */ 	lw	$a1,0x60($sp)
/*  f19a700:	8fae004c */ 	lw	$t6,0x4c($sp)
/*  f19a704:	afa20048 */ 	sw	$v0,0x48($sp)
/*  f19a708:	51c0002d */ 	beqzl	$t6,.L0f19a7c0
/*  f19a70c:	00001025 */ 	or	$v0,$zero,$zero
/*  f19a710:	1040002a */ 	beqz	$v0,.L0f19a7bc
/*  f19a714:	3c0f800a */ 	lui	$t7,0x800a
/*  f19a718:	8fa80050 */ 	lw	$t0,0x50($sp)
/*  f19a71c:	8def9fc8 */ 	lw	$t7,-0x6038($t7)
/*  f19a720:	85090000 */ 	lh	$t1,0x0($t0)
/*  f19a724:	000fc243 */ 	sra	$t8,$t7,0x9
/*  f19a728:	0018c9c0 */ 	sll	$t9,$t8,0x7
/*  f19a72c:	000950c0 */ 	sll	$t2,$t1,0x3
/*  f19a730:	032a2021 */ 	addu	$a0,$t9,$t2
/*  f19a734:	0fc45090 */ 	jal	func0f114240
/*  f19a738:	00802825 */ 	or	$a1,$a0,$zero
/*  f19a73c:	8fa4004c */ 	lw	$a0,0x4c($sp)
/*  f19a740:	8fa50048 */ 	lw	$a1,0x48($sp)
/*  f19a744:	27a60030 */ 	addiu	$a2,$sp,0x30
/*  f19a748:	0fc4547b */ 	jal	func0f1151ec
/*  f19a74c:	24070006 */ 	addiu	$a3,$zero,0x6
/*  f19a750:	afa2002c */ 	sw	$v0,0x2c($sp)
/*  f19a754:	00002025 */ 	or	$a0,$zero,$zero
/*  f19a758:	0fc45090 */ 	jal	func0f114240
/*  f19a75c:	00002825 */ 	or	$a1,$zero,$zero
/*  f19a760:	8fab002c */ 	lw	$t3,0x2c($sp)
/*  f19a764:	8fac0030 */ 	lw	$t4,0x30($sp)
/*  f19a768:	29610002 */ 	slti	$at,$t3,0x2
/*  f19a76c:	54200014 */ 	bnezl	$at,.L0f19a7c0
/*  f19a770:	00001025 */ 	or	$v0,$zero,$zero
/*  f19a774:	1180000c */ 	beqz	$t4,.L0f19a7a8
/*  f19a778:	00002825 */ 	or	$a1,$zero,$zero
/*  f19a77c:	27a30030 */ 	addiu	$v1,$sp,0x30
/*  f19a780:	8c640000 */ 	lw	$a0,0x0($v1)
/*  f19a784:	8fa20064 */ 	lw	$v0,0x64($sp)
/*  f19a788:	8c8e0000 */ 	lw	$t6,0x0($a0)
.L0f19a78c:
/*  f19a78c:	24a50001 */ 	addiu	$a1,$a1,0x1
/*  f19a790:	24420002 */ 	addiu	$v0,$v0,0x2
/*  f19a794:	a44e00f6 */ 	sh	$t6,0xf6($v0)
/*  f19a798:	8c640004 */ 	lw	$a0,0x4($v1)
/*  f19a79c:	24630004 */ 	addiu	$v1,$v1,0x4
/*  f19a7a0:	5480fffa */ 	bnezl	$a0,.L0f19a78c
/*  f19a7a4:	8c8e0000 */ 	lw	$t6,0x0($a0)
.L0f19a7a8:
/*  f19a7a8:	8fa60064 */ 	lw	$a2,0x64($sp)
/*  f19a7ac:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f19a7b0:	a0c00105 */ 	sb	$zero,0x105($a2)
/*  f19a7b4:	10000002 */ 	beqz	$zero,.L0f19a7c0
/*  f19a7b8:	a0c50104 */ 	sb	$a1,0x104($a2)
.L0f19a7bc:
/*  f19a7bc:	00001025 */ 	or	$v0,$zero,$zero
.L0f19a7c0:
/*  f19a7c0:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f19a7c4:	27bd0050 */ 	addiu	$sp,$sp,0x50
/*  f19a7c8:	03e00008 */ 	jr	$ra
/*  f19a7cc:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f19a7d0
/*  f19a7d0:	27bdff90 */ 	addiu	$sp,$sp,-112
/*  f19a7d4:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f19a7d8:	afa40070 */ 	sw	$a0,0x70($sp)
/*  f19a7dc:	afa50074 */ 	sw	$a1,0x74($sp)
/*  f19a7e0:	3087ffff */ 	andi	$a3,$a0,0xffff
/*  f19a7e4:	00e02025 */ 	or	$a0,$a3,$zero
/*  f19a7e8:	24050042 */ 	addiu	$a1,$zero,0x42
/*  f19a7ec:	0fc456ac */ 	jal	padUnpack
/*  f19a7f0:	27a6001c */ 	addiu	$a2,$sp,0x1c
/*  f19a7f4:	8fae0064 */ 	lw	$t6,0x64($sp)
/*  f19a7f8:	c7a4001c */ 	lwc1	$f4,0x1c($sp)
/*  f19a7fc:	8fb80074 */ 	lw	$t8,0x74($sp)
/*  f19a800:	240fffff */ 	addiu	$t7,$zero,-1
/*  f19a804:	a7af001a */ 	sh	$t7,0x1a($sp)
/*  f19a808:	a7ae0018 */ 	sh	$t6,0x18($sp)
/*  f19a80c:	27a4001c */ 	addiu	$a0,$sp,0x1c
/*  f19a810:	27a50018 */ 	addiu	$a1,$sp,0x18
/*  f19a814:	00003025 */ 	or	$a2,$zero,$zero
/*  f19a818:	00003825 */ 	or	$a3,$zero,$zero
/*  f19a81c:	0c00a8db */ 	jal	func0002a36c
/*  f19a820:	e7040000 */ 	swc1	$f4,0x0($t8)
/*  f19a824:	3c014316 */ 	lui	$at,0x4316
/*  f19a828:	44813000 */ 	mtc1	$at,$f6
/*  f19a82c:	8fa20074 */ 	lw	$v0,0x74($sp)
/*  f19a830:	46060200 */ 	add.s	$f8,$f0,$f6
/*  f19a834:	e4480004 */ 	swc1	$f8,0x4($v0)
/*  f19a838:	c7aa0024 */ 	lwc1	$f10,0x24($sp)
/*  f19a83c:	e44a0008 */ 	swc1	$f10,0x8($v0)
/*  f19a840:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f19a844:	27bd0070 */ 	addiu	$sp,$sp,0x70
/*  f19a848:	03e00008 */ 	jr	$ra
/*  f19a84c:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f19a850
/*  f19a850:	27bdfeb8 */ 	addiu	$sp,$sp,-328
/*  f19a854:	afb10048 */ 	sw	$s1,0x48($sp)
/*  f19a858:	00808825 */ 	or	$s1,$a0,$zero
/*  f19a85c:	afbf004c */ 	sw	$ra,0x4c($sp)
/*  f19a860:	afb00044 */ 	sw	$s0,0x44($sp)
/*  f19a864:	02203025 */ 	or	$a2,$s1,$zero
/*  f19a868:	24040120 */ 	addiu	$a0,$zero,0x120
/*  f19a86c:	0fc22e20 */ 	jal	func0f08b880
/*  f19a870:	24050058 */ 	addiu	$a1,$zero,0x58
/*  f19a874:	1040007c */ 	beqz	$v0,.L0f19aa68
/*  f19a878:	00408025 */ 	or	$s0,$v0,$zero
/*  f19a87c:	3c0f8009 */ 	lui	$t7,%hi(var800884a4)
/*  f19a880:	25ef84a4 */ 	addiu	$t7,$t7,%lo(var800884a4)
/*  f19a884:	8de10000 */ 	lw	$at,0x0($t7)
/*  f19a888:	27ae0078 */ 	addiu	$t6,$sp,0x78
/*  f19a88c:	8df90004 */ 	lw	$t9,0x4($t7)
/*  f19a890:	adc10000 */ 	sw	$at,0x0($t6)
/*  f19a894:	8de10008 */ 	lw	$at,0x8($t7)
/*  f19a898:	02202025 */ 	or	$a0,$s1,$zero
/*  f19a89c:	add90004 */ 	sw	$t9,0x4($t6)
/*  f19a8a0:	0fc0f97c */ 	jal	func0f03e5f0
/*  f19a8a4:	adc10008 */ 	sw	$at,0x8($t6)
/*  f19a8a8:	e7a00074 */ 	swc1	$f0,0x74($sp)
/*  f19a8ac:	0fc0f9d5 */ 	jal	func0f03e754
/*  f19a8b0:	02202025 */ 	or	$a0,$s1,$zero
/*  f19a8b4:	e7a00070 */ 	swc1	$f0,0x70($sp)
/*  f19a8b8:	0c0068f4 */ 	jal	func0001a3d0
/*  f19a8bc:	46000306 */ 	mov.s	$f12,$f0
/*  f19a8c0:	e7a0005c */ 	swc1	$f0,0x5c($sp)
/*  f19a8c4:	0c0068f7 */ 	jal	func0001a3dc
/*  f19a8c8:	c7ac0074 */ 	lwc1	$f12,0x74($sp)
/*  f19a8cc:	c7a4005c */ 	lwc1	$f4,0x5c($sp)
/*  f19a8d0:	c7ac0070 */ 	lwc1	$f12,0x70($sp)
/*  f19a8d4:	46040182 */ 	mul.s	$f6,$f0,$f4
/*  f19a8d8:	0c0068f7 */ 	jal	func0001a3dc
/*  f19a8dc:	e7a60064 */ 	swc1	$f6,0x64($sp)
/*  f19a8e0:	e7a00068 */ 	swc1	$f0,0x68($sp)
/*  f19a8e4:	0c0068f4 */ 	jal	func0001a3d0
/*  f19a8e8:	c7ac0070 */ 	lwc1	$f12,0x70($sp)
/*  f19a8ec:	e7a0005c */ 	swc1	$f0,0x5c($sp)
/*  f19a8f0:	0c0068f4 */ 	jal	func0001a3d0
/*  f19a8f4:	c7ac0074 */ 	lwc1	$f12,0x74($sp)
/*  f19a8f8:	c7a8005c */ 	lwc1	$f8,0x5c($sp)
/*  f19a8fc:	c7ac0070 */ 	lwc1	$f12,0x70($sp)
/*  f19a900:	27a500c4 */ 	addiu	$a1,$sp,0xc4
/*  f19a904:	46080282 */ 	mul.s	$f10,$f0,$f8
/*  f19a908:	0c0058ba */ 	jal	func000162e8
/*  f19a90c:	e7aa006c */ 	swc1	$f10,0x6c($sp)
/*  f19a910:	c7ac0074 */ 	lwc1	$f12,0x74($sp)
/*  f19a914:	0c0058dd */ 	jal	func00016374
/*  f19a918:	27a50084 */ 	addiu	$a1,$sp,0x84
/*  f19a91c:	27a40084 */ 	addiu	$a0,$sp,0x84
/*  f19a920:	0c0056f8 */ 	jal	func00015be0
/*  f19a924:	27a500c4 */ 	addiu	$a1,$sp,0xc4
/*  f19a928:	0c00566c */ 	jal	func000159b0
/*  f19a92c:	27a40104 */ 	addiu	$a0,$sp,0x104
/*  f19a930:	8e23001c */ 	lw	$v1,0x1c($s1)
/*  f19a934:	27a90064 */ 	addiu	$t1,$sp,0x64
/*  f19a938:	27aa0104 */ 	addiu	$t2,$sp,0x104
/*  f19a93c:	24650008 */ 	addiu	$a1,$v1,0x8
/*  f19a940:	afa5001c */ 	sw	$a1,0x1c($sp)
/*  f19a944:	afaa0014 */ 	sw	$t2,0x14($sp)
/*  f19a948:	afa90010 */ 	sw	$t1,0x10($sp)
/*  f19a94c:	02002025 */ 	or	$a0,$s0,$zero
/*  f19a950:	27a700c4 */ 	addiu	$a3,$sp,0xc4
/*  f19a954:	24660028 */ 	addiu	$a2,$v1,0x28
/*  f19a958:	0fc27af3 */ 	jal	func0f09ebcc
/*  f19a95c:	afa30018 */ 	sw	$v1,0x18($sp)
/*  f19a960:	8e0b0040 */ 	lw	$t3,0x40($s0)
/*  f19a964:	316c0080 */ 	andi	$t4,$t3,0x80
/*  f19a968:	51800040 */ 	beqzl	$t4,.L0f19aa6c
/*  f19a96c:	8fbf004c */ 	lw	$ra,0x4c($sp)
/*  f19a970:	0fc0a221 */ 	jal	chrGetTargetProp
/*  f19a974:	02202025 */ 	or	$a0,$s1,$zero
/*  f19a978:	3c01bf80 */ 	lui	$at,0xbf80
/*  f19a97c:	44810000 */ 	mtc1	$at,$f0
/*  f19a980:	3c0140f0 */ 	lui	$at,0x40f0
/*  f19a984:	44818000 */ 	mtc1	$at,$f16
/*  f19a988:	8e180048 */ 	lw	$t8,0x48($s0)
/*  f19a98c:	240dffff */ 	addiu	$t5,$zero,-1
/*  f19a990:	a60d0062 */ 	sh	$t5,0x62($s0)
/*  f19a994:	e7100010 */ 	swc1	$f16,0x10($t8)
/*  f19a998:	8e0e0048 */ 	lw	$t6,0x48($s0)
/*  f19a99c:	c7b20070 */ 	lwc1	$f18,0x70($sp)
/*  f19a9a0:	3c092000 */ 	lui	$t1,0x2000
/*  f19a9a4:	240bffff */ 	addiu	$t3,$zero,-1
/*  f19a9a8:	e5d20014 */ 	swc1	$f18,0x14($t6)
/*  f19a9ac:	8e0f0048 */ 	lw	$t7,0x48($s0)
/*  f19a9b0:	c7a40074 */ 	lwc1	$f4,0x74($sp)
/*  f19a9b4:	240cffff */ 	addiu	$t4,$zero,-1
/*  f19a9b8:	00002025 */ 	or	$a0,$zero,$zero
/*  f19a9bc:	e5e40018 */ 	swc1	$f4,0x18($t7)
/*  f19a9c0:	8e190048 */ 	lw	$t9,0x48($s0)
/*  f19a9c4:	24068053 */ 	addiu	$a2,$zero,-32685
/*  f19a9c8:	2407ffff */ 	addiu	$a3,$zero,-1
/*  f19a9cc:	af2000f4 */ 	sw	$zero,0xf4($t9)
/*  f19a9d0:	8e0a0048 */ 	lw	$t2,0x48($s0)
/*  f19a9d4:	ad4900b4 */ 	sw	$t1,0xb4($t2)
/*  f19a9d8:	8e050014 */ 	lw	$a1,0x14($s0)
/*  f19a9dc:	afa20060 */ 	sw	$v0,0x60($sp)
/*  f19a9e0:	afac002c */ 	sw	$t4,0x2c($sp)
/*  f19a9e4:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f19a9e8:	afa00020 */ 	sw	$zero,0x20($sp)
/*  f19a9ec:	afa0001c */ 	sw	$zero,0x1c($sp)
/*  f19a9f0:	afa00018 */ 	sw	$zero,0x18($sp)
/*  f19a9f4:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f19a9f8:	afab0010 */ 	sw	$t3,0x10($sp)
/*  f19a9fc:	e7a00038 */ 	swc1	$f0,0x38($sp)
/*  f19aa00:	e7a00034 */ 	swc1	$f0,0x34($sp)
/*  f19aa04:	e7a00030 */ 	swc1	$f0,0x30($sp)
/*  f19aa08:	0fc24e7e */ 	jal	func0f0939f8
/*  f19aa0c:	e7a00024 */ 	swc1	$f0,0x24($sp)
/*  f19aa10:	8fa80060 */ 	lw	$t0,0x60($sp)
/*  f19aa14:	8e23001c */ 	lw	$v1,0x1c($s1)
/*  f19aa18:	02202025 */ 	or	$a0,$s1,$zero
/*  f19aa1c:	250d0028 */ 	addiu	$t5,$t0,0x28
/*  f19aa20:	afad0010 */ 	sw	$t5,0x10($sp)
/*  f19aa24:	8e180048 */ 	lw	$t8,0x48($s0)
/*  f19aa28:	25060008 */ 	addiu	$a2,$t0,0x8
/*  f19aa2c:	24650008 */ 	addiu	$a1,$v1,0x8
/*  f19aa30:	24670028 */ 	addiu	$a3,$v1,0x28
/*  f19aa34:	0fc669b4 */ 	jal	func0f19a6d0
/*  f19aa38:	afb80014 */ 	sw	$t8,0x14($sp)
/*  f19aa3c:	54400004 */ 	bnezl	$v0,.L0f19aa50
/*  f19aa40:	8e020048 */ 	lw	$v0,0x48($s0)
/*  f19aa44:	10000008 */ 	beqz	$zero,.L0f19aa68
/*  f19aa48:	a6000062 */ 	sh	$zero,0x62($s0)
/*  f19aa4c:	8e020048 */ 	lw	$v0,0x48($s0)
.L0f19aa50:
/*  f19aa50:	944400f8 */ 	lhu	$a0,0xf8($v0)
/*  f19aa54:	0fc669f4 */ 	jal	func0f19a7d0
/*  f19aa58:	244500c4 */ 	addiu	$a1,$v0,0xc4
/*  f19aa5c:	8e0e0014 */ 	lw	$t6,0x14($s0)
/*  f19aa60:	8e2f02d4 */ 	lw	$t7,0x2d4($s1)
/*  f19aa64:	adee0044 */ 	sw	$t6,0x44($t7)
.L0f19aa68:
/*  f19aa68:	8fbf004c */ 	lw	$ra,0x4c($sp)
.L0f19aa6c:
/*  f19aa6c:	8fb00044 */ 	lw	$s0,0x44($sp)
/*  f19aa70:	8fb10048 */ 	lw	$s1,0x48($sp)
/*  f19aa74:	03e00008 */ 	jr	$ra
/*  f19aa78:	27bd0148 */ 	addiu	$sp,$sp,0x148
/*  f19aa7c:	00000000 */ 	sll	$zero,$zero,0x0
);

/**
 * @cmd 0185
 */
bool ai0185(void)
{
	func0f190708();
	g_Vars.aioffset += 2;
	return false;
}

/**
 * @cmd 0176
 */
GLOBAL_ASM(
glabel ai0176
/*  f19aab4:	3c07800a */ 	lui	$a3,%hi(g_Vars)
/*  f19aab8:	24e79fc0 */ 	addiu	$a3,$a3,%lo(g_Vars)
/*  f19aabc:	8ce20424 */ 	lw	$v0,0x424($a3)
/*  f19aac0:	8ce40434 */ 	lw	$a0,0x434($a3)
/*  f19aac4:	8ce50438 */ 	lw	$a1,0x438($a3)
/*  f19aac8:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*  f19aacc:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f19aad0:	10400003 */ 	beqz	$v0,.L0f19aae0
/*  f19aad4:	00854821 */ 	addu	$t1,$a0,$a1
/*  f19aad8:	8c4302d4 */ 	lw	$v1,0x2d4($v0)
/*  f19aadc:	14600004 */ 	bnez	$v1,.L0f19aaf0
.L0f19aae0:
/*  f19aae0:	24ae0003 */ 	addiu	$t6,$a1,0x3
/*  f19aae4:	acee0438 */ 	sw	$t6,0x438($a3)
/*  f19aae8:	8c4302d4 */ 	lw	$v1,0x2d4($v0)
/*  f19aaec:	01c02825 */ 	or	$a1,$t6,$zero
.L0f19aaf0:
/*  f19aaf0:	906f0059 */ 	lbu	$t7,0x59($v1)
/*  f19aaf4:	24010001 */ 	addiu	$at,$zero,0x1
/*  f19aaf8:	24b80003 */ 	addiu	$t8,$a1,0x3
/*  f19aafc:	55e1000b */ 	bnel	$t7,$at,.L0f19ab2c
/*  f19ab00:	acf80438 */ 	sw	$t8,0x438($a3)
/*  f19ab04:	91260002 */ 	lbu	$a2,0x2($t1)
/*  f19ab08:	0fc13583 */ 	jal	chraiGoToLabel
/*  f19ab0c:	afa30018 */ 	sw	$v1,0x18($sp)
/*  f19ab10:	3c07800a */ 	lui	$a3,%hi(g_Vars)
/*  f19ab14:	8fa80018 */ 	lw	$t0,0x18($sp)
/*  f19ab18:	24e79fc0 */ 	addiu	$a3,$a3,%lo(g_Vars)
/*  f19ab1c:	ace20438 */ 	sw	$v0,0x438($a3)
/*  f19ab20:	10000002 */ 	beqz	$zero,.L0f19ab2c
/*  f19ab24:	a1000059 */ 	sb	$zero,0x59($t0)
/*  f19ab28:	acf80438 */ 	sw	$t8,0x438($a3)
.L0f19ab2c:
/*  f19ab2c:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f19ab30:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*  f19ab34:	00001025 */ 	or	$v0,$zero,$zero
/*  f19ab38:	03e00008 */ 	jr	$ra
/*  f19ab3c:	00000000 */ 	sll	$zero,$zero,0x0
);

void func0f19ab40(void)
{
	if (var80090af0) {
		var80090af4 = 0;
		var80090af8 = 0;
		var80090afc = 0;
	}
}

GLOBAL_ASM(
glabel func0f19ab70
/*  f19ab70:	27bdfde8 */ 	addiu	$sp,$sp,-536
/*  f19ab74:	afa40218 */ 	sw	$a0,0x218($sp)
/*  f19ab78:	87ae021a */ 	lh	$t6,0x21a($sp)
/*  f19ab7c:	afb60030 */ 	sw	$s6,0x30($sp)
/*  f19ab80:	afb5002c */ 	sw	$s5,0x2c($sp)
/*  f19ab84:	afb40028 */ 	sw	$s4,0x28($sp)
/*  f19ab88:	240fffff */ 	addiu	$t7,$zero,-1
/*  f19ab8c:	afbf003c */ 	sw	$ra,0x3c($sp)
/*  f19ab90:	afbe0038 */ 	sw	$s8,0x38($sp)
/*  f19ab94:	afb70034 */ 	sw	$s7,0x34($sp)
/*  f19ab98:	afb30024 */ 	sw	$s3,0x24($sp)
/*  f19ab9c:	afb20020 */ 	sw	$s2,0x20($sp)
/*  f19aba0:	afb1001c */ 	sw	$s1,0x1c($sp)
/*  f19aba4:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f19aba8:	afa5021c */ 	sw	$a1,0x21c($sp)
/*  f19abac:	afa60220 */ 	sw	$a2,0x220($sp)
/*  f19abb0:	afa70224 */ 	sw	$a3,0x224($sp)
/*  f19abb4:	0000b025 */ 	or	$s6,$zero,$zero
/*  f19abb8:	0000a825 */ 	or	$s5,$zero,$zero
/*  f19abbc:	afa00050 */ 	sw	$zero,0x50($sp)
/*  f19abc0:	a7af0156 */ 	sh	$t7,0x156($sp)
/*  f19abc4:	0000a025 */ 	or	$s4,$zero,$zero
/*  f19abc8:	a7ae0154 */ 	sh	$t6,0x154($sp)
/*  f19abcc:	afa00054 */ 	sw	$zero,0x54($sp)
.L0f19abd0:
/*  f19abd0:	0fc458b4 */ 	jal	func0f1162d0
/*  f19abd4:	00009025 */ 	or	$s2,$zero,$zero
/*  f19abd8:	1840002f */ 	blez	$v0,.L0f19ac98
/*  f19abdc:	0040f025 */ 	or	$s8,$v0,$zero
/*  f19abe0:	02402025 */ 	or	$a0,$s2,$zero
.L0f19abe4:
/*  f19abe4:	0fc458b8 */ 	jal	func0f1162e0
/*  f19abe8:	27a50158 */ 	addiu	$a1,$sp,0x158
/*  f19abec:	50400027 */ 	beqzl	$v0,.L0f19ac8c
/*  f19abf0:	26520001 */ 	addiu	$s2,$s2,0x1
/*  f19abf4:	0fc4596c */ 	jal	func0f1165b0
/*  f19abf8:	27a40158 */ 	addiu	$a0,$sp,0x158
/*  f19abfc:	14400022 */ 	bnez	$v0,.L0f19ac88
/*  f19ac00:	27a40160 */ 	addiu	$a0,$sp,0x160
/*  f19ac04:	0fc19620 */ 	jal	func0f065880
/*  f19ac08:	27a50154 */ 	addiu	$a1,$sp,0x154
/*  f19ac0c:	1040001e */ 	beqz	$v0,.L0f19ac88
/*  f19ac10:	8fb80050 */ 	lw	$t8,0x50($sp)
/*  f19ac14:	1300000e */ 	beqz	$t8,.L0f19ac50
/*  f19ac18:	97b90164 */ 	lhu	$t9,0x164($sp)
/*  f19ac1c:	33280100 */ 	andi	$t0,$t9,0x100
/*  f19ac20:	1100000b */ 	beqz	$t0,.L0f19ac50
/*  f19ac24:	02402025 */ 	or	$a0,$s2,$zero
/*  f19ac28:	00164880 */ 	sll	$t1,$s6,0x2
/*  f19ac2c:	27aa016c */ 	addiu	$t2,$sp,0x16c
/*  f19ac30:	012a8021 */ 	addu	$s0,$t1,$t2
/*  f19ac34:	0fc4594a */ 	jal	func0f116528
/*  f19ac38:	24050100 */ 	addiu	$a1,$zero,0x100
/*  f19ac3c:	ae120000 */ 	sw	$s2,0x0($s0)
/*  f19ac40:	26d60001 */ 	addiu	$s6,$s6,0x1
/*  f19ac44:	26100004 */ 	addiu	$s0,$s0,0x4
/*  f19ac48:	1000000c */ 	beqz	$zero,.L0f19ac7c
/*  f19ac4c:	26940001 */ 	addiu	$s4,$s4,0x1
.L0f19ac50:
/*  f19ac50:	97ab0164 */ 	lhu	$t3,0x164($sp)
/*  f19ac54:	316c0100 */ 	andi	$t4,$t3,0x100
/*  f19ac58:	15800006 */ 	bnez	$t4,.L0f19ac74
/*  f19ac5c:	00166880 */ 	sll	$t5,$s6,0x2
/*  f19ac60:	03ad7021 */ 	addu	$t6,$sp,$t5
/*  f19ac64:	add2016c */ 	sw	$s2,0x16c($t6)
/*  f19ac68:	26d60001 */ 	addiu	$s6,$s6,0x1
/*  f19ac6c:	10000003 */ 	beqz	$zero,.L0f19ac7c
/*  f19ac70:	26940001 */ 	addiu	$s4,$s4,0x1
.L0f19ac74:
/*  f19ac74:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f19ac78:	afaf0054 */ 	sw	$t7,0x54($sp)
.L0f19ac7c:
/*  f19ac7c:	2ac10028 */ 	slti	$at,$s6,0x28
/*  f19ac80:	10200005 */ 	beqz	$at,.L0f19ac98
/*  f19ac84:	00000000 */ 	sll	$zero,$zero,0x0
.L0f19ac88:
/*  f19ac88:	26520001 */ 	addiu	$s2,$s2,0x1
.L0f19ac8c:
/*  f19ac8c:	025e082a */ 	slt	$at,$s2,$s8
/*  f19ac90:	5420ffd4 */ 	bnezl	$at,.L0f19abe4
/*  f19ac94:	02402025 */ 	or	$a0,$s2,$zero
.L0f19ac98:
/*  f19ac98:	3c18800a */ 	lui	$t8,0x800a
/*  f19ac9c:	8f18d030 */ 	lw	$t8,-0x2fd0($t8)
/*  f19aca0:	53000047 */ 	beqzl	$t8,.L0f19adc0
/*  f19aca4:	8fac0054 */ 	lw	$t4,0x54($sp)
/*  f19aca8:	87b7021a */ 	lh	$s7,0x21a($sp)
/*  f19acac:	3c08800a */ 	lui	$t0,0x800a
/*  f19acb0:	8d084928 */ 	lw	$t0,0x4928($t0)
/*  f19acb4:	0017c8c0 */ 	sll	$t9,$s7,0x3
/*  f19acb8:	0337c821 */ 	addu	$t9,$t9,$s7
/*  f19acbc:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f19acc0:	0337c823 */ 	subu	$t9,$t9,$s7
/*  f19acc4:	0019b880 */ 	sll	$s7,$t9,0x2
/*  f19acc8:	01174821 */ 	addu	$t1,$t0,$s7
/*  f19accc:	913e0009 */ 	lbu	$s8,0x9($t1)
/*  f19acd0:	00009025 */ 	or	$s2,$zero,$zero
/*  f19acd4:	5bc0003a */ 	blezl	$s8,.L0f19adc0
/*  f19acd8:	8fac0054 */ 	lw	$t4,0x54($sp)
/*  f19acdc:	00009825 */ 	or	$s3,$zero,$zero
.L0f19ace0:
/*  f19ace0:	3c0b800a */ 	lui	$t3,0x800a
/*  f19ace4:	8d6b4928 */ 	lw	$t3,0x4928($t3)
/*  f19ace8:	3c0a800a */ 	lui	$t2,0x800a
/*  f19acec:	8d4aa020 */ 	lw	$t2,-0x5fe0($t2)
/*  f19acf0:	01776021 */ 	addu	$t4,$t3,$s7
/*  f19acf4:	958d000c */ 	lhu	$t5,0xc($t4)
/*  f19acf8:	3c08800a */ 	lui	$t0,0x800a
/*  f19acfc:	8d08d030 */ 	lw	$t0,-0x2fd0($t0)
/*  f19ad00:	000d7040 */ 	sll	$t6,$t5,0x1
/*  f19ad04:	014e7821 */ 	addu	$t7,$t2,$t6
/*  f19ad08:	01f3c021 */ 	addu	$t8,$t7,$s3
/*  f19ad0c:	87020000 */ 	lh	$v0,0x0($t8)
/*  f19ad10:	24050080 */ 	addiu	$a1,$zero,0x80
/*  f19ad14:	27a60058 */ 	addiu	$a2,$sp,0x58
/*  f19ad18:	0002c900 */ 	sll	$t9,$v0,0x4
/*  f19ad1c:	03288821 */ 	addu	$s1,$t9,$t0
/*  f19ad20:	0fc456ac */ 	jal	padUnpack
/*  f19ad24:	8e240000 */ 	lw	$a0,0x0($s1)
/*  f19ad28:	8fa90050 */ 	lw	$t1,0x50($sp)
/*  f19ad2c:	51200011 */ 	beqzl	$t1,.L0f19ad74
/*  f19ad30:	8faf00a4 */ 	lw	$t7,0xa4($sp)
/*  f19ad34:	8fab00a4 */ 	lw	$t3,0xa4($sp)
/*  f19ad38:	3c050002 */ 	lui	$a1,0x2
/*  f19ad3c:	00156880 */ 	sll	$t5,$s5,0x2
/*  f19ad40:	000b6380 */ 	sll	$t4,$t3,0xe
/*  f19ad44:	0581000a */ 	bgez	$t4,.L0f19ad70
/*  f19ad48:	27aa00b4 */ 	addiu	$t2,$sp,0xb4
/*  f19ad4c:	8e240000 */ 	lw	$a0,0x0($s1)
/*  f19ad50:	0fc458a0 */ 	jal	func0f116280
/*  f19ad54:	01aa8021 */ 	addu	$s0,$t5,$t2
/*  f19ad58:	8e2e0000 */ 	lw	$t6,0x0($s1)
/*  f19ad5c:	26b50001 */ 	addiu	$s5,$s5,0x1
/*  f19ad60:	26100004 */ 	addiu	$s0,$s0,0x4
/*  f19ad64:	26940001 */ 	addiu	$s4,$s4,0x1
/*  f19ad68:	1000000e */ 	beqz	$zero,.L0f19ada4
/*  f19ad6c:	ae0efffc */ 	sw	$t6,-0x4($s0)
.L0f19ad70:
/*  f19ad70:	8faf00a4 */ 	lw	$t7,0xa4($sp)
.L0f19ad74:
/*  f19ad74:	000fc380 */ 	sll	$t8,$t7,0xe
/*  f19ad78:	07020009 */ 	bltzl	$t8,.L0f19ada0
/*  f19ad7c:	240b0001 */ 	addiu	$t3,$zero,0x1
/*  f19ad80:	8e390000 */ 	lw	$t9,0x0($s1)
/*  f19ad84:	00154080 */ 	sll	$t0,$s5,0x2
/*  f19ad88:	03a84821 */ 	addu	$t1,$sp,$t0
/*  f19ad8c:	26b50001 */ 	addiu	$s5,$s5,0x1
/*  f19ad90:	26940001 */ 	addiu	$s4,$s4,0x1
/*  f19ad94:	10000003 */ 	beqz	$zero,.L0f19ada4
/*  f19ad98:	ad3900b4 */ 	sw	$t9,0xb4($t1)
/*  f19ad9c:	240b0001 */ 	addiu	$t3,$zero,0x1
.L0f19ada0:
/*  f19ada0:	afab0054 */ 	sw	$t3,0x54($sp)
.L0f19ada4:
/*  f19ada4:	2aa10028 */ 	slti	$at,$s5,0x28
/*  f19ada8:	50200005 */ 	beqzl	$at,.L0f19adc0
/*  f19adac:	8fac0054 */ 	lw	$t4,0x54($sp)
/*  f19adb0:	26520001 */ 	addiu	$s2,$s2,0x1
/*  f19adb4:	165effca */ 	bne	$s2,$s8,.L0f19ace0
/*  f19adb8:	26730002 */ 	addiu	$s3,$s3,0x2
/*  f19adbc:	8fac0054 */ 	lw	$t4,0x54($sp)
.L0f19adc0:
/*  f19adc0:	11800003 */ 	beqz	$t4,.L0f19add0
/*  f19adc4:	afac0050 */ 	sw	$t4,0x50($sp)
/*  f19adc8:	5280ff81 */ 	beqzl	$s4,.L0f19abd0
/*  f19adcc:	afa00054 */ 	sw	$zero,0x54($sp)
.L0f19add0:
/*  f19add0:	16800003 */ 	bnez	$s4,.L0f19ade0
/*  f19add4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f19add8:	10000041 */ 	beqz	$zero,.L0f19aee0
/*  f19addc:	00001025 */ 	or	$v0,$zero,$zero
.L0f19ade0:
/*  f19ade0:	0c004b70 */ 	jal	random
/*  f19ade4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f19ade8:	0054001b */ 	divu	$zero,$v0,$s4
/*  f19adec:	00001810 */ 	mfhi	$v1
/*  f19adf0:	0076082a */ 	slt	$at,$v1,$s6
/*  f19adf4:	16800002 */ 	bnez	$s4,.L0f19ae00
/*  f19adf8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f19adfc:	0007000d */ 	break	0x7
.L0f19ae00:
/*  f19ae00:	00609025 */ 	or	$s2,$v1,$zero
/*  f19ae04:	1020001b */ 	beqz	$at,.L0f19ae74
/*  f19ae08:	00036880 */ 	sll	$t5,$v1,0x2
/*  f19ae0c:	27aa016c */ 	addiu	$t2,$sp,0x16c
/*  f19ae10:	01aa8021 */ 	addu	$s0,$t5,$t2
/*  f19ae14:	8e040000 */ 	lw	$a0,0x0($s0)
/*  f19ae18:	0fc458b8 */ 	jal	func0f1162e0
/*  f19ae1c:	27a50158 */ 	addiu	$a1,$sp,0x158
/*  f19ae20:	8fae0158 */ 	lw	$t6,0x158($sp)
/*  f19ae24:	8faf021c */ 	lw	$t7,0x21c($sp)
/*  f19ae28:	c5c40000 */ 	lwc1	$f4,0x0($t6)
/*  f19ae2c:	e5e40000 */ 	swc1	$f4,0x0($t7)
/*  f19ae30:	c5c60004 */ 	lwc1	$f6,0x4($t6)
/*  f19ae34:	e5e60004 */ 	swc1	$f6,0x4($t7)
/*  f19ae38:	c5c80008 */ 	lwc1	$f8,0x8($t6)
/*  f19ae3c:	e5e80008 */ 	swc1	$f8,0x8($t7)
/*  f19ae40:	8fb8015c */ 	lw	$t8,0x15c($sp)
/*  f19ae44:	c70c0008 */ 	lwc1	$f12,0x8($t8)
/*  f19ae48:	0fc259d4 */ 	jal	func0f096750
/*  f19ae4c:	c70e0000 */ 	lwc1	$f14,0x0($t8)
/*  f19ae50:	8fb90220 */ 	lw	$t9,0x220($sp)
/*  f19ae54:	2408ffff */ 	addiu	$t0,$zero,-1
/*  f19ae58:	e7200000 */ 	swc1	$f0,0x0($t9)
/*  f19ae5c:	8fa90224 */ 	lw	$t1,0x224($sp)
/*  f19ae60:	ad280000 */ 	sw	$t0,0x0($t1)
/*  f19ae64:	8fac0228 */ 	lw	$t4,0x228($sp)
/*  f19ae68:	8e0b0000 */ 	lw	$t3,0x0($s0)
/*  f19ae6c:	1000001b */ 	beqz	$zero,.L0f19aedc
/*  f19ae70:	ad8b0000 */ 	sw	$t3,0x0($t4)
.L0f19ae74:
/*  f19ae74:	02569023 */ 	subu	$s2,$s2,$s6
/*  f19ae78:	00126880 */ 	sll	$t5,$s2,0x2
/*  f19ae7c:	27aa00b4 */ 	addiu	$t2,$sp,0xb4
/*  f19ae80:	01aa8021 */ 	addu	$s0,$t5,$t2
/*  f19ae84:	8e040000 */ 	lw	$a0,0x0($s0)
/*  f19ae88:	24050006 */ 	addiu	$a1,$zero,0x6
/*  f19ae8c:	0fc456ac */ 	jal	padUnpack
/*  f19ae90:	27a60058 */ 	addiu	$a2,$sp,0x58
/*  f19ae94:	c7aa0058 */ 	lwc1	$f10,0x58($sp)
/*  f19ae98:	8fae021c */ 	lw	$t6,0x21c($sp)
/*  f19ae9c:	e5ca0000 */ 	swc1	$f10,0x0($t6)
/*  f19aea0:	c7b0005c */ 	lwc1	$f16,0x5c($sp)
/*  f19aea4:	e5d00004 */ 	swc1	$f16,0x4($t6)
/*  f19aea8:	c7b20060 */ 	lwc1	$f18,0x60($sp)
/*  f19aeac:	e5d20008 */ 	swc1	$f18,0x8($t6)
/*  f19aeb0:	c7ae0064 */ 	lwc1	$f14,0x64($sp)
/*  f19aeb4:	0fc259d4 */ 	jal	func0f096750
/*  f19aeb8:	c7ac006c */ 	lwc1	$f12,0x6c($sp)
/*  f19aebc:	8faf0220 */ 	lw	$t7,0x220($sp)
/*  f19aec0:	2408ffff */ 	addiu	$t0,$zero,-1
/*  f19aec4:	e5e00000 */ 	swc1	$f0,0x0($t7)
/*  f19aec8:	8fb90224 */ 	lw	$t9,0x224($sp)
/*  f19aecc:	8e180000 */ 	lw	$t8,0x0($s0)
/*  f19aed0:	af380000 */ 	sw	$t8,0x0($t9)
/*  f19aed4:	8fa90228 */ 	lw	$t1,0x228($sp)
/*  f19aed8:	ad280000 */ 	sw	$t0,0x0($t1)
.L0f19aedc:
/*  f19aedc:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f19aee0:
/*  f19aee0:	8fbf003c */ 	lw	$ra,0x3c($sp)
/*  f19aee4:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f19aee8:	8fb1001c */ 	lw	$s1,0x1c($sp)
/*  f19aeec:	8fb20020 */ 	lw	$s2,0x20($sp)
/*  f19aef0:	8fb30024 */ 	lw	$s3,0x24($sp)
/*  f19aef4:	8fb40028 */ 	lw	$s4,0x28($sp)
/*  f19aef8:	8fb5002c */ 	lw	$s5,0x2c($sp)
/*  f19aefc:	8fb60030 */ 	lw	$s6,0x30($sp)
/*  f19af00:	8fb70034 */ 	lw	$s7,0x34($sp)
/*  f19af04:	8fbe0038 */ 	lw	$s8,0x38($sp)
/*  f19af08:	03e00008 */ 	jr	$ra
/*  f19af0c:	27bd0218 */ 	addiu	$sp,$sp,0x218
/*  f19af10:	00047080 */ 	sll	$t6,$a0,0x2
/*  f19af14:	01c47023 */ 	subu	$t6,$t6,$a0
/*  f19af18:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f19af1c:	01c47021 */ 	addu	$t6,$t6,$a0
/*  f19af20:	000e7040 */ 	sll	$t6,$t6,0x1
/*  f19af24:	3c028009 */ 	lui	$v0,0x8009
/*  f19af28:	004e1021 */ 	addu	$v0,$v0,$t6
/*  f19af2c:	904284bc */ 	lbu	$v0,-0x7b44($v0)
/*  f19af30:	304f0001 */ 	andi	$t7,$v0,0x1
/*  f19af34:	03e00008 */ 	jr	$ra
/*  f19af38:	000f102b */ 	sltu	$v0,$zero,$t7
);

bool func0f19af3c(s32 chrnum, s32 challengeindex)
{
	if ((g_MpSetup.chrslots & (1 << chrnum)) == 0) {
		return 0;
	}

	return ((g_MpChallenges[challengeindex].completions[0] & (2 << chrnum)) != 0);
}

bool mpIsChallengeAvailable(s32 challengeindex)
{
	return (g_MpChallenges[challengeindex].completions[0] & (((g_MpSetup.chrslots & 0xf) << 1) | 1)) != 0;
}

GLOBAL_ASM(
glabel func0f19afdc
/*  f19afdc:	27bdffc8 */ 	addiu	$sp,$sp,-56
/*  f19afe0:	afb1001c */ 	sw	$s1,0x1c($sp)
/*  f19afe4:	3c118009 */ 	lui	$s1,%hi(g_MpChallenges)
/*  f19afe8:	3c028009 */ 	lui	$v0,%hi(var800887c4)
/*  f19afec:	afbf0034 */ 	sw	$ra,0x34($sp)
/*  f19aff0:	afb60030 */ 	sw	$s6,0x30($sp)
/*  f19aff4:	afb5002c */ 	sw	$s5,0x2c($sp)
/*  f19aff8:	afb40028 */ 	sw	$s4,0x28($sp)
/*  f19affc:	afb30024 */ 	sw	$s3,0x24($sp)
/*  f19b000:	afb20020 */ 	sw	$s2,0x20($sp)
/*  f19b004:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f19b008:	244287c4 */ 	addiu	$v0,$v0,%lo(var800887c4)
/*  f19b00c:	263184b8 */ 	addiu	$s1,$s1,%lo(g_MpChallenges)
.L0f19b010:
/*  f19b010:	2631001a */ 	addiu	$s1,$s1,0x1a
/*  f19b014:	0222082b */ 	sltu	$at,$s1,$v0
/*  f19b018:	1420fffd */ 	bnez	$at,.L0f19b010
/*  f19b01c:	a220ffea */ 	sb	$zero,-0x16($s1)
/*  f19b020:	3c118009 */ 	lui	$s1,%hi(g_MpChallenges)
/*  f19b024:	0000a025 */ 	or	$s4,$zero,$zero
/*  f19b028:	263184b8 */ 	addiu	$s1,$s1,%lo(g_MpChallenges)
/*  f19b02c:	0000a825 */ 	or	$s5,$zero,$zero
.L0f19b030:
/*  f19b030:	00009025 */ 	or	$s2,$zero,$zero
/*  f19b034:	02a02025 */ 	or	$a0,$s5,$zero
/*  f19b038:	0fc670f7 */ 	jal	mpIsChallengeCompletedByAnyChrWithNumPlayers
/*  f19b03c:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f19b040:	1440000d */ 	bnez	$v0,.L0f19b078
/*  f19b044:	02a02025 */ 	or	$a0,$s5,$zero
/*  f19b048:	0fc670f7 */ 	jal	mpIsChallengeCompletedByAnyChrWithNumPlayers
/*  f19b04c:	24050002 */ 	addiu	$a1,$zero,0x2
/*  f19b050:	14400009 */ 	bnez	$v0,.L0f19b078
/*  f19b054:	02a02025 */ 	or	$a0,$s5,$zero
/*  f19b058:	0fc670f7 */ 	jal	mpIsChallengeCompletedByAnyChrWithNumPlayers
/*  f19b05c:	24050003 */ 	addiu	$a1,$zero,0x3
/*  f19b060:	14400005 */ 	bnez	$v0,.L0f19b078
/*  f19b064:	02a02025 */ 	or	$a0,$s5,$zero
/*  f19b068:	0fc670f7 */ 	jal	mpIsChallengeCompletedByAnyChrWithNumPlayers
/*  f19b06c:	24050004 */ 	addiu	$a1,$zero,0x4
/*  f19b070:	10400003 */ 	beqz	$v0,.L0f19b080
/*  f19b074:	2aa10004 */ 	slti	$at,$s5,0x4
.L0f19b078:
/*  f19b078:	1000001b */ 	beqz	$zero,.L0f19b0e8
/*  f19b07c:	24120001 */ 	addiu	$s2,$zero,0x1
.L0f19b080:
/*  f19b080:	10200004 */ 	beqz	$at,.L0f19b094
/*  f19b084:	00000000 */ 	sll	$zero,$zero,0x0
/*  f19b088:	24120001 */ 	addiu	$s2,$zero,0x1
/*  f19b08c:	10000016 */ 	beqz	$zero,.L0f19b0e8
/*  f19b090:	26940001 */ 	addiu	$s4,$s4,0x1
.L0f19b094:
/*  f19b094:	1aa00014 */ 	blez	$s5,.L0f19b0e8
/*  f19b098:	26b0ffff */ 	addiu	$s0,$s5,-1
/*  f19b09c:	02002025 */ 	or	$a0,$s0,$zero
/*  f19b0a0:	0fc670f7 */ 	jal	mpIsChallengeCompletedByAnyChrWithNumPlayers
/*  f19b0a4:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f19b0a8:	1440000d */ 	bnez	$v0,.L0f19b0e0
/*  f19b0ac:	02002025 */ 	or	$a0,$s0,$zero
/*  f19b0b0:	0fc670f7 */ 	jal	mpIsChallengeCompletedByAnyChrWithNumPlayers
/*  f19b0b4:	24050002 */ 	addiu	$a1,$zero,0x2
/*  f19b0b8:	14400009 */ 	bnez	$v0,.L0f19b0e0
/*  f19b0bc:	02002025 */ 	or	$a0,$s0,$zero
/*  f19b0c0:	0fc670f7 */ 	jal	mpIsChallengeCompletedByAnyChrWithNumPlayers
/*  f19b0c4:	24050003 */ 	addiu	$a1,$zero,0x3
/*  f19b0c8:	14400005 */ 	bnez	$v0,.L0f19b0e0
/*  f19b0cc:	02002025 */ 	or	$a0,$s0,$zero
/*  f19b0d0:	0fc670f7 */ 	jal	mpIsChallengeCompletedByAnyChrWithNumPlayers
/*  f19b0d4:	24050004 */ 	addiu	$a1,$zero,0x4
/*  f19b0d8:	50400004 */ 	beqzl	$v0,.L0f19b0ec
/*  f19b0dc:	922e0004 */ 	lbu	$t6,0x4($s1)
.L0f19b0e0:
/*  f19b0e0:	24120001 */ 	addiu	$s2,$zero,0x1
/*  f19b0e4:	26940001 */ 	addiu	$s4,$s4,0x1
.L0f19b0e8:
/*  f19b0e8:	922e0004 */ 	lbu	$t6,0x4($s1)
.L0f19b0ec:
/*  f19b0ec:	26b50001 */ 	addiu	$s5,$s5,0x1
/*  f19b0f0:	2aa1001e */ 	slti	$at,$s5,0x1e
/*  f19b0f4:	01d27825 */ 	or	$t7,$t6,$s2
/*  f19b0f8:	2631001a */ 	addiu	$s1,$s1,0x1a
/*  f19b0fc:	1420ffcc */ 	bnez	$at,.L0f19b030
/*  f19b100:	a22fffea */ 	sb	$t7,-0x16($s1)
/*  f19b104:	2a810004 */ 	slti	$at,$s4,0x4
/*  f19b108:	10200014 */ 	beqz	$at,.L0f19b15c
/*  f19b10c:	00009825 */ 	or	$s3,$zero,$zero
/*  f19b110:	0000c080 */ 	sll	$t8,$zero,0x2
/*  f19b114:	0300c023 */ 	subu	$t8,$t8,$zero
/*  f19b118:	3c198009 */ 	lui	$t9,%hi(g_MpChallenges)
/*  f19b11c:	273984b8 */ 	addiu	$t9,$t9,%lo(g_MpChallenges)
/*  f19b120:	0018c0c0 */ 	sll	$t8,$t8,0x3
/*  f19b124:	3c038009 */ 	lui	$v1,%hi(var800887c4)
/*  f19b128:	246387c4 */ 	addiu	$v1,$v1,%lo(var800887c4)
/*  f19b12c:	03198821 */ 	addu	$s1,$t8,$t9
/*  f19b130:	92220004 */ 	lbu	$v0,0x4($s1)
.L0f19b134:
/*  f19b134:	30480001 */ 	andi	$t0,$v0,0x1
/*  f19b138:	15000003 */ 	bnez	$t0,.L0f19b148
/*  f19b13c:	34490001 */ 	ori	$t1,$v0,0x1
/*  f19b140:	a2290004 */ 	sb	$t1,0x4($s1)
/*  f19b144:	26940001 */ 	addiu	$s4,$s4,0x1
.L0f19b148:
/*  f19b148:	2a810004 */ 	slti	$at,$s4,0x4
/*  f19b14c:	10200003 */ 	beqz	$at,.L0f19b15c
/*  f19b150:	2631001a */ 	addiu	$s1,$s1,0x1a
/*  f19b154:	5623fff7 */ 	bnel	$s1,$v1,.L0f19b134
/*  f19b158:	92220004 */ 	lbu	$v0,0x4($s1)
.L0f19b15c:
/*  f19b15c:	3c168009 */ 	lui	$s6,%hi(var800887c4)
/*  f19b160:	26d687c4 */ 	addiu	$s6,$s6,%lo(var800887c4)
.L0f19b164:
/*  f19b164:	3c118009 */ 	lui	$s1,%hi(g_MpChallenges)
/*  f19b168:	0000a025 */ 	or	$s4,$zero,$zero
/*  f19b16c:	263184b8 */ 	addiu	$s1,$s1,%lo(g_MpChallenges)
/*  f19b170:	0000a825 */ 	or	$s5,$zero,$zero
.L0f19b174:
/*  f19b174:	00009025 */ 	or	$s2,$zero,$zero
/*  f19b178:	02602025 */ 	or	$a0,$s3,$zero
/*  f19b17c:	02a02825 */ 	or	$a1,$s5,$zero
/*  f19b180:	0fc6711f */ 	jal	mpIsChallengeCompletedByChrWithNumPlayers
/*  f19b184:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f19b188:	14400010 */ 	bnez	$v0,.L0f19b1cc
/*  f19b18c:	02602025 */ 	or	$a0,$s3,$zero
/*  f19b190:	02a02825 */ 	or	$a1,$s5,$zero
/*  f19b194:	0fc6711f */ 	jal	mpIsChallengeCompletedByChrWithNumPlayers
/*  f19b198:	24060002 */ 	addiu	$a2,$zero,0x2
/*  f19b19c:	1440000b */ 	bnez	$v0,.L0f19b1cc
/*  f19b1a0:	02602025 */ 	or	$a0,$s3,$zero
/*  f19b1a4:	02a02825 */ 	or	$a1,$s5,$zero
/*  f19b1a8:	0fc6711f */ 	jal	mpIsChallengeCompletedByChrWithNumPlayers
/*  f19b1ac:	24060003 */ 	addiu	$a2,$zero,0x3
/*  f19b1b0:	14400006 */ 	bnez	$v0,.L0f19b1cc
/*  f19b1b4:	02602025 */ 	or	$a0,$s3,$zero
/*  f19b1b8:	02a02825 */ 	or	$a1,$s5,$zero
/*  f19b1bc:	0fc6711f */ 	jal	mpIsChallengeCompletedByChrWithNumPlayers
/*  f19b1c0:	24060004 */ 	addiu	$a2,$zero,0x4
/*  f19b1c4:	10400006 */ 	beqz	$v0,.L0f19b1e0
/*  f19b1c8:	2aa10004 */ 	slti	$at,$s5,0x4
.L0f19b1cc:
/*  f19b1cc:	240a0002 */ 	addiu	$t2,$zero,0x2
/*  f19b1d0:	026a9004 */ 	sllv	$s2,$t2,$s3
/*  f19b1d4:	324b00ff */ 	andi	$t3,$s2,0xff
/*  f19b1d8:	10000023 */ 	beqz	$zero,.L0f19b268
/*  f19b1dc:	01609025 */ 	or	$s2,$t3,$zero
.L0f19b1e0:
/*  f19b1e0:	10200006 */ 	beqz	$at,.L0f19b1fc
/*  f19b1e4:	240c0002 */ 	addiu	$t4,$zero,0x2
/*  f19b1e8:	026c9004 */ 	sllv	$s2,$t4,$s3
/*  f19b1ec:	324d00ff */ 	andi	$t5,$s2,0xff
/*  f19b1f0:	01a09025 */ 	or	$s2,$t5,$zero
/*  f19b1f4:	1000001c */ 	beqz	$zero,.L0f19b268
/*  f19b1f8:	26940001 */ 	addiu	$s4,$s4,0x1
.L0f19b1fc:
/*  f19b1fc:	1aa0001a */ 	blez	$s5,.L0f19b268
/*  f19b200:	02602025 */ 	or	$a0,$s3,$zero
/*  f19b204:	26b0ffff */ 	addiu	$s0,$s5,-1
/*  f19b208:	02002825 */ 	or	$a1,$s0,$zero
/*  f19b20c:	0fc6711f */ 	jal	mpIsChallengeCompletedByChrWithNumPlayers
/*  f19b210:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f19b214:	1440000f */ 	bnez	$v0,.L0f19b254
/*  f19b218:	02602025 */ 	or	$a0,$s3,$zero
/*  f19b21c:	02002825 */ 	or	$a1,$s0,$zero
/*  f19b220:	0fc6711f */ 	jal	mpIsChallengeCompletedByChrWithNumPlayers
/*  f19b224:	24060002 */ 	addiu	$a2,$zero,0x2
/*  f19b228:	1440000a */ 	bnez	$v0,.L0f19b254
/*  f19b22c:	02602025 */ 	or	$a0,$s3,$zero
/*  f19b230:	02002825 */ 	or	$a1,$s0,$zero
/*  f19b234:	0fc6711f */ 	jal	mpIsChallengeCompletedByChrWithNumPlayers
/*  f19b238:	24060003 */ 	addiu	$a2,$zero,0x3
/*  f19b23c:	14400005 */ 	bnez	$v0,.L0f19b254
/*  f19b240:	02602025 */ 	or	$a0,$s3,$zero
/*  f19b244:	02002825 */ 	or	$a1,$s0,$zero
/*  f19b248:	0fc6711f */ 	jal	mpIsChallengeCompletedByChrWithNumPlayers
/*  f19b24c:	24060004 */ 	addiu	$a2,$zero,0x4
/*  f19b250:	10400005 */ 	beqz	$v0,.L0f19b268
.L0f19b254:
/*  f19b254:	240e0002 */ 	addiu	$t6,$zero,0x2
/*  f19b258:	026e9004 */ 	sllv	$s2,$t6,$s3
/*  f19b25c:	324f00ff */ 	andi	$t7,$s2,0xff
/*  f19b260:	01e09025 */ 	or	$s2,$t7,$zero
/*  f19b264:	26940001 */ 	addiu	$s4,$s4,0x1
.L0f19b268:
/*  f19b268:	92380004 */ 	lbu	$t8,0x4($s1)
/*  f19b26c:	26b50001 */ 	addiu	$s5,$s5,0x1
/*  f19b270:	2aa1001e */ 	slti	$at,$s5,0x1e
/*  f19b274:	0312c825 */ 	or	$t9,$t8,$s2
/*  f19b278:	2631001a */ 	addiu	$s1,$s1,0x1a
/*  f19b27c:	1420ffbd */ 	bnez	$at,.L0f19b174
/*  f19b280:	a239ffea */ 	sb	$t9,-0x16($s1)
/*  f19b284:	2a810004 */ 	slti	$at,$s4,0x4
/*  f19b288:	10200013 */ 	beqz	$at,.L0f19b2d8
/*  f19b28c:	00004080 */ 	sll	$t0,$zero,0x2
/*  f19b290:	01004023 */ 	subu	$t0,$t0,$zero
/*  f19b294:	3c098009 */ 	lui	$t1,%hi(g_MpChallenges)
/*  f19b298:	252984b8 */ 	addiu	$t1,$t1,%lo(g_MpChallenges)
/*  f19b29c:	000840c0 */ 	sll	$t0,$t0,0x3
/*  f19b2a0:	240a0002 */ 	addiu	$t2,$zero,0x2
/*  f19b2a4:	026a1804 */ 	sllv	$v1,$t2,$s3
/*  f19b2a8:	01098821 */ 	addu	$s1,$t0,$t1
/*  f19b2ac:	92220004 */ 	lbu	$v0,0x4($s1)
.L0f19b2b0:
/*  f19b2b0:	00435824 */ 	and	$t3,$v0,$v1
/*  f19b2b4:	15600003 */ 	bnez	$t3,.L0f19b2c4
/*  f19b2b8:	00436025 */ 	or	$t4,$v0,$v1
/*  f19b2bc:	a22c0004 */ 	sb	$t4,0x4($s1)
/*  f19b2c0:	26940001 */ 	addiu	$s4,$s4,0x1
.L0f19b2c4:
/*  f19b2c4:	2a810004 */ 	slti	$at,$s4,0x4
/*  f19b2c8:	10200003 */ 	beqz	$at,.L0f19b2d8
/*  f19b2cc:	2631001a */ 	addiu	$s1,$s1,0x1a
/*  f19b2d0:	5636fff7 */ 	bnel	$s1,$s6,.L0f19b2b0
/*  f19b2d4:	92220004 */ 	lbu	$v0,0x4($s1)
.L0f19b2d8:
/*  f19b2d8:	26730001 */ 	addiu	$s3,$s3,0x1
/*  f19b2dc:	2a610004 */ 	slti	$at,$s3,0x4
/*  f19b2e0:	1420ffa0 */ 	bnez	$at,.L0f19b164
/*  f19b2e4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f19b2e8:	3c14800b */ 	lui	$s4,%hi(g_MpChallengesCompleted)
/*  f19b2ec:	3c16800b */ 	lui	$s6,%hi(g_MpChallengesCompleted)
/*  f19b2f0:	26d6ccc8 */ 	addiu	$s6,$s6,%lo(g_MpChallengesCompleted)
/*  f19b2f4:	2694ccc8 */ 	addiu	$s4,$s4,%lo(g_MpChallengesCompleted)
/*  f19b2f8:	00009825 */ 	or	$s3,$zero,$zero
/*  f19b2fc:	24110010 */ 	addiu	$s1,$zero,0x10
.L0f19b300:
/*  f19b300:	00009025 */ 	or	$s2,$zero,$zero
/*  f19b304:	0000a825 */ 	or	$s5,$zero,$zero
.L0f19b308:
/*  f19b308:	0fc66be6 */ 	jal	mpIsChallengeAvailable
/*  f19b30c:	02a02025 */ 	or	$a0,$s5,$zero
/*  f19b310:	10400011 */ 	beqz	$v0,.L0f19b358
/*  f19b314:	00156880 */ 	sll	$t5,$s5,0x2
/*  f19b318:	01b56823 */ 	subu	$t5,$t5,$s5
/*  f19b31c:	000d6880 */ 	sll	$t5,$t5,0x2
/*  f19b320:	01b56821 */ 	addu	$t5,$t5,$s5
/*  f19b324:	3c0e8009 */ 	lui	$t6,%hi(g_MpChallenges)
/*  f19b328:	25ce84b8 */ 	addiu	$t6,$t6,%lo(g_MpChallenges)
/*  f19b32c:	000d6840 */ 	sll	$t5,$t5,0x1
/*  f19b330:	01ae1821 */ 	addu	$v1,$t5,$t6
/*  f19b334:	00001025 */ 	or	$v0,$zero,$zero
.L0f19b338:
/*  f19b338:	906f0009 */ 	lbu	$t7,0x9($v1)
/*  f19b33c:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f19b340:	36580001 */ 	ori	$t8,$s2,0x1
/*  f19b344:	166f0002 */ 	bne	$s3,$t7,.L0f19b350
/*  f19b348:	00000000 */ 	sll	$zero,$zero,0x0
/*  f19b34c:	331200ff */ 	andi	$s2,$t8,0xff
.L0f19b350:
/*  f19b350:	1451fff9 */ 	bne	$v0,$s1,.L0f19b338
/*  f19b354:	24630001 */ 	addiu	$v1,$v1,0x1
.L0f19b358:
/*  f19b358:	26b50001 */ 	addiu	$s5,$s5,0x1
/*  f19b35c:	2aa1001e */ 	slti	$at,$s5,0x1e
/*  f19b360:	1420ffe9 */ 	bnez	$at,.L0f19b308
/*  f19b364:	00000000 */ 	sll	$zero,$zero,0x0
/*  f19b368:	3c03800b */ 	lui	$v1,%hi(var800acca0)
/*  f19b36c:	2463cca0 */ 	addiu	$v1,$v1,%lo(var800acca0)
/*  f19b370:	90680000 */ 	lbu	$t0,0x0($v1)
.L0f19b374:
/*  f19b374:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f19b378:	36490001 */ 	ori	$t1,$s2,0x1
/*  f19b37c:	16680002 */ 	bne	$s3,$t0,.L0f19b388
/*  f19b380:	00000000 */ 	sll	$zero,$zero,0x0
/*  f19b384:	313200ff */ 	andi	$s2,$t1,0xff
.L0f19b388:
/*  f19b388:	5476fffa */ 	bnel	$v1,$s6,.L0f19b374
/*  f19b38c:	90680000 */ 	lbu	$t0,0x0($v1)
/*  f19b390:	0000a825 */ 	or	$s5,$zero,$zero
/*  f19b394:	00008025 */ 	or	$s0,$zero,$zero
.L0f19b398:
/*  f19b398:	02002025 */ 	or	$a0,$s0,$zero
.L0f19b39c:
/*  f19b39c:	0fc66bcf */ 	jal	func0f19af3c
/*  f19b3a0:	02a02825 */ 	or	$a1,$s5,$zero
/*  f19b3a4:	10400013 */ 	beqz	$v0,.L0f19b3f4
/*  f19b3a8:	00155880 */ 	sll	$t3,$s5,0x2
/*  f19b3ac:	01755823 */ 	subu	$t3,$t3,$s5
/*  f19b3b0:	000b5880 */ 	sll	$t3,$t3,0x2
/*  f19b3b4:	01755821 */ 	addu	$t3,$t3,$s5
/*  f19b3b8:	3c0c8009 */ 	lui	$t4,%hi(g_MpChallenges)
/*  f19b3bc:	258c84b8 */ 	addiu	$t4,$t4,%lo(g_MpChallenges)
/*  f19b3c0:	000b5840 */ 	sll	$t3,$t3,0x1
/*  f19b3c4:	016c1821 */ 	addu	$v1,$t3,$t4
/*  f19b3c8:	00001025 */ 	or	$v0,$zero,$zero
.L0f19b3cc:
/*  f19b3cc:	906d0009 */ 	lbu	$t5,0x9($v1)
/*  f19b3d0:	240e0002 */ 	addiu	$t6,$zero,0x2
/*  f19b3d4:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f19b3d8:	166d0004 */ 	bne	$s3,$t5,.L0f19b3ec
/*  f19b3dc:	020e7804 */ 	sllv	$t7,$t6,$s0
/*  f19b3e0:	024f9025 */ 	or	$s2,$s2,$t7
/*  f19b3e4:	325800ff */ 	andi	$t8,$s2,0xff
/*  f19b3e8:	03009025 */ 	or	$s2,$t8,$zero
.L0f19b3ec:
/*  f19b3ec:	1451fff7 */ 	bne	$v0,$s1,.L0f19b3cc
/*  f19b3f0:	24630001 */ 	addiu	$v1,$v1,0x1
.L0f19b3f4:
/*  f19b3f4:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f19b3f8:	2a010004 */ 	slti	$at,$s0,0x4
/*  f19b3fc:	5420ffe7 */ 	bnezl	$at,.L0f19b39c
/*  f19b400:	02002025 */ 	or	$a0,$s0,$zero
/*  f19b404:	26b50001 */ 	addiu	$s5,$s5,0x1
/*  f19b408:	2aa1001e */ 	slti	$at,$s5,0x1e
/*  f19b40c:	5420ffe2 */ 	bnezl	$at,.L0f19b398
/*  f19b410:	00008025 */ 	or	$s0,$zero,$zero
/*  f19b414:	26730001 */ 	addiu	$s3,$s3,0x1
/*  f19b418:	2a610050 */ 	slti	$at,$s3,0x50
/*  f19b41c:	26940001 */ 	addiu	$s4,$s4,0x1
/*  f19b420:	1420ffb7 */ 	bnez	$at,.L0f19b300
/*  f19b424:	a292ffff */ 	sb	$s2,-0x1($s4)
/*  f19b428:	0fc622f3 */ 	jal	func0f188bcc
/*  f19b42c:	00009825 */ 	or	$s3,$zero,$zero
/*  f19b430:	1840001c */ 	blez	$v0,.L0f19b4a4
/*  f19b434:	0013c880 */ 	sll	$t9,$s3,0x2
/*  f19b438:	0333c821 */ 	addu	$t9,$t9,$s3
/*  f19b43c:	3c088008 */ 	lui	$t0,%hi(mpweaponstable)
/*  f19b440:	25087268 */ 	addiu	$t0,$t0,%lo(mpweaponstable)
/*  f19b444:	0019c840 */ 	sll	$t9,$t9,0x1
/*  f19b448:	3c11800b */ 	lui	$s1,%hi(g_MpChallengesCompleted)
/*  f19b44c:	2631ccc8 */ 	addiu	$s1,$s1,%lo(g_MpChallengesCompleted)
/*  f19b450:	03288021 */ 	addu	$s0,$t9,$t0
/*  f19b454:	96090004 */ 	lhu	$t1,0x4($s0)
.L0f19b458:
/*  f19b458:	312a007f */ 	andi	$t2,$t1,0x7f
/*  f19b45c:	5940000c */ 	blezl	$t2,.L0f19b490
/*  f19b460:	26730001 */ 	addiu	$s3,$s3,0x1
/*  f19b464:	0fc672f3 */ 	jal	func0f19cbcc
/*  f19b468:	92040000 */ 	lbu	$a0,0x0($s0)
/*  f19b46c:	50400008 */ 	beqzl	$v0,.L0f19b490
/*  f19b470:	26730001 */ 	addiu	$s3,$s3,0x1
/*  f19b474:	960b0004 */ 	lhu	$t3,0x4($s0)
/*  f19b478:	316c007f */ 	andi	$t4,$t3,0x7f
/*  f19b47c:	022c1021 */ 	addu	$v0,$s1,$t4
/*  f19b480:	904d0000 */ 	lbu	$t5,0x0($v0)
/*  f19b484:	35ae0001 */ 	ori	$t6,$t5,0x1
/*  f19b488:	a04e0000 */ 	sb	$t6,0x0($v0)
/*  f19b48c:	26730001 */ 	addiu	$s3,$s3,0x1
.L0f19b490:
/*  f19b490:	0fc622f3 */ 	jal	func0f188bcc
/*  f19b494:	2610000a */ 	addiu	$s0,$s0,0xa
/*  f19b498:	0262082a */ 	slt	$at,$s3,$v0
/*  f19b49c:	5420ffee */ 	bnezl	$at,.L0f19b458
/*  f19b4a0:	96090004 */ 	lhu	$t1,0x4($s0)
.L0f19b4a4:
/*  f19b4a4:	0fc6257a */ 	jal	func0f1895e8
/*  f19b4a8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f19b4ac:	0fc67244 */ 	jal	mpIsChallengeComplete
/*  f19b4b0:	24040040 */ 	addiu	$a0,$zero,0x40
/*  f19b4b4:	14400018 */ 	bnez	$v0,.L0f19b518
/*  f19b4b8:	24100004 */ 	addiu	$s0,$zero,0x4
/*  f19b4bc:	3c11800b */ 	lui	$s1,%hi(g_MpSetup)
/*  f19b4c0:	2631cb88 */ 	addiu	$s1,$s1,%lo(g_MpSetup)
/*  f19b4c4:	24120008 */ 	addiu	$s2,$zero,0x8
/*  f19b4c8:	962f0016 */ 	lhu	$t7,0x16($s1)
.L0f19b4cc:
/*  f19b4cc:	26180004 */ 	addiu	$t8,$s0,0x4
/*  f19b4d0:	24190001 */ 	addiu	$t9,$zero,0x1
/*  f19b4d4:	03194004 */ 	sllv	$t0,$t9,$t8
/*  f19b4d8:	01e84824 */ 	and	$t1,$t7,$t0
/*  f19b4dc:	51200004 */ 	beqzl	$t1,.L0f19b4f0
/*  f19b4e0:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f19b4e4:	0fc632ff */ 	jal	mpRemoveSimulant
/*  f19b4e8:	02002025 */ 	or	$a0,$s0,$zero
/*  f19b4ec:	26100001 */ 	addiu	$s0,$s0,0x1
.L0f19b4f0:
/*  f19b4f0:	5612fff6 */ 	bnel	$s0,$s2,.L0f19b4cc
/*  f19b4f4:	962f0016 */ 	lhu	$t7,0x16($s1)
/*  f19b4f8:	3c02800a */ 	lui	$v0,%hi(g_Vars)
/*  f19b4fc:	24429fc0 */ 	addiu	$v0,$v0,%lo(g_Vars)
/*  f19b500:	8c4a04a4 */ 	lw	$t2,0x4a4($v0)
/*  f19b504:	240b0004 */ 	addiu	$t3,$zero,0x4
/*  f19b508:	29410005 */ 	slti	$at,$t2,0x5
/*  f19b50c:	54200003 */ 	bnezl	$at,.L0f19b51c
/*  f19b510:	8fbf0034 */ 	lw	$ra,0x34($sp)
/*  f19b514:	ac4b04a4 */ 	sw	$t3,0x4a4($v0)
.L0f19b518:
/*  f19b518:	8fbf0034 */ 	lw	$ra,0x34($sp)
.L0f19b51c:
/*  f19b51c:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f19b520:	8fb1001c */ 	lw	$s1,0x1c($sp)
/*  f19b524:	8fb20020 */ 	lw	$s2,0x20($sp)
/*  f19b528:	8fb30024 */ 	lw	$s3,0x24($sp)
/*  f19b52c:	8fb40028 */ 	lw	$s4,0x28($sp)
/*  f19b530:	8fb5002c */ 	lw	$s5,0x2c($sp)
/*  f19b534:	8fb60030 */ 	lw	$s6,0x30($sp)
/*  f19b538:	03e00008 */ 	jr	$ra
/*  f19b53c:	27bd0038 */ 	addiu	$sp,$sp,0x38
);

GLOBAL_ASM(
glabel func0f19b540
/*  f19b540:	3c0e800b */ 	lui	$t6,0x800b
/*  f19b544:	91cecc10 */ 	lbu	$t6,-0x33f0($t6)
/*  f19b548:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f19b54c:	24010005 */ 	addiu	$at,$zero,0x5
/*  f19b550:	15c10038 */ 	bne	$t6,$at,.L0f19b634
/*  f19b554:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f19b558:	3c07800b */ 	lui	$a3,0x800b
/*  f19b55c:	3c03800b */ 	lui	$v1,%hi(g_MpPlayers)
/*  f19b560:	00002825 */ 	or	$a1,$zero,$zero
/*  f19b564:	2463c7b8 */ 	addiu	$v1,$v1,%lo(g_MpPlayers)
/*  f19b568:	94e7cb9e */ 	lhu	$a3,-0x3462($a3)
/*  f19b56c:	00001025 */ 	or	$v0,$zero,$zero
/*  f19b570:	24060080 */ 	addiu	$a2,$zero,0x80
/*  f19b574:	240400a0 */ 	addiu	$a0,$zero,0xa0
/*  f19b578:	240f0001 */ 	addiu	$t7,$zero,0x1
.L0f19b57c:
/*  f19b57c:	004fc004 */ 	sllv	$t8,$t7,$v0
/*  f19b580:	00f8c824 */ 	and	$t9,$a3,$t8
/*  f19b584:	53200007 */ 	beqzl	$t9,.L0f19b5a4
/*  f19b588:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f19b58c:	00440019 */ 	multu	$v0,$a0
/*  f19b590:	24a50001 */ 	addiu	$a1,$a1,0x1
/*  f19b594:	00004012 */ 	mflo	$t0
/*  f19b598:	00684821 */ 	addu	$t1,$v1,$t0
/*  f19b59c:	a126009d */ 	sb	$a2,0x9d($t1)
/*  f19b5a0:	24420001 */ 	addiu	$v0,$v0,0x1
.L0f19b5a4:
/*  f19b5a4:	28410004 */ 	slti	$at,$v0,0x4
/*  f19b5a8:	5420fff4 */ 	bnezl	$at,.L0f19b57c
/*  f19b5ac:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f19b5b0:	3c0b800b */ 	lui	$t3,%hi(var800ac798)
/*  f19b5b4:	3c06800b */ 	lui	$a2,%hi(g_MpSetup)
/*  f19b5b8:	30ea000f */ 	andi	$t2,$a3,0xf
/*  f19b5bc:	256bc798 */ 	addiu	$t3,$t3,%lo(var800ac798)
/*  f19b5c0:	24c6cb88 */ 	addiu	$a2,$a2,%lo(g_MpSetup)
/*  f19b5c4:	00ab2021 */ 	addu	$a0,$a1,$t3
/*  f19b5c8:	3c03800b */ 	lui	$v1,%hi(g_MpSimulants)
/*  f19b5cc:	a4ca0016 */ 	sh	$t2,0x16($a2)
/*  f19b5d0:	2463c538 */ 	addiu	$v1,$v1,%lo(g_MpSimulants)
/*  f19b5d4:	24050006 */ 	addiu	$a1,$zero,0x6
/*  f19b5d8:	24070008 */ 	addiu	$a3,$zero,0x8
/*  f19b5dc:	00001025 */ 	or	$v0,$zero,$zero
.L0f19b5e0:
/*  f19b5e0:	908cffff */ 	lbu	$t4,-0x1($a0)
/*  f19b5e4:	2463004c */ 	addiu	$v1,$v1,0x4c
/*  f19b5e8:	244f0004 */ 	addiu	$t7,$v0,0x4
/*  f19b5ec:	318d00ff */ 	andi	$t5,$t4,0xff
/*  f19b5f0:	10ad0006 */ 	beq	$a1,$t5,.L0f19b60c
/*  f19b5f4:	a06cfffc */ 	sb	$t4,-0x4($v1)
/*  f19b5f8:	94ce0016 */ 	lhu	$t6,0x16($a2)
/*  f19b5fc:	24180001 */ 	addiu	$t8,$zero,0x1
/*  f19b600:	01f8c804 */ 	sllv	$t9,$t8,$t7
/*  f19b604:	01d94025 */ 	or	$t0,$t6,$t9
/*  f19b608:	a4c80016 */ 	sh	$t0,0x16($a2)
.L0f19b60c:
/*  f19b60c:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f19b610:	1447fff3 */ 	bne	$v0,$a3,.L0f19b5e0
/*  f19b614:	24840004 */ 	addiu	$a0,$a0,0x4
/*  f19b618:	90c90010 */ 	lbu	$t1,0x10($a2)
/*  f19b61c:	24010004 */ 	addiu	$at,$zero,0x4
/*  f19b620:	240a000a */ 	addiu	$t2,$zero,0xa
/*  f19b624:	1521000b */ 	bne	$t1,$at,.L0f19b654
/*  f19b628:	3c01800a */ 	lui	$at,0x800a
/*  f19b62c:	10000009 */ 	beqz	$zero,.L0f19b654
/*  f19b630:	ac2aa444 */ 	sw	$t2,-0x5bbc($at)
.L0f19b634:
/*  f19b634:	0fc67244 */ 	jal	mpIsChallengeComplete
/*  f19b638:	24040040 */ 	addiu	$a0,$zero,0x40
/*  f19b63c:	14400005 */ 	bnez	$v0,.L0f19b654
/*  f19b640:	3c06800b */ 	lui	$a2,%hi(g_MpSetup)
/*  f19b644:	24c6cb88 */ 	addiu	$a2,$a2,%lo(g_MpSetup)
/*  f19b648:	94cb0016 */ 	lhu	$t3,0x16($a2)
/*  f19b64c:	316c00ff */ 	andi	$t4,$t3,0xff
/*  f19b650:	a4cc0016 */ 	sh	$t4,0x16($a2)
.L0f19b654:
/*  f19b654:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f19b658:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f19b65c:	03e00008 */ 	jr	$ra
/*  f19b660:	00000000 */ 	sll	$zero,$zero,0x0
);

// Mismatch because it's doing something weird with the chrslots, and also
// writing to negative mpsim offsets. This code below might not be functionally
// identical.
//void func0f19b540(void)
//{
//	if (var800acc10 == 5) {
//		s32 slot = 0;
//		s32 i;
//		u32 *ptr;
//
//		for (i = 0; i < 4; i++) {
//			if (g_MpSetup.chrslots & (1 << i)) {
//				g_MpPlayers[i].unk9d = 0x80;
//				slot++;
//			}
//		}
//
//		g_MpSetup.chrslots &= 0x000f;
//		ptr = &var800ac798[slot];
//
//		for (i = 0; i != 8; i++) {
//			g_MpSimulants[i].unk48 = *(ptr - 1);
//
//			if (*(ptr - 1) != 6) {
//				g_MpSetup.chrslots |= 1 << (i + 4);
//			}
//
//			ptr++;
//		}
//
//		if (g_MpSetup.scenario == MPSCENARIO_KINGOFTHEHILL) {
//			g_Vars.mphilltime = 10;
//		}
//	} else {
//		if (!mpIsChallengeComplete(CHALLENGE_UNK64)) {
//			g_MpSetup.chrslots &= 0x00ff;
//		}
//	}
//}

s32 mpGetNumAvailableChallenges(void)
{
	s32 challengeindex;
	s32 count = 0;

	for (challengeindex = 0; challengeindex != 30; challengeindex++) {
		if (mpIsChallengeAvailable(challengeindex)) {
			count++;
		}
	}

	return count;
}

char *mpChallengeGetName(s32 challengeindex)
{
	return textGet(g_MpChallenges[challengeindex].name);
}

GLOBAL_ASM(
glabel func0f19b6f8
/*  f19b6f8:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*  f19b6fc:	afb30020 */ 	sw	$s3,0x20($sp)
/*  f19b700:	afb2001c */ 	sw	$s2,0x1c($sp)
/*  f19b704:	afb10018 */ 	sw	$s1,0x18($sp)
/*  f19b708:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f19b70c:	00809825 */ 	or	$s3,$a0,$zero
/*  f19b710:	afbf0024 */ 	sw	$ra,0x24($sp)
/*  f19b714:	00008825 */ 	or	$s1,$zero,$zero
/*  f19b718:	00008025 */ 	or	$s0,$zero,$zero
/*  f19b71c:	2412001e */ 	addiu	$s2,$zero,0x1e
.L0f19b720:
/*  f19b720:	0fc66be6 */ 	jal	mpIsChallengeAvailable
/*  f19b724:	02002025 */ 	or	$a0,$s0,$zero
/*  f19b728:	50400009 */ 	beqzl	$v0,.L0f19b750
/*  f19b72c:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f19b730:	56330006 */ 	bnel	$s1,$s3,.L0f19b74c
/*  f19b734:	26310001 */ 	addiu	$s1,$s1,0x1
/*  f19b738:	0fc66daf */ 	jal	mpChallengeGetName
/*  f19b73c:	02002025 */ 	or	$a0,$s0,$zero
/*  f19b740:	10000008 */ 	beqz	$zero,.L0f19b764
/*  f19b744:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*  f19b748:	26310001 */ 	addiu	$s1,$s1,0x1
.L0f19b74c:
/*  f19b74c:	26100001 */ 	addiu	$s0,$s0,0x1
.L0f19b750:
/*  f19b750:	1612fff3 */ 	bne	$s0,$s2,.L0f19b720
/*  f19b754:	00000000 */ 	sll	$zero,$zero,0x0
/*  f19b758:	3c027f1c */ 	lui	$v0,0x7f1c
/*  f19b75c:	24429170 */ 	addiu	$v0,$v0,-28304
/*  f19b760:	8fbf0024 */ 	lw	$ra,0x24($sp)
.L0f19b764:
/*  f19b764:	8fb00014 */ 	lw	$s0,0x14($sp)
/*  f19b768:	8fb10018 */ 	lw	$s1,0x18($sp)
/*  f19b76c:	8fb2001c */ 	lw	$s2,0x1c($sp)
/*  f19b770:	8fb30020 */ 	lw	$s3,0x20($sp)
/*  f19b774:	03e00008 */ 	jr	$ra
/*  f19b778:	27bd0028 */ 	addiu	$sp,$sp,0x28
);

void mpSetCurrentChallenge(s32 slotnum)
{
	s32 challengeindex;
	g_MpChallengeIndex = 0;

	for (challengeindex = 0; challengeindex != 30; challengeindex++) {
		if (mpIsChallengeAvailable(challengeindex)) {
			if (slotnum == 0) {
				g_MpChallengeIndex = challengeindex;
				break;
			}

			slotnum--;
		}
	}

	func0f19c1cc();
}

s32 mpGetCurrentChallengeIndex(void)
{
	return g_MpChallengeIndex;
}

GLOBAL_ASM(
glabel func0f19b800
/*  f19b800:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*  f19b804:	afb30020 */ 	sw	$s3,0x20($sp)
/*  f19b808:	afb2001c */ 	sw	$s2,0x1c($sp)
/*  f19b80c:	afb10018 */ 	sw	$s1,0x18($sp)
/*  f19b810:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f19b814:	00809825 */ 	or	$s3,$a0,$zero
/*  f19b818:	afbf0024 */ 	sw	$ra,0x24($sp)
/*  f19b81c:	afa5002c */ 	sw	$a1,0x2c($sp)
/*  f19b820:	00008825 */ 	or	$s1,$zero,$zero
/*  f19b824:	00008025 */ 	or	$s0,$zero,$zero
/*  f19b828:	2412001e */ 	addiu	$s2,$zero,0x1e
.L0f19b82c:
/*  f19b82c:	0fc66be6 */ 	jal	mpIsChallengeAvailable
/*  f19b830:	02002025 */ 	or	$a0,$s0,$zero
/*  f19b834:	50400009 */ 	beqzl	$v0,.L0f19b85c
/*  f19b838:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f19b83c:	16330005 */ 	bne	$s1,$s3,.L0f19b854
/*  f19b840:	02002025 */ 	or	$a0,$s0,$zero
/*  f19b844:	0fc670f7 */ 	jal	mpIsChallengeCompletedByAnyChrWithNumPlayers
/*  f19b848:	8fa5002c */ 	lw	$a1,0x2c($sp)
/*  f19b84c:	10000007 */ 	beqz	$zero,.L0f19b86c
/*  f19b850:	8fbf0024 */ 	lw	$ra,0x24($sp)
.L0f19b854:
/*  f19b854:	26310001 */ 	addiu	$s1,$s1,0x1
/*  f19b858:	26100001 */ 	addiu	$s0,$s0,0x1
.L0f19b85c:
/*  f19b85c:	1612fff3 */ 	bne	$s0,$s2,.L0f19b82c
/*  f19b860:	00000000 */ 	sll	$zero,$zero,0x0
/*  f19b864:	00001025 */ 	or	$v0,$zero,$zero
/*  f19b868:	8fbf0024 */ 	lw	$ra,0x24($sp)
.L0f19b86c:
/*  f19b86c:	8fb00014 */ 	lw	$s0,0x14($sp)
/*  f19b870:	8fb10018 */ 	lw	$s1,0x18($sp)
/*  f19b874:	8fb2001c */ 	lw	$s2,0x1c($sp)
/*  f19b878:	8fb30020 */ 	lw	$s3,0x20($sp)
/*  f19b87c:	03e00008 */ 	jr	$ra
/*  f19b880:	27bd0028 */ 	addiu	$sp,$sp,0x28
/*  f19b884:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*  f19b888:	afb30020 */ 	sw	$s3,0x20($sp)
/*  f19b88c:	afb2001c */ 	sw	$s2,0x1c($sp)
/*  f19b890:	afb10018 */ 	sw	$s1,0x18($sp)
/*  f19b894:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f19b898:	00a09825 */ 	or	$s3,$a1,$zero
/*  f19b89c:	afbf0024 */ 	sw	$ra,0x24($sp)
/*  f19b8a0:	afa40028 */ 	sw	$a0,0x28($sp)
/*  f19b8a4:	afa60030 */ 	sw	$a2,0x30($sp)
/*  f19b8a8:	00008825 */ 	or	$s1,$zero,$zero
/*  f19b8ac:	00008025 */ 	or	$s0,$zero,$zero
/*  f19b8b0:	2412001e */ 	addiu	$s2,$zero,0x1e
.L0f19b8b4:
/*  f19b8b4:	0fc66be6 */ 	jal	mpIsChallengeAvailable
/*  f19b8b8:	02002025 */ 	or	$a0,$s0,$zero
/*  f19b8bc:	5040000b */ 	beqzl	$v0,.L0f19b8ec
/*  f19b8c0:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f19b8c4:	56330008 */ 	bnel	$s1,$s3,.L0f19b8e8
/*  f19b8c8:	26310001 */ 	addiu	$s1,$s1,0x1
/*  f19b8cc:	8fa40028 */ 	lw	$a0,0x28($sp)
/*  f19b8d0:	02002825 */ 	or	$a1,$s0,$zero
/*  f19b8d4:	0fc6711f */ 	jal	mpIsChallengeCompletedByChrWithNumPlayers
/*  f19b8d8:	8fa60030 */ 	lw	$a2,0x30($sp)
/*  f19b8dc:	10000007 */ 	beqz	$zero,.L0f19b8fc
/*  f19b8e0:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*  f19b8e4:	26310001 */ 	addiu	$s1,$s1,0x1
.L0f19b8e8:
/*  f19b8e8:	26100001 */ 	addiu	$s0,$s0,0x1
.L0f19b8ec:
/*  f19b8ec:	1612fff1 */ 	bne	$s0,$s2,.L0f19b8b4
/*  f19b8f0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f19b8f4:	00001025 */ 	or	$v0,$zero,$zero
/*  f19b8f8:	8fbf0024 */ 	lw	$ra,0x24($sp)
.L0f19b8fc:
/*  f19b8fc:	8fb00014 */ 	lw	$s0,0x14($sp)
/*  f19b900:	8fb10018 */ 	lw	$s1,0x18($sp)
/*  f19b904:	8fb2001c */ 	lw	$s2,0x1c($sp)
/*  f19b908:	8fb30020 */ 	lw	$s3,0x20($sp)
/*  f19b90c:	03e00008 */ 	jr	$ra
/*  f19b910:	27bd0028 */ 	addiu	$sp,$sp,0x28
);

GLOBAL_ASM(
glabel func0f19b914
/*  f19b914:	27bdfe38 */ 	addiu	$sp,$sp,-456
/*  f19b918:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f19b91c:	afa401c8 */ 	sw	$a0,0x1c8($sp)
/*  f19b920:	afa501cc */ 	sw	$a1,0x1cc($sp)
/*  f19b924:	0fc5b9b5 */ 	jal	textGetLanguageId
/*  f19b928:	afa601d0 */ 	sw	$a2,0x1d0($sp)
/*  f19b92c:	3c0f8009 */ 	lui	$t7,%hi(var800887c4)
/*  f19b930:	25ef87c4 */ 	addiu	$t7,$t7,%lo(var800887c4)
/*  f19b934:	afa20050 */ 	sw	$v0,0x50($sp)
/*  f19b938:	25e80030 */ 	addiu	$t0,$t7,0x30
/*  f19b93c:	27ae0018 */ 	addiu	$t6,$sp,0x18
.L0f19b940:
/*  f19b940:	8de10000 */ 	lw	$at,0x0($t7)
/*  f19b944:	25ef000c */ 	addiu	$t7,$t7,0xc
/*  f19b948:	25ce000c */ 	addiu	$t6,$t6,0xc
/*  f19b94c:	adc1fff4 */ 	sw	$at,-0xc($t6)
/*  f19b950:	8de1fff8 */ 	lw	$at,-0x8($t7)
/*  f19b954:	adc1fff8 */ 	sw	$at,-0x8($t6)
/*  f19b958:	8de1fffc */ 	lw	$at,-0x4($t7)
/*  f19b95c:	15e8fff8 */ 	bne	$t7,$t0,.L0f19b940
/*  f19b960:	adc1fffc */ 	sw	$at,-0x4($t6)
/*  f19b964:	8de10000 */ 	lw	$at,0x0($t7)
/*  f19b968:	8de80004 */ 	lw	$t0,0x4($t7)
/*  f19b96c:	3c0b007d */ 	lui	$t3,0x7d
/*  f19b970:	adc10000 */ 	sw	$at,0x0($t6)
/*  f19b974:	adc80004 */ 	sw	$t0,0x4($t6)
/*  f19b978:	8fa901c8 */ 	lw	$t1,0x1c8($sp)
/*  f19b97c:	256b0a40 */ 	addiu	$t3,$t3,0xa40
/*  f19b980:	8fa401cc */ 	lw	$a0,0x1cc($sp)
/*  f19b984:	00095080 */ 	sll	$t2,$t1,0x2
/*  f19b988:	01495023 */ 	subu	$t2,$t2,$t1
/*  f19b98c:	000a5080 */ 	sll	$t2,$t2,0x2
/*  f19b990:	01495021 */ 	addu	$t2,$t2,$t1
/*  f19b994:	000a50c0 */ 	sll	$t2,$t2,0x3
/*  f19b998:	014b2821 */ 	addu	$a1,$t2,$t3
/*  f19b99c:	0c003522 */ 	jal	func0000d488
/*  f19b9a0:	24060068 */ 	addiu	$a2,$zero,0x68
/*  f19b9a4:	8fac0050 */ 	lw	$t4,0x50($sp)
/*  f19b9a8:	8fb901c8 */ 	lw	$t9,0x1c8($sp)
/*  f19b9ac:	27a4005c */ 	addiu	$a0,$sp,0x5c
/*  f19b9b0:	000c68c0 */ 	sll	$t5,$t4,0x3
/*  f19b9b4:	03ad1821 */ 	addu	$v1,$sp,$t5
/*  f19b9b8:	0019c080 */ 	sll	$t8,$t9,0x2
/*  f19b9bc:	8c630018 */ 	lw	$v1,0x18($v1)
/*  f19b9c0:	0319c021 */ 	addu	$t8,$t8,$t9
/*  f19b9c4:	0018c180 */ 	sll	$t8,$t8,0x6
/*  f19b9c8:	afa201c4 */ 	sw	$v0,0x1c4($sp)
/*  f19b9cc:	24060140 */ 	addiu	$a2,$zero,0x140
/*  f19b9d0:	0c003522 */ 	jal	func0000d488
/*  f19b9d4:	00782821 */ 	addu	$a1,$v1,$t8
/*  f19b9d8:	8fa701c4 */ 	lw	$a3,0x1c4($sp)
/*  f19b9dc:	00404825 */ 	or	$t1,$v0,$zero
/*  f19b9e0:	244e0138 */ 	addiu	$t6,$v0,0x138
/*  f19b9e4:	00e05025 */ 	or	$t2,$a3,$zero
.L0f19b9e8:
/*  f19b9e8:	89210000 */ 	lwl	$at,0x0($t1)
/*  f19b9ec:	99210003 */ 	lwr	$at,0x3($t1)
/*  f19b9f0:	2529000c */ 	addiu	$t1,$t1,0xc
/*  f19b9f4:	254a000c */ 	addiu	$t2,$t2,0xc
/*  f19b9f8:	a941005c */ 	swl	$at,0x5c($t2)
/*  f19b9fc:	b941005f */ 	swr	$at,0x5f($t2)
/*  f19ba00:	8921fff8 */ 	lwl	$at,-0x8($t1)
/*  f19ba04:	9921fffb */ 	lwr	$at,-0x5($t1)
/*  f19ba08:	a9410060 */ 	swl	$at,0x60($t2)
/*  f19ba0c:	b9410063 */ 	swr	$at,0x63($t2)
/*  f19ba10:	8921fffc */ 	lwl	$at,-0x4($t1)
/*  f19ba14:	9921ffff */ 	lwr	$at,-0x1($t1)
/*  f19ba18:	a9410064 */ 	swl	$at,0x64($t2)
/*  f19ba1c:	152efff2 */ 	bne	$t1,$t6,.L0f19b9e8
/*  f19ba20:	b9410067 */ 	swr	$at,0x67($t2)
/*  f19ba24:	89210000 */ 	lwl	$at,0x0($t1)
/*  f19ba28:	99210003 */ 	lwr	$at,0x3($t1)
/*  f19ba2c:	00e01025 */ 	or	$v0,$a3,$zero
/*  f19ba30:	a9410068 */ 	swl	$at,0x68($t2)
/*  f19ba34:	b941006b */ 	swr	$at,0x6b($t2)
/*  f19ba38:	892e0004 */ 	lwl	$t6,0x4($t1)
/*  f19ba3c:	992e0007 */ 	lwr	$t6,0x7($t1)
/*  f19ba40:	a94e006c */ 	swl	$t6,0x6c($t2)
/*  f19ba44:	b94e006f */ 	swr	$t6,0x6f($t2)
/*  f19ba48:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f19ba4c:	27bd01c8 */ 	addiu	$sp,$sp,0x1c8
/*  f19ba50:	03e00008 */ 	jr	$ra
/*  f19ba54:	00000000 */ 	sll	$zero,$zero,0x0
);

s32 func0f19ba58(s32 challengeindex, s32 arg1, s32 arg2)
{
	return func0f19b914(g_MpChallenges[challengeindex].unk02, arg1, arg2);
}

s32 mpGetNthAvailableChallengeSomething(s32 n, s32 arg1, s32 arg2)
{
	s32 numavailable = 0;
	s32 challengeindex;

	for (challengeindex = 0; challengeindex != 30; challengeindex++) {
		if (mpIsChallengeAvailable(challengeindex)) {
			if (numavailable == n) {
				return func0f19ba58(challengeindex, arg1, arg2);
			}

			numavailable++;
		}
	}

	return 0;
}

s32 func0f19bb20(s32 arg0, s32 arg1)
{
	return func0f19ba58(g_MpChallengeIndex, arg0, arg1);
}

GLOBAL_ASM(
glabel func0f19bb50
/*  f19bb50:	18c00008 */ 	blez	$a2,.L0f19bb74
/*  f19bb54:	00001025 */ 	or	$v0,$zero,$zero
/*  f19bb58:	00a01825 */ 	or	$v1,$a1,$zero
.L0f19bb5c:
/*  f19bb5c:	906e0000 */ 	lbu	$t6,0x0($v1)
/*  f19bb60:	508e0005 */ 	beql	$a0,$t6,.L0f19bb78
/*  f19bb64:	0046082a */ 	slt	$at,$v0,$a2
/*  f19bb68:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f19bb6c:	1446fffb */ 	bne	$v0,$a2,.L0f19bb5c
/*  f19bb70:	24630001 */ 	addiu	$v1,$v1,0x1
.L0f19bb74:
/*  f19bb74:	0046082a */ 	slt	$at,$v0,$a2
.L0f19bb78:
/*  f19bb78:	14200005 */ 	bnez	$at,.L0f19bb90
/*  f19bb7c:	00c7082a */ 	slt	$at,$a2,$a3
/*  f19bb80:	10200003 */ 	beqz	$at,.L0f19bb90
/*  f19bb84:	00a67821 */ 	addu	$t7,$a1,$a2
/*  f19bb88:	a1e40000 */ 	sb	$a0,0x0($t7)
/*  f19bb8c:	24c60001 */ 	addiu	$a2,$a2,0x1
.L0f19bb90:
/*  f19bb90:	03e00008 */ 	jr	$ra
/*  f19bb94:	00c01025 */ 	or	$v0,$a2,$zero
);

GLOBAL_ASM(
glabel func0f19bb98
/*  f19bb98:	27bdffc8 */ 	addiu	$sp,$sp,-56
/*  f19bb9c:	afb30020 */ 	sw	$s3,0x20($sp)
/*  f19bba0:	afb70030 */ 	sw	$s7,0x30($sp)
/*  f19bba4:	afb6002c */ 	sw	$s6,0x2c($sp)
/*  f19bba8:	afb50028 */ 	sw	$s5,0x28($sp)
/*  f19bbac:	afb40024 */ 	sw	$s4,0x24($sp)
/*  f19bbb0:	afb2001c */ 	sw	$s2,0x1c($sp)
/*  f19bbb4:	afb10018 */ 	sw	$s1,0x18($sp)
/*  f19bbb8:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f19bbbc:	3c138008 */ 	lui	$s3,%hi(mpweaponstable)
/*  f19bbc0:	00a0a825 */ 	or	$s5,$a1,$zero
/*  f19bbc4:	00c0b025 */ 	or	$s6,$a2,$zero
/*  f19bbc8:	0080b825 */ 	or	$s7,$a0,$zero
/*  f19bbcc:	afbf0034 */ 	sw	$ra,0x34($sp)
/*  f19bbd0:	00009025 */ 	or	$s2,$zero,$zero
/*  f19bbd4:	26737268 */ 	addiu	$s3,$s3,%lo(mpweaponstable)
/*  f19bbd8:	00808025 */ 	or	$s0,$a0,$zero
/*  f19bbdc:	00008825 */ 	or	$s1,$zero,$zero
/*  f19bbe0:	2414000a */ 	addiu	$s4,$zero,0xa
.L0f19bbe4:
/*  f19bbe4:	920e0018 */ 	lbu	$t6,0x18($s0)
/*  f19bbe8:	02a02825 */ 	or	$a1,$s5,$zero
/*  f19bbec:	02403025 */ 	or	$a2,$s2,$zero
/*  f19bbf0:	01d40019 */ 	multu	$t6,$s4
/*  f19bbf4:	00007812 */ 	mflo	$t7
/*  f19bbf8:	026fc021 */ 	addu	$t8,$s3,$t7
/*  f19bbfc:	97040004 */ 	lhu	$a0,0x4($t8)
/*  f19bc00:	3099007f */ 	andi	$t9,$a0,0x7f
/*  f19bc04:	13200004 */ 	beqz	$t9,.L0f19bc18
/*  f19bc08:	03202025 */ 	or	$a0,$t9,$zero
/*  f19bc0c:	0fc66ed4 */ 	jal	func0f19bb50
/*  f19bc10:	02c03825 */ 	or	$a3,$s6,$zero
/*  f19bc14:	00409025 */ 	or	$s2,$v0,$zero
.L0f19bc18:
/*  f19bc18:	26310001 */ 	addiu	$s1,$s1,0x1
/*  f19bc1c:	2a210006 */ 	slti	$at,$s1,0x6
/*  f19bc20:	1420fff0 */ 	bnez	$at,.L0f19bbe4
/*  f19bc24:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f19bc28:	0fc5e43f */ 	jal	func0f1790fc
/*  f19bc2c:	00008825 */ 	or	$s1,$zero,$zero
/*  f19bc30:	18400018 */ 	blez	$v0,.L0f19bc94
/*  f19bc34:	00114080 */ 	sll	$t0,$s1,0x2
/*  f19bc38:	01114023 */ 	subu	$t0,$t0,$s1
/*  f19bc3c:	3c098008 */ 	lui	$t1,%hi(mpstages)
/*  f19bc40:	25294b98 */ 	addiu	$t1,$t1,%lo(mpstages)
/*  f19bc44:	00084040 */ 	sll	$t0,$t0,0x1
/*  f19bc48:	01098021 */ 	addu	$s0,$t0,$t1
/*  f19bc4c:	92ea0011 */ 	lbu	$t2,0x11($s7)
.L0f19bc50:
/*  f19bc50:	860b0000 */ 	lh	$t3,0x0($s0)
/*  f19bc54:	554b000a */ 	bnel	$t2,$t3,.L0f19bc80
/*  f19bc58:	26310001 */ 	addiu	$s1,$s1,0x1
/*  f19bc5c:	92040002 */ 	lbu	$a0,0x2($s0)
/*  f19bc60:	02a02825 */ 	or	$a1,$s5,$zero
/*  f19bc64:	02403025 */ 	or	$a2,$s2,$zero
/*  f19bc68:	50800005 */ 	beqzl	$a0,.L0f19bc80
/*  f19bc6c:	26310001 */ 	addiu	$s1,$s1,0x1
/*  f19bc70:	0fc66ed4 */ 	jal	func0f19bb50
/*  f19bc74:	02c03825 */ 	or	$a3,$s6,$zero
/*  f19bc78:	00409025 */ 	or	$s2,$v0,$zero
/*  f19bc7c:	26310001 */ 	addiu	$s1,$s1,0x1
.L0f19bc80:
/*  f19bc80:	0fc5e43f */ 	jal	func0f1790fc
/*  f19bc84:	26100006 */ 	addiu	$s0,$s0,0x6
/*  f19bc88:	0222082a */ 	slt	$at,$s1,$v0
/*  f19bc8c:	5420fff0 */ 	bnezl	$at,.L0f19bc50
/*  f19bc90:	92ea0011 */ 	lbu	$t2,0x11($s7)
.L0f19bc94:
/*  f19bc94:	92e20010 */ 	lbu	$v0,0x10($s7)
/*  f19bc98:	3c048008 */ 	lui	$a0,0x8008
/*  f19bc9c:	28410006 */ 	slti	$at,$v0,0x6
/*  f19bca0:	1020000c */ 	beqz	$at,.L0f19bcd4
/*  f19bca4:	00026080 */ 	sll	$t4,$v0,0x2
/*  f19bca8:	01826023 */ 	subu	$t4,$t4,$v0
/*  f19bcac:	000c6040 */ 	sll	$t4,$t4,0x1
/*  f19bcb0:	008c2021 */ 	addu	$a0,$a0,$t4
/*  f19bcb4:	9084714c */ 	lbu	$a0,0x714c($a0)
/*  f19bcb8:	02a02825 */ 	or	$a1,$s5,$zero
/*  f19bcbc:	02403025 */ 	or	$a2,$s2,$zero
/*  f19bcc0:	50800005 */ 	beqzl	$a0,.L0f19bcd8
/*  f19bcc4:	8ee3000c */ 	lw	$v1,0xc($s7)
/*  f19bcc8:	0fc66ed4 */ 	jal	func0f19bb50
/*  f19bccc:	02c03825 */ 	or	$a3,$s6,$zero
/*  f19bcd0:	00409025 */ 	or	$s2,$v0,$zero
.L0f19bcd4:
/*  f19bcd4:	8ee3000c */ 	lw	$v1,0xc($s7)
.L0f19bcd8:
/*  f19bcd8:	2404001e */ 	addiu	$a0,$zero,0x1e
/*  f19bcdc:	02a02825 */ 	or	$a1,$s5,$zero
/*  f19bce0:	306d0001 */ 	andi	$t5,$v1,0x1
/*  f19bce4:	11a00005 */ 	beqz	$t5,.L0f19bcfc
/*  f19bce8:	02403025 */ 	or	$a2,$s2,$zero
/*  f19bcec:	0fc66ed4 */ 	jal	func0f19bb50
/*  f19bcf0:	02c03825 */ 	or	$a3,$s6,$zero
/*  f19bcf4:	00409025 */ 	or	$s2,$v0,$zero
/*  f19bcf8:	8ee3000c */ 	lw	$v1,0xc($s7)
.L0f19bcfc:
/*  f19bcfc:	306e00c0 */ 	andi	$t6,$v1,0xc0
/*  f19bd00:	11c00006 */ 	beqz	$t6,.L0f19bd1c
/*  f19bd04:	2404001d */ 	addiu	$a0,$zero,0x1d
/*  f19bd08:	02a02825 */ 	or	$a1,$s5,$zero
/*  f19bd0c:	02403025 */ 	or	$a2,$s2,$zero
/*  f19bd10:	0fc66ed4 */ 	jal	func0f19bb50
/*  f19bd14:	02c03825 */ 	or	$a3,$s6,$zero
/*  f19bd18:	00409025 */ 	or	$s2,$v0,$zero
.L0f19bd1c:
/*  f19bd1c:	8fbf0034 */ 	lw	$ra,0x34($sp)
/*  f19bd20:	02401025 */ 	or	$v0,$s2,$zero
/*  f19bd24:	8fb2001c */ 	lw	$s2,0x1c($sp)
/*  f19bd28:	8fb00014 */ 	lw	$s0,0x14($sp)
/*  f19bd2c:	8fb10018 */ 	lw	$s1,0x18($sp)
/*  f19bd30:	8fb30020 */ 	lw	$s3,0x20($sp)
/*  f19bd34:	8fb40024 */ 	lw	$s4,0x24($sp)
/*  f19bd38:	8fb50028 */ 	lw	$s5,0x28($sp)
/*  f19bd3c:	8fb6002c */ 	lw	$s6,0x2c($sp)
/*  f19bd40:	8fb70030 */ 	lw	$s7,0x30($sp)
/*  f19bd44:	03e00008 */ 	jr	$ra
/*  f19bd48:	27bd0038 */ 	addiu	$sp,$sp,0x38
);

GLOBAL_ASM(
glabel func0f19bd4c
/*  f19bd4c:	27bdffa0 */ 	addiu	$sp,$sp,-96
/*  f19bd50:	afbf003c */ 	sw	$ra,0x3c($sp)
/*  f19bd54:	afb40028 */ 	sw	$s4,0x28($sp)
/*  f19bd58:	afb30024 */ 	sw	$s3,0x24($sp)
/*  f19bd5c:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f19bd60:	00808025 */ 	or	$s0,$a0,$zero
/*  f19bd64:	00c09825 */ 	or	$s3,$a2,$zero
/*  f19bd68:	00a0a025 */ 	or	$s4,$a1,$zero
/*  f19bd6c:	afbe0038 */ 	sw	$s8,0x38($sp)
/*  f19bd70:	afb70034 */ 	sw	$s7,0x34($sp)
/*  f19bd74:	afb60030 */ 	sw	$s6,0x30($sp)
/*  f19bd78:	afb5002c */ 	sw	$s5,0x2c($sp)
/*  f19bd7c:	afb20020 */ 	sw	$s2,0x20($sp)
/*  f19bd80:	afb1001c */ 	sw	$s1,0x1c($sp)
/*  f19bd84:	0fc66ee6 */ 	jal	func0f19bb98
/*  f19bd88:	afa7006c */ 	sw	$a3,0x6c($sp)
/*  f19bd8c:	3c158008 */ 	lui	$s5,%hi(g_MpGeneralSimulants)
/*  f19bd90:	00409025 */ 	or	$s2,$v0,$zero
/*  f19bd94:	26b5772c */ 	addiu	$s5,$s5,%lo(g_MpGeneralSimulants)
/*  f19bd98:	0000f025 */ 	or	$s8,$zero,$zero
/*  f19bd9c:	0200b825 */ 	or	$s7,$s0,$zero
/*  f19bda0:	afb00040 */ 	sw	$s0,0x40($sp)
/*  f19bda4:	24160004 */ 	addiu	$s6,$zero,0x4
.L0f19bda8:
/*  f19bda8:	92e40028 */ 	lbu	$a0,0x28($s7)
/*  f19bdac:	0fc6335a */ 	jal	func0f18cd68
/*  f19bdb0:	24050002 */ 	addiu	$a1,$zero,0x2
/*  f19bdb4:	0440000a */ 	bltz	$v0,.L0f19bde0
/*  f19bdb8:	000270c0 */ 	sll	$t6,$v0,0x3
/*  f19bdbc:	02ae7821 */ 	addu	$t7,$s5,$t6
/*  f19bdc0:	91e40006 */ 	lbu	$a0,0x6($t7)
/*  f19bdc4:	02802825 */ 	or	$a1,$s4,$zero
/*  f19bdc8:	02403025 */ 	or	$a2,$s2,$zero
/*  f19bdcc:	50800005 */ 	beqzl	$a0,.L0f19bde4
/*  f19bdd0:	00008025 */ 	or	$s0,$zero,$zero
/*  f19bdd4:	0fc66ed4 */ 	jal	func0f19bb50
/*  f19bdd8:	02603825 */ 	or	$a3,$s3,$zero
/*  f19bddc:	00409025 */ 	or	$s2,$v0,$zero
.L0f19bde0:
/*  f19bde0:	00008025 */ 	or	$s0,$zero,$zero
.L0f19bde4:
/*  f19bde4:	8fb10040 */ 	lw	$s1,0x40($sp)
.L0f19bde8:
/*  f19bde8:	00002025 */ 	or	$a0,$zero,$zero
/*  f19bdec:	0fc6335a */ 	jal	func0f18cd68
/*  f19bdf0:	9225002c */ 	lbu	$a1,0x2c($s1)
/*  f19bdf4:	0440000a */ 	bltz	$v0,.L0f19be20
/*  f19bdf8:	0002c0c0 */ 	sll	$t8,$v0,0x3
/*  f19bdfc:	02b8c821 */ 	addu	$t9,$s5,$t8
/*  f19be00:	93240006 */ 	lbu	$a0,0x6($t9)
/*  f19be04:	02802825 */ 	or	$a1,$s4,$zero
/*  f19be08:	02403025 */ 	or	$a2,$s2,$zero
/*  f19be0c:	50800005 */ 	beqzl	$a0,.L0f19be24
/*  f19be10:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f19be14:	0fc66ed4 */ 	jal	func0f19bb50
/*  f19be18:	02603825 */ 	or	$a3,$s3,$zero
/*  f19be1c:	00409025 */ 	or	$s2,$v0,$zero
.L0f19be20:
/*  f19be20:	26100001 */ 	addiu	$s0,$s0,0x1
.L0f19be24:
/*  f19be24:	1616fff0 */ 	bne	$s0,$s6,.L0f19bde8
/*  f19be28:	26310001 */ 	addiu	$s1,$s1,0x1
/*  f19be2c:	92e2002a */ 	lbu	$v0,0x2a($s7)
/*  f19be30:	3c048008 */ 	lui	$a0,0x8008
/*  f19be34:	2841003d */ 	slti	$at,$v0,0x3d
/*  f19be38:	1020000a */ 	beqz	$at,.L0f19be64
/*  f19be3c:	000240c0 */ 	sll	$t0,$v0,0x3
/*  f19be40:	00882021 */ 	addu	$a0,$a0,$t0
/*  f19be44:	908477c2 */ 	lbu	$a0,0x77c2($a0)
/*  f19be48:	02802825 */ 	or	$a1,$s4,$zero
/*  f19be4c:	02403025 */ 	or	$a2,$s2,$zero
/*  f19be50:	50800005 */ 	beqzl	$a0,.L0f19be68
/*  f19be54:	92e20029 */ 	lbu	$v0,0x29($s7)
/*  f19be58:	0fc66ed4 */ 	jal	func0f19bb50
/*  f19be5c:	02603825 */ 	or	$a3,$s3,$zero
/*  f19be60:	00409025 */ 	or	$s2,$v0,$zero
.L0f19be64:
/*  f19be64:	92e20029 */ 	lbu	$v0,0x29($s7)
.L0f19be68:
/*  f19be68:	3c048008 */ 	lui	$a0,0x8008
/*  f19be6c:	2841004b */ 	slti	$at,$v0,0x4b
/*  f19be70:	1020000a */ 	beqz	$at,.L0f19be9c
/*  f19be74:	00024880 */ 	sll	$t1,$v0,0x2
/*  f19be78:	00892021 */ 	addu	$a0,$a0,$t1
/*  f19be7c:	9084752e */ 	lbu	$a0,0x752e($a0)
/*  f19be80:	02802825 */ 	or	$a1,$s4,$zero
/*  f19be84:	02403025 */ 	or	$a2,$s2,$zero
/*  f19be88:	50800005 */ 	beqzl	$a0,.L0f19bea0
/*  f19be8c:	8faa0040 */ 	lw	$t2,0x40($sp)
/*  f19be90:	0fc66ed4 */ 	jal	func0f19bb50
/*  f19be94:	02603825 */ 	or	$a3,$s3,$zero
/*  f19be98:	00409025 */ 	or	$s2,$v0,$zero
.L0f19be9c:
/*  f19be9c:	8faa0040 */ 	lw	$t2,0x40($sp)
.L0f19bea0:
/*  f19bea0:	27de0008 */ 	addiu	$s8,$s8,0x8
/*  f19bea4:	2bc10040 */ 	slti	$at,$s8,0x40
/*  f19bea8:	254b0008 */ 	addiu	$t3,$t2,0x8
/*  f19beac:	afab0040 */ 	sw	$t3,0x40($sp)
/*  f19beb0:	1420ffbd */ 	bnez	$at,.L0f19bda8
/*  f19beb4:	26f70008 */ 	addiu	$s7,$s7,0x8
/*  f19beb8:	8fa2006c */ 	lw	$v0,0x6c($sp)
/*  f19bebc:	2404001c */ 	addiu	$a0,$zero,0x1c
/*  f19bec0:	02802825 */ 	or	$a1,$s4,$zero
/*  f19bec4:	28410019 */ 	slti	$at,$v0,0x19
/*  f19bec8:	14200006 */ 	bnez	$at,.L0f19bee4
/*  f19becc:	02403025 */ 	or	$a2,$s2,$zero
/*  f19bed0:	0fc66ed4 */ 	jal	func0f19bb50
/*  f19bed4:	02603825 */ 	or	$a3,$s3,$zero
/*  f19bed8:	00409025 */ 	or	$s2,$v0,$zero
/*  f19bedc:	10000014 */ 	beqz	$zero,.L0f19bf30
/*  f19bee0:	8fa2006c */ 	lw	$v0,0x6c($sp)
.L0f19bee4:
/*  f19bee4:	28410014 */ 	slti	$at,$v0,0x14
/*  f19bee8:	14200008 */ 	bnez	$at,.L0f19bf0c
/*  f19beec:	24040023 */ 	addiu	$a0,$zero,0x23
/*  f19bef0:	02802825 */ 	or	$a1,$s4,$zero
/*  f19bef4:	02403025 */ 	or	$a2,$s2,$zero
/*  f19bef8:	0fc66ed4 */ 	jal	func0f19bb50
/*  f19befc:	02603825 */ 	or	$a3,$s3,$zero
/*  f19bf00:	00409025 */ 	or	$s2,$v0,$zero
/*  f19bf04:	1000000a */ 	beqz	$zero,.L0f19bf30
/*  f19bf08:	8fa2006c */ 	lw	$v0,0x6c($sp)
.L0f19bf0c:
/*  f19bf0c:	2841000f */ 	slti	$at,$v0,0xf
/*  f19bf10:	14200007 */ 	bnez	$at,.L0f19bf30
/*  f19bf14:	2404004d */ 	addiu	$a0,$zero,0x4d
/*  f19bf18:	02802825 */ 	or	$a1,$s4,$zero
/*  f19bf1c:	02403025 */ 	or	$a2,$s2,$zero
/*  f19bf20:	0fc66ed4 */ 	jal	func0f19bb50
/*  f19bf24:	02603825 */ 	or	$a3,$s3,$zero
/*  f19bf28:	00409025 */ 	or	$s2,$v0,$zero
/*  f19bf2c:	8fa2006c */ 	lw	$v0,0x6c($sp)
.L0f19bf30:
/*  f19bf30:	2841000a */ 	slti	$at,$v0,0xa
/*  f19bf34:	14200006 */ 	bnez	$at,.L0f19bf50
/*  f19bf38:	24040040 */ 	addiu	$a0,$zero,0x40
/*  f19bf3c:	02802825 */ 	or	$a1,$s4,$zero
/*  f19bf40:	02403025 */ 	or	$a2,$s2,$zero
/*  f19bf44:	0fc66ed4 */ 	jal	func0f19bb50
/*  f19bf48:	02603825 */ 	or	$a3,$s3,$zero
/*  f19bf4c:	00409025 */ 	or	$s2,$v0,$zero
.L0f19bf50:
/*  f19bf50:	0253082a */ 	slt	$at,$s2,$s3
/*  f19bf54:	10200006 */ 	beqz	$at,.L0f19bf70
/*  f19bf58:	02401825 */ 	or	$v1,$s2,$zero
/*  f19bf5c:	02921021 */ 	addu	$v0,$s4,$s2
.L0f19bf60:
/*  f19bf60:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f19bf64:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f19bf68:	1473fffd */ 	bne	$v1,$s3,.L0f19bf60
/*  f19bf6c:	a040ffff */ 	sb	$zero,-0x1($v0)
.L0f19bf70:
/*  f19bf70:	8fbf003c */ 	lw	$ra,0x3c($sp)
/*  f19bf74:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f19bf78:	8fb1001c */ 	lw	$s1,0x1c($sp)
/*  f19bf7c:	8fb20020 */ 	lw	$s2,0x20($sp)
/*  f19bf80:	8fb30024 */ 	lw	$s3,0x24($sp)
/*  f19bf84:	8fb40028 */ 	lw	$s4,0x28($sp)
/*  f19bf88:	8fb5002c */ 	lw	$s5,0x2c($sp)
/*  f19bf8c:	8fb60030 */ 	lw	$s6,0x30($sp)
/*  f19bf90:	8fb70034 */ 	lw	$s7,0x34($sp)
/*  f19bf94:	8fbe0038 */ 	lw	$s8,0x38($sp)
/*  f19bf98:	03e00008 */ 	jr	$ra
/*  f19bf9c:	27bd0060 */ 	addiu	$sp,$sp,0x60
);

GLOBAL_ASM(
glabel func0f19bfa0
/*  f19bfa0:	27bdffc0 */ 	addiu	$sp,$sp,-64
/*  f19bfa4:	afb30024 */ 	sw	$s3,0x24($sp)
/*  f19bfa8:	3c13800b */ 	lui	$s3,%hi(var800acca0)
/*  f19bfac:	2673cca0 */ 	addiu	$s3,$s3,%lo(var800acca0)
/*  f19bfb0:	afbf003c */ 	sw	$ra,0x3c($sp)
/*  f19bfb4:	afb5002c */ 	sw	$s5,0x2c($sp)
/*  f19bfb8:	3c04800b */ 	lui	$a0,%hi(g_MpSetup)
/*  f19bfbc:	afbe0038 */ 	sw	$s8,0x38($sp)
/*  f19bfc0:	afb70034 */ 	sw	$s7,0x34($sp)
/*  f19bfc4:	afb60030 */ 	sw	$s6,0x30($sp)
/*  f19bfc8:	afb40028 */ 	sw	$s4,0x28($sp)
/*  f19bfcc:	afb20020 */ 	sw	$s2,0x20($sp)
/*  f19bfd0:	afb1001c */ 	sw	$s1,0x1c($sp)
/*  f19bfd4:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f19bfd8:	0000a825 */ 	or	$s5,$zero,$zero
/*  f19bfdc:	2484cb88 */ 	addiu	$a0,$a0,%lo(g_MpSetup)
/*  f19bfe0:	02602825 */ 	or	$a1,$s3,$zero
/*  f19bfe4:	0fc66ee6 */ 	jal	func0f19bb98
/*  f19bfe8:	24060028 */ 	addiu	$a2,$zero,0x28
/*  f19bfec:	3c11800b */ 	lui	$s1,%hi(g_MpSimulants)
/*  f19bff0:	3c1e800b */ 	lui	$s8,%hi(var800ac798)
/*  f19bff4:	3c178008 */ 	lui	$s7,%hi(mpheadstable)
/*  f19bff8:	3c168008 */ 	lui	$s6,%hi(mpbodytable)
/*  f19bffc:	3c148008 */ 	lui	$s4,%hi(g_MpGeneralSimulants)
/*  f19c000:	00408025 */ 	or	$s0,$v0,$zero
/*  f19c004:	2694772c */ 	addiu	$s4,$s4,%lo(g_MpGeneralSimulants)
/*  f19c008:	26d677bc */ 	addiu	$s6,$s6,%lo(mpbodytable)
/*  f19c00c:	26f7752c */ 	addiu	$s7,$s7,%lo(mpheadstable)
/*  f19c010:	27dec798 */ 	addiu	$s8,$s8,%lo(var800ac798)
/*  f19c014:	2631c538 */ 	addiu	$s1,$s1,%lo(g_MpSimulants)
/*  f19c018:	92240047 */ 	lbu	$a0,0x47($s1)
.L0f19c01c:
/*  f19c01c:	0fc6335a */ 	jal	func0f18cd68
/*  f19c020:	24050002 */ 	addiu	$a1,$zero,0x2
/*  f19c024:	0440000a */ 	bltz	$v0,.L0f19c050
/*  f19c028:	000270c0 */ 	sll	$t6,$v0,0x3
/*  f19c02c:	028e7821 */ 	addu	$t7,$s4,$t6
/*  f19c030:	91e40006 */ 	lbu	$a0,0x6($t7)
/*  f19c034:	02602825 */ 	or	$a1,$s3,$zero
/*  f19c038:	02003025 */ 	or	$a2,$s0,$zero
/*  f19c03c:	50800005 */ 	beqzl	$a0,.L0f19c054
/*  f19c040:	00002025 */ 	or	$a0,$zero,$zero
/*  f19c044:	0fc66ed4 */ 	jal	func0f19bb50
/*  f19c048:	24070028 */ 	addiu	$a3,$zero,0x28
/*  f19c04c:	00408025 */ 	or	$s0,$v0,$zero
.L0f19c050:
/*  f19c050:	00002025 */ 	or	$a0,$zero,$zero
.L0f19c054:
/*  f19c054:	0fc6335a */ 	jal	func0f18cd68
/*  f19c058:	92250048 */ 	lbu	$a1,0x48($s1)
/*  f19c05c:	0440000b */ 	bltz	$v0,.L0f19c08c
/*  f19c060:	00409025 */ 	or	$s2,$v0,$zero
/*  f19c064:	0002c0c0 */ 	sll	$t8,$v0,0x3
/*  f19c068:	0298c821 */ 	addu	$t9,$s4,$t8
/*  f19c06c:	93240006 */ 	lbu	$a0,0x6($t9)
/*  f19c070:	02602825 */ 	or	$a1,$s3,$zero
/*  f19c074:	02003025 */ 	or	$a2,$s0,$zero
/*  f19c078:	10800004 */ 	beqz	$a0,.L0f19c08c
/*  f19c07c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f19c080:	0fc66ed4 */ 	jal	func0f19bb50
/*  f19c084:	24070028 */ 	addiu	$a3,$zero,0x28
/*  f19c088:	00408025 */ 	or	$s0,$v0,$zero
.L0f19c08c:
/*  f19c08c:	06420003 */ 	bltzl	$s2,.L0f19c09c
/*  f19c090:	92220010 */ 	lbu	$v0,0x10($s1)
/*  f19c094:	26b50001 */ 	addiu	$s5,$s5,0x1
/*  f19c098:	92220010 */ 	lbu	$v0,0x10($s1)
.L0f19c09c:
/*  f19c09c:	2841003d */ 	slti	$at,$v0,0x3d
/*  f19c0a0:	1020000a */ 	beqz	$at,.L0f19c0cc
/*  f19c0a4:	000240c0 */ 	sll	$t0,$v0,0x3
/*  f19c0a8:	02c84821 */ 	addu	$t1,$s6,$t0
/*  f19c0ac:	91240006 */ 	lbu	$a0,0x6($t1)
/*  f19c0b0:	02602825 */ 	or	$a1,$s3,$zero
/*  f19c0b4:	02003025 */ 	or	$a2,$s0,$zero
/*  f19c0b8:	50800005 */ 	beqzl	$a0,.L0f19c0d0
/*  f19c0bc:	9222000f */ 	lbu	$v0,0xf($s1)
/*  f19c0c0:	0fc66ed4 */ 	jal	func0f19bb50
/*  f19c0c4:	24070028 */ 	addiu	$a3,$zero,0x28
/*  f19c0c8:	00408025 */ 	or	$s0,$v0,$zero
.L0f19c0cc:
/*  f19c0cc:	9222000f */ 	lbu	$v0,0xf($s1)
.L0f19c0d0:
/*  f19c0d0:	2841004b */ 	slti	$at,$v0,0x4b
/*  f19c0d4:	1020000a */ 	beqz	$at,.L0f19c100
/*  f19c0d8:	00025080 */ 	sll	$t2,$v0,0x2
/*  f19c0dc:	02ea5821 */ 	addu	$t3,$s7,$t2
/*  f19c0e0:	91640002 */ 	lbu	$a0,0x2($t3)
/*  f19c0e4:	02602825 */ 	or	$a1,$s3,$zero
/*  f19c0e8:	02003025 */ 	or	$a2,$s0,$zero
/*  f19c0ec:	50800005 */ 	beqzl	$a0,.L0f19c104
/*  f19c0f0:	2631004c */ 	addiu	$s1,$s1,0x4c
/*  f19c0f4:	0fc66ed4 */ 	jal	func0f19bb50
/*  f19c0f8:	24070028 */ 	addiu	$a3,$zero,0x28
/*  f19c0fc:	00408025 */ 	or	$s0,$v0,$zero
.L0f19c100:
/*  f19c100:	2631004c */ 	addiu	$s1,$s1,0x4c
.L0f19c104:
/*  f19c104:	023e082b */ 	sltu	$at,$s1,$s8
/*  f19c108:	5420ffc4 */ 	bnezl	$at,.L0f19c01c
/*  f19c10c:	92240047 */ 	lbu	$a0,0x47($s1)
/*  f19c110:	2aa10005 */ 	slti	$at,$s5,0x5
/*  f19c114:	14200006 */ 	bnez	$at,.L0f19c130
/*  f19c118:	24040040 */ 	addiu	$a0,$zero,0x40
/*  f19c11c:	02602825 */ 	or	$a1,$s3,$zero
/*  f19c120:	02003025 */ 	or	$a2,$s0,$zero
/*  f19c124:	0fc66ed4 */ 	jal	func0f19bb50
/*  f19c128:	24070028 */ 	addiu	$a3,$zero,0x28
/*  f19c12c:	00408025 */ 	or	$s0,$v0,$zero
.L0f19c130:
/*  f19c130:	2a010028 */ 	slti	$at,$s0,0x28
/*  f19c134:	10200008 */ 	beqz	$at,.L0f19c158
/*  f19c138:	3c0c800b */ 	lui	$t4,%hi(var800acca0)
/*  f19c13c:	258ccca0 */ 	addiu	$t4,$t4,%lo(var800acca0)
/*  f19c140:	3c03800b */ 	lui	$v1,%hi(g_MpChallengesCompleted)
/*  f19c144:	2463ccc8 */ 	addiu	$v1,$v1,%lo(g_MpChallengesCompleted)
/*  f19c148:	020c1021 */ 	addu	$v0,$s0,$t4
.L0f19c14c:
/*  f19c14c:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f19c150:	1443fffe */ 	bne	$v0,$v1,.L0f19c14c
/*  f19c154:	a040ffff */ 	sb	$zero,-0x1($v0)
.L0f19c158:
/*  f19c158:	0fc66bf7 */ 	jal	func0f19afdc
/*  f19c15c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f19c160:	8fbf003c */ 	lw	$ra,0x3c($sp)
/*  f19c164:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f19c168:	8fb1001c */ 	lw	$s1,0x1c($sp)
/*  f19c16c:	8fb20020 */ 	lw	$s2,0x20($sp)
/*  f19c170:	8fb30024 */ 	lw	$s3,0x24($sp)
/*  f19c174:	8fb40028 */ 	lw	$s4,0x28($sp)
/*  f19c178:	8fb5002c */ 	lw	$s5,0x2c($sp)
/*  f19c17c:	8fb60030 */ 	lw	$s6,0x30($sp)
/*  f19c180:	8fb70034 */ 	lw	$s7,0x34($sp)
/*  f19c184:	8fbe0038 */ 	lw	$s8,0x38($sp)
/*  f19c188:	03e00008 */ 	jr	$ra
/*  f19c18c:	27bd0040 */ 	addiu	$sp,$sp,0x40
);

void func0f19c190(void)
{
	s32 i;
	for (i = 0; i < 40; i++) {
		var800acca0[i] = 0;
	}

	func0f19afdc();
}

GLOBAL_ASM(
glabel func0f19c1cc
/*  f19c1cc:	27bdfe10 */ 	addiu	$sp,$sp,-496
/*  f19c1d0:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f19c1d4:	27a40020 */ 	addiu	$a0,$sp,0x20
/*  f19c1d8:	0fc66ec8 */ 	jal	func0f19bb20
/*  f19c1dc:	240501ca */ 	addiu	$a1,$zero,0x1ca
/*  f19c1e0:	0fc6373b */ 	jal	func0f18dcec
/*  f19c1e4:	00402025 */ 	or	$a0,$v0,$zero
/*  f19c1e8:	24040005 */ 	addiu	$a0,$zero,0x5
/*  f19c1ec:	0fc62fdc */ 	jal	mpSetLock
/*  f19c1f0:	24050005 */ 	addiu	$a1,$zero,0x5
/*  f19c1f4:	3c03800b */ 	lui	$v1,%hi(g_MpPlayers)
/*  f19c1f8:	3c02800b */ 	lui	$v0,%hi(var800aca38)
/*  f19c1fc:	2442ca38 */ 	addiu	$v0,$v0,%lo(var800aca38)
/*  f19c200:	2463c7b8 */ 	addiu	$v1,$v1,%lo(g_MpPlayers)
.L0f19c204:
/*  f19c204:	246300a0 */ 	addiu	$v1,$v1,0xa0
/*  f19c208:	1462fffe */ 	bne	$v1,$v0,.L0f19c204
/*  f19c20c:	a060ff71 */ 	sb	$zero,-0x8f($v1)
/*  f19c210:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f19c214:	27bd01f0 */ 	addiu	$sp,$sp,0x1f0
/*  f19c218:	03e00008 */ 	jr	$ra
/*  f19c21c:	00000000 */ 	sll	$zero,$zero,0x0
);

s32 func0f19c220(void)
{
	return mpSetLock(0, 0);
}

void mpCalculateVar800884b4(s32 arg0, s32 arg1)
{
	var800884b4 = func0f19bb20(arg0, arg1);
}

void mpResetVar800884b4(void)
{
	var800884b4 = 0;
}

bool mpIsVar800884b4NonZero(void)
{
	return var800884b4 != 0;
}

GLOBAL_ASM(
glabel func0f19c288
/*  f19c288:	3c038009 */ 	lui	$v1,0x8009
/*  f19c28c:	8c6384b4 */ 	lw	$v1,-0x7b4c($v1)
/*  f19c290:	3c027f1c */ 	lui	$v0,0x7f1c
/*  f19c294:	24429174 */ 	addiu	$v0,$v0,-28300
/*  f19c298:	10600003 */ 	beqz	$v1,.L0f19c2a8
/*  f19c29c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f19c2a0:	03e00008 */ 	jr	$ra
/*  f19c2a4:	24620068 */ 	addiu	$v0,$v1,0x68
.L0f19c2a8:
/*  f19c2a8:	03e00008 */ 	jr	$ra
/*  f19c2ac:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f19c2b0
/*  f19c2b0:	10800003 */ 	beqz	$a0,.L0f19c2c0
/*  f19c2b4:	3c027f1c */ 	lui	$v0,0x7f1c
/*  f19c2b8:	03e00008 */ 	jr	$ra
/*  f19c2bc:	24820068 */ 	addiu	$v0,$a0,0x68
.L0f19c2c0:
/*  f19c2c0:	24429178 */ 	addiu	$v0,$v0,-28296
/*  f19c2c4:	03e00008 */ 	jr	$ra
/*  f19c2c8:	00000000 */ 	sll	$zero,$zero,0x0
);

s32 mpGetNumChallengesAvailable(s32 mpchrnum)
{
	s32 challengeindex;
	s32 numavail = 0;

	for (challengeindex = 29; challengeindex >= 0; challengeindex--) {
		if (mpIsChallengeCompletedByChrWithNumPlayers(mpchrnum, challengeindex, 1) ||
				mpIsChallengeCompletedByChrWithNumPlayers(mpchrnum, challengeindex, 2) ||
				mpIsChallengeCompletedByChrWithNumPlayers(mpchrnum, challengeindex, 3) ||
				mpIsChallengeCompletedByChrWithNumPlayers(mpchrnum, challengeindex, 4)) {
			numavail = challengeindex + 1;
			break;
		}
	}

	if (numavail < 4) {
		numavail = 4;
	}

	return numavail;
}

char *mpChallengeGetNameWithArg(s32 arg0, s32 challengeindex)
{
	return textGet(g_MpChallenges[challengeindex].name);
}

bool func0f19c3bc(s32 mpchrnum, s32 index, s32 numplayers)
{
	return mpIsChallengeCompletedByChrWithNumPlayers(mpchrnum, index, numplayers);
}

bool mpIsChallengeCompletedByAnyChrWithNumPlayers(s32 index, s32 numplayers)
{
	return (g_MpChallenges[index].completions[numplayers] & 1) != 0;
}

void mpSetChallengeCompletedByAnyChrWithNumPlayers(s32 index, s32 numplayers, bool completed)
{
	if (completed) {
		g_MpChallenges[index].completions[numplayers] |= 1;
		return;
	}

	g_MpChallenges[index].completions[numplayers] &= ~1;
}

bool mpIsChallengeCompletedByChrWithNumPlayers(s32 mpchrnum, s32 index, s32 numplayers)
{
	return (g_MpChallenges[index].completions[numplayers] & (2 << mpchrnum)) != 0;
}

void mpSetChallengeCompletedByChrWithNumPlayers(u32 mpchrnum, s32 index, s32 numplayers, bool completed)
{
	if (completed) {
		g_MpChallenges[index].completions[numplayers] |= 2 << mpchrnum;
		return;
	}

	g_MpChallenges[index].completions[numplayers] &= ~(2 << mpchrnum);
}

GLOBAL_ASM(
glabel func0f19c53c
/*  f19c53c:	27bdfec0 */ 	addiu	$sp,$sp,-320
/*  f19c540:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f19c544:	3c10800a */ 	lui	$s0,%hi(g_Vars)
/*  f19c548:	26109fc0 */ 	addiu	$s0,$s0,%lo(g_Vars)
/*  f19c54c:	8e0f006c */ 	lw	$t7,0x6c($s0)
/*  f19c550:	8e0e028c */ 	lw	$t6,0x28c($s0)
/*  f19c554:	afb20020 */ 	sw	$s2,0x20($sp)
/*  f19c558:	afb1001c */ 	sw	$s1,0x1c($sp)
/*  f19c55c:	afbf0024 */ 	sw	$ra,0x24($sp)
/*  f19c560:	afa00138 */ 	sw	$zero,0x138($sp)
/*  f19c564:	00009025 */ 	or	$s2,$zero,$zero
/*  f19c568:	00008825 */ 	or	$s1,$zero,$zero
/*  f19c56c:	11e00003 */ 	beqz	$t7,.L0f19c57c
/*  f19c570:	afae013c */ 	sw	$t6,0x13c($sp)
/*  f19c574:	10000002 */ 	beqz	$zero,.L0f19c580
/*  f19c578:	24050001 */ 	addiu	$a1,$zero,0x1
.L0f19c57c:
/*  f19c57c:	00002825 */ 	or	$a1,$zero,$zero
.L0f19c580:
/*  f19c580:	8e180068 */ 	lw	$t8,0x68($s0)
/*  f19c584:	00002025 */ 	or	$a0,$zero,$zero
/*  f19c588:	00001825 */ 	or	$v1,$zero,$zero
/*  f19c58c:	13000003 */ 	beqz	$t8,.L0f19c59c
/*  f19c590:	00000000 */ 	sll	$zero,$zero,0x0
/*  f19c594:	10000001 */ 	beqz	$zero,.L0f19c59c
/*  f19c598:	24040001 */ 	addiu	$a0,$zero,0x1
.L0f19c59c:
/*  f19c59c:	8e190064 */ 	lw	$t9,0x64($s0)
/*  f19c5a0:	00001025 */ 	or	$v0,$zero,$zero
/*  f19c5a4:	13200003 */ 	beqz	$t9,.L0f19c5b4
/*  f19c5a8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f19c5ac:	10000001 */ 	beqz	$zero,.L0f19c5b4
/*  f19c5b0:	24030001 */ 	addiu	$v1,$zero,0x1
.L0f19c5b4:
/*  f19c5b4:	8e080070 */ 	lw	$t0,0x70($s0)
/*  f19c5b8:	11000003 */ 	beqz	$t0,.L0f19c5c8
/*  f19c5bc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f19c5c0:	10000001 */ 	beqz	$zero,.L0f19c5c8
/*  f19c5c4:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f19c5c8:
/*  f19c5c8:	00434821 */ 	addu	$t1,$v0,$v1
/*  f19c5cc:	01245021 */ 	addu	$t2,$t1,$a0
/*  f19c5d0:	01455821 */ 	addu	$t3,$t2,$a1
/*  f19c5d4:	19600027 */ 	blez	$t3,.L0f19c674
/*  f19c5d8:	00000000 */ 	sll	$zero,$zero,0x0
.L0f19c5dc:
/*  f19c5dc:	0fc4a24b */ 	jal	setCurrentPlayerNum
/*  f19c5e0:	02202025 */ 	or	$a0,$s1,$zero
/*  f19c5e4:	8e0c0284 */ 	lw	$t4,0x284($s0)
/*  f19c5e8:	00002825 */ 	or	$a1,$zero,$zero
/*  f19c5ec:	00002025 */ 	or	$a0,$zero,$zero
/*  f19c5f0:	8d8d048c */ 	lw	$t5,0x48c($t4)
/*  f19c5f4:	00001825 */ 	or	$v1,$zero,$zero
/*  f19c5f8:	00001025 */ 	or	$v0,$zero,$zero
/*  f19c5fc:	51a00003 */ 	beqzl	$t5,.L0f19c60c
/*  f19c600:	8e0e006c */ 	lw	$t6,0x6c($s0)
/*  f19c604:	24120001 */ 	addiu	$s2,$zero,0x1
/*  f19c608:	8e0e006c */ 	lw	$t6,0x6c($s0)
.L0f19c60c:
/*  f19c60c:	26310001 */ 	addiu	$s1,$s1,0x1
/*  f19c610:	11c00003 */ 	beqz	$t6,.L0f19c620
/*  f19c614:	00000000 */ 	sll	$zero,$zero,0x0
/*  f19c618:	10000001 */ 	beqz	$zero,.L0f19c620
/*  f19c61c:	24050001 */ 	addiu	$a1,$zero,0x1
.L0f19c620:
/*  f19c620:	8e0f0068 */ 	lw	$t7,0x68($s0)
/*  f19c624:	11e00003 */ 	beqz	$t7,.L0f19c634
/*  f19c628:	00000000 */ 	sll	$zero,$zero,0x0
/*  f19c62c:	10000001 */ 	beqz	$zero,.L0f19c634
/*  f19c630:	24040001 */ 	addiu	$a0,$zero,0x1
.L0f19c634:
/*  f19c634:	8e180064 */ 	lw	$t8,0x64($s0)
/*  f19c638:	13000003 */ 	beqz	$t8,.L0f19c648
/*  f19c63c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f19c640:	10000001 */ 	beqz	$zero,.L0f19c648
/*  f19c644:	24030001 */ 	addiu	$v1,$zero,0x1
.L0f19c648:
/*  f19c648:	8e190070 */ 	lw	$t9,0x70($s0)
/*  f19c64c:	13200003 */ 	beqz	$t9,.L0f19c65c
/*  f19c650:	00000000 */ 	sll	$zero,$zero,0x0
/*  f19c654:	10000001 */ 	beqz	$zero,.L0f19c65c
/*  f19c658:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f19c65c:
/*  f19c65c:	00434021 */ 	addu	$t0,$v0,$v1
/*  f19c660:	01044821 */ 	addu	$t1,$t0,$a0
/*  f19c664:	01255021 */ 	addu	$t2,$t1,$a1
/*  f19c668:	022a082a */ 	slt	$at,$s1,$t2
/*  f19c66c:	1420ffdb */ 	bnez	$at,.L0f19c5dc
/*  f19c670:	00000000 */ 	sll	$zero,$zero,0x0
.L0f19c674:
/*  f19c674:	0fc4a24b */ 	jal	setCurrentPlayerNum
/*  f19c678:	8fa4013c */ 	lw	$a0,0x13c($sp)
/*  f19c67c:	56400009 */ 	bnezl	$s2,.L0f19c6a4
/*  f19c680:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*  f19c684:	0fc622a1 */ 	jal	func0f188a84
/*  f19c688:	27a4003c */ 	addiu	$a0,$sp,0x3c
/*  f19c68c:	8fab0040 */ 	lw	$t3,0x40($sp)
/*  f19c690:	240c0001 */ 	addiu	$t4,$zero,0x1
/*  f19c694:	55600003 */ 	bnezl	$t3,.L0f19c6a4
/*  f19c698:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*  f19c69c:	afac0138 */ 	sw	$t4,0x138($sp)
/*  f19c6a0:	8fbf0024 */ 	lw	$ra,0x24($sp)
.L0f19c6a4:
/*  f19c6a4:	8fa20138 */ 	lw	$v0,0x138($sp)
/*  f19c6a8:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f19c6ac:	8fb1001c */ 	lw	$s1,0x1c($sp)
/*  f19c6b0:	8fb20020 */ 	lw	$s2,0x20($sp)
/*  f19c6b4:	03e00008 */ 	jr	$ra
/*  f19c6b8:	27bd0140 */ 	addiu	$sp,$sp,0x140
);

/**
 * This uses about 256 extra bytes of stack and passes it to func0f188a84.
 * Should decompile func0f188a84 first.
 */
//bool func0f19c53c(void)
//{
//	bool result = false;
//	bool aborting = false;
//	s32 i;
//	u32 prevplayernum = g_Vars.currentplayernum;
//
//	for (i = 0; i < PLAYERCOUNT(); i++) {
//		setCurrentPlayerNum(i);
//
//		if (g_Vars.currentplayer->aborted) {
//			aborting = true;
//		}
//	}
//
//	setCurrentPlayerNum(prevplayernum);
//
//	if (!aborting && func0f188a84() == 0) {
//		result = true;
//	}
//
//	return result;
//}

void mpConsiderMarkingCurrentChallengeComplete(void)
{
	bool result = func0f19c53c();

	if (g_CheatsActiveBank0 == 0 && g_CheatsActiveBank1 == 0 && result) {
		u32 prevplayernum;
		s32 i;

		mpSetChallengeCompletedByAnyChrWithNumPlayers(g_MpChallengeIndex, PLAYERCOUNT(), 1);
		prevplayernum = g_Vars.currentplayernum;

		for (i = 0; i < PLAYERCOUNT(); i++) {
			setCurrentPlayerNum(i);
			mpSetChallengeCompletedByChrWithNumPlayers(g_Vars.unk000288->mpchrnum, g_MpChallengeIndex, PLAYERCOUNT(), true);
		}

		setCurrentPlayerNum(prevplayernum);
		func0f19afdc();
	}
}

bool mpIsChallengeComplete(s32 challenge)
{
	if (challenge == 0) {
		return true;
	}

	return (g_MpChallengesCompleted[challenge] & 1) != 0;
}

bool mpIsChallengeCompleteWithNumPlayers(u32 numplayers, s32 challenge)
{
	if (challenge == 0) {
		return true;
	}

	return (g_MpChallengesCompleted[challenge] & (2 << numplayers)) != 0;
}

bool func0f19c96c(s32 challenge)
{
	if (challenge) {
		return false;
	}

	return true;
}
