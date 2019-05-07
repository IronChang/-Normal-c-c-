#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#define N 3
/*2.
//杨氏矩阵
有一个二维数组.
数组的每行从左到右是递增的，每列从上到下是递增的.
在这样的数组中查找一个数字是否存在。
时间复杂度小于O(N);
数组：
1 2 3
2 3 4
3 4 5

1 3 4
2 4 5
4 5 6

1 2 3
4 5 6
7 8 9
*/

//从右上角开始

int my_find_1(int arr[][N], int row, int col, int key)
{
	int x = 0;
	int y = col - 1;

	while (x < row && y >= 0)
	{
		if (key>arr[x][y])//向下移动
		{
			++x;
		}
		else if (key < arr[x][y])//向左移动
		{
			--y;
		}
		else
		{
			return 1;//相等返回
		}
	}
	return 0;//没有找到返回
}

//从左下角开始

int my_find_2(int arr[][N], int row, int col, int key)
{
	int x = row - 1;
	int y = 0;

	while (x >= 0 && y < col)
	{
		if (key > arr[x][y])
		{
			++y;
		}
		else if (key < arr[x][y])
		{
			--x;
		}
		else
		{
			return 1;
		}
	}
	return 0;
}

//从右上角开始（递归）

int my_find_3(int arr[][N],int row,int col,int x,int y,int key)
{
	if (x >= row || y < 0)//以函数越出数组范围作为终止条件
	{
		return 0;
	}
	if (arr[x][y] == key)
	{
		return 1;
	}
	else if (key>arr[x][y])
	{
		return my_find_3(arr, row, col, x + 1, y, key);
	}
	else
	{
		return my_find_3(arr, row, col, x, y-1, key);
	}
}

//从左下角开（递归）

int my_find_4(int arr[][N], int row, int col, int x, int y, int key)
{
	if(x<0 || y>=col)//以函数越出数组范围作为终止条件
	{
		return 0;
	}
	if (key=arr[x][y])
	{
		return 1;
	}
	else if (key>arr[x][y])
	{
		return my_find_4(arr, row, col, x, y + 1, key);
	}
	else
	{
		return my_find_4(arr, row, col, x-1, y, key);
	}
}

int main()
{
	int a[N][N] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int key = 0;
	scanf("%d", &key);

	if (my_find_4(a, N, N,0,2, key))
	{
		printf("已找到：%d\n", key);
	}
	else
	{
		printf("不存在：%d\n", key);
	}
	system("pause");
	return 0;
}