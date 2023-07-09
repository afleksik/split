#include <stdio.h>
#include <getopt.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>

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

int len_of_number(int n)
{
	int len = 1;
	int sign = (n < 0);

	while ((n /= 10))
		len++;
	return len + sign;
}

void usage(const char *name)
{
	printf("Usage: %s [-n|-s number] [-o preffix] file...\n"
		"OPTIONS:\n"
			"\t-n\t- split file on n parts\n"
			"\t-s\t- split file on (size bytes) file\n"
			"\t-o\t- output path\n", name);
}



long file_size(FILE *fd);

int main()
{
	// unsigned int n = 0;
	// int ret = scanf("%u", &n);

	// printf("in - %u\n", n);
	// printf("ret - %d\n", ret);

	// return 0;

	FILE *fp = fopen("split_file.c", "rb");
	long size = file_size(fp);
	printf("file size = %ld\n", size);

	// itoa()
	// sprintf()
	// "filename_part.part"
	// "split_file_00.part"
	// "split_file_01.part"
	// "split_file_02.part"

	while (part)
	{
		
	}

	fclose(fp);
	return 0;


	/*int parts = 0;
	int size = 0;
	int err = 0;
	int opt = 0;
	char *p_e = NULL;
	char *output_path = NULL;

   	while ((opt = getopt(argc, argv, "n:s:o:")) != -1)
	{
		switch (opt)
		{
			case 'n':
				parts = strtol(optarg, &p_e, 10);
				err = (err
						|| p_e != optarg + strlen(optarg)
						|| errno || parts < 0);
				break;
			case 's':
				size = strtol(optarg, &p_e, 10);
				err = (err
						|| p_e != optarg + strlen(optarg)
						|| errno || size < 0);
				break;
			case 'o':
				output_path = strdup(optarg);
				break;
			case 'h':
			default: // '?'
				usage(argv[0]);
				return 0;
		}
	}
	
	if (optind >= argc)
	{
		fprintf(stderr, "Expected argument after options\n");
		return -1;
	}

	if (err)
	{
		fprintf(stderr, "Incorrect numbers\n");
		return -1;
	}
	else if (parts >= 0 ^ size >= 0)
	{
		fprintf(stderr, "Parts or size must be set.\n");
		return -1;
	}

	for (int i = optind; i < argc; ++i)
	{
		if ((err = split(argv[i], size, parts)))
			fprintf(stderr, "split: %s: %s\n", argv[i], strerror(err));
	}
	return 0;
	*/
}
