#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct st_type
{
	int i;
	char a[0];//��������  int[]Ҳ���Ա��
}type;

void send(type* m)
{
	printf("%d\n%s\n", m->i, m->a);
}

int main()
{
	printf("%d\n", sizeof(type));//�����С�£���������������Ĵ�С��
	type* p = (type*)malloc(sizeof(type)+100 * sizeof(int));//�����ڴ�ʱ��Ҫ���ڽṹ�屾��
	p->i = 210;
	strcpy(p->a, "hello bit");
	send(p);
	free(p);
	system("pause");
	return 0;
}

typedef struct type
{
	char i;
	char* p_a;
}type;

void send(type* m)
{
	printf("%d\n%s\n", m->i, m->p_a);
}

int main()
{
	type* p = malloc(sizeof(type));
	p->i = 100;
	p->p_a = (char*)malloc(p->i * 10);
	strcpy(p->p_a, "hello fuck");
	send(p);
	free(p);
	system("pause");
	return 0;
}

