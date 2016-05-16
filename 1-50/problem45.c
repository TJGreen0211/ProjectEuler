#include <stdio.h>
#include <math.h>
#include <time.h>

typedef int bool;
#define true 1
#define false 0
	
int main()
{
	unsigned long long int tri, hex, pent;
	for(unsigned long long int i = 1; i < 300000; i++)
	{
		tri = (i*(i+1))/2;
		for(unsigned long long int j = 1; j < 300000; j++)
		{
			pent = (j*(3*j-1))/2;
			if(tri == pent)
			{
			for(unsigned long long int k = 1; k < 300000; k++)
			{
				hex = k*(2*k-1);
				if(tri == pent && tri == hex){
					printf("%llu\n", tri);}
			}
			}
		}
	}
}

/*
int triangle(n)
{
	int tri;
	tri = (n*(n+1))/2;
	return tri;
}

int pentagon(n)
{
	int pent;
	pent = (n*(3*n-1))/2;
	return pent;
}

int hexagon(n)
{
	int hex;
	hex = n*(2*n-1);
	return hex;
}
*/