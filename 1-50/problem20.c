#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>


int main()
{
	clock_t start,end;
	float time_spent;
	start=clock();

	int totalSum = 0;
	int iterations = 100;
	int remainder = 0;
	int carry = 0;
	int a1[500]= {0};
	int temp[500] = {0};
	a1[499] = iterations;
	int count = iterations;
	
	for(int j = 0; j < iterations-1; j++)
	{
		for(int k = 0; k < 500; k++)
			temp[k] = a1[k];
		for(int l = 0; l < count-2; l++)
		{	
			for(int i = 499; i >= 0; i--)
			{
				a1[i] = a1[i]+temp[i]+carry;
				remainder = a1[i]%10;
				carry = (a1[i] - remainder)/10;
				a1[i] = remainder;
				a1[i-1] += carry;
				carry=0;
			}
		}
		count--;
	}
	
	for(int i = 0; i < 500; i++)
	{
		totalSum+=a1[i];
		//printf("%d\n",a1[i]);
	}
	
	printf("Total Sum: %d\n", totalSum);
	
	end=clock();
	time_spent=(((float)end - (float)start) / 1000000.0F );
	printf("\nSystem time is at %f\n seconds", time_spent);
}