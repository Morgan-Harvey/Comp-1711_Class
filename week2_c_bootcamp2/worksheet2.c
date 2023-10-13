# include<stdio.h>

int main()
{
 char str[] = "Hello";
 int count = 0;
    
while (str[count] != '\0')
{       
    count++;
}

    int i;
    for ( i = count - 1; i >= 0 ; i--)
    {
        printf("%c\n", str[i]);
    }




}
