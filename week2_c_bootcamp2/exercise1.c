#include <stdio.h>
int main()
{

    int v = 20;
    while (v >= 0)
    {
        if (v % 2 == 0)
        {
            printf("%d\n",v);
            v --;
        }
    }
}
