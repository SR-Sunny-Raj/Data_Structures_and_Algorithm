#include<stdio.h>
#include<stdlib.h>
#define N 20
//Parenthesis checker (application of stack)
char stack[20];
int top=-1;
void push(char e)
{
    top++;
    stack[top]=e;
}
void pop()
{
    top--;
}
int main()
{
    char exp[N],*e;
    printf("Enter the expression to check -: ");
    scanf("%s",exp);
    e=exp;
    while(*e!='\0')
    {
        if(*e=='[' || *e=='{' || *e=='(')
        {
            push(*e);
        }
        else if(*e==']' && stack[top]=='[')
        {
            pop();
        }
        else if(*e=='}' && stack[top]=='{')
        {
            pop();
        }
        else if(*e==')' && stack[top]=='(')
        {
            pop();
        }
        else if((*e==']' && stack[top]!='[') || (*e=='}' && stack[top]!='{') || (*e==')' && stack[top]!='('))
        {
            printf("Invalid expression!!\nCheck all the paranthesis correctly");
            exit(0);
        }
        e++;
    }
    if(top!=-1)
    {
        printf("Invalid expression!!\nCheck all the paranthesis correctly");
    }
    else
    {
        printf("\nThe expression is correctly paranthesised");
    }
    return 0;
}
