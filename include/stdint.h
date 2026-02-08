/* SPDX-FileCopyrightText: 2026 hangocdinhnew */
/* SPDX-License-Identifier: BSD-3-Clause */

#ifndef __LIBZC_STDINT_H
#define __LIBZC_STDINT_H

#ifdef __cplusplus
extern "C" {
#endif

#include "limits.h"
  
  typedef __INT8_TYPE__    int8_t;
  typedef __INT16_TYPE__   int16_t;
  typedef __INT32_TYPE__   int32_t;
  typedef __INT64_TYPE__   int64_t;
  
  typedef __UINT8_TYPE__   uint8_t;
  typedef __UINT16_TYPE__  uint16_t;
  typedef __UINT32_TYPE__  uint32_t;
  typedef __UINT64_TYPE__  uint64_t;
  
  typedef __INT_LEAST8_TYPE__   int_least8_t;
  typedef __INT_LEAST16_TYPE__  int_least16_t;
  typedef __INT_LEAST32_TYPE__  int_least32_t;
  typedef __INT_LEAST64_TYPE__  int_least64_t;
  
  typedef __UINT_LEAST8_TYPE__  uint_least8_t;
  typedef __UINT_LEAST16_TYPE__ uint_least16_t;
  typedef __UINT_LEAST32_TYPE__ uint_least32_t;
  typedef __UINT_LEAST64_TYPE__ uint_least64_t;
  
  typedef __INT_FAST8_TYPE__   int_fast8_t;
  typedef __INT_FAST16_TYPE__  int_fast16_t;
  typedef __INT_FAST32_TYPE__  int_fast32_t;
  typedef __INT_FAST64_TYPE__  int_fast64_t;
  
  typedef __UINT_FAST8_TYPE__  uint_fast8_t;
  typedef __UINT_FAST16_TYPE__ uint_fast16_t;
  typedef __UINT_FAST32_TYPE__ uint_fast32_t;
  typedef __UINT_FAST64_TYPE__ uint_fast64_t;
  
  typedef __INTPTR_TYPE__  intptr_t;
  typedef __UINTPTR_TYPE__ uintptr_t;
  
  typedef __INTMAX_TYPE__  intmax_t;
  typedef __UINTMAX_TYPE__ uintmax_t;
  
#define INT8_MIN   (-__INT8_MAX__ - 1)
#define INT8_MAX   __INT8_MAX__
#define UINT8_MAX  __UINT8_MAX__
  
#define INT16_MIN  (-__INT16_MAX__ - 1)
#define INT16_MAX  __INT16_MAX__
#define UINT16_MAX __UINT16_MAX__
  
#define INT32_MIN  (-__INT32_MAX__ - 1)
#define INT32_MAX  __INT32_MAX__
#define UINT32_MAX __UINT32_MAX__
  
#define INT64_MIN  (-__INT64_MAX__ - 1)
#define INT64_MAX  __INT64_MAX__
#define UINT64_MAX __UINT64_MAX__

#define INTPTR_MIN  (-__INTPTR_MAX__ - 1)
#define INTPTR_MAX  __INTPTR_MAX__
#define UINTPTR_MAX __UINTPTR_MAX__

#define INTMAX_MIN  (-__INTMAX_MAX__ - 1)
#define INTMAX_MAX  __INTMAX_MAX__
#define UINTMAX_MAX __UINTMAX_MAX__

#define INT_LEAST8_MIN  __INT_LEAST8_MIN__
#define INT_LEAST8_MAX  __INT_LEAST8_MAX__
#define UINT_FAST8_MAX  __UINT_FAST8_MAX__

#define INT_LEAST16_MIN  __INT_LEAST16_MIN__
#define INT_LEAST16_MAX  __INT_LEAST16_MAX__
#define UINT_FAST16_MAX  __UINT_FAST16_MAX__

#define INT_LEAST32_MIN  __INT_LEAST32_MIN__
#define INT_LEAST32_MAX  __INT_LEAST32_MAX__
#define UINT_FAST32_MAX  __UINT_FAST32_MAX__

#define INT_LEAST64_MIN  __INT_LEAST64_MIN__
#define INT_LEAST64_MAX  __INT_LEAST64_MAX__
#define UINT_FAST64_MAX  __UINT_FAST64_MAX__

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
