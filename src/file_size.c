#include <stdio.h>

long file_size(FILE *fd)
{
	long file_size = 0;
	long pos = 0;

	if (fd == NULL)
		return -1;

	pos = ftell(fd);
	
	fseek(fd, 0, SEEK_END);
	file_size = ftell(fd);
	fseek(fd, pos, SEEK_SET);

	return file_size;
}