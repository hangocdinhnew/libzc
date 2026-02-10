#ifndef __LIBZC_BITS_HELPER_H
#define __LIBZC_BITS_HELPER_H

#ifdef __cplusplus
extern "C" {
#endif

#ifndef LIBZC_RESTRICT
  #if defined(_MSC_VER)
    #define LIBZC_RESTRICT __restrict
  #elif defined(__GNUC__) || defined(__clang__)
    #define LIBZC_RESTRICT __restrict__
  #else
    #define LIBZC_RESTRICT restrict
  #endif
#endif

#ifdef __cplusplus
}
#endif

#endif /* __LIBZC_BITS_HELPER_H */
