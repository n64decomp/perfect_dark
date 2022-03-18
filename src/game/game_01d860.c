#include <ultra64.h>
#include "constants.h"
#include "game/game_1668e0.h"
#include "bss.h"
#include "data.h"
#include "types.h"

#if VERSION >= VERSION_JPN_FINAL
const char var7f1a9240jf[] = "jap";

GLOBAL_ASM(
glabel func0f01d860
/*  f01ea20:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f01ea24:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f01ea28:	3c01800a */ 	lui	$at,0x800a
/*  f01ea2c:	3c047f1b */ 	lui	$a0,0x7f1b
/*  f01ea30:	3c058006 */ 	lui	$a1,0x8006
/*  f01ea34:	ac20d370 */ 	sw	$zero,-0x2c90($at)
/*  f01ea38:	24a528a0 */ 	addiu	$a1,$a1,0x28a0
/*  f01ea3c:	0c0036b4 */ 	jal	mainOverrideVariable
/*  f01ea40:	24849240 */ 	addiu	$a0,$a0,-28096
/*  f01ea44:	3c048006 */ 	lui	$a0,0x8006
/*  f01ea48:	8c8428a0 */ 	lw	$a0,0x28a0($a0)
/*  f01ea4c:	2c810002 */ 	sltiu	$at,$a0,0x2
/*  f01ea50:	10200006 */ 	beqz	$at,.JF0f01ea6c
/*  f01ea54:	00000000 */ 	nop
/*  f01ea58:	0fc5bb09 */ 	jal	langSetJpnEnabled
/*  f01ea5c:	00000000 */ 	nop
/*  f01ea60:	240e0063 */ 	li	$t6,0x63
/*  f01ea64:	3c018006 */ 	lui	$at,0x8006
/*  f01ea68:	ac2e28a0 */ 	sw	$t6,0x28a0($at)
.JF0f01ea6c:
/*  f01ea6c:	3c06800a */ 	lui	$a2,0x800a
/*  f01ea70:	8cc6d140 */ 	lw	$a2,-0x2ec0($a2)
/*  f01ea74:	00001825 */ 	move	$v1,$zero
/*  f01ea78:	00002025 */ 	move	$a0,$zero
/*  f01ea7c:	18c00013 */ 	blez	$a2,.JF0f01eacc
/*  f01ea80:	3c07800b */ 	lui	$a3,0x800b
/*  f01ea84:	24e7b5a8 */ 	addiu	$a3,$a3,-19032
.JF0f01ea88:
/*  f01ea88:	8cef0000 */ 	lw	$t7,0x0($a3)
/*  f01ea8c:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f01ea90:	01e41021 */ 	addu	$v0,$t7,$a0
/*  f01ea94:	94450000 */ 	lhu	$a1,0x0($v0)
/*  f01ea98:	0005c382 */ 	srl	$t8,$a1,0xe
/*  f01ea9c:	13000008 */ 	beqz	$t8,.JF0f01eac0
/*  f01eaa0:	2719ffff */ 	addiu	$t9,$t8,-1
/*  f01eaa4:	904a0000 */ 	lbu	$t2,0x0($v0)
/*  f01eaa8:	00194980 */ 	sll	$t1,$t9,0x6
/*  f01eaac:	3c06800a */ 	lui	$a2,0x800a
/*  f01eab0:	314bff3f */ 	andi	$t3,$t2,0xff3f
/*  f01eab4:	012b6025 */ 	or	$t4,$t1,$t3
/*  f01eab8:	a04c0000 */ 	sb	$t4,0x0($v0)
/*  f01eabc:	8cc6d140 */ 	lw	$a2,-0x2ec0($a2)
.JF0f01eac0:
/*  f01eac0:	0066082a */ 	slt	$at,$v1,$a2
/*  f01eac4:	1420fff0 */ 	bnez	$at,.JF0f01ea88
/*  f01eac8:	24840002 */ 	addiu	$a0,$a0,0x2
.JF0f01eacc:
/*  f01eacc:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f01ead0:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f01ead4:	03e00008 */ 	jr	$ra
/*  f01ead8:	00000000 */ 	nop
/*  f01eadc:	00000000 */ 	nop
);
#elif VERSION >= VERSION_PAL_FINAL
const char var7f1a9880pf[] = "language";

GLOBAL_ASM(
glabel func0f01d860
/*  f01d930:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f01d934:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f01d938:	3c047f1b */ 	lui	$a0,0x7f1b
/*  f01d93c:	3c058006 */ 	lui	$a1,0x8006
/*  f01d940:	24a52630 */ 	addiu	$a1,$a1,0x2630
/*  f01d944:	0c003624 */ 	jal	mainOverrideVariable
/*  f01d948:	24849880 */ 	addiu	$a0,$a0,-26496
/*  f01d94c:	3c048006 */ 	lui	$a0,0x8006
/*  f01d950:	8c842630 */ 	lw	$a0,0x2630($a0)
/*  f01d954:	2c810005 */ 	sltiu	$at,$a0,0x5
/*  f01d958:	10200006 */ 	beqz	$at,.PF0f01d974
/*  f01d95c:	00000000 */ 	nop
/*  f01d960:	0fc5bdd7 */ 	jal	lang0f16f75c
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
);
#elif VERSION >= VERSION_PAL_BETA
const char var7f1aa330[] = "language";

GLOBAL_ASM(
glabel func0f01d860
/*  f01d8d0:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f01d8d4:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f01d8d8:	3c047f1b */ 	lui	$a0,0x7f1b
/*  f01d8dc:	3c058006 */ 	lui	$a1,0x8006
/*  f01d8e0:	24a54020 */ 	addiu	$a1,$a1,0x4020
/*  f01d8e4:	0c003648 */ 	jal	mainOverrideVariable
/*  f01d8e8:	2484a330 */ 	addiu	$a0,$a0,-23760
/*  f01d8ec:	3c048006 */ 	lui	$a0,0x8006
/*  f01d8f0:	8c844020 */ 	lw	$a0,0x4020($a0)
/*  f01d8f4:	2c810005 */ 	sltiu	$at,$a0,0x5
/*  f01d8f8:	10200006 */ 	beqz	$at,.PB0f01d914
/*  f01d8fc:	00000000 */ 	nop
/*  f01d900:	0fc5c097 */ 	jal	lang0f16f75c
/*  f01d904:	00000000 */ 	nop
/*  f01d908:	240e0063 */ 	li	$t6,0x63
/*  f01d90c:	3c018006 */ 	lui	$at,0x8006
/*  f01d910:	ac2e4020 */ 	sw	$t6,0x4020($at)
.PB0f01d914:
/*  f01d914:	3c0f8008 */ 	lui	$t7,0x8008
/*  f01d918:	8def65f0 */ 	lw	$t7,0x65f0($t7)
/*  f01d91c:	00001025 */ 	move	$v0,$zero
/*  f01d920:	240600f8 */ 	li	$a2,0xf8
/*  f01d924:	11e00011 */ 	beqz	$t7,.PB0f01d96c
/*  f01d928:	3c05800b */ 	lui	$a1,0x800b
/*  f01d92c:	24a5f1d8 */ 	addiu	$a1,$a1,-3624
/*  f01d930:	8cb80000 */ 	lw	$t8,0x0($a1)
.PB0f01d934:
/*  f01d934:	03021821 */ 	addu	$v1,$t8,$v0
/*  f01d938:	94640000 */ 	lhu	$a0,0x0($v1)
/*  f01d93c:	24420002 */ 	addiu	$v0,$v0,0x2
/*  f01d940:	0004cb82 */ 	srl	$t9,$a0,0xe
/*  f01d944:	13200007 */ 	beqz	$t9,.PB0f01d964
/*  f01d948:	00000000 */ 	nop
/*  f01d94c:	906b0000 */ 	lbu	$t3,0x0($v1)
/*  f01d950:	2728ffff */ 	addiu	$t0,$t9,-1
/*  f01d954:	00085180 */ 	sll	$t2,$t0,0x6
/*  f01d958:	316cff3f */ 	andi	$t4,$t3,0xff3f
/*  f01d95c:	014c6825 */ 	or	$t5,$t2,$t4
/*  f01d960:	a06d0000 */ 	sb	$t5,0x0($v1)
.PB0f01d964:
/*  f01d964:	5446fff3 */ 	bnel	$v0,$a2,.PB0f01d934
/*  f01d968:	8cb80000 */ 	lw	$t8,0x0($a1)
.PB0f01d96c:
/*  f01d96c:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f01d970:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f01d974:	03e00008 */ 	jr	$ra
/*  f01d978:	00000000 */ 	nop
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
