#include<stdio.h>
#include<stdlib.h>
//Program to insert a node at any specific position in a doubly linked list
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
	temp->next=NULL;
	temp->prev=ptr;
	ptr->next=temp;
	ptr=temp;
	return temp;
}

void display(int m)
{
	node *ptr=head;
	if(m==1)
	printf("\nOur Doubly linked list is : ");
	else
	printf("\nAfter insertion our list is : ");
	while(ptr!=NULL)
	{
		printf("%d <-> ",ptr->data);
		ptr=ptr->next;
	}
	printf("NULL");
}

void insert_at_any(int n)
{
	int pos,d,m;
	char ch;
	node *ptr=head;
	node *curr=head->next;
	node *temp=malloc(sizeof(node));
	printf("\nEnter the data you want to insert : ");
	scanf("%d",&d);
	printf("\nEnter the position at which you want to insert the node : ");
	scanf("%d",&pos);
	if(pos<=0||pos>n+1)
	{
		printf("\nInvalid Position!!");
		printf("\nPlease enter a valid position");
		insert_at_any(n);
	}
	else if(pos==1)
	{
		temp->data=d;
		temp->prev=NULL;
		temp->next=ptr;
		ptr->prev=temp;
		ptr=temp;
		head=temp;
		n++;
	}
	else if(pos==n+1)
	{
		while(pos!=2)
		{
			ptr=ptr->next;
			pos--;
		}
		temp->data=d;
		temp->next=NULL;
		ptr->next=temp;
		temp->prev=ptr;
		n++;
	}
	else
	{
		while(pos!=2)
		{
			ptr=ptr->next;
			curr=curr->next;
			pos--;
		}
		temp->data=d;
		temp->prev=ptr;
		ptr->next=temp;
		temp->next=curr;
		curr->prev=temp;
		n++;
	}
	m=2;
	display(m);
	printf("\nDo you still want to insert some more node (y/n) : ");
	ch = getch();
	if(ch=='y'||ch=='Y')
	insert_at_any(n);
	else
	return;
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
	node *ptr=head;
	for(i=2;i<=n;i++)
	{
		printf("\nEnter data for node %d : ",i);
		scanf("%d",&d);
		ptr=add_at_end(ptr,d);
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
	printf("\nDo you want to insert a node (y/n) : ");
	ch = getch();
	if(ch=='y'||ch=='Y')
	{
		insert_at_any(n);
	}
	else
	printf("There is no updation in our list.");
	return 0;	
}
