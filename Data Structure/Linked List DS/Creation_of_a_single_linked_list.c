#include <stdio.h>
#include <stdlib.h>
//A simple creation of a linked list
typedef struct node
{
	int data;
	struct node *link;
}node;
node *head = NULL;
node *current = NULL;
void display()
{
	node *ptr = head;
	while(ptr!=NULL)
	{
	printf("%d->",ptr->data);
	ptr = ptr->link;
	}
	printf("NULL");
}

int main()
{
	head = malloc(sizeof(node));
	head->data = 21;
	head->link = NULL;
	node *current = malloc(sizeof(node));
	current->data = 24;
	current->link = NULL;
	head->link = current;
	current = malloc(sizeof(node));
	current->data = 13;
	current->link = NULL;
	head->link->link = current;
	current = malloc(sizeof(node));
	current->data = 33;
	current->link = NULL;
	head->link->link->link = current;
	printf("Our Linked list is : ");
	display();
	return 0;
}
