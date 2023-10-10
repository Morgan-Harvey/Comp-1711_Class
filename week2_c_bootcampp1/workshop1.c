#include <stdio.h>

int main(){
    int num1;
    int num2;
    printf("Enter the height: ");
    scanf("%d", &num1);
    printf("Enter the width: ");
    scanf("%d", &num2);
    int num3 = num1 * num2;
    printf("the area is: %d\n", num3);
return 0;
}