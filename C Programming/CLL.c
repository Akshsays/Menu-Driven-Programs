#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
}*head;
void createCsl();
void displayCsl();
int main()
{
    int choice=0;
    head=NULL;
    while(1)
    {
        printf("\n1.Create csl\n");
        printf("\n2.Display csl\n");
        printf("\n3.Exit the program\n");
        printf("Enter the choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            if(head==NULL)
            {
                createCsl();
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
                displayCsl();
            }
            break;
            case 3:exit(0);
        }
    }
    return 0;
}
void createCsl()
{
    struct node *newnode,*tail;
    int ele,i,s;
    printf("Enter the size of list:");
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
        newnode->next=NULL;
        if(head==NULL)
        {
            head=newnode;
            tail=newnode;
            tail->next=head;
        }
        else
        {
            tail->next=newnode;
            tail=newnode;
            tail->next=head;
        }
    }
}
void displayCsl()
{
    struct node *traverse=head;
    printf("Csl list:");
    do
    {
        printf("%d ",traverse->data);
        traverse=traverse->next;
    }
    while(traverse!=head);
}