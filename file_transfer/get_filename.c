#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *get_filename(char *filepath)
{
    int length_path = strlen(filepath);
    int kol = 0;
    int k = 0;
    int j = 0;
    int n = 0;
    int m = 0;
    int i = length_path;
    int final_length = 0;
    //printf("%d\n", length_path);

    for (i; (filepath[i] != '\\') && (filepath[i] != '/') && i >= 0; --i);

    char *filename = (char*)malloc((length_path - i - 1) * sizeof(char));

    while (filepath[++i] != '\0')
    {
        filename[k] = filepath[i];
        ++k;
    }

    final_length = strlen(filename);
    for (n = final_length; (filename[n] != '.') && n >= 0; --n);
    char *file_format = (char*)malloc((final_length - n + 1) * sizeof(char));
    k = 0;
    while(filename[n - 1] != '\0')
    {
        file_format[k] = filename[n];
        ++k;
        ++n;
    }
    char *filename_noformat = (char*)malloc((n + 1) * sizeof(char));

    while (filename[m] != '\0' && m < n)
    {
        filename_noformat[j] = filename[m];
        ++j;
        ++m;
    }
    return filename_noformat;
}