#include <stdio.h>
#include <stdlib.h>

int main()
{
char filename[] = "./squares.dat";
FILE *file = fopen(filename, "r");

char dat[100];

fgets(dat, 100, file);

printf("%s", dat);
    fclose(file);
    return 0;

}