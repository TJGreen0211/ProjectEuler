#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int primeFactors(int n);

int main()
{
	clock_t start,end;
	float time_spent;
	start=clock();
	
	int triNum = 0;
	int factors;
	int num = 2;
	int isTrue = 1;
	
	while(isTrue == 1){
		for(int i = 1; i < num; i++)
		{
			triNum+=i;
		}
		
		factors = primeFactors(triNum);
		if(factors > 500)
		{
			printf("Factors: %d\n", factors);
			printf("Factor Number: %d\n", triNum);
			isTrue = 0;
		}
		
		num++;
		triNum=0;
	}
	
	end=clock();
	time_spent=(((float)end - (float)start) / 1000000.0F );
	printf("\nSystem time is at %f seconds\n", time_spent);
}

int primeFactors(int n)
{
	int numFactors = 0;
	int primePower = 0;
	
	while(n%2 == 0)
	{
		n = n/2;
		primePower++;
	}
	numFactors = (primePower+1);
	for(int i = 3; i <= sqrt(n); i+=2)
	{
		primePower = 0;
		while(n%i == 0)
		{
			n = n/i;
			primePower++;
		}
		numFactors = numFactors*(primePower+1);
	}
	if(n > 2)
		numFactors = numFactors*2;
	return numFactors;
}