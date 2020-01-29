//
// Linear Search
//
#include <stdio.h>
#define N 8  // Data number

int LinearSearch(int x[], int n, int y)
{
    int i = 0;
    x[n] = y;  // Add sentinel 
    while(i < n) {
        if ( x[i] == y ) return i;
	else i++;
    }
    return -1;
}

int SentinelSearch(int x[], int n, int y)
{
    int i = 0;
    x[n] = y;  // Add sentinel 
    while(1) {
        if ( x[i] == y ) break;
	else i++;
    }
    if ( i < n ) return i;
    return -1;
}

void main()
{
    int data[N]={11,22,33,44,55,66,77,88};
    int target, rc;

    printf("Input target data : ");
    scanf("%d",&target);

    //rc = LinearSearch(data, N, target);
    rc = SentinelSearch(data, N, target);
    
    if (rc == -1) printf("Not found\n");
    else printf("Element number is %d \n", rc);

    return;
}
