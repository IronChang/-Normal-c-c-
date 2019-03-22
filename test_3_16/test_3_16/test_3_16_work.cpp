#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<iostream>
#include<math.h>
using namespace std;

//
//void menu()
//{
//	printf("********************************************\n");
//	printf("*************** 1.开始游戏 *****************\n");
//	printf("*************** 0.退出游戏 *****************\n");
//	printf("********************************************\n");
//}
//
//void game()
//{
//	int ret = 0;
//	int guess = 0;
//	ret = rand() % 100 + 1;
//	while (1)
//	{
//		printf("猜猜该数字：>");
//		scanf("%d", &guess);
//		if (guess > ret)
//		{
//			printf("猜大了\n");
//		}
//		else if (guess < ret)
//		{
//			printf("猜小了\n");
//		}
//		else
//		{
//			printf("恭喜，猜对了\n");
//			break;
//		}
//	}
//}
//
//int main()
//{
//	int input = 0;
//	srand((unsigned int)time(NULL));
//	do
//	{
//		menu();
//		printf("请选择：>");
//		scanf("%d", &input);
//		switch (input)
//		{
//		case 1:
//			game();
//			break;
//		case 0:
//			printf("退出游戏！\n");
//			break;
//		default:
//			printf("选择错误！\n");
//			break;
//		}
//	} while (input);
//	system("pause");
//	return 0;
//}
//
////二分查找（折半）
//int binary_search(int arr[], int k, int left, int right)
//{
//	int mid = left + (right - left) / 2;
//	while (left <= right)
//	{
//		if (arr[mid] > k)
//		{
//			right = mid - 1;
//		}
//		else if (arr[mid] < k)
//		{
//			left = mid + 1;
//		}
//		else
//		{
//			return mid;
//		}	
//	}
//    return -1;
//}
//int main()
//{
//	int arr[] = { 9, 8, 2, 6, 47, 1, 3, 4, 63, 6 };
//	int k = 0;
//	int left = 0;
//	int right = sizeof(arr) / sizeof(arr[0]) - 1;
//	scanf("%d", &k);
//	int ret = binary_search(arr, k, left, right);
//    
//	if (ret == -1)
//	{
//		printf("没有找到！\n");
//	}
//	else
//	{
//		printf("找到了！下表为 %d\n", ret);
//	}
//	system("pause");
//	return 0;
//}
//
////模拟密码输入
//
//int main()
//{
//	int i = 0;
//	
//	for (i = 0; i < 3; i++)
//	{
//        char arr[] = { 0 };
//		printf("请输入密码：>");
//		scanf("%s", arr);
//		if (strcmp(arr, "7410123") == 0)
//		{
//			printf("输入正确！\n");
//			break;
//		}
//		else
//		{
//			printf("输入错误!\n");
//		}
//	}
//	if (i == 3)
//	{
//		printf("三次输入错误，退出程序！！！");
//	}
//}
//
////大小写转换
//int main()
//{
//	int ch;
//	printf("请输入一个字符：\n");
//	while ((ch = getchar()) != EOF)
//	{
//		if (ch >= 'a'&&ch <= 'z')
//		{
//			printf("%c" ,ch - 32);
//		}
//		else if (ch >= 'A'&&ch <= 'Z')
//		{
//			printf("%c", ch + 32);
//		}
//		else if (ch >= '0'&&ch <= '9')
//		{
//			printf("%c", ch);
//		}
//}
//	printf("\n");
//	system("pause");
//	return 0;
//}

////求2—10000之间的完全树；除过自身其因子加一块的自己，6=1+2+3；
//int main()
//{
//	int i = 0;
//	int j = 0;
//
//	for (i = 2; i <= 10000; i++)
//	{
//		int sum = 0;
//		for (j = 1; j<i - 1; j++)
//		{
//			if (i%j == 0)
//			{
//				sum += j;
//			}
//		}
//		if (sum == i)
//		{
//			cout << i << " " << endl;
//		}
//	}
//	system("pause");
//	return 0;
//}

//打印n阶乘法口诀
//int main()
//{
//	int i = 0;
//	int j = 0;
//	int n = 0;
//	scanf("%d", &n);
//	for (i = 1; i <= n; i++)
//	{
//		for (j = 1; j <= i; j++)
//		{
//			printf("%d*%d=%2d ", i, j, i*j);
//		}
//		printf("\n");
//	}
//	system("pause");
//	return 0;
//}
//
//使用函数实现两个数的交换
//void swap(int *a, int *b)
//{
//	int temp = *a;
//	*a = *b;
//	*b = temp;
//}
//int main()
//{
//	int a = 20;
//	int b = 15;
//	printf("a= %d,b= %d\n", a, b);
//	swap(&a, &b);
//	printf("a= %d,b= %d\n", a, b);
//	system("pause");
//	return 0;
//}
//
//用函数实现判断year是不是闰年
//1000—2000年之间
//
//int is_leap_year(int year)
//{
//	if ((year % 100 != 0) && (year % 4 == 0) || (year % 400 == 0))
//	{
//		return year;
//	}
//	else
//	{
//		return -1;
//	}
//}
//int main()
//{
//	int year = 0; 
//	for (year = 1000; year <= 2000; year++)
//	{
//		int ret = is_leap_year(year);
//		if (ret != -1)
//		{
//			printf("%d ", year);
//		}
//	}
//	
//	system("pause");
//	return 0;
//}
//
//创建一个数组，实现相应的函数
// void init(int a[])
//{
//	 int i = 0;
//	 for (i = 0; i < 10; i++)
//	 {
//		 a[i] = 0;
//	 }
//}
// void empty(int a[])
// {
//	 int i = 0;
//	 for (i = 0; i < 10; i++)
//	 {
//		 a[i] = 0;
//	 }
// }
// void swap(int *p1, int *p2)
// {
//	 int temp = *p1;
//	 *p1 = *p2;
//	 *p2 = temp;
// }
// void reverse(int a[])
// {
//	 int i = 0;
//	 int len = sizeof(a) / sizeof(a[0]);
//	 for (i = 0; i < len/2; i++)
//	 { 
//		 swap(a + i, a + len - 1 - i);
//	 }
// }
//int main()
//{
//	int i = 0;
//	int a[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ", a[i]);
//	}
//	printf("\n");
//	reverse(a);//数组元素逆置
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ", a[i]);
//	}
//	printf("\n");
//	init(a);//初始化数组
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ", a[i]);
//	}
//	printf("\n");
//	empty(a);//清空数组
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ", a[i]);
//	}
//	printf("\n");
//	
//	system("pause");
//	return 0;
//}
//
//
//
//写一个函数判断是不是素数
//范围100——200之间
//int is_prime(int n)
//{
//	int i = 0;
//	for (i = 2; i <sqrt(n); i++)
//	{
//		if (n%i == 0)
//		{
//			return 0;
//		}
//	}
//	return 1;
//}
//
//int main()
//{
//	int i = 0;
//	int count = 0;
//	for (i = 100; i <= 200; i++)
//	{
//		int ret = is_prime(i);
//		if (ret == 1)
//		{
//			printf("%d ",i);
//			count++;
//		}
//		
//	}
//	printf("\n");
//	printf("%d\n", count);
//	system("pause");
//	return 0;
//}

//递归和非递归实现斐波那契数列
//递归实现  如果数字很大算法很费时间和内存
//int fib(int n)
//{
//	if (n <= 2)
//	{
//		return 1;
//	}
//	if (n > 2)
//	{
//		return  fib(n - 1) + fib(n - 2);
//	}
//}
//int main()
//{
//	int n = 0;
//	int ret = 0;
//	scanf("%d", &n);
//	ret = fib(n);
//	printf("%d\n", ret);
//	system("pause");
//	return 0;
//}
//非递归实现斐波那契数列
//int fib(int n)
//{
//	int i = 1;
//	int j = 1;
//	int c = 1;
//	while (n > 2)
//	{
//		c = i + j;
//		i = j;
//		j = c;
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
//	printf("%d\n", ret);
//	system("pause");
//	return 0;
//}

////编写一个函数实现n^k，使用递归实现 
//int n_cube(int n, int k)
//{
//	if (k==0)
//	{
//		return 1;
//	}
//	else if (k == 1)
//	{
//		return n;
//	}
//	else
//	{
//		return n*n_cube(n, k - 1);
//	}
//}
//int main()
//{
//	int n = 0;
//	int k = 0;
//	scanf("%d %d", &n, &k);
//	int ret = n_cube(n, k);
//	printf("%d\n", ret);
//	system("pause");
//	return 0;
//}

//// 写一个递归函数DigitSum(n)，输入一个非负整数，返回组成它的数字之和， 例如，调用DigitSum(1729)，则应该返回1 + 7 + 2 + 9，它的和是19
//int DigitSum(int n)
//{
//	int sum = 0;
//	int m = 0;
//	if (n != 0)
//	{
//		m = n % 10;
//		n = n / 10;
//		sum = m + DigitSum(n);
//	}
//	return sum;
//}
//int main()
//{
//	int n = 0;
//	int ret = 0;
//	scanf("%d", &n);
//	ret = DigitSum(n);
//	printf("sum=%d\n", ret);
//	system("pause");
//	return 0;
//}

//编写一个函数 reverse_string(char * string)（递归实现） 实现：将参数字符串中的字符反向排列。要求：不能使用C函数库中的字符串操作函数。
//void reverse_string(char * string)
//{
//	int len = strlen(string);
//	if (len <= 1)
//	{
//		return;
//	}
//	else
//	{
//		char tmp = string[0];
//		string[0] = string[len - 1];
//		string[len - 1] = '\0';
//		reverse_string(string + 1);
//		string[len - 1] = tmp;
//	}
//
//}
//int main()
//{
//	char arr[] = "abcdefgh";
//	reverse_string(arr);
//	printf("%s\n", arr);
//	system("pause");
//	return 0;
//}

//////递归和非递归分别实现strlen 
//////递归实现
////int my_strlen(char *arr)
////{
////	if (*arr == '\0')
////	{
////		return 0;
////	}
////	else
////	{
////		return 1 + my_strlen(arr + 1);
////	}
////}
////int main()
////{
////	char arr[] = "abcdef";
////	int ret = 0;
////	ret = my_strlen(arr);
////	printf("%d\n", ret);
////	system("pause");
////	return 0;
////
////}
////非递归实现
//int my_strlen(char* arr)
//{
//	int i = 0;
//	while(*arr != '\0')
//	{
//		i++;
//		arr+=1;
//	}
//	return i;
//}
//int main()
//{
//    char arr[] = "abcdef";
//	int ret = 0;
//	ret = my_strlen(arr);
//	printf("%d\n", ret);
//	system("pause");
//	return 0;
//}

////递归和非递归分别实现求n的阶乘 
////递归实现
//int fac(int n)
//{
//	if (n == 1)
//	{
//		return 1;
//	}
//	else
//	{
//		return n*fac(n - 1);
//	}
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
////非递归实现
//int fac(int n)
//{
//	int i = 0;
//	int ret=1;
//	while (n != 0)
//	{
//		ret *= n;
//		n--;
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

////递归方式实现打印一个整数的每一位 
//void print(int n)
//{
//	if (n > 9)
//	{
//		print(n / 10);
//	}
//	printf("%d ", n % 10);
//}
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	print(n);
//	printf("\n");
//	system("pause");
//	return 0;
//}
