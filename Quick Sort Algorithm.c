#include <stdio.h>
//Quick Sort Algorithm
int Partition(int arr[],int LB,int UB)
{
    int start=LB,end=UB,key=arr[LB],temp;
    while(start<end)
    {
        while(arr[start]<=key)
        {
            start++;
        }
        while(arr[end]>key)
        {
            end--;
        }
        if(start<end)
        {
            temp=arr[end];
            arr[end]=arr[start];
            arr[start]=temp;
        }
    }
    temp=arr[end];
    arr[end]=arr[LB];
    arr[LB]=temp;
    return end;
}

void Quick_sort(int n,int arr[],int LB,int UB)
{
    if(LB<UB)
    {
    int pos=Partition(arr,LB,UB);
    Quick_sort(n,arr,LB,pos-1);
    Quick_sort(n,arr,pos+1,UB);
    }
}

int main()
{
    int n,i;
    printf("Enter the number of elements you want in your list : ");
    scanf("%d",&n);
    int arr[n],LB=0,UB=n;
    printf("Enter the elements in the list : ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    Quick_sort(n,arr,LB,UB);
    printf("Our sorted list is : ");
    for(i=0;i<n;i++)
    {
        printf("%d  ",arr[i]);
    }
    return 0;
}
