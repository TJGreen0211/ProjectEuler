#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int p1 = 1;
int p2 = 2;
int p5 = 5;
int p10 = 10;
int p20 = 20;
int p50 = 50;
int p100 = 100;
int p200 = 200;

int calculateChange(int count);

int main()
{
	clock_t start,end;
	float time_spent;
	start=clock();

	int count = 0;
	int total;
	total = calculateChange(count);
	
	printf("%d\n", total);
	
	end=clock();
	time_spent=(((float)end - (float)start) / 1000000.0F );
	printf("\nSystem time is at %f\n seconds", time_spent);
}

int calculateChange(int count)
{

		for(int i = 200; i >= 0; i-=p200)
		{
			for(int j = i; j >= 0; j-=p100)
			{
				for(int k = j; k >= 0; k-=p50)
				{
					for(int l = k; l >= 0; l-=p20)
					{	
						for(int m = l; m >= 0; m-=p10)
						{
							for(int n = m; n >= 0; n-=p5)
							{	
								for(int o = n; o >= 0; o-=p2)
								{	
									count++;
								}
							}
						}	
					}
				}
			}
		}
	
	return count;	
}