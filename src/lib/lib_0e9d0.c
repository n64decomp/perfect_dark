#include <ultra64.h>
#include "constants.h"
#include "game/data/data_000000.h"
#include "game/data/data_0083d0.h"
#include "game/data/data_00e460.h"
#include "game/data/data_0160b0.h"
#include "game/data/data_01a3a0.h"
#include "game/data/data_020df0.h"
#include "game/game_166e40.h"
#include "game/game_167ae0.h"
#include "game/game_16cfa0.h"
#include "gvars/gvars.h"
#include "lib/lib_074f0.h"
#include "lib/lib_08a20.h"
#include "lib/lib_0d0a0.h"
#include "lib/lib_0e9d0.h"
#include "lib/lib_121e0.h"
#include "lib/lib_12dc0.h"
#include "lib/lib_13130.h"
#include "lib/lib_2faf0.h"
#include "lib/lib_2fc60.h"
#include "lib/lib_317f0.h"
#include "lib/lib_37650.h"
#include "lib/lib_37b00.h"
#include "lib/lib_38d10.h"
#include "lib/lib_38d30.h"
#include "lib/lib_39c80.h"
#include "lib/lib_481e0.h"
#include "lib/lib_48830.h"
#include "types.h"

const char var70053b20[] = "RUSSES SOUND GUARD STRING";
const char var70053b3c[] = "Snd: SoundHeaderCacheInit\n";
const char var70053b58[] = "-nomp3";
const char var70053b60[] = "RWI : Initialising the new and improved MP3 player\n";
const char var70053b94[] = "RWI : MP3 player Initialising Done\n";
const char var70053bb8[] = "gsSndpNew\n";
const char var70053bc4[] = "Set the sample callbacks\n";
const char var70053be0[] = "Snd_Play_Universal : Overriding -> Link = %d\n";
const char var70053c10[] = "Snd_Play_Mpeg : SYSTEM IS DISABLED\n";
const char var70053c34[] = "Snd_Play_Mpeg  : Lib called -> Adr=%x\n";
const char var70053c5c[] = "Snd_Play_Mpeg  : Chunk size -> Adr=%x\n";
const u32 var70053c84[] = {0x3ee147ae};
const u32 var70053c88[] = {0x3f266666};
const u32 var70053c8c[] = {0x3e99999a};
const u32 var70053c90[] = {0x3f333333};
const u32 var70053c94[] = {0x3eb33333};
const u32 var70053c98[] = {0x3f4ccccd};
const u32 var70053c9c[] = {0x00000000};

GLOBAL_ASM(
glabel func0000e9d0
/*     e9d0:	3c028009 */ 	lui	$v0,%hi(var80094eb4)
/*     e9d4:	03e00008 */ 	jr	$ra
/*     e9d8:	8c424eb4 */ 	lw	$v0,%lo(var80094eb4)($v0)
);

GLOBAL_ASM(
glabel func0000e9dc
/*     e9dc:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*     e9e0:	afbf0014 */ 	sw	$ra,0x14($sp)
/*     e9e4:	0c00cfb1 */ 	jal	func00033ec4
/*     e9e8:	00002025 */ 	or	$a0,$zero,$zero
/*     e9ec:	28415000 */ 	slti	$at,$v0,0x5000
/*     e9f0:	10200005 */ 	beqz	$at,.L0000ea08
/*     e9f4:	24035000 */ 	addiu	$v1,$zero,0x5000
/*     e9f8:	0c00cfb1 */ 	jal	func00033ec4
/*     e9fc:	00002025 */ 	or	$a0,$zero,$zero
/*     ea00:	10000001 */ 	beqz	$zero,.L0000ea08
/*     ea04:	00401825 */ 	or	$v1,$v0,$zero
.L0000ea08:
/*     ea08:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*     ea0c:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*     ea10:	3062ffff */ 	andi	$v0,$v1,0xffff
/*     ea14:	03e00008 */ 	jr	$ra
/*     ea18:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel audioSetSfxVolume
/*     ea1c:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*     ea20:	afb10018 */ 	sw	$s1,0x18($sp)
/*     ea24:	3091ffff */ 	andi	$s1,$a0,0xffff
/*     ea28:	2a215001 */ 	slti	$at,$s1,0x5001
/*     ea2c:	afbf001c */ 	sw	$ra,0x1c($sp)
/*     ea30:	afb00014 */ 	sw	$s0,0x14($sp)
/*     ea34:	14200002 */ 	bnez	$at,.L0000ea40
/*     ea38:	afa40020 */ 	sw	$a0,0x20($sp)
/*     ea3c:	24115000 */ 	addiu	$s1,$zero,0x5000
.L0000ea40:
/*     ea40:	00008025 */ 	or	$s0,$zero,$zero
.L0000ea44:
/*     ea44:	320400ff */ 	andi	$a0,$s0,0xff
/*     ea48:	0c00cfd1 */ 	jal	func00033f44
/*     ea4c:	3225ffff */ 	andi	$a1,$s1,0xffff
/*     ea50:	26100001 */ 	addiu	$s0,$s0,0x1
/*     ea54:	320e00ff */ 	andi	$t6,$s0,0xff
/*     ea58:	29c10009 */ 	slti	$at,$t6,0x9
/*     ea5c:	1420fff9 */ 	bnez	$at,.L0000ea44
/*     ea60:	01c08025 */ 	or	$s0,$t6,$zero
/*     ea64:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*     ea68:	3c018006 */ 	lui	$at,%hi(g_SfxVolume)
/*     ea6c:	a431ddc8 */ 	sh	$s1,%lo(g_SfxVolume)($at)
/*     ea70:	8fb10018 */ 	lw	$s1,0x18($sp)
/*     ea74:	8fb00014 */ 	lw	$s0,0x14($sp)
/*     ea78:	03e00008 */ 	jr	$ra
/*     ea7c:	27bd0020 */ 	addiu	$sp,$sp,0x20
);

GLOBAL_ASM(
glabel func0000ea80
/*     ea80:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*     ea84:	afb10018 */ 	sw	$s1,0x18($sp)
/*     ea88:	3091ffff */ 	andi	$s1,$a0,0xffff
/*     ea8c:	2a215001 */ 	slti	$at,$s1,0x5001
/*     ea90:	afbf001c */ 	sw	$ra,0x1c($sp)
/*     ea94:	afb00014 */ 	sw	$s0,0x14($sp)
/*     ea98:	14200002 */ 	bnez	$at,.L0000eaa4
/*     ea9c:	afa40020 */ 	sw	$a0,0x20($sp)
/*     eaa0:	24115000 */ 	addiu	$s1,$zero,0x5000
.L0000eaa4:
/*     eaa4:	00008025 */ 	or	$s0,$zero,$zero
.L0000eaa8:
/*     eaa8:	320400ff */ 	andi	$a0,$s0,0xff
/*     eaac:	0c00cfd1 */ 	jal	func00033f44
/*     eab0:	3225ffff */ 	andi	$a1,$s1,0xffff
/*     eab4:	26100001 */ 	addiu	$s0,$s0,0x1
/*     eab8:	320e00ff */ 	andi	$t6,$s0,0xff
/*     eabc:	29c10009 */ 	slti	$at,$t6,0x9
/*     eac0:	1420fff9 */ 	bnez	$at,.L0000eaa8
/*     eac4:	01c08025 */ 	or	$s0,$t6,$zero
/*     eac8:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*     eacc:	8fb00014 */ 	lw	$s0,0x14($sp)
/*     ead0:	8fb10018 */ 	lw	$s1,0x18($sp)
/*     ead4:	03e00008 */ 	jr	$ra
/*     ead8:	27bd0020 */ 	addiu	$sp,$sp,0x20
);

GLOBAL_ASM(
glabel func0000eadc
/*     eadc:	3c028009 */ 	lui	$v0,%hi(var80094eb0)
/*     eae0:	24424eb0 */ 	addiu	$v0,$v0,%lo(var80094eb0)
/*     eae4:	944e0000 */ 	lhu	$t6,0x0($v0)
/*     eae8:	2403ffff */ 	addiu	$v1,$zero,-1
/*     eaec:	ac400004 */ 	sw	$zero,0x4($v0)
/*     eaf0:	31cff800 */ 	andi	$t7,$t6,0xf800
/*     eaf4:	a44f0000 */ 	sh	$t7,0x0($v0)
/*     eaf8:	90580000 */ 	lbu	$t8,0x0($v0)
/*     eafc:	ac400008 */ 	sw	$zero,0x8($v0)
/*     eb00:	ac43000c */ 	sw	$v1,0xc($v0)
/*     eb04:	3308ffe7 */ 	andi	$t0,$t8,0xffe7
/*     eb08:	310a009f */ 	andi	$t2,$t0,0x9f
/*     eb0c:	a0480000 */ 	sb	$t0,0x0($v0)
/*     eb10:	a04a0000 */ 	sb	$t2,0x0($v0)
/*     eb14:	314b007f */ 	andi	$t3,$t2,0x7f
/*     eb18:	a04b0000 */ 	sb	$t3,0x0($v0)
/*     eb1c:	ac430010 */ 	sw	$v1,0x10($v0)
/*     eb20:	ac430014 */ 	sw	$v1,0x14($v0)
/*     eb24:	03e00008 */ 	jr	$ra
/*     eb28:	ac430018 */ 	sw	$v1,0x18($v0)
);

GLOBAL_ASM(
glabel func0000eb2c
/*     eb2c:	27bdfe90 */ 	addiu	$sp,$sp,-368
/*     eb30:	afb20028 */ 	sw	$s2,0x28($sp)
/*     eb34:	03a09025 */ 	or	$s2,$sp,$zero
/*     eb38:	afb10024 */ 	sw	$s1,0x24($sp)
/*     eb3c:	afb00020 */ 	sw	$s0,0x20($sp)
/*     eb40:	2652006b */ 	addiu	$s2,$s2,0x6b
/*     eb44:	3c118009 */ 	lui	$s1,%hi(var80094ea4)
/*     eb48:	364e000f */ 	ori	$t6,$s2,0xf
/*     eb4c:	3c100081 */ 	lui	$s0,0x81
/*     eb50:	26314ea4 */ 	addiu	$s1,$s1,%lo(var80094ea4)
/*     eb54:	afbf0034 */ 	sw	$ra,0x34($sp)
/*     eb58:	2610a250 */ 	addiu	$s0,$s0,-23984
/*     eb5c:	39c4000f */ 	xori	$a0,$t6,0xf
/*     eb60:	afb40030 */ 	sw	$s4,0x30($sp)
/*     eb64:	afb3002c */ 	sw	$s3,0x2c($sp)
/*     eb68:	ae200000 */ 	sw	$zero,0x0($s1)
/*     eb6c:	00809025 */ 	or	$s2,$a0,$zero
/*     eb70:	02002825 */ 	or	$a1,$s0,$zero
/*     eb74:	0c003504 */ 	jal	func0000d410
/*     eb78:	24060100 */ 	addiu	$a2,$zero,0x100
/*     eb7c:	8e580004 */ 	lw	$t8,0x4($s2)
/*     eb80:	02402025 */ 	or	$a0,$s2,$zero
/*     eb84:	24060100 */ 	addiu	$a2,$zero,0x100
/*     eb88:	0c003504 */ 	jal	func0000d410
/*     eb8c:	02182821 */ 	addu	$a1,$s0,$t8
/*     eb90:	8e59000c */ 	lw	$t9,0xc($s2)
/*     eb94:	02402025 */ 	or	$a0,$s2,$zero
/*     eb98:	24060100 */ 	addiu	$a2,$zero,0x100
/*     eb9c:	0219a021 */ 	addu	$s4,$s0,$t9
/*     eba0:	0c003504 */ 	jal	func0000d410
/*     eba4:	02802825 */ 	or	$a1,$s4,$zero
/*     eba8:	864a000e */ 	lh	$t2,0xe($s2)
/*     ebac:	3c098009 */ 	lui	$t1,%hi(var80094ea0)
/*     ebb0:	3c018009 */ 	lui	$at,%hi(var80094ea0)
/*     ebb4:	254b0001 */ 	addiu	$t3,$t2,0x1
/*     ebb8:	25294ea0 */ 	addiu	$t1,$t1,%lo(var80094ea0)
/*     ebbc:	ac2b4ea0 */ 	sw	$t3,%lo(var80094ea0)($at)
/*     ebc0:	8d330000 */ 	lw	$s3,0x0($t1)
/*     ebc4:	3c068009 */ 	lui	$a2,%hi(var800951f0)
/*     ebc8:	24c651f0 */ 	addiu	$a2,$a2,%lo(var800951f0)
/*     ebcc:	00136080 */ 	sll	$t4,$s3,0x2
/*     ebd0:	01809825 */ 	or	$s3,$t4,$zero
/*     ebd4:	26730023 */ 	addiu	$s3,$s3,0x23
/*     ebd8:	366d000f */ 	ori	$t5,$s3,0xf
/*     ebdc:	39b3000f */ 	xori	$s3,$t5,0xf
/*     ebe0:	afb30010 */ 	sw	$s3,0x10($sp)
/*     ebe4:	00002025 */ 	or	$a0,$zero,$zero
/*     ebe8:	00002825 */ 	or	$a1,$zero,$zero
/*     ebec:	0c00bec5 */ 	jal	func0002fb14
/*     ebf0:	24070001 */ 	addiu	$a3,$zero,0x1
/*     ebf4:	ae220000 */ 	sw	$v0,0x0($s1)
/*     ebf8:	00402025 */ 	or	$a0,$v0,$zero
/*     ebfc:	02802825 */ 	or	$a1,$s4,$zero
/*     ec00:	0c003504 */ 	jal	func0000d410
/*     ec04:	02603025 */ 	or	$a2,$s3,$zero
/*     ec08:	3c098009 */ 	lui	$t1,%hi(var80094ea0)
/*     ec0c:	8e2f0000 */ 	lw	$t7,0x0($s1)
/*     ec10:	25294ea0 */ 	addiu	$t1,$t1,%lo(var80094ea0)
/*     ec14:	8d280000 */ 	lw	$t0,0x0($t1)
/*     ec18:	25f80010 */ 	addiu	$t8,$t7,0x10
/*     ec1c:	ae380000 */ 	sw	$t8,0x0($s1)
/*     ec20:	1900000e */ 	blez	$t0,.L0000ec5c
/*     ec24:	00001825 */ 	or	$v1,$zero,$zero
/*     ec28:	00002025 */ 	or	$a0,$zero,$zero
/*     ec2c:	8e390000 */ 	lw	$t9,0x0($s1)
.L0000ec30:
/*     ec30:	24630001 */ 	addiu	$v1,$v1,0x1
/*     ec34:	03241021 */ 	addu	$v0,$t9,$a0
/*     ec38:	8c4a0000 */ 	lw	$t2,0x0($v0)
/*     ec3c:	24840004 */ 	addiu	$a0,$a0,0x4
/*     ec40:	01505821 */ 	addu	$t3,$t2,$s0
/*     ec44:	ac4b0000 */ 	sw	$t3,0x0($v0)
/*     ec48:	8d280000 */ 	lw	$t0,0x0($t1)
/*     ec4c:	0068082a */ 	slt	$at,$v1,$t0
/*     ec50:	5420fff7 */ 	bnezl	$at,.L0000ec30
/*     ec54:	8e390000 */ 	lw	$t9,0x0($s1)
/*     ec58:	00001825 */ 	or	$v1,$zero,$zero
.L0000ec5c:
/*     ec5c:	3c068009 */ 	lui	$a2,%hi(var800951f0)
/*     ec60:	24c651f0 */ 	addiu	$a2,$a2,%lo(var800951f0)
/*     ec64:	00002025 */ 	or	$a0,$zero,$zero
/*     ec68:	00002825 */ 	or	$a1,$zero,$zero
/*     ec6c:	24070002 */ 	addiu	$a3,$zero,0x2
/*     ec70:	afa80010 */ 	sw	$t0,0x10($sp)
/*     ec74:	0c00bec5 */ 	jal	func0002fb14
/*     ec78:	afa3016c */ 	sw	$v1,0x16c($sp)
/*     ec7c:	3c098009 */ 	lui	$t1,%hi(var80094ea0)
/*     ec80:	25294ea0 */ 	addiu	$t1,$t1,%lo(var80094ea0)
/*     ec84:	8d2c0000 */ 	lw	$t4,0x0($t1)
/*     ec88:	3c058009 */ 	lui	$a1,%hi(var80095210)
/*     ec8c:	24a55210 */ 	addiu	$a1,$a1,%lo(var80095210)
/*     ec90:	aca20000 */ 	sw	$v0,0x0($a1)
/*     ec94:	1180000c */ 	beqz	$t4,.L0000ecc8
/*     ec98:	8fa3016c */ 	lw	$v1,0x16c($sp)
/*     ec9c:	00001025 */ 	or	$v0,$zero,$zero
/*     eca0:	3404ffff */ 	dli	$a0,0xffff
/*     eca4:	8cad0000 */ 	lw	$t5,0x0($a1)
.L0000eca8:
/*     eca8:	24630001 */ 	addiu	$v1,$v1,0x1
/*     ecac:	01a27021 */ 	addu	$t6,$t5,$v0
/*     ecb0:	a5c40000 */ 	sh	$a0,0x0($t6)
/*     ecb4:	8d2f0000 */ 	lw	$t7,0x0($t1)
/*     ecb8:	24420002 */ 	addiu	$v0,$v0,0x2
/*     ecbc:	006f082b */ 	sltu	$at,$v1,$t7
/*     ecc0:	5420fff9 */ 	bnezl	$at,.L0000eca8
/*     ecc4:	8cad0000 */ 	lw	$t5,0x0($a1)
.L0000ecc8:
/*     ecc8:	3c188009 */ 	lui	$t8,%hi(var80095210)
/*     eccc:	27025210 */ 	addiu	$v0,$t8,%lo(var80095210)
/*     ecd0:	3c058009 */ 	lui	$a1,%hi(var8009523c+0x1)
/*     ecd4:	24a5523d */ 	addiu	$a1,$a1,%lo(var8009523c+0x1)
/*     ecd8:	00401825 */ 	or	$v1,$v0,$zero
/*     ecdc:	24040001 */ 	addiu	$a0,$zero,0x1
.L0000ece0:
/*     ece0:	24420001 */ 	addiu	$v0,$v0,0x1
/*     ece4:	a4640032 */ 	sh	$a0,0x32($v1)
/*     ece8:	24630002 */ 	addiu	$v1,$v1,0x2
/*     ecec:	1445fffc */ 	bne	$v0,$a1,.L0000ece0
/*     ecf0:	a0400003 */ 	sb	$zero,0x3($v0)
/*     ecf4:	8fbf0034 */ 	lw	$ra,0x34($sp)
/*     ecf8:	8fb00020 */ 	lw	$s0,0x20($sp)
/*     ecfc:	8fb10024 */ 	lw	$s1,0x24($sp)
/*     ed00:	8fb20028 */ 	lw	$s2,0x28($sp)
/*     ed04:	8fb3002c */ 	lw	$s3,0x2c($sp)
/*     ed08:	8fb40030 */ 	lw	$s4,0x30($sp)
/*     ed0c:	03e00008 */ 	jr	$ra
/*     ed10:	27bd0170 */ 	addiu	$sp,$sp,0x170
);

GLOBAL_ASM(
glabel func0000ed14
/*     ed14:	3c038009 */ 	lui	$v1,%hi(var80095210)
/*     ed18:	3c068009 */ 	lui	$a2,%hi(var80095210)
/*     ed1c:	24c65210 */ 	addiu	$a2,$a2,%lo(var80095210)
/*     ed20:	24635210 */ 	addiu	$v1,$v1,%lo(var80095210)
/*     ed24:	00001025 */ 	or	$v0,$zero,$zero
/*     ed28:	2407002d */ 	addiu	$a3,$zero,0x2d
.L0000ed2c:
/*     ed2c:	906e0004 */ 	lbu	$t6,0x4($v1)
/*     ed30:	00027840 */ 	sll	$t7,$v0,0x1
/*     ed34:	00cf2021 */ 	addu	$a0,$a2,$t7
/*     ed38:	55c00007 */ 	bnezl	$t6,.L0000ed58
/*     ed3c:	24420001 */ 	addiu	$v0,$v0,0x1
/*     ed40:	94850032 */ 	lhu	$a1,0x32($a0)
/*     ed44:	28a17d00 */ 	slti	$at,$a1,0x7d00
/*     ed48:	10200002 */ 	beqz	$at,.L0000ed54
/*     ed4c:	24b80001 */ 	addiu	$t8,$a1,0x1
/*     ed50:	a4980032 */ 	sh	$t8,0x32($a0)
.L0000ed54:
/*     ed54:	24420001 */ 	addiu	$v0,$v0,0x1
.L0000ed58:
/*     ed58:	1447fff4 */ 	bne	$v0,$a3,.L0000ed2c
/*     ed5c:	24630001 */ 	addiu	$v1,$v1,0x1
/*     ed60:	03e00008 */ 	jr	$ra
/*     ed64:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0000ed68
/*     ed68:	27bdff10 */ 	addiu	$sp,$sp,-240
/*     ed6c:	afb20020 */ 	sw	$s2,0x20($sp)
/*     ed70:	afb1001c */ 	sw	$s1,0x1c($sp)
/*     ed74:	03a08825 */ 	or	$s1,$sp,$zero
/*     ed78:	03a09025 */ 	or	$s2,$sp,$zero
/*     ed7c:	3c0e0081 */ 	lui	$t6,0x81
/*     ed80:	265200af */ 	addiu	$s2,$s2,0xaf
/*     ed84:	2631005f */ 	addiu	$s1,$s1,0x5f
/*     ed88:	afb40028 */ 	sw	$s4,0x28($sp)
/*     ed8c:	afb30024 */ 	sw	$s3,0x24($sp)
/*     ed90:	25cea250 */ 	addiu	$t6,$t6,-23984
/*     ed94:	3639000f */ 	ori	$t9,$s1,0xf
/*     ed98:	364f000f */ 	ori	$t7,$s2,0xf
/*     ed9c:	afbf002c */ 	sw	$ra,0x2c($sp)
/*     eda0:	afb00018 */ 	sw	$s0,0x18($sp)
/*     eda4:	afa500f4 */ 	sw	$a1,0xf4($sp)
/*     eda8:	008ea021 */ 	addu	$s4,$a0,$t6
/*     edac:	39f2000f */ 	xori	$s2,$t7,0xf
/*     edb0:	3b31000f */ 	xori	$s1,$t9,0xf
/*     edb4:	24130040 */ 	addiu	$s3,$zero,0x40
/*     edb8:	02402025 */ 	or	$a0,$s2,$zero
.L0000edbc:
/*     edbc:	02802825 */ 	or	$a1,$s4,$zero
/*     edc0:	0c003513 */ 	jal	func0000d44c
/*     edc4:	24060040 */ 	addiu	$a2,$zero,0x40
/*     edc8:	00008025 */ 	or	$s0,$zero,$zero
/*     edcc:	00001825 */ 	or	$v1,$zero,$zero
/*     edd0:	00001025 */ 	or	$v0,$zero,$zero
.L0000edd4:
/*     edd4:	02424821 */ 	addu	$t1,$s2,$v0
/*     edd8:	8d2a0000 */ 	lw	$t2,0x0($t1)
/*     eddc:	24630001 */ 	addiu	$v1,$v1,0x1
/*     ede0:	2c610010 */ 	sltiu	$at,$v1,0x10
/*     ede4:	24420004 */ 	addiu	$v0,$v0,0x4
/*     ede8:	1420fffa */ 	bnez	$at,.L0000edd4
/*     edec:	020a8021 */ 	addu	$s0,$s0,$t2
/*     edf0:	02202025 */ 	or	$a0,$s1,$zero
/*     edf4:	02802825 */ 	or	$a1,$s4,$zero
/*     edf8:	0c003513 */ 	jal	func0000d44c
/*     edfc:	24060040 */ 	addiu	$a2,$zero,0x40
/*     ee00:	00002025 */ 	or	$a0,$zero,$zero
/*     ee04:	00001025 */ 	or	$v0,$zero,$zero
.L0000ee08:
/*     ee08:	02225821 */ 	addu	$t3,$s1,$v0
/*     ee0c:	8d6c0000 */ 	lw	$t4,0x0($t3)
/*     ee10:	24420004 */ 	addiu	$v0,$v0,0x4
/*     ee14:	1453fffc */ 	bne	$v0,$s3,.L0000ee08
/*     ee18:	008c2021 */ 	addu	$a0,$a0,$t4
/*     ee1c:	5604ffe7 */ 	bnel	$s0,$a0,.L0000edbc
/*     ee20:	02402025 */ 	or	$a0,$s2,$zero
/*     ee24:	97ad00f6 */ 	lhu	$t5,0xf6($sp)
/*     ee28:	8e210000 */ 	lw	$at,0x0($s1)
/*     ee2c:	3c038009 */ 	lui	$v1,%hi(var80095210)
/*     ee30:	24635210 */ 	addiu	$v1,$v1,%lo(var80095210)
/*     ee34:	000d7100 */ 	sll	$t6,$t5,0x4
/*     ee38:	006e7821 */ 	addu	$t7,$v1,$t6
/*     ee3c:	ade1008c */ 	sw	$at,0x8c($t7)
/*     ee40:	8e390004 */ 	lw	$t9,0x4($s1)
/*     ee44:	adf90090 */ 	sw	$t9,0x90($t7)
/*     ee48:	8e210008 */ 	lw	$at,0x8($s1)
/*     ee4c:	ade10094 */ 	sw	$at,0x94($t7)
/*     ee50:	8e39000c */ 	lw	$t9,0xc($s1)
/*     ee54:	adf90098 */ 	sw	$t9,0x98($t7)
/*     ee58:	97a800f6 */ 	lhu	$t0,0xf6($sp)
/*     ee5c:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*     ee60:	8fb40028 */ 	lw	$s4,0x28($sp)
/*     ee64:	00084900 */ 	sll	$t1,$t0,0x4
/*     ee68:	00691021 */ 	addu	$v0,$v1,$t1
/*     ee6c:	8fb30024 */ 	lw	$s3,0x24($sp)
/*     ee70:	8fb20020 */ 	lw	$s2,0x20($sp)
/*     ee74:	8fb1001c */ 	lw	$s1,0x1c($sp)
/*     ee78:	8fb00018 */ 	lw	$s0,0x18($sp)
/*     ee7c:	27bd00f0 */ 	addiu	$sp,$sp,0xf0
/*     ee80:	03e00008 */ 	jr	$ra
/*     ee84:	2442008c */ 	addiu	$v0,$v0,0x8c
);

GLOBAL_ASM(
glabel func0000ee88
/*     ee88:	27bdff10 */ 	addiu	$sp,$sp,-240
/*     ee8c:	afb20020 */ 	sw	$s2,0x20($sp)
/*     ee90:	afb1001c */ 	sw	$s1,0x1c($sp)
/*     ee94:	03a08825 */ 	or	$s1,$sp,$zero
/*     ee98:	03a09025 */ 	or	$s2,$sp,$zero
/*     ee9c:	3c0e0081 */ 	lui	$t6,0x81
/*     eea0:	265200af */ 	addiu	$s2,$s2,0xaf
/*     eea4:	2631005f */ 	addiu	$s1,$s1,0x5f
/*     eea8:	afb40028 */ 	sw	$s4,0x28($sp)
/*     eeac:	afb30024 */ 	sw	$s3,0x24($sp)
/*     eeb0:	25cea250 */ 	addiu	$t6,$t6,-23984
/*     eeb4:	3639000f */ 	ori	$t9,$s1,0xf
/*     eeb8:	364f000f */ 	ori	$t7,$s2,0xf
/*     eebc:	afbf002c */ 	sw	$ra,0x2c($sp)
/*     eec0:	afb00018 */ 	sw	$s0,0x18($sp)
/*     eec4:	afa500f4 */ 	sw	$a1,0xf4($sp)
/*     eec8:	008ea021 */ 	addu	$s4,$a0,$t6
/*     eecc:	39f2000f */ 	xori	$s2,$t7,0xf
/*     eed0:	3b31000f */ 	xori	$s1,$t9,0xf
/*     eed4:	24130040 */ 	addiu	$s3,$zero,0x40
/*     eed8:	02402025 */ 	or	$a0,$s2,$zero
.L0000eedc:
/*     eedc:	02802825 */ 	or	$a1,$s4,$zero
/*     eee0:	0c003513 */ 	jal	func0000d44c
/*     eee4:	24060040 */ 	addiu	$a2,$zero,0x40
/*     eee8:	00008025 */ 	or	$s0,$zero,$zero
/*     eeec:	00001825 */ 	or	$v1,$zero,$zero
/*     eef0:	00001025 */ 	or	$v0,$zero,$zero
.L0000eef4:
/*     eef4:	02424821 */ 	addu	$t1,$s2,$v0
/*     eef8:	8d2a0000 */ 	lw	$t2,0x0($t1)
/*     eefc:	24630001 */ 	addiu	$v1,$v1,0x1
/*     ef00:	2c610010 */ 	sltiu	$at,$v1,0x10
/*     ef04:	24420004 */ 	addiu	$v0,$v0,0x4
/*     ef08:	1420fffa */ 	bnez	$at,.L0000eef4
/*     ef0c:	020a8021 */ 	addu	$s0,$s0,$t2
/*     ef10:	02202025 */ 	or	$a0,$s1,$zero
/*     ef14:	02802825 */ 	or	$a1,$s4,$zero
/*     ef18:	0c003513 */ 	jal	func0000d44c
/*     ef1c:	24060040 */ 	addiu	$a2,$zero,0x40
/*     ef20:	00002025 */ 	or	$a0,$zero,$zero
/*     ef24:	00001025 */ 	or	$v0,$zero,$zero
.L0000ef28:
/*     ef28:	02225821 */ 	addu	$t3,$s1,$v0
/*     ef2c:	8d6c0000 */ 	lw	$t4,0x0($t3)
/*     ef30:	24420004 */ 	addiu	$v0,$v0,0x4
/*     ef34:	1453fffc */ 	bne	$v0,$s3,.L0000ef28
/*     ef38:	008c2021 */ 	addu	$a0,$a0,$t4
/*     ef3c:	5604ffe7 */ 	bnel	$s0,$a0,.L0000eedc
/*     ef40:	02402025 */ 	or	$a0,$s2,$zero
/*     ef44:	97a300f6 */ 	lhu	$v1,0xf6($sp)
/*     ef48:	8a210000 */ 	lwl	$at,0x0($s1)
/*     ef4c:	9a210003 */ 	lwr	$at,0x3($s1)
/*     ef50:	00036880 */ 	sll	$t5,$v1,0x2
/*     ef54:	3c048009 */ 	lui	$a0,%hi(var80095210)
/*     ef58:	01a36823 */ 	subu	$t5,$t5,$v1
/*     ef5c:	24845210 */ 	addiu	$a0,$a0,%lo(var80095210)
/*     ef60:	000d6840 */ 	sll	$t5,$t5,0x1
/*     ef64:	008d7021 */ 	addu	$t6,$a0,$t5
/*     ef68:	a9c1035c */ 	swl	$at,0x35c($t6)
/*     ef6c:	b9c1035f */ 	swr	$at,0x35f($t6)
/*     ef70:	92210004 */ 	lbu	$at,0x4($s1)
/*     ef74:	008d1021 */ 	addu	$v0,$a0,$t5
/*     ef78:	2442035c */ 	addiu	$v0,$v0,0x35c
/*     ef7c:	a1c10360 */ 	sb	$at,0x360($t6)
/*     ef80:	92380005 */ 	lbu	$t8,0x5($s1)
/*     ef84:	a1d80361 */ 	sb	$t8,0x361($t6)
/*     ef88:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*     ef8c:	8fb40028 */ 	lw	$s4,0x28($sp)
/*     ef90:	8fb30024 */ 	lw	$s3,0x24($sp)
/*     ef94:	8fb20020 */ 	lw	$s2,0x20($sp)
/*     ef98:	8fb1001c */ 	lw	$s1,0x1c($sp)
/*     ef9c:	8fb00018 */ 	lw	$s0,0x18($sp)
/*     efa0:	03e00008 */ 	jr	$ra
/*     efa4:	27bd00f0 */ 	addiu	$sp,$sp,0xf0
);

GLOBAL_ASM(
glabel func0000efa8
/*     efa8:	27bdfd10 */ 	addiu	$sp,$sp,-752
/*     efac:	afb20020 */ 	sw	$s2,0x20($sp)
/*     efb0:	afb1001c */ 	sw	$s1,0x1c($sp)
/*     efb4:	03a08825 */ 	or	$s1,$sp,$zero
/*     efb8:	03a09025 */ 	or	$s2,$sp,$zero
/*     efbc:	3c0e0081 */ 	lui	$t6,0x81
/*     efc0:	265201af */ 	addiu	$s2,$s2,0x1af
/*     efc4:	2631005f */ 	addiu	$s1,$s1,0x5f
/*     efc8:	afb40028 */ 	sw	$s4,0x28($sp)
/*     efcc:	afb30024 */ 	sw	$s3,0x24($sp)
/*     efd0:	25cea250 */ 	addiu	$t6,$t6,-23984
/*     efd4:	3639000f */ 	ori	$t9,$s1,0xf
/*     efd8:	364f000f */ 	ori	$t7,$s2,0xf
/*     efdc:	afbf002c */ 	sw	$ra,0x2c($sp)
/*     efe0:	afb00018 */ 	sw	$s0,0x18($sp)
/*     efe4:	afa502f4 */ 	sw	$a1,0x2f4($sp)
/*     efe8:	008ea021 */ 	addu	$s4,$a0,$t6
/*     efec:	39f2000f */ 	xori	$s2,$t7,0xf
/*     eff0:	3b31000f */ 	xori	$s1,$t9,0xf
/*     eff4:	24130140 */ 	addiu	$s3,$zero,0x140
/*     eff8:	02402025 */ 	or	$a0,$s2,$zero
.L0000effc:
/*     effc:	02802825 */ 	or	$a1,$s4,$zero
/*     f000:	0c003513 */ 	jal	func0000d44c
/*     f004:	24060140 */ 	addiu	$a2,$zero,0x140
/*     f008:	00008025 */ 	or	$s0,$zero,$zero
/*     f00c:	00001825 */ 	or	$v1,$zero,$zero
/*     f010:	00001025 */ 	or	$v0,$zero,$zero
.L0000f014:
/*     f014:	02424821 */ 	addu	$t1,$s2,$v0
/*     f018:	8d2a0000 */ 	lw	$t2,0x0($t1)
/*     f01c:	24630001 */ 	addiu	$v1,$v1,0x1
/*     f020:	2c610050 */ 	sltiu	$at,$v1,0x50
/*     f024:	24420004 */ 	addiu	$v0,$v0,0x4
/*     f028:	1420fffa */ 	bnez	$at,.L0000f014
/*     f02c:	020a8021 */ 	addu	$s0,$s0,$t2
/*     f030:	02202025 */ 	or	$a0,$s1,$zero
/*     f034:	02802825 */ 	or	$a1,$s4,$zero
/*     f038:	0c003513 */ 	jal	func0000d44c
/*     f03c:	24060140 */ 	addiu	$a2,$zero,0x140
/*     f040:	00002025 */ 	or	$a0,$zero,$zero
/*     f044:	00001025 */ 	or	$v0,$zero,$zero
.L0000f048:
/*     f048:	02225821 */ 	addu	$t3,$s1,$v0
/*     f04c:	8d6c0000 */ 	lw	$t4,0x0($t3)
/*     f050:	24420004 */ 	addiu	$v0,$v0,0x4
/*     f054:	1453fffc */ 	bne	$v0,$s3,.L0000f048
/*     f058:	008c2021 */ 	addu	$a0,$a0,$t4
/*     f05c:	5604ffe7 */ 	bnel	$s0,$a0,.L0000effc
/*     f060:	02402025 */ 	or	$a0,$s2,$zero
/*     f064:	97a302f6 */ 	lhu	$v1,0x2f6($sp)
/*     f068:	3c048009 */ 	lui	$a0,%hi(var80095210)
/*     f06c:	24845210 */ 	addiu	$a0,$a0,%lo(var80095210)
/*     f070:	00036940 */ 	sll	$t5,$v1,0x5
/*     f074:	01a36821 */ 	addu	$t5,$t5,$v1
/*     f078:	000d18c0 */ 	sll	$v1,$t5,0x3
/*     f07c:	00837021 */ 	addu	$t6,$a0,$v1
/*     f080:	0220c825 */ 	or	$t9,$s1,$zero
/*     f084:	26380108 */ 	addiu	$t8,$s1,0x108
.L0000f088:
/*     f088:	8f210000 */ 	lw	$at,0x0($t9)
/*     f08c:	2739000c */ 	addiu	$t9,$t9,0xc
/*     f090:	25ce000c */ 	addiu	$t6,$t6,0xc
/*     f094:	adc107e4 */ 	sw	$at,0x7e4($t6)
/*     f098:	8f21fff8 */ 	lw	$at,-0x8($t9)
/*     f09c:	adc107e8 */ 	sw	$at,0x7e8($t6)
/*     f0a0:	8f21fffc */ 	lw	$at,-0x4($t9)
/*     f0a4:	1738fff8 */ 	bne	$t9,$t8,.L0000f088
/*     f0a8:	adc107ec */ 	sw	$at,0x7ec($t6)
/*     f0ac:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*     f0b0:	00831021 */ 	addu	$v0,$a0,$v1
/*     f0b4:	8fb00018 */ 	lw	$s0,0x18($sp)
/*     f0b8:	8fb1001c */ 	lw	$s1,0x1c($sp)
/*     f0bc:	8fb20020 */ 	lw	$s2,0x20($sp)
/*     f0c0:	8fb30024 */ 	lw	$s3,0x24($sp)
/*     f0c4:	8fb40028 */ 	lw	$s4,0x28($sp)
/*     f0c8:	27bd02f0 */ 	addiu	$sp,$sp,0x2f0
/*     f0cc:	03e00008 */ 	jr	$ra
/*     f0d0:	244207f0 */ 	addiu	$v0,$v0,0x7f0
);

GLOBAL_ASM(
glabel func0000f0d4
/*     f0d4:	27bdff10 */ 	addiu	$sp,$sp,-240
/*     f0d8:	afb40028 */ 	sw	$s4,0x28($sp)
/*     f0dc:	0080a025 */ 	or	$s4,$a0,$zero
/*     f0e0:	afbf002c */ 	sw	$ra,0x2c($sp)
/*     f0e4:	afb30024 */ 	sw	$s3,0x24($sp)
/*     f0e8:	afb20020 */ 	sw	$s2,0x20($sp)
/*     f0ec:	afb1001c */ 	sw	$s1,0x1c($sp)
/*     f0f0:	afb00018 */ 	sw	$s0,0x18($sp)
/*     f0f4:	14800003 */ 	bnez	$a0,.L0000f104
/*     f0f8:	afa500f4 */ 	sw	$a1,0xf4($sp)
/*     f0fc:	10000042 */ 	beqz	$zero,.L0000f208
/*     f100:	00001025 */ 	or	$v0,$zero,$zero
.L0000f104:
/*     f104:	03a09025 */ 	or	$s2,$sp,$zero
/*     f108:	03a08825 */ 	or	$s1,$sp,$zero
/*     f10c:	3c0e0081 */ 	lui	$t6,0x81
/*     f110:	2631005f */ 	addiu	$s1,$s1,0x5f
/*     f114:	265200af */ 	addiu	$s2,$s2,0xaf
/*     f118:	25cea250 */ 	addiu	$t6,$t6,-23984
/*     f11c:	364f000f */ 	ori	$t7,$s2,0xf
/*     f120:	3639000f */ 	ori	$t9,$s1,0xf
/*     f124:	028ea021 */ 	addu	$s4,$s4,$t6
/*     f128:	3b31000f */ 	xori	$s1,$t9,0xf
/*     f12c:	39f2000f */ 	xori	$s2,$t7,0xf
/*     f130:	24130040 */ 	addiu	$s3,$zero,0x40
/*     f134:	02402025 */ 	or	$a0,$s2,$zero
.L0000f138:
/*     f138:	02802825 */ 	or	$a1,$s4,$zero
/*     f13c:	0c003513 */ 	jal	func0000d44c
/*     f140:	24060040 */ 	addiu	$a2,$zero,0x40
/*     f144:	00008025 */ 	or	$s0,$zero,$zero
/*     f148:	00001825 */ 	or	$v1,$zero,$zero
/*     f14c:	00001025 */ 	or	$v0,$zero,$zero
.L0000f150:
/*     f150:	02424821 */ 	addu	$t1,$s2,$v0
/*     f154:	8d2a0000 */ 	lw	$t2,0x0($t1)
/*     f158:	24630001 */ 	addiu	$v1,$v1,0x1
/*     f15c:	2c610010 */ 	sltiu	$at,$v1,0x10
/*     f160:	24420004 */ 	addiu	$v0,$v0,0x4
/*     f164:	1420fffa */ 	bnez	$at,.L0000f150
/*     f168:	020a8021 */ 	addu	$s0,$s0,$t2
/*     f16c:	02202025 */ 	or	$a0,$s1,$zero
/*     f170:	02802825 */ 	or	$a1,$s4,$zero
/*     f174:	0c003513 */ 	jal	func0000d44c
/*     f178:	24060040 */ 	addiu	$a2,$zero,0x40
/*     f17c:	00002025 */ 	or	$a0,$zero,$zero
/*     f180:	00001025 */ 	or	$v0,$zero,$zero
.L0000f184:
/*     f184:	02225821 */ 	addu	$t3,$s1,$v0
/*     f188:	8d6c0000 */ 	lw	$t4,0x0($t3)
/*     f18c:	24420004 */ 	addiu	$v0,$v0,0x4
/*     f190:	1453fffc */ 	bne	$v0,$s3,.L0000f184
/*     f194:	008c2021 */ 	addu	$a0,$a0,$t4
/*     f198:	5604ffe7 */ 	bnel	$s0,$a0,.L0000f138
/*     f19c:	02402025 */ 	or	$a0,$s2,$zero
/*     f1a0:	97a300f6 */ 	lhu	$v1,0xf6($sp)
/*     f1a4:	3c048009 */ 	lui	$a0,%hi(var80095210)
/*     f1a8:	24845210 */ 	addiu	$a0,$a0,%lo(var80095210)
/*     f1ac:	00036880 */ 	sll	$t5,$v1,0x2
/*     f1b0:	01a36823 */ 	subu	$t5,$t5,$v1
/*     f1b4:	000d6880 */ 	sll	$t5,$t5,0x2
/*     f1b8:	01a36823 */ 	subu	$t5,$t5,$v1
/*     f1bc:	000d1880 */ 	sll	$v1,$t5,0x2
/*     f1c0:	00837021 */ 	addu	$t6,$a0,$v1
/*     f1c4:	0220c825 */ 	or	$t9,$s1,$zero
/*     f1c8:	26380024 */ 	addiu	$t8,$s1,0x24
.L0000f1cc:
/*     f1cc:	8f210000 */ 	lw	$at,0x0($t9)
/*     f1d0:	2739000c */ 	addiu	$t9,$t9,0xc
/*     f1d4:	25ce000c */ 	addiu	$t6,$t6,0xc
/*     f1d8:	adc1364c */ 	sw	$at,0x364c($t6)
/*     f1dc:	8f21fff8 */ 	lw	$at,-0x8($t9)
/*     f1e0:	adc13650 */ 	sw	$at,0x3650($t6)
/*     f1e4:	8f21fffc */ 	lw	$at,-0x4($t9)
/*     f1e8:	1738fff8 */ 	bne	$t9,$t8,.L0000f1cc
/*     f1ec:	adc13654 */ 	sw	$at,0x3654($t6)
/*     f1f0:	8f210000 */ 	lw	$at,0x0($t9)
/*     f1f4:	00831021 */ 	addu	$v0,$a0,$v1
/*     f1f8:	24423658 */ 	addiu	$v0,$v0,0x3658
/*     f1fc:	adc13658 */ 	sw	$at,0x3658($t6)
/*     f200:	8f380004 */ 	lw	$t8,0x4($t9)
/*     f204:	add8365c */ 	sw	$t8,0x365c($t6)
.L0000f208:
/*     f208:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*     f20c:	8fb00018 */ 	lw	$s0,0x18($sp)
/*     f210:	8fb1001c */ 	lw	$s1,0x1c($sp)
/*     f214:	8fb20020 */ 	lw	$s2,0x20($sp)
/*     f218:	8fb30024 */ 	lw	$s3,0x24($sp)
/*     f21c:	8fb40028 */ 	lw	$s4,0x28($sp)
/*     f220:	03e00008 */ 	jr	$ra
/*     f224:	27bd00f0 */ 	addiu	$sp,$sp,0xf0
);

GLOBAL_ASM(
glabel func0000f228
/*     f228:	27bdff08 */ 	addiu	$sp,$sp,-248
/*     f22c:	afb20020 */ 	sw	$s2,0x20($sp)
/*     f230:	afb1001c */ 	sw	$s1,0x1c($sp)
/*     f234:	03a08825 */ 	or	$s1,$sp,$zero
/*     f238:	03a09025 */ 	or	$s2,$sp,$zero
/*     f23c:	3c0e0081 */ 	lui	$t6,0x81
/*     f240:	265200b7 */ 	addiu	$s2,$s2,0xb7
/*     f244:	26310067 */ 	addiu	$s1,$s1,0x67
/*     f248:	afb40028 */ 	sw	$s4,0x28($sp)
/*     f24c:	afb30024 */ 	sw	$s3,0x24($sp)
/*     f250:	25cea250 */ 	addiu	$t6,$t6,-23984
/*     f254:	3639000f */ 	ori	$t9,$s1,0xf
/*     f258:	364f000f */ 	ori	$t7,$s2,0xf
/*     f25c:	afbf002c */ 	sw	$ra,0x2c($sp)
/*     f260:	afb00018 */ 	sw	$s0,0x18($sp)
/*     f264:	afa500fc */ 	sw	$a1,0xfc($sp)
/*     f268:	008ea021 */ 	addu	$s4,$a0,$t6
/*     f26c:	39f2000f */ 	xori	$s2,$t7,0xf
/*     f270:	3b31000f */ 	xori	$s1,$t9,0xf
/*     f274:	24130040 */ 	addiu	$s3,$zero,0x40
/*     f278:	02402025 */ 	or	$a0,$s2,$zero
.L0000f27c:
/*     f27c:	02802825 */ 	or	$a1,$s4,$zero
/*     f280:	0c003513 */ 	jal	func0000d44c
/*     f284:	24060040 */ 	addiu	$a2,$zero,0x40
/*     f288:	00008025 */ 	or	$s0,$zero,$zero
/*     f28c:	00001825 */ 	or	$v1,$zero,$zero
/*     f290:	00001025 */ 	or	$v0,$zero,$zero
.L0000f294:
/*     f294:	02424821 */ 	addu	$t1,$s2,$v0
/*     f298:	8d2a0000 */ 	lw	$t2,0x0($t1)
/*     f29c:	24630001 */ 	addiu	$v1,$v1,0x1
/*     f2a0:	2c610010 */ 	sltiu	$at,$v1,0x10
/*     f2a4:	24420004 */ 	addiu	$v0,$v0,0x4
/*     f2a8:	1420fffa */ 	bnez	$at,.L0000f294
/*     f2ac:	020a8021 */ 	addu	$s0,$s0,$t2
/*     f2b0:	02202025 */ 	or	$a0,$s1,$zero
/*     f2b4:	02802825 */ 	or	$a1,$s4,$zero
/*     f2b8:	0c003513 */ 	jal	func0000d44c
/*     f2bc:	24060040 */ 	addiu	$a2,$zero,0x40
/*     f2c0:	00002025 */ 	or	$a0,$zero,$zero
/*     f2c4:	00001025 */ 	or	$v0,$zero,$zero
.L0000f2c8:
/*     f2c8:	02225821 */ 	addu	$t3,$s1,$v0
/*     f2cc:	8d6c0000 */ 	lw	$t4,0x0($t3)
/*     f2d0:	24420004 */ 	addiu	$v0,$v0,0x4
/*     f2d4:	1453fffc */ 	bne	$v0,$s3,.L0000f2c8
/*     f2d8:	008c2021 */ 	addu	$a0,$a0,$t4
/*     f2dc:	5604ffe7 */ 	bnel	$s0,$a0,.L0000f27c
/*     f2e0:	02402025 */ 	or	$a0,$s2,$zero
/*     f2e4:	97ad00fe */ 	lhu	$t5,0xfe($sp)
/*     f2e8:	3c0f8009 */ 	lui	$t7,%hi(var80095210)
/*     f2ec:	8e210000 */ 	lw	$at,0x0($s1)
/*     f2f0:	000d7080 */ 	sll	$t6,$t5,0x2
/*     f2f4:	01cd7021 */ 	addu	$t6,$t6,$t5
/*     f2f8:	000e7080 */ 	sll	$t6,$t6,0x2
/*     f2fc:	25ef5210 */ 	addiu	$t7,$t7,%lo(var80095210)
/*     f300:	01cf1021 */ 	addu	$v0,$t6,$t7
/*     f304:	2450046c */ 	addiu	$s0,$v0,0x46c
/*     f308:	ae010000 */ 	sw	$at,0x0($s0)
/*     f30c:	8e390004 */ 	lw	$t9,0x4($s1)
/*     f310:	3c090084 */ 	lui	$t1,0x84
/*     f314:	25299dd0 */ 	addiu	$t1,$t1,-25136
/*     f318:	ae190004 */ 	sw	$t9,0x4($s0)
/*     f31c:	8e210008 */ 	lw	$at,0x8($s1)
/*     f320:	ae010008 */ 	sw	$at,0x8($s0)
/*     f324:	8e39000c */ 	lw	$t9,0xc($s1)
/*     f328:	ae19000c */ 	sw	$t9,0xc($s0)
/*     f32c:	8e210010 */ 	lw	$at,0x10($s1)
/*     f330:	ae010010 */ 	sw	$at,0x10($s0)
/*     f334:	8c48046c */ 	lw	$t0,0x46c($v0)
/*     f338:	904b0474 */ 	lbu	$t3,0x474($v0)
/*     f33c:	01095021 */ 	addu	$t2,$t0,$t1
/*     f340:	15600009 */ 	bnez	$t3,.L0000f368
/*     f344:	ac4a046c */ 	sw	$t2,0x46c($v0)
/*     f348:	8e040010 */ 	lw	$a0,0x10($s0)
/*     f34c:	0c003bea */ 	jal	func0000efa8
/*     f350:	97a500fe */ 	lhu	$a1,0xfe($sp)
/*     f354:	ae020010 */ 	sw	$v0,0x10($s0)
/*     f358:	8e04000c */ 	lw	$a0,0xc($s0)
/*     f35c:	0c003c35 */ 	jal	func0000f0d4
/*     f360:	97a500fe */ 	lhu	$a1,0xfe($sp)
/*     f364:	ae02000c */ 	sw	$v0,0xc($s0)
.L0000f368:
/*     f368:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*     f36c:	02001025 */ 	or	$v0,$s0,$zero
/*     f370:	8fb00018 */ 	lw	$s0,0x18($sp)
/*     f374:	8fb1001c */ 	lw	$s1,0x1c($sp)
/*     f378:	8fb20020 */ 	lw	$s2,0x20($sp)
/*     f37c:	8fb30024 */ 	lw	$s3,0x24($sp)
/*     f380:	8fb40028 */ 	lw	$s4,0x28($sp)
/*     f384:	03e00008 */ 	jr	$ra
/*     f388:	27bd00f8 */ 	addiu	$sp,$sp,0xf8
);

GLOBAL_ASM(
glabel audioSetSoundMode
/*     f38c:	27bdffd0 */ 	addiu	$sp,$sp,-48
/*     f390:	afb1001c */ 	sw	$s1,0x1c($sp)
/*     f394:	3c018006 */ 	lui	$at,%hi(g_SoundMode)
/*     f398:	00808825 */ 	or	$s1,$a0,$zero
/*     f39c:	afbf002c */ 	sw	$ra,0x2c($sp)
/*     f3a0:	afb40028 */ 	sw	$s4,0x28($sp)
/*     f3a4:	afb30024 */ 	sw	$s3,0x24($sp)
/*     f3a8:	afb20020 */ 	sw	$s2,0x20($sp)
/*     f3ac:	afb00018 */ 	sw	$s0,0x18($sp)
/*     f3b0:	1080000a */ 	beqz	$a0,.L0000f3dc
/*     f3b4:	ac24ddcc */ 	sw	$a0,%lo(g_SoundMode)($at)
/*     f3b8:	24140001 */ 	addiu	$s4,$zero,0x1
/*     f3bc:	1094000d */ 	beq	$a0,$s4,.L0000f3f4
/*     f3c0:	24130002 */ 	addiu	$s3,$zero,0x2
/*     f3c4:	10930010 */ 	beq	$a0,$s3,.L0000f408
/*     f3c8:	24120003 */ 	addiu	$s2,$zero,0x3
/*     f3cc:	10920012 */ 	beq	$a0,$s2,.L0000f418
/*     f3d0:	00000000 */ 	sll	$zero,$zero,0x0
/*     f3d4:	10000013 */ 	beqz	$zero,.L0000f424
/*     f3d8:	00002025 */ 	or	$a0,$zero,$zero
.L0000f3dc:
/*     f3dc:	0c00d00c */ 	jal	func00034030
/*     f3e0:	24040001 */ 	addiu	$a0,$zero,0x1
/*     f3e4:	24140001 */ 	addiu	$s4,$zero,0x1
/*     f3e8:	24130002 */ 	addiu	$s3,$zero,0x2
/*     f3ec:	1000000c */ 	beqz	$zero,.L0000f420
/*     f3f0:	24120003 */ 	addiu	$s2,$zero,0x3
.L0000f3f4:
/*     f3f4:	0c00d00c */ 	jal	func00034030
/*     f3f8:	24040002 */ 	addiu	$a0,$zero,0x2
/*     f3fc:	24130002 */ 	addiu	$s3,$zero,0x2
/*     f400:	10000007 */ 	beqz	$zero,.L0000f420
/*     f404:	24120003 */ 	addiu	$s2,$zero,0x3
.L0000f408:
/*     f408:	0c00d00c */ 	jal	func00034030
/*     f40c:	24040003 */ 	addiu	$a0,$zero,0x3
/*     f410:	10000003 */ 	beqz	$zero,.L0000f420
/*     f414:	24120003 */ 	addiu	$s2,$zero,0x3
.L0000f418:
/*     f418:	0c00d00c */ 	jal	func00034030
/*     f41c:	24040004 */ 	addiu	$a0,$zero,0x4
.L0000f420:
/*     f420:	00002025 */ 	or	$a0,$zero,$zero
.L0000f424:
/*     f424:	0c00d041 */ 	jal	func00034104
/*     f428:	24050004 */ 	addiu	$a1,$zero,0x4
/*     f42c:	3c028009 */ 	lui	$v0,%hi(var80094ea8)
/*     f430:	8c424ea8 */ 	lw	$v0,%lo(var80094ea8)($v0)
/*     f434:	02808025 */ 	or	$s0,$s4,$zero
/*     f438:	28410002 */ 	slti	$at,$v0,0x2
/*     f43c:	54200010 */ 	bnezl	$at,.L0000f480
/*     f440:	8fbf002c */ 	lw	$ra,0x2c($sp)
.L0000f444:
/*     f444:	12340005 */ 	beq	$s1,$s4,.L0000f45c
/*     f448:	02002025 */ 	or	$a0,$s0,$zero
/*     f44c:	12330003 */ 	beq	$s1,$s3,.L0000f45c
/*     f450:	00000000 */ 	sll	$zero,$zero,0x0
/*     f454:	56320006 */ 	bnel	$s1,$s2,.L0000f470
/*     f458:	26100001 */ 	addiu	$s0,$s0,0x1
.L0000f45c:
/*     f45c:	0c00d041 */ 	jal	func00034104
/*     f460:	24050004 */ 	addiu	$a1,$zero,0x4
/*     f464:	3c028009 */ 	lui	$v0,%hi(var80094ea8)
/*     f468:	8c424ea8 */ 	lw	$v0,%lo(var80094ea8)($v0)
/*     f46c:	26100001 */ 	addiu	$s0,$s0,0x1
.L0000f470:
/*     f470:	0202082a */ 	slt	$at,$s0,$v0
/*     f474:	1420fff3 */ 	bnez	$at,.L0000f444
/*     f478:	00000000 */ 	sll	$zero,$zero,0x0
/*     f47c:	8fbf002c */ 	lw	$ra,0x2c($sp)
.L0000f480:
/*     f480:	8fb00018 */ 	lw	$s0,0x18($sp)
/*     f484:	8fb1001c */ 	lw	$s1,0x1c($sp)
/*     f488:	8fb20020 */ 	lw	$s2,0x20($sp)
/*     f48c:	8fb30024 */ 	lw	$s3,0x24($sp)
/*     f490:	8fb40028 */ 	lw	$s4,0x28($sp)
/*     f494:	03e00008 */ 	jr	$ra
/*     f498:	27bd0030 */ 	addiu	$sp,$sp,0x30
);

GLOBAL_ASM(
glabel func0000f49c
/*     f49c:	27bdff50 */ 	addiu	$sp,$sp,-176
/*     f4a0:	afb00014 */ 	sw	$s0,0x14($sp)
/*     f4a4:	00048400 */ 	sll	$s0,$a0,0x10
/*     f4a8:	00107403 */ 	sra	$t6,$s0,0x10
/*     f4ac:	afa400b0 */ 	sw	$a0,0xb0($sp)
/*     f4b0:	000e2400 */ 	sll	$a0,$t6,0x10
/*     f4b4:	afbf001c */ 	sw	$ra,0x1c($sp)
/*     f4b8:	00047c03 */ 	sra	$t7,$a0,0x10
/*     f4bc:	01c08025 */ 	or	$s0,$t6,$zero
/*     f4c0:	afb10018 */ 	sw	$s1,0x18($sp)
/*     f4c4:	0c003ee8 */ 	jal	func0000fba0
/*     f4c8:	01e02025 */ 	or	$a0,$t7,$zero
/*     f4cc:	10400003 */ 	beqz	$v0,.L0000f4dc
/*     f4d0:	3c088009 */ 	lui	$t0,%hi(var80095210)
/*     f4d4:	10000064 */ 	beqz	$zero,.L0000f668
/*     f4d8:	00001025 */ 	or	$v0,$zero,$zero
.L0000f4dc:
/*     f4dc:	25085210 */ 	addiu	$t0,$t0,%lo(var80095210)
/*     f4e0:	320a07ff */ 	andi	$t2,$s0,0x7ff
/*     f4e4:	8d060000 */ 	lw	$a2,0x0($t0)
/*     f4e8:	000ac400 */ 	sll	$t8,$t2,0x10
/*     f4ec:	00185403 */ 	sra	$t2,$t8,0x10
/*     f4f0:	000a5840 */ 	sll	$t3,$t2,0x1
/*     f4f4:	00cb6021 */ 	addu	$t4,$a2,$t3
/*     f4f8:	95890000 */ 	lhu	$t1,0x0($t4)
/*     f4fc:	3401ffff */ 	dli	$at,0xffff
/*     f500:	2407ffff */ 	addiu	$a3,$zero,-1
/*     f504:	15210051 */ 	bne	$t1,$at,.L0000f64c
/*     f508:	00002825 */ 	or	$a1,$zero,$zero
/*     f50c:	3c038009 */ 	lui	$v1,%hi(var80095210)
/*     f510:	24635210 */ 	addiu	$v1,$v1,%lo(var80095210)
/*     f514:	00001025 */ 	or	$v0,$zero,$zero
.L0000f518:
/*     f518:	906d0004 */ 	lbu	$t5,0x4($v1)
/*     f51c:	00027040 */ 	sll	$t6,$v0,0x1
/*     f520:	010e7821 */ 	addu	$t7,$t0,$t6
/*     f524:	55a00008 */ 	bnezl	$t5,.L0000f548
/*     f528:	24420001 */ 	addiu	$v0,$v0,0x1
/*     f52c:	95e40032 */ 	lhu	$a0,0x32($t7)
/*     f530:	00a4082b */ 	sltu	$at,$a1,$a0
/*     f534:	50200004 */ 	beqzl	$at,.L0000f548
/*     f538:	24420001 */ 	addiu	$v0,$v0,0x1
/*     f53c:	00802825 */ 	or	$a1,$a0,$zero
/*     f540:	00403825 */ 	or	$a3,$v0,$zero
/*     f544:	24420001 */ 	addiu	$v0,$v0,0x1
.L0000f548:
/*     f548:	2841002d */ 	slti	$at,$v0,0x2d
/*     f54c:	1420fff2 */ 	bnez	$at,.L0000f518
/*     f550:	24630001 */ 	addiu	$v1,$v1,0x1
/*     f554:	3c048009 */ 	lui	$a0,%hi(var80094ea0)
/*     f558:	8c844ea0 */ 	lw	$a0,%lo(var80094ea0)($a0)
/*     f55c:	30e9ffff */ 	andi	$t1,$a3,0xffff
/*     f560:	00c01825 */ 	or	$v1,$a2,$zero
/*     f564:	1080000d */ 	beqz	$a0,.L0000f59c
/*     f568:	00001025 */ 	or	$v0,$zero,$zero
/*     f56c:	30e5ffff */ 	andi	$a1,$a3,0xffff
/*     f570:	3406ffff */ 	dli	$a2,0xffff
.L0000f574:
/*     f574:	94780000 */ 	lhu	$t8,0x0($v1)
/*     f578:	24420001 */ 	addiu	$v0,$v0,0x1
/*     f57c:	54b80005 */ 	bnel	$a1,$t8,.L0000f594
/*     f580:	0044082b */ 	sltu	$at,$v0,$a0
/*     f584:	a4660000 */ 	sh	$a2,0x0($v1)
/*     f588:	3c048009 */ 	lui	$a0,%hi(var80094ea0)
/*     f58c:	8c844ea0 */ 	lw	$a0,%lo(var80094ea0)($a0)
/*     f590:	0044082b */ 	sltu	$at,$v0,$a0
.L0000f594:
/*     f594:	1420fff7 */ 	bnez	$at,.L0000f574
/*     f598:	24630002 */ 	addiu	$v1,$v1,0x2
.L0000f59c:
/*     f59c:	3c0d8009 */ 	lui	$t5,%hi(var80094ea4)
/*     f5a0:	8dad4ea4 */ 	lw	$t5,%lo(var80094ea4)($t5)
/*     f5a4:	03a08025 */ 	or	$s0,$sp,$zero
/*     f5a8:	26100047 */ 	addiu	$s0,$s0,0x47
/*     f5ac:	000a7080 */ 	sll	$t6,$t2,0x2
/*     f5b0:	3619000f */ 	ori	$t9,$s0,0xf
/*     f5b4:	01ae7821 */ 	addu	$t7,$t5,$t6
/*     f5b8:	8de5fffc */ 	lw	$a1,-0x4($t7)
/*     f5bc:	3b24000f */ 	xori	$a0,$t9,0xf
/*     f5c0:	00808025 */ 	or	$s0,$a0,$zero
/*     f5c4:	afab0024 */ 	sw	$t3,0x24($sp)
/*     f5c8:	a7a900aa */ 	sh	$t1,0xaa($sp)
/*     f5cc:	24060040 */ 	addiu	$a2,$zero,0x40
/*     f5d0:	0c003513 */ 	jal	func0000d44c
/*     f5d4:	30f1ffff */ 	andi	$s1,$a3,0xffff
/*     f5d8:	8e040000 */ 	lw	$a0,0x0($s0)
/*     f5dc:	0c003b5a */ 	jal	func0000ed68
/*     f5e0:	3225ffff */ 	andi	$a1,$s1,0xffff
/*     f5e4:	ae020000 */ 	sw	$v0,0x0($s0)
/*     f5e8:	8e040008 */ 	lw	$a0,0x8($s0)
/*     f5ec:	0c003c8a */ 	jal	func0000f228
/*     f5f0:	3225ffff */ 	andi	$a1,$s1,0xffff
/*     f5f4:	ae020008 */ 	sw	$v0,0x8($s0)
/*     f5f8:	8e040004 */ 	lw	$a0,0x4($s0)
/*     f5fc:	0c003ba2 */ 	jal	func0000ee88
/*     f600:	3225ffff */ 	andi	$a1,$s1,0xffff
/*     f604:	8e010000 */ 	lw	$at,0x0($s0)
/*     f608:	3c088009 */ 	lui	$t0,%hi(var80095210)
/*     f60c:	25085210 */ 	addiu	$t0,$t0,%lo(var80095210)
/*     f610:	97a900aa */ 	lhu	$t1,0xaa($sp)
/*     f614:	0011c100 */ 	sll	$t8,$s1,0x4
/*     f618:	ae020004 */ 	sw	$v0,0x4($s0)
/*     f61c:	0118c821 */ 	addu	$t9,$t0,$t8
/*     f620:	af213e14 */ 	sw	$at,0x3e14($t9)
/*     f624:	8e0d0004 */ 	lw	$t5,0x4($s0)
/*     f628:	af2d3e18 */ 	sw	$t5,0x3e18($t9)
/*     f62c:	8e010008 */ 	lw	$at,0x8($s0)
/*     f630:	af213e1c */ 	sw	$at,0x3e1c($t9)
/*     f634:	8e0d000c */ 	lw	$t5,0xc($s0)
/*     f638:	af2d3e20 */ 	sw	$t5,0x3e20($t9)
/*     f63c:	8faf0024 */ 	lw	$t7,0x24($sp)
/*     f640:	8d0e0000 */ 	lw	$t6,0x0($t0)
/*     f644:	01cfc021 */ 	addu	$t8,$t6,$t7
/*     f648:	a7110000 */ 	sh	$s1,0x0($t8)
.L0000f64c:
/*     f64c:	0009c840 */ 	sll	$t9,$t1,0x1
/*     f650:	00097100 */ 	sll	$t6,$t1,0x4
/*     f654:	01196821 */ 	addu	$t5,$t0,$t9
/*     f658:	240c0001 */ 	addiu	$t4,$zero,0x1
/*     f65c:	010e1021 */ 	addu	$v0,$t0,$t6
/*     f660:	a5ac0032 */ 	sh	$t4,0x32($t5)
/*     f664:	24423e14 */ 	addiu	$v0,$v0,0x3e14
.L0000f668:
/*     f668:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*     f66c:	8fb00014 */ 	lw	$s0,0x14($sp)
/*     f670:	8fb10018 */ 	lw	$s1,0x18($sp)
/*     f674:	03e00008 */ 	jr	$ra
/*     f678:	27bd00b0 */ 	addiu	$sp,$sp,0xb0
);

GLOBAL_ASM(
glabel func0000f67c
/*     f67c:	27bdffc0 */ 	addiu	$sp,$sp,-64
/*     f680:	3c198009 */ 	lui	$t9,%hi(var800951f0)
/*     f684:	afbf001c */ 	sw	$ra,0x1c($sp)
/*     f688:	afa40040 */ 	sw	$a0,0x40($sp)
/*     f68c:	240e002c */ 	addiu	$t6,$zero,0x2c
/*     f690:	240f0040 */ 	addiu	$t7,$zero,0x40
/*     f694:	24180010 */ 	addiu	$t8,$zero,0x10
/*     f698:	273951f0 */ 	addiu	$t9,$t9,%lo(var800951f0)
/*     f69c:	afae0020 */ 	sw	$t6,0x20($sp)
/*     f6a0:	afaf0024 */ 	sw	$t7,0x24($sp)
/*     f6a4:	a3b80028 */ 	sb	$t8,0x28($sp)
/*     f6a8:	a3a00029 */ 	sb	$zero,0x29($sp)
/*     f6ac:	afb9002c */ 	sw	$t9,0x2c($sp)
/*     f6b0:	0c00c326 */ 	jal	func00030c98
/*     f6b4:	27a40020 */ 	addiu	$a0,$sp,0x20
/*     f6b8:	3c088009 */ 	lui	$t0,%hi(g_Is4Mb)
/*     f6bc:	91080af0 */ 	lbu	$t0,%lo(g_Is4Mb)($t0)
/*     f6c0:	24010001 */ 	addiu	$at,$zero,0x1
/*     f6c4:	00002025 */ 	or	$a0,$zero,$zero
/*     f6c8:	15010006 */ 	bne	$t0,$at,.L0000f6e4
/*     f6cc:	00002825 */ 	or	$a1,$zero,$zero
/*     f6d0:	3c028009 */ 	lui	$v0,%hi(var8009520c)
/*     f6d4:	2442520c */ 	addiu	$v0,$v0,%lo(var8009520c)
/*     f6d8:	24093800 */ 	addiu	$t1,$zero,0x3800
/*     f6dc:	10000005 */ 	beqz	$zero,.L0000f6f4
/*     f6e0:	ac490000 */ 	sw	$t1,0x0($v0)
.L0000f6e4:
/*     f6e4:	3c028009 */ 	lui	$v0,%hi(var8009520c)
/*     f6e8:	2442520c */ 	addiu	$v0,$v0,%lo(var8009520c)
/*     f6ec:	240a4800 */ 	addiu	$t2,$zero,0x4800
/*     f6f0:	ac4a0000 */ 	sw	$t2,0x0($v0)
.L0000f6f4:
/*     f6f4:	8c4b0000 */ 	lw	$t3,0x0($v0)
/*     f6f8:	3c068009 */ 	lui	$a2,%hi(var800951f0)
/*     f6fc:	24c651f0 */ 	addiu	$a2,$a2,%lo(var800951f0)
/*     f700:	24070001 */ 	addiu	$a3,$zero,0x1
/*     f704:	0c00bec5 */ 	jal	func0002fb14
/*     f708:	afab0010 */ 	sw	$t3,0x10($sp)
/*     f70c:	8fac0040 */ 	lw	$t4,0x40($sp)
/*     f710:	3c068009 */ 	lui	$a2,%hi(var800951f0)
/*     f714:	240d008c */ 	addiu	$t5,$zero,0x8c
/*     f718:	ad8200fc */ 	sw	$v0,0xfc($t4)
/*     f71c:	afad0010 */ 	sw	$t5,0x10($sp)
/*     f720:	24c651f0 */ 	addiu	$a2,$a2,%lo(var800951f0)
/*     f724:	00002025 */ 	or	$a0,$zero,$zero
/*     f728:	00002825 */ 	or	$a1,$zero,$zero
/*     f72c:	0c00bec5 */ 	jal	func0002fb14
/*     f730:	24070001 */ 	addiu	$a3,$zero,0x1
/*     f734:	8fae0040 */ 	lw	$t6,0x40($sp)
/*     f738:	00402025 */ 	or	$a0,$v0,$zero
/*     f73c:	27a50020 */ 	addiu	$a1,$sp,0x20
/*     f740:	0c00d090 */ 	jal	func00034240
/*     f744:	adc200f8 */ 	sw	$v0,0xf8($t6)
/*     f748:	8faf0040 */ 	lw	$t7,0x40($sp)
/*     f74c:	3c058009 */ 	lui	$a1,%hi(var80095204)
/*     f750:	8ca55204 */ 	lw	$a1,%lo(var80095204)($a1)
/*     f754:	0c00dd94 */ 	jal	func00037650
/*     f758:	8de400f8 */ 	lw	$a0,0xf8($t7)
/*     f75c:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*     f760:	27bd0040 */ 	addiu	$sp,$sp,0x40
/*     f764:	03e00008 */ 	jr	$ra
/*     f768:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0000f76c
/*     f76c:	3c0e800a */ 	lui	$t6,%hi(var80099024)
/*     f770:	25ce9024 */ 	addiu	$t6,$t6,%lo(var80099024)
/*     f774:	008e082b */ 	sltu	$at,$a0,$t6
/*     f778:	1420000d */ 	bnez	$at,.L0000f7b0
/*     f77c:	3c0f800a */ 	lui	$t7,%hi(var800992e4)
/*     f780:	25ef92e4 */ 	addiu	$t7,$t7,%lo(var800992e4)
/*     f784:	01e4082b */ 	sltu	$at,$t7,$a0
/*     f788:	14200009 */ 	bnez	$at,.L0000f7b0
/*     f78c:	3c038009 */ 	lui	$v1,%hi(var80095210)
/*     f790:	24635210 */ 	addiu	$v1,$v1,%lo(var80095210)
/*     f794:	0083c023 */ 	subu	$t8,$a0,$v1
/*     f798:	2719c1ec */ 	addiu	$t9,$t8,-15892
/*     f79c:	00194103 */ 	sra	$t0,$t9,0x4
/*     f7a0:	00681021 */ 	addu	$v0,$v1,$t0
/*     f7a4:	90490004 */ 	lbu	$t1,0x4($v0)
/*     f7a8:	252a0001 */ 	addiu	$t2,$t1,0x1
/*     f7ac:	a04a0004 */ 	sb	$t2,0x4($v0)
.L0000f7b0:
/*     f7b0:	03e00008 */ 	jr	$ra
/*     f7b4:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0000f7b8
/*     f7b8:	3c0e800a */ 	lui	$t6,%hi(var80099024)
/*     f7bc:	25ce9024 */ 	addiu	$t6,$t6,%lo(var80099024)
/*     f7c0:	008e082b */ 	sltu	$at,$a0,$t6
/*     f7c4:	1420000d */ 	bnez	$at,.L0000f7fc
/*     f7c8:	3c0f800a */ 	lui	$t7,%hi(var800992e4)
/*     f7cc:	25ef92e4 */ 	addiu	$t7,$t7,%lo(var800992e4)
/*     f7d0:	01e4082b */ 	sltu	$at,$t7,$a0
/*     f7d4:	14200009 */ 	bnez	$at,.L0000f7fc
/*     f7d8:	3c038009 */ 	lui	$v1,%hi(var80095210)
/*     f7dc:	24635210 */ 	addiu	$v1,$v1,%lo(var80095210)
/*     f7e0:	0083c023 */ 	subu	$t8,$a0,$v1
/*     f7e4:	2719c1ec */ 	addiu	$t9,$t8,-15892
/*     f7e8:	00194103 */ 	sra	$t0,$t9,0x4
/*     f7ec:	00681021 */ 	addu	$v0,$v1,$t0
/*     f7f0:	90490004 */ 	lbu	$t1,0x4($v0)
/*     f7f4:	252affff */ 	addiu	$t2,$t1,-1
/*     f7f8:	a04a0004 */ 	sb	$t2,0x4($v0)
.L0000f7fc:
/*     f7fc:	03e00008 */ 	jr	$ra
/*     f800:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0000f804
/*     f804:	3c0e8009 */ 	lui	$t6,%hi(g_Is4Mb)
/*     f808:	91ce0af0 */ 	lbu	$t6,%lo(g_Is4Mb)($t6)
/*     f80c:	27bdff70 */ 	addiu	$sp,$sp,-144
/*     f810:	afb0001c */ 	sw	$s0,0x1c($sp)
/*     f814:	24020001 */ 	addiu	$v0,$zero,0x1
/*     f818:	3c100006 */ 	lui	$s0,0x6
/*     f81c:	3c01800a */ 	lui	$at,%hi(g_Vars+0x4e3)
/*     f820:	afbf0024 */ 	sw	$ra,0x24($sp)
/*     f824:	afb10020 */ 	sw	$s1,0x20($sp)
/*     f828:	3610e400 */ 	ori	$s0,$s0,0xe400
/*     f82c:	144e000d */ 	bne	$v0,$t6,.L0000f864
/*     f830:	a020a4a3 */ 	sb	$zero,%lo(g_Vars+0x4e3)($at)
/*     f834:	3c018009 */ 	lui	$at,%hi(var80094ea8)
/*     f838:	ac224ea8 */ 	sw	$v0,%lo(var80094ea8)($at)
/*     f83c:	3c100006 */ 	lui	$s0,0x6
/*     f840:	3c01fffd */ 	lui	$at,0xfffd
/*     f844:	36104c00 */ 	ori	$s0,$s0,0x4c00
/*     f848:	3421dc00 */ 	ori	$at,$at,0xdc00
/*     f84c:	02018021 */ 	addu	$s0,$s0,$at
/*     f850:	2610d000 */ 	addiu	$s0,$s0,-12288
/*     f854:	3c018006 */ 	lui	$at,%hi(var8005ddd0)
/*     f858:	2610a400 */ 	addiu	$s0,$s0,-23552
/*     f85c:	1000000d */ 	beqz	$zero,.L0000f894
/*     f860:	ac20ddd0 */ 	sw	$zero,%lo(var8005ddd0)($at)
.L0000f864:
/*     f864:	3c018006 */ 	lui	$at,%hi(var8005ddd0)
/*     f868:	ac22ddd0 */ 	sw	$v0,%lo(var8005ddd0)($at)
/*     f86c:	3c018009 */ 	lui	$at,%hi(var80094ea8)
/*     f870:	240f0002 */ 	addiu	$t7,$zero,0x2
/*     f874:	3c057005 */ 	lui	$a1,%hi(var70053b58)
/*     f878:	ac2f4ea8 */ 	sw	$t7,%lo(var80094ea8)($at)
/*     f87c:	24a53b58 */ 	addiu	$a1,$a1,%lo(var70053b58)
/*     f880:	0c004c04 */ 	jal	func00013010
/*     f884:	00402025 */ 	or	$a0,$v0,$zero
/*     f888:	10400002 */ 	beqz	$v0,.L0000f894
/*     f88c:	3c018006 */ 	lui	$at,%hi(var8005ddd0)
/*     f890:	ac20ddd0 */ 	sw	$zero,%lo(var8005ddd0)($at)
.L0000f894:
/*     f894:	3c188006 */ 	lui	$t8,%hi(var8005dda0)
/*     f898:	8f18dda0 */ 	lw	$t8,%lo(var8005dda0)($t8)
/*     f89c:	02002025 */ 	or	$a0,$s0,$zero
/*     f8a0:	570000bb */ 	bnezl	$t8,.L0000fb90
/*     f8a4:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*     f8a8:	0c0048f2 */ 	jal	malloc
/*     f8ac:	24050006 */ 	addiu	$a1,$zero,0x6
/*     f8b0:	00502021 */ 	addu	$a0,$v0,$s0
/*     f8b4:	0044082b */ 	sltu	$at,$v0,$a0
/*     f8b8:	00401825 */ 	or	$v1,$v0,$zero
/*     f8bc:	10200005 */ 	beqz	$at,.L0000f8d4
/*     f8c0:	00403825 */ 	or	$a3,$v0,$zero
.L0000f8c4:
/*     f8c4:	24630001 */ 	addiu	$v1,$v1,0x1
/*     f8c8:	0064082b */ 	sltu	$at,$v1,$a0
/*     f8cc:	1420fffd */ 	bnez	$at,.L0000f8c4
/*     f8d0:	a060ffff */ 	sb	$zero,-0x1($v1)
.L0000f8d4:
/*     f8d4:	3c048009 */ 	lui	$a0,%hi(var800951f0)
/*     f8d8:	248451f0 */ 	addiu	$a0,$a0,%lo(var800951f0)
/*     f8dc:	00e02825 */ 	or	$a1,$a3,$zero
/*     f8e0:	0c00bebc */ 	jal	func0002faf0
/*     f8e4:	02003025 */ 	or	$a2,$s0,$zero
/*     f8e8:	3c068009 */ 	lui	$a2,%hi(var800951f0)
/*     f8ec:	24190020 */ 	addiu	$t9,$zero,0x20
/*     f8f0:	afb90010 */ 	sw	$t9,0x10($sp)
/*     f8f4:	24c651f0 */ 	addiu	$a2,$a2,%lo(var800951f0)
/*     f8f8:	00002025 */ 	or	$a0,$zero,$zero
/*     f8fc:	00002825 */ 	or	$a1,$zero,$zero
/*     f900:	0c00bec5 */ 	jal	func0002fb14
/*     f904:	24070001 */ 	addiu	$a3,$zero,0x1
/*     f908:	3c038006 */ 	lui	$v1,%hi(var8005dde0)
/*     f90c:	2463dde0 */ 	addiu	$v1,$v1,%lo(var8005dde0)
/*     f910:	3c057005 */ 	lui	$a1,%hi(var70053b20)
/*     f914:	ac620000 */ 	sw	$v0,0x0($v1)
/*     f918:	24a53b20 */ 	addiu	$a1,$a1,%lo(var70053b20)
/*     f91c:	0c004c4c */ 	jal	strcpy
/*     f920:	00402025 */ 	or	$a0,$v0,$zero
/*     f924:	0c003acb */ 	jal	func0000eb2c
/*     f928:	00000000 */ 	sll	$zero,$zero,0x0
/*     f92c:	3c0900d0 */ 	lui	$t1,0xd0
/*     f930:	3c0a00d0 */ 	lui	$t2,0xd0
/*     f934:	254abf30 */ 	addiu	$t2,$t2,-16592
/*     f938:	25295f90 */ 	addiu	$t1,$t1,0x5f90
/*     f93c:	2408ffff */ 	addiu	$t0,$zero,-1
/*     f940:	3c018009 */ 	lui	$at,%hi(var80095200)
/*     f944:	012a8023 */ 	subu	$s0,$t1,$t2
/*     f948:	3c068009 */ 	lui	$a2,%hi(var800951f0)
/*     f94c:	ac285200 */ 	sw	$t0,%lo(var80095200)($at)
/*     f950:	24c651f0 */ 	addiu	$a2,$a2,%lo(var800951f0)
/*     f954:	afb00010 */ 	sw	$s0,0x10($sp)
/*     f958:	00002025 */ 	or	$a0,$zero,$zero
/*     f95c:	00002825 */ 	or	$a1,$zero,$zero
/*     f960:	0c00bec5 */ 	jal	func0002fb14
/*     f964:	24070001 */ 	addiu	$a3,$zero,0x1
/*     f968:	3c0500d0 */ 	lui	$a1,0xd0
/*     f96c:	00408825 */ 	or	$s1,$v0,$zero
/*     f970:	24a5bf30 */ 	addiu	$a1,$a1,-16592
/*     f974:	00402025 */ 	or	$a0,$v0,$zero
/*     f978:	0c003504 */ 	jal	func0000d410
/*     f97c:	02003025 */ 	or	$a2,$s0,$zero
/*     f980:	3c0500d0 */ 	lui	$a1,0xd0
/*     f984:	24a55f90 */ 	addiu	$a1,$a1,0x5f90
/*     f988:	0c00ddc1 */ 	jal	func00037704
/*     f98c:	02202025 */ 	or	$a0,$s1,$zero
/*     f990:	8e2b0004 */ 	lw	$t3,0x4($s1)
/*     f994:	3c018009 */ 	lui	$at,%hi(var80095204)
/*     f998:	3c068009 */ 	lui	$a2,%hi(var800951f0)
/*     f99c:	240c0010 */ 	addiu	$t4,$zero,0x10
/*     f9a0:	afac0010 */ 	sw	$t4,0x10($sp)
/*     f9a4:	24c651f0 */ 	addiu	$a2,$a2,%lo(var800951f0)
/*     f9a8:	00002025 */ 	or	$a0,$zero,$zero
/*     f9ac:	00002825 */ 	or	$a1,$zero,$zero
/*     f9b0:	24070001 */ 	addiu	$a3,$zero,0x1
/*     f9b4:	0c00bec5 */ 	jal	func0002fb14
/*     f9b8:	ac2b5204 */ 	sw	$t3,%lo(var80095204)($at)
/*     f9bc:	3c108009 */ 	lui	$s0,%hi(var80095208)
/*     f9c0:	3c1100e8 */ 	lui	$s1,0xe8
/*     f9c4:	26105208 */ 	addiu	$s0,$s0,%lo(var80095208)
/*     f9c8:	26312000 */ 	addiu	$s1,$s1,0x2000
/*     f9cc:	ae020000 */ 	sw	$v0,0x0($s0)
/*     f9d0:	02202825 */ 	or	$a1,$s1,$zero
/*     f9d4:	00402025 */ 	or	$a0,$v0,$zero
/*     f9d8:	0c003504 */ 	jal	func0000d410
/*     f9dc:	24060010 */ 	addiu	$a2,$zero,0x10
/*     f9e0:	8e0d0000 */ 	lw	$t5,0x0($s0)
/*     f9e4:	3c068009 */ 	lui	$a2,%hi(var800951f0)
/*     f9e8:	24c651f0 */ 	addiu	$a2,$a2,%lo(var800951f0)
/*     f9ec:	95a30000 */ 	lhu	$v1,0x0($t5)
/*     f9f0:	00002025 */ 	or	$a0,$zero,$zero
/*     f9f4:	00002825 */ 	or	$a1,$zero,$zero
/*     f9f8:	000370c0 */ 	sll	$t6,$v1,0x3
/*     f9fc:	25c30004 */ 	addiu	$v1,$t6,0x4
/*     fa00:	afa30010 */ 	sw	$v1,0x10($sp)
/*     fa04:	afa3004c */ 	sw	$v1,0x4c($sp)
/*     fa08:	0c00bec5 */ 	jal	func0002fb14
/*     fa0c:	24070001 */ 	addiu	$a3,$zero,0x1
/*     fa10:	8fa3004c */ 	lw	$v1,0x4c($sp)
/*     fa14:	2401fff0 */ 	addiu	$at,$zero,-16
/*     fa18:	ae020000 */ 	sw	$v0,0x0($s0)
/*     fa1c:	2466000f */ 	addiu	$a2,$v1,0xf
/*     fa20:	00c17824 */ 	and	$t7,$a2,$at
/*     fa24:	01e03025 */ 	or	$a2,$t7,$zero
/*     fa28:	00402025 */ 	or	$a0,$v0,$zero
/*     fa2c:	0c003504 */ 	jal	func0000d410
/*     fa30:	02202825 */ 	or	$a1,$s1,$zero
/*     fa34:	8e040000 */ 	lw	$a0,0x0($s0)
/*     fa38:	00001825 */ 	or	$v1,$zero,$zero
/*     fa3c:	240a002c */ 	addiu	$t2,$zero,0x2c
/*     fa40:	94980000 */ 	lhu	$t8,0x0($a0)
/*     fa44:	240b001e */ 	addiu	$t3,$zero,0x1e
/*     fa48:	240c0040 */ 	addiu	$t4,$zero,0x40
/*     fa4c:	1b00000d */ 	blez	$t8,.L0000fa84
/*     fa50:	3c0d8009 */ 	lui	$t5,%hi(var800951f0)
/*     fa54:	00002825 */ 	or	$a1,$zero,$zero
/*     fa58:	00851021 */ 	addu	$v0,$a0,$a1
.L0000fa5c:
/*     fa5c:	8c590004 */ 	lw	$t9,0x4($v0)
/*     fa60:	24630001 */ 	addiu	$v1,$v1,0x1
/*     fa64:	24a50008 */ 	addiu	$a1,$a1,0x8
/*     fa68:	03314021 */ 	addu	$t0,$t9,$s1
/*     fa6c:	ac480004 */ 	sw	$t0,0x4($v0)
/*     fa70:	8e040000 */ 	lw	$a0,0x0($s0)
/*     fa74:	94890000 */ 	lhu	$t1,0x0($a0)
/*     fa78:	0069082a */ 	slt	$at,$v1,$t1
/*     fa7c:	5420fff7 */ 	bnezl	$at,.L0000fa5c
/*     fa80:	00851021 */ 	addu	$v0,$a0,$a1
.L0000fa84:
/*     fa84:	3c038009 */ 	lui	$v1,%hi(var80094ea8)
/*     fa88:	8c634ea8 */ 	lw	$v1,%lo(var80094ea8)($v1)
/*     fa8c:	25ad51f0 */ 	addiu	$t5,$t5,%lo(var800951f0)
/*     fa90:	afaa0054 */ 	sw	$t2,0x54($sp)
/*     fa94:	afab0058 */ 	sw	$t3,0x58($sp)
/*     fa98:	afac005c */ 	sw	$t4,0x5c($sp)
/*     fa9c:	afa00064 */ 	sw	$zero,0x64($sp)
/*     faa0:	afa0006c */ 	sw	$zero,0x6c($sp)
/*     faa4:	afad0068 */ 	sw	$t5,0x68($sp)
/*     faa8:	18600008 */ 	blez	$v1,.L0000facc
/*     faac:	afa30060 */ 	sw	$v1,0x60($sp)
/*     fab0:	27a20054 */ 	addiu	$v0,$sp,0x54
/*     fab4:	00622021 */ 	addu	$a0,$v1,$v0
/*     fab8:	24030006 */ 	addiu	$v1,$zero,0x6
.L0000fabc:
/*     fabc:	24420001 */ 	addiu	$v0,$v0,0x1
/*     fac0:	0044082b */ 	sltu	$at,$v0,$a0
/*     fac4:	1420fffd */ 	bnez	$at,.L0000fabc
/*     fac8:	a043001b */ 	sb	$v1,0x1b($v0)
.L0000facc:
/*     facc:	3c098009 */ 	lui	$t1,%hi(var800951f0)
/*     fad0:	240f0040 */ 	addiu	$t7,$zero,0x40
/*     fad4:	24180040 */ 	addiu	$t8,$zero,0x40
/*     fad8:	24190014 */ 	addiu	$t9,$zero,0x14
/*     fadc:	24080009 */ 	addiu	$t0,$zero,0x9
/*     fae0:	252951f0 */ 	addiu	$t1,$t1,%lo(var800951f0)
/*     fae4:	afaf0080 */ 	sw	$t7,0x80($sp)
/*     fae8:	afb8007c */ 	sw	$t8,0x7c($sp)
/*     faec:	afb90084 */ 	sw	$t9,0x84($sp)
/*     faf0:	a7a8008c */ 	sh	$t0,0x8c($sp)
/*     faf4:	afa90088 */ 	sw	$t1,0x88($sp)
/*     faf8:	0c002292 */ 	jal	func00008a48
/*     fafc:	27a40054 */ 	addiu	$a0,$sp,0x54
/*     fb00:	3c0a8006 */ 	lui	$t2,%hi(var8005ddd0)
/*     fb04:	8d4addd0 */ 	lw	$t2,%lo(var8005ddd0)($t2)
/*     fb08:	3c048009 */ 	lui	$a0,%hi(var800951f0)
/*     fb0c:	11400009 */ 	beqz	$t2,.L0000fb34
/*     fb10:	00000000 */ 	sll	$zero,$zero,0x0
/*     fb14:	0c00dec0 */ 	jal	func00037b00
/*     fb18:	248451f0 */ 	addiu	$a0,$a0,%lo(var800951f0)
/*     fb1c:	24047fff */ 	addiu	$a0,$zero,0x7fff
/*     fb20:	0c00dfc2 */ 	jal	func00037f08
/*     fb24:	24050001 */ 	addiu	$a1,$zero,0x1
/*     fb28:	00002025 */ 	or	$a0,$zero,$zero
/*     fb2c:	0c00dfd7 */ 	jal	func00037f5c
/*     fb30:	24050001 */ 	addiu	$a1,$zero,0x1
.L0000fb34:
/*     fb34:	3c108009 */ 	lui	$s0,%hi(var80094ed8)
/*     fb38:	26104ed8 */ 	addiu	$s0,$s0,%lo(var80094ed8)
.L0000fb3c:
/*     fb3c:	0c003d9f */ 	jal	func0000f67c
/*     fb40:	02002025 */ 	or	$a0,$s0,$zero
/*     fb44:	3c0b8009 */ 	lui	$t3,%hi(var800951f0)
/*     fb48:	256b51f0 */ 	addiu	$t3,$t3,%lo(var800951f0)
/*     fb4c:	26100108 */ 	addiu	$s0,$s0,0x108
/*     fb50:	160bfffa */ 	bne	$s0,$t3,.L0000fb3c
/*     fb54:	00000000 */ 	sll	$zero,$zero,0x0
/*     fb58:	0c00c5fc */ 	jal	func000317f0
/*     fb5c:	27a4007c */ 	addiu	$a0,$sp,0x7c
/*     fb60:	3c047001 */ 	lui	$a0,%hi(func0000f76c)
/*     fb64:	0c00ccde */ 	jal	func00033378
/*     fb68:	2484f76c */ 	addiu	$a0,$a0,%lo(func0000f76c)
/*     fb6c:	3c047001 */ 	lui	$a0,%hi(func0000f7b8)
/*     fb70:	0c00cd8d */ 	jal	func00033634
/*     fb74:	2484f7b8 */ 	addiu	$a0,$a0,%lo(func0000f7b8)
/*     fb78:	0c00243b */ 	jal	func000090ec
/*     fb7c:	00000000 */ 	sll	$zero,$zero,0x0
/*     fb80:	3c048006 */ 	lui	$a0,%hi(g_SoundMode)
/*     fb84:	0c003ce3 */ 	jal	audioSetSoundMode
/*     fb88:	8c84ddcc */ 	lw	$a0,%lo(g_SoundMode)($a0)
/*     fb8c:	8fbf0024 */ 	lw	$ra,0x24($sp)
.L0000fb90:
/*     fb90:	8fb0001c */ 	lw	$s0,0x1c($sp)
/*     fb94:	8fb10020 */ 	lw	$s1,0x20($sp)
/*     fb98:	03e00008 */ 	jr	$ra
/*     fb9c:	27bd0090 */ 	addiu	$sp,$sp,0x90
);

GLOBAL_ASM(
glabel func0000fba0
/*     fba0:	27bdfff8 */ 	addiu	$sp,$sp,-8
/*     fba4:	a7a40004 */ 	sh	$a0,0x4($sp)
/*     fba8:	8fa20004 */ 	lw	$v0,0x4($sp)
/*     fbac:	afa40008 */ 	sw	$a0,0x8($sp)
/*     fbb0:	27bd0008 */ 	addiu	$sp,$sp,0x8
/*     fbb4:	0002c0c0 */ 	sll	$t8,$v0,0x3
/*     fbb8:	0018cf82 */ 	srl	$t9,$t8,0x1e
/*     fbbc:	03e00008 */ 	jr	$ra
/*     fbc0:	0019102b */ 	sltu	$v0,$zero,$t9
);

GLOBAL_ASM(
glabel func0000fbc4
/*     fbc4:	3c0e8006 */ 	lui	$t6,%hi(var8005dda0)
/*     fbc8:	8dcedda0 */ 	lw	$t6,%lo(var8005dda0)($t6)
/*     fbcc:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*     fbd0:	afbf0014 */ 	sw	$ra,0x14($sp)
/*     fbd4:	15c00015 */ 	bnez	$t6,.L0000fc2c
/*     fbd8:	afa40018 */ 	sw	$a0,0x18($sp)
/*     fbdc:	3c0f8006 */ 	lui	$t7,%hi(var8005ddd0)
/*     fbe0:	8defddd0 */ 	lw	$t7,%lo(var8005ddd0)($t7)
/*     fbe4:	51e00012 */ 	beqzl	$t7,.L0000fc30
/*     fbe8:	24020001 */ 	addiu	$v0,$zero,0x1
/*     fbec:	0c00dfa9 */ 	jal	func00037ea4
/*     fbf0:	00000000 */ 	sll	$zero,$zero,0x0
/*     fbf4:	10400006 */ 	beqz	$v0,.L0000fc10
/*     fbf8:	3c188009 */ 	lui	$t8,%hi(var80094eb8)
/*     fbfc:	8f184eb8 */ 	lw	$t8,%lo(var80094eb8)($t8)
/*     fc00:	13000003 */ 	beqz	$t8,.L0000fc10
/*     fc04:	00000000 */ 	sll	$zero,$zero,0x0
/*     fc08:	10000009 */ 	beqz	$zero,.L0000fc30
/*     fc0c:	00001025 */ 	or	$v0,$zero,$zero
.L0000fc10:
/*     fc10:	0c00df87 */ 	jal	func00037e1c
/*     fc14:	00000000 */ 	sll	$zero,$zero,0x0
/*     fc18:	3c028009 */ 	lui	$v0,%hi(var80094eb0)
/*     fc1c:	24424eb0 */ 	addiu	$v0,$v0,%lo(var80094eb0)
/*     fc20:	2419ffff */ 	addiu	$t9,$zero,-1
/*     fc24:	ac400004 */ 	sw	$zero,0x4($v0)
/*     fc28:	ac59000c */ 	sw	$t9,0xc($v0)
.L0000fc2c:
/*     fc2c:	24020001 */ 	addiu	$v0,$zero,0x1
.L0000fc30:
/*     fc30:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*     fc34:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*     fc38:	03e00008 */ 	jr	$ra
/*     fc3c:	00000000 */ 	sll	$zero,$zero,0x0
/*     fc40:	03e00008 */ 	jr	$ra
/*     fc44:	afa40000 */ 	sw	$a0,0x0($sp)
);

GLOBAL_ASM(
glabel func0000fc48
/*     fc48:	27bdebb8 */ 	addiu	$sp,$sp,-5192
/*     fc4c:	afb00018 */ 	sw	$s0,0x18($sp)
/*     fc50:	00808025 */ 	or	$s0,$a0,$zero
/*     fc54:	afbf001c */ 	sw	$ra,0x1c($sp)
/*     fc58:	afa5144c */ 	sw	$a1,0x144c($sp)
/*     fc5c:	0c00e344 */ 	jal	func00038d10
/*     fc60:	8c8400f8 */ 	lw	$a0,0xf8($a0)
/*     fc64:	3c0e8006 */ 	lui	$t6,%hi(var8005dda0)
/*     fc68:	8dcedda0 */ 	lw	$t6,%lo(var8005dda0)($t6)
/*     fc6c:	8fa4144c */ 	lw	$a0,0x144c($sp)
/*     fc70:	3c038009 */ 	lui	$v1,%hi(var80095208)
/*     fc74:	51c00004 */ 	beqzl	$t6,.L0000fc88
/*     fc78:	ae040104 */ 	sw	$a0,0x104($s0)
/*     fc7c:	10000038 */ 	beqz	$zero,.L0000fd60
/*     fc80:	00001025 */ 	or	$v0,$zero,$zero
/*     fc84:	ae040104 */ 	sw	$a0,0x104($s0)
.L0000fc88:
/*     fc88:	10400003 */ 	beqz	$v0,.L0000fc98
/*     fc8c:	8c635208 */ 	lw	$v1,%lo(var80095208)($v1)
/*     fc90:	10000033 */ 	beqz	$zero,.L0000fd60
/*     fc94:	00001025 */ 	or	$v0,$zero,$zero
.L0000fc98:
/*     fc98:	8e0f0104 */ 	lw	$t7,0x104($s0)
/*     fc9c:	3c010001 */ 	lui	$at,0x1
/*     fca0:	000fc0c0 */ 	sll	$t8,$t7,0x3
/*     fca4:	00781021 */ 	addu	$v0,$v1,$t8
/*     fca8:	8c450004 */ 	lw	$a1,0x4($v0)
/*     fcac:	00a1082b */ 	sltu	$at,$a1,$at
/*     fcb0:	50200004 */ 	beqzl	$at,.L0000fcc4
/*     fcb4:	94430008 */ 	lhu	$v1,0x8($v0)
/*     fcb8:	10000029 */ 	beqz	$zero,.L0000fd60
/*     fcbc:	00001025 */ 	or	$v0,$zero,$zero
/*     fcc0:	94430008 */ 	lhu	$v1,0x8($v0)
.L0000fcc4:
/*     fcc4:	3c098009 */ 	lui	$t1,%hi(var8009520c)
/*     fcc8:	8d29520c */ 	lw	$t1,%lo(var8009520c)($t1)
/*     fccc:	2463000f */ 	addiu	$v1,$v1,0xf
/*     fcd0:	3479000f */ 	ori	$t9,$v1,0xf
/*     fcd4:	3b28000f */ 	xori	$t0,$t9,0xf
/*     fcd8:	25030040 */ 	addiu	$v1,$t0,0x40
/*     fcdc:	0069082b */ 	sltu	$at,$v1,$t1
/*     fce0:	54200004 */ 	bnezl	$at,.L0000fcf4
/*     fce4:	9446000a */ 	lhu	$a2,0xa($v0)
/*     fce8:	1000001d */ 	beqz	$zero,.L0000fd60
/*     fcec:	00001025 */ 	or	$v0,$zero,$zero
/*     fcf0:	9446000a */ 	lhu	$a2,0xa($v0)
.L0000fcf4:
/*     fcf4:	8e0700fc */ 	lw	$a3,0xfc($s0)
/*     fcf8:	24c6000f */ 	addiu	$a2,$a2,0xf
/*     fcfc:	34ca000f */ 	ori	$t2,$a2,0xf
/*     fd00:	3946000f */ 	xori	$a2,$t2,0xf
/*     fd04:	00e36021 */ 	addu	$t4,$a3,$v1
/*     fd08:	01862023 */ 	subu	$a0,$t4,$a2
/*     fd0c:	afa40028 */ 	sw	$a0,0x28($sp)
/*     fd10:	0c003504 */ 	jal	func0000d410
/*     fd14:	afa7143c */ 	sw	$a3,0x143c($sp)
/*     fd18:	8fa40028 */ 	lw	$a0,0x28($sp)
/*     fd1c:	8fa5143c */ 	lw	$a1,0x143c($sp)
/*     fd20:	0c001d3c */ 	jal	func000074f0
/*     fd24:	27a60034 */ 	addiu	$a2,$sp,0x34
/*     fd28:	02002025 */ 	or	$a0,$s0,$zero
/*     fd2c:	0c00e34c */ 	jal	func00038d30
/*     fd30:	8e0500fc */ 	lw	$a1,0xfc($s0)
/*     fd34:	8e0400f8 */ 	lw	$a0,0xf8($s0)
/*     fd38:	0c00e6f8 */ 	jal	func00039be0
/*     fd3c:	02002825 */ 	or	$a1,$s0,$zero
/*     fd40:	0c003f5d */ 	jal	func0000fd74
/*     fd44:	02002025 */ 	or	$a0,$s0,$zero
/*     fd48:	02002025 */ 	or	$a0,$s0,$zero
/*     fd4c:	0c003f67 */ 	jal	func0000fd9c
/*     fd50:	3045ffff */ 	andi	$a1,$v0,0xffff
/*     fd54:	0c00e70c */ 	jal	func00039c30
/*     fd58:	8e0400f8 */ 	lw	$a0,0xf8($s0)
/*     fd5c:	24020001 */ 	addiu	$v0,$zero,0x1
.L0000fd60:
/*     fd60:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*     fd64:	8fb00018 */ 	lw	$s0,0x18($sp)
/*     fd68:	27bd1448 */ 	addiu	$sp,$sp,0x1448
/*     fd6c:	03e00008 */ 	jr	$ra
/*     fd70:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0000fd74
/*     fd74:	3c0e8006 */ 	lui	$t6,%hi(var8005dda0)
/*     fd78:	8dcedda0 */ 	lw	$t6,%lo(var8005dda0)($t6)
/*     fd7c:	24037fff */ 	addiu	$v1,$zero,0x7fff
/*     fd80:	51c00004 */ 	beqzl	$t6,.L0000fd94
/*     fd84:	94830100 */ 	lhu	$v1,0x100($a0)
/*     fd88:	03e00008 */ 	jr	$ra
/*     fd8c:	3062ffff */ 	andi	$v0,$v1,0xffff
/*     fd90:	94830100 */ 	lhu	$v1,0x100($a0)
.L0000fd94:
/*     fd94:	03e00008 */ 	jr	$ra
/*     fd98:	3062ffff */ 	andi	$v0,$v1,0xffff
);

GLOBAL_ASM(
glabel func0000fd9c
/*     fd9c:	3c0f8006 */ 	lui	$t7,%hi(var8005dda0)
/*     fda0:	8defdda0 */ 	lw	$t7,%lo(var8005dda0)($t7)
/*     fda4:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*     fda8:	afbf0014 */ 	sw	$ra,0x14($sp)
/*     fdac:	afa5001c */ 	sw	$a1,0x1c($sp)
/*     fdb0:	00803025 */ 	or	$a2,$a0,$zero
/*     fdb4:	15e00014 */ 	bnez	$t7,.L0000fe08
/*     fdb8:	30aeffff */ 	andi	$t6,$a1,0xffff
/*     fdbc:	8c980104 */ 	lw	$t8,0x104($a0)
/*     fdc0:	3c088006 */ 	lui	$t0,%hi(var8005ecf8)
/*     fdc4:	34018000 */ 	dli	$at,0x8000
/*     fdc8:	0018c840 */ 	sll	$t9,$t8,0x1
/*     fdcc:	01194021 */ 	addu	$t0,$t0,$t9
/*     fdd0:	8508ecf8 */ 	lh	$t0,%lo(var8005ecf8)($t0)
/*     fdd4:	a48e0100 */ 	sh	$t6,0x100($a0)
/*     fdd8:	010e0019 */ 	multu	$t0,$t6
/*     fddc:	00001012 */ 	mflo	$v0
/*     fde0:	00024bc2 */ 	srl	$t1,$v0,0xf
/*     fde4:	0121082b */ 	sltu	$at,$t1,$at
/*     fde8:	14200002 */ 	bnez	$at,.L0000fdf4
/*     fdec:	01201025 */ 	or	$v0,$t1,$zero
/*     fdf0:	24027fff */ 	addiu	$v0,$zero,0x7fff
.L0000fdf4:
/*     fdf4:	00022c00 */ 	sll	$a1,$v0,0x10
/*     fdf8:	00055403 */ 	sra	$t2,$a1,0x10
/*     fdfc:	01402825 */ 	or	$a1,$t2,$zero
/*     fe00:	0c00e720 */ 	jal	func00039c80
/*     fe04:	8cc400f8 */ 	lw	$a0,0xf8($a2)
.L0000fe08:
/*     fe08:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*     fe0c:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*     fe10:	03e00008 */ 	jr	$ra
/*     fe14:	00000000 */ 	sll	$zero,$zero,0x0
);

void func0000fe18(void)
{
	// empty
}

GLOBAL_ASM(
glabel func0000fe20
/*     fe20:	3c0e8006 */ 	lui	$t6,%hi(var8005ddd0)
/*     fe24:	8dceddd0 */ 	lw	$t6,%lo(var8005ddd0)($t6)
/*     fe28:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*     fe2c:	afbf0014 */ 	sw	$ra,0x14($sp)
/*     fe30:	51c00004 */ 	beqzl	$t6,.L0000fe44
/*     fe34:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*     fe38:	0c00df8e */ 	jal	func00037e38
/*     fe3c:	00000000 */ 	sll	$zero,$zero,0x0
/*     fe40:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0000fe44:
/*     fe44:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*     fe48:	03e00008 */ 	jr	$ra
/*     fe4c:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0000fe50
/*     fe50:	3c0e8006 */ 	lui	$t6,%hi(var8005ddd0)
/*     fe54:	8dceddd0 */ 	lw	$t6,%lo(var8005ddd0)($t6)
/*     fe58:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*     fe5c:	afbf0014 */ 	sw	$ra,0x14($sp)
/*     fe60:	51c00004 */ 	beqzl	$t6,.L0000fe74
/*     fe64:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*     fe68:	0c00df9a */ 	jal	func00037e68
/*     fe6c:	00000000 */ 	sll	$zero,$zero,0x0
/*     fe70:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0000fe74:
/*     fe74:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*     fe78:	03e00008 */ 	jr	$ra
/*     fe7c:	00000000 */ 	sll	$zero,$zero,0x0
/*     fe80:	03e00008 */ 	jr	$ra
/*     fe84:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0000fe88
/*     fe88:	27bdeb98 */ 	addiu	$sp,$sp,-5224
/*     fe8c:	afbf002c */ 	sw	$ra,0x2c($sp)
/*     fe90:	0c003b45 */ 	jal	func0000ed14
/*     fe94:	afb00028 */ 	sw	$s0,0x28($sp)
/*     fe98:	0c012230 */ 	jal	osGetThreadPri
/*     fe9c:	00002025 */ 	or	$a0,$zero,$zero
/*     fea0:	3c048009 */ 	lui	$a0,%hi(var800915e0)
/*     fea4:	00408025 */ 	or	$s0,$v0,$zero
/*     fea8:	0c012230 */ 	jal	osGetThreadPri
/*     feac:	248415e0 */ 	addiu	$a0,$a0,%lo(var800915e0)
/*     feb0:	00002025 */ 	or	$a0,$zero,$zero
/*     feb4:	0c01210c */ 	jal	osSetThreadPri
/*     feb8:	24450001 */ 	addiu	$a1,$v0,0x1
/*     febc:	0c00cfc9 */ 	jal	func00033f24
/*     fec0:	00000000 */ 	sll	$zero,$zero,0x0
/*     fec4:	0c00cfc2 */ 	jal	func00033f08
/*     fec8:	afa20060 */ 	sw	$v0,0x60($sp)
/*     fecc:	3c078006 */ 	lui	$a3,%hi(var8005ddd4)
/*     fed0:	24e7ddd4 */ 	addiu	$a3,$a3,%lo(var8005ddd4)
/*     fed4:	8fa80060 */ 	lw	$t0,0x60($sp)
/*     fed8:	00401825 */ 	or	$v1,$v0,$zero
/*     fedc:	1040002c */ 	beqz	$v0,.L0000ff90
/*     fee0:	ace00000 */ 	sw	$zero,0x0($a3)
/*     fee4:	27a51368 */ 	addiu	$a1,$sp,0x1368
/*     fee8:	27a60068 */ 	addiu	$a2,$sp,0x68
/*     feec:	24090001 */ 	addiu	$t1,$zero,0x1
/*     fef0:	aca30000 */ 	sw	$v1,0x0($a1)
.L0000fef4:
/*     fef4:	0060c025 */ 	or	$t8,$v1,$zero
/*     fef8:	00c0c825 */ 	or	$t9,$a2,$zero
/*     fefc:	246f0048 */ 	addiu	$t7,$v1,0x48
.L0000ff00:
/*     ff00:	8f010000 */ 	lw	$at,0x0($t8)
/*     ff04:	2718000c */ 	addiu	$t8,$t8,0xc
/*     ff08:	2739000c */ 	addiu	$t9,$t9,0xc
/*     ff0c:	af21fff4 */ 	sw	$at,-0xc($t9)
/*     ff10:	8f01fff8 */ 	lw	$at,-0x8($t8)
/*     ff14:	af21fff8 */ 	sw	$at,-0x8($t9)
/*     ff18:	8f01fffc */ 	lw	$at,-0x4($t8)
/*     ff1c:	170ffff8 */ 	bne	$t8,$t7,.L0000ff00
/*     ff20:	af21fffc */ 	sw	$at,-0x4($t9)
/*     ff24:	8f010000 */ 	lw	$at,0x0($t8)
/*     ff28:	af210000 */ 	sw	$at,0x0($t9)
/*     ff2c:	8cea0000 */ 	lw	$t2,0x0($a3)
/*     ff30:	254b0001 */ 	addiu	$t3,$t2,0x1
/*     ff34:	aceb0000 */ 	sw	$t3,0x0($a3)
/*     ff38:	906c0044 */ 	lbu	$t4,0x44($v1)
/*     ff3c:	318d0002 */ 	andi	$t5,$t4,0x2
/*     ff40:	55a0000f */ 	bnezl	$t5,.L0000ff80
/*     ff44:	8c630000 */ 	lw	$v1,0x0($v1)
/*     ff48:	8ca20000 */ 	lw	$v0,0x0($a1)
/*     ff4c:	904e0045 */ 	lbu	$t6,0x45($v0)
/*     ff50:	552e000b */ 	bnel	$t1,$t6,.L0000ff80
/*     ff54:	8c630000 */ 	lw	$v1,0x0($v1)
/*     ff58:	8c440048 */ 	lw	$a0,0x48($v0)
/*     ff5c:	18800007 */ 	blez	$a0,.L0000ff7c
/*     ff60:	0088082a */ 	slt	$at,$a0,$t0
/*     ff64:	50200006 */ 	beqzl	$at,.L0000ff80
/*     ff68:	8c630000 */ 	lw	$v1,0x0($v1)
/*     ff6c:	0c00cf6c */ 	jal	func00033db0
/*     ff70:	ac600048 */ 	sw	$zero,0x48($v1)
/*     ff74:	10000007 */ 	beqz	$zero,.L0000ff94
/*     ff78:	00002025 */ 	or	$a0,$zero,$zero
.L0000ff7c:
/*     ff7c:	8c630000 */ 	lw	$v1,0x0($v1)
.L0000ff80:
/*     ff80:	24a50004 */ 	addiu	$a1,$a1,0x4
/*     ff84:	24c6004c */ 	addiu	$a2,$a2,0x4c
/*     ff88:	5460ffda */ 	bnezl	$v1,.L0000fef4
/*     ff8c:	aca30000 */ 	sw	$v1,0x0($a1)
.L0000ff90:
/*     ff90:	00002025 */ 	or	$a0,$zero,$zero
.L0000ff94:
/*     ff94:	0c01210c */ 	jal	osSetThreadPri
/*     ff98:	02002825 */ 	or	$a1,$s0,$zero
/*     ff9c:	3c048006 */ 	lui	$a0,%hi(var8005ddd8)
/*     ffa0:	3c078006 */ 	lui	$a3,%hi(var8005ddd4)
/*     ffa4:	24e7ddd4 */ 	addiu	$a3,$a3,%lo(var8005ddd4)
/*     ffa8:	2484ddd8 */ 	addiu	$a0,$a0,%lo(var8005ddd8)
/*     ffac:	8c820000 */ 	lw	$v0,0x0($a0)
/*     ffb0:	8ce30000 */ 	lw	$v1,0x0($a3)
/*     ffb4:	3c0f8006 */ 	lui	$t7,%hi(var8005edec)
/*     ffb8:	3c188006 */ 	lui	$t8,%hi(var8005dda0)
/*     ffbc:	0043082a */ 	slt	$at,$v0,$v1
/*     ffc0:	10200003 */ 	beqz	$at,.L0000ffd0
/*     ffc4:	3c198006 */ 	lui	$t9,%hi(var8005ddd0)
/*     ffc8:	ac830000 */ 	sw	$v1,0x0($a0)
/*     ffcc:	00601025 */ 	or	$v0,$v1,$zero
.L0000ffd0:
/*     ffd0:	8defedec */ 	lw	$t7,%lo(var8005edec)($t7)
/*     ffd4:	3c018006 */ 	lui	$at,%hi(var8005edec)
/*     ffd8:	11e20002 */ 	beq	$t7,$v0,.L0000ffe4
/*     ffdc:	00000000 */ 	sll	$zero,$zero,0x0
/*     ffe0:	ac22edec */ 	sw	$v0,%lo(var8005edec)($at)
.L0000ffe4:
/*     ffe4:	8f18dda0 */ 	lw	$t8,%lo(var8005dda0)($t8)
/*     ffe8:	570000d4 */ 	bnezl	$t8,.L0001033c
/*     ffec:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*     fff0:	8f39ddd0 */ 	lw	$t9,%lo(var8005ddd0)($t9)
/*     fff4:	3c02800a */ 	lui	$v0,%hi(g_Vars+0x4b4)
/*     fff8:	532000d0 */ 	beqzl	$t9,.L0001033c
/*     fffc:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*    10000:	8c42a474 */ 	lw	$v0,%lo(g_Vars+0x4b4)($v0)
/*    10004:	24010031 */ 	addiu	$at,$zero,0x31
/*    10008:	54410006 */ 	bnel	$v0,$at,.L00010024
/*    1000c:	24010019 */ 	addiu	$at,$zero,0x19
/*    10010:	0c004384 */ 	jal	func00010e10
/*    10014:	00000000 */ 	sll	$zero,$zero,0x0
/*    10018:	10000006 */ 	beqz	$zero,.L00010034
/*    1001c:	00000000 */ 	sll	$zero,$zero,0x0
/*    10020:	24010019 */ 	addiu	$at,$zero,0x19
.L00010024:
/*    10024:	14410003 */ 	bne	$v0,$at,.L00010034
/*    10028:	00000000 */ 	sll	$zero,$zero,0x0
/*    1002c:	0c004447 */ 	jal	func0001111c
/*    10030:	00000000 */ 	sll	$zero,$zero,0x0
.L00010034:
/*    10034:	3c0a800a */ 	lui	$t2,%hi(g_Vars+0x2ac)
/*    10038:	8d4aa26c */ 	lw	$t2,%lo(g_Vars+0x2ac)($t2)
/*    1003c:	24010006 */ 	addiu	$at,$zero,0x6
/*    10040:	15410014 */ 	bne	$t2,$at,.L00010094
/*    10044:	00000000 */ 	sll	$zero,$zero,0x0
/*    10048:	0fc5b3e8 */ 	jal	func0f16cfa0
/*    1004c:	00000000 */ 	sll	$zero,$zero,0x0
/*    10050:	3c038006 */ 	lui	$v1,%hi(g_SfxVolume)
/*    10054:	9463ddc8 */ 	lhu	$v1,%lo(g_SfxVolume)($v1)
/*    10058:	0062082a */ 	slt	$at,$v1,$v0
/*    1005c:	10200005 */ 	beqz	$at,.L00010074
/*    10060:	00608025 */ 	or	$s0,$v1,$zero
/*    10064:	0fc5b3e8 */ 	jal	func0f16cfa0
/*    10068:	00000000 */ 	sll	$zero,$zero,0x0
/*    1006c:	10000001 */ 	beqz	$zero,.L00010074
/*    10070:	00408025 */ 	or	$s0,$v0,$zero
.L00010074:
/*    10074:	0c003a77 */ 	jal	func0000e9dc
/*    10078:	00000000 */ 	sll	$zero,$zero,0x0
/*    1007c:	1202000d */ 	beq	$s0,$v0,.L000100b4
/*    10080:	00000000 */ 	sll	$zero,$zero,0x0
/*    10084:	0c003aa0 */ 	jal	func0000ea80
/*    10088:	3204ffff */ 	andi	$a0,$s0,0xffff
/*    1008c:	10000009 */ 	beqz	$zero,.L000100b4
/*    10090:	00000000 */ 	sll	$zero,$zero,0x0
.L00010094:
/*    10094:	0c003a77 */ 	jal	func0000e9dc
/*    10098:	00000000 */ 	sll	$zero,$zero,0x0
/*    1009c:	3c048006 */ 	lui	$a0,%hi(g_SfxVolume)
/*    100a0:	9484ddc8 */ 	lhu	$a0,%lo(g_SfxVolume)($a0)
/*    100a4:	10820003 */ 	beq	$a0,$v0,.L000100b4
/*    100a8:	00000000 */ 	sll	$zero,$zero,0x0
/*    100ac:	0c003aa0 */ 	jal	func0000ea80
/*    100b0:	00000000 */ 	sll	$zero,$zero,0x0
.L000100b4:
/*    100b4:	3c048006 */ 	lui	$a0,%hi(var8005dde0)
/*    100b8:	8c84dde0 */ 	lw	$a0,%lo(var8005dde0)($a0)
/*    100bc:	3c057005 */ 	lui	$a1,%hi(var70053b20)
/*    100c0:	10800003 */ 	beqz	$a0,.L000100d0
/*    100c4:	00000000 */ 	sll	$zero,$zero,0x0
/*    100c8:	0c004c9d */ 	jal	func00013274
/*    100cc:	24a53b20 */ 	addiu	$a1,$a1,%lo(var70053b20)
.L000100d0:
/*    100d0:	0c00dfa9 */ 	jal	func00037ea4
/*    100d4:	00000000 */ 	sll	$zero,$zero,0x0
/*    100d8:	1440001d */ 	bnez	$v0,.L00010150
/*    100dc:	3c108009 */ 	lui	$s0,%hi(var80094eb0)
/*    100e0:	26104eb0 */ 	addiu	$s0,$s0,%lo(var80094eb0)
/*    100e4:	8e0b0004 */ 	lw	$t3,0x4($s0)
/*    100e8:	11600019 */ 	beqz	$t3,.L00010150
/*    100ec:	00000000 */ 	sll	$zero,$zero,0x0
/*    100f0:	8e0c0008 */ 	lw	$t4,0x8($s0)
/*    100f4:	51800007 */ 	beqzl	$t4,.L00010114
/*    100f8:	8e020024 */ 	lw	$v0,0x24($s0)
/*    100fc:	8e04001c */ 	lw	$a0,0x1c($s0)
/*    10100:	0c00df62 */ 	jal	func00037d88
/*    10104:	8e050020 */ 	lw	$a1,0x20($s0)
/*    10108:	1000008c */ 	beqz	$zero,.L0001033c
/*    1010c:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*    10110:	8e020024 */ 	lw	$v0,0x24($s0)
.L00010114:
/*    10114:	24030001 */ 	addiu	$v1,$zero,0x1
/*    10118:	24010002 */ 	addiu	$at,$zero,0x2
/*    1011c:	10430007 */ 	beq	$v0,$v1,.L0001013c
/*    10120:	240d003c */ 	addiu	$t5,$zero,0x3c
/*    10124:	10410005 */ 	beq	$v0,$at,.L0001013c
/*    10128:	24010003 */ 	addiu	$at,$zero,0x3
/*    1012c:	50410006 */ 	beql	$v0,$at,.L00010148
/*    10130:	ae03000c */ 	sw	$v1,0xc($s0)
/*    10134:	10000004 */ 	beqz	$zero,.L00010148
/*    10138:	00000000 */ 	sll	$zero,$zero,0x0
.L0001013c:
/*    1013c:	10000002 */ 	beqz	$zero,.L00010148
/*    10140:	ae0d000c */ 	sw	$t5,0xc($s0)
/*    10144:	ae03000c */ 	sw	$v1,0xc($s0)
.L00010148:
/*    10148:	1000007b */ 	beqz	$zero,.L00010338
/*    1014c:	ae000004 */ 	sw	$zero,0x4($s0)
.L00010150:
/*    10150:	3c108009 */ 	lui	$s0,%hi(var80094eb0)
/*    10154:	26104eb0 */ 	addiu	$s0,$s0,%lo(var80094eb0)
/*    10158:	8e02000c */ 	lw	$v0,0xc($s0)
/*    1015c:	3c0e800a */ 	lui	$t6,%hi(g_Vars+0x34)
/*    10160:	58400076 */ 	blezl	$v0,.L0001033c
/*    10164:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*    10168:	8dce9ff4 */ 	lw	$t6,%lo(g_Vars+0x34)($t6)
/*    1016c:	004e7823 */ 	subu	$t7,$v0,$t6
/*    10170:	1de00071 */ 	bgtz	$t7,.L00010338
/*    10174:	ae0f000c */ 	sw	$t7,0xc($s0)
/*    10178:	8e020024 */ 	lw	$v0,0x24($s0)
/*    1017c:	24010002 */ 	addiu	$at,$zero,0x2
/*    10180:	5441001f */ 	bnel	$v0,$at,.L00010200
/*    10184:	24010001 */ 	addiu	$at,$zero,0x1
.L00010188:
/*    10188:	0c004b70 */ 	jal	random
/*    1018c:	00000000 */ 	sll	$zero,$zero,0x0
/*    10190:	8e190010 */ 	lw	$t9,0x10($s0)
/*    10194:	30430003 */ 	andi	$v1,$v0,0x3
/*    10198:	1323fffb */ 	beq	$t9,$v1,.L00010188
/*    1019c:	00000000 */ 	sll	$zero,$zero,0x0
/*    101a0:	3c018009 */ 	lui	$at,%hi(var80094ec0)
/*    101a4:	1060000c */ 	beqz	$v1,.L000101d8
/*    101a8:	ac234ec0 */ 	sw	$v1,%lo(var80094ec0)($at)
/*    101ac:	24010001 */ 	addiu	$at,$zero,0x1
/*    101b0:	1061000c */ 	beq	$v1,$at,.L000101e4
/*    101b4:	240b7cee */ 	addiu	$t3,$zero,0x7cee
/*    101b8:	24010002 */ 	addiu	$at,$zero,0x2
/*    101bc:	1061000b */ 	beq	$v1,$at,.L000101ec
/*    101c0:	240c7cef */ 	addiu	$t4,$zero,0x7cef
/*    101c4:	24010003 */ 	addiu	$at,$zero,0x3
/*    101c8:	1061000a */ 	beq	$v1,$at,.L000101f4
/*    101cc:	240d7cf0 */ 	addiu	$t5,$zero,0x7cf0
/*    101d0:	1000004a */ 	beqz	$zero,.L000102fc
/*    101d4:	3c01bf80 */ 	lui	$at,0xbf80
.L000101d8:
/*    101d8:	240a7ced */ 	addiu	$t2,$zero,0x7ced
/*    101dc:	10000046 */ 	beqz	$zero,.L000102f8
/*    101e0:	a7aa0050 */ 	sh	$t2,0x50($sp)
.L000101e4:
/*    101e4:	10000044 */ 	beqz	$zero,.L000102f8
/*    101e8:	a7ab0050 */ 	sh	$t3,0x50($sp)
.L000101ec:
/*    101ec:	10000042 */ 	beqz	$zero,.L000102f8
/*    101f0:	a7ac0050 */ 	sh	$t4,0x50($sp)
.L000101f4:
/*    101f4:	10000040 */ 	beqz	$zero,.L000102f8
/*    101f8:	a7ad0050 */ 	sh	$t5,0x50($sp)
/*    101fc:	24010001 */ 	addiu	$at,$zero,0x1
.L00010200:
/*    10200:	5441001f */ 	bnel	$v0,$at,.L00010280
/*    10204:	24010003 */ 	addiu	$at,$zero,0x3
.L00010208:
/*    10208:	0c004b70 */ 	jal	random
/*    1020c:	00000000 */ 	sll	$zero,$zero,0x0
/*    10210:	8e0e0014 */ 	lw	$t6,0x14($s0)
/*    10214:	30430003 */ 	andi	$v1,$v0,0x3
/*    10218:	11c3fffb */ 	beq	$t6,$v1,.L00010208
/*    1021c:	00000000 */ 	sll	$zero,$zero,0x0
/*    10220:	3c018009 */ 	lui	$at,%hi(var80094ec4)
/*    10224:	1060000c */ 	beqz	$v1,.L00010258
/*    10228:	ac234ec4 */ 	sw	$v1,%lo(var80094ec4)($at)
/*    1022c:	24010001 */ 	addiu	$at,$zero,0x1
/*    10230:	1061000c */ 	beq	$v1,$at,.L00010264
/*    10234:	24187cf9 */ 	addiu	$t8,$zero,0x7cf9
/*    10238:	24010002 */ 	addiu	$at,$zero,0x2
/*    1023c:	1061000b */ 	beq	$v1,$at,.L0001026c
/*    10240:	24197cfa */ 	addiu	$t9,$zero,0x7cfa
/*    10244:	24010003 */ 	addiu	$at,$zero,0x3
/*    10248:	1061000a */ 	beq	$v1,$at,.L00010274
/*    1024c:	240a7cfb */ 	addiu	$t2,$zero,0x7cfb
/*    10250:	1000002a */ 	beqz	$zero,.L000102fc
/*    10254:	3c01bf80 */ 	lui	$at,0xbf80
.L00010258:
/*    10258:	240f7cf8 */ 	addiu	$t7,$zero,0x7cf8
/*    1025c:	10000026 */ 	beqz	$zero,.L000102f8
/*    10260:	a7af0050 */ 	sh	$t7,0x50($sp)
.L00010264:
/*    10264:	10000024 */ 	beqz	$zero,.L000102f8
/*    10268:	a7b80050 */ 	sh	$t8,0x50($sp)
.L0001026c:
/*    1026c:	10000022 */ 	beqz	$zero,.L000102f8
/*    10270:	a7b90050 */ 	sh	$t9,0x50($sp)
.L00010274:
/*    10274:	10000020 */ 	beqz	$zero,.L000102f8
/*    10278:	a7aa0050 */ 	sh	$t2,0x50($sp)
/*    1027c:	24010003 */ 	addiu	$at,$zero,0x3
.L00010280:
/*    10280:	5441001e */ 	bnel	$v0,$at,.L000102fc
/*    10284:	3c01bf80 */ 	lui	$at,0xbf80
.L00010288:
/*    10288:	0c004b70 */ 	jal	random
/*    1028c:	00000000 */ 	sll	$zero,$zero,0x0
/*    10290:	8e0b0018 */ 	lw	$t3,0x18($s0)
/*    10294:	30430003 */ 	andi	$v1,$v0,0x3
/*    10298:	1163fffb */ 	beq	$t3,$v1,.L00010288
/*    1029c:	00000000 */ 	sll	$zero,$zero,0x0
/*    102a0:	3c018009 */ 	lui	$at,%hi(var80094ec8)
/*    102a4:	1060000c */ 	beqz	$v1,.L000102d8
/*    102a8:	ac234ec8 */ 	sw	$v1,%lo(var80094ec8)($at)
/*    102ac:	24010001 */ 	addiu	$at,$zero,0x1
/*    102b0:	1061000c */ 	beq	$v1,$at,.L000102e4
/*    102b4:	240d77b7 */ 	addiu	$t5,$zero,0x77b7
/*    102b8:	24010002 */ 	addiu	$at,$zero,0x2
/*    102bc:	1061000b */ 	beq	$v1,$at,.L000102ec
/*    102c0:	240e77b8 */ 	addiu	$t6,$zero,0x77b8
/*    102c4:	24010003 */ 	addiu	$at,$zero,0x3
/*    102c8:	1061000a */ 	beq	$v1,$at,.L000102f4
/*    102cc:	240f77b9 */ 	addiu	$t7,$zero,0x77b9
/*    102d0:	1000000a */ 	beqz	$zero,.L000102fc
/*    102d4:	3c01bf80 */ 	lui	$at,0xbf80
.L000102d8:
/*    102d8:	240c77b6 */ 	addiu	$t4,$zero,0x77b6
/*    102dc:	10000006 */ 	beqz	$zero,.L000102f8
/*    102e0:	a7ac0050 */ 	sh	$t4,0x50($sp)
.L000102e4:
/*    102e4:	10000004 */ 	beqz	$zero,.L000102f8
/*    102e8:	a7ad0050 */ 	sh	$t5,0x50($sp)
.L000102ec:
/*    102ec:	10000002 */ 	beqz	$zero,.L000102f8
/*    102f0:	a7ae0050 */ 	sh	$t6,0x50($sp)
.L000102f4:
/*    102f4:	a7af0050 */ 	sh	$t7,0x50($sp)
.L000102f8:
/*    102f8:	3c01bf80 */ 	lui	$at,0xbf80
.L000102fc:
/*    102fc:	44812000 */ 	mtc1	$at,$f4
/*    10300:	2418ffff */ 	addiu	$t8,$zero,-1
/*    10304:	2419ffff */ 	addiu	$t9,$zero,-1
/*    10308:	240affff */ 	addiu	$t2,$zero,-1
/*    1030c:	240bffff */ 	addiu	$t3,$zero,-1
/*    10310:	ae18000c */ 	sw	$t8,0xc($s0)
/*    10314:	afab001c */ 	sw	$t3,0x1c($sp)
/*    10318:	afaa0018 */ 	sw	$t2,0x18($sp)
/*    1031c:	afb90010 */ 	sw	$t9,0x10($sp)
/*    10320:	00002025 */ 	or	$a0,$zero,$zero
/*    10324:	87a50050 */ 	lh	$a1,0x50($sp)
/*    10328:	00003025 */ 	or	$a2,$zero,$zero
/*    1032c:	2407ffff */ 	addiu	$a3,$zero,-1
/*    10330:	0c004241 */ 	jal	func00010904
/*    10334:	e7a40014 */ 	swc1	$f4,0x14($sp)
.L00010338:
/*    10338:	8fbf002c */ 	lw	$ra,0x2c($sp)
.L0001033c:
/*    1033c:	8fb00028 */ 	lw	$s0,0x28($sp)
/*    10340:	27bd1468 */ 	addiu	$sp,$sp,0x1468
/*    10344:	03e00008 */ 	jr	$ra
/*    10348:	00000000 */ 	sll	$zero,$zero,0x0
/*    1034c:	309907ff */ 	andi	$t9,$a0,0x7ff
/*    10350:	00194400 */ 	sll	$t0,$t9,0x10
/*    10354:	afa40000 */ 	sw	$a0,0x0($sp)
/*    10358:	03e00008 */ 	jr	$ra
/*    1035c:	00081403 */ 	sra	$v0,$t0,0x10
);

GLOBAL_ASM(
glabel func00010360
/*    10360:	3c028006 */ 	lui	$v0,%hi(var8005dda0)
/*    10364:	03e00008 */ 	jr	$ra
/*    10368:	8c42dda0 */ 	lw	$v0,%lo(var8005dda0)($v0)
);

GLOBAL_ASM(
glabel func0001036c
/*    1036c:	3c0e8006 */ 	lui	$t6,%hi(var8005dda0)
/*    10370:	8dcedda0 */ 	lw	$t6,%lo(var8005dda0)($t6)
/*    10374:	27bdffd0 */ 	addiu	$sp,$sp,-48
/*    10378:	afbf0024 */ 	sw	$ra,0x24($sp)
/*    1037c:	15c0001f */ 	bnez	$t6,.L000103fc
/*    10380:	afa40030 */ 	sw	$a0,0x30($sp)
/*    10384:	3c0f8006 */ 	lui	$t7,%hi(var8005ddd0)
/*    10388:	8defddd0 */ 	lw	$t7,%lo(var8005ddd0)($t7)
/*    1038c:	00806025 */ 	or	$t4,$a0,$zero
/*    10390:	318d07ff */ 	andi	$t5,$t4,0x7ff
/*    10394:	11e00019 */ 	beqz	$t7,.L000103fc
/*    10398:	00002025 */ 	or	$a0,$zero,$zero
/*    1039c:	a7a0002c */ 	sh	$zero,0x2c($sp)
/*    103a0:	93b8002c */ 	lbu	$t8,0x2c($sp)
/*    103a4:	3c01bf80 */ 	lui	$at,0xbf80
/*    103a8:	44812000 */ 	mtc1	$at,$f4
/*    103ac:	3308ff9f */ 	andi	$t0,$t8,0xff9f
/*    103b0:	310900e7 */ 	andi	$t1,$t0,0xe7
/*    103b4:	a3a8002c */ 	sb	$t0,0x2c($sp)
/*    103b8:	352a0008 */ 	ori	$t2,$t1,0x8
/*    103bc:	a3aa002c */ 	sb	$t2,0x2c($sp)
/*    103c0:	97ae002c */ 	lhu	$t6,0x2c($sp)
/*    103c4:	2409ffff */ 	addiu	$t1,$zero,-1
/*    103c8:	2408ffff */ 	addiu	$t0,$zero,-1
/*    103cc:	31cff800 */ 	andi	$t7,$t6,0xf800
/*    103d0:	01afc025 */ 	or	$t8,$t5,$t7
/*    103d4:	a7b8002c */ 	sh	$t8,0x2c($sp)
/*    103d8:	2419ffff */ 	addiu	$t9,$zero,-1
/*    103dc:	afb90010 */ 	sw	$t9,0x10($sp)
/*    103e0:	87a5002c */ 	lh	$a1,0x2c($sp)
/*    103e4:	afa80018 */ 	sw	$t0,0x18($sp)
/*    103e8:	afa9001c */ 	sw	$t1,0x1c($sp)
/*    103ec:	00003025 */ 	or	$a2,$zero,$zero
/*    103f0:	2407ffff */ 	addiu	$a3,$zero,-1
/*    103f4:	0c004241 */ 	jal	func00010904
/*    103f8:	e7a40014 */ 	swc1	$f4,0x14($sp)
.L000103fc:
/*    103fc:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*    10400:	27bd0030 */ 	addiu	$sp,$sp,0x30
/*    10404:	03e00008 */ 	jr	$ra
/*    10408:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel audioIsFiltered
/*    1040c:	3c0e800a */ 	lui	$t6,%hi(g_Vars+0x4e3)
/*    10410:	91cea4a3 */ 	lbu	$t6,%lo(g_Vars+0x4e3)($t6)
/*    10414:	27bdfff8 */ 	addiu	$sp,$sp,-8
/*    10418:	51c0001f */ 	beqzl	$t6,.L00010498
/*    1041c:	00001025 */ 	or	$v0,$zero,$zero
/*    10420:	a7a40004 */ 	sh	$a0,0x4($sp)
/*    10424:	8faf0004 */ 	lw	$t7,0x4($sp)
/*    10428:	97a20004 */ 	lhu	$v0,0x4($sp)
/*    1042c:	2401051d */ 	addiu	$at,$zero,0x51d
/*    10430:	000fc7c2 */ 	srl	$t8,$t7,0x1f
/*    10434:	1300000f */ 	beqz	$t8,.L00010474
/*    10438:	304e07ff */ 	andi	$t6,$v0,0x7ff
/*    1043c:	30887fff */ 	andi	$t0,$a0,0x7fff
/*    10440:	00084880 */ 	sll	$t1,$t0,0x2
/*    10444:	3c0a8006 */ 	lui	$t2,%hi(audiodefinitions+0x2)
/*    10448:	01495021 */ 	addu	$t2,$t2,$t1
/*    1044c:	954adde6 */ 	lhu	$t2,%lo(audiodefinitions+0x2)($t2)
/*    10450:	3c0c8006 */ 	lui	$t4,%hi(audioconfigs+0x1c)
/*    10454:	000a5940 */ 	sll	$t3,$t2,0x5
/*    10458:	018b6021 */ 	addu	$t4,$t4,$t3
/*    1045c:	8d8ce4f4 */ 	lw	$t4,%lo(audioconfigs+0x1c)($t4)
/*    10460:	318d0010 */ 	andi	$t5,$t4,0x10
/*    10464:	51a0000c */ 	beqzl	$t5,.L00010498
/*    10468:	00001025 */ 	or	$v0,$zero,$zero
/*    1046c:	1000000a */ 	beqz	$zero,.L00010498
/*    10470:	24020001 */ 	addiu	$v0,$zero,0x1
.L00010474:
/*    10474:	11c10005 */ 	beq	$t6,$at,.L0001048c
/*    10478:	2401051e */ 	addiu	$at,$zero,0x51e
/*    1047c:	11c10003 */ 	beq	$t6,$at,.L0001048c
/*    10480:	240117ad */ 	addiu	$at,$zero,0x17ad
/*    10484:	55c10004 */ 	bnel	$t6,$at,.L00010498
/*    10488:	00001025 */ 	or	$v0,$zero,$zero
.L0001048c:
/*    1048c:	10000002 */ 	beqz	$zero,.L00010498
/*    10490:	24020001 */ 	addiu	$v0,$zero,0x1
/*    10494:	00001025 */ 	or	$v0,$zero,$zero
.L00010498:
/*    10498:	03e00008 */ 	jr	$ra
/*    1049c:	27bd0008 */ 	addiu	$sp,$sp,0x8
);

//bool audioIsFiltered(s16 audio_id)
//{
//	bool filtered = false;
//
//	if (g_LangFilterActive) {
//		if (audio_id < 0) {
//			u32 bankoffset = audio_id & 0x7ff;
//			filtered = bankoffset == 0x51d || bankoffset == 0x51e || bankoffset == 0x17ad;
//		} else {
//			filtered = (audioconfigs[audiodefinitions[audio_id].audioconfig_index].flags & 0x10) != 0;
//		}
//	}
//
//	return filtered;
//}

GLOBAL_ASM(
glabel func000104a0
/*    104a0:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*    104a4:	8faf0048 */ 	lw	$t7,0x48($sp)
/*    104a8:	240effff */ 	addiu	$t6,$zero,-1
/*    104ac:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    104b0:	afa40028 */ 	sw	$a0,0x28($sp)
/*    104b4:	afa5002c */ 	sw	$a1,0x2c($sp)
/*    104b8:	15e00005 */ 	bnez	$t7,.L000104d0
/*    104bc:	afae0024 */ 	sw	$t6,0x24($sp)
/*    104c0:	8fa20044 */ 	lw	$v0,0x44($sp)
/*    104c4:	2408ffff */ 	addiu	$t0,$zero,-1
/*    104c8:	50480015 */ 	beql	$v0,$t0,.L00010520
/*    104cc:	8fa20038 */ 	lw	$v0,0x38($sp)
.L000104d0:
/*    104d0:	8fa20044 */ 	lw	$v0,0x44($sp)
/*    104d4:	2408ffff */ 	addiu	$t0,$zero,-1
/*    104d8:	3c188006 */ 	lui	$t8,%hi(g_SoundMode)
/*    104dc:	50480004 */ 	beql	$v0,$t0,.L000104f0
/*    104e0:	afa00024 */ 	sw	$zero,0x24($sp)
/*    104e4:	10000002 */ 	beqz	$zero,.L000104f0
/*    104e8:	afa20024 */ 	sw	$v0,0x24($sp)
/*    104ec:	afa00024 */ 	sw	$zero,0x24($sp)
.L000104f0:
/*    104f0:	50e8000b */ 	beql	$a3,$t0,.L00010520
/*    104f4:	8fa20038 */ 	lw	$v0,0x38($sp)
/*    104f8:	8f18ddcc */ 	lw	$t8,%lo(g_SoundMode)($t8)
/*    104fc:	24010003 */ 	addiu	$at,$zero,0x3
/*    10500:	30f90080 */ 	andi	$t9,$a3,0x80
/*    10504:	57010006 */ 	bnel	$t8,$at,.L00010520
/*    10508:	8fa20038 */ 	lw	$v0,0x38($sp)
/*    1050c:	13200003 */ 	beqz	$t9,.L0001051c
/*    10510:	8faa0024 */ 	lw	$t2,0x24($sp)
/*    10514:	254b0080 */ 	addiu	$t3,$t2,0x80
/*    10518:	afab0024 */ 	sw	$t3,0x24($sp)
.L0001051c:
/*    1051c:	8fa20038 */ 	lw	$v0,0x38($sp)
.L00010520:
/*    10520:	58400036 */ 	blezl	$v0,.L000105fc
/*    10524:	8fac002c */ 	lw	$t4,0x2c($sp)
/*    10528:	a7a20020 */ 	sh	$v0,0x20($sp)
/*    1052c:	8fac0020 */ 	lw	$t4,0x20($sp)
/*    10530:	3c058006 */ 	lui	$a1,%hi(audiodefinitions)
/*    10534:	24a5dde4 */ 	addiu	$a1,$a1,%lo(audiodefinitions)
/*    10538:	000c6fc2 */ 	srl	$t5,$t4,0x1f
/*    1053c:	11a0002e */ 	beqz	$t5,.L000105f8
/*    10540:	00407025 */ 	or	$t6,$v0,$zero
/*    10544:	31cf7fff */ 	andi	$t7,$t6,0x7fff
/*    10548:	000fc080 */ 	sll	$t8,$t7,0x2
/*    1054c:	00b8c821 */ 	addu	$t9,$a1,$t8
/*    10550:	00b85021 */ 	addu	$t2,$a1,$t8
/*    10554:	97220002 */ 	lhu	$v0,0x2($t9)
/*    10558:	854b0000 */ 	lh	$t3,0x0($t2)
/*    1055c:	3c0f8006 */ 	lui	$t7,%hi(audioconfigs)
/*    10560:	25efe4d8 */ 	addiu	$t7,$t7,%lo(audioconfigs)
/*    10564:	00027140 */ 	sll	$t6,$v0,0x5
/*    10568:	a7ab001c */ 	sh	$t3,0x1c($sp)
/*    1056c:	93ac001c */ 	lbu	$t4,0x1c($sp)
/*    10570:	01cf2021 */ 	addu	$a0,$t6,$t7
/*    10574:	8c830010 */ 	lw	$v1,0x10($a0)
/*    10578:	24090064 */ 	addiu	$t1,$zero,0x64
/*    1057c:	318dff7f */ 	andi	$t5,$t4,0xff7f
/*    10580:	11230010 */ 	beq	$t1,$v1,.L000105c4
/*    10584:	a3ad001c */ 	sb	$t5,0x1c($sp)
/*    10588:	00660019 */ 	multu	$v1,$a2
/*    1058c:	0000c812 */ 	mflo	$t9
/*    10590:	00000000 */ 	sll	$zero,$zero,0x0
/*    10594:	00000000 */ 	sll	$zero,$zero,0x0
/*    10598:	0329001a */ 	div	$zero,$t9,$t1
/*    1059c:	00003012 */ 	mflo	$a2
/*    105a0:	15200002 */ 	bnez	$t1,.L000105ac
/*    105a4:	00000000 */ 	sll	$zero,$zero,0x0
/*    105a8:	0007000d */ 	break	0x7
.L000105ac:
/*    105ac:	2401ffff */ 	addiu	$at,$zero,-1
/*    105b0:	15210004 */ 	bne	$t1,$at,.L000105c4
/*    105b4:	3c018000 */ 	lui	$at,0x8000
/*    105b8:	17210002 */ 	bne	$t9,$at,.L000105c4
/*    105bc:	00000000 */ 	sll	$zero,$zero,0x0
/*    105c0:	0006000d */ 	break	0x6
.L000105c4:
/*    105c4:	8c820014 */ 	lw	$v0,0x14($a0)
/*    105c8:	3c18800a */ 	lui	$t8,%hi(g_Vars+0x4e3)
/*    105cc:	11020002 */ 	beq	$t0,$v0,.L000105d8
/*    105d0:	00000000 */ 	sll	$zero,$zero,0x0
/*    105d4:	00403825 */ 	or	$a3,$v0,$zero
.L000105d8:
/*    105d8:	9318a4a3 */ 	lbu	$t8,%lo(g_Vars+0x4e3)($t8)
/*    105dc:	53000007 */ 	beqzl	$t8,.L000105fc
/*    105e0:	8fac002c */ 	lw	$t4,0x2c($sp)
/*    105e4:	8c8a001c */ 	lw	$t2,0x1c($a0)
/*    105e8:	314b0010 */ 	andi	$t3,$t2,0x10
/*    105ec:	51600003 */ 	beqzl	$t3,.L000105fc
/*    105f0:	8fac002c */ 	lw	$t4,0x2c($sp)
/*    105f4:	00003025 */ 	or	$a2,$zero,$zero
.L000105f8:
/*    105f8:	8fac002c */ 	lw	$t4,0x2c($sp)
.L000105fc:
/*    105fc:	5180001f */ 	beqzl	$t4,.L0001067c
/*    10600:	8fae0028 */ 	lw	$t6,0x28($sp)
/*    10604:	10c80013 */ 	beq	$a2,$t0,.L00010654
/*    10608:	00000000 */ 	sll	$zero,$zero,0x0
/*    1060c:	afa60030 */ 	sw	$a2,0x30($sp)
/*    10610:	0c003a77 */ 	jal	func0000e9dc
/*    10614:	afa70034 */ 	sw	$a3,0x34($sp)
/*    10618:	8fa60030 */ 	lw	$a2,0x30($sp)
/*    1061c:	24017fff */ 	addiu	$at,$zero,0x7fff
/*    10620:	24050001 */ 	addiu	$a1,$zero,0x1
/*    10624:	00460019 */ 	multu	$v0,$a2
/*    10628:	00003012 */ 	mflo	$a2
/*    1062c:	00000000 */ 	sll	$zero,$zero,0x0
/*    10630:	00000000 */ 	sll	$zero,$zero,0x0
/*    10634:	00c1001a */ 	div	$zero,$a2,$at
/*    10638:	00002012 */ 	mflo	$a0
/*    1063c:	afa40030 */ 	sw	$a0,0x30($sp)
/*    10640:	0c00dfc2 */ 	jal	func00037f08
/*    10644:	00000000 */ 	sll	$zero,$zero,0x0
/*    10648:	8fa60030 */ 	lw	$a2,0x30($sp)
/*    1064c:	8fa70034 */ 	lw	$a3,0x34($sp)
/*    10650:	2408ffff */ 	addiu	$t0,$zero,-1
.L00010654:
/*    10654:	10e80008 */ 	beq	$a3,$t0,.L00010678
/*    10658:	00e02025 */ 	or	$a0,$a3,$zero
/*    1065c:	24050001 */ 	addiu	$a1,$zero,0x1
/*    10660:	afa60030 */ 	sw	$a2,0x30($sp)
/*    10664:	0c00dfd7 */ 	jal	func00037f5c
/*    10668:	afa70034 */ 	sw	$a3,0x34($sp)
/*    1066c:	8fa60030 */ 	lw	$a2,0x30($sp)
/*    10670:	8fa70034 */ 	lw	$a3,0x34($sp)
/*    10674:	2408ffff */ 	addiu	$t0,$zero,-1
.L00010678:
/*    10678:	8fae0028 */ 	lw	$t6,0x28($sp)
.L0001067c:
/*    1067c:	8dc40000 */ 	lw	$a0,0x0($t6)
/*    10680:	50800022 */ 	beqzl	$a0,.L0001070c
/*    10684:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    10688:	10c80005 */ 	beq	$a2,$t0,.L000106a0
/*    1068c:	24050008 */ 	addiu	$a1,$zero,0x8
/*    10690:	0c00cf94 */ 	jal	func00033e50
/*    10694:	afa70034 */ 	sw	$a3,0x34($sp)
/*    10698:	8fa70034 */ 	lw	$a3,0x34($sp)
/*    1069c:	2408ffff */ 	addiu	$t0,$zero,-1
.L000106a0:
/*    106a0:	10e80006 */ 	beq	$a3,$t0,.L000106bc
/*    106a4:	8faf0028 */ 	lw	$t7,0x28($sp)
/*    106a8:	8de40000 */ 	lw	$a0,0x0($t7)
/*    106ac:	24050004 */ 	addiu	$a1,$zero,0x4
/*    106b0:	0c00cf94 */ 	jal	func00033e50
/*    106b4:	30e6007f */ 	andi	$a2,$a3,0x7f
/*    106b8:	2408ffff */ 	addiu	$t0,$zero,-1
.L000106bc:
/*    106bc:	3c01bf80 */ 	lui	$at,0xbf80
/*    106c0:	44813000 */ 	mtc1	$at,$f6
/*    106c4:	c7a4003c */ 	lwc1	$f4,0x3c($sp)
/*    106c8:	8fb90028 */ 	lw	$t9,0x28($sp)
/*    106cc:	24050010 */ 	addiu	$a1,$zero,0x10
/*    106d0:	46062032 */ 	c.eq.s	$f4,$f6
/*    106d4:	8fa6003c */ 	lw	$a2,0x3c($sp)
/*    106d8:	45030005 */ 	bc1tl	.L000106f0
/*    106dc:	8fb80024 */ 	lw	$t8,0x24($sp)
/*    106e0:	0c00cf94 */ 	jal	func00033e50
/*    106e4:	8f240000 */ 	lw	$a0,0x0($t9)
/*    106e8:	2408ffff */ 	addiu	$t0,$zero,-1
/*    106ec:	8fb80024 */ 	lw	$t8,0x24($sp)
.L000106f0:
/*    106f0:	8faa0028 */ 	lw	$t2,0x28($sp)
/*    106f4:	24050100 */ 	addiu	$a1,$zero,0x100
/*    106f8:	13080003 */ 	beq	$t8,$t0,.L00010708
/*    106fc:	03003025 */ 	or	$a2,$t8,$zero
/*    10700:	0c00cf94 */ 	jal	func00033e50
/*    10704:	8d440000 */ 	lw	$a0,0x0($t2)
.L00010708:
/*    10708:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0001070c:
/*    1070c:	27bd0028 */ 	addiu	$sp,$sp,0x28
/*    10710:	03e00008 */ 	jr	$ra
/*    10714:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func00010718
/*    10718:	27bdffc0 */ 	addiu	$sp,$sp,-64
/*    1071c:	afbf0024 */ 	sw	$ra,0x24($sp)
/*    10720:	afa40040 */ 	sw	$a0,0x40($sp)
/*    10724:	afa50044 */ 	sw	$a1,0x44($sp)
/*    10728:	afa60048 */ 	sw	$a2,0x48($sp)
/*    1072c:	afa7004c */ 	sw	$a3,0x4c($sp)
/*    10730:	0c012230 */ 	jal	osGetThreadPri
/*    10734:	00002025 */ 	or	$a0,$zero,$zero
/*    10738:	2408ffff */ 	addiu	$t0,$zero,-1
/*    1073c:	3c048009 */ 	lui	$a0,%hi(var800915e0)
/*    10740:	afa2003c */ 	sw	$v0,0x3c($sp)
/*    10744:	248415e0 */ 	addiu	$a0,$a0,%lo(var800915e0)
/*    10748:	0c012230 */ 	jal	osGetThreadPri
/*    1074c:	afa80038 */ 	sw	$t0,0x38($sp)
/*    10750:	00002025 */ 	or	$a0,$zero,$zero
/*    10754:	0c01210c */ 	jal	osSetThreadPri
/*    10758:	24450001 */ 	addiu	$a1,$v0,0x1
/*    1075c:	8fae0060 */ 	lw	$t6,0x60($sp)
/*    10760:	8fa80038 */ 	lw	$t0,0x38($sp)
/*    10764:	8fa2005c */ 	lw	$v0,0x5c($sp)
/*    10768:	15c00004 */ 	bnez	$t6,.L0001077c
/*    1076c:	8fa90050 */ 	lw	$t1,0x50($sp)
/*    10770:	2407ffff */ 	addiu	$a3,$zero,-1
/*    10774:	10470012 */ 	beq	$v0,$a3,.L000107c0
/*    10778:	00000000 */ 	sll	$zero,$zero,0x0
.L0001077c:
/*    1077c:	8fa2005c */ 	lw	$v0,0x5c($sp)
/*    10780:	2407ffff */ 	addiu	$a3,$zero,-1
/*    10784:	00004025 */ 	or	$t0,$zero,$zero
/*    10788:	10470003 */ 	beq	$v0,$a3,.L00010798
/*    1078c:	8faf004c */ 	lw	$t7,0x4c($sp)
/*    10790:	10000001 */ 	beqz	$zero,.L00010798
/*    10794:	00404025 */ 	or	$t0,$v0,$zero
.L00010798:
/*    10798:	11e70009 */ 	beq	$t7,$a3,.L000107c0
/*    1079c:	3c188006 */ 	lui	$t8,%hi(g_SoundMode)
/*    107a0:	8f18ddcc */ 	lw	$t8,%lo(g_SoundMode)($t8)
/*    107a4:	24010003 */ 	addiu	$at,$zero,0x3
/*    107a8:	31f90080 */ 	andi	$t9,$t7,0x80
/*    107ac:	17010004 */ 	bne	$t8,$at,.L000107c0
/*    107b0:	00000000 */ 	sll	$zero,$zero,0x0
/*    107b4:	13200002 */ 	beqz	$t9,.L000107c0
/*    107b8:	00000000 */ 	sll	$zero,$zero,0x0
/*    107bc:	25080080 */ 	addiu	$t0,$t0,0x80
.L000107c0:
/*    107c0:	51200039 */ 	beqzl	$t1,.L000108a8
/*    107c4:	8fad004c */ 	lw	$t5,0x4c($sp)
/*    107c8:	a7a90030 */ 	sh	$t1,0x30($sp)
/*    107cc:	8faa0030 */ 	lw	$t2,0x30($sp)
/*    107d0:	3c058006 */ 	lui	$a1,%hi(audiodefinitions)
/*    107d4:	24a5dde4 */ 	addiu	$a1,$a1,%lo(audiodefinitions)
/*    107d8:	000a5fc2 */ 	srl	$t3,$t2,0x1f
/*    107dc:	11600031 */ 	beqz	$t3,.L000108a4
/*    107e0:	24060064 */ 	addiu	$a2,$zero,0x64
/*    107e4:	01206025 */ 	or	$t4,$t1,$zero
/*    107e8:	318d7fff */ 	andi	$t5,$t4,0x7fff
/*    107ec:	000d7080 */ 	sll	$t6,$t5,0x2
/*    107f0:	00ae7821 */ 	addu	$t7,$a1,$t6
/*    107f4:	85f90000 */ 	lh	$t9,0x0($t7)
/*    107f8:	00aec021 */ 	addu	$t8,$a1,$t6
/*    107fc:	97020002 */ 	lhu	$v0,0x2($t8)
/*    10800:	3c0d8006 */ 	lui	$t5,%hi(audioconfigs)
/*    10804:	a7b9002c */ 	sh	$t9,0x2c($sp)
/*    10808:	93aa002c */ 	lbu	$t2,0x2c($sp)
/*    1080c:	25ade4d8 */ 	addiu	$t5,$t5,%lo(audioconfigs)
/*    10810:	00026140 */ 	sll	$t4,$v0,0x5
/*    10814:	018d2021 */ 	addu	$a0,$t4,$t5
/*    10818:	8c830010 */ 	lw	$v1,0x10($a0)
/*    1081c:	314bff7f */ 	andi	$t3,$t2,0xff7f
/*    10820:	a3ab002c */ 	sb	$t3,0x2c($sp)
/*    10824:	10c30012 */ 	beq	$a2,$v1,.L00010870
/*    10828:	87a9002c */ 	lh	$t1,0x2c($sp)
/*    1082c:	8fb80048 */ 	lw	$t8,0x48($sp)
/*    10830:	00780019 */ 	multu	$v1,$t8
/*    10834:	00007012 */ 	mflo	$t6
/*    10838:	00000000 */ 	sll	$zero,$zero,0x0
/*    1083c:	00000000 */ 	sll	$zero,$zero,0x0
/*    10840:	01c6001a */ 	div	$zero,$t6,$a2
/*    10844:	00007812 */ 	mflo	$t7
/*    10848:	afaf0048 */ 	sw	$t7,0x48($sp)
/*    1084c:	14c00002 */ 	bnez	$a2,.L00010858
/*    10850:	00000000 */ 	sll	$zero,$zero,0x0
/*    10854:	0007000d */ 	break	0x7
.L00010858:
/*    10858:	2401ffff */ 	addiu	$at,$zero,-1
/*    1085c:	14c10004 */ 	bne	$a2,$at,.L00010870
/*    10860:	3c018000 */ 	lui	$at,0x8000
/*    10864:	15c10002 */ 	bne	$t6,$at,.L00010870
/*    10868:	00000000 */ 	sll	$zero,$zero,0x0
/*    1086c:	0006000d */ 	break	0x6
.L00010870:
/*    10870:	8c820014 */ 	lw	$v0,0x14($a0)
/*    10874:	3c19800a */ 	lui	$t9,%hi(g_Vars+0x4e3)
/*    10878:	10e20002 */ 	beq	$a3,$v0,.L00010884
/*    1087c:	00000000 */ 	sll	$zero,$zero,0x0
/*    10880:	afa2004c */ 	sw	$v0,0x4c($sp)
.L00010884:
/*    10884:	9339a4a3 */ 	lbu	$t9,%lo(g_Vars+0x4e3)($t9)
/*    10888:	53200007 */ 	beqzl	$t9,.L000108a8
/*    1088c:	8fad004c */ 	lw	$t5,0x4c($sp)
/*    10890:	8c8a001c */ 	lw	$t2,0x1c($a0)
/*    10894:	314b0010 */ 	andi	$t3,$t2,0x10
/*    10898:	51600003 */ 	beqzl	$t3,.L000108a8
/*    1089c:	8fad004c */ 	lw	$t5,0x4c($sp)
/*    108a0:	afa00048 */ 	sw	$zero,0x48($sp)
.L000108a4:
/*    108a4:	8fad004c */ 	lw	$t5,0x4c($sp)
.L000108a8:
/*    108a8:	c7a40054 */ 	lwc1	$f4,0x54($sp)
/*    108ac:	8fb80058 */ 	lw	$t8,0x58($sp)
/*    108b0:	00092c00 */ 	sll	$a1,$t1,0x10
/*    108b4:	00056403 */ 	sra	$t4,$a1,0x10
/*    108b8:	3c048009 */ 	lui	$a0,%hi(var80095200)
/*    108bc:	8c845200 */ 	lw	$a0,%lo(var80095200)($a0)
/*    108c0:	01802825 */ 	or	$a1,$t4,$zero
/*    108c4:	8fa60040 */ 	lw	$a2,0x40($sp)
/*    108c8:	8fa70048 */ 	lw	$a3,0x48($sp)
/*    108cc:	afa8001c */ 	sw	$t0,0x1c($sp)
/*    108d0:	afad0010 */ 	sw	$t5,0x10($sp)
/*    108d4:	e7a40014 */ 	swc1	$f4,0x14($sp)
/*    108d8:	0c004241 */ 	jal	func00010904
/*    108dc:	afb80018 */ 	sw	$t8,0x18($sp)
/*    108e0:	afa20034 */ 	sw	$v0,0x34($sp)
/*    108e4:	00002025 */ 	or	$a0,$zero,$zero
/*    108e8:	0c01210c */ 	jal	osSetThreadPri
/*    108ec:	8fa5003c */ 	lw	$a1,0x3c($sp)
/*    108f0:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*    108f4:	8fa20034 */ 	lw	$v0,0x34($sp)
/*    108f8:	27bd0040 */ 	addiu	$sp,$sp,0x40
/*    108fc:	03e00008 */ 	jr	$ra
/*    10900:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func00010904
/*    10904:	27bdffb8 */ 	addiu	$sp,$sp,-72
/*    10908:	8fae0064 */ 	lw	$t6,0x64($sp)
/*    1090c:	2402ffff */ 	addiu	$v0,$zero,-1
/*    10910:	afbf0024 */ 	sw	$ra,0x24($sp)
/*    10914:	afa40048 */ 	sw	$a0,0x48($sp)
/*    10918:	afa5004c */ 	sw	$a1,0x4c($sp)
/*    1091c:	11c20003 */ 	beq	$t6,$v0,.L0001092c
/*    10920:	afa60050 */ 	sw	$a2,0x50($sp)
/*    10924:	10000002 */ 	beqz	$zero,.L00010930
/*    10928:	93a90067 */ 	lbu	$t1,0x67($sp)
.L0001092c:
/*    1092c:	00004825 */ 	or	$t1,$zero,$zero
.L00010930:
/*    10930:	8fa30060 */ 	lw	$v1,0x60($sp)
/*    10934:	44802000 */ 	mtc1	$zero,$f4
/*    10938:	24050001 */ 	addiu	$a1,$zero,0x1
/*    1093c:	10620003 */ 	beq	$v1,$v0,.L0001094c
/*    10940:	3c198006 */ 	lui	$t9,%hi(var8005dda0)
/*    10944:	10000001 */ 	beqz	$zero,.L0001094c
/*    10948:	306500ff */ 	andi	$a1,$v1,0xff
.L0001094c:
/*    1094c:	8fa30058 */ 	lw	$v1,0x58($sp)
/*    10950:	24080040 */ 	addiu	$t0,$zero,0x40
/*    10954:	240f7fff */ 	addiu	$t7,$zero,0x7fff
/*    10958:	10620003 */ 	beq	$v1,$v0,.L00010968
/*    1095c:	3c013f80 */ 	lui	$at,0x3f80
/*    10960:	10000001 */ 	beqz	$zero,.L00010968
/*    10964:	306800ff */ 	andi	$t0,$v1,0xff
.L00010968:
/*    10968:	50e20004 */ 	beql	$a3,$v0,.L0001097c
/*    1096c:	a7af003a */ 	sh	$t7,0x3a($sp)
/*    10970:	10000002 */ 	beqz	$zero,.L0001097c
/*    10974:	a7a7003a */ 	sh	$a3,0x3a($sp)
/*    10978:	a7af003a */ 	sh	$t7,0x3a($sp)
.L0001097c:
/*    1097c:	c7a2005c */ 	lwc1	$f2,0x5c($sp)
/*    10980:	4602203c */ 	c.lt.s	$f4,$f2
/*    10984:	00000000 */ 	sll	$zero,$zero,0x0
/*    10988:	45020004 */ 	bc1fl	.L0001099c
/*    1098c:	44810000 */ 	mtc1	$at,$f0
/*    10990:	10000003 */ 	beqz	$zero,.L000109a0
/*    10994:	46001006 */ 	mov.s	$f0,$f2
/*    10998:	44810000 */ 	mtc1	$at,$f0
.L0001099c:
/*    1099c:	00000000 */ 	sll	$zero,$zero,0x0
.L000109a0:
/*    109a0:	8f39dda0 */ 	lw	$t9,%lo(var8005dda0)($t9)
/*    109a4:	87b8004e */ 	lh	$t8,0x4e($sp)
/*    109a8:	24010037 */ 	addiu	$at,$zero,0x37
/*    109ac:	13200003 */ 	beqz	$t9,.L000109bc
/*    109b0:	a7b80044 */ 	sh	$t8,0x44($sp)
/*    109b4:	10000047 */ 	beqz	$zero,.L00010ad4
/*    109b8:	00001025 */ 	or	$v0,$zero,$zero
.L000109bc:
/*    109bc:	8fab0044 */ 	lw	$t3,0x44($sp)
/*    109c0:	97ad0044 */ 	lhu	$t5,0x44($sp)
/*    109c4:	87a40044 */ 	lh	$a0,0x44($sp)
/*    109c8:	000b67c2 */ 	srl	$t4,$t3,0x1f
/*    109cc:	11800006 */ 	beqz	$t4,.L000109e8
/*    109d0:	31ae7fff */ 	andi	$t6,$t5,0x7fff
/*    109d4:	000e7880 */ 	sll	$t7,$t6,0x2
/*    109d8:	3c048006 */ 	lui	$a0,%hi(audiodefinitions)
/*    109dc:	008f2021 */ 	addu	$a0,$a0,$t7
/*    109e0:	10000001 */ 	beqz	$zero,.L000109e8
/*    109e4:	8484dde4 */ 	lh	$a0,%lo(audiodefinitions)($a0)
.L000109e8:
/*    109e8:	308307ff */ 	andi	$v1,$a0,0x7ff
/*    109ec:	10610003 */ 	beq	$v1,$at,.L000109fc
/*    109f0:	24010009 */ 	addiu	$at,$zero,0x9
/*    109f4:	54610004 */ 	bnel	$v1,$at,.L00010a08
/*    109f8:	afa3002c */ 	sw	$v1,0x2c($sp)
.L000109fc:
/*    109fc:	10000035 */ 	beqz	$zero,.L00010ad4
/*    10a00:	00001025 */ 	or	$v0,$zero,$zero
/*    10a04:	afa3002c */ 	sw	$v1,0x2c($sp)
.L00010a08:
/*    10a08:	a7a40040 */ 	sh	$a0,0x40($sp)
/*    10a0c:	a3a5003e */ 	sb	$a1,0x3e($sp)
/*    10a10:	a3a8003d */ 	sb	$t0,0x3d($sp)
/*    10a14:	a3a9003f */ 	sb	$t1,0x3f($sp)
/*    10a18:	0c003ee8 */ 	jal	func0000fba0
/*    10a1c:	e7a00034 */ 	swc1	$f0,0x34($sp)
/*    10a20:	8fa3002c */ 	lw	$v1,0x2c($sp)
/*    10a24:	87a40040 */ 	lh	$a0,0x40($sp)
/*    10a28:	93a5003e */ 	lbu	$a1,0x3e($sp)
/*    10a2c:	93a8003d */ 	lbu	$t0,0x3d($sp)
/*    10a30:	93a9003f */ 	lbu	$t1,0x3f($sp)
/*    10a34:	8faa0050 */ 	lw	$t2,0x50($sp)
/*    10a38:	1040000b */ 	beqz	$v0,.L00010a68
/*    10a3c:	c7a00034 */ 	lwc1	$f0,0x34($sp)
/*    10a40:	97a5003a */ 	lhu	$a1,0x3a($sp)
/*    10a44:	01003025 */ 	or	$a2,$t0,$zero
/*    10a48:	0c0042b9 */ 	jal	func00010ae4
/*    10a4c:	00003825 */ 	or	$a3,$zero,$zero
/*    10a50:	8faa0050 */ 	lw	$t2,0x50($sp)
/*    10a54:	11400002 */ 	beqz	$t2,.L00010a60
/*    10a58:	00000000 */ 	sll	$zero,$zero,0x0
/*    10a5c:	ad400000 */ 	sw	$zero,0x0($t2)
.L00010a60:
/*    10a60:	1000001c */ 	beqz	$zero,.L00010ad4
/*    10a64:	00001025 */ 	or	$v0,$zero,$zero
.L00010a68:
/*    10a68:	3c188009 */ 	lui	$t8,%hi(var80094ea0)
/*    10a6c:	8f184ea0 */ 	lw	$t8,%lo(var80094ea0)($t8)
/*    10a70:	3c198009 */ 	lui	$t9,%hi(g_Is4Mb)
/*    10a74:	8fa40048 */ 	lw	$a0,0x48($sp)
/*    10a78:	0078082b */ 	sltu	$at,$v1,$t8
/*    10a7c:	10200015 */ 	beqz	$at,.L00010ad4
/*    10a80:	00001025 */ 	or	$v0,$zero,$zero
/*    10a84:	93390af0 */ 	lbu	$t9,%lo(g_Is4Mb)($t9)
/*    10a88:	24010001 */ 	addiu	$at,$zero,0x1
/*    10a8c:	97a6003a */ 	lhu	$a2,0x3a($sp)
/*    10a90:	17210003 */ 	bne	$t9,$at,.L00010aa0
/*    10a94:	01003825 */ 	or	$a3,$t0,$zero
/*    10a98:	10000002 */ 	beqz	$zero,.L00010aa4
/*    10a9c:	00001025 */ 	or	$v0,$zero,$zero
.L00010aa0:
/*    10aa0:	00a01025 */ 	or	$v0,$a1,$zero
.L00010aa4:
/*    10aa4:	00032c00 */ 	sll	$a1,$v1,0x10
/*    10aa8:	00055c03 */ 	sra	$t3,$a1,0x10
/*    10aac:	30ec007f */ 	andi	$t4,$a3,0x7f
/*    10ab0:	01803825 */ 	or	$a3,$t4,$zero
/*    10ab4:	01602825 */ 	or	$a1,$t3,$zero
/*    10ab8:	e7a00010 */ 	swc1	$f0,0x10($sp)
/*    10abc:	afa90014 */ 	sw	$t1,0x14($sp)
/*    10ac0:	afa20018 */ 	sw	$v0,0x18($sp)
/*    10ac4:	0c00ce08 */ 	jal	func00033820
/*    10ac8:	afaa001c */ 	sw	$t2,0x1c($sp)
/*    10acc:	10000002 */ 	beqz	$zero,.L00010ad8
/*    10ad0:	8fbf0024 */ 	lw	$ra,0x24($sp)
.L00010ad4:
/*    10ad4:	8fbf0024 */ 	lw	$ra,0x24($sp)
.L00010ad8:
/*    10ad8:	27bd0048 */ 	addiu	$sp,$sp,0x48
/*    10adc:	03e00008 */ 	jr	$ra
/*    10ae0:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func00010ae4
/*    10ae4:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*    10ae8:	3c188006 */ 	lui	$t8,%hi(var8005dda0)
/*    10aec:	8f18dda0 */ 	lw	$t8,%lo(var8005dda0)($t8)
/*    10af0:	00047400 */ 	sll	$t6,$a0,0x10
/*    10af4:	000e7c03 */ 	sra	$t7,$t6,0x10
/*    10af8:	afa40028 */ 	sw	$a0,0x28($sp)
/*    10afc:	01e02025 */ 	or	$a0,$t7,$zero
/*    10b00:	afbf001c */ 	sw	$ra,0x1c($sp)
/*    10b04:	afb00018 */ 	sw	$s0,0x18($sp)
/*    10b08:	afa70034 */ 	sw	$a3,0x34($sp)
/*    10b0c:	170000a3 */ 	bnez	$t8,.L00010d9c
/*    10b10:	a7af0024 */ 	sh	$t7,0x24($sp)
/*    10b14:	8fb90024 */ 	lw	$t9,0x24($sp)
/*    10b18:	3c108009 */ 	lui	$s0,%hi(var80094eb0)
/*    10b1c:	31ea7fff */ 	andi	$t2,$t7,0x7fff
/*    10b20:	001947c2 */ 	srl	$t0,$t9,0x1f
/*    10b24:	1100000a */ 	beqz	$t0,.L00010b50
/*    10b28:	26104eb0 */ 	addiu	$s0,$s0,%lo(var80094eb0)
/*    10b2c:	000a5880 */ 	sll	$t3,$t2,0x2
/*    10b30:	3c0c8006 */ 	lui	$t4,%hi(audiodefinitions)
/*    10b34:	018b6021 */ 	addu	$t4,$t4,$t3
/*    10b38:	858cdde4 */ 	lh	$t4,%lo(audiodefinitions)($t4)
/*    10b3c:	a7ac0020 */ 	sh	$t4,0x20($sp)
/*    10b40:	93ad0020 */ 	lbu	$t5,0x20($sp)
/*    10b44:	31aeff7f */ 	andi	$t6,$t5,0xff7f
/*    10b48:	10000002 */ 	beqz	$zero,.L00010b54
/*    10b4c:	a3ae0020 */ 	sb	$t6,0x20($sp)
.L00010b50:
/*    10b50:	a7a40020 */ 	sh	$a0,0x20($sp)
.L00010b54:
/*    10b54:	8e0f0004 */ 	lw	$t7,0x4($s0)
/*    10b58:	8fb80020 */ 	lw	$t8,0x20($sp)
/*    10b5c:	24010001 */ 	addiu	$at,$zero,0x1
/*    10b60:	11e00012 */ 	beqz	$t7,.L00010bac
/*    10b64:	0018c8c0 */ 	sll	$t9,$t8,0x3
/*    10b68:	00194782 */ 	srl	$t0,$t9,0x1e
/*    10b6c:	15010007 */ 	bne	$t0,$at,.L00010b8c
/*    10b70:	8faf0020 */ 	lw	$t7,0x20($sp)
/*    10b74:	8e090000 */ 	lw	$t1,0x0($s0)
/*    10b78:	24010001 */ 	addiu	$at,$zero,0x1
/*    10b7c:	000950c0 */ 	sll	$t2,$t1,0x3
/*    10b80:	000a5f82 */ 	srl	$t3,$t2,0x1e
/*    10b84:	51610086 */ 	beql	$t3,$at,.L00010da0
/*    10b88:	8fbf001c */ 	lw	$ra,0x1c($sp)
.L00010b8c:
/*    10b8c:	8e0c0000 */ 	lw	$t4,0x0($s0)
/*    10b90:	000fc0c0 */ 	sll	$t8,$t7,0x3
/*    10b94:	0018cf82 */ 	srl	$t9,$t8,0x1e
/*    10b98:	000c68c0 */ 	sll	$t5,$t4,0x3
/*    10b9c:	000d7782 */ 	srl	$t6,$t5,0x1e
/*    10ba0:	01d9082a */ 	slt	$at,$t6,$t9
/*    10ba4:	5420007e */ 	bnezl	$at,.L00010da0
/*    10ba8:	8fbf001c */ 	lw	$ra,0x1c($sp)
.L00010bac:
/*    10bac:	8fa80024 */ 	lw	$t0,0x24($sp)
/*    10bb0:	97aa0024 */ 	lhu	$t2,0x24($sp)
/*    10bb4:	00084fc2 */ 	srl	$t1,$t0,0x1f
/*    10bb8:	1120002e */ 	beqz	$t1,.L00010c74
/*    10bbc:	314b7fff */ 	andi	$t3,$t2,0x7fff
/*    10bc0:	3c028006 */ 	lui	$v0,%hi(audioconfigs)
/*    10bc4:	2442e4d8 */ 	addiu	$v0,$v0,%lo(audioconfigs)
/*    10bc8:	000b6140 */ 	sll	$t4,$t3,0x5
/*    10bcc:	004c6821 */ 	addu	$t5,$v0,$t4
/*    10bd0:	8daf0010 */ 	lw	$t7,0x10($t5)
/*    10bd4:	97a80024 */ 	lhu	$t0,0x24($sp)
/*    10bd8:	2403ffff */ 	addiu	$v1,$zero,-1
/*    10bdc:	106f000a */ 	beq	$v1,$t7,.L00010c08
/*    10be0:	31097fff */ 	andi	$t1,$t0,0x7fff
/*    10be4:	004cc021 */ 	addu	$t8,$v0,$t4
/*    10be8:	8f050010 */ 	lw	$a1,0x10($t8)
/*    10bec:	24010064 */ 	addiu	$at,$zero,0x64
/*    10bf0:	000573c0 */ 	sll	$t6,$a1,0xf
/*    10bf4:	01c57023 */ 	subu	$t6,$t6,$a1
/*    10bf8:	01c1001a */ 	div	$zero,$t6,$at
/*    10bfc:	00002812 */ 	mflo	$a1
/*    10c00:	00000000 */ 	sll	$zero,$zero,0x0
/*    10c04:	00000000 */ 	sll	$zero,$zero,0x0
.L00010c08:
/*    10c08:	00095140 */ 	sll	$t2,$t1,0x5
/*    10c0c:	004a5821 */ 	addu	$t3,$v0,$t2
/*    10c10:	8d6d0014 */ 	lw	$t5,0x14($t3)
/*    10c14:	97ac0024 */ 	lhu	$t4,0x24($sp)
/*    10c18:	3c0b800a */ 	lui	$t3,%hi(g_Vars+0x4e3)
/*    10c1c:	106d0003 */ 	beq	$v1,$t5,.L00010c2c
/*    10c20:	31987fff */ 	andi	$t8,$t4,0x7fff
/*    10c24:	004a7821 */ 	addu	$t7,$v0,$t2
/*    10c28:	8de60014 */ 	lw	$a2,0x14($t7)
.L00010c2c:
/*    10c2c:	00187140 */ 	sll	$t6,$t8,0x5
/*    10c30:	004ec821 */ 	addu	$t9,$v0,$t6
/*    10c34:	8f280014 */ 	lw	$t0,0x14($t9)
/*    10c38:	97ad0024 */ 	lhu	$t5,0x24($sp)
/*    10c3c:	004e4821 */ 	addu	$t1,$v0,$t6
/*    10c40:	10680002 */ 	beq	$v1,$t0,.L00010c4c
/*    10c44:	31aa7fff */ 	andi	$t2,$t5,0x7fff
/*    10c48:	8d260014 */ 	lw	$a2,0x14($t1)
.L00010c4c:
/*    10c4c:	916ba4a3 */ 	lbu	$t3,%lo(g_Vars+0x4e3)($t3)
/*    10c50:	000a7940 */ 	sll	$t7,$t2,0x5
/*    10c54:	004f6021 */ 	addu	$t4,$v0,$t7
/*    10c58:	51600007 */ 	beqzl	$t3,.L00010c78
/*    10c5c:	afa5002c */ 	sw	$a1,0x2c($sp)
/*    10c60:	8d98001c */ 	lw	$t8,0x1c($t4)
/*    10c64:	33190010 */ 	andi	$t9,$t8,0x10
/*    10c68:	53200003 */ 	beqzl	$t9,.L00010c78
/*    10c6c:	afa5002c */ 	sw	$a1,0x2c($sp)
/*    10c70:	00002825 */ 	or	$a1,$zero,$zero
.L00010c74:
/*    10c74:	afa5002c */ 	sw	$a1,0x2c($sp)
.L00010c78:
/*    10c78:	0c003a77 */ 	jal	func0000e9dc
/*    10c7c:	afa60030 */ 	sw	$a2,0x30($sp)
/*    10c80:	8fa8002c */ 	lw	$t0,0x2c($sp)
/*    10c84:	24017fff */ 	addiu	$at,$zero,0x7fff
/*    10c88:	97a40020 */ 	lhu	$a0,0x20($sp)
/*    10c8c:	00480019 */ 	multu	$v0,$t0
/*    10c90:	308b07ff */ 	andi	$t3,$a0,0x7ff
/*    10c94:	01602025 */ 	or	$a0,$t3,$zero
/*    10c98:	00007012 */ 	mflo	$t6
/*    10c9c:	00000000 */ 	sll	$zero,$zero,0x0
/*    10ca0:	00000000 */ 	sll	$zero,$zero,0x0
/*    10ca4:	01c1001a */ 	div	$zero,$t6,$at
/*    10ca8:	00004812 */ 	mflo	$t1
/*    10cac:	afa9002c */ 	sw	$t1,0x2c($sp)
/*    10cb0:	0fc59b90 */ 	jal	func0f166e40
/*    10cb4:	00000000 */ 	sll	$zero,$zero,0x0
/*    10cb8:	97a40020 */ 	lhu	$a0,0x20($sp)
/*    10cbc:	ae02001c */ 	sw	$v0,0x1c($s0)
/*    10cc0:	308d07ff */ 	andi	$t5,$a0,0x7ff
/*    10cc4:	0fc59b9f */ 	jal	func0f166e7c
/*    10cc8:	01a02025 */ 	or	$a0,$t5,$zero
/*    10ccc:	ae020020 */ 	sw	$v0,0x20($s0)
/*    10cd0:	8fa4002c */ 	lw	$a0,0x2c($sp)
/*    10cd4:	0c00dfc2 */ 	jal	func00037f08
/*    10cd8:	24050001 */ 	addiu	$a1,$zero,0x1
/*    10cdc:	8fa40030 */ 	lw	$a0,0x30($sp)
/*    10ce0:	0c00dfd7 */ 	jal	func00037f5c
/*    10ce4:	24050001 */ 	addiu	$a1,$zero,0x1
/*    10ce8:	8e04001c */ 	lw	$a0,0x1c($s0)
/*    10cec:	0c00df62 */ 	jal	func00037d88
/*    10cf0:	8e050020 */ 	lw	$a1,0x20($s0)
/*    10cf4:	8fa4002c */ 	lw	$a0,0x2c($sp)
/*    10cf8:	0c00dfc2 */ 	jal	func00037f08
/*    10cfc:	24050001 */ 	addiu	$a1,$zero,0x1
/*    10d00:	8fa40030 */ 	lw	$a0,0x30($sp)
/*    10d04:	0c00dfd7 */ 	jal	func00037f5c
/*    10d08:	24050001 */ 	addiu	$a1,$zero,0x1
/*    10d0c:	87aa0020 */ 	lh	$t2,0x20($sp)
/*    10d10:	24030002 */ 	addiu	$v1,$zero,0x2
/*    10d14:	240f0001 */ 	addiu	$t7,$zero,0x1
/*    10d18:	a60a0000 */ 	sh	$t2,0x0($s0)
/*    10d1c:	8e020000 */ 	lw	$v0,0x0($s0)
/*    10d20:	240cffff */ 	addiu	$t4,$zero,-1
/*    10d24:	ae0f0004 */ 	sw	$t7,0x4($s0)
/*    10d28:	0002c040 */ 	sll	$t8,$v0,0x1
/*    10d2c:	00181782 */ 	srl	$v0,$t8,0x1e
/*    10d30:	ae0c000c */ 	sw	$t4,0xc($s0)
/*    10d34:	14620004 */ 	bne	$v1,$v0,.L00010d48
/*    10d38:	ae000024 */ 	sw	$zero,0x24($s0)
/*    10d3c:	24080001 */ 	addiu	$t0,$zero,0x1
/*    10d40:	10000005 */ 	beqz	$zero,.L00010d58
/*    10d44:	ae080024 */ 	sw	$t0,0x24($s0)
.L00010d48:
/*    10d48:	24010001 */ 	addiu	$at,$zero,0x1
/*    10d4c:	54410003 */ 	bnel	$v0,$at,.L00010d5c
/*    10d50:	8fae0024 */ 	lw	$t6,0x24($sp)
/*    10d54:	ae030024 */ 	sw	$v1,0x24($s0)
.L00010d58:
/*    10d58:	8fae0024 */ 	lw	$t6,0x24($sp)
.L00010d5c:
/*    10d5c:	97ab0024 */ 	lhu	$t3,0x24($sp)
/*    10d60:	3c0f8006 */ 	lui	$t7,%hi(audioconfigs+0x1c)
/*    10d64:	000e4fc2 */ 	srl	$t1,$t6,0x1f
/*    10d68:	11200007 */ 	beqz	$t1,.L00010d88
/*    10d6c:	316d7fff */ 	andi	$t5,$t3,0x7fff
/*    10d70:	000d5140 */ 	sll	$t2,$t5,0x5
/*    10d74:	01ea7821 */ 	addu	$t7,$t7,$t2
/*    10d78:	8defe4f4 */ 	lw	$t7,%lo(audioconfigs+0x1c)($t7)
/*    10d7c:	31ec0004 */ 	andi	$t4,$t7,0x4
/*    10d80:	55800005 */ 	bnezl	$t4,.L00010d98
/*    10d84:	24080003 */ 	addiu	$t0,$zero,0x3
.L00010d88:
/*    10d88:	8fb80034 */ 	lw	$t8,0x34($sp)
/*    10d8c:	33190001 */ 	andi	$t9,$t8,0x1
/*    10d90:	13200002 */ 	beqz	$t9,.L00010d9c
/*    10d94:	24080003 */ 	addiu	$t0,$zero,0x3
.L00010d98:
/*    10d98:	ae080024 */ 	sw	$t0,0x24($s0)
.L00010d9c:
/*    10d9c:	8fbf001c */ 	lw	$ra,0x1c($sp)
.L00010da0:
/*    10da0:	8fb00018 */ 	lw	$s0,0x18($sp)
/*    10da4:	27bd0028 */ 	addiu	$sp,$sp,0x28
/*    10da8:	03e00008 */ 	jr	$ra
/*    10dac:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func00010db0
/*    10db0:	00047100 */ 	sll	$t6,$a0,0x4
/*    10db4:	01c47023 */ 	subu	$t6,$t6,$a0
/*    10db8:	000e7100 */ 	sll	$t6,$t6,0x4
/*    10dbc:	3c018006 */ 	lui	$at,%hi(var8005ddb0)
/*    10dc0:	ac2eddb0 */ 	sw	$t6,%lo(var8005ddb0)($at)
/*    10dc4:	3c018006 */ 	lui	$at,%hi(var8005ddac)
/*    10dc8:	ac20ddac */ 	sw	$zero,%lo(var8005ddac)($at)
/*    10dcc:	3c018006 */ 	lui	$at,%hi(var8005dda8)
/*    10dd0:	ac20dda8 */ 	sw	$zero,%lo(var8005dda8)($at)
/*    10dd4:	3c018006 */ 	lui	$at,%hi(var8005ddc0)
/*    10dd8:	03e00008 */ 	jr	$ra
/*    10ddc:	ac20ddc0 */ 	sw	$zero,%lo(var8005ddc0)($at)
);

GLOBAL_ASM(
glabel func00010de0
/*    10de0:	3c028006 */ 	lui	$v0,%hi(var8005ddac)
/*    10de4:	2442ddac */ 	addiu	$v0,$v0,%lo(var8005ddac)
/*    10de8:	8c4e0000 */ 	lw	$t6,0x0($v0)
/*    10dec:	2401ffff */ 	addiu	$at,$zero,-1
/*    10df0:	3c0f8006 */ 	lui	$t7,%hi(var8005ddb0)
/*    10df4:	11c10004 */ 	beq	$t6,$at,.L00010e08
/*    10df8:	00000000 */ 	sll	$zero,$zero,0x0
/*    10dfc:	8defddb0 */ 	lw	$t7,%lo(var8005ddb0)($t7)
/*    10e00:	25f80001 */ 	addiu	$t8,$t7,0x1
/*    10e04:	ac580000 */ 	sw	$t8,0x0($v0)
.L00010e08:
/*    10e08:	03e00008 */ 	jr	$ra
/*    10e0c:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func00010e10
/*    10e10:	3c038006 */ 	lui	$v1,%hi(var8005ddac)
/*    10e14:	2463ddac */ 	addiu	$v1,$v1,%lo(var8005ddac)
/*    10e18:	8c620000 */ 	lw	$v0,0x0($v1)
/*    10e1c:	27bdffc8 */ 	addiu	$sp,$sp,-56
/*    10e20:	2401ffff */ 	addiu	$at,$zero,-1
/*    10e24:	104100a1 */ 	beq	$v0,$at,.L000110ac
/*    10e28:	afbf002c */ 	sw	$ra,0x2c($sp)
/*    10e2c:	3c08800a */ 	lui	$t0,%hi(g_Vars)
/*    10e30:	25089fc0 */ 	addiu	$t0,$t0,%lo(g_Vars)
/*    10e34:	8d0e0034 */ 	lw	$t6,0x34($t0)
/*    10e38:	3c198006 */ 	lui	$t9,%hi(var8005ddb0)
/*    10e3c:	3c013f80 */ 	lui	$at,0x3f80
/*    10e40:	004ec021 */ 	addu	$t8,$v0,$t6
/*    10e44:	ac780000 */ 	sw	$t8,0x0($v1)
/*    10e48:	8f39ddb0 */ 	lw	$t9,%lo(var8005ddb0)($t9)
/*    10e4c:	44982000 */ 	mtc1	$t8,$f4
/*    10e50:	44818000 */ 	mtc1	$at,$f16
/*    10e54:	44994000 */ 	mtc1	$t9,$f8
/*    10e58:	468021a0 */ 	cvt.s.w	$f6,$f4
/*    10e5c:	3c028006 */ 	lui	$v0,%hi(var8005dda8)
/*    10e60:	3c017005 */ 	lui	$at,%hi(var70053c84)
/*    10e64:	2442dda8 */ 	addiu	$v0,$v0,%lo(var8005dda8)
/*    10e68:	468042a0 */ 	cvt.s.w	$f10,$f8
/*    10e6c:	460a3003 */ 	div.s	$f0,$f6,$f10
/*    10e70:	4610003c */ 	c.lt.s	$f0,$f16
/*    10e74:	00000000 */ 	sll	$zero,$zero,0x0
/*    10e78:	45020067 */ 	bc1fl	.L00011018
/*    10e7c:	8c460000 */ 	lw	$a2,0x0($v0)
/*    10e80:	c4323c84 */ 	lwc1	$f18,%lo(var70053c84)($at)
/*    10e84:	46120000 */ 	add.s	$f0,$f0,$f18
/*    10e88:	0fc5b364 */ 	jal	getVar80084014
/*    10e8c:	e7a00034 */ 	swc1	$f0,0x34($sp)
/*    10e90:	3c08800a */ 	lui	$t0,%hi(g_Vars)
/*    10e94:	25089fc0 */ 	addiu	$t0,$t0,%lo(g_Vars)
/*    10e98:	10400028 */ 	beqz	$v0,.L00010f3c
/*    10e9c:	c7a00034 */ 	lwc1	$f0,0x34($sp)
/*    10ea0:	3c028006 */ 	lui	$v0,%hi(var8005dda8)
/*    10ea4:	2442dda8 */ 	addiu	$v0,$v0,%lo(var8005dda8)
/*    10ea8:	8c460000 */ 	lw	$a2,0x0($v0)
/*    10eac:	00002825 */ 	or	$a1,$zero,$zero
/*    10eb0:	24070040 */ 	addiu	$a3,$zero,0x40
/*    10eb4:	18c0000b */ 	blez	$a2,.L00010ee4
/*    10eb8:	3c048006 */ 	lui	$a0,0x8006
/*    10ebc:	8d090040 */ 	lw	$t1,0x40($t0)
/*    10ec0:	00095080 */ 	sll	$t2,$t1,0x2
/*    10ec4:	01495021 */ 	addu	$t2,$t2,$t1
/*    10ec8:	000a5100 */ 	sll	$t2,$t2,0x4
/*    10ecc:	00ca5823 */ 	subu	$t3,$a2,$t2
/*    10ed0:	ac4b0000 */ 	sw	$t3,0x0($v0)
/*    10ed4:	05610003 */ 	bgez	$t3,.L00010ee4
/*    10ed8:	01603025 */ 	or	$a2,$t3,$zero
/*    10edc:	ac400000 */ 	sw	$zero,0x0($v0)
/*    10ee0:	00003025 */ 	or	$a2,$zero,$zero
.L00010ee4:
/*    10ee4:	10c0000d */ 	beqz	$a2,.L00010f1c
/*    10ee8:	240cffff */ 	addiu	$t4,$zero,-1
/*    10eec:	3c048006 */ 	lui	$a0,%hi(var8005ddc0)
/*    10ef0:	240dffff */ 	addiu	$t5,$zero,-1
/*    10ef4:	240e0001 */ 	addiu	$t6,$zero,0x1
/*    10ef8:	afae0020 */ 	sw	$t6,0x20($sp)
/*    10efc:	afad001c */ 	sw	$t5,0x1c($sp)
/*    10f00:	2484ddc0 */ 	addiu	$a0,$a0,%lo(var8005ddc0)
/*    10f04:	afac0010 */ 	sw	$t4,0x10($sp)
/*    10f08:	e7a00014 */ 	swc1	$f0,0x14($sp)
/*    10f0c:	0c004128 */ 	jal	func000104a0
/*    10f10:	afa00018 */ 	sw	$zero,0x18($sp)
/*    10f14:	10000066 */ 	beqz	$zero,.L000110b0
/*    10f18:	8fbf002c */ 	lw	$ra,0x2c($sp)
.L00010f1c:
/*    10f1c:	8c84ddc0 */ 	lw	$a0,-8768($a0)
/*    10f20:	50800063 */ 	beqzl	$a0,.L000110b0
/*    10f24:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*    10f28:	0c00cec9 */ 	jal	func00033b24
/*    10f2c:	00000000 */ 	sll	$zero,$zero,0x0
/*    10f30:	3c018006 */ 	lui	$at,%hi(var8005ddc0)
/*    10f34:	1000005d */ 	beqz	$zero,.L000110ac
/*    10f38:	ac20ddc0 */ 	sw	$zero,%lo(var8005ddc0)($at)
.L00010f3c:
/*    10f3c:	3c0f8006 */ 	lui	$t7,%hi(var8005ddc0)
/*    10f40:	8defddc0 */ 	lw	$t7,%lo(var8005ddc0)($t7)
/*    10f44:	3c048009 */ 	lui	$a0,%hi(var80095200)
/*    10f48:	24050608 */ 	addiu	$a1,$zero,0x608
/*    10f4c:	15e00012 */ 	bnez	$t7,.L00010f98
/*    10f50:	3c068006 */ 	lui	$a2,%hi(var8005ddc0)
/*    10f54:	3c01bf80 */ 	lui	$at,0xbf80
/*    10f58:	44812000 */ 	mtc1	$at,$f4
/*    10f5c:	2418ffff */ 	addiu	$t8,$zero,-1
/*    10f60:	2419ffff */ 	addiu	$t9,$zero,-1
/*    10f64:	2409ffff */ 	addiu	$t1,$zero,-1
/*    10f68:	afa9001c */ 	sw	$t1,0x1c($sp)
/*    10f6c:	afb90018 */ 	sw	$t9,0x18($sp)
/*    10f70:	afb80010 */ 	sw	$t8,0x10($sp)
/*    10f74:	8c845200 */ 	lw	$a0,%lo(var80095200)($a0)
/*    10f78:	24c6ddc0 */ 	addiu	$a2,$a2,%lo(var8005ddc0)
/*    10f7c:	2407ffff */ 	addiu	$a3,$zero,-1
/*    10f80:	e7a00034 */ 	swc1	$f0,0x34($sp)
/*    10f84:	0c004241 */ 	jal	func00010904
/*    10f88:	e7a40014 */ 	swc1	$f4,0x14($sp)
/*    10f8c:	3c08800a */ 	lui	$t0,%hi(g_Vars)
/*    10f90:	25089fc0 */ 	addiu	$t0,$t0,%lo(g_Vars)
/*    10f94:	c7a00034 */ 	lwc1	$f0,0x34($sp)
.L00010f98:
/*    10f98:	3c028006 */ 	lui	$v0,%hi(var8005dda8)
/*    10f9c:	2442dda8 */ 	addiu	$v0,$v0,%lo(var8005dda8)
/*    10fa0:	8c460000 */ 	lw	$a2,0x0($v0)
/*    10fa4:	3c048006 */ 	lui	$a0,%hi(var8005ddc0)
/*    10fa8:	2484ddc0 */ 	addiu	$a0,$a0,%lo(var8005ddc0)
/*    10fac:	28c14e20 */ 	slti	$at,$a2,0x4e20
/*    10fb0:	1020000c */ 	beqz	$at,.L00010fe4
/*    10fb4:	00002825 */ 	or	$a1,$zero,$zero
/*    10fb8:	8d0a0040 */ 	lw	$t2,0x40($t0)
/*    10fbc:	000a5880 */ 	sll	$t3,$t2,0x2
/*    10fc0:	016a5821 */ 	addu	$t3,$t3,$t2
/*    10fc4:	000b58c0 */ 	sll	$t3,$t3,0x3
/*    10fc8:	00cb6021 */ 	addu	$t4,$a2,$t3
/*    10fcc:	29814e21 */ 	slti	$at,$t4,0x4e21
/*    10fd0:	ac4c0000 */ 	sw	$t4,0x0($v0)
/*    10fd4:	14200003 */ 	bnez	$at,.L00010fe4
/*    10fd8:	01803025 */ 	or	$a2,$t4,$zero
/*    10fdc:	24064e20 */ 	addiu	$a2,$zero,0x4e20
/*    10fe0:	ac460000 */ 	sw	$a2,0x0($v0)
.L00010fe4:
/*    10fe4:	240effff */ 	addiu	$t6,$zero,-1
/*    10fe8:	240fffff */ 	addiu	$t7,$zero,-1
/*    10fec:	24180001 */ 	addiu	$t8,$zero,0x1
/*    10ff0:	afb80020 */ 	sw	$t8,0x20($sp)
/*    10ff4:	afaf001c */ 	sw	$t7,0x1c($sp)
/*    10ff8:	afae0010 */ 	sw	$t6,0x10($sp)
/*    10ffc:	24070040 */ 	addiu	$a3,$zero,0x40
/*    11000:	e7a00014 */ 	swc1	$f0,0x14($sp)
/*    11004:	0c004128 */ 	jal	func000104a0
/*    11008:	afa00018 */ 	sw	$zero,0x18($sp)
/*    1100c:	10000028 */ 	beqz	$zero,.L000110b0
/*    11010:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*    11014:	8c460000 */ 	lw	$a2,0x0($v0)
.L00011018:
/*    11018:	00002825 */ 	or	$a1,$zero,$zero
/*    1101c:	24070040 */ 	addiu	$a3,$zero,0x40
/*    11020:	18c0000b */ 	blez	$a2,.L00011050
/*    11024:	3c048006 */ 	lui	$a0,0x8006
/*    11028:	8d190040 */ 	lw	$t9,0x40($t0)
/*    1102c:	00194880 */ 	sll	$t1,$t9,0x2
/*    11030:	01394821 */ 	addu	$t1,$t1,$t9
/*    11034:	00094900 */ 	sll	$t1,$t1,0x4
/*    11038:	00c95023 */ 	subu	$t2,$a2,$t1
/*    1103c:	ac4a0000 */ 	sw	$t2,0x0($v0)
/*    11040:	05410003 */ 	bgez	$t2,.L00011050
/*    11044:	01403025 */ 	or	$a2,$t2,$zero
/*    11048:	ac400000 */ 	sw	$zero,0x0($v0)
/*    1104c:	00003025 */ 	or	$a2,$zero,$zero
.L00011050:
/*    11050:	10c0000f */ 	beqz	$a2,.L00011090
/*    11054:	240bffff */ 	addiu	$t3,$zero,-1
/*    11058:	3c01bf80 */ 	lui	$at,0xbf80
/*    1105c:	44814000 */ 	mtc1	$at,$f8
/*    11060:	3c048006 */ 	lui	$a0,%hi(var8005ddc0)
/*    11064:	240cffff */ 	addiu	$t4,$zero,-1
/*    11068:	240d0001 */ 	addiu	$t5,$zero,0x1
/*    1106c:	afad0020 */ 	sw	$t5,0x20($sp)
/*    11070:	afac001c */ 	sw	$t4,0x1c($sp)
/*    11074:	2484ddc0 */ 	addiu	$a0,$a0,%lo(var8005ddc0)
/*    11078:	afab0010 */ 	sw	$t3,0x10($sp)
/*    1107c:	afa00018 */ 	sw	$zero,0x18($sp)
/*    11080:	0c004128 */ 	jal	func000104a0
/*    11084:	e7a80014 */ 	swc1	$f8,0x14($sp)
/*    11088:	10000009 */ 	beqz	$zero,.L000110b0
/*    1108c:	8fbf002c */ 	lw	$ra,0x2c($sp)
.L00011090:
/*    11090:	8c84ddc0 */ 	lw	$a0,-8768($a0)
/*    11094:	50800006 */ 	beqzl	$a0,.L000110b0
/*    11098:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*    1109c:	0c00cec9 */ 	jal	func00033b24
/*    110a0:	00000000 */ 	sll	$zero,$zero,0x0
/*    110a4:	3c018006 */ 	lui	$at,%hi(var8005ddc0)
/*    110a8:	ac20ddc0 */ 	sw	$zero,%lo(var8005ddc0)($at)
.L000110ac:
/*    110ac:	8fbf002c */ 	lw	$ra,0x2c($sp)
.L000110b0:
/*    110b0:	27bd0038 */ 	addiu	$sp,$sp,0x38
/*    110b4:	03e00008 */ 	jr	$ra
/*    110b8:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func000110bc
/*    110bc:	00047100 */ 	sll	$t6,$a0,0x4
/*    110c0:	01c47023 */ 	subu	$t6,$t6,$a0
/*    110c4:	000e7100 */ 	sll	$t6,$t6,0x4
/*    110c8:	3c018006 */ 	lui	$at,%hi(var8005ddbc)
/*    110cc:	ac2eddbc */ 	sw	$t6,%lo(var8005ddbc)($at)
/*    110d0:	3c018006 */ 	lui	$at,%hi(var8005ddb8)
/*    110d4:	ac20ddb8 */ 	sw	$zero,%lo(var8005ddb8)($at)
/*    110d8:	3c018006 */ 	lui	$at,%hi(var8005ddb4)
/*    110dc:	ac20ddb4 */ 	sw	$zero,%lo(var8005ddb4)($at)
/*    110e0:	3c018006 */ 	lui	$at,%hi(var8005ddc4)
/*    110e4:	03e00008 */ 	jr	$ra
/*    110e8:	ac20ddc4 */ 	sw	$zero,%lo(var8005ddc4)($at)
);

GLOBAL_ASM(
glabel func000110ec
/*    110ec:	3c028006 */ 	lui	$v0,%hi(var8005ddb8)
/*    110f0:	2442ddb8 */ 	addiu	$v0,$v0,%lo(var8005ddb8)
/*    110f4:	8c4e0000 */ 	lw	$t6,0x0($v0)
/*    110f8:	2401ffff */ 	addiu	$at,$zero,-1
/*    110fc:	3c0f8006 */ 	lui	$t7,%hi(var8005ddbc)
/*    11100:	11c10004 */ 	beq	$t6,$at,.L00011114
/*    11104:	00000000 */ 	sll	$zero,$zero,0x0
/*    11108:	8defddbc */ 	lw	$t7,%lo(var8005ddbc)($t7)
/*    1110c:	25f80001 */ 	addiu	$t8,$t7,0x1
/*    11110:	ac580000 */ 	sw	$t8,0x0($v0)
.L00011114:
/*    11114:	03e00008 */ 	jr	$ra
/*    11118:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0001111c
/*    1111c:	3c038006 */ 	lui	$v1,%hi(var8005ddb8)
/*    11120:	2463ddb8 */ 	addiu	$v1,$v1,%lo(var8005ddb8)
/*    11124:	8c620000 */ 	lw	$v0,0x0($v1)
/*    11128:	27bdffc8 */ 	addiu	$sp,$sp,-56
/*    1112c:	2401ffff */ 	addiu	$at,$zero,-1
/*    11130:	104100b5 */ 	beq	$v0,$at,.L00011408
/*    11134:	afbf002c */ 	sw	$ra,0x2c($sp)
/*    11138:	3c08800a */ 	lui	$t0,%hi(g_Vars)
/*    1113c:	25089fc0 */ 	addiu	$t0,$t0,%lo(g_Vars)
/*    11140:	8d0e0034 */ 	lw	$t6,0x34($t0)
/*    11144:	3c198006 */ 	lui	$t9,%hi(var8005ddbc)
/*    11148:	3c013f80 */ 	lui	$at,0x3f80
/*    1114c:	004ec021 */ 	addu	$t8,$v0,$t6
/*    11150:	ac780000 */ 	sw	$t8,0x0($v1)
/*    11154:	8f39ddbc */ 	lw	$t9,%lo(var8005ddbc)($t9)
/*    11158:	44982000 */ 	mtc1	$t8,$f4
/*    1115c:	44816000 */ 	mtc1	$at,$f12
/*    11160:	44994000 */ 	mtc1	$t9,$f8
/*    11164:	468021a0 */ 	cvt.s.w	$f6,$f4
/*    11168:	3c028006 */ 	lui	$v0,%hi(var8005ddb4)
/*    1116c:	3c017005 */ 	lui	$at,%hi(var70053c88)
/*    11170:	2442ddb4 */ 	addiu	$v0,$v0,%lo(var8005ddb4)
/*    11174:	468042a0 */ 	cvt.s.w	$f10,$f8
/*    11178:	460a3003 */ 	div.s	$f0,$f6,$f10
/*    1117c:	460c003c */ 	c.lt.s	$f0,$f12
/*    11180:	00000000 */ 	sll	$zero,$zero,0x0
/*    11184:	4502007b */ 	bc1fl	.L00011374
/*    11188:	8c460000 */ 	lw	$a2,0x0($v0)
/*    1118c:	c4223c88 */ 	lwc1	$f2,%lo(var70053c88)($at)
/*    11190:	3c017005 */ 	lui	$at,%hi(var70053c94)
/*    11194:	4602003c */ 	c.lt.s	$f0,$f2
/*    11198:	00000000 */ 	sll	$zero,$zero,0x0
/*    1119c:	4502000a */ 	bc1fl	.L000111c8
/*    111a0:	46020181 */ 	sub.s	$f6,$f0,$f2
/*    111a4:	46020403 */ 	div.s	$f16,$f0,$f2
/*    111a8:	3c017005 */ 	lui	$at,%hi(var70053c8c)
/*    111ac:	c4323c8c */ 	lwc1	$f18,%lo(var70053c8c)($at)
/*    111b0:	3c017005 */ 	lui	$at,%hi(var70053c90)
/*    111b4:	c4283c90 */ 	lwc1	$f8,%lo(var70053c90)($at)
/*    111b8:	46128102 */ 	mul.s	$f4,$f16,$f18
/*    111bc:	10000008 */ 	beqz	$zero,.L000111e0
/*    111c0:	46082000 */ 	add.s	$f0,$f4,$f8
/*    111c4:	46020181 */ 	sub.s	$f6,$f0,$f2
.L000111c8:
/*    111c8:	c42a3c94 */ 	lwc1	$f10,%lo(var70053c94)($at)
/*    111cc:	3c017005 */ 	lui	$at,%hi(var70053c98)
/*    111d0:	c4323c98 */ 	lwc1	$f18,%lo(var70053c98)($at)
/*    111d4:	460a3403 */ 	div.s	$f16,$f6,$f10
/*    111d8:	46128102 */ 	mul.s	$f4,$f16,$f18
/*    111dc:	460c2000 */ 	add.s	$f0,$f4,$f12
.L000111e0:
/*    111e0:	0fc5b364 */ 	jal	getVar80084014
/*    111e4:	e7a00034 */ 	swc1	$f0,0x34($sp)
/*    111e8:	3c08800a */ 	lui	$t0,%hi(g_Vars)
/*    111ec:	25089fc0 */ 	addiu	$t0,$t0,%lo(g_Vars)
/*    111f0:	10400028 */ 	beqz	$v0,.L00011294
/*    111f4:	c7a00034 */ 	lwc1	$f0,0x34($sp)
/*    111f8:	3c028006 */ 	lui	$v0,%hi(var8005ddb4)
/*    111fc:	2442ddb4 */ 	addiu	$v0,$v0,%lo(var8005ddb4)
/*    11200:	8c460000 */ 	lw	$a2,0x0($v0)
/*    11204:	00002825 */ 	or	$a1,$zero,$zero
/*    11208:	24070040 */ 	addiu	$a3,$zero,0x40
/*    1120c:	18c0000b */ 	blez	$a2,.L0001123c
/*    11210:	3c048006 */ 	lui	$a0,0x8006
/*    11214:	8d090040 */ 	lw	$t1,0x40($t0)
/*    11218:	00095100 */ 	sll	$t2,$t1,0x4
/*    1121c:	01495023 */ 	subu	$t2,$t2,$t1
/*    11220:	000a50c0 */ 	sll	$t2,$t2,0x3
/*    11224:	00ca5823 */ 	subu	$t3,$a2,$t2
/*    11228:	ac4b0000 */ 	sw	$t3,0x0($v0)
/*    1122c:	05610003 */ 	bgez	$t3,.L0001123c
/*    11230:	01603025 */ 	or	$a2,$t3,$zero
/*    11234:	ac400000 */ 	sw	$zero,0x0($v0)
/*    11238:	00003025 */ 	or	$a2,$zero,$zero
.L0001123c:
/*    1123c:	10c0000d */ 	beqz	$a2,.L00011274
/*    11240:	240cffff */ 	addiu	$t4,$zero,-1
/*    11244:	3c048006 */ 	lui	$a0,%hi(var8005ddc4)
/*    11248:	240dffff */ 	addiu	$t5,$zero,-1
/*    1124c:	240e0001 */ 	addiu	$t6,$zero,0x1
/*    11250:	afae0020 */ 	sw	$t6,0x20($sp)
/*    11254:	afad001c */ 	sw	$t5,0x1c($sp)
/*    11258:	2484ddc4 */ 	addiu	$a0,$a0,%lo(var8005ddc4)
/*    1125c:	afac0010 */ 	sw	$t4,0x10($sp)
/*    11260:	e7a00014 */ 	swc1	$f0,0x14($sp)
/*    11264:	0c004128 */ 	jal	func000104a0
/*    11268:	afa00018 */ 	sw	$zero,0x18($sp)
/*    1126c:	10000067 */ 	beqz	$zero,.L0001140c
/*    11270:	8fbf002c */ 	lw	$ra,0x2c($sp)
.L00011274:
/*    11274:	8c84ddc4 */ 	lw	$a0,-8764($a0)
/*    11278:	50800064 */ 	beqzl	$a0,.L0001140c
/*    1127c:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*    11280:	0c00cec9 */ 	jal	func00033b24
/*    11284:	00000000 */ 	sll	$zero,$zero,0x0
/*    11288:	3c018006 */ 	lui	$at,%hi(var8005ddc4)
/*    1128c:	1000005e */ 	beqz	$zero,.L00011408
/*    11290:	ac20ddc4 */ 	sw	$zero,%lo(var8005ddc4)($at)
.L00011294:
/*    11294:	3c0f8006 */ 	lui	$t7,%hi(var8005ddc4)
/*    11298:	8defddc4 */ 	lw	$t7,%lo(var8005ddc4)($t7)
/*    1129c:	3c048009 */ 	lui	$a0,%hi(var80095200)
/*    112a0:	24050609 */ 	addiu	$a1,$zero,0x609
/*    112a4:	15e00012 */ 	bnez	$t7,.L000112f0
/*    112a8:	3c068006 */ 	lui	$a2,%hi(var8005ddc4)
/*    112ac:	3c01bf80 */ 	lui	$at,0xbf80
/*    112b0:	44814000 */ 	mtc1	$at,$f8
/*    112b4:	2418ffff */ 	addiu	$t8,$zero,-1
/*    112b8:	2419ffff */ 	addiu	$t9,$zero,-1
/*    112bc:	2409ffff */ 	addiu	$t1,$zero,-1
/*    112c0:	afa9001c */ 	sw	$t1,0x1c($sp)
/*    112c4:	afb90018 */ 	sw	$t9,0x18($sp)
/*    112c8:	afb80010 */ 	sw	$t8,0x10($sp)
/*    112cc:	8c845200 */ 	lw	$a0,%lo(var80095200)($a0)
/*    112d0:	24c6ddc4 */ 	addiu	$a2,$a2,%lo(var8005ddc4)
/*    112d4:	2407ffff */ 	addiu	$a3,$zero,-1
/*    112d8:	e7a00034 */ 	swc1	$f0,0x34($sp)
/*    112dc:	0c004241 */ 	jal	func00010904
/*    112e0:	e7a80014 */ 	swc1	$f8,0x14($sp)
/*    112e4:	3c08800a */ 	lui	$t0,%hi(g_Vars)
/*    112e8:	25089fc0 */ 	addiu	$t0,$t0,%lo(g_Vars)
/*    112ec:	c7a00034 */ 	lwc1	$f0,0x34($sp)
.L000112f0:
/*    112f0:	3c028006 */ 	lui	$v0,%hi(var8005ddb4)
/*    112f4:	2442ddb4 */ 	addiu	$v0,$v0,%lo(var8005ddb4)
/*    112f8:	8c460000 */ 	lw	$a2,0x0($v0)
/*    112fc:	3c048006 */ 	lui	$a0,%hi(var8005ddc4)
/*    11300:	2484ddc4 */ 	addiu	$a0,$a0,%lo(var8005ddc4)
/*    11304:	28c17fff */ 	slti	$at,$a2,0x7fff
/*    11308:	1020000d */ 	beqz	$at,.L00011340
/*    1130c:	00002825 */ 	or	$a1,$zero,$zero
/*    11310:	8d0a0040 */ 	lw	$t2,0x40($t0)
/*    11314:	34018000 */ 	dli	$at,0x8000
/*    11318:	000a5880 */ 	sll	$t3,$t2,0x2
/*    1131c:	016a5821 */ 	addu	$t3,$t3,$t2
/*    11320:	000b58c0 */ 	sll	$t3,$t3,0x3
/*    11324:	00cb6021 */ 	addu	$t4,$a2,$t3
/*    11328:	0181082a */ 	slt	$at,$t4,$at
/*    1132c:	ac4c0000 */ 	sw	$t4,0x0($v0)
/*    11330:	14200003 */ 	bnez	$at,.L00011340
/*    11334:	01803025 */ 	or	$a2,$t4,$zero
/*    11338:	24067fff */ 	addiu	$a2,$zero,0x7fff
/*    1133c:	ac460000 */ 	sw	$a2,0x0($v0)
.L00011340:
/*    11340:	240effff */ 	addiu	$t6,$zero,-1
/*    11344:	240fffff */ 	addiu	$t7,$zero,-1
/*    11348:	24180001 */ 	addiu	$t8,$zero,0x1
/*    1134c:	afb80020 */ 	sw	$t8,0x20($sp)
/*    11350:	afaf001c */ 	sw	$t7,0x1c($sp)
/*    11354:	afae0010 */ 	sw	$t6,0x10($sp)
/*    11358:	24070040 */ 	addiu	$a3,$zero,0x40
/*    1135c:	e7a00014 */ 	swc1	$f0,0x14($sp)
/*    11360:	0c004128 */ 	jal	func000104a0
/*    11364:	afa00018 */ 	sw	$zero,0x18($sp)
/*    11368:	10000028 */ 	beqz	$zero,.L0001140c
/*    1136c:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*    11370:	8c460000 */ 	lw	$a2,0x0($v0)
.L00011374:
/*    11374:	00002825 */ 	or	$a1,$zero,$zero
/*    11378:	24070040 */ 	addiu	$a3,$zero,0x40
/*    1137c:	18c0000b */ 	blez	$a2,.L000113ac
/*    11380:	3c048006 */ 	lui	$a0,0x8006
/*    11384:	8d190040 */ 	lw	$t9,0x40($t0)
/*    11388:	00194900 */ 	sll	$t1,$t9,0x4
/*    1138c:	01394823 */ 	subu	$t1,$t1,$t9
/*    11390:	000948c0 */ 	sll	$t1,$t1,0x3
/*    11394:	00c95023 */ 	subu	$t2,$a2,$t1
/*    11398:	ac4a0000 */ 	sw	$t2,0x0($v0)
/*    1139c:	05410003 */ 	bgez	$t2,.L000113ac
/*    113a0:	01403025 */ 	or	$a2,$t2,$zero
/*    113a4:	ac400000 */ 	sw	$zero,0x0($v0)
/*    113a8:	00003025 */ 	or	$a2,$zero,$zero
.L000113ac:
/*    113ac:	10c0000f */ 	beqz	$a2,.L000113ec
/*    113b0:	240bffff */ 	addiu	$t3,$zero,-1
/*    113b4:	3c01bf80 */ 	lui	$at,0xbf80
/*    113b8:	44813000 */ 	mtc1	$at,$f6
/*    113bc:	3c048006 */ 	lui	$a0,%hi(var8005ddc4)
/*    113c0:	240cffff */ 	addiu	$t4,$zero,-1
/*    113c4:	240d0001 */ 	addiu	$t5,$zero,0x1
/*    113c8:	afad0020 */ 	sw	$t5,0x20($sp)
/*    113cc:	afac001c */ 	sw	$t4,0x1c($sp)
/*    113d0:	2484ddc4 */ 	addiu	$a0,$a0,%lo(var8005ddc4)
/*    113d4:	afab0010 */ 	sw	$t3,0x10($sp)
/*    113d8:	afa00018 */ 	sw	$zero,0x18($sp)
/*    113dc:	0c004128 */ 	jal	func000104a0
/*    113e0:	e7a60014 */ 	swc1	$f6,0x14($sp)
/*    113e4:	10000009 */ 	beqz	$zero,.L0001140c
/*    113e8:	8fbf002c */ 	lw	$ra,0x2c($sp)
.L000113ec:
/*    113ec:	8c84ddc4 */ 	lw	$a0,-8764($a0)
/*    113f0:	50800006 */ 	beqzl	$a0,.L0001140c
/*    113f4:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*    113f8:	0c00cec9 */ 	jal	func00033b24
/*    113fc:	00000000 */ 	sll	$zero,$zero,0x0
/*    11400:	3c018006 */ 	lui	$at,%hi(var8005ddc4)
/*    11404:	ac20ddc4 */ 	sw	$zero,%lo(var8005ddc4)($at)
.L00011408:
/*    11408:	8fbf002c */ 	lw	$ra,0x2c($sp)
.L0001140c:
/*    1140c:	27bd0038 */ 	addiu	$sp,$sp,0x38
/*    11410:	03e00008 */ 	jr	$ra
/*    11414:	00000000 */ 	sll	$zero,$zero,0x0
/*    11418:	00000000 */ 	sll	$zero,$zero,0x0
/*    1141c:	00000000 */ 	sll	$zero,$zero,0x0
);
