#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<assert.h>
#include<windows.h>
#include<string.h>

//�ڴ治Ӧ���ص�
void* my_memcpy(void*dst, const void* src, size_t num)
{
	assert(dst&&src);

	//����ǿ������ת��void*���ܽ��н����úͽ���++��--
	char* dst_ = (char*)dst;
	const char* src_ = (char*)src;
	char* ret = (char*)dst;

	while (num--)
	{
		*dst_ = *src_;
		++dst_;
		++src_;
	}
	return ret;
}

//int main()
//{
//	int arr1[10] = { 0 };
//	int arr2[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//	char arr3[100] = { 0 };
//	char arr4[] = { "hello world" };
//	my_memcpy(arr1, arr2, sizeof(arr2));
//	my_memcpy(arr3, arr4, 5);
//	int sz = sizeof(arr1) / sizeof(arr1[0]);
//	puts(arr3);
//	for (int i = 0; i < sz; i++)
//	{
//			printf("%d ", arr1[i]);
//	}
//	system("pause");
//	return 0;
//}

void* my_memmove(void* dst, const void* src, size_t num)
{
	assert(dst&&src);

	char* dst_ = (char*)dst;
	const char* src_ = (const char*)src;
	char* ret = (char*)dst;

	if (dst_ < src_)//�ڴ治�ص�  ��ǰ������
	{
		while (num--)
		{
			*dst_++ = *src_++;
		}
	}
	else//�ڴ��ص�  �Ӻ���ǰ����
	{
		while (num--)
		{
			*(dst_ + num) = *(src_ + num);
		}
	}
	return dst;
}

//int main()
//{
//	char str[] = "memmove can be very useful......";
//	memmove(str + 20, str + 15, 11);
//	puts(str);
//
//	system("pause");
//	return 0;
//}

//�ַ����Һ���
//����int�Ƚ��������������ڽ��нض�
//���ص�һ�γ����ַ���λ��
char* my_strchr(const char* str, int charactor)
{
	assert(str);//���������ַ����Ƿ�Ϊ��
    
	char c = (char)charactor;//�ض�

	while (*str)
	{
		if (*str == c)
		{
			return str;
		}
		++str;
	}

	printf("û������ַ�!!!\n");
}

//int main()
//{
//	char str[] = "This is a sample string";
//	char * pch;
//	printf("Looking for the 's' character in \"%s\"...\n", str);
//	pch = strchr(str, 's');
//	while (pch != NULL)
//	{
//		printf("found at %d\n", pch - str + 1);
//		pch = strchr(pch + 1, 's');
//	}
//
//	system("pause");
//	return 0;
//}

char* my_strstr(const char* dst, const char* src)
{
	assert(dst&&src);

	while (*dst)
	{
		const char* dst_ = dst;
		const char* src_ = src;

		while (*src_&&*dst_ == *src_)
		{
			++dst_;
			++src_;
		}
		if (*src == '\0')
		{
			return dst;
		}
		else
		{
			dst++;
		}
	}
}

int main()
{
	char str[] = "This is a simple string";
	char * pch;
	pch = strstr(str, "simple");
	strncpy(pch, "sample", 6);
	puts(str);

	system("pause");
	return 0;
}