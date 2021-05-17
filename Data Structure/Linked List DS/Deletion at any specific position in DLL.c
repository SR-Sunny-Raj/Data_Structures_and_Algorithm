#include<stdio.h>
#include<stdlib.h>
//Program to delete any specific node from a Doubly linked list
typedef struct node
{
	int data;
	struct node *prev;
	struct node *next;
}node;
node *head = NULL;
node *last = NULL;

node *add_at_end(node *last,int d)
{
	node *temp=malloc(sizeof(node));
	temp->data=d;
	temp->prev=last;
	temp->next=NULL;
	last->next=temp;
	last=temp;
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
		ptr=ptr->next;
	}
	printf("NULL");
}

void del_any(int n)
{
	int pos,m=2;
	char ch;
	node *ptr=head,*ptrlast=NULL;
	printf("\nEnter the position of the node you want to delete : ");
	scanf("%d",&pos);
	if(pos==1)
	{
		if(ptr->next==NULL)
		{
			free(ptr);
			printf("\nNo more elements to delete.");
			exit(0);	
		}
		else
		{
			head=head->next;
			head->prev=NULL;
			free(ptr);
			ptr=NULL;
			n--;
			display(m);
		}
	}
	else if(pos<1||pos>n)
	{
		printf("\nInvalid Position!!\nPlease enter any valid position");
		del_any(n);
	}
	else if(pos==n)
	{
		ptrlast=last;
		last=last->prev;
		last->next=NULL;
		free(ptrlast);
		ptrlast=NULL;
		n--;
		display(m);
	}
	else
	{
		while(pos!=1)
		{
			ptr=ptr->next;
			pos--;
		}
		ptr->prev->next=ptr->next;
		ptr->next->prev=ptr->prev;
		free(ptr);
		n--;
		display(m);
	}
	printf("\nDo you want to delete some more nodes from the list (y/n) : ");
	ch = getch();
	if(ch=='y'||ch=='Y')
	{
		del_any(n);
	}
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
	printf("\nDo you want to delete a node from the list (y/n) : ");
	ch = getch();
	if(ch=='y'||ch=='Y')
	{
		del_any(n);
	}
	else
	printf("\nThere is no updation in our list. ");
	return 0;
}
