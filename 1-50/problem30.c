#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int upperBound = 354294; //6*9^5
int powArray[6] = {0};

int main() {
	clock_t start,end;
	float time_spent;
	start=clock();
	
	int totalSum = 0;
	for(int i = 2; i < upperBound; i++) {
		int count = 0;
		int num = i;
		while(num > 0) {
			int digit = num % 10;
			num /= 10;
			powArray[count] = digit;
			count++;
		}
		//printf("Number: %d\n", i);
		
		int powNum = 0;
		//int power = 1;
		for(int j = 0; j < 6; j++) {
			powNum += pow(powArray[j], 5);
		}
		//printf("Number: %d, Power: %d\n", i, powNum);
		if(powNum == i) {
			printf("Number: %d, power: %d\n", i, powNum);
			totalSum += i;
		}
	}
	printf("Total sum: %d\n", totalSum);
	
	end=clock();
	time_spent=(((float)end - (float)start) / 1000000.0F );
	printf("\nSystem time is at %f seconds\n", time_spent);
	return 0;
}