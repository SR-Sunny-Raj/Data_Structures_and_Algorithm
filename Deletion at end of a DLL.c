#include<stdio.h>
#include<stdlib.h>
//Program to delete node at the end of a Doubly linked list
typedef struct node
{
	int data;
	struct node *prev;
	struct node *next;
}node;
node *head = NULL;
node *last = NULL;

node *add_at_end(node *last , int d)
{
	node *temp = malloc(sizeof(node));
	temp->data=d;
	temp->prev=last;
	temp->next=NULL;
	last->next=temp;
	last=temp;
	return temp;
}

void display(int m)
{
	node *ptr=head;
	if(m==1)
	printf("\nOur Doubly linked list is : ");
	else
	printf("\nAfter deletion our list is : ");
	while(ptr!=NULL)
	{
		printf("%d <-> ",ptr->data);
		ptr=ptr->next;
	}
	printf("NULL");
}

void del_last()
{
	int m=2;
	char ch;
	if(last->prev==NULL)
	{
		free(last);
		printf("\nNo more elements to delete.");
		exit(0);
	}
	else
	{
	node *ptr=last->prev;
	ptr->next=NULL;
	free(last);
	last=ptr;
	ptr=NULL;
	display(m);
	printf("\n\nDo you want to delete some more node from last of the list (y/n) : ");
	ch = getch();
	if(ch=='y'||ch=='Y')
	del_last();
	else
	return;
	}
}

void create(int n)
{
	int d,i;
	head = malloc(sizeof(node));
	last = malloc(sizeof(node));
	printf("\nEnter data for node 1 : ");
	scanf("%d",&d);
	head->data=d;
	head->prev=NULL;
	head->next=NULL;
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
	int n,m=1;
	char ch;
	printf("Enter the number of nodes you want in your Doubly linked list : ");
	scanf("%d",&n);
	create(n);
	display(m);
	printf("\nDo you want to delete the last node (y/n) : ");
	ch = getch();
	if(ch=='y'||ch=='Y')
	del_last();
	else
	printf("\nThere is no updation in our list.");
	return 0;
}
