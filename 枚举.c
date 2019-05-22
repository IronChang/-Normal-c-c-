#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

//enum color
//{
//	RED = 1,
//	GREEN=2,
//	BIUE=4
//};

//enum Num
//{
//	x1=-2,
//	x2 ,
//	x3=50,
//	x4
//};
//
//int main()
//{
//	enum Num a,b,c,d;
//	a = x1;
//	b = x2;
//	c = x3;
//	d = x4;
//	printf("%d\n%d\n%d\n%d\n", a, b, c, d);
//	system("pause");
//	return 0;
//}

enum body
{
	a, b, c, d
};
int main()
{

	int month[31];
	int j = a;
	int i;
	for (i = 1; i <= 30; i++){
		month[i] = j;
		j++;
		if (j>d) j = a;
	}
	for (i = 1; i <= 30; i++){
		switch (month[i])
		{
		case a:printf(" %2d %c\t", i, 'a'); break;
		case b:printf(" %2d %c\t", i, 'b'); break;
		case c:printf(" %2d %c\t", i, 'c'); break;
		case d:printf(" %2d %c\t", i, 'd'); break;
		default:break;
		}
	}
	printf("\n");

	system("pause");
	return 0;
}