#include <stdio.h>
#include <string.h>
int COUNT=0;
 
int SimpleSearch( char text[ ], char key[ ])
{
  int i,j,m,n;
 
  n = strlen(text);
  m= strlen(key);
 
  for(i=0;i<=n-m;i++){
    for(j=0;j<m;j++){
      COUNT++;
      if(text[i+j] != key[j]) break;
    }
    if(j==m) return i;
  }
  return -1;
}
 
int KMPSearch(char text[ ], char key[])
{
  int i,j,k,l,m,n;
  int table[64];
 
  m=strlen(key);
  n=strlen(text);
 
  //Create table
  table[0]=table[1]=0;
  k=1; l=0;
  while(k<m){
    if(key[k]==key[l]){
      k++;l++;
      table[k]=l;
    }else if(l>0){
      l=table[l];
    }else{
      k++;
      table[k]=0;
    }
  }
 
  //Display the table.
  printf("Created table : ");
  for(i=0;i<m;i++) printf("%d",table[i]);
  printf("\n");
 
  //Start searching
  i=0;j=0;
  while(i<=n-m){
    COUNT++;
    if(text[i+j]==key[j]){
      j++;
      if(j==m)return i;
    }else{
      if(j==0)i++;
      else i=i+j-table[j];
      j=table[j];
    }
  }
  return(-1);
}
 
int main()
{
  char text[]="aaaaaaaaaaaa";
  char key[]="aaab";
  int rc;
 
  printf("Text       : %s\n",text);
  printf("Key word   : %s\n",key);
 
  printf("\n=Simple search method=\n");
  COUNT=0;
  rc = SimpleSearch(text,key);
  printf("Comparison     : %d times\n",COUNT);
  printf("search result  : ");
  if(rc!=-1){
    printf("The key word was serched for the %d letter\n",rc+1);
  }else{
    printf("No keyword was searched\n");
  }
 
  printf("\n=KMP method=\n");
  COUNT=0;
  rc = KMPSearch(text,key);
  printf("Comparison     : %d times\n",COUNT);
  printf("search result  : ");
  if(rc!=-1){
    printf("The key word was serched for the %d letter\n",rc+1);
  }else{
    printf("No keyword was searched\n");
  }
 
  return 0;
}
