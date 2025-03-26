#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/split.h"

int scan_part(const char *filename, int part_size) {
    FILE *file = fopen(filename, "rb");
    if (!file) return -1;

    unsigned char *s = malloc(part_size);
    if (!s) {
        fclose(file);
        return -1;
    }

    size_t total_read = 0;
    size_t ret;
    while ((ret = fread(s, 1, part_size, file)) > 0) {
        for (size_t i = 0; i < ret; ++i)
            printf("%02x ", s[i]);
        printf("\nRead = %zu\n\n", ret);
        total_read += ret;
    }

    free(s);
    fclose(file);
    return 0;
}

void bits_out2(int n) {
    for (long unsigned int i = 0; i < sizeof(int) * 8; ++i) {
        printf("%d", (n >> (31 - i)) & 1);
        ++i;
        if (i % 4 == 0) putchar(' ');
    }
}