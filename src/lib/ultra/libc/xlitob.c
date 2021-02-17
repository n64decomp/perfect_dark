#include <ultra64.h>
#include "data.h"
#include "lib/libc/ldiv.h"

#define BUFF_LEN 0x18

void _Litob(printf_struct *args, char type)
{
	char buff[BUFF_LEN];
	const char *digs;
	s32 base;
	s32 i;
	unsigned long long ullval;

	if (type == 'X') {
		digs = udigs;
	} else {
		digs = ldigs;
	}

	base = (type == 'o') ? 8 : ((type != 'x' && type != 'X') ? 10 : 16);
	i = BUFF_LEN;
	ullval = args->value.s64;

	if ((type == 'd' || type == 'i') && args->value.s64 < 0) {
		ullval = -ullval;
	}

	if (ullval != 0 || args->precision != 0) {
		buff[--i] = digs[ullval % base];
	}

	args->value.s64 = ullval / base;

	while (args->value.s64 > 0 && i > 0) {
		lldiv_t qr = lldiv(args->value.s64, base);
		args->value.s64 = qr.quot;
		buff[--i] = digs[qr.rem];
	}

	args->part2_len = BUFF_LEN - i;

	memcpy(args->buff, buff + i, args->part2_len);

	if (args->part2_len < args->precision) {
		args->num_leading_zeros = args->precision - args->part2_len;
	}

	if (args->precision < 0 && (args->flags & (FLAGS_ZERO | FLAGS_MINUS)) == FLAGS_ZERO) {
		i = args->width - args->n0 - args->num_leading_zeros - args->part2_len;

		if (i > 0) {
			args->num_leading_zeros += i;
		}
	}
}
