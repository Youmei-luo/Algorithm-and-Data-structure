//
// Generate random numbers
//
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 10

void GenerateRandomData(int range, int data[], int num)
{
    int i;
    srand(time(NULL));
    for(i=0; i<num; i++){
        data[i] = rand()%range + 1;
        printf("%d\t", data[i]);
    }
    printf("\n");
    return;
}

void main()
{
    int data[N];
    int range;
    
    printf("Number range : ");
    scanf("%d",&range);
    
    GenerateRandomData(range,data,N);
    return;
}
