#include<stdio.h>
#include<stdlib.h>
//program to reverse the Doubly linked list
typedef struct node
{
	int data;
	struct node *prev;
	struct node *next;
}node;
node *head = NULL;
node *tail = NULL;

node *add_at_end(node *last , int d)
{
	node *temp=malloc(sizeof(node));
	temp->data=d;
	temp->prev=tail;
	temp->next=NULL;
	tail->next=temp;
	tail=temp;
	return temp;
}

node *display(int m)
{
	node *ptr=head,*ptrl=tail;
	if(m==1)
	{
		printf("\nOur Doubly linked list is : ");
		while(ptr!=NULL)
		{
			printf("%d <-> ",ptr->data);
			ptr=ptr->next;
		}
		printf("NULL");
	}
	else
	{
		printf("\nThe reverse of our list is : ");
		while(tail!=NULL)
		{
			printf("%d <-> ",tail->data);
			tail=tail->prev;
		}
		printf("NULL");
		tail=head;
		head=ptrl;
		ptrl=NULL;
		return head;
	}
}

void create(n)
{
	int d,i;
	head=malloc(sizeof(node));
	tail=malloc(sizeof(node));
	printf("Enter data for node 1 : ");
	scanf("%d",&d);
	head->data=d;
	head->prev=NULL;
	head->next=NULL;
	tail=head;
	for(i=2;i<=n;i++)
	{
		printf("Enter data for node %d : ",i);
		scanf("%d",&d);
		tail = add_at_end(tail,d);
	}
}

int main()
{
	int n,m=1;
	char ch;
	printf("Enter the number of nodes you want in your Doubly Linked List : ");
	scanf("%d",&n);
	create(n);
	display(m);
	printf("\nDo you want to reverse the list? (y/n) : ");
	ch = getch();
	if(ch=='y'||ch=='Y')
	{
		m=2;
		head = display(m);
	}
	else
	printf("\nNo operation performed on the list.");
	return 0;
}
