#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

//联合体是一种特殊的自定义类型，这种类型定义的变量也包含一系列的成员，特征是这些成员公用一块空间（所以联合也叫共用体）。

union Un
{
	char c;
	int i;
};

union Un un;

//int main()
//{
//	printf("%d\n", sizeof(un));//联合的大小至少是最大成员的大小
//	system("pause");
//	return 0;
//}


//联合体的成员是共用同一块内存空间，这样一个联合变量的大小，至少是最大成员的大小
union Un1
{
	int i;
	char c;
};

union Un1 un1;

//int main()
//{
//	printf("%d\n", &(un1.i));
//	printf("%d\n", &(un1.c));
//	un1.i = 0x11223344;
//	un1.c = 0x55;
//	printf("%x\n", un1.i);
//	system("pause");
//	return 0;
//}

//联合体大小计算
//1 联合的大小至少是最大成员的大小
//2 当前最大成员大小不是最大对齐数的整数倍的时候，就要对齐到最大对齐数的整数倍。

union Un2
{
	char c[5];
	int i;
};

union Un3
{
	short c[7];
	int i;
};

int main()
{
	printf("%d\n", sizeof(union Un2));//8
	printf("%d\n", sizeof(union Un3));//16
	system("pause");
	return 0;
}