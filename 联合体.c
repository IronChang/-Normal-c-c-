#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

//��������һ��������Զ������ͣ��������Ͷ���ı���Ҳ����һϵ�еĳ�Ա����������Щ��Ա����һ��ռ䣨��������Ҳ�й����壩��

union Un
{
	char c;
	int i;
};

union Un un;

//int main()
//{
//	printf("%d\n", sizeof(un));//���ϵĴ�С����������Ա�Ĵ�С
//	system("pause");
//	return 0;
//}


//������ĳ�Ա�ǹ���ͬһ���ڴ�ռ䣬����һ�����ϱ����Ĵ�С������������Ա�Ĵ�С
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

//�������С����
//1 ���ϵĴ�С����������Ա�Ĵ�С
//2 ��ǰ����Ա��С����������������������ʱ�򣬾�Ҫ���뵽������������������

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