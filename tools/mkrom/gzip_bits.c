/* bits.c -- output variable-length bit strings
 * Copyright (C) 1992-1993 Jean-loup Gailly
 * This is free software; you can redistribute it and/or modify it under the
 * terms of the GNU General Public License, see the file COPYING.
 */

#include "gzip.h"
#include "crypt.h"

/* ===========================================================================
 * Local data used by the "bit string" routines.
 */

local unsigned short bi_buf;
/* Output buffer. bits are inserted starting at the bottom (least significant
 * bits).
 */

#define Buf_size (8 * 2*sizeof(char))
/* Number of bits used within bi_buf. (bi_buf might be implemented on
 * more than 16 bits on some systems.)
 */

local int bi_valid;
/* Number of valid bits in bi_buf.  All bits above the last valid bit
 * are always zero.
 */

/* ===========================================================================
 * Initialize the bit string routines.
 */
void bi_init(void)
{
	bi_buf = 0;
	bi_valid = 0;
}

/* ===========================================================================
 * Send a value on a given number of bits.
 * IN assertion: length <= 16 and value fits in length bits.
 */
void send_bits(value, length)
	int value;  /* value to send */
	int length; /* number of bits */
{
	/* If not enough room in bi_buf, use (valid) bits from bi_buf and
	 * (16 - bi_valid) bits from value, leaving (width - (16-bi_valid))
	 * unused bits in value.
	 */
	if (bi_valid > (int)Buf_size - length) {
		bi_buf |= (value << bi_valid);
		put_short(bi_buf);
		bi_buf = (ush)value >> (Buf_size - bi_valid);
		bi_valid += length - Buf_size;
	} else {
		bi_buf |= value << bi_valid;
		bi_valid += length;
	}
}

/* ===========================================================================
 * Reverse the first len bits of a code, using straightforward code (a faster
 * method would use a table)
 * IN assertion: 1 <= len <= 15
 */
unsigned bi_reverse(code, len)
	unsigned code; /* the value to invert */
	int len;       /* its bit length */
{
	register unsigned res = 0;
	do {
		res |= code & 1;
		code >>= 1, res <<= 1;
	} while (--len > 0);
	return res >> 1;
}

/* ===========================================================================
 * Write out any remaining bits in an incomplete byte.
 */
void bi_windup()
{
	if (bi_valid > 8) {
		put_short(bi_buf);
	} else if (bi_valid > 0) {
		put_byte(bi_buf);
	}
	bi_buf = 0;
	bi_valid = 0;
}

/* ===========================================================================
 * Copy a stored block to the zip file, storing first the length and its
 * one's complement if requested.
 */
void copy_block(buf, len, header)
	char     *buf;    /* the input data */
	unsigned len;     /* its length */
	int      header;  /* true if block header must be written */
{
	bi_windup();              /* align on byte boundary */

	if (header) {
		put_short((ush)len);
		put_short((ush)~len);
	}
	while (len--) {
		put_byte(*buf++);
	}
}

void flush_outbuf()
{
	if (outcnt == 0) return;

	write_buf((char *)outbuf, outcnt);
	outcnt = 0;
}
