#include<stdio.h>

void insertionsort(int a[5])
{
	int min,i,j;
	int temp;
	for(i=0;i<5;i++)
	{
		for(j=i;j>0;j--)
		{	
			if(a[j]<a[j-1])
			{
				//swap
				temp=a[j];
				a[j]=a[j-1];
				a[j-1]=temp;			
			}
			else
				break;
		}

	}

}

int main()
{
	int a[5]={3,4,5,1,2};
	insertionsort(a);
	int i;
	for(i=0;i<5;i++)
		printf("%d\t",a[i]);
	printf("\n");
	
}
