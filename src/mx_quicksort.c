#include "../inc/libmx.h"

int mx_quicksort(char** arr, int left, int right) {
    if (!arr)
        return -1;

    int swaps = 0;
    if (left < right) {
        char* pivot = arr[left + (right - left) / 2];
        int i = left;
        int j = right;

        while (i <= j) {
            while (mx_strlen(arr[i]) < mx_strlen(pivot))
                i++;
            while (mx_strlen(arr[j]) > mx_strlen(pivot))
                j--;

            if (i <= j) {
                if (i != j) {
                    char* temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                    swaps++;
                }
                i++;
                j--;
            }
        }

        swaps += mx_quicksort(arr, left, j);
        swaps += mx_quicksort(arr, i, right);
    }

    return swaps;
}
