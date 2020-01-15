#include<stdio.h>

void selectionsort(int a[5])
{
	int min,i,j;
	int temp;
	for(i=0;i<5;i++)
	{
		min=i;
		for(j=i+1;j<5;j++)
		{	
			if(a[j]<a[min])
				min=j;
		}
	//swap
		temp=a[i];
		a[i]=a[min];
		a[min]=temp;
	}

}

int main()
{
	int a[5]={3,4,5,1,2};
	selectionsort(a);
	int i;
	for(i=0;i<5;i++)
		printf("%d\t",a[i]);
	printf("\n");
	
}
