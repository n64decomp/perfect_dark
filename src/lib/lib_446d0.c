#include <ultra64.h>
#include "constants.h"
#include "game/data/data_000000.h"
#include "game/data/data_0083d0.h"
#include "game/data/data_00e460.h"
#include "game/data/data_0160b0.h"
#include "game/data/data_01a3a0.h"
#include "game/data/data_020df0.h"
#include "gvars/gvars.h"
#include "lib/lib_3e730.h"
#include "lib/lib_4a360.h"
#include "types.h"

GLOBAL_ASM(
glabel func000446d0
/*    446d0:	27bdffb8 */ 	addiu	$sp,$sp,-72
/*    446d4:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    446d8:	afa40048 */ 	sw	$a0,0x48($sp)
/*    446dc:	afa5004c */ 	sw	$a1,0x4c($sp)
/*    446e0:	afa60050 */ 	sw	$a2,0x50($sp)
/*    446e4:	afa70054 */ 	sw	$a3,0x54($sp)
/*    446e8:	8fae004c */ 	lw	$t6,0x4c($sp)
/*    446ec:	afae0044 */ 	sw	$t6,0x44($sp)
/*    446f0:	3c0f8006 */ 	lui	$t7,0x8006
/*    446f4:	8deff114 */ 	lw	$t7,-0xeec($t7)
/*    446f8:	8fb90050 */ 	lw	$t9,0x50($sp)
/*    446fc:	8df80034 */ 	lw	$t8,0x34($t7)
/*    44700:	001940c0 */ 	sll	$t0,$t9,0x3
/*    44704:	01194021 */ 	addu	$t0,$t0,$t9
/*    44708:	000840c0 */ 	sll	$t0,$t0,0x3
/*    4470c:	03084821 */ 	addu	$t1,$t8,$t0
/*    44710:	afa90040 */ 	sw	$t1,0x40($sp)
/*    44714:	8faa0040 */ 	lw	$t2,0x40($sp)
/*    44718:	8d4b001c */ 	lw	$t3,0x1c($t2)
/*    4471c:	afab003c */ 	sw	$t3,0x3c($sp)
/*    44720:	afa00034 */ 	sw	$zero,0x34($sp)
/*    44724:	240c0001 */ 	addiu	$t4,$zero,0x1
/*    44728:	afac0030 */ 	sw	$t4,0x30($sp)
/*    4472c:	8fad0044 */ 	lw	$t5,0x44($sp)
/*    44730:	25ae0008 */ 	addiu	$t6,$t5,0x8
/*    44734:	afae0044 */ 	sw	$t6,0x44($sp)
/*    44738:	afad0028 */ 	sw	$t5,0x28($sp)
/*    4473c:	8fb90028 */ 	lw	$t9,0x28($sp)
/*    44740:	3c0f0200 */ 	lui	$t7,0x200
/*    44744:	35ef07c0 */ 	ori	$t7,$t7,0x7c0
/*    44748:	af2f0000 */ 	sw	$t7,0x0($t9)
/*    4474c:	8fa80028 */ 	lw	$t0,0x28($sp)
/*    44750:	241802e0 */ 	addiu	$t8,$zero,0x2e0
/*    44754:	ad180004 */ 	sw	$t8,0x4($t0)
/*    44758:	8fa90054 */ 	lw	$t1,0x54($sp)
/*    4475c:	ad200000 */ 	sw	$zero,0x0($t1)
/*    44760:	8faa0040 */ 	lw	$t2,0x40($sp)
/*    44764:	afa00038 */ 	sw	$zero,0x38($sp)
/*    44768:	8d4b0014 */ 	lw	$t3,0x14($t2)
/*    4476c:	11600041 */ 	beqz	$t3,.L00044874
/*    44770:	00000000 */ 	sll	$zero,$zero,0x0
.L00044774:
/*    44774:	8fad0038 */ 	lw	$t5,0x38($sp)
/*    44778:	8fac003c */ 	lw	$t4,0x3c($sp)
/*    4477c:	000d7080 */ 	sll	$t6,$t5,0x2
/*    44780:	018e7821 */ 	addu	$t7,$t4,$t6
/*    44784:	8df90000 */ 	lw	$t9,0x0($t7)
/*    44788:	8f380008 */ 	lw	$t8,0x8($t9)
/*    4478c:	13000031 */ 	beqz	$t8,.L00044854
/*    44790:	00000000 */ 	sll	$zero,$zero,0x0
/*    44794:	87080018 */ 	lh	$t0,0x18($t8)
/*    44798:	8fa90050 */ 	lw	$t1,0x50($sp)
/*    4479c:	1509002d */ 	bne	$t0,$t1,.L00044854
/*    447a0:	00000000 */ 	sll	$zero,$zero,0x0
/*    447a4:	8f0a0008 */ 	lw	$t2,0x8($t8)
/*    447a8:	1140002a */ 	beqz	$t2,.L00044854
/*    447ac:	00000000 */ 	sll	$zero,$zero,0x0
/*    447b0:	914b008c */ 	lbu	$t3,0x8c($t2)
/*    447b4:	29610040 */ 	slti	$at,$t3,0x40
/*    447b8:	14200026 */ 	bnez	$at,.L00044854
/*    447bc:	00000000 */ 	sll	$zero,$zero,0x0
/*    447c0:	8fac0038 */ 	lw	$t4,0x38($sp)
/*    447c4:	8fad003c */ 	lw	$t5,0x3c($sp)
/*    447c8:	8fa50048 */ 	lw	$a1,0x48($sp)
/*    447cc:	000c7080 */ 	sll	$t6,$t4,0x2
/*    447d0:	01ae7821 */ 	addu	$t7,$t5,$t6
/*    447d4:	8de40000 */ 	lw	$a0,0x0($t7)
/*    447d8:	0c00fa30 */ 	jal	func0003e8c0
/*    447dc:	8fa60044 */ 	lw	$a2,0x44($sp)
/*    447e0:	afa20044 */ 	sw	$v0,0x44($sp)
/*    447e4:	8fb90054 */ 	lw	$t9,0x54($sp)
/*    447e8:	8f280000 */ 	lw	$t0,0x0($t9)
/*    447ec:	25090001 */ 	addiu	$t1,$t0,0x1
/*    447f0:	af290000 */ 	sw	$t1,0x0($t9)
/*    447f4:	8fb80034 */ 	lw	$t8,0x34($sp)
/*    447f8:	270a0001 */ 	addiu	$t2,$t8,0x1
/*    447fc:	afaa0034 */ 	sw	$t2,0x34($sp)
/*    44800:	8fac0038 */ 	lw	$t4,0x38($sp)
/*    44804:	8fab003c */ 	lw	$t3,0x3c($sp)
/*    44808:	8fb80030 */ 	lw	$t8,0x30($sp)
/*    4480c:	000c6880 */ 	sll	$t5,$t4,0x2
/*    44810:	016d7021 */ 	addu	$t6,$t3,$t5
/*    44814:	8dcf0000 */ 	lw	$t7,0x0($t6)
/*    44818:	8de80008 */ 	lw	$t0,0x8($t7)
/*    4481c:	8d090008 */ 	lw	$t1,0x8($t0)
/*    44820:	9139008c */ 	lbu	$t9,0x8c($t1)
/*    44824:	0319082b */ 	sltu	$at,$t8,$t9
/*    44828:	1020000a */ 	beqz	$at,.L00044854
/*    4482c:	00000000 */ 	sll	$zero,$zero,0x0
/*    44830:	8fac0038 */ 	lw	$t4,0x38($sp)
/*    44834:	8faa003c */ 	lw	$t2,0x3c($sp)
/*    44838:	000c5880 */ 	sll	$t3,$t4,0x2
/*    4483c:	014b6821 */ 	addu	$t5,$t2,$t3
/*    44840:	8dae0000 */ 	lw	$t6,0x0($t5)
/*    44844:	8dcf0008 */ 	lw	$t7,0x8($t6)
/*    44848:	8de80008 */ 	lw	$t0,0x8($t7)
/*    4484c:	9109008c */ 	lbu	$t1,0x8c($t0)
/*    44850:	afa90030 */ 	sw	$t1,0x30($sp)
.L00044854:
/*    44854:	8fb90038 */ 	lw	$t9,0x38($sp)
/*    44858:	8fac0040 */ 	lw	$t4,0x40($sp)
/*    4485c:	27380001 */ 	addiu	$t8,$t9,0x1
/*    44860:	afb80038 */ 	sw	$t8,0x38($sp)
/*    44864:	8d8a0014 */ 	lw	$t2,0x14($t4)
/*    44868:	030a082b */ 	sltu	$at,$t8,$t2
/*    4486c:	1420ffc1 */ 	bnez	$at,.L00044774
/*    44870:	00000000 */ 	sll	$zero,$zero,0x0
.L00044874:
/*    44874:	8fab0034 */ 	lw	$t3,0x34($sp)
/*    44878:	11600088 */ 	beqz	$t3,.L00044a9c
/*    4487c:	00000000 */ 	sll	$zero,$zero,0x0
/*    44880:	8fad0030 */ 	lw	$t5,0x30($sp)
/*    44884:	25aeffc2 */ 	addiu	$t6,$t5,-62
/*    44888:	afae0030 */ 	sw	$t6,0x30($sp)
/*    4488c:	8faf0030 */ 	lw	$t7,0x30($sp)
/*    44890:	2de10007 */ 	sltiu	$at,$t7,0x7
/*    44894:	14200033 */ 	bnez	$at,.L00044964
/*    44898:	00000000 */ 	sll	$zero,$zero,0x0
/*    4489c:	8fa80030 */ 	lw	$t0,0x30($sp)
/*    448a0:	44882000 */ 	mtc1	$t0,$f4
/*    448a4:	05010005 */ 	bgez	$t0,.L000448bc
/*    448a8:	46802320 */ 	cvt.s.w	$f12,$f4
/*    448ac:	3c014f80 */ 	lui	$at,0x4f80
/*    448b0:	44813000 */ 	mtc1	$at,$f6
/*    448b4:	00000000 */ 	sll	$zero,$zero,0x0
/*    448b8:	46066300 */ 	add.s	$f12,$f12,$f6
.L000448bc:
/*    448bc:	0c012974 */ 	jal	sqrtf
/*    448c0:	00000000 */ 	sll	$zero,$zero,0x0
/*    448c4:	3c017006 */ 	lui	$at,0x7006
/*    448c8:	c4289c70 */ 	lwc1	$f8,-0x6390($at)
/*    448cc:	24190001 */ 	addiu	$t9,$zero,0x1
/*    448d0:	46004283 */ 	div.s	$f10,$f8,$f0
/*    448d4:	4449f800 */ 	cfc1	$t1,$31
/*    448d8:	44d9f800 */ 	ctc1	$t9,$31
/*    448dc:	00000000 */ 	sll	$zero,$zero,0x0
/*    448e0:	46005424 */ 	cvt.w.s	$f16,$f10
/*    448e4:	4459f800 */ 	cfc1	$t9,$31
/*    448e8:	00000000 */ 	sll	$zero,$zero,0x0
/*    448ec:	33210004 */ 	andi	$at,$t9,0x4
/*    448f0:	33390078 */ 	andi	$t9,$t9,0x78
/*    448f4:	13200014 */ 	beqz	$t9,.L00044948
/*    448f8:	00000000 */ 	sll	$zero,$zero,0x0
/*    448fc:	3c014f00 */ 	lui	$at,0x4f00
/*    44900:	44818000 */ 	mtc1	$at,$f16
/*    44904:	24190001 */ 	addiu	$t9,$zero,0x1
/*    44908:	46105401 */ 	sub.s	$f16,$f10,$f16
/*    4490c:	44d9f800 */ 	ctc1	$t9,$31
/*    44910:	00000000 */ 	sll	$zero,$zero,0x0
/*    44914:	46008424 */ 	cvt.w.s	$f16,$f16
/*    44918:	4459f800 */ 	cfc1	$t9,$31
/*    4491c:	00000000 */ 	sll	$zero,$zero,0x0
/*    44920:	33210004 */ 	andi	$at,$t9,0x4
/*    44924:	33390078 */ 	andi	$t9,$t9,0x78
/*    44928:	17200005 */ 	bnez	$t9,.L00044940
/*    4492c:	00000000 */ 	sll	$zero,$zero,0x0
/*    44930:	44198000 */ 	mfc1	$t9,$f16
/*    44934:	3c018000 */ 	lui	$at,0x8000
/*    44938:	10000007 */ 	beqz	$zero,.L00044958
/*    4493c:	0321c825 */ 	or	$t9,$t9,$at
.L00044940:
/*    44940:	10000005 */ 	beqz	$zero,.L00044958
/*    44944:	2419ffff */ 	addiu	$t9,$zero,-1
.L00044948:
/*    44948:	44198000 */ 	mfc1	$t9,$f16
/*    4494c:	00000000 */ 	sll	$zero,$zero,0x0
/*    44950:	0720fffb */ 	bltz	$t9,.L00044940
/*    44954:	00000000 */ 	sll	$zero,$zero,0x0
.L00044958:
/*    44958:	44c9f800 */ 	ctc1	$t1,$31
/*    4495c:	10000031 */ 	beqz	$zero,.L00044a24
/*    44960:	afb9002c */ 	sw	$t9,0x2c($sp)
.L00044964:
/*    44964:	8fac0030 */ 	lw	$t4,0x30($sp)
/*    44968:	3c014780 */ 	lui	$at,0x4780
/*    4496c:	44819000 */ 	mtc1	$at,$f18
/*    44970:	448c2000 */ 	mtc1	$t4,$f4
/*    44974:	05810005 */ 	bgez	$t4,.L0004498c
/*    44978:	468021a0 */ 	cvt.s.w	$f6,$f4
/*    4497c:	3c014f80 */ 	lui	$at,0x4f80
/*    44980:	44814000 */ 	mtc1	$at,$f8
/*    44984:	00000000 */ 	sll	$zero,$zero,0x0
/*    44988:	46083180 */ 	add.s	$f6,$f6,$f8
.L0004498c:
/*    4498c:	46069283 */ 	div.s	$f10,$f18,$f6
/*    44990:	240a0001 */ 	addiu	$t2,$zero,0x1
/*    44994:	4458f800 */ 	cfc1	$t8,$31
/*    44998:	44caf800 */ 	ctc1	$t2,$31
/*    4499c:	00000000 */ 	sll	$zero,$zero,0x0
/*    449a0:	46005424 */ 	cvt.w.s	$f16,$f10
/*    449a4:	444af800 */ 	cfc1	$t2,$31
/*    449a8:	00000000 */ 	sll	$zero,$zero,0x0
/*    449ac:	31410004 */ 	andi	$at,$t2,0x4
/*    449b0:	314a0078 */ 	andi	$t2,$t2,0x78
/*    449b4:	11400014 */ 	beqz	$t2,.L00044a08
/*    449b8:	00000000 */ 	sll	$zero,$zero,0x0
/*    449bc:	3c014f00 */ 	lui	$at,0x4f00
/*    449c0:	44818000 */ 	mtc1	$at,$f16
/*    449c4:	240a0001 */ 	addiu	$t2,$zero,0x1
/*    449c8:	46105401 */ 	sub.s	$f16,$f10,$f16
/*    449cc:	44caf800 */ 	ctc1	$t2,$31
/*    449d0:	00000000 */ 	sll	$zero,$zero,0x0
/*    449d4:	46008424 */ 	cvt.w.s	$f16,$f16
/*    449d8:	444af800 */ 	cfc1	$t2,$31
/*    449dc:	00000000 */ 	sll	$zero,$zero,0x0
/*    449e0:	31410004 */ 	andi	$at,$t2,0x4
/*    449e4:	314a0078 */ 	andi	$t2,$t2,0x78
/*    449e8:	15400005 */ 	bnez	$t2,.L00044a00
/*    449ec:	00000000 */ 	sll	$zero,$zero,0x0
/*    449f0:	440a8000 */ 	mfc1	$t2,$f16
/*    449f4:	3c018000 */ 	lui	$at,0x8000
/*    449f8:	10000007 */ 	beqz	$zero,.L00044a18
/*    449fc:	01415025 */ 	or	$t2,$t2,$at
.L00044a00:
/*    44a00:	10000005 */ 	beqz	$zero,.L00044a18
/*    44a04:	240affff */ 	addiu	$t2,$zero,-1
.L00044a08:
/*    44a08:	440a8000 */ 	mfc1	$t2,$f16
/*    44a0c:	00000000 */ 	sll	$zero,$zero,0x0
/*    44a10:	0540fffb */ 	bltz	$t2,.L00044a00
/*    44a14:	00000000 */ 	sll	$zero,$zero,0x0
.L00044a18:
/*    44a18:	44d8f800 */ 	ctc1	$t8,$31
/*    44a1c:	afaa002c */ 	sw	$t2,0x2c($sp)
/*    44a20:	00000000 */ 	sll	$zero,$zero,0x0
.L00044a24:
/*    44a24:	8fab0044 */ 	lw	$t3,0x44($sp)
/*    44a28:	256d0008 */ 	addiu	$t5,$t3,0x8
/*    44a2c:	afad0044 */ 	sw	$t5,0x44($sp)
/*    44a30:	afab0024 */ 	sw	$t3,0x24($sp)
/*    44a34:	8faf0024 */ 	lw	$t7,0x24($sp)
/*    44a38:	240e04e0 */ 	addiu	$t6,$zero,0x4e0
/*    44a3c:	adee0000 */ 	sw	$t6,0x0($t7)
/*    44a40:	8fa8002c */ 	lw	$t0,0x2c($sp)
/*    44a44:	8fac0030 */ 	lw	$t4,0x30($sp)
/*    44a48:	8fab0024 */ 	lw	$t3,0x24($sp)
/*    44a4c:	3109ffff */ 	andi	$t1,$t0,0xffff
/*    44a50:	0009cc00 */ 	sll	$t9,$t1,0x10
/*    44a54:	3198ffff */ 	andi	$t8,$t4,0xffff
/*    44a58:	03385025 */ 	or	$t2,$t9,$t8
/*    44a5c:	ad6a0004 */ 	sw	$t2,0x4($t3)
/*    44a60:	8fad0044 */ 	lw	$t5,0x44($sp)
/*    44a64:	25ae0008 */ 	addiu	$t6,$t5,0x8
/*    44a68:	afae0044 */ 	sw	$t6,0x44($sp)
/*    44a6c:	afad0020 */ 	sw	$t5,0x20($sp)
/*    44a70:	8fa80020 */ 	lw	$t0,0x20($sp)
/*    44a74:	240f0650 */ 	addiu	$t7,$zero,0x650
/*    44a78:	ad0f0000 */ 	sw	$t7,0x0($t0)
/*    44a7c:	8fa9002c */ 	lw	$t1,0x2c($sp)
/*    44a80:	8fb80030 */ 	lw	$t8,0x30($sp)
/*    44a84:	8fad0020 */ 	lw	$t5,0x20($sp)
/*    44a88:	312cffff */ 	andi	$t4,$t1,0xffff
/*    44a8c:	000ccc00 */ 	sll	$t9,$t4,0x10
/*    44a90:	330affff */ 	andi	$t2,$t8,0xffff
/*    44a94:	032a5825 */ 	or	$t3,$t9,$t2
/*    44a98:	adab0004 */ 	sw	$t3,0x4($t5)
.L00044a9c:
/*    44a9c:	8fae0040 */ 	lw	$t6,0x40($sp)
/*    44aa0:	afa00038 */ 	sw	$zero,0x38($sp)
/*    44aa4:	8dcf0014 */ 	lw	$t7,0x14($t6)
/*    44aa8:	11e0003a */ 	beqz	$t7,.L00044b94
/*    44aac:	00000000 */ 	sll	$zero,$zero,0x0
.L00044ab0:
/*    44ab0:	8fa90038 */ 	lw	$t1,0x38($sp)
/*    44ab4:	8fa8003c */ 	lw	$t0,0x3c($sp)
/*    44ab8:	00096080 */ 	sll	$t4,$t1,0x2
/*    44abc:	010cc021 */ 	addu	$t8,$t0,$t4
/*    44ac0:	8f190000 */ 	lw	$t9,0x0($t8)
/*    44ac4:	8f2a0008 */ 	lw	$t2,0x8($t9)
/*    44ac8:	1140000c */ 	beqz	$t2,.L00044afc
/*    44acc:	00000000 */ 	sll	$zero,$zero,0x0
/*    44ad0:	854b0018 */ 	lh	$t3,0x18($t2)
/*    44ad4:	8fad0050 */ 	lw	$t5,0x50($sp)
/*    44ad8:	156d0008 */ 	bne	$t3,$t5,.L00044afc
/*    44adc:	00000000 */ 	sll	$zero,$zero,0x0
/*    44ae0:	8d4e0008 */ 	lw	$t6,0x8($t2)
/*    44ae4:	11c00010 */ 	beqz	$t6,.L00044b28
/*    44ae8:	00000000 */ 	sll	$zero,$zero,0x0
/*    44aec:	91cf008c */ 	lbu	$t7,0x8c($t6)
/*    44af0:	29e10040 */ 	slti	$at,$t7,0x40
/*    44af4:	1420000c */ 	bnez	$at,.L00044b28
/*    44af8:	00000000 */ 	sll	$zero,$zero,0x0
.L00044afc:
/*    44afc:	8fa80038 */ 	lw	$t0,0x38($sp)
/*    44b00:	8fa9003c */ 	lw	$t1,0x3c($sp)
/*    44b04:	00086080 */ 	sll	$t4,$t0,0x2
/*    44b08:	012cc021 */ 	addu	$t8,$t1,$t4
/*    44b0c:	8f190000 */ 	lw	$t9,0x0($t8)
/*    44b10:	8f2b0008 */ 	lw	$t3,0x8($t9)
/*    44b14:	15600017 */ 	bnez	$t3,.L00044b74
/*    44b18:	00000000 */ 	sll	$zero,$zero,0x0
/*    44b1c:	8fad0050 */ 	lw	$t5,0x50($sp)
/*    44b20:	15a00014 */ 	bnez	$t5,.L00044b74
/*    44b24:	00000000 */ 	sll	$zero,$zero,0x0
.L00044b28:
/*    44b28:	8faa0044 */ 	lw	$t2,0x44($sp)
/*    44b2c:	afaa001c */ 	sw	$t2,0x1c($sp)
/*    44b30:	8faf0038 */ 	lw	$t7,0x38($sp)
/*    44b34:	8fae003c */ 	lw	$t6,0x3c($sp)
/*    44b38:	8fa50048 */ 	lw	$a1,0x48($sp)
/*    44b3c:	000f4080 */ 	sll	$t0,$t7,0x2
/*    44b40:	01c84821 */ 	addu	$t1,$t6,$t0
/*    44b44:	8d240000 */ 	lw	$a0,0x0($t1)
/*    44b48:	0c00fa30 */ 	jal	func0003e8c0
/*    44b4c:	8fa60044 */ 	lw	$a2,0x44($sp)
/*    44b50:	afa20044 */ 	sw	$v0,0x44($sp)
/*    44b54:	8fac0044 */ 	lw	$t4,0x44($sp)
/*    44b58:	8fb8001c */ 	lw	$t8,0x1c($sp)
/*    44b5c:	11980005 */ 	beq	$t4,$t8,.L00044b74
/*    44b60:	00000000 */ 	sll	$zero,$zero,0x0
/*    44b64:	8fb90054 */ 	lw	$t9,0x54($sp)
/*    44b68:	8f2b0000 */ 	lw	$t3,0x0($t9)
/*    44b6c:	256d0001 */ 	addiu	$t5,$t3,0x1
/*    44b70:	af2d0000 */ 	sw	$t5,0x0($t9)
.L00044b74:
/*    44b74:	8faa0038 */ 	lw	$t2,0x38($sp)
/*    44b78:	8fae0040 */ 	lw	$t6,0x40($sp)
/*    44b7c:	254f0001 */ 	addiu	$t7,$t2,0x1
/*    44b80:	afaf0038 */ 	sw	$t7,0x38($sp)
/*    44b84:	8dc80014 */ 	lw	$t0,0x14($t6)
/*    44b88:	01e8082b */ 	sltu	$at,$t7,$t0
/*    44b8c:	1420ffc8 */ 	bnez	$at,.L00044ab0
/*    44b90:	00000000 */ 	sll	$zero,$zero,0x0
.L00044b94:
/*    44b94:	10000003 */ 	beqz	$zero,.L00044ba4
/*    44b98:	8fa20044 */ 	lw	$v0,0x44($sp)
/*    44b9c:	10000001 */ 	beqz	$zero,.L00044ba4
/*    44ba0:	00000000 */ 	sll	$zero,$zero,0x0
.L00044ba4:
/*    44ba4:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    44ba8:	27bd0048 */ 	addiu	$sp,$sp,0x48
/*    44bac:	03e00008 */ 	jr	$ra
/*    44bb0:	00000000 */ 	sll	$zero,$zero,0x0
/*    44bb4:	00000000 */ 	sll	$zero,$zero,0x0
/*    44bb8:	00000000 */ 	sll	$zero,$zero,0x0
/*    44bbc:	00000000 */ 	sll	$zero,$zero,0x0
);