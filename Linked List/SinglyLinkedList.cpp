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
    cout << "Enter the value to be inserted : ";
    cin >> n;
    temp->data=n;
    temp->next=head;
    return temp;
}

void display(struct node *head)
{
    while(head!=NULL)
    {
        cout << head->data << " ";
        head=head->next;
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