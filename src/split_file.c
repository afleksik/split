/*
1. консольное приложение без интерактива
2. Опции: (-n <parts>|-size <part_size>) [-o output_path] file...
3. Функция split(filename, size, parts)
4. Разбиение любого файла - работа с файлом в бинарном режиме
5. генерация выходных файлов (см пример ниже)
6. Вычисление размера частей ?
7. Последняя часть может быть не целой
*/

// split -o out file1
// split -o /path/to/folder/out file1
// out_0
// out_1...

// split -o /path/to/folder file1
// file1_0
// file1_1...

// filesize...
// 1. fseek ? ftell ?
// 2. man 2 stat

// man 3 basename - посмотреть что такое
// width = num_length(max_part_num, base) // positive/negative +- 1, 0, INT_MAX, INT_MIN
// strlen(output_filename) + 1 + width + 1
// const char * const template = "%s_%0*d", 
// #define TEMPLATE "%s_%0*d"

// main cycle
// - gen file name
// - open
// - write current part
// - close


// XXX
// 127 = 100 + 20 + 7 = 1 * 10 ** 2 + 2 * 10 ** 1 + 7 * 10 ** 0
// 101010111 = 1 * 2**8 + 
// 37 = 32 + 4 + 1 = 100101
// 0000 0000 0000 0000 0000 0000 0010 0101
// 1 "-"
// -37 = 100101 ->
// 1111 1111 1111 1111 1111 1111 1101 1010 // инверсный код
// 1111 1111 1111 1111 1111 1111 1101 1011 // дополнительный код

#include <stdio.h>
#include <getopt.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/split.h"

void usage(const char *name) {
	printf("Usage: %s (-n <parts> | -s <size>) [-o output_prefix] file...\n"
		   "OPTIONS:\n"
		   "\t-n <parts>\t- split file into <parts> parts\n"
		   "\t-s <size>\t- split file into parts of <size> bytes\n"
		   "\t-o <prefix>\t- output filename prefix\n", name);
}

int split(const char *filename, const char *output_prefix, long part_size) {
	FILE *in = fopen(filename, "rb");
	if (!in) return errno;

	long total_size = file_size(in);
	if (total_size < 0) {
		fclose(in);
		return EINVAL;
	}

	size_t part_number = 0;
	long bytes_remaining = total_size;
	char *basename = get_filename(output_prefix ? output_prefix : filename);
	if (!basename) {
		fclose(in);
		return EINVAL;
	}

	while (bytes_remaining > 0) {
		long current_part_size = (bytes_remaining > part_size) ? part_size : bytes_remaining;
		int num_digits = num_len((total_size + part_size - 1) / part_size);
		char *out_filename = filename_add_num(basename, part_number, num_digits);
		if (!out_filename) {
			free(basename);
			fclose(in);
			return ENOMEM;
		}

		FILE *out = fopen(out_filename, "wb");
		if (!out) {
			free(out_filename);
			free(basename);
			fclose(in);
			return errno;
		}

		unsigned char *buffer = malloc(current_part_size);
		if (!buffer) {
			fclose(out);
			free(out_filename);
			free(basename);
			fclose(in);
			return ENOMEM;
		}

		size_t bytes_read = fread(buffer, 1, current_part_size, in);
		if (bytes_read == 0 && ferror(in)) {
			free(buffer);
			fclose(out);
			free(out_filename);
			free(basename);
			fclose(in);
			return EIO;
		}

		fwrite(buffer, 1, bytes_read, out);
		free(buffer);
		fclose(out);
		free(out_filename);

		bytes_remaining -= bytes_read;
		part_number++;
	}

	free(basename);
	fclose(in);
	return 0;
}