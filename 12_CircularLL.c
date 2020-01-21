
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
        newnode->next=head;
    }
    else
    {
       do
        {
            cur=cur->next;
        } while(cur->next!=head);
        cur->next=newnode;
        newnode->next=head;
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
        newnode->next=head;
    }
    else
    {
        newnode->next=cur;
        while(cur->next!=head)
        {
            cur=cur->next;
        }
        head=newnode;
        cur->next=head;
    }

    return head;
}

node *deleteBEG(node *head)
{
    int num;
    node *cur,*temp,*newnode;
    temp=head;
    //printf("DEL\n");
    cur=head;
     while(cur->next!=head)
    {
        cur=cur->next;
    }
    //printf("DEL2\n");
    head=temp->next;
    printf("%d is deleted\n",temp->data);
    cur->next=head;
    free(temp);
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
        //return head;
    }
    if(cur->next==head)
    {
        head=NULL;
        num=cur->data;
        printf("%d is deleted \n",num);
        free(cur);

    }
    else
    {
   do
    {
        prev=cur;
        cur=cur->next;
    } while(cur->next!=head);
    num=cur->data;
    printf("%d is deleted \n",num);
    prev->next=head;
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
       do
        {
            prev=cur;
            cur=cur->next;
            count++;
         if(count==pos)
        {
            prev->next=newnode;
            newnode->next=cur;
        }
        } while(cur!=head);
    }
    return head;
}

node *reverse(node *head)
{
    node *t1,*t2,*t3,*cur;
    t1=head;

    if(head==NULL||t1->next==head)
        return head;
    else
    {
        t1=head;
        t2=t1->next;
        t3=t2->next;
        while(t2!=head)
        {
            t2->next=t1;
            t1=t2;
            t2=t3;
            if(t3!=head)
                t3=t3->next;
        }
    head->next=NULL;
    head=t1;
    cur=head;
    while(cur->next!=NULL)
    {
        cur=cur->next;
    }
    cur->next=head;

    return head;
  }
}

node *deletePOS(node *head)
{
    node *cur,*temp,*temp2;
    int count=1,i,pos;
    cur=head;
    temp=head;
    printf("Enter the position:\n");
    scanf("%d",&pos);
    if(pos==1)
    {
      temp2=head;
      temp=cur->next;
      while(cur->next!=head)
      {
          cur=cur->next;
      }
      cur->next=temp;
      head=temp;
      free(temp2);
      return head;
    }
    else
    {
        cur=head;
        for(i=1;i<pos;i++)
        {
            temp=cur;
            cur=cur->next;
        }
        temp->next=cur->next;
        free(cur);
        return head;
    }
}

node *display(node *head)
{
    node *cur;
    cur=head;
    if(cur==NULL)
    {
        printf("Empty\n");
    }

    do
    {
        printf("%d\t",cur->data);
        cur=cur->next;
    }while(cur!=head);
    printf("\n");
    return head;
}

main()
{
    node *head;
    //node *temp;
    head=NULL;
    int ch,done=1;
    while(done)
    {
    printf("1.Insert at rear\n2.Delete rear\n3.Display\n4.Insert beg\n5.Delete beg\n6.Insert position\n7.Reverse\n8.Delete Position\n");
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
        case 4:head=inserBEG(head);
               break;
        case 5:head=deleteBEG(head);
                break;
        case 6:head=insertPOS(head);
               break;
        case 7:head=reverse(head);
               break;
        case 8:head=deletePOS(head);
               break;
        default: done=0;
    }



    }
}
