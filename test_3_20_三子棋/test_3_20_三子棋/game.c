#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"

void init_chess(char arr[ROW][COL], int row, int col)//初始化数组
{
	int i = 0;
	for (i = 0; i < row; i++)
	{
		int j = 0;
		for (j = 0; j < col; j++)
		{
			arr[i][j] = ' ';
		}
	}
}

void display_chess(char arr[ROW][COL], int row, int col)//打印棋盘
{
	int i = 0;
	int j = 0;

	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			printf(" %c ", arr[i][j]);
			if (j < col - 1)
				printf("|");

		}
		printf("\n");
		if (i < row - 1)
		{
			for (j = 0; j < col; j++)
			{
				printf("---");
				if (j<col - 1)
					printf("|");
			}
		}
		printf("\n");
	}

}

void ComeputerMove(char arr[ROW][COL], int row, int col)//电脑下棋
{
	int x = 0;
	int y = 0;

	printf("电脑走:>\n");
	while (1)
	{
		x = rand() % row;
		y = rand() % col;

		if (arr[x][y] == ' ')
		{
			arr[x][y] = '0';
			break;
		}
	}
}

void PlayerMove(char arr[ROW][COL], int row, int col)////玩家下棋
{
	int x = 0;
	int y = 0;
	printf("玩家走:>\n");
	while (1)
	{
	   printf("请输入坐标:>\n");
       scanf("%d%d", &x, &y);
	   if (x > 0 && x <= row&&y > 0 && y <= col)
	  {
		if (arr[x - 1][y - 1] == ' ')
		{
			arr[x - 1][y - 1] = 'X';
			break;
		}
		else
		{
			printf("该位置已经有棋子了！\n");
		}
	  }
	   else
	   {
		   printf("位置不合理！\n");
	   }
	}
}

int IsFull(char arr[ROW][COL], int row, int col)//判断棋盘是否下满
{
	int i = 0;
	int j = 0;

	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (arr[i][j] == ' ')
			{
				return 0;
			}
		}
	}
	return -1;
}

char IsWin(char arr[ROW][COL], int row, int col)//判断输赢
{
	int i = 0;
	int j = 0;
	int tmp = 0;
	//判断输赢
	for (i = 0; i < row; i++)
	{
		tmp = 0;
		for (j = 0; j < col - 1; j++)
		{
			if ((arr[i][j] == arr[i][j + 1]) && arr[i][j] != ' ')
			{
				;
			}
			else
			{
				tmp = 1;
				break;
			}
		}
		if (tmp == 0)
		{
			return arr[i][j];
		}
	}
	for (j = 0; j < col; j++)

	{
		tmp = 0;
		for (i = 0; i < row - 1; i++)
		{
			if ((arr[i][j] == arr[i + 1][j]) && arr[i][j] != ' ')
			{
				;
			}
			else
			{
				tmp = 1;
				break;
			}
		}
		if (tmp == 0)
		{
			return arr[i][j];
		}
	}


	for (i = 0, j = 0; i < row - 1, j < col - 1; i++, j++)
	{
		tmp = 0;
		if ((tmp == 0) && (arr[i][j] == arr[i + 1][j + 1]) && arr[i][j] != ' ')
		{
			;
		}
		else
		{
			tmp = 1;
			break;
		}
	}
	if (tmp == 0)
	{
		return arr[i][j];
	}



	for (i = row, j = 0; i > 0, j < col - 1; i--, j++)
	{
		tmp = 0;
		if ((tmp == 0) && (arr[i][j] == arr[i - 1][j + 1]) && arr[i][j] != ' ')
		{
			;
		}
		else
		{
			tmp = 1;
			break;
		}
	}
	if (tmp == 0)
	{
		return arr[i][j];
	}//判断平局
	if (IsFull(arr, row, col))
	{
		return 'p';
	}
	//游戏继续
	return ' ';
}
