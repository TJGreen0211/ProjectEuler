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
	fp = fopen("/Users/tylergreen/Documents/Programming/ProjEuler/prob13.txt", "r");
	
	if(!fp)
   	{
      	printf("Error while opening the file.\n");
      	exit(1);
   	}
	int arrayPos = -1;
	int iPos = 0;
	int gridArray[100][50];// = malloc(count*sizeof(int));
	
	char line[5000];
	while (fgets(line, sizeof(line), fp) != 0)
	{
		char *str = line;
		int j;
		int pos;
		while (sscanf(str, "%1d%n", &j, &pos) == 1)
        {
            if(iPos%50 == 0)
            {
            	arrayPos++;
            	iPos=0;
            }
            gridArray[arrayPos][iPos] = j;
            iPos++;
            str += pos;
        }
	}
	fclose(fp);
	
	int remainder;
	int rowSum = 0;
	int sub = 0;
	int newArray[50];
	for(int i = 49; i >= 0; i--)
	{
		rowSum = 0;
		for(int j = 99; j >= 0; j--)
		{
			rowSum += gridArray[j][i];
		}
		rowSum = sub+rowSum;
		remainder = rowSum%10;
		sub = (rowSum - remainder)/10;
		if(i == 0)
			newArray[i] = rowSum;
		else
			newArray[i] = remainder;
	}
	
	for(int i = 0; i < 50; i++)
	{
		printf("%d",newArray[i]);
	}
	printf("\n");
	
	end=clock();
	time_spent=(((float)end - (float)start) / 1000000.0F ) * 1000;
	printf("System time is at %f\n ms", time_spent);
}