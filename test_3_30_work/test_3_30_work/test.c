#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
//写一个函数返回参数二进制中 1 的个数
//比如： 15 0000 1111 4 个 1
//程序原型：
//int count_one_bits(unsigned int value)
//{
//	// 返回 1的位数 
//}
//
//int count_one_bits(unsigned int value)
//{ 
//	int count = 0;
//	int num = value;
//	int i = 0;
//	for (i = 0; i < 32; i++)
//	{
//		if (((num>>i)&1==1))
//		{
//			count++;
//		}
//	}
//	return count;
//}
//int main()
//{
//	int value = 0;
//	scanf("%d", &value);
//	int ret = count_one_bits(value);
//	printf("%d的二进制数中有[ %d ] 个1\n", value, ret);
//	system("pause");
//	return 0;
//}

//2.获取一个数二进制序列中所有的偶数位和奇数位，
//分别输出二进制序列。

//void count( unsigned int value)
//{
//	int i=0;
//	int num = value;
//	printf("偶数：");
//	for (i = 31; i <= 1; i-=2)
//	{	
//		printf("%d ", (num>> i) & 1);
//	}
//	printf("\n");
//	printf("奇数：");
//	for (i = 30; i <= 0; i -= 2)
//	{
//		printf("%d ", (num >> i) & 1);
//	}
//	printf("\n");
//}
//int main()
//{
//	int value = 0;
//	scanf("%d", &value);
//	count(value);
//	system("pause");
//	return 0;
//}
//
//
//int main()
//{
//
//	int i = 0;
//	int num = 0;
//	int count = 0;
//
//	scanf("%d", &num);
//
//	printf("偶数位：");
//	for (i = 31; i >= 1; i -= 2)
//
//	{
//		printf("%d ", (num >> i) & 1);
//	}
//	printf("\n");
//	printf("奇数位：");
//	for (i = 30; i >= 0; i -= 2)
//	{
//		printf("%d ", (num >> i) & 1);
//	}
//	printf("\n");
//
//	system("pause");
//	return 0;
//}
//3. 输出一个整数的每一位。 
//int main()
//{
//	int i = 0;
//	int num = 0;
//
//	scanf("%d", &num);
//	for (i = 30; i >= 0; i--)
//	{
//		printf("%d", (num >> i) & 1);
//	}
//	printf("\n");
//	system("pause");
//	return 0;
//}

////4.编程实现： 
////两个int（32位）整数m和n的二进制表达中，有多少个位(bit)不同？
////输入例子 :
////1999 2299
////输出例子 : 7
//
//int main()
//{
//	int m = 0;
//	int n = 0;
//	int m1 = 0;
//	int n1 = 0;
//	int i = 0;
//	static count = 0;
//
//	//获取整数m n
//	scanf("%d", &m);
//	scanf("%d", &n);
//
//	//循环计算比较
//	for (i = 0; i < 30; i++)
//	{
//		m1 = (m >> i) & 1;
//		n1 = (n >> i) & 1;
//
//		if (m1 != n1)
//		{
//			count++;
//		}
//	}
//	printf("%d\n", count);
//
//	system("pause");
//	return 0;
//}

//afternoon work

//1.
//5位运动员参加了10米台跳水比赛，有人让他们预测比赛结果
//A选手说：B第二，我第三；
//B选手说：我第二，E第四；
//C选手说：我第一，D第二；
//D选手说：C最后，我第三；
//E选手说：我第四，A第一；
//比赛结束后，每位选手都说对了一半，请编程确定比赛的名次。
//每个人都有五种可能性
//int main()
//{
//	int a = 0;//对五个人进行赋初值
//	int b = 0;
//	int c = 0;
//	int d = 0;
//	int e = 0;
//
//	for (a = 1; a <= 5; a++)
//	for (b = 1; b <= 5; b++)
//	for (c = 1; c <= 5; c++)
//	for (d = 1; d <= 5; d++)
//	for (e = 1; e <= 5; e++)
//	{
//		if ((2 == b && 3 != a) || (2 != b && 3 == a) == 1)//一半为真，一半为假
//		{
//			if ((2 == b && 4 != e) || (2 != b && 4 == e) == 1)
//			{
//				if ((1 == c && 2 != d) || (1 != c && 2 == d) == 1)
//				{
//					if ((5 == c && 3 != d) || (5 != c && 3 == d) == 1)
//					{
//						if ((4 == e && 1 != a) || (4 != e && 1 == a) == 1)
//						{
//							if (((a != b) && (a != c) && (a != d) && (a != e))//五个值不同的判断
//								&& ((b != c) && (b != d) && (b != e))
//								&& ((c != d) && (c != e))
//								&& ((d != e)))
//							{
//								printf("a= %d, b= %d,c= %d,d= %d,e= %d\n", a, b, c, d, e);
//							}
//						}
//					}
//				}
//			}
//		}
//					
//	}	
//	system("pause");
//	return 0;
//}
//
//2.日本某地发生了一件谋杀案，警察通过排查确定杀人凶手必为4个
//嫌疑犯的一个。以下为4个嫌疑犯的供词。
//A说：不是我。
//B说：是C。
//C说：是D。
//D说：C在胡说
//已知3个人说了真话，1个人说的是假话。
//现在请根据这些信息，写一个程序来确定到底谁是凶手。
//
//int main()
//{
//	char killer;
//	for (killer = 'A'; killer <= 'D'; killer++)
//	{
//		if (((killer != 'A') + (killer == 'C') + (killer == 'D') + (killer != 'D')) == 3)//有三个人说真话
//		{
//			printf("%c是凶手\n", killer);
//			break;
//		}
//	}
//	system("Pause");
//	return 0;
//}
//
//
//打印杨辉三角
//
//int main()
//{
//	int arr[100][100] = {1};
//	int n = 0;
//	int i = 0;
//	int j = 0;
//    
//	printf("请输入要打印的行数n（1-100)：>");
//	scanf("%d", &n);
//
//	for (i = 1; i < n; i++)
//	{   arr[i][0] = 1;
//		for (j = 1; j <= i; j++)
//		{
//			arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
//		}
//	}
//
//	for (i = 0; i < n; i++)
//	{
//		for (j = 0; j <= i; j++)
//		{
//			printf("%d ", arr[i][j]);
//		}
//		printf("\n");
//	}
//
//	system("pause");
//	return 0;
//}

