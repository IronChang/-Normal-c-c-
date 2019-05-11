#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<assert.h>

/* 1. char * strncpy（char * destination，const char * source，size_t num） 拷贝num位字符数
   含义：将源的前num个字符复制到目标。如果在复制num个字符之前找到源 C字符串的结尾（由空字符表示），则使用零填充目标，直到已向其写入总共num个字符。如果source长于num，则不会在目标末尾隐式附加空字符。因此，在这种情况下，目标不应被视为空终止的C字符串（因此读取它会溢出）.目的地和
     源不应重叠（重叠时请参阅memmove以获得更安全的替代方案）。
   注意：strncpy的功能和strcpy相似，只是它复制时多了一个终止条件。即是未遇到原串的’\0’，如果已经复制了n个字符（n为提供的参数长度），复制同样会终止。
*/

char* my_strncpy(char* dst, const char* src, size_t n)
{
	assert(dst && src);//断言判断输入不为空
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

//sizeof()在计算字符串数组是计算'\0'

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

/* 2. char * strncat（char * destination，const char * source，size_t num） 链接前num字符数
   含义：将源的前num个字符追加到destination，再加上一个终止的null字符。 如果source中 C字符串的长度小于num，则仅复制终止空字符的内容。
   注意;strncat的功能和strcat相似，只是链接时多了一个终止条件。即未遇到原串的终止空字符'\0'，如果已经连接了num个字符，复制同样终止。
*/

char* my_strncat_1(char* dst,  const char* src, size_t n)
{
	assert(dst && src);
	char* ret = dst;

	while (*dst)//将dst指针指向其字符串'\0'地位置
		++dst;

	while (n--)
	{
		*dst = *src;
		dst++;
		src++;
	}

	if (*(dst - 1) != '\0')//判断当n给链接完了是否有'\0’，没有就加上
	{
		*dst = '\0';
	}

	return ret;
}

char* my_strncat_2(char* dst, const char* src, size_t num)
{
	assert(dst && src);
	char* ret = dst;

	while (*dst)//把指针移到“\0”的位置上
		++dst;

	while (num--)
	{
		*dst = *src;
		++dst;
		++src;
	}

	*dst = '\0';//最后一位补'\0'

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

/* 3. int strncmp（const char * str1，const char * str2，size_t num）;
   含义：将C字符串str1的最多num个字符与C字符串str2的字符进行比较。 此函数开始比较每个字符串的第一个字符。如果它们彼此相等，则继续使用以下对，直到字符不同，直到达到终止空字符，或者直到num字符在两个字符串中匹配，以先发生者为准。
   注意：strncmp的功能和strcmp相似，只是比较时有了较小的变化，前者可以只比较字符串前num给字符数，而后者要全部比较，也就是多了一个终止条件罢了。
*/

int my_strncmp(const char* str1, const char* str2, size_t n)
{
	assert(str1 && str2);//判断是否输入为空

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