#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/split.h"

char *get_filename(const char *filepath) {
    const char *basename;

    if (!filepath || !filepath[0])
        return NULL;
    if (!(basename = strrchr(filepath, '/')))
        basename = filepath;
    else
        ++basename;
    if (*basename == 0 || strcmp(".", basename) == 0 || strcmp("..", basename) == 0)
        return NULL;
    return strdup(basename);
}

size_t num_len(size_t n) {
    size_t len = 1;
    while (n /= 10)
        len++;
    return len;
}

char *filename_add_num(char *filename, size_t part, int num_digits) {
    size_t len = strlen(filename) + num_digits + 2; // '_' + digits + null
    char *final = malloc(len);
    if (final)
        snprintf(final, len, "%s_%0*zu", filename, num_digits, part);
    return final;
}