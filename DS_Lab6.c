#include<stdio.h>
#include<math.h>

int LinearSearch(int*);

int main()
{
	int i,j, arr[100];
	for(i = 0;i < 100; i += 1) //100 iterations
	{
		arr[i] = rand() % 200 + 1; //random number between 1-200
	}
	
	//print array
	printf("The array values are:");
	for(i = 0;i < 100; i += 1)
	{
		if((i % 10) == 0)
		{
			printf("\n");
		}
		printf("%d\t", arr[i]);
	}
	printf("\n\n");
	
	LinearSearch(arr);
	
	return 0;
}

//100 random numbers searched in arr[]
int LinearSearch(int* arr)
{
	int i, j, search, search_count = 0, successful = 0, count,sum = 0, percent, avg_search;
	for(i = 0;i < 100; i += 1)
	{
		count = 0;
		search_count += 1;
		search = rand() % 200 + 1; //random search number
	
		//linear search
		for(j = 0;j < 100; j += 1) 
		{
			count += 1;
			if(arr[j] == search)
			{
				successful += 1;
				break;
			}
		}
		sum += count;
	}
	avg_search = sum/ search_count;
	percent = (successful * 100)/search_count;
	printf("Total Search: %d\nSuccessful Searches: %d\nPercentage of successful searches: %d\nAverage search count:%d\n", search_count, successful, percent, avg_search);
}



