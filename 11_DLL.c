#include<stdio.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

typedef struct node node;

node *insertEND(node *head)
{
    node *newnode,*cur;
    cur=head;
    int num;
    newnode=(node *)malloc(sizeof(node));
    printf("Enter the number:\n");
    scanf("%d",&num);
    newnode->data=num;
    newnode->prev=newnode->next=NULL;
    if(head==NULL)
    {
        head=newnode;
        return head;
    }
    while(cur->next!=NULL)
    {
        cur=cur->next;
    }
    cur->next=newnode;
    newnode->prev=cur;
    return head;
}

node *insertBEG(node *head)
{
    node *newnode,*cur;

    int num;
    newnode=(node *)malloc(sizeof(node));
    printf("Enter the number:\n");
    scanf("%d",&num);
    newnode->data=num;
    newnode->prev=newnode->next=NULL;
    if(head==NULL)
    {
        head=newnode;
        newnode->prev=newnode->next=NULL;
        return head;
    }
    newnode->next=head;
    head->prev=newnode;
    //printf("INSERTED 2 ");
    head=newnode;
    return head;
}



node *deleteEND(node *head)
{
    node *cur,*pre;
    cur=head;
    if(head==NULL)
    {
        return head;
    }
    while(cur->next!=NULL)
    {
        pre=cur;
        cur=cur->next;
    }
    pre->next=NULL;
    free(cur);
    return head;
}


node *deleteBEG(node *head)
{
    node *cur,*temp;
    cur=head->next;
    temp=head;
    if(head==NULL)
    {
        return head;
    }
    cur->prev=NULL;
    head=cur;
    free(temp);
    return head;
}


node *display(node *head)
{
    node *cur;
    cur=head;
    while(cur!=NULL)
    {
        printf("%d\t",cur->data);
        cur=cur->next;
    }
    printf("\n");
    return head;
}

node *insertPOS(node *head)
{
    node *cur,*temp,*newnode;
    cur=head;
    int pos,num;
    int n=1;
    printf("Enter the position:\n");
    scanf("%d",&pos);
    printf("Enter the number:\n");
    scanf("%d",&num);
    newnode=(node *)malloc(sizeof(node));
    newnode->data=num;
    newnode->prev=newnode->next=NULL;
    while(n!=pos)
    {
        cur=cur->next;
        n++;
    }
    if(cur==head)
    {
      //temp=
      head->prev=newnode;
      newnode->next=head;
      newnode->prev=NULL;
      head=newnode;
      return head;
    }

    else if(cur->next!=NULL)
   {
       temp=cur;
       cur->prev->next=newnode;
       newnode->next=cur;
       cur->prev=newnode;
       cur->next=temp->next;
       newnode->prev=temp->prev;
   }
   else
    {
        cur->next=newnode;
        newnode->prev=cur;
        newnode->next=NULL;
    }
   return head;

}


node *deletePOS(node *head)
{
    node *cur,*temp;
    int ele;
    cur=head;
    printf("Enter the element you want to delete:\n");
    scanf("%d",&ele);
    while(cur!=NULL)
    {
        if(cur->data!=ele)
            cur=cur->next;
        else
            break;
    }

    if(cur==NULL)
    {
        printf("Empty\n");
    }
    else if(cur->prev==NULL && cur->next==NULL)
    {
        free(cur);
        head=NULL;
    }
    else if(cur==head)
    {
        head=cur->next;
        free (cur);
        cur=head;
        cur->prev=NULL;
    }

    else if(cur->next==NULL)
    {
        temp=cur->prev;
        temp->next=NULL;
        //cur->prev->next=NULL;
        head=temp;
        free(cur);
    }
    else
    {
        temp=cur;
        cur->prev->next=cur->next;
        cur->next->prev=cur->prev;
        free(cur);
    }
    return head;
}

node *reverse(node *head)
{
   node *cur,*temp;
   cur=head;
   while(cur!=NULL)
   {
       temp=cur->prev;
       cur->prev=cur->next;
       cur->next=temp;
       cur=cur->prev;
   }
   if(temp!=NULL)
   {
       head=temp->prev;
   }
   return head;
}

main()
{
    node *head;
    //node *temp;
    head=NULL;
    //head2=NULL;
    int ch,done=1;
    while(done)
    {
    printf("1.Insert at end\n2.Delete end\n3.Display \n4.Insert beg\n5.Delete beg\n6.Delete position\n7.Insert position\n8.Reverse\n");
    printf("Enter the choice:\n");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1:head=insertEND(head);
                     break;
        case 2:head=deleteEND(head);
                     break;
        case 3:head=display(head);
               break;
        case 4:head=insertBEG(head);
               break;
        case 5:head=deleteBEG(head);
               break;
        case 6:head=deletePOS(head);
               break;
        case 7:head=insertPOS(head);
               break;
        case 8:head=reverse(head);
               break;
        default: done=0;
    }



    }
}





