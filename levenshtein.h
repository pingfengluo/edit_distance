#ifndef ___EDIT_DIST__H__
#define ___EDIT_DIST__H__

#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif
    int levenshtein_distance(const char *src, const size_t src_len, const char *dst, const size_t dst_len);
#ifdef __cplusplus
}
#endif

#endif
