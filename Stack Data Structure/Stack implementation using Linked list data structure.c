#include<stdio.h>
#include<stdlib.h>
//Stack implementation using linked list
typedef struct node
{
    int data;
    struct node *link;
}node;
node *top = NULL;
void push()
{
    int x;
    printf("Enter the data to push into the stack :- ");
    scanf("%d",&x);
    node *newnode;
    newnode = (node*)malloc(sizeof(node));
    newnode->data=x;
    newnode->link=top;
    top=newnode;
}
void pop()
{
    node *temp;
    temp=top;
    if(top==NULL)
    {
        printf("\nStack is empty\n");
    }
    else
    {
        printf("\n%d popped out from the stack\n",top->data);
        top=top->link;
        free(temp);
    }
}
void peek()
{
    if(top==NULL)
    {
        printf("\nStack is empty\n");
    }
    else
    {
        printf("\nTop element of the stack is -: %d\n",top->data);
    }
}
void isempty()
{
    if(top==NULL)
    {
        printf("\nYes stack is empty\n");
    }
    else{
        printf("\nNo the stack is not empty\n");
    }
}
void display()
{
    node *temp=top;
    if(top==NULL)
    {
        printf("\nStack is empty\n");
    }
    else
    {
        printf("\nThe elements in the stack are  -: \n");
        while(temp!=NULL)
        {
            printf("%d\t",temp->data);
            temp=temp->link;
        }
        printf("\n");
    }
}
int main()
{
    int ch;
    while(1)
    {
    printf("\n1. Push\n2. Pop\n3. Peek\n4. Is empty ?\n5. Display\n6. Exit\n");
    printf("Select your choice -: ");
    scanf("%d",&ch);
    switch (ch)
    {
    case 1 : push();
        break;
    case 2 : pop();
        break;
    case 3 : peek();
        break;
    case 4 : isempty();
        break;
    case 5 : display();
        break;
    case 6 : exit(0);
        break;
    default: printf("\nInvalid choice!!\nPlease make a valid choice\n");
        break;
    }
    }
    return 0;
}
