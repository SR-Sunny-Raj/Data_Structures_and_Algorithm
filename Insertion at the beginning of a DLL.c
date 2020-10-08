#include<stdio.h>
#include<stdlib.h>
//Program to insert a new node at the begining of a Doubly Linked List
typedef struct node
{
	int data;
	struct node *prev;
	struct node *next;
}node;
node *head = NULL;

node *add_at_end(node *ptr,int d)
{
	node *temp = malloc(sizeof(node));
	temp->data=d;
	temp->next=NULL;
	temp->prev=ptr;
	ptr->next=temp;
	ptr=temp;
	return temp;
}

void create(int n)
{
	int d,i;
	head = malloc(sizeof(node));
	printf("\nEnter data for node 1 : ");
	scanf("%d",&d);
	head->data=d;
	head->prev=NULL;
	head->next=NULL;
	node *ptr = head;
	for(i=2;i<=n;i++)
	{
		printf("Enter data for node %d : ",i);
		scanf("%d",&d);
		ptr = add_at_end(ptr,d);
	}
}

void display(int m)
{
	node *ptr = head;
	if(m==1)
	printf("\nOur Doubly linked list is : ");
	else
	printf("\nAfter insertion our list is : ");
	while(ptr!=NULL)
	{
		printf("%d <-> ",ptr->data);
		ptr = ptr->next;
	}
	printf("NULL");
}

node *add_beg()
{
	int d;
	node *temp = malloc(sizeof(node));
	printf("\nEnter the data for the new node : ");
	scanf("%d",&d);
	temp->data=d;
	temp->prev=NULL;
	temp->next=head;
	head->prev=temp;
	head=temp;
	return temp;
}

int main()
{
	int n,m=1;
	char ch;
	printf("Enter the number of nodes you want in your list : ");
	scanf("%d",&n);
	create(n);
	display(m);
	printf("\nDo you want to insert a node at the begining of the list (y/n) : ");
	ch = getch();
	if(ch == 'y' || ch == 'Y')
	{
		head = add_beg();
		m=2;
		display(m);
	}
	else
	printf("\nThere is no updation in our Doubly linked list.");
	return 0;
}
