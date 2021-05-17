#include<stdio.h>
#include<stdlib.h>
#define N 10
//Implementation of Queue using array
int queue[N],front=-1,rear=-1;
void enqueue()
{
    int x;
    if(front==-1 && rear==-1)
    {
        front=rear=0;
        printf("\nEnter the value to insert :- ");
        scanf("%d",&x);
        queue[rear]=x;
    }
    else if(rear>=N-1)
    {
        printf("\nOverflow\n");
    }
    else
    {
        rear++;
        printf("\nEnter the value to insert :- ");
        scanf("%d",&x);
        queue[rear]=x;
    }
}
void dequeue()
{
    if(front==-1 && rear==-1)
    {
        printf("\nQueue is empty\n");
    }
    else if(front==rear)
    {
        printf("\nDequed element is %d\n",queue[front]);
        front=-1;
        rear=-1;
    }
    else
    {
        printf("\nDequed element is %d\n",queue[front]);
        front++;
    }
}
void peek()
{
    if(front==-1 && rear==-1)
    {
        printf("\nQueue is empty\n");
    }
    else
    {
        printf("\nFront element is %d\n",queue[front]);
    }
}
void display()
{
    int i=front;
    if(front==-1 && rear==-1)
    {
        printf("\nQueue is empty\n");
    }
    else
    {
        printf("\nThe elements in the queue are -:\n");
        while(i!=rear+1)
        {
            printf("%d\t",queue[i]);
            i++;
        }
        printf("\n");
    }
}
int main()
{
    int ch;
    while(1)
    {
    printf("\n1. Insert\n2. Delete\n3. Peek\n4. Display\n5. Exit\n");
    printf("Enter your choice from the following -: ");
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
        default : printf("\nInvalid choice!!\nPlease make a valid choice");
        break;
    }
    }
    return 0;
}
