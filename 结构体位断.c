#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>


//位段成员可以是int ,unsigned int,char(属于整型家族)类型
struct S1
{
	int a : 3;//开始时int，所以空间是以4个字节开辟的
	int b : 4;
	int c : 31;
	int d : 4;
};

struct S2
{
	char a : 6;//开始时char，所以空间是以1个字节开辟的
	char b : 5;
	char c : 3;
	char d : 7;
};

int main()
{
	printf("%d\n", sizeof(struct S1));
	printf("%d\n", sizeof(struct S2));
	system("PAUSE");
	return 0;
}
