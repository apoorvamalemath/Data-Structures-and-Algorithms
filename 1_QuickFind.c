
#include<stdio.h>

/*
	Union - To connect i.e. to merge components.
	Find  - To check if connected or not.
	
	In every Union previously changed value must also be changed.

	
*/


void Connected(int a[10],int p, int q)
{
	if(a[p]==a[q])	
		printf("Connected\n");
	else
		printf("Not Connected\n");
}


void Union(int a[10], int p, int q)
{
	int pid=p;
	int qid=q;
	int i;
	for(i=0;i<10;i++)
	{
		if(a[i]==pid)
			a[i]=qid;
	}	
}

int main()
{
	int a[10];
	inr i;
	for(i=0;i<10;i++)
		a[i]=i;
	Union(a,1,2);
	Union(a,3,5);
	Union(a,1,5);
	Connected(a,1,2);
	Connected(a,7,8);
}
