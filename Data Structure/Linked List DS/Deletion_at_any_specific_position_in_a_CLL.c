#include<stdio.h>
#include<stdlib.h>
//Program to delete node from any specific position of a Circular linked list
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

void del_any(n)
{
	int m=2,pos;
	char ch;
	node *ptr=head,*preptr=NULL;
	printf("\nEnter the position of the node you want to delete : ");
	scanf("%d",&pos);
	while(pos>n)
	{
		pos=pos-n;
		continue;
	}
	if(n==1)
	{
		free(head);
		printf("\nNow the list is empty.");
		exit(0);
	}
	else if(pos==1)
	{
		head=head->link;
		free(ptr);
		n--;
	}
	else if(pos==n)
	{
		while(ptr->link!=tail)
		{
			ptr=ptr->link;
		}
		ptr->link=head;
		free(tail);
		tail=ptr;
		ptr=NULL;
		n--;
	}
	else
	{
		while(pos!=1)
		{
			preptr=ptr;
			ptr=ptr->link;
			pos--;
		}
		preptr->link=ptr->link;
		free(ptr);
		ptr=NULL;
		preptr=NULL;
		n--;
	}
	display(m);
	printf("\nDo you again want to delete a node from the end (y/n) : ");
	ch = getch();
	if(ch=='y'||ch=='Y')
	{
		del_any(n);
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
	printf("\nDo you want to delete any node from the list (y/n) : ");
	ch = getch();
	if(ch=='y'||ch=='Y')
	{
		del_any(n);
	}
	else
	printf("\nNo updation in our list.");
	return 0;
}
