#include <string.h>
#include <stdarg.h>
#include "xstdio.h"

char spaces[] = "                                ";
char zeroes[] = "00000000000000000000000000000000";

#define ISDIGIT(x) ((x >= '0' && x <= '9'))

#define ATOI(dst, src)				   \
	for (dst = 0; ISDIGIT(*src); ++src)  \
	{									\
		if (dst < 999)				   \
			dst = dst * 10 + *src - '0'; \
	}

#define MAX_PAD ((sizeof(spaces) - 1))

#define PAD(s, n)											 \
	if (0 < (n))											  \
	{														 \
		int i, j = (n);									   \
		for (; 0 < j; j -= i)								 \
		{													 \
			i = MAX_PAD < (unsigned int)j ? (int)MAX_PAD : j; \
			PUT(s, i);										\
		}													 \
	}

#define PUT(s, n)								\
	if (0 < (n))								 \
	{											\
		if ((arg = (*prout)(arg, s, n)) != NULL) \
			x.size += (n);					   \
		else									 \
			return x.size;					   \
	}

static void _Putfld(printf_struct *x, va_list *args, char type, char *buff)
{
	x->n0 = x->num_leading_zeros = x->part2_len = x->num_mid_zeros = x->part3_len = x->num_trailing_zeros = 0;

	switch (type) {
	case 'c':
		buff[x->n0++] = va_arg(*args, int);
		break;
	case 'd':
	case 'i':
		if (x->length == 'l') {
			x->value.s64 = va_arg(*args, int);
		} else if (x->length == 'L') {
			x->value.s64 = va_arg(*args, s64);
		} else {
			x->value.s64 = va_arg(*args, int);
		}

		if (x->length == 'h') {
			x->value.s64 = (s16)x->value.s64;
		}

		if (x->value.s64 < 0) {
			buff[x->n0++] = '-';
		} else if (x->flags & FLAGS_PLUS) {
			buff[x->n0++] = '+';
		} else if (x->flags & FLAGS_SPACE) {
			buff[x->n0++] = ' ';
		}

		x->buff = (char *)&buff[x->n0];

		_Litob(x, type);
		break;
	case 'x':
	case 'X':
	case 'u':
	case 'o':
		if (x->length == 'l') {
			x->value.s64 = va_arg(*args, int);
		} else if (x->length == 'L') {
			x->value.s64 = va_arg(*args, s64);
		} else {
			x->value.s64 = va_arg(*args, int);
		}

		if (x->length == 'h') {
			x->value.s64 = (u16)x->value.s64;
		} else if (x->length == 0) {
			x->value.s64 = (unsigned int)x->value.s64;
		}

		if (x->flags & FLAGS_HASH) {
			buff[x->n0++] = '0';

			if (type == 'x' || type == 'X') {
				buff[x->n0++] = type;
			}
		}

		x->buff = (char *)&buff[x->n0];
		_Litob(x, type);
		break;
	case 'e':
	case 'f':
	case 'g':
	case 'E':
	case 'G':
		x->value.f64 = x->length == 'L' ? va_arg(*args, f64) : va_arg(*args, f64);

		if (*(u16 *)&x->value.f64 & 0x8000) {
			buff[x->n0++] = '-';
		} else if (x->flags & FLAGS_PLUS) {
			buff[x->n0++] = '+';
		} else if (x->flags & FLAGS_SPACE) {
			buff[x->n0++] = ' ';
		}

		x->buff = (char *)&buff[x->n0];
		_Ldtob(x, type);
		break;
	case 'n':
		if (x->length == 'h') {
			*(va_arg(*args, u16 *)) = x->size;
		} else if (x->length == 'l') {
			*va_arg(*args, unsigned int *) = x->size;
		} else if (x->length == 'L') {
			*va_arg(*args, u64 *) = x->size;
		} else {
			*va_arg(*args, unsigned int *) = x->size;
		}
		break;
	case 'p':
		x->value.s64 = (long)va_arg(*args, void *);
		x->buff = (char *)&buff[x->n0];
		_Litob(x, 'x');
		break;
	case 's':
		x->buff = va_arg(*args, char *);
		x->part2_len = strlen(x->buff);

		if (x->precision >= 0 && x->part2_len > x->precision) {
			x->part2_len = x->precision;
		}
		break;
	case '%':
		buff[x->n0++] = '%';
		break;
	default:
		buff[x->n0++] = type;
		break;
	}
}

int _Printf(outfun prout, char *arg, const char *fmt, va_list args)
{
	printf_struct x;
	const char *s;
	char c;
	const char *t;
	static const char fchar[6] = " +-#0";
	static const int fbit[6] = {FLAGS_SPACE, FLAGS_PLUS, FLAGS_MINUS, FLAGS_HASH, FLAGS_ZERO, 0};
	char ac[32];
	x.size = 0;

	for (;;) {
		s = fmt;

		for (c = *s; c != 0 && c != '%';) {
			c = *++s;
		}

		PUT(fmt, s - fmt);

		if (c == 0) {
			return x.size;
		}

		fmt = ++s;

		for (x.flags = 0; (t = strchr(fchar, *s)) != NULL; s++) {
			x.flags |= fbit[t - fchar];
		}

		if (*s == '*') {
			x.width = va_arg(args, int);

			if (x.width < 0) {
				x.width = -x.width;
				x.flags |= FLAGS_MINUS;
			}

			s++;
		} else {
			ATOI(x.width, s);
		}

		if (*s != '.') {
			x.precision = -1;
		} else if (*++s == '*') {
			x.precision = va_arg(args, int);
			++s;
		} else {
			ATOI(x.precision, s);
		}

		x.length = strchr("hlL", *s) ? *s++ : '\0';

		if (x.length == 'l' && *s == 'l') {
			x.length = 'L';
			++s;
		}

		_Putfld(&x, &args, *s, ac);

		x.width -= x.n0 + x.num_leading_zeros + x.part2_len + x.num_mid_zeros + x.part3_len + x.num_trailing_zeros;

		if (!(x.flags & FLAGS_MINUS)) {
			PAD(spaces, x.width);
		}

		PUT(ac, x.n0);
		PAD(zeroes, x.num_leading_zeros);
		PUT(x.buff, x.part2_len);
		PAD(zeroes, x.num_mid_zeros);
		PUT(x.buff + x.part2_len, x.part3_len);
		PAD(zeroes, x.num_trailing_zeros);

		if (x.flags & FLAGS_MINUS) {
			PAD(spaces, x.width);
		}

		fmt = s + 1;
	}

	return 0;
}
