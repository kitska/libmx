#include "../inc/libmx.h"

char* mx_itoa(int number) {
    int maxDigits = 1;
    int temp = number;
    while (temp / 10 != 0) {
        maxDigits++;
        temp /= 10;
    }

    char* result = (char*)malloc((maxDigits + 1) * 1);
    if (result == NULL) {
        return NULL;
    }

    int i = 0;
    if (number < 0) {
        result[i++] = '-';
        number = -number;
    }

    do {
        result[i++] = '0' + (number % 10);
        number /= 10;
    } while (number > 0);

    result[i] = '\0';

    int start = (result[0] == '-') ? 1 : 0;
    int end = i - 1;
    while (start < end) {
        char temp = result[start];
        result[start] = result[end];
        result[end] = temp;
        start++;
        end--;
    }

    return result;
}
