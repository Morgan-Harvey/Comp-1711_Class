#include <stdio.h>

int main()
{
    int nums[5] = {12,24,36,48,60};
    int max_num = nums[0];

    for (int count = 0; count < 5; count++)
    {
        if (nums[count] > max_num)
        {
            max_num = nums[count];
            
        }
    }
        printf("the max element is %d\n",max_num);
        return 0;

}

