#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *link1,*link2;
}*head;
void createCdl()
{
    struct node *newnode,*tail;
    int ele,i,s;
    printf("Enter the size of Cdl:");
    scanf("%d",&s);
    for(i=0;i<s;i++)
    {
        newnode=(struct node *)malloc(sizeof(struct node));
        if(newnode==NULL)
        {
            printf("Allocation failed");
        }
        printf("Enter %d data:",i+1);
        scanf("%d",&ele);
        newnode->data=ele;
        newnode->link2=NULL;
        if(head==NULL)
        {
            head=newnode;
            tail=newnode;
            head->link1=head;
            head->link2=head;
        }
        else
        {
            tail->link2=newnode;
            newnode->link1=tail;
            tail=newnode;
            newnode->link2=head;
            head->link1=newnode;
        }
    }
}
void displayCdl()
{
    struct node *traverse=head;
    printf("Cdl list:");
    do
    {
        printf("%d",traverse->data);
        traverse=traverse->link2;
    }
    while(traverse!=head);
}
void insertCdl()
{
    struct node *newnode,*traverse=head,*current;
    int ele,pos,count=1;
    newnode=(struct node *)malloc(sizeof(struct node));
    if(newnode==NULL)
    {
        printf("Allocation failed");
        return;
    }
    printf("Enter the position:");
    scanf("%d",&pos);
    printf("Enter the data:");
    scanf("%d",&ele);
    newnode->data=ele;
    if(pos==1)
    {
        current=head->link1;
        newnode->link2=head;
        newnode->link1=current;
        current->link2=newnode;
        head->link1=newnode;
        head=newnode;
    }
    else
    {
        while(count!=pos-1)
        {
            traverse=traverse->link2;
            if(traverse->link2==head)
            {
                printf("Position doesn't exist");
                return;
            }
            count++;
        }
        current=traverse->link2;
        newnode->link2=current;
        current->link1=newnode;
        traverse->link2=newnode;
        newnode->link1=traverse;
        }
    }
void delNode()
{
    struct node *traverse=head,*current,*del;
    int pos,count=1;
    printf("Enter the position for deletion:");
    scanf("%d",&pos);
    if(pos==1)
    {
        current=head->link1;
        del=head;
        head=head->link2;
        head->link1=current;
        current->link2=head;
        free(del);
    }
    else
    {
        while(count!=pos-1)
        {
            traverse=traverse->link2;
            if(traverse->link2==head)
            {
                printf("Position not found");
                return;
            }
            count++;
        }
        current=traverse->link2;
        traverse->link2=current->link2;
        current->link2->link1 = traverse;
        free(current);
        }
}
int main()
{
    int choice=0;
    head=NULL;
    while(1)
    {
        printf("\n1. Create Cdl\n");
        printf("\n2. Display Cdl\n");
        printf("\n3. Insert Cdl\n");
        printf("\n4. Delete Cdl\n");
        printf("\n5. Exit the program\n");
        printf("Enter your choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            if(head==NULL)
            {
                createCdl();
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
                displayCdl();
            }
            break;
            case 3:
            if(head==NULL)
            {
                printf("\n List is empty \n");
            }
            else
            {
                insertCdl();
            }
            break;
            case 4:
            if(head==NULL)
            {
                printf("\n List is empty \n");
            }
            else
            {
                delNode();
            }
            break;
            case 5:exit(0);
            default:printf("Invaild Choice!!");
        }
    }
}