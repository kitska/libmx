#include "../inc/libmx.h"

char *mx_del_extra_spaces(const char *str) {
	if (str == NULL) {
        return NULL;
    }

    char *trimmed_str = mx_strnew(mx_strlen(str));

    if (trimmed_str == NULL) {
        return NULL;
    }

    bool in_word = false;
    size_t trimmed_index = 0;

    for (size_t i = 0; str[i] != '\0'; i++) {
        if (!mx_isspace(str[i]) && mx_isprint(str[i])) {
            trimmed_str[trimmed_index++] = str[i];
            in_word = true;
        } else if (in_word) {
            trimmed_str[trimmed_index++] = ' ';
            in_word = false;
        }
    }

    trimmed_str[trimmed_index] = '\0';

    return trimmed_str;
}
