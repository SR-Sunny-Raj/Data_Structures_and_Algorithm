#include<stdio.h>
#include<stdlib.h>
//Deletion at the beginning of a Doubly linked list
typedef struct node
{
	int data;
	struct node *prev;
	struct node *next;
}node;
node *head = NULL;

node *add_at_end(node *ptr, int d)
{
	node *temp = malloc(sizeof(node));
	temp->data=d;
	temp->prev=ptr;
	temp->next=NULL;
	ptr->next=temp;
	return temp;
}

void display(int m)
{
	node *ptr = head;
	if(m==1)
	printf("\nOur Doubly linked list is : ");
	else
	printf("\nAfter deletion our list is : ");
	while(ptr!=NULL)
	{
		printf("%d <-> ",ptr->data);
		ptr = ptr->next;
	}
	printf("NULL");
}

void del()
{
	int m;
	char ch;
	node *ptr=head;
	if(head->next==NULL)
	{
		free(head);
		printf("\nNo more elements to delete.");
		exit(0);
	}
	else
	{
	head=head->next;
	head->prev=NULL;
	free(ptr);
	ptr=NULL;
	m=2;
	display(m);
	printf("\nDo you want to delete one more node from the begining of the list (y/n) : ");
	ch = getch();
	if(ch=='y'||ch=='Y')
	del();
	else
	return;
	}
	
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

int main()
{
	int n,m=1;
	char ch;
	printf("Enter the number of nodes you want in your Doubly linked list : ");
	scanf("%d",&n);
	create(n);
	display(m);
	printf("\nDo you want to delete a node at the begining (y/n) : ");
	ch = getch();
	if(ch=='y'||ch=='Y')
	del();
	else
	printf("\nThere is no updation in our list.");
	return 0;
}
