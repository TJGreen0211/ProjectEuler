#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

typedef int bool;
#define true 1
#define false 0

int main()
{
	clock_t start,end;
	float time_spent;
	start=clock();
    int top_value = 2000000;
    int count = top_value - 1;
    
    int *array = calloc( top_value + 1, sizeof(int));
    int i, prime, multiple;
                                   
    for (i=2; i <= top_value; ++i) 
        array[i] = 1;

    for (prime = 2; prime <= top_value; ++prime)
    {
        if (array[prime])
            for (multiple = 2*prime; multiple <= top_value; multiple += prime)
                if (array[multiple]) 
                {
                    array[multiple] = 0;
                    --count;
               	}
    }

	long long int sum = 0;
    for (i=2; i <= top_value; ++i)
    {
        if (array[i]){
            sum += i;
            printf("%d ", i);
        }
    }
    
    printf("\n\n%d primes up to %d found.\n", count, top_value);
    printf("Sum is %lld \n", sum);
    end=clock();
    
	time_spent=(((float)end - (float)start) / 1000000.0F ); 
    printf("Count is at %d, system time is at %f\n s", count, time_spent);

 }
