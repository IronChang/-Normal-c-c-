#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<assert.h>

/*1. strstr( ) 寻找子字符串
函数原型 char *strstr( const char* str, const char* substr );
意义：判断str2是否为str1的字串，若是则返回str2在str1中首次出现的指针位置，若不是返回NULL
注意：匹配过程不包括终止空字符，但它会在那里停止。
子串：是字符串的子集，并且出现的顺序和字符串中出现的顺序是一样的，是连续的
子序列:不一定是连续的
*/

char* strstr(const char* src, const char* sub)
{
	const char *bp;
	const char *sp;
	if (!src || !sub)
	{
		return src;
	}
	/* 遍历src字符串  */
	while (*src)
	{
		/* 用来遍历子串 */
		bp = src;
		sp = sub;
		do
		{
			if (!*sp)  /*到了sub的结束位置，返回src位置   */
				return src;
		} while (*bp++ == *sp++);
		src++;
	}
	return NULL;
}

int main()
{
	char p[] = "123456";
	char q[] = "23";
	char *r = strstr(p, q);
	printf("r:%s\n", r);
	getchar();
	system("pause");
	return 0;
}

/*2. strchr() 根据某个字符切割字符串
函数原型 char * strchr ( const char *, int ); 
注意：在字符串中找到第一个出现的字符，返回指向C字符串str中第一个字符出现的指针。终止空字符被认为是C字符串的一部分。
因此，也可以定位它以便检索指向字符串末尾的指针。
注意：查找字符串s中首次出现字符c的位置,返回首次出现c的位置的指针，如果s中不存在c则返回NULL。
*/

char*  my_strchr(const char* dst, int c)
{
	assert(dst);

	while (*dst != '\0')
	{
		if (*dst == c)
		{
			return dst;
		}
		dst++;
	}
	return NULL;
}

int main()
{
	char a[] = { "hello world!" };
	char c = 0;
	scanf("%c", &c);
	printf("%s\n", my_strchr(a, c));
	system("pause");
	return 0;
}