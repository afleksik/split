#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *get_filename(const char *filepath)
{
    const char *basename;

    if (!filepath || !filepath[0])
        return NULL;
    if (!(basename = strrchr(filepath, '/')))
        basename = filepath;
    else
        ++basename;
    if (*basename == 0
        || strcmp(".", basename) == 0 || strcmp("..", basename) == 0)
        return NULL;
    return strdup(basename);
}

char *generate_filename(const char *filename)
{
    return NULL;
}

static size_t num_len(size_t n)
{
    size_t len = 1;

    while ((n /= 10))
        len++;
    return len;
}

char *filename_add_num(char *filename, size_t part)
{
    size_t len = strlen(filename) + num_len(part) + 1; // for '_'
    char *final = malloc((len + 1) * sizeof(char));
    if (final)
        snprintf(final, len, "%s_%zu", filename, part); 
    return final;
}