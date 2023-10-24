#include <stdio.h>
#include "utils.h"

FILE *open_file(char filename[],char mode[])
{
FILE *file = fopen(filename, mode);
if (file == NULL){
    perror("no file found dummy");
    exit(1);
}
    return file;
}


