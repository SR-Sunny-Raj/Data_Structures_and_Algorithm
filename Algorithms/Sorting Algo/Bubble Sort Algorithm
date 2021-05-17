#include <stdio.h>
//Bubble Sort Algorithm
void Bubblesort(int n,int arr[])
{
	int a,b,k,flag,temp;
	for(a=0;a<n-1;a++)
	{
		flag=0;
		for(b=0;b<(n-1-a);b++)
		{
			if(arr[b]>arr[b+1])
			{
				temp=arr[b];
				arr[b]=arr[b+1];
				arr[b+1]=temp;
				flag=1;
			}
		}
		if(flag==0)
		{
		printf("\nOur list is sorted and the list is :-\n");
		for(k=0;k<n;k++)
		{
			printf("%d\t",arr[k]);
		}
		break;
		}
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
	Bubblesort(n,arr);
	return 0;
}
