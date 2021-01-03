.data

.set VERSION_NTSC_BETA,  0
.set VERSION_NTSC_1_0,   1
.set VERSION_NTSC_FINAL, 2
.set VERSION_PAL_BETA,   3
.set VERSION_PAL_FINAL,  4
.set VERSION_JPN_FINAL,  5


.word 0x80371240 # Identifier
.word 0x0000000F # Clock rate
.word 0x80001000 # Program counter
.word 0x00001449 # Release address
.word 0x00000000 # CRC 1
.word 0x00000000 # CRC 2
.word 0x00000000
.word 0x00000000

.ascii "Perfect Dark        "
.word 0x00000000
.byte 0x00
.byte 0x00
.byte 0x00
.ascii "NPDE"

# Version
.if VERSION == VERSION_NTSC_BETA
	.byte 0x01
.elseif VERSION == VERSION_NTSC_FINAL
	.byte 0x01
.else
	.byte 0x00
.endif

