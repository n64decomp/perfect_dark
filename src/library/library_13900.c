#include <ultra64.h>
#include "types.h"
#include "game/game_115ab0.h"
#include "library/library_04a80.h"
#include "library/library_0d520.h"
#include "library/library_13900.h"
#include "library/library_481e0.h"
#include "library/library_48520.h"
#include "library/library_48650.h"
#include "library/library_488e0.h"
#include "library/library_4a980.h"
#include "library/library_4f350.h"
#include "library/library_4f400.h"
#include "library/library_4f5e0.h"

const char var70054080[] = "joyReset\n";
const char var7005408c[] = "joyReset: doing nothing\n";
const char var700540a8[] = "debugjoy";
const char var700540b4[] = "JOY : g_EnableCyclicPolling=%d";
const char var700540d4[] = "JOY : g_JoyReCheckInterval=%d";
const char var700540f4[] = "JOY : g_JoyReCheckEventIn=%d";
const char var70054114[] = "JOY : g_JoyRecheckDone=%d";
const char var70054130[] = "osContStartReadData -> Failed - CONT_NO_RESPONSE_ERROR\n";
const char var70054168[] = "osContStartReadData -> Failed - CONT_OVERRUN_ERROR\n";
const char var7005419c[] = "joyTickRetrace:joy%derrno%d->%d\n";
const char var700541c0[] = "joyTickRetrace:joy%derrno%d->%d\n";
const u32 var700541e4[] = {0x700156a4};
const u32 var700541e8[] = {0x700156d8};
const u32 var700541ec[] = {0x700157a8};
const u32 var700541f0[] = {0x700157d8};
const u32 var700541f4[] = {0x7001581c};
const u32 var700541f8[] = {0x7001580c};
const u32 var700541fc[] = {0x00000000};

GLOBAL_ASM(
glabel func00013900
/*    13900:	3c0e8006 */ 	lui	$t6,0x8006
/*    13904:	8dceeef0 */ 	lw	$t6,-0x1110($t6)
/*    13908:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*    1390c:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    13910:	51c00006 */ 	beqzl	$t6,.L0001392c
/*    13914:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    13918:	0c00543a */ 	jal	func000150e8
/*    1391c:	00000000 */ 	sll	$zero,$zero,0x0
/*    13920:	3c018006 */ 	lui	$at,0x8006
/*    13924:	ac20eef0 */ 	sw	$zero,-0x1110($at)
/*    13928:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0001392c:
/*    1392c:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*    13930:	03e00008 */ 	jr	$ra
/*    13934:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func00013938
/*    13938:	3c0e8006 */ 	lui	$t6,0x8006
/*    1393c:	8dceeef0 */ 	lw	$t6,-0x1110($t6)
/*    13940:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*    13944:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    13948:	55c00007 */ 	bnezl	$t6,.L00013968
/*    1394c:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    13950:	0c005451 */ 	jal	func00015144
/*    13954:	00000000 */ 	sll	$zero,$zero,0x0
/*    13958:	240f0001 */ 	addiu	$t7,$zero,0x1
/*    1395c:	3c018006 */ 	lui	$at,0x8006
/*    13960:	ac2feef0 */ 	sw	$t7,-0x1110($at)
/*    13964:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L00013968:
/*    13968:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*    1396c:	03e00008 */ 	jr	$ra
/*    13970:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func00013974
/*    13974:	3c018006 */ 	lui	$at,0x8006
/*    13978:	03e00008 */ 	jr	$ra
/*    1397c:	ac24eeec */ 	sw	$a0,-0x1114($at)
);

GLOBAL_ASM(
glabel func00013980
/*    13980:	3c028006 */ 	lui	$v0,0x8006
/*    13984:	03e00008 */ 	jr	$ra
/*    13988:	8c42eeec */ 	lw	$v0,-0x1114($v0)
);

GLOBAL_ASM(
glabel func0001398c
/*    1398c:	00047080 */ 	sll	$t6,$a0,0x2
/*    13990:	01c47023 */ 	subu	$t6,$t6,$a0
/*    13994:	000e7080 */ 	sll	$t6,$t6,0x2
/*    13998:	01c47023 */ 	subu	$t6,$t6,$a0
/*    1399c:	000e7080 */ 	sll	$t6,$t6,0x2
/*    139a0:	01c47023 */ 	subu	$t6,$t6,$a0
/*    139a4:	000e7140 */ 	sll	$t6,$t6,0x5
/*    139a8:	3c028006 */ 	lui	$v0,%hi(var8005eee0)
/*    139ac:	01c47023 */ 	subu	$t6,$t6,$a0
/*    139b0:	2442eee0 */ 	addiu	$v0,$v0,%lo(var8005eee0)
/*    139b4:	000e70c0 */ 	sll	$t6,$t6,0x3
/*    139b8:	ac4e0000 */ 	sw	$t6,0x0($v0)
/*    139bc:	3c018006 */ 	lui	$at,0x8006
/*    139c0:	03e00008 */ 	jr	$ra
/*    139c4:	ac2eeee4 */ 	sw	$t6,-0x111c($at)
);

GLOBAL_ASM(
glabel func000139c8
/*    139c8:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*    139cc:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    139d0:	0c004e63 */ 	jal	func0001398c
/*    139d4:	2404000a */ 	addiu	$a0,$zero,0xa
/*    139d8:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    139dc:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*    139e0:	03e00008 */ 	jr	$ra
/*    139e4:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func000139e8
/*    139e8:	3c068006 */ 	lui	$a2,%hi(var8005eecc)
/*    139ec:	24c6eecc */ 	addiu	$a2,$a2,%lo(var8005eecc)
/*    139f0:	8cc20000 */ 	lw	$v0,0x0($a2)
/*    139f4:	00001825 */ 	or	$v1,$zero,$zero
/*    139f8:	1040000f */ 	beqz	$v0,.L00013a38
/*    139fc:	28410002 */ 	slti	$at,$v0,0x2
/*    13a00:	3c03800a */ 	lui	$v1,0x800a
/*    13a04:	1420000c */ 	bnez	$at,.L00013a38
/*    13a08:	90639f48 */ 	lbu	$v1,-0x60b8($v1)
/*    13a0c:	18400009 */ 	blez	$v0,.L00013a34
/*    13a10:	2458ffff */ 	addiu	$t8,$v0,-1
/*    13a14:	3c0e800a */ 	lui	$t6,0x800a
/*    13a18:	25c49f48 */ 	addiu	$a0,$t6,-24760
/*    13a1c:	00442821 */ 	addu	$a1,$v0,$a0
.L00013a20:
/*    13a20:	908f0001 */ 	lbu	$t7,0x1($a0)
/*    13a24:	24840001 */ 	addiu	$a0,$a0,0x1
/*    13a28:	0085082b */ 	sltu	$at,$a0,$a1
/*    13a2c:	1420fffc */ 	bnez	$at,.L00013a20
/*    13a30:	a08fffff */ 	sb	$t7,-0x1($a0)
.L00013a34:
/*    13a34:	acd80000 */ 	sw	$t8,0x0($a2)
.L00013a38:
/*    13a38:	03e00008 */ 	jr	$ra
/*    13a3c:	00601025 */ 	or	$v0,$v1,$zero
);

GLOBAL_ASM(
glabel func00013a40
/*    13a40:	3c028006 */ 	lui	$v0,0x8006
/*    13a44:	8c42eecc */ 	lw	$v0,-0x1134($v0)
/*    13a48:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*    13a4c:	afa40018 */ 	sw	$a0,0x18($sp)
/*    13a50:	244f0001 */ 	addiu	$t7,$v0,0x1
/*    13a54:	308e00ff */ 	andi	$t6,$a0,0xff
/*    13a58:	29e10064 */ 	slti	$at,$t7,0x64
/*    13a5c:	01c02025 */ 	or	$a0,$t6,$zero
/*    13a60:	14200006 */ 	bnez	$at,.L00013a7c
/*    13a64:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    13a68:	0c004e7a */ 	jal	func000139e8
/*    13a6c:	a3ae001b */ 	sb	$t6,0x1b($sp)
/*    13a70:	3c028006 */ 	lui	$v0,0x8006
/*    13a74:	8c42eecc */ 	lw	$v0,-0x1134($v0)
/*    13a78:	93a4001b */ 	lbu	$a0,0x1b($sp)
.L00013a7c:
/*    13a7c:	10400004 */ 	beqz	$v0,.L00013a90
/*    13a80:	3c18800a */ 	lui	$t8,0x800a
/*    13a84:	0302c021 */ 	addu	$t8,$t8,$v0
/*    13a88:	93189f47 */ 	lbu	$t8,-0x60b9($t8)
/*    13a8c:	10980006 */ 	beq	$a0,$t8,.L00013aa8
.L00013a90:
/*    13a90:	3c01800a */ 	lui	$at,0x800a
/*    13a94:	00220821 */ 	addu	$at,$at,$v0
/*    13a98:	a0249f48 */ 	sb	$a0,-0x60b8($at)
/*    13a9c:	3c018006 */ 	lui	$at,0x8006
/*    13aa0:	24590001 */ 	addiu	$t9,$v0,0x1
/*    13aa4:	ac39eecc */ 	sw	$t9,-0x1134($at)
.L00013aa8:
/*    13aa8:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    13aac:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*    13ab0:	03e00008 */ 	jr	$ra
/*    13ab4:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func00013ab8
/*    13ab8:	3c0e8006 */ 	lui	$t6,0x8006
/*    13abc:	8dceeedc */ 	lw	$t6,-0x1124($t6)
/*    13ac0:	27bdffd0 */ 	addiu	$sp,$sp,-48
/*    13ac4:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    13ac8:	11c0005c */ 	beqz	$t6,.L00013c3c
/*    13acc:	00803825 */ 	or	$a3,$a0,$zero
/*    13ad0:	24010002 */ 	addiu	$at,$zero,0x2
/*    13ad4:	10810010 */ 	beq	$a0,$at,.L00013b18
/*    13ad8:	3c0f8006 */ 	lui	$t7,0x8006
/*    13adc:	8defeee0 */ 	lw	$t7,-0x1120($t7)
/*    13ae0:	51e00057 */ 	beqzl	$t7,.L00013c40
/*    13ae4:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    13ae8:	1480000b */ 	bnez	$a0,.L00013b18
/*    13aec:	3c188006 */ 	lui	$t8,0x8006
/*    13af0:	8f18eebc */ 	lw	$t8,-0x1144($t8)
/*    13af4:	3c198006 */ 	lui	$t9,0x8006
/*    13af8:	3c088006 */ 	lui	$t0,0x8006
/*    13afc:	13000004 */ 	beqz	$t8,.L00013b10
/*    13b00:	00000000 */ 	sll	$zero,$zero,0x0
/*    13b04:	8f39eef0 */ 	lw	$t9,-0x1110($t9)
/*    13b08:	5720004d */ 	bnezl	$t9,.L00013c40
/*    13b0c:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L00013b10:
/*    13b10:	8d08eeec */ 	lw	$t0,-0x1114($t0)
/*    13b14:	11000049 */ 	beqz	$t0,.L00013c3c
.L00013b18:
/*    13b18:	3c098006 */ 	lui	$t1,0x8006
/*    13b1c:	8d29eefc */ 	lw	$t1,-0x1104($t1)
/*    13b20:	240a0001 */ 	addiu	$t2,$zero,0x1
/*    13b24:	3c018006 */ 	lui	$at,0x8006
/*    13b28:	15200044 */ 	bnez	$t1,.L00013c3c
/*    13b2c:	3c0b8006 */ 	lui	$t3,0x8006
/*    13b30:	8d6beef4 */ 	lw	$t3,-0x110c($t3)
/*    13b34:	ac2aeefc */ 	sw	$t2,-0x1104($at)
/*    13b38:	3c018006 */ 	lui	$at,0x8006
/*    13b3c:	afa70030 */ 	sw	$a3,0x30($sp)
/*    13b40:	0c012144 */ 	jal	func00048510
/*    13b44:	ac2beef8 */ 	sw	$t3,-0x1108($at)
/*    13b48:	3c0c8006 */ 	lui	$t4,0x8006
/*    13b4c:	8d8ceef8 */ 	lw	$t4,-0x1108($t4)
/*    13b50:	3c068006 */ 	lui	$a2,0x8006
/*    13b54:	8cc6eee0 */ 	lw	$a2,-0x1120($a2)
/*    13b58:	3c018006 */ 	lui	$at,0x8006
/*    13b5c:	004c1823 */ 	subu	$v1,$v0,$t4
/*    13b60:	ac22eef4 */ 	sw	$v0,-0x110c($at)
/*    13b64:	00032202 */ 	srl	$a0,$v1,0x8
/*    13b68:	00062840 */ 	sll	$a1,$a2,0x1
/*    13b6c:	00a4082b */ 	sltu	$at,$a1,$a0
/*    13b70:	10200002 */ 	beqz	$at,.L00013b7c
/*    13b74:	8fa70030 */ 	lw	$a3,0x30($sp)
/*    13b78:	00a02025 */ 	or	$a0,$a1,$zero
.L00013b7c:
/*    13b7c:	3c038006 */ 	lui	$v1,%hi(var8005eee4)
/*    13b80:	2463eee4 */ 	addiu	$v1,$v1,%lo(var8005eee4)
/*    13b84:	8c6e0000 */ 	lw	$t6,0x0($v1)
/*    13b88:	24010002 */ 	addiu	$at,$zero,0x2
/*    13b8c:	3c028006 */ 	lui	$v0,%hi(var8005eee8)
/*    13b90:	01c47823 */ 	subu	$t7,$t6,$a0
/*    13b94:	05e00009 */ 	bltz	$t7,.L00013bbc
/*    13b98:	ac6f0000 */ 	sw	$t7,0x0($v1)
/*    13b9c:	10e10007 */ 	beq	$a3,$at,.L00013bbc
/*    13ba0:	24010001 */ 	addiu	$at,$zero,0x1
/*    13ba4:	14e10023 */ 	bne	$a3,$at,.L00013c34
/*    13ba8:	00000000 */ 	sll	$zero,$zero,0x0
/*    13bac:	05e10021 */ 	bgez	$t7,.L00013c34
/*    13bb0:	000fc023 */ 	negu	$t8,$t7
/*    13bb4:	00d8082a */ 	slt	$at,$a2,$t8
/*    13bb8:	1020001e */ 	beqz	$at,.L00013c34
.L00013bbc:
/*    13bbc:	2442eee8 */ 	addiu	$v0,$v0,%lo(var8005eee8)
/*    13bc0:	8c590000 */ 	lw	$t9,0x0($v0)
/*    13bc4:	a3a00027 */ 	sb	$zero,0x27($sp)
/*    13bc8:	27280001 */ 	addiu	$t0,$t9,0x1
/*    13bcc:	10e00004 */ 	beqz	$a3,.L00013be0
/*    13bd0:	ac480000 */ 	sw	$t0,0x0($v0)
/*    13bd4:	0c00543a */ 	jal	func000150e8
/*    13bd8:	afa70030 */ 	sw	$a3,0x30($sp)
/*    13bdc:	8fa70030 */ 	lw	$a3,0x30($sp)
.L00013be0:
/*    13be0:	3c04800a */ 	lui	$a0,%hi(var80099e78)
/*    13be4:	24849e78 */ 	addiu	$a0,$a0,%lo(var80099e78)
/*    13be8:	27a50027 */ 	addiu	$a1,$sp,0x27
/*    13bec:	0c0015dc */ 	jal	func00005770
/*    13bf0:	afa70030 */ 	sw	$a3,0x30($sp)
/*    13bf4:	8fa70030 */ 	lw	$a3,0x30($sp)
/*    13bf8:	50e00005 */ 	beqzl	$a3,.L00013c10
/*    13bfc:	93a40027 */ 	lbu	$a0,0x27($sp)
/*    13c00:	0c005451 */ 	jal	func00015144
/*    13c04:	afa70030 */ 	sw	$a3,0x30($sp)
/*    13c08:	8fa70030 */ 	lw	$a3,0x30($sp)
/*    13c0c:	93a40027 */ 	lbu	$a0,0x27($sp)
.L00013c10:
/*    13c10:	afa70030 */ 	sw	$a3,0x30($sp)
/*    13c14:	34890010 */ 	ori	$t1,$a0,0x10
/*    13c18:	312400ff */ 	andi	$a0,$t1,0xff
/*    13c1c:	0c004e90 */ 	jal	func00013a40
/*    13c20:	a3a40027 */ 	sb	$a0,0x27($sp)
/*    13c24:	3c0b8006 */ 	lui	$t3,0x8006
/*    13c28:	8d6beee0 */ 	lw	$t3,-0x1120($t3)
/*    13c2c:	3c018006 */ 	lui	$at,0x8006
/*    13c30:	ac2beee4 */ 	sw	$t3,-0x111c($at)
.L00013c34:
/*    13c34:	3c018006 */ 	lui	$at,0x8006
/*    13c38:	ac20eefc */ 	sw	$zero,-0x1104($at)
.L00013c3c:
/*    13c3c:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L00013c40:
/*    13c40:	27bd0030 */ 	addiu	$sp,$sp,0x30
/*    13c44:	03e00008 */ 	jr	$ra
/*    13c48:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func00013c4c
/*    13c4c:	00042e00 */ 	sll	$a1,$a0,0x18
/*    13c50:	3c0f8006 */ 	lui	$t7,0x8006
/*    13c54:	91efeed8 */ 	lbu	$t7,-0x1128($t7)
/*    13c58:	00057603 */ 	sra	$t6,$a1,0x18
/*    13c5c:	24180001 */ 	addiu	$t8,$zero,0x1
/*    13c60:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*    13c64:	01d8c804 */ 	sllv	$t9,$t8,$t6
/*    13c68:	afa40018 */ 	sw	$a0,0x18($sp)
/*    13c6c:	03204027 */ 	nor	$t0,$t9,$zero
/*    13c70:	01e82024 */ 	and	$a0,$t7,$t0
/*    13c74:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    13c78:	308900ff */ 	andi	$t1,$a0,0xff
/*    13c7c:	0c004e90 */ 	jal	func00013a40
/*    13c80:	01202025 */ 	or	$a0,$t1,$zero
/*    13c84:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    13c88:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*    13c8c:	03e00008 */ 	jr	$ra
/*    13c90:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func00013c94
/*    13c94:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*    13c98:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    13c9c:	3c04800a */ 	lui	$a0,%hi(var80099ec0)
/*    13ca0:	3c05800a */ 	lui	$a1,%hi(var80099eb8)
/*    13ca4:	24a59eb8 */ 	addiu	$a1,$a1,%lo(var80099eb8)
/*    13ca8:	24849ec0 */ 	addiu	$a0,$a0,%lo(var80099ec0)
/*    13cac:	0c0120d0 */ 	jal	func00048340
/*    13cb0:	24060001 */ 	addiu	$a2,$zero,0x1
/*    13cb4:	3c04800a */ 	lui	$a0,%hi(var80099ee0)
/*    13cb8:	3c05800a */ 	lui	$a1,%hi(var80099ed8)
/*    13cbc:	24a59ed8 */ 	addiu	$a1,$a1,%lo(var80099ed8)
/*    13cc0:	24849ee0 */ 	addiu	$a0,$a0,%lo(var80099ee0)
/*    13cc4:	0c0120d0 */ 	jal	func00048340
/*    13cc8:	24060001 */ 	addiu	$a2,$zero,0x1
/*    13ccc:	3c04800a */ 	lui	$a0,%hi(var80099f00)
/*    13cd0:	3c05800a */ 	lui	$a1,%hi(var80099ef8)
/*    13cd4:	24a59ef8 */ 	addiu	$a1,$a1,%lo(var80099ef8)
/*    13cd8:	24849f00 */ 	addiu	$a0,$a0,%lo(var80099f00)
/*    13cdc:	0c0120d0 */ 	jal	func00048340
/*    13ce0:	24060001 */ 	addiu	$a2,$zero,0x1
/*    13ce4:	3c04800a */ 	lui	$a0,%hi(var80099f20)
/*    13ce8:	3c05800a */ 	lui	$a1,%hi(var80099f18)
/*    13cec:	24a59f18 */ 	addiu	$a1,$a1,%lo(var80099f18)
/*    13cf0:	24849f20 */ 	addiu	$a0,$a0,%lo(var80099f20)
/*    13cf4:	0c0120d0 */ 	jal	func00048340
/*    13cf8:	24060001 */ 	addiu	$a2,$zero,0x1
/*    13cfc:	3c04800a */ 	lui	$a0,%hi(var80099e78)
/*    13d00:	3c05800a */ 	lui	$a1,%hi(var80099e90)
/*    13d04:	24a59e90 */ 	addiu	$a1,$a1,%lo(var80099e90)
/*    13d08:	24849e78 */ 	addiu	$a0,$a0,%lo(var80099e78)
/*    13d0c:	0c0120d0 */ 	jal	func00048340
/*    13d10:	2406000a */ 	addiu	$a2,$zero,0xa
/*    13d14:	3c05800a */ 	lui	$a1,%hi(var80099e78)
/*    13d18:	24a59e78 */ 	addiu	$a1,$a1,%lo(var80099e78)
/*    13d1c:	24040005 */ 	addiu	$a0,$zero,0x5
/*    13d20:	0c012148 */ 	jal	func00048520
/*    13d24:	00003025 */ 	or	$a2,$zero,$zero
/*    13d28:	240e0001 */ 	addiu	$t6,$zero,0x1
/*    13d2c:	3c018006 */ 	lui	$at,0x8006
/*    13d30:	ac2eeeb0 */ 	sw	$t6,-0x1150($at)
/*    13d34:	3c018006 */ 	lui	$at,0x8006
/*    13d38:	ac20eec4 */ 	sw	$zero,-0x113c($at)
/*    13d3c:	3c0f800a */ 	lui	$t7,0x800a
/*    13d40:	3c018006 */ 	lui	$at,0x8006
/*    13d44:	25e69a60 */ 	addiu	$a2,$t7,-26016
/*    13d48:	3c08800a */ 	lui	$t0,%hi(var80099e68)
/*    13d4c:	ac20eec8 */ 	sw	$zero,-0x1138($at)
/*    13d50:	25089e68 */ 	addiu	$t0,$t0,%lo(var80099e68)
/*    13d54:	00c02825 */ 	or	$a1,$a2,$zero
/*    13d58:	2407ffff */ 	addiu	$a3,$zero,-1
/*    13d5c:	24040004 */ 	addiu	$a0,$zero,0x4
.L00013d60:
/*    13d60:	aca001e0 */ 	sw	$zero,0x1e0($a1)
/*    13d64:	aca001e4 */ 	sw	$zero,0x1e4($a1)
/*    13d68:	aca001e8 */ 	sw	$zero,0x1e8($a1)
/*    13d6c:	aca001ec */ 	sw	$zero,0x1ec($a1)
/*    13d70:	aca70200 */ 	sw	$a3,0x200($a1)
/*    13d74:	00001825 */ 	or	$v1,$zero,$zero
/*    13d78:	00c01025 */ 	or	$v0,$a2,$zero
.L00013d7c:
/*    13d7c:	24630001 */ 	addiu	$v1,$v1,0x1
/*    13d80:	24420006 */ 	addiu	$v0,$v0,0x6
/*    13d84:	a440fffa */ 	sh	$zero,-0x6($v0)
/*    13d88:	a040fffc */ 	sb	$zero,-0x4($v0)
/*    13d8c:	a040fffd */ 	sb	$zero,-0x3($v0)
/*    13d90:	1464fffa */ 	bne	$v1,$a0,.L00013d7c
/*    13d94:	a040fffe */ 	sb	$zero,-0x2($v0)
/*    13d98:	24c60204 */ 	addiu	$a2,$a2,0x204
/*    13d9c:	00c8082b */ 	sltu	$at,$a2,$t0
/*    13da0:	1420ffef */ 	bnez	$at,.L00013d60
/*    13da4:	24a50204 */ 	addiu	$a1,$a1,0x204
/*    13da8:	3c02800a */ 	lui	$v0,%hi(var80099e68)
/*    13dac:	3c03800a */ 	lui	$v1,%hi(var80099e78)
/*    13db0:	24639e78 */ 	addiu	$v1,$v1,%lo(var80099e78)
/*    13db4:	24429e68 */ 	addiu	$v0,$v0,%lo(var80099e68)
.L00013db8:
/*    13db8:	24420004 */ 	addiu	$v0,$v0,0x4
/*    13dbc:	1443fffe */ 	bne	$v0,$v1,.L00013db8
/*    13dc0:	ac40fffc */ 	sw	$zero,-0x4($v0)
/*    13dc4:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    13dc8:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*    13dcc:	03e00008 */ 	jr	$ra
/*    13dd0:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func00013dd4
/*    13dd4:	3c03800a */ 	lui	$v1,%hi(var80099e68)
/*    13dd8:	3c04800a */ 	lui	$a0,%hi(var80099e78)
/*    13ddc:	24849e78 */ 	addiu	$a0,$a0,%lo(var80099e78)
/*    13de0:	24639e68 */ 	addiu	$v1,$v1,%lo(var80099e68)
/*    13de4:	2402003c */ 	addiu	$v0,$zero,0x3c
.L00013de8:
/*    13de8:	24630004 */ 	addiu	$v1,$v1,0x4
/*    13dec:	1464fffe */ 	bne	$v1,$a0,.L00013de8
/*    13df0:	ac62fffc */ 	sw	$v0,-0x4($v1)
/*    13df4:	03e00008 */ 	jr	$ra
/*    13df8:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func00013dfc
/*    13dfc:	3c0e8006 */ 	lui	$t6,0x8006
/*    13e00:	8dceeeb0 */ 	lw	$t6,-0x1150($t6)
/*    13e04:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*    13e08:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    13e0c:	11c00019 */ 	beqz	$t6,.L00013e74
/*    13e10:	3c04800a */ 	lui	$a0,%hi(var80099ec0)
/*    13e14:	24849ec0 */ 	addiu	$a0,$a0,%lo(var80099ec0)
/*    13e18:	27a5001c */ 	addiu	$a1,$sp,0x1c
/*    13e1c:	0c012238 */ 	jal	func000488e0
/*    13e20:	00003025 */ 	or	$a2,$zero,$zero
/*    13e24:	3c04800a */ 	lui	$a0,%hi(var80099ee0)
/*    13e28:	24849ee0 */ 	addiu	$a0,$a0,%lo(var80099ee0)
/*    13e2c:	27a5001c */ 	addiu	$a1,$sp,0x1c
/*    13e30:	0c0121bc */ 	jal	func000486f0
/*    13e34:	24060001 */ 	addiu	$a2,$zero,0x1
/*    13e38:	0c004fa1 */ 	jal	func00013e84
/*    13e3c:	00000000 */ 	sll	$zero,$zero,0x0
/*    13e40:	3c04800a */ 	lui	$a0,%hi(var80099f00)
/*    13e44:	24849f00 */ 	addiu	$a0,$a0,%lo(var80099f00)
/*    13e48:	27a5001c */ 	addiu	$a1,$sp,0x1c
/*    13e4c:	0c012238 */ 	jal	func000488e0
/*    13e50:	00003025 */ 	or	$a2,$zero,$zero
/*    13e54:	3c04800a */ 	lui	$a0,%hi(var80099f20)
/*    13e58:	24849f20 */ 	addiu	$a0,$a0,%lo(var80099f20)
/*    13e5c:	27a5001c */ 	addiu	$a1,$sp,0x1c
/*    13e60:	0c0121bc */ 	jal	func000486f0
/*    13e64:	24060001 */ 	addiu	$a2,$zero,0x1
/*    13e68:	240f0001 */ 	addiu	$t7,$zero,0x1
/*    13e6c:	3c018006 */ 	lui	$at,0x8006
/*    13e70:	ac2feec0 */ 	sw	$t7,-0x1140($at)
.L00013e74:
/*    13e74:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    13e78:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*    13e7c:	03e00008 */ 	jr	$ra
/*    13e80:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func00013e84
/*    13e84:	3c028006 */ 	lui	$v0,%hi(var8005eeb8)
/*    13e88:	2442eeb8 */ 	addiu	$v0,$v0,%lo(var8005eeb8)
/*    13e8c:	8c4e0000 */ 	lw	$t6,0x0($v0)
/*    13e90:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*    13e94:	afbf001c */ 	sw	$ra,0x1c($sp)
/*    13e98:	afb10018 */ 	sw	$s1,0x18($sp)
/*    13e9c:	11c00018 */ 	beqz	$t6,.L00013f00
/*    13ea0:	afb00014 */ 	sw	$s0,0x14($sp)
/*    13ea4:	3c11800a */ 	lui	$s1,0x800a
/*    13ea8:	3c058006 */ 	lui	$a1,%hi(var8005eeac)
/*    13eac:	3c06800a */ 	lui	$a2,%hi(var80099f38)
/*    13eb0:	26249e78 */ 	addiu	$a0,$s1,-24968
/*    13eb4:	ac400000 */ 	sw	$zero,0x0($v0)
/*    13eb8:	24c69f38 */ 	addiu	$a2,$a2,%lo(var80099f38)
/*    13ebc:	0c012a60 */ 	jal	func0004a980
/*    13ec0:	24a5eeac */ 	addiu	$a1,$a1,%lo(var8005eeac)
/*    13ec4:	240f0001 */ 	addiu	$t7,$zero,0x1
/*    13ec8:	3c018006 */ 	lui	$at,0x8006
/*    13ecc:	ac2feeb4 */ 	sw	$t7,-0x114c($at)
/*    13ed0:	00008025 */ 	or	$s0,$zero,$zero
/*    13ed4:	24110004 */ 	addiu	$s1,$zero,0x4
/*    13ed8:	00102600 */ 	sll	$a0,$s0,0x18
.L00013edc:
/*    13edc:	0004c603 */ 	sra	$t8,$a0,0x18
/*    13ee0:	03002025 */ 	or	$a0,$t8,$zero
/*    13ee4:	0c0054f1 */ 	jal	func000153c4
/*    13ee8:	00002825 */ 	or	$a1,$zero,$zero
/*    13eec:	26100001 */ 	addiu	$s0,$s0,0x1
/*    13ef0:	5611fffa */ 	bnel	$s0,$s1,.L00013edc
/*    13ef4:	00102600 */ 	sll	$a0,$s0,0x18
/*    13ef8:	1000001d */ 	beqz	$zero,.L00013f70
/*    13efc:	00000000 */ 	sll	$zero,$zero,0x0
.L00013f00:
/*    13f00:	3c11800a */ 	lui	$s1,%hi(var80099e78)
/*    13f04:	26319e78 */ 	addiu	$s1,$s1,%lo(var80099e78)
/*    13f08:	2410000f */ 	addiu	$s0,$zero,0xf
/*    13f0c:	0c013cd4 */ 	jal	func0004f350
/*    13f10:	02202025 */ 	or	$a0,$s1,$zero
/*    13f14:	02202025 */ 	or	$a0,$s1,$zero
/*    13f18:	00002825 */ 	or	$a1,$zero,$zero
/*    13f1c:	0c0121bc */ 	jal	func000486f0
/*    13f20:	24060001 */ 	addiu	$a2,$zero,0x1
/*    13f24:	3c04800a */ 	lui	$a0,%hi(var80099f38)
/*    13f28:	0c013cf5 */ 	jal	func0004f3d4
/*    13f2c:	24849f38 */ 	addiu	$a0,$a0,%lo(var80099f38)
/*    13f30:	3c03800a */ 	lui	$v1,%hi(var80099f38)
/*    13f34:	24639f38 */ 	addiu	$v1,$v1,%lo(var80099f38)
/*    13f38:	00001025 */ 	or	$v0,$zero,$zero
/*    13f3c:	24110004 */ 	addiu	$s1,$zero,0x4
.L00013f40:
/*    13f40:	90790003 */ 	lbu	$t9,0x3($v1)
/*    13f44:	24090001 */ 	addiu	$t1,$zero,0x1
/*    13f48:	00495004 */ 	sllv	$t2,$t1,$v0
/*    13f4c:	33280008 */ 	andi	$t0,$t9,0x8
/*    13f50:	51000003 */ 	beqzl	$t0,.L00013f60
/*    13f54:	24420001 */ 	addiu	$v0,$v0,0x1
/*    13f58:	020a8023 */ 	subu	$s0,$s0,$t2
/*    13f5c:	24420001 */ 	addiu	$v0,$v0,0x1
.L00013f60:
/*    13f60:	1451fff7 */ 	bne	$v0,$s1,.L00013f40
/*    13f64:	24630004 */ 	addiu	$v1,$v1,0x4
/*    13f68:	3c018006 */ 	lui	$at,0x8006
/*    13f6c:	a030eeac */ 	sb	$s0,-0x1154($at)
.L00013f70:
/*    13f70:	3c068006 */ 	lui	$a2,0x8006
/*    13f74:	3c0b8006 */ 	lui	$t3,0x8006
/*    13f78:	916bef00 */ 	lbu	$t3,-0x1100($t3)
/*    13f7c:	90c6eeac */ 	lbu	$a2,-0x1154($a2)
/*    13f80:	00001025 */ 	or	$v0,$zero,$zero
/*    13f84:	00001825 */ 	or	$v1,$zero,$zero
/*    13f88:	10cb000f */ 	beq	$a2,$t3,.L00013fc8
/*    13f8c:	00c02025 */ 	or	$a0,$a2,$zero
/*    13f90:	3c05800a */ 	lui	$a1,%hi(g_Vars)
/*    13f94:	24a59fc0 */ 	addiu	$a1,$a1,%lo(g_Vars)
/*    13f98:	240c0001 */ 	addiu	$t4,$zero,0x1
.L00013f9c:
/*    13f9c:	004c6804 */ 	sllv	$t5,$t4,$v0
/*    13fa0:	008d7024 */ 	and	$t6,$a0,$t5
/*    13fa4:	11c00003 */ 	beqz	$t6,.L00013fb4
/*    13fa8:	00a37821 */ 	addu	$t7,$a1,$v1
/*    13fac:	a1e204dc */ 	sb	$v0,0x4dc($t7)
/*    13fb0:	24630001 */ 	addiu	$v1,$v1,0x1
.L00013fb4:
/*    13fb4:	24420001 */ 	addiu	$v0,$v0,0x1
/*    13fb8:	5451fff8 */ 	bnel	$v0,$s1,.L00013f9c
/*    13fbc:	240c0001 */ 	addiu	$t4,$zero,0x1
/*    13fc0:	3c018006 */ 	lui	$at,0x8006
/*    13fc4:	a026ef00 */ 	sb	$a2,-0x1100($at)
.L00013fc8:
/*    13fc8:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*    13fcc:	8fb00014 */ 	lw	$s0,0x14($sp)
/*    13fd0:	8fb10018 */ 	lw	$s1,0x18($sp)
/*    13fd4:	03e00008 */ 	jr	$ra
/*    13fd8:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*    13fdc:	3c0e8006 */ 	lui	$t6,0x8006
/*    13fe0:	8dceee60 */ 	lw	$t6,-0x11a0($t6)
/*    13fe4:	3c028006 */ 	lui	$v0,0x8006
/*    13fe8:	24040004 */ 	addiu	$a0,$zero,0x4
/*    13fec:	8dc30200 */ 	lw	$v1,0x200($t6)
/*    13ff0:	04620006 */ 	bltzl	$v1,.L0001400c
/*    13ff4:	00001825 */ 	or	$v1,$zero,$zero
/*    13ff8:	00031600 */ 	sll	$v0,$v1,0x18
/*    13ffc:	00027e03 */ 	sra	$t7,$v0,0x18
/*    14000:	03e00008 */ 	jr	$ra
/*    14004:	01e01025 */ 	or	$v0,$t7,$zero
/*    14008:	00001825 */ 	or	$v1,$zero,$zero
.L0001400c:
/*    1400c:	9042eeac */ 	lbu	$v0,-0x1154($v0)
/*    14010:	24180001 */ 	addiu	$t8,$zero,0x1
.L00014014:
/*    14014:	0078c804 */ 	sllv	$t9,$t8,$v1
/*    14018:	00594024 */ 	and	$t0,$v0,$t9
/*    1401c:	55000006 */ 	bnezl	$t0,.L00014038
/*    14020:	24630001 */ 	addiu	$v1,$v1,0x1
/*    14024:	00031600 */ 	sll	$v0,$v1,0x18
/*    14028:	00024e03 */ 	sra	$t1,$v0,0x18
/*    1402c:	03e00008 */ 	jr	$ra
/*    14030:	01201025 */ 	or	$v0,$t1,$zero
/*    14034:	24630001 */ 	addiu	$v1,$v1,0x1
.L00014038:
/*    14038:	5464fff6 */ 	bnel	$v1,$a0,.L00014014
/*    1403c:	24180001 */ 	addiu	$t8,$zero,0x1
/*    14040:	24020004 */ 	addiu	$v0,$zero,0x4
/*    14044:	03e00008 */ 	jr	$ra
/*    14048:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0001404c
/*    1404c:	3c028006 */ 	lui	$v0,0x8006
/*    14050:	03e00008 */ 	jr	$ra
/*    14054:	9042eeac */ 	lbu	$v0,-0x1154($v0)
);

GLOBAL_ASM(
glabel func00014058
/*    14058:	27bdfff8 */ 	addiu	$sp,$sp,-8
/*    1405c:	afb00004 */ 	sw	$s0,0x4($sp)
/*    14060:	8c8e01e0 */ 	lw	$t6,0x1e0($a0)
/*    14064:	8c8f01e8 */ 	lw	$t7,0x1e8($a0)
/*    14068:	24100014 */ 	addiu	$s0,$zero,0x14
/*    1406c:	00001025 */ 	or	$v0,$zero,$zero
/*    14070:	ac8e01e4 */ 	sw	$t6,0x1e4($a0)
/*    14074:	ac8f01e0 */ 	sw	$t7,0x1e0($a0)
/*    14078:	0002c040 */ 	sll	$t8,$v0,0x1
.L0001407c:
/*    1407c:	00981821 */ 	addu	$v1,$a0,$t8
/*    14080:	a46001f0 */ 	sh	$zero,0x1f0($v1)
/*    14084:	a46001f8 */ 	sh	$zero,0x1f8($v1)
/*    14088:	8c9901e0 */ 	lw	$t9,0x1e0($a0)
/*    1408c:	8c8501e4 */ 	lw	$a1,0x1e4($a0)
/*    14090:	3c18800a */ 	lui	$t8,%hi(var80099e68)
/*    14094:	27189e68 */ 	addiu	$t8,$t8,%lo(var80099e68)
/*    14098:	10b9005e */ 	beq	$a1,$t9,.L00014214
/*    1409c:	24ae0001 */ 	addiu	$t6,$a1,0x1
/*    140a0:	01d0001a */ 	div	$zero,$t6,$s0
/*    140a4:	00023880 */ 	sll	$a3,$v0,0x2
/*    140a8:	00003010 */ 	mfhi	$a2
/*    140ac:	00e23823 */ 	subu	$a3,$a3,$v0
/*    140b0:	00027880 */ 	sll	$t7,$v0,0x2
/*    140b4:	01f86021 */ 	addu	$t4,$t7,$t8
/*    140b8:	00073840 */ 	sll	$a3,$a3,0x1
/*    140bc:	16000002 */ 	bnez	$s0,.L000140c8
/*    140c0:	00000000 */ 	sll	$zero,$zero,0x0
/*    140c4:	0007000d */ 	break	0x7
.L000140c8:
/*    140c8:	2401ffff */ 	addiu	$at,$zero,-1
/*    140cc:	16010004 */ 	bne	$s0,$at,.L000140e0
/*    140d0:	3c018000 */ 	lui	$at,0x8000
/*    140d4:	15c10002 */ 	bne	$t6,$at,.L000140e0
/*    140d8:	00000000 */ 	sll	$zero,$zero,0x0
/*    140dc:	0006000d */ 	break	0x6
.L000140e0:
/*    140e0:	24cf0013 */ 	addiu	$t7,$a2,0x13
.L000140e4:
/*    140e4:	01f0001a */ 	div	$zero,$t7,$s0
/*    140e8:	0006c880 */ 	sll	$t9,$a2,0x2
/*    140ec:	0326c823 */ 	subu	$t9,$t9,$a2
/*    140f0:	0019c8c0 */ 	sll	$t9,$t9,0x3
/*    140f4:	00997021 */ 	addu	$t6,$a0,$t9
/*    140f8:	0000c010 */ 	mfhi	$t8
/*    140fc:	0018c880 */ 	sll	$t9,$t8,0x2
/*    14100:	0338c823 */ 	subu	$t9,$t9,$t8
/*    14104:	01c74021 */ 	addu	$t0,$t6,$a3
/*    14108:	0019c8c0 */ 	sll	$t9,$t9,0x3
/*    1410c:	00997021 */ 	addu	$t6,$a0,$t9
/*    14110:	95050000 */ 	lhu	$a1,0x0($t0)
/*    14114:	16000002 */ 	bnez	$s0,.L00014120
/*    14118:	00000000 */ 	sll	$zero,$zero,0x0
/*    1411c:	0007000d */ 	break	0x7
.L00014120:
/*    14120:	2401ffff */ 	addiu	$at,$zero,-1
/*    14124:	16010004 */ 	bne	$s0,$at,.L00014138
/*    14128:	3c018000 */ 	lui	$at,0x8000
/*    1412c:	15e10002 */ 	bne	$t7,$at,.L00014138
/*    14130:	00000000 */ 	sll	$zero,$zero,0x0
/*    14134:	0006000d */ 	break	0x6
.L00014138:
/*    14138:	01c77821 */ 	addu	$t7,$t6,$a3
/*    1413c:	95e90000 */ 	lhu	$t1,0x0($t7)
/*    14140:	947801f0 */ 	lhu	$t8,0x1f0($v1)
/*    14144:	00a05025 */ 	or	$t2,$a1,$zero
/*    14148:	0120c827 */ 	nor	$t9,$t1,$zero
/*    1414c:	00b97024 */ 	and	$t6,$a1,$t9
/*    14150:	030e7825 */ 	or	$t7,$t8,$t6
/*    14154:	947901f8 */ 	lhu	$t9,0x1f8($v1)
/*    14158:	00a0c027 */ 	nor	$t8,$a1,$zero
/*    1415c:	a46f01f0 */ 	sh	$t7,0x1f0($v1)
/*    14160:	03097024 */ 	and	$t6,$t8,$t1
/*    14164:	032e7825 */ 	or	$t7,$t9,$t6
/*    14168:	a46f01f8 */ 	sh	$t7,0x1f8($v1)
/*    1416c:	8d8d0000 */ 	lw	$t5,0x0($t4)
/*    14170:	01205825 */ 	or	$t3,$t1,$zero
/*    14174:	59a00017 */ 	blezl	$t5,.L000141d4
/*    14178:	8c8e01e0 */ 	lw	$t6,0x1e0($a0)
/*    1417c:	95180000 */ 	lhu	$t8,0x0($t0)
/*    14180:	57000012 */ 	bnezl	$t8,.L000141cc
/*    14184:	25b9ffff */ 	addiu	$t9,$t5,-1
/*    14188:	81050002 */ 	lb	$a1,0x2($t0)
/*    1418c:	28a1000f */ 	slti	$at,$a1,0xf
/*    14190:	5020000e */ 	beqzl	$at,.L000141cc
/*    14194:	25b9ffff */ 	addiu	$t9,$t5,-1
/*    14198:	28a1fff2 */ 	slti	$at,$a1,-14
/*    1419c:	5420000b */ 	bnezl	$at,.L000141cc
/*    141a0:	25b9ffff */ 	addiu	$t9,$t5,-1
/*    141a4:	81050003 */ 	lb	$a1,0x3($t0)
/*    141a8:	28a1000f */ 	slti	$at,$a1,0xf
/*    141ac:	50200007 */ 	beqzl	$at,.L000141cc
/*    141b0:	25b9ffff */ 	addiu	$t9,$t5,-1
/*    141b4:	28a1fff2 */ 	slti	$at,$a1,-14
/*    141b8:	54200004 */ 	bnezl	$at,.L000141cc
/*    141bc:	25b9ffff */ 	addiu	$t9,$t5,-1
/*    141c0:	10000003 */ 	beqz	$zero,.L000141d0
/*    141c4:	ad800000 */ 	sw	$zero,0x0($t4)
/*    141c8:	25b9ffff */ 	addiu	$t9,$t5,-1
.L000141cc:
/*    141cc:	ad990000 */ 	sw	$t9,0x0($t4)
.L000141d0:
/*    141d0:	8c8e01e0 */ 	lw	$t6,0x1e0($a0)
.L000141d4:
/*    141d4:	50ce0010 */ 	beql	$a2,$t6,.L00014218
/*    141d8:	24420001 */ 	addiu	$v0,$v0,0x1
/*    141dc:	24cf0001 */ 	addiu	$t7,$a2,0x1
/*    141e0:	01f0001a */ 	div	$zero,$t7,$s0
/*    141e4:	00003010 */ 	mfhi	$a2
/*    141e8:	16000002 */ 	bnez	$s0,.L000141f4
/*    141ec:	00000000 */ 	sll	$zero,$zero,0x0
/*    141f0:	0007000d */ 	break	0x7
.L000141f4:
/*    141f4:	2401ffff */ 	addiu	$at,$zero,-1
/*    141f8:	16010004 */ 	bne	$s0,$at,.L0001420c
/*    141fc:	3c018000 */ 	lui	$at,0x8000
/*    14200:	15e10002 */ 	bne	$t7,$at,.L0001420c
/*    14204:	00000000 */ 	sll	$zero,$zero,0x0
/*    14208:	0006000d */ 	break	0x6
.L0001420c:
/*    1420c:	1000ffb5 */ 	beqz	$zero,.L000140e4
/*    14210:	24cf0013 */ 	addiu	$t7,$a2,0x13
.L00014214:
/*    14214:	24420001 */ 	addiu	$v0,$v0,0x1
.L00014218:
/*    14218:	0002c600 */ 	sll	$t8,$v0,0x18
/*    1421c:	00181603 */ 	sra	$v0,$t8,0x18
/*    14220:	28410004 */ 	slti	$at,$v0,0x4
/*    14224:	5420ff95 */ 	bnezl	$at,.L0001407c
/*    14228:	0002c040 */ 	sll	$t8,$v0,0x1
/*    1422c:	8fb00004 */ 	lw	$s0,0x4($sp)
/*    14230:	03e00008 */ 	jr	$ra
/*    14234:	27bd0008 */ 	addiu	$sp,$sp,0x8
);

GLOBAL_ASM(
glabel func00014238
/*    14238:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*    1423c:	3c0e8006 */ 	lui	$t6,0x8006
/*    14240:	8dceef04 */ 	lw	$t6,-0x10fc($t6)
/*    14244:	afbf0024 */ 	sw	$ra,0x24($sp)
/*    14248:	afb30020 */ 	sw	$s3,0x20($sp)
/*    1424c:	afb2001c */ 	sw	$s2,0x1c($sp)
/*    14250:	afb10018 */ 	sw	$s1,0x18($sp)
/*    14254:	15c0001f */ 	bnez	$t6,.L000142d4
/*    14258:	afb00014 */ 	sw	$s0,0x14($sp)
/*    1425c:	240f0001 */ 	addiu	$t7,$zero,0x1
/*    14260:	3c018006 */ 	lui	$at,0x8006
/*    14264:	ac2fef04 */ 	sw	$t7,-0x10fc($at)
/*    14268:	00008825 */ 	or	$s1,$zero,$zero
/*    1426c:	24130004 */ 	addiu	$s3,$zero,0x4
/*    14270:	2412000d */ 	addiu	$s2,$zero,0xd
/*    14274:	00118600 */ 	sll	$s0,$s1,0x18
.L00014278:
/*    14278:	0010c603 */ 	sra	$t8,$s0,0x18
/*    1427c:	00182600 */ 	sll	$a0,$t8,0x18
/*    14280:	0004ce03 */ 	sra	$t9,$a0,0x18
/*    14284:	03202025 */ 	or	$a0,$t9,$zero
/*    14288:	0c00557d */ 	jal	func000155f4
/*    1428c:	03008025 */ 	or	$s0,$t8,$zero
/*    14290:	14520005 */ 	bne	$v0,$s2,.L000142a8
/*    14294:	00102600 */ 	sll	$a0,$s0,0x18
/*    14298:	00044603 */ 	sra	$t0,$a0,0x18
/*    1429c:	01002025 */ 	or	$a0,$t0,$zero
/*    142a0:	0fc45b6c */ 	jal	func0f116db0
/*    142a4:	2405000b */ 	addiu	$a1,$zero,0xb
.L000142a8:
/*    142a8:	26310001 */ 	addiu	$s1,$s1,0x1
/*    142ac:	5633fff2 */ 	bnel	$s1,$s3,.L00014278
/*    142b0:	00118600 */ 	sll	$s0,$s1,0x18
/*    142b4:	3c098006 */ 	lui	$t1,0x8006
/*    142b8:	8d29eec4 */ 	lw	$t1,-0x113c($t1)
/*    142bc:	15200003 */ 	bnez	$t1,.L000142cc
/*    142c0:	00000000 */ 	sll	$zero,$zero,0x0
/*    142c4:	0c005587 */ 	jal	func0001561c
/*    142c8:	00000000 */ 	sll	$zero,$zero,0x0
.L000142cc:
/*    142cc:	3c018006 */ 	lui	$at,0x8006
/*    142d0:	ac20ef04 */ 	sw	$zero,-0x10fc($at)
.L000142d4:
/*    142d4:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*    142d8:	8fb00014 */ 	lw	$s0,0x14($sp)
/*    142dc:	8fb10018 */ 	lw	$s1,0x18($sp)
/*    142e0:	8fb2001c */ 	lw	$s2,0x1c($sp)
/*    142e4:	8fb30020 */ 	lw	$s3,0x20($sp)
/*    142e8:	03e00008 */ 	jr	$ra
/*    142ec:	27bd0028 */ 	addiu	$sp,$sp,0x28
);

GLOBAL_ASM(
glabel func000142f0
/*    142f0:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*    142f4:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    142f8:	3c047005 */ 	lui	$a0,%hi(var700540a8)
/*    142fc:	3c058006 */ 	lui	$a1,%hi(var8005ef08)
/*    14300:	24a5ef08 */ 	addiu	$a1,$a1,%lo(var8005ef08)
/*    14304:	0c0036cc */ 	jal	func0000db30
/*    14308:	248440a8 */ 	addiu	$a0,$a0,%lo(var700540a8)
/*    1430c:	3c0e800a */ 	lui	$t6,0x800a
/*    14310:	91cea490 */ 	lbu	$t6,-0x5b70($t6)
/*    14314:	11c00003 */ 	beqz	$t6,.L00014324
/*    14318:	00000000 */ 	sll	$zero,$zero,0x0
/*    1431c:	0c004eae */ 	jal	func00013ab8
/*    14320:	24040001 */ 	addiu	$a0,$zero,0x1
.L00014324:
/*    14324:	3c028006 */ 	lui	$v0,0x8006
/*    14328:	8c42eec4 */ 	lw	$v0,-0x113c($v0)
/*    1432c:	3c04800a */ 	lui	$a0,%hi(var80099c64)
/*    14330:	24849c64 */ 	addiu	$a0,$a0,%lo(var80099c64)
/*    14334:	10400008 */ 	beqz	$v0,.L00014358
/*    14338:	3c05800a */ 	lui	$a1,0x800a
/*    1433c:	0040f809 */ 	jalr	$v0
/*    14340:	8ca59e44 */ 	lw	$a1,-0x61bc($a1)
/*    14344:	3c01800a */ 	lui	$at,0x800a
/*    14348:	3c04800a */ 	lui	$a0,%hi(var80099c64)
/*    1434c:	ac229e4c */ 	sw	$v0,-0x61b4($at)
/*    14350:	0c005016 */ 	jal	func00014058
/*    14354:	24849c64 */ 	addiu	$a0,$a0,%lo(var80099c64)
.L00014358:
/*    14358:	3c04800a */ 	lui	$a0,%hi(var80099a60)
/*    1435c:	0c005016 */ 	jal	func00014058
/*    14360:	24849a60 */ 	addiu	$a0,$a0,%lo(var80099a60)
/*    14364:	3c028006 */ 	lui	$v0,0x8006
/*    14368:	8c42eec8 */ 	lw	$v0,-0x1138($v0)
/*    1436c:	3c04800a */ 	lui	$a0,%hi(var80099a60)
/*    14370:	24849a60 */ 	addiu	$a0,$a0,%lo(var80099a60)
/*    14374:	10400004 */ 	beqz	$v0,.L00014388
/*    14378:	00000000 */ 	sll	$zero,$zero,0x0
/*    1437c:	8c8501e4 */ 	lw	$a1,0x1e4($a0)
/*    14380:	0040f809 */ 	jalr	$v0
/*    14384:	8c8601e0 */ 	lw	$a2,0x1e0($a0)
.L00014388:
/*    14388:	0c005431 */ 	jal	func000150c4
/*    1438c:	00000000 */ 	sll	$zero,$zero,0x0
/*    14390:	10400011 */ 	beqz	$v0,.L000143d8
/*    14394:	3c0f8006 */ 	lui	$t7,0x8006
/*    14398:	8defeec0 */ 	lw	$t7,-0x1140($t7)
/*    1439c:	51e0000f */ 	beqzl	$t7,.L000143dc
/*    143a0:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    143a4:	0c005207 */ 	jal	func0001481c
/*    143a8:	00000000 */ 	sll	$zero,$zero,0x0
/*    143ac:	5c40000b */ 	bgtzl	$v0,.L000143dc
/*    143b0:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    143b4:	0c00543a */ 	jal	func000150e8
/*    143b8:	00000000 */ 	sll	$zero,$zero,0x0
/*    143bc:	0c00508e */ 	jal	func00014238
/*    143c0:	00000000 */ 	sll	$zero,$zero,0x0
/*    143c4:	0c005451 */ 	jal	func00015144
/*    143c8:	00000000 */ 	sll	$zero,$zero,0x0
/*    143cc:	3c04800a */ 	lui	$a0,%hi(var80099a60)
/*    143d0:	0c005016 */ 	jal	func00014058
/*    143d4:	24849a60 */ 	addiu	$a0,$a0,%lo(var80099a60)
.L000143d8:
/*    143d8:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L000143dc:
/*    143dc:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*    143e0:	03e00008 */ 	jr	$ra
/*    143e4:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func000143e8
/*    143e8:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*    143ec:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    143f0:	0c013d00 */ 	jal	func0004f400
/*    143f4:	00000000 */ 	sll	$zero,$zero,0x0
/*    143f8:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    143fc:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*    14400:	03e00008 */ 	jr	$ra
/*    14404:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func00014408
/*    14408:	3c03800a */ 	lui	$v1,%hi(var80099a60)
/*    1440c:	24639a60 */ 	addiu	$v1,$v1,%lo(var80099a60)
/*    14410:	8c6401e8 */ 	lw	$a0,0x1e8($v1)
/*    14414:	24010014 */ 	addiu	$at,$zero,0x14
/*    14418:	8c6f01e4 */ 	lw	$t7,0x1e4($v1)
/*    1441c:	24820001 */ 	addiu	$v0,$a0,0x1
/*    14420:	0041001a */ 	div	$zero,$v0,$at
/*    14424:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*    14428:	00001010 */ 	mfhi	$v0
/*    1442c:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    14430:	544f0003 */ 	bnel	$v0,$t7,.L00014440
/*    14434:	0002c080 */ 	sll	$t8,$v0,0x2
/*    14438:	00801025 */ 	or	$v0,$a0,$zero
/*    1443c:	0002c080 */ 	sll	$t8,$v0,0x2
.L00014440:
/*    14440:	0302c023 */ 	subu	$t8,$t8,$v0
/*    14444:	0018c0c0 */ 	sll	$t8,$t8,0x3
/*    14448:	00782021 */ 	addu	$a0,$v1,$t8
/*    1444c:	0c013d21 */ 	jal	func0004f484
/*    14450:	afa2001c */ 	sw	$v0,0x1c($sp)
/*    14454:	8fa2001c */ 	lw	$v0,0x1c($sp)
/*    14458:	24010014 */ 	addiu	$at,$zero,0x14
/*    1445c:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    14460:	24480013 */ 	addiu	$t0,$v0,0x13
/*    14464:	0101001a */ 	div	$zero,$t0,$at
/*    14468:	3c03800a */ 	lui	$v1,%hi(var80099a60)
/*    1446c:	24639a60 */ 	addiu	$v1,$v1,%lo(var80099a60)
/*    14470:	00004810 */ 	mfhi	$t1
/*    14474:	ac6901ec */ 	sw	$t1,0x1ec($v1)
/*    14478:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*    1447c:	03e00008 */ 	jr	$ra
/*    14480:	ac6201e8 */ 	sw	$v0,0x1e8($v1)
);

GLOBAL_ASM(
glabel func00014484
/*    14484:	27bdffc8 */ 	addiu	$sp,$sp,-56
/*    14488:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    1448c:	3c04800a */ 	lui	$a0,%hi(var80099ec0)
/*    14490:	24849ec0 */ 	addiu	$a0,$a0,%lo(var80099ec0)
/*    14494:	27a50034 */ 	addiu	$a1,$sp,0x34
/*    14498:	0c0121bc */ 	jal	func000486f0
/*    1449c:	00003025 */ 	or	$a2,$zero,$zero
/*    144a0:	14400049 */ 	bnez	$v0,.L000145c8
/*    144a4:	3c04800a */ 	lui	$a0,%hi(var80099f00)
/*    144a8:	3c0e8006 */ 	lui	$t6,0x8006
/*    144ac:	8dceee64 */ 	lw	$t6,-0x119c($t6)
/*    144b0:	3c04800a */ 	lui	$a0,%hi(var80099e78)
/*    144b4:	24849e78 */ 	addiu	$a0,$a0,%lo(var80099e78)
/*    144b8:	11c00035 */ 	beqz	$t6,.L00014590
/*    144bc:	27a50034 */ 	addiu	$a1,$sp,0x34
/*    144c0:	0c0121bc */ 	jal	func000486f0
/*    144c4:	24060001 */ 	addiu	$a2,$zero,0x1
/*    144c8:	3c018006 */ 	lui	$at,0x8006
/*    144cc:	0c005102 */ 	jal	func00014408
/*    144d0:	ac20ee64 */ 	sw	$zero,-0x119c($at)
/*    144d4:	3c0f800a */ 	lui	$t7,0x800a
/*    144d8:	8def9c48 */ 	lw	$t7,-0x63b8($t7)
/*    144dc:	3c19800a */ 	lui	$t9,%hi(var80099a60)
/*    144e0:	27399a60 */ 	addiu	$t9,$t9,%lo(var80099a60)
/*    144e4:	000fc080 */ 	sll	$t8,$t7,0x2
/*    144e8:	030fc023 */ 	subu	$t8,$t8,$t7
/*    144ec:	0018c0c0 */ 	sll	$t8,$t8,0x3
/*    144f0:	3c04800a */ 	lui	$a0,%hi(var80099a60)
/*    144f4:	24849a60 */ 	addiu	$a0,$a0,%lo(var80099a60)
/*    144f8:	03193821 */ 	addu	$a3,$t8,$t9
/*    144fc:	00002825 */ 	or	$a1,$zero,$zero
/*    14500:	24060006 */ 	addiu	$a2,$zero,0x6
.L00014504:
/*    14504:	00a60019 */ 	multu	$a1,$a2
/*    14508:	00001012 */ 	mflo	$v0
/*    1450c:	00e24021 */ 	addu	$t0,$a3,$v0
/*    14510:	91030004 */ 	lbu	$v1,0x4($t0)
/*    14514:	1460000a */ 	bnez	$v1,.L00014540
/*    14518:	00000000 */ 	sll	$zero,$zero,0x0
/*    1451c:	8c8901ec */ 	lw	$t1,0x1ec($a0)
/*    14520:	00095080 */ 	sll	$t2,$t1,0x2
/*    14524:	01495023 */ 	subu	$t2,$t2,$t1
/*    14528:	000a50c0 */ 	sll	$t2,$t2,0x3
/*    1452c:	008a5821 */ 	addu	$t3,$a0,$t2
/*    14530:	01626021 */ 	addu	$t4,$t3,$v0
/*    14534:	918d0004 */ 	lbu	$t5,0x4($t4)
/*    14538:	15a0000c */ 	bnez	$t5,.L0001456c
/*    1453c:	00000000 */ 	sll	$zero,$zero,0x0
.L00014540:
/*    14540:	1060000e */ 	beqz	$v1,.L0001457c
/*    14544:	24a50001 */ 	addiu	$a1,$a1,0x1
/*    14548:	8c8e01ec */ 	lw	$t6,0x1ec($a0)
/*    1454c:	000e7880 */ 	sll	$t7,$t6,0x2
/*    14550:	01ee7823 */ 	subu	$t7,$t7,$t6
/*    14554:	000f78c0 */ 	sll	$t7,$t7,0x3
/*    14558:	008fc021 */ 	addu	$t8,$a0,$t7
/*    1455c:	0302c821 */ 	addu	$t9,$t8,$v0
/*    14560:	93280004 */ 	lbu	$t0,0x4($t9)
/*    14564:	55000006 */ 	bnezl	$t0,.L00014580
/*    14568:	00054e00 */ 	sll	$t1,$a1,0x18
.L0001456c:
/*    1456c:	0c004fa1 */ 	jal	func00013e84
/*    14570:	00000000 */ 	sll	$zero,$zero,0x0
/*    14574:	10000006 */ 	beqz	$zero,.L00014590
/*    14578:	00000000 */ 	sll	$zero,$zero,0x0
.L0001457c:
/*    1457c:	00054e00 */ 	sll	$t1,$a1,0x18
.L00014580:
/*    14580:	00092e03 */ 	sra	$a1,$t1,0x18
/*    14584:	28a10004 */ 	slti	$at,$a1,0x4
/*    14588:	1420ffde */ 	bnez	$at,.L00014504
/*    1458c:	00000000 */ 	sll	$zero,$zero,0x0
.L00014590:
/*    14590:	3c04800a */ 	lui	$a0,%hi(var80099ee0)
/*    14594:	24849ee0 */ 	addiu	$a0,$a0,%lo(var80099ee0)
/*    14598:	27a50034 */ 	addiu	$a1,$sp,0x34
/*    1459c:	0c012238 */ 	jal	func000488e0
/*    145a0:	00003025 */ 	or	$a2,$zero,$zero
/*    145a4:	3c038006 */ 	lui	$v1,%hi(var8005ee68)
/*    145a8:	2463ee68 */ 	addiu	$v1,$v1,%lo(var8005ee68)
/*    145ac:	8c6b0000 */ 	lw	$t3,0x0($v1)
/*    145b0:	00002025 */ 	or	$a0,$zero,$zero
/*    145b4:	256c0001 */ 	addiu	$t4,$t3,0x1
/*    145b8:	0c004eae */ 	jal	func00013ab8
/*    145bc:	ac6c0000 */ 	sw	$t4,0x0($v1)
/*    145c0:	10000090 */ 	beqz	$zero,.L00014804
/*    145c4:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L000145c8:
/*    145c8:	24849f00 */ 	addiu	$a0,$a0,%lo(var80099f00)
/*    145cc:	27a50034 */ 	addiu	$a1,$sp,0x34
/*    145d0:	0c0121bc */ 	jal	func000486f0
/*    145d4:	00003025 */ 	or	$a2,$zero,$zero
/*    145d8:	14400014 */ 	bnez	$v0,.L0001462c
/*    145dc:	3c198006 */ 	lui	$t9,0x8006
/*    145e0:	3c038006 */ 	lui	$v1,%hi(var8005ee68)
/*    145e4:	2463ee68 */ 	addiu	$v1,$v1,%lo(var8005ee68)
/*    145e8:	8c6d0000 */ 	lw	$t5,0x0($v1)
/*    145ec:	3c04800a */ 	lui	$a0,%hi(var80099e78)
/*    145f0:	25aeffff */ 	addiu	$t6,$t5,-1
/*    145f4:	15c00006 */ 	bnez	$t6,.L00014610
/*    145f8:	ac6e0000 */ 	sw	$t6,0x0($v1)
/*    145fc:	0c0050fa */ 	jal	func000143e8
/*    14600:	24849e78 */ 	addiu	$a0,$a0,%lo(var80099e78)
/*    14604:	24180001 */ 	addiu	$t8,$zero,0x1
/*    14608:	3c018006 */ 	lui	$at,0x8006
/*    1460c:	ac38ee64 */ 	sw	$t8,-0x119c($at)
.L00014610:
/*    14610:	3c04800a */ 	lui	$a0,%hi(var80099f20)
/*    14614:	24849f20 */ 	addiu	$a0,$a0,%lo(var80099f20)
/*    14618:	27a50034 */ 	addiu	$a1,$sp,0x34
/*    1461c:	0c012238 */ 	jal	func000488e0
/*    14620:	00003025 */ 	or	$a2,$zero,$zero
/*    14624:	10000077 */ 	beqz	$zero,.L00014804
/*    14628:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0001462c:
/*    1462c:	8f39eeb4 */ 	lw	$t9,-0x114c($t9)
/*    14630:	3c038006 */ 	lui	$v1,%hi(var8005ee68)
/*    14634:	2463ee68 */ 	addiu	$v1,$v1,%lo(var8005ee68)
/*    14638:	53200072 */ 	beqzl	$t9,.L00014804
/*    1463c:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    14640:	8c680000 */ 	lw	$t0,0x0($v1)
/*    14644:	3c04800a */ 	lui	$a0,%hi(var80099e78)
/*    14648:	24849e78 */ 	addiu	$a0,$a0,%lo(var80099e78)
/*    1464c:	11000005 */ 	beqz	$t0,.L00014664
/*    14650:	27a50034 */ 	addiu	$a1,$sp,0x34
/*    14654:	0c004eae */ 	jal	func00013ab8
/*    14658:	00002025 */ 	or	$a0,$zero,$zero
/*    1465c:	10000069 */ 	beqz	$zero,.L00014804
/*    14660:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L00014664:
/*    14664:	0c0121bc */ 	jal	func000486f0
/*    14668:	00003025 */ 	or	$a2,$zero,$zero
/*    1466c:	14400064 */ 	bnez	$v0,.L00014800
/*    14670:	3c018006 */ 	lui	$at,0x8006
/*    14674:	0c005102 */ 	jal	func00014408
/*    14678:	ac20ee64 */ 	sw	$zero,-0x119c($at)
/*    1467c:	3c09800a */ 	lui	$t1,0x800a
/*    14680:	8d299c48 */ 	lw	$t1,-0x63b8($t1)
/*    14684:	3c0b800a */ 	lui	$t3,%hi(var80099a60)
/*    14688:	256b9a60 */ 	addiu	$t3,$t3,%lo(var80099a60)
/*    1468c:	00095080 */ 	sll	$t2,$t1,0x2
/*    14690:	01495023 */ 	subu	$t2,$t2,$t1
/*    14694:	000a50c0 */ 	sll	$t2,$t2,0x3
/*    14698:	3c04800a */ 	lui	$a0,%hi(var80099a60)
/*    1469c:	24849a60 */ 	addiu	$a0,$a0,%lo(var80099a60)
/*    146a0:	014b3821 */ 	addu	$a3,$t2,$t3
/*    146a4:	00002825 */ 	or	$a1,$zero,$zero
/*    146a8:	24060006 */ 	addiu	$a2,$zero,0x6
.L000146ac:
/*    146ac:	00a60019 */ 	multu	$a1,$a2
/*    146b0:	00001012 */ 	mflo	$v0
/*    146b4:	00e26021 */ 	addu	$t4,$a3,$v0
/*    146b8:	91830004 */ 	lbu	$v1,0x4($t4)
/*    146bc:	1460000a */ 	bnez	$v1,.L000146e8
/*    146c0:	00000000 */ 	sll	$zero,$zero,0x0
/*    146c4:	8c8d01ec */ 	lw	$t5,0x1ec($a0)
/*    146c8:	000d7080 */ 	sll	$t6,$t5,0x2
/*    146cc:	01cd7023 */ 	subu	$t6,$t6,$t5
/*    146d0:	000e70c0 */ 	sll	$t6,$t6,0x3
/*    146d4:	008e7821 */ 	addu	$t7,$a0,$t6
/*    146d8:	01e2c021 */ 	addu	$t8,$t7,$v0
/*    146dc:	93190004 */ 	lbu	$t9,0x4($t8)
/*    146e0:	1720000c */ 	bnez	$t9,.L00014714
/*    146e4:	00000000 */ 	sll	$zero,$zero,0x0
.L000146e8:
/*    146e8:	1060000e */ 	beqz	$v1,.L00014724
/*    146ec:	24a50001 */ 	addiu	$a1,$a1,0x1
/*    146f0:	8c8801ec */ 	lw	$t0,0x1ec($a0)
/*    146f4:	00084880 */ 	sll	$t1,$t0,0x2
/*    146f8:	01284823 */ 	subu	$t1,$t1,$t0
/*    146fc:	000948c0 */ 	sll	$t1,$t1,0x3
/*    14700:	00895021 */ 	addu	$t2,$a0,$t1
/*    14704:	01425821 */ 	addu	$t3,$t2,$v0
/*    14708:	916c0004 */ 	lbu	$t4,0x4($t3)
/*    1470c:	55800006 */ 	bnezl	$t4,.L00014728
/*    14710:	00056e00 */ 	sll	$t5,$a1,0x18
.L00014714:
/*    14714:	0c004fa1 */ 	jal	func00013e84
/*    14718:	00000000 */ 	sll	$zero,$zero,0x0
/*    1471c:	10000006 */ 	beqz	$zero,.L00014738
/*    14720:	00000000 */ 	sll	$zero,$zero,0x0
.L00014724:
/*    14724:	00056e00 */ 	sll	$t5,$a1,0x18
.L00014728:
/*    14728:	000d2e03 */ 	sra	$a1,$t5,0x18
/*    1472c:	28a10004 */ 	slti	$at,$a1,0x4
/*    14730:	1420ffde */ 	bnez	$at,.L000146ac
/*    14734:	00000000 */ 	sll	$zero,$zero,0x0
.L00014738:
/*    14738:	0c00508e */ 	jal	func00014238
/*    1473c:	00000000 */ 	sll	$zero,$zero,0x0
/*    14740:	0c004eae */ 	jal	func00013ab8
/*    14744:	00002025 */ 	or	$a0,$zero,$zero
/*    14748:	3c04800a */ 	lui	$a0,%hi(var80099e78)
/*    1474c:	0c0050fa */ 	jal	func000143e8
/*    14750:	24849e78 */ 	addiu	$a0,$a0,%lo(var80099e78)
/*    14754:	3c038006 */ 	lui	$v1,%hi(var80060004)
/*    14758:	8c63ef0c */ 	lw	$v1,-0x10f4($v1)
/*    1475c:	240f0001 */ 	addiu	$t7,$zero,0x1
/*    14760:	3c018006 */ 	lui	$at,0x8006
/*    14764:	ac2fee64 */ 	sw	$t7,-0x119c($at)
/*    14768:	3c018006 */ 	lui	$at,0x8006
/*    1476c:	24630001 */ 	addiu	$v1,$v1,0x1
/*    14770:	ac23ef0c */ 	sw	$v1,-0x10f4($at)
/*    14774:	2861003c */ 	slti	$at,$v1,0x3c
/*    14778:	14200021 */ 	bnez	$at,.L00014800
/*    1477c:	3c038006 */ 	lui	$v1,%hi(var8005ee6c)
/*    14780:	3c048006 */ 	lui	$a0,%hi(var8005ee7c)
/*    14784:	3c058006 */ 	lui	$a1,%hi(var8005ee8c)
/*    14788:	3c028006 */ 	lui	$v0,%hi(var8005ee9c)
/*    1478c:	3c068006 */ 	lui	$a2,%hi(var8005eeac)
/*    14790:	24c6eeac */ 	addiu	$a2,$a2,%lo(var8005eeac)
/*    14794:	2442ee9c */ 	addiu	$v0,$v0,%lo(var8005ee9c)
/*    14798:	24a5ee8c */ 	addiu	$a1,$a1,%lo(var8005ee8c)
/*    1479c:	2484ee7c */ 	addiu	$a0,$a0,%lo(var8005ee7c)
/*    147a0:	2463ee6c */ 	addiu	$v1,$v1,%lo(var8005ee6c)
.L000147a4:
/*    147a4:	8c780000 */ 	lw	$t8,0x0($v1)
/*    147a8:	5700000b */ 	bnezl	$t8,.L000147d8
/*    147ac:	ac600000 */ 	sw	$zero,0x0($v1)
/*    147b0:	8c990000 */ 	lw	$t9,0x0($a0)
/*    147b4:	57200008 */ 	bnezl	$t9,.L000147d8
/*    147b8:	ac600000 */ 	sw	$zero,0x0($v1)
/*    147bc:	8ca80000 */ 	lw	$t0,0x0($a1)
/*    147c0:	55000005 */ 	bnezl	$t0,.L000147d8
/*    147c4:	ac600000 */ 	sw	$zero,0x0($v1)
/*    147c8:	8c490000 */ 	lw	$t1,0x0($v0)
/*    147cc:	51200006 */ 	beqzl	$t1,.L000147e8
/*    147d0:	24420004 */ 	addiu	$v0,$v0,0x4
/*    147d4:	ac600000 */ 	sw	$zero,0x0($v1)
.L000147d8:
/*    147d8:	ac800000 */ 	sw	$zero,0x0($a0)
/*    147dc:	aca00000 */ 	sw	$zero,0x0($a1)
/*    147e0:	ac400000 */ 	sw	$zero,0x0($v0)
/*    147e4:	24420004 */ 	addiu	$v0,$v0,0x4
.L000147e8:
/*    147e8:	24630004 */ 	addiu	$v1,$v1,%lo(var80060004)
/*    147ec:	24840004 */ 	addiu	$a0,$a0,0x4
/*    147f0:	1446ffec */ 	bne	$v0,$a2,.L000147a4
/*    147f4:	24a50004 */ 	addiu	$a1,$a1,0x4
/*    147f8:	3c018006 */ 	lui	$at,0x8006
/*    147fc:	ac20ef0c */ 	sw	$zero,-0x10f4($at)
.L00014800:
/*    14800:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L00014804:
/*    14804:	27bd0038 */ 	addiu	$sp,$sp,0x38
/*    14808:	03e00008 */ 	jr	$ra
/*    1480c:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func00014810
/*    14810:	3c018006 */ 	lui	$at,0x8006
/*    14814:	03e00008 */ 	jr	$ra
/*    14818:	ac24eec0 */ 	sw	$a0,-0x1140($at)
);

GLOBAL_ASM(
glabel func0001481c
/*    1481c:	3c038006 */ 	lui	$v1,0x8006
/*    14820:	8c63ee60 */ 	lw	$v1,-0x11a0($v1)
/*    14824:	24010014 */ 	addiu	$at,$zero,0x14
/*    14828:	8c6e01e0 */ 	lw	$t6,0x1e0($v1)
/*    1482c:	8c6f01e4 */ 	lw	$t7,0x1e4($v1)
/*    14830:	01cf1023 */ 	subu	$v0,$t6,$t7
/*    14834:	24420014 */ 	addiu	$v0,$v0,0x14
/*    14838:	0041001a */ 	div	$zero,$v0,$at
/*    1483c:	00001010 */ 	mfhi	$v0
/*    14840:	03e00008 */ 	jr	$ra
/*    14844:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func00014848
/*    14848:	3c038006 */ 	lui	$v1,0x8006
/*    1484c:	8c63ee60 */ 	lw	$v1,-0x11a0($v1)
/*    14850:	afa50004 */ 	sw	$a1,0x4($sp)
/*    14854:	00057600 */ 	sll	$t6,$a1,0x18
/*    14858:	8c780200 */ 	lw	$t8,0x200($v1)
/*    1485c:	000e7e03 */ 	sra	$t7,$t6,0x18
/*    14860:	01e02825 */ 	or	$a1,$t7,$zero
/*    14864:	0701000e */ 	bgez	$t8,.L000148a0
/*    14868:	3c198006 */ 	lui	$t9,0x8006
/*    1486c:	9339eeac */ 	lbu	$t9,-0x1154($t9)
/*    14870:	3c0b8006 */ 	lui	$t3,%hi(var8005ee6c)
/*    14874:	256bee6c */ 	addiu	$t3,$t3,%lo(var8005ee6c)
/*    14878:	01f94007 */ 	srav	$t0,$t9,$t7
/*    1487c:	31090001 */ 	andi	$t1,$t0,0x1
/*    14880:	15200007 */ 	bnez	$t1,.L000148a0
/*    14884:	000f5080 */ 	sll	$t2,$t7,0x2
/*    14888:	014b1821 */ 	addu	$v1,$t2,$t3
/*    1488c:	8c6c0000 */ 	lw	$t4,0x0($v1)
/*    14890:	00001025 */ 	or	$v0,$zero,$zero
/*    14894:	258d0001 */ 	addiu	$t5,$t4,0x1
/*    14898:	03e00008 */ 	jr	$ra
/*    1489c:	ac6d0000 */ 	sw	$t5,0x0($v1)
.L000148a0:
/*    148a0:	00057080 */ 	sll	$t6,$a1,0x2
/*    148a4:	3c0f800a */ 	lui	$t7,0x800a
/*    148a8:	01ee7821 */ 	addu	$t7,$t7,$t6
/*    148ac:	8def9e68 */ 	lw	$t7,-0x6198($t7)
/*    148b0:	59e00004 */ 	blezl	$t7,.L000148c4
/*    148b4:	8c7801e4 */ 	lw	$t8,0x1e4($v1)
/*    148b8:	03e00008 */ 	jr	$ra
/*    148bc:	00001025 */ 	or	$v0,$zero,$zero
/*    148c0:	8c7801e4 */ 	lw	$t8,0x1e4($v1)
.L000148c4:
/*    148c4:	24010014 */ 	addiu	$at,$zero,0x14
/*    148c8:	00056080 */ 	sll	$t4,$a1,0x2
/*    148cc:	0304c821 */ 	addu	$t9,$t8,$a0
/*    148d0:	27280001 */ 	addiu	$t0,$t9,0x1
/*    148d4:	0101001a */ 	div	$zero,$t0,$at
/*    148d8:	00004810 */ 	mfhi	$t1
/*    148dc:	00095080 */ 	sll	$t2,$t1,0x2
/*    148e0:	01495023 */ 	subu	$t2,$t2,$t1
/*    148e4:	000a50c0 */ 	sll	$t2,$t2,0x3
/*    148e8:	01856023 */ 	subu	$t4,$t4,$a1
/*    148ec:	000c6040 */ 	sll	$t4,$t4,0x1
/*    148f0:	006a5821 */ 	addu	$t3,$v1,$t2
/*    148f4:	016c6821 */ 	addu	$t5,$t3,$t4
/*    148f8:	81a20002 */ 	lb	$v0,0x2($t5)
/*    148fc:	03e00008 */ 	jr	$ra
/*    14900:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func00014904
/*    14904:	3c038006 */ 	lui	$v1,0x8006
/*    14908:	8c63ee60 */ 	lw	$v1,-0x11a0($v1)
/*    1490c:	afa50004 */ 	sw	$a1,0x4($sp)
/*    14910:	00057600 */ 	sll	$t6,$a1,0x18
/*    14914:	8c780200 */ 	lw	$t8,0x200($v1)
/*    14918:	000e7e03 */ 	sra	$t7,$t6,0x18
/*    1491c:	01e02825 */ 	or	$a1,$t7,$zero
/*    14920:	0701000e */ 	bgez	$t8,.L0001495c
/*    14924:	3c198006 */ 	lui	$t9,0x8006
/*    14928:	9339eeac */ 	lbu	$t9,-0x1154($t9)
/*    1492c:	3c0b8006 */ 	lui	$t3,%hi(var8005ee7c)
/*    14930:	256bee7c */ 	addiu	$t3,$t3,%lo(var8005ee7c)
/*    14934:	01f94007 */ 	srav	$t0,$t9,$t7
/*    14938:	31090001 */ 	andi	$t1,$t0,0x1
/*    1493c:	15200007 */ 	bnez	$t1,.L0001495c
/*    14940:	000f5080 */ 	sll	$t2,$t7,0x2
/*    14944:	014b1821 */ 	addu	$v1,$t2,$t3
/*    14948:	8c6c0000 */ 	lw	$t4,0x0($v1)
/*    1494c:	00001025 */ 	or	$v0,$zero,$zero
/*    14950:	258d0001 */ 	addiu	$t5,$t4,0x1
/*    14954:	03e00008 */ 	jr	$ra
/*    14958:	ac6d0000 */ 	sw	$t5,0x0($v1)
.L0001495c:
/*    1495c:	00057080 */ 	sll	$t6,$a1,0x2
/*    14960:	3c0f800a */ 	lui	$t7,0x800a
/*    14964:	01ee7821 */ 	addu	$t7,$t7,$t6
/*    14968:	8def9e68 */ 	lw	$t7,-0x6198($t7)
/*    1496c:	59e00004 */ 	blezl	$t7,.L00014980
/*    14970:	8c7801e4 */ 	lw	$t8,0x1e4($v1)
/*    14974:	03e00008 */ 	jr	$ra
/*    14978:	00001025 */ 	or	$v0,$zero,$zero
/*    1497c:	8c7801e4 */ 	lw	$t8,0x1e4($v1)
.L00014980:
/*    14980:	24010014 */ 	addiu	$at,$zero,0x14
/*    14984:	00056080 */ 	sll	$t4,$a1,0x2
/*    14988:	0304c821 */ 	addu	$t9,$t8,$a0
/*    1498c:	27280001 */ 	addiu	$t0,$t9,0x1
/*    14990:	0101001a */ 	div	$zero,$t0,$at
/*    14994:	00004810 */ 	mfhi	$t1
/*    14998:	00095080 */ 	sll	$t2,$t1,0x2
/*    1499c:	01495023 */ 	subu	$t2,$t2,$t1
/*    149a0:	000a50c0 */ 	sll	$t2,$t2,0x3
/*    149a4:	01856023 */ 	subu	$t4,$t4,$a1
/*    149a8:	000c6040 */ 	sll	$t4,$t4,0x1
/*    149ac:	006a5821 */ 	addu	$t3,$v1,$t2
/*    149b0:	016c6821 */ 	addu	$t5,$t3,$t4
/*    149b4:	81a20003 */ 	lb	$v0,0x3($t5)
/*    149b8:	03e00008 */ 	jr	$ra
/*    149bc:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func000149c0
/*    149c0:	3c038006 */ 	lui	$v1,0x8006
/*    149c4:	8c63ee60 */ 	lw	$v1,-0x11a0($v1)
/*    149c8:	afa50004 */ 	sw	$a1,0x4($sp)
/*    149cc:	00057600 */ 	sll	$t6,$a1,0x18
/*    149d0:	8c780200 */ 	lw	$t8,0x200($v1)
/*    149d4:	000e7e03 */ 	sra	$t7,$t6,0x18
/*    149d8:	01e02825 */ 	or	$a1,$t7,$zero
/*    149dc:	0701000e */ 	bgez	$t8,.L00014a18
/*    149e0:	3c198006 */ 	lui	$t9,0x8006
/*    149e4:	9339eeac */ 	lbu	$t9,-0x1154($t9)
/*    149e8:	3c0b8006 */ 	lui	$t3,%hi(var8005ee7c)
/*    149ec:	256bee7c */ 	addiu	$t3,$t3,%lo(var8005ee7c)
/*    149f0:	01f94007 */ 	srav	$t0,$t9,$t7
/*    149f4:	31090001 */ 	andi	$t1,$t0,0x1
/*    149f8:	15200007 */ 	bnez	$t1,.L00014a18
/*    149fc:	000f5080 */ 	sll	$t2,$t7,0x2
/*    14a00:	014b1821 */ 	addu	$v1,$t2,$t3
/*    14a04:	8c6c0000 */ 	lw	$t4,0x0($v1)
/*    14a08:	00001025 */ 	or	$v0,$zero,$zero
/*    14a0c:	258d0001 */ 	addiu	$t5,$t4,0x1
/*    14a10:	03e00008 */ 	jr	$ra
/*    14a14:	ac6d0000 */ 	sw	$t5,0x0($v1)
.L00014a18:
/*    14a18:	00057080 */ 	sll	$t6,$a1,0x2
/*    14a1c:	3c0f800a */ 	lui	$t7,0x800a
/*    14a20:	01ee7821 */ 	addu	$t7,$t7,$t6
/*    14a24:	8def9e68 */ 	lw	$t7,-0x6198($t7)
/*    14a28:	59e00004 */ 	blezl	$t7,.L00014a3c
/*    14a2c:	8c7801e4 */ 	lw	$t8,0x1e4($v1)
/*    14a30:	03e00008 */ 	jr	$ra
/*    14a34:	00001025 */ 	or	$v0,$zero,$zero
/*    14a38:	8c7801e4 */ 	lw	$t8,0x1e4($v1)
.L00014a3c:
/*    14a3c:	24010014 */ 	addiu	$at,$zero,0x14
/*    14a40:	00055880 */ 	sll	$t3,$a1,0x2
/*    14a44:	0304c821 */ 	addu	$t9,$t8,$a0
/*    14a48:	0321001a */ 	div	$zero,$t9,$at
/*    14a4c:	00004010 */ 	mfhi	$t0
/*    14a50:	00084880 */ 	sll	$t1,$t0,0x2
/*    14a54:	01284823 */ 	subu	$t1,$t1,$t0
/*    14a58:	000948c0 */ 	sll	$t1,$t1,0x3
/*    14a5c:	01655823 */ 	subu	$t3,$t3,$a1
/*    14a60:	000b5840 */ 	sll	$t3,$t3,0x1
/*    14a64:	00695021 */ 	addu	$t2,$v1,$t1
/*    14a68:	014b6021 */ 	addu	$t4,$t2,$t3
/*    14a6c:	81820003 */ 	lb	$v0,0x3($t4)
/*    14a70:	03e00008 */ 	jr	$ra
/*    14a74:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func00014a78
/*    14a78:	3c038006 */ 	lui	$v1,0x8006
/*    14a7c:	8c63ee60 */ 	lw	$v1,-0x11a0($v1)
/*    14a80:	afa50004 */ 	sw	$a1,0x4($sp)
/*    14a84:	afa60008 */ 	sw	$a2,0x8($sp)
/*    14a88:	8c790200 */ 	lw	$t9,0x200($v1)
/*    14a8c:	00057600 */ 	sll	$t6,$a1,0x18
/*    14a90:	000e7e03 */ 	sra	$t7,$t6,0x18
/*    14a94:	30d8ffff */ 	andi	$t8,$a2,0xffff
/*    14a98:	03003025 */ 	or	$a2,$t8,$zero
/*    14a9c:	01e02825 */ 	or	$a1,$t7,$zero
/*    14aa0:	0721000f */ 	bgez	$t9,.L00014ae0
/*    14aa4:	00803825 */ 	or	$a3,$a0,$zero
/*    14aa8:	3c088006 */ 	lui	$t0,0x8006
/*    14aac:	9108eeac */ 	lbu	$t0,-0x1154($t0)
/*    14ab0:	3c0c8006 */ 	lui	$t4,%hi(var8005ee8c)
/*    14ab4:	258cee8c */ 	addiu	$t4,$t4,%lo(var8005ee8c)
/*    14ab8:	01e84807 */ 	srav	$t1,$t0,$t7
/*    14abc:	312a0001 */ 	andi	$t2,$t1,0x1
/*    14ac0:	15400007 */ 	bnez	$t2,.L00014ae0
/*    14ac4:	000f5880 */ 	sll	$t3,$t7,0x2
/*    14ac8:	016c1821 */ 	addu	$v1,$t3,$t4
/*    14acc:	8c6d0000 */ 	lw	$t5,0x0($v1)
/*    14ad0:	00001025 */ 	or	$v0,$zero,$zero
/*    14ad4:	25ae0001 */ 	addiu	$t6,$t5,0x1
/*    14ad8:	03e00008 */ 	jr	$ra
/*    14adc:	ac6e0000 */ 	sw	$t6,0x0($v1)
.L00014ae0:
/*    14ae0:	00057880 */ 	sll	$t7,$a1,0x2
/*    14ae4:	3c18800a */ 	lui	$t8,0x800a
/*    14ae8:	030fc021 */ 	addu	$t8,$t8,$t7
/*    14aec:	8f189e68 */ 	lw	$t8,-0x6198($t8)
/*    14af0:	5b000004 */ 	blezl	$t8,.L00014b04
/*    14af4:	8c7901e4 */ 	lw	$t9,0x1e4($v1)
/*    14af8:	03e00008 */ 	jr	$ra
/*    14afc:	00001025 */ 	or	$v0,$zero,$zero
/*    14b00:	8c7901e4 */ 	lw	$t9,0x1e4($v1)
.L00014b04:
/*    14b04:	24010014 */ 	addiu	$at,$zero,0x14
/*    14b08:	00056880 */ 	sll	$t5,$a1,0x2
/*    14b0c:	03274021 */ 	addu	$t0,$t9,$a3
/*    14b10:	25090001 */ 	addiu	$t1,$t0,0x1
/*    14b14:	0121001a */ 	div	$zero,$t1,$at
/*    14b18:	00005010 */ 	mfhi	$t2
/*    14b1c:	000a5880 */ 	sll	$t3,$t2,0x2
/*    14b20:	016a5823 */ 	subu	$t3,$t3,$t2
/*    14b24:	000b58c0 */ 	sll	$t3,$t3,0x3
/*    14b28:	01a56823 */ 	subu	$t5,$t5,$a1
/*    14b2c:	000d6840 */ 	sll	$t5,$t5,0x1
/*    14b30:	006b6021 */ 	addu	$t4,$v1,$t3
/*    14b34:	018d7021 */ 	addu	$t6,$t4,$t5
/*    14b38:	95c40000 */ 	lhu	$a0,0x0($t6)
/*    14b3c:	00861024 */ 	and	$v0,$a0,$a2
/*    14b40:	304fffff */ 	andi	$t7,$v0,0xffff
/*    14b44:	01e01025 */ 	or	$v0,$t7,$zero
/*    14b48:	03e00008 */ 	jr	$ra
/*    14b4c:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func00014b50
/*    14b50:	3c038006 */ 	lui	$v1,0x8006
/*    14b54:	8c63ee60 */ 	lw	$v1,-0x11a0($v1)
/*    14b58:	afa50004 */ 	sw	$a1,0x4($sp)
/*    14b5c:	afa60008 */ 	sw	$a2,0x8($sp)
/*    14b60:	8c780200 */ 	lw	$t8,0x200($v1)
/*    14b64:	00057600 */ 	sll	$t6,$a1,0x18
/*    14b68:	000e7e03 */ 	sra	$t7,$t6,0x18
/*    14b6c:	01e02825 */ 	or	$a1,$t7,$zero
/*    14b70:	07010010 */ 	bgez	$t8,.L00014bb4
/*    14b74:	00803825 */ 	or	$a3,$a0,$zero
/*    14b78:	3c198006 */ 	lui	$t9,0x8006
/*    14b7c:	9339eeac */ 	lbu	$t9,-0x1154($t9)
/*    14b80:	00056880 */ 	sll	$t5,$a1,0x2
/*    14b84:	00b95807 */ 	srav	$t3,$t9,$a1
/*    14b88:	316c0001 */ 	andi	$t4,$t3,0x1
/*    14b8c:	5580000a */ 	bnezl	$t4,.L00014bb8
/*    14b90:	0005c880 */ 	sll	$t9,$a1,0x2
/*    14b94:	3c0e8006 */ 	lui	$t6,%hi(var8005ee9c)
/*    14b98:	25ceee9c */ 	addiu	$t6,$t6,%lo(var8005ee9c)
/*    14b9c:	01ae1821 */ 	addu	$v1,$t5,$t6
/*    14ba0:	8c6f0000 */ 	lw	$t7,0x0($v1)
/*    14ba4:	00001025 */ 	or	$v0,$zero,$zero
/*    14ba8:	25f80001 */ 	addiu	$t8,$t7,0x1
/*    14bac:	03e00008 */ 	jr	$ra
/*    14bb0:	ac780000 */ 	sw	$t8,0x0($v1)
.L00014bb4:
/*    14bb4:	0005c880 */ 	sll	$t9,$a1,0x2
.L00014bb8:
/*    14bb8:	3c0b800a */ 	lui	$t3,0x800a
/*    14bbc:	01795821 */ 	addu	$t3,$t3,$t9
/*    14bc0:	8d6b9e68 */ 	lw	$t3,-0x6198($t3)
/*    14bc4:	59600004 */ 	blezl	$t3,.L00014bd8
/*    14bc8:	8c6c01e4 */ 	lw	$t4,0x1e4($v1)
/*    14bcc:	03e00008 */ 	jr	$ra
/*    14bd0:	00001025 */ 	or	$v0,$zero,$zero
/*    14bd4:	8c6c01e4 */ 	lw	$t4,0x1e4($v1)
.L00014bd8:
/*    14bd8:	240a0014 */ 	addiu	$t2,$zero,0x14
/*    14bdc:	00054080 */ 	sll	$t0,$a1,0x2
/*    14be0:	01873021 */ 	addu	$a2,$t4,$a3
/*    14be4:	24cd0001 */ 	addiu	$t5,$a2,0x1
/*    14be8:	01aa001a */ 	div	$zero,$t5,$t2
/*    14bec:	00007010 */ 	mfhi	$t6
/*    14bf0:	000e7880 */ 	sll	$t7,$t6,0x2
/*    14bf4:	01ee7823 */ 	subu	$t7,$t7,$t6
/*    14bf8:	00ca001a */ 	div	$zero,$a2,$t2
/*    14bfc:	00005810 */ 	mfhi	$t3
/*    14c00:	000b6080 */ 	sll	$t4,$t3,0x2
/*    14c04:	01054023 */ 	subu	$t0,$t0,$a1
/*    14c08:	018b6023 */ 	subu	$t4,$t4,$t3
/*    14c0c:	00084040 */ 	sll	$t0,$t0,0x1
/*    14c10:	15400002 */ 	bnez	$t2,.L00014c1c
/*    14c14:	00000000 */ 	sll	$zero,$zero,0x0
/*    14c18:	0007000d */ 	break	0x7
.L00014c1c:
/*    14c1c:	2401ffff */ 	addiu	$at,$zero,-1
/*    14c20:	15410004 */ 	bne	$t2,$at,.L00014c34
/*    14c24:	3c018000 */ 	lui	$at,0x8000
/*    14c28:	15a10002 */ 	bne	$t5,$at,.L00014c34
/*    14c2c:	00000000 */ 	sll	$zero,$zero,0x0
/*    14c30:	0006000d */ 	break	0x6
.L00014c34:
/*    14c34:	000f78c0 */ 	sll	$t7,$t7,0x3
/*    14c38:	000c60c0 */ 	sll	$t4,$t4,0x3
/*    14c3c:	006fc021 */ 	addu	$t8,$v1,$t7
/*    14c40:	006c6821 */ 	addu	$t5,$v1,$t4
/*    14c44:	0308c821 */ 	addu	$t9,$t8,$t0
/*    14c48:	01a87021 */ 	addu	$t6,$t5,$t0
/*    14c4c:	97240000 */ 	lhu	$a0,0x0($t9)
/*    14c50:	95c90000 */ 	lhu	$t1,0x0($t6)
/*    14c54:	97b9000a */ 	lhu	$t9,0xa($sp)
/*    14c58:	15400002 */ 	bnez	$t2,.L00014c64
/*    14c5c:	00000000 */ 	sll	$zero,$zero,0x0
/*    14c60:	0007000d */ 	break	0x7
.L00014c64:
/*    14c64:	2401ffff */ 	addiu	$at,$zero,-1
/*    14c68:	15410004 */ 	bne	$t2,$at,.L00014c7c
/*    14c6c:	3c018000 */ 	lui	$at,0x8000
/*    14c70:	14c10002 */ 	bne	$a2,$at,.L00014c7c
/*    14c74:	00000000 */ 	sll	$zero,$zero,0x0
/*    14c78:	0006000d */ 	break	0x6
.L00014c7c:
/*    14c7c:	01207827 */ 	nor	$t7,$t1,$zero
/*    14c80:	008fc024 */ 	and	$t8,$a0,$t7
/*    14c84:	03191024 */ 	and	$v0,$t8,$t9
/*    14c88:	304bffff */ 	andi	$t3,$v0,0xffff
/*    14c8c:	01601025 */ 	or	$v0,$t3,$zero
/*    14c90:	03e00008 */ 	jr	$ra
/*    14c94:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func00014c98
/*    14c98:	27bdfff0 */ 	addiu	$sp,$sp,-16
/*    14c9c:	3c078006 */ 	lui	$a3,0x8006
/*    14ca0:	8ce7ee60 */ 	lw	$a3,-0x11a0($a3)
/*    14ca4:	afb1000c */ 	sw	$s1,0xc($sp)
/*    14ca8:	afb00008 */ 	sw	$s0,0x8($sp)
/*    14cac:	afa50014 */ 	sw	$a1,0x14($sp)
/*    14cb0:	afa60018 */ 	sw	$a2,0x18($sp)
/*    14cb4:	8cf80200 */ 	lw	$t8,0x200($a3)
/*    14cb8:	00057600 */ 	sll	$t6,$a1,0x18
/*    14cbc:	000e7e03 */ 	sra	$t7,$t6,0x18
/*    14cc0:	01e02825 */ 	or	$a1,$t7,$zero
/*    14cc4:	00808025 */ 	or	$s0,$a0,$zero
/*    14cc8:	30d1ffff */ 	andi	$s1,$a2,0xffff
/*    14ccc:	00001825 */ 	or	$v1,$zero,$zero
/*    14cd0:	07010010 */ 	bgez	$t8,.L00014d14
/*    14cd4:	00001025 */ 	or	$v0,$zero,$zero
/*    14cd8:	3c198006 */ 	lui	$t9,0x8006
/*    14cdc:	9339eeac */ 	lbu	$t9,-0x1154($t9)
/*    14ce0:	00056880 */ 	sll	$t5,$a1,0x2
/*    14ce4:	00b95807 */ 	srav	$t3,$t9,$a1
/*    14ce8:	316c0001 */ 	andi	$t4,$t3,0x1
/*    14cec:	5580000a */ 	bnezl	$t4,.L00014d18
/*    14cf0:	0005c880 */ 	sll	$t9,$a1,0x2
/*    14cf4:	3c0e8006 */ 	lui	$t6,%hi(var8005ee8c)
/*    14cf8:	25ceee8c */ 	addiu	$t6,$t6,%lo(var8005ee8c)
/*    14cfc:	01ae1821 */ 	addu	$v1,$t5,$t6
/*    14d00:	8c6f0000 */ 	lw	$t7,0x0($v1)
/*    14d04:	00001025 */ 	or	$v0,$zero,$zero
/*    14d08:	25f80001 */ 	addiu	$t8,$t7,0x1
/*    14d0c:	1000003c */ 	beqz	$zero,.L00014e00
/*    14d10:	ac780000 */ 	sw	$t8,0x0($v1)
.L00014d14:
/*    14d14:	0005c880 */ 	sll	$t9,$a1,0x2
.L00014d18:
/*    14d18:	3c0b800a */ 	lui	$t3,0x800a
/*    14d1c:	01795821 */ 	addu	$t3,$t3,$t9
/*    14d20:	8d6b9e68 */ 	lw	$t3,-0x6198($t3)
/*    14d24:	59600004 */ 	blezl	$t3,.L00014d38
/*    14d28:	8cec01e4 */ 	lw	$t4,0x1e4($a3)
/*    14d2c:	10000034 */ 	beqz	$zero,.L00014e00
/*    14d30:	00001025 */ 	or	$v0,$zero,$zero
/*    14d34:	8cec01e4 */ 	lw	$t4,0x1e4($a3)
.L00014d38:
/*    14d38:	24090014 */ 	addiu	$t1,$zero,0x14
/*    14d3c:	8ce801e0 */ 	lw	$t0,0x1e0($a3)
/*    14d40:	258d0001 */ 	addiu	$t5,$t4,0x1
/*    14d44:	01a9001a */ 	div	$zero,$t5,$t1
/*    14d48:	00002010 */ 	mfhi	$a0
/*    14d4c:	240a0006 */ 	addiu	$t2,$zero,0x6
/*    14d50:	15200002 */ 	bnez	$t1,.L00014d5c
/*    14d54:	00000000 */ 	sll	$zero,$zero,0x0
/*    14d58:	0007000d */ 	break	0x7
.L00014d5c:
/*    14d5c:	2401ffff */ 	addiu	$at,$zero,-1
/*    14d60:	15210004 */ 	bne	$t1,$at,.L00014d74
/*    14d64:	3c018000 */ 	lui	$at,0x8000
/*    14d68:	15a10002 */ 	bne	$t5,$at,.L00014d74
/*    14d6c:	00000000 */ 	sll	$zero,$zero,0x0
/*    14d70:	0006000d */ 	break	0x6
.L00014d74:
/*    14d74:	12000005 */ 	beqz	$s0,.L00014d8c
/*    14d78:	00027080 */ 	sll	$t6,$v0,0x2
/*    14d7c:	020e7821 */ 	addu	$t7,$s0,$t6
/*    14d80:	8df80000 */ 	lw	$t8,0x0($t7)
/*    14d84:	1300000d */ 	beqz	$t8,.L00014dbc
/*    14d88:	00000000 */ 	sll	$zero,$zero,0x0
.L00014d8c:
/*    14d8c:	00aa0019 */ 	multu	$a1,$t2
/*    14d90:	0004c880 */ 	sll	$t9,$a0,0x2
/*    14d94:	0324c823 */ 	subu	$t9,$t9,$a0
/*    14d98:	0019c8c0 */ 	sll	$t9,$t9,0x3
/*    14d9c:	00f95821 */ 	addu	$t3,$a3,$t9
/*    14da0:	00006012 */ 	mflo	$t4
/*    14da4:	016c6821 */ 	addu	$t5,$t3,$t4
/*    14da8:	95a60000 */ 	lhu	$a2,0x0($t5)
/*    14dac:	00d17024 */ 	and	$t6,$a2,$s1
/*    14db0:	11c00002 */ 	beqz	$t6,.L00014dbc
/*    14db4:	00000000 */ 	sll	$zero,$zero,0x0
/*    14db8:	24630001 */ 	addiu	$v1,$v1,0x1
.L00014dbc:
/*    14dbc:	1088000f */ 	beq	$a0,$t0,.L00014dfc
/*    14dc0:	248f0001 */ 	addiu	$t7,$a0,0x1
/*    14dc4:	01e9001a */ 	div	$zero,$t7,$t1
/*    14dc8:	00002010 */ 	mfhi	$a0
/*    14dcc:	24420001 */ 	addiu	$v0,$v0,0x1
/*    14dd0:	15200002 */ 	bnez	$t1,.L00014ddc
/*    14dd4:	00000000 */ 	sll	$zero,$zero,0x0
/*    14dd8:	0007000d */ 	break	0x7
.L00014ddc:
/*    14ddc:	2401ffff */ 	addiu	$at,$zero,-1
/*    14de0:	15210004 */ 	bne	$t1,$at,.L00014df4
/*    14de4:	3c018000 */ 	lui	$at,0x8000
/*    14de8:	15e10002 */ 	bne	$t7,$at,.L00014df4
/*    14dec:	00000000 */ 	sll	$zero,$zero,0x0
/*    14df0:	0006000d */ 	break	0x6
.L00014df4:
/*    14df4:	1000ffdf */ 	beqz	$zero,.L00014d74
/*    14df8:	00000000 */ 	sll	$zero,$zero,0x0
.L00014dfc:
/*    14dfc:	00601025 */ 	or	$v0,$v1,$zero
.L00014e00:
/*    14e00:	8fb00008 */ 	lw	$s0,0x8($sp)
/*    14e04:	8fb1000c */ 	lw	$s1,0xc($sp)
/*    14e08:	03e00008 */ 	jr	$ra
/*    14e0c:	27bd0010 */ 	addiu	$sp,$sp,0x10
);

GLOBAL_ASM(
glabel func00014e10
/*    14e10:	3c038006 */ 	lui	$v1,0x8006
/*    14e14:	8c63ee60 */ 	lw	$v1,-0x11a0($v1)
/*    14e18:	afa40000 */ 	sw	$a0,0x0($sp)
/*    14e1c:	00047600 */ 	sll	$t6,$a0,0x18
/*    14e20:	8c780200 */ 	lw	$t8,0x200($v1)
/*    14e24:	000e7e03 */ 	sra	$t7,$t6,0x18
/*    14e28:	01e02025 */ 	or	$a0,$t7,$zero
/*    14e2c:	0701000e */ 	bgez	$t8,.L00014e68
/*    14e30:	3c198006 */ 	lui	$t9,0x8006
/*    14e34:	9339eeac */ 	lbu	$t9,-0x1154($t9)
/*    14e38:	3c0b8006 */ 	lui	$t3,%hi(var8005ee6c)
/*    14e3c:	256bee6c */ 	addiu	$t3,$t3,%lo(var8005ee6c)
/*    14e40:	01f94007 */ 	srav	$t0,$t9,$t7
/*    14e44:	31090001 */ 	andi	$t1,$t0,0x1
/*    14e48:	15200007 */ 	bnez	$t1,.L00014e68
/*    14e4c:	000f5080 */ 	sll	$t2,$t7,0x2
/*    14e50:	014b1821 */ 	addu	$v1,$t2,$t3
/*    14e54:	8c6c0000 */ 	lw	$t4,0x0($v1)
/*    14e58:	00001025 */ 	or	$v0,$zero,$zero
/*    14e5c:	258d0001 */ 	addiu	$t5,$t4,0x1
/*    14e60:	03e00008 */ 	jr	$ra
/*    14e64:	ac6d0000 */ 	sw	$t5,0x0($v1)
.L00014e68:
/*    14e68:	00047080 */ 	sll	$t6,$a0,0x2
/*    14e6c:	3c0f800a */ 	lui	$t7,0x800a
/*    14e70:	01ee7821 */ 	addu	$t7,$t7,$t6
/*    14e74:	8def9e68 */ 	lw	$t7,-0x6198($t7)
/*    14e78:	59e00004 */ 	blezl	$t7,.L00014e8c
/*    14e7c:	8c7801e0 */ 	lw	$t8,0x1e0($v1)
/*    14e80:	03e00008 */ 	jr	$ra
/*    14e84:	00001025 */ 	or	$v0,$zero,$zero
/*    14e88:	8c7801e0 */ 	lw	$t8,0x1e0($v1)
.L00014e8c:
/*    14e8c:	00044880 */ 	sll	$t1,$a0,0x2
/*    14e90:	01244823 */ 	subu	$t1,$t1,$a0
/*    14e94:	0018c880 */ 	sll	$t9,$t8,0x2
/*    14e98:	0338c823 */ 	subu	$t9,$t9,$t8
/*    14e9c:	0019c8c0 */ 	sll	$t9,$t9,0x3
/*    14ea0:	00794021 */ 	addu	$t0,$v1,$t9
/*    14ea4:	00094840 */ 	sll	$t1,$t1,0x1
/*    14ea8:	01095021 */ 	addu	$t2,$t0,$t1
/*    14eac:	81420002 */ 	lb	$v0,0x2($t2)
/*    14eb0:	03e00008 */ 	jr	$ra
/*    14eb4:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func00014eb8
/*    14eb8:	3c038006 */ 	lui	$v1,0x8006
/*    14ebc:	8c63ee60 */ 	lw	$v1,-0x11a0($v1)
/*    14ec0:	afa40000 */ 	sw	$a0,0x0($sp)
/*    14ec4:	00047600 */ 	sll	$t6,$a0,0x18
/*    14ec8:	8c780200 */ 	lw	$t8,0x200($v1)
/*    14ecc:	000e7e03 */ 	sra	$t7,$t6,0x18
/*    14ed0:	01e02025 */ 	or	$a0,$t7,$zero
/*    14ed4:	0701000e */ 	bgez	$t8,.L00014f10
/*    14ed8:	3c198006 */ 	lui	$t9,0x8006
/*    14edc:	9339eeac */ 	lbu	$t9,-0x1154($t9)
/*    14ee0:	3c0b8006 */ 	lui	$t3,%hi(var8005ee7c)
/*    14ee4:	256bee7c */ 	addiu	$t3,$t3,%lo(var8005ee7c)
/*    14ee8:	01f94007 */ 	srav	$t0,$t9,$t7
/*    14eec:	31090001 */ 	andi	$t1,$t0,0x1
/*    14ef0:	15200007 */ 	bnez	$t1,.L00014f10
/*    14ef4:	000f5080 */ 	sll	$t2,$t7,0x2
/*    14ef8:	014b1821 */ 	addu	$v1,$t2,$t3
/*    14efc:	8c6c0000 */ 	lw	$t4,0x0($v1)
/*    14f00:	00001025 */ 	or	$v0,$zero,$zero
/*    14f04:	258d0001 */ 	addiu	$t5,$t4,0x1
/*    14f08:	03e00008 */ 	jr	$ra
/*    14f0c:	ac6d0000 */ 	sw	$t5,0x0($v1)
.L00014f10:
/*    14f10:	00047080 */ 	sll	$t6,$a0,0x2
/*    14f14:	3c0f800a */ 	lui	$t7,0x800a
/*    14f18:	01ee7821 */ 	addu	$t7,$t7,$t6
/*    14f1c:	8def9e68 */ 	lw	$t7,-0x6198($t7)
/*    14f20:	59e00004 */ 	blezl	$t7,.L00014f34
/*    14f24:	8c7801e0 */ 	lw	$t8,0x1e0($v1)
/*    14f28:	03e00008 */ 	jr	$ra
/*    14f2c:	00001025 */ 	or	$v0,$zero,$zero
/*    14f30:	8c7801e0 */ 	lw	$t8,0x1e0($v1)
.L00014f34:
/*    14f34:	00044880 */ 	sll	$t1,$a0,0x2
/*    14f38:	01244823 */ 	subu	$t1,$t1,$a0
/*    14f3c:	0018c880 */ 	sll	$t9,$t8,0x2
/*    14f40:	0338c823 */ 	subu	$t9,$t9,$t8
/*    14f44:	0019c8c0 */ 	sll	$t9,$t9,0x3
/*    14f48:	00794021 */ 	addu	$t0,$v1,$t9
/*    14f4c:	00094840 */ 	sll	$t1,$t1,0x1
/*    14f50:	01095021 */ 	addu	$t2,$t0,$t1
/*    14f54:	81420003 */ 	lb	$v0,0x3($t2)
/*    14f58:	03e00008 */ 	jr	$ra
/*    14f5c:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func00014f60
/*    14f60:	3c038006 */ 	lui	$v1,0x8006
/*    14f64:	8c63ee60 */ 	lw	$v1,-0x11a0($v1)
/*    14f68:	afa40000 */ 	sw	$a0,0x0($sp)
/*    14f6c:	afa50004 */ 	sw	$a1,0x4($sp)
/*    14f70:	8c790200 */ 	lw	$t9,0x200($v1)
/*    14f74:	00047600 */ 	sll	$t6,$a0,0x18
/*    14f78:	000e7e03 */ 	sra	$t7,$t6,0x18
/*    14f7c:	30b8ffff */ 	andi	$t8,$a1,0xffff
/*    14f80:	03002825 */ 	or	$a1,$t8,$zero
/*    14f84:	0721000f */ 	bgez	$t9,.L00014fc4
/*    14f88:	01e02025 */ 	or	$a0,$t7,$zero
/*    14f8c:	3c088006 */ 	lui	$t0,0x8006
/*    14f90:	9108eeac */ 	lbu	$t0,-0x1154($t0)
/*    14f94:	3c0c8006 */ 	lui	$t4,%hi(var8005ee8c)
/*    14f98:	258cee8c */ 	addiu	$t4,$t4,%lo(var8005ee8c)
/*    14f9c:	01e84807 */ 	srav	$t1,$t0,$t7
/*    14fa0:	312a0001 */ 	andi	$t2,$t1,0x1
/*    14fa4:	15400007 */ 	bnez	$t2,.L00014fc4
/*    14fa8:	000f5880 */ 	sll	$t3,$t7,0x2
/*    14fac:	016c1821 */ 	addu	$v1,$t3,$t4
/*    14fb0:	8c6d0000 */ 	lw	$t5,0x0($v1)
/*    14fb4:	00001025 */ 	or	$v0,$zero,$zero
/*    14fb8:	25ae0001 */ 	addiu	$t6,$t5,0x1
/*    14fbc:	03e00008 */ 	jr	$ra
/*    14fc0:	ac6e0000 */ 	sw	$t6,0x0($v1)
.L00014fc4:
/*    14fc4:	00047880 */ 	sll	$t7,$a0,0x2
/*    14fc8:	3c18800a */ 	lui	$t8,0x800a
/*    14fcc:	030fc021 */ 	addu	$t8,$t8,$t7
/*    14fd0:	8f189e68 */ 	lw	$t8,-0x6198($t8)
/*    14fd4:	5b000004 */ 	blezl	$t8,.L00014fe8
/*    14fd8:	8c7901e0 */ 	lw	$t9,0x1e0($v1)
/*    14fdc:	03e00008 */ 	jr	$ra
/*    14fe0:	00001025 */ 	or	$v0,$zero,$zero
/*    14fe4:	8c7901e0 */ 	lw	$t9,0x1e0($v1)
.L00014fe8:
/*    14fe8:	00045080 */ 	sll	$t2,$a0,0x2
/*    14fec:	01445023 */ 	subu	$t2,$t2,$a0
/*    14ff0:	00194080 */ 	sll	$t0,$t9,0x2
/*    14ff4:	01194023 */ 	subu	$t0,$t0,$t9
/*    14ff8:	000840c0 */ 	sll	$t0,$t0,0x3
/*    14ffc:	00684821 */ 	addu	$t1,$v1,$t0
/*    15000:	000a5040 */ 	sll	$t2,$t2,0x1
/*    15004:	012a5821 */ 	addu	$t3,$t1,$t2
/*    15008:	956c0000 */ 	lhu	$t4,0x0($t3)
/*    1500c:	01851024 */ 	and	$v0,$t4,$a1
/*    15010:	304dffff */ 	andi	$t5,$v0,0xffff
/*    15014:	01a01025 */ 	or	$v0,$t5,$zero
/*    15018:	03e00008 */ 	jr	$ra
/*    1501c:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func00015020
/*    15020:	3c038006 */ 	lui	$v1,0x8006
/*    15024:	8c63ee60 */ 	lw	$v1,-0x11a0($v1)
/*    15028:	afa40000 */ 	sw	$a0,0x0($sp)
/*    1502c:	afa50004 */ 	sw	$a1,0x4($sp)
/*    15030:	8c790200 */ 	lw	$t9,0x200($v1)
/*    15034:	00047600 */ 	sll	$t6,$a0,0x18
/*    15038:	000e7e03 */ 	sra	$t7,$t6,0x18
/*    1503c:	30b8ffff */ 	andi	$t8,$a1,0xffff
/*    15040:	03002825 */ 	or	$a1,$t8,$zero
/*    15044:	0721000f */ 	bgez	$t9,.L00015084
/*    15048:	01e02025 */ 	or	$a0,$t7,$zero
/*    1504c:	3c088006 */ 	lui	$t0,0x8006
/*    15050:	9108eeac */ 	lbu	$t0,-0x1154($t0)
/*    15054:	3c0c8006 */ 	lui	$t4,%hi(var8005ee9c)
/*    15058:	258cee9c */ 	addiu	$t4,$t4,%lo(var8005ee9c)
/*    1505c:	01e84807 */ 	srav	$t1,$t0,$t7
/*    15060:	312a0001 */ 	andi	$t2,$t1,0x1
/*    15064:	15400007 */ 	bnez	$t2,.L00015084
/*    15068:	000f5880 */ 	sll	$t3,$t7,0x2
/*    1506c:	016c1821 */ 	addu	$v1,$t3,$t4
/*    15070:	8c6d0000 */ 	lw	$t5,0x0($v1)
/*    15074:	00001025 */ 	or	$v0,$zero,$zero
/*    15078:	25ae0001 */ 	addiu	$t6,$t5,0x1
/*    1507c:	03e00008 */ 	jr	$ra
/*    15080:	ac6e0000 */ 	sw	$t6,0x0($v1)
.L00015084:
/*    15084:	00047880 */ 	sll	$t7,$a0,0x2
/*    15088:	3c18800a */ 	lui	$t8,0x800a
/*    1508c:	030fc021 */ 	addu	$t8,$t8,$t7
/*    15090:	8f189e68 */ 	lw	$t8,-0x6198($t8)
/*    15094:	5b000004 */ 	blezl	$t8,.L000150a8
/*    15098:	0004c840 */ 	sll	$t9,$a0,0x1
/*    1509c:	03e00008 */ 	jr	$ra
/*    150a0:	00001025 */ 	or	$v0,$zero,$zero
/*    150a4:	0004c840 */ 	sll	$t9,$a0,0x1
.L000150a8:
/*    150a8:	00794021 */ 	addu	$t0,$v1,$t9
/*    150ac:	950901f0 */ 	lhu	$t1,0x1f0($t0)
/*    150b0:	01251024 */ 	and	$v0,$t1,$a1
/*    150b4:	304affff */ 	andi	$t2,$v0,0xffff
/*    150b8:	01401025 */ 	or	$v0,$t2,$zero
/*    150bc:	03e00008 */ 	jr	$ra
/*    150c0:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func000150c4
/*    150c4:	3c0e8006 */ 	lui	$t6,0x8006
/*    150c8:	8dceeebc */ 	lw	$t6,-0x1144($t6)
/*    150cc:	24030001 */ 	addiu	$v1,$zero,0x1
/*    150d0:	11c00003 */ 	beqz	$t6,.L000150e0
/*    150d4:	00000000 */ 	sll	$zero,$zero,0x0
/*    150d8:	03e00008 */ 	jr	$ra
/*    150dc:	00001025 */ 	or	$v0,$zero,$zero
.L000150e0:
/*    150e0:	03e00008 */ 	jr	$ra
/*    150e4:	00601025 */ 	or	$v0,$v1,$zero
);

GLOBAL_ASM(
glabel func000150e8
/*    150e8:	3c028006 */ 	lui	$v0,0x8006
/*    150ec:	8c42eebc */ 	lw	$v0,-0x1144($v0)
/*    150f0:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*    150f4:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    150f8:	1440000c */ 	bnez	$v0,.L0001512c
/*    150fc:	3c04800a */ 	lui	$a0,%hi(var80099ec0)
/*    15100:	24849ec0 */ 	addiu	$a0,$a0,%lo(var80099ec0)
/*    15104:	27a5001c */ 	addiu	$a1,$sp,0x1c
/*    15108:	0c012238 */ 	jal	func000488e0
/*    1510c:	00003025 */ 	or	$a2,$zero,$zero
/*    15110:	3c04800a */ 	lui	$a0,%hi(var80099ee0)
/*    15114:	24849ee0 */ 	addiu	$a0,$a0,%lo(var80099ee0)
/*    15118:	27a5001c */ 	addiu	$a1,$sp,0x1c
/*    1511c:	0c0121bc */ 	jal	func000486f0
/*    15120:	24060001 */ 	addiu	$a2,$zero,0x1
/*    15124:	3c028006 */ 	lui	$v0,0x8006
/*    15128:	8c42eebc */ 	lw	$v0,-0x1144($v0)
.L0001512c:
/*    1512c:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    15130:	244e0001 */ 	addiu	$t6,$v0,0x1
/*    15134:	3c018006 */ 	lui	$at,0x8006
/*    15138:	ac2eeebc */ 	sw	$t6,-0x1144($at)
/*    1513c:	03e00008 */ 	jr	$ra
/*    15140:	27bd0020 */ 	addiu	$sp,$sp,0x20
);

GLOBAL_ASM(
glabel func00015144
/*    15144:	3c028006 */ 	lui	$v0,%hi(var8005eebc)
/*    15148:	2442eebc */ 	addiu	$v0,$v0,%lo(var8005eebc)
/*    1514c:	8c4e0000 */ 	lw	$t6,0x0($v0)
/*    15150:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*    15154:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    15158:	25cfffff */ 	addiu	$t7,$t6,-1
/*    1515c:	15e0000b */ 	bnez	$t7,.L0001518c
/*    15160:	ac4f0000 */ 	sw	$t7,0x0($v0)
/*    15164:	3c04800a */ 	lui	$a0,%hi(var80099f00)
/*    15168:	24849f00 */ 	addiu	$a0,$a0,%lo(var80099f00)
/*    1516c:	27a5001c */ 	addiu	$a1,$sp,0x1c
/*    15170:	0c012238 */ 	jal	func000488e0
/*    15174:	00003025 */ 	or	$a2,$zero,$zero
/*    15178:	3c04800a */ 	lui	$a0,%hi(var80099f20)
/*    1517c:	24849f20 */ 	addiu	$a0,$a0,%lo(var80099f20)
/*    15180:	27a5001c */ 	addiu	$a1,$sp,0x1c
/*    15184:	0c0121bc */ 	jal	func000486f0
/*    15188:	24060001 */ 	addiu	$a2,$zero,0x1
.L0001518c:
/*    1518c:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    15190:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*    15194:	03e00008 */ 	jr	$ra
/*    15198:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0001519c
/*    1519c:	27bdffd0 */ 	addiu	$sp,$sp,-48
/*    151a0:	afb40028 */ 	sw	$s4,0x28($sp)
/*    151a4:	3c14800a */ 	lui	$s4,%hi(var80099e78)
/*    151a8:	26949e78 */ 	addiu	$s4,$s4,%lo(var80099e78)
/*    151ac:	afbf002c */ 	sw	$ra,0x2c($sp)
/*    151b0:	3c05800a */ 	lui	$a1,%hi(var80099e90)
/*    151b4:	afb30024 */ 	sw	$s3,0x24($sp)
/*    151b8:	afb20020 */ 	sw	$s2,0x20($sp)
/*    151bc:	afb1001c */ 	sw	$s1,0x1c($sp)
/*    151c0:	afb00018 */ 	sw	$s0,0x18($sp)
/*    151c4:	24a59e90 */ 	addiu	$a1,$a1,%lo(var80099e90)
/*    151c8:	02802025 */ 	or	$a0,$s4,$zero
/*    151cc:	0c0120d0 */ 	jal	func00048340
/*    151d0:	2406000a */ 	addiu	$a2,$zero,0xa
/*    151d4:	24040005 */ 	addiu	$a0,$zero,0x5
/*    151d8:	02802825 */ 	or	$a1,$s4,$zero
/*    151dc:	0c012148 */ 	jal	func00048520
/*    151e0:	00003025 */ 	or	$a2,$zero,$zero
/*    151e4:	3c12800a */ 	lui	$s2,%hi(var800a3180)
/*    151e8:	26523180 */ 	addiu	$s2,$s2,%lo(var800a3180)
/*    151ec:	00008025 */ 	or	$s0,$zero,$zero
/*    151f0:	24130068 */ 	addiu	$s3,$zero,0x68
/*    151f4:	24110004 */ 	addiu	$s1,$zero,0x4
.L000151f8:
/*    151f8:	16110003 */ 	bne	$s0,$s1,.L00015208
/*    151fc:	02802025 */ 	or	$a0,$s4,$zero
/*    15200:	10000005 */ 	beqz	$zero,.L00015218
/*    15204:	00003825 */ 	or	$a3,$zero,$zero
.L00015208:
/*    15208:	02130019 */ 	multu	$s0,$s3
/*    1520c:	00007012 */ 	mflo	$t6
/*    15210:	024e3821 */ 	addu	$a3,$s2,$t6
/*    15214:	00000000 */ 	sll	$zero,$zero,0x0
.L00015218:
/*    15218:	00e02825 */ 	or	$a1,$a3,$zero
/*    1521c:	0c013e15 */ 	jal	func0004f854
/*    15220:	02003025 */ 	or	$a2,$s0,$zero
/*    15224:	1440001f */ 	bnez	$v0,.L000152a4
/*    15228:	00002825 */ 	or	$a1,$zero,$zero
/*    1522c:	16110003 */ 	bne	$s0,$s1,.L0001523c
/*    15230:	00000000 */ 	sll	$zero,$zero,0x0
/*    15234:	10000005 */ 	beqz	$zero,.L0001524c
/*    15238:	00003825 */ 	or	$a3,$zero,$zero
.L0001523c:
/*    1523c:	02130019 */ 	multu	$s0,$s3
/*    15240:	00007812 */ 	mflo	$t7
/*    15244:	024f3821 */ 	addu	$a3,$s2,$t7
/*    15248:	00000000 */ 	sll	$zero,$zero,0x0
.L0001524c:
/*    1524c:	0c013d78 */ 	jal	func0004f5e0
/*    15250:	00e02025 */ 	or	$a0,$a3,$zero
/*    15254:	16110003 */ 	bne	$s0,$s1,.L00015264
/*    15258:	00002825 */ 	or	$a1,$zero,$zero
/*    1525c:	10000005 */ 	beqz	$zero,.L00015274
/*    15260:	00003825 */ 	or	$a3,$zero,$zero
.L00015264:
/*    15264:	02130019 */ 	multu	$s0,$s3
/*    15268:	0000c012 */ 	mflo	$t8
/*    1526c:	02583821 */ 	addu	$a3,$s2,$t8
/*    15270:	00000000 */ 	sll	$zero,$zero,0x0
.L00015274:
/*    15274:	0c013d78 */ 	jal	func0004f5e0
/*    15278:	00e02025 */ 	or	$a0,$a3,$zero
/*    1527c:	16110003 */ 	bne	$s0,$s1,.L0001528c
/*    15280:	00002825 */ 	or	$a1,$zero,$zero
/*    15284:	10000005 */ 	beqz	$zero,.L0001529c
/*    15288:	00003825 */ 	or	$a3,$zero,$zero
.L0001528c:
/*    1528c:	02130019 */ 	multu	$s0,$s3
/*    15290:	0000c812 */ 	mflo	$t9
/*    15294:	02593821 */ 	addu	$a3,$s2,$t9
/*    15298:	00000000 */ 	sll	$zero,$zero,0x0
.L0001529c:
/*    1529c:	0c013d78 */ 	jal	func0004f5e0
/*    152a0:	00e02025 */ 	or	$a0,$a3,$zero
.L000152a4:
/*    152a4:	26100001 */ 	addiu	$s0,$s0,0x1
/*    152a8:	1611ffd3 */ 	bne	$s0,$s1,.L000151f8
/*    152ac:	00000000 */ 	sll	$zero,$zero,0x0
/*    152b0:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*    152b4:	8fb00018 */ 	lw	$s0,0x18($sp)
/*    152b8:	8fb1001c */ 	lw	$s1,0x1c($sp)
/*    152bc:	8fb20020 */ 	lw	$s2,0x20($sp)
/*    152c0:	8fb30024 */ 	lw	$s3,0x24($sp)
/*    152c4:	8fb40028 */ 	lw	$s4,0x28($sp)
/*    152c8:	03e00008 */ 	jr	$ra
/*    152cc:	27bd0030 */ 	addiu	$sp,$sp,0x30
);

GLOBAL_ASM(
glabel func000152d0
/*    152d0:	3c07800a */ 	lui	$a3,%hi(g_Vars)
/*    152d4:	24e79fc0 */ 	addiu	$a3,$a3,%lo(g_Vars)
/*    152d8:	8cf80318 */ 	lw	$t8,0x318($a3)
/*    152dc:	00047600 */ 	sll	$t6,$a0,0x18
/*    152e0:	000e7e03 */ 	sra	$t7,$t6,0x18
/*    152e4:	afa40000 */ 	sw	$a0,0x0($sp)
/*    152e8:	13000008 */ 	beqz	$t8,.L0001530c
/*    152ec:	01e02025 */ 	or	$a0,$t7,$zero
/*    152f0:	000fc9c0 */ 	sll	$t9,$t7,0x7
/*    152f4:	00f94021 */ 	addu	$t0,$a3,$t9
/*    152f8:	8d0900e4 */ 	lw	$t1,0xe4($t0)
/*    152fc:	240affff */ 	addiu	$t2,$zero,-1
/*    15300:	aca90000 */ 	sw	$t1,0x0($a1)
/*    15304:	03e00008 */ 	jr	$ra
/*    15308:	acca0000 */ 	sw	$t2,0x0($a2)
.L0001530c:
/*    1530c:	000459c0 */ 	sll	$t3,$a0,0x7
/*    15310:	aca40000 */ 	sw	$a0,0x0($a1)
/*    15314:	00eb6021 */ 	addu	$t4,$a3,$t3
/*    15318:	8d8d00e4 */ 	lw	$t5,0xe4($t4)
/*    1531c:	3c0f800b */ 	lui	$t7,0x800b
/*    15320:	000d7080 */ 	sll	$t6,$t5,0x2
/*    15324:	01cd7021 */ 	addu	$t6,$t6,$t5
/*    15328:	000e7140 */ 	sll	$t6,$t6,0x5
/*    1532c:	01ee7821 */ 	addu	$t7,$t7,$t6
/*    15330:	91efc7fc */ 	lbu	$t7,-0x3804($t7)
/*    15334:	240effff */ 	addiu	$t6,$zero,-1
/*    15338:	29e10004 */ 	slti	$at,$t7,0x4
/*    1533c:	5420001f */ 	bnezl	$at,.L000153bc
/*    15340:	acce0000 */ 	sw	$t6,0x0($a2)
/*    15344:	8cf8006c */ 	lw	$t8,0x6c($a3)
/*    15348:	00001025 */ 	or	$v0,$zero,$zero
/*    1534c:	00001825 */ 	or	$v1,$zero,$zero
/*    15350:	13000003 */ 	beqz	$t8,.L00015360
/*    15354:	00002825 */ 	or	$a1,$zero,$zero
/*    15358:	10000001 */ 	beqz	$zero,.L00015360
/*    1535c:	24020001 */ 	addiu	$v0,$zero,0x1
.L00015360:
/*    15360:	8cf90068 */ 	lw	$t9,0x68($a3)
/*    15364:	13200003 */ 	beqz	$t9,.L00015374
/*    15368:	00000000 */ 	sll	$zero,$zero,0x0
/*    1536c:	10000001 */ 	beqz	$zero,.L00015374
/*    15370:	24030001 */ 	addiu	$v1,$zero,0x1
.L00015374:
/*    15374:	8ce80064 */ 	lw	$t0,0x64($a3)
/*    15378:	11000003 */ 	beqz	$t0,.L00015388
/*    1537c:	00000000 */ 	sll	$zero,$zero,0x0
/*    15380:	10000001 */ 	beqz	$zero,.L00015388
/*    15384:	24050001 */ 	addiu	$a1,$zero,0x1
.L00015388:
/*    15388:	8ce90070 */ 	lw	$t1,0x70($a3)
/*    1538c:	00003825 */ 	or	$a3,$zero,$zero
/*    15390:	11200003 */ 	beqz	$t1,.L000153a0
/*    15394:	00000000 */ 	sll	$zero,$zero,0x0
/*    15398:	10000001 */ 	beqz	$zero,.L000153a0
/*    1539c:	24070001 */ 	addiu	$a3,$zero,0x1
.L000153a0:
/*    153a0:	00e55021 */ 	addu	$t2,$a3,$a1
/*    153a4:	01435821 */ 	addu	$t3,$t2,$v1
/*    153a8:	01626021 */ 	addu	$t4,$t3,$v0
/*    153ac:	01846821 */ 	addu	$t5,$t4,$a0
/*    153b0:	03e00008 */ 	jr	$ra
/*    153b4:	accd0000 */ 	sw	$t5,0x0($a2)
/*    153b8:	acce0000 */ 	sw	$t6,0x0($a2)
.L000153bc:
/*    153bc:	03e00008 */ 	jr	$ra
/*    153c0:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func000153c4
/*    153c4:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*    153c8:	00043600 */ 	sll	$a2,$a0,0x18
/*    153cc:	00067603 */ 	sra	$t6,$a2,0x18
/*    153d0:	24010004 */ 	addiu	$at,$zero,0x4
/*    153d4:	01c03025 */ 	or	$a2,$t6,$zero
/*    153d8:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    153dc:	afa40028 */ 	sw	$a0,0x28($sp)
/*    153e0:	11c10070 */ 	beq	$t6,$at,.L000155a4
/*    153e4:	afa5002c */ 	sw	$a1,0x2c($sp)
/*    153e8:	000e7880 */ 	sll	$t7,$t6,0x2
/*    153ec:	01ee7823 */ 	subu	$t7,$t7,$t6
/*    153f0:	000f7880 */ 	sll	$t7,$t7,0x2
/*    153f4:	01ee7823 */ 	subu	$t7,$t7,$t6
/*    153f8:	000f7880 */ 	sll	$t7,$t7,0x2
/*    153fc:	01ee7821 */ 	addu	$t7,$t7,$t6
/*    15400:	000f7880 */ 	sll	$t7,$t7,0x2
/*    15404:	01ee7823 */ 	subu	$t7,$t7,$t6
/*    15408:	3c18800a */ 	lui	$t8,%hi(var800a2380)
/*    1540c:	27182380 */ 	addiu	$t8,$t8,%lo(var800a2380)
/*    15410:	000f7880 */ 	sll	$t7,$t7,0x2
/*    15414:	01f8c821 */ 	addu	$t9,$t7,$t8
/*    15418:	afb9001c */ 	sw	$t9,0x1c($sp)
/*    1541c:	8f220000 */ 	lw	$v0,0x0($t9)
/*    15420:	24010002 */ 	addiu	$at,$zero,0x2
/*    15424:	1041005f */ 	beq	$v0,$at,.L000155a4
/*    15428:	24010003 */ 	addiu	$at,$zero,0x3
/*    1542c:	5041005e */ 	beql	$v0,$at,.L000155a8
/*    15430:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    15434:	50a00005 */ 	beqzl	$a1,.L0001544c
/*    15438:	24010004 */ 	addiu	$at,$zero,0x4
/*    1543c:	0c00543a */ 	jal	func000150e8
/*    15440:	a3ae002b */ 	sb	$t6,0x2b($sp)
/*    15444:	83a6002b */ 	lb	$a2,0x2b($sp)
/*    15448:	24010004 */ 	addiu	$at,$zero,0x4
.L0001544c:
/*    1544c:	14c10003 */ 	bne	$a2,$at,.L0001545c
/*    15450:	3c04800a */ 	lui	$a0,%hi(var80099e78)
/*    15454:	10000009 */ 	beqz	$zero,.L0001547c
/*    15458:	00003825 */ 	or	$a3,$zero,$zero
.L0001545c:
/*    1545c:	00064880 */ 	sll	$t1,$a2,0x2
/*    15460:	01264823 */ 	subu	$t1,$t1,$a2
/*    15464:	00094880 */ 	sll	$t1,$t1,0x2
/*    15468:	01264821 */ 	addu	$t1,$t1,$a2
/*    1546c:	3c0a800a */ 	lui	$t2,%hi(var800a3180)
/*    15470:	254a3180 */ 	addiu	$t2,$t2,%lo(var800a3180)
/*    15474:	000948c0 */ 	sll	$t1,$t1,0x3
/*    15478:	012a3821 */ 	addu	$a3,$t1,$t2
.L0001547c:
/*    1547c:	24849e78 */ 	addiu	$a0,$a0,%lo(var80099e78)
/*    15480:	00e02825 */ 	or	$a1,$a3,$zero
/*    15484:	0c013e15 */ 	jal	func0004f854
/*    15488:	a3a6002b */ 	sb	$a2,0x2b($sp)
/*    1548c:	14400034 */ 	bnez	$v0,.L00015560
/*    15490:	83a6002b */ 	lb	$a2,0x2b($sp)
/*    15494:	24010004 */ 	addiu	$at,$zero,0x4
/*    15498:	14c10003 */ 	bne	$a2,$at,.L000154a8
/*    1549c:	00002825 */ 	or	$a1,$zero,$zero
/*    154a0:	10000009 */ 	beqz	$zero,.L000154c8
/*    154a4:	00003825 */ 	or	$a3,$zero,$zero
.L000154a8:
/*    154a8:	00065880 */ 	sll	$t3,$a2,0x2
/*    154ac:	01665823 */ 	subu	$t3,$t3,$a2
/*    154b0:	000b5880 */ 	sll	$t3,$t3,0x2
/*    154b4:	01665821 */ 	addu	$t3,$t3,$a2
/*    154b8:	3c0c800a */ 	lui	$t4,%hi(var800a3180)
/*    154bc:	258c3180 */ 	addiu	$t4,$t4,%lo(var800a3180)
/*    154c0:	000b58c0 */ 	sll	$t3,$t3,0x3
/*    154c4:	016c3821 */ 	addu	$a3,$t3,$t4
.L000154c8:
/*    154c8:	00e02025 */ 	or	$a0,$a3,$zero
/*    154cc:	0c013d78 */ 	jal	func0004f5e0
/*    154d0:	a3a6002b */ 	sb	$a2,0x2b($sp)
/*    154d4:	83a6002b */ 	lb	$a2,0x2b($sp)
/*    154d8:	24010004 */ 	addiu	$at,$zero,0x4
/*    154dc:	00002825 */ 	or	$a1,$zero,$zero
/*    154e0:	14c10003 */ 	bne	$a2,$at,.L000154f0
/*    154e4:	00066880 */ 	sll	$t5,$a2,0x2
/*    154e8:	10000008 */ 	beqz	$zero,.L0001550c
/*    154ec:	00003825 */ 	or	$a3,$zero,$zero
.L000154f0:
/*    154f0:	01a66823 */ 	subu	$t5,$t5,$a2
/*    154f4:	000d6880 */ 	sll	$t5,$t5,0x2
/*    154f8:	01a66821 */ 	addu	$t5,$t5,$a2
/*    154fc:	3c0e800a */ 	lui	$t6,%hi(var800a3180)
/*    15500:	25ce3180 */ 	addiu	$t6,$t6,%lo(var800a3180)
/*    15504:	000d68c0 */ 	sll	$t5,$t5,0x3
/*    15508:	01ae3821 */ 	addu	$a3,$t5,$t6
.L0001550c:
/*    1550c:	00e02025 */ 	or	$a0,$a3,$zero
/*    15510:	0c013d78 */ 	jal	func0004f5e0
/*    15514:	a3a6002b */ 	sb	$a2,0x2b($sp)
/*    15518:	83a6002b */ 	lb	$a2,0x2b($sp)
/*    1551c:	24010004 */ 	addiu	$at,$zero,0x4
/*    15520:	00002825 */ 	or	$a1,$zero,$zero
/*    15524:	14c10003 */ 	bne	$a2,$at,.L00015534
/*    15528:	00067880 */ 	sll	$t7,$a2,0x2
/*    1552c:	10000008 */ 	beqz	$zero,.L00015550
/*    15530:	00003825 */ 	or	$a3,$zero,$zero
.L00015534:
/*    15534:	01e67823 */ 	subu	$t7,$t7,$a2
/*    15538:	000f7880 */ 	sll	$t7,$t7,0x2
/*    1553c:	01e67821 */ 	addu	$t7,$t7,$a2
/*    15540:	3c18800a */ 	lui	$t8,%hi(var800a3180)
/*    15544:	27183180 */ 	addiu	$t8,$t8,%lo(var800a3180)
/*    15548:	000f78c0 */ 	sll	$t7,$t7,0x3
/*    1554c:	01f83821 */ 	addu	$a3,$t7,$t8
.L00015550:
/*    15550:	00e02025 */ 	or	$a0,$a3,$zero
/*    15554:	0c013d78 */ 	jal	func0004f5e0
/*    15558:	a3a6002b */ 	sb	$a2,0x2b($sp)
/*    1555c:	83a6002b */ 	lb	$a2,0x2b($sp)
.L00015560:
/*    15560:	8fb9002c */ 	lw	$t9,0x2c($sp)
/*    15564:	53200004 */ 	beqzl	$t9,.L00015578
/*    15568:	8fa3001c */ 	lw	$v1,0x1c($sp)
/*    1556c:	0c005451 */ 	jal	func00015144
/*    15570:	a3a6002b */ 	sb	$a2,0x2b($sp)
/*    15574:	8fa3001c */ 	lw	$v1,0x1c($sp)
.L00015578:
/*    15578:	24010006 */ 	addiu	$at,$zero,0x6
/*    1557c:	8c620004 */ 	lw	$v0,0x4($v1)
/*    15580:	10410004 */ 	beq	$v0,$at,.L00015594
/*    15584:	24010007 */ 	addiu	$at,$zero,0x7
/*    15588:	10410002 */ 	beq	$v0,$at,.L00015594
/*    1558c:	24080005 */ 	addiu	$t0,$zero,0x5
/*    15590:	ac680004 */ 	sw	$t0,0x4($v1)
.L00015594:
/*    15594:	3c01bf80 */ 	lui	$at,0xbf80
/*    15598:	44812000 */ 	mtc1	$at,$f4
/*    1559c:	00000000 */ 	sll	$zero,$zero,0x0
/*    155a0:	e46402b4 */ 	swc1	$f4,0x2b4($v1)
.L000155a4:
/*    155a4:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L000155a8:
/*    155a8:	27bd0028 */ 	addiu	$sp,$sp,0x28
/*    155ac:	03e00008 */ 	jr	$ra
/*    155b0:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func000155b4
/*    155b4:	00047600 */ 	sll	$t6,$a0,0x18
/*    155b8:	000e7e03 */ 	sra	$t7,$t6,0x18
/*    155bc:	000fc080 */ 	sll	$t8,$t7,0x2
/*    155c0:	030fc023 */ 	subu	$t8,$t8,$t7
/*    155c4:	0018c080 */ 	sll	$t8,$t8,0x2
/*    155c8:	030fc023 */ 	subu	$t8,$t8,$t7
/*    155cc:	0018c080 */ 	sll	$t8,$t8,0x2
/*    155d0:	030fc021 */ 	addu	$t8,$t8,$t7
/*    155d4:	0018c080 */ 	sll	$t8,$t8,0x2
/*    155d8:	030fc023 */ 	subu	$t8,$t8,$t7
/*    155dc:	0018c080 */ 	sll	$t8,$t8,0x2
/*    155e0:	3c02800a */ 	lui	$v0,0x800a
/*    155e4:	00581021 */ 	addu	$v0,$v0,$t8
/*    155e8:	afa40000 */ 	sw	$a0,0x0($sp)
/*    155ec:	03e00008 */ 	jr	$ra
/*    155f0:	8c422390 */ 	lw	$v0,0x2390($v0)
);

GLOBAL_ASM(
glabel func000155f4
/*    155f4:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*    155f8:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    155fc:	afa40018 */ 	sw	$a0,0x18($sp)
/*    15600:	00047600 */ 	sll	$t6,$a0,0x18
/*    15604:	0c00556d */ 	jal	func000155b4
/*    15608:	000e2603 */ 	sra	$a0,$t6,0x18
/*    1560c:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    15610:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*    15614:	03e00008 */ 	jr	$ra
/*    15618:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0001561c
/*    1561c:	27bdffd0 */ 	addiu	$sp,$sp,-48
/*    15620:	afb30020 */ 	sw	$s3,0x20($sp)
/*    15624:	afb00014 */ 	sw	$s0,0x14($sp)
/*    15628:	afb50028 */ 	sw	$s5,0x28($sp)
/*    1562c:	afb40024 */ 	sw	$s4,0x24($sp)
/*    15630:	afb2001c */ 	sw	$s2,0x1c($sp)
/*    15634:	afb10018 */ 	sw	$s1,0x18($sp)
/*    15638:	3c10800a */ 	lui	$s0,%hi(var800a2380)
/*    1563c:	3c13800a */ 	lui	$s3,%hi(var800a3180)
/*    15640:	afbf002c */ 	sw	$ra,0x2c($sp)
/*    15644:	26733180 */ 	addiu	$s3,$s3,%lo(var800a3180)
/*    15648:	26102380 */ 	addiu	$s0,$s0,%lo(var800a2380)
/*    1564c:	00008825 */ 	or	$s1,$zero,$zero
/*    15650:	24120004 */ 	addiu	$s2,$zero,0x4
/*    15654:	24140068 */ 	addiu	$s4,$zero,0x68
/*    15658:	24150002 */ 	addiu	$s5,$zero,0x2
.L0001565c:
/*    1565c:	8e0e0010 */ 	lw	$t6,0x10($s0)
/*    15660:	2401000b */ 	addiu	$at,$zero,0xb
/*    15664:	55c1006e */ 	bnel	$t6,$at,.L00015820
/*    15668:	26310001 */ 	addiu	$s1,$s1,0x1
/*    1566c:	8e0f0000 */ 	lw	$t7,0x0($s0)
/*    15670:	24010001 */ 	addiu	$at,$zero,0x1
/*    15674:	55e1006a */ 	bnel	$t7,$at,.L00015820
/*    15678:	26310001 */ 	addiu	$s1,$s1,0x1
/*    1567c:	8e180004 */ 	lw	$t8,0x4($s0)
/*    15680:	2719fffd */ 	addiu	$t9,$t8,-3
/*    15684:	2f210006 */ 	sltiu	$at,$t9,0x6
/*    15688:	10200064 */ 	beqz	$at,.L0001581c
/*    1568c:	0019c880 */ 	sll	$t9,$t9,0x2
/*    15690:	3c017005 */ 	lui	$at,%hi(var700541e4)
/*    15694:	00390821 */ 	addu	$at,$at,$t9
/*    15698:	8c3941e4 */ 	lw	$t9,%lo(var700541e4)($at)
/*    1569c:	03200008 */ 	jr	$t9
/*    156a0:	00000000 */ 	sll	$zero,$zero,0x0
/*    156a4:	24080004 */ 	addiu	$t0,$zero,0x4
/*    156a8:	16320003 */ 	bne	$s1,$s2,.L000156b8
/*    156ac:	ae080004 */ 	sw	$t0,0x4($s0)
/*    156b0:	10000005 */ 	beqz	$zero,.L000156c8
/*    156b4:	00002025 */ 	or	$a0,$zero,$zero
.L000156b8:
/*    156b8:	02340019 */ 	multu	$s1,$s4
/*    156bc:	00004812 */ 	mflo	$t1
/*    156c0:	02692021 */ 	addu	$a0,$s3,$t1
/*    156c4:	00000000 */ 	sll	$zero,$zero,0x0
.L000156c8:
/*    156c8:	0c013d78 */ 	jal	func0004f5e0
/*    156cc:	24050001 */ 	addiu	$a1,$zero,0x1
/*    156d0:	10000053 */ 	beqz	$zero,.L00015820
/*    156d4:	26310001 */ 	addiu	$s1,$s1,0x1
/*    156d8:	8e030284 */ 	lw	$v1,0x284($s0)
/*    156dc:	2401ffff */ 	addiu	$at,$zero,-1
/*    156e0:	50610024 */ 	beql	$v1,$at,.L00015774
/*    156e4:	3c013f80 */ 	lui	$at,0x3f80
/*    156e8:	8e02028c */ 	lw	$v0,0x28c($s0)
/*    156ec:	1440000d */ 	bnez	$v0,.L00015724
/*    156f0:	00000000 */ 	sll	$zero,$zero,0x0
/*    156f4:	16320003 */ 	bne	$s1,$s2,.L00015704
/*    156f8:	00000000 */ 	sll	$zero,$zero,0x0
/*    156fc:	10000005 */ 	beqz	$zero,.L00015714
/*    15700:	00002025 */ 	or	$a0,$zero,$zero
.L00015704:
/*    15704:	02340019 */ 	multu	$s1,$s4
/*    15708:	00005012 */ 	mflo	$t2
/*    1570c:	026a2021 */ 	addu	$a0,$s3,$t2
/*    15710:	00000000 */ 	sll	$zero,$zero,0x0
.L00015714:
/*    15714:	0c013d78 */ 	jal	func0004f5e0
/*    15718:	24050001 */ 	addiu	$a1,$zero,0x1
/*    1571c:	1000000e */ 	beqz	$zero,.L00015758
/*    15720:	8e02028c */ 	lw	$v0,0x28c($s0)
.L00015724:
/*    15724:	5462000d */ 	bnel	$v1,$v0,.L0001575c
/*    15728:	8e0d0288 */ 	lw	$t5,0x288($s0)
/*    1572c:	16320003 */ 	bne	$s1,$s2,.L0001573c
/*    15730:	00000000 */ 	sll	$zero,$zero,0x0
/*    15734:	10000005 */ 	beqz	$zero,.L0001574c
/*    15738:	00002025 */ 	or	$a0,$zero,$zero
.L0001573c:
/*    1573c:	02340019 */ 	multu	$s1,$s4
/*    15740:	00005812 */ 	mflo	$t3
/*    15744:	026b2021 */ 	addu	$a0,$s3,$t3
/*    15748:	00000000 */ 	sll	$zero,$zero,0x0
.L0001574c:
/*    1574c:	0c013d78 */ 	jal	func0004f5e0
/*    15750:	00002825 */ 	or	$a1,$zero,$zero
/*    15754:	8e02028c */ 	lw	$v0,0x28c($s0)
.L00015758:
/*    15758:	8e0d0288 */ 	lw	$t5,0x288($s0)
.L0001575c:
/*    1575c:	244c0001 */ 	addiu	$t4,$v0,0x1
/*    15760:	ae0c028c */ 	sw	$t4,0x28c($s0)
/*    15764:	55ac0003 */ 	bnel	$t5,$t4,.L00015774
/*    15768:	3c013f80 */ 	lui	$at,0x3f80
/*    1576c:	ae00028c */ 	sw	$zero,0x28c($s0)
/*    15770:	3c013f80 */ 	lui	$at,0x3f80
.L00015774:
/*    15774:	44813000 */ 	mtc1	$at,$f6
/*    15778:	c60402b4 */ 	lwc1	$f4,0x2b4($s0)
/*    1577c:	44808000 */ 	mtc1	$zero,$f16
/*    15780:	240f0005 */ 	addiu	$t7,$zero,0x5
/*    15784:	46062201 */ 	sub.s	$f8,$f4,$f6
/*    15788:	e60802b4 */ 	swc1	$f8,0x2b4($s0)
/*    1578c:	c60a02b4 */ 	lwc1	$f10,0x2b4($s0)
/*    15790:	4610503c */ 	c.lt.s	$f10,$f16
/*    15794:	00000000 */ 	sll	$zero,$zero,0x0
/*    15798:	45020021 */ 	bc1fl	.L00015820
/*    1579c:	26310001 */ 	addiu	$s1,$s1,0x1
/*    157a0:	1000001e */ 	beqz	$zero,.L0001581c
/*    157a4:	ae0f0004 */ 	sw	$t7,0x4($s0)
/*    157a8:	16320003 */ 	bne	$s1,$s2,.L000157b8
/*    157ac:	ae150004 */ 	sw	$s5,0x4($s0)
/*    157b0:	10000005 */ 	beqz	$zero,.L000157c8
/*    157b4:	00002025 */ 	or	$a0,$zero,$zero
.L000157b8:
/*    157b8:	02340019 */ 	multu	$s1,$s4
/*    157bc:	0000c012 */ 	mflo	$t8
/*    157c0:	02782021 */ 	addu	$a0,$s3,$t8
/*    157c4:	00000000 */ 	sll	$zero,$zero,0x0
.L000157c8:
/*    157c8:	0c013d78 */ 	jal	func0004f5e0
/*    157cc:	00002825 */ 	or	$a1,$zero,$zero
/*    157d0:	10000013 */ 	beqz	$zero,.L00015820
/*    157d4:	26310001 */ 	addiu	$s1,$s1,0x1
/*    157d8:	16320003 */ 	bne	$s1,$s2,.L000157e8
/*    157dc:	00000000 */ 	sll	$zero,$zero,0x0
/*    157e0:	10000005 */ 	beqz	$zero,.L000157f8
/*    157e4:	00002025 */ 	or	$a0,$zero,$zero
.L000157e8:
/*    157e8:	02340019 */ 	multu	$s1,$s4
/*    157ec:	0000c812 */ 	mflo	$t9
/*    157f0:	02792021 */ 	addu	$a0,$s3,$t9
/*    157f4:	00000000 */ 	sll	$zero,$zero,0x0
.L000157f8:
/*    157f8:	0c013d78 */ 	jal	func0004f5e0
/*    157fc:	00002825 */ 	or	$a1,$zero,$zero
/*    15800:	24080007 */ 	addiu	$t0,$zero,0x7
/*    15804:	10000005 */ 	beqz	$zero,.L0001581c
/*    15808:	ae080004 */ 	sw	$t0,0x4($s0)
/*    1580c:	3c01bf80 */ 	lui	$at,0xbf80
/*    15810:	44819000 */ 	mtc1	$at,$f18
/*    15814:	ae150004 */ 	sw	$s5,0x4($s0)
/*    15818:	e61202b4 */ 	swc1	$f18,0x2b4($s0)
.L0001581c:
/*    1581c:	26310001 */ 	addiu	$s1,$s1,0x1
.L00015820:
/*    15820:	1632ff8e */ 	bne	$s1,$s2,.L0001565c
/*    15824:	261002cc */ 	addiu	$s0,$s0,0x2cc
/*    15828:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*    1582c:	8fb00014 */ 	lw	$s0,0x14($sp)
/*    15830:	8fb10018 */ 	lw	$s1,0x18($sp)
/*    15834:	8fb2001c */ 	lw	$s2,0x1c($sp)
/*    15838:	8fb30020 */ 	lw	$s3,0x20($sp)
/*    1583c:	8fb40024 */ 	lw	$s4,0x24($sp)
/*    15840:	8fb50028 */ 	lw	$s5,0x28($sp)
/*    15844:	03e00008 */ 	jr	$ra
/*    15848:	27bd0030 */ 	addiu	$sp,$sp,0x30
/*    1584c:	00000000 */ 	sll	$zero,$zero,0x0
/*    15850:	03e00008 */ 	jr	$ra
/*    15854:	00000000 */ 	sll	$zero,$zero,0x0
/*    15858:	00000000 */ 	sll	$zero,$zero,0x0
/*    1585c:	00000000 */ 	sll	$zero,$zero,0x0
);
