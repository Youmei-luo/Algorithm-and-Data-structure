#include <stdio.h>
#include <string.h>
 
int SimpleSearch(char text[],char key[])
{
  int i,j,m,n;
 
  m = strlen(key);
  n = strlen(text);
 
  for(i=0;i<=n-m;i++){
    for(j=0;j<n;j++){
      if(text[i+j] != key[j]) break;
    }
    if(j==m) return i;
  }
  return -1;
}
 
int main()
{
  char Text[]="She sells seashells by the seashore.";
  char Key[64];
  int rc,i,m,s;
 
  printf("Text       : %s\n",Text);
  printf("Key word   : "); scanf("%s",Key);
 
  m=strlen(Key);
 
  printf("search result  : ");
  s=0;
  while(1){
    rc = SimpleSearch(Text+s,Key);
    if(rc!=-1){
      for(i=s;i<s+rc;i++) printf("%c",Text[i]);
      printf("\e[7m"); //Reverse display
      for(i=s+rc;i<s+rc+m;i++) printf("%c",Text[i]);
      printf("\e[0m"); //Reset display
      s=s+rc+m;
    }else{
      printf("%s\n",Text+s);
      break;
    }
  }
  return 0;
}
