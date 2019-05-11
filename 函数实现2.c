#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<assert.h>

/* 1. char * strncpy��char * destination��const char * source��size_t num�� ����numλ�ַ���
   ���壺��Դ��ǰnum���ַ����Ƶ�Ŀ�ꡣ����ڸ���num���ַ�֮ǰ�ҵ�Դ C�ַ����Ľ�β���ɿ��ַ���ʾ������ʹ�������Ŀ�ֱ꣬��������д���ܹ�num���ַ������source����num���򲻻���Ŀ��ĩβ��ʽ���ӿ��ַ�����ˣ�����������£�Ŀ�겻Ӧ����Ϊ����ֹ��C�ַ�������˶�ȡ���������.Ŀ�ĵغ�
     Դ��Ӧ�ص����ص�ʱ�����memmove�Ի�ø���ȫ�������������
   ע�⣺strncpy�Ĺ��ܺ�strcpy���ƣ�ֻ��������ʱ����һ����ֹ����������δ����ԭ���ġ�\0��������Ѿ�������n���ַ���nΪ�ṩ�Ĳ������ȣ�������ͬ������ֹ��
*/

char* my_strncpy(char* dst, const char* src, size_t n)
{
	assert(dst && src);//�����ж����벻Ϊ��
	char* ret = dst;

	while (n--)
	{
		*dst++ = *src++;
	}

	if (*(dst - 1) != '\0')
	{
		*dst = '\0';
	}

	return ret;
}

//sizeof()�ڼ����ַ��������Ǽ���'\0'

//int main()
//{
//	char str1[] = "To be or not to be";
//	char str2[40];
//	char str3[40];
//
//	my_strncpy(str2, str1,8);
//	my_strncpy(str3, str1, 5);
//	
//	puts(str1);
//	puts(str2);
//	puts(str3);
//
//	system("pause");
//	return 0;
//}

/* 2. char * strncat��char * destination��const char * source��size_t num�� ����ǰnum�ַ���
   ���壺��Դ��ǰnum���ַ�׷�ӵ�destination���ټ���һ����ֹ��null�ַ��� ���source�� C�ַ����ĳ���С��num�����������ֹ���ַ������ݡ�
   ע��;strncat�Ĺ��ܺ�strcat���ƣ�ֻ������ʱ����һ����ֹ��������δ����ԭ������ֹ���ַ�'\0'������Ѿ�������num���ַ�������ͬ����ֹ��
*/

char* my_strncat_1(char* dst,  const char* src, size_t n)
{
	assert(dst && src);
	char* ret = dst;

	while (*dst)//��dstָ��ָ�����ַ���'\0'��λ��
		++dst;

	while (n--)
	{
		*dst = *src;
		dst++;
		src++;
	}

	if (*(dst - 1) != '\0')//�жϵ�n�����������Ƿ���'\0����û�оͼ���
	{
		*dst = '\0';
	}

	return ret;
}

char* my_strncat_2(char* dst, const char* src, size_t num)
{
	assert(dst && src);
	char* ret = dst;

	while (*dst)//��ָ���Ƶ���\0����λ����
		++dst;

	while (num--)
	{
		*dst = *src;
		++dst;
		++src;
	}

	*dst = '\0';//���һλ��'\0'

	return ret;
}

//int main()
//{
//	char str1[20];
//	char str2[20];
//	char str3[20];
//
//
//	strcpy(str1, "To be ");
//	strcpy(str2, "or not to be");
//	//my_strncat_1(str1, str2, 18);
//	my_strncat_2(str1, str2, 18);
//	strcpy(str3, str1);
//	puts(str1);
//	puts(str3);
//
//	system("pause");
//	return 0;
//}

/* 3. int strncmp��const char * str1��const char * str2��size_t num��;
   ���壺��C�ַ���str1�����num���ַ���C�ַ���str2���ַ����бȽϡ� �˺�����ʼ�Ƚ�ÿ���ַ����ĵ�һ���ַ���������Ǳ˴���ȣ������ʹ�����¶ԣ�ֱ���ַ���ͬ��ֱ���ﵽ��ֹ���ַ�������ֱ��num�ַ��������ַ�����ƥ�䣬���ȷ�����Ϊ׼��
   ע�⣺strncmp�Ĺ��ܺ�strcmp���ƣ�ֻ�ǱȽ�ʱ���˽�С�ı仯��ǰ�߿���ֻ�Ƚ��ַ���ǰnum���ַ�����������Ҫȫ���Ƚϣ�Ҳ���Ƕ���һ����ֹ�������ˡ�
*/

int my_strncmp(const char* str1, const char* str2, size_t n)
{
	assert(str1 && str2);//�ж��Ƿ�����Ϊ��

	while (n && (*str1 == *str2))
	{
		(char*)str1++;
		(char*)str2++;
		n--;
	}
	if (n > 0)
		return *str1 - *str2;

	return *(str1 - 1) - *(str2 - 1);
}

#include <stdio.h>
#include <string.h>

int main()
{
	char str[][5] = { "R2D2", "C3PO", "R2A6" };
	int n;
	puts("Looking for R2 astromech droids...");
	for (n = 0; n<3; n++)
	if (strncmp(str[n], "R2xx", 2) == 0)
	{
		printf("found %s\n", str[n]);
	}
	system("pause");
	return 0;
}