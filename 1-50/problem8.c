#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

typedef int bool;
#define true 1
#define false 0

int main()
{
	int *intArray = malloc(1000 * sizeof(int));
	FILE *fp;
	fp = fopen("/Users/tylergreen/Desktop/ProjEuler/prob8.txt", "r");
	int i = 0;
	int num;
	while(fscanf(fp, "%1d", &num) > 0) {
        intArray[i] = num;
        i++;
    }
    fclose(fp);

    
    long long int sum = 1;
    long long int final = 0;
    for(int j = 0; j < 1000-13; j++)
    {
    	for(int k = j; k < j + 13; k++)
    	{
    		sum *= intArray[k];
    	}
    	if(final < sum)
    		final = sum;
    	printf("%lld\n", sum);
    	sum = 1;
    	
    }
    printf("Final is %lld", final);
    
    free(intArray);
	
}

/*
clock_t start,end;
float time_spent;
start=clock();
end=clock();
time_spent=(((float)end - (float)start) / 1000000.0F ) * 1000;
*/