#include <stdio.h>
#include <stdlib.h>
//Preorder , Inorder and Postorder traversal in binary tree
typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
} node;
node *create()
{
    int x;
    printf("\nEnter data (-1 for no node) -: ");
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
void preorder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    else
    {
        printf("%d\t", root->data);
        preorder(root->left);
        preorder(root->right);
        return;
    }
}
void inorder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    else
    {
        inorder(root->left);
        printf("%d\t", root->data);
        inorder(root->right);
        return;
    }
}
void postorder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    else
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d\t", root->data);
        return;
    }
}
int main()
{
    int ch;
    printf("Creation of the tree\n");
    node *root = NULL;
    root = create();
    while (1)
    {
        printf("\n\n1. Preorder traversal of tree\n2. Inorder traversal of tree\n3. Postorder traversal of tree\n4. Exit");
        printf("\nEnter your choice -: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("\nPreorder traversal of the tree is -: \n");
            preorder(root);
            break;
        case 2:
            printf("\nInorder traversal of the tree is -: \n");
            inorder(root);
            break;
        case 3:
            printf("\nPostorder traversal of the tree is -: \n");
            postorder(root);
            break;
        case 4:
            exit(0);
            break;
        default:
            printf("\nInvalid choice!!\nPlease make a valid choice.");
            break;
        }
    }
    return 0;
}
