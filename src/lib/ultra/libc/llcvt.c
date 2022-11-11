#include "constants.h"

/**
 * IDO's __f_to_ll is gcc's __fixsfdi
 * IDO's __f_to_ull is gcc's __fixunssfdi
 * IDO's __ll_to_d is gcc's __floatdidf
 * IDO's __ull_to_f is gcc's __floatundisf
 */

__asm__("                                       \n\
		.set push                               \n\
		.set noat                               \n\
		.set noreorder                          \n\
		.set gp=64                              \n\
		                                        \n\
		.global __fixsfdi                       \n\
		__fixsfdi:                              \n\
		.type __fixsfdi, @function              \n\
		.ent __fixsfdi                          \n\
		trunc.l.s  $f4, $f12                    \n\
		dmfc1      $v0, $f4                     \n\
		nop                                     \n\
		dsll32     $v1, $v0, 0                  \n\
		dsra32     $v1, $v1, 0                  \n\
		jr         $ra                          \n\
		dsra32     $v0, $v0, 0                  \n\
		.end __fixsfdi                          \n\
		.size __fixsfdi, . - __fixsfdi          \n\
		                                        \n\
		.global __fixunssfdi                    \n\
		__fixunssfdi:                           \n\
		.type __fixunssfdi, @function           \n\
		.ent __fixunssfdi                       \n\
		cfc1       $t6, $31                     \n\
		addiu      $v0, $zero, 1                \n\
		ctc1       $v0, $31                     \n\
		nop                                     \n\
		cvt.l.s    $f4, $f12                    \n\
		cfc1       $v0, $31                     \n\
		nop                                     \n\
		andi       $at, $v0, 4                  \n\
		andi       $v0, $v0, 0x78               \n\
		beqz       $v0, 2f                      \n\
		lui        $at, 0x5f00                  \n\
		mtc1       $at, $f4                     \n\
		addiu      $v0, $zero, 1                \n\
		sub.s      $f4, $f12, $f4               \n\
		ctc1       $v0, $31                     \n\
		nop                                     \n\
		cvt.l.s    $f4, $f4                     \n\
		cfc1       $v0, $31                     \n\
		nop                                     \n\
		andi       $at, $v0, 4                  \n\
		andi       $v0, $v0, 0x78               \n\
		bnez       $v0, 1f                      \n\
		nop                                     \n\
		lui        $t7, 0x8000                  \n\
		dsll32     $t7, $t7, 0                  \n\
		dmfc1      $v0, $f4                     \n\
		b          3f                           \n\
		or         $v0, $v0, $t7                \n\
		1:                                      \n\
		b          3f                           \n\
		addiu      $v0, $zero, -1               \n\
		2:                                      \n\
		dmfc1      $v0, $f4                     \n\
		nop                                     \n\
		bltz       $v0, 1b                      \n\
		nop                                     \n\
		3:                                      \n\
		ctc1       $t6, $31                     \n\
		dsll32     $v1, $v0, 0                  \n\
		dsra32     $v1, $v1, 0                  \n\
		jr         $ra                          \n\
		dsra32     $v0, $v0, 0                  \n\
		.end __fixunssfdi                       \n\
		.size __fixunssfdi, . - __fixunssfdi    \n\
		                                        \n\
		.global __floatdidf                     \n\
		__floatdidf:                            \n\
		.type __floatdidf, @function            \n\
		.ent __floatdidf                        \n\
		sw         $a0, 0($sp)                  \n\
		sw         $a1, 4($sp)                  \n\
		ld         $t6, 0($sp)                  \n\
		dmtc1      $t6, $f4                     \n\
		jr         $ra                          \n\
		cvt.d.l    $f0, $f4                     \n\
		.end __floatdidf                        \n\
		.size __floatdidf, . - __floatdidf      \n\
		                                        \n\
		.global __floatundisf                   \n\
		__floatundisf:                          \n\
		.type __floatundisf, @function          \n\
		.ent __floatundisf                      \n\
		sw       $a0, 0($sp)                    \n\
		sw       $a1, 4($sp)                    \n\
		ld       $t6, 0($sp)                    \n\
		dmtc1    $t6, $f4                       \n\
		bgez     $t6, 1f                        \n\
		cvt.s.l  $f0, $f4                       \n\
		lui      $at, 0x4f80                    \n\
		mtc1     $at, $f6                       \n\
		nop                                     \n\
		add.s    $f0, $f0, $f6                  \n\
		1:                                      \n\
		jr       $ra                            \n\
		nop                                     \n\
		.end __floatundisf                      \n\
		.size __floatundisf, . - __floatundisf  \n\
		                                        \n\
		.set pop                                \n\
		\n");
