/* SPDX-FileCopyrightText: 2026 hangocdinhnew */
/* SPDX-License-Identifier: BSD-3-Clause */

#ifndef __LIBZC_STDINT_H
#define __LIBZC_STDINT_H

#ifdef __cplusplus
extern "C" {
#endif
  
#include "limits.h"

#if CHAR_BIT != 8
#error "Unsupported architecture: 8-bit bytes required!"
#endif
  
  typedef signed char int8_t;
  typedef signed short int16_t;
  typedef signed int int32_t;
  typedef signed long long int64_t;
  
  typedef unsigned char uint8_t;
  typedef unsigned short uint16_t;
  typedef unsigned int uint32_t;
  typedef unsigned long long uint64_t;
  
  typedef signed char int_least8_t;
  typedef signed short int_least16_t;
  typedef signed int int_least32_t;
  typedef signed long long int_least64_t;
  
  typedef unsigned char uint_least8_t;
  typedef unsigned short uint_least16_t;
  typedef unsigned int uint_least32_t;
  typedef unsigned long long uint_least64_t;
  
  typedef signed int int_fast8_t;
  typedef signed int int_fast16_t;
  typedef signed int int_fast32_t;
  typedef signed long long int_fast64_t;
  
  typedef unsigned int uint_fast8_t;
  typedef unsigned int uint_fast16_t;
  typedef unsigned int uint_fast32_t;
  typedef unsigned long long uint_fast64_t;
  
#ifdef _MSC_VER
#if defined(_WIN64)
  typedef signed long long intptr_t;
  typedef unsigned long long uintptr_t;
#else
  typedef signed int intptr_t;
  typedef unsigned int uintptr_t;
#endif
  
#else
  
#if __SIZEOF_POINTER__ == 8
  typedef signed long intptr_t;
  typedef unsigned long uintptr_t;
#else
  typedef signed int intptr_t;
  typedef unsigned int uintptr_t;
#endif
#endif
  
  typedef signed long long intmax_t;
  typedef unsigned long long uintmax_t;
  
#if defined(_MSC_VER)
#define INT8_C(x)     x
#define UINT8_C(x)    x##u
  
#define INT16_C(x)    x
#define UINT16_C(x)   x##u
  
#define INT32_C(x)    x
#define UINT32_C(x)   x##u
  
#define INT64_C(x)    x##i64
#define UINT64_C(x)   x##ui64
  
#define INTMAX_C(x)   x##i64
#define UINTMAX_C(x)  x##ui64
  
#else
  
#define INT8_C(x)    x
#define UINT8_C(x)   x##U
  
#define INT16_C(x)   x
#define UINT16_C(x)  x##U
  
#define INT32_C(x)   x
#define UINT32_C(x)  x##U
  
#define INT64_C(x)   x##LL
#define UINT64_C(x)  x##ULL
  
#define INTMAX_C(x)   x##LL
#define UINTMAX_C(x)  x##ULL
#endif

#define INT8_MAX   127
#define INT8_MIN  (-127 - 1)
#define UINT8_MAX  UINT8_C(255)
  
#define INT16_MAX  32767
#define INT16_MIN  (-32768)
#define UINT16_MAX UINT16_C(65535)
  
#define INT32_MAX  2147483647
#define INT32_MIN  (-2147483647 - 1)
#define UINT32_MAX UINT32_C(4294967295)
  
#define INT64_MAX  INT64_C(9223372036854775807)
#define INT64_MIN  (INT64_C(-9223372036854775807) - 1)
#define UINT64_MAX UINT64_C(18446744073709551615)

#define INTPTR_MAX  ((intptr_t)(((uintptr_t)~0) >> 1))
#define INTPTR_MIN  (-INTPTR_MAX - 1)
#define UINTPTR_MAX ((uintptr_t)~0)
  
#define INTMAX_MAX  INT64_MAX
#define INTMAX_MIN  INT64_MIN
#define UINTMAX_MAX UINT64_MAX

#define INT_LEAST8_MIN   INT8_MIN
#define INT_LEAST8_MAX   INT8_MAX
#define UINT_LEAST8_MAX  UINT8_MAX

#define INT_LEAST16_MIN  INT16_MIN
#define INT_LEAST16_MAX  INT16_MAX
#define UINT_LEAST16_MAX UINT16_MAX

#define INT_LEAST32_MIN  INT32_MIN
#define INT_LEAST32_MAX  INT32_MAX
#define UINT_LEAST32_MAX UINT32_MAX

#define INT_LEAST64_MIN  INT64_MIN
#define INT_LEAST64_MAX  INT64_MAX
#define UINT_LEAST64_MAX UINT64_MAX
  
#define INT_FAST8_MIN    INT32_MIN
#define INT_FAST8_MAX    INT32_MAX
#define UINT_FAST8_MAX   UINT32_MAX

#define INT_FAST16_MIN   INT32_MIN
#define INT_FAST16_MAX   INT32_MAX
#define UINT_FAST16_MAX  UINT32_MAX

#define INT_FAST32_MIN   INT32_MIN
#define INT_FAST32_MAX   INT32_MAX
#define UINT_FAST32_MAX  UINT32_MAX

#define INT_FAST64_MIN   INT64_MIN
#define INT_FAST64_MAX   INT64_MAX
#define UINT_FAST64_MAX  UINT64_MAX
  
#if defined(__STDC_VERSION__) && __STDC_VERSION__ >= 202311L
#define INT_FAST8_WIDTH   (sizeof(int_fast8_t) * CHAR_BIT)
#define INT_FAST16_WIDTH   (sizeof(int_fast16_t) * CHAR_BIT)
#define INT_FAST32_WIDTH   (sizeof(int_fast32_t) * CHAR_BIT)
#define INT_FAST64_WIDTH   (sizeof(int_fast64_t) * CHAR_BIT)
  
#define INT_LEAST8_WIDTH   (sizeof(int_least8_t) * CHAR_BIT)
#define INT_LEAST16_WIDTH   (sizeof(int_least16_t) * CHAR_BIT)
#define INT_LEAST32_WIDTH   (sizeof(int_least32_t) * CHAR_BIT)
#define INT_LEAST64_WIDTH   (sizeof(int_least64_t) * CHAR_BIT)
#endif
  
#ifdef __cplusplus
}
#endif

#endif /* __LIBZC_STDINT_H */
