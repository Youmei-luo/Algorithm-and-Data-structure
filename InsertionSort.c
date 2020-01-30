#include <stdio.h>

int COMPARE_COUNT;
int MOVE_COUNT;

void InsertionSort(int x[], int n)
{
    int i, j, tmp;
    
    for(j=1; j < n; j++){
        tmp = x[j];
        MOVE_COUNT++;
        
        for(i=j-1 ;i>=0; i--){
            COMPARE_COUNT++;
            if( x[i] > tmp ) { x[i+1] = x[i]; MOVE_COUNT++; }
            else break;
	}
        x[i+1] = tmp; MOVE_COUNT++;
    }
    return;
}

void main()
{
    
    int i;
    int data[8] = {3,2,8,5,7,1,6,4};
    
    printf("\nBefore sorting\n");
    for( i = 0; i < 8; i++) {
        printf("%d\t",data[i]);
    }
    printf("\n");
	
    printf("\n=Basic insertion method = \n");
    COMPARE_COUNT = MOVE_COUNT = 0;
    InsertionSort(data,8);
    printf("Comparison %d times, Replacement %d times\n", COMPARE_COUNT,MOVE_COUNT);
	
    printf("\nAfter replacement\n");
    for( i = 0; i < 8; i++) printf("%d\t",data[i]);
    printf("\n");
	
    return;
}
