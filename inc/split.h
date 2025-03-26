#ifndef SPLIT_H
#define SPLIT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *get_filename(const char *filepath);
char *filename_add_num(char *filename, size_t part, int num_digits);
size_t num_len(size_t n);

long file_size(FILE *fd);

int scan_part(const char *filename, int part_size);
void bits_out2(int n);

int split(const char *filename, const char *output_prefix, long part_size);

void usage(const char *name);

#endif