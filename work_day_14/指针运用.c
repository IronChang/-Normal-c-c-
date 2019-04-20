#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>

//1.实现一个函数，可以左旋字符串中的k个字符。
//ABCD左旋一个字符得到BCDA
//ABCD左旋两个字符得到CDAB

/*第一想法，反转字符串（审题不仔细），
再次审题想到三次翻转，先进行整体翻转，
在进行翻转部分翻转，在翻转剩下部分
*/

//原因：审题不认真，基础太差。对翻转字符串算法还是不熟悉

//自己写的垃圾代码
//连续进行三次翻转

/*
void adjustALL(char* left ,char* right,int n)//大调整
{
for (int i = 0; i < n; i++)//将前n给字符反转到最后
{
while (left < right)
{
char tmp = *left;
*left = *right;
*right = tmp;
left++;
right--;
}
}
}

void adjustleft(int n,char a[F])//调整前n个字符串
{
int len = n+1;

for (int i = 0; i < len/2; i++)
{
char tmp = a[i];
a[i] = a[len-i-1];
a[len - i - 1] = tmp;
}
}

void adjustright(int n,char a[F],int len)//调整后n个字串
{

for (int i = 0; i < n/2; i++)
{
char tmp = a[i+ (n + 1)];
a[i+n+1] = a[len - i - 1];
a[len - i - 1] = tmp;
}
}

int main()
{
char a[F] = { "abcdefg" };
int n = 0;
int len = strlen(a);

printf("请输入要左旋的字符个数:>\n");
scanf("%d", &n);
adjustALL(a,a+F-1,n);//进行全部调整
adjustleft(n, a);//调整前F-n个
adjustright(n, a, F);//调整后n个

for (int i = 0; i < F; i++)
{
printf("%c", a[i]);
}
printf("\n");

system("pause");
return 0;
}
*/


//暴力移位法

//void left_move(char* str, int n)
//{
//	assert(str != NULL);
//	while (n--)
//	{
//		char* cur = str;
//		char tmp = *cur;//将第一个元素存在tmp中
//
//		while (*(cur + 1) != '\0')
//		{
//			*cur = *(cur + 1);
//				cur++;
//		}
//
//		*cur = tmp;
//	}
//}

//int main()
//{
//	char arr[] = "ABCDE";
//	int n = 0;
//
//	printf("请输入要左旋的个数:>");
//	scanf("%d", &n);
//	left_move(arr, n);
//	printf("%s", arr);
//
//	system("pause");
//	return 0;
//}

//重写三步翻转法

//void reverse(char* left, char* right)//翻转函数
//{
//	while (left < right)
//	{
//		char tmp = *left;
//		*left = *right;
//		*right = tmp;
//		left++;
//		right--;
//	}
//}

//void left_move(char* str, int n)
//{
//	int len = strlen(str);
//	reverse(str, str + len - 1);
//	reverse(str + n, str + len - 1);
//	reverse(str, str + n - 1);
//}

//int main()
//{
//	char arr[] = "ABCDE";
//	int n = 0;
//	printf("请输入要左旋的个数:>");
//	scanf("%d", &n);
//	left_move(arr, n);
//
//	system("pause");
//	return 0;
//}


/*
2.判断一个字符串是否为另外一个字符串旋转之后的字符串。 
例如：给定s1 =AABCD和s2 = BCDAA，返回1 
给定s1=abcd和s2=ACBD，返回0. 

AABCD左旋一个字符得到ABCDA 
AABCD左旋两个字符得到BCDAA 

AABCD右旋一个字符得到DAABC
*/

//暴力移位法，每次移动一位就进行一次比较，通过左旋来判断
//int judge_left(char* str1, char* str2)
//{
//	int i = 0;
//	int j = 0;
//	int len = strlen(str1);//通过函数求字符串长度
//
//	for (i = 0; i < len - 1; i++)
//	{
//
//		int tmp = str1[0];
//		for (j = 0; j < len - 1; j++)
//		{
//			str1[j] = str1[j + 1];
//		}
//		str1[len - 1] = tmp;
//		if (0 == strcmp(str1, str2))
//		{
//			return 1;
//		}
//	}
//	return 0;
//}

//int main()
//{
//	char s1[] = "0";
//	char s2[] = "0";
//
//	gets(s1);
//	gets(s2);
//	int ret = 0;
//	ret = judge_left(s1, s2);
//	printf("%d\n",ret);
//
//	system("pause");
//	return 0;
//}

//暴力移位法，每次移动一位就进行一次比较，通过右旋来判断

//int judge_right(char* str1, char* str2)
//{
//	int i = 0;
//	int j = 0;
//	int len = strlen(str2);//通过函数求字符串长度
//
//	for (i = len - 1; i >= 0;i--)
//	{
//		char tmp = str2[len-1];
//		for (j = len - 1; j >= 0; j--)
//		{
//			str2[j] = str2[j - 1];
//		}
//		str2[0] = tmp;
//		if (0 == strcmp(str1, str2))
//		{
//			return 1;
//		}
//	}
//	return 0;
//}

//int main()
//{
//	char s1[] = "0";
//	char s2[] = "0";
//
//	gets(s1);
//	gets(s2);
//	int ret = 0;
//	ret = judge_right(s1, s2);
//	printf("%d\n", ret);
//
//	system("pause");
//	return 0;
//}