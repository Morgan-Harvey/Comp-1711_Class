#include <stdio.h>
int main(){
char filename[] = "./data.txt";
FILE *file = fopen(filename, "r");
FILE *file = fopen(filename, "r");
if(file == NULL){
    perror("OY READ THE FILE BETTER FOUR EYES");
    return 1;
}
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