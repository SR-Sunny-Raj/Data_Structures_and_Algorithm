#include <stdio.h>
//Merge Sort Algorithm
void Merge(int n,int arr[],int LB,int mid,int UB)
{
    int i=LB,j=mid+1,k=LB,brr[k];
    while(i<=mid && j<=UB)
    {
        if(arr[i]<=arr[j])
        {
            brr[k]=arr[i];
            i++;
        }
        else
        {
            brr[k]=arr[j];
            j++;
        }
        k++;
    }
    if(i>mid)
    {
        while(j<=UB)
        {
            brr[k]=arr[j];
            j++;
            k++;
        }
    }
    else if(j>UB)
    {
        while(i<=mid)
        {
            brr[k]=arr[i];
            i++;
            k++;
        }
    }
    for(k=LB;k<=UB;k++)
    {
        arr[k]=brr[k];
    }
}

void Merge_sort(int n,int arr[],int LB,int UB)
{
    if(LB<UB)
    {
        int mid=(LB+UB)/2;
        Merge_sort(n,arr,LB,mid);
        Merge_sort(n,arr,mid+1,UB);
        Merge(n,arr,LB,mid,UB);
    }
}

int main()
{
    int n,i;
    printf("Enter the number of elements you want in your list : ");
    scanf("%d",&n);
    int arr[n],LB=0,UB=n-1;
    printf("Enter the elements in the list : ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    Merge_sort(n,arr,LB,UB);
    printf("Our sorted list is : ");
    for(i=0;i<n;i++)
    {
        printf("%d  ",arr[i]);
    }
    return 0;
}
