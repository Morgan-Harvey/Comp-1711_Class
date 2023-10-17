#include <stdio.h>

int main()
{
    int num;
    printf("input number: ");
    scanf("%d",&num);

    if(num % 4 == 0 && num % 5 == 0){
        printf("divisable \n");
    } 
    else
        printf("not divisable \n");
    
    




}