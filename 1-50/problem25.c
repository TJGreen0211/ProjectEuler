#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main()
{
	clock_t start,end;
	float time_spent;
	start=clock();
	
	int fibStart = 1;
	
	int remainder = 0;
	int carry = 0;
	int a1[1000] = {0};
	int a2[1000] = {0};
	int temp[1000] = {0};
	a1[999] = fibStart;
	int count = 1;
	int isTrue = 1;
	
	while(isTrue == 1)
	{
		for(int k = 0; k < 1000; k++)
			a2[k] = a1[k];
		for(int i = 999; i >= 0; i--)
		{
			a1[i] = a1[i]+temp[i]+carry;
			remainder = a1[i]%10;
			carry = (a1[i] - remainder)/10;
			a1[i] = remainder;
			a1[i-1] += carry;
			carry=0;
		}
		for(int k = 0; k < 1000; k++)
			temp[k] = a2[k];
		count++;
		if(a1[0] > 0)
		{
			printf("Index is %d\n", count);
			isTrue = 0;
		}
	}
	
	end=clock();
	time_spent=(((float)end - (float)start) / 1000000.0F );
	printf("\nSystem time is at %f\n seconds", time_spent);
}