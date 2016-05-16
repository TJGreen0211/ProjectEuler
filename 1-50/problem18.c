#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int max(int one, int two);

int sumArray[15][15] = {
{75},
{95, 64},
{17, 47, 82},
{18, 35, 87, 10},
{20, 04, 82, 47, 65},
{19, 01, 23, 75, 03, 34},
{88, 02, 77, 73, 07, 63, 67},
{99, 65, 04, 28, 06, 16, 70, 92},
{41, 41, 26, 56, 83, 40, 80, 70, 33},
{41, 48, 72, 33, 47, 32, 37, 16, 94, 29},
{53, 71, 44, 65, 25, 43, 91, 52, 97, 51, 14},
{70, 11, 33, 28, 77, 73, 17, 78, 39, 68, 17, 57},
{91, 71, 52, 38, 17, 14, 91, 43, 58, 50, 27, 29, 48},
{63, 66, 04, 68, 89, 53, 67, 30, 73, 16, 69, 87, 40, 31},
{04, 62, 98, 27, 23, 9, 70, 98, 73, 93, 38, 53, 60, 04, 23}};


int main()
{
	clock_t start,end;
	float time_spent;
	start=clock();
	int tempArray[15] = {0};
	int count = 0;
	int firstCount = 1;
	
	for(int i = 14; i > 0; i--)
	{
		for(int j = 0; j < 14-count; j++)
		{
			if(firstCount == 1)
			{
				tempArray[j] = max(sumArray[i][j], sumArray[i][j+1])+sumArray[i-1][j];
			}
			else
			{
				tempArray[j] = max(tempArray[j], tempArray[j+1])+sumArray[i-1][j];
			}
		}
		firstCount = 0;
		count++;
	}
	printf("Final sum is: %d\n", tempArray[0]);
	
	end=clock();
	time_spent=(((float)end - (float)start) / 1000000.0F );
	printf("\nSystem time is at %f seconds\n", time_spent);
}


int max(int one, int two)
{
	if(one > two)
		return one;
	else
		return two;
}