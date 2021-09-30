#include <ultra64.h>
#include "constants.h"
#include "game/camdraw.h"
#include "game/game_0b3350.h"
#include "game/game_0f09f0.h"
#include "game/stubs/game_102230.h"
#include "game/bg.h"
#include "game/lang.h"
#include "game/pak/pak.h"
#include "game/splat.h"
#include "game/utils.h"
#include "bss.h"
#include "lib/main.h"
#include "lib/memory.h"
#include "lib/lib_126b0.h"
#include "lib/rng.h"
#include "lib/lib_16110.h"
#include "lib/libc/ll.h"
#include "data.h"
#include "types.h"

struct var800a45a0 *var800a45a0;
u32 var800a45a4;
u32 var800a45a8;
u32 var800a45ac;
u32 var800a45b0;
u32 var800a45b4;
u32 var800a45b8;
u32 var800a45bc;

const char var7f1b6050[] = "Init";
const char var7f1b6058[] = "Start Header Read";
const char var7f1b606c[] = "Header Read Done";
const char var7f1b6080[] = "Null";
const char var7f1b6088[] = "Exit 1";
const char var7f1b6090[] = "Exit 2";
const char var7f1b6098[] = "Exit 3";

const u32 var7f1b60a0[] = {0x00000000};
const u32 var7f1b60a4[] = {0x00000000};
const u32 var7f1b60a8[] = {0x00000000};
const u32 var7f1b60ac[] = {0x00000001};
const u32 var7f1b60b0[] = {0x00000001};
const u32 var7f1b60b4[] = {0x00000000};
const u32 var7f1b60b8[] = {0x00000002};
const u32 var7f1b60bc[] = {0x00000000};
const u32 var7f1b60c0[] = {0x00000001};
const u32 var7f1b60c4[] = {0x00000001};
const u32 var7f1b60c8[] = {0x00000000};
const u32 var7f1b60cc[] = {0x00000002};
const u32 var7f1b60d0[] = {0x00000000};
const u32 var7f1b60d4[] = {0x00000003};
const u32 var7f1b60d8[] = {0x00000001};
const u32 var7f1b60dc[] = {0x00000002};
const u32 var7f1b60e0[] = {0x00000002};
const u32 var7f1b60e4[] = {0x00000001};
const u32 var7f1b60e8[] = {0x00000003};
const u32 var7f1b60ec[] = {0x00000000};
const u32 var7f1b60f0[] = {0x00000004};
const u32 var7f1b60f4[] = {0x00000000};
const u32 var7f1b60f8[] = {0x00000003};
const u32 var7f1b60fc[] = {0x00000001};
const u32 var7f1b6100[] = {0x00000002};
const u32 var7f1b6104[] = {0x00000002};
const u32 var7f1b6108[] = {0x00000001};
const u32 var7f1b610c[] = {0x00000003};
const u32 var7f1b6110[] = {0x00000000};
const u32 var7f1b6114[] = {0x00000004};
const u32 var7f1b6118[] = {0x00000000};
const u32 var7f1b611c[] = {0x00000005};
const u32 var7f1b6120[] = {0x00000001};
const u32 var7f1b6124[] = {0x00000004};
const u32 var7f1b6128[] = {0x00000002};
const u32 var7f1b612c[] = {0x00000003};
const u32 var7f1b6130[] = {0x00000003};
const u32 var7f1b6134[] = {0x00000002};
const u32 var7f1b6138[] = {0x00000004};
const u32 var7f1b613c[] = {0x00000001};
const u32 var7f1b6140[] = {0x00000005};
const u32 var7f1b6144[] = {0x00000000};
const u32 var7f1b6148[] = {0x00000006};
const u32 var7f1b614c[] = {0x00000000};
const u32 var7f1b6150[] = {0x00000005};
const u32 var7f1b6154[] = {0x00000001};
const u32 var7f1b6158[] = {0x00000004};
const u32 var7f1b615c[] = {0x00000002};
const u32 var7f1b6160[] = {0x00000003};
const u32 var7f1b6164[] = {0x00000003};
const u32 var7f1b6168[] = {0x00000002};
const u32 var7f1b616c[] = {0x00000004};
const u32 var7f1b6170[] = {0x00000001};
const u32 var7f1b6174[] = {0x00000005};
const u32 var7f1b6178[] = {0x00000000};
const u32 var7f1b617c[] = {0x00000006};
const u32 var7f1b6180[] = {0x00000000};
const u32 var7f1b6184[] = {0x00000007};
const u32 var7f1b6188[] = {0x00000001};
const u32 var7f1b618c[] = {0x00000006};
const u32 var7f1b6190[] = {0x00000002};
const u32 var7f1b6194[] = {0x00000005};
const u32 var7f1b6198[] = {0x00000003};
const u32 var7f1b619c[] = {0x00000004};
const u32 var7f1b61a0[] = {0x00000004};
const u32 var7f1b61a4[] = {0x00000003};
const u32 var7f1b61a8[] = {0x00000005};
const u32 var7f1b61ac[] = {0x00000002};
const u32 var7f1b61b0[] = {0x00000006};
const u32 var7f1b61b4[] = {0x00000001};
const u32 var7f1b61b8[] = {0x00000007};
const u32 var7f1b61bc[] = {0x00000000};
const u32 var7f1b61c0[] = {0x00000007};
const u32 var7f1b61c4[] = {0x00000001};
const u32 var7f1b61c8[] = {0x00000006};
const u32 var7f1b61cc[] = {0x00000002};
const u32 var7f1b61d0[] = {0x00000005};
const u32 var7f1b61d4[] = {0x00000003};
const u32 var7f1b61d8[] = {0x00000004};
const u32 var7f1b61dc[] = {0x00000004};
const u32 var7f1b61e0[] = {0x00000003};
const u32 var7f1b61e4[] = {0x00000005};
const u32 var7f1b61e8[] = {0x00000002};
const u32 var7f1b61ec[] = {0x00000006};
const u32 var7f1b61f0[] = {0x00000001};
const u32 var7f1b61f4[] = {0x00000007};
const u32 var7f1b61f8[] = {0x00000002};
const u32 var7f1b61fc[] = {0x00000007};
const u32 var7f1b6200[] = {0x00000003};
const u32 var7f1b6204[] = {0x00000006};
const u32 var7f1b6208[] = {0x00000004};
const u32 var7f1b620c[] = {0x00000005};
const u32 var7f1b6210[] = {0x00000005};
const u32 var7f1b6214[] = {0x00000004};
const u32 var7f1b6218[] = {0x00000006};
const u32 var7f1b621c[] = {0x00000003};
const u32 var7f1b6220[] = {0x00000007};
const u32 var7f1b6224[] = {0x00000002};
const u32 var7f1b6228[] = {0x00000007};
const u32 var7f1b622c[] = {0x00000003};
const u32 var7f1b6230[] = {0x00000006};
const u32 var7f1b6234[] = {0x00000004};
const u32 var7f1b6238[] = {0x00000005};
const u32 var7f1b623c[] = {0x00000005};
const u32 var7f1b6240[] = {0x00000004};
const u32 var7f1b6244[] = {0x00000006};
const u32 var7f1b6248[] = {0x00000003};
const u32 var7f1b624c[] = {0x00000007};
const u32 var7f1b6250[] = {0x00000004};
const u32 var7f1b6254[] = {0x00000007};
const u32 var7f1b6258[] = {0x00000005};
const u32 var7f1b625c[] = {0x00000006};
const u32 var7f1b6260[] = {0x00000006};
const u32 var7f1b6264[] = {0x00000005};
const u32 var7f1b6268[] = {0x00000007};
const u32 var7f1b626c[] = {0x00000004};
const u32 var7f1b6270[] = {0x00000007};
const u32 var7f1b6274[] = {0x00000005};
const u32 var7f1b6278[] = {0x00000006};
const u32 var7f1b627c[] = {0x00000006};
const u32 var7f1b6280[] = {0x00000005};
const u32 var7f1b6284[] = {0x00000007};
const u32 var7f1b6288[] = {0x00000006};
const u32 var7f1b628c[] = {0x00000007};
const u32 var7f1b6290[] = {0x00000007};
const u32 var7f1b6294[] = {0x00000006};
const u32 var7f1b6298[] = {0x00000007};
const u32 var7f1b629c[] = {0x00000007};
const u32 var7f1b62a0[] = {0x00000000};
const u32 var7f1b62a4[] = {0xffffffff};
const u32 var7f1b62a8[] = {0xdc9785ff};
const u32 var7f1b62ac[] = {0xdc917bff};
const u32 var7f1b62b0[] = {0xdd8d71ff};
const u32 var7f1b62b4[] = {0xdd8367ff};
const u32 var7f1b62b8[] = {0xdf795dff};
const u32 var7f1b62bc[] = {0xdf7953ff};
const u32 var7f1b62c0[] = {0x00000000};
const u32 var7f1b62c4[] = {0xffffffff};
const u32 var7f1b62c8[] = {0xa67b6dff};
const u32 var7f1b62cc[] = {0xa16152ff};
const u32 var7f1b62d0[] = {0x8c6741ff};
const u32 var7f1b62d4[] = {0x81544cff};
const u32 var7f1b62d8[] = {0x6a4031ff};
const u32 var7f1b62dc[] = {0x4f433cff};
const u32 var7f1b62e0[] = {0x00000000};
const u32 var7f1b62e4[] = {0xffffffff};
const u32 var7f1b62e8[] = {0xccb38dff};
const u32 var7f1b62ec[] = {0xddc07cff};
const u32 var7f1b62f0[] = {0xe6a667ff};
const u32 var7f1b62f4[] = {0xd1ab50ff};
const u32 var7f1b62f8[] = {0xc69f6dff};
const u32 var7f1b62fc[] = {0xb27e5bff};
const u32 var7f1b6300[] = {0x00000000};
const u32 var7f1b6304[] = {0xffffffff};
const u32 var7f1b6308[] = {0x5f3a25ff};
const u32 var7f1b630c[] = {0x553a20ff};
const u32 var7f1b6310[] = {0x4b351cff};
const u32 var7f1b6314[] = {0x412d19ff};
const u32 var7f1b6318[] = {0x41260fff};
const u32 var7f1b631c[] = {0x371e04ff};
const u32 var7f1b6320[] = {0x00000000};
const u32 var7f1b6324[] = {0xffffffff};
const u32 var7f1b6328[] = {0xe9d679ff};
const u32 var7f1b632c[] = {0x654f40ff};
const u32 var7f1b6330[] = {0xebb279ff};
const u32 var7f1b6334[] = {0x846b51ff};
const u32 var7f1b6338[] = {0xebc579ff};
const u32 var7f1b633c[] = {0xab8d6fff};
const u32 var7f1b6340[] = {0x00000000};
const u32 var7f1b6344[] = {0xffffffff};
const u32 var7f1b6348[] = {0x26374dff};
const u32 var7f1b634c[] = {0x18253eff};
const u32 var7f1b6350[] = {0x171d20ff};
const u32 var7f1b6354[] = {0x060e16ff};
const u32 var7f1b6358[] = {0x00001cff};
const u32 var7f1b635c[] = {0x000001ff};
const u32 var7f1b6360[] = {0x00000000};
const u32 var7f1b6364[] = {0xffffffff};
const u32 var7f1b6368[] = {0x972f1aff};
const u32 var7f1b636c[] = {0x822817ff};
const u32 var7f1b6370[] = {0x6e1e12ff};
const u32 var7f1b6374[] = {0x5a140dff};
const u32 var7f1b6378[] = {0x460a08ff};
const u32 var7f1b637c[] = {0x200001ff};
const u32 var7f1b6380[] = {0x00000000};
const u32 var7f1b6384[] = {0xffffffff};
const u32 var7f1b6388[] = {0x79b2ebff};
const u32 var7f1b638c[] = {0x007fffff};
const u32 var7f1b6390[] = {0x1f5fdfff};
const u32 var7f1b6394[] = {0x0043caff};
const u32 var7f1b6398[] = {0x00147eff};
const u32 var7f1b639c[] = {0x0c1857ff};

const char var7f1b63a0[] = "RWI : Cam Alloc : Guid=%d -> Total = %u (%d at %s)\n";

u32 var8007f8c0 = (u32)&var7f1b6050;
u32 var8007f8c4 = (u32)&var7f1b6058;
u32 var8007f8c8 = (u32)&var7f1b606c;
u32 var8007f8cc = (u32)&var7f1b6080;
u32 var8007f8d0 = (u32)&var7f1b6088;
u32 var8007f8d4 = (u32)&var7f1b6090;
u32 var8007f8d8 = (u32)&var7f1b6098;
struct var8007f8dc *var8007f8dc = NULL;
struct var8007f8e0 *var8007f8e0 = NULL;
u32 var8007f8e4 = 0x00000000;
u32 var8007f8e8 = 0x00000008;
u32 var8007f8ec = 0x0000005a;
u32 var8007f8f0 = 0x00000005;
u32 var8007f8f4 = 0x000000c8;
u32 var8007f8f8 = 0x00000000;
u32 var8007f8fc = 0x00000001;
u32 var8007f900 = 0x00000078;
u32 var8007f904 = 0x02000233;
u32 var8007f908 = 0x024e026b;
u32 var8007f90c = 0x028902a9;
u32 var8007f910 = 0x02ca02ed;
u32 var8007f914 = 0x03120338;
u32 var8007f918 = 0x0360038b;
u32 var8007f91c = 0x03b703e5;
u32 var8007f920 = 0x04160449;
u32 var8007f924 = 0x047f04b7;
u32 var8007f928 = 0x04f20530;
u32 var8007f92c = 0x057005b4;
u32 var8007f930 = 0x05fc0646;
u32 var8007f934 = 0x069506e7;
u32 var8007f938 = 0x073d0798;
u32 var8007f93c = 0x07f7085a;
u32 var8007f940 = 0x08c30930;
u32 var8007f944 = 0x09a30a1b;
u32 var8007f948 = 0x0a9a0b1e;
u32 var8007f94c = 0x0ba90c3b;
u32 var8007f950 = 0x0cd40d74;
u32 var8007f954 = 0x0e1c0ecc;
u32 var8007f958 = 0x0f851047;
u32 var8007f95c = 0x111311e8;
u32 var8007f960 = 0x12c813b3;
u32 var8007f964 = 0x14a915ab;
u32 var8007f968 = 0x16ba17d6;
u32 var8007f96c = 0x18ff1a38;
u32 var8007f970 = 0x1b7f1cd7;
u32 var8007f974 = 0x1e3f1fb9;
u32 var8007f978 = 0x214622e6;
u32 var8007f97c = 0x249a2663;
u32 var8007f980 = 0x28432a3a;
u32 var8007f984 = 0x2c492e73;
u32 var8007f988 = 0x30b73318;
u32 var8007f98c = 0x35963834;
u32 var8007f990 = 0x3af23dd3;
u32 var8007f994 = 0x40d74402;
u32 var8007f998 = 0x47534acf;
u32 var8007f99c = 0x4e75524a;
u32 var8007f9a0 = 0x564e5a84;
u32 var8007f9a4 = 0x5eef6392;
u32 var8007f9a8 = 0x686e6d87;
u32 var8007f9ac = 0x72df787a;
u32 var8007f9b0 = 0x7e5c8487;
u32 var8007f9b4 = 0x8aff91c7;
u32 var8007f9b8 = 0x98e5a05b;
u32 var8007f9bc = 0xa82fb065;
u32 var8007f9c0 = 0xb901c208;
u32 var8007f9c4 = 0xcb81d570;
u32 var8007f9c8 = 0xdfdbeac8;
u32 var8007f9cc = 0xf63dffff;
u32 var8007f9d0 = 0x00000000;
u32 var8007f9d4 = 0x00000000;
u32 var8007f9d8 = 0x3f800000;
u32 var8007f9dc = 0x3f800000;
u32 var8007f9e0 = 0x3f800000;
u32 var8007f9e4 = 0x3f800000;
u32 var8007f9e8 = 0x3f800000;
u32 var8007f9ec = 0x3f800000;
u32 var8007f9f0 = 0x3f800000;
u32 var8007f9f4 = 0x3f800000;
u32 var8007f9f8 = 0x3f800000;
u32 var8007f9fc = 0x3b42938e;
u32 var8007fa00 = 0x3c5a0169;
u32 var8007fa04 = 0x3cb3b752;
u32 var8007fa08 = 0x3c5a0169;
u32 var8007fa0c = 0x3b42938e;
u32 var8007fa10 = 0x3c5a0169;
u32 var8007fa14 = 0x3d7442c8;
u32 var8007fa18 = 0x3dc95bff;
u32 var8007fa1c = 0x3d7442c8;
u32 var8007fa20 = 0x3c5a0169;
u32 var8007fa24 = 0x3cb3b752;
u32 var8007fa28 = 0x3dc95bff;
u32 var8007fa2c = 0x3e25fe54;
u32 var8007fa30 = 0x3dc95bff;
u32 var8007fa34 = 0x3cb3b752;
u32 var8007fa38 = 0x3c5a0169;
u32 var8007fa3c = 0x3d7442c8;
u32 var8007fa40 = 0x3dc95bff;
u32 var8007fa44 = 0x3d7442c8;
u32 var8007fa48 = 0x3c5a0169;
u32 var8007fa4c = 0x3b42938e;
u32 var8007fa50 = 0x3c5a0169;
u32 var8007fa54 = 0x3cb3b752;
u32 var8007fa58 = 0x3c5a0169;
u32 var8007fa5c = 0x3b42938e;
u32 var8007fa60 = 0x3f800000;
u32 var8007fa64 = 0x3f800000;
u32 var8007fa68 = 0x3f800000;
u32 var8007fa6c = 0x3f800000;
u32 var8007fa70 = 0x3f800000;
u32 var8007fa74 = 0x3f800000;
u32 var8007fa78 = 0x3f800000;
u32 var8007fa7c = 0x00000000;

GLOBAL_ASM(
glabel func0f149c90
/*  f149c90:	90830005 */ 	lbu	$v1,0x5($a0)
/*  f149c94:	00001025 */ 	or	$v0,$zero,$zero
/*  f149c98:	1860002d */ 	blez	$v1,.L0f149d50
/*  f149c9c:	00000000 */ 	nop
/*  f149ca0:	90860004 */ 	lbu	$a2,0x4($a0)
.L0f149ca4:
/*  f149ca4:	18c00026 */ 	blez	$a2,.L0f149d40
/*  f149ca8:	00002825 */ 	or	$a1,$zero,$zero
/*  f149cac:	00003825 */ 	or	$a3,$zero,$zero
/*  f149cb0:	30480001 */ 	andi	$t0,$v0,0x1
/*  f149cb4:	00025180 */ 	sll	$t2,$v0,0x6
.L0f149cb8:
/*  f149cb8:	00e6001a */ 	div	$zero,$a3,$a2
/*  f149cbc:	00001812 */ 	mflo	$v1
/*  f149cc0:	00037140 */ 	sll	$t6,$v1,0x5
/*  f149cc4:	14c00002 */ 	bnez	$a2,.L0f149cd0
/*  f149cc8:	00000000 */ 	nop
/*  f149ccc:	0007000d */ 	break	0x7
.L0f149cd0:
/*  f149cd0:	2401ffff */ 	addiu	$at,$zero,-1
/*  f149cd4:	14c10004 */ 	bne	$a2,$at,.L0f149ce8
/*  f149cd8:	3c018000 */ 	lui	$at,0x8000
/*  f149cdc:	14e10002 */ 	bne	$a3,$at,.L0f149ce8
/*  f149ce0:	00000000 */ 	nop
/*  f149ce4:	0006000d */ 	break	0x6
.L0f149ce8:
/*  f149ce8:	01c01825 */ 	or	$v1,$t6,$zero
/*  f149cec:	11000008 */ 	beqz	$t0,.L0f149d10
/*  f149cf0:	00004825 */ 	or	$t1,$zero,$zero
/*  f149cf4:	30af0004 */ 	andi	$t7,$a1,0x4
/*  f149cf8:	11e00003 */ 	beqz	$t7,.L0f149d08
/*  f149cfc:	24060004 */ 	addiu	$a2,$zero,0x4
/*  f149d00:	10000003 */ 	b	.L0f149d10
/*  f149d04:	2409fffc */ 	addiu	$t1,$zero,-4
.L0f149d08:
/*  f149d08:	10000001 */ 	b	.L0f149d10
/*  f149d0c:	00c04825 */ 	or	$t1,$a2,$zero
.L0f149d10:
/*  f149d10:	8c980000 */ 	lw	$t8,0x0($a0)
/*  f149d14:	24e70008 */ 	addiu	$a3,$a3,0x8
/*  f149d18:	030ac821 */ 	addu	$t9,$t8,$t2
/*  f149d1c:	03255821 */ 	addu	$t3,$t9,$a1
/*  f149d20:	01696021 */ 	addu	$t4,$t3,$t1
/*  f149d24:	a1830000 */ 	sb	$v1,0x0($t4)
/*  f149d28:	90860004 */ 	lbu	$a2,0x4($a0)
/*  f149d2c:	24a50001 */ 	addiu	$a1,$a1,0x1
/*  f149d30:	00a6082a */ 	slt	$at,$a1,$a2
/*  f149d34:	1420ffe0 */ 	bnez	$at,.L0f149cb8
/*  f149d38:	00000000 */ 	nop
/*  f149d3c:	90830005 */ 	lbu	$v1,0x5($a0)
.L0f149d40:
/*  f149d40:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f149d44:	0043082a */ 	slt	$at,$v0,$v1
/*  f149d48:	1420ffd6 */ 	bnez	$at,.L0f149ca4
/*  f149d4c:	00000000 */ 	nop
.L0f149d50:
/*  f149d50:	03e00008 */ 	jr	$ra
/*  f149d54:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel func0f149d58
/*  f149d58:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*  f149d5c:	afbf001c */ 	sw	$ra,0x1c($sp)
/*  f149d60:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f149d64:	afa50024 */ 	sw	$a1,0x24($sp)
/*  f149d68:	0fc5db69 */ 	jal	align16
/*  f149d6c:	afa60028 */ 	sw	$a2,0x28($sp)
/*  f149d70:	00408025 */ 	or	$s0,$v0,$zero
/*  f149d74:	00402025 */ 	or	$a0,$v0,$zero
/*  f149d78:	0fc5796e */ 	jal	func0f15e5b8
/*  f149d7c:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f149d80:	3c028008 */ 	lui	$v0,%hi(var8007f9d0)
/*  f149d84:	2442f9d0 */ 	addiu	$v0,$v0,%lo(var8007f9d0)
/*  f149d88:	8c4e0000 */ 	lw	$t6,0x0($v0)
/*  f149d8c:	02002025 */ 	or	$a0,$s0,$zero
/*  f149d90:	01d07821 */ 	addu	$t7,$t6,$s0
/*  f149d94:	0c004aac */ 	jal	func00012ab0
/*  f149d98:	ac4f0000 */ 	sw	$t7,0x0($v0)
/*  f149d9c:	3c188008 */ 	lui	$t8,%hi(var8007f9d4)
/*  f149da0:	8f18f9d4 */ 	lw	$t8,%lo(var8007f9d4)($t8)
/*  f149da4:	3c07800a */ 	lui	$a3,%hi(var800a45a0)
/*  f149da8:	3c018008 */ 	lui	$at,%hi(var8007f9d4)
/*  f149dac:	27190001 */ 	addiu	$t9,$t8,0x1
/*  f149db0:	24e745a0 */ 	addiu	$a3,$a3,%lo(var800a45a0)
/*  f149db4:	ac39f9d4 */ 	sw	$t9,%lo(var8007f9d4)($at)
/*  f149db8:	8ce40000 */ 	lw	$a0,0x0($a3)
/*  f149dbc:	00403025 */ 	or	$a2,$v0,$zero
/*  f149dc0:	00001825 */ 	or	$v1,$zero,$zero
/*  f149dc4:	8c85037c */ 	lw	$a1,0x37c($a0)
/*  f149dc8:	00801025 */ 	or	$v0,$a0,$zero
/*  f149dcc:	18a00010 */ 	blez	$a1,.L0f149e10
/*  f149dd0:	00054880 */ 	sll	$t1,$a1,0x2
.L0f149dd4:
/*  f149dd4:	8c480380 */ 	lw	$t0,0x380($v0)
/*  f149dd8:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f149ddc:	0065082a */ 	slt	$at,$v1,$a1
/*  f149de0:	15000009 */ 	bnez	$t0,.L0f149e08
/*  f149de4:	00895021 */ 	addu	$t2,$a0,$t1
/*  f149de8:	ad460380 */ 	sw	$a2,0x380($t2)
/*  f149dec:	8ce40000 */ 	lw	$a0,0x0($a3)
/*  f149df0:	00c01025 */ 	or	$v0,$a2,$zero
/*  f149df4:	8c8b037c */ 	lw	$t3,0x37c($a0)
/*  f149df8:	000b6080 */ 	sll	$t4,$t3,0x2
/*  f149dfc:	008c6821 */ 	addu	$t5,$a0,$t4
/*  f149e00:	10000010 */ 	b	.L0f149e44
/*  f149e04:	adb003f8 */ 	sw	$s0,0x3f8($t5)
.L0f149e08:
/*  f149e08:	1420fff2 */ 	bnez	$at,.L0f149dd4
/*  f149e0c:	24420004 */ 	addiu	$v0,$v0,0x4
.L0f149e10:
/*  f149e10:	00057080 */ 	sll	$t6,$a1,0x2
/*  f149e14:	008e7821 */ 	addu	$t7,$a0,$t6
/*  f149e18:	ade60380 */ 	sw	$a2,0x380($t7)
/*  f149e1c:	8ce40000 */ 	lw	$a0,0x0($a3)
/*  f149e20:	00c01025 */ 	or	$v0,$a2,$zero
/*  f149e24:	8c98037c */ 	lw	$t8,0x37c($a0)
/*  f149e28:	0018c880 */ 	sll	$t9,$t8,0x2
/*  f149e2c:	00994021 */ 	addu	$t0,$a0,$t9
/*  f149e30:	ad1003f8 */ 	sw	$s0,0x3f8($t0)
/*  f149e34:	8ce40000 */ 	lw	$a0,0x0($a3)
/*  f149e38:	8c89037c */ 	lw	$t1,0x37c($a0)
/*  f149e3c:	252a0001 */ 	addiu	$t2,$t1,0x1
/*  f149e40:	ac8a037c */ 	sw	$t2,0x37c($a0)
.L0f149e44:
/*  f149e44:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f149e48:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f149e4c:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*  f149e50:	03e00008 */ 	jr	$ra
/*  f149e54:	00000000 */ 	nop
);

void func0f149e58(u8 *arg0, u32 size)
{
	s32 i;

	var8007f9d0 -= size;

	for (i = 0; i < var800a45a0->unk37c; i++) {
		if (arg0 == NULL || arg0 == var800a45a0->unk380[i]) {
			func00012cb4(var800a45a0->unk380[i], var800a45a0->unk3f8[i]);
			var800a45a0->unk380[i] = 0;
		}
	}

	if (arg0 == NULL) {
		var800a45a0->unk37c = 0;
	}
}

void func0f149f10(void)
{
	// empty
}

void func0f149f18(void)
{
	struct var8007f8e0 *thing;
	s32 i;

	func0f14b394(func0f14a06c(-1));

	thing = func0f14a06c(-1);
	thing->unk3f4_00 = false;

	if (var800a45a0->unk470) {
		for (i = 0; i < 0x4000; i++) {
			var800a45a0->unk470[i] = random() % 255;
		}
	}
}

void func0f149fc8(s32 index)
{
	func0f14c50c(func0f14a06c(index), func0f14a06c(-1), 1040, "camdraw.c");
}

const char var7f1b63e0[] = "Cam -> Dumping head vertex colour information\n";
const char var7f1b6410[] = "Cam -> Face Col - Pal=%d, Entry=%d, Col=%08x\n";
const char var7f1b6440[] = "Cam -> Hair Col - Pal=%d, Entry=%d, Col=%08x\n";
const char var7f1b6470[] = "Cam_Tick (%d Total Slots)";
const char var7f1b648c[] = "Current Camera Slot = %d\n";
const char var7f1b64a8[] = "Slot %d -> Active = %d";

void func0f14a00c(bool arg0)
{
	struct var8007f8e0 *thing;

	thing = func0f14a06c(-1);
	thing->unk3f4_04 = arg0;

	thing = func0f14a06c(-2);
	thing->unk3f4_04 = arg0;
}

struct var8007f8e0 *func0f14a06c(s32 index)
{
	if (index == -1) {
		return &var8007f8e0[var800a45a0->unk16c];
	}

	if (index == -4) {
		return &var8007f8e0[var800a45a0->unk174];
	}

	if (index == -5) {
		return &var8007f8e0[var800a45a0->unk178];
	}

	if (index == -2) {
		return &var8007f8e0[var800a45a0->unk014[var800a45a0->unk004]];
	}

	if (index == -3) {
		return &var8007f8e0[var800a45a0->unk170];
	}

	return &var8007f8e0[var800a45a0->unk014[index]];
}

void func0f14a16c(s32 arg0)
{
	struct var8007f8dc *thing = func0f14a20c();
	thing->unk100 = arg0;
}

bool func0f14a194(void)
{
	return var8007f8dc[var800a45a0->unk000].unk0d4_04 & 0xff;
}

/**
 * 0 returns "Style 1"
 * 1 returns "Style 2"
 * 2 returns "Style 3"
 * 3 returns "Style 4"
 */
char *phGetStyleName(s32 stylenum)
{
	return langGet(L_MISC_429 + stylenum);
}

/**
 * 0 returns "Blonde"
 * 1 returns "Black"
 * 2 returns "Auburn"
 * 3 returns "Blue Rinse"
 */
char *phGetColourName(s32 colournum)
{
	return langGet(L_MISC_433 + colournum);
}

struct var8007f8dc *func0f14a20c(void)
{
	return &var8007f8dc[func0f14a5a4()];
}

void func0f14a240(void)
{
	s32 i;
	s32 j;

	var800a45a0->unk48c = 0;
	var800a45a0->unk484 = 0;
	var800a45a0->unk470 = 0;
	var800a45a0->unk474 = 0;
	var800a45a0->unk478 = 0;
	var800a45a0->unk47c = 0;
	var800a45a0->unk480 = 0;
	var800a45a0->unk37c = 0;
	var800a45a0->unk000 = 0;
	var800a45a0->unk004 = -1;
	var800a45a0->unk008 = 1;

	for (i = 0; i < 4; i++) {
		for (j = 0; j < 8; j++) {
			// empty
		}
	}

	for (i = 0; i < 4; i++) {
		for (j = 0; j < 8; j++) {
			// empty
		}
	}
}

bool func0f14a2fc(s32 index, u32 line, char *file)
{
	struct var8007f8e0 *thing = func0f14a06c(index);
	return thing->unk3f4_00;
}

void phAllocate(void)
{
	s32 i;

	if (IS8MB()) {
		u32 size1 = align16(sizeof(struct var8007f8dc) * 4);
		u32 size2 = align16(sizeof(struct var800a45a0));

		var8007f8dc = malloc(size1, MEMPOOL_PERMANENT);
		var800a45a0 = malloc(size2, MEMPOOL_PERMANENT);

		func0f14a240();

		for (i = 0; i < 4; i++) {
			func0f14ad58(i);
		}
	}
}

void func0f14a3bc(void)
{
	// empty
}

void func0f14a3c4(void)
{
	s32 i;

	var800a45a0->unk37c = 0;

	for (i = 0; i < 4; i++) {
		var8007f8dc[i].unk0d4_03 = false;
	}
}

void func0f14a404(void)
{
	func0f149e58(NULL, 0);
}

void func0f14a428(void)
{
	s32 i;

	for (i = 0; i < 22; i++) {
		func0f14a2fc(i, 1296, "camdraw.c");
	}
}

const char var7f1b64cc[] = "CAM : Cam_StartCamFileRead - Go\n";
const char var7f1b64f0[] = "************ Cam_ActivateAndClearSlot ************ : Slot=%d\n";

void func0f14a480(void)
{
	// empty
}

void func0f14a488(void)
{
	s32 i;

	func0f14aed0(-1);

	for (i = 0; i < 32; i++) {
		func0f149c90(&var800a45a0->unk484[i]);
	}

	for (i = 0; i < 4; i++) {
		var8007f8dc[i].unk0f4 = 0;
		pak0f11d478(i);
	}
}

void func0f14a52c(void)
{
	s32 i;

	for (i = 0; i < 4; i++) {
		var8007f8dc[i].unk0d4_03 = true;
	}
}

void func0f14a560(void)
{
	s32 i;

	for (i = 0; i < 4; i++) {
		var8007f8dc[i].unk0d4_03 = false;
	}
}

void func0f14a594(s32 arg0)
{
	var800a45a0->unk000 = arg0;
}

s32 func0f14a5a4(void)
{
	return var800a45a0->unk000;
}

void func0f14a5b4(s32 index)
{
	var800a45a0->unk004 = index;

	func0f14b394(func0f14a06c(index));
}

void func0f14a5e4(void)
{
	func0f14def0(-1, 1407, "camdraw.c");
}

void func0f14a610(void)
{
	func0f14def0(-1, 1415, "camdraw.c");
	func0f14c50c(func0f14a06c(-2), func0f14a06c(-1), 1416, "camdraw.c");
}

s32 func0f14a668(void)
{
	return var800a45a0->unk004;
}

void func0f14a678(void)
{
	func0f14c50c(func0f14a06c(-2), func0f14a06c(-1), 1433, "camdraw.c");
}

void func0f14a6bc(void)
{
	func0f14c50c(func0f14a06c(-4), func0f14a06c(-1), 1441, "camdraw.c");
	func0f14c50c(func0f14a06c(-1), func0f14a06c(-3), 1442, "camdraw.c");
	func0f14c50c(func0f14a06c(-3), func0f14a06c(-4), 1443, "camdraw.c");
}

const char var7f1b6584[] = "Cam_CopyEditorToUndo\n";

void func0f14a760(void)
{
	func0f14c50c(func0f14a06c(-3), func0f14a06c(-1), 1452, "camdraw.c");
}

const char var7f1b65a8[] = "Cam_CopyUndoToEditor\n";

void func0f14a7a4(void)
{
	func0f14c50c(func0f14a06c(-1), func0f14a06c(-3), 1461, "camdraw.c");
}

void func0f14a7e8(s32 index)
{
	func0f14c50c(func0f14a06c(-1), func0f14a06c(index), 1470, "camdraw.c");
}

void func0f14a830(void)
{
	struct var8007f8dc *thing = func0f14a20c();

	if (thing->unk0d4_00) {
		thing->unk0d4_00 = false;
	} else {
		thing->unk0d4_00 = true;
	}

	if (thing->unk0d4_00) {
		func0f14def0(-1, 1484, "camdraw.c");
	}
}

u32 *func0f14a89c(s32 index)
{
	struct var8007f8e0 *thing = func0f14a06c(index);

	return &thing->unk004;
}

bool func0f14a8c0(void)
{
	struct var8007f8dc *thing = func0f14a20c();

	return thing->unk0d4_00;
}

bool func0f14a8e8(void)
{
	struct var8007f8dc *thing = func0f14a20c();

	return thing->unk0f8 == 0 ? false : true;
}

void func0f14a91c(s32 arg0)
{
	struct var8007f8e0 *thing = func0f14a06c(-1);

	thing->unk3bc = arg0;

	func0f14def0(-1, 1518, "camdraw.c");
}

const char var7f1b65f0[] = "Cam -> Setting current hair colour to %s\n";
const char var7f1b661c[] = "Cam -> Setting current face colour to %s\n";

void func0f14a95c(void)
{
	struct var8007f8e0 *thing = func0f14a06c(-1);

	thing->unk3bc = 0x80;
}

s32 func0f14a984(void)
{
	struct var8007f8e0 *thing = func0f14a06c(-1);

	return thing->unk3bc;
}

void func0f14a9a8(s32 arg0)
{
	struct var8007f8e0 *thing = func0f14a06c(-1);

	thing->unk3a4 = arg0;
}

void func0f14a9d4(void)
{
	struct var8007f8e0 *thing = func0f14a06c(-1);

	thing->unk3a4 = 0;
}

s32 func0f14a9f8(s32 index)
{
	struct var8007f8e0 *thing = func0f14a06c(index);

	return thing->unk3a4;
}

void func0f14aa1c(s32 arg0)
{
	struct var8007f8e0 *thing = func0f14a06c(-1);

	thing->unk3b8 = arg0;
}

void func0f14aa48(void)
{
	struct var8007f8e0 *thing = func0f14a06c(-1);

	thing->unk3b8 = 6;
}

s32 func0f14aa70(void)
{
	struct var8007f8e0 *thing = func0f14a06c(-1);

	return thing->unk3b8;
}

void func0f14aa94(s32 colournum)
{
	struct var8007f8e0 *thing;

	phGetColourName(colournum);

	thing = func0f14a06c(-1);
	thing->colournum = colournum;
}

void func0f14aac4(void)
{
	struct var8007f8e0 *thing = func0f14a06c(-1);

	thing->colournum = 0;
}

s32 func0f14aae8(void)
{
	struct var8007f8e0 *thing = func0f14a06c(-1);

	return thing->colournum;
}

void func0f14ab0c(s32 stylenum)
{
	struct var8007f8e0 *thing;

	phGetStyleName(stylenum);

	thing = func0f14a06c(-1);
	thing->stylenum = stylenum;
}

void func0f14ab3c(void)
{
	struct var8007f8e0 *thing = func0f14a06c(-1);
	thing->stylenum = 0;
}

s32 func0f14ab60(void)
{
	struct var8007f8e0 *thing = func0f14a06c(-1);
	return thing->stylenum;
}

void func0f14ab84(s32 arg0)
{
	struct var8007f8e0 *thing = func0f14a06c(-1);
	thing->unk3b4 = arg0;
}

s32 func0f14abb0(void)
{
	struct var8007f8e0 *thing = func0f14a06c(-1);
	return thing->unk3b4;
}

void func0f14abd4(s32 index, s32 arg1)
{
	var8007f8dc[index].unk06c = arg1;
}

s32 func0f14abf4(s32 index)
{
	return var8007f8dc[index].unk06c;
}

bool func0f14ac14(void)
{
	struct var8007f8e0 *thing = func0f14a06c(-1);
	return thing->unk3f4_02;
}

void func0f14ac3c(bool arg0)
{
	struct var8007f8e0 *thing = func0f14a06c(-1);
	thing->unk3f4_02 = arg0;

	func0f14def0(-1, 1681, "camdraw.c");
}

const char var7f1b6654[] = "Cam_SetAutoDeArtefact -> State = %d\n";

bool func0f14ac90(void)
{
	struct var8007f8e0 *thing = func0f14a06c(-1);
	return thing->unk3f4_01;
}

void func0f14acb8(bool arg0)
{
	struct var8007f8e0 *thing = func0f14a06c(-1);

	if (arg0) {
		thing->unk3f4_01 = true;
	} else {
		thing->unk3f4_01 = false;
	}

	func0f14def0(-1, 1699, "camdraw.c");
}

u16 func0f14ad14(s32 device)
{
	return var8007f8dc[device].unk05c & 0xffff;
}

s32 func0f14ad38(s32 device)
{
	return var8007f8dc[device].unk060;
}

const char var7f1b6688[] = "Cam_ClearCameraLoadBuffer -> Camera=%d\n";
const char var7f1b66b0[] = "Cam_StartTemp : Need %u bytes for temp cam images buffer\n";

GLOBAL_ASM(
glabel func0f14ad58
.late_rodata
glabel var7f1b72e4
.word 0x3dcccccd
glabel var7f1b72e8
.word 0x3e4ccccd
.text
/*  f14ad58:	3c0f8008 */ 	lui	$t7,%hi(var8007f8dc)
/*  f14ad5c:	8deff8dc */ 	lw	$t7,%lo(var8007f8dc)($t7)
/*  f14ad60:	00047180 */ 	sll	$t6,$a0,0x6
/*  f14ad64:	3c013f80 */ 	lui	$at,0x3f80
/*  f14ad68:	01c47021 */ 	addu	$t6,$t6,$a0
/*  f14ad6c:	44810000 */ 	mtc1	$at,$f0
/*  f14ad70:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f14ad74:	3c0142dc */ 	lui	$at,0x42dc
/*  f14ad78:	01cf1021 */ 	addu	$v0,$t6,$t7
/*  f14ad7c:	44812000 */ 	mtc1	$at,$f4
/*  f14ad80:	ac400000 */ 	sw	$zero,0x0($v0)
/*  f14ad84:	3c017f1b */ 	lui	$at,%hi(var7f1b72e4)
/*  f14ad88:	e4400004 */ 	swc1	$f0,0x4($v0)
/*  f14ad8c:	e4400008 */ 	swc1	$f0,0x8($v0)
/*  f14ad90:	e4440050 */ 	swc1	$f4,0x50($v0)
/*  f14ad94:	c42672e4 */ 	lwc1	$f6,%lo(var7f1b72e4)($at)
/*  f14ad98:	3c017f1b */ 	lui	$at,%hi(var7f1b72e8)
/*  f14ad9c:	44801000 */ 	mtc1	$zero,$f2
/*  f14ada0:	e446000c */ 	swc1	$f6,0xc($v0)
/*  f14ada4:	c42872e8 */ 	lwc1	$f8,%lo(var7f1b72e8)($at)
/*  f14ada8:	3c0141f0 */ 	lui	$at,0x41f0
/*  f14adac:	44815000 */ 	mtc1	$at,$f10
/*  f14adb0:	2403ffff */ 	addiu	$v1,$zero,-1
/*  f14adb4:	2418001e */ 	addiu	$t8,$zero,0x1e
/*  f14adb8:	ac430058 */ 	sw	$v1,0x58($v0)
/*  f14adbc:	ac430068 */ 	sw	$v1,0x68($v0)
/*  f14adc0:	ac40006c */ 	sw	$zero,0x6c($v0)
/*  f14adc4:	ac400070 */ 	sw	$zero,0x70($v0)
/*  f14adc8:	ac400074 */ 	sw	$zero,0x74($v0)
/*  f14adcc:	ac400084 */ 	sw	$zero,0x84($v0)
/*  f14add0:	ac580054 */ 	sw	$t8,0x54($v0)
/*  f14add4:	3c198008 */ 	lui	$t9,%hi(var8007f940)
/*  f14add8:	e4400024 */ 	swc1	$f0,0x24($v0)
/*  f14addc:	e4400028 */ 	swc1	$f0,0x28($v0)
/*  f14ade0:	e440003c */ 	swc1	$f0,0x3c($v0)
/*  f14ade4:	e4420014 */ 	swc1	$f2,0x14($v0)
/*  f14ade8:	e4420018 */ 	swc1	$f2,0x18($v0)
/*  f14adec:	e442001c */ 	swc1	$f2,0x1c($v0)
/*  f14adf0:	e4420020 */ 	swc1	$f2,0x20($v0)
/*  f14adf4:	e442002c */ 	swc1	$f2,0x2c($v0)
/*  f14adf8:	e4420030 */ 	swc1	$f2,0x30($v0)
/*  f14adfc:	e4420034 */ 	swc1	$f2,0x34($v0)
/*  f14ae00:	e4420038 */ 	swc1	$f2,0x38($v0)
/*  f14ae04:	e4420040 */ 	swc1	$f2,0x40($v0)
/*  f14ae08:	e4480010 */ 	swc1	$f8,0x10($v0)
/*  f14ae0c:	e44a0044 */ 	swc1	$f10,0x44($v0)
/*  f14ae10:	9739f940 */ 	lhu	$t9,%lo(var8007f940)($t9)
/*  f14ae14:	904b00d4 */ 	lbu	$t3,0xd4($v0)
/*  f14ae18:	24080006 */ 	addiu	$t0,$zero,0x6
/*  f14ae1c:	ac480060 */ 	sw	$t0,0x60($v0)
/*  f14ae20:	316dff7f */ 	andi	$t5,$t3,0xff7f
/*  f14ae24:	31af00bf */ 	andi	$t7,$t5,0xbf
/*  f14ae28:	2409000e */ 	addiu	$t1,$zero,0xe
/*  f14ae2c:	3c013f80 */ 	lui	$at,0x3f80
/*  f14ae30:	a04d00d4 */ 	sb	$t5,0xd4($v0)
/*  f14ae34:	31e800df */ 	andi	$t0,$t7,0xdf
/*  f14ae38:	44818000 */ 	mtc1	$at,$f16
/*  f14ae3c:	ac49008c */ 	sw	$t1,0x8c($v0)
/*  f14ae40:	a04f00d4 */ 	sb	$t7,0xd4($v0)
/*  f14ae44:	240a0001 */ 	addiu	$t2,$zero,0x1
/*  f14ae48:	24030003 */ 	addiu	$v1,$zero,0x3
/*  f14ae4c:	a04800d4 */ 	sb	$t0,0xd4($v0)
/*  f14ae50:	35090008 */ 	ori	$t1,$t0,0x8
/*  f14ae54:	ac4a0088 */ 	sw	$t2,0x88($v0)
/*  f14ae58:	ac400090 */ 	sw	$zero,0x90($v0)
/*  f14ae5c:	ac400064 */ 	sw	$zero,0x64($v0)
/*  f14ae60:	ac4000f4 */ 	sw	$zero,0xf4($v0)
/*  f14ae64:	ac400094 */ 	sw	$zero,0x94($v0)
/*  f14ae68:	a04900d4 */ 	sb	$t1,0xd4($v0)
/*  f14ae6c:	ac4000f8 */ 	sw	$zero,0xf8($v0)
/*  f14ae70:	ac4300fc */ 	sw	$v1,0xfc($v0)
/*  f14ae74:	ac430100 */ 	sw	$v1,0x100($v0)
/*  f14ae78:	ac4000e0 */ 	sw	$zero,0xe0($v0)
/*  f14ae7c:	ac4000e4 */ 	sw	$zero,0xe4($v0)
/*  f14ae80:	ac4000e8 */ 	sw	$zero,0xe8($v0)
/*  f14ae84:	ac4000ec */ 	sw	$zero,0xec($v0)
/*  f14ae88:	ac4000f0 */ 	sw	$zero,0xf0($v0)
/*  f14ae8c:	ac400078 */ 	sw	$zero,0x78($v0)
/*  f14ae90:	ac40007c */ 	sw	$zero,0x7c($v0)
/*  f14ae94:	ac59005c */ 	sw	$t9,0x5c($v0)
/*  f14ae98:	03e00008 */ 	jr	$ra
/*  f14ae9c:	e4500048 */ 	swc1	$f16,0x48($v0)
);

// Mismatch: need to fiddle with the order of these
//void func0f14ad58(s32 index)
//{
//	struct var8007f8dc *thing = &var8007f8dc[index];
//
//	thing->unk000 = 0;
//	thing->unk004 = 1.0f;
//	thing->unk008 = 1.0f;
//	thing->unk050 = 110.0f;
//	thing->unk00c = 0.1f;
//	thing->unk010 = 0.2f;
//	thing->unk054 = 30;
//	thing->unk058 = -1;
//	thing->unk068 = -1;
//	thing->unk06c = 0;
//	thing->unk070 = 0;
//	thing->unk074 = 0;
//	thing->unk084 = 0;
//	thing->unk024 = 1.0f;
//	thing->unk028 = 1.0f;
//	thing->unk03c = 1.0f;
//	thing->unk014 = 0.0f;
//	thing->unk018 = 0.0f;
//	thing->unk01c = 0.0f;
//	thing->unk020 = 0.0f;
//	thing->unk02c = 0.0f;
//	thing->unk030 = 0.0f;
//	thing->unk034 = 0.0f;
//	thing->unk038 = 0.0f;
//	thing->unk040 = 0.0f;
//	thing->unk044 = 30.0f;
//	thing->unk060 = 6;
//	thing->unk08c = 14;
//	thing->unk088 = 1;
//	thing->unk090 = 0;
//	thing->unk064 = 0;
//	thing->unk0f4 = 0;
//	thing->unk094 = 0;
//	thing->unk0f8 = 0;
//	thing->unk0fc = 3;
//	thing->unk100 = 3;
//	thing->unk0e0 = 0;
//	thing->unk0e4 = 0;
//	thing->unk0e8 = 0;
//	thing->unk0ec = 0;
//	thing->unk0f0 = 0;
//	thing->unk078 = 0;
//	thing->unk07c = 0;
//	thing->unk05c = var8007f940;
//	thing->unk048 = 1.0f;
//	thing->unk0d4_00 = false;
//	thing->unk0d4_01 = false;
//	thing->unk0d4_02 = false;
//	thing->unk0d4_04 = true;
//}

bool func0f14aea0(s32 device)
{
	return var8007f8dc[device].unk0d4_03;
}

void func0f14aec8(void)
{
	// empty
}

void func0f14aed0(s32 device)
{
	// empty
}

void func0f14aed8(void)
{
	// empty
}

const char var7f1b66ec[] = "camdraw.c";
const char var7f1b66f8[] = "camdraw.c";
const char var7f1b6704[] = "camdraw.c";
const char var7f1b6710[] = "camdraw.c";
const char var7f1b671c[] = "camdraw.c";
const char var7f1b6728[] = "Camera -> Cam_Start for Camera %d\n";
const char var7f1b674c[] = "Camera -> Cam_Stop\n";
const char var7f1b6760[] = "Camera -> Cam_Finish - Done\n";
const char var7f1b6780[] = "Camera ->Created a new slot - Id=%d\n";
const char var7f1b67a8[] = "Camera -> CD_DeleteSlot - Dumping slot %d\n";

GLOBAL_ASM(
glabel func0f14aee0
/*  f14aee0:	27bdff80 */ 	addiu	$sp,$sp,-128
/*  f14aee4:	afb5002c */ 	sw	$s5,0x2c($sp)
/*  f14aee8:	3c15800a */ 	lui	$s5,%hi(var800a45a0)
/*  f14aeec:	26b545a0 */ 	addiu	$s5,$s5,%lo(var800a45a0)
/*  f14aef0:	8ea20000 */ 	lw	$v0,0x0($s5)
/*  f14aef4:	afbf003c */ 	sw	$ra,0x3c($sp)
/*  f14aef8:	afbe0038 */ 	sw	$s8,0x38($sp)
/*  f14aefc:	afb70034 */ 	sw	$s7,0x34($sp)
/*  f14af00:	afb60030 */ 	sw	$s6,0x30($sp)
/*  f14af04:	afb40028 */ 	sw	$s4,0x28($sp)
/*  f14af08:	afb30024 */ 	sw	$s3,0x24($sp)
/*  f14af0c:	afb20020 */ 	sw	$s2,0x20($sp)
/*  f14af10:	afb1001c */ 	sw	$s1,0x1c($sp)
/*  f14af14:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f14af18:	8c4e0484 */ 	lw	$t6,0x484($v0)
/*  f14af1c:	27b0006c */ 	addiu	$s0,$sp,0x6c
/*  f14af20:	24120021 */ 	addiu	$s2,$zero,0x21
/*  f14af24:	15c00030 */ 	bnez	$t6,.L0f14afe8
/*  f14af28:	00000000 */ 	nop
/*  f14af2c:	0fc531f7 */ 	jal	func0f14c7dc
/*  f14af30:	02002025 */ 	or	$a0,$s0,$zero
/*  f14af34:	0fc53205 */ 	jal	func0f14c814
/*  f14af38:	02002025 */ 	or	$a0,$s0,$zero
/*  f14af3c:	0fc5db70 */ 	jal	align32
/*  f14af40:	00402025 */ 	or	$a0,$v0,$zero
/*  f14af44:	0040a025 */ 	or	$s4,$v0,$zero
/*  f14af48:	0fc5db69 */ 	jal	align16
/*  f14af4c:	2404018c */ 	addiu	$a0,$zero,0x18c
/*  f14af50:	00142140 */ 	sll	$a0,$s4,0x5
/*  f14af54:	00408025 */ 	or	$s0,$v0,$zero
/*  f14af58:	0fc5db69 */ 	jal	align16
/*  f14af5c:	00942021 */ 	addu	$a0,$a0,$s4
/*  f14af60:	02022021 */ 	addu	$a0,$s0,$v0
/*  f14af64:	0c0048f2 */ 	jal	malloc
/*  f14af68:	24050004 */ 	addiu	$a1,$zero,0x4
/*  f14af6c:	8eaf0000 */ 	lw	$t7,0x0($s5)
/*  f14af70:	2451018c */ 	addiu	$s1,$v0,0x18c
/*  f14af74:	00009825 */ 	or	$s3,$zero,$zero
/*  f14af78:	00008025 */ 	or	$s0,$zero,$zero
/*  f14af7c:	ade20484 */ 	sw	$v0,0x484($t7)
.L0f14af80:
/*  f14af80:	8eb80000 */ 	lw	$t8,0x0($s5)
/*  f14af84:	8f190484 */ 	lw	$t9,0x484($t8)
/*  f14af88:	0fc531f7 */ 	jal	func0f14c7dc
/*  f14af8c:	03302021 */ 	addu	$a0,$t9,$s0
/*  f14af90:	8ea80000 */ 	lw	$t0,0x0($s5)
/*  f14af94:	26730001 */ 	addiu	$s3,$s3,0x1
/*  f14af98:	8d090484 */ 	lw	$t1,0x484($t0)
/*  f14af9c:	01305021 */ 	addu	$t2,$t1,$s0
/*  f14afa0:	ad510000 */ 	sw	$s1,0x0($t2)
/*  f14afa4:	2610000c */ 	addiu	$s0,$s0,0xc
/*  f14afa8:	1672fff5 */ 	bne	$s3,$s2,.L0f14af80
/*  f14afac:	02348821 */ 	addu	$s1,$s1,$s4
/*  f14afb0:	00009825 */ 	or	$s3,$zero,$zero
/*  f14afb4:	00008025 */ 	or	$s0,$zero,$zero
.L0f14afb8:
/*  f14afb8:	8eab0000 */ 	lw	$t3,0x0($s5)
/*  f14afbc:	8d6c0484 */ 	lw	$t4,0x484($t3)
/*  f14afc0:	0fc52724 */ 	jal	func0f149c90
/*  f14afc4:	01902021 */ 	addu	$a0,$t4,$s0
/*  f14afc8:	26730001 */ 	addiu	$s3,$s3,0x1
/*  f14afcc:	1672fffa */ 	bne	$s3,$s2,.L0f14afb8
/*  f14afd0:	2610000c */ 	addiu	$s0,$s0,0xc
/*  f14afd4:	8ea20000 */ 	lw	$v0,0x0($s5)
/*  f14afd8:	8c4d0484 */ 	lw	$t5,0x484($v0)
/*  f14afdc:	25ae0180 */ 	addiu	$t6,$t5,0x180
/*  f14afe0:	ac4e0488 */ 	sw	$t6,0x488($v0)
/*  f14afe4:	8ea20000 */ 	lw	$v0,0x0($s5)
.L0f14afe8:
/*  f14afe8:	3c067f1b */ 	lui	$a2,%hi(var7f1b66ec)
/*  f14afec:	ac40037c */ 	sw	$zero,0x37c($v0)
/*  f14aff0:	24c666ec */ 	addiu	$a2,$a2,%lo(var7f1b66ec)
/*  f14aff4:	24044000 */ 	addiu	$a0,$zero,0x4000
/*  f14aff8:	2405077b */ 	addiu	$a1,$zero,0x77b
/*  f14affc:	0fc52756 */ 	jal	func0f149d58
/*  f14b000:	00009825 */ 	or	$s3,$zero,$zero
/*  f14b004:	8eaf0000 */ 	lw	$t7,0x0($s5)
/*  f14b008:	3c100001 */ 	lui	$s0,0x1
/*  f14b00c:	3c067f1b */ 	lui	$a2,%hi(var7f1b66f8)
/*  f14b010:	24c666f8 */ 	addiu	$a2,$a2,%lo(var7f1b66f8)
/*  f14b014:	02002025 */ 	or	$a0,$s0,$zero
/*  f14b018:	2405077c */ 	addiu	$a1,$zero,0x77c
/*  f14b01c:	0fc52756 */ 	jal	func0f149d58
/*  f14b020:	ade20470 */ 	sw	$v0,0x470($t7)
/*  f14b024:	8eb80000 */ 	lw	$t8,0x0($s5)
/*  f14b028:	3c067f1b */ 	lui	$a2,%hi(var7f1b6704)
/*  f14b02c:	24c66704 */ 	addiu	$a2,$a2,%lo(var7f1b6704)
/*  f14b030:	02002025 */ 	or	$a0,$s0,$zero
/*  f14b034:	2405077d */ 	addiu	$a1,$zero,0x77d
/*  f14b038:	0fc52756 */ 	jal	func0f149d58
/*  f14b03c:	af020474 */ 	sw	$v0,0x474($t8)
/*  f14b040:	8eb90000 */ 	lw	$t9,0x0($s5)
/*  f14b044:	3c067f1b */ 	lui	$a2,%hi(var7f1b6710)
/*  f14b048:	24c66710 */ 	addiu	$a2,$a2,%lo(var7f1b6710)
/*  f14b04c:	24040078 */ 	addiu	$a0,$zero,0x78
/*  f14b050:	2405077e */ 	addiu	$a1,$zero,0x77e
/*  f14b054:	0fc52756 */ 	jal	func0f149d58
/*  f14b058:	af220478 */ 	sw	$v0,0x478($t9)
/*  f14b05c:	8ea80000 */ 	lw	$t0,0x0($s5)
/*  f14b060:	3c067f1b */ 	lui	$a2,%hi(var7f1b671c)
/*  f14b064:	24c6671c */ 	addiu	$a2,$a2,%lo(var7f1b671c)
/*  f14b068:	24041000 */ 	addiu	$a0,$zero,0x1000
/*  f14b06c:	2405077f */ 	addiu	$a1,$zero,0x77f
/*  f14b070:	0fc52756 */ 	jal	func0f149d58
/*  f14b074:	ad02047c */ 	sw	$v0,0x47c($t0)
/*  f14b078:	8ea90000 */ 	lw	$t1,0x0($s5)
/*  f14b07c:	3c168008 */ 	lui	$s6,%hi(var8007f8dc)
/*  f14b080:	26d6f8dc */ 	addiu	$s6,$s6,%lo(var8007f8dc)
/*  f14b084:	0000a025 */ 	or	$s4,$zero,$zero
/*  f14b088:	241e0004 */ 	addiu	$s8,$zero,0x4
/*  f14b08c:	2417ffff */ 	addiu	$s7,$zero,-1
/*  f14b090:	2412001e */ 	addiu	$s2,$zero,0x1e
/*  f14b094:	241000ff */ 	addiu	$s0,$zero,0xff
/*  f14b098:	ad220480 */ 	sw	$v0,0x480($t1)
.L0f14b09c:
/*  f14b09c:	8eab0000 */ 	lw	$t3,0x0($s5)
/*  f14b0a0:	8eca0000 */ 	lw	$t2,0x0($s6)
/*  f14b0a4:	00132600 */ 	sll	$a0,$s3,0x18
/*  f14b0a8:	8d6c047c */ 	lw	$t4,0x47c($t3)
/*  f14b0ac:	028a8821 */ 	addu	$s1,$s4,$t2
/*  f14b0b0:	00047e03 */ 	sra	$t7,$a0,0x18
/*  f14b0b4:	ae2c00dc */ 	sw	$t4,0xdc($s1)
/*  f14b0b8:	8ead0000 */ 	lw	$t5,0x0($s5)
/*  f14b0bc:	01e02025 */ 	or	$a0,$t7,$zero
/*  f14b0c0:	8da50480 */ 	lw	$a1,0x480($t5)
/*  f14b0c4:	ae37007c */ 	sw	$s7,0x7c($s1)
/*  f14b0c8:	ae200078 */ 	sw	$zero,0x78($s1)
/*  f14b0cc:	0fc45c54 */ 	jal	pak0f117150
/*  f14b0d0:	ae2500d8 */ 	sw	$a1,0xd8($s1)
/*  f14b0d4:	00002025 */ 	or	$a0,$zero,$zero
/*  f14b0d8:	24050003 */ 	addiu	$a1,$zero,0x3
/*  f14b0dc:	0fc45c6d */ 	jal	pak0f1171b4
/*  f14b0e0:	00003025 */ 	or	$a2,$zero,$zero
/*  f14b0e4:	0fc52bb4 */ 	jal	func0f14aed0
/*  f14b0e8:	02602025 */ 	or	$a0,$s3,$zero
/*  f14b0ec:	ae200094 */ 	sw	$zero,0x94($s1)
/*  f14b0f0:	00001825 */ 	or	$v1,$zero,$zero
/*  f14b0f4:	02201025 */ 	or	$v0,$s1,$zero
.L0f14b0f8:
/*  f14b0f8:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f14b0fc:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f14b100:	a0500097 */ 	sb	$s0,0x97($v0)
/*  f14b104:	1472fffc */ 	bne	$v1,$s2,.L0f14b0f8
/*  f14b108:	a05000b5 */ 	sb	$s0,0xb5($v0)
/*  f14b10c:	26730001 */ 	addiu	$s3,$s3,0x1
/*  f14b110:	167effe2 */ 	bne	$s3,$s8,.L0f14b09c
/*  f14b114:	26940104 */ 	addiu	$s4,$s4,0x104
/*  f14b118:	0fc52965 */ 	jal	func0f14a594
/*  f14b11c:	00002025 */ 	or	$a0,$zero,$zero
/*  f14b120:	8fbf003c */ 	lw	$ra,0x3c($sp)
/*  f14b124:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f14b128:	8fb1001c */ 	lw	$s1,0x1c($sp)
/*  f14b12c:	8fb20020 */ 	lw	$s2,0x20($sp)
/*  f14b130:	8fb30024 */ 	lw	$s3,0x24($sp)
/*  f14b134:	8fb40028 */ 	lw	$s4,0x28($sp)
/*  f14b138:	8fb5002c */ 	lw	$s5,0x2c($sp)
/*  f14b13c:	8fb60030 */ 	lw	$s6,0x30($sp)
/*  f14b140:	8fb70034 */ 	lw	$s7,0x34($sp)
/*  f14b144:	8fbe0038 */ 	lw	$s8,0x38($sp)
/*  f14b148:	03e00008 */ 	jr	$ra
/*  f14b14c:	27bd0080 */ 	addiu	$sp,$sp,0x80
);

void func0f14b150(void)
{
	var800a45a0->unk48c = 0;

	func0f14b178();
}

void func0f14b178(void)
{
	s32 i;

	func0f149e58(var800a45a0->unk470, 0x4000);
	func0f149e58(var800a45a0->unk474, 0x10000);
	func0f149e58(var800a45a0->unk478, 0x10000);
	func0f149e58(var800a45a0->unk47c, 0x78);
	func0f149e58(var800a45a0->unk480, 0x1000);

	for (i = 0; i < 4; i++) {
		struct var8007f8dc *thing = &var8007f8dc[i];

		thing->unk0d4_03 = false;
		thing->unk0dc = 0;
		thing->unk0d8 = 0;
	}
}

void func0f14b228(struct var8007f8e0 *arg0)
{
	s32 i;

	arg0->unk03c = 0;
	arg0->unk3f4_00 = false;

	for (i = 0; i < ARRAYCOUNT(arg0->unk040); i++) {
		arg0->unk040[i] = 0xff;
	}

	for (i = 0; i < ARRAYCOUNT(arg0->unk2fc); i++) {
		arg0->unk2fc[i] = 0xff;
	}

	for (i = 0; i < ARRAYCOUNT(arg0->unk108); i++) {
		arg0->unk108[i] = 0xff;
	}

	for (i = 0; i < ARRAYCOUNT(arg0->unk3d0); i++) {
		arg0->unk3d0[i] = 1.0f;
	}

	arg0->unk036 = 3;
	arg0->unk3f4_01 = false;
	arg0->unk3f4_02 = true;
	arg0->unk3f4_03 = false;
	arg0->unk028 = 0;
	arg0->unk02c = 0;
	arg0->unk034 = 0;
	arg0->unk030 = 1.0f;
	arg0->unk3f4_04 = false;
	arg0->colournum = 0;
	arg0->stylenum = 0;
	arg0->unk3a4 = 0;
	arg0->unk3a8 = -1;
	arg0->unk3ac = -1;
	arg0->unk3b0 = -1;
	arg0->unk3b4 = 0x10;
	arg0->unk3b8 = 6;
	arg0->unk3bc = 0x80;
	arg0->unk3c0 = 10;
	arg0->unk3c4 = 0x36;
	arg0->unk3c8 = 3;
	arg0->unk3cc = 0x3d;
	arg0->unk3ec = 0;
	arg0->unk3f0 = 0;
	arg0->fileguid.fileid = 0;
	arg0->fileguid.deviceserial = 0;
}

void func0f14b358(void)
{
	// empty
}

void func0f14b360(s32 index)
{
	struct var8007f8e0 *thing = func0f14a06c(index);

	func0f14b228(thing);
	func0f14b394(thing);
}

GLOBAL_ASM(
glabel func0f14b394
/*  f14b394:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*  f14b398:	afb30020 */ 	sw	$s3,0x20($sp)
/*  f14b39c:	00809825 */ 	or	$s3,$a0,$zero
/*  f14b3a0:	afbf0024 */ 	sw	$ra,0x24($sp)
/*  f14b3a4:	afb2001c */ 	sw	$s2,0x1c($sp)
/*  f14b3a8:	afb10018 */ 	sw	$s1,0x18($sp)
/*  f14b3ac:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f14b3b0:	0fc53205 */ 	jal	func0f14c814
/*  f14b3b4:	24840004 */ 	addiu	$a0,$a0,0x4
/*  f14b3b8:	0fc5db70 */ 	jal	align32
/*  f14b3bc:	00402025 */ 	or	$a0,$v0,$zero
/*  f14b3c0:	00408825 */ 	or	$s1,$v0,$zero
/*  f14b3c4:	18400011 */ 	blez	$v0,.L0f14b40c
/*  f14b3c8:	00008025 */ 	or	$s0,$zero,$zero
/*  f14b3cc:	241200ff */ 	addiu	$s2,$zero,0xff
.L0f14b3d0:
/*  f14b3d0:	0c004b70 */ 	jal	random
/*  f14b3d4:	00000000 */ 	nop
/*  f14b3d8:	0052001b */ 	divu	$zero,$v0,$s2
/*  f14b3dc:	8e6f0004 */ 	lw	$t7,0x4($s3)
/*  f14b3e0:	00007010 */ 	mfhi	$t6
/*  f14b3e4:	01f0c021 */ 	addu	$t8,$t7,$s0
/*  f14b3e8:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f14b3ec:	0211082a */ 	slt	$at,$s0,$s1
/*  f14b3f0:	16400002 */ 	bnez	$s2,.L0f14b3fc
/*  f14b3f4:	00000000 */ 	nop
/*  f14b3f8:	0007000d */ 	break	0x7
.L0f14b3fc:
/*  f14b3fc:	a30e0000 */ 	sb	$t6,0x0($t8)
/*  f14b400:	1420fff3 */ 	bnez	$at,.L0f14b3d0
/*  f14b404:	00000000 */ 	nop
/*  f14b408:	00008025 */ 	or	$s0,$zero,$zero
.L0f14b40c:
/*  f14b40c:	241200ff */ 	addiu	$s2,$zero,0xff
/*  f14b410:	0fc53205 */ 	jal	func0f14c814
/*  f14b414:	26640010 */ 	addiu	$a0,$s3,0x10
/*  f14b418:	0fc5db70 */ 	jal	align32
/*  f14b41c:	00402025 */ 	or	$a0,$v0,$zero
/*  f14b420:	1840000f */ 	blez	$v0,.L0f14b460
/*  f14b424:	00408825 */ 	or	$s1,$v0,$zero
.L0f14b428:
/*  f14b428:	0c004b70 */ 	jal	random
/*  f14b42c:	00000000 */ 	nop
/*  f14b430:	0052001b */ 	divu	$zero,$v0,$s2
/*  f14b434:	8e680010 */ 	lw	$t0,0x10($s3)
/*  f14b438:	0000c810 */ 	mfhi	$t9
/*  f14b43c:	01104821 */ 	addu	$t1,$t0,$s0
/*  f14b440:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f14b444:	0211082a */ 	slt	$at,$s0,$s1
/*  f14b448:	16400002 */ 	bnez	$s2,.L0f14b454
/*  f14b44c:	00000000 */ 	nop
/*  f14b450:	0007000d */ 	break	0x7
.L0f14b454:
/*  f14b454:	a1390000 */ 	sb	$t9,0x0($t1)
/*  f14b458:	1420fff3 */ 	bnez	$at,.L0f14b428
/*  f14b45c:	00000000 */ 	nop
.L0f14b460:
/*  f14b460:	0fc52c8a */ 	jal	func0f14b228
/*  f14b464:	02602025 */ 	or	$a0,$s3,$zero
/*  f14b468:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*  f14b46c:	8fb00014 */ 	lw	$s0,0x14($sp)
/*  f14b470:	8fb10018 */ 	lw	$s1,0x18($sp)
/*  f14b474:	8fb2001c */ 	lw	$s2,0x1c($sp)
/*  f14b478:	8fb30020 */ 	lw	$s3,0x20($sp)
/*  f14b47c:	03e00008 */ 	jr	$ra
/*  f14b480:	27bd0028 */ 	addiu	$sp,$sp,0x28
);

GLOBAL_ASM(
glabel func0f14b484
.late_rodata
glabel var7f1b72ec
.word 0x3c23d70a
glabel var7f1b72f0
.word 0x33d6bf95
.text
/*  f14b484:	3c188008 */ 	lui	$t8,%hi(var8007f8e8)
/*  f14b488:	8f18f8e8 */ 	lw	$t8,%lo(var8007f8e8)($t8)
/*  f14b48c:	00047180 */ 	sll	$t6,$a0,0x6
/*  f14b490:	3c0f8008 */ 	lui	$t7,%hi(var8007f8dc)
/*  f14b494:	8deff8dc */ 	lw	$t7,%lo(var8007f8dc)($t7)
/*  f14b498:	44982000 */ 	mtc1	$t8,$f4
/*  f14b49c:	01c47021 */ 	addu	$t6,$t6,$a0
/*  f14b4a0:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*  f14b4a4:	3c017f1b */ 	lui	$at,%hi(var7f1b72ec)
/*  f14b4a8:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f14b4ac:	c42072ec */ 	lwc1	$f0,%lo(var7f1b72ec)($at)
/*  f14b4b0:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f14b4b4:	01cf1821 */ 	addu	$v1,$t6,$t7
/*  f14b4b8:	07010005 */ 	bgez	$t8,.L0f14b4d0
/*  f14b4bc:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f14b4c0:	3c014f80 */ 	lui	$at,0x4f80
/*  f14b4c4:	44814000 */ 	mtc1	$at,$f8
/*  f14b4c8:	00000000 */ 	nop
/*  f14b4cc:	46083180 */ 	add.s	$f6,$f6,$f8
.L0f14b4d0:
/*  f14b4d0:	46003282 */ 	mul.s	$f10,$f6,$f0
/*  f14b4d4:	3c198008 */ 	lui	$t9,%hi(var8007f8ec)
/*  f14b4d8:	e46a0004 */ 	swc1	$f10,0x4($v1)
/*  f14b4dc:	8f39f8ec */ 	lw	$t9,%lo(var8007f8ec)($t9)
/*  f14b4e0:	44998000 */ 	mtc1	$t9,$f16
/*  f14b4e4:	07210005 */ 	bgez	$t9,.L0f14b4fc
/*  f14b4e8:	468084a0 */ 	cvt.s.w	$f18,$f16
/*  f14b4ec:	3c014f80 */ 	lui	$at,0x4f80
/*  f14b4f0:	44812000 */ 	mtc1	$at,$f4
/*  f14b4f4:	00000000 */ 	nop
/*  f14b4f8:	46049480 */ 	add.s	$f18,$f18,$f4
.L0f14b4fc:
/*  f14b4fc:	46009202 */ 	mul.s	$f8,$f18,$f0
/*  f14b500:	3c088008 */ 	lui	$t0,%hi(var8007f8f0)
/*  f14b504:	3c014f80 */ 	lui	$at,0x4f80
/*  f14b508:	e4680008 */ 	swc1	$f8,0x8($v1)
/*  f14b50c:	8d08f8f0 */ 	lw	$t0,%lo(var8007f8f0)($t0)
/*  f14b510:	44883000 */ 	mtc1	$t0,$f6
/*  f14b514:	05010004 */ 	bgez	$t0,.L0f14b528
/*  f14b518:	468032a0 */ 	cvt.s.w	$f10,$f6
/*  f14b51c:	44818000 */ 	mtc1	$at,$f16
/*  f14b520:	00000000 */ 	nop
/*  f14b524:	46105280 */ 	add.s	$f10,$f10,$f16
.L0f14b528:
/*  f14b528:	46005102 */ 	mul.s	$f4,$f10,$f0
/*  f14b52c:	3c098008 */ 	lui	$t1,%hi(var8007f8f4)
/*  f14b530:	3c014f80 */ 	lui	$at,0x4f80
/*  f14b534:	e464000c */ 	swc1	$f4,0xc($v1)
/*  f14b538:	8d29f8f4 */ 	lw	$t1,%lo(var8007f8f4)($t1)
/*  f14b53c:	44899000 */ 	mtc1	$t1,$f18
/*  f14b540:	05210004 */ 	bgez	$t1,.L0f14b554
/*  f14b544:	46809220 */ 	cvt.s.w	$f8,$f18
/*  f14b548:	44813000 */ 	mtc1	$at,$f6
/*  f14b54c:	00000000 */ 	nop
/*  f14b550:	46064200 */ 	add.s	$f8,$f8,$f6
.L0f14b554:
/*  f14b554:	46004402 */ 	mul.s	$f16,$f8,$f0
/*  f14b558:	3c0a8008 */ 	lui	$t2,%hi(var8007f8fc)
/*  f14b55c:	3c0b8008 */ 	lui	$t3,%hi(var8007f900)
/*  f14b560:	3c014f80 */ 	lui	$at,0x4f80
/*  f14b564:	e4700010 */ 	swc1	$f16,0x10($v1)
/*  f14b568:	8d4af8fc */ 	lw	$t2,%lo(var8007f8fc)($t2)
/*  f14b56c:	ac6a0000 */ 	sw	$t2,0x0($v1)
/*  f14b570:	8d6bf900 */ 	lw	$t3,%lo(var8007f900)($t3)
/*  f14b574:	448b5000 */ 	mtc1	$t3,$f10
/*  f14b578:	05610004 */ 	bgez	$t3,.L0f14b58c
/*  f14b57c:	46805120 */ 	cvt.s.w	$f4,$f10
/*  f14b580:	44819000 */ 	mtc1	$at,$f18
/*  f14b584:	00000000 */ 	nop
/*  f14b588:	46122100 */ 	add.s	$f4,$f4,$f18
.L0f14b58c:
/*  f14b58c:	c4660024 */ 	lwc1	$f6,0x24($v1)
/*  f14b590:	c468003c */ 	lwc1	$f8,0x3c($v1)
/*  f14b594:	e4640050 */ 	swc1	$f4,0x50($v1)
/*  f14b598:	e4660020 */ 	swc1	$f6,0x20($v1)
/*  f14b59c:	e4680038 */ 	swc1	$f8,0x38($v1)
/*  f14b5a0:	0c012144 */ 	jal	osGetCount
/*  f14b5a4:	afa3001c */ 	sw	$v1,0x1c($sp)
/*  f14b5a8:	44828000 */ 	mtc1	$v0,$f16
/*  f14b5ac:	3c014170 */ 	lui	$at,0x4170
/*  f14b5b0:	44816000 */ 	mtc1	$at,$f12
/*  f14b5b4:	8fa3001c */ 	lw	$v1,0x1c($sp)
/*  f14b5b8:	04410005 */ 	bgez	$v0,.L0f14b5d0
/*  f14b5bc:	468082a0 */ 	cvt.s.w	$f10,$f16
/*  f14b5c0:	3c014f80 */ 	lui	$at,0x4f80
/*  f14b5c4:	44819000 */ 	mtc1	$at,$f18
/*  f14b5c8:	00000000 */ 	nop
/*  f14b5cc:	46125280 */ 	add.s	$f10,$f10,$f18
.L0f14b5d0:
/*  f14b5d0:	3c017f1b */ 	lui	$at,%hi(var7f1b72f0)
/*  f14b5d4:	c42472f0 */ 	lwc1	$f4,%lo(var7f1b72f0)($at)
/*  f14b5d8:	c4660020 */ 	lwc1	$f6,0x20($v1)
/*  f14b5dc:	46045002 */ 	mul.s	$f0,$f10,$f4
/*  f14b5e0:	46060081 */ 	sub.s	$f2,$f0,$f6
/*  f14b5e4:	e4600024 */ 	swc1	$f0,0x24($v1)
/*  f14b5e8:	4602603c */ 	c.lt.s	$f12,$f2
/*  f14b5ec:	e4620028 */ 	swc1	$f2,0x28($v1)
/*  f14b5f0:	45020003 */ 	bc1fl	.L0f14b600
/*  f14b5f4:	c468004c */ 	lwc1	$f8,0x4c($v1)
/*  f14b5f8:	e46c0028 */ 	swc1	$f12,0x28($v1)
/*  f14b5fc:	c468004c */ 	lwc1	$f8,0x4c($v1)
.L0f14b600:
/*  f14b600:	c4700050 */ 	lwc1	$f16,0x50($v1)
/*  f14b604:	c4620028 */ 	lwc1	$f2,0x28($v1)
/*  f14b608:	c46a0014 */ 	lwc1	$f10,0x14($v1)
/*  f14b60c:	46104001 */ 	sub.s	$f0,$f8,$f16
/*  f14b610:	3c0143fa */ 	lui	$at,0x43fa
/*  f14b614:	44817000 */ 	mtc1	$at,$f14
/*  f14b618:	3c01c3fa */ 	lui	$at,0xc3fa
/*  f14b61c:	46020483 */ 	div.s	$f18,$f0,$f2
/*  f14b620:	e460003c */ 	swc1	$f0,0x3c($v1)
/*  f14b624:	e460001c */ 	swc1	$f0,0x1c($v1)
/*  f14b628:	46020102 */ 	mul.s	$f4,$f0,$f2
/*  f14b62c:	44810000 */ 	mtc1	$at,$f0
/*  f14b630:	3c01bf80 */ 	lui	$at,0xbf80
/*  f14b634:	44818000 */ 	mtc1	$at,$f16
/*  f14b638:	3c014120 */ 	lui	$at,0x4120
/*  f14b63c:	46045180 */ 	add.s	$f6,$f10,$f4
/*  f14b640:	e4720018 */ 	swc1	$f18,0x18($v1)
/*  f14b644:	e4660014 */ 	swc1	$f6,0x14($v1)
/*  f14b648:	c46c0014 */ 	lwc1	$f12,0x14($v1)
/*  f14b64c:	460c703c */ 	c.lt.s	$f14,$f12
/*  f14b650:	00000000 */ 	nop
/*  f14b654:	45020004 */ 	bc1fl	.L0f14b668
/*  f14b658:	4600603c */ 	c.lt.s	$f12,$f0
/*  f14b65c:	e46e0014 */ 	swc1	$f14,0x14($v1)
/*  f14b660:	c46c0014 */ 	lwc1	$f12,0x14($v1)
/*  f14b664:	4600603c */ 	c.lt.s	$f12,$f0
.L0f14b668:
/*  f14b668:	00000000 */ 	nop
/*  f14b66c:	45020004 */ 	bc1fl	.L0f14b680
/*  f14b670:	c4680010 */ 	lwc1	$f8,0x10($v1)
/*  f14b674:	e4600014 */ 	swc1	$f0,0x14($v1)
/*  f14b678:	c46c0014 */ 	lwc1	$f12,0x14($v1)
/*  f14b67c:	c4680010 */ 	lwc1	$f8,0x10($v1)
.L0f14b680:
/*  f14b680:	c46a0018 */ 	lwc1	$f10,0x18($v1)
/*  f14b684:	c4640008 */ 	lwc1	$f4,0x8($v1)
/*  f14b688:	46104482 */ 	mul.s	$f18,$f8,$f16
/*  f14b68c:	c466001c */ 	lwc1	$f6,0x1c($v1)
/*  f14b690:	c468000c */ 	lwc1	$f8,0xc($v1)
/*  f14b694:	c4700004 */ 	lwc1	$f16,0x4($v1)
/*  f14b698:	8c6c0000 */ 	lw	$t4,0x0($v1)
/*  f14b69c:	460a9002 */ 	mul.s	$f0,$f18,$f10
/*  f14b6a0:	46008487 */ 	neg.s	$f18,$f16
/*  f14b6a4:	46062082 */ 	mul.s	$f2,$f4,$f6
/*  f14b6a8:	e4600034 */ 	swc1	$f0,0x34($v1)
/*  f14b6ac:	460c4382 */ 	mul.s	$f14,$f8,$f12
/*  f14b6b0:	46020280 */ 	add.s	$f10,$f0,$f2
/*  f14b6b4:	e462002c */ 	swc1	$f2,0x2c($v1)
/*  f14b6b8:	460e5100 */ 	add.s	$f4,$f10,$f14
/*  f14b6bc:	e46e0030 */ 	swc1	$f14,0x30($v1)
/*  f14b6c0:	46049182 */ 	mul.s	$f6,$f18,$f4
/*  f14b6c4:	11800066 */ 	beqz	$t4,.L0f14b860
/*  f14b6c8:	e4660040 */ 	swc1	$f6,0x40($v1)
/*  f14b6cc:	44806000 */ 	mtc1	$zero,$f12
/*  f14b6d0:	c460003c */ 	lwc1	$f0,0x3c($v1)
/*  f14b6d4:	44814000 */ 	mtc1	$at,$f8
/*  f14b6d8:	3c013f80 */ 	lui	$at,0x3f80
/*  f14b6dc:	4600603c */ 	c.lt.s	$f12,$f0
/*  f14b6e0:	00000000 */ 	nop
/*  f14b6e4:	45020004 */ 	bc1fl	.L0f14b6f8
/*  f14b6e8:	46000087 */ 	neg.s	$f2,$f0
/*  f14b6ec:	10000002 */ 	b	.L0f14b6f8
/*  f14b6f0:	46000086 */ 	mov.s	$f2,$f0
/*  f14b6f4:	46000087 */ 	neg.s	$f2,$f0
.L0f14b6f8:
/*  f14b6f8:	4602403c */ 	c.lt.s	$f8,$f2
/*  f14b6fc:	00000000 */ 	nop
/*  f14b700:	45020055 */ 	bc1fl	.L0f14b858
/*  f14b704:	44808000 */ 	mtc1	$zero,$f16
/*  f14b708:	c4600040 */ 	lwc1	$f0,0x40($v1)
/*  f14b70c:	44818000 */ 	mtc1	$at,$f16
/*  f14b710:	4600603c */ 	c.lt.s	$f12,$f0
/*  f14b714:	00000000 */ 	nop
/*  f14b718:	45020004 */ 	bc1fl	.L0f14b72c
/*  f14b71c:	46000087 */ 	neg.s	$f2,$f0
/*  f14b720:	10000002 */ 	b	.L0f14b72c
/*  f14b724:	46000086 */ 	mov.s	$f2,$f0
/*  f14b728:	46000087 */ 	neg.s	$f2,$f0
.L0f14b72c:
/*  f14b72c:	4602803e */ 	c.le.s	$f16,$f2
/*  f14b730:	00000000 */ 	nop
/*  f14b734:	4502004b */ 	bc1fl	.L0f14b864
/*  f14b738:	3c01428c */ 	lui	$at,0x428c
/*  f14b73c:	4600028d */ 	trunc.w.s	$f10,$f0
/*  f14b740:	8c6d0054 */ 	lw	$t5,0x54($v1)
/*  f14b744:	44804000 */ 	mtc1	$zero,$f8
/*  f14b748:	24080001 */ 	addiu	$t0,$zero,0x1
/*  f14b74c:	440f5000 */ 	mfc1	$t7,$f10
/*  f14b750:	00000000 */ 	nop
/*  f14b754:	01af1021 */ 	addu	$v0,$t5,$t7
/*  f14b758:	28410051 */ 	slti	$at,$v0,0x51
/*  f14b75c:	14200003 */ 	bnez	$at,.L0f14b76c
/*  f14b760:	ac620054 */ 	sw	$v0,0x54($v1)
/*  f14b764:	24020050 */ 	addiu	$v0,$zero,0x50
/*  f14b768:	ac620054 */ 	sw	$v0,0x54($v1)
.L0f14b76c:
/*  f14b76c:	5c400003 */ 	bgtzl	$v0,.L0f14b77c
/*  f14b770:	c4720044 */ 	lwc1	$f18,0x44($v1)
/*  f14b774:	ac680054 */ 	sw	$t0,0x54($v1)
/*  f14b778:	c4720044 */ 	lwc1	$f18,0x44($v1)
.L0f14b77c:
/*  f14b77c:	c4640040 */ 	lwc1	$f4,0x40($v1)
/*  f14b780:	3c0142a0 */ 	lui	$at,0x42a0
/*  f14b784:	44811000 */ 	mtc1	$at,$f2
/*  f14b788:	46049180 */ 	add.s	$f6,$f18,$f4
/*  f14b78c:	3c013f80 */ 	lui	$at,0x3f80
/*  f14b790:	e4660044 */ 	swc1	$f6,0x44($v1)
/*  f14b794:	c4600044 */ 	lwc1	$f0,0x44($v1)
/*  f14b798:	4600103c */ 	c.lt.s	$f2,$f0
/*  f14b79c:	00000000 */ 	nop
/*  f14b7a0:	45020004 */ 	bc1fl	.L0f14b7b4
/*  f14b7a4:	44811000 */ 	mtc1	$at,$f2
/*  f14b7a8:	e4620044 */ 	swc1	$f2,0x44($v1)
/*  f14b7ac:	c4600044 */ 	lwc1	$f0,0x44($v1)
/*  f14b7b0:	44811000 */ 	mtc1	$at,$f2
.L0f14b7b4:
/*  f14b7b4:	00000000 */ 	nop
/*  f14b7b8:	4602003c */ 	c.lt.s	$f0,$f2
/*  f14b7bc:	00000000 */ 	nop
/*  f14b7c0:	45020003 */ 	bc1fl	.L0f14b7d0
/*  f14b7c4:	8c690054 */ 	lw	$t1,0x54($v1)
/*  f14b7c8:	e4620044 */ 	swc1	$f2,0x44($v1)
/*  f14b7cc:	8c690054 */ 	lw	$t1,0x54($v1)
.L0f14b7d0:
/*  f14b7d0:	3c058008 */ 	lui	$a1,%hi(var8007f904)
/*  f14b7d4:	24a5f904 */ 	addiu	$a1,$a1,%lo(var8007f904)
/*  f14b7d8:	00095040 */ 	sll	$t2,$t1,0x1
/*  f14b7dc:	00aa5821 */ 	addu	$t3,$a1,$t2
/*  f14b7e0:	95620000 */ 	lhu	$v0,0x0($t3)
/*  f14b7e4:	ac62005c */ 	sw	$v0,0x5c($v1)
/*  f14b7e8:	94a40002 */ 	lhu	$a0,0x2($a1)
/*  f14b7ec:	0044082a */ 	slt	$at,$v0,$a0
/*  f14b7f0:	5020000b */ 	beqzl	$at,.L0f14b820
/*  f14b7f4:	94a400a0 */ 	lhu	$a0,0xa0($a1)
/*  f14b7f8:	8c6e0060 */ 	lw	$t6,0x60($v1)
/*  f14b7fc:	ac64005c */ 	sw	$a0,0x5c($v1)
/*  f14b800:	24180002 */ 	addiu	$t8,$zero,0x2
/*  f14b804:	25cdffff */ 	addiu	$t5,$t6,-1
/*  f14b808:	29a10002 */ 	slti	$at,$t5,0x2
/*  f14b80c:	1020000f */ 	beqz	$at,.L0f14b84c
/*  f14b810:	ac6d0060 */ 	sw	$t5,0x60($v1)
/*  f14b814:	1000000d */ 	b	.L0f14b84c
/*  f14b818:	ac780060 */ 	sw	$t8,0x60($v1)
/*  f14b81c:	94a400a0 */ 	lhu	$a0,0xa0($a1)
.L0f14b820:
/*  f14b820:	0082082a */ 	slt	$at,$a0,$v0
/*  f14b824:	10200009 */ 	beqz	$at,.L0f14b84c
/*  f14b828:	00000000 */ 	nop
/*  f14b82c:	8c790060 */ 	lw	$t9,0x60($v1)
/*  f14b830:	ac64005c */ 	sw	$a0,0x5c($v1)
/*  f14b834:	240a000a */ 	addiu	$t2,$zero,0xa
/*  f14b838:	27280001 */ 	addiu	$t0,$t9,0x1
/*  f14b83c:	2901000b */ 	slti	$at,$t0,0xb
/*  f14b840:	14200002 */ 	bnez	$at,.L0f14b84c
/*  f14b844:	ac680060 */ 	sw	$t0,0x60($v1)
/*  f14b848:	ac6a0060 */ 	sw	$t2,0x60($v1)
.L0f14b84c:
/*  f14b84c:	10000004 */ 	b	.L0f14b860
/*  f14b850:	e4680014 */ 	swc1	$f8,0x14($v1)
/*  f14b854:	44808000 */ 	mtc1	$zero,$f16
.L0f14b858:
/*  f14b858:	00000000 */ 	nop
/*  f14b85c:	e4700014 */ 	swc1	$f16,0x14($v1)
.L0f14b860:
/*  f14b860:	3c01428c */ 	lui	$at,0x428c
.L0f14b864:
/*  f14b864:	44815000 */ 	mtc1	$at,$f10
/*  f14b868:	c460004c */ 	lwc1	$f0,0x4c($v1)
/*  f14b86c:	3c014320 */ 	lui	$at,0x4320
/*  f14b870:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f14b874:	460a003c */ 	c.lt.s	$f0,$f10
/*  f14b878:	00000000 */ 	nop
/*  f14b87c:	45010007 */ 	bc1t	.L0f14b89c
/*  f14b880:	00000000 */ 	nop
/*  f14b884:	44819000 */ 	mtc1	$at,$f18
/*  f14b888:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f14b88c:	4600903c */ 	c.lt.s	$f18,$f0
/*  f14b890:	00000000 */ 	nop
/*  f14b894:	45000003 */ 	bc1f	.L0f14b8a4
/*  f14b898:	00000000 */ 	nop
.L0f14b89c:
/*  f14b89c:	10000001 */ 	b	.L0f14b8a4
/*  f14b8a0:	00001025 */ 	or	$v0,$zero,$zero
.L0f14b8a4:
/*  f14b8a4:	03e00008 */ 	jr	$ra
/*  f14b8a8:	27bd0020 */ 	addiu	$sp,$sp,0x20
);

void func0f14b8ac(s32 index)
{
	struct var8007f8dc *thing = &var8007f8dc[index];

	func0000db30("kg", &var8007f8e8);
	func0000db30("Kp", &var8007f8ec);
	func0000db30("Ki", &var8007f8f0);
	func0000db30("Kd", &var8007f8f4);
	func0000db30("tInt", &var8007f8f8);
	func0000db30("gocal", &var8007f8fc);
	func0000db30("aim", &var8007f900);

	if (thing->unk0d4_00) {
		func0f14cf6c();
		return;
	}

	func0f14a95c();

	if (pak0f11d3f8(func0f14a5a4())) {
		pak0f11d620(func0f14a5a4());

		if (thing->unk0f8 == 0 && var8007f8dc[var800a45a0->unk000].unk0d4_04 == false) {
			func0f14e790(var800a45a0->unk470);
			func0f14a16c(1);
			func0f14bc04();
			return;
		}

		switch (pakGetUnk008(func0f14a5a4())) {
		case 12:
			func0f14a95c();
			func0f14aa48();
			func0f14e790(var800a45a0->unk470);
			func0f14cf6c();
			pak0f11e3bc(func0f14a5a4());
			func0f14a16c(1);
			func0f14bc04();
			break;
		case 1:
			pak0f11d4dc(func0f14a5a4());
			break;
		case 11:
			pak0f11d9c4(func0f14a5a4(), var800a45a0->unk470, 0, 0);
			func0f14d064(index, var800a45a0->unk470);
			pak0f11d478(func0f14a5a4());

			if (thing->unk0f8 == 0) {
				func0f14a16c(3);
				func0f14bc04();

				if (var8007f8dc[var800a45a0->unk000].unk0d4_04) {
					struct var8007f8e0 *thing2 = func0f14a06c(-1);
					thing2->unk3f4_00 = true;
				}
			} else {
				func0f14a16c(4);
				func0f14bc04();
			}

			if (!func0f14a8e8()) {
				func0f14b484(var800a45a0->unk000);
			}
			break;
		}
	} else {
		func0f14cf6c();
		func0f14e7e0(var800a45a0->unk470);
		func0f14a16c(3);
		func0f14bc04();
	}
}

const char var7f1b67f8[] = "CAM : Cam_MakeTextures\n";

void func0f14bc04(void)
{
	struct var8007f8e0 *thing1 = func0f14a06c(-1);
	struct var8007f8dc *thing2 = func0f14a20c();

	thing1->unk3f4_02 = true;

	switch (thing2->unk100) {
	case 0:
		break;
	case 1:
		thing1->unk3f4_02 = false;
		func0f14d714(var800a45a0->unk470, thing1->unk01c);
		break;
	case 4:
		func0f14d714(var800a45a0->unk470, thing1->unk01c);
		break;
	case 2:
		func0f14d2c8(var800a45a0->unk470, thing1->unk01c);
		break;
	case 3:
		func0f14d4f0(var800a45a0->unk470, thing1->unk01c);
		break;
	case 5:
		func0f14ff94(thing1);
		break;
	}

	func0f14def0(-1, 2433, "camdraw.c");

	if (thing2->unk100 != 4) {
		func0f14dac0(var800a45a0->unk470, &thing1->unk010);
	}

	thing1->unk3f4_03 = false;
}

const char var7f1b681c[] = "pD->ReadMode = %s";
const char var7f1b6830[] = "Camera -> Getting Header Info\n";
const char var7f1b6850[] = "Camera -> Item=%d, pD->CamHeader[i]=%d\n";
const char var7f1b6878[] = "Camera -> Found %d Valid images\n";
const char var7f1b689c[] = "Camera -> Item=%d, Valid=%s, Bank=%d\n";
const char var7f1b68c4[] = "YES";
const char var7f1b68c8[] = "NO";
const char var7f1b68cc[] = "CD_TransferCurrentCacheToEditorAndExit : Player=%d, pD->CamRdImg=%d\n";
const char var7f1b6914[] = "Camera -> CD_CycleHandleRead - Need to load up the camera header\n";
const char var7f1b6958[] = "Camera -> CD_CycleHandleRead - Image %d needs loading for editor coppying on menu exit\n";
const char var7f1b69b0[] = "Camera -> CD_CycleHandleRead - Error ekCamReadModeExit2 in Null cycle\n";
const char var7f1b69f8[] = "CAMERA : COPY SLOT (%d of %s): Slot %d(%s) -> Slot %d(%s)\n";
const char var7f1b6a34[] = "ACTIVE";
const char var7f1b6a3c[] = "NULL";
const char var7f1b6a44[] = "ACTIVE";
const char var7f1b6a4c[] = "NULL";
const char var7f1b6a54[] = "RWI : Warning -> Not copying the thumbnail texture\n";
const char var7f1b6a88[] = "CD_DrawTexture : pTex=%x\n";
const char var7f1b6aa4[] = "Cam -> WARNING - Not done intensity table recalc :- No samples within threshold\n";
const char var7f1b6af8[] = "Camera -> Call to reset auto calibrate\n";
const char var7f1b6b20[] = "AC -> ekCamAutoCalStatusReset - pD->tTime = %d, pD->tTimeNxAdd = %d\n";
const char var7f1b6b68[] = "Cam 0 -> Time = %d, Target = %d, tInt = %.2f\n";
const char var7f1b6b98[] = "Cam 0 -> Too Low -> Adding Time\n";
const char var7f1b6bbc[] = "Cam 0 -> Too High -> Subbing Time\n";
const char var7f1b6be0[] = "Cam -> ekCamAutoCalStatusSettingTime - New time = %d\n";
const char var7f1b6c18[] = "%s%sAC -> Gain = %d, Target = %.2f, tInt = %.2f\n";
const char var7f1b6c4c[] = "";
const char var7f1b6c50[] = "";
const char var7f1b6c54[] = "Auto Calibrate is removing the menu message\n";
const char var7f1b6c84[] = "Auto Calibrate is shutting down\n";
const char var7f1b6ca8[] = "Cam -> Cam_BalanceSlot %d -> tZroShift = %d\n";
const char var7f1b6cd8[] = "Cam_BuildFaceTexture (slot=%d): %d of %s\n";

void func0f14bd34(s32 index)
{
	struct var8007f8dc *thing = &var8007f8dc[index];

	if (thing->unk080 != -1) {
		pak0f1171b4(func0f14a5a4(), 3, 0);
		pak0f11d540(func0f14a5a4(), thing->unk0b6[thing->unk080]);
	}
}

void func0f14bdbc(s32 index)
{
	struct var8007f8dc *thing = &var8007f8dc[index];
	struct var8007f8e0 *thing2;
	s32 i;
	s32 value;

	for (i = 0; i < 30; i++) {
		thing->unk0dc[i] = 0;
	}

	thing->unk094 = 0;

	for (i = 0; i < 30; i++) {
		thing->unk098[i] = 0xff;
		thing->unk0b6[i] = 0xff;
	}

	value = var8007f8dc[index].unk0f4;

	if (value == 4 || value == 5) {
		thing->unk0f4 = 6;
		g_MpPlayerNum = index;
		func0f0f0ca0(-1, false);

		thing2 = func0f14a06c(-1);
		thing2->unk3f4_00 = false;

		g_MpPlayerNum = index;

		menuPopDialog();

		g_MpPlayerNum = 0;
	} else {
		pak0f11e3bc(func0f14a5a4());

		thing->unk0f4 = 0;
	}
}

void func0f14bec8(s32 index)
{
	struct var8007f8dc *thing = &var8007f8dc[index];
	struct var8007f8e0 *thing2 = func0f14a06c(-1);
	struct var800a45a0_484 *thing3;
	s32 i;

	if (thing->unk0f4 == 4 && thing->unk080 == thing->unk074) {
		thing->unk0f4 = 5;
	}

	switch (thing->unk0f4) {
	case 1:
		pak0f11d9c4(index, NULL, thing->unk098, 0);
		thing->unk0f4 = 2;

		for (i = 0; i < 30; i++) {
			if (thing->unk098[i] != 0xff) {
				thing->unk098[i] += 2;
			}
		}

		for (i = 0, thing->unk094 = 0; i < 30; i++) {
			if (thing->unk098[i] != 0xff) {
				thing->unk0b6[thing->unk094] = thing->unk098[i];
				thing->unk094++;
			}
		}

		for (i = thing->unk094; i < 30; i++) {
			thing->unk0b6[i] = 0xff;
		}

		if (thing->unk094);

		for (i = 0; i < 30; i++);

		pak0f1171b4(func0f14a5a4(), 3, 0);
		pak0f11d478(func0f14a5a4());
		break;
	case 3:
		pak0f11d9c4(func0f14a5a4(), var800a45a0->unk470, 0, 1);
		thing3 = &var800a45a0->unk484[thing->unk080];
		func0f14a16c(2);
		func0f14bc04();
		func0f14c75c(thing3, &thing2->unk004);
		thing->unk0dc[thing->unk080] = 1;
		pak0f11d478(func0f14a5a4());
		break;
	case 4:
		pak0f11d478(func0f14a5a4());
		break;
	case 5:
		pak0f11d9c4(func0f14a5a4(), var800a45a0->unk470, 0, 1);
		func0f14a16c(3);
		func0f14bc04();
		pak0f11d478(func0f14a5a4());
		g_MpPlayerNum = index;
		func0f0f0ca0(-1, false);
		func0f14a678();
		thing2->unk3f4_00 = true;
		g_MpPlayerNum = index;
		stub0f102230();
		g_MpPlayerNum = 0;
		thing->unk0f4 = 6;
		break;
	case 2:
	case 6:
		break;
	}
}

void func0f14c1cc(s32 index)
{
	struct var8007f8dc *thing = &var8007f8dc[index];
	s32 count = func0f14f008(index);
	s32 max = count / 2 + 1;
	s32 i;

	switch (thing->unk0f4) {
	case 0:
		pak0f1171b4(func0f14a5a4(), 0, 0);
		pak0f11d5b0(func0f14a5a4());
		thing->unk0f4 = 1;
		break;
	case 2:
		thing->unk0f4 = 3;
		break;
	case 4:
		if (thing->unk074 != thing->unk080) {
			thing->unk0dc[thing->unk074] = 0;
			thing->unk080 = thing->unk074;
			thing->unk0f4 = 5;

			func0f14bd34(index);
		}
		break;
	case 3:
		thing->unk080 = -1;

		for (i = 0; i < max; i++) {
			s32 a = (thing->unk074 + i) % count;
			s32 b = thing->unk074 - i;

			if (b < 0) {
				b += count;
			}

			if (thing->unk0dc[a] == 0 && thing->unk0b6[a] != 0xff) {
				thing->unk080 = a;
				break;
			}

			if (thing->unk0dc[b] == 0 && thing->unk0b6[b] != 0xff) {
				thing->unk080 = b;
				break;
			}
		}
		func0f14bd34(index);
		break;
	case 1:
	case 5:
		break;
	}
}

void func0f14c3a4(s32 index)
{
	struct var8007f8dc *thing = &var8007f8dc[index];
	s32 i;

	if (pak0f11d3f8(func0f14a5a4()) == 0) {
		for (i = 0; i < 30; i++) {
			thing->unk0dc[i] = 0;
		}

		for (i = 0; i < 30; i++) {
			thing->unk094 = 0;
			thing->unk098[i] = 0xff;
			thing->unk0b6[i] = 0xff;
		}
	} else {
		pak0f11d620(func0f14a5a4());

		switch (pakGetUnk008(func0f14a5a4())) {
		case 1:
			func0f14c1cc(index);
			break;
		case 11:
			func0f14bec8(index);
			break;
		case 12:
			func0f14bdbc(index);
			break;
		}
	}
}

void func0f14c4c0(s32 index)
{
	var8007f8dc[index].unk0f4 = 4;
	g_MpPlayerNum = index;

	func0f0f0ca0(2, false);
}

GLOBAL_ASM(
glabel func0f14c50c
/*  f14c50c:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*  f14c510:	afa60028 */ 	sw	$a2,0x28($sp)
/*  f14c514:	afb10018 */ 	sw	$s1,0x18($sp)
/*  f14c518:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f14c51c:	3c068008 */ 	lui	$a2,%hi(var8007f8e0)
/*  f14c520:	00808025 */ 	or	$s0,$a0,$zero
/*  f14c524:	00a08825 */ 	or	$s1,$a1,$zero
/*  f14c528:	afbf001c */ 	sw	$ra,0x1c($sp)
/*  f14c52c:	afa7002c */ 	sw	$a3,0x2c($sp)
/*  f14c530:	8cc6f8e0 */ 	lw	$a2,%lo(var8007f8e0)($a2)
/*  f14c534:	00001025 */ 	or	$v0,$zero,$zero
/*  f14c538:	24420001 */ 	addiu	$v0,$v0,0x1
.L0f14c53c:
/*  f14c53c:	28410016 */ 	slti	$at,$v0,0x16
/*  f14c540:	5420fffe */ 	bnezl	$at,.L0f14c53c
/*  f14c544:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f14c548:	8e2203f4 */ 	lw	$v0,0x3f4($s1)
/*  f14c54c:	920c03f4 */ 	lbu	$t4,0x3f4($s0)
/*  f14c550:	02001825 */ 	or	$v1,$s0,$zero
/*  f14c554:	00027fc2 */ 	srl	$t7,$v0,0x1f
/*  f14c558:	000fc9c0 */ 	sll	$t9,$t7,0x7
/*  f14c55c:	318dff7f */ 	andi	$t5,$t4,0xff7f
/*  f14c560:	032d7025 */ 	or	$t6,$t9,$t5
/*  f14c564:	a20e03f4 */ 	sb	$t6,0x3f4($s0)
/*  f14c568:	8e2f03f4 */ 	lw	$t7,0x3f4($s1)
/*  f14c56c:	00001025 */ 	or	$v0,$zero,$zero
/*  f14c570:	02202025 */ 	or	$a0,$s1,$zero
/*  f14c574:	000fc040 */ 	sll	$t8,$t7,0x1
/*  f14c578:	001867c2 */ 	srl	$t4,$t8,0x1f
/*  f14c57c:	000cc980 */ 	sll	$t9,$t4,0x6
/*  f14c580:	332d0040 */ 	andi	$t5,$t9,0x40
/*  f14c584:	31cf00bf */ 	andi	$t7,$t6,0xbf
/*  f14c588:	01afc025 */ 	or	$t8,$t5,$t7
/*  f14c58c:	a21803f4 */ 	sb	$t8,0x3f4($s0)
/*  f14c590:	8e2c03f4 */ 	lw	$t4,0x3f4($s1)
/*  f14c594:	24050007 */ 	addiu	$a1,$zero,0x7
/*  f14c598:	240a003f */ 	addiu	$t2,$zero,0x3f
/*  f14c59c:	000cc880 */ 	sll	$t9,$t4,0x2
/*  f14c5a0:	001977c2 */ 	srl	$t6,$t9,0x1f
/*  f14c5a4:	000e6940 */ 	sll	$t5,$t6,0x5
/*  f14c5a8:	31af0020 */ 	andi	$t7,$t5,0x20
/*  f14c5ac:	330c00df */ 	andi	$t4,$t8,0xdf
/*  f14c5b0:	01ecc825 */ 	or	$t9,$t7,$t4
/*  f14c5b4:	a21903f4 */ 	sb	$t9,0x3f4($s0)
/*  f14c5b8:	8e2e03f4 */ 	lw	$t6,0x3f4($s1)
/*  f14c5bc:	00004025 */ 	or	$t0,$zero,$zero
/*  f14c5c0:	24070fc0 */ 	addiu	$a3,$zero,0xfc0
/*  f14c5c4:	000e68c0 */ 	sll	$t5,$t6,0x3
/*  f14c5c8:	000dc7c2 */ 	srl	$t8,$t5,0x1f
/*  f14c5cc:	00187900 */ 	sll	$t7,$t8,0x4
/*  f14c5d0:	31ec0010 */ 	andi	$t4,$t7,0x10
/*  f14c5d4:	332e00ef */ 	andi	$t6,$t9,0xef
/*  f14c5d8:	018e6825 */ 	or	$t5,$t4,$t6
/*  f14c5dc:	a20d03f4 */ 	sb	$t5,0x3f4($s0)
/*  f14c5e0:	8e38039c */ 	lw	$t8,0x39c($s1)
/*  f14c5e4:	240bffc0 */ 	addiu	$t3,$zero,-64
/*  f14c5e8:	24090040 */ 	addiu	$t1,$zero,0x40
/*  f14c5ec:	ae18039c */ 	sw	$t8,0x39c($s0)
/*  f14c5f0:	8e2f03a0 */ 	lw	$t7,0x3a0($s1)
/*  f14c5f4:	ae0f03a0 */ 	sw	$t7,0x3a0($s0)
/*  f14c5f8:	8e3903a4 */ 	lw	$t9,0x3a4($s1)
/*  f14c5fc:	ae1903a4 */ 	sw	$t9,0x3a4($s0)
/*  f14c600:	8e2c03b4 */ 	lw	$t4,0x3b4($s1)
/*  f14c604:	ae0c03b4 */ 	sw	$t4,0x3b4($s0)
/*  f14c608:	8e2e03b8 */ 	lw	$t6,0x3b8($s1)
/*  f14c60c:	ae0e03b8 */ 	sw	$t6,0x3b8($s0)
/*  f14c610:	8e2d03bc */ 	lw	$t5,0x3bc($s1)
/*  f14c614:	ae0d03bc */ 	sw	$t5,0x3bc($s0)
/*  f14c618:	8e3803c0 */ 	lw	$t8,0x3c0($s1)
/*  f14c61c:	ae1803c0 */ 	sw	$t8,0x3c0($s0)
/*  f14c620:	8e2f03c4 */ 	lw	$t7,0x3c4($s1)
/*  f14c624:	ae0f03c4 */ 	sw	$t7,0x3c4($s0)
/*  f14c628:	8e3903c8 */ 	lw	$t9,0x3c8($s1)
/*  f14c62c:	ae1903c8 */ 	sw	$t9,0x3c8($s0)
/*  f14c630:	8e2c03cc */ 	lw	$t4,0x3cc($s1)
/*  f14c634:	ae0c03cc */ 	sw	$t4,0x3cc($s0)
/*  f14c638:	8e2e03ec */ 	lw	$t6,0x3ec($s1)
/*  f14c63c:	ae0e03ec */ 	sw	$t6,0x3ec($s0)
/*  f14c640:	8e2d03f0 */ 	lw	$t5,0x3f0($s1)
/*  f14c644:	ae0d03f0 */ 	sw	$t5,0x3f0($s0)
/*  f14c648:	8e3803f8 */ 	lw	$t8,0x3f8($s1)
/*  f14c64c:	ae1803f8 */ 	sw	$t8,0x3f8($s0)
/*  f14c650:	962f03fc */ 	lhu	$t7,0x3fc($s1)
/*  f14c654:	a60f03fc */ 	sh	$t7,0x3fc($s0)
.L0f14c658:
/*  f14c658:	c48403d0 */ 	lwc1	$f4,0x3d0($a0)
/*  f14c65c:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f14c660:	24630004 */ 	addiu	$v1,$v1,0x4
/*  f14c664:	24840004 */ 	addiu	$a0,$a0,0x4
/*  f14c668:	1445fffb */ 	bne	$v0,$a1,.L0f14c658
/*  f14c66c:	e46403cc */ 	swc1	$f4,0x3cc($v1)
/*  f14c670:	8e19001c */ 	lw	$t9,0x1c($s0)
/*  f14c674:	1320001a */ 	beqz	$t9,.L0f14c6e0
.L0f14c678:
/*  f14c678:	00001025 */ 	or	$v0,$zero,$zero
/*  f14c67c:	31460001 */ 	andi	$a2,$t2,0x1
.L0f14c680:
/*  f14c680:	10c00008 */ 	beqz	$a2,.L0f14c6a4
/*  f14c684:	8e05001c */ 	lw	$a1,0x1c($s0)
/*  f14c688:	304c0004 */ 	andi	$t4,$v0,0x4
/*  f14c68c:	11800003 */ 	beqz	$t4,.L0f14c69c
/*  f14c690:	24030004 */ 	addiu	$v1,$zero,0x4
/*  f14c694:	10000004 */ 	b	.L0f14c6a8
/*  f14c698:	2404fffc */ 	addiu	$a0,$zero,-4
.L0f14c69c:
/*  f14c69c:	10000002 */ 	b	.L0f14c6a8
/*  f14c6a0:	00602025 */ 	or	$a0,$v1,$zero
.L0f14c6a4:
/*  f14c6a4:	00002025 */ 	or	$a0,$zero,$zero
.L0f14c6a8:
/*  f14c6a8:	8e2e0004 */ 	lw	$t6,0x4($s1)
/*  f14c6ac:	00a8c821 */ 	addu	$t9,$a1,$t0
/*  f14c6b0:	03226021 */ 	addu	$t4,$t9,$v0
/*  f14c6b4:	008e6821 */ 	addu	$t5,$a0,$t6
/*  f14c6b8:	01a7c021 */ 	addu	$t8,$t5,$a3
/*  f14c6bc:	03027821 */ 	addu	$t7,$t8,$v0
/*  f14c6c0:	91e30000 */ 	lbu	$v1,0x0($t7)
/*  f14c6c4:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f14c6c8:	1449ffed */ 	bne	$v0,$t1,.L0f14c680
/*  f14c6cc:	a1830000 */ 	sb	$v1,0x0($t4)
/*  f14c6d0:	24e7ffc0 */ 	addiu	$a3,$a3,-64
/*  f14c6d4:	254affff */ 	addiu	$t2,$t2,-1
/*  f14c6d8:	1567ffe7 */ 	bne	$t3,$a3,.L0f14c678
/*  f14c6dc:	25080040 */ 	addiu	$t0,$t0,0x40
.L0f14c6e0:
/*  f14c6e0:	26040004 */ 	addiu	$a0,$s0,0x4
/*  f14c6e4:	0fc531d7 */ 	jal	func0f14c75c
/*  f14c6e8:	26250004 */ 	addiu	$a1,$s1,0x4
/*  f14c6ec:	8e0e0010 */ 	lw	$t6,0x10($s0)
/*  f14c6f0:	51c00008 */ 	beqzl	$t6,.L0f14c714
/*  f14c6f4:	8e3803f4 */ 	lw	$t8,0x3f4($s1)
/*  f14c6f8:	8e2d0010 */ 	lw	$t5,0x10($s1)
/*  f14c6fc:	26040010 */ 	addiu	$a0,$s0,0x10
/*  f14c700:	51a00004 */ 	beqzl	$t5,.L0f14c714
/*  f14c704:	8e3803f4 */ 	lw	$t8,0x3f4($s1)
/*  f14c708:	0fc531d7 */ 	jal	func0f14c75c
/*  f14c70c:	26250010 */ 	addiu	$a1,$s1,0x10
/*  f14c710:	8e3803f4 */ 	lw	$t8,0x3f4($s1)
.L0f14c714:
/*  f14c714:	00001025 */ 	or	$v0,$zero,$zero
/*  f14c718:	24030400 */ 	addiu	$v1,$zero,0x400
/*  f14c71c:	0018c8c0 */ 	sll	$t9,$t8,0x3
/*  f14c720:	0723000a */ 	bgezl	$t9,.L0f14c74c
/*  f14c724:	8fbf001c */ 	lw	$ra,0x1c($sp)
.L0f14c728:
/*  f14c728:	8e2c0020 */ 	lw	$t4,0x20($s1)
/*  f14c72c:	8e180020 */ 	lw	$t8,0x20($s0)
/*  f14c730:	01827021 */ 	addu	$t6,$t4,$v0
/*  f14c734:	91cd0000 */ 	lbu	$t5,0x0($t6)
/*  f14c738:	03027821 */ 	addu	$t7,$t8,$v0
/*  f14c73c:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f14c740:	1443fff9 */ 	bne	$v0,$v1,.L0f14c728
/*  f14c744:	a1ed0000 */ 	sb	$t5,0x0($t7)
/*  f14c748:	8fbf001c */ 	lw	$ra,0x1c($sp)
.L0f14c74c:
/*  f14c74c:	8fb00014 */ 	lw	$s0,0x14($sp)
/*  f14c750:	8fb10018 */ 	lw	$s1,0x18($sp)
/*  f14c754:	03e00008 */ 	jr	$ra
/*  f14c758:	27bd0020 */ 	addiu	$sp,$sp,0x20
);

GLOBAL_ASM(
glabel func0f14c75c
/*  f14c75c:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*  f14c760:	afbf001c */ 	sw	$ra,0x1c($sp)
/*  f14c764:	afb10018 */ 	sw	$s1,0x18($sp)
/*  f14c768:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f14c76c:	00808025 */ 	or	$s0,$a0,$zero
/*  f14c770:	0fc53205 */ 	jal	func0f14c814
/*  f14c774:	00a08825 */ 	or	$s1,$a1,$zero
/*  f14c778:	0fc5db70 */ 	jal	align32
/*  f14c77c:	00402025 */ 	or	$a0,$v0,$zero
/*  f14c780:	02202025 */ 	or	$a0,$s1,$zero
/*  f14c784:	0fc53205 */ 	jal	func0f14c814
/*  f14c788:	afa20020 */ 	sw	$v0,0x20($sp)
/*  f14c78c:	0fc5db70 */ 	jal	align32
/*  f14c790:	00402025 */ 	or	$a0,$v0,$zero
/*  f14c794:	8fa50020 */ 	lw	$a1,0x20($sp)
/*  f14c798:	00001825 */ 	or	$v1,$zero,$zero
/*  f14c79c:	50a0000b */ 	beqzl	$a1,.L0f14c7cc
/*  f14c7a0:	8fbf001c */ 	lw	$ra,0x1c($sp)
.L0f14c7a4:
/*  f14c7a4:	8e2e0000 */ 	lw	$t6,0x0($s1)
/*  f14c7a8:	8e190000 */ 	lw	$t9,0x0($s0)
/*  f14c7ac:	01c37821 */ 	addu	$t7,$t6,$v1
/*  f14c7b0:	03234021 */ 	addu	$t0,$t9,$v1
/*  f14c7b4:	91f80000 */ 	lbu	$t8,0x0($t7)
/*  f14c7b8:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f14c7bc:	0065082b */ 	sltu	$at,$v1,$a1
/*  f14c7c0:	1420fff8 */ 	bnez	$at,.L0f14c7a4
/*  f14c7c4:	a1180000 */ 	sb	$t8,0x0($t0)
/*  f14c7c8:	8fbf001c */ 	lw	$ra,0x1c($sp)
.L0f14c7cc:
/*  f14c7cc:	8fb00014 */ 	lw	$s0,0x14($sp)
/*  f14c7d0:	8fb10018 */ 	lw	$s1,0x18($sp)
/*  f14c7d4:	03e00008 */ 	jr	$ra
/*  f14c7d8:	27bd0028 */ 	addiu	$sp,$sp,0x28
);

GLOBAL_ASM(
glabel func0f14c7dc
/*  f14c7dc:	24030001 */ 	addiu	$v1,$zero,0x1
/*  f14c7e0:	24020040 */ 	addiu	$v0,$zero,0x40
/*  f14c7e4:	240e0004 */ 	addiu	$t6,$zero,0x4
/*  f14c7e8:	a0820004 */ 	sb	$v0,0x4($a0)
/*  f14c7ec:	a0820005 */ 	sb	$v0,0x5($a0)
/*  f14c7f0:	a0800006 */ 	sb	$zero,0x6($a0)
/*  f14c7f4:	a08e0007 */ 	sb	$t6,0x7($a0)
/*  f14c7f8:	a0830008 */ 	sb	$v1,0x8($a0)
/*  f14c7fc:	a0800009 */ 	sb	$zero,0x9($a0)
/*  f14c800:	a083000a */ 	sb	$v1,0xa($a0)
/*  f14c804:	03e00008 */ 	jr	$ra
/*  f14c808:	a083000b */ 	sb	$v1,0xb($a0)
/*  f14c80c:	03e00008 */ 	jr	$ra
/*  f14c810:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel func0f14c814
/*  f14c814:	908e0004 */ 	lbu	$t6,0x4($a0)
/*  f14c818:	908f0005 */ 	lbu	$t7,0x5($a0)
/*  f14c81c:	90820008 */ 	lbu	$v0,0x8($a0)
/*  f14c820:	24010001 */ 	addiu	$at,$zero,0x1
/*  f14c824:	01cf0019 */ 	multu	$t6,$t7
/*  f14c828:	00001812 */ 	mflo	$v1
/*  f14c82c:	10400009 */ 	beqz	$v0,.L0f14c854
/*  f14c830:	00000000 */ 	nop
/*  f14c834:	1041000c */ 	beq	$v0,$at,.L0f14c868
/*  f14c838:	24010002 */ 	addiu	$at,$zero,0x2
/*  f14c83c:	10410007 */ 	beq	$v0,$at,.L0f14c85c
/*  f14c840:	24010003 */ 	addiu	$at,$zero,0x3
/*  f14c844:	10410007 */ 	beq	$v0,$at,.L0f14c864
/*  f14c848:	00034080 */ 	sll	$t0,$v1,0x2
/*  f14c84c:	03e00008 */ 	jr	$ra
/*  f14c850:	00601025 */ 	or	$v0,$v1,$zero
.L0f14c854:
/*  f14c854:	03e00008 */ 	jr	$ra
/*  f14c858:	00031042 */ 	srl	$v0,$v1,0x1
.L0f14c85c:
/*  f14c85c:	03e00008 */ 	jr	$ra
/*  f14c860:	00031040 */ 	sll	$v0,$v1,0x1
.L0f14c864:
/*  f14c864:	01001825 */ 	or	$v1,$t0,$zero
.L0f14c868:
/*  f14c868:	03e00008 */ 	jr	$ra
/*  f14c86c:	00601025 */ 	or	$v0,$v1,$zero
);

GLOBAL_ASM(
glabel func0f14c870
/*  f14c870:	27bdffc0 */ 	addiu	$sp,$sp,-64
/*  f14c874:	afbf0024 */ 	sw	$ra,0x24($sp)
/*  f14c878:	afa40040 */ 	sw	$a0,0x40($sp)
/*  f14c87c:	afa7004c */ 	sw	$a3,0x4c($sp)
/*  f14c880:	3c013f00 */ 	lui	$at,0x3f00
/*  f14c884:	44810000 */ 	mtc1	$at,$f0
/*  f14c888:	c4c20000 */ 	lwc1	$f2,0x0($a2)
/*  f14c88c:	3c014080 */ 	lui	$at,0x4080
/*  f14c890:	44818000 */ 	mtc1	$at,$f16
/*  f14c894:	46001100 */ 	add.s	$f4,$f2,$f0
/*  f14c898:	240b0001 */ 	addiu	$t3,$zero,0x1
/*  f14c89c:	3c014f00 */ 	lui	$at,0x4f00
/*  f14c8a0:	46102182 */ 	mul.s	$f6,$f4,$f16
/*  f14c8a4:	444ef800 */ 	cfc1	$t6,$31
/*  f14c8a8:	44cbf800 */ 	ctc1	$t3,$31
/*  f14c8ac:	00000000 */ 	nop
/*  f14c8b0:	46003224 */ 	cvt.w.s	$f8,$f6
/*  f14c8b4:	444bf800 */ 	cfc1	$t3,$31
/*  f14c8b8:	00000000 */ 	nop
/*  f14c8bc:	316b0078 */ 	andi	$t3,$t3,0x78
/*  f14c8c0:	51600013 */ 	beqzl	$t3,.L0f14c910
/*  f14c8c4:	440b4000 */ 	mfc1	$t3,$f8
/*  f14c8c8:	44814000 */ 	mtc1	$at,$f8
/*  f14c8cc:	240b0001 */ 	addiu	$t3,$zero,0x1
/*  f14c8d0:	46083201 */ 	sub.s	$f8,$f6,$f8
/*  f14c8d4:	44cbf800 */ 	ctc1	$t3,$31
/*  f14c8d8:	00000000 */ 	nop
/*  f14c8dc:	46004224 */ 	cvt.w.s	$f8,$f8
/*  f14c8e0:	444bf800 */ 	cfc1	$t3,$31
/*  f14c8e4:	00000000 */ 	nop
/*  f14c8e8:	316b0078 */ 	andi	$t3,$t3,0x78
/*  f14c8ec:	15600005 */ 	bnez	$t3,.L0f14c904
/*  f14c8f0:	00000000 */ 	nop
/*  f14c8f4:	440b4000 */ 	mfc1	$t3,$f8
/*  f14c8f8:	3c018000 */ 	lui	$at,0x8000
/*  f14c8fc:	10000007 */ 	b	.L0f14c91c
/*  f14c900:	01615825 */ 	or	$t3,$t3,$at
.L0f14c904:
/*  f14c904:	10000005 */ 	b	.L0f14c91c
/*  f14c908:	240bffff */ 	addiu	$t3,$zero,-1
/*  f14c90c:	440b4000 */ 	mfc1	$t3,$f8
.L0f14c910:
/*  f14c910:	00000000 */ 	nop
/*  f14c914:	0560fffb */ 	bltz	$t3,.L0f14c904
/*  f14c918:	00000000 */ 	nop
.L0f14c91c:
/*  f14c91c:	44cef800 */ 	ctc1	$t6,$31
/*  f14c920:	c4cc0004 */ 	lwc1	$f12,0x4($a2)
/*  f14c924:	240c0001 */ 	addiu	$t4,$zero,0x1
/*  f14c928:	3c014f00 */ 	lui	$at,0x4f00
/*  f14c92c:	46006280 */ 	add.s	$f10,$f12,$f0
/*  f14c930:	46105482 */ 	mul.s	$f18,$f10,$f16
/*  f14c934:	444ff800 */ 	cfc1	$t7,$31
/*  f14c938:	44ccf800 */ 	ctc1	$t4,$31
/*  f14c93c:	00000000 */ 	nop
/*  f14c940:	46009124 */ 	cvt.w.s	$f4,$f18
/*  f14c944:	444cf800 */ 	cfc1	$t4,$31
/*  f14c948:	00000000 */ 	nop
/*  f14c94c:	318c0078 */ 	andi	$t4,$t4,0x78
/*  f14c950:	51800013 */ 	beqzl	$t4,.L0f14c9a0
/*  f14c954:	440c2000 */ 	mfc1	$t4,$f4
/*  f14c958:	44812000 */ 	mtc1	$at,$f4
/*  f14c95c:	240c0001 */ 	addiu	$t4,$zero,0x1
/*  f14c960:	46049101 */ 	sub.s	$f4,$f18,$f4
/*  f14c964:	44ccf800 */ 	ctc1	$t4,$31
/*  f14c968:	00000000 */ 	nop
/*  f14c96c:	46002124 */ 	cvt.w.s	$f4,$f4
/*  f14c970:	444cf800 */ 	cfc1	$t4,$31
/*  f14c974:	00000000 */ 	nop
/*  f14c978:	318c0078 */ 	andi	$t4,$t4,0x78
/*  f14c97c:	15800005 */ 	bnez	$t4,.L0f14c994
/*  f14c980:	00000000 */ 	nop
/*  f14c984:	440c2000 */ 	mfc1	$t4,$f4
/*  f14c988:	3c018000 */ 	lui	$at,0x8000
/*  f14c98c:	10000007 */ 	b	.L0f14c9ac
/*  f14c990:	01816025 */ 	or	$t4,$t4,$at
.L0f14c994:
/*  f14c994:	10000005 */ 	b	.L0f14c9ac
/*  f14c998:	240cffff */ 	addiu	$t4,$zero,-1
/*  f14c99c:	440c2000 */ 	mfc1	$t4,$f4
.L0f14c9a0:
/*  f14c9a0:	00000000 */ 	nop
/*  f14c9a4:	0580fffb */ 	bltz	$t4,.L0f14c994
/*  f14c9a8:	00000000 */ 	nop
.L0f14c9ac:
/*  f14c9ac:	90b80004 */ 	lbu	$t8,0x4($a1)
/*  f14c9b0:	44cff800 */ 	ctc1	$t7,$31
/*  f14c9b4:	c7a6004c */ 	lwc1	$f6,0x4c($sp)
/*  f14c9b8:	44984000 */ 	mtc1	$t8,$f8
/*  f14c9bc:	3c014f80 */ 	lui	$at,0x4f80
/*  f14c9c0:	07010004 */ 	bgez	$t8,.L0f14c9d4
/*  f14c9c4:	468042a0 */ 	cvt.s.w	$f10,$f8
/*  f14c9c8:	44819000 */ 	mtc1	$at,$f18
/*  f14c9cc:	00000000 */ 	nop
/*  f14c9d0:	46125280 */ 	add.s	$f10,$f10,$f18
.L0f14c9d4:
/*  f14c9d4:	460a3102 */ 	mul.s	$f4,$f6,$f10
/*  f14c9d8:	46001201 */ 	sub.s	$f8,$f2,$f0
/*  f14c9dc:	240d0001 */ 	addiu	$t5,$zero,0x1
/*  f14c9e0:	3c014f00 */ 	lui	$at,0x4f00
/*  f14c9e4:	46044480 */ 	add.s	$f18,$f8,$f4
/*  f14c9e8:	46109282 */ 	mul.s	$f10,$f18,$f16
/*  f14c9ec:	4459f800 */ 	cfc1	$t9,$31
/*  f14c9f0:	44cdf800 */ 	ctc1	$t5,$31
/*  f14c9f4:	00000000 */ 	nop
/*  f14c9f8:	46005224 */ 	cvt.w.s	$f8,$f10
/*  f14c9fc:	444df800 */ 	cfc1	$t5,$31
/*  f14ca00:	00000000 */ 	nop
/*  f14ca04:	31ad0078 */ 	andi	$t5,$t5,0x78
/*  f14ca08:	51a00013 */ 	beqzl	$t5,.L0f14ca58
/*  f14ca0c:	440d4000 */ 	mfc1	$t5,$f8
/*  f14ca10:	44814000 */ 	mtc1	$at,$f8
/*  f14ca14:	240d0001 */ 	addiu	$t5,$zero,0x1
/*  f14ca18:	46085201 */ 	sub.s	$f8,$f10,$f8
/*  f14ca1c:	44cdf800 */ 	ctc1	$t5,$31
/*  f14ca20:	00000000 */ 	nop
/*  f14ca24:	46004224 */ 	cvt.w.s	$f8,$f8
/*  f14ca28:	444df800 */ 	cfc1	$t5,$31
/*  f14ca2c:	00000000 */ 	nop
/*  f14ca30:	31ad0078 */ 	andi	$t5,$t5,0x78
/*  f14ca34:	15a00005 */ 	bnez	$t5,.L0f14ca4c
/*  f14ca38:	00000000 */ 	nop
/*  f14ca3c:	440d4000 */ 	mfc1	$t5,$f8
/*  f14ca40:	3c018000 */ 	lui	$at,0x8000
/*  f14ca44:	10000007 */ 	b	.L0f14ca64
/*  f14ca48:	01a16825 */ 	or	$t5,$t5,$at
.L0f14ca4c:
/*  f14ca4c:	10000005 */ 	b	.L0f14ca64
/*  f14ca50:	240dffff */ 	addiu	$t5,$zero,-1
/*  f14ca54:	440d4000 */ 	mfc1	$t5,$f8
.L0f14ca58:
/*  f14ca58:	00000000 */ 	nop
/*  f14ca5c:	05a0fffb */ 	bltz	$t5,.L0f14ca4c
/*  f14ca60:	00000000 */ 	nop
.L0f14ca64:
/*  f14ca64:	90ae0005 */ 	lbu	$t6,0x5($a1)
/*  f14ca68:	44d9f800 */ 	ctc1	$t9,$31
/*  f14ca6c:	3c014f80 */ 	lui	$at,0x4f80
/*  f14ca70:	448e2000 */ 	mtc1	$t6,$f4
/*  f14ca74:	05c10004 */ 	bgez	$t6,.L0f14ca88
/*  f14ca78:	468023a0 */ 	cvt.s.w	$f14,$f4
/*  f14ca7c:	44819000 */ 	mtc1	$at,$f18
/*  f14ca80:	00000000 */ 	nop
/*  f14ca84:	46127380 */ 	add.s	$f14,$f14,$f18
.L0f14ca88:
/*  f14ca88:	460e3202 */ 	mul.s	$f8,$f6,$f14
/*  f14ca8c:	46006281 */ 	sub.s	$f10,$f12,$f0
/*  f14ca90:	241f0001 */ 	addiu	$ra,$zero,0x1
/*  f14ca94:	3c014f00 */ 	lui	$at,0x4f00
/*  f14ca98:	46085100 */ 	add.s	$f4,$f10,$f8
/*  f14ca9c:	46102482 */ 	mul.s	$f18,$f4,$f16
/*  f14caa0:	444ff800 */ 	cfc1	$t7,$31
/*  f14caa4:	44dff800 */ 	ctc1	$ra,$31
/*  f14caa8:	00000000 */ 	nop
/*  f14caac:	460091a4 */ 	cvt.w.s	$f6,$f18
/*  f14cab0:	445ff800 */ 	cfc1	$ra,$31
/*  f14cab4:	00000000 */ 	nop
/*  f14cab8:	33ff0078 */ 	andi	$ra,$ra,0x78
/*  f14cabc:	53e00013 */ 	beqzl	$ra,.L0f14cb0c
/*  f14cac0:	441f3000 */ 	mfc1	$ra,$f6
/*  f14cac4:	44813000 */ 	mtc1	$at,$f6
/*  f14cac8:	241f0001 */ 	addiu	$ra,$zero,0x1
/*  f14cacc:	46069181 */ 	sub.s	$f6,$f18,$f6
/*  f14cad0:	44dff800 */ 	ctc1	$ra,$31
/*  f14cad4:	00000000 */ 	nop
/*  f14cad8:	460031a4 */ 	cvt.w.s	$f6,$f6
/*  f14cadc:	445ff800 */ 	cfc1	$ra,$31
/*  f14cae0:	00000000 */ 	nop
/*  f14cae4:	33ff0078 */ 	andi	$ra,$ra,0x78
/*  f14cae8:	17e00005 */ 	bnez	$ra,.L0f14cb00
/*  f14caec:	00000000 */ 	nop
/*  f14caf0:	441f3000 */ 	mfc1	$ra,$f6
/*  f14caf4:	3c018000 */ 	lui	$at,0x8000
/*  f14caf8:	10000007 */ 	b	.L0f14cb18
/*  f14cafc:	03e1f825 */ 	or	$ra,$ra,$at
.L0f14cb00:
/*  f14cb00:	10000005 */ 	b	.L0f14cb18
/*  f14cb04:	241fffff */ 	addiu	$ra,$zero,-1
/*  f14cb08:	441f3000 */ 	mfc1	$ra,$f6
.L0f14cb0c:
/*  f14cb0c:	00000000 */ 	nop
/*  f14cb10:	07e0fffb */ 	bltz	$ra,.L0f14cb00
/*  f14cb14:	00000000 */ 	nop
.L0f14cb18:
/*  f14cb18:	44cff800 */ 	ctc1	$t7,$31
/*  f14cb1c:	3c014200 */ 	lui	$at,0x4200
/*  f14cb20:	44814000 */ 	mtc1	$at,$f8
/*  f14cb24:	46007281 */ 	sub.s	$f10,$f14,$f0
/*  f14cb28:	8fae0040 */ 	lw	$t6,0x40($sp)
/*  f14cb2c:	3c18e700 */ 	lui	$t8,0xe700
/*  f14cb30:	27a40040 */ 	addiu	$a0,$sp,0x40
/*  f14cb34:	46085102 */ 	mul.s	$f4,$f10,$f8
/*  f14cb38:	25cf0008 */ 	addiu	$t7,$t6,0x8
/*  f14cb3c:	afaf0040 */ 	sw	$t7,0x40($sp)
/*  f14cb40:	3c0fba00 */ 	lui	$t7,0xba00
/*  f14cb44:	35ef0c02 */ 	ori	$t7,$t7,0xc02
/*  f14cb48:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f14cb4c:	00003825 */ 	or	$a3,$zero,$zero
/*  f14cb50:	4600248d */ 	trunc.w.s	$f18,$f4
/*  f14cb54:	44199000 */ 	mfc1	$t9,$f18
/*  f14cb58:	00000000 */ 	nop
/*  f14cb5c:	afb90028 */ 	sw	$t9,0x28($sp)
/*  f14cb60:	adc00004 */ 	sw	$zero,0x4($t6)
/*  f14cb64:	add80000 */ 	sw	$t8,0x0($t6)
/*  f14cb68:	8fb90040 */ 	lw	$t9,0x40($sp)
/*  f14cb6c:	272e0008 */ 	addiu	$t6,$t9,0x8
/*  f14cb70:	afae0040 */ 	sw	$t6,0x40($sp)
/*  f14cb74:	af200004 */ 	sw	$zero,0x4($t9)
/*  f14cb78:	af2f0000 */ 	sw	$t7,0x0($t9)
/*  f14cb7c:	8fb80040 */ 	lw	$t8,0x40($sp)
/*  f14cb80:	3c0eba00 */ 	lui	$t6,0xba00
/*  f14cb84:	35ce1301 */ 	ori	$t6,$t6,0x1301
/*  f14cb88:	27190008 */ 	addiu	$t9,$t8,0x8
/*  f14cb8c:	afb90040 */ 	sw	$t9,0x40($sp)
/*  f14cb90:	af000004 */ 	sw	$zero,0x4($t8)
/*  f14cb94:	af0e0000 */ 	sw	$t6,0x0($t8)
/*  f14cb98:	8faf0040 */ 	lw	$t7,0x40($sp)
/*  f14cb9c:	3c19b900 */ 	lui	$t9,0xb900
/*  f14cba0:	37390002 */ 	ori	$t9,$t9,0x2
/*  f14cba4:	25f80008 */ 	addiu	$t8,$t7,0x8
/*  f14cba8:	afb80040 */ 	sw	$t8,0x40($sp)
/*  f14cbac:	ade00004 */ 	sw	$zero,0x4($t7)
/*  f14cbb0:	adf90000 */ 	sw	$t9,0x0($t7)
/*  f14cbb4:	8fae0040 */ 	lw	$t6,0x40($sp)
/*  f14cbb8:	3c18ba00 */ 	lui	$t8,0xba00
/*  f14cbbc:	37181001 */ 	ori	$t8,$t8,0x1001
/*  f14cbc0:	25cf0008 */ 	addiu	$t7,$t6,0x8
/*  f14cbc4:	afaf0040 */ 	sw	$t7,0x40($sp)
/*  f14cbc8:	adc00004 */ 	sw	$zero,0x4($t6)
/*  f14cbcc:	add80000 */ 	sw	$t8,0x0($t6)
/*  f14cbd0:	8fb90040 */ 	lw	$t9,0x40($sp)
/*  f14cbd4:	3c0fba00 */ 	lui	$t7,0xba00
/*  f14cbd8:	35ef0903 */ 	ori	$t7,$t7,0x903
/*  f14cbdc:	272e0008 */ 	addiu	$t6,$t9,0x8
/*  f14cbe0:	afae0040 */ 	sw	$t6,0x40($sp)
/*  f14cbe4:	24180c00 */ 	addiu	$t8,$zero,0xc00
/*  f14cbe8:	af380004 */ 	sw	$t8,0x4($t9)
/*  f14cbec:	af2f0000 */ 	sw	$t7,0x0($t9)
/*  f14cbf0:	8fb90040 */ 	lw	$t9,0x40($sp)
/*  f14cbf4:	3c0ffc12 */ 	lui	$t7,0xfc12
/*  f14cbf8:	35ef7e24 */ 	ori	$t7,$t7,0x7e24
/*  f14cbfc:	272e0008 */ 	addiu	$t6,$t9,0x8
/*  f14cc00:	afae0040 */ 	sw	$t6,0x40($sp)
/*  f14cc04:	2418f9fc */ 	addiu	$t8,$zero,-1540
/*  f14cc08:	af2f0000 */ 	sw	$t7,0x0($t9)
/*  f14cc0c:	af380004 */ 	sw	$t8,0x4($t9)
/*  f14cc10:	3c0f800a */ 	lui	$t7,%hi(var800a45a8)
/*  f14cc14:	25ef45a8 */ 	addiu	$t7,$t7,%lo(var800a45a8)
/*  f14cc18:	afbf0030 */ 	sw	$ra,0x30($sp)
/*  f14cc1c:	24190002 */ 	addiu	$t9,$zero,0x2
/*  f14cc20:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f14cc24:	afae0014 */ 	sw	$t6,0x14($sp)
/*  f14cc28:	afb90010 */ 	sw	$t9,0x10($sp)
/*  f14cc2c:	afaf0018 */ 	sw	$t7,0x18($sp)
/*  f14cc30:	afad0034 */ 	sw	$t5,0x34($sp)
/*  f14cc34:	afac0038 */ 	sw	$t4,0x38($sp)
/*  f14cc38:	0fc2ce70 */ 	jal	func0f0b39c0
/*  f14cc3c:	afab003c */ 	sw	$t3,0x3c($sp)
/*  f14cc40:	8fb80040 */ 	lw	$t8,0x40($sp)
/*  f14cc44:	8fab003c */ 	lw	$t3,0x3c($sp)
/*  f14cc48:	8fac0038 */ 	lw	$t4,0x38($sp)
/*  f14cc4c:	27190008 */ 	addiu	$t9,$t8,0x8
/*  f14cc50:	8fad0034 */ 	lw	$t5,0x34($sp)
/*  f14cc54:	8fbf0030 */ 	lw	$ra,0x30($sp)
/*  f14cc58:	afb90040 */ 	sw	$t9,0x40($sp)
/*  f14cc5c:	3c0eba00 */ 	lui	$t6,0xba00
/*  f14cc60:	35ce1402 */ 	ori	$t6,$t6,0x1402
/*  f14cc64:	af0e0000 */ 	sw	$t6,0x0($t8)
/*  f14cc68:	af000004 */ 	sw	$zero,0x4($t8)
/*  f14cc6c:	8faf0040 */ 	lw	$t7,0x40($sp)
/*  f14cc70:	03001025 */ 	or	$v0,$t8,$zero
/*  f14cc74:	3c0efffc */ 	lui	$t6,0xfffc
/*  f14cc78:	25f80008 */ 	addiu	$t8,$t7,0x8
/*  f14cc7c:	afb80040 */ 	sw	$t8,0x40($sp)
/*  f14cc80:	3c19fcff */ 	lui	$t9,0xfcff
/*  f14cc84:	3c068008 */ 	lui	$a2,%hi(g_ScaleX)
/*  f14cc88:	3739ffff */ 	ori	$t9,$t9,0xffff
/*  f14cc8c:	35cef279 */ 	ori	$t6,$t6,0xf279
/*  f14cc90:	24c6fac0 */ 	addiu	$a2,$a2,%lo(g_ScaleX)
/*  f14cc94:	adee0004 */ 	sw	$t6,0x4($t7)
/*  f14cc98:	adf90000 */ 	sw	$t9,0x0($t7)
/*  f14cc9c:	8cd90000 */ 	lw	$t9,0x0($a2)
/*  f14cca0:	8faf0040 */ 	lw	$t7,0x40($sp)
/*  f14cca4:	3c01e400 */ 	lui	$at,0xe400
/*  f14cca8:	032d0019 */ 	multu	$t9,$t5
/*  f14ccac:	25f80008 */ 	addiu	$t8,$t7,0x8
/*  f14ccb0:	01e02025 */ 	or	$a0,$t7,$zero
/*  f14ccb4:	afb80040 */ 	sw	$t8,0x40($sp)
/*  f14ccb8:	00007012 */ 	mflo	$t6
/*  f14ccbc:	31cf0fff */ 	andi	$t7,$t6,0xfff
/*  f14ccc0:	000fc300 */ 	sll	$t8,$t7,0xc
/*  f14ccc4:	0301c825 */ 	or	$t9,$t8,$at
/*  f14ccc8:	33ee0fff */ 	andi	$t6,$ra,0xfff
/*  f14cccc:	032e7825 */ 	or	$t7,$t9,$t6
/*  f14ccd0:	ac8f0000 */ 	sw	$t7,0x0($a0)
/*  f14ccd4:	8cd80000 */ 	lw	$t8,0x0($a2)
/*  f14ccd8:	3c010010 */ 	lui	$at,0x10
/*  f14ccdc:	030b0019 */ 	multu	$t8,$t3
/*  f14cce0:	31980fff */ 	andi	$t8,$t4,0xfff
/*  f14cce4:	0000c812 */ 	mflo	$t9
/*  f14cce8:	332e0fff */ 	andi	$t6,$t9,0xfff
/*  f14ccec:	000e7b00 */ 	sll	$t7,$t6,0xc
/*  f14ccf0:	01f8c825 */ 	or	$t9,$t7,$t8
/*  f14ccf4:	ac990004 */ 	sw	$t9,0x4($a0)
/*  f14ccf8:	8fae0040 */ 	lw	$t6,0x40($sp)
/*  f14ccfc:	3c18b400 */ 	lui	$t8,0xb400
/*  f14cd00:	25cf0008 */ 	addiu	$t7,$t6,0x8
/*  f14cd04:	afaf0040 */ 	sw	$t7,0x40($sp)
/*  f14cd08:	add80000 */ 	sw	$t8,0x0($t6)
/*  f14cd0c:	8fb90028 */ 	lw	$t9,0x28($sp)
/*  f14cd10:	01c02825 */ 	or	$a1,$t6,$zero
/*  f14cd14:	332effff */ 	andi	$t6,$t9,0xffff
/*  f14cd18:	01c17825 */ 	or	$t7,$t6,$at
/*  f14cd1c:	acaf0004 */ 	sw	$t7,0x4($a1)
/*  f14cd20:	8fb80040 */ 	lw	$t8,0x40($sp)
/*  f14cd24:	3c0eb300 */ 	lui	$t6,0xb300
/*  f14cd28:	3c014480 */ 	lui	$at,0x4480
/*  f14cd2c:	27190008 */ 	addiu	$t9,$t8,0x8
/*  f14cd30:	afb90040 */ 	sw	$t9,0x40($sp)
/*  f14cd34:	af0e0000 */ 	sw	$t6,0x0($t8)
/*  f14cd38:	c7a6004c */ 	lwc1	$f6,0x4c($sp)
/*  f14cd3c:	44810000 */ 	mtc1	$at,$f0
/*  f14cd40:	03001825 */ 	or	$v1,$t8,$zero
/*  f14cd44:	8cd90000 */ 	lw	$t9,0x0($a2)
/*  f14cd48:	46060283 */ 	div.s	$f10,$f0,$f6
/*  f14cd4c:	c7a40050 */ 	lwc1	$f4,0x50($sp)
/*  f14cd50:	46040483 */ 	div.s	$f18,$f0,$f4
/*  f14cd54:	4600520d */ 	trunc.w.s	$f8,$f10
/*  f14cd58:	44184000 */ 	mfc1	$t8,$f8
/*  f14cd5c:	00000000 */ 	nop
/*  f14cd60:	0319001a */ 	div	$zero,$t8,$t9
/*  f14cd64:	4600918d */ 	trunc.w.s	$f6,$f18
/*  f14cd68:	00007812 */ 	mflo	$t7
/*  f14cd6c:	17200002 */ 	bnez	$t9,.L0f14cd78
/*  f14cd70:	00000000 */ 	nop
/*  f14cd74:	0007000d */ 	break	0x7
.L0f14cd78:
/*  f14cd78:	2401ffff */ 	addiu	$at,$zero,-1
/*  f14cd7c:	17210004 */ 	bne	$t9,$at,.L0f14cd90
/*  f14cd80:	3c018000 */ 	lui	$at,0x8000
/*  f14cd84:	17010002 */ 	bne	$t8,$at,.L0f14cd90
/*  f14cd88:	00000000 */ 	nop
/*  f14cd8c:	0006000d */ 	break	0x6
.L0f14cd90:
/*  f14cd90:	440e3000 */ 	mfc1	$t6,$f6
/*  f14cd94:	000fc400 */ 	sll	$t8,$t7,0x10
/*  f14cd98:	31cfffff */ 	andi	$t7,$t6,0xffff
/*  f14cd9c:	030fc825 */ 	or	$t9,$t8,$t7
/*  f14cda0:	ac790004 */ 	sw	$t9,0x4($v1)
/*  f14cda4:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*  f14cda8:	8fa20040 */ 	lw	$v0,0x40($sp)
/*  f14cdac:	27bd0040 */ 	addiu	$sp,$sp,0x40
/*  f14cdb0:	03e00008 */ 	jr	$ra
/*  f14cdb4:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel func0f14cdb8
/*  f14cdb8:	3c098008 */ 	lui	$t1,%hi(var8007f8dc)
/*  f14cdbc:	2529f8dc */ 	addiu	$t1,$t1,%lo(var8007f8dc)
/*  f14cdc0:	8d2e0000 */ 	lw	$t6,0x0($t1)
/*  f14cdc4:	00041180 */ 	sll	$v0,$a0,0x6
/*  f14cdc8:	44800000 */ 	mtc1	$zero,$f0
/*  f14cdcc:	00441021 */ 	addu	$v0,$v0,$a0
/*  f14cdd0:	00021080 */ 	sll	$v0,$v0,0x2
/*  f14cdd4:	01c27821 */ 	addu	$t7,$t6,$v0
/*  f14cdd8:	00003025 */ 	or	$a2,$zero,$zero
/*  f14cddc:	24071000 */ 	addiu	$a3,$zero,0x1000
/*  f14cde0:	24a81000 */ 	addiu	$t0,$a1,0x1000
/*  f14cde4:	240b3000 */ 	addiu	$t3,$zero,0x3000
/*  f14cde8:	240a0060 */ 	addiu	$t2,$zero,0x60
/*  f14cdec:	e5e0004c */ 	swc1	$f0,0x4c($t7)
.L0f14cdf0:
/*  f14cdf0:	24040020 */ 	addiu	$a0,$zero,0x20
/*  f14cdf4:	25050020 */ 	addiu	$a1,$t0,0x20
.L0f14cdf8:
/*  f14cdf8:	90b90000 */ 	lbu	$t9,0x0($a1)
/*  f14cdfc:	8d380000 */ 	lw	$t8,0x0($t1)
/*  f14ce00:	24c60001 */ 	addiu	$a2,$a2,0x1
/*  f14ce04:	44993000 */ 	mtc1	$t9,$f6
/*  f14ce08:	03021821 */ 	addu	$v1,$t8,$v0
/*  f14ce0c:	c464004c */ 	lwc1	$f4,0x4c($v1)
/*  f14ce10:	07210005 */ 	bgez	$t9,.L0f14ce28
/*  f14ce14:	46803220 */ 	cvt.s.w	$f8,$f6
/*  f14ce18:	3c014f80 */ 	lui	$at,0x4f80
/*  f14ce1c:	44815000 */ 	mtc1	$at,$f10
/*  f14ce20:	00000000 */ 	nop
/*  f14ce24:	460a4200 */ 	add.s	$f8,$f8,$f10
.L0f14ce28:
/*  f14ce28:	46082400 */ 	add.s	$f16,$f4,$f8
/*  f14ce2c:	24840001 */ 	addiu	$a0,$a0,0x1
/*  f14ce30:	24a50001 */ 	addiu	$a1,$a1,0x1
/*  f14ce34:	148afff0 */ 	bne	$a0,$t2,.L0f14cdf8
/*  f14ce38:	e470004c */ 	swc1	$f16,0x4c($v1)
/*  f14ce3c:	24e70080 */ 	addiu	$a3,$a3,0x80
/*  f14ce40:	14ebffeb */ 	bne	$a3,$t3,.L0f14cdf0
/*  f14ce44:	25080080 */ 	addiu	$t0,$t0,0x80
/*  f14ce48:	58c0000a */ 	blezl	$a2,.L0f14ce74
/*  f14ce4c:	8d2d0000 */ 	lw	$t5,0x0($t1)
/*  f14ce50:	44863000 */ 	mtc1	$a2,$f6
/*  f14ce54:	8d2c0000 */ 	lw	$t4,0x0($t1)
/*  f14ce58:	468032a0 */ 	cvt.s.w	$f10,$f6
/*  f14ce5c:	01821821 */ 	addu	$v1,$t4,$v0
/*  f14ce60:	c472004c */ 	lwc1	$f18,0x4c($v1)
/*  f14ce64:	460a9103 */ 	div.s	$f4,$f18,$f10
/*  f14ce68:	03e00008 */ 	jr	$ra
/*  f14ce6c:	e464004c */ 	swc1	$f4,0x4c($v1)
/*  f14ce70:	8d2d0000 */ 	lw	$t5,0x0($t1)
.L0f14ce74:
/*  f14ce74:	01a27021 */ 	addu	$t6,$t5,$v0
/*  f14ce78:	e5c0004c */ 	swc1	$f0,0x4c($t6)
/*  f14ce7c:	03e00008 */ 	jr	$ra
/*  f14ce80:	00000000 */ 	nop
/*  f14ce84:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f14ce88:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f14ce8c:	0fc52969 */ 	jal	func0f14a5a4
/*  f14ce90:	00000000 */ 	nop
/*  f14ce94:	00022600 */ 	sll	$a0,$v0,0x18
/*  f14ce98:	00047603 */ 	sra	$t6,$a0,0x18
/*  f14ce9c:	0fc474fe */ 	jal	pak0f11d3f8
/*  f14cea0:	01c02025 */ 	or	$a0,$t6,$zero
/*  f14cea4:	5040002e */ 	beqzl	$v0,.L0f14cf60
/*  f14cea8:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f14ceac:	0fc52969 */ 	jal	func0f14a5a4
/*  f14ceb0:	00000000 */ 	nop
/*  f14ceb4:	00022600 */ 	sll	$a0,$v0,0x18
/*  f14ceb8:	00047e03 */ 	sra	$t7,$a0,0x18
/*  f14cebc:	0fc45c84 */ 	jal	pakGetUnk008
/*  f14cec0:	01e02025 */ 	or	$a0,$t7,$zero
/*  f14cec4:	2401000c */ 	addiu	$at,$zero,0xc
/*  f14cec8:	1041001e */ 	beq	$v0,$at,.L0f14cf44
/*  f14cecc:	00000000 */ 	nop
/*  f14ced0:	0fc52969 */ 	jal	func0f14a5a4
/*  f14ced4:	00000000 */ 	nop
/*  f14ced8:	3c198008 */ 	lui	$t9,%hi(var8007f8dc)
/*  f14cedc:	8f39f8dc */ 	lw	$t9,%lo(var8007f8dc)($t9)
/*  f14cee0:	00024180 */ 	sll	$t0,$v0,0x6
/*  f14cee4:	01024021 */ 	addu	$t0,$t0,$v0
/*  f14cee8:	00084080 */ 	sll	$t0,$t0,0x2
/*  f14ceec:	24180001 */ 	addiu	$t8,$zero,0x1
/*  f14cef0:	03284821 */ 	addu	$t1,$t9,$t0
/*  f14cef4:	0fc52969 */ 	jal	func0f14a5a4
/*  f14cef8:	ad3800f8 */ 	sw	$t8,0xf8($t1)
/*  f14cefc:	3c0a8008 */ 	lui	$t2,%hi(var8007f8dc)
/*  f14cf00:	8d4af8dc */ 	lw	$t2,%lo(var8007f8dc)($t2)
/*  f14cf04:	00025980 */ 	sll	$t3,$v0,0x6
/*  f14cf08:	01625821 */ 	addu	$t3,$t3,$v0
/*  f14cf0c:	000b5880 */ 	sll	$t3,$t3,0x2
/*  f14cf10:	014b1821 */ 	addu	$v1,$t2,$t3
/*  f14cf14:	906c00d4 */ 	lbu	$t4,0xd4($v1)
/*  f14cf18:	318dff7f */ 	andi	$t5,$t4,0xff7f
/*  f14cf1c:	0fc52a57 */ 	jal	func0f14a95c
/*  f14cf20:	a06d00d4 */ 	sb	$t5,0xd4($v1)
/*  f14cf24:	0fc52a92 */ 	jal	func0f14aa48
/*  f14cf28:	00000000 */ 	nop
/*  f14cf2c:	0fc52ab1 */ 	jal	func0f14aac4
/*  f14cf30:	00000000 */ 	nop
/*  f14cf34:	0fc52acf */ 	jal	func0f14ab3c
/*  f14cf38:	00000000 */ 	nop
/*  f14cf3c:	10000008 */ 	b	.L0f14cf60
/*  f14cf40:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f14cf44:
/*  f14cf44:	0fc52969 */ 	jal	func0f14a5a4
/*  f14cf48:	00000000 */ 	nop
/*  f14cf4c:	00022600 */ 	sll	$a0,$v0,0x18
/*  f14cf50:	00047603 */ 	sra	$t6,$a0,0x18
/*  f14cf54:	0fc478ef */ 	jal	pak0f11e3bc
/*  f14cf58:	01c02025 */ 	or	$a0,$t6,$zero
/*  f14cf5c:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f14cf60:
/*  f14cf60:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f14cf64:	03e00008 */ 	jr	$ra
/*  f14cf68:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel func0f14cf6c
.late_rodata
glabel var7f1b733c
.word func0f14cf6c+0x90 # f14cffc
glabel var7f1b7340
.word func0f14cf6c+0x90 # f14cffc
glabel var7f1b7344
.word func0f14cf6c+0x90 # f14cffc
glabel var7f1b7348
.word func0f14cf6c+0x90 # f14cffc
glabel var7f1b734c
.word func0f14cf6c+0x90 # f14cffc
.text
/*  f14cf6c:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f14cf70:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f14cf74:	3c018007 */ 	lui	$at,%hi(g_MpPlayerNum)
/*  f14cf78:	ac201448 */ 	sw	$zero,%lo(g_MpPlayerNum)($at)
/*  f14cf7c:	2404ffff */ 	addiu	$a0,$zero,-1
/*  f14cf80:	0fc3c328 */ 	jal	func0f0f0ca0
/*  f14cf84:	00002825 */ 	or	$a1,$zero,$zero
/*  f14cf88:	0fc52969 */ 	jal	func0f14a5a4
/*  f14cf8c:	00000000 */ 	nop
/*  f14cf90:	3c0e8008 */ 	lui	$t6,%hi(var8007f8dc)
/*  f14cf94:	8dcef8dc */ 	lw	$t6,%lo(var8007f8dc)($t6)
/*  f14cf98:	00027980 */ 	sll	$t7,$v0,0x6
/*  f14cf9c:	01e27821 */ 	addu	$t7,$t7,$v0
/*  f14cfa0:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f14cfa4:	01cfc021 */ 	addu	$t8,$t6,$t7
/*  f14cfa8:	8f1900f8 */ 	lw	$t9,0xf8($t8)
/*  f14cfac:	5320002a */ 	beqzl	$t9,.L0f14d058
/*  f14cfb0:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f14cfb4:	0fc52969 */ 	jal	func0f14a5a4
/*  f14cfb8:	00000000 */ 	nop
/*  f14cfbc:	3c088008 */ 	lui	$t0,%hi(var8007f8dc)
/*  f14cfc0:	8d08f8dc */ 	lw	$t0,%lo(var8007f8dc)($t0)
/*  f14cfc4:	00024980 */ 	sll	$t1,$v0,0x6
/*  f14cfc8:	01224821 */ 	addu	$t1,$t1,$v0
/*  f14cfcc:	00094880 */ 	sll	$t1,$t1,0x2
/*  f14cfd0:	01095021 */ 	addu	$t2,$t0,$t1
/*  f14cfd4:	8d4b00f8 */ 	lw	$t3,0xf8($t2)
/*  f14cfd8:	256cfffe */ 	addiu	$t4,$t3,-2
/*  f14cfdc:	2d810005 */ 	sltiu	$at,$t4,0x5
/*  f14cfe0:	10200013 */ 	beqz	$at,.L0f14d030
/*  f14cfe4:	000c6080 */ 	sll	$t4,$t4,0x2
/*  f14cfe8:	3c017f1b */ 	lui	$at,%hi(var7f1b733c)
/*  f14cfec:	002c0821 */ 	addu	$at,$at,$t4
/*  f14cff0:	8c2c733c */ 	lw	$t4,%lo(var7f1b733c)($at)
/*  f14cff4:	01800008 */ 	jr	$t4
/*  f14cff8:	00000000 */ 	nop
/*  f14cffc:	0fc52969 */ 	jal	func0f14a5a4
/*  f14d000:	00000000 */ 	nop
/*  f14d004:	00022600 */ 	sll	$a0,$v0,0x18
/*  f14d008:	00046e03 */ 	sra	$t5,$a0,0x18
/*  f14d00c:	01a02025 */ 	or	$a0,$t5,$zero
/*  f14d010:	24050003 */ 	addiu	$a1,$zero,0x3
/*  f14d014:	0fc45c6d */ 	jal	pak0f1171b4
/*  f14d018:	00003025 */ 	or	$a2,$zero,$zero
/*  f14d01c:	3c018007 */ 	lui	$at,%hi(g_MpPlayerNum)
/*  f14d020:	ac201448 */ 	sw	$zero,%lo(g_MpPlayerNum)($at)
/*  f14d024:	2404ffff */ 	addiu	$a0,$zero,-1
/*  f14d028:	0fc3c328 */ 	jal	func0f0f0ca0
/*  f14d02c:	00002825 */ 	or	$a1,$zero,$zero
.L0f14d030:
/*  f14d030:	0fc52969 */ 	jal	func0f14a5a4
/*  f14d034:	00000000 */ 	nop
/*  f14d038:	3c0e8008 */ 	lui	$t6,%hi(var8007f8dc)
/*  f14d03c:	8dcef8dc */ 	lw	$t6,%lo(var8007f8dc)($t6)
/*  f14d040:	00027980 */ 	sll	$t7,$v0,0x6
/*  f14d044:	01e27821 */ 	addu	$t7,$t7,$v0
/*  f14d048:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f14d04c:	01cfc021 */ 	addu	$t8,$t6,$t7
/*  f14d050:	af0000f8 */ 	sw	$zero,0xf8($t8)
/*  f14d054:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f14d058:
/*  f14d058:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f14d05c:	03e00008 */ 	jr	$ra
/*  f14d060:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel func0f14d064
/*  f14d064:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*  f14d068:	3c188008 */ 	lui	$t8,%hi(var8007f8dc)
/*  f14d06c:	8f18f8dc */ 	lw	$t8,%lo(var8007f8dc)($t8)
/*  f14d070:	00047980 */ 	sll	$t7,$a0,0x6
/*  f14d074:	01e47821 */ 	addu	$t7,$t7,$a0
/*  f14d078:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f14d07c:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f14d080:	afbf001c */ 	sw	$ra,0x1c($sp)
/*  f14d084:	afa40020 */ 	sw	$a0,0x20($sp)
/*  f14d088:	afa50024 */ 	sw	$a1,0x24($sp)
/*  f14d08c:	01f88021 */ 	addu	$s0,$t7,$t8
/*  f14d090:	8e0300f8 */ 	lw	$v1,0xf8($s0)
/*  f14d094:	24010001 */ 	addiu	$at,$zero,0x1
/*  f14d098:	24194000 */ 	addiu	$t9,$zero,0x4000
/*  f14d09c:	14610018 */ 	bne	$v1,$at,.L0f14d100
/*  f14d0a0:	24082000 */ 	addiu	$t0,$zero,0x2000
/*  f14d0a4:	24090006 */ 	addiu	$t1,$zero,0x6
/*  f14d0a8:	ae19005c */ 	sw	$t9,0x5c($s0)
/*  f14d0ac:	ae080064 */ 	sw	$t0,0x64($s0)
/*  f14d0b0:	ae090060 */ 	sw	$t1,0x60($s0)
/*  f14d0b4:	8faa0020 */ 	lw	$t2,0x20($sp)
/*  f14d0b8:	3c018007 */ 	lui	$at,%hi(g_MpPlayerNum)
/*  f14d0bc:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f14d0c0:	00002825 */ 	or	$a1,$zero,$zero
/*  f14d0c4:	0fc3c328 */ 	jal	func0f0f0ca0
/*  f14d0c8:	ac2a1448 */ 	sw	$t2,%lo(g_MpPlayerNum)($at)
/*  f14d0cc:	0fc5285b */ 	jal	func0f14a16c
/*  f14d0d0:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f14d0d4:	0fc52969 */ 	jal	func0f14a5a4
/*  f14d0d8:	00000000 */ 	nop
/*  f14d0dc:	00022600 */ 	sll	$a0,$v0,0x18
/*  f14d0e0:	00045e03 */ 	sra	$t3,$a0,0x18
/*  f14d0e4:	01602025 */ 	or	$a0,$t3,$zero
/*  f14d0e8:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f14d0ec:	0fc45c6d */ 	jal	pak0f1171b4
/*  f14d0f0:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f14d0f4:	240c0003 */ 	addiu	$t4,$zero,0x3
/*  f14d0f8:	1000006e */ 	b	.L0f14d2b4
/*  f14d0fc:	ae0c00f8 */ 	sw	$t4,0xf8($s0)
.L0f14d100:
/*  f14d100:	24010003 */ 	addiu	$at,$zero,0x3
/*  f14d104:	14610027 */ 	bne	$v1,$at,.L0f14d1a4
/*  f14d108:	8fa40020 */ 	lw	$a0,0x20($sp)
/*  f14d10c:	0fc5336e */ 	jal	func0f14cdb8
/*  f14d110:	8fa50024 */ 	lw	$a1,0x24($sp)
/*  f14d114:	3c014302 */ 	lui	$at,0x4302
/*  f14d118:	44816000 */ 	mtc1	$at,$f12
/*  f14d11c:	c600004c */ 	lwc1	$f0,0x4c($s0)
/*  f14d120:	3c014120 */ 	lui	$at,0x4120
/*  f14d124:	44812000 */ 	mtc1	$at,$f4
/*  f14d128:	4600603c */ 	c.lt.s	$f12,$f0
/*  f14d12c:	24030002 */ 	addiu	$v1,$zero,0x2
/*  f14d130:	45020004 */ 	bc1fl	.L0f14d144
/*  f14d134:	460c0081 */ 	sub.s	$f2,$f0,$f12
/*  f14d138:	10000003 */ 	b	.L0f14d148
/*  f14d13c:	460c0081 */ 	sub.s	$f2,$f0,$f12
/*  f14d140:	460c0081 */ 	sub.s	$f2,$f0,$f12
.L0f14d144:
/*  f14d144:	46001087 */ 	neg.s	$f2,$f2
.L0f14d148:
/*  f14d148:	4604103c */ 	c.lt.s	$f2,$f4
/*  f14d14c:	00000000 */ 	nop
/*  f14d150:	45010005 */ 	bc1t	.L0f14d168
/*  f14d154:	00000000 */ 	nop
/*  f14d158:	8e020064 */ 	lw	$v0,0x64($s0)
/*  f14d15c:	24010040 */ 	addiu	$at,$zero,0x40
/*  f14d160:	14410003 */ 	bne	$v0,$at,.L0f14d170
/*  f14d164:	00024043 */ 	sra	$t0,$v0,0x1
.L0f14d168:
/*  f14d168:	1000000e */ 	b	.L0f14d1a4
/*  f14d16c:	ae0300f8 */ 	sw	$v1,0xf8($s0)
.L0f14d170:
/*  f14d170:	460c003c */ 	c.lt.s	$f0,$f12
/*  f14d174:	00000000 */ 	nop
/*  f14d178:	45020006 */ 	bc1fl	.L0f14d194
/*  f14d17c:	8e18005c */ 	lw	$t8,0x5c($s0)
/*  f14d180:	8e0e005c */ 	lw	$t6,0x5c($s0)
/*  f14d184:	01c27821 */ 	addu	$t7,$t6,$v0
/*  f14d188:	10000004 */ 	b	.L0f14d19c
/*  f14d18c:	ae0f005c */ 	sw	$t7,0x5c($s0)
/*  f14d190:	8e18005c */ 	lw	$t8,0x5c($s0)
.L0f14d194:
/*  f14d194:	0302c823 */ 	subu	$t9,$t8,$v0
/*  f14d198:	ae19005c */ 	sw	$t9,0x5c($s0)
.L0f14d19c:
/*  f14d19c:	ae080064 */ 	sw	$t0,0x64($s0)
/*  f14d1a0:	8e0300f8 */ 	lw	$v1,0xf8($s0)
.L0f14d1a4:
/*  f14d1a4:	24010002 */ 	addiu	$at,$zero,0x2
/*  f14d1a8:	14610013 */ 	bne	$v1,$at,.L0f14d1f8
/*  f14d1ac:	8fa40020 */ 	lw	$a0,0x20($sp)
/*  f14d1b0:	0fc5336e */ 	jal	func0f14cdb8
/*  f14d1b4:	8fa50024 */ 	lw	$a1,0x24($sp)
/*  f14d1b8:	8e020060 */ 	lw	$v0,0x60($s0)
/*  f14d1bc:	2401000c */ 	addiu	$at,$zero,0xc
/*  f14d1c0:	24030006 */ 	addiu	$v1,$zero,0x6
/*  f14d1c4:	10410008 */ 	beq	$v0,$at,.L0f14d1e8
/*  f14d1c8:	3c0142f0 */ 	lui	$at,0x42f0
/*  f14d1cc:	44813000 */ 	mtc1	$at,$f6
/*  f14d1d0:	c608004c */ 	lwc1	$f8,0x4c($s0)
/*  f14d1d4:	244a0002 */ 	addiu	$t2,$v0,0x2
/*  f14d1d8:	4608303c */ 	c.lt.s	$f6,$f8
/*  f14d1dc:	00000000 */ 	nop
/*  f14d1e0:	45020004 */ 	bc1fl	.L0f14d1f4
/*  f14d1e4:	ae0a0060 */ 	sw	$t2,0x60($s0)
.L0f14d1e8:
/*  f14d1e8:	10000003 */ 	b	.L0f14d1f8
/*  f14d1ec:	ae0300f8 */ 	sw	$v1,0xf8($s0)
/*  f14d1f0:	ae0a0060 */ 	sw	$t2,0x60($s0)
.L0f14d1f4:
/*  f14d1f4:	8e0300f8 */ 	lw	$v1,0xf8($s0)
.L0f14d1f8:
/*  f14d1f8:	24010006 */ 	addiu	$at,$zero,0x6
/*  f14d1fc:	14610029 */ 	bne	$v1,$at,.L0f14d2a4
/*  f14d200:	00000000 */ 	nop
/*  f14d204:	0fc52969 */ 	jal	func0f14a5a4
/*  f14d208:	00000000 */ 	nop
/*  f14d20c:	00022600 */ 	sll	$a0,$v0,0x18
/*  f14d210:	00045e03 */ 	sra	$t3,$a0,0x18
/*  f14d214:	01602025 */ 	or	$a0,$t3,$zero
/*  f14d218:	24050003 */ 	addiu	$a1,$zero,0x3
/*  f14d21c:	0fc45c6d */ 	jal	pak0f1171b4
/*  f14d220:	00003025 */ 	or	$a2,$zero,$zero
/*  f14d224:	8e0d00fc */ 	lw	$t5,0xfc($s0)
/*  f14d228:	240c0006 */ 	addiu	$t4,$zero,0x6
/*  f14d22c:	ae0c00f8 */ 	sw	$t4,0xf8($s0)
/*  f14d230:	ae0d0100 */ 	sw	$t5,0x100($s0)
/*  f14d234:	8fae0020 */ 	lw	$t6,0x20($sp)
/*  f14d238:	3c018007 */ 	lui	$at,%hi(g_MpPlayerNum)
/*  f14d23c:	2404ffff */ 	addiu	$a0,$zero,-1
/*  f14d240:	00002825 */ 	or	$a1,$zero,$zero
/*  f14d244:	0fc3c328 */ 	jal	func0f0f0ca0
/*  f14d248:	ac2e1448 */ 	sw	$t6,%lo(g_MpPlayerNum)($at)
/*  f14d24c:	0fc52969 */ 	jal	func0f14a5a4
/*  f14d250:	00000000 */ 	nop
/*  f14d254:	00022600 */ 	sll	$a0,$v0,0x18
/*  f14d258:	00047e03 */ 	sra	$t7,$a0,0x18
/*  f14d25c:	01e02025 */ 	or	$a0,$t7,$zero
/*  f14d260:	24050003 */ 	addiu	$a1,$zero,0x3
/*  f14d264:	0fc45c6d */ 	jal	pak0f1171b4
/*  f14d268:	00003025 */ 	or	$a2,$zero,$zero
/*  f14d26c:	3c19800a */ 	lui	$t9,%hi(var800a45a0)
/*  f14d270:	8f3945a0 */ 	lw	$t9,%lo(var800a45a0)($t9)
/*  f14d274:	3c188008 */ 	lui	$t8,%hi(var8007f8dc)
/*  f14d278:	8f18f8dc */ 	lw	$t8,%lo(var8007f8dc)($t8)
/*  f14d27c:	8f280000 */ 	lw	$t0,0x0($t9)
/*  f14d280:	00001825 */ 	or	$v1,$zero,$zero
/*  f14d284:	00084980 */ 	sll	$t1,$t0,0x6
/*  f14d288:	01284821 */ 	addu	$t1,$t1,$t0
/*  f14d28c:	00094880 */ 	sll	$t1,$t1,0x2
/*  f14d290:	03091021 */ 	addu	$v0,$t8,$t1
/*  f14d294:	904b00d4 */ 	lbu	$t3,0xd4($v0)
/*  f14d298:	356c0008 */ 	ori	$t4,$t3,0x8
/*  f14d29c:	a04c00d4 */ 	sb	$t4,0xd4($v0)
/*  f14d2a0:	ae0000f8 */ 	sw	$zero,0xf8($s0)
.L0f14d2a4:
/*  f14d2a4:	14600003 */ 	bnez	$v1,.L0f14d2b4
/*  f14d2a8:	8fa40020 */ 	lw	$a0,0x20($sp)
/*  f14d2ac:	0fc5336e */ 	jal	func0f14cdb8
/*  f14d2b0:	8fa50024 */ 	lw	$a1,0x24($sp)
.L0f14d2b4:
/*  f14d2b4:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f14d2b8:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f14d2bc:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*  f14d2c0:	03e00008 */ 	jr	$ra
/*  f14d2c4:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel func0f14d2c8
/*  f14d2c8:	27bdff70 */ 	addiu	$sp,$sp,-144
/*  f14d2cc:	3c02800a */ 	lui	$v0,%hi(var800a45a0)
/*  f14d2d0:	8c4245a0 */ 	lw	$v0,%lo(var800a45a0)($v0)
/*  f14d2d4:	afb20028 */ 	sw	$s2,0x28($sp)
/*  f14d2d8:	afbf002c */ 	sw	$ra,0x2c($sp)
/*  f14d2dc:	afb10024 */ 	sw	$s1,0x24($sp)
/*  f14d2e0:	afb00020 */ 	sw	$s0,0x20($sp)
/*  f14d2e4:	afa50094 */ 	sw	$a1,0x94($sp)
/*  f14d2e8:	3c0f8008 */ 	lui	$t7,%hi(var8007f9d8)
/*  f14d2ec:	25eff9d8 */ 	addiu	$t7,$t7,%lo(var8007f9d8)
/*  f14d2f0:	00809025 */ 	or	$s2,$a0,$zero
/*  f14d2f4:	24080080 */ 	addiu	$t0,$zero,0x80
/*  f14d2f8:	25ea0024 */ 	addiu	$t2,$t7,0x24
/*  f14d2fc:	27ae0050 */ 	addiu	$t6,$sp,0x50
/*  f14d300:	8c510474 */ 	lw	$s1,0x474($v0)
/*  f14d304:	8c500478 */ 	lw	$s0,0x478($v0)
.L0f14d308:
/*  f14d308:	8de10000 */ 	lw	$at,0x0($t7)
/*  f14d30c:	25ef000c */ 	addiu	$t7,$t7,0xc
/*  f14d310:	25ce000c */ 	addiu	$t6,$t6,0xc
/*  f14d314:	adc1fff4 */ 	sw	$at,-0xc($t6)
/*  f14d318:	8de1fff8 */ 	lw	$at,-0x8($t7)
/*  f14d31c:	adc1fff8 */ 	sw	$at,-0x8($t6)
/*  f14d320:	8de1fffc */ 	lw	$at,-0x4($t7)
/*  f14d324:	15eafff8 */ 	bne	$t7,$t2,.L0f14d308
/*  f14d328:	adc1fffc */ 	sw	$at,-0x4($t6)
/*  f14d32c:	00003825 */ 	or	$a3,$zero,$zero
/*  f14d330:	24050080 */ 	addiu	$a1,$zero,0x80
/*  f14d334:	000731c0 */ 	sll	$a2,$a3,0x7
.L0f14d338:
/*  f14d338:	00065880 */ 	sll	$t3,$a2,0x2
/*  f14d33c:	022b1821 */ 	addu	$v1,$s1,$t3
/*  f14d340:	02462021 */ 	addu	$a0,$s2,$a2
/*  f14d344:	00001025 */ 	or	$v0,$zero,$zero
.L0f14d348:
/*  f14d348:	908c0000 */ 	lbu	$t4,0x0($a0)
/*  f14d34c:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f14d350:	24840001 */ 	addiu	$a0,$a0,0x1
/*  f14d354:	448c2000 */ 	mtc1	$t4,$f4
/*  f14d358:	3c014f80 */ 	lui	$at,0x4f80
/*  f14d35c:	05810004 */ 	bgez	$t4,.L0f14d370
/*  f14d360:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f14d364:	44814000 */ 	mtc1	$at,$f8
/*  f14d368:	00000000 */ 	nop
/*  f14d36c:	46083180 */ 	add.s	$f6,$f6,$f8
.L0f14d370:
/*  f14d370:	24630004 */ 	addiu	$v1,$v1,0x4
/*  f14d374:	1445fff4 */ 	bne	$v0,$a1,.L0f14d348
/*  f14d378:	e466fffc */ 	swc1	$f6,-0x4($v1)
/*  f14d37c:	24e70001 */ 	addiu	$a3,$a3,0x1
/*  f14d380:	00e8082a */ 	slt	$at,$a3,$t0
/*  f14d384:	5420ffec */ 	bnezl	$at,.L0f14d338
/*  f14d388:	000731c0 */ 	sll	$a2,$a3,0x7
/*  f14d38c:	27a40050 */ 	addiu	$a0,$sp,0x50
/*  f14d390:	0fc53613 */ 	jal	func0f14d84c
/*  f14d394:	24050003 */ 	addiu	$a1,$zero,0x3
/*  f14d398:	240d0003 */ 	addiu	$t5,$zero,0x3
/*  f14d39c:	afad0010 */ 	sw	$t5,0x10($sp)
/*  f14d3a0:	02202025 */ 	or	$a0,$s1,$zero
/*  f14d3a4:	02002825 */ 	or	$a1,$s0,$zero
/*  f14d3a8:	24060080 */ 	addiu	$a2,$zero,0x80
/*  f14d3ac:	0fc53636 */ 	jal	func0f14d8d8
/*  f14d3b0:	27a70050 */ 	addiu	$a3,$sp,0x50
/*  f14d3b4:	3c013e80 */ 	lui	$at,0x3e80
/*  f14d3b8:	44817000 */ 	mtc1	$at,$f14
/*  f14d3bc:	3c01437f */ 	lui	$at,0x437f
/*  f14d3c0:	44816000 */ 	mtc1	$at,$f12
/*  f14d3c4:	44801000 */ 	mtc1	$zero,$f2
/*  f14d3c8:	8fa80094 */ 	lw	$t0,0x94($sp)
/*  f14d3cc:	00003825 */ 	or	$a3,$zero,$zero
/*  f14d3d0:	24093f00 */ 	addiu	$t1,$zero,0x3f00
/*  f14d3d4:	2406007e */ 	addiu	$a2,$zero,0x7e
.L0f14d3d8:
/*  f14d3d8:	00001825 */ 	or	$v1,$zero,$zero
/*  f14d3dc:	01002025 */ 	or	$a0,$t0,$zero
/*  f14d3e0:	00e02825 */ 	or	$a1,$a3,$zero
.L0f14d3e4:
/*  f14d3e4:	0005c880 */ 	sll	$t9,$a1,0x2
/*  f14d3e8:	03301021 */ 	addu	$v0,$t9,$s0
/*  f14d3ec:	c44a0000 */ 	lwc1	$f10,0x0($v0)
/*  f14d3f0:	c4500004 */ 	lwc1	$f16,0x4($v0)
/*  f14d3f4:	c4440200 */ 	lwc1	$f4,0x200($v0)
/*  f14d3f8:	c4460204 */ 	lwc1	$f6,0x204($v0)
/*  f14d3fc:	46105480 */ 	add.s	$f18,$f10,$f16
/*  f14d400:	24a50002 */ 	addiu	$a1,$a1,0x2
/*  f14d404:	24630002 */ 	addiu	$v1,$v1,0x2
/*  f14d408:	240a0001 */ 	addiu	$t2,$zero,0x1
/*  f14d40c:	46049200 */ 	add.s	$f8,$f18,$f4
/*  f14d410:	3c014f00 */ 	lui	$at,0x4f00
/*  f14d414:	46083280 */ 	add.s	$f10,$f6,$f8
/*  f14d418:	460e5002 */ 	mul.s	$f0,$f10,$f14
/*  f14d41c:	4602003c */ 	c.lt.s	$f0,$f2
/*  f14d420:	00000000 */ 	nop
/*  f14d424:	45020003 */ 	bc1fl	.L0f14d434
/*  f14d428:	4600603c */ 	c.lt.s	$f12,$f0
/*  f14d42c:	46001006 */ 	mov.s	$f0,$f2
/*  f14d430:	4600603c */ 	c.lt.s	$f12,$f0
.L0f14d434:
/*  f14d434:	00000000 */ 	nop
/*  f14d438:	45020003 */ 	bc1fl	.L0f14d448
/*  f14d43c:	4458f800 */ 	cfc1	$t8,$31
/*  f14d440:	46006006 */ 	mov.s	$f0,$f12
/*  f14d444:	4458f800 */ 	cfc1	$t8,$31
.L0f14d448:
/*  f14d448:	44caf800 */ 	ctc1	$t2,$31
/*  f14d44c:	00000000 */ 	nop
/*  f14d450:	46000424 */ 	cvt.w.s	$f16,$f0
/*  f14d454:	444af800 */ 	cfc1	$t2,$31
/*  f14d458:	00000000 */ 	nop
/*  f14d45c:	314a0078 */ 	andi	$t2,$t2,0x78
/*  f14d460:	51400013 */ 	beqzl	$t2,.L0f14d4b0
/*  f14d464:	440a8000 */ 	mfc1	$t2,$f16
/*  f14d468:	44818000 */ 	mtc1	$at,$f16
/*  f14d46c:	240a0001 */ 	addiu	$t2,$zero,0x1
/*  f14d470:	46100401 */ 	sub.s	$f16,$f0,$f16
/*  f14d474:	44caf800 */ 	ctc1	$t2,$31
/*  f14d478:	00000000 */ 	nop
/*  f14d47c:	46008424 */ 	cvt.w.s	$f16,$f16
/*  f14d480:	444af800 */ 	cfc1	$t2,$31
/*  f14d484:	00000000 */ 	nop
/*  f14d488:	314a0078 */ 	andi	$t2,$t2,0x78
/*  f14d48c:	15400005 */ 	bnez	$t2,.L0f14d4a4
/*  f14d490:	00000000 */ 	nop
/*  f14d494:	440a8000 */ 	mfc1	$t2,$f16
/*  f14d498:	3c018000 */ 	lui	$at,0x8000
/*  f14d49c:	10000007 */ 	b	.L0f14d4bc
/*  f14d4a0:	01415025 */ 	or	$t2,$t2,$at
.L0f14d4a4:
/*  f14d4a4:	10000005 */ 	b	.L0f14d4bc
/*  f14d4a8:	240affff */ 	addiu	$t2,$zero,-1
/*  f14d4ac:	440a8000 */ 	mfc1	$t2,$f16
.L0f14d4b0:
/*  f14d4b0:	00000000 */ 	nop
/*  f14d4b4:	0540fffb */ 	bltz	$t2,.L0f14d4a4
/*  f14d4b8:	00000000 */ 	nop
.L0f14d4bc:
/*  f14d4bc:	44d8f800 */ 	ctc1	$t8,$31
/*  f14d4c0:	24840001 */ 	addiu	$a0,$a0,0x1
/*  f14d4c4:	1466ffc7 */ 	bne	$v1,$a2,.L0f14d3e4
/*  f14d4c8:	a08affff */ 	sb	$t2,-0x1($a0)
/*  f14d4cc:	24e70100 */ 	addiu	$a3,$a3,0x100
/*  f14d4d0:	14e9ffc1 */ 	bne	$a3,$t1,.L0f14d3d8
/*  f14d4d4:	25080040 */ 	addiu	$t0,$t0,0x40
/*  f14d4d8:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*  f14d4dc:	8fb00020 */ 	lw	$s0,0x20($sp)
/*  f14d4e0:	8fb10024 */ 	lw	$s1,0x24($sp)
/*  f14d4e4:	8fb20028 */ 	lw	$s2,0x28($sp)
/*  f14d4e8:	03e00008 */ 	jr	$ra
/*  f14d4ec:	27bd0090 */ 	addiu	$sp,$sp,0x90
);

GLOBAL_ASM(
glabel func0f14d4f0
/*  f14d4f0:	27bdff30 */ 	addiu	$sp,$sp,-208
/*  f14d4f4:	3c02800a */ 	lui	$v0,%hi(var800a45a0)
/*  f14d4f8:	8c4245a0 */ 	lw	$v0,%lo(var800a45a0)($v0)
/*  f14d4fc:	afb20028 */ 	sw	$s2,0x28($sp)
/*  f14d500:	afbf002c */ 	sw	$ra,0x2c($sp)
/*  f14d504:	afb10024 */ 	sw	$s1,0x24($sp)
/*  f14d508:	afb00020 */ 	sw	$s0,0x20($sp)
/*  f14d50c:	afa500d4 */ 	sw	$a1,0xd4($sp)
/*  f14d510:	3c0f8008 */ 	lui	$t7,%hi(var8007f9fc)
/*  f14d514:	25eff9fc */ 	addiu	$t7,$t7,%lo(var8007f9fc)
/*  f14d518:	00809025 */ 	or	$s2,$a0,$zero
/*  f14d51c:	24080080 */ 	addiu	$t0,$zero,0x80
/*  f14d520:	25ea0060 */ 	addiu	$t2,$t7,0x60
/*  f14d524:	27ae0050 */ 	addiu	$t6,$sp,0x50
/*  f14d528:	8c510474 */ 	lw	$s1,0x474($v0)
/*  f14d52c:	8c500478 */ 	lw	$s0,0x478($v0)
.L0f14d530:
/*  f14d530:	8de10000 */ 	lw	$at,0x0($t7)
/*  f14d534:	25ef000c */ 	addiu	$t7,$t7,0xc
/*  f14d538:	25ce000c */ 	addiu	$t6,$t6,0xc
/*  f14d53c:	adc1fff4 */ 	sw	$at,-0xc($t6)
/*  f14d540:	8de1fff8 */ 	lw	$at,-0x8($t7)
/*  f14d544:	adc1fff8 */ 	sw	$at,-0x8($t6)
/*  f14d548:	8de1fffc */ 	lw	$at,-0x4($t7)
/*  f14d54c:	15eafff8 */ 	bne	$t7,$t2,.L0f14d530
/*  f14d550:	adc1fffc */ 	sw	$at,-0x4($t6)
/*  f14d554:	8de10000 */ 	lw	$at,0x0($t7)
/*  f14d558:	00003825 */ 	or	$a3,$zero,$zero
/*  f14d55c:	24050080 */ 	addiu	$a1,$zero,0x80
/*  f14d560:	adc10000 */ 	sw	$at,0x0($t6)
/*  f14d564:	000731c0 */ 	sll	$a2,$a3,0x7
.L0f14d568:
/*  f14d568:	00065880 */ 	sll	$t3,$a2,0x2
/*  f14d56c:	022b1821 */ 	addu	$v1,$s1,$t3
/*  f14d570:	02462021 */ 	addu	$a0,$s2,$a2
/*  f14d574:	00001025 */ 	or	$v0,$zero,$zero
.L0f14d578:
/*  f14d578:	908c0000 */ 	lbu	$t4,0x0($a0)
/*  f14d57c:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f14d580:	24840001 */ 	addiu	$a0,$a0,0x1
/*  f14d584:	448c2000 */ 	mtc1	$t4,$f4
/*  f14d588:	3c014f80 */ 	lui	$at,0x4f80
/*  f14d58c:	05810004 */ 	bgez	$t4,.L0f14d5a0
/*  f14d590:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f14d594:	44814000 */ 	mtc1	$at,$f8
/*  f14d598:	00000000 */ 	nop
/*  f14d59c:	46083180 */ 	add.s	$f6,$f6,$f8
.L0f14d5a0:
/*  f14d5a0:	24630004 */ 	addiu	$v1,$v1,0x4
/*  f14d5a4:	1445fff4 */ 	bne	$v0,$a1,.L0f14d578
/*  f14d5a8:	e466fffc */ 	swc1	$f6,-0x4($v1)
/*  f14d5ac:	24e70001 */ 	addiu	$a3,$a3,0x1
/*  f14d5b0:	00e8082a */ 	slt	$at,$a3,$t0
/*  f14d5b4:	5420ffec */ 	bnezl	$at,.L0f14d568
/*  f14d5b8:	000731c0 */ 	sll	$a2,$a3,0x7
/*  f14d5bc:	240d0005 */ 	addiu	$t5,$zero,0x5
/*  f14d5c0:	afad0010 */ 	sw	$t5,0x10($sp)
/*  f14d5c4:	02202025 */ 	or	$a0,$s1,$zero
/*  f14d5c8:	02002825 */ 	or	$a1,$s0,$zero
/*  f14d5cc:	24060080 */ 	addiu	$a2,$zero,0x80
/*  f14d5d0:	0fc53636 */ 	jal	func0f14d8d8
/*  f14d5d4:	27a70050 */ 	addiu	$a3,$sp,0x50
/*  f14d5d8:	3c013e80 */ 	lui	$at,0x3e80
/*  f14d5dc:	44817000 */ 	mtc1	$at,$f14
/*  f14d5e0:	3c01437f */ 	lui	$at,0x437f
/*  f14d5e4:	44816000 */ 	mtc1	$at,$f12
/*  f14d5e8:	44801000 */ 	mtc1	$zero,$f2
/*  f14d5ec:	8fa800d4 */ 	lw	$t0,0xd4($sp)
/*  f14d5f0:	00003825 */ 	or	$a3,$zero,$zero
/*  f14d5f4:	24093f00 */ 	addiu	$t1,$zero,0x3f00
/*  f14d5f8:	2406007e */ 	addiu	$a2,$zero,0x7e
.L0f14d5fc:
/*  f14d5fc:	00001825 */ 	or	$v1,$zero,$zero
/*  f14d600:	01002025 */ 	or	$a0,$t0,$zero
/*  f14d604:	00e02825 */ 	or	$a1,$a3,$zero
.L0f14d608:
/*  f14d608:	0005c880 */ 	sll	$t9,$a1,0x2
/*  f14d60c:	03301021 */ 	addu	$v0,$t9,$s0
/*  f14d610:	c44a0000 */ 	lwc1	$f10,0x0($v0)
/*  f14d614:	c4500004 */ 	lwc1	$f16,0x4($v0)
/*  f14d618:	c4440200 */ 	lwc1	$f4,0x200($v0)
/*  f14d61c:	c4460204 */ 	lwc1	$f6,0x204($v0)
/*  f14d620:	46105480 */ 	add.s	$f18,$f10,$f16
/*  f14d624:	24a50002 */ 	addiu	$a1,$a1,0x2
/*  f14d628:	24630002 */ 	addiu	$v1,$v1,0x2
/*  f14d62c:	240a0001 */ 	addiu	$t2,$zero,0x1
/*  f14d630:	46049200 */ 	add.s	$f8,$f18,$f4
/*  f14d634:	3c014f00 */ 	lui	$at,0x4f00
/*  f14d638:	46083280 */ 	add.s	$f10,$f6,$f8
/*  f14d63c:	460e5002 */ 	mul.s	$f0,$f10,$f14
/*  f14d640:	4602003c */ 	c.lt.s	$f0,$f2
/*  f14d644:	00000000 */ 	nop
/*  f14d648:	45020003 */ 	bc1fl	.L0f14d658
/*  f14d64c:	4600603c */ 	c.lt.s	$f12,$f0
/*  f14d650:	46001006 */ 	mov.s	$f0,$f2
/*  f14d654:	4600603c */ 	c.lt.s	$f12,$f0
.L0f14d658:
/*  f14d658:	00000000 */ 	nop
/*  f14d65c:	45020003 */ 	bc1fl	.L0f14d66c
/*  f14d660:	4458f800 */ 	cfc1	$t8,$31
/*  f14d664:	46006006 */ 	mov.s	$f0,$f12
/*  f14d668:	4458f800 */ 	cfc1	$t8,$31
.L0f14d66c:
/*  f14d66c:	44caf800 */ 	ctc1	$t2,$31
/*  f14d670:	00000000 */ 	nop
/*  f14d674:	46000424 */ 	cvt.w.s	$f16,$f0
/*  f14d678:	444af800 */ 	cfc1	$t2,$31
/*  f14d67c:	00000000 */ 	nop
/*  f14d680:	314a0078 */ 	andi	$t2,$t2,0x78
/*  f14d684:	51400013 */ 	beqzl	$t2,.L0f14d6d4
/*  f14d688:	440a8000 */ 	mfc1	$t2,$f16
/*  f14d68c:	44818000 */ 	mtc1	$at,$f16
/*  f14d690:	240a0001 */ 	addiu	$t2,$zero,0x1
/*  f14d694:	46100401 */ 	sub.s	$f16,$f0,$f16
/*  f14d698:	44caf800 */ 	ctc1	$t2,$31
/*  f14d69c:	00000000 */ 	nop
/*  f14d6a0:	46008424 */ 	cvt.w.s	$f16,$f16
/*  f14d6a4:	444af800 */ 	cfc1	$t2,$31
/*  f14d6a8:	00000000 */ 	nop
/*  f14d6ac:	314a0078 */ 	andi	$t2,$t2,0x78
/*  f14d6b0:	15400005 */ 	bnez	$t2,.L0f14d6c8
/*  f14d6b4:	00000000 */ 	nop
/*  f14d6b8:	440a8000 */ 	mfc1	$t2,$f16
/*  f14d6bc:	3c018000 */ 	lui	$at,0x8000
/*  f14d6c0:	10000007 */ 	b	.L0f14d6e0
/*  f14d6c4:	01415025 */ 	or	$t2,$t2,$at
.L0f14d6c8:
/*  f14d6c8:	10000005 */ 	b	.L0f14d6e0
/*  f14d6cc:	240affff */ 	addiu	$t2,$zero,-1
/*  f14d6d0:	440a8000 */ 	mfc1	$t2,$f16
.L0f14d6d4:
/*  f14d6d4:	00000000 */ 	nop
/*  f14d6d8:	0540fffb */ 	bltz	$t2,.L0f14d6c8
/*  f14d6dc:	00000000 */ 	nop
.L0f14d6e0:
/*  f14d6e0:	44d8f800 */ 	ctc1	$t8,$31
/*  f14d6e4:	24840001 */ 	addiu	$a0,$a0,0x1
/*  f14d6e8:	1466ffc7 */ 	bne	$v1,$a2,.L0f14d608
/*  f14d6ec:	a08affff */ 	sb	$t2,-0x1($a0)
/*  f14d6f0:	24e70100 */ 	addiu	$a3,$a3,0x100
/*  f14d6f4:	14e9ffc1 */ 	bne	$a3,$t1,.L0f14d5fc
/*  f14d6f8:	25080040 */ 	addiu	$t0,$t0,0x40
/*  f14d6fc:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*  f14d700:	8fb00020 */ 	lw	$s0,0x20($sp)
/*  f14d704:	8fb10024 */ 	lw	$s1,0x24($sp)
/*  f14d708:	8fb20028 */ 	lw	$s2,0x28($sp)
/*  f14d70c:	03e00008 */ 	jr	$ra
/*  f14d710:	27bd00d0 */ 	addiu	$sp,$sp,0xd0
);

GLOBAL_ASM(
glabel func0f14d714
/*  f14d714:	3c01437f */ 	lui	$at,0x437f
/*  f14d718:	44817000 */ 	mtc1	$at,$f14
/*  f14d71c:	3c013e80 */ 	lui	$at,0x3e80
/*  f14d720:	44811000 */ 	mtc1	$at,$f2
/*  f14d724:	44806000 */ 	mtc1	$zero,$f12
/*  f14d728:	00803025 */ 	or	$a2,$a0,$zero
/*  f14d72c:	00001825 */ 	or	$v1,$zero,$zero
/*  f14d730:	00003825 */ 	or	$a3,$zero,$zero
/*  f14d734:	00a04025 */ 	or	$t0,$a1,$zero
/*  f14d738:	240b0fc0 */ 	addiu	$t3,$zero,0xfc0
/*  f14d73c:	240a007e */ 	addiu	$t2,$zero,0x7e
.L0f14d740:
/*  f14d740:	00002025 */ 	or	$a0,$zero,$zero
/*  f14d744:	00662821 */ 	addu	$a1,$v1,$a2
/*  f14d748:	01004825 */ 	or	$t1,$t0,$zero
.L0f14d74c:
/*  f14d74c:	90ae0081 */ 	lbu	$t6,0x81($a1)
/*  f14d750:	90af0000 */ 	lbu	$t7,0x0($a1)
/*  f14d754:	90b90001 */ 	lbu	$t9,0x1($a1)
/*  f14d758:	90ad0080 */ 	lbu	$t5,0x80($a1)
/*  f14d75c:	01cfc021 */ 	addu	$t8,$t6,$t7
/*  f14d760:	03196021 */ 	addu	$t4,$t8,$t9
/*  f14d764:	018d7021 */ 	addu	$t6,$t4,$t5
/*  f14d768:	448e2000 */ 	mtc1	$t6,$f4
/*  f14d76c:	24840002 */ 	addiu	$a0,$a0,0x2
/*  f14d770:	24a50002 */ 	addiu	$a1,$a1,0x2
/*  f14d774:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f14d778:	24180001 */ 	addiu	$t8,$zero,0x1
/*  f14d77c:	3c014f00 */ 	lui	$at,0x4f00
/*  f14d780:	46023002 */ 	mul.s	$f0,$f6,$f2
/*  f14d784:	460c003c */ 	c.lt.s	$f0,$f12
/*  f14d788:	00000000 */ 	nop
/*  f14d78c:	45020003 */ 	bc1fl	.L0f14d79c
/*  f14d790:	4600703c */ 	c.lt.s	$f14,$f0
/*  f14d794:	46006006 */ 	mov.s	$f0,$f12
/*  f14d798:	4600703c */ 	c.lt.s	$f14,$f0
.L0f14d79c:
/*  f14d79c:	00000000 */ 	nop
/*  f14d7a0:	45020003 */ 	bc1fl	.L0f14d7b0
/*  f14d7a4:	444ff800 */ 	cfc1	$t7,$31
/*  f14d7a8:	46007006 */ 	mov.s	$f0,$f14
/*  f14d7ac:	444ff800 */ 	cfc1	$t7,$31
.L0f14d7b0:
/*  f14d7b0:	44d8f800 */ 	ctc1	$t8,$31
/*  f14d7b4:	00000000 */ 	nop
/*  f14d7b8:	46000224 */ 	cvt.w.s	$f8,$f0
/*  f14d7bc:	4458f800 */ 	cfc1	$t8,$31
/*  f14d7c0:	00000000 */ 	nop
/*  f14d7c4:	33180078 */ 	andi	$t8,$t8,0x78
/*  f14d7c8:	53000013 */ 	beqzl	$t8,.L0f14d818
/*  f14d7cc:	44184000 */ 	mfc1	$t8,$f8
/*  f14d7d0:	44814000 */ 	mtc1	$at,$f8
/*  f14d7d4:	24180001 */ 	addiu	$t8,$zero,0x1
/*  f14d7d8:	46080201 */ 	sub.s	$f8,$f0,$f8
/*  f14d7dc:	44d8f800 */ 	ctc1	$t8,$31
/*  f14d7e0:	00000000 */ 	nop
/*  f14d7e4:	46004224 */ 	cvt.w.s	$f8,$f8
/*  f14d7e8:	4458f800 */ 	cfc1	$t8,$31
/*  f14d7ec:	00000000 */ 	nop
/*  f14d7f0:	33180078 */ 	andi	$t8,$t8,0x78
/*  f14d7f4:	17000005 */ 	bnez	$t8,.L0f14d80c
/*  f14d7f8:	00000000 */ 	nop
/*  f14d7fc:	44184000 */ 	mfc1	$t8,$f8
/*  f14d800:	3c018000 */ 	lui	$at,0x8000
/*  f14d804:	10000007 */ 	b	.L0f14d824
/*  f14d808:	0301c025 */ 	or	$t8,$t8,$at
.L0f14d80c:
/*  f14d80c:	10000005 */ 	b	.L0f14d824
/*  f14d810:	2418ffff */ 	addiu	$t8,$zero,-1
/*  f14d814:	44184000 */ 	mfc1	$t8,$f8
.L0f14d818:
/*  f14d818:	00000000 */ 	nop
/*  f14d81c:	0700fffb */ 	bltz	$t8,.L0f14d80c
/*  f14d820:	00000000 */ 	nop
.L0f14d824:
/*  f14d824:	44cff800 */ 	ctc1	$t7,$31
/*  f14d828:	25290001 */ 	addiu	$t1,$t1,0x1
/*  f14d82c:	148affc7 */ 	bne	$a0,$t2,.L0f14d74c
/*  f14d830:	a138ffff */ 	sb	$t8,-0x1($t1)
/*  f14d834:	24e70040 */ 	addiu	$a3,$a3,0x40
/*  f14d838:	24630100 */ 	addiu	$v1,$v1,0x100
/*  f14d83c:	14ebffc0 */ 	bne	$a3,$t3,.L0f14d740
/*  f14d840:	25080040 */ 	addiu	$t0,$t0,0x40
/*  f14d844:	03e00008 */ 	jr	$ra
/*  f14d848:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel func0f14d84c
/*  f14d84c:	00a50019 */ 	multu	$a1,$a1
/*  f14d850:	44800000 */ 	mtc1	$zero,$f0
/*  f14d854:	00802825 */ 	or	$a1,$a0,$zero
/*  f14d858:	00003025 */ 	or	$a2,$zero,$zero
/*  f14d85c:	00001812 */ 	mflo	$v1
/*  f14d860:	00601025 */ 	or	$v0,$v1,$zero
/*  f14d864:	18600008 */ 	blez	$v1,.L0f14d888
/*  f14d868:	00027080 */ 	sll	$t6,$v0,0x2
/*  f14d86c:	01c43021 */ 	addu	$a2,$t6,$a0
.L0f14d870:
/*  f14d870:	c4a40000 */ 	lwc1	$f4,0x0($a1)
/*  f14d874:	24a50004 */ 	addiu	$a1,$a1,0x4
/*  f14d878:	00a6082b */ 	sltu	$at,$a1,$a2
/*  f14d87c:	1420fffc */ 	bnez	$at,.L0f14d870
/*  f14d880:	46040000 */ 	add.s	$f0,$f0,$f4
/*  f14d884:	00003025 */ 	or	$a2,$zero,$zero
.L0f14d888:
/*  f14d888:	3c013f80 */ 	lui	$at,0x3f80
/*  f14d88c:	44813000 */ 	mtc1	$at,$f6
/*  f14d890:	00802825 */ 	or	$a1,$a0,$zero
/*  f14d894:	1860000e */ 	blez	$v1,.L0f14d8d0
/*  f14d898:	46003083 */ 	div.s	$f2,$f6,$f0
/*  f14d89c:	c4b00000 */ 	lwc1	$f16,0x0($a1)
/*  f14d8a0:	24c60001 */ 	addiu	$a2,$a2,0x1
/*  f14d8a4:	46028482 */ 	mul.s	$f18,$f16,$f2
/*  f14d8a8:	50c20008 */ 	beql	$a2,$v0,.L0f14d8cc
/*  f14d8ac:	24a50004 */ 	addiu	$a1,$a1,0x4
.L0f14d8b0:
/*  f14d8b0:	c4b00004 */ 	lwc1	$f16,0x4($a1)
/*  f14d8b4:	24c60001 */ 	addiu	$a2,$a2,0x1
/*  f14d8b8:	e4b20000 */ 	swc1	$f18,0x0($a1)
/*  f14d8bc:	46028482 */ 	mul.s	$f18,$f16,$f2
/*  f14d8c0:	14c2fffb */ 	bne	$a2,$v0,.L0f14d8b0
/*  f14d8c4:	24a50004 */ 	addiu	$a1,$a1,0x4
/*  f14d8c8:	24a50004 */ 	addiu	$a1,$a1,0x4
.L0f14d8cc:
/*  f14d8cc:	e4b2fffc */ 	swc1	$f18,-0x4($a1)
.L0f14d8d0:
/*  f14d8d0:	03e00008 */ 	jr	$ra
/*  f14d8d4:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel func0f14d8d8
/*  f14d8d8:	27bdf9e0 */ 	addiu	$sp,$sp,-1568
/*  f14d8dc:	afb00004 */ 	sw	$s0,0x4($sp)
/*  f14d8e0:	8fb00630 */ 	lw	$s0,0x630($sp)
/*  f14d8e4:	afb10008 */ 	sw	$s1,0x8($sp)
/*  f14d8e8:	00e08825 */ 	or	$s1,$a3,$zero
/*  f14d8ec:	afb6001c */ 	sw	$s6,0x1c($sp)
/*  f14d8f0:	afb50018 */ 	sw	$s5,0x18($sp)
/*  f14d8f4:	afb40014 */ 	sw	$s4,0x14($sp)
/*  f14d8f8:	afb30010 */ 	sw	$s3,0x10($sp)
/*  f14d8fc:	afb2000c */ 	sw	$s2,0xc($sp)
/*  f14d900:	06010003 */ 	bgez	$s0,.L0f14d910
/*  f14d904:	00104043 */ 	sra	$t0,$s0,0x1
/*  f14d908:	26010001 */ 	addiu	$at,$s0,0x1
/*  f14d90c:	00014043 */ 	sra	$t0,$at,0x1
.L0f14d910:
/*  f14d910:	25090001 */ 	addiu	$t1,$t0,0x1
/*  f14d914:	01201825 */ 	or	$v1,$t1,$zero
/*  f14d918:	24c2ffff */ 	addiu	$v0,$a2,-1
/*  f14d91c:	1a000017 */ 	blez	$s0,.L0f14d97c
/*  f14d920:	00005025 */ 	or	$t2,$zero,$zero
.L0f14d924:
/*  f14d924:	1a000012 */ 	blez	$s0,.L0f14d970
/*  f14d928:	00003825 */ 	or	$a3,$zero,$zero
/*  f14d92c:	01500019 */ 	multu	$t2,$s0
/*  f14d930:	000a7080 */ 	sll	$t6,$t2,0x2
/*  f14d934:	01ca7021 */ 	addu	$t6,$t6,$t2
/*  f14d938:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f14d93c:	01ca7023 */ 	subu	$t6,$t6,$t2
/*  f14d940:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f14d944:	27af005c */ 	addiu	$t7,$sp,0x5c
/*  f14d948:	01cf5821 */ 	addu	$t3,$t6,$t7
/*  f14d94c:	0000c012 */ 	mflo	$t8
/*  f14d950:	0018c880 */ 	sll	$t9,$t8,0x2
/*  f14d954:	02396021 */ 	addu	$t4,$s1,$t9
.L0f14d958:
/*  f14d958:	c5840000 */ 	lwc1	$f4,0x0($t4)
/*  f14d95c:	24e70001 */ 	addiu	$a3,$a3,0x1
/*  f14d960:	256b0004 */ 	addiu	$t3,$t3,0x4
/*  f14d964:	258c0004 */ 	addiu	$t4,$t4,0x4
/*  f14d968:	14f0fffb */ 	bne	$a3,$s0,.L0f14d958
/*  f14d96c:	e564fffc */ 	swc1	$f4,-0x4($t3)
.L0f14d970:
/*  f14d970:	254a0001 */ 	addiu	$t2,$t2,0x1
/*  f14d974:	1550ffeb */ 	bne	$t2,$s0,.L0f14d924
/*  f14d978:	00000000 */ 	nop
.L0f14d97c:
/*  f14d97c:	18c00047 */ 	blez	$a2,.L0f14da9c
/*  f14d980:	00005025 */ 	or	$t2,$zero,$zero
/*  f14d984:	44801000 */ 	mtc1	$zero,$f2
/*  f14d988:	00000000 */ 	nop
.L0f14d98c:
/*  f14d98c:	18c00040 */ 	blez	$a2,.L0f14da90
/*  f14d990:	00005825 */ 	or	$t3,$zero,$zero
/*  f14d994:	01460019 */ 	multu	$t2,$a2
/*  f14d998:	00083823 */ 	negu	$a3,$t0
/*  f14d99c:	00007012 */ 	mflo	$t6
/*  f14d9a0:	000e7880 */ 	sll	$t7,$t6,0x2
/*  f14d9a4:	00afa021 */ 	addu	$s4,$a1,$t7
.L0f14d9a8:
/*  f14d9a8:	00e9082a */ 	slt	$at,$a3,$t1
/*  f14d9ac:	46001006 */ 	mov.s	$f0,$f2
/*  f14d9b0:	10200033 */ 	beqz	$at,.L0f14da80
/*  f14d9b4:	00e06025 */ 	or	$t4,$a3,$zero
/*  f14d9b8:	014c8021 */ 	addu	$s0,$t2,$t4
.L0f14d9bc:
/*  f14d9bc:	0050082a */ 	slt	$at,$v0,$s0
/*  f14d9c0:	02006825 */ 	or	$t5,$s0,$zero
/*  f14d9c4:	10200002 */ 	beqz	$at,.L0f14d9d0
/*  f14d9c8:	00e08825 */ 	or	$s1,$a3,$zero
/*  f14d9cc:	00406825 */ 	or	$t5,$v0,$zero
.L0f14d9d0:
/*  f14d9d0:	05a10002 */ 	bgez	$t5,.L0f14d9dc
/*  f14d9d4:	00e9082a */ 	slt	$at,$a3,$t1
/*  f14d9d8:	00006825 */ 	or	$t5,$zero,$zero
.L0f14d9dc:
/*  f14d9dc:	10200025 */ 	beqz	$at,.L0f14da74
/*  f14d9e0:	01719021 */ 	addu	$s2,$t3,$s1
/*  f14d9e4:	01a60019 */ 	multu	$t5,$a2
/*  f14d9e8:	000c7080 */ 	sll	$t6,$t4,0x2
/*  f14d9ec:	00087880 */ 	sll	$t7,$t0,0x2
/*  f14d9f0:	01e87821 */ 	addu	$t7,$t7,$t0
/*  f14d9f4:	01cc7021 */ 	addu	$t6,$t6,$t4
/*  f14d9f8:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f14d9fc:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f14da00:	01e87823 */ 	subu	$t7,$t7,$t0
/*  f14da04:	01cc7023 */ 	subu	$t6,$t6,$t4
/*  f14da08:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f14da0c:	0000c012 */ 	mflo	$t8
/*  f14da10:	0018c880 */ 	sll	$t9,$t8,0x2
/*  f14da14:	00999821 */ 	addu	$s3,$a0,$t9
/*  f14da18:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f14da1c:	01cfc021 */ 	addu	$t8,$t6,$t7
/*  f14da20:	27b9005c */ 	addiu	$t9,$sp,0x5c
/*  f14da24:	0319a821 */ 	addu	$s5,$t8,$t9
/*  f14da28:	0008b080 */ 	sll	$s6,$t0,0x2
.L0f14da2c:
/*  f14da2c:	0052082a */ 	slt	$at,$v0,$s2
/*  f14da30:	10200002 */ 	beqz	$at,.L0f14da3c
/*  f14da34:	02406825 */ 	or	$t5,$s2,$zero
/*  f14da38:	00406825 */ 	or	$t5,$v0,$zero
.L0f14da3c:
/*  f14da3c:	05a10002 */ 	bgez	$t5,.L0f14da48
/*  f14da40:	00117080 */ 	sll	$t6,$s1,0x2
/*  f14da44:	00006825 */ 	or	$t5,$zero,$zero
.L0f14da48:
/*  f14da48:	02ae7821 */ 	addu	$t7,$s5,$t6
/*  f14da4c:	000dc880 */ 	sll	$t9,$t5,0x2
/*  f14da50:	02797021 */ 	addu	$t6,$s3,$t9
/*  f14da54:	01f6c021 */ 	addu	$t8,$t7,$s6
/*  f14da58:	c7060000 */ 	lwc1	$f6,0x0($t8)
/*  f14da5c:	c5c80000 */ 	lwc1	$f8,0x0($t6)
/*  f14da60:	26310001 */ 	addiu	$s1,$s1,0x1
/*  f14da64:	26520001 */ 	addiu	$s2,$s2,0x1
/*  f14da68:	46083282 */ 	mul.s	$f10,$f6,$f8
/*  f14da6c:	1623ffef */ 	bne	$s1,$v1,.L0f14da2c
/*  f14da70:	460a0000 */ 	add.s	$f0,$f0,$f10
.L0f14da74:
/*  f14da74:	258c0001 */ 	addiu	$t4,$t4,0x1
/*  f14da78:	1583ffd0 */ 	bne	$t4,$v1,.L0f14d9bc
/*  f14da7c:	26100001 */ 	addiu	$s0,$s0,0x1
.L0f14da80:
/*  f14da80:	256b0001 */ 	addiu	$t3,$t3,0x1
/*  f14da84:	26940004 */ 	addiu	$s4,$s4,0x4
/*  f14da88:	1566ffc7 */ 	bne	$t3,$a2,.L0f14d9a8
/*  f14da8c:	e680fffc */ 	swc1	$f0,-0x4($s4)
.L0f14da90:
/*  f14da90:	254a0001 */ 	addiu	$t2,$t2,0x1
/*  f14da94:	1546ffbd */ 	bne	$t2,$a2,.L0f14d98c
/*  f14da98:	00000000 */ 	nop
.L0f14da9c:
/*  f14da9c:	8fb00004 */ 	lw	$s0,0x4($sp)
/*  f14daa0:	8fb10008 */ 	lw	$s1,0x8($sp)
/*  f14daa4:	8fb2000c */ 	lw	$s2,0xc($sp)
/*  f14daa8:	8fb30010 */ 	lw	$s3,0x10($sp)
/*  f14daac:	8fb40014 */ 	lw	$s4,0x14($sp)
/*  f14dab0:	8fb50018 */ 	lw	$s5,0x18($sp)
/*  f14dab4:	8fb6001c */ 	lw	$s6,0x1c($sp)
/*  f14dab8:	03e00008 */ 	jr	$ra
/*  f14dabc:	27bd0620 */ 	addiu	$sp,$sp,0x620
);

GLOBAL_ASM(
glabel func0f14dac0
/*  f14dac0:	27bdff98 */ 	addiu	$sp,$sp,-104
/*  f14dac4:	f7ba0038 */ 	sdc1	$f26,0x38($sp)
/*  f14dac8:	3c013d80 */ 	lui	$at,0x3d80
/*  f14dacc:	4481d000 */ 	mtc1	$at,$f26
/*  f14dad0:	f7b80030 */ 	sdc1	$f24,0x30($sp)
/*  f14dad4:	3c013c80 */ 	lui	$at,0x3c80
/*  f14dad8:	4481c000 */ 	mtc1	$at,$f24
/*  f14dadc:	f7b60028 */ 	sdc1	$f22,0x28($sp)
/*  f14dae0:	f7b40020 */ 	sdc1	$f20,0x20($sp)
/*  f14dae4:	3c01437f */ 	lui	$at,0x437f
/*  f14dae8:	afbe0060 */ 	sw	$s8,0x60($sp)
/*  f14daec:	afb7005c */ 	sw	$s7,0x5c($sp)
/*  f14daf0:	afb60058 */ 	sw	$s6,0x58($sp)
/*  f14daf4:	afb3004c */ 	sw	$s3,0x4c($sp)
/*  f14daf8:	afb20048 */ 	sw	$s2,0x48($sp)
/*  f14dafc:	afb00040 */ 	sw	$s0,0x40($sp)
/*  f14db00:	4481a000 */ 	mtc1	$at,$f20
/*  f14db04:	4480b000 */ 	mtc1	$zero,$f22
/*  f14db08:	00809825 */ 	or	$s3,$a0,$zero
/*  f14db0c:	00a0b025 */ 	or	$s6,$a1,$zero
/*  f14db10:	afbf0064 */ 	sw	$ra,0x64($sp)
/*  f14db14:	afb50054 */ 	sw	$s5,0x54($sp)
/*  f14db18:	afb40050 */ 	sw	$s4,0x50($sp)
/*  f14db1c:	afb10044 */ 	sw	$s1,0x44($sp)
/*  f14db20:	24100008 */ 	addiu	$s0,$zero,0x8
/*  f14db24:	00009025 */ 	or	$s2,$zero,$zero
/*  f14db28:	0000b825 */ 	or	$s7,$zero,$zero
/*  f14db2c:	241e0010 */ 	addiu	$s8,$zero,0x10
.L0f14db30:
/*  f14db30:	0000a825 */ 	or	$s5,$zero,$zero
/*  f14db34:	00008825 */ 	or	$s1,$zero,$zero
.L0f14db38:
/*  f14db38:	4600b306 */ 	mov.s	$f12,$f22
/*  f14db3c:	00002025 */ 	or	$a0,$zero,$zero
/*  f14db40:	001271c0 */ 	sll	$t6,$s2,0x7
.L0f14db44:
/*  f14db44:	026e7821 */ 	addu	$t7,$s3,$t6
/*  f14db48:	01f1c021 */ 	addu	$t8,$t7,$s1
/*  f14db4c:	03041821 */ 	addu	$v1,$t8,$a0
/*  f14db50:	00001025 */ 	or	$v0,$zero,$zero
.L0f14db54:
/*  f14db54:	90790000 */ 	lbu	$t9,0x0($v1)
/*  f14db58:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f14db5c:	24630080 */ 	addiu	$v1,$v1,0x80
/*  f14db60:	44992000 */ 	mtc1	$t9,$f4
/*  f14db64:	3c014f80 */ 	lui	$at,0x4f80
/*  f14db68:	07210004 */ 	bgez	$t9,.L0f14db7c
/*  f14db6c:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f14db70:	44814000 */ 	mtc1	$at,$f8
/*  f14db74:	00000000 */ 	nop
/*  f14db78:	46083180 */ 	add.s	$f6,$f6,$f8
.L0f14db7c:
/*  f14db7c:	1450fff5 */ 	bne	$v0,$s0,.L0f14db54
/*  f14db80:	46066300 */ 	add.s	$f12,$f12,$f6
/*  f14db84:	24840001 */ 	addiu	$a0,$a0,0x1
/*  f14db88:	5490ffee */ 	bnel	$a0,$s0,.L0f14db44
/*  f14db8c:	001271c0 */ 	sll	$t6,$s2,0x7
/*  f14db90:	46186302 */ 	mul.s	$f12,$f12,$f24
/*  f14db94:	2408000f */ 	addiu	$t0,$zero,0xf
/*  f14db98:	460ca03c */ 	c.lt.s	$f20,$f12
/*  f14db9c:	00000000 */ 	nop
/*  f14dba0:	45000002 */ 	bc1f	.L0f14dbac
/*  f14dba4:	00000000 */ 	nop
/*  f14dba8:	4600a306 */ 	mov.s	$f12,$f20
.L0f14dbac:
/*  f14dbac:	461a6302 */ 	mul.s	$f12,$f12,$f26
/*  f14dbb0:	52c0000a */ 	beqzl	$s6,.L0f14dbdc
/*  f14dbb4:	26b50001 */ 	addiu	$s5,$s5,0x1
/*  f14dbb8:	0c00169f */ 	jal	__f_to_ull
/*  f14dbbc:	0117a023 */ 	subu	$s4,$t0,$s7
/*  f14dbc0:	02c02025 */ 	or	$a0,$s6,$zero
/*  f14dbc4:	02802825 */ 	or	$a1,$s4,$zero
/*  f14dbc8:	02a03025 */ 	or	$a2,$s5,$zero
/*  f14dbcc:	afa20010 */ 	sw	$v0,0x10($sp)
/*  f14dbd0:	0fc53a21 */ 	jal	func0f14e884
/*  f14dbd4:	afa30014 */ 	sw	$v1,0x14($sp)
/*  f14dbd8:	26b50001 */ 	addiu	$s5,$s5,0x1
.L0f14dbdc:
/*  f14dbdc:	16beffd6 */ 	bne	$s5,$s8,.L0f14db38
/*  f14dbe0:	26310008 */ 	addiu	$s1,$s1,0x8
/*  f14dbe4:	26f70001 */ 	addiu	$s7,$s7,0x1
/*  f14dbe8:	16feffd1 */ 	bne	$s7,$s8,.L0f14db30
/*  f14dbec:	26520008 */ 	addiu	$s2,$s2,0x8
/*  f14dbf0:	8fbf0064 */ 	lw	$ra,0x64($sp)
/*  f14dbf4:	d7b40020 */ 	ldc1	$f20,0x20($sp)
/*  f14dbf8:	d7b60028 */ 	ldc1	$f22,0x28($sp)
/*  f14dbfc:	d7b80030 */ 	ldc1	$f24,0x30($sp)
/*  f14dc00:	d7ba0038 */ 	ldc1	$f26,0x38($sp)
/*  f14dc04:	8fb00040 */ 	lw	$s0,0x40($sp)
/*  f14dc08:	8fb10044 */ 	lw	$s1,0x44($sp)
/*  f14dc0c:	8fb20048 */ 	lw	$s2,0x48($sp)
/*  f14dc10:	8fb3004c */ 	lw	$s3,0x4c($sp)
/*  f14dc14:	8fb40050 */ 	lw	$s4,0x50($sp)
/*  f14dc18:	8fb50054 */ 	lw	$s5,0x54($sp)
/*  f14dc1c:	8fb60058 */ 	lw	$s6,0x58($sp)
/*  f14dc20:	8fb7005c */ 	lw	$s7,0x5c($sp)
/*  f14dc24:	8fbe0060 */ 	lw	$s8,0x60($sp)
/*  f14dc28:	03e00008 */ 	jr	$ra
/*  f14dc2c:	27bd0068 */ 	addiu	$sp,$sp,0x68
);

GLOBAL_ASM(
glabel func0f14dc30
/*  f14dc30:	27bdff78 */ 	addiu	$sp,$sp,-136
/*  f14dc34:	afbf003c */ 	sw	$ra,0x3c($sp)
/*  f14dc38:	afb00038 */ 	sw	$s0,0x38($sp)
/*  f14dc3c:	00a08025 */ 	or	$s0,$a1,$zero
/*  f14dc40:	f7ba0030 */ 	sdc1	$f26,0x30($sp)
/*  f14dc44:	f7b80028 */ 	sdc1	$f24,0x28($sp)
/*  f14dc48:	f7b60020 */ 	sdc1	$f22,0x20($sp)
/*  f14dc4c:	f7b40018 */ 	sdc1	$f20,0x18($sp)
/*  f14dc50:	0fc52a61 */ 	jal	func0f14a984
/*  f14dc54:	afa40088 */ 	sw	$a0,0x88($sp)
/*  f14dc58:	244eff80 */ 	addiu	$t6,$v0,-128
/*  f14dc5c:	448e2000 */ 	mtc1	$t6,$f4
/*  f14dc60:	8fa40088 */ 	lw	$a0,0x88($sp)
/*  f14dc64:	0fc5281b */ 	jal	func0f14a06c
/*  f14dc68:	468026a0 */ 	cvt.s.w	$f26,$f4
/*  f14dc6c:	8c4f03f4 */ 	lw	$t7,0x3f4($v0)
/*  f14dc70:	00403825 */ 	or	$a3,$v0,$zero
/*  f14dc74:	00002025 */ 	or	$a0,$zero,$zero
/*  f14dc78:	000fc880 */ 	sll	$t9,$t7,0x2
/*  f14dc7c:	07210008 */ 	bgez	$t9,.L0f14dca0
/*  f14dc80:	27a50080 */ 	addiu	$a1,$sp,0x80
/*  f14dc84:	27a6007c */ 	addiu	$a2,$sp,0x7c
/*  f14dc88:	0fc5392b */ 	jal	func0f14e4ac
/*  f14dc8c:	afa20070 */ 	sw	$v0,0x70($sp)
/*  f14dc90:	44808000 */ 	mtc1	$zero,$f16
/*  f14dc94:	8fa70070 */ 	lw	$a3,0x70($sp)
/*  f14dc98:	10000004 */ 	b	.L0f14dcac
/*  f14dc9c:	46000586 */ 	mov.s	$f22,$f0
.L0f14dca0:
/*  f14dca0:	44808000 */ 	mtc1	$zero,$f16
/*  f14dca4:	00000000 */ 	nop
/*  f14dca8:	46008586 */ 	mov.s	$f22,$f16
.L0f14dcac:
/*  f14dcac:	3c01bf80 */ 	lui	$at,0xbf80
/*  f14dcb0:	4481c000 */ 	mtc1	$at,$f24
/*  f14dcb4:	3c01437f */ 	lui	$at,0x437f
/*  f14dcb8:	4481a000 */ 	mtc1	$at,$f20
/*  f14dcbc:	3c013f80 */ 	lui	$at,0x3f80
/*  f14dcc0:	3c0a8008 */ 	lui	$t2,%hi(var8007f8dc)
/*  f14dcc4:	44819000 */ 	mtc1	$at,$f18
/*  f14dcc8:	254af8dc */ 	addiu	$t2,$t2,%lo(var8007f8dc)
/*  f14dccc:	00005825 */ 	or	$t3,$zero,$zero
/*  f14dcd0:	00004025 */ 	or	$t0,$zero,$zero
/*  f14dcd4:	24090040 */ 	addiu	$t1,$zero,0x40
.L0f14dcd8:
/*  f14dcd8:	240c003f */ 	addiu	$t4,$zero,0x3f
/*  f14dcdc:	018b1023 */ 	subu	$v0,$t4,$t3
/*  f14dce0:	30450001 */ 	andi	$a1,$v0,0x1
/*  f14dce4:	00023180 */ 	sll	$a2,$v0,0x6
/*  f14dce8:	00002025 */ 	or	$a0,$zero,$zero
.L0f14dcec:
/*  f14dcec:	8ced001c */ 	lw	$t5,0x1c($a3)
/*  f14dcf0:	3c014f80 */ 	lui	$at,0x4f80
/*  f14dcf4:	00001825 */ 	or	$v1,$zero,$zero
/*  f14dcf8:	01a87021 */ 	addu	$t6,$t5,$t0
/*  f14dcfc:	01c47821 */ 	addu	$t7,$t6,$a0
/*  f14dd00:	91f80000 */ 	lbu	$t8,0x0($t7)
/*  f14dd04:	44983000 */ 	mtc1	$t8,$f6
/*  f14dd08:	07010004 */ 	bgez	$t8,.L0f14dd1c
/*  f14dd0c:	468033a0 */ 	cvt.s.w	$f14,$f6
/*  f14dd10:	44814000 */ 	mtc1	$at,$f8
/*  f14dd14:	00000000 */ 	nop
/*  f14dd18:	46087380 */ 	add.s	$f14,$f14,$f8
.L0f14dd1c:
/*  f14dd1c:	5200002c */ 	beqzl	$s0,.L0f14ddd0
/*  f14dd20:	46008006 */ 	mov.s	$f0,$f16
/*  f14dd24:	8cf903f4 */ 	lw	$t9,0x3f4($a3)
/*  f14dd28:	8fae007c */ 	lw	$t6,0x7c($sp)
/*  f14dd2c:	00196880 */ 	sll	$t5,$t9,0x2
/*  f14dd30:	05a30027 */ 	bgezl	$t5,.L0f14ddd0
/*  f14dd34:	46008006 */ 	mov.s	$f0,$f16
/*  f14dd38:	11c00024 */ 	beqz	$t6,.L0f14ddcc
/*  f14dd3c:	8faf0080 */ 	lw	$t7,0x80($sp)
/*  f14dd40:	01e4c023 */ 	subu	$t8,$t7,$a0
/*  f14dd44:	44985000 */ 	mtc1	$t8,$f10
/*  f14dd48:	8fb9007c */ 	lw	$t9,0x7c($sp)
/*  f14dd4c:	46805020 */ 	cvt.s.w	$f0,$f10
/*  f14dd50:	44992000 */ 	mtc1	$t9,$f4
/*  f14dd54:	00000000 */ 	nop
/*  f14dd58:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f14dd5c:	4600803c */ 	c.lt.s	$f16,$f0
/*  f14dd60:	00000000 */ 	nop
/*  f14dd64:	45020004 */ 	bc1fl	.L0f14dd78
/*  f14dd68:	46000087 */ 	neg.s	$f2,$f0
/*  f14dd6c:	10000002 */ 	b	.L0f14dd78
/*  f14dd70:	46000086 */ 	mov.s	$f2,$f0
/*  f14dd74:	46000087 */ 	neg.s	$f2,$f0
.L0f14dd78:
/*  f14dd78:	46061303 */ 	div.s	$f12,$f2,$f6
/*  f14dd7c:	460c903c */ 	c.lt.s	$f18,$f12
/*  f14dd80:	00000000 */ 	nop
/*  f14dd84:	45000002 */ 	bc1f	.L0f14dd90
/*  f14dd88:	00000000 */ 	nop
/*  f14dd8c:	46009306 */ 	mov.s	$f12,$f18
.L0f14dd90:
/*  f14dd90:	460cb082 */ 	mul.s	$f2,$f22,$f12
/*  f14dd94:	8fac0080 */ 	lw	$t4,0x80($sp)
/*  f14dd98:	0184082a */ 	slt	$at,$t4,$a0
/*  f14dd9c:	10200003 */ 	beqz	$at,.L0f14ddac
/*  f14dda0:	46001006 */ 	mov.s	$f0,$f2
/*  f14dda4:	46181002 */ 	mul.s	$f0,$f2,$f24
/*  f14dda8:	00000000 */ 	nop
.L0f14ddac:
/*  f14ddac:	8d4d0000 */ 	lw	$t5,0x0($t2)
/*  f14ddb0:	8dae0088 */ 	lw	$t6,0x88($t5)
/*  f14ddb4:	448e4000 */ 	mtc1	$t6,$f8
/*  f14ddb8:	00000000 */ 	nop
/*  f14ddbc:	468042a0 */ 	cvt.s.w	$f10,$f8
/*  f14ddc0:	460a0002 */ 	mul.s	$f0,$f0,$f10
/*  f14ddc4:	10000003 */ 	b	.L0f14ddd4
/*  f14ddc8:	46007100 */ 	add.s	$f4,$f14,$f0
.L0f14ddcc:
/*  f14ddcc:	46008006 */ 	mov.s	$f0,$f16
.L0f14ddd0:
/*  f14ddd0:	46007100 */ 	add.s	$f4,$f14,$f0
.L0f14ddd4:
/*  f14ddd4:	24190001 */ 	addiu	$t9,$zero,0x1
/*  f14ddd8:	308f0004 */ 	andi	$t7,$a0,0x4
/*  f14dddc:	3c014f00 */ 	lui	$at,0x4f00
/*  f14dde0:	461a2300 */ 	add.s	$f12,$f4,$f26
/*  f14dde4:	4610603c */ 	c.lt.s	$f12,$f16
/*  f14dde8:	00000000 */ 	nop
/*  f14ddec:	45020003 */ 	bc1fl	.L0f14ddfc
/*  f14ddf0:	460ca03c */ 	c.lt.s	$f20,$f12
/*  f14ddf4:	46008306 */ 	mov.s	$f12,$f16
/*  f14ddf8:	460ca03c */ 	c.lt.s	$f20,$f12
.L0f14ddfc:
/*  f14ddfc:	00000000 */ 	nop
/*  f14de00:	45000002 */ 	bc1f	.L0f14de0c
/*  f14de04:	00000000 */ 	nop
/*  f14de08:	4600a306 */ 	mov.s	$f12,$f20
.L0f14de0c:
/*  f14de0c:	10a00007 */ 	beqz	$a1,.L0f14de2c
/*  f14de10:	00000000 */ 	nop
/*  f14de14:	11e00003 */ 	beqz	$t7,.L0f14de24
/*  f14de18:	24020004 */ 	addiu	$v0,$zero,0x4
/*  f14de1c:	10000003 */ 	b	.L0f14de2c
/*  f14de20:	2403fffc */ 	addiu	$v1,$zero,-4
.L0f14de24:
/*  f14de24:	10000001 */ 	b	.L0f14de2c
/*  f14de28:	00401825 */ 	or	$v1,$v0,$zero
.L0f14de2c:
/*  f14de2c:	4458f800 */ 	cfc1	$t8,$31
/*  f14de30:	44d9f800 */ 	ctc1	$t9,$31
/*  f14de34:	00000000 */ 	nop
/*  f14de38:	460061a4 */ 	cvt.w.s	$f6,$f12
/*  f14de3c:	4459f800 */ 	cfc1	$t9,$31
/*  f14de40:	00000000 */ 	nop
/*  f14de44:	33390078 */ 	andi	$t9,$t9,0x78
/*  f14de48:	53200013 */ 	beqzl	$t9,.L0f14de98
/*  f14de4c:	44193000 */ 	mfc1	$t9,$f6
/*  f14de50:	44813000 */ 	mtc1	$at,$f6
/*  f14de54:	24190001 */ 	addiu	$t9,$zero,0x1
/*  f14de58:	46066181 */ 	sub.s	$f6,$f12,$f6
/*  f14de5c:	44d9f800 */ 	ctc1	$t9,$31
/*  f14de60:	00000000 */ 	nop
/*  f14de64:	460031a4 */ 	cvt.w.s	$f6,$f6
/*  f14de68:	4459f800 */ 	cfc1	$t9,$31
/*  f14de6c:	00000000 */ 	nop
/*  f14de70:	33390078 */ 	andi	$t9,$t9,0x78
/*  f14de74:	17200005 */ 	bnez	$t9,.L0f14de8c
/*  f14de78:	00000000 */ 	nop
/*  f14de7c:	44193000 */ 	mfc1	$t9,$f6
/*  f14de80:	3c018000 */ 	lui	$at,0x8000
/*  f14de84:	10000007 */ 	b	.L0f14dea4
/*  f14de88:	0321c825 */ 	or	$t9,$t9,$at
.L0f14de8c:
/*  f14de8c:	10000005 */ 	b	.L0f14dea4
/*  f14de90:	2419ffff */ 	addiu	$t9,$zero,-1
/*  f14de94:	44193000 */ 	mfc1	$t9,$f6
.L0f14de98:
/*  f14de98:	00000000 */ 	nop
/*  f14de9c:	0720fffb */ 	bltz	$t9,.L0f14de8c
/*  f14dea0:	00000000 */ 	nop
.L0f14dea4:
/*  f14dea4:	8cec0004 */ 	lw	$t4,0x4($a3)
/*  f14dea8:	44d8f800 */ 	ctc1	$t8,$31
/*  f14deac:	01866821 */ 	addu	$t5,$t4,$a2
/*  f14deb0:	01a47021 */ 	addu	$t6,$t5,$a0
/*  f14deb4:	24840001 */ 	addiu	$a0,$a0,0x1
/*  f14deb8:	01c37821 */ 	addu	$t7,$t6,$v1
/*  f14debc:	1489ff8b */ 	bne	$a0,$t1,.L0f14dcec
/*  f14dec0:	a1f90000 */ 	sb	$t9,0x0($t7)
/*  f14dec4:	256b0001 */ 	addiu	$t3,$t3,0x1
/*  f14dec8:	1569ff83 */ 	bne	$t3,$t1,.L0f14dcd8
/*  f14decc:	25080040 */ 	addiu	$t0,$t0,0x40
/*  f14ded0:	8fbf003c */ 	lw	$ra,0x3c($sp)
/*  f14ded4:	d7b40018 */ 	ldc1	$f20,0x18($sp)
/*  f14ded8:	d7b60020 */ 	ldc1	$f22,0x20($sp)
/*  f14dedc:	d7b80028 */ 	ldc1	$f24,0x28($sp)
/*  f14dee0:	d7ba0030 */ 	ldc1	$f26,0x30($sp)
/*  f14dee4:	8fb00038 */ 	lw	$s0,0x38($sp)
/*  f14dee8:	03e00008 */ 	jr	$ra
/*  f14deec:	27bd0088 */ 	addiu	$sp,$sp,0x88
);

const char var7f1b6d04[] = "camdraw.c";
const char var7f1b6d10[] = "camdraw.c";
const char var7f1b6d1c[] = "Cam %d -> Balance : No Data Available\n";

GLOBAL_ASM(
glabel func0f14def0
/*  f14def0:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*  f14def4:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f14def8:	afa40028 */ 	sw	$a0,0x28($sp)
/*  f14defc:	afa5002c */ 	sw	$a1,0x2c($sp)
/*  f14df00:	afa60030 */ 	sw	$a2,0x30($sp)
/*  f14df04:	0fc5281b */ 	jal	func0f14a06c
/*  f14df08:	2404ffff */ 	addiu	$a0,$zero,-1
/*  f14df0c:	8fa40028 */ 	lw	$a0,0x28($sp)
/*  f14df10:	2401ffff */ 	addiu	$at,$zero,-1
/*  f14df14:	afa20024 */ 	sw	$v0,0x24($sp)
/*  f14df18:	50810006 */ 	beql	$a0,$at,.L0f14df34
/*  f14df1c:	afa00020 */ 	sw	$zero,0x20($sp)
/*  f14df20:	0fc5281b */ 	jal	func0f14a06c
/*  f14df24:	00000000 */ 	nop
/*  f14df28:	10000002 */ 	b	.L0f14df34
/*  f14df2c:	afa20020 */ 	sw	$v0,0x20($sp)
/*  f14df30:	afa00020 */ 	sw	$zero,0x20($sp)
.L0f14df34:
/*  f14df34:	0fc5281b */ 	jal	func0f14a06c
/*  f14df38:	2404fffc */ 	addiu	$a0,$zero,-4
/*  f14df3c:	afa2001c */ 	sw	$v0,0x1c($sp)
/*  f14df40:	0fc5281b */ 	jal	func0f14a06c
/*  f14df44:	2404fffb */ 	addiu	$a0,$zero,-5
/*  f14df48:	3c077f1b */ 	lui	$a3,%hi(var7f1b6d04)
/*  f14df4c:	afa20018 */ 	sw	$v0,0x18($sp)
/*  f14df50:	24e76d04 */ 	addiu	$a3,$a3,%lo(var7f1b6d04)
/*  f14df54:	00402025 */ 	or	$a0,$v0,$zero
/*  f14df58:	8fa50024 */ 	lw	$a1,0x24($sp)
/*  f14df5c:	0fc53143 */ 	jal	func0f14c50c
/*  f14df60:	24060db4 */ 	addiu	$a2,$zero,0xdb4
/*  f14df64:	2404ffff */ 	addiu	$a0,$zero,-1
/*  f14df68:	0fc5370c */ 	jal	func0f14dc30
/*  f14df6c:	00002825 */ 	or	$a1,$zero,$zero
/*  f14df70:	8fa40020 */ 	lw	$a0,0x20($sp)
/*  f14df74:	50800004 */ 	beqzl	$a0,.L0f14df88
/*  f14df78:	2404fffb */ 	addiu	$a0,$zero,-5
/*  f14df7c:	0fc53871 */ 	jal	func0f14e1c4
/*  f14df80:	00000000 */ 	nop
/*  f14df84:	2404fffb */ 	addiu	$a0,$zero,-5
.L0f14df88:
/*  f14df88:	0fc5370c */ 	jal	func0f14dc30
/*  f14df8c:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f14df90:	0fc53871 */ 	jal	func0f14e1c4
/*  f14df94:	8fa40018 */ 	lw	$a0,0x18($sp)
/*  f14df98:	3c077f1b */ 	lui	$a3,%hi(var7f1b6d10)
/*  f14df9c:	24e76d10 */ 	addiu	$a3,$a3,%lo(var7f1b6d10)
/*  f14dfa0:	8fa4001c */ 	lw	$a0,0x1c($sp)
/*  f14dfa4:	8fa50018 */ 	lw	$a1,0x18($sp)
/*  f14dfa8:	0fc53143 */ 	jal	func0f14c50c
/*  f14dfac:	24060dbf */ 	addiu	$a2,$zero,0xdbf
/*  f14dfb0:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f14dfb4:	27bd0028 */ 	addiu	$sp,$sp,0x28
/*  f14dfb8:	03e00008 */ 	jr	$ra
/*  f14dfbc:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel func0f14dfc0
/*  f14dfc0:	30c20001 */ 	andi	$v0,$a2,0x1
/*  f14dfc4:	27bdffb0 */ 	addiu	$sp,$sp,-80
/*  f14dfc8:	10400008 */ 	beqz	$v0,.L0f14dfec
/*  f14dfcc:	00803825 */ 	or	$a3,$a0,$zero
/*  f14dfd0:	30ae0004 */ 	andi	$t6,$a1,0x4
/*  f14dfd4:	11c00003 */ 	beqz	$t6,.L0f14dfe4
/*  f14dfd8:	24030004 */ 	addiu	$v1,$zero,0x4
/*  f14dfdc:	10000004 */ 	b	.L0f14dff0
/*  f14dfe0:	2404fffc */ 	addiu	$a0,$zero,-4
.L0f14dfe4:
/*  f14dfe4:	10000002 */ 	b	.L0f14dff0
/*  f14dfe8:	00602025 */ 	or	$a0,$v1,$zero
.L0f14dfec:
/*  f14dfec:	00002025 */ 	or	$a0,$zero,$zero
.L0f14dff0:
/*  f14dff0:	8cef0004 */ 	lw	$t7,0x4($a3)
/*  f14dff4:	00064180 */ 	sll	$t0,$a2,0x6
/*  f14dff8:	3c0d0001 */ 	lui	$t5,0x1
/*  f14dffc:	008fc021 */ 	addu	$t8,$a0,$t7
/*  f14e000:	0308c821 */ 	addu	$t9,$t8,$t0
/*  f14e004:	03257021 */ 	addu	$t6,$t9,$a1
/*  f14e008:	91cf0000 */ 	lbu	$t7,0x0($t6)
/*  f14e00c:	24d8ffff */ 	addiu	$t8,$a2,-1
/*  f14e010:	33190001 */ 	andi	$t9,$t8,0x1
/*  f14e014:	13200008 */ 	beqz	$t9,.L0f14e038
/*  f14e018:	afaf0028 */ 	sw	$t7,0x28($sp)
/*  f14e01c:	30ae0004 */ 	andi	$t6,$a1,0x4
/*  f14e020:	11c00003 */ 	beqz	$t6,.L0f14e030
/*  f14e024:	24030004 */ 	addiu	$v1,$zero,0x4
/*  f14e028:	10000004 */ 	b	.L0f14e03c
/*  f14e02c:	2404fffc */ 	addiu	$a0,$zero,-4
.L0f14e030:
/*  f14e030:	10000002 */ 	b	.L0f14e03c
/*  f14e034:	00602025 */ 	or	$a0,$v1,$zero
.L0f14e038:
/*  f14e038:	00002025 */ 	or	$a0,$zero,$zero
.L0f14e03c:
/*  f14e03c:	8cef0004 */ 	lw	$t7,0x4($a3)
/*  f14e040:	35ad869f */ 	ori	$t5,$t5,0x869f
/*  f14e044:	27ac0028 */ 	addiu	$t4,$sp,0x28
/*  f14e048:	008fc021 */ 	addu	$t8,$a0,$t7
/*  f14e04c:	0308c821 */ 	addu	$t9,$t8,$t0
/*  f14e050:	03257021 */ 	addu	$t6,$t9,$a1
/*  f14e054:	91cfffc0 */ 	lbu	$t7,-0x40($t6)
/*  f14e058:	27ab003c */ 	addiu	$t3,$sp,0x3c
/*  f14e05c:	10400009 */ 	beqz	$v0,.L0f14e084
/*  f14e060:	afaf002c */ 	sw	$t7,0x2c($sp)
/*  f14e064:	24b8ffff */ 	addiu	$t8,$a1,-1
/*  f14e068:	33190004 */ 	andi	$t9,$t8,0x4
/*  f14e06c:	13200003 */ 	beqz	$t9,.L0f14e07c
/*  f14e070:	24030004 */ 	addiu	$v1,$zero,0x4
/*  f14e074:	10000004 */ 	b	.L0f14e088
/*  f14e078:	2404fffc */ 	addiu	$a0,$zero,-4
.L0f14e07c:
/*  f14e07c:	10000002 */ 	b	.L0f14e088
/*  f14e080:	00602025 */ 	or	$a0,$v1,$zero
.L0f14e084:
/*  f14e084:	00002025 */ 	or	$a0,$zero,$zero
.L0f14e088:
/*  f14e088:	8cee0004 */ 	lw	$t6,0x4($a3)
/*  f14e08c:	008e7821 */ 	addu	$t7,$a0,$t6
/*  f14e090:	01e8c021 */ 	addu	$t8,$t7,$t0
/*  f14e094:	0305c821 */ 	addu	$t9,$t8,$a1
/*  f14e098:	932effff */ 	lbu	$t6,-0x1($t9)
/*  f14e09c:	24cf0001 */ 	addiu	$t7,$a2,0x1
/*  f14e0a0:	31f80001 */ 	andi	$t8,$t7,0x1
/*  f14e0a4:	13000008 */ 	beqz	$t8,.L0f14e0c8
/*  f14e0a8:	afae0030 */ 	sw	$t6,0x30($sp)
/*  f14e0ac:	30b90004 */ 	andi	$t9,$a1,0x4
/*  f14e0b0:	13200003 */ 	beqz	$t9,.L0f14e0c0
/*  f14e0b4:	24030004 */ 	addiu	$v1,$zero,0x4
/*  f14e0b8:	10000004 */ 	b	.L0f14e0cc
/*  f14e0bc:	2404fffc */ 	addiu	$a0,$zero,-4
.L0f14e0c0:
/*  f14e0c0:	10000002 */ 	b	.L0f14e0cc
/*  f14e0c4:	00602025 */ 	or	$a0,$v1,$zero
.L0f14e0c8:
/*  f14e0c8:	00002025 */ 	or	$a0,$zero,$zero
.L0f14e0cc:
/*  f14e0cc:	8cee0004 */ 	lw	$t6,0x4($a3)
/*  f14e0d0:	008e7821 */ 	addu	$t7,$a0,$t6
/*  f14e0d4:	01e8c021 */ 	addu	$t8,$t7,$t0
/*  f14e0d8:	0305c821 */ 	addu	$t9,$t8,$a1
/*  f14e0dc:	932e0040 */ 	lbu	$t6,0x40($t9)
/*  f14e0e0:	00002025 */ 	or	$a0,$zero,$zero
/*  f14e0e4:	10400009 */ 	beqz	$v0,.L0f14e10c
/*  f14e0e8:	afae0034 */ 	sw	$t6,0x34($sp)
/*  f14e0ec:	24af0001 */ 	addiu	$t7,$a1,0x1
/*  f14e0f0:	31f80004 */ 	andi	$t8,$t7,0x4
/*  f14e0f4:	13000003 */ 	beqz	$t8,.L0f14e104
/*  f14e0f8:	24030004 */ 	addiu	$v1,$zero,0x4
/*  f14e0fc:	10000003 */ 	b	.L0f14e10c
/*  f14e100:	2404fffc */ 	addiu	$a0,$zero,-4
.L0f14e104:
/*  f14e104:	10000001 */ 	b	.L0f14e10c
/*  f14e108:	00602025 */ 	or	$a0,$v1,$zero
.L0f14e10c:
/*  f14e10c:	8cf90004 */ 	lw	$t9,0x4($a3)
/*  f14e110:	00001025 */ 	or	$v0,$zero,$zero
/*  f14e114:	00001825 */ 	or	$v1,$zero,$zero
/*  f14e118:	00997021 */ 	addu	$t6,$a0,$t9
/*  f14e11c:	01c87821 */ 	addu	$t7,$t6,$t0
/*  f14e120:	01e5c021 */ 	addu	$t8,$t7,$a1
/*  f14e124:	93190001 */ 	lbu	$t9,0x1($t8)
/*  f14e128:	240affff */ 	addiu	$t2,$zero,-1
/*  f14e12c:	24090005 */ 	addiu	$t1,$zero,0x5
/*  f14e130:	afb90038 */ 	sw	$t9,0x38($sp)
/*  f14e134:	2404270f */ 	addiu	$a0,$zero,0x270f
.L0f14e138:
/*  f14e138:	01402825 */ 	or	$a1,$t2,$zero
/*  f14e13c:	00003025 */ 	or	$a2,$zero,$zero
/*  f14e140:	27a70028 */ 	addiu	$a3,$sp,0x28
.L0f14e144:
/*  f14e144:	8ce80000 */ 	lw	$t0,0x0($a3)
/*  f14e148:	0104082b */ 	sltu	$at,$t0,$a0
/*  f14e14c:	50200004 */ 	beqzl	$at,.L0f14e160
/*  f14e150:	24c60001 */ 	addiu	$a2,$a2,0x1
/*  f14e154:	00c02825 */ 	or	$a1,$a2,$zero
/*  f14e158:	01002025 */ 	or	$a0,$t0,$zero
/*  f14e15c:	24c60001 */ 	addiu	$a2,$a2,0x1
.L0f14e160:
/*  f14e160:	14c9fff8 */ 	bne	$a2,$t1,.L0f14e144
/*  f14e164:	24e70004 */ 	addiu	$a3,$a3,0x4
/*  f14e168:	10aa0009 */ 	beq	$a1,$t2,.L0f14e190
/*  f14e16c:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f14e170:	00057080 */ 	sll	$t6,$a1,0x2
/*  f14e174:	018e2021 */ 	addu	$a0,$t4,$t6
/*  f14e178:	8c8f0000 */ 	lw	$t7,0x0($a0)
/*  f14e17c:	0002c080 */ 	sll	$t8,$v0,0x2
/*  f14e180:	0178c821 */ 	addu	$t9,$t3,$t8
/*  f14e184:	af2f0000 */ 	sw	$t7,0x0($t9)
/*  f14e188:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f14e18c:	ac8d0000 */ 	sw	$t5,0x0($a0)
.L0f14e190:
/*  f14e190:	5469ffe9 */ 	bnel	$v1,$t1,.L0f14e138
/*  f14e194:	2404270f */ 	addiu	$a0,$zero,0x270f
/*  f14e198:	8fae0048 */ 	lw	$t6,0x48($sp)
/*  f14e19c:	8fb80040 */ 	lw	$t8,0x40($sp)
/*  f14e1a0:	8fb90044 */ 	lw	$t9,0x44($sp)
/*  f14e1a4:	24010003 */ 	addiu	$at,$zero,0x3
/*  f14e1a8:	01d87821 */ 	addu	$t7,$t6,$t8
/*  f14e1ac:	01f91021 */ 	addu	$v0,$t7,$t9
/*  f14e1b0:	0041001b */ 	divu	$zero,$v0,$at
/*  f14e1b4:	00001012 */ 	mflo	$v0
/*  f14e1b8:	27bd0050 */ 	addiu	$sp,$sp,0x50
/*  f14e1bc:	03e00008 */ 	jr	$ra
/*  f14e1c0:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel func0f14e1c4
/*  f14e1c4:	27bdff40 */ 	addiu	$sp,$sp,-192
/*  f14e1c8:	afb10040 */ 	sw	$s1,0x40($sp)
/*  f14e1cc:	00808825 */ 	or	$s1,$a0,$zero
/*  f14e1d0:	afbf004c */ 	sw	$ra,0x4c($sp)
/*  f14e1d4:	afb30048 */ 	sw	$s3,0x48($sp)
/*  f14e1d8:	afb20044 */ 	sw	$s2,0x44($sp)
/*  f14e1dc:	afb0003c */ 	sw	$s0,0x3c($sp)
/*  f14e1e0:	f7bc0030 */ 	sdc1	$f28,0x30($sp)
/*  f14e1e4:	f7ba0028 */ 	sdc1	$f26,0x28($sp)
/*  f14e1e8:	f7b80020 */ 	sdc1	$f24,0x20($sp)
/*  f14e1ec:	f7b60018 */ 	sdc1	$f22,0x18($sp)
/*  f14e1f0:	f7b40010 */ 	sdc1	$f20,0x10($sp)
/*  f14e1f4:	27a400bc */ 	addiu	$a0,$sp,0xbc
/*  f14e1f8:	27a500b8 */ 	addiu	$a1,$sp,0xb8
/*  f14e1fc:	27a600b4 */ 	addiu	$a2,$sp,0xb4
/*  f14e200:	0fc53b36 */ 	jal	func0f14ecd8
/*  f14e204:	27a700b0 */ 	addiu	$a3,$sp,0xb0
/*  f14e208:	8fb900b4 */ 	lw	$t9,0xb4($sp)
/*  f14e20c:	8fab00bc */ 	lw	$t3,0xbc($sp)
/*  f14e210:	3c013e80 */ 	lui	$at,0x3e80
/*  f14e214:	44813000 */ 	mtc1	$at,$f6
/*  f14e218:	032b6023 */ 	subu	$t4,$t9,$t3
/*  f14e21c:	448c2000 */ 	mtc1	$t4,$f4
/*  f14e220:	24030001 */ 	addiu	$v1,$zero,0x1
/*  f14e224:	8fae00b0 */ 	lw	$t6,0xb0($sp)
/*  f14e228:	468026a0 */ 	cvt.s.w	$f26,$f4
/*  f14e22c:	8faf00b8 */ 	lw	$t7,0xb8($sp)
/*  f14e230:	032b1021 */ 	addu	$v0,$t9,$t3
/*  f14e234:	3c014f00 */ 	lui	$at,0x4f00
/*  f14e238:	01cf3021 */ 	addu	$a2,$t6,$t7
/*  f14e23c:	00068042 */ 	srl	$s0,$a2,0x1
/*  f14e240:	4606d202 */ 	mul.s	$f8,$f26,$f6
/*  f14e244:	02003025 */ 	or	$a2,$s0,$zero
/*  f14e248:	00027042 */ 	srl	$t6,$v0,0x1
/*  f14e24c:	02202025 */ 	or	$a0,$s1,$zero
/*  f14e250:	444df800 */ 	cfc1	$t5,$31
/*  f14e254:	44c3f800 */ 	ctc1	$v1,$31
/*  f14e258:	00000000 */ 	nop
/*  f14e25c:	460042a4 */ 	cvt.w.s	$f10,$f8
/*  f14e260:	4443f800 */ 	cfc1	$v1,$31
/*  f14e264:	00000000 */ 	nop
/*  f14e268:	30630078 */ 	andi	$v1,$v1,0x78
/*  f14e26c:	50600013 */ 	beqzl	$v1,.L0f14e2bc
/*  f14e270:	44035000 */ 	mfc1	$v1,$f10
/*  f14e274:	44815000 */ 	mtc1	$at,$f10
/*  f14e278:	24030001 */ 	addiu	$v1,$zero,0x1
/*  f14e27c:	460a4281 */ 	sub.s	$f10,$f8,$f10
/*  f14e280:	44c3f800 */ 	ctc1	$v1,$31
/*  f14e284:	00000000 */ 	nop
/*  f14e288:	460052a4 */ 	cvt.w.s	$f10,$f10
/*  f14e28c:	4443f800 */ 	cfc1	$v1,$31
/*  f14e290:	00000000 */ 	nop
/*  f14e294:	30630078 */ 	andi	$v1,$v1,0x78
/*  f14e298:	14600005 */ 	bnez	$v1,.L0f14e2b0
/*  f14e29c:	00000000 */ 	nop
/*  f14e2a0:	44035000 */ 	mfc1	$v1,$f10
/*  f14e2a4:	3c018000 */ 	lui	$at,0x8000
/*  f14e2a8:	10000007 */ 	b	.L0f14e2c8
/*  f14e2ac:	00611825 */ 	or	$v1,$v1,$at
.L0f14e2b0:
/*  f14e2b0:	10000005 */ 	b	.L0f14e2c8
/*  f14e2b4:	2403ffff */ 	addiu	$v1,$zero,-1
/*  f14e2b8:	44035000 */ 	mfc1	$v1,$f10
.L0f14e2bc:
/*  f14e2bc:	00000000 */ 	nop
/*  f14e2c0:	0460fffb */ 	bltz	$v1,.L0f14e2b0
/*  f14e2c4:	00000000 */ 	nop
.L0f14e2c8:
/*  f14e2c8:	44cdf800 */ 	ctc1	$t5,$31
/*  f14e2cc:	006e9821 */ 	addu	$s3,$v1,$t6
/*  f14e2d0:	0fc537f0 */ 	jal	func0f14dfc0
/*  f14e2d4:	01c32823 */ 	subu	$a1,$t6,$v1
/*  f14e2d8:	00409025 */ 	or	$s2,$v0,$zero
/*  f14e2dc:	02202025 */ 	or	$a0,$s1,$zero
/*  f14e2e0:	02602825 */ 	or	$a1,$s3,$zero
/*  f14e2e4:	0fc537f0 */ 	jal	func0f14dfc0
/*  f14e2e8:	02003025 */ 	or	$a2,$s0,$zero
/*  f14e2ec:	3c013f00 */ 	lui	$at,0x3f00
/*  f14e2f0:	44818000 */ 	mtc1	$at,$f16
/*  f14e2f4:	4480a000 */ 	mtc1	$zero,$f20
/*  f14e2f8:	00409825 */ 	or	$s3,$v0,$zero
/*  f14e2fc:	4610d582 */ 	mul.s	$f22,$f26,$f16
/*  f14e300:	3c013f80 */ 	lui	$at,0x3f80
/*  f14e304:	4616a03c */ 	c.lt.s	$f20,$f22
/*  f14e308:	4600b606 */ 	mov.s	$f24,$f22
/*  f14e30c:	4502005c */ 	bc1fl	.L0f14e480
/*  f14e310:	8fbf004c */ 	lw	$ra,0x4c($sp)
/*  f14e314:	4481e000 */ 	mtc1	$at,$f28
/*  f14e318:	4616b680 */ 	add.s	$f26,$f22,$f22
.L0f14e31c:
/*  f14e31c:	4614d482 */ 	mul.s	$f18,$f26,$f20
/*  f14e320:	00008025 */ 	or	$s0,$zero,$zero
/*  f14e324:	4614a102 */ 	mul.s	$f4,$f20,$f20
/*  f14e328:	0c012974 */ 	jal	sqrtf
/*  f14e32c:	46049301 */ 	sub.s	$f12,$f18,$f4
/*  f14e330:	4600b181 */ 	sub.s	$f6,$f22,$f0
/*  f14e334:	8fac00b8 */ 	lw	$t4,0xb8($sp)
/*  f14e338:	8fad00b0 */ 	lw	$t5,0xb0($sp)
/*  f14e33c:	4600a28d */ 	trunc.w.s	$f10,$f20
/*  f14e340:	4600320d */ 	trunc.w.s	$f8,$f6
/*  f14e344:	44025000 */ 	mfc1	$v0,$f10
/*  f14e348:	461ca500 */ 	add.s	$f20,$f20,$f28
/*  f14e34c:	440a4000 */ 	mfc1	$t2,$f8
/*  f14e350:	004c2021 */ 	addu	$a0,$v0,$t4
/*  f14e354:	30860001 */ 	andi	$a2,$a0,0x1
/*  f14e358:	19400044 */ 	blez	$t2,.L0f14e46c
/*  f14e35c:	01a22823 */ 	subu	$a1,$t5,$v0
/*  f14e360:	00043980 */ 	sll	$a3,$a0,0x6
/*  f14e364:	30a80001 */ 	andi	$t0,$a1,0x1
/*  f14e368:	00054980 */ 	sll	$t1,$a1,0x6
.L0f14e36c:
/*  f14e36c:	8fb900bc */ 	lw	$t9,0xbc($sp)
/*  f14e370:	8fab00b4 */ 	lw	$t3,0xb4($sp)
/*  f14e374:	00001825 */ 	or	$v1,$zero,$zero
/*  f14e378:	03301021 */ 	addu	$v0,$t9,$s0
/*  f14e37c:	00402025 */ 	or	$a0,$v0,$zero
/*  f14e380:	10c00008 */ 	beqz	$a2,.L0f14e3a4
/*  f14e384:	01702823 */ 	subu	$a1,$t3,$s0
/*  f14e388:	304e0004 */ 	andi	$t6,$v0,0x4
/*  f14e38c:	11c00003 */ 	beqz	$t6,.L0f14e39c
/*  f14e390:	24020004 */ 	addiu	$v0,$zero,0x4
/*  f14e394:	10000003 */ 	b	.L0f14e3a4
/*  f14e398:	2403fffc */ 	addiu	$v1,$zero,-4
.L0f14e39c:
/*  f14e39c:	10000001 */ 	b	.L0f14e3a4
/*  f14e3a0:	00401825 */ 	or	$v1,$v0,$zero
.L0f14e3a4:
/*  f14e3a4:	8e2f0004 */ 	lw	$t7,0x4($s1)
/*  f14e3a8:	30990004 */ 	andi	$t9,$a0,0x4
/*  f14e3ac:	01e7c021 */ 	addu	$t8,$t7,$a3
/*  f14e3b0:	03046021 */ 	addu	$t4,$t8,$a0
/*  f14e3b4:	01836821 */ 	addu	$t5,$t4,$v1
/*  f14e3b8:	11000007 */ 	beqz	$t0,.L0f14e3d8
/*  f14e3bc:	a1b20000 */ 	sb	$s2,0x0($t5)
/*  f14e3c0:	13200003 */ 	beqz	$t9,.L0f14e3d0
/*  f14e3c4:	24020004 */ 	addiu	$v0,$zero,0x4
/*  f14e3c8:	10000004 */ 	b	.L0f14e3dc
/*  f14e3cc:	2403fffc */ 	addiu	$v1,$zero,-4
.L0f14e3d0:
/*  f14e3d0:	10000002 */ 	b	.L0f14e3dc
/*  f14e3d4:	00401825 */ 	or	$v1,$v0,$zero
.L0f14e3d8:
/*  f14e3d8:	00001825 */ 	or	$v1,$zero,$zero
.L0f14e3dc:
/*  f14e3dc:	8e2b0004 */ 	lw	$t3,0x4($s1)
/*  f14e3e0:	30ac0004 */ 	andi	$t4,$a1,0x4
/*  f14e3e4:	01697021 */ 	addu	$t6,$t3,$t1
/*  f14e3e8:	01c47821 */ 	addu	$t7,$t6,$a0
/*  f14e3ec:	01e3c021 */ 	addu	$t8,$t7,$v1
/*  f14e3f0:	10c00007 */ 	beqz	$a2,.L0f14e410
/*  f14e3f4:	a3120000 */ 	sb	$s2,0x0($t8)
/*  f14e3f8:	11800003 */ 	beqz	$t4,.L0f14e408
/*  f14e3fc:	24020004 */ 	addiu	$v0,$zero,0x4
/*  f14e400:	10000004 */ 	b	.L0f14e414
/*  f14e404:	2403fffc */ 	addiu	$v1,$zero,-4
.L0f14e408:
/*  f14e408:	10000002 */ 	b	.L0f14e414
/*  f14e40c:	00401825 */ 	or	$v1,$v0,$zero
.L0f14e410:
/*  f14e410:	00001825 */ 	or	$v1,$zero,$zero
.L0f14e414:
/*  f14e414:	8e2d0004 */ 	lw	$t5,0x4($s1)
/*  f14e418:	30af0004 */ 	andi	$t7,$a1,0x4
/*  f14e41c:	01a7c821 */ 	addu	$t9,$t5,$a3
/*  f14e420:	03255821 */ 	addu	$t3,$t9,$a1
/*  f14e424:	01637021 */ 	addu	$t6,$t3,$v1
/*  f14e428:	11000007 */ 	beqz	$t0,.L0f14e448
/*  f14e42c:	a1d30000 */ 	sb	$s3,0x0($t6)
/*  f14e430:	11e00003 */ 	beqz	$t7,.L0f14e440
/*  f14e434:	24020004 */ 	addiu	$v0,$zero,0x4
/*  f14e438:	10000004 */ 	b	.L0f14e44c
/*  f14e43c:	2403fffc */ 	addiu	$v1,$zero,-4
.L0f14e440:
/*  f14e440:	10000002 */ 	b	.L0f14e44c
/*  f14e444:	00401825 */ 	or	$v1,$v0,$zero
.L0f14e448:
/*  f14e448:	00001825 */ 	or	$v1,$zero,$zero
.L0f14e44c:
/*  f14e44c:	8e380004 */ 	lw	$t8,0x4($s1)
/*  f14e450:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f14e454:	020a082a */ 	slt	$at,$s0,$t2
/*  f14e458:	03096021 */ 	addu	$t4,$t8,$t1
/*  f14e45c:	01856821 */ 	addu	$t5,$t4,$a1
/*  f14e460:	01a3c821 */ 	addu	$t9,$t5,$v1
/*  f14e464:	1420ffc1 */ 	bnez	$at,.L0f14e36c
/*  f14e468:	a3330000 */ 	sb	$s3,0x0($t9)
.L0f14e46c:
/*  f14e46c:	4618a03c */ 	c.lt.s	$f20,$f24
/*  f14e470:	00000000 */ 	nop
/*  f14e474:	4501ffa9 */ 	bc1t	.L0f14e31c
/*  f14e478:	00000000 */ 	nop
/*  f14e47c:	8fbf004c */ 	lw	$ra,0x4c($sp)
.L0f14e480:
/*  f14e480:	d7b40010 */ 	ldc1	$f20,0x10($sp)
/*  f14e484:	d7b60018 */ 	ldc1	$f22,0x18($sp)
/*  f14e488:	d7b80020 */ 	ldc1	$f24,0x20($sp)
/*  f14e48c:	d7ba0028 */ 	ldc1	$f26,0x28($sp)
/*  f14e490:	d7bc0030 */ 	ldc1	$f28,0x30($sp)
/*  f14e494:	8fb0003c */ 	lw	$s0,0x3c($sp)
/*  f14e498:	8fb10040 */ 	lw	$s1,0x40($sp)
/*  f14e49c:	8fb20044 */ 	lw	$s2,0x44($sp)
/*  f14e4a0:	8fb30048 */ 	lw	$s3,0x48($sp)
/*  f14e4a4:	03e00008 */ 	jr	$ra
/*  f14e4a8:	27bd00c0 */ 	addiu	$sp,$sp,0xc0
);

GLOBAL_ASM(
glabel func0f14e4ac
/*  f14e4ac:	27bdff58 */ 	addiu	$sp,$sp,-168
/*  f14e4b0:	afbf002c */ 	sw	$ra,0x2c($sp)
/*  f14e4b4:	afa400a8 */ 	sw	$a0,0xa8($sp)
/*  f14e4b8:	afb40028 */ 	sw	$s4,0x28($sp)
/*  f14e4bc:	afb30024 */ 	sw	$s3,0x24($sp)
/*  f14e4c0:	afb20020 */ 	sw	$s2,0x20($sp)
/*  f14e4c4:	afb1001c */ 	sw	$s1,0x1c($sp)
/*  f14e4c8:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f14e4cc:	afa500ac */ 	sw	$a1,0xac($sp)
/*  f14e4d0:	afa600b0 */ 	sw	$a2,0xb0($sp)
/*  f14e4d4:	0fc5281b */ 	jal	func0f14a06c
/*  f14e4d8:	2404ffff */ 	addiu	$a0,$zero,-1
/*  f14e4dc:	27a40098 */ 	addiu	$a0,$sp,0x98
/*  f14e4e0:	27a50094 */ 	addiu	$a1,$sp,0x94
/*  f14e4e4:	27a60090 */ 	addiu	$a2,$sp,0x90
/*  f14e4e8:	27a7008c */ 	addiu	$a3,$sp,0x8c
/*  f14e4ec:	0fc53b36 */ 	jal	func0f14ecd8
/*  f14e4f0:	afa200a4 */ 	sw	$v0,0xa4($sp)
/*  f14e4f4:	8fa700ac */ 	lw	$a3,0xac($sp)
/*  f14e4f8:	44807000 */ 	mtc1	$zero,$f14
/*  f14e4fc:	8fad00a4 */ 	lw	$t5,0xa4($sp)
/*  f14e500:	10e00002 */ 	beqz	$a3,.L0f14e50c
/*  f14e504:	00005825 */ 	or	$t3,$zero,$zero
/*  f14e508:	ace00000 */ 	sw	$zero,0x0($a3)
.L0f14e50c:
/*  f14e50c:	8fa600b0 */ 	lw	$a2,0xb0($sp)
/*  f14e510:	00004025 */ 	or	$t0,$zero,$zero
/*  f14e514:	00004825 */ 	or	$t1,$zero,$zero
/*  f14e518:	10c00002 */ 	beqz	$a2,.L0f14e524
/*  f14e51c:	46007086 */ 	mov.s	$f2,$f14
/*  f14e520:	acc00000 */ 	sw	$zero,0x0($a2)
.L0f14e524:
/*  f14e524:	8fa40090 */ 	lw	$a0,0x90($sp)
/*  f14e528:	8fa50098 */ 	lw	$a1,0x98($sp)
/*  f14e52c:	46007306 */ 	mov.s	$f12,$f14
/*  f14e530:	00851823 */ 	subu	$v1,$a0,$a1
/*  f14e534:	28610020 */ 	slti	$at,$v1,0x20
/*  f14e538:	10200009 */ 	beqz	$at,.L0f14e560
/*  f14e53c:	00857821 */ 	addu	$t7,$a0,$a1
/*  f14e540:	00851021 */ 	addu	$v0,$a0,$a1
/*  f14e544:	00027043 */ 	sra	$t6,$v0,0x1
/*  f14e548:	25d3fff0 */ 	addiu	$s3,$t6,-16
/*  f14e54c:	06610002 */ 	bgez	$s3,.L0f14e558
/*  f14e550:	00000000 */ 	nop
/*  f14e554:	00009825 */ 	or	$s3,$zero,$zero
.L0f14e558:
/*  f14e558:	10000005 */ 	b	.L0f14e570
/*  f14e55c:	26740020 */ 	addiu	$s4,$s3,0x20
.L0f14e560:
/*  f14e560:	000fc043 */ 	sra	$t8,$t7,0x1
/*  f14e564:	0003c843 */ 	sra	$t9,$v1,0x1
/*  f14e568:	03199823 */ 	subu	$s3,$t8,$t9
/*  f14e56c:	0263a021 */ 	addu	$s4,$s3,$v1
.L0f14e570:
/*  f14e570:	8fa4008c */ 	lw	$a0,0x8c($sp)
/*  f14e574:	8fa50094 */ 	lw	$a1,0x94($sp)
/*  f14e578:	02938823 */ 	subu	$s1,$s4,$s3
/*  f14e57c:	00851823 */ 	subu	$v1,$a0,$a1
/*  f14e580:	28610020 */ 	slti	$at,$v1,0x20
/*  f14e584:	10200009 */ 	beqz	$at,.L0f14e5ac
/*  f14e588:	00857821 */ 	addu	$t7,$a0,$a1
/*  f14e58c:	00851021 */ 	addu	$v0,$a0,$a1
/*  f14e590:	00027043 */ 	sra	$t6,$v0,0x1
/*  f14e594:	25d0fff0 */ 	addiu	$s0,$t6,-16
/*  f14e598:	06010002 */ 	bgez	$s0,.L0f14e5a4
/*  f14e59c:	00000000 */ 	nop
/*  f14e5a0:	00008025 */ 	or	$s0,$zero,$zero
.L0f14e5a4:
/*  f14e5a4:	10000005 */ 	b	.L0f14e5bc
/*  f14e5a8:	261f0020 */ 	addiu	$ra,$s0,0x20
.L0f14e5ac:
/*  f14e5ac:	000fc043 */ 	sra	$t8,$t7,0x1
/*  f14e5b0:	0003c843 */ 	sra	$t9,$v1,0x1
/*  f14e5b4:	03198023 */ 	subu	$s0,$t8,$t9
/*  f14e5b8:	0203f821 */ 	addu	$ra,$s0,$v1
.L0f14e5bc:
/*  f14e5bc:	03f01023 */ 	subu	$v0,$ra,$s0
/*  f14e5c0:	00117043 */ 	sra	$t6,$s1,0x1
/*  f14e5c4:	00029043 */ 	sra	$s2,$v0,0x1
/*  f14e5c8:	01c08825 */ 	or	$s1,$t6,$zero
/*  f14e5cc:	1a40003e */ 	blez	$s2,.L0f14e6c8
/*  f14e5d0:	01c05025 */ 	or	$t2,$t6,$zero
/*  f14e5d4:	25ccfff0 */ 	addiu	$t4,$t6,-16
.L0f14e5d8:
/*  f14e5d8:	05810002 */ 	bgez	$t4,.L0f14e5e4
/*  f14e5dc:	01801825 */ 	or	$v1,$t4,$zero
/*  f14e5e0:	00001825 */ 	or	$v1,$zero,$zero
.L0f14e5e4:
/*  f14e5e4:	0071082a */ 	slt	$at,$v1,$s1
/*  f14e5e8:	10200033 */ 	beqz	$at,.L0f14e6b8
/*  f14e5ec:	00601025 */ 	or	$v0,$v1,$zero
/*  f14e5f0:	02741821 */ 	addu	$v1,$s3,$s4
/*  f14e5f4:	021f2021 */ 	addu	$a0,$s0,$ra
/*  f14e5f8:	8dae001c */ 	lw	$t6,0x1c($t5)
/*  f14e5fc:	0004c843 */ 	sra	$t9,$a0,0x1
/*  f14e600:	0003c043 */ 	sra	$t8,$v1,0x1
/*  f14e604:	03001825 */ 	or	$v1,$t8,$zero
/*  f14e608:	032b7823 */ 	subu	$t7,$t9,$t3
/*  f14e60c:	000fc180 */ 	sll	$t8,$t7,0x6
/*  f14e610:	03202025 */ 	or	$a0,$t9,$zero
/*  f14e614:	01d8c821 */ 	addu	$t9,$t6,$t8
/*  f14e618:	01c07825 */ 	or	$t7,$t6,$zero
/*  f14e61c:	008b7021 */ 	addu	$t6,$a0,$t3
/*  f14e620:	000ec180 */ 	sll	$t8,$t6,0x6
/*  f14e624:	03233021 */ 	addu	$a2,$t9,$v1
/*  f14e628:	01f8c821 */ 	addu	$t9,$t7,$t8
/*  f14e62c:	03233821 */ 	addu	$a3,$t9,$v1
/*  f14e630:	00c27023 */ 	subu	$t6,$a2,$v0
.L0f14e634:
/*  f14e634:	91c30000 */ 	lbu	$v1,0x0($t6)
/*  f14e638:	00e27821 */ 	addu	$t7,$a3,$v0
/*  f14e63c:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f14e640:	28610015 */ 	slti	$at,$v1,0x15
/*  f14e644:	1420001a */ 	bnez	$at,.L0f14e6b0
/*  f14e648:	91e40000 */ 	lbu	$a0,0x0($t7)
/*  f14e64c:	286100c8 */ 	slti	$at,$v1,0xc8
/*  f14e650:	10200017 */ 	beqz	$at,.L0f14e6b0
/*  f14e654:	28810015 */ 	slti	$at,$a0,0x15
/*  f14e658:	14200015 */ 	bnez	$at,.L0f14e6b0
/*  f14e65c:	288100c8 */ 	slti	$at,$a0,0xc8
/*  f14e660:	10200013 */ 	beqz	$at,.L0f14e6b0
/*  f14e664:	00000000 */ 	nop
/*  f14e668:	44832000 */ 	mtc1	$v1,$f4
/*  f14e66c:	44845000 */ 	mtc1	$a0,$f10
/*  f14e670:	04610005 */ 	bgez	$v1,.L0f14e688
/*  f14e674:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f14e678:	3c014f80 */ 	lui	$at,0x4f80
/*  f14e67c:	44814000 */ 	mtc1	$at,$f8
/*  f14e680:	00000000 */ 	nop
/*  f14e684:	46083180 */ 	add.s	$f6,$f6,$f8
.L0f14e688:
/*  f14e688:	46061080 */ 	add.s	$f2,$f2,$f6
/*  f14e68c:	25080001 */ 	addiu	$t0,$t0,0x1
/*  f14e690:	04810005 */ 	bgez	$a0,.L0f14e6a8
/*  f14e694:	46805420 */ 	cvt.s.w	$f16,$f10
/*  f14e698:	3c014f80 */ 	lui	$at,0x4f80
/*  f14e69c:	44819000 */ 	mtc1	$at,$f18
/*  f14e6a0:	00000000 */ 	nop
/*  f14e6a4:	46128400 */ 	add.s	$f16,$f16,$f18
.L0f14e6a8:
/*  f14e6a8:	46106300 */ 	add.s	$f12,$f12,$f16
/*  f14e6ac:	25290001 */ 	addiu	$t1,$t1,0x1
.L0f14e6b0:
/*  f14e6b0:	544affe0 */ 	bnel	$v0,$t2,.L0f14e634
/*  f14e6b4:	00c27023 */ 	subu	$t6,$a2,$v0
.L0f14e6b8:
/*  f14e6b8:	256b0001 */ 	addiu	$t3,$t3,0x1
/*  f14e6bc:	0172082a */ 	slt	$at,$t3,$s2
/*  f14e6c0:	1420ffc5 */ 	bnez	$at,.L0f14e5d8
/*  f14e6c4:	00000000 */ 	nop
.L0f14e6c8:
/*  f14e6c8:	51000029 */ 	beqzl	$t0,.L0f14e770
/*  f14e6cc:	46007006 */ 	mov.s	$f0,$f14
/*  f14e6d0:	51200027 */ 	beqzl	$t1,.L0f14e770
/*  f14e6d4:	46007006 */ 	mov.s	$f0,$f14
/*  f14e6d8:	44882000 */ 	mtc1	$t0,$f4
/*  f14e6dc:	44895000 */ 	mtc1	$t1,$f10
/*  f14e6e0:	3c013f80 */ 	lui	$at,0x3f80
/*  f14e6e4:	46802220 */ 	cvt.s.w	$f8,$f4
/*  f14e6e8:	44810000 */ 	mtc1	$at,$f0
/*  f14e6ec:	8fb800ac */ 	lw	$t8,0xac($sp)
/*  f14e6f0:	0274c821 */ 	addu	$t9,$s3,$s4
/*  f14e6f4:	00197043 */ 	sra	$t6,$t9,0x1
/*  f14e6f8:	468054a0 */ 	cvt.s.w	$f18,$f10
/*  f14e6fc:	3c013f00 */ 	lui	$at,0x3f00
/*  f14e700:	46080183 */ 	div.s	$f6,$f0,$f8
/*  f14e704:	46120403 */ 	div.s	$f16,$f0,$f18
/*  f14e708:	46061082 */ 	mul.s	$f2,$f2,$f6
/*  f14e70c:	00000000 */ 	nop
/*  f14e710:	46106302 */ 	mul.s	$f12,$f12,$f16
/*  f14e714:	13000002 */ 	beqz	$t8,.L0f14e720
/*  f14e718:	00000000 */ 	nop
/*  f14e71c:	af0e0000 */ 	sw	$t6,0x0($t8)
.L0f14e720:
/*  f14e720:	460c1100 */ 	add.s	$f4,$f2,$f12
/*  f14e724:	44814000 */ 	mtc1	$at,$f8
/*  f14e728:	8faf00b0 */ 	lw	$t7,0xb0($sp)
/*  f14e72c:	46082182 */ 	mul.s	$f6,$f4,$f8
/*  f14e730:	51e00003 */ 	beqzl	$t7,.L0f14e740
/*  f14e734:	46023001 */ 	sub.s	$f0,$f6,$f2
/*  f14e738:	adf10000 */ 	sw	$s1,0x0($t7)
/*  f14e73c:	46023001 */ 	sub.s	$f0,$f6,$f2
.L0f14e740:
/*  f14e740:	8faf00a8 */ 	lw	$t7,0xa8($sp)
/*  f14e744:	3c188008 */ 	lui	$t8,%hi(var8007f8dc)
/*  f14e748:	8f18f8dc */ 	lw	$t8,%lo(var8007f8dc)($t8)
/*  f14e74c:	4600028d */ 	trunc.w.s	$f10,$f0
/*  f14e750:	000fc980 */ 	sll	$t9,$t7,0x6
/*  f14e754:	032fc821 */ 	addu	$t9,$t9,$t7
/*  f14e758:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f14e75c:	440e5000 */ 	mfc1	$t6,$f10
/*  f14e760:	03197821 */ 	addu	$t7,$t8,$t9
/*  f14e764:	10000002 */ 	b	.L0f14e770
/*  f14e768:	adee0090 */ 	sw	$t6,0x90($t7)
/*  f14e76c:	46007006 */ 	mov.s	$f0,$f14
.L0f14e770:
/*  f14e770:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*  f14e774:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f14e778:	8fb1001c */ 	lw	$s1,0x1c($sp)
/*  f14e77c:	8fb20020 */ 	lw	$s2,0x20($sp)
/*  f14e780:	8fb30024 */ 	lw	$s3,0x24($sp)
/*  f14e784:	8fb40028 */ 	lw	$s4,0x28($sp)
/*  f14e788:	03e00008 */ 	jr	$ra
/*  f14e78c:	27bd00a8 */ 	addiu	$sp,$sp,0xa8
);

void func0f14e790(u8 *arg0)
{
	s32 i;
	s32 j;

	for (i = 0; i < 128; i++) {
		for (j = 0; j < 128; j++) {
			arg0[i * 128 + j] = j / 16 * 32;
		}
	}
}

void func0f14e7e0(u8 *arg0)
{
	s32 i;
	s32 j;

	for (i = 0; i < 128; i++) {
		for (j = 0; j < 128; j++) {
			arg0[i * 128 + j] = random() % 255;
		}
	}
}

GLOBAL_ASM(
glabel func0f14e884
/*  f14e884:	27bdffa0 */ 	addiu	$sp,$sp,-96
/*  f14e888:	afbf001c */ 	sw	$ra,0x1c($sp)
/*  f14e88c:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f14e890:	90820008 */ 	lbu	$v0,0x8($a0)
/*  f14e894:	00808025 */ 	or	$s0,$a0,$zero
/*  f14e898:	5040000d */ 	beqzl	$v0,.L0f14e8d0
/*  f14e89c:	240e0010 */ 	addiu	$t6,$zero,0x10
/*  f14e8a0:	24010001 */ 	addiu	$at,$zero,0x1
/*  f14e8a4:	5041001a */ 	beql	$v0,$at,.L0f14e910
/*  f14e8a8:	240b0008 */ 	addiu	$t3,$zero,0x8
/*  f14e8ac:	24010002 */ 	addiu	$at,$zero,0x2
/*  f14e8b0:	50410025 */ 	beql	$v0,$at,.L0f14e948
/*  f14e8b4:	24190004 */ 	addiu	$t9,$zero,0x4
/*  f14e8b8:	24010003 */ 	addiu	$at,$zero,0x3
/*  f14e8bc:	50410032 */ 	beql	$v0,$at,.L0f14e988
/*  f14e8c0:	240d0002 */ 	addiu	$t5,$zero,0x2
/*  f14e8c4:	1000003e */ 	b	.L0f14e9c0
/*  f14e8c8:	8fa20054 */ 	lw	$v0,0x54($sp)
/*  f14e8cc:	240e0010 */ 	addiu	$t6,$zero,0x10
.L0f14e8d0:
/*  f14e8d0:	24180000 */ 	addiu	$t8,$zero,0x0
/*  f14e8d4:	2419000f */ 	addiu	$t9,$zero,0xf
/*  f14e8d8:	00067843 */ 	sra	$t7,$a2,0x1
/*  f14e8dc:	afae004c */ 	sw	$t6,0x4c($sp)
/*  f14e8e0:	afb9003c */ 	sw	$t9,0x3c($sp)
/*  f14e8e4:	afb80038 */ 	sw	$t8,0x38($sp)
/*  f14e8e8:	afaf005c */ 	sw	$t7,0x5c($sp)
/*  f14e8ec:	92080004 */ 	lbu	$t0,0x4($s0)
/*  f14e8f0:	24020004 */ 	addiu	$v0,$zero,0x4
/*  f14e8f4:	00084843 */ 	sra	$t1,$t0,0x1
/*  f14e8f8:	01250019 */ 	multu	$t1,$a1
/*  f14e8fc:	00005012 */ 	mflo	$t2
/*  f14e900:	afaa0058 */ 	sw	$t2,0x58($sp)
/*  f14e904:	1000002f */ 	b	.L0f14e9c4
/*  f14e908:	8faa004c */ 	lw	$t2,0x4c($sp)
/*  f14e90c:	240b0008 */ 	addiu	$t3,$zero,0x8
.L0f14e910:
/*  f14e910:	240c0000 */ 	addiu	$t4,$zero,0x0
/*  f14e914:	240d00ff */ 	addiu	$t5,$zero,0xff
/*  f14e918:	afab004c */ 	sw	$t3,0x4c($sp)
/*  f14e91c:	afad003c */ 	sw	$t5,0x3c($sp)
/*  f14e920:	afac0038 */ 	sw	$t4,0x38($sp)
/*  f14e924:	afa6005c */ 	sw	$a2,0x5c($sp)
/*  f14e928:	920e0004 */ 	lbu	$t6,0x4($s0)
/*  f14e92c:	24020008 */ 	addiu	$v0,$zero,0x8
/*  f14e930:	01c50019 */ 	multu	$t6,$a1
/*  f14e934:	0000c012 */ 	mflo	$t8
/*  f14e938:	afb80058 */ 	sw	$t8,0x58($sp)
/*  f14e93c:	10000021 */ 	b	.L0f14e9c4
/*  f14e940:	8faa004c */ 	lw	$t2,0x4c($sp)
/*  f14e944:	24190004 */ 	addiu	$t9,$zero,0x4
.L0f14e948:
/*  f14e948:	24080000 */ 	addiu	$t0,$zero,0x0
/*  f14e94c:	3409ffff */ 	dli	$t1,0xffff
/*  f14e950:	00067840 */ 	sll	$t7,$a2,0x1
/*  f14e954:	afb9004c */ 	sw	$t9,0x4c($sp)
/*  f14e958:	afa9003c */ 	sw	$t1,0x3c($sp)
/*  f14e95c:	afa80038 */ 	sw	$t0,0x38($sp)
/*  f14e960:	afaf005c */ 	sw	$t7,0x5c($sp)
/*  f14e964:	920a0004 */ 	lbu	$t2,0x4($s0)
/*  f14e968:	24020010 */ 	addiu	$v0,$zero,0x10
/*  f14e96c:	000a5840 */ 	sll	$t3,$t2,0x1
/*  f14e970:	01650019 */ 	multu	$t3,$a1
/*  f14e974:	00006012 */ 	mflo	$t4
/*  f14e978:	afac0058 */ 	sw	$t4,0x58($sp)
/*  f14e97c:	10000011 */ 	b	.L0f14e9c4
/*  f14e980:	8faa004c */ 	lw	$t2,0x4c($sp)
/*  f14e984:	240d0002 */ 	addiu	$t5,$zero,0x2
.L0f14e988:
/*  f14e988:	240e0000 */ 	addiu	$t6,$zero,0x0
/*  f14e98c:	240fffff */ 	addiu	$t7,$zero,-1
/*  f14e990:	0006c080 */ 	sll	$t8,$a2,0x2
/*  f14e994:	afad004c */ 	sw	$t5,0x4c($sp)
/*  f14e998:	afaf003c */ 	sw	$t7,0x3c($sp)
/*  f14e99c:	afae0038 */ 	sw	$t6,0x38($sp)
/*  f14e9a0:	afb8005c */ 	sw	$t8,0x5c($sp)
/*  f14e9a4:	92190004 */ 	lbu	$t9,0x4($s0)
/*  f14e9a8:	24020020 */ 	addiu	$v0,$zero,0x20
/*  f14e9ac:	00194080 */ 	sll	$t0,$t9,0x2
/*  f14e9b0:	01050019 */ 	multu	$t0,$a1
/*  f14e9b4:	00004812 */ 	mflo	$t1
/*  f14e9b8:	afa90058 */ 	sw	$t1,0x58($sp)
/*  f14e9bc:	00000000 */ 	nop
.L0f14e9c0:
/*  f14e9c0:	8faa004c */ 	lw	$t2,0x4c($sp)
.L0f14e9c4:
/*  f14e9c4:	24190040 */ 	addiu	$t9,$zero,0x40
/*  f14e9c8:	24180000 */ 	addiu	$t8,$zero,0x0
/*  f14e9cc:	00ca001a */ 	div	$zero,$a2,$t2
/*  f14e9d0:	00005810 */ 	mfhi	$t3
/*  f14e9d4:	afa00020 */ 	sw	$zero,0x20($sp)
/*  f14e9d8:	15400002 */ 	bnez	$t2,.L0f14e9e4
/*  f14e9dc:	00000000 */ 	nop
/*  f14e9e0:	0007000d */ 	break	0x7
.L0f14e9e4:
/*  f14e9e4:	2401ffff */ 	addiu	$at,$zero,-1
/*  f14e9e8:	15410004 */ 	bne	$t2,$at,.L0f14e9fc
/*  f14e9ec:	3c018000 */ 	lui	$at,0x8000
/*  f14e9f0:	14c10002 */ 	bne	$a2,$at,.L0f14e9fc
/*  f14e9f4:	00000000 */ 	nop
/*  f14e9f8:	0006000d */ 	break	0x6
.L0f14e9fc:
/*  f14e9fc:	01620019 */ 	multu	$t3,$v0
/*  f14ea00:	000257c3 */ 	sra	$t2,$v0,0x1f
/*  f14ea04:	00405825 */ 	or	$t3,$v0,$zero
/*  f14ea08:	afa00040 */ 	sw	$zero,0x40($sp)
/*  f14ea0c:	00006012 */ 	mflo	$t4
/*  f14ea10:	000c77c3 */ 	sra	$t6,$t4,0x1f
/*  f14ea14:	032c082b */ 	sltu	$at,$t9,$t4
/*  f14ea18:	032c4823 */ 	subu	$t1,$t9,$t4
/*  f14ea1c:	030e4023 */ 	subu	$t0,$t8,$t6
/*  f14ea20:	01014023 */ 	subu	$t0,$t0,$at
/*  f14ea24:	01226823 */ 	subu	$t5,$t1,$v0
/*  f14ea28:	01807825 */ 	or	$t7,$t4,$zero
/*  f14ea2c:	010a6023 */ 	subu	$t4,$t0,$t2
/*  f14ea30:	31b9003f */ 	andi	$t9,$t5,0x3f
/*  f14ea34:	0122082b */ 	sltu	$at,$t1,$v0
/*  f14ea38:	30ae0001 */ 	andi	$t6,$a1,0x1
/*  f14ea3c:	01816023 */ 	subu	$t4,$t4,$at
/*  f14ea40:	afb90024 */ 	sw	$t9,0x24($sp)
/*  f14ea44:	afb90044 */ 	sw	$t9,0x44($sp)
/*  f14ea48:	11c00005 */ 	beqz	$t6,.L0f14ea60
/*  f14ea4c:	0000c025 */ 	or	$t8,$zero,$zero
/*  f14ea50:	27290020 */ 	addiu	$t1,$t9,0x20
/*  f14ea54:	312b003f */ 	andi	$t3,$t1,0x3f
/*  f14ea58:	afab0044 */ 	sw	$t3,0x44($sp)
/*  f14ea5c:	afa00040 */ 	sw	$zero,0x40($sp)
.L0f14ea60:
/*  f14ea60:	8faf005c */ 	lw	$t7,0x5c($sp)
/*  f14ea64:	8fad0058 */ 	lw	$t5,0x58($sp)
/*  f14ea68:	8e080000 */ 	lw	$t0,0x0($s0)
/*  f14ea6c:	000f60c3 */ 	sra	$t4,$t7,0x3
/*  f14ea70:	000d70c3 */ 	sra	$t6,$t5,0x3
/*  f14ea74:	018ec021 */ 	addu	$t8,$t4,$t6
/*  f14ea78:	0018c8c0 */ 	sll	$t9,$t8,0x3
/*  f14ea7c:	01194821 */ 	addu	$t1,$t0,$t9
/*  f14ea80:	afa90034 */ 	sw	$t1,0x34($sp)
/*  f14ea84:	8fa40038 */ 	lw	$a0,0x38($sp)
/*  f14ea88:	8fa5003c */ 	lw	$a1,0x3c($sp)
/*  f14ea8c:	8fa60040 */ 	lw	$a2,0x40($sp)
/*  f14ea90:	0c012ba9 */ 	jal	__ll_lshift
/*  f14ea94:	8fa70044 */ 	lw	$a3,0x44($sp)
/*  f14ea98:	8fb00034 */ 	lw	$s0,0x34($sp)
/*  f14ea9c:	afa20028 */ 	sw	$v0,0x28($sp)
/*  f14eaa0:	afa3002c */ 	sw	$v1,0x2c($sp)
/*  f14eaa4:	8fa40070 */ 	lw	$a0,0x70($sp)
/*  f14eaa8:	8fa50074 */ 	lw	$a1,0x74($sp)
/*  f14eaac:	8fa60040 */ 	lw	$a2,0x40($sp)
/*  f14eab0:	0c012ba9 */ 	jal	__ll_lshift
/*  f14eab4:	8fa70044 */ 	lw	$a3,0x44($sp)
/*  f14eab8:	8fad002c */ 	lw	$t5,0x2c($sp)
/*  f14eabc:	8e0b0004 */ 	lw	$t3,0x4($s0)
/*  f14eac0:	8fac0028 */ 	lw	$t4,0x28($sp)
/*  f14eac4:	01a07827 */ 	nor	$t7,$t5,$zero
/*  f14eac8:	8e0a0000 */ 	lw	$t2,0x0($s0)
/*  f14eacc:	016fc824 */ 	and	$t9,$t3,$t7
/*  f14ead0:	00794821 */ 	addu	$t1,$v1,$t9
/*  f14ead4:	0139082b */ 	sltu	$at,$t1,$t9
/*  f14ead8:	01807027 */ 	nor	$t6,$t4,$zero
/*  f14eadc:	00224021 */ 	addu	$t0,$at,$v0
/*  f14eae0:	014ec024 */ 	and	$t8,$t2,$t6
/*  f14eae4:	01184021 */ 	addu	$t0,$t0,$t8
/*  f14eae8:	ae080000 */ 	sw	$t0,0x0($s0)
/*  f14eaec:	ae090004 */ 	sw	$t1,0x4($s0)
/*  f14eaf0:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f14eaf4:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f14eaf8:	27bd0060 */ 	addiu	$sp,$sp,0x60
/*  f14eafc:	03e00008 */ 	jr	$ra
/*  f14eb00:	00000000 */ 	nop
/*  f14eb04:	44862000 */ 	mtc1	$a2,$f4
/*  f14eb08:	44874000 */ 	mtc1	$a3,$f8
/*  f14eb0c:	27bdffc8 */ 	addiu	$sp,$sp,-56
/*  f14eb10:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f14eb14:	afbf001c */ 	sw	$ra,0x1c($sp)
/*  f14eb18:	afa40038 */ 	sw	$a0,0x38($sp)
/*  f14eb1c:	afa60040 */ 	sw	$a2,0x40($sp)
/*  f14eb20:	afa70044 */ 	sw	$a3,0x44($sp)
/*  f14eb24:	468042a0 */ 	cvt.s.w	$f10,$f8
/*  f14eb28:	e7a60030 */ 	swc1	$f6,0x30($sp)
/*  f14eb2c:	00a02025 */ 	or	$a0,$a1,$zero
/*  f14eb30:	0fc5281b */ 	jal	func0f14a06c
/*  f14eb34:	e7aa0034 */ 	swc1	$f10,0x34($sp)
/*  f14eb38:	8fb80048 */ 	lw	$t8,0x48($sp)
/*  f14eb3c:	8fb90040 */ 	lw	$t9,0x40($sp)
/*  f14eb40:	8fa9004c */ 	lw	$t1,0x4c($sp)
/*  f14eb44:	8faa0044 */ 	lw	$t2,0x44($sp)
/*  f14eb48:	03194023 */ 	subu	$t0,$t8,$t9
/*  f14eb4c:	44888000 */ 	mtc1	$t0,$f16
/*  f14eb50:	012a5823 */ 	subu	$t3,$t1,$t2
/*  f14eb54:	448b3000 */ 	mtc1	$t3,$f6
/*  f14eb58:	468084a0 */ 	cvt.s.w	$f18,$f16
/*  f14eb5c:	3c013c80 */ 	lui	$at,0x3c80
/*  f14eb60:	44810000 */ 	mtc1	$at,$f0
/*  f14eb64:	8fa40038 */ 	lw	$a0,0x38($sp)
/*  f14eb68:	24450004 */ 	addiu	$a1,$v0,0x4
/*  f14eb6c:	46803220 */ 	cvt.s.w	$f8,$f6
/*  f14eb70:	46009102 */ 	mul.s	$f4,$f18,$f0
/*  f14eb74:	27a60030 */ 	addiu	$a2,$sp,0x30
/*  f14eb78:	46004282 */ 	mul.s	$f10,$f8,$f0
/*  f14eb7c:	44072000 */ 	mfc1	$a3,$f4
/*  f14eb80:	0fc5321c */ 	jal	func0f14c870
/*  f14eb84:	e7aa0010 */ 	swc1	$f10,0x10($sp)
/*  f14eb88:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f14eb8c:	27bd0038 */ 	addiu	$sp,$sp,0x38
/*  f14eb90:	03e00008 */ 	jr	$ra
/*  f14eb94:	00000000 */ 	nop
/*  f14eb98:	44862000 */ 	mtc1	$a2,$f4
/*  f14eb9c:	44874000 */ 	mtc1	$a3,$f8
/*  f14eba0:	27bdffc8 */ 	addiu	$sp,$sp,-56
/*  f14eba4:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f14eba8:	afbf001c */ 	sw	$ra,0x1c($sp)
/*  f14ebac:	afa40038 */ 	sw	$a0,0x38($sp)
/*  f14ebb0:	afa60040 */ 	sw	$a2,0x40($sp)
/*  f14ebb4:	afa70044 */ 	sw	$a3,0x44($sp)
/*  f14ebb8:	468042a0 */ 	cvt.s.w	$f10,$f8
/*  f14ebbc:	e7a60030 */ 	swc1	$f6,0x30($sp)
/*  f14ebc0:	00a02025 */ 	or	$a0,$a1,$zero
/*  f14ebc4:	0fc5281b */ 	jal	func0f14a06c
/*  f14ebc8:	e7aa0034 */ 	swc1	$f10,0x34($sp)
/*  f14ebcc:	8fb80048 */ 	lw	$t8,0x48($sp)
/*  f14ebd0:	8fb90040 */ 	lw	$t9,0x40($sp)
/*  f14ebd4:	8fa9004c */ 	lw	$t1,0x4c($sp)
/*  f14ebd8:	8faa0044 */ 	lw	$t2,0x44($sp)
/*  f14ebdc:	03194023 */ 	subu	$t0,$t8,$t9
/*  f14ebe0:	44888000 */ 	mtc1	$t0,$f16
/*  f14ebe4:	012a5823 */ 	subu	$t3,$t1,$t2
/*  f14ebe8:	448b3000 */ 	mtc1	$t3,$f6
/*  f14ebec:	468084a0 */ 	cvt.s.w	$f18,$f16
/*  f14ebf0:	3c013d80 */ 	lui	$at,0x3d80
/*  f14ebf4:	44810000 */ 	mtc1	$at,$f0
/*  f14ebf8:	8fa40038 */ 	lw	$a0,0x38($sp)
/*  f14ebfc:	24450010 */ 	addiu	$a1,$v0,0x10
/*  f14ec00:	46803220 */ 	cvt.s.w	$f8,$f6
/*  f14ec04:	46009102 */ 	mul.s	$f4,$f18,$f0
/*  f14ec08:	27a60030 */ 	addiu	$a2,$sp,0x30
/*  f14ec0c:	46004282 */ 	mul.s	$f10,$f8,$f0
/*  f14ec10:	44072000 */ 	mfc1	$a3,$f4
/*  f14ec14:	0fc5321c */ 	jal	func0f14c870
/*  f14ec18:	e7aa0010 */ 	swc1	$f10,0x10($sp)
/*  f14ec1c:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f14ec20:	27bd0038 */ 	addiu	$sp,$sp,0x38
/*  f14ec24:	03e00008 */ 	jr	$ra
/*  f14ec28:	00000000 */ 	nop
);

const char var7f1b6d44[] = "camdraw.c";
const char var7f1b6d50[] = "Cam_SetSquashZ : %u, %u, %f\n";

GLOBAL_ASM(
glabel func0f14ec2c
/*  f14ec2c:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*  f14ec30:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f14ec34:	afa40020 */ 	sw	$a0,0x20($sp)
/*  f14ec38:	afa50024 */ 	sw	$a1,0x24($sp)
/*  f14ec3c:	afa60028 */ 	sw	$a2,0x28($sp)
/*  f14ec40:	afa7002c */ 	sw	$a3,0x2c($sp)
/*  f14ec44:	0fc5281b */ 	jal	func0f14a06c
/*  f14ec48:	2404ffff */ 	addiu	$a0,$zero,-1
/*  f14ec4c:	2404fffe */ 	addiu	$a0,$zero,-2
/*  f14ec50:	0fc5281b */ 	jal	func0f14a06c
/*  f14ec54:	afa2001c */ 	sw	$v0,0x1c($sp)
/*  f14ec58:	8fa3001c */ 	lw	$v1,0x1c($sp)
/*  f14ec5c:	2404ffff */ 	addiu	$a0,$zero,-1
/*  f14ec60:	2405103f */ 	addiu	$a1,$zero,0x103f
/*  f14ec64:	1060000b */ 	beqz	$v1,.L0f14ec94
/*  f14ec68:	3c067f1b */ 	lui	$a2,%hi(var7f1b6d44)
/*  f14ec6c:	8fae0020 */ 	lw	$t6,0x20($sp)
/*  f14ec70:	ac6e03c0 */ 	sw	$t6,0x3c0($v1)
/*  f14ec74:	8faf0024 */ 	lw	$t7,0x24($sp)
/*  f14ec78:	ac6f03c8 */ 	sw	$t7,0x3c8($v1)
/*  f14ec7c:	8fb80028 */ 	lw	$t8,0x28($sp)
/*  f14ec80:	ac7803c4 */ 	sw	$t8,0x3c4($v1)
/*  f14ec84:	8fb9002c */ 	lw	$t9,0x2c($sp)
/*  f14ec88:	ac6003ec */ 	sw	$zero,0x3ec($v1)
/*  f14ec8c:	ac6003f0 */ 	sw	$zero,0x3f0($v1)
/*  f14ec90:	ac7903cc */ 	sw	$t9,0x3cc($v1)
.L0f14ec94:
/*  f14ec94:	1040000a */ 	beqz	$v0,.L0f14ecc0
/*  f14ec98:	8fa80020 */ 	lw	$t0,0x20($sp)
/*  f14ec9c:	ac4803c0 */ 	sw	$t0,0x3c0($v0)
/*  f14eca0:	8fa90024 */ 	lw	$t1,0x24($sp)
/*  f14eca4:	ac4903c8 */ 	sw	$t1,0x3c8($v0)
/*  f14eca8:	8faa0028 */ 	lw	$t2,0x28($sp)
/*  f14ecac:	ac4a03c4 */ 	sw	$t2,0x3c4($v0)
/*  f14ecb0:	8fab002c */ 	lw	$t3,0x2c($sp)
/*  f14ecb4:	ac4003ec */ 	sw	$zero,0x3ec($v0)
/*  f14ecb8:	ac4003f0 */ 	sw	$zero,0x3f0($v0)
/*  f14ecbc:	ac4b03cc */ 	sw	$t3,0x3cc($v0)
.L0f14ecc0:
/*  f14ecc0:	0fc537bc */ 	jal	func0f14def0
/*  f14ecc4:	24c66d44 */ 	addiu	$a2,$a2,%lo(var7f1b6d44)
/*  f14ecc8:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f14eccc:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*  f14ecd0:	03e00008 */ 	jr	$ra
/*  f14ecd4:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel func0f14ecd8
.late_rodata
glabel var7f1b7350
.word 0x3ff33333
glabel var7f1b7354
.word 0x3c23d70a
glabel var7f1b7358
.word 0x3dcccccd
glabel var7f1b735c
.word 0x3dcccccd
.text
/*  f14ecd8:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f14ecdc:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f14ece0:	afa40018 */ 	sw	$a0,0x18($sp)
/*  f14ece4:	afa5001c */ 	sw	$a1,0x1c($sp)
/*  f14ece8:	afa60020 */ 	sw	$a2,0x20($sp)
/*  f14ecec:	afa70024 */ 	sw	$a3,0x24($sp)
/*  f14ecf0:	0fc5281b */ 	jal	func0f14a06c
/*  f14ecf4:	2404fffe */ 	addiu	$a0,$zero,-2
/*  f14ecf8:	8c4e03c0 */ 	lw	$t6,0x3c0($v0)
/*  f14ecfc:	8faf0018 */ 	lw	$t7,0x18($sp)
/*  f14ed00:	adee0000 */ 	sw	$t6,0x0($t7)
/*  f14ed04:	8fb9001c */ 	lw	$t9,0x1c($sp)
/*  f14ed08:	8c5803c8 */ 	lw	$t8,0x3c8($v0)
/*  f14ed0c:	af380000 */ 	sw	$t8,0x0($t9)
/*  f14ed10:	8fa90020 */ 	lw	$t1,0x20($sp)
/*  f14ed14:	8c4803c4 */ 	lw	$t0,0x3c4($v0)
/*  f14ed18:	ad280000 */ 	sw	$t0,0x0($t1)
/*  f14ed1c:	8fab0024 */ 	lw	$t3,0x24($sp)
/*  f14ed20:	8c4a03cc */ 	lw	$t2,0x3cc($v0)
/*  f14ed24:	ad6a0000 */ 	sw	$t2,0x0($t3)
/*  f14ed28:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f14ed2c:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f14ed30:	03e00008 */ 	jr	$ra
/*  f14ed34:	00000000 */ 	nop
/*  f14ed38:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f14ed3c:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f14ed40:	2404000a */ 	addiu	$a0,$zero,0xa
/*  f14ed44:	24050003 */ 	addiu	$a1,$zero,0x3
/*  f14ed48:	24060036 */ 	addiu	$a2,$zero,0x36
/*  f14ed4c:	0fc53b0b */ 	jal	func0f14ec2c
/*  f14ed50:	2407003d */ 	addiu	$a3,$zero,0x3d
/*  f14ed54:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f14ed58:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f14ed5c:	03e00008 */ 	jr	$ra
/*  f14ed60:	00000000 */ 	nop
/*  f14ed64:	27bdffc8 */ 	addiu	$sp,$sp,-56
/*  f14ed68:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f14ed6c:	0fc53bd4 */ 	jal	func0f14ef50
/*  f14ed70:	27a4001c */ 	addiu	$a0,$sp,0x1c
/*  f14ed74:	3c0142c8 */ 	lui	$at,0x42c8
/*  f14ed78:	44813000 */ 	mtc1	$at,$f6
/*  f14ed7c:	c7a40034 */ 	lwc1	$f4,0x34($sp)
/*  f14ed80:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f14ed84:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f14ed88:	46062202 */ 	mul.s	$f8,$f4,$f6
/*  f14ed8c:	27bd0038 */ 	addiu	$sp,$sp,0x38
/*  f14ed90:	3c014f00 */ 	lui	$at,0x4f00
/*  f14ed94:	444ef800 */ 	cfc1	$t6,$31
/*  f14ed98:	44c2f800 */ 	ctc1	$v0,$31
/*  f14ed9c:	00000000 */ 	nop
/*  f14eda0:	460042a4 */ 	cvt.w.s	$f10,$f8
/*  f14eda4:	4442f800 */ 	cfc1	$v0,$31
/*  f14eda8:	00000000 */ 	nop
/*  f14edac:	30420078 */ 	andi	$v0,$v0,0x78
/*  f14edb0:	50400013 */ 	beqzl	$v0,.L0f14ee00
/*  f14edb4:	44025000 */ 	mfc1	$v0,$f10
/*  f14edb8:	44815000 */ 	mtc1	$at,$f10
/*  f14edbc:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f14edc0:	460a4281 */ 	sub.s	$f10,$f8,$f10
/*  f14edc4:	44c2f800 */ 	ctc1	$v0,$31
/*  f14edc8:	00000000 */ 	nop
/*  f14edcc:	460052a4 */ 	cvt.w.s	$f10,$f10
/*  f14edd0:	4442f800 */ 	cfc1	$v0,$31
/*  f14edd4:	00000000 */ 	nop
/*  f14edd8:	30420078 */ 	andi	$v0,$v0,0x78
/*  f14eddc:	14400005 */ 	bnez	$v0,.L0f14edf4
/*  f14ede0:	00000000 */ 	nop
/*  f14ede4:	44025000 */ 	mfc1	$v0,$f10
/*  f14ede8:	3c018000 */ 	lui	$at,0x8000
/*  f14edec:	10000007 */ 	b	.L0f14ee0c
/*  f14edf0:	00411025 */ 	or	$v0,$v0,$at
.L0f14edf4:
/*  f14edf4:	10000005 */ 	b	.L0f14ee0c
/*  f14edf8:	2402ffff */ 	addiu	$v0,$zero,-1
/*  f14edfc:	44025000 */ 	mfc1	$v0,$f10
.L0f14ee00:
/*  f14ee00:	00000000 */ 	nop
/*  f14ee04:	0440fffb */ 	bltz	$v0,.L0f14edf4
/*  f14ee08:	00000000 */ 	nop
.L0f14ee0c:
/*  f14ee0c:	44cef800 */ 	ctc1	$t6,$31
/*  f14ee10:	03e00008 */ 	jr	$ra
/*  f14ee14:	2442ffe7 */ 	addiu	$v0,$v0,-25
/*  f14ee18:	27bdffc8 */ 	addiu	$sp,$sp,-56
/*  f14ee1c:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f14ee20:	24850019 */ 	addiu	$a1,$a0,0x19
/*  f14ee24:	afa50038 */ 	sw	$a1,0x38($sp)
/*  f14ee28:	0fc53bd4 */ 	jal	func0f14ef50
/*  f14ee2c:	27a4001c */ 	addiu	$a0,$sp,0x1c
/*  f14ee30:	8fa50038 */ 	lw	$a1,0x38($sp)
/*  f14ee34:	3c017f1b */ 	lui	$at,%hi(var7f1b7350)
/*  f14ee38:	c4227350 */ 	lwc1	$f2,%lo(var7f1b7350)($at)
/*  f14ee3c:	44852000 */ 	mtc1	$a1,$f4
/*  f14ee40:	3c014f80 */ 	lui	$at,0x4f80
/*  f14ee44:	04a10004 */ 	bgez	$a1,.L0f14ee58
/*  f14ee48:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f14ee4c:	44814000 */ 	mtc1	$at,$f8
/*  f14ee50:	00000000 */ 	nop
/*  f14ee54:	46083180 */ 	add.s	$f6,$f6,$f8
.L0f14ee58:
/*  f14ee58:	3c017f1b */ 	lui	$at,%hi(var7f1b7354)
/*  f14ee5c:	c42a7354 */ 	lwc1	$f10,%lo(var7f1b7354)($at)
/*  f14ee60:	3c017f1b */ 	lui	$at,%hi(var7f1b7358)
/*  f14ee64:	460a3002 */ 	mul.s	$f0,$f6,$f10
/*  f14ee68:	4600103c */ 	c.lt.s	$f2,$f0
/*  f14ee6c:	00000000 */ 	nop
/*  f14ee70:	45000002 */ 	bc1f	.L0f14ee7c
/*  f14ee74:	00000000 */ 	nop
/*  f14ee78:	46001006 */ 	mov.s	$f0,$f2
.L0f14ee7c:
/*  f14ee7c:	c4227358 */ 	lwc1	$f2,%lo(var7f1b7358)($at)
/*  f14ee80:	e7a00034 */ 	swc1	$f0,0x34($sp)
/*  f14ee84:	4602003c */ 	c.lt.s	$f0,$f2
/*  f14ee88:	00000000 */ 	nop
/*  f14ee8c:	45000002 */ 	bc1f	.L0f14ee98
/*  f14ee90:	00000000 */ 	nop
/*  f14ee94:	e7a20034 */ 	swc1	$f2,0x34($sp)
.L0f14ee98:
/*  f14ee98:	0fc53bac */ 	jal	func0f14eeb0
/*  f14ee9c:	27a4001c */ 	addiu	$a0,$sp,0x1c
/*  f14eea0:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f14eea4:	27bd0038 */ 	addiu	$sp,$sp,0x38
/*  f14eea8:	03e00008 */ 	jr	$ra
/*  f14eeac:	00000000 */ 	nop
);

const char var7f1b6d70[] = "camdraw.c";
const char var7f1b6d7c[] = "Cam : Alloc for copy of Vtx %d bytes\n";
const char var7f1b6da4[] = "CAM : Cam_AllocAndCopyAllVtx -> Ptr all-ready allocted - No extra needed\n";

GLOBAL_ASM(
glabel func0f14eeb0
.late_rodata
glabel var7f1b7360
.word 0x3ff33333
.text
/*  f14eeb0:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*  f14eeb4:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f14eeb8:	afa40020 */ 	sw	$a0,0x20($sp)
/*  f14eebc:	0fc5281b */ 	jal	func0f14a06c
/*  f14eec0:	2404ffff */ 	addiu	$a0,$zero,-1
/*  f14eec4:	2404fffe */ 	addiu	$a0,$zero,-2
/*  f14eec8:	0fc5281b */ 	jal	func0f14a06c
/*  f14eecc:	afa2001c */ 	sw	$v0,0x1c($sp)
/*  f14eed0:	3c017f1b */ 	lui	$at,%hi(var7f1b7360)
/*  f14eed4:	8fa5001c */ 	lw	$a1,0x1c($sp)
/*  f14eed8:	c42c7360 */ 	lwc1	$f12,%lo(var7f1b7360)($at)
/*  f14eedc:	00001825 */ 	or	$v1,$zero,$zero
/*  f14eee0:	8fa40020 */ 	lw	$a0,0x20($sp)
/*  f14eee4:	2406001c */ 	addiu	$a2,$zero,0x1c
.L0f14eee8:
/*  f14eee8:	c4820000 */ 	lwc1	$f2,0x0($a0)
/*  f14eeec:	00a37021 */ 	addu	$t6,$a1,$v1
/*  f14eef0:	4602603c */ 	c.lt.s	$f12,$f2
/*  f14eef4:	00000000 */ 	nop
/*  f14eef8:	45000001 */ 	bc1f	.L0f14ef00
/*  f14eefc:	00000000 */ 	nop
.L0f14ef00:
/*  f14ef00:	10a00002 */ 	beqz	$a1,.L0f14ef0c
/*  f14ef04:	00000000 */ 	nop
/*  f14ef08:	e5c203d0 */ 	swc1	$f2,0x3d0($t6)
.L0f14ef0c:
/*  f14ef0c:	50400005 */ 	beqzl	$v0,.L0f14ef24
/*  f14ef10:	24630004 */ 	addiu	$v1,$v1,0x4
/*  f14ef14:	c4840000 */ 	lwc1	$f4,0x0($a0)
/*  f14ef18:	00437821 */ 	addu	$t7,$v0,$v1
/*  f14ef1c:	e5e403d0 */ 	swc1	$f4,0x3d0($t7)
/*  f14ef20:	24630004 */ 	addiu	$v1,$v1,0x4
.L0f14ef24:
/*  f14ef24:	1466fff0 */ 	bne	$v1,$a2,.L0f14eee8
/*  f14ef28:	24840004 */ 	addiu	$a0,$a0,0x4
/*  f14ef2c:	3c067f1b */ 	lui	$a2,%hi(var7f1b6d70)
/*  f14ef30:	24c66d70 */ 	addiu	$a2,$a2,%lo(var7f1b6d70)
/*  f14ef34:	2404ffff */ 	addiu	$a0,$zero,-1
/*  f14ef38:	0fc537bc */ 	jal	func0f14def0
/*  f14ef3c:	24051090 */ 	addiu	$a1,$zero,0x1090
/*  f14ef40:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f14ef44:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*  f14ef48:	03e00008 */ 	jr	$ra
/*  f14ef4c:	00000000 */ 	nop
);

void func0f14ef50(f32 *arg0)
{
	s32 i;

	for (i = 0; i < 7; i++) {
		struct var8007f8e0 *thing = func0f14a06c(-2);

		arg0[i] = thing->unk3d0[i];
	}
}

GLOBAL_ASM(
glabel func0f14efa8
/*  f14efa8:	27bdffc8 */ 	addiu	$sp,$sp,-56
/*  f14efac:	3c0e8008 */ 	lui	$t6,%hi(var8007fa60)
/*  f14efb0:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f14efb4:	25cefa60 */ 	addiu	$t6,$t6,%lo(var8007fa60)
/*  f14efb8:	8dc10000 */ 	lw	$at,0x0($t6)
/*  f14efbc:	27a4001c */ 	addiu	$a0,$sp,0x1c
/*  f14efc0:	ac810000 */ 	sw	$at,0x0($a0)
/*  f14efc4:	8dd90004 */ 	lw	$t9,0x4($t6)
/*  f14efc8:	ac990004 */ 	sw	$t9,0x4($a0)
/*  f14efcc:	8dc10008 */ 	lw	$at,0x8($t6)
/*  f14efd0:	ac810008 */ 	sw	$at,0x8($a0)
/*  f14efd4:	8dd9000c */ 	lw	$t9,0xc($t6)
/*  f14efd8:	ac99000c */ 	sw	$t9,0xc($a0)
/*  f14efdc:	8dc10010 */ 	lw	$at,0x10($t6)
/*  f14efe0:	ac810010 */ 	sw	$at,0x10($a0)
/*  f14efe4:	8dd90014 */ 	lw	$t9,0x14($t6)
/*  f14efe8:	ac990014 */ 	sw	$t9,0x14($a0)
/*  f14efec:	8dc10018 */ 	lw	$at,0x18($t6)
/*  f14eff0:	0fc53bac */ 	jal	func0f14eeb0
/*  f14eff4:	ac810018 */ 	sw	$at,0x18($a0)
/*  f14eff8:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f14effc:	27bd0038 */ 	addiu	$sp,$sp,0x38
/*  f14f000:	03e00008 */ 	jr	$ra
/*  f14f004:	00000000 */ 	nop
);

s32 func0f14f008(s32 index)
{
	if (index == -1) {
		index = var800a45a0->unk000;
	}

	return var8007f8dc[index].unk094;
}

void func0f14f03c(s32 index, s32 value)
{
	var8007f8dc[index].unk074 = value;
}

s32 func0f14f05c(s32 index)
{
	return var8007f8dc[index].unk074;
}

const char var7f1b6df0[] = "camdraw.c";
const char var7f1b6dfc[] = "Cam_RebuildHead : Slot=%d\n";
const char var7f1b6e18[] = "Cam -> Cam_ColourHeadOnePart - Remapping %s\n";
const char var7f1b6e48[] = "Cam_ColourHead : Face Col = %u, Hair Col = %u\n";
const char var7f1b6e78[] = "FACE";
const char var7f1b6e80[] = "SIDE";
const char var7f1b6e88[] = "HAIR";
const char var7f1b6e90[] = "Cam -> Cam_SquashOnePart - pExtents=%08x, pVcopy=%08x, \n";
const char var7f1b6ecc[] = "Cam -> Cam_SquashOnePart - Head centre at (%d,%d,%d)\n";
const char var7f1b6f04[] = "Cam -> Cam_SquashOnePart - Scale Param 1 = %s%s%.3f\n";
const char var7f1b6f3c[] = "";
const char var7f1b6f40[] = "";
const char var7f1b6f44[] = "Cam -> Cam_SquashOnePart - Scale Param 2 = %s%s%.3f\n";
const char var7f1b6f7c[] = "";
const char var7f1b6f80[] = "";
const char var7f1b6f84[] = "Cam -> Cam_SquashOnePart - Scale Param 3 = %s%s%.3f\n";
const char var7f1b6fbc[] = "";
const char var7f1b6fc0[] = "";
const char var7f1b6fc4[] = "Cam -> Cam_SquashOnePart - Scale Param 4 = %s%s%.3f\n";
const char var7f1b6ffc[] = "";
const char var7f1b7000[] = "";
const char var7f1b7004[] = "Cam -> Cam_SquashOnePart - Scale Param 5 = %s%s%.3f\n";
const char var7f1b703c[] = "";
const char var7f1b7040[] = "";
const char var7f1b7044[] = "Cam -> Cam_SquashOnePart - Scale Param 6 = %s%s%.3f\n";
const char var7f1b707c[] = "";
const char var7f1b7080[] = "";
const char var7f1b7084[] = "Cam -> Cam_SquashOnePart - Scale Param 7 = %s%s%.3f\n";
const char var7f1b70bc[] = "";
const char var7f1b70c0[] = "";
const char var7f1b70c4[] = "Cam_DctInitialise_Read -> %x\n";
const char var7f1b70e4[] = "Cam_DctUnCompressSlot -> %x\n";
const char var7f1b7104[] = "Cam_LoadFromPakIntoSlot -> Pak=%d, fileGuid=%u, pakGuid=%u, Slot=%d, pS=%x, pE=%x\n";

GLOBAL_ASM(
glabel func0f14f07c
/*  f14f07c:	27bdffc0 */ 	addiu	$sp,$sp,-64
/*  f14f080:	44862000 */ 	mtc1	$a2,$f4
/*  f14f084:	44874000 */ 	mtc1	$a3,$f8
/*  f14f088:	3c0e800a */ 	lui	$t6,%hi(var800a45a0)
/*  f14f08c:	8dce45a0 */ 	lw	$t6,%lo(var800a45a0)($t6)
/*  f14f090:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f14f094:	afbf0024 */ 	sw	$ra,0x24($sp)
/*  f14f098:	afb00020 */ 	sw	$s0,0x20($sp)
/*  f14f09c:	afa50044 */ 	sw	$a1,0x44($sp)
/*  f14f0a0:	afa60048 */ 	sw	$a2,0x48($sp)
/*  f14f0a4:	468042a0 */ 	cvt.s.w	$f10,$f8
/*  f14f0a8:	afa7004c */ 	sw	$a3,0x4c($sp)
/*  f14f0ac:	8dcf0484 */ 	lw	$t7,0x484($t6)
/*  f14f0b0:	0005c880 */ 	sll	$t9,$a1,0x2
/*  f14f0b4:	0325c823 */ 	subu	$t9,$t9,$a1
/*  f14f0b8:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f14f0bc:	01f94021 */ 	addu	$t0,$t7,$t9
/*  f14f0c0:	00808025 */ 	or	$s0,$a0,$zero
/*  f14f0c4:	afa8003c */ 	sw	$t0,0x3c($sp)
/*  f14f0c8:	e7a60034 */ 	swc1	$f6,0x34($sp)
/*  f14f0cc:	0fc52883 */ 	jal	func0f14a20c
/*  f14f0d0:	e7aa0038 */ 	swc1	$f10,0x38($sp)
/*  f14f0d4:	8fab0044 */ 	lw	$t3,0x44($sp)
/*  f14f0d8:	240100ff */ 	addiu	$at,$zero,0xff
/*  f14f0dc:	004b6021 */ 	addu	$t4,$v0,$t3
/*  f14f0e0:	918d00b6 */ 	lbu	$t5,0xb6($t4)
/*  f14f0e4:	51a10037 */ 	beql	$t5,$at,.L0f14f1c4
/*  f14f0e8:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*  f14f0ec:	0fc52883 */ 	jal	func0f14a20c
/*  f14f0f0:	00000000 */ 	nop
/*  f14f0f4:	8fb80044 */ 	lw	$t8,0x44($sp)
/*  f14f0f8:	8c4e00dc */ 	lw	$t6,0xdc($v0)
/*  f14f0fc:	8fa90054 */ 	lw	$t1,0x54($sp)
/*  f14f100:	00187880 */ 	sll	$t7,$t8,0x2
/*  f14f104:	01cfc821 */ 	addu	$t9,$t6,$t7
/*  f14f108:	8f280000 */ 	lw	$t0,0x0($t9)
/*  f14f10c:	8fb90048 */ 	lw	$t9,0x48($sp)
/*  f14f110:	8faf0050 */ 	lw	$t7,0x50($sp)
/*  f14f114:	15000019 */ 	bnez	$t0,.L0f14f17c
/*  f14f118:	8faa004c */ 	lw	$t2,0x4c($sp)
/*  f14f11c:	8faa0050 */ 	lw	$t2,0x50($sp)
/*  f14f120:	8fab0048 */ 	lw	$t3,0x48($sp)
/*  f14f124:	8fad0054 */ 	lw	$t5,0x54($sp)
/*  f14f128:	8fb8004c */ 	lw	$t8,0x4c($sp)
/*  f14f12c:	014b6023 */ 	subu	$t4,$t2,$t3
/*  f14f130:	448c8000 */ 	mtc1	$t4,$f16
/*  f14f134:	01b87023 */ 	subu	$t6,$t5,$t8
/*  f14f138:	448e3000 */ 	mtc1	$t6,$f6
/*  f14f13c:	468084a0 */ 	cvt.s.w	$f18,$f16
/*  f14f140:	3c013c80 */ 	lui	$at,0x3c80
/*  f14f144:	44810000 */ 	mtc1	$at,$f0
/*  f14f148:	3c09800a */ 	lui	$t1,%hi(var800a45a0)
/*  f14f14c:	8d2945a0 */ 	lw	$t1,%lo(var800a45a0)($t1)
/*  f14f150:	46803220 */ 	cvt.s.w	$f8,$f6
/*  f14f154:	46009102 */ 	mul.s	$f4,$f18,$f0
/*  f14f158:	8d250488 */ 	lw	$a1,0x488($t1)
/*  f14f15c:	02002025 */ 	or	$a0,$s0,$zero
/*  f14f160:	27a60034 */ 	addiu	$a2,$sp,0x34
/*  f14f164:	46004282 */ 	mul.s	$f10,$f8,$f0
/*  f14f168:	44072000 */ 	mfc1	$a3,$f4
/*  f14f16c:	0fc5321c */ 	jal	func0f14c870
/*  f14f170:	e7aa0010 */ 	swc1	$f10,0x10($sp)
/*  f14f174:	10000012 */ 	b	.L0f14f1c0
/*  f14f178:	00408025 */ 	or	$s0,$v0,$zero
.L0f14f17c:
/*  f14f17c:	01f94023 */ 	subu	$t0,$t7,$t9
/*  f14f180:	44888000 */ 	mtc1	$t0,$f16
/*  f14f184:	012a5823 */ 	subu	$t3,$t1,$t2
/*  f14f188:	448b3000 */ 	mtc1	$t3,$f6
/*  f14f18c:	468084a0 */ 	cvt.s.w	$f18,$f16
/*  f14f190:	3c013c80 */ 	lui	$at,0x3c80
/*  f14f194:	44810000 */ 	mtc1	$at,$f0
/*  f14f198:	02002025 */ 	or	$a0,$s0,$zero
/*  f14f19c:	8fa5003c */ 	lw	$a1,0x3c($sp)
/*  f14f1a0:	46803220 */ 	cvt.s.w	$f8,$f6
/*  f14f1a4:	46009102 */ 	mul.s	$f4,$f18,$f0
/*  f14f1a8:	27a60034 */ 	addiu	$a2,$sp,0x34
/*  f14f1ac:	46004282 */ 	mul.s	$f10,$f8,$f0
/*  f14f1b0:	44072000 */ 	mfc1	$a3,$f4
/*  f14f1b4:	0fc5321c */ 	jal	func0f14c870
/*  f14f1b8:	e7aa0010 */ 	swc1	$f10,0x10($sp)
/*  f14f1bc:	00408025 */ 	or	$s0,$v0,$zero
.L0f14f1c0:
/*  f14f1c0:	8fbf0024 */ 	lw	$ra,0x24($sp)
.L0f14f1c4:
/*  f14f1c4:	02001025 */ 	or	$v0,$s0,$zero
/*  f14f1c8:	8fb00020 */ 	lw	$s0,0x20($sp)
/*  f14f1cc:	03e00008 */ 	jr	$ra
/*  f14f1d0:	27bd0040 */ 	addiu	$sp,$sp,0x40
/*  f14f1d4:	18a00035 */ 	blez	$a1,.L0f14f2ac
/*  f14f1d8:	00000000 */ 	nop
/*  f14f1dc:	84820000 */ 	lh	$v0,0x0($a0)
/*  f14f1e0:	28a10002 */ 	slti	$at,$a1,0x2
/*  f14f1e4:	24030001 */ 	addiu	$v1,$zero,0x1
/*  f14f1e8:	acc2000c */ 	sw	$v0,0xc($a2)
/*  f14f1ec:	acc20000 */ 	sw	$v0,0x0($a2)
/*  f14f1f0:	84820002 */ 	lh	$v0,0x2($a0)
/*  f14f1f4:	acc20010 */ 	sw	$v0,0x10($a2)
/*  f14f1f8:	acc20004 */ 	sw	$v0,0x4($a2)
/*  f14f1fc:	84820004 */ 	lh	$v0,0x4($a0)
/*  f14f200:	acc20014 */ 	sw	$v0,0x14($a2)
/*  f14f204:	14200029 */ 	bnez	$at,.L0f14f2ac
/*  f14f208:	acc20008 */ 	sw	$v0,0x8($a2)
/*  f14f20c:	2482000c */ 	addiu	$v0,$a0,0xc
.L0f14f210:
/*  f14f210:	84440000 */ 	lh	$a0,0x0($v0)
/*  f14f214:	8cce000c */ 	lw	$t6,0xc($a2)
/*  f14f218:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f14f21c:	01c4082a */ 	slt	$at,$t6,$a0
/*  f14f220:	50200004 */ 	beqzl	$at,.L0f14f234
/*  f14f224:	8ccf0000 */ 	lw	$t7,0x0($a2)
/*  f14f228:	10000006 */ 	b	.L0f14f244
/*  f14f22c:	acc4000c */ 	sw	$a0,0xc($a2)
/*  f14f230:	8ccf0000 */ 	lw	$t7,0x0($a2)
.L0f14f234:
/*  f14f234:	008f082a */ 	slt	$at,$a0,$t7
/*  f14f238:	50200003 */ 	beqzl	$at,.L0f14f248
/*  f14f23c:	84440002 */ 	lh	$a0,0x2($v0)
/*  f14f240:	acc40000 */ 	sw	$a0,0x0($a2)
.L0f14f244:
/*  f14f244:	84440002 */ 	lh	$a0,0x2($v0)
.L0f14f248:
/*  f14f248:	8cd80010 */ 	lw	$t8,0x10($a2)
/*  f14f24c:	0304082a */ 	slt	$at,$t8,$a0
/*  f14f250:	50200004 */ 	beqzl	$at,.L0f14f264
/*  f14f254:	8cd90004 */ 	lw	$t9,0x4($a2)
/*  f14f258:	10000006 */ 	b	.L0f14f274
/*  f14f25c:	acc40010 */ 	sw	$a0,0x10($a2)
/*  f14f260:	8cd90004 */ 	lw	$t9,0x4($a2)
.L0f14f264:
/*  f14f264:	0099082a */ 	slt	$at,$a0,$t9
/*  f14f268:	50200003 */ 	beqzl	$at,.L0f14f278
/*  f14f26c:	84440004 */ 	lh	$a0,0x4($v0)
/*  f14f270:	acc40004 */ 	sw	$a0,0x4($a2)
.L0f14f274:
/*  f14f274:	84440004 */ 	lh	$a0,0x4($v0)
.L0f14f278:
/*  f14f278:	8cc80014 */ 	lw	$t0,0x14($a2)
/*  f14f27c:	0104082a */ 	slt	$at,$t0,$a0
/*  f14f280:	50200004 */ 	beqzl	$at,.L0f14f294
/*  f14f284:	8cc90008 */ 	lw	$t1,0x8($a2)
/*  f14f288:	10000006 */ 	b	.L0f14f2a4
/*  f14f28c:	acc40014 */ 	sw	$a0,0x14($a2)
/*  f14f290:	8cc90008 */ 	lw	$t1,0x8($a2)
.L0f14f294:
/*  f14f294:	0089082a */ 	slt	$at,$a0,$t1
/*  f14f298:	10200002 */ 	beqz	$at,.L0f14f2a4
/*  f14f29c:	00000000 */ 	nop
/*  f14f2a0:	acc40008 */ 	sw	$a0,0x8($a2)
.L0f14f2a4:
/*  f14f2a4:	1465ffda */ 	bne	$v1,$a1,.L0f14f210
/*  f14f2a8:	2442000c */ 	addiu	$v0,$v0,0xc
.L0f14f2ac:
/*  f14f2ac:	03e00008 */ 	jr	$ra
/*  f14f2b0:	00000000 */ 	nop
/*  f14f2b4:	27bdffa8 */ 	addiu	$sp,$sp,-88
/*  f14f2b8:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f14f2bc:	00a08025 */ 	or	$s0,$a1,$zero
/*  f14f2c0:	afbf001c */ 	sw	$ra,0x1c($sp)
/*  f14f2c4:	afa40058 */ 	sw	$a0,0x58($sp)
/*  f14f2c8:	afa60060 */ 	sw	$a2,0x60($sp)
/*  f14f2cc:	0c006a47 */ 	jal	modelGetPart
/*  f14f2d0:	24050190 */ 	addiu	$a1,$zero,0x190
/*  f14f2d4:	afa20054 */ 	sw	$v0,0x54($sp)
/*  f14f2d8:	8fa40058 */ 	lw	$a0,0x58($sp)
/*  f14f2dc:	0c006a47 */ 	jal	modelGetPart
/*  f14f2e0:	24050191 */ 	addiu	$a1,$zero,0x191
/*  f14f2e4:	8fa40058 */ 	lw	$a0,0x58($sp)
/*  f14f2e8:	24050192 */ 	addiu	$a1,$zero,0x192
/*  f14f2ec:	0c006a47 */ 	jal	modelGetPart
/*  f14f2f0:	afa20050 */ 	sw	$v0,0x50($sp)
/*  f14f2f4:	8fad0060 */ 	lw	$t5,0x60($sp)
/*  f14f2f8:	8fa30050 */ 	lw	$v1,0x50($sp)
/*  f14f2fc:	00405825 */ 	or	$t3,$v0,$zero
/*  f14f300:	11a00002 */ 	beqz	$t5,.L0f14f30c
/*  f14f304:	afa00048 */ 	sw	$zero,0x48($sp)
/*  f14f308:	ada00000 */ 	sw	$zero,0x0($t5)
.L0f14f30c:
/*  f14f30c:	8fac0054 */ 	lw	$t4,0x54($sp)
/*  f14f310:	51800048 */ 	beqzl	$t4,.L0f14f434
/*  f14f314:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f14f318:	50600046 */ 	beqzl	$v1,.L0f14f434
/*  f14f31c:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f14f320:	50400044 */ 	beqzl	$v0,.L0f14f434
/*  f14f324:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f14f328:	8d850004 */ 	lw	$a1,0x4($t4)
/*  f14f32c:	8c660004 */ 	lw	$a2,0x4($v1)
/*  f14f330:	8d670004 */ 	lw	$a3,0x4($t3)
/*  f14f334:	84a80010 */ 	lh	$t0,0x10($a1)
/*  f14f338:	84c90010 */ 	lh	$t1,0x10($a2)
/*  f14f33c:	84ea0010 */ 	lh	$t2,0x10($a3)
/*  f14f340:	afa50044 */ 	sw	$a1,0x44($sp)
/*  f14f344:	01097021 */ 	addu	$t6,$t0,$t1
/*  f14f348:	01ca1021 */ 	addu	$v0,$t6,$t2
/*  f14f34c:	00022080 */ 	sll	$a0,$v0,0x2
/*  f14f350:	00822023 */ 	subu	$a0,$a0,$v0
/*  f14f354:	afa20048 */ 	sw	$v0,0x48($sp)
/*  f14f358:	00042080 */ 	sll	$a0,$a0,0x2
/*  f14f35c:	afa60040 */ 	sw	$a2,0x40($sp)
/*  f14f360:	afa7003c */ 	sw	$a3,0x3c($sp)
/*  f14f364:	afa80038 */ 	sw	$t0,0x38($sp)
/*  f14f368:	afa90034 */ 	sw	$t1,0x34($sp)
/*  f14f36c:	0fc5db69 */ 	jal	align16
/*  f14f370:	afaa0030 */ 	sw	$t2,0x30($sp)
/*  f14f374:	afa2002c */ 	sw	$v0,0x2c($sp)
/*  f14f378:	8e040000 */ 	lw	$a0,0x0($s0)
/*  f14f37c:	3c067f1b */ 	lui	$a2,%hi(var7f1b6df0)
/*  f14f380:	24c66df0 */ 	addiu	$a2,$a2,%lo(var7f1b6df0)
/*  f14f384:	14800005 */ 	bnez	$a0,.L0f14f39c
/*  f14f388:	2405114d */ 	addiu	$a1,$zero,0x114d
/*  f14f38c:	0fc52756 */ 	jal	func0f149d58
/*  f14f390:	00402025 */ 	or	$a0,$v0,$zero
/*  f14f394:	ae020000 */ 	sw	$v0,0x0($s0)
/*  f14f398:	00402025 */ 	or	$a0,$v0,$zero
.L0f14f39c:
/*  f14f39c:	8fa60038 */ 	lw	$a2,0x38($sp)
/*  f14f3a0:	8faf0044 */ 	lw	$t7,0x44($sp)
/*  f14f3a4:	0006c080 */ 	sll	$t8,$a2,0x2
/*  f14f3a8:	0306c023 */ 	subu	$t8,$t8,$a2
/*  f14f3ac:	00183080 */ 	sll	$a2,$t8,0x2
/*  f14f3b0:	8de5000c */ 	lw	$a1,0xc($t7)
/*  f14f3b4:	0c012978 */ 	jal	memcpy
/*  f14f3b8:	afa60024 */ 	sw	$a2,0x24($sp)
/*  f14f3bc:	8fa70034 */ 	lw	$a3,0x34($sp)
/*  f14f3c0:	8faf0040 */ 	lw	$t7,0x40($sp)
/*  f14f3c4:	8e190000 */ 	lw	$t9,0x0($s0)
/*  f14f3c8:	0007c080 */ 	sll	$t8,$a3,0x2
/*  f14f3cc:	8fae0024 */ 	lw	$t6,0x24($sp)
/*  f14f3d0:	0307c023 */ 	subu	$t8,$t8,$a3
/*  f14f3d4:	00183080 */ 	sll	$a2,$t8,0x2
/*  f14f3d8:	8de5000c */ 	lw	$a1,0xc($t7)
/*  f14f3dc:	afa60028 */ 	sw	$a2,0x28($sp)
/*  f14f3e0:	00c03825 */ 	or	$a3,$a2,$zero
/*  f14f3e4:	0c012978 */ 	jal	memcpy
/*  f14f3e8:	032e2021 */ 	addu	$a0,$t9,$t6
/*  f14f3ec:	8e190000 */ 	lw	$t9,0x0($s0)
/*  f14f3f0:	8fae0024 */ 	lw	$t6,0x24($sp)
/*  f14f3f4:	8fa60030 */ 	lw	$a2,0x30($sp)
/*  f14f3f8:	8fa70028 */ 	lw	$a3,0x28($sp)
/*  f14f3fc:	032e7821 */ 	addu	$t7,$t9,$t6
/*  f14f400:	8fb8003c */ 	lw	$t8,0x3c($sp)
/*  f14f404:	0006c880 */ 	sll	$t9,$a2,0x2
/*  f14f408:	0326c823 */ 	subu	$t9,$t9,$a2
/*  f14f40c:	00193080 */ 	sll	$a2,$t9,0x2
/*  f14f410:	01e72021 */ 	addu	$a0,$t7,$a3
/*  f14f414:	0c012978 */ 	jal	memcpy
/*  f14f418:	8f05000c */ 	lw	$a1,0xc($t8)
/*  f14f41c:	8fae0060 */ 	lw	$t6,0x60($sp)
/*  f14f420:	8faf002c */ 	lw	$t7,0x2c($sp)
/*  f14f424:	51c00003 */ 	beqzl	$t6,.L0f14f434
/*  f14f428:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f14f42c:	adcf0000 */ 	sw	$t7,0x0($t6)
/*  f14f430:	8fbf001c */ 	lw	$ra,0x1c($sp)
.L0f14f434:
/*  f14f434:	8fa20048 */ 	lw	$v0,0x48($sp)
/*  f14f438:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f14f43c:	03e00008 */ 	jr	$ra
/*  f14f440:	27bd0058 */ 	addiu	$sp,$sp,0x58
/*  f14f444:	afa40000 */ 	sw	$a0,0x0($sp)
/*  f14f448:	afa50004 */ 	sw	$a1,0x4($sp)
/*  f14f44c:	afa60008 */ 	sw	$a2,0x8($sp)
/*  f14f450:	03e00008 */ 	jr	$ra
/*  f14f454:	afa7000c */ 	sw	$a3,0xc($sp)
/*  f14f458:	03e00008 */ 	jr	$ra
/*  f14f45c:	00000000 */ 	nop
/*  f14f460:	03e00008 */ 	jr	$ra
/*  f14f464:	00000000 */ 	nop
/*  f14f468:	03e00008 */ 	jr	$ra
/*  f14f46c:	00000000 */ 	nop
/*  f14f470:	03e00008 */ 	jr	$ra
/*  f14f474:	00000000 */ 	nop
/*  f14f478:	03e00008 */ 	jr	$ra
/*  f14f47c:	00000000 */ 	nop
/*  f14f480:	03e00008 */ 	jr	$ra
/*  f14f484:	00000000 */ 	nop
/*  f14f488:	03e00008 */ 	jr	$ra
/*  f14f48c:	00000000 */ 	nop
/*  f14f490:	03e00008 */ 	jr	$ra
/*  f14f494:	00000000 */ 	nop
/*  f14f498:	03e00008 */ 	jr	$ra
/*  f14f49c:	00000000 */ 	nop
/*  f14f4a0:	03e00008 */ 	jr	$ra
/*  f14f4a4:	00801025 */ 	or	$v0,$a0,$zero
/*  f14f4a8:	03e00008 */ 	jr	$ra
/*  f14f4ac:	00000000 */ 	nop
/*  f14f4b0:	03e00008 */ 	jr	$ra
/*  f14f4b4:	afa40000 */ 	sw	$a0,0x0($sp)
);

GLOBAL_ASM(
glabel func0f14f4b8
/*  f14f4b8:	ac800028 */ 	sw	$zero,0x28($a0)
/*  f14f4bc:	ac80002c */ 	sw	$zero,0x2c($a0)
/*  f14f4c0:	00001025 */ 	or	$v0,$zero,$zero
/*  f14f4c4:	24031000 */ 	addiu	$v1,$zero,0x1000
.L0f14f4c8:
/*  f14f4c8:	8c8e001c */ 	lw	$t6,0x1c($a0)
/*  f14f4cc:	01c27821 */ 	addu	$t7,$t6,$v0
/*  f14f4d0:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f14f4d4:	1443fffc */ 	bne	$v0,$v1,.L0f14f4c8
/*  f14f4d8:	a1e00000 */ 	sb	$zero,0x0($t7)
/*  f14f4dc:	03e00008 */ 	jr	$ra
/*  f14f4e0:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel func0f14f4e4
/*  f14f4e4:	ac800028 */ 	sw	$zero,0x28($a0)
/*  f14f4e8:	ac80002c */ 	sw	$zero,0x2c($a0)
/*  f14f4ec:	00001025 */ 	or	$v0,$zero,$zero
/*  f14f4f0:	24031000 */ 	addiu	$v1,$zero,0x1000
.L0f14f4f4:
/*  f14f4f4:	8c8e0024 */ 	lw	$t6,0x24($a0)
/*  f14f4f8:	01c27821 */ 	addu	$t7,$t6,$v0
/*  f14f4fc:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f14f500:	1443fffc */ 	bne	$v0,$v1,.L0f14f4f4
/*  f14f504:	a1e00000 */ 	sb	$zero,0x0($t7)
/*  f14f508:	03e00008 */ 	jr	$ra
/*  f14f50c:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel func0f14f510
.late_rodata
glabel var7f1b7364
.word 0x40490fda
.text
/*  f14f510:	27bdffa0 */ 	addiu	$sp,$sp,-96
/*  f14f514:	afb40050 */ 	sw	$s4,0x50($sp)
/*  f14f518:	afb3004c */ 	sw	$s3,0x4c($sp)
/*  f14f51c:	3c14800a */ 	lui	$s4,%hi(var800a45a0)
/*  f14f520:	afbf005c */ 	sw	$ra,0x5c($sp)
/*  f14f524:	afb60058 */ 	sw	$s6,0x58($sp)
/*  f14f528:	afb50054 */ 	sw	$s5,0x54($sp)
/*  f14f52c:	afb20048 */ 	sw	$s2,0x48($sp)
/*  f14f530:	afb10044 */ 	sw	$s1,0x44($sp)
/*  f14f534:	afb00040 */ 	sw	$s0,0x40($sp)
/*  f14f538:	f7bc0038 */ 	sdc1	$f28,0x38($sp)
/*  f14f53c:	f7ba0030 */ 	sdc1	$f26,0x30($sp)
/*  f14f540:	f7b80028 */ 	sdc1	$f24,0x28($sp)
/*  f14f544:	f7b60020 */ 	sdc1	$f22,0x20($sp)
/*  f14f548:	f7b40018 */ 	sdc1	$f20,0x18($sp)
/*  f14f54c:	269445a0 */ 	addiu	$s4,$s4,%lo(var800a45a0)
/*  f14f550:	00009825 */ 	or	$s3,$zero,$zero
/*  f14f554:	266e0001 */ 	addiu	$t6,$s3,0x1
.L0f14f558:
/*  f14f558:	01c40019 */ 	multu	$t6,$a0
/*  f14f55c:	00008825 */ 	or	$s1,$zero,$zero
/*  f14f560:	00008025 */ 	or	$s0,$zero,$zero
/*  f14f564:	00001012 */ 	mflo	$v0
/*  f14f568:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f14f56c:	00000000 */ 	nop
.L0f14f570:
/*  f14f570:	8e8f0000 */ 	lw	$t7,0x0($s4)
/*  f14f574:	0013c140 */ 	sll	$t8,$s3,0x5
/*  f14f578:	26310001 */ 	addiu	$s1,$s1,0x1
/*  f14f57c:	01f8c821 */ 	addu	$t9,$t7,$t8
/*  f14f580:	03304021 */ 	addu	$t0,$t9,$s0
/*  f14f584:	2a210008 */ 	slti	$at,$s1,0x8
/*  f14f588:	ad02006c */ 	sw	$v0,0x6c($t0)
/*  f14f58c:	00441021 */ 	addu	$v0,$v0,$a0
/*  f14f590:	1420fff7 */ 	bnez	$at,.L0f14f570
/*  f14f594:	26100004 */ 	addiu	$s0,$s0,0x4
/*  f14f598:	26730001 */ 	addiu	$s3,$s3,0x1
/*  f14f59c:	2a610008 */ 	slti	$at,$s3,0x8
/*  f14f5a0:	5420ffed */ 	bnezl	$at,.L0f14f558
/*  f14f5a4:	266e0001 */ 	addiu	$t6,$s3,0x1
/*  f14f5a8:	8e890000 */ 	lw	$t1,0x0($s4)
/*  f14f5ac:	3c013f80 */ 	lui	$at,0x3f80
/*  f14f5b0:	4481b000 */ 	mtc1	$at,$f22
/*  f14f5b4:	ad200010 */ 	sw	$zero,0x10($t1)
/*  f14f5b8:	8e8a0000 */ 	lw	$t2,0x0($s4)
/*  f14f5bc:	3c014100 */ 	lui	$at,0x4100
/*  f14f5c0:	4481a000 */ 	mtc1	$at,$f20
/*  f14f5c4:	00008025 */ 	or	$s0,$zero,$zero
/*  f14f5c8:	00009025 */ 	or	$s2,$zero,$zero
/*  f14f5cc:	24110100 */ 	addiu	$s1,$zero,0x100
/*  f14f5d0:	ad40000c */ 	sw	$zero,0xc($t2)
.L0f14f5d4:
/*  f14f5d4:	0c012974 */ 	jal	sqrtf
/*  f14f5d8:	4600a306 */ 	mov.s	$f12,$f20
/*  f14f5dc:	4600b103 */ 	div.s	$f4,$f22,$f0
/*  f14f5e0:	8e8b0000 */ 	lw	$t3,0x0($s4)
/*  f14f5e4:	01706021 */ 	addu	$t4,$t3,$s0
/*  f14f5e8:	e584017c */ 	swc1	$f4,0x17c($t4)
/*  f14f5ec:	8e820000 */ 	lw	$v0,0x0($s4)
/*  f14f5f0:	00506821 */ 	addu	$t5,$v0,$s0
/*  f14f5f4:	c5a6017c */ 	lwc1	$f6,0x17c($t5)
/*  f14f5f8:	00527021 */ 	addu	$t6,$v0,$s2
/*  f14f5fc:	26520020 */ 	addiu	$s2,$s2,0x20
/*  f14f600:	26100004 */ 	addiu	$s0,$s0,0x4
/*  f14f604:	1651fff3 */ 	bne	$s2,$s1,.L0f14f5d4
/*  f14f608:	e5c6027c */ 	swc1	$f6,0x27c($t6)
/*  f14f60c:	3c014180 */ 	lui	$at,0x4180
/*  f14f610:	4481e000 */ 	mtc1	$at,$f28
/*  f14f614:	3c017f1b */ 	lui	$at,%hi(var7f1b7364)
/*  f14f618:	c43a7364 */ 	lwc1	$f26,%lo(var7f1b7364)($at)
/*  f14f61c:	3c013e80 */ 	lui	$at,0x3e80
/*  f14f620:	4481c000 */ 	mtc1	$at,$f24
/*  f14f624:	24130001 */ 	addiu	$s3,$zero,0x1
/*  f14f628:	24150004 */ 	addiu	$s5,$zero,0x4
/*  f14f62c:	24160008 */ 	addiu	$s6,$zero,0x8
.L0f14f630:
/*  f14f630:	44934000 */ 	mtc1	$s3,$f8
/*  f14f634:	00008825 */ 	or	$s1,$zero,$zero
/*  f14f638:	00008025 */ 	or	$s0,$zero,$zero
/*  f14f63c:	24120001 */ 	addiu	$s2,$zero,0x1
/*  f14f640:	468045a0 */ 	cvt.s.w	$f22,$f8
.L0f14f644:
/*  f14f644:	0c012974 */ 	jal	sqrtf
/*  f14f648:	4600c306 */ 	mov.s	$f12,$f24
/*  f14f64c:	44925000 */ 	mtc1	$s2,$f10
/*  f14f650:	46000506 */ 	mov.s	$f20,$f0
/*  f14f654:	46805420 */ 	cvt.s.w	$f16,$f10
/*  f14f658:	461a8482 */ 	mul.s	$f18,$f16,$f26
/*  f14f65c:	00000000 */ 	nop
/*  f14f660:	46169102 */ 	mul.s	$f4,$f18,$f22
/*  f14f664:	0c0068f4 */ 	jal	cosf
/*  f14f668:	461c2303 */ 	div.s	$f12,$f4,$f28
/*  f14f66c:	46140182 */ 	mul.s	$f6,$f0,$f20
/*  f14f670:	8e8f0000 */ 	lw	$t7,0x0($s4)
/*  f14f674:	0013c140 */ 	sll	$t8,$s3,0x5
/*  f14f678:	00134940 */ 	sll	$t1,$s3,0x5
/*  f14f67c:	01f8c821 */ 	addu	$t9,$t7,$t8
/*  f14f680:	03304021 */ 	addu	$t0,$t9,$s0
/*  f14f684:	00116140 */ 	sll	$t4,$s1,0x5
/*  f14f688:	e506017c */ 	swc1	$f6,0x17c($t0)
/*  f14f68c:	8e820000 */ 	lw	$v0,0x0($s4)
/*  f14f690:	26310001 */ 	addiu	$s1,$s1,0x1
/*  f14f694:	26520002 */ 	addiu	$s2,$s2,0x2
/*  f14f698:	00495021 */ 	addu	$t2,$v0,$t1
/*  f14f69c:	01505821 */ 	addu	$t3,$t2,$s0
/*  f14f6a0:	c568017c */ 	lwc1	$f8,0x17c($t3)
/*  f14f6a4:	004c6821 */ 	addu	$t5,$v0,$t4
/*  f14f6a8:	01b57021 */ 	addu	$t6,$t5,$s5
/*  f14f6ac:	26100004 */ 	addiu	$s0,$s0,0x4
/*  f14f6b0:	1636ffe4 */ 	bne	$s1,$s6,.L0f14f644
/*  f14f6b4:	e5c8027c */ 	swc1	$f8,0x27c($t6)
/*  f14f6b8:	26730001 */ 	addiu	$s3,$s3,0x1
/*  f14f6bc:	1676ffdc */ 	bne	$s3,$s6,.L0f14f630
/*  f14f6c0:	26b50004 */ 	addiu	$s5,$s5,0x4
/*  f14f6c4:	8fbf005c */ 	lw	$ra,0x5c($sp)
/*  f14f6c8:	d7b40018 */ 	ldc1	$f20,0x18($sp)
/*  f14f6cc:	d7b60020 */ 	ldc1	$f22,0x20($sp)
/*  f14f6d0:	d7b80028 */ 	ldc1	$f24,0x28($sp)
/*  f14f6d4:	d7ba0030 */ 	ldc1	$f26,0x30($sp)
/*  f14f6d8:	d7bc0038 */ 	ldc1	$f28,0x38($sp)
/*  f14f6dc:	8fb00040 */ 	lw	$s0,0x40($sp)
/*  f14f6e0:	8fb10044 */ 	lw	$s1,0x44($sp)
/*  f14f6e4:	8fb20048 */ 	lw	$s2,0x48($sp)
/*  f14f6e8:	8fb3004c */ 	lw	$s3,0x4c($sp)
/*  f14f6ec:	8fb40050 */ 	lw	$s4,0x50($sp)
/*  f14f6f0:	8fb50054 */ 	lw	$s5,0x54($sp)
/*  f14f6f4:	8fb60058 */ 	lw	$s6,0x58($sp)
/*  f14f6f8:	03e00008 */ 	jr	$ra
/*  f14f6fc:	27bd0060 */ 	addiu	$sp,$sp,0x60
);

GLOBAL_ASM(
glabel func0f14f700
/*  f14f700:	24ce001f */ 	addiu	$t6,$a2,0x1f
/*  f14f704:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f14f708:	01cf1004 */ 	sllv	$v0,$t7,$t6
/*  f14f70c:	10400015 */ 	beqz	$v0,.L0f14f764
/*  f14f710:	24090007 */ 	addiu	$t1,$zero,0x7
.L0f14f714:
/*  f14f714:	0045c024 */ 	and	$t8,$v0,$a1
/*  f14f718:	5300000d */ 	beqzl	$t8,.L0f14f750
/*  f14f71c:	8c98002c */ 	lw	$t8,0x2c($a0)
/*  f14f720:	8c86002c */ 	lw	$a2,0x2c($a0)
/*  f14f724:	8c990024 */ 	lw	$t9,0x24($a0)
/*  f14f728:	240c0001 */ 	addiu	$t4,$zero,0x1
/*  f14f72c:	000638c2 */ 	srl	$a3,$a2,0x3
/*  f14f730:	03274021 */ 	addu	$t0,$t9,$a3
/*  f14f734:	910a0000 */ 	lbu	$t2,0x0($t0)
/*  f14f738:	30c30007 */ 	andi	$v1,$a2,0x7
/*  f14f73c:	01235823 */ 	subu	$t3,$t1,$v1
/*  f14f740:	016c7804 */ 	sllv	$t7,$t4,$t3
/*  f14f744:	014f7025 */ 	or	$t6,$t2,$t7
/*  f14f748:	a10e0000 */ 	sb	$t6,0x0($t0)
/*  f14f74c:	8c98002c */ 	lw	$t8,0x2c($a0)
.L0f14f750:
/*  f14f750:	00026042 */ 	srl	$t4,$v0,0x1
/*  f14f754:	01801025 */ 	or	$v0,$t4,$zero
/*  f14f758:	27190001 */ 	addiu	$t9,$t8,0x1
/*  f14f75c:	1580ffed */ 	bnez	$t4,.L0f14f714
/*  f14f760:	ac99002c */ 	sw	$t9,0x2c($a0)
.L0f14f764:
/*  f14f764:	03e00008 */ 	jr	$ra
/*  f14f768:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel func0f14f76c
/*  f14f76c:	24ae001f */ 	addiu	$t6,$a1,0x1f
/*  f14f770:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f14f774:	01cf1004 */ 	sllv	$v0,$t7,$t6
/*  f14f778:	10400014 */ 	beqz	$v0,.L0f14f7cc
/*  f14f77c:	00003025 */ 	or	$a2,$zero,$zero
/*  f14f780:	24080007 */ 	addiu	$t0,$zero,0x7
.L0f14f784:
/*  f14f784:	8c85002c */ 	lw	$a1,0x2c($a0)
/*  f14f788:	8c980020 */ 	lw	$t8,0x20($a0)
/*  f14f78c:	240b0001 */ 	addiu	$t3,$zero,0x1
/*  f14f790:	000538c2 */ 	srl	$a3,$a1,0x3
/*  f14f794:	30a30007 */ 	andi	$v1,$a1,0x7
/*  f14f798:	0307c821 */ 	addu	$t9,$t8,$a3
/*  f14f79c:	93290000 */ 	lbu	$t1,0x0($t9)
/*  f14f7a0:	01035023 */ 	subu	$t2,$t0,$v1
/*  f14f7a4:	014b6004 */ 	sllv	$t4,$t3,$t2
/*  f14f7a8:	318d00ff */ 	andi	$t5,$t4,0xff
/*  f14f7ac:	012d7824 */ 	and	$t7,$t1,$t5
/*  f14f7b0:	11e00002 */ 	beqz	$t7,.L0f14f7bc
/*  f14f7b4:	24ae0001 */ 	addiu	$t6,$a1,0x1
/*  f14f7b8:	00c23025 */ 	or	$a2,$a2,$v0
.L0f14f7bc:
/*  f14f7bc:	0002c042 */ 	srl	$t8,$v0,0x1
/*  f14f7c0:	03001025 */ 	or	$v0,$t8,$zero
/*  f14f7c4:	1700ffef */ 	bnez	$t8,.L0f14f784
/*  f14f7c8:	ac8e002c */ 	sw	$t6,0x2c($a0)
.L0f14f7cc:
/*  f14f7cc:	03e00008 */ 	jr	$ra
/*  f14f7d0:	00c01025 */ 	or	$v0,$a2,$zero
);

GLOBAL_ASM(
glabel func0f14f7d4
/*  f14f7d4:	3c03800a */ 	lui	$v1,%hi(var800a45a0)
/*  f14f7d8:	8c6345a0 */ 	lw	$v1,%lo(var800a45a0)($v1)
/*  f14f7dc:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*  f14f7e0:	afbf001c */ 	sw	$ra,0x1c($sp)
/*  f14f7e4:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f14f7e8:	8c65000c */ 	lw	$a1,0xc($v1)
/*  f14f7ec:	00808025 */ 	or	$s0,$a0,$zero
/*  f14f7f0:	02002025 */ 	or	$a0,$s0,$zero
/*  f14f7f4:	18a00004 */ 	blez	$a1,.L0f14f808
/*  f14f7f8:	24aeffff */ 	addiu	$t6,$a1,-1
/*  f14f7fc:	ac6e000c */ 	sw	$t6,0xc($v1)
/*  f14f800:	1000002d */ 	b	.L0f14f8b8
/*  f14f804:	00001025 */ 	or	$v0,$zero,$zero
.L0f14f808:
/*  f14f808:	0fc53ddb */ 	jal	func0f14f76c
/*  f14f80c:	24050002 */ 	addiu	$a1,$zero,0x2
/*  f14f810:	14400009 */ 	bnez	$v0,.L0f14f838
/*  f14f814:	00403025 */ 	or	$a2,$v0,$zero
/*  f14f818:	02002025 */ 	or	$a0,$s0,$zero
/*  f14f81c:	0fc53ddb */ 	jal	func0f14f76c
/*  f14f820:	24050004 */ 	addiu	$a1,$zero,0x4
/*  f14f824:	3c0f800a */ 	lui	$t7,%hi(var800a45a0)
/*  f14f828:	8def45a0 */ 	lw	$t7,%lo(var800a45a0)($t7)
/*  f14f82c:	ade2000c */ 	sw	$v0,0xc($t7)
/*  f14f830:	10000021 */ 	b	.L0f14f8b8
/*  f14f834:	00001025 */ 	or	$v0,$zero,$zero
.L0f14f838:
/*  f14f838:	24010001 */ 	addiu	$at,$zero,0x1
/*  f14f83c:	14410006 */ 	bne	$v0,$at,.L0f14f858
/*  f14f840:	02002025 */ 	or	$a0,$s0,$zero
/*  f14f844:	02002025 */ 	or	$a0,$s0,$zero
/*  f14f848:	0fc53ddb */ 	jal	func0f14f76c
/*  f14f84c:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f14f850:	10000008 */ 	b	.L0f14f874
/*  f14f854:	24460001 */ 	addiu	$a2,$v0,0x1
.L0f14f858:
/*  f14f858:	24050002 */ 	addiu	$a1,$zero,0x2
/*  f14f85c:	0fc53ddb */ 	jal	func0f14f76c
/*  f14f860:	afa60024 */ 	sw	$a2,0x24($sp)
/*  f14f864:	8fa60024 */ 	lw	$a2,0x24($sp)
/*  f14f868:	0006c080 */ 	sll	$t8,$a2,0x2
/*  f14f86c:	00583021 */ 	addu	$a2,$v0,$t8
/*  f14f870:	24c6fffb */ 	addiu	$a2,$a2,-5
.L0f14f874:
/*  f14f874:	02002025 */ 	or	$a0,$s0,$zero
/*  f14f878:	00c02825 */ 	or	$a1,$a2,$zero
/*  f14f87c:	0fc53ddb */ 	jal	func0f14f76c
/*  f14f880:	afa60024 */ 	sw	$a2,0x24($sp)
/*  f14f884:	8fa60024 */ 	lw	$a2,0x24($sp)
/*  f14f888:	24080001 */ 	addiu	$t0,$zero,0x1
/*  f14f88c:	00401825 */ 	or	$v1,$v0,$zero
/*  f14f890:	24d9001f */ 	addiu	$t9,$a2,0x1f
/*  f14f894:	03284804 */ 	sllv	$t1,$t0,$t9
/*  f14f898:	01225024 */ 	and	$t2,$t1,$v0
/*  f14f89c:	11400003 */ 	beqz	$t2,.L0f14f8ac
/*  f14f8a0:	240b0001 */ 	addiu	$t3,$zero,0x1
/*  f14f8a4:	10000005 */ 	b	.L0f14f8bc
/*  f14f8a8:	8fbf001c */ 	lw	$ra,0x1c($sp)
.L0f14f8ac:
/*  f14f8ac:	00cb6004 */ 	sllv	$t4,$t3,$a2
/*  f14f8b0:	006c1023 */ 	subu	$v0,$v1,$t4
/*  f14f8b4:	24420001 */ 	addiu	$v0,$v0,0x1
.L0f14f8b8:
/*  f14f8b8:	8fbf001c */ 	lw	$ra,0x1c($sp)
.L0f14f8bc:
/*  f14f8bc:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f14f8c0:	27bd0028 */ 	addiu	$sp,$sp,0x28
/*  f14f8c4:	03e00008 */ 	jr	$ra
/*  f14f8c8:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel func0f14f8cc
/*  f14f8cc:	27bdffd0 */ 	addiu	$sp,$sp,-48
/*  f14f8d0:	afb40028 */ 	sw	$s4,0x28($sp)
/*  f14f8d4:	afb30024 */ 	sw	$s3,0x24($sp)
/*  f14f8d8:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f14f8dc:	afb20020 */ 	sw	$s2,0x20($sp)
/*  f14f8e0:	afb1001c */ 	sw	$s1,0x1c($sp)
/*  f14f8e4:	3c107f1b */ 	lui	$s0,%hi(var7f1b60a0)
/*  f14f8e8:	3c13800a */ 	lui	$s3,%hi(var800a45a0)
/*  f14f8ec:	3c147f1b */ 	lui	$s4,%hi(var7f1b62a0)
/*  f14f8f0:	00808825 */ 	or	$s1,$a0,$zero
/*  f14f8f4:	00a09025 */ 	or	$s2,$a1,$zero
/*  f14f8f8:	afbf002c */ 	sw	$ra,0x2c($sp)
/*  f14f8fc:	269462a0 */ 	addiu	$s4,$s4,%lo(var7f1b62a0)
/*  f14f900:	267345a0 */ 	addiu	$s3,$s3,%lo(var800a45a0)
/*  f14f904:	261060a0 */ 	addiu	$s0,$s0,%lo(var7f1b60a0)
.L0f14f908:
/*  f14f908:	0fc53df5 */ 	jal	func0f14f7d4
/*  f14f90c:	02202025 */ 	or	$a0,$s1,$zero
/*  f14f910:	8e030000 */ 	lw	$v1,0x0($s0)
/*  f14f914:	8e050004 */ 	lw	$a1,0x4($s0)
/*  f14f918:	8e6e0000 */ 	lw	$t6,0x0($s3)
/*  f14f91c:	00037940 */ 	sll	$t7,$v1,0x5
/*  f14f920:	00052080 */ 	sll	$a0,$a1,0x2
/*  f14f924:	01cfc021 */ 	addu	$t8,$t6,$t7
/*  f14f928:	0304c821 */ 	addu	$t9,$t8,$a0
/*  f14f92c:	8f28006c */ 	lw	$t0,0x6c($t9)
/*  f14f930:	00035140 */ 	sll	$t2,$v1,0x5
/*  f14f934:	024a5821 */ 	addu	$t3,$s2,$t2
/*  f14f938:	01020019 */ 	multu	$t0,$v0
/*  f14f93c:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f14f940:	01646021 */ 	addu	$t4,$t3,$a0
/*  f14f944:	00004812 */ 	mflo	$t1
/*  f14f948:	ad890000 */ 	sw	$t1,0x0($t4)
/*  f14f94c:	1614ffee */ 	bne	$s0,$s4,.L0f14f908
/*  f14f950:	00000000 */ 	nop
/*  f14f954:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*  f14f958:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f14f95c:	8fb1001c */ 	lw	$s1,0x1c($sp)
/*  f14f960:	8fb20020 */ 	lw	$s2,0x20($sp)
/*  f14f964:	8fb30024 */ 	lw	$s3,0x24($sp)
/*  f14f968:	8fb40028 */ 	lw	$s4,0x28($sp)
/*  f14f96c:	03e00008 */ 	jr	$ra
/*  f14f970:	27bd0030 */ 	addiu	$sp,$sp,0x30
);

GLOBAL_ASM(
glabel func0f14f974
/*  f14f974:	27bdffd0 */ 	addiu	$sp,$sp,-48
/*  f14f978:	afb10018 */ 	sw	$s1,0x18($sp)
/*  f14f97c:	00808825 */ 	or	$s1,$a0,$zero
/*  f14f980:	afbf001c */ 	sw	$ra,0x1c($sp)
/*  f14f984:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f14f988:	14a00008 */ 	bnez	$a1,.L0f14f9ac
/*  f14f98c:	afa50034 */ 	sw	$a1,0x34($sp)
/*  f14f990:	3c10800a */ 	lui	$s0,%hi(var800a45a0)
/*  f14f994:	261045a0 */ 	addiu	$s0,$s0,%lo(var800a45a0)
/*  f14f998:	8e020000 */ 	lw	$v0,0x0($s0)
/*  f14f99c:	8c4f0010 */ 	lw	$t7,0x10($v0)
/*  f14f9a0:	25f80001 */ 	addiu	$t8,$t7,0x1
/*  f14f9a4:	1000004f */ 	b	.L0f14fae4
/*  f14f9a8:	ac580010 */ 	sw	$t8,0x10($v0)
.L0f14f9ac:
/*  f14f9ac:	3c10800a */ 	lui	$s0,%hi(var800a45a0)
/*  f14f9b0:	261045a0 */ 	addiu	$s0,$s0,%lo(var800a45a0)
/*  f14f9b4:	8e190000 */ 	lw	$t9,0x0($s0)
/*  f14f9b8:	8f220010 */ 	lw	$v0,0x10($t9)
/*  f14f9bc:	5040001f */ 	beqzl	$v0,.L0f14fa3c
/*  f14f9c0:	8fae0034 */ 	lw	$t6,0x34($sp)
/*  f14f9c4:	1840001c */ 	blez	$v0,.L0f14fa38
/*  f14f9c8:	02202025 */ 	or	$a0,$s1,$zero
.L0f14f9cc:
/*  f14f9cc:	00002825 */ 	or	$a1,$zero,$zero
/*  f14f9d0:	0fc53dc0 */ 	jal	func0f14f700
/*  f14f9d4:	24060002 */ 	addiu	$a2,$zero,0x2
/*  f14f9d8:	8e080000 */ 	lw	$t0,0x0($s0)
/*  f14f9dc:	24060004 */ 	addiu	$a2,$zero,0x4
/*  f14f9e0:	02202025 */ 	or	$a0,$s1,$zero
/*  f14f9e4:	8d020010 */ 	lw	$v0,0x10($t0)
/*  f14f9e8:	2405000f */ 	addiu	$a1,$zero,0xf
/*  f14f9ec:	28410011 */ 	slti	$at,$v0,0x11
/*  f14f9f0:	10200007 */ 	beqz	$at,.L0f14fa10
/*  f14f9f4:	00000000 */ 	nop
/*  f14f9f8:	02202025 */ 	or	$a0,$s1,$zero
/*  f14f9fc:	0fc53dc0 */ 	jal	func0f14f700
/*  f14fa00:	2445ffff */ 	addiu	$a1,$v0,-1
/*  f14fa04:	8e090000 */ 	lw	$t1,0x0($s0)
/*  f14fa08:	10000007 */ 	b	.L0f14fa28
/*  f14fa0c:	ad200010 */ 	sw	$zero,0x10($t1)
.L0f14fa10:
/*  f14fa10:	0fc53dc0 */ 	jal	func0f14f700
/*  f14fa14:	24060004 */ 	addiu	$a2,$zero,0x4
/*  f14fa18:	8e020000 */ 	lw	$v0,0x0($s0)
/*  f14fa1c:	8c4a0010 */ 	lw	$t2,0x10($v0)
/*  f14fa20:	254bfff0 */ 	addiu	$t3,$t2,-16
/*  f14fa24:	ac4b0010 */ 	sw	$t3,0x10($v0)
.L0f14fa28:
/*  f14fa28:	8e0c0000 */ 	lw	$t4,0x0($s0)
/*  f14fa2c:	8d8d0010 */ 	lw	$t5,0x10($t4)
/*  f14fa30:	5da0ffe6 */ 	bgtzl	$t5,.L0f14f9cc
/*  f14fa34:	02202025 */ 	or	$a0,$s1,$zero
.L0f14fa38:
/*  f14fa38:	8fae0034 */ 	lw	$t6,0x34($sp)
.L0f14fa3c:
/*  f14fa3c:	8fa20034 */ 	lw	$v0,0x34($sp)
/*  f14fa40:	24100001 */ 	addiu	$s0,$zero,0x1
/*  f14fa44:	19c00003 */ 	blez	$t6,.L0f14fa54
/*  f14fa48:	00021023 */ 	negu	$v0,$v0
/*  f14fa4c:	10000001 */ 	b	.L0f14fa54
/*  f14fa50:	01c01025 */ 	or	$v0,$t6,$zero
.L0f14fa54:
/*  f14fa54:	28410002 */ 	slti	$at,$v0,0x2
/*  f14fa58:	14200006 */ 	bnez	$at,.L0f14fa74
/*  f14fa5c:	24070001 */ 	addiu	$a3,$zero,0x1
.L0f14fa60:
/*  f14fa60:	00107840 */ 	sll	$t7,$s0,0x1
/*  f14fa64:	25f00001 */ 	addiu	$s0,$t7,0x1
/*  f14fa68:	0202082a */ 	slt	$at,$s0,$v0
/*  f14fa6c:	1420fffc */ 	bnez	$at,.L0f14fa60
/*  f14fa70:	24e70001 */ 	addiu	$a3,$a3,0x1
.L0f14fa74:
/*  f14fa74:	28e10003 */ 	slti	$at,$a3,0x3
/*  f14fa78:	10200008 */ 	beqz	$at,.L0f14fa9c
/*  f14fa7c:	02202025 */ 	or	$a0,$s1,$zero
/*  f14fa80:	02202025 */ 	or	$a0,$s1,$zero
/*  f14fa84:	24e50001 */ 	addiu	$a1,$a3,0x1
/*  f14fa88:	24060003 */ 	addiu	$a2,$zero,0x3
/*  f14fa8c:	0fc53dc0 */ 	jal	func0f14f700
/*  f14fa90:	afa70024 */ 	sw	$a3,0x24($sp)
/*  f14fa94:	10000006 */ 	b	.L0f14fab0
/*  f14fa98:	8fa70024 */ 	lw	$a3,0x24($sp)
.L0f14fa9c:
/*  f14fa9c:	24e50005 */ 	addiu	$a1,$a3,0x5
/*  f14faa0:	24060004 */ 	addiu	$a2,$zero,0x4
/*  f14faa4:	0fc53dc0 */ 	jal	func0f14f700
/*  f14faa8:	afa70024 */ 	sw	$a3,0x24($sp)
/*  f14faac:	8fa70024 */ 	lw	$a3,0x24($sp)
.L0f14fab0:
/*  f14fab0:	8fb80034 */ 	lw	$t8,0x34($sp)
/*  f14fab4:	8fb90034 */ 	lw	$t9,0x34($sp)
/*  f14fab8:	02202025 */ 	or	$a0,$s1,$zero
/*  f14fabc:	1b000007 */ 	blez	$t8,.L0f14fadc
/*  f14fac0:	03302821 */ 	addu	$a1,$t9,$s0
/*  f14fac4:	02202025 */ 	or	$a0,$s1,$zero
/*  f14fac8:	03002825 */ 	or	$a1,$t8,$zero
/*  f14facc:	0fc53dc0 */ 	jal	func0f14f700
/*  f14fad0:	00e03025 */ 	or	$a2,$a3,$zero
/*  f14fad4:	10000004 */ 	b	.L0f14fae8
/*  f14fad8:	8fbf001c */ 	lw	$ra,0x1c($sp)
.L0f14fadc:
/*  f14fadc:	0fc53dc0 */ 	jal	func0f14f700
/*  f14fae0:	00e03025 */ 	or	$a2,$a3,$zero
.L0f14fae4:
/*  f14fae4:	8fbf001c */ 	lw	$ra,0x1c($sp)
.L0f14fae8:
/*  f14fae8:	8fb00014 */ 	lw	$s0,0x14($sp)
/*  f14faec:	8fb10018 */ 	lw	$s1,0x18($sp)
/*  f14faf0:	03e00008 */ 	jr	$ra
/*  f14faf4:	27bd0030 */ 	addiu	$sp,$sp,0x30
);

GLOBAL_ASM(
glabel func0f14faf8
/*  f14faf8:	27bdffc0 */ 	addiu	$sp,$sp,-64
/*  f14fafc:	afb20030 */ 	sw	$s2,0x30($sp)
/*  f14fb00:	afb1002c */ 	sw	$s1,0x2c($sp)
/*  f14fb04:	afb00028 */ 	sw	$s0,0x28($sp)
/*  f14fb08:	f7b60020 */ 	sdc1	$f22,0x20($sp)
/*  f14fb0c:	f7b40018 */ 	sdc1	$f20,0x18($sp)
/*  f14fb10:	3c013f00 */ 	lui	$at,0x3f00
/*  f14fb14:	afb40038 */ 	sw	$s4,0x38($sp)
/*  f14fb18:	afb30034 */ 	sw	$s3,0x34($sp)
/*  f14fb1c:	3c107f1b */ 	lui	$s0,%hi(var7f1b60a0)
/*  f14fb20:	3c11800a */ 	lui	$s1,%hi(var800a45a0)
/*  f14fb24:	3c127f1b */ 	lui	$s2,%hi(var7f1b62a0)
/*  f14fb28:	4481a000 */ 	mtc1	$at,$f20
/*  f14fb2c:	4480b000 */ 	mtc1	$zero,$f22
/*  f14fb30:	00a09825 */ 	or	$s3,$a1,$zero
/*  f14fb34:	0080a025 */ 	or	$s4,$a0,$zero
/*  f14fb38:	afbf003c */ 	sw	$ra,0x3c($sp)
/*  f14fb3c:	265262a0 */ 	addiu	$s2,$s2,%lo(var7f1b62a0)
/*  f14fb40:	263145a0 */ 	addiu	$s1,$s1,%lo(var800a45a0)
/*  f14fb44:	261060a0 */ 	addiu	$s0,$s0,%lo(var7f1b60a0)
/*  f14fb48:	8e020000 */ 	lw	$v0,0x0($s0)
.L0f14fb4c:
/*  f14fb4c:	8e040004 */ 	lw	$a0,0x4($s0)
/*  f14fb50:	8e2e0000 */ 	lw	$t6,0x0($s1)
/*  f14fb54:	00027940 */ 	sll	$t7,$v0,0x5
/*  f14fb58:	00024940 */ 	sll	$t1,$v0,0x5
/*  f14fb5c:	00041880 */ 	sll	$v1,$a0,0x2
/*  f14fb60:	02695021 */ 	addu	$t2,$s3,$t1
/*  f14fb64:	01cfc021 */ 	addu	$t8,$t6,$t7
/*  f14fb68:	0303c821 */ 	addu	$t9,$t8,$v1
/*  f14fb6c:	01435821 */ 	addu	$t3,$t2,$v1
/*  f14fb70:	8d6c0000 */ 	lw	$t4,0x0($t3)
/*  f14fb74:	8f28006c */ 	lw	$t0,0x6c($t9)
/*  f14fb78:	448c4000 */ 	mtc1	$t4,$f8
/*  f14fb7c:	44882000 */ 	mtc1	$t0,$f4
/*  f14fb80:	468042a0 */ 	cvt.s.w	$f10,$f8
/*  f14fb84:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f14fb88:	46065003 */ 	div.s	$f0,$f10,$f6
/*  f14fb8c:	4616003c */ 	c.lt.s	$f0,$f22
/*  f14fb90:	00000000 */ 	nop
/*  f14fb94:	45020007 */ 	bc1fl	.L0f14fbb4
/*  f14fb98:	46140100 */ 	add.s	$f4,$f0,$f20
/*  f14fb9c:	46140401 */ 	sub.s	$f16,$f0,$f20
/*  f14fba0:	4600848d */ 	trunc.w.s	$f18,$f16
/*  f14fba4:	44059000 */ 	mfc1	$a1,$f18
/*  f14fba8:	10000005 */ 	b	.L0f14fbc0
/*  f14fbac:	00000000 */ 	nop
/*  f14fbb0:	46140100 */ 	add.s	$f4,$f0,$f20
.L0f14fbb4:
/*  f14fbb4:	4600220d */ 	trunc.w.s	$f8,$f4
/*  f14fbb8:	44054000 */ 	mfc1	$a1,$f8
/*  f14fbbc:	00000000 */ 	nop
.L0f14fbc0:
/*  f14fbc0:	0fc53e5d */ 	jal	func0f14f974
/*  f14fbc4:	02802025 */ 	or	$a0,$s4,$zero
/*  f14fbc8:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f14fbcc:	5612ffdf */ 	bnel	$s0,$s2,.L0f14fb4c
/*  f14fbd0:	8e020000 */ 	lw	$v0,0x0($s0)
/*  f14fbd4:	8fbf003c */ 	lw	$ra,0x3c($sp)
/*  f14fbd8:	d7b40018 */ 	ldc1	$f20,0x18($sp)
/*  f14fbdc:	d7b60020 */ 	ldc1	$f22,0x20($sp)
/*  f14fbe0:	8fb00028 */ 	lw	$s0,0x28($sp)
/*  f14fbe4:	8fb1002c */ 	lw	$s1,0x2c($sp)
/*  f14fbe8:	8fb20030 */ 	lw	$s2,0x30($sp)
/*  f14fbec:	8fb30034 */ 	lw	$s3,0x34($sp)
/*  f14fbf0:	8fb40038 */ 	lw	$s4,0x38($sp)
/*  f14fbf4:	03e00008 */ 	jr	$ra
/*  f14fbf8:	27bd0040 */ 	addiu	$sp,$sp,0x40
);

GLOBAL_ASM(
glabel func0f14fbfc
/*  f14fbfc:	27bdfed0 */ 	addiu	$sp,$sp,-304
/*  f14fc00:	3c09800a */ 	lui	$t1,%hi(var800a45a0)
/*  f14fc04:	44801000 */ 	mtc1	$zero,$f2
/*  f14fc08:	afa50134 */ 	sw	$a1,0x134($sp)
/*  f14fc0c:	8d2945a0 */ 	lw	$t1,%lo(var800a45a0)($t1)
/*  f14fc10:	27a60030 */ 	addiu	$a2,$sp,0x30
/*  f14fc14:	00003825 */ 	or	$a3,$zero,$zero
/*  f14fc18:	00804025 */ 	or	$t0,$a0,$zero
/*  f14fc1c:	240b0020 */ 	addiu	$t3,$zero,0x20
/*  f14fc20:	240a0008 */ 	addiu	$t2,$zero,0x8
.L0f14fc24:
/*  f14fc24:	00002025 */ 	or	$a0,$zero,$zero
/*  f14fc28:	00c01025 */ 	or	$v0,$a2,$zero
.L0f14fc2c:
/*  f14fc2c:	e4420000 */ 	swc1	$f2,0x0($v0)
/*  f14fc30:	00001825 */ 	or	$v1,$zero,$zero
/*  f14fc34:	01242821 */ 	addu	$a1,$t1,$a0
/*  f14fc38:	8d0e0000 */ 	lw	$t6,0x0($t0)
/*  f14fc3c:	c4b0027c */ 	lwc1	$f16,0x27c($a1)
/*  f14fc40:	254affff */ 	addiu	$t2,$t2,-1
/*  f14fc44:	01c37821 */ 	addu	$t7,$t6,$v1
/*  f14fc48:	91f80000 */ 	lbu	$t8,0x0($t7)
/*  f14fc4c:	2719ff80 */ 	addiu	$t9,$t8,-128
/*  f14fc50:	44997000 */ 	mtc1	$t9,$f14
/*  f14fc54:	00000000 */ 	nop
/*  f14fc58:	468073a0 */ 	cvt.s.w	$f14,$f14
/*  f14fc5c:	46107482 */ 	mul.s	$f18,$f14,$f16
/*  f14fc60:	506a0012 */ 	beql	$v1,$t2,.L0f14fcac
/*  f14fc64:	c4500000 */ 	lwc1	$f16,0x0($v0)
/*  f14fc68:	c4500000 */ 	lwc1	$f16,0x0($v0)
.L0f14fc6c:
/*  f14fc6c:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f14fc70:	24a50020 */ 	addiu	$a1,$a1,0x20
/*  f14fc74:	46128400 */ 	add.s	$f16,$f16,$f18
/*  f14fc78:	e4500000 */ 	swc1	$f16,0x0($v0)
/*  f14fc7c:	8d0e0000 */ 	lw	$t6,0x0($t0)
/*  f14fc80:	c4b0027c */ 	lwc1	$f16,0x27c($a1)
/*  f14fc84:	01c37821 */ 	addu	$t7,$t6,$v1
/*  f14fc88:	91f80000 */ 	lbu	$t8,0x0($t7)
/*  f14fc8c:	2719ff80 */ 	addiu	$t9,$t8,-128
/*  f14fc90:	44997000 */ 	mtc1	$t9,$f14
/*  f14fc94:	00000000 */ 	nop
/*  f14fc98:	468073a0 */ 	cvt.s.w	$f14,$f14
/*  f14fc9c:	46107482 */ 	mul.s	$f18,$f14,$f16
/*  f14fca0:	546afff2 */ 	bnel	$v1,$t2,.L0f14fc6c
/*  f14fca4:	c4500000 */ 	lwc1	$f16,0x0($v0)
/*  f14fca8:	c4500000 */ 	lwc1	$f16,0x0($v0)
.L0f14fcac:
/*  f14fcac:	254a0001 */ 	addiu	$t2,$t2,0x1
/*  f14fcb0:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f14fcb4:	46128400 */ 	add.s	$f16,$f16,$f18
/*  f14fcb8:	24a50020 */ 	addiu	$a1,$a1,0x20
/*  f14fcbc:	e4500000 */ 	swc1	$f16,0x0($v0)
/*  f14fcc0:	24840004 */ 	addiu	$a0,$a0,0x4
/*  f14fcc4:	148bffd9 */ 	bne	$a0,$t3,.L0f14fc2c
/*  f14fcc8:	24420004 */ 	addiu	$v0,$v0,0x4
/*  f14fccc:	24e70004 */ 	addiu	$a3,$a3,0x4
/*  f14fcd0:	28e10020 */ 	slti	$at,$a3,0x20
/*  f14fcd4:	24c60020 */ 	addiu	$a2,$a2,0x20
/*  f14fcd8:	1420ffd2 */ 	bnez	$at,.L0f14fc24
/*  f14fcdc:	25080004 */ 	addiu	$t0,$t0,0x4
/*  f14fce0:	3c013f00 */ 	lui	$at,0x3f00
/*  f14fce4:	44816000 */ 	mtc1	$at,$f12
/*  f14fce8:	00001025 */ 	or	$v0,$zero,$zero
/*  f14fcec:	8fa70134 */ 	lw	$a3,0x134($sp)
/*  f14fcf0:	24090020 */ 	addiu	$t1,$zero,0x20
.L0f14fcf4:
/*  f14fcf4:	00002025 */ 	or	$a0,$zero,$zero
/*  f14fcf8:	00e04025 */ 	or	$t0,$a3,$zero
.L0f14fcfc:
/*  f14fcfc:	3c0c800a */ 	lui	$t4,%hi(var800a45a0)
/*  f14fd00:	8d8c45a0 */ 	lw	$t4,%lo(var800a45a0)($t4)
/*  f14fd04:	00026940 */ 	sll	$t5,$v0,0x5
/*  f14fd08:	27ae0030 */ 	addiu	$t6,$sp,0x30
/*  f14fd0c:	46001006 */ 	mov.s	$f0,$f2
/*  f14fd10:	008e3021 */ 	addu	$a2,$a0,$t6
/*  f14fd14:	00001825 */ 	or	$v1,$zero,$zero
/*  f14fd18:	018d2821 */ 	addu	$a1,$t4,$t5
/*  f14fd1c:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f14fd20:	c4b2017c */ 	lwc1	$f18,0x17c($a1)
/*  f14fd24:	106a0009 */ 	beq	$v1,$t2,.L0f14fd4c
/*  f14fd28:	c4d00000 */ 	lwc1	$f16,0x0($a2)
.L0f14fd2c:
/*  f14fd2c:	46109382 */ 	mul.s	$f14,$f18,$f16
/*  f14fd30:	c4b20180 */ 	lwc1	$f18,0x180($a1)
/*  f14fd34:	24c60020 */ 	addiu	$a2,$a2,0x20
/*  f14fd38:	c4d00000 */ 	lwc1	$f16,0x0($a2)
/*  f14fd3c:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f14fd40:	24a50004 */ 	addiu	$a1,$a1,0x4
/*  f14fd44:	146afff9 */ 	bne	$v1,$t2,.L0f14fd2c
/*  f14fd48:	460e0000 */ 	add.s	$f0,$f0,$f14
.L0f14fd4c:
/*  f14fd4c:	46109382 */ 	mul.s	$f14,$f18,$f16
/*  f14fd50:	24c60020 */ 	addiu	$a2,$a2,0x20
/*  f14fd54:	24a50004 */ 	addiu	$a1,$a1,0x4
/*  f14fd58:	460e0000 */ 	add.s	$f0,$f0,$f14
/*  f14fd5c:	4602003c */ 	c.lt.s	$f0,$f2
/*  f14fd60:	24840004 */ 	addiu	$a0,$a0,0x4
/*  f14fd64:	45020007 */ 	bc1fl	.L0f14fd84
/*  f14fd68:	460c0480 */ 	add.s	$f18,$f0,$f12
/*  f14fd6c:	460c0401 */ 	sub.s	$f16,$f0,$f12
/*  f14fd70:	4600828d */ 	trunc.w.s	$f10,$f16
/*  f14fd74:	44185000 */ 	mfc1	$t8,$f10
/*  f14fd78:	10000006 */ 	b	.L0f14fd94
/*  f14fd7c:	ad180000 */ 	sw	$t8,0x0($t0)
/*  f14fd80:	460c0480 */ 	add.s	$f18,$f0,$f12
.L0f14fd84:
/*  f14fd84:	4600910d */ 	trunc.w.s	$f4,$f18
/*  f14fd88:	440c2000 */ 	mfc1	$t4,$f4
/*  f14fd8c:	00000000 */ 	nop
/*  f14fd90:	ad0c0000 */ 	sw	$t4,0x0($t0)
.L0f14fd94:
/*  f14fd94:	1489ffd9 */ 	bne	$a0,$t1,.L0f14fcfc
/*  f14fd98:	25080004 */ 	addiu	$t0,$t0,0x4
/*  f14fd9c:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f14fda0:	144affd4 */ 	bne	$v0,$t2,.L0f14fcf4
/*  f14fda4:	24e70020 */ 	addiu	$a3,$a3,0x20
/*  f14fda8:	03e00008 */ 	jr	$ra
/*  f14fdac:	27bd0130 */ 	addiu	$sp,$sp,0x130
);

GLOBAL_ASM(
glabel func0f14fdb0
/*  f14fdb0:	27bdfed0 */ 	addiu	$sp,$sp,-304
/*  f14fdb4:	3c08800a */ 	lui	$t0,%hi(var800a45a0)
/*  f14fdb8:	44801000 */ 	mtc1	$zero,$f2
/*  f14fdbc:	afa50134 */ 	sw	$a1,0x134($sp)
/*  f14fdc0:	8d0845a0 */ 	lw	$t0,%lo(var800a45a0)($t0)
/*  f14fdc4:	27a60030 */ 	addiu	$a2,$sp,0x30
/*  f14fdc8:	27ac0130 */ 	addiu	$t4,$sp,0x130
/*  f14fdcc:	00803825 */ 	or	$a3,$a0,$zero
/*  f14fdd0:	240b0020 */ 	addiu	$t3,$zero,0x20
/*  f14fdd4:	240a0008 */ 	addiu	$t2,$zero,0x8
.L0f14fdd8:
/*  f14fdd8:	00002025 */ 	or	$a0,$zero,$zero
/*  f14fddc:	00c01025 */ 	or	$v0,$a2,$zero
.L0f14fde0:
/*  f14fde0:	e4420000 */ 	swc1	$f2,0x0($v0)
/*  f14fde4:	00002825 */ 	or	$a1,$zero,$zero
/*  f14fde8:	00e01825 */ 	or	$v1,$a3,$zero
/*  f14fdec:	01044821 */ 	addu	$t1,$t0,$a0
/*  f14fdf0:	8c6e0000 */ 	lw	$t6,0x0($v1)
/*  f14fdf4:	c52e017c */ 	lwc1	$f14,0x17c($t1)
/*  f14fdf8:	24a50001 */ 	addiu	$a1,$a1,0x1
/*  f14fdfc:	448e6000 */ 	mtc1	$t6,$f12
/*  f14fe00:	c4500000 */ 	lwc1	$f16,0x0($v0)
/*  f14fe04:	46806320 */ 	cvt.s.w	$f12,$f12
/*  f14fe08:	460e6482 */ 	mul.s	$f18,$f12,$f14
/*  f14fe0c:	50aa0010 */ 	beql	$a1,$t2,.L0f14fe50
/*  f14fe10:	46128380 */ 	add.s	$f14,$f16,$f18
/*  f14fe14:	46128380 */ 	add.s	$f14,$f16,$f18
.L0f14fe18:
/*  f14fe18:	24a50001 */ 	addiu	$a1,$a1,0x1
/*  f14fe1c:	24630004 */ 	addiu	$v1,$v1,0x4
/*  f14fe20:	25290020 */ 	addiu	$t1,$t1,0x20
/*  f14fe24:	e44e0000 */ 	swc1	$f14,0x0($v0)
/*  f14fe28:	8c6e0000 */ 	lw	$t6,0x0($v1)
/*  f14fe2c:	c52e017c */ 	lwc1	$f14,0x17c($t1)
/*  f14fe30:	c4500000 */ 	lwc1	$f16,0x0($v0)
/*  f14fe34:	448e6000 */ 	mtc1	$t6,$f12
/*  f14fe38:	00000000 */ 	nop
/*  f14fe3c:	46806320 */ 	cvt.s.w	$f12,$f12
/*  f14fe40:	460e6482 */ 	mul.s	$f18,$f12,$f14
/*  f14fe44:	54aafff4 */ 	bnel	$a1,$t2,.L0f14fe18
/*  f14fe48:	46128380 */ 	add.s	$f14,$f16,$f18
/*  f14fe4c:	46128380 */ 	add.s	$f14,$f16,$f18
.L0f14fe50:
/*  f14fe50:	24630004 */ 	addiu	$v1,$v1,0x4
/*  f14fe54:	25290020 */ 	addiu	$t1,$t1,0x20
/*  f14fe58:	e44e0000 */ 	swc1	$f14,0x0($v0)
/*  f14fe5c:	24840004 */ 	addiu	$a0,$a0,0x4
/*  f14fe60:	148bffdf */ 	bne	$a0,$t3,.L0f14fde0
/*  f14fe64:	24420004 */ 	addiu	$v0,$v0,0x4
/*  f14fe68:	24c60020 */ 	addiu	$a2,$a2,0x20
/*  f14fe6c:	00cc082b */ 	sltu	$at,$a2,$t4
/*  f14fe70:	1420ffd9 */ 	bnez	$at,.L0f14fdd8
/*  f14fe74:	24e70020 */ 	addiu	$a3,$a3,0x20
/*  f14fe78:	3c013f00 */ 	lui	$at,0x3f00
/*  f14fe7c:	44818000 */ 	mtc1	$at,$f16
/*  f14fe80:	3c01437f */ 	lui	$at,0x437f
/*  f14fe84:	44817000 */ 	mtc1	$at,$f14
/*  f14fe88:	3c014300 */ 	lui	$at,0x4300
/*  f14fe8c:	44816000 */ 	mtc1	$at,$f12
/*  f14fe90:	00001025 */ 	or	$v0,$zero,$zero
/*  f14fe94:	8fa80134 */ 	lw	$t0,0x134($sp)
.L0f14fe98:
/*  f14fe98:	00001825 */ 	or	$v1,$zero,$zero
/*  f14fe9c:	00002025 */ 	or	$a0,$zero,$zero
.L0f14fea0:
/*  f14fea0:	3c0f800a */ 	lui	$t7,%hi(var800a45a0)
/*  f14fea4:	8def45a0 */ 	lw	$t7,%lo(var800a45a0)($t7)
/*  f14fea8:	0002c140 */ 	sll	$t8,$v0,0x5
/*  f14feac:	27b90030 */ 	addiu	$t9,$sp,0x30
/*  f14feb0:	46001006 */ 	mov.s	$f0,$f2
/*  f14feb4:	00993821 */ 	addu	$a3,$a0,$t9
/*  f14feb8:	00002825 */ 	or	$a1,$zero,$zero
/*  f14febc:	01f83021 */ 	addu	$a2,$t7,$t8
/*  f14fec0:	24a50001 */ 	addiu	$a1,$a1,0x1
/*  f14fec4:	c4ea0000 */ 	lwc1	$f10,0x0($a3)
/*  f14fec8:	10aa0009 */ 	beq	$a1,$t2,.L0f14fef0
/*  f14fecc:	c4d2027c */ 	lwc1	$f18,0x27c($a2)
.L0f14fed0:
/*  f14fed0:	460a9202 */ 	mul.s	$f8,$f18,$f10
/*  f14fed4:	c4ea0020 */ 	lwc1	$f10,0x20($a3)
/*  f14fed8:	24c60004 */ 	addiu	$a2,$a2,0x4
/*  f14fedc:	c4d2027c */ 	lwc1	$f18,0x27c($a2)
/*  f14fee0:	24a50001 */ 	addiu	$a1,$a1,0x1
/*  f14fee4:	24e70020 */ 	addiu	$a3,$a3,0x20
/*  f14fee8:	14aafff9 */ 	bne	$a1,$t2,.L0f14fed0
/*  f14feec:	46080000 */ 	add.s	$f0,$f0,$f8
.L0f14fef0:
/*  f14fef0:	460a9202 */ 	mul.s	$f8,$f18,$f10
/*  f14fef4:	24c60004 */ 	addiu	$a2,$a2,0x4
/*  f14fef8:	24e70020 */ 	addiu	$a3,$a3,0x20
/*  f14fefc:	46080000 */ 	add.s	$f0,$f0,$f8
/*  f14ff00:	460c0000 */ 	add.s	$f0,$f0,$f12
/*  f14ff04:	4600703c */ 	c.lt.s	$f14,$f0
/*  f14ff08:	00000000 */ 	nop
/*  f14ff0c:	45020003 */ 	bc1fl	.L0f14ff1c
/*  f14ff10:	4602003c */ 	c.lt.s	$f0,$f2
/*  f14ff14:	46007006 */ 	mov.s	$f0,$f14
/*  f14ff18:	4602003c */ 	c.lt.s	$f0,$f2
.L0f14ff1c:
/*  f14ff1c:	00000000 */ 	nop
/*  f14ff20:	45020003 */ 	bc1fl	.L0f14ff30
/*  f14ff24:	4602003c */ 	c.lt.s	$f0,$f2
/*  f14ff28:	46001006 */ 	mov.s	$f0,$f2
/*  f14ff2c:	4602003c */ 	c.lt.s	$f0,$f2
.L0f14ff30:
/*  f14ff30:	00000000 */ 	nop
/*  f14ff34:	45020009 */ 	bc1fl	.L0f14ff5c
/*  f14ff38:	46100180 */ 	add.s	$f6,$f0,$f16
/*  f14ff3c:	46100281 */ 	sub.s	$f10,$f0,$f16
/*  f14ff40:	8d0f0000 */ 	lw	$t7,0x0($t0)
/*  f14ff44:	4600510d */ 	trunc.w.s	$f4,$f10
/*  f14ff48:	01e3c021 */ 	addu	$t8,$t7,$v1
/*  f14ff4c:	440e2000 */ 	mfc1	$t6,$f4
/*  f14ff50:	10000008 */ 	b	.L0f14ff74
/*  f14ff54:	a30e0000 */ 	sb	$t6,0x0($t8)
/*  f14ff58:	46100180 */ 	add.s	$f6,$f0,$f16
.L0f14ff5c:
/*  f14ff5c:	8d0f0000 */ 	lw	$t7,0x0($t0)
/*  f14ff60:	4600320d */ 	trunc.w.s	$f8,$f6
/*  f14ff64:	01e37021 */ 	addu	$t6,$t7,$v1
/*  f14ff68:	440d4000 */ 	mfc1	$t5,$f8
/*  f14ff6c:	00000000 */ 	nop
/*  f14ff70:	a1cd0000 */ 	sb	$t5,0x0($t6)
.L0f14ff74:
/*  f14ff74:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f14ff78:	146affc9 */ 	bne	$v1,$t2,.L0f14fea0
/*  f14ff7c:	24840004 */ 	addiu	$a0,$a0,0x4
/*  f14ff80:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f14ff84:	144affc4 */ 	bne	$v0,$t2,.L0f14fe98
/*  f14ff88:	25080004 */ 	addiu	$t0,$t0,4
/*  f14ff8c:	03e00008 */ 	jr	$ra
/*  f14ff90:	27bd0130 */ 	addiu	$sp,$sp,0x130
);

GLOBAL_ASM(
glabel func0f14ff94
/*  f14ff94:	27bdfe90 */ 	addiu	$sp,$sp,-368
/*  f14ff98:	afbf0034 */ 	sw	$ra,0x34($sp)
/*  f14ff9c:	afb20020 */ 	sw	$s2,0x20($sp)
/*  f14ffa0:	00809025 */ 	or	$s2,$a0,$zero
/*  f14ffa4:	afb60030 */ 	sw	$s6,0x30($sp)
/*  f14ffa8:	afb5002c */ 	sw	$s5,0x2c($sp)
/*  f14ffac:	afb40028 */ 	sw	$s4,0x28($sp)
/*  f14ffb0:	afb30024 */ 	sw	$s3,0x24($sp)
/*  f14ffb4:	afb1001c */ 	sw	$s1,0x1c($sp)
/*  f14ffb8:	0fc53d2e */ 	jal	func0f14f4b8
/*  f14ffbc:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f14ffc0:	02402025 */ 	or	$a0,$s2,$zero
/*  f14ffc4:	0fc53ddb */ 	jal	func0f14f76c
/*  f14ffc8:	24050008 */ 	addiu	$a1,$zero,0x8
/*  f14ffcc:	0fc53d44 */ 	jal	func0f14f510
/*  f14ffd0:	00402025 */ 	or	$a0,$v0,$zero
/*  f14ffd4:	27b10060 */ 	addiu	$s1,$sp,0x60
/*  f14ffd8:	02209825 */ 	or	$s3,$s1,$zero
/*  f14ffdc:	0000b025 */ 	or	$s6,$zero,$zero
/*  f14ffe0:	27b50040 */ 	addiu	$s5,$sp,0x40
/*  f14ffe4:	24140040 */ 	addiu	$s4,$zero,0x40
/*  f14ffe8:	00008025 */ 	or	$s0,$zero,$zero
.L0f14ffec:
/*  f14ffec:	02402025 */ 	or	$a0,$s2,$zero
.L0f14fff0:
/*  f14fff0:	0fc53e33 */ 	jal	func0f14f8cc
/*  f14fff4:	02602825 */ 	or	$a1,$s3,$zero
/*  f14fff8:	27a20040 */ 	addiu	$v0,$sp,0x40
/*  f14fffc:	00161980 */ 	sll	$v1,$s6,0x6
.L0f150000:
/*  f150000:	8e4f001c */ 	lw	$t7,0x1c($s2)
/*  f150004:	24420004 */ 	addiu	$v0,$v0,0x4
/*  f150008:	01e3c021 */ 	addu	$t8,$t7,$v1
/*  f15000c:	0310c821 */ 	addu	$t9,$t8,$s0
/*  f150010:	24630040 */ 	addiu	$v1,$v1,0x40
/*  f150014:	1451fffa */ 	bne	$v0,$s1,.L0f150000
/*  f150018:	ac59fffc */ 	sw	$t9,-0x4($v0)
/*  f15001c:	02602025 */ 	or	$a0,$s3,$zero
/*  f150020:	0fc53f6c */ 	jal	func0f14fdb0
/*  f150024:	02a02825 */ 	or	$a1,$s5,$zero
/*  f150028:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f15002c:	5614fff0 */ 	bnel	$s0,$s4,.L0f14fff0
/*  f150030:	02402025 */ 	or	$a0,$s2,$zero
/*  f150034:	26d60008 */ 	addiu	$s6,$s6,0x8
/*  f150038:	56d4ffec */ 	bnel	$s6,$s4,.L0f14ffec
/*  f15003c:	00008025 */ 	or	$s0,$zero,$zero
/*  f150040:	8fbf0034 */ 	lw	$ra,0x34($sp)
/*  f150044:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f150048:	8fb1001c */ 	lw	$s1,0x1c($sp)
/*  f15004c:	8fb20020 */ 	lw	$s2,0x20($sp)
/*  f150050:	8fb30024 */ 	lw	$s3,0x24($sp)
/*  f150054:	8fb40028 */ 	lw	$s4,0x28($sp)
/*  f150058:	8fb5002c */ 	lw	$s5,0x2c($sp)
/*  f15005c:	8fb60030 */ 	lw	$s6,0x30($sp)
/*  f150060:	03e00008 */ 	jr	$ra
/*  f150064:	27bd0170 */ 	addiu	$sp,$sp,0x170
);

GLOBAL_ASM(
glabel func0f150068
/*  f150068:	27bdfe90 */ 	addiu	$sp,$sp,-368
/*  f15006c:	afbf0034 */ 	sw	$ra,0x34($sp)
/*  f150070:	afb20020 */ 	sw	$s2,0x20($sp)
/*  f150074:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f150078:	00a08025 */ 	or	$s0,$a1,$zero
/*  f15007c:	00809025 */ 	or	$s2,$a0,$zero
/*  f150080:	afb60030 */ 	sw	$s6,0x30($sp)
/*  f150084:	afb5002c */ 	sw	$s5,0x2c($sp)
/*  f150088:	afb40028 */ 	sw	$s4,0x28($sp)
/*  f15008c:	afb30024 */ 	sw	$s3,0x24($sp)
/*  f150090:	0fc53d39 */ 	jal	func0f14f4e4
/*  f150094:	afb1001c */ 	sw	$s1,0x1c($sp)
/*  f150098:	0fc53d44 */ 	jal	func0f14f510
/*  f15009c:	02002025 */ 	or	$a0,$s0,$zero
/*  f1500a0:	02402025 */ 	or	$a0,$s2,$zero
/*  f1500a4:	02002825 */ 	or	$a1,$s0,$zero
/*  f1500a8:	0fc53dc0 */ 	jal	func0f14f700
/*  f1500ac:	24060008 */ 	addiu	$a2,$zero,0x8
/*  f1500b0:	27b10064 */ 	addiu	$s1,$sp,0x64
/*  f1500b4:	02209825 */ 	or	$s3,$s1,$zero
/*  f1500b8:	0000b025 */ 	or	$s6,$zero,$zero
/*  f1500bc:	27b50044 */ 	addiu	$s5,$sp,0x44
/*  f1500c0:	24140040 */ 	addiu	$s4,$zero,0x40
/*  f1500c4:	00008025 */ 	or	$s0,$zero,$zero
.L0f1500c8:
/*  f1500c8:	27a20044 */ 	addiu	$v0,$sp,0x44
.L0f1500cc:
/*  f1500cc:	00161980 */ 	sll	$v1,$s6,0x6
.L0f1500d0:
/*  f1500d0:	8e4f001c */ 	lw	$t7,0x1c($s2)
/*  f1500d4:	24420004 */ 	addiu	$v0,$v0,0x4
/*  f1500d8:	01e3c021 */ 	addu	$t8,$t7,$v1
/*  f1500dc:	0310c821 */ 	addu	$t9,$t8,$s0
/*  f1500e0:	24630040 */ 	addiu	$v1,$v1,0x40
/*  f1500e4:	1451fffa */ 	bne	$v0,$s1,.L0f1500d0
/*  f1500e8:	ac59fffc */ 	sw	$t9,-0x4($v0)
/*  f1500ec:	02a02025 */ 	or	$a0,$s5,$zero
/*  f1500f0:	0fc53eff */ 	jal	func0f14fbfc
/*  f1500f4:	02602825 */ 	or	$a1,$s3,$zero
/*  f1500f8:	02402025 */ 	or	$a0,$s2,$zero
/*  f1500fc:	0fc53ebe */ 	jal	func0f14faf8
/*  f150100:	02602825 */ 	or	$a1,$s3,$zero
/*  f150104:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f150108:	5614fff0 */ 	bnel	$s0,$s4,.L0f1500cc
/*  f15010c:	27a20044 */ 	addiu	$v0,$sp,0x44
/*  f150110:	26d60008 */ 	addiu	$s6,$s6,0x8
/*  f150114:	56d4ffec */ 	bnel	$s6,$s4,.L0f1500c8
/*  f150118:	00008025 */ 	or	$s0,$zero,$zero
/*  f15011c:	02402025 */ 	or	$a0,$s2,$zero
/*  f150120:	0fc53e5d */ 	jal	func0f14f974
/*  f150124:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f150128:	8e48002c */ 	lw	$t0,0x2c($s2)
/*  f15012c:	000848c2 */ 	srl	$t1,$t0,0x3
/*  f150130:	a6490034 */ 	sh	$t1,0x34($s2)
/*  f150134:	8fbf0034 */ 	lw	$ra,0x34($sp)
/*  f150138:	8fb60030 */ 	lw	$s6,0x30($sp)
/*  f15013c:	8fb5002c */ 	lw	$s5,0x2c($sp)
/*  f150140:	8fb40028 */ 	lw	$s4,0x28($sp)
/*  f150144:	8fb30024 */ 	lw	$s3,0x24($sp)
/*  f150148:	8fb20020 */ 	lw	$s2,0x20($sp)
/*  f15014c:	8fb1001c */ 	lw	$s1,0x1c($sp)
/*  f150150:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f150154:	03e00008 */ 	jr	$ra
/*  f150158:	27bd0170 */ 	addiu	$sp,$sp,0x170
);

const char var7f1b7158[] = "camdraw.c";
const char var7f1b7164[] = "camdraw.c";
const char var7f1b7170[] = "Cam -> Compressing Editor Slot\n";
const char var7f1b7190[] = "Cam -> Trying image compression at quality %u\n";
const char var7f1b71c0[] = "Cam -> Failed - Too big - This=%u, Max=%d\n";
const char var7f1b71ec[] = "Cam -> Trying lower quality setting\n";
const char var7f1b7214[] = "Cam -> Save Failed - Cant get it small enough - oo-er\n";
const char var7f1b724c[] = "Cam -> Sucess at quality %u - Size=%u, Max=%d\n";
const char var7f1b727c[] = "\nCam_SaveEditSlotToParamPakItem -> Save failed\n";
const char var7f1b72ac[] = "Camera Save Error Result: %d\n";
const char var7f1b72cc[] = "Magic Guid set to %d\n";

GLOBAL_ASM(
glabel func0f15015c
/*  f15015c:	27bdfb20 */ 	addiu	$sp,$sp,-1248
/*  f150160:	afbf0024 */ 	sw	$ra,0x24($sp)
/*  f150164:	afa404e0 */ 	sw	$a0,0x4e0($sp)
/*  f150168:	afa604e8 */ 	sw	$a2,0x4e8($sp)
/*  f15016c:	00047600 */ 	sll	$t6,$a0,0x18
/*  f150170:	000e2603 */ 	sra	$a0,$t6,0x18
/*  f150174:	afb20020 */ 	sw	$s2,0x20($sp)
/*  f150178:	afb1001c */ 	sw	$s1,0x1c($sp)
/*  f15017c:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f150180:	27a60040 */ 	addiu	$a2,$sp,0x40
/*  f150184:	0fc45a00 */ 	jal	pakReadBodyAtGuid
/*  f150188:	24070080 */ 	addiu	$a3,$zero,0x80
/*  f15018c:	1440000b */ 	bnez	$v0,.L0f1501bc
/*  f150190:	8fa504e8 */ 	lw	$a1,0x4e8($sp)
/*  f150194:	00a01825 */ 	or	$v1,$a1,$zero
/*  f150198:	27a20040 */ 	addiu	$v0,$sp,0x40
/*  f15019c:	27a400c0 */ 	addiu	$a0,$sp,0xc0
.L0f1501a0:
/*  f1501a0:	90580000 */ 	lbu	$t8,0x0($v0)
/*  f1501a4:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f1501a8:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f1501ac:	1444fffc */ 	bne	$v0,$a0,.L0f1501a0
/*  f1501b0:	a078ffff */ 	sb	$t8,-0x1($v1)
/*  f1501b4:	10000010 */ 	b	.L0f1501f8
/*  f1501b8:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f1501bc:
/*  f1501bc:	2401000a */ 	addiu	$at,$zero,0xa
/*  f1501c0:	1441000c */ 	bne	$v0,$at,.L0f1501f4
/*  f1501c4:	24120080 */ 	addiu	$s2,$zero,0x80
/*  f1501c8:	00008025 */ 	or	$s0,$zero,$zero
/*  f1501cc:	00a08825 */ 	or	$s1,$a1,$zero
.L0f1501d0:
/*  f1501d0:	0c004b70 */ 	jal	random
/*  f1501d4:	00000000 */ 	nop
/*  f1501d8:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f1501dc:	0212082a */ 	slt	$at,$s0,$s2
/*  f1501e0:	26310001 */ 	addiu	$s1,$s1,0x1
/*  f1501e4:	1420fffa */ 	bnez	$at,.L0f1501d0
/*  f1501e8:	a222ffff */ 	sb	$v0,-0x1($s1)
/*  f1501ec:	10000002 */ 	b	.L0f1501f8
/*  f1501f0:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f1501f4:
/*  f1501f4:	00001025 */ 	or	$v0,$zero,$zero
.L0f1501f8:
/*  f1501f8:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*  f1501fc:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f150200:	8fb1001c */ 	lw	$s1,0x1c($sp)
/*  f150204:	8fb20020 */ 	lw	$s2,0x20($sp)
/*  f150208:	03e00008 */ 	jr	$ra
/*  f15020c:	27bd04e0 */ 	addiu	$sp,$sp,0x4e0
/*  f150210:	27bdfb20 */ 	addiu	$sp,$sp,-1248
/*  f150214:	2401ffff */ 	addiu	$at,$zero,-1
/*  f150218:	afbf001c */ 	sw	$ra,0x1c($sp)
/*  f15021c:	afb10018 */ 	sw	$s1,0x18($sp)
/*  f150220:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f150224:	afa404e0 */ 	sw	$a0,0x4e0($sp)
/*  f150228:	afa504e4 */ 	sw	$a1,0x4e4($sp)
/*  f15022c:	14e10003 */ 	bne	$a3,$at,.L0f15023c
/*  f150230:	afa604e8 */ 	sw	$a2,0x4e8($sp)
/*  f150234:	10000002 */ 	b	.L0f150240
/*  f150238:	2404ffff */ 	addiu	$a0,$zero,-1
.L0f15023c:
/*  f15023c:	00e02025 */ 	or	$a0,$a3,$zero
.L0f150240:
/*  f150240:	0fc5281b */ 	jal	func0f14a06c
/*  f150244:	00000000 */ 	nop
/*  f150248:	00408025 */ 	or	$s0,$v0,$zero
/*  f15024c:	0fc5281b */ 	jal	func0f14a06c
/*  f150250:	2404ffff */ 	addiu	$a0,$zero,-1
/*  f150254:	00408825 */ 	or	$s1,$v0,$zero
/*  f150258:	83a404e3 */ 	lb	$a0,0x4e3($sp)
/*  f15025c:	8fa504e4 */ 	lw	$a1,0x4e4($sp)
/*  f150260:	27a60038 */ 	addiu	$a2,$sp,0x38
/*  f150264:	0fc45a00 */ 	jal	pakReadBodyAtGuid
/*  f150268:	00003825 */ 	or	$a3,$zero,$zero
/*  f15026c:	14400076 */ 	bnez	$v0,.L0f150448
/*  f150270:	00401825 */ 	or	$v1,$v0,$zero
/*  f150274:	8fae04e4 */ 	lw	$t6,0x4e4($sp)
/*  f150278:	ae0e03f8 */ 	sw	$t6,0x3f8($s0)
/*  f15027c:	97af04ea */ 	lhu	$t7,0x4ea($sp)
/*  f150280:	12300003 */ 	beq	$s1,$s0,.L0f150290
/*  f150284:	a60f03fc */ 	sh	$t7,0x3fc($s0)
/*  f150288:	8e38001c */ 	lw	$t8,0x1c($s1)
/*  f15028c:	ae18001c */ 	sw	$t8,0x1c($s0)
.L0f150290:
/*  f150290:	97b900c6 */ 	lhu	$t9,0xc6($sp)
/*  f150294:	920c03f4 */ 	lbu	$t4,0x3f4($s0)
/*  f150298:	3c01447a */ 	lui	$at,0x447a
/*  f15029c:	00194bc2 */ 	srl	$t1,$t9,0xf
/*  f1502a0:	00095180 */ 	sll	$t2,$t1,0x6
/*  f1502a4:	314b0040 */ 	andi	$t3,$t2,0x40
/*  f1502a8:	318dffbf */ 	andi	$t5,$t4,0xffbf
/*  f1502ac:	016d6025 */ 	or	$t4,$t3,$t5
/*  f1502b0:	a20c03f4 */ 	sb	$t4,0x3f4($s0)
/*  f1502b4:	8faf00c4 */ 	lw	$t7,0xc4($sp)
/*  f1502b8:	318b00df */ 	andi	$t3,$t4,0xdf
/*  f1502bc:	44810000 */ 	mtc1	$at,$f0
/*  f1502c0:	000fc440 */ 	sll	$t8,$t7,0x11
/*  f1502c4:	001847c2 */ 	srl	$t0,$t8,0x1f
/*  f1502c8:	00084940 */ 	sll	$t1,$t0,0x5
/*  f1502cc:	312a0020 */ 	andi	$t2,$t1,0x20
/*  f1502d0:	014b6825 */ 	or	$t5,$t2,$t3
/*  f1502d4:	a20d03f4 */ 	sb	$t5,0x3f4($s0)
/*  f1502d8:	8fae00c4 */ 	lw	$t6,0xc4($sp)
/*  f1502dc:	02002025 */ 	or	$a0,$s0,$zero
/*  f1502e0:	27a30038 */ 	addiu	$v1,$sp,0x38
/*  f1502e4:	000e7c80 */ 	sll	$t7,$t6,0x12
/*  f1502e8:	000fc602 */ 	srl	$t8,$t7,0x18
/*  f1502ec:	ae1803a4 */ 	sw	$t8,0x3a4($s0)
/*  f1502f0:	97b900ba */ 	lhu	$t9,0xba($sp)
/*  f1502f4:	27a20046 */ 	addiu	$v0,$sp,0x46
/*  f1502f8:	ae1903bc */ 	sw	$t9,0x3bc($s0)
/*  f1502fc:	97a800bc */ 	lhu	$t0,0xbc($sp)
/*  f150300:	ae0803b8 */ 	sw	$t0,0x3b8($s0)
/*  f150304:	93a900c4 */ 	lbu	$t1,0xc4($sp)
/*  f150308:	920803f4 */ 	lbu	$t0,0x3f4($s0)
/*  f15030c:	ae09039c */ 	sw	$t1,0x39c($s0)
/*  f150310:	93ac00c5 */ 	lbu	$t4,0xc5($sp)
/*  f150314:	ae0c03a0 */ 	sw	$t4,0x3a0($s0)
/*  f150318:	93aa00be */ 	lbu	$t2,0xbe($sp)
/*  f15031c:	ae0a03c0 */ 	sw	$t2,0x3c0($s0)
/*  f150320:	93ab00bf */ 	lbu	$t3,0xbf($sp)
/*  f150324:	350a0010 */ 	ori	$t2,$t0,0x10
/*  f150328:	ae0b03c4 */ 	sw	$t3,0x3c4($s0)
/*  f15032c:	93ad00c0 */ 	lbu	$t5,0xc0($sp)
/*  f150330:	354b0080 */ 	ori	$t3,$t2,0x80
/*  f150334:	ae0d03c8 */ 	sw	$t5,0x3c8($s0)
/*  f150338:	93ae00c1 */ 	lbu	$t6,0xc1($sp)
/*  f15033c:	ae0e03cc */ 	sw	$t6,0x3cc($s0)
/*  f150340:	93af00c2 */ 	lbu	$t7,0xc2($sp)
/*  f150344:	ae0f03ec */ 	sw	$t7,0x3ec($s0)
/*  f150348:	93b800c3 */ 	lbu	$t8,0xc3($sp)
/*  f15034c:	a20a03f4 */ 	sb	$t2,0x3f4($s0)
/*  f150350:	a20b03f4 */ 	sb	$t3,0x3f4($s0)
/*  f150354:	ae1803f0 */ 	sw	$t8,0x3f0($s0)
/*  f150358:	24630002 */ 	addiu	$v1,$v1,0x2
/*  f15035c:	0062082b */ 	sltu	$at,$v1,$v0
/*  f150360:	1020000a */ 	beqz	$at,.L0f15038c
/*  f150364:	846d008e */ 	lh	$t5,0x8e($v1)
.L0f150368:
/*  f150368:	448d9000 */ 	mtc1	$t5,$f18
/*  f15036c:	24630002 */ 	addiu	$v1,$v1,0x2
/*  f150370:	0062082b */ 	sltu	$at,$v1,$v0
/*  f150374:	468094a0 */ 	cvt.s.w	$f18,$f18
/*  f150378:	24840004 */ 	addiu	$a0,$a0,0x4
/*  f15037c:	46009483 */ 	div.s	$f18,$f18,$f0
/*  f150380:	e49203cc */ 	swc1	$f18,0x3cc($a0)
/*  f150384:	1420fff8 */ 	bnez	$at,.L0f150368
/*  f150388:	846d008e */ 	lh	$t5,0x8e($v1)
.L0f15038c:
/*  f15038c:	448d9000 */ 	mtc1	$t5,$f18
/*  f150390:	24840004 */ 	addiu	$a0,$a0,0x4
/*  f150394:	468094a0 */ 	cvt.s.w	$f18,$f18
/*  f150398:	46009483 */ 	div.s	$f18,$f18,$f0
/*  f15039c:	e49203cc */ 	swc1	$f18,0x3cc($a0)
/*  f1503a0:	00001025 */ 	or	$v0,$zero,$zero
/*  f1503a4:	27a30038 */ 	addiu	$v1,$sp,0x38
.L0f1503a8:
/*  f1503a8:	8e0f0020 */ 	lw	$t7,0x20($s0)
/*  f1503ac:	906e009e */ 	lbu	$t6,0x9e($v1)
/*  f1503b0:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f1503b4:	01e2c021 */ 	addu	$t8,$t7,$v0
/*  f1503b8:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f1503bc:	28410400 */ 	slti	$at,$v0,0x400
/*  f1503c0:	1420fff9 */ 	bnez	$at,.L0f1503a8
/*  f1503c4:	a30e0000 */ 	sb	$t6,0x0($t8)
/*  f1503c8:	12300006 */ 	beq	$s1,$s0,.L0f1503e4
/*  f1503cc:	02202025 */ 	or	$a0,$s1,$zero
/*  f1503d0:	3c077f1b */ 	lui	$a3,%hi(var7f1b7158)
/*  f1503d4:	24e77158 */ 	addiu	$a3,$a3,%lo(var7f1b7158)
/*  f1503d8:	02002825 */ 	or	$a1,$s0,$zero
/*  f1503dc:	0fc53143 */ 	jal	func0f14c50c
/*  f1503e0:	2406195e */ 	addiu	$a2,$zero,0x195e
.L0f1503e4:
/*  f1503e4:	0fc52803 */ 	jal	func0f14a00c
/*  f1503e8:	00002025 */ 	or	$a0,$zero,$zero
/*  f1503ec:	0fc5285b */ 	jal	func0f14a16c
/*  f1503f0:	24040005 */ 	addiu	$a0,$zero,0x5
/*  f1503f4:	0fc52f01 */ 	jal	func0f14bc04
/*  f1503f8:	00000000 */ 	nop
/*  f1503fc:	00001025 */ 	or	$v0,$zero,$zero
/*  f150400:	27a30038 */ 	addiu	$v1,$sp,0x38
/*  f150404:	24040080 */ 	addiu	$a0,$zero,0x80
.L0f150408:
/*  f150408:	8e280010 */ 	lw	$t0,0x10($s1)
/*  f15040c:	90790000 */ 	lbu	$t9,0x0($v1)
/*  f150410:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f150414:	01024821 */ 	addu	$t1,$t0,$v0
/*  f150418:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f15041c:	1444fffa */ 	bne	$v0,$a0,.L0f150408
/*  f150420:	a1390000 */ 	sb	$t9,0x0($t1)
/*  f150424:	12300006 */ 	beq	$s1,$s0,.L0f150440
/*  f150428:	02002025 */ 	or	$a0,$s0,$zero
/*  f15042c:	3c077f1b */ 	lui	$a3,%hi(var7f1b7164)
/*  f150430:	24e77164 */ 	addiu	$a3,$a3,%lo(var7f1b7164)
/*  f150434:	02202825 */ 	or	$a1,$s1,$zero
/*  f150438:	0fc53143 */ 	jal	func0f14c50c
/*  f15043c:	2406196d */ 	addiu	$a2,$zero,0x196d
.L0f150440:
/*  f150440:	10000004 */ 	b	.L0f150454
/*  f150444:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f150448:
/*  f150448:	3c01800a */ 	lui	$at,%hi(g_FilemgrLastPakError)
/*  f15044c:	ac2321f8 */ 	sw	$v1,%lo(g_FilemgrLastPakError)($at)
/*  f150450:	00001025 */ 	or	$v0,$zero,$zero
.L0f150454:
/*  f150454:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f150458:	8fb00014 */ 	lw	$s0,0x14($sp)
/*  f15045c:	8fb10018 */ 	lw	$s1,0x18($sp)
/*  f150460:	03e00008 */ 	jr	$ra
/*  f150464:	27bd04e0 */ 	addiu	$sp,$sp,0x4e0
/*  f150468:	27bdeb08 */ 	addiu	$sp,$sp,-5368
/*  f15046c:	afb0001c */ 	sw	$s0,0x1c($sp)
/*  f150470:	00048600 */ 	sll	$s0,$a0,0x18
/*  f150474:	00107603 */ 	sra	$t6,$s0,0x18
/*  f150478:	afbf002c */ 	sw	$ra,0x2c($sp)
/*  f15047c:	afb30028 */ 	sw	$s3,0x28($sp)
/*  f150480:	afb20024 */ 	sw	$s2,0x24($sp)
/*  f150484:	afa414f8 */ 	sw	$a0,0x14f8($sp)
/*  f150488:	00a09025 */ 	or	$s2,$a1,$zero
/*  f15048c:	30d3ffff */ 	andi	$s3,$a2,0xffff
/*  f150490:	01c08025 */ 	or	$s0,$t6,$zero
/*  f150494:	afb10020 */ 	sw	$s1,0x20($sp)
/*  f150498:	afa61500 */ 	sw	$a2,0x1500($sp)
/*  f15049c:	0fc5281b */ 	jal	func0f14a06c
/*  f1504a0:	2404ffff */ 	addiu	$a0,$zero,-1
/*  f1504a4:	8c4f03f4 */ 	lw	$t7,0x3f4($v0)
/*  f1504a8:	00408825 */ 	or	$s1,$v0,$zero
/*  f1504ac:	24080001 */ 	addiu	$t0,$zero,0x1
/*  f1504b0:	000fc8c0 */ 	sll	$t9,$t7,0x3
/*  f1504b4:	07200030 */ 	bltz	$t9,.L0f150578
/*  f1504b8:	27a90044 */ 	addiu	$t1,$sp,0x44
/*  f1504bc:	a0480036 */ 	sb	$t0,0x36($v0)
/*  f1504c0:	ac490024 */ 	sw	$t1,0x24($v0)
/*  f1504c4:	310500ff */ 	andi	$a1,$t0,0xff
.L0f1504c8:
/*  f1504c8:	0fc5401a */ 	jal	func0f150068
/*  f1504cc:	02202025 */ 	or	$a0,$s1,$zero
/*  f1504d0:	8e2a002c */ 	lw	$t2,0x2c($s1)
/*  f1504d4:	000a58c2 */ 	srl	$t3,$t2,0x3
/*  f1504d8:	316cffff */ 	andi	$t4,$t3,0xffff
/*  f1504dc:	2d810400 */ 	sltiu	$at,$t4,0x400
/*  f1504e0:	14200009 */ 	bnez	$at,.L0f150508
/*  f1504e4:	a7ab10d0 */ 	sh	$t3,0x10d0($sp)
/*  f1504e8:	922d0036 */ 	lbu	$t5,0x36($s1)
/*  f1504ec:	25ae0001 */ 	addiu	$t6,$t5,0x1
/*  f1504f0:	31c500ff */ 	andi	$a1,$t6,0xff
/*  f1504f4:	28a1000c */ 	slti	$at,$a1,0xc
/*  f1504f8:	1420fff3 */ 	bnez	$at,.L0f1504c8
/*  f1504fc:	a22e0036 */ 	sb	$t6,0x36($s1)
/*  f150500:	100000a5 */ 	b	.L0f150798
/*  f150504:	2402ffff */ 	addiu	$v0,$zero,-1
.L0f150508:
/*  f150508:	97af10d0 */ 	lhu	$t7,0x10d0($sp)
/*  f15050c:	00001025 */ 	or	$v0,$zero,$zero
/*  f150510:	24050400 */ 	addiu	$a1,$zero,0x400
/*  f150514:	51e0000d */ 	beqzl	$t7,.L0f15054c
/*  f150518:	97a210d0 */ 	lhu	$v0,0x10d0($sp)
/*  f15051c:	8e380024 */ 	lw	$t8,0x24($s1)
.L0f150520:
/*  f150520:	8e290020 */ 	lw	$t1,0x20($s1)
/*  f150524:	0302c821 */ 	addu	$t9,$t8,$v0
/*  f150528:	93280000 */ 	lbu	$t0,0x0($t9)
/*  f15052c:	01225021 */ 	addu	$t2,$t1,$v0
/*  f150530:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f150534:	a1480000 */ 	sb	$t0,0x0($t2)
/*  f150538:	97ab10d0 */ 	lhu	$t3,0x10d0($sp)
/*  f15053c:	004b082b */ 	sltu	$at,$v0,$t3
/*  f150540:	5420fff7 */ 	bnezl	$at,.L0f150520
/*  f150544:	8e380024 */ 	lw	$t8,0x24($s1)
/*  f150548:	97a210d0 */ 	lhu	$v0,0x10d0($sp)
.L0f15054c:
/*  f15054c:	28410400 */ 	slti	$at,$v0,0x400
/*  f150550:	50200007 */ 	beqzl	$at,.L0f150570
/*  f150554:	922f03f4 */ 	lbu	$t7,0x3f4($s1)
.L0f150558:
/*  f150558:	8e2c0020 */ 	lw	$t4,0x20($s1)
/*  f15055c:	01826821 */ 	addu	$t5,$t4,$v0
/*  f150560:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f150564:	1445fffc */ 	bne	$v0,$a1,.L0f150558
/*  f150568:	a1a00000 */ 	sb	$zero,0x0($t5)
/*  f15056c:	922f03f4 */ 	lbu	$t7,0x3f4($s1)
.L0f150570:
/*  f150570:	35f80010 */ 	ori	$t8,$t7,0x10
/*  f150574:	a23803f4 */ 	sb	$t8,0x3f4($s1)
.L0f150578:
/*  f150578:	8e3903f4 */ 	lw	$t9,0x3f4($s1)
/*  f15057c:	93ac10de */ 	lbu	$t4,0x10de($sp)
/*  f150580:	3c01447a */ 	lui	$at,0x447a
/*  f150584:	00194840 */ 	sll	$t1,$t9,0x1
/*  f150588:	000947c2 */ 	srl	$t0,$t1,0x1f
/*  f15058c:	000859c0 */ 	sll	$t3,$t0,0x7
/*  f150590:	318dff7f */ 	andi	$t5,$t4,0xff7f
/*  f150594:	016d5025 */ 	or	$t2,$t3,$t5
/*  f150598:	a3aa10de */ 	sb	$t2,0x10de($sp)
/*  f15059c:	8e2f03f4 */ 	lw	$t7,0x3f4($s1)
/*  f1505a0:	314c00bf */ 	andi	$t4,$t2,0xbf
/*  f1505a4:	44810000 */ 	mtc1	$at,$f0
/*  f1505a8:	000fc080 */ 	sll	$t8,$t7,0x2
/*  f1505ac:	0018cfc2 */ 	srl	$t9,$t8,0x1f
/*  f1505b0:	00194980 */ 	sll	$t1,$t9,0x6
/*  f1505b4:	31280040 */ 	andi	$t0,$t1,0x40
/*  f1505b8:	010c5825 */ 	or	$t3,$t0,$t4
/*  f1505bc:	a3ab10de */ 	sb	$t3,0x10de($sp)
/*  f1505c0:	922d03a7 */ 	lbu	$t5,0x3a7($s1)
/*  f1505c4:	97b910de */ 	lhu	$t9,0x10de($sp)
/*  f1505c8:	24050400 */ 	addiu	$a1,$zero,0x400
/*  f1505cc:	000d7980 */ 	sll	$t7,$t5,0x6
/*  f1505d0:	31f83fc0 */ 	andi	$t8,$t7,0x3fc0
/*  f1505d4:	3329c03f */ 	andi	$t1,$t9,0xc03f
/*  f1505d8:	03097025 */ 	or	$t6,$t8,$t1
/*  f1505dc:	a7ae10de */ 	sh	$t6,0x10de($sp)
/*  f1505e0:	8e2a03bc */ 	lw	$t2,0x3bc($s1)
/*  f1505e4:	27a31050 */ 	addiu	$v1,$sp,0x1050
/*  f1505e8:	02202025 */ 	or	$a0,$s1,$zero
/*  f1505ec:	a7aa10d2 */ 	sh	$t2,0x10d2($sp)
/*  f1505f0:	8e2803b8 */ 	lw	$t0,0x3b8($s1)
/*  f1505f4:	27a2105e */ 	addiu	$v0,$sp,0x105e
/*  f1505f8:	a7a810d4 */ 	sh	$t0,0x10d4($sp)
/*  f1505fc:	8e2c039c */ 	lw	$t4,0x39c($s1)
/*  f150600:	a3ac10dc */ 	sb	$t4,0x10dc($sp)
/*  f150604:	8e2b03a0 */ 	lw	$t3,0x3a0($s1)
/*  f150608:	a3ab10dd */ 	sb	$t3,0x10dd($sp)
/*  f15060c:	8e2d03c0 */ 	lw	$t5,0x3c0($s1)
/*  f150610:	a3ad10d6 */ 	sb	$t5,0x10d6($sp)
/*  f150614:	8e2f03c4 */ 	lw	$t7,0x3c4($s1)
/*  f150618:	a3af10d7 */ 	sb	$t7,0x10d7($sp)
/*  f15061c:	8e3903c8 */ 	lw	$t9,0x3c8($s1)
/*  f150620:	a3b910d8 */ 	sb	$t9,0x10d8($sp)
/*  f150624:	8e3803cc */ 	lw	$t8,0x3cc($s1)
/*  f150628:	a3b810d9 */ 	sb	$t8,0x10d9($sp)
/*  f15062c:	8e2903ec */ 	lw	$t1,0x3ec($s1)
/*  f150630:	a3a910da */ 	sb	$t1,0x10da($sp)
/*  f150634:	8e2e03f0 */ 	lw	$t6,0x3f0($s1)
/*  f150638:	a3ae10db */ 	sb	$t6,0x10db($sp)
/*  f15063c:	c49003d0 */ 	lwc1	$f16,0x3d0($a0)
/*  f150640:	24630002 */ 	addiu	$v1,$v1,0x2
/*  f150644:	46008482 */ 	mul.s	$f18,$f16,$f0
/*  f150648:	5062000c */ 	beql	$v1,$v0,.L0f15067c
/*  f15064c:	4600940d */ 	trunc.w.s	$f16,$f18
/*  f150650:	4600940d */ 	trunc.w.s	$f16,$f18
.L0f150654:
/*  f150654:	24840004 */ 	addiu	$a0,$a0,0x4
/*  f150658:	24630002 */ 	addiu	$v1,$v1,0x2
/*  f15065c:	44088000 */ 	mfc1	$t0,$f16
/*  f150660:	00000000 */ 	nop
/*  f150664:	a468008c */ 	sh	$t0,0x8c($v1)
/*  f150668:	c49003d0 */ 	lwc1	$f16,0x3d0($a0)
/*  f15066c:	46008482 */ 	mul.s	$f18,$f16,$f0
/*  f150670:	5462fff8 */ 	bnel	$v1,$v0,.L0f150654
/*  f150674:	4600940d */ 	trunc.w.s	$f16,$f18
/*  f150678:	4600940d */ 	trunc.w.s	$f16,$f18
.L0f15067c:
/*  f15067c:	24840004 */ 	addiu	$a0,$a0,0x4
/*  f150680:	44088000 */ 	mfc1	$t0,$f16
/*  f150684:	00000000 */ 	nop
/*  f150688:	a468008e */ 	sh	$t0,0x8e($v1)
/*  f15068c:	00001025 */ 	or	$v0,$zero,$zero
/*  f150690:	27a31050 */ 	addiu	$v1,$sp,0x1050
.L0f150694:
/*  f150694:	8e2c0010 */ 	lw	$t4,0x10($s1)
/*  f150698:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f15069c:	01825821 */ 	addu	$t3,$t4,$v0
/*  f1506a0:	916d0000 */ 	lbu	$t5,0x0($t3)
/*  f1506a4:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f1506a8:	28410080 */ 	slti	$at,$v0,0x80
/*  f1506ac:	1420fff9 */ 	bnez	$at,.L0f150694
/*  f1506b0:	a06dffff */ 	sb	$t5,-0x1($v1)
/*  f1506b4:	00001025 */ 	or	$v0,$zero,$zero
/*  f1506b8:	27a31050 */ 	addiu	$v1,$sp,0x1050
.L0f1506bc:
/*  f1506bc:	8e2f0020 */ 	lw	$t7,0x20($s1)
/*  f1506c0:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f1506c4:	01e2c821 */ 	addu	$t9,$t7,$v0
/*  f1506c8:	93380000 */ 	lbu	$t8,0x0($t9)
/*  f1506cc:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f1506d0:	1445fffa */ 	bne	$v0,$a1,.L0f1506bc
/*  f1506d4:	a078009d */ 	sb	$t8,0x9d($v1)
/*  f1506d8:	00102600 */ 	sll	$a0,$s0,0x18
/*  f1506dc:	24090001 */ 	addiu	$t1,$zero,0x1
/*  f1506e0:	3c018007 */ 	lui	$at,%hi(g_FileLists+0x1c)
/*  f1506e4:	00047603 */ 	sra	$t6,$a0,0x18
/*  f1506e8:	27aa1044 */ 	addiu	$t2,$sp,0x1044
/*  f1506ec:	ac295bdc */ 	sw	$t1,%lo(g_FileLists+0x1c)($at)
/*  f1506f0:	afaa0010 */ 	sw	$t2,0x10($sp)
/*  f1506f4:	01c02025 */ 	or	$a0,$t6,$zero
/*  f1506f8:	02402825 */ 	or	$a1,$s2,$zero
/*  f1506fc:	24060008 */ 	addiu	$a2,$zero,0x8
/*  f150700:	27a71050 */ 	addiu	$a3,$sp,0x1050
/*  f150704:	0fc45a0a */ 	jal	pakSaveAtGuid
/*  f150708:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f15070c:	1440001f */ 	bnez	$v0,.L0f15078c
/*  f150710:	00401825 */ 	or	$v1,$v0,$zero
/*  f150714:	3c12800a */ 	lui	$s2,%hi(g_Vars)
/*  f150718:	26529fc0 */ 	addiu	$s2,$s2,%lo(g_Vars)
/*  f15071c:	00008025 */ 	or	$s0,$zero,$zero
.L0f150720:
/*  f150720:	0fc5281b */ 	jal	func0f14a06c
/*  f150724:	02002025 */ 	or	$a0,$s0,$zero
/*  f150728:	8e2803f8 */ 	lw	$t0,0x3f8($s1)
/*  f15072c:	8c4c03f8 */ 	lw	$t4,0x3f8($v0)
/*  f150730:	550c000e */ 	bnel	$t0,$t4,.L0f15076c
/*  f150734:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f150738:	962b03fc */ 	lhu	$t3,0x3fc($s1)
/*  f15073c:	944d03fc */ 	lhu	$t5,0x3fc($v0)
/*  f150740:	8faf1044 */ 	lw	$t7,0x1044($sp)
/*  f150744:	2a01000c */ 	slti	$at,$s0,0xc
/*  f150748:	556d0008 */ 	bnel	$t3,$t5,.L0f15076c
/*  f15074c:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f150750:	ac4f03f8 */ 	sw	$t7,0x3f8($v0)
/*  f150754:	14200004 */ 	bnez	$at,.L0f150768
/*  f150758:	a45303fc */ 	sh	$s3,0x3fc($v0)
/*  f15075c:	8e590458 */ 	lw	$t9,0x458($s2)
/*  f150760:	37380001 */ 	ori	$t8,$t9,0x1
/*  f150764:	ae580458 */ 	sw	$t8,0x458($s2)
.L0f150768:
/*  f150768:	26100001 */ 	addiu	$s0,$s0,0x1
.L0f15076c:
/*  f15076c:	24010012 */ 	addiu	$at,$zero,0x12
/*  f150770:	1601ffeb */ 	bne	$s0,$at,.L0f150720
/*  f150774:	00000000 */ 	nop
/*  f150778:	8fa91044 */ 	lw	$t1,0x1044($sp)
/*  f15077c:	a63303fc */ 	sh	$s3,0x3fc($s1)
/*  f150780:	00001025 */ 	or	$v0,$zero,$zero
/*  f150784:	10000004 */ 	b	.L0f150798
/*  f150788:	ae2903f8 */ 	sw	$t1,0x3f8($s1)
.L0f15078c:
/*  f15078c:	3c01800a */ 	lui	$at,%hi(g_FilemgrLastPakError)
/*  f150790:	ac2321f8 */ 	sw	$v1,%lo(g_FilemgrLastPakError)($at)
/*  f150794:	2402ffff */ 	addiu	$v0,$zero,-1
.L0f150798:
/*  f150798:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*  f15079c:	8fb0001c */ 	lw	$s0,0x1c($sp)
/*  f1507a0:	8fb10020 */ 	lw	$s1,0x20($sp)
/*  f1507a4:	8fb20024 */ 	lw	$s2,0x24($sp)
/*  f1507a8:	8fb30028 */ 	lw	$s3,0x28($sp)
/*  f1507ac:	03e00008 */ 	jr	$ra
/*  f1507b0:	27bd14f8 */ 	addiu	$sp,$sp,0x14f8
);

void phGetGuid(s32 index, struct fileguid *guid)
{
	struct var8007f8e0 *thing = func0f14a06c(index);

	guid->fileid = thing->fileguid.fileid;
	guid->deviceserial = thing->fileguid.deviceserial;
}

void phSetFileId(s32 fileid)
{
	struct var8007f8e0 *thing = func0f14a06c(-1);

	thing->fileguid.deviceserial = 0;
	thing->fileguid.fileid = fileid;
}
