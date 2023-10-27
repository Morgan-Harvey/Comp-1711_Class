#include <stdio.h>

int main()
{
char filename[] = "squares.dat";
FILE *file = fopen(filename, "w");
    int num;
    printf("type in a number: \n");
    scanf("%d", &num);

    for (int i = 0; i <= num; i++)
    {
        int pow = i * i;
        fprintf(file, "%d\n", pow);
    }
    fclose(file);
    return 0;

}