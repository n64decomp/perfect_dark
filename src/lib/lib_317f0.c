#include <ultra64.h>
#include "constants.h"
#include "game/data/data_000000.h"
#include "game/data/data_0083d0.h"
#include "game/data/data_00e460.h"
#include "game/data/data_0160b0.h"
#include "game/data/data_01a3a0.h"
#include "game/data/data_020df0.h"
#include "gvars/gvars.h"
#include "lib/lib_0e9d0.h"
#include "lib/lib_2faf0.h"
#include "lib/lib_2fc60.h"
#include "lib/lib_30ce0.h"
#include "lib/lib_317f0.h"
#include "lib/lib_38d30.h"
#include "lib/lib_39c80.h"
#include "lib/lib_39fe0.h"
#include "lib/lib_3a100.h"
#include "lib/lib_3c4d0.h"
#include "lib/lib_3ccf0.h"
#include "lib/lib_3cdc0.h"
#include "lib/lib_3cef0.h"
#include "lib/lib_3d280.h"
#include "lib/lib_3e3e0.h"
#include "lib/lib_3e730.h"
#include "lib/lib_48650.h"
#include "lib/lib_488e0.h"
#include "types.h"

const u32 var70054740[] = {0x70031ce0};
const u32 var70054744[] = {0x700325ac};
const u32 var70054748[] = {0x70033010};
const u32 var7005474c[] = {0x70032730};
const u32 var70054750[] = {0x70033010};
const u32 var70054754[] = {0x70033010};
const u32 var70054758[] = {0x70033010};
const u32 var7005475c[] = {0x70032a3c};
const u32 var70054760[] = {0x70033010};
const u32 var70054764[] = {0x70033010};
const u32 var70054768[] = {0x70033010};
const u32 var7005476c[] = {0x70033010};
const u32 var70054770[] = {0x70033010};
const u32 var70054774[] = {0x70033010};
const u32 var70054778[] = {0x70033010};
const u32 var7005477c[] = {0x700327d4};
const u32 var70054780[] = {0x70034500};
const u32 var70054784[] = {0x70034d84};
const u32 var70054788[] = {0x70034910};
const u32 var7005478c[] = {0x70034d84};
const u32 var70054790[] = {0x70034d84};
const u32 var70054794[] = {0x70034538};
const u32 var70054798[] = {0x70034590};
const u32 var7005479c[] = {0x70034928};
const u32 var700547a0[] = {0x70034d8c};
const u32 var700547a4[] = {0x70034510};
const u32 var700547a8[] = {0x70034940};
const u32 var700547ac[] = {0x70034d8c};
const u32 var700547b0[] = {0x70034ce0};
const u32 var700547b4[] = {0x70034d20};
const u32 var700547b8[] = {0x70034d60};
const u32 var700547bc[] = {0x70034aa4};
const u32 var700547c0[] = {0x70034ad4};
const u32 var700547c4[] = {0x70034b5c};
const u32 var700547c8[] = {0x70034d8c};
const u32 var700547cc[] = {0x70034d8c};
const u32 var700547d0[] = {0x70034d8c};
const u32 var700547d4[] = {0x70034910};
const u32 var700547d8[] = {0x70034624};
const u32 var700547dc[] = {0x70034764};
const u32 var700547e0[] = {0x700349b0};
const u32 var700547e4[] = {0x70034a10};
const u32 var700547e8[] = {0x70034e5c};
const u32 var700547ec[] = {0x70034eec};
const u32 var700547f0[] = {0x70034e78};
const u32 var700547f4[] = {0x70034e94};
const u32 var700547f8[] = {0x70034eec};
const u32 var700547fc[] = {0x70034eec};
const u32 var70054800[] = {0x70034eec};
const u32 var70054804[] = {0x70034eec};
const u32 var70054808[] = {0x70034eec};
const u32 var7005480c[] = {0x70034eec};
const u32 var70054810[] = {0x70034eec};
const u32 var70054814[] = {0x70034eec};
const u32 var70054818[] = {0x70034eec};
const u32 var7005481c[] = {0x70034eec};
const u32 var70054820[] = {0x70034eec};
const u32 var70054824[] = {0x70034eec};
const u32 var70054828[] = {0x70034eec};
const u32 var7005482c[] = {0x70034edc};
const u32 var70054830[] = {0x70034edc};
const u32 var70054834[] = {0x70034edc};
const u32 var70054838[] = {0x70035a44};
const u32 var7005483c[] = {0x700371f8};
const u32 var70054840[] = {0x700371f8};
const u32 var70054844[] = {0x700371f8};
const u32 var70054848[] = {0x700371f8};
const u32 var7005484c[] = {0x700371f8};
const u32 var70054850[] = {0x700371f8};
const u32 var70054854[] = {0x700371f8};
const u32 var70054858[] = {0x700371f8};
const u32 var7005485c[] = {0x700371f8};
const u32 var70054860[] = {0x700371f8};
const u32 var70054864[] = {0x700371f8};
const u32 var70054868[] = {0x700371f8};
const u32 var7005486c[] = {0x700371f8};
const u32 var70054870[] = {0x700371f8};
const u32 var70054874[] = {0x700371f8};
const u32 var70054878[] = {0x700351a4};
const u32 var7005487c[] = {0x700371f8};
const u32 var70054880[] = {0x700371f8};
const u32 var70054884[] = {0x700371f8};
const u32 var70054888[] = {0x700371f8};
const u32 var7005488c[] = {0x700371f8};
const u32 var70054890[] = {0x700371f8};
const u32 var70054894[] = {0x700371f8};
const u32 var70054898[] = {0x700371f8};
const u32 var7005489c[] = {0x700371f8};
const u32 var700548a0[] = {0x700371f8};
const u32 var700548a4[] = {0x700371f8};
const u32 var700548a8[] = {0x700371f8};
const u32 var700548ac[] = {0x700371f8};
const u32 var700548b0[] = {0x700371f8};
const u32 var700548b4[] = {0x700371f8};
const u32 var700548b8[] = {0x70035b68};
const u32 var700548bc[] = {0x700371f8};
const u32 var700548c0[] = {0x700371f8};
const u32 var700548c4[] = {0x700371f8};
const u32 var700548c8[] = {0x700371f8};
const u32 var700548cc[] = {0x700371f8};
const u32 var700548d0[] = {0x700371f8};
const u32 var700548d4[] = {0x700371f8};
const u32 var700548d8[] = {0x700371f8};
const u32 var700548dc[] = {0x700371f8};
const u32 var700548e0[] = {0x700371f8};
const u32 var700548e4[] = {0x700371f8};
const u32 var700548e8[] = {0x700371f8};
const u32 var700548ec[] = {0x700371f8};
const u32 var700548f0[] = {0x700371f8};
const u32 var700548f4[] = {0x700371f8};
const u32 var700548f8[] = {0x70035c64};
const u32 var700548fc[] = {0x700371f8};
const u32 var70054900[] = {0x700371f8};
const u32 var70054904[] = {0x700371f8};
const u32 var70054908[] = {0x700371f8};
const u32 var7005490c[] = {0x700371f8};
const u32 var70054910[] = {0x700371f8};
const u32 var70054914[] = {0x700371f8};
const u32 var70054918[] = {0x700371f8};
const u32 var7005491c[] = {0x700371f8};
const u32 var70054920[] = {0x700371f8};
const u32 var70054924[] = {0x700371f8};
const u32 var70054928[] = {0x700371f8};
const u32 var7005492c[] = {0x700371f8};
const u32 var70054930[] = {0x700371f8};
const u32 var70054934[] = {0x700371f8};
const u32 var70054938[] = {0x70036fb4};
const u32 var7005493c[] = {0x700371f8};
const u32 var70054940[] = {0x700371f8};
const u32 var70054944[] = {0x700371f8};
const u32 var70054948[] = {0x700371f8};
const u32 var7005494c[] = {0x700371f8};
const u32 var70054950[] = {0x700371f8};
const u32 var70054954[] = {0x700371f8};
const u32 var70054958[] = {0x700371f8};
const u32 var7005495c[] = {0x700371f8};
const u32 var70054960[] = {0x700371f8};
const u32 var70054964[] = {0x700371f8};
const u32 var70054968[] = {0x700371f8};
const u32 var7005496c[] = {0x700371f8};
const u32 var70054970[] = {0x700371f8};
const u32 var70054974[] = {0x700371f8};
const u32 var70054978[] = {0x70035be0};
const u32 var7005497c[] = {0x700371f8};
const u32 var70054980[] = {0x700371f8};
const u32 var70054984[] = {0x700371f8};
const u32 var70054988[] = {0x700371f8};
const u32 var7005498c[] = {0x700371f8};
const u32 var70054990[] = {0x700371f8};
const u32 var70054994[] = {0x700371f8};
const u32 var70054998[] = {0x700371f8};
const u32 var7005499c[] = {0x700371f8};
const u32 var700549a0[] = {0x700371f8};
const u32 var700549a4[] = {0x700371f8};
const u32 var700549a8[] = {0x700371f8};
const u32 var700549ac[] = {0x700371f8};
const u32 var700549b0[] = {0x700371f8};
const u32 var700549b4[] = {0x700371f8};
const u32 var700549b8[] = {0x70037044};
const u32 var700549bc[] = {0x70036e4c};
const u32 var700549c0[] = {0x70036988};
const u32 var700549c4[] = {0x700369ec};
const u32 var700549c8[] = {0x70036aa4};
const u32 var700549cc[] = {0x70036fa4};
const u32 var700549d0[] = {0x70036fa4};
const u32 var700549d4[] = {0x70036328};
const u32 var700549d8[] = {0x70036fa4};
const u32 var700549dc[] = {0x70036fa4};
const u32 var700549e0[] = {0x70035d40};
const u32 var700549e4[] = {0x70036b30};
const u32 var700549e8[] = {0x70036ba8};
const u32 var700549ec[] = {0x70036c08};
const u32 var700549f0[] = {0x70036c6c};
const u32 var700549f4[] = {0x70036ccc};
const u32 var700549f8[] = {0x700363d8};
const u32 var700549fc[] = {0x70036d2c};
const u32 var70054a00[] = {0x70036d8c};
const u32 var70054a04[] = {0x70036dec};
const u32 var70054a08[] = {0x70036778};
const u32 var70054a0c[] = {0x700367e8};
const u32 var70054a10[] = {0x70036848};
const u32 var70054a14[] = {0x700368b8};
const u32 var70054a18[] = {0x70036918};
const u32 var70054a1c[] = {0x70036f70};
const u32 var70054a20[] = {0x70036734};
const u32 var70054a24[] = {0x70036fa4};
const u32 var70054a28[] = {0x70036fa4};
const u32 var70054a2c[] = {0x70036fa4};
const u32 var70054a30[] = {0x700362e0};
const u32 var70054a34[] = {0x70036fa4};
const u32 var70054a38[] = {0x70036744};
const u32 var70054a3c[] = {0x700361e8};
const u32 var70054a40[] = {0x70036228};
const u32 var70054a44[] = {0x70036268};
const u32 var70054a48[] = {0x70036ecc};
const u32 var70054a4c[] = {0x70036ee0};
const u32 var70054a50[] = {0x70036ee0};
const u32 var70054a54[] = {0x70036ee0};
const u32 var70054a58[] = {0x70036f40};
const u32 var70054a5c[] = {0x70036ef8};
const u32 var70054a60[] = {0x70036f40};
const u32 var70054a64[] = {0x70036ef8};
const u32 var70054a68[] = {0x70036f1c};
const u32 var70054a6c[] = {0x70036f40};
const u32 var70054a70[] = {0x70036f40};
const u32 var70054a74[] = {0x70036ef8};
const u32 var70054a78[] = {0x00000000};
const u32 var70054a7c[] = {0x00000000};

GLOBAL_ASM(
glabel func000317f0
/*    317f0:	27bdffc0 */ 	addiu	$sp,$sp,-64
/*    317f4:	afbf001c */ 	sw	$ra,0x1c($sp)
/*    317f8:	afa40040 */ 	sw	$a0,0x40($sp)
/*    317fc:	8fae0040 */ 	lw	$t6,0x40($sp)
/*    31800:	3c188006 */ 	lui	$t8,0x8006
/*    31804:	8f18f12c */ 	lw	$t8,-0xed4($t8)
/*    31808:	8dcf0008 */ 	lw	$t7,0x8($t6)
/*    3180c:	af0f0044 */ 	sw	$t7,0x44($t8)
/*    31810:	3c198006 */ 	lui	$t9,0x8006
/*    31814:	8f39f12c */ 	lw	$t9,-0xed4($t9)
/*    31818:	af20003c */ 	sw	$zero,0x3c($t9)
/*    3181c:	3c098006 */ 	lui	$t1,0x8006
/*    31820:	8d29f12c */ 	lw	$t1,-0xed4($t1)
/*    31824:	24083e80 */ 	addiu	$t0,$zero,0x3e80
/*    31828:	ad280048 */ 	sw	$t0,0x48($t1)
/*    3182c:	8faa0040 */ 	lw	$t2,0x40($sp)
/*    31830:	00002025 */ 	or	$a0,$zero,$zero
/*    31834:	00002825 */ 	or	$a1,$zero,$zero
/*    31838:	8d4b0000 */ 	lw	$t3,0x0($t2)
/*    3183c:	8d46000c */ 	lw	$a2,0xc($t2)
/*    31840:	24070001 */ 	addiu	$a3,$zero,0x1
/*    31844:	000b6080 */ 	sll	$t4,$t3,0x2
/*    31848:	018b6021 */ 	addu	$t4,$t4,$t3
/*    3184c:	000c6080 */ 	sll	$t4,$t4,0x2
/*    31850:	018b6023 */ 	subu	$t4,$t4,$t3
/*    31854:	000c6080 */ 	sll	$t4,$t4,0x2
/*    31858:	0c00bec5 */ 	jal	func0002fb14
/*    3185c:	afac0010 */ 	sw	$t4,0x10($sp)
/*    31860:	afa20038 */ 	sw	$v0,0x38($sp)
/*    31864:	3c0e8006 */ 	lui	$t6,0x8006
/*    31868:	8dcef12c */ 	lw	$t6,-0xed4($t6)
/*    3186c:	8fad0038 */ 	lw	$t5,0x38($sp)
/*    31870:	adcd0040 */ 	sw	$t5,0x40($t6)
/*    31874:	8faf0040 */ 	lw	$t7,0x40($sp)
/*    31878:	00002025 */ 	or	$a0,$zero,$zero
/*    3187c:	00002825 */ 	or	$a1,$zero,$zero
/*    31880:	8df80004 */ 	lw	$t8,0x4($t7)
/*    31884:	8de6000c */ 	lw	$a2,0xc($t7)
/*    31888:	24070001 */ 	addiu	$a3,$zero,0x1
/*    3188c:	0018c8c0 */ 	sll	$t9,$t8,0x3
/*    31890:	0338c823 */ 	subu	$t9,$t9,$t8
/*    31894:	0019c880 */ 	sll	$t9,$t9,0x2
/*    31898:	0c00bec5 */ 	jal	func0002fb14
/*    3189c:	afb90010 */ 	sw	$t9,0x10($sp)
/*    318a0:	afa20038 */ 	sw	$v0,0x38($sp)
/*    318a4:	3c048006 */ 	lui	$a0,%hi(var80060014)
/*    318a8:	8c84f12c */ 	lw	$a0,-0xed4($a0)
/*    318ac:	8fa80040 */ 	lw	$t0,0x40($sp)
/*    318b0:	8fa50038 */ 	lw	$a1,0x38($sp)
/*    318b4:	24840014 */ 	addiu	$a0,$a0,%lo(var80060014)
/*    318b8:	0c00f134 */ 	jal	func0003c4d0
/*    318bc:	8d060004 */ 	lw	$a2,0x4($t0)
/*    318c0:	3c098006 */ 	lui	$t1,0x8006
/*    318c4:	8d29f12c */ 	lw	$t1,-0xed4($t1)
/*    318c8:	3c018006 */ 	lui	$at,0x8006
/*    318cc:	8d2a0040 */ 	lw	$t2,0x40($t1)
/*    318d0:	ac2af128 */ 	sw	$t2,-0xed8($at)
/*    318d4:	8fac0040 */ 	lw	$t4,0x40($sp)
/*    318d8:	240b0001 */ 	addiu	$t3,$zero,0x1
/*    318dc:	afab003c */ 	sw	$t3,0x3c($sp)
/*    318e0:	8d8d0000 */ 	lw	$t5,0x0($t4)
/*    318e4:	2da10002 */ 	sltiu	$at,$t5,0x2
/*    318e8:	14200018 */ 	bnez	$at,.L0003194c
/*    318ec:	00000000 */ 	sll	$zero,$zero,0x0
.L000318f0:
/*    318f0:	3c0e8006 */ 	lui	$t6,0x8006
/*    318f4:	8dcef12c */ 	lw	$t6,-0xed4($t6)
/*    318f8:	8dcf0040 */ 	lw	$t7,0x40($t6)
/*    318fc:	afaf0024 */ 	sw	$t7,0x24($sp)
/*    31900:	8fb8003c */ 	lw	$t8,0x3c($sp)
/*    31904:	8fa80024 */ 	lw	$t0,0x24($sp)
/*    31908:	0018c880 */ 	sll	$t9,$t8,0x2
/*    3190c:	0338c821 */ 	addu	$t9,$t9,$t8
/*    31910:	0019c880 */ 	sll	$t9,$t9,0x2
/*    31914:	0338c823 */ 	subu	$t9,$t9,$t8
/*    31918:	0019c880 */ 	sll	$t9,$t9,0x2
/*    3191c:	03284821 */ 	addu	$t1,$t9,$t0
/*    31920:	01202025 */ 	or	$a0,$t1,$zero
/*    31924:	0c00c5dc */ 	jal	func00031770
/*    31928:	2525ffb4 */ 	addiu	$a1,$t1,-76
/*    3192c:	8faa003c */ 	lw	$t2,0x3c($sp)
/*    31930:	8fac0040 */ 	lw	$t4,0x40($sp)
/*    31934:	254b0001 */ 	addiu	$t3,$t2,0x1
/*    31938:	afab003c */ 	sw	$t3,0x3c($sp)
/*    3193c:	8d8d0000 */ 	lw	$t5,0x0($t4)
/*    31940:	016d082b */ 	sltu	$at,$t3,$t5
/*    31944:	1420ffea */ 	bnez	$at,.L000318f0
/*    31948:	00000000 */ 	sll	$zero,$zero,0x0
.L0003194c:
/*    3194c:	0c00ccde */ 	jal	func00033378
/*    31950:	00002025 */ 	or	$a0,$zero,$zero
/*    31954:	0c00cd8d */ 	jal	func00033634
/*    31958:	00002025 */ 	or	$a0,$zero,$zero
/*    3195c:	8fae0040 */ 	lw	$t6,0x40($sp)
/*    31960:	00002025 */ 	or	$a0,$zero,$zero
/*    31964:	00002825 */ 	or	$a1,$zero,$zero
/*    31968:	95cf0010 */ 	lhu	$t7,0x10($t6)
/*    3196c:	8dc6000c */ 	lw	$a2,0xc($t6)
/*    31970:	24070002 */ 	addiu	$a3,$zero,0x2
/*    31974:	0c00bec5 */ 	jal	func0002fb14
/*    31978:	afaf0010 */ 	sw	$t7,0x10($sp)
/*    3197c:	3c01800a */ 	lui	$at,0x800a
/*    31980:	ac22c334 */ 	sw	$v0,-0x3ccc($at)
/*    31984:	8fb80040 */ 	lw	$t8,0x40($sp)
/*    31988:	afa0003c */ 	sw	$zero,0x3c($sp)
/*    3198c:	97190010 */ 	lhu	$t9,0x10($t8)
/*    31990:	13200010 */ 	beqz	$t9,.L000319d4
/*    31994:	00000000 */ 	sll	$zero,$zero,0x0
.L00031998:
/*    31998:	8faa003c */ 	lw	$t2,0x3c($sp)
/*    3199c:	3c09800a */ 	lui	$t1,0x800a
/*    319a0:	8d29c334 */ 	lw	$t1,-0x3ccc($t1)
/*    319a4:	000a6040 */ 	sll	$t4,$t2,0x1
/*    319a8:	24087fff */ 	addiu	$t0,$zero,0x7fff
/*    319ac:	012c5821 */ 	addu	$t3,$t1,$t4
/*    319b0:	a5680000 */ 	sh	$t0,0x0($t3)
/*    319b4:	8fad003c */ 	lw	$t5,0x3c($sp)
/*    319b8:	8faf0040 */ 	lw	$t7,0x40($sp)
/*    319bc:	25ae0001 */ 	addiu	$t6,$t5,0x1
/*    319c0:	afae003c */ 	sw	$t6,0x3c($sp)
/*    319c4:	95f80010 */ 	lhu	$t8,0x10($t7)
/*    319c8:	01d8082b */ 	sltu	$at,$t6,$t8
/*    319cc:	1420fff2 */ 	bnez	$at,.L00031998
/*    319d0:	00000000 */ 	sll	$zero,$zero,0x0
.L000319d4:
/*    319d4:	3c198006 */ 	lui	$t9,0x8006
/*    319d8:	8f39f12c */ 	lw	$t9,-0xed4($t9)
/*    319dc:	af200000 */ 	sw	$zero,0x0($t9)
/*    319e0:	3c098006 */ 	lui	$t1,0x8006
/*    319e4:	8d29f12c */ 	lw	$t1,-0xed4($t1)
/*    319e8:	3c0a7003 */ 	lui	$t2,0x7003
/*    319ec:	254a1a68 */ 	addiu	$t2,$t2,0x1a68
/*    319f0:	ad2a0008 */ 	sw	$t2,0x8($t1)
/*    319f4:	3c0c8006 */ 	lui	$t4,0x8006
/*    319f8:	8d8cf12c */ 	lw	$t4,-0xed4($t4)
/*    319fc:	ad8c0004 */ 	sw	$t4,0x4($t4)
/*    31a00:	3c048006 */ 	lui	$a0,%hi(var80060028)
/*    31a04:	0c00f240 */ 	jal	func0003c900
/*    31a08:	8c84f12c */ 	lw	$a0,-0xed4($a0)
/*    31a0c:	24080020 */ 	addiu	$t0,$zero,0x20
/*    31a10:	a7a80028 */ 	sh	$t0,0x28($sp)
/*    31a14:	3c0b8006 */ 	lui	$t3,0x8006
/*    31a18:	8d6bf12c */ 	lw	$t3,-0xed4($t3)
/*    31a1c:	27a50028 */ 	addiu	$a1,$sp,0x28
/*    31a20:	24070001 */ 	addiu	$a3,$zero,0x1
/*    31a24:	25640014 */ 	addiu	$a0,$t3,0x14
/*    31a28:	0c00f184 */ 	jal	func0003c610
/*    31a2c:	8d660048 */ 	lw	$a2,0x48($t3)
/*    31a30:	3c0d8006 */ 	lui	$t5,0x8006
/*    31a34:	8dadf12c */ 	lw	$t5,-0xed4($t5)
/*    31a38:	25a40014 */ 	addiu	$a0,$t5,0x14
/*    31a3c:	0c00f15b */ 	jal	func0003c56c
/*    31a40:	25a50028 */ 	addiu	$a1,$t5,0x28
/*    31a44:	3c0f8006 */ 	lui	$t7,0x8006
/*    31a48:	8deff12c */ 	lw	$t7,-0xed4($t7)
/*    31a4c:	ade2004c */ 	sw	$v0,0x4c($t7)
/*    31a50:	10000001 */ 	beqz	$zero,.L00031a58
/*    31a54:	00000000 */ 	sll	$zero,$zero,0x0
.L00031a58:
/*    31a58:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*    31a5c:	27bd0040 */ 	addiu	$sp,$sp,0x40
/*    31a60:	03e00008 */ 	jr	$ra
/*    31a64:	00000000 */ 	sll	$zero,$zero,0x0
/*    31a68:	27bdffd0 */ 	addiu	$sp,$sp,-48
/*    31a6c:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    31a70:	afa40030 */ 	sw	$a0,0x30($sp)
/*    31a74:	8fae0030 */ 	lw	$t6,0x30($sp)
/*    31a78:	afae002c */ 	sw	$t6,0x2c($sp)
.L00031a7c:
/*    31a7c:	8faf002c */ 	lw	$t7,0x2c($sp)
/*    31a80:	24010020 */ 	addiu	$at,$zero,0x20
/*    31a84:	85f80028 */ 	lh	$t8,0x28($t7)
/*    31a88:	1701000d */ 	bne	$t8,$at,.L00031ac0
/*    31a8c:	00000000 */ 	sll	$zero,$zero,0x0
/*    31a90:	10000001 */ 	beqz	$zero,.L00031a98
/*    31a94:	00000000 */ 	sll	$zero,$zero,0x0
.L00031a98:
/*    31a98:	24190020 */ 	addiu	$t9,$zero,0x20
/*    31a9c:	a7b9001c */ 	sh	$t9,0x1c($sp)
/*    31aa0:	8fa8002c */ 	lw	$t0,0x2c($sp)
/*    31aa4:	27a5001c */ 	addiu	$a1,$sp,0x1c
/*    31aa8:	24070001 */ 	addiu	$a3,$zero,0x1
/*    31aac:	25040014 */ 	addiu	$a0,$t0,0x14
/*    31ab0:	0c00f184 */ 	jal	func0003c610
/*    31ab4:	8d060048 */ 	lw	$a2,0x48($t0)
/*    31ab8:	10000006 */ 	beqz	$zero,.L00031ad4
/*    31abc:	00000000 */ 	sll	$zero,$zero,0x0
.L00031ac0:
/*    31ac0:	8fa4002c */ 	lw	$a0,0x2c($sp)
/*    31ac4:	0c00c6cd */ 	jal	func00031b34
/*    31ac8:	24840028 */ 	addiu	$a0,$a0,%lo(var80060028)
/*    31acc:	10000001 */ 	beqz	$zero,.L00031ad4
/*    31ad0:	00000000 */ 	sll	$zero,$zero,0x0
.L00031ad4:
/*    31ad4:	8fa9002c */ 	lw	$t1,0x2c($sp)
/*    31ad8:	25240014 */ 	addiu	$a0,$t1,0x14
/*    31adc:	0c00f15b */ 	jal	func0003c56c
/*    31ae0:	25250028 */ 	addiu	$a1,$t1,0x28
/*    31ae4:	8faa002c */ 	lw	$t2,0x2c($sp)
/*    31ae8:	ad42004c */ 	sw	$v0,0x4c($t2)
/*    31aec:	8fab002c */ 	lw	$t3,0x2c($sp)
/*    31af0:	8d6c004c */ 	lw	$t4,0x4c($t3)
/*    31af4:	1180ffe1 */ 	beqz	$t4,.L00031a7c
/*    31af8:	00000000 */ 	sll	$zero,$zero,0x0
/*    31afc:	8fad002c */ 	lw	$t5,0x2c($sp)
/*    31b00:	8dae0050 */ 	lw	$t6,0x50($t5)
/*    31b04:	8daf004c */ 	lw	$t7,0x4c($t5)
/*    31b08:	01cfc021 */ 	addu	$t8,$t6,$t7
/*    31b0c:	adb80050 */ 	sw	$t8,0x50($t5)
/*    31b10:	8fb9002c */ 	lw	$t9,0x2c($sp)
/*    31b14:	10000003 */ 	beqz	$zero,.L00031b24
/*    31b18:	8f22004c */ 	lw	$v0,0x4c($t9)
/*    31b1c:	10000001 */ 	beqz	$zero,.L00031b24
/*    31b20:	00000000 */ 	sll	$zero,$zero,0x0
.L00031b24:
/*    31b24:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    31b28:	27bd0030 */ 	addiu	$sp,$sp,0x30
/*    31b2c:	03e00008 */ 	jr	$ra
/*    31b30:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func00031b34
/*    31b34:	27bdff48 */ 	addiu	$sp,$sp,-184
/*    31b38:	afbf0034 */ 	sw	$ra,0x34($sp)
/*    31b3c:	afa400b8 */ 	sw	$a0,0xb8($sp)
/*    31b40:	afb10030 */ 	sw	$s1,0x30($sp)
/*    31b44:	afb0002c */ 	sw	$s0,0x2c($sp)
/*    31b48:	240e0001 */ 	addiu	$t6,$zero,0x1
/*    31b4c:	afae0068 */ 	sw	$t6,0x68($sp)
/*    31b50:	afa00064 */ 	sw	$zero,0x64($sp)
/*    31b54:	afa00060 */ 	sw	$zero,0x60($sp)
/*    31b58:	afa0005c */ 	sw	$zero,0x5c($sp)
.L00031b5c:
/*    31b5c:	8faf005c */ 	lw	$t7,0x5c($sp)
/*    31b60:	11e0000b */ 	beqz	$t7,.L00031b90
/*    31b64:	00000000 */ 	sll	$zero,$zero,0x0
/*    31b68:	8fb80060 */ 	lw	$t8,0x60($sp)
/*    31b6c:	afb80088 */ 	sw	$t8,0x88($sp)
/*    31b70:	8fb900b8 */ 	lw	$t9,0xb8($sp)
/*    31b74:	97280000 */ 	lhu	$t0,0x0($t9)
/*    31b78:	a7a80084 */ 	sh	$t0,0x84($sp)
/*    31b7c:	8fa900b8 */ 	lw	$t1,0xb8($sp)
/*    31b80:	8d2a0008 */ 	lw	$t2,0x8($t1)
/*    31b84:	afaa008c */ 	sw	$t2,0x8c($sp)
/*    31b88:	27ab0084 */ 	addiu	$t3,$sp,0x84
/*    31b8c:	afab00b8 */ 	sw	$t3,0xb8($sp)
.L00031b90:
/*    31b90:	8fac00b8 */ 	lw	$t4,0xb8($sp)
/*    31b94:	8d8d0004 */ 	lw	$t5,0x4($t4)
/*    31b98:	afad0060 */ 	sw	$t5,0x60($sp)
/*    31b9c:	8fae0060 */ 	lw	$t6,0x60($sp)
/*    31ba0:	3c018000 */ 	lui	$at,0x8000
/*    31ba4:	01c17824 */ 	and	$t7,$t6,$at
/*    31ba8:	15e00001 */ 	bnez	$t7,.L00031bb0
/*    31bac:	00000000 */ 	sll	$zero,$zero,0x0
.L00031bb0:
/*    31bb0:	8fb80060 */ 	lw	$t8,0x60($sp)
/*    31bb4:	8f190008 */ 	lw	$t9,0x8($t8)
/*    31bb8:	afb900ac */ 	sw	$t9,0xac($sp)
/*    31bbc:	8fa800ac */ 	lw	$t0,0xac($sp)
/*    31bc0:	15000006 */ 	bnez	$t0,.L00031bdc
/*    31bc4:	00000000 */ 	sll	$zero,$zero,0x0
/*    31bc8:	27a4005a */ 	addiu	$a0,$sp,0x5a
/*    31bcc:	0c00cc9d */ 	jal	func00033274
/*    31bd0:	27a50058 */ 	addiu	$a1,$sp,0x58
/*    31bd4:	10000529 */ 	beqz	$zero,.L0003307c
/*    31bd8:	00000000 */ 	sll	$zero,$zero,0x0
.L00031bdc:
/*    31bdc:	8fa900ac */ 	lw	$t1,0xac($sp)
/*    31be0:	8d2a0004 */ 	lw	$t2,0x4($t1)
/*    31be4:	afaa00a8 */ 	sw	$t2,0xa8($sp)
/*    31be8:	8fab0060 */ 	lw	$t3,0x60($sp)
/*    31bec:	8d6c0000 */ 	lw	$t4,0x0($t3)
/*    31bf0:	afac005c */ 	sw	$t4,0x5c($sp)
/*    31bf4:	8fad00b8 */ 	lw	$t5,0xb8($sp)
/*    31bf8:	95b00000 */ 	lhu	$s0,0x0($t5)
/*    31bfc:	2a010201 */ 	slti	$at,$s0,0x201
/*    31c00:	14200012 */ 	bnez	$at,.L00031c4c
/*    31c04:	00000000 */ 	sll	$zero,$zero,0x0
/*    31c08:	24010400 */ 	addiu	$at,$zero,0x400
/*    31c0c:	12010267 */ 	beq	$s0,$at,.L000325ac
/*    31c10:	00000000 */ 	sll	$zero,$zero,0x0
/*    31c14:	24010800 */ 	addiu	$at,$zero,0x800
/*    31c18:	120103ef */ 	beq	$s0,$at,.L00032bd8
/*    31c1c:	00000000 */ 	sll	$zero,$zero,0x0
/*    31c20:	24011000 */ 	addiu	$at,$zero,0x1000
/*    31c24:	12010261 */ 	beq	$s0,$at,.L000325ac
/*    31c28:	00000000 */ 	sll	$zero,$zero,0x0
/*    31c2c:	24012000 */ 	addiu	$at,$zero,0x2000
/*    31c30:	1201036a */ 	beq	$s0,$at,.L000329dc
/*    31c34:	00000000 */ 	sll	$zero,$zero,0x0
/*    31c38:	24014000 */ 	addiu	$at,$zero,0x4000
/*    31c3c:	12010330 */ 	beq	$s0,$at,.L00032900
/*    31c40:	00000000 */ 	sll	$zero,$zero,0x0
/*    31c44:	100004f2 */ 	beqz	$zero,.L00033010
/*    31c48:	00000000 */ 	sll	$zero,$zero,0x0
.L00031c4c:
/*    31c4c:	2a010081 */ 	slti	$at,$s0,0x81
/*    31c50:	14200009 */ 	bnez	$at,.L00031c78
/*    31c54:	00000000 */ 	sll	$zero,$zero,0x0
/*    31c58:	24010100 */ 	addiu	$at,$zero,0x100
/*    31c5c:	120102f7 */ 	beq	$s0,$at,.L0003283c
/*    31c60:	00000000 */ 	sll	$zero,$zero,0x0
/*    31c64:	24010200 */ 	addiu	$at,$zero,0x200
/*    31c68:	120104d3 */ 	beq	$s0,$at,.L00032fb8
/*    31c6c:	00000000 */ 	sll	$zero,$zero,0x0
/*    31c70:	100004e7 */ 	beqz	$zero,.L00033010
/*    31c74:	00000000 */ 	sll	$zero,$zero,0x0
.L00031c78:
/*    31c78:	2a010041 */ 	slti	$at,$s0,0x41
/*    31c7c:	14200006 */ 	bnez	$at,.L00031c98
/*    31c80:	00000000 */ 	sll	$zero,$zero,0x0
/*    31c84:	24010080 */ 	addiu	$at,$zero,0x80
/*    31c88:	120104c7 */ 	beq	$s0,$at,.L00032fa8
/*    31c8c:	00000000 */ 	sll	$zero,$zero,0x0
/*    31c90:	100004df */ 	beqz	$zero,.L00033010
/*    31c94:	00000000 */ 	sll	$zero,$zero,0x0
.L00031c98:
/*    31c98:	2a010011 */ 	slti	$at,$s0,0x11
/*    31c9c:	14200006 */ 	bnez	$at,.L00031cb8
/*    31ca0:	00000000 */ 	sll	$zero,$zero,0x0
/*    31ca4:	24010040 */ 	addiu	$at,$zero,0x40
/*    31ca8:	12010436 */ 	beq	$s0,$at,.L00032d84
/*    31cac:	00000000 */ 	sll	$zero,$zero,0x0
/*    31cb0:	100004d7 */ 	beqz	$zero,.L00033010
/*    31cb4:	00000000 */ 	sll	$zero,$zero,0x0
.L00031cb8:
/*    31cb8:	260effff */ 	addiu	$t6,$s0,-1
/*    31cbc:	2dc10010 */ 	sltiu	$at,$t6,0x10
/*    31cc0:	102004d3 */ 	beqz	$at,.L00033010
/*    31cc4:	00000000 */ 	sll	$zero,$zero,0x0
/*    31cc8:	000e7080 */ 	sll	$t6,$t6,0x2
/*    31ccc:	3c017005 */ 	lui	$at,%hi(var70054740)
/*    31cd0:	002e0821 */ 	addu	$at,$at,$t6
/*    31cd4:	8c2e4740 */ 	lw	$t6,%lo(var70054740)($at)
/*    31cd8:	01c00008 */ 	jr	$t6
/*    31cdc:	00000000 */ 	sll	$zero,$zero,0x0
/*    31ce0:	8faf0060 */ 	lw	$t7,0x60($sp)
/*    31ce4:	24010005 */ 	addiu	$at,$zero,0x5
/*    31ce8:	91f80045 */ 	lbu	$t8,0x45($t7)
/*    31cec:	13010006 */ 	beq	$t8,$at,.L00031d08
/*    31cf0:	00000000 */ 	sll	$zero,$zero,0x0
/*    31cf4:	24010004 */ 	addiu	$at,$zero,0x4
/*    31cf8:	13010003 */ 	beq	$t8,$at,.L00031d08
/*    31cfc:	00000000 */ 	sll	$zero,$zero,0x0
/*    31d00:	100004de */ 	beqz	$zero,.L0003307c
/*    31d04:	00000000 */ 	sll	$zero,$zero,0x0
.L00031d08:
/*    31d08:	8fb90060 */ 	lw	$t9,0x60($sp)
/*    31d0c:	93280043 */ 	lbu	$t0,0x43($t9)
/*    31d10:	a7a800b2 */ 	sh	$t0,0xb2($sp)
/*    31d14:	8fa90060 */ 	lw	$t1,0x60($sp)
/*    31d18:	912a0040 */ 	lbu	$t2,0x40($t1)
/*    31d1c:	a7aa00b0 */ 	sh	$t2,0xb0($sp)
/*    31d20:	a3a000b4 */ 	sb	$zero,0xb4($sp)
/*    31d24:	3c0c8006 */ 	lui	$t4,0x8006
/*    31d28:	8d8cf12c */ 	lw	$t4,-0xed4($t4)
/*    31d2c:	3c0b8006 */ 	lui	$t3,0x8006
/*    31d30:	856bf130 */ 	lh	$t3,-0xed0($t3)
/*    31d34:	8d8d0044 */ 	lw	$t5,0x44($t4)
/*    31d38:	016d702a */ 	slt	$t6,$t3,$t5
/*    31d3c:	39ce0001 */ 	xori	$t6,$t6,0x1
/*    31d40:	afae0070 */ 	sw	$t6,0x70($sp)
/*    31d44:	8faf0070 */ 	lw	$t7,0x70($sp)
/*    31d48:	11e00006 */ 	beqz	$t7,.L00031d64
/*    31d4c:	00000000 */ 	sll	$zero,$zero,0x0
/*    31d50:	8fb80060 */ 	lw	$t8,0x60($sp)
/*    31d54:	93190044 */ 	lbu	$t9,0x44($t8)
/*    31d58:	33280010 */ 	andi	$t0,$t9,0x10
/*    31d5c:	11000006 */ 	beqz	$t0,.L00031d78
/*    31d60:	00000000 */ 	sll	$zero,$zero,0x0
.L00031d64:
/*    31d64:	8fa40060 */ 	lw	$a0,0x60($sp)
/*    31d68:	27a500b0 */ 	addiu	$a1,$sp,0xb0
/*    31d6c:	0c00f278 */ 	jal	func0003c9e0
/*    31d70:	2484000c */ 	addiu	$a0,$a0,0xc
/*    31d74:	afa20064 */ 	sw	$v0,0x64($sp)
.L00031d78:
/*    31d78:	8fa90064 */ 	lw	$t1,0x64($sp)
/*    31d7c:	1520005f */ 	bnez	$t1,.L00031efc
/*    31d80:	00000000 */ 	sll	$zero,$zero,0x0
/*    31d84:	8faa0060 */ 	lw	$t2,0x60($sp)
/*    31d88:	914c0044 */ 	lbu	$t4,0x44($t2)
/*    31d8c:	318b0012 */ 	andi	$t3,$t4,0x12
/*    31d90:	15600004 */ 	bnez	$t3,.L00031da4
/*    31d94:	00000000 */ 	sll	$zero,$zero,0x0
/*    31d98:	8d4d0034 */ 	lw	$t5,0x34($t2)
/*    31d9c:	19a00011 */ 	blez	$t5,.L00031de4
/*    31da0:	00000000 */ 	sll	$zero,$zero,0x0
.L00031da4:
/*    31da4:	8faf0060 */ 	lw	$t7,0x60($sp)
/*    31da8:	240e0004 */ 	addiu	$t6,$zero,0x4
/*    31dac:	a1ee0045 */ 	sb	$t6,0x45($t7)
/*    31db0:	8fb80060 */ 	lw	$t8,0x60($sp)
/*    31db4:	8f190034 */ 	lw	$t9,0x34($t8)
/*    31db8:	2728ffff */ 	addiu	$t0,$t9,-1
/*    31dbc:	af080034 */ 	sw	$t0,0x34($t8)
/*    31dc0:	3c048006 */ 	lui	$a0,%hi(var80060014)
/*    31dc4:	8c84f12c */ 	lw	$a0,-0xed4($a0)
/*    31dc8:	8fa500b8 */ 	lw	$a1,0xb8($sp)
/*    31dcc:	34068235 */ 	dli	$a2,0x8235
/*    31dd0:	00003825 */ 	or	$a3,$zero,$zero
/*    31dd4:	0c00f184 */ 	jal	func0003c610
/*    31dd8:	24840014 */ 	addiu	$a0,$a0,%lo(var80060014)
/*    31ddc:	10000045 */ 	beqz	$zero,.L00031ef4
/*    31de0:	00000000 */ 	sll	$zero,$zero,0x0
.L00031de4:
/*    31de4:	8fa90070 */ 	lw	$t1,0x70($sp)
/*    31de8:	11200040 */ 	beqz	$t1,.L00031eec
/*    31dec:	00000000 */ 	sll	$zero,$zero,0x0
/*    31df0:	3c0c8006 */ 	lui	$t4,0x8006
/*    31df4:	8d8cf124 */ 	lw	$t4,-0xedc($t4)
/*    31df8:	afac0054 */ 	sw	$t4,0x54($sp)
.L00031dfc:
/*    31dfc:	8fab0054 */ 	lw	$t3,0x54($sp)
/*    31e00:	916a0044 */ 	lbu	$t2,0x44($t3)
/*    31e04:	314d0012 */ 	andi	$t5,$t2,0x12
/*    31e08:	15a0001c */ 	bnez	$t5,.L00031e7c
/*    31e0c:	00000000 */ 	sll	$zero,$zero,0x0
/*    31e10:	314e0004 */ 	andi	$t6,$t2,0x4
/*    31e14:	11c00019 */ 	beqz	$t6,.L00031e7c
/*    31e18:	00000000 */ 	sll	$zero,$zero,0x0
/*    31e1c:	916f0045 */ 	lbu	$t7,0x45($t3)
/*    31e20:	24010003 */ 	addiu	$at,$zero,0x3
/*    31e24:	11e10015 */ 	beq	$t7,$at,.L00031e7c
/*    31e28:	00000000 */ 	sll	$zero,$zero,0x0
/*    31e2c:	afa00070 */ 	sw	$zero,0x70($sp)
/*    31e30:	24190080 */ 	addiu	$t9,$zero,0x80
/*    31e34:	a7b90044 */ 	sh	$t9,0x44($sp)
/*    31e38:	8fa80054 */ 	lw	$t0,0x54($sp)
/*    31e3c:	afa80048 */ 	sw	$t0,0x48($sp)
/*    31e40:	8fa90054 */ 	lw	$t1,0x54($sp)
/*    31e44:	24180003 */ 	addiu	$t8,$zero,0x3
/*    31e48:	a1380045 */ 	sb	$t8,0x45($t1)
/*    31e4c:	3c048006 */ 	lui	$a0,%hi(var80060014)
/*    31e50:	8c84f12c */ 	lw	$a0,-0xed4($a0)
/*    31e54:	27a50044 */ 	addiu	$a1,$sp,0x44
/*    31e58:	240603e8 */ 	addiu	$a2,$zero,0x3e8
/*    31e5c:	00003825 */ 	or	$a3,$zero,$zero
/*    31e60:	0c00f184 */ 	jal	func0003c610
/*    31e64:	24840014 */ 	addiu	$a0,$a0,%lo(var80060014)
/*    31e68:	8fa40054 */ 	lw	$a0,0x54($sp)
/*    31e6c:	00002825 */ 	or	$a1,$zero,$zero
/*    31e70:	240603e8 */ 	addiu	$a2,$zero,0x3e8
/*    31e74:	0c00f33c */ 	jal	func0003ccf0
/*    31e78:	2484000c */ 	addiu	$a0,$a0,0xc
.L00031e7c:
/*    31e7c:	8fac0054 */ 	lw	$t4,0x54($sp)
/*    31e80:	8d8d0004 */ 	lw	$t5,0x4($t4)
/*    31e84:	afad0054 */ 	sw	$t5,0x54($sp)
/*    31e88:	8faa0070 */ 	lw	$t2,0x70($sp)
/*    31e8c:	11400004 */ 	beqz	$t2,.L00031ea0
/*    31e90:	00000000 */ 	sll	$zero,$zero,0x0
/*    31e94:	8fae0054 */ 	lw	$t6,0x54($sp)
/*    31e98:	15c0ffd8 */ 	bnez	$t6,.L00031dfc
/*    31e9c:	00000000 */ 	sll	$zero,$zero,0x0
.L00031ea0:
/*    31ea0:	8fab0070 */ 	lw	$t3,0x70($sp)
/*    31ea4:	1560000d */ 	bnez	$t3,.L00031edc
/*    31ea8:	00000000 */ 	sll	$zero,$zero,0x0
/*    31eac:	8fb90060 */ 	lw	$t9,0x60($sp)
/*    31eb0:	240f0002 */ 	addiu	$t7,$zero,0x2
/*    31eb4:	af2f0034 */ 	sw	$t7,0x34($t9)
/*    31eb8:	3c048006 */ 	lui	$a0,%hi(var80060014)
/*    31ebc:	8c84f12c */ 	lw	$a0,-0xed4($a0)
/*    31ec0:	8fa500b8 */ 	lw	$a1,0xb8($sp)
/*    31ec4:	240603e9 */ 	addiu	$a2,$zero,0x3e9
/*    31ec8:	00003825 */ 	or	$a3,$zero,$zero
/*    31ecc:	0c00f184 */ 	jal	func0003c610
/*    31ed0:	24840014 */ 	addiu	$a0,$a0,%lo(var80060014)
/*    31ed4:	10000003 */ 	beqz	$zero,.L00031ee4
/*    31ed8:	00000000 */ 	sll	$zero,$zero,0x0
.L00031edc:
/*    31edc:	0c00cc24 */ 	jal	func00033090
/*    31ee0:	8fa40060 */ 	lw	$a0,0x60($sp)
.L00031ee4:
/*    31ee4:	10000003 */ 	beqz	$zero,.L00031ef4
/*    31ee8:	00000000 */ 	sll	$zero,$zero,0x0
.L00031eec:
/*    31eec:	0c00cc24 */ 	jal	func00033090
/*    31ef0:	8fa40060 */ 	lw	$a0,0x60($sp)
.L00031ef4:
/*    31ef4:	10000461 */ 	beqz	$zero,.L0003307c
/*    31ef8:	00000000 */ 	sll	$zero,$zero,0x0
.L00031efc:
/*    31efc:	8fa800ac */ 	lw	$t0,0xac($sp)
/*    31f00:	8fac0060 */ 	lw	$t4,0x60($sp)
/*    31f04:	8d180000 */ 	lw	$t8,0x0($t0)
/*    31f08:	c588002c */ 	lwc1	$f8,0x2c($t4)
/*    31f0c:	c5900028 */ 	lwc1	$f16,0x28($t4)
/*    31f10:	8f090000 */ 	lw	$t1,0x0($t8)
/*    31f14:	44892000 */ 	mtc1	$t1,$f4
/*    31f18:	00000000 */ 	sll	$zero,$zero,0x0
/*    31f1c:	468021a0 */ 	cvt.s.w	$f6,$f4
/*    31f20:	46083283 */ 	div.s	$f10,$f6,$f8
/*    31f24:	46105483 */ 	div.s	$f18,$f10,$f16
/*    31f28:	4600910d */ 	trunc.w.s	$f4,$f18
/*    31f2c:	440a2000 */ 	mfc1	$t2,$f4
/*    31f30:	00000000 */ 	sll	$zero,$zero,0x0
/*    31f34:	afaa0080 */ 	sw	$t2,0x80($sp)
/*    31f38:	8fae0060 */ 	lw	$t6,0x60($sp)
/*    31f3c:	91cb0044 */ 	lbu	$t3,0x44($t6)
/*    31f40:	316f0002 */ 	andi	$t7,$t3,0x2
/*    31f44:	11e00004 */ 	beqz	$t7,.L00031f58
/*    31f48:	00000000 */ 	sll	$zero,$zero,0x0
/*    31f4c:	8fb90060 */ 	lw	$t9,0x60($sp)
/*    31f50:	10000029 */ 	beqz	$zero,.L00031ff8
/*    31f54:	af200048 */ 	sw	$zero,0x48($t9)
.L00031f58:
/*    31f58:	8fa800ac */ 	lw	$t0,0xac($sp)
/*    31f5c:	8fac0060 */ 	lw	$t4,0x60($sp)
/*    31f60:	8d180000 */ 	lw	$t8,0x0($t0)
/*    31f64:	c58a002c */ 	lwc1	$f10,0x2c($t4)
/*    31f68:	c5920028 */ 	lwc1	$f18,0x28($t4)
/*    31f6c:	8f090004 */ 	lw	$t1,0x4($t8)
/*    31f70:	44893000 */ 	mtc1	$t1,$f6
/*    31f74:	00000000 */ 	sll	$zero,$zero,0x0
/*    31f78:	46803220 */ 	cvt.s.w	$f8,$f6
/*    31f7c:	460a4403 */ 	div.s	$f16,$f8,$f10
/*    31f80:	46128103 */ 	div.s	$f4,$f16,$f18
/*    31f84:	4600218d */ 	trunc.w.s	$f6,$f4
/*    31f88:	440a3000 */ 	mfc1	$t2,$f6
/*    31f8c:	00000000 */ 	sll	$zero,$zero,0x0
/*    31f90:	afaa0040 */ 	sw	$t2,0x40($sp)
/*    31f94:	8fae0040 */ 	lw	$t6,0x40($sp)
/*    31f98:	3c010053 */ 	lui	$at,0x53
/*    31f9c:	3421ec61 */ 	ori	$at,$at,0xec61
/*    31fa0:	01c1082a */ 	slt	$at,$t6,$at
/*    31fa4:	14200004 */ 	bnez	$at,.L00031fb8
/*    31fa8:	00000000 */ 	sll	$zero,$zero,0x0
/*    31fac:	3c0b0053 */ 	lui	$t3,0x53
/*    31fb0:	356bec60 */ 	ori	$t3,$t3,0xec60
/*    31fb4:	afab0040 */ 	sw	$t3,0x40($sp)
.L00031fb8:
/*    31fb8:	3c198006 */ 	lui	$t9,0x8006
/*    31fbc:	8f39f12c */ 	lw	$t9,-0xed4($t9)
/*    31fc0:	8faf0040 */ 	lw	$t7,0x40($sp)
/*    31fc4:	8fac0060 */ 	lw	$t4,0x60($sp)
/*    31fc8:	8f280050 */ 	lw	$t0,0x50($t9)
/*    31fcc:	3c01000f */ 	lui	$at,0xf
/*    31fd0:	34214240 */ 	ori	$at,$at,0x4240
/*    31fd4:	01e8c021 */ 	addu	$t8,$t7,$t0
/*    31fd8:	03014821 */ 	addu	$t1,$t8,$at
/*    31fdc:	ad890048 */ 	sw	$t1,0x48($t4)
/*    31fe0:	8fad0060 */ 	lw	$t5,0x60($sp)
/*    31fe4:	8daa0048 */ 	lw	$t2,0x48($t5)
/*    31fe8:	05410003 */ 	bgez	$t2,.L00031ff8
/*    31fec:	00000000 */ 	sll	$zero,$zero,0x0
/*    31ff0:	8fae0060 */ 	lw	$t6,0x60($sp)
/*    31ff4:	adc00048 */ 	sw	$zero,0x48($t6)
.L00031ff8:
/*    31ff8:	8fab0080 */ 	lw	$t3,0x80($sp)
/*    31ffc:	3c010053 */ 	lui	$at,0x53
/*    32000:	3421ec61 */ 	ori	$at,$at,0xec61
/*    32004:	0161082a */ 	slt	$at,$t3,$at
/*    32008:	14200005 */ 	bnez	$at,.L00032020
/*    3200c:	00000000 */ 	sll	$zero,$zero,0x0
/*    32010:	0c00cc24 */ 	jal	func00033090
/*    32014:	8fa40060 */ 	lw	$a0,0x60($sp)
/*    32018:	10000418 */ 	beqz	$zero,.L0003307c
/*    3201c:	00000000 */ 	sll	$zero,$zero,0x0
.L00032020:
/*    32020:	8fb90060 */ 	lw	$t9,0x60($sp)
/*    32024:	932f0044 */ 	lbu	$t7,0x44($t9)
/*    32028:	35e80004 */ 	ori	$t0,$t7,0x4
/*    3202c:	a3280044 */ 	sb	$t0,0x44($t9)
/*    32030:	8fb800ac */ 	lw	$t8,0xac($sp)
/*    32034:	8fad0060 */ 	lw	$t5,0x60($sp)
/*    32038:	8f090000 */ 	lw	$t1,0x0($t8)
/*    3203c:	912c000c */ 	lbu	$t4,0xc($t1)
/*    32040:	a5ac003a */ 	sh	$t4,0x3a($t5)
/*    32044:	87aa00b2 */ 	lh	$t2,0xb2($sp)
/*    32048:	8fae0060 */ 	lw	$t6,0x60($sp)
/*    3204c:	a1ca0043 */ 	sb	$t2,0x43($t6)
/*    32050:	3c0b8006 */ 	lui	$t3,0x8006
/*    32054:	8d6bf12c */ 	lw	$t3,-0xed4($t3)
/*    32058:	8fa80080 */ 	lw	$t0,0x80($sp)
/*    3205c:	8fb80060 */ 	lw	$t8,0x60($sp)
/*    32060:	8d6f0050 */ 	lw	$t7,0x50($t3)
/*    32064:	01e8c821 */ 	addu	$t9,$t7,$t0
/*    32068:	af19003c */ 	sw	$t9,0x3c($t8)
/*    3206c:	8fa80060 */ 	lw	$t0,0x60($sp)
/*    32070:	8fac00a8 */ 	lw	$t4,0xa8($sp)
/*    32074:	3c09800a */ 	lui	$t1,0x800a
/*    32078:	8519003a */ 	lh	$t9,0x3a($t0)
/*    3207c:	85180038 */ 	lh	$t8,0x38($t0)
/*    32080:	918d0002 */ 	lbu	$t5,0x2($t4)
/*    32084:	8d29c334 */ 	lw	$t1,-0x3ccc($t1)
/*    32088:	03380019 */ 	multu	$t9,$t8
/*    3208c:	31aa001f */ 	andi	$t2,$t5,0x1f
/*    32090:	8fad00ac */ 	lw	$t5,0xac($sp)
/*    32094:	000a7040 */ 	sll	$t6,$t2,0x1
/*    32098:	012e5821 */ 	addu	$t3,$t1,$t6
/*    3209c:	91aa000d */ 	lbu	$t2,0xd($t5)
/*    320a0:	24013f01 */ 	addiu	$at,$zero,0x3f01
/*    320a4:	856f0000 */ 	lh	$t7,0x0($t3)
/*    320a8:	00006012 */ 	mflo	$t4
/*    320ac:	00000000 */ 	sll	$zero,$zero,0x0
/*    320b0:	00000000 */ 	sll	$zero,$zero,0x0
/*    320b4:	018a0019 */ 	multu	$t4,$t2
/*    320b8:	00004812 */ 	mflo	$t1
/*    320bc:	00000000 */ 	sll	$zero,$zero,0x0
/*    320c0:	00000000 */ 	sll	$zero,$zero,0x0
/*    320c4:	0121001a */ 	div	$zero,$t1,$at
/*    320c8:	00007012 */ 	mflo	$t6
/*    320cc:	24017fff */ 	addiu	$at,$zero,0x7fff
/*    320d0:	00000000 */ 	sll	$zero,$zero,0x0
/*    320d4:	01ee0019 */ 	multu	$t7,$t6
/*    320d8:	00005812 */ 	mflo	$t3
/*    320dc:	00000000 */ 	sll	$zero,$zero,0x0
/*    320e0:	00000000 */ 	sll	$zero,$zero,0x0
/*    320e4:	0161001a */ 	div	$zero,$t3,$at
/*    320e8:	00004012 */ 	mflo	$t0
/*    320ec:	1d000003 */ 	bgtz	$t0,.L000320fc
/*    320f0:	00000000 */ 	sll	$zero,$zero,0x0
/*    320f4:	10000023 */ 	beqz	$zero,.L00032184
/*    320f8:	afa00078 */ 	sw	$zero,0x78($sp)
.L000320fc:
/*    320fc:	8fae0060 */ 	lw	$t6,0x60($sp)
/*    32100:	8fb800a8 */ 	lw	$t8,0xa8($sp)
/*    32104:	3c19800a */ 	lui	$t9,0x800a
/*    32108:	85cb003a */ 	lh	$t3,0x3a($t6)
/*    3210c:	85c80038 */ 	lh	$t0,0x38($t6)
/*    32110:	930d0002 */ 	lbu	$t5,0x2($t8)
/*    32114:	8f39c334 */ 	lw	$t9,-0x3ccc($t9)
/*    32118:	01680019 */ 	multu	$t3,$t0
/*    3211c:	31ac001f */ 	andi	$t4,$t5,0x1f
/*    32120:	8fad00ac */ 	lw	$t5,0xac($sp)
/*    32124:	000c5040 */ 	sll	$t2,$t4,0x1
/*    32128:	032a4821 */ 	addu	$t1,$t9,$t2
/*    3212c:	91ac000d */ 	lbu	$t4,0xd($t5)
/*    32130:	24013f01 */ 	addiu	$at,$zero,0x3f01
/*    32134:	852f0000 */ 	lh	$t7,0x0($t1)
/*    32138:	0000c012 */ 	mflo	$t8
/*    3213c:	00000000 */ 	sll	$zero,$zero,0x0
/*    32140:	00000000 */ 	sll	$zero,$zero,0x0
/*    32144:	030c0019 */ 	multu	$t8,$t4
/*    32148:	0000c812 */ 	mflo	$t9
/*    3214c:	00000000 */ 	sll	$zero,$zero,0x0
/*    32150:	00000000 */ 	sll	$zero,$zero,0x0
/*    32154:	0321001a */ 	div	$zero,$t9,$at
/*    32158:	00005012 */ 	mflo	$t2
/*    3215c:	24017fff */ 	addiu	$at,$zero,0x7fff
/*    32160:	00000000 */ 	sll	$zero,$zero,0x0
/*    32164:	01ea0019 */ 	multu	$t7,$t2
/*    32168:	00004812 */ 	mflo	$t1
/*    3216c:	00000000 */ 	sll	$zero,$zero,0x0
/*    32170:	00000000 */ 	sll	$zero,$zero,0x0
/*    32174:	0121001a */ 	div	$zero,$t1,$at
/*    32178:	00007012 */ 	mflo	$t6
/*    3217c:	25cbffff */ 	addiu	$t3,$t6,-1
/*    32180:	afab0078 */ 	sw	$t3,0x78($sp)
.L00032184:
/*    32184:	8fa80060 */ 	lw	$t0,0x60($sp)
/*    32188:	8fb800ac */ 	lw	$t8,0xac($sp)
/*    3218c:	910d0041 */ 	lbu	$t5,0x41($t0)
/*    32190:	930c000c */ 	lbu	$t4,0xc($t8)
/*    32194:	01acc821 */ 	addu	$t9,$t5,$t4
/*    32198:	272fffc0 */ 	addiu	$t7,$t9,-64
/*    3219c:	afaf0074 */ 	sw	$t7,0x74($sp)
/*    321a0:	8faa0074 */ 	lw	$t2,0x74($sp)
/*    321a4:	19400003 */ 	blez	$t2,.L000321b4
/*    321a8:	00000000 */ 	sll	$zero,$zero,0x0
/*    321ac:	10000002 */ 	beqz	$zero,.L000321b8
/*    321b0:	01408025 */ 	or	$s0,$t2,$zero
.L000321b4:
/*    321b4:	00008025 */ 	or	$s0,$zero,$zero
.L000321b8:
/*    321b8:	2a01007f */ 	slti	$at,$s0,0x7f
/*    321bc:	10200009 */ 	beqz	$at,.L000321e4
/*    321c0:	00000000 */ 	sll	$zero,$zero,0x0
/*    321c4:	8fa90074 */ 	lw	$t1,0x74($sp)
/*    321c8:	19200003 */ 	blez	$t1,.L000321d8
/*    321cc:	00000000 */ 	sll	$zero,$zero,0x0
/*    321d0:	10000002 */ 	beqz	$zero,.L000321dc
/*    321d4:	01208825 */ 	or	$s1,$t1,$zero
.L000321d8:
/*    321d8:	00008825 */ 	or	$s1,$zero,$zero
.L000321dc:
/*    321dc:	10000003 */ 	beqz	$zero,.L000321ec
/*    321e0:	a3b100a7 */ 	sb	$s1,0xa7($sp)
.L000321e4:
/*    321e4:	240e007f */ 	addiu	$t6,$zero,0x7f
/*    321e8:	a3ae00a7 */ 	sb	$t6,0xa7($sp)
.L000321ec:
/*    321ec:	8fad00a8 */ 	lw	$t5,0xa8($sp)
/*    321f0:	8fab0060 */ 	lw	$t3,0x60($sp)
/*    321f4:	91ac0003 */ 	lbu	$t4,0x3($t5)
/*    321f8:	91680042 */ 	lbu	$t0,0x42($t3)
/*    321fc:	3199000f */ 	andi	$t9,$t4,0xf
/*    32200:	001978c0 */ 	sll	$t7,$t9,0x3
/*    32204:	3118007f */ 	andi	$t8,$t0,0x7f
/*    32208:	030f5021 */ 	addu	$t2,$t8,$t7
/*    3220c:	afaa007c */ 	sw	$t2,0x7c($sp)
/*    32210:	8fa9007c */ 	lw	$t1,0x7c($sp)
/*    32214:	05210003 */ 	bgez	$t1,.L00032224
/*    32218:	00000000 */ 	sll	$zero,$zero,0x0
/*    3221c:	10000002 */ 	beqz	$zero,.L00032228
/*    32220:	00008025 */ 	or	$s0,$zero,$zero
.L00032224:
/*    32224:	8fb0007c */ 	lw	$s0,0x7c($sp)
.L00032228:
/*    32228:	2a010080 */ 	slti	$at,$s0,0x80
/*    3222c:	14200004 */ 	bnez	$at,.L00032240
/*    32230:	00000000 */ 	sll	$zero,$zero,0x0
/*    32234:	240e007f */ 	addiu	$t6,$zero,0x7f
/*    32238:	10000008 */ 	beqz	$zero,.L0003225c
/*    3223c:	afae007c */ 	sw	$t6,0x7c($sp)
.L00032240:
/*    32240:	8fab007c */ 	lw	$t3,0x7c($sp)
/*    32244:	05610003 */ 	bgez	$t3,.L00032254
/*    32248:	00000000 */ 	sll	$zero,$zero,0x0
/*    3224c:	10000002 */ 	beqz	$zero,.L00032258
/*    32250:	00008825 */ 	or	$s1,$zero,$zero
.L00032254:
/*    32254:	8fb1007c */ 	lw	$s1,0x7c($sp)
.L00032258:
/*    32258:	afb1007c */ 	sw	$s1,0x7c($sp)
.L0003225c:
/*    3225c:	8fad0060 */ 	lw	$t5,0x60($sp)
/*    32260:	8fa8007c */ 	lw	$t0,0x7c($sp)
/*    32264:	91ac0042 */ 	lbu	$t4,0x42($t5)
/*    32268:	31990080 */ 	andi	$t9,$t4,0x80
/*    3226c:	0119c025 */ 	or	$t8,$t0,$t9
/*    32270:	afb8007c */ 	sw	$t8,0x7c($sp)
/*    32274:	8faf0060 */ 	lw	$t7,0x60($sp)
/*    32278:	8faa00ac */ 	lw	$t2,0xac($sp)
/*    3227c:	93a900a7 */ 	lbu	$t1,0xa7($sp)
/*    32280:	c5e8002c */ 	lwc1	$f8,0x2c($t7)
/*    32284:	c5ea0028 */ 	lwc1	$f10,0x28($t7)
/*    32288:	8d450008 */ 	lw	$a1,0x8($t2)
/*    3228c:	8fae007c */ 	lw	$t6,0x7c($sp)
/*    32290:	460a4402 */ 	mul.s	$f16,$f8,$f10
/*    32294:	44809000 */ 	mtc1	$zero,$f18
/*    32298:	8fab0080 */ 	lw	$t3,0x80($sp)
/*    3229c:	afa00020 */ 	sw	$zero,0x20($sp)
/*    322a0:	afa00018 */ 	sw	$zero,0x18($sp)
/*    322a4:	8fa70078 */ 	lw	$a3,0x78($sp)
/*    322a8:	25e4000c */ 	addiu	$a0,$t7,0xc
/*    322ac:	44068000 */ 	mfc1	$a2,$f16
/*    322b0:	afa90010 */ 	sw	$t1,0x10($sp)
/*    322b4:	afae0014 */ 	sw	$t6,0x14($sp)
/*    322b8:	afab0024 */ 	sw	$t3,0x24($sp)
/*    322bc:	0c00f370 */ 	jal	func0003cdc0
/*    322c0:	e7b2001c */ 	swc1	$f18,0x1c($sp)
/*    322c4:	8fac0060 */ 	lw	$t4,0x60($sp)
/*    322c8:	240d0001 */ 	addiu	$t5,$zero,0x1
/*    322cc:	a18d0045 */ 	sb	$t5,0x45($t4)
/*    322d0:	3c088006 */ 	lui	$t0,0x8006
/*    322d4:	8508f130 */ 	lh	$t0,-0xed0($t0)
/*    322d8:	3c018006 */ 	lui	$at,0x8006
/*    322dc:	25190001 */ 	addiu	$t9,$t0,0x1
/*    322e0:	a439f130 */ 	sh	$t9,-0xed0($at)
/*    322e4:	8fb80060 */ 	lw	$t8,0x60($sp)
/*    322e8:	930a0044 */ 	lbu	$t2,0x44($t8)
/*    322ec:	314f0002 */ 	andi	$t7,$t2,0x2
/*    322f0:	15e000ac */ 	bnez	$t7,.L000325a4
/*    322f4:	00000000 */ 	sll	$zero,$zero,0x0
/*    322f8:	8fa90080 */ 	lw	$t1,0x80($sp)
/*    322fc:	15200085 */ 	bnez	$t1,.L00032514
/*    32300:	00000000 */ 	sll	$zero,$zero,0x0
/*    32304:	8fae00ac */ 	lw	$t6,0xac($sp)
/*    32308:	8fac0060 */ 	lw	$t4,0x60($sp)
/*    3230c:	8dcb0000 */ 	lw	$t3,0x0($t6)
/*    32310:	916d000d */ 	lbu	$t5,0xd($t3)
/*    32314:	a58d003a */ 	sh	$t5,0x3a($t4)
/*    32318:	8fab0060 */ 	lw	$t3,0x60($sp)
/*    3231c:	8fb900a8 */ 	lw	$t9,0xa8($sp)
/*    32320:	3c08800a */ 	lui	$t0,0x800a
/*    32324:	856d003a */ 	lh	$t5,0x3a($t3)
/*    32328:	856c0038 */ 	lh	$t4,0x38($t3)
/*    3232c:	93380002 */ 	lbu	$t8,0x2($t9)
/*    32330:	8d08c334 */ 	lw	$t0,-0x3ccc($t0)
/*    32334:	01ac0019 */ 	multu	$t5,$t4
/*    32338:	330a001f */ 	andi	$t2,$t8,0x1f
/*    3233c:	8fb800ac */ 	lw	$t8,0xac($sp)
/*    32340:	000a7840 */ 	sll	$t7,$t2,0x1
/*    32344:	010f4821 */ 	addu	$t1,$t0,$t7
/*    32348:	930a000d */ 	lbu	$t2,0xd($t8)
/*    3234c:	24013f01 */ 	addiu	$at,$zero,0x3f01
/*    32350:	852e0000 */ 	lh	$t6,0x0($t1)
/*    32354:	0000c812 */ 	mflo	$t9
/*    32358:	00000000 */ 	sll	$zero,$zero,0x0
/*    3235c:	00000000 */ 	sll	$zero,$zero,0x0
/*    32360:	032a0019 */ 	multu	$t9,$t2
/*    32364:	00004012 */ 	mflo	$t0
/*    32368:	00000000 */ 	sll	$zero,$zero,0x0
/*    3236c:	00000000 */ 	sll	$zero,$zero,0x0
/*    32370:	0101001a */ 	div	$zero,$t0,$at
/*    32374:	00007812 */ 	mflo	$t7
/*    32378:	24017fff */ 	addiu	$at,$zero,0x7fff
/*    3237c:	00000000 */ 	sll	$zero,$zero,0x0
/*    32380:	01cf0019 */ 	multu	$t6,$t7
/*    32384:	00004812 */ 	mflo	$t1
/*    32388:	00000000 */ 	sll	$zero,$zero,0x0
/*    3238c:	00000000 */ 	sll	$zero,$zero,0x0
/*    32390:	0121001a */ 	div	$zero,$t1,$at
/*    32394:	00005812 */ 	mflo	$t3
/*    32398:	1d600003 */ 	bgtz	$t3,.L000323a8
/*    3239c:	00000000 */ 	sll	$zero,$zero,0x0
/*    323a0:	10000023 */ 	beqz	$zero,.L00032430
/*    323a4:	afa00078 */ 	sw	$zero,0x78($sp)
.L000323a8:
/*    323a8:	8faf0060 */ 	lw	$t7,0x60($sp)
/*    323ac:	8fac00a8 */ 	lw	$t4,0xa8($sp)
/*    323b0:	3c0d800a */ 	lui	$t5,0x800a
/*    323b4:	85e9003a */ 	lh	$t1,0x3a($t7)
/*    323b8:	85eb0038 */ 	lh	$t3,0x38($t7)
/*    323bc:	91980002 */ 	lbu	$t8,0x2($t4)
/*    323c0:	8dadc334 */ 	lw	$t5,-0x3ccc($t5)
/*    323c4:	012b0019 */ 	multu	$t1,$t3
/*    323c8:	3319001f */ 	andi	$t9,$t8,0x1f
/*    323cc:	8fb800ac */ 	lw	$t8,0xac($sp)
/*    323d0:	00195040 */ 	sll	$t2,$t9,0x1
/*    323d4:	01aa4021 */ 	addu	$t0,$t5,$t2
/*    323d8:	9319000d */ 	lbu	$t9,0xd($t8)
/*    323dc:	24013f01 */ 	addiu	$at,$zero,0x3f01
/*    323e0:	850e0000 */ 	lh	$t6,0x0($t0)
/*    323e4:	00006012 */ 	mflo	$t4
/*    323e8:	00000000 */ 	sll	$zero,$zero,0x0
/*    323ec:	00000000 */ 	sll	$zero,$zero,0x0
/*    323f0:	01990019 */ 	multu	$t4,$t9
/*    323f4:	00006812 */ 	mflo	$t5
/*    323f8:	00000000 */ 	sll	$zero,$zero,0x0
/*    323fc:	00000000 */ 	sll	$zero,$zero,0x0
/*    32400:	01a1001a */ 	div	$zero,$t5,$at
/*    32404:	00005012 */ 	mflo	$t2
/*    32408:	24017fff */ 	addiu	$at,$zero,0x7fff
/*    3240c:	00000000 */ 	sll	$zero,$zero,0x0
/*    32410:	01ca0019 */ 	multu	$t6,$t2
/*    32414:	00004012 */ 	mflo	$t0
/*    32418:	00000000 */ 	sll	$zero,$zero,0x0
/*    3241c:	00000000 */ 	sll	$zero,$zero,0x0
/*    32420:	0101001a */ 	div	$zero,$t0,$at
/*    32424:	00007812 */ 	mflo	$t7
/*    32428:	25e9ffff */ 	addiu	$t1,$t7,-1
/*    3242c:	afa90078 */ 	sw	$t1,0x78($sp)
.L00032430:
/*    32430:	8fab00ac */ 	lw	$t3,0xac($sp)
/*    32434:	8fb90060 */ 	lw	$t9,0x60($sp)
/*    32438:	8d780000 */ 	lw	$t8,0x0($t3)
/*    3243c:	c7280028 */ 	lwc1	$f8,0x28($t9)
/*    32440:	c730002c */ 	lwc1	$f16,0x2c($t9)
/*    32444:	8f0c0004 */ 	lw	$t4,0x4($t8)
/*    32448:	448c2000 */ 	mtc1	$t4,$f4
/*    3244c:	00000000 */ 	sll	$zero,$zero,0x0
/*    32450:	468021a0 */ 	cvt.s.w	$f6,$f4
/*    32454:	46083283 */ 	div.s	$f10,$f6,$f8
/*    32458:	46105483 */ 	div.s	$f18,$f10,$f16
/*    3245c:	4600910d */ 	trunc.w.s	$f4,$f18
/*    32460:	440e2000 */ 	mfc1	$t6,$f4
/*    32464:	00000000 */ 	sll	$zero,$zero,0x0
/*    32468:	afae0080 */ 	sw	$t6,0x80($sp)
/*    3246c:	8faa0080 */ 	lw	$t2,0x80($sp)
/*    32470:	3c010053 */ 	lui	$at,0x53
/*    32474:	3421ec61 */ 	ori	$at,$at,0xec61
/*    32478:	0141082a */ 	slt	$at,$t2,$at
/*    3247c:	14200005 */ 	bnez	$at,.L00032494
/*    32480:	00000000 */ 	sll	$zero,$zero,0x0
/*    32484:	0c00cc24 */ 	jal	func00033090
/*    32488:	8fa40060 */ 	lw	$a0,0x60($sp)
/*    3248c:	100002fb */ 	beqz	$zero,.L0003307c
/*    32490:	00000000 */ 	sll	$zero,$zero,0x0
.L00032494:
/*    32494:	3c088006 */ 	lui	$t0,0x8006
/*    32498:	8d08f12c */ 	lw	$t0,-0xed4($t0)
/*    3249c:	8fa90080 */ 	lw	$t1,0x80($sp)
/*    324a0:	8fb80060 */ 	lw	$t8,0x60($sp)
/*    324a4:	8d0f0050 */ 	lw	$t7,0x50($t0)
/*    324a8:	01e95821 */ 	addu	$t3,$t7,$t1
/*    324ac:	af0b003c */ 	sw	$t3,0x3c($t8)
/*    324b0:	8fa40060 */ 	lw	$a0,0x60($sp)
/*    324b4:	8fa50078 */ 	lw	$a1,0x78($sp)
/*    324b8:	8fa60080 */ 	lw	$a2,0x80($sp)
/*    324bc:	0c00f33c */ 	jal	func0003ccf0
/*    324c0:	2484000c */ 	addiu	$a0,$a0,0xc
/*    324c4:	240c0002 */ 	addiu	$t4,$zero,0x2
/*    324c8:	a7ac0094 */ 	sh	$t4,0x94($sp)
/*    324cc:	8fb90060 */ 	lw	$t9,0x60($sp)
/*    324d0:	afb90098 */ 	sw	$t9,0x98($sp)
/*    324d4:	3c048006 */ 	lui	$a0,%hi(var80060014)
/*    324d8:	8c84f12c */ 	lw	$a0,-0xed4($a0)
/*    324dc:	27a50094 */ 	addiu	$a1,$sp,0x94
/*    324e0:	8fa60080 */ 	lw	$a2,0x80($sp)
/*    324e4:	00003825 */ 	or	$a3,$zero,$zero
/*    324e8:	0c00f184 */ 	jal	func0003c610
/*    324ec:	24840014 */ 	addiu	$a0,$a0,%lo(var80060014)
/*    324f0:	8fad0060 */ 	lw	$t5,0x60($sp)
/*    324f4:	91ae0044 */ 	lbu	$t6,0x44($t5)
/*    324f8:	31ca0020 */ 	andi	$t2,$t6,0x20
/*    324fc:	11400003 */ 	beqz	$t2,.L0003250c
/*    32500:	00000000 */ 	sll	$zero,$zero,0x0
/*    32504:	0c00cc40 */ 	jal	func00033100
/*    32508:	8fa40060 */ 	lw	$a0,0x60($sp)
.L0003250c:
/*    3250c:	10000025 */ 	beqz	$zero,.L000325a4
/*    32510:	00000000 */ 	sll	$zero,$zero,0x0
.L00032514:
/*    32514:	24080040 */ 	addiu	$t0,$zero,0x40
/*    32518:	a7a80094 */ 	sh	$t0,0x94($sp)
/*    3251c:	8faf0060 */ 	lw	$t7,0x60($sp)
/*    32520:	afaf0098 */ 	sw	$t7,0x98($sp)
/*    32524:	8fa900ac */ 	lw	$t1,0xac($sp)
/*    32528:	8fac0060 */ 	lw	$t4,0x60($sp)
/*    3252c:	8d2b0000 */ 	lw	$t3,0x0($t1)
/*    32530:	c58a002c */ 	lwc1	$f10,0x2c($t4)
/*    32534:	c5920028 */ 	lwc1	$f18,0x28($t4)
/*    32538:	8d780000 */ 	lw	$t8,0x0($t3)
/*    3253c:	44983000 */ 	mtc1	$t8,$f6
/*    32540:	00000000 */ 	sll	$zero,$zero,0x0
/*    32544:	46803220 */ 	cvt.s.w	$f8,$f6
/*    32548:	460a4403 */ 	div.s	$f16,$f8,$f10
/*    3254c:	46128103 */ 	div.s	$f4,$f16,$f18
/*    32550:	4600218d */ 	trunc.w.s	$f6,$f4
/*    32554:	440d3000 */ 	mfc1	$t5,$f6
/*    32558:	00000000 */ 	sll	$zero,$zero,0x0
/*    3255c:	afad0080 */ 	sw	$t5,0x80($sp)
/*    32560:	8fae0080 */ 	lw	$t6,0x80($sp)
/*    32564:	3c010053 */ 	lui	$at,0x53
/*    32568:	3421ec61 */ 	ori	$at,$at,0xec61
/*    3256c:	01c1082a */ 	slt	$at,$t6,$at
/*    32570:	14200005 */ 	bnez	$at,.L00032588
/*    32574:	00000000 */ 	sll	$zero,$zero,0x0
/*    32578:	0c00cc24 */ 	jal	func00033090
/*    3257c:	8fa40060 */ 	lw	$a0,0x60($sp)
/*    32580:	100002be */ 	beqz	$zero,.L0003307c
/*    32584:	00000000 */ 	sll	$zero,$zero,0x0
.L00032588:
/*    32588:	3c048006 */ 	lui	$a0,%hi(var80060014)
/*    3258c:	8c84f12c */ 	lw	$a0,-0xed4($a0)
/*    32590:	27a50094 */ 	addiu	$a1,$sp,0x94
/*    32594:	8fa60080 */ 	lw	$a2,0x80($sp)
/*    32598:	00003825 */ 	or	$a3,$zero,$zero
/*    3259c:	0c00f184 */ 	jal	func0003c610
/*    325a0:	24840014 */ 	addiu	$a0,$a0,%lo(var80060014)
.L000325a4:
/*    325a4:	1000029c */ 	beqz	$zero,.L00033018
/*    325a8:	00000000 */ 	sll	$zero,$zero,0x0
.L000325ac:
/*    325ac:	8faa00b8 */ 	lw	$t2,0xb8($sp)
/*    325b0:	24011000 */ 	addiu	$at,$zero,0x1000
/*    325b4:	95480000 */ 	lhu	$t0,0x0($t2)
/*    325b8:	15010006 */ 	bne	$t0,$at,.L000325d4
/*    325bc:	00000000 */ 	sll	$zero,$zero,0x0
/*    325c0:	8faf0060 */ 	lw	$t7,0x60($sp)
/*    325c4:	91e90044 */ 	lbu	$t1,0x44($t7)
/*    325c8:	312b0002 */ 	andi	$t3,$t1,0x2
/*    325cc:	11600056 */ 	beqz	$t3,.L00032728
/*    325d0:	00000000 */ 	sll	$zero,$zero,0x0
.L000325d4:
/*    325d4:	8fb80060 */ 	lw	$t8,0x60($sp)
/*    325d8:	24010001 */ 	addiu	$at,$zero,0x1
/*    325dc:	93100045 */ 	lbu	$s0,0x45($t8)
/*    325e0:	12010009 */ 	beq	$s0,$at,.L00032608
/*    325e4:	00000000 */ 	sll	$zero,$zero,0x0
/*    325e8:	24010004 */ 	addiu	$at,$zero,0x4
/*    325ec:	12010040 */ 	beq	$s0,$at,.L000326f0
/*    325f0:	00000000 */ 	sll	$zero,$zero,0x0
/*    325f4:	24010005 */ 	addiu	$at,$zero,0x5
/*    325f8:	1201003d */ 	beq	$s0,$at,.L000326f0
/*    325fc:	00000000 */ 	sll	$zero,$zero,0x0
/*    32600:	1000003f */ 	beqz	$zero,.L00032700
/*    32604:	00000000 */ 	sll	$zero,$zero,0x0
.L00032608:
/*    32608:	3c048006 */ 	lui	$a0,%hi(var80060014)
/*    3260c:	8c84f12c */ 	lw	$a0,-0xed4($a0)
/*    32610:	8fa50060 */ 	lw	$a1,0x60($sp)
/*    32614:	24060040 */ 	addiu	$a2,$zero,0x40
/*    32618:	0c00cc60 */ 	jal	func00033180
/*    3261c:	24840014 */ 	addiu	$a0,$a0,%lo(var80060014)
/*    32620:	8fac00ac */ 	lw	$t4,0xac($sp)
/*    32624:	8fae0060 */ 	lw	$t6,0x60($sp)
/*    32628:	8d990000 */ 	lw	$t9,0x0($t4)
/*    3262c:	c5d00028 */ 	lwc1	$f16,0x28($t6)
/*    32630:	c5c4002c */ 	lwc1	$f4,0x2c($t6)
/*    32634:	8f2d0008 */ 	lw	$t5,0x8($t9)
/*    32638:	448d4000 */ 	mtc1	$t5,$f8
/*    3263c:	00000000 */ 	sll	$zero,$zero,0x0
/*    32640:	468042a0 */ 	cvt.s.w	$f10,$f8
/*    32644:	46105483 */ 	div.s	$f18,$f10,$f16
/*    32648:	46049183 */ 	div.s	$f6,$f18,$f4
/*    3264c:	4600320d */ 	trunc.w.s	$f8,$f6
/*    32650:	44084000 */ 	mfc1	$t0,$f8
/*    32654:	00000000 */ 	sll	$zero,$zero,0x0
/*    32658:	afa80080 */ 	sw	$t0,0x80($sp)
/*    3265c:	8faf0080 */ 	lw	$t7,0x80($sp)
/*    32660:	3c010053 */ 	lui	$at,0x53
/*    32664:	3421ec61 */ 	ori	$at,$at,0xec61
/*    32668:	01e1082a */ 	slt	$at,$t7,$at
/*    3266c:	14200005 */ 	bnez	$at,.L00032684
/*    32670:	00000000 */ 	sll	$zero,$zero,0x0
/*    32674:	0c00cc24 */ 	jal	func00033090
/*    32678:	8fa40060 */ 	lw	$a0,0x60($sp)
/*    3267c:	10000022 */ 	beqz	$zero,.L00032708
/*    32680:	00000000 */ 	sll	$zero,$zero,0x0
.L00032684:
/*    32684:	8fa40060 */ 	lw	$a0,0x60($sp)
/*    32688:	00002825 */ 	or	$a1,$zero,$zero
/*    3268c:	8fa60080 */ 	lw	$a2,0x80($sp)
/*    32690:	0c00f33c */ 	jal	func0003ccf0
/*    32694:	2484000c */ 	addiu	$a0,$a0,0xc
/*    32698:	8fa90080 */ 	lw	$t1,0x80($sp)
/*    3269c:	11200010 */ 	beqz	$t1,.L000326e0
/*    326a0:	00000000 */ 	sll	$zero,$zero,0x0
/*    326a4:	240b0080 */ 	addiu	$t3,$zero,0x80
/*    326a8:	a7ab0094 */ 	sh	$t3,0x94($sp)
/*    326ac:	8fb80060 */ 	lw	$t8,0x60($sp)
/*    326b0:	afb80098 */ 	sw	$t8,0x98($sp)
/*    326b4:	3c048006 */ 	lui	$a0,%hi(var80060014)
/*    326b8:	8c84f12c */ 	lw	$a0,-0xed4($a0)
/*    326bc:	27a50094 */ 	addiu	$a1,$sp,0x94
/*    326c0:	8fa60080 */ 	lw	$a2,0x80($sp)
/*    326c4:	00003825 */ 	or	$a3,$zero,$zero
/*    326c8:	0c00f184 */ 	jal	func0003c610
/*    326cc:	24840014 */ 	addiu	$a0,$a0,%lo(var80060014)
/*    326d0:	8fb90060 */ 	lw	$t9,0x60($sp)
/*    326d4:	240c0002 */ 	addiu	$t4,$zero,0x2
/*    326d8:	10000003 */ 	beqz	$zero,.L000326e8
/*    326dc:	a32c0045 */ 	sb	$t4,0x45($t9)
.L000326e0:
/*    326e0:	0c00cc24 */ 	jal	func00033090
/*    326e4:	8fa40060 */ 	lw	$a0,0x60($sp)
.L000326e8:
/*    326e8:	10000007 */ 	beqz	$zero,.L00032708
/*    326ec:	00000000 */ 	sll	$zero,$zero,0x0
.L000326f0:
/*    326f0:	0c00cc24 */ 	jal	func00033090
/*    326f4:	8fa40060 */ 	lw	$a0,0x60($sp)
/*    326f8:	10000003 */ 	beqz	$zero,.L00032708
/*    326fc:	00000000 */ 	sll	$zero,$zero,0x0
.L00032700:
/*    32700:	10000001 */ 	beqz	$zero,.L00032708
/*    32704:	00000000 */ 	sll	$zero,$zero,0x0
.L00032708:
/*    32708:	8fad00b8 */ 	lw	$t5,0xb8($sp)
/*    3270c:	24010002 */ 	addiu	$at,$zero,0x2
/*    32710:	95ae0000 */ 	lhu	$t6,0x0($t5)
/*    32714:	15c10004 */ 	bne	$t6,$at,.L00032728
/*    32718:	00000000 */ 	sll	$zero,$zero,0x0
/*    3271c:	8fa800b8 */ 	lw	$t0,0xb8($sp)
/*    32720:	240a1000 */ 	addiu	$t2,$zero,0x1000
/*    32724:	a50a0000 */ 	sh	$t2,0x0($t0)
.L00032728:
/*    32728:	1000023b */ 	beqz	$zero,.L00033018
/*    3272c:	00000000 */ 	sll	$zero,$zero,0x0
/*    32730:	8faf00b8 */ 	lw	$t7,0xb8($sp)
/*    32734:	8fab0060 */ 	lw	$t3,0x60($sp)
/*    32738:	8de90008 */ 	lw	$t1,0x8($t7)
/*    3273c:	a1690041 */ 	sb	$t1,0x41($t3)
/*    32740:	8fb80060 */ 	lw	$t8,0x60($sp)
/*    32744:	24010001 */ 	addiu	$at,$zero,0x1
/*    32748:	930c0045 */ 	lbu	$t4,0x45($t8)
/*    3274c:	1581001f */ 	bne	$t4,$at,.L000327cc
/*    32750:	00000000 */ 	sll	$zero,$zero,0x0
/*    32754:	8fb90060 */ 	lw	$t9,0x60($sp)
/*    32758:	8fae00ac */ 	lw	$t6,0xac($sp)
/*    3275c:	932d0041 */ 	lbu	$t5,0x41($t9)
/*    32760:	91ca000c */ 	lbu	$t2,0xc($t6)
/*    32764:	01aa4021 */ 	addu	$t0,$t5,$t2
/*    32768:	250fffc0 */ 	addiu	$t7,$t0,-64
/*    3276c:	afaf0074 */ 	sw	$t7,0x74($sp)
/*    32770:	8fa90074 */ 	lw	$t1,0x74($sp)
/*    32774:	19200003 */ 	blez	$t1,.L00032784
/*    32778:	00000000 */ 	sll	$zero,$zero,0x0
/*    3277c:	10000002 */ 	beqz	$zero,.L00032788
/*    32780:	01208025 */ 	or	$s0,$t1,$zero
.L00032784:
/*    32784:	00008025 */ 	or	$s0,$zero,$zero
.L00032788:
/*    32788:	2a01007f */ 	slti	$at,$s0,0x7f
/*    3278c:	10200009 */ 	beqz	$at,.L000327b4
/*    32790:	00000000 */ 	sll	$zero,$zero,0x0
/*    32794:	8fab0074 */ 	lw	$t3,0x74($sp)
/*    32798:	19600003 */ 	blez	$t3,.L000327a8
/*    3279c:	00000000 */ 	sll	$zero,$zero,0x0
/*    327a0:	10000002 */ 	beqz	$zero,.L000327ac
/*    327a4:	01608825 */ 	or	$s1,$t3,$zero
.L000327a8:
/*    327a8:	00008825 */ 	or	$s1,$zero,$zero
.L000327ac:
/*    327ac:	10000003 */ 	beqz	$zero,.L000327bc
/*    327b0:	a3b100a7 */ 	sb	$s1,0xa7($sp)
.L000327b4:
/*    327b4:	2418007f */ 	addiu	$t8,$zero,0x7f
/*    327b8:	a3b800a7 */ 	sb	$t8,0xa7($sp)
.L000327bc:
/*    327bc:	8fa40060 */ 	lw	$a0,0x60($sp)
/*    327c0:	93a500a7 */ 	lbu	$a1,0xa7($sp)
/*    327c4:	0c00f3bc */ 	jal	func0003cef0
/*    327c8:	2484000c */ 	addiu	$a0,$a0,0xc
.L000327cc:
/*    327cc:	10000212 */ 	beqz	$zero,.L00033018
/*    327d0:	00000000 */ 	sll	$zero,$zero,0x0
/*    327d4:	8fac00b8 */ 	lw	$t4,0xb8($sp)
/*    327d8:	8fb90060 */ 	lw	$t9,0x60($sp)
/*    327dc:	c58a0008 */ 	lwc1	$f10,0x8($t4)
/*    327e0:	e72a002c */ 	swc1	$f10,0x2c($t9)
/*    327e4:	8fae0060 */ 	lw	$t6,0x60($sp)
/*    327e8:	24010001 */ 	addiu	$at,$zero,0x1
/*    327ec:	91cd0045 */ 	lbu	$t5,0x45($t6)
/*    327f0:	15a10010 */ 	bne	$t5,$at,.L00032834
/*    327f4:	00000000 */ 	sll	$zero,$zero,0x0
/*    327f8:	8faa0060 */ 	lw	$t2,0x60($sp)
/*    327fc:	c550002c */ 	lwc1	$f16,0x2c($t2)
/*    32800:	c5520028 */ 	lwc1	$f18,0x28($t2)
/*    32804:	2544000c */ 	addiu	$a0,$t2,0xc
/*    32808:	46128102 */ 	mul.s	$f4,$f16,$f18
/*    3280c:	44052000 */ 	mfc1	$a1,$f4
/*    32810:	0c00f3e8 */ 	jal	func0003cfa0
/*    32814:	00000000 */ 	sll	$zero,$zero,0x0
/*    32818:	8fa80060 */ 	lw	$t0,0x60($sp)
/*    3281c:	910f0044 */ 	lbu	$t7,0x44($t0)
/*    32820:	31e90020 */ 	andi	$t1,$t7,0x20
/*    32824:	11200003 */ 	beqz	$t1,.L00032834
/*    32828:	00000000 */ 	sll	$zero,$zero,0x0
/*    3282c:	0c00cc40 */ 	jal	func00033100
/*    32830:	8fa40060 */ 	lw	$a0,0x60($sp)
.L00032834:
/*    32834:	100001f8 */ 	beqz	$zero,.L00033018
/*    32838:	00000000 */ 	sll	$zero,$zero,0x0
.L0003283c:
/*    3283c:	8fab00b8 */ 	lw	$t3,0xb8($sp)
/*    32840:	8fac0060 */ 	lw	$t4,0x60($sp)
/*    32844:	8d780008 */ 	lw	$t8,0x8($t3)
/*    32848:	a1980042 */ 	sb	$t8,0x42($t4)
/*    3284c:	8fb90060 */ 	lw	$t9,0x60($sp)
/*    32850:	24010001 */ 	addiu	$at,$zero,0x1
/*    32854:	932e0045 */ 	lbu	$t6,0x45($t9)
/*    32858:	15c10027 */ 	bne	$t6,$at,.L000328f8
/*    3285c:	00000000 */ 	sll	$zero,$zero,0x0
/*    32860:	8faf00a8 */ 	lw	$t7,0xa8($sp)
/*    32864:	8fad0060 */ 	lw	$t5,0x60($sp)
/*    32868:	91e90003 */ 	lbu	$t1,0x3($t7)
/*    3286c:	91aa0042 */ 	lbu	$t2,0x42($t5)
/*    32870:	312b000f */ 	andi	$t3,$t1,0xf
/*    32874:	000bc0c0 */ 	sll	$t8,$t3,0x3
/*    32878:	3148007f */ 	andi	$t0,$t2,0x7f
/*    3287c:	01186021 */ 	addu	$t4,$t0,$t8
/*    32880:	afac007c */ 	sw	$t4,0x7c($sp)
/*    32884:	8fb9007c */ 	lw	$t9,0x7c($sp)
/*    32888:	07210003 */ 	bgez	$t9,.L00032898
/*    3288c:	00000000 */ 	sll	$zero,$zero,0x0
/*    32890:	10000002 */ 	beqz	$zero,.L0003289c
/*    32894:	00008025 */ 	or	$s0,$zero,$zero
.L00032898:
/*    32898:	8fb0007c */ 	lw	$s0,0x7c($sp)
.L0003289c:
/*    3289c:	2a010080 */ 	slti	$at,$s0,0x80
/*    328a0:	14200004 */ 	bnez	$at,.L000328b4
/*    328a4:	00000000 */ 	sll	$zero,$zero,0x0
/*    328a8:	240e007f */ 	addiu	$t6,$zero,0x7f
/*    328ac:	10000008 */ 	beqz	$zero,.L000328d0
/*    328b0:	afae007c */ 	sw	$t6,0x7c($sp)
.L000328b4:
/*    328b4:	8fad007c */ 	lw	$t5,0x7c($sp)
/*    328b8:	05a10003 */ 	bgez	$t5,.L000328c8
/*    328bc:	00000000 */ 	sll	$zero,$zero,0x0
/*    328c0:	10000002 */ 	beqz	$zero,.L000328cc
/*    328c4:	00008825 */ 	or	$s1,$zero,$zero
.L000328c8:
/*    328c8:	8fb1007c */ 	lw	$s1,0x7c($sp)
.L000328cc:
/*    328cc:	afb1007c */ 	sw	$s1,0x7c($sp)
.L000328d0:
/*    328d0:	8faf0060 */ 	lw	$t7,0x60($sp)
/*    328d4:	8faa007c */ 	lw	$t2,0x7c($sp)
/*    328d8:	91e90042 */ 	lbu	$t1,0x42($t7)
/*    328dc:	312b0080 */ 	andi	$t3,$t1,0x80
/*    328e0:	014b4025 */ 	or	$t0,$t2,$t3
/*    328e4:	afa8007c */ 	sw	$t0,0x7c($sp)
/*    328e8:	8fa40060 */ 	lw	$a0,0x60($sp)
/*    328ec:	8fa5007c */ 	lw	$a1,0x7c($sp)
/*    328f0:	0c00f414 */ 	jal	func0003d050
/*    328f4:	2484000c */ 	addiu	$a0,$a0,0xc
.L000328f8:
/*    328f8:	100001c7 */ 	beqz	$zero,.L00033018
/*    328fc:	00000000 */ 	sll	$zero,$zero,0x0
.L00032900:
/*    32900:	8fb80060 */ 	lw	$t8,0x60($sp)
/*    32904:	8fad00b8 */ 	lw	$t5,0xb8($sp)
/*    32908:	930c0042 */ 	lbu	$t4,0x42($t8)
/*    3290c:	8daf0008 */ 	lw	$t7,0x8($t5)
/*    32910:	3199007f */ 	andi	$t9,$t4,0x7f
/*    32914:	31e90080 */ 	andi	$t1,$t7,0x80
/*    32918:	312a00ff */ 	andi	$t2,$t1,0xff
/*    3291c:	332e00ff */ 	andi	$t6,$t9,0xff
/*    32920:	01ca5825 */ 	or	$t3,$t6,$t2
/*    32924:	a30b0042 */ 	sb	$t3,0x42($t8)
/*    32928:	8fa80060 */ 	lw	$t0,0x60($sp)
/*    3292c:	24010001 */ 	addiu	$at,$zero,0x1
/*    32930:	910c0045 */ 	lbu	$t4,0x45($t0)
/*    32934:	15810027 */ 	bne	$t4,$at,.L000329d4
/*    32938:	00000000 */ 	sll	$zero,$zero,0x0
/*    3293c:	8fa900a8 */ 	lw	$t1,0xa8($sp)
/*    32940:	8fb90060 */ 	lw	$t9,0x60($sp)
/*    32944:	912e0003 */ 	lbu	$t6,0x3($t1)
/*    32948:	932d0042 */ 	lbu	$t5,0x42($t9)
/*    3294c:	31ca000f */ 	andi	$t2,$t6,0xf
/*    32950:	000a58c0 */ 	sll	$t3,$t2,0x3
/*    32954:	31af007f */ 	andi	$t7,$t5,0x7f
/*    32958:	01ebc021 */ 	addu	$t8,$t7,$t3
/*    3295c:	afb8007c */ 	sw	$t8,0x7c($sp)
/*    32960:	8fa8007c */ 	lw	$t0,0x7c($sp)
/*    32964:	05010003 */ 	bgez	$t0,.L00032974
/*    32968:	00000000 */ 	sll	$zero,$zero,0x0
/*    3296c:	10000002 */ 	beqz	$zero,.L00032978
/*    32970:	00008025 */ 	or	$s0,$zero,$zero
.L00032974:
/*    32974:	8fb0007c */ 	lw	$s0,0x7c($sp)
.L00032978:
/*    32978:	2a010080 */ 	slti	$at,$s0,0x80
/*    3297c:	14200004 */ 	bnez	$at,.L00032990
/*    32980:	00000000 */ 	sll	$zero,$zero,0x0
/*    32984:	240c007f */ 	addiu	$t4,$zero,0x7f
/*    32988:	10000008 */ 	beqz	$zero,.L000329ac
/*    3298c:	afac007c */ 	sw	$t4,0x7c($sp)
.L00032990:
/*    32990:	8fb9007c */ 	lw	$t9,0x7c($sp)
/*    32994:	07210003 */ 	bgez	$t9,.L000329a4
/*    32998:	00000000 */ 	sll	$zero,$zero,0x0
/*    3299c:	10000002 */ 	beqz	$zero,.L000329a8
/*    329a0:	00008825 */ 	or	$s1,$zero,$zero
.L000329a4:
/*    329a4:	8fb1007c */ 	lw	$s1,0x7c($sp)
.L000329a8:
/*    329a8:	afb1007c */ 	sw	$s1,0x7c($sp)
.L000329ac:
/*    329ac:	8fa90060 */ 	lw	$t1,0x60($sp)
/*    329b0:	8fad007c */ 	lw	$t5,0x7c($sp)
/*    329b4:	912e0042 */ 	lbu	$t6,0x42($t1)
/*    329b8:	31ca0080 */ 	andi	$t2,$t6,0x80
/*    329bc:	01aa7825 */ 	or	$t7,$t5,$t2
/*    329c0:	afaf007c */ 	sw	$t7,0x7c($sp)
/*    329c4:	8fa40060 */ 	lw	$a0,0x60($sp)
/*    329c8:	8fa5007c */ 	lw	$a1,0x7c($sp)
/*    329cc:	0c00f414 */ 	jal	func0003d050
/*    329d0:	2484000c */ 	addiu	$a0,$a0,0xc
.L000329d4:
/*    329d4:	10000190 */ 	beqz	$zero,.L00033018
/*    329d8:	00000000 */ 	sll	$zero,$zero,0x0
.L000329dc:
/*    329dc:	8fab00b8 */ 	lw	$t3,0xb8($sp)
/*    329e0:	8fa80060 */ 	lw	$t0,0x60($sp)
/*    329e4:	8d780008 */ 	lw	$t8,0x8($t3)
/*    329e8:	a1180043 */ 	sb	$t8,0x43($t0)
/*    329ec:	3c098006 */ 	lui	$t1,0x8006
/*    329f0:	8d29f114 */ 	lw	$t1,-0xeec($t1)
/*    329f4:	8fac0060 */ 	lw	$t4,0x60($sp)
/*    329f8:	8d2e003c */ 	lw	$t6,0x3c($t1)
/*    329fc:	91990043 */ 	lbu	$t9,0x43($t4)
/*    32a00:	032e082a */ 	slt	$at,$t9,$t6
/*    32a04:	14200003 */ 	bnez	$at,.L00032a14
/*    32a08:	00000000 */ 	sll	$zero,$zero,0x0
/*    32a0c:	8fad0060 */ 	lw	$t5,0x60($sp)
/*    32a10:	a1a00043 */ 	sb	$zero,0x43($t5)
.L00032a14:
/*    32a14:	8faa0060 */ 	lw	$t2,0x60($sp)
/*    32a18:	24010001 */ 	addiu	$at,$zero,0x1
/*    32a1c:	914f0045 */ 	lbu	$t7,0x45($t2)
/*    32a20:	15e10004 */ 	bne	$t7,$at,.L00032a34
/*    32a24:	00000000 */ 	sll	$zero,$zero,0x0
/*    32a28:	8fab0060 */ 	lw	$t3,0x60($sp)
/*    32a2c:	91780043 */ 	lbu	$t8,0x43($t3)
/*    32a30:	a5780024 */ 	sh	$t8,0x24($t3)
.L00032a34:
/*    32a34:	10000178 */ 	beqz	$zero,.L00033018
/*    32a38:	00000000 */ 	sll	$zero,$zero,0x0
/*    32a3c:	8fa800b8 */ 	lw	$t0,0xb8($sp)
/*    32a40:	8fa90060 */ 	lw	$t1,0x60($sp)
/*    32a44:	8d0c0008 */ 	lw	$t4,0x8($t0)
/*    32a48:	a52c0038 */ 	sh	$t4,0x38($t1)
/*    32a4c:	8fb90060 */ 	lw	$t9,0x60($sp)
/*    32a50:	24010001 */ 	addiu	$at,$zero,0x1
/*    32a54:	932e0045 */ 	lbu	$t6,0x45($t9)
/*    32a58:	15c1005d */ 	bne	$t6,$at,.L00032bd0
/*    32a5c:	00000000 */ 	sll	$zero,$zero,0x0
/*    32a60:	8fa90060 */ 	lw	$t1,0x60($sp)
/*    32a64:	8faa00a8 */ 	lw	$t2,0xa8($sp)
/*    32a68:	3c0d800a */ 	lui	$t5,0x800a
/*    32a6c:	8539003a */ 	lh	$t9,0x3a($t1)
/*    32a70:	852e0038 */ 	lh	$t6,0x38($t1)
/*    32a74:	914f0002 */ 	lbu	$t7,0x2($t2)
/*    32a78:	8dadc334 */ 	lw	$t5,-0x3ccc($t5)
/*    32a7c:	032e0019 */ 	multu	$t9,$t6
/*    32a80:	31f8001f */ 	andi	$t8,$t7,0x1f
/*    32a84:	8faf00ac */ 	lw	$t7,0xac($sp)
/*    32a88:	00185840 */ 	sll	$t3,$t8,0x1
/*    32a8c:	01ab4021 */ 	addu	$t0,$t5,$t3
/*    32a90:	91f8000d */ 	lbu	$t8,0xd($t7)
/*    32a94:	24013f01 */ 	addiu	$at,$zero,0x3f01
/*    32a98:	850c0000 */ 	lh	$t4,0x0($t0)
/*    32a9c:	00005012 */ 	mflo	$t2
/*    32aa0:	00000000 */ 	sll	$zero,$zero,0x0
/*    32aa4:	00000000 */ 	sll	$zero,$zero,0x0
/*    32aa8:	01580019 */ 	multu	$t2,$t8
/*    32aac:	00006812 */ 	mflo	$t5
/*    32ab0:	00000000 */ 	sll	$zero,$zero,0x0
/*    32ab4:	00000000 */ 	sll	$zero,$zero,0x0
/*    32ab8:	01a1001a */ 	div	$zero,$t5,$at
/*    32abc:	00005812 */ 	mflo	$t3
/*    32ac0:	24017fff */ 	addiu	$at,$zero,0x7fff
/*    32ac4:	00000000 */ 	sll	$zero,$zero,0x0
/*    32ac8:	018b0019 */ 	multu	$t4,$t3
/*    32acc:	00004012 */ 	mflo	$t0
/*    32ad0:	00000000 */ 	sll	$zero,$zero,0x0
/*    32ad4:	00000000 */ 	sll	$zero,$zero,0x0
/*    32ad8:	0101001a */ 	div	$zero,$t0,$at
/*    32adc:	00004812 */ 	mflo	$t1
/*    32ae0:	1d200003 */ 	bgtz	$t1,.L00032af0
/*    32ae4:	00000000 */ 	sll	$zero,$zero,0x0
/*    32ae8:	10000023 */ 	beqz	$zero,.L00032b78
/*    32aec:	afa00078 */ 	sw	$zero,0x78($sp)
.L00032af0:
/*    32af0:	8fab0060 */ 	lw	$t3,0x60($sp)
/*    32af4:	8fae00a8 */ 	lw	$t6,0xa8($sp)
/*    32af8:	3c19800a */ 	lui	$t9,0x800a
/*    32afc:	8568003a */ 	lh	$t0,0x3a($t3)
/*    32b00:	85690038 */ 	lh	$t1,0x38($t3)
/*    32b04:	91cf0002 */ 	lbu	$t7,0x2($t6)
/*    32b08:	8f39c334 */ 	lw	$t9,-0x3ccc($t9)
/*    32b0c:	01090019 */ 	multu	$t0,$t1
/*    32b10:	31ea001f */ 	andi	$t2,$t7,0x1f
/*    32b14:	8faf00ac */ 	lw	$t7,0xac($sp)
/*    32b18:	000ac040 */ 	sll	$t8,$t2,0x1
/*    32b1c:	03386821 */ 	addu	$t5,$t9,$t8
/*    32b20:	91ea000d */ 	lbu	$t2,0xd($t7)
/*    32b24:	24013f01 */ 	addiu	$at,$zero,0x3f01
/*    32b28:	85ac0000 */ 	lh	$t4,0x0($t5)
/*    32b2c:	00007012 */ 	mflo	$t6
/*    32b30:	00000000 */ 	sll	$zero,$zero,0x0
/*    32b34:	00000000 */ 	sll	$zero,$zero,0x0
/*    32b38:	01ca0019 */ 	multu	$t6,$t2
/*    32b3c:	0000c812 */ 	mflo	$t9
/*    32b40:	00000000 */ 	sll	$zero,$zero,0x0
/*    32b44:	00000000 */ 	sll	$zero,$zero,0x0
/*    32b48:	0321001a */ 	div	$zero,$t9,$at
/*    32b4c:	0000c012 */ 	mflo	$t8
/*    32b50:	24017fff */ 	addiu	$at,$zero,0x7fff
/*    32b54:	00000000 */ 	sll	$zero,$zero,0x0
/*    32b58:	01980019 */ 	multu	$t4,$t8
/*    32b5c:	00006812 */ 	mflo	$t5
/*    32b60:	00000000 */ 	sll	$zero,$zero,0x0
/*    32b64:	00000000 */ 	sll	$zero,$zero,0x0
/*    32b68:	01a1001a */ 	div	$zero,$t5,$at
/*    32b6c:	00005812 */ 	mflo	$t3
/*    32b70:	2568ffff */ 	addiu	$t0,$t3,-1
/*    32b74:	afa80078 */ 	sw	$t0,0x78($sp)
.L00032b78:
/*    32b78:	3c0e8006 */ 	lui	$t6,0x8006
/*    32b7c:	8dcef12c */ 	lw	$t6,-0xed4($t6)
/*    32b80:	8fa90060 */ 	lw	$t1,0x60($sp)
/*    32b84:	8dca0050 */ 	lw	$t2,0x50($t6)
/*    32b88:	8d2f003c */ 	lw	$t7,0x3c($t1)
/*    32b8c:	01eac823 */ 	subu	$t9,$t7,$t2
/*    32b90:	2b2103e8 */ 	slti	$at,$t9,0x3e8
/*    32b94:	10200003 */ 	beqz	$at,.L00032ba4
/*    32b98:	00000000 */ 	sll	$zero,$zero,0x0
/*    32b9c:	10000007 */ 	beqz	$zero,.L00032bbc
/*    32ba0:	241003e8 */ 	addiu	$s0,$zero,0x3e8
.L00032ba4:
/*    32ba4:	3c0d8006 */ 	lui	$t5,0x8006
/*    32ba8:	8dadf12c */ 	lw	$t5,-0xed4($t5)
/*    32bac:	8fac0060 */ 	lw	$t4,0x60($sp)
/*    32bb0:	8dab0050 */ 	lw	$t3,0x50($t5)
/*    32bb4:	8d98003c */ 	lw	$t8,0x3c($t4)
/*    32bb8:	030b8023 */ 	subu	$s0,$t8,$t3
.L00032bbc:
/*    32bbc:	8fa40060 */ 	lw	$a0,0x60($sp)
/*    32bc0:	8fa50078 */ 	lw	$a1,0x78($sp)
/*    32bc4:	02003025 */ 	or	$a2,$s0,$zero
/*    32bc8:	0c00f33c */ 	jal	func0003ccf0
/*    32bcc:	2484000c */ 	addiu	$a0,$a0,0xc
.L00032bd0:
/*    32bd0:	10000111 */ 	beqz	$zero,.L00033018
/*    32bd4:	00000000 */ 	sll	$zero,$zero,0x0
.L00032bd8:
/*    32bd8:	8fa80060 */ 	lw	$t0,0x60($sp)
/*    32bdc:	24010001 */ 	addiu	$at,$zero,0x1
/*    32be0:	91090045 */ 	lbu	$t1,0x45($t0)
/*    32be4:	15210065 */ 	bne	$t1,$at,.L00032d7c
/*    32be8:	00000000 */ 	sll	$zero,$zero,0x0
/*    32bec:	8fae00ac */ 	lw	$t6,0xac($sp)
/*    32bf0:	8fb90060 */ 	lw	$t9,0x60($sp)
/*    32bf4:	8dcf0000 */ 	lw	$t7,0x0($t6)
/*    32bf8:	c72a0028 */ 	lwc1	$f10,0x28($t9)
/*    32bfc:	c732002c */ 	lwc1	$f18,0x2c($t9)
/*    32c00:	8dea0008 */ 	lw	$t2,0x8($t7)
/*    32c04:	448a3000 */ 	mtc1	$t2,$f6
/*    32c08:	00000000 */ 	sll	$zero,$zero,0x0
/*    32c0c:	46803220 */ 	cvt.s.w	$f8,$f6
/*    32c10:	460a4403 */ 	div.s	$f16,$f8,$f10
/*    32c14:	46128103 */ 	div.s	$f4,$f16,$f18
/*    32c18:	4600218d */ 	trunc.w.s	$f6,$f4
/*    32c1c:	440d3000 */ 	mfc1	$t5,$f6
/*    32c20:	00000000 */ 	sll	$zero,$zero,0x0
/*    32c24:	afad0080 */ 	sw	$t5,0x80($sp)
/*    32c28:	8fb80080 */ 	lw	$t8,0x80($sp)
/*    32c2c:	3c010053 */ 	lui	$at,0x53
/*    32c30:	3421ec61 */ 	ori	$at,$at,0xec61
/*    32c34:	0301082a */ 	slt	$at,$t8,$at
/*    32c38:	14200005 */ 	bnez	$at,.L00032c50
/*    32c3c:	00000000 */ 	sll	$zero,$zero,0x0
/*    32c40:	0c00cc24 */ 	jal	func00033090
/*    32c44:	8fa40060 */ 	lw	$a0,0x60($sp)
/*    32c48:	100000f3 */ 	beqz	$zero,.L00033018
/*    32c4c:	00000000 */ 	sll	$zero,$zero,0x0
.L00032c50:
/*    32c50:	8fac0060 */ 	lw	$t4,0x60($sp)
/*    32c54:	8fa800a8 */ 	lw	$t0,0xa8($sp)
/*    32c58:	3c0b800a */ 	lui	$t3,0x800a
/*    32c5c:	858d003a */ 	lh	$t5,0x3a($t4)
/*    32c60:	85980038 */ 	lh	$t8,0x38($t4)
/*    32c64:	91090002 */ 	lbu	$t1,0x2($t0)
/*    32c68:	8d6bc334 */ 	lw	$t3,-0x3ccc($t3)
/*    32c6c:	01b80019 */ 	multu	$t5,$t8
/*    32c70:	312e001f */ 	andi	$t6,$t1,0x1f
/*    32c74:	8fa900ac */ 	lw	$t1,0xac($sp)
/*    32c78:	000e7840 */ 	sll	$t7,$t6,0x1
/*    32c7c:	016f5021 */ 	addu	$t2,$t3,$t7
/*    32c80:	912e000d */ 	lbu	$t6,0xd($t1)
/*    32c84:	24013f01 */ 	addiu	$at,$zero,0x3f01
/*    32c88:	85590000 */ 	lh	$t9,0x0($t2)
/*    32c8c:	00004012 */ 	mflo	$t0
/*    32c90:	00000000 */ 	sll	$zero,$zero,0x0
/*    32c94:	00000000 */ 	sll	$zero,$zero,0x0
/*    32c98:	010e0019 */ 	multu	$t0,$t6
/*    32c9c:	00005812 */ 	mflo	$t3
/*    32ca0:	00000000 */ 	sll	$zero,$zero,0x0
/*    32ca4:	00000000 */ 	sll	$zero,$zero,0x0
/*    32ca8:	0161001a */ 	div	$zero,$t3,$at
/*    32cac:	00007812 */ 	mflo	$t7
/*    32cb0:	24017fff */ 	addiu	$at,$zero,0x7fff
/*    32cb4:	00000000 */ 	sll	$zero,$zero,0x0
/*    32cb8:	032f0019 */ 	multu	$t9,$t7
/*    32cbc:	00005012 */ 	mflo	$t2
/*    32cc0:	00000000 */ 	sll	$zero,$zero,0x0
/*    32cc4:	00000000 */ 	sll	$zero,$zero,0x0
/*    32cc8:	0141001a */ 	div	$zero,$t2,$at
/*    32ccc:	00006012 */ 	mflo	$t4
/*    32cd0:	1d800003 */ 	bgtz	$t4,.L00032ce0
/*    32cd4:	00000000 */ 	sll	$zero,$zero,0x0
/*    32cd8:	10000023 */ 	beqz	$zero,.L00032d68
/*    32cdc:	afa00078 */ 	sw	$zero,0x78($sp)
.L00032ce0:
/*    32ce0:	8faf0060 */ 	lw	$t7,0x60($sp)
/*    32ce4:	8fb800a8 */ 	lw	$t8,0xa8($sp)
/*    32ce8:	3c0d800a */ 	lui	$t5,0x800a
/*    32cec:	85ea003a */ 	lh	$t2,0x3a($t7)
/*    32cf0:	85ec0038 */ 	lh	$t4,0x38($t7)
/*    32cf4:	93090002 */ 	lbu	$t1,0x2($t8)
/*    32cf8:	8dadc334 */ 	lw	$t5,-0x3ccc($t5)
/*    32cfc:	014c0019 */ 	multu	$t2,$t4
/*    32d00:	3128001f */ 	andi	$t0,$t1,0x1f
/*    32d04:	8fa900ac */ 	lw	$t1,0xac($sp)
/*    32d08:	00087040 */ 	sll	$t6,$t0,0x1
/*    32d0c:	01ae5821 */ 	addu	$t3,$t5,$t6
/*    32d10:	9128000d */ 	lbu	$t0,0xd($t1)
/*    32d14:	24013f01 */ 	addiu	$at,$zero,0x3f01
/*    32d18:	85790000 */ 	lh	$t9,0x0($t3)
/*    32d1c:	0000c012 */ 	mflo	$t8
/*    32d20:	00000000 */ 	sll	$zero,$zero,0x0
/*    32d24:	00000000 */ 	sll	$zero,$zero,0x0
/*    32d28:	03080019 */ 	multu	$t8,$t0
/*    32d2c:	00006812 */ 	mflo	$t5
/*    32d30:	00000000 */ 	sll	$zero,$zero,0x0
/*    32d34:	00000000 */ 	sll	$zero,$zero,0x0
/*    32d38:	01a1001a */ 	div	$zero,$t5,$at
/*    32d3c:	00007012 */ 	mflo	$t6
/*    32d40:	24017fff */ 	addiu	$at,$zero,0x7fff
/*    32d44:	00000000 */ 	sll	$zero,$zero,0x0
/*    32d48:	032e0019 */ 	multu	$t9,$t6
/*    32d4c:	00005812 */ 	mflo	$t3
/*    32d50:	00000000 */ 	sll	$zero,$zero,0x0
/*    32d54:	00000000 */ 	sll	$zero,$zero,0x0
/*    32d58:	0161001a */ 	div	$zero,$t3,$at
/*    32d5c:	00007812 */ 	mflo	$t7
/*    32d60:	25eaffff */ 	addiu	$t2,$t7,-1
/*    32d64:	afaa0078 */ 	sw	$t2,0x78($sp)
.L00032d68:
/*    32d68:	8fa40060 */ 	lw	$a0,0x60($sp)
/*    32d6c:	8fa50078 */ 	lw	$a1,0x78($sp)
/*    32d70:	8fa60080 */ 	lw	$a2,0x80($sp)
/*    32d74:	0c00f33c */ 	jal	func0003ccf0
/*    32d78:	2484000c */ 	addiu	$a0,$a0,0xc
.L00032d7c:
/*    32d7c:	100000a6 */ 	beqz	$zero,.L00033018
/*    32d80:	00000000 */ 	sll	$zero,$zero,0x0
.L00032d84:
/*    32d84:	8fac0060 */ 	lw	$t4,0x60($sp)
/*    32d88:	91890044 */ 	lbu	$t1,0x44($t4)
/*    32d8c:	31380002 */ 	andi	$t8,$t1,0x2
/*    32d90:	17000083 */ 	bnez	$t8,.L00032fa0
/*    32d94:	00000000 */ 	sll	$zero,$zero,0x0
/*    32d98:	8fa800ac */ 	lw	$t0,0xac($sp)
/*    32d9c:	8fae0060 */ 	lw	$t6,0x60($sp)
/*    32da0:	8d0d0000 */ 	lw	$t5,0x0($t0)
/*    32da4:	91b9000d */ 	lbu	$t9,0xd($t5)
/*    32da8:	a5d9003a */ 	sh	$t9,0x3a($t6)
/*    32dac:	8fad0060 */ 	lw	$t5,0x60($sp)
/*    32db0:	8faf00a8 */ 	lw	$t7,0xa8($sp)
/*    32db4:	3c0b800a */ 	lui	$t3,0x800a
/*    32db8:	85b9003a */ 	lh	$t9,0x3a($t5)
/*    32dbc:	85ae0038 */ 	lh	$t6,0x38($t5)
/*    32dc0:	91ea0002 */ 	lbu	$t2,0x2($t7)
/*    32dc4:	8d6bc334 */ 	lw	$t3,-0x3ccc($t3)
/*    32dc8:	032e0019 */ 	multu	$t9,$t6
/*    32dcc:	314c001f */ 	andi	$t4,$t2,0x1f
/*    32dd0:	8faa00ac */ 	lw	$t2,0xac($sp)
/*    32dd4:	000c4840 */ 	sll	$t1,$t4,0x1
/*    32dd8:	0169c021 */ 	addu	$t8,$t3,$t1
/*    32ddc:	914c000d */ 	lbu	$t4,0xd($t2)
/*    32de0:	24013f01 */ 	addiu	$at,$zero,0x3f01
/*    32de4:	87080000 */ 	lh	$t0,0x0($t8)
/*    32de8:	00007812 */ 	mflo	$t7
/*    32dec:	00000000 */ 	sll	$zero,$zero,0x0
/*    32df0:	00000000 */ 	sll	$zero,$zero,0x0
/*    32df4:	01ec0019 */ 	multu	$t7,$t4
/*    32df8:	00005812 */ 	mflo	$t3
/*    32dfc:	00000000 */ 	sll	$zero,$zero,0x0
/*    32e00:	00000000 */ 	sll	$zero,$zero,0x0
/*    32e04:	0161001a */ 	div	$zero,$t3,$at
/*    32e08:	00004812 */ 	mflo	$t1
/*    32e0c:	24017fff */ 	addiu	$at,$zero,0x7fff
/*    32e10:	00000000 */ 	sll	$zero,$zero,0x0
/*    32e14:	01090019 */ 	multu	$t0,$t1
/*    32e18:	0000c012 */ 	mflo	$t8
/*    32e1c:	00000000 */ 	sll	$zero,$zero,0x0
/*    32e20:	00000000 */ 	sll	$zero,$zero,0x0
/*    32e24:	0301001a */ 	div	$zero,$t8,$at
/*    32e28:	00006812 */ 	mflo	$t5
/*    32e2c:	1da00003 */ 	bgtz	$t5,.L00032e3c
/*    32e30:	00000000 */ 	sll	$zero,$zero,0x0
/*    32e34:	10000023 */ 	beqz	$zero,.L00032ec4
/*    32e38:	afa00078 */ 	sw	$zero,0x78($sp)
.L00032e3c:
/*    32e3c:	8fa90060 */ 	lw	$t1,0x60($sp)
/*    32e40:	8fae00a8 */ 	lw	$t6,0xa8($sp)
/*    32e44:	3c19800a */ 	lui	$t9,0x800a
/*    32e48:	8538003a */ 	lh	$t8,0x3a($t1)
/*    32e4c:	852d0038 */ 	lh	$t5,0x38($t1)
/*    32e50:	91ca0002 */ 	lbu	$t2,0x2($t6)
/*    32e54:	8f39c334 */ 	lw	$t9,-0x3ccc($t9)
/*    32e58:	030d0019 */ 	multu	$t8,$t5
/*    32e5c:	314f001f */ 	andi	$t7,$t2,0x1f
/*    32e60:	8faa00ac */ 	lw	$t2,0xac($sp)
/*    32e64:	000f6040 */ 	sll	$t4,$t7,0x1
/*    32e68:	032c5821 */ 	addu	$t3,$t9,$t4
/*    32e6c:	914f000d */ 	lbu	$t7,0xd($t2)
/*    32e70:	24013f01 */ 	addiu	$at,$zero,0x3f01
/*    32e74:	85680000 */ 	lh	$t0,0x0($t3)
/*    32e78:	00007012 */ 	mflo	$t6
/*    32e7c:	00000000 */ 	sll	$zero,$zero,0x0
/*    32e80:	00000000 */ 	sll	$zero,$zero,0x0
/*    32e84:	01cf0019 */ 	multu	$t6,$t7
/*    32e88:	0000c812 */ 	mflo	$t9
/*    32e8c:	00000000 */ 	sll	$zero,$zero,0x0
/*    32e90:	00000000 */ 	sll	$zero,$zero,0x0
/*    32e94:	0321001a */ 	div	$zero,$t9,$at
/*    32e98:	00006012 */ 	mflo	$t4
/*    32e9c:	24017fff */ 	addiu	$at,$zero,0x7fff
/*    32ea0:	00000000 */ 	sll	$zero,$zero,0x0
/*    32ea4:	010c0019 */ 	multu	$t0,$t4
/*    32ea8:	00005812 */ 	mflo	$t3
/*    32eac:	00000000 */ 	sll	$zero,$zero,0x0
/*    32eb0:	00000000 */ 	sll	$zero,$zero,0x0
/*    32eb4:	0161001a */ 	div	$zero,$t3,$at
/*    32eb8:	00004812 */ 	mflo	$t1
/*    32ebc:	2538ffff */ 	addiu	$t8,$t1,-1
/*    32ec0:	afb80078 */ 	sw	$t8,0x78($sp)
.L00032ec4:
/*    32ec4:	8fad00ac */ 	lw	$t5,0xac($sp)
/*    32ec8:	8faf0060 */ 	lw	$t7,0x60($sp)
/*    32ecc:	8daa0000 */ 	lw	$t2,0x0($t5)
/*    32ed0:	c5f00028 */ 	lwc1	$f16,0x28($t7)
/*    32ed4:	c5e4002c */ 	lwc1	$f4,0x2c($t7)
/*    32ed8:	8d4e0004 */ 	lw	$t6,0x4($t2)
/*    32edc:	448e4000 */ 	mtc1	$t6,$f8
/*    32ee0:	00000000 */ 	sll	$zero,$zero,0x0
/*    32ee4:	468042a0 */ 	cvt.s.w	$f10,$f8
/*    32ee8:	46105483 */ 	div.s	$f18,$f10,$f16
/*    32eec:	46049183 */ 	div.s	$f6,$f18,$f4
/*    32ef0:	4600320d */ 	trunc.w.s	$f8,$f6
/*    32ef4:	44084000 */ 	mfc1	$t0,$f8
/*    32ef8:	00000000 */ 	sll	$zero,$zero,0x0
/*    32efc:	afa80080 */ 	sw	$t0,0x80($sp)
/*    32f00:	8fac0080 */ 	lw	$t4,0x80($sp)
/*    32f04:	3c010053 */ 	lui	$at,0x53
/*    32f08:	3421ec61 */ 	ori	$at,$at,0xec61
/*    32f0c:	0181082a */ 	slt	$at,$t4,$at
/*    32f10:	14200005 */ 	bnez	$at,.L00032f28
/*    32f14:	00000000 */ 	sll	$zero,$zero,0x0
/*    32f18:	0c00cc24 */ 	jal	func00033090
/*    32f1c:	8fa40060 */ 	lw	$a0,0x60($sp)
/*    32f20:	1000003d */ 	beqz	$zero,.L00033018
/*    32f24:	00000000 */ 	sll	$zero,$zero,0x0
.L00032f28:
/*    32f28:	3c0b8006 */ 	lui	$t3,0x8006
/*    32f2c:	8d6bf12c */ 	lw	$t3,-0xed4($t3)
/*    32f30:	8fb80080 */ 	lw	$t8,0x80($sp)
/*    32f34:	8faa0060 */ 	lw	$t2,0x60($sp)
/*    32f38:	8d690050 */ 	lw	$t1,0x50($t3)
/*    32f3c:	01386821 */ 	addu	$t5,$t1,$t8
/*    32f40:	ad4d003c */ 	sw	$t5,0x3c($t2)
/*    32f44:	8fa40060 */ 	lw	$a0,0x60($sp)
/*    32f48:	8fa50078 */ 	lw	$a1,0x78($sp)
/*    32f4c:	8fa60080 */ 	lw	$a2,0x80($sp)
/*    32f50:	0c00f33c */ 	jal	func0003ccf0
/*    32f54:	2484000c */ 	addiu	$a0,$a0,0xc
/*    32f58:	240e0002 */ 	addiu	$t6,$zero,0x2
/*    32f5c:	a7ae0094 */ 	sh	$t6,0x94($sp)
/*    32f60:	8faf0060 */ 	lw	$t7,0x60($sp)
/*    32f64:	afaf0098 */ 	sw	$t7,0x98($sp)
/*    32f68:	3c048006 */ 	lui	$a0,%hi(var80060014)
/*    32f6c:	8c84f12c */ 	lw	$a0,-0xed4($a0)
/*    32f70:	27a50094 */ 	addiu	$a1,$sp,0x94
/*    32f74:	8fa60080 */ 	lw	$a2,0x80($sp)
/*    32f78:	00003825 */ 	or	$a3,$zero,$zero
/*    32f7c:	0c00f184 */ 	jal	func0003c610
/*    32f80:	24840014 */ 	addiu	$a0,$a0,%lo(var80060014)
/*    32f84:	8fb90060 */ 	lw	$t9,0x60($sp)
/*    32f88:	93280044 */ 	lbu	$t0,0x44($t9)
/*    32f8c:	310c0020 */ 	andi	$t4,$t0,0x20
/*    32f90:	11800003 */ 	beqz	$t4,.L00032fa0
/*    32f94:	00000000 */ 	sll	$zero,$zero,0x0
/*    32f98:	0c00cc40 */ 	jal	func00033100
/*    32f9c:	8fa40060 */ 	lw	$a0,0x60($sp)
.L00032fa0:
/*    32fa0:	1000001d */ 	beqz	$zero,.L00033018
/*    32fa4:	00000000 */ 	sll	$zero,$zero,0x0
.L00032fa8:
/*    32fa8:	0c00cc24 */ 	jal	func00033090
/*    32fac:	8fa40060 */ 	lw	$a0,0x60($sp)
/*    32fb0:	10000019 */ 	beqz	$zero,.L00033018
/*    32fb4:	00000000 */ 	sll	$zero,$zero,0x0
.L00032fb8:
/*    32fb8:	8fab0060 */ 	lw	$t3,0x60($sp)
/*    32fbc:	91690044 */ 	lbu	$t1,0x44($t3)
/*    32fc0:	31380010 */ 	andi	$t8,$t1,0x10
/*    32fc4:	13000010 */ 	beqz	$t8,.L00033008
/*    32fc8:	00000000 */ 	sll	$zero,$zero,0x0
/*    32fcc:	8faa0060 */ 	lw	$t2,0x60($sp)
/*    32fd0:	8fad00b8 */ 	lw	$t5,0xb8($sp)
/*    32fd4:	c54a002c */ 	lwc1	$f10,0x2c($t2)
/*    32fd8:	85460038 */ 	lh	$a2,0x38($t2)
/*    32fdc:	91470041 */ 	lbu	$a3,0x41($t2)
/*    32fe0:	8da4000c */ 	lw	$a0,0xc($t5)
/*    32fe4:	8da50008 */ 	lw	$a1,0x8($t5)
/*    32fe8:	e7aa0010 */ 	swc1	$f10,0x10($sp)
/*    32fec:	914e0042 */ 	lbu	$t6,0x42($t2)
/*    32ff0:	afae0014 */ 	sw	$t6,0x14($sp)
/*    32ff4:	914f0043 */ 	lbu	$t7,0x43($t2)
/*    32ff8:	afaf0018 */ 	sw	$t7,0x18($sp)
/*    32ffc:	8d590030 */ 	lw	$t9,0x30($t2)
/*    33000:	0c00ce08 */ 	jal	func00033820
/*    33004:	afb9001c */ 	sw	$t9,0x1c($sp)
.L00033008:
/*    33008:	10000003 */ 	beqz	$zero,.L00033018
/*    3300c:	00000000 */ 	sll	$zero,$zero,0x0
.L00033010:
/*    33010:	10000001 */ 	beqz	$zero,.L00033018
/*    33014:	00000000 */ 	sll	$zero,$zero,0x0
.L00033018:
/*    33018:	8fa800b8 */ 	lw	$t0,0xb8($sp)
/*    3301c:	950c0000 */ 	lhu	$t4,0x0($t0)
/*    33020:	318b02d1 */ 	andi	$t3,$t4,0x2d1
/*    33024:	afab006c */ 	sw	$t3,0x6c($sp)
/*    33028:	8fa9005c */ 	lw	$t1,0x5c($sp)
/*    3302c:	11200008 */ 	beqz	$t1,.L00033050
/*    33030:	afa90060 */ 	sw	$t1,0x60($sp)
/*    33034:	8fb8006c */ 	lw	$t8,0x6c($sp)
/*    33038:	17000005 */ 	bnez	$t8,.L00033050
/*    3303c:	00000000 */ 	sll	$zero,$zero,0x0
/*    33040:	8fad0060 */ 	lw	$t5,0x60($sp)
/*    33044:	91ae0044 */ 	lbu	$t6,0x44($t5)
/*    33048:	31cf0001 */ 	andi	$t7,$t6,0x1
/*    3304c:	afaf0068 */ 	sw	$t7,0x68($sp)
.L00033050:
/*    33050:	8faa0068 */ 	lw	$t2,0x68($sp)
/*    33054:	15400007 */ 	bnez	$t2,.L00033074
/*    33058:	00000000 */ 	sll	$zero,$zero,0x0
/*    3305c:	8fb90060 */ 	lw	$t9,0x60($sp)
/*    33060:	13200004 */ 	beqz	$t9,.L00033074
/*    33064:	00000000 */ 	sll	$zero,$zero,0x0
/*    33068:	8fa8006c */ 	lw	$t0,0x6c($sp)
/*    3306c:	1100fabb */ 	beqz	$t0,.L00031b5c
/*    33070:	00000000 */ 	sll	$zero,$zero,0x0
.L00033074:
/*    33074:	10000001 */ 	beqz	$zero,.L0003307c
/*    33078:	00000000 */ 	sll	$zero,$zero,0x0
.L0003307c:
/*    3307c:	8fbf0034 */ 	lw	$ra,0x34($sp)
/*    33080:	8fb0002c */ 	lw	$s0,0x2c($sp)
/*    33084:	8fb10030 */ 	lw	$s1,0x30($sp)
/*    33088:	03e00008 */ 	jr	$ra
/*    3308c:	27bd00b8 */ 	addiu	$sp,$sp,0xb8
);

GLOBAL_ASM(
glabel func00033090
/*    33090:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*    33094:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    33098:	afa40018 */ 	sw	$a0,0x18($sp)
/*    3309c:	8fae0018 */ 	lw	$t6,0x18($sp)
/*    330a0:	91cf0044 */ 	lbu	$t7,0x44($t6)
/*    330a4:	31f80004 */ 	andi	$t8,$t7,0x4
/*    330a8:	13000007 */ 	beqz	$t8,.L000330c8
/*    330ac:	00000000 */ 	sll	$zero,$zero,0x0
/*    330b0:	8fa40018 */ 	lw	$a0,0x18($sp)
/*    330b4:	0c00f440 */ 	jal	func0003d100
/*    330b8:	2484000c */ 	addiu	$a0,$a0,0xc
/*    330bc:	8fa40018 */ 	lw	$a0,0x18($sp)
/*    330c0:	0c00f468 */ 	jal	func0003d1a0
/*    330c4:	2484000c */ 	addiu	$a0,$a0,0xc
.L000330c8:
/*    330c8:	0c00cd93 */ 	jal	func0003364c
/*    330cc:	8fa40018 */ 	lw	$a0,0x18($sp)
/*    330d0:	3c048006 */ 	lui	$a0,%hi(var80060014)
/*    330d4:	8c84f12c */ 	lw	$a0,-0xed4($a0)
/*    330d8:	8fa50018 */ 	lw	$a1,0x18($sp)
/*    330dc:	3406ffff */ 	dli	$a2,0xffff
/*    330e0:	0c00cc60 */ 	jal	func00033180
/*    330e4:	24840014 */ 	addiu	$a0,$a0,%lo(var80060014)
/*    330e8:	10000001 */ 	beqz	$zero,.L000330f0
/*    330ec:	00000000 */ 	sll	$zero,$zero,0x0
.L000330f0:
/*    330f0:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    330f4:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*    330f8:	03e00008 */ 	jr	$ra
/*    330fc:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func00033100
/*    33100:	27bdffd0 */ 	addiu	$sp,$sp,-48
/*    33104:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    33108:	afa40030 */ 	sw	$a0,0x30($sp)
/*    3310c:	8fae0030 */ 	lw	$t6,0x30($sp)
/*    33110:	8dcf0008 */ 	lw	$t7,0x8($t6)
/*    33114:	8df80004 */ 	lw	$t8,0x4($t7)
/*    33118:	0c00e7f8 */ 	jal	func00039fe0
/*    3311c:	83040005 */ 	lb	$a0,0x5($t8)
/*    33120:	8fb90030 */ 	lw	$t9,0x30($sp)
/*    33124:	c724002c */ 	lwc1	$f4,0x2c($t9)
/*    33128:	46040182 */ 	mul.s	$f6,$f0,$f4
/*    3312c:	e7a6001c */ 	swc1	$f6,0x1c($sp)
/*    33130:	24080010 */ 	addiu	$t0,$zero,0x10
/*    33134:	a7a80020 */ 	sh	$t0,0x20($sp)
/*    33138:	8fa90030 */ 	lw	$t1,0x30($sp)
/*    3313c:	afa90024 */ 	sw	$t1,0x24($sp)
/*    33140:	27aa001c */ 	addiu	$t2,$sp,0x1c
/*    33144:	8d4b0000 */ 	lw	$t3,0x0($t2)
/*    33148:	afab0028 */ 	sw	$t3,0x28($sp)
/*    3314c:	3c048006 */ 	lui	$a0,%hi(var80060014)
/*    33150:	8c84f12c */ 	lw	$a0,-0xed4($a0)
/*    33154:	27a50020 */ 	addiu	$a1,$sp,0x20
/*    33158:	34068235 */ 	dli	$a2,0x8235
/*    3315c:	00003825 */ 	or	$a3,$zero,$zero
/*    33160:	0c00f184 */ 	jal	func0003c610
/*    33164:	24840014 */ 	addiu	$a0,$a0,%lo(var80060014)
/*    33168:	10000001 */ 	beqz	$zero,.L00033170
/*    3316c:	00000000 */ 	sll	$zero,$zero,0x0
.L00033170:
/*    33170:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    33174:	27bd0030 */ 	addiu	$sp,$sp,0x30
/*    33178:	03e00008 */ 	jr	$ra
/*    3317c:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func00033180
/*    33180:	27bdffd0 */ 	addiu	$sp,$sp,-48
/*    33184:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    33188:	afa40030 */ 	sw	$a0,0x30($sp)
/*    3318c:	afa50034 */ 	sw	$a1,0x34($sp)
/*    33190:	afa60038 */ 	sw	$a2,0x38($sp)
/*    33194:	0c012194 */ 	jal	func00048650
/*    33198:	24040001 */ 	addiu	$a0,$zero,0x1
/*    3319c:	afa20018 */ 	sw	$v0,0x18($sp)
/*    331a0:	8fae0030 */ 	lw	$t6,0x30($sp)
/*    331a4:	8dcf0008 */ 	lw	$t7,0x8($t6)
/*    331a8:	afaf002c */ 	sw	$t7,0x2c($sp)
/*    331ac:	8fb8002c */ 	lw	$t8,0x2c($sp)
/*    331b0:	13000028 */ 	beqz	$t8,.L00033254
/*    331b4:	00000000 */ 	sll	$zero,$zero,0x0
.L000331b8:
/*    331b8:	8fb9002c */ 	lw	$t9,0x2c($sp)
/*    331bc:	8f280000 */ 	lw	$t0,0x0($t9)
/*    331c0:	afa80028 */ 	sw	$t0,0x28($sp)
/*    331c4:	8fa9002c */ 	lw	$t1,0x2c($sp)
/*    331c8:	afa90024 */ 	sw	$t1,0x24($sp)
/*    331cc:	8faa0028 */ 	lw	$t2,0x28($sp)
/*    331d0:	afaa0020 */ 	sw	$t2,0x20($sp)
/*    331d4:	8fab0024 */ 	lw	$t3,0x24($sp)
/*    331d8:	256c000c */ 	addiu	$t4,$t3,0xc
/*    331dc:	afac001c */ 	sw	$t4,0x1c($sp)
/*    331e0:	8fad001c */ 	lw	$t5,0x1c($sp)
/*    331e4:	8faf0034 */ 	lw	$t7,0x34($sp)
/*    331e8:	8dae0004 */ 	lw	$t6,0x4($t5)
/*    331ec:	15cf0014 */ 	bne	$t6,$t7,.L00033240
/*    331f0:	00000000 */ 	sll	$zero,$zero,0x0
/*    331f4:	95b80000 */ 	lhu	$t8,0x0($t5)
/*    331f8:	97b9003a */ 	lhu	$t9,0x3a($sp)
/*    331fc:	03194024 */ 	and	$t0,$t8,$t9
/*    33200:	1100000f */ 	beqz	$t0,.L00033240
/*    33204:	00000000 */ 	sll	$zero,$zero,0x0
/*    33208:	8fa90020 */ 	lw	$t1,0x20($sp)
/*    3320c:	11200007 */ 	beqz	$t1,.L0003322c
/*    33210:	00000000 */ 	sll	$zero,$zero,0x0
/*    33214:	8faa0020 */ 	lw	$t2,0x20($sp)
/*    33218:	8fac0024 */ 	lw	$t4,0x24($sp)
/*    3321c:	8d4b0008 */ 	lw	$t3,0x8($t2)
/*    33220:	8d8e0008 */ 	lw	$t6,0x8($t4)
/*    33224:	016e7821 */ 	addu	$t7,$t3,$t6
/*    33228:	ad4f0008 */ 	sw	$t7,0x8($t2)
.L0003322c:
/*    3322c:	0c00c5e9 */ 	jal	func000317a4
/*    33230:	8fa4002c */ 	lw	$a0,0x2c($sp)
/*    33234:	8fa4002c */ 	lw	$a0,0x2c($sp)
/*    33238:	0c00c5dc */ 	jal	func00031770
/*    3323c:	8fa50030 */ 	lw	$a1,0x30($sp)
.L00033240:
/*    33240:	8fad0028 */ 	lw	$t5,0x28($sp)
/*    33244:	afad002c */ 	sw	$t5,0x2c($sp)
/*    33248:	8fb8002c */ 	lw	$t8,0x2c($sp)
/*    3324c:	1700ffda */ 	bnez	$t8,.L000331b8
/*    33250:	00000000 */ 	sll	$zero,$zero,0x0
.L00033254:
/*    33254:	0c012194 */ 	jal	func00048650
/*    33258:	8fa40018 */ 	lw	$a0,0x18($sp)
/*    3325c:	10000001 */ 	beqz	$zero,.L00033264
/*    33260:	00000000 */ 	sll	$zero,$zero,0x0
.L00033264:
/*    33264:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    33268:	27bd0030 */ 	addiu	$sp,$sp,0x30
/*    3326c:	03e00008 */ 	jr	$ra
/*    33270:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func00033274
/*    33274:	27bdffd0 */ 	addiu	$sp,$sp,-48
/*    33278:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    3327c:	afa40030 */ 	sw	$a0,0x30($sp)
/*    33280:	afa50034 */ 	sw	$a1,0x34($sp)
/*    33284:	0c012194 */ 	jal	func00048650
/*    33288:	24040001 */ 	addiu	$a0,$zero,0x1
/*    3328c:	afa2002c */ 	sw	$v0,0x2c($sp)
/*    33290:	3c0e8006 */ 	lui	$t6,0x8006
/*    33294:	8dcef120 */ 	lw	$t6,-0xee0($t6)
/*    33298:	afae0020 */ 	sw	$t6,0x20($sp)
/*    3329c:	3c0f8006 */ 	lui	$t7,0x8006
/*    332a0:	8deff128 */ 	lw	$t7,-0xed8($t7)
/*    332a4:	afaf001c */ 	sw	$t7,0x1c($sp)
/*    332a8:	3c188006 */ 	lui	$t8,0x8006
/*    332ac:	8f18f124 */ 	lw	$t8,-0xedc($t8)
/*    332b0:	afb80018 */ 	sw	$t8,0x18($sp)
/*    332b4:	8fb90020 */ 	lw	$t9,0x20($sp)
/*    332b8:	a7a0002a */ 	sh	$zero,0x2a($sp)
/*    332bc:	13200008 */ 	beqz	$t9,.L000332e0
/*    332c0:	00000000 */ 	sll	$zero,$zero,0x0
.L000332c4:
/*    332c4:	97a8002a */ 	lhu	$t0,0x2a($sp)
/*    332c8:	8faa0020 */ 	lw	$t2,0x20($sp)
/*    332cc:	25090001 */ 	addiu	$t1,$t0,0x1
/*    332d0:	a7a9002a */ 	sh	$t1,0x2a($sp)
/*    332d4:	8d4b0000 */ 	lw	$t3,0x0($t2)
/*    332d8:	1560fffa */ 	bnez	$t3,.L000332c4
/*    332dc:	afab0020 */ 	sw	$t3,0x20($sp)
.L000332e0:
/*    332e0:	8fac001c */ 	lw	$t4,0x1c($sp)
/*    332e4:	a7a00028 */ 	sh	$zero,0x28($sp)
/*    332e8:	11800008 */ 	beqz	$t4,.L0003330c
/*    332ec:	00000000 */ 	sll	$zero,$zero,0x0
.L000332f0:
/*    332f0:	97ad0028 */ 	lhu	$t5,0x28($sp)
/*    332f4:	8faf001c */ 	lw	$t7,0x1c($sp)
/*    332f8:	25ae0001 */ 	addiu	$t6,$t5,0x1
/*    332fc:	a7ae0028 */ 	sh	$t6,0x28($sp)
/*    33300:	8df80000 */ 	lw	$t8,0x0($t7)
/*    33304:	1700fffa */ 	bnez	$t8,.L000332f0
/*    33308:	afb8001c */ 	sw	$t8,0x1c($sp)
.L0003330c:
/*    3330c:	8fb90018 */ 	lw	$t9,0x18($sp)
/*    33310:	a7a00026 */ 	sh	$zero,0x26($sp)
/*    33314:	13200008 */ 	beqz	$t9,.L00033338
/*    33318:	00000000 */ 	sll	$zero,$zero,0x0
.L0003331c:
/*    3331c:	97a80026 */ 	lhu	$t0,0x26($sp)
/*    33320:	8faa0018 */ 	lw	$t2,0x18($sp)
/*    33324:	25090001 */ 	addiu	$t1,$t0,0x1
/*    33328:	a7a90026 */ 	sh	$t1,0x26($sp)
/*    3332c:	8d4b0004 */ 	lw	$t3,0x4($t2)
/*    33330:	1560fffa */ 	bnez	$t3,.L0003331c
/*    33334:	afab0018 */ 	sw	$t3,0x18($sp)
.L00033338:
/*    33338:	97ac0028 */ 	lhu	$t4,0x28($sp)
/*    3333c:	8fad0030 */ 	lw	$t5,0x30($sp)
/*    33340:	a5ac0000 */ 	sh	$t4,0x0($t5)
/*    33344:	97ae002a */ 	lhu	$t6,0x2a($sp)
/*    33348:	8faf0034 */ 	lw	$t7,0x34($sp)
/*    3334c:	a5ee0000 */ 	sh	$t6,0x0($t7)
/*    33350:	0c012194 */ 	jal	func00048650
/*    33354:	8fa4002c */ 	lw	$a0,0x2c($sp)
/*    33358:	10000003 */ 	beqz	$zero,.L00033368
/*    3335c:	97a20026 */ 	lhu	$v0,0x26($sp)
/*    33360:	10000001 */ 	beqz	$zero,.L00033368
/*    33364:	00000000 */ 	sll	$zero,$zero,0x0
.L00033368:
/*    33368:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    3336c:	27bd0030 */ 	addiu	$sp,$sp,0x30
/*    33370:	03e00008 */ 	jr	$ra
/*    33374:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func00033378
/*    33378:	3c018006 */ 	lui	$at,0x8006
/*    3337c:	ac24f13c */ 	sw	$a0,-0xec4($at)
/*    33380:	03e00008 */ 	jr	$ra
/*    33384:	00000000 */ 	sll	$zero,$zero,0x0
/*    33388:	03e00008 */ 	jr	$ra
/*    3338c:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func00033390
/*    33390:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*    33394:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    33398:	afa40028 */ 	sw	$a0,0x28($sp)
/*    3339c:	afa5002c */ 	sw	$a1,0x2c($sp)
/*    333a0:	8fae002c */ 	lw	$t6,0x2c($sp)
/*    333a4:	8dcf0004 */ 	lw	$t7,0x4($t6)
/*    333a8:	afaf0020 */ 	sw	$t7,0x20($sp)
/*    333ac:	3c188006 */ 	lui	$t8,0x8006
/*    333b0:	8f18f134 */ 	lw	$t8,-0xecc($t8)
/*    333b4:	3c088006 */ 	lui	$t0,0x8006
/*    333b8:	8d08f138 */ 	lw	$t0,-0xec8($t0)
/*    333bc:	3c018006 */ 	lui	$at,0x8006
/*    333c0:	27190001 */ 	addiu	$t9,$t8,0x1
/*    333c4:	ac39f134 */ 	sw	$t9,-0xecc($at)
/*    333c8:	0119082a */ 	slt	$at,$t0,$t9
/*    333cc:	1020000a */ 	beqz	$at,.L000333f8
/*    333d0:	00000000 */ 	sll	$zero,$zero,0x0
/*    333d4:	3c098006 */ 	lui	$t1,0x8006
/*    333d8:	8d29f134 */ 	lw	$t1,-0xecc($t1)
/*    333dc:	3c018006 */ 	lui	$at,0x8006
/*    333e0:	ac29f138 */ 	sw	$t1,-0xec8($at)
/*    333e4:	3c0a8006 */ 	lui	$t2,0x8006
/*    333e8:	8d4af134 */ 	lw	$t2,-0xecc($t2)
/*    333ec:	29410011 */ 	slti	$at,$t2,0x11
/*    333f0:	14200001 */ 	bnez	$at,.L000333f8
/*    333f4:	00000000 */ 	sll	$zero,$zero,0x0
.L000333f8:
/*    333f8:	0c012194 */ 	jal	func00048650
/*    333fc:	24040001 */ 	addiu	$a0,$zero,0x1
/*    33400:	afa2001c */ 	sw	$v0,0x1c($sp)
/*    33404:	3c0b8006 */ 	lui	$t3,0x8006
/*    33408:	8d6bf128 */ 	lw	$t3,-0xed8($t3)
/*    3340c:	afab0024 */ 	sw	$t3,0x24($sp)
/*    33410:	8fac0024 */ 	lw	$t4,0x24($sp)
/*    33414:	1180007d */ 	beqz	$t4,.L0003360c
/*    33418:	00000000 */ 	sll	$zero,$zero,0x0
/*    3341c:	8fad0024 */ 	lw	$t5,0x24($sp)
/*    33420:	3c018006 */ 	lui	$at,0x8006
/*    33424:	8dae0000 */ 	lw	$t6,0x0($t5)
/*    33428:	ac2ef128 */ 	sw	$t6,-0xed8($at)
/*    3342c:	0c00c5e9 */ 	jal	func000317a4
/*    33430:	8fa40024 */ 	lw	$a0,0x24($sp)
/*    33434:	3c0f8006 */ 	lui	$t7,0x8006
/*    33438:	8deff120 */ 	lw	$t7,-0xee0($t7)
/*    3343c:	11e0000f */ 	beqz	$t7,.L0003347c
/*    33440:	00000000 */ 	sll	$zero,$zero,0x0
/*    33444:	3c188006 */ 	lui	$t8,0x8006
/*    33448:	8f18f120 */ 	lw	$t8,-0xee0($t8)
/*    3344c:	8fb90024 */ 	lw	$t9,0x24($sp)
/*    33450:	af380000 */ 	sw	$t8,0x0($t9)
/*    33454:	8fa80024 */ 	lw	$t0,0x24($sp)
/*    33458:	ad000004 */ 	sw	$zero,0x4($t0)
/*    3345c:	3c0a8006 */ 	lui	$t2,0x8006
/*    33460:	8d4af120 */ 	lw	$t2,-0xee0($t2)
/*    33464:	8fa90024 */ 	lw	$t1,0x24($sp)
/*    33468:	ad490004 */ 	sw	$t1,0x4($t2)
/*    3346c:	8fab0024 */ 	lw	$t3,0x24($sp)
/*    33470:	3c018006 */ 	lui	$at,0x8006
/*    33474:	1000000c */ 	beqz	$zero,.L000334a8
/*    33478:	ac2bf120 */ 	sw	$t3,-0xee0($at)
.L0003347c:
/*    3347c:	8fac0024 */ 	lw	$t4,0x24($sp)
/*    33480:	ad800004 */ 	sw	$zero,0x4($t4)
/*    33484:	8fad0024 */ 	lw	$t5,0x24($sp)
/*    33488:	8dae0004 */ 	lw	$t6,0x4($t5)
/*    3348c:	adae0000 */ 	sw	$t6,0x0($t5)
/*    33490:	8faf0024 */ 	lw	$t7,0x24($sp)
/*    33494:	3c018006 */ 	lui	$at,0x8006
/*    33498:	ac2ff120 */ 	sw	$t7,-0xee0($at)
/*    3349c:	8fb80024 */ 	lw	$t8,0x24($sp)
/*    334a0:	3c018006 */ 	lui	$at,0x8006
/*    334a4:	ac38f124 */ 	sw	$t8,-0xedc($at)
.L000334a8:
/*    334a8:	0c012194 */ 	jal	func00048650
/*    334ac:	8fa4001c */ 	lw	$a0,0x1c($sp)
/*    334b0:	8fb9002c */ 	lw	$t9,0x2c($sp)
/*    334b4:	8f280000 */ 	lw	$t0,0x0($t9)
/*    334b8:	8d090004 */ 	lw	$t1,0x4($t0)
/*    334bc:	252a0001 */ 	addiu	$t2,$t1,0x1
/*    334c0:	2d4a0001 */ 	sltiu	$t2,$t2,0x1
/*    334c4:	afaa0018 */ 	sw	$t2,0x18($sp)
/*    334c8:	8fab002c */ 	lw	$t3,0x2c($sp)
/*    334cc:	8fac0024 */ 	lw	$t4,0x24($sp)
/*    334d0:	ad8b0008 */ 	sw	$t3,0x8($t4)
/*    334d4:	8fae0018 */ 	lw	$t6,0x18($sp)
/*    334d8:	8faf0024 */ 	lw	$t7,0x24($sp)
/*    334dc:	25cd0040 */ 	addiu	$t5,$t6,0x40
/*    334e0:	a1ed0040 */ 	sb	$t5,0x40($t7)
/*    334e4:	8fb90024 */ 	lw	$t9,0x24($sp)
/*    334e8:	24180005 */ 	addiu	$t8,$zero,0x5
/*    334ec:	a3380045 */ 	sb	$t8,0x45($t9)
/*    334f0:	3c013f80 */ 	lui	$at,0x3f80
/*    334f4:	44812000 */ 	mtc1	$at,$f4
/*    334f8:	8fa80024 */ 	lw	$t0,0x24($sp)
/*    334fc:	e504002c */ 	swc1	$f4,0x2c($t0)
/*    33500:	8faa0024 */ 	lw	$t2,0x24($sp)
/*    33504:	24090002 */ 	addiu	$t1,$zero,0x2
/*    33508:	ad490034 */ 	sw	$t1,0x34($t2)
/*    3350c:	8fab0020 */ 	lw	$t3,0x20($sp)
/*    33510:	8fad0024 */ 	lw	$t5,0x24($sp)
/*    33514:	916c0003 */ 	lbu	$t4,0x3($t3)
/*    33518:	318e00f0 */ 	andi	$t6,$t4,0xf0
/*    3351c:	a1ae0044 */ 	sb	$t6,0x44($t5)
/*    33520:	8faf0024 */ 	lw	$t7,0x24($sp)
/*    33524:	ade00030 */ 	sw	$zero,0x30($t7)
/*    33528:	8fb80024 */ 	lw	$t8,0x24($sp)
/*    3352c:	93190044 */ 	lbu	$t9,0x44($t8)
/*    33530:	33280020 */ 	andi	$t0,$t9,0x20
/*    33534:	1100000e */ 	beqz	$t0,.L00033570
/*    33538:	00000000 */ 	sll	$zero,$zero,0x0
/*    3353c:	8fa90020 */ 	lw	$t1,0x20($sp)
/*    33540:	91240004 */ 	lbu	$a0,0x4($t1)
/*    33544:	00800821 */ 	addu	$at,$a0,$zero
/*    33548:	00012080 */ 	sll	$a0,$at,0x2
/*    3354c:	00812023 */ 	subu	$a0,$a0,$at
/*    33550:	000420c0 */ 	sll	$a0,$a0,0x3
/*    33554:	00812021 */ 	addu	$a0,$a0,$at
/*    33558:	00042080 */ 	sll	$a0,$a0,0x2
/*    3355c:	0c00e7f8 */ 	jal	func00039fe0
/*    33560:	2484e890 */ 	addiu	$a0,$a0,-6000
/*    33564:	8faa0024 */ 	lw	$t2,0x24($sp)
/*    33568:	1000000e */ 	beqz	$zero,.L000335a4
/*    3356c:	e5400028 */ 	swc1	$f0,0x28($t2)
.L00033570:
/*    33570:	8fab0020 */ 	lw	$t3,0x20($sp)
/*    33574:	916c0004 */ 	lbu	$t4,0x4($t3)
/*    33578:	816d0005 */ 	lb	$t5,0x5($t3)
/*    3357c:	000c7080 */ 	sll	$t6,$t4,0x2
/*    33580:	01cc7023 */ 	subu	$t6,$t6,$t4
/*    33584:	000e70c0 */ 	sll	$t6,$t6,0x3
/*    33588:	01cc7021 */ 	addu	$t6,$t6,$t4
/*    3358c:	000e7080 */ 	sll	$t6,$t6,0x2
/*    33590:	01cd2021 */ 	addu	$a0,$t6,$t5
/*    33594:	0c00e7f8 */ 	jal	func00039fe0
/*    33598:	2484e890 */ 	addiu	$a0,$a0,-6000
/*    3359c:	8faf0024 */ 	lw	$t7,0x24($sp)
/*    335a0:	e5e00028 */ 	swc1	$f0,0x28($t7)
.L000335a4:
/*    335a4:	8fb80018 */ 	lw	$t8,0x18($sp)
/*    335a8:	13000005 */ 	beqz	$t8,.L000335c0
/*    335ac:	00000000 */ 	sll	$zero,$zero,0x0
/*    335b0:	8fb90024 */ 	lw	$t9,0x24($sp)
/*    335b4:	93280044 */ 	lbu	$t0,0x44($t9)
/*    335b8:	35090002 */ 	ori	$t1,$t0,0x2
/*    335bc:	a3290044 */ 	sb	$t1,0x44($t9)
.L000335c0:
/*    335c0:	8faa0024 */ 	lw	$t2,0x24($sp)
/*    335c4:	a1400042 */ 	sb	$zero,0x42($t2)
/*    335c8:	8fab0024 */ 	lw	$t3,0x24($sp)
/*    335cc:	240c0040 */ 	addiu	$t4,$zero,0x40
/*    335d0:	a16c0041 */ 	sb	$t4,0x41($t3)
/*    335d4:	8fad0024 */ 	lw	$t5,0x24($sp)
/*    335d8:	240e7fff */ 	addiu	$t6,$zero,0x7fff
/*    335dc:	a5ae0038 */ 	sh	$t6,0x38($t5)
/*    335e0:	3c0f8006 */ 	lui	$t7,0x8006
/*    335e4:	8deff13c */ 	lw	$t7,-0xec4($t7)
/*    335e8:	11e00006 */ 	beqz	$t7,.L00033604
/*    335ec:	00000000 */ 	sll	$zero,$zero,0x0
/*    335f0:	3c198006 */ 	lui	$t9,0x8006
/*    335f4:	8f39f13c */ 	lw	$t9,-0xec4($t9)
/*    335f8:	8fb80024 */ 	lw	$t8,0x24($sp)
/*    335fc:	0320f809 */ 	jalr	$t9
/*    33600:	8f040008 */ 	lw	$a0,0x8($t8)
.L00033604:
/*    33604:	10000003 */ 	beqz	$zero,.L00033614
/*    33608:	00000000 */ 	sll	$zero,$zero,0x0
.L0003360c:
/*    3360c:	0c012194 */ 	jal	func00048650
/*    33610:	8fa4001c */ 	lw	$a0,0x1c($sp)
.L00033614:
/*    33614:	10000003 */ 	beqz	$zero,.L00033624
/*    33618:	8fa20024 */ 	lw	$v0,0x24($sp)
/*    3361c:	10000001 */ 	beqz	$zero,.L00033624
/*    33620:	00000000 */ 	sll	$zero,$zero,0x0
.L00033624:
/*    33624:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    33628:	27bd0028 */ 	addiu	$sp,$sp,0x28
/*    3362c:	03e00008 */ 	jr	$ra
/*    33630:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func00033634
/*    33634:	3c018006 */ 	lui	$at,0x8006
/*    33638:	ac24f140 */ 	sw	$a0,-0xec0($at)
/*    3363c:	03e00008 */ 	jr	$ra
/*    33640:	00000000 */ 	sll	$zero,$zero,0x0
/*    33644:	03e00008 */ 	jr	$ra
/*    33648:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0003364c
/*    3364c:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*    33650:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    33654:	afa40018 */ 	sw	$a0,0x18($sp)
/*    33658:	3c0e8006 */ 	lui	$t6,0x8006
/*    3365c:	8dcef134 */ 	lw	$t6,-0xecc($t6)
/*    33660:	3c018006 */ 	lui	$at,0x8006
/*    33664:	25cfffff */ 	addiu	$t7,$t6,-1
/*    33668:	ac2ff134 */ 	sw	$t7,-0xecc($at)
/*    3366c:	3c188006 */ 	lui	$t8,0x8006
/*    33670:	8f18f120 */ 	lw	$t8,-0xee0($t8)
/*    33674:	8fb90018 */ 	lw	$t9,0x18($sp)
/*    33678:	17190005 */ 	bne	$t8,$t9,.L00033690
/*    3367c:	00000000 */ 	sll	$zero,$zero,0x0
/*    33680:	8fa80018 */ 	lw	$t0,0x18($sp)
/*    33684:	3c018006 */ 	lui	$at,0x8006
/*    33688:	8d090000 */ 	lw	$t1,0x0($t0)
/*    3368c:	ac29f120 */ 	sw	$t1,-0xee0($at)
.L00033690:
/*    33690:	3c0a8006 */ 	lui	$t2,0x8006
/*    33694:	8d4af124 */ 	lw	$t2,-0xedc($t2)
/*    33698:	8fab0018 */ 	lw	$t3,0x18($sp)
/*    3369c:	154b0005 */ 	bne	$t2,$t3,.L000336b4
/*    336a0:	00000000 */ 	sll	$zero,$zero,0x0
/*    336a4:	8fac0018 */ 	lw	$t4,0x18($sp)
/*    336a8:	3c018006 */ 	lui	$at,0x8006
/*    336ac:	8d8d0004 */ 	lw	$t5,0x4($t4)
/*    336b0:	ac2df124 */ 	sw	$t5,-0xedc($at)
.L000336b4:
/*    336b4:	0c00c5e9 */ 	jal	func000317a4
/*    336b8:	8fa40018 */ 	lw	$a0,0x18($sp)
/*    336bc:	3c0e8006 */ 	lui	$t6,0x8006
/*    336c0:	8dcef128 */ 	lw	$t6,-0xed8($t6)
/*    336c4:	11c0000f */ 	beqz	$t6,.L00033704
/*    336c8:	00000000 */ 	sll	$zero,$zero,0x0
/*    336cc:	3c0f8006 */ 	lui	$t7,0x8006
/*    336d0:	8deff128 */ 	lw	$t7,-0xed8($t7)
/*    336d4:	8fb80018 */ 	lw	$t8,0x18($sp)
/*    336d8:	af0f0000 */ 	sw	$t7,0x0($t8)
/*    336dc:	8fb90018 */ 	lw	$t9,0x18($sp)
/*    336e0:	af200004 */ 	sw	$zero,0x4($t9)
/*    336e4:	3c098006 */ 	lui	$t1,0x8006
/*    336e8:	8d29f128 */ 	lw	$t1,-0xed8($t1)
/*    336ec:	8fa80018 */ 	lw	$t0,0x18($sp)
/*    336f0:	ad280004 */ 	sw	$t0,0x4($t1)
/*    336f4:	8faa0018 */ 	lw	$t2,0x18($sp)
/*    336f8:	3c018006 */ 	lui	$at,0x8006
/*    336fc:	10000009 */ 	beqz	$zero,.L00033724
/*    33700:	ac2af128 */ 	sw	$t2,-0xed8($at)
.L00033704:
/*    33704:	8fab0018 */ 	lw	$t3,0x18($sp)
/*    33708:	ad600004 */ 	sw	$zero,0x4($t3)
/*    3370c:	8fac0018 */ 	lw	$t4,0x18($sp)
/*    33710:	8d8d0004 */ 	lw	$t5,0x4($t4)
/*    33714:	ad8d0000 */ 	sw	$t5,0x0($t4)
/*    33718:	8fae0018 */ 	lw	$t6,0x18($sp)
/*    3371c:	3c018006 */ 	lui	$at,0x8006
/*    33720:	ac2ef128 */ 	sw	$t6,-0xed8($at)
.L00033724:
/*    33724:	8faf0018 */ 	lw	$t7,0x18($sp)
/*    33728:	91f80044 */ 	lbu	$t8,0x44($t7)
/*    3372c:	33190004 */ 	andi	$t9,$t8,0x4
/*    33730:	13200006 */ 	beqz	$t9,.L0003374c
/*    33734:	00000000 */ 	sll	$zero,$zero,0x0
/*    33738:	3c088006 */ 	lui	$t0,0x8006
/*    3373c:	8508f130 */ 	lh	$t0,-0xed0($t0)
/*    33740:	3c018006 */ 	lui	$at,0x8006
/*    33744:	2509ffff */ 	addiu	$t1,$t0,-1
/*    33748:	a429f130 */ 	sh	$t1,-0xed0($at)
.L0003374c:
/*    3374c:	8faa0018 */ 	lw	$t2,0x18($sp)
/*    33750:	a1400045 */ 	sb	$zero,0x45($t2)
/*    33754:	8fab0018 */ 	lw	$t3,0x18($sp)
/*    33758:	8d6d0030 */ 	lw	$t5,0x30($t3)
/*    3375c:	11a0000b */ 	beqz	$t5,.L0003378c
/*    33760:	00000000 */ 	sll	$zero,$zero,0x0
/*    33764:	8fac0018 */ 	lw	$t4,0x18($sp)
/*    33768:	8d8e0030 */ 	lw	$t6,0x30($t4)
/*    3376c:	8dcf0000 */ 	lw	$t7,0x0($t6)
/*    33770:	15ec0004 */ 	bne	$t7,$t4,.L00033784
/*    33774:	00000000 */ 	sll	$zero,$zero,0x0
/*    33778:	8fb80018 */ 	lw	$t8,0x18($sp)
/*    3377c:	8f190030 */ 	lw	$t9,0x30($t8)
/*    33780:	af200000 */ 	sw	$zero,0x0($t9)
.L00033784:
/*    33784:	8fa80018 */ 	lw	$t0,0x18($sp)
/*    33788:	ad000030 */ 	sw	$zero,0x30($t0)
.L0003378c:
/*    3378c:	3c098006 */ 	lui	$t1,0x8006
/*    33790:	8d29f140 */ 	lw	$t1,-0xec0($t1)
/*    33794:	11200006 */ 	beqz	$t1,.L000337b0
/*    33798:	00000000 */ 	sll	$zero,$zero,0x0
/*    3379c:	3c198006 */ 	lui	$t9,0x8006
/*    337a0:	8f39f140 */ 	lw	$t9,-0xec0($t9)
/*    337a4:	8faa0018 */ 	lw	$t2,0x18($sp)
/*    337a8:	0320f809 */ 	jalr	$t9
/*    337ac:	8d440008 */ 	lw	$a0,0x8($t2)
.L000337b0:
/*    337b0:	10000001 */ 	beqz	$zero,.L000337b8
/*    337b4:	00000000 */ 	sll	$zero,$zero,0x0
.L000337b8:
/*    337b8:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    337bc:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*    337c0:	03e00008 */ 	jr	$ra
/*    337c4:	00000000 */ 	sll	$zero,$zero,0x0
/*    337c8:	30a500ff */ 	andi	$a1,$a1,0xff
/*    337cc:	10800004 */ 	beqz	$a0,.L000337e0
/*    337d0:	00000000 */ 	sll	$zero,$zero,0x0
/*    337d4:	00057400 */ 	sll	$t6,$a1,0x10
/*    337d8:	000e7c03 */ 	sra	$t7,$t6,0x10
/*    337dc:	a08f0040 */ 	sb	$t7,0x40($a0)
.L000337e0:
/*    337e0:	03e00008 */ 	jr	$ra
/*    337e4:	00000000 */ 	sll	$zero,$zero,0x0
/*    337e8:	03e00008 */ 	jr	$ra
/*    337ec:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func000337f0
/*    337f0:	10800005 */ 	beqz	$a0,.L00033808
/*    337f4:	00000000 */ 	sll	$zero,$zero,0x0
/*    337f8:	03e00008 */ 	jr	$ra
/*    337fc:	90820045 */ 	lbu	$v0,0x45($a0)
/*    33800:	10000003 */ 	beqz	$zero,.L00033810
/*    33804:	00000000 */ 	sll	$zero,$zero,0x0
.L00033808:
/*    33808:	03e00008 */ 	jr	$ra
/*    3380c:	00001025 */ 	or	$v0,$zero,$zero
.L00033810:
/*    33810:	03e00008 */ 	jr	$ra
/*    33814:	00000000 */ 	sll	$zero,$zero,0x0
/*    33818:	03e00008 */ 	jr	$ra
/*    3381c:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func00033820
/*    33820:	27bdffa0 */ 	addiu	$sp,$sp,-96
/*    33824:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    33828:	afa40060 */ 	sw	$a0,0x60($sp)
/*    3382c:	afa50064 */ 	sw	$a1,0x64($sp)
/*    33830:	afa60068 */ 	sw	$a2,0x68($sp)
/*    33834:	afa7006c */ 	sw	$a3,0x6c($sp)
/*    33838:	afa00058 */ 	sw	$zero,0x58($sp)
/*    3383c:	a7a0004e */ 	sh	$zero,0x4e($sp)
/*    33840:	afa00040 */ 	sw	$zero,0x40($sp)
/*    33844:	0c0040d8 */ 	jal	func00010360
/*    33848:	00000000 */ 	sll	$zero,$zero,0x0
/*    3384c:	10400003 */ 	beqz	$v0,.L0003385c
/*    33850:	00000000 */ 	sll	$zero,$zero,0x0
/*    33854:	100000af */ 	beqz	$zero,.L00033b14
/*    33858:	00001025 */ 	or	$v0,$zero,$zero
.L0003385c:
/*    3385c:	87ae0066 */ 	lh	$t6,0x66($sp)
/*    33860:	11c000a2 */ 	beqz	$t6,.L00033aec
/*    33864:	00000000 */ 	sll	$zero,$zero,0x0
.L00033868:
/*    33868:	0c003d27 */ 	jal	func0000f49c
/*    3386c:	87a40066 */ 	lh	$a0,0x66($sp)
/*    33870:	afa20050 */ 	sw	$v0,0x50($sp)
/*    33874:	8fa40060 */ 	lw	$a0,0x60($sp)
/*    33878:	0c00cce4 */ 	jal	func00033390
/*    3387c:	8fa50050 */ 	lw	$a1,0x50($sp)
/*    33880:	afa2005c */ 	sw	$v0,0x5c($sp)
/*    33884:	8faf005c */ 	lw	$t7,0x5c($sp)
/*    33888:	11e00064 */ 	beqz	$t7,.L00033a1c
/*    3388c:	00000000 */ 	sll	$zero,$zero,0x0
/*    33890:	3c198006 */ 	lui	$t9,0x8006
/*    33894:	8f39f12c */ 	lw	$t9,-0xed4($t9)
/*    33898:	8fb8005c */ 	lw	$t8,0x5c($sp)
/*    3389c:	af38003c */ 	sw	$t8,0x3c($t9)
/*    338a0:	24080001 */ 	addiu	$t0,$zero,0x1
/*    338a4:	a7a8002c */ 	sh	$t0,0x2c($sp)
/*    338a8:	8fa9005c */ 	lw	$t1,0x5c($sp)
/*    338ac:	afa90030 */ 	sw	$t1,0x30($sp)
/*    338b0:	8fab005c */ 	lw	$t3,0x5c($sp)
/*    338b4:	93aa006f */ 	lbu	$t2,0x6f($sp)
/*    338b8:	916c0041 */ 	lbu	$t4,0x41($t3)
/*    338bc:	014c6821 */ 	addu	$t5,$t2,$t4
/*    338c0:	25aeffc0 */ 	addiu	$t6,$t5,-64
/*    338c4:	afae003c */ 	sw	$t6,0x3c($sp)
/*    338c8:	8faf003c */ 	lw	$t7,0x3c($sp)
/*    338cc:	29e10080 */ 	slti	$at,$t7,0x80
/*    338d0:	14200004 */ 	bnez	$at,.L000338e4
/*    338d4:	00000000 */ 	sll	$zero,$zero,0x0
/*    338d8:	2418007f */ 	addiu	$t8,$zero,0x7f
/*    338dc:	10000005 */ 	beqz	$zero,.L000338f4
/*    338e0:	afb8003c */ 	sw	$t8,0x3c($sp)
.L000338e4:
/*    338e4:	8fb9003c */ 	lw	$t9,0x3c($sp)
/*    338e8:	07210002 */ 	bgez	$t9,.L000338f4
/*    338ec:	00000000 */ 	sll	$zero,$zero,0x0
/*    338f0:	afa0003c */ 	sw	$zero,0x3c($sp)
.L000338f4:
/*    338f4:	8fa8003c */ 	lw	$t0,0x3c($sp)
/*    338f8:	8fa9005c */ 	lw	$t1,0x5c($sp)
/*    338fc:	a1280041 */ 	sb	$t0,0x41($t1)
/*    33900:	8faa005c */ 	lw	$t2,0x5c($sp)
/*    33904:	97ab006a */ 	lhu	$t3,0x6a($sp)
/*    33908:	854c0038 */ 	lh	$t4,0x38($t2)
/*    3390c:	016c0019 */ 	multu	$t3,$t4
/*    33910:	00006812 */ 	mflo	$t5
/*    33914:	000d73c2 */ 	srl	$t6,$t5,0xf
/*    33918:	a54e0038 */ 	sh	$t6,0x38($t2)
/*    3391c:	8faf005c */ 	lw	$t7,0x5c($sp)
/*    33920:	c7a60070 */ 	lwc1	$f6,0x70($sp)
/*    33924:	c5e4002c */ 	lwc1	$f4,0x2c($t7)
/*    33928:	46062202 */ 	mul.s	$f8,$f4,$f6
/*    3392c:	e5e8002c */ 	swc1	$f8,0x2c($t7)
/*    33930:	93b80077 */ 	lbu	$t8,0x77($sp)
/*    33934:	8fb9005c */ 	lw	$t9,0x5c($sp)
/*    33938:	a3380042 */ 	sb	$t8,0x42($t9)
/*    3393c:	93a8007b */ 	lbu	$t0,0x7b($sp)
/*    33940:	8fa9005c */ 	lw	$t1,0x5c($sp)
/*    33944:	a1280043 */ 	sb	$t0,0x43($t1)
/*    33948:	87ab0066 */ 	lh	$t3,0x66($sp)
/*    3394c:	8fac005c */ 	lw	$t4,0x5c($sp)
/*    33950:	a58b0046 */ 	sh	$t3,0x46($t4)
/*    33954:	8fad005c */ 	lw	$t5,0x5c($sp)
/*    33958:	ada00048 */ 	sw	$zero,0x48($t5)
/*    3395c:	8fae0050 */ 	lw	$t6,0x50($sp)
/*    33960:	8dca0004 */ 	lw	$t2,0x4($t6)
/*    33964:	914f0001 */ 	lbu	$t7,0x1($t2)
/*    33968:	000fc180 */ 	sll	$t8,$t7,0x6
/*    3396c:	030fc021 */ 	addu	$t8,$t8,$t7
/*    33970:	0018c0c0 */ 	sll	$t8,$t8,0x3
/*    33974:	030fc021 */ 	addu	$t8,$t8,$t7
/*    33978:	0018c080 */ 	sll	$t8,$t8,0x2
/*    3397c:	030fc023 */ 	subu	$t8,$t8,$t7
/*    33980:	0018c080 */ 	sll	$t8,$t8,0x2
/*    33984:	030fc021 */ 	addu	$t8,$t8,$t7
/*    33988:	0018c080 */ 	sll	$t8,$t8,0x2
/*    3398c:	030fc021 */ 	addu	$t8,$t8,$t7
/*    33990:	afb80044 */ 	sw	$t8,0x44($sp)
/*    33994:	8fb9005c */ 	lw	$t9,0x5c($sp)
/*    33998:	93280044 */ 	lbu	$t0,0x44($t9)
/*    3399c:	31090010 */ 	andi	$t1,$t0,0x10
/*    339a0:	11200014 */ 	beqz	$t1,.L000339f4
/*    339a4:	00000000 */ 	sll	$zero,$zero,0x0
/*    339a8:	8fab005c */ 	lw	$t3,0x5c($sp)
/*    339ac:	2401ffef */ 	addiu	$at,$zero,-17
/*    339b0:	916c0044 */ 	lbu	$t4,0x44($t3)
/*    339b4:	01816824 */ 	and	$t5,$t4,$at
/*    339b8:	a16d0044 */ 	sb	$t5,0x44($t3)
/*    339bc:	3c048006 */ 	lui	$a0,%hi(var80060014)
/*    339c0:	8c84f12c */ 	lw	$a0,-0xed4($a0)
/*    339c4:	8fa60040 */ 	lw	$a2,0x40($sp)
/*    339c8:	27a5002c */ 	addiu	$a1,$sp,0x2c
/*    339cc:	00003825 */ 	or	$a3,$zero,$zero
/*    339d0:	24840014 */ 	addiu	$a0,$a0,%lo(var80060014)
/*    339d4:	0c00f184 */ 	jal	func0003c610
/*    339d8:	24c60001 */ 	addiu	$a2,$a2,0x1
/*    339dc:	8fae0044 */ 	lw	$t6,0x44($sp)
/*    339e0:	25ca0001 */ 	addiu	$t2,$t6,0x1
/*    339e4:	afaa0048 */ 	sw	$t2,0x48($sp)
/*    339e8:	87af0066 */ 	lh	$t7,0x66($sp)
/*    339ec:	10000009 */ 	beqz	$zero,.L00033a14
/*    339f0:	a7af004e */ 	sh	$t7,0x4e($sp)
.L000339f4:
/*    339f4:	3c048006 */ 	lui	$a0,%hi(var80060014)
/*    339f8:	8c84f12c */ 	lw	$a0,-0xed4($a0)
/*    339fc:	8fa60044 */ 	lw	$a2,0x44($sp)
/*    33a00:	27a5002c */ 	addiu	$a1,$sp,0x2c
/*    33a04:	00003825 */ 	or	$a3,$zero,$zero
/*    33a08:	24840014 */ 	addiu	$a0,$a0,%lo(var80060014)
/*    33a0c:	0c00f184 */ 	jal	func0003c610
/*    33a10:	24c60001 */ 	addiu	$a2,$a2,0x1
.L00033a14:
/*    33a14:	8fb8005c */ 	lw	$t8,0x5c($sp)
/*    33a18:	afb80058 */ 	sw	$t8,0x58($sp)
.L00033a1c:
/*    33a1c:	8fb90040 */ 	lw	$t9,0x40($sp)
/*    33a20:	8fa80044 */ 	lw	$t0,0x44($sp)
/*    33a24:	03284821 */ 	addu	$t1,$t9,$t0
/*    33a28:	afa90040 */ 	sw	$t1,0x40($sp)
/*    33a2c:	8fac0050 */ 	lw	$t4,0x50($sp)
/*    33a30:	8d8d0004 */ 	lw	$t5,0x4($t4)
/*    33a34:	afad0054 */ 	sw	$t5,0x54($sp)
/*    33a38:	8fab0054 */ 	lw	$t3,0x54($sp)
/*    33a3c:	916a0002 */ 	lbu	$t2,0x2($t3)
/*    33a40:	916e0000 */ 	lbu	$t6,0x0($t3)
/*    33a44:	314f00c0 */ 	andi	$t7,$t2,0xc0
/*    33a48:	000fc080 */ 	sll	$t8,$t7,0x2
/*    33a4c:	01d8c821 */ 	addu	$t9,$t6,$t8
/*    33a50:	a7b90066 */ 	sh	$t9,0x66($sp)
/*    33a54:	87a80066 */ 	lh	$t0,0x66($sp)
/*    33a58:	11000004 */ 	beqz	$t0,.L00033a6c
/*    33a5c:	00000000 */ 	sll	$zero,$zero,0x0
/*    33a60:	8fa9005c */ 	lw	$t1,0x5c($sp)
/*    33a64:	1520ff80 */ 	bnez	$t1,.L00033868
/*    33a68:	00000000 */ 	sll	$zero,$zero,0x0
.L00033a6c:
/*    33a6c:	8fac0058 */ 	lw	$t4,0x58($sp)
/*    33a70:	1180001e */ 	beqz	$t4,.L00033aec
/*    33a74:	00000000 */ 	sll	$zero,$zero,0x0
/*    33a78:	8fad0058 */ 	lw	$t5,0x58($sp)
/*    33a7c:	91ab0044 */ 	lbu	$t3,0x44($t5)
/*    33a80:	356a0001 */ 	ori	$t2,$t3,0x1
/*    33a84:	a1aa0044 */ 	sb	$t2,0x44($t5)
/*    33a88:	8faf007c */ 	lw	$t7,0x7c($sp)
/*    33a8c:	8fae0058 */ 	lw	$t6,0x58($sp)
/*    33a90:	adcf0030 */ 	sw	$t7,0x30($t6)
/*    33a94:	87b8004e */ 	lh	$t8,0x4e($sp)
/*    33a98:	13000014 */ 	beqz	$t8,.L00033aec
/*    33a9c:	00000000 */ 	sll	$zero,$zero,0x0
/*    33aa0:	8fb90058 */ 	lw	$t9,0x58($sp)
/*    33aa4:	93280044 */ 	lbu	$t0,0x44($t9)
/*    33aa8:	35090010 */ 	ori	$t1,$t0,0x10
/*    33aac:	a3290044 */ 	sb	$t1,0x44($t9)
/*    33ab0:	240c0200 */ 	addiu	$t4,$zero,0x200
/*    33ab4:	a7ac001c */ 	sh	$t4,0x1c($sp)
/*    33ab8:	8fab0058 */ 	lw	$t3,0x58($sp)
/*    33abc:	afab0020 */ 	sw	$t3,0x20($sp)
/*    33ac0:	87aa004e */ 	lh	$t2,0x4e($sp)
/*    33ac4:	afaa0024 */ 	sw	$t2,0x24($sp)
/*    33ac8:	8fad0060 */ 	lw	$t5,0x60($sp)
/*    33acc:	afad0028 */ 	sw	$t5,0x28($sp)
/*    33ad0:	3c048006 */ 	lui	$a0,%hi(var80060014)
/*    33ad4:	8c84f12c */ 	lw	$a0,-0xed4($a0)
/*    33ad8:	27a5001c */ 	addiu	$a1,$sp,0x1c
/*    33adc:	8fa60048 */ 	lw	$a2,0x48($sp)
/*    33ae0:	00003825 */ 	or	$a3,$zero,$zero
/*    33ae4:	0c00f184 */ 	jal	func0003c610
/*    33ae8:	24840014 */ 	addiu	$a0,$a0,%lo(var80060014)
.L00033aec:
/*    33aec:	8faf007c */ 	lw	$t7,0x7c($sp)
/*    33af0:	11e00004 */ 	beqz	$t7,.L00033b04
/*    33af4:	00000000 */ 	sll	$zero,$zero,0x0
/*    33af8:	8fae0058 */ 	lw	$t6,0x58($sp)
/*    33afc:	8fb8007c */ 	lw	$t8,0x7c($sp)
/*    33b00:	af0e0000 */ 	sw	$t6,0x0($t8)
.L00033b04:
/*    33b04:	10000003 */ 	beqz	$zero,.L00033b14
/*    33b08:	8fa20058 */ 	lw	$v0,0x58($sp)
/*    33b0c:	10000001 */ 	beqz	$zero,.L00033b14
/*    33b10:	00000000 */ 	sll	$zero,$zero,0x0
.L00033b14:
/*    33b14:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    33b18:	27bd0060 */ 	addiu	$sp,$sp,0x60
/*    33b1c:	03e00008 */ 	jr	$ra
/*    33b20:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func00033b24
/*    33b24:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*    33b28:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    33b2c:	afa40028 */ 	sw	$a0,0x28($sp)
/*    33b30:	8fae0028 */ 	lw	$t6,0x28($sp)
/*    33b34:	11c00009 */ 	beqz	$t6,.L00033b5c
/*    33b38:	00000000 */ 	sll	$zero,$zero,0x0
/*    33b3c:	91cf0044 */ 	lbu	$t7,0x44($t6)
/*    33b40:	31f80002 */ 	andi	$t8,$t7,0x2
/*    33b44:	13000005 */ 	beqz	$t8,.L00033b5c
/*    33b48:	00000000 */ 	sll	$zero,$zero,0x0
/*    33b4c:	0c00cef0 */ 	jal	func00033bc0
/*    33b50:	8fa40028 */ 	lw	$a0,0x28($sp)
/*    33b54:	10000014 */ 	beqz	$zero,.L00033ba8
/*    33b58:	00000000 */ 	sll	$zero,$zero,0x0
.L00033b5c:
/*    33b5c:	24190400 */ 	addiu	$t9,$zero,0x400
/*    33b60:	a7b90018 */ 	sh	$t9,0x18($sp)
/*    33b64:	8fa80028 */ 	lw	$t0,0x28($sp)
/*    33b68:	afa8001c */ 	sw	$t0,0x1c($sp)
/*    33b6c:	8fa90028 */ 	lw	$t1,0x28($sp)
/*    33b70:	1120000d */ 	beqz	$t1,.L00033ba8
/*    33b74:	00000000 */ 	sll	$zero,$zero,0x0
/*    33b78:	8faa001c */ 	lw	$t2,0x1c($sp)
/*    33b7c:	2401ffef */ 	addiu	$at,$zero,-17
/*    33b80:	914b0044 */ 	lbu	$t3,0x44($t2)
/*    33b84:	01616024 */ 	and	$t4,$t3,$at
/*    33b88:	a14c0044 */ 	sb	$t4,0x44($t2)
/*    33b8c:	3c048006 */ 	lui	$a0,%hi(var80060014)
/*    33b90:	8c84f12c */ 	lw	$a0,-0xed4($a0)
/*    33b94:	27a50018 */ 	addiu	$a1,$sp,0x18
/*    33b98:	00003025 */ 	or	$a2,$zero,$zero
/*    33b9c:	00003825 */ 	or	$a3,$zero,$zero
/*    33ba0:	0c00f184 */ 	jal	func0003c610
/*    33ba4:	24840014 */ 	addiu	$a0,$a0,%lo(var80060014)
.L00033ba8:
/*    33ba8:	10000001 */ 	beqz	$zero,.L00033bb0
/*    33bac:	00000000 */ 	sll	$zero,$zero,0x0
.L00033bb0:
/*    33bb0:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    33bb4:	27bd0028 */ 	addiu	$sp,$sp,0x28
/*    33bb8:	03e00008 */ 	jr	$ra
/*    33bbc:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func00033bc0
/*    33bc0:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*    33bc4:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    33bc8:	afa40028 */ 	sw	$a0,0x28($sp)
/*    33bcc:	240e0080 */ 	addiu	$t6,$zero,0x80
/*    33bd0:	a7ae0018 */ 	sh	$t6,0x18($sp)
/*    33bd4:	8faf0028 */ 	lw	$t7,0x28($sp)
/*    33bd8:	afaf001c */ 	sw	$t7,0x1c($sp)
/*    33bdc:	8fb80028 */ 	lw	$t8,0x28($sp)
/*    33be0:	1300000d */ 	beqz	$t8,.L00033c18
/*    33be4:	00000000 */ 	sll	$zero,$zero,0x0
/*    33be8:	8fb9001c */ 	lw	$t9,0x1c($sp)
/*    33bec:	2401ffef */ 	addiu	$at,$zero,-17
/*    33bf0:	93280044 */ 	lbu	$t0,0x44($t9)
/*    33bf4:	01014824 */ 	and	$t1,$t0,$at
/*    33bf8:	a3290044 */ 	sb	$t1,0x44($t9)
/*    33bfc:	3c048006 */ 	lui	$a0,%hi(var80060014)
/*    33c00:	8c84f12c */ 	lw	$a0,-0xed4($a0)
/*    33c04:	27a50018 */ 	addiu	$a1,$sp,0x18
/*    33c08:	00003025 */ 	or	$a2,$zero,$zero
/*    33c0c:	00003825 */ 	or	$a3,$zero,$zero
/*    33c10:	0c00f184 */ 	jal	func0003c610
/*    33c14:	24840014 */ 	addiu	$a0,$a0,%lo(var80060014)
.L00033c18:
/*    33c18:	10000001 */ 	beqz	$zero,.L00033c20
/*    33c1c:	00000000 */ 	sll	$zero,$zero,0x0
.L00033c20:
/*    33c20:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    33c24:	27bd0028 */ 	addiu	$sp,$sp,0x28
/*    33c28:	03e00008 */ 	jr	$ra
/*    33c2c:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func00033c30
/*    33c30:	27bdffd0 */ 	addiu	$sp,$sp,-48
/*    33c34:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    33c38:	afa40030 */ 	sw	$a0,0x30($sp)
/*    33c3c:	0c012194 */ 	jal	func00048650
/*    33c40:	24040001 */ 	addiu	$a0,$zero,0x1
/*    33c44:	afa2002c */ 	sw	$v0,0x2c($sp)
/*    33c48:	3c0e8006 */ 	lui	$t6,0x8006
/*    33c4c:	8dcef120 */ 	lw	$t6,-0xee0($t6)
/*    33c50:	afae0018 */ 	sw	$t6,0x18($sp)
/*    33c54:	8faf0018 */ 	lw	$t7,0x18($sp)
/*    33c58:	11e0001d */ 	beqz	$t7,.L00033cd0
/*    33c5c:	00000000 */ 	sll	$zero,$zero,0x0
.L00033c60:
/*    33c60:	24180400 */ 	addiu	$t8,$zero,0x400
/*    33c64:	a7b8001c */ 	sh	$t8,0x1c($sp)
/*    33c68:	8fb90018 */ 	lw	$t9,0x18($sp)
/*    33c6c:	afb90020 */ 	sw	$t9,0x20($sp)
/*    33c70:	8fa80018 */ 	lw	$t0,0x18($sp)
/*    33c74:	93aa0033 */ 	lbu	$t2,0x33($sp)
/*    33c78:	91090044 */ 	lbu	$t1,0x44($t0)
/*    33c7c:	012a5824 */ 	and	$t3,$t1,$t2
/*    33c80:	156a000d */ 	bne	$t3,$t2,.L00033cb8
/*    33c84:	00000000 */ 	sll	$zero,$zero,0x0
/*    33c88:	8fac0020 */ 	lw	$t4,0x20($sp)
/*    33c8c:	2401ffef */ 	addiu	$at,$zero,-17
/*    33c90:	918d0044 */ 	lbu	$t5,0x44($t4)
/*    33c94:	01a17024 */ 	and	$t6,$t5,$at
/*    33c98:	a18e0044 */ 	sb	$t6,0x44($t4)
/*    33c9c:	3c048006 */ 	lui	$a0,%hi(var80060014)
/*    33ca0:	8c84f12c */ 	lw	$a0,-0xed4($a0)
/*    33ca4:	27a5001c */ 	addiu	$a1,$sp,0x1c
/*    33ca8:	00003025 */ 	or	$a2,$zero,$zero
/*    33cac:	00003825 */ 	or	$a3,$zero,$zero
/*    33cb0:	0c00f184 */ 	jal	func0003c610
/*    33cb4:	24840014 */ 	addiu	$a0,$a0,%lo(var80060014)
.L00033cb8:
/*    33cb8:	8faf0018 */ 	lw	$t7,0x18($sp)
/*    33cbc:	8df80000 */ 	lw	$t8,0x0($t7)
/*    33cc0:	afb80018 */ 	sw	$t8,0x18($sp)
/*    33cc4:	8fb90018 */ 	lw	$t9,0x18($sp)
/*    33cc8:	1720ffe5 */ 	bnez	$t9,.L00033c60
/*    33ccc:	00000000 */ 	sll	$zero,$zero,0x0
.L00033cd0:
/*    33cd0:	0c012194 */ 	jal	func00048650
/*    33cd4:	8fa4002c */ 	lw	$a0,0x2c($sp)
/*    33cd8:	10000001 */ 	beqz	$zero,.L00033ce0
/*    33cdc:	00000000 */ 	sll	$zero,$zero,0x0
.L00033ce0:
/*    33ce0:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    33ce4:	27bd0030 */ 	addiu	$sp,$sp,0x30
/*    33ce8:	03e00008 */ 	jr	$ra
/*    33cec:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func00033cf0
/*    33cf0:	27bdffd0 */ 	addiu	$sp,$sp,-48
/*    33cf4:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    33cf8:	afa40030 */ 	sw	$a0,0x30($sp)
/*    33cfc:	0c012194 */ 	jal	func00048650
/*    33d00:	24040001 */ 	addiu	$a0,$zero,0x1
/*    33d04:	afa2002c */ 	sw	$v0,0x2c($sp)
/*    33d08:	3c0e8006 */ 	lui	$t6,0x8006
/*    33d0c:	8dcef120 */ 	lw	$t6,-0xee0($t6)
/*    33d10:	afae0018 */ 	sw	$t6,0x18($sp)
/*    33d14:	8faf0018 */ 	lw	$t7,0x18($sp)
/*    33d18:	11e0001d */ 	beqz	$t7,.L00033d90
/*    33d1c:	00000000 */ 	sll	$zero,$zero,0x0
.L00033d20:
/*    33d20:	24180080 */ 	addiu	$t8,$zero,0x80
/*    33d24:	a7b8001c */ 	sh	$t8,0x1c($sp)
/*    33d28:	8fb90018 */ 	lw	$t9,0x18($sp)
/*    33d2c:	afb90020 */ 	sw	$t9,0x20($sp)
/*    33d30:	8fa80018 */ 	lw	$t0,0x18($sp)
/*    33d34:	93aa0033 */ 	lbu	$t2,0x33($sp)
/*    33d38:	91090044 */ 	lbu	$t1,0x44($t0)
/*    33d3c:	012a5824 */ 	and	$t3,$t1,$t2
/*    33d40:	156a000d */ 	bne	$t3,$t2,.L00033d78
/*    33d44:	00000000 */ 	sll	$zero,$zero,0x0
/*    33d48:	8fac0020 */ 	lw	$t4,0x20($sp)
/*    33d4c:	2401ffef */ 	addiu	$at,$zero,-17
/*    33d50:	918d0044 */ 	lbu	$t5,0x44($t4)
/*    33d54:	01a17024 */ 	and	$t6,$t5,$at
/*    33d58:	a18e0044 */ 	sb	$t6,0x44($t4)
/*    33d5c:	3c048006 */ 	lui	$a0,%hi(var80060014)
/*    33d60:	8c84f12c */ 	lw	$a0,-0xed4($a0)
/*    33d64:	27a5001c */ 	addiu	$a1,$sp,0x1c
/*    33d68:	00003025 */ 	or	$a2,$zero,$zero
/*    33d6c:	00003825 */ 	or	$a3,$zero,$zero
/*    33d70:	0c00f184 */ 	jal	func0003c610
/*    33d74:	24840014 */ 	addiu	$a0,$a0,%lo(var80060014)
.L00033d78:
/*    33d78:	8faf0018 */ 	lw	$t7,0x18($sp)
/*    33d7c:	8df80000 */ 	lw	$t8,0x0($t7)
/*    33d80:	afb80018 */ 	sw	$t8,0x18($sp)
/*    33d84:	8fb90018 */ 	lw	$t9,0x18($sp)
/*    33d88:	1720ffe5 */ 	bnez	$t9,.L00033d20
/*    33d8c:	00000000 */ 	sll	$zero,$zero,0x0
.L00033d90:
/*    33d90:	0c012194 */ 	jal	func00048650
/*    33d94:	8fa4002c */ 	lw	$a0,0x2c($sp)
/*    33d98:	10000001 */ 	beqz	$zero,.L00033da0
/*    33d9c:	00000000 */ 	sll	$zero,$zero,0x0
.L00033da0:
/*    33da0:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    33da4:	27bd0030 */ 	addiu	$sp,$sp,0x30
/*    33da8:	03e00008 */ 	jr	$ra
/*    33dac:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func00033db0
/*    33db0:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*    33db4:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    33db8:	0c00cf3c */ 	jal	func00033cf0
/*    33dbc:	24040001 */ 	addiu	$a0,$zero,0x1
/*    33dc0:	10000001 */ 	beqz	$zero,.L00033dc8
/*    33dc4:	00000000 */ 	sll	$zero,$zero,0x0
.L00033dc8:
/*    33dc8:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    33dcc:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*    33dd0:	03e00008 */ 	jr	$ra
/*    33dd4:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func00033dd8
/*    33dd8:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*    33ddc:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    33de0:	0c00cf0c */ 	jal	func00033c30
/*    33de4:	24040001 */ 	addiu	$a0,$zero,0x1
/*    33de8:	10000001 */ 	beqz	$zero,.L00033df0
/*    33dec:	00000000 */ 	sll	$zero,$zero,0x0
.L00033df0:
/*    33df0:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    33df4:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*    33df8:	03e00008 */ 	jr	$ra
/*    33dfc:	00000000 */ 	sll	$zero,$zero,0x0
/*    33e00:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*    33e04:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    33e08:	0c00cf0c */ 	jal	func00033c30
/*    33e0c:	24040011 */ 	addiu	$a0,$zero,0x11
/*    33e10:	10000001 */ 	beqz	$zero,.L00033e18
/*    33e14:	00000000 */ 	sll	$zero,$zero,0x0
.L00033e18:
/*    33e18:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    33e1c:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*    33e20:	03e00008 */ 	jr	$ra
/*    33e24:	00000000 */ 	sll	$zero,$zero,0x0
/*    33e28:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*    33e2c:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    33e30:	0c00cf0c */ 	jal	func00033c30
/*    33e34:	24040003 */ 	addiu	$a0,$zero,0x3
/*    33e38:	10000001 */ 	beqz	$zero,.L00033e40
/*    33e3c:	00000000 */ 	sll	$zero,$zero,0x0
.L00033e40:
/*    33e40:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    33e44:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*    33e48:	03e00008 */ 	jr	$ra
/*    33e4c:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func00033e50
/*    33e50:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*    33e54:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    33e58:	afa40028 */ 	sw	$a0,0x28($sp)
/*    33e5c:	afa5002c */ 	sw	$a1,0x2c($sp)
/*    33e60:	afa60030 */ 	sw	$a2,0x30($sp)
/*    33e64:	87ae002e */ 	lh	$t6,0x2e($sp)
/*    33e68:	a7ae0018 */ 	sh	$t6,0x18($sp)
/*    33e6c:	8faf0028 */ 	lw	$t7,0x28($sp)
/*    33e70:	afaf001c */ 	sw	$t7,0x1c($sp)
/*    33e74:	8fb80030 */ 	lw	$t8,0x30($sp)
/*    33e78:	afb80020 */ 	sw	$t8,0x20($sp)
/*    33e7c:	8fb90028 */ 	lw	$t9,0x28($sp)
/*    33e80:	1320000a */ 	beqz	$t9,.L00033eac
/*    33e84:	00000000 */ 	sll	$zero,$zero,0x0
/*    33e88:	3c048006 */ 	lui	$a0,%hi(var80060014)
/*    33e8c:	8c84f12c */ 	lw	$a0,-0xed4($a0)
/*    33e90:	27a50018 */ 	addiu	$a1,$sp,0x18
/*    33e94:	00003025 */ 	or	$a2,$zero,$zero
/*    33e98:	00003825 */ 	or	$a3,$zero,$zero
/*    33e9c:	0c00f184 */ 	jal	func0003c610
/*    33ea0:	24840014 */ 	addiu	$a0,$a0,%lo(var80060014)
/*    33ea4:	10000001 */ 	beqz	$zero,.L00033eac
/*    33ea8:	00000000 */ 	sll	$zero,$zero,0x0
.L00033eac:
/*    33eac:	10000001 */ 	beqz	$zero,.L00033eb4
/*    33eb0:	00000000 */ 	sll	$zero,$zero,0x0
.L00033eb4:
/*    33eb4:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    33eb8:	27bd0028 */ 	addiu	$sp,$sp,0x28
/*    33ebc:	03e00008 */ 	jr	$ra
/*    33ec0:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func00033ec4
/*    33ec4:	27bdfff8 */ 	addiu	$sp,$sp,-8
/*    33ec8:	308400ff */ 	andi	$a0,$a0,0xff
/*    33ecc:	3c0e800a */ 	lui	$t6,0x800a
/*    33ed0:	8dcec334 */ 	lw	$t6,-0x3ccc($t6)
/*    33ed4:	11c00005 */ 	beqz	$t6,.L00033eec
/*    33ed8:	00000000 */ 	sll	$zero,$zero,0x0
/*    33edc:	00047840 */ 	sll	$t7,$a0,0x1
/*    33ee0:	01cfc021 */ 	addu	$t8,$t6,$t7
/*    33ee4:	10000002 */ 	beqz	$zero,.L00033ef0
/*    33ee8:	87050000 */ 	lh	$a1,0x0($t8)
.L00033eec:
/*    33eec:	00002825 */ 	or	$a1,$zero,$zero
.L00033ef0:
/*    33ef0:	10000003 */ 	beqz	$zero,.L00033f00
/*    33ef4:	30a2ffff */ 	andi	$v0,$a1,0xffff
/*    33ef8:	10000001 */ 	beqz	$zero,.L00033f00
/*    33efc:	00000000 */ 	sll	$zero,$zero,0x0
.L00033f00:
/*    33f00:	03e00008 */ 	jr	$ra
/*    33f04:	27bd0008 */ 	addiu	$sp,$sp,0x8
);

GLOBAL_ASM(
glabel func00033f08
/*    33f08:	3c028006 */ 	lui	$v0,0x8006
/*    33f0c:	03e00008 */ 	jr	$ra
/*    33f10:	8c42f120 */ 	lw	$v0,-0xee0($v0)
/*    33f14:	03e00008 */ 	jr	$ra
/*    33f18:	00000000 */ 	sll	$zero,$zero,0x0
/*    33f1c:	03e00008 */ 	jr	$ra
/*    33f20:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func00033f24
/*    33f24:	3c0e8006 */ 	lui	$t6,0x8006
/*    33f28:	8dcef12c */ 	lw	$t6,-0xed4($t6)
/*    33f2c:	03e00008 */ 	jr	$ra
/*    33f30:	8dc20050 */ 	lw	$v0,0x50($t6)
/*    33f34:	03e00008 */ 	jr	$ra
/*    33f38:	00000000 */ 	sll	$zero,$zero,0x0
/*    33f3c:	03e00008 */ 	jr	$ra
/*    33f40:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func00033f44
/*    33f44:	27bdffc8 */ 	addiu	$sp,$sp,-56
/*    33f48:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    33f4c:	afa40038 */ 	sw	$a0,0x38($sp)
/*    33f50:	afa5003c */ 	sw	$a1,0x3c($sp)
/*    33f54:	3c0e800a */ 	lui	$t6,0x800a
/*    33f58:	8dcec334 */ 	lw	$t6,-0x3ccc($t6)
/*    33f5c:	11c0002e */ 	beqz	$t6,.L00034018
/*    33f60:	00000000 */ 	sll	$zero,$zero,0x0
/*    33f64:	0c012194 */ 	jal	func00048650
/*    33f68:	24040001 */ 	addiu	$a0,$zero,0x1
/*    33f6c:	afa20034 */ 	sw	$v0,0x34($sp)
/*    33f70:	3c0f8006 */ 	lui	$t7,0x8006
/*    33f74:	8deff120 */ 	lw	$t7,-0xee0($t7)
/*    33f78:	afaf0030 */ 	sw	$t7,0x30($sp)
/*    33f7c:	93a8003b */ 	lbu	$t0,0x3b($sp)
/*    33f80:	3c19800a */ 	lui	$t9,0x800a
/*    33f84:	8f39c334 */ 	lw	$t9,-0x3ccc($t9)
/*    33f88:	97b8003e */ 	lhu	$t8,0x3e($sp)
/*    33f8c:	00084840 */ 	sll	$t1,$t0,0x1
/*    33f90:	03295021 */ 	addu	$t2,$t9,$t1
/*    33f94:	a5580000 */ 	sh	$t8,0x0($t2)
/*    33f98:	8fab0030 */ 	lw	$t3,0x30($sp)
/*    33f9c:	afa0002c */ 	sw	$zero,0x2c($sp)
/*    33fa0:	1160001b */ 	beqz	$t3,.L00034010
/*    33fa4:	00000000 */ 	sll	$zero,$zero,0x0
.L00033fa8:
/*    33fa8:	8fac0030 */ 	lw	$t4,0x30($sp)
/*    33fac:	93b9003b */ 	lbu	$t9,0x3b($sp)
/*    33fb0:	8d8d0008 */ 	lw	$t5,0x8($t4)
/*    33fb4:	8dae0004 */ 	lw	$t6,0x4($t5)
/*    33fb8:	91cf0002 */ 	lbu	$t7,0x2($t6)
/*    33fbc:	31e8001f */ 	andi	$t0,$t7,0x1f
/*    33fc0:	1519000c */ 	bne	$t0,$t9,.L00033ff4
/*    33fc4:	00000000 */ 	sll	$zero,$zero,0x0
/*    33fc8:	24090800 */ 	addiu	$t1,$zero,0x800
/*    33fcc:	a7a9001c */ 	sh	$t1,0x1c($sp)
/*    33fd0:	8fb80030 */ 	lw	$t8,0x30($sp)
/*    33fd4:	afb80020 */ 	sw	$t8,0x20($sp)
/*    33fd8:	3c048006 */ 	lui	$a0,%hi(var80060014)
/*    33fdc:	8c84f12c */ 	lw	$a0,-0xed4($a0)
/*    33fe0:	27a5001c */ 	addiu	$a1,$sp,0x1c
/*    33fe4:	00003025 */ 	or	$a2,$zero,$zero
/*    33fe8:	00003825 */ 	or	$a3,$zero,$zero
/*    33fec:	0c00f184 */ 	jal	func0003c610
/*    33ff0:	24840014 */ 	addiu	$a0,$a0,%lo(var80060014)
.L00033ff4:
/*    33ff4:	8faa002c */ 	lw	$t2,0x2c($sp)
/*    33ff8:	8fac0030 */ 	lw	$t4,0x30($sp)
/*    33ffc:	254b0001 */ 	addiu	$t3,$t2,0x1
/*    34000:	afab002c */ 	sw	$t3,0x2c($sp)
/*    34004:	8d8d0000 */ 	lw	$t5,0x0($t4)
/*    34008:	15a0ffe7 */ 	bnez	$t5,.L00033fa8
/*    3400c:	afad0030 */ 	sw	$t5,0x30($sp)
.L00034010:
/*    34010:	0c012194 */ 	jal	func00048650
/*    34014:	8fa40034 */ 	lw	$a0,0x34($sp)
.L00034018:
/*    34018:	10000001 */ 	beqz	$zero,.L00034020
/*    3401c:	00000000 */ 	sll	$zero,$zero,0x0
.L00034020:
/*    34020:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    34024:	27bd0038 */ 	addiu	$sp,$sp,0x38
/*    34028:	03e00008 */ 	jr	$ra
/*    3402c:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func00034030
/*    34030:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*    34034:	afbf001c */ 	sw	$ra,0x1c($sp)
/*    34038:	afa40028 */ 	sw	$a0,0x28($sp)
/*    3403c:	afb00018 */ 	sw	$s0,0x18($sp)
/*    34040:	3c01800a */ 	lui	$at,0x800a
/*    34044:	a020c340 */ 	sb	$zero,-0x3cc0($at)
/*    34048:	3c01800a */ 	lui	$at,0x800a
/*    3404c:	a020c341 */ 	sb	$zero,-0x3cbf($at)
/*    34050:	3c01800a */ 	lui	$at,0x800a
/*    34054:	a020c342 */ 	sb	$zero,-0x3cbe($at)
/*    34058:	93b0002b */ 	lbu	$s0,0x2b($sp)
/*    3405c:	24010001 */ 	addiu	$at,$zero,0x1
/*    34060:	12010009 */ 	beq	$s0,$at,.L00034088
/*    34064:	00000000 */ 	sll	$zero,$zero,0x0
/*    34068:	24010003 */ 	addiu	$at,$zero,0x3
/*    3406c:	1201000b */ 	beq	$s0,$at,.L0003409c
/*    34070:	00000000 */ 	sll	$zero,$zero,0x0
/*    34074:	24010004 */ 	addiu	$at,$zero,0x4
/*    34078:	1201000d */ 	beq	$s0,$at,.L000340b0
/*    3407c:	00000000 */ 	sll	$zero,$zero,0x0
/*    34080:	10000010 */ 	beqz	$zero,.L000340c4
/*    34084:	00000000 */ 	sll	$zero,$zero,0x0
.L00034088:
/*    34088:	240e0001 */ 	addiu	$t6,$zero,0x1
/*    3408c:	3c01800a */ 	lui	$at,0x800a
/*    34090:	a02ec341 */ 	sb	$t6,-0x3cbf($at)
/*    34094:	1000000b */ 	beqz	$zero,.L000340c4
/*    34098:	00000000 */ 	sll	$zero,$zero,0x0
.L0003409c:
/*    3409c:	240f0001 */ 	addiu	$t7,$zero,0x1
/*    340a0:	3c01800a */ 	lui	$at,0x800a
/*    340a4:	a02fc342 */ 	sb	$t7,-0x3cbe($at)
/*    340a8:	10000006 */ 	beqz	$zero,.L000340c4
/*    340ac:	00000000 */ 	sll	$zero,$zero,0x0
.L000340b0:
/*    340b0:	24180001 */ 	addiu	$t8,$zero,0x1
/*    340b4:	3c01800a */ 	lui	$at,0x800a
/*    340b8:	a038c340 */ 	sb	$t8,-0x3cc0($at)
/*    340bc:	10000001 */ 	beqz	$zero,.L000340c4
/*    340c0:	00000000 */ 	sll	$zero,$zero,0x0
.L000340c4:
/*    340c4:	afa00024 */ 	sw	$zero,0x24($sp)
.L000340c8:
/*    340c8:	8fa40024 */ 	lw	$a0,0x24($sp)
/*    340cc:	0c00d041 */ 	jal	func00034104
/*    340d0:	00002825 */ 	or	$a1,$zero,$zero
/*    340d4:	8fb90024 */ 	lw	$t9,0x24($sp)
/*    340d8:	27280001 */ 	addiu	$t0,$t9,0x1
/*    340dc:	29010002 */ 	slti	$at,$t0,0x2
/*    340e0:	1420fff9 */ 	bnez	$at,.L000340c8
/*    340e4:	afa80024 */ 	sw	$t0,0x24($sp)
/*    340e8:	10000001 */ 	beqz	$zero,.L000340f0
/*    340ec:	00000000 */ 	sll	$zero,$zero,0x0
.L000340f0:
/*    340f0:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*    340f4:	8fb00018 */ 	lw	$s0,0x18($sp)
/*    340f8:	27bd0028 */ 	addiu	$sp,$sp,0x28
/*    340fc:	03e00008 */ 	jr	$ra
/*    34100:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func00034104
/*    34104:	27bdfff8 */ 	addiu	$sp,$sp,-8
/*    34108:	14a00004 */ 	bnez	$a1,.L0003411c
/*    3410c:	00000000 */ 	sll	$zero,$zero,0x0
/*    34110:	3c05800a */ 	lui	$a1,0x800a
/*    34114:	00a42821 */ 	addu	$a1,$a1,$a0
/*    34118:	90a5c348 */ 	lbu	$a1,-0x3cb8($a1)
.L0003411c:
/*    3411c:	3c01800a */ 	lui	$at,0x800a
/*    34120:	00240821 */ 	addu	$at,$at,$a0
/*    34124:	a020c344 */ 	sb	$zero,-0x3cbc($at)
/*    34128:	3c01800a */ 	lui	$at,0x800a
/*    3412c:	00240821 */ 	addu	$at,$at,$a0
/*    34130:	a020c346 */ 	sb	$zero,-0x3cba($at)
/*    34134:	00a03025 */ 	or	$a2,$a1,$zero
/*    34138:	24010002 */ 	addiu	$at,$zero,0x2
/*    3413c:	10c1000c */ 	beq	$a2,$at,.L00034170
/*    34140:	00000000 */ 	sll	$zero,$zero,0x0
/*    34144:	24010003 */ 	addiu	$at,$zero,0x3
/*    34148:	10c10013 */ 	beq	$a2,$at,.L00034198
/*    3414c:	00000000 */ 	sll	$zero,$zero,0x0
/*    34150:	24010004 */ 	addiu	$at,$zero,0x4
/*    34154:	10c1001a */ 	beq	$a2,$at,.L000341c0
/*    34158:	00000000 */ 	sll	$zero,$zero,0x0
/*    3415c:	24010005 */ 	addiu	$at,$zero,0x5
/*    34160:	10c10021 */ 	beq	$a2,$at,.L000341e8
/*    34164:	00000000 */ 	sll	$zero,$zero,0x0
/*    34168:	1000002d */ 	beqz	$zero,.L00034220
/*    3416c:	00000000 */ 	sll	$zero,$zero,0x0
.L00034170:
/*    34170:	3c0e800a */ 	lui	$t6,0x800a
/*    34174:	91cec340 */ 	lbu	$t6,-0x3cc0($t6)
/*    34178:	11c00005 */ 	beqz	$t6,.L00034190
/*    3417c:	00000000 */ 	sll	$zero,$zero,0x0
/*    34180:	3c01800a */ 	lui	$at,0x800a
/*    34184:	00240821 */ 	addu	$at,$at,$a0
/*    34188:	240f0001 */ 	addiu	$t7,$zero,0x1
/*    3418c:	a02fc346 */ 	sb	$t7,-0x3cba($at)
.L00034190:
/*    34190:	10000023 */ 	beqz	$zero,.L00034220
/*    34194:	00000000 */ 	sll	$zero,$zero,0x0
.L00034198:
/*    34198:	3c18800a */ 	lui	$t8,0x800a
/*    3419c:	9318c340 */ 	lbu	$t8,-0x3cc0($t8)
/*    341a0:	13000005 */ 	beqz	$t8,.L000341b8
/*    341a4:	00000000 */ 	sll	$zero,$zero,0x0
/*    341a8:	3c01800a */ 	lui	$at,0x800a
/*    341ac:	00240821 */ 	addu	$at,$at,$a0
/*    341b0:	24190001 */ 	addiu	$t9,$zero,0x1
/*    341b4:	a039c344 */ 	sb	$t9,-0x3cbc($at)
.L000341b8:
/*    341b8:	10000019 */ 	beqz	$zero,.L00034220
/*    341bc:	00000000 */ 	sll	$zero,$zero,0x0
.L000341c0:
/*    341c0:	3c08800a */ 	lui	$t0,0x800a
/*    341c4:	9108c341 */ 	lbu	$t0,-0x3cbf($t0)
/*    341c8:	15000005 */ 	bnez	$t0,.L000341e0
/*    341cc:	00000000 */ 	sll	$zero,$zero,0x0
/*    341d0:	3c01800a */ 	lui	$at,0x800a
/*    341d4:	00240821 */ 	addu	$at,$at,$a0
/*    341d8:	24090001 */ 	addiu	$t1,$zero,0x1
/*    341dc:	a029c344 */ 	sb	$t1,-0x3cbc($at)
.L000341e0:
/*    341e0:	1000000f */ 	beqz	$zero,.L00034220
/*    341e4:	00000000 */ 	sll	$zero,$zero,0x0
.L000341e8:
/*    341e8:	3c0a800a */ 	lui	$t2,0x800a
/*    341ec:	914ac341 */ 	lbu	$t2,-0x3cbf($t2)
/*    341f0:	15400009 */ 	bnez	$t2,.L00034218
/*    341f4:	00000000 */ 	sll	$zero,$zero,0x0
/*    341f8:	3c01800a */ 	lui	$at,0x800a
/*    341fc:	00240821 */ 	addu	$at,$at,$a0
/*    34200:	240b0001 */ 	addiu	$t3,$zero,0x1
/*    34204:	a02bc344 */ 	sb	$t3,-0x3cbc($at)
/*    34208:	3c01800a */ 	lui	$at,0x800a
/*    3420c:	00240821 */ 	addu	$at,$at,$a0
/*    34210:	240c0001 */ 	addiu	$t4,$zero,0x1
/*    34214:	a02cc346 */ 	sb	$t4,-0x3cba($at)
.L00034218:
/*    34218:	10000001 */ 	beqz	$zero,.L00034220
/*    3421c:	00000000 */ 	sll	$zero,$zero,0x0
.L00034220:
/*    34220:	3c01800a */ 	lui	$at,0x800a
/*    34224:	00240821 */ 	addu	$at,$at,$a0
/*    34228:	a025c348 */ 	sb	$a1,-0x3cb8($at)
/*    3422c:	10000001 */ 	beqz	$zero,.L00034234
/*    34230:	00000000 */ 	sll	$zero,$zero,0x0
.L00034234:
/*    34234:	03e00008 */ 	jr	$ra
/*    34238:	27bd0008 */ 	addiu	$sp,$sp,0x8
/*    3423c:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func00034240
/*    34240:	27bdffc8 */ 	addiu	$sp,$sp,-56
/*    34244:	afbf001c */ 	sw	$ra,0x1c($sp)
/*    34248:	afa40038 */ 	sw	$a0,0x38($sp)
/*    3424c:	afa5003c */ 	sw	$a1,0x3c($sp)
/*    34250:	8fae003c */ 	lw	$t6,0x3c($sp)
/*    34254:	8dcf000c */ 	lw	$t7,0xc($t6)
/*    34258:	afaf0024 */ 	sw	$t7,0x24($sp)
/*    3425c:	8fb80038 */ 	lw	$t8,0x38($sp)
/*    34260:	af000020 */ 	sw	$zero,0x20($t8)
/*    34264:	8fb90038 */ 	lw	$t9,0x38($sp)
/*    34268:	af200018 */ 	sw	$zero,0x18($t9)
/*    3426c:	3c088006 */ 	lui	$t0,0x8006
/*    34270:	8d08f114 */ 	lw	$t0,-0xeec($t0)
/*    34274:	8fa90038 */ 	lw	$t1,0x38($sp)
/*    34278:	ad280014 */ 	sw	$t0,0x14($t1)
/*    3427c:	8fab0038 */ 	lw	$t3,0x38($sp)
/*    34280:	340affff */ 	dli	$t2,0xffff
/*    34284:	a56a0030 */ 	sh	$t2,0x30($t3)
/*    34288:	0c00e734 */ 	jal	func00039cd0
/*    3428c:	8fa40038 */ 	lw	$a0,0x38($sp)
/*    34290:	8fad0038 */ 	lw	$t5,0x38($sp)
/*    34294:	240c01e8 */ 	addiu	$t4,$zero,0x1e8
/*    34298:	adac0024 */ 	sw	$t4,0x24($t5)
/*    3429c:	8fae0038 */ 	lw	$t6,0x38($sp)
/*    342a0:	adc00028 */ 	sw	$zero,0x28($t6)
/*    342a4:	8faf0038 */ 	lw	$t7,0x38($sp)
/*    342a8:	ade0002c */ 	sw	$zero,0x2c($t7)
/*    342ac:	8fb90038 */ 	lw	$t9,0x38($sp)
/*    342b0:	24187fff */ 	addiu	$t8,$zero,0x7fff
/*    342b4:	a7380032 */ 	sh	$t8,0x32($t9)
/*    342b8:	8fa8003c */ 	lw	$t0,0x3c($sp)
/*    342bc:	8faa0038 */ 	lw	$t2,0x38($sp)
/*    342c0:	91090009 */ 	lbu	$t1,0x9($t0)
/*    342c4:	a1490035 */ 	sb	$t1,0x35($t2)
/*    342c8:	8fac0038 */ 	lw	$t4,0x38($sp)
/*    342cc:	240b3e80 */ 	addiu	$t3,$zero,0x3e80
/*    342d0:	ad8b005c */ 	sw	$t3,0x5c($t4)
/*    342d4:	8fad0038 */ 	lw	$t5,0x38($sp)
/*    342d8:	ada0001c */ 	sw	$zero,0x1c($t5)
/*    342dc:	8fae003c */ 	lw	$t6,0x3c($sp)
/*    342e0:	8fb80038 */ 	lw	$t8,0x38($sp)
/*    342e4:	8dcf0010 */ 	lw	$t7,0x10($t6)
/*    342e8:	af0f0070 */ 	sw	$t7,0x70($t8)
/*    342ec:	8fb9003c */ 	lw	$t9,0x3c($sp)
/*    342f0:	8fa90038 */ 	lw	$t1,0x38($sp)
/*    342f4:	8f280014 */ 	lw	$t0,0x14($t9)
/*    342f8:	ad280074 */ 	sw	$t0,0x74($t1)
/*    342fc:	8faa003c */ 	lw	$t2,0x3c($sp)
/*    34300:	8fac0038 */ 	lw	$t4,0x38($sp)
/*    34304:	8d4b0018 */ 	lw	$t3,0x18($t2)
/*    34308:	ad8b0078 */ 	sw	$t3,0x78($t4)
/*    3430c:	44802000 */ 	mtc1	$zero,$f4
/*    34310:	8fad0038 */ 	lw	$t5,0x38($sp)
/*    34314:	e5a4007c */ 	swc1	$f4,0x7c($t5)
/*    34318:	3c013f80 */ 	lui	$at,0x3f80
/*    3431c:	44813000 */ 	mtc1	$at,$f6
/*    34320:	8fae0038 */ 	lw	$t6,0x38($sp)
/*    34324:	e5c60080 */ 	swc1	$f6,0x80($t6)
/*    34328:	8faf0038 */ 	lw	$t7,0x38($sp)
/*    3432c:	ade00084 */ 	sw	$zero,0x84($t7)
/*    34330:	8fb80038 */ 	lw	$t8,0x38($sp)
/*    34334:	a3000089 */ 	sb	$zero,0x89($t8)
/*    34338:	8fb9003c */ 	lw	$t9,0x3c($sp)
/*    3433c:	8fa90038 */ 	lw	$t1,0x38($sp)
/*    34340:	8f280000 */ 	lw	$t0,0x0($t9)
/*    34344:	a1280088 */ 	sb	$t0,0x88($t1)
/*    34348:	8fab0038 */ 	lw	$t3,0x38($sp)
/*    3434c:	240a0009 */ 	addiu	$t2,$zero,0x9
/*    34350:	a56a0038 */ 	sh	$t2,0x38($t3)
/*    34354:	8fac003c */ 	lw	$t4,0x3c($sp)
/*    34358:	8fae0038 */ 	lw	$t6,0x38($sp)
/*    3435c:	918d0008 */ 	lbu	$t5,0x8($t4)
/*    34360:	a1cd0034 */ 	sb	$t5,0x34($t6)
/*    34364:	8faf003c */ 	lw	$t7,0x3c($sp)
/*    34368:	24180034 */ 	addiu	$t8,$zero,0x34
/*    3436c:	00002025 */ 	or	$a0,$zero,$zero
/*    34370:	91e70008 */ 	lbu	$a3,0x8($t7)
/*    34374:	afb80010 */ 	sw	$t8,0x10($sp)
/*    34378:	00002825 */ 	or	$a1,$zero,$zero
/*    3437c:	0c00bec5 */ 	jal	func0002fb14
/*    34380:	8fa60024 */ 	lw	$a2,0x24($sp)
/*    34384:	8fb90038 */ 	lw	$t9,0x38($sp)
/*    34388:	af220060 */ 	sw	$v0,0x60($t9)
/*    3438c:	0c00f722 */ 	jal	func0003dc88
/*    34390:	8fa40038 */ 	lw	$a0,0x38($sp)
/*    34394:	8fa8003c */ 	lw	$t0,0x3c($sp)
/*    34398:	24090040 */ 	addiu	$t1,$zero,0x40
/*    3439c:	00002025 */ 	or	$a0,$zero,$zero
/*    343a0:	8d070000 */ 	lw	$a3,0x0($t0)
/*    343a4:	afa90010 */ 	sw	$t1,0x10($sp)
/*    343a8:	00002825 */ 	or	$a1,$zero,$zero
/*    343ac:	0c00bec5 */ 	jal	func0002fb14
/*    343b0:	8fa60024 */ 	lw	$a2,0x24($sp)
/*    343b4:	afa20028 */ 	sw	$v0,0x28($sp)
/*    343b8:	8faa0038 */ 	lw	$t2,0x38($sp)
/*    343bc:	ad40006c */ 	sw	$zero,0x6c($t2)
/*    343c0:	8fab003c */ 	lw	$t3,0x3c($sp)
/*    343c4:	afa00034 */ 	sw	$zero,0x34($sp)
/*    343c8:	8d6c0000 */ 	lw	$t4,0x0($t3)
/*    343cc:	19800015 */ 	blez	$t4,.L00034424
/*    343d0:	00000000 */ 	sll	$zero,$zero,0x0
.L000343d4:
/*    343d4:	8fad0034 */ 	lw	$t5,0x34($sp)
/*    343d8:	8faf0028 */ 	lw	$t7,0x28($sp)
/*    343dc:	000d7180 */ 	sll	$t6,$t5,0x6
/*    343e0:	01cfc021 */ 	addu	$t8,$t6,$t7
/*    343e4:	afb8002c */ 	sw	$t8,0x2c($sp)
/*    343e8:	8fb90038 */ 	lw	$t9,0x38($sp)
/*    343ec:	8fa9002c */ 	lw	$t1,0x2c($sp)
/*    343f0:	8f28006c */ 	lw	$t0,0x6c($t9)
/*    343f4:	ad280000 */ 	sw	$t0,0x0($t1)
/*    343f8:	8faa002c */ 	lw	$t2,0x2c($sp)
/*    343fc:	8fab0038 */ 	lw	$t3,0x38($sp)
/*    34400:	ad6a006c */ 	sw	$t2,0x6c($t3)
/*    34404:	8fac0034 */ 	lw	$t4,0x34($sp)
/*    34408:	8fae003c */ 	lw	$t6,0x3c($sp)
/*    3440c:	258d0001 */ 	addiu	$t5,$t4,0x1
/*    34410:	afad0034 */ 	sw	$t5,0x34($sp)
/*    34414:	8dcf0000 */ 	lw	$t7,0x0($t6)
/*    34418:	01af082a */ 	slt	$at,$t5,$t7
/*    3441c:	1420ffed */ 	bnez	$at,.L000343d4
/*    34420:	00000000 */ 	sll	$zero,$zero,0x0
.L00034424:
/*    34424:	8fb80038 */ 	lw	$t8,0x38($sp)
/*    34428:	af000064 */ 	sw	$zero,0x64($t8)
/*    3442c:	8fb90038 */ 	lw	$t9,0x38($sp)
/*    34430:	af200068 */ 	sw	$zero,0x68($t9)
/*    34434:	8fa8003c */ 	lw	$t0,0x3c($sp)
/*    34438:	2409001c */ 	addiu	$t1,$zero,0x1c
/*    3443c:	00002025 */ 	or	$a0,$zero,$zero
/*    34440:	8d070004 */ 	lw	$a3,0x4($t0)
/*    34444:	afa90010 */ 	sw	$t1,0x10($sp)
/*    34448:	00002825 */ 	or	$a1,$zero,$zero
/*    3444c:	0c00bec5 */ 	jal	func0002fb14
/*    34450:	8fa60024 */ 	lw	$a2,0x24($sp)
/*    34454:	afa20030 */ 	sw	$v0,0x30($sp)
/*    34458:	8fa40038 */ 	lw	$a0,0x38($sp)
/*    3445c:	8faa003c */ 	lw	$t2,0x3c($sp)
/*    34460:	8fa50030 */ 	lw	$a1,0x30($sp)
/*    34464:	24840048 */ 	addiu	$a0,$a0,0x48
/*    34468:	0c00f134 */ 	jal	func0003c4d0
/*    3446c:	8d460004 */ 	lw	$a2,0x4($t2)
/*    34470:	8fab0038 */ 	lw	$t3,0x38($sp)
/*    34474:	ad600000 */ 	sw	$zero,0x0($t3)
/*    34478:	8fae0038 */ 	lw	$t6,0x38($sp)
/*    3447c:	3c0c7003 */ 	lui	$t4,0x7003
/*    34480:	258c44b0 */ 	addiu	$t4,$t4,0x44b0
/*    34484:	adcc0008 */ 	sw	$t4,0x8($t6)
/*    34488:	8fad0038 */ 	lw	$t5,0x38($sp)
/*    3448c:	adad0004 */ 	sw	$t5,0x4($t5)
/*    34490:	0c00f25c */ 	jal	func0003c970
/*    34494:	8fa40038 */ 	lw	$a0,0x38($sp)
/*    34498:	10000001 */ 	beqz	$zero,.L000344a0
/*    3449c:	00000000 */ 	sll	$zero,$zero,0x0
.L000344a0:
/*    344a0:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*    344a4:	27bd0038 */ 	addiu	$sp,$sp,0x38
/*    344a8:	03e00008 */ 	jr	$ra
/*    344ac:	00000000 */ 	sll	$zero,$zero,0x0
/*    344b0:	27bdff88 */ 	addiu	$sp,$sp,-120
/*    344b4:	afbf002c */ 	sw	$ra,0x2c($sp)
/*    344b8:	afa40078 */ 	sw	$a0,0x78($sp)
/*    344bc:	afb20028 */ 	sw	$s2,0x28($sp)
/*    344c0:	afb10024 */ 	sw	$s1,0x24($sp)
/*    344c4:	afb00020 */ 	sw	$s0,0x20($sp)
/*    344c8:	f7b40018 */ 	sdc1	$f20,0x18($sp)
/*    344cc:	8fae0078 */ 	lw	$t6,0x78($sp)
/*    344d0:	afae0074 */ 	sw	$t6,0x74($sp)
.L000344d4:
/*    344d4:	8faf0074 */ 	lw	$t7,0x74($sp)
/*    344d8:	95f80038 */ 	lhu	$t8,0x38($t7)
/*    344dc:	2f01001a */ 	sltiu	$at,$t8,0x1a
/*    344e0:	1020022a */ 	beqz	$at,.L00034d8c
/*    344e4:	00000000 */ 	sll	$zero,$zero,0x0
/*    344e8:	0018c080 */ 	sll	$t8,$t8,0x2
/*    344ec:	3c017005 */ 	lui	$at,%hi(var70054780)
/*    344f0:	00380821 */ 	addu	$at,$at,$t8
/*    344f4:	8c384780 */ 	lw	$t8,%lo(var70054780)($at)
/*    344f8:	03000008 */ 	jr	$t8
/*    344fc:	00000000 */ 	sll	$zero,$zero,0x0
/*    34500:	0c00d37e */ 	jal	func00034df8
/*    34504:	8fa40074 */ 	lw	$a0,0x74($sp)
/*    34508:	10000220 */ 	beqz	$zero,.L00034d8c
/*    3450c:	00000000 */ 	sll	$zero,$zero,0x0
/*    34510:	24190009 */ 	addiu	$t9,$zero,0x9
/*    34514:	a7b90064 */ 	sh	$t9,0x64($sp)
/*    34518:	8fa80074 */ 	lw	$t0,0x74($sp)
/*    3451c:	27a50064 */ 	addiu	$a1,$sp,0x64
/*    34520:	24070001 */ 	addiu	$a3,$zero,0x1
/*    34524:	25040048 */ 	addiu	$a0,$t0,0x48
/*    34528:	0c00f184 */ 	jal	func0003c610
/*    3452c:	8d06005c */ 	lw	$a2,0x5c($t0)
/*    34530:	10000216 */ 	beqz	$zero,.L00034d8c
/*    34534:	00000000 */ 	sll	$zero,$zero,0x0
/*    34538:	8fa90074 */ 	lw	$t1,0x74($sp)
/*    3453c:	8d2a003c */ 	lw	$t2,0x3c($t1)
/*    34540:	afaa0060 */ 	sw	$t2,0x60($sp)
/*    34544:	0c00f440 */ 	jal	func0003d100
/*    34548:	8fa40060 */ 	lw	$a0,0x60($sp)
/*    3454c:	0c00f468 */ 	jal	func0003d1a0
/*    34550:	8fa40060 */ 	lw	$a0,0x60($sp)
/*    34554:	8fab0060 */ 	lw	$t3,0x60($sp)
/*    34558:	8d6c0010 */ 	lw	$t4,0x10($t3)
/*    3455c:	afac0058 */ 	sw	$t4,0x58($sp)
/*    34560:	8fad0058 */ 	lw	$t5,0x58($sp)
/*    34564:	91ae0037 */ 	lbu	$t6,0x37($t5)
/*    34568:	11c00004 */ 	beqz	$t6,.L0003457c
/*    3456c:	00000000 */ 	sll	$zero,$zero,0x0
/*    34570:	8fa40074 */ 	lw	$a0,0x74($sp)
/*    34574:	0c00f8a8 */ 	jal	func0003e2a0
/*    34578:	8fa50058 */ 	lw	$a1,0x58($sp)
.L0003457c:
/*    3457c:	8fa40074 */ 	lw	$a0,0x74($sp)
/*    34580:	0c00f4a0 */ 	jal	func0003d280
/*    34584:	8fa50060 */ 	lw	$a1,0x60($sp)
/*    34588:	10000200 */ 	beqz	$zero,.L00034d8c
/*    3458c:	00000000 */ 	sll	$zero,$zero,0x0
/*    34590:	8faf0074 */ 	lw	$t7,0x74($sp)
/*    34594:	8df8003c */ 	lw	$t8,0x3c($t7)
/*    34598:	afb80060 */ 	sw	$t8,0x60($sp)
/*    3459c:	8fb90060 */ 	lw	$t9,0x60($sp)
/*    345a0:	8f280010 */ 	lw	$t0,0x10($t9)
/*    345a4:	afa80058 */ 	sw	$t0,0x58($sp)
/*    345a8:	8fa90058 */ 	lw	$t1,0x58($sp)
/*    345ac:	912a0034 */ 	lbu	$t2,0x34($t1)
/*    345b0:	15400004 */ 	bnez	$t2,.L000345c4
/*    345b4:	00000000 */ 	sll	$zero,$zero,0x0
/*    345b8:	8fac0058 */ 	lw	$t4,0x58($sp)
/*    345bc:	240b0001 */ 	addiu	$t3,$zero,0x1
/*    345c0:	a18b0034 */ 	sb	$t3,0x34($t4)
.L000345c4:
/*    345c4:	8fad0074 */ 	lw	$t5,0x74($sp)
/*    345c8:	8dae0040 */ 	lw	$t6,0x40($t5)
/*    345cc:	afae005c */ 	sw	$t6,0x5c($sp)
/*    345d0:	8faf0074 */ 	lw	$t7,0x74($sp)
/*    345d4:	8fb9005c */ 	lw	$t9,0x5c($sp)
/*    345d8:	8fa90058 */ 	lw	$t1,0x58($sp)
/*    345dc:	8df8001c */ 	lw	$t8,0x1c($t7)
/*    345e0:	03194021 */ 	addu	$t0,$t8,$t9
/*    345e4:	ad280024 */ 	sw	$t0,0x24($t1)
/*    345e8:	8faa0074 */ 	lw	$t2,0x74($sp)
/*    345ec:	8fac0058 */ 	lw	$t4,0x58($sp)
/*    345f0:	914b0044 */ 	lbu	$t3,0x44($t2)
/*    345f4:	a18b0030 */ 	sb	$t3,0x30($t4)
/*    345f8:	8fa40058 */ 	lw	$a0,0x58($sp)
/*    345fc:	0c00f629 */ 	jal	func0003d8a4
/*    34600:	8fa50074 */ 	lw	$a1,0x74($sp)
/*    34604:	00028400 */ 	sll	$s0,$v0,0x10
/*    34608:	00108403 */ 	sra	$s0,$s0,0x10
/*    3460c:	02002825 */ 	or	$a1,$s0,$zero
/*    34610:	8fa40060 */ 	lw	$a0,0x60($sp)
/*    34614:	0c00f33c */ 	jal	func0003ccf0
/*    34618:	8fa6005c */ 	lw	$a2,0x5c($sp)
/*    3461c:	100001db */ 	beqz	$zero,.L00034d8c
/*    34620:	00000000 */ 	sll	$zero,$zero,0x0
/*    34624:	8fad0074 */ 	lw	$t5,0x74($sp)
/*    34628:	8dae003c */ 	lw	$t6,0x3c($t5)
/*    3462c:	afae0058 */ 	sw	$t6,0x58($sp)
/*    34630:	8faf0074 */ 	lw	$t7,0x74($sp)
/*    34634:	8df80040 */ 	lw	$t8,0x40($t7)
/*    34638:	afb80054 */ 	sw	$t8,0x54($sp)
/*    3463c:	8fb90074 */ 	lw	$t9,0x74($sp)
/*    34640:	8fa40054 */ 	lw	$a0,0x54($sp)
/*    34644:	27a50050 */ 	addiu	$a1,$sp,0x50
/*    34648:	8f390074 */ 	lw	$t9,0x74($t9)
/*    3464c:	0320f809 */ 	jalr	$t9
/*    34650:	00000000 */ 	sll	$zero,$zero,0x0
/*    34654:	afa2005c */ 	sw	$v0,0x5c($sp)
/*    34658:	4448f800 */ 	cfc1	$t0,$31
/*    3465c:	24090001 */ 	addiu	$t1,$zero,0x1
/*    34660:	44c9f800 */ 	ctc1	$t1,$31
/*    34664:	c7a40050 */ 	lwc1	$f4,0x50($sp)
/*    34668:	460021a4 */ 	cvt.w.s	$f6,$f4
/*    3466c:	4449f800 */ 	cfc1	$t1,$31
/*    34670:	00000000 */ 	sll	$zero,$zero,0x0
/*    34674:	31210004 */ 	andi	$at,$t1,0x4
/*    34678:	31290078 */ 	andi	$t1,$t1,0x78
/*    3467c:	11200014 */ 	beqz	$t1,.L000346d0
/*    34680:	00000000 */ 	sll	$zero,$zero,0x0
/*    34684:	3c014f00 */ 	lui	$at,0x4f00
/*    34688:	44813000 */ 	mtc1	$at,$f6
/*    3468c:	24090001 */ 	addiu	$t1,$zero,0x1
/*    34690:	46062181 */ 	sub.s	$f6,$f4,$f6
/*    34694:	44c9f800 */ 	ctc1	$t1,$31
/*    34698:	00000000 */ 	sll	$zero,$zero,0x0
/*    3469c:	460031a4 */ 	cvt.w.s	$f6,$f6
/*    346a0:	4449f800 */ 	cfc1	$t1,$31
/*    346a4:	00000000 */ 	sll	$zero,$zero,0x0
/*    346a8:	31210004 */ 	andi	$at,$t1,0x4
/*    346ac:	31290078 */ 	andi	$t1,$t1,0x78
/*    346b0:	15200005 */ 	bnez	$t1,.L000346c8
/*    346b4:	00000000 */ 	sll	$zero,$zero,0x0
/*    346b8:	44093000 */ 	mfc1	$t1,$f6
/*    346bc:	3c018000 */ 	lui	$at,0x8000
/*    346c0:	10000007 */ 	beqz	$zero,.L000346e0
/*    346c4:	01214825 */ 	or	$t1,$t1,$at
.L000346c8:
/*    346c8:	10000005 */ 	beqz	$zero,.L000346e0
/*    346cc:	2409ffff */ 	addiu	$t1,$zero,-1
.L000346d0:
/*    346d0:	44093000 */ 	mfc1	$t1,$f6
/*    346d4:	00000000 */ 	sll	$zero,$zero,0x0
/*    346d8:	0520fffb */ 	bltz	$t1,.L000346c8
/*    346dc:	00000000 */ 	sll	$zero,$zero,0x0
.L000346e0:
/*    346e0:	8faa0058 */ 	lw	$t2,0x58($sp)
/*    346e4:	44c8f800 */ 	ctc1	$t0,$31
/*    346e8:	a1490036 */ 	sb	$t1,0x36($t2)
/*    346ec:	00000000 */ 	sll	$zero,$zero,0x0
/*    346f0:	8fa40058 */ 	lw	$a0,0x58($sp)
/*    346f4:	0c00f629 */ 	jal	func0003d8a4
/*    346f8:	8fa50074 */ 	lw	$a1,0x74($sp)
/*    346fc:	8fab0074 */ 	lw	$t3,0x74($sp)
/*    34700:	00028400 */ 	sll	$s0,$v0,0x10
/*    34704:	00108403 */ 	sra	$s0,$s0,0x10
/*    34708:	8fa40058 */ 	lw	$a0,0x58($sp)
/*    3470c:	0c00f6b4 */ 	jal	func0003dad0
/*    34710:	8d65001c */ 	lw	$a1,0x1c($t3)
/*    34714:	8fa40058 */ 	lw	$a0,0x58($sp)
/*    34718:	00408825 */ 	or	$s1,$v0,$zero
/*    3471c:	02203025 */ 	or	$a2,$s1,$zero
/*    34720:	02002825 */ 	or	$a1,$s0,$zero
/*    34724:	0c00f33c */ 	jal	func0003ccf0
/*    34728:	24840004 */ 	addiu	$a0,$a0,0x4
/*    3472c:	240c0016 */ 	addiu	$t4,$zero,0x16
/*    34730:	a7ac0064 */ 	sh	$t4,0x64($sp)
/*    34734:	8fad0058 */ 	lw	$t5,0x58($sp)
/*    34738:	afad0068 */ 	sw	$t5,0x68($sp)
/*    3473c:	8fae0054 */ 	lw	$t6,0x54($sp)
/*    34740:	afae006c */ 	sw	$t6,0x6c($sp)
/*    34744:	8fa40074 */ 	lw	$a0,0x74($sp)
/*    34748:	27a50064 */ 	addiu	$a1,$sp,0x64
/*    3474c:	8fa6005c */ 	lw	$a2,0x5c($sp)
/*    34750:	00003825 */ 	or	$a3,$zero,$zero
/*    34754:	0c00f184 */ 	jal	func0003c610
/*    34758:	24840048 */ 	addiu	$a0,$a0,0x48
/*    3475c:	1000018b */ 	beqz	$zero,.L00034d8c
/*    34760:	00000000 */ 	sll	$zero,$zero,0x0
/*    34764:	8faf0074 */ 	lw	$t7,0x74($sp)
/*    34768:	8df8003c */ 	lw	$t8,0x3c($t7)
/*    3476c:	afb80058 */ 	sw	$t8,0x58($sp)
/*    34770:	8fb90074 */ 	lw	$t9,0x74($sp)
/*    34774:	8f280040 */ 	lw	$t0,0x40($t9)
/*    34778:	afa80054 */ 	sw	$t0,0x54($sp)
/*    3477c:	8fa90074 */ 	lw	$t1,0x74($sp)
/*    34780:	912a0044 */ 	lbu	$t2,0x44($t1)
/*    34784:	a3aa004f */ 	sb	$t2,0x4f($sp)
/*    34788:	8fab0074 */ 	lw	$t3,0x74($sp)
/*    3478c:	8fa40054 */ 	lw	$a0,0x54($sp)
/*    34790:	27a50050 */ 	addiu	$a1,$sp,0x50
/*    34794:	8d790074 */ 	lw	$t9,0x74($t3)
/*    34798:	0320f809 */ 	jalr	$t9
/*    3479c:	00000000 */ 	sll	$zero,$zero,0x0
/*    347a0:	afa2005c */ 	sw	$v0,0x5c($sp)
/*    347a4:	c7a80050 */ 	lwc1	$f8,0x50($sp)
/*    347a8:	8fac0058 */ 	lw	$t4,0x58($sp)
/*    347ac:	e588002c */ 	swc1	$f8,0x2c($t4)
/*    347b0:	8fad0058 */ 	lw	$t5,0x58($sp)
/*    347b4:	93b8004f */ 	lbu	$t8,0x4f($sp)
/*    347b8:	8fae0074 */ 	lw	$t6,0x74($sp)
/*    347bc:	c5b00028 */ 	lwc1	$f16,0x28($t5)
/*    347c0:	c5b2002c */ 	lwc1	$f18,0x2c($t5)
/*    347c4:	00184080 */ 	sll	$t0,$t8,0x2
/*    347c8:	01184023 */ 	subu	$t0,$t0,$t8
/*    347cc:	46128102 */ 	mul.s	$f4,$f16,$f18
/*    347d0:	8dcf0060 */ 	lw	$t7,0x60($t6)
/*    347d4:	00084080 */ 	sll	$t0,$t0,0x2
/*    347d8:	01184021 */ 	addu	$t0,$t0,$t8
/*    347dc:	00084080 */ 	sll	$t0,$t0,0x2
/*    347e0:	01e84821 */ 	addu	$t1,$t7,$t0
/*    347e4:	c52a0014 */ 	lwc1	$f10,0x14($t1)
/*    347e8:	25a40004 */ 	addiu	$a0,$t5,0x4
/*    347ec:	46045182 */ 	mul.s	$f6,$f10,$f4
/*    347f0:	44053000 */ 	mfc1	$a1,$f6
/*    347f4:	0c00f3e8 */ 	jal	func0003cfa0
/*    347f8:	00000000 */ 	sll	$zero,$zero,0x0
/*    347fc:	93b9004f */ 	lbu	$t9,0x4f($sp)
/*    34800:	8faa0074 */ 	lw	$t2,0x74($sp)
/*    34804:	00196080 */ 	sll	$t4,$t9,0x2
/*    34808:	01996023 */ 	subu	$t4,$t4,$t9
/*    3480c:	8d4b0060 */ 	lw	$t3,0x60($t2)
/*    34810:	000c6080 */ 	sll	$t4,$t4,0x2
/*    34814:	01996021 */ 	addu	$t4,$t4,$t9
/*    34818:	000c6080 */ 	sll	$t4,$t4,0x2
/*    3481c:	016c7021 */ 	addu	$t6,$t3,$t4
/*    34820:	91d80011 */ 	lbu	$t8,0x11($t6)
/*    34824:	1300002a */ 	beqz	$t8,.L000348d0
/*    34828:	00000000 */ 	sll	$zero,$zero,0x0
/*    3482c:	8fab0058 */ 	lw	$t3,0x58($sp)
/*    34830:	93a9004f */ 	lbu	$t1,0x4f($sp)
/*    34834:	8faf0074 */ 	lw	$t7,0x74($sp)
/*    34838:	8d6e0020 */ 	lw	$t6,0x20($t3)
/*    3483c:	00096880 */ 	sll	$t5,$t1,0x2
/*    34840:	01a96823 */ 	subu	$t5,$t5,$t1
/*    34844:	8de80060 */ 	lw	$t0,0x60($t7)
/*    34848:	8dd80004 */ 	lw	$t8,0x4($t6)
/*    3484c:	000d6880 */ 	sll	$t5,$t5,0x2
/*    34850:	01a96821 */ 	addu	$t5,$t5,$t1
/*    34854:	000d6880 */ 	sll	$t5,$t5,0x2
/*    34858:	916c0032 */ 	lbu	$t4,0x32($t3)
/*    3485c:	930f0004 */ 	lbu	$t7,0x4($t8)
/*    34860:	010d5021 */ 	addu	$t2,$t0,$t5
/*    34864:	91590012 */ 	lbu	$t9,0x12($t2)
/*    34868:	018f4823 */ 	subu	$t1,$t4,$t7
/*    3486c:	03292021 */ 	addu	$a0,$t9,$t1
/*    34870:	0c00ee75 */ 	jal	func0003b9d4
/*    34874:	2484ffc0 */ 	addiu	$a0,$a0,-64
/*    34878:	93ab004f */ 	lbu	$t3,0x4f($sp)
/*    3487c:	3c0143dc */ 	lui	$at,0x43dc
/*    34880:	44818000 */ 	mtc1	$at,$f16
/*    34884:	8fad0074 */ 	lw	$t5,0x74($sp)
/*    34888:	000b7080 */ 	sll	$t6,$t3,0x2
/*    3488c:	46000506 */ 	mov.s	$f20,$f0
/*    34890:	01cb7023 */ 	subu	$t6,$t6,$t3
/*    34894:	46148482 */ 	mul.s	$f18,$f16,$f20
/*    34898:	8daa0060 */ 	lw	$t2,0x60($t5)
/*    3489c:	000e7080 */ 	sll	$t6,$t6,0x2
/*    348a0:	01cb7021 */ 	addu	$t6,$t6,$t3
/*    348a4:	000e7080 */ 	sll	$t6,$t6,0x2
/*    348a8:	014ec021 */ 	addu	$t8,$t2,$t6
/*    348ac:	c7080014 */ 	lwc1	$f8,0x14($t8)
/*    348b0:	8fa80058 */ 	lw	$t0,0x58($sp)
/*    348b4:	46124282 */ 	mul.s	$f10,$f8,$f18
/*    348b8:	c504002c */ 	lwc1	$f4,0x2c($t0)
/*    348bc:	25040004 */ 	addiu	$a0,$t0,0x4
/*    348c0:	46045182 */ 	mul.s	$f6,$f10,$f4
/*    348c4:	44053000 */ 	mfc1	$a1,$f6
/*    348c8:	0c00f8f8 */ 	jal	func0003e3e0
/*    348cc:	00000000 */ 	sll	$zero,$zero,0x0
.L000348d0:
/*    348d0:	240c0017 */ 	addiu	$t4,$zero,0x17
/*    348d4:	a7ac0064 */ 	sh	$t4,0x64($sp)
/*    348d8:	8faf0058 */ 	lw	$t7,0x58($sp)
/*    348dc:	afaf0068 */ 	sw	$t7,0x68($sp)
/*    348e0:	8fb90054 */ 	lw	$t9,0x54($sp)
/*    348e4:	afb9006c */ 	sw	$t9,0x6c($sp)
/*    348e8:	93a9004f */ 	lbu	$t1,0x4f($sp)
/*    348ec:	a3a90070 */ 	sb	$t1,0x70($sp)
/*    348f0:	8fa40074 */ 	lw	$a0,0x74($sp)
/*    348f4:	27a50064 */ 	addiu	$a1,$sp,0x64
/*    348f8:	8fa6005c */ 	lw	$a2,0x5c($sp)
/*    348fc:	00003825 */ 	or	$a3,$zero,$zero
/*    34900:	0c00f184 */ 	jal	func0003c610
/*    34904:	24840048 */ 	addiu	$a0,$a0,0x48
/*    34908:	10000120 */ 	beqz	$zero,.L00034d8c
/*    3490c:	00000000 */ 	sll	$zero,$zero,0x0
/*    34910:	8fad0074 */ 	lw	$t5,0x74($sp)
/*    34914:	01a02025 */ 	or	$a0,$t5,$zero
/*    34918:	0c00d444 */ 	jal	func00035110
/*    3491c:	25a50038 */ 	addiu	$a1,$t5,0x38
/*    34920:	1000011a */ 	beqz	$zero,.L00034d8c
/*    34924:	00000000 */ 	sll	$zero,$zero,0x0
/*    34928:	8fab0074 */ 	lw	$t3,0x74($sp)
/*    3492c:	01602025 */ 	or	$a0,$t3,$zero
/*    34930:	0c00dc88 */ 	jal	func00037220
/*    34934:	25650038 */ 	addiu	$a1,$t3,0x38
/*    34938:	10000114 */ 	beqz	$zero,.L00034d8c
/*    3493c:	00000000 */ 	sll	$zero,$zero,0x0
/*    34940:	8faa0074 */ 	lw	$t2,0x74($sp)
/*    34944:	854e003c */ 	lh	$t6,0x3c($t2)
/*    34948:	a54e0032 */ 	sh	$t6,0x32($t2)
/*    3494c:	8fb80074 */ 	lw	$t8,0x74($sp)
/*    34950:	8f080064 */ 	lw	$t0,0x64($t8)
/*    34954:	11000014 */ 	beqz	$t0,.L000349a8
/*    34958:	afa80058 */ 	sw	$t0,0x58($sp)
.L0003495c:
/*    3495c:	8fa40058 */ 	lw	$a0,0x58($sp)
/*    34960:	0c00f629 */ 	jal	func0003d8a4
/*    34964:	8fa50074 */ 	lw	$a1,0x74($sp)
/*    34968:	8fac0074 */ 	lw	$t4,0x74($sp)
/*    3496c:	00028400 */ 	sll	$s0,$v0,0x10
/*    34970:	00108403 */ 	sra	$s0,$s0,0x10
/*    34974:	8fa40058 */ 	lw	$a0,0x58($sp)
/*    34978:	0c00f6b4 */ 	jal	func0003dad0
/*    3497c:	8d85001c */ 	lw	$a1,0x1c($t4)
/*    34980:	8fa40058 */ 	lw	$a0,0x58($sp)
/*    34984:	00408825 */ 	or	$s1,$v0,$zero
/*    34988:	02203025 */ 	or	$a2,$s1,$zero
/*    3498c:	02002825 */ 	or	$a1,$s0,$zero
/*    34990:	0c00f33c */ 	jal	func0003ccf0
/*    34994:	24840004 */ 	addiu	$a0,$a0,0x4
/*    34998:	8faf0058 */ 	lw	$t7,0x58($sp)
/*    3499c:	8df90000 */ 	lw	$t9,0x0($t7)
/*    349a0:	1720ffee */ 	bnez	$t9,.L0003495c
/*    349a4:	afb90058 */ 	sw	$t9,0x58($sp)
.L000349a8:
/*    349a8:	100000f8 */ 	beqz	$zero,.L00034d8c
/*    349ac:	00000000 */ 	sll	$zero,$zero,0x0
/*    349b0:	8fa90074 */ 	lw	$t1,0x74($sp)
/*    349b4:	c530003c */ 	lwc1	$f16,0x3c($t1)
/*    349b8:	e530007c */ 	swc1	$f16,0x7c($t1)
/*    349bc:	8fad0074 */ 	lw	$t5,0x74($sp)
/*    349c0:	c5a80040 */ 	lwc1	$f8,0x40($t5)
/*    349c4:	e5a80080 */ 	swc1	$f8,0x80($t5)
/*    349c8:	8fab0074 */ 	lw	$t3,0x74($sp)
/*    349cc:	8d6e0064 */ 	lw	$t6,0x64($t3)
/*    349d0:	11c0000d */ 	beqz	$t6,.L00034a08
/*    349d4:	afae0058 */ 	sw	$t6,0x58($sp)
.L000349d8:
/*    349d8:	8fa40058 */ 	lw	$a0,0x58($sp)
/*    349dc:	0c00f673 */ 	jal	func0003d9cc
/*    349e0:	8fa50074 */ 	lw	$a1,0x74($sp)
/*    349e4:	8fa40058 */ 	lw	$a0,0x58($sp)
/*    349e8:	305200ff */ 	andi	$s2,$v0,0xff
/*    349ec:	02402825 */ 	or	$a1,$s2,$zero
/*    349f0:	0c00f414 */ 	jal	func0003d050
/*    349f4:	24840004 */ 	addiu	$a0,$a0,0x4
/*    349f8:	8faa0058 */ 	lw	$t2,0x58($sp)
/*    349fc:	8d580000 */ 	lw	$t8,0x0($t2)
/*    34a00:	1700fff5 */ 	bnez	$t8,.L000349d8
/*    34a04:	afb80058 */ 	sw	$t8,0x58($sp)
.L00034a08:
/*    34a08:	100000e0 */ 	beqz	$zero,.L00034d8c
/*    34a0c:	00000000 */ 	sll	$zero,$zero,0x0
/*    34a10:	8fa80074 */ 	lw	$t0,0x74($sp)
/*    34a14:	910c003d */ 	lbu	$t4,0x3d($t0)
/*    34a18:	29810008 */ 	slti	$at,$t4,0x8
/*    34a1c:	10200013 */ 	beqz	$at,.L00034a6c
/*    34a20:	00000000 */ 	sll	$zero,$zero,0x0
/*    34a24:	8faf0074 */ 	lw	$t7,0x74($sp)
/*    34a28:	0c00f950 */ 	jal	func0003e540
/*    34a2c:	91e4003c */ 	lbu	$a0,0x3c($t7)
/*    34a30:	afa20048 */ 	sw	$v0,0x48($sp)
/*    34a34:	8fb90048 */ 	lw	$t9,0x48($sp)
/*    34a38:	1320000a */ 	beqz	$t9,.L00034a64
/*    34a3c:	00000000 */ 	sll	$zero,$zero,0x0
/*    34a40:	8fa90074 */ 	lw	$t1,0x74($sp)
/*    34a44:	8fa40048 */ 	lw	$a0,0x48($sp)
/*    34a48:	912d003e */ 	lbu	$t5,0x3e($t1)
/*    34a4c:	912e003d */ 	lbu	$t6,0x3d($t1)
/*    34a50:	25260040 */ 	addiu	$a2,$t1,0x40
/*    34a54:	000d58c0 */ 	sll	$t3,$t5,0x3
/*    34a58:	31ca0007 */ 	andi	$t2,$t6,0x7
/*    34a5c:	0c00f98c */ 	jal	func0003e630
/*    34a60:	016a2825 */ 	or	$a1,$t3,$t2
.L00034a64:
/*    34a64:	1000000d */ 	beqz	$zero,.L00034a9c
/*    34a68:	00000000 */ 	sll	$zero,$zero,0x0
.L00034a6c:
/*    34a6c:	8fb80074 */ 	lw	$t8,0x74($sp)
/*    34a70:	0c00f96e */ 	jal	func0003e5b8
/*    34a74:	9304003c */ 	lbu	$a0,0x3c($t8)
/*    34a78:	afa20044 */ 	sw	$v0,0x44($sp)
/*    34a7c:	8fa80044 */ 	lw	$t0,0x44($sp)
/*    34a80:	11000006 */ 	beqz	$t0,.L00034a9c
/*    34a84:	00000000 */ 	sll	$zero,$zero,0x0
/*    34a88:	8fac0074 */ 	lw	$t4,0x74($sp)
/*    34a8c:	8fa40044 */ 	lw	$a0,0x44($sp)
/*    34a90:	9185003d */ 	lbu	$a1,0x3d($t4)
/*    34a94:	0c00f99d */ 	jal	func0003e674
/*    34a98:	25860040 */ 	addiu	$a2,$t4,0x40
.L00034a9c:
/*    34a9c:	100000bb */ 	beqz	$zero,.L00034d8c
/*    34aa0:	00000000 */ 	sll	$zero,$zero,0x0
/*    34aa4:	8faf0074 */ 	lw	$t7,0x74($sp)
/*    34aa8:	24010001 */ 	addiu	$at,$zero,0x1
/*    34aac:	8df9002c */ 	lw	$t9,0x2c($t7)
/*    34ab0:	13210006 */ 	beq	$t9,$at,.L00034acc
/*    34ab4:	00000000 */ 	sll	$zero,$zero,0x0
/*    34ab8:	8fae0074 */ 	lw	$t6,0x74($sp)
/*    34abc:	240d0001 */ 	addiu	$t5,$zero,0x1
/*    34ac0:	adcd002c */ 	sw	$t5,0x2c($t6)
/*    34ac4:	0c00dd67 */ 	jal	func0003759c
/*    34ac8:	8fa40074 */ 	lw	$a0,0x74($sp)
.L00034acc:
/*    34acc:	100000af */ 	beqz	$zero,.L00034d8c
/*    34ad0:	00000000 */ 	sll	$zero,$zero,0x0
/*    34ad4:	8fab0074 */ 	lw	$t3,0x74($sp)
/*    34ad8:	24010002 */ 	addiu	$at,$zero,0x2
/*    34adc:	8d6a002c */ 	lw	$t2,0x2c($t3)
/*    34ae0:	1541001c */ 	bne	$t2,$at,.L00034b54
/*    34ae4:	00000000 */ 	sll	$zero,$zero,0x0
/*    34ae8:	8fa90074 */ 	lw	$t1,0x74($sp)
/*    34aec:	8d380064 */ 	lw	$t8,0x64($t1)
/*    34af0:	13000016 */ 	beqz	$t8,.L00034b4c
/*    34af4:	afb80058 */ 	sw	$t8,0x58($sp)
.L00034af8:
/*    34af8:	8fa40058 */ 	lw	$a0,0x58($sp)
/*    34afc:	0c00f440 */ 	jal	func0003d100
/*    34b00:	24840004 */ 	addiu	$a0,$a0,0x4
/*    34b04:	8fa40058 */ 	lw	$a0,0x58($sp)
/*    34b08:	0c00f468 */ 	jal	func0003d1a0
/*    34b0c:	24840004 */ 	addiu	$a0,$a0,0x4
/*    34b10:	8fa80058 */ 	lw	$t0,0x58($sp)
/*    34b14:	910c0037 */ 	lbu	$t4,0x37($t0)
/*    34b18:	11800004 */ 	beqz	$t4,.L00034b2c
/*    34b1c:	00000000 */ 	sll	$zero,$zero,0x0
/*    34b20:	8fa40074 */ 	lw	$a0,0x74($sp)
/*    34b24:	0c00f8a8 */ 	jal	func0003e2a0
/*    34b28:	8fa50058 */ 	lw	$a1,0x58($sp)
.L00034b2c:
/*    34b2c:	8fa50058 */ 	lw	$a1,0x58($sp)
/*    34b30:	8fa40074 */ 	lw	$a0,0x74($sp)
/*    34b34:	0c00f4a0 */ 	jal	func0003d280
/*    34b38:	24a50004 */ 	addiu	$a1,$a1,0x4
/*    34b3c:	8faf0074 */ 	lw	$t7,0x74($sp)
/*    34b40:	8df90064 */ 	lw	$t9,0x64($t7)
/*    34b44:	1720ffec */ 	bnez	$t9,.L00034af8
/*    34b48:	afb90058 */ 	sw	$t9,0x58($sp)
.L00034b4c:
/*    34b4c:	8fad0074 */ 	lw	$t5,0x74($sp)
/*    34b50:	ada0002c */ 	sw	$zero,0x2c($t5)
.L00034b54:
/*    34b54:	1000008d */ 	beqz	$zero,.L00034d8c
/*    34b58:	00000000 */ 	sll	$zero,$zero,0x0
/*    34b5c:	8fae0074 */ 	lw	$t6,0x74($sp)
/*    34b60:	24010001 */ 	addiu	$at,$zero,0x1
/*    34b64:	8dcb002c */ 	lw	$t3,0x2c($t6)
/*    34b68:	1561005b */ 	bne	$t3,$at,.L00034cd8
/*    34b6c:	00000000 */ 	sll	$zero,$zero,0x0
/*    34b70:	8fa40074 */ 	lw	$a0,0x74($sp)
/*    34b74:	00002825 */ 	or	$a1,$zero,$zero
/*    34b78:	0c00f1f0 */ 	jal	func0003c7c0
/*    34b7c:	24840048 */ 	addiu	$a0,$a0,0x48
/*    34b80:	8fa40074 */ 	lw	$a0,0x74($sp)
/*    34b84:	24050015 */ 	addiu	$a1,$zero,0x15
/*    34b88:	0c00f1f0 */ 	jal	func0003c7c0
/*    34b8c:	24840048 */ 	addiu	$a0,$a0,0x48
/*    34b90:	8fa40074 */ 	lw	$a0,0x74($sp)
/*    34b94:	24050002 */ 	addiu	$a1,$zero,0x2
/*    34b98:	0c00f1f0 */ 	jal	func0003c7c0
/*    34b9c:	24840048 */ 	addiu	$a0,$a0,0x48
/*    34ba0:	8faa0074 */ 	lw	$t2,0x74($sp)
/*    34ba4:	8d490064 */ 	lw	$t1,0x64($t2)
/*    34ba8:	11200011 */ 	beqz	$t1,.L00034bf0
/*    34bac:	afa90058 */ 	sw	$t1,0x58($sp)
.L00034bb0:
/*    34bb0:	8fa50058 */ 	lw	$a1,0x58($sp)
/*    34bb4:	8fa40074 */ 	lw	$a0,0x74($sp)
/*    34bb8:	3406c350 */ 	dli	$a2,0xc350
/*    34bbc:	0c00f52e */ 	jal	func0003d4b8
/*    34bc0:	24a50004 */ 	addiu	$a1,$a1,0x4
/*    34bc4:	10400006 */ 	beqz	$v0,.L00034be0
/*    34bc8:	00000000 */ 	sll	$zero,$zero,0x0
/*    34bcc:	8fa50058 */ 	lw	$a1,0x58($sp)
/*    34bd0:	8fa40074 */ 	lw	$a0,0x74($sp)
/*    34bd4:	3406c350 */ 	dli	$a2,0xc350
/*    34bd8:	0c00f4d0 */ 	jal	func0003d340
/*    34bdc:	24a50004 */ 	addiu	$a1,$a1,0x4
.L00034be0:
/*    34be0:	8fb80058 */ 	lw	$t8,0x58($sp)
/*    34be4:	8f080000 */ 	lw	$t0,0x0($t8)
/*    34be8:	1500fff1 */ 	bnez	$t0,.L00034bb0
/*    34bec:	afa80058 */ 	sw	$t0,0x58($sp)
.L00034bf0:
/*    34bf0:	a3a0004f */ 	sb	$zero,0x4f($sp)
.L00034bf4:
/*    34bf4:	93b9004f */ 	lbu	$t9,0x4f($sp)
/*    34bf8:	8fac0074 */ 	lw	$t4,0x74($sp)
/*    34bfc:	00196880 */ 	sll	$t5,$t9,0x2
/*    34c00:	01b96823 */ 	subu	$t5,$t5,$t9
/*    34c04:	8d8f0060 */ 	lw	$t7,0x60($t4)
/*    34c08:	000d6880 */ 	sll	$t5,$t5,0x2
/*    34c0c:	01b96821 */ 	addu	$t5,$t5,$t9
/*    34c10:	000d6880 */ 	sll	$t5,$t5,0x2
/*    34c14:	01ed7021 */ 	addu	$t6,$t7,$t5
/*    34c18:	91cb000e */ 	lbu	$t3,0xe($t6)
/*    34c1c:	a1cb000d */ 	sb	$t3,0xd($t6)
/*    34c20:	93b8004f */ 	lbu	$t8,0x4f($sp)
/*    34c24:	8faa0074 */ 	lw	$t2,0x74($sp)
/*    34c28:	00184080 */ 	sll	$t0,$t8,0x2
/*    34c2c:	01184023 */ 	subu	$t0,$t0,$t8
/*    34c30:	8d490060 */ 	lw	$t1,0x60($t2)
/*    34c34:	00084080 */ 	sll	$t0,$t0,0x2
/*    34c38:	01184021 */ 	addu	$t0,$t0,$t8
/*    34c3c:	00084080 */ 	sll	$t0,$t0,0x2
/*    34c40:	01286021 */ 	addu	$t4,$t1,$t0
/*    34c44:	9199000d */ 	lbu	$t9,0xd($t4)
/*    34c48:	1720000a */ 	bnez	$t9,.L00034c74
/*    34c4c:	00000000 */ 	sll	$zero,$zero,0x0
/*    34c50:	8faf0074 */ 	lw	$t7,0x74($sp)
/*    34c54:	93ab004f */ 	lbu	$t3,0x4f($sp)
/*    34c58:	240e0001 */ 	addiu	$t6,$zero,0x1
/*    34c5c:	95ed0030 */ 	lhu	$t5,0x30($t7)
/*    34c60:	016e5004 */ 	sllv	$t2,$t6,$t3
/*    34c64:	3958ffff */ 	xori	$t8,$t2,0xffff
/*    34c68:	01b84824 */ 	and	$t1,$t5,$t8
/*    34c6c:	10000008 */ 	beqz	$zero,.L00034c90
/*    34c70:	a5e90030 */ 	sh	$t1,0x30($t7)
.L00034c74:
/*    34c74:	8fa80074 */ 	lw	$t0,0x74($sp)
/*    34c78:	93b9004f */ 	lbu	$t9,0x4f($sp)
/*    34c7c:	240e0001 */ 	addiu	$t6,$zero,0x1
/*    34c80:	950c0030 */ 	lhu	$t4,0x30($t0)
/*    34c84:	032e5804 */ 	sllv	$t3,$t6,$t9
/*    34c88:	018b5025 */ 	or	$t2,$t4,$t3
/*    34c8c:	a50a0030 */ 	sh	$t2,0x30($t0)
.L00034c90:
/*    34c90:	93ad004f */ 	lbu	$t5,0x4f($sp)
/*    34c94:	25b80001 */ 	addiu	$t8,$t5,0x1
/*    34c98:	330900ff */ 	andi	$t1,$t8,0xff
/*    34c9c:	29210010 */ 	slti	$at,$t1,0x10
/*    34ca0:	1420ffd4 */ 	bnez	$at,.L00034bf4
/*    34ca4:	a3b8004f */ 	sb	$t8,0x4f($sp)
/*    34ca8:	8fae0074 */ 	lw	$t6,0x74($sp)
/*    34cac:	240f0002 */ 	addiu	$t7,$zero,0x2
/*    34cb0:	adcf002c */ 	sw	$t7,0x2c($t6)
/*    34cb4:	24190010 */ 	addiu	$t9,$zero,0x10
/*    34cb8:	a7b90064 */ 	sh	$t9,0x64($sp)
/*    34cbc:	8fa40074 */ 	lw	$a0,0x74($sp)
/*    34cc0:	3c067fff */ 	lui	$a2,0x7fff
/*    34cc4:	34c6ffff */ 	ori	$a2,$a2,0xffff
/*    34cc8:	27a50064 */ 	addiu	$a1,$sp,0x64
/*    34ccc:	00003825 */ 	or	$a3,$zero,$zero
/*    34cd0:	0c00f184 */ 	jal	func0003c610
/*    34cd4:	24840048 */ 	addiu	$a0,$a0,0x48
.L00034cd8:
/*    34cd8:	1000002c */ 	beqz	$zero,.L00034d8c
/*    34cdc:	00000000 */ 	sll	$zero,$zero,0x0
/*    34ce0:	8fac0074 */ 	lw	$t4,0x74($sp)
/*    34ce4:	918b003c */ 	lbu	$t3,0x3c($t4)
/*    34ce8:	a3ab004f */ 	sb	$t3,0x4f($sp)
/*    34cec:	93b8004f */ 	lbu	$t8,0x4f($sp)
/*    34cf0:	8faa0074 */ 	lw	$t2,0x74($sp)
/*    34cf4:	00184880 */ 	sll	$t1,$t8,0x2
/*    34cf8:	01384823 */ 	subu	$t1,$t1,$t8
/*    34cfc:	8d4d0060 */ 	lw	$t5,0x60($t2)
/*    34d00:	00094880 */ 	sll	$t1,$t1,0x2
/*    34d04:	9148003d */ 	lbu	$t0,0x3d($t2)
/*    34d08:	01384821 */ 	addu	$t1,$t1,$t8
/*    34d0c:	00094880 */ 	sll	$t1,$t1,0x2
/*    34d10:	01a97821 */ 	addu	$t7,$t5,$t1
/*    34d14:	a1e80008 */ 	sb	$t0,0x8($t7)
/*    34d18:	1000001c */ 	beqz	$zero,.L00034d8c
/*    34d1c:	00000000 */ 	sll	$zero,$zero,0x0
/*    34d20:	8fae0074 */ 	lw	$t6,0x74($sp)
/*    34d24:	8dd9003c */ 	lw	$t9,0x3c($t6)
/*    34d28:	add90018 */ 	sw	$t9,0x18($t6)
/*    34d2c:	8fab0074 */ 	lw	$t3,0x74($sp)
/*    34d30:	340cffff */ 	dli	$t4,0xffff
/*    34d34:	a56c0030 */ 	sh	$t4,0x30($t3)
/*    34d38:	8faa0074 */ 	lw	$t2,0x74($sp)
/*    34d3c:	8d580020 */ 	lw	$t8,0x20($t2)
/*    34d40:	13000005 */ 	beqz	$t8,.L00034d58
/*    34d44:	00000000 */ 	sll	$zero,$zero,0x0
/*    34d48:	8fad0074 */ 	lw	$t5,0x74($sp)
/*    34d4c:	01a02025 */ 	or	$a0,$t5,$zero
/*    34d50:	0c00f6e8 */ 	jal	func0003dba0
/*    34d54:	8da50020 */ 	lw	$a1,0x20($t5)
.L00034d58:
/*    34d58:	1000000c */ 	beqz	$zero,.L00034d8c
/*    34d5c:	00000000 */ 	sll	$zero,$zero,0x0
/*    34d60:	8fa90074 */ 	lw	$t1,0x74($sp)
/*    34d64:	8d28003c */ 	lw	$t0,0x3c($t1)
/*    34d68:	ad280020 */ 	sw	$t0,0x20($t1)
/*    34d6c:	8faf0074 */ 	lw	$t7,0x74($sp)
/*    34d70:	01e02025 */ 	or	$a0,$t7,$zero
/*    34d74:	0c00f6e8 */ 	jal	func0003dba0
/*    34d78:	8de50020 */ 	lw	$a1,0x20($t7)
/*    34d7c:	10000003 */ 	beqz	$zero,.L00034d8c
/*    34d80:	00000000 */ 	sll	$zero,$zero,0x0
/*    34d84:	10000001 */ 	beqz	$zero,.L00034d8c
/*    34d88:	00000000 */ 	sll	$zero,$zero,0x0
.L00034d8c:
/*    34d8c:	8fb90074 */ 	lw	$t9,0x74($sp)
/*    34d90:	27240048 */ 	addiu	$a0,$t9,0x48
/*    34d94:	0c00f15b */ 	jal	func0003c56c
/*    34d98:	27250038 */ 	addiu	$a1,$t9,0x38
/*    34d9c:	8fae0074 */ 	lw	$t6,0x74($sp)
/*    34da0:	adc20028 */ 	sw	$v0,0x28($t6)
/*    34da4:	8fac0074 */ 	lw	$t4,0x74($sp)
/*    34da8:	8d8b0028 */ 	lw	$t3,0x28($t4)
/*    34dac:	1160fdc9 */ 	beqz	$t3,.L000344d4
/*    34db0:	00000000 */ 	sll	$zero,$zero,0x0
/*    34db4:	8faa0074 */ 	lw	$t2,0x74($sp)
/*    34db8:	8d58001c */ 	lw	$t8,0x1c($t2)
/*    34dbc:	8d4d0028 */ 	lw	$t5,0x28($t2)
/*    34dc0:	030d4021 */ 	addu	$t0,$t8,$t5
/*    34dc4:	ad48001c */ 	sw	$t0,0x1c($t2)
/*    34dc8:	8fa90074 */ 	lw	$t1,0x74($sp)
/*    34dcc:	10000003 */ 	beqz	$zero,.L00034ddc
/*    34dd0:	8d220028 */ 	lw	$v0,0x28($t1)
/*    34dd4:	10000001 */ 	beqz	$zero,.L00034ddc
/*    34dd8:	00000000 */ 	sll	$zero,$zero,0x0
.L00034ddc:
/*    34ddc:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*    34de0:	d7b40018 */ 	ldc1	$f20,0x18($sp)
/*    34de4:	8fb00020 */ 	lw	$s0,0x20($sp)
/*    34de8:	8fb10024 */ 	lw	$s1,0x24($sp)
/*    34dec:	8fb20028 */ 	lw	$s2,0x28($sp)
/*    34df0:	03e00008 */ 	jr	$ra
/*    34df4:	27bd0078 */ 	addiu	$sp,$sp,0x78
);

GLOBAL_ASM(
glabel func00034df8
/*    34df8:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*    34dfc:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    34e00:	afa40028 */ 	sw	$a0,0x28($sp)
/*    34e04:	8fae0028 */ 	lw	$t6,0x28($sp)
/*    34e08:	8dcf0018 */ 	lw	$t7,0x18($t6)
/*    34e0c:	15e00003 */ 	bnez	$t7,.L00034e1c
/*    34e10:	00000000 */ 	sll	$zero,$zero,0x0
/*    34e14:	10000039 */ 	beqz	$zero,.L00034efc
/*    34e18:	00000000 */ 	sll	$zero,$zero,0x0
.L00034e1c:
/*    34e1c:	8fb80028 */ 	lw	$t8,0x28($sp)
/*    34e20:	27a50018 */ 	addiu	$a1,$sp,0x18
/*    34e24:	24060001 */ 	addiu	$a2,$zero,0x1
/*    34e28:	0c00e3ac */ 	jal	func00038eb0
/*    34e2c:	8f040018 */ 	lw	$a0,0x18($t8)
/*    34e30:	87b90018 */ 	lh	$t9,0x18($sp)
/*    34e34:	2728ffff */ 	addiu	$t0,$t9,-1
/*    34e38:	2d010014 */ 	sltiu	$at,$t0,0x14
/*    34e3c:	1020002b */ 	beqz	$at,.L00034eec
/*    34e40:	00000000 */ 	sll	$zero,$zero,0x0
/*    34e44:	00084080 */ 	sll	$t0,$t0,0x2
/*    34e48:	3c017005 */ 	lui	$at,%hi(var700547e8)
/*    34e4c:	00280821 */ 	addu	$at,$at,$t0
/*    34e50:	8c2847e8 */ 	lw	$t0,%lo(var700547e8)($at)
/*    34e54:	01000008 */ 	jr	$t0
/*    34e58:	00000000 */ 	sll	$zero,$zero,0x0
/*    34e5c:	8fa40028 */ 	lw	$a0,0x28($sp)
/*    34e60:	0c00d444 */ 	jal	func00035110
/*    34e64:	27a50018 */ 	addiu	$a1,$sp,0x18
/*    34e68:	0c00dd67 */ 	jal	func0003759c
/*    34e6c:	8fa40028 */ 	lw	$a0,0x28($sp)
/*    34e70:	10000020 */ 	beqz	$zero,.L00034ef4
/*    34e74:	00000000 */ 	sll	$zero,$zero,0x0
/*    34e78:	8fa40028 */ 	lw	$a0,0x28($sp)
/*    34e7c:	0c00dc88 */ 	jal	func00037220
/*    34e80:	27a50018 */ 	addiu	$a1,$sp,0x18
/*    34e84:	0c00dd67 */ 	jal	func0003759c
/*    34e88:	8fa40028 */ 	lw	$a0,0x28($sp)
/*    34e8c:	10000019 */ 	beqz	$zero,.L00034ef4
/*    34e90:	00000000 */ 	sll	$zero,$zero,0x0
/*    34e94:	3c098006 */ 	lui	$t1,0x8006
/*    34e98:	8d29f4dc */ 	lw	$t1,-0xb24($t1)
/*    34e9c:	1520000d */ 	bnez	$t1,.L00034ed4
/*    34ea0:	00000000 */ 	sll	$zero,$zero,0x0
/*    34ea4:	8fab0028 */ 	lw	$t3,0x28($sp)
/*    34ea8:	240a0002 */ 	addiu	$t2,$zero,0x2
/*    34eac:	ad6a002c */ 	sw	$t2,0x2c($t3)
/*    34eb0:	240c0010 */ 	addiu	$t4,$zero,0x10
/*    34eb4:	a7ac0018 */ 	sh	$t4,0x18($sp)
/*    34eb8:	8fa40028 */ 	lw	$a0,0x28($sp)
/*    34ebc:	3c067fff */ 	lui	$a2,0x7fff
/*    34ec0:	34c6ffff */ 	ori	$a2,$a2,0xffff
/*    34ec4:	27a50018 */ 	addiu	$a1,$sp,0x18
/*    34ec8:	00003825 */ 	or	$a3,$zero,$zero
/*    34ecc:	0c00f184 */ 	jal	func0003c610
/*    34ed0:	24840048 */ 	addiu	$a0,$a0,0x48
.L00034ed4:
/*    34ed4:	10000007 */ 	beqz	$zero,.L00034ef4
/*    34ed8:	00000000 */ 	sll	$zero,$zero,0x0
/*    34edc:	0c00dd67 */ 	jal	func0003759c
/*    34ee0:	8fa40028 */ 	lw	$a0,0x28($sp)
/*    34ee4:	10000003 */ 	beqz	$zero,.L00034ef4
/*    34ee8:	00000000 */ 	sll	$zero,$zero,0x0
.L00034eec:
/*    34eec:	10000001 */ 	beqz	$zero,.L00034ef4
/*    34ef0:	00000000 */ 	sll	$zero,$zero,0x0
.L00034ef4:
/*    34ef4:	10000001 */ 	beqz	$zero,.L00034efc
/*    34ef8:	00000000 */ 	sll	$zero,$zero,0x0
.L00034efc:
/*    34efc:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    34f00:	27bd0028 */ 	addiu	$sp,$sp,0x28
/*    34f04:	03e00008 */ 	jr	$ra
/*    34f08:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func00034f0c
/*    34f0c:	27bdffd0 */ 	addiu	$sp,$sp,-48
/*    34f10:	afbf001c */ 	sw	$ra,0x1c($sp)
/*    34f14:	afa40030 */ 	sw	$a0,0x30($sp)
/*    34f18:	afa50034 */ 	sw	$a1,0x34($sp)
/*    34f1c:	afb00018 */ 	sw	$s0,0x18($sp)
/*    34f20:	8fae0030 */ 	lw	$t6,0x30($sp)
/*    34f24:	8dcf0064 */ 	lw	$t7,0x64($t6)
/*    34f28:	11e0001c */ 	beqz	$t7,.L00034f9c
/*    34f2c:	afaf002c */ 	sw	$t7,0x2c($sp)
.L00034f30:
/*    34f30:	8fb8002c */ 	lw	$t8,0x2c($sp)
/*    34f34:	93a80037 */ 	lbu	$t0,0x37($sp)
/*    34f38:	93190031 */ 	lbu	$t9,0x31($t8)
/*    34f3c:	17280013 */ 	bne	$t9,$t0,.L00034f8c
/*    34f40:	00000000 */ 	sll	$zero,$zero,0x0
/*    34f44:	93090034 */ 	lbu	$t1,0x34($t8)
/*    34f48:	24010003 */ 	addiu	$at,$zero,0x3
/*    34f4c:	1121000f */ 	beq	$t1,$at,.L00034f8c
/*    34f50:	00000000 */ 	sll	$zero,$zero,0x0
/*    34f54:	8fa4002c */ 	lw	$a0,0x2c($sp)
/*    34f58:	0c00f629 */ 	jal	func0003d8a4
/*    34f5c:	8fa50030 */ 	lw	$a1,0x30($sp)
/*    34f60:	a7a2002a */ 	sh	$v0,0x2a($sp)
/*    34f64:	8faa0030 */ 	lw	$t2,0x30($sp)
/*    34f68:	8fa4002c */ 	lw	$a0,0x2c($sp)
/*    34f6c:	0c00f6b4 */ 	jal	func0003dad0
/*    34f70:	8d45001c */ 	lw	$a1,0x1c($t2)
/*    34f74:	8fa4002c */ 	lw	$a0,0x2c($sp)
/*    34f78:	00408025 */ 	or	$s0,$v0,$zero
/*    34f7c:	02003025 */ 	or	$a2,$s0,$zero
/*    34f80:	87a5002a */ 	lh	$a1,0x2a($sp)
/*    34f84:	0c00f33c */ 	jal	func0003ccf0
/*    34f88:	24840004 */ 	addiu	$a0,$a0,0x4
.L00034f8c:
/*    34f8c:	8fab002c */ 	lw	$t3,0x2c($sp)
/*    34f90:	8d6c0000 */ 	lw	$t4,0x0($t3)
/*    34f94:	1580ffe6 */ 	bnez	$t4,.L00034f30
/*    34f98:	afac002c */ 	sw	$t4,0x2c($sp)
.L00034f9c:
/*    34f9c:	10000001 */ 	beqz	$zero,.L00034fa4
/*    34fa0:	00000000 */ 	sll	$zero,$zero,0x0
.L00034fa4:
/*    34fa4:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*    34fa8:	8fb00018 */ 	lw	$s0,0x18($sp)
/*    34fac:	27bd0030 */ 	addiu	$sp,$sp,0x30
/*    34fb0:	03e00008 */ 	jr	$ra
/*    34fb4:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func00034fb8
/*    34fb8:	27bdffd0 */ 	addiu	$sp,$sp,-48
/*    34fbc:	afbf001c */ 	sw	$ra,0x1c($sp)
/*    34fc0:	afa40030 */ 	sw	$a0,0x30($sp)
/*    34fc4:	afa50034 */ 	sw	$a1,0x34($sp)
/*    34fc8:	f7b40010 */ 	sdc1	$f20,0x10($sp)
/*    34fcc:	93b80037 */ 	lbu	$t8,0x37($sp)
/*    34fd0:	8fae0030 */ 	lw	$t6,0x30($sp)
/*    34fd4:	0018c880 */ 	sll	$t9,$t8,0x2
/*    34fd8:	0338c823 */ 	subu	$t9,$t9,$t8
/*    34fdc:	8dcf0060 */ 	lw	$t7,0x60($t6)
/*    34fe0:	0019c880 */ 	sll	$t9,$t9,0x2
/*    34fe4:	0338c821 */ 	addu	$t9,$t9,$t8
/*    34fe8:	0019c880 */ 	sll	$t9,$t9,0x2
/*    34fec:	01f94021 */ 	addu	$t0,$t7,$t9
/*    34ff0:	81090012 */ 	lb	$t1,0x12($t0)
/*    34ff4:	252affc0 */ 	addiu	$t2,$t1,-64
/*    34ff8:	a3aa0029 */ 	sb	$t2,0x29($sp)
/*    34ffc:	93ad0037 */ 	lbu	$t5,0x37($sp)
/*    35000:	8fab0030 */ 	lw	$t3,0x30($sp)
/*    35004:	000d7080 */ 	sll	$t6,$t5,0x2
/*    35008:	01cd7023 */ 	subu	$t6,$t6,$t5
/*    3500c:	8d6c0060 */ 	lw	$t4,0x60($t3)
/*    35010:	000e7080 */ 	sll	$t6,$t6,0x2
/*    35014:	01cd7021 */ 	addu	$t6,$t6,$t5
/*    35018:	000e7080 */ 	sll	$t6,$t6,0x2
/*    3501c:	018ec021 */ 	addu	$t8,$t4,$t6
/*    35020:	c7040014 */ 	lwc1	$f4,0x14($t8)
/*    35024:	e7a40024 */ 	swc1	$f4,0x24($sp)
/*    35028:	8faf0030 */ 	lw	$t7,0x30($sp)
/*    3502c:	8df90064 */ 	lw	$t9,0x64($t7)
/*    35030:	13200030 */ 	beqz	$t9,.L000350f4
/*    35034:	afb9002c */ 	sw	$t9,0x2c($sp)
.L00035038:
/*    35038:	8fa8002c */ 	lw	$t0,0x2c($sp)
/*    3503c:	93aa0037 */ 	lbu	$t2,0x37($sp)
/*    35040:	91090031 */ 	lbu	$t1,0x31($t0)
/*    35044:	152a0027 */ 	bne	$t1,$t2,.L000350e4
/*    35048:	00000000 */ 	sll	$zero,$zero,0x0
/*    3504c:	93ac0037 */ 	lbu	$t4,0x37($sp)
/*    35050:	8fab0030 */ 	lw	$t3,0x30($sp)
/*    35054:	000c7080 */ 	sll	$t6,$t4,0x2
/*    35058:	01cc7023 */ 	subu	$t6,$t6,$t4
/*    3505c:	8d6d0060 */ 	lw	$t5,0x60($t3)
/*    35060:	000e7080 */ 	sll	$t6,$t6,0x2
/*    35064:	01cc7021 */ 	addu	$t6,$t6,$t4
/*    35068:	000e7080 */ 	sll	$t6,$t6,0x2
/*    3506c:	01aec021 */ 	addu	$t8,$t5,$t6
/*    35070:	930f0011 */ 	lbu	$t7,0x11($t8)
/*    35074:	a7af002a */ 	sh	$t7,0x2a($sp)
/*    35078:	8fa4002c */ 	lw	$a0,0x2c($sp)
/*    3507c:	87a5002a */ 	lh	$a1,0x2a($sp)
/*    35080:	0c00f924 */ 	jal	func0003e490
/*    35084:	24840004 */ 	addiu	$a0,$a0,0x4
/*    35088:	87b9002a */ 	lh	$t9,0x2a($sp)
/*    3508c:	13200015 */ 	beqz	$t9,.L000350e4
/*    35090:	00000000 */ 	sll	$zero,$zero,0x0
/*    35094:	8fa8002c */ 	lw	$t0,0x2c($sp)
/*    35098:	83ae0029 */ 	lb	$t6,0x29($sp)
/*    3509c:	8d0a0020 */ 	lw	$t2,0x20($t0)
/*    350a0:	91090032 */ 	lbu	$t1,0x32($t0)
/*    350a4:	8d4b0004 */ 	lw	$t3,0x4($t2)
/*    350a8:	916c0004 */ 	lbu	$t4,0x4($t3)
/*    350ac:	012c6823 */ 	subu	$t5,$t1,$t4
/*    350b0:	0c00ee75 */ 	jal	func0003b9d4
/*    350b4:	01ae2021 */ 	addu	$a0,$t5,$t6
/*    350b8:	3c0143dc */ 	lui	$at,0x43dc
/*    350bc:	44813000 */ 	mtc1	$at,$f6
/*    350c0:	46000506 */ 	mov.s	$f20,$f0
/*    350c4:	c7aa0024 */ 	lwc1	$f10,0x24($sp)
/*    350c8:	4606a202 */ 	mul.s	$f8,$f20,$f6
/*    350cc:	8fa4002c */ 	lw	$a0,0x2c($sp)
/*    350d0:	24840004 */ 	addiu	$a0,$a0,0x4
/*    350d4:	460a4402 */ 	mul.s	$f16,$f8,$f10
/*    350d8:	44058000 */ 	mfc1	$a1,$f16
/*    350dc:	0c00f8f8 */ 	jal	func0003e3e0
/*    350e0:	00000000 */ 	sll	$zero,$zero,0x0
.L000350e4:
/*    350e4:	8fb8002c */ 	lw	$t8,0x2c($sp)
/*    350e8:	8f0f0000 */ 	lw	$t7,0x0($t8)
/*    350ec:	15e0ffd2 */ 	bnez	$t7,.L00035038
/*    350f0:	afaf002c */ 	sw	$t7,0x2c($sp)
.L000350f4:
/*    350f4:	10000001 */ 	beqz	$zero,.L000350fc
/*    350f8:	00000000 */ 	sll	$zero,$zero,0x0
.L000350fc:
/*    350fc:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*    35100:	d7b40010 */ 	ldc1	$f20,0x10($sp)
/*    35104:	27bd0030 */ 	addiu	$sp,$sp,0x30
/*    35108:	03e00008 */ 	jr	$ra
/*    3510c:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func00035110
/*    35110:	27bdff30 */ 	addiu	$sp,$sp,-208
/*    35114:	afbf003c */ 	sw	$ra,0x3c($sp)
/*    35118:	afa400d0 */ 	sw	$a0,0xd0($sp)
/*    3511c:	afa500d4 */ 	sw	$a1,0xd4($sp)
/*    35120:	afb10038 */ 	sw	$s1,0x38($sp)
/*    35124:	afb00034 */ 	sw	$s0,0x34($sp)
/*    35128:	f7b40028 */ 	sdc1	$f20,0x28($sp)
/*    3512c:	8fae00d4 */ 	lw	$t6,0xd4($sp)
/*    35130:	25cf0004 */ 	addiu	$t7,$t6,0x4
/*    35134:	afaf00b8 */ 	sw	$t7,0xb8($sp)
/*    35138:	8fb800b8 */ 	lw	$t8,0xb8($sp)
/*    3513c:	93190004 */ 	lbu	$t9,0x4($t8)
/*    35140:	332800f0 */ 	andi	$t0,$t9,0xf0
/*    35144:	afa800c4 */ 	sw	$t0,0xc4($sp)
/*    35148:	8fa900b8 */ 	lw	$t1,0xb8($sp)
/*    3514c:	912a0004 */ 	lbu	$t2,0x4($t1)
/*    35150:	314b000f */ 	andi	$t3,$t2,0xf
/*    35154:	a3ab00c3 */ 	sb	$t3,0xc3($sp)
/*    35158:	8fac00b8 */ 	lw	$t4,0xb8($sp)
/*    3515c:	918d0005 */ 	lbu	$t5,0x5($t4)
/*    35160:	a3ad00c2 */ 	sb	$t5,0xc2($sp)
/*    35164:	a3ad00c0 */ 	sb	$t5,0xc0($sp)
/*    35168:	8fae00b8 */ 	lw	$t6,0xb8($sp)
/*    3516c:	91cf0006 */ 	lbu	$t7,0x6($t6)
/*    35170:	a3af00c1 */ 	sb	$t7,0xc1($sp)
/*    35174:	a3af00bf */ 	sb	$t7,0xbf($sp)
/*    35178:	8fb800c4 */ 	lw	$t8,0xc4($sp)
/*    3517c:	2719ff80 */ 	addiu	$t9,$t8,-128
/*    35180:	2f210061 */ 	sltiu	$at,$t9,0x61
/*    35184:	1020081c */ 	beqz	$at,.L000371f8
/*    35188:	00000000 */ 	sll	$zero,$zero,0x0
/*    3518c:	0019c880 */ 	sll	$t9,$t9,0x2
/*    35190:	3c017005 */ 	lui	$at,%hi(var70054838)
/*    35194:	00390821 */ 	addu	$at,$at,$t9
/*    35198:	8c394838 */ 	lw	$t9,%lo(var70054838)($at)
/*    3519c:	03200008 */ 	jr	$t9
/*    351a0:	00000000 */ 	sll	$zero,$zero,0x0
/*    351a4:	93a800c1 */ 	lbu	$t0,0xc1($sp)
/*    351a8:	11000226 */ 	beqz	$t0,.L00035a44
/*    351ac:	00000000 */ 	sll	$zero,$zero,0x0
/*    351b0:	afa0006c */ 	sw	$zero,0x6c($sp)
/*    351b4:	8fa900d0 */ 	lw	$t1,0xd0($sp)
/*    351b8:	24010001 */ 	addiu	$at,$zero,0x1
/*    351bc:	8d2a002c */ 	lw	$t2,0x2c($t1)
/*    351c0:	15410008 */ 	bne	$t2,$at,.L000351e4
/*    351c4:	00000000 */ 	sll	$zero,$zero,0x0
/*    351c8:	93ac00c3 */ 	lbu	$t4,0xc3($sp)
/*    351cc:	952b0030 */ 	lhu	$t3,0x30($t1)
/*    351d0:	240d0001 */ 	addiu	$t5,$zero,0x1
/*    351d4:	018d7004 */ 	sllv	$t6,$t5,$t4
/*    351d8:	016e7824 */ 	and	$t7,$t3,$t6
/*    351dc:	15e00023 */ 	bnez	$t7,.L0003526c
/*    351e0:	00000000 */ 	sll	$zero,$zero,0x0
.L000351e4:
/*    351e4:	8fb800b8 */ 	lw	$t8,0xb8($sp)
/*    351e8:	8f190008 */ 	lw	$t9,0x8($t8)
/*    351ec:	1320001d */ 	beqz	$t9,.L00035264
/*    351f0:	00000000 */ 	sll	$zero,$zero,0x0
/*    351f4:	24080015 */ 	addiu	$t0,$zero,0x15
/*    351f8:	a7a800a4 */ 	sh	$t0,0xa4($sp)
/*    351fc:	93aa00c3 */ 	lbu	$t2,0xc3($sp)
/*    35200:	35490080 */ 	ori	$t1,$t2,0x80
/*    35204:	a3a900ac */ 	sb	$t1,0xac($sp)
/*    35208:	93ad00c2 */ 	lbu	$t5,0xc2($sp)
/*    3520c:	a3ad00ad */ 	sb	$t5,0xad($sp)
/*    35210:	a3a000ae */ 	sb	$zero,0xae($sp)
/*    35214:	8fac00d0 */ 	lw	$t4,0xd0($sp)
/*    35218:	8fae00b8 */ 	lw	$t6,0xb8($sp)
/*    3521c:	8d8b0024 */ 	lw	$t3,0x24($t4)
/*    35220:	8dcf0008 */ 	lw	$t7,0x8($t6)
/*    35224:	016f0019 */ 	multu	$t3,$t7
/*    35228:	0000c012 */ 	mflo	$t8
/*    3522c:	afb800a0 */ 	sw	$t8,0xa0($sp)
/*    35230:	00000000 */ 	sll	$zero,$zero,0x0
/*    35234:	93a800c3 */ 	lbu	$t0,0xc3($sp)
/*    35238:	8fb900a0 */ 	lw	$t9,0xa0($sp)
/*    3523c:	3c01800a */ 	lui	$at,0x800a
/*    35240:	00085080 */ 	sll	$t2,$t0,0x2
/*    35244:	002a0821 */ 	addu	$at,$at,$t2
/*    35248:	ac39c350 */ 	sw	$t9,-0x3cb0($at)
/*    3524c:	8fa400d0 */ 	lw	$a0,0xd0($sp)
/*    35250:	27a500a4 */ 	addiu	$a1,$sp,0xa4
/*    35254:	8fa600a0 */ 	lw	$a2,0xa0($sp)
/*    35258:	00003825 */ 	or	$a3,$zero,$zero
/*    3525c:	0c00f184 */ 	jal	func0003c610
/*    35260:	24840048 */ 	addiu	$a0,$a0,0x48
.L00035264:
/*    35264:	100007e6 */ 	beqz	$zero,.L00037200
/*    35268:	00000000 */ 	sll	$zero,$zero,0x0
.L0003526c:
/*    3526c:	93ac00c3 */ 	lbu	$t4,0xc3($sp)
/*    35270:	8fa900d0 */ 	lw	$t1,0xd0($sp)
/*    35274:	000c7080 */ 	sll	$t6,$t4,0x2
/*    35278:	01cc7023 */ 	subu	$t6,$t6,$t4
/*    3527c:	8d2d0060 */ 	lw	$t5,0x60($t1)
/*    35280:	000e7080 */ 	sll	$t6,$t6,0x2
/*    35284:	01cc7021 */ 	addu	$t6,$t6,$t4
/*    35288:	000e7080 */ 	sll	$t6,$t6,0x2
/*    3528c:	01ae5821 */ 	addu	$t3,$t5,$t6
/*    35290:	afab0094 */ 	sw	$t3,0x94($sp)
/*    35294:	8fa400d0 */ 	lw	$a0,0xd0($sp)
/*    35298:	93a500c2 */ 	lbu	$a1,0xc2($sp)
/*    3529c:	93a600c1 */ 	lbu	$a2,0xc1($sp)
/*    352a0:	0c00f5cb */ 	jal	func0003d72c
/*    352a4:	93a700c3 */ 	lbu	$a3,0xc3($sp)
/*    352a8:	afa20084 */ 	sw	$v0,0x84($sp)
/*    352ac:	8faf0084 */ 	lw	$t7,0x84($sp)
/*    352b0:	15e00003 */ 	bnez	$t7,.L000352c0
/*    352b4:	00000000 */ 	sll	$zero,$zero,0x0
/*    352b8:	100007d3 */ 	beqz	$zero,.L00037208
/*    352bc:	00000000 */ 	sll	$zero,$zero,0x0
.L000352c0:
/*    352c0:	8fb80094 */ 	lw	$t8,0x94($sp)
/*    352c4:	93080008 */ 	lbu	$t0,0x8($t8)
/*    352c8:	a7a80088 */ 	sh	$t0,0x88($sp)
/*    352cc:	8fb90094 */ 	lw	$t9,0x94($sp)
/*    352d0:	932a000b */ 	lbu	$t2,0xb($t9)
/*    352d4:	a7aa008a */ 	sh	$t2,0x8a($sp)
/*    352d8:	a3a0008c */ 	sb	$zero,0x8c($sp)
/*    352dc:	8fa400d0 */ 	lw	$a0,0xd0($sp)
/*    352e0:	93a500c2 */ 	lbu	$a1,0xc2($sp)
/*    352e4:	93a600c1 */ 	lbu	$a2,0xc1($sp)
/*    352e8:	0c00f576 */ 	jal	func0003d5d8
/*    352ec:	93a700c3 */ 	lbu	$a3,0xc3($sp)
/*    352f0:	afa2009c */ 	sw	$v0,0x9c($sp)
/*    352f4:	8fa9009c */ 	lw	$t1,0x9c($sp)
/*    352f8:	15200003 */ 	bnez	$t1,.L00035308
/*    352fc:	00000000 */ 	sll	$zero,$zero,0x0
/*    35300:	100007c1 */ 	beqz	$zero,.L00037208
/*    35304:	00000000 */ 	sll	$zero,$zero,0x0
.L00035308:
/*    35308:	8fac009c */ 	lw	$t4,0x9c($sp)
/*    3530c:	258d0004 */ 	addiu	$t5,$t4,0x4
/*    35310:	afad00cc */ 	sw	$t5,0xcc($sp)
/*    35314:	8fa400cc */ 	lw	$a0,0xcc($sp)
/*    35318:	0c00f278 */ 	jal	func0003c9e0
/*    3531c:	27a50088 */ 	addiu	$a1,$sp,0x88
/*    35320:	8fae0084 */ 	lw	$t6,0x84($sp)
/*    35324:	8fab009c */ 	lw	$t3,0x9c($sp)
/*    35328:	ad6e0020 */ 	sw	$t6,0x20($t3)
/*    3532c:	8faf009c */ 	lw	$t7,0x9c($sp)
/*    35330:	a1e00034 */ 	sb	$zero,0x34($t7)
/*    35334:	8fb80094 */ 	lw	$t8,0x94($sp)
/*    35338:	9308000c */ 	lbu	$t0,0xc($t8)
/*    3533c:	29010040 */ 	slti	$at,$t0,0x40
/*    35340:	14200005 */ 	bnez	$at,.L00035358
/*    35344:	00000000 */ 	sll	$zero,$zero,0x0
/*    35348:	8faa009c */ 	lw	$t2,0x9c($sp)
/*    3534c:	24190002 */ 	addiu	$t9,$zero,0x2
/*    35350:	10000003 */ 	beqz	$zero,.L00035360
/*    35354:	a1590035 */ 	sb	$t9,0x35($t2)
.L00035358:
/*    35358:	8fa9009c */ 	lw	$t1,0x9c($sp)
/*    3535c:	a1200035 */ 	sb	$zero,0x35($t1)
.L00035360:
/*    35360:	8fad0084 */ 	lw	$t5,0x84($sp)
/*    35364:	93ac00c2 */ 	lbu	$t4,0xc2($sp)
/*    35368:	8dae0004 */ 	lw	$t6,0x4($t5)
/*    3536c:	91cb0004 */ 	lbu	$t3,0x4($t6)
/*    35370:	81c80005 */ 	lb	$t0,0x5($t6)
/*    35374:	018b7823 */ 	subu	$t7,$t4,$t3
/*    35378:	000fc080 */ 	sll	$t8,$t7,0x2
/*    3537c:	030fc023 */ 	subu	$t8,$t8,$t7
/*    35380:	0018c0c0 */ 	sll	$t8,$t8,0x3
/*    35384:	030fc021 */ 	addu	$t8,$t8,$t7
/*    35388:	0018c080 */ 	sll	$t8,$t8,0x2
/*    3538c:	0308c821 */ 	addu	$t9,$t8,$t0
/*    35390:	a7b90082 */ 	sh	$t9,0x82($sp)
/*    35394:	8faa0094 */ 	lw	$t2,0x94($sp)
/*    35398:	91490024 */ 	lbu	$t1,0x24($t2)
/*    3539c:	11200006 */ 	beqz	$t1,.L000353b8
/*    353a0:	00000000 */ 	sll	$zero,$zero,0x0
/*    353a4:	8fac0094 */ 	lw	$t4,0x94($sp)
/*    353a8:	87ad0082 */ 	lh	$t5,0x82($sp)
/*    353ac:	818b0027 */ 	lb	$t3,0x27($t4)
/*    353b0:	01ab7821 */ 	addu	$t7,$t5,$t3
/*    353b4:	a7af0082 */ 	sh	$t7,0x82($sp)
.L000353b8:
/*    353b8:	0c00e7f8 */ 	jal	func00039fe0
/*    353bc:	87a40082 */ 	lh	$a0,0x82($sp)
/*    353c0:	8fae009c */ 	lw	$t6,0x9c($sp)
/*    353c4:	e5c00028 */ 	swc1	$f0,0x28($t6)
/*    353c8:	8fb80094 */ 	lw	$t8,0x94($sp)
/*    353cc:	93080024 */ 	lbu	$t0,0x24($t8)
/*    353d0:	1100000d */ 	beqz	$t0,.L00035408
/*    353d4:	00000000 */ 	sll	$zero,$zero,0x0
/*    353d8:	8fb90094 */ 	lw	$t9,0x94($sp)
/*    353dc:	8fa9009c */ 	lw	$t1,0x9c($sp)
/*    353e0:	932a0025 */ 	lbu	$t2,0x25($t9)
/*    353e4:	a12a0030 */ 	sb	$t2,0x30($t1)
/*    353e8:	8fac00d0 */ 	lw	$t4,0xd0($sp)
/*    353ec:	8fab0094 */ 	lw	$t3,0x94($sp)
/*    353f0:	8fb8009c */ 	lw	$t8,0x9c($sp)
/*    353f4:	8d8d001c */ 	lw	$t5,0x1c($t4)
/*    353f8:	8d6f0018 */ 	lw	$t7,0x18($t3)
/*    353fc:	01af7021 */ 	addu	$t6,$t5,$t7
/*    35400:	1000000e */ 	beqz	$zero,.L0003543c
/*    35404:	af0e0024 */ 	sw	$t6,0x24($t8)
.L00035408:
/*    35408:	8fa80084 */ 	lw	$t0,0x84($sp)
/*    3540c:	8fa9009c */ 	lw	$t1,0x9c($sp)
/*    35410:	8d190000 */ 	lw	$t9,0x0($t0)
/*    35414:	932a000c */ 	lbu	$t2,0xc($t9)
/*    35418:	a12a0030 */ 	sb	$t2,0x30($t1)
/*    3541c:	8fad0084 */ 	lw	$t5,0x84($sp)
/*    35420:	8fac00d0 */ 	lw	$t4,0xd0($sp)
/*    35424:	8fa8009c */ 	lw	$t0,0x9c($sp)
/*    35428:	8daf0000 */ 	lw	$t7,0x0($t5)
/*    3542c:	8d8b001c */ 	lw	$t3,0x1c($t4)
/*    35430:	8dee0000 */ 	lw	$t6,0x0($t7)
/*    35434:	016ec021 */ 	addu	$t8,$t3,$t6
/*    35438:	ad180024 */ 	sw	$t8,0x24($t0)
.L0003543c:
/*    3543c:	8fb9009c */ 	lw	$t9,0x9c($sp)
/*    35440:	a3200037 */ 	sb	$zero,0x37($t9)
/*    35444:	8faa0094 */ 	lw	$t2,0x94($sp)
/*    35448:	91490024 */ 	lbu	$t1,0x24($t2)
/*    3544c:	11200005 */ 	beqz	$t1,.L00035464
/*    35450:	00000000 */ 	sll	$zero,$zero,0x0
/*    35454:	8fac0094 */ 	lw	$t4,0x94($sp)
/*    35458:	918d0028 */ 	lbu	$t5,0x28($t4)
/*    3545c:	1000000f */ 	beqz	$zero,.L0003549c
/*    35460:	afad0090 */ 	sw	$t5,0x90($sp)
.L00035464:
/*    35464:	93ae00c3 */ 	lbu	$t6,0xc3($sp)
/*    35468:	8faf00d0 */ 	lw	$t7,0xd0($sp)
/*    3546c:	000ec080 */ 	sll	$t8,$t6,0x2
/*    35470:	030ec023 */ 	subu	$t8,$t8,$t6
/*    35474:	8deb0060 */ 	lw	$t3,0x60($t7)
/*    35478:	0018c080 */ 	sll	$t8,$t8,0x2
/*    3547c:	030ec021 */ 	addu	$t8,$t8,$t6
/*    35480:	0018c080 */ 	sll	$t8,$t8,0x2
/*    35484:	01784021 */ 	addu	$t0,$t3,$t8
/*    35488:	8d190000 */ 	lw	$t9,0x0($t0)
/*    3548c:	afb90068 */ 	sw	$t9,0x68($sp)
/*    35490:	8faa0068 */ 	lw	$t2,0x68($sp)
/*    35494:	91490004 */ 	lbu	$t1,0x4($t2)
/*    35498:	afa90090 */ 	sw	$t1,0x90($sp)
.L0003549c:
/*    3549c:	3c0142fe */ 	lui	$at,0x42fe
/*    354a0:	44812000 */ 	mtc1	$at,$f4
/*    354a4:	00000000 */ 	sll	$zero,$zero,0x0
/*    354a8:	e7a40078 */ 	swc1	$f4,0x78($sp)
/*    354ac:	8fac0090 */ 	lw	$t4,0x90($sp)
/*    354b0:	11800041 */ 	beqz	$t4,.L000355b8
/*    354b4:	00000000 */ 	sll	$zero,$zero,0x0
/*    354b8:	8fad00d0 */ 	lw	$t5,0xd0($sp)
/*    354bc:	8daf0070 */ 	lw	$t7,0x70($t5)
/*    354c0:	11e0003d */ 	beqz	$t7,.L000355b8
/*    354c4:	00000000 */ 	sll	$zero,$zero,0x0
/*    354c8:	8fae0094 */ 	lw	$t6,0x94($sp)
/*    354cc:	91cb0024 */ 	lbu	$t3,0x24($t6)
/*    354d0:	11600012 */ 	beqz	$t3,.L0003551c
/*    354d4:	00000000 */ 	sll	$zero,$zero,0x0
/*    354d8:	8fb80094 */ 	lw	$t8,0x94($sp)
/*    354dc:	8fa900d0 */ 	lw	$t1,0xd0($sp)
/*    354e0:	27a4006c */ 	addiu	$a0,$sp,0x6c
/*    354e4:	9308002a */ 	lbu	$t0,0x2a($t8)
/*    354e8:	93060028 */ 	lbu	$a2,0x28($t8)
/*    354ec:	93070029 */ 	lbu	$a3,0x29($t8)
/*    354f0:	afa80010 */ 	sw	$t0,0x10($sp)
/*    354f4:	9319002b */ 	lbu	$t9,0x2b($t8)
/*    354f8:	27a50078 */ 	addiu	$a1,$sp,0x78
/*    354fc:	afb90014 */ 	sw	$t9,0x14($sp)
/*    35500:	930a0031 */ 	lbu	$t2,0x31($t8)
/*    35504:	afaa0018 */ 	sw	$t2,0x18($sp)
/*    35508:	8d390070 */ 	lw	$t9,0x70($t1)
/*    3550c:	0320f809 */ 	jalr	$t9
/*    35510:	00000000 */ 	sll	$zero,$zero,0x0
/*    35514:	10000012 */ 	beqz	$zero,.L00035560
/*    35518:	afa200a0 */ 	sw	$v0,0xa0($sp)
.L0003551c:
/*    3551c:	8fac0068 */ 	lw	$t4,0x68($sp)
/*    35520:	8fae0094 */ 	lw	$t6,0x94($sp)
/*    35524:	8fa800d0 */ 	lw	$t0,0xd0($sp)
/*    35528:	918d0006 */ 	lbu	$t5,0x6($t4)
/*    3552c:	91860004 */ 	lbu	$a2,0x4($t4)
/*    35530:	91870005 */ 	lbu	$a3,0x5($t4)
/*    35534:	afad0010 */ 	sw	$t5,0x10($sp)
/*    35538:	918f0007 */ 	lbu	$t7,0x7($t4)
/*    3553c:	27a4006c */ 	addiu	$a0,$sp,0x6c
/*    35540:	27a50078 */ 	addiu	$a1,$sp,0x78
/*    35544:	afaf0014 */ 	sw	$t7,0x14($sp)
/*    35548:	91cb0031 */ 	lbu	$t3,0x31($t6)
/*    3554c:	afab0018 */ 	sw	$t3,0x18($sp)
/*    35550:	8d190070 */ 	lw	$t9,0x70($t0)
/*    35554:	0320f809 */ 	jalr	$t9
/*    35558:	00000000 */ 	sll	$zero,$zero,0x0
/*    3555c:	afa200a0 */ 	sw	$v0,0xa0($sp)
.L00035560:
/*    35560:	8fb800a0 */ 	lw	$t8,0xa0($sp)
/*    35564:	13000014 */ 	beqz	$t8,.L000355b8
/*    35568:	00000000 */ 	sll	$zero,$zero,0x0
/*    3556c:	240a0016 */ 	addiu	$t2,$zero,0x16
/*    35570:	a7aa00a4 */ 	sh	$t2,0xa4($sp)
/*    35574:	8fa9009c */ 	lw	$t1,0x9c($sp)
/*    35578:	afa900a8 */ 	sw	$t1,0xa8($sp)
/*    3557c:	8fad006c */ 	lw	$t5,0x6c($sp)
/*    35580:	afad00ac */ 	sw	$t5,0xac($sp)
/*    35584:	8fa400d0 */ 	lw	$a0,0xd0($sp)
/*    35588:	27a500a4 */ 	addiu	$a1,$sp,0xa4
/*    3558c:	8fa600a0 */ 	lw	$a2,0xa0($sp)
/*    35590:	00003825 */ 	or	$a3,$zero,$zero
/*    35594:	0c00f184 */ 	jal	func0003c610
/*    35598:	24840048 */ 	addiu	$a0,$a0,0x48
/*    3559c:	8fac009c */ 	lw	$t4,0x9c($sp)
/*    355a0:	918f0037 */ 	lbu	$t7,0x37($t4)
/*    355a4:	35ee0001 */ 	ori	$t6,$t7,0x1
/*    355a8:	a18e0037 */ 	sb	$t6,0x37($t4)
/*    355ac:	8fab006c */ 	lw	$t3,0x6c($sp)
/*    355b0:	8fa8009c */ 	lw	$t0,0x9c($sp)
/*    355b4:	ad0b0038 */ 	sw	$t3,0x38($t0)
.L000355b8:
/*    355b8:	4459f800 */ 	cfc1	$t9,$31
/*    355bc:	24180001 */ 	addiu	$t8,$zero,0x1
/*    355c0:	44d8f800 */ 	ctc1	$t8,$31
/*    355c4:	c7a60078 */ 	lwc1	$f6,0x78($sp)
/*    355c8:	46003224 */ 	cvt.w.s	$f8,$f6
/*    355cc:	4458f800 */ 	cfc1	$t8,$31
/*    355d0:	00000000 */ 	sll	$zero,$zero,0x0
/*    355d4:	33010004 */ 	andi	$at,$t8,0x4
/*    355d8:	33180078 */ 	andi	$t8,$t8,0x78
/*    355dc:	13000014 */ 	beqz	$t8,.L00035630
/*    355e0:	00000000 */ 	sll	$zero,$zero,0x0
/*    355e4:	3c014f00 */ 	lui	$at,0x4f00
/*    355e8:	44814000 */ 	mtc1	$at,$f8
/*    355ec:	24180001 */ 	addiu	$t8,$zero,0x1
/*    355f0:	46083201 */ 	sub.s	$f8,$f6,$f8
/*    355f4:	44d8f800 */ 	ctc1	$t8,$31
/*    355f8:	00000000 */ 	sll	$zero,$zero,0x0
/*    355fc:	46004224 */ 	cvt.w.s	$f8,$f8
/*    35600:	4458f800 */ 	cfc1	$t8,$31
/*    35604:	00000000 */ 	sll	$zero,$zero,0x0
/*    35608:	33010004 */ 	andi	$at,$t8,0x4
/*    3560c:	33180078 */ 	andi	$t8,$t8,0x78
/*    35610:	17000005 */ 	bnez	$t8,.L00035628
/*    35614:	00000000 */ 	sll	$zero,$zero,0x0
/*    35618:	44184000 */ 	mfc1	$t8,$f8
/*    3561c:	3c018000 */ 	lui	$at,0x8000
/*    35620:	10000007 */ 	beqz	$zero,.L00035640
/*    35624:	0301c025 */ 	or	$t8,$t8,$at
.L00035628:
/*    35628:	10000005 */ 	beqz	$zero,.L00035640
/*    3562c:	2418ffff */ 	addiu	$t8,$zero,-1
.L00035630:
/*    35630:	44184000 */ 	mfc1	$t8,$f8
/*    35634:	00000000 */ 	sll	$zero,$zero,0x0
/*    35638:	0700fffb */ 	bltz	$t8,.L00035628
/*    3563c:	00000000 */ 	sll	$zero,$zero,0x0
.L00035640:
/*    35640:	8faa009c */ 	lw	$t2,0x9c($sp)
/*    35644:	44d9f800 */ 	ctc1	$t9,$31
/*    35648:	a1580036 */ 	sb	$t8,0x36($t2)
/*    3564c:	00000000 */ 	sll	$zero,$zero,0x0
/*    35650:	3c013f80 */ 	lui	$at,0x3f80
/*    35654:	44815000 */ 	mtc1	$at,$f10
/*    35658:	00000000 */ 	sll	$zero,$zero,0x0
/*    3565c:	e7aa0078 */ 	swc1	$f10,0x78($sp)
/*    35660:	8fa90094 */ 	lw	$t1,0x94($sp)
/*    35664:	912d0024 */ 	lbu	$t5,0x24($t1)
/*    35668:	11a00005 */ 	beqz	$t5,.L00035680
/*    3566c:	00000000 */ 	sll	$zero,$zero,0x0
/*    35670:	8faf0094 */ 	lw	$t7,0x94($sp)
/*    35674:	91ee002c */ 	lbu	$t6,0x2c($t7)
/*    35678:	10000004 */ 	beqz	$zero,.L0003568c
/*    3567c:	afae0090 */ 	sw	$t6,0x90($sp)
.L00035680:
/*    35680:	8fac0068 */ 	lw	$t4,0x68($sp)
/*    35684:	918b0008 */ 	lbu	$t3,0x8($t4)
/*    35688:	afab0090 */ 	sw	$t3,0x90($sp)
.L0003568c:
/*    3568c:	8fa80090 */ 	lw	$t0,0x90($sp)
/*    35690:	11000043 */ 	beqz	$t0,.L000357a0
/*    35694:	00000000 */ 	sll	$zero,$zero,0x0
/*    35698:	8fb900d0 */ 	lw	$t9,0xd0($sp)
/*    3569c:	8f380070 */ 	lw	$t8,0x70($t9)
/*    356a0:	1300003f */ 	beqz	$t8,.L000357a0
/*    356a4:	00000000 */ 	sll	$zero,$zero,0x0
/*    356a8:	8faa0094 */ 	lw	$t2,0x94($sp)
/*    356ac:	91490024 */ 	lbu	$t1,0x24($t2)
/*    356b0:	11200012 */ 	beqz	$t1,.L000356fc
/*    356b4:	00000000 */ 	sll	$zero,$zero,0x0
/*    356b8:	8fad0094 */ 	lw	$t5,0x94($sp)
/*    356bc:	8fab00d0 */ 	lw	$t3,0xd0($sp)
/*    356c0:	27a4006c */ 	addiu	$a0,$sp,0x6c
/*    356c4:	91af002e */ 	lbu	$t7,0x2e($t5)
/*    356c8:	91a6002c */ 	lbu	$a2,0x2c($t5)
/*    356cc:	91a7002d */ 	lbu	$a3,0x2d($t5)
/*    356d0:	afaf0010 */ 	sw	$t7,0x10($sp)
/*    356d4:	91ae002f */ 	lbu	$t6,0x2f($t5)
/*    356d8:	27a50078 */ 	addiu	$a1,$sp,0x78
/*    356dc:	afae0014 */ 	sw	$t6,0x14($sp)
/*    356e0:	91ac0031 */ 	lbu	$t4,0x31($t5)
/*    356e4:	afac0018 */ 	sw	$t4,0x18($sp)
/*    356e8:	8d790070 */ 	lw	$t9,0x70($t3)
/*    356ec:	0320f809 */ 	jalr	$t9
/*    356f0:	00000000 */ 	sll	$zero,$zero,0x0
/*    356f4:	10000012 */ 	beqz	$zero,.L00035740
/*    356f8:	afa200a0 */ 	sw	$v0,0xa0($sp)
.L000356fc:
/*    356fc:	8fa80068 */ 	lw	$t0,0x68($sp)
/*    35700:	8fa90094 */ 	lw	$t1,0x94($sp)
/*    35704:	8fae00d0 */ 	lw	$t6,0xd0($sp)
/*    35708:	9118000a */ 	lbu	$t8,0xa($t0)
/*    3570c:	91060008 */ 	lbu	$a2,0x8($t0)
/*    35710:	91070009 */ 	lbu	$a3,0x9($t0)
/*    35714:	afb80010 */ 	sw	$t8,0x10($sp)
/*    35718:	910a000b */ 	lbu	$t2,0xb($t0)
/*    3571c:	27a4006c */ 	addiu	$a0,$sp,0x6c
/*    35720:	27a50078 */ 	addiu	$a1,$sp,0x78
/*    35724:	afaa0014 */ 	sw	$t2,0x14($sp)
/*    35728:	912f0031 */ 	lbu	$t7,0x31($t1)
/*    3572c:	afaf0018 */ 	sw	$t7,0x18($sp)
/*    35730:	8dd90070 */ 	lw	$t9,0x70($t6)
/*    35734:	0320f809 */ 	jalr	$t9
/*    35738:	00000000 */ 	sll	$zero,$zero,0x0
/*    3573c:	afa200a0 */ 	sw	$v0,0xa0($sp)
.L00035740:
/*    35740:	8fad00a0 */ 	lw	$t5,0xa0($sp)
/*    35744:	11a00016 */ 	beqz	$t5,.L000357a0
/*    35748:	00000000 */ 	sll	$zero,$zero,0x0
/*    3574c:	240c0017 */ 	addiu	$t4,$zero,0x17
/*    35750:	a7ac00a4 */ 	sh	$t4,0xa4($sp)
/*    35754:	8fab009c */ 	lw	$t3,0x9c($sp)
/*    35758:	afab00a8 */ 	sw	$t3,0xa8($sp)
/*    3575c:	8fb8006c */ 	lw	$t8,0x6c($sp)
/*    35760:	afb800ac */ 	sw	$t8,0xac($sp)
/*    35764:	93a800c3 */ 	lbu	$t0,0xc3($sp)
/*    35768:	a3a800b0 */ 	sb	$t0,0xb0($sp)
/*    3576c:	8fa400d0 */ 	lw	$a0,0xd0($sp)
/*    35770:	27a500a4 */ 	addiu	$a1,$sp,0xa4
/*    35774:	8fa600a0 */ 	lw	$a2,0xa0($sp)
/*    35778:	00003825 */ 	or	$a3,$zero,$zero
/*    3577c:	0c00f184 */ 	jal	func0003c610
/*    35780:	24840048 */ 	addiu	$a0,$a0,0x48
/*    35784:	8faa009c */ 	lw	$t2,0x9c($sp)
/*    35788:	91490037 */ 	lbu	$t1,0x37($t2)
/*    3578c:	352f0002 */ 	ori	$t7,$t1,0x2
/*    35790:	a14f0037 */ 	sb	$t7,0x37($t2)
/*    35794:	8fae006c */ 	lw	$t6,0x6c($sp)
/*    35798:	8fb9009c */ 	lw	$t9,0x9c($sp)
/*    3579c:	af2e003c */ 	sw	$t6,0x3c($t9)
.L000357a0:
/*    357a0:	c7b00078 */ 	lwc1	$f16,0x78($sp)
/*    357a4:	8fad009c */ 	lw	$t5,0x9c($sp)
/*    357a8:	e5b0002c */ 	swc1	$f16,0x2c($t5)
/*    357ac:	8fac009c */ 	lw	$t4,0x9c($sp)
/*    357b0:	8fab0094 */ 	lw	$t3,0x94($sp)
/*    357b4:	c5920028 */ 	lwc1	$f18,0x28($t4)
/*    357b8:	c5640014 */ 	lwc1	$f4,0x14($t3)
/*    357bc:	c588002c */ 	lwc1	$f8,0x2c($t4)
/*    357c0:	46049182 */ 	mul.s	$f6,$f18,$f4
/*    357c4:	00000000 */ 	sll	$zero,$zero,0x0
/*    357c8:	46083282 */ 	mul.s	$f10,$f6,$f8
/*    357cc:	e7aa007c */ 	swc1	$f10,0x7c($sp)
/*    357d0:	8fa4009c */ 	lw	$a0,0x9c($sp)
/*    357d4:	0c00f673 */ 	jal	func0003d9cc
/*    357d8:	8fa500d0 */ 	lw	$a1,0xd0($sp)
/*    357dc:	a3a20077 */ 	sb	$v0,0x77($sp)
/*    357e0:	8fb80094 */ 	lw	$t8,0x94($sp)
/*    357e4:	93080011 */ 	lbu	$t0,0x11($t8)
/*    357e8:	a3a80076 */ 	sb	$t0,0x76($sp)
/*    357ec:	93a90076 */ 	lbu	$t1,0x76($sp)
/*    357f0:	11200012 */ 	beqz	$t1,.L0003583c
/*    357f4:	00000000 */ 	sll	$zero,$zero,0x0
/*    357f8:	87af0082 */ 	lh	$t7,0x82($sp)
/*    357fc:	24010064 */ 	addiu	$at,$zero,0x64
/*    35800:	8fae0094 */ 	lw	$t6,0x94($sp)
/*    35804:	01e1001a */ 	div	$zero,$t7,$at
/*    35808:	91d90012 */ 	lbu	$t9,0x12($t6)
/*    3580c:	00005012 */ 	mflo	$t2
/*    35810:	01592021 */ 	addu	$a0,$t2,$t9
/*    35814:	0c00ee75 */ 	jal	func0003b9d4
/*    35818:	2484ffc0 */ 	addiu	$a0,$a0,-64
/*    3581c:	3c0143dc */ 	lui	$at,0x43dc
/*    35820:	44818000 */ 	mtc1	$at,$f16
/*    35824:	8fad0094 */ 	lw	$t5,0x94($sp)
/*    35828:	46100482 */ 	mul.s	$f18,$f0,$f16
/*    3582c:	c5a40014 */ 	lwc1	$f4,0x14($t5)
/*    35830:	46049182 */ 	mul.s	$f6,$f18,$f4
/*    35834:	10000005 */ 	beqz	$zero,.L0003584c
/*    35838:	e7a60070 */ 	swc1	$f6,0x70($sp)
.L0003583c:
/*    3583c:	3c0142fe */ 	lui	$at,0x42fe
/*    35840:	44814000 */ 	mtc1	$at,$f8
/*    35844:	00000000 */ 	sll	$zero,$zero,0x0
/*    35848:	e7a80070 */ 	swc1	$f8,0x70($sp)
.L0003584c:
/*    3584c:	8fa4009c */ 	lw	$a0,0x9c($sp)
/*    35850:	0c00f6c5 */ 	jal	func0003db14
/*    35854:	8fa500d0 */ 	lw	$a1,0xd0($sp)
/*    35858:	a3a2009b */ 	sb	$v0,0x9b($sp)
/*    3585c:	8fa4009c */ 	lw	$a0,0x9c($sp)
/*    35860:	0c00f629 */ 	jal	func0003d8a4
/*    35864:	8fa500d0 */ 	lw	$a1,0xd0($sp)
/*    35868:	a7a200b6 */ 	sh	$v0,0xb6($sp)
/*    3586c:	8fab0094 */ 	lw	$t3,0x94($sp)
/*    35870:	916c0024 */ 	lbu	$t4,0x24($t3)
/*    35874:	11800005 */ 	beqz	$t4,.L0003588c
/*    35878:	00000000 */ 	sll	$zero,$zero,0x0
/*    3587c:	8fb80094 */ 	lw	$t8,0x94($sp)
/*    35880:	8f080018 */ 	lw	$t0,0x18($t8)
/*    35884:	10000005 */ 	beqz	$zero,.L0003589c
/*    35888:	afa800a0 */ 	sw	$t0,0xa0($sp)
.L0003588c:
/*    3588c:	8fa90084 */ 	lw	$t1,0x84($sp)
/*    35890:	8d2f0000 */ 	lw	$t7,0x0($t1)
/*    35894:	8dee0000 */ 	lw	$t6,0x0($t7)
/*    35898:	afae00a0 */ 	sw	$t6,0xa0($sp)
.L0003589c:
/*    3589c:	8faa0084 */ 	lw	$t2,0x84($sp)
/*    358a0:	93b9009b */ 	lbu	$t9,0x9b($sp)
/*    358a4:	93ad0077 */ 	lbu	$t5,0x77($sp)
/*    358a8:	8d450008 */ 	lw	$a1,0x8($t2)
/*    358ac:	93ab0076 */ 	lbu	$t3,0x76($sp)
/*    358b0:	c7aa0070 */ 	lwc1	$f10,0x70($sp)
/*    358b4:	8fac0094 */ 	lw	$t4,0x94($sp)
/*    358b8:	afb90010 */ 	sw	$t9,0x10($sp)
/*    358bc:	afad0014 */ 	sw	$t5,0x14($sp)
/*    358c0:	afab0018 */ 	sw	$t3,0x18($sp)
/*    358c4:	e7aa001c */ 	swc1	$f10,0x1c($sp)
/*    358c8:	8fa800a0 */ 	lw	$t0,0xa0($sp)
/*    358cc:	91980013 */ 	lbu	$t8,0x13($t4)
/*    358d0:	8fa400cc */ 	lw	$a0,0xcc($sp)
/*    358d4:	8fa6007c */ 	lw	$a2,0x7c($sp)
/*    358d8:	87a700b6 */ 	lh	$a3,0xb6($sp)
/*    358dc:	afa80024 */ 	sw	$t0,0x24($sp)
/*    358e0:	0c00f370 */ 	jal	func0003cdc0
/*    358e4:	afb80020 */ 	sw	$t8,0x20($sp)
/*    358e8:	24090006 */ 	addiu	$t1,$zero,0x6
/*    358ec:	a7a900a4 */ 	sh	$t1,0xa4($sp)
/*    358f0:	8faf00cc */ 	lw	$t7,0xcc($sp)
/*    358f4:	afaf00a8 */ 	sw	$t7,0xa8($sp)
/*    358f8:	8fae0094 */ 	lw	$t6,0x94($sp)
/*    358fc:	91ca0024 */ 	lbu	$t2,0x24($t6)
/*    35900:	11400008 */ 	beqz	$t2,.L00035924
/*    35904:	00000000 */ 	sll	$zero,$zero,0x0
/*    35908:	8fb90094 */ 	lw	$t9,0x94($sp)
/*    3590c:	932d0026 */ 	lbu	$t5,0x26($t9)
/*    35910:	a3ad00b0 */ 	sb	$t5,0xb0($sp)
/*    35914:	8fab0094 */ 	lw	$t3,0x94($sp)
/*    35918:	8d6c001c */ 	lw	$t4,0x1c($t3)
/*    3591c:	10000009 */ 	beqz	$zero,.L00035944
/*    35920:	afac00ac */ 	sw	$t4,0xac($sp)
.L00035924:
/*    35924:	8fb80084 */ 	lw	$t8,0x84($sp)
/*    35928:	8f080000 */ 	lw	$t0,0x0($t8)
/*    3592c:	9109000d */ 	lbu	$t1,0xd($t0)
/*    35930:	a3a900b0 */ 	sb	$t1,0xb0($sp)
/*    35934:	8faf0084 */ 	lw	$t7,0x84($sp)
/*    35938:	8dee0000 */ 	lw	$t6,0x0($t7)
/*    3593c:	8dca0004 */ 	lw	$t2,0x4($t6)
/*    35940:	afaa00ac */ 	sw	$t2,0xac($sp)
.L00035944:
/*    35944:	8fa400d0 */ 	lw	$a0,0xd0($sp)
/*    35948:	27a500a4 */ 	addiu	$a1,$sp,0xa4
/*    3594c:	8fa600a0 */ 	lw	$a2,0xa0($sp)
/*    35950:	00003825 */ 	or	$a3,$zero,$zero
/*    35954:	0c00f184 */ 	jal	func0003c610
/*    35958:	24840048 */ 	addiu	$a0,$a0,0x48
/*    3595c:	8fb900b8 */ 	lw	$t9,0xb8($sp)
/*    35960:	8f2d0008 */ 	lw	$t5,0x8($t9)
/*    35964:	11a0001d */ 	beqz	$t5,.L000359dc
/*    35968:	00000000 */ 	sll	$zero,$zero,0x0
/*    3596c:	240b0015 */ 	addiu	$t3,$zero,0x15
/*    35970:	a7ab00a4 */ 	sh	$t3,0xa4($sp)
/*    35974:	93ac00c3 */ 	lbu	$t4,0xc3($sp)
/*    35978:	35980080 */ 	ori	$t8,$t4,0x80
/*    3597c:	a3b800ac */ 	sb	$t8,0xac($sp)
/*    35980:	93a800c2 */ 	lbu	$t0,0xc2($sp)
/*    35984:	a3a800ad */ 	sb	$t0,0xad($sp)
/*    35988:	a3a000ae */ 	sb	$zero,0xae($sp)
/*    3598c:	8fa900d0 */ 	lw	$t1,0xd0($sp)
/*    35990:	8fae00b8 */ 	lw	$t6,0xb8($sp)
/*    35994:	8d2f0024 */ 	lw	$t7,0x24($t1)
/*    35998:	8dca0008 */ 	lw	$t2,0x8($t6)
/*    3599c:	01ea0019 */ 	multu	$t7,$t2
/*    359a0:	0000c812 */ 	mflo	$t9
/*    359a4:	afb900a0 */ 	sw	$t9,0xa0($sp)
/*    359a8:	00000000 */ 	sll	$zero,$zero,0x0
/*    359ac:	93ab00c3 */ 	lbu	$t3,0xc3($sp)
/*    359b0:	8fad00a0 */ 	lw	$t5,0xa0($sp)
/*    359b4:	3c01800a */ 	lui	$at,0x800a
/*    359b8:	000b6080 */ 	sll	$t4,$t3,0x2
/*    359bc:	002c0821 */ 	addu	$at,$at,$t4
/*    359c0:	ac2dc350 */ 	sw	$t5,-0x3cb0($at)
/*    359c4:	8fa400d0 */ 	lw	$a0,0xd0($sp)
/*    359c8:	27a500a4 */ 	addiu	$a1,$sp,0xa4
/*    359cc:	8fa600a0 */ 	lw	$a2,0xa0($sp)
/*    359d0:	00003825 */ 	or	$a3,$zero,$zero
/*    359d4:	0c00f184 */ 	jal	func0003c610
/*    359d8:	24840048 */ 	addiu	$a0,$a0,0x48
.L000359dc:
/*    359dc:	8fb80094 */ 	lw	$t8,0x94($sp)
/*    359e0:	93080010 */ 	lbu	$t0,0x10($t8)
/*    359e4:	31090001 */ 	andi	$t1,$t0,0x1
/*    359e8:	11200014 */ 	beqz	$t1,.L00035a3c
/*    359ec:	00000000 */ 	sll	$zero,$zero,0x0
/*    359f0:	8fae00d0 */ 	lw	$t6,0xd0($sp)
/*    359f4:	8dcf0084 */ 	lw	$t7,0x84($t6)
/*    359f8:	11e00010 */ 	beqz	$t7,.L00035a3c
/*    359fc:	00000000 */ 	sll	$zero,$zero,0x0
/*    35a00:	93b900c3 */ 	lbu	$t9,0xc3($sp)
/*    35a04:	8fb80094 */ 	lw	$t8,0x94($sp)
/*    35a08:	3c0d800a */ 	lui	$t5,0x800a
/*    35a0c:	00195880 */ 	sll	$t3,$t9,0x2
/*    35a10:	01ab6821 */ 	addu	$t5,$t5,$t3
/*    35a14:	8dadc350 */ 	lw	$t5,-0x3cb0($t5)
/*    35a18:	93080010 */ 	lbu	$t0,0x10($t8)
/*    35a1c:	8faa00d0 */ 	lw	$t2,0xd0($sp)
/*    35a20:	2401ff00 */ 	addiu	$at,$zero,-256
/*    35a24:	01a16024 */ 	and	$t4,$t5,$at
/*    35a28:	00084883 */ 	sra	$t1,$t0,0x2
/*    35a2c:	01892825 */ 	or	$a1,$t4,$t1
/*    35a30:	00003025 */ 	or	$a2,$zero,$zero
/*    35a34:	0c012238 */ 	jal	osSendMesg
/*    35a38:	8d440084 */ 	lw	$a0,0x84($t2)
.L00035a3c:
/*    35a3c:	100005f0 */ 	beqz	$zero,.L00037200
/*    35a40:	00000000 */ 	sll	$zero,$zero,0x0
.L00035a44:
/*    35a44:	8fa400d0 */ 	lw	$a0,0xd0($sp)
/*    35a48:	93a500c2 */ 	lbu	$a1,0xc2($sp)
/*    35a4c:	0c00f5a7 */ 	jal	func0003d69c
/*    35a50:	93a600c3 */ 	lbu	$a2,0xc3($sp)
/*    35a54:	afa2009c */ 	sw	$v0,0x9c($sp)
/*    35a58:	8fae009c */ 	lw	$t6,0x9c($sp)
/*    35a5c:	15c00003 */ 	bnez	$t6,.L00035a6c
/*    35a60:	00000000 */ 	sll	$zero,$zero,0x0
/*    35a64:	100005e8 */ 	beqz	$zero,.L00037208
/*    35a68:	00000000 */ 	sll	$zero,$zero,0x0
.L00035a6c:
/*    35a6c:	93b900c3 */ 	lbu	$t9,0xc3($sp)
/*    35a70:	8faf00d0 */ 	lw	$t7,0xd0($sp)
/*    35a74:	00195880 */ 	sll	$t3,$t9,0x2
/*    35a78:	01795823 */ 	subu	$t3,$t3,$t9
/*    35a7c:	8dea0060 */ 	lw	$t2,0x60($t7)
/*    35a80:	000b5880 */ 	sll	$t3,$t3,0x2
/*    35a84:	01795821 */ 	addu	$t3,$t3,$t9
/*    35a88:	000b5880 */ 	sll	$t3,$t3,0x2
/*    35a8c:	014b6821 */ 	addu	$t5,$t2,$t3
/*    35a90:	afad0094 */ 	sw	$t5,0x94($sp)
/*    35a94:	8fb8009c */ 	lw	$t8,0x9c($sp)
/*    35a98:	24010002 */ 	addiu	$at,$zero,0x2
/*    35a9c:	93080035 */ 	lbu	$t0,0x35($t8)
/*    35aa0:	15010005 */ 	bne	$t0,$at,.L00035ab8
/*    35aa4:	00000000 */ 	sll	$zero,$zero,0x0
/*    35aa8:	8fa9009c */ 	lw	$t1,0x9c($sp)
/*    35aac:	240c0004 */ 	addiu	$t4,$zero,0x4
/*    35ab0:	10000017 */ 	beqz	$zero,.L00035b10
/*    35ab4:	a12c0035 */ 	sb	$t4,0x35($t1)
.L00035ab8:
/*    35ab8:	8faf009c */ 	lw	$t7,0x9c($sp)
/*    35abc:	240e0003 */ 	addiu	$t6,$zero,0x3
/*    35ac0:	a1ee0035 */ 	sb	$t6,0x35($t7)
/*    35ac4:	8fb90094 */ 	lw	$t9,0x94($sp)
/*    35ac8:	932a0024 */ 	lbu	$t2,0x24($t9)
/*    35acc:	11400009 */ 	beqz	$t2,.L00035af4
/*    35ad0:	00000000 */ 	sll	$zero,$zero,0x0
/*    35ad4:	8fa5009c */ 	lw	$a1,0x9c($sp)
/*    35ad8:	8fab0094 */ 	lw	$t3,0x94($sp)
/*    35adc:	8fa400d0 */ 	lw	$a0,0xd0($sp)
/*    35ae0:	24a50004 */ 	addiu	$a1,$a1,0x4
/*    35ae4:	0c00f4d0 */ 	jal	func0003d340
/*    35ae8:	8d660020 */ 	lw	$a2,0x20($t3)
/*    35aec:	10000008 */ 	beqz	$zero,.L00035b10
/*    35af0:	00000000 */ 	sll	$zero,$zero,0x0
.L00035af4:
/*    35af4:	8fad009c */ 	lw	$t5,0x9c($sp)
/*    35af8:	8fa400d0 */ 	lw	$a0,0xd0($sp)
/*    35afc:	8db80020 */ 	lw	$t8,0x20($t5)
/*    35b00:	25a50004 */ 	addiu	$a1,$t5,0x4
/*    35b04:	8f080000 */ 	lw	$t0,0x0($t8)
/*    35b08:	0c00f4d0 */ 	jal	func0003d340
/*    35b0c:	8d060008 */ 	lw	$a2,0x8($t0)
.L00035b10:
/*    35b10:	8fac0094 */ 	lw	$t4,0x94($sp)
/*    35b14:	91890010 */ 	lbu	$t1,0x10($t4)
/*    35b18:	312e0002 */ 	andi	$t6,$t1,0x2
/*    35b1c:	11c00010 */ 	beqz	$t6,.L00035b60
/*    35b20:	00000000 */ 	sll	$zero,$zero,0x0
/*    35b24:	8faf00d0 */ 	lw	$t7,0xd0($sp)
/*    35b28:	8df90084 */ 	lw	$t9,0x84($t7)
/*    35b2c:	1320000c */ 	beqz	$t9,.L00035b60
/*    35b30:	00000000 */ 	sll	$zero,$zero,0x0
/*    35b34:	8fa80094 */ 	lw	$t0,0x94($sp)
/*    35b38:	93ab00c2 */ 	lbu	$t3,0xc2($sp)
/*    35b3c:	8faa00d0 */ 	lw	$t2,0xd0($sp)
/*    35b40:	910c0010 */ 	lbu	$t4,0x10($t0)
/*    35b44:	000b6c00 */ 	sll	$t5,$t3,0x10
/*    35b48:	35b80008 */ 	ori	$t8,$t5,0x8
/*    35b4c:	000c4883 */ 	sra	$t1,$t4,0x2
/*    35b50:	03092825 */ 	or	$a1,$t8,$t1
/*    35b54:	00003025 */ 	or	$a2,$zero,$zero
/*    35b58:	0c012238 */ 	jal	osSendMesg
/*    35b5c:	8d440084 */ 	lw	$a0,0x84($t2)
.L00035b60:
/*    35b60:	100005a7 */ 	beqz	$zero,.L00037200
/*    35b64:	00000000 */ 	sll	$zero,$zero,0x0
/*    35b68:	8fa400d0 */ 	lw	$a0,0xd0($sp)
/*    35b6c:	93a500c2 */ 	lbu	$a1,0xc2($sp)
/*    35b70:	0c00f5a7 */ 	jal	func0003d69c
/*    35b74:	93a600c3 */ 	lbu	$a2,0xc3($sp)
/*    35b78:	afa2009c */ 	sw	$v0,0x9c($sp)
/*    35b7c:	8fae009c */ 	lw	$t6,0x9c($sp)
/*    35b80:	15c00003 */ 	bnez	$t6,.L00035b90
/*    35b84:	00000000 */ 	sll	$zero,$zero,0x0
/*    35b88:	1000059f */ 	beqz	$zero,.L00037208
/*    35b8c:	00000000 */ 	sll	$zero,$zero,0x0
.L00035b90:
/*    35b90:	93af00bf */ 	lbu	$t7,0xbf($sp)
/*    35b94:	8fb9009c */ 	lw	$t9,0x9c($sp)
/*    35b98:	a32f0033 */ 	sb	$t7,0x33($t9)
/*    35b9c:	8fa4009c */ 	lw	$a0,0x9c($sp)
/*    35ba0:	0c00f629 */ 	jal	func0003d8a4
/*    35ba4:	8fa500d0 */ 	lw	$a1,0xd0($sp)
/*    35ba8:	8faa00d0 */ 	lw	$t2,0xd0($sp)
/*    35bac:	00028c00 */ 	sll	$s1,$v0,0x10
/*    35bb0:	00118c03 */ 	sra	$s1,$s1,0x10
/*    35bb4:	8fa4009c */ 	lw	$a0,0x9c($sp)
/*    35bb8:	0c00f6b4 */ 	jal	func0003dad0
/*    35bbc:	8d45001c */ 	lw	$a1,0x1c($t2)
/*    35bc0:	8fa4009c */ 	lw	$a0,0x9c($sp)
/*    35bc4:	00408025 */ 	or	$s0,$v0,$zero
/*    35bc8:	02003025 */ 	or	$a2,$s0,$zero
/*    35bcc:	02202825 */ 	or	$a1,$s1,$zero
/*    35bd0:	0c00f33c */ 	jal	func0003ccf0
/*    35bd4:	24840004 */ 	addiu	$a0,$a0,0x4
/*    35bd8:	10000589 */ 	beqz	$zero,.L00037200
/*    35bdc:	00000000 */ 	sll	$zero,$zero,0x0
/*    35be0:	8fab00d0 */ 	lw	$t3,0xd0($sp)
/*    35be4:	8d6d0064 */ 	lw	$t5,0x64($t3)
/*    35be8:	11a0001c */ 	beqz	$t5,.L00035c5c
/*    35bec:	afad00c8 */ 	sw	$t5,0xc8($sp)
.L00035bf0:
/*    35bf0:	8fa800c8 */ 	lw	$t0,0xc8($sp)
/*    35bf4:	93b800c3 */ 	lbu	$t8,0xc3($sp)
/*    35bf8:	910c0031 */ 	lbu	$t4,0x31($t0)
/*    35bfc:	15980013 */ 	bne	$t4,$t8,.L00035c4c
/*    35c00:	00000000 */ 	sll	$zero,$zero,0x0
/*    35c04:	93a900c0 */ 	lbu	$t1,0xc0($sp)
/*    35c08:	8fae00c8 */ 	lw	$t6,0xc8($sp)
/*    35c0c:	a1c90033 */ 	sb	$t1,0x33($t6)
/*    35c10:	8fa400c8 */ 	lw	$a0,0xc8($sp)
/*    35c14:	0c00f629 */ 	jal	func0003d8a4
/*    35c18:	8fa500d0 */ 	lw	$a1,0xd0($sp)
/*    35c1c:	8faf00d0 */ 	lw	$t7,0xd0($sp)
/*    35c20:	00028c00 */ 	sll	$s1,$v0,0x10
/*    35c24:	00118c03 */ 	sra	$s1,$s1,0x10
/*    35c28:	8fa400c8 */ 	lw	$a0,0xc8($sp)
/*    35c2c:	0c00f6b4 */ 	jal	func0003dad0
/*    35c30:	8de5001c */ 	lw	$a1,0x1c($t7)
/*    35c34:	8fa400c8 */ 	lw	$a0,0xc8($sp)
/*    35c38:	00408025 */ 	or	$s0,$v0,$zero
/*    35c3c:	02003025 */ 	or	$a2,$s0,$zero
/*    35c40:	02202825 */ 	or	$a1,$s1,$zero
/*    35c44:	0c00f33c */ 	jal	func0003ccf0
/*    35c48:	24840004 */ 	addiu	$a0,$a0,0x4
.L00035c4c:
/*    35c4c:	8fb900c8 */ 	lw	$t9,0xc8($sp)
/*    35c50:	8f2a0000 */ 	lw	$t2,0x0($t9)
/*    35c54:	1540ffe6 */ 	bnez	$t2,.L00035bf0
/*    35c58:	afaa00c8 */ 	sw	$t2,0xc8($sp)
.L00035c5c:
/*    35c5c:	10000568 */ 	beqz	$zero,.L00037200
/*    35c60:	00000000 */ 	sll	$zero,$zero,0x0
/*    35c64:	93b000c0 */ 	lbu	$s0,0xc0($sp)
/*    35c68:	2a01005d */ 	slti	$at,$s0,0x5d
/*    35c6c:	1420000f */ 	bnez	$at,.L00035cac
/*    35c70:	00000000 */ 	sll	$zero,$zero,0x0
/*    35c74:	240100fc */ 	addiu	$at,$zero,0xfc
/*    35c78:	1201012d */ 	beq	$s0,$at,.L00036130
/*    35c7c:	00000000 */ 	sll	$zero,$zero,0x0
/*    35c80:	240100fd */ 	addiu	$at,$zero,0xfd
/*    35c84:	12010050 */ 	beq	$s0,$at,.L00035dc8
/*    35c88:	00000000 */ 	sll	$zero,$zero,0x0
/*    35c8c:	240100fe */ 	addiu	$at,$zero,0xfe
/*    35c90:	120100ab */ 	beq	$s0,$at,.L00035f40
/*    35c94:	00000000 */ 	sll	$zero,$zero,0x0
/*    35c98:	240100ff */ 	addiu	$at,$zero,0xff
/*    35c9c:	12010057 */ 	beq	$s0,$at,.L00035dfc
/*    35ca0:	00000000 */ 	sll	$zero,$zero,0x0
/*    35ca4:	100004bf */ 	beqz	$zero,.L00036fa4
/*    35ca8:	00000000 */ 	sll	$zero,$zero,0x0
.L00035cac:
/*    35cac:	2a010042 */ 	slti	$at,$s0,0x42
/*    35cb0:	14200009 */ 	bnez	$at,.L00035cd8
/*    35cb4:	00000000 */ 	sll	$zero,$zero,0x0
/*    35cb8:	2401005b */ 	addiu	$at,$zero,0x5b
/*    35cbc:	12010244 */ 	beq	$s0,$at,.L000365d0
/*    35cc0:	00000000 */ 	sll	$zero,$zero,0x0
/*    35cc4:	2401005c */ 	addiu	$at,$zero,0x5c
/*    35cc8:	12010286 */ 	beq	$s0,$at,.L000366e4
/*    35ccc:	00000000 */ 	sll	$zero,$zero,0x0
/*    35cd0:	100004b4 */ 	beqz	$zero,.L00036fa4
/*    35cd4:	00000000 */ 	sll	$zero,$zero,0x0
.L00035cd8:
/*    35cd8:	2a010041 */ 	slti	$at,$s0,0x41
/*    35cdc:	14200006 */ 	bnez	$at,.L00035cf8
/*    35ce0:	00000000 */ 	sll	$zero,$zero,0x0
/*    35ce4:	24010041 */ 	addiu	$at,$zero,0x41
/*    35ce8:	12010253 */ 	beq	$s0,$at,.L00036638
/*    35cec:	00000000 */ 	sll	$zero,$zero,0x0
/*    35cf0:	100004ac */ 	beqz	$zero,.L00036fa4
/*    35cf4:	00000000 */ 	sll	$zero,$zero,0x0
.L00035cf8:
/*    35cf8:	2a010024 */ 	slti	$at,$s0,0x24
/*    35cfc:	14200006 */ 	bnez	$at,.L00035d18
/*    35d00:	00000000 */ 	sll	$zero,$zero,0x0
/*    35d04:	24010040 */ 	addiu	$at,$zero,0x40
/*    35d08:	120101c0 */ 	beq	$s0,$at,.L0003640c
/*    35d0c:	00000000 */ 	sll	$zero,$zero,0x0
/*    35d10:	100004a4 */ 	beqz	$zero,.L00036fa4
/*    35d14:	00000000 */ 	sll	$zero,$zero,0x0
.L00035d18:
/*    35d18:	260bffff */ 	addiu	$t3,$s0,-1
/*    35d1c:	2d610023 */ 	sltiu	$at,$t3,0x23
/*    35d20:	102004a0 */ 	beqz	$at,.L00036fa4
/*    35d24:	00000000 */ 	sll	$zero,$zero,0x0
/*    35d28:	000b5880 */ 	sll	$t3,$t3,0x2
/*    35d2c:	3c017005 */ 	lui	$at,%hi(var700549bc)
/*    35d30:	002b0821 */ 	addu	$at,$at,$t3
/*    35d34:	8c2b49bc */ 	lw	$t3,%lo(var700549bc)($at)
/*    35d38:	01600008 */ 	jr	$t3
/*    35d3c:	00000000 */ 	sll	$zero,$zero,0x0
/*    35d40:	93b800c3 */ 	lbu	$t8,0xc3($sp)
/*    35d44:	8fa800d0 */ 	lw	$t0,0xd0($sp)
/*    35d48:	93ad00bf */ 	lbu	$t5,0xbf($sp)
/*    35d4c:	00184880 */ 	sll	$t1,$t8,0x2
/*    35d50:	01384823 */ 	subu	$t1,$t1,$t8
/*    35d54:	8d0c0060 */ 	lw	$t4,0x60($t0)
/*    35d58:	00094880 */ 	sll	$t1,$t1,0x2
/*    35d5c:	01384821 */ 	addu	$t1,$t1,$t8
/*    35d60:	00094880 */ 	sll	$t1,$t1,0x2
/*    35d64:	01897021 */ 	addu	$t6,$t4,$t1
/*    35d68:	a1cd0007 */ 	sb	$t5,0x7($t6)
/*    35d6c:	8faf00d0 */ 	lw	$t7,0xd0($sp)
/*    35d70:	8df90064 */ 	lw	$t9,0x64($t7)
/*    35d74:	13200012 */ 	beqz	$t9,.L00035dc0
/*    35d78:	afb900c8 */ 	sw	$t9,0xc8($sp)
.L00035d7c:
/*    35d7c:	8faa00c8 */ 	lw	$t2,0xc8($sp)
/*    35d80:	93a800c3 */ 	lbu	$t0,0xc3($sp)
/*    35d84:	914b0031 */ 	lbu	$t3,0x31($t2)
/*    35d88:	15680009 */ 	bne	$t3,$t0,.L00035db0
/*    35d8c:	00000000 */ 	sll	$zero,$zero,0x0
/*    35d90:	8fa400c8 */ 	lw	$a0,0xc8($sp)
/*    35d94:	0c00f6c5 */ 	jal	func0003db14
/*    35d98:	8fa500d0 */ 	lw	$a1,0xd0($sp)
/*    35d9c:	a3a2009b */ 	sb	$v0,0x9b($sp)
/*    35da0:	8fa400c8 */ 	lw	$a0,0xc8($sp)
/*    35da4:	93a5009b */ 	lbu	$a1,0x9b($sp)
/*    35da8:	0c00f3bc */ 	jal	func0003cef0
/*    35dac:	24840004 */ 	addiu	$a0,$a0,0x4
.L00035db0:
/*    35db0:	8fb800c8 */ 	lw	$t8,0xc8($sp)
/*    35db4:	8f0c0000 */ 	lw	$t4,0x0($t8)
/*    35db8:	1580fff0 */ 	bnez	$t4,.L00035d7c
/*    35dbc:	afac00c8 */ 	sw	$t4,0xc8($sp)
.L00035dc0:
/*    35dc0:	1000047a */ 	beqz	$zero,.L00036fac
/*    35dc4:	00000000 */ 	sll	$zero,$zero,0x0
.L00035dc8:
/*    35dc8:	93af00c3 */ 	lbu	$t7,0xc3($sp)
/*    35dcc:	8fad00d0 */ 	lw	$t5,0xd0($sp)
/*    35dd0:	93a900bf */ 	lbu	$t1,0xbf($sp)
/*    35dd4:	000fc880 */ 	sll	$t9,$t7,0x2
/*    35dd8:	032fc823 */ 	subu	$t9,$t9,$t7
/*    35ddc:	8dae0060 */ 	lw	$t6,0x60($t5)
/*    35de0:	0019c880 */ 	sll	$t9,$t9,0x2
/*    35de4:	032fc821 */ 	addu	$t9,$t9,$t7
/*    35de8:	0019c880 */ 	sll	$t9,$t9,0x2
/*    35dec:	01d95021 */ 	addu	$t2,$t6,$t9
/*    35df0:	a149000f */ 	sb	$t1,0xf($t2)
/*    35df4:	1000046d */ 	beqz	$zero,.L00036fac
/*    35df8:	00000000 */ 	sll	$zero,$zero,0x0
.L00035dfc:
/*    35dfc:	93b800c3 */ 	lbu	$t8,0xc3($sp)
/*    35e00:	8fab00d0 */ 	lw	$t3,0xd0($sp)
/*    35e04:	00186080 */ 	sll	$t4,$t8,0x2
/*    35e08:	01986023 */ 	subu	$t4,$t4,$t8
/*    35e0c:	8d680060 */ 	lw	$t0,0x60($t3)
/*    35e10:	000c6080 */ 	sll	$t4,$t4,0x2
/*    35e14:	01986021 */ 	addu	$t4,$t4,$t8
/*    35e18:	000c6080 */ 	sll	$t4,$t4,0x2
/*    35e1c:	010c6821 */ 	addu	$t5,$t0,$t4
/*    35e20:	91af000f */ 	lbu	$t7,0xf($t5)
/*    35e24:	15e0000c */ 	bnez	$t7,.L00035e58
/*    35e28:	00000000 */ 	sll	$zero,$zero,0x0
/*    35e2c:	93aa00c3 */ 	lbu	$t2,0xc3($sp)
/*    35e30:	8fb900d0 */ 	lw	$t9,0xd0($sp)
/*    35e34:	240e0090 */ 	addiu	$t6,$zero,0x90
/*    35e38:	000a5880 */ 	sll	$t3,$t2,0x2
/*    35e3c:	016a5823 */ 	subu	$t3,$t3,$t2
/*    35e40:	8f290060 */ 	lw	$t1,0x60($t9)
/*    35e44:	000b5880 */ 	sll	$t3,$t3,0x2
/*    35e48:	016a5821 */ 	addu	$t3,$t3,$t2
/*    35e4c:	000b5880 */ 	sll	$t3,$t3,0x2
/*    35e50:	012bc021 */ 	addu	$t8,$t1,$t3
/*    35e54:	a30e000f */ 	sb	$t6,0xf($t8)
.L00035e58:
/*    35e58:	93ad00c3 */ 	lbu	$t5,0xc3($sp)
/*    35e5c:	8fa800d0 */ 	lw	$t0,0xd0($sp)
/*    35e60:	93a900bf */ 	lbu	$t1,0xbf($sp)
/*    35e64:	000d7880 */ 	sll	$t7,$t5,0x2
/*    35e68:	01ed7823 */ 	subu	$t7,$t7,$t5
/*    35e6c:	8d0c0060 */ 	lw	$t4,0x60($t0)
/*    35e70:	000f7880 */ 	sll	$t7,$t7,0x2
/*    35e74:	01ed7821 */ 	addu	$t7,$t7,$t5
/*    35e78:	000f7880 */ 	sll	$t7,$t7,0x2
/*    35e7c:	018fc821 */ 	addu	$t9,$t4,$t7
/*    35e80:	932a000e */ 	lbu	$t2,0xe($t9)
/*    35e84:	11490029 */ 	beq	$t2,$t1,.L00035f2c
/*    35e88:	00000000 */ 	sll	$zero,$zero,0x0
/*    35e8c:	93b800c3 */ 	lbu	$t8,0xc3($sp)
/*    35e90:	8fab00d0 */ 	lw	$t3,0xd0($sp)
/*    35e94:	00184080 */ 	sll	$t0,$t8,0x2
/*    35e98:	01184023 */ 	subu	$t0,$t0,$t8
/*    35e9c:	8d6e0060 */ 	lw	$t6,0x60($t3)
/*    35ea0:	00084080 */ 	sll	$t0,$t0,0x2
/*    35ea4:	01184021 */ 	addu	$t0,$t0,$t8
/*    35ea8:	00084080 */ 	sll	$t0,$t0,0x2
/*    35eac:	01c86821 */ 	addu	$t5,$t6,$t0
/*    35eb0:	91ac000d */ 	lbu	$t4,0xd($t5)
/*    35eb4:	91af000e */ 	lbu	$t7,0xe($t5)
/*    35eb8:	158f000d */ 	bne	$t4,$t7,.L00035ef0
/*    35ebc:	00000000 */ 	sll	$zero,$zero,0x0
/*    35ec0:	93ab00c3 */ 	lbu	$t3,0xc3($sp)
/*    35ec4:	8faa00d0 */ 	lw	$t2,0xd0($sp)
/*    35ec8:	93b900bf */ 	lbu	$t9,0xbf($sp)
/*    35ecc:	000bc080 */ 	sll	$t8,$t3,0x2
/*    35ed0:	030bc023 */ 	subu	$t8,$t8,$t3
/*    35ed4:	8d490060 */ 	lw	$t1,0x60($t2)
/*    35ed8:	0018c080 */ 	sll	$t8,$t8,0x2
/*    35edc:	030bc021 */ 	addu	$t8,$t8,$t3
/*    35ee0:	0018c080 */ 	sll	$t8,$t8,0x2
/*    35ee4:	01387021 */ 	addu	$t6,$t1,$t8
/*    35ee8:	1000000e */ 	beqz	$zero,.L00035f24
/*    35eec:	a1d9000e */ 	sb	$t9,0xe($t6)
.L00035ef0:
/*    35ef0:	93af00c3 */ 	lbu	$t7,0xc3($sp)
/*    35ef4:	8fad00d0 */ 	lw	$t5,0xd0($sp)
/*    35ef8:	93a800bf */ 	lbu	$t0,0xbf($sp)
/*    35efc:	000f5080 */ 	sll	$t2,$t7,0x2
/*    35f00:	014f5023 */ 	subu	$t2,$t2,$t7
/*    35f04:	8dac0060 */ 	lw	$t4,0x60($t5)
/*    35f08:	000a5080 */ 	sll	$t2,$t2,0x2
/*    35f0c:	014f5021 */ 	addu	$t2,$t2,$t7
/*    35f10:	000a5080 */ 	sll	$t2,$t2,0x2
/*    35f14:	018a5821 */ 	addu	$t3,$t4,$t2
/*    35f18:	a168000e */ 	sb	$t0,0xe($t3)
/*    35f1c:	10000423 */ 	beqz	$zero,.L00036fac
/*    35f20:	00000000 */ 	sll	$zero,$zero,0x0
.L00035f24:
/*    35f24:	10000003 */ 	beqz	$zero,.L00035f34
/*    35f28:	00000000 */ 	sll	$zero,$zero,0x0
.L00035f2c:
/*    35f2c:	1000041f */ 	beqz	$zero,.L00036fac
/*    35f30:	00000000 */ 	sll	$zero,$zero,0x0
.L00035f34:
/*    35f34:	8fb800b8 */ 	lw	$t8,0xb8($sp)
/*    35f38:	240900fe */ 	addiu	$t1,$zero,0xfe
/*    35f3c:	a3090005 */ 	sb	$t1,0x5($t8)
.L00035f40:
/*    35f40:	93ad00c3 */ 	lbu	$t5,0xc3($sp)
/*    35f44:	8fb900d0 */ 	lw	$t9,0xd0($sp)
/*    35f48:	000d7880 */ 	sll	$t7,$t5,0x2
/*    35f4c:	01ed7823 */ 	subu	$t7,$t7,$t5
/*    35f50:	8f2e0060 */ 	lw	$t6,0x60($t9)
/*    35f54:	000f7880 */ 	sll	$t7,$t7,0x2
/*    35f58:	01ed7821 */ 	addu	$t7,$t7,$t5
/*    35f5c:	000f7880 */ 	sll	$t7,$t7,0x2
/*    35f60:	01cf6021 */ 	addu	$t4,$t6,$t7
/*    35f64:	918a000d */ 	lbu	$t2,0xd($t4)
/*    35f68:	a3aa0067 */ 	sb	$t2,0x67($sp)
/*    35f6c:	93a900c3 */ 	lbu	$t1,0xc3($sp)
/*    35f70:	8fa800d0 */ 	lw	$t0,0xd0($sp)
/*    35f74:	0009c080 */ 	sll	$t8,$t1,0x2
/*    35f78:	0309c023 */ 	subu	$t8,$t8,$t1
/*    35f7c:	8d0b0060 */ 	lw	$t3,0x60($t0)
/*    35f80:	0018c080 */ 	sll	$t8,$t8,0x2
/*    35f84:	0309c021 */ 	addu	$t8,$t8,$t1
/*    35f88:	0018c080 */ 	sll	$t8,$t8,0x2
/*    35f8c:	0178c821 */ 	addu	$t9,$t3,$t8
/*    35f90:	932d000e */ 	lbu	$t5,0xe($t9)
/*    35f94:	a3ad0066 */ 	sb	$t5,0x66($sp)
/*    35f98:	93ac00c3 */ 	lbu	$t4,0xc3($sp)
/*    35f9c:	8fae00d0 */ 	lw	$t6,0xd0($sp)
/*    35fa0:	000c5080 */ 	sll	$t2,$t4,0x2
/*    35fa4:	014c5023 */ 	subu	$t2,$t2,$t4
/*    35fa8:	8dcf0060 */ 	lw	$t7,0x60($t6)
/*    35fac:	000a5080 */ 	sll	$t2,$t2,0x2
/*    35fb0:	014c5021 */ 	addu	$t2,$t2,$t4
/*    35fb4:	000a5080 */ 	sll	$t2,$t2,0x2
/*    35fb8:	01ea4021 */ 	addu	$t0,$t7,$t2
/*    35fbc:	9109000f */ 	lbu	$t1,0xf($t0)
/*    35fc0:	a3a900c1 */ 	sb	$t1,0xc1($sp)
/*    35fc4:	93ab0066 */ 	lbu	$t3,0x66($sp)
/*    35fc8:	93b80067 */ 	lbu	$t8,0x67($sp)
/*    35fcc:	0178c823 */ 	subu	$t9,$t3,$t8
/*    35fd0:	afb90060 */ 	sw	$t9,0x60($sp)
/*    35fd4:	8fad0060 */ 	lw	$t5,0x60($sp)
/*    35fd8:	19a00012 */ 	blez	$t5,.L00036024
/*    35fdc:	00000000 */ 	sll	$zero,$zero,0x0
/*    35fe0:	93ae00c1 */ 	lbu	$t6,0xc1($sp)
/*    35fe4:	31cc0080 */ 	andi	$t4,$t6,0x80
/*    35fe8:	11800005 */ 	beqz	$t4,.L00036000
/*    35fec:	00000000 */ 	sll	$zero,$zero,0x0
/*    35ff0:	93af00c1 */ 	lbu	$t7,0xc1($sp)
/*    35ff4:	31ea007f */ 	andi	$t2,$t7,0x7f
/*    35ff8:	000a4040 */ 	sll	$t0,$t2,0x1
/*    35ffc:	a3a800c1 */ 	sb	$t0,0xc1($sp)
.L00036000:
/*    36000:	8fa90060 */ 	lw	$t1,0x60($sp)
/*    36004:	93ab00c1 */ 	lbu	$t3,0xc1($sp)
/*    36008:	0169082a */ 	slt	$at,$t3,$t1
/*    3600c:	10200003 */ 	beqz	$at,.L0003601c
/*    36010:	00000000 */ 	sll	$zero,$zero,0x0
/*    36014:	93b800c1 */ 	lbu	$t8,0xc1($sp)
/*    36018:	afb80060 */ 	sw	$t8,0x60($sp)
.L0003601c:
/*    3601c:	1000000d */ 	beqz	$zero,.L00036054
/*    36020:	00000000 */ 	sll	$zero,$zero,0x0
.L00036024:
/*    36024:	93b900c1 */ 	lbu	$t9,0xc1($sp)
/*    36028:	332d007f */ 	andi	$t5,$t9,0x7f
/*    3602c:	a3ad00c1 */ 	sb	$t5,0xc1($sp)
/*    36030:	93ac00c1 */ 	lbu	$t4,0xc1($sp)
/*    36034:	8fae0060 */ 	lw	$t6,0x60($sp)
/*    36038:	000c7823 */ 	negu	$t7,$t4
/*    3603c:	01cf082a */ 	slt	$at,$t6,$t7
/*    36040:	10200004 */ 	beqz	$at,.L00036054
/*    36044:	00000000 */ 	sll	$zero,$zero,0x0
/*    36048:	93aa00c1 */ 	lbu	$t2,0xc1($sp)
/*    3604c:	000a4023 */ 	negu	$t0,$t2
/*    36050:	afa80060 */ 	sw	$t0,0x60($sp)
.L00036054:
/*    36054:	93a90067 */ 	lbu	$t1,0x67($sp)
/*    36058:	8fab0060 */ 	lw	$t3,0x60($sp)
/*    3605c:	012bc021 */ 	addu	$t8,$t1,$t3
/*    36060:	a3b80067 */ 	sb	$t8,0x67($sp)
/*    36064:	93ae00c3 */ 	lbu	$t6,0xc3($sp)
/*    36068:	8fad00d0 */ 	lw	$t5,0xd0($sp)
/*    3606c:	93b90067 */ 	lbu	$t9,0x67($sp)
/*    36070:	000e7880 */ 	sll	$t7,$t6,0x2
/*    36074:	01ee7823 */ 	subu	$t7,$t7,$t6
/*    36078:	8dac0060 */ 	lw	$t4,0x60($t5)
/*    3607c:	000f7880 */ 	sll	$t7,$t7,0x2
/*    36080:	01ee7821 */ 	addu	$t7,$t7,$t6
/*    36084:	000f7880 */ 	sll	$t7,$t7,0x2
/*    36088:	018f5021 */ 	addu	$t2,$t4,$t7
/*    3608c:	a159000d */ 	sb	$t9,0xd($t2)
/*    36090:	93a80067 */ 	lbu	$t0,0x67($sp)
/*    36094:	93a90066 */ 	lbu	$t1,0x66($sp)
/*    36098:	1109000d */ 	beq	$t0,$t1,.L000360d0
/*    3609c:	00000000 */ 	sll	$zero,$zero,0x0
/*    360a0:	8fab00d0 */ 	lw	$t3,0xd0($sp)
/*    360a4:	8fa500d4 */ 	lw	$a1,0xd4($sp)
/*    360a8:	00003825 */ 	or	$a3,$zero,$zero
/*    360ac:	8d660024 */ 	lw	$a2,0x24($t3)
/*    360b0:	25640048 */ 	addiu	$a0,$t3,0x48
/*    360b4:	00c00821 */ 	addu	$at,$a2,$zero
/*    360b8:	00013080 */ 	sll	$a2,$at,0x2
/*    360bc:	00c13023 */ 	subu	$a2,$a2,$at
/*    360c0:	000630c0 */ 	sll	$a2,$a2,0x3
/*    360c4:	00c13021 */ 	addu	$a2,$a2,$at
/*    360c8:	0c00f184 */ 	jal	func0003c610
/*    360cc:	00063080 */ 	sll	$a2,$a2,0x2
.L000360d0:
/*    360d0:	93b80067 */ 	lbu	$t8,0x67($sp)
/*    360d4:	13000009 */ 	beqz	$t8,.L000360fc
/*    360d8:	00000000 */ 	sll	$zero,$zero,0x0
/*    360dc:	8fad00d0 */ 	lw	$t5,0xd0($sp)
/*    360e0:	93ac00c3 */ 	lbu	$t4,0xc3($sp)
/*    360e4:	240f0001 */ 	addiu	$t7,$zero,0x1
/*    360e8:	95ae0030 */ 	lhu	$t6,0x30($t5)
/*    360ec:	018fc804 */ 	sllv	$t9,$t7,$t4
/*    360f0:	01d95025 */ 	or	$t2,$t6,$t9
/*    360f4:	10000009 */ 	beqz	$zero,.L0003611c
/*    360f8:	a5aa0030 */ 	sh	$t2,0x30($t5)
.L000360fc:
/*    360fc:	8fa800d0 */ 	lw	$t0,0xd0($sp)
/*    36100:	93ab00c3 */ 	lbu	$t3,0xc3($sp)
/*    36104:	24180001 */ 	addiu	$t8,$zero,0x1
/*    36108:	95090030 */ 	lhu	$t1,0x30($t0)
/*    3610c:	01787804 */ 	sllv	$t7,$t8,$t3
/*    36110:	01e06027 */ 	nor	$t4,$t7,$zero
/*    36114:	012c7024 */ 	and	$t6,$t1,$t4
/*    36118:	a50e0030 */ 	sh	$t6,0x30($t0)
.L0003611c:
/*    3611c:	8fa400d0 */ 	lw	$a0,0xd0($sp)
/*    36120:	0c00d3c3 */ 	jal	func00034f0c
/*    36124:	93a500c3 */ 	lbu	$a1,0xc3($sp)
/*    36128:	100003a0 */ 	beqz	$zero,.L00036fac
/*    3612c:	00000000 */ 	sll	$zero,$zero,0x0
.L00036130:
/*    36130:	93b800c3 */ 	lbu	$t8,0xc3($sp)
/*    36134:	8faa00d0 */ 	lw	$t2,0xd0($sp)
/*    36138:	93b900bf */ 	lbu	$t9,0xbf($sp)
/*    3613c:	00185880 */ 	sll	$t3,$t8,0x2
/*    36140:	01785823 */ 	subu	$t3,$t3,$t8
/*    36144:	8d4d0060 */ 	lw	$t5,0x60($t2)
/*    36148:	000b5880 */ 	sll	$t3,$t3,0x2
/*    3614c:	01785821 */ 	addu	$t3,$t3,$t8
/*    36150:	000b5880 */ 	sll	$t3,$t3,0x2
/*    36154:	01ab7821 */ 	addu	$t7,$t5,$t3
/*    36158:	a1f9000d */ 	sb	$t9,0xd($t7)
/*    3615c:	93a800c3 */ 	lbu	$t0,0xc3($sp)
/*    36160:	8fac00d0 */ 	lw	$t4,0xd0($sp)
/*    36164:	93a900bf */ 	lbu	$t1,0xbf($sp)
/*    36168:	00085080 */ 	sll	$t2,$t0,0x2
/*    3616c:	01485023 */ 	subu	$t2,$t2,$t0
/*    36170:	8d8e0060 */ 	lw	$t6,0x60($t4)
/*    36174:	000a5080 */ 	sll	$t2,$t2,0x2
/*    36178:	01485021 */ 	addu	$t2,$t2,$t0
/*    3617c:	000a5080 */ 	sll	$t2,$t2,0x2
/*    36180:	01cac021 */ 	addu	$t8,$t6,$t2
/*    36184:	a309000e */ 	sb	$t1,0xe($t8)
/*    36188:	93ad00bf */ 	lbu	$t5,0xbf($sp)
/*    3618c:	15a0000a */ 	bnez	$t5,.L000361b8
/*    36190:	00000000 */ 	sll	$zero,$zero,0x0
/*    36194:	8fab00d0 */ 	lw	$t3,0xd0($sp)
/*    36198:	93af00c3 */ 	lbu	$t7,0xc3($sp)
/*    3619c:	240c0001 */ 	addiu	$t4,$zero,0x1
/*    361a0:	95790030 */ 	lhu	$t9,0x30($t3)
/*    361a4:	01ec4004 */ 	sllv	$t0,$t4,$t7
/*    361a8:	390effff */ 	xori	$t6,$t0,0xffff
/*    361ac:	032e5024 */ 	and	$t2,$t9,$t6
/*    361b0:	10000008 */ 	beqz	$zero,.L000361d4
/*    361b4:	a56a0030 */ 	sh	$t2,0x30($t3)
.L000361b8:
/*    361b8:	8fa900d0 */ 	lw	$t1,0xd0($sp)
/*    361bc:	93ad00c3 */ 	lbu	$t5,0xc3($sp)
/*    361c0:	240c0001 */ 	addiu	$t4,$zero,0x1
/*    361c4:	95380030 */ 	lhu	$t8,0x30($t1)
/*    361c8:	01ac7804 */ 	sllv	$t7,$t4,$t5
/*    361cc:	030f4025 */ 	or	$t0,$t8,$t7
/*    361d0:	a5280030 */ 	sh	$t0,0x30($t1)
.L000361d4:
/*    361d4:	8fa400d0 */ 	lw	$a0,0xd0($sp)
/*    361d8:	0c00d3c3 */ 	jal	func00034f0c
/*    361dc:	93a500c3 */ 	lbu	$a1,0xc3($sp)
/*    361e0:	10000372 */ 	beqz	$zero,.L00036fac
/*    361e4:	00000000 */ 	sll	$zero,$zero,0x0
/*    361e8:	93ab00c3 */ 	lbu	$t3,0xc3($sp)
/*    361ec:	8fae00d0 */ 	lw	$t6,0xd0($sp)
/*    361f0:	93b900bf */ 	lbu	$t9,0xbf($sp)
/*    361f4:	000b6080 */ 	sll	$t4,$t3,0x2
/*    361f8:	018b6023 */ 	subu	$t4,$t4,$t3
/*    361fc:	8dca0060 */ 	lw	$t2,0x60($t6)
/*    36200:	000c6080 */ 	sll	$t4,$t4,0x2
/*    36204:	018b6021 */ 	addu	$t4,$t4,$t3
/*    36208:	000c6080 */ 	sll	$t4,$t4,0x2
/*    3620c:	014c6821 */ 	addu	$t5,$t2,$t4
/*    36210:	a1b90011 */ 	sb	$t9,0x11($t5)
/*    36214:	8fa400d0 */ 	lw	$a0,0xd0($sp)
/*    36218:	0c00d3ee */ 	jal	func00034fb8
/*    3621c:	93a500c3 */ 	lbu	$a1,0xc3($sp)
/*    36220:	10000362 */ 	beqz	$zero,.L00036fac
/*    36224:	00000000 */ 	sll	$zero,$zero,0x0
/*    36228:	93a900c3 */ 	lbu	$t1,0xc3($sp)
/*    3622c:	8faf00d0 */ 	lw	$t7,0xd0($sp)
/*    36230:	93b800bf */ 	lbu	$t8,0xbf($sp)
/*    36234:	00097080 */ 	sll	$t6,$t1,0x2
/*    36238:	01c97023 */ 	subu	$t6,$t6,$t1
/*    3623c:	8de80060 */ 	lw	$t0,0x60($t7)
/*    36240:	000e7080 */ 	sll	$t6,$t6,0x2
/*    36244:	01c97021 */ 	addu	$t6,$t6,$t1
/*    36248:	000e7080 */ 	sll	$t6,$t6,0x2
/*    3624c:	010e5821 */ 	addu	$t3,$t0,$t6
/*    36250:	a1780012 */ 	sb	$t8,0x12($t3)
/*    36254:	8fa400d0 */ 	lw	$a0,0xd0($sp)
/*    36258:	0c00d3ee */ 	jal	func00034fb8
/*    3625c:	93a500c3 */ 	lbu	$a1,0xc3($sp)
/*    36260:	10000352 */ 	beqz	$zero,.L00036fac
/*    36264:	00000000 */ 	sll	$zero,$zero,0x0
/*    36268:	93ad00c3 */ 	lbu	$t5,0xc3($sp)
/*    3626c:	8fac00d0 */ 	lw	$t4,0xd0($sp)
/*    36270:	93aa00bf */ 	lbu	$t2,0xbf($sp)
/*    36274:	000d7880 */ 	sll	$t7,$t5,0x2
/*    36278:	01ed7823 */ 	subu	$t7,$t7,$t5
/*    3627c:	8d990060 */ 	lw	$t9,0x60($t4)
/*    36280:	000f7880 */ 	sll	$t7,$t7,0x2
/*    36284:	01ed7821 */ 	addu	$t7,$t7,$t5
/*    36288:	000f7880 */ 	sll	$t7,$t7,0x2
/*    3628c:	032f4821 */ 	addu	$t1,$t9,$t7
/*    36290:	a12a0013 */ 	sb	$t2,0x13($t1)
/*    36294:	8fa800d0 */ 	lw	$t0,0xd0($sp)
/*    36298:	8d0e0064 */ 	lw	$t6,0x64($t0)
/*    3629c:	11c0000e */ 	beqz	$t6,.L000362d8
/*    362a0:	afae00c8 */ 	sw	$t6,0xc8($sp)
.L000362a4:
/*    362a4:	8fb800c8 */ 	lw	$t8,0xc8($sp)
/*    362a8:	93ac00c3 */ 	lbu	$t4,0xc3($sp)
/*    362ac:	930b0031 */ 	lbu	$t3,0x31($t8)
/*    362b0:	156c0005 */ 	bne	$t3,$t4,.L000362c8
/*    362b4:	00000000 */ 	sll	$zero,$zero,0x0
/*    362b8:	8fa400c8 */ 	lw	$a0,0xc8($sp)
/*    362bc:	93a500bf */ 	lbu	$a1,0xbf($sp)
/*    362c0:	0c00f9cc */ 	jal	func0003e730
/*    362c4:	24840004 */ 	addiu	$a0,$a0,0x4
.L000362c8:
/*    362c8:	8fad00c8 */ 	lw	$t5,0xc8($sp)
/*    362cc:	8db90000 */ 	lw	$t9,0x0($t5)
/*    362d0:	1720fff4 */ 	bnez	$t9,.L000362a4
/*    362d4:	afb900c8 */ 	sw	$t9,0xc8($sp)
.L000362d8:
/*    362d8:	10000334 */ 	beqz	$zero,.L00036fac
/*    362dc:	00000000 */ 	sll	$zero,$zero,0x0
/*    362e0:	8faf00d0 */ 	lw	$t7,0xd0($sp)
/*    362e4:	8dea0084 */ 	lw	$t2,0x84($t7)
/*    362e8:	1140000d */ 	beqz	$t2,.L00036320
/*    362ec:	00000000 */ 	sll	$zero,$zero,0x0
/*    362f0:	8fa900d0 */ 	lw	$t1,0xd0($sp)
/*    362f4:	93a800bf */ 	lbu	$t0,0xbf($sp)
/*    362f8:	2401ff00 */ 	addiu	$at,$zero,-256
/*    362fc:	8d2b0010 */ 	lw	$t3,0x10($t1)
/*    36300:	310e0007 */ 	andi	$t6,$t0,0x7
/*    36304:	35d80010 */ 	ori	$t8,$t6,0x10
/*    36308:	000b6140 */ 	sll	$t4,$t3,0x5
/*    3630c:	01816824 */ 	and	$t5,$t4,$at
/*    36310:	030d2825 */ 	or	$a1,$t8,$t5
/*    36314:	00003025 */ 	or	$a2,$zero,$zero
/*    36318:	0c012238 */ 	jal	osSendMesg
/*    3631c:	8d240084 */ 	lw	$a0,0x84($t1)
.L00036320:
/*    36320:	10000322 */ 	beqz	$zero,.L00036fac
/*    36324:	00000000 */ 	sll	$zero,$zero,0x0
/*    36328:	93a800c3 */ 	lbu	$t0,0xc3($sp)
/*    3632c:	8faf00d0 */ 	lw	$t7,0xd0($sp)
/*    36330:	93b900bf */ 	lbu	$t9,0xbf($sp)
/*    36334:	00087080 */ 	sll	$t6,$t0,0x2
/*    36338:	01c87023 */ 	subu	$t6,$t6,$t0
/*    3633c:	8dea0060 */ 	lw	$t2,0x60($t7)
/*    36340:	000e7080 */ 	sll	$t6,$t6,0x2
/*    36344:	01c87021 */ 	addu	$t6,$t6,$t0
/*    36348:	000e7080 */ 	sll	$t6,$t6,0x2
/*    3634c:	014e4821 */ 	addu	$t1,$t2,$t6
/*    36350:	a1390009 */ 	sb	$t9,0x9($t1)
/*    36354:	8fab00d0 */ 	lw	$t3,0xd0($sp)
/*    36358:	8d6c0064 */ 	lw	$t4,0x64($t3)
/*    3635c:	1180001c */ 	beqz	$t4,.L000363d0
/*    36360:	afac00c8 */ 	sw	$t4,0xc8($sp)
.L00036364:
/*    36364:	8fb800c8 */ 	lw	$t8,0xc8($sp)
/*    36368:	93af00c3 */ 	lbu	$t7,0xc3($sp)
/*    3636c:	930d0031 */ 	lbu	$t5,0x31($t8)
/*    36370:	15af0013 */ 	bne	$t5,$t7,.L000363c0
/*    36374:	00000000 */ 	sll	$zero,$zero,0x0
/*    36378:	93080034 */ 	lbu	$t0,0x34($t8)
/*    3637c:	24010003 */ 	addiu	$at,$zero,0x3
/*    36380:	1101000f */ 	beq	$t0,$at,.L000363c0
/*    36384:	00000000 */ 	sll	$zero,$zero,0x0
/*    36388:	8fa400c8 */ 	lw	$a0,0xc8($sp)
/*    3638c:	0c00f629 */ 	jal	func0003d8a4
/*    36390:	8fa500d0 */ 	lw	$a1,0xd0($sp)
/*    36394:	a7a200b6 */ 	sh	$v0,0xb6($sp)
/*    36398:	8faa00d0 */ 	lw	$t2,0xd0($sp)
/*    3639c:	8fa400c8 */ 	lw	$a0,0xc8($sp)
/*    363a0:	0c00f6b4 */ 	jal	func0003dad0
/*    363a4:	8d45001c */ 	lw	$a1,0x1c($t2)
/*    363a8:	8fa400c8 */ 	lw	$a0,0xc8($sp)
/*    363ac:	00408025 */ 	or	$s0,$v0,$zero
/*    363b0:	02003025 */ 	or	$a2,$s0,$zero
/*    363b4:	87a500b6 */ 	lh	$a1,0xb6($sp)
/*    363b8:	0c00f33c */ 	jal	func0003ccf0
/*    363bc:	24840004 */ 	addiu	$a0,$a0,0x4
.L000363c0:
/*    363c0:	8fae00c8 */ 	lw	$t6,0xc8($sp)
/*    363c4:	8dd90000 */ 	lw	$t9,0x0($t6)
/*    363c8:	1720ffe6 */ 	bnez	$t9,.L00036364
/*    363cc:	afb900c8 */ 	sw	$t9,0xc8($sp)
.L000363d0:
/*    363d0:	100002f6 */ 	beqz	$zero,.L00036fac
/*    363d4:	00000000 */ 	sll	$zero,$zero,0x0
/*    363d8:	93ad00c3 */ 	lbu	$t5,0xc3($sp)
/*    363dc:	8fab00d0 */ 	lw	$t3,0xd0($sp)
/*    363e0:	93a900bf */ 	lbu	$t1,0xbf($sp)
/*    363e4:	000d7880 */ 	sll	$t7,$t5,0x2
/*    363e8:	01ed7823 */ 	subu	$t7,$t7,$t5
/*    363ec:	8d6c0060 */ 	lw	$t4,0x60($t3)
/*    363f0:	000f7880 */ 	sll	$t7,$t7,0x2
/*    363f4:	01ed7821 */ 	addu	$t7,$t7,$t5
/*    363f8:	000f7880 */ 	sll	$t7,$t7,0x2
/*    363fc:	018fc021 */ 	addu	$t8,$t4,$t7
/*    36400:	a3090008 */ 	sb	$t1,0x8($t8)
/*    36404:	100002e9 */ 	beqz	$zero,.L00036fac
/*    36408:	00000000 */ 	sll	$zero,$zero,0x0
.L0003640c:
/*    3640c:	93b900c3 */ 	lbu	$t9,0xc3($sp)
/*    36410:	8faa00d0 */ 	lw	$t2,0xd0($sp)
/*    36414:	93a800bf */ 	lbu	$t0,0xbf($sp)
/*    36418:	00195880 */ 	sll	$t3,$t9,0x2
/*    3641c:	01795823 */ 	subu	$t3,$t3,$t9
/*    36420:	8d4e0060 */ 	lw	$t6,0x60($t2)
/*    36424:	000b5880 */ 	sll	$t3,$t3,0x2
/*    36428:	01795821 */ 	addu	$t3,$t3,$t9
/*    3642c:	000b5880 */ 	sll	$t3,$t3,0x2
/*    36430:	01cb6821 */ 	addu	$t5,$t6,$t3
/*    36434:	a1a8000c */ 	sb	$t0,0xc($t5)
/*    36438:	8fac00d0 */ 	lw	$t4,0xd0($sp)
/*    3643c:	8d8f0064 */ 	lw	$t7,0x64($t4)
/*    36440:	11e00061 */ 	beqz	$t7,.L000365c8
/*    36444:	afaf00c8 */ 	sw	$t7,0xc8($sp)
.L00036448:
/*    36448:	8fa900c8 */ 	lw	$t1,0xc8($sp)
/*    3644c:	93aa00c3 */ 	lbu	$t2,0xc3($sp)
/*    36450:	91380031 */ 	lbu	$t8,0x31($t1)
/*    36454:	170a0058 */ 	bne	$t8,$t2,.L000365b8
/*    36458:	00000000 */ 	sll	$zero,$zero,0x0
/*    3645c:	91390035 */ 	lbu	$t9,0x35($t1)
/*    36460:	24010003 */ 	addiu	$at,$zero,0x3
/*    36464:	13210054 */ 	beq	$t9,$at,.L000365b8
/*    36468:	00000000 */ 	sll	$zero,$zero,0x0
/*    3646c:	93ae00bf */ 	lbu	$t6,0xbf($sp)
/*    36470:	29c10040 */ 	slti	$at,$t6,0x40
/*    36474:	1420000a */ 	bnez	$at,.L000364a0
/*    36478:	00000000 */ 	sll	$zero,$zero,0x0
/*    3647c:	8fab00c8 */ 	lw	$t3,0xc8($sp)
/*    36480:	91680035 */ 	lbu	$t0,0x35($t3)
/*    36484:	15000004 */ 	bnez	$t0,.L00036498
/*    36488:	00000000 */ 	sll	$zero,$zero,0x0
/*    3648c:	8fac00c8 */ 	lw	$t4,0xc8($sp)
/*    36490:	240d0002 */ 	addiu	$t5,$zero,0x2
/*    36494:	a18d0035 */ 	sb	$t5,0x35($t4)
.L00036498:
/*    36498:	10000047 */ 	beqz	$zero,.L000365b8
/*    3649c:	00000000 */ 	sll	$zero,$zero,0x0
.L000364a0:
/*    364a0:	8faf00c8 */ 	lw	$t7,0xc8($sp)
/*    364a4:	24010002 */ 	addiu	$at,$zero,0x2
/*    364a8:	91f80035 */ 	lbu	$t8,0x35($t7)
/*    364ac:	17010004 */ 	bne	$t8,$at,.L000364c0
/*    364b0:	00000000 */ 	sll	$zero,$zero,0x0
/*    364b4:	8faa00c8 */ 	lw	$t2,0xc8($sp)
/*    364b8:	1000003f */ 	beqz	$zero,.L000365b8
/*    364bc:	a1400035 */ 	sb	$zero,0x35($t2)
.L000364c0:
/*    364c0:	8fa900c8 */ 	lw	$t1,0xc8($sp)
/*    364c4:	24010004 */ 	addiu	$at,$zero,0x4
/*    364c8:	91390035 */ 	lbu	$t9,0x35($t1)
/*    364cc:	1721003a */ 	bne	$t9,$at,.L000365b8
/*    364d0:	00000000 */ 	sll	$zero,$zero,0x0
/*    364d4:	8fab00c8 */ 	lw	$t3,0xc8($sp)
/*    364d8:	240e0003 */ 	addiu	$t6,$zero,0x3
/*    364dc:	a16e0035 */ 	sb	$t6,0x35($t3)
/*    364e0:	8fa80094 */ 	lw	$t0,0x94($sp)
/*    364e4:	910d0024 */ 	lbu	$t5,0x24($t0)
/*    364e8:	11a00021 */ 	beqz	$t5,.L00036570
/*    364ec:	00000000 */ 	sll	$zero,$zero,0x0
/*    364f0:	93b800c3 */ 	lbu	$t8,0xc3($sp)
/*    364f4:	8fac00d0 */ 	lw	$t4,0xd0($sp)
/*    364f8:	00185080 */ 	sll	$t2,$t8,0x2
/*    364fc:	01585023 */ 	subu	$t2,$t2,$t8
/*    36500:	8d8f0060 */ 	lw	$t7,0x60($t4)
/*    36504:	000a5080 */ 	sll	$t2,$t2,0x2
/*    36508:	01585021 */ 	addu	$t2,$t2,$t8
/*    3650c:	000a5080 */ 	sll	$t2,$t2,0x2
/*    36510:	01ea4821 */ 	addu	$t1,$t7,$t2
/*    36514:	8d390020 */ 	lw	$t9,0x20($t1)
/*    36518:	2b213e80 */ 	slti	$at,$t9,0x3e80
/*    3651c:	10200003 */ 	beqz	$at,.L0003652c
/*    36520:	00000000 */ 	sll	$zero,$zero,0x0
/*    36524:	1000000b */ 	beqz	$zero,.L00036554
/*    36528:	24103e80 */ 	addiu	$s0,$zero,0x3e80
.L0003652c:
/*    3652c:	93a800c3 */ 	lbu	$t0,0xc3($sp)
/*    36530:	8fae00d0 */ 	lw	$t6,0xd0($sp)
/*    36534:	00086880 */ 	sll	$t5,$t0,0x2
/*    36538:	01a86823 */ 	subu	$t5,$t5,$t0
/*    3653c:	8dcb0060 */ 	lw	$t3,0x60($t6)
/*    36540:	000d6880 */ 	sll	$t5,$t5,0x2
/*    36544:	01a86821 */ 	addu	$t5,$t5,$t0
/*    36548:	000d6880 */ 	sll	$t5,$t5,0x2
/*    3654c:	016d6021 */ 	addu	$t4,$t3,$t5
/*    36550:	8d900020 */ 	lw	$s0,0x20($t4)
.L00036554:
/*    36554:	8fa500c8 */ 	lw	$a1,0xc8($sp)
/*    36558:	8fa400d0 */ 	lw	$a0,0xd0($sp)
/*    3655c:	02003025 */ 	or	$a2,$s0,$zero
/*    36560:	0c00f4d0 */ 	jal	func0003d340
/*    36564:	24a50004 */ 	addiu	$a1,$a1,0x4
/*    36568:	10000013 */ 	beqz	$zero,.L000365b8
/*    3656c:	00000000 */ 	sll	$zero,$zero,0x0
.L00036570:
/*    36570:	8fb8009c */ 	lw	$t8,0x9c($sp)
/*    36574:	8f0f0020 */ 	lw	$t7,0x20($t8)
/*    36578:	8dea0000 */ 	lw	$t2,0x0($t7)
/*    3657c:	8d490008 */ 	lw	$t1,0x8($t2)
/*    36580:	29213e80 */ 	slti	$at,$t1,0x3e80
/*    36584:	10200003 */ 	beqz	$at,.L00036594
/*    36588:	00000000 */ 	sll	$zero,$zero,0x0
/*    3658c:	10000005 */ 	beqz	$zero,.L000365a4
/*    36590:	24103e80 */ 	addiu	$s0,$zero,0x3e80
.L00036594:
/*    36594:	8fb9009c */ 	lw	$t9,0x9c($sp)
/*    36598:	8f2e0020 */ 	lw	$t6,0x20($t9)
/*    3659c:	8dc80000 */ 	lw	$t0,0x0($t6)
/*    365a0:	8d100008 */ 	lw	$s0,0x8($t0)
.L000365a4:
/*    365a4:	8fa500c8 */ 	lw	$a1,0xc8($sp)
/*    365a8:	8fa400d0 */ 	lw	$a0,0xd0($sp)
/*    365ac:	02003025 */ 	or	$a2,$s0,$zero
/*    365b0:	0c00f4d0 */ 	jal	func0003d340
/*    365b4:	24a50004 */ 	addiu	$a1,$a1,0x4
.L000365b8:
/*    365b8:	8fab00c8 */ 	lw	$t3,0xc8($sp)
/*    365bc:	8d6d0000 */ 	lw	$t5,0x0($t3)
/*    365c0:	15a0ffa1 */ 	bnez	$t5,.L00036448
/*    365c4:	afad00c8 */ 	sw	$t5,0xc8($sp)
.L000365c8:
/*    365c8:	10000278 */ 	beqz	$zero,.L00036fac
/*    365cc:	00000000 */ 	sll	$zero,$zero,0x0
.L000365d0:
/*    365d0:	93af00c3 */ 	lbu	$t7,0xc3($sp)
/*    365d4:	8fac00d0 */ 	lw	$t4,0xd0($sp)
/*    365d8:	93a800bf */ 	lbu	$t0,0xbf($sp)
/*    365dc:	000f5080 */ 	sll	$t2,$t7,0x2
/*    365e0:	014f5023 */ 	subu	$t2,$t2,$t7
/*    365e4:	8d980060 */ 	lw	$t8,0x60($t4)
/*    365e8:	000a5080 */ 	sll	$t2,$t2,0x2
/*    365ec:	014f5021 */ 	addu	$t2,$t2,$t7
/*    365f0:	000a5080 */ 	sll	$t2,$t2,0x2
/*    365f4:	030a4821 */ 	addu	$t1,$t8,$t2
/*    365f8:	9139000a */ 	lbu	$t9,0xa($t1)
/*    365fc:	332e0080 */ 	andi	$t6,$t9,0x80
/*    36600:	01c85825 */ 	or	$t3,$t6,$t0
/*    36604:	a12b000a */ 	sb	$t3,0xa($t1)
/*    36608:	93af00c3 */ 	lbu	$t7,0xc3($sp)
/*    3660c:	8fad00d0 */ 	lw	$t5,0xd0($sp)
/*    36610:	000fc080 */ 	sll	$t8,$t7,0x2
/*    36614:	030fc023 */ 	subu	$t8,$t8,$t7
/*    36618:	8dac0060 */ 	lw	$t4,0x60($t5)
/*    3661c:	0018c080 */ 	sll	$t8,$t8,0x2
/*    36620:	030fc021 */ 	addu	$t8,$t8,$t7
/*    36624:	0018c080 */ 	sll	$t8,$t8,0x2
/*    36628:	01985021 */ 	addu	$t2,$t4,$t8
/*    3662c:	9159000a */ 	lbu	$t9,0xa($t2)
/*    36630:	001971c3 */ 	sra	$t6,$t9,0x7
/*    36634:	a3ae00bf */ 	sb	$t6,0xbf($sp)
.L00036638:
/*    36638:	93a900c3 */ 	lbu	$t1,0xc3($sp)
/*    3663c:	8fa800d0 */ 	lw	$t0,0xd0($sp)
/*    36640:	93aa00bf */ 	lbu	$t2,0xbf($sp)
/*    36644:	00096880 */ 	sll	$t5,$t1,0x2
/*    36648:	01a96823 */ 	subu	$t5,$t5,$t1
/*    3664c:	8d0b0060 */ 	lw	$t3,0x60($t0)
/*    36650:	000d6880 */ 	sll	$t5,$t5,0x2
/*    36654:	01a96821 */ 	addu	$t5,$t5,$t1
/*    36658:	000d6880 */ 	sll	$t5,$t5,0x2
/*    3665c:	016d7821 */ 	addu	$t7,$t3,$t5
/*    36660:	91ec000a */ 	lbu	$t4,0xa($t7)
/*    36664:	000ac9c0 */ 	sll	$t9,$t2,0x7
/*    36668:	3198007f */ 	andi	$t8,$t4,0x7f
/*    3666c:	03197025 */ 	or	$t6,$t8,$t9
/*    36670:	a1ee000a */ 	sb	$t6,0xa($t7)
/*    36674:	8fa800d0 */ 	lw	$t0,0xd0($sp)
/*    36678:	8d090064 */ 	lw	$t1,0x64($t0)
/*    3667c:	11200017 */ 	beqz	$t1,.L000366dc
/*    36680:	afa900c8 */ 	sw	$t1,0xc8($sp)
.L00036684:
/*    36684:	8fab00c8 */ 	lw	$t3,0xc8($sp)
/*    36688:	93ac00c3 */ 	lbu	$t4,0xc3($sp)
/*    3668c:	916d0031 */ 	lbu	$t5,0x31($t3)
/*    36690:	15ac000e */ 	bne	$t5,$t4,.L000366cc
/*    36694:	00000000 */ 	sll	$zero,$zero,0x0
/*    36698:	93b900c3 */ 	lbu	$t9,0xc3($sp)
/*    3669c:	8faa00d0 */ 	lw	$t2,0xd0($sp)
/*    366a0:	8fa400c8 */ 	lw	$a0,0xc8($sp)
/*    366a4:	00197080 */ 	sll	$t6,$t9,0x2
/*    366a8:	01d97023 */ 	subu	$t6,$t6,$t9
/*    366ac:	8d580060 */ 	lw	$t8,0x60($t2)
/*    366b0:	000e7080 */ 	sll	$t6,$t6,0x2
/*    366b4:	01d97021 */ 	addu	$t6,$t6,$t9
/*    366b8:	000e7080 */ 	sll	$t6,$t6,0x2
/*    366bc:	030e7821 */ 	addu	$t7,$t8,$t6
/*    366c0:	91e5000a */ 	lbu	$a1,0xa($t7)
/*    366c4:	0c00f414 */ 	jal	func0003d050
/*    366c8:	24840004 */ 	addiu	$a0,$a0,0x4
.L000366cc:
/*    366cc:	8fa800c8 */ 	lw	$t0,0xc8($sp)
/*    366d0:	8d090000 */ 	lw	$t1,0x0($t0)
/*    366d4:	1520ffeb */ 	bnez	$t1,.L00036684
/*    366d8:	afa900c8 */ 	sw	$t1,0xc8($sp)
.L000366dc:
/*    366dc:	10000233 */ 	beqz	$zero,.L00036fac
/*    366e0:	00000000 */ 	sll	$zero,$zero,0x0
.L000366e4:
/*    366e4:	3c0d8006 */ 	lui	$t5,0x8006
/*    366e8:	8dadf114 */ 	lw	$t5,-0xeec($t5)
/*    366ec:	93ab00bf */ 	lbu	$t3,0xbf($sp)
/*    366f0:	8dac003c */ 	lw	$t4,0x3c($t5)
/*    366f4:	016c082a */ 	slt	$at,$t3,$t4
/*    366f8:	1020000c */ 	beqz	$at,.L0003672c
/*    366fc:	00000000 */ 	sll	$zero,$zero,0x0
/*    36700:	93ae00c3 */ 	lbu	$t6,0xc3($sp)
/*    36704:	8fb900d0 */ 	lw	$t9,0xd0($sp)
/*    36708:	93aa00bf */ 	lbu	$t2,0xbf($sp)
/*    3670c:	000e7880 */ 	sll	$t7,$t6,0x2
/*    36710:	01ee7823 */ 	subu	$t7,$t7,$t6
/*    36714:	8f380060 */ 	lw	$t8,0x60($t9)
/*    36718:	000f7880 */ 	sll	$t7,$t7,0x2
/*    3671c:	01ee7821 */ 	addu	$t7,$t7,$t6
/*    36720:	000f7880 */ 	sll	$t7,$t7,0x2
/*    36724:	030f4021 */ 	addu	$t0,$t8,$t7
/*    36728:	a10a000b */ 	sb	$t2,0xb($t0)
.L0003672c:
/*    3672c:	1000021f */ 	beqz	$zero,.L00036fac
/*    36730:	00000000 */ 	sll	$zero,$zero,0x0
/*    36734:	0c0040db */ 	jal	func0001036c
/*    36738:	93a400bf */ 	lbu	$a0,0xbf($sp)
/*    3673c:	1000021b */ 	beqz	$zero,.L00036fac
/*    36740:	00000000 */ 	sll	$zero,$zero,0x0
/*    36744:	93ac00c3 */ 	lbu	$t4,0xc3($sp)
/*    36748:	8fad00d0 */ 	lw	$t5,0xd0($sp)
/*    3674c:	93a900bf */ 	lbu	$t1,0xbf($sp)
/*    36750:	000cc880 */ 	sll	$t9,$t4,0x2
/*    36754:	032cc823 */ 	subu	$t9,$t9,$t4
/*    36758:	8dab0060 */ 	lw	$t3,0x60($t5)
/*    3675c:	0019c880 */ 	sll	$t9,$t9,0x2
/*    36760:	032cc821 */ 	addu	$t9,$t9,$t4
/*    36764:	0019c880 */ 	sll	$t9,$t9,0x2
/*    36768:	01797021 */ 	addu	$t6,$t3,$t9
/*    3676c:	a1c90032 */ 	sb	$t1,0x32($t6)
/*    36770:	1000020e */ 	beqz	$zero,.L00036fac
/*    36774:	00000000 */ 	sll	$zero,$zero,0x0
/*    36778:	93ac00c3 */ 	lbu	$t4,0xc3($sp)
/*    3677c:	93b800bf */ 	lbu	$t8,0xbf($sp)
/*    36780:	8fa800d0 */ 	lw	$t0,0xd0($sp)
/*    36784:	000c5880 */ 	sll	$t3,$t4,0x2
/*    36788:	3c0a8006 */ 	lui	$t2,0x8006
/*    3678c:	016c5823 */ 	subu	$t3,$t3,$t4
/*    36790:	00187880 */ 	sll	$t7,$t8,0x2
/*    36794:	8d0d0060 */ 	lw	$t5,0x60($t0)
/*    36798:	014f5021 */ 	addu	$t2,$t2,$t7
/*    3679c:	000b5880 */ 	sll	$t3,$t3,0x2
/*    367a0:	8d4af150 */ 	lw	$t2,-0xeb0($t2)
/*    367a4:	016c5821 */ 	addu	$t3,$t3,$t4
/*    367a8:	000b5880 */ 	sll	$t3,$t3,0x2
/*    367ac:	01abc821 */ 	addu	$t9,$t5,$t3
/*    367b0:	af2a0018 */ 	sw	$t2,0x18($t9)
/*    367b4:	93af00c3 */ 	lbu	$t7,0xc3($sp)
/*    367b8:	8fae00d0 */ 	lw	$t6,0xd0($sp)
/*    367bc:	24090001 */ 	addiu	$t1,$zero,0x1
/*    367c0:	000f4080 */ 	sll	$t0,$t7,0x2
/*    367c4:	010f4023 */ 	subu	$t0,$t0,$t7
/*    367c8:	8dd80060 */ 	lw	$t8,0x60($t6)
/*    367cc:	00084080 */ 	sll	$t0,$t0,0x2
/*    367d0:	010f4021 */ 	addu	$t0,$t0,$t7
/*    367d4:	00084080 */ 	sll	$t0,$t0,0x2
/*    367d8:	03086021 */ 	addu	$t4,$t8,$t0
/*    367dc:	a1890024 */ 	sb	$t1,0x24($t4)
/*    367e0:	100001f2 */ 	beqz	$zero,.L00036fac
/*    367e4:	00000000 */ 	sll	$zero,$zero,0x0
/*    367e8:	93b900c3 */ 	lbu	$t9,0xc3($sp)
/*    367ec:	8fab00d0 */ 	lw	$t3,0xd0($sp)
/*    367f0:	93ad00bf */ 	lbu	$t5,0xbf($sp)
/*    367f4:	00197080 */ 	sll	$t6,$t9,0x2
/*    367f8:	01d97023 */ 	subu	$t6,$t6,$t9
/*    367fc:	8d6a0060 */ 	lw	$t2,0x60($t3)
/*    36800:	000e7080 */ 	sll	$t6,$t6,0x2
/*    36804:	01d97021 */ 	addu	$t6,$t6,$t9
/*    36808:	000e7080 */ 	sll	$t6,$t6,0x2
/*    3680c:	014e7821 */ 	addu	$t7,$t2,$t6
/*    36810:	a1ed0025 */ 	sb	$t5,0x25($t7)
/*    36814:	93ac00c3 */ 	lbu	$t4,0xc3($sp)
/*    36818:	8fa800d0 */ 	lw	$t0,0xd0($sp)
/*    3681c:	24180001 */ 	addiu	$t8,$zero,0x1
/*    36820:	000c5880 */ 	sll	$t3,$t4,0x2
/*    36824:	016c5823 */ 	subu	$t3,$t3,$t4
/*    36828:	8d090060 */ 	lw	$t1,0x60($t0)
/*    3682c:	000b5880 */ 	sll	$t3,$t3,0x2
/*    36830:	016c5821 */ 	addu	$t3,$t3,$t4
/*    36834:	000b5880 */ 	sll	$t3,$t3,0x2
/*    36838:	012bc821 */ 	addu	$t9,$t1,$t3
/*    3683c:	a3380024 */ 	sb	$t8,0x24($t9)
/*    36840:	100001da */ 	beqz	$zero,.L00036fac
/*    36844:	00000000 */ 	sll	$zero,$zero,0x0
/*    36848:	93ac00c3 */ 	lbu	$t4,0xc3($sp)
/*    3684c:	93aa00bf */ 	lbu	$t2,0xbf($sp)
/*    36850:	8faf00d0 */ 	lw	$t7,0xd0($sp)
/*    36854:	000c4880 */ 	sll	$t1,$t4,0x2
/*    36858:	3c0d8006 */ 	lui	$t5,0x8006
/*    3685c:	012c4823 */ 	subu	$t1,$t1,$t4
/*    36860:	000a7080 */ 	sll	$t6,$t2,0x2
/*    36864:	8de80060 */ 	lw	$t0,0x60($t7)
/*    36868:	01ae6821 */ 	addu	$t5,$t5,$t6
/*    3686c:	00094880 */ 	sll	$t1,$t1,0x2
/*    36870:	8dadf150 */ 	lw	$t5,-0xeb0($t5)
/*    36874:	012c4821 */ 	addu	$t1,$t1,$t4
/*    36878:	00094880 */ 	sll	$t1,$t1,0x2
/*    3687c:	01095821 */ 	addu	$t3,$t0,$t1
/*    36880:	ad6d001c */ 	sw	$t5,0x1c($t3)
/*    36884:	93ae00c3 */ 	lbu	$t6,0xc3($sp)
/*    36888:	8fb900d0 */ 	lw	$t9,0xd0($sp)
/*    3688c:	24180001 */ 	addiu	$t8,$zero,0x1
/*    36890:	000e7880 */ 	sll	$t7,$t6,0x2
/*    36894:	01ee7823 */ 	subu	$t7,$t7,$t6
/*    36898:	8f2a0060 */ 	lw	$t2,0x60($t9)
/*    3689c:	000f7880 */ 	sll	$t7,$t7,0x2
/*    368a0:	01ee7821 */ 	addu	$t7,$t7,$t6
/*    368a4:	000f7880 */ 	sll	$t7,$t7,0x2
/*    368a8:	014f6021 */ 	addu	$t4,$t2,$t7
/*    368ac:	a1980024 */ 	sb	$t8,0x24($t4)
/*    368b0:	100001be */ 	beqz	$zero,.L00036fac
/*    368b4:	00000000 */ 	sll	$zero,$zero,0x0
/*    368b8:	93ab00c3 */ 	lbu	$t3,0xc3($sp)
/*    368bc:	8fa900d0 */ 	lw	$t1,0xd0($sp)
/*    368c0:	93a800bf */ 	lbu	$t0,0xbf($sp)
/*    368c4:	000bc880 */ 	sll	$t9,$t3,0x2
/*    368c8:	032bc823 */ 	subu	$t9,$t9,$t3
/*    368cc:	8d2d0060 */ 	lw	$t5,0x60($t1)
/*    368d0:	0019c880 */ 	sll	$t9,$t9,0x2
/*    368d4:	032bc821 */ 	addu	$t9,$t9,$t3
/*    368d8:	0019c880 */ 	sll	$t9,$t9,0x2
/*    368dc:	01b97021 */ 	addu	$t6,$t5,$t9
/*    368e0:	a1c80026 */ 	sb	$t0,0x26($t6)
/*    368e4:	93ac00c3 */ 	lbu	$t4,0xc3($sp)
/*    368e8:	8faf00d0 */ 	lw	$t7,0xd0($sp)
/*    368ec:	240a0001 */ 	addiu	$t2,$zero,0x1
/*    368f0:	000c4880 */ 	sll	$t1,$t4,0x2
/*    368f4:	012c4823 */ 	subu	$t1,$t1,$t4
/*    368f8:	8df80060 */ 	lw	$t8,0x60($t7)
/*    368fc:	00094880 */ 	sll	$t1,$t1,0x2
/*    36900:	012c4821 */ 	addu	$t1,$t1,$t4
/*    36904:	00094880 */ 	sll	$t1,$t1,0x2
/*    36908:	03095821 */ 	addu	$t3,$t8,$t1
/*    3690c:	a16a0024 */ 	sb	$t2,0x24($t3)
/*    36910:	100001a6 */ 	beqz	$zero,.L00036fac
/*    36914:	00000000 */ 	sll	$zero,$zero,0x0
/*    36918:	93ac00c3 */ 	lbu	$t4,0xc3($sp)
/*    3691c:	93ad00bf */ 	lbu	$t5,0xbf($sp)
/*    36920:	8fae00d0 */ 	lw	$t6,0xd0($sp)
/*    36924:	000cc080 */ 	sll	$t8,$t4,0x2
/*    36928:	3c088006 */ 	lui	$t0,0x8006
/*    3692c:	030cc023 */ 	subu	$t8,$t8,$t4
/*    36930:	000dc880 */ 	sll	$t9,$t5,0x2
/*    36934:	8dcf0060 */ 	lw	$t7,0x60($t6)
/*    36938:	01194021 */ 	addu	$t0,$t0,$t9
/*    3693c:	0018c080 */ 	sll	$t8,$t8,0x2
/*    36940:	8d08f150 */ 	lw	$t0,-0xeb0($t0)
/*    36944:	030cc021 */ 	addu	$t8,$t8,$t4
/*    36948:	0018c080 */ 	sll	$t8,$t8,0x2
/*    3694c:	01f84821 */ 	addu	$t1,$t7,$t8
/*    36950:	ad280020 */ 	sw	$t0,0x20($t1)
/*    36954:	93b900c3 */ 	lbu	$t9,0xc3($sp)
/*    36958:	8fab00d0 */ 	lw	$t3,0xd0($sp)
/*    3695c:	240a0001 */ 	addiu	$t2,$zero,0x1
/*    36960:	00197080 */ 	sll	$t6,$t9,0x2
/*    36964:	01d97023 */ 	subu	$t6,$t6,$t9
/*    36968:	8d6d0060 */ 	lw	$t5,0x60($t3)
/*    3696c:	000e7080 */ 	sll	$t6,$t6,0x2
/*    36970:	01d97021 */ 	addu	$t6,$t6,$t9
/*    36974:	000e7080 */ 	sll	$t6,$t6,0x2
/*    36978:	01ae6021 */ 	addu	$t4,$t5,$t6
/*    3697c:	a18a0024 */ 	sb	$t2,0x24($t4)
/*    36980:	1000018a */ 	beqz	$zero,.L00036fac
/*    36984:	00000000 */ 	sll	$zero,$zero,0x0
/*    36988:	93ab00c3 */ 	lbu	$t3,0xc3($sp)
/*    3698c:	8fa800d0 */ 	lw	$t0,0xd0($sp)
/*    36990:	93af00bf */ 	lbu	$t7,0xbf($sp)
/*    36994:	000bc880 */ 	sll	$t9,$t3,0x2
/*    36998:	032bc823 */ 	subu	$t9,$t9,$t3
/*    3699c:	8d090060 */ 	lw	$t1,0x60($t0)
/*    369a0:	0019c880 */ 	sll	$t9,$t9,0x2
/*    369a4:	032bc821 */ 	addu	$t9,$t9,$t3
/*    369a8:	0019c880 */ 	sll	$t9,$t9,0x2
/*    369ac:	25f8ffc0 */ 	addiu	$t8,$t7,-64
/*    369b0:	01396821 */ 	addu	$t5,$t1,$t9
/*    369b4:	a1b80027 */ 	sb	$t8,0x27($t5)
/*    369b8:	93af00c3 */ 	lbu	$t7,0xc3($sp)
/*    369bc:	8faa00d0 */ 	lw	$t2,0xd0($sp)
/*    369c0:	240e0001 */ 	addiu	$t6,$zero,0x1
/*    369c4:	000f4080 */ 	sll	$t0,$t7,0x2
/*    369c8:	010f4023 */ 	subu	$t0,$t0,$t7
/*    369cc:	8d4c0060 */ 	lw	$t4,0x60($t2)
/*    369d0:	00084080 */ 	sll	$t0,$t0,0x2
/*    369d4:	010f4021 */ 	addu	$t0,$t0,$t7
/*    369d8:	00084080 */ 	sll	$t0,$t0,0x2
/*    369dc:	01885821 */ 	addu	$t3,$t4,$t0
/*    369e0:	a16e0024 */ 	sb	$t6,0x24($t3)
/*    369e4:	10000171 */ 	beqz	$zero,.L00036fac
/*    369e8:	00000000 */ 	sll	$zero,$zero,0x0
/*    369ec:	93b800c3 */ 	lbu	$t8,0xc3($sp)
/*    369f0:	8fa900d0 */ 	lw	$t1,0xd0($sp)
/*    369f4:	24010064 */ 	addiu	$at,$zero,0x64
/*    369f8:	00186880 */ 	sll	$t5,$t8,0x2
/*    369fc:	01b86823 */ 	subu	$t5,$t5,$t8
/*    36a00:	8d390060 */ 	lw	$t9,0x60($t1)
/*    36a04:	000d6880 */ 	sll	$t5,$t5,0x2
/*    36a08:	01b86821 */ 	addu	$t5,$t5,$t8
/*    36a0c:	000d6880 */ 	sll	$t5,$t5,0x2
/*    36a10:	032d5021 */ 	addu	$t2,$t9,$t5
/*    36a14:	854f0004 */ 	lh	$t7,0x4($t2)
/*    36a18:	01e1001a */ 	div	$zero,$t7,$at
/*    36a1c:	00006012 */ 	mflo	$t4
/*    36a20:	a54c0004 */ 	sh	$t4,0x4($t2)
/*    36a24:	00000000 */ 	sll	$zero,$zero,0x0
/*    36a28:	93ab00c3 */ 	lbu	$t3,0xc3($sp)
/*    36a2c:	8fa800d0 */ 	lw	$t0,0xd0($sp)
/*    36a30:	000b4880 */ 	sll	$t1,$t3,0x2
/*    36a34:	012b4823 */ 	subu	$t1,$t1,$t3
/*    36a38:	8d0e0060 */ 	lw	$t6,0x60($t0)
/*    36a3c:	00094880 */ 	sll	$t1,$t1,0x2
/*    36a40:	012b4821 */ 	addu	$t1,$t1,$t3
/*    36a44:	00094880 */ 	sll	$t1,$t1,0x2
/*    36a48:	01c9c021 */ 	addu	$t8,$t6,$t1
/*    36a4c:	87190004 */ 	lh	$t9,0x4($t8)
/*    36a50:	00196880 */ 	sll	$t5,$t9,0x2
/*    36a54:	01b96823 */ 	subu	$t5,$t5,$t9
/*    36a58:	000d68c0 */ 	sll	$t5,$t5,0x3
/*    36a5c:	01b96821 */ 	addu	$t5,$t5,$t9
/*    36a60:	000d6880 */ 	sll	$t5,$t5,0x2
/*    36a64:	a70d0004 */ 	sh	$t5,0x4($t8)
/*    36a68:	93aa00c3 */ 	lbu	$t2,0xc3($sp)
/*    36a6c:	8faf00d0 */ 	lw	$t7,0xd0($sp)
/*    36a70:	93a900bf */ 	lbu	$t1,0xbf($sp)
/*    36a74:	000a4080 */ 	sll	$t0,$t2,0x2
/*    36a78:	010a4023 */ 	subu	$t0,$t0,$t2
/*    36a7c:	8dec0060 */ 	lw	$t4,0x60($t7)
/*    36a80:	00084080 */ 	sll	$t0,$t0,0x2
/*    36a84:	010a4021 */ 	addu	$t0,$t0,$t2
/*    36a88:	00084080 */ 	sll	$t0,$t0,0x2
/*    36a8c:	01885821 */ 	addu	$t3,$t4,$t0
/*    36a90:	856e0004 */ 	lh	$t6,0x4($t3)
/*    36a94:	01c9c821 */ 	addu	$t9,$t6,$t1
/*    36a98:	a5790004 */ 	sh	$t9,0x4($t3)
/*    36a9c:	10000143 */ 	beqz	$zero,.L00036fac
/*    36aa0:	00000000 */ 	sll	$zero,$zero,0x0
/*    36aa4:	93af00c3 */ 	lbu	$t7,0xc3($sp)
/*    36aa8:	8fad00d0 */ 	lw	$t5,0xd0($sp)
/*    36aac:	24010064 */ 	addiu	$at,$zero,0x64
/*    36ab0:	000f5080 */ 	sll	$t2,$t7,0x2
/*    36ab4:	014f5023 */ 	subu	$t2,$t2,$t7
/*    36ab8:	8db80060 */ 	lw	$t8,0x60($t5)
/*    36abc:	000a5080 */ 	sll	$t2,$t2,0x2
/*    36ac0:	014f5021 */ 	addu	$t2,$t2,$t7
/*    36ac4:	000a5080 */ 	sll	$t2,$t2,0x2
/*    36ac8:	030a6021 */ 	addu	$t4,$t8,$t2
/*    36acc:	85880004 */ 	lh	$t0,0x4($t4)
/*    36ad0:	0101001a */ 	div	$zero,$t0,$at
/*    36ad4:	00007010 */ 	mfhi	$t6
/*    36ad8:	a58e0004 */ 	sh	$t6,0x4($t4)
/*    36adc:	00000000 */ 	sll	$zero,$zero,0x0
/*    36ae0:	93ab00c3 */ 	lbu	$t3,0xc3($sp)
/*    36ae4:	8fa900d0 */ 	lw	$t1,0xd0($sp)
/*    36ae8:	93aa00bf */ 	lbu	$t2,0xbf($sp)
/*    36aec:	000b6880 */ 	sll	$t5,$t3,0x2
/*    36af0:	01ab6823 */ 	subu	$t5,$t5,$t3
/*    36af4:	8d390060 */ 	lw	$t9,0x60($t1)
/*    36af8:	000d6880 */ 	sll	$t5,$t5,0x2
/*    36afc:	01ab6821 */ 	addu	$t5,$t5,$t3
/*    36b00:	000d6880 */ 	sll	$t5,$t5,0x2
/*    36b04:	000a4080 */ 	sll	$t0,$t2,0x2
/*    36b08:	010a4023 */ 	subu	$t0,$t0,$t2
/*    36b0c:	032d7821 */ 	addu	$t7,$t9,$t5
/*    36b10:	85f80004 */ 	lh	$t8,0x4($t7)
/*    36b14:	000840c0 */ 	sll	$t0,$t0,0x3
/*    36b18:	010a4021 */ 	addu	$t0,$t0,$t2
/*    36b1c:	00084080 */ 	sll	$t0,$t0,0x2
/*    36b20:	03087021 */ 	addu	$t6,$t8,$t0
/*    36b24:	a5ee0004 */ 	sh	$t6,0x4($t7)
/*    36b28:	10000120 */ 	beqz	$zero,.L00036fac
/*    36b2c:	00000000 */ 	sll	$zero,$zero,0x0
/*    36b30:	93ac00bf */ 	lbu	$t4,0xbf($sp)
/*    36b34:	11800004 */ 	beqz	$t4,.L00036b48
/*    36b38:	00000000 */ 	sll	$zero,$zero,0x0
/*    36b3c:	93a900bf */ 	lbu	$t1,0xbf($sp)
/*    36b40:	252b0080 */ 	addiu	$t3,$t1,0x80
/*    36b44:	a3ab00bf */ 	sb	$t3,0xbf($sp)
.L00036b48:
/*    36b48:	93b800c3 */ 	lbu	$t8,0xc3($sp)
/*    36b4c:	8fad00d0 */ 	lw	$t5,0xd0($sp)
/*    36b50:	93b900bf */ 	lbu	$t9,0xbf($sp)
/*    36b54:	00184080 */ 	sll	$t0,$t8,0x2
/*    36b58:	01184023 */ 	subu	$t0,$t0,$t8
/*    36b5c:	8daa0060 */ 	lw	$t2,0x60($t5)
/*    36b60:	00084080 */ 	sll	$t0,$t0,0x2
/*    36b64:	01184021 */ 	addu	$t0,$t0,$t8
/*    36b68:	00084080 */ 	sll	$t0,$t0,0x2
/*    36b6c:	01487021 */ 	addu	$t6,$t2,$t0
/*    36b70:	a1d9002c */ 	sb	$t9,0x2c($t6)
/*    36b74:	93ab00c3 */ 	lbu	$t3,0xc3($sp)
/*    36b78:	8fac00d0 */ 	lw	$t4,0xd0($sp)
/*    36b7c:	240f0001 */ 	addiu	$t7,$zero,0x1
/*    36b80:	000b6880 */ 	sll	$t5,$t3,0x2
/*    36b84:	01ab6823 */ 	subu	$t5,$t5,$t3
/*    36b88:	8d890060 */ 	lw	$t1,0x60($t4)
/*    36b8c:	000d6880 */ 	sll	$t5,$t5,0x2
/*    36b90:	01ab6821 */ 	addu	$t5,$t5,$t3
/*    36b94:	000d6880 */ 	sll	$t5,$t5,0x2
/*    36b98:	012dc021 */ 	addu	$t8,$t1,$t5
/*    36b9c:	a30f0024 */ 	sb	$t7,0x24($t8)
/*    36ba0:	10000102 */ 	beqz	$zero,.L00036fac
/*    36ba4:	00000000 */ 	sll	$zero,$zero,0x0
/*    36ba8:	93ae00c3 */ 	lbu	$t6,0xc3($sp)
/*    36bac:	8fa800d0 */ 	lw	$t0,0xd0($sp)
/*    36bb0:	93aa00bf */ 	lbu	$t2,0xbf($sp)
/*    36bb4:	000e6080 */ 	sll	$t4,$t6,0x2
/*    36bb8:	018e6023 */ 	subu	$t4,$t4,$t6
/*    36bbc:	8d190060 */ 	lw	$t9,0x60($t0)
/*    36bc0:	000c6080 */ 	sll	$t4,$t4,0x2
/*    36bc4:	018e6021 */ 	addu	$t4,$t4,$t6
/*    36bc8:	000c6080 */ 	sll	$t4,$t4,0x2
/*    36bcc:	032c5821 */ 	addu	$t3,$t9,$t4
/*    36bd0:	a16a002d */ 	sb	$t2,0x2d($t3)
/*    36bd4:	93b800c3 */ 	lbu	$t8,0xc3($sp)
/*    36bd8:	8fad00d0 */ 	lw	$t5,0xd0($sp)
/*    36bdc:	24090001 */ 	addiu	$t1,$zero,0x1
/*    36be0:	00184080 */ 	sll	$t0,$t8,0x2
/*    36be4:	01184023 */ 	subu	$t0,$t0,$t8
/*    36be8:	8daf0060 */ 	lw	$t7,0x60($t5)
/*    36bec:	00084080 */ 	sll	$t0,$t0,0x2
/*    36bf0:	01184021 */ 	addu	$t0,$t0,$t8
/*    36bf4:	00084080 */ 	sll	$t0,$t0,0x2
/*    36bf8:	01e87021 */ 	addu	$t6,$t7,$t0
/*    36bfc:	a1c90024 */ 	sb	$t1,0x24($t6)
/*    36c00:	100000ea */ 	beqz	$zero,.L00036fac
/*    36c04:	00000000 */ 	sll	$zero,$zero,0x0
/*    36c08:	93ad00c3 */ 	lbu	$t5,0xc3($sp)
/*    36c0c:	8faa00d0 */ 	lw	$t2,0xd0($sp)
/*    36c10:	93b900bf */ 	lbu	$t9,0xbf($sp)
/*    36c14:	000dc080 */ 	sll	$t8,$t5,0x2
/*    36c18:	030dc023 */ 	subu	$t8,$t8,$t5
/*    36c1c:	8d4b0060 */ 	lw	$t3,0x60($t2)
/*    36c20:	0018c080 */ 	sll	$t8,$t8,0x2
/*    36c24:	030dc021 */ 	addu	$t8,$t8,$t5
/*    36c28:	0018c080 */ 	sll	$t8,$t8,0x2
/*    36c2c:	00196040 */ 	sll	$t4,$t9,0x1
/*    36c30:	01787821 */ 	addu	$t7,$t3,$t8
/*    36c34:	a1ec002e */ 	sb	$t4,0x2e($t7)
/*    36c38:	93b900c3 */ 	lbu	$t9,0xc3($sp)
/*    36c3c:	8fa900d0 */ 	lw	$t1,0xd0($sp)
/*    36c40:	24080001 */ 	addiu	$t0,$zero,0x1
/*    36c44:	00195080 */ 	sll	$t2,$t9,0x2
/*    36c48:	01595023 */ 	subu	$t2,$t2,$t9
/*    36c4c:	8d2e0060 */ 	lw	$t6,0x60($t1)
/*    36c50:	000a5080 */ 	sll	$t2,$t2,0x2
/*    36c54:	01595021 */ 	addu	$t2,$t2,$t9
/*    36c58:	000a5080 */ 	sll	$t2,$t2,0x2
/*    36c5c:	01ca6821 */ 	addu	$t5,$t6,$t2
/*    36c60:	a1a80024 */ 	sb	$t0,0x24($t5)
/*    36c64:	100000d1 */ 	beqz	$zero,.L00036fac
/*    36c68:	00000000 */ 	sll	$zero,$zero,0x0
/*    36c6c:	93af00c3 */ 	lbu	$t7,0xc3($sp)
/*    36c70:	8fb800d0 */ 	lw	$t8,0xd0($sp)
/*    36c74:	93ab00bf */ 	lbu	$t3,0xbf($sp)
/*    36c78:	000f4880 */ 	sll	$t1,$t7,0x2
/*    36c7c:	012f4823 */ 	subu	$t1,$t1,$t7
/*    36c80:	8f0c0060 */ 	lw	$t4,0x60($t8)
/*    36c84:	00094880 */ 	sll	$t1,$t1,0x2
/*    36c88:	012f4821 */ 	addu	$t1,$t1,$t7
/*    36c8c:	00094880 */ 	sll	$t1,$t1,0x2
/*    36c90:	0189c821 */ 	addu	$t9,$t4,$t1
/*    36c94:	a32b002f */ 	sb	$t3,0x2f($t9)
/*    36c98:	93ad00c3 */ 	lbu	$t5,0xc3($sp)
/*    36c9c:	8faa00d0 */ 	lw	$t2,0xd0($sp)
/*    36ca0:	240e0001 */ 	addiu	$t6,$zero,0x1
/*    36ca4:	000dc080 */ 	sll	$t8,$t5,0x2
/*    36ca8:	030dc023 */ 	subu	$t8,$t8,$t5
/*    36cac:	8d480060 */ 	lw	$t0,0x60($t2)
/*    36cb0:	0018c080 */ 	sll	$t8,$t8,0x2
/*    36cb4:	030dc021 */ 	addu	$t8,$t8,$t5
/*    36cb8:	0018c080 */ 	sll	$t8,$t8,0x2
/*    36cbc:	01187821 */ 	addu	$t7,$t0,$t8
/*    36cc0:	a1ee0024 */ 	sb	$t6,0x24($t7)
/*    36cc4:	100000b9 */ 	beqz	$zero,.L00036fac
/*    36cc8:	00000000 */ 	sll	$zero,$zero,0x0
/*    36ccc:	93b900c3 */ 	lbu	$t9,0xc3($sp)
/*    36cd0:	8fa900d0 */ 	lw	$t1,0xd0($sp)
/*    36cd4:	93ac00bf */ 	lbu	$t4,0xbf($sp)
/*    36cd8:	00195080 */ 	sll	$t2,$t9,0x2
/*    36cdc:	01595023 */ 	subu	$t2,$t2,$t9
/*    36ce0:	8d2b0060 */ 	lw	$t3,0x60($t1)
/*    36ce4:	000a5080 */ 	sll	$t2,$t2,0x2
/*    36ce8:	01595021 */ 	addu	$t2,$t2,$t9
/*    36cec:	000a5080 */ 	sll	$t2,$t2,0x2
/*    36cf0:	016a6821 */ 	addu	$t5,$t3,$t2
/*    36cf4:	a1ac0028 */ 	sb	$t4,0x28($t5)
/*    36cf8:	93af00c3 */ 	lbu	$t7,0xc3($sp)
/*    36cfc:	8fb800d0 */ 	lw	$t8,0xd0($sp)
/*    36d00:	24080001 */ 	addiu	$t0,$zero,0x1
/*    36d04:	000f4880 */ 	sll	$t1,$t7,0x2
/*    36d08:	012f4823 */ 	subu	$t1,$t1,$t7
/*    36d0c:	8f0e0060 */ 	lw	$t6,0x60($t8)
/*    36d10:	00094880 */ 	sll	$t1,$t1,0x2
/*    36d14:	012f4821 */ 	addu	$t1,$t1,$t7
/*    36d18:	00094880 */ 	sll	$t1,$t1,0x2
/*    36d1c:	01c9c821 */ 	addu	$t9,$t6,$t1
/*    36d20:	a3280024 */ 	sb	$t0,0x24($t9)
/*    36d24:	100000a1 */ 	beqz	$zero,.L00036fac
/*    36d28:	00000000 */ 	sll	$zero,$zero,0x0
/*    36d2c:	93ad00c3 */ 	lbu	$t5,0xc3($sp)
/*    36d30:	8faa00d0 */ 	lw	$t2,0xd0($sp)
/*    36d34:	93ab00bf */ 	lbu	$t3,0xbf($sp)
/*    36d38:	000dc080 */ 	sll	$t8,$t5,0x2
/*    36d3c:	030dc023 */ 	subu	$t8,$t8,$t5
/*    36d40:	8d4c0060 */ 	lw	$t4,0x60($t2)
/*    36d44:	0018c080 */ 	sll	$t8,$t8,0x2
/*    36d48:	030dc021 */ 	addu	$t8,$t8,$t5
/*    36d4c:	0018c080 */ 	sll	$t8,$t8,0x2
/*    36d50:	01987821 */ 	addu	$t7,$t4,$t8
/*    36d54:	a1eb0029 */ 	sb	$t3,0x29($t7)
/*    36d58:	93b900c3 */ 	lbu	$t9,0xc3($sp)
/*    36d5c:	8fa900d0 */ 	lw	$t1,0xd0($sp)
/*    36d60:	240e0001 */ 	addiu	$t6,$zero,0x1
/*    36d64:	00195080 */ 	sll	$t2,$t9,0x2
/*    36d68:	01595023 */ 	subu	$t2,$t2,$t9
/*    36d6c:	8d280060 */ 	lw	$t0,0x60($t1)
/*    36d70:	000a5080 */ 	sll	$t2,$t2,0x2
/*    36d74:	01595021 */ 	addu	$t2,$t2,$t9
/*    36d78:	000a5080 */ 	sll	$t2,$t2,0x2
/*    36d7c:	010a6821 */ 	addu	$t5,$t0,$t2
/*    36d80:	a1ae0024 */ 	sb	$t6,0x24($t5)
/*    36d84:	10000089 */ 	beqz	$zero,.L00036fac
/*    36d88:	00000000 */ 	sll	$zero,$zero,0x0
/*    36d8c:	93af00c3 */ 	lbu	$t7,0xc3($sp)
/*    36d90:	8fb800d0 */ 	lw	$t8,0xd0($sp)
/*    36d94:	93ac00bf */ 	lbu	$t4,0xbf($sp)
/*    36d98:	000f4880 */ 	sll	$t1,$t7,0x2
/*    36d9c:	012f4823 */ 	subu	$t1,$t1,$t7
/*    36da0:	8f0b0060 */ 	lw	$t3,0x60($t8)
/*    36da4:	00094880 */ 	sll	$t1,$t1,0x2
/*    36da8:	012f4821 */ 	addu	$t1,$t1,$t7
/*    36dac:	00094880 */ 	sll	$t1,$t1,0x2
/*    36db0:	0169c821 */ 	addu	$t9,$t3,$t1
/*    36db4:	a32c002a */ 	sb	$t4,0x2a($t9)
/*    36db8:	93ad00c3 */ 	lbu	$t5,0xc3($sp)
/*    36dbc:	8faa00d0 */ 	lw	$t2,0xd0($sp)
/*    36dc0:	24080001 */ 	addiu	$t0,$zero,0x1
/*    36dc4:	000dc080 */ 	sll	$t8,$t5,0x2
/*    36dc8:	030dc023 */ 	subu	$t8,$t8,$t5
/*    36dcc:	8d4e0060 */ 	lw	$t6,0x60($t2)
/*    36dd0:	0018c080 */ 	sll	$t8,$t8,0x2
/*    36dd4:	030dc021 */ 	addu	$t8,$t8,$t5
/*    36dd8:	0018c080 */ 	sll	$t8,$t8,0x2
/*    36ddc:	01d87821 */ 	addu	$t7,$t6,$t8
/*    36de0:	a1e80024 */ 	sb	$t0,0x24($t7)
/*    36de4:	10000071 */ 	beqz	$zero,.L00036fac
/*    36de8:	00000000 */ 	sll	$zero,$zero,0x0
/*    36dec:	93b900c3 */ 	lbu	$t9,0xc3($sp)
/*    36df0:	8fa900d0 */ 	lw	$t1,0xd0($sp)
/*    36df4:	93ab00bf */ 	lbu	$t3,0xbf($sp)
/*    36df8:	00195080 */ 	sll	$t2,$t9,0x2
/*    36dfc:	01595023 */ 	subu	$t2,$t2,$t9
/*    36e00:	8d2c0060 */ 	lw	$t4,0x60($t1)
/*    36e04:	000a5080 */ 	sll	$t2,$t2,0x2
/*    36e08:	01595021 */ 	addu	$t2,$t2,$t9
/*    36e0c:	000a5080 */ 	sll	$t2,$t2,0x2
/*    36e10:	018a6821 */ 	addu	$t5,$t4,$t2
/*    36e14:	a1ab002b */ 	sb	$t3,0x2b($t5)
/*    36e18:	93af00c3 */ 	lbu	$t7,0xc3($sp)
/*    36e1c:	8fb800d0 */ 	lw	$t8,0xd0($sp)
/*    36e20:	240e0001 */ 	addiu	$t6,$zero,0x1
/*    36e24:	000f4880 */ 	sll	$t1,$t7,0x2
/*    36e28:	012f4823 */ 	subu	$t1,$t1,$t7
/*    36e2c:	8f080060 */ 	lw	$t0,0x60($t8)
/*    36e30:	00094880 */ 	sll	$t1,$t1,0x2
/*    36e34:	012f4821 */ 	addu	$t1,$t1,$t7
/*    36e38:	00094880 */ 	sll	$t1,$t1,0x2
/*    36e3c:	0109c821 */ 	addu	$t9,$t0,$t1
/*    36e40:	a32e0024 */ 	sb	$t6,0x24($t9)
/*    36e44:	10000059 */ 	beqz	$zero,.L00036fac
/*    36e48:	00000000 */ 	sll	$zero,$zero,0x0
/*    36e4c:	93ac00bf */ 	lbu	$t4,0xbf($sp)
/*    36e50:	000c5040 */ 	sll	$t2,$t4,0x1
/*    36e54:	a3aa00bf */ 	sb	$t2,0xbf($sp)
/*    36e58:	8fab00d0 */ 	lw	$t3,0xd0($sp)
/*    36e5c:	8d6d0064 */ 	lw	$t5,0x64($t3)
/*    36e60:	11a00041 */ 	beqz	$t5,.L00036f68
/*    36e64:	afad00c8 */ 	sw	$t5,0xc8($sp)
.L00036e68:
/*    36e68:	8fb800c8 */ 	lw	$t8,0xc8($sp)
/*    36e6c:	93a800c3 */ 	lbu	$t0,0xc3($sp)
/*    36e70:	930f0031 */ 	lbu	$t7,0x31($t8)
/*    36e74:	15e80038 */ 	bne	$t7,$t0,.L00036f58
/*    36e78:	00000000 */ 	sll	$zero,$zero,0x0
/*    36e7c:	8f09003c */ 	lw	$t1,0x3c($t8)
/*    36e80:	11200035 */ 	beqz	$t1,.L00036f58
/*    36e84:	00000000 */ 	sll	$zero,$zero,0x0
/*    36e88:	8fae00c8 */ 	lw	$t6,0xc8($sp)
/*    36e8c:	8dd9003c */ 	lw	$t9,0x3c($t6)
/*    36e90:	afb9005c */ 	sw	$t9,0x5c($sp)
/*    36e94:	8fac005c */ 	lw	$t4,0x5c($sp)
/*    36e98:	2401ff7f */ 	addiu	$at,$zero,-129
/*    36e9c:	918a0004 */ 	lbu	$t2,0x4($t4)
/*    36ea0:	01415824 */ 	and	$t3,$t2,$at
/*    36ea4:	256dfffe */ 	addiu	$t5,$t3,-2
/*    36ea8:	2da1000c */ 	sltiu	$at,$t5,0xc
/*    36eac:	10200024 */ 	beqz	$at,.L00036f40
/*    36eb0:	00000000 */ 	sll	$zero,$zero,0x0
/*    36eb4:	000d6880 */ 	sll	$t5,$t5,0x2
/*    36eb8:	3c017005 */ 	lui	$at,%hi(var70054a48)
/*    36ebc:	002d0821 */ 	addu	$at,$at,$t5
/*    36ec0:	8c2d4a48 */ 	lw	$t5,%lo(var70054a48)($at)
/*    36ec4:	01a00008 */ 	jr	$t5
/*    36ec8:	00000000 */ 	sll	$zero,$zero,0x0
/*    36ecc:	0c00bf18 */ 	jal	func0002fc60
/*    36ed0:	93a400bf */ 	lbu	$a0,0xbf($sp)
/*    36ed4:	8faf005c */ 	lw	$t7,0x5c($sp)
/*    36ed8:	46000407 */ 	neg.s	$f16,$f0
/*    36edc:	e5f00010 */ 	swc1	$f16,0x10($t7)
/*    36ee0:	0c00bf18 */ 	jal	func0002fc60
/*    36ee4:	93a400bf */ 	lbu	$a0,0xbf($sp)
/*    36ee8:	8fa8005c */ 	lw	$t0,0x5c($sp)
/*    36eec:	e500000c */ 	swc1	$f0,0xc($t0)
/*    36ef0:	10000019 */ 	beqz	$zero,.L00036f58
/*    36ef4:	00000000 */ 	sll	$zero,$zero,0x0
/*    36ef8:	0c00bf18 */ 	jal	func0002fc60
/*    36efc:	93a400bf */ 	lbu	$a0,0xbf($sp)
/*    36f00:	3c014000 */ 	lui	$at,0x4000
/*    36f04:	44819000 */ 	mtc1	$at,$f18
/*    36f08:	8fb8005c */ 	lw	$t8,0x5c($sp)
/*    36f0c:	46120103 */ 	div.s	$f4,$f0,$f18
/*    36f10:	e704000c */ 	swc1	$f4,0xc($t8)
/*    36f14:	10000010 */ 	beqz	$zero,.L00036f58
/*    36f18:	00000000 */ 	sll	$zero,$zero,0x0
/*    36f1c:	0c00bf18 */ 	jal	func0002fc60
/*    36f20:	93a400bf */ 	lbu	$a0,0xbf($sp)
/*    36f24:	3c014000 */ 	lui	$at,0x4000
/*    36f28:	44813000 */ 	mtc1	$at,$f6
/*    36f2c:	8fa9005c */ 	lw	$t1,0x5c($sp)
/*    36f30:	46060202 */ 	mul.s	$f8,$f0,$f6
/*    36f34:	e528000c */ 	swc1	$f8,0xc($t1)
/*    36f38:	10000007 */ 	beqz	$zero,.L00036f58
/*    36f3c:	00000000 */ 	sll	$zero,$zero,0x0
.L00036f40:
/*    36f40:	0c00bf18 */ 	jal	func0002fc60
/*    36f44:	93a400bf */ 	lbu	$a0,0xbf($sp)
/*    36f48:	8fae005c */ 	lw	$t6,0x5c($sp)
/*    36f4c:	e5c0000c */ 	swc1	$f0,0xc($t6)
/*    36f50:	10000001 */ 	beqz	$zero,.L00036f58
/*    36f54:	00000000 */ 	sll	$zero,$zero,0x0
.L00036f58:
/*    36f58:	8fb900c8 */ 	lw	$t9,0xc8($sp)
/*    36f5c:	8f2c0000 */ 	lw	$t4,0x0($t9)
/*    36f60:	1580ffc1 */ 	bnez	$t4,.L00036e68
/*    36f64:	afac00c8 */ 	sw	$t4,0xc8($sp)
.L00036f68:
/*    36f68:	10000010 */ 	beqz	$zero,.L00036fac
/*    36f6c:	00000000 */ 	sll	$zero,$zero,0x0
/*    36f70:	93af00c3 */ 	lbu	$t7,0xc3($sp)
/*    36f74:	8fab00d0 */ 	lw	$t3,0xd0($sp)
/*    36f78:	93aa00bf */ 	lbu	$t2,0xbf($sp)
/*    36f7c:	000f4080 */ 	sll	$t0,$t7,0x2
/*    36f80:	010f4023 */ 	subu	$t0,$t0,$t7
/*    36f84:	8d6d0060 */ 	lw	$t5,0x60($t3)
/*    36f88:	00084080 */ 	sll	$t0,$t0,0x2
/*    36f8c:	010f4021 */ 	addu	$t0,$t0,$t7
/*    36f90:	00084080 */ 	sll	$t0,$t0,0x2
/*    36f94:	01a8c021 */ 	addu	$t8,$t5,$t0
/*    36f98:	a30a0031 */ 	sb	$t2,0x31($t8)
/*    36f9c:	10000003 */ 	beqz	$zero,.L00036fac
/*    36fa0:	00000000 */ 	sll	$zero,$zero,0x0
.L00036fa4:
/*    36fa4:	10000001 */ 	beqz	$zero,.L00036fac
/*    36fa8:	00000000 */ 	sll	$zero,$zero,0x0
.L00036fac:
/*    36fac:	10000094 */ 	beqz	$zero,.L00037200
/*    36fb0:	00000000 */ 	sll	$zero,$zero,0x0
/*    36fb4:	93b900c3 */ 	lbu	$t9,0xc3($sp)
/*    36fb8:	8fa900d0 */ 	lw	$t1,0xd0($sp)
/*    36fbc:	93a800c2 */ 	lbu	$t0,0xc2($sp)
/*    36fc0:	00196080 */ 	sll	$t4,$t9,0x2
/*    36fc4:	01996023 */ 	subu	$t4,$t4,$t9
/*    36fc8:	8d2e0060 */ 	lw	$t6,0x60($t1)
/*    36fcc:	000c6080 */ 	sll	$t4,$t4,0x2
/*    36fd0:	01996021 */ 	addu	$t4,$t4,$t9
/*    36fd4:	000c6080 */ 	sll	$t4,$t4,0x2
/*    36fd8:	01cc5821 */ 	addu	$t3,$t6,$t4
/*    36fdc:	916f0032 */ 	lbu	$t7,0x32($t3)
/*    36fe0:	000f69c0 */ 	sll	$t5,$t7,0x7
/*    36fe4:	01a85021 */ 	addu	$t2,$t5,$t0
/*    36fe8:	afaa0090 */ 	sw	$t2,0x90($sp)
/*    36fec:	8fa900d0 */ 	lw	$t1,0xd0($sp)
/*    36ff0:	8fb80090 */ 	lw	$t8,0x90($sp)
/*    36ff4:	8d390020 */ 	lw	$t9,0x20($t1)
/*    36ff8:	872e0000 */ 	lh	$t6,0x0($t9)
/*    36ffc:	030e082a */ 	slt	$at,$t8,$t6
/*    37000:	1020000e */ 	beqz	$at,.L0003703c
/*    37004:	00000000 */ 	sll	$zero,$zero,0x0
/*    37008:	8fac00d0 */ 	lw	$t4,0xd0($sp)
/*    3700c:	8faf0090 */ 	lw	$t7,0x90($sp)
/*    37010:	8d8b0020 */ 	lw	$t3,0x20($t4)
/*    37014:	000f6880 */ 	sll	$t5,$t7,0x2
/*    37018:	016d4021 */ 	addu	$t0,$t3,$t5
/*    3701c:	8d0a000c */ 	lw	$t2,0xc($t0)
/*    37020:	afaa0058 */ 	sw	$t2,0x58($sp)
/*    37024:	8fa400d0 */ 	lw	$a0,0xd0($sp)
/*    37028:	8fa50058 */ 	lw	$a1,0x58($sp)
/*    3702c:	0c00f7d9 */ 	jal	func0003df64
/*    37030:	93a600c3 */ 	lbu	$a2,0xc3($sp)
/*    37034:	10000001 */ 	beqz	$zero,.L0003703c
/*    37038:	00000000 */ 	sll	$zero,$zero,0x0
.L0003703c:
/*    3703c:	10000070 */ 	beqz	$zero,.L00037200
/*    37040:	00000000 */ 	sll	$zero,$zero,0x0
/*    37044:	93a900bf */ 	lbu	$t1,0xbf($sp)
/*    37048:	93b800c0 */ 	lbu	$t8,0xc0($sp)
/*    3704c:	0009c9c0 */ 	sll	$t9,$t1,0x7
/*    37050:	03387021 */ 	addu	$t6,$t9,$t8
/*    37054:	25cce000 */ 	addiu	$t4,$t6,-8192
/*    37058:	afac0054 */ 	sw	$t4,0x54($sp)
/*    3705c:	93ad00c3 */ 	lbu	$t5,0xc3($sp)
/*    37060:	8faf00d0 */ 	lw	$t7,0xd0($sp)
/*    37064:	8fb90054 */ 	lw	$t9,0x54($sp)
/*    37068:	000d4080 */ 	sll	$t0,$t5,0x2
/*    3706c:	010d4023 */ 	subu	$t0,$t0,$t5
/*    37070:	8deb0060 */ 	lw	$t3,0x60($t7)
/*    37074:	00084080 */ 	sll	$t0,$t0,0x2
/*    37078:	010d4021 */ 	addu	$t0,$t0,$t5
/*    3707c:	00084080 */ 	sll	$t0,$t0,0x2
/*    37080:	01685021 */ 	addu	$t2,$t3,$t0
/*    37084:	85490004 */ 	lh	$t1,0x4($t2)
/*    37088:	01390019 */ 	multu	$t1,$t9
/*    3708c:	0000c012 */ 	mflo	$t8
/*    37090:	07010003 */ 	bgez	$t8,.L000370a0
/*    37094:	00187343 */ 	sra	$t6,$t8,0xd
/*    37098:	27011fff */ 	addiu	$at,$t8,0x1fff
/*    3709c:	00017343 */ 	sra	$t6,$at,0xd
.L000370a0:
/*    370a0:	afae004c */ 	sw	$t6,0x4c($sp)
/*    370a4:	0c00e7f8 */ 	jal	func00039fe0
/*    370a8:	8fa4004c */ 	lw	$a0,0x4c($sp)
/*    370ac:	e7a00050 */ 	swc1	$f0,0x50($sp)
/*    370b0:	93ad00c3 */ 	lbu	$t5,0xc3($sp)
/*    370b4:	8fac00d0 */ 	lw	$t4,0xd0($sp)
/*    370b8:	c7aa0050 */ 	lwc1	$f10,0x50($sp)
/*    370bc:	000d5880 */ 	sll	$t3,$t5,0x2
/*    370c0:	016d5823 */ 	subu	$t3,$t3,$t5
/*    370c4:	8d8f0060 */ 	lw	$t7,0x60($t4)
/*    370c8:	000b5880 */ 	sll	$t3,$t3,0x2
/*    370cc:	016d5821 */ 	addu	$t3,$t3,$t5
/*    370d0:	000b5880 */ 	sll	$t3,$t3,0x2
/*    370d4:	01eb4021 */ 	addu	$t0,$t7,$t3
/*    370d8:	e50a0014 */ 	swc1	$f10,0x14($t0)
/*    370dc:	8faa00d0 */ 	lw	$t2,0xd0($sp)
/*    370e0:	8d490064 */ 	lw	$t1,0x64($t2)
/*    370e4:	11200042 */ 	beqz	$t1,.L000371f0
/*    370e8:	afa900c8 */ 	sw	$t1,0xc8($sp)
.L000370ec:
/*    370ec:	8fb900c8 */ 	lw	$t9,0xc8($sp)
/*    370f0:	93ae00c3 */ 	lbu	$t6,0xc3($sp)
/*    370f4:	93380031 */ 	lbu	$t8,0x31($t9)
/*    370f8:	170e0039 */ 	bne	$t8,$t6,.L000371e0
/*    370fc:	00000000 */ 	sll	$zero,$zero,0x0
/*    37100:	8fac00c8 */ 	lw	$t4,0xc8($sp)
/*    37104:	c7b20050 */ 	lwc1	$f18,0x50($sp)
/*    37108:	c5900028 */ 	lwc1	$f16,0x28($t4)
/*    3710c:	c586002c */ 	lwc1	$f6,0x2c($t4)
/*    37110:	25840004 */ 	addiu	$a0,$t4,0x4
/*    37114:	46128102 */ 	mul.s	$f4,$f16,$f18
/*    37118:	00000000 */ 	sll	$zero,$zero,0x0
/*    3711c:	46062202 */ 	mul.s	$f8,$f4,$f6
/*    37120:	44054000 */ 	mfc1	$a1,$f8
/*    37124:	0c00f3e8 */ 	jal	func0003cfa0
/*    37128:	00000000 */ 	sll	$zero,$zero,0x0
/*    3712c:	93ab00c3 */ 	lbu	$t3,0xc3($sp)
/*    37130:	8fad00d0 */ 	lw	$t5,0xd0($sp)
/*    37134:	000b4080 */ 	sll	$t0,$t3,0x2
/*    37138:	010b4023 */ 	subu	$t0,$t0,$t3
/*    3713c:	8daf0060 */ 	lw	$t7,0x60($t5)
/*    37140:	00084080 */ 	sll	$t0,$t0,0x2
/*    37144:	010b4021 */ 	addu	$t0,$t0,$t3
/*    37148:	00084080 */ 	sll	$t0,$t0,0x2
/*    3714c:	01e85021 */ 	addu	$t2,$t7,$t0
/*    37150:	91490011 */ 	lbu	$t1,0x11($t2)
/*    37154:	11200022 */ 	beqz	$t1,.L000371e0
/*    37158:	00000000 */ 	sll	$zero,$zero,0x0
/*    3715c:	8faf00c8 */ 	lw	$t7,0xc8($sp)
/*    37160:	93ae00c3 */ 	lbu	$t6,0xc3($sp)
/*    37164:	8fb900d0 */ 	lw	$t9,0xd0($sp)
/*    37168:	8dea0020 */ 	lw	$t2,0x20($t7)
/*    3716c:	000e6080 */ 	sll	$t4,$t6,0x2
/*    37170:	018e6023 */ 	subu	$t4,$t4,$t6
/*    37174:	8f380060 */ 	lw	$t8,0x60($t9)
/*    37178:	8d490004 */ 	lw	$t1,0x4($t2)
/*    3717c:	000c6080 */ 	sll	$t4,$t4,0x2
/*    37180:	018e6021 */ 	addu	$t4,$t4,$t6
/*    37184:	000c6080 */ 	sll	$t4,$t4,0x2
/*    37188:	91e80032 */ 	lbu	$t0,0x32($t7)
/*    3718c:	91390004 */ 	lbu	$t9,0x4($t1)
/*    37190:	030c6821 */ 	addu	$t5,$t8,$t4
/*    37194:	91ab0012 */ 	lbu	$t3,0x12($t5)
/*    37198:	01197023 */ 	subu	$t6,$t0,$t9
/*    3719c:	016e2021 */ 	addu	$a0,$t3,$t6
/*    371a0:	0c00ee75 */ 	jal	func0003b9d4
/*    371a4:	2484ffc0 */ 	addiu	$a0,$a0,-64
/*    371a8:	3c0143dc */ 	lui	$at,0x43dc
/*    371ac:	44815000 */ 	mtc1	$at,$f10
/*    371b0:	46000506 */ 	mov.s	$f20,$f0
/*    371b4:	c7b20050 */ 	lwc1	$f18,0x50($sp)
/*    371b8:	460aa402 */ 	mul.s	$f16,$f20,$f10
/*    371bc:	8fb800c8 */ 	lw	$t8,0xc8($sp)
/*    371c0:	c706002c */ 	lwc1	$f6,0x2c($t8)
/*    371c4:	27040004 */ 	addiu	$a0,$t8,0x4
/*    371c8:	46128102 */ 	mul.s	$f4,$f16,$f18
/*    371cc:	00000000 */ 	sll	$zero,$zero,0x0
/*    371d0:	46062202 */ 	mul.s	$f8,$f4,$f6
/*    371d4:	44054000 */ 	mfc1	$a1,$f8
/*    371d8:	0c00f8f8 */ 	jal	func0003e3e0
/*    371dc:	00000000 */ 	sll	$zero,$zero,0x0
.L000371e0:
/*    371e0:	8fac00c8 */ 	lw	$t4,0xc8($sp)
/*    371e4:	8d8d0000 */ 	lw	$t5,0x0($t4)
/*    371e8:	15a0ffc0 */ 	bnez	$t5,.L000370ec
/*    371ec:	afad00c8 */ 	sw	$t5,0xc8($sp)
.L000371f0:
/*    371f0:	10000003 */ 	beqz	$zero,.L00037200
/*    371f4:	00000000 */ 	sll	$zero,$zero,0x0
.L000371f8:
/*    371f8:	10000001 */ 	beqz	$zero,.L00037200
/*    371fc:	00000000 */ 	sll	$zero,$zero,0x0
.L00037200:
/*    37200:	10000001 */ 	beqz	$zero,.L00037208
/*    37204:	00000000 */ 	sll	$zero,$zero,0x0
.L00037208:
/*    37208:	8fbf003c */ 	lw	$ra,0x3c($sp)
/*    3720c:	d7b40028 */ 	ldc1	$f20,0x28($sp)
/*    37210:	8fb00034 */ 	lw	$s0,0x34($sp)
/*    37214:	8fb10038 */ 	lw	$s1,0x38($sp)
/*    37218:	03e00008 */ 	jr	$ra
/*    3721c:	27bd00d0 */ 	addiu	$sp,$sp,0xd0
);

GLOBAL_ASM(
glabel func00037220
/*    37220:	27bdffc0 */ 	addiu	$sp,$sp,-64
/*    37224:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    37228:	afa40040 */ 	sw	$a0,0x40($sp)
/*    3722c:	afa50044 */ 	sw	$a1,0x44($sp)
/*    37230:	8fae0044 */ 	lw	$t6,0x44($sp)
/*    37234:	25cf0004 */ 	addiu	$t7,$t6,0x4
/*    37238:	afaf003c */ 	sw	$t7,0x3c($sp)
/*    3723c:	afa00028 */ 	sw	$zero,0x28($sp)
/*    37240:	afa0001c */ 	sw	$zero,0x1c($sp)
/*    37244:	8fb80044 */ 	lw	$t8,0x44($sp)
/*    37248:	240100ff */ 	addiu	$at,$zero,0xff
/*    3724c:	93190008 */ 	lbu	$t9,0x8($t8)
/*    37250:	1721007d */ 	bne	$t9,$at,.L00037448
/*    37254:	00000000 */ 	sll	$zero,$zero,0x0
/*    37258:	8fa80044 */ 	lw	$t0,0x44($sp)
/*    3725c:	24010051 */ 	addiu	$at,$zero,0x51
/*    37260:	91090009 */ 	lbu	$t1,0x9($t0)
/*    37264:	15210078 */ 	bne	$t1,$at,.L00037448
/*    37268:	00000000 */ 	sll	$zero,$zero,0x0
/*    3726c:	8faa0040 */ 	lw	$t2,0x40($sp)
/*    37270:	8d4b0024 */ 	lw	$t3,0x24($t2)
/*    37274:	afab0034 */ 	sw	$t3,0x34($sp)
/*    37278:	8fac003c */ 	lw	$t4,0x3c($sp)
/*    3727c:	918d0007 */ 	lbu	$t5,0x7($t4)
/*    37280:	918f0008 */ 	lbu	$t7,0x8($t4)
/*    37284:	91880009 */ 	lbu	$t0,0x9($t4)
/*    37288:	000d7400 */ 	sll	$t6,$t5,0x10
/*    3728c:	000fc200 */ 	sll	$t8,$t7,0x8
/*    37290:	01d8c825 */ 	or	$t9,$t6,$t8
/*    37294:	03284825 */ 	or	$t1,$t9,$t0
/*    37298:	afa90038 */ 	sw	$t1,0x38($sp)
/*    3729c:	8faa0038 */ 	lw	$t2,0x38($sp)
/*    372a0:	8fa40040 */ 	lw	$a0,0x40($sp)
/*    372a4:	448a2000 */ 	mtc1	$t2,$f4
/*    372a8:	00000000 */ 	sll	$zero,$zero,0x0
/*    372ac:	46802120 */ 	cvt.s.w	$f4,$f4
/*    372b0:	44052000 */ 	mfc1	$a1,$f4
/*    372b4:	0c00dd55 */ 	jal	func00037554
/*    372b8:	00000000 */ 	sll	$zero,$zero,0x0
/*    372bc:	8fab0040 */ 	lw	$t3,0x40($sp)
/*    372c0:	8d6d0050 */ 	lw	$t5,0x50($t3)
/*    372c4:	afad0024 */ 	sw	$t5,0x24($sp)
/*    372c8:	8faf0024 */ 	lw	$t7,0x24($sp)
/*    372cc:	11e00036 */ 	beqz	$t7,.L000373a8
/*    372d0:	00000000 */ 	sll	$zero,$zero,0x0
.L000372d4:
/*    372d4:	8fb80024 */ 	lw	$t8,0x24($sp)
/*    372d8:	8fae0028 */ 	lw	$t6,0x28($sp)
/*    372dc:	8f0c0008 */ 	lw	$t4,0x8($t8)
/*    372e0:	01ccc821 */ 	addu	$t9,$t6,$t4
/*    372e4:	afb90028 */ 	sw	$t9,0x28($sp)
/*    372e8:	8fa80024 */ 	lw	$t0,0x24($sp)
/*    372ec:	8d090000 */ 	lw	$t1,0x0($t0)
/*    372f0:	afa90020 */ 	sw	$t1,0x20($sp)
/*    372f4:	8faa0024 */ 	lw	$t2,0x24($sp)
/*    372f8:	24010015 */ 	addiu	$at,$zero,0x15
/*    372fc:	854b000c */ 	lh	$t3,0xc($t2)
/*    37300:	15610024 */ 	bne	$t3,$at,.L00037394
/*    37304:	00000000 */ 	sll	$zero,$zero,0x0
/*    37308:	0c00c5e9 */ 	jal	func000317a4
/*    3730c:	8fa40024 */ 	lw	$a0,0x24($sp)
/*    37310:	8fad001c */ 	lw	$t5,0x1c($sp)
/*    37314:	11a00006 */ 	beqz	$t5,.L00037330
/*    37318:	00000000 */ 	sll	$zero,$zero,0x0
/*    3731c:	8fa40024 */ 	lw	$a0,0x24($sp)
/*    37320:	0c00c5dc */ 	jal	func00031770
/*    37324:	8fa5001c */ 	lw	$a1,0x1c($sp)
/*    37328:	10000007 */ 	beqz	$zero,.L00037348
/*    3732c:	00000000 */ 	sll	$zero,$zero,0x0
.L00037330:
/*    37330:	8faf0024 */ 	lw	$t7,0x24($sp)
/*    37334:	ade00000 */ 	sw	$zero,0x0($t7)
/*    37338:	8fb80024 */ 	lw	$t8,0x24($sp)
/*    3733c:	af000004 */ 	sw	$zero,0x4($t8)
/*    37340:	8fae0024 */ 	lw	$t6,0x24($sp)
/*    37344:	afae001c */ 	sw	$t6,0x1c($sp)
.L00037348:
/*    37348:	8fac0028 */ 	lw	$t4,0x28($sp)
/*    3734c:	afac002c */ 	sw	$t4,0x2c($sp)
/*    37350:	8fb90020 */ 	lw	$t9,0x20($sp)
/*    37354:	1320000c */ 	beqz	$t9,.L00037388
/*    37358:	00000000 */ 	sll	$zero,$zero,0x0
/*    3735c:	8fa90024 */ 	lw	$t1,0x24($sp)
/*    37360:	8fa80028 */ 	lw	$t0,0x28($sp)
/*    37364:	8d2a0008 */ 	lw	$t2,0x8($t1)
/*    37368:	010a5823 */ 	subu	$t3,$t0,$t2
/*    3736c:	afab0028 */ 	sw	$t3,0x28($sp)
/*    37370:	8fad0020 */ 	lw	$t5,0x20($sp)
/*    37374:	8fb80024 */ 	lw	$t8,0x24($sp)
/*    37378:	8daf0008 */ 	lw	$t7,0x8($t5)
/*    3737c:	8f0e0008 */ 	lw	$t6,0x8($t8)
/*    37380:	01ee6021 */ 	addu	$t4,$t7,$t6
/*    37384:	adac0008 */ 	sw	$t4,0x8($t5)
.L00037388:
/*    37388:	8fb9002c */ 	lw	$t9,0x2c($sp)
/*    3738c:	8fa90024 */ 	lw	$t1,0x24($sp)
/*    37390:	ad390008 */ 	sw	$t9,0x8($t1)
.L00037394:
/*    37394:	8fa80020 */ 	lw	$t0,0x20($sp)
/*    37398:	afa80024 */ 	sw	$t0,0x24($sp)
/*    3739c:	8faa0024 */ 	lw	$t2,0x24($sp)
/*    373a0:	1540ffcc */ 	bnez	$t2,.L000372d4
/*    373a4:	00000000 */ 	sll	$zero,$zero,0x0
.L000373a8:
/*    373a8:	8fab001c */ 	lw	$t3,0x1c($sp)
/*    373ac:	afab0024 */ 	sw	$t3,0x24($sp)
/*    373b0:	8fb80024 */ 	lw	$t8,0x24($sp)
/*    373b4:	13000024 */ 	beqz	$t8,.L00037448
/*    373b8:	00000000 */ 	sll	$zero,$zero,0x0
.L000373bc:
/*    373bc:	8faf0024 */ 	lw	$t7,0x24($sp)
/*    373c0:	8dee0000 */ 	lw	$t6,0x0($t7)
/*    373c4:	afae0020 */ 	sw	$t6,0x20($sp)
/*    373c8:	8fac0024 */ 	lw	$t4,0x24($sp)
/*    373cc:	8fb90034 */ 	lw	$t9,0x34($sp)
/*    373d0:	8d8d0008 */ 	lw	$t5,0x8($t4)
/*    373d4:	01b9001a */ 	div	$zero,$t5,$t9
/*    373d8:	00004812 */ 	mflo	$t1
/*    373dc:	afa90030 */ 	sw	$t1,0x30($sp)
/*    373e0:	17200002 */ 	bnez	$t9,.L000373ec
/*    373e4:	00000000 */ 	sll	$zero,$zero,0x0
/*    373e8:	0007000d */ 	break	0x7
.L000373ec:
/*    373ec:	2401ffff */ 	addiu	$at,$zero,-1
/*    373f0:	17210004 */ 	bne	$t9,$at,.L00037404
/*    373f4:	3c018000 */ 	lui	$at,0x8000
/*    373f8:	15a10002 */ 	bne	$t5,$at,.L00037404
/*    373fc:	00000000 */ 	sll	$zero,$zero,0x0
/*    37400:	0006000d */ 	break	0x6
.L00037404:
/*    37404:	8fa80040 */ 	lw	$t0,0x40($sp)
/*    37408:	8fab0030 */ 	lw	$t3,0x30($sp)
/*    3740c:	8faf0024 */ 	lw	$t7,0x24($sp)
/*    37410:	8d0a0024 */ 	lw	$t2,0x24($t0)
/*    37414:	014b0019 */ 	multu	$t2,$t3
/*    37418:	0000c012 */ 	mflo	$t8
/*    3741c:	adf80008 */ 	sw	$t8,0x8($t7)
/*    37420:	00000000 */ 	sll	$zero,$zero,0x0
/*    37424:	8fa40040 */ 	lw	$a0,0x40($sp)
/*    37428:	8fa50024 */ 	lw	$a1,0x24($sp)
/*    3742c:	0c00dd18 */ 	jal	func00037460
/*    37430:	24840048 */ 	addiu	$a0,$a0,0x48
/*    37434:	8fae0020 */ 	lw	$t6,0x20($sp)
/*    37438:	afae0024 */ 	sw	$t6,0x24($sp)
/*    3743c:	8fac0024 */ 	lw	$t4,0x24($sp)
/*    37440:	1580ffde */ 	bnez	$t4,.L000373bc
/*    37444:	00000000 */ 	sll	$zero,$zero,0x0
.L00037448:
/*    37448:	10000001 */ 	beqz	$zero,.L00037450
/*    3744c:	00000000 */ 	sll	$zero,$zero,0x0
.L00037450:
/*    37450:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    37454:	27bd0040 */ 	addiu	$sp,$sp,0x40
/*    37458:	03e00008 */ 	jr	$ra
/*    3745c:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func00037460
/*    37460:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*    37464:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    37468:	afa40028 */ 	sw	$a0,0x28($sp)
/*    3746c:	afa5002c */ 	sw	$a1,0x2c($sp)
/*    37470:	0c012194 */ 	jal	func00048650
/*    37474:	24040001 */ 	addiu	$a0,$zero,0x1
/*    37478:	afa20024 */ 	sw	$v0,0x24($sp)
/*    3747c:	8fae0028 */ 	lw	$t6,0x28($sp)
/*    37480:	25cf0008 */ 	addiu	$t7,$t6,0x8
/*    37484:	11e0002b */ 	beqz	$t7,.L00037534
/*    37488:	afaf0020 */ 	sw	$t7,0x20($sp)
.L0003748c:
/*    3748c:	8fb80020 */ 	lw	$t8,0x20($sp)
/*    37490:	8f190000 */ 	lw	$t9,0x0($t8)
/*    37494:	17200008 */ 	bnez	$t9,.L000374b8
/*    37498:	00000000 */ 	sll	$zero,$zero,0x0
/*    3749c:	8fa4002c */ 	lw	$a0,0x2c($sp)
/*    374a0:	0c00c5dc */ 	jal	func00031770
/*    374a4:	8fa50020 */ 	lw	$a1,0x20($sp)
/*    374a8:	10000022 */ 	beqz	$zero,.L00037534
/*    374ac:	00000000 */ 	sll	$zero,$zero,0x0
/*    374b0:	1000001c */ 	beqz	$zero,.L00037524
/*    374b4:	00000000 */ 	sll	$zero,$zero,0x0
.L000374b8:
/*    374b8:	8fa80020 */ 	lw	$t0,0x20($sp)
/*    374bc:	8d090000 */ 	lw	$t1,0x0($t0)
/*    374c0:	afa9001c */ 	sw	$t1,0x1c($sp)
/*    374c4:	8faa002c */ 	lw	$t2,0x2c($sp)
/*    374c8:	8fac001c */ 	lw	$t4,0x1c($sp)
/*    374cc:	8d4b0008 */ 	lw	$t3,0x8($t2)
/*    374d0:	8d8d0008 */ 	lw	$t5,0x8($t4)
/*    374d4:	016d082a */ 	slt	$at,$t3,$t5
/*    374d8:	1020000c */ 	beqz	$at,.L0003750c
/*    374dc:	00000000 */ 	sll	$zero,$zero,0x0
/*    374e0:	8fae001c */ 	lw	$t6,0x1c($sp)
/*    374e4:	8fb8002c */ 	lw	$t8,0x2c($sp)
/*    374e8:	8dcf0008 */ 	lw	$t7,0x8($t6)
/*    374ec:	8f190008 */ 	lw	$t9,0x8($t8)
/*    374f0:	01f94023 */ 	subu	$t0,$t7,$t9
/*    374f4:	adc80008 */ 	sw	$t0,0x8($t6)
/*    374f8:	8fa4002c */ 	lw	$a0,0x2c($sp)
/*    374fc:	0c00c5dc */ 	jal	func00031770
/*    37500:	8fa50020 */ 	lw	$a1,0x20($sp)
/*    37504:	1000000b */ 	beqz	$zero,.L00037534
/*    37508:	00000000 */ 	sll	$zero,$zero,0x0
.L0003750c:
/*    3750c:	8fa9002c */ 	lw	$t1,0x2c($sp)
/*    37510:	8fac001c */ 	lw	$t4,0x1c($sp)
/*    37514:	8d2a0008 */ 	lw	$t2,0x8($t1)
/*    37518:	8d8b0008 */ 	lw	$t3,0x8($t4)
/*    3751c:	014b6823 */ 	subu	$t5,$t2,$t3
/*    37520:	ad2d0008 */ 	sw	$t5,0x8($t1)
.L00037524:
/*    37524:	8fb80020 */ 	lw	$t8,0x20($sp)
/*    37528:	8f0f0000 */ 	lw	$t7,0x0($t8)
/*    3752c:	15e0ffd7 */ 	bnez	$t7,.L0003748c
/*    37530:	afaf0020 */ 	sw	$t7,0x20($sp)
.L00037534:
/*    37534:	0c012194 */ 	jal	func00048650
/*    37538:	8fa40024 */ 	lw	$a0,0x24($sp)
/*    3753c:	10000001 */ 	beqz	$zero,.L00037544
/*    37540:	00000000 */ 	sll	$zero,$zero,0x0
.L00037544:
/*    37544:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    37548:	27bd0028 */ 	addiu	$sp,$sp,0x28
/*    3754c:	03e00008 */ 	jr	$ra
/*    37550:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func00037554
/*    37554:	afa50004 */ 	sw	$a1,0x4($sp)
/*    37558:	8c8e0018 */ 	lw	$t6,0x18($a0)
/*    3755c:	11c00009 */ 	beqz	$t6,.L00037584
/*    37560:	00000000 */ 	sll	$zero,$zero,0x0
/*    37564:	8c8f0018 */ 	lw	$t7,0x18($a0)
/*    37568:	c7a40004 */ 	lwc1	$f4,0x4($sp)
/*    3756c:	c5e60008 */ 	lwc1	$f6,0x8($t7)
/*    37570:	46062202 */ 	mul.s	$f8,$f4,$f6
/*    37574:	4600428d */ 	trunc.w.s	$f10,$f8
/*    37578:	44195000 */ 	mfc1	$t9,$f10
/*    3757c:	10000003 */ 	beqz	$zero,.L0003758c
/*    37580:	ac990024 */ 	sw	$t9,0x24($a0)
.L00037584:
/*    37584:	240801e8 */ 	addiu	$t0,$zero,0x1e8
/*    37588:	ac880024 */ 	sw	$t0,0x24($a0)
.L0003758c:
/*    3758c:	10000001 */ 	beqz	$zero,.L00037594
/*    37590:	00000000 */ 	sll	$zero,$zero,0x0
.L00037594:
/*    37594:	03e00008 */ 	jr	$ra
/*    37598:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0003759c
/*    3759c:	27bdffd0 */ 	addiu	$sp,$sp,-48
/*    375a0:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    375a4:	afa40030 */ 	sw	$a0,0x30($sp)
/*    375a8:	8fae0030 */ 	lw	$t6,0x30($sp)
/*    375ac:	24010001 */ 	addiu	$at,$zero,0x1
/*    375b0:	8dcf002c */ 	lw	$t7,0x2c($t6)
/*    375b4:	15e10004 */ 	bne	$t7,$at,.L000375c8
/*    375b8:	00000000 */ 	sll	$zero,$zero,0x0
/*    375bc:	8dd80018 */ 	lw	$t8,0x18($t6)
/*    375c0:	17000003 */ 	bnez	$t8,.L000375d0
/*    375c4:	00000000 */ 	sll	$zero,$zero,0x0
.L000375c8:
/*    375c8:	10000016 */ 	beqz	$zero,.L00037624
/*    375cc:	00000000 */ 	sll	$zero,$zero,0x0
.L000375d0:
/*    375d0:	8fb90030 */ 	lw	$t9,0x30($sp)
/*    375d4:	27a5001c */ 	addiu	$a1,$sp,0x1c
/*    375d8:	0c00f9f8 */ 	jal	func0003e7e0
/*    375dc:	8f240018 */ 	lw	$a0,0x18($t9)
/*    375e0:	14400003 */ 	bnez	$v0,.L000375f0
/*    375e4:	00000000 */ 	sll	$zero,$zero,0x0
/*    375e8:	1000000e */ 	beqz	$zero,.L00037624
/*    375ec:	00000000 */ 	sll	$zero,$zero,0x0
.L000375f0:
/*    375f0:	a7a00020 */ 	sh	$zero,0x20($sp)
/*    375f4:	8fa80030 */ 	lw	$t0,0x30($sp)
/*    375f8:	8faa001c */ 	lw	$t2,0x1c($sp)
/*    375fc:	27a50020 */ 	addiu	$a1,$sp,0x20
/*    37600:	8d090024 */ 	lw	$t1,0x24($t0)
/*    37604:	00003825 */ 	or	$a3,$zero,$zero
/*    37608:	25040048 */ 	addiu	$a0,$t0,0x48
/*    3760c:	012a0019 */ 	multu	$t1,$t2
/*    37610:	00003012 */ 	mflo	$a2
/*    37614:	0c00f184 */ 	jal	func0003c610
/*    37618:	00000000 */ 	sll	$zero,$zero,0x0
/*    3761c:	10000001 */ 	beqz	$zero,.L00037624
/*    37620:	00000000 */ 	sll	$zero,$zero,0x0
.L00037624:
/*    37624:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    37628:	27bd0030 */ 	addiu	$sp,$sp,0x30
/*    3762c:	03e00008 */ 	jr	$ra
/*    37630:	00000000 */ 	sll	$zero,$zero,0x0
/*    37634:	30a500ff */ 	andi	$a1,$a1,0xff
/*    37638:	a0850088 */ 	sb	$a1,0x88($a0)
/*    3763c:	03e00008 */ 	jr	$ra
/*    37640:	00000000 */ 	sll	$zero,$zero,0x0
/*    37644:	03e00008 */ 	jr	$ra
/*    37648:	00000000 */ 	sll	$zero,$zero,0x0
/*    3764c:	00000000 */ 	sll	$zero,$zero,0x0
);