#include <ultra64.h>
#include "constants.h"
#include "lib/reset.h"
#include "gvars/gvars.h"
#include "data.h"
#include "types.h"

#if VERSION >= VERSION_PAL_FINAL
GLOBAL_ASM(
glabel resetproc
/*     2df0:	27bdffd0 */ 	addiu	$sp,$sp,-48
/*     2df4:	afa40030 */ 	sw	$a0,0x30($sp)
/*     2df8:	afbf0014 */ 	sw	$ra,0x14($sp)
/*     2dfc:	3c048009 */ 	lui	$a0,0x8009
/*     2e00:	afa0002c */ 	sw	$zero,0x2c($sp)
/*     2e04:	2484fff8 */ 	addiu	$a0,$a0,-8
/*     2e08:	27a5002c */ 	addiu	$a1,$sp,0x2c
/*     2e0c:	0c011ffc */ 	jal	0x47ff0
/*     2e10:	24060001 */ 	li	$a2,0x1
/*     2e14:	240e0001 */ 	li	$t6,0x1
/*     2e18:	3c018006 */ 	lui	$at,0x8006
/*     2e1c:	0c002413 */ 	jal	0x904c
/*     2e20:	a02ecb80 */ 	sb	$t6,-0x3480($at)
/*     2e24:	3c048009 */ 	lui	$a0,0x8009
/*     2e28:	0c011f1c */ 	jal	0x47c70
/*     2e2c:	2484dc20 */ 	addiu	$a0,$a0,-9184
/*     2e30:	00002025 */ 	move	$a0,$zero
/*     2e34:	0c011f4c */ 	jal	0x47d30
/*     2e38:	2405000b */ 	li	$a1,0xb
/*     2e3c:	3c028006 */ 	lui	$v0,0x8006
/*     2e40:	2442f3c0 */ 	addiu	$v0,$v0,-3136
/*     2e44:	24030400 */ 	li	$v1,0x400
/*     2e48:	3c048006 */ 	lui	$a0,0x8006
/*     2e4c:	ac43052c */ 	sw	$v1,0x52c($v0)
/*     2e50:	ac430540 */ 	sw	$v1,0x540($v0)
/*     2e54:	0c012194 */ 	jal	0x48650
/*     2e58:	2484f8c0 */ 	addiu	$a0,$a0,-1856
/*     2e5c:	0c012178 */ 	jal	0x485e0
/*     2e60:	24040001 */ 	li	$a0,0x1
/*     2e64:	0c012288 */ 	jal	0x48a20
/*     2e68:	00000000 */ 	nop
/*     2e6c:	3c018009 */ 	lui	$at,0x8009
/*     2e70:	ac220340 */ 	sw	$v0,0x340($at)
/*     2e74:	0c012288 */ 	jal	0x48a20
/*     2e78:	ac230344 */ 	sw	$v1,0x344($at)
/*     2e7c:	3c198009 */ 	lui	$t9,0x8009
/*     2e80:	8f390344 */ 	lw	$t9,0x344($t9)
/*     2e84:	3c188009 */ 	lui	$t8,0x8009
/*     2e88:	3c010022 */ 	lui	$at,0x22
/*     2e8c:	8f180340 */ 	lw	$t8,0x340($t8)
/*     2e90:	3421add7 */ 	ori	$at,$at,0xadd7
/*     2e94:	03214821 */ 	addu	$t1,$t9,$at
/*     2e98:	0121082b */ 	sltu	$at,$t1,$at
/*     2e9c:	03014021 */ 	addu	$t0,$t8,$at
/*     2ea0:	25080000 */ 	addiu	$t0,$t0,0x0
/*     2ea4:	0102082b */ 	sltu	$at,$t0,$v0
/*     2ea8:	14200019 */ 	bnez	$at,.PF00002f10
/*     2eac:	0048082b */ 	sltu	$at,$v0,$t0
/*     2eb0:	14200003 */ 	bnez	$at,.PF00002ec0
/*     2eb4:	0069082b */ 	sltu	$at,$v1,$t1
/*     2eb8:	10200015 */ 	beqz	$at,.PF00002f10
/*     2ebc:	00000000 */ 	nop
.PF00002ec0:
/*     2ec0:	0c012288 */ 	jal	0x48a20
/*     2ec4:	00000000 */ 	nop
/*     2ec8:	3c0b8009 */ 	lui	$t3,0x8009
/*     2ecc:	8d6b0344 */ 	lw	$t3,0x344($t3)
/*     2ed0:	3c0a8009 */ 	lui	$t2,0x8009
/*     2ed4:	3c010022 */ 	lui	$at,0x22
/*     2ed8:	8d4a0340 */ 	lw	$t2,0x340($t2)
/*     2edc:	3421add7 */ 	ori	$at,$at,0xadd7
/*     2ee0:	01616821 */ 	addu	$t5,$t3,$at
/*     2ee4:	01a1082b */ 	sltu	$at,$t5,$at
/*     2ee8:	01416021 */ 	addu	$t4,$t2,$at
/*     2eec:	258c0000 */ 	addiu	$t4,$t4,0x0
/*     2ef0:	004c082b */ 	sltu	$at,$v0,$t4
/*     2ef4:	1420fff2 */ 	bnez	$at,.PF00002ec0
/*     2ef8:	00000000 */ 	nop
/*     2efc:	0182082b */ 	sltu	$at,$t4,$v0
/*     2f00:	14200003 */ 	bnez	$at,.PF00002f10
/*     2f04:	006d082b */ 	sltu	$at,$v1,$t5
/*     2f08:	1420ffed */ 	bnez	$at,.PF00002ec0
/*     2f0c:	00000000 */ 	nop
.PF00002f10:
/*     2f10:	0c0053c9 */ 	jal	0x14f24
/*     2f14:	00000000 */ 	nop
.PF00002f18:
/*     2f18:	1000ffff */ 	b	.PF00002f18
/*     2f1c:	00000000 */ 	nop
/*     2f20:	00000000 */ 	nop
/*     2f24:	00000000 */ 	nop
/*     2f28:	00000000 */ 	nop
/*     2f2c:	00000000 */ 	nop
/*     2f30:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*     2f34:	27bd0030 */ 	addiu	$sp,$sp,0x30
/*     2f38:	03e00008 */ 	jr	$ra
/*     2f3c:	00000000 */ 	nop
);
#else
GLOBAL_ASM(
glabel resetproc
/*     2e00:	27bdffd0 */ 	addiu	$sp,$sp,-48
/*     2e04:	afa40030 */ 	sw	$a0,0x30($sp)
/*     2e08:	afbf0014 */ 	sw	$ra,0x14($sp)
/*     2e0c:	3c048009 */ 	lui	$a0,%hi(g_ResetMesgQueue)
/*     2e10:	afa0002c */ 	sw	$zero,0x2c($sp)
/*     2e14:	2484faa8 */ 	addiu	$a0,$a0,%lo(g_ResetMesgQueue)
/*     2e18:	27a5002c */ 	addiu	$a1,$sp,0x2c
/*     2e1c:	0c0121bc */ 	jal	osRecvMesg
/*     2e20:	24060001 */ 	addiu	$a2,$zero,0x1
/*     2e24:	240e0001 */ 	addiu	$t6,$zero,0x1
/*     2e28:	3c018006 */ 	lui	$at,%hi(var8005ced0)
/*     2e2c:	0c002449 */ 	jal	amgrStopThread
/*     2e30:	a02eced0 */ 	sb	$t6,%lo(var8005ced0)($at)
/*     2e34:	3c048009 */ 	lui	$a0,%hi(g_MainThread)
/*     2e38:	0c0120dc */ 	jal	osStopThread
/*     2e3c:	2484d6d0 */ 	addiu	$a0,$a0,%lo(g_MainThread)
/*     2e40:	00002025 */ 	or	$a0,$zero,$zero
/*     2e44:	0c01210c */ 	jal	osSetThreadPri
/*     2e48:	2405000b */ 	addiu	$a1,$zero,0xb
/*     2e4c:	3c0f8000 */ 	lui	$t7,0x8000
/*     2e50:	8def0300 */ 	lw	$t7,0x300($t7)
/*     2e54:	24010002 */ 	addiu	$at,$zero,0x2
/*     2e58:	24020400 */ 	addiu	$v0,$zero,0x400
/*     2e5c:	15e10004 */ 	bne	$t7,$at,.L00002e70
/*     2e60:	3c048006 */ 	lui	$a0,%hi(osViModeTable+0xa0)
/*     2e64:	3c048006 */ 	lui	$a0,%hi(osViModeTable+0x960)
/*     2e68:	10000002 */ 	b	.L00002e74
/*     2e6c:	24840070 */ 	addiu	$a0,$a0,%lo(osViModeTable+0x960)
.L00002e70:
/*     2e70:	2484f7b0 */ 	addiu	$a0,$a0,%lo(osViModeTable+0xa0)
.L00002e74:
/*     2e74:	ac82002c */ 	sw	$v0,0x2c($a0)
/*     2e78:	0c012354 */ 	jal	osViSetMode
/*     2e7c:	ac820040 */ 	sw	$v0,0x40($a0)
/*     2e80:	0c012338 */ 	jal	osViBlack
/*     2e84:	24040001 */ 	addiu	$a0,$zero,0x1
/*     2e88:	0c012448 */ 	jal	osGetTime
/*     2e8c:	00000000 */ 	nop
/*     2e90:	3c018009 */ 	lui	$at,%hi(g_ResetStack+0x100)
/*     2e94:	ac22fdf0 */ 	sw	$v0,%lo(g_ResetStack+0x100)($at)
/*     2e98:	0c012448 */ 	jal	osGetTime
/*     2e9c:	ac23fdf4 */ 	sw	$v1,-0x20c($at)
/*     2ea0:	3c198009 */ 	lui	$t9,%hi(var8008fdf4)
/*     2ea4:	8f39fdf4 */ 	lw	$t9,%lo(var8008fdf4)($t9)
/*     2ea8:	3c188009 */ 	lui	$t8,%hi(g_ResetStack+0x100)
/*     2eac:	3c010022 */ 	lui	$at,0x22
/*     2eb0:	8f18fdf0 */ 	lw	$t8,%lo(g_ResetStack+0x100)($t8)
/*     2eb4:	3421add7 */ 	ori	$at,$at,0xadd7
/*     2eb8:	03214821 */ 	addu	$t1,$t9,$at
/*     2ebc:	0121082b */ 	sltu	$at,$t1,$at
/*     2ec0:	03014021 */ 	addu	$t0,$t8,$at
/*     2ec4:	25080000 */ 	addiu	$t0,$t0,0x0
/*     2ec8:	0102082b */ 	sltu	$at,$t0,$v0
/*     2ecc:	14200019 */ 	bnez	$at,.L00002f34
/*     2ed0:	0048082b */ 	sltu	$at,$v0,$t0
/*     2ed4:	14200003 */ 	bnez	$at,.L00002ee4
/*     2ed8:	0069082b */ 	sltu	$at,$v1,$t1
/*     2edc:	10200015 */ 	beqz	$at,.L00002f34
/*     2ee0:	00000000 */ 	nop
.L00002ee4:
/*     2ee4:	0c012448 */ 	jal	osGetTime
/*     2ee8:	00000000 */ 	nop
/*     2eec:	3c0b8009 */ 	lui	$t3,%hi(var8008fdf4)
/*     2ef0:	8d6bfdf4 */ 	lw	$t3,%lo(var8008fdf4)($t3)
/*     2ef4:	3c0a8009 */ 	lui	$t2,%hi(g_ResetStack+0x100)
/*     2ef8:	3c010022 */ 	lui	$at,0x22
/*     2efc:	8d4afdf0 */ 	lw	$t2,%lo(g_ResetStack+0x100)($t2)
/*     2f00:	3421add7 */ 	ori	$at,$at,0xadd7
/*     2f04:	01616821 */ 	addu	$t5,$t3,$at
/*     2f08:	01a1082b */ 	sltu	$at,$t5,$at
/*     2f0c:	01416021 */ 	addu	$t4,$t2,$at
/*     2f10:	258c0000 */ 	addiu	$t4,$t4,0x0
/*     2f14:	004c082b */ 	sltu	$at,$v0,$t4
/*     2f18:	1420fff2 */ 	bnez	$at,.L00002ee4
/*     2f1c:	00000000 */ 	nop
/*     2f20:	0182082b */ 	sltu	$at,$t4,$v0
/*     2f24:	14200003 */ 	bnez	$at,.L00002f34
/*     2f28:	006d082b */ 	sltu	$at,$v1,$t5
/*     2f2c:	1420ffed */ 	bnez	$at,.L00002ee4
/*     2f30:	00000000 */ 	nop
.L00002f34:
/*     2f34:	3c048006 */ 	lui	$a0,%hi(osViModeTable+0xa0)
/*     2f38:	0c005467 */ 	jal	func0001519c
/*     2f3c:	2484f7b0 */ 	addiu	$a0,$a0,%lo(osViModeTable+0xa0)
.L00002f40:
/*     2f40:	1000ffff */ 	b	.L00002f40
/*     2f44:	00000000 */ 	nop
/*     2f48:	00000000 */ 	nop
/*     2f4c:	00000000 */ 	nop
/*     2f50:	00000000 */ 	nop
/*     2f54:	00000000 */ 	nop
/*     2f58:	00000000 */ 	nop
/*     2f5c:	00000000 */ 	nop
/*     2f60:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*     2f64:	27bd0030 */ 	addiu	$sp,$sp,0x30
/*     2f68:	03e00008 */ 	jr	$ra
/*     2f6c:	00000000 */ 	nop
);
#endif

void resetThreadCreate(void)
{
	osCreateMesgQueue(&g_ResetMesgQueue, &g_ResetMesg, 10);
	osSetEventMesg(OS_EVENT_PRENMI, &g_ResetMesgQueue, (OSMesg) 669);
	osCreateThread(&g_ResetThread, THREAD_RESET, resetproc, 0, &g_ResetStack[STACKSIZE_RESET], THREADPRI_RESET);
	osStartThread(&g_ResetThread);
}
