#include<stdio.h>
#include<stdlib.h>
//Creation of a Doubly Linked List
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

void display()
{
	node *ptr=head;
	printf("\nOur doubly linked list is : ");
	while(ptr!=NULL)
	{
		printf("%d <-> ",ptr->data);
		ptr=ptr->next;
	}
	printf("NULL");
}

void create(int n)
{
	int d,i;
	head = malloc(sizeof(node));
	printf("\nEnter the data for node 1 : ");
	scanf("%d",&d);
	head->data=d;
	head->prev=NULL;
	head->next=NULL;
	node *ptr=head;
	for(i=2;i<=n;i++)
	{
		printf("\nEnter the data for node %d : ",i);
		scanf("%d",&d);
		ptr = add_at_end(ptr,d);
	}
}

int main()
{
	int n;
	printf("Enetr the number of nodes you want in your list : ");
	scanf("%d",&n);
	create(n);
	display();
}
