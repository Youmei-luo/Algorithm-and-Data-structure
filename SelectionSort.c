#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 100
 
int COMPARE_COUNT;
int MOVE_COUNT;
 
void GenerateRandomData(int range,int Data[],int num)
{
  int i;
  srand(time(NULL));
  for(i=0;i<num;i++){
    Data[i]=rand()%range+1;
    //printf("%d\t",Data[i]);
  }
  printf("\n");
  return;
}
 
void InsertionSort(int x[],int n)
{
  int i,j;
  int tmp;
  for(j=1;j<n;j++){
    tmp=x[j]; MOVE_COUNT++;
    for(i=j-1;i>=0;i--){
      COMPARE_COUNT++;
      if(x[i]>tmp){ x[i+1]=x[i]; MOVE_COUNT++; }
      else break;
    }
    x[i+1]=tmp; MOVE_COUNT++;
  }
  return;
}
 
void SelectionSort(int x[],int n)
{
  int i,j,max_id;
  int tmp;
  for(j=n-1;j>0;j--){
    max_id=0;
    for(i=1;i<=j;i++){
      COMPARE_COUNT++;
      if(x[max_id]<x[i])max_id=i;
    }
    tmp=x[j];
    x[j]=x[max_id];
    x[max_id]=tmp;
    MOVE_COUNT=MOVE_COUNT+3;
  }
  return;
}
 
void main()
{
  int i;
  int data1[N];
  int data2[N];
 
  GenerateRandomData(N,data1,N);
  for(i=0;i<N;i++)data2[i]=data1[i]; //Copy data
  printf("Number of data %d\n",N);  //Print number of data
 
  printf("\n=Basic insertion method=\n");
  COMPARE_COUNT=MOVE_COUNT=0;
  InsertionSort(data1,N);  
  printf("Comparison %d times、Replacement %d times \n",COMPARE_COUNT,MOVE_COUNT);
 
  printf("\n=Basic selection method=\n");
  COMPARE_COUNT=MOVE_COUNT=0;
  SelectionSort(data2,N);  
  printf("Comparison %d times、Replacement %d times\n",COMPARE_COUNT,MOVE_COUNT);
 
  return;
}
