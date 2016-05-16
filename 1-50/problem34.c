#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int splitNum(int n);
int factorial(int n);

int factArray[9] = {0};
//Using precomputed factorials cuts time ~ 1/2
//int facts[] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};

int main() {
	clock_t start,end;
	float time_spent;
	start=clock();
	
	int upperLimit = 7*factorial(9);
	int totalSum = 0;
	int compare;
	for(int i = 144; i < upperLimit; i++) {
		compare = splitNum(i);
		if(compare == i) {
			totalSum += i;
		}
	}
	printf("Num: %d\n", totalSum);
	
	end=clock();
	time_spent=(((float)end - (float)start) / 1000000.0F );
	printf("\nSystem time is at %f seconds\n", time_spent);
	return 0;
}

int splitNum(int n) {
	int c = 0;
	int sum = 0;
	while(n > 0) {
		int digit = n%10;
		n /= 10;
		factArray[c] = digit;
		c++;
	}
	for(int i = 0; i < c; i++) {
		sum += factorial(factArray[i]);
		//sum += facts[factArray[i]];
	}
	return sum;
}

int factorial(int n) {
	int sum = 1;
	for(int i = 1; i <= n; i++) {
		sum *= i; 
	}
	return sum;
}