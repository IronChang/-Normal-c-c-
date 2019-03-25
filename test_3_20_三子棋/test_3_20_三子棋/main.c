#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include"game.h"

void menu()
{
    printf("****************************************\n");
	printf("*********     1.��ʼ��Ϸ       *********\n");
	printf("*********     0.�˳���Ϸ       *********\n");
	printf("****************************************\n");
}

void game()
{
	char arr[ROW][COL] = { 0 };
	char ret = '0';
	int input = 0;
	printf("1.�������� 2.�������\n");
	printf("��ѡ��˭����:>");
	scanf("%d", &input);
	init_chess(arr, ROW, COL);
	display_chess(arr, ROW, COL);
	switch (input)
	{
	case 1:
		while (1)
		{
			ComeputerMove(arr, ROW, COL);
			ret = IsWin(arr, ROW, COL);
			if (ret != ' ')
			{
				break;
			}
			display_chess(arr, ROW, COL);
			PlayerMove(arr, ROW, COL);
			if (ret != ' ')
			{
				break;
			}
			display_chess(arr, ROW, COL);
		}
		break;

	case 2:
		while (1)
		{
			
			PlayerMove(arr, ROW, COL);
			ret = IsWin(arr, ROW, COL);
			if (ret != ' ')
			{
				break;
			}
			display_chess(arr, ROW, COL);
			ComeputerMove(arr, ROW, COL);
			ret = IsWin(arr, ROW, COL);
			if (ret != ' ')
			{
				break;
			}
			display_chess(arr, ROW, COL);
		}
		break;

	default:
		break;
	}
	if (ret == ' ')
	{
		printf("ƽ��\n");
		display_chess(arr, ROW, COL);
	}
	else if (ret == 'x')
	{
		printf("���Ӯ!!!\n");
		display_chess(arr, ROW, COL);
	}
	else if (ret == '0')
	{
		printf("����Ӯ!!!\n");
		display_chess(arr, ROW, COL);
	}
}

int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("��ѡ��:>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("�������\n");
			break;
		}
	} while (input);
	system("pause");
	return 0;
}