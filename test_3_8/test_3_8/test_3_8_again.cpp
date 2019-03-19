#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

//判断是否为素数
//素数：除了能被1和自身整除外不能被其他数整出；
int main()
{
	 int i = 0;
	int count = 0;

	for (i = 100; i <= 200; i++)
	{
		int j = 0;
		for (j = 2; j <= i/2; j++)
		{
			if (i%j == 0)
			{
				break;
			}
		}
		if (j>(i/2))
		{
			printf("%d ", i);
			count++;
		}
	}
	printf("%d\n", count);
	system("pause");
	return 0;
}