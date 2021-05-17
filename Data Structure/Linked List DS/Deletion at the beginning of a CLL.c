#include<stdio.h>
#include<stdlib.h>
//Program to delete node from the beginning of a Circular linked list
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
	printf("\nAfter deletion our list is : ");
	while(ptr!=tail)
	{
		printf("%d -> ",ptr->data);
		ptr=ptr->link;
	}
	printf("%d -> ",ptr->data);
}

void del_beg()
{
	int m=2;
	char ch;
	if(head==tail)
	{
		free(head);
		printf("\nNo more nodes left in the list.");
		exit(0);
	}
	else
	{
	node *ptr=head->link;
	free(head);
	head=ptr;
	ptr=NULL;
	display(m);
	}
	printf("\nDo you again want to delete a node from the beginning (y/n) : ");
	ch = getch();
	if(ch=='y'||ch=='Y')
	{
		del_beg();
	}
	else
	{
		printf("\nYou successfully deleted some nodes.");
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
	printf("\nDo you want to delete the first node from the list (y/n) : ");
	ch = getch();
	if(ch=='y'||ch=='Y')
	{
		del_beg();
	}
	else
	printf("\nNo updation in our list.");
	return 0;
}
