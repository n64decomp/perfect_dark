#include <ultra64.h>
#include "constants.h"
#include "boot/reset.h"
#include "gvars/gvars.h"
#include "types.h"

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
/*     2e2c:	0c002449 */ 	jal	audioStopThread
/*     2e30:	a02eced0 */ 	sb	$t6,%lo(var8005ced0)($at)
/*     2e34:	3c048009 */ 	lui	$a0,%hi(var8008d6d0)
/*     2e38:	0c0120dc */ 	jal	osStopThread
/*     2e3c:	2484d6d0 */ 	addiu	$a0,$a0,%lo(var8008d6d0)
/*     2e40:	00002025 */ 	or	$a0,$zero,$zero
/*     2e44:	0c01210c */ 	jal	osSetThreadPri
/*     2e48:	2405000b */ 	addiu	$a1,$zero,0xb
/*     2e4c:	3c0f8000 */ 	lui	$t7,0x8000
/*     2e50:	8def0300 */ 	lw	$t7,0x300($t7)
/*     2e54:	24010002 */ 	addiu	$at,$zero,0x2
/*     2e58:	24020400 */ 	addiu	$v0,$zero,0x400
/*     2e5c:	15e10004 */ 	bne	$t7,$at,.L00002e70
/*     2e60:	3c048006 */ 	lui	$a0,%hi(var8005f7b0)
/*     2e64:	3c048006 */ 	lui	$a0,%hi(var80060070)
/*     2e68:	10000002 */ 	b	.L00002e74
/*     2e6c:	24840070 */ 	addiu	$a0,$a0,%lo(var80060070)
.L00002e70:
/*     2e70:	2484f7b0 */ 	addiu	$a0,$a0,%lo(var8005f7b0)
.L00002e74:
/*     2e74:	ac82002c */ 	sw	$v0,0x2c($a0)
/*     2e78:	0c012354 */ 	jal	func00048d50
/*     2e7c:	ac820040 */ 	sw	$v0,0x40($a0)
/*     2e80:	0c012338 */ 	jal	func00048ce0
/*     2e84:	24040001 */ 	addiu	$a0,$zero,0x1
/*     2e88:	0c012448 */ 	jal	func00049120
/*     2e8c:	00000000 */ 	nop
/*     2e90:	3c018009 */ 	lui	$at,%hi(var8008fdf0)
/*     2e94:	ac22fdf0 */ 	sw	$v0,%lo(var8008fdf0)($at)
/*     2e98:	0c012448 */ 	jal	func00049120
/*     2e9c:	ac23fdf4 */ 	sw	$v1,-0x20c($at)
/*     2ea0:	3c198009 */ 	lui	$t9,%hi(var8008fdf4)
/*     2ea4:	8f39fdf4 */ 	lw	$t9,%lo(var8008fdf4)($t9)
/*     2ea8:	3c188009 */ 	lui	$t8,%hi(var8008fdf0)
/*     2eac:	3c010022 */ 	lui	$at,0x22
/*     2eb0:	8f18fdf0 */ 	lw	$t8,%lo(var8008fdf0)($t8)
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
/*     2ee4:	0c012448 */ 	jal	func00049120
/*     2ee8:	00000000 */ 	nop
/*     2eec:	3c0b8009 */ 	lui	$t3,%hi(var8008fdf4)
/*     2ef0:	8d6bfdf4 */ 	lw	$t3,%lo(var8008fdf4)($t3)
/*     2ef4:	3c0a8009 */ 	lui	$t2,%hi(var8008fdf0)
/*     2ef8:	3c010022 */ 	lui	$at,0x22
/*     2efc:	8d4afdf0 */ 	lw	$t2,%lo(var8008fdf0)($t2)
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
/*     2f34:	3c048006 */ 	lui	$a0,%hi(var8005f7b0)
/*     2f38:	0c005467 */ 	jal	func0001519c
/*     2f3c:	2484f7b0 */ 	addiu	$a0,$a0,%lo(var8005f7b0)
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

void resetThreadCreate(void)
{
	osCreateMesgQueue(&g_ResetMesgQueue, &g_ResetMesg, 10);
	osSetEventMesg(OS_EVENT_PRENMI, &g_ResetMesgQueue, (OSMesg) 669);
	osCreateThread(&g_ResetThread, THREAD_RESET, resetproc, 0, &var8008fdf0, 11);
	osStartThread(&g_ResetThread);
}
