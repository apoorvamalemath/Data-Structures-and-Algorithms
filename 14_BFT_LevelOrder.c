#include<stdio.h>

// Breadth First Traversal -- Level Order Traversal

struct node
{
	int data;
	struct node* right, *left;
};

struct node* newNode(int data)
{
	struct node* node=(struct node*)malloc(sizeof(struct node));
	node->data = data;
	node->left = NULL;
	node->right = NULL;

}

int height(struct node* node)
{
	if(node==NULL)
		return 0;
	else
	{
		int lheight= height(node->left);
		int rheight = height(node->right);
		
		if(lheight>rheight)
			return lheight+1;
		else
			return rheight+1;
	}

}

void BFS(struct node* root)
{
	int h= height(root);
	for(int i=1;i<=h;i++)
		printGivenLevel(root,i);
	
}

void printGivenLevel(struct node* root, int level)
{
	if(root==NULL)
		return;
	if(level == 1)
		printf("%d ",root->data);
	else if(level > 1)
	{
		printGivenLevel(root->left, level-1);
		printGivenLevel(root->right, level-1);
	}

}


void main()
{
	struct node *root = newNode(1);
	root->left =newNode(2);
	root->right =newNode(3);
	root->left->left =newNode(4);
	root->right->right = newNode(5);

	BFS(root);
}	




















