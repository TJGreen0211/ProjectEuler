#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int factorial(int number);

int main()
{	
	clock_t start,end;
	float time_spent;
	start=clock();
	
	int array[15] = {0};
	int arrayPos = 0;
	int count = 1;
	int lpm = 1000000;
	int offset = 0;
	int arrayPerm[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	
	for(int i = 9; i > 0; i--)
	{
		while(factorial(i)*count < lpm)
		{
			count++;
		}
		lpm = lpm-factorial(i)*(count-1);
		array[arrayPos] = arrayPerm[count-1];
		for(int j = count-1; j < 10; j++)
			arrayPerm[j] = arrayPerm[j+1];
		offset++;
		arrayPos++;
		count = 1;
	}
	printf("The millionth lexicographic permutation is: ");
	for(int i = 0; i < 10; i++)
		printf("%d", array[i]);
	
	end=clock();
	time_spent=(((float)end - (float)start) / 1000000.0F );
	printf("\nSystem time is at %f\n seconds", time_spent);
}

int factorial(int number)
{
	int temp = number;
	for(int i = number; i > 1; i--)
	{
		temp = temp*(i-1);
	}
	return temp;
}