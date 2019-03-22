#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
#include<time.h>
#include<math.h>

////判断是否是闰年 封装成函数
//int Is_leap_year(int n)
//{
//	if ((n % 4 == 0) && (n % 100 != 0) || (n % 400 == 0))
//	{
//		return 1;
//	}
//	else
//	{
//		return 0;
//	}
//}
//
//int main()
//{
//	int year = 0;
//	int count = 0;
//	for (year = 1000; year <= 2000; year++)
//	{
//		if ((Is_leap_year(year) == 1))
//		{
//			printf("%d  ", year);
//			count++;
//		}
//	}
//	printf("\n共有闰年=%d\n",count);
//	system("pause");
//	return 0;
//}

////二分查找（折半查找） 封装成函数
//int binary_search(int arr[], int k, int left, int right)
//{
//	while (left <= right)
//	{
//		int mid = left + (right - left) / 2;
//
//		if (k > arr[mid])
//		{
//			left = mid + 1;
//		}
//		else if (k < arr[mid])
//		{
//			right = mid - 1;
//		}
//		else
//		{
//			return mid;
//		}
//	}
//	return -1;
//}
//int main()
//{
//	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//	int k = 0;
//	int left = 0;
//	int right = sizeof(arr) / sizeof(arr[0]) - 1;
//	scanf("%d", &k);
//	int ret = binary_search(arr, k, left, right);
//	if (ret == -1)
//	{
//		printf("找不到！\n");
//	}
//	else
//	{
//		printf("找到了，下标为%d\n", ret);
//	}
//    system("pause");
//	return 0;
//}

////二分法查找
//int binary_search(int arr[], int k, int sz)
//{
//	int left = 0;
//	int right = sz - 1;
//	while (left <= right)
//	{
//		int mid = left + (right - left) / 2;
//		if (k > arr[mid])
//		{
//			left = mid + 1;
//		}
//		else if (k < arr[mid])
//		{
//			right = mid - 1;
//		}
//		else
//		{
//			return mid;
//		}
//	}
//	return -1;
//}
//
//int main()
//{
//	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//	int k = 0;
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	scanf("%d", &k);
//	int ret = binary_search(arr, k, sz);
//	if (ret == -1)
//	{
//		printf("没有找到！\n");
//	}
//	else
//	{
//		printf("找到了，下表为 %d\n", ret);
//	}
//	system("pause");
//	return 0;
//}

////址传递实现一个数自身增加 封装函数
//ADD(int *p)
//{
//	(*p)++;//*p代表才是对数字本身加减
//	//*p++;//指的是对指针变量进行加减
//}
//int main()
//{
//	int num = 0;
//	ADD(&num);
//	printf("%d\n", num);
//
//	ADD(&num);
//	printf("%d\n", num);
//
//	system("pause");
//	return 0;
//}

//首先printf()是有返回值的
//printf()函数返回值是其输出数的长度有关
//int main()
//{
//	int len = strlen("abcdef");
//	printf("%d\n", len);
//	printf("%d\n", strlen("abcdef"));
//	printf("%d\n", printf("%d", printf("%d", 43)));
//	system("pause");
//	return 0;
//}

//ADD（）函数实现两数之和
//int ADD(int a, int b)
//{
//	//return *a + *b;
//	int sum = a + b;
//	return sum;
//}
//
//int main()
//{
//	int a = 20;
//	int b = 15;
//	int sum=ADD(a, b);
//	printf("%d\n", sum);
//	system("pause");
//	return 0;
//}

////递归函数
//void print(unsigned int n)
//{
//	if (n > 9)
//	{
//		print(n / 10);
//	}
//	printf("%d ", n % 10);
//	
//}
//int main()
//{
//	unsigned int num = 1234;
//	print(num);
//	printf("\n");
//	system("pause");
//	return 0;
//}

////字符串计算的几种方式
//int main()
//{
//	char arr1[] ="abcdef";
//	int c = strlen("abcdef");
//	int a = strlen(arr1);
//	int b = sizeof(arr1) / sizeof(arr1[0])-1;
//	printf("%d  %d  %d", a, b,c);
//	system("pause");
//	return 0;
//}

////递归写法求字符串长度的函数
//int my_strlen(char *str)
//{
//	if (*str == '\0')
//	{
//		return 0;
//	}
//	else
//	{
//		return 1 + my_strlen(str + 1);//将指针往后面移动一位
//	}
//}
//int my_strlen(char* str)
//{
//	int count = 0;
//	while (*str != '\0')
//	{
//		count++;
//		str++;
//	}
//	return count;
//}
//int main()
//{
//	int len = my_strlen("abc");
//	printf("%d\n", len);
//	system("pause");
//}

////写成函数模块的求n的阶乘
//int fac(int n)
//{
//	int i = 0;
//	int ret = 1;
//	for (i = 1; i <= n; i++)
//	{
//		ret *= i;
//	}
//	return ret;
//}
//int main()
//{
//	int n = 0;
//	int ret = 0;
//	scanf("%d", &n);
//	ret = fac(n);
//	printf("%d\n", ret);
//	system("pause");
//	return 0;
//}
//

//递归写法 斐锲娜波数列 很麻烦很费内存 很费时间
//int fib(int n)
//{
//	if (n <= 2)
//	{
//		return 1;
//	}
//	else
//	{
//		return fib(n - 1) + fib(n - 2);
//	}
//}
//int main()
//{
//	int n = 0;
//	int ret = 0;
//	scanf("%d", &n);
//	ret = fib(n);
//	printf("%d ", ret);
//	system("pause");
//	return 0;
//}
//

//非递归求斐锲 迭代
//int fib(int n)
//{
//	int a = 1;
//	int b = 1;
//	int c = 1;
//	while (n>2)
//	{
//		c = a + b;
//		a = b;
//		b = c;
//		n--;
//	}
//	return c;
//}
//int main()
//{
//	int n = 0;
//	int ret = 0;
//	scanf("%d", &n);
//	ret = fib(n);
//	printf("%d \n", ret);
//	system("pause");
//	return 0;
//}

