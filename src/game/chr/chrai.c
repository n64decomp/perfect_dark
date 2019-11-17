#include <ultra64.h>
#include "constants.h"
#include "gvars/gvars.h"
#include "setup/setup_000000.h"
#include "setup/setup_0160b0.h"
#include "setup/setup_020df0.h"
#include "types.h"
#include "game/chr/chrai.h"
#include "library/library_12dc0.h"
#include "library/library_16110.h"

GLOBAL_ASM(
glabel chraiEndList
/*  f04d560:	3c08800a */ 	lui	$t0,%hi(var8009d030)
/*  f04d564:	2508d030 */ 	addiu	$t0,$t0,%lo(var8009d030)
/*  f04d568:	8d020018 */ 	lw	$v0,0x18($t0)
/*  f04d56c:	00a03825 */ 	or	$a3,$a1,$zero
/*  f04d570:	3c198008 */ 	lui	$t9,0x8008
/*  f04d574:	10400013 */ 	beqz	$v0,.L0f04d5c4
/*  f04d578:	00000000 */ 	sll	$zero,$zero,0x0
/*  f04d57c:	8c4e0000 */ 	lw	$t6,0x0($v0)
/*  f04d580:	00001825 */ 	or	$v1,$zero,$zero
/*  f04d584:	00402825 */ 	or	$a1,$v0,$zero
/*  f04d588:	11c0000e */ 	beqz	$t6,.L0f04d5c4
/*  f04d58c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f04d590:	8c460000 */ 	lw	$a2,0x0($v0)
.L0f04d594:
/*  f04d594:	54860007 */ 	bnel	$a0,$a2,.L0f04d5b4
/*  f04d598:	8ca60008 */ 	lw	$a2,0x8($a1)
/*  f04d59c:	ace00000 */ 	sw	$zero,0x0($a3)
/*  f04d5a0:	8d0f0018 */ 	lw	$t7,0x18($t0)
/*  f04d5a4:	01e3c021 */ 	addu	$t8,$t7,$v1
/*  f04d5a8:	03e00008 */ 	jr	$ra
/*  f04d5ac:	8f020004 */ 	lw	$v0,0x4($t8)
/*  f04d5b0:	8ca60008 */ 	lw	$a2,0x8($a1)
.L0f04d5b4:
/*  f04d5b4:	24630008 */ 	addiu	$v1,$v1,0x8
/*  f04d5b8:	24a50008 */ 	addiu	$a1,$a1,0x8
/*  f04d5bc:	14c0fff5 */ 	bnez	$a2,.L0f04d594
/*  f04d5c0:	00000000 */ 	sll	$zero,$zero,0x0
.L0f04d5c4:
/*  f04d5c4:	8f39ac58 */ 	lw	$t9,-0x53a8($t9)
/*  f04d5c8:	3c098008 */ 	lui	$t1,0x8008
/*  f04d5cc:	2523ac58 */ 	addiu	$v1,$t1,-21416
/*  f04d5d0:	1320000b */ 	beqz	$t9,.L0f04d600
/*  f04d5d4:	240a0001 */ 	addiu	$t2,$zero,0x1
/*  f04d5d8:	8c620000 */ 	lw	$v0,0x0($v1)
.L0f04d5dc:
/*  f04d5dc:	54820005 */ 	bnel	$a0,$v0,.L0f04d5f4
/*  f04d5e0:	8c620008 */ 	lw	$v0,0x8($v1)
/*  f04d5e4:	acea0000 */ 	sw	$t2,0x0($a3)
/*  f04d5e8:	03e00008 */ 	jr	$ra
/*  f04d5ec:	8c620004 */ 	lw	$v0,0x4($v1)
/*  f04d5f0:	8c620008 */ 	lw	$v0,0x8($v1)
.L0f04d5f4:
/*  f04d5f4:	24630008 */ 	addiu	$v1,$v1,0x8
/*  f04d5f8:	1440fff8 */ 	bnez	$v0,.L0f04d5dc
/*  f04d5fc:	00000000 */ 	sll	$zero,$zero,0x0
.L0f04d600:
/*  f04d600:	2402ffff */ 	addiu	$v0,$zero,-1
/*  f04d604:	03e00008 */ 	jr	$ra
/*  f04d608:	00000000 */ 	sll	$zero,$zero,0x0
);

u32 chraiGoToLabel(u8 *ailist, u32 aioffset, u8 label)
{
	do {
		u8 *cmd = aioffset + ailist;
		u32 type = (cmd[0] << 8) + cmd[1];

		if (type == CMD_LABEL) {
			if (label == cmd[2]) {
				return aioffset;
			}
		} else if (type == CMD_END) {
			return 0;
		}

		aioffset += chraiGetCommandLength(ailist, aioffset);
	} while (true);
}

GLOBAL_ASM(
glabel chraiExecute
/*  f04d6b4:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*  f04d6b8:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f04d6bc:	3c10800a */ 	lui	$s0,%hi(g_Vars)
/*  f04d6c0:	26109fc0 */ 	addiu	$s0,$s0,%lo(g_Vars)
/*  f04d6c4:	24010003 */ 	addiu	$at,$zero,0x3
/*  f04d6c8:	afbf001c */ 	sw	$ra,0x1c($sp)
/*  f04d6cc:	ae000424 */ 	sw	$zero,0x424($s0)
/*  f04d6d0:	ae000428 */ 	sw	$zero,0x428($s0)
/*  f04d6d4:	ae00042c */ 	sw	$zero,0x42c($s0)
/*  f04d6d8:	ae000430 */ 	sw	$zero,0x430($s0)
/*  f04d6dc:	ae000434 */ 	sw	$zero,0x434($s0)
/*  f04d6e0:	14a10003 */ 	bne	$a1,$at,.L0f04d6f0
/*  f04d6e4:	ae000438 */ 	sw	$zero,0x438($s0)
/*  f04d6e8:	10000015 */ 	beqz	$zero,.L0f04d740
/*  f04d6ec:	ae040424 */ 	sw	$a0,0x424($s0)
.L0f04d6f0:
/*  f04d6f0:	24010001 */ 	addiu	$at,$zero,0x1
/*  f04d6f4:	54a10013 */ 	bnel	$a1,$at,.L0f04d744
/*  f04d6f8:	8e070424 */ 	lw	$a3,0x424($s0)
/*  f04d6fc:	90820003 */ 	lbu	$v0,0x3($a0)
/*  f04d700:	24010027 */ 	addiu	$at,$zero,0x27
/*  f04d704:	54410004 */ 	bnel	$v0,$at,.L0f04d718
/*  f04d708:	24010028 */ 	addiu	$at,$zero,0x28
/*  f04d70c:	1000000c */ 	beqz	$zero,.L0f04d740
/*  f04d710:	ae040428 */ 	sw	$a0,0x428($s0)
/*  f04d714:	24010028 */ 	addiu	$at,$zero,0x28
.L0f04d718:
/*  f04d718:	54410004 */ 	bnel	$v0,$at,.L0f04d72c
/*  f04d71c:	24010037 */ 	addiu	$at,$zero,0x37
/*  f04d720:	10000007 */ 	beqz	$zero,.L0f04d740
/*  f04d724:	ae04042c */ 	sw	$a0,0x42c($s0)
/*  f04d728:	24010037 */ 	addiu	$at,$zero,0x37
.L0f04d72c:
/*  f04d72c:	10410003 */ 	beq	$v0,$at,.L0f04d73c
/*  f04d730:	24010039 */ 	addiu	$at,$zero,0x39
/*  f04d734:	54410003 */ 	bnel	$v0,$at,.L0f04d744
/*  f04d738:	8e070424 */ 	lw	$a3,0x424($s0)
.L0f04d73c:
/*  f04d73c:	ae040430 */ 	sw	$a0,0x430($s0)
.L0f04d740:
/*  f04d740:	8e070424 */ 	lw	$a3,0x424($s0)
.L0f04d744:
/*  f04d744:	50e00007 */ 	beqzl	$a3,.L0f04d764
/*  f04d748:	8e020428 */ 	lw	$v0,0x428($s0)
/*  f04d74c:	8cee0108 */ 	lw	$t6,0x108($a3)
/*  f04d750:	ae0e0434 */ 	sw	$t6,0x434($s0)
/*  f04d754:	94ef010c */ 	lhu	$t7,0x10c($a3)
/*  f04d758:	10000018 */ 	beqz	$zero,.L0f04d7bc
/*  f04d75c:	ae0f0438 */ 	sw	$t7,0x438($s0)
/*  f04d760:	8e020428 */ 	lw	$v0,0x428($s0)
.L0f04d764:
/*  f04d764:	50400007 */ 	beqzl	$v0,.L0f04d784
/*  f04d768:	8e02042c */ 	lw	$v0,0x42c($s0)
/*  f04d76c:	8c58005c */ 	lw	$t8,0x5c($v0)
/*  f04d770:	ae180434 */ 	sw	$t8,0x434($s0)
/*  f04d774:	94590060 */ 	lhu	$t9,0x60($v0)
/*  f04d778:	10000010 */ 	beqz	$zero,.L0f04d7bc
/*  f04d77c:	ae190438 */ 	sw	$t9,0x438($s0)
/*  f04d780:	8e02042c */ 	lw	$v0,0x42c($s0)
.L0f04d784:
/*  f04d784:	50400007 */ 	beqzl	$v0,.L0f04d7a4
/*  f04d788:	8e020430 */ 	lw	$v0,0x430($s0)
/*  f04d78c:	8c48005c */ 	lw	$t0,0x5c($v0)
/*  f04d790:	ae080434 */ 	sw	$t0,0x434($s0)
/*  f04d794:	94490060 */ 	lhu	$t1,0x60($v0)
/*  f04d798:	10000008 */ 	beqz	$zero,.L0f04d7bc
/*  f04d79c:	ae090438 */ 	sw	$t1,0x438($s0)
/*  f04d7a0:	8e020430 */ 	lw	$v0,0x430($s0)
.L0f04d7a4:
/*  f04d7a4:	50400006 */ 	beqzl	$v0,.L0f04d7c0
/*  f04d7a8:	8e0c0434 */ 	lw	$t4,0x434($s0)
/*  f04d7ac:	8c4a005c */ 	lw	$t2,0x5c($v0)
/*  f04d7b0:	ae0a0434 */ 	sw	$t2,0x434($s0)
/*  f04d7b4:	944b0060 */ 	lhu	$t3,0x60($v0)
/*  f04d7b8:	ae0b0438 */ 	sw	$t3,0x438($s0)
.L0f04d7bc:
/*  f04d7bc:	8e0c0434 */ 	lw	$t4,0x434($s0)
.L0f04d7c0:
/*  f04d7c0:	518000db */ 	beqzl	$t4,.L0f04db30
/*  f04d7c4:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f04d7c8:	10e00004 */ 	beqz	$a3,.L0f04d7dc
/*  f04d7cc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f04d7d0:	0fc13111 */ 	jal	func0f04c444
/*  f04d7d4:	00e02025 */ 	or	$a0,$a3,$zero
/*  f04d7d8:	8e070424 */ 	lw	$a3,0x424($s0)
.L0f04d7dc:
/*  f04d7dc:	10e0002c */ 	beqz	$a3,.L0f04d890
/*  f04d7e0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f04d7e4:	8ced0018 */ 	lw	$t5,0x18($a3)
/*  f04d7e8:	000d7280 */ 	sll	$t6,$t5,0xa
/*  f04d7ec:	05c10028 */ 	bgez	$t6,.L0f04d890
/*  f04d7f0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f04d7f4:	0c00744f */ 	jal	func0001d13c
/*  f04d7f8:	8ce40020 */ 	lw	$a0,0x20($a3)
/*  f04d7fc:	8e070424 */ 	lw	$a3,0x424($s0)
/*  f04d800:	84ef0110 */ 	lh	$t7,0x110($a3)
/*  f04d804:	05e00020 */ 	bltz	$t7,.L0f04d888
/*  f04d808:	00000000 */ 	sll	$zero,$zero,0x0
/*  f04d80c:	44800000 */ 	mtc1	$zero,$f0
/*  f04d810:	c4e40180 */ 	lwc1	$f4,0x180($a3)
/*  f04d814:	4600203e */ 	c.le.s	$f4,$f0
/*  f04d818:	00000000 */ 	sll	$zero,$zero,0x0
/*  f04d81c:	4500001a */ 	bc1f	.L0f04d888
/*  f04d820:	00000000 */ 	sll	$zero,$zero,0x0
/*  f04d824:	c4e60100 */ 	lwc1	$f6,0x100($a3)
/*  f04d828:	24010269 */ 	addiu	$at,$zero,0x269
/*  f04d82c:	4606003e */ 	c.le.s	$f0,$f6
/*  f04d830:	00000000 */ 	sll	$zero,$zero,0x0
/*  f04d834:	45010004 */ 	bc1t	.L0f04d848
/*  f04d838:	00000000 */ 	sll	$zero,$zero,0x0
/*  f04d83c:	8cf80300 */ 	lw	$t8,0x300($a3)
/*  f04d840:	13000011 */ 	beqz	$t8,.L0f04d888
/*  f04d844:	00000000 */ 	sll	$zero,$zero,0x0
.L0f04d848:
/*  f04d848:	1041000f */ 	beq	$v0,$at,.L0f04d888
/*  f04d84c:	2401026b */ 	addiu	$at,$zero,0x26b
/*  f04d850:	1041000d */ 	beq	$v0,$at,.L0f04d888
/*  f04d854:	2401026a */ 	addiu	$at,$zero,0x26a
/*  f04d858:	1041000b */ 	beq	$v0,$at,.L0f04d888
/*  f04d85c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f04d860:	8cf90018 */ 	lw	$t9,0x18($a3)
/*  f04d864:	3c01ffdf */ 	lui	$at,0xffdf
/*  f04d868:	3421ffff */ 	ori	$at,$at,0xffff
/*  f04d86c:	03214024 */ 	and	$t0,$t9,$at
/*  f04d870:	ace80018 */ 	sw	$t0,0x18($a3)
/*  f04d874:	8e090424 */ 	lw	$t1,0x424($s0)
/*  f04d878:	0c006134 */ 	jal	ailistFindById
/*  f04d87c:	85240110 */ 	lh	$a0,0x110($t1)
/*  f04d880:	ae020434 */ 	sw	$v0,0x434($s0)
/*  f04d884:	ae000438 */ 	sw	$zero,0x438($s0)
.L0f04d888:
/*  f04d888:	1000008b */ 	beqz	$zero,.L0f04dab8
/*  f04d88c:	8e040434 */ 	lw	$a0,0x434($s0)
.L0f04d890:
/*  f04d890:	10e00052 */ 	beqz	$a3,.L0f04d9dc
/*  f04d894:	00000000 */ 	sll	$zero,$zero,0x0
/*  f04d898:	8ce20018 */ 	lw	$v0,0x18($a3)
/*  f04d89c:	3c01f7ff */ 	lui	$at,0xf7ff
/*  f04d8a0:	3421ffff */ 	ori	$at,$at,0xffff
/*  f04d8a4:	00025100 */ 	sll	$t2,$v0,0x4
/*  f04d8a8:	0541004c */ 	bgez	$t2,.L0f04d9dc
/*  f04d8ac:	00415824 */ 	and	$t3,$v0,$at
/*  f04d8b0:	aceb0018 */ 	sw	$t3,0x18($a3)
/*  f04d8b4:	8e0c0424 */ 	lw	$t4,0x424($s0)
/*  f04d8b8:	85840356 */ 	lh	$a0,0x356($t4)
/*  f04d8bc:	0482003b */ 	bltzl	$a0,.L0f04d9ac
/*  f04d8c0:	8e070424 */ 	lw	$a3,0x424($s0)
/*  f04d8c4:	0c006134 */ 	jal	ailistFindById
/*  f04d8c8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f04d8cc:	8e0d0424 */ 	lw	$t5,0x424($s0)
/*  f04d8d0:	8dae0108 */ 	lw	$t6,0x108($t5)
/*  f04d8d4:	504e0035 */ 	beql	$v0,$t6,.L0f04d9ac
/*  f04d8d8:	8e070424 */ 	lw	$a3,0x424($s0)
/*  f04d8dc:	0c004b70 */ 	jal	random
/*  f04d8e0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f04d8e4:	24010064 */ 	addiu	$at,$zero,0x64
/*  f04d8e8:	0041001b */ 	divu	$zero,$v0,$at
/*  f04d8ec:	8e070424 */ 	lw	$a3,0x424($s0)
/*  f04d8f0:	00007810 */ 	mfhi	$t7
/*  f04d8f4:	24050400 */ 	addiu	$a1,$zero,0x400
/*  f04d8f8:	90f8035e */ 	lbu	$t8,0x35e($a3)
/*  f04d8fc:	00e02025 */ 	or	$a0,$a3,$zero
/*  f04d900:	01f8082b */ 	sltu	$at,$t7,$t8
/*  f04d904:	50200029 */ 	beqzl	$at,.L0f04d9ac
/*  f04d908:	8e070424 */ 	lw	$a3,0x424($s0)
/*  f04d90c:	0fc12790 */ 	jal	chrHasFlag
/*  f04d910:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f04d914:	14400024 */ 	bnez	$v0,.L0f04d9a8
/*  f04d918:	3c050001 */ 	lui	$a1,0x1
/*  f04d91c:	8e040424 */ 	lw	$a0,0x424($s0)
/*  f04d920:	0fc12790 */ 	jal	chrHasFlag
/*  f04d924:	00003025 */ 	or	$a2,$zero,$zero
/*  f04d928:	54400020 */ 	bnezl	$v0,.L0f04d9ac
/*  f04d92c:	8e070424 */ 	lw	$a3,0x424($s0)
/*  f04d930:	8e190424 */ 	lw	$t9,0x424($s0)
/*  f04d934:	0c006134 */ 	jal	ailistFindById
/*  f04d938:	87240356 */ 	lh	$a0,0x356($t9)
/*  f04d93c:	8e070424 */ 	lw	$a3,0x424($s0)
/*  f04d940:	8ce80108 */ 	lw	$t0,0x108($a3)
/*  f04d944:	50480019 */ 	beql	$v0,$t0,.L0f04d9ac
/*  f04d948:	8e070424 */ 	lw	$a3,0x424($s0)
/*  f04d94c:	80e20007 */ 	lb	$v0,0x7($a3)
/*  f04d950:	24010008 */ 	addiu	$at,$zero,0x8
/*  f04d954:	10410014 */ 	beq	$v0,$at,.L0f04d9a8
/*  f04d958:	24010009 */ 	addiu	$at,$zero,0x9
/*  f04d95c:	10410012 */ 	beq	$v0,$at,.L0f04d9a8
/*  f04d960:	24010004 */ 	addiu	$at,$zero,0x4
/*  f04d964:	10410010 */ 	beq	$v0,$at,.L0f04d9a8
/*  f04d968:	24010005 */ 	addiu	$at,$zero,0x5
/*  f04d96c:	1041000e */ 	beq	$v0,$at,.L0f04d9a8
/*  f04d970:	24010006 */ 	addiu	$at,$zero,0x6
/*  f04d974:	1041000c */ 	beq	$v0,$at,.L0f04d9a8
/*  f04d978:	24010007 */ 	addiu	$at,$zero,0x7
/*  f04d97c:	1041000a */ 	beq	$v0,$at,.L0f04d9a8
/*  f04d980:	2401000a */ 	addiu	$at,$zero,0xa
/*  f04d984:	50410009 */ 	beql	$v0,$at,.L0f04d9ac
/*  f04d988:	8e070424 */ 	lw	$a3,0x424($s0)
/*  f04d98c:	0c006134 */ 	jal	ailistFindById
/*  f04d990:	84e40356 */ 	lh	$a0,0x356($a3)
/*  f04d994:	8e090424 */ 	lw	$t1,0x424($s0)
/*  f04d998:	ae020434 */ 	sw	$v0,0x434($s0)
/*  f04d99c:	ae000438 */ 	sw	$zero,0x438($s0)
/*  f04d9a0:	1000000c */ 	beqz	$zero,.L0f04d9d4
/*  f04d9a4:	a120035e */ 	sb	$zero,0x35e($t1)
.L0f04d9a8:
/*  f04d9a8:	8e070424 */ 	lw	$a3,0x424($s0)
.L0f04d9ac:
/*  f04d9ac:	90ea035e */ 	lbu	$t2,0x35e($a3)
/*  f04d9b0:	000a5840 */ 	sll	$t3,$t2,0x1
/*  f04d9b4:	a0eb035e */ 	sb	$t3,0x35e($a3)
/*  f04d9b8:	8e070424 */ 	lw	$a3,0x424($s0)
/*  f04d9bc:	90e2035f */ 	lbu	$v0,0x35f($a3)
/*  f04d9c0:	90ec035e */ 	lbu	$t4,0x35e($a3)
/*  f04d9c4:	004c082a */ 	slt	$at,$v0,$t4
/*  f04d9c8:	10200002 */ 	beqz	$at,.L0f04d9d4
/*  f04d9cc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f04d9d0:	a0e2035e */ 	sb	$v0,0x35e($a3)
.L0f04d9d4:
/*  f04d9d4:	10000038 */ 	beqz	$zero,.L0f04dab8
/*  f04d9d8:	8e040434 */ 	lw	$a0,0x434($s0)
.L0f04d9dc:
/*  f04d9dc:	50e00036 */ 	beqzl	$a3,.L0f04dab8
/*  f04d9e0:	8e040434 */ 	lw	$a0,0x434($s0)
/*  f04d9e4:	8ced032c */ 	lw	$t5,0x32c($a3)
/*  f04d9e8:	00e02025 */ 	or	$a0,$a3,$zero
/*  f04d9ec:	24050400 */ 	addiu	$a1,$zero,0x400
/*  f04d9f0:	000d7b80 */ 	sll	$t7,$t5,0xe
/*  f04d9f4:	05e30030 */ 	bgezl	$t7,.L0f04dab8
/*  f04d9f8:	8e040434 */ 	lw	$a0,0x434($s0)
/*  f04d9fc:	0fc12790 */ 	jal	chrHasFlag
/*  f04da00:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f04da04:	5440002c */ 	bnezl	$v0,.L0f04dab8
/*  f04da08:	8e040434 */ 	lw	$a0,0x434($s0)
/*  f04da0c:	8e180424 */ 	lw	$t8,0x424($s0)
/*  f04da10:	0c006134 */ 	jal	ailistFindById
/*  f04da14:	8704035a */ 	lh	$a0,0x35a($t8)
/*  f04da18:	8e070424 */ 	lw	$a3,0x424($s0)
/*  f04da1c:	8cf90108 */ 	lw	$t9,0x108($a3)
/*  f04da20:	50590025 */ 	beql	$v0,$t9,.L0f04dab8
/*  f04da24:	8e040434 */ 	lw	$a0,0x434($s0)
/*  f04da28:	8e0804b4 */ 	lw	$t0,0x4b4($s0)
/*  f04da2c:	2401001c */ 	addiu	$at,$zero,0x1c
/*  f04da30:	51010021 */ 	beql	$t0,$at,.L0f04dab8
/*  f04da34:	8e040434 */ 	lw	$a0,0x434($s0)
/*  f04da38:	90e9032d */ 	lbu	$t1,0x32d($a3)
/*  f04da3c:	312afffd */ 	andi	$t2,$t1,0xfffd
/*  f04da40:	a0ea032d */ 	sb	$t2,0x32d($a3)
/*  f04da44:	8e070424 */ 	lw	$a3,0x424($s0)
/*  f04da48:	84eb035a */ 	lh	$t3,0x35a($a3)
/*  f04da4c:	05600017 */ 	bltz	$t3,.L0f04daac
/*  f04da50:	00000000 */ 	sll	$zero,$zero,0x0
/*  f04da54:	80e20007 */ 	lb	$v0,0x7($a3)
/*  f04da58:	24010004 */ 	addiu	$at,$zero,0x4
/*  f04da5c:	10410013 */ 	beq	$v0,$at,.L0f04daac
/*  f04da60:	24010005 */ 	addiu	$at,$zero,0x5
/*  f04da64:	10410011 */ 	beq	$v0,$at,.L0f04daac
/*  f04da68:	24010006 */ 	addiu	$at,$zero,0x6
/*  f04da6c:	1041000f */ 	beq	$v0,$at,.L0f04daac
/*  f04da70:	00e02025 */ 	or	$a0,$a3,$zero
/*  f04da74:	24050400 */ 	addiu	$a1,$zero,0x400
/*  f04da78:	0fc12776 */ 	jal	chrSetFlags
/*  f04da7c:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f04da80:	8e040424 */ 	lw	$a0,0x424($s0)
/*  f04da84:	3c051000 */ 	lui	$a1,0x1000
/*  f04da88:	0fc12776 */ 	jal	chrSetFlags
/*  f04da8c:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f04da90:	8e0c0424 */ 	lw	$t4,0x424($s0)
/*  f04da94:	a1800113 */ 	sb	$zero,0x113($t4)
/*  f04da98:	8e0d0424 */ 	lw	$t5,0x424($s0)
/*  f04da9c:	0c006134 */ 	jal	ailistFindById
/*  f04daa0:	85a4035a */ 	lh	$a0,0x35a($t5)
/*  f04daa4:	ae020434 */ 	sw	$v0,0x434($s0)
/*  f04daa8:	ae000438 */ 	sw	$zero,0x438($s0)
.L0f04daac:
/*  f04daac:	10000002 */ 	beqz	$zero,.L0f04dab8
/*  f04dab0:	8e040434 */ 	lw	$a0,0x434($s0)
/*  f04dab4:	8e040434 */ 	lw	$a0,0x434($s0)
.L0f04dab8:
/*  f04dab8:	5080001d */ 	beqzl	$a0,.L0f04db30
/*  f04dabc:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f04dac0:	8e050438 */ 	lw	$a1,0x438($s0)
.L0f04dac4:
/*  f04dac4:	00a41021 */ 	addu	$v0,$a1,$a0
/*  f04dac8:	904f0000 */ 	lbu	$t7,0x0($v0)
/*  f04dacc:	904e0001 */ 	lbu	$t6,0x1($v0)
/*  f04dad0:	000fc200 */ 	sll	$t8,$t7,0x8
/*  f04dad4:	01d81821 */ 	addu	$v1,$t6,$t8
/*  f04dad8:	0460000c */ 	bltz	$v1,.L0f04db0c
/*  f04dadc:	286101e1 */ 	slti	$at,$v1,0x1e1
/*  f04dae0:	1020000a */ 	beqz	$at,.L0f04db0c
/*  f04dae4:	0003c880 */ 	sll	$t9,$v1,0x2
/*  f04dae8:	3c018007 */ 	lui	$at,0x8007
/*  f04daec:	00390821 */ 	addu	$at,$at,$t9
/*  f04daf0:	8c398490 */ 	lw	$t9,-0x7b70($at)
/*  f04daf4:	0320f809 */ 	jalr	$t9
/*  f04daf8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f04dafc:	50400009 */ 	beqzl	$v0,.L0f04db24
/*  f04db00:	8e040434 */ 	lw	$a0,0x434($s0)
/*  f04db04:	1000000a */ 	beqz	$zero,.L0f04db30
/*  f04db08:	8fbf001c */ 	lw	$ra,0x1c($sp)
.L0f04db0c:
/*  f04db0c:	0fc136d0 */ 	jal	chraiGetCommandLength
/*  f04db10:	00000000 */ 	sll	$zero,$zero,0x0
/*  f04db14:	8e080438 */ 	lw	$t0,0x438($s0)
/*  f04db18:	01024821 */ 	addu	$t1,$t0,$v0
/*  f04db1c:	ae090438 */ 	sw	$t1,0x438($s0)
/*  f04db20:	8e040434 */ 	lw	$a0,0x434($s0)
.L0f04db24:
/*  f04db24:	5480ffe7 */ 	bnezl	$a0,.L0f04dac4
/*  f04db28:	8e050438 */ 	lw	$a1,0x438($s0)
/*  f04db2c:	8fbf001c */ 	lw	$ra,0x1c($sp)
.L0f04db30:
/*  f04db30:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f04db34:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*  f04db38:	03e00008 */ 	jr	$ra
/*  f04db3c:	00000000 */ 	sll	$zero,$zero,0x0
);

// Uses different temporary register near BITFIELD. Matches otherwise.
//void chraiExecute(void *entity, s32 entity_type)
//{
//	g_Vars.chrdata = NULL;
//	g_Vars.objdata = NULL;
//	g_Vars.aicdata = NULL;
//	g_Vars.hovdata = NULL;
//	g_Vars.ailist = NULL;
//	g_Vars.aioffset = 0;
//
//	if (entity_type == 3) {
//		g_Vars.chrdata = entity;
//	} else if (entity_type == 1) {
//		struct defaultobj *obj = entity;
//
//		if (obj->type == 0x27) {
//			g_Vars.objdata = entity;
//		} else if (obj->type == 0x28) {
//			g_Vars.aicdata = entity;
//		} else if (obj->type == OBJTYPE_HOVERVEHICLE || obj->type == OBJTYPE_ARMEDVEHICLE) {
//			g_Vars.hovdata = entity;
//		}
//	}
//
//	if (g_Vars.chrdata) {
//		g_Vars.ailist = g_Vars.chrdata->ailist;
//		g_Vars.aioffset = g_Vars.chrdata->aioffset;
//	} else if (g_Vars.objdata) {
//		g_Vars.ailist = g_Vars.objdata->ailist;
//		g_Vars.aioffset = g_Vars.objdata->aioffset;
//	} else if (g_Vars.aicdata) {
//		g_Vars.ailist = g_Vars.aicdata->ailist;
//		g_Vars.aioffset = g_Vars.aicdata->aioffset;
//	} else if (g_Vars.hovdata) {
//		g_Vars.ailist = g_Vars.hovdata->ailist;
//		g_Vars.aioffset = g_Vars.hovdata->aioffset;
//	}
//
//	if (g_Vars.ailist) {
//		if (g_Vars.chrdata) {
//			func0f04c444(g_Vars.chrdata);
//		}
//
//		// Check if the ailist should be switched to a different one
//		if (g_Vars.chrdata && (g_Vars.chrdata->chrflags & 0x00200000)) {
//			u32 animationmaybe = func0001d13c(g_Vars.chrdata->unk020);
//			if (g_Vars.chrdata->aishotlist >= 0
//					&& g_Vars.chrdata->cshield <= 0
//					&& (0 <= g_Vars.chrdata->damage || g_Vars.chrdata->gungroundpos != NULL)
//					&& animationmaybe != 0x269 && animationmaybe != 0x26b && animationmaybe != 0x26a) {
//				// Set shot list
//				g_Vars.chrdata->chrflags &= ~0x00200000;
//				g_Vars.ailist = ailistFindById(g_Vars.chrdata->aishotlist);
//				g_Vars.aioffset = 0;
//			}
//		} else if (g_Vars.chrdata && (g_Vars.chrdata->chrflags & 0x08000000)) {
//			g_Vars.chrdata->chrflags &= ~0x08000000;
//
//			if (g_Vars.chrdata->aishootingatmelist >= 0
//					&& ailistFindById(g_Vars.chrdata->aishootingatmelist) != g_Vars.chrdata->ailist
//					&& g_Vars.chrdata->dodgerating > (u32)random() % 100
//					&& chrHasFlag(g_Vars.chrdata, 0x00000400, BANK_1) == 0
//					&& chrHasFlag(g_Vars.chrdata, 0x00010000, BANK_0) == 0
//					&& ailistFindById(g_Vars.chrdata->aishootingatmelist) != g_Vars.chrdata->ailist
//					&& g_Vars.chrdata->actiontype != 8
//					&& g_Vars.chrdata->actiontype != 9
//					&& g_Vars.chrdata->actiontype != 4
//					&& g_Vars.chrdata->actiontype != 5
//					&& g_Vars.chrdata->actiontype != 6
//					&& g_Vars.chrdata->actiontype != 7
//					&& g_Vars.chrdata->actiontype != 10) {
//				// Set shooting at me list
//				g_Vars.ailist = ailistFindById(g_Vars.chrdata->aishootingatmelist);
//				g_Vars.aioffset = 0;
//				g_Vars.chrdata->dodgerating = 0;
//			} else {
//				// Increase dodge rating
//				g_Vars.chrdata->dodgerating *= 2;
//
//				if (g_Vars.chrdata->dodgerating > g_Vars.chrdata->maxdodgerating) {
//					g_Vars.chrdata->dodgerating = g_Vars.chrdata->maxdodgerating & 0xff;
//				}
//			}
//		} else if (g_Vars.chrdata
//				&& g_Vars.chrdata->BITFIELD.word & 0x00020000
//				&& chrHasFlag(g_Vars.chrdata, 0x00000400, BANK_1) == 0
//				&& ailistFindById(g_Vars.chrdata->aidarkroomlist) != g_Vars.chrdata->ailist
//				&& g_Vars.unk0004b4 != 0x1c) {
//			g_Vars.chrdata->BITFIELD.bytes[1] &= ~0x02;
//
//			if (g_Vars.chrdata->aidarkroomlist >= 0
//					&& g_Vars.chrdata->actiontype != 4
//					&& g_Vars.chrdata->actiontype != 5
//					&& g_Vars.chrdata->actiontype != 6) {
//				// Set darkroom list
//				chrSetFlags(g_Vars.chrdata, 0x00000400, BANK_1);
//				chrSetFlags(g_Vars.chrdata, 0x10000000, BANK_1);
//				g_Vars.chrdata->alertness = 0;
//				g_Vars.ailist = ailistFindById(g_Vars.chrdata->aidarkroomlist);
//				g_Vars.aioffset = 0;
//			}
//		} else {
//			// empty
//		}
//
//		// Iterate and execute the ailist
//		while (g_Vars.ailist) {
//			u8 *cmd = g_Vars.aioffset + g_Vars.ailist;
//			s32 type = (cmd[0] << 8) + cmd[1];
//
//			if (type >= 0 && type <= 0x1e0) {
//				if (g_CommandPointers[type]()) {
//					break;
//				}
//			} else {
//				// This is attempting to handle situations where the command
//				// type is invalid by passing over them and continuing
//				// execution. This would very likely result in a crash though.
//				g_Vars.aioffset += chraiGetCommandLength(g_Vars.ailist, g_Vars.aioffset);
//			}
//		}
//	}
//}

u32 chraiGetCommandLength(u8 *ailist, u32 aioffset)
{
	u8 *cmd = aioffset + ailist;
	s32 type = (cmd[0] << 8) + cmd[1];

	if (type == CMD_PRINT) {
		u32 pos = aioffset + 2;

		while (ailist[pos] != 0) {
			++pos;
		}

		return (pos - aioffset) + 1;
	}

	if (type >= 0 && type < 0x1e1) {
		return g_CommandLengths[type];
	}

	return 1;
}
