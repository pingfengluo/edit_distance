//*********************************************************************************
//
//  levenshtein.cc
//
//  Created by Pingfeng on 04/06/19.
//
//  Description: 
//
//*********************************************************************************
#include "levenshtein.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <cstring>

int levenshtein_distance(char const *src, size_t const src_len, char const *dst, size_t const dst_len) {
    assert(src != NULL && dst != NULL);

    if (src == dst) {
	return 0;
    } else if (src_len == 0) {
	return  dst_len;
    } else if (dst_len == 0) {
	return  src_len;
    }

    int d[src_len + 1][dst_len + 1];
    for (size_t i = 0; i < src_len + 1; i++) d[i][0] = i;
    for (size_t j = 0; j < dst_len + 1; j++) d[0][j] = j;

    for (size_t i = 1; i < src_len + 1; i++) {
	for (size_t j = 1; j < dst_len + 1; j++) {
#define min(a, b) ((a) < (b) ? (a) : (b))
	    d[i][j] = min(min(d[i-1][j], d[i][j-1]) + 1, d[i-1][j-1] + (src[i-1] == dst[j-1] ? 0 : 1));
#undef min
	}   
    }   
    return d[src_len][dst_len];
}

int main(int argc, char **argv) {
    const char str1[] = "abcde";
    const char str2[] = "ab2efg";
    const char str3[] = "";
    int dist0 = levenshtein_distance(str1, strlen(str1), str2, strlen(str2));
    int dist1 = levenshtein_distance(str2, strlen(str2), str1, strlen(str1));
    int dist2 = levenshtein_distance(str1, strlen(str1), str3, strlen(str3));
    int dist3 = levenshtein_distance(str3, strlen(str3), str1, strlen(str1));
    int dist4 = levenshtein_distance(str1, strlen(str1), str1, strlen(str1));
    printf("edit_dist of '%s' and '%s' is: %d \n", str1, str2, dist0);
    printf("edit_dist of '%s' and '%s' is: %d \n", str2, str1, dist1);
    printf("edit_dist of '%s' and '%s' is: %d \n", str1, str3, dist2);
    printf("edit_dist of '%s' and '%s' is: %d \n", str3, str1, dist3);
    printf("edit_dist of '%s' and '%s' is: %d \n", str1, str1, dist4);
}
