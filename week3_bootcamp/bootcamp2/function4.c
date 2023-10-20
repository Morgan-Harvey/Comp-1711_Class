#include <stdio.h>

float fahr_to_celsius (float f_temp)
{
    float c_temp;
    c_temp = (f_temp-32)/1.8;
    return c_temp;
}
float fahr_to_kelvin (float f_temp)
{
    float k_temp;
    k_temp = fahr_to_celsius(f_temp)+ 273.15;
    return k_temp;
    
}
float fahr_to_NTS (float f_temp)
{
    float N_temp;
    N_temp = (f_temp-32) / 5.45454555;
    return N_temp;
}

int main(){

    float fahrenheit;
    char option;
    printf("Enter a number to conver in farenheit\n");
    scanf("%f", &fahrenheit);

    printf("\n");
    printf("Select A to convert to Celsius\n");
    printf("Select B to convert to Kelvin\n");
    printf("Select C to convert to Newton temperature scale\n");
    printf("Select Q to convert to Quit\n");

    scanf(" %c", &option);


    switch (option)
    {
    case 'A':
        printf("converted to %.2f degrees celsius\n", fahr_to_celsius(fahrenheit));
        break;
    
    case 'B':
        printf("converted to %.2f degrees Kelvin\n", fahr_to_kelvin(fahrenheit));
        break;

    case 'C':
        printf("converted to %.2f degrees Newton temperature\n", fahr_to_NTS(fahrenheit));
        break;

    case 'Q':
        break;
    }
}