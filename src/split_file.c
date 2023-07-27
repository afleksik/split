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

static int len_of_number(int n)
{
	int len = 1;
	int sign = (n < 0);

	while ((n /= 10))
		len++;
	return len + sign;
}

static enum e_errors {
	ESUCCESS,
	ENOFILE,
	ENOPARAM,
	EMULPAR // multiple params set
};

int split(char *filename, size_t size, size_t parts)
{
	FILE *fp;

	if (filename == NULL)
		return ENOFILE;
	if (size == 0 && parts == 0)
		return ENOPARAM;
	if (size != 0 && parts != 0)
		return EMULPAR;

	if (!(fp = fopen(filename, "r")))
		return errno;

	if (parts)
	{
		// get_filesize();
		// size = cell(filesize / parts);
	}
	// while ()
	// {
	// fout = fopen(generate_name(filename, part_num), "w");
	// fread(buf, size, 1, fp);
	// fwrite(buf, size, 1, fout);
	// fclose(fout);
	// }
	return ESUCCESS;
}