#include<stdio.h>
//Interpolation Search
int main()
{
	int n,i,key,flag=0;
	printf("Enter the number of elements you want in your list : ");
	scanf("%d",&n);
	int arr[n];
	printf("Enter the elements in the list : ");
	for(i=0;i<n;i++)
	{
	scanf("%d",&arr[i]);
	}
	printf("Enter the data you want to search in the list : ");
	scanf("%d",&key);
	flag = Interpolation_Search(arr,n,key,flag);
	if(flag==0)
	{
		printf("Data not found in the list!!");
	}
	return 0;
}
int Interpolation_Search(int arr[],int n,int key,int flag)
{
	int pos,LB=0,UB=(n-1);
	while(LB<=UB && key>=arr[LB] && key<=arr[UB])
	{
	pos=LB+(UB-LB)/(arr[UB]-arr[LB])*(key-arr[LB]);
	if(arr[pos]==key)
	{
		printf("Data found at index %d",pos);
		flag=1;
		break;
	}
	else if(arr[pos]<key)
	{
		LB=pos+1;
	}
	else if(arr[pos]>key)
	{
		UB=pos-1;
	}
	}
	return flag;
}
