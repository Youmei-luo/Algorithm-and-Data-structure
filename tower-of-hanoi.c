// Tower of Hanoi
#include <stdio.h>
 
void hanoi(int n,char start,char temp,char end)
{
  if(n>0){
    hanoi(n-1,start,end,temp);
    printf("Move the %d th disk from %c to %c \n",n,start,end);
    hanoi(n-1,temp,start,end);
  }
}
 
int main()
{
  int n;
  printf("Number of disks "); scanf("%d",&n);
  hanoi(n,'A','B','C');
  return 0;
}
