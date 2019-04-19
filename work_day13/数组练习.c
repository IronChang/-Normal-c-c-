#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>

#define N 3

//1.��������ʹ����ȫ����λ��ż��ǰ�档
//��Ŀ��
//����һ���������飬ʵ��һ��������
//�����������������ֵ�˳��ʹ�����������е�����λ�������ǰ�벿�֣�
//����ż��λ������ĺ�벿�֡�

void adjust(int a[], int sz)
{
	int start = 0;
	int end = sz - 1;

	while (start < end)
	{
		//���������ҵ�һ��ż��
		while (a[start] % 2 != 0)
		{
			++start;
		}
		//���������ҵ�һ������
		while (a[end] % 2 != 1)
		{
			--end;
		}
		if (start < end)
		{
			a[start] = a[start] ^ a[end];
			a[end] = a[start] ^ a[end];
			a[start] = a[start] ^ a[end];
		}

	}
}

int main()
{
	int a[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	adjust(a, 10);
	for (int i = 0; i < 10; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");

	system("pause");
	return 0;
}


//2.
////���Ͼ��� 
//��һ����ά����.
//�����ÿ�д������ǵ����ģ�ÿ�д��ϵ����ǵ�����.
//�������������в���һ�������Ƿ���ڡ�
//ʱ�临�Ӷ�С��O(N);
//���飺
//1 2 3
//2 3 4
//3 4 5
//
//1 3 4
//2 4 5
//4 5 6
//
//1 2 3
//4 5 6
//7 8 9


//1.ʵ��һ�����������������ַ����е�k���ַ���
//ABCD����һ���ַ��õ�BCDA
//ABCD���������ַ��õ�CDAB

/*��һ�뷨����ת�ַ��������ⲻ��ϸ����
�ٴ������뵽���η�ת���Ƚ������巭ת��
�ڽ��з�ת���ַ�ת���ڷ�תʣ�²���
*/

//ԭ�����ⲻ���棬����̫��Է�ת�ַ����㷨���ǲ���Ϥ

//�Լ�д����������
//�����������η�ת

/*
void adjustALL(char* left ,char* right,int n)//�����
{
	for (int i = 0; i < n; i++)//��ǰn���ַ���ת�����
	{
		while (left < right)
		{
			char tmp = *left;
			*left = *right;
			*right = tmp;
			left++;
			right--;
		}
	}
}

void adjustleft(int n,char a[F])//����ǰn���ַ���
{
	int len = n+1;

	for (int i = 0; i < len/2; i++)
	{
		char tmp = a[i];
		a[i] = a[len-i-1];
		a[len - i - 1] = tmp;
	}
}

void adjustright(int n,char a[F],int len)//������n���ִ�
{
	
	for (int i = 0; i < n/2; i++)
	{
		char tmp = a[i+ (n + 1)];
		a[i+n+1] = a[len - i - 1];
		a[len - i - 1] = tmp;
	}
}

int main()
{
	char a[F] = { "abcdefg" };
    int n = 0;
	int len = strlen(a);

	printf("������Ҫ�������ַ�����:>\n");
	scanf("%d", &n);
	adjustALL(a,a+F-1,n);//����ȫ������
	adjustleft(n, a);//����ǰF-n��
	adjustright(n, a, F);//������n��

	for (int i = 0; i < F; i++)
	{
		printf("%c", a[i]);
	}
	printf("\n");

	system("pause");
	return 0;
}
*/


//������λ��
void left_move(char* str, int n)
{
	assert(str != NULL);
	while (n--)
	{
		char* cur = str;
		char tmp = *cur;//����һ��Ԫ�ش���tmp��

		while (*(cur + 1) != '\0')
		{
			*cur = *(cur + 1);
				cur++;
		}

		*cur = tmp;
	}
}

int main()
{
	char arr[] = "ABCDE";
	int n = 0;

	printf("������Ҫ�����ĸ���:>");
	scanf("%d", &n);
	left_move(arr, n);
	printf("%s", arr);

	system("pause");
	return 0;
}

//��д������ת��

void reverse(char* left, char* right)//��ת����
{
	while (left < right)
	{
		char tmp = *left;
		*left = *right;
		*right = tmp;
		left++;
		right--;
	}
}

void left_move(char* str, int n)
{
	int len = strlen(str);
	reverse(str, str + len - 1);
	reverse(str + n, str + len - 1);
	reverse(str, str + n - 1);
}

int main()
{
	char arr[] = "ABCDE";
	int n = 0;
	printf("������Ҫ�����ĸ���:>");
	scanf("%d", &n);
	left_move(arr, n);

	system("pause");
	return 0;
}