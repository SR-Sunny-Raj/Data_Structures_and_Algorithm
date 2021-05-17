#include<stdio.h>
#include<stdlib.h>
//Queue implementation using linked list
typedef struct node
{
    int data;
    struct node *link;
}node;
node *front=NULL;
node *rear=NULL;
void enqueue()
{
    int i;
    printf("Enter the element to insert in the queue :- ");
    scanf("%d",&i);
    node *newnode;
    newnode = (node *)malloc(sizeof(node));
    if(front==NULL && rear==NULL)
    {
        newnode->data=i;
        newnode->link=NULL;
        front=rear=newnode;
    }
    else
    {
        newnode->data=i;
        newnode->link=NULL;
        rear->link=newnode;
        rear=newnode;
    }
}
void dequeue()
{
    node *temp = front;
    if(front==NULL && rear==NULL)
    {
        printf("Queue is empty");
    }
    else if(front!=NULL)
    {
        printf("Dequed element is %d",front->data);
        front = front->link;
        free(temp);
    }
    else
    {
        printf("Queue is empty");
    }
}
void peek()
{
    if(front==NULL && rear==NULL)
    {
        printf("Queue is empty");
    }
    else
    {
        printf("Front element is %d",front->data);
    }
}
void display()
{
    if(front==NULL && rear==NULL)
    {
        printf("Queue is empty");
    }
    else
    {
        node *temp=front;
        while(temp!=NULL)
        {
        printf("%d\t",temp->data);
        temp=temp->link;
        }
    }
}
int main()
{
    int ch;
    while(1)
    {
        printf("\n1. Insert\n2. Delete\n3. Peek\n4. Display\n5. Exit\n");
        printf("Enter your choice -: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1 : enqueue();
            break;
            case 2 : dequeue();
            break;
            case 3 : peek();
            break;
            case 4 : display();
            break;
            case 5 : exit(0);
            break;
            default : printf("Invalid choice!!\nPlease make a valid choice");
            break;
        }
    }
    return 0;
}
