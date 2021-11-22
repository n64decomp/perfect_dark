.rsp

// flags

OS_TASK_DP_WAIT         equ 0x0002

// rdp rd flags
DPC_STATUS_XBUS_DMA     equ 0x0001
DPC_STATUS_DMA_BUSY     equ 0x0100
DPC_STATUS_START_VALID  equ 0x0400

// rdp wr flags
DPC_STATUS_CLR_XBUS     equ 0x0001

// sp status flags
SP_STATUS_SET_SIG7      equ 0x4000

.macro jumpTableEntry, addr
    .dh addr & 0xffff
.endmacro

.macro OverlayEntry, loadStart, loadEnd, imemAddr
    .dw loadStart
    .dh (loadEnd - loadStart - 1) & 0xffff
    .dh (imemAddr) & 0xffff
.endmacro

.create DATA_FILE, 0x0000

// 0x0000
data_0000: // overlay 0
    OverlayEntry orga(Overlay0Address), orga(Overlay0End), Overlay0Address
// 0x0008
data_0008: // overlay 1
    OverlayEntry orga(Overlay1Address), orga(Overlay1End) + 0x10, Overlay1Address

Overlay0DataLoadAddress:
Overlay1DataLoadAddress:

// OVERLAY 0 DATA
Overlay0DataStart:

// 0x0010
dispatchTable:
    jumpTableEntry cmd_DISABLE
    jumpTableEntry cmd_ADPCM
    jumpTableEntry cmd_CLEARBUFF
    jumpTableEntry cmd_ENVMIXER
    jumpTableEntry cmd_LOADBUFF
    jumpTableEntry cmd_RESAMPLE
    jumpTableEntry cmd_SAVEBUFF
    jumpTableEntry cmd_MP3
    jumpTableEntry cmd_MP3ADDY
    jumpTableEntry cmd_SETVOL
    jumpTableEntry cmd_DMEMMOVE
    jumpTableEntry cmd_LOADADPCM
    jumpTableEntry cmd_MIXER
    jumpTableEntry cmd_INTERLEAVE
    jumpTableEntry cmd_16EC
    jumpTableEntry cmd_SETLOOP

// 0x0030
data_0_0030:
.dh 0xf000, 0x0f00, 0x00f0, 0x000f, 0x0001, 0x0010, 0x0100, 0x1000

// 0x0040
data_0_0040:
.dh 0x0002, 0x0004, 0x0006, 0x0008, 0x000a, 0x000c, 0x000e, 0x0010

// 0x0050
data_0_0050:
.dh 0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 0x0001

// 0x0060
data_0_0060:
.dh 0x0000, 0x0020, 0x0002, 0x0800, 0x0008, 0x7fff, 0x0100, 0x0200

// 0x0070
data_0_0070:
.dh 0x0001, 0x0000, 0x0000, 0x0000, 0x0001, 0x0000, 0x0000, 0x0000

// 0x0080
data_0_0080:
.dh 0x0000, 0x0001, 0x0000, 0x0000, 0x0000, 0x0001, 0x0000, 0x0000

// 0x0090
data_0_0090:
.dh 0x0000, 0x0000, 0x0001, 0x0000, 0x0000, 0x0000, 0x0001, 0x0000

// 0x00a0
data_0_00A0:
.dh 0x0000, 0x0000, 0x0000, 0x0001, 0x0000, 0x0000, 0x0000, 0x0001

// 0x00b0
data_0_00B0:
.dh 0x2000, 0x4000, 0x6000, 0x8000, 0xa000, 0xc000, 0xe000, 0xffff

// 0x00c0
data_0_00C0:
.word 0x0c3966ad, 0x0d46ffdf, 0x0b396696, 0x0e5fffd8, 0x0a446669, 0x0f83ffd0, 0x095a6626, 0x10b4ffc8
.word 0x087d65cd, 0x11f0ffbf, 0x07ab655e, 0x1338ffb6, 0x06e464d9, 0x148cffac, 0x0628643f, 0x15ebffa1
.word 0x0577638f, 0x1756ff96, 0x04d162cb, 0x18cbff8a, 0x043561f3, 0x1a4cff7e, 0x03a46106, 0x1bd7ff71
.word 0x031c6007, 0x1d6cff64, 0x029f5ef5, 0x1f0bff56, 0x022a5dd0, 0x20b3ff48, 0x01be5c9a, 0x2264ff3a
.word 0x015b5b53, 0x241eff2c, 0x010159fc, 0x25e0ff1e, 0x00ae5896, 0x27a9ff10, 0x00635720, 0x297aff02
.word 0x001f559d, 0x2b50fef4, 0xffe2540d, 0x2d2cfee8, 0xffac5270, 0x2f0dfedb, 0xff7c50c7, 0x30f3fed0
.word 0xff534f14, 0x32dcfec6, 0xff2e4d57, 0x34c8febd, 0xff0f4b91, 0x36b6feb6, 0xfef549c2, 0x38a5feb0
.word 0xfedf47ed, 0x3a95feac, 0xfece4611, 0x3c85feab, 0xfec04430, 0x3e74feac, 0xfeb6424a, 0x4060feaf
.word 0xfeaf4060, 0x424afeb6, 0xfeac3e74, 0x4430fec0, 0xfeab3c85, 0x4611fece, 0xfeac3a95, 0x47edfedf
.word 0xfeb038a5, 0x49c2fef5, 0xfeb636b6, 0x4b91ff0f, 0xfebd34c8, 0x4d57ff2e, 0xfec632dc, 0x4f14ff53
.word 0xfed030f3, 0x50c7ff7c, 0xfedb2f0d, 0x5270ffac, 0xfee82d2c, 0x540dffe2, 0xfef42b50, 0x559d001f
.word 0xff02297a, 0x57200063, 0xff1027a9, 0x589600ae, 0xff1e25e0, 0x59fc0101, 0xff2c241e, 0x5b53015b
.word 0xff3a2264, 0x5c9a01be, 0xff4820b3, 0x5dd0022a, 0xff561f0b, 0x5ef5029f, 0xff641d6c, 0x6007031c
.word 0xff711bd7, 0x610603a4, 0xff7e1a4c, 0x61f30435, 0xff8a18cb, 0x62cb04d1, 0xff961756, 0x638f0577
.word 0xffa115eb, 0x643f0628, 0xffac148c, 0x64d906e4, 0xffb61338, 0x655e07ab, 0xffbf11f0, 0x65cd087d
.word 0xffc810b4, 0x6626095a, 0xffd00f83, 0x66690a44, 0xffd80e5f, 0x66960b39, 0xffdf0d46, 0x66ad0c39

Overlay0DataEnd:

// OVERLAY 1 DATA
.headersize Overlay1DataLoadAddress - orga()
Overlay1DataStart:

// 0x0010
data_1_0010:
.dh 0xfec4, 0xfb14, 0xf4fa, 0xec84, 0xe1c4, 0xd4dc, 0xc5e4, 0xa268

// 0x0020
data_1_0020:
.dh 0x8e3a, 0x78ae, 0x61f8, 0x4a50, 0x31f2, 0x1916, 0x8000, 0x0000

// 0x0030
data_1_0030:
.dh 0xffb2, 0xfd3a, 0xf854, 0xf10a, 0xe76c, 0xdb94, 0xcda0, 0xbdae

// 0x0040
data_1_0040:
.dh 0xabec, 0x9880, 0x839c, 0xdae8, 0xac7c, 0x7c68, 0x4b20, 0x1920

// 0x0050
data_1_0050:
.dh 0xb504, 0xa57e, 0x0001, 0x6a09, 0x0002, 0xd413, 0x0005, 0xa827

// 0x0060
// ?
.dh 0x0000, 0xfff3, 0x005d, 0xff38, 0x037a, 0xf736, 0x0b37, 0xc00e
.dh 0x7fff, 0x3ff2, 0x0b37, 0x08ca, 0x037a, 0x00c8, 0x005d, 0x000d

// 0x0080
DeWindowLUT:
.word 0x0000fff3, 0x005dff38, 0x037af736, 0x0b37c00e, 0x7fff3ff2, 0x0b3708ca, 0x037a00c8, 0x005d000d
.word 0x0000fff2, 0x005fff1d, 0x0369f697, 0x0a2abce7, 0x7feb3ccb, 0x0c2b082b, 0x038500af, 0x005b000b
.word 0x0000fff2, 0x005fff1d, 0x0369f697, 0x0a2abce7, 0x7feb3ccb, 0x0c2b082b, 0x038500af, 0x005b000b
.word 0x0000fff1, 0x0061ff02, 0x0354f5f9, 0x0905b9c4, 0x7fb039a4, 0x0d08078c, 0x038c0098, 0x0058000a
.word 0x0000fff1, 0x0061ff02, 0x0354f5f9, 0x0905b9c4, 0x7fb039a4, 0x0d08078c, 0x038c0098, 0x0058000a
.word 0x0000ffef, 0x0062fee6, 0x033bf55c, 0x07c8b6a4, 0x7f4d367e, 0x0dce06ee, 0x038f0080, 0x00560009
.word 0x0000ffef, 0x0062fee6, 0x033bf55c, 0x07c8b6a4, 0x7f4d367e, 0x0dce06ee, 0x038f0080, 0x00560009
.word 0x0000ffee, 0x0063feca, 0x031cf4c3, 0x0671b38c, 0x7ec2335d, 0x0e7c0652, 0x038e006b, 0x00530008
.word 0x0000ffee, 0x0063feca, 0x031cf4c3, 0x0671b38c, 0x7ec2335d, 0x0e7c0652, 0x038e006b, 0x00530008
.word 0x0000ffec, 0x0064feac, 0x02f7f42c, 0x0502b07c, 0x7e123041, 0x0f1405b7, 0x038a0056, 0x00500007
.word 0x0000ffec, 0x0064feac, 0x02f7f42c, 0x0502b07c, 0x7e123041, 0x0f1405b7, 0x038a0056, 0x00500007
.word 0x0000ffeb, 0x0064fe8e, 0x02cef399, 0x037aad75, 0x7d3a2d2c, 0x0f970520, 0x03820043, 0x004d0007
.word 0x0000ffeb, 0x0064fe8e, 0x02cef399, 0x037aad75, 0x7d3a2d2c, 0x0f970520, 0x03820043, 0x004d0007
.word 0xffffffe9, 0x0063fe6f, 0x029ef30b, 0x01d8aa7b, 0x7c3d2a1f, 0x1004048b, 0x03770030, 0x004a0006
.word 0xffffffe9, 0x0063fe6f, 0x029ef30b, 0x01d8aa7b, 0x7c3d2a1f, 0x1004048b, 0x03770030, 0x004a0006
.word 0xffffffe7, 0x0062fe4f, 0x0269f282, 0x001fa78d, 0x7b1a271c, 0x105d03f9, 0x036a001f, 0x00460006
.word 0xffffffe7, 0x0062fe4f, 0x0269f282, 0x001fa78d, 0x7b1a271c, 0x105d03f9, 0x036a001f, 0x00460006
.word 0xffffffe4, 0x0061fe2f, 0x022ff1ff, 0xfe4ca4af, 0x79d32425, 0x10a2036c, 0x03590010, 0x00430005
.word 0xffffffe4, 0x0061fe2f, 0x022ff1ff, 0xfe4ca4af, 0x79d32425, 0x10a2036c, 0x03590010, 0x00430005
.word 0xffffffe2, 0x005efe10, 0x01eef184, 0xfc61a1e1, 0x78692139, 0x10d302e3, 0x03460001, 0x00400004
.word 0xffffffe2, 0x005efe10, 0x01eef184, 0xfc61a1e1, 0x78692139, 0x10d302e3, 0x03460001, 0x00400004
.word 0xffffffe0, 0x005bfdf0, 0x01a8f111, 0xfa5f9f27, 0x76db1e5c, 0x10f2025e, 0x0331fff3, 0x003d0004
.word 0xffffffe0, 0x005bfdf0, 0x01a8f111, 0xfa5f9f27, 0x76db1e5c, 0x10f2025e, 0x0331fff3, 0x003d0004
.word 0xffffffde, 0x0057fdd0, 0x015bf0a7, 0xf8459c80, 0x752c1b8e, 0x110001de, 0x0319ffe7, 0x003a0003
.word 0xffffffde, 0x0057fdd0, 0x015bf0a7, 0xf8459c80, 0x752c1b8e, 0x110001de, 0x0319ffe7, 0x003a0003
.word 0xfffeffdb, 0x0053fdb0, 0x0108f046, 0xf61399ee, 0x735c18d1, 0x10fd0163, 0x0300ffdc, 0x00370003
.word 0xfffeffdb, 0x0053fdb0, 0x0108f046, 0xf61399ee, 0x735c18d1, 0x10fd0163, 0x0300ffdc, 0x00370003
.word 0xfffeffd8, 0x004dfd90, 0x00b0eff0, 0xf3cc9775, 0x716c1624, 0x10ea00ee, 0x02e5ffd2, 0x00330003
.word 0xfffeffd8, 0x004dfd90, 0x00b0eff0, 0xf3cc9775, 0x716c1624, 0x10ea00ee, 0x02e5ffd2, 0x00330003
.word 0xfffeffd6, 0x0047fd72, 0x0051efa6, 0xf16f9514, 0x6f5e138a, 0x10c8007e, 0x02caffc9, 0x00300003
.word 0xfffeffd6, 0x0047fd72, 0x0051efa6, 0xf16f9514, 0x6f5e138a, 0x10c8007e, 0x02caffc9, 0x00300003
.word 0xfffeffd3, 0x0040fd54, 0xffecef68, 0xeefc92cd, 0x6d331104, 0x10980014, 0x02acffc0, 0x002d0002
.word 0xfffeffd3, 0x0040fd54, 0xffecef68, 0xeefc92cd, 0x6d331104, 0x10980014, 0x02acffc0, 0x002d0002
.word 0x0030ffc9, 0x02ca007e, 0x10c8138a, 0x6f5e9514, 0xf16fefa6, 0x0051fd72, 0x0047ffd6, 0xfffe0003
.word 0x0030ffc9, 0x02ca007e, 0x10c8138a, 0x6f5e9514, 0xf16fefa6, 0x0051fd72, 0x0047ffd6, 0xfffe0003
.word 0x0033ffd2, 0x02e500ee, 0x10ea1624, 0x716c9775, 0xf3cceff0, 0x00b0fd90, 0x004dffd8, 0xfffe0003
.word 0x0033ffd2, 0x02e500ee, 0x10ea1624, 0x716c9775, 0xf3cceff0, 0x00b0fd90, 0x004dffd8, 0xfffe0003
.word 0x0037ffdc, 0x03000163, 0x10fd18d1, 0x735c99ee, 0xf613f046, 0x0108fdb0, 0x0053ffdb, 0xfffe0003
.word 0x0037ffdc, 0x03000163, 0x10fd18d1, 0x735c99ee, 0xf613f046, 0x0108fdb0, 0x0053ffdb, 0xfffe0003
.word 0x003affe7, 0x031901de, 0x11001b8e, 0x752c9c80, 0xf845f0a7, 0x015bfdd0, 0x0057ffde, 0xffff0003
.word 0x003affe7, 0x031901de, 0x11001b8e, 0x752c9c80, 0xf845f0a7, 0x015bfdd0, 0x0057ffde, 0xffff0004
.word 0x003dfff3, 0x0331025e, 0x10f21e5c, 0x76db9f27, 0xfa5ff111, 0x01a8fdf0, 0x005bffe0, 0xffff0004
.word 0x003dfff3, 0x0331025e, 0x10f21e5c, 0x76db9f27, 0xfa5ff111, 0x01a8fdf0, 0x005bffe0, 0xffff0004
.word 0x00400001, 0x034602e3, 0x10d32139, 0x7869a1e1, 0xfc61f184, 0x01eefe10, 0x005effe2, 0xffff0004
.word 0x00400001, 0x034602e3, 0x10d32139, 0x7869a1e1, 0xfc61f184, 0x01eefe10, 0x005effe2, 0xffff0005
.word 0x00430010, 0x0359036c, 0x10a22425, 0x79d3a4af, 0xfe4cf1ff, 0x022ffe2f, 0x0061ffe4, 0xffff0005
.word 0x00430010, 0x0359036c, 0x10a22425, 0x79d3a4af, 0xfe4cf1ff, 0x022ffe2f, 0x0061ffe4, 0xffff0006
.word 0x0046001f, 0x036a03f9, 0x105d271c, 0x7b1aa78d, 0x001ff282, 0x0269fe4f, 0x0062ffe7, 0xffff0006
.word 0x0046001f, 0x036a03f9, 0x105d271c, 0x7b1aa78d, 0x001ff282, 0x0269fe4f, 0x0062ffe7, 0xffff0006
.word 0x004a0030, 0x0377048b, 0x10042a1f, 0x7c3daa7b, 0x01d8f30b, 0x029efe6f, 0x0063ffe9, 0xffff0006
.word 0x004a0030, 0x0377048b, 0x10042a1f, 0x7c3daa7b, 0x01d8f30b, 0x029efe6f, 0x0063ffe9, 0xffff0007
.word 0x004d0043, 0x03820520, 0x0f972d2c, 0x7d3aad75, 0x037af399, 0x02cefe8e, 0x0064ffeb, 0x00000007
.word 0x004d0043, 0x03820520, 0x0f972d2c, 0x7d3aad75, 0x037af399, 0x02cefe8e, 0x0064ffeb, 0x00000007
.word 0x00500056, 0x038a05b7, 0x0f143041, 0x7e12b07c, 0x0502f42c, 0x02f7feac, 0x0064ffec, 0x00000007
.word 0x00500056, 0x038a05b7, 0x0f143041, 0x7e12b07c, 0x0502f42c, 0x02f7feac, 0x0064ffec, 0x00000008
.word 0x0053006b, 0x038e0652, 0x0e7c335d, 0x7ec2b38c, 0x0671f4c3, 0x031cfeca, 0x0063ffee, 0x00000008
.word 0x0053006b, 0x038e0652, 0x0e7c335d, 0x7ec2b38c, 0x0671f4c3, 0x031cfeca, 0x0063ffee, 0x00000009
.word 0x00560080, 0x038f06ee, 0x0dce367e, 0x7f4db6a4, 0x07c8f55c, 0x033bfee6, 0x0062ffef, 0x00000009
.word 0x00560080, 0x038f06ee, 0x0dce367e, 0x7f4db6a4, 0x07c8f55c, 0x033bfee6, 0x0062ffef, 0x0000000a
.word 0x00580098, 0x038c078c, 0x0d0839a4, 0x7fb0b9c4, 0x0905f5f9, 0x0354ff02, 0x0061fff1, 0x0000000a
.word 0x00580098, 0x038c078c, 0x0d0839a4, 0x7fb0b9c4, 0x0905f5f9, 0x0354ff02, 0x0061fff1, 0x0000000b
.word 0x005b00af, 0x0385082b, 0x0c2b3ccb, 0x7febbce7, 0x0a2af697, 0x0369ff1d, 0x005ffff2, 0x0000000b
.word 0x005b00af, 0x0385082b, 0x0c2b3ccb, 0x7febbce7, 0x0a2af697, 0x0369ff1d, 0x005ffff2, 0x0000000d
.word 0x005d00c8, 0x037a08ca, 0x0b373ff2, 0x7fffc00e, 0x0b37f736, 0x037aff38, 0x005dfff3, 0x0000000d
.word 0x005d00c8, 0x037a08ca, 0x0b373ff2, 0x7fffc00e, 0x0b37f736, 0x037aff38, 0x005dfff3, 0x00000000

Overlay1DataEnd:

// OVERLAY 0 BSS
.headersize Overlay0DataEnd - orga()
Overlay0BssStart:

// 0x02c0
nextTaskEntry_len equ 0x140
nextTaskEntry:
    .skip 0x140

// 0x0400
adpcmTable:
    .skip 0x100

// 0x0500
data_0_0500:
    .skip 0x170

// 0x0670
data_0_0670:
    .skip 0x370

// 0x09e0
data_0_09E0:
    .skip 0x170

// 0x0b50
data_0_0B50:
    .skip 0x170

// 0x0cc0
data_0_0CC0:
    .skip 0x170

// 0x0e30
data_0_0E30:
    .skip 0x180

// 0x0fb0
data_0_0FB0_neg equ -(0x1000 - data_0_0FB0)
data_0_0FB0:
    .skip 0x10

// 0xfc0
data_0_0FC0_neg equ -(0x1000 - data_0_0FC0)
data_0_0FC0:
    .skip 0x30

Overlay0BssEnd:

.if Overlay0BssEnd > 0x1000-0x10
    .error "Not enough room in DMEM"
.endif

// OVERLAY 1 BSS
.headersize Overlay1DataEnd - orga()
Overlay1BssStart:

// 0x08a0
data_1_08A0:
    .skip 0x448

// 0x0ce8
data_1_0CE8:
    .skip 0x8

// 0x0cf0
data_1_0CF0:
    .skip 0x180

// 0x0e70
data_1_0E70:
    .skip 0x180

Overlay1BssEnd:

.if Overlay1BssEnd > 0x1000-0x10
    .error "Not enough room in DMEM"
.endif

// Shared bss

// 0x0ff0
audioStruct_0 equ 0x0
audioStruct_4 equ 0x4
audioStruct_8 equ 0x8
audioStruct_C equ 0xc
audioStruct:
    .skip 0x10

.close

.create CODE_FILE, 0x04001080

// Register names
cmd_w0 equ k0
cmd_w1 equ t9

// OVERLAY 0
Overlay0Address:

// on entry from rspboot, at contains a pointer to the OSTask
entry:
/* 04001080 000000 40055800 */  mfc0    a1, DPC_STATUS
/* 04001084 000004 8C3C0030 */  lw      gp, 0x30(at)                   // task_data
/* 04001088 000008 8C3B0034 */  lw      k1, 0x34(at)                   // task_data_size
/* 0400108C 00000C 30A40001 */  andi    a0, a1, DPC_STATUS_XBUS_DMA
/* 04001090 000010 10800006 */  beqz    a0, no_dma
/* 04001094 000014 30A40100 */   andi   a0, a1, DPC_STATUS_DMA_BUSY
/* 04001098 000018 10800004 */  beqz    a0, no_dma
/* 0400109C 00001C 40045800 */   mfc0   a0, DPC_STATUS
dpc_dma_busy:
/* 040010A0 000020 30840100 */  andi    a0, a0, DPC_STATUS_DMA_BUSY
/* 040010A4 000024 1C80FFFE */  bgtz    a0, dpc_dma_busy
/* 040010A8 000028 40045800 */   mfc0   a0, DPC_STATUS
no_dma:
/* 040010AC 00002C 20180FA0 */  addi    t8, zero, 0xfa0
/* 040010B0 000030 8C250010 */  lw      a1, 0x10(at)                    // ucode dram addr
/* 040010B4 000034 8C040000 */  lw      a0, (data_0000)(zero)          // overlay 0 start
/* 040010B8 000038 00852020 */  add     a0, a0, a1                      // convert overlay 0 start to dram addr
/* 040010BC 00003C AC040000 */  sw      a0, (data_0000)(zero)
/* 040010C0 000040 8C040008 */  lw      a0, (data_0008)(zero)          // overlay 1 start
/* 040010C4 000044 00852020 */  add     a0, a0, a1                      // convert overlay 1 start to dram addr
/* 040010C8 000048 AC040008 */  sw      a0, (data_0008)(zero)
/* 040010CC 00004C 8C250018 */  lw      a1, 0x18(at)                    // ucode_data dram addr
/* 040010D0 000050 AC050FF8 */  sw      a1, (audioStruct + 0x8)(zero)   // save ucode_data dram addr
/* 040010D4 000054 0D000454 */  jal     load_acmd_list
/* 040010D8 000058 001C1020 */   add    v0, zero, gp
/* 040010DC 00005C 40023000 */  mfc0    v0, SP_DMA_BUSY

dma_wait_then_dispatch:
@@dma_busy:
/* 040010E0 000060 1440FFFF */  bnez    v0, @@dma_busy
/* 040010E4 000064 40023000 */   mfc0   v0, SP_DMA_BUSY
dispatch_cmd:
/* 040010E8 000068 8FBA0000 */  lw      cmd_w0, 0(sp)                  // first cmd word
/* 040010EC 00006C 8FB90004 */  lw      cmd_w1, 4(sp)                  // second cmd word
/* 040010F0 000070 239C0008 */  addi    gp, gp, 8
/* 040010F4 000074 001A0DC2 */  srl     at, cmd_w0, 0x17                // cmd byte << 1
/* 040010F8 000078 302100FE */  andi    at, at, 0xfe
/* 040010FC 00007C 84210010 */  lh      at, (dispatchTable)(at)         // load jtbl label
/* 04001100 000080 00200008 */  jr      at                              // enter cmd handler
/* 04001104 000084 237BFFF8 */   addi   k1, k1, -8                    // decrement task_data_size
/* 04001108 000088 0000000D */  break

next_cmd:
/* 0400110C 00008C 1FC0FFF6 */  bgtz    fp, dispatch_cmd
/* 04001110 000090 23BD0008 */   addi   sp, sp, 8
/* 04001114 000094 1B600005 */  blez    k1, task_done
/* 04001118 000098 34014000 */   ori    at, zero, SP_STATUS_SET_SIG7
/* 0400111C 00009C 0D000454 */  jal     load_acmd_list
/* 04001120 0000A0 001C1020 */   add    v0, zero, gp
/* 04001124 0000A4 09000438 */  j       dma_wait_then_dispatch
/* 04001128 0000A8 40023000 */   mfc0   v0, SP_DMA_BUSY

task_done:
@@dma_busy:
/* 0400112C 0000AC 40023000 */  mfc0    v0, SP_DMA_BUSY
/* 04001130 0000B0 1440FFFE */  bnez    v0, @@dma_busy
/* 04001134 0000B4 00000000 */   nop
/* 04001138 0000B8 40803800 */  mtc0    zero, SP_SEMAPHORE
/* 0400113C 0000BC 40812000 */  mtc0    at, SP_STATUS
/* 04001140 0000C0 0000000D */  break
/* 04001144 0000C4 00000000 */  nop
forever:
/* 04001148 0000C8 1000FFFF */  b       forever
/* 0400114C 0000CC 00000000 */   nop

load_acmd_list:
/* 04001150 0000D0 23E50000 */  addi    a1, $ra, 0
/* 04001154 0000D4 23630000 */  addi    v1, k1, 0
/* 04001158 0000D8 2064FEC0 */  addi    a0, v1, -nextTaskEntry_len
/* 0400115C 0000DC 18800002 */  blez    a0, .L04001168
/* 04001160 0000E0 200102C0 */   addi   at, zero, nextTaskEntry
/* 04001164 0000E4 20030140 */  addi    v1, zero, nextTaskEntry_len
.L04001168:
/* 04001168 0000E8 207E0000 */  addi    fp, v1, 0
/* 0400116C 0000EC 0D00045F */  jal     dma_read
/* 04001170 0000F0 2063FFFF */   addi   v1, v1, -1
/* 04001174 0000F4 00A00008 */  jr      a1
/* 04001178 0000F8 201D02C0 */   addi   sp, zero, nextTaskEntry

/***************************************************************
 *  RDRAM -> SP Mem DMA Transfer
 *      at = SP Mem Addr
 *      v0 = RDRAM Addr
 *      v1 = Length - 1
 */
dma_read:
/* 0400117C 0000FC 40042800 */  mfc0    a0, SP_DMA_FULL
@@dma_full:
/* 04001180 000100 1480FFFF */  bnez    a0, @@dma_full
/* 04001184 000104 40042800 */   mfc0   a0, SP_DMA_FULL
/* 04001188 000108 40810000 */  mtc0    at, SP_MEM_ADDR
/* 0400118C 00010C 40820800 */  mtc0    v0, SP_DRAM_ADDR
/* 04001190 000110 03E00008 */  jr      $ra
/* 04001194 000114 40831000 */   mtc0   v1, SP_RD_LEN

/***************************************************************
 *  SP Mem -> RDRAM DMA Transfer
 *      at = SP Mem Addr
 *      v0 = RDRAM Addr
 *      v1 = Length - 1
 */
dma_write:
/* 04001198 000118 40042800 */  mfc0    a0, SP_DMA_FULL
@@dma_full:
/* 0400119C 00011C 1480FFFF */  bnez    a0, @@dma_full
/* 040011A0 000120 40042800 */   mfc0   a0, SP_DMA_FULL
/* 040011A4 000124 40810000 */  mtc0    at, SP_MEM_ADDR
/* 040011A8 000128 40820800 */  mtc0    v0, SP_DRAM_ADDR
/* 040011AC 00012C 03E00008 */  jr      $ra
/* 040011B0 000130 40831800 */   mtc0   v1, SP_WR_LEN

/***************************************************************
 *  Wait for ongoing DMA to complete
 */
dma_wait:
@@dma_busy:
/* 040011B4 000134 40043000 */  mfc0    a0, SP_DMA_BUSY
/* 040011B8 000138 1480FFFE */  bnez    a0, @@dma_busy
/* 040011BC 00013C 00000000 */   nop
/* 040011C0 000140 03E00008 */  jr      $ra
/* 040011C4 000144 00000000 */   nop

/***************************************************************
 *  Loads overlay 0 once overlay 1 exits
 */
reload_overlay_0:
/* 040011C8 000148 84030004 */  lh      v1, (data_0000 + 0x4)(zero)
/* 040011CC 00014C 8C020000 */  lw      v0, (data_0000 + 0x0)(zero)
/* 040011D0 000150 8401000E */  lh      at, (data_0008 + 0x6)(zero)
/* 040011D4 000154 00411020 */  add     v0, v0, at
/* 040011D8 000158 00611822 */  sub     v1, v1, at
/* 040011DC 00015C 84010006 */  lh      at, (data_0000 + 0x6)(zero)
/* 040011E0 000160 00411022 */  sub     v0, v0, at
/* 040011E4 000164 00611820 */  add     v1, v1, at
/* 040011E8 000168 0D00045F */  jal     dma_read
/* 040011EC 00016C 8401000E */   lh     at, (data_0008 + 0x6)(zero)
/* 040011F0 000170 8C020FF8 */  lw      v0, (audioStruct + 0x8)(zero)        // ucode_data dram addr
/* 040011F4 000174 20420010 */  addi    v0, v0, orga(Overlay0DataStart)
/* 040011F8 000178 20010010 */  addi    at, zero, orga(Overlay0DataLoadAddress)
/* 040011FC 00017C 0D00045F */  jal     dma_read
/* 04001200 000180 200302AF */   addi   v1, zero, org(Overlay0DataEnd)-org(Overlay0DataStart)-1
/* 04001204 000184 0D00046D */  jal     dma_wait
/* 04001208 000188 00000000 */   nop
/* 0400120C 00018C 09000443 */  j       next_cmd
/* 04001210 000190 23DEFFF8 */   addi   fp, fp, -8

/***************************************************************
 *  Loads overlay 1 and enters the proper handler for the MP3 cmd
 */
cmd_MP3:
/* 04001214 000194 8401000E */  lh      at, (data_0008 + 0x6)(zero)        // Load overlay 1 imem addr
/* 04001218 000198 8C020008 */  lw      v0, (data_0008 + 0x0)(zero)        // Load overlay 1 dram addr
/* 0400121C 00019C 0D00045F */  jal     dma_read
/* 04001220 0001A0 8403000C */   lh     v1, (data_0008 + 0x4)(zero)        // load overlay 1 length
/* 04001224 0001A4 0D00046D */  jal     dma_wait
/* 04001228 0001A8 00000000 */   nop
/* 0400122C 0001AC 0900048E */  j       cmd_MP3_overlay1                    // jump to overlay 1 code
/* 04001230 0001B0 00000000 */   nop

/* 04001234 0001B4 00000000 */  nop
.align 8
Overlay1LoadAddress:
/* 04001238 0001B8 00000000 */  nop
/* 0400123C 0001BC 00000000 */  nop

/***************************************************************
 *  ZZXXAAAA XXXXBBBB
 *      Z = cmd
 *      X = pad
 *      A = dmem addr
 *      B = length
 */
cmd_CLEARBUFF:
/* 04001240 0001C0 3322FFFF */  andi    v0, cmd_w1, 0xffff      // load length
/* 04001244 0001C4 4A01086C */  vxor    $v1, $v1, $v1           // Zero out $v1
/* 04001248 0001C8 3341FFFF */  andi    at, cmd_w0, 0xffff      // load dmem address
/* 0400124C 0001CC 20210500 */  addi    at, at, 0x500
@@loop:
/* 04001250 0001D0 E8211800 */  sdv     $v1[0], 0x0(at)         // Store zero'd $v1
/* 04001254 0001D4 E8211801 */  sdv     $v1[0], 0x8(at)
/* 04001258 0001D8 2042FFF0 */  addi    v0, v0, -0x10
/* 0400125C 0001DC 1C40FFFC */  bgtz    v0, @@loop              // loop until whole region is cleared
/* 04001260 0001E0 20210010 */   addi   at, at, 0x10
/* 04001264 0001E4 09000443 */  j       next_cmd
/* 04001268 0001E8 23DEFFF8 */   addi   fp, fp, -8





cmd_LOADBUFF:
/* 0400126C 0001EC 001A1A00 */  sll     v1, cmd_w0, 8
/* 04001270 0001F0 00031D02 */  srl     v1, v1, 0x14
/* 04001274 0001F4 1060FFA5 */  beqz    v1, next_cmd
/* 04001278 0001F8 23DEFFF8 */   addi   fp, fp, -8
/* 0400127C 0001FC 33410FFF */  andi    at, cmd_w0, 0xfff
/* 04001280 000200 20210500 */  addi    at, at, 0x500
/* 04001284 000204 00191200 */  sll     v0, cmd_w1, 8
/* 04001288 000208 00021202 */  srl     v0, v0, 8
/* 0400128C 00020C 0D00045F */  jal     dma_read
/* 04001290 000210 2063FFFF */   addi   v1, v1, -1
/* 04001294 000214 40013000 */  mfc0    at, SP_DMA_BUSY
@@dma_busy:
/* 04001298 000218 1420FFFF */  bnez    at, @@dma_busy
/* 0400129C 00021C 40013000 */   mfc0   at, SP_DMA_BUSY
/* 040012A0 000220 09000443 */  j       next_cmd
/* 040012A4 000224 00000000 */   nop





cmd_SAVEBUFF:
/* 040012A8 000228 001A1A00 */  sll     v1, cmd_w0, 8
/* 040012AC 00022C 00031D02 */  srl     v1, v1, 0x14
/* 040012B0 000230 1060FF96 */  beqz    v1, next_cmd
/* 040012B4 000234 23DEFFF8 */   addi   fp, fp, -8
/* 040012B8 000238 33410FFF */  andi    at, cmd_w0, 0xfff
/* 040012BC 00023C 20210500 */  addi    at, at, 0x500
/* 040012C0 000240 00191200 */  sll     v0, cmd_w1, 8
/* 040012C4 000244 00021202 */  srl     v0, v0, 8
/* 040012C8 000248 0D000466 */  jal     dma_write
/* 040012CC 00024C 2063FFFF */   addi   v1, v1, -1
/* 040012D0 000250 40013000 */  mfc0    at, SP_DMA_BUSY
@@dma_busy:
/* 040012D4 000254 1420FFFF */  bnez    at, @@dma_busy
/* 040012D8 000258 40013000 */   mfc0   at, SP_DMA_BUSY
/* 040012DC 00025C 09000443 */  j       next_cmd
/* 040012E0 000260 00000000 */   nop





cmd_LOADADPCM:
/* 040012E4 000264 00191200 */  sll     v0, cmd_w1, 8
/* 040012E8 000268 00021202 */  srl     v0, v0, 8
/* 040012EC 00026C 20010400 */  addi    at, zero, adpcmTable
/* 040012F0 000270 3343FFFF */  andi    v1, cmd_w0, 0xffff
/* 040012F4 000274 0D00045F */  jal     dma_read
/* 040012F8 000278 2063FFFF */   addi   v1, v1, -1
/* 040012FC 00027C 40013000 */  mfc0    at, SP_DMA_BUSY
@@dma_busy:
/* 04001300 000280 1420FFFF */  bnez    at, @@dma_busy
/* 04001304 000284 40013000 */   mfc0   at, SP_DMA_BUSY
/* 04001308 000288 09000443 */  j       next_cmd
/* 0400130C 00028C 23DEFFF8 */   addi   fp, fp, -8





cmd_SETVOL:
/* 04001310 000290 001A1C02 */  srl     v1, cmd_w0, 0x10
/* 04001314 000294 30610004 */  andi    at, v1, 4
/* 04001318 000298 10200009 */  beqz    at, .L04001340
/* 0400131C 00029C 30610002 */   andi   at, v1, 2
/* 04001320 0002A0 10200004 */  beqz    at, .L04001334
/* 04001324 0002A4 00191402 */   srl    v0, cmd_w1, 0x10
/* 04001328 0002A8 A71A0050 */  sh      cmd_w0, 0x50(t8)
/* 0400132C 0002AC A702004C */  sh      v0, 0x4c(t8)
/* 04001330 0002B0 A719004E */  sh      cmd_w1, 0x4e(t8)
.L04001334:
/* 04001334 0002B4 A71A0046 */  sh      cmd_w0, 0x46(t8)
/* 04001338 0002B8 A7020048 */  sh      v0, 0x48(t8)
/* 0400133C 0002BC A719004A */  sh      cmd_w1, 0x4a(t8)
.L04001340:
/* 04001340 0002C0 00191402 */  srl     v0, cmd_w1, 0x10
/* 04001344 0002C4 A71A0040 */  sh      cmd_w0, 0x40(t8)
/* 04001348 0002C8 A7020042 */  sh      v0, 0x42(t8)
/* 0400134C 0002CC A7190044 */  sh      cmd_w1, 0x44(t8)
/* 04001350 0002D0 09000443 */  j       next_cmd
/* 04001354 0002D4 23DEFFF8 */   addi   fp, fp, -8





cmd_INTERLEAVE:
/* 04001358 0002D8 20010170 */  addi    at, zero, 0x170
/* 0400135C 0002DC 20040500 */  addi    a0, zero, data_0_0500
/* 04001360 0002E0 200209E0 */  addi    v0, zero, data_0_09E0
/* 04001364 0002E4 20030B50 */  addi    v1, zero, data_0_0B50
@@loop:
/* 04001368 0002E8 C8412000 */  lqv     $v1[0], 0x0(v0)
/* 0400136C 0002EC C8622000 */  lqv     $v2[0], 0x0(v1)
/* 04001370 0002F0 2021FFF0 */  addi    at, at, -0x10
/* 04001374 0002F4 20420010 */  addi    v0, v0, 0x10
/* 04001378 0002F8 20630010 */  addi    v1, v1, 0x10
/* 0400137C 0002FC E8810800 */  ssv     $v1[0], 0x0(a0)
/* 04001380 000300 E8820801 */  ssv     $v2[0], 0x2(a0)
/* 04001384 000304 E8810902 */  ssv     $v1[2], 0x4(a0)
/* 04001388 000308 E8820903 */  ssv     $v2[2], 0x6(a0)
/* 0400138C 00030C E8810A04 */  ssv     $v1[4], 0x8(a0)
/* 04001390 000310 E8820A05 */  ssv     $v2[4], 0xa(a0)
/* 04001394 000314 E8810B06 */  ssv     $v1[6], 0xc(a0)
/* 04001398 000318 E8820B07 */  ssv     $v2[6], 0xe(a0)
/* 0400139C 00031C E8810C08 */  ssv     $v1[8], 0x10(a0)
/* 040013A0 000320 E8820C09 */  ssv     $v2[8], 0x12(a0)
/* 040013A4 000324 E8810D0A */  ssv     $v1[10], 0x14(a0)
/* 040013A8 000328 E8820D0B */  ssv     $v2[10], 0x16(a0)
/* 040013AC 00032C E8810E0C */  ssv     $v1[12], 0x18(a0)
/* 040013B0 000330 E8820E0D */  ssv     $v2[12], 0x1a(a0)
/* 040013B4 000334 E8810F0E */  ssv     $v1[14], 0x1c(a0)
/* 040013B8 000338 E8820F0F */  ssv     $v2[14], 0x1e(a0)
/* 040013BC 00033C 1C20FFEA */  bgtz    at, @@loop
/* 040013C0 000340 20840020 */   addi   a0, a0, 0x20
/* 040013C4 000344 09000443 */  j       next_cmd
/* 040013C8 000348 23DEFFF8 */   addi   fp, fp, -8





cmd_DMEMMOVE:
/* 040013CC 00034C 3321FFFF */  andi    at, cmd_w1, 0xffff
/* 040013D0 000350 3342FFFF */  andi    v0, cmd_w0, 0xffff
/* 040013D4 000354 20420500 */  addi    v0, v0, 0x500
/* 040013D8 000358 00191C02 */  srl     v1, cmd_w1, 0x10
/* 040013DC 00035C 20630500 */  addi    v1, v1, 0x500
@@loop:
/* 040013E0 000360 C8411800 */  ldv     $v1[0], 0x0(v0)
/* 040013E4 000364 C8421801 */  ldv     $v2[0], 0x8(v0)
/* 040013E8 000368 2021FFF0 */  addi    at, at, -0x10
/* 040013EC 00036C 20420010 */  addi    v0, v0, 0x10
/* 040013F0 000370 E8611800 */  sdv     $v1[0], 0x0(v1)
/* 040013F4 000374 E8621801 */  sdv     $v2[0], 0x8(v1)
/* 040013F8 000378 1C20FFF9 */  bgtz    at, @@loop
/* 040013FC 00037C 20630010 */   addi   v1, v1, 0x10
/* 04001400 000380 09000443 */  j       next_cmd
/* 04001404 000384 23DEFFF8 */   addi   fp, fp, -8





cmd_SETLOOP:
/* 04001408 000388 00190A00 */  sll     at, cmd_w1, 8
/* 0400140C 00038C 00010A02 */  srl     at, at, 8
/* 04001410 000390 AC010FFC */  sw      at, (audioStruct + 0xc)(zero)
/* 04001414 000394 09000443 */  j       next_cmd
/* 04001418 000398 23DEFFF8 */   addi   fp, fp, -8

/***************************************************************
 *  ZZAAAAAA XXBBBBBB
 *      Z = cmd
 *      X = padding
 *      A = ?
 *      B = rdram address
 */
cmd_MP3ADDY:
/* 0400141C 00039C 00190A00 */  sll     at, cmd_w1, 8                   // remove top 8 bits
/* 04001420 0003A0 00010A02 */  srl     at, at, 8
/* 04001424 0003A4 AC010FF4 */  sw      at, (audioStruct + 0x4)(zero)    // store 24-bit value
/* 04001428 0003A8 001A1200 */  sll     v0, cmd_w0, 8                   // remove top 8 bits
/* 0400142C 0003AC 00021202 */  srl     v0, v0, 8
/* 04001430 0003B0 AC020FF0 */  sw      v0, (audioStruct + 0x0)(zero)    // store 24-bit value
/* 04001434 0003B4 09000443 */  j       next_cmd
/* 04001438 0003B8 23DEFFF8 */   addi   fp, fp, -8





cmd_ADPCM:
/* 0400143C 0003BC C81F2006 */  lqv     $v31[0], (data_0_0060)(zero)
/* 04001440 0003C0 0019BB02 */  srl     s7, cmd_w1, 0xc
/* 04001444 0003C4 4A19CE6C */  vxor    $v25, $v25, $v25
/* 04001448 0003C8 32F7000F */  andi    s7, s7, 0xf
/* 0400144C 0003CC 4A18C62C */  vxor    $v24, $v24, $v24
/* 04001450 0003D0 22F70500 */  addi    s7, s7, 0x500
/* 04001454 0003D4 4A0D6B6C */  vxor    $v13, $v13, $v13
/* 04001458 0003D8 33210FFF */  andi    at, cmd_w1, 0xfff
/* 0400145C 0003DC 4A0E73AC */  vxor    $v14, $v14, $v14
/* 04001460 0003E0 20210500 */  addi    at, at, 0x500
/* 04001464 0003E4 4A0F7BEC */  vxor    $v15, $v15, $v15
/* 04001468 0003E8 0019AC02 */  srl     s5, cmd_w1, 0x10
/* 0400146C 0003EC 4A10842C */  vxor    $v16, $v16, $v16
/* 04001470 0003F0 32B50FFF */  andi    s5, s5, 0xfff
/* 04001474 0003F4 4A118C6C */  vxor    $v17, $v17, $v17
/* 04001478 0003F8 001AA200 */  sll     s4, cmd_w0, 8
/* 0400147C 0003FC 4A1294AC */  vxor    $v18, $v18, $v18
/* 04001480 000400 0014A202 */  srl     s4, s4, 8
/* 04001484 000404 4A139CEC */  vxor    $v19, $v19, $v19
/* 04001488 000408 2003001F */  addi    v1, zero, 0x20-1
/* 0400148C 00040C 00196F02 */  srl     t5, cmd_w1, 0x1c
/* 04001490 000410 31A20001 */  andi    v0, t5, 1
/* 04001494 000414 1C400017 */  bgtz    v0, .L040014F4
/* 04001498 000418 22F60001 */   addi   s6, s7, 1
/* 0400149C 00041C 31A20002 */  andi    v0, t5, 2
/* 040014A0 000420 10400002 */  beqz    v0, .L040014AC
/* 040014A4 000424 22820000 */   addi   v0, s4, 0
/* 040014A8 000428 8C020FFC */  lw      v0, (audioStruct + 0xc)(zero)
.L040014AC:
/* 040014AC 00042C 400D2800 */  mfc0    t5, SP_DMA_FULL
@@dma_full:
/* 040014B0 000430 15A0FFFF */  bnez    t5, @@dma_full
/* 040014B4 000434 400D2800 */   mfc0   t5, SP_DMA_FULL
/* 040014B8 000438 40810000 */  mtc0    at, SP_MEM_ADDR
/* 040014BC 00043C 40820800 */  mtc0    v0, SP_DRAM_ADDR
/* 040014C0 000440 40831000 */  mtc0    v1, SP_RD_LEN
/* 040014C4 000444 20130030 */  addi    s3, zero, data_0_0030
/* 040014C8 000448 20120400 */  addi    s2, zero, adpcmTable
/* 040014CC 00044C CA791800 */  ldv     $v25[0], 0x0(s3)
/* 040014D0 000450 CA781C00 */  ldv     $v24[8], 0x0(s3)
/* 040014D4 000454 CA771801 */  ldv     $v23[0], 0x8(s3)
/* 040014D8 000458 CA771C01 */  ldv     $v23[8], 0x8(s3)
/* 040014DC 00045C 40053000 */  mfc0    a1, SP_DMA_BUSY
.L040014E0:
/* 040014E0 000460 14A0FFFF */  bnez    a1, .L040014E0
/* 040014E4 000464 40053000 */   mfc0   a1, SP_DMA_BUSY
/* 040014E8 000468 00000020 */  add     zero, zero, zero
/* 040014EC 00046C 09000546 */  j       .L040014EC
/* 040014F0 000470 C83B2001 */   lqv    $v27[0], 0x10(at)
.L040014F4:
/* 040014F4 000474 20130030 */  addi    s3, zero, data_0_0030
/* 040014F8 000478 4A1BDEEC */  vxor    $v27, $v27, $v27
/* 040014FC 00047C 20120400 */  addi    s2, zero, adpcmTable
/* 04001500 000480 CA791800 */  ldv     $v25[0], 0x0(s3)
/* 04001504 000484 CA781C00 */  ldv     $v24[8], 0x0(s3)
/* 04001508 000488 CA771801 */  ldv     $v23[0], 0x8(s3)
/* 0400150C 00048C CA771C01 */  ldv     $v23[8], 0x8(s3)
/* 04001510 000490 E83B2000 */  sqv     $v27[0], 0x0(at)
/* 04001514 000494 E83B2001 */  sqv     $v27[0], 0x10(at)
.L040014EC:
/* 04001518 000498 12A0006B */  beqz    s5, .L040016C8
/* 0400151C 00049C 20210020 */   addi   at, at, 0x20
/* 04001520 0004A0 CACC1800 */  ldv     $v12[0], 0x0(s6)
/* 04001524 0004A4 92EA0000 */  lbu     t2, (s7)
/* 04001528 0004A8 200D000C */  addi    t5, zero, 0xc
/* 0400152C 0004AC 200C0001 */  addi    t4, zero, 1
/* 04001530 0004B0 314E000F */  andi    t6, t2, 0xf
/* 04001534 0004B4 000E7140 */  sll     t6, t6, 5
/* 04001538 0004B8 4B0CCAA8 */  vand    $v10, $v25, $v12[0]
/* 0400153C 0004BC 01D28020 */  add     s0, t6, s2
/* 04001540 0004C0 4B2CC268 */  vand    $v9, $v24, $v12[1]
/* 04001544 0004C4 000A8902 */  srl     s1, t2, 4
/* 04001548 0004C8 4B4CCA28 */  vand    $v8, $v25, $v12[2]
/* 0400154C 0004CC 01B18822 */  sub     s1, t5, s1
/* 04001550 0004D0 4B6CC1E8 */  vand    $v7, $v24, $v12[3]
/* 04001554 0004D4 222DFFFF */  addi    t5, s1, -1
/* 04001558 0004D8 000C63C0 */  sll     t4, t4, 0xf
/* 0400155C 0004DC 01AC5806 */  srlv    t3, t4, t5
/* 04001560 0004E0 488BB000 */  mtc2    t3, $v22[0]
/* 04001564 0004E4 CA152000 */  lqv     $v21[0], 0x0(s0)
/* 04001568 0004E8 CA142001 */  lqv     $v20[0], 0x10(s0)
/* 0400156C 0004EC 2210FFFE */  addi    s0, s0, -2
/* 04001570 0004F0 CA132802 */  lrv     $v19[0], 0x20(s0)
/* 04001574 0004F4 2210FFFE */  addi    s0, s0, -2
/* 04001578 0004F8 CA122802 */  lrv     $v18[0], 0x20(s0)
/* 0400157C 0004FC 2210FFFE */  addi    s0, s0, -2
/* 04001580 000500 CA112802 */  lrv     $v17[0], 0x20(s0)
/* 04001584 000504 2210FFFE */  addi    s0, s0, -2
/* 04001588 000508 CA102802 */  lrv     $v16[0], 0x20(s0)
/* 0400158C 00050C 2210FFFE */  addi    s0, s0, -2
/* 04001590 000510 CA0F2802 */  lrv     $v15[0], 0x20(s0)
/* 04001594 000514 2210FFFE */  addi    s0, s0, -2
/* 04001598 000518 CA0E2802 */  lrv     $v14[0], 0x20(s0)
/* 0400159C 00051C 2210FFFE */  addi    s0, s0, -2
/* 040015A0 000520 CA0D2802 */  lrv     $v13[0], 0x20(s0)
.L040015A4:
/* 040015A4 000524 22D60009 */  addi    s6, s6, 9
/* 040015A8 000528 4A175786 */  vmudn   $v30, $v10, $v23
/* 040015AC 00052C 22F70009 */  addi    s7, s7, 9
/* 040015B0 000530 4A174F8E */  vmadn   $v30, $v9, $v23
/* 040015B4 000534 92EA0000 */  lbu     t2, (s7)
/* 040015B8 000538 4A174746 */  vmudn   $v29, $v8, $v23
/* 040015BC 00053C CACC1800 */  ldv     $v12[0], 0x0(s6)
/* 040015C0 000540 4A173F4E */  vmadn   $v29, $v7, $v23
/* 040015C4 000544 200D000C */  addi    t5, zero, 0xc
/* 040015C8 000548 1A200003 */  blez    s1, .L040015D8
/* 040015CC 00054C 314E000F */   andi   t6, t2, 0xf
/* 040015D0 000550 4B16F785 */  vmudm   $v30, $v30, $v22[0]
/* 040015D4 000554 4B16EF45 */  vmudm   $v29, $v29, $v22[0]
.L040015D8:
/* 040015D8 000558 000E7140 */  sll     t6, t6, 5
/* 040015DC 00055C 4BDBAAC7 */  vmudh   $v11, $v21, $v27[6]
/* 040015E0 000560 01D28020 */  add     s0, t6, s2
/* 040015E4 000564 4BFBA2CF */  vmadh   $v11, $v20, $v27[7]
/* 040015E8 000568 4B1E9ACF */  vmadh   $v11, $v19, $v30[0]
/* 040015EC 00056C 4B3E92CF */  vmadh   $v11, $v18, $v30[1]
/* 040015F0 000570 000A8902 */  srl     s1, t2, 4
/* 040015F4 000574 4B5E8ACF */  vmadh   $v11, $v17, $v30[2]
/* 040015F8 000578 4B7E82CF */  vmadh   $v11, $v16, $v30[3]
/* 040015FC 00057C 01B18822 */  sub     s1, t5, s1
/* 04001600 000580 4B9E7F0F */  vmadh   $v28, $v15, $v30[4]
/* 04001604 000584 222DFFFF */  addi    t5, s1, -1
/* 04001608 000588 4BBE72CF */  vmadh   $v11, $v14, $v30[5]
/* 0400160C 00058C 4BDE6ACF */  vmadh   $v11, $v13, $v30[6]
/* 04001610 000590 4B7FF2CF */  vmadh   $v11, $v30, $v31[3]
/* 04001614 000594 01AC5806 */  srlv    t3, t4, t5
/* 04001618 000598 4B3C369D */  vsar    $v26, $v6, $v28[1]
/* 0400161C 00059C 488BB000 */  mtc2    t3, $v22[0]
/* 04001620 0005A0 4B1C371D */  vsar    $v28, $v6, $v28[0]
/* 04001624 0005A4 4B0CCAA8 */  vand    $v10, $v25, $v12[0]
/* 04001628 0005A8 4B2CC268 */  vand    $v9, $v24, $v12[1]
/* 0400162C 0005AC 4B4CCA28 */  vand    $v8, $v25, $v12[2]
/* 04001630 0005B0 4B6CC1E8 */  vand    $v7, $v24, $v12[3]
/* 04001634 0005B4 4B3FD2C6 */  vmudn   $v11, $v26, $v31[1]
/* 04001638 0005B8 4B3FE70F */  vmadh   $v28, $v28, $v31[1]
/* 0400163C 0005BC 4B1D9AC7 */  vmudh   $v11, $v19, $v29[0]
/* 04001640 0005C0 220FFFFE */  addi    t7, s0, -2
/* 04001644 0005C4 4B3D92CF */  vmadh   $v11, $v18, $v29[1]
/* 04001648 0005C8 C9F32802 */  lrv     $v19[0], 0x20(t7)
/* 0400164C 0005CC 4B5D8ACF */  vmadh   $v11, $v17, $v29[2]
/* 04001650 0005D0 21EFFFFE */  addi    t7, t7, -2
/* 04001654 0005D4 4B7D82CF */  vmadh   $v11, $v16, $v29[3]
/* 04001658 0005D8 C9F22802 */  lrv     $v18[0], 0x20(t7)
/* 0400165C 0005DC 4B9D7ACF */  vmadh   $v11, $v15, $v29[4]
/* 04001660 0005E0 21EFFFFE */  addi    t7, t7, -2
/* 04001664 0005E4 4BBD72CF */  vmadh   $v11, $v14, $v29[5]
/* 04001668 0005E8 C9F12802 */  lrv     $v17[0], 0x20(t7)
/* 0400166C 0005EC 4BDD6ACF */  vmadh   $v11, $v13, $v29[6]
/* 04001670 0005F0 21EFFFFE */  addi    t7, t7, -2
/* 04001674 0005F4 4B7FEACF */  vmadh   $v11, $v29, $v31[3]
/* 04001678 0005F8 C9F02802 */  lrv     $v16[0], 0x20(t7)
/* 0400167C 0005FC 4BDCAACF */  vmadh   $v11, $v21, $v28[6]
/* 04001680 000600 21EFFFFE */  addi    t7, t7, -2
/* 04001684 000604 4BFCA2CF */  vmadh   $v11, $v20, $v28[7]
/* 04001688 000608 C9EF2802 */  lrv     $v15[0], 0x20(t7)
/* 0400168C 00060C 4B3B369D */  vsar    $v26, $v6, $v27[1]
/* 04001690 000610 21EFFFFE */  addi    t7, t7, -2
/* 04001694 000614 4B1B36DD */  vsar    $v27, $v6, $v27[0]
/* 04001698 000618 C9EE2802 */  lrv     $v14[0], 0x20(t7)
/* 0400169C 00061C 21EFFFFE */  addi    t7, t7, -2
/* 040016A0 000620 C9ED2802 */  lrv     $v13[0], 0x20(t7)
/* 040016A4 000624 CA152000 */  lqv     $v21[0], 0x0(s0)
/* 040016A8 000628 4B3FD2C6 */  vmudn   $v11, $v26, $v31[1]
/* 040016AC 00062C CA142001 */  lqv     $v20[0], 0x10(s0)
/* 040016B0 000630 4B3FDECF */  vmadh   $v27, $v27, $v31[1]
/* 040016B4 000634 22B5FFE0 */  addi    s5, s5, -0x20
/* 040016B8 000638 E83C2000 */  sqv     $v28[0], 0x0(at)
/* 040016BC 00063C 20210020 */  addi    at, at, 0x20
/* 040016C0 000640 1EA0FFB8 */  bgtz    s5, .L040015A4
/* 040016C4 000644 E83B207F */   sqv    $v27[0], -0x10(at)
.L040016C8:
/* 040016C8 000648 2021FFE0 */  addi    at, at, -0x20
/* 040016CC 00064C 0D000466 */  jal     dma_write
/* 040016D0 000650 22820000 */   addi   v0, s4, 0
/* 040016D4 000654 23DEFFF8 */  addi    fp, fp, -8
/* 040016D8 000658 40053000 */  mfc0    a1, SP_DMA_BUSY
@@dma_busy:
/* 040016DC 00065C 14A0FFFF */  bnez    a1, @@dma_busy
/* 040016E0 000660 40053000 */   mfc0   a1, SP_DMA_BUSY
/* 040016E4 000664 09000443 */  j       next_cmd
/* 040016E8 000668 00000024 */   and    zero, zero, zero





cmd_16EC:
/* 040016EC 00066C 20140400 */  addi    s4, zero, adpcmTable
/* 040016F0 000670 4A1AD6AC */  vxor    $v26, $v26, $v26
/* 040016F4 000674 8E910000 */  lw      s1, (s4)
/* 040016F8 000678 1220009C */  beqz    s1, .L0400196C
/* 040016FC 00067C 23DEFFF8 */   addi   fp, fp, -8
/* 04001700 000680 23570500 */  addi    s7, cmd_w0, 0x500
/* 04001704 000684 CA921800 */  ldv     $v18[0], 0x0(s4)
/* 04001708 000688 4A19CE6C */  vxor    $v25, $v25, $v25
/* 0400170C 00068C 03201020 */  add     v0, cmd_w1, zero
/* 04001710 000690 22F5FFFC */  addi    s5, s7, -4
/* 04001714 000694 22F3FFFE */  addi    s3, s7, -2
/* 04001718 000698 4A18C62C */  vxor    $v24, $v24, $v24
/* 0400171C 00069C 4A17BDEC */  vxor    $v23, $v23, $v23
/* 04001720 0006A0 20030007 */  addi    v1, zero, 7
/* 04001724 0006A4 4A16B5AC */  vxor    $v22, $v22, $v22
/* 04001728 0006A8 20160170 */  addi    s6, zero, 0x170
/* 0400172C 0006AC 4A15AD6C */  vxor    $v21, $v21, $v21
/* 04001730 0006B0 001A8402 */  srl     s0, cmd_w0, 0x10
/* 04001734 0006B4 4A14A52C */  vxor    $v20, $v20, $v20
/* 04001738 0006B8 32100001 */  andi    s0, s0, 1
/* 0400173C 0006BC 4A139CEC */  vxor    $v19, $v19, $v19
/* 04001740 0006C0 8E920002 */  lw      s2, 2(s4)
/* 04001744 0006C4 1E00001E */  bgtz    s0, .L040017C0
/* 04001748 0006C8 23010000 */   addi   at, t8, 0
/* 0400174C 0006CC 40102800 */  mfc0    s0, SP_DMA_FULL
@@dma_full:
/* 04001750 0006D0 1600FFFF */  bnez    s0, @@dma_full
/* 04001754 0006D4 40102800 */   mfc0   s0, SP_DMA_FULL
/* 04001758 0006D8 40810000 */  mtc0    at, SP_MEM_ADDR
/* 0400175C 0006DC 40820800 */  mtc0    v0, SP_DRAM_ADDR
/* 04001760 0006E0 40831000 */  mtc0    v1, SP_RD_LEN
/* 04001764 0006E4 CA9A1004 */  llv     $v26[0], 0x10(s4)
/* 04001768 0006E8 2294FFFE */  addi    s4, s4, -2
/* 0400176C 0006EC CA991802 */  ldv     $v25[0], 0x10(s4)
/* 04001770 0006F0 22940002 */  addi    s4, s4, 2
/* 04001774 0006F4 CA981204 */  llv     $v24[4], 0x10(s4)
/* 04001778 0006F8 2294FFFE */  addi    s4, s4, -2
/* 0400177C 0006FC CA971A02 */  ldv     $v23[4], 0x10(s4)
/* 04001780 000700 22940002 */  addi    s4, s4, 2
/* 04001784 000704 CA961404 */  llv     $v22[8], 0x10(s4)
/* 04001788 000708 2294FFFE */  addi    s4, s4, -2
/* 0400178C 00070C CA951C02 */  ldv     $v21[8], 0x10(s4)
/* 04001790 000710 22940002 */  addi    s4, s4, 2
/* 04001794 000714 CA941604 */  llv     $v20[12], 0x10(s4)
/* 04001798 000718 CA930F08 */  lsv     $v19[14], 0x10(s4)
/* 0400179C 00071C CA930809 */  lsv     $v19[0], 0x12(s4)
/* 040017A0 000720 40053000 */  mfc0    a1, SP_DMA_BUSY
@@dma_busy:
/* 040017A4 000724 14A0FFFF */  bnez    a1, @@dma_busy
/* 040017A8 000728 40053000 */   mfc0   a1, SP_DMA_BUSY
/* 040017AC 00072C C82F1000 */  llv     $v15[0], 0x0(at)
/* 040017B0 000730 12400016 */  beqz    s2, .L0400180C
/* 040017B4 000734 C83C1601 */   llv    $v28[12], 0x4(at)
/* 040017B8 000738 0900060B */  j       .L0400182C
/* 040017BC 00073C C82B0801 */   lsv    $v11[0], 0x2(at)
.L040017C0:
/* 040017C0 000740 CA9A1004 */  llv     $v26[0], 0x10(s4)
/* 040017C4 000744 2294FFFE */  addi    s4, s4, -2
/* 040017C8 000748 4A0F7BEC */  vxor    $v15, $v15, $v15
/* 040017CC 00074C CA991802 */  ldv     $v25[0], 0x10(s4)
/* 040017D0 000750 22940002 */  addi    s4, s4, 2
/* 040017D4 000754 4A0B5AEC */  vxor    $v11, $v11, $v11
/* 040017D8 000758 CA981204 */  llv     $v24[4], 0x10(s4)
/* 040017DC 00075C 2294FFFE */  addi    s4, s4, -2
/* 040017E0 000760 4A1CE72C */  vxor    $v28, $v28, $v28
/* 040017E4 000764 CA971A02 */  ldv     $v23[4], 0x10(s4)
/* 040017E8 000768 22940002 */  addi    s4, s4, 2
/* 040017EC 00076C CA961404 */  llv     $v22[8], 0x10(s4)
/* 040017F0 000770 2294FFFE */  addi    s4, s4, -2
/* 040017F4 000774 CA951C02 */  ldv     $v21[8], 0x10(s4)
/* 040017F8 000778 22940002 */  addi    s4, s4, 2
/* 040017FC 00077C CA941604 */  llv     $v20[12], 0x10(s4)
/* 04001800 000780 CA930F08 */  lsv     $v19[14], 0x10(s4)
/* 04001804 000784 16400009 */  bnez    s2, .L0400182C
/* 04001808 000788 CA930809 */   lsv    $v19[0], 0x12(s4)
.L0400180C:
/* 0400180C 00078C CAFE2000 */  lqv     $v30[0], 0x0(s7)
/* 04001810 000790 CAAF2801 */  lrv     $v15[0], 0x10(s5)
/* 04001814 000794 4A0FF7D1 */  vsub    $v31, $v30, $v15
/* 04001818 000798 4BDC9C00 */  vmulf   $v16, $v19, $v28[6]
/* 0400181C 00079C 4B12FFC0 */  vmulf   $v31, $v31, $v18[0]
/* 04001820 0007A0 4A108410 */  vadd    $v16, $v16, $v16
/* 04001824 0007A4 09000651 */  j       .L04001824
/* 04001828 0007A8 4BFC7F73 */   vmov   $v29[7], $v28[7]
.L0400182C:
/* 0400182C 0007AC CAFE2000 */  lqv     $v30[0], 0x0(s7)
/* 04001830 0007B0 CA6B2801 */  lrv     $v11[0], 0x10(s3)
/* 04001834 0007B4 CAAF2801 */  lrv     $v15[0], 0x10(s5)
/* 04001838 0007B8 4B12F780 */  vmulf   $v30, $v30, $v18[0]
/* 0400183C 0007BC 4B325AC0 */  vmulf   $v11, $v11, $v18[1]
/* 04001840 0007C0 4B127BC0 */  vmulf   $v15, $v15, $v18[0]
/* 04001844 0007C4 4BDC9C00 */  vmulf   $v16, $v19, $v28[6]
/* 04001848 0007C8 4A0BF7D0 */  vadd    $v31, $v30, $v11
/* 0400184C 0007CC 4A108410 */  vadd    $v16, $v16, $v16
/* 04001850 0007D0 4A0FFFD0 */  vadd    $v31, $v31, $v15
.L04001854:
/* 04001854 0007D4 4BFCD440 */  vmulf   $v17, $v26, $v28[7]
/* 04001858 0007D8 4B1F86D0 */  vadd    $v27, $v16, $v31[0]
/* 0400185C 0007DC 4BFC7F73 */  vmov    $v29[7], $v28[7]
/* 04001860 0007E0 22D6FFF0 */  addi    s6, s6, -0x10
/* 04001864 0007E4 4A118C50 */  vadd    $v17, $v17, $v17
/* 04001868 0007E8 4A11DF10 */  vadd    $v28, $v27, $v17
/* 0400186C 0007EC 4B3F8ED0 */  vadd    $v27, $v17, $v31[1]
/* 04001870 0007F0 4B1CCC00 */  vmulf   $v16, $v25, $v28[0]
/* 04001874 0007F4 4A1DEBAA */  vor     $v14, $v29, $v29
/* 04001878 0007F8 CA6B2001 */  lqv     $v11[0], 0x10(s3)
/* 0400187C 0007FC 4B1C4773 */  vmov    $v29[0], $v28[0]
/* 04001880 000800 4A108410 */  vadd    $v16, $v16, $v16
/* 04001884 000804 4A10DF10 */  vadd    $v28, $v27, $v16
/* 04001888 000808 4B5F86D0 */  vadd    $v27, $v16, $v31[2]
/* 0400188C 00080C 4B3CC440 */  vmulf   $v17, $v24, $v28[1]
/* 04001890 000810 CA6B2802 */  lrv     $v11[0], 0x20(s3)
/* 04001894 000814 16400002 */  bnez    s2, .L040018A0
/* 04001898 000818 4B3C4F73 */   vmov   $v29[1], $v28[1]
/* 0400189C 00081C EAEE207F */  sqv     $v14[0], -0x10(s7)
.L040018A0:
/* 040018A0 000820 4A118C50 */  vadd    $v17, $v17, $v17
/* 040018A4 000824 4A11DF10 */  vadd    $v28, $v27, $v17
/* 040018A8 000828 00009025 */  or      s2, zero, zero
/* 040018AC 00082C 4B7F8ED0 */  vadd    $v27, $v17, $v31[3]
/* 040018B0 000830 4B5CBC00 */  vmulf   $v16, $v23, $v28[2]
/* 040018B4 000834 4B5C5773 */  vmov    $v29[2], $v28[2]
/* 040018B8 000838 4B325AC0 */  vmulf   $v11, $v11, $v18[1]
/* 040018BC 00083C CAFE2001 */  lqv     $v30[0], 0x10(s7)
/* 040018C0 000840 4A108410 */  vadd    $v16, $v16, $v16
/* 040018C4 000844 4A10DF10 */  vadd    $v28, $v27, $v16
/* 040018C8 000848 4B9F86D0 */  vadd    $v27, $v16, $v31[4]
/* 040018CC 00084C 4B7CB440 */  vmulf   $v17, $v22, $v28[3]
/* 040018D0 000850 4B7C5F73 */  vmov    $v29[3], $v28[3]
/* 040018D4 000854 4A118C50 */  vadd    $v17, $v17, $v17
/* 040018D8 000858 CAAF2001 */  lqv     $v15[0], 0x10(s5)
/* 040018DC 00085C 4B12F780 */  vmulf   $v30, $v30, $v18[0]
/* 040018E0 000860 4A11DF10 */  vadd    $v28, $v27, $v17
/* 040018E4 000864 4BBF8ED0 */  vadd    $v27, $v17, $v31[5]
/* 040018E8 000868 4B9CAC00 */  vmulf   $v16, $v21, $v28[4]
/* 040018EC 00086C 4B9C6773 */  vmov    $v29[4], $v28[4]
/* 040018F0 000870 4A108410 */  vadd    $v16, $v16, $v16
/* 040018F4 000874 CAAF2802 */  lrv     $v15[0], 0x20(s5)
/* 040018F8 000878 4A1E5AD0 */  vadd    $v11, $v11, $v30
/* 040018FC 00087C 4A10DF10 */  vadd    $v28, $v27, $v16
/* 04001900 000880 4BDF86D0 */  vadd    $v27, $v16, $v31[6]
/* 04001904 000884 4BBCA440 */  vmulf   $v17, $v20, $v28[5]
/* 04001908 000888 4BBC6F73 */  vmov    $v29[5], $v28[5]
/* 0400190C 00088C 4B127B40 */  vmulf   $v13, $v15, $v18[0]
/* 04001910 000890 4A118C50 */  vadd    $v17, $v17, $v17
/* 04001914 000894 4A11DF10 */  vadd    $v28, $v27, $v17
/* 04001918 000898 4BFF8ED0 */  vadd    $v27, $v17, $v31[7]
/* 0400191C 00089C 4BDC9C00 */  vmulf   $v16, $v19, $v28[6]
/* 04001920 0008A0 22B50010 */  addi    s5, s5, 0x10
/* 04001924 0008A4 4BDC7773 */  vmov    $v29[6], $v28[6]
/* 04001928 0008A8 22730010 */  addi    s3, s3, 0x10
/* 0400192C 0008AC 4A0D5FD0 */  vadd    $v31, $v11, $v13
/* 04001930 0008B0 4A108410 */  vadd    $v16, $v16, $v16
/* 04001934 0008B4 4A10DF10 */  vadd    $v28, $v27, $v16
/* 04001938 0008B8 1EC0FFC6 */  bgtz    s6, .L04001854
/* 0400193C 0008BC 22F70010 */   addi   s7, s7, 0x10
/* 04001940 0008C0 4BFC7F73 */  vmov    $v29[7], $v28[7]
.L04001824:
/* 04001944 0008C4 4A1DEBAA */  vor     $v14, $v29, $v29
/* 04001948 0008C8 E82F1000 */  slv     $v15[0], 0x0(at)
/* 0400194C 0008CC E83D1601 */  slv     $v29[12], 0x4(at)
/* 04001950 0008D0 0D000466 */  jal     dma_write
/* 04001954 0008D4 EAEE207F */   sqv    $v14[0], -0x10(s7)
/* 04001958 0008D8 40053000 */  mfc0    a1, SP_DMA_BUSY
@@dma_busy:
/* 0400195C 0008DC 14A0FFFF */  bnez    a1, @@dma_busy
/* 04001960 0008E0 40053000 */   mfc0   a1, SP_DMA_BUSY
/* 04001964 0008E4 09000443 */  j       next_cmd
/* 04001968 0008E8 00000000 */   nop
.L0400196C:
/* 0400196C 0008EC 00199E02 */  srl     s3, cmd_w1, 0x18
/* 04001970 0008F0 20140400 */  addi    s4, zero, adpcmTable
/* 04001974 0008F4 4A15AD6C */  vxor    $v21, $v21, $v21
/* 04001978 0008F8 12600002 */  beqz    s3, .L04001984
/* 0400197C 0008FC 20170500 */   addi   s7, zero, data_0_0500
/* 04001980 000900 20170670 */  addi    s7, zero, data_0_0670
.L04001984:
/* 04001984 000904 CA9C2001 */  lqv     $v28[0], 0x10(s4)
/* 04001988 000908 4A16B5AC */  vxor    $v22, $v22, $v22
/* 0400198C 00090C 489A9500 */  mtc2    cmd_w0, $v18[10]
/* 04001990 000910 4A17BDEC */  vxor    $v23, $v23, $v23
/* 04001994 000914 001AD080 */  sll     cmd_w0, cmd_w0, 2
/* 04001998 000918 4A18C62C */  vxor    $v24, $v24, $v24
/* 0400199C 00091C 489AA000 */  mtc2    cmd_w0, $v20[0]
/* 040019A0 000920 4A19CE6C */  vxor    $v25, $v25, $v25
/* 040019A4 000924 00191200 */  sll     v0, cmd_w1, 8
/* 040019A8 000928 4A1AD6AC */  vxor    $v26, $v26, $v26
/* 040019AC 00092C 00021202 */  srl     v0, v0, 8
/* 040019B0 000930 4A1BDEEC */  vxor    $v27, $v27, $v27
/* 040019B4 000934 20030007 */  addi    v1, zero, 7
/* 040019B8 000938 20130004 */  addi    s3, zero, 4
/* 040019BC 00093C 48939000 */  mtc2    s3, $v18[0]
/* 040019C0 000940 20160170 */  addi    s6, zero, 0x170
/* 040019C4 000944 4B14E505 */  vmudm   $v20, $v28, $v20[0]
/* 040019C8 000948 001A9C02 */  srl     s3, cmd_w0, 0x10
/* 040019CC 00094C 32730001 */  andi    s3, s3, 1
/* 040019D0 000950 1E60001B */  bgtz    s3, .L04001A40
/* 040019D4 000954 EA942001 */   sqv    $v20[0], 0x10(s4)
/* 040019D8 000958 23010000 */  addi    at, t8, 0
/* 040019DC 00095C 40132800 */  mfc0    s3, SP_DMA_FULL
@@dma_full:
/* 040019E0 000960 1660FFFF */  bnez    s3, @@dma_full
/* 040019E4 000964 40132800 */   mfc0   s3, SP_DMA_FULL
/* 040019E8 000968 40810000 */  mtc0    at, SP_MEM_ADDR
/* 040019EC 00096C 40820800 */  mtc0    v0, SP_DRAM_ADDR
/* 040019F0 000970 40831000 */  mtc0    v1, SP_RD_LEN
/* 040019F4 000974 2294FFFE */  addi    s4, s4, -2
/* 040019F8 000978 CA9B2802 */  lrv     $v27[0], 0x20(s4)
/* 040019FC 00097C 2294FFFE */  addi    s4, s4, -2
/* 04001A00 000980 CA9A2802 */  lrv     $v26[0], 0x20(s4)
/* 04001A04 000984 2294FFFE */  addi    s4, s4, -2
/* 04001A08 000988 CA992802 */  lrv     $v25[0], 0x20(s4)
/* 04001A0C 00098C 2294FFFE */  addi    s4, s4, -2
/* 04001A10 000990 CA982802 */  lrv     $v24[0], 0x20(s4)
/* 04001A14 000994 2294FFFE */  addi    s4, s4, -2
/* 04001A18 000998 CA972802 */  lrv     $v23[0], 0x20(s4)
/* 04001A1C 00099C 2294FFFE */  addi    s4, s4, -2
/* 04001A20 0009A0 CA962802 */  lrv     $v22[0], 0x20(s4)
/* 04001A24 0009A4 2294FFFE */  addi    s4, s4, -2
/* 04001A28 0009A8 CA952802 */  lrv     $v21[0], 0x20(s4)
/* 04001A2C 0009AC 40053000 */  mfc0    a1, SP_DMA_BUSY
@@dma_busy:
/* 04001A30 0009B0 14A0FFFF */  bnez    a1, @@dma_busy
/* 04001A34 0009B4 40053000 */   mfc0   a1, SP_DMA_BUSY
/* 04001A38 0009B8 0900069F */  j       .L04001A7C
/* 04001A3C 0009BC C83E1C00 */   ldv    $v30[8], 0x0(at)
.L04001A40:
/* 04001A40 0009C0 2294FFFE */  addi    s4, s4, -2
/* 04001A44 0009C4 4A1EF7AC */  vxor    $v30, $v30, $v30
/* 04001A48 0009C8 CA9B2802 */  lrv     $v27[0], 0x20(s4)
/* 04001A4C 0009CC 2294FFFE */  addi    s4, s4, -2
/* 04001A50 0009D0 CA9A2802 */  lrv     $v26[0], 0x20(s4)
/* 04001A54 0009D4 2294FFFE */  addi    s4, s4, -2
/* 04001A58 0009D8 CA992802 */  lrv     $v25[0], 0x20(s4)
/* 04001A5C 0009DC 2294FFFE */  addi    s4, s4, -2
/* 04001A60 0009E0 CA982802 */  lrv     $v24[0], 0x20(s4)
/* 04001A64 0009E4 2294FFFE */  addi    s4, s4, -2
/* 04001A68 0009E8 CA972802 */  lrv     $v23[0], 0x20(s4)
/* 04001A6C 0009EC 2294FFFE */  addi    s4, s4, -2
/* 04001A70 0009F0 CA962802 */  lrv     $v22[0], 0x20(s4)
/* 04001A74 0009F4 2294FFFE */  addi    s4, s4, -2
/* 04001A78 0009F8 CA952802 */  lrv     $v21[0], 0x20(s4)
.L04001A7C:
/* 04001A7C 0009FC CAFF2000 */  lqv     $v31[0], 0x0(s7)
.L04001A80:
/* 04001A80 000A00 4BFEE507 */  vmudh   $v20, $v28, $v30[7]
/* 04001A84 000A04 4B1FDD0F */  vmadh   $v20, $v27, $v31[0]
/* 04001A88 000A08 22D6FFF0 */  addi    s6, s6, -0x10
/* 04001A8C 000A0C 4B3FD50F */  vmadh   $v20, $v26, $v31[1]
/* 04001A90 000A10 4B5FCD0F */  vmadh   $v20, $v25, $v31[2]
/* 04001A94 000A14 EAFE207F */  sqv     $v30[0], -0x10(s7)
/* 04001A98 000A18 4B7FC50F */  vmadh   $v20, $v24, $v31[3]
/* 04001A9C 000A1C 4B9FBF8F */  vmadh   $v30, $v23, $v31[4]
/* 04001AA0 000A20 4BBFB50F */  vmadh   $v20, $v22, $v31[5]
/* 04001AA4 000A24 4BDFAD0F */  vmadh   $v20, $v21, $v31[6]
/* 04001AA8 000A28 4BB2FD0F */  vmadh   $v20, $v31, $v18[5]
/* 04001AAC 000A2C CAFF2001 */  lqv     $v31[0], 0x10(s7)
/* 04001AB0 000A30 4B3E9F5D */  vsar    $v29, $v19, $v30[1]
/* 04001AB4 000A34 4B1E9F9D */  vsar    $v30, $v19, $v30[0]
/* 04001AB8 000A38 4B12ED06 */  vmudn   $v20, $v29, $v18[0]
/* 04001ABC 000A3C 4B12F78F */  vmadh   $v30, $v30, $v18[0]
/* 04001AC0 000A40 1EC0FFEF */  bgtz    s6, .L04001A80
/* 04001AC4 000A44 22F70010 */   addi   s7, s7, 0x10
/* 04001AC8 000A48 22E1FFF8 */  addi    at, s7, -8
/* 04001ACC 000A4C 0D000466 */  jal     dma_write
/* 04001AD0 000A50 EAFE207F */   sqv    $v30[0], -0x10(s7)
/* 04001AD4 000A54 40053000 */  mfc0    a1, SP_DMA_BUSY
@@dma_busy:
/* 04001AD8 000A58 14A0FFFF */  bnez    a1, @@dma_busy
/* 04001ADC 000A5C 40053000 */   mfc0   a1, SP_DMA_BUSY
/* 04001AE0 000A60 09000443 */  j       next_cmd
/* 04001AE4 000A64 00000000 */   nop





cmd_DISABLE:
/* 04001AE8 000A68 20020170 */  addi    v0, zero, 0x170
/* 04001AEC 000A6C 23410500 */  addi    at, cmd_w0, data_0_0500
/* 04001AF0 000A70 48990800 */  mtc2    cmd_w1, $v1[0]
/* 04001AF4 000A74 00191C02 */  srl     v1, cmd_w1, 0x10
/* 04001AF8 000A78 48830900 */  mtc2    v1, $v1[2]
@@loop:
/* 04001AFC 000A7C C8222000 */  lqv     $v2[0], 0x0(at)
/* 04001B00 000A80 2042FFF0 */  addi    v0, v0, -0x10
/* 04001B04 000A84 20210010 */  addi    at, at, 0x10
/* 04001B08 000A88 4B0110C7 */  vmudh   $v3, $v2, $v1[0]
/* 04001B0C 000A8C 4B2118C5 */  vmudm   $v3, $v3, $v1[1]
/* 04001B10 000A90 1C40FFFA */  bgtz    v0, @@loop
/* 04001B14 000A94 E823207F */   sqv    $v3[0], -0x10(at)
/* 04001B18 000A98 09000443 */  j       next_cmd
/* 04001B1C 000A9C 23DEFFF8 */   addi   fp, fp, -8





cmd_RESAMPLE:
/* 04001B20 000AA0 001A1200 */  sll     v0, cmd_w0, 8
/* 04001B24 000AA4 4A17BDEC */  vxor    $v23, $v23, $v23
/* 04001B28 000AA8 00021202 */  srl     v0, v0, 8
/* 04001B2C 000AAC 2003000F */  addi    v1, zero, 0x10-1
/* 04001B30 000AB0 0019AF82 */  srl     s5, cmd_w1, 0x1e
/* 04001B34 000AB4 1EA00012 */  bgtz    s5, .L04001B80
/* 04001B38 000AB8 23010000 */   addi   at, t8, 0
/* 04001B3C 000ABC 40042800 */  mfc0    a0, SP_DMA_FULL
@@dma_full:
/* 04001B40 000AC0 1480FFFF */  bnez    a0, @@dma_full
/* 04001B44 000AC4 40042800 */   mfc0   a0, SP_DMA_FULL
/* 04001B48 000AC8 40810000 */  mtc0    at, SP_MEM_ADDR
/* 04001B4C 000ACC 40820800 */  mtc0    v0, SP_DRAM_ADDR
/* 04001B50 000AD0 40831000 */  mtc0    v1, SP_RD_LEN
/* 04001B54 000AD4 0019A082 */  srl     s4, cmd_w1, 2
/* 04001B58 000AD8 32940FFF */  andi    s4, s4, 0xfff
/* 04001B5C 000ADC 229404F8 */  addi    s4, s4, 0x4f8
/* 04001B60 000AE0 C81F2005 */  lqv     $v31[0], (data_0_0050)(zero)
/* 04001B64 000AE4 C8192004 */  lqv     $v25[0], (data_0_0040)(zero)
/* 04001B68 000AE8 40053000 */  mfc0    a1, SP_DMA_BUSY
@@dma_busy:
/* 04001B6C 000AEC 14A0FFFF */  bnez    a1, @@dma_busy
/* 04001B70 000AF0 40053000 */   mfc0   a1, SP_DMA_BUSY
/* 04001B74 000AF4 CB131800 */  ldv     $v19[0], 0x0(t8)
/* 04001B78 000AF8 090006E7 */  j       .L04001B9C
/* 04001B7C 000AFC CB180F04 */   lsv    $v24[14], 0x8(t8)
.L04001B80:
/* 04001B80 000B00 0019A082 */  srl     s4, cmd_w1, 2
/* 04001B84 000B04 32940FFF */  andi    s4, s4, 0xfff
/* 04001B88 000B08 229404F8 */  addi    s4, s4, 0x4f8
/* 04001B8C 000B0C C81F2005 */  lqv     $v31[0], (data_0_0050)(zero)
/* 04001B90 000B10 4A139CEC */  vxor    $v19, $v19, $v19
/* 04001B94 000B14 C8192004 */  lqv     $v25[0], (data_0_0040)(zero)
/* 04001B98 000B18 4A18C62C */  vxor    $v24, $v24, $v24
.L04001B9C:
/* 04001B9C 000B1C 4894AA00 */  mtc2    s4, $v21[4]
/* 04001BA0 000B20 200400C0 */  addi    a0, zero, data_0_00C0
/* 04001BA4 000B24 4884AB00 */  mtc2    a0, $v21[6]
/* 04001BA8 000B28 4A1FCE51 */  vsub    $v25, $v25, $v31
/* 04001BAC 000B2C 00192382 */  srl     a0, cmd_w1, 0xe
/* 04001BB0 000B30 4884AC00 */  mtc2    a0, $v21[8]
/* 04001BB4 000B34 20040040 */  addi    a0, zero, 0x40
/* 04001BB8 000B38 4884AD00 */  mtc2    a0, $v21[10]
/* 04001BBC 000B3C 4A1FCE51 */  vsub    $v25, $v25, $v31
/* 04001BC0 000B40 C81E2006 */  lqv     $v30[0], (data_0_0060)(zero)
/* 04001BC4 000B44 C81D2007 */  lqv     $v29[0], (data_0_0070)(zero)
/* 04001BC8 000B48 C81C2008 */  lqv     $v28[0], (data_0_0080)(zero)
/* 04001BCC 000B4C 4BF8FE05 */  vmudm   $v24, $v31, $v24[7]
/* 04001BD0 000B50 C81B2009 */  lqv     $v27[0], (data_0_0090)(zero)
/* 04001BD4 000B54 4B95CDCD */  vmadm   $v23, $v25, $v21[4]
/* 04001BD8 000B58 C81A200A */  lqv     $v26[0], (data_0_00A0)(zero)
/* 04001BDC 000B5C 4B1EFE0E */  vmadn   $v24, $v31, $v30[0]
/* 04001BE0 000B60 EA931800 */  sdv     $v19[0], 0x0(s4)
/* 04001BE4 000B64 C8192004 */  lqv     $v25[0], (data_0_0040)(zero)
/* 04001BE8 000B68 4B55FD86 */  vmudn   $v22, $v31, $v21[2]
/* 04001BEC 000B6C 20160170 */  addi    s6, zero, 0x170
/* 04001BF0 000B70 4B5EBD8E */  vmadn   $v22, $v23, $v30[2]
/* 04001BF4 000B74 33240003 */  andi    a0, cmd_w1, 3
/* 04001BF8 000B78 4BB5C504 */  vmudl   $v20, $v24, $v21[5]
/* 04001BFC 000B7C 10800002 */  beqz    a0, .L04001C08
/* 04001C00 000B80 20170500 */   addi   s7, zero, data_0_0500
/* 04001C04 000B84 20170670 */  addi    s7, zero, data_0_0670
.L04001C08:
/* 04001C08 000B88 EB180B84 */  ssv     $v24[7], 0x8(t8)
/* 04001C0C 000B8C 4B9EA506 */  vmudn   $v20, $v20, $v30[4]
/* 04001C10 000B90 E816207B */  sqv     $v22[0], (data_0_0FB0_neg)(zero)
/* 04001C14 000B94 4B75FD0E */  vmadn   $v20, $v31, $v21[3]
/* 04001C18 000B98 E814207C */  sqv     $v20[0], (data_0_0FC0_neg)(zero)
/* 04001C1C 000B9C 84150FB0 */  lh      s5, (data_0_0FB0 + 0)(zero)
/* 04001C20 000BA0 840D0FC0 */  lh      t5, (data_0_0FB0 + 0x10)(zero)
/* 04001C24 000BA4 84110FB8 */  lh      s1, (data_0_0FB0 + 0x8)(zero)
/* 04001C28 000BA8 84090FC8 */  lh      t1, (data_0_0FB0 + 0x18)(zero)
/* 04001C2C 000BAC 84140FB2 */  lh      s4, (data_0_0FB0 + 0x2)(zero)
/* 04001C30 000BB0 840C0FC2 */  lh      t4, (data_0_0FB0 + 0x12)(zero)
/* 04001C34 000BB4 84100FBA */  lh      s0, (data_0_0FB0 + 0xa)(zero)
/* 04001C38 000BB8 84080FCA */  lh      t0, (data_0_0FB0 + 0x1a)(zero)
/* 04001C3C 000BBC 84130FB4 */  lh      s3, (data_0_0FB0 + 0x4)(zero)
/* 04001C40 000BC0 840B0FC4 */  lh      t3, (data_0_0FB0 + 0x14)(zero)
/* 04001C44 000BC4 840F0FBC */  lh      t7, (data_0_0FB0 + 0xc)(zero)
/* 04001C48 000BC8 84070FCC */  lh      a3, (data_0_0FB0 + 0x1c)(zero)
/* 04001C4C 000BCC 84120FB6 */  lh      s2, (data_0_0FB0 + 0x6)(zero)
/* 04001C50 000BD0 840A0FC6 */  lh      t2, (data_0_0FB0 + 0x16)(zero)
/* 04001C54 000BD4 840E0FBE */  lh      t6, (data_0_0FB0 + 0xe)(zero)
/* 04001C58 000BD8 84060FCE */  lh      a2, (data_0_0FB0 + 0x1e)(zero)
.L04001C5C:
/* 04001C5C 000BDC CAB31800 */  ldv     $v19[0], 0x0(s5)
/* 04001C60 000BE0 4BF8FE05 */  vmudm   $v24, $v31, $v24[7]
/* 04001C64 000BE4 C9B21800 */  ldv     $v18[0], 0x0(t5)
/* 04001C68 000BE8 4BF7FE0F */  vmadh   $v24, $v31, $v23[7]
/* 04001C6C 000BEC CA331C00 */  ldv     $v19[8], 0x0(s1)
/* 04001C70 000BF0 4B95CDCD */  vmadm   $v23, $v25, $v21[4]
/* 04001C74 000BF4 C9321C00 */  ldv     $v18[8], 0x0(t1)
/* 04001C78 000BF8 4B1EFE0E */  vmadn   $v24, $v31, $v30[0]
/* 04001C7C 000BFC CA911800 */  ldv     $v17[0], 0x0(s4)
/* 04001C80 000C00 4B55FD86 */  vmudn   $v22, $v31, $v21[2]
/* 04001C84 000C04 C9901800 */  ldv     $v16[0], 0x0(t4)
/* 04001C88 000C08 CA111C00 */  ldv     $v17[8], 0x0(s0)
/* 04001C8C 000C0C 4B5EBD8E */  vmadn   $v22, $v23, $v30[2]
/* 04001C90 000C10 C9101C00 */  ldv     $v16[8], 0x0(t0)
/* 04001C94 000C14 4BB5C504 */  vmudl   $v20, $v24, $v21[5]
/* 04001C98 000C18 CA6F1800 */  ldv     $v15[0], 0x0(s3)
/* 04001C9C 000C1C C96E1800 */  ldv     $v14[0], 0x0(t3)
/* 04001CA0 000C20 C9EF1C00 */  ldv     $v15[8], 0x0(t7)
/* 04001CA4 000C24 C8EE1C00 */  ldv     $v14[8], 0x0(a3)
/* 04001CA8 000C28 4B9EA506 */  vmudn   $v20, $v20, $v30[4]
/* 04001CAC 000C2C CA4D1800 */  ldv     $v13[0], 0x0(s2)
/* 04001CB0 000C30 4B75FD0E */  vmadn   $v20, $v31, $v21[3]
/* 04001CB4 000C34 C94C1800 */  ldv     $v12[0], 0x0(t2)
/* 04001CB8 000C38 C9CD1C00 */  ldv     $v13[8], 0x0(t6)
/* 04001CBC 000C3C 4A129AC0 */  vmulf   $v11, $v19, $v18
/* 04001CC0 000C40 C8CC1C00 */  ldv     $v12[8], 0x0(a2)
/* 04001CC4 000C44 4A108A80 */  vmulf   $v10, $v17, $v16
/* 04001CC8 000C48 E816207B */  sqv     $v22[0], data_0_0FB0_neg(zero)
/* 04001CCC 000C4C 4A0E7A40 */  vmulf   $v9, $v15, $v14
/* 04001CD0 000C50 E814207C */  sqv     $v20[0], data_0_0FC0_neg(zero)
/* 04001CD4 000C54 84150FB0 */  lh      s5, (data_0_0FB0 + 0)(zero)
/* 04001CD8 000C58 840D0FC0 */  lh      t5, (data_0_0FB0 + 0x10)(zero)
/* 04001CDC 000C5C 4A0C6A00 */  vmulf   $v8, $v13, $v12
/* 04001CE0 000C60 84110FB8 */  lh      s1, (data_0_0FB0 + 0x8)(zero)
/* 04001CE4 000C64 4A6B5AD0 */  vadd    $v11, $v11, $v11[1q]
/* 04001CE8 000C68 84090FC8 */  lh      t1, (data_0_0FB0 + 0x18)(zero)
/* 04001CEC 000C6C 4A6A5290 */  vadd    $v10, $v10, $v10[1q]
/* 04001CF0 000C70 84140FB2 */  lh      s4, (data_0_0FB0 + 0x2)(zero)
/* 04001CF4 000C74 4A694A50 */  vadd    $v9, $v9, $v9[1q]
/* 04001CF8 000C78 840C0FC2 */  lh      t4, (data_0_0FB0 + 0x12)(zero)
/* 04001CFC 000C7C 4A684210 */  vadd    $v8, $v8, $v8[1q]
/* 04001D00 000C80 84100FBA */  lh      s0, (data_0_0FB0 + 0xa)(zero)
/* 04001D04 000C84 4ACB5AD0 */  vadd    $v11, $v11, $v11[2h]
/* 04001D08 000C88 84080FCA */  lh      t0, (data_0_0FB0 + 0x1a)(zero)
/* 04001D0C 000C8C 4ACA5290 */  vadd    $v10, $v10, $v10[2h]
/* 04001D10 000C90 84130FB4 */  lh      s3, (data_0_0FB0 + 0x4)(zero)
/* 04001D14 000C94 4AC94A50 */  vadd    $v9, $v9, $v9[2h]
/* 04001D18 000C98 840B0FC4 */  lh      t3, (data_0_0FB0 + 0x14)(zero)
/* 04001D1C 000C9C 4AC84210 */  vadd    $v8, $v8, $v8[2h]
/* 04001D20 000CA0 840F0FBC */  lh      t7, (data_0_0FB0 + 0xc)(zero)
/* 04001D24 000CA4 4A8BE9C6 */  vmudn   $v7, $v29, $v11[0h]
/* 04001D28 000CA8 84070FCC */  lh      a3, (data_0_0FB0 + 0x1c)(zero)
/* 04001D2C 000CAC 4A8AE1CE */  vmadn   $v7, $v28, $v10[0h]
/* 04001D30 000CB0 84120FB6 */  lh      s2, (data_0_0FB0 + 0x6)(zero)
/* 04001D34 000CB4 4A89D9CE */  vmadn   $v7, $v27, $v9[0h]
/* 04001D38 000CB8 840A0FC6 */  lh      t2, (data_0_0FB0 + 0x16)(zero)
/* 04001D3C 000CBC 4A88D1CE */  vmadn   $v7, $v26, $v8[0h]
/* 04001D40 000CC0 840E0FBE */  lh      t6, (data_0_0FB0 + 0xe)(zero)
/* 04001D44 000CC4 84060FCE */  lh      a2, (data_0_0FB0 + 0x1e)(zero)
/* 04001D48 000CC8 22D6FFF0 */  addi    s6, s6, -0x10
/* 04001D4C 000CCC 1AC00003 */  blez    s6, .L04001D5C
/* 04001D50 000CD0 EAE72000 */   sqv    $v7[0], 0x0(s7)
/* 04001D54 000CD4 09000717 */  j       .L04001C5C
/* 04001D58 000CD8 22F70010 */   addi   s7, s7, 0x10
.L04001D5C:
/* 04001D5C 000CDC CAB31800 */  ldv     $v19[0], 0x0(s5)
/* 04001D60 000CE0 EB180804 */  ssv     $v24[0], 0x8(t8)
/* 04001D64 000CE4 0D000466 */  jal     dma_write
/* 04001D68 000CE8 EB131800 */   sdv    $v19[0], 0x0(t8)
/* 04001D6C 000CEC 23DEFFF8 */  addi    fp, fp, -8
/* 04001D70 000CF0 40053000 */  mfc0    a1, SP_DMA_BUSY
@@dma_busy:
/* 04001D74 000CF4 14A0FFFF */  bnez    a1, @@dma_busy
/* 04001D78 000CF8 40053000 */   mfc0   a1, SP_DMA_BUSY
/* 04001D7C 000CFC 09000443 */  j       next_cmd
/* 04001D80 000D00 00000000 */   nop





cmd_ENVMIXER:
/* 04001D84 000D04 00191200 */  sll     v0, cmd_w1, 8
/* 04001D88 000D08 00021202 */  srl     v0, v0, 8
/* 04001D8C 000D0C C81F2005 */  lqv     $v31[0], (data_0_0050)(zero)
/* 04001D90 000D10 C80A2006 */  lqv     $v10[0], (data_0_0060)(zero)
/* 04001D94 000D14 C81E200B */  lqv     $v30[0], (data_0_00B0)(zero)
/* 04001D98 000D18 4A00002C */  vxor    $v0, $v0, $v0
/* 04001D9C 000D1C 001A7402 */  srl     t6, cmd_w0, 0x10
/* 04001DA0 000D20 31CF0001 */  andi    t7, t6, 1
/* 04001DA4 000D24 1DE0000A */  bgtz    t7, .L04001DD0
/* 04001DA8 000D28 23010000 */   addi   at, t8, 0
/* 04001DAC 000D2C 0D00045F */  jal     dma_read
/* 04001DB0 000D30 2003004F */   addi   v1, zero, 0x50-1
/* 04001DB4 000D34 40053000 */  mfc0    a1, SP_DMA_BUSY
@@dma_busy:
/* 04001DB8 000D38 14A0FFFF */  bnez    a1, @@dma_busy
/* 04001DBC 000D3C 40053000 */   mfc0   a1, SP_DMA_BUSY
/* 04001DC0 000D40 CB142000 */  lqv     $v20[0], 0x0(t8)
/* 04001DC4 000D44 CB152001 */  lqv     $v21[0], 0x10(t8)
/* 04001DC8 000D48 CB122002 */  lqv     $v18[0], 0x20(t8)
/* 04001DCC 000D4C CB132003 */  lqv     $v19[0], 0x30(t8)
.L04001DD0:
/* 04001DD0 000D50 CB182004 */  lqv     $v24[0], 0x40(t8)
/* 04001DD4 000D54 20100500 */  addi    s0, zero, data_0_0500
/* 04001DD8 000D58 201509E0 */  addi    s5, zero, data_0_09E0
/* 04001DDC 000D5C 20140B50 */  addi    s4, zero, data_0_0B50
/* 04001DE0 000D60 20130CC0 */  addi    s3, zero, data_0_0CC0
/* 04001DE4 000D64 20120E30 */  addi    s2, zero, data_0_0E30
/* 04001DE8 000D68 20110170 */  addi    s1, zero, 0x170
/* 04001DEC 000D6C 4816C400 */  mfc2    s6, $v24[8]
/* 04001DF0 000D70 4BD8FA68 */  vand    $v9, $v31, $v24[6]
/* 04001DF4 000D74 4BF8FA28 */  vand    $v8, $v31, $v24[7]
/* 04001DF8 000D78 4A090251 */  vsub    $v9, $v0, $v9
/* 04001DFC 000D7C 4A080211 */  vsub    $v8, $v0, $v8
/* 04001E00 000D80 4A09422C */  vxor    $v8, $v8, $v9
/* 04001E04 000D84 11E00035 */  beqz    t7, .L04001EDC
/* 04001E08 000D88 4817C100 */   mfc2   s7, $v24[2]
/* 04001E0C 000D8C 2003004F */  addi    v1, zero, 0x4f
/* 04001E10 000D90 4A14A52C */  vxor    $v20, $v20, $v20
/* 04001E14 000D94 CB140F28 */  lsv     $v20[14], 0x50(t8)
/* 04001E18 000D98 4A15AD6C */  vxor    $v21, $v21, $v21
/* 04001E1C 000D9C CA112000 */  lqv     $v17[0], 0x0(s0)
/* 04001E20 000DA0 4A1294AC */  vxor    $v18, $v18, $v18
/* 04001E24 000DA4 489A9700 */  mtc2    cmd_w0, $v18[14]
/* 04001E28 000DA8 4B58F5C4 */  vmudl   $v23, $v30, $v24[2]
/* 04001E2C 000DAC CABD2000 */  lqv     $v29[0], 0x0(s5)
/* 04001E30 000DB0 4B38F5CE */  vmadn   $v23, $v30, $v24[1]
/* 04001E34 000DB4 CA7B2000 */  lqv     $v27[0], 0x0(s3)
/* 04001E38 000DB8 4BF4FD0F */  vmadh   $v20, $v31, $v20[7]
/* 04001E3C 000DBC CA9C2000 */  lqv     $v28[0], 0x0(s4)
/* 04001E40 000DC0 4B00FD4E */  vmadn   $v21, $v31, $v0[0]
/* 04001E44 000DC4 06E10003 */  bgez    s7, .L04001E54
/* 04001E48 000DC8 4A139CEC */   vxor   $v19, $v19, $v19
/* 04001E4C 000DCC 09000796 */  j       .L04001E4C
/* 04001E50 000DD0 4B18A523 */   vge    $v20, $v20, $v24[0]
.L04001E54:
/* 04001E54 000DD4 4B18A520 */  vlt     $v20, $v20, $v24[0]
.L04001E4C:
/* 04001E58 000DD8 4A114C6C */  vxor    $v17, $v9, $v17
/* 04001E5C 000DDC 4BB8F5C4 */  vmudl   $v23, $v30, $v24[5]
/* 04001E60 000DE0 CA5A2000 */  lqv     $v26[0], 0x0(s2)
/* 04001E64 000DE4 4B98F5CE */  vmadn   $v23, $v30, $v24[4]
/* 04001E68 000DE8 2231FFF0 */  addi    s1, s1, -0x10
/* 04001E6C 000DEC 4BF2FC8F */  vmadh   $v18, $v31, $v18[7]
/* 04001E70 000DF0 22100010 */  addi    s0, s0, 0x10
/* 04001E74 000DF4 4B00FCCE */  vmadn   $v19, $v31, $v0[0]
/* 04001E78 000DF8 4BD8A400 */  vmulf   $v16, $v20, $v24[6]
/* 04001E7C 000DFC 06C10003 */  bgez    s6, .L04001E8C
/* 04001E80 000E00 4BF8A3C0 */   vmulf  $v15, $v20, $v24[7]
/* 04001E84 000E04 090007A4 */  j       .L04001E84
/* 04001E88 000E08 4B7894A3 */   vge    $v18, $v18, $v24[3]
.L04001E8C:
/* 04001E8C 000E0C 4B7894A0 */  vlt     $v18, $v18, $v24[3]
.L04001E84:
/* 04001E90 000E10 4BAAEF40 */  vmulf   $v29, $v29, $v10[5]
/* 04001E94 000E14 4A108F48 */  vmacf   $v29, $v17, $v16
/* 04001E98 000E18 4BAADEC0 */  vmulf   $v27, $v27, $v10[5]
/* 04001E9C 000E1C 4A0F8EC8 */  vmacf   $v27, $v17, $v15
/* 04001EA0 000E20 4A11446C */  vxor    $v17, $v8, $v17
/* 04001EA4 000E24 4BD89400 */  vmulf   $v16, $v18, $v24[6]
/* 04001EA8 000E28 4BF893C0 */  vmulf   $v15, $v18, $v24[7]
/* 04001EAC 000E2C EABD2000 */  sqv     $v29[0], 0x0(s5)
/* 04001EB0 000E30 4BAAE700 */  vmulf   $v28, $v28, $v10[5]
/* 04001EB4 000E34 22B50010 */  addi    s5, s5, 0x10
/* 04001EB8 000E38 4A108F08 */  vmacf   $v28, $v17, $v16
/* 04001EBC 000E3C EA7B2000 */  sqv     $v27[0], 0x0(s3)
/* 04001EC0 000E40 4BAAD680 */  vmulf   $v26, $v26, $v10[5]
/* 04001EC4 000E44 22730010 */  addi    s3, s3, 0x10
/* 04001EC8 000E48 4A0F8E88 */  vmacf   $v26, $v17, $v15
/* 04001ECC 000E4C EA9C2000 */  sqv     $v28[0], 0x0(s4)
/* 04001ED0 000E50 22940010 */  addi    s4, s4, 0x10
/* 04001ED4 000E54 EA5A2000 */  sqv     $v26[0], 0x0(s2)
/* 04001ED8 000E58 22520010 */  addi    s2, s2, 0x10
.L04001EDC:
/* 04001EDC 000E5C 4B58AD54 */  vaddc   $v21, $v21, $v24[2]
/* 04001EE0 000E60 4B38A510 */  vadd    $v20, $v20, $v24[1]
.L04001EE4:
/* 04001EE4 000E64 CABD2000 */  lqv     $v29[0], 0x0(s5)
/* 04001EE8 000E68 4BB89CD4 */  vaddc   $v19, $v19, $v24[5]
/* 04001EEC 000E6C CA112000 */  lqv     $v17[0], 0x0(s0)
/* 04001EF0 000E70 06E10003 */  bgez    s7, .L04001F00
/* 04001EF4 000E74 4B989490 */   vadd   $v18, $v18, $v24[4]
/* 04001EF8 000E78 090007C1 */  j       .L04001F04
/* 04001EFC 000E7C 4B18A523 */   vge    $v20, $v20, $v24[0]
.L04001F00:
/* 04001F00 000E80 4B18A520 */  vlt     $v20, $v20, $v24[0]
.L04001F04:
/* 04001F04 000E84 4A114C6C */  vxor    $v17, $v9, $v17
/* 04001F08 000E88 06C10003 */  bgez    s6, .L04001F18
/* 04001F0C 000E8C CA7B2000 */   lqv    $v27[0], 0x0(s3)
/* 04001F10 000E90 090007C7 */  j       .L04001F10
/* 04001F14 000E94 4B7894A3 */   vge    $v18, $v18, $v24[3]
.L04001F18:
/* 04001F18 000E98 4B7894A0 */  vlt     $v18, $v18, $v24[3]
.L04001F10:
/* 04001F1C 000E9C 4BD8A400 */  vmulf   $v16, $v20, $v24[6]
/* 04001F20 000EA0 EB142000 */  sqv     $v20[0], 0x0(t8)
/* 04001F24 000EA4 4BF8A3C0 */  vmulf   $v15, $v20, $v24[7]
/* 04001F28 000EA8 EB152001 */  sqv     $v21[0], 0x10(t8)
/* 04001F2C 000EAC 4BAAEF40 */  vmulf   $v29, $v29, $v10[5]
/* 04001F30 000EB0 4A108F48 */  vmacf   $v29, $v17, $v16
/* 04001F34 000EB4 CA9C2000 */  lqv     $v28[0], 0x0(s4)
/* 04001F38 000EB8 4BAADEC0 */  vmulf   $v27, $v27, $v10[5]
/* 04001F3C 000EBC CA5A2000 */  lqv     $v26[0], 0x0(s2)
/* 04001F40 000EC0 4A0F8EC8 */  vmacf   $v27, $v17, $v15
/* 04001F44 000EC4 4A11446C */  vxor    $v17, $v8, $v17
/* 04001F48 000EC8 2231FFF0 */  addi    s1, s1, -0x10
/* 04001F4C 000ECC 4B58AD54 */  vaddc   $v21, $v21, $v24[2]
/* 04001F50 000ED0 22100010 */  addi    s0, s0, 0x10
/* 04001F54 000ED4 4B38A510 */  vadd    $v20, $v20, $v24[1]
/* 04001F58 000ED8 EABD2000 */  sqv     $v29[0], 0x0(s5)
/* 04001F5C 000EDC 4BD89400 */  vmulf   $v16, $v18, $v24[6]
/* 04001F60 000EE0 22B50010 */  addi    s5, s5, 0x10
/* 04001F64 000EE4 4BF893C0 */  vmulf   $v15, $v18, $v24[7]
/* 04001F68 000EE8 EA7B2000 */  sqv     $v27[0], 0x0(s3)
/* 04001F6C 000EEC 4BAAE700 */  vmulf   $v28, $v28, $v10[5]
/* 04001F70 000EF0 22730010 */  addi    s3, s3, 0x10
/* 04001F74 000EF4 4A108F08 */  vmacf   $v28, $v17, $v16
/* 04001F78 000EF8 4BAAD680 */  vmulf   $v26, $v26, $v10[5]
/* 04001F7C 000EFC 4A0F8E88 */  vmacf   $v26, $v17, $v15
/* 04001F80 000F00 EA9C2000 */  sqv     $v28[0], 0x0(s4)
/* 04001F84 000F04 22940010 */  addi    s4, s4, 0x10
/* 04001F88 000F08 1A200003 */  blez    s1, .L04001F98
/* 04001F8C 000F0C EA5A2000 */   sqv    $v26[0], 0x0(s2)
/* 04001F90 000F10 090007B9 */  j       .L04001EE4
/* 04001F94 000F14 22520010 */   addi   s2, s2, 0x10
.L04001F98:
/* 04001F98 000F18 EB122002 */  sqv     $v18[0], 0x20(t8)
/* 04001F9C 000F1C EB132003 */  sqv     $v19[0], 0x30(t8)
/* 04001FA0 000F20 0D000466 */  jal     dma_write
/* 04001FA4 000F24 EB182004 */   sqv    $v24[0], 0x40(t8)
/* 04001FA8 000F28 09000443 */  j       next_cmd
/* 04001FAC 000F2C 23DEFFF8 */   addi   fp, fp, -8





cmd_MIXER:
/* 04001FB0 000F30 C81F2006 */  lqv     $v31[0], (data_0_0060)(zero)
/* 04001FB4 000F34 3336FFFF */  andi    s6, cmd_w1, 0xffff
/* 04001FB8 000F38 22D60500 */  addi    s6, s6, 0x500
/* 04001FBC 000F3C CADC2000 */  lqv     $v28[0], 0x0(s6)
/* 04001FC0 000F40 0019BC02 */  srl     s7, cmd_w1, 0x10
/* 04001FC4 000F44 22F70500 */  addi    s7, s7, 0x500
/* 04001FC8 000F48 CAFD2000 */  lqv     $v29[0], 0x0(s7)
/* 04001FCC 000F4C 489AF000 */  mtc2    cmd_w0, $v30[0]
/* 04001FD0 000F50 20150170 */  addi    s5, zero, 0x170
@@loop:
/* 04001FD4 000F54 4BBFE6C0 */  vmulf   $v27, $v28, $v31[5]
/* 04001FD8 000F58 22B5FFF0 */  addi    s5, s5, -0x10
/* 04001FDC 000F5C 22F70010 */  addi    s7, s7, 0x10
/* 04001FE0 000F60 22D60010 */  addi    s6, s6, 0x10
/* 04001FE4 000F64 4B1EEEC8 */  vmacf   $v27, $v29, $v30[0]
/* 04001FE8 000F68 CADC2000 */  lqv     $v28[0], 0x0(s6)
/* 04001FEC 000F6C CAFD2000 */  lqv     $v29[0], 0x0(s7)
/* 04001FF0 000F70 1EA0FFF8 */  bgtz    s5, @@loop
/* 04001FF4 000F74 EADB207F */   sqv    $v27[0], -0x10(s6)
/* 04001FF8 000F78 09000443 */  j       next_cmd
/* 04001FFC 000F7C 23DEFFF8 */   addi   fp, fp, -8

.align 8
Overlay0End:

.if Overlay0End > 0x04002000
    .error "Not enough room in IMEM for Overlay 0"
.endif

.headersize Overlay1LoadAddress - orga()
// OVERLAY 1
Overlay1Address:

cmd_MP3_overlay1:
/* 04001238 000F80 8C110FF4 */  lw      s1, (audioStruct + 0x4)(zero)   // set by MP3ADDY, mp3 address?
/* 0400123C 000F84 8C100FF8 */  lw      s0, (audioStruct + 0x8)(zero)   // ucode_data dram addr
/* 04001240 000F88 8C0F0FFC */  lw      t7, (audioStruct + 0xc)(zero)
/* 04001244 000F8C 02201020 */  add     v0, s1, zero
/* 04001248 000F90 200108A0 */  addi    at, zero, data_1_08A0
/* 0400124C 000F94 0D00045F */  jal     dma_read                        // dma mp3 data
/* 04001250 000F98 2003043F */   addi   v1, zero, 0x440-1
/* 04001254 000F9C 02201020 */  add     v0, s1, zero
/* 04001258 000FA0 200102C0 */  addi    at, zero, nextTaskEntry
/* 0400125C 000FA4 0D000466 */  jal     dma_write                       // write part of dmem over the mp3 data
/* 04001260 000FA8 2003013F */   addi   v1, zero, nextTaskEntry_len-1
/* 04001264 000FAC 0D00046D */  jal     dma_wait
/* 04001268 000FB0 00000000 */   nop
/* 0400126C 000FB4 220202C0 */  addi    v0, s0, orga(Overlay1DataStart)
/* 04001270 000FB8 20010010 */  addi    at, zero, orga(Overlay1DataLoadAddress)
/* 04001274 000FBC 0D00045F */  jal     dma_read
/* 04001278 000FC0 2003088F */   addi   v1, zero, org(Overlay1DataEnd)-org(Overlay1DataStart)-1
/* 0400127C 000FC4 0D00046D */  jal     dma_wait
/* 04001280 000FC8 00000000 */   nop
/* 04001284 000FCC 0019AA00 */  sll     s5, cmd_w1, 8                  // remove top 8 bits
/* 04001288 000FD0 0015AA02 */  srl     s5, s5, 8
/* 0400128C 000FD4 0015B020 */  add     s6, zero, s5                 // save
/* 04001290 000FD8 20030188 */  addi    v1, zero, 0x188
/* 04001294 000FDC 20140480 */  addi    s4, zero, 0x480
/* 04001298 000FE0 00151020 */  add     v0, zero, s5
/* 0400129C 000FE4 22B50008 */  addi    s5, s5, 8
/* 040012A0 000FE8 20010CE8 */  addi    at, zero, data_1_0CE8
/* 040012A4 000FEC 200E08A0 */  addi    t6, zero, data_1_08A0
/* 040012A8 000FF0 21CD0220 */  addi    t5, t6, 0x220
/* 040012AC 000FF4 334C001E */  andi    t4, cmd_w0, 0x1e
mp3_decode_loop:
/* 040012B0 000FF8 0D00045F */  jal     dma_read
/* 040012B4 000FFC 2063FFFF */   addi   v1, v1, -1
/* 040012B8 001000 20030180 */  addi    v1, zero, 0x180
/* 040012BC 001004 2294FE80 */  addi    s4, s4, -0x180
/* 040012C0 001008 20120180 */  addi    s2, zero, 0x180
/* 040012C4 00100C 20170CF0 */  addi    s7, zero, data_1_0CF0
/* 040012C8 001010 0D00046D */  jal     dma_wait
/* 040012CC 001014 20130E70 */   addi   s3, zero, data_1_0E70
mp3_decode_innerloop:
/* 040012D0 001018 31CEFFE0 */  andi    t6, t6, 0xffe0
/* 040012D4 00101C 31ADFFE0 */  andi    t5, t5, 0xffe0
/* 040012D8 001020 01CC7025 */  or      t6, t6, t4
/* 040012DC 001024 01AC6825 */  or      t5, t5, t4
/* 040012E0 001028 CAE00800 */  lsv     $v0[0], 0x0(s7)
/* 040012E4 00102C CAFF081F */  lsv     $v31[0], 0x3e(s7)
/* 040012E8 001030 CAE10801 */  lsv     $v1[0], 0x2(s7)
/* 040012EC 001034 CAFE081E */  lsv     $v30[0], 0x3c(s7)
/* 040012F0 001038 CAE20803 */  lsv     $v2[0], 0x6(s7)
/* 040012F4 00103C CAFC081C */  lsv     $v28[0], 0x38(s7)
/* 040012F8 001040 4A1F0010 */  vadd    $v0, $v0, $v31
/* 040012FC 001044 CAE30802 */  lsv     $v3[0], 0x4(s7)
/* 04001300 001048 CAFD081D */  lsv     $v29[0], 0x3a(s7)
/* 04001304 00104C 4A1E0850 */  vadd    $v1, $v1, $v30
/* 04001308 001050 CAE40807 */  lsv     $v4[0], 0xe(s7)
/* 0400130C 001054 CAF80818 */  lsv     $v24[0], 0x30(s7)
/* 04001310 001058 4A1C1090 */  vadd    $v2, $v2, $v28
/* 04001314 00105C CAE50806 */  lsv     $v5[0], 0xc(s7)
/* 04001318 001060 CAF90819 */  lsv     $v25[0], 0x32(s7)
/* 0400131C 001064 4A1D18D0 */  vadd    $v3, $v3, $v29
/* 04001320 001068 CAE60804 */  lsv     $v6[0], 0x8(s7)
/* 04001324 00106C CAFB081B */  lsv     $v27[0], 0x36(s7)
/* 04001328 001070 4A182110 */  vadd    $v4, $v4, $v24
/* 0400132C 001074 CAE70805 */  lsv     $v7[0], 0xa(s7)
/* 04001330 001078 CAFA081A */  lsv     $v26[0], 0x34(s7)
/* 04001334 00107C 4A192950 */  vadd    $v5, $v5, $v25
/* 04001338 001080 CAE8080F */  lsv     $v8[0], 0x1e(s7)
/* 0400133C 001084 CAF00810 */  lsv     $v16[0], 0x20(s7)
/* 04001340 001088 4A1B3190 */  vadd    $v6, $v6, $v27
/* 04001344 00108C CAE9080E */  lsv     $v9[0], 0x1c(s7)
/* 04001348 001090 CAF10811 */  lsv     $v17[0], 0x22(s7)
/* 0400134C 001094 4A1A39D0 */  vadd    $v7, $v7, $v26
/* 04001350 001098 CAEA080C */  lsv     $v10[0], 0x18(s7)
/* 04001354 00109C CAF30813 */  lsv     $v19[0], 0x26(s7)
/* 04001358 0010A0 4A104210 */  vadd    $v8, $v8, $v16
/* 0400135C 0010A4 CAEB080D */  lsv     $v11[0], 0x1a(s7)
/* 04001360 0010A8 CAF20812 */  lsv     $v18[0], 0x24(s7)
/* 04001364 0010AC 4A114A50 */  vadd    $v9, $v9, $v17
/* 04001368 0010B0 CAEC0808 */  lsv     $v12[0], 0x10(s7)
/* 0400136C 0010B4 CAF70817 */  lsv     $v23[0], 0x2e(s7)
/* 04001370 0010B8 4A135290 */  vadd    $v10, $v10, $v19
/* 04001374 0010BC CAED0809 */  lsv     $v13[0], 0x12(s7)
/* 04001378 0010C0 CAF60816 */  lsv     $v22[0], 0x2c(s7)
/* 0400137C 0010C4 4A125AD0 */  vadd    $v11, $v11, $v18
/* 04001380 0010C8 CAEE080B */  lsv     $v14[0], 0x16(s7)
/* 04001384 0010CC CAF40814 */  lsv     $v20[0], 0x28(s7)
/* 04001388 0010D0 4A176310 */  vadd    $v12, $v12, $v23
/* 0400138C 0010D4 CAEF080A */  lsv     $v15[0], 0x14(s7)
/* 04001390 0010D8 CAF50815 */  lsv     $v21[0], 0x2a(s7)
/* 04001394 0010DC 4A166B50 */  vadd    $v13, $v13, $v22
/* 04001398 0010E0 4A147390 */  vadd    $v14, $v14, $v20
/* 0400139C 0010E4 4A157BD0 */  vadd    $v15, $v15, $v21
/* 040013A0 0010E8 0D0006AC */  jal     func_04001AB0
/* 040013A4 0010EC 00000000 */   nop
/* 040013A8 0010F0 C8002005 */  lqv     $v0[0], (data_1_0050)(zero)
/* 040013AC 0010F4 4A1182D1 */  vsub    $v11, $v16, $v17
/* 040013B0 0010F8 21C80100 */  addi    t0, t6, 0x100
/* 040013B4 0010FC 4A118410 */  vadd    $v16, $v16, $v17
/* 040013B8 001100 21AA0100 */  addi    t2, t5, 0x100
/* 040013BC 001104 4A01086C */  vxor    $v1, $v1, $v1
/* 040013C0 001108 21C90200 */  addi    t1, t6, 0x200
/* 040013C4 00110C 4A100C11 */  vsub    $v16, $v1, $v16
/* 040013C8 001110 21AB0200 */  addi    t3, t5, 0x200
/* 040013CC 001114 4B005AC5 */  vmudm   $v11, $v11, $v0[0]
/* 040013D0 001118 4A139090 */  vadd    $v2, $v18, $v19
/* 040013D4 00111C 4A1390D1 */  vsub    $v3, $v18, $v19
/* 040013D8 001120 E9CB0800 */  ssv     $v11[0], 0x0(t6)
/* 040013DC 001124 4A0B0AD1 */  vsub    $v11, $v1, $v11
/* 040013E0 001128 E9700800 */  ssv     $v16[0], 0x0(t3)
/* 040013E4 00112C E9AB0800 */  ssv     $v11[0], 0x0(t5)
/* 040013E8 001130 4A020891 */  vsub    $v2, $v1, $v2
/* 040013EC 001134 4B601C45 */  vmudm   $v17, $v3, $v0[3]
/* 040013F0 001138 E9420800 */  ssv     $v2[0], 0x0(t2)
/* 040013F4 00113C 4B4018CF */  vmadh   $v3, $v3, $v0[2]
/* 040013F8 001140 4A0218D0 */  vadd    $v3, $v3, $v2
/* 040013FC 001144 E9030800 */  ssv     $v3[0], 0x0(t0)
/* 04001400 001148 4A15A151 */  vsub    $v5, $v20, $v21
/* 04001404 00114C 4A15A110 */  vadd    $v4, $v20, $v21
/* 04001408 001150 4A17B190 */  vadd    $v6, $v22, $v23
/* 0400140C 001154 4A17B1D1 */  vsub    $v7, $v22, $v23
/* 04001410 001158 4B602C45 */  vmudm   $v17, $v5, $v0[3]
/* 04001414 00115C 4B40294F */  vmadh   $v5, $v5, $v0[2]
/* 04001418 001160 4A040911 */  vsub    $v4, $v1, $v4
/* 0400141C 001164 4BA03C45 */  vmudm   $v17, $v7, $v0[5]
/* 04001420 001168 E9640840 */  ssv     $v4[0], -0x80(t3)
/* 04001424 00116C 4B8039CF */  vmadh   $v7, $v7, $v0[4]
/* 04001428 001170 4A042951 */  vsub    $v5, $v5, $v4
/* 0400142C 001174 4A040911 */  vsub    $v4, $v1, $v4
/* 04001430 001178 4A063190 */  vadd    $v6, $v6, $v6
/* 04001434 00117C 4A0539D1 */  vsub    $v7, $v7, $v5
/* 04001438 001180 4A062111 */  vsub    $v4, $v4, $v6
/* 0400143C 001184 4A062951 */  vsub    $v5, $v5, $v6
/* 04001440 001188 E9270840 */  ssv     $v7[0], -0x80(t1)
/* 04001444 00118C E9440840 */  ssv     $v4[0], -0x80(t2)
/* 04001448 001190 E9050840 */  ssv     $v5[0], -0x80(t0)
/* 0400144C 001194 4A19C251 */  vsub    $v9, $v24, $v25
/* 04001450 001198 4A19C210 */  vadd    $v8, $v24, $v25
/* 04001454 00119C 4B604C45 */  vmudm   $v17, $v9, $v0[3]
/* 04001458 0011A0 4B404A4F */  vmadh   $v9, $v9, $v0[2]
/* 0400145C 0011A4 4A1BD2D1 */  vsub    $v11, $v26, $v27
/* 04001460 0011A8 4A1BD290 */  vadd    $v10, $v26, $v27
/* 04001464 0011AC 4A1DE351 */  vsub    $v13, $v28, $v29
/* 04001468 0011B0 4A094090 */  vadd    $v2, $v8, $v9
/* 0400146C 0011B4 4BA05C45 */  vmudm   $v17, $v11, $v0[5]
/* 04001470 0011B8 4B805ACF */  vmadh   $v11, $v11, $v0[4]
/* 04001474 0011BC 4BA06C45 */  vmudm   $v17, $v13, $v0[5]
/* 04001478 0011C0 4B806B4F */  vmadh   $v13, $v13, $v0[4]
/* 0400147C 0011C4 4A1DE310 */  vadd    $v12, $v28, $v29
/* 04001480 0011C8 4A025AD0 */  vadd    $v11, $v11, $v2
/* 04001484 0011CC 4A0A5290 */  vadd    $v10, $v10, $v10
/* 04001488 0011D0 4A026B51 */  vsub    $v13, $v13, $v2
/* 0400148C 0011D4 4A0C6310 */  vadd    $v12, $v12, $v12
/* 04001490 0011D8 4A1FF390 */  vadd    $v14, $v30, $v31
/* 04001494 0011DC 4A1FF3D1 */  vsub    $v15, $v30, $v31
/* 04001498 0011E0 4A0A40D0 */  vadd    $v3, $v8, $v10
/* 0400149C 0011E4 4A0E7390 */  vadd    $v14, $v14, $v14
/* 040014A0 0011E8 4A0C6B50 */  vadd    $v13, $v13, $v12
/* 040014A4 0011EC 4BE07C45 */  vmudm   $v17, $v15, $v0[7]
/* 040014A8 0011F0 4BC07BCF */  vmadh   $v15, $v15, $v0[6]
/* 040014AC 0011F4 4A0E7390 */  vadd    $v14, $v14, $v14
/* 040014B0 0011F8 4A0B7BD1 */  vsub    $v15, $v15, $v11
/* 040014B4 0011FC 4A037391 */  vsub    $v14, $v14, $v3
/* 040014B8 001200 4A0E0B91 */  vsub    $v14, $v1, $v14
/* 040014BC 001204 4A0A6C51 */  vsub    $v17, $v13, $v10
/* 040014C0 001208 4A0E4A50 */  vadd    $v9, $v9, $v14
/* 040014C4 00120C 4A025AD1 */  vsub    $v11, $v11, $v2
/* 040014C8 001210 E9C90820 */  ssv     $v9[0], 0x40(t6)
/* 040014CC 001214 4A0D5AD1 */  vsub    $v11, $v11, $v13
/* 040014D0 001218 E9110860 */  ssv     $v17[0], -0x40(t0)
/* 040014D4 00121C 4A0C4311 */  vsub    $v12, $v8, $v12
/* 040014D8 001220 E90B0820 */  ssv     $v11[0], 0x40(t0)
/* 040014DC 001224 4A080A11 */  vsub    $v8, $v1, $v8
/* 040014E0 001228 E92F0860 */  ssv     $v15[0], -0x40(t1)
/* 040014E4 00122C 4A0A0A91 */  vsub    $v10, $v1, $v10
/* 040014E8 001230 E94C0820 */  ssv     $v12[0], 0x40(t2)
/* 040014EC 001234 E9680860 */  ssv     $v8[0], -0x40(t3)
/* 040014F0 001238 4A0C5291 */  vsub    $v10, $v10, $v12
/* 040014F4 00123C E9AE0820 */  ssv     $v14[0], 0x40(t5)
/* 040014F8 001240 E94A0860 */  ssv     $v10[0], -0x40(t2)
/* 040014FC 001244 CAE00800 */  lsv     $v0[0], 0x0(s7)
/* 04001500 001248 CAFF081F */  lsv     $v31[0], 0x3e(s7)
/* 04001504 00124C CAE10801 */  lsv     $v1[0], 0x2(s7)
/* 04001508 001250 CAFE081E */  lsv     $v30[0], 0x3c(s7)
/* 0400150C 001254 CAE20803 */  lsv     $v2[0], 0x6(s7)
/* 04001510 001258 CAFC081C */  lsv     $v28[0], 0x38(s7)
/* 04001514 00125C CAE30802 */  lsv     $v3[0], 0x4(s7)
/* 04001518 001260 CAFD081D */  lsv     $v29[0], 0x3a(s7)
/* 0400151C 001264 4A1F0011 */  vsub    $v0, $v0, $v31
/* 04001520 001268 C81F2003 */  lqv     $v31[0], (data_0_0030)(zero)
/* 04001524 00126C 4A1E0851 */  vsub    $v1, $v1, $v30
/* 04001528 001270 4A1C1091 */  vsub    $v2, $v2, $v28
/* 0400152C 001274 CAE40807 */  lsv     $v4[0], 0xe(s7)
/* 04001530 001278 4A1D18D1 */  vsub    $v3, $v3, $v29
/* 04001534 00127C CAF80818 */  lsv     $v24[0], 0x30(s7)
/* 04001538 001280 4B1F0005 */  vmudm   $v0, $v0, $v31[0]
/* 0400153C 001284 CAE50806 */  lsv     $v5[0], 0xc(s7)
/* 04001540 001288 4B3F0845 */  vmudm   $v1, $v1, $v31[1]
/* 04001544 00128C CAF90819 */  lsv     $v25[0], 0x32(s7)
/* 04001548 001290 4B7F1085 */  vmudm   $v2, $v2, $v31[3]
/* 0400154C 001294 CAE60804 */  lsv     $v6[0], 0x8(s7)
/* 04001550 001298 4B5F18C5 */  vmudm   $v3, $v3, $v31[2]
/* 04001554 00129C CAFB081B */  lsv     $v27[0], 0x36(s7)
/* 04001558 0012A0 4A000010 */  vadd    $v0, $v0, $v0
/* 0400155C 0012A4 CAE70805 */  lsv     $v7[0], 0xa(s7)
/* 04001560 0012A8 4A010850 */  vadd    $v1, $v1, $v1
/* 04001564 0012AC CAFA081A */  lsv     $v26[0], 0x34(s7)
/* 04001568 0012B0 4A021090 */  vadd    $v2, $v2, $v2
/* 0400156C 0012B4 C81E2004 */  lqv     $v30[0], (data_1_0040)(zero)
/* 04001570 0012B8 4A0318D0 */  vadd    $v3, $v3, $v3
/* 04001574 0012BC CAE8080F */  lsv     $v8[0], 0x1e(s7)
/* 04001578 0012C0 4A182111 */  vsub    $v4, $v4, $v24
/* 0400157C 0012C4 CAF00810 */  lsv     $v16[0], 0x20(s7)
/* 04001580 0012C8 4A192951 */  vsub    $v5, $v5, $v25
/* 04001584 0012CC CAE9080E */  lsv     $v9[0], 0x1c(s7)
/* 04001588 0012D0 4A1B3191 */  vsub    $v6, $v6, $v27
/* 0400158C 0012D4 CAF10811 */  lsv     $v17[0], 0x22(s7)
/* 04001590 0012D8 4A1A39D1 */  vsub    $v7, $v7, $v26
/* 04001594 0012DC CAEA080C */  lsv     $v10[0], 0x18(s7)
/* 04001598 0012E0 4BFF2105 */  vmudm   $v4, $v4, $v31[7]
/* 0400159C 0012E4 CAF30813 */  lsv     $v19[0], 0x26(s7)
/* 040015A0 0012E8 4BDF2945 */  vmudm   $v5, $v5, $v31[6]
/* 040015A4 0012EC CAEB080D */  lsv     $v11[0], 0x1a(s7)
/* 040015A8 0012F0 4B9F3185 */  vmudm   $v6, $v6, $v31[4]
/* 040015AC 0012F4 CAF20812 */  lsv     $v18[0], 0x24(s7)
/* 040015B0 0012F8 4BBF39C5 */  vmudm   $v7, $v7, $v31[5]
/* 040015B4 0012FC 4A042110 */  vadd    $v4, $v4, $v4
/* 040015B8 001300 4A052950 */  vadd    $v5, $v5, $v5
/* 040015BC 001304 4A063190 */  vadd    $v6, $v6, $v6
/* 040015C0 001308 4A0739D0 */  vadd    $v7, $v7, $v7
/* 040015C4 00130C CAEC0808 */  lsv     $v12[0], 0x10(s7)
/* 040015C8 001310 4A104211 */  vsub    $v8, $v8, $v16
/* 040015CC 001314 CAF70817 */  lsv     $v23[0], 0x2e(s7)
/* 040015D0 001318 4A114A51 */  vsub    $v9, $v9, $v17
/* 040015D4 00131C CAED0809 */  lsv     $v13[0], 0x12(s7)
/* 040015D8 001320 4A135291 */  vsub    $v10, $v10, $v19
/* 040015DC 001324 CAF60816 */  lsv     $v22[0], 0x2c(s7)
/* 040015E0 001328 4A125AD1 */  vsub    $v11, $v11, $v18
/* 040015E4 00132C CAEE080B */  lsv     $v14[0], 0x16(s7)
/* 040015E8 001330 4BFE4205 */  vmudm   $v8, $v8, $v30[7]
/* 040015EC 001334 CAF40814 */  lsv     $v20[0], 0x28(s7)
/* 040015F0 001338 4BDE4A45 */  vmudm   $v9, $v9, $v30[6]
/* 040015F4 00133C CAEF080A */  lsv     $v15[0], 0x14(s7)
/* 040015F8 001340 4B9E5285 */  vmudm   $v10, $v10, $v30[4]
/* 040015FC 001344 CAF50815 */  lsv     $v21[0], 0x2a(s7)
/* 04001600 001348 4BBE5AC5 */  vmudm   $v11, $v11, $v30[5]
/* 04001604 00134C 4A176311 */  vsub    $v12, $v12, $v23
/* 04001608 001350 4A166B51 */  vsub    $v13, $v13, $v22
/* 0400160C 001354 4A147391 */  vsub    $v14, $v14, $v20
/* 04001610 001358 4A157BD1 */  vsub    $v15, $v15, $v21
/* 04001614 00135C 4B1E6305 */  vmudm   $v12, $v12, $v30[0]
/* 04001618 001360 4B3E6B45 */  vmudm   $v13, $v13, $v30[1]
/* 0400161C 001364 4B7E7385 */  vmudm   $v14, $v14, $v30[3]
/* 04001620 001368 4B5E7BC5 */  vmudm   $v15, $v15, $v30[2]
/* 04001624 00136C 4A0C6310 */  vadd    $v12, $v12, $v12
/* 04001628 001370 4A0D6B50 */  vadd    $v13, $v13, $v13
/* 0400162C 001374 4A0F7BD0 */  vadd    $v15, $v15, $v15
/* 04001630 001378 0D0006AC */  jal     func_04001AB0
/* 04001634 00137C 00000000 */   nop
/* 04001638 001380 4A139090 */  vadd    $v2, $v18, $v19
/* 0400163C 001384 4A1390D1 */  vsub    $v3, $v18, $v19
/* 04001640 001388 C8132005 */  lqv     $v19[0], (data_1_0050)(zero)
/* 04001644 00138C 4B138005 */  vmudm   $v0, $v16, $v19[0]
/* 04001648 001390 C8122002 */  lqv     $v18[0], (data_1_0020)(zero)
/* 0400164C 001394 4B338848 */  vmacf   $v1, $v17, $v19[1]
/* 04001650 001398 4BD28005 */  vmudm   $v0, $v16, $v18[6]
/* 04001654 00139C 4BD2880D */  vmadm   $v0, $v17, $v18[6]
/* 04001658 0013A0 4A10842C */  vxor    $v16, $v16, $v16
/* 0400165C 0013A4 4A028091 */  vsub    $v2, $v16, $v2
/* 04001660 0013A8 4B731C45 */  vmudm   $v17, $v3, $v19[3]
/* 04001664 0013AC 4B5318CF */  vmadh   $v3, $v3, $v19[2]
/* 04001668 0013B0 4A15A110 */  vadd    $v4, $v20, $v21
/* 0400166C 0013B4 4A002110 */  vadd    $v4, $v4, $v0
/* 04001670 0013B8 4A15A151 */  vsub    $v5, $v20, $v21
/* 04001674 0013BC 4B732C45 */  vmudm   $v17, $v5, $v19[3]
/* 04001678 0013C0 4B53294F */  vmadh   $v5, $v5, $v19[2]
/* 0400167C 0013C4 4A012950 */  vadd    $v5, $v5, $v1
/* 04001680 0013C8 4A17B190 */  vadd    $v6, $v22, $v23
/* 04001684 0013CC 4A063190 */  vadd    $v6, $v6, $v6
/* 04001688 0013D0 4A003190 */  vadd    $v6, $v6, $v0
/* 0400168C 0013D4 4A023191 */  vsub    $v6, $v6, $v2
/* 04001690 0013D8 4A17B1D1 */  vsub    $v7, $v22, $v23
/* 04001694 0013DC 4BB33C45 */  vmudm   $v17, $v7, $v19[5]
/* 04001698 0013E0 4B9339CF */  vmadh   $v7, $v7, $v19[4]
/* 0400169C 0013E4 4A0039D0 */  vadd    $v7, $v7, $v0
/* 040016A0 0013E8 4A008011 */  vsub    $v0, $v16, $v0
/* 040016A4 0013EC 4A0139D0 */  vadd    $v7, $v7, $v1
/* 040016A8 0013F0 E9600870 */  ssv     $v0[0], -0x20(t3)
/* 040016AC 0013F4 4A0339D0 */  vadd    $v7, $v7, $v3
/* 040016B0 0013F8 4A008011 */  vsub    $v0, $v16, $v0
/* 040016B4 0013FC 4A19C210 */  vadd    $v8, $v24, $v25
/* 040016B8 001400 4A19C251 */  vsub    $v9, $v24, $v25
/* 040016BC 001404 4B734C45 */  vmudm   $v17, $v9, $v19[3]
/* 040016C0 001408 4B534A4F */  vmadh   $v9, $v9, $v19[2]
/* 040016C4 00140C 4A1BD290 */  vadd    $v10, $v26, $v27
/* 040016C8 001410 4A0A5290 */  vadd    $v10, $v10, $v10
/* 040016CC 001414 4A085290 */  vadd    $v10, $v10, $v8
/* 040016D0 001418 4A1BD2D1 */  vsub    $v11, $v26, $v27
/* 040016D4 00141C 4BB35C45 */  vmudm   $v17, $v11, $v19[5]
/* 040016D8 001420 4B935ACF */  vmadh   $v11, $v11, $v19[4]
/* 040016DC 001424 4A085AD0 */  vadd    $v11, $v11, $v8
/* 040016E0 001428 4A095AD0 */  vadd    $v11, $v11, $v9
/* 040016E4 00142C 4A1DE310 */  vadd    $v12, $v28, $v29
/* 040016E8 001430 4A0C6310 */  vadd    $v12, $v12, $v12
/* 040016EC 001434 4A0C2311 */  vsub    $v12, $v4, $v12
/* 040016F0 001438 4A1DE351 */  vsub    $v13, $v28, $v29
/* 040016F4 00143C 4BB36C45 */  vmudm   $v17, $v13, $v19[5]
/* 040016F8 001440 E94C0810 */  ssv     $v12[0], 0x20(t2)
/* 040016FC 001444 4B936B4F */  vmadh   $v13, $v13, $v19[4]
/* 04001700 001448 4A0C6B51 */  vsub    $v13, $v13, $v12
/* 04001704 00144C 4A056B51 */  vsub    $v13, $v13, $v5
/* 04001708 001450 4A1FF390 */  vadd    $v14, $v30, $v31
/* 0400170C 001454 4A0E7390 */  vadd    $v14, $v14, $v14
/* 04001710 001458 4A0E7390 */  vadd    $v14, $v14, $v14
/* 04001714 00145C 4A0E3391 */  vsub    $v14, $v6, $v14
/* 04001718 001460 4A1FF3D1 */  vsub    $v15, $v30, $v31
/* 0400171C 001464 4BF37C45 */  vmudm   $v17, $v15, $v19[7]
/* 04001720 001468 E9AE0810 */  ssv     $v14[0], 0x20(t5)
/* 04001724 00146C 4BD37BCF */  vmadh   $v15, $v15, $v19[6]
/* 04001728 001470 4A077BD1 */  vsub    $v15, $v15, $v7
/* 0400172C 001474 4A017390 */  vadd    $v14, $v14, $v1
/* 04001730 001478 E9CE0810 */  ssv     $v14[0], 0x20(t6)
/* 04001734 00147C E92F0870 */  ssv     $v15[0], -0x20(t1)
/* 04001738 001480 4A0A4A50 */  vadd    $v9, $v9, $v10
/* 0400173C 001484 4A060850 */  vadd    $v1, $v1, $v6
/* 04001740 001488 4A065191 */  vsub    $v6, $v10, $v6
/* 04001744 00148C 4A014851 */  vsub    $v1, $v9, $v1
/* 04001748 001490 E9A60830 */  ssv     $v6[0], 0x60(t5)
/* 0400174C 001494 4A025290 */  vadd    $v10, $v10, $v2
/* 04001750 001498 4A0A2291 */  vsub    $v10, $v4, $v10
/* 04001754 00149C E94A0850 */  ssv     $v10[0], -0x60(t2)
/* 04001758 0014A0 4A0C1311 */  vsub    $v12, $v2, $v12
/* 0400175C 0014A4 E94C0870 */  ssv     $v12[0], -0x20(t2)
/* 04001760 0014A8 4A052150 */  vadd    $v5, $v4, $v5
/* 04001764 0014AC 4A044111 */  vsub    $v4, $v8, $v4
/* 04001768 0014B0 E9440830 */  ssv     $v4[0], 0x60(t2)
/* 0400176C 0014B4 4A080011 */  vsub    $v0, $v0, $v8
/* 04001770 0014B8 E9600850 */  ssv     $v0[0], -0x60(t3)
/* 04001774 0014BC 4A0B39D1 */  vsub    $v7, $v7, $v11
/* 04001778 0014C0 E9270850 */  ssv     $v7[0], -0x60(t1)
/* 0400177C 0014C4 4A035AD1 */  vsub    $v11, $v11, $v3
/* 04001780 0014C8 E9C10830 */  ssv     $v1[0], 0x60(t6)
/* 04001784 0014CC 4A055AD1 */  vsub    $v11, $v11, $v5
/* 04001788 0014D0 E90B0830 */  ssv     $v11[0], 0x60(t0)
/* 0400178C 0014D4 4A0D18D1 */  vsub    $v3, $v3, $v13
/* 04001790 0014D8 E9030810 */  ssv     $v3[0], 0x20(t0)
/* 04001794 0014DC 4A026B50 */  vadd    $v13, $v13, $v2
/* 04001798 0014E0 E90D0870 */  ssv     $v13[0], -0x20(t0)
/* 0400179C 0014E4 4A022891 */  vsub    $v2, $v5, $v2
/* 040017A0 0014E8 4A091091 */  vsub    $v2, $v2, $v9
/* 040017A4 0014EC E9020850 */  ssv     $v2[0], -0x60(t0)
/* 040017A8 0014F0 31C9FFE0 */  andi    t1, t6, 0xffe0
/* 040017AC 0014F4 200A0080 */  addi    t2, zero, DeWindowLUT
/* 040017B0 0014F8 014C5022 */  sub     t2, t2, t4
/* 040017B4 0014FC C9222000 */  lqv     $v2[0], 0x0(t1)
/* 040017B8 001500 C9412000 */  lqv     $v1[0], 0x0(t2)
/* 040017BC 001504 C9412801 */  lrv     $v1[0], 0x10(t2)
/* 040017C0 001508 C9242001 */  lqv     $v4[0], 0x10(t1)
/* 040017C4 00150C C9432001 */  lqv     $v3[0], 0x10(t2)
/* 040017C8 001510 C9432802 */  lrv     $v3[0], 0x20(t2)
/* 040017CC 001514 C9262002 */  lqv     $v6[0], 0x20(t1)
/* 040017D0 001518 C9452004 */  lqv     $v5[0], 0x40(t2)
/* 040017D4 00151C C9452805 */  lrv     $v5[0], 0x50(t2)
/* 040017D8 001520 C9282003 */  lqv     $v8[0], 0x30(t1)
/* 040017DC 001524 C9472005 */  lqv     $v7[0], 0x50(t2)
/* 040017E0 001528 C9472806 */  lrv     $v7[0], 0x60(t2)
/* 040017E4 00152C 4A011080 */  vmulf   $v2, $v2, $v1
/* 040017E8 001530 200B0CE8 */  addi    t3, zero, data_1_0CE8
/* 040017EC 001534 4A032100 */  vmulf   $v4, $v4, $v3
/* 040017F0 001538 C9741800 */  ldv     $v20[0], 0x0(t3)
/* 040017F4 00153C 4A053180 */  vmulf   $v6, $v6, $v5
/* 040017F8 001540 200B0008 */  addi    t3, zero, 8
/* 040017FC 001544 4A074200 */  vmulf   $v8, $v8, $v7
.L04001800:
/* 04001800 001548 214A0080 */  addi    t2, t2, 0x80
/* 04001804 00154C 4AC21250 */  vadd    $v9, $v2, $v2[2h]
/* 04001808 001550 21290040 */  addi    t1, t1, 0x40
/* 0400180C 001554 4AC42290 */  vadd    $v10, $v4, $v4[2h]
/* 04001810 001558 C9412000 */  lqv     $v1[0], 0x0(t2)
/* 04001814 00155C 4AC632D0 */  vadd    $v11, $v6, $v6[2h]
/* 04001818 001560 C9412801 */  lrv     $v1[0], 0x10(t2)
/* 0400181C 001564 4AC84310 */  vadd    $v12, $v8, $v8[2h]
/* 04001820 001568 C9432001 */  lqv     $v3[0], 0x10(t2)
/* 04001824 00156C 4AE21350 */  vadd    $v13, $v2, $v2[3h]
/* 04001828 001570 C9432802 */  lrv     $v3[0], 0x20(t2)
/* 0400182C 001574 4AE42390 */  vadd    $v14, $v4, $v4[3h]
/* 04001830 001578 C9452004 */  lqv     $v5[0], 0x40(t2)
/* 04001834 00157C 4AE633D0 */  vadd    $v15, $v6, $v6[3h]
/* 04001838 001580 C9452805 */  lrv     $v5[0], 0x50(t2)
/* 0400183C 001584 4AE84410 */  vadd    $v16, $v8, $v8[3h]
/* 04001840 001588 C9472005 */  lqv     $v7[0], 0x50(t2)
/* 04001844 00158C 4AAD4810 */  vadd    $v0, $v9, $v13[1h]
/* 04001848 001590 C9472806 */  lrv     $v7[0], 0x60(t2)
/* 0400184C 001594 4AAE5450 */  vadd    $v17, $v10, $v14[1h]
/* 04001850 001598 C9222000 */  lqv     $v2[0], 0x0(t1)
/* 04001854 00159C 4AAF5C90 */  vadd    $v18, $v11, $v15[1h]
/* 04001858 0015A0 C9242001 */  lqv     $v4[0], 0x10(t1)
/* 0400185C 0015A4 4AB064D0 */  vadd    $v19, $v12, $v16[1h]
/* 04001860 0015A8 C9262002 */  lqv     $v6[0], 0x20(t1)
/* 04001864 0015AC 4A110010 */  vadd    $v0, $v0, $v17
/* 04001868 0015B0 C9282003 */  lqv     $v8[0], 0x30(t1)
/* 0400186C 0015B4 4A139490 */  vadd    $v18, $v18, $v19
/* 04001870 0015B8 4A011080 */  vmulf   $v2, $v2, $v1
/* 04001874 0015BC 4B800010 */  vadd    $v0, $v0, $v0[4]
/* 04001878 0015C0 4A032100 */  vmulf   $v4, $v4, $v3
/* 0400187C 0015C4 4B929490 */  vadd    $v18, $v18, $v18[4]
/* 04001880 0015C8 4A053180 */  vmulf   $v6, $v6, $v5
/* 04001884 0015CC EA600800 */  ssv     $v0[0], 0x0(s3)
/* 04001888 0015D0 4A074200 */  vmulf   $v8, $v8, $v7
/* 0400188C 0015D4 216BFFFF */  addi    t3, t3, -1
/* 04001890 0015D8 EA720801 */  ssv     $v18[0], 0x2(s3)
/* 04001894 0015DC 1D60FFDA */  bgtz    t3, .L04001800
/* 04001898 0015E0 22730004 */   addi   s3, s3, 4
/* 0400189C 0015E4 4AC21250 */  vadd    $v9, $v2, $v2[2h]
/* 040018A0 0015E8 31880002 */  andi    t0, t4, 2
/* 040018A4 0015EC 4AC42290 */  vadd    $v10, $v4, $v4[2h]
/* 040018A8 0015F0 4AE21350 */  vadd    $v13, $v2, $v2[3h]
/* 040018AC 0015F4 4AE42390 */  vadd    $v14, $v4, $v4[3h]
/* 040018B0 0015F8 4A0A4810 */  vadd    $v0, $v9, $v10
/* 040018B4 0015FC 4B800010 */  vadd    $v0, $v0, $v0[4]
/* 040018B8 001600 4A0E6C50 */  vadd    $v17, $v13, $v14
/* 040018BC 001604 2129FFC0 */  addi    t1, t1, -0x40
/* 040018C0 001608 4BB18C50 */  vadd    $v17, $v17, $v17[5]
/* 040018C4 00160C 4B340085 */  vmudm   $v2, $v0, $v20[1]
/* 040018C8 001610 4B14000F */  vmadh   $v0, $v0, $v20[0]
/* 040018CC 001614 4B348905 */  vmudm   $v4, $v17, $v20[1]
/* 040018D0 001618 200B0CE8 */  addi    t3, zero, data_1_0CE8
/* 040018D4 00161C 4B148C4F */  vmadh   $v17, $v17, $v20[0]
/* 040018D8 001620 15000003 */  bnez    t0, .L040018E8
/* 040018DC 001624 EA600800 */   ssv    $v0[0], 0x0(s3)
/* 040018E0 001628 C9741200 */  llv     $v20[4], 0x0(t3)
/* 040018E4 00162C EA710900 */  ssv     $v17[2], 0x0(s3)
.L040018E8:
/* 040018E8 001630 200A04BE */  addi    t2, zero, DeWindowLUT + 0x43e
/* 040018EC 001634 014C5022 */  sub     t2, t2, t4
/* 040018F0 001638 C9222002 */  lqv     $v2[0], 0x20(t1)
/* 040018F4 00163C C9412000 */  lqv     $v1[0], 0x0(t2)
/* 040018F8 001640 C9412801 */  lrv     $v1[0], 0x10(t2)
/* 040018FC 001644 C9242003 */  lqv     $v4[0], 0x30(t1)
/* 04001900 001648 C9432001 */  lqv     $v3[0], 0x10(t2)
/* 04001904 00164C C9432802 */  lrv     $v3[0], 0x20(t2)
/* 04001908 001650 C9262000 */  lqv     $v6[0], 0x0(t1)
/* 0400190C 001654 C9452004 */  lqv     $v5[0], 0x40(t2)
/* 04001910 001658 C9452805 */  lrv     $v5[0], 0x50(t2)
/* 04001914 00165C C9282001 */  lqv     $v8[0], 0x10(t1)
/* 04001918 001660 C9472005 */  lqv     $v7[0], 0x50(t2)
/* 0400191C 001664 C9472806 */  lrv     $v7[0], 0x60(t2)
/* 04001920 001668 4A011080 */  vmulf   $v2, $v2, $v1
/* 04001924 00166C 200B0008 */  addi    t3, zero, 8
/* 04001928 001670 4A032100 */  vmulf   $v4, $v4, $v3
/* 0400192C 001674 4A053180 */  vmulf   $v6, $v6, $v5
/* 04001930 001678 4A074200 */  vmulf   $v8, $v8, $v7
.L04001934:
/* 04001934 00167C 214A0080 */  addi    t2, t2, 0x80
/* 04001938 001680 4AC21250 */  vadd    $v9, $v2, $v2[2h]
/* 0400193C 001684 2129FFC0 */  addi    t1, t1, -0x40
/* 04001940 001688 4AC42290 */  vadd    $v10, $v4, $v4[2h]
/* 04001944 00168C C9412000 */  lqv     $v1[0], 0x0(t2)
/* 04001948 001690 4AC632D0 */  vadd    $v11, $v6, $v6[2h]
/* 0400194C 001694 C9412801 */  lrv     $v1[0], 0x10(t2)
/* 04001950 001698 4AC84310 */  vadd    $v12, $v8, $v8[2h]
/* 04001954 00169C C9432001 */  lqv     $v3[0], 0x10(t2)
/* 04001958 0016A0 4AE21350 */  vadd    $v13, $v2, $v2[3h]
/* 0400195C 0016A4 C9432802 */  lrv     $v3[0], 0x20(t2)
/* 04001960 0016A8 4AE42390 */  vadd    $v14, $v4, $v4[3h]
/* 04001964 0016AC C9452004 */  lqv     $v5[0], 0x40(t2)
/* 04001968 0016B0 4AE633D0 */  vadd    $v15, $v6, $v6[3h]
/* 0400196C 0016B4 C9452805 */  lrv     $v5[0], 0x50(t2)
/* 04001970 0016B8 4AE84410 */  vadd    $v16, $v8, $v8[3h]
/* 04001974 0016BC C9472005 */  lqv     $v7[0], 0x50(t2)
/* 04001978 0016C0 4AAD4811 */  vsub    $v0, $v9, $v13[1h]
/* 0400197C 0016C4 C9472806 */  lrv     $v7[0], 0x60(t2)
/* 04001980 0016C8 4AAE5451 */  vsub    $v17, $v10, $v14[1h]
/* 04001984 0016CC C9222002 */  lqv     $v2[0], 0x20(t1)
/* 04001988 0016D0 4AAF5C91 */  vsub    $v18, $v11, $v15[1h]
/* 0400198C 0016D4 C9242003 */  lqv     $v4[0], 0x30(t1)
/* 04001990 0016D8 4AB064D1 */  vsub    $v19, $v12, $v16[1h]
/* 04001994 0016DC C9262000 */  lqv     $v6[0], 0x0(t1)
/* 04001998 0016E0 4A110010 */  vadd    $v0, $v0, $v17
/* 0400199C 0016E4 C9282001 */  lqv     $v8[0], 0x10(t1)
/* 040019A0 0016E8 4A139490 */  vadd    $v18, $v18, $v19
/* 040019A4 0016EC 4A011080 */  vmulf   $v2, $v2, $v1
/* 040019A8 0016F0 4B800010 */  vadd    $v0, $v0, $v0[4]
/* 040019AC 0016F4 4A032100 */  vmulf   $v4, $v4, $v3
/* 040019B0 0016F8 4B929490 */  vadd    $v18, $v18, $v18[4]
/* 040019B4 0016FC 216BFFFF */  addi    t3, t3, -1
/* 040019B8 001700 4A053180 */  vmulf   $v6, $v6, $v5
/* 040019BC 001704 EA600801 */  ssv     $v0[0], 0x2(s3)
/* 040019C0 001708 4A074200 */  vmulf   $v8, $v8, $v7
/* 040019C4 00170C EA720802 */  ssv     $v18[0], 0x4(s3)
/* 040019C8 001710 1D60FFDA */  bgtz    t3, .L04001934
/* 040019CC 001714 22730004 */   addi   s3, s3, 4
/* 040019D0 001718 22680002 */  addi    t0, s3, 2
/* 040019D4 00171C CA60207C */  lqv     $v0[0], -0x40(s3)
/* 040019D8 001720 CA71207D */  lqv     $v17[0], -0x30(s3)
/* 040019DC 001724 C902207E */  lqv     $v2[0], -0x20(t0)
/* 040019E0 001728 C902287F */  lrv     $v2[0], -0x10(t0)
/* 040019E4 00172C C904207F */  lqv     $v4[0], -0x10(t0)
/* 040019E8 001730 4B340185 */  vmudm   $v6, $v0, $v20[1]
/* 040019EC 001734 C9042800 */  lrv     $v4[0], 0x0(t0)
/* 040019F0 001738 4B14000F */  vmadh   $v0, $v0, $v20[0]
/* 040019F4 00173C 4B741185 */  vmudm   $v6, $v2, $v20[3]
/* 040019F8 001740 EA60207C */  sqv     $v0[0], -0x40(s3)
/* 040019FC 001744 4B54108F */  vmadh   $v2, $v2, $v20[2]
/* 04001A00 001748 4B348985 */  vmudm   $v6, $v17, $v20[1]
/* 04001A04 00174C E902207E */  sqv     $v2[0], -0x20(t0)
/* 04001A08 001750 E902287F */  srv     $v2[0], -0x10(t0)
/* 04001A0C 001754 4B148C4F */  vmadh   $v17, $v17, $v20[0]
/* 04001A10 001758 4B742185 */  vmudm   $v6, $v4, $v20[3]
/* 04001A14 00175C EA71207D */  sqv     $v17[0], -0x30(s3)
/* 04001A18 001760 4B54210F */  vmadh   $v4, $v4, $v20[2]
/* 04001A1C 001764 E904207F */  sqv     $v4[0], -0x10(t0)
/* 04001A20 001768 E9042800 */  srv     $v4[0], 0x0(t0)
/* 04001A24 00176C 000E5820 */  add     t3, zero, t6
/* 04001A28 001770 000D7020 */  add     t6, zero, t5
/* 04001A2C 001774 000B6820 */  add     t5, zero, t3
/* 04001A30 001778 218CFFFE */  addi    t4, t4, -2
/* 04001A34 00177C 318C001E */  andi    t4, t4, 0x1e
/* 04001A38 001780 2252FFC0 */  addi    s2, s2, -0x40
/* 04001A3C 001784 1E40FE24 */  bgtz    s2, mp3_decode_innerloop
/* 04001A40 001788 22F70040 */   addi   s7, s7, 0x40
/* 04001A44 00178C 20010E70 */  addi    at, zero, data_1_0E70
/* 04001A48 001790 00161020 */  add     v0, zero, s6                  // write out decoded
/* 04001A4C 001794 0D000466 */  jal     dma_write
/* 04001A50 001798 2063FFFF */   addi   v1, v1, -1
/* 04001A54 00179C 20630001 */  addi    v1, v1, 1
/* 04001A58 0017A0 22D60180 */  addi    s6, s6, 0x180
/* 04001A5C 0017A4 22B50180 */  addi    s5, s5, 0x180
/* 04001A60 0017A8 0D00046D */  jal     dma_wait
/* 04001A64 0017AC 00151020 */   add    v0, zero, s5
/* 04001A68 0017B0 1E80FE11 */  bgtz    s4, mp3_decode_loop            // loop until done decoding all
/* 04001A6C 0017B4 20010CF0 */   addi   at, zero, data_1_0CF0
/* 04001A70 0017B8 02201020 */  add     v0, s1, zero
/* 04001A74 0017BC 200102C0 */  addi    at, zero, nextTaskEntry
/* 04001A78 0017C0 0D00045F */  jal     dma_read                        // read back the saved dmem
/* 04001A7C 0017C4 2003013F */   addi   v1, zero, nextTaskEntry_len-1
/* 04001A80 0017C8 200108A0 */  addi    at, zero, data_1_08A0
/* 04001A84 0017CC 0D000466 */  jal     dma_write                       // write back the mp3 data that was pasted over by dmem contents
/* 04001A88 0017D0 2003043F */   addi   v1, zero, 0x440-1
/* 04001A8C 0017D4 8C0B0CE8 */  lw      t3, (data_1_0CE8)(zero)
/* 04001A90 0017D8 0D00046D */  jal     dma_wait                        // wait for dmas to complete
/* 04001A94 0017DC 00000000 */   nop
/* 04001A98 0017E0 AC110FF4 */  sw      s1, (audioStruct + 0x4)(zero)
/* 04001A9C 0017E4 AC100FF8 */  sw      s0, (audioStruct + 0x8)(zero)   // ucode_data dram addr
/* 04001AA0 0017E8 AC0F0FFC */  sw      t7, (audioStruct + 0xc)(zero)
/* 04001AA4 0017EC AC0B0FF0 */  sw      t3, (audioStruct + 0x0)(zero)
/* 04001AA8 0017F0 09000472 */  j       reload_overlay_0
/* 04001AAC 0017F4 00000000 */   nop

func_04001AB0:
/* 04001AB0 0017F8 4A080410 */  vadd    $v16, $v0, $v8
/* 04001AB4 0017FC 4A090C50 */  vadd    $v17, $v1, $v9
/* 04001AB8 001800 4A0A1490 */  vadd    $v18, $v2, $v10
/* 04001ABC 001804 4A0B1CD0 */  vadd    $v19, $v3, $v11
/* 04001AC0 001808 4A0C2510 */  vadd    $v20, $v4, $v12
/* 04001AC4 00180C 4A0D2D50 */  vadd    $v21, $v5, $v13
/* 04001AC8 001810 4A0E3590 */  vadd    $v22, $v6, $v14
/* 04001ACC 001814 4A0F3DD0 */  vadd    $v23, $v7, $v15
/* 04001AD0 001818 4A080611 */  vsub    $v24, $v0, $v8
/* 04001AD4 00181C C8082001 */  lqv     $v8[0], (data_1_0010)(zero)
/* 04001AD8 001820 4A090E51 */  vsub    $v25, $v1, $v9
/* 04001ADC 001824 C8092002 */  lqv     $v9[0], (data_1_0020)(zero)
/* 04001AE0 001828 4A0A1691 */  vsub    $v26, $v2, $v10
/* 04001AE4 00182C 4A0B1ED1 */  vsub    $v27, $v3, $v11
/* 04001AE8 001830 4B08C605 */  vmudm   $v24, $v24, $v8[0]
/* 04001AEC 001834 4B48CE45 */  vmudm   $v25, $v25, $v8[2]
/* 04001AF0 001838 4A0C2711 */  vsub    $v28, $v4, $v12
/* 04001AF4 00183C 4A0D2F51 */  vsub    $v29, $v5, $v13
/* 04001AF8 001840 4BC8D685 */  vmudm   $v26, $v26, $v8[6]
/* 04001AFC 001844 4B88DEC5 */  vmudm   $v27, $v27, $v8[4]
/* 04001B00 001848 4A0E3791 */  vsub    $v30, $v6, $v14
/* 04001B04 00184C 4A0F3FD1 */  vsub    $v31, $v7, $v15
/* 04001B08 001850 4BA9E705 */  vmudm   $v28, $v28, $v9[5]
/* 04001B0C 001854 4B69EF45 */  vmudm   $v29, $v29, $v9[3]
/* 04001B10 001858 4BE8F785 */  vmudm   $v30, $v30, $v8[7]
/* 04001B14 00185C 4B29FFC5 */  vmudm   $v31, $v31, $v9[1]
/* 04001B18 001860 4A148111 */  vsub    $v4, $v16, $v20
/* 04001B1C 001864 4A158951 */  vsub    $v5, $v17, $v21
/* 04001B20 001868 4A148010 */  vadd    $v0, $v16, $v20
/* 04001B24 00186C 4A158850 */  vadd    $v1, $v17, $v21
/* 04001B28 001870 4B282105 */  vmudm   $v4, $v4, $v8[1]
/* 04001B2C 001874 4BA82945 */  vmudm   $v5, $v5, $v8[5]
/* 04001B30 001878 4A169191 */  vsub    $v6, $v18, $v22
/* 04001B34 00187C 4A1799D1 */  vsub    $v7, $v19, $v23
/* 04001B38 001880 4A169090 */  vadd    $v2, $v18, $v22
/* 04001B3C 001884 4A1798D0 */  vadd    $v3, $v19, $v23
/* 04001B40 001888 4B893185 */  vmudm   $v6, $v6, $v9[4]
/* 04001B44 00188C 4B0939C5 */  vmudm   $v7, $v7, $v9[0]
/* 04001B48 001890 4A1CC311 */  vsub    $v12, $v24, $v28
/* 04001B4C 001894 4A1DCB51 */  vsub    $v13, $v25, $v29
/* 04001B50 001898 4A1ED290 */  vadd    $v10, $v26, $v30
/* 04001B54 00189C 4A1FDAD0 */  vadd    $v11, $v27, $v31
/* 04001B58 0018A0 4A1ED391 */  vsub    $v14, $v26, $v30
/* 04001B5C 0018A4 4A1FDBD1 */  vsub    $v15, $v27, $v31
/* 04001B60 0018A8 4B286305 */  vmudm   $v12, $v12, $v8[1]
/* 04001B64 0018AC 4BA86B45 */  vmudm   $v13, $v13, $v8[5]
/* 04001B68 0018B0 4B897385 */  vmudm   $v14, $v14, $v9[4]
/* 04001B6C 0018B4 4B097BC5 */  vmudm   $v15, $v15, $v9[0]
/* 04001B70 0018B8 4A1CC210 */  vadd    $v8, $v24, $v28
/* 04001B74 0018BC 4A1DCA50 */  vadd    $v9, $v25, $v29
/* 04001B78 0018C0 4A020410 */  vadd    $v16, $v0, $v2
/* 04001B7C 0018C4 4A030C50 */  vadd    $v17, $v1, $v3
/* 04001B80 0018C8 4A020491 */  vsub    $v18, $v0, $v2
/* 04001B84 0018CC C8002001 */  lqv     $v0[0], (data_1_0010)(zero)
/* 04001B88 0018D0 4A030CD1 */  vsub    $v19, $v1, $v3
/* 04001B8C 0018D4 C8022002 */  lqv     $v2[0], (data_1_0020)(zero)
/* 04001B90 0018D8 4A062510 */  vadd    $v20, $v4, $v6
/* 04001B94 0018DC 4A072D50 */  vadd    $v21, $v5, $v7
/* 04001B98 0018E0 4A062591 */  vsub    $v22, $v4, $v6
/* 04001B9C 0018E4 4A072DD1 */  vsub    $v23, $v5, $v7
/* 04001BA0 0018E8 4B609485 */  vmudm   $v18, $v18, $v0[3]
/* 04001BA4 0018EC 4B429CC5 */  vmudm   $v19, $v19, $v2[2]
/* 04001BA8 0018F0 4B60B585 */  vmudm   $v22, $v22, $v0[3]
/* 04001BAC 0018F4 4B42BDC5 */  vmudm   $v23, $v23, $v2[2]
/* 04001BB0 0018F8 4A0A4691 */  vsub    $v26, $v8, $v10
/* 04001BB4 0018FC 4A0B4ED1 */  vsub    $v27, $v9, $v11
/* 04001BB8 001900 4A0A4610 */  vadd    $v24, $v8, $v10
/* 04001BBC 001904 4A0B4E50 */  vadd    $v25, $v9, $v11
/* 04001BC0 001908 4B60D685 */  vmudm   $v26, $v26, $v0[3]
/* 04001BC4 00190C 4B42DEC5 */  vmudm   $v27, $v27, $v2[2]
/* 04001BC8 001910 4A0E6791 */  vsub    $v30, $v12, $v14
/* 04001BCC 001914 4A0F6FD1 */  vsub    $v31, $v13, $v15
/* 04001BD0 001918 4A0E6710 */  vadd    $v28, $v12, $v14
/* 04001BD4 00191C 4A0F6F50 */  vadd    $v29, $v13, $v15
/* 04001BD8 001920 4B60F785 */  vmudm   $v30, $v30, $v0[3]
/* 04001BDC 001924 4B42FFC5 */  vmudm   $v31, $v31, $v2[2]
/* 04001BE0 001928 03E00008 */  jr      $ra
/* 04001BE4 00192C 00000000 */   nop

.align 8
Overlay1End:

.if Overlay1End > 0x04002000
    .error "Not enough room in IMEM for Overlay 1"
.endif

.close
