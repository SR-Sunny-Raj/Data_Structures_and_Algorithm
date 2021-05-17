#include <stdio.h>
#include <stdlib.h>
#define N 5
//Circular queue implementation using array
int queue[N], front = -1, rear = -1;
void enqueue()
{
    int x;
    if (front == -1 && rear == -1)
    {
        front = rear = 0;
        printf("\nEnter the value to insert -: ");
        scanf("%d", &x);
        queue[rear] = x;
    }
    else if (((rear + 1) % N) == front)
    {
        printf("\nOverflow\n");
    }
    else
    {
        rear = (rear + 1) % N;
        printf("\nEnter the value to insert -: ");
        scanf("%d", &x);
        queue[rear] = x;
    }
}
void dequeue()
{
    if (front == -1 && rear == -1)
    {
        printf("\nUnderflow\n");
    }
    else if (front == rear)
    {
        printf("\nDequed element is %d\n", queue[front]);
        front = rear = -1;
    }
    else
    {
        printf("\nDequed element is %d\n", queue[front]);
        front = (front + 1) % N;
    }
}
void peek()
{
    if (front == -1 && rear == -1)
    {
        printf("\nQueue is empty\n");
    }
    else
    {
        printf("\nFront element is %d\n", queue[front]);
    }
}
void display()
{
    int i = front;
    if (front == -1 && rear == -1)
    {
        printf("\nQueue is empty\n");
    }
    else
    {
        printf("\nQueue is -: ");
        while (i != rear)
        {
            printf("%d\t", queue[i]);
            i = (i + 1) % N;
        }
        printf("%d", queue[rear]);
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
            printf("\nInvalid choice!!\nPlease make a valid choice\n");
            break;
        }
    }
    return 0;
}
