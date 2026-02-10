/* SPDX-FileCopyrightText: 2026 hangocdinhnew */
/* SPDX-License-Identifier: BSD-3-Clause */

#ifndef __LIBZC_STDDEF_H
#define __LIBZC_STDDEF_H

#ifdef __cplusplus
extern "C" {
#endif

#if defined(_MSC_VER)

#ifdef _WIN64
  
typedef unsigned __int64 size_t;
typedef __int64 ptrdiff_t;

#else

typedef unsigned int size_t;
typedef signed int ptrdiff_t;

#endif

#elif defined(__SIZE_TYPE__) && defined(__PTRDIFF_TYPE__)

typedef __SIZE_TYPE__ size_t;
typedef __PTRDIFF_TYPE__ ptrdiff_t;

#else
#error "Compiler does not expose builtin size/ptrdiff types"
#endif

#ifndef NULL
#ifndef __cplusplus
#define NULL ((void*)0)
#else
#define NULL 0
#endif
#endif

#if defined(__GNUC__) || defined(__clang__) || defined(_MSC_VER)
#define offsetof(type, member) __builtin_offsetof(type, member)
#else
#define offsetof(type, member) ((size_t)&(((type *)0)->member))
#endif

#ifdef __cplusplus
}
#endif

#endif /* __LIBZC_STDDEF_H */
