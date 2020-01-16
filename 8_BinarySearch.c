#include<stdio.h>

// To find element x
int BinarySearch(int a[], int l, int h, int x)
{
	if(h>=l)
	{
		int mid = l+(h-l)/2;
		if(a[mid]==x)
			return mid;
		if(a[mid]>x)
			return BinarySearch(a,l,mid-1,x);
		 
		
		return BinarySearch(a,mid+1,h,x);

	}	
	
	return -1; //if not found

}


  
int main(void) 
{ 
    int arr[] = { 2, 3, 4, 10, 40 }; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    int x = 20; 
    int result = BinarySearch(arr, 0, n - 1, x); 
    (result == -1) ? printf("Element is not present in array\n") 
                   : printf("Element is present at index %d\n", 
                            result); 
    
    x=40;
    result = BinarySearch(arr, 0, n - 1, x); 
    (result == -1) ? printf("Element is not present in arrayn\n") 
                   : printf("Element is present at index %d\n", 
                            result); 
   return 0; 
} 
