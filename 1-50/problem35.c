#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int splitNum(int n, int iCount);
int factorial(int n);
int rotate(int *array, int count, int n, int iCount);
int *swap(int *array, int one, int two);
int checkPrimes(int *array, int len, int iCount);
void populatePrimes();

int totalSum = 0;
int topValue = 1000000;
int max = 100;
int *primeArray;
int digitArray[7] = {0};

int main() {
	clock_t start,end;
	float time_spent;
	start=clock();
	
	populatePrimes();
	printf("Total number of circular primes: %d\n", totalSum);
	
	end=clock();
	time_spent=(((float)end - (float)start) / 1000000.0F );
	printf("\nSystem time is at %f seconds\n", time_spent);
	return 0;
}

void populatePrimes() {
	int count = topValue - 1;
    int *array = calloc( topValue + 1, sizeof(int));
                                   
    for (int i = 2; i <= topValue; ++i) 
        array[i] = 1;

    for (int prime = 2; prime <= topValue; ++prime)
    {
        if (array[prime])
            for (int multiple = 2*prime; multiple <= topValue; multiple += prime)
                if (array[multiple]) 
                {
                    array[multiple] = 0;
                    --count;
               	}
    }
    primeArray = (int *)malloc(max * sizeof(int));
    int c = 0;
    for (int i = 2; i <= topValue; ++i)
    {
        if (array[i]){
        	if(count > max) {
        		max *= 2;
        		primeArray = (int *)realloc(primeArray, max * sizeof(int));
        	}
        	primeArray[c] = i;
        	c++;
        }
    }
    for(int i = 0; i < c; i++) {
    	//printf("%d\n",primeArray[i]);
		splitNum(primeArray[i], c);
	}
}

int splitNum(int n, int iCount) {
	int c = 0;
	int sum = 0;
	while(n > 0) {
		int digit = n%10;
		digitArray[c] = digit;
		n /= 10;
		c++;
	}
	if(rotate(digitArray, 1, c, iCount) == 1) {
		//for(int i = 0; i < c; i++) {
		//	printf("%d",digitArray[i]);
		//}
		totalSum++;
	}
	return sum;
}

int *leftRotatebyOne(int *arr, int n)
{
	int i, temp;
	temp = arr[0];
	for (i = 0; i < n-1; i++)
    	arr[i] = arr[i+1];
	arr[i] = temp;
	return arr;
}

int rotate(int *array, int count, int n, int iCount) {
	if(count == 0)
		return 1;
  	for (int i = 0; i < n; i++) {
    	array = leftRotatebyOne(array, n);
    	if(checkPrimes(array, n, iCount) == 0)
			return 0;
    }
	return 1;
}


int checkPrimes(int *array, int len, int iCount) {
	int mult = 1;
	int sum = 0;
	for(int i = 0; i < len; i++) {
		sum += mult*array[i];
		mult *= 10;
	}
	//printf("Sum: %d\n", sum);
	for(int i = 0; i < iCount; i++) {
		if(sum == primeArray[i]) {
			//printf("%d\n", primeArray[i]);
			return 1;
		}
	}
	return 0;
}