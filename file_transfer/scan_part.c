#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int scan_part(const char *filename, int part_size)
{
    FILE *file = fopen(filename, "r");
    int scanned = 0;
    int i = 0;
    unsigned char s[part_size];
    
    while(!feof(file) && scanned < part_size)
    {
        size_t ret = fread(s, 1, part_size, file);
        for (int i = 0; i < part_size; ++i)
        {
            printf("%#02x ", s[i]);
        }
        printf("\nReaded = %zu\n\n", ret);
        scanned++;
    }
    fclose(file);
    return 0;
}

void bits_out2(int n)
{
    for (int i = 0; i < sizeof(int) * 8; )
    {
        printf("%d", (n >> (31 - i)) & 1);
        ++i;
        if (i % 4 == 0)
            putchar(' '); // putc(' ', stdout);
    }
}

// 128 = 2 ^ 7 = 10000000
// 127 = 1111111
//           100

int main()
{
    // scan_part("a.out", 10);

    bits_out2(123);
    putchar('\n');

    return 0;
}