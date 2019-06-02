#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<Windows.h>

//�ݹ�ʵ��쳲���������
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

	if (n <= 2)//쳲�����ǰ���඼��1
	{
		return 1;
	}

	for (int i = 3; i <= n; i++)//�������2���쳲���������
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

	printf("�ݹ���㣺\n");
	printf("%d\n", my_fib_1(num));
	printf("�ǵݹ���㣺\n");
	printf("%d\n", my_fib_2(num));

	system("pause");
	return 0;
}