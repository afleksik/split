#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int scan_part(const char *filename, int part_size)
{
    FILE *file = fopen(filename, "rb");
    int i = 0;
    unsigned char s[part_size];
    
    while(!feof(file))
    {
        size_t ret = fread(s, 1, part_size, file);
        for (int i = 0; i < ret; ++i)
        {
            printf("%#02x ", s[i]);
        }
        printf("\nReaded = %zu\n\n", ret);
    }
    fclose(file);
    return 0;
}
