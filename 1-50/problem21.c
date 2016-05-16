#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>



int divisors(int number);

int main()
{
	clock_t start,end;
	float time_spent;
	start=clock();
	
	int testNum;
	int iterations = 10000;
	int total = 0;
	int num[iterations][1];
	
	for(int i = 0; i < iterations; i++)
	{
		num[i][0] = divisors(i);
	}
	
	for(int i = 0; i < iterations; i++)
	{
		if(num[i][0] < iterations)
		{
			testNum = num[i][0];
			if(i == num[testNum][0] && testNum != num[testNum][0])
			{
				printf("%d, %d\n",testNum, num[testNum][0]);
				total += i;
			}
		}
	}
	
	printf("The total is: %d\n", total);
	
	end=clock();
	time_spent=(((float)end - (float)start) / 1000000.0F );
	printf("\nSystem time is at %f\n seconds", time_spent);
}

int divisors(int number)
{
	int sum = 0;
	for(int i = 1; i < (number/2)+1; i++)
	{
		if(number%i == 0)
		{
			sum+=i;
		}
	}
	return sum;
}