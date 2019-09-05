# vi: ft=asm

// Only used within this file
.macro generic_object model pad props1 props2 u1 u2 u3 u4 u5 u6 u7 u8 u9 u10 u11 u12 u13 u14 u15 u16 u17 u18 u19
	.short \model
	.short \pad
	.word  \props1
	.word  \props2
	.word  \u1
	.word  \u2
	.word  \u3
	.word  \u4
	.word  \u5
	.word  \u6
	.word  \u7
	.word  \u8
	.word  \u9
	.word  \u10
	.word  \u11
	.word  \u12
	.word  \u13
	.word  \u14
	.word  \u15
	.word  \u16
	.word  \u17
	.word  \u18
	.word  \u19
.endm

.macro door scale model pad props1 props2 u1 u2 u3 u4 u5 u6 u7 u8 u9 u10 u11 u12 u13 u14 u15 u16 u17 u18 u19 u20 u21 u22 u23 u24 u25 u26 u27 u28 u29 u30 u31 u32 u33 u34 u35 u36 u37 u38 u39 u40 u41 u42 u43 u44 u45 u46 u47 u48 u49 u50 u51
	.short \scale
	.short 0x0001
	generic_object \model \pad \props1 \props2 \u1 \u2 \u3 \u4 \u5 \u6 \u7 \u8 \u9 \u10 \u11 \u12 \u13 \u14 \u15 \u16 \u17 \u18 \u19
	.word  \u20
	.word  \u21
	.word  \u22
	.word  \u23
	.word  \u24
	.word  \u25
	.word  \u26
	.word  \u27
	.word  \u28
	.word  \u29
	.word  \u30
	.word  \u31
	.word  \u32
	.word  \u33
	.word  \u34
	.word  \u35
	.word  \u36
	.word  \u37
	.word  \u38
	.word  \u39
	.word  \u40
	.word  \u41
	.word  \u42
	.word  \u43
	.word  \u44
	.word  \u45
	.word  \u46
	.word  \u47
	.word  \u48
	.word  \u49
	.word  \u50
	.word  \u51
.endm

.macro door_scale scale
	.word 0x00000002
	.word \scale
.endm

.macro object scale model pad props1 props2 u1 u2 u3 u4 u5 u6 u7 u8 u9 u10 u11 u12 u13 u14 u15 u16 u17 u18 u19
	.short \scale
	.short 0x0003
	generic_object \model \pad \props1 \props2 \u1 \u2 \u3 \u4 \u5 \u6 \u7 \u8 \u9 \u10 \u11 \u12 \u13 \u14 \u15 \u16 \u17 \u18 \u19
.endm

.macro key scale model pad props1 props2 u1 u2 u3 u4 u5 u6 u7 u8 u9 u10 u11 u12 u13 u14 u15 u16 u17 u18 u19 lockbits
	.short \scale
	.short 0x0004
	generic_object \model \pad \props1 \props2 \u1 \u2 \u3 \u4 \u5 \u6 \u7 \u8 \u9 \u10 \u11 \u12 \u13 \u14 \u15 \u16 \u17 \u18 \u19
	.word  \lockbits
.endm

.macro camera scale model pad props1 props2 u1 u2 u3 u4 u5 u6 u7 u8 u9 u10 u11 u12 u13 u14 u15 u16 u17 u18 u19 u20 u21 u22 u23 u24 u25 u26 u27 u28 u29 u30 u31 u32 u33 u34 u35 u36 u37 u38 u39 u40 u41 u42 u43 u44 u45
	.short \scale
	.short 0x0006
	generic_object \model \pad \props1 \props2 \u1 \u2 \u3 \u4 \u5 \u6 \u7 \u8 \u9 \u10 \u11 \u12 \u13 \u14 \u15 \u16 \u17 \u18 \u19
	.word  \u20
	.word  \u21
	.word  \u22
	.word  \u23
	.word  \u24
	.word  \u25
	.word  \u26
	.word  \u27
	.word  \u28
	.word  \u29
	.word  \u30
	.word  \u31
	.word  \u32
	.word  \u33
	.word  \u34
	.word  \u35
	.word  \u36
	.word  \u37
	.word  \u38
	.word  \u39
	.word  \u40
	.word  \u41
	.word  \u42
	.word  \u43
	.word  \u44
	.word  \u45
.endm

.macro weapon scale model chr props1 props2 u1 u2 u3 u4 u5 u6 u7 u8 u9 u10 u11 u12 u13 u14 u15 u16 u17 u18 u19 weapon u20 u21
	.short \scale
	.short 0x0008
	generic_object \model \chr \props1 \props2 \u1 \u2 \u3 \u4 \u5 \u6 \u7 \u8 \u9 \u10 \u11 \u12 \u13 \u14 \u15 \u16 \u17 \u18 \u19
	.byte  \weapon
	.byte  0
	.short 0
	.word  \u20
	.word  \u21
.endm

.macro ammocrate scale model pad props1 props2 u1 u2 u3 u4 u5 u6 u7 u8 u9 u10 u11 u12 u13 u14 u15 u16 u17 u18 u19 ammotype
	.short \scale
	.short 0x0007
	generic_object \model \pad \props1 \props2 \u1 \u2 \u3 \u4 \u5 \u6 \u7 \u8 \u9 \u10 \u11 \u12 \u13 \u14 \u15 \u16 \u17 \u18 \u19
	.word  \ammotype
.endm

.macro chr unk1 id pad body head function target_pad target_chr hear_dist view_dist props1 bank1flags alliance group chair group2 associated
	.word  0x00000009
	.word  \unk1
	.short \id
	.short \pad
	.byte  \body
	.byte  \head
	.short \function
	.short \target_pad
	.short \target_chr
	.short \hear_dist
	.short \view_dist
	.word  \props1
	.word  \bank1flags
	.byte  \alliance
	.byte  \group
	.short \chair
	.word  \group2
	.word  \associated
.endm

.macro singlemonitor scale model pad props1 props2 u1 u2 u3 u4 u5 u6 u7 u8 u9 u10 u11 u12 u13 u14 u15 u16 u17 u18 u19 u20 u21 u22 u23 u24 u25 u26 u27 u28 u29 u30 u31 u32 u33 u34 u35 u36 u37 u38 u39 u40 u41 u42 u43 u44 u45 u46 u47 u48 u49
	.short \scale
	.short 0x000a
	generic_object \model \pad \props1 \props2 \u1 \u2 \u3 \u4 \u5 \u6 \u7 \u8 \u9 \u10 \u11 \u12 \u13 \u14 \u15 \u16 \u17 \u18 \u19
	.word  \u20
	.word  \u21
	.word  \u22
	.word  \u23
	.word  \u24
	.word  \u25
	.word  \u26
	.word  \u27
	.word  \u28
	.word  \u29
	.word  \u30
	.word  \u31
	.word  \u32
	.word  \u33
	.word  \u34
	.word  \u35
	.word  \u36
	.word  \u37
	.word  \u38
	.word  \u39
	.word  \u40
	.word  \u41
	.word  \u42
	.word  \u43
	.word  \u44
	.word  \u45
	.word  \u46
	.word  \u47
	.word  \u48
	.word  \u49
.endm

.macro multimonitor scale model pad props1 props2 u1 u2 u3 u4 u5 u6 u7 u8 u9 u10 u11 u12 u13 u14 u15 u16 u17 u18 u19 u20 u21 u22 u23 u24 u25 u26 u27 u28 u29 u30 u31 u32 u33 u34 u35 u36 u37 u38 u39 u40 u41 u42 u43 u44 u45 u46 u47 u48 u49 u50 u51 u52 u53 u54 u55 u56 u57 u58 u59 u60 u61 u62 u63 u64 u65 u66 u67 u68 u69 u70 u71 u72 u73 u74 u75 u76 u77 u78 u79 u80 u81 u82 u83 u84 u85 u86 u87 u88 u89 u90 u91 u92 u93 u94 u95 u96 u97 u98 u99 u100 u101 u102 u103 u104 u105 u106 u107 u108 u109 u110 u111 u112 u113 u114 u115 u116 u117 u118 u119 u120 u121 u122 u123 u124 u125 u126 u127 u128 u129 u130 u131 u132 u133 u134 u135 u136
	.short \scale
	.short 0x000b
	generic_object \model \pad \props1 \props2 \u1 \u2 \u3 \u4 \u5 \u6 \u7 \u8 \u9 \u10 \u11 \u12 \u13 \u14 \u15 \u16 \u17 \u18 \u19
	.word  \u20
	.word  \u21
	.word  \u22
	.word  \u23
	.word  \u24
	.word  \u25
	.word  \u26
	.word  \u27
	.word  \u28
	.word  \u29
	.word  \u30
	.word  \u31
	.word  \u32
	.word  \u33
	.word  \u34
	.word  \u35
	.word  \u36
	.word  \u37
	.word  \u38
	.word  \u39
	.word  \u40
	.word  \u41
	.word  \u42
	.word  \u43
	.word  \u44
	.word  \u45
	.word  \u46
	.word  \u47
	.word  \u48
	.word  \u49
	.word  \u50
	.word  \u51
	.word  \u52
	.word  \u53
	.word  \u54
	.word  \u55
	.word  \u56
	.word  \u57
	.word  \u58
	.word  \u59
	.word  \u60
	.word  \u61
	.word  \u62
	.word  \u63
	.word  \u64
	.word  \u65
	.word  \u66
	.word  \u67
	.word  \u68
	.word  \u69
	.word  \u70
	.word  \u71
	.word  \u72
	.word  \u73
	.word  \u74
	.word  \u75
	.word  \u76
	.word  \u77
	.word  \u78
	.word  \u79
	.word  \u80
	.word  \u81
	.word  \u82
	.word  \u83
	.word  \u84
	.word  \u85
	.word  \u86
	.word  \u87
	.word  \u88
	.word  \u89
	.word  \u90
	.word  \u91
	.word  \u92
	.word  \u93
	.word  \u94
	.word  \u95
	.word  \u96
	.word  \u97
	.word  \u98
	.word  \u99
	.word  \u100
	.word  \u101
	.word  \u102
	.word  \u103
	.word  \u104
	.word  \u105
	.word  \u106
	.word  \u107
	.word  \u108
	.word  \u109
	.word  \u110
	.word  \u111
	.word  \u112
	.word  \u113
	.word  \u114
	.word  \u115
	.word  \u116
	.word  \u117
	.word  \u118
	.word  \u119
	.word  \u120
	.word  \u121
	.word  \u122
	.word  \u123
	.word  \u124
	.word  \u125
	.word  \u126
	.word  \u127
	.word  \u128
	.word  \u129
	.word  \u130
	.word  \u131
	.word  \u132
	.word  \u133
	.word  \u134
	.word  \u135
	.word  \u136
.endm

.macro autogun scale model pad props1 props2 u1 u2 u3 u4 u5 u6 u7 u8 u9 u10 u11 u12 u13 u14 u15 u16 u17 u18 u19 u20 u21 u22 u23 u24 u25 u26 u27 u28 u29 u30 u31 u32 u33 u34 u35 u36 u37 u38 u39
	.short \scale
	.short 0x000d
	generic_object \model \pad \props1 \props2 \u1 \u2 \u3 \u4 \u5 \u6 \u7 \u8 \u9 \u10 \u11 \u12 \u13 \u14 \u15 \u16 \u17 \u18 \u19
	.word  \u20
	.word  \u21
	.word  \u22
	.word  \u23
	.word  \u24
	.word  \u25
	.word  \u26
	.word  \u27
	.word  \u28
	.word  \u29
	.word  \u30
	.word  \u31
	.word  \u32
	.word  \u33
	.word  \u34
	.word  \u35
	.word  \u36
	.word  \u37
	.word  \u38
	.word  \u39
.endm

.macro link_collectibles a b
	.word 0x0000000e
	.short \a
	.short \b
.endm

.macro debris scale model pad props1 props2 u1 u2 u3 u4 u5 u6 u7 u8 u9 u10 u11 u12 u13 u14 u15 u16 u17 u18 u19
	.short \scale
	.short 0x000f
	generic_object \model \pad \props1 \props2 \u1 \u2 \u3 \u4 \u5 \u6 \u7 \u8 \u9 \u10 \u11 \u12 \u13 \u14 \u15 \u16 \u17 \u18 \u19
.endm

.macro link_objects u1 u2 u3 u4
	.word 0x00000013
	.word \u1
	.word \u2
	.word \u3
	.word \u4
.endm

.macro ammocratemulti scale model pad props1 props2 u1 u2 u3 u4 u5 u6 u7 u8 u9 u10 u11 u12 u13 u14 u15 u16 u17 u18 u19 u20 u21 u22 u23 u24 u25 u26 u27 u28 u29 u30 u31 u32 u33 u34 u35 u36 u37 u38
	.short \scale
	.short 0x0014
	generic_object \model \pad \props1 \props2 \u1 \u2 \u3 \u4 \u5 \u6 \u7 \u8 \u9 \u10 \u11 \u12 \u13 \u14 \u15 \u16 \u17 \u18 \u19
	.word  \u20
	.word  \u21
	.word  \u22
	.word  \u23
	.word  \u24
	.word  \u25
	.word  \u26
	.word  \u27
	.word  \u28
	.word  \u29
	.word  \u30
	.word  \u31
	.word  \u32
	.word  \u33
	.word  \u34
	.word  \u35
	.word  \u36
	.word  \u37
	.word  \u38
.endm

.macro shield scale model pad props1 props2 u1 u2 u3 u4 u5 u6 u7 u8 u9 u10 u11 u12 u13 u14 u15 u16 u17 u18 u19 u20 u21 u22
	.short \scale
	.short 0x0015
	generic_object \model \pad \props1 \props2 \u1 \u2 \u3 \u4 \u5 \u6 \u7 \u8 \u9 \u10 \u11 \u12 \u13 \u14 \u15 \u16 \u17 \u18 \u19
	.word  \u20
	.word  \u21
	.word  \u22
.endm

.macro tag id value
	.word  0x00000016
	.short \id
	.short \value
	.word  0
	.word  0
.endm

.macro beginobjective value text diffbit
	.word 0x00000017
	.word \value
	.word \text
	.word \diffbit
.endm

.macro endobjective
	.word 0x00000018
.endm

.macro require_object_destroyed object
	.word 0x00000019
	.word \object
.endm

.macro complete_flags stageflag
	.word 0x0000001a
	.word \stageflag
.endm

.macro fail_flags stageflag
	.word 0x0000001b
	.word \stageflag
.endm

.macro require_object_collected object
	.word 0x0000001c
	.word \object
.endm

.macro require_object_thrown object
	.word 0x0000001d
	.word \object
.endm

.macro require_object_holographed object u1 u2
	.word 0x0000001e
	.word \object
	.word \u1
	.word \u2
.endm

.macro require_room_entered room
	.word 0x00000020
	.word \room
.endm

.macro require_object_thrown_on_target throw_object target_object u1
	.word 0x00000021
	.word \throw_object
	.word \target_object
	.word \u1
.endm

.macro briefing value text1
	.word 0x00000023
	.word \value
	.word \text1
	.word 0
.endm

.macro rename_object u1 id text text2 text3 text4 text5 u2 u3
	.word 0x00000025
	.word \u1
	.word \id
	.word \text
	.word \text2
	.word \text3
	.word \text4
	.word \text5
	.word \u2
	.word \u3
.endm

.macro glass scale model pad props1 props2 u1 u2 u3 u4 u5 u6 u7 u8 u9 u10 u11 u12 u13 u14 u15 u16 u17 u18 u19 u20
	.short \scale
	.short 0x002a
	generic_object \model \pad \props1 \props2 \u1 \u2 \u3 \u4 \u5 \u6 \u7 \u8 \u9 \u10 \u11 \u12 \u13 \u14 \u15 \u16 \u17 \u18 \u19
	.word  \u20
.endm

.macro camera2 scale u1 u2 u3 u4 u5 u6
	.short \scale
	.short 0x002e
	.word  \u1
	.word  \u2
	.word  \u3
	.word  \u4
	.word  \u5
	.word  \u6
.endm

.macro tinted_glass scale model pad props1 props2 u1 u2 u3 u4 u5 u6 u7 u8 u9 u10 u11 u12 u13 u14 u15 u16 u17 u18 u19 u20 u21 u22
	.short \scale
	.short 0x002f
	generic_object \model \pad \props1 \props2 \u1 \u2 \u3 \u4 \u5 \u6 \u7 \u8 \u9 \u10 \u11 \u12 \u13 \u14 \u15 \u16 \u17 \u18 \u19
	.word  \u20
	.word  \u21
	.word  \u22
.endm

.macro lift scale model pad props1 props2 u1 u2 u3 u4 u5 u6 u7 u8 u9 u10 u11 u12 u13 u14 u15 u16 u17 u18 u19 pad1 pad2 u20 u21 u22 u23 u24 u25 u26 u27 u28 u29 u30 u31 u32
	.short \scale
	.short 0x0030
	generic_object \model \pad \props1 \props2 \u1 \u2 \u3 \u4 \u5 \u6 \u7 \u8 \u9 \u10 \u11 \u12 \u13 \u14 \u15 \u16 \u17 \u18 \u19
	.short \pad1
	.short \pad2
	.word  \u20
	.word  \u21
	.word  \u22
	.word  \u23
	.word  \u24
	.word  \u25
	.word  \u26
	.word  \u27
	.word  \u28
	.word  \u29
	.word  \u30
	.word  \u31
	.word  \u32
.endm

.macro link_scenery unk1 unk2 unk3
	.word 0x00000031
	.word \unk1
	.word \unk2
	.word \unk3
	.word 0
.endm

.macro link_paths u1 u2 u3
	.word 0x00000032
	.word \u1
	.word \u2
	.word \u3
.endm

.macro hoverbike scale model pad props1 props2 u1 u2 u3 u4 u5 u6 u7 u8 u9 u10 u11 u12 u13 u14 u15 u16 u17 u18 u19 u20 u21 u22 u23 u24 u25 u26 u27 u28 u29 u30 u31 u32 u33 u34 u35 u36 u37 u38 u39 u40 u41 u42 u43 u44 u45 u46 u47 u48 u49 u50 u51 u52
	.short \scale
	.short 0x0033
	generic_object \model \pad \props1 \props2 \u1 \u2 \u3 \u4 \u5 \u6 \u7 \u8 \u9 \u10 \u11 \u12 \u13 \u14 \u15 \u16 \u17 \u18 \u19
	.word  \u20
	.word  \u21
	.word  \u22
	.word  \u23
	.word  \u24
	.word  \u25
	.word  \u26
	.word  \u27
	.word  \u28
	.word  \u29
	.word  \u30
	.word  \u31
	.word  \u32
	.word  \u33
	.word  \u34
	.word  \u35
	.word  \u36
	.word  \u37
	.word  \u38
	.word  \u39
	.word  \u40
	.word  \u41
	.word  \u42
	.word  \u43
	.word  \u44
	.word  \u45
	.word  \u46
	.word  \u47
	.word  \u48
	.word  \u49
	.word  \u50
	.word  \u51
	.word  \u52
.endm

.macro endprops
	.word 0x00000034
.endm

.macro hover_prop scale model pad props1 props2 u1 u2 u3 u4 u5 u6 u7 u8 u9 u10 u11 u12 u13 u14 u15 u16 u17 u18 u19 u20 u21 u22 u23 u24 u25 u26 u27 u28 u29 u30 u31 u32 u33 u34 u35
	.short \scale
	.short 0x0035
	generic_object \model \pad \props1 \props2 \u1 \u2 \u3 \u4 \u5 \u6 \u7 \u8 \u9 \u10 \u11 \u12 \u13 \u14 \u15 \u16 \u17 \u18 \u19
	.word  \u20
	.word  \u21
	.word  \u22
	.word  \u23
	.word  \u24
	.word  \u25
	.word  \u26
	.word  \u27
	.word  \u28
	.word  \u29
	.word  \u30
	.word  \u31
	.word  \u32
	.word  \u33
	.word  \u34
	.word  \u35
.endm

.macro vent_fan scale model pad props1 props2 u1 u2 u3 u4 u5 u6 u7 u8 u9 u10 u11 u12 u13 u14 u15 u16 u17 u18 u19 u20 u21 u22 u23 u24 u25
	.short \scale
	.short 0x0036
	generic_object \model \pad \props1 \props2 \u1 \u2 \u3 \u4 \u5 \u6 \u7 \u8 \u9 \u10 \u11 \u12 \u13 \u14 \u15 \u16 \u17 \u18 \u19
	.word  \u20
	.word  \u21
	.word  \u22
	.word  \u23
	.word  \u24
	.word  \u25
.endm

.macro hover_vehicle scale model pad props1 props2 u1 u2 u3 u4 u5 u6 u7 u8 u9 u10 u11 u12 u13 u14 u15 u16 u17 u18 u19 u20 u21 u22 u23 u24 u25 u26 u27 u28 u29 u30 u31 u32 u33 u34
	.short \scale
	.short 0x0037
	generic_object \model \pad \props1 \props2 \u1 \u2 \u3 \u4 \u5 \u6 \u7 \u8 \u9 \u10 \u11 \u12 \u13 \u14 \u15 \u16 \u17 \u18 \u19
	.word  \u20
	.word  \u21
	.word  \u22
	.word  \u23
	.word  \u24
	.word  \u25
	.word  \u26
	.word  \u27
	.word  \u28
	.word  \u29
	.word  \u30
	.word  \u31
	.word  \u32
	.word  \u33
	.word  \u34
.endm

.macro pad_effect effect pad
	.word 0x00000038
	.word \effect
	.word \pad
.endm

.macro armed_vehicle scale model pad props1 props2 u1 u2 u3 u4 u5 u6 u7 u8 u9 u10 u11 u12 u13 u14 u15 u16 u17 u18 u19 u20 u21 u22 u23 u24 u25 u26 u27 u28 u29 u30 u31 u32 u33 u34 u35 u36 u37 u38 u39 u40 u41 u42 u43 u44 u45 u46 u47 u48 u49 u50 u51 u52 u53 u54
	.short \scale
	.short 0x0039
	generic_object \model \pad \props1 \props2 \u1 \u2 \u3 \u4 \u5 \u6 \u7 \u8 \u9 \u10 \u11 \u12 \u13 \u14 \u15 \u16 \u17 \u18 \u19
	.word  \u20
	.word  \u21
	.word  \u22
	.word  \u23
	.word  \u24
	.word  \u25
	.word  \u26
	.word  \u27
	.word  \u28
	.word  \u29
	.word  \u30
	.word  \u31
	.word  \u32
	.word  \u33
	.word  \u34
	.word  \u35
	.word  \u36
	.word  \u37
	.word  \u38
	.word  \u39
	.word  \u40
	.word  \u41
	.word  \u42
	.word  \u43
	.word  \u44
	.word  \u45
	.word  \u46
	.word  \u47
	.word  \u48
	.word  \u49
	.word  \u50
	.word  \u51
	.word  \u52
	.word  \u53
	.word  \u54
.endm

.macro remote_mine scale model pad props1 props2 u1 u2 u3 u4 u5 u6 u7 u8 u9 u10 u11 u12 u13 u14 u15 u16 u17 u18 u19 u20 u21 u22
	.short \scale
	.short 0x003a
	generic_object \model \pad \props1 \props2 \u1 \u2 \u3 \u4 \u5 \u6 \u7 \u8 \u9 \u10 \u11 \u12 \u13 \u14 \u15 \u16 \u17 \u18 \u19
	.word  \u20
	.word  \u21
	.word  \u22
.endm

.macro escalator scale model pad props1 props2 u1 u2 u3 u4 u5 u6 u7 u8 u9 u10 u11 u12 u13 u14 u15 u16 u17 u18 u19 u20 u21 u22 u23
	.short \scale
	.short 0x003b
	generic_object \model \pad \props1 \props2 \u1 \u2 \u3 \u4 \u5 \u6 \u7 \u8 \u9 \u10 \u11 \u12 \u13 \u14 \u15 \u16 \u17 \u18 \u19
	.word  \u20
	.word  \u21
	.word  \u22
	.word  \u23
.endm
