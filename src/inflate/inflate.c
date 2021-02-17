#include <ultra64.h>
#include "constants.h"
#include "inflate/inflate.h"
#include "data.h"
#include "types.h"

#define GETBYTE()   (inbuf[inptr++])
#define NEXTBYTE()  (u8)GETBYTE()
#define NEEDBITS(n) {while(k<(n)){b|=((u32)NEXTBYTE())<<k;k+=8;}}
#define DUMPBITS(n) {b>>=(n);k-=(n);}

#define BMAX 16
#define N_MAX 288

u8 *inbuf = 0;
u8 *outbuf = 0;

u32 inptr = 0;
u32 wp = 0;
struct huft *huftlist = NULL;

u8 border[] = { /* Order of the bit length code lengths */
        16, 17, 18, 0, 8, 7, 9, 6, 10, 5, 11, 4, 12, 3, 13, 2, 14, 1, 15};

/* Tables for deflate from PKZIP's appnote.txt. */
u16 cplens[] = { /* Copy lengths for literal codes 257..285 */
        3, 4, 5, 6, 7, 8, 9, 10, 11, 13, 15, 17, 19, 23, 27, 31,
        35, 43, 51, 59, 67, 83, 99, 115, 131, 163, 195, 227, 258, 0, 0};

        /* actually lengths - 2; also see note #13 above about 258 */
u8 cplext[] = { /* Extra bits for literal codes 257..285 */
        0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 2, 2, 2, 2,
        3, 3, 3, 3, 4, 4, 4, 4, 5, 5, 5, 5, 0, 99, 99}; /* 128==invalid */

u16 cpdist[] = { /* Copy offsets for distance codes 0..29 */
        1, 2, 3, 4, 5, 7, 9, 13, 17, 25, 33, 49, 65, 97, 129, 193,
        257, 385, 513, 769, 1025, 1537, 2049, 3073, 4097, 6145,
        8193, 12289, 16385, 24577};

u8 cpdext[] = { /* Extra bits for distance codes */
        0, 0, 0, 0, 1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6,
        7, 7, 8, 8, 9, 9, 10, 10, 11, 11,
        12, 12, 13, 13};

u32 bb = 0;
u32 bk = 0;

/* And'ing with mask[n] masks the lower n bits */
u16 mask_bits[] = {
    0x0000,
    0x0001, 0x0003, 0x0007, 0x000f, 0x001f, 0x003f, 0x007f, 0x00ff,
    0x01ff, 0x03ff, 0x07ff, 0x0fff, 0x1fff, 0x3fff, 0x7fff, 0xffff
};

u32 lbits = 9;
u32 dbits = 6;
u32 hufts = 0;

/**
 * Given a list of code lengths and a maximum table size, make a set of
 * tables to decode that set of codes.
 *
 * b = code lengths in bits (all assumed <= BMAX)
 * n = number of codes (assumed <= N_MAX)
 * s = number of simple-valued codes (0..s-1)
 * d = list of base values for non-simple codes
 * e = list of extra bits for non-simple codes
 * t = result: starting table
 * m = maximum lookup bits, returns actual
 */
s32 huft_build(u32 *b, u32 n, u32 s, u16 *d, u8 *e, struct huft **t, s32 *m)
{
	u32 a;                   /* counter for codes of length k */
	u32 c[BMAX+1];           /* bit length count table */
	u32 f;                   /* i repeats in table every f entries */
	s32 g;                   /* maximum code length */
	s32 h;                   /* table level */
	register u32 i;          /* counter, current code */
	register u32 j;          /* counter */
	register s32 k;          /* number of bits in current code */
	s32 l;                   /* bits per table (returned in m) */
	register u32 *p;         /* pointer into c[], b[], or v[] */
	register struct huft *q; /* points to current table */
	struct huft r;           /* table entry for structure assignment */
	struct huft *u[BMAX];    /* table stack */
	u32 v[N_MAX];            /* values in order of bit length */
	register s32 w;          /* bits before this table == (l * h) */
	u32 x[BMAX+1];           /* bit offsets, then code stack */
	u32 *xp;                 /* pointer into x */
	s32 y;                   /* number of dummy codes added */
	u32 z;                   /* number of entries in current table */
	u32 i2;

	/* Generate counts for each bit length */
	for (i2 = 0; i2 != BMAX + 1; i2++) {
		c[i2] = 0;
	}

	p = b;
	i = n;

	do {
		c[*p]++;                  /* assume all entries <= BMAX */
		p++;                      /* Can't combine with above line (Solaris bug) */
	} while (--i);

	if (c[0] == n) {              /* null input--all zero length codes */
		*t = NULL;
		*m = 0;
		return 0;
	}

	/* Find minimum and maximum length, bound *m by those */
	l = *m;

	for (j = 1; j <= BMAX; j++) {
		if (c[j]) {
			break;
		}
	}

	k = j;                        /* minimum code length */

	if (l < j) {
		l = j;
	}

	for (i = BMAX; i; i--) {
		if (c[i]) {
			break;
		}
	}

	g = i;                        /* maximum code length */

	if (l > i) {
		l = i;
	}

	*m = l;

	/* Adjust last length count to fill out codes, if needed */
	for (y = 1 << j; j < i; j++, y <<= 1) {
		y -= c[j];
	}

	y -= c[i];
	c[i] += y;

	/* Generate starting offsets into the value table for each length */
	x[1] = j = 0;
	p = c + 1;
	xp = x + 2;

	while (--i) {                 /* note that i == g from above */
		*xp++ = (j += *p++);
	}

	/* Make a table of values in order of bit lengths */
	p = b;
	i = 0;

	do {
		if ((j = *p++) != 0) {
			v[x[j]++] = i;
		}
	} while (++i < n);

	/* Generate the Huffman codes and for each, make the table entries */
	x[0] = i = 0;                 /* first Huffman code is zero */
	p = v;                        /* grab values in bit order */
	h = -1;                       /* no tables yet--level -1 */
	w = -l;                       /* bits decoded == (l * h) */
	u[0] = (struct huft *)NULL;   /* just to keep compilers happy */
	q = (struct huft *)NULL;      /* ditto */
	z = 0;                        /* ditto */

	/* go through the bit lengths (k already is bits in shortest code) */
	for (; k <= g; k++) {
		a = c[k];

		while (a--) {
			/* here i is the Huffman code of length k bits for value *p */
			/* make tables up to required level */
			while (k > w + l) {
				h++;
				w += l;                 /* previous table always l bits */

				/* compute minimum size table less than or equal to l bits */
				z = (z = g - w) > l ? l : z;  /* upper limit on table size */

				if ((f = 1 << (j = k - w)) > a + 1) {   /* try a k-w bit table */
				                          /* too few codes for k-w bit table */
					f -= a + 1;           /* deduct codes from patterns left */
					xp = c + k;

					while (++j < z) {     /* try smaller tables up to z bits */
						if ((f <<= 1) <= *++xp) {
							break;            /* enough codes to use up j bits */
						}

						f -= *xp;           /* else deduct codes from patterns */
					}
				}

				z = 1 << j;             /* table entries for j-bit table */

				/* allocate and link in new table */
				q = &huftlist[hufts];

				hufts += z + 1;         /* track memory usage */
				*t = q + 1;             /* link to list for huft_free() */
				*(t = &(q->v.t)) = (struct huft *)NULL;
				u[h] = ++q;             /* table starts after link */

				/* connect to last table, if there is one */
				if (h) {
					x[h] = i;             /* save pattern for backing up */
					r.b = l;              /* bits to dump before this table */
					r.e = 16 + j;         /* bits in this table */
					r.v.t = q;            /* pointer to this table */
					j = i >> (w - l);     /* (get around Turbo C bug) */
					u[h-1][j] = r;        /* connect to last table */
				}
			}

			/* set up table entry in r */
			r.b = (k - w);

			if (p >= v + n) {
				r.e = 99;               /* out of values--invalid code */
			} else if (*p < s) {
				r.e = (*p < 256 ? 16 : 15);    /* 256 is end-of-block code */
				r.v.n = *p;             /* simple code is just the value */
				p++;                    /* one compiler does not like *p++ */
			} else {
				r.e = e[*p - s];   /* non-simple--look up in lists */
				r.v.n = d[*p++ - s];
			}

			/* fill code-like entries with r */
			f = 1 << (k - w);

			for (j = i >> w; j < z; j += f) {
				q[j] = r;
			}

			/* backwards increment the k-bit code i */
			for (j = 1 << (k - 1); i & j; j >>= 1) {
				i ^= j;
			}

			i ^= j;

			/* backup over finished tables */
			while ((i & ((1 << w) - 1)) != x[h]) {
				h--;                    /* don't need to update q */
				w -= l;
			}
		}
	}

	/* Return true (1) if we were given an incomplete table */
	return y != 0 && g != 1;
}

s32 inflate_codes(struct huft *tl, struct huft *td, s32 bl, s32 bd)
{
	register u32 e;  /* table entry flag/number of extra bits */
	u32 n, d;        /* length and index for copy */
	u32 w;           /* current window position */
	struct huft *t;       /* pointer to table entry */
	u32 ml, md;      /* masks for bl and bd bits */
	register u32 b;       /* bit buffer */
	register u32 k;  /* number of bits in bit buffer */

	/* make local copies of globals */
	b = bb;                       /* initialize bit buffer */
	k = bk;
	w = wp;                       /* initialize window position */

	/* inflate the coded data */
	ml = mask_bits[bl];           /* precompute masks for speed */
	md = mask_bits[bd];

	for (;;) {                    /* do until end of block */
		NEEDBITS(bl)
		if ((e = (t = tl + (b & ml))->e) > 16) {
			do {
				DUMPBITS(t->b)
				e -= 16;
				NEEDBITS(e)
			} while ((e = (t = t->v.t + (b & mask_bits[e]))->e) > 16);
		}
		DUMPBITS(t->b)

		if (e == 16) {              /* then it's a literal */
			outbuf[w++] = (u8)t->v.n;
		} else {                      /* it's an EOB or a length */
			/* exit if end of block */
			if (e == 15) {
				break;
			}

			/* get length of block to copy */
			NEEDBITS(e)
			n = t->v.n + (b & mask_bits[e]);
			DUMPBITS(e);

			/* decode distance of block to copy */
			NEEDBITS(bd)
			if ((e = (t = td + (b & md))->e) > 16) {
				do {
					DUMPBITS(t->b)
					e -= 16;
					NEEDBITS(e)
				} while ((e = (t = t->v.t + (b & mask_bits[e]))->e) > 16);
			}
			DUMPBITS(t->b)
			NEEDBITS(e)
			d = w - t->v.n - (b & mask_bits[e]);
			DUMPBITS(e)

			/* do the copy */
			do {
				e = n;
				n = 0;

				do {
					outbuf[w++] = outbuf[d++];
				} while (--e);
			} while (n);
		}
	}

	/* restore the globals from the locals */
	wp = w;                       /* restore global window pointer */
	bb = b;                       /* restore global bit buffer */
	bk = k;

	/* done */
	return 0;
}

s32 inflate_stored(void)
{
	s32 n;           /* number of bytes in block */
	s32 w;           /* current window position */
	register u32 b; /* bit buffer */
	register u32 k;  /* number of bits in bit buffer */

	/* make local copies of globals */
	b = bb;                       /* initialize bit buffer */
	k = bk;
	w = wp;                       /* initialize window position */

	/* go to byte boundary */
	n = k & 7;
	DUMPBITS(n);

	/* get the length and its complement */
	NEEDBITS(16)
	n = (b & 0xffff);
	DUMPBITS(16)

	NEEDBITS(16)
	DUMPBITS(16)

	/* read and output the compressed data */
	while (n--) {
		NEEDBITS(8)
		outbuf[w++] = (u8)b;

		DUMPBITS(8)
	}

	/* restore the globals from the locals */
	wp = w;                       /* restore global window pointer */
	bb = b;                       /* restore global bit buffer */
	bk = k;
	return 0;
}

s32 inflate_fixed(void)
{
	s32 i;                /* temporary variable */
	struct huft *tl;      /* literal/length code table */
	struct huft *td;      /* distance code table */
	s32 bl;               /* lookup bits for tl */
	s32 bd;               /* lookup bits for td */
	u32 l[288];           /* length list for huft_build */

	/* set up literal table */
	for (i = 0; i < 144; i++) {
		l[i] = 8;
	}
	for (; i < 256; i++) {
		l[i] = 9;
	}
	for (; i < 280; i++) {
		l[i] = 7;
	}
	for (; i < 288; i++) {
		l[i] = 8;
	}

	bl = 7;

	huft_build(l, 288, 257, cplens, cplext, &tl, &bl);

	/* set up distance table */
	for (i = 0; i < 30; i++) {
		l[i] = 5;
	}

	bd = 5;

	/* decompress until an end-of-block code */
	huft_build(l, 30, 0, cpdist, cpdext, &td, &bd);

	inflate_codes(tl, td, bl, bd);

	return 0;
}

s32 inflate_dynamic(void)
{
	s32 i;                /* temporary variables */
	u32 j;
	u32 l;           /* last length */
	u32 m;           /* mask for bit lengths table */
	u32 n;           /* number of lengths to get */
	struct huft *tl;      /* literal/length code table */
	struct huft *td;      /* distance code table */
	s32 bl;               /* lookup bits for tl */
	s32 bd;               /* lookup bits for td */
	u32 nb;          /* number of bit length codes */
	u32 nl;          /* number of literal/length codes */
	u32 nd;          /* number of distance codes */
	register u32 k;  /* number of bits in bit buffer */
	register u32 b;  /* bit buffer */
	u32 ll[286+30];  /* literal/length and distance code lengths */

	/* make local bit buffer */
	b = bb;
	k = bk;

	/* read in table lengths */
	NEEDBITS(5)
	nl = 257 + (b & 0x1f);      /* number of literal/length codes */
	DUMPBITS(5)
	NEEDBITS(5)
	nd = 1 + (b & 0x1f);        /* number of distance codes */
	DUMPBITS(5)
	NEEDBITS(4)
	nb = 4 + (b & 0xf);         /* number of bit length codes */
	DUMPBITS(4)

	/* read in bit-length-code lengths */
	for (j = 0; j < nb; j++) {
		NEEDBITS(3)
		ll[border[j]] = b & 7;
		DUMPBITS(3)
	}

	for (; j < 19; j++) {
		ll[border[j]] = 0;
	}

	/* build decoding table for trees--single level, 7 bit lookup */
	bl = 7;

	huft_build(ll, 19, 19, NULL, NULL, &tl, &bl);

	/* read in literal and distance code lengths */
	n = nl + nd;
	m = mask_bits[bl];
	i = l = 0;

	while (i < n) {
		NEEDBITS(bl)
		j = (td = tl + (b & m))->b;
		DUMPBITS(j)

		j = td->v.n;

		if (j < 16) {                 /* length of code in bits (0..15) */
			ll[i++] = l = j;          /* save last length in l */
		} else if (j == 16) {         /* repeat last length 3 to 6 times */
			NEEDBITS(2)
			j = 3 + (b & 3);
			DUMPBITS(2)

			while (j--) {
				ll[i++] = l;
			}
		} else if (j == 17) {         /* 3 to 10 zero length codes */
			NEEDBITS(3)
			j = 3 + (b & 7);
			DUMPBITS(3)

			while (j--) {
				ll[i++] = 0;
			}

			l = 0;
		} else {                      /* j == 18: 11 to 138 zero length codes */
			NEEDBITS(7)
			j = 11 + (b & 0x7f);
			DUMPBITS(7)

			while (j--) {
				ll[i++] = 0;
			}

			l = 0;
		}
	}

	/* restore the global bit buffer */
	bb = b;
	bk = k;

	/* build the decoding tables for literal/length and distance codes */
	bl = lbits;

	huft_build(ll, nl, 257, cplens, cplext, &tl, &bl);

	bd = dbits;

	huft_build(ll + nl, nd, 0, cpdist, cpdext, &td, &bd);

	/* decompress until an end-of-block code */
	inflate_codes(tl, td, bl, bd);

	return 0;
}

s32 inflate_block(s32 *e)
{
	u32 t;                /* block type */
	register u32 b = bb;  /* bit buffer */
	register u32 k = bk;  /* number of bits in bit buffer */

	/* make local bit buffer */
	b = bb;
	k = bk;

	/* read in last block bit */
	NEEDBITS(1)
	*e = b & 1;
	DUMPBITS(1)

	/* read in last block type */
	NEEDBITS(2)
	t = b & 3;
	DUMPBITS(2)

	/* restore the global bit buffer */
	bb = b;
	bk = k;

	/* inflate that block type */
	if (t == 2) {
		return inflate_dynamic();
	}

	if (t == 0) {
		return inflate_stored();
	}

	if (t == 1) {
		return inflate_fixed();
	}

	/* bad block type */
	return 2;
}

u32 inflate(void)
{
	s32 e;           /* last block flag */
	s32 r;           /* result code */
	u32 h;           /* maximum struct huft's malloc'ed */

	/* initialize window, bit buffer */
	wp = 0;
	bk = 0;
	bb = 0;

	/* decompress until the last block */
	h = 0;

	do {
		hufts = 0;
		r = inflate_block(&e);

		if (r != 0) {
			return r;
		}

		if (h < hufts) {
			h = hufts;
		}
	} while (!e);

	/* Undo too much lookahead. The next read will be byte aligned so we
	 * can discard unused bits in the last meaningful byte.
	 */
	while (bk >= 8) {
		bk -= 8;
		inptr--;
	}

	return 0;
}

u32 inflate1173(void *src, void *dst, struct huft *hlist)
{
	inbuf = src;
	outbuf = dst;
	huftlist = hlist;
	inbuf += 2;
	inbuf += 3;
	wp = 0;
	inptr = 0;

	inflate();

	return wp;
}
