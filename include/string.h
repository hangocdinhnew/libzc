/*
 * SPDX-FileCopyrightText: 2026 hangocdinhnew
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
/* SPDX-License-Identifier: BSD-3-Clause */

#ifndef __LIBZC_STRING_H
#define __LIBZC_STRING_H

#ifdef __cplusplus
extern "C" {
#endif

#include "bits/helper.h"
#include "stddef.h"

  void* memcpy(void* LIBZC_RESTRICT dest, const void* LIBZC_RESTRICT src, size_t n);
  size_t strlen(const char* s);

#ifdef __cplusplus
}
#endif

#endif /* __LIBZC_STRING_H */
