#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<windows.h>

//#define 定义标识符  定义宏
//常量+表达式替换
#define N 100
//#define MAX(a,b) ((a) > (b) ? (a) : (b))//宏函数：减少调用函数的消耗，提高效率。直接在预处理是替换无需开辟栈帧
//
//int Max(int a, int b)//调用时要在内存开辟相应栈帧 
//{
//	return ((a) > (b) ? (a) : (b));//用括号好括起来，避免优先级问题
//}

//int main()
//{
//	int x1 = 0;
//	int x2 = 1;
//	printf("%d\n" ,MAX(x1, x2));
//	printf("%d\n", Max(x1, x2));
//
//	system("pause");
//	return 0;
//}

//#define ADD(a,b) ((a)+(b))
//
//int add(int a,int b)
//{
//	return a + b;
//}
//
//int main()
//{
//	printf("%d\n", ADD(1, 2) * 3);//输出应该是9，但是是7? why?
//	因为就是优先级的问题
//	printf("%d\n", add(1, 2) * 3);
//
//	int x1 = 1, x2 = 2;
//	printf("%d\n", ADD(x1 | x2,x1 | x2) * 3);//还是优先级的问题
//	printf("%d\n", add(x1 | x2, x1 | x2) * 3);
//
//	system("pause");
//	return 0;
//}


//宏定义把参数传入字符串中
//#define PRINT(FORMAT, VALUE) \
//	printf("my value is "FORMAT"\n", VALUE);
#define PRINT(FORMAT, VALUE)\
printf("the value of " #VALUE "is "FORMAT "\n", VALUE);

int main()
{
	int i = 10;
	PRINT("%d", i + 3); printf("the value of " "i + 3" "is " "%d" "\n", i + 3);
	system("pause");
	return 0;
}