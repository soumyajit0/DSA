#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node *next;
};

struct node * insertBeg(struct node *head)
{
    int n;
    struct node *temp=(struct node *)malloc(sizeof(struct node));
    cout << "Enter the value to be inserted at the beginning : ";
    cin >> n;
    temp->data=n;
    temp->next=head;
    return temp;
}

struct node * insertEnd(struct node *head)
{
    int n;
    struct node *temp=(struct node *)malloc(sizeof(struct node));
    cout << "Enter the value to be inserted at the end : ";
    cin >> n;
    temp->data=n;
    temp->next=NULL;
    struct node *ptr=head;
    while(ptr->next!=NULL)
    {
        ptr=ptr->next;
    }
    ptr->next=temp;
    return head;
}

struct node * deleteBeg(struct node *head)
{
    if(head==NULL)
    {
        cout << "Linkedlist is already empty\n";
        return head;
    }
    struct node *temp=head->next;
    free(head);
    return temp;
}

struct node * deleteEnd(struct node *head)
{
    //When No. of Nodes = 0
    if(head==NULL){
        cout << "Linkedlist is already empty\n";
        return head;
    }
    //When No. of Nodes = 1
    else if(head->next==NULL)
    {
        free(head);
        return NULL;
    }
    //When No. of Nodes > 1
    struct node *temp=head;
    while(temp->next->next!=NULL){
        temp=temp->next;
    }
    free(temp->next);
    temp->next=NULL;
    return head;
}

void display(struct node *head)
{
    struct node *ptr=head;
    while(ptr!=NULL)
    {
        cout << ptr->data << " ";
        ptr=ptr->next;
    }
    cout << endl;
}

int main()
{

    struct node *head=NULL;
    int c;

    while(true)
    {
        cout << "\nPress 1 to insert at beginning\n";
        cout << "Press 2 to insert at the end\n";
        cout << "Press 3 to delete from the beginning\n";
        cout << "Press 4 to delete from end\n";
        cout << "Press 5 to display\n";
        cout << "Press 6 to exit\n";
        cout << "\nEnter your choice : ";
        cin >> c;
        switch(c)
        {
            case 1:
                head=insertBeg(head);
                break;
            case 2:
                head=insertEnd(head);
                break;
            case 3:
                head=deleteBeg(head);
                break;
            case 4:
                head=deleteEnd(head);
                break;
            case 5:
                display(head);
                break;
            case 6:
                return 0;
            default:
                cout << "Invalid Choice. Try again\n";
        }
    }

    return 0;
}
