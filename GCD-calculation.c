//Programming of greatest common divisor calculation by Euclidean algorithm
#include <stdio.h>
 
int GCD( int A, int B)
{
  if(B==0) return A;
  return GCD(B, A%B);
}
 
int main()
{
  int a,b;
  printf("Value 1 : "); scanf("%d",&a);
  printf("value 2 : "); scanf("%d",&b);
  printf("The greatest common divisor of %d and %d is %d \n",a,b,GCD(a,b));
  return 0;
}
