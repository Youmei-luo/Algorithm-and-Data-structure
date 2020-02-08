#include <stdio.h>
 
#define SMALL  1
#define MEDIUM 2
#define LARGE  3
 
#define OK    0
#define ERROR 1
 
#define MAX_NUM 10
int stack[MAX_NUM];
int num;
 
void push(int data)
{
   if(num==MAX_NUM){
      printf(" No more stacks \n");
      return;
   }
   stack[num]=data;
   num++;
   return;
}
 
int pop(void)
{
   if(num==0){
      printf(" No data on stack \n");
      return 0;
   }
   num--;
   return stack[num];
}
 
int check(char* str)
{
   int i;
   num=0;
   for( i=0 ; str[i]!='\0' ; i++ ){
      switch(str[i]){
         case '(':
            push(SMALL); break;
         case '{':
            push(MEDIUM); break;
         case '[':
            push(LARGE); break;
         case ')':
            if(pop()==SMALL) break;
            else return ERROR;
         case '}':
            if(pop()==MEDIUM) break;
            else return ERROR;
         case ']':
            if(pop()==LARGE) break;
            else return ERROR;
      }
   }
   if(num==0) return OK;
   else return ERROR;
}
 
void main(void)
{
   char str[100];
 
   // ex. 12/[3*{5-(4-1)]-(2+1)]
   printf(" Enter formula (up to 100 characters) : "); 
   scanf("%s",str);
 
   if(check(str)==OK) printf(" Brackets are facing each other\n");
   else printf(" Brackets are not facing each other\n");
 
   return;
}
