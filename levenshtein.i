%module levenshtein
%{
#define SWIG_FILE_WITH_INIT
#include "levenshtein.h"
%}
int levenshtein_distance(const char *src, const size_t src_len, const char *dst, const size_t dst_len);
