#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<windows.h>

//怎样判断大小端存储模式

//方法一
//int main()
//{
//	int x = 1;
//	char* p = (char*)&x;//指针类型决定决定解引用时访问字节大小，进行强制类型转换
//
//	if (*p == 1)//1的低为为00000001，表明数据低位保存在内存低位
//	{
//		printf("小端模式\n");
//	}
//	else
//	{
//		printf("大端模式\n");
//	}
//
//	system("pause");
//	return 0;
//}

//方法二
//int main()
//{
//	int x = 1;
//	char firstbyte = (char)x;//强制转换x将其从int类型转换为char类型
//
//	if (firstbyte == 1)
//	{
//		printf("小端模式\n");
//	}
//	else
//	{
//		printf("大端模式\n");
//	}
//
//	system("pause");
//	return 0;
//}

//方法三
//int main()//联合体
//{
//	union UN //联合体申请空间，看其中的数据类型按最大申请，全部共用一个空间
//	{
//		int i;
//		char c;
//	};
//
//	union UN u;
//	u.i = 1;//给联合体中i赋值，此时联合体u空间被占满
//
//	if (u.c == 1)
//	{
//		printf("小端模式\n");
//	}
//	else
//	{
//		printf("大端模式\n");
//	}
//	system("pause");
//	return 0;
//}


//有符号，无符号例题辨析 整形存储

//例题一：
//int main()
//{
//	// 截断 -- 跟变量类型无关
//	char a = -1;
//	signed char b = -1;
//	unsigned char c = -1;
//
//	// 整形提升 -- 提升变量是有符号，符号位1，高位补1 ，符号位位0，高位补0
//	// 整形提升 -- 提升变量无符号，高位补0
//	// a  补24个1 11111111
//	// b  补24个1 11111111
//	// c  补24个0 11111111
//	printf("a=%d,b=%d,c=%d\n", a, b, c);
//	// 127 127 177601
//
// //10000000 00000000 00000000 00000001 原
// //11111111 11111111 11111111 11111110 反
// //11111111 11111111 11111111 11111111 补
//
//// 00000000 00000000 00000000 11111111 补
//	system("pause");
//	return 0;
//}

//例题二
//int main()
//{
//	char a = -129;
//	//-129在内存中
//	//10000000 00000000 00000000 10000001 原码
//	//11111111 11111111 11111111 01111111 补码
//	//截断 01111111
//	//整形提升 补24个0 01111111
//	printf("%u\n", a);
//	system("pause");
//	return 0;
//}

//例题三
//int main()
//{
//	char a = 129;
//	printf("%u\n", a);
//	system("pause");
//	return 0;
//}

//例题四
//int main()
//{
//	int i = -20;
//	unsigned int j = 10;
//
//	printf("%d\n", i + j);
//
//	system("pause");
//	return 0;
//}

//例题五
//int main()
//{
//	unsigned int i;
//
//	for (i = 9; i >= 0; i--)
//	{
//		Sleep(500);
//		printf("%u\n", i);
//	}
//	//结果是无限循环
//	//因为当i=0输出后，i进入循环i=-1；因为i的数据类型时无符号类型，所以-1在内存中时补码
//	//11111111 11111111 11111111 11111111 会被认为时整数
//	//将再次进入循环
//	system("pause");
//	return 0;
//}

//例题六
//int main()
//{
//	char a[1000];
//	int i;
//
//	for (i = 0; i < 1000; i++)
//	{
//		a[i] = -1 - i;
//	}
//	printf("%d\n", strlen(a));
//
//	system("pause");
//	return 0;
//}

//例题七
//int main()
//{
//    unsigned char i = 0;//同例题五
//
//	for (i = 0; i <= 255; i++)
//	{
//		printf("hello world\n");
//	}
//	system("pause");
//	return 0;
//}


//浮点存储
//int main()
//{
//	int n = 9;
//	float *pFloat = (float *)&n;
//	printf("n的值为：%d\n", n);
//	printf("*pFloat的值为：%f\n", *pFloat);
//	*pFloat = 9.0;
//	printf("num的值为：%d\n", n);
//	printf("*pFloat的值为：%f\n", *pFloat);
//	system("pause");
//	return 0;
//}
