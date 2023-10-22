#include <stdio.h>

int main()
{
    int nums[5] = {1,2,3,4,5};
    int last = nums[4];
    for (int count = 0; count < 4; count++)
    {
        nums[count] = nums[count+1];
    }
    nums[0] = last;

    for (int count = 4; count < 0; count--){
    printf("rotation: %d\n",nums[count]);
    }
}