#include "../inc/libmx.h"

void *mx_realloc(void *ptr, size_t size) {
	if (ptr == NULL) {
        return malloc(size);
    } else if (size == 0) {
        free(ptr);
        return NULL;
    } else {
        void *new_ptr = malloc(size);
        if (new_ptr == NULL) {
            return NULL;
        }

        size_t min_size = size;
        size_t old_size = 0;

        char *old_ptr = (char *)ptr;
        while (old_ptr[old_size] != '\0') {
            old_size++;
        }

        if (min_size > old_size) {
            min_size = old_size;
        }

        for (size_t i = 0; i < min_size; i++) {
            ((char *)new_ptr)[i] = ((char *)ptr)[i];
        }
        free(ptr);
        return new_ptr;
    }
}
