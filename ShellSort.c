#include <stdio.h>

int COMPARE_COUNT;
int MOVE_COUNT;


void ShellSort(int x[], int n)
{
    int i, j, k, tmp, gap;
    
    gap = n / 2;
    while(gap > 0 ) 
    {
        for (k = 0; k < gap; k++)
        {
            for (j = k + gap; j < n; j = j + gap)
            {
                tmp = x[j]; MOVE_COUNT++;
                for (i = j - gap; i >= 0; i = i - gap)
                {
                    COMPARE_COUNT++;
                    if ( x[i] > tmp ) { x[i+gap] = x[i]; MOVE_COUNT++; }
                    else break;
                }
                x[i + gap] = tmp;
                MOVE_COUNT++;
            }
        }
        gap = gap / 2;
    }
    return;
}

void BestGapShellSort(int x[], int n)
{
    int i, j, k, tmp, gap;
    
    gap = 1;
    while ( n > gap ) gap = 3 * gap + 1;
    gap = (gap - 1) /3;
    
    while(gap > 0 ) 
    {
    	for (k = 0; k < gap; k++)
    	{
            for (j = k + gap; j < n; j = j + gap)
            {
           	tmp = x[j]; MOVE_COUNT++;
            	for (i = j - gap; i >= 0; i = i - gap)
            	{
                    COMPARE_COUNT++;
                    if ( x[i] > tmp ) { x[i+gap] = x[i]; MOVE_COUNT++; }
                    else break;
            	}
                x[i + gap] = tmp;
                MOVE_COUNT++;
            }
        }
        gap = (gap - 1) / 3;
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
	
    //printf("\n=Shell sort = \n");
    //COMPARE_COUNT = MOVE_COUNT = 0;
    //ShellSort(data,8);
    printf("\n=Best Shell sort = \n");
    COMPARE_COUNT = MOVE_COUNT = 0;
    BestGapShellSort(data,8);
    printf("Comparison %d times,Replacement %d times\n", COMPARE_COUNT,MOVE_COUNT);
	
    printf("\nAfter replacement\n");
    for( i = 0; i < 8; i++) printf("%d\t",data[i]);
    printf("\n");
	
    return;
}
