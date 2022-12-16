#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

struct node{
    int data;
    int priority;
    struct node *next;;
};

struct node * enqueue(struct node *head){
    int value,pr;
    printf("Enter the value to be inserted : ");
    scanf("%d",&value);
    printf("Enter the priority : ");
    scanf("%d",&pr);
    printf("\n%d is inserted in the Queue with %d priority\n",value,pr);
    struct node *temp=(struct node *)malloc(sizeof(struct node));
    temp->data=value;
    temp->priority=pr;
    temp->next=NULL;
    if (head==NULL || head->priority<pr){
        temp->next=head;
        return temp;
    }
    struct node *ptr=head;
    while(ptr->next!=NULL){
        if (ptr->next->priority<pr){
            temp->next=ptr->next;
            ptr->next=temp;
            return head;
        }
        ptr=ptr->next;
    }
    ptr->next=temp;
    return head;
}

struct node * dequeue(struct node *head){
    if (head==NULL){
        printf("\nUnderflow\n");
        return head;
    }
    printf("\n%d is dequeued\n",head->data);
    struct node *temp=head->next;
    free(head);
    return temp;
}

void display(struct node *head){
    printf("\nThe Priority Queue is : ");
    while(head!=NULL){
        printf("%d ",head->data);
        head=head->next;
    }
    printf("\n");
}

int main(){
    struct node *head=NULL;
    int c;
    while(true){
        printf("\nPress 1 to Enqueue\n");
        printf("Press 2 to Dequeue\n");
        printf("Press 3 to Display\n");
        printf("Press 4 to Exit\n");
        printf("\nEnter your choice : ");
        scanf("%d",&c);
        switch(c){
            case 1:
                head=enqueue(head);
                break;
            case 2:
                head=dequeue(head);
                break;
            case 3:
                display(head);
                break;
            case 4:
                return 0;
            default:
                printf("Invalid Choice. Try Again\n");
        }
    }
}