#include<stdio.h>
#include<stdlib.h>
//Program to reverse a Circular Linked List
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
	printf("\n\nAfter reversing, our list is : ");
	while(ptr!=tail)
	{
		printf("%d -> ",ptr->data);
		ptr=ptr->link;
	}
	printf("%d -> ",tail->data);
}

void reverse()
{
	int m=2;
	char ch;
	node *ptr=head,*preptr=head,*nextptr=NULL;
	while(nextptr!=tail)
	{
		nextptr=ptr->link;
		ptr->link=preptr;
		preptr=ptr;
		ptr=nextptr;
	}
	tail->link=preptr;
	head->link=tail;
	tail=head;
	head=ptr;
	display(m);
	printf("\n\nDo you again want to reverse the list (y/n) : ");
	ch=getch();
	if(ch=='y'||ch=='Y')
	reverse();
	else
	{
		printf("\nNo more reversing.");
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
	printf("Enter the number of nodes you want in your list : ");
	scanf("%d",&n);
	create(n);
	display(m);
	printf("\n\nDo you want to reverse the list (y/n) : ");
	ch=getch();
	if(ch=='y'||ch=='Y')
	{
		reverse();
	}
	else
	printf("\nNo updation in the list.");
	return 0;
}
