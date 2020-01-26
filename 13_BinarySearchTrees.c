#include<stdio.h>

struct tree
{
    int data;
    struct tree *right;
    struct tree *left;
};

typedef struct tree tree;

tree *maketree(tree *root,int num)
{
    if(root==NULL)
    {
        root=(tree*)malloc(sizeof(tree));
        root->data=num;
        root->right=root->left=NULL;
    }
    else if(num==root->data)
    {
        printf("Duplicate entry\n");
       // return;
    }
    else if(num<root->data)
        root->left=maketree(root->left,num);
    else
        root->right=maketree(root->right,num);
    return root;
}

int search(tree *root,int key)
{
    if(root==NULL)
        return 0;
    else if(root->data==key)
        return 1;
    else if(key<root->data)
        return(search(root->left,key));
    else
        return(search(root->right,key));

}

tree *keyinsert(tree *root,int key)
{
    int found;
    found=search(root,key);
    if(found)
        printf("Duplicate \n");
    else
    {
        printf("Key inserted\n");
        root=maketree(root,key);
    }
    return root;
}

void inorder(tree *root)
{
    if(root)
    {
        inorder(root->left);
        printf("%d",root->data);
        inorder(root->right);
    }
}


void *postorder(tree *root)
{
    if(root)
    {
      postorder(root->left);
      postorder(root->right);
      printf("%d \t",root->data);
    }
    return(root);
}

void *preorder(tree *root)
{
    if(root)
    {
        printf("%d \t",root->data);
        preorder(root->left);
        preorder(root->right);
    }
    //return(root);
}

int height(tree **root)
{
    int lh,rh;
    if(*root==NULL)
    return 0;
    else
    {
        lh=height(&((*root)->left));
        rh=height(&((*root)->right));
    //}
        if(lh>rh)
            return lh+1;
        else
            return rh+1;
    }
}



main()
{
    tree *root=NULL;
    int h;
    int ch,done=1,num,key;
    while(done)
    {
        printf("\n1.Insert\n2.Search\n3.Key insert\n4.Inorder\n5.Preorder\n6.Postorder\n7.Height\n8.Delete");
        printf("Enter your choice :\n");
        scanf("%d",&ch);
        switch(ch)
        {
           case 1:printf("Enter the element:\n");
                  scanf("%d",&num);
                  root=maketree(root,num);
                  break;
           case 2:printf("Enter the key:\n");
                  scanf("%d",&key);
                  num=search(root,key);
                  if(num==1)
                    printf("Element is found\n");
                  else
                    printf("Element is not found\n");
                  break;
           case 3:printf("Enter the key:\n");
                  scanf("%d",&key);
                  num=keyinsert(root,key);
                  break;
           case 4:printf("Inorder:\n");
                  inorder(root);
                  break;
           case 5:printf("Preorder\n");
                  preorder(root);
                  break;
           case 6:printf("Postorder:\n");
                  postorder(root);
                  break;
           case 7:h=height(&root);
                  printf("%d is the height\n",h);
                   break;
           case 8:printf("Enter the key to be deleted:\n");
                  scanf("%d",&h);
                  //root=deletenode(root,h);
                  break;
           default:done=0;
        }
    }
}
