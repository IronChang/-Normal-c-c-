#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"

void init_chess(char arr[ROW][COL], int row, int col)//��ʼ������
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

void display_chess(char arr[ROW][COL], int row, int col)//��ӡ����
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

void ComeputerMove(char arr[ROW][COL], int row, int col)//��������
{
	int x = 0;
	int y = 0;

	printf("������:>\n");
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

void PlayerMove(char arr[ROW][COL], int row, int col)////�������
{
	int x = 0;
	int y = 0;
	printf("�����:>\n");
	while (1)
	{
	   printf("����������:>\n");
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
			printf("��λ���Ѿ��������ˣ�\n");
		}
	  }
	   else
	   {
		   printf("λ�ò�����\n");
	   }
	}
}

int IsFull(char arr[ROW][COL], int row, int col)//�ж������Ƿ�����
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

char IsWin(char arr[ROW][COL], int row, int col)//�ж���Ӯ
{
	int i = 0;
	int j = 0;
	int tmp = 0;
	//�ж���Ӯ
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
	}//�ж�ƽ��
	if (IsFull(arr, row, col))
	{
		return 'p';
	}
	//��Ϸ����
	return ' ';
}
