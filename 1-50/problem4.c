#include <stdio.h>
#include <math.h>

typedef int bool;
#define true 1
#define false 0
	
	
int palindrome(num)
{
	int rem;
	int reverse = 0;
	int temp = num;
	while( temp != 0 )
   	{
		rem = temp%10;
      	reverse = reverse * 10 + rem;
     	temp /= 10;
   	}
   	return reverse;
}

int main()
{
	int reverse;
	int num;
	int final = 0;
	
	for(int i = 100; i < 999; i++)
	{
		for(int j = 100; j < 999; j++)
		{
			num = i * j;
			
			reverse = palindrome(num);
   			
   			
   			if(num == reverse)
   			{
   				if(num > final)
   				{
   					final = num;
   				}
   			}
   			reverse = 0;
		}
	}
	printf("The palindrome is %d\n", final);
	
}

