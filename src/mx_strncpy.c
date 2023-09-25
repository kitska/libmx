#include "../inc/libmx.h"

char *mx_strncpy(char *dst, const char *src, int len) {
	if (dst == NULL || src == NULL || len <= 0) {
        return dst; 
    }

    char *originalDst = dst; 

    while (len > 0 && *src != '\0') {
        *dst = *src;
        dst++;
        src++;
        len--;
    }

    while (len > 0) {
        *dst = '\0';
        dst++;
        len--;
    }
	
	*dst = '\0';
    return originalDst;
}
