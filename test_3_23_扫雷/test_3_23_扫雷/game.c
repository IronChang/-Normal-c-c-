#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"

void init(char mine[ROWS][COLS], int rows, int cols, char set)//初始化
{
	int i = 0;
	int j = 0;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			mine[i][j] = set;
		}
	}
}

void display(char mine[ROWS][COLS], int row, int col)//打印数组
{
	int i = 0;
	int j = 0;
	printf("------------------------------\n");
	for (i = 0; i <= col; i++)
	{
		printf("%d  ", i);
	}
	printf("\n");
	for (i = 1; i <=row; i++)
	{
		printf("%d  ", i);
		for (j = 1; j <=col; j++)
		{
			printf("%c  ", mine[i][j]);
		}
		printf("\n");
	}
	printf("------------------------------\n");
}

void setmine(char mine[ROWS][COLS], int row, int col) //布雷
{
	int x = 0;
	int y = 0;
	int count = EASY_COUNT;
	
	while (count)
	{
		x = rand() % row+1 ;
		y = rand() % col+1 ;
		 
		if (mine[x][y] == '0')
		{
               mine[x][y] = '1';
			   count--;
		}
	}	
}

//static int GetMineCount(char mine[ROWS][COLS], int x, int y)//计算x，y周围的雷数量
//{
//	return
//		mine[x - 1][y] + mine[x - 1][y - 1] +
//		mine[x][y - 1] + mine[x + 1][y - 1] +
//		mine[x + 1][y] + mine[x + 1][y + 1] +
//		mine[x][y + 1] + mine[x -1][y - 1] - 8 * '0';
//}

int CountMine(char mine[ROWS][COLS], int x, int y)//计算x，y周围的雷数量
{
	int count = 0;
	if (mine[x - 1][y - 1] == '1')  //1表示该位置有雷
	{
		count++;
	}
	if (mine[x - 1][y] == '1')
	{
		count++;
	}
	if (mine[x - 1][y + 1] == '1')
	{
		count++;
	}
	if (mine[x][y - 1] == '1')
	{
		count++;
	}
	if (mine[x][y + 1] == '1')
	{
		count++;
	}
	if (mine[x + 1][y - 1] == '1')
	{
		count++;
	}
	if (mine[x + 1][y] == '1')
	{
		count++;
	}
	if (mine[x + 1][y + 1] == '1')
	{
		count++;
	}
	return count;
}

void OpenMine(char mine[ROWS][COLS], char show[ROWS][COLS], int x, int y)
{
	if (mine[x - 1][y - 1] == '0')  //如果该位置没有雷，则计算出其周围8个区域雷的个数并标记在玩家棋盘对应位置
	{
		show[x - 1][y - 1] = CountMine(mine, x - 1, y - 1) + '0';
	}
	if (mine[x - 1][y] == '0')
	{
		show[x - 1][y] = CountMine(mine, x - 1, y) + '0';
	}
	if (mine[x - 1][y + 1] == '0')
	{
		show[x - 1][y + 1] = CountMine(mine, x - 1, y + 1) + '0';  //CountMine()函数返回的是数字，而PlayerMine数组存的是字符，所以将数字加上字符零可得数字字符
	}
	if (mine[x][y - 1] == '0')
	{
		show[x][y - 1] = CountMine(mine, x, y - 1) + '0';  //CountMine()函数返回的是数字，而PlayerMine数组存的是字符，所以将数字加上字符零可得数字字符
	}
	if (mine[x][y + 1] == '0')
	{
		show[x][y + 1] = CountMine(mine, x, y + 1) + '0';  //CountMine()函数返回的是数字，而PlayerMine数组存的是字符，所以将数字加上字符零可得数字字符
	}
	if (mine[x + 1][y - 1] == '0')
	{
		show[x + 1][y - 1] = CountMine(mine, x + 1, y - 1) + '0';  //CountMine()函数返回的是数字，而PlayerMine数组存的是字符，所以将数字加上字符零可得数字字符
	}
	if (mine[x + 1][y] == '0')
	{
		show[x + 1][y] = CountMine(mine, x + 1, y) + '0';  //CountMine()函数返回的是数字，而PlayerMine数组存的是字符，所以将数字加上字符零可得数字字符
	}
	if (mine[x + 1][y + 1] == '0')
	{
		show[x + 1][y + 1] = CountMine(mine, x + 1, y + 1) + '0';  //CountMine()函数返回的是数字，而PlayerMine数组存的是字符，所以将数字加上字符零可得数字字符
	}
}

void findmine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)//扫雷且判输赢
{   
	int x = 0;
	int y = 0;
	int count = 0;
	while (1)
	{
		printf("请输入排查坐标：>");
		scanf("%d %d", &x, &y);
		if (x >= 1 && x <= row&&y >= 1 && y <= col)
		{
			if (mine[x][y] == '1')
			{
				printf("抱歉！你踩雷了\n");
				display(mine, row, col);
				break;
			}
			else
			{
				int ret = CountMine(mine, x, y);//计算x，y周围雷数
				show[x][y] = ret+'0';
				OpenMine(mine,show,x,y);
				display(show, row, col);
				count++;
				if ((ROW*COL) - EASY_COUNT == count)
				{
					printf("你赢了！\n");
					display(mine, row, col);
				}

			}
		}
		else
		{
			printf("输入错误，坐标非法！");
		}
	}
}

