#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

//交换数组当中的内容
//int main()
//{
//	int a[] = { 1, 2, 3, 4, 5 };
//	int b[] = { 6, 7, 8, 9, 10 };
//	int i = 0;
//	int j = 0;
//	int temp;
//
//	for (i; i < 5; i++)//建立中间值进行交换
//	{
//		
//		   temp = b[i];
//			b[i] = a[i];
//			a[i] = temp;
//		
//	}
//	for (int l = 0; l < 5; l++)
//	{
//		printf("%d  ", a[l]);
//		
//	}
//
//	system("pause");
//	return 0;
//}

//计算1 / 1 - 1 / 2 + 1 / 3 - 1 / 4 + 1 / 5 …… + 1 / 99 - 1 / 100 的值
//int main()
//{
//	int i = 0;
//	double sum1 = 0;
//	double sum2 = 0;
//	for (i = 1; i <= 100; i += 2)//求出奇数项之和
//	{
//		sum1 += (1.0/ i);
//	}
//	for (i = 2; i <= 100; i += 2)//秋初偶数项之和
//	{
//		sum2 += (1.0 / i);
//	}
//    printf("%lf\n", sum1-sum2);
//	system("pause");
//	return 0;
//}

//编写程序数一下 1到 100 的所有整数中出现多少次数字9
//int main()
//{
//	int i = 0;
//	int k = 0;
//	for (i = 1; i <= 100; i++)
//	{
//		if (i % 10 == 9)//针对个位是9的
//		{
//			k++;
//		}
//		if (i / 10 == 9)//针对十位是9的
//		{
//			k++;
//		}
//
//	}
//
//	printf("总共出现9的个数为：%d\n", k);
//	system("pause");
//	return 0;
//}