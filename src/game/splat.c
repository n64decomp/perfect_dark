#include <ultra64.h>
#include "constants.h"
#include "game/data/data_000000.h"
#include "game/data/data_0083d0.h"
#include "game/data/data_00e460.h"
#include "game/data/data_0160b0.h"
#include "game/data/data_01a3a0.h"
#include "game/data/data_020df0.h"
#include "game/data/data_02da90.h"
#include "game/smoke.h"
#include "game/game_157db0.h"
#include "game/propobj.h"
#include "game/splat.h"
#include "game/utils.h"
#include "game/wallhit.h"
#include "gvars/gvars.h"
#include "lib/lib_12dc0.h"
#include "lib/lib_159b0.h"
#include "lib/lib_16110.h"
#include "lib/lib_1a500.h"
#include "types.h"

const char var7f1b5f70[] = "Splat Tick - P=%x, B=%d, T=%d, S=%d, W=%d, D=%d, H=%d\n";
const char var7f1b5fa8[] = "SPLAT : Not Dead Enough %s%s%f";
const char var7f1b5fc8[] = "";
const char var7f1b5fcc[] = "";

const char var7f1b5fd0[] = "splat.c";
const char var7f1b5fd8[] = "splat.c";
const char var7f1b5fe0[] = "Splat : Out of range\n";
const char var7f1b5ff8[] = "Splat_ResetChr : Reset One Char : chrdata = %x\n";

GLOBAL_ASM(
glabel func0f148b80
/*  f148b80:	27bdffb0 */ 	addiu	$sp,$sp,-80
/*  f148b84:	afbf0034 */ 	sw	$ra,0x34($sp)
/*  f148b88:	afa40050 */ 	sw	$a0,0x50($sp)
/*  f148b8c:	8c830004 */ 	lw	$v1,0x4($a0)
/*  f148b90:	8c6f0350 */ 	lw	$t7,0x350($v1)
/*  f148b94:	afaf0048 */ 	sw	$t7,0x48($sp)
/*  f148b98:	8c78032c */ 	lw	$t8,0x32c($v1)
/*  f148b9c:	00184cc0 */ 	sll	$t1,$t8,0x13
/*  f148ba0:	052200a9 */ 	bltzl	$t1,.L0f148e48
/*  f148ba4:	8fbf0034 */ 	lw	$ra,0x34($sp)
/*  f148ba8:	8c6a0018 */ 	lw	$t2,0x18($v1)
/*  f148bac:	314b0400 */ 	andi	$t3,$t2,0x400
/*  f148bb0:	556000a5 */ 	bnezl	$t3,.L0f148e48
/*  f148bb4:	8fbf0034 */ 	lw	$ra,0x34($sp)
/*  f148bb8:	90640334 */ 	lbu	$a0,0x334($v1)
/*  f148bbc:	24010002 */ 	addiu	$at,$zero,0x2
/*  f148bc0:	508000a1 */ 	beqzl	$a0,.L0f148e48
/*  f148bc4:	8fbf0034 */ 	lw	$ra,0x34($sp)
/*  f148bc8:	10600003 */ 	beqz	$v1,.L0f148bd8
/*  f148bcc:	00001025 */ 	or	$v0,$zero,$zero
/*  f148bd0:	10000001 */ 	b	.L0f148bd8
/*  f148bd4:	906202fe */ 	lbu	$v0,0x2fe($v1)
.L0f148bd8:
/*  f148bd8:	10410095 */ 	beq	$v0,$at,.L0f148e30
/*  f148bdc:	24050004 */ 	addiu	$a1,$zero,0x4
/*  f148be0:	10450093 */ 	beq	$v0,$a1,.L0f148e30
/*  f148be4:	24010001 */ 	addiu	$at,$zero,0x1
/*  f148be8:	10410005 */ 	beq	$v0,$at,.L0f148c00
/*  f148bec:	00004025 */ 	or	$t0,$zero,$zero
/*  f148bf0:	846c0010 */ 	lh	$t4,0x10($v1)
/*  f148bf4:	2401005b */ 	addiu	$at,$zero,0x5b
/*  f148bf8:	55810003 */ 	bnel	$t4,$at,.L0f148c08
/*  f148bfc:	80620007 */ 	lb	$v0,0x7($v1)
.L0f148c00:
/*  f148c00:	24080001 */ 	addiu	$t0,$zero,0x1
/*  f148c04:	80620007 */ 	lb	$v0,0x7($v1)
.L0f148c08:
/*  f148c08:	24010005 */ 	addiu	$at,$zero,0x5
/*  f148c0c:	50410003 */ 	beql	$v0,$at,.L0f148c1c
/*  f148c10:	3c01bf80 */ 	lui	$at,0xbf80
/*  f148c14:	14a20048 */ 	bne	$a1,$v0,.L0f148d38
/*  f148c18:	3c01bf80 */ 	lui	$at,0xbf80
.L0f148c1c:
/*  f148c1c:	44816000 */ 	mtc1	$at,$f12
/*  f148c20:	14a2000e */ 	bne	$a1,$v0,.L0f148c5c
/*  f148c24:	46006086 */ 	mov.s	$f2,$f12
/*  f148c28:	c4600034 */ 	lwc1	$f0,0x34($v1)
/*  f148c2c:	46006032 */ 	c.eq.s	$f12,$f0
/*  f148c30:	00000000 */ 	nop
/*  f148c34:	45030004 */ 	bc1tl	.L0f148c48
/*  f148c38:	c4600030 */ 	lwc1	$f0,0x30($v1)
/*  f148c3c:	10000007 */ 	b	.L0f148c5c
/*  f148c40:	46000086 */ 	mov.s	$f2,$f0
/*  f148c44:	c4600030 */ 	lwc1	$f0,0x30($v1)
.L0f148c48:
/*  f148c48:	46006032 */ 	c.eq.s	$f12,$f0
/*  f148c4c:	00000000 */ 	nop
/*  f148c50:	45030003 */ 	bc1tl	.L0f148c60
/*  f148c54:	460c1032 */ 	c.eq.s	$f2,$f12
/*  f148c58:	46000086 */ 	mov.s	$f2,$f0
.L0f148c5c:
/*  f148c5c:	460c1032 */ 	c.eq.s	$f2,$f12
.L0f148c60:
/*  f148c60:	00000000 */ 	nop
/*  f148c64:	45030013 */ 	bc1tl	.L0f148cb4
/*  f148c68:	946d0336 */ 	lhu	$t5,0x336($v1)
/*  f148c6c:	8c640020 */ 	lw	$a0,0x20($v1)
/*  f148c70:	e7a20038 */ 	swc1	$f2,0x38($sp)
/*  f148c74:	a3a80043 */ 	sb	$t0,0x43($sp)
/*  f148c78:	0c00745f */ 	jal	modelGetCurAnimFrame
/*  f148c7c:	afa3004c */ 	sw	$v1,0x4c($sp)
/*  f148c80:	c7a20038 */ 	lwc1	$f2,0x38($sp)
/*  f148c84:	8fa3004c */ 	lw	$v1,0x4c($sp)
/*  f148c88:	93a80043 */ 	lbu	$t0,0x43($sp)
/*  f148c8c:	4602003c */ 	c.lt.s	$f0,$f2
/*  f148c90:	00000000 */ 	nop
/*  f148c94:	45020007 */ 	bc1fl	.L0f148cb4
/*  f148c98:	946d0336 */ 	lhu	$t5,0x336($v1)
/*  f148c9c:	8c640020 */ 	lw	$a0,0x20($v1)
/*  f148ca0:	0c00745f */ 	jal	modelGetCurAnimFrame
/*  f148ca4:	afa3004c */ 	sw	$v1,0x4c($sp)
/*  f148ca8:	10000061 */ 	b	.L0f148e30
/*  f148cac:	8fa3004c */ 	lw	$v1,0x4c($sp)
/*  f148cb0:	946d0336 */ 	lhu	$t5,0x336($v1)
.L0f148cb4:
/*  f148cb4:	29a1001f */ 	slti	$at,$t5,0x1f
/*  f148cb8:	1420005d */ 	bnez	$at,.L0f148e30
/*  f148cbc:	00000000 */ 	nop
/*  f148cc0:	906e033a */ 	lbu	$t6,0x33a($v1)
/*  f148cc4:	29c10006 */ 	slti	$at,$t6,0x6
/*  f148cc8:	10200059 */ 	beqz	$at,.L0f148e30
/*  f148ccc:	00000000 */ 	nop
/*  f148cd0:	afa3004c */ 	sw	$v1,0x4c($sp)
/*  f148cd4:	0c004b70 */ 	jal	random
/*  f148cd8:	a3a80043 */ 	sb	$t0,0x43($sp)
/*  f148cdc:	93a80043 */ 	lbu	$t0,0x43($sp)
/*  f148ce0:	8fb90048 */ 	lw	$t9,0x48($sp)
/*  f148ce4:	3c053f8c */ 	lui	$a1,0x3f8c
/*  f148ce8:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f148cec:	24180096 */ 	addiu	$t8,$zero,0x96
/*  f148cf0:	30490008 */ 	andi	$t1,$v0,0x8
/*  f148cf4:	afa90028 */ 	sw	$t1,0x28($sp)
/*  f148cf8:	afb80020 */ 	sw	$t8,0x20($sp)
/*  f148cfc:	afaf001c */ 	sw	$t7,0x1c($sp)
/*  f148d00:	34a5cccd */ 	ori	$a1,$a1,0xcccd
/*  f148d04:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f148d08:	8fa60050 */ 	lw	$a2,0x50($sp)
/*  f148d0c:	00003825 */ 	or	$a3,$zero,$zero
/*  f148d10:	afa00010 */ 	sw	$zero,0x10($sp)
/*  f148d14:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f148d18:	afa80018 */ 	sw	$t0,0x18($sp)
/*  f148d1c:	0fc523c6 */ 	jal	func0f148f18
/*  f148d20:	afb90024 */ 	sw	$t9,0x24($sp)
/*  f148d24:	8fa3004c */ 	lw	$v1,0x4c($sp)
/*  f148d28:	906a033a */ 	lbu	$t2,0x33a($v1)
/*  f148d2c:	01425821 */ 	addu	$t3,$t2,$v0
/*  f148d30:	1000003f */ 	b	.L0f148e30
/*  f148d34:	a06b033a */ 	sb	$t3,0x33a($v1)
.L0f148d38:
/*  f148d38:	946c0336 */ 	lhu	$t4,0x336($v1)
/*  f148d3c:	8fa50050 */ 	lw	$a1,0x50($sp)
/*  f148d40:	008c0019 */ 	multu	$a0,$t4
/*  f148d44:	2464033c */ 	addiu	$a0,$v1,0x33c
/*  f148d48:	24a50008 */ 	addiu	$a1,$a1,0x8
/*  f148d4c:	00001012 */ 	mflo	$v0
/*  f148d50:	2c4100f1 */ 	sltiu	$at,$v0,0xf1
/*  f148d54:	5420002b */ 	bnezl	$at,.L0f148e04
/*  f148d58:	906a0335 */ 	lbu	$t2,0x335($v1)
/*  f148d5c:	afa3004c */ 	sw	$v1,0x4c($sp)
/*  f148d60:	0fc5dd18 */ 	jal	func0f177460
/*  f148d64:	a3a80043 */ 	sb	$t0,0x43($sp)
/*  f148d68:	3c014220 */ 	lui	$at,0x4220
/*  f148d6c:	44812000 */ 	mtc1	$at,$f4
/*  f148d70:	3c053e99 */ 	lui	$a1,0x3e99
/*  f148d74:	8fa3004c */ 	lw	$v1,0x4c($sp)
/*  f148d78:	4600203c */ 	c.lt.s	$f4,$f0
/*  f148d7c:	93a80043 */ 	lbu	$t0,0x43($sp)
/*  f148d80:	00001025 */ 	or	$v0,$zero,$zero
/*  f148d84:	34a5999a */ 	ori	$a1,$a1,0x999a
/*  f148d88:	45000004 */ 	bc1f	.L0f148d9c
/*  f148d8c:	00003825 */ 	or	$a3,$zero,$zero
/*  f148d90:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f148d94:	10000007 */ 	b	.L0f148db4
/*  f148d98:	a0600338 */ 	sb	$zero,0x338($v1)
.L0f148d9c:
/*  f148d9c:	90640338 */ 	lbu	$a0,0x338($v1)
/*  f148da0:	28810008 */ 	slti	$at,$a0,0x8
/*  f148da4:	10200003 */ 	beqz	$at,.L0f148db4
/*  f148da8:	248d0001 */ 	addiu	$t5,$a0,0x1
/*  f148dac:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f148db0:	a06d0338 */ 	sb	$t5,0x338($v1)
.L0f148db4:
/*  f148db4:	10400012 */ 	beqz	$v0,.L0f148e00
/*  f148db8:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f148dbc:	8fb80048 */ 	lw	$t8,0x48($sp)
/*  f148dc0:	240e0002 */ 	addiu	$t6,$zero,0x2
/*  f148dc4:	240f0050 */ 	addiu	$t7,$zero,0x50
/*  f148dc8:	afaf0020 */ 	sw	$t7,0x20($sp)
/*  f148dcc:	afae001c */ 	sw	$t6,0x1c($sp)
/*  f148dd0:	8fa60050 */ 	lw	$a2,0x50($sp)
/*  f148dd4:	afa00010 */ 	sw	$zero,0x10($sp)
/*  f148dd8:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f148ddc:	afa80018 */ 	sw	$t0,0x18($sp)
/*  f148de0:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f148de4:	afa3004c */ 	sw	$v1,0x4c($sp)
/*  f148de8:	0fc523c6 */ 	jal	func0f148f18
/*  f148dec:	afb80024 */ 	sw	$t8,0x24($sp)
/*  f148df0:	8fa3004c */ 	lw	$v1,0x4c($sp)
/*  f148df4:	90790335 */ 	lbu	$t9,0x335($v1)
/*  f148df8:	03224821 */ 	addu	$t1,$t9,$v0
/*  f148dfc:	a0690335 */ 	sb	$t1,0x335($v1)
.L0f148e00:
/*  f148e00:	906a0335 */ 	lbu	$t2,0x335($v1)
.L0f148e04:
/*  f148e04:	8fa40050 */ 	lw	$a0,0x50($sp)
/*  f148e08:	29410028 */ 	slti	$at,$t2,0x28
/*  f148e0c:	54200008 */ 	bnezl	$at,.L0f148e30
/*  f148e10:	a060033a */ 	sb	$zero,0x33a($v1)
/*  f148e14:	0fc505c1 */ 	jal	func0f141704
/*  f148e18:	afa3004c */ 	sw	$v1,0x4c($sp)
/*  f148e1c:	8fa3004c */ 	lw	$v1,0x4c($sp)
/*  f148e20:	906b0335 */ 	lbu	$t3,0x335($v1)
/*  f148e24:	256cffff */ 	addiu	$t4,$t3,-1
/*  f148e28:	a06c0335 */ 	sb	$t4,0x335($v1)
/*  f148e2c:	a060033a */ 	sb	$zero,0x33a($v1)
.L0f148e30:
/*  f148e30:	3c0e800a */ 	lui	$t6,%hi(g_Vars+0x38)
/*  f148e34:	8dce9ff8 */ 	lw	$t6,%lo(g_Vars+0x38)($t6)
/*  f148e38:	946d0336 */ 	lhu	$t5,0x336($v1)
/*  f148e3c:	01ae7821 */ 	addu	$t7,$t5,$t6
/*  f148e40:	a46f0336 */ 	sh	$t7,0x336($v1)
/*  f148e44:	8fbf0034 */ 	lw	$ra,0x34($sp)
.L0f148e48:
/*  f148e48:	27bd0050 */ 	addiu	$sp,$sp,0x50
/*  f148e4c:	03e00008 */ 	jr	$ra
/*  f148e50:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel func0f148e54
/*  f148e54:	27bdffc0 */ 	addiu	$sp,$sp,-64
/*  f148e58:	afbf0034 */ 	sw	$ra,0x34($sp)
/*  f148e5c:	afa40040 */ 	sw	$a0,0x40($sp)
/*  f148e60:	afa50044 */ 	sw	$a1,0x44($sp)
/*  f148e64:	afa60048 */ 	sw	$a2,0x48($sp)
/*  f148e68:	afa7004c */ 	sw	$a3,0x4c($sp)
/*  f148e6c:	8c880004 */ 	lw	$t0,0x4($a0)
/*  f148e70:	91020334 */ 	lbu	$v0,0x334($t0)
/*  f148e74:	28410007 */ 	slti	$at,$v0,0x7
/*  f148e78:	10200002 */ 	beqz	$at,.L0f148e84
/*  f148e7c:	244f0001 */ 	addiu	$t7,$v0,0x1
/*  f148e80:	a10f0334 */ 	sb	$t7,0x334($t0)
.L0f148e84:
/*  f148e84:	8fb80054 */ 	lw	$t8,0x54($sp)
/*  f148e88:	57000020 */ 	bnezl	$t8,.L0f148f0c
/*  f148e8c:	8fbf0034 */ 	lw	$ra,0x34($sp)
/*  f148e90:	0c004b70 */ 	jal	random
/*  f148e94:	afa8003c */ 	sw	$t0,0x3c($sp)
/*  f148e98:	24010003 */ 	addiu	$at,$zero,0x3
/*  f148e9c:	0041001b */ 	divu	$zero,$v0,$at
/*  f148ea0:	00002010 */ 	mfhi	$a0
/*  f148ea4:	8fa8003c */ 	lw	$t0,0x3c($sp)
/*  f148ea8:	10800017 */ 	beqz	$a0,.L0f148f08
/*  f148eac:	3c053f4c */ 	lui	$a1,0x3f4c
/*  f148eb0:	8fb90048 */ 	lw	$t9,0x48($sp)
/*  f148eb4:	8fa9004c */ 	lw	$t1,0x4c($sp)
/*  f148eb8:	8faa0050 */ 	lw	$t2,0x50($sp)
/*  f148ebc:	8fab0054 */ 	lw	$t3,0x54($sp)
/*  f148ec0:	8fad0058 */ 	lw	$t5,0x58($sp)
/*  f148ec4:	240c0032 */ 	addiu	$t4,$zero,0x32
/*  f148ec8:	afac0020 */ 	sw	$t4,0x20($sp)
/*  f148ecc:	34a5cccd */ 	ori	$a1,$a1,0xcccd
/*  f148ed0:	8fa60040 */ 	lw	$a2,0x40($sp)
/*  f148ed4:	8fa70044 */ 	lw	$a3,0x44($sp)
/*  f148ed8:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f148edc:	afa8003c */ 	sw	$t0,0x3c($sp)
/*  f148ee0:	afb90010 */ 	sw	$t9,0x10($sp)
/*  f148ee4:	afa90014 */ 	sw	$t1,0x14($sp)
/*  f148ee8:	afaa0018 */ 	sw	$t2,0x18($sp)
/*  f148eec:	afab001c */ 	sw	$t3,0x1c($sp)
/*  f148ef0:	0fc523c6 */ 	jal	func0f148f18
/*  f148ef4:	afad0024 */ 	sw	$t5,0x24($sp)
/*  f148ef8:	8fa8003c */ 	lw	$t0,0x3c($sp)
/*  f148efc:	910e0339 */ 	lbu	$t6,0x339($t0)
/*  f148f00:	01c27821 */ 	addu	$t7,$t6,$v0
/*  f148f04:	a10f0339 */ 	sb	$t7,0x339($t0)
.L0f148f08:
/*  f148f08:	8fbf0034 */ 	lw	$ra,0x34($sp)
.L0f148f0c:
/*  f148f0c:	27bd0040 */ 	addiu	$sp,$sp,0x40
/*  f148f10:	03e00008 */ 	jr	$ra
/*  f148f14:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel func0f148f18
.late_rodata
glabel var7f1b6028
.word 0x3f333333
glabel var7f1b602c
.word 0x3c8efa35
glabel var7f1b6030
.word 0x497423f0
.text
/*  f148f18:	27bdfaa8 */ 	addiu	$sp,$sp,-1368
/*  f148f1c:	8fae0574 */ 	lw	$t6,0x574($sp)
/*  f148f20:	f7ba0048 */ 	sdc1	$f26,0x48($sp)
/*  f148f24:	4485d000 */ 	mtc1	$a1,$f26
/*  f148f28:	afbf0074 */ 	sw	$ra,0x74($sp)
/*  f148f2c:	afbe0070 */ 	sw	$s8,0x70($sp)
/*  f148f30:	afb7006c */ 	sw	$s7,0x6c($sp)
/*  f148f34:	afb60068 */ 	sw	$s6,0x68($sp)
/*  f148f38:	afb50064 */ 	sw	$s5,0x64($sp)
/*  f148f3c:	afb40060 */ 	sw	$s4,0x60($sp)
/*  f148f40:	afb3005c */ 	sw	$s3,0x5c($sp)
/*  f148f44:	afb20058 */ 	sw	$s2,0x58($sp)
/*  f148f48:	afb10054 */ 	sw	$s1,0x54($sp)
/*  f148f4c:	afb00050 */ 	sw	$s0,0x50($sp)
/*  f148f50:	f7b80040 */ 	sdc1	$f24,0x40($sp)
/*  f148f54:	f7b60038 */ 	sdc1	$f22,0x38($sp)
/*  f148f58:	f7b40030 */ 	sdc1	$f20,0x30($sp)
/*  f148f5c:	15c00003 */ 	bnez	$t6,.L0f148f6c
/*  f148f60:	afa40558 */ 	sw	$a0,0x558($sp)
/*  f148f64:	10000002 */ 	b	.L0f148f70
/*  f148f68:	00e0b825 */ 	or	$s7,$a3,$zero
.L0f148f6c:
/*  f148f6c:	27b7010c */ 	addiu	$s7,$sp,0x10c
.L0f148f70:
/*  f148f70:	8faf0574 */ 	lw	$t7,0x574($sp)
/*  f148f74:	0000f025 */ 	or	$s8,$zero,$zero
/*  f148f78:	8fb0056c */ 	lw	$s0,0x56c($sp)
/*  f148f7c:	15e00029 */ 	bnez	$t7,.L0f149024
/*  f148f80:	26e4001c */ 	addiu	$a0,$s7,0x1c
/*  f148f84:	02002825 */ 	or	$a1,$s0,$zero
/*  f148f88:	0fc5dd18 */ 	jal	func0f177460
/*  f148f8c:	afa60560 */ 	sw	$a2,0x560($sp)
/*  f148f90:	46000606 */ 	mov.s	$f24,$f0
/*  f148f94:	27a400fc */ 	addiu	$a0,$sp,0xfc
/*  f148f98:	02e01025 */ 	or	$v0,$s7,$zero
/*  f148f9c:	27a300f0 */ 	addiu	$v1,$sp,0xf0
/*  f148fa0:	02002825 */ 	or	$a1,$s0,$zero
/*  f148fa4:	8fa60568 */ 	lw	$a2,0x568($sp)
/*  f148fa8:	27a700fc */ 	addiu	$a3,$sp,0xfc
/*  f148fac:	24630004 */ 	addiu	$v1,$v1,0x4
/*  f148fb0:	1067000f */ 	beq	$v1,$a3,.L0f148ff0
/*  f148fb4:	c4560028 */ 	lwc1	$f22,0x28($v0)
.L0f148fb8:
/*  f148fb8:	e4960000 */ 	swc1	$f22,0x0($a0)
/*  f148fbc:	c454000c */ 	lwc1	$f20,0xc($v0)
/*  f148fc0:	24630004 */ 	addiu	$v1,$v1,0x4
/*  f148fc4:	24840004 */ 	addiu	$a0,$a0,0x4
/*  f148fc8:	e474fff8 */ 	swc1	$f20,-0x8($v1)
/*  f148fcc:	c4b40000 */ 	lwc1	$f20,0x0($a1)
/*  f148fd0:	c456002c */ 	lwc1	$f22,0x2c($v0)
/*  f148fd4:	24420004 */ 	addiu	$v0,$v0,0x4
/*  f148fd8:	e4540018 */ 	swc1	$f20,0x18($v0)
/*  f148fdc:	c4d40000 */ 	lwc1	$f20,0x0($a2)
/*  f148fe0:	24a50004 */ 	addiu	$a1,$a1,0x4
/*  f148fe4:	24c60004 */ 	addiu	$a2,$a2,0x4
/*  f148fe8:	1467fff3 */ 	bne	$v1,$a3,.L0f148fb8
/*  f148fec:	e454fffc */ 	swc1	$f20,-0x4($v0)
.L0f148ff0:
/*  f148ff0:	e4960000 */ 	swc1	$f22,0x0($a0)
/*  f148ff4:	c454000c */ 	lwc1	$f20,0xc($v0)
/*  f148ff8:	24840004 */ 	addiu	$a0,$a0,0x4
/*  f148ffc:	24420004 */ 	addiu	$v0,$v0,0x4
/*  f149000:	e474fffc */ 	swc1	$f20,-0x4($v1)
/*  f149004:	c4b40000 */ 	lwc1	$f20,0x0($a1)
/*  f149008:	24a50004 */ 	addiu	$a1,$a1,0x4
/*  f14900c:	24c60004 */ 	addiu	$a2,$a2,0x4
/*  f149010:	e4540018 */ 	swc1	$f20,0x18($v0)
/*  f149014:	c4d4fffc */ 	lwc1	$f20,-0x4($a2)
/*  f149018:	e454fffc */ 	swc1	$f20,-0x4($v0)
/*  f14901c:	1000002c */ 	b	.L0f1490d0
/*  f149020:	8fb90558 */ 	lw	$t9,0x558($sp)
.L0f149024:
/*  f149024:	90d80000 */ 	lbu	$t8,0x0($a2)
/*  f149028:	24010003 */ 	addiu	$at,$zero,0x3
/*  f14902c:	17010005 */ 	bne	$t8,$at,.L0f149044
/*  f149030:	3c014248 */ 	lui	$at,0x4248
/*  f149034:	44816000 */ 	mtc1	$at,$f12
/*  f149038:	44800000 */ 	mtc1	$zero,$f0
/*  f14903c:	10000005 */ 	b	.L0f149054
/*  f149040:	3c01bf80 */ 	lui	$at,0xbf80
.L0f149044:
/*  f149044:	44800000 */ 	mtc1	$zero,$f0
/*  f149048:	00000000 */ 	nop
/*  f14904c:	46000306 */ 	mov.s	$f12,$f0
/*  f149050:	3c01bf80 */ 	lui	$at,0xbf80
.L0f149054:
/*  f149054:	44811000 */ 	mtc1	$at,$f2
/*  f149058:	3c017f1b */ 	lui	$at,%hi(var7f1b6028)
/*  f14905c:	c4386028 */ 	lwc1	$f24,%lo(var7f1b6028)($at)
/*  f149060:	e6e00028 */ 	swc1	$f0,0x28($s7)
/*  f149064:	e7a000fc */ 	swc1	$f0,0xfc($sp)
/*  f149068:	e6e2002c */ 	swc1	$f2,0x2c($s7)
/*  f14906c:	e7a20100 */ 	swc1	$f2,0x100($sp)
/*  f149070:	e6e00030 */ 	swc1	$f0,0x30($s7)
/*  f149074:	e7a00104 */ 	swc1	$f0,0x104($sp)
/*  f149078:	e6e0000c */ 	swc1	$f0,0xc($s7)
/*  f14907c:	e7a000f0 */ 	swc1	$f0,0xf0($sp)
/*  f149080:	e6e20010 */ 	swc1	$f2,0x10($s7)
/*  f149084:	e7a200f4 */ 	swc1	$f2,0xf4($sp)
/*  f149088:	e6e00014 */ 	swc1	$f0,0x14($s7)
/*  f14908c:	e7a000f8 */ 	swc1	$f0,0xf8($sp)
/*  f149090:	c4d00008 */ 	lwc1	$f16,0x8($a2)
/*  f149094:	e6f0001c */ 	swc1	$f16,0x1c($s7)
/*  f149098:	c4d2000c */ 	lwc1	$f18,0xc($a2)
/*  f14909c:	460c9100 */ 	add.s	$f4,$f18,$f12
/*  f1490a0:	e6e40020 */ 	swc1	$f4,0x20($s7)
/*  f1490a4:	c4c60010 */ 	lwc1	$f6,0x10($a2)
/*  f1490a8:	e6e60024 */ 	swc1	$f6,0x24($s7)
/*  f1490ac:	c4c80008 */ 	lwc1	$f8,0x8($a2)
/*  f1490b0:	e6e80000 */ 	swc1	$f8,0x0($s7)
/*  f1490b4:	c4ca000c */ 	lwc1	$f10,0xc($a2)
/*  f1490b8:	460c5400 */ 	add.s	$f16,$f10,$f12
/*  f1490bc:	e6f00004 */ 	swc1	$f16,0x4($s7)
/*  f1490c0:	c4d20010 */ 	lwc1	$f18,0x10($a2)
/*  f1490c4:	e6f20008 */ 	swc1	$f18,0x8($s7)
/*  f1490c8:	afa60560 */ 	sw	$a2,0x560($sp)
/*  f1490cc:	8fb90558 */ 	lw	$t9,0x558($sp)
.L0f1490d0:
/*  f1490d0:	8fa60560 */ 	lw	$a2,0x560($sp)
/*  f1490d4:	0000a025 */ 	or	$s4,$zero,$zero
/*  f1490d8:	1b20004b */ 	blez	$t9,.L0f149208
/*  f1490dc:	26f50028 */ 	addiu	$s5,$s7,0x28
/*  f1490e0:	3c017f1b */ 	lui	$at,%hi(var7f1b602c)
/*  f1490e4:	c436602c */ 	lwc1	$f22,%lo(var7f1b602c)($at)
/*  f1490e8:	3c012f80 */ 	lui	$at,0x2f80
/*  f1490ec:	3c118008 */ 	lui	$s1,%hi(var8007f8a8)
/*  f1490f0:	4481a000 */ 	mtc1	$at,$f20
/*  f1490f4:	2631f8a8 */ 	addiu	$s1,$s1,%lo(var8007f8a8)
/*  f1490f8:	26f6000c */ 	addiu	$s6,$s7,0xc
/*  f1490fc:	afa60560 */ 	sw	$a2,0x560($sp)
/*  f149100:	27b300a4 */ 	addiu	$s3,$sp,0xa4
/*  f149104:	27b200f0 */ 	addiu	$s2,$sp,0xf0
/*  f149108:	27b000e4 */ 	addiu	$s0,$sp,0xe4
.L0f14910c:
/*  f14910c:	0c004b70 */ 	jal	random
/*  f149110:	00000000 */ 	nop
/*  f149114:	44822000 */ 	mtc1	$v0,$f4
/*  f149118:	c6200000 */ 	lwc1	$f0,0x0($s1)
/*  f14911c:	04410005 */ 	bgez	$v0,.L0f149134
/*  f149120:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f149124:	3c014f80 */ 	lui	$at,0x4f80
/*  f149128:	44814000 */ 	mtc1	$at,$f8
/*  f14912c:	00000000 */ 	nop
/*  f149130:	46083180 */ 	add.s	$f6,$f6,$f8
.L0f149134:
/*  f149134:	46143282 */ 	mul.s	$f10,$f6,$f20
/*  f149138:	26100004 */ 	addiu	$s0,$s0,0x4
/*  f14913c:	46005082 */ 	mul.s	$f2,$f10,$f0
/*  f149140:	46021400 */ 	add.s	$f16,$f2,$f2
/*  f149144:	46008481 */ 	sub.s	$f18,$f16,$f0
/*  f149148:	46169102 */ 	mul.s	$f4,$f18,$f22
/*  f14914c:	1612ffef */ 	bne	$s0,$s2,.L0f14910c
/*  f149150:	e604fffc */ 	swc1	$f4,-0x4($s0)
/*  f149154:	27a400e4 */ 	addiu	$a0,$sp,0xe4
/*  f149158:	0c005923 */ 	jal	func0001648c
/*  f14915c:	02602825 */ 	or	$a1,$s3,$zero
/*  f149160:	02602025 */ 	or	$a0,$s3,$zero
/*  f149164:	27a500fc */ 	addiu	$a1,$sp,0xfc
/*  f149168:	0c0056c5 */ 	jal	func00015b14
/*  f14916c:	02a03025 */ 	or	$a2,$s5,$zero
/*  f149170:	02602025 */ 	or	$a0,$s3,$zero
/*  f149174:	27a500f0 */ 	addiu	$a1,$sp,0xf0
/*  f149178:	0c0056c5 */ 	jal	func00015b14
/*  f14917c:	02c03025 */ 	or	$a2,$s6,$zero
/*  f149180:	3c077f1b */ 	lui	$a3,%hi(var7f1b5fd0)
/*  f149184:	24e75fd0 */ 	addiu	$a3,$a3,%lo(var7f1b5fd0)
/*  f149188:	02a02025 */ 	or	$a0,$s5,$zero
/*  f14918c:	02a02825 */ 	or	$a1,$s5,$zero
/*  f149190:	0fc5dc59 */ 	jal	func0f177164
/*  f149194:	24060193 */ 	addiu	$a2,$zero,0x193
/*  f149198:	3c077f1b */ 	lui	$a3,%hi(var7f1b5fd8)
/*  f14919c:	24e75fd8 */ 	addiu	$a3,$a3,%lo(var7f1b5fd8)
/*  f1491a0:	02c02025 */ 	or	$a0,$s6,$zero
/*  f1491a4:	02c02825 */ 	or	$a1,$s6,$zero
/*  f1491a8:	0fc5dc59 */ 	jal	func0f177164
/*  f1491ac:	24060194 */ 	addiu	$a2,$zero,0x194
/*  f1491b0:	8fa80570 */ 	lw	$t0,0x570($sp)
/*  f1491b4:	8fa90574 */ 	lw	$t1,0x574($sp)
/*  f1491b8:	8faa0578 */ 	lw	$t2,0x578($sp)
/*  f1491bc:	8fab057c */ 	lw	$t3,0x57c($sp)
/*  f1491c0:	8fac0580 */ 	lw	$t4,0x580($sp)
/*  f1491c4:	4407c000 */ 	mfc1	$a3,$f24
/*  f1491c8:	4600d306 */ 	mov.s	$f12,$f26
/*  f1491cc:	8fa50560 */ 	lw	$a1,0x560($sp)
/*  f1491d0:	02e03025 */ 	or	$a2,$s7,$zero
/*  f1491d4:	afa80010 */ 	sw	$t0,0x10($sp)
/*  f1491d8:	afa90014 */ 	sw	$t1,0x14($sp)
/*  f1491dc:	afaa0018 */ 	sw	$t2,0x18($sp)
/*  f1491e0:	afab001c */ 	sw	$t3,0x1c($sp)
/*  f1491e4:	0fc5249d */ 	jal	func0f149274
/*  f1491e8:	afac0020 */ 	sw	$t4,0x20($sp)
/*  f1491ec:	10400002 */ 	beqz	$v0,.L0f1491f8
/*  f1491f0:	8fad0558 */ 	lw	$t5,0x558($sp)
/*  f1491f4:	27de0001 */ 	addiu	$s8,$s8,0x1
.L0f1491f8:
/*  f1491f8:	26940001 */ 	addiu	$s4,$s4,0x1
/*  f1491fc:	568dffc3 */ 	bnel	$s4,$t5,.L0f14910c
/*  f149200:	27b000e4 */ 	addiu	$s0,$sp,0xe4
/*  f149204:	8fa60560 */ 	lw	$a2,0x560($sp)
.L0f149208:
/*  f149208:	53c0000a */ 	beqzl	$s8,.L0f149234
/*  f14920c:	8fbf0074 */ 	lw	$ra,0x74($sp)
/*  f149210:	8cc20004 */ 	lw	$v0,0x4($a2)
/*  f149214:	a4400336 */ 	sh	$zero,0x336($v0)
/*  f149218:	c4c80008 */ 	lwc1	$f8,0x8($a2)
/*  f14921c:	e448033c */ 	swc1	$f8,0x33c($v0)
/*  f149220:	c4c6000c */ 	lwc1	$f6,0xc($a2)
/*  f149224:	e4460340 */ 	swc1	$f6,0x340($v0)
/*  f149228:	c4ca0010 */ 	lwc1	$f10,0x10($a2)
/*  f14922c:	e44a0344 */ 	swc1	$f10,0x344($v0)
/*  f149230:	8fbf0074 */ 	lw	$ra,0x74($sp)
.L0f149234:
/*  f149234:	03c01025 */ 	or	$v0,$s8,$zero
/*  f149238:	8fbe0070 */ 	lw	$s8,0x70($sp)
/*  f14923c:	d7b40030 */ 	ldc1	$f20,0x30($sp)
/*  f149240:	d7b60038 */ 	ldc1	$f22,0x38($sp)
/*  f149244:	d7b80040 */ 	ldc1	$f24,0x40($sp)
/*  f149248:	d7ba0048 */ 	ldc1	$f26,0x48($sp)
/*  f14924c:	8fb00050 */ 	lw	$s0,0x50($sp)
/*  f149250:	8fb10054 */ 	lw	$s1,0x54($sp)
/*  f149254:	8fb20058 */ 	lw	$s2,0x58($sp)
/*  f149258:	8fb3005c */ 	lw	$s3,0x5c($sp)
/*  f14925c:	8fb40060 */ 	lw	$s4,0x60($sp)
/*  f149260:	8fb50064 */ 	lw	$s5,0x64($sp)
/*  f149264:	8fb60068 */ 	lw	$s6,0x68($sp)
/*  f149268:	8fb7006c */ 	lw	$s7,0x6c($sp)
/*  f14926c:	03e00008 */ 	jr	$ra
/*  f149270:	27bd0558 */ 	addiu	$sp,$sp,0x558
);

GLOBAL_ASM(
glabel func0f149274
/*  f149274:	27bdfa18 */ 	addiu	$sp,$sp,-1512
/*  f149278:	afbf001c */ 	sw	$ra,0x1c($sp)
/*  f14927c:	e7ac05e8 */ 	swc1	$f12,0x5e8($sp)
/*  f149280:	afa505ec */ 	sw	$a1,0x5ec($sp)
/*  f149284:	afa705f4 */ 	sw	$a3,0x5f4($sp)
/*  f149288:	afa00500 */ 	sw	$zero,0x500($sp)
/*  f14928c:	afa004ec */ 	sw	$zero,0x4ec($sp)
/*  f149290:	27a200a0 */ 	addiu	$v0,$sp,0xa0
/*  f149294:	27a400ac */ 	addiu	$a0,$sp,0xac
/*  f149298:	00c01825 */ 	or	$v1,$a2,$zero
.L0f14929c:
/*  f14929c:	c4640000 */ 	lwc1	$f4,0x0($v1)
/*  f1492a0:	24420004 */ 	addiu	$v0,$v0,0x4
/*  f1492a4:	0044082b */ 	sltu	$at,$v0,$a0
/*  f1492a8:	e444fffc */ 	swc1	$f4,-0x4($v0)
/*  f1492ac:	c466000c */ 	lwc1	$f6,0xc($v1)
/*  f1492b0:	24630004 */ 	addiu	$v1,$v1,0x4
/*  f1492b4:	e4460008 */ 	swc1	$f6,0x8($v0)
/*  f1492b8:	c4680018 */ 	lwc1	$f8,0x18($v1)
/*  f1492bc:	e4480018 */ 	swc1	$f8,0x18($v0)
/*  f1492c0:	c46a0024 */ 	lwc1	$f10,0x24($v1)
/*  f1492c4:	1420fff5 */ 	bnez	$at,.L0f14929c
/*  f1492c8:	e44a0024 */ 	swc1	$f10,0x24($v0)
/*  f1492cc:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f1492d0:	3c018008 */ 	lui	$at,0x8008
/*  f1492d4:	afae00d8 */ 	sw	$t6,0xd8($sp)
/*  f1492d8:	c420f8b0 */ 	lwc1	$f0,-0x750($at)
/*  f1492dc:	27a200a0 */ 	addiu	$v0,$sp,0xa0
/*  f1492e0:	27a30514 */ 	addiu	$v1,$sp,0x514
/*  f1492e4:	27a40520 */ 	addiu	$a0,$sp,0x520
/*  f1492e8:	c44e0028 */ 	lwc1	$f14,0x28($v0)
/*  f1492ec:	24630004 */ 	addiu	$v1,$v1,0x4
/*  f1492f0:	0064082b */ 	sltu	$at,$v1,$a0
/*  f1492f4:	46007482 */ 	mul.s	$f18,$f14,$f0
/*  f1492f8:	5020000b */ 	beqzl	$at,.L0f149328
/*  f1492fc:	c450001c */ 	lwc1	$f16,0x1c($v0)
.L0f149300:
/*  f149300:	c450001c */ 	lwc1	$f16,0x1c($v0)
/*  f149304:	c44e002c */ 	lwc1	$f14,0x2c($v0)
/*  f149308:	24630004 */ 	addiu	$v1,$v1,0x4
/*  f14930c:	46109400 */ 	add.s	$f16,$f18,$f16
/*  f149310:	46007482 */ 	mul.s	$f18,$f14,$f0
/*  f149314:	0064082b */ 	sltu	$at,$v1,$a0
/*  f149318:	24420004 */ 	addiu	$v0,$v0,0x4
/*  f14931c:	1420fff8 */ 	bnez	$at,.L0f149300
/*  f149320:	e470fff8 */ 	swc1	$f16,-0x8($v1)
/*  f149324:	c450001c */ 	lwc1	$f16,0x1c($v0)
.L0f149328:
/*  f149328:	24420004 */ 	addiu	$v0,$v0,0x4
/*  f14932c:	46109400 */ 	add.s	$f16,$f18,$f16
/*  f149330:	e470fffc */ 	swc1	$f16,-0x4($v1)
/*  f149334:	8faf05ec */ 	lw	$t7,0x5ec($sp)
/*  f149338:	27a500bc */ 	addiu	$a1,$sp,0xbc
/*  f14933c:	27a70530 */ 	addiu	$a3,$sp,0x530
/*  f149340:	afa00010 */ 	sw	$zero,0x10($sp)
/*  f149344:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f149348:	25e40008 */ 	addiu	$a0,$t7,0x8
/*  f14934c:	0c006052 */ 	jal	func00018148
/*  f149350:	25e60028 */ 	addiu	$a2,$t7,0x28
/*  f149354:	27b80540 */ 	addiu	$t8,$sp,0x540
/*  f149358:	2419001f */ 	addiu	$t9,$zero,0x1f
/*  f14935c:	afb90014 */ 	sw	$t9,0x14($sp)
/*  f149360:	afb80010 */ 	sw	$t8,0x10($sp)
/*  f149364:	27a400bc */ 	addiu	$a0,$sp,0xbc
/*  f149368:	27a50514 */ 	addiu	$a1,$sp,0x514
/*  f14936c:	27a60530 */ 	addiu	$a2,$sp,0x530
/*  f149370:	0c006052 */ 	jal	func00018148
/*  f149374:	27a70520 */ 	addiu	$a3,$sp,0x520
/*  f149378:	87a80540 */ 	lh	$t0,0x540($sp)
/*  f14937c:	2401ffff */ 	addiu	$at,$zero,-1
/*  f149380:	27a30540 */ 	addiu	$v1,$sp,0x540
/*  f149384:	51010086 */ 	beql	$t0,$at,.L0f1495a0
/*  f149388:	8fb904ec */ 	lw	$t9,0x4ec($sp)
/*  f14938c:	84660000 */ 	lh	$a2,0x0($v1)
/*  f149390:	27a400bc */ 	addiu	$a0,$sp,0xbc
.L0f149394:
/*  f149394:	27a50514 */ 	addiu	$a1,$sp,0x514
/*  f149398:	27a705b0 */ 	addiu	$a3,$sp,0x5b0
/*  f14939c:	0fc58548 */ 	jal	func0f161520
/*  f1493a0:	afa30034 */ 	sw	$v1,0x34($sp)
/*  f1493a4:	10400078 */ 	beqz	$v0,.L0f149588
/*  f1493a8:	8fa30034 */ 	lw	$v1,0x34($sp)
/*  f1493ac:	c7a00514 */ 	lwc1	$f0,0x514($sp)
/*  f1493b0:	c7b000bc */ 	lwc1	$f16,0xbc($sp)
/*  f1493b4:	c7aa05b0 */ 	lwc1	$f10,0x5b0($sp)
/*  f1493b8:	4600803e */ 	c.le.s	$f16,$f0
/*  f1493bc:	00000000 */ 	nop
/*  f1493c0:	4502000a */ 	bc1fl	.L0f1493ec
/*  f1493c4:	4610003e */ 	c.le.s	$f0,$f16
/*  f1493c8:	4600503e */ 	c.le.s	$f10,$f0
/*  f1493cc:	00000000 */ 	nop
/*  f1493d0:	45020006 */ 	bc1fl	.L0f1493ec
/*  f1493d4:	4610003e */ 	c.le.s	$f0,$f16
/*  f1493d8:	460a803e */ 	c.le.s	$f16,$f10
/*  f1493dc:	00000000 */ 	nop
/*  f1493e0:	4503000e */ 	bc1tl	.L0f14941c
/*  f1493e4:	c7a20518 */ 	lwc1	$f2,0x518($sp)
/*  f1493e8:	4610003e */ 	c.le.s	$f0,$f16
.L0f1493ec:
/*  f1493ec:	c7b205b0 */ 	lwc1	$f18,0x5b0($sp)
/*  f1493f0:	45020066 */ 	bc1fl	.L0f14958c
/*  f1493f4:	84660002 */ 	lh	$a2,0x2($v1)
/*  f1493f8:	4612003e */ 	c.le.s	$f0,$f18
/*  f1493fc:	00000000 */ 	nop
/*  f149400:	45020062 */ 	bc1fl	.L0f14958c
/*  f149404:	84660002 */ 	lh	$a2,0x2($v1)
/*  f149408:	4610903e */ 	c.le.s	$f18,$f16
/*  f14940c:	00000000 */ 	nop
/*  f149410:	4502005e */ 	bc1fl	.L0f14958c
/*  f149414:	84660002 */ 	lh	$a2,0x2($v1)
/*  f149418:	c7a20518 */ 	lwc1	$f2,0x518($sp)
.L0f14941c:
/*  f14941c:	c7ae00c0 */ 	lwc1	$f14,0xc0($sp)
/*  f149420:	c7a405b4 */ 	lwc1	$f4,0x5b4($sp)
/*  f149424:	4602703e */ 	c.le.s	$f14,$f2
/*  f149428:	00000000 */ 	nop
/*  f14942c:	4502000a */ 	bc1fl	.L0f149458
/*  f149430:	460e103e */ 	c.le.s	$f2,$f14
/*  f149434:	4602203e */ 	c.le.s	$f4,$f2
/*  f149438:	00000000 */ 	nop
/*  f14943c:	45020006 */ 	bc1fl	.L0f149458
/*  f149440:	460e103e */ 	c.le.s	$f2,$f14
/*  f149444:	4604703e */ 	c.le.s	$f14,$f4
/*  f149448:	00000000 */ 	nop
/*  f14944c:	4503000e */ 	bc1tl	.L0f149488
/*  f149450:	c7a000c4 */ 	lwc1	$f0,0xc4($sp)
/*  f149454:	460e103e */ 	c.le.s	$f2,$f14
.L0f149458:
/*  f149458:	c7a605b4 */ 	lwc1	$f6,0x5b4($sp)
/*  f14945c:	4502004b */ 	bc1fl	.L0f14958c
/*  f149460:	84660002 */ 	lh	$a2,0x2($v1)
/*  f149464:	4606103e */ 	c.le.s	$f2,$f6
/*  f149468:	00000000 */ 	nop
/*  f14946c:	45020047 */ 	bc1fl	.L0f14958c
/*  f149470:	84660002 */ 	lh	$a2,0x2($v1)
/*  f149474:	460e303e */ 	c.le.s	$f6,$f14
/*  f149478:	00000000 */ 	nop
/*  f14947c:	45020043 */ 	bc1fl	.L0f14958c
/*  f149480:	84660002 */ 	lh	$a2,0x2($v1)
/*  f149484:	c7a000c4 */ 	lwc1	$f0,0xc4($sp)
.L0f149488:
/*  f149488:	c7ac051c */ 	lwc1	$f12,0x51c($sp)
/*  f14948c:	c7a805b8 */ 	lwc1	$f8,0x5b8($sp)
/*  f149490:	460c003e */ 	c.le.s	$f0,$f12
/*  f149494:	00000000 */ 	nop
/*  f149498:	4502000a */ 	bc1fl	.L0f1494c4
/*  f14949c:	4600603e */ 	c.le.s	$f12,$f0
/*  f1494a0:	460c403e */ 	c.le.s	$f8,$f12
/*  f1494a4:	00000000 */ 	nop
/*  f1494a8:	45020006 */ 	bc1fl	.L0f1494c4
/*  f1494ac:	4600603e */ 	c.le.s	$f12,$f0
/*  f1494b0:	4608003e */ 	c.le.s	$f0,$f8
/*  f1494b4:	00000000 */ 	nop
/*  f1494b8:	4503000e */ 	bc1tl	.L0f1494f4
/*  f1494bc:	c7b205b0 */ 	lwc1	$f18,0x5b0($sp)
/*  f1494c0:	4600603e */ 	c.le.s	$f12,$f0
.L0f1494c4:
/*  f1494c4:	c7aa05b8 */ 	lwc1	$f10,0x5b8($sp)
/*  f1494c8:	45020030 */ 	bc1fl	.L0f14958c
/*  f1494cc:	84660002 */ 	lh	$a2,0x2($v1)
/*  f1494d0:	460a603e */ 	c.le.s	$f12,$f10
/*  f1494d4:	00000000 */ 	nop
/*  f1494d8:	4502002c */ 	bc1fl	.L0f14958c
/*  f1494dc:	84660002 */ 	lh	$a2,0x2($v1)
/*  f1494e0:	4600503e */ 	c.le.s	$f10,$f0
/*  f1494e4:	00000000 */ 	nop
/*  f1494e8:	45020028 */ 	bc1fl	.L0f14958c
/*  f1494ec:	84660002 */ 	lh	$a2,0x2($v1)
/*  f1494f0:	c7b205b0 */ 	lwc1	$f18,0x5b0($sp)
.L0f1494f4:
/*  f1494f4:	c7a405b4 */ 	lwc1	$f4,0x5b4($sp)
/*  f1494f8:	c7a605b8 */ 	lwc1	$f6,0x5b8($sp)
/*  f1494fc:	46128032 */ 	c.eq.s	$f16,$f18
/*  f149500:	00000000 */ 	nop
/*  f149504:	4502000a */ 	bc1fl	.L0f149530
/*  f149508:	846a0000 */ 	lh	$t2,0x0($v1)
/*  f14950c:	46047032 */ 	c.eq.s	$f14,$f4
/*  f149510:	00000000 */ 	nop
/*  f149514:	45020006 */ 	bc1fl	.L0f149530
/*  f149518:	846a0000 */ 	lh	$t2,0x0($v1)
/*  f14951c:	46060032 */ 	c.eq.s	$f0,$f6
/*  f149520:	00000000 */ 	nop
/*  f149524:	45030019 */ 	bc1tl	.L0f14958c
/*  f149528:	84660002 */ 	lh	$a2,0x2($v1)
/*  f14952c:	846a0000 */ 	lh	$t2,0x0($v1)
.L0f149530:
/*  f149530:	27ac05b0 */ 	addiu	$t4,$sp,0x5b0
/*  f149534:	258f0030 */ 	addiu	$t7,$t4,0x30
/*  f149538:	27ab0580 */ 	addiu	$t3,$sp,0x580
/*  f14953c:	afaa0500 */ 	sw	$t2,0x500($sp)
.L0f149540:
/*  f149540:	8d810000 */ 	lw	$at,0x0($t4)
/*  f149544:	258c000c */ 	addiu	$t4,$t4,0xc
/*  f149548:	256b000c */ 	addiu	$t3,$t3,0xc
/*  f14954c:	ad61fff4 */ 	sw	$at,-0xc($t3)
/*  f149550:	8d81fff8 */ 	lw	$at,-0x8($t4)
/*  f149554:	ad61fff8 */ 	sw	$at,-0x8($t3)
/*  f149558:	8d81fffc */ 	lw	$at,-0x4($t4)
/*  f14955c:	158ffff8 */ 	bne	$t4,$t7,.L0f149540
/*  f149560:	ad61fffc */ 	sw	$at,-0x4($t3)
/*  f149564:	c7a005b0 */ 	lwc1	$f0,0x5b0($sp)
/*  f149568:	c7a205b4 */ 	lwc1	$f2,0x5b4($sp)
/*  f14956c:	c7ac05b8 */ 	lwc1	$f12,0x5b8($sp)
/*  f149570:	24180001 */ 	addiu	$t8,$zero,0x1
/*  f149574:	afb804ec */ 	sw	$t8,0x4ec($sp)
/*  f149578:	e7a00514 */ 	swc1	$f0,0x514($sp)
/*  f14957c:	e7a20518 */ 	swc1	$f2,0x518($sp)
/*  f149580:	10000006 */ 	b	.L0f14959c
/*  f149584:	e7ac051c */ 	swc1	$f12,0x51c($sp)
.L0f149588:
/*  f149588:	84660002 */ 	lh	$a2,0x2($v1)
.L0f14958c:
/*  f14958c:	2401ffff */ 	addiu	$at,$zero,-1
/*  f149590:	24630002 */ 	addiu	$v1,$v1,0x2
/*  f149594:	54c1ff7f */ 	bnel	$a2,$at,.L0f149394
/*  f149598:	27a400bc */ 	addiu	$a0,$sp,0xbc
.L0f14959c:
/*  f14959c:	8fb904ec */ 	lw	$t9,0x4ec($sp)
.L0f1495a0:
/*  f1495a0:	27a400bc */ 	addiu	$a0,$sp,0xbc
/*  f1495a4:	3c017f1b */ 	lui	$at,%hi(var7f1b6030)
/*  f1495a8:	13200019 */ 	beqz	$t9,.L0f149610
/*  f1495ac:	00000000 */ 	nop
/*  f1495b0:	0fc5dd18 */ 	jal	func0f177460
/*  f1495b4:	27a50580 */ 	addiu	$a1,$sp,0x580
/*  f1495b8:	3c018008 */ 	lui	$at,0x8008
/*  f1495bc:	c428f8b0 */ 	lwc1	$f8,-0x750($at)
/*  f1495c0:	46000306 */ 	mov.s	$f12,$f0
/*  f1495c4:	27a805b0 */ 	addiu	$t0,$sp,0x5b0
/*  f1495c8:	4608003c */ 	c.lt.s	$f0,$f8
/*  f1495cc:	27a905bc */ 	addiu	$t1,$sp,0x5bc
/*  f1495d0:	4500000d */ 	bc1f	.L0f149608
/*  f1495d4:	00000000 */ 	nop
/*  f1495d8:	87ae05dc */ 	lh	$t6,0x5dc($sp)
/*  f1495dc:	8faa0500 */ 	lw	$t2,0x500($sp)
/*  f1495e0:	afa8050c */ 	sw	$t0,0x50c($sp)
/*  f1495e4:	39cd0002 */ 	xori	$t5,$t6,0x2
/*  f1495e8:	2dad0001 */ 	sltiu	$t5,$t5,0x1
/*  f1495ec:	afa80508 */ 	sw	$t0,0x508($sp)
/*  f1495f0:	afa90504 */ 	sw	$t1,0x504($sp)
/*  f1495f4:	afa005e0 */ 	sw	$zero,0x5e0($sp)
/*  f1495f8:	afa004fc */ 	sw	$zero,0x4fc($sp)
/*  f1495fc:	afad04f0 */ 	sw	$t5,0x4f0($sp)
/*  f149600:	10000004 */ 	b	.L0f149614
/*  f149604:	afaa04f8 */ 	sw	$t2,0x4f8($sp)
.L0f149608:
/*  f149608:	10000002 */ 	b	.L0f149614
/*  f14960c:	afa004ec */ 	sw	$zero,0x4ec($sp)
.L0f149610:
/*  f149610:	c42c6030 */ 	lwc1	$f12,%lo(var7f1b6030)($at)
.L0f149614:
/*  f149614:	8faf05fc */ 	lw	$t7,0x5fc($sp)
/*  f149618:	3c018008 */ 	lui	$at,0x8008
/*  f14961c:	c7aa05f4 */ 	lwc1	$f10,0x5f4($sp)
/*  f149620:	55e0005c */ 	bnezl	$t7,.L0f149794
/*  f149624:	8fae04ec */ 	lw	$t6,0x4ec($sp)
/*  f149628:	c420f8b0 */ 	lwc1	$f0,-0x750($at)
/*  f14962c:	4600603c */ 	c.lt.s	$f12,$f0
/*  f149630:	00000000 */ 	nop
/*  f149634:	45020004 */ 	bc1fl	.L0f149648
/*  f149638:	46000086 */ 	mov.s	$f2,$f0
/*  f14963c:	10000002 */ 	b	.L0f149648
/*  f149640:	46006086 */ 	mov.s	$f2,$f12
/*  f149644:	46000086 */ 	mov.s	$f2,$f0
.L0f149648:
/*  f149648:	460a1080 */ 	add.s	$f2,$f2,$f10
/*  f14964c:	27a200a0 */ 	addiu	$v0,$sp,0xa0
/*  f149650:	27a304b0 */ 	addiu	$v1,$sp,0x4b0
/*  f149654:	e7a200d4 */ 	swc1	$f2,0xd4($sp)
.L0f149658:
/*  f149658:	24420068 */ 	addiu	$v0,$v0,0x68
/*  f14965c:	ac40ffd8 */ 	sw	$zero,-0x28($v0)
/*  f149660:	ac40ffdc */ 	sw	$zero,-0x24($v0)
/*  f149664:	1443fffc */ 	bne	$v0,$v1,.L0f149658
/*  f149668:	ac40ffe0 */ 	sw	$zero,-0x20($v0)
/*  f14966c:	3c02800a */ 	lui	$v0,%hi(g_Vars)
/*  f149670:	24429fc0 */ 	addiu	$v0,$v0,%lo(g_Vars)
/*  f149674:	8c43034c */ 	lw	$v1,0x34c($v0)
/*  f149678:	8c450348 */ 	lw	$a1,0x348($v0)
/*  f14967c:	2463fffc */ 	addiu	$v1,$v1,-4
/*  f149680:	0065082b */ 	sltu	$at,$v1,$a1
/*  f149684:	14200016 */ 	bnez	$at,.L0f1496e0
/*  f149688:	00000000 */ 	nop
/*  f14968c:	8c640000 */ 	lw	$a0,0x0($v1)
.L0f149690:
/*  f149690:	50800010 */ 	beqzl	$a0,.L0f1496d4
/*  f149694:	2463fffc */ 	addiu	$v1,$v1,-4
/*  f149698:	90820000 */ 	lbu	$v0,0x0($a0)
/*  f14969c:	24010001 */ 	addiu	$at,$zero,0x1
/*  f1496a0:	10410005 */ 	beq	$v0,$at,.L0f1496b8
/*  f1496a4:	24010002 */ 	addiu	$at,$zero,0x2
/*  f1496a8:	10410003 */ 	beq	$v0,$at,.L0f1496b8
/*  f1496ac:	24010004 */ 	addiu	$at,$zero,0x4
/*  f1496b0:	54410008 */ 	bnel	$v0,$at,.L0f1496d4
/*  f1496b4:	2463fffc */ 	addiu	$v1,$v1,-4
.L0f1496b8:
/*  f1496b8:	27a500a0 */ 	addiu	$a1,$sp,0xa0
/*  f1496bc:	0fc21780 */ 	jal	func0f085e00
/*  f1496c0:	afa305e4 */ 	sw	$v1,0x5e4($sp)
/*  f1496c4:	3c05800a */ 	lui	$a1,%hi(g_Vars+0x348)
/*  f1496c8:	8fa305e4 */ 	lw	$v1,0x5e4($sp)
/*  f1496cc:	8ca5a308 */ 	lw	$a1,%lo(g_Vars+0x348)($a1)
/*  f1496d0:	2463fffc */ 	addiu	$v1,$v1,-4
.L0f1496d4:
/*  f1496d4:	0065082b */ 	sltu	$at,$v1,$a1
/*  f1496d8:	5020ffed */ 	beqzl	$at,.L0f149690
/*  f1496dc:	8c640000 */ 	lw	$a0,0x0($v1)
.L0f1496e0:
/*  f1496e0:	3c06800b */ 	lui	$a2,%hi(g_Textures)
/*  f1496e4:	3c058008 */ 	lui	$a1,%hi(somethings)
/*  f1496e8:	24a54458 */ 	addiu	$a1,$a1,%lo(somethings)
/*  f1496ec:	24c6abc0 */ 	addiu	$a2,$a2,%lo(g_Textures)
/*  f1496f0:	27a200a0 */ 	addiu	$v0,$sp,0xa0
/*  f1496f4:	27a704b0 */ 	addiu	$a3,$sp,0x4b0
/*  f1496f8:	8c4c0040 */ 	lw	$t4,0x40($v0)
.L0f1496fc:
/*  f1496fc:	2444003c */ 	addiu	$a0,$v0,0x3c
/*  f149700:	24420068 */ 	addiu	$v0,$v0,0x68
/*  f149704:	11800020 */ 	beqz	$t4,.L0f149788
/*  f149708:	00000000 */ 	nop
/*  f14970c:	8483003a */ 	lh	$v1,0x3a($a0)
/*  f149710:	0460000d */ 	bltz	$v1,.L0f149748
/*  f149714:	28610daf */ 	slti	$at,$v1,0xdaf
/*  f149718:	5020000c */ 	beqzl	$at,.L0f14974c
/*  f14971c:	248c0010 */ 	addiu	$t4,$a0,0x10
/*  f149720:	8ccb0000 */ 	lw	$t3,0x0($a2)
/*  f149724:	0003c0c0 */ 	sll	$t8,$v1,0x3
/*  f149728:	0178c821 */ 	addu	$t9,$t3,$t8
/*  f14972c:	93280000 */ 	lbu	$t0,0x0($t9)
/*  f149730:	3109000f */ 	andi	$t1,$t0,0xf
/*  f149734:	00095080 */ 	sll	$t2,$t1,0x2
/*  f149738:	00aa7021 */ 	addu	$t6,$a1,$t2
/*  f14973c:	8dcd0000 */ 	lw	$t5,0x0($t6)
/*  f149740:	85af000a */ 	lh	$t7,0xa($t5)
/*  f149744:	11e00010 */ 	beqz	$t7,.L0f149788
.L0f149748:
/*  f149748:	248c0010 */ 	addiu	$t4,$a0,0x10
.L0f14974c:
/*  f14974c:	248b0050 */ 	addiu	$t3,$a0,0x50
/*  f149750:	2498001c */ 	addiu	$t8,$a0,0x1c
/*  f149754:	afac050c */ 	sw	$t4,0x50c($sp)
/*  f149758:	afab0508 */ 	sw	$t3,0x508($sp)
/*  f14975c:	afb80504 */ 	sw	$t8,0x504($sp)
/*  f149760:	8c990004 */ 	lw	$t9,0x4($a0)
/*  f149764:	24090001 */ 	addiu	$t1,$zero,0x1
/*  f149768:	240a0001 */ 	addiu	$t2,$zero,0x1
/*  f14976c:	afb905e0 */ 	sw	$t9,0x5e0($sp)
/*  f149770:	80880043 */ 	lb	$t0,0x43($a0)
/*  f149774:	afa904f8 */ 	sw	$t1,0x4f8($sp)
/*  f149778:	afa004f0 */ 	sw	$zero,0x4f0($sp)
/*  f14977c:	afaa04ec */ 	sw	$t2,0x4ec($sp)
/*  f149780:	10000003 */ 	b	.L0f149790
/*  f149784:	afa804fc */ 	sw	$t0,0x4fc($sp)
.L0f149788:
/*  f149788:	5447ffdc */ 	bnel	$v0,$a3,.L0f1496fc
/*  f14978c:	8c4c0040 */ 	lw	$t4,0x40($v0)
.L0f149790:
/*  f149790:	8fae04ec */ 	lw	$t6,0x4ec($sp)
.L0f149794:
/*  f149794:	27a3003c */ 	addiu	$v1,$sp,0x3c
/*  f149798:	8fa4050c */ 	lw	$a0,0x50c($sp)
/*  f14979c:	11c0002d */ 	beqz	$t6,.L0f149854
/*  f1497a0:	00001025 */ 	or	$v0,$zero,$zero
/*  f1497a4:	27a200a0 */ 	addiu	$v0,$sp,0xa0
/*  f1497a8:	8fa50508 */ 	lw	$a1,0x508($sp)
/*  f1497ac:	8fa60504 */ 	lw	$a2,0x504($sp)
/*  f1497b0:	27a70048 */ 	addiu	$a3,$sp,0x48
.L0f1497b4:
/*  f1497b4:	c4920000 */ 	lwc1	$f18,0x0($a0)
/*  f1497b8:	c446001c */ 	lwc1	$f6,0x1c($v0)
/*  f1497bc:	24630004 */ 	addiu	$v1,$v1,0x4
/*  f1497c0:	e472fffc */ 	swc1	$f18,-0x4($v1)
/*  f1497c4:	c4a40000 */ 	lwc1	$f4,0x0($a1)
/*  f1497c8:	e4660020 */ 	swc1	$f6,0x20($v1)
/*  f1497cc:	24420004 */ 	addiu	$v0,$v0,0x4
/*  f1497d0:	e4640008 */ 	swc1	$f4,0x8($v1)
/*  f1497d4:	c4c80000 */ 	lwc1	$f8,0x0($a2)
/*  f1497d8:	24840004 */ 	addiu	$a0,$a0,0x4
/*  f1497dc:	24a50004 */ 	addiu	$a1,$a1,4
/*  f1497e0:	24c60004 */ 	addiu	$a2,$a2,0x4
/*  f1497e4:	1467fff3 */ 	bne	$v1,$a3,.L0f1497b4
/*  f1497e8:	e4680014 */ 	swc1	$f8,0x14($v1)
/*  f1497ec:	8fad05ec */ 	lw	$t5,0x5ec($sp)
/*  f1497f0:	8faf05e0 */ 	lw	$t7,0x5e0($sp)
/*  f1497f4:	8fac0604 */ 	lw	$t4,0x604($sp)
/*  f1497f8:	8fab04fc */ 	lw	$t3,0x4fc($sp)
/*  f1497fc:	8fb804f8 */ 	lw	$t8,0x4f8($sp)
/*  f149800:	8fb905f8 */ 	lw	$t9,0x5f8($sp)
/*  f149804:	8fa80600 */ 	lw	$t0,0x600($sp)
/*  f149808:	c7aa05e8 */ 	lwc1	$f10,0x5e8($sp)
/*  f14980c:	8fa905fc */ 	lw	$t1,0x5fc($sp)
/*  f149810:	8faa0608 */ 	lw	$t2,0x608($sp)
/*  f149814:	8fae04f0 */ 	lw	$t6,0x4f0($sp)
/*  f149818:	27a4003c */ 	addiu	$a0,$sp,0x3c
/*  f14981c:	afad0074 */ 	sw	$t5,0x74($sp)
/*  f149820:	afaf0070 */ 	sw	$t7,0x70($sp)
/*  f149824:	afac0078 */ 	sw	$t4,0x78($sp)
/*  f149828:	afab007c */ 	sw	$t3,0x7c($sp)
/*  f14982c:	afb80080 */ 	sw	$t8,0x80($sp)
/*  f149830:	afb90084 */ 	sw	$t9,0x84($sp)
/*  f149834:	afa80090 */ 	sw	$t0,0x90($sp)
/*  f149838:	e7aa008c */ 	swc1	$f10,0x8c($sp)
/*  f14983c:	afa9006c */ 	sw	$t1,0x6c($sp)
/*  f149840:	afaa0094 */ 	sw	$t2,0x94($sp)
/*  f149844:	0fc5261b */ 	jal	func0f14986c
/*  f149848:	afae0088 */ 	sw	$t6,0x88($sp)
/*  f14984c:	10000001 */ 	b	.L0f149854
/*  f149850:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f149854:
/*  f149854:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f149858:	27bd05e8 */ 	addiu	$sp,$sp,0x5e8
/*  f14985c:	03e00008 */ 	jr	$ra
/*  f149860:	00000000 */ 	nop
);

void func0f149864(void)
{
	// empty
}

GLOBAL_ASM(
glabel func0f14986c
.late_rodata
glabel var7f1b6034
.word func0f14986c+0x11c # f149988
glabel var7f1b6038
.word func0f14986c+0x11c # f149988
glabel var7f1b603c
.word func0f14986c+0x11c # f149988
glabel var7f1b6040
.word func0f14986c+0x12c # f149998
glabel var7f1b6044
.word func0f14986c+0x12c # f149998
glabel var7f1b6048
.word func0f14986c+0x13c # f1499a8
.text
/*  f14986c:	27bdff50 */ 	addiu	$sp,$sp,-176
/*  f149870:	240e00c0 */ 	addiu	$t6,$zero,0xc0
/*  f149874:	afbf005c */ 	sw	$ra,0x5c($sp)
/*  f149878:	afb00058 */ 	sw	$s0,0x58($sp)
/*  f14987c:	a3ae0092 */ 	sb	$t6,0x92($sp)
/*  f149880:	8c820048 */ 	lw	$v0,0x48($a0)
/*  f149884:	00808025 */ 	or	$s0,$a0,$zero
/*  f149888:	304f0001 */ 	andi	$t7,$v0,0x1
/*  f14988c:	afaf0088 */ 	sw	$t7,0x88($sp)
/*  f149890:	afaf0084 */ 	sw	$t7,0x84($sp)
/*  f149894:	8c98004c */ 	lw	$t8,0x4c($a0)
/*  f149898:	0c004b70 */ 	jal	random
/*  f14989c:	afb80080 */ 	sw	$t8,0x80($sp)
/*  f1498a0:	24010003 */ 	addiu	$at,$zero,0x3
/*  f1498a4:	0041001b */ 	divu	$zero,$v0,$at
/*  f1498a8:	0000c810 */ 	mfhi	$t9
/*  f1498ac:	27280009 */ 	addiu	$t0,$t9,0x9
/*  f1498b0:	afa8008c */ 	sw	$t0,0x8c($sp)
/*  f1498b4:	8e030034 */ 	lw	$v1,0x34($s0)
/*  f1498b8:	50600013 */ 	beqzl	$v1,.L0f149908
/*  f1498bc:	8e020030 */ 	lw	$v0,0x30($s0)
/*  f1498c0:	90690000 */ 	lbu	$t1,0x0($v1)
/*  f1498c4:	24010001 */ 	addiu	$at,$zero,0x1
/*  f1498c8:	5521000f */ 	bnel	$t1,$at,.L0f149908
/*  f1498cc:	8e020030 */ 	lw	$v0,0x30($s0)
/*  f1498d0:	8c620004 */ 	lw	$v0,0x4($v1)
/*  f1498d4:	5040000c */ 	beqzl	$v0,.L0f149908
/*  f1498d8:	8e020030 */ 	lw	$v0,0x30($s0)
/*  f1498dc:	90430003 */ 	lbu	$v1,0x3($v0)
/*  f1498e0:	2401002a */ 	addiu	$at,$zero,0x2a
/*  f1498e4:	240a0040 */ 	addiu	$t2,$zero,0x40
/*  f1498e8:	10610004 */ 	beq	$v1,$at,.L0f1498fc
/*  f1498ec:	240b0001 */ 	addiu	$t3,$zero,0x1
/*  f1498f0:	2401002f */ 	addiu	$at,$zero,0x2f
/*  f1498f4:	54610004 */ 	bnel	$v1,$at,.L0f149908
/*  f1498f8:	8e020030 */ 	lw	$v0,0x30($s0)
.L0f1498fc:
/*  f1498fc:	a3aa0092 */ 	sb	$t2,0x92($sp)
/*  f149900:	afab0080 */ 	sw	$t3,0x80($sp)
/*  f149904:	8e020030 */ 	lw	$v0,0x30($s0)
.L0f149908:
/*  f149908:	24010001 */ 	addiu	$at,$zero,0x1
/*  f14990c:	10410005 */ 	beq	$v0,$at,.L0f149924
/*  f149910:	24010002 */ 	addiu	$at,$zero,0x2
/*  f149914:	1041000b */ 	beq	$v0,$at,.L0f149944
/*  f149918:	00000000 */ 	nop
/*  f14991c:	1000000d */ 	b	.L0f149954
/*  f149920:	00000000 */ 	nop
.L0f149924:
/*  f149924:	0c004b70 */ 	jal	random
/*  f149928:	00000000 */ 	nop
/*  f14992c:	24010003 */ 	addiu	$at,$zero,0x3
/*  f149930:	0041001b */ 	divu	$zero,$v0,$at
/*  f149934:	00006010 */ 	mfhi	$t4
/*  f149938:	258d0009 */ 	addiu	$t5,$t4,0x9
/*  f14993c:	10000005 */ 	b	.L0f149954
/*  f149940:	afad008c */ 	sw	$t5,0x8c($sp)
.L0f149944:
/*  f149944:	0c004b70 */ 	jal	random
/*  f149948:	00000000 */ 	nop
/*  f14994c:	240e000c */ 	addiu	$t6,$zero,0xc
/*  f149950:	afae008c */ 	sw	$t6,0x8c($sp)
.L0f149954:
/*  f149954:	0c004b70 */ 	jal	random
/*  f149958:	00000000 */ 	nop
/*  f14995c:	24010006 */ 	addiu	$at,$zero,0x6
/*  f149960:	0041001b */ 	divu	$zero,$v0,$at
/*  f149964:	00007810 */ 	mfhi	$t7
/*  f149968:	2de10006 */ 	sltiu	$at,$t7,0x6
/*  f14996c:	10200012 */ 	beqz	$at,.L0f1499b8
/*  f149970:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f149974:	3c017f1b */ 	lui	$at,%hi(var7f1b6034)
/*  f149978:	002f0821 */ 	addu	$at,$at,$t7
/*  f14997c:	8c2f6034 */ 	lw	$t7,%lo(var7f1b6034)($at)
/*  f149980:	01e00008 */ 	jr	$t7
/*  f149984:	00000000 */ 	nop
/*  f149988:	3c013fc0 */ 	lui	$at,0x3fc0
/*  f14998c:	44812000 */ 	mtc1	$at,$f4
/*  f149990:	10000009 */ 	b	.L0f1499b8
/*  f149994:	e7a4009c */ 	swc1	$f4,0x9c($sp)
/*  f149998:	3c0140a0 */ 	lui	$at,0x40a0
/*  f14999c:	44813000 */ 	mtc1	$at,$f6
/*  f1499a0:	10000005 */ 	b	.L0f1499b8
/*  f1499a4:	e7a6009c */ 	swc1	$f6,0x9c($sp)
/*  f1499a8:	3c014040 */ 	lui	$at,0x4040
/*  f1499ac:	44814000 */ 	mtc1	$at,$f8
/*  f1499b0:	00000000 */ 	nop
/*  f1499b4:	e7a8009c */ 	swc1	$f8,0x9c($sp)
.L0f1499b8:
/*  f1499b8:	2605000c */ 	addiu	$a1,$s0,0xc
/*  f1499bc:	afa5006c */ 	sw	$a1,0x6c($sp)
/*  f1499c0:	0fc5dd18 */ 	jal	func0f177460
/*  f1499c4:	26040024 */ 	addiu	$a0,$s0,0x24
/*  f1499c8:	3c018008 */ 	lui	$at,0x8008
/*  f1499cc:	c42af8a0 */ 	lwc1	$f10,-0x760($at)
/*  f1499d0:	c7a6009c */ 	lwc1	$f6,0x9c($sp)
/*  f1499d4:	3c018008 */ 	lui	$at,0x8008
/*  f1499d8:	46005102 */ 	mul.s	$f4,$f10,$f0
/*  f1499dc:	c422f8b8 */ 	lwc1	$f2,-0x748($at)
/*  f1499e0:	3c018008 */ 	lui	$at,0x8008
/*  f1499e4:	46062302 */ 	mul.s	$f12,$f4,$f6
/*  f1499e8:	460c103c */ 	c.lt.s	$f2,$f12
/*  f1499ec:	00000000 */ 	nop
/*  f1499f0:	45000002 */ 	bc1f	.L0f1499fc
/*  f1499f4:	00000000 */ 	nop
/*  f1499f8:	46001306 */ 	mov.s	$f12,$f2
.L0f1499fc:
/*  f1499fc:	c420f8b4 */ 	lwc1	$f0,-0x74c($at)
/*  f149a00:	3c013f80 */ 	lui	$at,0x3f80
/*  f149a04:	44811000 */ 	mtc1	$at,$f2
/*  f149a08:	4600603c */ 	c.lt.s	$f12,$f0
/*  f149a0c:	3c013f00 */ 	lui	$at,0x3f00
/*  f149a10:	44814000 */ 	mtc1	$at,$f8
/*  f149a14:	45000002 */ 	bc1f	.L0f149a20
/*  f149a18:	00000000 */ 	nop
/*  f149a1c:	46000306 */ 	mov.s	$f12,$f0
.L0f149a20:
/*  f149a20:	460c4002 */ 	mul.s	$f0,$f8,$f12
/*  f149a24:	4602003c */ 	c.lt.s	$f0,$f2
/*  f149a28:	46000406 */ 	mov.s	$f16,$f0
/*  f149a2c:	46000486 */ 	mov.s	$f18,$f0
/*  f149a30:	45020003 */ 	bc1fl	.L0f149a40
/*  f149a34:	4602003c */ 	c.lt.s	$f0,$f2
/*  f149a38:	46001406 */ 	mov.s	$f16,$f2
/*  f149a3c:	4602003c */ 	c.lt.s	$f0,$f2
.L0f149a40:
/*  f149a40:	00000000 */ 	nop
/*  f149a44:	45020003 */ 	bc1fl	.L0f149a54
/*  f149a48:	e7ac00a0 */ 	swc1	$f12,0xa0($sp)
/*  f149a4c:	46001486 */ 	mov.s	$f18,$f2
/*  f149a50:	e7ac00a0 */ 	swc1	$f12,0xa0($sp)
.L0f149a54:
/*  f149a54:	e7b000ac */ 	swc1	$f16,0xac($sp)
/*  f149a58:	0c004b70 */ 	jal	random
/*  f149a5c:	e7b200a8 */ 	swc1	$f18,0xa8($sp)
/*  f149a60:	44825000 */ 	mtc1	$v0,$f10
/*  f149a64:	c7ac00a0 */ 	lwc1	$f12,0xa0($sp)
/*  f149a68:	c7b000ac */ 	lwc1	$f16,0xac($sp)
/*  f149a6c:	04410005 */ 	bgez	$v0,.L0f149a84
/*  f149a70:	46805120 */ 	cvt.s.w	$f4,$f10
/*  f149a74:	3c014f80 */ 	lui	$at,0x4f80
/*  f149a78:	44813000 */ 	mtc1	$at,$f6
/*  f149a7c:	00000000 */ 	nop
/*  f149a80:	46062100 */ 	add.s	$f4,$f4,$f6
.L0f149a84:
/*  f149a84:	3c012f80 */ 	lui	$at,0x2f80
/*  f149a88:	44814000 */ 	mtc1	$at,$f8
/*  f149a8c:	00000000 */ 	nop
/*  f149a90:	46082282 */ 	mul.s	$f10,$f4,$f8
/*  f149a94:	00000000 */ 	nop
/*  f149a98:	46105002 */ 	mul.s	$f0,$f10,$f16
/*  f149a9c:	46000180 */ 	add.s	$f6,$f0,$f0
/*  f149aa0:	46103101 */ 	sub.s	$f4,$f6,$f16
/*  f149aa4:	460c2380 */ 	add.s	$f14,$f4,$f12
/*  f149aa8:	0c004b70 */ 	jal	random
/*  f149aac:	e7ae0094 */ 	swc1	$f14,0x94($sp)
/*  f149ab0:	44824000 */ 	mtc1	$v0,$f8
/*  f149ab4:	c7ac00a0 */ 	lwc1	$f12,0xa0($sp)
/*  f149ab8:	c7ae0094 */ 	lwc1	$f14,0x94($sp)
/*  f149abc:	c7b200a8 */ 	lwc1	$f18,0xa8($sp)
/*  f149ac0:	04410005 */ 	bgez	$v0,.L0f149ad8
/*  f149ac4:	468042a0 */ 	cvt.s.w	$f10,$f8
/*  f149ac8:	3c014f80 */ 	lui	$at,0x4f80
/*  f149acc:	44813000 */ 	mtc1	$at,$f6
/*  f149ad0:	00000000 */ 	nop
/*  f149ad4:	46065280 */ 	add.s	$f10,$f10,$f6
.L0f149ad8:
/*  f149ad8:	3c012f80 */ 	lui	$at,0x2f80
/*  f149adc:	44812000 */ 	mtc1	$at,$f4
/*  f149ae0:	3c018008 */ 	lui	$at,0x8008
/*  f149ae4:	c422f8b8 */ 	lwc1	$f2,-0x748($at)
/*  f149ae8:	46045202 */ 	mul.s	$f8,$f10,$f4
/*  f149aec:	460e103c */ 	c.lt.s	$f2,$f14
/*  f149af0:	46124002 */ 	mul.s	$f0,$f8,$f18
/*  f149af4:	46000180 */ 	add.s	$f6,$f0,$f0
/*  f149af8:	46123281 */ 	sub.s	$f10,$f6,$f18
/*  f149afc:	460c5400 */ 	add.s	$f16,$f10,$f12
/*  f149b00:	45000002 */ 	bc1f	.L0f149b0c
/*  f149b04:	e7b00098 */ 	swc1	$f16,0x98($sp)
/*  f149b08:	46001386 */ 	mov.s	$f14,$f2
.L0f149b0c:
/*  f149b0c:	4610103c */ 	c.lt.s	$f2,$f16
/*  f149b10:	00000000 */ 	nop
/*  f149b14:	45020003 */ 	bc1fl	.L0f149b24
/*  f149b18:	c6000050 */ 	lwc1	$f0,0x50($s0)
/*  f149b1c:	e7a20098 */ 	swc1	$f2,0x98($sp)
/*  f149b20:	c6000050 */ 	lwc1	$f0,0x50($s0)
.L0f149b24:
/*  f149b24:	c7a40098 */ 	lwc1	$f4,0x98($sp)
/*  f149b28:	46007382 */ 	mul.s	$f14,$f14,$f0
/*  f149b2c:	00000000 */ 	nop
/*  f149b30:	46002202 */ 	mul.s	$f8,$f4,$f0
/*  f149b34:	e7a80098 */ 	swc1	$f8,0x98($sp)
/*  f149b38:	8e040038 */ 	lw	$a0,0x38($s0)
/*  f149b3c:	0fc4f972 */ 	jal	func0f13e5c8
/*  f149b40:	e7ae0094 */ 	swc1	$f14,0x94($sp)
/*  f149b44:	8e02003c */ 	lw	$v0,0x3c($s0)
/*  f149b48:	c7ae0094 */ 	lwc1	$f14,0x94($sp)
/*  f149b4c:	00003025 */ 	or	$a2,$zero,$zero
/*  f149b50:	10400004 */ 	beqz	$v0,.L0f149b64
/*  f149b54:	00000000 */ 	nop
/*  f149b58:	8c46001c */ 	lw	$a2,0x1c($v0)
/*  f149b5c:	10000001 */ 	b	.L0f149b64
/*  f149b60:	24c60008 */ 	addiu	$a2,$a2,0x8
.L0f149b64:
/*  f149b64:	afa60070 */ 	sw	$a2,0x70($sp)
/*  f149b68:	0c004b70 */ 	jal	random
/*  f149b6c:	e7ae0094 */ 	swc1	$f14,0x94($sp)
/*  f149b70:	24010168 */ 	addiu	$at,$zero,0x168
/*  f149b74:	0041001b */ 	divu	$zero,$v0,$at
/*  f149b78:	8fb8008c */ 	lw	$t8,0x8c($sp)
/*  f149b7c:	afa00010 */ 	sw	$zero,0x10($sp)
/*  f149b80:	c7ae0094 */ 	lwc1	$f14,0x94($sp)
/*  f149b84:	afb80014 */ 	sw	$t8,0x14($sp)
/*  f149b88:	8e190044 */ 	lw	$t9,0x44($s0)
/*  f149b8c:	c7a60098 */ 	lwc1	$f6,0x98($sp)
/*  f149b90:	93ac0092 */ 	lbu	$t4,0x92($sp)
/*  f149b94:	afb90018 */ 	sw	$t9,0x18($sp)
/*  f149b98:	8e080034 */ 	lw	$t0,0x34($s0)
/*  f149b9c:	00007010 */ 	mfhi	$t6
/*  f149ba0:	240d00ff */ 	addiu	$t5,$zero,0xff
/*  f149ba4:	afa8001c */ 	sw	$t0,0x1c($sp)
/*  f149ba8:	8e090038 */ 	lw	$t1,0x38($s0)
/*  f149bac:	8fb90080 */ 	lw	$t9,0x80($sp)
/*  f149bb0:	8fa60070 */ 	lw	$a2,0x70($sp)
/*  f149bb4:	afa90020 */ 	sw	$t1,0x20($sp)
/*  f149bb8:	8e0a0040 */ 	lw	$t2,0x40($s0)
/*  f149bbc:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f149bc0:	02002025 */ 	or	$a0,$s0,$zero
/*  f149bc4:	afaa0024 */ 	sw	$t2,0x24($sp)
/*  f149bc8:	8e0b003c */ 	lw	$t3,0x3c($s0)
/*  f149bcc:	afae0040 */ 	sw	$t6,0x40($sp)
/*  f149bd0:	afad003c */ 	sw	$t5,0x3c($sp)
/*  f149bd4:	e7ae0030 */ 	swc1	$f14,0x30($sp)
/*  f149bd8:	e7a60034 */ 	swc1	$f6,0x34($sp)
/*  f149bdc:	afac0038 */ 	sw	$t4,0x38($sp)
/*  f149be0:	afab002c */ 	sw	$t3,0x2c($sp)
/*  f149be4:	960f0056 */ 	lhu	$t7,0x56($s0)
/*  f149be8:	26050018 */ 	addiu	$a1,$s0,0x18
/*  f149bec:	00003825 */ 	or	$a3,$zero,$zero
/*  f149bf0:	afaf0044 */ 	sw	$t7,0x44($sp)
/*  f149bf4:	8e180058 */ 	lw	$t8,0x58($s0)
/*  f149bf8:	afb9004c */ 	sw	$t9,0x4c($sp)
/*  f149bfc:	0fc4fd41 */ 	jal	func0f13f504
/*  f149c00:	afb80048 */ 	sw	$t8,0x48($sp)
/*  f149c04:	8fa20088 */ 	lw	$v0,0x88($sp)
/*  f149c08:	8fa80084 */ 	lw	$t0,0x84($sp)
/*  f149c0c:	240affff */ 	addiu	$t2,$zero,-1
/*  f149c10:	14400003 */ 	bnez	$v0,.L0f149c20
/*  f149c14:	27a50078 */ 	addiu	$a1,$sp,0x78
/*  f149c18:	5100000e */ 	beqzl	$t0,.L0f149c54
/*  f149c1c:	8fbf005c */ 	lw	$ra,0x5c($sp)
.L0f149c20:
/*  f149c20:	8e090044 */ 	lw	$t1,0x44($s0)
/*  f149c24:	a7aa007a */ 	sh	$t2,0x7a($sp)
/*  f149c28:	10400003 */ 	beqz	$v0,.L0f149c38
/*  f149c2c:	a7a90078 */ 	sh	$t1,0x78($sp)
/*  f149c30:	10000002 */ 	b	.L0f149c3c
/*  f149c34:	2402000d */ 	addiu	$v0,$zero,0xd
.L0f149c38:
/*  f149c38:	2402000e */ 	addiu	$v0,$zero,0xe
.L0f149c3c:
/*  f149c3c:	00023400 */ 	sll	$a2,$v0,0x10
/*  f149c40:	00065c03 */ 	sra	$t3,$a2,0x10
/*  f149c44:	01603025 */ 	or	$a2,$t3,$zero
/*  f149c48:	0fc4ba08 */ 	jal	smokeCreateSimple
/*  f149c4c:	8fa4006c */ 	lw	$a0,0x6c($sp)
/*  f149c50:	8fbf005c */ 	lw	$ra,0x5c($sp)
.L0f149c54:
/*  f149c54:	8fb00058 */ 	lw	$s0,0x58($sp)
/*  f149c58:	27bd00b0 */ 	addiu	$sp,$sp,0xb0
/*  f149c5c:	03e00008 */ 	jr	$ra
/*  f149c60:	00000000 */ 	nop
);

void chrInitSplats(struct chrdata *chr)
{
	chr->bulletstaken = 0;
	chr->tickssincesplat = 0;
	chr->stdsplatsadded = 0;
	chr->woundedsplatsadded = 0;
	chr->deaddropsplatsadded = 0;
	chr->splatsdroppedhe = 0;
	chr->lastdroppos.x = 0;
	chr->lastdroppos.y = 0;
	chr->lastdroppos.z = 0;
}
