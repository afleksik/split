#include <stdio.h>
#include <stdlib.h>


// error list - optional
// errno = EINVAL

// int split(char *filename, size_t parts, size_t size)
// 1 - 10 0
// 2 - 0 10
// 3 - 0 0 - EINVAL
// 4 - 10 10 - EINVAL

// new_file_0001

// strrchr

void usage(const char *name)
{
	printf("Usage: %s [-n|-s number] [-o preffix] file...\n"
		"OPTIONS:\n"
			"\t-n\t- split file on n parts\n"
			"\t-s\t- split file on (size bytes) file\n"
			"\t-o\t- output path\n", name);
}

/*int main()
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
	
}
*/


// file1 - 10M
// file2 - 20M

// split (file1)
// split (file2)