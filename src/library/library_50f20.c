#include <ultra64.h>
#include "types.h"
#include "library/library_06330.h"
#include "library/library_4ae00.h"
#include "library/library_4d6f0.h"
#include "library/library_50a00.h"
#include "library/library_513b0.h"

GLOBAL_ASM(
glabel func50f20
/*    50f20:	27bdfdf0 */ 	addiu	$sp,$sp,-528
/*    50f24:	afbf0044 */ 	sw	$ra,0x44($sp)
/*    50f28:	240e0001 */ 	addiu	$t6,$zero,0x1
/*    50f2c:	afbe0040 */ 	sw	$s8,0x40($sp)
/*    50f30:	afb7003c */ 	sw	$s7,0x3c($sp)
/*    50f34:	afb60038 */ 	sw	$s6,0x38($sp)
/*    50f38:	afb50034 */ 	sw	$s5,0x34($sp)
/*    50f3c:	afb40030 */ 	sw	$s4,0x30($sp)
/*    50f40:	afb3002c */ 	sw	$s3,0x2c($sp)
/*    50f44:	afb20028 */ 	sw	$s2,0x28($sp)
/*    50f48:	afb10024 */ 	sw	$s1,0x24($sp)
/*    50f4c:	afb00020 */ 	sw	$s0,0x20($sp)
/*    50f50:	afa40210 */ 	sw	$a0,0x210($sp)
/*    50f54:	afa50214 */ 	sw	$a1,0x214($sp)
/*    50f58:	afae0208 */ 	sw	$t6,0x208($sp)
/*    50f5c:	afa00204 */ 	sw	$zero,0x204($sp)
/*    50f60:	0c0142f8 */ 	jal	func00050be0
/*    50f64:	a7a00200 */ 	sh	$zero,0x200($sp)
/*    50f68:	2401000d */ 	addiu	$at,$zero,0xd
/*    50f6c:	14410005 */ 	bne	$v0,$at,.L00050f84
/*    50f70:	00401825 */ 	or	$v1,$v0,$zero
/*    50f74:	8fa40210 */ 	lw	$a0,0x210($sp)
/*    50f78:	0c0142f8 */ 	jal	func00050be0
/*    50f7c:	8fa50214 */ 	lw	$a1,0x214($sp)
/*    50f80:	00401825 */ 	or	$v1,$v0,$zero
.L00050f84:
/*    50f84:	2401000d */ 	addiu	$at,$zero,0xd
/*    50f88:	14410003 */ 	bne	$v0,$at,.L00050f98
/*    50f8c:	00000000 */ 	sll	$zero,$zero,0x0
/*    50f90:	100000f9 */ 	beqz	$zero,.L00051378
/*    50f94:	24020004 */ 	addiu	$v0,$zero,0x4
.L00050f98:
/*    50f98:	144000f6 */ 	bnez	$v0,.L00051374
/*    50f9c:	8faf0214 */ 	lw	$t7,0x214($sp)
/*    50fa0:	91f80000 */ 	lbu	$t8,0x0($t7)
/*    50fa4:	8fa40210 */ 	lw	$a0,0x210($sp)
/*    50fa8:	33190001 */ 	andi	$t9,$t8,0x1
/*    50fac:	57200008 */ 	bnezl	$t9,.L00050fd0
/*    50fb0:	27a40070 */ 	addiu	$a0,$sp,0x70
/*    50fb4:	0c0018cc */ 	jal	func00006330
/*    50fb8:	24050001 */ 	addiu	$a1,$zero,0x1
/*    50fbc:	50400004 */ 	beqzl	$v0,.L00050fd0
/*    50fc0:	27a40070 */ 	addiu	$a0,$sp,0x70
/*    50fc4:	100000ed */ 	beqz	$zero,.L0005137c
/*    50fc8:	8fbf0044 */ 	lw	$ra,0x44($sp)
/*    50fcc:	27a40070 */ 	addiu	$a0,$sp,0x70
.L00050fd0:
/*    50fd0:	0c012c30 */ 	jal	func0004b0c0
/*    50fd4:	2405000c */ 	addiu	$a1,$zero,0xc
/*    50fd8:	24080080 */ 	addiu	$t0,$zero,0x80
/*    50fdc:	24020080 */ 	addiu	$v0,$zero,0x80
/*    50fe0:	afa20068 */ 	sw	$v0,0x68($sp)
/*    50fe4:	a7a80202 */ 	sh	$t0,0x202($sp)
/*    50fe8:	24160001 */ 	addiu	$s6,$zero,0x1
.L00050fec:
/*    50fec:	8fa90208 */ 	lw	$t1,0x208($sp)
/*    50ff0:	27ab007c */ 	addiu	$t3,$sp,0x7c
/*    50ff4:	00009825 */ 	or	$s3,$zero,$zero
/*    50ff8:	000951c0 */ 	sll	$t2,$t1,0x7
/*    50ffc:	00009025 */ 	or	$s2,$zero,$zero
/*    51000:	014bf021 */ 	addu	$s8,$t2,$t3
.L00051004:
/*    51004:	8fa20068 */ 	lw	$v0,0x68($sp)
/*    51008:	00138140 */ 	sll	$s0,$s3,0x5
/*    5100c:	03d0a821 */ 	addu	$s5,$s8,$s0
/*    51010:	00523021 */ 	addu	$a2,$v0,$s2
/*    51014:	30ccffff */ 	andi	$t4,$a2,0xffff
/*    51018:	240d0020 */ 	addiu	$t5,$zero,0x20
/*    5101c:	afad0010 */ 	sw	$t5,0x10($sp)
/*    51020:	01803025 */ 	or	$a2,$t4,$zero
/*    51024:	02a03825 */ 	or	$a3,$s5,$zero
/*    51028:	8fa40210 */ 	lw	$a0,0x210($sp)
/*    5102c:	00002825 */ 	or	$a1,$zero,$zero
/*    51030:	0c0144ec */ 	jal	func000513b0
/*    51034:	0240a025 */ 	or	$s4,$s2,$zero
/*    51038:	10400003 */ 	beqz	$v0,.L00051048
/*    5103c:	8fae0208 */ 	lw	$t6,0x208($sp)
/*    51040:	100000ce */ 	beqz	$zero,.L0005137c
/*    51044:	8fbf0044 */ 	lw	$ra,0x44($sp)
.L00051048:
/*    51048:	000e7880 */ 	sll	$t7,$t6,0x2
/*    5104c:	27b80070 */ 	addiu	$t8,$sp,0x70
/*    51050:	01f8b821 */ 	addu	$s7,$t7,$t8
/*    51054:	02f3c821 */ 	addu	$t9,$s7,$s3
/*    51058:	a3360000 */ 	sb	$s6,0x0($t9)
/*    5105c:	8fa80204 */ 	lw	$t0,0x204($sp)
/*    51060:	27ab0070 */ 	addiu	$t3,$sp,0x70
/*    51064:	27ad007c */ 	addiu	$t5,$sp,0x7c
/*    51068:	00084880 */ 	sll	$t1,$t0,0x2
/*    5106c:	01335021 */ 	addu	$t2,$t1,$s3
/*    51070:	014b8821 */ 	addu	$s1,$t2,$t3
/*    51074:	922e0000 */ 	lbu	$t6,0x0($s1)
/*    51078:	000861c0 */ 	sll	$t4,$t0,0x7
/*    5107c:	018d9021 */ 	addu	$s2,$t4,$t5
/*    51080:	15c0000f */ 	bnez	$t6,.L000510c0
/*    51084:	8fa40210 */ 	lw	$a0,0x210($sp)
/*    51088:	97af0200 */ 	lhu	$t7,0x200($sp)
/*    5108c:	24190020 */ 	addiu	$t9,$zero,0x20
/*    51090:	afb90010 */ 	sw	$t9,0x10($sp)
/*    51094:	01f43021 */ 	addu	$a2,$t7,$s4
/*    51098:	30d8ffff */ 	andi	$t8,$a2,0xffff
/*    5109c:	03003025 */ 	or	$a2,$t8,$zero
/*    510a0:	00002825 */ 	or	$a1,$zero,$zero
/*    510a4:	0c0144ec */ 	jal	func000513b0
/*    510a8:	02503821 */ 	addu	$a3,$s2,$s0
/*    510ac:	50400004 */ 	beqzl	$v0,.L000510c0
/*    510b0:	a2360000 */ 	sb	$s6,0x0($s1)
/*    510b4:	100000b1 */ 	beqz	$zero,.L0005137c
/*    510b8:	8fbf0044 */ 	lw	$ra,0x44($sp)
/*    510bc:	a2360000 */ 	sb	$s6,0x0($s1)
.L000510c0:
/*    510c0:	02a02025 */ 	or	$a0,$s5,$zero
/*    510c4:	02502821 */ 	addu	$a1,$s2,$s0
/*    510c8:	0c013824 */ 	jal	func0004e090
/*    510cc:	24060020 */ 	addiu	$a2,$zero,0x20
/*    510d0:	10400003 */ 	beqz	$v0,.L000510e0
/*    510d4:	26920020 */ 	addiu	$s2,$s4,0x20
/*    510d8:	10000008 */ 	beqz	$zero,.L000510fc
/*    510dc:	00009825 */ 	or	$s3,$zero,$zero
.L000510e0:
/*    510e0:	2a620003 */ 	slti	$v0,$s3,0x3
/*    510e4:	26730001 */ 	addiu	$s3,$s3,0x1
/*    510e8:	326affff */ 	andi	$t2,$s3,0xffff
/*    510ec:	3249ffff */ 	andi	$t1,$s2,0xffff
/*    510f0:	01209025 */ 	or	$s2,$t1,$zero
/*    510f4:	1440ffc3 */ 	bnez	$v0,.L00051004
/*    510f8:	01409825 */ 	or	$s3,$t2,$zero
.L000510fc:
/*    510fc:	12600003 */ 	beqz	$s3,.L0005110c
/*    51100:	02601025 */ 	or	$v0,$s3,$zero
/*    51104:	1000009c */ 	beqz	$zero,.L00051378
/*    51108:	24020004 */ 	addiu	$v0,$zero,0x4
.L0005110c:
/*    5110c:	8fab0204 */ 	lw	$t3,0x204($sp)
/*    51110:	00009825 */ 	or	$s3,$zero,$zero
/*    51114:	00009025 */ 	or	$s2,$zero,$zero
/*    51118:	11600036 */ 	beqz	$t3,.L000511f4
.L0005111c:
/*    5111c:	02f38021 */ 	addu	$s0,$s7,$s3
/*    51120:	92080000 */ 	lbu	$t0,0x0($s0)
/*    51124:	8fa40210 */ 	lw	$a0,0x210($sp)
/*    51128:	00002825 */ 	or	$a1,$zero,$zero
/*    5112c:	1500000e */ 	bnez	$t0,.L00051168
/*    51130:	8fac0068 */ 	lw	$t4,0x68($sp)
/*    51134:	01923021 */ 	addu	$a2,$t4,$s2
/*    51138:	30cdffff */ 	andi	$t5,$a2,0xffff
/*    5113c:	00137140 */ 	sll	$t6,$s3,0x5
/*    51140:	240f0020 */ 	addiu	$t7,$zero,0x20
/*    51144:	afaf0010 */ 	sw	$t7,0x10($sp)
/*    51148:	03ce3821 */ 	addu	$a3,$s8,$t6
/*    5114c:	0c0144ec */ 	jal	func000513b0
/*    51150:	01a03025 */ 	or	$a2,$t5,$zero
/*    51154:	50400004 */ 	beqzl	$v0,.L00051168
/*    51158:	a2160000 */ 	sb	$s6,0x0($s0)
/*    5115c:	10000087 */ 	beqz	$zero,.L0005137c
/*    51160:	8fbf0044 */ 	lw	$ra,0x44($sp)
/*    51164:	a2160000 */ 	sb	$s6,0x0($s0)
.L00051168:
/*    51168:	27b80070 */ 	addiu	$t8,$sp,0x70
/*    5116c:	02788821 */ 	addu	$s1,$s3,$t8
/*    51170:	92390000 */ 	lbu	$t9,0x0($s1)
/*    51174:	00138140 */ 	sll	$s0,$s3,0x5
/*    51178:	8fa40210 */ 	lw	$a0,0x210($sp)
/*    5117c:	1720000c */ 	bnez	$t9,.L000511b0
/*    51180:	00002825 */ 	or	$a1,$zero,$zero
/*    51184:	27a9007c */ 	addiu	$t1,$sp,0x7c
/*    51188:	240a0020 */ 	addiu	$t2,$zero,0x20
/*    5118c:	afaa0010 */ 	sw	$t2,0x10($sp)
/*    51190:	02093821 */ 	addu	$a3,$s0,$t1
/*    51194:	0c0144ec */ 	jal	func000513b0
/*    51198:	3246ffff */ 	andi	$a2,$s2,0xffff
/*    5119c:	50400004 */ 	beqzl	$v0,.L000511b0
/*    511a0:	a2360000 */ 	sb	$s6,0x0($s1)
/*    511a4:	10000075 */ 	beqz	$zero,.L0005137c
/*    511a8:	8fbf0044 */ 	lw	$ra,0x44($sp)
/*    511ac:	a2360000 */ 	sb	$s6,0x0($s1)
.L000511b0:
/*    511b0:	27ab007c */ 	addiu	$t3,$sp,0x7c
/*    511b4:	020b2821 */ 	addu	$a1,$s0,$t3
/*    511b8:	03d02021 */ 	addu	$a0,$s8,$s0
/*    511bc:	0c013824 */ 	jal	func0004e090
/*    511c0:	24060020 */ 	addiu	$a2,$zero,0x20
/*    511c4:	10400003 */ 	beqz	$v0,.L000511d4
/*    511c8:	26520020 */ 	addiu	$s2,$s2,0x20
/*    511cc:	10000009 */ 	beqz	$zero,.L000511f4
/*    511d0:	00001025 */ 	or	$v0,$zero,$zero
.L000511d4:
/*    511d4:	2a620003 */ 	slti	$v0,$s3,0x3
/*    511d8:	26730001 */ 	addiu	$s3,$s3,0x1
/*    511dc:	326cffff */ 	andi	$t4,$s3,0xffff
/*    511e0:	3248ffff */ 	andi	$t0,$s2,0xffff
/*    511e4:	01009025 */ 	or	$s2,$t0,$zero
/*    511e8:	1440ffcc */ 	bnez	$v0,.L0005111c
/*    511ec:	01809825 */ 	or	$s3,$t4,$zero
/*    511f0:	01801025 */ 	or	$v0,$t4,$zero
.L000511f4:
/*    511f4:	10400003 */ 	beqz	$v0,.L00051204
/*    511f8:	8fad0204 */ 	lw	$t5,0x204($sp)
/*    511fc:	1000005e */ 	beqz	$zero,.L00051378
/*    51200:	24020004 */ 	addiu	$v0,$zero,0x4
.L00051204:
/*    51204:	11a00005 */ 	beqz	$t5,.L0005121c
/*    51208:	000d7080 */ 	sll	$t6,$t5,0x2
/*    5120c:	27af0070 */ 	addiu	$t7,$sp,0x70
/*    51210:	01cf2021 */ 	addu	$a0,$t6,$t7
/*    51214:	0c012c30 */ 	jal	func0004b0c0
/*    51218:	24050004 */ 	addiu	$a1,$zero,0x4
.L0005121c:
/*    5121c:	8faa0068 */ 	lw	$t2,0x68($sp)
/*    51220:	8fb90208 */ 	lw	$t9,0x208($sp)
/*    51224:	97b80202 */ 	lhu	$t8,0x202($sp)
/*    51228:	000a5840 */ 	sll	$t3,$t2,0x1
/*    5122c:	3168ffff */ 	andi	$t0,$t3,0xffff
/*    51230:	29014001 */ 	slti	$at,$t0,0x4001
/*    51234:	3b290003 */ 	xori	$t1,$t9,0x3
/*    51238:	afa80068 */ 	sw	$t0,0x68($sp)
/*    5123c:	a7ab0202 */ 	sh	$t3,0x202($sp)
/*    51240:	afa90208 */ 	sw	$t1,0x208($sp)
/*    51244:	afb90204 */ 	sw	$t9,0x204($sp)
/*    51248:	1420ff68 */ 	bnez	$at,.L00050fec
/*    5124c:	a7b80200 */ 	sh	$t8,0x200($sp)
/*    51250:	8fac0210 */ 	lw	$t4,0x210($sp)
/*    51254:	8faf0208 */ 	lw	$t7,0x208($sp)
/*    51258:	00009825 */ 	or	$s3,$zero,$zero
/*    5125c:	8d8d0050 */ 	lw	$t5,0x50($t4)
/*    51260:	00009025 */ 	or	$s2,$zero,$zero
/*    51264:	27b9007c */ 	addiu	$t9,$sp,0x7c
/*    51268:	29a10002 */ 	slti	$at,$t5,0x2
/*    5126c:	10200005 */ 	beqz	$at,.L00051284
/*    51270:	000fc1c0 */ 	sll	$t8,$t7,0x7
/*    51274:	8d8e004c */ 	lw	$t6,0x4c($t4)
/*    51278:	24010002 */ 	addiu	$at,$zero,0x2
/*    5127c:	55c10037 */ 	bnel	$t6,$at,.L0005135c
/*    51280:	8fa40210 */ 	lw	$a0,0x210($sp)
.L00051284:
/*    51284:	0319f021 */ 	addu	$s8,$t8,$t9
/*    51288:	3416a000 */ 	dli	$s6,0xa000
.L0005128c:
/*    5128c:	02563021 */ 	addu	$a2,$s2,$s6
/*    51290:	00138140 */ 	sll	$s0,$s3,0x5
/*    51294:	03d0a821 */ 	addu	$s5,$s8,$s0
/*    51298:	30c9ffff */ 	andi	$t1,$a2,0xffff
/*    5129c:	240a0020 */ 	addiu	$t2,$zero,0x20
/*    512a0:	afaa0010 */ 	sw	$t2,0x10($sp)
/*    512a4:	01203025 */ 	or	$a2,$t1,$zero
/*    512a8:	02a03825 */ 	or	$a3,$s5,$zero
/*    512ac:	8fa40210 */ 	lw	$a0,0x210($sp)
/*    512b0:	00002825 */ 	or	$a1,$zero,$zero
/*    512b4:	0c0144ec */ 	jal	func000513b0
/*    512b8:	0240a025 */ 	or	$s4,$s2,$zero
/*    512bc:	10400003 */ 	beqz	$v0,.L000512cc
/*    512c0:	8fa40210 */ 	lw	$a0,0x210($sp)
/*    512c4:	1000002d */ 	beqz	$zero,.L0005137c
/*    512c8:	8fbf0044 */ 	lw	$ra,0x44($sp)
.L000512cc:
/*    512cc:	8fa80204 */ 	lw	$t0,0x204($sp)
/*    512d0:	26862000 */ 	addiu	$a2,$s4,0x2000
/*    512d4:	27ae007c */ 	addiu	$t6,$sp,0x7c
/*    512d8:	000869c0 */ 	sll	$t5,$t0,0x7
/*    512dc:	01b06021 */ 	addu	$t4,$t5,$s0
/*    512e0:	018e8821 */ 	addu	$s1,$t4,$t6
/*    512e4:	30cbffff */ 	andi	$t3,$a2,0xffff
/*    512e8:	240f0020 */ 	addiu	$t7,$zero,0x20
/*    512ec:	afaf0010 */ 	sw	$t7,0x10($sp)
/*    512f0:	01603025 */ 	or	$a2,$t3,$zero
/*    512f4:	02203825 */ 	or	$a3,$s1,$zero
/*    512f8:	0c0144ec */ 	jal	func000513b0
/*    512fc:	00002825 */ 	or	$a1,$zero,$zero
/*    51300:	10400003 */ 	beqz	$v0,.L00051310
/*    51304:	02a02025 */ 	or	$a0,$s5,$zero
/*    51308:	1000001c */ 	beqz	$zero,.L0005137c
/*    5130c:	8fbf0044 */ 	lw	$ra,0x44($sp)
.L00051310:
/*    51310:	02202825 */ 	or	$a1,$s1,$zero
/*    51314:	0c013824 */ 	jal	func0004e090
/*    51318:	24060020 */ 	addiu	$a2,$zero,0x20
/*    5131c:	10400003 */ 	beqz	$v0,.L0005132c
/*    51320:	26920020 */ 	addiu	$s2,$s4,0x20
/*    51324:	10000008 */ 	beqz	$zero,.L00051348
/*    51328:	00009825 */ 	or	$s3,$zero,$zero
.L0005132c:
/*    5132c:	2a620003 */ 	slti	$v0,$s3,0x3
/*    51330:	26730001 */ 	addiu	$s3,$s3,0x1
/*    51334:	3279ffff */ 	andi	$t9,$s3,0xffff
/*    51338:	3258ffff */ 	andi	$t8,$s2,0xffff
/*    5133c:	03009025 */ 	or	$s2,$t8,$zero
/*    51340:	1440ffd2 */ 	bnez	$v0,.L0005128c
/*    51344:	03209825 */ 	or	$s3,$t9,$zero
.L00051348:
/*    51348:	52600004 */ 	beqzl	$s3,.L0005135c
/*    5134c:	8fa40210 */ 	lw	$a0,0x210($sp)
/*    51350:	10000009 */ 	beqz	$zero,.L00051378
/*    51354:	24020004 */ 	addiu	$v0,$zero,0x4
/*    51358:	8fa40210 */ 	lw	$a0,0x210($sp)
.L0005135c:
/*    5135c:	0c0142f8 */ 	jal	func00050be0
/*    51360:	8fa50214 */ 	lw	$a1,0x214($sp)
/*    51364:	2401000d */ 	addiu	$at,$zero,0xd
/*    51368:	14410002 */ 	bne	$v0,$at,.L00051374
/*    5136c:	00401825 */ 	or	$v1,$v0,$zero
/*    51370:	24030004 */ 	addiu	$v1,$zero,0x4
.L00051374:
/*    51374:	00601025 */ 	or	$v0,$v1,$zero
.L00051378:
/*    51378:	8fbf0044 */ 	lw	$ra,0x44($sp)
.L0005137c:
/*    5137c:	8fb00020 */ 	lw	$s0,0x20($sp)
/*    51380:	8fb10024 */ 	lw	$s1,0x24($sp)
/*    51384:	8fb20028 */ 	lw	$s2,0x28($sp)
/*    51388:	8fb3002c */ 	lw	$s3,0x2c($sp)
/*    5138c:	8fb40030 */ 	lw	$s4,0x30($sp)
/*    51390:	8fb50034 */ 	lw	$s5,0x34($sp)
/*    51394:	8fb60038 */ 	lw	$s6,0x38($sp)
/*    51398:	8fb7003c */ 	lw	$s7,0x3c($sp)
/*    5139c:	8fbe0040 */ 	lw	$s8,0x40($sp)
/*    513a0:	03e00008 */ 	jr	$ra
/*    513a4:	27bd0210 */ 	addiu	$sp,$sp,0x210
/*    513a8:	00000000 */ 	sll	$zero,$zero,0x0
/*    513ac:	00000000 */ 	sll	$zero,$zero,0x0
);