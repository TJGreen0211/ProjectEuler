#include <stdio.h>
#include <math.h>

typedef int bool;
#define true 1
#define false 0
	
int main()
{
	long int n = 600851475143;
	int z = 2;
	//int final = 0;
	while(z * z <= n)
	{
		if(n % z == 0)
		{
			printf("%d\n", z);
			n /= z;
		}
		else z++;
	}
	if(n > 1)
	{
		printf("%ld", n);
	}
	
}