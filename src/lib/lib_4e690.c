#include <ultra64.h>
#include "constants.h"
#include "game/data/data_000000.h"
#include "game/data/data_0083d0.h"
#include "game/data/data_0160b0.h"
#include "game/data/data_020df0.h"
#include "gvars/gvars.h"
#include "lib/lib_04a80.h"
#include "lib/lib_4a5e0.h"
#include "lib/lib_4e690.h"
#include "lib/lib_52070.h"
#include "types.h"

GLOBAL_ASM(
glabel func0004e690
/*    4e690:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*    4e694:	afa50020 */ 	sw	$a1,0x20($sp)
/*    4e698:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    4e69c:	30ae00ff */ 	andi	$t6,$a1,0xff
/*    4e6a0:	29c10026 */ 	slti	$at,$t6,0x26
/*    4e6a4:	01c02825 */ 	or	$a1,$t6,$zero
/*    4e6a8:	ae00000c */ 	sw	$zero,0xc($s0)
/*    4e6ac:	ae000010 */ 	sw	$zero,0x10($s0)
/*    4e6b0:	ae000014 */ 	sw	$zero,0x14($s0)
/*    4e6b4:	ae000018 */ 	sw	$zero,0x18($s0)
/*    4e6b8:	ae00001c */ 	sw	$zero,0x1c($s0)
/*    4e6bc:	ae000020 */ 	sw	$zero,0x20($s0)
/*    4e6c0:	1420000a */ 	bnez	$at,.L0004e6ec
/*    4e6c4:	01c01825 */ 	or	$v1,$t6,$zero
/*    4e6c8:	25cfffbb */ 	addiu	$t7,$t6,-69
/*    4e6cc:	2de10034 */ 	sltiu	$at,$t7,0x34
/*    4e6d0:	10200181 */ 	beqz	$at,.L0004ecd8
/*    4e6d4:	000f7880 */ 	sll	$t7,$t7,0x2
/*    4e6d8:	3c017006 */ 	lui	$at,0x7006
/*    4e6dc:	002f0821 */ 	addu	$at,$at,$t7
/*    4e6e0:	8c2f9ef4 */ 	lw	$t7,-0x610c($at)
/*    4e6e4:	01e00008 */ 	jr	$t7
/*    4e6e8:	00000000 */ 	sll	$zero,$zero,0x0
.L0004e6ec:
/*    4e6ec:	24010025 */ 	addiu	$at,$zero,0x25
/*    4e6f0:	50610172 */ 	beql	$v1,$at,.L0004ecbc
/*    4e6f4:	8e18000c */ 	lw	$t8,0xc($s0)
/*    4e6f8:	10000178 */ 	beqz	$zero,.L0004ecdc
/*    4e6fc:	8e0e000c */ 	lw	$t6,0xc($s0)
/*    4e700:	8cd80000 */ 	lw	$t8,0x0($a2)
/*    4e704:	2401fffc */ 	addiu	$at,$zero,-4
/*    4e708:	27190003 */ 	addiu	$t9,$t8,0x3
/*    4e70c:	03217024 */ 	and	$t6,$t9,$at
/*    4e710:	25cf0004 */ 	addiu	$t7,$t6,0x4
/*    4e714:	accf0000 */ 	sw	$t7,0x0($a2)
/*    4e718:	8e0e000c */ 	lw	$t6,0xc($s0)
/*    4e71c:	8df9fffc */ 	lw	$t9,-0x4($t7)
/*    4e720:	00ee7821 */ 	addu	$t7,$a3,$t6
/*    4e724:	a1f90000 */ 	sb	$t9,0x0($t7)
/*    4e728:	8e18000c */ 	lw	$t8,0xc($s0)
/*    4e72c:	270e0001 */ 	addiu	$t6,$t8,0x1
/*    4e730:	1000016f */ 	beqz	$zero,.L0004ecf0
/*    4e734:	ae0e000c */ 	sw	$t6,0xc($s0)
/*    4e738:	92020034 */ 	lbu	$v0,0x34($s0)
/*    4e73c:	2401006c */ 	addiu	$at,$zero,0x6c
/*    4e740:	5441000d */ 	bnel	$v0,$at,.L0004e778
/*    4e744:	2401004c */ 	addiu	$at,$zero,0x4c
/*    4e748:	8cd90000 */ 	lw	$t9,0x0($a2)
/*    4e74c:	2401fffc */ 	addiu	$at,$zero,-4
/*    4e750:	272f0003 */ 	addiu	$t7,$t9,0x3
/*    4e754:	01e1c024 */ 	and	$t8,$t7,$at
/*    4e758:	270e0004 */ 	addiu	$t6,$t8,0x4
/*    4e75c:	acce0000 */ 	sw	$t6,0x0($a2)
/*    4e760:	8dcffffc */ 	lw	$t7,-0x4($t6)
/*    4e764:	000fc7c3 */ 	sra	$t8,$t7,0x1f
/*    4e768:	ae180000 */ 	sw	$t8,0x0($s0)
/*    4e76c:	10000019 */ 	beqz	$zero,.L0004e7d4
/*    4e770:	ae0f0004 */ 	sw	$t7,0x4($s0)
/*    4e774:	2401004c */ 	addiu	$at,$zero,0x4c
.L0004e778:
/*    4e778:	5441000d */ 	bnel	$v0,$at,.L0004e7b0
/*    4e77c:	8ccf0000 */ 	lw	$t7,0x0($a2)
/*    4e780:	8cce0000 */ 	lw	$t6,0x0($a2)
/*    4e784:	2401fff8 */ 	addiu	$at,$zero,-8
/*    4e788:	25cf0007 */ 	addiu	$t7,$t6,0x7
/*    4e78c:	01e1c024 */ 	and	$t8,$t7,$at
/*    4e790:	27190008 */ 	addiu	$t9,$t8,0x8
/*    4e794:	acd90000 */ 	sw	$t9,0x0($a2)
/*    4e798:	8f38fff8 */ 	lw	$t8,-0x8($t9)
/*    4e79c:	8f39fffc */ 	lw	$t9,-0x4($t9)
/*    4e7a0:	ae180000 */ 	sw	$t8,0x0($s0)
/*    4e7a4:	1000000b */ 	beqz	$zero,.L0004e7d4
/*    4e7a8:	ae190004 */ 	sw	$t9,0x4($s0)
/*    4e7ac:	8ccf0000 */ 	lw	$t7,0x0($a2)
.L0004e7b0:
/*    4e7b0:	2401fffc */ 	addiu	$at,$zero,-4
/*    4e7b4:	25ee0003 */ 	addiu	$t6,$t7,0x3
/*    4e7b8:	01c1c024 */ 	and	$t8,$t6,$at
/*    4e7bc:	27190004 */ 	addiu	$t9,$t8,0x4
/*    4e7c0:	acd90000 */ 	sw	$t9,0x0($a2)
/*    4e7c4:	8f2efffc */ 	lw	$t6,-0x4($t9)
/*    4e7c8:	000ec7c3 */ 	sra	$t8,$t6,0x1f
/*    4e7cc:	ae180000 */ 	sw	$t8,0x0($s0)
/*    4e7d0:	ae0e0004 */ 	sw	$t6,0x4($s0)
.L0004e7d4:
/*    4e7d4:	920f0034 */ 	lbu	$t7,0x34($s0)
/*    4e7d8:	24010068 */ 	addiu	$at,$zero,0x68
/*    4e7dc:	55e10008 */ 	bnel	$t7,$at,.L0004e800
/*    4e7e0:	8e0e0000 */ 	lw	$t6,0x0($s0)
/*    4e7e4:	8e0f0004 */ 	lw	$t7,0x4($s0)
/*    4e7e8:	000fcc00 */ 	sll	$t9,$t7,0x10
/*    4e7ec:	00197403 */ 	sra	$t6,$t9,0x10
/*    4e7f0:	000ec7c3 */ 	sra	$t8,$t6,0x1f
/*    4e7f4:	ae180000 */ 	sw	$t8,0x0($s0)
/*    4e7f8:	ae0e0004 */ 	sw	$t6,0x4($s0)
/*    4e7fc:	8e0e0000 */ 	lw	$t6,0x0($s0)
.L0004e800:
/*    4e800:	5dc0000e */ 	bgtzl	$t6,.L0004e83c
/*    4e804:	8e020030 */ 	lw	$v0,0x30($s0)
/*    4e808:	05c20004 */ 	bltzl	$t6,.L0004e81c
/*    4e80c:	8e19000c */ 	lw	$t9,0xc($s0)
/*    4e810:	1000000a */ 	beqz	$zero,.L0004e83c
/*    4e814:	8e020030 */ 	lw	$v0,0x30($s0)
/*    4e818:	8e19000c */ 	lw	$t9,0xc($s0)
.L0004e81c:
/*    4e81c:	2418002d */ 	addiu	$t8,$zero,0x2d
/*    4e820:	00f97021 */ 	addu	$t6,$a3,$t9
/*    4e824:	a1d80000 */ 	sb	$t8,0x0($t6)
/*    4e828:	8e0f000c */ 	lw	$t7,0xc($s0)
/*    4e82c:	25f90001 */ 	addiu	$t9,$t7,0x1
/*    4e830:	10000016 */ 	beqz	$zero,.L0004e88c
/*    4e834:	ae19000c */ 	sw	$t9,0xc($s0)
/*    4e838:	8e020030 */ 	lw	$v0,0x30($s0)
.L0004e83c:
/*    4e83c:	30580002 */ 	andi	$t8,$v0,0x2
/*    4e840:	13000009 */ 	beqz	$t8,.L0004e868
/*    4e844:	304e0001 */ 	andi	$t6,$v0,0x1
/*    4e848:	8e0f000c */ 	lw	$t7,0xc($s0)
/*    4e84c:	240e002b */ 	addiu	$t6,$zero,0x2b
/*    4e850:	00efc821 */ 	addu	$t9,$a3,$t7
/*    4e854:	a32e0000 */ 	sb	$t6,0x0($t9)
/*    4e858:	8e18000c */ 	lw	$t8,0xc($s0)
/*    4e85c:	270f0001 */ 	addiu	$t7,$t8,0x1
/*    4e860:	1000000a */ 	beqz	$zero,.L0004e88c
/*    4e864:	ae0f000c */ 	sw	$t7,0xc($s0)
.L0004e868:
/*    4e868:	51c00009 */ 	beqzl	$t6,.L0004e890
/*    4e86c:	8e19000c */ 	lw	$t9,0xc($s0)
/*    4e870:	8e18000c */ 	lw	$t8,0xc($s0)
/*    4e874:	24190020 */ 	addiu	$t9,$zero,0x20
/*    4e878:	00f87821 */ 	addu	$t7,$a3,$t8
/*    4e87c:	a1f90000 */ 	sb	$t9,0x0($t7)
/*    4e880:	8e0e000c */ 	lw	$t6,0xc($s0)
/*    4e884:	25d80001 */ 	addiu	$t8,$t6,0x1
/*    4e888:	ae18000c */ 	sw	$t8,0xc($s0)
.L0004e88c:
/*    4e88c:	8e19000c */ 	lw	$t9,0xc($s0)
.L0004e890:
/*    4e890:	02002025 */ 	or	$a0,$s0,$zero
/*    4e894:	03277821 */ 	addu	$t7,$t9,$a3
/*    4e898:	0c014830 */ 	jal	func000520c0
/*    4e89c:	ae0f0008 */ 	sw	$t7,0x8($s0)
/*    4e8a0:	10000114 */ 	beqz	$zero,.L0004ecf4
/*    4e8a4:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    4e8a8:	92020034 */ 	lbu	$v0,0x34($s0)
/*    4e8ac:	2401006c */ 	addiu	$at,$zero,0x6c
/*    4e8b0:	5441000d */ 	bnel	$v0,$at,.L0004e8e8
/*    4e8b4:	2401004c */ 	addiu	$at,$zero,0x4c
/*    4e8b8:	8cce0000 */ 	lw	$t6,0x0($a2)
/*    4e8bc:	2401fffc */ 	addiu	$at,$zero,-4
/*    4e8c0:	25d80003 */ 	addiu	$t8,$t6,0x3
/*    4e8c4:	0301c824 */ 	and	$t9,$t8,$at
/*    4e8c8:	272f0004 */ 	addiu	$t7,$t9,0x4
/*    4e8cc:	accf0000 */ 	sw	$t7,0x0($a2)
/*    4e8d0:	8df8fffc */ 	lw	$t8,-0x4($t7)
/*    4e8d4:	001877c3 */ 	sra	$t6,$t8,0x1f
/*    4e8d8:	ae0e0000 */ 	sw	$t6,0x0($s0)
/*    4e8dc:	10000019 */ 	beqz	$zero,.L0004e944
/*    4e8e0:	ae180004 */ 	sw	$t8,0x4($s0)
/*    4e8e4:	2401004c */ 	addiu	$at,$zero,0x4c
.L0004e8e8:
/*    4e8e8:	5441000d */ 	bnel	$v0,$at,.L0004e920
/*    4e8ec:	8cce0000 */ 	lw	$t6,0x0($a2)
/*    4e8f0:	8cd90000 */ 	lw	$t9,0x0($a2)
/*    4e8f4:	2401fff8 */ 	addiu	$at,$zero,-8
/*    4e8f8:	27380007 */ 	addiu	$t8,$t9,0x7
/*    4e8fc:	03017024 */ 	and	$t6,$t8,$at
/*    4e900:	25cf0008 */ 	addiu	$t7,$t6,0x8
/*    4e904:	accf0000 */ 	sw	$t7,0x0($a2)
/*    4e908:	8df9fffc */ 	lw	$t9,-0x4($t7)
/*    4e90c:	8df8fff8 */ 	lw	$t8,-0x8($t7)
/*    4e910:	ae190004 */ 	sw	$t9,0x4($s0)
/*    4e914:	1000000b */ 	beqz	$zero,.L0004e944
/*    4e918:	ae180000 */ 	sw	$t8,0x0($s0)
/*    4e91c:	8cce0000 */ 	lw	$t6,0x0($a2)
.L0004e920:
/*    4e920:	2401fffc */ 	addiu	$at,$zero,-4
/*    4e924:	25cf0003 */ 	addiu	$t7,$t6,0x3
/*    4e928:	01e1c024 */ 	and	$t8,$t7,$at
/*    4e92c:	27190004 */ 	addiu	$t9,$t8,0x4
/*    4e930:	acd90000 */ 	sw	$t9,0x0($a2)
/*    4e934:	8f2ffffc */ 	lw	$t7,-0x4($t9)
/*    4e938:	000fc7c3 */ 	sra	$t8,$t7,0x1f
/*    4e93c:	ae180000 */ 	sw	$t8,0x0($s0)
/*    4e940:	ae0f0004 */ 	sw	$t7,0x4($s0)
.L0004e944:
/*    4e944:	92020034 */ 	lbu	$v0,0x34($s0)
/*    4e948:	24010068 */ 	addiu	$at,$zero,0x68
/*    4e94c:	14410007 */ 	bne	$v0,$at,.L0004e96c
/*    4e950:	00000000 */ 	sll	$zero,$zero,0x0
/*    4e954:	8e0f0004 */ 	lw	$t7,0x4($s0)
/*    4e958:	240e0000 */ 	addiu	$t6,$zero,0x0
/*    4e95c:	ae0e0000 */ 	sw	$t6,0x0($s0)
/*    4e960:	31f9ffff */ 	andi	$t9,$t7,0xffff
/*    4e964:	10000007 */ 	beqz	$zero,.L0004e984
/*    4e968:	ae190004 */ 	sw	$t9,0x4($s0)
.L0004e96c:
/*    4e96c:	54400006 */ 	bnezl	$v0,.L0004e988
/*    4e970:	8e0f0030 */ 	lw	$t7,0x30($s0)
/*    4e974:	8e190004 */ 	lw	$t9,0x4($s0)
/*    4e978:	24180000 */ 	addiu	$t8,$zero,0x0
/*    4e97c:	ae180000 */ 	sw	$t8,0x0($s0)
/*    4e980:	ae190004 */ 	sw	$t9,0x4($s0)
.L0004e984:
/*    4e984:	8e0f0030 */ 	lw	$t7,0x30($s0)
.L0004e988:
/*    4e988:	31ee0008 */ 	andi	$t6,$t7,0x8
/*    4e98c:	51c00014 */ 	beqzl	$t6,.L0004e9e0
/*    4e990:	8e18000c */ 	lw	$t8,0xc($s0)
/*    4e994:	8e19000c */ 	lw	$t9,0xc($s0)
/*    4e998:	24180030 */ 	addiu	$t8,$zero,0x30
/*    4e99c:	24010078 */ 	addiu	$at,$zero,0x78
/*    4e9a0:	00f97821 */ 	addu	$t7,$a3,$t9
/*    4e9a4:	a1f80000 */ 	sb	$t8,0x0($t7)
/*    4e9a8:	8e0e000c */ 	lw	$t6,0xc($s0)
/*    4e9ac:	25d90001 */ 	addiu	$t9,$t6,0x1
/*    4e9b0:	10610004 */ 	beq	$v1,$at,.L0004e9c4
/*    4e9b4:	ae19000c */ 	sw	$t9,0xc($s0)
/*    4e9b8:	24010058 */ 	addiu	$at,$zero,0x58
/*    4e9bc:	54610008 */ 	bnel	$v1,$at,.L0004e9e0
/*    4e9c0:	8e18000c */ 	lw	$t8,0xc($s0)
.L0004e9c4:
/*    4e9c4:	8e18000c */ 	lw	$t8,0xc($s0)
/*    4e9c8:	00f87821 */ 	addu	$t7,$a3,$t8
/*    4e9cc:	a1e50000 */ 	sb	$a1,0x0($t7)
/*    4e9d0:	8e0e000c */ 	lw	$t6,0xc($s0)
/*    4e9d4:	25d90001 */ 	addiu	$t9,$t6,0x1
/*    4e9d8:	ae19000c */ 	sw	$t9,0xc($s0)
/*    4e9dc:	8e18000c */ 	lw	$t8,0xc($s0)
.L0004e9e0:
/*    4e9e0:	02002025 */ 	or	$a0,$s0,$zero
/*    4e9e4:	03077821 */ 	addu	$t7,$t8,$a3
/*    4e9e8:	0c014830 */ 	jal	func000520c0
/*    4e9ec:	ae0f0008 */ 	sw	$t7,0x8($s0)
/*    4e9f0:	100000c0 */ 	beqz	$zero,.L0004ecf4
/*    4e9f4:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    4e9f8:	920e0034 */ 	lbu	$t6,0x34($s0)
/*    4e9fc:	2401004c */ 	addiu	$at,$zero,0x4c
/*    4ea00:	55c10019 */ 	bnel	$t6,$at,.L0004ea68
/*    4ea04:	8cc20000 */ 	lw	$v0,0x0($a2)
/*    4ea08:	8cc20000 */ 	lw	$v0,0x0($a2)
/*    4ea0c:	30590001 */ 	andi	$t9,$v0,0x1
/*    4ea10:	13200005 */ 	beqz	$t9,.L0004ea28
/*    4ea14:	00401825 */ 	or	$v1,$v0,$zero
/*    4ea18:	24780007 */ 	addiu	$t8,$v1,0x7
/*    4ea1c:	acd80000 */ 	sw	$t8,0x0($a2)
/*    4ea20:	1000000d */ 	beqz	$zero,.L0004ea58
/*    4ea24:	2702ffea */ 	addiu	$v0,$t8,-22
.L0004ea28:
/*    4ea28:	306f0002 */ 	andi	$t7,$v1,0x2
/*    4ea2c:	11e00005 */ 	beqz	$t7,.L0004ea44
/*    4ea30:	24590007 */ 	addiu	$t9,$v0,0x7
/*    4ea34:	246e000a */ 	addiu	$t6,$v1,0xa
/*    4ea38:	acce0000 */ 	sw	$t6,0x0($a2)
/*    4ea3c:	10000005 */ 	beqz	$zero,.L0004ea54
/*    4ea40:	25c4ffd8 */ 	addiu	$a0,$t6,-40
.L0004ea44:
/*    4ea44:	2401fff8 */ 	addiu	$at,$zero,-8
/*    4ea48:	0321c024 */ 	and	$t8,$t9,$at
/*    4ea4c:	27040008 */ 	addiu	$a0,$t8,0x8
/*    4ea50:	acc40000 */ 	sw	$a0,0x0($a2)
.L0004ea54:
/*    4ea54:	00801025 */ 	or	$v0,$a0,$zero
.L0004ea58:
/*    4ea58:	d444fff8 */ 	ldc1	$f4,-0x8($v0)
/*    4ea5c:	10000017 */ 	beqz	$zero,.L0004eabc
/*    4ea60:	f6040000 */ 	sdc1	$f4,0x0($s0)
/*    4ea64:	8cc20000 */ 	lw	$v0,0x0($a2)
.L0004ea68:
/*    4ea68:	304e0001 */ 	andi	$t6,$v0,0x1
/*    4ea6c:	11c00005 */ 	beqz	$t6,.L0004ea84
/*    4ea70:	00401825 */ 	or	$v1,$v0,$zero
/*    4ea74:	24790007 */ 	addiu	$t9,$v1,0x7
/*    4ea78:	acd90000 */ 	sw	$t9,0x0($a2)
/*    4ea7c:	1000000d */ 	beqz	$zero,.L0004eab4
/*    4ea80:	2722ffea */ 	addiu	$v0,$t9,-22
.L0004ea84:
/*    4ea84:	30780002 */ 	andi	$t8,$v1,0x2
/*    4ea88:	13000005 */ 	beqz	$t8,.L0004eaa0
/*    4ea8c:	244e0007 */ 	addiu	$t6,$v0,0x7
/*    4ea90:	246f000a */ 	addiu	$t7,$v1,0xa
/*    4ea94:	accf0000 */ 	sw	$t7,0x0($a2)
/*    4ea98:	10000005 */ 	beqz	$zero,.L0004eab0
/*    4ea9c:	25e4ffd8 */ 	addiu	$a0,$t7,-40
.L0004eaa0:
/*    4eaa0:	2401fff8 */ 	addiu	$at,$zero,-8
/*    4eaa4:	01c1c824 */ 	and	$t9,$t6,$at
/*    4eaa8:	27240008 */ 	addiu	$a0,$t9,0x8
/*    4eaac:	acc40000 */ 	sw	$a0,0x0($a2)
.L0004eab0:
/*    4eab0:	00801025 */ 	or	$v0,$a0,$zero
.L0004eab4:
/*    4eab4:	d446fff8 */ 	ldc1	$f6,-0x8($v0)
/*    4eab8:	f6060000 */ 	sdc1	$f6,0x0($s0)
.L0004eabc:
/*    4eabc:	960f0000 */ 	lhu	$t7,0x0($s0)
/*    4eac0:	31ee8000 */ 	andi	$t6,$t7,0x8000
/*    4eac4:	51c0000a */ 	beqzl	$t6,.L0004eaf0
/*    4eac8:	8e020030 */ 	lw	$v0,0x30($s0)
/*    4eacc:	8e18000c */ 	lw	$t8,0xc($s0)
/*    4ead0:	2419002d */ 	addiu	$t9,$zero,0x2d
/*    4ead4:	00f87821 */ 	addu	$t7,$a3,$t8
/*    4ead8:	a1f90000 */ 	sb	$t9,0x0($t7)
/*    4eadc:	8e0e000c */ 	lw	$t6,0xc($s0)
/*    4eae0:	25d80001 */ 	addiu	$t8,$t6,0x1
/*    4eae4:	10000016 */ 	beqz	$zero,.L0004eb40
/*    4eae8:	ae18000c */ 	sw	$t8,0xc($s0)
/*    4eaec:	8e020030 */ 	lw	$v0,0x30($s0)
.L0004eaf0:
/*    4eaf0:	30590002 */ 	andi	$t9,$v0,0x2
/*    4eaf4:	13200009 */ 	beqz	$t9,.L0004eb1c
/*    4eaf8:	304f0001 */ 	andi	$t7,$v0,0x1
/*    4eafc:	8e0e000c */ 	lw	$t6,0xc($s0)
/*    4eb00:	240f002b */ 	addiu	$t7,$zero,0x2b
/*    4eb04:	00eec021 */ 	addu	$t8,$a3,$t6
/*    4eb08:	a30f0000 */ 	sb	$t7,0x0($t8)
/*    4eb0c:	8e19000c */ 	lw	$t9,0xc($s0)
/*    4eb10:	272e0001 */ 	addiu	$t6,$t9,0x1
/*    4eb14:	1000000a */ 	beqz	$zero,.L0004eb40
/*    4eb18:	ae0e000c */ 	sw	$t6,0xc($s0)
.L0004eb1c:
/*    4eb1c:	51e00009 */ 	beqzl	$t7,.L0004eb44
/*    4eb20:	8e18000c */ 	lw	$t8,0xc($s0)
/*    4eb24:	8e19000c */ 	lw	$t9,0xc($s0)
/*    4eb28:	24180020 */ 	addiu	$t8,$zero,0x20
/*    4eb2c:	00f97021 */ 	addu	$t6,$a3,$t9
/*    4eb30:	a1d80000 */ 	sb	$t8,0x0($t6)
/*    4eb34:	8e0f000c */ 	lw	$t7,0xc($s0)
/*    4eb38:	25f90001 */ 	addiu	$t9,$t7,0x1
/*    4eb3c:	ae19000c */ 	sw	$t9,0xc($s0)
.L0004eb40:
/*    4eb40:	8e18000c */ 	lw	$t8,0xc($s0)
.L0004eb44:
/*    4eb44:	02002025 */ 	or	$a0,$s0,$zero
/*    4eb48:	03077021 */ 	addu	$t6,$t8,$a3
/*    4eb4c:	0c001314 */ 	jal	func00004c50
/*    4eb50:	ae0e0008 */ 	sw	$t6,0x8($s0)
/*    4eb54:	10000067 */ 	beqz	$zero,.L0004ecf4
/*    4eb58:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    4eb5c:	92020034 */ 	lbu	$v0,0x34($s0)
/*    4eb60:	24010068 */ 	addiu	$at,$zero,0x68
/*    4eb64:	5441000c */ 	bnel	$v0,$at,.L0004eb98
/*    4eb68:	2401006c */ 	addiu	$at,$zero,0x6c
/*    4eb6c:	8ccf0000 */ 	lw	$t7,0x0($a2)
/*    4eb70:	2401fffc */ 	addiu	$at,$zero,-4
/*    4eb74:	25f90003 */ 	addiu	$t9,$t7,0x3
/*    4eb78:	0321c024 */ 	and	$t8,$t9,$at
/*    4eb7c:	270e0004 */ 	addiu	$t6,$t8,0x4
/*    4eb80:	acce0000 */ 	sw	$t6,0x0($a2)
/*    4eb84:	8dd9fffc */ 	lw	$t9,-0x4($t6)
/*    4eb88:	8e0f002c */ 	lw	$t7,0x2c($s0)
/*    4eb8c:	10000058 */ 	beqz	$zero,.L0004ecf0
/*    4eb90:	a72f0000 */ 	sh	$t7,0x0($t9)
/*    4eb94:	2401006c */ 	addiu	$at,$zero,0x6c
.L0004eb98:
/*    4eb98:	5441000c */ 	bnel	$v0,$at,.L0004ebcc
/*    4eb9c:	2401004c */ 	addiu	$at,$zero,0x4c
/*    4eba0:	8cd80000 */ 	lw	$t8,0x0($a2)
/*    4eba4:	2401fffc */ 	addiu	$at,$zero,-4
/*    4eba8:	270e0003 */ 	addiu	$t6,$t8,0x3
/*    4ebac:	01c17824 */ 	and	$t7,$t6,$at
/*    4ebb0:	25f90004 */ 	addiu	$t9,$t7,0x4
/*    4ebb4:	acd90000 */ 	sw	$t9,0x0($a2)
/*    4ebb8:	8f2efffc */ 	lw	$t6,-0x4($t9)
/*    4ebbc:	8e18002c */ 	lw	$t8,0x2c($s0)
/*    4ebc0:	1000004b */ 	beqz	$zero,.L0004ecf0
/*    4ebc4:	add80000 */ 	sw	$t8,0x0($t6)
/*    4ebc8:	2401004c */ 	addiu	$at,$zero,0x4c
.L0004ebcc:
/*    4ebcc:	5441000e */ 	bnel	$v0,$at,.L0004ec08
/*    4ebd0:	8ccf0000 */ 	lw	$t7,0x0($a2)
/*    4ebd4:	8ccf0000 */ 	lw	$t7,0x0($a2)
/*    4ebd8:	2401fffc */ 	addiu	$at,$zero,-4
/*    4ebdc:	25f90003 */ 	addiu	$t9,$t7,0x3
/*    4ebe0:	0321c024 */ 	and	$t8,$t9,$at
/*    4ebe4:	270e0004 */ 	addiu	$t6,$t8,0x4
/*    4ebe8:	acce0000 */ 	sw	$t6,0x0($a2)
/*    4ebec:	8dcefffc */ 	lw	$t6,-0x4($t6)
/*    4ebf0:	8e0f002c */ 	lw	$t7,0x2c($s0)
/*    4ebf4:	24180000 */ 	addiu	$t8,$zero,0x0
/*    4ebf8:	add80000 */ 	sw	$t8,0x0($t6)
/*    4ebfc:	1000003c */ 	beqz	$zero,.L0004ecf0
/*    4ec00:	adcf0004 */ 	sw	$t7,0x4($t6)
/*    4ec04:	8ccf0000 */ 	lw	$t7,0x0($a2)
.L0004ec08:
/*    4ec08:	2401fffc */ 	addiu	$at,$zero,-4
/*    4ec0c:	25f80003 */ 	addiu	$t8,$t7,0x3
/*    4ec10:	0301c824 */ 	and	$t9,$t8,$at
/*    4ec14:	272e0004 */ 	addiu	$t6,$t9,0x4
/*    4ec18:	acce0000 */ 	sw	$t6,0x0($a2)
/*    4ec1c:	8dd8fffc */ 	lw	$t8,-0x4($t6)
/*    4ec20:	8e0f002c */ 	lw	$t7,0x2c($s0)
/*    4ec24:	10000032 */ 	beqz	$zero,.L0004ecf0
/*    4ec28:	af0f0000 */ 	sw	$t7,0x0($t8)
/*    4ec2c:	8cd90000 */ 	lw	$t9,0x0($a2)
/*    4ec30:	2401fffc */ 	addiu	$at,$zero,-4
/*    4ec34:	02002025 */ 	or	$a0,$s0,$zero
/*    4ec38:	272e0003 */ 	addiu	$t6,$t9,0x3
/*    4ec3c:	01c17824 */ 	and	$t7,$t6,$at
/*    4ec40:	25f80004 */ 	addiu	$t8,$t7,0x4
/*    4ec44:	acd80000 */ 	sw	$t8,0x0($a2)
/*    4ec48:	8f0efffc */ 	lw	$t6,-0x4($t8)
/*    4ec4c:	8e0f000c */ 	lw	$t7,0xc($s0)
/*    4ec50:	24050078 */ 	addiu	$a1,$zero,0x78
/*    4ec54:	000ec7c3 */ 	sra	$t8,$t6,0x1f
/*    4ec58:	ae0e0004 */ 	sw	$t6,0x4($s0)
/*    4ec5c:	01e77021 */ 	addu	$t6,$t7,$a3
/*    4ec60:	ae180000 */ 	sw	$t8,0x0($s0)
/*    4ec64:	0c014830 */ 	jal	func000520c0
/*    4ec68:	ae0e0008 */ 	sw	$t6,0x8($s0)
/*    4ec6c:	10000021 */ 	beqz	$zero,.L0004ecf4
/*    4ec70:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    4ec74:	8cd80000 */ 	lw	$t8,0x0($a2)
/*    4ec78:	2401fffc */ 	addiu	$at,$zero,-4
/*    4ec7c:	27190003 */ 	addiu	$t9,$t8,0x3
/*    4ec80:	03217824 */ 	and	$t7,$t9,$at
/*    4ec84:	25ee0004 */ 	addiu	$t6,$t7,0x4
/*    4ec88:	acce0000 */ 	sw	$t6,0x0($a2)
/*    4ec8c:	8dc4fffc */ 	lw	$a0,-0x4($t6)
/*    4ec90:	0c012983 */ 	jal	func0004a60c
/*    4ec94:	ae040008 */ 	sw	$a0,0x8($s0)
/*    4ec98:	8e030024 */ 	lw	$v1,0x24($s0)
/*    4ec9c:	ae020014 */ 	sw	$v0,0x14($s0)
/*    4eca0:	04600013 */ 	bltz	$v1,.L0004ecf0
/*    4eca4:	0062082a */ 	slt	$at,$v1,$v0
/*    4eca8:	50200012 */ 	beqzl	$at,.L0004ecf4
/*    4ecac:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    4ecb0:	1000000f */ 	beqz	$zero,.L0004ecf0
/*    4ecb4:	ae030014 */ 	sw	$v1,0x14($s0)
/*    4ecb8:	8e18000c */ 	lw	$t8,0xc($s0)
.L0004ecbc:
/*    4ecbc:	240e0025 */ 	addiu	$t6,$zero,0x25
/*    4ecc0:	00f8c821 */ 	addu	$t9,$a3,$t8
/*    4ecc4:	a32e0000 */ 	sb	$t6,0x0($t9)
/*    4ecc8:	8e0f000c */ 	lw	$t7,0xc($s0)
/*    4eccc:	25f80001 */ 	addiu	$t8,$t7,0x1
/*    4ecd0:	10000007 */ 	beqz	$zero,.L0004ecf0
/*    4ecd4:	ae18000c */ 	sw	$t8,0xc($s0)
.L0004ecd8:
/*    4ecd8:	8e0e000c */ 	lw	$t6,0xc($s0)
.L0004ecdc:
/*    4ecdc:	00eec821 */ 	addu	$t9,$a3,$t6
/*    4ece0:	a3250000 */ 	sb	$a1,0x0($t9)
/*    4ece4:	8e0f000c */ 	lw	$t7,0xc($s0)
/*    4ece8:	25f80001 */ 	addiu	$t8,$t7,0x1
/*    4ecec:	ae18000c */ 	sw	$t8,0xc($s0)
.L0004ecf0:
/*    4ecf0:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0004ecf4:
/*    4ecf4:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*    4ecf8:	03e00008 */ 	jr	$ra
/*    4ecfc:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0004ed00
/*    4ed00:	27bdff28 */ 	addiu	$sp,$sp,-216
/*    4ed04:	afb70034 */ 	sw	$s7,0x34($sp)
/*    4ed08:	afb60030 */ 	sw	$s6,0x30($sp)
/*    4ed0c:	afb5002c */ 	sw	$s5,0x2c($sp)
/*    4ed10:	afbe0038 */ 	sw	$s8,0x38($sp)
/*    4ed14:	afb40028 */ 	sw	$s4,0x28($sp)
/*    4ed18:	afb30024 */ 	sw	$s3,0x24($sp)
/*    4ed1c:	afa700e4 */ 	sw	$a3,0xe4($sp)
/*    4ed20:	3c158006 */ 	lui	$s5,%hi(var800609c4)
/*    4ed24:	3c167006 */ 	lui	$s6,0x7006
/*    4ed28:	3c178006 */ 	lui	$s7,%hi(var800609a0)
/*    4ed2c:	00c03825 */ 	or	$a3,$a2,$zero
/*    4ed30:	00a09825 */ 	or	$s3,$a1,$zero
/*    4ed34:	0080a025 */ 	or	$s4,$a0,$zero
/*    4ed38:	afbf003c */ 	sw	$ra,0x3c($sp)
/*    4ed3c:	afb20020 */ 	sw	$s2,0x20($sp)
/*    4ed40:	afb1001c */ 	sw	$s1,0x1c($sp)
/*    4ed44:	afb00018 */ 	sw	$s0,0x18($sp)
/*    4ed48:	afa600e0 */ 	sw	$a2,0xe0($sp)
/*    4ed4c:	afa000cc */ 	sw	$zero,0xcc($sp)
/*    4ed50:	26f709a0 */ 	addiu	$s7,$s7,%lo(var800609a0)
/*    4ed54:	26d69ed4 */ 	addiu	$s6,$s6,-24876
/*    4ed58:	26b509c4 */ 	addiu	$s5,$s5,%lo(var800609c4)
/*    4ed5c:	241e000a */ 	addiu	$s8,$zero,0xa
.L0004ed60:
/*    4ed60:	90e20000 */ 	lbu	$v0,0x0($a3)
/*    4ed64:	00e09025 */ 	or	$s2,$a3,$zero
/*    4ed68:	24030025 */ 	addiu	$v1,$zero,0x25
/*    4ed6c:	10400009 */ 	beqz	$v0,.L0004ed94
/*    4ed70:	00408025 */ 	or	$s0,$v0,$zero
/*    4ed74:	50620008 */ 	beql	$v1,$v0,.L0004ed98
/*    4ed78:	02471023 */ 	subu	$v0,$s2,$a3
/*    4ed7c:	92420001 */ 	lbu	$v0,0x1($s2)
.L0004ed80:
/*    4ed80:	26520001 */ 	addiu	$s2,$s2,0x1
/*    4ed84:	10400003 */ 	beqz	$v0,.L0004ed94
/*    4ed88:	00408025 */ 	or	$s0,$v0,$zero
/*    4ed8c:	5462fffc */ 	bnel	$v1,$v0,.L0004ed80
/*    4ed90:	92420001 */ 	lbu	$v0,0x1($s2)
.L0004ed94:
/*    4ed94:	02471023 */ 	subu	$v0,$s2,$a3
.L0004ed98:
/*    4ed98:	1840000d */ 	blez	$v0,.L0004edd0
/*    4ed9c:	02602025 */ 	or	$a0,$s3,$zero
/*    4eda0:	00e02825 */ 	or	$a1,$a3,$zero
/*    4eda4:	00408825 */ 	or	$s1,$v0,$zero
/*    4eda8:	0280f809 */ 	jalr	$s4
/*    4edac:	00403025 */ 	or	$a2,$v0,$zero
/*    4edb0:	10400005 */ 	beqz	$v0,.L0004edc8
/*    4edb4:	00409825 */ 	or	$s3,$v0,$zero
/*    4edb8:	8fae00cc */ 	lw	$t6,0xcc($sp)
/*    4edbc:	01d17821 */ 	addu	$t7,$t6,$s1
/*    4edc0:	10000003 */ 	beqz	$zero,.L0004edd0
/*    4edc4:	afaf00cc */ 	sw	$t7,0xcc($sp)
.L0004edc8:
/*    4edc8:	10000153 */ 	beqz	$zero,.L0004f318
/*    4edcc:	8fa200cc */ 	lw	$v0,0xcc($sp)
.L0004edd0:
/*    4edd0:	16000003 */ 	bnez	$s0,.L0004ede0
/*    4edd4:	26520001 */ 	addiu	$s2,$s2,0x1
/*    4edd8:	1000014f */ 	beqz	$zero,.L0004f318
/*    4eddc:	8fa200cc */ 	lw	$v0,0xcc($sp)
.L0004ede0:
/*    4ede0:	afa000d0 */ 	sw	$zero,0xd0($sp)
/*    4ede4:	92450000 */ 	lbu	$a1,0x0($s2)
/*    4ede8:	0c01298d */ 	jal	strchr
/*    4edec:	02c02025 */ 	or	$a0,$s6,$zero
/*    4edf0:	1040000f */ 	beqz	$v0,.L0004ee30
/*    4edf4:	00408025 */ 	or	$s0,$v0,$zero
.L0004edf8:
/*    4edf8:	0216c823 */ 	subu	$t9,$s0,$s6
/*    4edfc:	00197080 */ 	sll	$t6,$t9,0x2
/*    4ee00:	3c0f7006 */ 	lui	$t7,0x7006
/*    4ee04:	01ee7821 */ 	addu	$t7,$t7,$t6
/*    4ee08:	8def9edc */ 	lw	$t7,-0x6124($t7)
/*    4ee0c:	8fb800d0 */ 	lw	$t8,0xd0($sp)
/*    4ee10:	26520001 */ 	addiu	$s2,$s2,0x1
/*    4ee14:	02c02025 */ 	or	$a0,$s6,$zero
/*    4ee18:	030fc825 */ 	or	$t9,$t8,$t7
/*    4ee1c:	afb900d0 */ 	sw	$t9,0xd0($sp)
/*    4ee20:	0c01298d */ 	jal	strchr
/*    4ee24:	92450000 */ 	lbu	$a1,0x0($s2)
/*    4ee28:	1440fff3 */ 	bnez	$v0,.L0004edf8
/*    4ee2c:	00408025 */ 	or	$s0,$v0,$zero
.L0004ee30:
/*    4ee30:	924e0000 */ 	lbu	$t6,0x0($s2)
/*    4ee34:	2402002a */ 	addiu	$v0,$zero,0x2a
/*    4ee38:	8fb800e4 */ 	lw	$t8,0xe4($sp)
/*    4ee3c:	144e0011 */ 	bne	$v0,$t6,.L0004ee84
/*    4ee40:	3c047006 */ 	lui	$a0,0x7006
/*    4ee44:	270f0003 */ 	addiu	$t7,$t8,0x3
/*    4ee48:	2401fffc */ 	addiu	$at,$zero,-4
/*    4ee4c:	01e1c824 */ 	and	$t9,$t7,$at
/*    4ee50:	272e0004 */ 	addiu	$t6,$t9,0x4
/*    4ee54:	afae00e4 */ 	sw	$t6,0xe4($sp)
/*    4ee58:	8f380000 */ 	lw	$t8,0x0($t9)
/*    4ee5c:	26520001 */ 	addiu	$s2,$s2,0x1
/*    4ee60:	07010006 */ 	bgez	$t8,.L0004ee7c
/*    4ee64:	afb800c8 */ 	sw	$t8,0xc8($sp)
/*    4ee68:	8fae00d0 */ 	lw	$t6,0xd0($sp)
/*    4ee6c:	00187823 */ 	negu	$t7,$t8
/*    4ee70:	afaf00c8 */ 	sw	$t7,0xc8($sp)
/*    4ee74:	35d90004 */ 	ori	$t9,$t6,0x4
/*    4ee78:	afb900d0 */ 	sw	$t9,0xd0($sp)
.L0004ee7c:
/*    4ee7c:	10000018 */ 	beqz	$zero,.L0004eee0
/*    4ee80:	92450000 */ 	lbu	$a1,0x0($s2)
.L0004ee84:
/*    4ee84:	afa000c8 */ 	sw	$zero,0xc8($sp)
/*    4ee88:	92450000 */ 	lbu	$a1,0x0($s2)
/*    4ee8c:	28a10030 */ 	slti	$at,$a1,0x30
/*    4ee90:	14200013 */ 	bnez	$at,.L0004eee0
/*    4ee94:	28a1003a */ 	slti	$at,$a1,0x3a
/*    4ee98:	50200012 */ 	beqzl	$at,.L0004eee4
/*    4ee9c:	2401002e */ 	addiu	$at,$zero,0x2e
/*    4eea0:	8fb800c8 */ 	lw	$t8,0xc8($sp)
.L0004eea4:
/*    4eea4:	2b0103e7 */ 	slti	$at,$t8,0x3e7
/*    4eea8:	50200007 */ 	beqzl	$at,.L0004eec8
/*    4eeac:	92450001 */ 	lbu	$a1,0x1($s2)
/*    4eeb0:	031e0019 */ 	multu	$t8,$s8
/*    4eeb4:	00007812 */ 	mflo	$t7
/*    4eeb8:	00af7021 */ 	addu	$t6,$a1,$t7
/*    4eebc:	25d9ffd0 */ 	addiu	$t9,$t6,-48
/*    4eec0:	afb900c8 */ 	sw	$t9,0xc8($sp)
/*    4eec4:	92450001 */ 	lbu	$a1,0x1($s2)
.L0004eec8:
/*    4eec8:	26520001 */ 	addiu	$s2,$s2,0x1
/*    4eecc:	28a10030 */ 	slti	$at,$a1,0x30
/*    4eed0:	14200003 */ 	bnez	$at,.L0004eee0
/*    4eed4:	28a1003a */ 	slti	$at,$a1,0x3a
/*    4eed8:	5420fff2 */ 	bnezl	$at,.L0004eea4
/*    4eedc:	8fb800c8 */ 	lw	$t8,0xc8($sp)
.L0004eee0:
/*    4eee0:	2401002e */ 	addiu	$at,$zero,0x2e
.L0004eee4:
/*    4eee4:	10a10004 */ 	beq	$a1,$at,.L0004eef8
/*    4eee8:	2418ffff */ 	addiu	$t8,$zero,-1
/*    4eeec:	afb800c4 */ 	sw	$t8,0xc4($sp)
/*    4eef0:	10000026 */ 	beqz	$zero,.L0004ef8c
/*    4eef4:	92450000 */ 	lbu	$a1,0x0($s2)
.L0004eef8:
/*    4eef8:	924f0001 */ 	lbu	$t7,0x1($s2)
/*    4eefc:	8fae00e4 */ 	lw	$t6,0xe4($sp)
/*    4ef00:	26520001 */ 	addiu	$s2,$s2,0x1
/*    4ef04:	144f000a */ 	bne	$v0,$t7,.L0004ef30
/*    4ef08:	25d90003 */ 	addiu	$t9,$t6,0x3
/*    4ef0c:	2401fffc */ 	addiu	$at,$zero,-4
/*    4ef10:	0321c024 */ 	and	$t8,$t9,$at
/*    4ef14:	270f0004 */ 	addiu	$t7,$t8,0x4
/*    4ef18:	afaf00e4 */ 	sw	$t7,0xe4($sp)
/*    4ef1c:	8f0e0000 */ 	lw	$t6,0x0($t8)
/*    4ef20:	26520001 */ 	addiu	$s2,$s2,0x1
/*    4ef24:	afae00c4 */ 	sw	$t6,0xc4($sp)
/*    4ef28:	10000018 */ 	beqz	$zero,.L0004ef8c
/*    4ef2c:	92450000 */ 	lbu	$a1,0x0($s2)
.L0004ef30:
/*    4ef30:	afa000c4 */ 	sw	$zero,0xc4($sp)
/*    4ef34:	92450000 */ 	lbu	$a1,0x0($s2)
/*    4ef38:	28a10030 */ 	slti	$at,$a1,0x30
/*    4ef3c:	14200013 */ 	bnez	$at,.L0004ef8c
/*    4ef40:	28a1003a */ 	slti	$at,$a1,0x3a
/*    4ef44:	10200011 */ 	beqz	$at,.L0004ef8c
/*    4ef48:	00000000 */ 	sll	$zero,$zero,0x0
/*    4ef4c:	8fb900c4 */ 	lw	$t9,0xc4($sp)
.L0004ef50:
/*    4ef50:	2b2103e7 */ 	slti	$at,$t9,0x3e7
/*    4ef54:	50200007 */ 	beqzl	$at,.L0004ef74
/*    4ef58:	92450001 */ 	lbu	$a1,0x1($s2)
/*    4ef5c:	033e0019 */ 	multu	$t9,$s8
/*    4ef60:	00007812 */ 	mflo	$t7
/*    4ef64:	00afc021 */ 	addu	$t8,$a1,$t7
/*    4ef68:	270effd0 */ 	addiu	$t6,$t8,-48
/*    4ef6c:	afae00c4 */ 	sw	$t6,0xc4($sp)
/*    4ef70:	92450001 */ 	lbu	$a1,0x1($s2)
.L0004ef74:
/*    4ef74:	26520001 */ 	addiu	$s2,$s2,0x1
/*    4ef78:	28a10030 */ 	slti	$at,$a1,0x30
/*    4ef7c:	14200003 */ 	bnez	$at,.L0004ef8c
/*    4ef80:	28a1003a */ 	slti	$at,$a1,0x3a
/*    4ef84:	5420fff2 */ 	bnezl	$at,.L0004ef50
/*    4ef88:	8fb900c4 */ 	lw	$t9,0xc4($sp)
.L0004ef8c:
/*    4ef8c:	0c01298d */ 	jal	strchr
/*    4ef90:	24849ed0 */ 	addiu	$a0,$a0,-24880
/*    4ef94:	10400005 */ 	beqz	$v0,.L0004efac
/*    4ef98:	27b000a0 */ 	addiu	$s0,$sp,0xa0
/*    4ef9c:	92590000 */ 	lbu	$t9,0x0($s2)
/*    4efa0:	26520001 */ 	addiu	$s2,$s2,0x1
/*    4efa4:	10000002 */ 	beqz	$zero,.L0004efb0
/*    4efa8:	a3b900d4 */ 	sb	$t9,0xd4($sp)
.L0004efac:
/*    4efac:	a3a000d4 */ 	sb	$zero,0xd4($sp)
.L0004efb0:
/*    4efb0:	93af00d4 */ 	lbu	$t7,0xd4($sp)
/*    4efb4:	2402006c */ 	addiu	$v0,$zero,0x6c
/*    4efb8:	27a600e4 */ 	addiu	$a2,$sp,0xe4
/*    4efbc:	144f0007 */ 	bne	$v0,$t7,.L0004efdc
/*    4efc0:	27a70074 */ 	addiu	$a3,$sp,0x74
/*    4efc4:	92580000 */ 	lbu	$t8,0x0($s2)
/*    4efc8:	240e004c */ 	addiu	$t6,$zero,0x4c
/*    4efcc:	14580003 */ 	bne	$v0,$t8,.L0004efdc
/*    4efd0:	00000000 */ 	sll	$zero,$zero,0x0
/*    4efd4:	a3ae00d4 */ 	sb	$t6,0xd4($sp)
/*    4efd8:	26520001 */ 	addiu	$s2,$s2,0x1
.L0004efdc:
/*    4efdc:	0c0139a4 */ 	jal	func0004e690
/*    4efe0:	92450000 */ 	lbu	$a1,0x0($s2)
/*    4efe4:	8fb900c8 */ 	lw	$t9,0xc8($sp)
/*    4efe8:	8faf00ac */ 	lw	$t7,0xac($sp)
/*    4efec:	8fae00b0 */ 	lw	$t6,0xb0($sp)
/*    4eff0:	032fc023 */ 	subu	$t8,$t9,$t7
/*    4eff4:	8faf00b4 */ 	lw	$t7,0xb4($sp)
/*    4eff8:	030ec823 */ 	subu	$t9,$t8,$t6
/*    4effc:	8fae00b8 */ 	lw	$t6,0xb8($sp)
/*    4f000:	032fc023 */ 	subu	$t8,$t9,$t7
/*    4f004:	8faf00bc */ 	lw	$t7,0xbc($sp)
/*    4f008:	030ec823 */ 	subu	$t9,$t8,$t6
/*    4f00c:	8fae00c0 */ 	lw	$t6,0xc0($sp)
/*    4f010:	032fc023 */ 	subu	$t8,$t9,$t7
/*    4f014:	8faf00d0 */ 	lw	$t7,0xd0($sp)
/*    4f018:	030ec823 */ 	subu	$t9,$t8,$t6
/*    4f01c:	afb900c8 */ 	sw	$t9,0xc8($sp)
/*    4f020:	31f80004 */ 	andi	$t8,$t7,0x4
/*    4f024:	1700001a */ 	bnez	$t8,.L0004f090
/*    4f028:	0019702a */ 	slt	$t6,$zero,$t9
/*    4f02c:	51c00019 */ 	beqzl	$t6,.L0004f094
/*    4f030:	8fb900ac */ 	lw	$t9,0xac($sp)
/*    4f034:	11c00016 */ 	beqz	$t6,.L0004f090
/*    4f038:	03208825 */ 	or	$s1,$t9,$zero
/*    4f03c:	2e210021 */ 	sltiu	$at,$s1,0x21
.L0004f040:
/*    4f040:	14200003 */ 	bnez	$at,.L0004f050
/*    4f044:	02208025 */ 	or	$s0,$s1,$zero
/*    4f048:	10000001 */ 	beqz	$zero,.L0004f050
/*    4f04c:	24100020 */ 	addiu	$s0,$zero,0x20
.L0004f050:
/*    4f050:	1a00000c */ 	blez	$s0,.L0004f084
/*    4f054:	02602025 */ 	or	$a0,$s3,$zero
/*    4f058:	02e02825 */ 	or	$a1,$s7,$zero
/*    4f05c:	0280f809 */ 	jalr	$s4
/*    4f060:	02003025 */ 	or	$a2,$s0,$zero
/*    4f064:	10400005 */ 	beqz	$v0,.L0004f07c
/*    4f068:	00409825 */ 	or	$s3,$v0,$zero
/*    4f06c:	8faf00cc */ 	lw	$t7,0xcc($sp)
/*    4f070:	01f0c021 */ 	addu	$t8,$t7,$s0
/*    4f074:	10000003 */ 	beqz	$zero,.L0004f084
/*    4f078:	afb800cc */ 	sw	$t8,0xcc($sp)
.L0004f07c:
/*    4f07c:	100000a6 */ 	beqz	$zero,.L0004f318
/*    4f080:	8fa200cc */ 	lw	$v0,0xcc($sp)
.L0004f084:
/*    4f084:	02308823 */ 	subu	$s1,$s1,$s0
/*    4f088:	5e20ffed */ 	bgtzl	$s1,.L0004f040
/*    4f08c:	2e210021 */ 	sltiu	$at,$s1,0x21
.L0004f090:
/*    4f090:	8fb900ac */ 	lw	$t9,0xac($sp)
.L0004f094:
/*    4f094:	02602025 */ 	or	$a0,$s3,$zero
/*    4f098:	27a50074 */ 	addiu	$a1,$sp,0x74
/*    4f09c:	5b20000d */ 	blezl	$t9,.L0004f0d4
/*    4f0a0:	8fb900b0 */ 	lw	$t9,0xb0($sp)
/*    4f0a4:	0280f809 */ 	jalr	$s4
/*    4f0a8:	03203025 */ 	or	$a2,$t9,$zero
/*    4f0ac:	10400006 */ 	beqz	$v0,.L0004f0c8
/*    4f0b0:	00409825 */ 	or	$s3,$v0,$zero
/*    4f0b4:	8fae00cc */ 	lw	$t6,0xcc($sp)
/*    4f0b8:	8faf00ac */ 	lw	$t7,0xac($sp)
/*    4f0bc:	01cfc021 */ 	addu	$t8,$t6,$t7
/*    4f0c0:	10000003 */ 	beqz	$zero,.L0004f0d0
/*    4f0c4:	afb800cc */ 	sw	$t8,0xcc($sp)
.L0004f0c8:
/*    4f0c8:	10000093 */ 	beqz	$zero,.L0004f318
/*    4f0cc:	8fa200cc */ 	lw	$v0,0xcc($sp)
.L0004f0d0:
/*    4f0d0:	8fb900b0 */ 	lw	$t9,0xb0($sp)
.L0004f0d4:
/*    4f0d4:	0019702a */ 	slt	$t6,$zero,$t9
/*    4f0d8:	51c00019 */ 	beqzl	$t6,.L0004f140
/*    4f0dc:	8fb900b4 */ 	lw	$t9,0xb4($sp)
/*    4f0e0:	11c00016 */ 	beqz	$t6,.L0004f13c
/*    4f0e4:	03208825 */ 	or	$s1,$t9,$zero
/*    4f0e8:	2e210021 */ 	sltiu	$at,$s1,0x21
.L0004f0ec:
/*    4f0ec:	14200003 */ 	bnez	$at,.L0004f0fc
/*    4f0f0:	02208025 */ 	or	$s0,$s1,$zero
/*    4f0f4:	10000001 */ 	beqz	$zero,.L0004f0fc
/*    4f0f8:	24100020 */ 	addiu	$s0,$zero,0x20
.L0004f0fc:
/*    4f0fc:	1a00000c */ 	blez	$s0,.L0004f130
/*    4f100:	02602025 */ 	or	$a0,$s3,$zero
/*    4f104:	02a02825 */ 	or	$a1,$s5,$zero
/*    4f108:	0280f809 */ 	jalr	$s4
/*    4f10c:	02003025 */ 	or	$a2,$s0,$zero
/*    4f110:	10400005 */ 	beqz	$v0,.L0004f128
/*    4f114:	00409825 */ 	or	$s3,$v0,$zero
/*    4f118:	8faf00cc */ 	lw	$t7,0xcc($sp)
/*    4f11c:	01f0c021 */ 	addu	$t8,$t7,$s0
/*    4f120:	10000003 */ 	beqz	$zero,.L0004f130
/*    4f124:	afb800cc */ 	sw	$t8,0xcc($sp)
.L0004f128:
/*    4f128:	1000007b */ 	beqz	$zero,.L0004f318
/*    4f12c:	8fa200cc */ 	lw	$v0,0xcc($sp)
.L0004f130:
/*    4f130:	02308823 */ 	subu	$s1,$s1,$s0
/*    4f134:	5e20ffed */ 	bgtzl	$s1,.L0004f0ec
/*    4f138:	2e210021 */ 	sltiu	$at,$s1,0x21
.L0004f13c:
/*    4f13c:	8fb900b4 */ 	lw	$t9,0xb4($sp)
.L0004f140:
/*    4f140:	02602025 */ 	or	$a0,$s3,$zero
/*    4f144:	8fa500a8 */ 	lw	$a1,0xa8($sp)
/*    4f148:	5b20000d */ 	blezl	$t9,.L0004f180
/*    4f14c:	8fb900b8 */ 	lw	$t9,0xb8($sp)
/*    4f150:	0280f809 */ 	jalr	$s4
/*    4f154:	03203025 */ 	or	$a2,$t9,$zero
/*    4f158:	10400006 */ 	beqz	$v0,.L0004f174
/*    4f15c:	00409825 */ 	or	$s3,$v0,$zero
/*    4f160:	8fae00cc */ 	lw	$t6,0xcc($sp)
/*    4f164:	8faf00b4 */ 	lw	$t7,0xb4($sp)
/*    4f168:	01cfc021 */ 	addu	$t8,$t6,$t7
/*    4f16c:	10000003 */ 	beqz	$zero,.L0004f17c
/*    4f170:	afb800cc */ 	sw	$t8,0xcc($sp)
.L0004f174:
/*    4f174:	10000068 */ 	beqz	$zero,.L0004f318
/*    4f178:	8fa200cc */ 	lw	$v0,0xcc($sp)
.L0004f17c:
/*    4f17c:	8fb900b8 */ 	lw	$t9,0xb8($sp)
.L0004f180:
/*    4f180:	0019702a */ 	slt	$t6,$zero,$t9
/*    4f184:	51c00019 */ 	beqzl	$t6,.L0004f1ec
/*    4f188:	8fb900bc */ 	lw	$t9,0xbc($sp)
/*    4f18c:	11c00016 */ 	beqz	$t6,.L0004f1e8
/*    4f190:	03208825 */ 	or	$s1,$t9,$zero
/*    4f194:	2e210021 */ 	sltiu	$at,$s1,0x21
.L0004f198:
/*    4f198:	14200003 */ 	bnez	$at,.L0004f1a8
/*    4f19c:	02208025 */ 	or	$s0,$s1,$zero
/*    4f1a0:	10000001 */ 	beqz	$zero,.L0004f1a8
/*    4f1a4:	24100020 */ 	addiu	$s0,$zero,0x20
.L0004f1a8:
/*    4f1a8:	1a00000c */ 	blez	$s0,.L0004f1dc
/*    4f1ac:	02602025 */ 	or	$a0,$s3,$zero
/*    4f1b0:	02a02825 */ 	or	$a1,$s5,$zero
/*    4f1b4:	0280f809 */ 	jalr	$s4
/*    4f1b8:	02003025 */ 	or	$a2,$s0,$zero
/*    4f1bc:	10400005 */ 	beqz	$v0,.L0004f1d4
/*    4f1c0:	00409825 */ 	or	$s3,$v0,$zero
/*    4f1c4:	8faf00cc */ 	lw	$t7,0xcc($sp)
/*    4f1c8:	01f0c021 */ 	addu	$t8,$t7,$s0
/*    4f1cc:	10000003 */ 	beqz	$zero,.L0004f1dc
/*    4f1d0:	afb800cc */ 	sw	$t8,0xcc($sp)
.L0004f1d4:
/*    4f1d4:	10000050 */ 	beqz	$zero,.L0004f318
/*    4f1d8:	8fa200cc */ 	lw	$v0,0xcc($sp)
.L0004f1dc:
/*    4f1dc:	02308823 */ 	subu	$s1,$s1,$s0
/*    4f1e0:	5e20ffed */ 	bgtzl	$s1,.L0004f198
/*    4f1e4:	2e210021 */ 	sltiu	$at,$s1,0x21
.L0004f1e8:
/*    4f1e8:	8fb900bc */ 	lw	$t9,0xbc($sp)
.L0004f1ec:
/*    4f1ec:	02602025 */ 	or	$a0,$s3,$zero
/*    4f1f0:	8fae00a8 */ 	lw	$t6,0xa8($sp)
/*    4f1f4:	1b20000d */ 	blez	$t9,.L0004f22c
/*    4f1f8:	8faf00b4 */ 	lw	$t7,0xb4($sp)
/*    4f1fc:	01cf2821 */ 	addu	$a1,$t6,$t7
/*    4f200:	0280f809 */ 	jalr	$s4
/*    4f204:	03203025 */ 	or	$a2,$t9,$zero
/*    4f208:	10400006 */ 	beqz	$v0,.L0004f224
/*    4f20c:	00409825 */ 	or	$s3,$v0,$zero
/*    4f210:	8fb800cc */ 	lw	$t8,0xcc($sp)
/*    4f214:	8fae00bc */ 	lw	$t6,0xbc($sp)
/*    4f218:	030e7821 */ 	addu	$t7,$t8,$t6
/*    4f21c:	10000003 */ 	beqz	$zero,.L0004f22c
/*    4f220:	afaf00cc */ 	sw	$t7,0xcc($sp)
.L0004f224:
/*    4f224:	1000003c */ 	beqz	$zero,.L0004f318
/*    4f228:	8fa200cc */ 	lw	$v0,0xcc($sp)
.L0004f22c:
/*    4f22c:	8fb900c0 */ 	lw	$t9,0xc0($sp)
/*    4f230:	0019c02a */ 	slt	$t8,$zero,$t9
/*    4f234:	53000019 */ 	beqzl	$t8,.L0004f29c
/*    4f238:	8fb900d0 */ 	lw	$t9,0xd0($sp)
/*    4f23c:	13000016 */ 	beqz	$t8,.L0004f298
/*    4f240:	03208825 */ 	or	$s1,$t9,$zero
/*    4f244:	2e210021 */ 	sltiu	$at,$s1,0x21
.L0004f248:
/*    4f248:	14200003 */ 	bnez	$at,.L0004f258
/*    4f24c:	02208025 */ 	or	$s0,$s1,$zero
/*    4f250:	10000001 */ 	beqz	$zero,.L0004f258
/*    4f254:	24100020 */ 	addiu	$s0,$zero,0x20
.L0004f258:
/*    4f258:	1a00000c */ 	blez	$s0,.L0004f28c
/*    4f25c:	02602025 */ 	or	$a0,$s3,$zero
/*    4f260:	02a02825 */ 	or	$a1,$s5,$zero
/*    4f264:	0280f809 */ 	jalr	$s4
/*    4f268:	02003025 */ 	or	$a2,$s0,$zero
/*    4f26c:	10400005 */ 	beqz	$v0,.L0004f284
/*    4f270:	00409825 */ 	or	$s3,$v0,$zero
/*    4f274:	8fae00cc */ 	lw	$t6,0xcc($sp)
/*    4f278:	01d07821 */ 	addu	$t7,$t6,$s0
/*    4f27c:	10000003 */ 	beqz	$zero,.L0004f28c
/*    4f280:	afaf00cc */ 	sw	$t7,0xcc($sp)
.L0004f284:
/*    4f284:	10000024 */ 	beqz	$zero,.L0004f318
/*    4f288:	8fa200cc */ 	lw	$v0,0xcc($sp)
.L0004f28c:
/*    4f28c:	02308823 */ 	subu	$s1,$s1,$s0
/*    4f290:	5e20ffed */ 	bgtzl	$s1,.L0004f248
/*    4f294:	2e210021 */ 	sltiu	$at,$s1,0x21
.L0004f298:
/*    4f298:	8fb900d0 */ 	lw	$t9,0xd0($sp)
.L0004f29c:
/*    4f29c:	8fae00c8 */ 	lw	$t6,0xc8($sp)
/*    4f2a0:	33380004 */ 	andi	$t8,$t9,0x4
/*    4f2a4:	1300001a */ 	beqz	$t8,.L0004f310
/*    4f2a8:	000e782a */ 	slt	$t7,$zero,$t6
/*    4f2ac:	11e00018 */ 	beqz	$t7,.L0004f310
/*    4f2b0:	00000000 */ 	sll	$zero,$zero,0x0
/*    4f2b4:	11e00016 */ 	beqz	$t7,.L0004f310
/*    4f2b8:	01c08825 */ 	or	$s1,$t6,$zero
/*    4f2bc:	2e210021 */ 	sltiu	$at,$s1,0x21
.L0004f2c0:
/*    4f2c0:	14200003 */ 	bnez	$at,.L0004f2d0
/*    4f2c4:	02208025 */ 	or	$s0,$s1,$zero
/*    4f2c8:	10000001 */ 	beqz	$zero,.L0004f2d0
/*    4f2cc:	24100020 */ 	addiu	$s0,$zero,0x20
.L0004f2d0:
/*    4f2d0:	1a00000c */ 	blez	$s0,.L0004f304
/*    4f2d4:	02602025 */ 	or	$a0,$s3,$zero
/*    4f2d8:	02e02825 */ 	or	$a1,$s7,$zero
/*    4f2dc:	0280f809 */ 	jalr	$s4
/*    4f2e0:	02003025 */ 	or	$a2,$s0,$zero
/*    4f2e4:	10400005 */ 	beqz	$v0,.L0004f2fc
/*    4f2e8:	00409825 */ 	or	$s3,$v0,$zero
/*    4f2ec:	8fb900cc */ 	lw	$t9,0xcc($sp)
/*    4f2f0:	0330c021 */ 	addu	$t8,$t9,$s0
/*    4f2f4:	10000003 */ 	beqz	$zero,.L0004f304
/*    4f2f8:	afb800cc */ 	sw	$t8,0xcc($sp)
.L0004f2fc:
/*    4f2fc:	10000006 */ 	beqz	$zero,.L0004f318
/*    4f300:	8fa200cc */ 	lw	$v0,0xcc($sp)
.L0004f304:
/*    4f304:	02308823 */ 	subu	$s1,$s1,$s0
/*    4f308:	5e20ffed */ 	bgtzl	$s1,.L0004f2c0
/*    4f30c:	2e210021 */ 	sltiu	$at,$s1,0x21
.L0004f310:
/*    4f310:	1000fe93 */ 	beqz	$zero,.L0004ed60
/*    4f314:	26470001 */ 	addiu	$a3,$s2,0x1
.L0004f318:
/*    4f318:	8fbf003c */ 	lw	$ra,0x3c($sp)
/*    4f31c:	8fb00018 */ 	lw	$s0,0x18($sp)
/*    4f320:	8fb1001c */ 	lw	$s1,0x1c($sp)
/*    4f324:	8fb20020 */ 	lw	$s2,0x20($sp)
/*    4f328:	8fb30024 */ 	lw	$s3,0x24($sp)
/*    4f32c:	8fb40028 */ 	lw	$s4,0x28($sp)
/*    4f330:	8fb5002c */ 	lw	$s5,0x2c($sp)
/*    4f334:	8fb60030 */ 	lw	$s6,0x30($sp)
/*    4f338:	8fb70034 */ 	lw	$s7,0x34($sp)
/*    4f33c:	8fbe0038 */ 	lw	$s8,0x38($sp)
/*    4f340:	03e00008 */ 	jr	$ra
/*    4f344:	27bd00d8 */ 	addiu	$sp,$sp,0xd8
/*    4f348:	00000000 */ 	sll	$zero,$zero,0x0
/*    4f34c:	00000000 */ 	sll	$zero,$zero,0x0
);