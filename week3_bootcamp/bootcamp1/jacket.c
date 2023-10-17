#include <stdio.h>

int main(){
    float temperature;
    printf("what is the temperature today? ");
    scanf("%f", &temperature);

// making some conditions or some junk 
    if(temperature >= 20)
        printf("i can walk outside naked today :D \n");
    else if(temperature >= 10)
        printf("I have to go against nature and wear clothes D: \n");
    else
        printf("i will freeze my balls off without a jacket \n");
    return 0;
}