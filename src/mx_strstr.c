#include "../inc/libmx.h"


char *mx_strstr(const char *haystack, const char *needle) {
	if (haystack == NULL || needle == NULL) {
        return NULL;
    }

    while (*haystack != '\0') {
        const char *haystackPtr = haystack;
        const char *needlePtr = needle;

        while (*needlePtr != '\0' && *haystackPtr == *needlePtr) {
            haystackPtr++;
            needlePtr++;
        }

        if (*needlePtr == '\0') {
            return (char *)haystack;
        }

        haystack++;
    }

    return NULL;
}
