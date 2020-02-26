#include <ultra64.h>
#include "constants.h"
#include "game/data/data_000000.h"
#include "game/data/data_0083d0.h"
#include "game/data/data_0160b0.h"
#include "game/data/data_020df0.h"
#include "gvars/gvars.h"
#include "library/library_12dc0.h"
#include "types.h"

GLOBAL_ASM(
glabel func0f128f30
/*  f128f30:	27bdffa8 */ 	addiu	$sp,$sp,-88
/*  f128f34:	3c0e8f80 */ 	lui	$t6,0x8f80
/*  f128f38:	3c0f3108 */ 	lui	$t7,0x3108
/*  f128f3c:	afb50028 */ 	sw	$s5,0x28($sp)
/*  f128f40:	afb40024 */ 	sw	$s4,0x24($sp)
/*  f128f44:	afb30020 */ 	sw	$s3,0x20($sp)
/*  f128f48:	afb10018 */ 	sw	$s1,0x18($sp)
/*  f128f4c:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f128f50:	35efb3c1 */ 	ori	$t7,$t7,0xb3c1
/*  f128f54:	35ce9f47 */ 	ori	$t6,$t6,0x9f47
/*  f128f58:	0085082b */ 	sltu	$at,$a0,$a1
/*  f128f5c:	00a0a825 */ 	or	$s5,$a1,$zero
/*  f128f60:	afbf002c */ 	sw	$ra,0x2c($sp)
/*  f128f64:	afb2001c */ 	sw	$s2,0x1c($sp)
/*  f128f68:	afa60060 */ 	sw	$a2,0x60($sp)
/*  f128f6c:	00803825 */ 	or	$a3,$a0,$zero
/*  f128f70:	00008825 */ 	or	$s1,$zero,$zero
/*  f128f74:	afae0048 */ 	sw	$t6,0x48($sp)
/*  f128f78:	afaf004c */ 	sw	$t7,0x4c($sp)
/*  f128f7c:	00009825 */ 	or	$s3,$zero,$zero
/*  f128f80:	0000a025 */ 	or	$s4,$zero,$zero
/*  f128f84:	10200016 */ 	beqz	$at,.L0f128fe0
/*  f128f88:	00808025 */ 	or	$s0,$a0,$zero
/*  f128f8c:	afa40058 */ 	sw	$a0,0x58($sp)
/*  f128f90:	27b20048 */ 	addiu	$s2,$sp,0x48
.L0f128f94:
/*  f128f94:	92180000 */ 	lbu	$t8,0x0($s0)
/*  f128f98:	8fad004c */ 	lw	$t5,0x4c($sp)
/*  f128f9c:	3239000f */ 	andi	$t9,$s1,0xf
/*  f128fa0:	03384004 */ 	sllv	$t0,$t8,$t9
/*  f128fa4:	8fac0048 */ 	lw	$t4,0x48($sp)
/*  f128fa8:	010d7821 */ 	addu	$t7,$t0,$t5
/*  f128fac:	000857c3 */ 	sra	$t2,$t0,0x1f
/*  f128fb0:	01ed082b */ 	sltu	$at,$t7,$t5
/*  f128fb4:	002a7021 */ 	addu	$t6,$at,$t2
/*  f128fb8:	01cc7021 */ 	addu	$t6,$t6,$t4
/*  f128fbc:	afae0048 */ 	sw	$t6,0x48($sp)
/*  f128fc0:	afaf004c */ 	sw	$t7,0x4c($sp)
/*  f128fc4:	0c004b87 */ 	jal	func00012e1c
/*  f128fc8:	02402025 */ 	or	$a0,$s2,$zero
/*  f128fcc:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f128fd0:	26310007 */ 	addiu	$s1,$s1,0x7
/*  f128fd4:	1615ffef */ 	bne	$s0,$s5,.L0f128f94
/*  f128fd8:	02629826 */ 	xor	$s3,$s3,$v0
/*  f128fdc:	8fa70058 */ 	lw	$a3,0x58($sp)
.L0f128fe0:
/*  f128fe0:	26b0ffff */ 	addiu	$s0,$s5,-1
/*  f128fe4:	0207082b */ 	sltu	$at,$s0,$a3
/*  f128fe8:	14200014 */ 	bnez	$at,.L0f12903c
/*  f128fec:	27b20048 */ 	addiu	$s2,$sp,0x48
/*  f128ff0:	24f5ffff */ 	addiu	$s5,$a3,-1
.L0f128ff4:
/*  f128ff4:	92090000 */ 	lbu	$t1,0x0($s0)
/*  f128ff8:	8fab004c */ 	lw	$t3,0x4c($sp)
/*  f128ffc:	3238000f */ 	andi	$t8,$s1,0xf
/*  f129000:	0309c804 */ 	sllv	$t9,$t1,$t8
/*  f129004:	8faa0048 */ 	lw	$t2,0x48($sp)
/*  f129008:	032b6821 */ 	addu	$t5,$t9,$t3
/*  f12900c:	001947c3 */ 	sra	$t0,$t9,0x1f
/*  f129010:	01ab082b */ 	sltu	$at,$t5,$t3
/*  f129014:	00286021 */ 	addu	$t4,$at,$t0
/*  f129018:	018a6021 */ 	addu	$t4,$t4,$t2
/*  f12901c:	afac0048 */ 	sw	$t4,0x48($sp)
/*  f129020:	afad004c */ 	sw	$t5,0x4c($sp)
/*  f129024:	0c004b87 */ 	jal	func00012e1c
/*  f129028:	02402025 */ 	or	$a0,$s2,$zero
/*  f12902c:	2610ffff */ 	addiu	$s0,$s0,-1
/*  f129030:	26310003 */ 	addiu	$s1,$s1,0x3
/*  f129034:	1615ffef */ 	bne	$s0,$s5,.L0f128ff4
/*  f129038:	0282a026 */ 	xor	$s4,$s4,$v0
.L0f12903c:
/*  f12903c:	8fae0060 */ 	lw	$t6,0x60($sp)
/*  f129040:	add30000 */ 	sw	$s3,0x0($t6)
/*  f129044:	add40004 */ 	sw	$s4,0x4($t6)
/*  f129048:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*  f12904c:	8fb50028 */ 	lw	$s5,0x28($sp)
/*  f129050:	8fb40024 */ 	lw	$s4,0x24($sp)
/*  f129054:	8fb30020 */ 	lw	$s3,0x20($sp)
/*  f129058:	8fb2001c */ 	lw	$s2,0x1c($sp)
/*  f12905c:	8fb10018 */ 	lw	$s1,0x18($sp)
/*  f129060:	8fb00014 */ 	lw	$s0,0x14($sp)
/*  f129064:	03e00008 */ 	jr	$ra
/*  f129068:	27bd0058 */ 	addiu	$sp,$sp,0x58
);

GLOBAL_ASM(
glabel func0f12906c
/*  f12906c:	27bdffa8 */ 	addiu	$sp,$sp,-88
/*  f129070:	3c0e8f80 */ 	lui	$t6,0x8f80
/*  f129074:	3c0f3108 */ 	lui	$t7,0x3108
/*  f129078:	afb50028 */ 	sw	$s5,0x28($sp)
/*  f12907c:	afb40024 */ 	sw	$s4,0x24($sp)
/*  f129080:	afb30020 */ 	sw	$s3,0x20($sp)
/*  f129084:	afb10018 */ 	sw	$s1,0x18($sp)
/*  f129088:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f12908c:	35efb3c1 */ 	ori	$t7,$t7,0xb3c1
/*  f129090:	35ce9f47 */ 	ori	$t6,$t6,0x9f47
/*  f129094:	0085082b */ 	sltu	$at,$a0,$a1
/*  f129098:	00a0a825 */ 	or	$s5,$a1,$zero
/*  f12909c:	afbf002c */ 	sw	$ra,0x2c($sp)
/*  f1290a0:	afb2001c */ 	sw	$s2,0x1c($sp)
/*  f1290a4:	afa60060 */ 	sw	$a2,0x60($sp)
/*  f1290a8:	00803825 */ 	or	$a3,$a0,$zero
/*  f1290ac:	00008825 */ 	or	$s1,$zero,$zero
/*  f1290b0:	afae0048 */ 	sw	$t6,0x48($sp)
/*  f1290b4:	afaf004c */ 	sw	$t7,0x4c($sp)
/*  f1290b8:	00009825 */ 	or	$s3,$zero,$zero
/*  f1290bc:	0000a025 */ 	or	$s4,$zero,$zero
/*  f1290c0:	10200016 */ 	beqz	$at,.L0f12911c
/*  f1290c4:	00808025 */ 	or	$s0,$a0,$zero
/*  f1290c8:	afa40058 */ 	sw	$a0,0x58($sp)
/*  f1290cc:	27b20048 */ 	addiu	$s2,$sp,0x48
.L0f1290d0:
/*  f1290d0:	92180000 */ 	lbu	$t8,0x0($s0)
/*  f1290d4:	8fad004c */ 	lw	$t5,0x4c($sp)
/*  f1290d8:	3239000f */ 	andi	$t9,$s1,0xf
/*  f1290dc:	03384004 */ 	sllv	$t0,$t8,$t9
/*  f1290e0:	8fac0048 */ 	lw	$t4,0x48($sp)
/*  f1290e4:	010d7821 */ 	addu	$t7,$t0,$t5
/*  f1290e8:	000857c3 */ 	sra	$t2,$t0,0x1f
/*  f1290ec:	01ed082b */ 	sltu	$at,$t7,$t5
/*  f1290f0:	002a7021 */ 	addu	$t6,$at,$t2
/*  f1290f4:	01cc7021 */ 	addu	$t6,$t6,$t4
/*  f1290f8:	afae0048 */ 	sw	$t6,0x48($sp)
/*  f1290fc:	afaf004c */ 	sw	$t7,0x4c($sp)
/*  f129100:	0c004b87 */ 	jal	func00012e1c
/*  f129104:	02402025 */ 	or	$a0,$s2,$zero
/*  f129108:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f12910c:	26310007 */ 	addiu	$s1,$s1,0x7
/*  f129110:	1615ffef */ 	bne	$s0,$s5,.L0f1290d0
/*  f129114:	02629826 */ 	xor	$s3,$s3,$v0
/*  f129118:	8fa70058 */ 	lw	$a3,0x58($sp)
.L0f12911c:
/*  f12911c:	26b0ffff */ 	addiu	$s0,$s5,-1
/*  f129120:	0207082b */ 	sltu	$at,$s0,$a3
/*  f129124:	14200014 */ 	bnez	$at,.L0f129178
/*  f129128:	27b20048 */ 	addiu	$s2,$sp,0x48
/*  f12912c:	24f5ffff */ 	addiu	$s5,$a3,-1
.L0f129130:
/*  f129130:	92090000 */ 	lbu	$t1,0x0($s0)
/*  f129134:	8fab004c */ 	lw	$t3,0x4c($sp)
/*  f129138:	3238000f */ 	andi	$t8,$s1,0xf
/*  f12913c:	0309c804 */ 	sllv	$t9,$t1,$t8
/*  f129140:	8faa0048 */ 	lw	$t2,0x48($sp)
/*  f129144:	032b6821 */ 	addu	$t5,$t9,$t3
/*  f129148:	001947c3 */ 	sra	$t0,$t9,0x1f
/*  f12914c:	01ab082b */ 	sltu	$at,$t5,$t3
/*  f129150:	00286021 */ 	addu	$t4,$at,$t0
/*  f129154:	018a6021 */ 	addu	$t4,$t4,$t2
/*  f129158:	afac0048 */ 	sw	$t4,0x48($sp)
/*  f12915c:	afad004c */ 	sw	$t5,0x4c($sp)
/*  f129160:	0c004b87 */ 	jal	func00012e1c
/*  f129164:	02402025 */ 	or	$a0,$s2,$zero
/*  f129168:	2610ffff */ 	addiu	$s0,$s0,-1
/*  f12916c:	26310003 */ 	addiu	$s1,$s1,0x3
/*  f129170:	1615ffef */ 	bne	$s0,$s5,.L0f129130
/*  f129174:	0282a026 */ 	xor	$s4,$s4,$v0
.L0f129178:
/*  f129178:	8faf0060 */ 	lw	$t7,0x60($sp)
/*  f12917c:	02607025 */ 	or	$t6,$s3,$zero
/*  f129180:	0280c025 */ 	or	$t8,$s4,$zero
/*  f129184:	a5ee0000 */ 	sh	$t6,0x0($t7)
/*  f129188:	a5f80002 */ 	sh	$t8,0x2($t7)
/*  f12918c:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*  f129190:	8fb50028 */ 	lw	$s5,0x28($sp)
/*  f129194:	8fb40024 */ 	lw	$s4,0x24($sp)
/*  f129198:	8fb30020 */ 	lw	$s3,0x20($sp)
/*  f12919c:	8fb2001c */ 	lw	$s2,0x1c($sp)
/*  f1291a0:	8fb10018 */ 	lw	$s1,0x18($sp)
/*  f1291a4:	8fb00014 */ 	lw	$s0,0x14($sp)
/*  f1291a8:	03e00008 */ 	jr	$ra
/*  f1291ac:	27bd0058 */ 	addiu	$sp,$sp,0x58
);

GLOBAL_ASM(
glabel func0f1291b0
/*  f1291b0:	3c048008 */ 	lui	$a0,0x8008
/*  f1291b4:	dc84e3c0 */ 	ld	$a0,-0x1c40($a0)
/*  f1291b8:	3c018008 */ 	lui	$at,0x8008
/*  f1291bc:	000437fc */ 	dsll32	$a2,$a0,0x1f
/*  f1291c0:	00042ff8 */ 	dsll	$a1,$a0,0x1f
/*  f1291c4:	000637fa */ 	dsrl	$a2,$a2,0x1f
/*  f1291c8:	0005283e */ 	dsrl32	$a1,$a1,0x0
/*  f1291cc:	0004233c */ 	dsll32	$a0,$a0,0xc
/*  f1291d0:	00c53025 */ 	or	$a2,$a2,$a1
/*  f1291d4:	0004203e */ 	dsrl32	$a0,$a0,0x0
/*  f1291d8:	00c43026 */ 	xor	$a2,$a2,$a0
/*  f1291dc:	0006253a */ 	dsrl	$a0,$a2,0x14
/*  f1291e0:	30840fff */ 	andi	$a0,$a0,0xfff
/*  f1291e4:	00862026 */ 	xor	$a0,$a0,$a2
/*  f1291e8:	0004103c */ 	dsll32	$v0,$a0,0x0
/*  f1291ec:	fc24e3c0 */ 	sd	$a0,-0x1c40($at)
/*  f1291f0:	03e00008 */ 	jr	$ra
/*  f1291f4:	0002103f */ 	dsra32	$v0,$v0,0x0
);

GLOBAL_ASM(
glabel func0f1291f8
/*  f1291f8:	64840001 */ 	daddiu	$a0,$a0,0x1
/*  f1291fc:	3c018008 */ 	lui	$at,0x8008
/*  f129200:	fc24e3c0 */ 	sd	$a0,-0x1c40($at)
/*  f129204:	03e00008 */ 	jr	$ra
/*  f129208:	24040000 */ 	addiu	$a0,$zero,0x0
/*  f12920c:	00000000 */ 	sll	$zero,$zero,0x0
);
