#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include"game.h"

void menu()//游戏菜单
{
	printf("*******************************\n");
	printf("****         1.play        ****\n");
	printf("****         0.exit        ****\n");
	printf("****    1=有雷    0=无雷   ****\n");
	printf("*******************************\n");
}

void test()
{
	char mine[ROWS][COLS] = { 0 };//存放雷的信息
	char show[ROWS][COLS] = { 0 };//存放排查出雷的信息
	int input = 0;
	srand((unsigned int)time(NULL));

	do
	{
		printf("请选择：>");
        scanf("%d", &input);
		switch (input)
		{
		case 1:
			init(mine, ROWS, COLS, '0');
			init(show, ROWS, COLS, '*');
			setmine(mine, ROW, COL);
			display(show, ROW, COL);
			findmine(mine, show,ROW, COL);
			break;
		case 0:
			printf("推出游戏！\n");
			break;
		default:
			printf("输入错误，请从新选择:>\n");
			break;
		}
	} while (input);
}
int main()
{
	menu();
	test();
	system("pause");
	return 0;
}