#include <ultra64.h>
#include "lib/init.h"
#include "lib/sched.h"
#include "constants.h"
#include "gvars/gvars.h"
#include "lib/lib_09660.h"
#include "lib/lib_2faf0.h"
#include "lib/lib_2fba0.h"
#include "lib/lib_2fc60.h"
#include "lib/lib_30ce0.h"
#include "lib/libc/ll.h"
#include "data.h"
#include "types.h"

u32 var8005cf90 = 0x00000000;
u8 var8005cf94 = 1;
u32 var8005cf98 = 0x00000001;
u32 var8005cf9c = 0x000014a0;
u32 var8005cfa0 = 0x00000000;
u32 var8005cfa4 = 0x00001358;
u32 var8005cfa8 = 0x00004d0c;
u32 var8005cfac = 0x00000000;
u32 var8005cfb0 = 0x000053ff;
u32 var8005cfb4 = 0x00000000;
u32 var8005cfb8 = 0x00000000;
u32 var8005cfbc = 0x00000000;
u32 var8005cfc0 = 0x00000001;
u32 var8005cfc4 = 0x000001b8;
u32 var8005cfc8 = 0x00000000;
u32 var8005cfcc = 0x00000068;
u32 var8005cfd0 = 0x00004000;
u32 var8005cfd4 = 0x00000000;
u32 var8005cfd8 = 0x00007fff;
u32 var8005cfdc = 0x00001db0;
u32 var8005cfe0 = 0x00001b58;
u32 var8005cfe4 = 0x00000000;
u32 var8005cfe8 = 0x00000001;
u32 var8005cfec = 0x000001b8;
u32 var8005cff0 = 0x00000000;
u32 var8005cff4 = 0x00000068;
u32 var8005cff8 = 0x00000000;
u32 var8005cffc = 0x00005fff;
u32 var8005d000 = 0x00007fff;
u32 var8005d004 = 0x0000017c;
u32 var8005d008 = 0x000001f4;
u32 var8005d00c = 0x00000000;
u32 var8005d010 = 0x00000006;
u32 var8005d014 = 0x00001868;
u32 var8005d018 = 0x00000000;
u32 var8005d01c = 0x00000160;
u32 var8005d020 = 0x00002666;
u32 var8005d024 = 0xffffd99a;
u32 var8005d028 = 0x00000000;
u32 var8005d02c = 0x00000000;
u32 var8005d030 = 0x00000000;
u32 var8005d034 = 0x00000000;
u32 var8005d038 = 0x00000188;
u32 var8005d03c = 0x00000640;
u32 var8005d040 = 0x0000235e;
u32 var8005d044 = 0xffffd99a;
u32 var8005d048 = 0x0000750c;
u32 var8005d04c = 0x00000000;
u32 var8005d050 = 0x00000000;
u32 var8005d054 = 0x00000bca;
u32 var8005d058 = 0x00000318;
u32 var8005d05c = 0x000009f8;
u32 var8005d060 = 0x00004000;
u32 var8005d064 = 0xffffc000;
u32 var8005d068 = 0x00006d78;
u32 var8005d06c = 0x00000000;
u32 var8005d070 = 0x00000000;
u32 var8005d074 = 0x00001286;
u32 var8005d078 = 0x00000c78;
u32 var8005d07c = 0x000015d8;
u32 var8005d080 = 0x0000521a;
u32 var8005d084 = 0xffffc000;
u32 var8005d088 = 0x0000724f;
u32 var8005d08c = 0x00000000;
u32 var8005d090 = 0x00000000;
u32 var8005d094 = 0x00001650;
u32 var8005d098 = 0x00000d28;
u32 var8005d09c = 0x000012c0;
u32 var8005d0a0 = 0x00002143;
u32 var8005d0a4 = 0xffffe000;
u32 var8005d0a8 = 0x00005de4;
u32 var8005d0ac = 0x00000000;
u32 var8005d0b0 = 0x00000000;
u32 var8005d0b4 = 0x00002286;
u32 var8005d0b8 = 0x00000000;
u32 var8005d0bc = 0x00001720;
u32 var8005d0c0 = 0x000032c8;
u32 var8005d0c4 = 0xffffcd38;
u32 var8005d0c8 = 0x00000000;
u32 var8005d0cc = 0x00000000;
u32 var8005d0d0 = 0x00000000;
u32 var8005d0d4 = 0x00004500;
u32 var8005d0d8 = 0x00000002;
u32 var8005d0dc = 0x000008b0;
u32 var8005d0e0 = 0x00000600;
u32 var8005d0e4 = 0x00000760;
u32 var8005d0e8 = 0x00007142;
u32 var8005d0ec = 0x00000000;
u32 var8005d0f0 = 0x00005bff;
u32 var8005d0f4 = 0x00000000;
u32 var8005d0f8 = 0x00000000;
u32 var8005d0fc = 0x00007bc9;
u32 var8005d100 = 0x00000000;
u32 var8005d104 = 0x00000528;
u32 var8005d108 = 0x00005f27;
u32 var8005d10c = 0xffffb288;
u32 var8005d110 = 0x00007ef1;
u32 var8005d114 = 0x00000000;
u32 var8005d118 = 0x00000001;
u32 var8005d11c = 0x000066bb;
u32 var8005d120 = 0x00000003;
u32 var8005d124 = 0x00000b40;
u32 var8005d128 = 0x00000000;
u32 var8005d12c = 0x00000160;
u32 var8005d130 = 0x00002666;
u32 var8005d134 = 0xffffd99a;
u32 var8005d138 = 0x00000000;
u32 var8005d13c = 0x00000000;
u32 var8005d140 = 0x00000000;
u32 var8005d144 = 0x00000000;
u32 var8005d148 = 0x00000188;
u32 var8005d14c = 0x00000640;
u32 var8005d150 = 0x0000235e;
u32 var8005d154 = 0xffffd99a;
u32 var8005d158 = 0x000016f2;
u32 var8005d15c = 0x00000000;
u32 var8005d160 = 0x00000000;
u32 var8005d164 = 0x00000bca;
u32 var8005d168 = 0x00000318;
u32 var8005d16c = 0x000009f8;
u32 var8005d170 = 0x00004000;
u32 var8005d174 = 0xffffc000;
u32 var8005d178 = 0x0000186b;
u32 var8005d17c = 0x00000000;
u32 var8005d180 = 0x00000000;
u32 var8005d184 = 0x00001286;
u32 var8005d188 = 0x00000003;
u32 var8005d18c = 0x00000b40;
u32 var8005d190 = 0x00000000;
u32 var8005d194 = 0x00000160;
u32 var8005d198 = 0x00002666;
u32 var8005d19c = 0xffffd99a;
u32 var8005d1a0 = 0x00000000;
u32 var8005d1a4 = 0x00000000;
u32 var8005d1a8 = 0x00000000;
u32 var8005d1ac = 0x00000000;
u32 var8005d1b0 = 0x00000188;
u32 var8005d1b4 = 0x00000640;
u32 var8005d1b8 = 0x0000235e;
u32 var8005d1bc = 0xffffd99a;
u32 var8005d1c0 = 0x000016f2;
u32 var8005d1c4 = 0x00000000;
u32 var8005d1c8 = 0x00000000;
u32 var8005d1cc = 0x00000bca;
u32 var8005d1d0 = 0x00000318;
u32 var8005d1d4 = 0x000009f8;
u32 var8005d1d8 = 0x00004000;
u32 var8005d1dc = 0xffffc000;
u32 var8005d1e0 = 0x0000186b;
u32 var8005d1e4 = 0x00000000;
u32 var8005d1e8 = 0x00000000;
u32 var8005d1ec = 0x00001286;
u32 var8005d1f0 = 0x00000003;
u32 var8005d1f4 = 0x00000898;
u32 var8005d1f8 = 0x00000000;
u32 var8005d1fc = 0x000004a0;
u32 var8005d200 = 0x00002666;
u32 var8005d204 = 0xffffd99a;
u32 var8005d208 = 0x00000000;
u32 var8005d20c = 0x00000000;
u32 var8005d210 = 0x00000000;
u32 var8005d214 = 0x00000000;
u32 var8005d218 = 0x000001a0;
u32 var8005d21c = 0x00000340;
u32 var8005d220 = 0x00000ccc;
u32 var8005d224 = 0xfffff334;
u32 var8005d228 = 0x00003fff;
u32 var8005d22c = 0x00000000;
u32 var8005d230 = 0x00000000;
u32 var8005d234 = 0x00000000;
u32 var8005d238 = 0x00000000;
u32 var8005d23c = 0x00000528;
u32 var8005d240 = 0x00001388;
u32 var8005d244 = 0x00000000;
u32 var8005d248 = 0x00000000;
u32 var8005d24c = 0x00000000;
u32 var8005d250 = 0x00000000;
u32 var8005d254 = 0x00005000;
u32 var8005d258 = 0x00000004;
u32 var8005d25c = 0x00000898;
u32 var8005d260 = 0x00000000;
u32 var8005d264 = 0x000005a8;
u32 var8005d268 = 0x00002666;
u32 var8005d26c = 0xffffd99a;
u32 var8005d270 = 0x00000000;
u32 var8005d274 = 0x00000000;
u32 var8005d278 = 0x00000000;
u32 var8005d27c = 0x00000000;
u32 var8005d280 = 0x000001e0;
u32 var8005d284 = 0x000004a0;
u32 var8005d288 = 0x00000ccc;
u32 var8005d28c = 0xfffff334;
u32 var8005d290 = 0x00003fff;
u32 var8005d294 = 0x00000000;
u32 var8005d298 = 0x00000000;
u32 var8005d29c = 0x00000000;
u32 var8005d2a0 = 0x000005a8;
u32 var8005d2a4 = 0x000007d0;
u32 var8005d2a8 = 0x00000ccc;
u32 var8005d2ac = 0xfffff334;
u32 var8005d2b0 = 0x00003fff;
u32 var8005d2b4 = 0x00000000;
u32 var8005d2b8 = 0x00000000;
u32 var8005d2bc = 0x00000000;
u32 var8005d2c0 = 0x00000000;
u32 var8005d2c4 = 0x00000810;
u32 var8005d2c8 = 0x00001f40;
u32 var8005d2cc = 0x00000000;
u32 var8005d2d0 = 0x00000000;
u32 var8005d2d4 = 0x00000000;
u32 var8005d2d8 = 0x00000000;
u32 var8005d2dc = 0x00005000;
u32 var8005d2e0 = 0x00000001;
u32 var8005d2e4 = 0x00001130;
u32 var8005d2e8 = 0x00000000;
u32 var8005d2ec = 0x00000f60;
u32 var8005d2f0 = 0x00002ee0;
u32 var8005d2f4 = 0x00000000;
u32 var8005d2f8 = 0x00007fff;
u32 var8005d2fc = 0x00000000;
u32 var8005d300 = 0x00000000;
u32 var8005d304 = 0x00000000;
u32 var8005d308 = 0x00000004;
u32 var8005d30c = 0x00000e98;
u32 var8005d310 = 0x000000c0;
u32 var8005d314 = 0x00000188;
u32 var8005d318 = 0x00002666;
u32 var8005d31c = 0xffffd99a;
u32 var8005d320 = 0x00003484;
u32 var8005d324 = 0x00000000;
u32 var8005d328 = 0x00000000;
u32 var8005d32c = 0x00000000;
u32 var8005d330 = 0x000001b8;
u32 var8005d334 = 0x00000580;
u32 var8005d338 = 0x00004000;
u32 var8005d33c = 0xffffc000;
u32 var8005d340 = 0x000019eb;
u32 var8005d344 = 0x00000000;
u32 var8005d348 = 0x00000000;
u32 var8005d34c = 0x00000000;
u32 var8005d350 = 0x00000a50;
u32 var8005d354 = 0x00000b98;
u32 var8005d358 = 0x00002000;
u32 var8005d35c = 0xffffe000;
u32 var8005d360 = 0x00000000;
u32 var8005d364 = 0x00000000;
u32 var8005d368 = 0x00000000;
u32 var8005d36c = 0x00000000;
u32 var8005d370 = 0x00000000;
u32 var8005d374 = 0x00000cb8;
u32 var8005d378 = 0x00004650;
u32 var8005d37c = 0xffffb9b0;
u32 var8005d380 = 0x00000000;
u32 var8005d384 = 0x0000017c;
u32 var8005d388 = 0x0000000a;
u32 var8005d38c = 0x00000000;
u32 var8005d390 = 0x00000001;
u32 var8005d394 = 0x00000528;
u32 var8005d398 = 0x00000000;
u32 var8005d39c = 0x00000448;
u32 var8005d3a0 = 0x00003334;
u32 var8005d3a4 = 0x00000000;
u32 var8005d3a8 = 0x00007335;
u32 var8005d3ac = 0x00000000;
u32 var8005d3b0 = 0x00000000;
u32 var8005d3b4 = 0x00000000;
u32 var8005d3b8 = 0x00000008;
u32 var8005d3bc = 0x00001b80;
u32 var8005d3c0 = 0x00000000;
u32 var8005d3c4 = 0x000000c0;
u32 var8005d3c8 = 0x00002666;
u32 var8005d3cc = 0xffffd99a;
u32 var8005d3d0 = 0x00000000;
u32 var8005d3d4 = 0x00000000;
u32 var8005d3d8 = 0x00000000;
u32 var8005d3dc = 0x00000000;
u32 var8005d3e0 = 0x000000c0;
u32 var8005d3e4 = 0x00000188;
u32 var8005d3e8 = 0x00002666;
u32 var8005d3ec = 0xffffd99a;
u32 var8005d3f0 = 0x00002b84;
u32 var8005d3f4 = 0x00000000;
u32 var8005d3f8 = 0x00000000;
u32 var8005d3fc = 0x00000000;
u32 var8005d400 = 0x00000370;
u32 var8005d404 = 0x00000b00;
u32 var8005d408 = 0x00004000;
u32 var8005d40c = 0xffffc000;
u32 var8005d410 = 0x000011eb;
u32 var8005d414 = 0x00000000;
u32 var8005d418 = 0x00000000;
u32 var8005d41c = 0x00000000;
u32 var8005d420 = 0x00000420;
u32 var8005d424 = 0x00000840;
u32 var8005d428 = 0x00002000;
u32 var8005d42c = 0xffffe000;
u32 var8005d430 = 0x00000000;
u32 var8005d434 = 0x00000000;
u32 var8005d438 = 0x00000000;
u32 var8005d43c = 0x00000000;
u32 var8005d440 = 0x00000dc0;
u32 var8005d444 = 0x00001810;
u32 var8005d448 = 0x00004000;
u32 var8005d44c = 0xffffc000;
u32 var8005d450 = 0x000011eb;
u32 var8005d454 = 0x00000000;
u32 var8005d458 = 0x00000000;
u32 var8005d45c = 0x00000000;
u32 var8005d460 = 0x00000e70;
u32 var8005d464 = 0x000014a0;
u32 var8005d468 = 0x00002000;
u32 var8005d46c = 0xffffe000;
u32 var8005d470 = 0x00000000;
u32 var8005d474 = 0x00000000;
u32 var8005d478 = 0x00000000;
u32 var8005d47c = 0x00000000;
u32 var8005d480 = 0x000014a0;
u32 var8005d484 = 0x00001738;
u32 var8005d488 = 0x00002000;
u32 var8005d48c = 0xffffe000;
u32 var8005d490 = 0x00000000;
u32 var8005d494 = 0x00000000;
u32 var8005d498 = 0x00000000;
u32 var8005d49c = 0x00000000;
u32 var8005d4a0 = 0x00000000;
u32 var8005d4a4 = 0x00001970;
u32 var8005d4a8 = 0x000032c8;
u32 var8005d4ac = 0xffffcd38;
u32 var8005d4b0 = 0x00000000;
u32 var8005d4b4 = 0x0000017c;
u32 var8005d4b8 = 0x0000000a;
u32 var8005d4bc = 0x00000000;
u32 var8005d4c0 = 0x00000001;
u32 var8005d4c4 = 0x00000a50;
u32 var8005d4c8 = 0x00000000;
u32 var8005d4cc = 0x00000898;
u32 var8005d4d0 = 0x00003334;
u32 var8005d4d4 = 0x00000000;
u32 var8005d4d8 = 0x00007335;
u32 var8005d4dc = 0x00000000;
u32 var8005d4e0 = 0x00000000;
u32 var8005d4e4 = 0x00000000;
u32 var8005d4e8 = 0x00000001;
u32 var8005d4ec = 0x00000148;
u32 var8005d4f0 = 0x00000000;
u32 var8005d4f4 = 0x00000000;
u32 var8005d4f8 = 0x00000000;
u32 var8005d4fc = 0x00000000;
u32 var8005d500 = 0x00000000;
u32 var8005d504 = 0x00000000;
u32 var8005d508 = 0x00000000;
u32 var8005d50c = 0x00000000;
s8 g_AudioIsThreadRunning = false;
u32 var8005d514 = 0x00000001;

void amgrHandleDoneMsg(AudioInfo *info);

void amgrAllocateStack(void)
{
	g_AudioSp = allocateStack(THREAD_AUDIO, STACKSIZE_AUDIO);
}

GLOBAL_ASM(
glabel amgrCreate
/*     8a48:	27bdfa40 */ 	addiu	$sp,$sp,-1472
/*     8a4c:	afbf0034 */ 	sw	$ra,0x34($sp)
/*     8a50:	afa405c0 */ 	sw	$a0,0x5c0($sp)
/*     8a54:	afb50030 */ 	sw	$s5,0x30($sp)
/*     8a58:	afb4002c */ 	sw	$s4,0x2c($sp)
/*     8a5c:	afb30028 */ 	sw	$s3,0x28($sp)
/*     8a60:	afb20024 */ 	sw	$s2,0x24($sp)
/*     8a64:	afb10020 */ 	sw	$s1,0x20($sp)
/*     8a68:	afb0001c */ 	sw	$s0,0x1c($sp)
/*     8a6c:	0c01389c */ 	jal	osAiSetFrequency
/*     8a70:	24045604 */ 	addiu	$a0,$zero,0x5604
/*     8a74:	44822000 */ 	mtc1	$v0,$f4
/*     8a78:	3c0141f0 */ 	lui	$at,0x41f0
/*     8a7c:	44814000 */ 	mtc1	$at,$f8
/*     8a80:	468021a0 */ 	cvt.s.w	$f6,$f4
/*     8a84:	8fa505c0 */ 	lw	$a1,0x5c0($sp)
/*     8a88:	3c0e7001 */ 	lui	$t6,%hi(func00009844)
/*     8a8c:	3c158009 */ 	lui	$s5,%hi(g_Is4Mb)
/*     8a90:	25ce9844 */ 	addiu	$t6,$t6,%lo(func00009844)
/*     8a94:	26b50af0 */ 	addiu	$s5,$s5,%lo(g_Is4Mb)
/*     8a98:	46083083 */ 	div.s	$f2,$f6,$f8
/*     8a9c:	aca20018 */ 	sw	$v0,0x18($a1)
/*     8aa0:	acae0010 */ 	sw	$t6,0x10($a1)
/*     8aa4:	92af0000 */ 	lbu	$t7,0x0($s5)
/*     8aa8:	24140001 */ 	addiu	$s4,$zero,0x1
/*     8aac:	240400b8 */ 	addiu	$a0,$zero,0xb8
/*     8ab0:	168f0006 */ 	bne	$s4,$t7,.L00008acc
/*     8ab4:	46001006 */ 	mov.s	$f0,$f2
/*     8ab8:	3c013f00 */ 	lui	$at,0x3f00
/*     8abc:	44815000 */ 	mtc1	$at,$f10
/*     8ac0:	00000000 */ 	nop
/*     8ac4:	460a1002 */ 	mul.s	$f0,$f2,$f10
/*     8ac8:	00000000 */ 	nop
.L00008acc:
/*     8acc:	4600040d */ 	trunc.w.s	$f16,$f0
/*     8ad0:	3c038009 */ 	lui	$v1,%hi(var800918e0)
/*     8ad4:	246318e0 */ 	addiu	$v1,$v1,%lo(var800918e0)
/*     8ad8:	44198000 */ 	mfc1	$t9,$f16
/*     8adc:	00000000 */ 	nop
/*     8ae0:	03201025 */ 	or	$v0,$t9,$zero
/*     8ae4:	44829000 */ 	mtc1	$v0,$f18
/*     8ae8:	ac790000 */ 	sw	$t9,0x0($v1)
/*     8aec:	07210005 */ 	bgez	$t9,.L00008b04
/*     8af0:	46809120 */ 	cvt.s.w	$f4,$f18
/*     8af4:	3c014f80 */ 	lui	$at,0x4f80
/*     8af8:	44813000 */ 	mtc1	$at,$f6
/*     8afc:	00000000 */ 	nop
/*     8b00:	46062100 */ 	add.s	$f4,$f4,$f6
.L00008b04:
/*     8b04:	4600203c */ 	c.lt.s	$f4,$f0
/*     8b08:	00000000 */ 	nop
/*     8b0c:	45000004 */ 	bc1f	.L00008b20
/*     8b10:	00000000 */ 	nop
/*     8b14:	24480001 */ 	addiu	$t0,$v0,0x1
/*     8b18:	ac680000 */ 	sw	$t0,0x0($v1)
/*     8b1c:	01001025 */ 	or	$v0,$t0,$zero
.L00008b20:
/*     8b20:	0044001b */ 	divu	$zero,$v0,$a0
/*     8b24:	00004812 */ 	mflo	$t1
/*     8b28:	3c018009 */ 	lui	$at,%hi(var800918dc)
/*     8b2c:	14800002 */ 	bnez	$a0,.L00008b38
/*     8b30:	00000000 */ 	nop
/*     8b34:	0007000d */ 	break	0x7
.L00008b38:
/*     8b38:	01240019 */ 	multu	$t1,$a0
/*     8b3c:	00005012 */ 	mflo	$t2
/*     8b40:	254b00b8 */ 	addiu	$t3,$t2,0xb8
/*     8b44:	ac6b0000 */ 	sw	$t3,0x0($v1)
/*     8b48:	256cff48 */ 	addiu	$t4,$t3,-184
/*     8b4c:	ac2c18dc */ 	sw	$t4,%lo(var800918dc)($at)
/*     8b50:	3c018009 */ 	lui	$at,%hi(var800918e4)
/*     8b54:	256d0050 */ 	addiu	$t5,$t3,0x50
/*     8b58:	ac2d18e4 */ 	sw	$t5,%lo(var800918e4)($at)
/*     8b5c:	3c018006 */ 	lui	$at,%hi(var8005cf94)
/*     8b60:	0c002598 */ 	jal	func00009660
/*     8b64:	a020cf94 */ 	sb	$zero,%lo(var8005cf94)($at)
/*     8b68:	3c048009 */ 	lui	$a0,%hi(g_AudioManager+0x280)
/*     8b6c:	3c058009 */ 	lui	$a1,%hi(var80091860)
/*     8b70:	24a51860 */ 	addiu	$a1,$a1,%lo(var80091860)
/*     8b74:	24841848 */ 	addiu	$a0,$a0,%lo(g_AudioManager+0x280)
/*     8b78:	0c0120d0 */ 	jal	osCreateMesgQueue
/*     8b7c:	24060008 */ 	addiu	$a2,$zero,0x8
/*     8b80:	3c048009 */ 	lui	$a0,%hi(g_AudioManager+0x248)
/*     8b84:	3c058009 */ 	lui	$a1,%hi(g_AudioManager+0x260)
/*     8b88:	24a51828 */ 	addiu	$a1,$a1,%lo(g_AudioManager+0x260)
/*     8b8c:	24841810 */ 	addiu	$a0,$a0,%lo(g_AudioManager+0x248)
/*     8b90:	0c0120d0 */ 	jal	osCreateMesgQueue
/*     8b94:	24060008 */ 	addiu	$a2,$zero,0x8
/*     8b98:	92af0000 */ 	lbu	$t7,0x0($s5)
/*     8b9c:	3c128009 */ 	lui	$s2,%hi(var800918ec)
/*     8ba0:	265218ec */ 	addiu	$s2,$s2,%lo(var800918ec)
/*     8ba4:	240e07d0 */ 	addiu	$t6,$zero,0x7d0
/*     8ba8:	168f0003 */ 	bne	$s4,$t7,.L00008bb8
/*     8bac:	ae4e0000 */ 	sw	$t6,0x0($s2)
/*     8bb0:	000ec843 */ 	sra	$t9,$t6,0x1
/*     8bb4:	ae590000 */ 	sw	$t9,0x0($s2)
.L00008bb8:
/*     8bb8:	3c108009 */ 	lui	$s0,%hi(g_AudioManager)
/*     8bbc:	3c138009 */ 	lui	$s3,%hi(g_AudioManager+0x8)
/*     8bc0:	3c118009 */ 	lui	$s1,%hi(var800951f0)
/*     8bc4:	263151f0 */ 	addiu	$s1,$s1,%lo(var800951f0)
/*     8bc8:	267315d0 */ 	addiu	$s3,$s3,%lo(g_AudioManager+0x8)
/*     8bcc:	261015c8 */ 	addiu	$s0,$s0,%lo(g_AudioManager)
.L00008bd0:
/*     8bd0:	8e480000 */ 	lw	$t0,0x0($s2)
/*     8bd4:	00002025 */ 	or	$a0,$zero,$zero
/*     8bd8:	00002825 */ 	or	$a1,$zero,$zero
/*     8bdc:	000848c0 */ 	sll	$t1,$t0,0x3
/*     8be0:	afa90010 */ 	sw	$t1,0x10($sp)
/*     8be4:	02203025 */ 	or	$a2,$s1,$zero
/*     8be8:	0c00bec5 */ 	jal	func0002fb14
/*     8bec:	02803825 */ 	or	$a3,$s4,$zero
/*     8bf0:	26100004 */ 	addiu	$s0,$s0,0x4
/*     8bf4:	0213082b */ 	sltu	$at,$s0,$s3
/*     8bf8:	1420fff5 */ 	bnez	$at,.L00008bd0
/*     8bfc:	ae02fffc */ 	sw	$v0,-0x4($s0)
/*     8c00:	3c108009 */ 	lui	$s0,%hi(g_AudioManager)
/*     8c04:	3c128009 */ 	lui	$s2,%hi(g_AudioManager+0x0c)
/*     8c08:	265215d4 */ 	addiu	$s2,$s2,%lo(g_AudioManager+0x0c)
/*     8c0c:	261015c8 */ 	addiu	$s0,$s0,%lo(g_AudioManager)
.L00008c10:
/*     8c10:	240a0060 */ 	addiu	$t2,$zero,0x60
/*     8c14:	afaa0010 */ 	sw	$t2,0x10($sp)
/*     8c18:	00002025 */ 	or	$a0,$zero,$zero
/*     8c1c:	00002825 */ 	or	$a1,$zero,$zero
/*     8c20:	02203025 */ 	or	$a2,$s1,$zero
/*     8c24:	0c00bec5 */ 	jal	func0002fb14
/*     8c28:	02803825 */ 	or	$a3,$s4,$zero
/*     8c2c:	ae020008 */ 	sw	$v0,0x8($s0)
/*     8c30:	a4400004 */ 	sh	$zero,0x4($v0)
/*     8c34:	240b0c00 */ 	addiu	$t3,$zero,0xc00
/*     8c38:	afab0010 */ 	sw	$t3,0x10($sp)
/*     8c3c:	00002025 */ 	or	$a0,$zero,$zero
/*     8c40:	00002825 */ 	or	$a1,$zero,$zero
/*     8c44:	02203025 */ 	or	$a2,$s1,$zero
/*     8c48:	0c00bec5 */ 	jal	func0002fb14
/*     8c4c:	02803825 */ 	or	$a3,$s4,$zero
/*     8c50:	8e0c0008 */ 	lw	$t4,0x8($s0)
/*     8c54:	26100004 */ 	addiu	$s0,$s0,0x4
/*     8c58:	0212082b */ 	sltu	$at,$s0,$s2
/*     8c5c:	1420ffec */ 	bnez	$at,.L00008c10
/*     8c60:	ad820000 */ 	sw	$v0,0x0($t4)
/*     8c64:	3c0e8006 */ 	lui	$t6,%hi(var8005cf98)
/*     8c68:	25cecf98 */ 	addiu	$t6,$t6,%lo(var8005cf98)
/*     8c6c:	27a201c0 */ 	addiu	$v0,$sp,0x1c0
/*     8c70:	27a30090 */ 	addiu	$v1,$sp,0x90
/*     8c74:	27a50198 */ 	addiu	$a1,$sp,0x198
/*     8c78:	27a60068 */ 	addiu	$a2,$sp,0x68
/*     8c7c:	25d80024 */ 	addiu	$t8,$t6,0x24
/*     8c80:	27ad0590 */ 	addiu	$t5,$sp,0x590
.L00008c84:
/*     8c84:	8dc10000 */ 	lw	$at,0x0($t6)
/*     8c88:	25ce000c */ 	addiu	$t6,$t6,0xc
/*     8c8c:	25ad000c */ 	addiu	$t5,$t5,0xc
/*     8c90:	ada1fff4 */ 	sw	$at,-0xc($t5)
/*     8c94:	8dc1fff8 */ 	lw	$at,-0x8($t6)
/*     8c98:	ada1fff8 */ 	sw	$at,-0x8($t5)
/*     8c9c:	8dc1fffc */ 	lw	$at,-0x4($t6)
/*     8ca0:	15d8fff8 */ 	bne	$t6,$t8,.L00008c84
/*     8ca4:	ada1fffc */ 	sw	$at,-0x4($t5)
/*     8ca8:	8dc10000 */ 	lw	$at,0x0($t6)
/*     8cac:	3c088006 */ 	lui	$t0,%hi(var8005cfc0)
/*     8cb0:	2508cfc0 */ 	addiu	$t0,$t0,%lo(var8005cfc0)
/*     8cb4:	250a0024 */ 	addiu	$t2,$t0,0x24
/*     8cb8:	27b90568 */ 	addiu	$t9,$sp,0x568
/*     8cbc:	ada10000 */ 	sw	$at,0x0($t5)
.L00008cc0:
/*     8cc0:	8d010000 */ 	lw	$at,0x0($t0)
/*     8cc4:	2508000c */ 	addiu	$t0,$t0,0xc
/*     8cc8:	2739000c */ 	addiu	$t9,$t9,0xc
/*     8ccc:	af21fff4 */ 	sw	$at,-0xc($t9)
/*     8cd0:	8d01fff8 */ 	lw	$at,-0x8($t0)
/*     8cd4:	af21fff8 */ 	sw	$at,-0x8($t9)
/*     8cd8:	8d01fffc */ 	lw	$at,-0x4($t0)
/*     8cdc:	150afff8 */ 	bne	$t0,$t2,.L00008cc0
/*     8ce0:	af21fffc */ 	sw	$at,-0x4($t9)
/*     8ce4:	8d010000 */ 	lw	$at,0x0($t0)
/*     8ce8:	3c0c8006 */ 	lui	$t4,%hi(var8005cfe8)
/*     8cec:	258ccfe8 */ 	addiu	$t4,$t4,%lo(var8005cfe8)
/*     8cf0:	25980024 */ 	addiu	$t8,$t4,0x24
/*     8cf4:	27ab0540 */ 	addiu	$t3,$sp,0x540
/*     8cf8:	af210000 */ 	sw	$at,0x0($t9)
.L00008cfc:
/*     8cfc:	8d810000 */ 	lw	$at,0x0($t4)
/*     8d00:	258c000c */ 	addiu	$t4,$t4,0xc
/*     8d04:	256b000c */ 	addiu	$t3,$t3,0xc
/*     8d08:	ad61fff4 */ 	sw	$at,-0xc($t3)
/*     8d0c:	8d81fff8 */ 	lw	$at,-0x8($t4)
/*     8d10:	ad61fff8 */ 	sw	$at,-0x8($t3)
/*     8d14:	8d81fffc */ 	lw	$at,-0x4($t4)
/*     8d18:	1598fff8 */ 	bne	$t4,$t8,.L00008cfc
/*     8d1c:	ad61fffc */ 	sw	$at,-0x4($t3)
/*     8d20:	8d810000 */ 	lw	$at,0x0($t4)
/*     8d24:	3c0d8006 */ 	lui	$t5,%hi(var8005d010)
/*     8d28:	25add010 */ 	addiu	$t5,$t5,%lo(var8005d010)
/*     8d2c:	25aa00c0 */ 	addiu	$t2,$t5,0xc0
/*     8d30:	27ae0478 */ 	addiu	$t6,$sp,0x478
/*     8d34:	ad610000 */ 	sw	$at,0x0($t3)
.L00008d38:
/*     8d38:	8da10000 */ 	lw	$at,0x0($t5)
/*     8d3c:	25ad000c */ 	addiu	$t5,$t5,0xc
/*     8d40:	25ce000c */ 	addiu	$t6,$t6,0xc
/*     8d44:	adc1fff4 */ 	sw	$at,-0xc($t6)
/*     8d48:	8da1fff8 */ 	lw	$at,-0x8($t5)
/*     8d4c:	adc1fff8 */ 	sw	$at,-0x8($t6)
/*     8d50:	8da1fffc */ 	lw	$at,-0x4($t5)
/*     8d54:	15aafff8 */ 	bne	$t5,$t2,.L00008d38
/*     8d58:	adc1fffc */ 	sw	$at,-0x4($t6)
/*     8d5c:	8da10000 */ 	lw	$at,0x0($t5)
/*     8d60:	8daa0004 */ 	lw	$t2,0x4($t5)
/*     8d64:	3c198006 */ 	lui	$t9,%hi(var8005d0d8)
/*     8d68:	2739d0d8 */ 	addiu	$t9,$t9,%lo(var8005d0d8)
/*     8d6c:	27380048 */ 	addiu	$t8,$t9,0x48
/*     8d70:	27a80430 */ 	addiu	$t0,$sp,0x430
/*     8d74:	adc10000 */ 	sw	$at,0x0($t6)
/*     8d78:	adca0004 */ 	sw	$t2,0x4($t6)
.L00008d7c:
/*     8d7c:	8f210000 */ 	lw	$at,0x0($t9)
/*     8d80:	2739000c */ 	addiu	$t9,$t9,0xc
/*     8d84:	2508000c */ 	addiu	$t0,$t0,0xc
/*     8d88:	ad01fff4 */ 	sw	$at,-0xc($t0)
/*     8d8c:	8f21fff8 */ 	lw	$at,-0x8($t9)
/*     8d90:	ad01fff8 */ 	sw	$at,-0x8($t0)
/*     8d94:	8f21fffc */ 	lw	$at,-0x4($t9)
/*     8d98:	1738fff8 */ 	bne	$t9,$t8,.L00008d7c
/*     8d9c:	ad01fffc */ 	sw	$at,-0x4($t0)
/*     8da0:	3c0b8006 */ 	lui	$t3,%hi(var8005d120)
/*     8da4:	256bd120 */ 	addiu	$t3,$t3,%lo(var8005d120)
/*     8da8:	256a0060 */ 	addiu	$t2,$t3,0x60
/*     8dac:	27ac03c8 */ 	addiu	$t4,$sp,0x3c8
.L00008db0:
/*     8db0:	8d610000 */ 	lw	$at,0x0($t3)
/*     8db4:	256b000c */ 	addiu	$t3,$t3,0xc
/*     8db8:	258c000c */ 	addiu	$t4,$t4,0xc
/*     8dbc:	ad81fff4 */ 	sw	$at,-0xc($t4)
/*     8dc0:	8d61fff8 */ 	lw	$at,-0x8($t3)
/*     8dc4:	ad81fff8 */ 	sw	$at,-0x8($t4)
/*     8dc8:	8d61fffc */ 	lw	$at,-0x4($t3)
/*     8dcc:	156afff8 */ 	bne	$t3,$t2,.L00008db0
/*     8dd0:	ad81fffc */ 	sw	$at,-0x4($t4)
/*     8dd4:	8d610000 */ 	lw	$at,0x0($t3)
/*     8dd8:	8d6a0004 */ 	lw	$t2,0x4($t3)
/*     8ddc:	3c0e8006 */ 	lui	$t6,%hi(var8005d188)
/*     8de0:	25ced188 */ 	addiu	$t6,$t6,%lo(var8005d188)
/*     8de4:	25d80060 */ 	addiu	$t8,$t6,0x60
/*     8de8:	27ad0360 */ 	addiu	$t5,$sp,0x360
/*     8dec:	ad810000 */ 	sw	$at,0x0($t4)
/*     8df0:	ad8a0004 */ 	sw	$t2,0x4($t4)
.L00008df4:
/*     8df4:	8dc10000 */ 	lw	$at,0x0($t6)
/*     8df8:	25ce000c */ 	addiu	$t6,$t6,0xc
/*     8dfc:	25ad000c */ 	addiu	$t5,$t5,0xc
/*     8e00:	ada1fff4 */ 	sw	$at,-0xc($t5)
/*     8e04:	8dc1fff8 */ 	lw	$at,-0x8($t6)
/*     8e08:	ada1fff8 */ 	sw	$at,-0x8($t5)
/*     8e0c:	8dc1fffc */ 	lw	$at,-0x4($t6)
/*     8e10:	15d8fff8 */ 	bne	$t6,$t8,.L00008df4
/*     8e14:	ada1fffc */ 	sw	$at,-0x4($t5)
/*     8e18:	8dc10000 */ 	lw	$at,0x0($t6)
/*     8e1c:	8dd80004 */ 	lw	$t8,0x4($t6)
/*     8e20:	3c088006 */ 	lui	$t0,%hi(var8005d1f0)
/*     8e24:	2508d1f0 */ 	addiu	$t0,$t0,%lo(var8005d1f0)
/*     8e28:	250a0060 */ 	addiu	$t2,$t0,0x60
/*     8e2c:	27b902f8 */ 	addiu	$t9,$sp,0x2f8
/*     8e30:	ada10000 */ 	sw	$at,0x0($t5)
/*     8e34:	adb80004 */ 	sw	$t8,0x4($t5)
.L00008e38:
/*     8e38:	8d010000 */ 	lw	$at,0x0($t0)
/*     8e3c:	2508000c */ 	addiu	$t0,$t0,0xc
/*     8e40:	2739000c */ 	addiu	$t9,$t9,0xc
/*     8e44:	af21fff4 */ 	sw	$at,-0xc($t9)
/*     8e48:	8d01fff8 */ 	lw	$at,-0x8($t0)
/*     8e4c:	af21fff8 */ 	sw	$at,-0x8($t9)
/*     8e50:	8d01fffc */ 	lw	$at,-0x4($t0)
/*     8e54:	150afff8 */ 	bne	$t0,$t2,.L00008e38
/*     8e58:	af21fffc */ 	sw	$at,-0x4($t9)
/*     8e5c:	8d010000 */ 	lw	$at,0x0($t0)
/*     8e60:	8d0a0004 */ 	lw	$t2,0x4($t0)
/*     8e64:	3c0c8006 */ 	lui	$t4,%hi(var8005d258)
/*     8e68:	258cd258 */ 	addiu	$t4,$t4,%lo(var8005d258)
/*     8e6c:	25980084 */ 	addiu	$t8,$t4,0x84
/*     8e70:	27ab0270 */ 	addiu	$t3,$sp,0x270
/*     8e74:	af210000 */ 	sw	$at,0x0($t9)
/*     8e78:	af2a0004 */ 	sw	$t2,0x4($t9)
.L00008e7c:
/*     8e7c:	8d810000 */ 	lw	$at,0x0($t4)
/*     8e80:	258c000c */ 	addiu	$t4,$t4,0xc
/*     8e84:	256b000c */ 	addiu	$t3,$t3,0xc
/*     8e88:	ad61fff4 */ 	sw	$at,-0xc($t3)
/*     8e8c:	8d81fff8 */ 	lw	$at,-0x8($t4)
/*     8e90:	ad61fff8 */ 	sw	$at,-0x8($t3)
/*     8e94:	8d81fffc */ 	lw	$at,-0x4($t4)
/*     8e98:	1598fff8 */ 	bne	$t4,$t8,.L00008e7c
/*     8e9c:	ad61fffc */ 	sw	$at,-0x4($t3)
/*     8ea0:	8d810000 */ 	lw	$at,0x0($t4)
/*     8ea4:	3c0d8006 */ 	lui	$t5,%hi(var8005d2e0)
/*     8ea8:	25add2e0 */ 	addiu	$t5,$t5,%lo(var8005d2e0)
/*     8eac:	25aa0024 */ 	addiu	$t2,$t5,0x24
/*     8eb0:	27ae0248 */ 	addiu	$t6,$sp,0x248
/*     8eb4:	ad610000 */ 	sw	$at,0x0($t3)
.L00008eb8:
/*     8eb8:	8da10000 */ 	lw	$at,0x0($t5)
/*     8ebc:	25ad000c */ 	addiu	$t5,$t5,0xc
/*     8ec0:	25ce000c */ 	addiu	$t6,$t6,0xc
/*     8ec4:	adc1fff4 */ 	sw	$at,-0xc($t6)
/*     8ec8:	8da1fff8 */ 	lw	$at,-0x8($t5)
/*     8ecc:	adc1fff8 */ 	sw	$at,-0x8($t6)
/*     8ed0:	8da1fffc */ 	lw	$at,-0x4($t5)
/*     8ed4:	15aafff8 */ 	bne	$t5,$t2,.L00008eb8
/*     8ed8:	adc1fffc */ 	sw	$at,-0x4($t6)
/*     8edc:	8da10000 */ 	lw	$at,0x0($t5)
/*     8ee0:	3c088006 */ 	lui	$t0,%hi(var8005d308)
/*     8ee4:	2508d308 */ 	addiu	$t0,$t0,%lo(var8005d308)
/*     8ee8:	250f0084 */ 	addiu	$t7,$t0,0x84
/*     8eec:	0040c025 */ 	or	$t8,$v0,$zero
/*     8ef0:	adc10000 */ 	sw	$at,0x0($t6)
.L00008ef4:
/*     8ef4:	8d010000 */ 	lw	$at,0x0($t0)
/*     8ef8:	2508000c */ 	addiu	$t0,$t0,0xc
/*     8efc:	2718000c */ 	addiu	$t8,$t8,0xc
/*     8f00:	af01fff4 */ 	sw	$at,-0xc($t8)
/*     8f04:	8d01fff8 */ 	lw	$at,-0x8($t0)
/*     8f08:	af01fff8 */ 	sw	$at,-0x8($t8)
/*     8f0c:	8d01fffc */ 	lw	$at,-0x4($t0)
/*     8f10:	150ffff8 */ 	bne	$t0,$t7,.L00008ef4
/*     8f14:	af01fffc */ 	sw	$at,-0x4($t8)
/*     8f18:	8d010000 */ 	lw	$at,0x0($t0)
/*     8f1c:	3c0c8006 */ 	lui	$t4,%hi(var8005d390)
/*     8f20:	258cd390 */ 	addiu	$t4,$t4,%lo(var8005d390)
/*     8f24:	25890024 */ 	addiu	$t1,$t4,0x24
/*     8f28:	00a05025 */ 	or	$t2,$a1,$zero
/*     8f2c:	af010000 */ 	sw	$at,0x0($t8)
.L00008f30:
/*     8f30:	8d810000 */ 	lw	$at,0x0($t4)
/*     8f34:	258c000c */ 	addiu	$t4,$t4,0xc
/*     8f38:	254a000c */ 	addiu	$t2,$t2,0xc
/*     8f3c:	ad41fff4 */ 	sw	$at,-0xc($t2)
/*     8f40:	8d81fff8 */ 	lw	$at,-0x8($t4)
/*     8f44:	ad41fff8 */ 	sw	$at,-0x8($t2)
/*     8f48:	8d81fffc */ 	lw	$at,-0x4($t4)
/*     8f4c:	1589fff8 */ 	bne	$t4,$t1,.L00008f30
/*     8f50:	ad41fffc */ 	sw	$at,-0x4($t2)
/*     8f54:	8d810000 */ 	lw	$at,0x0($t4)
/*     8f58:	3c0d8006 */ 	lui	$t5,%hi(var8005d3b8)
/*     8f5c:	25add3b8 */ 	addiu	$t5,$t5,%lo(var8005d3b8)
/*     8f60:	25b90108 */ 	addiu	$t9,$t5,0x108
/*     8f64:	00607825 */ 	or	$t7,$v1,$zero
/*     8f68:	ad410000 */ 	sw	$at,0x0($t2)
.L00008f6c:
/*     8f6c:	8da10000 */ 	lw	$at,0x0($t5)
/*     8f70:	25ad000c */ 	addiu	$t5,$t5,0xc
/*     8f74:	25ef000c */ 	addiu	$t7,$t7,0xc
/*     8f78:	ade1fff4 */ 	sw	$at,-0xc($t7)
/*     8f7c:	8da1fff8 */ 	lw	$at,-0x8($t5)
/*     8f80:	ade1fff8 */ 	sw	$at,-0x8($t7)
/*     8f84:	8da1fffc */ 	lw	$at,-0x4($t5)
/*     8f88:	15b9fff8 */ 	bne	$t5,$t9,.L00008f6c
/*     8f8c:	ade1fffc */ 	sw	$at,-0x4($t7)
/*     8f90:	3c088006 */ 	lui	$t0,%hi(var8005d4c0)
/*     8f94:	2508d4c0 */ 	addiu	$t0,$t0,%lo(var8005d4c0)
/*     8f98:	250b0024 */ 	addiu	$t3,$t0,0x24
/*     8f9c:	00c04825 */ 	or	$t1,$a2,$zero
.L00008fa0:
/*     8fa0:	8d010000 */ 	lw	$at,0x0($t0)
/*     8fa4:	2508000c */ 	addiu	$t0,$t0,0xc
/*     8fa8:	2529000c */ 	addiu	$t1,$t1,0xc
/*     8fac:	ad21fff4 */ 	sw	$at,-0xc($t1)
/*     8fb0:	8d01fff8 */ 	lw	$at,-0x8($t0)
/*     8fb4:	ad21fff8 */ 	sw	$at,-0x8($t1)
/*     8fb8:	8d01fffc */ 	lw	$at,-0x4($t0)
/*     8fbc:	150bfff8 */ 	bne	$t0,$t3,.L00008fa0
/*     8fc0:	ad21fffc */ 	sw	$at,-0x4($t1)
/*     8fc4:	8d010000 */ 	lw	$at,0x0($t0)
/*     8fc8:	3c0a8006 */ 	lui	$t2,%hi(var8005d4e8)
/*     8fcc:	254ad4e8 */ 	addiu	$t2,$t2,%lo(var8005d4e8)
/*     8fd0:	25590024 */ 	addiu	$t9,$t2,0x24
/*     8fd4:	27ac0040 */ 	addiu	$t4,$sp,0x40
/*     8fd8:	ad210000 */ 	sw	$at,0x0($t1)
.L00008fdc:
/*     8fdc:	8d410000 */ 	lw	$at,0x0($t2)
/*     8fe0:	254a000c */ 	addiu	$t2,$t2,0xc
/*     8fe4:	258c000c */ 	addiu	$t4,$t4,0xc
/*     8fe8:	ad81fff4 */ 	sw	$at,-0xc($t4)
/*     8fec:	8d41fff8 */ 	lw	$at,-0x8($t2)
/*     8ff0:	ad81fff8 */ 	sw	$at,-0x8($t4)
/*     8ff4:	8d41fffc */ 	lw	$at,-0x4($t2)
/*     8ff8:	1559fff8 */ 	bne	$t2,$t9,.L00008fdc
/*     8ffc:	ad81fffc */ 	sw	$at,-0x4($t4)
/*     9000:	8d410000 */ 	lw	$at,0x0($t2)
/*     9004:	ad810000 */ 	sw	$at,0x0($t4)
/*     9008:	92ad0000 */ 	lbu	$t5,0x0($s5)
/*     900c:	8fa705c0 */ 	lw	$a3,0x5c0($sp)
/*     9010:	568d0004 */ 	bnel	$s4,$t5,.L00009024
/*     9014:	8fa705c0 */ 	lw	$a3,0x5c0($sp)
/*     9018:	10000003 */ 	b	.L00009028
/*     901c:	ace20020 */ 	sw	$v0,0x20($a3)
/*     9020:	8fa705c0 */ 	lw	$a3,0x5c0($sp)
.L00009024:
/*     9024:	ace30020 */ 	sw	$v1,0x20($a3)
.L00009028:
/*     9028:	3c048009 */ 	lui	$a0,%hi(var80094ea8)
/*     902c:	24844ea8 */ 	addiu	$a0,$a0,%lo(var80094ea8)
/*     9030:	8c820000 */ 	lw	$v0,0x0($a0)
/*     9034:	28410002 */ 	slti	$at,$v0,0x2
/*     9038:	14200010 */ 	bnez	$at,.L0000907c
/*     903c:	28410002 */ 	slti	$at,$v0,0x2
/*     9040:	1420000e */ 	bnez	$at,.L0000907c
/*     9044:	02801825 */ 	or	$v1,$s4,$zero
/*     9048:	24e20004 */ 	addiu	$v0,$a3,0x4
/*     904c:	92b80000 */ 	lbu	$t8,0x0($s5)
.L00009050:
/*     9050:	56980004 */ 	bnel	$s4,$t8,.L00009064
/*     9054:	ac460020 */ 	sw	$a2,0x20($v0)
/*     9058:	10000002 */ 	b	.L00009064
/*     905c:	ac450020 */ 	sw	$a1,0x20($v0)
/*     9060:	ac460020 */ 	sw	$a2,0x20($v0)
.L00009064:
/*     9064:	8c8b0000 */ 	lw	$t3,0x0($a0)
/*     9068:	24630001 */ 	addiu	$v1,$v1,0x1
/*     906c:	24420004 */ 	addiu	$v0,$v0,0x4
/*     9070:	006b082a */ 	slt	$at,$v1,$t3
/*     9074:	5420fff6 */ 	bnezl	$at,.L00009050
/*     9078:	92b80000 */ 	lbu	$t8,0x0($s5)
.L0000907c:
/*     907c:	3c048009 */ 	lui	$a0,%hi(g_AudioManager+0x2b8)
/*     9080:	24841880 */ 	addiu	$a0,$a0,%lo(g_AudioManager+0x2b8)
/*     9084:	0c00bee8 */ 	jal	func0002fba0
/*     9088:	00e02825 */ 	or	$a1,$a3,$zero
/*     908c:	00002025 */ 	or	$a0,$zero,$zero
/*     9090:	0c00c2ff */ 	jal	func00030bfc
/*     9094:	2405003c */ 	addiu	$a1,$zero,0x3c
/*     9098:	3c088009 */ 	lui	$t0,%hi(g_AudioSp)
/*     909c:	8d0818f0 */ 	lw	$t0,%lo(g_AudioSp)($t0)
/*     90a0:	3c048009 */ 	lui	$a0,%hi(g_AudioManager+0x18)
/*     90a4:	3c067001 */ 	lui	$a2,%hi(amgrMain)
/*     90a8:	24090014 */ 	addiu	$t1,$zero,0x14
/*     90ac:	afa90014 */ 	sw	$t1,0x14($sp)
/*     90b0:	24c69154 */ 	addiu	$a2,$a2,%lo(amgrMain)
/*     90b4:	248415e0 */ 	addiu	$a0,$a0,%lo(g_AudioManager+0x18)
/*     90b8:	24050004 */ 	addiu	$a1,$zero,0x4
/*     90bc:	00003825 */ 	or	$a3,$zero,$zero
/*     90c0:	0c000fb8 */ 	jal	osCreateThread
/*     90c4:	afa80010 */ 	sw	$t0,0x10($sp)
/*     90c8:	8fbf0034 */ 	lw	$ra,0x34($sp)
/*     90cc:	8fb0001c */ 	lw	$s0,0x1c($sp)
/*     90d0:	8fb10020 */ 	lw	$s1,0x20($sp)
/*     90d4:	8fb20024 */ 	lw	$s2,0x24($sp)
/*     90d8:	8fb30028 */ 	lw	$s3,0x28($sp)
/*     90dc:	8fb4002c */ 	lw	$s4,0x2c($sp)
/*     90e0:	8fb50030 */ 	lw	$s5,0x30($sp)
/*     90e4:	03e00008 */ 	jr	$ra
/*     90e8:	27bd05c0 */ 	addiu	$sp,$sp,0x5c0
);

void amgrStartThread(void)
{
	osStartThread(&g_AudioManager.thread);
	g_AudioIsThreadRunning = true;
}

GLOBAL_ASM(
glabel amgr00009118
/*     9118:	3c028009 */ 	lui	$v0,%hi(g_AudioManager+0x248)
/*     911c:	03e00008 */ 	jr	$ra
/*     9120:	24421810 */ 	addiu	$v0,$v0,%lo(g_AudioManager+0x248)
);

/**
 * This doesn't set g_AudioIsThreadRunning to false, but that's okay because
 * this is only called when resetting the console, and when that happens the
 * variable is likely reset too.
 */
void amgrStopThread(void)
{
	if (g_AudioIsThreadRunning) {
		osStopThread(&g_AudioManager.thread);
	}
}

GLOBAL_ASM(
glabel amgrMain
/*     9154:	27bdff90 */ 	addiu	$sp,$sp,-112
/*     9158:	3c078009 */ 	lui	$a3,%hi(g_Is4Mb)
/*     915c:	90e70af0 */ 	lbu	$a3,%lo(g_Is4Mb)($a3)
/*     9160:	afa40070 */ 	sw	$a0,0x70($sp)
/*     9164:	afbf003c */ 	sw	$ra,0x3c($sp)
/*     9168:	38ee0001 */ 	xori	$t6,$a3,0x1
/*     916c:	afb30024 */ 	sw	$s3,0x24($sp)
/*     9170:	afb20020 */ 	sw	$s2,0x20($sp)
/*     9174:	2dce0001 */ 	sltiu	$t6,$t6,0x1
/*     9178:	3c048009 */ 	lui	$a0,%hi(g_SchedThread)
/*     917c:	3c058009 */ 	lui	$a1,%hi(var800918d0)
/*     9180:	3c068009 */ 	lui	$a2,%hi(g_AudioManager+0x248)
/*     9184:	afbe0038 */ 	sw	$s8,0x38($sp)
/*     9188:	afb70034 */ 	sw	$s7,0x34($sp)
/*     918c:	afb60030 */ 	sw	$s6,0x30($sp)
/*     9190:	afb5002c */ 	sw	$s5,0x2c($sp)
/*     9194:	afb40028 */ 	sw	$s4,0x28($sp)
/*     9198:	afb1001c */ 	sw	$s1,0x1c($sp)
/*     919c:	afb00018 */ 	sw	$s0,0x18($sp)
/*     91a0:	00009025 */ 	or	$s2,$zero,$zero
/*     91a4:	00009825 */ 	or	$s3,$zero,$zero
/*     91a8:	afa00064 */ 	sw	$zero,0x64($sp)
/*     91ac:	afa00060 */ 	sw	$zero,0x60($sp)
/*     91b0:	24c61810 */ 	addiu	$a2,$a2,%lo(g_AudioManager+0x248)
/*     91b4:	24a518d0 */ 	addiu	$a1,$a1,%lo(var800918d0)
/*     91b8:	2484dbd0 */ 	addiu	$a0,$a0,%lo(g_SchedThread)
/*     91bc:	0c00078c */ 	jal	osScAddClient
/*     91c0:	2dc70001 */ 	sltiu	$a3,$t6,0x1
/*     91c4:	3c158009 */ 	lui	$s5,%hi(var80091590)
/*     91c8:	3c148009 */ 	lui	$s4,%hi(var80091588)
/*     91cc:	3c118009 */ 	lui	$s1,%hi(var80091568)
/*     91d0:	3c108009 */ 	lui	$s0,%hi(var80091580)
/*     91d4:	26101580 */ 	addiu	$s0,$s0,%lo(var80091580)
/*     91d8:	26311568 */ 	addiu	$s1,$s1,%lo(var80091568)
/*     91dc:	26941588 */ 	addiu	$s4,$s4,%lo(var80091588)
/*     91e0:	26b51590 */ 	addiu	$s5,$s5,%lo(var80091590)
/*     91e4:	241e0005 */ 	addiu	$s8,$zero,0x5
/*     91e8:	24170004 */ 	addiu	$s7,$zero,0x4
/*     91ec:	27b60064 */ 	addiu	$s6,$sp,0x64
.L000091f0:
/*     91f0:	3c048009 */ 	lui	$a0,%hi(g_AudioManager+0x248)
/*     91f4:	24841810 */ 	addiu	$a0,$a0,%lo(g_AudioManager+0x248)
/*     91f8:	02c02825 */ 	or	$a1,$s6,$zero
/*     91fc:	0c0121bc */ 	jal	osRecvMesg
/*     9200:	24060001 */ 	addiu	$a2,$zero,0x1
/*     9204:	8faf0064 */ 	lw	$t7,0x64($sp)
/*     9208:	85e70000 */ 	lh	$a3,0x0($t7)
/*     920c:	10f70007 */ 	beq	$a3,$s7,.L0000922c
/*     9210:	00000000 */ 	nop
/*     9214:	10fe0078 */ 	beq	$a3,$s8,.L000093f8
/*     9218:	2401000a */ 	addiu	$at,$zero,0xa
/*     921c:	50e10079 */ 	beql	$a3,$at,.L00009404
/*     9220:	24130001 */ 	addiu	$s3,$zero,0x1
/*     9224:	10000077 */ 	b	.L00009404
/*     9228:	00000000 */ 	nop
.L0000922c:
/*     922c:	0c012448 */ 	jal	osGetTime
/*     9230:	00000000 */ 	nop
/*     9234:	ae820000 */ 	sw	$v0,0x0($s4)
/*     9238:	ae830004 */ 	sw	$v1,0x4($s4)
/*     923c:	0c0026a8 */ 	jal	func00009aa0
/*     9240:	3c040003 */ 	lui	$a0,0x3
/*     9244:	3c188009 */ 	lui	$t8,%hi(var80092828)
/*     9248:	8f182828 */ 	lw	$t8,%lo(var80092828)($t8)
/*     924c:	24010003 */ 	addiu	$at,$zero,0x3
/*     9250:	3c048009 */ 	lui	$a0,%hi(g_AudioManager+0x8)
/*     9254:	0301001b */ 	divu	$zero,$t8,$at
/*     9258:	0000c810 */ 	mfhi	$t9
/*     925c:	00194080 */ 	sll	$t0,$t9,0x2
/*     9260:	00882021 */ 	addu	$a0,$a0,$t0
/*     9264:	8c8415d0 */ 	lw	$a0,%lo(g_AudioManager+0x8)($a0)
/*     9268:	0c002512 */ 	jal	amgrHandleFrameMsg
/*     926c:	8fa50060 */ 	lw	$a1,0x60($sp)
/*     9270:	0c002682 */ 	jal	func00009a08
/*     9274:	00000000 */ 	nop
/*     9278:	26520001 */ 	addiu	$s2,$s2,0x1
/*     927c:	0c0026a8 */ 	jal	func00009aa0
/*     9280:	3c040006 */ 	lui	$a0,0x6
/*     9284:	0c012448 */ 	jal	osGetTime
/*     9288:	00000000 */ 	nop
/*     928c:	8e8c0000 */ 	lw	$t4,0x0($s4)
/*     9290:	8e8d0004 */ 	lw	$t5,0x4($s4)
/*     9294:	aea20000 */ 	sw	$v0,0x0($s5)
/*     9298:	004c4023 */ 	subu	$t0,$v0,$t4
/*     929c:	006d082b */ 	sltu	$at,$v1,$t5
/*     92a0:	01014023 */ 	subu	$t0,$t0,$at
/*     92a4:	aea30004 */ 	sw	$v1,0x4($s5)
/*     92a8:	3c018009 */ 	lui	$at,%hi(var80091570+0x4)
/*     92ac:	006d4823 */ 	subu	$t1,$v1,$t5
/*     92b0:	ac291574 */ 	sw	$t1,%lo(var80091570+0x4)($at)
/*     92b4:	ac281570 */ 	sw	$t0,0x1570($at)
/*     92b8:	240100f0 */ 	addiu	$at,$zero,0xf0
/*     92bc:	0241001a */ 	div	$zero,$s2,$at
/*     92c0:	00005010 */ 	mfhi	$t2
/*     92c4:	afa90044 */ 	sw	$t1,0x44($sp)
/*     92c8:	afa80040 */ 	sw	$t0,0x40($sp)
/*     92cc:	afa20050 */ 	sw	$v0,0x50($sp)
/*     92d0:	afa30054 */ 	sw	$v1,0x54($sp)
/*     92d4:	afac0048 */ 	sw	$t4,0x48($sp)
/*     92d8:	1540001c */ 	bnez	$t2,.L0000934c
/*     92dc:	afad004c */ 	sw	$t5,0x4c($sp)
/*     92e0:	8e040000 */ 	lw	$a0,0x0($s0)
/*     92e4:	8e050004 */ 	lw	$a1,0x4($s0)
/*     92e8:	24060000 */ 	addiu	$a2,$zero,0x0
/*     92ec:	0c012b9a */ 	jal	__ull_div
/*     92f0:	240700f0 */ 	addiu	$a3,$zero,0xf0
/*     92f4:	3c018009 */ 	lui	$at,%hi(var80091578)
/*     92f8:	ac221578 */ 	sw	$v0,%lo(var80091578)($at)
/*     92fc:	ac23157c */ 	sw	$v1,0x157c($at)
/*     9300:	8e890004 */ 	lw	$t1,0x4($s4)
/*     9304:	8e880000 */ 	lw	$t0,0x0($s4)
/*     9308:	8eb90004 */ 	lw	$t9,0x4($s5)
/*     930c:	8eb80000 */ 	lw	$t8,0x0($s5)
/*     9310:	240c0000 */ 	addiu	$t4,$zero,0x0
/*     9314:	0329082b */ 	sltu	$at,$t9,$t1
/*     9318:	03085023 */ 	subu	$t2,$t8,$t0
/*     931c:	01415023 */ 	subu	$t2,$t2,$at
/*     9320:	240d0000 */ 	addiu	$t5,$zero,0x0
/*     9324:	240e0000 */ 	addiu	$t6,$zero,0x0
/*     9328:	240f0000 */ 	addiu	$t7,$zero,0x0
/*     932c:	03295823 */ 	subu	$t3,$t9,$t1
/*     9330:	afab0044 */ 	sw	$t3,0x44($sp)
/*     9334:	ae2f0004 */ 	sw	$t7,0x4($s1)
/*     9338:	ae2e0000 */ 	sw	$t6,0x0($s1)
/*     933c:	ae0d0004 */ 	sw	$t5,0x4($s0)
/*     9340:	afaa0040 */ 	sw	$t2,0x40($sp)
/*     9344:	10000011 */ 	b	.L0000938c
/*     9348:	ae0c0000 */ 	sw	$t4,0x0($s0)
.L0000934c:
/*     934c:	8e0d0004 */ 	lw	$t5,0x4($s0)
/*     9350:	8faf0054 */ 	lw	$t7,0x54($sp)
/*     9354:	8e0c0000 */ 	lw	$t4,0x0($s0)
/*     9358:	8fae0050 */ 	lw	$t6,0x50($sp)
/*     935c:	01afc821 */ 	addu	$t9,$t5,$t7
/*     9360:	8fa80048 */ 	lw	$t0,0x48($sp)
/*     9364:	8fa9004c */ 	lw	$t1,0x4c($sp)
/*     9368:	032f082b */ 	sltu	$at,$t9,$t7
/*     936c:	002cc021 */ 	addu	$t8,$at,$t4
/*     9370:	030ec021 */ 	addu	$t8,$t8,$t6
/*     9374:	03085023 */ 	subu	$t2,$t8,$t0
/*     9378:	0329082b */ 	sltu	$at,$t9,$t1
/*     937c:	01415023 */ 	subu	$t2,$t2,$at
/*     9380:	03295823 */ 	subu	$t3,$t9,$t1
/*     9384:	ae0b0004 */ 	sw	$t3,0x4($s0)
/*     9388:	ae0a0000 */ 	sw	$t2,0x0($s0)
.L0000938c:
/*     938c:	8e2c0000 */ 	lw	$t4,0x0($s1)
/*     9390:	8fae0040 */ 	lw	$t6,0x40($sp)
/*     9394:	8e2d0004 */ 	lw	$t5,0x4($s1)
/*     9398:	8faf0044 */ 	lw	$t7,0x44($sp)
/*     939c:	01cc082b */ 	sltu	$at,$t6,$t4
/*     93a0:	14200008 */ 	bnez	$at,.L000093c4
/*     93a4:	3c188006 */ 	lui	$t8,%hi(var8005d514)
/*     93a8:	018e082b */ 	sltu	$at,$t4,$t6
/*     93ac:	14200003 */ 	bnez	$at,.L000093bc
/*     93b0:	01af082b */ 	sltu	$at,$t5,$t7
/*     93b4:	10200003 */ 	beqz	$at,.L000093c4
/*     93b8:	00000000 */ 	nop
.L000093bc:
/*     93bc:	ae2e0000 */ 	sw	$t6,0x0($s1)
/*     93c0:	ae2f0004 */ 	sw	$t7,0x4($s1)
.L000093c4:
/*     93c4:	8f18d514 */ 	lw	$t8,%lo(var8005d514)($t8)
/*     93c8:	3c048009 */ 	lui	$a0,%hi(g_AudioManager+0x280)
/*     93cc:	24841848 */ 	addiu	$a0,$a0,%lo(g_AudioManager+0x280)
/*     93d0:	17000003 */ 	bnez	$t8,.L000093e0
/*     93d4:	27a50060 */ 	addiu	$a1,$sp,0x60
/*     93d8:	0c0121bc */ 	jal	osRecvMesg
/*     93dc:	24060001 */ 	addiu	$a2,$zero,0x1
.L000093e0:
/*     93e0:	3c018006 */ 	lui	$at,%hi(var8005d514)
/*     93e4:	ac20d514 */ 	sw	$zero,%lo(var8005d514)($at)
/*     93e8:	0c002585 */ 	jal	amgrHandleDoneMsg
/*     93ec:	8fa40060 */ 	lw	$a0,0x60($sp)
/*     93f0:	10000004 */ 	b	.L00009404
/*     93f4:	00000000 */ 	nop
.L000093f8:
/*     93f8:	10000002 */ 	b	.L00009404
/*     93fc:	24130001 */ 	addiu	$s3,$zero,0x1
/*     9400:	24130001 */ 	addiu	$s3,$zero,0x1
.L00009404:
/*     9404:	1260ff7a */ 	beqz	$s3,.L000091f0
/*     9408:	00000000 */ 	nop
/*     940c:	3c048009 */ 	lui	$a0,%hi(g_AudioManager+0x2b8)
/*     9410:	0c00bf03 */ 	jal	alClose
/*     9414:	24841880 */ 	addiu	$a0,$a0,%lo(g_AudioManager+0x2b8)
/*     9418:	8fbf003c */ 	lw	$ra,0x3c($sp)
/*     941c:	8fb00018 */ 	lw	$s0,0x18($sp)
/*     9420:	8fb1001c */ 	lw	$s1,0x1c($sp)
/*     9424:	8fb20020 */ 	lw	$s2,0x20($sp)
/*     9428:	8fb30024 */ 	lw	$s3,0x24($sp)
/*     942c:	8fb40028 */ 	lw	$s4,0x28($sp)
/*     9430:	8fb5002c */ 	lw	$s5,0x2c($sp)
/*     9434:	8fb60030 */ 	lw	$s6,0x30($sp)
/*     9438:	8fb70034 */ 	lw	$s7,0x34($sp)
/*     943c:	8fbe0038 */ 	lw	$s8,0x38($sp)
/*     9440:	03e00008 */ 	jr	$ra
/*     9444:	27bd0070 */ 	addiu	$sp,$sp,0x70
);

// Mismatch: needs bss relocation
//void amgrMain(void *arg)
//{
//	s32 count = 0; // s2
//	bool done = false; // s3
//	s16 *msg = NULL; // 64
//	AudioInfo *info = NULL; // 60
//
//	static u32 var8005d514;
//	static u64 var80091570;
//	static u64 var80091578;
//
//	osScAddClient(&g_SchedThread, &var800918d0, &g_AudioManager.audioFrameMsgQ, (void *)!IS4MB());
//
//	while (!done) {
//		osRecvMesg(&g_AudioManager.audioFrameMsgQ, (OSMesg *) &msg, OS_MESG_BLOCK);
//
//		switch (*msg) {
//		case 4:
//			var80091588 = osGetTime();
//			func00009aa0(0x30000);
//			amgrHandleFrameMsg(var800915d0[var80092828 % 3], info);
//			func00009a08();
//
//			count++;
//			func00009aa0(0x60000);
//
//			var80091590 = osGetTime();
//			var80091570 = var80091590 - var80091588;
//
//			// 2d8
//			if (count % 240 == 0) {
//				var80091578 = var80091580 / 240;
//				var80091568 = 0;
//				var80091580 = 0;
//			} else {
//				// 34c
//				var80091580 = (var80091580 + var80091590) - var80091588;
//			}
//
//			if (var80091568 < var80091590 - var80091588) {
//				var80091568 = var80091590 - var80091588;
//			}
//
//			if (var8005d514 == 0) {
//				osRecvMesg(&g_AudioManager.audioReplyMsgQ, (OSMesg *) &info, OS_MESG_BLOCK);
//			}
//
//			var8005d514 = 0;
//			amgrHandleDoneMsg(info);
//			break;
//		case 5:
//			done = true;
//			break;
//		case 10:
//			done = true;
//			break;
//		}
//	}
//
//	alClose(&g_AudioManager.g);
//}

GLOBAL_ASM(
glabel amgrHandleFrameMsg
/*     9448:	3c068009 */ 	lui	$a2,%hi(g_AmgrCurrentCmdList)
/*     944c:	8cc618f4 */ 	lw	$a2,%lo(g_AmgrCurrentCmdList)($a2)
/*     9450:	27bdffd0 */ 	addiu	$sp,$sp,-48
/*     9454:	afb00018 */ 	sw	$s0,0x18($sp)
/*     9458:	00808025 */ 	or	$s0,$a0,$zero
/*     945c:	afbf001c */ 	sw	$ra,0x1c($sp)
/*     9460:	10c00007 */ 	beqz	$a2,.L00009480
/*     9464:	afa50034 */ 	sw	$a1,0x34($sp)
/*     9468:	3c048009 */ 	lui	$a0,%hi(g_SchedThread)
/*     946c:	3c018009 */ 	lui	$at,%hi(g_AmgrCurrentCmdList)
/*     9470:	ac2618f4 */ 	sw	$a2,%lo(g_AmgrCurrentCmdList)($at)
/*     9474:	2484dbd0 */ 	addiu	$a0,$a0,%lo(g_SchedThread)
/*     9478:	0c0007ea */ 	jal	__scHandleRetraceViaPri
/*     947c:	00c02825 */ 	or	$a1,$a2,$zero
.L00009480:
/*     9480:	0c00264f */ 	jal	amgrClearDmaBuffers
/*     9484:	00000000 */ 	nop
/*     9488:	3c198006 */ 	lui	$t9,%hi(var8005cf90)
/*     948c:	8f39cf90 */ 	lw	$t9,%lo(var8005cf90)($t9)
/*     9490:	3c0ea450 */ 	lui	$t6,0xa450
/*     9494:	3c098009 */ 	lui	$t1,%hi(g_AudioManager)
/*     9498:	00194080 */ 	sll	$t0,$t9,0x2
/*     949c:	8dcf0004 */ 	lw	$t7,0x4($t6)
/*     94a0:	01284821 */ 	addu	$t1,$t1,$t0
/*     94a4:	8d2915c8 */ 	lw	$t1,%lo(g_AudioManager)($t1)
/*     94a8:	000fc082 */ 	srl	$t8,$t7,0x2
/*     94ac:	afb8002c */ 	sw	$t8,0x2c($sp)
/*     94b0:	afa90024 */ 	sw	$t1,0x24($sp)
/*     94b4:	0c012d20 */ 	jal	osVirtualToPhysical
/*     94b8:	8e040000 */ 	lw	$a0,0x0($s0)
/*     94bc:	8fa30034 */ 	lw	$v1,0x34($sp)
/*     94c0:	00403025 */ 	or	$a2,$v0,$zero
/*     94c4:	50600009 */ 	beqzl	$v1,.L000094ec
/*     94c8:	8fab002c */ 	lw	$t3,0x2c($sp)
/*     94cc:	84650004 */ 	lh	$a1,0x4($v1)
/*     94d0:	8c640000 */ 	lw	$a0,0x0($v1)
/*     94d4:	afa20028 */ 	sw	$v0,0x28($sp)
/*     94d8:	00055080 */ 	sll	$t2,$a1,0x2
/*     94dc:	0c0138f0 */ 	jal	osAiSetNextBuffer
/*     94e0:	01402825 */ 	or	$a1,$t2,$zero
/*     94e4:	8fa60028 */ 	lw	$a2,0x28($sp)
/*     94e8:	8fab002c */ 	lw	$t3,0x2c($sp)
.L000094ec:
/*     94ec:	3c058009 */ 	lui	$a1,%hi(var800918e8)
/*     94f0:	3c038006 */ 	lui	$v1,%hi(var8005cf94)
/*     94f4:	2d6100f9 */ 	sltiu	$at,$t3,0xf9
/*     94f8:	1420000b */ 	bnez	$at,.L00009528
/*     94fc:	24a518e8 */ 	addiu	$a1,$a1,%lo(var800918e8)
/*     9500:	2463cf94 */ 	addiu	$v1,$v1,%lo(var8005cf94)
/*     9504:	906c0000 */ 	lbu	$t4,0x0($v1)
/*     9508:	3c0d8009 */ 	lui	$t5,%hi(var800918dc)
/*     950c:	15800006 */ 	bnez	$t4,.L00009528
/*     9510:	00000000 */ 	nop
/*     9514:	8dad18dc */ 	lw	$t5,%lo(var800918dc)($t5)
/*     9518:	240e0002 */ 	addiu	$t6,$zero,0x2
/*     951c:	a60d0004 */ 	sh	$t5,0x4($s0)
/*     9520:	1000000a */ 	b	.L0000954c
/*     9524:	a06e0000 */ 	sb	$t6,0x0($v1)
.L00009528:
/*     9528:	3c0f8009 */ 	lui	$t7,%hi(var800918e0)
/*     952c:	8def18e0 */ 	lw	$t7,%lo(var800918e0)($t7)
/*     9530:	3c038006 */ 	lui	$v1,%hi(var8005cf94)
/*     9534:	2463cf94 */ 	addiu	$v1,$v1,%lo(var8005cf94)
/*     9538:	a60f0004 */ 	sh	$t7,0x4($s0)
/*     953c:	90620000 */ 	lbu	$v0,0x0($v1)
/*     9540:	10400002 */ 	beqz	$v0,.L0000954c
/*     9544:	2458ffff */ 	addiu	$t8,$v0,-1
/*     9548:	a0780000 */ 	sb	$t8,0x0($v1)
.L0000954c:
/*     954c:	8fa40024 */ 	lw	$a0,0x24($sp)
/*     9550:	0c00c4b9 */ 	jal	alAudioFrame
/*     9554:	86070004 */ 	lh	$a3,0x4($s0)
/*     9558:	26060008 */ 	addiu	$a2,$s0,0x8
/*     955c:	3c038006 */ 	lui	$v1,%hi(rspbootTextStart)
/*     9560:	3c088006 */ 	lui	$t0,%hi(rspbootTextEnd)
/*     9564:	24639fe0 */ 	addiu	$v1,$v1,%lo(rspbootTextStart)
/*     9568:	24040002 */ 	addiu	$a0,$zero,0x2
/*     956c:	3c198009 */ 	lui	$t9,%hi(g_AudioManager+0x280)
/*     9570:	2508a0b0 */ 	addiu	$t0,$t0,%lo(rspbootTextEnd)
/*     9574:	3c0a8006 */ 	lui	$t2,%hi(aspMainTextStart)
/*     9578:	3c0b8009 */ 	lui	$t3,%hi(aspMainDataStart)
/*     957c:	27391848 */ 	addiu	$t9,$t9,%lo(g_AudioManager+0x280)
/*     9580:	01034823 */ 	subu	$t1,$t0,$v1
/*     9584:	254ab4d0 */ 	addiu	$t2,$t2,%lo(aspMainTextStart)
/*     9588:	256ba2d0 */ 	addiu	$t3,$t3,%lo(aspMainDataStart)
/*     958c:	240c1000 */ 	addiu	$t4,$zero,0x1000
/*     9590:	240d0800 */ 	addiu	$t5,$zero,0x800
/*     9594:	acc00000 */ 	sw	$zero,0x0($a2)
/*     9598:	acd90050 */ 	sw	$t9,0x50($a2)
/*     959c:	acd00054 */ 	sw	$s0,0x54($a2)
/*     95a0:	acc40008 */ 	sw	$a0,0x8($a2)
/*     95a4:	acc40010 */ 	sw	$a0,0x10($a2)
/*     95a8:	acc00014 */ 	sw	$zero,0x14($a2)
/*     95ac:	acc30018 */ 	sw	$v1,0x18($a2)
/*     95b0:	acc9001c */ 	sw	$t1,0x1c($a2)
/*     95b4:	acca0020 */ 	sw	$t2,0x20($a2)
/*     95b8:	accb0028 */ 	sw	$t3,0x28($a2)
/*     95bc:	accc0024 */ 	sw	$t4,0x24($a2)
/*     95c0:	accd002c */ 	sw	$t5,0x2c($a2)
/*     95c4:	8fae0024 */ 	lw	$t6,0x24($sp)
/*     95c8:	3c018009 */ 	lui	$at,%hi(g_AmgrCurrentCmdList)
/*     95cc:	acce0040 */ 	sw	$t6,0x40($a2)
/*     95d0:	8faf0024 */ 	lw	$t7,0x24($sp)
/*     95d4:	acc00048 */ 	sw	$zero,0x48($a2)
/*     95d8:	acc0004c */ 	sw	$zero,0x4c($a2)
/*     95dc:	004fc023 */ 	subu	$t8,$v0,$t7
/*     95e0:	0018c8c3 */ 	sra	$t9,$t8,0x3
/*     95e4:	001940c0 */ 	sll	$t0,$t9,0x3
/*     95e8:	3c028006 */ 	lui	$v0,%hi(var8005cf90)
/*     95ec:	acc80044 */ 	sw	$t0,0x44($a2)
/*     95f0:	2442cf90 */ 	addiu	$v0,$v0,%lo(var8005cf90)
/*     95f4:	8c490000 */ 	lw	$t1,0x0($v0)
/*     95f8:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*     95fc:	8fb00018 */ 	lw	$s0,0x18($sp)
/*     9600:	392a0001 */ 	xori	$t2,$t1,0x1
/*     9604:	ac4a0000 */ 	sw	$t2,0x0($v0)
/*     9608:	ac2618f4 */ 	sw	$a2,%lo(g_AmgrCurrentCmdList)($at)
/*     960c:	03e00008 */ 	jr	$ra
/*     9610:	27bd0030 */ 	addiu	$sp,$sp,0x30
);

// Mismatch:
// - Regalloc, likely relating to g_AmgrCurrentCmdList = g_AmgrCurrentCmdList
// - g_AmgrCurrentCmdList needs to be moved into this file
//void amgrHandleFrameMsg(struct audioinfo *info, struct audioinfo *previnfo)
//{
//	u32 somevalue;
//	s16 *outbuffer;
//	Acmd *datastart;
//	Acmd *cmd;
//	OSScTask *task;
//	static OSScTask *g_AmgrCurrentCmdList;
//
//	extern u32 vara4500004;
//	extern u8 rspbootTextStart;
//	extern u8 rspbootTextEnd;
//	extern u8 aspMainTextStart;
//	extern u8 aspMainDataStart;
//
//	if (g_AmgrCurrentCmdList) {
//		g_AmgrCurrentCmdList = g_AmgrCurrentCmdList;
//		__scHandleRetraceViaPri(&g_SchedThread, g_AmgrCurrentCmdList);
//	}
//
//	amgrClearDmaBuffers();
//
//	somevalue = vara4500004 / 4;
//	datastart = g_AudioManager.ACMDList[var8005cf90];
//	outbuffer = (s16 *) osVirtualToPhysical(info->data);
//
//	if (previnfo) {
//		osAiSetNextBuffer(previnfo->data, previnfo->framesamples * 4);
//	}
//
//	if (somevalue > 248 && var8005cf94 == 0) {
//		info->framesamples = var800918dc;
//		var8005cf94 = 2;
//	} else {
//		info->framesamples = var800918e0;
//
//		if (var8005cf94 != 0) {
//			var8005cf94--;
//		}
//	}
//
//	cmd = alAudioFrame(datastart, &var800918e8, outbuffer, info->framesamples);
//
//	task = &info->task;
//
//	task->next = NULL;
//	task->msgQ = &var80091848;
//	task->msg = info;
//	task->flags = OS_SC_NEEDS_RSP;
//	task->list.t.type = M_AUDTASK;
//	task->list.t.flags = 0;
//	task->list.t.ucode_boot = (u64 *) &rspbootTextStart;
//	task->list.t.ucode_boot_size = (u32) &rspbootTextEnd - (u32) &rspbootTextStart;
//	task->list.t.ucode = (u64 *) &aspMainTextStart;
//	task->list.t.ucode_data = (u64 *) &aspMainDataStart;
//	task->list.t.ucode_size = SP_UCODE_SIZE;
//	task->list.t.ucode_data_size = SP_UCODE_DATA_SIZE;
//	task->list.t.data_ptr = (u64 *) datastart;
//	task->list.t.data_size = (cmd - datastart) * sizeof(Acmd);
//	task->list.t.yield_data_ptr = NULL;
//	task->list.t.yield_data_size = 0;
//
//	var8005cf90 ^= 1;
//
//	g_AmgrCurrentCmdList = task;
//}

void amgrHandleDoneMsg(AudioInfo *info)
{
	static bool firsttime = true;

	if ((s32)osAiGetLength() >> 2 == 0 && firsttime == false) {
		firsttime = false;
	}
}
