#include<stdio.h> 

int countClumps(int arr1[], int m) 
{
  int i,n;
  int l = m;
  int current = -1, clump = 0;
 for(i = 0; i < l - 1; i++) 
  {
    if(arr1[i] == arr1[i + 1] && arr1[i] != current) 
	{
       current = arr1[i];
       clump++;
    } 
	else 
	{
       if(arr1[i] != current) 
	   {
          current = -1;
       }
    }
  }
  return clump;
}
int main() 
{ 
    int arr1[] = {22, 12, 12, 12, 44, 44, 17, 17, 11}; 
    int arr_size = sizeof(arr1)/sizeof(arr1[0]); 
    int i = 0; 
   //------------- print original array ------------------	
	printf("The given array is:  \n\n");
	for(i = 0; i < arr_size; i++)
		{
			printf("%d  ", arr1[i]);
		}
	printf("\n\n");


    printf("Number of CLUMPS in the array is:  %d \n", countClumps(arr1,arr_size)); 
    return 0; 
}

