#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include"game.h"

void menu()//��Ϸ�˵�
{
	printf("*******************************\n");
	printf("****         1.play        ****\n");
	printf("****         0.exit        ****\n");
	printf("****    1=����    0=����   ****\n");
	printf("*******************************\n");
}

void test()
{
	char mine[ROWS][COLS] = { 0 };//����׵���Ϣ
	char show[ROWS][COLS] = { 0 };//����Ų���׵���Ϣ
	int input = 0;
	srand((unsigned int)time(NULL));

	do
	{
		printf("��ѡ��>");
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
			printf("�Ƴ���Ϸ��\n");
			break;
		default:
			printf("������������ѡ��:>\n");
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