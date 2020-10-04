#include <libultra_internal.h>

GLOBAL_ASM(
glabel osSetIntMask
/*    48650:	400c6000 */ 	mfc0	$t4,$12
/*    48654:	3182ff01 */ 	andi	$v0,$t4,0xff01
/*    48658:	3c088006 */ 	lui	$t0,%hi(var8005cf70)
/*    4865c:	2508cf70 */ 	addiu	$t0,$t0,%lo(var8005cf70)
/*    48660:	8d0b0000 */ 	lw	$t3,0x0($t0)
/*    48664:	2401ffff */ 	addiu	$at,$zero,-1
/*    48668:	01614026 */ 	xor	$t0,$t3,$at
/*    4866c:	3108ff00 */ 	andi	$t0,$t0,0xff00
/*    48670:	00481025 */ 	or	$v0,$v0,$t0
/*    48674:	3c0aa430 */ 	lui	$t2,0xa430
/*    48678:	8d4a000c */ 	lw	$t2,0xc($t2)
/*    4867c:	11400005 */ 	beqz	$t2,.L00048694
/*    48680:	000b4c02 */ 	srl	$t1,$t3,0x10
/*    48684:	2401ffff */ 	addiu	$at,$zero,-1
/*    48688:	01214826 */ 	xor	$t1,$t1,$at
/*    4868c:	3129003f */ 	andi	$t1,$t1,0x3f
/*    48690:	01495025 */ 	or	$t2,$t2,$t1
.L00048694:
/*    48694:	000a5400 */ 	sll	$t2,$t2,0x10
/*    48698:	004a1025 */ 	or	$v0,$v0,$t2
/*    4869c:	3c01003f */ 	lui	$at,0x3f
/*    486a0:	00814024 */ 	and	$t0,$a0,$at
/*    486a4:	010b4024 */ 	and	$t0,$t0,$t3
/*    486a8:	000843c2 */ 	srl	$t0,$t0,0xf
/*    486ac:	3c0a7006 */ 	lui	$t2,%hi(var70059e30)
/*    486b0:	01485021 */ 	addu	$t2,$t2,$t0
/*    486b4:	954a9e30 */ 	lhu	$t2,%lo(var70059e30)($t2)
/*    486b8:	3c01a430 */ 	lui	$at,0xa430
/*    486bc:	ac2a000c */ 	sw	$t2,0xc($at)
/*    486c0:	3088ff01 */ 	andi	$t0,$a0,0xff01
/*    486c4:	3169ff00 */ 	andi	$t1,$t3,0xff00
/*    486c8:	01094024 */ 	and	$t0,$t0,$t1
/*    486cc:	3c01ffff */ 	lui	$at,0xffff
/*    486d0:	342100ff */ 	ori	$at,$at,0xff
/*    486d4:	01816024 */ 	and	$t4,$t4,$at
/*    486d8:	01886025 */ 	or	$t4,$t4,$t0
/*    486dc:	408c6000 */ 	mtc0	$t4,$12
/*    486e0:	00000000 */ 	nop
/*    486e4:	00000000 */ 	nop
/*    486e8:	03e00008 */ 	jr	$ra
/*    486ec:	00000000 */ 	nop
);
