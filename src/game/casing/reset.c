#include <ultra64.h>
#include "constants.h"
#include "bss.h"
#include "data.h"
#include "types.h"

#if VERSION >= VERSION_NTSC_1_0
GLOBAL_ASM(
glabel casingsReset
/*  f010b20:	3c04800a */ 	lui	$a0,%hi(var8009d0d0)
/*  f010b24:	2484d0d0 */ 	addiu	$a0,$a0,%lo(var8009d0d0)
/*  f010b28:	ac800000 */ 	sw	$zero,0x0($a0)
/*  f010b2c:	ac800004 */ 	sw	$zero,0x4($a0)
/*  f010b30:	3c01800a */ 	lui	$at,%hi(var8009d0d8)
/*  f010b34:	3c03800a */ 	lui	$v1,%hi(g_BgunAudioHandles+0x10)
/*  f010b38:	3c02800a */ 	lui	$v0,%hi(g_BgunAudioHandles)
/*  f010b3c:	ac20d0d8 */ 	sw	$zero,%lo(var8009d0d8)($at)
/*  f010b40:	2442d0f0 */ 	addiu	$v0,$v0,%lo(g_BgunAudioHandles+0x10)
/*  f010b44:	2463d0e0 */ 	addiu	$v1,$v1,%lo(g_BgunAudioHandles)
.L0f010b48:
/*  f010b48:	24630004 */ 	addiu	$v1,$v1,0x4
/*  f010b4c:	1462fffe */ 	bne	$v1,$v0,.L0f010b48
/*  f010b50:	ac60fffc */ 	sw	$zero,-0x4($v1)
/*  f010b54:	3c02800a */ 	lui	$v0,%hi(var8009da60)
/*  f010b58:	3c03800a */ 	lui	$v1,%hi(g_Casings)
/*  f010b5c:	2442da60 */ 	addiu	$v0,$v0,%lo(var8009da60)
/*  f010b60:	2463d510 */ 	addiu	$v1,$v1,%lo(g_Casings)
.L0f010b64:
/*  f010b64:	24630044 */ 	addiu	$v1,$v1,0x44
/*  f010b68:	0062082b */ 	sltu	$at,$v1,$v0
/*  f010b6c:	1420fffd */ 	bnez	$at,.L0f010b64
/*  f010b70:	ac60fffc */ 	sw	$zero,-0x4($v1)
/*  f010b74:	3c018007 */ 	lui	$at,%hi(g_CasingsActive)
/*  f010b78:	3c03800a */ 	lui	$v1,%hi(g_Fireslots)
/*  f010b7c:	3c04800a */ 	lui	$a0,%hi(g_Fireslots+0x3c0)
/*  f010b80:	ac200524 */ 	sw	$zero,%lo(g_CasingsActive)($at)
/*  f010b84:	2484d510 */ 	addiu	$a0,$a0,%lo(g_Fireslots+0x3c0)
/*  f010b88:	2463d150 */ 	addiu	$v1,$v1,%lo(g_Fireslots)
/*  f010b8c:	2402ffff */ 	addiu	$v0,$zero,-1
.L0f010b90:
/*  f010b90:	24630030 */ 	addiu	$v1,$v1,0x30
/*  f010b94:	1464fffe */ 	bne	$v1,$a0,.L0f010b90
/*  f010b98:	ac62ffd0 */ 	sw	$v0,-0x30($v1)
/*  f010b9c:	3c02800a */ 	lui	$v0,%hi(g_Vars)
/*  f010ba0:	24429fc0 */ 	addiu	$v0,$v0,%lo(g_Vars)
/*  f010ba4:	ac4002b0 */ 	sw	$zero,0x2b0($v0)
/*  f010ba8:	03e00008 */ 	jr	$ra
/*  f010bac:	ac4002b4 */ 	sw	$zero,0x2b4($v0)
);
#else
GLOBAL_ASM(
glabel casingsReset
/*  f010860:	3c04800a */ 	lui	$a0,0x800a
/*  f010864:	24841868 */ 	addiu	$a0,$a0,0x1868
/*  f010868:	ac800000 */ 	sw	$zero,0x0($a0)
/*  f01086c:	ac800004 */ 	sw	$zero,0x4($a0)
/*  f010870:	3c01800a */ 	lui	$at,0x800a
/*  f010874:	3c03800a */ 	lui	$v1,0x800a
/*  f010878:	3c02800a */ 	lui	$v0,0x800a
/*  f01087c:	ac201870 */ 	sw	$zero,0x1870($at)
/*  f010880:	24421888 */ 	addiu	$v0,$v0,0x1888
/*  f010884:	24631878 */ 	addiu	$v1,$v1,0x1878
.NB0f010888:
/*  f010888:	24630004 */ 	addiu	$v1,$v1,0x4
/*  f01088c:	1462fffe */ 	bne	$v1,$v0,.NB0f010888
/*  f010890:	ac60fffc */ 	sw	$zero,-0x4($v1)
/*  f010894:	3c02800a */ 	lui	$v0,0x800a
/*  f010898:	3c03800a */ 	lui	$v1,0x800a
/*  f01089c:	24422240 */ 	addiu	$v0,$v0,0x2240
/*  f0108a0:	24631cf0 */ 	addiu	$v1,$v1,0x1cf0
.NB0f0108a4:
/*  f0108a4:	24630044 */ 	addiu	$v1,$v1,0x44
/*  f0108a8:	0062082b */ 	sltu	$at,$v1,$v0
/*  f0108ac:	1420fffd */ 	bnez	$at,.NB0f0108a4
/*  f0108b0:	ac60fffc */ 	sw	$zero,-0x4($v1)
/*  f0108b4:	3c018007 */ 	lui	$at,0x8007
/*  f0108b8:	3c03800a */ 	lui	$v1,0x800a
/*  f0108bc:	3c04800a */ 	lui	$a0,0x800a
/*  f0108c0:	ac202be4 */ 	sw	$zero,0x2be4($at)
/*  f0108c4:	24841ce8 */ 	addiu	$a0,$a0,0x1ce8
/*  f0108c8:	24631888 */ 	addiu	$v1,$v1,0x1888
/*  f0108cc:	2402ffff */ 	addiu	$v0,$zero,-1
.NB0f0108d0:
/*  f0108d0:	24630038 */ 	addiu	$v1,$v1,0x38
/*  f0108d4:	1464fffe */ 	bne	$v1,$a0,.NB0f0108d0
/*  f0108d8:	ac62ffc8 */ 	sw	$v0,-0x38($v1)
/*  f0108dc:	3c02800a */ 	lui	$v0,0x800a
/*  f0108e0:	2442e6c0 */ 	addiu	$v0,$v0,-6464
/*  f0108e4:	ac4002b0 */ 	sw	$zero,0x2b0($v0)
/*  f0108e8:	03e00008 */ 	jr	$ra
/*  f0108ec:	ac4002b4 */ 	sw	$zero,0x2b4($v0)
);
#endif

// Mismatch: Two instructions are swapped
//void casingsReset(void)
//{
//	s32 i;
//
//	var8009d0d0[0] = 0;
//	var8009d0d0[1] = 0;
//	var8009d0d8 = 0;
//
//	for (i = 0; i != ARRAYCOUNT(g_BgunAudioHandles); i++) {
//		g_BgunAudioHandles[i] = 0;
//	}
//
//	for (i = 0; i < ARRAYCOUNT(g_Casings); i++) {
//		g_Casings[i].unk40 = 0;
//	}
//
//	g_CasingsActive = 0;
//
//	for (i = 0; i < ARRAYCOUNT(g_Fireslots); i++) {
//		g_Fireslots[i].unk00 = -1;
//	}
//
//	g_Vars.killcount = 0;
//	g_Vars.knockoutcount = 0;
//}
