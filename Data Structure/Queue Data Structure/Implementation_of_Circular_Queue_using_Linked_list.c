#include <stdio.h>
#include <stdlib.h>
//Circular queue implementation using linked list
typedef struct node
{
    int data;
    struct node *link;
} node;
node *front = NULL;
node *rear = NULL;
void enqueue()
{
    int x;
    node *newnode;
    newnode = (node *)malloc(sizeof(node));
    printf("\nEnter the value to insert -: ");
    scanf("%d", &x);
    newnode->data = x;
    newnode->link = NULL;
    if (front == NULL && rear == NULL)
    {
        front = rear = newnode;
        rear->link = front;
    }
    else
    {
        rear->link = newnode;
        rear = newnode;
        rear->link = front;
    }
}
void dequeue()
{
    if (front == NULL && rear == NULL)
    {
        printf("\nUnderflow\n");
    }
    else if (front == rear)
    {
        node *temp = front;
        printf("\nDequed element is %d\n", front->data);
        front = rear = NULL;
        free(temp);
    }
    else
    {
        node *temp = front;
        printf("\nDequed element is %d\n", front->data);
        front = front->link;
        rear->link = front;
        free(temp);
    }
}
void peek()
{
    if (front == NULL && rear == NULL)
    {
        printf("\nQueue is empty\n");
    }
    else
    {
        printf("\nFront element is %d\n", front->data);
    }
}
void display()
{
    node *temp = front;
    if (front == NULL && rear == NULL)
    {
        printf("\nQueue is empty\n");
    }
    else
    {
        printf("\nQueue is -:\n");
        while (temp->link != front)
        {
            printf("%d\t", temp->data);
            temp = temp->link;
        }
        printf("%d", temp->data);
    }
}
int main()
{
    int ch;
    while (1)
    {
        printf("\n1. Insert\n2. Delete\n3. Peek\n4. Display\n5. Exit");
        printf("\nEnter your choice -: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            enqueue();
            break;
        case 2:
            dequeue();
            break;
        case 3:
            peek();
            break;
        case 4:
            display();
            break;
        case 5:
            exit(0);
            break;
        default:
            printf("\nInvalid choice!!\nPlease make a valid choice");
            break;
        }
    }
    return 0;
}
