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
//	printf("*************** 1.��ʼ��Ϸ *****************\n");
//	printf("*************** 0.�˳���Ϸ *****************\n");
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
//		printf("�²¸����֣�>");
//		scanf("%d", &guess);
//		if (guess > ret)
//		{
//			printf("�´���\n");
//		}
//		else if (guess < ret)
//		{
//			printf("��С��\n");
//		}
//		else
//		{
//			printf("��ϲ���¶���\n");
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
//		printf("��ѡ��>");
//		scanf("%d", &input);
//		switch (input)
//		{
//		case 1:
//			game();
//			break;
//		case 0:
//			printf("�˳���Ϸ��\n");
//			break;
//		default:
//			printf("ѡ�����\n");
//			break;
//		}
//	} while (input);
//	system("pause");
//	return 0;
//}
//
////���ֲ��ң��۰룩
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
//		printf("û���ҵ���\n");
//	}
//	else
//	{
//		printf("�ҵ��ˣ��±�Ϊ %d\n", ret);
//	}
//	system("pause");
//	return 0;
//}
//
////ģ����������
//
//int main()
//{
//	int i = 0;
//	
//	for (i = 0; i < 3; i++)
//	{
//        char arr[] = { 0 };
//		printf("���������룺>");
//		scanf("%s", arr);
//		if (strcmp(arr, "7410123") == 0)
//		{
//			printf("������ȷ��\n");
//			break;
//		}
//		else
//		{
//			printf("�������!\n");
//		}
//	}
//	if (i == 3)
//	{
//		printf("������������˳����򣡣���");
//	}
//}
//
////��Сдת��
//int main()
//{
//	int ch;
//	printf("������һ���ַ���\n");
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

////��2��10000֮�����ȫ�����������������Ӽ�һ����Լ���6=1+2+3��
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

//��ӡn�׳˷��ھ�
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
//ʹ�ú���ʵ���������Ľ���
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
//�ú���ʵ���ж�year�ǲ�������
//1000��2000��֮��
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
//����һ�����飬ʵ����Ӧ�ĺ���
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
//	reverse(a);//����Ԫ������
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ", a[i]);
//	}
//	printf("\n");
//	init(a);//��ʼ������
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ", a[i]);
//	}
//	printf("\n");
//	empty(a);//�������
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
//дһ�������ж��ǲ�������
//��Χ100����200֮��
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

//�ݹ�ͷǵݹ�ʵ��쳲���������
//�ݹ�ʵ��  ������ֺܴ��㷨�ܷ�ʱ����ڴ�
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
//�ǵݹ�ʵ��쳲���������
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

////��дһ������ʵ��n^k��ʹ�õݹ�ʵ�� 
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

//// дһ���ݹ麯��DigitSum(n)������һ���Ǹ����������������������֮�ͣ� ���磬����DigitSum(1729)����Ӧ�÷���1 + 7 + 2 + 9�����ĺ���19
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

//��дһ������ reverse_string(char * string)���ݹ�ʵ�֣� ʵ�֣��������ַ����е��ַ��������С�Ҫ�󣺲���ʹ��C�������е��ַ�������������
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

//////�ݹ�ͷǵݹ�ֱ�ʵ��strlen 
//////�ݹ�ʵ��
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
////�ǵݹ�ʵ��
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

////�ݹ�ͷǵݹ�ֱ�ʵ����n�Ľ׳� 
////�ݹ�ʵ��
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
////�ǵݹ�ʵ��
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

////�ݹ鷽ʽʵ�ִ�ӡһ��������ÿһλ 
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
