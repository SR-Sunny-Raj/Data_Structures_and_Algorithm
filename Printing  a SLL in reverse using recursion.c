#include<stdio.h>
#include<stdlib.h>
//Printing elements of a Single Linked List using recursion in reversed order
typedef struct node
{
	int data;
	struct node *link;
}node;
node *head = NULL;

void print(node *p)
{
		if(p->link==NULL)
		{
		return;
		}
		p=p->link;
		print(p);
		printf("%d -> ",p->data);
}

node *add_at_end(node *ptr,int d)
{
	node *temp = malloc(sizeof(node));
	temp->data=d;
	temp->link=NULL;
	ptr->link=temp;
	ptr=temp;
	return temp;
}


void create(int n)
{
	int d,i;
	head = malloc(sizeof(node));
	printf("\nEnter data for node 1 : ");
	scanf("%d",&d);
	head->data=d;
	head->link=NULL;
	node *ptr = head;
	for(i=2;i<=n;i++)
	{
		printf("\nEnter data for node %d : ",i);
		scanf("%d",&d);
		ptr = add_at_end(ptr,d);
	}
}

void display()
{
	node *ptr = head;
	printf("\nOur linked list is : ");
	while(ptr!=NULL)
	{
		printf("%d -> ",ptr->data);
		ptr = ptr->link;
	}
	printf("NULL");
}

int main()
{
	int n;
	char ch;
	printf("Enter the number of nodes you want in your list : ");
	scanf("%d",&n);
	create(n);
	display();
	printf("\nDo you want to print the list in reverse order (y/n) : \n");
	ch = getch();
	if(ch == 'y' || ch == 'Y')
	{
		print(head);
		printf("%d",head->data);
	}
	else
	printf("\nThere is no updation in our linked list : ");
	return 0;
}
