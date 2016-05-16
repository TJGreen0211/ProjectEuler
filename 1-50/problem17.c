#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int primeFactors(int n);
int one = 3;
int two = 3;
int three = 5;
int four = 4;
int five = 4;
int six = 3;
int seven = 5;
int eight = 5;
int nine = 4;
int ten = 3;
int eleven = 6;
int twelve = 6;
int thirteen = 8;
int fourteen = 8;
int fifteen = 7;
int sixteen = 7;
int seventeen = 9;
int eighteen = 8;
int nineteen = 8;
int twenty = 6;
int thirty = 6;
int forty = 5;
int fifty = 5;
int sixty = 5;
int seventy = 7;
int eighty = 6;
int ninety = 6;
int hundred = 7;
int and = 3;
int thousand = 8;

int modOneSum(int i);
int modTenSum(int i);
int modHundredSum(int i);

int main()
{
	clock_t start,end;
	float time_spent;
	start=clock();
	
	int totalSum = 0;
	
	for(int i = 1; i <= 1000; i++)
	{
		if(i < 20)
			totalSum += modOneSum(i);
		if(i > 19 && i < 100)
			totalSum += modTenSum(i);
		if(i > 99)
			totalSum += modHundredSum(i);
		printf("Total sum is: %d, %d\n", totalSum, i);
	}
	totalSum += one+thousand;
	
	printf("Total sum is: %d\n", totalSum);
	
	end=clock();
	time_spent=(((float)end - (float)start) / 1000000.0F );
	printf("\nSystem time is at %f seconds\n", time_spent);
}

int modOneSum(int i)
{
	int totalSum;
	if(i == 1)
		totalSum = one;
	if(i == 2)
		totalSum = two;
	if(i == 3)
		totalSum = three;
	if(i == 4)
		totalSum = four;
	if(i == 5)
		totalSum = five;
	if(i == 6)
		totalSum = six;
	if(i == 7)
		totalSum = seven;
	if(i == 8)
		totalSum = eight;
	if(i == 9)
		totalSum = nine;
	if(i == 10)
		totalSum = ten;
	if(i == 11)
		totalSum = eleven;
	if(i == 12)
		totalSum = twelve;
	if(i == 13)
		totalSum = thirteen;
	if(i == 14)
		totalSum = fourteen;
	if(i == 15)
		totalSum = fifteen;
	if(i == 16)
		totalSum = sixteen;
	if(i == 17)
		totalSum = seventeen;
	if(i == 18)
		totalSum = eighteen;
	if(i == 19)
		totalSum = nineteen;
	//printf("TOTALSUM1 %d, %d\n", totalSum, i);
	return totalSum;
	
}

int modTenSum(int i)
{
	int totalSum = 0;
	int temp;
	temp = i%10;
	int val = i - temp;
	if(val == 20)
		totalSum = twenty+modOneSum(temp);
	if(val == 30)
		totalSum = thirty+modOneSum(temp);
	if(val == 40)
		totalSum = forty+modOneSum(temp);
	if(val == 50)
		totalSum = fifty+modOneSum(temp);
	if(val == 60)
		totalSum = sixty+modOneSum(temp);
	if(val == 70)
		totalSum = seventy+modOneSum(temp);
	if(val == 80)
		totalSum = eighty+modOneSum(temp);
	if(val == 90)
		totalSum = ninety+modOneSum(temp);
	//printf("TOTALSUM10 %d, %d\n", totalSum, i);
	return totalSum;
}

int modHundredSum(int i)
{
	int totalSum;
	int temp = i%100;
	int val = i - temp;
	if(val == 100)
		totalSum = one+hundred+and+modTenSum(temp);
	if(val == 200)
		totalSum = two+hundred+and+modTenSum(temp);
	if(val == 300)
		totalSum = three+hundred+and+modTenSum(temp);
	if(val == 400)
		totalSum = four+hundred+and+modTenSum(temp);
	if(val == 500)
		totalSum = five+hundred+and+modTenSum(temp);
	if(val == 600)
		totalSum = six+hundred+and+modTenSum(temp);
	if(val == 700)
		totalSum = seven+hundred+and+modTenSum(temp);
	if(val == 800)
		totalSum = eight+hundred+and+modTenSum(temp);
	if(val == 900)
		totalSum = nine+hundred+and+modTenSum(temp);
	//printf("TOTALSUM100 %d, %d\n", totalSum, i);
	return totalSum;
}