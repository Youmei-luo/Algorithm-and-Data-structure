#include <stdio.h>
#define N 25  // Data count
 
int COUNT;
 
int BinarySearch(int x[],int n,int y)
{
    int min,mid,max;
    min=0;
    max=n-1;
    while(min<=max){
        mid=(min+max)/2;
        COUNT++;
        if(x[mid]<y) min=mid+1;
        else if(x[mid]>y) max=mid-1;
        else return mid;
    }
    return -1;
}
 
int LinearSearch(int x[],int n,int y)
{
    int i=0;
    while(i<n){
        COUNT++;
        if(x[i]==y) return i;
        else i++;
    }
    return -1;
}
 
void main()
{
    //int data[N]={11,22,33,44,55,66,77,88};
    int data[N]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,
         47,53,59,61,67,71,73,79,83,89,97};
    int target,rc;
 
    printf("Input target data : ");
    scanf("%d",&target);
 
    printf("\nLinearSearch\n");
    COUNT=0;
    rc = LinearSearch(data,N,target);
    if(rc==-1) printf("Not found\n");
    else printf("The %dth prime number\n",rc + 1);
    printf("Search count %d\n",COUNT);
 
    printf("\nBinarySearch\n");
    COUNT=0;
    rc = BinarySearch(data,N,target);
    if(rc==-1) printf("Not found\n");
    else printf("The %dth prime number\n",rc + 1);
    printf("Search count %d\n",COUNT);
 
    return;
}
