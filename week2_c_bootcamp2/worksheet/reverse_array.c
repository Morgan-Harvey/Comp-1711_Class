#include <stdio.h>

int main()
{
int nums[] = {12,24,26,48,60};
for (int count = 4; count >= 0; count--)
{
    int reverse = nums[count];
    printf("%d\n",reverse);
}
return 0;
}