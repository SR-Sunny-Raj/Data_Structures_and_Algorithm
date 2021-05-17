#include <stdio.h>
//Selection Sort Algorithm
void Selection_sort(int n,int arr[])
{
    int i,j,min,temp;
    for(i=0;i<n-1;i++)
    {
        min=i;
        for(j=i+1;j<n;j++)
        {
            if(arr[min]>arr[j])
            {
                min=j;
            }
        }
        if(min != i)
        {
            temp=arr[i];
            arr[i]=arr[min];
            arr[min]=temp;                                            
        }
    }
}

int main()
{
    int n,i;
    printf("Enter the number of elements you want in your list : ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the elements in your list : ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    Selection_sort(n,arr);
    printf("Our sorted list is : ");
    for(i=0;i<n;i++)
    {
        printf("%d  ",arr[i]);
    }
    return 0;
}
