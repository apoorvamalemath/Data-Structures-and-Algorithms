#include<stdio.h>

struct node
{
    int data;
    struct node *next;
};

typedef struct node node;

node *insertEND(node *head)
{
    int num;
    node *cur,*newnode;
    cur=head;
    printf("Enter the number to be inserted:\n");
    scanf("%d",&num);
    newnode=(node*)malloc(sizeof(node));
    newnode->data=num;
    newnode->next=NULL;
    if(head==NULL)
    {
        head=newnode;
    }
    else
    {
        while(cur->next!=NULL)
        {
            cur=cur->next;
        }
        cur->next=newnode;
    }
    return head;
}

node *inserBEG(node *head)
{
    int num;
    node *cur,*newnode;
    cur=head;
    printf("Enter the number to be inserted:\n");
    scanf("%d",&num);
    newnode=(node*)malloc(sizeof(node));
    newnode->data=num;
    newnode->next=NULL;
    if(head==NULL)
    {
        head=newnode;
    }
    else
    {
        newnode->next=cur;
        head=newnode;
    }
    return head;
}

node *deleteBEG(node *head)
{
    int num;
    node *cur,*newnode;
    cur=head;
    head=cur->next;
    free(cur);
    return head;
}

node *deleteEND(node *head)
{
    int num;
    node *cur,*prev;
    cur=head;
    prev=cur;
    if(cur==NULL)
    {
        printf("Empty\n");
    }
    if(cur->next==NULL)
    {
        head=NULL;
        num=cur->data;
        printf("%d is deleted \n",num);
        free(cur);

    }
    else
    {
    while(cur->next!=NULL)
    {
        prev=cur;
        cur=cur->next;
    }
    num=cur->data;
    printf("%d is deleted \n",num);
    prev->next=NULL;
    free(cur);
    }
    return head;
}

node *insertPOS(node *head)
{
    int num,pos;
    node *cur,*newnode,*prev;
    cur=head;
    int count=1;
    printf("Enter the position:\n");
    scanf("%d",&pos);
    printf("Enter the number to be inserted:\n");
    scanf("%d",&num);
    newnode=(node*)malloc(sizeof(node));
    newnode->data=num;
    newnode->next=NULL;
    if(count==pos)
    {
        newnode->next=cur;
        head=newnode;
    }
    else
    {
        while(cur!=NULL)
        {
            prev=cur;
            cur=cur->next;
            count++;
         if(count==pos)
        {
            prev->next=newnode;
            newnode->next=cur;
        }
        }
    }
    return head;
}

node *display(node *head)
{
    node *cur;
    cur=head;
    if(cur==NULL)
    {
        printf("Empty\n");
    }
    while(cur!=NULL)
    {
        printf("%d\t",cur->data);
        cur=cur->next;
    }
    printf("\n");
    return head;
}

main()
{
    node *head;
    head=NULL;
    int ch,done=1;
    while(done)
    {
    printf("1.Insert at rear\n2.Delete rear\n3.Display\n4.Insert beg\n5.Delete beg\n6.Insert position\n");
    printf("\nEnter the choice:\n");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1:head=insertEND(head);
                     break;
        case 2:head=deleteEND(head);
                     break;
        case 3:head=display(head);
               break;
        case 4:head=inserBEG(head);
               break;
        case 5:head=deleteBEG(head);
                break;
        case 6:head=insertPOS(head);
               break;
        default: done=0;
    }



    }
}
