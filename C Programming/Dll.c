#include <Stdio.h>
#include <stdlib.h>
struct node 
{
    int data;
    struct node *link1,*link2;
}*head;
void createDll();
void displayDll();
void insertDll();
void delDll();
int main()
{
    int choice=1;
    head=NULL;
    while(1)
    {
        printf("\n1.Create Dll\n");
        printf("\n2.display Dll\n");
        printf("\n3.Insert Dll\n");
        printf("\n4.Del node\n");
        printf("\n5.Exit the program\n");
        printf("\nEnter your choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            if(head==NULL)
            {
                createDll();
            }
            else
            {
                printf("List already created");
            }
            break;
            case 2:
            if(head==NULL)
            {
                printf("List is empty");
            }
            else
            {
                displayDll();
            }
            break;
            case 3:
            if(head==NULL)
            {
                printf("List is empty");
            }
            else
            {
                insertDll();
            }
            break;
            case 4:
            if(head==NULL)
            {
                printf("List is empty");
            }
            else
            {
                delDll();
            }
            break;
            case 5:exit(0);
            default:printf("Invaild choice");
        }
    }
    return 0;
}
void createDll()
{
    struct node *newnode,*tail;
    int ele,i,s;
    printf("Enter the size:");
    scanf("%d",&s);
    for(i=0;i<s;i++)
    {
        newnode=(struct node *)malloc(sizeof(struct node));
        if(newnode==NULL)
        {
            printf("Allocation failed");
            return;
        }
        printf("Enter %d data:",i+1);
        scanf("%d",&ele);
        newnode->data=ele;
        newnode->link2=NULL;
    if(head==NULL)
    {
        head=newnode;
        tail=newnode;
        head->link1=NULL;
    }
    else
    {
        tail->link2=newnode;
        newnode->link1=tail;
        tail=newnode;
    }
}
}
void displayDll()
{
    struct node *traverse=head;
    printf("Linked list:");
    while(traverse!=NULL)
    {
        printf("%d->",traverse->data);
        traverse=traverse->link2;
    }
    printf("NULL");
}
void insertDll()
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
        current=newnode;
        current->link1=NULL;
        current->link2=head;
        head->link1=newnode;
        head=newnode;
    }
    else
    {
        while(count!=pos-1)
        {
            traverse=traverse->link2;
            if(traverse->link2==NULL)
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
void delDll()
{
    struct node *traverse=head,*current;
    int pos,count=1;
    printf("Enter the position:");
    scanf("%d",&pos);
    if(pos==1)
    {
        current=head;
        head=head->link2;
        free(current);
    }
    else
    {
        while(count!=pos-1)
        {
            traverse=traverse->link2;
            if(traverse->link2==NULL)
            {
                printf("Position doesn't exist");
                return;
            }
            count++;
        }
        current=traverse->link2;
        traverse->link2=current->link2;
        free(current);
        }
}