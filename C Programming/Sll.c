#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
}*head;
void create_sll();
void display_sll();
void add_first();
void add_last();
void add_btw();
void del_node();
void del_last();
int main()
{
    int choice=0;
    head=NULL;
    while(1)
    {
        printf("\n1. Create linked list\n");
        printf("\n2. Display linked list\n");
        printf("\n3. Add element at beg\n");
        printf("\n4. Add element at last\n");
        printf("\n5. Add element at specific position\n");
        printf("\n6. Delete node at first and specific position\n");
        printf("\n7. Delete the end node");
        printf("\n8. Exit the program\n");
        printf("Enter your choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            if(head==NULL)
            {
                create_sll();
            }
            else
            {
                printf("\n Linked list exist \n");
            }
            break;
            case 2:
            if(head==NULL)
            {
                printf("\n Linked list empty \n");
            }
            else
            {
                display_sll();
            }
            break;
            case 3:
            if(head==NULL)
            {
                printf("\n List is empty \n");
            }
            else
            {
                add_first();
            }
            break;
            case 4:
            if(head==NULL)
            {
                printf("\n List is empty \n");
            }
            else
            {
                add_last();
            }
            break;
            case 5:
            if(head==NULL)
            {
                printf("\n List is empty \n");
            }
            else
            {
                add_btw();
            }
            break;
            case 6:
            if(head==NULL)
            {
                printf("\n List is empty \n");
            }
            else
            {
                del_node();
            }
            break;
            case 7:
            if(head==NULL)
            {
                printf("\n List is empty \n");
            }
            else
            {
                del_last();
            }
            break;
            case 8:exit(0);
            default:printf("\n Wrong choice \n");
        }
    }
    return 0;
}
void create_sll()
{
    struct node *tail,*newnode;
    int ele,n,i;
    printf("Enter the size:");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        newnode=(struct node *)malloc(sizeof(struct node));
        if(newnode==NULL)
        {
            printf("Allocation failed");
            exit(0);
        }
        printf("Enter the %d data:",i+1);
        scanf("%d",&ele);
        newnode->data=ele;
        newnode->next=NULL;
        if(head==NULL)
        {
            head=newnode;
            tail=newnode;
        }
        else
        {
            tail->next=newnode;
            tail=newnode;
        }
    }
}
void display_sll()
{
    struct node *traverse=NULL;
    traverse=head;
    printf("Linked list data:");  
    while(traverse!=NULL)
    {
        printf("%d",traverse->data);
        traverse=traverse->next;
    }

}
void add_first()
{
    struct node *newnode;
    int ele;
    newnode=(struct node *)malloc(sizeof(struct node));
    printf("Enter the data:");
    scanf("%d",&ele);
    newnode->data=ele;
    newnode->next=head;
    head=newnode;
}
void add_last()
{
    struct node *newnode,*traverse;
    int ele;
    newnode=(struct node *)malloc(sizeof(struct node));
    printf("Enter the data:");
    scanf("%d",&ele);
    newnode->data=ele;
    newnode->next=NULL;
    traverse=head;
    while(traverse->next!=NULL)
    {
        traverse=traverse->next;
    }
    traverse->next=newnode;
}
void add_btw()
{
    struct node *temp=head,*newnode;
    int pos,ele,count=1;
    newnode=(struct node *)malloc(sizeof(struct node));
    if(newnode==NULL)
    {
        printf("\nAllocation failed\n");
        return;
    }
    printf("Enter the position for insertion:");
    scanf("%d",&pos);
    printf("Enter the data:");
    scanf("%d",&ele);
    newnode->data=ele;
    if(pos==1)
    {
        newnode->next=head;
        head=newnode;
    }
    else
    {
    while(count!=pos-1)
    {
        temp=temp->next;
        if(temp->next==NULL)
        {
            printf("\nPosition not in list\n");
            return;
        }
        count++;   
    }
    newnode->next=temp->next;
    temp->next=newnode;
}
}
void del_node()
{
    struct node *traverse=head,*current;
    int pos,count=1;
    printf("Enter position for deletion:");
    scanf("%d",&pos);
    if(pos==1)
    {
        current=head;
        head=head->next;  
        free(current);
    }
    else
    {
        while(count!=pos-1)
        {
            traverse=traverse->next;
            if(traverse->next==NULL)
            {
                printf("\n Position not found \n");
                return;
            }
            count++;
        }
        current=traverse->next;
        traverse->next = current->next;
        free(current);
    }
}
void del_last()
{
    struct node *traverse=head,*current;
    while(traverse->next->next!=NULL)
    {
        traverse=traverse->next;
    }
    current=traverse->next;
    traverse->next=NULL;
    free(current);
}