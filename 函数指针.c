#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//#include<stdlib.h>

/*函数指针：函数指令当中，第一条指令的地址。一下两个都可以表示函数的指针
(1)函数名 （参考：组名也是数组首元素的地址）
(2)取地址函数名 （参考;取地址数组名也就是数组首元素的地址）
(3)通式 void (*+指针名)（ ） 返回值为 void
*/

//例子1 （*（void （*）（））0）（）；//其实是一个函数的调用
//函数指针解引用后加一个（函数参数），表示函数调用
//（void （*）（））0 // 把0强制转换成该类型的函数指针
//然后就解引用，就相当于调用函数
//实际上此时应该出现错误，“0”的地址为是不允许被访问的。也就相当于空指针。
//空指针就相当于该内存空间第一个地址位，是不允许被访问的。


//例子2 void (*signal(int , void(*)(int)))(int)； //这里相当于一个函数的声名
//函数名;signal(int , void(*)(int))
//参数：int,函数指针 (int , void(*)(int)
//返回值：是一个函数指针 void （*+signal（））（int）
//代码看起来很难懂，可以优化一下：
//typedef void(*Func)(int)
//Func signal(int ,Func)   

/*函数指针数组：存放函数指针的一类集合
（1） 通式:int (*arr[10])()
首先arr先和[]结合，说明arr是一个数组，而数组存放的是 int (* )() 类型的函数指针
*/ 


//函数指针数组的用途： 转移表
//实现（计算器） 一般方式实现

//int  add(int a, int b)
//{
//	return a + b;
//}

//int  sub(int a, int b)
//{
//	return a - b;
//}

//int  mul(int a, int b)
//{
//	return a * b;
//}

//int  div(int a, int b)
//{
//	return a / b;
//}

//int main()
//{
//	int x = 0;
//	int y = 0;
//	int input = 1;
//	int ret = 0;
//	
//	while (input)
//	{
//		printf("********************************\n");
//		printf("1: add                    2: sub\n");
//		printf("3: mul                    4: div\n");
//		printf("********************************\n");
//		printf("请选择：> ");
//		scanf("%d", &input);
//
//		switch (input)
//		{
//		case 1:
//			printf("请输入两个操作数；>");
//			scanf("%d %d", &x, &y);
//			ret = add(x, y);
//			break;
//		case 2:
//			printf("请输入两个操作数；>");
//			scanf("%d %d", &x, &y);
//			ret = mul(x, y);
//			break;
//		case 3:
//			printf("请输入两个操作数；>");
//			scanf("%d %d", &x, &y);
//			ret =mul(x, y);
//			break;
//		case 4:
//			printf("请输入两个操作数；>");
//			scanf("%d %d", &x, &y);
//			ret = div(x, y);
//			break;
//		default:
//			printf("输入错误！！！！！！！！");
//			break;
//		}
//		printf("结果 = %d\n", ret);
//	}
//	system("pause");
//	return 0;
//}

//利用函数指针数组实现

int  add(int a, int b)
{
	return a + b;
}

int  sub(int a, int b)
{
	return a - b;
}

int  mul(int a, int b)
{
	return a * b;
}

int  div(int a, int b)
{
	return a / b;
}

int main()
{
	int x = 0;
	int y = 0;
	int input = 1;
	int ret = 0;
	int(*p[5])(int x, int y) = { 0, add, sub, mul, div };

	while (input)
	{
		printf("********************************\n");
		printf("1: add                    2: sub\n");
		printf("3: mul                    4: div\n");
		printf("********************************\n");
		printf("请选择：> ");
		scanf("%d", &input);

		if (input <= 4 && input >= 1)
		{
			printf("请输入两个操作数：>");
			scanf("%d %d", &x, &y);
			ret = (*p[input])(x, y);
		}
		else
		{
			printf("输入错误！！！！！！！！！\n");
		}
		printf("%d\n", ret);
	}
	
	system("pause");
	return 0;
}