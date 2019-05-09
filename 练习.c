#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//#define N 3
////左下角起点
//int find(int a[][N], int row, int col, int key)
//{
//	int x = row - 1;
//	int y = 0;
//	//右上角： (0, col - 1)
//	while (x >= 0 && y < col)
//	{
//		if (key == a[x][y])
//			return 1;
//		else if (key > a[x][y])
//			//向右搜索
//			++y;
//		else
//			//向上搜索
//			--x;
//	}
//	return 0;
//}
//
////右上角：起点
//int find2(int a[][N], int row, int col, int key)
//{
//	int x = 0;
//	int y = col - 1;
//
//	while (x < row && y >= 0)
//	{
//		if (key == a[x][y])
//			return 1;
//		else if (key > a[x][y])
//			//向下搜索
//			++x;
//		else
//			//向左搜索
//			--y;
//	}
//	return 0;
//}
////右上角
//int find_r(int a[][N], int row, int col, int x, int y, int key)
//{
//	//终止
//	if (x >= row || y < 0)
//		return 0;
//	if (a[x][y] == key)
//		return 1;
//	else if (key > a[x][y])
//		return find_r(a, row, col, x + 1, y, key);
//	else
//		return find_r(a, row, col, x, y - 1, key);
//	
//}
//
////左下角
//
//int main()
//{
//	int a[N][N] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
//	int key;
//	scanf("%d", &key);
//	if (find_r(a, N, N, 0, N - 1, key))
//		printf("%d find!\n", key);
//	else
//		printf("%d not find!\n", key);
//	return 0;
//}
//左旋一次
void left_move_1(char* str)
{
	char start = *str;
	char* cur = str;
	//字符向前移动一个位置
	while (*(cur + 1))
	{
		*cur = *(cur + 1);
		++cur;
	}
	//第一个字符移动到最后一个位置
	*cur = start;	
}
#include <string.h>
// O(kn)
void left_move(char* str, int k)
{
	k %= strlen(str);
	while (k--)
	{
		left_move_1(str);
	}
}

// n / 2  ~  O(n)
void reverse(char* start, char* end)
{
	while (start < end)
	{
		char tmp = *start;
		*start = *end;
		*end = tmp;
		++start;
		--end;
	}
}
// O(n)
void left_move2(char* str, int k)
{
	int len = strlen(str);
	k %= len;
	//第一次：0 ~ k - 1
	// k / 2
	reverse(str, str + k - 1);
	//第二次： k ~ len - 1
	// (len - k) / 2
	reverse(str + k, str + len - 1);
	//第三次: 0 ~ len - 1
	// len / 2
	reverse(str, str + len - 1);  
}

void right_move(char* str, int k)
{
	int len = strlen(str);
	left_move2(str, len - k);
}

//int main()
//{
//	char str[100];
//	int k;
//	scanf("%s", str);
//	scanf("%d", &k);
//	left_move2(str, k);
//	printf("%s\n", str);
//	right_move(str, k);
//	printf("%s\n", str);
//
//	return 0;
//}

int isRotate(char* dest, char* src)
{
	int len = strlen(src);
	while (len--)
	{
		right_move(src, 1);
		if (!strcmp(dest, src))
			return 1;
	}

	return 0;
}

void sct(char* dest, char* src)
{
	while (*dest)
		++dest;
	while (*dest++ = *src++)
	{
		;
	}
}
void snct(char* dest, char* src, int len)
{
	while (*dest)
		++dest;
	while (len--)
	{
		*dest++ = *src++;
	}
	*dest = '\0';
}

int isRotate2(char* dest, char* src)
{
	snct(dest, dest, strlen(dest));
	if (strstr(dest, src) != NULL)
		return 1;
	return 0;
}

const char* strStr(const char* dest,const char* src)
{
	while (*dest)
	{
		const char* dst = dest;
		const char* sc = src;
		while (*dst && *sc && *dst == *sc)
		{
			++dst;
			++sc;
		}

		if (*sc == '\0')
			return dest;
		++dest;
	}

	return NULL;
}


//int main()
//{
//	char dest[100];
//	char src[100];
//	scanf("%s", dest);
//	scanf("%s", src);
//	if (isRotate2(dest, src))
//	{
//		printf("OK\n");
//	}
//	else
//		printf("ERROR\n");
//	return 0;
//}

//int main()
//{
//	char dest[100];
//	char src[100];
//	scanf("%s", dest);
//	scanf("%s", src);
//	if (strStr(dest, src) != NULL)
//	{
//		printf("OK\n");
//	}
//	else
//		printf("ERROR\n");
//	return 0;
//}

void find(int a[], int sz)
{
	int ret = 0;
	int pos = 0;
	int x = 0;
	int y = 0;
	for (int i = 0; i < sz; i++)
	{
		ret ^= a[i];
	}
	//找到ret中任意一个1的位置
	for (int i = 0; i < 32; i++)
	{
		if (((ret >> i) & 1) == 1)
		{
			pos = i;
			break;
		}		
	}

	//按照ret中第pos位是否为1，分成两组
	for (int i = 0; i < sz; i++)
	{
		if (((a[i] >> pos) & 1) == 1)
			x ^= a[i];
		else
			y ^= a[i];
	}
	printf("%d, %d\n", x, y);
}

int main()
{
	int arr[] = { 1, 2, 3, 4, 1, 4, 3, 9, 8, 2 };
	find(arr, sizeof(arr) / sizeof(arr[0]));
	return 0;
}