#include <ultra64.h>
#include "constants.h"
#include "game/game_1668e0.h"
#include "gvars/gvars.h"
#include "data.h"
#include "types.h"

#if VERSION >= VERSION_PAL_FINAL
const char var7f1a9880pf[] = "language";

GLOBAL_ASM(
glabel func0f01d860
/*  f01d930:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f01d934:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f01d938:	3c047f1b */ 	lui	$a0,0x7f1b
/*  f01d93c:	3c058006 */ 	lui	$a1,0x8006
/*  f01d940:	24a52630 */ 	addiu	$a1,$a1,0x2630
/*  f01d944:	0c003624 */ 	jal	0xd890
/*  f01d948:	24849880 */ 	addiu	$a0,$a0,-26496
/*  f01d94c:	3c048006 */ 	lui	$a0,0x8006
/*  f01d950:	8c842630 */ 	lw	$a0,0x2630($a0)
/*  f01d954:	2c810005 */ 	sltiu	$at,$a0,0x5
/*  f01d958:	10200006 */ 	beqz	$at,.PF0f01d974
/*  f01d95c:	00000000 */ 	nop
/*  f01d960:	0fc5bdd7 */ 	jal	0xf16f75c
/*  f01d964:	00000000 */ 	nop
/*  f01d968:	240e0063 */ 	li	$t6,0x63
/*  f01d96c:	3c018006 */ 	lui	$at,0x8006
/*  f01d970:	ac2e2630 */ 	sw	$t6,0x2630($at)
.PF0f01d974:
/*  f01d974:	3c0f8008 */ 	lui	$t7,0x8008
/*  f01d978:	8def4660 */ 	lw	$t7,0x4660($t7)
/*  f01d97c:	00001025 */ 	move	$v0,$zero
/*  f01d980:	240600f8 */ 	li	$a2,0xf8
/*  f01d984:	11e00011 */ 	beqz	$t7,.PF0f01d9cc
/*  f01d988:	3c05800b */ 	lui	$a1,0x800b
/*  f01d98c:	24a5b158 */ 	addiu	$a1,$a1,-20136
/*  f01d990:	8cb80000 */ 	lw	$t8,0x0($a1)
.PF0f01d994:
/*  f01d994:	03021821 */ 	addu	$v1,$t8,$v0
/*  f01d998:	94640000 */ 	lhu	$a0,0x0($v1)
/*  f01d99c:	24420002 */ 	addiu	$v0,$v0,0x2
/*  f01d9a0:	0004cb82 */ 	srl	$t9,$a0,0xe
/*  f01d9a4:	13200007 */ 	beqz	$t9,.PF0f01d9c4
/*  f01d9a8:	00000000 */ 	nop
/*  f01d9ac:	906b0000 */ 	lbu	$t3,0x0($v1)
/*  f01d9b0:	2728ffff */ 	addiu	$t0,$t9,-1
/*  f01d9b4:	00085180 */ 	sll	$t2,$t0,0x6
/*  f01d9b8:	316cff3f */ 	andi	$t4,$t3,0xff3f
/*  f01d9bc:	014c6825 */ 	or	$t5,$t2,$t4
/*  f01d9c0:	a06d0000 */ 	sb	$t5,0x0($v1)
.PF0f01d9c4:
/*  f01d9c4:	5446fff3 */ 	bnel	$v0,$a2,.PF0f01d994
/*  f01d9c8:	8cb80000 */ 	lw	$t8,0x0($a1)
.PF0f01d9cc:
/*  f01d9cc:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f01d9d0:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f01d9d4:	03e00008 */ 	jr	$ra
/*  f01d9d8:	00000000 */ 	nop
/*  f01d9dc:	00000000 */ 	nop
);
#else
void func0f01d860(void)
{
	s32 i;

	if (g_Jpn) {
		for (i = 0; i != 124; i++) {
			if (var800aabb8[i].unk00_00) {
				var800aabb8[i].unk00_00--;
			}
		}
	}
}
#endif

void func0f01d8c0(void)
{
	s32 i;

	for (i = 0; i < var80082050; i++) {
		if (var800a6668[i] >= 0) {
			var800a6660[i]++;

			if (var800a6660[i] > 1) {
				func0f16696c(i);
			}
		}
	}
}
