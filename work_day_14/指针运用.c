#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>

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

//void left_move(char* str, int n)
//{
//	assert(str != NULL);
//	while (n--)
//	{
//		char* cur = str;
//		char tmp = *cur;//����һ��Ԫ�ش���tmp��
//
//		while (*(cur + 1) != '\0')
//		{
//			*cur = *(cur + 1);
//				cur++;
//		}
//
//		*cur = tmp;
//	}
//}

//int main()
//{
//	char arr[] = "ABCDE";
//	int n = 0;
//
//	printf("������Ҫ�����ĸ���:>");
//	scanf("%d", &n);
//	left_move(arr, n);
//	printf("%s", arr);
//
//	system("pause");
//	return 0;
//}

//��д������ת��

//void reverse(char* left, char* right)//��ת����
//{
//	while (left < right)
//	{
//		char tmp = *left;
//		*left = *right;
//		*right = tmp;
//		left++;
//		right--;
//	}
//}

//void left_move(char* str, int n)
//{
//	int len = strlen(str);
//	reverse(str, str + len - 1);
//	reverse(str + n, str + len - 1);
//	reverse(str, str + n - 1);
//}

//int main()
//{
//	char arr[] = "ABCDE";
//	int n = 0;
//	printf("������Ҫ�����ĸ���:>");
//	scanf("%d", &n);
//	left_move(arr, n);
//
//	system("pause");
//	return 0;
//}


/*
2.�ж�һ���ַ����Ƿ�Ϊ����һ���ַ�����ת֮����ַ����� 
���磺����s1 =AABCD��s2 = BCDAA������1 
����s1=abcd��s2=ACBD������0. 

AABCD����һ���ַ��õ�ABCDA 
AABCD���������ַ��õ�BCDAA 

AABCD����һ���ַ��õ�DAABC
*/

//������λ����ÿ���ƶ�һλ�ͽ���һ�αȽϣ�ͨ���������ж�
//int judge_left(char* str1, char* str2)
//{
//	int i = 0;
//	int j = 0;
//	int len = strlen(str1);//ͨ���������ַ�������
//
//	for (i = 0; i < len - 1; i++)
//	{
//
//		int tmp = str1[0];
//		for (j = 0; j < len - 1; j++)
//		{
//			str1[j] = str1[j + 1];
//		}
//		str1[len - 1] = tmp;
//		if (0 == strcmp(str1, str2))
//		{
//			return 1;
//		}
//	}
//	return 0;
//}

//int main()
//{
//	char s1[] = "0";
//	char s2[] = "0";
//
//	gets(s1);
//	gets(s2);
//	int ret = 0;
//	ret = judge_left(s1, s2);
//	printf("%d\n",ret);
//
//	system("pause");
//	return 0;
//}

//������λ����ÿ���ƶ�һλ�ͽ���һ�αȽϣ�ͨ���������ж�

//int judge_right(char* str1, char* str2)
//{
//	int i = 0;
//	int j = 0;
//	int len = strlen(str2);//ͨ���������ַ�������
//
//	for (i = len - 1; i >= 0;i--)
//	{
//		char tmp = str2[len-1];
//		for (j = len - 1; j >= 0; j--)
//		{
//			str2[j] = str2[j - 1];
//		}
//		str2[0] = tmp;
//		if (0 == strcmp(str1, str2))
//		{
//			return 1;
//		}
//	}
//	return 0;
//}

//int main()
//{
//	char s1[] = "0";
//	char s2[] = "0";
//
//	gets(s1);
//	gets(s2);
//	int ret = 0;
//	ret = judge_right(s1, s2);
//	printf("%d\n", ret);
//
//	system("pause");
//	return 0;
//}