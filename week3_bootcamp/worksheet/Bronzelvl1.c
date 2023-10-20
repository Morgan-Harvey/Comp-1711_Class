#include <stdio.h>
# define PI           3.14159265358979323846

float CircleArea(float radius)
{
    float calc;
    calc = PI * (radius * radius);
    return calc;

}
int main()
{
    float rad;
    printf(" type in the area of the radius\n ");
    scanf(" %f", &rad);

    printf(" the area of the circle is %.2f \n", CircleArea(rad));

}