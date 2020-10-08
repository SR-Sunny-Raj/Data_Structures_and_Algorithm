#include<stdio.h>
#include<stdlib.h>
//Program to insert a node at the end of a Doubly Linked List
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
		printf("\nEnter data for node %d : ",i);
		scanf("%d",&d);
		ptr = add_at_end(ptr,d);
	}
}

void display(int m)
{
	node *ptr=head;
	if(m==1)
	printf("\nOur doubly linked list is : ");
	else
	printf("After insertion our list is : ");
	while(ptr!=NULL)
	{
		printf("%d <-> ",ptr->data);
		ptr = ptr->next;
	}
	printf("NULL");
}

int main()
{
	int n,d,m=1;
	char ch;
	printf("Enter the number of nodes you want in your doubly linked list : ");
	scanf("%d",&n);
	create(n);
	display(m);
	printf("\nDo you want to insert a node at the end of the list (y/n) : ");
	ch = getch();
	if(ch=='y'||ch=='Y')
	{
		node *ptr=head;
		while(ptr->next!=NULL)
		{
			ptr=ptr->next;
		}
		printf("\nEnter data you want to insert : ");
		scanf("%d",&d);
		ptr=add_at_end(ptr,d);
		m=2;
		display(m);
	}
	else
	printf("\nThere is no updation in our list.");
	return 0;
}
