# Assembly Macros

.macro glabel label
    .global \label
    \label:
.endm

