#define _CRT_SECURE_NO_WARNINGS 1
#include<stdlib.h>
#include<string.h>
#include<assert.h>

/*1.strlen() ���ַ����ĳ���
   ����ԭ�� size_t strlen��const char * str��;
   size_t = unsigned int  �޷�������
*/

//ʵ��strlen��������

//����һ 
size_t my_strlen_1(const char* str)
{
	assert(str);//�����ж������ַ����Ƿ�Ϊ��
	size_t count = 0;
	while (*str != '\0')
	{
		++count;
		++str;
	}
	return count;
}

//������
size_t my_strlen_2(const char* str)
{
	assert(str);//�����ж�������ַ����Ƿ�Ϊ��
	
	const char* end = str;//����һ������������str��

	while (*++end);//���㡮\0����λ��

	return end - str;//ĩβ-�ײ������ǳ���
}

//���������ݹ飩
//�㽨��ʹ�ã���ʱ�ѿռ䣬����ջ���
size_t my_strlen_3(const char* str)
{
	assert(str);
	if (*str == '\0')
	{
		return 0;
	}
	else
	{
		return 1 + my_strlen_3(str + 1);
	}
}

int main()
{
	char str[] = { "hello world" };
	printf("%d\n", my_strlen_3(str));
	system("pause");
	return 0;
}

/*2.strcpy() �ַ�����������
����ԭ�� char * strcpy ( char * destination, const char * source );
ע�⣺
1.Copies the C string pointed by source into the array pointed by destination, including the terminating null character (and stopping at that point).
2.To avoid overflows, the size of the array pointed by destination shall be long enough to contain the same C string as source (including the terminating null character), and should not overlap in memory with source.
*/

//ʵ��strcpy��������

//����һ
char* my_strcpy(char* dst, const char* src)
{
	assert(dst && src);//��֤������ַ������ǿ��ַ���
    
	char* ret = dst;//����һ��ͬ����ָ��洢dst�ص�ַ

	while (*dst++ = *src++);//���и��Ƹ�ֵ

	return ret;
}

int main()
{
	char a[12] = {0};
	my_strcpy(a, "hello world");
	printf("%s\n", a);

	system("pause");
	return 0;
}

/*3.strcat() �����ַ�������
����ԭ�� char * strcat��char * destination��const char * source��;
ע�⣺
1.Appends a copy of the source string to the destination string. The terminating null character in destination is overwritten by the first character of source, and a null-character is included at the end of the new string formed by the concatenation of both in destination.
2.destination and source shall not overlap.
*/

//ʵ��strcat��������

//����һ
char* my_strcat(char* dst, const char* src)
{
	assert(dst && src);//��֤������ַ������ǿ��ַ���

	char* ret = dst;

	while (*dst != '\0')//��ָ���ƶ���dst�ַ����ġ�\0��λ����
	{
		++dst;
	}

	while (*dst++ = *src++);//���Ը��ӣ�ƴ��

	return ret;
}

int main()
{
	char str1[20] = { "hello" };
	my_strcat(str1, " world");
	printf("%s\n", str1);
	system("pause");
	return 0;
}

/*3.strcmp() �ַ����ȽϺ���
����ԭ�� int strcmp��const char * str1��const char * str2��;
ע�⣺
1.Compares the C string str1 to the C string str2.
2.This function starts comparing the first character of each string. If they are equal to each other, it continues with the following pairs until the characters differ or until a terminating null-character is reached.
3.This function performs a binary comparison of the characters. For a function that takes into account locale-specific rules, see strcoll.
4.<0	��ƥ��ĵ�һ���ַ���ptr1�е�ֵ������ptr2�е�ֵ
   0	�����ַ������������
  >0	��ƥ��ĵ�һ���ַ���ptr1�е�ֵ������ptr2�е�ֵ
*/

//ʵ��strcmp()����

int my_strcmp(const char* str1, const char* str2)
{
	assert(str1 && str2);//��֤�ж�������ַ������ǿյ�

	while (*str1 && *str2)//�������ַ�����λ���бȽϣ������ڡ�\0��֮ǰ
	{
		if (*str1 > *str2)
		{
			return 1;
		}
		else if (*str1 < *str2)
		{
			return -1;
		}
		else
		{
			++str1;
			++str2;
		}
	}

	if (*str1 != '\0')//����str2�ĳ���С��str1
	{
		return 1;
	}
	else if (*str2 != '\0')//����str1�ĳ���С��str2
	{
		return -1;
	}
	else//���������ַ�������һ�����Ҷ�һ��
	{
		return 0;
	}

}

int main()
{
		// p1 < p2 - 1;
		char* p1 = "abcd";
		char* p2 = "bbcd";
		printf("%d\n", my_strcmp(p1, p2));

		// p1 > p2  1;
		char* p3 = "bbcd";
		char* p4 = "bacd";
		printf("%d\n", my_strcmp(p3, p4));

		// p1 == p2 0;
		char* p5 = "bbcd";
		char* p6 = "bbcd";
		printf("%d\n", my_strcmp(p5, p6));

		system("pause");
		return 0;
}
