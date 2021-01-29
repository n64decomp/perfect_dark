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
#include "lib/lib_12dc0.h"
#include "lib/lib_13130.h"
#include "lib/lib_2fa00.h"
#include "types.h"

const u32 var70053ff0[] = {0x00000000};
const char var70053ff4[] = "-d";
const char var70053ff8[] = "-s";
const char var70053ffc[] = "-j";
const char var70054000[] = "-level_";
const char var70054008[] = "";
const char var7005400c[] = "";

u64 rand_seed = 0xab8d9f7781280783;

u32 var8005ee08 = 0x00000000;
u32 var8005ee0c = 0x00000000;
u32 var8005ee10 = 0x00000001;
u32 var8005ee14 = 0x00000000;
u32 var8005ee18 = 0x00000000;
u32 var8005ee1c = 0x00000000;
u32 var8005ee20 = 0x00000000;
u32 var8005ee24 = 0x00000000;
u32 var8005ee28 = 0x00000000;
u32 var8005ee2c = 0x00000000;
u32 var8005ee30 = 0x00000000;
u32 var8005ee34 = 0x00000000;
u32 var8005ee38 = 0x00000000;
u32 var8005ee3c = 0x00000000;
u32 var8005ee40 = 0x00000000;
u32 var8005ee44 = 0x00000000;
u32 var8005ee48 = 0x00000000;
u32 var8005ee4c = 0x00000000;
u32 var8005ee50 = 0x00000000;
u32 var8005ee54 = 0x00000000;
u32 var8005ee58 = 0x00000000;
u32 var8005ee5c = 0x00000000;

GLOBAL_ASM(
glabel random
/*    12dc0:	3c048006 */ 	lui	$a0,%hi(rand_seed)
/*    12dc4:	dc84ee00 */ 	ld	$a0,%lo(rand_seed)($a0)
/*    12dc8:	3c018006 */ 	lui	$at,%hi(rand_seed)
/*    12dcc:	000437fc */ 	dsll32	$a2,$a0,0x1f
/*    12dd0:	00042ff8 */ 	dsll	$a1,$a0,0x1f
/*    12dd4:	000637fa */ 	dsrl	$a2,$a2,0x1f
/*    12dd8:	0005283e */ 	dsrl32	$a1,$a1,0x0
/*    12ddc:	0004233c */ 	dsll32	$a0,$a0,0xc
/*    12de0:	00c53025 */ 	or	$a2,$a2,$a1
/*    12de4:	0004203e */ 	dsrl32	$a0,$a0,0x0
/*    12de8:	00c43026 */ 	xor	$a2,$a2,$a0
/*    12dec:	0006253a */ 	dsrl	$a0,$a2,0x14
/*    12df0:	30840fff */ 	andi	$a0,$a0,0xfff
/*    12df4:	00862026 */ 	xor	$a0,$a0,$a2
/*    12df8:	0004103c */ 	dsll32	$v0,$a0,0x0
/*    12dfc:	fc24ee00 */ 	sd	$a0,%lo(rand_seed)($at)
/*    12e00:	03e00008 */ 	jr	$ra
/*    12e04:	0002103f */ 	dsra32	$v0,$v0,0x0
);

// Commented because ld isn't happy with bitshifting a u64.
//u32 random(void)
//{
//	rand_seed = ((rand_seed << 63) >> 31 | (rand_seed << 31) >> 32) ^ (rand_seed << 44) >> 32;
//	rand_seed = rand_seed >> 20 & 0xfff ^ rand_seed;
//
//	return rand_seed;
//}

GLOBAL_ASM(
glabel rngSetSeed
/*    12e08:	64840001 */ 	daddiu	$a0,$a0,0x1
/*    12e0c:	3c018006 */ 	lui	$at,%hi(rand_seed)
/*    12e10:	fc24ee00 */ 	sd	$a0,%lo(rand_seed)($at)
/*    12e14:	03e00008 */ 	jr	$ra
/*    12e18:	24040000 */ 	addiu	$a0,$zero,0x0
);

GLOBAL_ASM(
glabel func00012e1c
/*    12e1c:	dc870000 */ 	ld	$a3,0x0($a0)
/*    12e20:	000737fc */ 	dsll32	$a2,$a3,0x1f
/*    12e24:	00072ff8 */ 	dsll	$a1,$a3,0x1f
/*    12e28:	000637fa */ 	dsrl	$a2,$a2,0x1f
/*    12e2c:	0005283e */ 	dsrl32	$a1,$a1,0x0
/*    12e30:	00073b3c */ 	dsll32	$a3,$a3,0xc
/*    12e34:	00c53025 */ 	or	$a2,$a2,$a1
/*    12e38:	0007383e */ 	dsrl32	$a3,$a3,0x0
/*    12e3c:	00c73026 */ 	xor	$a2,$a2,$a3
/*    12e40:	00063d3a */ 	dsrl	$a3,$a2,0x14
/*    12e44:	30e70fff */ 	andi	$a3,$a3,0xfff
/*    12e48:	00e63826 */ 	xor	$a3,$a3,$a2
/*    12e4c:	0007103c */ 	dsll32	$v0,$a3,0x0
/*    12e50:	fc870000 */ 	sd	$a3,0x0($a0)
/*    12e54:	03e00008 */ 	jr	$ra
/*    12e58:	0002103f */ 	dsra32	$v0,$v0,0x0
/*    12e5c:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel func00012e60
/*    12e60:	3c058006 */ 	lui	$a1,%hi(var8005ee14)
/*    12e64:	3c068006 */ 	lui	$a2,%hi(var8005ee10)
/*    12e68:	3c0e7005 */ 	lui	$t6,%hi(var70053ff0)
/*    12e6c:	24c6ee10 */ 	addiu	$a2,$a2,%lo(var8005ee10)
/*    12e70:	24a5ee14 */ 	addiu	$a1,$a1,%lo(var8005ee14)
/*    12e74:	25ce3ff0 */ 	addiu	$t6,$t6,%lo(var70053ff0)
/*    12e78:	240f0001 */ 	addiu	$t7,$zero,0x1
/*    12e7c:	acae0000 */ 	sw	$t6,0x0($a1)
/*    12e80:	accf0000 */ 	sw	$t7,0x0($a2)
/*    12e84:	90820000 */ 	lbu	$v0,0x0($a0)
/*    12e88:	24070020 */ 	addiu	$a3,$zero,0x20
/*    12e8c:	10400019 */ 	beqz	$v0,.L00012ef4
/*    12e90:	00000000 */ 	nop
.L00012e94:
/*    12e94:	54e20007 */ 	bnel	$a3,$v0,.L00012eb4
/*    12e98:	8cc30000 */ 	lw	$v1,0x0($a2)
/*    12e9c:	90980001 */ 	lbu	$t8,0x1($a0)
.L00012ea0:
/*    12ea0:	a0800000 */ 	sb	$zero,0x0($a0)
/*    12ea4:	24840001 */ 	addiu	$a0,$a0,0x1
/*    12ea8:	50f8fffd */ 	beql	$a3,$t8,.L00012ea0
/*    12eac:	90980001 */ 	lbu	$t8,0x1($a0)
/*    12eb0:	8cc30000 */ 	lw	$v1,0x0($a2)
.L00012eb4:
/*    12eb4:	0003c880 */ 	sll	$t9,$v1,0x2
/*    12eb8:	00b94021 */ 	addu	$t0,$a1,$t9
/*    12ebc:	ad040000 */ 	sw	$a0,0x0($t0)
/*    12ec0:	24690001 */ 	addiu	$t1,$v1,0x1
/*    12ec4:	acc90000 */ 	sw	$t1,0x0($a2)
/*    12ec8:	90820000 */ 	lbu	$v0,0x0($a0)
/*    12ecc:	28410021 */ 	slti	$at,$v0,0x21
/*    12ed0:	14200006 */ 	bnez	$at,.L00012eec
/*    12ed4:	00000000 */ 	nop
/*    12ed8:	90820001 */ 	lbu	$v0,0x1($a0)
.L00012edc:
/*    12edc:	24840001 */ 	addiu	$a0,$a0,0x1
/*    12ee0:	28410021 */ 	slti	$at,$v0,0x21
/*    12ee4:	5020fffd */ 	beqzl	$at,.L00012edc
/*    12ee8:	90820001 */ 	lbu	$v0,0x1($a0)
.L00012eec:
/*    12eec:	1440ffe9 */ 	bnez	$v0,.L00012e94
/*    12ef0:	00000000 */ 	nop
.L00012ef4:
/*    12ef4:	03e00008 */ 	jr	$ra
/*    12ef8:	00801025 */ 	or	$v0,$a0,$zero
);

GLOBAL_ASM(
glabel func00012efc
/*    12efc:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*    12f00:	00802825 */ 	or	$a1,$a0,$zero
/*    12f04:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    12f08:	3c04800a */ 	lui	$a0,%hi(var80099880)
/*    12f0c:	0c004c4c */ 	jal	strcpy
/*    12f10:	24849880 */ 	addiu	$a0,$a0,%lo(var80099880)
/*    12f14:	3c04800a */ 	lui	$a0,%hi(var80099880)
/*    12f18:	0c004b98 */ 	jal	func00012e60
/*    12f1c:	24849880 */ 	addiu	$a0,$a0,%lo(var80099880)
/*    12f20:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    12f24:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*    12f28:	03e00008 */ 	jr	$ra
/*    12f2c:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel func00012f30
/*    12f30:	27bdffc8 */ 	addiu	$sp,$sp,-56
/*    12f34:	afb1001c */ 	sw	$s1,0x1c($sp)
/*    12f38:	afbf0024 */ 	sw	$ra,0x24($sp)
/*    12f3c:	3c1101ff */ 	lui	$s1,0x1ff
/*    12f40:	afb20020 */ 	sw	$s2,0x20($sp)
/*    12f44:	afb00018 */ 	sw	$s0,0x18($sp)
/*    12f48:	afa00028 */ 	sw	$zero,0x28($sp)
/*    12f4c:	0c00be82 */ 	jal	func0002fa08
/*    12f50:	3631ff00 */ 	ori	$s1,$s1,0xff00
/*    12f54:	10400004 */ 	beqz	$v0,.L00012f68
/*    12f58:	3c10800a */ 	lui	$s0,%hi(var80099880)
/*    12f5c:	3c01800a */ 	lui	$at,%hi(var80099880)
/*    12f60:	1000000a */ 	b	.L00012f8c
/*    12f64:	ac209880 */ 	sw	$zero,%lo(var80099880)($at)
.L00012f68:
/*    12f68:	3c12800a */ 	lui	$s2,%hi(var800998f8)
/*    12f6c:	265298f8 */ 	addiu	$s2,$s2,%lo(var800998f8)
/*    12f70:	26109880 */ 	addiu	$s0,$s0,%lo(var80099880)
.L00012f74:
/*    12f74:	02202025 */ 	or	$a0,$s1,$zero
/*    12f78:	0c013994 */ 	jal	osPiReadIo
/*    12f7c:	02002825 */ 	or	$a1,$s0,$zero
/*    12f80:	26100004 */ 	addiu	$s0,$s0,0x4
/*    12f84:	1612fffb */ 	bne	$s0,$s2,.L00012f74
/*    12f88:	26310004 */ 	addiu	$s1,$s1,0x4
.L00012f8c:
/*    12f8c:	3c04800a */ 	lui	$a0,%hi(var80099880)
/*    12f90:	0c004b98 */ 	jal	func00012e60
/*    12f94:	24849880 */ 	addiu	$a0,$a0,%lo(var80099880)
/*    12f98:	3c057005 */ 	lui	$a1,%hi(var70053ff4)
/*    12f9c:	24a53ff4 */ 	addiu	$a1,$a1,%lo(var70053ff4)
/*    12fa0:	0c004c04 */ 	jal	func00013010
/*    12fa4:	24040001 */ 	addiu	$a0,$zero,0x1
/*    12fa8:	10400003 */ 	beqz	$v0,.L00012fb8
/*    12fac:	24040001 */ 	addiu	$a0,$zero,0x1
/*    12fb0:	240e0001 */ 	addiu	$t6,$zero,0x1
/*    12fb4:	afae0028 */ 	sw	$t6,0x28($sp)
.L00012fb8:
/*    12fb8:	3c057005 */ 	lui	$a1,%hi(var70053ff8)
/*    12fbc:	0c004c04 */ 	jal	func00013010
/*    12fc0:	24a53ff8 */ 	addiu	$a1,$a1,%lo(var70053ff8)
/*    12fc4:	10400004 */ 	beqz	$v0,.L00012fd8
/*    12fc8:	24040001 */ 	addiu	$a0,$zero,0x1
/*    12fcc:	240f0001 */ 	addiu	$t7,$zero,0x1
/*    12fd0:	3c018006 */ 	lui	$at,%hi(var8005dda0)
/*    12fd4:	ac2fdda0 */ 	sw	$t7,%lo(var8005dda0)($at)
.L00012fd8:
/*    12fd8:	3c057005 */ 	lui	$a1,%hi(var70053ffc)
/*    12fdc:	0c004c04 */ 	jal	func00013010
/*    12fe0:	24a53ffc */ 	addiu	$a1,$a1,%lo(var70053ffc)
/*    12fe4:	10400003 */ 	beqz	$v0,.L00012ff4
/*    12fe8:	24180001 */ 	addiu	$t8,$zero,0x1
/*    12fec:	3c018008 */ 	lui	$at,%hi(g_LanguageId)
/*    12ff0:	ac384120 */ 	sw	$t8,%lo(g_LanguageId)($at)
.L00012ff4:
/*    12ff4:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*    12ff8:	8fa20028 */ 	lw	$v0,0x28($sp)
/*    12ffc:	8fb00018 */ 	lw	$s0,0x18($sp)
/*    13000:	8fb1001c */ 	lw	$s1,0x1c($sp)
/*    13004:	8fb20020 */ 	lw	$s2,0x20($sp)
/*    13008:	03e00008 */ 	jr	$ra
/*    1300c:	27bd0038 */ 	addiu	$sp,$sp,0x38
);

GLOBAL_ASM(
glabel func00013010
/*    13010:	27bdffd0 */ 	addiu	$sp,$sp,-48
/*    13014:	afb2001c */ 	sw	$s2,0x1c($sp)
/*    13018:	00809025 */ 	or	$s2,$a0,$zero
/*    1301c:	afbf002c */ 	sw	$ra,0x2c($sp)
/*    13020:	afb40024 */ 	sw	$s4,0x24($sp)
/*    13024:	00a0a025 */ 	or	$s4,$a1,$zero
/*    13028:	afb50028 */ 	sw	$s5,0x28($sp)
/*    1302c:	afb30020 */ 	sw	$s3,0x20($sp)
/*    13030:	afb10018 */ 	sw	$s1,0x18($sp)
/*    13034:	afb00014 */ 	sw	$s0,0x14($sp)
/*    13038:	0c012983 */ 	jal	strlen
/*    1303c:	00a02025 */ 	or	$a0,$a1,$zero
/*    13040:	3c158006 */ 	lui	$s5,%hi(var8005ee10)
/*    13044:	26b5ee10 */ 	addiu	$s5,$s5,%lo(var8005ee10)
/*    13048:	8eae0000 */ 	lw	$t6,0x0($s5)
/*    1304c:	00409825 */ 	or	$s3,$v0,$zero
/*    13050:	24110001 */ 	addiu	$s1,$zero,0x1
/*    13054:	29c10002 */ 	slti	$at,$t6,0x2
/*    13058:	14200014 */ 	bnez	$at,.L000130ac
/*    1305c:	3c108006 */ 	lui	$s0,%hi(var8005ee18)
/*    13060:	2610ee18 */ 	addiu	$s0,$s0,%lo(var8005ee18)
/*    13064:	02802025 */ 	or	$a0,$s4,$zero
.L00013068:
/*    13068:	8e050000 */ 	lw	$a1,0x0($s0)
/*    1306c:	0c004cb0 */ 	jal	func000132c0
/*    13070:	02603025 */ 	or	$a2,$s3,$zero
/*    13074:	54400008 */ 	bnezl	$v0,.L00013098
/*    13078:	8eb80000 */ 	lw	$t8,0x0($s5)
/*    1307c:	2652ffff */ 	addiu	$s2,$s2,-1
/*    13080:	56400005 */ 	bnezl	$s2,.L00013098
/*    13084:	8eb80000 */ 	lw	$t8,0x0($s5)
/*    13088:	8e0f0000 */ 	lw	$t7,0x0($s0)
/*    1308c:	10000008 */ 	b	.L000130b0
/*    13090:	01f31021 */ 	addu	$v0,$t7,$s3
/*    13094:	8eb80000 */ 	lw	$t8,0x0($s5)
.L00013098:
/*    13098:	26310001 */ 	addiu	$s1,$s1,0x1
/*    1309c:	26100004 */ 	addiu	$s0,$s0,0x4
/*    130a0:	0238082a */ 	slt	$at,$s1,$t8
/*    130a4:	5420fff0 */ 	bnezl	$at,.L00013068
/*    130a8:	02802025 */ 	or	$a0,$s4,$zero
.L000130ac:
/*    130ac:	00001025 */ 	or	$v0,$zero,$zero
.L000130b0:
/*    130b0:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*    130b4:	8fb00014 */ 	lw	$s0,0x14($sp)
/*    130b8:	8fb10018 */ 	lw	$s1,0x18($sp)
/*    130bc:	8fb2001c */ 	lw	$s2,0x1c($sp)
/*    130c0:	8fb30020 */ 	lw	$s3,0x20($sp)
/*    130c4:	8fb40024 */ 	lw	$s4,0x24($sp)
/*    130c8:	8fb50028 */ 	lw	$s5,0x28($sp)
/*    130cc:	03e00008 */ 	jr	$ra
/*    130d0:	27bd0030 */ 	addiu	$sp,$sp,0x30
);

GLOBAL_ASM(
glabel func000130d4
/*    130d4:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*    130d8:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    130dc:	afa40018 */ 	sw	$a0,0x18($sp)
/*    130e0:	3c057005 */ 	lui	$a1,%hi(var70054000)
/*    130e4:	24a54000 */ 	addiu	$a1,$a1,%lo(var70054000)
/*    130e8:	0c004c04 */ 	jal	func00013010
/*    130ec:	24040001 */ 	addiu	$a0,$zero,0x1
/*    130f0:	5040000b */ 	beqzl	$v0,.L00013120
/*    130f4:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    130f8:	904f0000 */ 	lbu	$t7,0x0($v0)
/*    130fc:	904e0001 */ 	lbu	$t6,0x1($v0)
/*    13100:	8fa90018 */ 	lw	$t1,0x18($sp)
/*    13104:	000fc080 */ 	sll	$t8,$t7,0x2
/*    13108:	030fc021 */ 	addu	$t8,$t8,$t7
/*    1310c:	0018c040 */ 	sll	$t8,$t8,0x1
/*    13110:	01d8c821 */ 	addu	$t9,$t6,$t8
/*    13114:	2728fdf0 */ 	addiu	$t0,$t9,-528
/*    13118:	ad280000 */ 	sw	$t0,0x0($t1)
/*    1311c:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L00013120:
/*    13120:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*    13124:	03e00008 */ 	jr	$ra
/*    13128:	00000000 */ 	nop
/*    1312c:	00000000 */ 	nop
);
