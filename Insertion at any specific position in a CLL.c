#include<stdio.h>
#include<stdlib.h>
//Program to insert a node at any specific position in a Circular Linked List
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

void insert_at_any(int n)
{
	int pos,d,m=2;
	char ch;
	node *ptr=head;
	node *temp=malloc(sizeof(node));
	printf("\nEnter the position at which you want to insert the node : ");
	scanf("%d",&pos);
	printf("\nEnter the data you want to insert : ");
	scanf("%d",&d);
	temp->data=d;
	temp->link=NULL;
	if(pos==1)
	{
		temp->link=head;
		head=temp;
		n++;
	}
	else if(pos==n+1)
	{
		temp->link=tail->link;
		tail->link=temp;
		tail=temp;
		n++;
	}
	else
	{
		while(pos!=2)
		{
			ptr=ptr->link;
			pos--;
		}
		temp->link=ptr->link;
		ptr->link=temp;
		ptr=NULL;
		n++;
	}
	display(m);
	printf("\nDo you want to add some more nodes (y/n) : ");
	ch = getch();
	if(ch=='y'||ch=='Y')
	{
		insert_at_any(n);
	}
	else
	{
		printf("\nNo more updation in our list.");
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
	int n,m=1;
	char ch;
	printf("Enter the number of nodes you want in your Circular linked list : ");
	scanf("%d",&n);
	create(n);
	display(m);
	printf("\nDo you want to insert a node in the list (y/n) : ");
	ch=getch();
	if(ch=='y'||ch=='Y')
	{
		insert_at_any(n);
	}
	else
	printf("There is no updation in our list.");
	return 0;
}
