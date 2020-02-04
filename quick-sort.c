#include <stdio.h>
#include <stdlib.h>
#include <time.h>
 
#define N 100
 
int COMPARE_COUNT,SWAP_COUNT,MOVE_COUNT;
 
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
 
void QuickSort(int x[], int min, int max )
{
    int p,i,j,tmp;
 
    if(min>=max) return;
 
    p=(x[min]+x[max])/2;
    i=min; j=max;
    while(1){
        while(x[i]<p){i++; COMPARE_COUNT++;}
        COMPARE_COUNT++;
        while(x[j]>p){j--; COMPARE_COUNT++;}
        COMPARE_COUNT++;
        if(j<=i) break;
        tmp=x[i]; x[i]=x[j]; x[j]=tmp; SWAP_COUNT++;
        i++; j--;
    }
 
    QuickSort(x,min,i-1);
    QuickSort(x,j+1,max);
 
    return;
}
 
void InsertionSort(int x[],int n)
{
    int i,j,tmp;
 
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
 
void main()
{
    int i;
    int data1[N];
    int data2[N];
 
    GenerateRandomData(N,data1,N);
    for(i=0;i<N;i++)data2[i]=data1[i]; //Copy data
    printf("The number of data %d\n",N); //Display the number of data
 
    printf("\n=Insertion sort=\n");
    COMPARE_COUNT=MOVE_COUNT=0;
    InsertionSort(data1,N);  
    printf("Comparison %d times, move %d  times \n",COMPARE_COUNT,MOVE_COUNT);
 
    printf("\n=Quick sort=\n");
    COMPARE_COUNT=SWAP_COUNT=0;
    QuickSort(data2,0,N-1);
    printf("Comparison %d times, move %d times \n",COMPARE_COUNT,SWAP_COUNT);
     
    return;
}
