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

//int main()
//{
//	char p[] = "123456";
//	char q[] = "23";
//	char *r = strstr(p, q);
//	printf("r:%s\n", r);
//	getchar();
//	system("pause");
//	return 0;
//}

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

//int main()
//{
//	char a[] = { "hello world!" };
//	char c = 0;
//	scanf("%c", &c);
//	printf("%s\n", my_strchr(a, c));
//	system("pause");
//	return 0;
//}

/*3. memcpy()  复制内存块
函数原型 ：void * memcpy ( void * destination, const void * source, size_t num );
注意：将num指向的位置的num个字节值直接复制到destination指向的内存块。
源和目标指针指向的对象的基础类型与此函数无关;结果是数据的二进制副本。
该函数不检查源中的任何终止空字符 - 它始终复制精确的num个字节。
为避免溢出，目标和源参数指向的数组大小应至少为num个字节，
并且不应重叠（对于重叠的内存块，memmove是一种更安全的方法）。
*/

void* my_memcpy(void* dst,const void* src, int n)
{
	assert(dst && src);//保证输入的地址不能为空

	char* ret = dst;//暂存将来要返回的首地址
	while (n--)
	{
		*(char*)dst = *(const char*)src;//void类型不能进行解引用要进行强制类型转换
		++(char*)dst;//同样void类型不能进行++或--
		++(char*)src;
	}
	return ret;
}

//int main()
//{
//	int arr1[10] = { 0 };
//	int arr2[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//	my_memcpy(arr1, arr2, sizeof(arr2));
//	int sz = sizeof(arr1) / sizeof(arr1[0]);
//	for (int i = 0; i < sz; i++)
//	{
//		printf("%d ", arr1[i]);
//	}
//	system("pause");
//	return 0;
//}


/*4. memmove()  移动内存块 内存操作函数，不是字符串函数，可以处理多种数据类型
函数原型 ：void * memmove（void * destination，const void * source，size_t num）;
注意：将num字节的值从source指向的位置复制到destination指向的内存块。复制就像使用中间缓冲区一样，允许目标和源重叠。源指针和目标指针指向
的对象的基础类型与此函数无关; 结果是数据的二进制副本。 该函数不检查源中的任何终止空字符- 它始终复制精确的num个字节。 为了避免溢出，数组的大小由两者指向
目标和源参数应至少为num个字节。
*/

void* my_memmove(void* dst, const void* src, int n)
{
	assert(dst && src);//判断输入的地址是否为空
	char* ret = dst;//暂存dst地地址，最后返回

	if ((char*)dst <= (char*)src && (char*)dst >= (char*)src + n)//正常情况下从前往后拷贝  
	{
		while (n--)
		{
			*(char*)dst = *(char*)src;//还要注意强制类型转换
		}
	}
	else//当出现内存覆盖时从后往前拷贝  
	{
		while (n--)
		{
			*((char*)dst + n) = *((char*)src + n);//还要注意强制类型转换
		}
	}
	return ret;
}

int main()
{
	char str[] = "memmove can be very useful......";
	my_memmove(str + 20, str + 15, 11);
	puts(str);
    system("pause");
	return 0;
}
	

