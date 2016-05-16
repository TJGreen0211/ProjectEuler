#include <stdio.h>
#include <math.h>

typedef int bool;
#define true 1
#define false 0
	
int main()
{
	int aSquare, bSquare, cSquare;
	
	for(int i = 1; i < 1001; i++)
	{
		aSquare = i * i;
		for(int j = 2; j < 1001; j++)
		{
			bSquare = j * j;
			for(int k = 3; k < 1001; k++)
			{
				cSquare = k*k;
				if(aSquare + bSquare == cSquare)
					if(i + j + k == 1000)
					{
						printf("The numbers are %d, %d, %d\n", aSquare, bSquare, cSquare);
						printf("The numbers are %d, %d, %d\n", i, j, k);
						printf("%d\n", i*j*k);
					}
			}
		}
	}
	
}