/* gzip.h -- common declarations for all gzip modules
 * Copyright (C) 1992-1993 Jean-loup Gailly.
 * This is free software; you can redistribute it and/or modify it under the
 * terms of the GNU General Public License, see the file COPYING.
 */

#if defined(__STDC__)
#  define OF(args)  args
#else
#  define OF(args)  ()
#endif

#ifdef __STDC__
	typedef void *voidp;
#else
	typedef char *voidp;
#endif

/* I don't like nested includes, but the string and io functions are used
 * too often
 */
#include <stdio.h>
#if !defined(NO_STRING_H) || defined(STDC_HEADERS)
#  include <string.h>
#  if !defined(STDC_HEADERS) && !defined(NO_MEMORY_H) && !defined(__GNUC__)
#    include <memory.h>
#  endif
#  define memzero(s, n)     memset ((voidp)(s), 0, (n))
#else
#  include <strings.h>
#  define strchr            index
#  define strrchr           rindex
#  define memcpy(d, s, n)   bcopy((s), (d), (n))
#  define memcmp(s1, s2, n) bcmp((s1), (s2), (n))
#  define memzero(s, n)     bzero((s), (n))
#endif

#ifndef RETSIGTYPE
#  define RETSIGTYPE void
#endif

#define local static

typedef unsigned char  uch;
typedef unsigned short ush;
typedef unsigned long  ulg;

/* Compression methods (see algorithm.doc) */
#define STORED      0
#define COMPRESSED  1
#define PACKED      2
#define LZHED       3
/* methods 4 to 7 reserved */
#define DEFLATED    8
#define MAX_METHODS 9

#ifndef	INBUFSIZ
#  ifdef SMALL_MEM
#    define INBUFSIZ  0x2000  /* input buffer size */
#  else
#    define INBUFSIZ  0x8000  /* input buffer size */
#  endif
#endif
#define INBUF_EXTRA  64     /* required by unlzw() */

#ifndef	OUTBUFSIZ
#  ifdef SMALL_MEM
#    define OUTBUFSIZ   8192  /* output buffer size */
#  else
#    define OUTBUFSIZ  16384  /* output buffer size */
#  endif
#endif
#define OUTBUF_EXTRA 2048   /* required by unlzw() */

#ifndef DIST_BUFSIZE
#  ifdef SMALL_MEM
#    define DIST_BUFSIZE 0x2000 /* buffer for distances, see trees.c */
#  else
#    define DIST_BUFSIZE 0x8000 /* buffer for distances, see trees.c */
#  endif
#endif

#define EXTERN(type, array)  extern type array[]
#define DECLARE(type, array, size)  type array[size]
#define ALLOC(type, array, size)
#define FREE(array)

EXTERN(uch, inbuf);          /* input buffer */
EXTERN(uch, outbuf);         /* output buffer */
EXTERN(ush, d_buf);          /* buffer for distances, see trees.c */
EXTERN(uch, window);         /* Sliding window and suffix table (unlzw) */
#define tab_suffix window
#ifndef MAXSEG_64K
#  define tab_prefix prev    /* hash link (see deflate.c) */
#  define head (prev+WSIZE)  /* hash head (see deflate.c) */
	EXTERN(ush, tab_prefix);  /* prefix code (see unlzw.c) */
#else
#  define tab_prefix0 prev
#  define head tab_prefix1
	EXTERN(ush, tab_prefix0); /* prefix for even codes */
	EXTERN(ush, tab_prefix1); /* prefix for odd  codes */
#endif

extern unsigned outcnt; /* bytes in output buffer */

/* for compatibility with old zip sources (to be cleaned) */

typedef int file_t;     /* Do not use stdio */
#define NO_FILE  (-1)   /* in memory compression */

/* internal file attribute */
#define UNKNOWN 0xffff
#define BINARY  0
#define ASCII   1

#ifndef WSIZE
#  define WSIZE 0x8000     /* window size--must be a power of two, and */
#endif                     /*  at least 32K for zip's deflate method */

#define MIN_MATCH  3
#define MAX_MATCH  258
/* The minimum and maximum match lengths */

#define MIN_LOOKAHEAD (MAX_MATCH+MIN_MATCH+1)
/* Minimum amount of lookahead, except at the end of the input file.
 * See deflate.c for comments about the MIN_MATCH+1.
 */

#define MAX_DIST  (WSIZE-MIN_LOOKAHEAD)
/* In order to simplify the code, particularly on 16 bit machines, match
 * distances are limited to MAX_DIST instead of WSIZE.
 */

/* put_byte is used for the compressed output, put_ubyte for the
 * uncompressed output. However unlzw() uses window for its
 * suffix table instead of its output buffer, so it does not use put_ubyte
 * (to be cleaned up).
 */
#define put_byte(c) {outbuf[outcnt++]=(uch)(c); if (outcnt==OUTBUFSIZ)\
	flush_outbuf();}

/* Output a 16 bit value, lsb first */
#define put_short(w) \
	{ if (outcnt < OUTBUFSIZ-2) { \
		outbuf[outcnt++] = (uch) ((w) & 0xff); \
		outbuf[outcnt++] = (uch) ((ush)(w) >> 8); \
	} else { \
		put_byte((uch)((w) & 0xff)); \
		put_byte((uch)((ush)(w) >> 8)); \
	} \
	}

#define seekable()    0  /* force sequential output */

/* in gzip.c */
RETSIGTYPE abort_gzip OF((void));

/* in deflate.c */
void lm_init OF((void));
ulg  deflate OF((void));

/* in trees.c */
void ct_init     OF((void));
int  ct_tally    OF((int dist, int lc));
ulg  flush_block OF((char *buf, ulg stored_len, int eof));

/* in bits.c */
void     bi_init    OF((void));
void     send_bits  OF((int value, int length));
unsigned bi_reverse OF((unsigned value, int length));
void     bi_windup  OF((void));
void     copy_block OF((char *buf, unsigned len, int header));
extern   int read_buf OF((char *buf, unsigned size));

/* in util.c: */
extern void flush_outbuf  OF((void));
extern void write_buf     OF((voidp buf, unsigned cnt));
extern void warn          OF((char *a, char *b));
