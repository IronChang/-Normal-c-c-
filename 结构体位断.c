#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>


//λ�γ�Ա������int ,unsigned int,char(�������ͼ���)����
struct S1
{
	int a : 3;//��ʼʱint�����Կռ�����4���ֽڿ��ٵ�
	int b : 4;
	int c : 31;
	int d : 4;
};

struct S2
{
	char a : 6;//��ʼʱchar�����Կռ�����1���ֽڿ��ٵ�
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
