#include <ultra64.h>
#include "constants.h"
#include "gvars/gvars.h"
#include "lib/lib_074f0.h"
#include "lib/lib_2fa00.h"
#include "data.h"
#include "types.h"

const u32 var70052530[] = {0x00000001};
const u32 var70052534[] = {0x00030007};
const u32 var70052538[] = {0x000f001f};
const u32 var7005253c[] = {0x003f007f};
const u32 var70052540[] = {0x00ff01ff};
const u32 var70052544[] = {0x03ff07ff};
const u32 var70052548[] = {0x0fff1fff};
const u32 var7005254c[] = {0x3fff7fff};
const u32 var70052550[] = {0xffff0003};
const u32 var70052554[] = {0x00040005};
const u32 var70052558[] = {0x00060007};
const u32 var7005255c[] = {0x00080009};
const u32 var70052560[] = {0x000a000b};
const u32 var70052564[] = {0x000d000f};
const u32 var70052568[] = {0x00110013};
const u32 var7005256c[] = {0x0017001b};
const u32 var70052570[] = {0x001f0023};
const u32 var70052574[] = {0x002b0033};
const u32 var70052578[] = {0x003b0043};
const u32 var7005257c[] = {0x00530063};
const u32 var70052580[] = {0x00730083};
const u32 var70052584[] = {0x00a300c3};
const u32 var70052588[] = {0x00e30102};
const u32 var7005258c[] = {0x00000000};
const u32 var70052590[] = {0x00010002};
const u32 var70052594[] = {0x00030004};
const u32 var70052598[] = {0x00050007};
const u32 var7005259c[] = {0x0009000d};
const u32 var700525a0[] = {0x00110019};
const u32 var700525a4[] = {0x00210031};
const u32 var700525a8[] = {0x00410061};
const u32 var700525ac[] = {0x008100c1};
const u32 var700525b0[] = {0x01010181};
const u32 var700525b4[] = {0x02010301};
const u32 var700525b8[] = {0x04010601};
const u32 var700525bc[] = {0x08010c01};
const u32 var700525c0[] = {0x10011801};
const u32 var700525c4[] = {0x20013001};
const u32 var700525c8[] = {0x40016001};
const u32 var700525cc[] = {0x10111200};
const u32 var700525d0[] = {0x08070906};
const u32 var700525d4[] = {0x0a050b04};
const u32 var700525d8[] = {0x0c030d02};
const u32 var700525dc[] = {0x0e010f00};
const u32 var700525e0[] = {0x00000000};
const u32 var700525e4[] = {0x00000001};
const u32 var700525e8[] = {0x01010102};
const u32 var700525ec[] = {0x02020203};
const u32 var700525f0[] = {0x03030304};
const u32 var700525f4[] = {0x04040405};
const u32 var700525f8[] = {0x05050500};
const u32 var700525fc[] = {0x63630000};
const u32 var70052600[] = {0x00000101};
const u32 var70052604[] = {0x02020303};
const u32 var70052608[] = {0x04040505};
const u32 var7005260c[] = {0x06060707};
const u32 var70052610[] = {0x08080909};
const u32 var70052614[] = {0x0a0a0b0b};
const u32 var70052618[] = {0x0c0c0d0d};

const char var7005261c[] =
	"RareZipAsmDecompress: inflate failed (%d)\n\0"
	"RareZipAsmDecompress: hufts overflow=%d\n\0"
	"RareZipAsmDecompress: bad len\n\0"
	"RareZipAsmDecompress: input not in any known rare zip format\n";

GLOBAL_ASM(
glabel rzipInflate
/*     74f0:	27bdf578 */ 	addiu	$sp,$sp,-2696
/*     74f4:	afb00a48 */ 	sw	$s0,0xa48($sp)
/*     74f8:	afb10a4c */ 	sw	$s1,0xa4c($sp)
/*     74fc:	afb20a50 */ 	sw	$s2,0xa50($sp)
/*     7500:	afb30a54 */ 	sw	$s3,0xa54($sp)
/*     7504:	afb40a58 */ 	sw	$s4,0xa58($sp)
/*     7508:	afb50a5c */ 	sw	$s5,0xa5c($sp)
/*     750c:	afb60a60 */ 	sw	$s6,0xa60($sp)
/*     7510:	afb70a64 */ 	sw	$s7,0xa64($sp)
/*     7514:	afbe0a78 */ 	sw	$s8,0xa78($sp)
/*     7518:	afbc0a7c */ 	sw	$gp,0xa7c($sp)
/*     751c:	afbf0a80 */ 	sw	$ra,0xa80($sp)
/*     7520:	24080011 */ 	addiu	$t0,$zero,0x11
/*     7524:	90890000 */ 	lbu	$t1,0x0($a0)
/*     7528:	11280044 */ 	beq	$t1,$t0,.L0000763c
/*     752c:	24080072 */ 	addiu	$t0,$zero,0x72
/*     7530:	27bdff80 */ 	addiu	$sp,$sp,-128
/*     7534:	afa40010 */ 	sw	$a0,0x10($sp)
/*     7538:	3c047005 */ 	lui	$a0,%hi(var7005261c+0x73)
/*     753c:	afbf0000 */ 	sw	$ra,0x0($sp)
/*     7540:	afa10004 */ 	sw	$at,0x4($sp)
/*     7544:	afa20008 */ 	sw	$v0,0x8($sp)
/*     7548:	afa3000c */ 	sw	$v1,0xc($sp)
/*     754c:	afa50014 */ 	sw	$a1,0x14($sp)
/*     7550:	afa60018 */ 	sw	$a2,0x18($sp)
/*     7554:	afa7001c */ 	sw	$a3,0x1c($sp)
/*     7558:	afa80020 */ 	sw	$t0,0x20($sp)
/*     755c:	afa90024 */ 	sw	$t1,0x24($sp)
/*     7560:	afaa0028 */ 	sw	$t2,0x28($sp)
/*     7564:	afab002c */ 	sw	$t3,0x2c($sp)
/*     7568:	afac0030 */ 	sw	$t4,0x30($sp)
/*     756c:	afad0034 */ 	sw	$t5,0x34($sp)
/*     7570:	afae0038 */ 	sw	$t6,0x38($sp)
/*     7574:	afaf003c */ 	sw	$t7,0x3c($sp)
/*     7578:	afb00040 */ 	sw	$s0,0x40($sp)
/*     757c:	afb10044 */ 	sw	$s1,0x44($sp)
/*     7580:	afb20048 */ 	sw	$s2,0x48($sp)
/*     7584:	afb3004c */ 	sw	$s3,0x4c($sp)
/*     7588:	afb40050 */ 	sw	$s4,0x50($sp)
/*     758c:	afb50054 */ 	sw	$s5,0x54($sp)
/*     7590:	afb60058 */ 	sw	$s6,0x58($sp)
/*     7594:	afb7005c */ 	sw	$s7,0x5c($sp)
/*     7598:	afb80060 */ 	sw	$t8,0x60($sp)
/*     759c:	afb90064 */ 	sw	$t9,0x64($sp)
/*     75a0:	afbc0070 */ 	sw	$gp,0x70($sp)
/*     75a4:	afbd0074 */ 	sw	$sp,0x74($sp)
/*     75a8:	afbe0078 */ 	sw	$s8,0x78($sp)
/*     75ac:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*     75b0:	0c00bea9 */ 	jal	rmonPrint
/*     75b4:	2484268f */ 	addiu	$a0,$a0,%lo(var7005261c+0x73)
/*     75b8:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*     75bc:	8fbf0000 */ 	lw	$ra,0x0($sp)
/*     75c0:	8fa10004 */ 	lw	$at,0x4($sp)
/*     75c4:	8fa20008 */ 	lw	$v0,0x8($sp)
/*     75c8:	8fa3000c */ 	lw	$v1,0xc($sp)
/*     75cc:	8fa40010 */ 	lw	$a0,0x10($sp)
/*     75d0:	8fa50014 */ 	lw	$a1,0x14($sp)
/*     75d4:	8fa60018 */ 	lw	$a2,0x18($sp)
/*     75d8:	8fa7001c */ 	lw	$a3,0x1c($sp)
/*     75dc:	8fa80020 */ 	lw	$t0,0x20($sp)
/*     75e0:	8fa90024 */ 	lw	$t1,0x24($sp)
/*     75e4:	8faa0028 */ 	lw	$t2,0x28($sp)
/*     75e8:	8fab002c */ 	lw	$t3,0x2c($sp)
/*     75ec:	8fac0030 */ 	lw	$t4,0x30($sp)
/*     75f0:	8fad0034 */ 	lw	$t5,0x34($sp)
/*     75f4:	8fae0038 */ 	lw	$t6,0x38($sp)
/*     75f8:	8faf003c */ 	lw	$t7,0x3c($sp)
/*     75fc:	8fb00040 */ 	lw	$s0,0x40($sp)
/*     7600:	8fb10044 */ 	lw	$s1,0x44($sp)
/*     7604:	8fb20048 */ 	lw	$s2,0x48($sp)
/*     7608:	8fb3004c */ 	lw	$s3,0x4c($sp)
/*     760c:	8fb40050 */ 	lw	$s4,0x50($sp)
/*     7610:	8fb50054 */ 	lw	$s5,0x54($sp)
/*     7614:	8fb60058 */ 	lw	$s6,0x58($sp)
/*     7618:	8fb7005c */ 	lw	$s7,0x5c($sp)
/*     761c:	8fb80060 */ 	lw	$t8,0x60($sp)
/*     7620:	8fb90064 */ 	lw	$t9,0x64($sp)
/*     7624:	8fbc0070 */ 	lw	$gp,0x70($sp)
/*     7628:	8fbd0074 */ 	lw	$sp,0x74($sp)
/*     762c:	8fbe0078 */ 	lw	$s8,0x78($sp)
/*     7630:	27bd0080 */ 	addiu	$sp,$sp,0x80
/*     7634:	08001dfd */ 	j	.L000077f4
/*     7638:	00000000 */ 	nop
.L0000763c:
/*     763c:	90890001 */ 	lbu	$t1,0x1($a0)
/*     7640:	11280046 */ 	beq	$t1,$t0,.L0000775c
/*     7644:	24080073 */ 	addiu	$t0,$zero,0x73
/*     7648:	11280046 */ 	beq	$t1,$t0,.L00007764
/*     764c:	00000000 */ 	nop
/*     7650:	27bdff80 */ 	addiu	$sp,$sp,-128
/*     7654:	afa40010 */ 	sw	$a0,0x10($sp)
/*     7658:	3c047005 */ 	lui	$a0,%hi(var7005261c+0x73)
/*     765c:	afbf0000 */ 	sw	$ra,0x0($sp)
/*     7660:	afa10004 */ 	sw	$at,0x4($sp)
/*     7664:	afa20008 */ 	sw	$v0,0x8($sp)
/*     7668:	afa3000c */ 	sw	$v1,0xc($sp)
/*     766c:	afa50014 */ 	sw	$a1,0x14($sp)
/*     7670:	afa60018 */ 	sw	$a2,0x18($sp)
/*     7674:	afa7001c */ 	sw	$a3,0x1c($sp)
/*     7678:	afa80020 */ 	sw	$t0,0x20($sp)
/*     767c:	afa90024 */ 	sw	$t1,0x24($sp)
/*     7680:	afaa0028 */ 	sw	$t2,0x28($sp)
/*     7684:	afab002c */ 	sw	$t3,0x2c($sp)
/*     7688:	afac0030 */ 	sw	$t4,0x30($sp)
/*     768c:	afad0034 */ 	sw	$t5,0x34($sp)
/*     7690:	afae0038 */ 	sw	$t6,0x38($sp)
/*     7694:	afaf003c */ 	sw	$t7,0x3c($sp)
/*     7698:	afb00040 */ 	sw	$s0,0x40($sp)
/*     769c:	afb10044 */ 	sw	$s1,0x44($sp)
/*     76a0:	afb20048 */ 	sw	$s2,0x48($sp)
/*     76a4:	afb3004c */ 	sw	$s3,0x4c($sp)
/*     76a8:	afb40050 */ 	sw	$s4,0x50($sp)
/*     76ac:	afb50054 */ 	sw	$s5,0x54($sp)
/*     76b0:	afb60058 */ 	sw	$s6,0x58($sp)
/*     76b4:	afb7005c */ 	sw	$s7,0x5c($sp)
/*     76b8:	afb80060 */ 	sw	$t8,0x60($sp)
/*     76bc:	afb90064 */ 	sw	$t9,0x64($sp)
/*     76c0:	afbc0070 */ 	sw	$gp,0x70($sp)
/*     76c4:	afbd0074 */ 	sw	$sp,0x74($sp)
/*     76c8:	afbe0078 */ 	sw	$s8,0x78($sp)
/*     76cc:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*     76d0:	0c00bea9 */ 	jal	rmonPrint
/*     76d4:	2484268f */ 	addiu	$a0,$a0,%lo(var7005261c+0x73)
/*     76d8:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*     76dc:	8fbf0000 */ 	lw	$ra,0x0($sp)
/*     76e0:	8fa10004 */ 	lw	$at,0x4($sp)
/*     76e4:	8fa20008 */ 	lw	$v0,0x8($sp)
/*     76e8:	8fa3000c */ 	lw	$v1,0xc($sp)
/*     76ec:	8fa40010 */ 	lw	$a0,0x10($sp)
/*     76f0:	8fa50014 */ 	lw	$a1,0x14($sp)
/*     76f4:	8fa60018 */ 	lw	$a2,0x18($sp)
/*     76f8:	8fa7001c */ 	lw	$a3,0x1c($sp)
/*     76fc:	8fa80020 */ 	lw	$t0,0x20($sp)
/*     7700:	8fa90024 */ 	lw	$t1,0x24($sp)
/*     7704:	8faa0028 */ 	lw	$t2,0x28($sp)
/*     7708:	8fab002c */ 	lw	$t3,0x2c($sp)
/*     770c:	8fac0030 */ 	lw	$t4,0x30($sp)
/*     7710:	8fad0034 */ 	lw	$t5,0x34($sp)
/*     7714:	8fae0038 */ 	lw	$t6,0x38($sp)
/*     7718:	8faf003c */ 	lw	$t7,0x3c($sp)
/*     771c:	8fb00040 */ 	lw	$s0,0x40($sp)
/*     7720:	8fb10044 */ 	lw	$s1,0x44($sp)
/*     7724:	8fb20048 */ 	lw	$s2,0x48($sp)
/*     7728:	8fb3004c */ 	lw	$s3,0x4c($sp)
/*     772c:	8fb40050 */ 	lw	$s4,0x50($sp)
/*     7730:	8fb50054 */ 	lw	$s5,0x54($sp)
/*     7734:	8fb60058 */ 	lw	$s6,0x58($sp)
/*     7738:	8fb7005c */ 	lw	$s7,0x5c($sp)
/*     773c:	8fb80060 */ 	lw	$t8,0x60($sp)
/*     7740:	8fb90064 */ 	lw	$t9,0x64($sp)
/*     7744:	8fbc0070 */ 	lw	$gp,0x70($sp)
/*     7748:	8fbd0074 */ 	lw	$sp,0x74($sp)
/*     774c:	8fbe0078 */ 	lw	$s8,0x78($sp)
/*     7750:	27bd0080 */ 	addiu	$sp,$sp,0x80
/*     7754:	08001dfd */ 	j	.L000077f4
/*     7758:	00000000 */ 	nop
.L0000775c:
/*     775c:	08001ddb */ 	j	.L0000776c
/*     7760:	24840002 */ 	addiu	$a0,$a0,0x2
.L00007764:
/*     7764:	08001ddb */ 	j	.L0000776c
/*     7768:	24840005 */ 	addiu	$a0,$a0,0x5
.L0000776c:
/*     776c:	24970000 */ 	addiu	$s7,$a0,0x0
/*     7770:	44858000 */ 	mtc1	$a1,$f16
/*     7774:	00c0b025 */ 	or	$s6,$a2,$zero
/*     7778:	44808800 */ 	mtc1	$zero,$f17
/*     777c:	3c0a7000 */ 	lui	$t2,0x7000
/*     7780:	00854023 */ 	subu	$t0,$a0,$a1
/*     7784:	5d000002 */ 	bgtzl	$t0,.L00007790
/*     7788:	00000000 */ 	nop
/*     778c:	01005025 */ 	or	$t2,$t0,$zero
.L00007790:
/*     7790:	00c54023 */ 	subu	$t0,$a2,$a1
/*     7794:	05000005 */ 	bltz	$t0,.L000077ac
/*     7798:	00000000 */ 	nop
/*     779c:	010a082a */ 	slt	$at,$t0,$t2
/*     77a0:	10200002 */ 	beqz	$at,.L000077ac
/*     77a4:	00000000 */ 	nop
/*     77a8:	01005025 */ 	or	$t2,$t0,$zero
.L000077ac:
/*     77ac:	448a9000 */ 	mtc1	$t2,$f18
/*     77b0:	0c001e42 */ 	jal	func00007908
/*     77b4:	00000000 */ 	nop
/*     77b8:	1440000e */ 	bnez	$v0,.L000077f4
/*     77bc:	44028800 */ 	mfc1	$v0,$f17
.L000077c0:
/*     77c0:	8fb00a48 */ 	lw	$s0,0xa48($sp)
/*     77c4:	8fb10a4c */ 	lw	$s1,0xa4c($sp)
/*     77c8:	8fb20a50 */ 	lw	$s2,0xa50($sp)
/*     77cc:	8fb30a54 */ 	lw	$s3,0xa54($sp)
/*     77d0:	8fb40a58 */ 	lw	$s4,0xa58($sp)
/*     77d4:	8fb50a5c */ 	lw	$s5,0xa5c($sp)
/*     77d8:	8fb60a60 */ 	lw	$s6,0xa60($sp)
/*     77dc:	8fb70a64 */ 	lw	$s7,0xa64($sp)
/*     77e0:	8fbe0a78 */ 	lw	$s8,0xa78($sp)
/*     77e4:	8fbc0a7c */ 	lw	$gp,0xa7c($sp)
/*     77e8:	8fbf0a80 */ 	lw	$ra,0xa80($sp)
/*     77ec:	03e00008 */ 	jr	$ra
/*     77f0:	27bd0a88 */ 	addiu	$sp,$sp,0xa88
.L000077f4:
/*     77f4:	27bdff80 */ 	addiu	$sp,$sp,-128
/*     77f8:	afbf0000 */ 	sw	$ra,0x0($sp)
/*     77fc:	afa10004 */ 	sw	$at,0x4($sp)
/*     7800:	afa20008 */ 	sw	$v0,0x8($sp)
/*     7804:	afa3000c */ 	sw	$v1,0xc($sp)
/*     7808:	afa40010 */ 	sw	$a0,0x10($sp)
/*     780c:	afa50014 */ 	sw	$a1,0x14($sp)
/*     7810:	afa60018 */ 	sw	$a2,0x18($sp)
/*     7814:	afa7001c */ 	sw	$a3,0x1c($sp)
/*     7818:	afa80020 */ 	sw	$t0,0x20($sp)
/*     781c:	afa90024 */ 	sw	$t1,0x24($sp)
/*     7820:	afaa0028 */ 	sw	$t2,0x28($sp)
/*     7824:	afab002c */ 	sw	$t3,0x2c($sp)
/*     7828:	afac0030 */ 	sw	$t4,0x30($sp)
/*     782c:	afad0034 */ 	sw	$t5,0x34($sp)
/*     7830:	afae0038 */ 	sw	$t6,0x38($sp)
/*     7834:	afaf003c */ 	sw	$t7,0x3c($sp)
/*     7838:	afb00040 */ 	sw	$s0,0x40($sp)
/*     783c:	afb10044 */ 	sw	$s1,0x44($sp)
/*     7840:	afb20048 */ 	sw	$s2,0x48($sp)
/*     7844:	afb3004c */ 	sw	$s3,0x4c($sp)
/*     7848:	afb40050 */ 	sw	$s4,0x50($sp)
/*     784c:	afb50054 */ 	sw	$s5,0x54($sp)
/*     7850:	afb60058 */ 	sw	$s6,0x58($sp)
/*     7854:	afb7005c */ 	sw	$s7,0x5c($sp)
/*     7858:	afb80060 */ 	sw	$t8,0x60($sp)
/*     785c:	afb90064 */ 	sw	$t9,0x64($sp)
/*     7860:	afbc0070 */ 	sw	$gp,0x70($sp)
/*     7864:	afbd0074 */ 	sw	$sp,0x74($sp)
/*     7868:	afbe0078 */ 	sw	$s8,0x78($sp)
/*     786c:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*     7870:	afa20004 */ 	sw	$v0,0x4($sp)
/*     7874:	3c047005 */ 	lui	$a0,%hi(var7005261c)
/*     7878:	2484261c */ 	addiu	$a0,$a0,%lo(var7005261c)
/*     787c:	0c00bea9 */ 	jal	rmonPrint
/*     7880:	8fa50004 */ 	lw	$a1,0x4($sp)
/*     7884:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*     7888:	8fbf0000 */ 	lw	$ra,0x0($sp)
/*     788c:	8fa10004 */ 	lw	$at,0x4($sp)
/*     7890:	8fa20008 */ 	lw	$v0,0x8($sp)
/*     7894:	8fa3000c */ 	lw	$v1,0xc($sp)
/*     7898:	8fa40010 */ 	lw	$a0,0x10($sp)
/*     789c:	8fa50014 */ 	lw	$a1,0x14($sp)
/*     78a0:	8fa60018 */ 	lw	$a2,0x18($sp)
/*     78a4:	8fa7001c */ 	lw	$a3,0x1c($sp)
/*     78a8:	8fa80020 */ 	lw	$t0,0x20($sp)
/*     78ac:	8fa90024 */ 	lw	$t1,0x24($sp)
/*     78b0:	8faa0028 */ 	lw	$t2,0x28($sp)
/*     78b4:	8fab002c */ 	lw	$t3,0x2c($sp)
/*     78b8:	8fac0030 */ 	lw	$t4,0x30($sp)
/*     78bc:	8fad0034 */ 	lw	$t5,0x34($sp)
/*     78c0:	8fae0038 */ 	lw	$t6,0x38($sp)
/*     78c4:	8faf003c */ 	lw	$t7,0x3c($sp)
/*     78c8:	8fb00040 */ 	lw	$s0,0x40($sp)
/*     78cc:	8fb10044 */ 	lw	$s1,0x44($sp)
/*     78d0:	8fb20048 */ 	lw	$s2,0x48($sp)
/*     78d4:	8fb3004c */ 	lw	$s3,0x4c($sp)
/*     78d8:	8fb40050 */ 	lw	$s4,0x50($sp)
/*     78dc:	8fb50054 */ 	lw	$s5,0x54($sp)
/*     78e0:	8fb60058 */ 	lw	$s6,0x58($sp)
/*     78e4:	8fb7005c */ 	lw	$s7,0x5c($sp)
/*     78e8:	8fb80060 */ 	lw	$t8,0x60($sp)
/*     78ec:	8fb90064 */ 	lw	$t9,0x64($sp)
/*     78f0:	8fbc0070 */ 	lw	$gp,0x70($sp)
/*     78f4:	8fbd0074 */ 	lw	$sp,0x74($sp)
/*     78f8:	8fbe0078 */ 	lw	$s8,0x78($sp)
/*     78fc:	27bd0080 */ 	addiu	$sp,$sp,0x80
/*     7900:	08001df0 */ 	j	.L000077c0
/*     7904:	24020000 */ 	addiu	$v0,$zero,0x0
);

GLOBAL_ASM(
glabel func00007908
/*     7908:	afbf0a6c */ 	sw	$ra,0xa6c($sp)
/*     790c:	44808800 */ 	mtc1	$zero,$f17
/*     7910:	241c0000 */ 	addiu	$gp,$zero,0x0
/*     7914:	241e0000 */ 	addiu	$s8,$zero,0x0
.L00007918:
/*     7918:	44809800 */ 	mtc1	$zero,$f19
/*     791c:	0c001e5b */ 	jal	func0000796c
/*     7920:	27a40a70 */ 	addiu	$a0,$sp,0xa70
/*     7924:	1440000e */ 	bnez	$v0,.L00007960
/*     7928:	8fab0a70 */ 	lw	$t3,0xa70($sp)
/*     792c:	1160fffa */ 	beqz	$t3,.L00007918
/*     7930:	00000000 */ 	nop
/*     7934:	2bc10008 */ 	slti	$at,$s8,0x8
/*     7938:	14200005 */ 	bnez	$at,.L00007950
/*     793c:	00000000 */ 	nop
.L00007940:
/*     7940:	27defff8 */ 	addiu	$s8,$s8,-8
/*     7944:	2bc10008 */ 	slti	$at,$s8,0x8
/*     7948:	1020fffd */ 	beqz	$at,.L00007940
/*     794c:	26f7ffff */ 	addiu	$s7,$s7,-1
.L00007950:
/*     7950:	24020000 */ 	addiu	$v0,$zero,0x0
/*     7954:	3c0b8009 */ 	lui	$t3,%hi(var80091558)
/*     7958:	256b1558 */ 	addiu	$t3,$t3,%lo(var80091558)
/*     795c:	ad770000 */ 	sw	$s7,0x0($t3)
.L00007960:
/*     7960:	8fbf0a6c */ 	lw	$ra,0xa6c($sp)
/*     7964:	03e00008 */ 	jr	$ra
/*     7968:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel func0000796c
/*     796c:	afbf0a68 */ 	sw	$ra,0xa68($sp)
/*     7970:	2bc10003 */ 	slti	$at,$s8,0x3
/*     7974:	10200009 */ 	beqz	$at,.L0000799c
/*     7978:	00000000 */ 	nop
/*     797c:	92e10000 */ 	lbu	$at,0x0($s7)
.L00007980:
/*     7980:	26f70001 */ 	addiu	$s7,$s7,0x1
/*     7984:	03c10804 */ 	sllv	$at,$at,$s8
/*     7988:	0381e025 */ 	or	$gp,$gp,$at
/*     798c:	27de0008 */ 	addiu	$s8,$s8,0x8
/*     7990:	2bc10003 */ 	slti	$at,$s8,0x3
/*     7994:	5420fffa */ 	bnezl	$at,.L00007980
/*     7998:	92e10000 */ 	lbu	$at,0x0($s7)
.L0000799c:
/*     799c:	33810001 */ 	andi	$at,$gp,0x1
/*     79a0:	ac810000 */ 	sw	$at,0x0($a0)
/*     79a4:	001c5842 */ 	srl	$t3,$gp,0x1
/*     79a8:	316b0003 */ 	andi	$t3,$t3,0x3
/*     79ac:	001ce0c2 */ 	srl	$gp,$gp,0x3
/*     79b0:	27defffd */ 	addiu	$s8,$s8,-3
/*     79b4:	24010002 */ 	addiu	$at,$zero,0x2
/*     79b8:	15610005 */ 	bne	$t3,$at,.L000079d0
/*     79bc:	00000000 */ 	nop
/*     79c0:	0c001e84 */ 	jal	func00007a10
/*     79c4:	00000000 */ 	nop
/*     79c8:	08001e81 */ 	j	.L00007a04
/*     79cc:	00000000 */ 	nop
.L000079d0:
/*     79d0:	15600005 */ 	bnez	$t3,.L000079e8
/*     79d4:	24010001 */ 	addiu	$at,$zero,0x1
/*     79d8:	0c001fc8 */ 	jal	func00007f20
/*     79dc:	00000000 */ 	nop
/*     79e0:	08001e81 */ 	j	.L00007a04
/*     79e4:	00000000 */ 	nop
.L000079e8:
/*     79e8:	15610005 */ 	bne	$t3,$at,.L00007a00
/*     79ec:	00000000 */ 	nop
/*     79f0:	0c002009 */ 	jal	func00008024
/*     79f4:	00000000 */ 	nop
/*     79f8:	08001e81 */ 	j	.L00007a04
/*     79fc:	00000000 */ 	nop
.L00007a00:
/*     7a00:	24020002 */ 	addiu	$v0,$zero,0x2
.L00007a04:
/*     7a04:	8fbf0a68 */ 	lw	$ra,0xa68($sp)
/*     7a08:	03e00008 */ 	jr	$ra
/*     7a0c:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel func00007a10
/*     7a10:	afbf0a44 */ 	sw	$ra,0xa44($sp)
/*     7a14:	3c0d7005 */ 	lui	$t5,%hi(var700525cc)
/*     7a18:	25ad25cc */ 	addiu	$t5,$t5,%lo(var700525cc)
/*     7a1c:	2bc1000e */ 	slti	$at,$s8,0xe
/*     7a20:	10200009 */ 	beqz	$at,.L00007a48
/*     7a24:	00000000 */ 	nop
/*     7a28:	92e10000 */ 	lbu	$at,0x0($s7)
.L00007a2c:
/*     7a2c:	26f70001 */ 	addiu	$s7,$s7,0x1
/*     7a30:	03c10804 */ 	sllv	$at,$at,$s8
/*     7a34:	0381e025 */ 	or	$gp,$gp,$at
/*     7a38:	27de0008 */ 	addiu	$s8,$s8,0x8
/*     7a3c:	2bc1000e */ 	slti	$at,$s8,0xe
/*     7a40:	5420fffa */ 	bnezl	$at,.L00007a2c
/*     7a44:	92e10000 */ 	lbu	$at,0x0($s7)
.L00007a48:
/*     7a48:	338a001f */ 	andi	$t2,$gp,0x1f
/*     7a4c:	254a0101 */ 	addiu	$t2,$t2,0x101
/*     7a50:	338b03e0 */ 	andi	$t3,$gp,0x3e0
/*     7a54:	000b5942 */ 	srl	$t3,$t3,0x5
/*     7a58:	256b0001 */ 	addiu	$t3,$t3,0x1
/*     7a5c:	33893c00 */ 	andi	$t1,$gp,0x3c00
/*     7a60:	00094a82 */ 	srl	$t1,$t1,0xa
/*     7a64:	25290004 */ 	addiu	$t1,$t1,0x4
/*     7a68:	001ce382 */ 	srl	$gp,$gp,0xe
/*     7a6c:	27defff2 */ 	addiu	$s8,$s8,-14
/*     7a70:	2941011f */ 	slti	$at,$t2,0x11f
/*     7a74:	102000e5 */ 	beqz	$at,.L00007e0c
/*     7a78:	00000000 */ 	nop
/*     7a7c:	2961001f */ 	slti	$at,$t3,0x1f
/*     7a80:	102000e2 */ 	beqz	$at,.L00007e0c
/*     7a84:	24110000 */ 	addiu	$s1,$zero,0x0
.L00007a88:
/*     7a88:	2bc10003 */ 	slti	$at,$s8,0x3
/*     7a8c:	10200009 */ 	beqz	$at,.L00007ab4
/*     7a90:	00000000 */ 	nop
/*     7a94:	92e10000 */ 	lbu	$at,0x0($s7)
.L00007a98:
/*     7a98:	26f70001 */ 	addiu	$s7,$s7,0x1
/*     7a9c:	03c10804 */ 	sllv	$at,$at,$s8
/*     7aa0:	0381e025 */ 	or	$gp,$gp,$at
/*     7aa4:	27de0008 */ 	addiu	$s8,$s8,0x8
/*     7aa8:	2bc10003 */ 	slti	$at,$s8,0x3
/*     7aac:	5420fffa */ 	bnezl	$at,.L00007a98
/*     7ab0:	92e10000 */ 	lbu	$at,0x0($s7)
.L00007ab4:
/*     7ab4:	01b1c021 */ 	addu	$t8,$t5,$s1
/*     7ab8:	93180000 */ 	lbu	$t8,0x0($t8)
/*     7abc:	0018c080 */ 	sll	$t8,$t8,0x2
/*     7ac0:	031dc021 */ 	addu	$t8,$t8,$sp
/*     7ac4:	33810007 */ 	andi	$at,$gp,0x7
/*     7ac8:	af010548 */ 	sw	$at,0x548($t8)
/*     7acc:	001ce0c2 */ 	srl	$gp,$gp,0x3
/*     7ad0:	27defffd */ 	addiu	$s8,$s8,-3
/*     7ad4:	26310001 */ 	addiu	$s1,$s1,0x1
/*     7ad8:	0229082a */ 	slt	$at,$s1,$t1
/*     7adc:	1420ffea */ 	bnez	$at,.L00007a88
/*     7ae0:	00000000 */ 	nop
/*     7ae4:	2a210013 */ 	slti	$at,$s1,0x13
/*     7ae8:	10200008 */ 	beqz	$at,.L00007b0c
.L00007aec:
/*     7aec:	01b1c021 */ 	addu	$t8,$t5,$s1
/*     7af0:	93180000 */ 	lbu	$t8,0x0($t8)
/*     7af4:	26310001 */ 	addiu	$s1,$s1,0x1
/*     7af8:	0018c080 */ 	sll	$t8,$t8,0x2
/*     7afc:	031dc021 */ 	addu	$t8,$t8,$sp
/*     7b00:	af000548 */ 	sw	$zero,0x548($t8)
/*     7b04:	2a210013 */ 	slti	$at,$s1,0x13
/*     7b08:	1420fff8 */ 	bnez	$at,.L00007aec
.L00007b0c:
/*     7b0c:	24180007 */ 	addiu	$t8,$zero,0x7
/*     7b10:	afb80a3c */ 	sw	$t8,0xa3c($sp)
/*     7b14:	448a0000 */ 	mtc1	$t2,$f0
/*     7b18:	448b0800 */ 	mtc1	$t3,$f1
/*     7b1c:	27a40548 */ 	addiu	$a0,$sp,0x548
/*     7b20:	24050013 */ 	addiu	$a1,$zero,0x13
/*     7b24:	24060013 */ 	addiu	$a2,$zero,0x13
/*     7b28:	24070000 */ 	addiu	$a3,$zero,0x0
/*     7b2c:	240f0000 */ 	addiu	$t7,$zero,0x0
/*     7b30:	27b80a38 */ 	addiu	$t8,$sp,0xa38
/*     7b34:	0c002019 */ 	jal	func00008064
/*     7b38:	27b90a3c */ 	addiu	$t9,$sp,0xa3c
/*     7b3c:	440a0000 */ 	mfc1	$t2,$f0
/*     7b40:	440b0800 */ 	mfc1	$t3,$f1
/*     7b44:	3c0e7005 */ 	lui	$t6,%hi(var70052530)
/*     7b48:	25ce2530 */ 	addiu	$t6,$t6,%lo(var70052530)
/*     7b4c:	97b50a38 */ 	lhu	$s5,0xa38($sp)
/*     7b50:	8fa80a3c */ 	lw	$t0,0xa3c($sp)
/*     7b54:	014ba021 */ 	addu	$s4,$t2,$t3
/*     7b58:	00089840 */ 	sll	$s3,$t0,0x1
/*     7b5c:	026e9821 */ 	addu	$s3,$s3,$t6
/*     7b60:	24190000 */ 	addiu	$t9,$zero,0x0
/*     7b64:	24120000 */ 	addiu	$s2,$zero,0x0
/*     7b68:	0334082a */ 	slt	$at,$t9,$s4
/*     7b6c:	10200078 */ 	beqz	$at,.L00007d50
/*     7b70:	96730000 */ 	lhu	$s3,0x0($s3)
.L00007b74:
/*     7b74:	03c8082a */ 	slt	$at,$s8,$t0
/*     7b78:	10200009 */ 	beqz	$at,.L00007ba0
/*     7b7c:	00000000 */ 	nop
/*     7b80:	92e10000 */ 	lbu	$at,0x0($s7)
.L00007b84:
/*     7b84:	26f70001 */ 	addiu	$s7,$s7,0x1
/*     7b88:	03c10804 */ 	sllv	$at,$at,$s8
/*     7b8c:	0381e025 */ 	or	$gp,$gp,$at
/*     7b90:	27de0008 */ 	addiu	$s8,$s8,0x8
/*     7b94:	03c8082a */ 	slt	$at,$s8,$t0
/*     7b98:	5420fffa */ 	bnezl	$at,.L00007b84
/*     7b9c:	92e10000 */ 	lbu	$at,0x0($s7)
.L00007ba0:
/*     7ba0:	03938024 */ 	and	$s0,$gp,$s3
/*     7ba4:	02158021 */ 	addu	$s0,$s0,$s5
/*     7ba8:	00108880 */ 	sll	$s1,$s0,0x2
/*     7bac:	02368821 */ 	addu	$s1,$s1,$s6
/*     7bb0:	92310001 */ 	lbu	$s1,0x1($s1)
/*     7bb4:	023ce006 */ 	srlv	$gp,$gp,$s1
/*     7bb8:	03d1f023 */ 	subu	$s8,$s8,$s1
/*     7bbc:	00108880 */ 	sll	$s1,$s0,0x2
/*     7bc0:	02368821 */ 	addu	$s1,$s1,$s6
/*     7bc4:	96310002 */ 	lhu	$s1,0x2($s1)
/*     7bc8:	2a210010 */ 	slti	$at,$s1,0x10
/*     7bcc:	10200007 */ 	beqz	$at,.L00007bec
/*     7bd0:	00000000 */ 	nop
/*     7bd4:	00199080 */ 	sll	$s2,$t9,0x2
/*     7bd8:	025d9021 */ 	addu	$s2,$s2,$sp
/*     7bdc:	ae510548 */ 	sw	$s1,0x548($s2)
/*     7be0:	27390001 */ 	addiu	$t9,$t9,0x1
/*     7be4:	08001f51 */ 	j	.L00007d44
/*     7be8:	02209025 */ 	or	$s2,$s1,$zero
.L00007bec:
/*     7bec:	24010010 */ 	addiu	$at,$zero,0x10
/*     7bf0:	1621001c */ 	bne	$s1,$at,.L00007c64
/*     7bf4:	00000000 */ 	nop
/*     7bf8:	2bc10002 */ 	slti	$at,$s8,0x2
/*     7bfc:	10200009 */ 	beqz	$at,.L00007c24
/*     7c00:	00000000 */ 	nop
/*     7c04:	92e10000 */ 	lbu	$at,0x0($s7)
.L00007c08:
/*     7c08:	26f70001 */ 	addiu	$s7,$s7,0x1
/*     7c0c:	03c10804 */ 	sllv	$at,$at,$s8
/*     7c10:	0381e025 */ 	or	$gp,$gp,$at
/*     7c14:	27de0008 */ 	addiu	$s8,$s8,0x8
/*     7c18:	2bc10002 */ 	slti	$at,$s8,0x2
/*     7c1c:	5420fffa */ 	bnezl	$at,.L00007c08
/*     7c20:	92e10000 */ 	lbu	$at,0x0($s7)
.L00007c24:
/*     7c24:	33910003 */ 	andi	$s1,$gp,0x3
/*     7c28:	26310003 */ 	addiu	$s1,$s1,0x3
/*     7c2c:	001ce082 */ 	srl	$gp,$gp,0x2
/*     7c30:	27defffe */ 	addiu	$s8,$s8,-2
/*     7c34:	0331c021 */ 	addu	$t8,$t9,$s1
/*     7c38:	0298082a */ 	slt	$at,$s4,$t8
/*     7c3c:	142000b4 */ 	bnez	$at,.L00007f10
/*     7c40:	0019c080 */ 	sll	$t8,$t9,0x2
/*     7c44:	031dc021 */ 	addu	$t8,$t8,$sp
.L00007c48:
/*     7c48:	af120548 */ 	sw	$s2,0x548($t8)
/*     7c4c:	27390001 */ 	addiu	$t9,$t9,0x1
/*     7c50:	2631ffff */ 	addiu	$s1,$s1,-1
/*     7c54:	1620fffc */ 	bnez	$s1,.L00007c48
/*     7c58:	27180004 */ 	addiu	$t8,$t8,0x4
/*     7c5c:	08001f51 */ 	j	.L00007d44
/*     7c60:	00000000 */ 	nop
.L00007c64:
/*     7c64:	24010011 */ 	addiu	$at,$zero,0x11
/*     7c68:	1621001c */ 	bne	$s1,$at,.L00007cdc
/*     7c6c:	00000000 */ 	nop
/*     7c70:	2bc10003 */ 	slti	$at,$s8,0x3
/*     7c74:	10200009 */ 	beqz	$at,.L00007c9c
/*     7c78:	00000000 */ 	nop
/*     7c7c:	92e10000 */ 	lbu	$at,0x0($s7)
.L00007c80:
/*     7c80:	26f70001 */ 	addiu	$s7,$s7,0x1
/*     7c84:	03c10804 */ 	sllv	$at,$at,$s8
/*     7c88:	0381e025 */ 	or	$gp,$gp,$at
/*     7c8c:	27de0008 */ 	addiu	$s8,$s8,0x8
/*     7c90:	2bc10003 */ 	slti	$at,$s8,0x3
/*     7c94:	5420fffa */ 	bnezl	$at,.L00007c80
/*     7c98:	92e10000 */ 	lbu	$at,0x0($s7)
.L00007c9c:
/*     7c9c:	33910007 */ 	andi	$s1,$gp,0x7
/*     7ca0:	26310003 */ 	addiu	$s1,$s1,0x3
/*     7ca4:	001ce0c2 */ 	srl	$gp,$gp,0x3
/*     7ca8:	27defffd */ 	addiu	$s8,$s8,-3
/*     7cac:	0331c021 */ 	addu	$t8,$t9,$s1
/*     7cb0:	0298082a */ 	slt	$at,$s4,$t8
/*     7cb4:	14200096 */ 	bnez	$at,.L00007f10
/*     7cb8:	0019c080 */ 	sll	$t8,$t9,0x2
/*     7cbc:	031dc021 */ 	addu	$t8,$t8,$sp
.L00007cc0:
/*     7cc0:	af000548 */ 	sw	$zero,0x548($t8)
/*     7cc4:	27390001 */ 	addiu	$t9,$t9,0x1
/*     7cc8:	2631ffff */ 	addiu	$s1,$s1,-1
/*     7ccc:	1620fffc */ 	bnez	$s1,.L00007cc0
/*     7cd0:	27180004 */ 	addiu	$t8,$t8,0x4
/*     7cd4:	08001f51 */ 	j	.L00007d44
/*     7cd8:	24120000 */ 	addiu	$s2,$zero,0x0
.L00007cdc:
/*     7cdc:	2bc10007 */ 	slti	$at,$s8,0x7
/*     7ce0:	10200009 */ 	beqz	$at,.L00007d08
/*     7ce4:	00000000 */ 	nop
/*     7ce8:	92e10000 */ 	lbu	$at,0x0($s7)
.L00007cec:
/*     7cec:	26f70001 */ 	addiu	$s7,$s7,0x1
/*     7cf0:	03c10804 */ 	sllv	$at,$at,$s8
/*     7cf4:	0381e025 */ 	or	$gp,$gp,$at
/*     7cf8:	27de0008 */ 	addiu	$s8,$s8,0x8
/*     7cfc:	2bc10007 */ 	slti	$at,$s8,0x7
/*     7d00:	5420fffa */ 	bnezl	$at,.L00007cec
/*     7d04:	92e10000 */ 	lbu	$at,0x0($s7)
.L00007d08:
/*     7d08:	3391007f */ 	andi	$s1,$gp,0x7f
/*     7d0c:	2631000b */ 	addiu	$s1,$s1,0xb
/*     7d10:	001ce1c2 */ 	srl	$gp,$gp,0x7
/*     7d14:	27defff9 */ 	addiu	$s8,$s8,-7
/*     7d18:	0331c021 */ 	addu	$t8,$t9,$s1
/*     7d1c:	0298082a */ 	slt	$at,$s4,$t8
/*     7d20:	1420007b */ 	bnez	$at,.L00007f10
/*     7d24:	0019c080 */ 	sll	$t8,$t9,0x2
/*     7d28:	031dc021 */ 	addu	$t8,$t8,$sp
.L00007d2c:
/*     7d2c:	af000548 */ 	sw	$zero,0x548($t8)
/*     7d30:	27390001 */ 	addiu	$t9,$t9,0x1
/*     7d34:	2631ffff */ 	addiu	$s1,$s1,-1
/*     7d38:	1620fffc */ 	bnez	$s1,.L00007d2c
/*     7d3c:	27180004 */ 	addiu	$t8,$t8,0x4
/*     7d40:	24120000 */ 	addiu	$s2,$zero,0x0
.L00007d44:
/*     7d44:	0334082a */ 	slt	$at,$t9,$s4
/*     7d48:	1420ff8a */ 	bnez	$at,.L00007b74
/*     7d4c:	00000000 */ 	nop
.L00007d50:
/*     7d50:	a7b50a38 */ 	sh	$s5,0xa38($sp)
/*     7d54:	a7b00a3a */ 	sh	$s0,0xa3a($sp)
/*     7d58:	24180009 */ 	addiu	$t8,$zero,0x9
/*     7d5c:	afb80a3c */ 	sw	$t8,0xa3c($sp)
/*     7d60:	448a0000 */ 	mtc1	$t2,$f0
/*     7d64:	448b0800 */ 	mtc1	$t3,$f1
/*     7d68:	27a40548 */ 	addiu	$a0,$sp,0x548
/*     7d6c:	01402825 */ 	or	$a1,$t2,$zero
/*     7d70:	24060101 */ 	addiu	$a2,$zero,0x101
/*     7d74:	3c077005 */ 	lui	$a3,%hi(var70052550+0x2)
/*     7d78:	24e72552 */ 	addiu	$a3,$a3,%lo(var70052550+0x2)
/*     7d7c:	3c0f7005 */ 	lui	$t7,%hi(var700525dc+0x3)
/*     7d80:	25ef25df */ 	addiu	$t7,$t7,%lo(var700525dc+0x3)
/*     7d84:	27b80a38 */ 	addiu	$t8,$sp,0xa38
/*     7d88:	0c002019 */ 	jal	func00008064
/*     7d8c:	27b90a3c */ 	addiu	$t9,$sp,0xa3c
/*     7d90:	440a0000 */ 	mfc1	$t2,$f0
/*     7d94:	440b0800 */ 	mfc1	$t3,$f1
/*     7d98:	1440005d */ 	bnez	$v0,.L00007f10
/*     7d9c:	24180006 */ 	addiu	$t8,$zero,0x6
/*     7da0:	afb80a40 */ 	sw	$t8,0xa40($sp)
/*     7da4:	000a2080 */ 	sll	$a0,$t2,0x2
/*     7da8:	009d2021 */ 	addu	$a0,$a0,$sp
/*     7dac:	24840548 */ 	addiu	$a0,$a0,0x548
/*     7db0:	01602825 */ 	or	$a1,$t3,$zero
/*     7db4:	24060000 */ 	addiu	$a2,$zero,0x0
/*     7db8:	3c077005 */ 	lui	$a3,%hi(var70052590)
/*     7dbc:	24e72590 */ 	addiu	$a3,$a3,%lo(var70052590)
/*     7dc0:	3c0f7005 */ 	lui	$t7,%hi(var700525fc+0x2)
/*     7dc4:	25ef25fe */ 	addiu	$t7,$t7,%lo(var700525fc+0x2)
/*     7dc8:	27b80a3a */ 	addiu	$t8,$sp,0xa3a
/*     7dcc:	0c002019 */ 	jal	func00008064
/*     7dd0:	27b90a40 */ 	addiu	$t9,$sp,0xa40
/*     7dd4:	1440004e */ 	bnez	$v0,.L00007f10
/*     7dd8:	97a40a38 */ 	lhu	$a0,0xa38($sp)
/*     7ddc:	00042080 */ 	sll	$a0,$a0,0x2
/*     7de0:	00962021 */ 	addu	$a0,$a0,$s6
/*     7de4:	97a50a3a */ 	lhu	$a1,0xa3a($sp)
/*     7de8:	00052880 */ 	sll	$a1,$a1,0x2
/*     7dec:	00b62821 */ 	addu	$a1,$a1,$s6
/*     7df0:	8fa60a3c */ 	lw	$a2,0xa3c($sp)
/*     7df4:	0c002184 */ 	jal	func00008610
/*     7df8:	8fa70a40 */ 	lw	$a3,0xa40($sp)
/*     7dfc:	14400044 */ 	bnez	$v0,.L00007f10
/*     7e00:	00000000 */ 	nop
/*     7e04:	08001fc5 */ 	j	.L00007f14
/*     7e08:	24020000 */ 	addiu	$v0,$zero,0x0
.L00007e0c:
/*     7e0c:	27bdff80 */ 	addiu	$sp,$sp,-128
/*     7e10:	afa40010 */ 	sw	$a0,0x10($sp)
/*     7e14:	3c047005 */ 	lui	$a0,%hi(var7005261c+0x54)
/*     7e18:	afbf0000 */ 	sw	$ra,0x0($sp)
/*     7e1c:	afa10004 */ 	sw	$at,0x4($sp)
/*     7e20:	afa20008 */ 	sw	$v0,0x8($sp)
/*     7e24:	afa3000c */ 	sw	$v1,0xc($sp)
/*     7e28:	afa50014 */ 	sw	$a1,0x14($sp)
/*     7e2c:	afa60018 */ 	sw	$a2,0x18($sp)
/*     7e30:	afa7001c */ 	sw	$a3,0x1c($sp)
/*     7e34:	afa80020 */ 	sw	$t0,0x20($sp)
/*     7e38:	afa90024 */ 	sw	$t1,0x24($sp)
/*     7e3c:	afaa0028 */ 	sw	$t2,0x28($sp)
/*     7e40:	afab002c */ 	sw	$t3,0x2c($sp)
/*     7e44:	afac0030 */ 	sw	$t4,0x30($sp)
/*     7e48:	afad0034 */ 	sw	$t5,0x34($sp)
/*     7e4c:	afae0038 */ 	sw	$t6,0x38($sp)
/*     7e50:	afaf003c */ 	sw	$t7,0x3c($sp)
/*     7e54:	afb00040 */ 	sw	$s0,0x40($sp)
/*     7e58:	afb10044 */ 	sw	$s1,0x44($sp)
/*     7e5c:	afb20048 */ 	sw	$s2,0x48($sp)
/*     7e60:	afb3004c */ 	sw	$s3,0x4c($sp)
/*     7e64:	afb40050 */ 	sw	$s4,0x50($sp)
/*     7e68:	afb50054 */ 	sw	$s5,0x54($sp)
/*     7e6c:	afb60058 */ 	sw	$s6,0x58($sp)
/*     7e70:	afb7005c */ 	sw	$s7,0x5c($sp)
/*     7e74:	afb80060 */ 	sw	$t8,0x60($sp)
/*     7e78:	afb90064 */ 	sw	$t9,0x64($sp)
/*     7e7c:	afbc0070 */ 	sw	$gp,0x70($sp)
/*     7e80:	afbd0074 */ 	sw	$sp,0x74($sp)
/*     7e84:	afbe0078 */ 	sw	$s8,0x78($sp)
/*     7e88:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*     7e8c:	0c00bea9 */ 	jal	rmonPrint
/*     7e90:	24842670 */ 	addiu	$a0,$a0,%lo(var7005261c+0x54)
/*     7e94:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*     7e98:	8fbf0000 */ 	lw	$ra,0x0($sp)
/*     7e9c:	8fa10004 */ 	lw	$at,0x4($sp)
/*     7ea0:	8fa20008 */ 	lw	$v0,0x8($sp)
/*     7ea4:	8fa3000c */ 	lw	$v1,0xc($sp)
/*     7ea8:	8fa40010 */ 	lw	$a0,0x10($sp)
/*     7eac:	8fa50014 */ 	lw	$a1,0x14($sp)
/*     7eb0:	8fa60018 */ 	lw	$a2,0x18($sp)
/*     7eb4:	8fa7001c */ 	lw	$a3,0x1c($sp)
/*     7eb8:	8fa80020 */ 	lw	$t0,0x20($sp)
/*     7ebc:	8fa90024 */ 	lw	$t1,0x24($sp)
/*     7ec0:	8faa0028 */ 	lw	$t2,0x28($sp)
/*     7ec4:	8fab002c */ 	lw	$t3,0x2c($sp)
/*     7ec8:	8fac0030 */ 	lw	$t4,0x30($sp)
/*     7ecc:	8fad0034 */ 	lw	$t5,0x34($sp)
/*     7ed0:	8fae0038 */ 	lw	$t6,0x38($sp)
/*     7ed4:	8faf003c */ 	lw	$t7,0x3c($sp)
/*     7ed8:	8fb00040 */ 	lw	$s0,0x40($sp)
/*     7edc:	8fb10044 */ 	lw	$s1,0x44($sp)
/*     7ee0:	8fb20048 */ 	lw	$s2,0x48($sp)
/*     7ee4:	8fb3004c */ 	lw	$s3,0x4c($sp)
/*     7ee8:	8fb40050 */ 	lw	$s4,0x50($sp)
/*     7eec:	8fb50054 */ 	lw	$s5,0x54($sp)
/*     7ef0:	8fb60058 */ 	lw	$s6,0x58($sp)
/*     7ef4:	8fb7005c */ 	lw	$s7,0x5c($sp)
/*     7ef8:	8fb80060 */ 	lw	$t8,0x60($sp)
/*     7efc:	8fb90064 */ 	lw	$t9,0x64($sp)
/*     7f00:	8fbc0070 */ 	lw	$gp,0x70($sp)
/*     7f04:	8fbd0074 */ 	lw	$sp,0x74($sp)
/*     7f08:	8fbe0078 */ 	lw	$s8,0x78($sp)
/*     7f0c:	27bd0080 */ 	addiu	$sp,$sp,0x80
.L00007f10:
/*     7f10:	24020001 */ 	addiu	$v0,$zero,0x1
.L00007f14:
/*     7f14:	8fbf0a44 */ 	lw	$ra,0xa44($sp)
/*     7f18:	03e00008 */ 	jr	$ra
/*     7f1c:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel func00007f20
/*     7f20:	440a8800 */ 	mfc1	$t2,$f17
/*     7f24:	440e9000 */ 	mfc1	$t6,$f18
/*     7f28:	440f8000 */ 	mfc1	$t7,$f16
/*     7f2c:	33cb0007 */ 	andi	$t3,$s8,0x7
/*     7f30:	017ce006 */ 	srlv	$gp,$gp,$t3
/*     7f34:	03cbf023 */ 	subu	$s8,$s8,$t3
/*     7f38:	2bc10010 */ 	slti	$at,$s8,0x10
/*     7f3c:	10200009 */ 	beqz	$at,.L00007f64
/*     7f40:	00000000 */ 	nop
/*     7f44:	92e10000 */ 	lbu	$at,0x0($s7)
.L00007f48:
/*     7f48:	26f70001 */ 	addiu	$s7,$s7,0x1
/*     7f4c:	03c10804 */ 	sllv	$at,$at,$s8
/*     7f50:	0381e025 */ 	or	$gp,$gp,$at
/*     7f54:	27de0008 */ 	addiu	$s8,$s8,0x8
/*     7f58:	2bc10010 */ 	slti	$at,$s8,0x10
/*     7f5c:	5420fffa */ 	bnezl	$at,.L00007f48
/*     7f60:	92e10000 */ 	lbu	$at,0x0($s7)
.L00007f64:
/*     7f64:	338bffff */ 	andi	$t3,$gp,0xffff
/*     7f68:	001ce402 */ 	srl	$gp,$gp,0x10
/*     7f6c:	27defff0 */ 	addiu	$s8,$s8,-16
/*     7f70:	2bc10010 */ 	slti	$at,$s8,0x10
/*     7f74:	10200009 */ 	beqz	$at,.L00007f9c
/*     7f78:	00000000 */ 	nop
/*     7f7c:	92e10000 */ 	lbu	$at,0x0($s7)
.L00007f80:
/*     7f80:	26f70001 */ 	addiu	$s7,$s7,0x1
/*     7f84:	03c10804 */ 	sllv	$at,$at,$s8
/*     7f88:	0381e025 */ 	or	$gp,$gp,$at
/*     7f8c:	27de0008 */ 	addiu	$s8,$s8,0x8
/*     7f90:	2bc10010 */ 	slti	$at,$s8,0x10
/*     7f94:	5420fffa */ 	bnezl	$at,.L00007f80
/*     7f98:	92e10000 */ 	lbu	$at,0x0($s7)
.L00007f9c:
/*     7f9c:	03806827 */ 	nor	$t5,$gp,$zero
/*     7fa0:	31adffff */ 	andi	$t5,$t5,0xffff
/*     7fa4:	156d001d */ 	bne	$t3,$t5,.L0000801c
/*     7fa8:	001ce402 */ 	srl	$gp,$gp,0x10
/*     7fac:	27defff0 */ 	addiu	$s8,$s8,-16
/*     7fb0:	014b6821 */ 	addu	$t5,$t2,$t3
/*     7fb4:	01ae082a */ 	slt	$at,$t5,$t6
/*     7fb8:	10200018 */ 	beqz	$at,.L0000801c
/*     7fbc:	01ea6821 */ 	addu	$t5,$t7,$t2
/*     7fc0:	014b5021 */ 	addu	$t2,$t2,$t3
/*     7fc4:	11600012 */ 	beqz	$t3,.L00008010
/*     7fc8:	256bffff */ 	addiu	$t3,$t3,-1
.L00007fcc:
/*     7fcc:	2bc10008 */ 	slti	$at,$s8,0x8
/*     7fd0:	10200009 */ 	beqz	$at,.L00007ff8
/*     7fd4:	00000000 */ 	nop
/*     7fd8:	92e10000 */ 	lbu	$at,0x0($s7)
.L00007fdc:
/*     7fdc:	26f70001 */ 	addiu	$s7,$s7,0x1
/*     7fe0:	03c10804 */ 	sllv	$at,$at,$s8
/*     7fe4:	0381e025 */ 	or	$gp,$gp,$at
/*     7fe8:	27de0008 */ 	addiu	$s8,$s8,0x8
/*     7fec:	2bc10008 */ 	slti	$at,$s8,0x8
/*     7ff0:	5420fffa */ 	bnezl	$at,.L00007fdc
/*     7ff4:	92e10000 */ 	lbu	$at,0x0($s7)
.L00007ff8:
/*     7ff8:	a1bc0000 */ 	sb	$gp,0x0($t5)
/*     7ffc:	25ad0001 */ 	addiu	$t5,$t5,0x1
/*     8000:	001ce202 */ 	srl	$gp,$gp,0x8
/*     8004:	27defff8 */ 	addiu	$s8,$s8,-8
/*     8008:	1560fff0 */ 	bnez	$t3,.L00007fcc
/*     800c:	256bffff */ 	addiu	$t3,$t3,-1
.L00008010:
/*     8010:	448a8800 */ 	mtc1	$t2,$f17
/*     8014:	03e00008 */ 	jr	$ra
/*     8018:	24020000 */ 	addiu	$v0,$zero,0x0
.L0000801c:
/*     801c:	03e00008 */ 	jr	$ra
/*     8020:	24020001 */ 	addiu	$v0,$zero,0x1
);

GLOBAL_ASM(
glabel func00008024
/*     8024:	afbf0a44 */ 	sw	$ra,0xa44($sp)
/*     8028:	afb60a74 */ 	sw	$s6,0xa74($sp)
/*     802c:	3c168009 */ 	lui	$s6,%hi(var80090b10)
/*     8030:	26d60b10 */ 	addiu	$s6,$s6,%lo(var80090b10)
/*     8034:	3c048009 */ 	lui	$a0,%hi(var80090b14)
/*     8038:	24840b14 */ 	addiu	$a0,$a0,%lo(var80090b14)
/*     803c:	3c058009 */ 	lui	$a1,%hi(var800914d8)
/*     8040:	24a514d8 */ 	addiu	$a1,$a1,%lo(var800914d8)
/*     8044:	24060007 */ 	addiu	$a2,$zero,0x7
/*     8048:	24070005 */ 	addiu	$a3,$zero,0x5
/*     804c:	0c002184 */ 	jal	func00008610
/*     8050:	00000000 */ 	nop
/*     8054:	8fb60a74 */ 	lw	$s6,0xa74($sp)
/*     8058:	8fbf0a44 */ 	lw	$ra,0xa44($sp)
/*     805c:	03e00008 */ 	jr	$ra
/*     8060:	24020000 */ 	addiu	$v0,$zero,0x0
);

GLOBAL_ASM(
glabel func00008064
/*     8064:	10a00120 */ 	beqz	$a1,.L000084e8
/*     8068:	44901000 */ 	mtc1	$s0,$f2
/*     806c:	44911800 */ 	mtc1	$s1,$f3
/*     8070:	44922000 */ 	mtc1	$s2,$f4
/*     8074:	44932800 */ 	mtc1	$s3,$f5
/*     8078:	44943000 */ 	mtc1	$s4,$f6
/*     807c:	44953800 */ 	mtc1	$s5,$f7
/*     8080:	44964000 */ 	mtc1	$s6,$f8
/*     8084:	44974800 */ 	mtc1	$s7,$f9
/*     8088:	449e5000 */ 	mtc1	$s8,$f10
/*     808c:	449c5800 */ 	mtc1	$gp,$f11
/*     8090:	44139800 */ 	mfc1	$s3,$f19
/*     8094:	ffa00000 */ 	sd	$zero,0x0($sp)
/*     8098:	ffa00008 */ 	sd	$zero,0x8($sp)
/*     809c:	ffa00010 */ 	sd	$zero,0x10($sp)
/*     80a0:	ffa00018 */ 	sd	$zero,0x18($sp)
/*     80a4:	ffa00020 */ 	sd	$zero,0x20($sp)
/*     80a8:	ffa00028 */ 	sd	$zero,0x28($sp)
/*     80ac:	ffa00030 */ 	sd	$zero,0x30($sp)
/*     80b0:	ffa00038 */ 	sd	$zero,0x38($sp)
/*     80b4:	afa00040 */ 	sw	$zero,0x40($sp)
/*     80b8:	00804025 */ 	or	$t0,$a0,$zero
/*     80bc:	00a04825 */ 	or	$t1,$a1,$zero
.L000080c0:
/*     80c0:	8d170000 */ 	lw	$s7,0x0($t0)
/*     80c4:	25080004 */ 	addiu	$t0,$t0,0x4
/*     80c8:	0017b880 */ 	sll	$s7,$s7,0x2
/*     80cc:	02fdb821 */ 	addu	$s7,$s7,$sp
/*     80d0:	8ee10000 */ 	lw	$at,0x0($s7)
/*     80d4:	2529ffff */ 	addiu	$t1,$t1,-1
/*     80d8:	24210001 */ 	addiu	$at,$at,0x1
/*     80dc:	1520fff8 */ 	bnez	$t1,.L000080c0
/*     80e0:	aee10000 */ 	sw	$at,0x0($s7)
/*     80e4:	8fb70000 */ 	lw	$s7,0x0($sp)
/*     80e8:	12e50101 */ 	beq	$s7,$a1,.L000084f0
/*     80ec:	8f2a0000 */ 	lw	$t2,0x0($t9)
/*     80f0:	240b0004 */ 	addiu	$t3,$zero,0x4
/*     80f4:	000a5080 */ 	sll	$t2,$t2,0x2
/*     80f8:	24010040 */ 	addiu	$at,$zero,0x40
.L000080fc:
/*     80fc:	017db821 */ 	addu	$s7,$t3,$sp
/*     8100:	8ef70000 */ 	lw	$s7,0x0($s7)
/*     8104:	16e00003 */ 	bnez	$s7,.L00008114
/*     8108:	00000000 */ 	nop
/*     810c:	1561fffb */ 	bne	$t3,$at,.L000080fc
/*     8110:	256b0004 */ 	addiu	$t3,$t3,0x4
.L00008114:
/*     8114:	014b082a */ 	slt	$at,$t2,$t3
/*     8118:	10200002 */ 	beqz	$at,.L00008124
/*     811c:	01606025 */ 	or	$t4,$t3,$zero
/*     8120:	01605025 */ 	or	$t2,$t3,$zero
.L00008124:
/*     8124:	24090040 */ 	addiu	$t1,$zero,0x40
.L00008128:
/*     8128:	013db821 */ 	addu	$s7,$t1,$sp
/*     812c:	8ef70000 */ 	lw	$s7,0x0($s7)
/*     8130:	16e00004 */ 	bnez	$s7,.L00008144
/*     8134:	00000000 */ 	nop
/*     8138:	2529fffc */ 	addiu	$t1,$t1,-4
/*     813c:	1520fffa */ 	bnez	$t1,.L00008128
/*     8140:	00000000 */ 	nop
.L00008144:
/*     8144:	012a082a */ 	slt	$at,$t1,$t2
/*     8148:	10200002 */ 	beqz	$at,.L00008154
/*     814c:	01206825 */ 	or	$t5,$t1,$zero
/*     8150:	01205025 */ 	or	$t2,$t1,$zero
.L00008154:
/*     8154:	000a5082 */ 	srl	$t2,$t2,0x2
/*     8158:	af2a0000 */ 	sw	$t2,0x0($t9)
/*     815c:	24190001 */ 	addiu	$t9,$zero,0x1
/*     8160:	000bb882 */ 	srl	$s7,$t3,0x2
/*     8164:	0169082a */ 	slt	$at,$t3,$t1
/*     8168:	10200008 */ 	beqz	$at,.L0000818c
/*     816c:	02f9c804 */ 	sllv	$t9,$t9,$s7
.L00008170:
/*     8170:	017db821 */ 	addu	$s7,$t3,$sp
/*     8174:	8ef70000 */ 	lw	$s7,0x0($s7)
/*     8178:	256b0004 */ 	addiu	$t3,$t3,0x4
/*     817c:	0337c823 */ 	subu	$t9,$t9,$s7
/*     8180:	0169082a */ 	slt	$at,$t3,$t1
/*     8184:	1420fffa */ 	bnez	$at,.L00008170
/*     8188:	0019c840 */ 	sll	$t9,$t9,0x1
.L0000818c:
/*     818c:	013db821 */ 	addu	$s7,$t1,$sp
/*     8190:	8ee10000 */ 	lw	$at,0x0($s7)
/*     8194:	aef90000 */ 	sw	$t9,0x0($s7)
/*     8198:	0321c823 */ 	subu	$t9,$t9,$at
/*     819c:	afa00508 */ 	sw	$zero,0x508($sp)
/*     81a0:	240b0000 */ 	addiu	$t3,$zero,0x0
/*     81a4:	27a80004 */ 	addiu	$t0,$sp,0x4
/*     81a8:	2529fffc */ 	addiu	$t1,$t1,-4
/*     81ac:	11200008 */ 	beqz	$t1,.L000081d0
/*     81b0:	27ae050c */ 	addiu	$t6,$sp,0x50c
.L000081b4:
/*     81b4:	8d170000 */ 	lw	$s7,0x0($t0)
/*     81b8:	25080004 */ 	addiu	$t0,$t0,0x4
/*     81bc:	01775821 */ 	addu	$t3,$t3,$s7
/*     81c0:	adcb0000 */ 	sw	$t3,0x0($t6)
/*     81c4:	2529fffc */ 	addiu	$t1,$t1,-4
/*     81c8:	1520fffa */ 	bnez	$t1,.L000081b4
/*     81cc:	25ce0004 */ 	addiu	$t6,$t6,0x4
.L000081d0:
/*     81d0:	000d6882 */ 	srl	$t5,$t5,0x2
/*     81d4:	000c6082 */ 	srl	$t4,$t4,0x2
/*     81d8:	00804025 */ 	or	$t0,$a0,$zero
/*     81dc:	24090000 */ 	addiu	$t1,$zero,0x0
/*     81e0:	8d0b0000 */ 	lw	$t3,0x0($t0)
.L000081e4:
/*     81e4:	25080004 */ 	addiu	$t0,$t0,0x4
/*     81e8:	11600008 */ 	beqz	$t3,.L0000820c
/*     81ec:	000b5880 */ 	sll	$t3,$t3,0x2
/*     81f0:	017d5821 */ 	addu	$t3,$t3,$sp
/*     81f4:	8d770504 */ 	lw	$s7,0x504($t3)
/*     81f8:	0017f080 */ 	sll	$s8,$s7,0x2
/*     81fc:	26e10001 */ 	addiu	$at,$s7,0x1
/*     8200:	ad610504 */ 	sw	$at,0x504($t3)
/*     8204:	03ddf021 */ 	addu	$s8,$s8,$sp
/*     8208:	afc90084 */ 	sw	$t1,0x84($s8)
.L0000820c:
/*     820c:	25290001 */ 	addiu	$t1,$t1,0x1
/*     8210:	0125082a */ 	slt	$at,$t1,$a1
/*     8214:	5420fff3 */ 	bnezl	$at,.L000081e4
/*     8218:	8d0b0000 */ 	lw	$t3,0x0($t0)
/*     821c:	afa00504 */ 	sw	$zero,0x504($sp)
/*     8220:	24090000 */ 	addiu	$t1,$zero,0x0
/*     8224:	27a80084 */ 	addiu	$t0,$sp,0x84
/*     8228:	2402ffff */ 	addiu	$v0,$zero,-1
/*     822c:	000a8823 */ 	negu	$s1,$t2
/*     8230:	afa00044 */ 	sw	$zero,0x44($sp)
/*     8234:	0800211d */ 	j	.L00008474
/*     8238:	24100000 */ 	addiu	$s0,$zero,0x0
/*     823c:	022a8821 */ 	addu	$s1,$s1,$t2
.L00008240:
/*     8240:	01b18023 */ 	subu	$s0,$t5,$s1
/*     8244:	0150082a */ 	slt	$at,$t2,$s0
/*     8248:	10200002 */ 	beqz	$at,.L00008254
/*     824c:	24420001 */ 	addiu	$v0,$v0,0x1
/*     8250:	01408025 */ 	or	$s0,$t2,$zero
.L00008254:
/*     8254:	01915823 */ 	subu	$t3,$t4,$s1
/*     8258:	24120001 */ 	addiu	$s2,$zero,0x1
/*     825c:	01729004 */ 	sllv	$s2,$s2,$t3
/*     8260:	24970001 */ 	addiu	$s7,$a0,0x1
/*     8264:	02f2082a */ 	slt	$at,$s7,$s2
/*     8268:	10200012 */ 	beqz	$at,.L000082b4
/*     826c:	00000000 */ 	nop
/*     8270:	02579023 */ 	subu	$s2,$s2,$s7
/*     8274:	000c7080 */ 	sll	$t6,$t4,0x2
/*     8278:	01dd7021 */ 	addu	$t6,$t6,$sp
/*     827c:	25ce0000 */ 	addiu	$t6,$t6,0x0
/*     8280:	256b0001 */ 	addiu	$t3,$t3,0x1
/*     8284:	0170082a */ 	slt	$at,$t3,$s0
/*     8288:	1020000a */ 	beqz	$at,.L000082b4
/*     828c:	00000000 */ 	nop
.L00008290:
/*     8290:	8dd70004 */ 	lw	$s7,0x4($t6)
/*     8294:	00129040 */ 	sll	$s2,$s2,0x1
/*     8298:	02f2082a */ 	slt	$at,$s7,$s2
/*     829c:	10200005 */ 	beqz	$at,.L000082b4
/*     82a0:	25ce0004 */ 	addiu	$t6,$t6,0x4
/*     82a4:	256b0001 */ 	addiu	$t3,$t3,0x1
/*     82a8:	0170082a */ 	slt	$at,$t3,$s0
/*     82ac:	1420fff8 */ 	bnez	$at,.L00008290
/*     82b0:	02579023 */ 	subu	$s2,$s2,$s7
.L000082b4:
/*     82b4:	24100001 */ 	addiu	$s0,$zero,0x1
/*     82b8:	01708004 */ 	sllv	$s0,$s0,$t3
/*     82bc:	00137080 */ 	sll	$t6,$s3,0x2
/*     82c0:	01d67021 */ 	addu	$t6,$t6,$s6
/*     82c4:	26770001 */ 	addiu	$s7,$s3,0x1
/*     82c8:	a7170000 */ 	sh	$s7,0x0($t8)
/*     82cc:	25d80002 */ 	addiu	$t8,$t6,0x2
/*     82d0:	a7000000 */ 	sh	$zero,0x0($t8)
/*     82d4:	25ce0004 */ 	addiu	$t6,$t6,0x4
/*     82d8:	0002b880 */ 	sll	$s7,$v0,0x2
/*     82dc:	02fdb821 */ 	addu	$s7,$s7,$sp
/*     82e0:	10400012 */ 	beqz	$v0,.L0000832c
/*     82e4:	aeee0044 */ 	sw	$t6,0x44($s7)
/*     82e8:	0002b880 */ 	sll	$s7,$v0,0x2
/*     82ec:	02fdb821 */ 	addu	$s7,$s7,$sp
/*     82f0:	aee90504 */ 	sw	$t1,0x504($s7)
/*     82f4:	0140a825 */ 	or	$s5,$t2,$zero
/*     82f8:	25740010 */ 	addiu	$s4,$t3,0x10
/*     82fc:	267c0001 */ 	addiu	$gp,$s3,0x1
/*     8300:	022a5823 */ 	subu	$t3,$s1,$t2
/*     8304:	01695806 */ 	srlv	$t3,$t1,$t3
/*     8308:	2457ffff */ 	addiu	$s7,$v0,-1
/*     830c:	0017b880 */ 	sll	$s7,$s7,0x2
/*     8310:	02fdb821 */ 	addu	$s7,$s7,$sp
/*     8314:	8ef70044 */ 	lw	$s7,0x44($s7)
/*     8318:	000b0880 */ 	sll	$at,$t3,0x2
/*     831c:	02e1b821 */ 	addu	$s7,$s7,$at
/*     8320:	a2f40000 */ 	sb	$s4,0x0($s7)
/*     8324:	a2f50001 */ 	sb	$s5,0x1($s7)
/*     8328:	a6fc0002 */ 	sh	$gp,0x2($s7)
.L0000832c:
/*     832c:	02709821 */ 	addu	$s3,$s3,$s0
/*     8330:	26730001 */ 	addiu	$s3,$s3,0x1
/*     8334:	2a610501 */ 	slti	$at,$s3,0x501
/*     8338:	10200071 */ 	beqz	$at,.L00008500
.L0000833c:
/*     833c:	022ab821 */ 	addu	$s7,$s1,$t2
.L00008340:
/*     8340:	02ec082a */ 	slt	$at,$s7,$t4
/*     8344:	5420ffbe */ 	bnezl	$at,.L00008240
/*     8348:	022a8821 */ 	addu	$s1,$s1,$t2
/*     834c:	0191a823 */ 	subu	$s5,$t4,$s1
/*     8350:	0005b880 */ 	sll	$s7,$a1,0x2
/*     8354:	02fdb821 */ 	addu	$s7,$s7,$sp
/*     8358:	26f70084 */ 	addiu	$s7,$s7,0x84
/*     835c:	0117082a */ 	slt	$at,$t0,$s7
/*     8360:	14200003 */ 	bnez	$at,.L00008370
/*     8364:	24140063 */ 	addiu	$s4,$zero,0x63
/*     8368:	080020ef */ 	j	.L000083bc
/*     836c:	24120001 */ 	addiu	$s2,$zero,0x1
.L00008370:
/*     8370:	8d170000 */ 	lw	$s7,0x0($t0)
/*     8374:	02e6082a */ 	slt	$at,$s7,$a2
/*     8378:	10200008 */ 	beqz	$at,.L0000839c
/*     837c:	00000000 */ 	nop
/*     8380:	02e0e025 */ 	or	$gp,$s7,$zero
/*     8384:	2ae10100 */ 	slti	$at,$s7,0x100
/*     8388:	54200002 */ 	bnezl	$at,.L00008394
/*     838c:	24140010 */ 	addiu	$s4,$zero,0x10
/*     8390:	2414000f */ 	addiu	$s4,$zero,0xf
.L00008394:
/*     8394:	080020ee */ 	j	.L000083b8
/*     8398:	25080004 */ 	addiu	$t0,$t0,0x4
.L0000839c:
/*     839c:	02e6b823 */ 	subu	$s7,$s7,$a2
/*     83a0:	02efa021 */ 	addu	$s4,$s7,$t7
/*     83a4:	92940000 */ 	lbu	$s4,0x0($s4)
/*     83a8:	0017b840 */ 	sll	$s7,$s7,0x1
/*     83ac:	02e7b821 */ 	addu	$s7,$s7,$a3
/*     83b0:	96fc0000 */ 	lhu	$gp,0x0($s7)
/*     83b4:	25080004 */ 	addiu	$t0,$t0,0x4
.L000083b8:
/*     83b8:	24120001 */ 	addiu	$s2,$zero,0x1
.L000083bc:
/*     83bc:	0191b823 */ 	subu	$s7,$t4,$s1
/*     83c0:	02f29004 */ 	sllv	$s2,$s2,$s7
/*     83c4:	02295806 */ 	srlv	$t3,$t1,$s1
/*     83c8:	0170082a */ 	slt	$at,$t3,$s0
/*     83cc:	10200010 */ 	beqz	$at,.L00008410
/*     83d0:	0014be00 */ 	sll	$s7,$s4,0x18
/*     83d4:	32b500ff */ 	andi	$s5,$s5,0xff
/*     83d8:	0015ac00 */ 	sll	$s5,$s5,0x10
/*     83dc:	02f5b825 */ 	or	$s7,$s7,$s5
/*     83e0:	3395ffff */ 	andi	$s5,$gp,0xffff
/*     83e4:	02b7a825 */ 	or	$s5,$s5,$s7
/*     83e8:	00129080 */ 	sll	$s2,$s2,0x2
/*     83ec:	000b5880 */ 	sll	$t3,$t3,0x2
/*     83f0:	016e5821 */ 	addu	$t3,$t3,$t6
/*     83f4:	0010b880 */ 	sll	$s7,$s0,0x2
/*     83f8:	02eeb821 */ 	addu	$s7,$s7,$t6
/*     83fc:	ad750000 */ 	sw	$s5,0x0($t3)
.L00008400:
/*     8400:	01725821 */ 	addu	$t3,$t3,$s2
/*     8404:	0177082a */ 	slt	$at,$t3,$s7
/*     8408:	5420fffd */ 	bnezl	$at,.L00008400
/*     840c:	ad750000 */ 	sw	$s5,0x0($t3)
.L00008410:
/*     8410:	2597ffff */ 	addiu	$s7,$t4,-1
/*     8414:	240b0001 */ 	addiu	$t3,$zero,0x1
/*     8418:	02eb5804 */ 	sllv	$t3,$t3,$s7
/*     841c:	012bb824 */ 	and	$s7,$t1,$t3
/*     8420:	12e00005 */ 	beqz	$s7,.L00008438
/*     8424:	012b4826 */ 	xor	$t1,$t1,$t3
.L00008428:
/*     8428:	000b5842 */ 	srl	$t3,$t3,0x1
/*     842c:	012bb824 */ 	and	$s7,$t1,$t3
/*     8430:	16e0fffd */ 	bnez	$s7,.L00008428
/*     8434:	012b4826 */ 	xor	$t1,$t1,$t3
.L00008438:
/*     8438:	08002112 */ 	j	.L00008448
/*     843c:	241e0001 */ 	addiu	$s8,$zero,0x1
/*     8440:	2442ffff */ 	addiu	$v0,$v0,-1
.L00008444:
/*     8444:	022a8823 */ 	subu	$s1,$s1,$t2
.L00008448:
/*     8448:	023eb804 */ 	sllv	$s7,$s8,$s1
/*     844c:	26f7ffff */ 	addiu	$s7,$s7,-1
/*     8450:	00020880 */ 	sll	$at,$v0,0x2
/*     8454:	003d0821 */ 	addu	$at,$at,$sp
/*     8458:	8c210504 */ 	lw	$at,0x504($at)
/*     845c:	02e9b824 */ 	and	$s7,$s7,$t1
/*     8460:	56e1fff8 */ 	bnel	$s7,$at,.L00008444
/*     8464:	2442ffff */ 	addiu	$v0,$v0,-1
/*     8468:	1480ffb4 */ 	bnez	$a0,.L0000833c
/*     846c:	2484ffff */ 	addiu	$a0,$a0,-1
.L00008470:
/*     8470:	258c0001 */ 	addiu	$t4,$t4,0x1
.L00008474:
/*     8474:	01ac082a */ 	slt	$at,$t5,$t4
/*     8478:	14200007 */ 	bnez	$at,.L00008498
/*     847c:	000c2080 */ 	sll	$a0,$t4,0x2
/*     8480:	009d2021 */ 	addu	$a0,$a0,$sp
/*     8484:	8c840000 */ 	lw	$a0,0x0($a0)
/*     8488:	1080fff9 */ 	beqz	$a0,.L00008470
/*     848c:	2484ffff */ 	addiu	$a0,$a0,-1
/*     8490:	080020d0 */ 	j	.L00008340
/*     8494:	022ab821 */ 	addu	$s7,$s1,$t2
.L00008498:
/*     8498:	57200002 */ 	bnezl	$t9,.L000084a4
/*     849c:	24170001 */ 	addiu	$s7,$zero,0x1
/*     84a0:	24170000 */ 	addiu	$s7,$zero,0x0
.L000084a4:
/*     84a4:	24010001 */ 	addiu	$at,$zero,0x1
/*     84a8:	55a10002 */ 	bnel	$t5,$at,.L000084b4
/*     84ac:	24010001 */ 	addiu	$at,$zero,0x1
/*     84b0:	24010000 */ 	addiu	$at,$zero,0x0
.L000084b4:
/*     84b4:	02e11024 */ 	and	$v0,$s7,$at
/*     84b8:	44939800 */ 	mtc1	$s3,$f19
.L000084bc:
/*     84bc:	44101000 */ 	mfc1	$s0,$f2
/*     84c0:	44111800 */ 	mfc1	$s1,$f3
/*     84c4:	44122000 */ 	mfc1	$s2,$f4
/*     84c8:	44132800 */ 	mfc1	$s3,$f5
/*     84cc:	44143000 */ 	mfc1	$s4,$f6
/*     84d0:	44153800 */ 	mfc1	$s5,$f7
/*     84d4:	44164000 */ 	mfc1	$s6,$f8
/*     84d8:	44174800 */ 	mfc1	$s7,$f9
/*     84dc:	441e5000 */ 	mfc1	$s8,$f10
/*     84e0:	03e00008 */ 	jr	$ra
/*     84e4:	441c5800 */ 	mfc1	$gp,$f11
.L000084e8:
/*     84e8:	03e00008 */ 	jr	$ra
/*     84ec:	24020001 */ 	addiu	$v0,$zero,0x1
.L000084f0:
/*     84f0:	a7000000 */ 	sh	$zero,0x0($t8)
/*     84f4:	af200000 */ 	sw	$zero,0x0($t9)
/*     84f8:	0800212f */ 	j	.L000084bc
/*     84fc:	24020000 */ 	addiu	$v0,$zero,0x0
.L00008500:
/*     8500:	27bdff80 */ 	addiu	$sp,$sp,-128
/*     8504:	afbf0000 */ 	sw	$ra,0x0($sp)
/*     8508:	afa10004 */ 	sw	$at,0x4($sp)
/*     850c:	afa20008 */ 	sw	$v0,0x8($sp)
/*     8510:	afa3000c */ 	sw	$v1,0xc($sp)
/*     8514:	afa40010 */ 	sw	$a0,0x10($sp)
/*     8518:	afa50014 */ 	sw	$a1,0x14($sp)
/*     851c:	afa60018 */ 	sw	$a2,0x18($sp)
/*     8520:	afa7001c */ 	sw	$a3,0x1c($sp)
/*     8524:	afa80020 */ 	sw	$t0,0x20($sp)
/*     8528:	afa90024 */ 	sw	$t1,0x24($sp)
/*     852c:	afaa0028 */ 	sw	$t2,0x28($sp)
/*     8530:	afab002c */ 	sw	$t3,0x2c($sp)
/*     8534:	afac0030 */ 	sw	$t4,0x30($sp)
/*     8538:	afad0034 */ 	sw	$t5,0x34($sp)
/*     853c:	afae0038 */ 	sw	$t6,0x38($sp)
/*     8540:	afaf003c */ 	sw	$t7,0x3c($sp)
/*     8544:	afb00040 */ 	sw	$s0,0x40($sp)
/*     8548:	afb10044 */ 	sw	$s1,0x44($sp)
/*     854c:	afb20048 */ 	sw	$s2,0x48($sp)
/*     8550:	afb3004c */ 	sw	$s3,0x4c($sp)
/*     8554:	afb40050 */ 	sw	$s4,0x50($sp)
/*     8558:	afb50054 */ 	sw	$s5,0x54($sp)
/*     855c:	afb60058 */ 	sw	$s6,0x58($sp)
/*     8560:	afb7005c */ 	sw	$s7,0x5c($sp)
/*     8564:	afb80060 */ 	sw	$t8,0x60($sp)
/*     8568:	afb90064 */ 	sw	$t9,0x64($sp)
/*     856c:	afbc0070 */ 	sw	$gp,0x70($sp)
/*     8570:	afbd0074 */ 	sw	$sp,0x74($sp)
/*     8574:	afbe0078 */ 	sw	$s8,0x78($sp)
/*     8578:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*     857c:	afb30004 */ 	sw	$s3,0x4($sp)
/*     8580:	3c047005 */ 	lui	$a0,%hi(var7005261c+0x2b)
/*     8584:	24842647 */ 	addiu	$a0,$a0,%lo(var7005261c+0x2b)
/*     8588:	0c00bea9 */ 	jal	rmonPrint
/*     858c:	8fa50004 */ 	lw	$a1,0x4($sp)
/*     8590:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*     8594:	8fbf0000 */ 	lw	$ra,0x0($sp)
/*     8598:	8fa10004 */ 	lw	$at,0x4($sp)
/*     859c:	8fa20008 */ 	lw	$v0,0x8($sp)
/*     85a0:	8fa3000c */ 	lw	$v1,0xc($sp)
/*     85a4:	8fa40010 */ 	lw	$a0,0x10($sp)
/*     85a8:	8fa50014 */ 	lw	$a1,0x14($sp)
/*     85ac:	8fa60018 */ 	lw	$a2,0x18($sp)
/*     85b0:	8fa7001c */ 	lw	$a3,0x1c($sp)
/*     85b4:	8fa80020 */ 	lw	$t0,0x20($sp)
/*     85b8:	8fa90024 */ 	lw	$t1,0x24($sp)
/*     85bc:	8faa0028 */ 	lw	$t2,0x28($sp)
/*     85c0:	8fab002c */ 	lw	$t3,0x2c($sp)
/*     85c4:	8fac0030 */ 	lw	$t4,0x30($sp)
/*     85c8:	8fad0034 */ 	lw	$t5,0x34($sp)
/*     85cc:	8fae0038 */ 	lw	$t6,0x38($sp)
/*     85d0:	8faf003c */ 	lw	$t7,0x3c($sp)
/*     85d4:	8fb00040 */ 	lw	$s0,0x40($sp)
/*     85d8:	8fb10044 */ 	lw	$s1,0x44($sp)
/*     85dc:	8fb20048 */ 	lw	$s2,0x48($sp)
/*     85e0:	8fb3004c */ 	lw	$s3,0x4c($sp)
/*     85e4:	8fb40050 */ 	lw	$s4,0x50($sp)
/*     85e8:	8fb50054 */ 	lw	$s5,0x54($sp)
/*     85ec:	8fb60058 */ 	lw	$s6,0x58($sp)
/*     85f0:	8fb7005c */ 	lw	$s7,0x5c($sp)
/*     85f4:	8fb80060 */ 	lw	$t8,0x60($sp)
/*     85f8:	8fb90064 */ 	lw	$t9,0x64($sp)
/*     85fc:	8fbc0070 */ 	lw	$gp,0x70($sp)
/*     8600:	8fbd0074 */ 	lw	$sp,0x74($sp)
/*     8604:	8fbe0078 */ 	lw	$s8,0x78($sp)
/*     8608:	080020cf */ 	j	.L0000833c
/*     860c:	27bd0080 */ 	addiu	$sp,$sp,0x80
);

GLOBAL_ASM(
glabel func00008610
/*     8610:	440b8000 */ 	mfc1	$t3,$f16
/*     8614:	440d9000 */ 	mfc1	$t5,$f18
/*     8618:	44148800 */ 	mfc1	$s4,$f17
/*     861c:	3c107005 */ 	lui	$s0,%hi(var70052530)
/*     8620:	26102530 */ 	addiu	$s0,$s0,%lo(var70052530)
/*     8624:	00067840 */ 	sll	$t7,$a2,0x1
/*     8628:	01f07821 */ 	addu	$t7,$t7,$s0
/*     862c:	95ea0000 */ 	lhu	$t2,0x0($t7)
/*     8630:	00077840 */ 	sll	$t7,$a3,0x1
/*     8634:	01f07821 */ 	addu	$t7,$t7,$s0
/*     8638:	95e80000 */ 	lhu	$t0,0x0($t7)
.L0000863c:
/*     863c:	03c6082a */ 	slt	$at,$s8,$a2
.L00008640:
/*     8640:	10200009 */ 	beqz	$at,.L00008668
/*     8644:	038aa824 */ 	and	$s5,$gp,$t2
.L00008648:
/*     8648:	92f50000 */ 	lbu	$s5,0x0($s7)
/*     864c:	26f70001 */ 	addiu	$s7,$s7,0x1
/*     8650:	03d5a804 */ 	sllv	$s5,$s5,$s8
/*     8654:	27de0008 */ 	addiu	$s8,$s8,0x8
/*     8658:	03c6082a */ 	slt	$at,$s8,$a2
/*     865c:	1420fffa */ 	bnez	$at,.L00008648
/*     8660:	0395e025 */ 	or	$gp,$gp,$s5
/*     8664:	038aa824 */ 	and	$s5,$gp,$t2
.L00008668:
/*     8668:	0015a880 */ 	sll	$s5,$s5,0x2
/*     866c:	02a4a821 */ 	addu	$s5,$s5,$a0
/*     8670:	92b10000 */ 	lbu	$s1,0x0($s5)
/*     8674:	2a210011 */ 	slti	$at,$s1,0x11
/*     8678:	1420001b */ 	bnez	$at,.L000086e8
/*     867c:	24190063 */ 	addiu	$t9,$zero,0x63
/*     8680:	92af0001 */ 	lbu	$t7,0x1($s5)
.L00008684:
/*     8684:	12390086 */ 	beq	$s1,$t9,.L000088a0
/*     8688:	2631fff0 */ 	addiu	$s1,$s1,-16
/*     868c:	03cff023 */ 	subu	$s8,$s8,$t7
/*     8690:	03d1082a */ 	slt	$at,$s8,$s1
/*     8694:	10200008 */ 	beqz	$at,.L000086b8
/*     8698:	01fce006 */ 	srlv	$gp,$gp,$t7
.L0000869c:
/*     869c:	92e10000 */ 	lbu	$at,0x0($s7)
/*     86a0:	26f70001 */ 	addiu	$s7,$s7,0x1
/*     86a4:	03c10804 */ 	sllv	$at,$at,$s8
/*     86a8:	27de0008 */ 	addiu	$s8,$s8,0x8
/*     86ac:	03d1782a */ 	slt	$t7,$s8,$s1
/*     86b0:	15e0fffa */ 	bnez	$t7,.L0000869c
/*     86b4:	0381e025 */ 	or	$gp,$gp,$at
.L000086b8:
/*     86b8:	00117840 */ 	sll	$t7,$s1,0x1
/*     86bc:	01f07821 */ 	addu	$t7,$t7,$s0
/*     86c0:	95ef0000 */ 	lhu	$t7,0x0($t7)
/*     86c4:	96b80002 */ 	lhu	$t8,0x2($s5)
/*     86c8:	01fc7824 */ 	and	$t7,$t7,$gp
/*     86cc:	01f87821 */ 	addu	$t7,$t7,$t8
/*     86d0:	000f7880 */ 	sll	$t7,$t7,0x2
/*     86d4:	02cfa821 */ 	addu	$s5,$s6,$t7
/*     86d8:	92b10000 */ 	lbu	$s1,0x0($s5)
/*     86dc:	2a210011 */ 	slti	$at,$s1,0x11
/*     86e0:	5020ffe8 */ 	beqzl	$at,.L00008684
/*     86e4:	92af0001 */ 	lbu	$t7,0x1($s5)
.L000086e8:
/*     86e8:	92af0001 */ 	lbu	$t7,0x1($s5)
/*     86ec:	24010010 */ 	addiu	$at,$zero,0x10
/*     86f0:	01fce006 */ 	srlv	$gp,$gp,$t7
/*     86f4:	16210006 */ 	bne	$s1,$at,.L00008710
/*     86f8:	03cff023 */ 	subu	$s8,$s8,$t7
/*     86fc:	96af0002 */ 	lhu	$t7,0x2($s5)
/*     8700:	0174c021 */ 	addu	$t8,$t3,$s4
/*     8704:	a30f0000 */ 	sb	$t7,0x0($t8)
/*     8708:	0800218f */ 	j	.L0000863c
/*     870c:	26940001 */ 	addiu	$s4,$s4,0x1
.L00008710:
/*     8710:	2401000f */ 	addiu	$at,$zero,0xf
/*     8714:	1221005f */ 	beq	$s1,$at,.L00008894
/*     8718:	00000000 */ 	nop
/*     871c:	03d1082a */ 	slt	$at,$s8,$s1
/*     8720:	10200008 */ 	beqz	$at,.L00008744
/*     8724:	00117840 */ 	sll	$t7,$s1,0x1
.L00008728:
/*     8728:	92f90000 */ 	lbu	$t9,0x0($s7)
/*     872c:	26f70001 */ 	addiu	$s7,$s7,0x1
/*     8730:	03d9c804 */ 	sllv	$t9,$t9,$s8
/*     8734:	27de0008 */ 	addiu	$s8,$s8,0x8
/*     8738:	03d1082a */ 	slt	$at,$s8,$s1
/*     873c:	1420fffa */ 	bnez	$at,.L00008728
/*     8740:	0399e025 */ 	or	$gp,$gp,$t9
.L00008744:
/*     8744:	01f07821 */ 	addu	$t7,$t7,$s0
/*     8748:	95ef0000 */ 	lhu	$t7,0x0($t7)
/*     874c:	96b80002 */ 	lhu	$t8,0x2($s5)
/*     8750:	01fc7824 */ 	and	$t7,$t7,$gp
/*     8754:	01f89021 */ 	addu	$s2,$t7,$t8
/*     8758:	03d1f023 */ 	subu	$s8,$s8,$s1
/*     875c:	03c7082a */ 	slt	$at,$s8,$a3
/*     8760:	10200008 */ 	beqz	$at,.L00008784
/*     8764:	023ce006 */ 	srlv	$gp,$gp,$s1
.L00008768:
/*     8768:	92ef0000 */ 	lbu	$t7,0x0($s7)
/*     876c:	26f70001 */ 	addiu	$s7,$s7,0x1
/*     8770:	03cf7804 */ 	sllv	$t7,$t7,$s8
/*     8774:	27de0008 */ 	addiu	$s8,$s8,0x8
/*     8778:	03c7082a */ 	slt	$at,$s8,$a3
/*     877c:	1420fffa */ 	bnez	$at,.L00008768
/*     8780:	038fe025 */ 	or	$gp,$gp,$t7
.L00008784:
/*     8784:	03887824 */ 	and	$t7,$gp,$t0
/*     8788:	000f7880 */ 	sll	$t7,$t7,0x2
/*     878c:	00afa821 */ 	addu	$s5,$a1,$t7
/*     8790:	92b10000 */ 	lbu	$s1,0x0($s5)
/*     8794:	2a210011 */ 	slti	$at,$s1,0x11
/*     8798:	1420001d */ 	bnez	$at,.L00008810
/*     879c:	240f0063 */ 	addiu	$t7,$zero,0x63
.L000087a0:
/*     87a0:	122f0041 */ 	beq	$s1,$t7,.L000088a8
/*     87a4:	92af0001 */ 	lbu	$t7,0x1($s5)
/*     87a8:	2631fff0 */ 	addiu	$s1,$s1,-16
/*     87ac:	01fce006 */ 	srlv	$gp,$gp,$t7
/*     87b0:	03cff023 */ 	subu	$s8,$s8,$t7
/*     87b4:	03d1082a */ 	slt	$at,$s8,$s1
/*     87b8:	10200009 */ 	beqz	$at,.L000087e0
/*     87bc:	00000000 */ 	nop
/*     87c0:	92e10000 */ 	lbu	$at,0x0($s7)
.L000087c4:
/*     87c4:	26f70001 */ 	addiu	$s7,$s7,0x1
/*     87c8:	03c10804 */ 	sllv	$at,$at,$s8
/*     87cc:	0381e025 */ 	or	$gp,$gp,$at
/*     87d0:	27de0008 */ 	addiu	$s8,$s8,0x8
/*     87d4:	03d1082a */ 	slt	$at,$s8,$s1
/*     87d8:	5420fffa */ 	bnezl	$at,.L000087c4
/*     87dc:	92e10000 */ 	lbu	$at,0x0($s7)
.L000087e0:
/*     87e0:	00117840 */ 	sll	$t7,$s1,0x1
/*     87e4:	01f07821 */ 	addu	$t7,$t7,$s0
/*     87e8:	95ef0000 */ 	lhu	$t7,0x0($t7)
/*     87ec:	96b80002 */ 	lhu	$t8,0x2($s5)
/*     87f0:	01fc7824 */ 	and	$t7,$t7,$gp
/*     87f4:	01f87821 */ 	addu	$t7,$t7,$t8
/*     87f8:	000f7880 */ 	sll	$t7,$t7,0x2
/*     87fc:	02cfa821 */ 	addu	$s5,$s6,$t7
/*     8800:	92b10000 */ 	lbu	$s1,0x0($s5)
/*     8804:	2a210011 */ 	slti	$at,$s1,0x11
/*     8808:	1020ffe5 */ 	beqz	$at,.L000087a0
/*     880c:	240f0063 */ 	addiu	$t7,$zero,0x63
.L00008810:
/*     8810:	92af0001 */ 	lbu	$t7,0x1($s5)
/*     8814:	0011c040 */ 	sll	$t8,$s1,0x1
/*     8818:	03cff023 */ 	subu	$s8,$s8,$t7
/*     881c:	03d1082a */ 	slt	$at,$s8,$s1
/*     8820:	10200008 */ 	beqz	$at,.L00008844
/*     8824:	01fce006 */ 	srlv	$gp,$gp,$t7
.L00008828:
/*     8828:	92ef0000 */ 	lbu	$t7,0x0($s7)
/*     882c:	26f70001 */ 	addiu	$s7,$s7,0x1
/*     8830:	03cf7804 */ 	sllv	$t7,$t7,$s8
/*     8834:	27de0008 */ 	addiu	$s8,$s8,0x8
/*     8838:	03d1082a */ 	slt	$at,$s8,$s1
/*     883c:	1420fffa */ 	bnez	$at,.L00008828
/*     8840:	038fe025 */ 	or	$gp,$gp,$t7
.L00008844:
/*     8844:	03107821 */ 	addu	$t7,$t8,$s0
/*     8848:	95ef0000 */ 	lhu	$t7,0x0($t7)
/*     884c:	96b80002 */ 	lhu	$t8,0x2($s5)
/*     8850:	01fc7824 */ 	and	$t7,$t7,$gp
/*     8854:	028f9823 */ 	subu	$s3,$s4,$t7
/*     8858:	02789823 */ 	subu	$s3,$s3,$t8
/*     885c:	023ce006 */ 	srlv	$gp,$gp,$s1
/*     8860:	03d1f023 */ 	subu	$s8,$s8,$s1
/*     8864:	02927821 */ 	addu	$t7,$s4,$s2
/*     8868:	0173c021 */ 	addu	$t8,$t3,$s3
/*     886c:	0174c821 */ 	addu	$t9,$t3,$s4
/*     8870:	0292a021 */ 	addu	$s4,$s4,$s2
/*     8874:	01741021 */ 	addu	$v0,$t3,$s4
.L00008878:
/*     8878:	930f0000 */ 	lbu	$t7,0x0($t8)
/*     887c:	27390001 */ 	addiu	$t9,$t9,0x1
/*     8880:	a32fffff */ 	sb	$t7,-0x1($t9)
/*     8884:	1722fffc */ 	bne	$t9,$v0,.L00008878
/*     8888:	27180001 */ 	addiu	$t8,$t8,0x1
/*     888c:	08002190 */ 	j	.L00008640
/*     8890:	03c6082a */ 	slt	$at,$s8,$a2
.L00008894:
/*     8894:	44948800 */ 	mtc1	$s4,$f17
/*     8898:	03e00008 */ 	jr	$ra
/*     889c:	24020000 */ 	addiu	$v0,$zero,0x0
.L000088a0:
/*     88a0:	03e00008 */ 	jr	$ra
/*     88a4:	24020002 */ 	addiu	$v0,$zero,0x2
.L000088a8:
/*     88a8:	03e00008 */ 	jr	$ra
/*     88ac:	24020004 */ 	addiu	$v0,$zero,0x4
);

GLOBAL_ASM(
glabel func000088b0
/*     88b0:	27bdf578 */ 	addiu	$sp,$sp,-2696
/*     88b4:	afb00a48 */ 	sw	$s0,0xa48($sp)
/*     88b8:	afb10a4c */ 	sw	$s1,0xa4c($sp)
/*     88bc:	afb20a50 */ 	sw	$s2,0xa50($sp)
/*     88c0:	afb30a54 */ 	sw	$s3,0xa54($sp)
/*     88c4:	afb40a58 */ 	sw	$s4,0xa58($sp)
/*     88c8:	afb50a5c */ 	sw	$s5,0xa5c($sp)
/*     88cc:	afb60a60 */ 	sw	$s6,0xa60($sp)
/*     88d0:	afb70a64 */ 	sw	$s7,0xa64($sp)
/*     88d4:	afbf0a80 */ 	sw	$ra,0xa80($sp)
/*     88d8:	44809800 */ 	mtc1	$zero,$f19
/*     88dc:	3c168009 */ 	lui	$s6,%hi(var80090b10)
/*     88e0:	26d60b10 */ 	addiu	$s6,$s6,%lo(var80090b10)
/*     88e4:	24080008 */ 	addiu	$t0,$zero,0x8
/*     88e8:	27aa0548 */ 	addiu	$t2,$sp,0x548
/*     88ec:	25490240 */ 	addiu	$t1,$t2,0x240
.L000088f0:
/*     88f0:	254a0004 */ 	addiu	$t2,$t2,0x4
/*     88f4:	1549fffe */ 	bne	$t2,$t1,.L000088f0
/*     88f8:	ad48fffc */ 	sw	$t0,-0x4($t2)
/*     88fc:	24080009 */ 	addiu	$t0,$zero,0x9
/*     8900:	254901c0 */ 	addiu	$t1,$t2,0x1c0
.L00008904:
/*     8904:	254a0004 */ 	addiu	$t2,$t2,0x4
/*     8908:	1549fffe */ 	bne	$t2,$t1,.L00008904
/*     890c:	ad48fffc */ 	sw	$t0,-0x4($t2)
/*     8910:	24080007 */ 	addiu	$t0,$zero,0x7
/*     8914:	25490060 */ 	addiu	$t1,$t2,0x60
.L00008918:
/*     8918:	254a0004 */ 	addiu	$t2,$t2,0x4
/*     891c:	1549fffe */ 	bne	$t2,$t1,.L00008918
/*     8920:	ad48fffc */ 	sw	$t0,-0x4($t2)
/*     8924:	24080008 */ 	addiu	$t0,$zero,0x8
/*     8928:	25490020 */ 	addiu	$t1,$t2,0x20
.L0000892c:
/*     892c:	254a0004 */ 	addiu	$t2,$t2,0x4
/*     8930:	1549fffe */ 	bne	$t2,$t1,.L0000892c
/*     8934:	ad48fffc */ 	sw	$t0,-0x4($t2)
/*     8938:	24080007 */ 	addiu	$t0,$zero,0x7
/*     893c:	afa809cc */ 	sw	$t0,0x9cc($sp)
/*     8940:	27a40548 */ 	addiu	$a0,$sp,0x548
/*     8944:	24050120 */ 	addiu	$a1,$zero,0x120
/*     8948:	24060101 */ 	addiu	$a2,$zero,0x101
/*     894c:	3c077005 */ 	lui	$a3,%hi(var70052550+0x2)
/*     8950:	24e72552 */ 	addiu	$a3,$a3,%lo(var70052550+0x2)
/*     8954:	3c0f7005 */ 	lui	$t7,%hi(var700525dc+0x3)
/*     8958:	25ef25df */ 	addiu	$t7,$t7,%lo(var700525dc+0x3)
/*     895c:	27b809c8 */ 	addiu	$t8,$sp,0x9c8
/*     8960:	0c002019 */ 	jal	func00008064
/*     8964:	27b909cc */ 	addiu	$t9,$sp,0x9cc
/*     8968:	27a80548 */ 	addiu	$t0,$sp,0x548
/*     896c:	24090005 */ 	addiu	$t1,$zero,0x5
/*     8970:	250a0078 */ 	addiu	$t2,$t0,0x78
.L00008974:
/*     8974:	25080004 */ 	addiu	$t0,$t0,0x4
/*     8978:	150afffe */ 	bne	$t0,$t2,.L00008974
/*     897c:	ad09fffc */ 	sw	$t1,-0x4($t0)
/*     8980:	24080005 */ 	addiu	$t0,$zero,0x5
/*     8984:	afa809d4 */ 	sw	$t0,0x9d4($sp)
/*     8988:	27a40548 */ 	addiu	$a0,$sp,0x548
/*     898c:	2405001e */ 	addiu	$a1,$zero,0x1e
/*     8990:	24060000 */ 	addiu	$a2,$zero,0x0
/*     8994:	3c077005 */ 	lui	$a3,%hi(var70052590)
/*     8998:	24e72590 */ 	addiu	$a3,$a3,%lo(var70052590)
/*     899c:	3c0f7005 */ 	lui	$t7,%hi(var700525fc+0x2)
/*     89a0:	25ef25fe */ 	addiu	$t7,$t7,%lo(var700525fc+0x2)
/*     89a4:	27b809d0 */ 	addiu	$t8,$sp,0x9d0
/*     89a8:	0c002019 */ 	jal	func00008064
/*     89ac:	27b909d4 */ 	addiu	$t9,$sp,0x9d4
/*     89b0:	8fb00a48 */ 	lw	$s0,0xa48($sp)
/*     89b4:	8fb10a4c */ 	lw	$s1,0xa4c($sp)
/*     89b8:	8fb20a50 */ 	lw	$s2,0xa50($sp)
/*     89bc:	8fb30a54 */ 	lw	$s3,0xa54($sp)
/*     89c0:	8fb40a58 */ 	lw	$s4,0xa58($sp)
/*     89c4:	8fb50a5c */ 	lw	$s5,0xa5c($sp)
/*     89c8:	8fb60a60 */ 	lw	$s6,0xa60($sp)
/*     89cc:	8fb70a64 */ 	lw	$s7,0xa64($sp)
/*     89d0:	8fbf0a80 */ 	lw	$ra,0xa80($sp)
/*     89d4:	03e00008 */ 	jr	$ra
/*     89d8:	27bd0a88 */ 	addiu	$sp,$sp,0xa88
);

GLOBAL_ASM(
glabel rzipIs1173
/*     89dc:	24090011 */ 	addiu	$t1,$zero,0x11
/*     89e0:	90880000 */ 	lbu	$t0,0x0($a0)
/*     89e4:	15090006 */ 	bne	$t0,$t1,.L00008a00
/*     89e8:	24090073 */ 	addiu	$t1,$zero,0x73
/*     89ec:	90880001 */ 	lbu	$t0,0x1($a0)
/*     89f0:	15090003 */ 	bne	$t0,$t1,.L00008a00
/*     89f4:	00000000 */ 	nop
/*     89f8:	03e00008 */ 	jr	$ra
/*     89fc:	24020001 */ 	addiu	$v0,$zero,0x1
.L00008a00:
/*     8a00:	03e00008 */ 	jr	$ra
/*     8a04:	24020000 */ 	addiu	$v0,$zero,0x0
);

GLOBAL_ASM(
glabel func00008a08
/*     8a08:	3c028009 */ 	lui	$v0,%hi(var80091558)
/*     8a0c:	24421558 */ 	addiu	$v0,$v0,%lo(var80091558)
/*     8a10:	03e00008 */ 	jr	$ra
/*     8a14:	8c420000 */ 	lw	$v0,0x0($v0)
/*     8a18:	00000000 */ 	nop
/*     8a1c:	00000000 */ 	nop
);
