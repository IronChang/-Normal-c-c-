// sum = a + aa + aaa + aaaa + aaaaa
//递推公式：n = n * 10 + n;
//循环五次 

#include<stdio.h>
#include<windows.h>

#include "math.h"


int SUM(int a, int n)
{
	if (n > 1) 
		return a*n + SUM(a, n - 1) * 10;
	else 
		return a;
}

int main()
{
	int sum1 = SUM(1, 5);
	printf("%d\n",sum1); 
	system("pause");
	return 0;
}
