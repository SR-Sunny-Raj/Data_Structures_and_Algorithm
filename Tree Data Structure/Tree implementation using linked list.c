#include <stdio.h>
#include <stdlib.h>
//Tree implementation using linked list
typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
} node;
node *create()
{
    int x;
    printf("\nEnter data(-1 for no node) -: ");
    scanf("%d", &x);
    if (x == -1)
    {
        return NULL;
    }
    else
    {
        node *newnode;
        newnode = (node *)malloc(sizeof(node));
        newnode->data = x;
        printf("\nEnter left child of %d", x);
        newnode->left = create();
        printf("\nEnter right child of %d", x);
        newnode->right = create();
        return newnode;
    }
}
int main()
{
    node *root = NULL;
    root = create();
    return 0;
}
