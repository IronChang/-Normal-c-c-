#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

//1.一个数组中只有两个数字是出现一次，
//其他所有数字都出现了两次。
//找出这两个只出现一次的数字，编程实现。

//不合理的暴力求解法（会改变原来数组的内容）

//void search_ones(int* arr,int sz)
//{
//	int i = 0;
//	int j = 0;
//
//	for (i = 0; i < sz; i++)
//	{
//		for (j = i + 1; j < sz; j++)
//		{
//			if (arr[i] == arr[j])
//			{
//				arr[i] = 0;
//				arr[j] = 0;
//			}
//
//		}
//	}
//	printf("出现过一次的数字:>");
//	for (i = 0; i < sz; i++)
//	{
//		if (arr[i] != 0)
//		{
//			printf("%d ", arr[i]);
//		}
//	}
//	printf("\n");
//}

//int main()
//{
//	int a[] = { 4,2,8,6,5,7,8,4,6,5};
//	int len = sizeof(a) / sizeof(a[0]);
//
//	printf("数组元素:>");
//	for (int i = 0; i < len; i++)
//	{
//		printf("%d ", a[i]);
//	}
//	printf("\n");
//	search_ones(a, len);
//
//	system("pause");
//	return 0;
//}

//合理的解法
void find_ones(int arr[], int sz)
{
	int i = 0;
	int ret = 0;//存放所有值的异或结果
	int pos = 0;//存放ret二进制第一个为1的位置
	int x = 0;
	int y = 0;

	for (i = 0; i < sz; i++)//数组的值全部异或
	{
		ret ^= arr[i];
	}

	for (i = 0; i < 32; i++)//拿到ret中第一为1的位置
	{
		if (1 == ((ret >> i) & 1))
		{
			pos = i;
			break;
		}
	}

	for (i = 0; i < sz; i++)//进行异或分成两组，分别异或的到两个值
	{
		if (1 == ((arr[i] >> pos) & 1))
		{
			x ^= arr[i];
		}
		else
		{
			y ^= arr[i];
		}
	}

	printf("%d  %d\n", x, y);
}

int main()
{
	int a[] = { 4, 2, 8, 6, 5, 7, 8, 4, 6, 5 };
	int len = sizeof(a) / sizeof(a[0]);
	find_ones(a, len);

	system("pause");
	return 0;
}

//2.喝汽水，1瓶汽水1元，2个空瓶可以换一瓶汽水，
//给20元，可以喝多少汽水。
//编程实现。

//int main()
//{
//	int m = 0;
//	int sum = 0;
//	int n = 0;
//	scanf("%d", &m);
//	sum = m;
//	while (m > 2)//用空瓶换饮料
//	{
//		m = m / 2;
//		sum +=m;
//	}
//	printf("%d\n", sum);
//	system("pause");
//	return 0;
//}


/*3.模拟实现strcpy

函数功能：将source指向的C字符串复制到destination指向的数组中，包括终止空字符（并在该点停止）。
为避免溢出，目标指向的数组大小应足够长，以包含与源相同的C字符串（包括终止空字符），并且不应在内存中与源重叠。

问题分析: 函数原型 char * strcpy（char * destination，const char * source）;

解释一下返回类型为 char* 的原因  使函数支持链式表达式，方便复制，增加函数灵活性。
*/

//自己写的，但是需要传三个参数

//void my_strcpy(char* a,const char* b,int len)
//{
//	for (int i = 0; i < len; i++)
//	{
//		a[i] = b[i];
//	}
//}

//int main()
//{
//	char arr1[] = { "abcdef" };
//	char arr2[] = {0};
//
//	int len = sizeof(arr1) / sizeof(arr1[0]);
//	my_strcpy(arr2, arr1,len);
//	printf("%s\n", arr2);
//
//	system("pause");
//	return 0;
//}

//修正后的

//char* my_strcpy1(char* dst, const char* src)
//{
//	assert((dst != NULL) && (src != NULL));//断言判断，传入的数组地址不是空的
//	char* temp = dst;
//
//	while ((*dst++ = *src++) != '\0')
//	{
//	}
//
//	return temp;
//}

//int main()
//{
//		char arr1[] = { "abcdefgh" };
//		char arr2[] = {0};
//	    char* arr3=my_strcpy1(arr2, arr1);
//
//		printf("%s\n", arr1);
//		printf("%s\n", arr2);//复制完成后，arr2里面的内容
//		printf("%s\n", arr3);//通过函数返回值接受的arr3里面的内容
//
//		system("pause");
//		return 0;
//}

/*
4.模拟实现strcat

函数功能：将源字符串的副本附加到目标字符串。目标中的终止空字符被源的第一个字符覆盖，
并且在由目标中的两个串联形成的新字符串的末尾包括空字符。
为避免溢出，目标指向的数组大小应足够长，以包含与源相同的C字符串（包括终止空字符），并且不应在内存中与源重叠。

问题分析：函数原型 char * strcat ( char * destination, const char * source );

解释一下返回类型为 char* 的原因  使函数支持链式表达式，方便复制，增加函数灵活性。
*/
//
//char* my_strcat(char* dst, const char* src)
//{
//	assert((dst != NULL) && (src != NULL));//断言判断,保证传入的指针不是空指针
//	char* temp = dst;
//
//	while (*dst != '\0')//将指针移到目标字符串的‘\0’的位置上
//	{
//		dst++;
//	}
//
//	while ((*dst=*src++)!= '\0')//把src的内容赋值给在dst的后面
//	{
//	}
//	return temp;
//}

//int main()
//{
//	char str1[10] = "abc";
//	char str2[] = "bcd";
//	
//	printf("str1=%s\n", str1);
//	char* str3 = my_strcat(str1, str2);
//	printf("str2=%s\n", str2);
//	printf("str3=%s\n", str3);
//
//	system("pause");
//	return 0;
//}
