#include<stdio.h>
int main()
{
	int arr[20],i,size;
	int greater,smaller;
	
	printf("enter no of elements: ");
	scanf("%d", &size);
	
	printf("enter %d elements are: \n", size);
	
	for(i=0;i<size;i++)
	
	//creating the array
	
	scanf("%d", &arr[i]);
	greater = arr[0];
	   
	for(i=1;i<=size;i++)
	{
		if(arr[i] > greater)
	   	{
	   		greater= arr[i];
	   		printf("position of max value in array is : %d \n", i);
		}
	}
	printf("\n Max value in array is : %d", greater);
	   
	   
	   
	   return 0;
}
