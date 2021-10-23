#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "gzip.h"

/**
 * This file is mkrom's interface to gzip.
 *
 * The key thing here is that we need to be able to set the uninitialised data
 * in the window buffer that gzip uses. This is required for a matching build
 * and is the reason why mkrom must be written in C.
 *
 * Much of the gzip code has been ripped out, including file functionality and
 * many, many global variables that it uses.
 */

#define BITS 16

// This global variable is required by gzip
unsigned outcnt;       /* bytes in gzip's output buffer (not ours) */

DECLARE(uch, inbuf,  INBUFSIZ +INBUF_EXTRA);
DECLARE(uch, outbuf, OUTBUFSIZ+OUTBUF_EXTRA);
DECLARE(ush, d_buf,  DIST_BUFSIZE);
DECLARE(uch, window, 2L*WSIZE);
DECLARE(ush, tab_prefix, 1L<<BITS);

// These global variables are used to allow
// us to work with gzip's input/output system
unsigned len_remaining;
uint8_t *inptr;
uint8_t *outptr;

static void zip(uint8_t *outbuffer, size_t *outlen, uint8_t *inbuffer, size_t inlen, uint32_t magic)
{
	// Set up pointers to the buffers.
	// We'll move the pointers forward as gzip requests data be read or written
	inptr = inbuffer;
	outptr = outbuffer;
	len_remaining = inlen;

	// Here we're setting some "uninitialised" data in the window.
	// Older versions of gzip are influenced by whatever data happened
	// to be in the window immediately after the end of the input.
	// Each game zip is 0x1000 long uncompressed.
	// The magic values differ per ROM version and are specified as mkrom args.
	window[0x1000] = (magic >> 8) & 0xff;
	window[0x1001] = magic & 0xff;

	outcnt = 0;

	// Begin calling gzip routines
	bi_init();
	ct_init();
	lm_init();

	deflate();
	flush_outbuf();

	*outlen = outptr - outbuffer;
}

/**
 * Write the RareZip header (0x1173 followed by original file size)
 * to the buffer followed by the compressed data.
 *
 * It's up to the caller to allocate an output buffer big enough.
 */
void rarezip(uint8_t *outbuffer, size_t *outlen, uint8_t *inbuffer, size_t inlen, uint32_t magic)
{
	outbuffer[0] = 0x11;
	outbuffer[1] = 0x73;
	outbuffer[2] = (inlen >> 16) & 0xff;
	outbuffer[3] = (inlen >> 8) & 0xff;
	outbuffer[4] = inlen & 0xff;

	zip(&outbuffer[5], outlen, inbuffer, inlen, magic);

	*outlen += 5;
}

/**
 * This function is called by gzip when it wants more data.
 */
int read_buf(char *buf, unsigned size)
{
	if (size > len_remaining) {
		size = len_remaining;
	}

	memcpy(buf, inptr, size);

	len_remaining -= size;
	inptr += size;

	return size;
}

/**
 * This function is called by gzip when it wants to output data.
 */
void write_buf(voidp buf, unsigned size)
{
	memcpy(outptr, buf, size);
	outptr += size;
}
