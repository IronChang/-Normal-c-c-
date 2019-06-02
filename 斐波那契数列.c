#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<Windows.h>

//递归实现斐波那契数列
int my_fib_1(int n)
{
	if (n == 2 || n == 1)
	{
		return 1;
	}
	else
	{
		return my_fib_1(n - 2) + my_fib_1(n - 1);
	}
}

int my_fib_2(int n)
{
	int first = 1;
	int second = 1;
	int num = 0;

	if (n <= 2)//斐波那契前亮相都是1
	{
		return 1;
	}

	for (int i = 3; i <= n; i++)//计算大于2项的斐波那契数列
	{
		num = first + second;
		first = second;
		second = num;
	}

	return num;
}


int main()
{
	int num = 0;
	scanf("%d", &num);

	printf("递归计算：\n");
	printf("%d\n", my_fib_1(num));
	printf("非递归计算：\n");
	printf("%d\n", my_fib_2(num));

	system("pause");
	return 0;
}