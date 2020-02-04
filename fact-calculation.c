//Factorial calculation programming with address display of provisional arguments.
#include <stdio.h>

int fact(int n)
{
    printf("Address of n %p \n",&n); 
    if(n==1) return 1;
    return  (n * fact(n-1)) ;
}
 
int main(void)
{
    int n;
    printf("Input positive integer n : "); scanf("%d",&n);
    if(n>0) printf("%d!=%d\n",n,fact(n));
    return 1;
}
