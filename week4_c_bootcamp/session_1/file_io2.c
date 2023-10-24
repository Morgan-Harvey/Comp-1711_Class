#include <stdio.h>

FILE *open_file(char filename[],char mode[])
{
FILE *file = fopen(filename, mode);
if (file == NULL){
    perror("no file found dummy");
    return file;
}

}
int main(){
char filename[] = "./data.txt";
FILE *file = open_file(filename, "r");

int buffersize = 2048;
char file_data[buffersize];
int count = 0;
while(fgets(file_data, buffersize, file)){
    printf("%s", file_data);
    count++;
}
printf("the loop was exececuted %d times\n", count);
fclose(file);
return 0;


}