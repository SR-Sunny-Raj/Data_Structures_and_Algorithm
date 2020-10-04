#include<stdio.h>
#include<stdlib.h>
//Program to insert data at the end of a singly linked list
typedef struct node
{
	int data;
	struct node *link;
}node;
node *head = NULL;
node *ptr = NULL;

node* add_node(node *ptr,int d)
{
	node *temp = malloc(sizeof(node));
	temp->data = d;
	temp->link = NULL;
	ptr->link = temp;
	ptr = temp;
	return temp;
}
void add_at_end(int d)
{
	node *ptr = head;
	node *temp = malloc(sizeof(node));
	temp->data = d;
	temp->link = NULL;
	while(ptr->link != NULL)
	{
		ptr = ptr->link;
	}
	ptr->link = temp;
}
void create_list(int n)
{
	int d,i;
	head = malloc(sizeof(node));
	printf("\nEnter the data for node 1 : ");
	scanf("%d",&d);
	head->data = d;
	head->link = NULL;
	node *ptr = head;
	for(i=2;i<=n;i++)
	{
		printf("\nEnter the data for node %d : ",i);
		scanf("%d",&d);
		ptr = add_node(ptr,d);
	}
}
void display(int m)
{
	node *ptr = head;
	if(m==1)
	{
	printf("\nOur linked list is : ");
	}
	else
	{
	printf("\nOur Updated linked list is : ");	
	}
	while(ptr!=NULL)
	{
		printf("%d->",ptr->data);
		ptr = ptr->link;
	}
	printf("NULL");	
}

int main()
{
	int n,m=1,d;
	char ch;
	printf("Enter the number of nodes you want in your linked list : ");
	scanf("%d",&n);
	create_list(n);
	display(m);
	printf("\nDo you want to insert a new node at the end(Y/N) : ");
	ch = getch();
	if(ch == 'y' || ch == 'Y')
	{
		printf("\nEnter the data you want to insert : ");
		scanf("%d",&d);
		add_at_end(d);
		m = 2;
	    display(m);
	}
	else
	{
		printf("\nTheir is no updation in our linked list");
	}
	return 0;
}
