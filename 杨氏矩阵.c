#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#define N 3
/*2.
//���Ͼ���
��һ����ά����.
�����ÿ�д������ǵ����ģ�ÿ�д��ϵ����ǵ�����.
�������������в���һ�������Ƿ���ڡ�
ʱ�临�Ӷ�С��O(N);
���飺
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

//�����Ͻǿ�ʼ

int my_find_1(int arr[][N], int row, int col, int key)
{
	int x = 0;
	int y = col - 1;

	while (x < row && y >= 0)
	{
		if (key>arr[x][y])//�����ƶ�
		{
			++x;
		}
		else if (key < arr[x][y])//�����ƶ�
		{
			--y;
		}
		else
		{
			return 1;//��ȷ���
		}
	}
	return 0;//û���ҵ�����
}

//�����½ǿ�ʼ

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

//�����Ͻǿ�ʼ���ݹ飩

int my_find_3(int arr[][N],int row,int col,int x,int y,int key)
{
	if (x >= row || y < 0)//�Ժ���Խ�����鷶Χ��Ϊ��ֹ����
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

//�����½ǿ����ݹ飩

int my_find_4(int arr[][N], int row, int col, int x, int y, int key)
{
	if(x<0 || y>=col)//�Ժ���Խ�����鷶Χ��Ϊ��ֹ����
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
		printf("���ҵ���%d\n", key);
	}
	else
	{
		printf("�����ڣ�%d\n", key);
	}
	system("pause");
	return 0;
}