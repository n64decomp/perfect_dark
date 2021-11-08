#include <ultra64.h>
#include "constants.h"
#include "bss.h"
#include "lib/lib_43dd0.h"
#include "lib/lib_461c0.h"
#include "data.h"
#include "types.h"

extern struct mp3vars g_Mp3Vars;

u8 var8009c650[0x88];
u8 *var8009c6d8;
u8 *var8009c6dc;

u32 var8005f700 = 0;
u32 var8005f704 = 0;

s32 func00043dd0(struct asistream *stream)
{
	s32 sp1c = 0x1000;
	s32 sp18;

	if (stream->unk201c + stream->unk3f88 > 0x1ffb) {
		bcopy(&stream->unk1c[sp1c], &stream->unk1c, sp1c);
		stream->unk201c -= sp1c;
		stream->unk2020 -= sp1c * 8;
	}

	sp18 = stream->unk04(stream->unk00, &stream->unk1c[stream->unk201c], stream->unk3f88, -1);

	if (sp18 < stream->unk3f88) {
		bzero(&stream->unk1c[sp18], stream->unk3f88 - sp18);
	}

	stream->unk18 += stream->unk3f88;
	stream->unk201c += stream->unk3f88;

	return stream->unk201c - stream->unk3f88;
}

GLOBAL_ASM(
glabel func00043ef8
/*    43ef8:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*    43efc:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    43f00:	afa40028 */ 	sw	$a0,0x28($sp)
/*    43f04:	afa5002c */ 	sw	$a1,0x2c($sp)
/*    43f08:	8fae002c */ 	lw	$t6,0x2c($sp)
/*    43f0c:	2401ffff */ 	addiu	$at,$zero,-1
/*    43f10:	11c10004 */ 	beq	$t6,$at,.L00043f24
/*    43f14:	00000000 */ 	nop
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
/*    43f68:	00000000 */ 	nop
/*    43f6c:	10000121 */ 	b	.L000443f4
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
/*    43fa8:	00000000 */ 	nop
/*    43fac:	240c00ff */ 	addiu	$t4,$zero,0xff
/*    43fb0:	a3ac001b */ 	sb	$t4,0x1b($sp)
/*    43fb4:	afa00020 */ 	sw	$zero,0x20($sp)
/*    43fb8:	1000000c */ 	b	.L00043fec
/*    43fbc:	00000000 */ 	nop
.L00043fc0:
/*    43fc0:	8fae0020 */ 	lw	$t6,0x20($sp)
/*    43fc4:	25cf0001 */ 	addiu	$t7,$t6,0x1
/*    43fc8:	afaf0020 */ 	sw	$t7,0x20($sp)
/*    43fcc:	93ad001b */ 	lbu	$t5,0x1b($sp)
/*    43fd0:	240100f0 */ 	addiu	$at,$zero,0xf0
/*    43fd4:	15a10003 */ 	bne	$t5,$at,.L00043fe4
/*    43fd8:	00000000 */ 	nop
/*    43fdc:	10000005 */ 	b	.L00043ff4
/*    43fe0:	00000000 */ 	nop
.L00043fe4:
/*    43fe4:	241800f0 */ 	addiu	$t8,$zero,0xf0
/*    43fe8:	a3b8001b */ 	sb	$t8,0x1b($sp)
.L00043fec:
/*    43fec:	1000ffd2 */ 	b	.L00043f38
/*    43ff0:	00000000 */ 	nop
.L00043ff4:
/*    43ff4:	8fa80028 */ 	lw	$t0,0x28($sp)
/*    43ff8:	24060002 */ 	addiu	$a2,$zero,0x2
/*    43ffc:	2407ffff */ 	addiu	$a3,$zero,-1
/*    44000:	8d190004 */ 	lw	$t9,0x4($t0)
/*    44004:	8d040000 */ 	lw	$a0,0x0($t0)
/*    44008:	25052026 */ 	addiu	$a1,$t0,0x2026
/*    4400c:	0320f809 */ 	jalr	$t9
/*    44010:	00000000 */ 	nop
/*    44014:	afa2001c */ 	sw	$v0,0x1c($sp)
/*    44018:	8faa001c */ 	lw	$t2,0x1c($sp)
/*    4401c:	1d400003 */ 	bgtz	$t2,.L0004402c
/*    44020:	00000000 */ 	nop
/*    44024:	100000f3 */ 	b	.L000443f4
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
/*    441a8:	00000000 */ 	nop
/*    441ac:	8d4c3bb4 */ 	lw	$t4,0x3bb4($t2)
/*    441b0:	24010003 */ 	addiu	$at,$zero,0x3
/*    441b4:	15810006 */ 	bne	$t4,$at,.L000441d0
/*    441b8:	00000000 */ 	nop
.L000441bc:
/*    441bc:	8fa40028 */ 	lw	$a0,0x28($sp)
/*    441c0:	0c010fbe */ 	jal	func00043ef8
/*    441c4:	2405ffff */ 	addiu	$a1,$zero,-1
/*    441c8:	1000008a */ 	b	.L000443f4
/*    441cc:	00000000 */ 	nop
.L000441d0:
/*    441d0:	8fa90028 */ 	lw	$t1,0x28($sp)
/*    441d4:	8d2e3bd4 */ 	lw	$t6,0x3bd4($t1)
/*    441d8:	15c0001a */ 	bnez	$t6,.L00044244
/*    441dc:	00000000 */ 	nop
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
/*    4423c:	1000001f */ 	b	.L000442bc
/*    44240:	ad793bf0 */ 	sw	$t9,0x3bf0($t3)
.L00044244:
/*    44244:	8fac0028 */ 	lw	$t4,0x28($sp)
/*    44248:	8d8a3ba4 */ 	lw	$t2,0x3ba4($t4)
/*    4424c:	8d8e3bd8 */ 	lw	$t6,0x3bd8($t4)
/*    44250:	154e0015 */ 	bne	$t2,$t6,.L000442a8
/*    44254:	00000000 */ 	nop
/*    44258:	8d893ba8 */ 	lw	$t1,0x3ba8($t4)
/*    4425c:	8d8d3bdc */ 	lw	$t5,0x3bdc($t4)
/*    44260:	152d0011 */ 	bne	$t1,$t5,.L000442a8
/*    44264:	00000000 */ 	nop
/*    44268:	8d8f3bac */ 	lw	$t7,0x3bac($t4)
/*    4426c:	8d983be0 */ 	lw	$t8,0x3be0($t4)
/*    44270:	15f8000d */ 	bne	$t7,$t8,.L000442a8
/*    44274:	00000000 */ 	nop
/*    44278:	8d883bb4 */ 	lw	$t0,0x3bb4($t4)
/*    4427c:	8d993be4 */ 	lw	$t9,0x3be4($t4)
/*    44280:	15190009 */ 	bne	$t0,$t9,.L000442a8
/*    44284:	00000000 */ 	nop
/*    44288:	8d8b3bc0 */ 	lw	$t3,0x3bc0($t4)
/*    4428c:	8d8a3be8 */ 	lw	$t2,0x3be8($t4)
/*    44290:	156a0005 */ 	bne	$t3,$t2,.L000442a8
/*    44294:	00000000 */ 	nop
/*    44298:	8d8e3bcc */ 	lw	$t6,0x3bcc($t4)
/*    4429c:	8d893bf0 */ 	lw	$t1,0x3bf0($t4)
/*    442a0:	11c90006 */ 	beq	$t6,$t1,.L000442bc
/*    442a4:	00000000 */ 	nop
.L000442a8:
/*    442a8:	8fa40028 */ 	lw	$a0,0x28($sp)
/*    442ac:	0c010fbe */ 	jal	func00043ef8
/*    442b0:	2405ffff */ 	addiu	$a1,$zero,-1
/*    442b4:	1000004f */ 	b	.L000443f4
/*    442b8:	00000000 */ 	nop
.L000442bc:
/*    442bc:	8faf0028 */ 	lw	$t7,0x28($sp)
/*    442c0:	240d0004 */ 	addiu	$t5,$zero,0x4
/*    442c4:	aded2068 */ 	sw	$t5,0x2068($t7)
/*    442c8:	8fb80028 */ 	lw	$t8,0x28($sp)
/*    442cc:	8f083bac */ 	lw	$t0,0x3bac($t8)
/*    442d0:	1500001a */ 	bnez	$t0,.L0004433c
/*    442d4:	00000000 */ 	nop
/*    442d8:	8fb90028 */ 	lw	$t9,0x28($sp)
/*    442dc:	24060002 */ 	addiu	$a2,$zero,0x2
/*    442e0:	2407ffff */ 	addiu	$a3,$zero,-1
/*    442e4:	8f240000 */ 	lw	$a0,0x0($t9)
/*    442e8:	27252028 */ 	addiu	$a1,$t9,0x2028
/*    442ec:	8f390004 */ 	lw	$t9,0x4($t9)
/*    442f0:	0320f809 */ 	jalr	$t9
/*    442f4:	00000000 */ 	nop
/*    442f8:	afa2001c */ 	sw	$v0,0x1c($sp)
/*    442fc:	8fab001c */ 	lw	$t3,0x1c($sp)
/*    44300:	1d600003 */ 	bgtz	$t3,.L00044310
/*    44304:	00000000 */ 	nop
/*    44308:	1000003a */ 	b	.L000443f4
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
/*    4434c:	00000000 */ 	nop
/*    44350:	8fae0028 */ 	lw	$t6,0x28($sp)
/*    44354:	3c0c7004 */ 	lui	$t4,%hi(func0004371c)
/*    44358:	258c371c */ 	addiu	$t4,$t4,%lo(func0004371c)
/*    4435c:	25c17fff */ 	addiu	$at,$t6,0x7fff
/*    44360:	ac2c0479 */ 	sw	$t4,0x479($at)
/*    44364:	8fad0028 */ 	lw	$t5,0x28($sp)
/*    44368:	3c0a7004 */ 	lui	$t2,%hi(func00042e38)
/*    4436c:	254a2e38 */ 	addiu	$t2,$t2,%lo(func00042e38)
/*    44370:	25a17fff */ 	addiu	$at,$t5,0x7fff
/*    44374:	10000011 */ 	b	.L000443bc
/*    44378:	ac2a047d */ 	sw	$t2,0x47d($at)
.L0004437c:
/*    4437c:	8faf0028 */ 	lw	$t7,0x28($sp)
/*    44380:	24010002 */ 	addiu	$at,$zero,0x2
/*    44384:	8de93ba8 */ 	lw	$t1,0x3ba8($t7)
/*    44388:	15210005 */ 	bne	$t1,$at,.L000443a0
/*    4438c:	00000000 */ 	nop
/*    44390:	10000018 */ 	b	.L000443f4
/*    44394:	00001025 */ 	or	$v0,$zero,$zero
/*    44398:	10000008 */ 	b	.L000443bc
/*    4439c:	00000000 */ 	nop
.L000443a0:
/*    443a0:	8fb80028 */ 	lw	$t8,0x28($sp)
/*    443a4:	24010003 */ 	addiu	$at,$zero,0x3
/*    443a8:	8f083ba8 */ 	lw	$t0,0x3ba8($t8)
/*    443ac:	15010003 */ 	bne	$t0,$at,.L000443bc
/*    443b0:	00000000 */ 	nop
/*    443b4:	1000000f */ 	b	.L000443f4
/*    443b8:	00001025 */ 	or	$v0,$zero,$zero
.L000443bc:
/*    443bc:	8fb90028 */ 	lw	$t9,0x28($sp)
/*    443c0:	03202025 */ 	or	$a0,$t9,$zero
/*    443c4:	27217fff */ 	addiu	$at,$t9,0x7fff
/*    443c8:	8c39047d */ 	lw	$t9,0x47d($at)
/*    443cc:	0320f809 */ 	jalr	$t9
/*    443d0:	00000000 */ 	nop
/*    443d4:	14400003 */ 	bnez	$v0,.L000443e4
/*    443d8:	00000000 */ 	nop
/*    443dc:	10000005 */ 	b	.L000443f4
/*    443e0:	00001025 */ 	or	$v0,$zero,$zero
.L000443e4:
/*    443e4:	10000003 */ 	b	.L000443f4
/*    443e8:	24020001 */ 	addiu	$v0,$zero,0x1
/*    443ec:	10000001 */ 	b	.L000443f4
/*    443f0:	00000000 */ 	nop
.L000443f4:
/*    443f4:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    443f8:	27bd0028 */ 	addiu	$sp,$sp,0x28
/*    443fc:	03e00008 */ 	jr	$ra
/*    44400:	00000000 */ 	nop
);

u32 func00044404(void)
{
	if (var8005f704++) {
		return 2;
	}

	func0003f8a0();
	return 0;
}

struct asistream *func00044460(s32 arg0, void *arg1, s32 arg2)
{
	struct asistream *stream = g_AsiStream;

	if (stream == NULL) {
		return NULL;
	}

	stream->unk0c = -1;
	stream->unk10 = -1;
	stream->unk14 = -1;

	stream->unk00 = arg0;
	stream->unk04 = arg1;
	stream->unk08 = arg2;

	stream->unk201c = 0;
	stream->unk2020 = 0;
	stream->unk3ba0 = 0;

	func00043ef8(stream, 0);

	stream->unk8474 = 0;

	bzero(&stream->unk6a64, sizeof(stream->unk6a64));

	return stream;
}

s32 func0004453c(struct asistream *streamptr, struct mp3thing **arg1, s32 *arg2)
{
	struct asistream *stream = streamptr;
	s32 result;

	stream->unk3ba0++;

	if (stream->unk3ba0 > 5) {
		stream->unk3ba0 = 0;
	}

	if (!func00043ef8(stream, stream->unk8474)) {
		g_Mp3Vars.var8009c3e0 = 3;
		return 0;
	}

	stream->unk8474 = -1;

	result = stream->unk8478(stream);

	if (!result) {
		// empty
	} else {
		*arg1 = &stream->unk2070[stream->unk3ba0];
		*arg2 = stream->unk3f8c;
	}

	return result;
}
