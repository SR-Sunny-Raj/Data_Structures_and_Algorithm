#include<stdio.h>
#include<stdlib.h>
//Program to delete any specific node of a single linked list
typedef struct node
{
	int data;
	struct node *link;
}node;
node *head = NULL;

node *add_at_end(node *ptr,int d)
{
	node *temp = malloc(sizeof(node));
	temp->data = d;
	temp->link=NULL;
	ptr->link=temp;
	ptr=temp;
	return temp;
}

void display(int m)
{
	node *ptr=head;
	if(m==1)
	printf("\nOur linked list is : ");
	else
	printf("\nOur updated linked list is : ");
	while(ptr!=NULL)
	{
	printf("%d -> ",ptr->data);
	ptr=ptr->link;	
	}
	printf("NULL");
}

void create_list(int n)
{
	int d,i;
	head = malloc(sizeof(node));
	printf("\nEnter the data for node 1 : ");
	scanf("%d",&d);
	head->data=d;
	head->link=NULL;
	node *ptr = head;
	for(i=2;i<=n;i++)
	{
		printf("\nEnter the data for node %d : ",i);
		scanf("%d",&d);
		ptr = add_at_end(ptr,d);
	}
}

node *del_pos(int pos)
{
	node *prev=head;
	node *current=head;
	if(pos==1)
	{
		prev=current->link;
		free(current);
		current=NULL;
		head=prev;
	}
	else
	{
	while(pos!=1)
	{
		prev=current;
		current=current->link;
		pos--;
	}
	prev->link=current->link;
	free(current);
	current=NULL;
	prev=head;
	head=prev;
	}
	return head;
}

int main()
{
	int n,m=1,pos;
	char ch;
	printf("Enter the number of nodes you want in your list : ");
	scanf("%d",&n);
	create_list(n);
	display(m);
	printf("\nDo you want to delete any node of the list (y/n) : ");
	ch = getch();
	if(ch == 'y' || ch == 'Y')
	{
		printf("\nEnetr the position of the node you want to delete : ");
		scanf("%d",&pos);
		if(pos<=0 || pos>n)
		{
		printf("\nInvalid Position!");
		exit(0);
	    }
		else
		{
		head = del_pos(pos);
		m=2;
		display(m);
	    }
	}
	else
	printf("\nTheir is no updation in our list.");
	return 0;
}
