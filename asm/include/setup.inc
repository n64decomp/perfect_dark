.include "asm/include/constants.inc"
.include "asm/include/commands.inc"
.include "asm/include/intro.inc"
.include "asm/include/paths.inc"
.include "asm/include/props.inc"

// Write file header
.data
.word 0
.word 0
.word 0
.word intro
.word props
.word paths
.word functions
.word 0

.if HEADERLEN > 0x20
	.word text_stagename
	.word text_briefing1
	.word text_briefing2
	.word text_briefing3
	.word text_briefing4
	.word text_objective1
	.word text_objective2
	.word text_objective3

	.if HEADERLEN > 0x40
		.word text_objective4
		.word text_objective5
	.endif
.endif
