#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

int max(int a,int b)
{
    if (a>b)
    {
        return a;
    }
    else
    {
        return b;
    }
}

int height(struct node *root)
{
    if (root==NULL)
    {
        return 0;
    }
    return max(height(root->left),height(root->right))+1;
}

int findSize(struct node *root)
{
    if (root==NULL)
    {
        return 0;
    }
    return findSize(root->left)+findSize(root->right)+1;
}

struct node* findMin(struct node* root)
{
    while(root->left != NULL)
    {
        root=root->left;
    }
    return root;
}

int minBST(struct node *root)
{
    while(root->left!=NULL)
    {
        root=root->left;
    }
    return root->data;
}

int maxBST(struct node *root)
{
    while(root->right!=NULL)
    {
        root=root->right;
    }
    return root->data;
}

void kBST(struct node *root,int k)
{
    if(root==NULL)
    {
        return;
    }
    if(k==0)
    {
        printf("%d ",root->data);
    }
    kBST(root->left,k-1);
    kBST(root->right,k-1);
}

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

struct node * delete(struct node *root,int value)
{
    if (root==NULL)
    {
        printf("Empty Tree\n");
        return root;
    }
    else if (value<root->data)
    {
        root->left=delete(root->left,value);
    }
    else if (value>root->data)
    {
        root->right=delete(root,value);
    }
    else{
        // Case 1 : No Child
        if (root->left==NULL && root->right==NULL)
        {
            free(root);
            root=NULL;
        }
        // Case 2 : One Child
        else if (root->left==NULL)
        {
            struct node *temp=root;
            root=root->right;
            free(temp);
        }
        else if (root->right==NULL)
        {
            struct node *temp=root;
            root=root->left;
            free(temp);
        }
        // Case 3 : Two Child
        else
	{
            struct node *temp = findMin(root->right);
	    root->data = temp->data;
	    root->right = delete(root->right,temp->data);
        }
    }
    
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
        printf("Press 6 to find Height\n");
        printf("Press 7 to find the size of Binary Search Tree\n");
        printf("Press 8 to find the minimum value\n");
        printf("Press 9 to find the maximum value\n");
        printf("Press 10 to diplay nodes at k distance\n");
        printf("Press 11 to Exit\n");
        printf("\nEnter your choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                root=insert(root);
                break;
            case 2:
                int value;
                printf("\nEnter the value to be deleted : ");
                scanf("%d",&value);
                root=delete(root,value);
                break;
            case 3:
                printf("\nPreorder Traversal : \n");
                preOrder(root);
                break;
            case 4:
                printf("\nInorder Traversal : \n");
                inOrder(root);
                break;
            case 5:
                printf("\nPostorder Traversal : \n");
                postOrder(root);
                break;
            case 6:
                printf("\nThe Height is : %d\n",height(root));
                break;
            case 7:
                printf("\nThe Size of the Binary Search Tree is : %d\n",findSize(root));
                break;
            case 8:
                printf("\nThe Minimum Value : %d\n",minBST(root));
                break;
            case 9:
                printf("\nThe Maximum Value : %d\n",maxBST(root));
                break;
            case 10:
                int k;
                printf("Enter the value of k : ");
                scanf("%d",&k);
                if (k>height(root))
                {
                    printf("k cannot be less than the height of the Tree\n");
                }
                else
                {
                    kBST(root,k);
                }
                break;
            case 11:
                return 0;
            default:
                printf("\nInvalid choice. Try again.\n");
        }
    }

    return 0;
}
