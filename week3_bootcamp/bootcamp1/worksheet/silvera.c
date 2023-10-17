#include <stdio.h>

int main(){
    int mark;
    printf("what was your mark? ");
    scanf("%d", &mark);

// making some conditions or some junk 
    if(mark >= 0 && mark <=100){

        if(mark >= 50 && mark < 70)
        {
            printf(" PASS your parents wont kill you :D \n");
        } 
        else if (mark < 50 )
        {
            printf("FAIL i will send flowers to your funeral (╥﹏╥) \n");
        }
        else 
            printf(" DISTINCTION Look at this over achiever (◯Δ ◯ ∥) / (･ω･)b \n");
    } 
    else 
        printf("how did you manage that (ಠ_ರ) \n");
    return 0;
}