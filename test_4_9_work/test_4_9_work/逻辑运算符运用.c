#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

//统计一个整数的二进制中有几个1？

//
//int count_one_bits(int val)
//{
//	int count = 0;
//	int i = 0;
//	for (i = 0; i < 32; i++)
//	{
//		if ((val >> i) & 1 == 1)
//			count++;
//	}
//	return count;
//}
//
//int count_one_bits2(int val)
//{
//	int count = 0;
//	int i = 0;
//	for (i = 1; i <= 32; i++)
//	{
//		if (val % 2 == 1)
//		{
//			count++;
//		}
//		val = val / 2;
//	}
//	return count;
//}
//

//int count_one_bits3(int val)
//{
//	int count = 0;
//	int i = 0;
//	//根据类型获取循环次数
//	for (i = 1; i != 0; i <<= 1)
//	{
//		//把第i位移到第一位，和1进行按位与&运算，获取二进制值
//		if ((val & i) != 0)
//		{
//			count++;
//		}
//	}
//	return count;
//}

//int count_one_bits4(int val)
//{
//	int count = 0;
//	while (val)
//	{
//		val = val&(val - 1);
//		count++;
//	}
//	return count;
//}
//

//int count_one_bits4(int n)
//{
//	int count = 0;
//	int flag = 1;
//	while (flag) {
//		if ((n & flag) != 0) {
//			count++;
//		}
//		flag = flag << 1;
//	}
//	return count;
//}

//int main()
//{
//	int val=0;
//	int ret = 0;
//	scanf("%d", &val);
//	ret = count_one_bits3(val);
//	printf("%d\n",ret);
//	system("pause");
//	return 0;
//}

//2.获取一个数二进制序列中所有的偶数位和奇数位， 分别输出二进制序列。

//void print_binary_bit(int val)
//{
//	int i = 0;
//	printf("偶数列：> ");
//	for (i = 30; i >= 0; i -= 2)
//	{
//		printf("%d", (val >> i) & 1);
//	}
//	printf("\n");
//	printf("奇数列：> ");
//	for (i = 31 ; i >= 0; i -= 2)
//	{
//		printf("%d", (val >> i) & 1);
//	}
//	printf("\n");
//}

//void print_binary_bit2(int val)
//{
//	int arr1[16] = { 0 };
//	int arr2[16] = { 0 };
//	int i = 0;
//	for (i = 0; i < 16; i++)
//	{
//		if ((val & 1) == 1)
//		{
//			arr1[i] = 1;
//		}
//		val >>= 1;
//		if ((val & 1) == 1)
//		{
//			arr2[i] = 1;
//		}
//		val >>= 1;
//	}
//	printf("偶数列：> ");
//	for (i = 15; i >= 0; i--)
//	{
//		printf("%d ", arr2[i]);
//	}
//	printf("\n");
//
//	printf("奇数列：> ");
//	for (i = 15; i >= 0; i--)
//	{
//		printf("%d ", arr1[i]);
//	}
//	printf("\n");
//}
//
//int main()
//{
//	int val = 0;
//	scanf("%d", &val);
//	print_binary_bit(val);
//	system("pause");
//	return 0;
//}

// 输出一个整数的每一位。 

//void printfs(int val)//递归
//{
//	if (val > 9)
//	{
//		printfs(val / 10);
//	}
//	printf("%d\n", val % 10);
//}

//void printfs2(int val)
//{
//	if (val == 0)
//	{
//		printf("0\n");
//		return;
//	}
//
//
//	int len = 0;
//	//获取长度
//	int tmp = val;
//	while (tmp)
//	{
//		len++;
//		tmp /= 10;
//	}
//
//	while (len)
//	{
//		int num = val / pow(10, len - 1);
//		printf("%d ", num % 10);
//		len--;
//	}
//	printf("\n");
//}

//int main()
//{
//	int val = 0;
//	scanf("%d", &val);
//	printfs2(val);
//	printf("\n");
//	system("pause");
//	return 0;
//}

//两个int（32位）整数m和n的二进制表达中，有多少个位(bit)不同？

//int calculateDifferentBit(int m, int n)
//{
//	//m和n的异或结果的二进制表示中，1的位表示m和n不同的位
//	//计算异或结果中二进制表示中1的个数
//	int yihuo = m^n;
//	int i = 0;
//	int count = 0;
//
//	while (yihuo)
//	{
//		yihuo = yihuo & (yihuo - 1);
//		count++;
//	}
//	return count;
//}

//int calculateDifferentBit2(int m, int n)
//{
//	int count = 0;
//	int i = 0;
//	for (i; i < 32; i++)
//	{
//		if (((m >> i) & 1) != ((n >> i) & 1))
//			count++;
//	}
//	return count;
//}

//int main()
//{
//	int m = 0;
//	int n = 0;
//	int ret = 0;
//	scanf("%d", &m);
//	scanf("%d", &n);
//	ret=calculateDifferentBit(m,n);
//	printf("%d\n", ret);
//	system("pause");
//	return 0;
//}