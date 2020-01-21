#include<stdio.h>


/*
	Consider the array as a set of trees i.e. forest.
	Find - Check if they have same root.
	Union - Only one value changes i.e. set id of p's root to id of q's root

*/


int root(int a[10],int i)
{
	while(i!=a[i])
		i=a[i];
	return i;
}

void Connected(int a[10],int p, int q)
{
	if(root(a,p)==root(a,q))	
		printf("Connected\n");
	else
		printf("Not Connected\n");
}

void Union(int a[10],int p,int q)
{
	int i,j;
	i=root(a,p);
	j=root(a,q);
	a[i]=j;
}  

int main()
{
	int a[10];
	int i;
	for(i=0;i<10;i++)
		a[i]=i;
	Union(a,4,3);
	Union(a,3,8);
	Union(a,6,5);
	Union(a,9,4);
	Union(a,2,1);
	Connected(a,0,7);
	Connected(a,4,8);
}
