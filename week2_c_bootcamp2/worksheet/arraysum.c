#include <stdio.h>

int main()
{
int nums[] = {12,24,26,48,60};
int count;
int sum = 0;
for (count = 0; count < 5; count++)
{
    sum += nums[count];
}
    printf("the sum of the array is %d\n", sum);
}





