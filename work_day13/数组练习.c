#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>

#define N 3

//1.调整数组使奇数全部都位于偶数前面。
//题目：
//输入一个整数数组，实现一个函数，
//来调整该数组中数字的顺序使得数组中所有的奇数位于数组的前半部分，
//所有偶数位于数组的后半部分。

void adjust(int a[], int sz)
{
	int start = 0;
	int end = sz - 1;

	while (start < end)
	{
		//从右向左找第一个偶数
		while (a[start] % 2 != 0)
		{
			++start;
		}
		//从右向左找第一个奇数
		while (a[end] % 2 != 1)
		{
			--end;
		}
		if (start < end)
		{
			a[start] = a[start] ^ a[end];
			a[end] = a[start] ^ a[end];
			a[start] = a[start] ^ a[end];
		}

	}
}

int main()
{
	int a[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	adjust(a, 10);
	for (int i = 0; i < 10; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");

	system("pause");
	return 0;
}


//2.
////杨氏矩阵 
//有一个二维数组.
//数组的每行从左到右是递增的，每列从上到下是递增的.
//在这样的数组中查找一个数字是否存在。
//时间复杂度小于O(N);
//数组：
//1 2 3
//2 3 4
//3 4 5
//
//1 3 4
//2 4 5
//4 5 6
//
//1 2 3
//4 5 6
//7 8 9


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
void left_move(char* str, int n)
{
	assert(str != NULL);
	while (n--)
	{
		char* cur = str;
		char tmp = *cur;//将第一个元素存在tmp中

		while (*(cur + 1) != '\0')
		{
			*cur = *(cur + 1);
				cur++;
		}

		*cur = tmp;
	}
}

int main()
{
	char arr[] = "ABCDE";
	int n = 0;

	printf("请输入要左旋的个数:>");
	scanf("%d", &n);
	left_move(arr, n);
	printf("%s", arr);

	system("pause");
	return 0;
}

//重写三步翻转法

void reverse(char* left, char* right)//翻转函数
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

void left_move(char* str, int n)
{
	int len = strlen(str);
	reverse(str, str + len - 1);
	reverse(str + n, str + len - 1);
	reverse(str, str + n - 1);
}

int main()
{
	char arr[] = "ABCDE";
	int n = 0;
	printf("请输入要左旋的个数:>");
	scanf("%d", &n);
	left_move(arr, n);

	system("pause");
	return 0;
}