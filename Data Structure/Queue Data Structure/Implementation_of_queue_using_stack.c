#include <stdio.h>
#include <stdlib.h>
#define N 5
//Implementation of queue using stack
int stack1[N], stack2[N];
int top1 = -1, top2 = -1, count = 0;
void push1(int a)
{
    if (top1 == -1)
    {
        top1 = 0;
        stack1[top1] = a;
    }
    else
    {
        top1++;
        stack1[top1] = a;
    }
}
void push2(int b)
{
    if (top2 == -1)
    {
        top2 = 0;
        stack2[top2] = b;
    }
    else
    {
        top2++;
        stack2[top2] = b;
    }
}
int pop1()
{
    return (stack1[top1--]);
}
int pop2()
{
    return (stack2[top2--]);
}
void enqueue()
{
    int x;
    if (top1 == -1 && top2 == -1)
    {
        printf("Enter the value to insert -: ");
        scanf("%d", &x);
        count++;
        push1(x);
    }
    else if (top1 == (N - 1) || top2 == (N - 1))
    {
        printf("Overflow");
    }
    else
    {
        printf("Enter the value to insert -: ");
        scanf("%d", &x);
        count++;
        push1(x);
    }
}
void dequeue()
{
    int i = count;
    if (top1 == -1)
    {
        printf("Underflow");
    }
    else
    {
        while (i != 0)
        {
            push2(pop1());
            i--;
        }
        printf("Popped element is %d", stack2[top2]);
        pop2();
        count--;
        i = count;
        while (i != 0)
        {
            push1(pop2());
            i--;
        }
    }
}
void peek()
{
    int i = count;
    if (top1 == -1)
    {
        printf("Queue is empty");
    }
    else
    {
        while (i != 0)
        {
            push2(pop1());
            i--;
        }
        printf("Front element is %d", stack2[top2]);
        i = count;
        while (i != 0)
        {
            push1(pop2());
            i--;
        }
    }
}
void display()
{
    int i = count;
    if (top1 == -1)
    {
        printf("Queue is empty");
    }
    else
    {
        while (i != 0)
        {
            push2(pop1());
            i--;
        }
        i = count;
        while (i != 0)
        {
            printf("%d\t", stack2[top2]);
            push1(pop2());
            i--;
        }
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
            printf("Invalid choice!!\nPlease make a valid choice");
            break;
        }
    }
    return 0;
}
