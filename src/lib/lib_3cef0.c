#include <ultra64.h>
#include "constants.h"
#include "bss.h"
#include "lib/lib_30ce0.h"
#include "lib/lib_3e730.h"
#include "data.h"
#include "types.h"

GLOBAL_ASM(
glabel func0003cef0
/*    3cef0:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*    3cef4:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    3cef8:	afa40020 */ 	sw	$a0,0x20($sp)
/*    3cefc:	afa50024 */ 	sw	$a1,0x24($sp)
/*    3cf00:	8fae0020 */ 	lw	$t6,0x20($sp)
/*    3cf04:	8dcf0008 */ 	lw	$t7,0x8($t6)
/*    3cf08:	11e0001f */ 	beqz	$t7,.L0003cf88
/*    3cf0c:	00000000 */ 	nop
/*    3cf10:	0c00c541 */ 	jal	func00031504
/*    3cf14:	00000000 */ 	nop
/*    3cf18:	afa2001c */ 	sw	$v0,0x1c($sp)
/*    3cf1c:	8fb8001c */ 	lw	$t8,0x1c($sp)
/*    3cf20:	17000003 */ 	bnez	$t8,.L0003cf30
/*    3cf24:	00000000 */ 	nop
/*    3cf28:	10000019 */ 	b	.L0003cf90
/*    3cf2c:	00000000 */ 	nop
.L0003cf30:
/*    3cf30:	8fa90020 */ 	lw	$t1,0x20($sp)
/*    3cf34:	3c198006 */ 	lui	$t9,%hi(var8005f114)
/*    3cf38:	8f39f114 */ 	lw	$t9,%lo(var8005f114)($t9)
/*    3cf3c:	8d2a0008 */ 	lw	$t2,0x8($t1)
/*    3cf40:	8fad001c */ 	lw	$t5,0x1c($sp)
/*    3cf44:	8f28001c */ 	lw	$t0,0x1c($t9)
/*    3cf48:	8d4b0088 */ 	lw	$t3,0x88($t2)
/*    3cf4c:	010b6021 */ 	addu	$t4,$t0,$t3
/*    3cf50:	adac0004 */ 	sw	$t4,0x4($t5)
/*    3cf54:	8faf001c */ 	lw	$t7,0x1c($sp)
/*    3cf58:	240e000c */ 	addiu	$t6,$zero,0xc
/*    3cf5c:	a5ee0008 */ 	sh	$t6,0x8($t7)
/*    3cf60:	93b80027 */ 	lbu	$t8,0x27($sp)
/*    3cf64:	8fb9001c */ 	lw	$t9,0x1c($sp)
/*    3cf68:	af38000c */ 	sw	$t8,0xc($t9)
/*    3cf6c:	8fa9001c */ 	lw	$t1,0x1c($sp)
/*    3cf70:	ad200000 */ 	sw	$zero,0x0($t1)
/*    3cf74:	8faa0020 */ 	lw	$t2,0x20($sp)
/*    3cf78:	24050003 */ 	addiu	$a1,$zero,0x3
/*    3cf7c:	8fa6001c */ 	lw	$a2,0x1c($sp)
/*    3cf80:	0c00fc79 */ 	jal	func0003f1e4
/*    3cf84:	8d440008 */ 	lw	$a0,0x8($t2)
.L0003cf88:
/*    3cf88:	10000001 */ 	b	.L0003cf90
/*    3cf8c:	00000000 */ 	nop
.L0003cf90:
/*    3cf90:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    3cf94:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*    3cf98:	03e00008 */ 	jr	$ra
/*    3cf9c:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel func0003cfa0
/*    3cfa0:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*    3cfa4:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    3cfa8:	afa40020 */ 	sw	$a0,0x20($sp)
/*    3cfac:	afa50024 */ 	sw	$a1,0x24($sp)
/*    3cfb0:	8fae0020 */ 	lw	$t6,0x20($sp)
/*    3cfb4:	8dcf0008 */ 	lw	$t7,0x8($t6)
/*    3cfb8:	11e0001f */ 	beqz	$t7,.L0003d038
/*    3cfbc:	00000000 */ 	nop
/*    3cfc0:	0c00c541 */ 	jal	func00031504
/*    3cfc4:	00000000 */ 	nop
/*    3cfc8:	afa2001c */ 	sw	$v0,0x1c($sp)
/*    3cfcc:	8fb8001c */ 	lw	$t8,0x1c($sp)
/*    3cfd0:	17000003 */ 	bnez	$t8,.L0003cfe0
/*    3cfd4:	00000000 */ 	nop
/*    3cfd8:	10000019 */ 	b	.L0003d040
/*    3cfdc:	00000000 */ 	nop
.L0003cfe0:
/*    3cfe0:	8fa90020 */ 	lw	$t1,0x20($sp)
/*    3cfe4:	3c198006 */ 	lui	$t9,%hi(var8005f114)
/*    3cfe8:	8f39f114 */ 	lw	$t9,%lo(var8005f114)($t9)
/*    3cfec:	8d2a0008 */ 	lw	$t2,0x8($t1)
/*    3cff0:	8fad001c */ 	lw	$t5,0x1c($sp)
/*    3cff4:	8f28001c */ 	lw	$t0,0x1c($t9)
/*    3cff8:	8d4b0088 */ 	lw	$t3,0x88($t2)
/*    3cffc:	010b6021 */ 	addu	$t4,$t0,$t3
/*    3d000:	adac0004 */ 	sw	$t4,0x4($t5)
/*    3d004:	8faf001c */ 	lw	$t7,0x1c($sp)
/*    3d008:	240e0007 */ 	addiu	$t6,$zero,0x7
/*    3d00c:	a5ee0008 */ 	sh	$t6,0x8($t7)
/*    3d010:	c7a40024 */ 	lwc1	$f4,0x24($sp)
/*    3d014:	8fb8001c */ 	lw	$t8,0x1c($sp)
/*    3d018:	e704000c */ 	swc1	$f4,0xc($t8)
/*    3d01c:	8fb9001c */ 	lw	$t9,0x1c($sp)
/*    3d020:	af200000 */ 	sw	$zero,0x0($t9)
/*    3d024:	8fa90020 */ 	lw	$t1,0x20($sp)
/*    3d028:	24050003 */ 	addiu	$a1,$zero,0x3
/*    3d02c:	8fa6001c */ 	lw	$a2,0x1c($sp)
/*    3d030:	0c00fc79 */ 	jal	func0003f1e4
/*    3d034:	8d240008 */ 	lw	$a0,0x8($t1)
.L0003d038:
/*    3d038:	10000001 */ 	b	.L0003d040
/*    3d03c:	00000000 */ 	nop
.L0003d040:
/*    3d040:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    3d044:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*    3d048:	03e00008 */ 	jr	$ra
/*    3d04c:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel func0003d050
/*    3d050:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*    3d054:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    3d058:	afa40020 */ 	sw	$a0,0x20($sp)
/*    3d05c:	afa50024 */ 	sw	$a1,0x24($sp)
/*    3d060:	8fae0020 */ 	lw	$t6,0x20($sp)
/*    3d064:	8dcf0008 */ 	lw	$t7,0x8($t6)
/*    3d068:	11e0001f */ 	beqz	$t7,.L0003d0e8
/*    3d06c:	00000000 */ 	nop
/*    3d070:	0c00c541 */ 	jal	func00031504
/*    3d074:	00000000 */ 	nop
/*    3d078:	afa2001c */ 	sw	$v0,0x1c($sp)
/*    3d07c:	8fb8001c */ 	lw	$t8,0x1c($sp)
/*    3d080:	17000003 */ 	bnez	$t8,.L0003d090
/*    3d084:	00000000 */ 	nop
/*    3d088:	10000019 */ 	b	.L0003d0f0
/*    3d08c:	00000000 */ 	nop
.L0003d090:
/*    3d090:	8fa90020 */ 	lw	$t1,0x20($sp)
/*    3d094:	3c198006 */ 	lui	$t9,%hi(var8005f114)
/*    3d098:	8f39f114 */ 	lw	$t9,%lo(var8005f114)($t9)
/*    3d09c:	8d2a0008 */ 	lw	$t2,0x8($t1)
/*    3d0a0:	8fad001c */ 	lw	$t5,0x1c($sp)
/*    3d0a4:	8f28001c */ 	lw	$t0,0x1c($t9)
/*    3d0a8:	8d4b0088 */ 	lw	$t3,0x88($t2)
/*    3d0ac:	010b6021 */ 	addu	$t4,$t0,$t3
/*    3d0b0:	adac0004 */ 	sw	$t4,0x4($t5)
/*    3d0b4:	8faf001c */ 	lw	$t7,0x1c($sp)
/*    3d0b8:	240e0010 */ 	addiu	$t6,$zero,0x10
/*    3d0bc:	a5ee0008 */ 	sh	$t6,0x8($t7)
/*    3d0c0:	93b80027 */ 	lbu	$t8,0x27($sp)
/*    3d0c4:	8fb9001c */ 	lw	$t9,0x1c($sp)
/*    3d0c8:	af38000c */ 	sw	$t8,0xc($t9)
/*    3d0cc:	8fa9001c */ 	lw	$t1,0x1c($sp)
/*    3d0d0:	ad200000 */ 	sw	$zero,0x0($t1)
/*    3d0d4:	8faa0020 */ 	lw	$t2,0x20($sp)
/*    3d0d8:	24050003 */ 	addiu	$a1,$zero,0x3
/*    3d0dc:	8fa6001c */ 	lw	$a2,0x1c($sp)
/*    3d0e0:	0c00fc79 */ 	jal	func0003f1e4
/*    3d0e4:	8d440008 */ 	lw	$a0,0x8($t2)
.L0003d0e8:
/*    3d0e8:	10000001 */ 	b	.L0003d0f0
/*    3d0ec:	00000000 */ 	nop
.L0003d0f0:
/*    3d0f0:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    3d0f4:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*    3d0f8:	03e00008 */ 	jr	$ra
/*    3d0fc:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel func0003d100
/*    3d100:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*    3d104:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    3d108:	afa40020 */ 	sw	$a0,0x20($sp)
/*    3d10c:	8fae0020 */ 	lw	$t6,0x20($sp)
/*    3d110:	8dcf0008 */ 	lw	$t7,0x8($t6)
/*    3d114:	11e0001c */ 	beqz	$t7,.L0003d188
/*    3d118:	00000000 */ 	nop
/*    3d11c:	0c00c541 */ 	jal	func00031504
/*    3d120:	00000000 */ 	nop
/*    3d124:	afa2001c */ 	sw	$v0,0x1c($sp)
/*    3d128:	8fb8001c */ 	lw	$t8,0x1c($sp)
/*    3d12c:	17000003 */ 	bnez	$t8,.L0003d13c
/*    3d130:	00000000 */ 	nop
/*    3d134:	10000016 */ 	b	.L0003d190
/*    3d138:	00000000 */ 	nop
.L0003d13c:
/*    3d13c:	8fa90020 */ 	lw	$t1,0x20($sp)
/*    3d140:	3c198006 */ 	lui	$t9,%hi(var8005f114)
/*    3d144:	8f39f114 */ 	lw	$t9,%lo(var8005f114)($t9)
/*    3d148:	8d2a0008 */ 	lw	$t2,0x8($t1)
/*    3d14c:	8fad001c */ 	lw	$t5,0x1c($sp)
/*    3d150:	8f28001c */ 	lw	$t0,0x1c($t9)
/*    3d154:	8d4b0088 */ 	lw	$t3,0x88($t2)
/*    3d158:	010b6021 */ 	addu	$t4,$t0,$t3
/*    3d15c:	adac0004 */ 	sw	$t4,0x4($t5)
/*    3d160:	8faf001c */ 	lw	$t7,0x1c($sp)
/*    3d164:	240e000f */ 	addiu	$t6,$zero,0xf
/*    3d168:	a5ee0008 */ 	sh	$t6,0x8($t7)
/*    3d16c:	8fb8001c */ 	lw	$t8,0x1c($sp)
/*    3d170:	af000000 */ 	sw	$zero,0x0($t8)
/*    3d174:	8fb90020 */ 	lw	$t9,0x20($sp)
/*    3d178:	24050003 */ 	addiu	$a1,$zero,0x3
/*    3d17c:	8fa6001c */ 	lw	$a2,0x1c($sp)
/*    3d180:	0c00fc79 */ 	jal	func0003f1e4
/*    3d184:	8f240008 */ 	lw	$a0,0x8($t9)
.L0003d188:
/*    3d188:	10000001 */ 	b	.L0003d190
/*    3d18c:	00000000 */ 	nop
.L0003d190:
/*    3d190:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    3d194:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*    3d198:	03e00008 */ 	jr	$ra
/*    3d19c:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel func0003d1a0
/*    3d1a0:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*    3d1a4:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    3d1a8:	afa40020 */ 	sw	$a0,0x20($sp)
/*    3d1ac:	8fae0020 */ 	lw	$t6,0x20($sp)
/*    3d1b0:	8dcf0008 */ 	lw	$t7,0x8($t6)
/*    3d1b4:	11e00029 */ 	beqz	$t7,.L0003d25c
/*    3d1b8:	00000000 */ 	nop
/*    3d1bc:	8fb80020 */ 	lw	$t8,0x20($sp)
/*    3d1c0:	8f190008 */ 	lw	$t9,0x8($t8)
/*    3d1c4:	8f280088 */ 	lw	$t0,0x88($t9)
/*    3d1c8:	1100001f */ 	beqz	$t0,.L0003d248
/*    3d1cc:	00000000 */ 	nop
/*    3d1d0:	0c00c541 */ 	jal	func00031504
/*    3d1d4:	00000000 */ 	nop
/*    3d1d8:	afa2001c */ 	sw	$v0,0x1c($sp)
/*    3d1dc:	8fa9001c */ 	lw	$t1,0x1c($sp)
/*    3d1e0:	15200003 */ 	bnez	$t1,.L0003d1f0
/*    3d1e4:	00000000 */ 	nop
/*    3d1e8:	1000001e */ 	b	.L0003d264
/*    3d1ec:	00000000 */ 	nop
.L0003d1f0:
/*    3d1f0:	8fac0020 */ 	lw	$t4,0x20($sp)
/*    3d1f4:	3c0a8006 */ 	lui	$t2,%hi(var8005f114)
/*    3d1f8:	8d4af114 */ 	lw	$t2,%lo(var8005f114)($t2)
/*    3d1fc:	8d8d0008 */ 	lw	$t5,0x8($t4)
/*    3d200:	8fb8001c */ 	lw	$t8,0x1c($sp)
/*    3d204:	8d4b001c */ 	lw	$t3,0x1c($t2)
/*    3d208:	8dae0088 */ 	lw	$t6,0x88($t5)
/*    3d20c:	016e7821 */ 	addu	$t7,$t3,$t6
/*    3d210:	af0f0004 */ 	sw	$t7,0x4($t8)
/*    3d214:	8fb9001c */ 	lw	$t9,0x1c($sp)
/*    3d218:	a7200008 */ 	sh	$zero,0x8($t9)
/*    3d21c:	8fa80020 */ 	lw	$t0,0x20($sp)
/*    3d220:	8faa001c */ 	lw	$t2,0x1c($sp)
/*    3d224:	8d090008 */ 	lw	$t1,0x8($t0)
/*    3d228:	ad49000c */ 	sw	$t1,0xc($t2)
/*    3d22c:	8fac0020 */ 	lw	$t4,0x20($sp)
/*    3d230:	24050003 */ 	addiu	$a1,$zero,0x3
/*    3d234:	8fa6001c */ 	lw	$a2,0x1c($sp)
/*    3d238:	0c00fc79 */ 	jal	func0003f1e4
/*    3d23c:	8d840008 */ 	lw	$a0,0x8($t4)
/*    3d240:	10000004 */ 	b	.L0003d254
/*    3d244:	00000000 */ 	nop
.L0003d248:
/*    3d248:	8fad0020 */ 	lw	$t5,0x20($sp)
/*    3d24c:	0c00c57d */ 	jal	func000315f4
/*    3d250:	8da40008 */ 	lw	$a0,0x8($t5)
.L0003d254:
/*    3d254:	8fab0020 */ 	lw	$t3,0x20($sp)
/*    3d258:	ad600008 */ 	sw	$zero,0x8($t3)
.L0003d25c:
/*    3d25c:	10000001 */ 	b	.L0003d264
/*    3d260:	00000000 */ 	nop
.L0003d264:
/*    3d264:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    3d268:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*    3d26c:	03e00008 */ 	jr	$ra
/*    3d270:	00000000 */ 	nop
);
