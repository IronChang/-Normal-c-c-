#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

struct s1
{
	double c1;
	char c2;
	int i;
};

struct s2
{
	char c1;
	int i;
	char c2;
};

struct s3
{
	char c1;
	char c2;
	int i;
};

struct s4
{
	char c1;
	struct s1 s3;
	double d;
};

int main()
{
	printf("%d\n", sizeof(struct s1));
	printf("%d\n", sizeof(struct s2));
	printf("%d\n", sizeof(struct s3));
	printf("%d\n", sizeof(struct s4));
	system("pause");
	return 0;
}

//修改默认对齐数
#pragma pack(6)
struct s5
{
	char c1;
	int i;
	double c2;
};
#pragma pack()
#pragma ppack(1)
struct s6
{
	char c1;
	int i;
	double c2;
};
#pragma pack()
int main()
{
	printf("%d\n", sizeof(struct s5));
	printf("%d\n", sizeof(struct s6));
	system("pause");
	return 0;
}
