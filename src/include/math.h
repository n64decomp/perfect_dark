#ifndef IN_MATH_H
#define IN_MATH_H

// @bug?
#define M_BADPI 3.141092641f
#define M_PI    3.141592741f

#define M_BADTAU (M_BADPI * 2)
#define M_TAU    (M_PI * 2)

#define DTOR(deg)  ((deg) * M_PI / 180.0f)
#define DTOR2(deg) ((deg) * (M_PI / 180.0f))

#define BADDTOR(deg)  ((deg) * M_BADPI / 180.0f)
#define BADDTOR2(deg) ((deg) * (M_BADPI / 180.0f))
#define BADDTOR3(deg) ((deg) * M_BADTAU / 360.0f)
#define BADDTOR4(deg) ((deg) / 360.0f * M_BADTAU)

#define RTOD(rad)  ((rad) * 180.0f / M_PI)
#define RTOD2(rad) ((rad) * (180.0f / M_PI))

#define BADRTOD(rad)  ((rad) * (180.0f / M_BADPI))
#define BADRTOD2(rad) ((rad) * 180.0f / M_BADPI)
#define BADRTOD3(rad) ((rad) / M_BADTAU * 360.0f)
#define BADRTOD4(rad) ((rad) * 360.0f / M_BADTAU)

/**
 * In many places, using the DTOR macros result in a value that differs from
 * the original by 1 bit, so a literal radian value must be used to get a match.
 *
 * To help with readability, the RAD macro is used so that both the degree and
 * radian values can be specified, even though degrees is not used.
 */
#define RAD(deg, rad) (rad)

#endif
