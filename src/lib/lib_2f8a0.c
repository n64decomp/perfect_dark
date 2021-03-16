#include <ultra64.h>
#include "constants.h"
#include "types.h"
#include "data.h"
#include "bss.h"
#include "lib/memory.h"

u8 var8009ad70[0xb00];

u16 *var8005f040 = NULL;
u16 *var8005f044 = NULL;
u32 var8005f048 = 0x00000000;
u32 var8005f04c = 0x00000000;
u32 var8005f050 = 0x00000000;
u32 var8005f054 = 0x00000000;
u32 var8005f058 = 0x00000001;
u32 var8005f05c = 0x00000002;
u32 var8005f060 = 0x00000000;
u32 var8005f064 = 0x00000000;
u32 var8005f068 = 0x00000000;
u32 var8005f06c = 0x00001000;
u32 var8005f070 = 0x00000000;
u32 var8005f074 = 0x00000800;
u32 var8005f078 = (u32) &var8009a970;
u32 var8005f07c = 0x00000400;
u32 var8005f080 = 0x00000000;
u32 var8005f084 = 0x00000000;
u32 var8005f088 = 0x00000000;
u32 var8005f08c = 0x00000000;
u32 var8005f090 = 0x00000000;
u32 var8005f094 = 0x00000000;
u32 var8005f098 = 0x00000000;
u32 var8005f09c = 0x00000000;
u32 var8005f0a0 = 0x00000000;
u32 var8005f0a4 = 0x00000000;
u32 var8005f0a8 = 0x00000000;
u32 var8005f0ac = 0x00000000;
u32 var8005f0b0 = 0x00000000;
u32 var8005f0b4 = 0x00000000;
u32 var8005f0b8 = 0x00000001;
u32 var8005f0bc = 0x00000002;
u32 var8005f0c0 = 0x00000000;
u32 var8005f0c4 = 0x00000000;
u32 var8005f0c8 = 0x00000000;
u32 var8005f0cc = 0x00001000;
u32 var8005f0d0 = 0x00000000;
u32 var8005f0d4 = 0x00000800;
u32 var8005f0d8 = (u32) &var8009a970;
u32 var8005f0dc = 0x00000400;
u32 var8005f0e0 = 0x00000000;
u32 var8005f0e4 = 0x00000000;
u32 var8005f0e8 = 0x00000000;
u32 var8005f0ec = 0x00000000;
u32 var8005f0f0 = 0x00000000;
u32 var8005f0f4 = 0x00000000;
u32 var8005f0f8 = 0x00000000;
u32 var8005f0fc = 0x00000000;
u32 var8005f100 = 0x00000000;
u32 var8005f104 = 0x00000000;
u32 var8005f108 = (u32) &var8005f048;

GLOBAL_ASM(
glabel func0002f8a0
/*    2f8a0:	3c0e8009 */ 	lui	$t6,%hi(g_Is4Mb)
/*    2f8a4:	91ce0af0 */ 	lbu	$t6,%lo(g_Is4Mb)($t6)
/*    2f8a8:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*    2f8ac:	24010001 */ 	addiu	$at,$zero,0x1
/*    2f8b0:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    2f8b4:	15c10002 */ 	bne	$t6,$at,.L0002f8c0
/*    2f8b8:	3c040001 */ 	lui	$a0,0x1
/*    2f8bc:	34048000 */ 	dli	$a0,0x8000
.L0002f8c0:
/*    2f8c0:	24050006 */ 	addiu	$a1,$zero,0x6
/*    2f8c4:	0c0048f2 */ 	jal	malloc
/*    2f8c8:	afa4001c */ 	sw	$a0,0x1c($sp)
/*    2f8cc:	8fa4001c */ 	lw	$a0,0x1c($sp)
/*    2f8d0:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    2f8d4:	3c038006 */ 	lui	$v1,%hi(var8005f044)
/*    2f8d8:	2463f044 */ 	addiu	$v1,$v1,%lo(var8005f044)
/*    2f8dc:	ac620000 */ 	sw	$v0,0x0($v1)
/*    2f8e0:	3c018006 */ 	lui	$at,%hi(var8005f040)
/*    2f8e4:	0044c021 */ 	addu	$t8,$v0,$a0
/*    2f8e8:	ac38f040 */ 	sw	$t8,%lo(var8005f040)($at)
/*    2f8ec:	03e00008 */ 	jr	$ra
/*    2f8f0:	27bd0020 */ 	addiu	$sp,$sp,0x20
);

GLOBAL_ASM(
glabel func0002f8f4
/*    2f8f4:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*    2f8f8:	3c038006 */ 	lui	$v1,%hi(var8005f108)
/*    2f8fc:	2463f108 */ 	addiu	$v1,$v1,%lo(var8005f108)
/*    2f900:	afa60028 */ 	sw	$a2,0x28($sp)
/*    2f904:	8c660000 */ 	lw	$a2,0x0($v1)
/*    2f908:	3c028006 */ 	lui	$v0,%hi(rspbootTextStart)
/*    2f90c:	3c0e8006 */ 	lui	$t6,%hi(rspbootTextEnd)
/*    2f910:	24429fe0 */ 	addiu	$v0,$v0,%lo(rspbootTextStart)
/*    2f914:	25cea0b0 */ 	addiu	$t6,$t6,%lo(rspbootTextEnd)
/*    2f918:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    2f91c:	01c27823 */ 	subu	$t7,$t6,$v0
/*    2f920:	acc20018 */ 	sw	$v0,0x18($a2)
/*    2f924:	3c188006 */ 	lui	$t8,%hi(gspTextStart)
/*    2f928:	3c198009 */ 	lui	$t9,%hi(gspDataStart)
/*    2f92c:	accf001c */ 	sw	$t7,0x1c($a2)
/*    2f930:	24c20010 */ 	addiu	$v0,$a2,0x10
/*    2f934:	2718a0b0 */ 	addiu	$t8,$t8,%lo(gspTextStart)
/*    2f938:	27399ad0 */ 	addiu	$t9,$t9,%lo(gspDataStart)
/*    2f93c:	ac580010 */ 	sw	$t8,0x10($v0)
/*    2f940:	ac590018 */ 	sw	$t9,0x18($v0)
/*    2f944:	3c088006 */ 	lui	$t0,%hi(var8005f044)
/*    2f948:	8d08f044 */ 	lw	$t0,%lo(var8005f044)($t0)
/*    2f94c:	3c098006 */ 	lui	$t1,%hi(var8005f040)
/*    2f950:	00a45023 */ 	subu	$t2,$a1,$a0
/*    2f954:	ac480028 */ 	sw	$t0,0x28($v0)
/*    2f958:	8d29f040 */ 	lw	$t1,%lo(var8005f040)($t1)
/*    2f95c:	000a58c3 */ 	sra	$t3,$t2,0x3
/*    2f960:	3c0d800a */ 	lui	$t5,%hi(var8009ad70)
/*    2f964:	000b60c0 */ 	sll	$t4,$t3,0x3
/*    2f968:	25adad70 */ 	addiu	$t5,$t5,%lo(var8009ad70)
/*    2f96c:	240e0b00 */ 	addiu	$t6,$zero,0xb00
/*    2f970:	ac440030 */ 	sw	$a0,0x30($v0)
/*    2f974:	ac4c0034 */ 	sw	$t4,0x34($v0)
/*    2f978:	ac4d0038 */ 	sw	$t5,0x38($v0)
/*    2f97c:	ac4e003c */ 	sw	$t6,0x3c($v0)
/*    2f980:	ac49002c */ 	sw	$t1,0x2c($v0)
/*    2f984:	3c188009 */ 	lui	$t8,%hi(var8008db30)
/*    2f988:	240f0063 */ 	addiu	$t7,$zero,0x63
/*    2f98c:	2718db30 */ 	addiu	$t8,$t8,%lo(var8008db30)
/*    2f990:	acc00000 */ 	sw	$zero,0x0($a2)
/*    2f994:	accf0008 */ 	sw	$t7,0x8($a2)
/*    2f998:	acd80050 */ 	sw	$t8,0x50($a2)
/*    2f99c:	acc70054 */ 	sw	$a3,0x54($a2)
/*    2f9a0:	8c790000 */ 	lw	$t9,0x0($v1)
/*    2f9a4:	8f280058 */ 	lw	$t0,0x58($t9)
/*    2f9a8:	acc8000c */ 	sw	$t0,0xc($a2)
/*    2f9ac:	0c012048 */ 	jal	osWritebackDCacheAll
/*    2f9b0:	afa6001c */ 	sw	$a2,0x1c($sp)
/*    2f9b4:	3c048009 */ 	lui	$a0,%hi(g_SchedThread)
/*    2f9b8:	8fa5001c */ 	lw	$a1,0x1c($sp)
/*    2f9bc:	0c0007ea */ 	jal	__scHandleRetraceViaPri
/*    2f9c0:	2484dbd0 */ 	addiu	$a0,$a0,%lo(g_SchedThread)
/*    2f9c4:	3c028006 */ 	lui	$v0,%hi(var8005f108)
/*    2f9c8:	2442f108 */ 	addiu	$v0,$v0,%lo(var8005f108)
/*    2f9cc:	8c490000 */ 	lw	$t1,0x0($v0)
/*    2f9d0:	3c0a8006 */ 	lui	$t2,%hi(var8005f048)
/*    2f9d4:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    2f9d8:	254af048 */ 	addiu	$t2,$t2,%lo(var8005f048)
/*    2f9dc:	3c0c8006 */ 	lui	$t4,%hi(var8005f0a8)
/*    2f9e0:	258cf0a8 */ 	addiu	$t4,$t4,%lo(var8005f0a8)
/*    2f9e4:	012a5826 */ 	xor	$t3,$t1,$t2
/*    2f9e8:	016c6826 */ 	xor	$t5,$t3,$t4
/*    2f9ec:	ac4d0000 */ 	sw	$t5,0x0($v0)
/*    2f9f0:	03e00008 */ 	jr	$ra
/*    2f9f4:	27bd0020 */ 	addiu	$sp,$sp,0x20
);
