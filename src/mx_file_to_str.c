#include "../inc/libmx.h"

char *mx_file_to_str(const char *file) {
	int fd = open(file, O_RDONLY);
    if (fd == -1) {
        return NULL;
    }

    off_t file_size = lseek(fd, 0, SEEK_END);
    if (file_size == -1) {
        close(fd);
        return NULL;
    }

    if (lseek(fd, 0, SEEK_SET) == -1) {
        close(fd);
        return NULL;
    }

    char *str = mx_strnew(file_size);
    if (str == NULL) {
        close(fd);
        return NULL; 
    }


    ssize_t bytes_read = read(fd, str, file_size);
    close(fd);

    if (bytes_read == -1 || (size_t)bytes_read != (size_t)file_size) {
        mx_strdel(&str);
        return NULL;
    }

    return str;
}
