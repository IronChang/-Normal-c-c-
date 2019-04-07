#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// 递归和非递归实现斐波那契数列

//递归
//int fib(int n)
//{
//	if (n == 2 ||n == 1)
//	{
//		return 1;
//	}
//	else
//	{
//		return fib(n-2) + fib(n - 1);
//	}
//}
//int main()
//{
//	int n = 0;
//	int ret = 0;
//	scanf("%d", &n);
//	ret=fib(n);
//	printf("%d\n",ret);
//	system("pause");
//	return 0;
//}

//非递归实现斐波那契数列
//int fib(int n)
//{
//	int n1 = 1;
//	int n2 = 1;
//	int ret = 0;
//	if (n <= 2)
//	{
//		return 1;
//	}
//	for (int i = 3; i <= n; i++)
//	{
//		ret = n1 + n2;
//		n1 = n2;
//		n2 = ret;
//	}
//	return ret;
//}
//int main()
//{
//	int n = 0;
//	int ret = 0;
//	scanf("%d", &n);
//	ret=fib(n);
//	printf("%d\n",ret);
//	system("pause");
//	return 0;
//}


//编写一个函数实现n^k，使用递归实现 

////递归实现
//int pow_n_K(int n, int k)
//{
//	if (k == 0)
//	{
//		return 1;
//	}
//	else
//	{
//		return n*pow_n_K(n, k - 1);
//	}
//}
//int main()
//{
//	int n = 0;
//	int k = 0;
//	int ret = 0;
//	scanf("%d", &n);
//	scanf("%d", &k);
//	ret = pow_n_K(n, k);
//	printf("%d\n", ret);
//	system("puase");
//	return 0;
//}

// 写一个递归函数DigitSum(n)，输入一个非负整数，返回组成它的数字之和

//int DigitSum(int n)
//{
//	if (n < 10)
//	{
//		return n;
//	}
//	else
//	{
//		return (n % 10) + DigitSum(n / 10);
//	}
//}
//int main()
//{
//	int n = 0;
//	int ret = 0;
//	scanf("%d", &n);
//	ret = DigitSum(n);
//	printf("%d\n", ret);
//	system("pause");
//	return 0;
//}

// 编写一个函数 reverse_string(char * string)（递归实现）

//void  reverse_string(char * string)
//{
//	if (*string)
//	{
//    int len = strlen(string);
//	char tmp = string[0];
//	string[0] = string[len - 1];
//	string[len - 1] = '\0';
//	reverse_string(string + 1);
//	string[len - 1] = tmp;
//	}
//	
//}
//int main()
//{
//	char str[] = { "abcdef" };
//	reverse_string(&str);
//	printf("%s", str);
//	system("pause");
//	return 0;
//}

//递归和非递归分别实现strlen 

//递归
//int my_strlen(char* string)
//{
//	if (*string == '\0')
//	{
//		return 0;
//	}
//	else
//	{
//		return 1 + my_strlen(string + 1);
//	}
//}
//int main()
//{
//	char str[] = { "abcdef" };
//	int ret = 0;
//	ret = my_strlen(str);
//	printf("%d\n", ret);
//	system("pause");
//	return 0;
//}

//非递归
//int my_strlen(char* string)
//{
//	int count = 0;
//	int i = 0;
//	while (*string != '\0')
//	{
//		count++;
//		string++;
//	}
//	return count;
//}
//int main()
//{
//	char str[] = { "abcdef" };
//	int ret = 0;
//	ret = my_strlen(str);
//	printf("%d\n", ret);
//	system("pause");
//	return 0;
//}

//递归和非递归分别实现求n的阶乘 

//递归
//int fac_n(int n)
//{
//	if (n == 0)
//	{
//		return  1;
//	}
//	else
//	{
//		return n*fac_n(n - 1);
//	}
//}
//int main()
//{
//	int n = 0;
//	int ret = 0;
//	scanf("%d", &n); 
//	ret = fac_n(n);
//	printf("%d\n", ret);
//	system("pause");
//	return 0;
//}

//非递归
//int fac_n(int n)
//{
//	int sum = 1;
//	int i = 0;
//	while (n)
//	{
//		sum *= n;
//		n--;
//	}
//	return sum;
//}
//int main()
//{
//	int n = 0;
//	int ret = 0;
//	scanf("%d", &n);
//	ret = fac_n(n);
//	printf("%d\n", ret);
//	system("pause");
//	return 0;
//}

//递归方式实现打印一个整数的每一位 

//void print(int n)
//{
//	if (n >9)
//	{
//		print(n / 10);
//	}
//	
//	printf("%d ", n % 10);
//	
//
//}
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	print(n);
//	system("pause");
//	return 0;
//}