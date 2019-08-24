#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<Windows.h>
#include<stdbool.h>

/*
题目：在一个二维数组中，每一行从左到右依次递增，每一列从上到下依次递增。
完成一个函数输入一个二维数组和一个整数，判断数组中是否含有这个整数
思路1：从右上角开始，利用递减规则
思路2：遍历数组
*/

#define row 4
#define col 4

//思路1：
//int Rserchnum(int arr[row][col], int val)//arr[4][4],arr[][4],前面一个可以省略
//{
//	int i = 0, j = col-1;
//	while (j >= 0 && i < row)
//	{
//		if (arr[i][j] > val)
//			j--;
//		else if (arr[i][j] < val)
//			i++;
//		else
//			return 1;
//	}
//	return -1;
//}

//思路2:
int  Rserchnum(int arr[row][col], int val)
{
	int i = 0;
	int j = 0;

	for (i; i < row; i++)
	{
		for (j; j < col; j++)
		{
			if (arr[i][j] == val)
			{
				return 1;
			}
		}
	}
	return -1;
}

int main()
{
	int arr[row][col] = {
		{ 1, 2, 8, 9 },
		{ 2, 4, 9, 12 },
		{ 4, 7, 10, 13 },
		{ 6, 8, 11, 15 } };
	int ret = Rserchnum(arr, 7);
	if (ret == 1) {
		printf("find successfully!\n");
	}
	else {
		printf("find unsuccessfully\n");
	}
	system("pause");
	return 0;
}