#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//交换两个数的值
//int main()
//{
//	int a, b, c;
//	a = 10;
//	b = 5;
//
//   printf("a=%d b=%d\n", a, b);
//
//	c = a;//；利用中间变量进行换
//	a = b;
//	b = c;
//	
//	printf("a=%d b=%d\n", a, b);
//
//	system("pause");
//	return 0;
//}

//不用创建中间量交换两个数的值
//int main()
//{
//	int a, b;
//	a = 10;
//	b = 5;
//	
//	a = a + b; //利用加法进行交换；
//	b = a - b;
//	a = a - b;
//
//	printf("a=%d", a);
//    printf("b=%d", b);
//
//	system("pause");
//	return 0;
//}

//求10个整数中的最大值
//int main()
//{
//	int a[10] = { 9, 8, 5, 3, 6, 2, 1, 4, 7, 45 };
//
//	int i = 0, j = 0, temp = 0;
//
//	for (i = 0; i < 10; i++)//冒泡排序法
//	{
//		for (j = i + 1; j < 10; j++)
//		{
//			if (a[i]>a[j])
//			{
//				temp = a[i];
//				a[i] = a[j];
//				a[j] = temp;
//			}
//		}
//	}
//	
//  printf("MAX=%d\n", a[9]);
//	system("pause");
//	return 0;
//}

////求两个数最大公约数
//int main()
//{
//	int m, n, temp, i = 0;;
//
//	scanf("%d %d", &m, &n);
//	if (m < n)
//	{
//		temp = m;
//		n = m;
//		m = temp;
//	}
//	for (i = 1; i<=n; i++)
//	{
//		if (m%i == 0 && n%i == 0)//判断是否满足公约数的条件
//		{
//			//printf("最大公约数为：%d\n", i);
//			printf("公约数为%d \n", i);
//		}
//	}
//	system("pause");
//	return 0;
//}

//将三个数从大到小输出
//int main()
//{
//	int a = 0;
//	int b = 0;
//	int c = 0;
//	int t = 0;
//
//	scanf("%d %d %d", &a, &b, &c);
//
//	if (a > b)//创建中间变量进行短暂数据交换
//	{
//		t = a;
//		a = b; 
//		b = t;
//	}
//	if (a > c)
//	{
//		t = a;
//		a = c;
//		c = t;
//    }
//	if (b > c)
//	{
//		t = b;
//		b = c;
//		c = t;
//	}
//
//	printf("%d %d %d\n", c, b, a);
//	
//
//	system("pause");
//	return 0;
//
//}
