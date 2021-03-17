#include <libultra_internal.h>
#include "data.h"

#if VERSION >= VERSION_PAL_FINAL
const u32 var70059eb0[] = {0x70049a7c};
const u32 var70059eb4[] = {0x70049994};
const u32 var70059eb8[] = {0x700499c8};
const u32 var70059ebc[] = {0x70049a98};
const u32 var70059ec0[] = {0x70049a98};
const u32 var70059ec4[] = {0x700499fc};
const u32 var70059ec8[] = {0x70049a3c};
#else
const u32 var70059eb0[] = {0x7004a17c};
const u32 var70059eb4[] = {0x7004a094};
const u32 var70059eb8[] = {0x7004a0c8};
const u32 var70059ebc[] = {0x7004a198};
const u32 var70059ec0[] = {0x7004a198};
const u32 var70059ec4[] = {0x7004a0fc};
const u32 var70059ec8[] = {0x7004a13c};
#endif

GLOBAL_ASM(
glabel __osDevMgrMain
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
/*    49e54:	0c0121bc */ 	jal	osRecvMesg
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
/*    49ef8:	00000000 */ 	nop
/*    49efc:	10000001 */ 	b	.L00049f04
/*    49f00:	02e09025 */ 	or	$s2,$s7,$zero
.L00049f04:
/*    49f04:	0c0121bc */ 	jal	osRecvMesg
/*    49f08:	8e840010 */ 	lw	$a0,0x10($s4)
/*    49f0c:	3c040010 */ 	lui	$a0,0x10
/*    49f10:	0c014628 */ 	jal	__osResetGlobalIntMask
/*    49f14:	34840401 */ 	ori	$a0,$a0,0x401
/*    49f18:	8e060010 */ 	lw	$a2,0x10($s0)
/*    49f1c:	8faf0074 */ 	lw	$t7,0x74($sp)
/*    49f20:	3c018000 */ 	lui	$at,0x8000
/*    49f24:	00c1c025 */ 	or	$t8,$a2,$at
/*    49f28:	03003025 */ 	or	$a2,$t8,$zero
/*    49f2c:	02602825 */ 	or	$a1,$s3,$zero
/*    49f30:	0c014640 */ 	jal	osEPiRawWriteIo
/*    49f34:	8de40014 */ 	lw	$a0,0x14($t7)
.L00049f38:
/*    49f38:	8e84000c */ 	lw	$a0,0xc($s4)
/*    49f3c:	02c02825 */ 	or	$a1,$s6,$zero
/*    49f40:	0c0121bc */ 	jal	osRecvMesg
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
/*    49f84:	0c014640 */ 	jal	osEPiRawWriteIo
/*    49f88:	01603025 */ 	or	$a2,$t3,$zero
/*    49f8c:	8fac0074 */ 	lw	$t4,0x74($sp)
/*    49f90:	02602825 */ 	or	$a1,$s3,$zero
/*    49f94:	8e060010 */ 	lw	$a2,0x10($s0)
/*    49f98:	0c014640 */ 	jal	osEPiRawWriteIo
/*    49f9c:	8d840014 */ 	lw	$a0,0x14($t4)
/*    49fa0:	8fad0074 */ 	lw	$t5,0x74($sp)
/*    49fa4:	3c050500 */ 	lui	$a1,0x500
/*    49fa8:	34a50508 */ 	ori	$a1,$a1,0x508
/*    49fac:	27a60054 */ 	addiu	$a2,$sp,0x54
/*    49fb0:	0c014698 */ 	jal	osEPiRawReadIo
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
/*    49fe0:	0c014640 */ 	jal	osEPiRawWriteIo
/*    49fe4:	03203025 */ 	or	$a2,$t9,$zero
/*    49fe8:	24080004 */ 	addiu	$t0,$zero,0x4
.L00049fec:
/*    49fec:	ae280000 */ 	sw	$t0,0x0($s1)
/*    49ff0:	24090002 */ 	addiu	$t1,$zero,0x2
/*    49ff4:	3c0aa460 */ 	lui	$t2,0xa460
/*    49ff8:	3c040010 */ 	lui	$a0,0x10
/*    49ffc:	ad490010 */ 	sw	$t1,0x10($t2)
/*    4a000:	0c0146f0 */ 	jal	__osSetGlobalIntMask
/*    4a004:	34840c01 */ 	ori	$a0,$a0,0xc01
/*    4a008:	8fa50074 */ 	lw	$a1,0x74($sp)
.L0004a00c:
/*    4a00c:	00003025 */ 	or	$a2,$zero,$zero
/*    4a010:	0c012238 */ 	jal	osSendMesg
/*    4a014:	8ca40004 */ 	lw	$a0,0x4($a1)
/*    4a018:	16570007 */ 	bne	$s2,$s7,.L0004a038
/*    4a01c:	8fac0074 */ 	lw	$t4,0x74($sp)
/*    4a020:	8d8d0014 */ 	lw	$t5,0x14($t4)
/*    4a024:	8dae002c */ 	lw	$t6,0x2c($t5)
/*    4a028:	55c00004 */ 	bnezl	$t6,.L0004a03c
/*    4a02c:	8e840010 */ 	lw	$a0,0x10($s4)
/*    4a030:	1000ffc1 */ 	b	.L00049f38
/*    4a034:	00009025 */ 	or	$s2,$zero,$zero
.L0004a038:
/*    4a038:	8e840010 */ 	lw	$a0,0x10($s4)
.L0004a03c:
/*    4a03c:	00002825 */ 	or	$a1,$zero,$zero
/*    4a040:	0c012238 */ 	jal	osSendMesg
/*    4a044:	00003025 */ 	or	$a2,$zero,$zero
/*    4a048:	8faf0074 */ 	lw	$t7,0x74($sp)
/*    4a04c:	8df80014 */ 	lw	$t8,0x14($t7)
/*    4a050:	9719001a */ 	lhu	$t9,0x1a($t8)
/*    4a054:	56f9ff7e */ 	bnel	$s7,$t9,.L00049e50
/*    4a058:	8e840008 */ 	lw	$a0,0x8($s4)
/*    4a05c:	0c014704 */ 	jal	osYieldThread
/*    4a060:	00000000 */ 	nop
/*    4a064:	1000ff7a */ 	b	.L00049e50
/*    4a068:	8e840008 */ 	lw	$a0,0x8($s4)
/*    4a06c:	95090000 */ 	lhu	$t1,0x0($t0)
.L0004a070:
/*    4a070:	252afff6 */ 	addiu	$t2,$t1,-10
/*    4a074:	2d410007 */ 	sltiu	$at,$t2,0x7
/*    4a078:	10200047 */ 	beqz	$at,.L0004a198
/*    4a07c:	000a5080 */ 	sll	$t2,$t2,0x2
/*    4a080:	3c017006 */ 	lui	$at,%hi(var70059eb0)
/*    4a084:	002a0821 */ 	addu	$at,$at,$t2
/*    4a088:	8c2a9eb0 */ 	lw	$t2,%lo(var70059eb0)($at)
/*    4a08c:	01400008 */ 	jr	$t2
/*    4a090:	00000000 */ 	nop
/*    4a094:	8e840010 */ 	lw	$a0,0x10($s4)
/*    4a098:	27a5006c */ 	addiu	$a1,$sp,0x6c
/*    4a09c:	0c0121bc */ 	jal	osRecvMesg
/*    4a0a0:	02e03025 */ 	or	$a2,$s7,$zero
/*    4a0a4:	8fab0074 */ 	lw	$t3,0x74($sp)
/*    4a0a8:	8e990014 */ 	lw	$t9,0x14($s4)
/*    4a0ac:	00002025 */ 	or	$a0,$zero,$zero
/*    4a0b0:	8d65000c */ 	lw	$a1,0xc($t3)
/*    4a0b4:	8d660008 */ 	lw	$a2,0x8($t3)
/*    4a0b8:	0320f809 */ 	jalr	$t9
/*    4a0bc:	8d670010 */ 	lw	$a3,0x10($t3)
/*    4a0c0:	10000036 */ 	b	.L0004a19c
/*    4a0c4:	00408025 */ 	or	$s0,$v0,$zero
/*    4a0c8:	8e840010 */ 	lw	$a0,0x10($s4)
/*    4a0cc:	27a5006c */ 	addiu	$a1,$sp,0x6c
/*    4a0d0:	0c0121bc */ 	jal	osRecvMesg
/*    4a0d4:	02e03025 */ 	or	$a2,$s7,$zero
/*    4a0d8:	8fac0074 */ 	lw	$t4,0x74($sp)
/*    4a0dc:	8e990014 */ 	lw	$t9,0x14($s4)
/*    4a0e0:	02e02025 */ 	or	$a0,$s7,$zero
/*    4a0e4:	8d85000c */ 	lw	$a1,0xc($t4)
/*    4a0e8:	8d860008 */ 	lw	$a2,0x8($t4)
/*    4a0ec:	0320f809 */ 	jalr	$t9
/*    4a0f0:	8d870010 */ 	lw	$a3,0x10($t4)
/*    4a0f4:	10000029 */ 	b	.L0004a19c
/*    4a0f8:	00408025 */ 	or	$s0,$v0,$zero
/*    4a0fc:	8e840010 */ 	lw	$a0,0x10($s4)
/*    4a100:	27a5006c */ 	addiu	$a1,$sp,0x6c
/*    4a104:	0c0121bc */ 	jal	osRecvMesg
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
/*    4a130:	00000000 */ 	nop
/*    4a134:	10000019 */ 	b	.L0004a19c
/*    4a138:	00408025 */ 	or	$s0,$v0,$zero
/*    4a13c:	8e840010 */ 	lw	$a0,0x10($s4)
/*    4a140:	27a5006c */ 	addiu	$a1,$sp,0x6c
/*    4a144:	0c0121bc */ 	jal	osRecvMesg
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
/*    4a170:	00000000 */ 	nop
/*    4a174:	10000009 */ 	b	.L0004a19c
/*    4a178:	00408025 */ 	or	$s0,$v0,$zero
/*    4a17c:	8fa50074 */ 	lw	$a1,0x74($sp)
/*    4a180:	00003025 */ 	or	$a2,$zero,$zero
/*    4a184:	2410ffff */ 	addiu	$s0,$zero,-1
/*    4a188:	0c012238 */ 	jal	osSendMesg
/*    4a18c:	8ca40004 */ 	lw	$a0,0x4($a1)
/*    4a190:	10000002 */ 	b	.L0004a19c
/*    4a194:	00000000 */ 	nop
.L0004a198:
/*    4a198:	2410ffff */ 	addiu	$s0,$zero,-1
.L0004a19c:
/*    4a19c:	1600ff2b */ 	bnez	$s0,.L00049e4c
/*    4a1a0:	02c02825 */ 	or	$a1,$s6,$zero
/*    4a1a4:	8e84000c */ 	lw	$a0,0xc($s4)
/*    4a1a8:	0c0121bc */ 	jal	osRecvMesg
/*    4a1ac:	02e03025 */ 	or	$a2,$s7,$zero
/*    4a1b0:	8fa50074 */ 	lw	$a1,0x74($sp)
/*    4a1b4:	00003025 */ 	or	$a2,$zero,$zero
/*    4a1b8:	0c012238 */ 	jal	osSendMesg
/*    4a1bc:	8ca40004 */ 	lw	$a0,0x4($a1)
/*    4a1c0:	8e840010 */ 	lw	$a0,0x10($s4)
/*    4a1c4:	00002825 */ 	or	$a1,$zero,$zero
/*    4a1c8:	0c012238 */ 	jal	osSendMesg
/*    4a1cc:	00003025 */ 	or	$a2,$zero,$zero
/*    4a1d0:	1000ff1f */ 	b	.L00049e50
/*    4a1d4:	8e840008 */ 	lw	$a0,0x8($s4)
/*    4a1d8:	00000000 */ 	nop
/*    4a1dc:	00000000 */ 	nop
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
