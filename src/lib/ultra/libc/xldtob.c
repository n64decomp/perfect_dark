#include <stdlib.h>
#include <string.h>
#include "xstdio.h"

static short _Ldunscale(short *pex, printf_struct *px);
static void _Genld(printf_struct *px, char code, char *p, short nsig, short xexp);

const double pows[] = {10e0L, 10e1L, 10e3L, 10e7L, 10e15L, 10e31L, 10e63L, 10e127L, 10e255L};

/* float properties */
#define _D0    0
#define _DBIAS 0x3ff
#define _DLONG 1
#define _DOFF  4
#define _FBIAS 0x7e
#define _FOFF  7
#define _FRND  1
#define _LBIAS 0x3ffe
#define _LOFF  15

/* integer properties */
#define _C2    1
#define _CSIGN 1
#define _ILONG 0
#define _MBMAX 8
#define NAN    2
#define INF    1
#define FINITE -1
#define _DFRAC ((1 << _DOFF) - 1)
#define _DMASK (0x7fff & ~_DFRAC)
#define _DMAX  ((1 << (15 - _DOFF)) - 1)
#define _DNAN  (0x8000 | _DMAX << _DOFF | 1 << (_DOFF - 1))
#define _DSIGN 0x8000
#define _D1    1
#define _D2    2
#define _D3    3

void _Ldtob(printf_struct *args, char type)
{
	u8 buff[0x20];
	u8 *p = buff;
	f64 ldval = args->value.f64;
	f32 zero = 0.0f;
	f64 zero64 = zero;
	f32 one32;
	short err;
	short nsig;
	short exp;

	if (args->precision < 0) {
		args->precision = 6;
	} else if (args->precision == 0 && (type == 'g' || type == 'G')) {
		args->precision = 1;
	}

	err = _Ldunscale(&exp, args);

	if (err > 0) {
		memcpy(args->buff, err == 2 ? "NaN" : "Inf", args->part2_len = 3);
		return;
	}

	if (err == 0) {
		nsig = 0;
		exp = 0;
	} else {
		int i;
		int n;

		if (ldval < zero64) {
			ldval = -ldval;
		}

		exp = exp * 30103 / 0x000186a0 - 4;

		if (exp < 0) {
			n = (3 - exp) & ~3;
			exp = -n;

			for (i = 0; n > 0; n >>= 1, i++) {
				if ((n & 1) != 0) {
					ldval *= pows[i];
				}
			}
		} else if (exp > 0) {
			f64 factor;
			one32 = 1.0f;
			factor = one32;
			exp &= ~3;

			for (n = exp, i = 0; n > 0; n >>= 1, i++) {
				if (n & 1) {
					factor *= pows[i];
				}
			}

			ldval /= factor;
		}

		{
			int gen = ((type == 'f') ? exp + 10 : 6) + args->precision;

			if (gen > 0x13) {
				gen = 0x13;
			}

			*p++ = '0';

			while (gen > 0 && zero64 < ldval) {
				int j;
				int lo = ldval;

				if ((gen -= 8) > 0) {
					ldval = (ldval - lo) * 1.0e8;
				}

				p += 8;

				for (j = 8; lo > 0 && --j >= 0;) {
					ldiv_t qr = ldiv(lo, 10);
					*--p = qr.rem + '0';
					lo = qr.quot;
				}

				while (--j >= 0) {
					p--;
					*p = '0';
				}

				p += 8;
			}

			gen = p - &buff[1];

			for (p = &buff[1], exp += 7; *p == '0'; p++) {
				--gen;
				--exp;
			}

			nsig = ((type == 'f') ? exp + 1 : ((type == 'e' || type == 'E') ? 1 : 0)) + args->precision;

			if (gen < nsig) {
				nsig = gen;
			}

			if (nsig > 0) {
				u8 drop;
				int n;

				if (nsig < gen && p[nsig] > '4') {
					drop = '9';
				} else {
					drop = '0';
				}

				for (n = nsig; p[--n] == drop;) {
					nsig--;
				}

				if (drop == '9') {
					p[n]++;
				}

				if (n < 0) {
					--p, ++nsig, ++exp;
				}
			}
		}
	}

	_Genld(args, type, p, nsig, exp);
}

static short _Ldunscale(short *pex, printf_struct *px)
{
	unsigned short *ps = (unsigned short *)px;
	short xchar = (ps[_D0] & _DMASK) >> _DOFF;

	if (xchar == _DMAX) {
		/* NaN or INF */
		*pex = 0;

		return ps[_D0] & _DFRAC || ps[_D1] || ps[_D2] || ps[_D3] ? NAN : INF;
	}

	if (xchar > 0) {
		ps[_D0] = (ps[_D0] & ~_DMASK) | (_DBIAS << _DOFF);
		*pex = xchar - (_DBIAS - 1);

		return FINITE;
	}

	if (xchar < 0) {
		return NAN;
	}

	*pex = 0;

	return 0;
}

static void _Genld(printf_struct *px, char code, char *p, short nsig, short xexp)
{
	const char point = '.';

	if (nsig <= 0) {
		p = (char *) "0";
		nsig = 1;
	}

	if (code == 'f' || ((code == 'g' || code == 'G') && xexp >= -4 && xexp < px->precision)) {
		/* 'f' format */
		xexp++; /* change to leading digit count */

		if (code != 'f') {
			/* fixup for 'g' */
			if (!(px->flags & FLAGS_HASH) && nsig < px->precision) {
				px->precision = nsig;
			}

			px->precision -= xexp;

			if (px->precision < 0) {
				px->precision = 0;
			}
		}

		if (xexp <= 0) {
			/* digits only to right of point */
			px->buff[px->part2_len++] = '0';

			if (px->precision > 0 || px->flags & FLAGS_HASH) {
				px->buff[px->part2_len++] = point;
			}

			if (px->precision < -xexp) {
				xexp = -px->precision;
			}

			px->num_mid_zeros = -xexp;
			px->precision += xexp;

			if (px->precision < nsig) {
				nsig = px->precision;
			}

			px->part3_len = nsig;

			memcpy(&px->buff[px->part2_len], p, nsig);

			px->num_trailing_zeros = px->precision - nsig;
		} else if (nsig < xexp) {
			/* zeros before point */
			memcpy(&px->buff[px->part2_len], p, nsig);

			px->part2_len += nsig;
			px->num_mid_zeros = xexp - nsig;

			if (px->precision > 0 || px->flags & FLAGS_HASH) {
				px->buff[px->part2_len] = point;
				px->part3_len++;
			}

			px->num_trailing_zeros = px->precision;
		} else {
			/* enough digits before point */
			memcpy(&px->buff[px->part2_len], p, xexp);

			px->part2_len += xexp;
			nsig -= xexp;

			if (px->precision > 0 || px->flags & FLAGS_HASH) {
				px->buff[px->part2_len++] = point;
			}

			if (px->precision < nsig) {
				nsig = px->precision;
			}

			memcpy(&px->buff[px->part2_len], p + xexp, nsig);

			px->part2_len += nsig;
			px->num_mid_zeros = px->precision - nsig;
		}
	} else {
		/* 'e' format */
		if (code == 'g' || code == 'G') {
			/* fixup for 'g' */
			if (nsig < px->precision) {
				px->precision = nsig;
			}

			px->precision--;

			if (px->precision < 0) {
				px->precision = 0;
			}

			code = code == 'g' ? 'e' : 'E';
		}

		px->buff[px->part2_len] = *p;
		px->part2_len++;
		p++;

		if (px->precision > 0 || px->flags & FLAGS_HASH) {
			px->buff[px->part2_len] = point;
			px->part2_len++;
		}

		if (px->precision > 0) {
			/* put fraction digits */
			nsig--;

			if (px->precision < nsig) {
				nsig = px->precision;
			}

			memcpy(&px->buff[px->part2_len], p, nsig);

			px->part2_len += nsig;
			px->num_mid_zeros = px->precision - nsig;
		}

		p = (char *) &px->buff[px->part2_len]; /* put exponent */
		*p = code;
		p++;

		if (xexp >= 0) {
			*p++ = '+';
		} else {
			/* negative exponent */
			*p++ = '-';
			xexp = -xexp;
		}

		if (xexp >= 100) {
			/* put oversize exponent */
			if (xexp >= 1000) {
				*p = xexp / 1000 + 0x30, xexp %= 1000;
				p++;
			}

			*p = xexp / 100 + 0x30, xexp %= 100;
			p++;
		}

		*p = xexp / 10 + 0x30, xexp %= 10;
		p++;
		*p = xexp + 0x30;
		p++;

		px->part3_len = p - (char *) &px->buff[px->part2_len];
	}

	if ((px->flags & (FLAGS_ZERO | FLAGS_MINUS)) == FLAGS_ZERO) {
		/* pad with leading zeros */
		int n = px->n0 + px->part2_len + px->num_mid_zeros + px->part3_len + px->num_trailing_zeros;

		if (n < px->width) {
			px->num_leading_zeros = px->width - n;
		}
	}
}
