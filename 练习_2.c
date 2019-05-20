#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>

//ģ��ʵ��strncppy  �������ڴ��ص��Ŀ���
char* my_strncpy(char* dst, const char* src, size_t n)
{
	assert(dst && src);
	char* ret = dst;

	while (n--)
	{
		*dst++ = *src++;
	}

	if (*(dst-1) != '\0')//�൱�ڼ�鸴�Ƶ��ֽ�����û�г���Դ�ַ���
	{
		*(dst) = '\0';
	}
	return ret;
}


//ģ��ʵ��strncat �ַ������Ӻ���

char* my_strncat(char* dst, const char* src, size_t n)
{
	assert(dst && src);
	char* ret = dst;

	while (*dst)//��dst�ƶ���'\0��λ�ã�
	{ 
		++dst;
	}

	while (n--)//����
	{
		*dst++ = *src++;
	}

	if (*(dst - 1) != '\0')//����Ƿ��srcָ����ַ����������
	{
		*dst = '\0';
	}

	return ret;
}

//ģ��ʵ��strncmp
int my_strncmp( const char* str1, const char* str2, size_t n)
{
	assert(str1 && str2);//�ж������Ƿ�Ϊ��

	while (n && (*str1 == *str2))
	{
		(char*)str1++;
		(char*)str2++;
		n--;
	}
	if (n > 0)
	{
		return *str1 - *str2;
	}

	return *(str1 - 1) - *(str2 - 1);
}

int main()
{
	char str1[] = "To be or not to be";
	char str2[40];
	char str3[40];
	char str4[40];

	my_strncpy(str2, str1, 8);
	my_strncpy(str3, str1+8, 10);
	my_strncat(str2, str3, 10);
	strcpy(str4, str2);


	puts(str1);
	puts(str2);
	puts(str3);
	puts(str4);

	char str[][5] = { "R2D2", "C3PO", "R2A6" };
	int n;
	puts("Looking for R2 astromech droids...");
	for (n = 0; n<3; n++)
	if (my_strncmp(str[n], "R2xx", 2) == 0)
	{
		printf("found %s\n", str[n]);
	}

	system("pause");
	return 0;
}