#ifndef IN_MATH_H
#define IN_MATH_H

// @bug?
#define M_BADPI 3.141092641f
#define M_PI    3.141592741f

#define M_BADTAU (M_BADPI * 2)
#define M_TAU    (M_PI * 2)

#define BADDEG2RAD(deg) ((deg) * (M_BADPI / 180.0f))
#define DEG2RAD(deg)    ((deg) * (M_PI / 180.0f))

#define RAD2DEG(rad) ((rad) * (180.0f / M_PI))
#define RAD2DEG2(rad) ((rad) * 180.0f / M_PI)
#define BADRAD2DEG(rad) ((rad) * (180.0f / M_BADPI))

/**
 * In many places, using the DEG2RAD macro results in a value that differs from
 * the original by 1 bit, so a literal radian value must be used to get a match.
 *
 * To help with readability, the RAD macro is used so that both the degree and
 * radian values can be specified, even though degrees is not used.
 */
#define RAD(deg, rad) (rad)

#endif
