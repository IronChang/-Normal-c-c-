#ifndef _GAME_H_
#define _GAME_H_
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define EASY_COUNT 10
#define ROWS 11
#define COLS 11
#define ROW 9
#define COL 9

void init(char mine[ROWS][COLS], int rows, int cols, int set);//��ʼ��

void display(char mine[ROWS][COLS], int row, int col);//��ӡ����

void setmine(char mine[ROWS][COLS], int row, int col);//����

void findmine(char mine[ROWS][COLS], char show[ROWS][COLS] ,int row, int col);//����������Ӯ

void OpenMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int coly);//չ��������Χ

void OpenMine(char mine[ROWS][COLS], char show[ROWS][COLS], int x, int y);
#endif