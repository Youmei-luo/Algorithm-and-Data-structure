#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 100

int COMPARE_COUNT;
int SWAP_COUNT;

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

void BubbleSort(int x[],int n)
{
    
    int i,j,tmp;

    for(j=n-1;j>0;j--){
	for(i=0;i<j;i++){
            if(x[i]>x[i+1]){
		tmp=x[i];
		x[i]=x[i+1];
		x[i+1]=tmp;
		SWAP_COUNT++;
       	    }

            COMPARE_COUNT++;
	}
    }

    return;
}

void CombSort(int x[],int n)
{

    int i,j,tmp,gap,flg=1;
	
    gap = n;
    while( gap>1 || flg==1 ){
	gap = gap*10/13;
	if(gap<1) gap = 1;
	flg = 0;
	for( i=0 ; i+gap < n ; i++ ){
       	    if( x[i] > x[i+gap] ){
		tmp = x[i];
		x[i] = x[i+gap];
		x[i+gap] = tmp;
		flg = 1;
		SWAP_COUNT++;
            }
            
            COMPARE_COUNT++;
	}
    }
    
    return;
}

void main()
{
    
    int i;
    int data1[N];
    int data2[N];
    
    GenerateRandomData(N,data1,N);
    for(i=0;i<N;i++)data2[i]=data1[i];
		
    printf("Element nunber %d\n",N);
	
    printf("\n=Buble sort＝\n");
    COMPARE_COUNT = SWAP_COUNT = 0;
    BubbleSort(data1,N);
    printf("Comparison:%dTimes、Exchange:%dTimes\n",COMPARE_COUNT,SWAP_COUNT);
	
    printf("\n=Comb sort＝\n");
    COMPARE_COUNT = SWAP_COUNT = 0;
    CombSort(data2,N);
    printf("Comparison:%dTimes、Exchange:%dTimes\n",COMPARE_COUNT,SWAP_COUNT);
	
    return;
}
