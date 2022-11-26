#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node * insert(struct node *root)
{
    int value;
    printf("\nEnter a value : ");
    scanf("%d",&value);
    struct node *temp=(struct node *)malloc(sizeof(struct node));
    temp->data=value;
    temp->left=NULL;
    temp->right=NULL;
    if (root==NULL)
    {
        return temp;
    }
    struct node *ptr=root;
    while(true)
    {
        if (value==ptr->data)
        {
            printf("%d %d",value,ptr->data);
            return root;
        }
        else if(value<ptr->data)
        {
            if (ptr->left==NULL)
            {
                ptr->left=temp;
                return root;
            }
            else
            {
                ptr=ptr->left;
            }
        }
        else
        {
            if(ptr->right==NULL)
            {
                ptr->right=temp;
                return root;
            }
            else
            {
                ptr=ptr->right;
            }
        }
    }
    return root;
}

struct node * delete(struct node *root)
{
    if (root==NULL)
    {
        printf("Empty Tree\n");
        return root;
    }
    int value;
    printf("Enter the value to be deleted : ");
    scanf("%d",&value);
    
    //Code
    
    return root;
}

void preOrder(struct node *root)
{
    if (root==NULL)
    {
        return;
    }
    printf("%d ",root->data);
    preOrder(root->left);
    preOrder(root->right);
}

void inOrder(struct node *root)
{
    if (root==NULL)
    {
        return;
    }
    inOrder(root->left);
    printf("%d ",root->data);
    inOrder(root->right);
}

void postOrder(struct node *root)
{
    if (root==NULL)
    {
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    printf("%d ",root->data);
}


int main()
{
    int choice;
    struct node *root=NULL;
    while(true)
    {
        printf("\nPress 1 to Insert\n");
        printf("Press 2 to Delete\n");
        printf("Press 3 for Preorder Transversal\n");
        printf("Press 4 for Inorder Traversal\n");
        printf("Press 5 for Postorder Traversal\n");
        printf("Press 6 to Exit\n");
        printf("\nEnter your choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                root=insert(root);
                break;
            case 2:
                root=delete(root);
                break;
            case 3:
                printf("Preorder Traversal : \n");
                preOrder(root);
                break;
            case 4:
                printf("Inorder Traversal : \n");
                inOrder(root);
                break;
            case 5:
                printf("Postorder Traversal : \n");
                postOrder(root);
                break;
            case 6:
                return 0;
            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}