#include <stdio.h>

float sum (float a , float b)
{
    float answer;
    answer = a + b;
    return answer;
}

int main(){
    float y = 2.1;
    float z = sum(5 , y);
    printf("the sum of 5 and %.2f is %.2f\n", y, z);
}