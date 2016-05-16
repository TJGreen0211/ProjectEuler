#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>


int main()
{
	clock_t start,end;
	float time_spent;
	start=clock();
	
	FILE *fp;
	fp = fopen("/Users/tylergreen/Documents/Programming/ProjEuler/Solved/prob11.txt", "r");
	
	if(!fp)
   	{
      	printf("Error while opening the file.\n");
      	exit(1);
   	}
   	char ch;
	int x;

	int arrayPos = -1;
	int iPos = 0;
	int gridArray[20][20];// = malloc(count*sizeof(int));
	
	while((ch = fgetc(fp)) != EOF)
	{
		if(iPos%20 == 0)
		{
			arrayPos++;
			iPos = 0;
		}
		fscanf(fp, "%d", &x);
		gridArray[arrayPos][iPos] = x;
		iPos++;
	}
	fclose(fp);
	
	int sum1, sum2, sum3, sum4 = 0; 
	int total1, total2, total3, total4 = 0;
	
	for(int i = 0; i < 16; i++)
	{
		for(int j = 0; j < 20; j++)
		{
			sum1 = gridArray[i][j]*gridArray[i+1][j]*gridArray[i+2][j]*gridArray[i+3][j];
			if(sum1 > total1)
				total1 = sum1;
		}
	}
	
	for(int i = 0; i < 20; i++)
	{
		for(int j = 0; j < 16; j++)
		{
			sum2 = gridArray[i][j]*gridArray[i][j+1]*gridArray[i][j+2]*gridArray[i][j+3];
			if(sum2 > total2)
				total2 = sum2;
		}
	}
	
	for(int i = 0; i < 16; i++)
	{
		for(int j = 0; j < 16; j++)
		{
			sum3 = gridArray[i][j]*gridArray[i+1][j+1]*gridArray[i+2][j+2]*gridArray[i+3][j+3];
			if(sum3 > total3)
				total3 = sum3;
		}
	}
	
	for(int i = 3; i < 20; i++)
	{
		for(int j = 0; j < 16; j++)
		{
			sum4 = gridArray[i][j]*gridArray[i-1][j+1]*gridArray[i-2][j+2]*gridArray[i-3][j+3];
			if(sum4 > total4)
				total4 = sum4;
		}
	}

	printf("Total1 %d\n", total1);
	printf("Total2 %d\n", total2);
	printf("Total3 %d\n", total3);
	printf("Total4 %d\n", total4);
	end=clock();
	time_spent=(((float)end - (float)start) / 1000000.0F ) * 1000;
	printf("System time is at %f\n ms", time_spent);
}



/*
clock_t start,end;
float time_spent;
start=clock();
end=clock();
time_spent=(((float)end - (float)start) / 1000000.0F ) * 1000;
*/