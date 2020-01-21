#include<stdio.h>

struct NODE
{
    int info;
    struct NODE *next;
};
static int count=0;
typedef struct NODE node;
//node *n,*head;
/*node getnode()
{
    node *p;
    p=(node*)malloc(sizeof(node));
    //p->next=NULL;
    return p;
}*/


void printList(node **head)
{
  node *cur=*head;
  if(*head==NULL)
    {
        printf("List is empty!!");
    }
    else
    {


  while (cur!= NULL)
  {
     printf(" %d ", cur->info);
     cur = cur->next;
  }
    }
}


void InsertNode(node **head)
{
    int num;
    node *newnode;
    node *current;
    newnode=(node*)malloc(sizeof(struct NODE));
    printf("Enter data:");
    scanf("%d",&num);
    newnode->info=num;
    newnode->next=NULL;
    count++;
    if(*head==NULL)        //If list is empty
    {
        //newnode->next=NULL;
        *head=newnode;
    }
    else
    {
        current=*head;
        while(current->next!=NULL)
        {
          current=current->next;

        }
        current->next=newnode;
        newnode->next=NULL;
        //*head=newnode;
        //*head=newnode;
    }
    //return (newnode);
   //printf("\n%d",newnode->info);
}
/*int getF(node **head)
{
     node *pre;
  node *cur;
  //node *n;
  cur=*head;
  if(*head==NULL)
    {
        printf("The list is empty!!");
        return;
    }
    else if(cur->next==NULL)
    {
        return cur->info;
        free(cur);
        *head=NULL;
    }
    else
    {
        return cur->info;
        cur=cur->next;
        *head=cur;
    }
}
int getB(node **head)
{
  node *pre;
  node *cur;
  //node *n;
  cur=*head;
  if(*head==NULL)
    {
        printf("The list is empty!!");
        return;
    }
    else if(cur->next==NULL)
    {
         return(cur->info);
         free(cur);
        *head=NULL;
    }
    else
    {
        for(pre=NULL,cur=*head;cur->next!=NULL;pre=cur,cur=cur->next);
        pre->next=NULL;
        return cur->info;
        free(cur);
    }
}
void pallin(node **head)
{
    node *cur;
    cur=*head;
    int l,f;
    int flag=0;
    while(cur!=NULL)
    {
        l=getB(*head);
        f=getF(*head);
        if(l!=f)
        {
            flag=1;
        }
    }
  if(flag==1)
    printf("Not pallindrome\n");
  else
    printf("Pallindrome\n");
}*/
void pallin(node **head)
{
  node *last,*prev,*first,*cur;
  cur=*head;
  last=*head;
  first=*head;
  int flag=0;
  while(cur!=NULL)
  {
      first=cur;
      last=cur;
      while(last->next!=NULL)
      {
          prev=last;
          last=last->next;
      }
      if(first->info!=last->info)
    {
        flag=1;
        break;
    }
    prev->next=NULL;
    free(last);
    cur=cur->next;
  }
  if(flag==1)
    printf("NOT\n");
  else
    printf("Pallin\n");
}


main()
{
    node *n;
    //node *newnode;
    node *head=NULL;
    int done=0;
    int ch;
    while(done==0)
    {
        printf("\nEnter the choice: \n1.Insert\n2.pallin \n3.Display\n");
        scanf("%d",&ch);
        switch(ch)
        {
           case 1: InsertNode(&head);
                   break;
           case 2:pallin(&head);
                   break;
           case 3:printList(&head);
                  break;
           case 4: done=1;
                   break;
           /* case 5: getF(&head);
                    break;
            case 6:getB(&head);
                break;*/
        }
    }

}

