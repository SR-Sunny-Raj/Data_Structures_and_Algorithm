#include <stdio.h>
//Insertion Sort Algorithm
void Insertion_sort(int n,int arr[])
{
    int i,j,temp;
    for(i=1;i<n;i++)
    {
        temp=arr[i];
        j=i-1;
        while(j>=0 && temp<arr[j])
        {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=temp;
    }
}

int main()
{
    int n,i;
    printf("Enter the number of elements you want in your list : ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the elements in the list : ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    Insertion_sort(n,arr);
    printf("Our Sorted list is : ");
    for(i=0;i<n;i++)
    {
        printf("%d  ",arr[i]);
    }
    return 0;
}
