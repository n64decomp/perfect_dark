#include <ultra64.h>
#include "constants.h"
#include "game/cheats.h"
#include "game/data/data_000000.h"
#include "game/data/data_0083d0.h"
#include "game/data/data_0160b0.h"
#include "game/data/data_020df0.h"
#include "game/game_066310.h"
#include "game/game_097ba0.h"
#include "game/game_0b63b0.h"
#include "game/game_127910.h"
#include "gvars/gvars.h"
#include "lib/lib_121e0.h"
#include "lib/lib_12dc0.h"
#include "types.h"

GLOBAL_ASM(
glabel func0f127910
/*  f127910:	3c013f80 */ 	lui	$at,0x3f80
/*  f127914:	3c03800a */ 	lui	$v1,%hi(g_Vars)
/*  f127918:	3c02800a */ 	lui	$v0,0x800a
/*  f12791c:	44810000 */ 	mtc1	$at,$f0
/*  f127920:	2442a1c0 */ 	addiu	$v0,$v0,-24128
/*  f127924:	24639fc0 */ 	addiu	$v1,$v1,%lo(g_Vars)
.L0f127928:
/*  f127928:	24630080 */ 	addiu	$v1,$v1,0x80
/*  f12792c:	1462fffe */ 	bne	$v1,$v0,.L0f127928
/*  f127930:	e4600050 */ 	swc1	$f0,0x50($v1)
/*  f127934:	3c02800a */ 	lui	$v0,%hi(g_Vars)
/*  f127938:	24429fc0 */ 	addiu	$v0,$v0,%lo(g_Vars)
/*  f12793c:	2403ffff */ 	addiu	$v1,$zero,-1
/*  f127940:	ac400294 */ 	sw	$zero,0x294($v0)
/*  f127944:	ac430298 */ 	sw	$v1,0x298($v0)
/*  f127948:	03e00008 */ 	jr	$ra
/*  f12794c:	ac43029c */ 	sw	$v1,0x29c($v0)
);

GLOBAL_ASM(
glabel func0f127950
/*  f127950:	3c02800a */ 	lui	$v0,%hi(g_Vars)
/*  f127954:	24429fc0 */ 	addiu	$v0,$v0,%lo(g_Vars)
/*  f127958:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f12795c:	240f0002 */ 	addiu	$t7,$zero,0x2
/*  f127960:	24180003 */ 	addiu	$t8,$zero,0x3
/*  f127964:	ac400064 */ 	sw	$zero,0x64($v0)
/*  f127968:	ac400068 */ 	sw	$zero,0x68($v0)
/*  f12796c:	ac40006c */ 	sw	$zero,0x6c($v0)
/*  f127970:	ac400070 */ 	sw	$zero,0x70($v0)
/*  f127974:	ac400284 */ 	sw	$zero,0x284($v0)
/*  f127978:	ac400290 */ 	sw	$zero,0x290($v0)
/*  f12797c:	ac400288 */ 	sw	$zero,0x288($v0)
/*  f127980:	ac40028c */ 	sw	$zero,0x28c($v0)
/*  f127984:	ac400274 */ 	sw	$zero,0x274($v0)
/*  f127988:	ac4e0278 */ 	sw	$t6,0x278($v0)
/*  f12798c:	ac4f027c */ 	sw	$t7,0x27c($v0)
/*  f127990:	ac580280 */ 	sw	$t8,0x280($v0)
/*  f127994:	ac4002a0 */ 	sw	$zero,0x2a0($v0)
/*  f127998:	ac4002a4 */ 	sw	$zero,0x2a4($v0)
/*  f12799c:	03e00008 */ 	jr	$ra
/*  f1279a0:	ac4002a8 */ 	sw	$zero,0x2a8($v0)
);

GLOBAL_ASM(
glabel func0f1279a4
/*  f1279a4:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*  f1279a8:	afb20020 */ 	sw	$s2,0x20($sp)
/*  f1279ac:	3c12800a */ 	lui	$s2,%hi(g_Vars)
/*  f1279b0:	26529fc0 */ 	addiu	$s2,$s2,%lo(g_Vars)
/*  f1279b4:	afb1001c */ 	sw	$s1,0x1c($sp)
/*  f1279b8:	00808825 */ 	or	$s1,$a0,$zero
/*  f1279bc:	afbf0024 */ 	sw	$ra,0x24($sp)
/*  f1279c0:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f1279c4:	ae400064 */ 	sw	$zero,0x64($s2)
/*  f1279c8:	ae400068 */ 	sw	$zero,0x68($s2)
/*  f1279cc:	ae40006c */ 	sw	$zero,0x6c($s2)
/*  f1279d0:	1880001f */ 	blez	$a0,.L0f127a50
/*  f1279d4:	ae400070 */ 	sw	$zero,0x70($s2)
/*  f1279d8:	18800006 */ 	blez	$a0,.L0f1279f4
/*  f1279dc:	00008025 */ 	or	$s0,$zero,$zero
.L0f1279e0:
/*  f1279e0:	0fc49eb9 */ 	jal	func0f127ae4
/*  f1279e4:	02002025 */ 	or	$a0,$s0,$zero
/*  f1279e8:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f1279ec:	1611fffc */ 	bne	$s0,$s1,.L0f1279e0
/*  f1279f0:	00000000 */ 	sll	$zero,$zero,0x0
.L0f1279f4:
/*  f1279f4:	0fc4a24b */ 	jal	setCurrentPlayerNum
/*  f1279f8:	00002025 */ 	or	$a0,$zero,$zero
/*  f1279fc:	8e4e0294 */ 	lw	$t6,0x294($s2)
/*  f127a00:	8e420298 */ 	lw	$v0,0x298($s2)
/*  f127a04:	000e7880 */ 	sll	$t7,$t6,0x2
/*  f127a08:	024fc021 */ 	addu	$t8,$s2,$t7
/*  f127a0c:	8f190064 */ 	lw	$t9,0x64($t8)
/*  f127a10:	00024080 */ 	sll	$t0,$v0,0x2
/*  f127a14:	04400006 */ 	bltz	$v0,.L0f127a30
/*  f127a18:	ae5902a0 */ 	sw	$t9,0x2a0($s2)
/*  f127a1c:	02484821 */ 	addu	$t1,$s2,$t0
/*  f127a20:	8d2a0064 */ 	lw	$t2,0x64($t1)
/*  f127a24:	ae4002a8 */ 	sw	$zero,0x2a8($s2)
/*  f127a28:	10000028 */ 	beqz	$zero,.L0f127acc
/*  f127a2c:	ae4a02a4 */ 	sw	$t2,0x2a4($s2)
.L0f127a30:
/*  f127a30:	8e42029c */ 	lw	$v0,0x29c($s2)
/*  f127a34:	04400025 */ 	bltz	$v0,.L0f127acc
/*  f127a38:	00025880 */ 	sll	$t3,$v0,0x2
/*  f127a3c:	ae4002a4 */ 	sw	$zero,0x2a4($s2)
/*  f127a40:	024b6021 */ 	addu	$t4,$s2,$t3
/*  f127a44:	8d8d0064 */ 	lw	$t5,0x64($t4)
/*  f127a48:	10000020 */ 	beqz	$zero,.L0f127acc
/*  f127a4c:	ae4d02a8 */ 	sw	$t5,0x2a8($s2)
.L0f127a50:
/*  f127a50:	0fc49eb9 */ 	jal	func0f127ae4
/*  f127a54:	00002025 */ 	or	$a0,$zero,$zero
/*  f127a58:	0fc4a24b */ 	jal	setCurrentPlayerNum
/*  f127a5c:	00002025 */ 	or	$a0,$zero,$zero
/*  f127a60:	924e04e0 */ 	lbu	$t6,0x4e0($s2)
/*  f127a64:	11c0000c */ 	beqz	$t6,.L0f127a98
/*  f127a68:	00000000 */ 	sll	$zero,$zero,0x0
/*  f127a6c:	0fc2f113 */ 	jal	func0f0bc44c
/*  f127a70:	00000000 */ 	sll	$zero,$zero,0x0
/*  f127a74:	00028400 */ 	sll	$s0,$v0,0x10
/*  f127a78:	00107c03 */ 	sra	$t7,$s0,0x10
/*  f127a7c:	0fc2f11e */ 	jal	func0f0bc478
/*  f127a80:	01e08025 */ 	or	$s0,$t7,$zero
/*  f127a84:	02002025 */ 	or	$a0,$s0,$zero
/*  f127a88:	0fc4a2a7 */ 	jal	func0f128a9c
/*  f127a8c:	00022840 */ 	sll	$a1,$v0,0x1
/*  f127a90:	1000000b */ 	beqz	$zero,.L0f127ac0
/*  f127a94:	8e590064 */ 	lw	$t9,0x64($s2)
.L0f127a98:
/*  f127a98:	0fc2f113 */ 	jal	func0f0bc44c
/*  f127a9c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f127aa0:	00028400 */ 	sll	$s0,$v0,0x10
/*  f127aa4:	0010c403 */ 	sra	$t8,$s0,0x10
/*  f127aa8:	0fc2f11e */ 	jal	func0f0bc478
/*  f127aac:	03008025 */ 	or	$s0,$t8,$zero
/*  f127ab0:	02002025 */ 	or	$a0,$s0,$zero
/*  f127ab4:	0fc4a2a7 */ 	jal	func0f128a9c
/*  f127ab8:	00402825 */ 	or	$a1,$v0,$zero
/*  f127abc:	8e590064 */ 	lw	$t9,0x64($s2)
.L0f127ac0:
/*  f127ac0:	ae4002a4 */ 	sw	$zero,0x2a4($s2)
/*  f127ac4:	ae4002a8 */ 	sw	$zero,0x2a8($s2)
/*  f127ac8:	ae5902a0 */ 	sw	$t9,0x2a0($s2)
.L0f127acc:
/*  f127acc:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*  f127ad0:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f127ad4:	8fb1001c */ 	lw	$s1,0x1c($sp)
/*  f127ad8:	8fb20020 */ 	lw	$s2,0x20($sp)
/*  f127adc:	03e00008 */ 	jr	$ra
/*  f127ae0:	27bd0028 */ 	addiu	$sp,$sp,0x28
);

GLOBAL_ASM(
glabel func0f127ae4
/*  f127ae4:	27bdf838 */ 	addiu	$sp,$sp,-1992
/*  f127ae8:	3c0f8008 */ 	lui	$t7,%hi(var8007dc10)
/*  f127aec:	25efdc10 */ 	addiu	$t7,$t7,%lo(var8007dc10)
/*  f127af0:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f127af4:	afa407c8 */ 	sw	$a0,0x7c8($sp)
/*  f127af8:	25eb07a4 */ 	addiu	$t3,$t7,0x7a4
/*  f127afc:	27ae0024 */ 	addiu	$t6,$sp,0x24
.L0f127b00:
/*  f127b00:	8de10000 */ 	lw	$at,0x0($t7)
/*  f127b04:	25ef000c */ 	addiu	$t7,$t7,0xc
/*  f127b08:	25ce000c */ 	addiu	$t6,$t6,0xc
/*  f127b0c:	adc1fff4 */ 	sw	$at,-0xc($t6)
/*  f127b10:	8de1fff8 */ 	lw	$at,-0x8($t7)
/*  f127b14:	adc1fff8 */ 	sw	$at,-0x8($t6)
/*  f127b18:	8de1fffc */ 	lw	$at,-0x4($t7)
/*  f127b1c:	15ebfff8 */ 	bne	$t7,$t3,.L0f127b00
/*  f127b20:	adc1fffc */ 	sw	$at,-0x4($t6)
/*  f127b24:	24041c70 */ 	addiu	$a0,$zero,0x1c70
/*  f127b28:	0c0048f2 */ 	jal	malloc
/*  f127b2c:	24050004 */ 	addiu	$a1,$zero,0x4
/*  f127b30:	8fac07c8 */ 	lw	$t4,0x7c8($sp)
/*  f127b34:	3c09800a */ 	lui	$t1,%hi(g_Vars)
/*  f127b38:	25299fc0 */ 	addiu	$t1,$t1,%lo(g_Vars)
/*  f127b3c:	000c6880 */ 	sll	$t5,$t4,0x2
/*  f127b40:	012d1821 */ 	addu	$v1,$t1,$t5
/*  f127b44:	ac620064 */ 	sw	$v0,0x64($v1)
/*  f127b48:	ac400000 */ 	sw	$zero,0x0($v0)
/*  f127b4c:	44800000 */ 	mtc1	$zero,$f0
/*  f127b50:	8c790064 */ 	lw	$t9,0x64($v1)
/*  f127b54:	2408ffff */ 	addiu	$t0,$zero,-1
/*  f127b58:	24070001 */ 	addiu	$a3,$zero,0x1
/*  f127b5c:	e7200004 */ 	swc1	$f0,0x4($t9)
/*  f127b60:	8c780064 */ 	lw	$t8,0x64($v1)
/*  f127b64:	3c013f80 */ 	lui	$at,0x3f80
/*  f127b68:	44811000 */ 	mtc1	$at,$f2
/*  f127b6c:	e7000008 */ 	swc1	$f0,0x8($t8)
/*  f127b70:	8c6b0064 */ 	lw	$t3,0x64($v1)
/*  f127b74:	3c01bf80 */ 	lui	$at,0xbf80
/*  f127b78:	44817000 */ 	mtc1	$at,$f14
/*  f127b7c:	e560000c */ 	swc1	$f0,0xc($t3)
/*  f127b80:	8c6f0064 */ 	lw	$t7,0x64($v1)
/*  f127b84:	3c01c080 */ 	lui	$at,0xc080
/*  f127b88:	44812000 */ 	mtc1	$at,$f4
/*  f127b8c:	ade80014 */ 	sw	$t0,0x14($t7)
/*  f127b90:	8c6e0064 */ 	lw	$t6,0x64($v1)
/*  f127b94:	3c017f1b */ 	lui	$at,%hi(var7f1b5150)
/*  f127b98:	240200ff */ 	addiu	$v0,$zero,0xff
/*  f127b9c:	e5c01bb0 */ 	swc1	$f0,0x1bb0($t6)
/*  f127ba0:	8c6c0064 */ 	lw	$t4,0x64($v1)
/*  f127ba4:	27aa0024 */ 	addiu	$t2,$sp,0x24
/*  f127ba8:	e5801bb4 */ 	swc1	$f0,0x1bb4($t4)
/*  f127bac:	8c6d0064 */ 	lw	$t5,0x64($v1)
/*  f127bb0:	e5a01bb8 */ 	swc1	$f0,0x1bb8($t5)
/*  f127bb4:	8c790064 */ 	lw	$t9,0x64($v1)
/*  f127bb8:	af271ba0 */ 	sw	$a3,0x1ba0($t9)
/*  f127bbc:	8c780064 */ 	lw	$t8,0x64($v1)
/*  f127bc0:	e7000038 */ 	swc1	$f0,0x38($t8)
/*  f127bc4:	8c6b0064 */ 	lw	$t3,0x64($v1)
/*  f127bc8:	e560003c */ 	swc1	$f0,0x3c($t3)
/*  f127bcc:	8c6f0064 */ 	lw	$t7,0x64($v1)
/*  f127bd0:	e5e00040 */ 	swc1	$f0,0x40($t7)
/*  f127bd4:	8c6e0064 */ 	lw	$t6,0x64($v1)
/*  f127bd8:	e5c00044 */ 	swc1	$f0,0x44($t6)
/*  f127bdc:	8c6c0064 */ 	lw	$t4,0x64($v1)
/*  f127be0:	e5800048 */ 	swc1	$f0,0x48($t4)
/*  f127be4:	8c6d0064 */ 	lw	$t5,0x64($v1)
/*  f127be8:	e5a0004c */ 	swc1	$f0,0x4c($t5)
/*  f127bec:	8c790064 */ 	lw	$t9,0x64($v1)
/*  f127bf0:	e7200050 */ 	swc1	$f0,0x50($t9)
/*  f127bf4:	8c780064 */ 	lw	$t8,0x64($v1)
/*  f127bf8:	24190003 */ 	addiu	$t9,$zero,0x3
/*  f127bfc:	e7000054 */ 	swc1	$f0,0x54($t8)
/*  f127c00:	8c6b0064 */ 	lw	$t3,0x64($v1)
/*  f127c04:	e5600058 */ 	swc1	$f0,0x58($t3)
/*  f127c08:	8c6f0064 */ 	lw	$t7,0x64($v1)
/*  f127c0c:	240b0014 */ 	addiu	$t3,$zero,0x14
/*  f127c10:	e5e00074 */ 	swc1	$f0,0x74($t7)
/*  f127c14:	8c6e0064 */ 	lw	$t6,0x64($v1)
/*  f127c18:	e5c00078 */ 	swc1	$f0,0x78($t6)
/*  f127c1c:	8c6c0064 */ 	lw	$t4,0x64($v1)
/*  f127c20:	ad8000bc */ 	sw	$zero,0xbc($t4)
/*  f127c24:	8c6d0064 */ 	lw	$t5,0x64($v1)
/*  f127c28:	ada700c0 */ 	sw	$a3,0xc0($t5)
/*  f127c2c:	8c780064 */ 	lw	$t8,0x64($v1)
/*  f127c30:	a31919cc */ 	sb	$t9,0x19cc($t8)
/*  f127c34:	8c6f0064 */ 	lw	$t7,0x64($v1)
/*  f127c38:	a5eb19ce */ 	sh	$t3,0x19ce($t7)
/*  f127c3c:	8c6e0064 */ 	lw	$t6,0x64($v1)
/*  f127c40:	e5c019d0 */ 	swc1	$f0,0x19d0($t6)
/*  f127c44:	8c6c0064 */ 	lw	$t4,0x64($v1)
/*  f127c48:	e58019d4 */ 	swc1	$f0,0x19d4($t4)
/*  f127c4c:	8c6d0064 */ 	lw	$t5,0x64($v1)
/*  f127c50:	e5a019d8 */ 	swc1	$f0,0x19d8($t5)
/*  f127c54:	8c790064 */ 	lw	$t9,0x64($v1)
/*  f127c58:	e72019dc */ 	swc1	$f0,0x19dc($t9)
/*  f127c5c:	8c780064 */ 	lw	$t8,0x64($v1)
/*  f127c60:	e70019e0 */ 	swc1	$f0,0x19e0($t8)
/*  f127c64:	8c6b0064 */ 	lw	$t3,0x64($v1)
/*  f127c68:	ad6000d0 */ 	sw	$zero,0xd0($t3)
/*  f127c6c:	8c6f0064 */ 	lw	$t7,0x64($v1)
/*  f127c70:	ade000d4 */ 	sw	$zero,0xd4($t7)
/*  f127c74:	8c6e0064 */ 	lw	$t6,0x64($v1)
/*  f127c78:	adc000d8 */ 	sw	$zero,0xd8($t6)
/*  f127c7c:	8c6c0064 */ 	lw	$t4,0x64($v1)
/*  f127c80:	ad80048c */ 	sw	$zero,0x48c($t4)
/*  f127c84:	8c6d0064 */ 	lw	$t5,0x64($v1)
/*  f127c88:	e5a200dc */ 	swc1	$f2,0xdc($t5)
/*  f127c8c:	8c790064 */ 	lw	$t9,0x64($v1)
/*  f127c90:	e72e1c5c */ 	swc1	$f14,0x1c5c($t9)
/*  f127c94:	8c780064 */ 	lw	$t8,0x64($v1)
/*  f127c98:	e70200e4 */ 	swc1	$f2,0xe4($t8)
/*  f127c9c:	8c6b0064 */ 	lw	$t3,0x64($v1)
/*  f127ca0:	e56000e8 */ 	swc1	$f0,0xe8($t3)
/*  f127ca4:	8c6f0064 */ 	lw	$t7,0x64($v1)
/*  f127ca8:	e5e200ec */ 	swc1	$f2,0xec($t7)
/*  f127cac:	8c6e0064 */ 	lw	$t6,0x64($v1)
/*  f127cb0:	e5c000f0 */ 	swc1	$f0,0xf0($t6)
/*  f127cb4:	8c6c0064 */ 	lw	$t4,0x64($v1)
/*  f127cb8:	e58e00f4 */ 	swc1	$f14,0xf4($t4)
/*  f127cbc:	8c6d0064 */ 	lw	$t5,0x64($v1)
/*  f127cc0:	e5ae00f8 */ 	swc1	$f14,0xf8($t5)
/*  f127cc4:	8c790064 */ 	lw	$t9,0x64($v1)
/*  f127cc8:	e72e0280 */ 	swc1	$f14,0x280($t9)
/*  f127ccc:	8c780064 */ 	lw	$t8,0x64($v1)
/*  f127cd0:	af0000fc */ 	sw	$zero,0xfc($t8)
/*  f127cd4:	8c6b0064 */ 	lw	$t3,0x64($v1)
/*  f127cd8:	ad600100 */ 	sw	$zero,0x100($t3)
/*  f127cdc:	8c6f0064 */ 	lw	$t7,0x64($v1)
/*  f127ce0:	ade00104 */ 	sw	$zero,0x104($t7)
/*  f127ce4:	8c6e0064 */ 	lw	$t6,0x64($v1)
/*  f127ce8:	adc00108 */ 	sw	$zero,0x108($t6)
/*  f127cec:	8c6c0064 */ 	lw	$t4,0x64($v1)
/*  f127cf0:	ad80010c */ 	sw	$zero,0x10c($t4)
/*  f127cf4:	8c6d0064 */ 	lw	$t5,0x64($v1)
/*  f127cf8:	ada70110 */ 	sw	$a3,0x110($t5)
/*  f127cfc:	8c790064 */ 	lw	$t9,0x64($v1)
/*  f127d00:	af270114 */ 	sw	$a3,0x114($t9)
/*  f127d04:	8c780064 */ 	lw	$t8,0x64($v1)
/*  f127d08:	af000118 */ 	sw	$zero,0x118($t8)
/*  f127d0c:	8c6b0064 */ 	lw	$t3,0x64($v1)
/*  f127d10:	ad67011c */ 	sw	$a3,0x11c($t3)
/*  f127d14:	8c6f0064 */ 	lw	$t7,0x64($v1)
/*  f127d18:	ade00120 */ 	sw	$zero,0x120($t7)
/*  f127d1c:	8c6e0064 */ 	lw	$t6,0x64($v1)
/*  f127d20:	adc70124 */ 	sw	$a3,0x124($t6)
/*  f127d24:	8c6c0064 */ 	lw	$t4,0x64($v1)
/*  f127d28:	e5800128 */ 	swc1	$f0,0x128($t4)
/*  f127d2c:	8c6d0064 */ 	lw	$t5,0x64($v1)
/*  f127d30:	ada0012c */ 	sw	$zero,0x12c($t5)
/*  f127d34:	8c790064 */ 	lw	$t9,0x64($v1)
/*  f127d38:	af280130 */ 	sw	$t0,0x130($t9)
/*  f127d3c:	8c780064 */ 	lw	$t8,0x64($v1)
/*  f127d40:	af070134 */ 	sw	$a3,0x134($t8)
/*  f127d44:	8c6b0064 */ 	lw	$t3,0x64($v1)
/*  f127d48:	e5600138 */ 	swc1	$f0,0x138($t3)
/*  f127d4c:	8c6f0064 */ 	lw	$t7,0x64($v1)
/*  f127d50:	ade0013c */ 	sw	$zero,0x13c($t7)
/*  f127d54:	8c6e0064 */ 	lw	$t6,0x64($v1)
/*  f127d58:	adc80140 */ 	sw	$t0,0x140($t6)
/*  f127d5c:	8c6c0064 */ 	lw	$t4,0x64($v1)
/*  f127d60:	e5800144 */ 	swc1	$f0,0x144($t4)
/*  f127d64:	8c6d0064 */ 	lw	$t5,0x64($v1)
/*  f127d68:	e5a00148 */ 	swc1	$f0,0x148($t5)
/*  f127d6c:	8c790064 */ 	lw	$t9,0x64($v1)
/*  f127d70:	e7201b9c */ 	swc1	$f0,0x1b9c($t9)
/*  f127d74:	8c780064 */ 	lw	$t8,0x64($v1)
/*  f127d78:	e702014c */ 	swc1	$f2,0x14c($t8)
/*  f127d7c:	8c6b0064 */ 	lw	$t3,0x64($v1)
/*  f127d80:	e5600150 */ 	swc1	$f0,0x150($t3)
/*  f127d84:	8c6f0064 */ 	lw	$t7,0x64($v1)
/*  f127d88:	e5e40154 */ 	swc1	$f4,0x154($t7)
/*  f127d8c:	8c6e0064 */ 	lw	$t6,0x64($v1)
/*  f127d90:	c4265150 */ 	lwc1	$f6,%lo(var7f1b5150)($at)
/*  f127d94:	3c017f1b */ 	lui	$at,%hi(var7f1b5154)
/*  f127d98:	e5c60158 */ 	swc1	$f6,0x158($t6)
/*  f127d9c:	8c6c0064 */ 	lw	$t4,0x64($v1)
/*  f127da0:	e580015c */ 	swc1	$f0,0x15c($t4)
/*  f127da4:	8c6d0064 */ 	lw	$t5,0x64($v1)
/*  f127da8:	e5a20160 */ 	swc1	$f2,0x160($t5)
/*  f127dac:	8c790064 */ 	lw	$t9,0x64($v1)
/*  f127db0:	e7200164 */ 	swc1	$f0,0x164($t9)
/*  f127db4:	8c780064 */ 	lw	$t8,0x64($v1)
/*  f127db8:	e70e0188 */ 	swc1	$f14,0x188($t8)
/*  f127dbc:	8c6b0064 */ 	lw	$t3,0x64($v1)
/*  f127dc0:	e56e018c */ 	swc1	$f14,0x18c($t3)
/*  f127dc4:	8c6f0064 */ 	lw	$t7,0x64($v1)
/*  f127dc8:	e5e00190 */ 	swc1	$f0,0x190($t7)
/*  f127dcc:	8c6e0064 */ 	lw	$t6,0x64($v1)
/*  f127dd0:	e5c00194 */ 	swc1	$f0,0x194($t6)
/*  f127dd4:	8c6c0064 */ 	lw	$t4,0x64($v1)
/*  f127dd8:	e5800198 */ 	swc1	$f0,0x198($t4)
/*  f127ddc:	8c6d0064 */ 	lw	$t5,0x64($v1)
/*  f127de0:	ada701bc */ 	sw	$a3,0x1bc($t5)
/*  f127de4:	8c790064 */ 	lw	$t9,0x64($v1)
/*  f127de8:	af2202d8 */ 	sw	$v0,0x2d8($t9)
/*  f127dec:	8c780064 */ 	lw	$t8,0x64($v1)
/*  f127df0:	af0202dc */ 	sw	$v0,0x2dc($t8)
/*  f127df4:	8c6b0064 */ 	lw	$t3,0x64($v1)
/*  f127df8:	ad6202e0 */ 	sw	$v0,0x2e0($t3)
/*  f127dfc:	8c6f0064 */ 	lw	$t7,0x64($v1)
/*  f127e00:	e5e002e4 */ 	swc1	$f0,0x2e4($t7)
/*  f127e04:	8c6e0064 */ 	lw	$t6,0x64($v1)
/*  f127e08:	e5ce02e8 */ 	swc1	$f14,0x2e8($t6)
/*  f127e0c:	8c6c0064 */ 	lw	$t4,0x64($v1)
/*  f127e10:	e58e02ec */ 	swc1	$f14,0x2ec($t4)
/*  f127e14:	8c6d0064 */ 	lw	$t5,0x64($v1)
/*  f127e18:	ada202f0 */ 	sw	$v0,0x2f0($t5)
/*  f127e1c:	8c790064 */ 	lw	$t9,0x64($v1)
/*  f127e20:	af2202f4 */ 	sw	$v0,0x2f4($t9)
/*  f127e24:	8c780064 */ 	lw	$t8,0x64($v1)
/*  f127e28:	af0202f8 */ 	sw	$v0,0x2f8($t8)
/*  f127e2c:	8c6b0064 */ 	lw	$t3,0x64($v1)
/*  f127e30:	ad6202fc */ 	sw	$v0,0x2fc($t3)
/*  f127e34:	8c6f0064 */ 	lw	$t7,0x64($v1)
/*  f127e38:	ade20300 */ 	sw	$v0,0x300($t7)
/*  f127e3c:	8c6e0064 */ 	lw	$t6,0x64($v1)
/*  f127e40:	adc20304 */ 	sw	$v0,0x304($t6)
/*  f127e44:	8c6c0064 */ 	lw	$t4,0x64($v1)
/*  f127e48:	240e0002 */ 	addiu	$t6,$zero,0x2
/*  f127e4c:	e5800308 */ 	swc1	$f0,0x308($t4)
/*  f127e50:	8c6d0064 */ 	lw	$t5,0x64($v1)
/*  f127e54:	e5a0030c */ 	swc1	$f0,0x30c($t5)
/*  f127e58:	8c790064 */ 	lw	$t9,0x64($v1)
/*  f127e5c:	af200324 */ 	sw	$zero,0x324($t9)
/*  f127e60:	8c780064 */ 	lw	$t8,0x64($v1)
/*  f127e64:	af070328 */ 	sw	$a3,0x328($t8)
/*  f127e68:	8c6b0064 */ 	lw	$t3,0x64($v1)
/*  f127e6c:	ad60032c */ 	sw	$zero,0x32c($t3)
/*  f127e70:	8c6f0064 */ 	lw	$t7,0x64($v1)
/*  f127e74:	ade00330 */ 	sw	$zero,0x330($t7)
/*  f127e78:	8c6c0064 */ 	lw	$t4,0x64($v1)
/*  f127e7c:	ad8e0334 */ 	sw	$t6,0x334($t4)
/*  f127e80:	8c6d0064 */ 	lw	$t5,0x64($v1)
/*  f127e84:	ada703a0 */ 	sw	$a3,0x3a0($t5)
/*  f127e88:	8c790064 */ 	lw	$t9,0x64($v1)
/*  f127e8c:	af2703a4 */ 	sw	$a3,0x3a4($t9)
/*  f127e90:	8c780064 */ 	lw	$t8,0x64($v1)
/*  f127e94:	af0703a8 */ 	sw	$a3,0x3a8($t8)
/*  f127e98:	8c6b0064 */ 	lw	$t3,0x64($v1)
/*  f127e9c:	c42c5154 */ 	lwc1	$f12,%lo(var7f1b5154)($at)
/*  f127ea0:	3c017f1b */ 	lui	$at,%hi(var7f1b5158)
/*  f127ea4:	ad6003ac */ 	sw	$zero,0x3ac($t3)
/*  f127ea8:	8c6f0064 */ 	lw	$t7,0x64($v1)
/*  f127eac:	c4285158 */ 	lwc1	$f8,%lo(var7f1b5158)($at)
/*  f127eb0:	e5e803b0 */ 	swc1	$f8,0x3b0($t7)
/*  f127eb4:	8c6e0064 */ 	lw	$t6,0x64($v1)
/*  f127eb8:	adc003b4 */ 	sw	$zero,0x3b4($t6)
/*  f127ebc:	8c6c0064 */ 	lw	$t4,0x64($v1)
/*  f127ec0:	e58203b8 */ 	swc1	$f2,0x3b8($t4)
/*  f127ec4:	8c6d0064 */ 	lw	$t5,0x64($v1)
/*  f127ec8:	e5a203bc */ 	swc1	$f2,0x3bc($t5)
/*  f127ecc:	8c790064 */ 	lw	$t9,0x64($v1)
/*  f127ed0:	e72003c0 */ 	swc1	$f0,0x3c0($t9)
/*  f127ed4:	8c780064 */ 	lw	$t8,0x64($v1)
/*  f127ed8:	e70003c4 */ 	swc1	$f0,0x3c4($t8)
/*  f127edc:	8c6b0064 */ 	lw	$t3,0x64($v1)
/*  f127ee0:	e56003c8 */ 	swc1	$f0,0x3c8($t3)
/*  f127ee4:	8c6f0064 */ 	lw	$t7,0x64($v1)
/*  f127ee8:	e5e003cc */ 	swc1	$f0,0x3cc($t7)
/*  f127eec:	8c6e0064 */ 	lw	$t6,0x64($v1)
/*  f127ef0:	e5c003d0 */ 	swc1	$f0,0x3d0($t6)
/*  f127ef4:	8c6c0064 */ 	lw	$t4,0x64($v1)
/*  f127ef8:	e58203d4 */ 	swc1	$f2,0x3d4($t4)
/*  f127efc:	8c6d0064 */ 	lw	$t5,0x64($v1)
/*  f127f00:	e5a003d8 */ 	swc1	$f0,0x3d8($t5)
/*  f127f04:	8c790064 */ 	lw	$t9,0x64($v1)
/*  f127f08:	e72203dc */ 	swc1	$f2,0x3dc($t9)
/*  f127f0c:	8c780064 */ 	lw	$t8,0x64($v1)
/*  f127f10:	e70003e0 */ 	swc1	$f0,0x3e0($t8)
/*  f127f14:	8c6b0064 */ 	lw	$t3,0x64($v1)
/*  f127f18:	e56003e4 */ 	swc1	$f0,0x3e4($t3)
/*  f127f1c:	8c6f0064 */ 	lw	$t7,0x64($v1)
/*  f127f20:	e5e003e8 */ 	swc1	$f0,0x3e8($t7)
/*  f127f24:	8c6e0064 */ 	lw	$t6,0x64($v1)
/*  f127f28:	e5c003ec */ 	swc1	$f0,0x3ec($t6)
/*  f127f2c:	8c6c0064 */ 	lw	$t4,0x64($v1)
/*  f127f30:	e58003f0 */ 	swc1	$f0,0x3f0($t4)
/*  f127f34:	8c6d0064 */ 	lw	$t5,0x64($v1)
/*  f127f38:	e5a003f4 */ 	swc1	$f0,0x3f4($t5)
/*  f127f3c:	8c790064 */ 	lw	$t9,0x64($v1)
/*  f127f40:	e72c03f8 */ 	swc1	$f12,0x3f8($t9)
/*  f127f44:	8c780064 */ 	lw	$t8,0x64($v1)
/*  f127f48:	e70003fc */ 	swc1	$f0,0x3fc($t8)
/*  f127f4c:	8c6b0064 */ 	lw	$t3,0x64($v1)
/*  f127f50:	e56c0400 */ 	swc1	$f12,0x400($t3)
/*  f127f54:	8c6f0064 */ 	lw	$t7,0x64($v1)
/*  f127f58:	e5e00404 */ 	swc1	$f0,0x404($t7)
/*  f127f5c:	8c6e0064 */ 	lw	$t6,0x64($v1)
/*  f127f60:	e5c00408 */ 	swc1	$f0,0x408($t6)
/*  f127f64:	8c6c0064 */ 	lw	$t4,0x64($v1)
/*  f127f68:	e580040c */ 	swc1	$f0,0x40c($t4)
/*  f127f6c:	8c6d0064 */ 	lw	$t5,0x64($v1)
/*  f127f70:	e5a00410 */ 	swc1	$f0,0x410($t5)
/*  f127f74:	8c790064 */ 	lw	$t9,0x64($v1)
/*  f127f78:	e7200414 */ 	swc1	$f0,0x414($t9)
/*  f127f7c:	8c780064 */ 	lw	$t8,0x64($v1)
/*  f127f80:	e7000418 */ 	swc1	$f0,0x418($t8)
/*  f127f84:	8c6b0064 */ 	lw	$t3,0x64($v1)
/*  f127f88:	e560041c */ 	swc1	$f0,0x41c($t3)
/*  f127f8c:	8c6f0064 */ 	lw	$t7,0x64($v1)
/*  f127f90:	e5e00420 */ 	swc1	$f0,0x420($t7)
/*  f127f94:	8c6e0064 */ 	lw	$t6,0x64($v1)
/*  f127f98:	00001025 */ 	or	$v0,$zero,$zero
/*  f127f9c:	240601ff */ 	addiu	$a2,$zero,0x1ff
/*  f127fa0:	e5c00424 */ 	swc1	$f0,0x424($t6)
/*  f127fa4:	8c6c0064 */ 	lw	$t4,0x64($v1)
/*  f127fa8:	240501e0 */ 	addiu	$a1,$zero,0x1e0
/*  f127fac:	24040280 */ 	addiu	$a0,$zero,0x280
/*  f127fb0:	e5800428 */ 	swc1	$f0,0x428($t4)
/*  f127fb4:	8c6d0064 */ 	lw	$t5,0x64($v1)
/*  f127fb8:	e5a0042c */ 	swc1	$f0,0x42c($t5)
/*  f127fbc:	8c790064 */ 	lw	$t9,0x64($v1)
/*  f127fc0:	e7220430 */ 	swc1	$f2,0x430($t9)
/*  f127fc4:	8c780064 */ 	lw	$t8,0x64($v1)
/*  f127fc8:	e7000434 */ 	swc1	$f0,0x434($t8)
/*  f127fcc:	8c6b0064 */ 	lw	$t3,0x64($v1)
/*  f127fd0:	e5600438 */ 	swc1	$f0,0x438($t3)
/*  f127fd4:	8c6f0064 */ 	lw	$t7,0x64($v1)
/*  f127fd8:	e5e2043c */ 	swc1	$f2,0x43c($t7)
/*  f127fdc:	8c6e0064 */ 	lw	$t6,0x64($v1)
/*  f127fe0:	e5c00440 */ 	swc1	$f0,0x440($t6)
/*  f127fe4:	8c6c0064 */ 	lw	$t4,0x64($v1)
/*  f127fe8:	e5820444 */ 	swc1	$f2,0x444($t4)
/*  f127fec:	8c6d0064 */ 	lw	$t5,0x64($v1)
/*  f127ff0:	e5a00448 */ 	swc1	$f0,0x448($t5)
/*  f127ff4:	8c790064 */ 	lw	$t9,0x64($v1)
/*  f127ff8:	e720044c */ 	swc1	$f0,0x44c($t9)
/*  f127ffc:	8c780064 */ 	lw	$t8,0x64($v1)
/*  f128000:	e7020450 */ 	swc1	$f2,0x450($t8)
/*  f128004:	8c6b0064 */ 	lw	$t3,0x64($v1)
/*  f128008:	e5600454 */ 	swc1	$f0,0x454($t3)
/*  f12800c:	8c6f0064 */ 	lw	$t7,0x64($v1)
/*  f128010:	ade00458 */ 	sw	$zero,0x458($t7)
/*  f128014:	8c6e0064 */ 	lw	$t6,0x64($v1)
/*  f128018:	adc000c4 */ 	sw	$zero,0xc4($t6)
/*  f12801c:	8c6c0064 */ 	lw	$t4,0x64($v1)
/*  f128020:	ad801c54 */ 	sw	$zero,0x1c54($t4)
/*  f128024:	8c6d0064 */ 	lw	$t5,0x64($v1)
/*  f128028:	a5a0161c */ 	sh	$zero,0x161c($t5)
.L0f12802c:
/*  f12802c:	8c790064 */ 	lw	$t9,0x64($v1)
/*  f128030:	0322c021 */ 	addu	$t8,$t9,$v0
/*  f128034:	a7040610 */ 	sh	$a0,0x610($t8)
/*  f128038:	8c6b0064 */ 	lw	$t3,0x64($v1)
/*  f12803c:	01627821 */ 	addu	$t7,$t3,$v0
/*  f128040:	a5e50612 */ 	sh	$a1,0x612($t7)
/*  f128044:	8c6e0064 */ 	lw	$t6,0x64($v1)
/*  f128048:	01c26021 */ 	addu	$t4,$t6,$v0
/*  f12804c:	a5860614 */ 	sh	$a2,0x614($t4)
/*  f128050:	8c6d0064 */ 	lw	$t5,0x64($v1)
/*  f128054:	01a2c821 */ 	addu	$t9,$t5,$v0
/*  f128058:	a7200616 */ 	sh	$zero,0x616($t9)
/*  f12805c:	8c780064 */ 	lw	$t8,0x64($v1)
/*  f128060:	03025821 */ 	addu	$t3,$t8,$v0
/*  f128064:	a5640618 */ 	sh	$a0,0x618($t3)
/*  f128068:	8c6f0064 */ 	lw	$t7,0x64($v1)
/*  f12806c:	01e27021 */ 	addu	$t6,$t7,$v0
/*  f128070:	a5c5061a */ 	sh	$a1,0x61a($t6)
/*  f128074:	8c6c0064 */ 	lw	$t4,0x64($v1)
/*  f128078:	01826821 */ 	addu	$t5,$t4,$v0
/*  f12807c:	a5a6061c */ 	sh	$a2,0x61c($t5)
/*  f128080:	8c790064 */ 	lw	$t9,0x64($v1)
/*  f128084:	0322c021 */ 	addu	$t8,$t9,$v0
/*  f128088:	24420010 */ 	addiu	$v0,$v0,0x10
/*  f12808c:	28410020 */ 	slti	$at,$v0,0x20
/*  f128090:	1420ffe6 */ 	bnez	$at,.L0f12802c
/*  f128094:	a700061e */ 	sh	$zero,0x61e($t8)
/*  f128098:	8c6b0064 */ 	lw	$t3,0x64($v1)
/*  f12809c:	24020064 */ 	addiu	$v0,$zero,0x64
/*  f1280a0:	a5620630 */ 	sh	$v0,0x630($t3)
/*  f1280a4:	8c6f0064 */ 	lw	$t7,0x64($v1)
/*  f1280a8:	a5e20632 */ 	sh	$v0,0x632($t7)
/*  f1280ac:	8c6e0064 */ 	lw	$t6,0x64($v1)
/*  f1280b0:	a5c00634 */ 	sh	$zero,0x634($t6)
/*  f1280b4:	8c6c0064 */ 	lw	$t4,0x64($v1)
/*  f1280b8:	a5800636 */ 	sh	$zero,0x636($t4)
/*  f1280bc:	8c6d0064 */ 	lw	$t5,0x64($v1)
/*  f1280c0:	ada00264 */ 	sw	$zero,0x264($t5)
/*  f1280c4:	8c790064 */ 	lw	$t9,0x64($v1)
/*  f1280c8:	af2000c8 */ 	sw	$zero,0xc8($t9)
/*  f1280cc:	8c780064 */ 	lw	$t8,0x64($v1)
/*  f1280d0:	24190002 */ 	addiu	$t9,$zero,0x2
/*  f1280d4:	af001588 */ 	sw	$zero,0x1588($t8)
/*  f1280d8:	8c6b0064 */ 	lw	$t3,0x64($v1)
/*  f1280dc:	ad60158c */ 	sw	$zero,0x158c($t3)
/*  f1280e0:	8c6f0064 */ 	lw	$t7,0x64($v1)
/*  f1280e4:	ade01590 */ 	sw	$zero,0x1590($t7)
/*  f1280e8:	8c6e0064 */ 	lw	$t6,0x64($v1)
/*  f1280ec:	a1c01580 */ 	sb	$zero,0x1580($t6)
/*  f1280f0:	8c6c0064 */ 	lw	$t4,0x64($v1)
/*  f1280f4:	a1881581 */ 	sb	$t0,0x1581($t4)
/*  f1280f8:	8c6d0064 */ 	lw	$t5,0x64($v1)
/*  f1280fc:	a1a81582 */ 	sb	$t0,0x1582($t5)
/*  f128100:	8c780064 */ 	lw	$t8,0x64($v1)
/*  f128104:	a31915ea */ 	sb	$t9,0x15ea($t8)
/*  f128108:	8c6b0064 */ 	lw	$t3,0x64($v1)
/*  f12810c:	255807a4 */ 	addiu	$t8,$t2,0x7a4
/*  f128110:	0140c825 */ 	or	$t9,$t2,$zero
/*  f128114:	a16015eb */ 	sb	$zero,0x15eb($t3)
/*  f128118:	8c6f0064 */ 	lw	$t7,0x64($v1)
/*  f12811c:	01405825 */ 	or	$t3,$t2,$zero
/*  f128120:	a1e015e6 */ 	sb	$zero,0x15e6($t7)
/*  f128124:	8c650064 */ 	lw	$a1,0x64($v1)
/*  f128128:	90ae1583 */ 	lbu	$t6,0x1583($a1)
/*  f12812c:	31ccfffe */ 	andi	$t4,$t6,0xfffe
/*  f128130:	a0ac1583 */ 	sb	$t4,0x1583($a1)
/*  f128134:	8c6d0064 */ 	lw	$t5,0x64($v1)
.L0f128138:
/*  f128138:	8d610000 */ 	lw	$at,0x0($t3)
/*  f12813c:	256b000c */ 	addiu	$t3,$t3,0xc
/*  f128140:	25ad000c */ 	addiu	$t5,$t5,0xc
/*  f128144:	ada1062c */ 	sw	$at,0x62c($t5)
/*  f128148:	8d61fff8 */ 	lw	$at,-0x8($t3)
/*  f12814c:	ada10630 */ 	sw	$at,0x630($t5)
/*  f128150:	8d61fffc */ 	lw	$at,-0x4($t3)
/*  f128154:	1578fff8 */ 	bne	$t3,$t8,.L0f128138
/*  f128158:	ada10634 */ 	sw	$at,0x634($t5)
/*  f12815c:	8c6f0064 */ 	lw	$t7,0x64($v1)
/*  f128160:	254c07a4 */ 	addiu	$t4,$t2,0x7a4
.L0f128164:
/*  f128164:	8f210000 */ 	lw	$at,0x0($t9)
/*  f128168:	2739000c */ 	addiu	$t9,$t9,0xc
/*  f12816c:	25ef000c */ 	addiu	$t7,$t7,0xc
/*  f128170:	ade10dd0 */ 	sw	$at,0xdd0($t7)
/*  f128174:	8f21fff8 */ 	lw	$at,-0x8($t9)
/*  f128178:	ade10dd4 */ 	sw	$at,0xdd4($t7)
/*  f12817c:	8f21fffc */ 	lw	$at,-0x4($t9)
/*  f128180:	172cfff8 */ 	bne	$t9,$t4,.L0f128164
/*  f128184:	ade10dd8 */ 	sw	$at,0xdd8($t7)
/*  f128188:	8c780064 */ 	lw	$t8,0x64($v1)
/*  f12818c:	240500ff */ 	addiu	$a1,$zero,0xff
/*  f128190:	00001025 */ 	or	$v0,$zero,$zero
/*  f128194:	e70215f8 */ 	swc1	$f2,0x15f8($t8)
/*  f128198:	8c6b0064 */ 	lw	$t3,0x64($v1)
/*  f12819c:	e56215fc */ 	swc1	$f2,0x15fc($t3)
/*  f1281a0:	8c6d0064 */ 	lw	$t5,0x64($v1)
/*  f1281a4:	ada01600 */ 	sw	$zero,0x1600($t5)
/*  f1281a8:	8c6e0064 */ 	lw	$t6,0x64($v1)
/*  f1281ac:	adc01604 */ 	sw	$zero,0x1604($t6)
/*  f1281b0:	8c6c0064 */ 	lw	$t4,0x64($v1)
/*  f1281b4:	ad801608 */ 	sw	$zero,0x1608($t4)
/*  f1281b8:	8c790064 */ 	lw	$t9,0x64($v1)
/*  f1281bc:	af20160c */ 	sw	$zero,0x160c($t9)
/*  f1281c0:	8c6f0064 */ 	lw	$t7,0x64($v1)
/*  f1281c4:	ade01610 */ 	sw	$zero,0x1610($t7)
/*  f1281c8:	8c780064 */ 	lw	$t8,0x64($v1)
/*  f1281cc:	a3051614 */ 	sb	$a1,0x1614($t8)
/*  f1281d0:	8c6b0064 */ 	lw	$t3,0x64($v1)
/*  f1281d4:	a1651615 */ 	sb	$a1,0x1615($t3)
/*  f1281d8:	8c6d0064 */ 	lw	$t5,0x64($v1)
/*  f1281dc:	a1a51616 */ 	sb	$a1,0x1616($t5)
/*  f1281e0:	8c6e0064 */ 	lw	$t6,0x64($v1)
/*  f1281e4:	a1c01617 */ 	sb	$zero,0x1617($t6)
/*  f1281e8:	8c6c0064 */ 	lw	$t4,0x64($v1)
/*  f1281ec:	a5871618 */ 	sh	$a3,0x1618($t4)
/*  f1281f0:	8c790064 */ 	lw	$t9,0x64($v1)
/*  f1281f4:	af201620 */ 	sw	$zero,0x1620($t9)
/*  f1281f8:	8c6f0064 */ 	lw	$t7,0x64($v1)
/*  f1281fc:	ade01624 */ 	sw	$zero,0x1624($t7)
.L0f128200:
/*  f128200:	8c780064 */ 	lw	$t8,0x64($v1)
/*  f128204:	03025821 */ 	addu	$t3,$t8,$v0
/*  f128208:	2442000c */ 	addiu	$v0,$v0,0xc
/*  f12820c:	28410030 */ 	slti	$at,$v0,0x30
/*  f128210:	1420fffb */ 	bnez	$at,.L0f128200
/*  f128214:	ad601630 */ 	sw	$zero,0x1630($t3)
/*  f128218:	8c6d0064 */ 	lw	$t5,0x64($v1)
/*  f12821c:	3c017f1b */ 	lui	$at,%hi(var7f1b515c)
/*  f128220:	c42c515c */ 	lwc1	$f12,%lo(var7f1b515c)($at)
/*  f128224:	e5a01660 */ 	swc1	$f0,0x1660($t5)
/*  f128228:	8c6e0064 */ 	lw	$t6,0x64($v1)
/*  f12822c:	3c017f1b */ 	lui	$at,%hi(var7f1b5160)
/*  f128230:	24040002 */ 	addiu	$a0,$zero,0x2
/*  f128234:	e5c01664 */ 	swc1	$f0,0x1664($t6)
/*  f128238:	8c6c0064 */ 	lw	$t4,0x64($v1)
/*  f12823c:	e5801668 */ 	swc1	$f0,0x1668($t4)
/*  f128240:	8c790064 */ 	lw	$t9,0x64($v1)
/*  f128244:	e720166c */ 	swc1	$f0,0x166c($t9)
/*  f128248:	8c6f0064 */ 	lw	$t7,0x64($v1)
/*  f12824c:	e5ec1670 */ 	swc1	$f12,0x1670($t7)
/*  f128250:	8c780064 */ 	lw	$t8,0x64($v1)
/*  f128254:	e7001470 */ 	swc1	$f0,0x1470($t8)
/*  f128258:	8c6b0064 */ 	lw	$t3,0x64($v1)
/*  f12825c:	e5601474 */ 	swc1	$f0,0x1474($t3)
/*  f128260:	8c6d0064 */ 	lw	$t5,0x64($v1)
/*  f128264:	e5a01478 */ 	swc1	$f0,0x1478($t5)
/*  f128268:	8c6e0064 */ 	lw	$t6,0x64($v1)
/*  f12826c:	e5c0147c */ 	swc1	$f0,0x147c($t6)
/*  f128270:	8c6c0064 */ 	lw	$t4,0x64($v1)
/*  f128274:	e5800ccc */ 	swc1	$f0,0xccc($t4)
/*  f128278:	8c790064 */ 	lw	$t9,0x64($v1)
/*  f12827c:	e7200cd0 */ 	swc1	$f0,0xcd0($t9)
/*  f128280:	8c6f0064 */ 	lw	$t7,0x64($v1)
/*  f128284:	e5e00cd4 */ 	swc1	$f0,0xcd4($t7)
/*  f128288:	8c780064 */ 	lw	$t8,0x64($v1)
/*  f12828c:	e7000cd8 */ 	swc1	$f0,0xcd8($t8)
/*  f128290:	8c6b0064 */ 	lw	$t3,0x64($v1)
/*  f128294:	e5601674 */ 	swc1	$f0,0x1674($t3)
/*  f128298:	8c6d0064 */ 	lw	$t5,0x64($v1)
/*  f12829c:	e5a01678 */ 	swc1	$f0,0x1678($t5)
/*  f1282a0:	8c6e0064 */ 	lw	$t6,0x64($v1)
/*  f1282a4:	e5c0167c */ 	swc1	$f0,0x167c($t6)
/*  f1282a8:	8c6c0064 */ 	lw	$t4,0x64($v1)
/*  f1282ac:	e5801680 */ 	swc1	$f0,0x1680($t4)
/*  f1282b0:	8c790064 */ 	lw	$t9,0x64($v1)
/*  f1282b4:	e72c1684 */ 	swc1	$f12,0x1684($t9)
/*  f1282b8:	8c6f0064 */ 	lw	$t7,0x64($v1)
/*  f1282bc:	e5e01688 */ 	swc1	$f0,0x1688($t7)
/*  f1282c0:	8c780064 */ 	lw	$t8,0x64($v1)
/*  f1282c4:	c42a5160 */ 	lwc1	$f10,%lo(var7f1b5160)($at)
/*  f1282c8:	3c014270 */ 	lui	$at,0x4270
/*  f1282cc:	44816000 */ 	mtc1	$at,$f12
/*  f1282d0:	e70a168c */ 	swc1	$f10,0x168c($t8)
/*  f1282d4:	8c6b0064 */ 	lw	$t3,0x64($v1)
/*  f1282d8:	3c0143a0 */ 	lui	$at,0x43a0
/*  f1282dc:	44818000 */ 	mtc1	$at,$f16
/*  f1282e0:	e5601690 */ 	swc1	$f0,0x1690($t3)
/*  f1282e4:	8c6d0064 */ 	lw	$t5,0x64($v1)
/*  f1282e8:	3c014370 */ 	lui	$at,0x4370
/*  f1282ec:	44819000 */ 	mtc1	$at,$f18
/*  f1282f0:	ada016d4 */ 	sw	$zero,0x16d4($t5)
/*  f1282f4:	8c6e0064 */ 	lw	$t6,0x64($v1)
/*  f1282f8:	3c014170 */ 	lui	$at,0x4170
/*  f1282fc:	44812000 */ 	mtc1	$at,$f4
/*  f128300:	adc016d8 */ 	sw	$zero,0x16d8($t6)
/*  f128304:	8c6c0064 */ 	lw	$t4,0x64($v1)
/*  f128308:	3c0141f0 */ 	lui	$at,0x41f0
/*  f12830c:	44813000 */ 	mtc1	$at,$f6
/*  f128310:	e58016dc */ 	swc1	$f0,0x16dc($t4)
/*  f128314:	8c790064 */ 	lw	$t9,0x64($v1)
/*  f128318:	3c014120 */ 	lui	$at,0x4120
/*  f12831c:	44814000 */ 	mtc1	$at,$f8
/*  f128320:	e72016e0 */ 	swc1	$f0,0x16e0($t9)
/*  f128324:	8c6f0064 */ 	lw	$t7,0x64($v1)
/*  f128328:	3c014238 */ 	lui	$at,0x4238
/*  f12832c:	44815000 */ 	mtc1	$at,$f10
/*  f128330:	e5e016e4 */ 	swc1	$f0,0x16e4($t7)
/*  f128334:	8c780064 */ 	lw	$t8,0x64($v1)
/*  f128338:	3c014320 */ 	lui	$at,0x4320
/*  f12833c:	af0016e8 */ 	sw	$zero,0x16e8($t8)
/*  f128340:	8c6b0064 */ 	lw	$t3,0x64($v1)
/*  f128344:	e56016ec */ 	swc1	$f0,0x16ec($t3)
/*  f128348:	8c6d0064 */ 	lw	$t5,0x64($v1)
/*  f12834c:	e5a016f0 */ 	swc1	$f0,0x16f0($t5)
/*  f128350:	8c6e0064 */ 	lw	$t6,0x64($v1)
/*  f128354:	e5c416f4 */ 	swc1	$f4,0x16f4($t6)
/*  f128358:	8c6c0064 */ 	lw	$t4,0x64($v1)
/*  f12835c:	44812000 */ 	mtc1	$at,$f4
/*  f128360:	3c0142f0 */ 	lui	$at,0x42f0
/*  f128364:	e58c16f8 */ 	swc1	$f12,0x16f8($t4)
/*  f128368:	8c790064 */ 	lw	$t9,0x64($v1)
/*  f12836c:	e72616fc */ 	swc1	$f6,0x16fc($t9)
/*  f128370:	8c6f0064 */ 	lw	$t7,0x64($v1)
/*  f128374:	44813000 */ 	mtc1	$at,$f6
/*  f128378:	3c017f1b */ 	lui	$at,%hi(var7f1b5164)
/*  f12837c:	ade81700 */ 	sw	$t0,0x1700($t7)
/*  f128380:	8c780064 */ 	lw	$t8,0x64($v1)
/*  f128384:	e7101704 */ 	swc1	$f16,0x1704($t8)
/*  f128388:	8c6b0064 */ 	lw	$t3,0x64($v1)
/*  f12838c:	e5721708 */ 	swc1	$f18,0x1708($t3)
/*  f128390:	8c6d0064 */ 	lw	$t5,0x64($v1)
/*  f128394:	e5a0170c */ 	swc1	$f0,0x170c($t5)
/*  f128398:	8c6e0064 */ 	lw	$t6,0x64($v1)
/*  f12839c:	e5c01710 */ 	swc1	$f0,0x1710($t6)
/*  f1283a0:	8c6c0064 */ 	lw	$t4,0x64($v1)
/*  f1283a4:	e5881714 */ 	swc1	$f8,0x1714($t4)
/*  f1283a8:	8c790064 */ 	lw	$t9,0x64($v1)
/*  f1283ac:	e72a1718 */ 	swc1	$f10,0x1718($t9)
/*  f1283b0:	8c6f0064 */ 	lw	$t7,0x64($v1)
/*  f1283b4:	e5e2171c */ 	swc1	$f2,0x171c($t7)
/*  f1283b8:	8c780064 */ 	lw	$t8,0x64($v1)
/*  f1283bc:	e7041720 */ 	swc1	$f4,0x1720($t8)
/*  f1283c0:	8c6b0064 */ 	lw	$t3,0x64($v1)
/*  f1283c4:	e5661724 */ 	swc1	$f6,0x1724($t3)
/*  f1283c8:	8c6d0064 */ 	lw	$t5,0x64($v1)
/*  f1283cc:	e5a21728 */ 	swc1	$f2,0x1728($t5)
/*  f1283d0:	8c6e0064 */ 	lw	$t6,0x64($v1)
/*  f1283d4:	e5c2172c */ 	swc1	$f2,0x172c($t6)
/*  f1283d8:	8c6c0064 */ 	lw	$t4,0x64($v1)
/*  f1283dc:	e5821730 */ 	swc1	$f2,0x1730($t4)
/*  f1283e0:	8c790064 */ 	lw	$t9,0x64($v1)
/*  f1283e4:	e7221734 */ 	swc1	$f2,0x1734($t9)
/*  f1283e8:	8c6f0064 */ 	lw	$t7,0x64($v1)
/*  f1283ec:	ade01738 */ 	sw	$zero,0x1738($t7)
/*  f1283f0:	8c780064 */ 	lw	$t8,0x64($v1)
/*  f1283f4:	af00173c */ 	sw	$zero,0x173c($t8)
/*  f1283f8:	8c6b0064 */ 	lw	$t3,0x64($v1)
/*  f1283fc:	ad601740 */ 	sw	$zero,0x1740($t3)
/*  f128400:	8c6d0064 */ 	lw	$t5,0x64($v1)
/*  f128404:	ada81744 */ 	sw	$t0,0x1744($t5)
/*  f128408:	8c6e0064 */ 	lw	$t6,0x64($v1)
/*  f12840c:	adc01748 */ 	sw	$zero,0x1748($t6)
/*  f128410:	8c6c0064 */ 	lw	$t4,0x64($v1)
/*  f128414:	ad80174c */ 	sw	$zero,0x174c($t4)
/*  f128418:	8c790064 */ 	lw	$t9,0x64($v1)
/*  f12841c:	af201750 */ 	sw	$zero,0x1750($t9)
/*  f128420:	8c6f0064 */ 	lw	$t7,0x64($v1)
/*  f128424:	ade01754 */ 	sw	$zero,0x1754($t7)
/*  f128428:	8c780064 */ 	lw	$t8,0x64($v1)
/*  f12842c:	af001758 */ 	sw	$zero,0x1758($t8)
/*  f128430:	8c6b0064 */ 	lw	$t3,0x64($v1)
/*  f128434:	ad60175c */ 	sw	$zero,0x175c($t3)
/*  f128438:	8c6d0064 */ 	lw	$t5,0x64($v1)
/*  f12843c:	ada01760 */ 	sw	$zero,0x1760($t5)
/*  f128440:	8c6e0064 */ 	lw	$t6,0x64($v1)
/*  f128444:	adc81764 */ 	sw	$t0,0x1764($t6)
/*  f128448:	8c6c0064 */ 	lw	$t4,0x64($v1)
/*  f12844c:	3c0e0001 */ 	lui	$t6,0x1
/*  f128450:	ad801768 */ 	sw	$zero,0x1768($t4)
/*  f128454:	8c790064 */ 	lw	$t9,0x64($v1)
/*  f128458:	af200484 */ 	sw	$zero,0x484($t9)
/*  f12845c:	8c6f0064 */ 	lw	$t7,0x64($v1)
/*  f128460:	ade00488 */ 	sw	$zero,0x488($t7)
/*  f128464:	8c780064 */ 	lw	$t8,0x64($v1)
/*  f128468:	e702176c */ 	swc1	$f2,0x176c($t8)
/*  f12846c:	8c6b0064 */ 	lw	$t3,0x64($v1)
/*  f128470:	e5621770 */ 	swc1	$f2,0x1770($t3)
/*  f128474:	8c6d0064 */ 	lw	$t5,0x64($v1)
/*  f128478:	e5a21774 */ 	swc1	$f2,0x1774($t5)
/*  f12847c:	8c6c0064 */ 	lw	$t4,0x64($v1)
/*  f128480:	ad8e1778 */ 	sw	$t6,0x1778($t4)
/*  f128484:	8c790064 */ 	lw	$t9,0x64($v1)
/*  f128488:	e7201794 */ 	swc1	$f0,0x1794($t9)
/*  f12848c:	8c6f0064 */ 	lw	$t7,0x64($v1)
/*  f128490:	e5e01798 */ 	swc1	$f0,0x1798($t7)
/*  f128494:	8c780064 */ 	lw	$t8,0x64($v1)
/*  f128498:	e710179c */ 	swc1	$f16,0x179c($t8)
/*  f12849c:	8c6b0064 */ 	lw	$t3,0x64($v1)
/*  f1284a0:	e57217a0 */ 	swc1	$f18,0x17a0($t3)
/*  f1284a4:	8c6d0064 */ 	lw	$t5,0x64($v1)
/*  f1284a8:	ada017a4 */ 	sw	$zero,0x17a4($t5)
/*  f1284ac:	8c6e0064 */ 	lw	$t6,0x64($v1)
/*  f1284b0:	adc01834 */ 	sw	$zero,0x1834($t6)
/*  f1284b4:	8c6c0064 */ 	lw	$t4,0x64($v1)
/*  f1284b8:	ad801838 */ 	sw	$zero,0x1838($t4)
/*  f1284bc:	8c790064 */ 	lw	$t9,0x64($v1)
/*  f1284c0:	af20183c */ 	sw	$zero,0x183c($t9)
/*  f1284c4:	8c6f0064 */ 	lw	$t7,0x64($v1)
/*  f1284c8:	e5e01840 */ 	swc1	$f0,0x1840($t7)
/*  f1284cc:	8c780064 */ 	lw	$t8,0x64($v1)
/*  f1284d0:	e7001844 */ 	swc1	$f0,0x1844($t8)
/*  f1284d4:	8c6b0064 */ 	lw	$t3,0x64($v1)
/*  f1284d8:	e56c1848 */ 	swc1	$f12,0x1848($t3)
/*  f1284dc:	8c6d0064 */ 	lw	$t5,0x64($v1)
/*  f1284e0:	e5ac184c */ 	swc1	$f12,0x184c($t5)
/*  f1284e4:	8c6e0064 */ 	lw	$t6,0x64($v1)
/*  f1284e8:	e5cc1850 */ 	swc1	$f12,0x1850($t6)
/*  f1284ec:	8c6c0064 */ 	lw	$t4,0x64($v1)
/*  f1284f0:	e58c1854 */ 	swc1	$f12,0x1854($t4)
/*  f1284f4:	8c790064 */ 	lw	$t9,0x64($v1)
/*  f1284f8:	c4285164 */ 	lwc1	$f8,%lo(var7f1b5164)($at)
/*  f1284fc:	e7281858 */ 	swc1	$f8,0x1858($t9)
/*  f128500:	8c6f0064 */ 	lw	$t7,0x64($v1)
/*  f128504:	ade0185c */ 	sw	$zero,0x185c($t7)
/*  f128508:	8c780064 */ 	lw	$t8,0x64($v1)
/*  f12850c:	af081860 */ 	sw	$t0,0x1860($t8)
/*  f128510:	8c6b0064 */ 	lw	$t3,0x64($v1)
/*  f128514:	ad601864 */ 	sw	$zero,0x1864($t3)
/*  f128518:	8c6d0064 */ 	lw	$t5,0x64($v1)
/*  f12851c:	ada01868 */ 	sw	$zero,0x1868($t5)
/*  f128520:	8c6e0064 */ 	lw	$t6,0x64($v1)
/*  f128524:	adc0186c */ 	sw	$zero,0x186c($t6)
/*  f128528:	8c6c0064 */ 	lw	$t4,0x64($v1)
/*  f12852c:	ad801870 */ 	sw	$zero,0x1870($t4)
/*  f128530:	8c790064 */ 	lw	$t9,0x64($v1)
/*  f128534:	af201874 */ 	sw	$zero,0x1874($t9)
/*  f128538:	8c6f0064 */ 	lw	$t7,0x64($v1)
/*  f12853c:	e5e018f4 */ 	swc1	$f0,0x18f4($t7)
/*  f128540:	0fc41b99 */ 	jal	cheatIsActive
/*  f128544:	afa3001c */ 	sw	$v1,0x1c($sp)
/*  f128548:	8fa3001c */ 	lw	$v1,0x1c($sp)
/*  f12854c:	24040007 */ 	addiu	$a0,$zero,0x7
/*  f128550:	3c013f80 */ 	lui	$at,0x3f80
/*  f128554:	8c780064 */ 	lw	$t8,0x64($v1)
/*  f128558:	44811000 */ 	mtc1	$at,$f2
/*  f12855c:	44800000 */ 	mtc1	$zero,$f0
/*  f128560:	a3021922 */ 	sb	$v0,0x1922($t8)
/*  f128564:	8c6b0064 */ 	lw	$t3,0x64($v1)
/*  f128568:	2408ffff */ 	addiu	$t0,$zero,-1
/*  f12856c:	3c01bf80 */ 	lui	$at,0xbf80
/*  f128570:	ad641924 */ 	sw	$a0,0x1924($t3)
/*  f128574:	8c6d0064 */ 	lw	$t5,0x64($v1)
/*  f128578:	3c09800a */ 	lui	$t1,%hi(g_Vars)
/*  f12857c:	44817000 */ 	mtc1	$at,$f14
/*  f128580:	e5a219bc */ 	swc1	$f2,0x19bc($t5)
/*  f128584:	8c6e0064 */ 	lw	$t6,0x64($v1)
/*  f128588:	25299fc0 */ 	addiu	$t1,$t1,%lo(g_Vars)
/*  f12858c:	24070001 */ 	addiu	$a3,$zero,0x1
/*  f128590:	e5c219c4 */ 	swc1	$f2,0x19c4($t6)
/*  f128594:	8c6c0064 */ 	lw	$t4,0x64($v1)
/*  f128598:	00001025 */ 	or	$v0,$zero,$zero
/*  f12859c:	e58219c0 */ 	swc1	$f2,0x19c0($t4)
/*  f1285a0:	8c790064 */ 	lw	$t9,0x64($v1)
/*  f1285a4:	e7201928 */ 	swc1	$f0,0x1928($t9)
/*  f1285a8:	8c6f0064 */ 	lw	$t7,0x64($v1)
/*  f1285ac:	ade0192c */ 	sw	$zero,0x192c($t7)
/*  f1285b0:	8c780064 */ 	lw	$t8,0x64($v1)
/*  f1285b4:	af04193c */ 	sw	$a0,0x193c($t8)
/*  f1285b8:	8c6b0064 */ 	lw	$t3,0x64($v1)
/*  f1285bc:	ad601940 */ 	sw	$zero,0x1940($t3)
/*  f1285c0:	8c6d0064 */ 	lw	$t5,0x64($v1)
/*  f1285c4:	ada8194c */ 	sw	$t0,0x194c($t5)
/*  f1285c8:	8c6e0064 */ 	lw	$t6,0x64($v1)
/*  f1285cc:	adc81950 */ 	sw	$t0,0x1950($t6)
/*  f1285d0:	8c6c0064 */ 	lw	$t4,0x64($v1)
/*  f1285d4:	ad881954 */ 	sw	$t0,0x1954($t4)
/*  f1285d8:	8c790064 */ 	lw	$t9,0x64($v1)
/*  f1285dc:	af281958 */ 	sw	$t0,0x1958($t9)
/*  f1285e0:	8c6f0064 */ 	lw	$t7,0x64($v1)
/*  f1285e4:	ade01964 */ 	sw	$zero,0x1964($t7)
/*  f1285e8:	8c780064 */ 	lw	$t8,0x64($v1)
/*  f1285ec:	af001994 */ 	sw	$zero,0x1994($t8)
/*  f1285f0:	8c6b0064 */ 	lw	$t3,0x64($v1)
/*  f1285f4:	ad601998 */ 	sw	$zero,0x1998($t3)
/*  f1285f8:	8c6d0064 */ 	lw	$t5,0x64($v1)
/*  f1285fc:	e5a2199c */ 	swc1	$f2,0x199c($t5)
/*  f128600:	8c6e0064 */ 	lw	$t6,0x64($v1)
/*  f128604:	e5c219a0 */ 	swc1	$f2,0x19a0($t6)
/*  f128608:	8c6c0064 */ 	lw	$t4,0x64($v1)
/*  f12860c:	ad8019c8 */ 	sw	$zero,0x19c8($t4)
/*  f128610:	8c790064 */ 	lw	$t9,0x64($v1)
/*  f128614:	af201a24 */ 	sw	$zero,0x1a24($t9)
/*  f128618:	8c6f0064 */ 	lw	$t7,0x64($v1)
/*  f12861c:	ade01a28 */ 	sw	$zero,0x1a28($t7)
/*  f128620:	8c780064 */ 	lw	$t8,0x64($v1)
/*  f128624:	af00019c */ 	sw	$zero,0x19c($t8)
/*  f128628:	8c6b0064 */ 	lw	$t3,0x64($v1)
/*  f12862c:	ad6001a0 */ 	sw	$zero,0x1a0($t3)
/*  f128630:	8c6d0064 */ 	lw	$t5,0x64($v1)
/*  f128634:	ada001b0 */ 	sw	$zero,0x1b0($t5)
/*  f128638:	8c6e0064 */ 	lw	$t6,0x64($v1)
/*  f12863c:	e5c01a48 */ 	swc1	$f0,0x1a48($t6)
/*  f128640:	8c6c0064 */ 	lw	$t4,0x64($v1)
/*  f128644:	e5801a4c */ 	swc1	$f0,0x1a4c($t4)
/*  f128648:	8c790064 */ 	lw	$t9,0x64($v1)
/*  f12864c:	e7201a50 */ 	swc1	$f0,0x1a50($t9)
/*  f128650:	8c6f0064 */ 	lw	$t7,0x64($v1)
/*  f128654:	e5e01a54 */ 	swc1	$f0,0x1a54($t7)
/*  f128658:	8c780064 */ 	lw	$t8,0x64($v1)
/*  f12865c:	e7001a58 */ 	swc1	$f0,0x1a58($t8)
/*  f128660:	8c6b0064 */ 	lw	$t3,0x64($v1)
/*  f128664:	e5601a5c */ 	swc1	$f0,0x1a5c($t3)
/*  f128668:	8c6d0064 */ 	lw	$t5,0x64($v1)
/*  f12866c:	e5a01a60 */ 	swc1	$f0,0x1a60($t5)
/*  f128670:	8c6e0064 */ 	lw	$t6,0x64($v1)
/*  f128674:	e5c01a64 */ 	swc1	$f0,0x1a64($t6)
/*  f128678:	8c6c0064 */ 	lw	$t4,0x64($v1)
/*  f12867c:	ad801a68 */ 	sw	$zero,0x1a68($t4)
/*  f128680:	8c790064 */ 	lw	$t9,0x64($v1)
/*  f128684:	af201a6c */ 	sw	$zero,0x1a6c($t9)
/*  f128688:	8c6f0064 */ 	lw	$t7,0x64($v1)
/*  f12868c:	e5e01ae8 */ 	swc1	$f0,0x1ae8($t7)
/*  f128690:	8c780064 */ 	lw	$t8,0x64($v1)
/*  f128694:	af001aec */ 	sw	$zero,0x1aec($t8)
/*  f128698:	8c6b0064 */ 	lw	$t3,0x64($v1)
/*  f12869c:	ad601af0 */ 	sw	$zero,0x1af0($t3)
/*  f1286a0:	8c6d0064 */ 	lw	$t5,0x64($v1)
/*  f1286a4:	ada01af4 */ 	sw	$zero,0x1af4($t5)
/*  f1286a8:	8c6e0064 */ 	lw	$t6,0x64($v1)
/*  f1286ac:	adc01b5c */ 	sw	$zero,0x1b5c($t6)
/*  f1286b0:	8c6c0064 */ 	lw	$t4,0x64($v1)
/*  f1286b4:	ad801b78 */ 	sw	$zero,0x1b78($t4)
/*  f1286b8:	8c790064 */ 	lw	$t9,0x64($v1)
/*  f1286bc:	af201b84 */ 	sw	$zero,0x1b84($t9)
/*  f1286c0:	8c6f0064 */ 	lw	$t7,0x64($v1)
/*  f1286c4:	ade01b88 */ 	sw	$zero,0x1b88($t7)
/*  f1286c8:	8c780064 */ 	lw	$t8,0x64($v1)
/*  f1286cc:	af001b8c */ 	sw	$zero,0x1b8c($t8)
.L0f1286d0:
/*  f1286d0:	8c6b0064 */ 	lw	$t3,0x64($v1)
/*  f1286d4:	01626821 */ 	addu	$t5,$t3,$v0
/*  f1286d8:	24420002 */ 	addiu	$v0,$v0,0x2
/*  f1286dc:	28410008 */ 	slti	$at,$v0,0x8
/*  f1286e0:	1420fffb */ 	bnez	$at,.L0f1286d0
/*  f1286e4:	a5a01b90 */ 	sh	$zero,0x1b90($t5)
/*  f1286e8:	8c6e0064 */ 	lw	$t6,0x64($v1)
/*  f1286ec:	24020008 */ 	addiu	$v0,$zero,0x8
/*  f1286f0:	3c01c080 */ 	lui	$at,0xc080
/*  f1286f4:	a1c01b98 */ 	sb	$zero,0x1b98($t6)
/*  f1286f8:	8c6c0064 */ 	lw	$t4,0x64($v1)
/*  f1286fc:	44815000 */ 	mtc1	$at,$f10
/*  f128700:	00002025 */ 	or	$a0,$zero,$zero
/*  f128704:	e58001b4 */ 	swc1	$f0,0x1b4($t4)
/*  f128708:	8c790064 */ 	lw	$t9,0x64($v1)
/*  f12870c:	e72001b8 */ 	swc1	$f0,0x1b8($t9)
/*  f128710:	8c650064 */ 	lw	$a1,0x64($v1)
/*  f128714:	24af01c0 */ 	addiu	$t7,$a1,0x1c0
/*  f128718:	acaf047c */ 	sw	$t7,0x47c($a1)
/*  f12871c:	8c780064 */ 	lw	$t8,0x64($v1)
/*  f128720:	af000480 */ 	sw	$zero,0x480($t8)
/*  f128724:	8c6b0064 */ 	lw	$t3,0x64($v1)
/*  f128728:	ad620490 */ 	sw	$v0,0x490($t3)
/*  f12872c:	8c6d0064 */ 	lw	$t5,0x64($v1)
/*  f128730:	a5a01ba4 */ 	sh	$zero,0x1ba4($t5)
/*  f128734:	8c6e0064 */ 	lw	$t6,0x64($v1)
/*  f128738:	a5c01ba6 */ 	sh	$zero,0x1ba6($t6)
/*  f12873c:	8c6c0064 */ 	lw	$t4,0x64($v1)
/*  f128740:	a5801ba8 */ 	sh	$zero,0x1ba8($t4)
/*  f128744:	8c790064 */ 	lw	$t9,0x64($v1)
/*  f128748:	a7201baa */ 	sh	$zero,0x1baa($t9)
/*  f12874c:	8c6f0064 */ 	lw	$t7,0x64($v1)
/*  f128750:	ade01bac */ 	sw	$zero,0x1bac($t7)
/*  f128754:	8c780064 */ 	lw	$t8,0x64($v1)
/*  f128758:	af00025c */ 	sw	$zero,0x25c($t8)
/*  f12875c:	8c6b0064 */ 	lw	$t3,0x64($v1)
/*  f128760:	e56e0258 */ 	swc1	$f14,0x258($t3)
/*  f128764:	8c6d0064 */ 	lw	$t5,0x64($v1)
/*  f128768:	ada019a8 */ 	sw	$zero,0x19a8($t5)
/*  f12876c:	8c6e0064 */ 	lw	$t6,0x64($v1)
/*  f128770:	adc00260 */ 	sw	$zero,0x260($t6)
/*  f128774:	8c6c0064 */ 	lw	$t4,0x64($v1)
/*  f128778:	e58a1be0 */ 	swc1	$f10,0x1be0($t4)
/*  f12877c:	8c790064 */ 	lw	$t9,0x64($v1)
/*  f128780:	a7201be4 */ 	sh	$zero,0x1be4($t9)
/*  f128784:	8c6f0064 */ 	lw	$t7,0x64($v1)
/*  f128788:	a1e01be6 */ 	sb	$zero,0x1be6($t7)
.L0f12878c:
/*  f12878c:	8c780064 */ 	lw	$t8,0x64($v1)
/*  f128790:	03045821 */ 	addu	$t3,$t8,$a0
/*  f128794:	24840001 */ 	addiu	$a0,$a0,0x1
/*  f128798:	1482fffc */ 	bne	$a0,$v0,.L0f12878c
/*  f12879c:	a1601be7 */ 	sb	$zero,0x1be7($t3)
/*  f1287a0:	8c6d0064 */ 	lw	$t5,0x64($v1)
/*  f1287a4:	a1a01bfc */ 	sb	$zero,0x1bfc($t5)
/*  f1287a8:	8c6e0064 */ 	lw	$t6,0x64($v1)
/*  f1287ac:	a1c01bfd */ 	sb	$zero,0x1bfd($t6)
/*  f1287b0:	8c6c0064 */ 	lw	$t4,0x64($v1)
/*  f1287b4:	a5801bfe */ 	sh	$zero,0x1bfe($t4)
/*  f1287b8:	8c790064 */ 	lw	$t9,0x64($v1)
/*  f1287bc:	af201c04 */ 	sw	$zero,0x1c04($t9)
/*  f1287c0:	8c6f0064 */ 	lw	$t7,0x64($v1)
/*  f1287c4:	ade01c08 */ 	sw	$zero,0x1c08($t7)
/*  f1287c8:	8c780064 */ 	lw	$t8,0x64($v1)
/*  f1287cc:	af081c0c */ 	sw	$t0,0x1c0c($t8)
/*  f1287d0:	8c6b0064 */ 	lw	$t3,0x64($v1)
/*  f1287d4:	ad601c10 */ 	sw	$zero,0x1c10($t3)
/*  f1287d8:	8c6d0064 */ 	lw	$t5,0x64($v1)
/*  f1287dc:	ada01c14 */ 	sw	$zero,0x1c14($t5)
/*  f1287e0:	8c6e0064 */ 	lw	$t6,0x64($v1)
/*  f1287e4:	e5c01c18 */ 	swc1	$f0,0x1c18($t6)
/*  f1287e8:	8c6c0064 */ 	lw	$t4,0x64($v1)
/*  f1287ec:	ad801c64 */ 	sw	$zero,0x1c64($t4)
/*  f1287f0:	8c790064 */ 	lw	$t9,0x64($v1)
/*  f1287f4:	e7201c44 */ 	swc1	$f0,0x1c44($t9)
/*  f1287f8:	8c6f0064 */ 	lw	$t7,0x64($v1)
/*  f1287fc:	e5e01c48 */ 	swc1	$f0,0x1c48($t7)
/*  f128800:	8c780064 */ 	lw	$t8,0x64($v1)
/*  f128804:	e7001c4c */ 	swc1	$f0,0x1c4c($t8)
/*  f128808:	8c650064 */ 	lw	$a1,0x64($v1)
/*  f12880c:	90ab1c50 */ 	lbu	$t3,0x1c50($a1)
/*  f128810:	316dffbf */ 	andi	$t5,$t3,0xffbf
/*  f128814:	a0ad1c50 */ 	sb	$t5,0x1c50($a1)
/*  f128818:	8c6e0064 */ 	lw	$t6,0x64($v1)
/*  f12881c:	a1c019b3 */ 	sb	$zero,0x19b3($t6)
/*  f128820:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f128824:	ad270324 */ 	sw	$a3,0x324($t1)
/*  f128828:	ad270328 */ 	sw	$a3,0x328($t1)
/*  f12882c:	03e00008 */ 	jr	$ra
/*  f128830:	27bd07c8 */ 	addiu	$sp,$sp,0x7c8
);

GLOBAL_ASM(
glabel func0f128834
/*  f128834:	3c0a800a */ 	lui	$t2,%hi(g_Vars)
/*  f128838:	254a9fc0 */ 	addiu	$t2,$t2,%lo(g_Vars)
/*  f12883c:	8d4e006c */ 	lw	$t6,0x6c($t2)
/*  f128840:	8d42028c */ 	lw	$v0,0x28c($t2)
/*  f128844:	00001825 */ 	or	$v1,$zero,$zero
/*  f128848:	11c00003 */ 	beqz	$t6,.L0f128858
/*  f12884c:	3c09800b */ 	lui	$t1,0x800b
/*  f128850:	10000001 */ 	beqz	$zero,.L0f128858
/*  f128854:	24030001 */ 	addiu	$v1,$zero,0x1
.L0f128858:
/*  f128858:	8d4f0068 */ 	lw	$t7,0x68($t2)
/*  f12885c:	00002025 */ 	or	$a0,$zero,$zero
/*  f128860:	00002825 */ 	or	$a1,$zero,$zero
/*  f128864:	11e00003 */ 	beqz	$t7,.L0f128874
/*  f128868:	00003025 */ 	or	$a2,$zero,$zero
/*  f12886c:	10000001 */ 	beqz	$zero,.L0f128874
/*  f128870:	24040001 */ 	addiu	$a0,$zero,0x1
.L0f128874:
/*  f128874:	8d580064 */ 	lw	$t8,0x64($t2)
/*  f128878:	3c0e800b */ 	lui	$t6,%hi(var800ac500)
/*  f12887c:	25cec500 */ 	addiu	$t6,$t6,%lo(var800ac500)
/*  f128880:	13000003 */ 	beqz	$t8,.L0f128890
/*  f128884:	00000000 */ 	sll	$zero,$zero,0x0
/*  f128888:	10000001 */ 	beqz	$zero,.L0f128890
/*  f12888c:	24050001 */ 	addiu	$a1,$zero,0x1
.L0f128890:
/*  f128890:	8d590070 */ 	lw	$t9,0x70($t2)
/*  f128894:	13200003 */ 	beqz	$t9,.L0f1288a4
/*  f128898:	00000000 */ 	sll	$zero,$zero,0x0
/*  f12889c:	10000001 */ 	beqz	$zero,.L0f1288a4
/*  f1288a0:	24060001 */ 	addiu	$a2,$zero,0x1
.L0f1288a4:
/*  f1288a4:	8d29c530 */ 	lw	$t1,-0x3ad0($t1)
/*  f1288a8:	00c55821 */ 	addu	$t3,$a2,$a1
/*  f1288ac:	01646021 */ 	addu	$t4,$t3,$a0
/*  f1288b0:	01833821 */ 	addu	$a3,$t4,$v1
/*  f1288b4:	00e9082a */ 	slt	$at,$a3,$t1
/*  f1288b8:	1020001a */ 	beqz	$at,.L0f128924
/*  f1288bc:	00e04025 */ 	or	$t0,$a3,$zero
/*  f1288c0:	00076880 */ 	sll	$t5,$a3,0x2
/*  f1288c4:	00022080 */ 	sll	$a0,$v0,0x2
/*  f1288c8:	008e2821 */ 	addu	$a1,$a0,$t6
/*  f1288cc:	01ae1821 */ 	addu	$v1,$t5,$t6
.L0f1288d0:
/*  f1288d0:	8c6f0000 */ 	lw	$t7,0x0($v1)
/*  f1288d4:	8cb90000 */ 	lw	$t9,0x0($a1)
/*  f1288d8:	01441021 */ 	addu	$v0,$t2,$a0
/*  f1288dc:	91f80011 */ 	lbu	$t8,0x11($t7)
/*  f1288e0:	932b0011 */ 	lbu	$t3,0x11($t9)
/*  f1288e4:	570b000c */ 	bnel	$t8,$t3,.L0f128918
/*  f1288e8:	25080001 */ 	addiu	$t0,$t0,0x1
/*  f1288ec:	8c460064 */ 	lw	$a2,0x64($v0)
/*  f1288f0:	3c09800b */ 	lui	$t1,0x800b
/*  f1288f4:	90cc1be6 */ 	lbu	$t4,0x1be6($a2)
/*  f1288f8:	00cc6821 */ 	addu	$t5,$a2,$t4
/*  f1288fc:	a1a81be7 */ 	sb	$t0,0x1be7($t5)
/*  f128900:	8c460064 */ 	lw	$a2,0x64($v0)
/*  f128904:	90ce1be6 */ 	lbu	$t6,0x1be6($a2)
/*  f128908:	25cf0001 */ 	addiu	$t7,$t6,0x1
/*  f12890c:	a0cf1be6 */ 	sb	$t7,0x1be6($a2)
/*  f128910:	8d29c530 */ 	lw	$t1,-0x3ad0($t1)
/*  f128914:	25080001 */ 	addiu	$t0,$t0,0x1
.L0f128918:
/*  f128918:	0109082a */ 	slt	$at,$t0,$t1
/*  f12891c:	1420ffec */ 	bnez	$at,.L0f1288d0
/*  f128920:	24630004 */ 	addiu	$v1,$v1,0x4
.L0f128924:
/*  f128924:	03e00008 */ 	jr	$ra
/*  f128928:	00000000 */ 	sll	$zero,$zero,0x0
);

void setCurrentPlayerNum(u32 playernum)
{
	g_Vars.currentplayernum = playernum;
	g_Vars.currentplayer = g_Vars.players[playernum];
	g_Vars.unk000288 = &g_Vars.unk000074[playernum];
	g_Vars.currentplayerindex = calculatePlayerIndex(playernum);
}

GLOBAL_ASM(
glabel propGetPlayerNum
/*  f12897c:	3c0a800a */ 	lui	$t2,%hi(g_Vars)
/*  f128980:	254a9fc0 */ 	addiu	$t2,$t2,%lo(g_Vars)
/*  f128984:	8d42006c */ 	lw	$v0,0x6c($t2)
/*  f128988:	27bdfff8 */ 	addiu	$sp,$sp,-8
/*  f12898c:	afb00004 */ 	sw	$s0,0x4($sp)
/*  f128990:	00808025 */ 	or	$s0,$a0,$zero
/*  f128994:	10400003 */ 	beqz	$v0,.L0f1289a4
/*  f128998:	00001825 */ 	or	$v1,$zero,$zero
/*  f12899c:	10000002 */ 	beqz	$zero,.L0f1289a8
/*  f1289a0:	24040001 */ 	addiu	$a0,$zero,0x1
.L0f1289a4:
/*  f1289a4:	00002025 */ 	or	$a0,$zero,$zero
.L0f1289a8:
/*  f1289a8:	8d450068 */ 	lw	$a1,0x68($t2)
/*  f1289ac:	00003025 */ 	or	$a2,$zero,$zero
/*  f1289b0:	00004025 */ 	or	$t0,$zero,$zero
/*  f1289b4:	10a00003 */ 	beqz	$a1,.L0f1289c4
/*  f1289b8:	0003c880 */ 	sll	$t9,$v1,0x2
/*  f1289bc:	10000001 */ 	beqz	$zero,.L0f1289c4
/*  f1289c0:	24060001 */ 	addiu	$a2,$zero,0x1
.L0f1289c4:
/*  f1289c4:	8d470064 */ 	lw	$a3,0x64($t2)
/*  f1289c8:	3c0c800a */ 	lui	$t4,%hi(g_Vars)
/*  f1289cc:	258c9fc0 */ 	addiu	$t4,$t4,%lo(g_Vars)
/*  f1289d0:	10e00003 */ 	beqz	$a3,.L0f1289e0
/*  f1289d4:	032c5821 */ 	addu	$t3,$t9,$t4
/*  f1289d8:	10000001 */ 	beqz	$zero,.L0f1289e0
/*  f1289dc:	24080001 */ 	addiu	$t0,$zero,0x1
.L0f1289e0:
/*  f1289e0:	8d490070 */ 	lw	$t1,0x70($t2)
/*  f1289e4:	00005025 */ 	or	$t2,$zero,$zero
/*  f1289e8:	11200003 */ 	beqz	$t1,.L0f1289f8
/*  f1289ec:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1289f0:	10000001 */ 	beqz	$zero,.L0f1289f8
/*  f1289f4:	240a0001 */ 	addiu	$t2,$zero,0x1
.L0f1289f8:
/*  f1289f8:	01487021 */ 	addu	$t6,$t2,$t0
/*  f1289fc:	01c67821 */ 	addu	$t7,$t6,$a2
/*  f128a00:	01e4c021 */ 	addu	$t8,$t7,$a0
/*  f128a04:	5b000022 */ 	blezl	$t8,.L0f128a90
/*  f128a08:	2402ffff */ 	addiu	$v0,$zero,-1
/*  f128a0c:	8d6d0064 */ 	lw	$t5,0x64($t3)
.L0f128a10:
/*  f128a10:	256b0004 */ 	addiu	$t3,$t3,0x4
/*  f128a14:	00002025 */ 	or	$a0,$zero,$zero
/*  f128a18:	8dae00bc */ 	lw	$t6,0xbc($t5)
/*  f128a1c:	00003025 */ 	or	$a2,$zero,$zero
/*  f128a20:	00004025 */ 	or	$t0,$zero,$zero
/*  f128a24:	160e0003 */ 	bne	$s0,$t6,.L0f128a34
/*  f128a28:	00005025 */ 	or	$t2,$zero,$zero
/*  f128a2c:	10000018 */ 	beqz	$zero,.L0f128a90
/*  f128a30:	00601025 */ 	or	$v0,$v1,$zero
.L0f128a34:
/*  f128a34:	10400003 */ 	beqz	$v0,.L0f128a44
/*  f128a38:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f128a3c:	10000001 */ 	beqz	$zero,.L0f128a44
/*  f128a40:	24040001 */ 	addiu	$a0,$zero,0x1
.L0f128a44:
/*  f128a44:	10a00003 */ 	beqz	$a1,.L0f128a54
/*  f128a48:	00000000 */ 	sll	$zero,$zero,0x0
/*  f128a4c:	10000001 */ 	beqz	$zero,.L0f128a54
/*  f128a50:	24060001 */ 	addiu	$a2,$zero,0x1
.L0f128a54:
/*  f128a54:	10e00003 */ 	beqz	$a3,.L0f128a64
/*  f128a58:	00000000 */ 	sll	$zero,$zero,0x0
/*  f128a5c:	10000001 */ 	beqz	$zero,.L0f128a64
/*  f128a60:	24080001 */ 	addiu	$t0,$zero,0x1
.L0f128a64:
/*  f128a64:	11200003 */ 	beqz	$t1,.L0f128a74
/*  f128a68:	00000000 */ 	sll	$zero,$zero,0x0
/*  f128a6c:	10000001 */ 	beqz	$zero,.L0f128a74
/*  f128a70:	240a0001 */ 	addiu	$t2,$zero,0x1
.L0f128a74:
/*  f128a74:	01487821 */ 	addu	$t7,$t2,$t0
/*  f128a78:	01e6c021 */ 	addu	$t8,$t7,$a2
/*  f128a7c:	0304c821 */ 	addu	$t9,$t8,$a0
/*  f128a80:	0079082a */ 	slt	$at,$v1,$t9
/*  f128a84:	5420ffe2 */ 	bnezl	$at,.L0f128a10
/*  f128a88:	8d6d0064 */ 	lw	$t5,0x64($t3)
/*  f128a8c:	2402ffff */ 	addiu	$v0,$zero,-1
.L0f128a90:
/*  f128a90:	8fb00004 */ 	lw	$s0,0x4($sp)
/*  f128a94:	03e00008 */ 	jr	$ra
/*  f128a98:	27bd0008 */ 	addiu	$sp,$sp,0x8
);

GLOBAL_ASM(
glabel func0f128a9c
/*  f128a9c:	3c02800a */ 	lui	$v0,%hi(g_Vars)
/*  f128aa0:	24429fc0 */ 	addiu	$v0,$v0,%lo(g_Vars)
/*  f128aa4:	8c4e0284 */ 	lw	$t6,0x284($v0)
/*  f128aa8:	a5c40630 */ 	sh	$a0,0x630($t6)
/*  f128aac:	8c4f0284 */ 	lw	$t7,0x284($v0)
/*  f128ab0:	03e00008 */ 	jr	$ra
/*  f128ab4:	a5e50632 */ 	sh	$a1,0x632($t7)
);

GLOBAL_ASM(
glabel func0f128ab8
/*  f128ab8:	3c02800a */ 	lui	$v0,%hi(g_Vars)
/*  f128abc:	24429fc0 */ 	addiu	$v0,$v0,%lo(g_Vars)
/*  f128ac0:	8c4e0284 */ 	lw	$t6,0x284($v0)
/*  f128ac4:	a5c40634 */ 	sh	$a0,0x634($t6)
/*  f128ac8:	8c4f0284 */ 	lw	$t7,0x284($v0)
/*  f128acc:	03e00008 */ 	jr	$ra
/*  f128ad0:	a5e50636 */ 	sh	$a1,0x636($t7)
);

GLOBAL_ASM(
glabel func0f128ad4
/*  f128ad4:	3c0e800a */ 	lui	$t6,0x800a
/*  f128ad8:	8dcea244 */ 	lw	$t6,-0x5dbc($t6)
/*  f128adc:	03e00008 */ 	jr	$ra
/*  f128ae0:	e5cc1854 */ 	swc1	$f12,0x1854($t6)
);

GLOBAL_ASM(
glabel func0f128ae4
/*  f128ae4:	3c0e800a */ 	lui	$t6,0x800a
/*  f128ae8:	8dcea244 */ 	lw	$t6,-0x5dbc($t6)
/*  f128aec:	03e00008 */ 	jr	$ra
/*  f128af0:	e5cc1858 */ 	swc1	$f12,0x1858($t6)
);

GLOBAL_ASM(
glabel func0f128af4
/*  f128af4:	28810052 */ 	slti	$at,$a0,0x52
/*  f128af8:	14200007 */ 	bnez	$at,.L0f128b18
/*  f128afc:	24010052 */ 	addiu	$at,$zero,0x52
/*  f128b00:	10810072 */ 	beq	$a0,$at,.L0f128ccc
/*  f128b04:	24010057 */ 	addiu	$at,$zero,0x57
/*  f128b08:	10810058 */ 	beq	$a0,$at,.L0f128c6c
/*  f128b0c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f128b10:	10000071 */ 	beqz	$zero,.L0f128cd8
/*  f128b14:	2881002d */ 	slti	$at,$a0,0x2d
.L0f128b18:
/*  f128b18:	28810032 */ 	slti	$at,$a0,0x32
/*  f128b1c:	14200005 */ 	bnez	$at,.L0f128b34
/*  f128b20:	24010051 */ 	addiu	$at,$zero,0x51
/*  f128b24:	10810067 */ 	beq	$a0,$at,.L0f128cc4
/*  f128b28:	00000000 */ 	sll	$zero,$zero,0x0
/*  f128b2c:	1000006a */ 	beqz	$zero,.L0f128cd8
/*  f128b30:	2881002d */ 	slti	$at,$a0,0x2d
.L0f128b34:
/*  f128b34:	2c810032 */ 	sltiu	$at,$a0,0x32
/*  f128b38:	10200066 */ 	beqz	$at,.L0f128cd4
/*  f128b3c:	00047080 */ 	sll	$t6,$a0,0x2
/*  f128b40:	3c017f1b */ 	lui	$at,%hi(var7f1b5168)
/*  f128b44:	002e0821 */ 	addu	$at,$at,$t6
/*  f128b48:	8c2e5168 */ 	lw	$t6,%lo(var7f1b5168)($at)
/*  f128b4c:	01c00008 */ 	jr	$t6
/*  f128b50:	00000000 */ 	sll	$zero,$zero,0x0
/*  f128b54:	03e00008 */ 	jr	$ra
/*  f128b58:	2402ffff */ 	addiu	$v0,$zero,-1
/*  f128b5c:	03e00008 */ 	jr	$ra
/*  f128b60:	240200f5 */ 	addiu	$v0,$zero,0xf5
/*  f128b64:	03e00008 */ 	jr	$ra
/*  f128b68:	240200f6 */ 	addiu	$v0,$zero,0xf6
/*  f128b6c:	03e00008 */ 	jr	$ra
/*  f128b70:	240200f7 */ 	addiu	$v0,$zero,0xf7
/*  f128b74:	03e00008 */ 	jr	$ra
/*  f128b78:	240200f8 */ 	addiu	$v0,$zero,0xf8
/*  f128b7c:	03e00008 */ 	jr	$ra
/*  f128b80:	240200f9 */ 	addiu	$v0,$zero,0xf9
/*  f128b84:	03e00008 */ 	jr	$ra
/*  f128b88:	240200fa */ 	addiu	$v0,$zero,0xfa
/*  f128b8c:	03e00008 */ 	jr	$ra
/*  f128b90:	240200fb */ 	addiu	$v0,$zero,0xfb
/*  f128b94:	03e00008 */ 	jr	$ra
/*  f128b98:	240200fc */ 	addiu	$v0,$zero,0xfc
/*  f128b9c:	03e00008 */ 	jr	$ra
/*  f128ba0:	240200fd */ 	addiu	$v0,$zero,0xfd
/*  f128ba4:	03e00008 */ 	jr	$ra
/*  f128ba8:	240200fe */ 	addiu	$v0,$zero,0xfe
/*  f128bac:	03e00008 */ 	jr	$ra
/*  f128bb0:	240200ff */ 	addiu	$v0,$zero,0xff
/*  f128bb4:	03e00008 */ 	jr	$ra
/*  f128bb8:	24020100 */ 	addiu	$v0,$zero,0x100
/*  f128bbc:	03e00008 */ 	jr	$ra
/*  f128bc0:	24020101 */ 	addiu	$v0,$zero,0x101
/*  f128bc4:	03e00008 */ 	jr	$ra
/*  f128bc8:	24020102 */ 	addiu	$v0,$zero,0x102
/*  f128bcc:	03e00008 */ 	jr	$ra
/*  f128bd0:	24020103 */ 	addiu	$v0,$zero,0x103
/*  f128bd4:	03e00008 */ 	jr	$ra
/*  f128bd8:	24020104 */ 	addiu	$v0,$zero,0x104
/*  f128bdc:	03e00008 */ 	jr	$ra
/*  f128be0:	24020105 */ 	addiu	$v0,$zero,0x105
/*  f128be4:	03e00008 */ 	jr	$ra
/*  f128be8:	24020106 */ 	addiu	$v0,$zero,0x106
/*  f128bec:	03e00008 */ 	jr	$ra
/*  f128bf0:	24020107 */ 	addiu	$v0,$zero,0x107
/*  f128bf4:	03e00008 */ 	jr	$ra
/*  f128bf8:	24020108 */ 	addiu	$v0,$zero,0x108
/*  f128bfc:	03e00008 */ 	jr	$ra
/*  f128c00:	24020109 */ 	addiu	$v0,$zero,0x109
/*  f128c04:	03e00008 */ 	jr	$ra
/*  f128c08:	2402010a */ 	addiu	$v0,$zero,0x10a
/*  f128c0c:	03e00008 */ 	jr	$ra
/*  f128c10:	2402010b */ 	addiu	$v0,$zero,0x10b
/*  f128c14:	03e00008 */ 	jr	$ra
/*  f128c18:	2402010c */ 	addiu	$v0,$zero,0x10c
/*  f128c1c:	03e00008 */ 	jr	$ra
/*  f128c20:	2402010d */ 	addiu	$v0,$zero,0x10d
/*  f128c24:	03e00008 */ 	jr	$ra
/*  f128c28:	24020195 */ 	addiu	$v0,$zero,0x195
/*  f128c2c:	03e00008 */ 	jr	$ra
/*  f128c30:	2402010f */ 	addiu	$v0,$zero,0x10f
/*  f128c34:	03e00008 */ 	jr	$ra
/*  f128c38:	2402010e */ 	addiu	$v0,$zero,0x10e
/*  f128c3c:	03e00008 */ 	jr	$ra
/*  f128c40:	2402010e */ 	addiu	$v0,$zero,0x10e
/*  f128c44:	03e00008 */ 	jr	$ra
/*  f128c48:	24020110 */ 	addiu	$v0,$zero,0x110
/*  f128c4c:	03e00008 */ 	jr	$ra
/*  f128c50:	24020112 */ 	addiu	$v0,$zero,0x112
/*  f128c54:	03e00008 */ 	jr	$ra
/*  f128c58:	24020115 */ 	addiu	$v0,$zero,0x115
/*  f128c5c:	03e00008 */ 	jr	$ra
/*  f128c60:	24020114 */ 	addiu	$v0,$zero,0x114
/*  f128c64:	03e00008 */ 	jr	$ra
/*  f128c68:	24020113 */ 	addiu	$v0,$zero,0x113
.L0f128c6c:
/*  f128c6c:	03e00008 */ 	jr	$ra
/*  f128c70:	24020011 */ 	addiu	$v0,$zero,0x11
/*  f128c74:	03e00008 */ 	jr	$ra
/*  f128c78:	2402012e */ 	addiu	$v0,$zero,0x12e
/*  f128c7c:	03e00008 */ 	jr	$ra
/*  f128c80:	24020117 */ 	addiu	$v0,$zero,0x117
/*  f128c84:	03e00008 */ 	jr	$ra
/*  f128c88:	24020118 */ 	addiu	$v0,$zero,0x118
/*  f128c8c:	03e00008 */ 	jr	$ra
/*  f128c90:	24020119 */ 	addiu	$v0,$zero,0x119
/*  f128c94:	03e00008 */ 	jr	$ra
/*  f128c98:	2402011a */ 	addiu	$v0,$zero,0x11a
/*  f128c9c:	03e00008 */ 	jr	$ra
/*  f128ca0:	2402011b */ 	addiu	$v0,$zero,0x11b
/*  f128ca4:	03e00008 */ 	jr	$ra
/*  f128ca8:	2402011c */ 	addiu	$v0,$zero,0x11c
/*  f128cac:	03e00008 */ 	jr	$ra
/*  f128cb0:	2402011d */ 	addiu	$v0,$zero,0x11d
/*  f128cb4:	03e00008 */ 	jr	$ra
/*  f128cb8:	2402011e */ 	addiu	$v0,$zero,0x11e
/*  f128cbc:	03e00008 */ 	jr	$ra
/*  f128cc0:	2402ffff */ 	addiu	$v0,$zero,-1
.L0f128cc4:
/*  f128cc4:	03e00008 */ 	jr	$ra
/*  f128cc8:	24020198 */ 	addiu	$v0,$zero,0x198
.L0f128ccc:
/*  f128ccc:	03e00008 */ 	jr	$ra
/*  f128cd0:	24020197 */ 	addiu	$v0,$zero,0x197
.L0f128cd4:
/*  f128cd4:	2881002d */ 	slti	$at,$a0,0x2d
.L0f128cd8:
/*  f128cd8:	10200003 */ 	beqz	$at,.L0f128ce8
/*  f128cdc:	2403ffff */ 	addiu	$v1,$zero,-1
/*  f128ce0:	03e00008 */ 	jr	$ra
/*  f128ce4:	2402010c */ 	addiu	$v0,$zero,0x10c
.L0f128ce8:
/*  f128ce8:	03e00008 */ 	jr	$ra
/*  f128cec:	00601025 */ 	or	$v0,$v1,$zero
);

GLOBAL_ASM(
glabel func0f128cf0
/*  f128cf0:	3c0e800a */ 	lui	$t6,0x800a
/*  f128cf4:	8dcea244 */ 	lw	$t6,-0x5dbc($t6)
/*  f128cf8:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f128cfc:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f128d00:	8dcf00bc */ 	lw	$t7,0xbc($t6)
/*  f128d04:	00802825 */ 	or	$a1,$a0,$zero
/*  f128d08:	0fc22e2e */ 	jal	func0f08b8b8
/*  f128d0c:	8de40004 */ 	lw	$a0,0x4($t7)
/*  f128d10:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f128d14:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f128d18:	03e00008 */ 	jr	$ra
/*  f128d1c:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f128d20
/*  f128d20:	3c0e800a */ 	lui	$t6,0x800a
/*  f128d24:	8dcea244 */ 	lw	$t6,-0x5dbc($t6)
/*  f128d28:	27bdffc8 */ 	addiu	$sp,$sp,-56
/*  f128d2c:	afbf001c */ 	sw	$ra,0x1c($sp)
/*  f128d30:	8dcf00bc */ 	lw	$t7,0xbc($t6)
/*  f128d34:	00041880 */ 	sll	$v1,$a0,0x2
/*  f128d38:	8de20004 */ 	lw	$v0,0x4($t7)
/*  f128d3c:	0043c021 */ 	addu	$t8,$v0,$v1
/*  f128d40:	8f190170 */ 	lw	$t9,0x170($t8)
/*  f128d44:	5720001a */ 	bnezl	$t9,.L0f128db0
/*  f128d48:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f128d4c:	afa20034 */ 	sw	$v0,0x34($sp)
/*  f128d50:	0fc2866a */ 	jal	getCurrentPlayerWeaponId
/*  f128d54:	afa30024 */ 	sw	$v1,0x24($sp)
/*  f128d58:	00402025 */ 	or	$a0,$v0,$zero
/*  f128d5c:	0fc4a2bd */ 	jal	func0f128af4
/*  f128d60:	afa20030 */ 	sw	$v0,0x30($sp)
/*  f128d64:	8fa30024 */ 	lw	$v1,0x24($sp)
/*  f128d68:	24010004 */ 	addiu	$at,$zero,0x4
/*  f128d6c:	8fa60030 */ 	lw	$a2,0x30($sp)
/*  f128d70:	14610005 */ 	bne	$v1,$at,.L0f128d88
/*  f128d74:	00402825 */ 	or	$a1,$v0,$zero
/*  f128d78:	24010022 */ 	addiu	$at,$zero,0x22
/*  f128d7c:	14c10002 */ 	bne	$a2,$at,.L0f128d88
/*  f128d80:	00000000 */ 	sll	$zero,$zero,0x0
/*  f128d84:	2405ffff */ 	addiu	$a1,$zero,-1
.L0f128d88:
/*  f128d88:	04a00008 */ 	bltz	$a1,.L0f128dac
/*  f128d8c:	8fa40034 */ 	lw	$a0,0x34($sp)
/*  f128d90:	14600003 */ 	bnez	$v1,.L0f128da0
/*  f128d94:	3c071000 */ 	lui	$a3,0x1000
/*  f128d98:	10000001 */ 	beqz	$zero,.L0f128da0
/*  f128d9c:	00003825 */ 	or	$a3,$zero,$zero
.L0f128da0:
/*  f128da0:	afa00010 */ 	sw	$zero,0x10($sp)
/*  f128da4:	0fc22e3a */ 	jal	func0f08b8e8
/*  f128da8:	afa00014 */ 	sw	$zero,0x14($sp)
.L0f128dac:
/*  f128dac:	8fbf001c */ 	lw	$ra,0x1c($sp)
.L0f128db0:
/*  f128db0:	27bd0038 */ 	addiu	$sp,$sp,0x38
/*  f128db4:	03e00008 */ 	jr	$ra
/*  f128db8:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f128dbc
/*  f128dbc:	27bdffd0 */ 	addiu	$sp,$sp,-48
/*  f128dc0:	afb1001c */ 	sw	$s1,0x1c($sp)
/*  f128dc4:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f128dc8:	3c11800a */ 	lui	$s1,%hi(g_Vars)
/*  f128dcc:	afbf002c */ 	sw	$ra,0x2c($sp)
/*  f128dd0:	afb40028 */ 	sw	$s4,0x28($sp)
/*  f128dd4:	afb30024 */ 	sw	$s3,0x24($sp)
/*  f128dd8:	afb20020 */ 	sw	$s2,0x20($sp)
/*  f128ddc:	26319fc0 */ 	addiu	$s1,$s1,%lo(g_Vars)
/*  f128de0:	00008025 */ 	or	$s0,$zero,$zero
.L0f128de4:
/*  f128de4:	ae300274 */ 	sw	$s0,0x274($s1)
/*  f128de8:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f128dec:	2a010004 */ 	slti	$at,$s0,0x4
/*  f128df0:	1420fffc */ 	bnez	$at,.L0f128de4
/*  f128df4:	26310004 */ 	addiu	$s1,$s1,0x4
/*  f128df8:	3c0e800a */ 	lui	$t6,0x800a
/*  f128dfc:	25d29fc0 */ 	addiu	$s2,$t6,-24640
/*  f128e00:	02408825 */ 	or	$s1,$s2,$zero
/*  f128e04:	00008025 */ 	or	$s0,$zero,$zero
/*  f128e08:	24140003 */ 	addiu	$s4,$zero,0x3
/*  f128e0c:	24130004 */ 	addiu	$s3,$zero,0x4
.L0f128e10:
/*  f128e10:	0c004b70 */ 	jal	random
/*  f128e14:	00000000 */ 	sll	$zero,$zero,0x0
/*  f128e18:	02707823 */ 	subu	$t7,$s3,$s0
/*  f128e1c:	004f001b */ 	divu	$zero,$v0,$t7
/*  f128e20:	0000c010 */ 	mfhi	$t8
/*  f128e24:	0018c880 */ 	sll	$t9,$t8,0x2
/*  f128e28:	02591821 */ 	addu	$v1,$s2,$t9
/*  f128e2c:	8c680274 */ 	lw	$t0,0x274($v1)
/*  f128e30:	8e240274 */ 	lw	$a0,0x274($s1)
/*  f128e34:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f128e38:	15e00002 */ 	bnez	$t7,.L0f128e44
/*  f128e3c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f128e40:	0007000d */ 	break	0x7
.L0f128e44:
/*  f128e44:	ae280274 */ 	sw	$t0,0x274($s1)
/*  f128e48:	26520004 */ 	addiu	$s2,$s2,0x4
/*  f128e4c:	26310004 */ 	addiu	$s1,$s1,0x4
/*  f128e50:	1614ffef */ 	bne	$s0,$s4,.L0f128e10
/*  f128e54:	ac640274 */ 	sw	$a0,0x274($v1)
/*  f128e58:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*  f128e5c:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f128e60:	8fb1001c */ 	lw	$s1,0x1c($sp)
/*  f128e64:	8fb20020 */ 	lw	$s2,0x20($sp)
/*  f128e68:	8fb30024 */ 	lw	$s3,0x24($sp)
/*  f128e6c:	8fb40028 */ 	lw	$s4,0x28($sp)
/*  f128e70:	03e00008 */ 	jr	$ra
/*  f128e74:	27bd0030 */ 	addiu	$sp,$sp,0x30
);

u32 calculatePlayerIndex(u32 playernum)
{
	u32 count = 0;
	u32 i;

	for (i = 0; i < 4; i++) {
		u32 thisnum = g_Vars.unk000274[i];

		if (playernum == thisnum) {
			break;
		}

		if (g_Vars.players[thisnum]) {
			count++;
		}
	}

	return count;
}

GLOBAL_ASM(
glabel func0f128ec8
/*  f128ec8:	3c03800a */ 	lui	$v1,%hi(g_Vars)
/*  f128ecc:	3c06800a */ 	lui	$a2,0x800a
/*  f128ed0:	3c02800a */ 	lui	$v0,%hi(g_Vars)
/*  f128ed4:	00802825 */ 	or	$a1,$a0,$zero
/*  f128ed8:	24429fc0 */ 	addiu	$v0,$v0,%lo(g_Vars)
/*  f128edc:	24c69fd0 */ 	addiu	$a2,$a2,-24624
/*  f128ee0:	24639fc0 */ 	addiu	$v1,$v1,%lo(g_Vars)
/*  f128ee4:	8c640274 */ 	lw	$a0,0x274($v1)
.L0f128ee8:
/*  f128ee8:	24630004 */ 	addiu	$v1,$v1,0x4
/*  f128eec:	00047080 */ 	sll	$t6,$a0,0x2
/*  f128ef0:	004e7821 */ 	addu	$t7,$v0,$t6
/*  f128ef4:	8df80064 */ 	lw	$t8,0x64($t7)
/*  f128ef8:	13000006 */ 	beqz	$t8,.L0f128f14
/*  f128efc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f128f00:	54a00004 */ 	bnezl	$a1,.L0f128f14
/*  f128f04:	24a5ffff */ 	addiu	$a1,$a1,-1
/*  f128f08:	03e00008 */ 	jr	$ra
/*  f128f0c:	00801025 */ 	or	$v0,$a0,$zero
/*  f128f10:	24a5ffff */ 	addiu	$a1,$a1,-1
.L0f128f14:
/*  f128f14:	5466fff4 */ 	bnel	$v1,$a2,.L0f128ee8
/*  f128f18:	8c640274 */ 	lw	$a0,0x274($v1)
/*  f128f1c:	00001025 */ 	or	$v0,$zero,$zero
/*  f128f20:	03e00008 */ 	jr	$ra
/*  f128f24:	00000000 */ 	sll	$zero,$zero,0x0
/*  f128f28:	00000000 */ 	sll	$zero,$zero,0x0
/*  f128f2c:	00000000 */ 	sll	$zero,$zero,0x0
);
