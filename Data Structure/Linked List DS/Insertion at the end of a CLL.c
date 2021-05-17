#include<stdio.h>
#include<stdlib.h>
//Program to insert node at the end of a Circular linked list
typedef struct node
{
	int data;
	struct node *link;
}node;
node *head=NULL;
node *tail=NULL;

node *add_at_end(node *tail,int d)
{
	node *temp=malloc(sizeof(node));
	temp->data=d;
	temp->link=head;
	tail->link=temp;
	tail=temp;
	return temp;
}

void display(int m)
{
	node *ptr=head;
	if(m==1)
	printf("\nOur Circular linked list is : ");
	else
	printf("\nAfter insertion our list is : ");
	while(ptr!=tail)
	{
		printf("%d -> ",ptr->data);
		ptr=ptr->link;
	}
	printf("%d -> %d",ptr->data,head->data);
}

void add()
{
	char ch;
	int d,m=2;
	printf("\nDo you still want to add some more data at the end of the list (y/n) : ");
	ch = getch();
	if(ch=='y'||ch=='Y')
	{
		printf("\nEnter data you want to insert : ");
		scanf("%d",&d);
		tail=add_at_end(tail,d);
		display(m);
		add();
	}
	else
	{
	printf("\nNo insertion at the end.");
	exit(0);
	}
}

void create(int n)
{
	int d,i;
	head=malloc(sizeof(node));
	tail=malloc(sizeof(node));
	printf("\nEnter data for node 1 : ");
	scanf("%d",&d);
	head->data=d;
	head->link=NULL;
	tail=head;
	for(i=2;i<=n;i++)
	{
		printf("\nEnter data for node %d : ",i);
		scanf("%d",&d);
		tail=add_at_end(tail,d);
	}
}

int main()
{
	int n,m=1,d;
	char ch;
	printf("Enter the number of nodes you want in your Circular linked list : ");
	scanf("%d",&n);
	create(n);
	display(m);
	printf("\nDo you want to insert a node at the end of the list (y/n) : ");
	ch = getch();
	if(ch=='y'||ch=='Y')
	{
		printf("\nEnter data you want to insert : ");
		scanf("%d",&d);
		tail=add_at_end(tail,d);
		m=2;
		display(m);
		add();
	}
	else
	printf("\nNo updation in our list.");
	return 0;
}
