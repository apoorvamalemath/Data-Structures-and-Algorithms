
#include<stdio.h>

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
	Union(a,1,2);
	Union(a,3,5);
	Union(a,1,5);
	Connected(a,1,2);
	Connected(a,7,8);
}
