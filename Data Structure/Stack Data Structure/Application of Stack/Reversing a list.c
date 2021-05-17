#include<stdio.h>
#include<stdlib.h>
#define N 20
//Reversing a list (application of stack)
int stack[N],top=-1;
void push(int d)
{
    top++;
    stack[top]=d;
}
void pop()
{
    printf("%d\t",stack[top]);
    top--;
}
int main()
{
    int n,i,d;
    printf("Enter the number of elements you want in your list -: ");
    scanf("%d",&n);
    printf("\nEnter the elements in the list -: ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&d);
        push(d);
    }
    printf("\nThe reverse list is -: ");
    while(top!=-1)
    {
        pop();
    }
    return 0;
}
