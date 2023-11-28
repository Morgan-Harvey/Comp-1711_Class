#include <stdio.h>

void printArray(int a[][3] ){
  for (size_t i = 0; i <= 1; ++i) {
     for (size_t j = 0; j <= 2; ++j) {
        printf("%d ", a[i][j]);
     }
     printf("\n"); // start new line of output 
     }
}

int main() {
  char array1[100] = {a, r, g};
  printf("%p\n", array1);
  printf("%p\n", &array1[1]);
  printf("%p\n", &array1[2]);
  

  return 0;
}