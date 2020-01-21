#include<stdio.h>

void swap(int *a, int *b)
{
	int temp=*a;
	*a=*b;
	*b=temp;
}

//place smaller elements to the left of pivot, and greater right of pivot
int partition(int a[], int low, int high)
{
	int pivot= a[high];
	int i=low-1;
	
	for(int j=low;j<=high-1;j++)
	{
		if(a[j]<=pivot)
		{
			i++;
			swap(&a[i],&a[j]);

		}
	}
	swap(&a[i+1],&a[high]);
	return (i+1);

}	


void quicksort(int a[], int low, int high)
{
	if(low<high)
	{
		int pi=partition(a,low,high);
		quicksort(a,low,pi-1);
		quicksort(a,pi+1,high);
	
	}

}

int main()
{
	int a[5]={3,4,5,1,2};
	quicksort(a,0,4);
	int i;
	for(i=0;i<5;i++)
		printf("%d\t",a[i]);
	printf("\n");
	
}
