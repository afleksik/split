#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <getopt.h>
#include <errno.h>
#include "../inc/split.h"

int main(int argc, char **argv) {
    int opt;
    long parts = 0, size = 0;
    char *output_prefix = NULL;
    int err = 0;

    while ((opt = getopt(argc, argv, "n:s:o:")) != -1) {
        if (opt == -1) break;
        char *endptr;
        switch (opt) {
            case 'n':
                parts = strtol(optarg, &endptr, 10);
                if (*endptr != '\0' || parts <= 0) err = 1;
                break;
            case 's':
                size = strtol(optarg, &endptr, 10);
                if (*endptr != '\0' || size <= 0) err = 1;
                break;
            case 'o':
                output_prefix = optarg;
                break;
            default:
                usage(argv[0]);
                return 1;
        }
    }

    if (err || optind >= argc || (parts <= 0 && size <= 0) || (parts > 0 && size > 0)) {
        usage(argv[0]);
        return 1;
    }

    for (int i = optind; i < argc; i++) {
        FILE *fp = fopen(argv[i], "rb");
        if (!fp) {
            fprintf(stderr, "Error opening %s: %s\n", argv[i], strerror(errno));
            continue;
        }
        long total_size = file_size(fp);
        fclose(fp);

        if (total_size <= 0) {
            fprintf(stderr, "Invalid file size for %s\n", argv[i]);
            continue;
        }

        long part_size = size > 0 ? size : (total_size + parts - 1) / parts;
        int result = split(argv[i], output_prefix, part_size);
        if (result != 0)
            fprintf(stderr, "Failed to split %s: %s\n", argv[i], strerror(result));
    }

    return 0;
}