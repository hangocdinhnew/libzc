/* SPDX-FileCopyrightText: 2026 hangocdinhnew */
/* SPDX-License-Identifier: BSD-3-Clause */

#ifndef __LIBZC_LIMITS_H
#define __LIBZC_LIMITS_H

#ifdef __cplusplus
extern "C" {
#endif

#define CHAR_BIT 8

#define SCHAR_MAX  ((signed char)(((unsigned char)~0) >> 1))
#define SCHAR_MIN  (-SCHAR_MAX - 1)
#define UCHAR_MAX  ((unsigned char)~0)

#if ((char)-1) < 0
#define CHAR_MIN SCHAR_MIN
#define CHAR_MAX SCHAR_MAX
#else
#define CHAR_MIN 0
#define CHAR_MAX UCHAR_MAX
#endif

#define SHRT_MAX  ((short)(((unsigned short)~0) >> 1))
#define SHRT_MIN  (-SHRT_MAX - 1)
#define USHRT_MAX ((unsigned short)~0)

#define INT_MAX   ((int)(((unsigned int)~0) >> 1))
#define INT_MIN   (-INT_MAX - 1)
#define UINT_MAX  ((unsigned int)~0)

#define LONG_MAX  ((long)(((unsigned long)~0) >> 1))
#define LONG_MIN  (-LONG_MAX - 1L)
#define ULONG_MAX ((unsigned long)~0)

#define LLONG_MAX  ((long long)(((unsigned long long)~0) >> 1))
#define LLONG_MIN  (-LLONG_MAX - 1LL)
#define ULLONG_MAX ((unsigned long long)~0)

#ifdef __cplusplus
}
#endif

#endif
