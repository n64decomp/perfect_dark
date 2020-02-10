#include <ultra64.h>
#include "constants.h"
#include "game/data/data_000000.h"
#include "game/data/data_0083d0.h"
#include "game/data/data_0160b0.h"
#include "game/data/data_020df0.h"
#include "gvars/gvars.h"
#include "library/library_034f0.h"
#include "library/library_48650.h"
#include "library/library_488e0.h"
#include "library/library_491b0.h"
#include "library/library_49c20.h"
#include "library/library_4b480.h"
#include "library/library_51890.h"
#include "library/library_51900.h"
#include "library/library_51a60.h"
#include "library/library_51c10.h"
#include "types.h"

GLOBAL_ASM(
glabel func00049c20
/*    49c20:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*    49c24:	3c03a460 */ 	lui	$v1,0xa460
/*    49c28:	34630010 */ 	ori	$v1,$v1,0x10
/*    49c2c:	afbf001c */ 	sw	$ra,0x1c($sp)
/*    49c30:	afb00018 */ 	sw	$s0,0x18($sp)
/*    49c34:	afa60028 */ 	sw	$a2,0x28($sp)
/*    49c38:	8c620000 */ 	lw	$v0,0x0($v1)
/*    49c3c:	00808025 */ 	or	$s0,$a0,$zero
/*    49c40:	304e0003 */ 	andi	$t6,$v0,0x3
/*    49c44:	51c00006 */ 	beqzl	$t6,.L00049c60
/*    49c48:	92020009 */ 	lbu	$v0,0x9($s0)
/*    49c4c:	8c620000 */ 	lw	$v0,0x0($v1)
.L00049c50:
/*    49c50:	304f0003 */ 	andi	$t7,$v0,0x3
/*    49c54:	55e0fffe */ 	bnezl	$t7,.L00049c50
/*    49c58:	8c620000 */ 	lw	$v0,0x0($v1)
/*    49c5c:	92020009 */ 	lbu	$v0,0x9($s0)
.L00049c60:
/*    49c60:	3c048006 */ 	lui	$a0,0x8006
/*    49c64:	92190004 */ 	lbu	$t9,0x4($s0)
/*    49c68:	0002c080 */ 	sll	$t8,$v0,0x2
/*    49c6c:	00982021 */ 	addu	$a0,$a0,$t8
/*    49c70:	8c84cf20 */ 	lw	$a0,-0x30e0($a0)
/*    49c74:	90880004 */ 	lbu	$t0,0x4($a0)
/*    49c78:	5328003d */ 	beql	$t9,$t0,.L00049d70
/*    49c7c:	00e02025 */ 	or	$a0,$a3,$zero
/*    49c80:	14400019 */ 	bnez	$v0,.L00049ce8
/*    49c84:	00801825 */ 	or	$v1,$a0,$zero
/*    49c88:	92020005 */ 	lbu	$v0,0x5($s0)
/*    49c8c:	90890005 */ 	lbu	$t1,0x5($a0)
/*    49c90:	3c0aa460 */ 	lui	$t2,0xa460
/*    49c94:	3c0ca460 */ 	lui	$t4,0xa460
/*    49c98:	10490002 */ 	beq	$v0,$t1,.L00049ca4
/*    49c9c:	3c0ea460 */ 	lui	$t6,0xa460
/*    49ca0:	ad420014 */ 	sw	$v0,0x14($t2)
.L00049ca4:
/*    49ca4:	92020006 */ 	lbu	$v0,0x6($s0)
/*    49ca8:	906b0006 */ 	lbu	$t3,0x6($v1)
/*    49cac:	3c18a460 */ 	lui	$t8,0xa460
/*    49cb0:	504b0003 */ 	beql	$v0,$t3,.L00049cc0
/*    49cb4:	92020007 */ 	lbu	$v0,0x7($s0)
/*    49cb8:	ad82001c */ 	sw	$v0,0x1c($t4)
/*    49cbc:	92020007 */ 	lbu	$v0,0x7($s0)
.L00049cc0:
/*    49cc0:	906d0007 */ 	lbu	$t5,0x7($v1)
/*    49cc4:	504d0003 */ 	beql	$v0,$t5,.L00049cd4
/*    49cc8:	92020008 */ 	lbu	$v0,0x8($s0)
/*    49ccc:	adc20020 */ 	sw	$v0,0x20($t6)
/*    49cd0:	92020008 */ 	lbu	$v0,0x8($s0)
.L00049cd4:
/*    49cd4:	906f0008 */ 	lbu	$t7,0x8($v1)
/*    49cd8:	504f001b */ 	beql	$v0,$t7,.L00049d48
/*    49cdc:	920f0004 */ 	lbu	$t7,0x4($s0)
/*    49ce0:	10000018 */ 	beqz	$zero,.L00049d44
/*    49ce4:	af020018 */ 	sw	$v0,0x18($t8)
.L00049ce8:
/*    49ce8:	92020005 */ 	lbu	$v0,0x5($s0)
/*    49cec:	90790005 */ 	lbu	$t9,0x5($v1)
/*    49cf0:	3c08a460 */ 	lui	$t0,0xa460
/*    49cf4:	3c0aa460 */ 	lui	$t2,0xa460
/*    49cf8:	10590002 */ 	beq	$v0,$t9,.L00049d04
/*    49cfc:	3c0ca460 */ 	lui	$t4,0xa460
/*    49d00:	ad020024 */ 	sw	$v0,0x24($t0)
.L00049d04:
/*    49d04:	92020006 */ 	lbu	$v0,0x6($s0)
/*    49d08:	90690006 */ 	lbu	$t1,0x6($v1)
/*    49d0c:	3c0ea460 */ 	lui	$t6,0xa460
/*    49d10:	50490003 */ 	beql	$v0,$t1,.L00049d20
/*    49d14:	92020007 */ 	lbu	$v0,0x7($s0)
/*    49d18:	ad42002c */ 	sw	$v0,0x2c($t2)
/*    49d1c:	92020007 */ 	lbu	$v0,0x7($s0)
.L00049d20:
/*    49d20:	906b0007 */ 	lbu	$t3,0x7($v1)
/*    49d24:	504b0003 */ 	beql	$v0,$t3,.L00049d34
/*    49d28:	92020008 */ 	lbu	$v0,0x8($s0)
/*    49d2c:	ad820030 */ 	sw	$v0,0x30($t4)
/*    49d30:	92020008 */ 	lbu	$v0,0x8($s0)
.L00049d34:
/*    49d34:	906d0008 */ 	lbu	$t5,0x8($v1)
/*    49d38:	504d0003 */ 	beql	$v0,$t5,.L00049d48
/*    49d3c:	920f0004 */ 	lbu	$t7,0x4($s0)
/*    49d40:	adc20028 */ 	sw	$v0,0x28($t6)
.L00049d44:
/*    49d44:	920f0004 */ 	lbu	$t7,0x4($s0)
.L00049d48:
/*    49d48:	a06f0004 */ 	sb	$t7,0x4($v1)
/*    49d4c:	92180005 */ 	lbu	$t8,0x5($s0)
/*    49d50:	a0780005 */ 	sb	$t8,0x5($v1)
/*    49d54:	92190006 */ 	lbu	$t9,0x6($s0)
/*    49d58:	a0790006 */ 	sb	$t9,0x6($v1)
/*    49d5c:	92080007 */ 	lbu	$t0,0x7($s0)
/*    49d60:	a0680007 */ 	sb	$t0,0x7($v1)
/*    49d64:	92090008 */ 	lbu	$t1,0x8($s0)
/*    49d68:	a0690008 */ 	sb	$t1,0x8($v1)
/*    49d6c:	00e02025 */ 	or	$a0,$a3,$zero
.L00049d70:
/*    49d70:	0c012d20 */ 	jal	func0004b480
/*    49d74:	afa50024 */ 	sw	$a1,0x24($sp)
/*    49d78:	8fa50024 */ 	lw	$a1,0x24($sp)
/*    49d7c:	3c0aa460 */ 	lui	$t2,0xa460
/*    49d80:	ad420000 */ 	sw	$v0,0x0($t2)
/*    49d84:	8fac0028 */ 	lw	$t4,0x28($sp)
/*    49d88:	8e0b000c */ 	lw	$t3,0xc($s0)
/*    49d8c:	3c011fff */ 	lui	$at,0x1fff
/*    49d90:	3421ffff */ 	ori	$at,$at,0xffff
/*    49d94:	016c6825 */ 	or	$t5,$t3,$t4
/*    49d98:	01a17024 */ 	and	$t6,$t5,$at
/*    49d9c:	3c0fa460 */ 	lui	$t7,0xa460
/*    49da0:	10a00006 */ 	beqz	$a1,.L00049dbc
/*    49da4:	adee0004 */ 	sw	$t6,0x4($t7)
/*    49da8:	24010001 */ 	addiu	$at,$zero,0x1
/*    49dac:	10a10008 */ 	beq	$a1,$at,.L00049dd0
/*    49db0:	8fa90030 */ 	lw	$t1,0x30($sp)
/*    49db4:	1000000d */ 	beqz	$zero,.L00049dec
/*    49db8:	2402ffff */ 	addiu	$v0,$zero,-1
.L00049dbc:
/*    49dbc:	8fb80030 */ 	lw	$t8,0x30($sp)
/*    49dc0:	3c08a460 */ 	lui	$t0,0xa460
/*    49dc4:	2719ffff */ 	addiu	$t9,$t8,-1
/*    49dc8:	10000007 */ 	beqz	$zero,.L00049de8
/*    49dcc:	ad19000c */ 	sw	$t9,0xc($t0)
.L00049dd0:
/*    49dd0:	252affff */ 	addiu	$t2,$t1,-1
/*    49dd4:	3c0ba460 */ 	lui	$t3,0xa460
/*    49dd8:	10000003 */ 	beqz	$zero,.L00049de8
/*    49ddc:	ad6a0008 */ 	sw	$t2,0x8($t3)
/*    49de0:	10000002 */ 	beqz	$zero,.L00049dec
/*    49de4:	2402ffff */ 	addiu	$v0,$zero,-1
.L00049de8:
/*    49de8:	00001025 */ 	or	$v0,$zero,$zero
.L00049dec:
/*    49dec:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*    49df0:	8fb00018 */ 	lw	$s0,0x18($sp)
/*    49df4:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*    49df8:	03e00008 */ 	jr	$ra
/*    49dfc:	00000000 */ 	sll	$zero,$zero,0x0
/*    49e00:	27bdff88 */ 	addiu	$sp,$sp,-120
/*    49e04:	afb3002c */ 	sw	$s3,0x2c($sp)
/*    49e08:	afbe0040 */ 	sw	$s8,0x40($sp)
/*    49e0c:	afb7003c */ 	sw	$s7,0x3c($sp)
/*    49e10:	afb60038 */ 	sw	$s6,0x38($sp)
/*    49e14:	afb50034 */ 	sw	$s5,0x34($sp)
/*    49e18:	afb40030 */ 	sw	$s4,0x30($sp)
/*    49e1c:	3c130500 */ 	lui	$s3,0x500
/*    49e20:	0080a025 */ 	or	$s4,$a0,$zero
/*    49e24:	afbf0044 */ 	sw	$ra,0x44($sp)
/*    49e28:	afb20028 */ 	sw	$s2,0x28($sp)
/*    49e2c:	afb10024 */ 	sw	$s1,0x24($sp)
/*    49e30:	afb00020 */ 	sw	$s0,0x20($sp)
/*    49e34:	afa00074 */ 	sw	$zero,0x74($sp)
/*    49e38:	36730510 */ 	ori	$s3,$s3,0x510
/*    49e3c:	24150024 */ 	addiu	$s5,$zero,0x24
/*    49e40:	27b60070 */ 	addiu	$s6,$sp,0x70
/*    49e44:	24170001 */ 	addiu	$s7,$zero,0x1
/*    49e48:	241e001d */ 	addiu	$s8,$zero,0x1d
.L00049e4c:
/*    49e4c:	8e840008 */ 	lw	$a0,0x8($s4)
.L00049e50:
/*    49e50:	27a50074 */ 	addiu	$a1,$sp,0x74
/*    49e54:	0c0121bc */ 	jal	func000486f0
/*    49e58:	02e03025 */ 	or	$a2,$s7,$zero
/*    49e5c:	8fae0074 */ 	lw	$t6,0x74($sp)
/*    49e60:	8fa80074 */ 	lw	$t0,0x74($sp)
/*    49e64:	8dc40014 */ 	lw	$a0,0x14($t6)
/*    49e68:	50800081 */ 	beqzl	$a0,.L0004a070
/*    49e6c:	95090000 */ 	lhu	$t1,0x0($t0)
/*    49e70:	908f0004 */ 	lbu	$t7,0x4($a0)
/*    49e74:	24010002 */ 	addiu	$at,$zero,0x2
/*    49e78:	55e1007d */ 	bnel	$t7,$at,.L0004a070
/*    49e7c:	95090000 */ 	lhu	$t1,0x0($t0)
/*    49e80:	8c820014 */ 	lw	$v0,0x14($a0)
/*    49e84:	24010001 */ 	addiu	$at,$zero,0x1
/*    49e88:	24900014 */ 	addiu	$s0,$a0,0x14
/*    49e8c:	10400003 */ 	beqz	$v0,.L00049e9c
/*    49e90:	27a5006c */ 	addiu	$a1,$sp,0x6c
/*    49e94:	54410076 */ 	bnel	$v0,$at,.L0004a070
/*    49e98:	95090000 */ 	lhu	$t1,0x0($t0)
.L00049e9c:
/*    49e9c:	96180006 */ 	lhu	$t8,0x6($s0)
/*    49ea0:	96020004 */ 	lhu	$v0,0x4($s0)
/*    49ea4:	2408ffff */ 	addiu	$t0,$zero,-1
/*    49ea8:	03150019 */ 	multu	$t8,$s5
/*    49eac:	24010003 */ 	addiu	$at,$zero,0x3
/*    49eb0:	ae080008 */ 	sw	$t0,0x8($s0)
/*    49eb4:	00009025 */ 	or	$s2,$zero,$zero
/*    49eb8:	02e03025 */ 	or	$a2,$s7,$zero
/*    49ebc:	0000c812 */ 	mflo	$t9
/*    49ec0:	02198821 */ 	addu	$s1,$s0,$t9
/*    49ec4:	10410006 */ 	beq	$v0,$at,.L00049ee0
/*    49ec8:	26310018 */ 	addiu	$s1,$s1,0x18
/*    49ecc:	8e290004 */ 	lw	$t1,0x4($s1)
/*    49ed0:	8e2a000c */ 	lw	$t2,0xc($s1)
/*    49ed4:	012a5823 */ 	subu	$t3,$t1,$t2
/*    49ed8:	ae2b0004 */ 	sw	$t3,0x4($s1)
/*    49edc:	96020004 */ 	lhu	$v0,0x4($s0)
.L00049ee0:
/*    49ee0:	24010002 */ 	addiu	$at,$zero,0x2
/*    49ee4:	14410007 */ 	bne	$v0,$at,.L00049f04
/*    49ee8:	8fac0074 */ 	lw	$t4,0x74($sp)
/*    49eec:	8d8d0014 */ 	lw	$t5,0x14($t4)
/*    49ef0:	8dae0014 */ 	lw	$t6,0x14($t5)
/*    49ef4:	15c00003 */ 	bnez	$t6,.L00049f04
/*    49ef8:	00000000 */ 	sll	$zero,$zero,0x0
/*    49efc:	10000001 */ 	beqz	$zero,.L00049f04
/*    49f00:	02e09025 */ 	or	$s2,$s7,$zero
.L00049f04:
/*    49f04:	0c0121bc */ 	jal	func000486f0
/*    49f08:	8e840010 */ 	lw	$a0,0x10($s4)
/*    49f0c:	3c040010 */ 	lui	$a0,0x10
/*    49f10:	0c014628 */ 	jal	func000518a0
/*    49f14:	34840401 */ 	ori	$a0,$a0,0x401
/*    49f18:	8e060010 */ 	lw	$a2,0x10($s0)
/*    49f1c:	8faf0074 */ 	lw	$t7,0x74($sp)
/*    49f20:	3c018000 */ 	lui	$at,0x8000
/*    49f24:	00c1c025 */ 	or	$t8,$a2,$at
/*    49f28:	03003025 */ 	or	$a2,$t8,$zero
/*    49f2c:	02602825 */ 	or	$a1,$s3,$zero
/*    49f30:	0c014640 */ 	jal	func00051900
/*    49f34:	8de40014 */ 	lw	$a0,0x14($t7)
.L00049f38:
/*    49f38:	8e84000c */ 	lw	$a0,0xc($s4)
/*    49f3c:	02c02825 */ 	or	$a1,$s6,$zero
/*    49f40:	0c0121bc */ 	jal	func000486f0
/*    49f44:	02e03025 */ 	or	$a2,$s7,$zero
/*    49f48:	8fb90074 */ 	lw	$t9,0x74($sp)
/*    49f4c:	8f240014 */ 	lw	$a0,0x14($t9)
/*    49f50:	24900014 */ 	addiu	$s0,$a0,0x14
/*    49f54:	96080006 */ 	lhu	$t0,0x6($s0)
/*    49f58:	01150019 */ 	multu	$t0,$s5
/*    49f5c:	00004812 */ 	mflo	$t1
/*    49f60:	02098821 */ 	addu	$s1,$s0,$t1
/*    49f64:	8e2a0018 */ 	lw	$t2,0x18($s1)
/*    49f68:	26310018 */ 	addiu	$s1,$s1,0x18
/*    49f6c:	57ca0027 */ 	bnel	$s8,$t2,.L0004a00c
/*    49f70:	8fa50074 */ 	lw	$a1,0x74($sp)
/*    49f74:	8e060010 */ 	lw	$a2,0x10($s0)
/*    49f78:	3c011000 */ 	lui	$at,0x1000
/*    49f7c:	02602825 */ 	or	$a1,$s3,$zero
/*    49f80:	00c15825 */ 	or	$t3,$a2,$at
/*    49f84:	0c014640 */ 	jal	func00051900
/*    49f88:	01603025 */ 	or	$a2,$t3,$zero
/*    49f8c:	8fac0074 */ 	lw	$t4,0x74($sp)
/*    49f90:	02602825 */ 	or	$a1,$s3,$zero
/*    49f94:	8e060010 */ 	lw	$a2,0x10($s0)
/*    49f98:	0c014640 */ 	jal	func00051900
/*    49f9c:	8d840014 */ 	lw	$a0,0x14($t4)
/*    49fa0:	8fad0074 */ 	lw	$t5,0x74($sp)
/*    49fa4:	3c050500 */ 	lui	$a1,0x500
/*    49fa8:	34a50508 */ 	ori	$a1,$a1,0x508
/*    49fac:	27a60054 */ 	addiu	$a2,$sp,0x54
/*    49fb0:	0c014698 */ 	jal	func00051a60
/*    49fb4:	8da40014 */ 	lw	$a0,0x14($t5)
/*    49fb8:	8fae0054 */ 	lw	$t6,0x54($sp)
/*    49fbc:	8fb80074 */ 	lw	$t8,0x74($sp)
/*    49fc0:	02602825 */ 	or	$a1,$s3,$zero
/*    49fc4:	000e7980 */ 	sll	$t7,$t6,0x6
/*    49fc8:	05e30008 */ 	bgezl	$t7,.L00049fec
/*    49fcc:	24080004 */ 	addiu	$t0,$zero,0x4
/*    49fd0:	8e060010 */ 	lw	$a2,0x10($s0)
/*    49fd4:	3c010100 */ 	lui	$at,0x100
/*    49fd8:	8f040014 */ 	lw	$a0,0x14($t8)
/*    49fdc:	00c1c825 */ 	or	$t9,$a2,$at
/*    49fe0:	0c014640 */ 	jal	func00051900
/*    49fe4:	03203025 */ 	or	$a2,$t9,$zero
/*    49fe8:	24080004 */ 	addiu	$t0,$zero,0x4
.L00049fec:
/*    49fec:	ae280000 */ 	sw	$t0,0x0($s1)
/*    49ff0:	24090002 */ 	addiu	$t1,$zero,0x2
/*    49ff4:	3c0aa460 */ 	lui	$t2,0xa460
/*    49ff8:	3c040010 */ 	lui	$a0,0x10
/*    49ffc:	ad490010 */ 	sw	$t1,0x10($t2)
/*    4a000:	0c0146f0 */ 	jal	func00051bc0
/*    4a004:	34840c01 */ 	ori	$a0,$a0,0xc01
/*    4a008:	8fa50074 */ 	lw	$a1,0x74($sp)
.L0004a00c:
/*    4a00c:	00003025 */ 	or	$a2,$zero,$zero
/*    4a010:	0c012238 */ 	jal	func000488e0
/*    4a014:	8ca40004 */ 	lw	$a0,0x4($a1)
/*    4a018:	16570007 */ 	bne	$s2,$s7,.L0004a038
/*    4a01c:	8fac0074 */ 	lw	$t4,0x74($sp)
/*    4a020:	8d8d0014 */ 	lw	$t5,0x14($t4)
/*    4a024:	8dae002c */ 	lw	$t6,0x2c($t5)
/*    4a028:	55c00004 */ 	bnezl	$t6,.L0004a03c
/*    4a02c:	8e840010 */ 	lw	$a0,0x10($s4)
/*    4a030:	1000ffc1 */ 	beqz	$zero,.L00049f38
/*    4a034:	00009025 */ 	or	$s2,$zero,$zero
.L0004a038:
/*    4a038:	8e840010 */ 	lw	$a0,0x10($s4)
.L0004a03c:
/*    4a03c:	00002825 */ 	or	$a1,$zero,$zero
/*    4a040:	0c012238 */ 	jal	func000488e0
/*    4a044:	00003025 */ 	or	$a2,$zero,$zero
/*    4a048:	8faf0074 */ 	lw	$t7,0x74($sp)
/*    4a04c:	8df80014 */ 	lw	$t8,0x14($t7)
/*    4a050:	9719001a */ 	lhu	$t9,0x1a($t8)
/*    4a054:	56f9ff7e */ 	bnel	$s7,$t9,.L00049e50
/*    4a058:	8e840008 */ 	lw	$a0,0x8($s4)
/*    4a05c:	0c014704 */ 	jal	func00051c10
/*    4a060:	00000000 */ 	sll	$zero,$zero,0x0
/*    4a064:	1000ff7a */ 	beqz	$zero,.L00049e50
/*    4a068:	8e840008 */ 	lw	$a0,0x8($s4)
/*    4a06c:	95090000 */ 	lhu	$t1,0x0($t0)
.L0004a070:
/*    4a070:	252afff6 */ 	addiu	$t2,$t1,-10
/*    4a074:	2d410007 */ 	sltiu	$at,$t2,0x7
/*    4a078:	10200047 */ 	beqz	$at,.L0004a198
/*    4a07c:	000a5080 */ 	sll	$t2,$t2,0x2
/*    4a080:	3c017006 */ 	lui	$at,0x7006
/*    4a084:	002a0821 */ 	addu	$at,$at,$t2
/*    4a088:	8c2a9eb0 */ 	lw	$t2,-0x6150($at)
/*    4a08c:	01400008 */ 	jr	$t2
/*    4a090:	00000000 */ 	sll	$zero,$zero,0x0
/*    4a094:	8e840010 */ 	lw	$a0,0x10($s4)
/*    4a098:	27a5006c */ 	addiu	$a1,$sp,0x6c
/*    4a09c:	0c0121bc */ 	jal	func000486f0
/*    4a0a0:	02e03025 */ 	or	$a2,$s7,$zero
/*    4a0a4:	8fab0074 */ 	lw	$t3,0x74($sp)
/*    4a0a8:	8e990014 */ 	lw	$t9,0x14($s4)
/*    4a0ac:	00002025 */ 	or	$a0,$zero,$zero
/*    4a0b0:	8d65000c */ 	lw	$a1,0xc($t3)
/*    4a0b4:	8d660008 */ 	lw	$a2,0x8($t3)
/*    4a0b8:	0320f809 */ 	jalr	$t9
/*    4a0bc:	8d670010 */ 	lw	$a3,0x10($t3)
/*    4a0c0:	10000036 */ 	beqz	$zero,.L0004a19c
/*    4a0c4:	00408025 */ 	or	$s0,$v0,$zero
/*    4a0c8:	8e840010 */ 	lw	$a0,0x10($s4)
/*    4a0cc:	27a5006c */ 	addiu	$a1,$sp,0x6c
/*    4a0d0:	0c0121bc */ 	jal	func000486f0
/*    4a0d4:	02e03025 */ 	or	$a2,$s7,$zero
/*    4a0d8:	8fac0074 */ 	lw	$t4,0x74($sp)
/*    4a0dc:	8e990014 */ 	lw	$t9,0x14($s4)
/*    4a0e0:	02e02025 */ 	or	$a0,$s7,$zero
/*    4a0e4:	8d85000c */ 	lw	$a1,0xc($t4)
/*    4a0e8:	8d860008 */ 	lw	$a2,0x8($t4)
/*    4a0ec:	0320f809 */ 	jalr	$t9
/*    4a0f0:	8d870010 */ 	lw	$a3,0x10($t4)
/*    4a0f4:	10000029 */ 	beqz	$zero,.L0004a19c
/*    4a0f8:	00408025 */ 	or	$s0,$v0,$zero
/*    4a0fc:	8e840010 */ 	lw	$a0,0x10($s4)
/*    4a100:	27a5006c */ 	addiu	$a1,$sp,0x6c
/*    4a104:	0c0121bc */ 	jal	func000486f0
/*    4a108:	02e03025 */ 	or	$a2,$s7,$zero
/*    4a10c:	8fad0074 */ 	lw	$t5,0x74($sp)
/*    4a110:	00002825 */ 	or	$a1,$zero,$zero
/*    4a114:	8dae0010 */ 	lw	$t6,0x10($t5)
/*    4a118:	8da40014 */ 	lw	$a0,0x14($t5)
/*    4a11c:	8da6000c */ 	lw	$a2,0xc($t5)
/*    4a120:	8da70008 */ 	lw	$a3,0x8($t5)
/*    4a124:	afae0010 */ 	sw	$t6,0x10($sp)
/*    4a128:	8e990018 */ 	lw	$t9,0x18($s4)
/*    4a12c:	0320f809 */ 	jalr	$t9
/*    4a130:	00000000 */ 	sll	$zero,$zero,0x0
/*    4a134:	10000019 */ 	beqz	$zero,.L0004a19c
/*    4a138:	00408025 */ 	or	$s0,$v0,$zero
/*    4a13c:	8e840010 */ 	lw	$a0,0x10($s4)
/*    4a140:	27a5006c */ 	addiu	$a1,$sp,0x6c
/*    4a144:	0c0121bc */ 	jal	func000486f0
/*    4a148:	02e03025 */ 	or	$a2,$s7,$zero
/*    4a14c:	8faf0074 */ 	lw	$t7,0x74($sp)
/*    4a150:	02e02825 */ 	or	$a1,$s7,$zero
/*    4a154:	8df80010 */ 	lw	$t8,0x10($t7)
/*    4a158:	8de40014 */ 	lw	$a0,0x14($t7)
/*    4a15c:	8de6000c */ 	lw	$a2,0xc($t7)
/*    4a160:	8de70008 */ 	lw	$a3,0x8($t7)
/*    4a164:	afb80010 */ 	sw	$t8,0x10($sp)
/*    4a168:	8e990018 */ 	lw	$t9,0x18($s4)
/*    4a16c:	0320f809 */ 	jalr	$t9
/*    4a170:	00000000 */ 	sll	$zero,$zero,0x0
/*    4a174:	10000009 */ 	beqz	$zero,.L0004a19c
/*    4a178:	00408025 */ 	or	$s0,$v0,$zero
/*    4a17c:	8fa50074 */ 	lw	$a1,0x74($sp)
/*    4a180:	00003025 */ 	or	$a2,$zero,$zero
/*    4a184:	2410ffff */ 	addiu	$s0,$zero,-1
/*    4a188:	0c012238 */ 	jal	func000488e0
/*    4a18c:	8ca40004 */ 	lw	$a0,0x4($a1)
/*    4a190:	10000002 */ 	beqz	$zero,.L0004a19c
/*    4a194:	00000000 */ 	sll	$zero,$zero,0x0
.L0004a198:
/*    4a198:	2410ffff */ 	addiu	$s0,$zero,-1
.L0004a19c:
/*    4a19c:	1600ff2b */ 	bnez	$s0,.L00049e4c
/*    4a1a0:	02c02825 */ 	or	$a1,$s6,$zero
/*    4a1a4:	8e84000c */ 	lw	$a0,0xc($s4)
/*    4a1a8:	0c0121bc */ 	jal	func000486f0
/*    4a1ac:	02e03025 */ 	or	$a2,$s7,$zero
/*    4a1b0:	8fa50074 */ 	lw	$a1,0x74($sp)
/*    4a1b4:	00003025 */ 	or	$a2,$zero,$zero
/*    4a1b8:	0c012238 */ 	jal	func000488e0
/*    4a1bc:	8ca40004 */ 	lw	$a0,0x4($a1)
/*    4a1c0:	8e840010 */ 	lw	$a0,0x10($s4)
/*    4a1c4:	00002825 */ 	or	$a1,$zero,$zero
/*    4a1c8:	0c012238 */ 	jal	func000488e0
/*    4a1cc:	00003025 */ 	or	$a2,$zero,$zero
/*    4a1d0:	1000ff1f */ 	beqz	$zero,.L00049e50
/*    4a1d4:	8e840008 */ 	lw	$a0,0x8($s4)
/*    4a1d8:	00000000 */ 	sll	$zero,$zero,0x0
/*    4a1dc:	00000000 */ 	sll	$zero,$zero,0x0
/*    4a1e0:	8fbf0044 */ 	lw	$ra,0x44($sp)
/*    4a1e4:	8fb00020 */ 	lw	$s0,0x20($sp)
/*    4a1e8:	8fb10024 */ 	lw	$s1,0x24($sp)
/*    4a1ec:	8fb20028 */ 	lw	$s2,0x28($sp)
/*    4a1f0:	8fb3002c */ 	lw	$s3,0x2c($sp)
/*    4a1f4:	8fb40030 */ 	lw	$s4,0x30($sp)
/*    4a1f8:	8fb50034 */ 	lw	$s5,0x34($sp)
/*    4a1fc:	8fb60038 */ 	lw	$s6,0x38($sp)
/*    4a200:	8fb7003c */ 	lw	$s7,0x3c($sp)
/*    4a204:	8fbe0040 */ 	lw	$s8,0x40($sp)
/*    4a208:	03e00008 */ 	jr	$ra
/*    4a20c:	27bd0078 */ 	addiu	$sp,$sp,0x78
);

GLOBAL_ASM(
glabel func0004a210
/*    4a210:	00803025 */ 	or	$a2,$a0,$zero
/*    4a214:	8cc70000 */ 	lw	$a3,0x0($a2)
/*    4a218:	27bdfff8 */ 	addiu	$sp,$sp,-8
/*    4a21c:	10e0000a */ 	beqz	$a3,.L0004a248
/*    4a220:	00000000 */ 	sll	$zero,$zero,0x0
.L0004a224:
/*    4a224:	14e50004 */ 	bne	$a3,$a1,.L0004a238
/*    4a228:	00000000 */ 	sll	$zero,$zero,0x0
/*    4a22c:	8cae0000 */ 	lw	$t6,0x0($a1)
/*    4a230:	10000005 */ 	beqz	$zero,.L0004a248
/*    4a234:	acce0000 */ 	sw	$t6,0x0($a2)
.L0004a238:
/*    4a238:	00e03025 */ 	or	$a2,$a3,$zero
/*    4a23c:	8cc70000 */ 	lw	$a3,0x0($a2)
/*    4a240:	14e0fff8 */ 	bnez	$a3,.L0004a224
/*    4a244:	00000000 */ 	sll	$zero,$zero,0x0
.L0004a248:
/*    4a248:	03e00008 */ 	jr	$ra
/*    4a24c:	27bd0008 */ 	addiu	$sp,$sp,0x8
);

GLOBAL_ASM(
glabel func0004a250
/*    4a250:	27bdffc8 */ 	addiu	$sp,$sp,-56
/*    4a254:	afbf0024 */ 	sw	$ra,0x24($sp)
/*    4a258:	afa40038 */ 	sw	$a0,0x38($sp)
/*    4a25c:	afb20020 */ 	sw	$s2,0x20($sp)
/*    4a260:	afb1001c */ 	sw	$s1,0x1c($sp)
/*    4a264:	0c01256c */ 	jal	func000495b0
/*    4a268:	afb00018 */ 	sw	$s0,0x18($sp)
/*    4a26c:	8fae0038 */ 	lw	$t6,0x38($sp)
/*    4a270:	00408025 */ 	or	$s0,$v0,$zero
/*    4a274:	15c00005 */ 	bnez	$t6,.L0004a28c
/*    4a278:	00000000 */ 	sll	$zero,$zero,0x0
/*    4a27c:	3c0f8006 */ 	lui	$t7,0x8006
/*    4a280:	8def0940 */ 	lw	$t7,0x940($t7)
/*    4a284:	10000009 */ 	beqz	$zero,.L0004a2ac
/*    4a288:	afaf0038 */ 	sw	$t7,0x38($sp)
.L0004a28c:
/*    4a28c:	8fb80038 */ 	lw	$t8,0x38($sp)
/*    4a290:	24010001 */ 	addiu	$at,$zero,0x1
/*    4a294:	97190010 */ 	lhu	$t9,0x10($t8)
/*    4a298:	13210004 */ 	beq	$t9,$at,.L0004a2ac
/*    4a29c:	00000000 */ 	sll	$zero,$zero,0x0
/*    4a2a0:	8f040008 */ 	lw	$a0,0x8($t8)
/*    4a2a4:	0c012884 */ 	jal	func0004a210
/*    4a2a8:	03002825 */ 	or	$a1,$t8,$zero
.L0004a2ac:
/*    4a2ac:	3c088006 */ 	lui	$t0,0x8006
/*    4a2b0:	8d08093c */ 	lw	$t0,0x93c($t0)
/*    4a2b4:	8fa90038 */ 	lw	$t1,0x38($sp)
/*    4a2b8:	15090005 */ 	bne	$t0,$t1,.L0004a2d0
/*    4a2bc:	00000000 */ 	sll	$zero,$zero,0x0
/*    4a2c0:	8d0a000c */ 	lw	$t2,0xc($t0)
/*    4a2c4:	3c018006 */ 	lui	$at,0x8006
/*    4a2c8:	10000013 */ 	beqz	$zero,.L0004a318
/*    4a2cc:	ac2a093c */ 	sw	$t2,0x93c($at)
.L0004a2d0:
/*    4a2d0:	3c118006 */ 	lui	$s1,0x8006
/*    4a2d4:	8e31093c */ 	lw	$s1,0x93c($s1)
/*    4a2d8:	2401ffff */ 	addiu	$at,$zero,-1
/*    4a2dc:	8e2b0004 */ 	lw	$t3,0x4($s1)
/*    4a2e0:	1161000d */ 	beq	$t3,$at,.L0004a318
/*    4a2e4:	00000000 */ 	sll	$zero,$zero,0x0
.L0004a2e8:
/*    4a2e8:	8e32000c */ 	lw	$s2,0xc($s1)
/*    4a2ec:	8fac0038 */ 	lw	$t4,0x38($sp)
/*    4a2f0:	164c0004 */ 	bne	$s2,$t4,.L0004a304
/*    4a2f4:	00000000 */ 	sll	$zero,$zero,0x0
/*    4a2f8:	8d8d000c */ 	lw	$t5,0xc($t4)
/*    4a2fc:	10000006 */ 	beqz	$zero,.L0004a318
/*    4a300:	ae2d000c */ 	sw	$t5,0xc($s1)
.L0004a304:
/*    4a304:	02408825 */ 	or	$s1,$s2,$zero
/*    4a308:	8e2e0004 */ 	lw	$t6,0x4($s1)
/*    4a30c:	2401ffff */ 	addiu	$at,$zero,-1
/*    4a310:	15c1fff5 */ 	bne	$t6,$at,.L0004a2e8
/*    4a314:	00000000 */ 	sll	$zero,$zero,0x0
.L0004a318:
/*    4a318:	3c198006 */ 	lui	$t9,0x8006
/*    4a31c:	8f390940 */ 	lw	$t9,0x940($t9)
/*    4a320:	8faf0038 */ 	lw	$t7,0x38($sp)
/*    4a324:	15f90003 */ 	bne	$t7,$t9,.L0004a334
/*    4a328:	00000000 */ 	sll	$zero,$zero,0x0
/*    4a32c:	0c000f44 */ 	jal	func00003d10
/*    4a330:	00000000 */ 	sll	$zero,$zero,0x0
.L0004a334:
/*    4a334:	0c012588 */ 	jal	func00049620
/*    4a338:	02002025 */ 	or	$a0,$s0,$zero
/*    4a33c:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*    4a340:	8fb00018 */ 	lw	$s0,0x18($sp)
/*    4a344:	8fb1001c */ 	lw	$s1,0x1c($sp)
/*    4a348:	8fb20020 */ 	lw	$s2,0x20($sp)
/*    4a34c:	03e00008 */ 	jr	$ra
/*    4a350:	27bd0038 */ 	addiu	$sp,$sp,0x38
/*    4a354:	00000000 */ 	sll	$zero,$zero,0x0
/*    4a358:	00000000 */ 	sll	$zero,$zero,0x0
/*    4a35c:	00000000 */ 	sll	$zero,$zero,0x0
);