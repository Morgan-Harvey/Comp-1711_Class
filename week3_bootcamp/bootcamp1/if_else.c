#include <stdio.h>

int main(){
    int mark;
    printf("what was your mark? ");
    scanf("%d", &mark);

// making some conditions or some junk 
    if(mark >= 0 && mark <=100){

        if(mark >= 40)
        {
            printf("your parents wont kill you :D \n");
        } else
            printf("i will send flowers to your funeral (╥﹏╥) \n");
    } 
    else if (mark > 100)
    {
        printf("Look at this over achiever (･ω･)b \n");
    }
        else{
            printf("how did you manage that (ಠ_ರ) \n");
        }
    return 0;
}