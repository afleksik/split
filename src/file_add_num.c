#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *file_add_num(char *filename, int num)
{
    int n, k, m, j, z = 0;
    int length = strlen(filename);

    for (n = length; (filename[n] != '.') && n >= 0; --n);

    /*
    char *file_format = (char*)malloc((length - n + 1) * sizeof(char));
    z = n;
    while(filename[n] != '\0')
    {
       file_format[k] = filename[n - 1];
       ++k;
       ++n;
    }
    */

    char *filename_noformat = (char*)malloc((n + 1) * sizeof(char));

    while (filename[m] != '\0' && m < n)
    {
        filename_noformat[j] = filename[m];
        ++j;
        ++m;
    }

    printf("%s\n", filename_noformat);
    int len = strlen(filename_noformat);
    char *final = (char*)malloc((len + 4) * sizeof(char));
    sprintf(final, "%s_%d", filename_noformat, num); 
    return final;
}