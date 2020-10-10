#include<stdio.h>
#include<stdlib.h>
//creation of a Circular linked list 
typedef struct node
{
	int data;
	struct node *link;
}node;
node *head = NULL;
node *last = NULL;

node *add_at_end(node *last,int d)
{
	node *temp=malloc(sizeof(node));
	temp->data=d;
	temp->link=head;
	last->link=temp;
	last=temp;
	return temp;
}

void display()
{
	node *ptr=head;
	printf("Our Circular linked list is : ");
	while(ptr!=last)
	{
		printf("%d -> ",ptr->data);
		ptr=ptr->link;
	}
	printf("%d -> %d",last->data,head->data);
}

void create(int n)
{
	int d,i;
	head=malloc(sizeof(node));
	last=malloc(sizeof(node));
	printf("\nEnter data for node 1 : ");
	scanf("%d",&d);
	head->data=d;
	head->link=NULL;
	last=head;
	for(i=2;i<=n;i++)
	{
		printf("\nEnter data for node %d : ",i);
		scanf("%d",&d);
		last = add_at_end(last,d);
	}
}

int main()
{
	int n;
	printf("Enter the number of nodes you want in your list : ");
	scanf("%d",&n);
	create(n);
	display();
	return 0;
}
