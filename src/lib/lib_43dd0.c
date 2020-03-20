#include <ultra64.h>
#include "constants.h"
#include "game/data/data_000000.h"
#include "game/data/data_0083d0.h"
#include "game/data/data_00e460.h"
#include "game/data/data_0160b0.h"
#include "game/data/data_01a3a0.h"
#include "game/data/data_020df0.h"
#include "gvars/gvars.h"
#include "lib/lib_3c4d0.h"
#include "lib/lib_3e730.h"
#include "lib/lib_43dd0.h"
#include "lib/lib_461c0.h"
#include "lib/lib_4ae00.h"
#include "lib/lib_4b170.h"
#include "types.h"

GLOBAL_ASM(
glabel func00043dd0
/*    43dd0:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*    43dd4:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    43dd8:	afa40020 */ 	sw	$a0,0x20($sp)
/*    43ddc:	240e1000 */ 	addiu	$t6,$zero,0x1000
/*    43de0:	afae001c */ 	sw	$t6,0x1c($sp)
/*    43de4:	8faf0020 */ 	lw	$t7,0x20($sp)
/*    43de8:	8df8201c */ 	lw	$t8,0x201c($t7)
/*    43dec:	8df93f88 */ 	lw	$t9,0x3f88($t7)
/*    43df0:	03194021 */ 	addu	$t0,$t8,$t9
/*    43df4:	29011ffc */ 	slti	$at,$t0,0x1ffc
/*    43df8:	14200013 */ 	bnez	$at,.L00043e48
/*    43dfc:	00000000 */ 	sll	$zero,$zero,0x0
/*    43e00:	8fa90020 */ 	lw	$t1,0x20($sp)
/*    43e04:	8faa001c */ 	lw	$t2,0x1c($sp)
/*    43e08:	2525001c */ 	addiu	$a1,$t1,0x1c
/*    43e0c:	012a2021 */ 	addu	$a0,$t1,$t2
/*    43e10:	2484001c */ 	addiu	$a0,$a0,0x1c
/*    43e14:	0c012c5c */ 	jal	func0004b170
/*    43e18:	01403025 */ 	or	$a2,$t2,$zero
/*    43e1c:	8fab0020 */ 	lw	$t3,0x20($sp)
/*    43e20:	8fad001c */ 	lw	$t5,0x1c($sp)
/*    43e24:	8d6c201c */ 	lw	$t4,0x201c($t3)
/*    43e28:	018d7023 */ 	subu	$t6,$t4,$t5
/*    43e2c:	ad6e201c */ 	sw	$t6,0x201c($t3)
/*    43e30:	8faf0020 */ 	lw	$t7,0x20($sp)
/*    43e34:	8fb9001c */ 	lw	$t9,0x1c($sp)
/*    43e38:	8df82020 */ 	lw	$t8,0x2020($t7)
/*    43e3c:	001940c0 */ 	sll	$t0,$t9,0x3
/*    43e40:	03084823 */ 	subu	$t1,$t8,$t0
/*    43e44:	ade92020 */ 	sw	$t1,0x2020($t7)
.L00043e48:
/*    43e48:	8faa0020 */ 	lw	$t2,0x20($sp)
/*    43e4c:	2407ffff */ 	addiu	$a3,$zero,-1
/*    43e50:	8d4c201c */ 	lw	$t4,0x201c($t2)
/*    43e54:	8d590004 */ 	lw	$t9,0x4($t2)
/*    43e58:	8d440000 */ 	lw	$a0,0x0($t2)
/*    43e5c:	014c2821 */ 	addu	$a1,$t2,$t4
/*    43e60:	24a5001c */ 	addiu	$a1,$a1,0x1c
/*    43e64:	0320f809 */ 	jalr	$t9
/*    43e68:	8d463f88 */ 	lw	$a2,0x3f88($t2)
/*    43e6c:	afa20018 */ 	sw	$v0,0x18($sp)
/*    43e70:	8fae0020 */ 	lw	$t6,0x20($sp)
/*    43e74:	8fad0018 */ 	lw	$t5,0x18($sp)
/*    43e78:	8dcb3f88 */ 	lw	$t3,0x3f88($t6)
/*    43e7c:	01ab082a */ 	slt	$at,$t5,$t3
/*    43e80:	10200008 */ 	beqz	$at,.L00043ea4
/*    43e84:	00000000 */ 	sll	$zero,$zero,0x0
/*    43e88:	8fb80020 */ 	lw	$t8,0x20($sp)
/*    43e8c:	8fa80018 */ 	lw	$t0,0x18($sp)
/*    43e90:	8f093f88 */ 	lw	$t1,0x3f88($t8)
/*    43e94:	03082021 */ 	addu	$a0,$t8,$t0
/*    43e98:	2484001c */ 	addiu	$a0,$a0,0x1c
/*    43e9c:	0c012c30 */ 	jal	bzero
/*    43ea0:	01282823 */ 	subu	$a1,$t1,$t0
.L00043ea4:
/*    43ea4:	8faf0020 */ 	lw	$t7,0x20($sp)
/*    43ea8:	8dec0018 */ 	lw	$t4,0x18($t7)
/*    43eac:	8dea3f88 */ 	lw	$t2,0x3f88($t7)
/*    43eb0:	018ac821 */ 	addu	$t9,$t4,$t2
/*    43eb4:	adf90018 */ 	sw	$t9,0x18($t7)
/*    43eb8:	8fae0020 */ 	lw	$t6,0x20($sp)
/*    43ebc:	8dcd201c */ 	lw	$t5,0x201c($t6)
/*    43ec0:	8dcb3f88 */ 	lw	$t3,0x3f88($t6)
/*    43ec4:	01abc021 */ 	addu	$t8,$t5,$t3
/*    43ec8:	add8201c */ 	sw	$t8,0x201c($t6)
/*    43ecc:	8fa90020 */ 	lw	$t1,0x20($sp)
/*    43ed0:	8d28201c */ 	lw	$t0,0x201c($t1)
/*    43ed4:	8d2c3f88 */ 	lw	$t4,0x3f88($t1)
/*    43ed8:	10000003 */ 	beqz	$zero,.L00043ee8
/*    43edc:	010c1023 */ 	subu	$v0,$t0,$t4
/*    43ee0:	10000001 */ 	beqz	$zero,.L00043ee8
/*    43ee4:	00000000 */ 	sll	$zero,$zero,0x0
.L00043ee8:
/*    43ee8:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    43eec:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*    43ef0:	03e00008 */ 	jr	$ra
/*    43ef4:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func00043ef8
/*    43ef8:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*    43efc:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    43f00:	afa40028 */ 	sw	$a0,0x28($sp)
/*    43f04:	afa5002c */ 	sw	$a1,0x2c($sp)
/*    43f08:	8fae002c */ 	lw	$t6,0x2c($sp)
/*    43f0c:	2401ffff */ 	addiu	$at,$zero,-1
/*    43f10:	11c10004 */ 	beq	$t6,$at,.L00043f24
/*    43f14:	00000000 */ 	sll	$zero,$zero,0x0
/*    43f18:	8faf002c */ 	lw	$t7,0x2c($sp)
/*    43f1c:	8fb80028 */ 	lw	$t8,0x28($sp)
/*    43f20:	af0f0018 */ 	sw	$t7,0x18($t8)
.L00043f24:
/*    43f24:	8fb9002c */ 	lw	$t9,0x2c($sp)
/*    43f28:	afb90024 */ 	sw	$t9,0x24($sp)
/*    43f2c:	afa00020 */ 	sw	$zero,0x20($sp)
/*    43f30:	240800ff */ 	addiu	$t0,$zero,0xff
/*    43f34:	a3a8001b */ 	sb	$t0,0x1b($sp)
.L00043f38:
/*    43f38:	8fa90028 */ 	lw	$t1,0x28($sp)
/*    43f3c:	8faa0020 */ 	lw	$t2,0x20($sp)
/*    43f40:	24060001 */ 	addiu	$a2,$zero,0x1
/*    43f44:	8d390004 */ 	lw	$t9,0x4($t1)
/*    43f48:	012a2821 */ 	addu	$a1,$t1,$t2
/*    43f4c:	24a52024 */ 	addiu	$a1,$a1,0x2024
/*    43f50:	8fa70024 */ 	lw	$a3,0x24($sp)
/*    43f54:	0320f809 */ 	jalr	$t9
/*    43f58:	8d240000 */ 	lw	$a0,0x0($t1)
/*    43f5c:	afa2001c */ 	sw	$v0,0x1c($sp)
/*    43f60:	8fab001c */ 	lw	$t3,0x1c($sp)
/*    43f64:	1d600003 */ 	bgtz	$t3,.L00043f74
/*    43f68:	00000000 */ 	sll	$zero,$zero,0x0
/*    43f6c:	10000121 */ 	beqz	$zero,.L000443f4
/*    43f70:	00001025 */ 	or	$v0,$zero,$zero
.L00043f74:
/*    43f74:	240cffff */ 	addiu	$t4,$zero,-1
/*    43f78:	afac0024 */ 	sw	$t4,0x24($sp)
/*    43f7c:	8fad0028 */ 	lw	$t5,0x28($sp)
/*    43f80:	8dae0018 */ 	lw	$t6,0x18($t5)
/*    43f84:	25cf0001 */ 	addiu	$t7,$t6,0x1
/*    43f88:	adaf0018 */ 	sw	$t7,0x18($t5)
/*    43f8c:	8fb80028 */ 	lw	$t8,0x28($sp)
/*    43f90:	8fa80020 */ 	lw	$t0,0x20($sp)
/*    43f94:	93b9001b */ 	lbu	$t9,0x1b($sp)
/*    43f98:	03085021 */ 	addu	$t2,$t8,$t0
/*    43f9c:	91492024 */ 	lbu	$t1,0x2024($t2)
/*    43fa0:	01395824 */ 	and	$t3,$t1,$t9
/*    43fa4:	11790006 */ 	beq	$t3,$t9,.L00043fc0
/*    43fa8:	00000000 */ 	sll	$zero,$zero,0x0
/*    43fac:	240c00ff */ 	addiu	$t4,$zero,0xff
/*    43fb0:	a3ac001b */ 	sb	$t4,0x1b($sp)
/*    43fb4:	afa00020 */ 	sw	$zero,0x20($sp)
/*    43fb8:	1000000c */ 	beqz	$zero,.L00043fec
/*    43fbc:	00000000 */ 	sll	$zero,$zero,0x0
.L00043fc0:
/*    43fc0:	8fae0020 */ 	lw	$t6,0x20($sp)
/*    43fc4:	25cf0001 */ 	addiu	$t7,$t6,0x1
/*    43fc8:	afaf0020 */ 	sw	$t7,0x20($sp)
/*    43fcc:	93ad001b */ 	lbu	$t5,0x1b($sp)
/*    43fd0:	240100f0 */ 	addiu	$at,$zero,0xf0
/*    43fd4:	15a10003 */ 	bne	$t5,$at,.L00043fe4
/*    43fd8:	00000000 */ 	sll	$zero,$zero,0x0
/*    43fdc:	10000005 */ 	beqz	$zero,.L00043ff4
/*    43fe0:	00000000 */ 	sll	$zero,$zero,0x0
.L00043fe4:
/*    43fe4:	241800f0 */ 	addiu	$t8,$zero,0xf0
/*    43fe8:	a3b8001b */ 	sb	$t8,0x1b($sp)
.L00043fec:
/*    43fec:	1000ffd2 */ 	beqz	$zero,.L00043f38
/*    43ff0:	00000000 */ 	sll	$zero,$zero,0x0
.L00043ff4:
/*    43ff4:	8fa80028 */ 	lw	$t0,0x28($sp)
/*    43ff8:	24060002 */ 	addiu	$a2,$zero,0x2
/*    43ffc:	2407ffff */ 	addiu	$a3,$zero,-1
/*    44000:	8d190004 */ 	lw	$t9,0x4($t0)
/*    44004:	8d040000 */ 	lw	$a0,0x0($t0)
/*    44008:	25052026 */ 	addiu	$a1,$t0,0x2026
/*    4400c:	0320f809 */ 	jalr	$t9
/*    44010:	00000000 */ 	sll	$zero,$zero,0x0
/*    44014:	afa2001c */ 	sw	$v0,0x1c($sp)
/*    44018:	8faa001c */ 	lw	$t2,0x1c($sp)
/*    4401c:	1d400003 */ 	bgtz	$t2,.L0004402c
/*    44020:	00000000 */ 	sll	$zero,$zero,0x0
/*    44024:	100000f3 */ 	beqz	$zero,.L000443f4
/*    44028:	00001025 */ 	or	$v0,$zero,$zero
.L0004402c:
/*    4402c:	8fa90028 */ 	lw	$t1,0x28($sp)
/*    44030:	8d2b0018 */ 	lw	$t3,0x18($t1)
/*    44034:	256c0002 */ 	addiu	$t4,$t3,0x2
/*    44038:	ad2c0018 */ 	sw	$t4,0x18($t1)
/*    4403c:	8faf0028 */ 	lw	$t7,0x28($sp)
/*    44040:	240e000c */ 	addiu	$t6,$zero,0xc
/*    44044:	adee2064 */ 	sw	$t6,0x2064($t7)
/*    44048:	8fad0028 */ 	lw	$t5,0x28($sp)
/*    4404c:	24060001 */ 	addiu	$a2,$zero,0x1
/*    44050:	25a42024 */ 	addiu	$a0,$t5,0x2024
/*    44054:	0c0118b1 */ 	jal	func000462c4
/*    44058:	25a52064 */ 	addiu	$a1,$t5,0x2064
/*    4405c:	8fb80028 */ 	lw	$t8,0x28($sp)
/*    44060:	af023ba4 */ 	sw	$v0,0x3ba4($t8)
/*    44064:	8fa80028 */ 	lw	$t0,0x28($sp)
/*    44068:	24060002 */ 	addiu	$a2,$zero,0x2
/*    4406c:	25042024 */ 	addiu	$a0,$t0,0x2024
/*    44070:	0c0118b1 */ 	jal	func000462c4
/*    44074:	25052064 */ 	addiu	$a1,$t0,0x2064
/*    44078:	8fb90028 */ 	lw	$t9,0x28($sp)
/*    4407c:	af223ba8 */ 	sw	$v0,0x3ba8($t9)
/*    44080:	8faa0028 */ 	lw	$t2,0x28($sp)
/*    44084:	24060001 */ 	addiu	$a2,$zero,0x1
/*    44088:	25442024 */ 	addiu	$a0,$t2,0x2024
/*    4408c:	0c0118b1 */ 	jal	func000462c4
/*    44090:	25452064 */ 	addiu	$a1,$t2,0x2064
/*    44094:	8fab0028 */ 	lw	$t3,0x28($sp)
/*    44098:	ad623bac */ 	sw	$v0,0x3bac($t3)
/*    4409c:	8fac0028 */ 	lw	$t4,0x28($sp)
/*    440a0:	24060004 */ 	addiu	$a2,$zero,0x4
/*    440a4:	25842024 */ 	addiu	$a0,$t4,0x2024
/*    440a8:	0c0118b1 */ 	jal	func000462c4
/*    440ac:	25852064 */ 	addiu	$a1,$t4,0x2064
/*    440b0:	8fa90028 */ 	lw	$t1,0x28($sp)
/*    440b4:	ad223bb0 */ 	sw	$v0,0x3bb0($t1)
/*    440b8:	8fae0028 */ 	lw	$t6,0x28($sp)
/*    440bc:	24060002 */ 	addiu	$a2,$zero,0x2
/*    440c0:	25c42024 */ 	addiu	$a0,$t6,0x2024
/*    440c4:	0c0118b1 */ 	jal	func000462c4
/*    440c8:	25c52064 */ 	addiu	$a1,$t6,0x2064
/*    440cc:	8faf0028 */ 	lw	$t7,0x28($sp)
/*    440d0:	ade23bb4 */ 	sw	$v0,0x3bb4($t7)
/*    440d4:	8fad0028 */ 	lw	$t5,0x28($sp)
/*    440d8:	24060001 */ 	addiu	$a2,$zero,0x1
/*    440dc:	25a42024 */ 	addiu	$a0,$t5,0x2024
/*    440e0:	0c0118b1 */ 	jal	func000462c4
/*    440e4:	25a52064 */ 	addiu	$a1,$t5,0x2064
/*    440e8:	8fb80028 */ 	lw	$t8,0x28($sp)
/*    440ec:	af023bb8 */ 	sw	$v0,0x3bb8($t8)
/*    440f0:	8fa80028 */ 	lw	$t0,0x28($sp)
/*    440f4:	24060001 */ 	addiu	$a2,$zero,0x1
/*    440f8:	25042024 */ 	addiu	$a0,$t0,0x2024
/*    440fc:	0c0118b1 */ 	jal	func000462c4
/*    44100:	25052064 */ 	addiu	$a1,$t0,0x2064
/*    44104:	8fb90028 */ 	lw	$t9,0x28($sp)
/*    44108:	af223bbc */ 	sw	$v0,0x3bbc($t9)
/*    4410c:	8faa0028 */ 	lw	$t2,0x28($sp)
/*    44110:	24060002 */ 	addiu	$a2,$zero,0x2
/*    44114:	25442024 */ 	addiu	$a0,$t2,0x2024
/*    44118:	0c0118b1 */ 	jal	func000462c4
/*    4411c:	25452064 */ 	addiu	$a1,$t2,0x2064
/*    44120:	8fab0028 */ 	lw	$t3,0x28($sp)
/*    44124:	ad623bc0 */ 	sw	$v0,0x3bc0($t3)
/*    44128:	8fac0028 */ 	lw	$t4,0x28($sp)
/*    4412c:	24060002 */ 	addiu	$a2,$zero,0x2
/*    44130:	25842024 */ 	addiu	$a0,$t4,0x2024
/*    44134:	0c0118b1 */ 	jal	func000462c4
/*    44138:	25852064 */ 	addiu	$a1,$t4,0x2064
/*    4413c:	8fa90028 */ 	lw	$t1,0x28($sp)
/*    44140:	ad223bc4 */ 	sw	$v0,0x3bc4($t1)
/*    44144:	8fae0028 */ 	lw	$t6,0x28($sp)
/*    44148:	24060001 */ 	addiu	$a2,$zero,0x1
/*    4414c:	25c42024 */ 	addiu	$a0,$t6,0x2024
/*    44150:	0c0118b1 */ 	jal	func000462c4
/*    44154:	25c52064 */ 	addiu	$a1,$t6,0x2064
/*    44158:	8faf0028 */ 	lw	$t7,0x28($sp)
/*    4415c:	ade23bc8 */ 	sw	$v0,0x3bc8($t7)
/*    44160:	8fad0028 */ 	lw	$t5,0x28($sp)
/*    44164:	24060001 */ 	addiu	$a2,$zero,0x1
/*    44168:	25a42024 */ 	addiu	$a0,$t5,0x2024
/*    4416c:	0c0118b1 */ 	jal	func000462c4
/*    44170:	25a52064 */ 	addiu	$a1,$t5,0x2064
/*    44174:	8fb80028 */ 	lw	$t8,0x28($sp)
/*    44178:	af023bcc */ 	sw	$v0,0x3bcc($t8)
/*    4417c:	8fa80028 */ 	lw	$t0,0x28($sp)
/*    44180:	24060002 */ 	addiu	$a2,$zero,0x2
/*    44184:	25042024 */ 	addiu	$a0,$t0,0x2024
/*    44188:	0c0118b1 */ 	jal	func000462c4
/*    4418c:	25052064 */ 	addiu	$a1,$t0,0x2064
/*    44190:	8fb90028 */ 	lw	$t9,0x28($sp)
/*    44194:	af223bd0 */ 	sw	$v0,0x3bd0($t9)
/*    44198:	8faa0028 */ 	lw	$t2,0x28($sp)
/*    4419c:	2401000f */ 	addiu	$at,$zero,0xf
/*    441a0:	8d4b3bb0 */ 	lw	$t3,0x3bb0($t2)
/*    441a4:	11610005 */ 	beq	$t3,$at,.L000441bc
/*    441a8:	00000000 */ 	sll	$zero,$zero,0x0
/*    441ac:	8d4c3bb4 */ 	lw	$t4,0x3bb4($t2)
/*    441b0:	24010003 */ 	addiu	$at,$zero,0x3
/*    441b4:	15810006 */ 	bne	$t4,$at,.L000441d0
/*    441b8:	00000000 */ 	sll	$zero,$zero,0x0
.L000441bc:
/*    441bc:	8fa40028 */ 	lw	$a0,0x28($sp)
/*    441c0:	0c010fbe */ 	jal	func00043ef8
/*    441c4:	2405ffff */ 	addiu	$a1,$zero,-1
/*    441c8:	1000008a */ 	beqz	$zero,.L000443f4
/*    441cc:	00000000 */ 	sll	$zero,$zero,0x0
.L000441d0:
/*    441d0:	8fa90028 */ 	lw	$t1,0x28($sp)
/*    441d4:	8d2e3bd4 */ 	lw	$t6,0x3bd4($t1)
/*    441d8:	15c0001a */ 	bnez	$t6,.L00044244
/*    441dc:	00000000 */ 	sll	$zero,$zero,0x0
/*    441e0:	8fad0028 */ 	lw	$t5,0x28($sp)
/*    441e4:	240f0001 */ 	addiu	$t7,$zero,0x1
/*    441e8:	adaf3bd4 */ 	sw	$t7,0x3bd4($t5)
/*    441ec:	8fb80028 */ 	lw	$t8,0x28($sp)
/*    441f0:	8f083ba4 */ 	lw	$t0,0x3ba4($t8)
/*    441f4:	af083bd8 */ 	sw	$t0,0x3bd8($t8)
/*    441f8:	8fb90028 */ 	lw	$t9,0x28($sp)
/*    441fc:	8f2b3ba8 */ 	lw	$t3,0x3ba8($t9)
/*    44200:	af2b3bdc */ 	sw	$t3,0x3bdc($t9)
/*    44204:	8faa0028 */ 	lw	$t2,0x28($sp)
/*    44208:	8d4c3bac */ 	lw	$t4,0x3bac($t2)
/*    4420c:	ad4c3be0 */ 	sw	$t4,0x3be0($t2)
/*    44210:	8fa90028 */ 	lw	$t1,0x28($sp)
/*    44214:	8d2e3bb4 */ 	lw	$t6,0x3bb4($t1)
/*    44218:	ad2e3be4 */ 	sw	$t6,0x3be4($t1)
/*    4421c:	8faf0028 */ 	lw	$t7,0x28($sp)
/*    44220:	8ded3bc0 */ 	lw	$t5,0x3bc0($t7)
/*    44224:	aded3be8 */ 	sw	$t5,0x3be8($t7)
/*    44228:	8fa80028 */ 	lw	$t0,0x28($sp)
/*    4422c:	8d183bc8 */ 	lw	$t8,0x3bc8($t0)
/*    44230:	ad183bec */ 	sw	$t8,0x3bec($t0)
/*    44234:	8fab0028 */ 	lw	$t3,0x28($sp)
/*    44238:	8d793bcc */ 	lw	$t9,0x3bcc($t3)
/*    4423c:	1000001f */ 	beqz	$zero,.L000442bc
/*    44240:	ad793bf0 */ 	sw	$t9,0x3bf0($t3)
.L00044244:
/*    44244:	8fac0028 */ 	lw	$t4,0x28($sp)
/*    44248:	8d8a3ba4 */ 	lw	$t2,0x3ba4($t4)
/*    4424c:	8d8e3bd8 */ 	lw	$t6,0x3bd8($t4)
/*    44250:	154e0015 */ 	bne	$t2,$t6,.L000442a8
/*    44254:	00000000 */ 	sll	$zero,$zero,0x0
/*    44258:	8d893ba8 */ 	lw	$t1,0x3ba8($t4)
/*    4425c:	8d8d3bdc */ 	lw	$t5,0x3bdc($t4)
/*    44260:	152d0011 */ 	bne	$t1,$t5,.L000442a8
/*    44264:	00000000 */ 	sll	$zero,$zero,0x0
/*    44268:	8d8f3bac */ 	lw	$t7,0x3bac($t4)
/*    4426c:	8d983be0 */ 	lw	$t8,0x3be0($t4)
/*    44270:	15f8000d */ 	bne	$t7,$t8,.L000442a8
/*    44274:	00000000 */ 	sll	$zero,$zero,0x0
/*    44278:	8d883bb4 */ 	lw	$t0,0x3bb4($t4)
/*    4427c:	8d993be4 */ 	lw	$t9,0x3be4($t4)
/*    44280:	15190009 */ 	bne	$t0,$t9,.L000442a8
/*    44284:	00000000 */ 	sll	$zero,$zero,0x0
/*    44288:	8d8b3bc0 */ 	lw	$t3,0x3bc0($t4)
/*    4428c:	8d8a3be8 */ 	lw	$t2,0x3be8($t4)
/*    44290:	156a0005 */ 	bne	$t3,$t2,.L000442a8
/*    44294:	00000000 */ 	sll	$zero,$zero,0x0
/*    44298:	8d8e3bcc */ 	lw	$t6,0x3bcc($t4)
/*    4429c:	8d893bf0 */ 	lw	$t1,0x3bf0($t4)
/*    442a0:	11c90006 */ 	beq	$t6,$t1,.L000442bc
/*    442a4:	00000000 */ 	sll	$zero,$zero,0x0
.L000442a8:
/*    442a8:	8fa40028 */ 	lw	$a0,0x28($sp)
/*    442ac:	0c010fbe */ 	jal	func00043ef8
/*    442b0:	2405ffff */ 	addiu	$a1,$zero,-1
/*    442b4:	1000004f */ 	beqz	$zero,.L000443f4
/*    442b8:	00000000 */ 	sll	$zero,$zero,0x0
.L000442bc:
/*    442bc:	8faf0028 */ 	lw	$t7,0x28($sp)
/*    442c0:	240d0004 */ 	addiu	$t5,$zero,0x4
/*    442c4:	aded2068 */ 	sw	$t5,0x2068($t7)
/*    442c8:	8fb80028 */ 	lw	$t8,0x28($sp)
/*    442cc:	8f083bac */ 	lw	$t0,0x3bac($t8)
/*    442d0:	1500001a */ 	bnez	$t0,.L0004433c
/*    442d4:	00000000 */ 	sll	$zero,$zero,0x0
/*    442d8:	8fb90028 */ 	lw	$t9,0x28($sp)
/*    442dc:	24060002 */ 	addiu	$a2,$zero,0x2
/*    442e0:	2407ffff */ 	addiu	$a3,$zero,-1
/*    442e4:	8f240000 */ 	lw	$a0,0x0($t9)
/*    442e8:	27252028 */ 	addiu	$a1,$t9,0x2028
/*    442ec:	8f390004 */ 	lw	$t9,0x4($t9)
/*    442f0:	0320f809 */ 	jalr	$t9
/*    442f4:	00000000 */ 	sll	$zero,$zero,0x0
/*    442f8:	afa2001c */ 	sw	$v0,0x1c($sp)
/*    442fc:	8fab001c */ 	lw	$t3,0x1c($sp)
/*    44300:	1d600003 */ 	bgtz	$t3,.L00044310
/*    44304:	00000000 */ 	sll	$zero,$zero,0x0
/*    44308:	1000003a */ 	beqz	$zero,.L000443f4
/*    4430c:	00001025 */ 	or	$v0,$zero,$zero
.L00044310:
/*    44310:	8faa0028 */ 	lw	$t2,0x28($sp)
/*    44314:	8d4c0018 */ 	lw	$t4,0x18($t2)
/*    44318:	258e0002 */ 	addiu	$t6,$t4,0x2
/*    4431c:	ad4e0018 */ 	sw	$t6,0x18($t2)
/*    44320:	8fa90028 */ 	lw	$t1,0x28($sp)
/*    44324:	8d2d2064 */ 	lw	$t5,0x2064($t1)
/*    44328:	25af0010 */ 	addiu	$t7,$t5,0x10
/*    4432c:	ad2f2064 */ 	sw	$t7,0x2064($t1)
/*    44330:	8fa80028 */ 	lw	$t0,0x28($sp)
/*    44334:	24180006 */ 	addiu	$t8,$zero,0x6
/*    44338:	ad182068 */ 	sw	$t8,0x2068($t0)
.L0004433c:
/*    4433c:	8fb90028 */ 	lw	$t9,0x28($sp)
/*    44340:	24010001 */ 	addiu	$at,$zero,0x1
/*    44344:	8f2b3ba8 */ 	lw	$t3,0x3ba8($t9)
/*    44348:	1561000c */ 	bne	$t3,$at,.L0004437c
/*    4434c:	00000000 */ 	sll	$zero,$zero,0x0
/*    44350:	8fae0028 */ 	lw	$t6,0x28($sp)
/*    44354:	3c0c7004 */ 	lui	$t4,%hi(func0004371c)
/*    44358:	258c371c */ 	addiu	$t4,$t4,%lo(func0004371c)
/*    4435c:	25c17fff */ 	addiu	$at,$t6,0x7fff
/*    44360:	ac2c0479 */ 	sw	$t4,0x479($at)
/*    44364:	8fad0028 */ 	lw	$t5,0x28($sp)
/*    44368:	3c0a7004 */ 	lui	$t2,%hi(func00042e38)
/*    4436c:	254a2e38 */ 	addiu	$t2,$t2,%lo(func00042e38)
/*    44370:	25a17fff */ 	addiu	$at,$t5,0x7fff
/*    44374:	10000011 */ 	beqz	$zero,.L000443bc
/*    44378:	ac2a047d */ 	sw	$t2,0x47d($at)
.L0004437c:
/*    4437c:	8faf0028 */ 	lw	$t7,0x28($sp)
/*    44380:	24010002 */ 	addiu	$at,$zero,0x2
/*    44384:	8de93ba8 */ 	lw	$t1,0x3ba8($t7)
/*    44388:	15210005 */ 	bne	$t1,$at,.L000443a0
/*    4438c:	00000000 */ 	sll	$zero,$zero,0x0
/*    44390:	10000018 */ 	beqz	$zero,.L000443f4
/*    44394:	00001025 */ 	or	$v0,$zero,$zero
/*    44398:	10000008 */ 	beqz	$zero,.L000443bc
/*    4439c:	00000000 */ 	sll	$zero,$zero,0x0
.L000443a0:
/*    443a0:	8fb80028 */ 	lw	$t8,0x28($sp)
/*    443a4:	24010003 */ 	addiu	$at,$zero,0x3
/*    443a8:	8f083ba8 */ 	lw	$t0,0x3ba8($t8)
/*    443ac:	15010003 */ 	bne	$t0,$at,.L000443bc
/*    443b0:	00000000 */ 	sll	$zero,$zero,0x0
/*    443b4:	1000000f */ 	beqz	$zero,.L000443f4
/*    443b8:	00001025 */ 	or	$v0,$zero,$zero
.L000443bc:
/*    443bc:	8fb90028 */ 	lw	$t9,0x28($sp)
/*    443c0:	03202025 */ 	or	$a0,$t9,$zero
/*    443c4:	27217fff */ 	addiu	$at,$t9,0x7fff
/*    443c8:	8c39047d */ 	lw	$t9,0x47d($at)
/*    443cc:	0320f809 */ 	jalr	$t9
/*    443d0:	00000000 */ 	sll	$zero,$zero,0x0
/*    443d4:	14400003 */ 	bnez	$v0,.L000443e4
/*    443d8:	00000000 */ 	sll	$zero,$zero,0x0
/*    443dc:	10000005 */ 	beqz	$zero,.L000443f4
/*    443e0:	00001025 */ 	or	$v0,$zero,$zero
.L000443e4:
/*    443e4:	10000003 */ 	beqz	$zero,.L000443f4
/*    443e8:	24020001 */ 	addiu	$v0,$zero,0x1
/*    443ec:	10000001 */ 	beqz	$zero,.L000443f4
/*    443f0:	00000000 */ 	sll	$zero,$zero,0x0
.L000443f4:
/*    443f4:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    443f8:	27bd0028 */ 	addiu	$sp,$sp,0x28
/*    443fc:	03e00008 */ 	jr	$ra
/*    44400:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func00044404
/*    44404:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*    44408:	afbf001c */ 	sw	$ra,0x1c($sp)
/*    4440c:	afb00018 */ 	sw	$s0,0x18($sp)
/*    44410:	3c0e8006 */ 	lui	$t6,%hi(var8005f704)
/*    44414:	8dcef704 */ 	lw	$t6,%lo(var8005f704)($t6)
/*    44418:	3c018006 */ 	lui	$at,%hi(var8005f704)
/*    4441c:	01c08025 */ 	or	$s0,$t6,$zero
/*    44420:	25cf0001 */ 	addiu	$t7,$t6,0x1
/*    44424:	12000003 */ 	beqz	$s0,.L00044434
/*    44428:	ac2ff704 */ 	sw	$t7,%lo(var8005f704)($at)
/*    4442c:	10000007 */ 	beqz	$zero,.L0004444c
/*    44430:	24020002 */ 	addiu	$v0,$zero,0x2
.L00044434:
/*    44434:	0c00fe28 */ 	jal	func0003f8a0
/*    44438:	00000000 */ 	sll	$zero,$zero,0x0
/*    4443c:	10000003 */ 	beqz	$zero,.L0004444c
/*    44440:	00001025 */ 	or	$v0,$zero,$zero
/*    44444:	10000001 */ 	beqz	$zero,.L0004444c
/*    44448:	00000000 */ 	sll	$zero,$zero,0x0
.L0004444c:
/*    4444c:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*    44450:	8fb00018 */ 	lw	$s0,0x18($sp)
/*    44454:	27bd0028 */ 	addiu	$sp,$sp,0x28
/*    44458:	03e00008 */ 	jr	$ra
/*    4445c:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func00044460
/*    44460:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*    44464:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    44468:	afa40020 */ 	sw	$a0,0x20($sp)
/*    4446c:	afa50024 */ 	sw	$a1,0x24($sp)
/*    44470:	afa60028 */ 	sw	$a2,0x28($sp)
/*    44474:	3c0e800a */ 	lui	$t6,%hi(var8009c3f4)
/*    44478:	8dcec3f4 */ 	lw	$t6,%lo(var8009c3f4)($t6)
/*    4447c:	afae001c */ 	sw	$t6,0x1c($sp)
/*    44480:	8faf001c */ 	lw	$t7,0x1c($sp)
/*    44484:	15e00003 */ 	bnez	$t7,.L00044494
/*    44488:	00000000 */ 	sll	$zero,$zero,0x0
/*    4448c:	10000027 */ 	beqz	$zero,.L0004452c
/*    44490:	00001025 */ 	or	$v0,$zero,$zero
.L00044494:
/*    44494:	8fb9001c */ 	lw	$t9,0x1c($sp)
/*    44498:	2418ffff */ 	addiu	$t8,$zero,-1
/*    4449c:	af38000c */ 	sw	$t8,0xc($t9)
/*    444a0:	8fa9001c */ 	lw	$t1,0x1c($sp)
/*    444a4:	2408ffff */ 	addiu	$t0,$zero,-1
/*    444a8:	ad280010 */ 	sw	$t0,0x10($t1)
/*    444ac:	8fab001c */ 	lw	$t3,0x1c($sp)
/*    444b0:	240affff */ 	addiu	$t2,$zero,-1
/*    444b4:	ad6a0014 */ 	sw	$t2,0x14($t3)
/*    444b8:	8fac0020 */ 	lw	$t4,0x20($sp)
/*    444bc:	8fad001c */ 	lw	$t5,0x1c($sp)
/*    444c0:	adac0000 */ 	sw	$t4,0x0($t5)
/*    444c4:	8fae0024 */ 	lw	$t6,0x24($sp)
/*    444c8:	8faf001c */ 	lw	$t7,0x1c($sp)
/*    444cc:	adee0004 */ 	sw	$t6,0x4($t7)
/*    444d0:	8fb80028 */ 	lw	$t8,0x28($sp)
/*    444d4:	8fb9001c */ 	lw	$t9,0x1c($sp)
/*    444d8:	af380008 */ 	sw	$t8,0x8($t9)
/*    444dc:	8fa8001c */ 	lw	$t0,0x1c($sp)
/*    444e0:	ad00201c */ 	sw	$zero,0x201c($t0)
/*    444e4:	8fa9001c */ 	lw	$t1,0x1c($sp)
/*    444e8:	ad202020 */ 	sw	$zero,0x2020($t1)
/*    444ec:	8faa001c */ 	lw	$t2,0x1c($sp)
/*    444f0:	ad403ba0 */ 	sw	$zero,0x3ba0($t2)
/*    444f4:	8fa4001c */ 	lw	$a0,0x1c($sp)
/*    444f8:	0c010fbe */ 	jal	func00043ef8
/*    444fc:	00002825 */ 	or	$a1,$zero,$zero
/*    44500:	8fab001c */ 	lw	$t3,0x1c($sp)
/*    44504:	25617fff */ 	addiu	$at,$t3,0x7fff
/*    44508:	ac200475 */ 	sw	$zero,0x475($at)
/*    4450c:	8fa4001c */ 	lw	$a0,0x1c($sp)
/*    44510:	24050900 */ 	addiu	$a1,$zero,0x900
/*    44514:	0c012c30 */ 	jal	bzero
/*    44518:	24846a64 */ 	addiu	$a0,$a0,0x6a64
/*    4451c:	10000003 */ 	beqz	$zero,.L0004452c
/*    44520:	8fa2001c */ 	lw	$v0,0x1c($sp)
/*    44524:	10000001 */ 	beqz	$zero,.L0004452c
/*    44528:	00000000 */ 	sll	$zero,$zero,0x0
.L0004452c:
/*    4452c:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    44530:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*    44534:	03e00008 */ 	jr	$ra
/*    44538:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0004453c
/*    4453c:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*    44540:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    44544:	afa40020 */ 	sw	$a0,0x20($sp)
/*    44548:	afa50024 */ 	sw	$a1,0x24($sp)
/*    4454c:	afa60028 */ 	sw	$a2,0x28($sp)
/*    44550:	8fae0020 */ 	lw	$t6,0x20($sp)
/*    44554:	afae001c */ 	sw	$t6,0x1c($sp)
/*    44558:	8faf001c */ 	lw	$t7,0x1c($sp)
/*    4455c:	8df83ba0 */ 	lw	$t8,0x3ba0($t7)
/*    44560:	27190001 */ 	addiu	$t9,$t8,0x1
/*    44564:	adf93ba0 */ 	sw	$t9,0x3ba0($t7)
/*    44568:	8fa8001c */ 	lw	$t0,0x1c($sp)
/*    4456c:	8d093ba0 */ 	lw	$t1,0x3ba0($t0)
/*    44570:	29210006 */ 	slti	$at,$t1,0x6
/*    44574:	14200003 */ 	bnez	$at,.L00044584
/*    44578:	00000000 */ 	sll	$zero,$zero,0x0
/*    4457c:	8faa001c */ 	lw	$t2,0x1c($sp)
/*    44580:	ad403ba0 */ 	sw	$zero,0x3ba0($t2)
.L00044584:
/*    44584:	8fab001c */ 	lw	$t3,0x1c($sp)
/*    44588:	25657fff */ 	addiu	$a1,$t3,0x7fff
/*    4458c:	8ca50475 */ 	lw	$a1,0x475($a1)
/*    44590:	0c010fbe */ 	jal	func00043ef8
/*    44594:	01602025 */ 	or	$a0,$t3,$zero
/*    44598:	14400006 */ 	bnez	$v0,.L000445b4
/*    4459c:	00000000 */ 	sll	$zero,$zero,0x0
/*    445a0:	240c0003 */ 	addiu	$t4,$zero,0x3
/*    445a4:	3c01800a */ 	lui	$at,%hi(var8009c3e0)
/*    445a8:	ac2cc3e0 */ 	sw	$t4,%lo(var8009c3e0)($at)
/*    445ac:	10000024 */ 	beqz	$zero,.L00044640
/*    445b0:	00001025 */ 	or	$v0,$zero,$zero
.L000445b4:
/*    445b4:	8fae001c */ 	lw	$t6,0x1c($sp)
/*    445b8:	240dffff */ 	addiu	$t5,$zero,-1
/*    445bc:	25c17fff */ 	addiu	$at,$t6,0x7fff
/*    445c0:	ac2d0475 */ 	sw	$t5,0x475($at)
/*    445c4:	8fb8001c */ 	lw	$t8,0x1c($sp)
/*    445c8:	27197fff */ 	addiu	$t9,$t8,0x7fff
/*    445cc:	8f390479 */ 	lw	$t9,0x479($t9)
/*    445d0:	03002025 */ 	or	$a0,$t8,$zero
/*    445d4:	0320f809 */ 	jalr	$t9
/*    445d8:	00000000 */ 	sll	$zero,$zero,0x0
/*    445dc:	afa20018 */ 	sw	$v0,0x18($sp)
/*    445e0:	8faf0018 */ 	lw	$t7,0x18($sp)
/*    445e4:	15e00003 */ 	bnez	$t7,.L000445f4
/*    445e8:	00000000 */ 	sll	$zero,$zero,0x0
/*    445ec:	10000010 */ 	beqz	$zero,.L00044630
/*    445f0:	00000000 */ 	sll	$zero,$zero,0x0
.L000445f4:
/*    445f4:	8fa8001c */ 	lw	$t0,0x1c($sp)
/*    445f8:	8fad0024 */ 	lw	$t5,0x24($sp)
/*    445fc:	8d093ba0 */ 	lw	$t1,0x3ba0($t0)
/*    44600:	000950c0 */ 	sll	$t2,$t1,0x3
/*    44604:	01495021 */ 	addu	$t2,$t2,$t1
/*    44608:	000a5100 */ 	sll	$t2,$t2,0x4
/*    4460c:	01495021 */ 	addu	$t2,$t2,$t1
/*    44610:	000a50c0 */ 	sll	$t2,$t2,0x3
/*    44614:	010a5821 */ 	addu	$t3,$t0,$t2
/*    44618:	256c2070 */ 	addiu	$t4,$t3,0x2070
/*    4461c:	adac0000 */ 	sw	$t4,0x0($t5)
/*    44620:	8fae001c */ 	lw	$t6,0x1c($sp)
/*    44624:	8fb90028 */ 	lw	$t9,0x28($sp)
/*    44628:	8dd83f8c */ 	lw	$t8,0x3f8c($t6)
/*    4462c:	af380000 */ 	sw	$t8,0x0($t9)
.L00044630:
/*    44630:	10000003 */ 	beqz	$zero,.L00044640
/*    44634:	8fa20018 */ 	lw	$v0,0x18($sp)
/*    44638:	10000001 */ 	beqz	$zero,.L00044640
/*    4463c:	00000000 */ 	sll	$zero,$zero,0x0
.L00044640:
/*    44640:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    44644:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*    44648:	03e00008 */ 	jr	$ra
/*    4464c:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func00044650
/*    44650:	27bdffd0 */ 	addiu	$sp,$sp,-48
/*    44654:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    44658:	afa40030 */ 	sw	$a0,0x30($sp)
/*    4465c:	afa50034 */ 	sw	$a1,0x34($sp)
/*    44660:	afa60038 */ 	sw	$a2,0x38($sp)
/*    44664:	afa7003c */ 	sw	$a3,0x3c($sp)
/*    44668:	240e0002 */ 	addiu	$t6,$zero,0x2
/*    4466c:	a7ae0020 */ 	sh	$t6,0x20($sp)
/*    44670:	afa00024 */ 	sw	$zero,0x24($sp)
/*    44674:	93af003b */ 	lbu	$t7,0x3b($sp)
/*    44678:	a3af0028 */ 	sb	$t7,0x28($sp)
/*    4467c:	93b8003f */ 	lbu	$t8,0x3f($sp)
/*    44680:	a3b80029 */ 	sb	$t8,0x29($sp)
/*    44684:	93b90043 */ 	lbu	$t9,0x43($sp)
/*    44688:	a3b9002a */ 	sb	$t9,0x2a($sp)
/*    4468c:	afa0002c */ 	sw	$zero,0x2c($sp)
/*    44690:	8fa80034 */ 	lw	$t0,0x34($sp)
/*    44694:	afa8001c */ 	sw	$t0,0x1c($sp)
/*    44698:	8fa40030 */ 	lw	$a0,0x30($sp)
/*    4469c:	27a50020 */ 	addiu	$a1,$sp,0x20
/*    446a0:	8fa6001c */ 	lw	$a2,0x1c($sp)
/*    446a4:	00003825 */ 	or	$a3,$zero,$zero
/*    446a8:	0c00f184 */ 	jal	func0003c610
/*    446ac:	24840048 */ 	addiu	$a0,$a0,0x48
/*    446b0:	10000001 */ 	beqz	$zero,.L000446b8
/*    446b4:	00000000 */ 	sll	$zero,$zero,0x0
.L000446b8:
/*    446b8:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    446bc:	27bd0030 */ 	addiu	$sp,$sp,0x30
/*    446c0:	03e00008 */ 	jr	$ra
/*    446c4:	00000000 */ 	sll	$zero,$zero,0x0
/*    446c8:	00000000 */ 	sll	$zero,$zero,0x0
/*    446cc:	00000000 */ 	sll	$zero,$zero,0x0
);