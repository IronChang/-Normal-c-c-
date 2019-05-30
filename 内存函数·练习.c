#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<assert.h>
#include<windows.h>
#include<string.h>

//内存不应该重叠
void* my_memcpy(void*dst, const void* src, size_t num)
{
	assert(dst&&src);

	//进行强制类型转换void*不能进行解引用和进行++或--
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

	if (dst_ < src_)//内存不重叠  从前往后复制
	{
		while (num--)
		{
			*dst_++ = *src_++;
		}
	}
	else//内存重叠  从后向前复制
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

//字符查找函数
//参数int先进行整形提升，在进行截断
//返回第一次出现字符的位置
char* my_strchr(const char* str, int charactor)
{
	assert(str);//检查输入的字符串是否为空
    
	char c = (char)charactor;//截断

	while (*str)
	{
		if (*str == c)
		{
			return str;
		}
		++str;
	}

	printf("没有这个字符!!!\n");
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