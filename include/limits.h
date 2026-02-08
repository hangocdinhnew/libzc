/* SPDX-FileCopyrightText: 2026 hangocdinhnew */
/* SPDX-License-Identifier: BSD-3-Clause */

#ifndef __LIBZC_LIMITS_H
#define __LIBZC_LIMITS_H

#ifdef __cplusplus
extern "C" {
#endif

#define CHAR_BIT __CHAR_BIT__

#define SCHAR_MIN  (-__SCHAR_MAX__ - 1)
#define SCHAR_MAX  __SCHAR_MAX__
#define UCHAR_MAX  __UCHAR_MAX__

#ifdef __CHAR_UNSIGNED__
#define CHAR_MIN   0
#define CHAR_MAX   __UCHAR_MAX__
#else
#define CHAR_MIN   SCHAR_MIN
#define CHAR_MAX   SCHAR_MAX
#endif

#define SHRT_MIN   (-__SHRT_MAX__ - 1)
#define SHRT_MAX   __SHRT_MAX__
#define USHRT_MAX  __USHRT_MAX__

#define INT_MIN    (-__INT_MAX__ - 1)
#define INT_MAX    __INT_MAX__
#define UINT_MAX   __UINT_MAX__

#define LONG_MIN   (-__LONG_MAX__ - 1L)
#define LONG_MAX   __LONG_MAX__
#define ULONG_MAX  __ULONG_MAX__

#define LLONG_MIN  (-__LONG_LONG_MAX__ - 1LL)
#define LLONG_MAX  __LONG_LONG_MAX__
#define ULLONG_MAX __ULONG_LONG_MAX__

#ifdef __cplusplus
}
#endif

#endif /* __LIBZC_LIMITS_H */
