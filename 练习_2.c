#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>

//模拟实现strncppy  不包含内存重叠的可能
char* my_strncpy(char* dst, const char* src, size_t n)
{
	assert(dst && src);
	char* ret = dst;

	while (n--)
	{
		*dst++ = *src++;
	}

	if (*(dst-1) != '\0')//相当于检查复制的字节数有没有超过源字符串
	{
		*(dst) = '\0';
	}
	return ret;
}


//模拟实现strncat 字符串连接函数

char* my_strncat(char* dst, const char* src, size_t n)
{
	assert(dst && src);
	char* ret = dst;

	while (*dst)//把dst移动到'\0的位置；
	{ 
		++dst;
	}

	while (n--)//链接
	{
		*dst++ = *src++;
	}

	if (*(dst - 1) != '\0')//检查是否把src指向的字符串复制完成
	{
		*dst = '\0';
	}

	return ret;
}

//模拟实现strncmp
int my_strncmp( const char* str1, const char* str2, size_t n)
{
	assert(str1 && str2);//判断输入是否为空

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