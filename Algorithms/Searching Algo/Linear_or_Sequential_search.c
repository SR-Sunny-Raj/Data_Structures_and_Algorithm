#include <stdio.h>
#include <stdlib.h>
//Linear or Sequential search
int main()
{
	int flag=0,key,n,i;
	printf("Enter number of elements you want in your list : ");
	scanf("%d",&n);
	int arr[n];
	printf("\nEnter the elements in the list : ");
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	printf("\nEnter the data you want to search in the list : ");
	scanf("%d",&key);
	for(i=0;i<n;i++)
	{
		if(arr[i]==key)
		{
			printf("\nData found at index %d",i);
			flag=1;
			break;
		}
	}
	if(flag==0)
	{
		printf("\nData not found in the list!!");
	}
	return 0;
}
