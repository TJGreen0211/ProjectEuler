#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main()
{
	int count = 1;
	int totalSum = 1;
	int final = 1;
	
	clock_t start,end;
	float time_spent;
	start=clock();
	
	while(totalSum < pow(1001, 2))
	{
		for(int i = 0; i < 4; i++)
		{
			totalSum += count+1;
			final += totalSum;
			printf("TotalSum: %d\n", totalSum);
		}
		count+=2;
	}
	
	printf("The diagonal sum is: %d\n", final);
	
	end=clock();
	time_spent=(((float)end - (float)start) / 1000000.0F );
	printf("\nSystem time is at %f\n seconds", time_spent);
}