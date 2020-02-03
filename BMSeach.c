#include <stdio.h>
#include <string.h>
int COUNT=0;
 
int SimpleSearch( char text[ ], char key[ ])
{
  int i,j,m,n;
 
  n = strlen(text);
  m = strlen(key);
 
  for(i=0;i<n-m;i++){
    for(j=0;j<m;j++){
      COUNT++;
      if(text[i+j] != key[j]) break;
    }
    if(j==m) return i;
  }
  return -1;
}
 
int BMSearch(unsigned char text[], unsigned char key[])
{
  int table[256];
  int nt,nk,i,t,k;
 
  nt = strlen(text);
  nk = strlen(key);
 
  //Create table
  for(i=0;i<256;i++) table[i]=nk;   
  for(i=0;i<nk;i++) table[key[i]]=nk-i-1;
 
  //Start searching
  t = k = nk-1;
  while(t<nt){
    COUNT++;
    if(text[t]==key[k]){
      if(k==0) return t;
      t--; k--; 
    }else{
      if(table[text[t]] <= nk-1-k) t = t+nk-k;
      else t = t + table[text[t]];
      k = nk-1;
    }
  }
  return(-1);
}
int main()
{
  char text[]="She sells seashells by the seashore.";
  char key[64];
  int rc;
 
  printf("text       : %s\n",text);
  printf("Key word   : "); scanf("%s",key);
 
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
 
  printf("\n=MB method\n");
  COUNT=0;
  rc = BMSearch(text,key);
  printf("Comparison     : %d times\n",COUNT);
  printf("search result  : ");
  if(rc!=-1){
    printf("The key word was serched for the %d letter\n",rc+1);
  }else{
    printf("No keyword was searched\n");
  }
 
  return 0;
}
