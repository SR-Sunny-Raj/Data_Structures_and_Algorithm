#include<stdio.h>
#include<stdlib.h>
//Stack implementation using array
#define N 5
int top=-1,stack[N];
void push()
{
    int a;
    if(top==(N-1))
    printf("\nStack overflow\n");
    else
    {
        int b;
        printf("\nEnter data to push into the stack :- ");
        scanf("%d",&b);
        top++;
        stack[top]=b;
    }
}
void pop()
{
    int c;
    if(top==-1)
    {
        printf("\nStack underflow\n");
    }
    else
    {
        c=stack[top];
        top--;
        printf("\n%d popped out from the stack",c);
    }
}
void topp()
{
    if(top==-1)
    {
        printf("\nStack is Empty\n");
    }
    else
    printf("\nThe top element of the stack is :- %d",stack[top]);
}
void isfull()
{
    if(top==(N-1))
    printf("\nYes stack is full\n");
    else
    printf("\nNo stack is not full\n");
}
void isempty()
{
    if(top==-1)
    printf("\nYes stack is empty\n");
    else
    printf("\nNo stack is not empty\n");
}
void display()
{
    int i;
    if(top==-1)
    printf("\nStack is empty\n");
    printf("\nThe elements in the stack are -:\n");
    for(i=top;i>=0;i--)
    {
        printf("%d\t",stack[i]);
    }
}
int main()
{
    int ch;
    while(1)
    {
    printf("\n1. To push into the stack\n2. To pop an element from the stack\n3.To see the top element\n4.To check if the stack is full\n5. To check if the stack is empty\n6. To display the stack\n7.Exit\n");
    printf("Enter your choice from the following -: ");
    scanf("%d",&ch);
    switch (ch)
    {
    case 1 : push();
        break;
    case 2 : pop();
        break;
    case 3 : topp();
        break;
    case 4 : isfull();
        break;
    case 5 : isempty();
        break;
    case 6 : display();
        break;
    case 7 : exit(0);
        break;
    default: printf("\nInvalid Choice!!\nPlease make a valid choice\n");
        break;
    }
    }
    return 0;
}
