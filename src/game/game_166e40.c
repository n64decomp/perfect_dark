#include <ultra64.h>
#include "constants.h"
#include "game/data/data_000000.h"
#include "game/data/data_0083d0.h"
#include "game/data/data_00e460.h"
#include "game/data/data_0160b0.h"
#include "game/data/data_01a3a0.h"
#include "game/data/data_020df0.h"
#include "game/data/data_02da90.h"
#include "game/game_166e40.h"
#include "game/game_175f50.h"
#include "gvars/gvars.h"
#include "lib/lib_074f0.h"
#include "lib/lib_0d0a0.h"
#include "lib/lib_121e0.h"
#include "lib/lib_12dc0.h"
#include "lib/lib_13130.h"
#include "types.h"

const char var7f1b76f0[] = "-mgfx";
const char var7f1b76f8[] = "-mgfx";
const char var7f1b7700[] = "-mgfxtra";
const char var7f1b770c[] = "-mgfxtra";
const char var7f1b7718[] = "-mvtx";
const char var7f1b7720[] = "-mvtx";
const char var7f1b7728[] = "";
const char var7f1b772c[] = "";
const char var7f1b7730[] = "fr: %d\n";
const char var7f1b7738[] = "cutsceneframe: %d\n";
const char var7f1b774c[] = "pos:%s%s %.2f %.2f %.2f\n";

const u32 var7f1b7768[] = {0x00000000};
const u32 var7f1b776c[] = {0x00000000};

GLOBAL_ASM(
glabel func0f166e40
/*  f166e40:	00047080 */ 	sll	$t6,$a0,0x2
/*  f166e44:	3c028008 */ 	lui	$v0,%hi(filetable)
/*  f166e48:	004e1021 */ 	addu	$v0,$v0,$t6
/*  f166e4c:	03e00008 */ 	jr	$ra
/*  f166e50:	8c422060 */ 	lw	$v0,%lo(filetable)($v0)
);

GLOBAL_ASM(
glabel func0f166e54
/*  f166e54:	8c820004 */ 	lw	$v0,0x4($a0)
/*  f166e58:	00001825 */ 	or	$v1,$zero,$zero
/*  f166e5c:	10400005 */ 	beqz	$v0,.L0f166e74
/*  f166e60:	00000000 */ 	nop
/*  f166e64:	8c8e0000 */ 	lw	$t6,0x0($a0)
/*  f166e68:	004e1823 */ 	subu	$v1,$v0,$t6
/*  f166e6c:	03e00008 */ 	jr	$ra
/*  f166e70:	00601025 */ 	or	$v0,$v1,$zero
.L0f166e74:
/*  f166e74:	03e00008 */ 	jr	$ra
/*  f166e78:	00601025 */ 	or	$v0,$v1,$zero
);

GLOBAL_ASM(
glabel func0f166e7c
/*  f166e7c:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f166e80:	3c0f8008 */ 	lui	$t7,%hi(filetable)
/*  f166e84:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f166e88:	25ef2060 */ 	addiu	$t7,$t7,%lo(filetable)
/*  f166e8c:	00047080 */ 	sll	$t6,$a0,0x2
/*  f166e90:	0fc59b95 */ 	jal	func0f166e54
/*  f166e94:	01cf2021 */ 	addu	$a0,$t6,$t7
/*  f166e98:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f166e9c:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f166ea0:	03e00008 */ 	jr	$ra
/*  f166ea4:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel func0f166ea8
/*  f166ea8:	afa40000 */ 	sw	$a0,0x0($sp)
/*  f166eac:	03e00008 */ 	jr	$ra
/*  f166eb0:	00001025 */ 	or	$v0,$zero,$zero
);

GLOBAL_ASM(
glabel func0f166eb4
/*  f166eb4:	27bdebd0 */ 	addiu	$sp,$sp,-5168
/*  f166eb8:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f166ebc:	afa41430 */ 	sw	$a0,0x1430($sp)
/*  f166ec0:	afa51434 */ 	sw	$a1,0x1434($sp)
/*  f166ec4:	afa61438 */ 	sw	$a2,0x1438($sp)
/*  f166ec8:	afa7143c */ 	sw	$a3,0x143c($sp)
/*  f166ecc:	0fc59b95 */ 	jal	func0f166e54
/*  f166ed0:	00c02025 */ 	or	$a0,$a2,$zero
/*  f166ed4:	8fa41434 */ 	lw	$a0,0x1434($sp)
/*  f166ed8:	8fa71430 */ 	lw	$a3,0x1430($sp)
/*  f166edc:	8fa91438 */ 	lw	$t1,0x1438($sp)
/*  f166ee0:	14800006 */ 	bnez	$a0,.L0f166efc
/*  f166ee4:	00403025 */ 	or	$a2,$v0,$zero
/*  f166ee8:	00e02025 */ 	or	$a0,$a3,$zero
/*  f166eec:	0c003504 */ 	jal	func0000d410
/*  f166ef0:	8d250000 */ 	lw	$a1,0x0($t1)
/*  f166ef4:	1000001c */ 	b	.L0f166f68
/*  f166ef8:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f166efc:
/*  f166efc:	2408fff8 */ 	addiu	$t0,$zero,-8
/*  f166f00:	244e0007 */ 	addiu	$t6,$v0,0x7
/*  f166f04:	01c87824 */ 	and	$t7,$t6,$t0
/*  f166f08:	00e41821 */ 	addu	$v1,$a3,$a0
/*  f166f0c:	006fc023 */ 	subu	$t8,$v1,$t7
/*  f166f10:	0307c823 */ 	subu	$t9,$t8,$a3
/*  f166f14:	2f210008 */ 	sltiu	$at,$t9,0x8
/*  f166f18:	10200004 */ 	beqz	$at,.L0f166f2c
/*  f166f1c:	24cb0007 */ 	addiu	$t3,$a2,0x7
/*  f166f20:	8faa143c */ 	lw	$t2,0x143c($sp)
/*  f166f24:	1000000f */ 	b	.L0f166f64
/*  f166f28:	ad400000 */ 	sw	$zero,0x0($t2)
.L0f166f2c:
/*  f166f2c:	01686024 */ 	and	$t4,$t3,$t0
/*  f166f30:	006c2023 */ 	subu	$a0,$v1,$t4
/*  f166f34:	8d250000 */ 	lw	$a1,0x0($t1)
/*  f166f38:	0c003504 */ 	jal	func0000d410
/*  f166f3c:	afa4001c */ 	sw	$a0,0x1c($sp)
/*  f166f40:	8fa4001c */ 	lw	$a0,0x1c($sp)
/*  f166f44:	8fa51430 */ 	lw	$a1,0x1430($sp)
/*  f166f48:	0c001d3c */ 	jal	func000074f0
/*  f166f4c:	27a6002c */ 	addiu	$a2,$sp,0x2c
/*  f166f50:	8fb8143c */ 	lw	$t8,0x143c($sp)
/*  f166f54:	244d000f */ 	addiu	$t5,$v0,0xf
/*  f166f58:	35ae000f */ 	ori	$t6,$t5,0xf
/*  f166f5c:	39cf000f */ 	xori	$t7,$t6,0xf
/*  f166f60:	af0f0000 */ 	sw	$t7,0x0($t8)
.L0f166f64:
/*  f166f64:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f166f68:
/*  f166f68:	27bd1430 */ 	addiu	$sp,$sp,0x1430
/*  f166f6c:	03e00008 */ 	jr	$ra
/*  f166f70:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel func0f166f74
/*  f166f74:	27bdffd0 */ 	addiu	$sp,$sp,-48
/*  f166f78:	afb20020 */ 	sw	$s2,0x20($sp)
/*  f166f7c:	afb1001c */ 	sw	$s1,0x1c($sp)
/*  f166f80:	afb40028 */ 	sw	$s4,0x28($sp)
/*  f166f84:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f166f88:	3c11800a */ 	lui	$s1,%hi(g_FileInfo)
/*  f166f8c:	3c128008 */ 	lui	$s2,%hi(filetable)
/*  f166f90:	afbf002c */ 	sw	$ra,0x2c($sp)
/*  f166f94:	afb30024 */ 	sw	$s3,0x24($sp)
/*  f166f98:	26522060 */ 	addiu	$s2,$s2,%lo(filetable)
/*  f166f9c:	26316680 */ 	addiu	$s1,$s1,%lo(g_FileInfo)
/*  f166fa0:	24100001 */ 	addiu	$s0,$zero,0x1
/*  f166fa4:	241407de */ 	addiu	$s4,$zero,0x7de
/*  f166fa8:	001070c0 */ 	sll	$t6,$s0,0x3
.L0f166fac:
/*  f166fac:	022e1021 */ 	addu	$v0,$s1,$t6
/*  f166fb0:	00107880 */ 	sll	$t7,$s0,0x2
/*  f166fb4:	ac400000 */ 	sw	$zero,0x0($v0)
/*  f166fb8:	ac400004 */ 	sw	$zero,0x4($v0)
/*  f166fbc:	0fc59b95 */ 	jal	func0f166e54
/*  f166fc0:	024f2021 */ 	addu	$a0,$s2,$t7
/*  f166fc4:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f166fc8:	5614fff8 */ 	bnel	$s0,$s4,.L0f166fac
/*  f166fcc:	001070c0 */ 	sll	$t6,$s0,0x3
/*  f166fd0:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*  f166fd4:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f166fd8:	8fb1001c */ 	lw	$s1,0x1c($sp)
/*  f166fdc:	8fb20020 */ 	lw	$s2,0x20($sp)
/*  f166fe0:	8fb30024 */ 	lw	$s3,0x24($sp)
/*  f166fe4:	8fb40028 */ 	lw	$s4,0x28($sp)
/*  f166fe8:	03e00008 */ 	jr	$ra
/*  f166fec:	27bd0030 */ 	addiu	$sp,$sp,0x30
);

GLOBAL_ASM(
glabel func0f166ff0
/*  f166ff0:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*  f166ff4:	afa40028 */ 	sw	$a0,0x28($sp)
/*  f166ff8:	97ae002a */ 	lhu	$t6,0x2a($sp)
/*  f166ffc:	3c188008 */ 	lui	$t8,%hi(filetable)
/*  f167000:	27182060 */ 	addiu	$t8,$t8,%lo(filetable)
/*  f167004:	000e7880 */ 	sll	$t7,$t6,0x2
/*  f167008:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f16700c:	01f82021 */ 	addu	$a0,$t7,$t8
/*  f167010:	afa5002c */ 	sw	$a1,0x2c($sp)
/*  f167014:	afa60030 */ 	sw	$a2,0x30($sp)
/*  f167018:	afa70034 */ 	sw	$a3,0x34($sp)
/*  f16701c:	0fc59b95 */ 	jal	func0f166e54
/*  f167020:	afa4001c */ 	sw	$a0,0x1c($sp)
/*  f167024:	10400007 */ 	beqz	$v0,.L0f167044
/*  f167028:	8fb9001c */ 	lw	$t9,0x1c($sp)
/*  f16702c:	8f280000 */ 	lw	$t0,0x0($t9)
/*  f167030:	8fa90030 */ 	lw	$t1,0x30($sp)
/*  f167034:	8fa4002c */ 	lw	$a0,0x2c($sp)
/*  f167038:	8fa60034 */ 	lw	$a2,0x34($sp)
/*  f16703c:	0c003504 */ 	jal	func0000d410
/*  f167040:	01092821 */ 	addu	$a1,$t0,$t1
.L0f167044:
/*  f167044:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f167048:	27bd0028 */ 	addiu	$sp,$sp,0x28
/*  f16704c:	03e00008 */ 	jr	$ra
/*  f167050:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel func0f167054
/*  f167054:	27bdff78 */ 	addiu	$sp,$sp,-136
/*  f167058:	3c0f8008 */ 	lui	$t7,%hi(filetable)
/*  f16705c:	25ef2060 */ 	addiu	$t7,$t7,%lo(filetable)
/*  f167060:	00047080 */ 	sll	$t6,$a0,0x2
/*  f167064:	afbf001c */ 	sw	$ra,0x1c($sp)
/*  f167068:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f16706c:	01cf2021 */ 	addu	$a0,$t6,$t7
/*  f167070:	8c850000 */ 	lw	$a1,0x0($a0)
/*  f167074:	27b00044 */ 	addiu	$s0,$sp,0x44
/*  f167078:	2401fff0 */ 	addiu	$at,$zero,-16
/*  f16707c:	14a0000c */ 	bnez	$a1,.L0f1670b0
/*  f167080:	24060040 */ 	addiu	$a2,$zero,0x40
/*  f167084:	0fc59baa */ 	jal	func0f166ea8
/*  f167088:	00000000 */ 	nop
/*  f16708c:	27b00044 */ 	addiu	$s0,$sp,0x44
/*  f167090:	2401fff0 */ 	addiu	$at,$zero,-16
/*  f167094:	02012824 */ 	and	$a1,$s0,$at
/*  f167098:	00a08025 */ 	or	$s0,$a1,$zero
/*  f16709c:	00402025 */ 	or	$a0,$v0,$zero
/*  f1670a0:	0fc5d7d6 */ 	jal	func0f175f58
/*  f1670a4:	24060010 */ 	addiu	$a2,$zero,0x10
/*  f1670a8:	10000004 */ 	b	.L0f1670bc
/*  f1670ac:	00000000 */ 	nop
.L0f1670b0:
/*  f1670b0:	02012024 */ 	and	$a0,$s0,$at
/*  f1670b4:	0c003504 */ 	jal	func0000d410
/*  f1670b8:	00808025 */ 	or	$s0,$a0,$zero
.L0f1670bc:
/*  f1670bc:	0c002277 */ 	jal	func000089dc
/*  f1670c0:	02002025 */ 	or	$a0,$s0,$zero
/*  f1670c4:	10400009 */ 	beqz	$v0,.L0f1670ec
/*  f1670c8:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f1670cc:	92090002 */ 	lbu	$t1,0x2($s0)
/*  f1670d0:	92080004 */ 	lbu	$t0,0x4($s0)
/*  f1670d4:	920c0003 */ 	lbu	$t4,0x3($s0)
/*  f1670d8:	00095400 */ 	sll	$t2,$t1,0x10
/*  f1670dc:	010a5825 */ 	or	$t3,$t0,$t2
/*  f1670e0:	000c6a00 */ 	sll	$t5,$t4,0x8
/*  f1670e4:	10000002 */ 	b	.L0f1670f0
/*  f1670e8:	016d1025 */ 	or	$v0,$t3,$t5
.L0f1670ec:
/*  f1670ec:	00001025 */ 	or	$v0,$zero,$zero
.L0f1670f0:
/*  f1670f0:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f1670f4:	03e00008 */ 	jr	$ra
/*  f1670f8:	27bd0088 */ 	addiu	$sp,$sp,0x88
);

GLOBAL_ASM(
glabel func0f1670fc
/*  f1670fc:	27bdffd0 */ 	addiu	$sp,$sp,-48
/*  f167100:	24010011 */ 	addiu	$at,$zero,0x11
/*  f167104:	afbf001c */ 	sw	$ra,0x1c($sp)
/*  f167108:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f16710c:	afa40030 */ 	sw	$a0,0x30($sp)
/*  f167110:	10a10004 */ 	beq	$a1,$at,.L0f167124
/*  f167114:	afa50034 */ 	sw	$a1,0x34($sp)
/*  f167118:	24010022 */ 	addiu	$at,$zero,0x22
/*  f16711c:	14a1002c */ 	bne	$a1,$at,.L0f1671d0
/*  f167120:	00000000 */ 	nop
.L0f167124:
/*  f167124:	8faf0030 */ 	lw	$t7,0x30($sp)
/*  f167128:	3c19800a */ 	lui	$t9,%hi(g_FileInfo)
/*  f16712c:	27396680 */ 	addiu	$t9,$t9,%lo(g_FileInfo)
/*  f167130:	000fc0c0 */ 	sll	$t8,$t7,0x3
/*  f167134:	03198021 */ 	addu	$s0,$t8,$t9
/*  f167138:	8e080000 */ 	lw	$t0,0x0($s0)
/*  f16713c:	5500000e */ 	bnezl	$t0,.L0f167178
/*  f167140:	8e040000 */ 	lw	$a0,0x0($s0)
/*  f167144:	0fc59c15 */ 	jal	func0f167054
/*  f167148:	01e02025 */ 	or	$a0,$t7,$zero
/*  f16714c:	24490020 */ 	addiu	$t1,$v0,0x20
/*  f167150:	2401fff0 */ 	addiu	$at,$zero,-16
/*  f167154:	01215024 */ 	and	$t2,$t1,$at
/*  f167158:	ae0a0000 */ 	sw	$t2,0x0($s0)
/*  f16715c:	8fab0034 */ 	lw	$t3,0x34($sp)
/*  f167160:	24010011 */ 	addiu	$at,$zero,0x11
/*  f167164:	15610003 */ 	bne	$t3,$at,.L0f167174
/*  f167168:	34018000 */ 	dli	$at,0x8000
/*  f16716c:	01416821 */ 	addu	$t5,$t2,$at
/*  f167170:	ae0d0000 */ 	sw	$t5,0x0($s0)
.L0f167174:
/*  f167174:	8e040000 */ 	lw	$a0,0x0($s0)
.L0f167178:
/*  f167178:	0c0048f2 */ 	jal	malloc
/*  f16717c:	24050004 */ 	addiu	$a1,$zero,0x4
/*  f167180:	afa20024 */ 	sw	$v0,0x24($sp)
/*  f167184:	8e050000 */ 	lw	$a1,0x0($s0)
/*  f167188:	3c198008 */ 	lui	$t9,%hi(filetable)
/*  f16718c:	27392060 */ 	addiu	$t9,$t9,%lo(filetable)
/*  f167190:	ae050004 */ 	sw	$a1,0x4($s0)
/*  f167194:	8fae0030 */ 	lw	$t6,0x30($sp)
/*  f167198:	00402025 */ 	or	$a0,$v0,$zero
/*  f16719c:	02003825 */ 	or	$a3,$s0,$zero
/*  f1671a0:	000ec080 */ 	sll	$t8,$t6,0x2
/*  f1671a4:	0fc59bad */ 	jal	func0f166eb4
/*  f1671a8:	03193021 */ 	addu	$a2,$t8,$t9
/*  f1671ac:	8fa80034 */ 	lw	$t0,0x34($sp)
/*  f1671b0:	24010011 */ 	addiu	$at,$zero,0x11
/*  f1671b4:	8fa40024 */ 	lw	$a0,0x24($sp)
/*  f1671b8:	11010007 */ 	beq	$t0,$at,.L0f1671d8
/*  f1671bc:	24060004 */ 	addiu	$a2,$zero,0x4
/*  f1671c0:	0c00490c */ 	jal	func00012430
/*  f1671c4:	8e050000 */ 	lw	$a1,0x0($s0)
/*  f1671c8:	10000004 */ 	b	.L0f1671dc
/*  f1671cc:	8fbf001c */ 	lw	$ra,0x1c($sp)
.L0f1671d0:
/*  f1671d0:	1000ffff */ 	b	.L0f1671d0
/*  f1671d4:	00000000 */ 	nop
.L0f1671d8:
/*  f1671d8:	8fbf001c */ 	lw	$ra,0x1c($sp)
.L0f1671dc:
/*  f1671dc:	8fa20024 */ 	lw	$v0,0x24($sp)
/*  f1671e0:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f1671e4:	03e00008 */ 	jr	$ra
/*  f1671e8:	27bd0030 */ 	addiu	$sp,$sp,0x30
/*  f1671ec:	00047080 */ 	sll	$t6,$a0,0x2
/*  f1671f0:	3c018008 */ 	lui	$at,%hi(filetable)
/*  f1671f4:	002e0821 */ 	addu	$at,$at,$t6
/*  f1671f8:	03e00008 */ 	jr	$ra
/*  f1671fc:	ac202060 */ 	sw	$zero,%lo(filetable)($at)
);

//void *func0f1670fc(u32 filenum, u32 arg1)
//{
//	struct fileinfo *info;
//	u32 stack;
//	void *ptr;
//
//	if (arg1 == 0x11 || arg1 == 0x22) {
//		// 124
//		info = &g_FileInfo[filenum];
//
//		// 13c
//		if (info->unk00 == 0) {
//			info->unk00 = (func0f167054(filenum) + 0x20) & 0xfffffff0;
//
//			// 164
//			if (arg1 == 0x11) {
//				info->unk00 += 0x8000;
//			}
//		}
//
//		// 174
//		ptr = malloc(info->unk00, 4);
//		info->unk04 = info->unk00;
//		func0f166eb4(ptr, info->unk00, &filetable[filenum], info);
//
//		if (arg1 != 0x11) {
//			func00012430(ptr, info->unk00, 4);
//		}
//	} else {
//		while (true) {
//			// empty
//		}
//	}
//
//	return ptr;
//}

GLOBAL_ASM(
glabel func0f167200
/*  f167200:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f167204:	24010011 */ 	addiu	$at,$zero,0x11
/*  f167208:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f16720c:	afa40018 */ 	sw	$a0,0x18($sp)
/*  f167210:	afa60020 */ 	sw	$a2,0x20($sp)
/*  f167214:	10a10004 */ 	beq	$a1,$at,.L0f167228
/*  f167218:	afa70024 */ 	sw	$a3,0x24($sp)
/*  f16721c:	24010022 */ 	addiu	$at,$zero,0x22
/*  f167220:	14a10012 */ 	bne	$a1,$at,.L0f16726c
/*  f167224:	00000000 */ 	nop
.L0f167228:
/*  f167228:	8fae0018 */ 	lw	$t6,0x18($sp)
/*  f16722c:	8fb90024 */ 	lw	$t9,0x24($sp)
/*  f167230:	3c18800a */ 	lui	$t8,%hi(g_FileInfo)
/*  f167234:	27186680 */ 	addiu	$t8,$t8,%lo(g_FileInfo)
/*  f167238:	000e78c0 */ 	sll	$t7,$t6,0x3
/*  f16723c:	01f83821 */ 	addu	$a3,$t7,$t8
/*  f167240:	acf90004 */ 	sw	$t9,0x4($a3)
/*  f167244:	8fa80018 */ 	lw	$t0,0x18($sp)
/*  f167248:	3c0a8008 */ 	lui	$t2,%hi(filetable)
/*  f16724c:	254a2060 */ 	addiu	$t2,$t2,%lo(filetable)
/*  f167250:	00084880 */ 	sll	$t1,$t0,0x2
/*  f167254:	012a3021 */ 	addu	$a2,$t1,$t2
/*  f167258:	8fa50024 */ 	lw	$a1,0x24($sp)
/*  f16725c:	0fc59bad */ 	jal	func0f166eb4
/*  f167260:	8fa40020 */ 	lw	$a0,0x20($sp)
/*  f167264:	10000003 */ 	b	.L0f167274
/*  f167268:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f16726c:
/*  f16726c:	1000ffff */ 	b	.L0f16726c
/*  f167270:	00000000 */ 	nop
.L0f167274:
/*  f167274:	8fa20020 */ 	lw	$v0,0x20($sp)
/*  f167278:	03e00008 */ 	jr	$ra
/*  f16727c:	27bd0018 */ 	addiu	$sp,$sp,0x18
);

u32 fileGetSize(s32 filenum)
{
	return g_FileInfo[filenum].size;
}

u32 fileGetUnk04(s32 filenum)
{
	return g_FileInfo[filenum].unk04;
}

GLOBAL_ASM(
glabel func0f1672a8
/*  f1672a8:	3c0f800a */ 	lui	$t7,%hi(g_FileInfo)
/*  f1672ac:	25ef6680 */ 	addiu	$t7,$t7,%lo(g_FileInfo)
/*  f1672b0:	000470c0 */ 	sll	$t6,$a0,0x3
/*  f1672b4:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f1672b8:	01cf1021 */ 	addu	$v0,$t6,$t7
/*  f1672bc:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f1672c0:	afa5001c */ 	sw	$a1,0x1c($sp)
/*  f1672c4:	ac460000 */ 	sw	$a2,0x0($v0)
/*  f1672c8:	10e00005 */ 	beqz	$a3,.L0f1672e0
/*  f1672cc:	ac460004 */ 	sw	$a2,0x4($v0)
/*  f1672d0:	00a02025 */ 	or	$a0,$a1,$zero
/*  f1672d4:	00c02825 */ 	or	$a1,$a2,$zero
/*  f1672d8:	0c00490c */ 	jal	func00012430
/*  f1672dc:	24060004 */ 	addiu	$a2,$zero,0x4
.L0f1672e0:
/*  f1672e0:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f1672e4:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f1672e8:	03e00008 */ 	jr	$ra
/*  f1672ec:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel func0f1672f0
/*  f1672f0:	afa40000 */ 	sw	$a0,0x0($sp)
/*  f1672f4:	308300ff */ 	andi	$v1,$a0,0xff
/*  f1672f8:	3c05800a */ 	lui	$a1,%hi(g_FileInfo)
/*  f1672fc:	24a56680 */ 	addiu	$a1,$a1,%lo(g_FileInfo)
/*  f167300:	24040004 */ 	addiu	$a0,$zero,0x4
/*  f167304:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f167308:	240607de */ 	addiu	$a2,$zero,0x7de
.L0f16730c:
/*  f16730c:	14830003 */ 	bne	$a0,$v1,.L0f16731c
/*  f167310:	000278c0 */ 	sll	$t7,$v0,0x3
/*  f167314:	00afc021 */ 	addu	$t8,$a1,$t7
/*  f167318:	af000000 */ 	sw	$zero,0x0($t8)
.L0f16731c:
/*  f16731c:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f167320:	1446fffa */ 	bne	$v0,$a2,.L0f16730c
/*  f167324:	00000000 */ 	nop
/*  f167328:	03e00008 */ 	jr	$ra
/*  f16732c:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel func0f167330
/*  f167330:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f167334:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f167338:	0fc59cbc */ 	jal	func0f1672f0
/*  f16733c:	24040005 */ 	addiu	$a0,$zero,0x5
/*  f167340:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f167344:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f167348:	03e00008 */ 	jr	$ra
/*  f16734c:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel func0f167350
/*  f167350:	27bdffc8 */ 	addiu	$sp,$sp,-56
/*  f167354:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f167358:	3c057f1b */ 	lui	$a1,%hi(var7f1b76f0)
/*  f16735c:	24a576f0 */ 	addiu	$a1,$a1,%lo(var7f1b76f0)
/*  f167360:	0c004c04 */ 	jal	func00013010
/*  f167364:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f167368:	10400061 */ 	beqz	$v0,.L0f1674f0
/*  f16736c:	3c057f1b */ 	lui	$a1,%hi(var7f1b76f8)
/*  f167370:	afa0002c */ 	sw	$zero,0x2c($sp)
/*  f167374:	24a576f8 */ 	addiu	$a1,$a1,%lo(var7f1b76f8)
/*  f167378:	0c004c04 */ 	jal	func00013010
/*  f16737c:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f167380:	00402025 */ 	or	$a0,$v0,$zero
/*  f167384:	00002825 */ 	or	$a1,$zero,$zero
/*  f167388:	0c004d02 */ 	jal	func00013408
/*  f16738c:	00003025 */ 	or	$a2,$zero,$zero
/*  f167390:	00027280 */ 	sll	$t6,$v0,0xa
/*  f167394:	3c057f1b */ 	lui	$a1,%hi(var7f1b7700)
/*  f167398:	afae0030 */ 	sw	$t6,0x30($sp)
/*  f16739c:	24a57700 */ 	addiu	$a1,$a1,%lo(var7f1b7700)
/*  f1673a0:	0c004c04 */ 	jal	func00013010
/*  f1673a4:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f1673a8:	1040002e */ 	beqz	$v0,.L0f167464
/*  f1673ac:	3c0a800a */ 	lui	$t2,%hi(g_Vars)
/*  f1673b0:	254a9fc0 */ 	addiu	$t2,$t2,%lo(g_Vars)
/*  f1673b4:	8d4f0298 */ 	lw	$t7,0x298($t2)
/*  f1673b8:	24010002 */ 	addiu	$at,$zero,0x2
/*  f1673bc:	05e30005 */ 	bgezl	$t7,.L0f1673d4
/*  f1673c0:	8d59006c */ 	lw	$t9,0x6c($t2)
/*  f1673c4:	8d58029c */ 	lw	$t8,0x29c($t2)
/*  f1673c8:	07000026 */ 	bltz	$t8,.L0f167464
/*  f1673cc:	00000000 */ 	nop
/*  f1673d0:	8d59006c */ 	lw	$t9,0x6c($t2)
.L0f1673d4:
/*  f1673d4:	00004025 */ 	or	$t0,$zero,$zero
/*  f1673d8:	00003825 */ 	or	$a3,$zero,$zero
/*  f1673dc:	13200003 */ 	beqz	$t9,.L0f1673ec
/*  f1673e0:	00001825 */ 	or	$v1,$zero,$zero
/*  f1673e4:	10000001 */ 	b	.L0f1673ec
/*  f1673e8:	24080001 */ 	addiu	$t0,$zero,0x1
.L0f1673ec:
/*  f1673ec:	8d4d0068 */ 	lw	$t5,0x68($t2)
/*  f1673f0:	00001025 */ 	or	$v0,$zero,$zero
/*  f1673f4:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f1673f8:	11a00003 */ 	beqz	$t5,.L0f167408
/*  f1673fc:	3c057f1b */ 	lui	$a1,%hi(var7f1b770c)
/*  f167400:	10000001 */ 	b	.L0f167408
/*  f167404:	24070001 */ 	addiu	$a3,$zero,0x1
.L0f167408:
/*  f167408:	8d4e0064 */ 	lw	$t6,0x64($t2)
/*  f16740c:	11c00003 */ 	beqz	$t6,.L0f16741c
/*  f167410:	00000000 */ 	nop
/*  f167414:	10000001 */ 	b	.L0f16741c
/*  f167418:	24030001 */ 	addiu	$v1,$zero,0x1
.L0f16741c:
/*  f16741c:	8d4f0070 */ 	lw	$t7,0x70($t2)
/*  f167420:	11e00003 */ 	beqz	$t7,.L0f167430
/*  f167424:	00000000 */ 	nop
/*  f167428:	10000001 */ 	b	.L0f167430
/*  f16742c:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f167430:
/*  f167430:	0043c021 */ 	addu	$t8,$v0,$v1
/*  f167434:	0307c821 */ 	addu	$t9,$t8,$a3
/*  f167438:	03286821 */ 	addu	$t5,$t9,$t0
/*  f16743c:	15a10009 */ 	bne	$t5,$at,.L0f167464
/*  f167440:	00000000 */ 	nop
/*  f167444:	0c004c04 */ 	jal	func00013010
/*  f167448:	24a5770c */ 	addiu	$a1,$a1,%lo(var7f1b770c)
/*  f16744c:	00402025 */ 	or	$a0,$v0,$zero
/*  f167450:	00002825 */ 	or	$a1,$zero,$zero
/*  f167454:	0c004d02 */ 	jal	func00013408
/*  f167458:	00003025 */ 	or	$a2,$zero,$zero
/*  f16745c:	00027280 */ 	sll	$t6,$v0,0xa
/*  f167460:	afae002c */ 	sw	$t6,0x2c($sp)
.L0f167464:
/*  f167464:	3c0a800a */ 	lui	$t2,%hi(g_Vars)
/*  f167468:	254a9fc0 */ 	addiu	$t2,$t2,%lo(g_Vars)
/*  f16746c:	8d4f0070 */ 	lw	$t7,0x70($t2)
/*  f167470:	8d44006c */ 	lw	$a0,0x6c($t2)
/*  f167474:	8d450068 */ 	lw	$a1,0x68($t2)
/*  f167478:	11e00003 */ 	beqz	$t7,.L0f167488
/*  f16747c:	8d490064 */ 	lw	$t1,0x64($t2)
/*  f167480:	10000002 */ 	b	.L0f16748c
/*  f167484:	24080001 */ 	addiu	$t0,$zero,0x1
.L0f167488:
/*  f167488:	00004025 */ 	or	$t0,$zero,$zero
.L0f16748c:
/*  f16748c:	10800003 */ 	beqz	$a0,.L0f16749c
/*  f167490:	8fb80030 */ 	lw	$t8,0x30($sp)
/*  f167494:	10000002 */ 	b	.L0f1674a0
/*  f167498:	24070001 */ 	addiu	$a3,$zero,0x1
.L0f16749c:
/*  f16749c:	00003825 */ 	or	$a3,$zero,$zero
.L0f1674a0:
/*  f1674a0:	10a00003 */ 	beqz	$a1,.L0f1674b0
/*  f1674a4:	8fb9002c */ 	lw	$t9,0x2c($sp)
/*  f1674a8:	10000002 */ 	b	.L0f1674b4
/*  f1674ac:	24030001 */ 	addiu	$v1,$zero,0x1
.L0f1674b0:
/*  f1674b0:	00001825 */ 	or	$v1,$zero,$zero
.L0f1674b4:
/*  f1674b4:	11200003 */ 	beqz	$t1,.L0f1674c4
/*  f1674b8:	03196821 */ 	addu	$t5,$t8,$t9
/*  f1674bc:	10000002 */ 	b	.L0f1674c8
/*  f1674c0:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f1674c4:
/*  f1674c4:	00001025 */ 	or	$v0,$zero,$zero
.L0f1674c8:
/*  f1674c8:	00027080 */ 	sll	$t6,$v0,0x2
/*  f1674cc:	00037880 */ 	sll	$t7,$v1,0x2
/*  f1674d0:	01cfc021 */ 	addu	$t8,$t6,$t7
/*  f1674d4:	0007c880 */ 	sll	$t9,$a3,0x2
/*  f1674d8:	03197021 */ 	addu	$t6,$t8,$t9
/*  f1674dc:	00087880 */ 	sll	$t7,$t0,0x2
/*  f1674e0:	01cfc021 */ 	addu	$t8,$t6,$t7
/*  f1674e4:	3c018008 */ 	lui	$at,%hi(filetable+0x1f7c)
/*  f1674e8:	00380821 */ 	addu	$at,$at,$t8
/*  f1674ec:	ac2d3fdc */ 	sw	$t5,%lo(filetable+0x1f7c)($at)
.L0f1674f0:
/*  f1674f0:	3c057f1b */ 	lui	$a1,%hi(var7f1b7718)
/*  f1674f4:	24a57718 */ 	addiu	$a1,$a1,%lo(var7f1b7718)
/*  f1674f8:	0c004c04 */ 	jal	func00013010
/*  f1674fc:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f167500:	3c0a800a */ 	lui	$t2,%hi(g_Vars)
/*  f167504:	10400034 */ 	beqz	$v0,.L0f1675d8
/*  f167508:	254a9fc0 */ 	addiu	$t2,$t2,%lo(g_Vars)
/*  f16750c:	8d590070 */ 	lw	$t9,0x70($t2)
/*  f167510:	3c057f1b */ 	lui	$a1,%hi(var7f1b7720)
/*  f167514:	24a57720 */ 	addiu	$a1,$a1,%lo(var7f1b7720)
/*  f167518:	13200003 */ 	beqz	$t9,.L0f167528
/*  f16751c:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f167520:	10000002 */ 	b	.L0f16752c
/*  f167524:	24090001 */ 	addiu	$t1,$zero,0x1
.L0f167528:
/*  f167528:	00004825 */ 	or	$t1,$zero,$zero
.L0f16752c:
/*  f16752c:	8d4e006c */ 	lw	$t6,0x6c($t2)
/*  f167530:	00004025 */ 	or	$t0,$zero,$zero
/*  f167534:	00003825 */ 	or	$a3,$zero,$zero
/*  f167538:	11c00003 */ 	beqz	$t6,.L0f167548
/*  f16753c:	00001825 */ 	or	$v1,$zero,$zero
/*  f167540:	10000001 */ 	b	.L0f167548
/*  f167544:	24080001 */ 	addiu	$t0,$zero,0x1
.L0f167548:
/*  f167548:	8d4f0068 */ 	lw	$t7,0x68($t2)
/*  f16754c:	11e00003 */ 	beqz	$t7,.L0f16755c
/*  f167550:	00000000 */ 	nop
/*  f167554:	10000001 */ 	b	.L0f16755c
/*  f167558:	24070001 */ 	addiu	$a3,$zero,0x1
.L0f16755c:
/*  f16755c:	8d4d0064 */ 	lw	$t5,0x64($t2)
/*  f167560:	11a00003 */ 	beqz	$t5,.L0f167570
/*  f167564:	00000000 */ 	nop
/*  f167568:	10000001 */ 	b	.L0f167570
/*  f16756c:	24030001 */ 	addiu	$v1,$zero,0x1
.L0f167570:
/*  f167570:	afa30024 */ 	sw	$v1,0x24($sp)
/*  f167574:	afa70020 */ 	sw	$a3,0x20($sp)
/*  f167578:	afa8001c */ 	sw	$t0,0x1c($sp)
/*  f16757c:	0c004c04 */ 	jal	func00013010
/*  f167580:	afa90018 */ 	sw	$t1,0x18($sp)
/*  f167584:	00402025 */ 	or	$a0,$v0,$zero
/*  f167588:	00002825 */ 	or	$a1,$zero,$zero
/*  f16758c:	0c004d02 */ 	jal	func00013408
/*  f167590:	00003025 */ 	or	$a2,$zero,$zero
/*  f167594:	8fa30024 */ 	lw	$v1,0x24($sp)
/*  f167598:	8fa70020 */ 	lw	$a3,0x20($sp)
/*  f16759c:	8fa8001c */ 	lw	$t0,0x1c($sp)
/*  f1675a0:	8fa90018 */ 	lw	$t1,0x18($sp)
/*  f1675a4:	0003c880 */ 	sll	$t9,$v1,0x2
/*  f1675a8:	00077080 */ 	sll	$t6,$a3,0x2
/*  f1675ac:	032e7821 */ 	addu	$t7,$t9,$t6
/*  f1675b0:	00086880 */ 	sll	$t5,$t0,0x2
/*  f1675b4:	01edc821 */ 	addu	$t9,$t7,$t5
/*  f1675b8:	00097080 */ 	sll	$t6,$t1,0x2
/*  f1675bc:	032e7821 */ 	addu	$t7,$t9,$t6
/*  f1675c0:	3c018008 */ 	lui	$at,%hi(var80083fec)
/*  f1675c4:	002f0821 */ 	addu	$at,$at,$t7
/*  f1675c8:	3c0a800a */ 	lui	$t2,%hi(g_Vars)
/*  f1675cc:	0002c280 */ 	sll	$t8,$v0,0xa
/*  f1675d0:	ac383fec */ 	sw	$t8,%lo(var80083fec)($at)
/*  f1675d4:	254a9fc0 */ 	addiu	$t2,$t2,%lo(g_Vars)
.L0f1675d8:
/*  f1675d8:	8d4d006c */ 	lw	$t5,0x6c($t2)
/*  f1675dc:	3c048008 */ 	lui	$a0,%hi(filetable+0x1f7c)
/*  f1675e0:	51a00004 */ 	beqzl	$t5,.L0f1675f4
/*  f1675e4:	00004025 */ 	or	$t0,$zero,$zero
/*  f1675e8:	10000002 */ 	b	.L0f1675f4
/*  f1675ec:	24080001 */ 	addiu	$t0,$zero,0x1
/*  f1675f0:	00004025 */ 	or	$t0,$zero,$zero
.L0f1675f4:
/*  f1675f4:	8d590068 */ 	lw	$t9,0x68($t2)
/*  f1675f8:	53200004 */ 	beqzl	$t9,.L0f16760c
/*  f1675fc:	00003825 */ 	or	$a3,$zero,$zero
/*  f167600:	10000002 */ 	b	.L0f16760c
/*  f167604:	24070001 */ 	addiu	$a3,$zero,0x1
/*  f167608:	00003825 */ 	or	$a3,$zero,$zero
.L0f16760c:
/*  f16760c:	8d4e0064 */ 	lw	$t6,0x64($t2)
/*  f167610:	51c00004 */ 	beqzl	$t6,.L0f167624
/*  f167614:	00001825 */ 	or	$v1,$zero,$zero
/*  f167618:	10000002 */ 	b	.L0f167624
/*  f16761c:	24030001 */ 	addiu	$v1,$zero,0x1
/*  f167620:	00001825 */ 	or	$v1,$zero,$zero
.L0f167624:
/*  f167624:	8d580070 */ 	lw	$t8,0x70($t2)
/*  f167628:	00036880 */ 	sll	$t5,$v1,0x2
/*  f16762c:	00077080 */ 	sll	$t6,$a3,0x2
/*  f167630:	53000004 */ 	beqzl	$t8,.L0f167644
/*  f167634:	00001025 */ 	or	$v0,$zero,$zero
/*  f167638:	10000002 */ 	b	.L0f167644
/*  f16763c:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f167640:	00001025 */ 	or	$v0,$zero,$zero
.L0f167644:
/*  f167644:	00027880 */ 	sll	$t7,$v0,0x2
/*  f167648:	01edc821 */ 	addu	$t9,$t7,$t5
/*  f16764c:	032ec021 */ 	addu	$t8,$t9,$t6
/*  f167650:	00087880 */ 	sll	$t7,$t0,0x2
/*  f167654:	030f6821 */ 	addu	$t5,$t8,$t7
/*  f167658:	008d2021 */ 	addu	$a0,$a0,$t5
/*  f16765c:	8c843fdc */ 	lw	$a0,%lo(filetable+0x1f7c)($a0)
/*  f167660:	24050004 */ 	addiu	$a1,$zero,0x4
/*  f167664:	0004c840 */ 	sll	$t9,$a0,0x1
/*  f167668:	0c0048f2 */ 	jal	malloc
/*  f16766c:	03202025 */ 	or	$a0,$t9,$zero
/*  f167670:	3c0a800a */ 	lui	$t2,%hi(g_Vars)
/*  f167674:	254a9fc0 */ 	addiu	$t2,$t2,%lo(g_Vars)
/*  f167678:	8d44006c */ 	lw	$a0,0x6c($t2)
/*  f16767c:	3c06800b */ 	lui	$a2,%hi(var800aa580)
/*  f167680:	24c6a580 */ 	addiu	$a2,$a2,%lo(var800aa580)
/*  f167684:	10800003 */ 	beqz	$a0,.L0f167694
/*  f167688:	acc20000 */ 	sw	$v0,0x0($a2)
/*  f16768c:	10000002 */ 	b	.L0f167698
/*  f167690:	24080001 */ 	addiu	$t0,$zero,0x1
.L0f167694:
/*  f167694:	00004025 */ 	or	$t0,$zero,$zero
.L0f167698:
/*  f167698:	8d450068 */ 	lw	$a1,0x68($t2)
/*  f16769c:	50a00004 */ 	beqzl	$a1,.L0f1676b0
/*  f1676a0:	00003825 */ 	or	$a3,$zero,$zero
/*  f1676a4:	10000002 */ 	b	.L0f1676b0
/*  f1676a8:	24070001 */ 	addiu	$a3,$zero,0x1
/*  f1676ac:	00003825 */ 	or	$a3,$zero,$zero
.L0f1676b0:
/*  f1676b0:	8d490064 */ 	lw	$t1,0x64($t2)
/*  f1676b4:	00076880 */ 	sll	$t5,$a3,0x2
/*  f1676b8:	51200004 */ 	beqzl	$t1,.L0f1676cc
/*  f1676bc:	00001825 */ 	or	$v1,$zero,$zero
/*  f1676c0:	10000002 */ 	b	.L0f1676cc
/*  f1676c4:	24030001 */ 	addiu	$v1,$zero,0x1
/*  f1676c8:	00001825 */ 	or	$v1,$zero,$zero
.L0f1676cc:
/*  f1676cc:	8d4b0070 */ 	lw	$t3,0x70($t2)
/*  f1676d0:	0003c080 */ 	sll	$t8,$v1,0x2
/*  f1676d4:	51600004 */ 	beqzl	$t3,.L0f1676e8
/*  f1676d8:	00001025 */ 	or	$v0,$zero,$zero
/*  f1676dc:	10000002 */ 	b	.L0f1676e8
/*  f1676e0:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f1676e4:	00001025 */ 	or	$v0,$zero,$zero
.L0f1676e8:
/*  f1676e8:	00027080 */ 	sll	$t6,$v0,0x2
/*  f1676ec:	01d87821 */ 	addu	$t7,$t6,$t8
/*  f1676f0:	01edc821 */ 	addu	$t9,$t7,$t5
/*  f1676f4:	00087080 */ 	sll	$t6,$t0,0x2
/*  f1676f8:	032ec021 */ 	addu	$t8,$t9,$t6
/*  f1676fc:	3c0f8008 */ 	lui	$t7,%hi(filetable+0x1f7c)
/*  f167700:	01f87821 */ 	addu	$t7,$t7,$t8
/*  f167704:	8def3fdc */ 	lw	$t7,%lo(filetable+0x1f7c)($t7)
/*  f167708:	8ccd0000 */ 	lw	$t5,0x0($a2)
/*  f16770c:	01edc821 */ 	addu	$t9,$t7,$t5
/*  f167710:	10800003 */ 	beqz	$a0,.L0f167720
/*  f167714:	acd90004 */ 	sw	$t9,0x4($a2)
/*  f167718:	10000002 */ 	b	.L0f167724
/*  f16771c:	24080001 */ 	addiu	$t0,$zero,0x1
.L0f167720:
/*  f167720:	00004025 */ 	or	$t0,$zero,$zero
.L0f167724:
/*  f167724:	50a00004 */ 	beqzl	$a1,.L0f167738
/*  f167728:	00003825 */ 	or	$a3,$zero,$zero
/*  f16772c:	10000002 */ 	b	.L0f167738
/*  f167730:	24070001 */ 	addiu	$a3,$zero,0x1
/*  f167734:	00003825 */ 	or	$a3,$zero,$zero
.L0f167738:
/*  f167738:	11200003 */ 	beqz	$t1,.L0f167748
/*  f16773c:	00076880 */ 	sll	$t5,$a3,0x2
/*  f167740:	10000002 */ 	b	.L0f16774c
/*  f167744:	24030001 */ 	addiu	$v1,$zero,0x1
.L0f167748:
/*  f167748:	00001825 */ 	or	$v1,$zero,$zero
.L0f16774c:
/*  f16774c:	11600003 */ 	beqz	$t3,.L0f16775c
/*  f167750:	0003c080 */ 	sll	$t8,$v1,0x2
/*  f167754:	10000002 */ 	b	.L0f167760
/*  f167758:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f16775c:
/*  f16775c:	00001025 */ 	or	$v0,$zero,$zero
.L0f167760:
/*  f167760:	00027080 */ 	sll	$t6,$v0,0x2
/*  f167764:	01d87821 */ 	addu	$t7,$t6,$t8
/*  f167768:	01edc821 */ 	addu	$t9,$t7,$t5
/*  f16776c:	00087080 */ 	sll	$t6,$t0,0x2
/*  f167770:	032ec021 */ 	addu	$t8,$t9,$t6
/*  f167774:	3c0f8008 */ 	lui	$t7,%hi(filetable+0x1f7c)
/*  f167778:	01f87821 */ 	addu	$t7,$t7,$t8
/*  f16777c:	8def3fdc */ 	lw	$t7,%lo(filetable+0x1f7c)($t7)
/*  f167780:	8ccd0004 */ 	lw	$t5,0x4($a2)
/*  f167784:	01edc821 */ 	addu	$t9,$t7,$t5
/*  f167788:	10800003 */ 	beqz	$a0,.L0f167798
/*  f16778c:	acd90008 */ 	sw	$t9,0x8($a2)
/*  f167790:	10000002 */ 	b	.L0f16779c
/*  f167794:	24080001 */ 	addiu	$t0,$zero,0x1
.L0f167798:
/*  f167798:	00004025 */ 	or	$t0,$zero,$zero
.L0f16779c:
/*  f16779c:	10a00003 */ 	beqz	$a1,.L0f1677ac
/*  f1677a0:	3c048008 */ 	lui	$a0,%hi(var80083fec)
/*  f1677a4:	10000002 */ 	b	.L0f1677b0
/*  f1677a8:	24070001 */ 	addiu	$a3,$zero,0x1
.L0f1677ac:
/*  f1677ac:	00003825 */ 	or	$a3,$zero,$zero
.L0f1677b0:
/*  f1677b0:	11200003 */ 	beqz	$t1,.L0f1677c0
/*  f1677b4:	00076880 */ 	sll	$t5,$a3,0x2
/*  f1677b8:	10000002 */ 	b	.L0f1677c4
/*  f1677bc:	24030001 */ 	addiu	$v1,$zero,0x1
.L0f1677c0:
/*  f1677c0:	00001825 */ 	or	$v1,$zero,$zero
.L0f1677c4:
/*  f1677c4:	11600003 */ 	beqz	$t3,.L0f1677d4
/*  f1677c8:	0003c080 */ 	sll	$t8,$v1,0x2
/*  f1677cc:	10000002 */ 	b	.L0f1677d8
/*  f1677d0:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f1677d4:
/*  f1677d4:	00001025 */ 	or	$v0,$zero,$zero
.L0f1677d8:
/*  f1677d8:	00027080 */ 	sll	$t6,$v0,0x2
/*  f1677dc:	01d87821 */ 	addu	$t7,$t6,$t8
/*  f1677e0:	01edc821 */ 	addu	$t9,$t7,$t5
/*  f1677e4:	00087080 */ 	sll	$t6,$t0,0x2
/*  f1677e8:	032ec021 */ 	addu	$t8,$t9,$t6
/*  f1677ec:	00982021 */ 	addu	$a0,$a0,$t8
/*  f1677f0:	8c843fec */ 	lw	$a0,%lo(var80083fec)($a0)
/*  f1677f4:	24050004 */ 	addiu	$a1,$zero,0x4
/*  f1677f8:	00047840 */ 	sll	$t7,$a0,0x1
/*  f1677fc:	0c0048f2 */ 	jal	malloc
/*  f167800:	01e02025 */ 	or	$a0,$t7,$zero
/*  f167804:	3c0a800a */ 	lui	$t2,%hi(g_Vars)
/*  f167808:	254a9fc0 */ 	addiu	$t2,$t2,%lo(g_Vars)
/*  f16780c:	8d44006c */ 	lw	$a0,0x6c($t2)
/*  f167810:	3c0c800b */ 	lui	$t4,%hi(var800aa590)
/*  f167814:	258ca590 */ 	addiu	$t4,$t4,%lo(var800aa590)
/*  f167818:	10800003 */ 	beqz	$a0,.L0f167828
/*  f16781c:	ad820000 */ 	sw	$v0,0x0($t4)
/*  f167820:	10000002 */ 	b	.L0f16782c
/*  f167824:	24080001 */ 	addiu	$t0,$zero,0x1
.L0f167828:
/*  f167828:	00004025 */ 	or	$t0,$zero,$zero
.L0f16782c:
/*  f16782c:	8d450068 */ 	lw	$a1,0x68($t2)
/*  f167830:	00003825 */ 	or	$a3,$zero,$zero
/*  f167834:	00001825 */ 	or	$v1,$zero,$zero
/*  f167838:	10a00003 */ 	beqz	$a1,.L0f167848
/*  f16783c:	3c01800b */ 	lui	$at,%hi(var800aa5a0)
/*  f167840:	10000001 */ 	b	.L0f167848
/*  f167844:	24070001 */ 	addiu	$a3,$zero,0x1
.L0f167848:
/*  f167848:	8d490064 */ 	lw	$t1,0x64($t2)
/*  f16784c:	0007c080 */ 	sll	$t8,$a3,0x2
/*  f167850:	00001025 */ 	or	$v0,$zero,$zero
/*  f167854:	11200003 */ 	beqz	$t1,.L0f167864
/*  f167858:	00000000 */ 	nop
/*  f16785c:	10000001 */ 	b	.L0f167864
/*  f167860:	24030001 */ 	addiu	$v1,$zero,0x1
.L0f167864:
/*  f167864:	8d4b0070 */ 	lw	$t3,0x70($t2)
/*  f167868:	0003c880 */ 	sll	$t9,$v1,0x2
/*  f16786c:	00003825 */ 	or	$a3,$zero,$zero
/*  f167870:	11600003 */ 	beqz	$t3,.L0f167880
/*  f167874:	00000000 */ 	nop
/*  f167878:	10000001 */ 	b	.L0f167880
/*  f16787c:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f167880:
/*  f167880:	00026880 */ 	sll	$t5,$v0,0x2
/*  f167884:	01b97021 */ 	addu	$t6,$t5,$t9
/*  f167888:	01d87821 */ 	addu	$t7,$t6,$t8
/*  f16788c:	00086880 */ 	sll	$t5,$t0,0x2
/*  f167890:	01edc821 */ 	addu	$t9,$t7,$t5
/*  f167894:	3c0e8008 */ 	lui	$t6,%hi(var80083fec)
/*  f167898:	01d97021 */ 	addu	$t6,$t6,$t9
/*  f16789c:	8dce3fec */ 	lw	$t6,%lo(var80083fec)($t6)
/*  f1678a0:	8d860000 */ 	lw	$a2,0x0($t4)
/*  f1678a4:	00004025 */ 	or	$t0,$zero,$zero
/*  f1678a8:	00001825 */ 	or	$v1,$zero,$zero
/*  f1678ac:	01c6c021 */ 	addu	$t8,$t6,$a2
/*  f1678b0:	10800003 */ 	beqz	$a0,.L0f1678c0
/*  f1678b4:	ad980004 */ 	sw	$t8,0x4($t4)
/*  f1678b8:	10000001 */ 	b	.L0f1678c0
/*  f1678bc:	24080001 */ 	addiu	$t0,$zero,0x1
.L0f1678c0:
/*  f1678c0:	10a00003 */ 	beqz	$a1,.L0f1678d0
/*  f1678c4:	00001025 */ 	or	$v0,$zero,$zero
/*  f1678c8:	10000001 */ 	b	.L0f1678d0
/*  f1678cc:	24070001 */ 	addiu	$a3,$zero,0x1
.L0f1678d0:
/*  f1678d0:	11200003 */ 	beqz	$t1,.L0f1678e0
/*  f1678d4:	00077080 */ 	sll	$t6,$a3,0x2
/*  f1678d8:	10000001 */ 	b	.L0f1678e0
/*  f1678dc:	24030001 */ 	addiu	$v1,$zero,0x1
.L0f1678e0:
/*  f1678e0:	11600003 */ 	beqz	$t3,.L0f1678f0
/*  f1678e4:	00036880 */ 	sll	$t5,$v1,0x2
/*  f1678e8:	10000001 */ 	b	.L0f1678f0
/*  f1678ec:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f1678f0:
/*  f1678f0:	00027880 */ 	sll	$t7,$v0,0x2
/*  f1678f4:	01edc821 */ 	addu	$t9,$t7,$t5
/*  f1678f8:	032ec021 */ 	addu	$t8,$t9,$t6
/*  f1678fc:	00087880 */ 	sll	$t7,$t0,0x2
/*  f167900:	030f6821 */ 	addu	$t5,$t8,$t7
/*  f167904:	3c198008 */ 	lui	$t9,%hi(var80083fec)
/*  f167908:	032dc821 */ 	addu	$t9,$t9,$t5
/*  f16790c:	8f393fec */ 	lw	$t9,%lo(var80083fec)($t9)
/*  f167910:	8d8e0004 */ 	lw	$t6,0x4($t4)
/*  f167914:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f167918:	27bd0038 */ 	addiu	$sp,$sp,0x38
/*  f16791c:	032ec021 */ 	addu	$t8,$t9,$t6
/*  f167920:	ad980008 */ 	sw	$t8,0x8($t4)
/*  f167924:	a020a5a0 */ 	sb	$zero,%lo(var800aa5a0)($at)
/*  f167928:	3c01800b */ 	lui	$at,%hi(var800aa5a4)
/*  f16792c:	ac20a5a4 */ 	sw	$zero,%lo(var800aa5a4)($at)
/*  f167930:	3c01800b */ 	lui	$at,%hi(var800aa59c)
/*  f167934:	03e00008 */ 	jr	$ra
/*  f167938:	ac26a59c */ 	sw	$a2,%lo(var800aa59c)($at)
);

GLOBAL_ASM(
glabel func0f16793c
/*  f16793c:	3c0f800b */ 	lui	$t7,%hi(var800aa5a0)
/*  f167940:	91efa5a0 */ 	lbu	$t7,%lo(var800aa5a0)($t7)
/*  f167944:	3c02800b */ 	lui	$v0,%hi(var800aa580)
/*  f167948:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f16794c:	000fc080 */ 	sll	$t8,$t7,0x2
/*  f167950:	3c01800b */ 	lui	$at,%hi(var800aa5a4)
/*  f167954:	00581021 */ 	addu	$v0,$v0,$t8
/*  f167958:	ac2ea5a4 */ 	sw	$t6,%lo(var800aa5a4)($at)
/*  f16795c:	03e00008 */ 	jr	$ra
/*  f167960:	8c42a580 */ 	lw	$v0,%lo(var800aa580)($v0)
);

GLOBAL_ASM(
glabel func0f167964
/*  f167964:	3c06800b */ 	lui	$a2,%hi(var800aa59c)
/*  f167968:	24c6a59c */ 	addiu	$a2,$a2,%lo(var800aa59c)
/*  f16796c:	8cc20000 */ 	lw	$v0,0x0($a2)
/*  f167970:	00047080 */ 	sll	$t6,$a0,0x2
/*  f167974:	01c47023 */ 	subu	$t6,$t6,$a0
/*  f167978:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f16797c:	004e7821 */ 	addu	$t7,$v0,$t6
/*  f167980:	25f9000f */ 	addiu	$t9,$t7,0xf
/*  f167984:	3728000f */ 	ori	$t0,$t9,0xf
/*  f167988:	accf0000 */ 	sw	$t7,0x0($a2)
/*  f16798c:	3909000f */ 	xori	$t1,$t0,0xf
/*  f167990:	03e00008 */ 	jr	$ra
/*  f167994:	acc90000 */ 	sw	$t1,0x0($a2)
);

GLOBAL_ASM(
glabel func0f167998
/*  f167998:	3c05800b */ 	lui	$a1,%hi(var800aa59c)
/*  f16799c:	24a5a59c */ 	addiu	$a1,$a1,%lo(var800aa59c)
/*  f1679a0:	8ca20000 */ 	lw	$v0,0x0($a1)
/*  f1679a4:	244e0040 */ 	addiu	$t6,$v0,0x40
/*  f1679a8:	03e00008 */ 	jr	$ra
/*  f1679ac:	acae0000 */ 	sw	$t6,0x0($a1)
);

GLOBAL_ASM(
glabel func0f1679b0
/*  f1679b0:	3c06800b */ 	lui	$a2,%hi(var800aa59c)
/*  f1679b4:	24c6a59c */ 	addiu	$a2,$a2,%lo(var800aa59c)
/*  f1679b8:	8cc20000 */ 	lw	$v0,0x0($a2)
/*  f1679bc:	00047100 */ 	sll	$t6,$a0,0x4
/*  f1679c0:	004e7821 */ 	addu	$t7,$v0,$t6
/*  f1679c4:	03e00008 */ 	jr	$ra
/*  f1679c8:	accf0000 */ 	sw	$t7,0x0($a2)
);

GLOBAL_ASM(
glabel func0f1679cc
/*  f1679cc:	3c06800b */ 	lui	$a2,%hi(var800aa59c)
/*  f1679d0:	24c6a59c */ 	addiu	$a2,$a2,%lo(var800aa59c)
/*  f1679d4:	00047080 */ 	sll	$t6,$a0,0x2
/*  f1679d8:	8cc20000 */ 	lw	$v0,0x0($a2)
/*  f1679dc:	25c4000f */ 	addiu	$a0,$t6,0xf
/*  f1679e0:	348f000f */ 	ori	$t7,$a0,0xf
/*  f1679e4:	39f8000f */ 	xori	$t8,$t7,0xf
/*  f1679e8:	0058c821 */ 	addu	$t9,$v0,$t8
/*  f1679ec:	03e00008 */ 	jr	$ra
/*  f1679f0:	acd90000 */ 	sw	$t9,0x0($a2)
);

GLOBAL_ASM(
glabel func0f1679f4
/*  f1679f4:	3c06800b */ 	lui	$a2,%hi(var800aa59c)
/*  f1679f8:	24c6a59c */ 	addiu	$a2,$a2,%lo(var800aa59c)
/*  f1679fc:	8cc20000 */ 	lw	$v0,0x0($a2)
/*  f167a00:	2484000f */ 	addiu	$a0,$a0,0xf
/*  f167a04:	348e000f */ 	ori	$t6,$a0,0xf
/*  f167a08:	39cf000f */ 	xori	$t7,$t6,0xf
/*  f167a0c:	004fc021 */ 	addu	$t8,$v0,$t7
/*  f167a10:	03e00008 */ 	jr	$ra
/*  f167a14:	acd80000 */ 	sw	$t8,0x0($a2)
);

GLOBAL_ASM(
glabel func0f167a18
/*  f167a18:	3c04800b */ 	lui	$a0,%hi(var800aa5a0)
/*  f167a1c:	2484a5a0 */ 	addiu	$a0,$a0,%lo(var800aa5a0)
/*  f167a20:	908e0000 */ 	lbu	$t6,0x0($a0)
/*  f167a24:	3c01800b */ 	lui	$at,%hi(var800aa5a4)
/*  f167a28:	3c19800b */ 	lui	$t9,%hi(var800aa590)
/*  f167a2c:	39cf0001 */ 	xori	$t7,$t6,0x1
/*  f167a30:	a08f0000 */ 	sb	$t7,0x0($a0)
/*  f167a34:	ac20a5a4 */ 	sw	$zero,%lo(var800aa5a4)($at)
/*  f167a38:	90820000 */ 	lbu	$v0,0x0($a0)
/*  f167a3c:	3c058008 */ 	lui	$a1,%hi(var80084008)
/*  f167a40:	3c01800b */ 	lui	$at,%hi(var800aa59c)
/*  f167a44:	0002c080 */ 	sll	$t8,$v0,0x2
/*  f167a48:	0338c821 */ 	addu	$t9,$t9,$t8
/*  f167a4c:	8f39a590 */ 	lw	$t9,%lo(var800aa590)($t9)
/*  f167a50:	24a54008 */ 	addiu	$a1,$a1,%lo(var80084008)
/*  f167a54:	240a0002 */ 	addiu	$t2,$zero,0x2
/*  f167a58:	ac39a59c */ 	sw	$t9,%lo(var800aa59c)($at)
/*  f167a5c:	8ca30000 */ 	lw	$v1,0x0($a1)
/*  f167a60:	3c018008 */ 	lui	$at,%hi(var80084000)
/*  f167a64:	00380821 */ 	addu	$at,$at,$t8
/*  f167a68:	ac234000 */ 	sw	$v1,%lo(var80084000)($at)
/*  f167a6c:	2401ffff */ 	addiu	$at,$zero,-1
/*  f167a70:	24680001 */ 	addiu	$t0,$v1,0x1
/*  f167a74:	15010002 */ 	bne	$t0,$at,.L0f167a80
/*  f167a78:	aca80000 */ 	sw	$t0,0x0($a1)
/*  f167a7c:	acaa0000 */ 	sw	$t2,0x0($a1)
.L0f167a80:
/*  f167a80:	03e00008 */ 	jr	$ra
/*  f167a84:	00000000 */ 	nop
/*  f167a88:	3c0e800b */ 	lui	$t6,%hi(var800aa5a0)
/*  f167a8c:	91cea5a0 */ 	lbu	$t6,%lo(var800aa5a0)($t6)
/*  f167a90:	3c18800b */ 	lui	$t8,%hi(var800aa584)
/*  f167a94:	000e7880 */ 	sll	$t7,$t6,0x2
/*  f167a98:	030fc021 */ 	addu	$t8,$t8,$t7
/*  f167a9c:	8f18a584 */ 	lw	$t8,%lo(var800aa584)($t8)
/*  f167aa0:	03041023 */ 	subu	$v0,$t8,$a0
/*  f167aa4:	0002c8c3 */ 	sra	$t9,$v0,0x3
/*  f167aa8:	03e00008 */ 	jr	$ra
/*  f167aac:	03201025 */ 	or	$v0,$t9,$zero
/*  f167ab0:	3c0e800b */ 	lui	$t6,%hi(var800aa5a0)
/*  f167ab4:	91cea5a0 */ 	lbu	$t6,%lo(var800aa5a0)($t6)
/*  f167ab8:	3c18800b */ 	lui	$t8,%hi(var800aa594)
/*  f167abc:	3c19800b */ 	lui	$t9,%hi(var800aa59c)
/*  f167ac0:	000e7880 */ 	sll	$t7,$t6,0x2
/*  f167ac4:	030fc021 */ 	addu	$t8,$t8,$t7
/*  f167ac8:	8f18a594 */ 	lw	$t8,%lo(var800aa594)($t8)
/*  f167acc:	8f39a59c */ 	lw	$t9,%lo(var800aa59c)($t9)
/*  f167ad0:	03e00008 */ 	jr	$ra
/*  f167ad4:	03191023 */ 	subu	$v0,$t8,$t9
/*  f167ad8:	00000000 */ 	nop
/*  f167adc:	00000000 */ 	nop
);
