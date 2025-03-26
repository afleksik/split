#include <stdio.h>

long file_size(FILE *fd) {
	long file_size = -1;
	if (!fd)
		return -1;

	long pos = ftell(fd);
	if (fseek(fd, 0, SEEK_END) != 0)
		return -1;

	file_size = ftell(fd);
	fseek(fd, pos, SEEK_SET);

	return file_size;
}