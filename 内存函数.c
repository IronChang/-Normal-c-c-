#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<assert.h>

char* my_strstr_1(const char* dst, const char* src)
{
	assert(dst && src);

	const char* dst_;//原指针不能随便动，比较时新设两个指针比较
	const char* src_;

	while (*dst)
	{
		dst_ = dst;
		src_ = src;
		do
		{
			if (!*src_)
			{
				return dst;
			}
		} while (*dst_++ == *src_++);
		dst++;
	}
	return NULL;
}

char* my_strstr_2(const char* dst, const char* src)
{
	assert(dst && src);
	while (*dst)
	{
		const char* dst_ = dst;
		const char* src_ = src;

		while (*src_ && *dst_ == *src_)
		{
			++dst_;
			++src_;
		}
		if (*src_ == '\0')
			return dst;
		else
			dst++;
	}
}

//int main()
//{
//	char str[] = "This is a simple string";
//	char * pch;
//	pch = my_strstr_1(str, "simple");
//	strncpy(pch, "sample", 6);
//	puts(str);
//	system("pause");
//	return 0;
//}

void* my_memcpy(void* dst, const void* src, size_t num)
{
	assert(dst && src);

	//进行强制类型转换 void*不能进行解引用和进行++或--
	char* dst_ = (char*)dst;
	const char* src_ = (const char*)src;
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
//	my_memcpy(arr3, arr4, sizeof(arr4));
//	int sz = sizeof(arr1) / sizeof(arr1[0]);
//	puts(arr3);
//	for (int i = 0; i < sz; i++)
//	{
//		printf("%d ", arr1[i]);
//	}
//	printf("\n");
//	system("pause");
//	return 0;
//}

void* my_memmove(void* dst, const void* src, size_t num)//考虑内存重叠
{
	assert(dst && src);

	char* dst_ = (char*)dst;
	const char* src_ = (const char*)src;
	//char* ret = (char*)dst;

	if (dst_ > src_ && dst_ < src_ + num)//内存重叠
	{
		while (num--)
		{
			*(dst_ + num) = *(src_ + num);
		}
	}
	else
	{
		while (num--)
		{
			*dst_++ = *src_++;
		}
	}
	return dst;
}

int main()
{
	char str[] = "memmove can be very useful......";
	char arr2[20] = { "hello " };
	char arr3[] = { "world" };
	my_memcpy(arr2 + 6, arr3, sizeof(arr3));
	my_memmove(str + 20, str + 15, 11);
	puts(arr2);
	puts(str);
	system("pause");
	return 0;
}