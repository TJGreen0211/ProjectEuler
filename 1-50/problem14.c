#include <stdio.h>
#include <math.h>
#include <time.h>

typedef int bool;
#define true 1
#define false 0
	
int main()
{
	int finalCount = 0;
	int final;
	for(unsigned long long int i = 13; i < 1000000; i++)
	{
		unsigned long long int temp = i;
		
		int count = 0;
		while(temp != 1)
		{
			if(temp%2 == 0)
				temp = temp/2;
			else
				temp = 3*temp + 1;
			count++;
		}
		if(finalCount < count)
		{
			finalCount = count;
			final = i;
		}
		printf("The final count is at %llu\n", i);
	}
	printf("Longest Collatz Sequence is %d, number is %d\n", finalCount, final);
}