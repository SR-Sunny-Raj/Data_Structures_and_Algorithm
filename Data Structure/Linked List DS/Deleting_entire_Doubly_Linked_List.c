#include<stdio.h>
#include<stdlib.h>
//Program to delete the entire Doubly linked list
typedef struct node
{
	int data;
	struct node *prev;
	struct node *next;
}node;
node *head = NULL;

node *add_at_end(node *ptr,int d)
{
	node *temp=malloc(sizeof(node));
	temp->data=d;
	temp->prev=ptr;
	temp->next=NULL;
	ptr->next=temp;
	ptr=temp;
	return temp;
}

void display()
{
	node *ptr=head;
	printf("\nOur Doubly linked list is : ");
	while(ptr!=NULL)
	{
		printf("%d <-> ",ptr->data);
		ptr=ptr->next;
	}
	printf("NULL");
}

void del_all()
{
	while(head->next!=NULL)
	{
		head=head->next;
		free(head->prev);
	}
	free(head);
	head=NULL;
}

void create(int n)
{
	int d,i;
	head=malloc(sizeof(node));
	printf("\nEnter data for node 1 : ");
	scanf("%d",&d);
	head->data=d;
	head->prev=NULL;
	head->next=NULL;
	node *ptr=head;
	for(i=2;i<=n;i++)
	{
		printf("\nEnter data for node %d : ",i);
		scanf("%d",&d);
		ptr = add_at_end(ptr,d);
	}
}

int main()
{
	int n;
	char ch;
	printf("Enter the number of nodes you want in your Doubly linked list : ");
	scanf("%d",&n);
	create(n);
	display();
	printf("\n\nDo you want to delete the entire list? (y/n) : ");
	ch = getch();
	if(ch=='y'||ch=='Y')
	{
		del_all();
		printf("\nList deleted successfully.");
	}
	else
	printf("\nThe list was not deleted.");
	return 0;
}
