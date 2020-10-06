#include<stdio.h>
#include<stdlib.h>
//Program to delete the first node of a single linked list
typedef struct node
{
	int data;
	struct node* link;
}node;
node* head = NULL;

node* add_at_end(node* ptr,int d)
{
	node* temp = ptr;
	temp = malloc(sizeof(node));
	temp->data=d;
	temp->link=NULL;
	ptr->link = temp;
	ptr=temp;
	return temp;
}

node* del_node()
{
	node *ptr = head;
	head = head->link;
	free(ptr);
	ptr = NULL;
	return head;
}

void create_list(int n)
{
	int d,i;
	head = malloc(sizeof(node));
	printf("\nEnter the data for node 1 : ");
	scanf("%d",&d);
	head->data=d;
	head->link=NULL;
	node* ptr = head;
	for(i=2;i<=n;i++)
	{
		printf("\nEnter the data for node %d : ",i);
		scanf("%d",&d);
		ptr = add_at_end(ptr,d);
	}
}

void display(int m)
{
	node* ptr = head;
	if(m==1)
	printf("\nOur linked list is : ");
	else
	printf("\nOur updated linked list is : ");
	while(ptr!=NULL)
	{
		printf("%d -> ",ptr->data);
		ptr = ptr->link;
	}
	printf("NULL");
}

int main()
{
	int n,m=1;
	char ch;
	printf("Enter the number of nodes you want in your list : ");
	scanf("%d",&n);
	create_list(n);
	display(m);
	printf("\nDo you want to delete the first node of the list (y/n) : ");
	ch = getch();
	if(ch == 'y' || ch == 'Y')
	{
		head = del_node();
		m = 2;
		display(m);
	}
	else
	printf("\nThere is no updation in our linked list.");
	return 0;
}
