#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<Windows.h>
#include<stdbool.h>

/*
��Ŀ����һ����ά�����У�ÿһ�д��������ε�����ÿһ�д��ϵ������ε�����
���һ����������һ����ά�����һ���������ж��������Ƿ����������
˼·1�������Ͻǿ�ʼ�����õݼ�����
˼·2����������
*/

#define row 4
#define col 4

//˼·1��
//int Rserchnum(int arr[row][col], int val)//arr[4][4],arr[][4],ǰ��һ������ʡ��
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

//˼·2:
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