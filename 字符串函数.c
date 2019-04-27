#define _CRT_SECURE_NO_WARNINGS 1
#include<stdlib.h>
#include<string.h>
#include<assert.h>

/*1.strlen() 求字符串的长度
   函数原型 size_t strlen（const char * str）;
   size_t = unsigned int  无符号整形
*/

//实现strlen（）函数

//方法一 
size_t my_strlen_1(const char* str)
{
	assert(str);//断言判断输入字符串是否为空
	size_t count = 0;
	while (*str != '\0')
	{
		++count;
		++str;
	}
	return count;
}

//方法二
size_t my_strlen_2(const char* str)
{
	assert(str);//断言判断输入的字符串是否为空
	
	const char* end = str;//声明一个变量，来接str；

	while (*++end);//计算‘\0’的位置

	return end - str;//末尾-首部，就是长度
}

//方法三（递归）
//你建议使用，费时费空间，容易栈溢出
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

/*2.strcpy() 字符串拷贝函数
函数原型 char * strcpy ( char * destination, const char * source );
注意：
1.Copies the C string pointed by source into the array pointed by destination, including the terminating null character (and stopping at that point).
2.To avoid overflows, the size of the array pointed by destination shall be long enough to contain the same C string as source (including the terminating null character), and should not overlap in memory with source.
*/

//实现strcpy（）函数

//方法一
char* my_strcpy(char* dst, const char* src)
{
	assert(dst && src);//保证数入的字符串不是空字符串
    
	char* ret = dst;//声明一个同类型指针存储dst地地址

	while (*dst++ = *src++);//进行复制赋值

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

/*3.strcat() 附加字符串函数
函数原型 char * strcat（char * destination，const char * source）;
注意：
1.Appends a copy of the source string to the destination string. The terminating null character in destination is overwritten by the first character of source, and a null-character is included at the end of the new string formed by the concatenation of both in destination.
2.destination and source shall not overlap.
*/

//实现strcat（）函数

//方法一
char* my_strcat(char* dst, const char* src)
{
	assert(dst && src);//保证数入的字符串不是空字符串

	char* ret = dst;

	while (*dst != '\0')//将指针移动到dst字符串的‘\0’位置上
	{
		++dst;
	}

	while (*dst++ = *src++);//进性附加，拼接

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

/*3.strcmp() 字符串比较函数
函数原型 int strcmp（const char * str1，const char * str2）;
注意：
1.Compares the C string str1 to the C string str2.
2.This function starts comparing the first character of each string. If they are equal to each other, it continues with the following pairs until the characters differ or until a terminating null-character is reached.
3.This function performs a binary comparison of the characters. For a function that takes into account locale-specific rules, see strcoll.
4.<0	不匹配的第一个字符在ptr1中的值低于在ptr2中的值
   0	两个字符串的内容相等
  >0	不匹配的第一个字符在ptr1中的值大于在ptr2中的值
*/

//实现strcmp()函数

int my_strcmp(const char* str1, const char* str2)
{
	assert(str1 && str2);//保证判断输入的字符串不是空的

	while (*str1 && *str2)//把两个字符串逐位进行比较，都是在‘\0’之前
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

	if (*str1 != '\0')//表明str2的长度小于str1
	{
		return 1;
	}
	else if (*str2 != '\0')//表明str1的长度小于str2
	{
		return -1;
	}
	else//表明两个字符串长度一样，且都一样
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
