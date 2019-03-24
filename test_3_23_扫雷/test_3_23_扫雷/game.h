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

void init(char mine[ROWS][COLS], int rows, int cols, int set);//初始化

void display(char mine[ROWS][COLS], int row, int col);//打印数组

void setmine(char mine[ROWS][COLS], int row, int col);//布雷

void findmine(char mine[ROWS][COLS], char show[ROWS][COLS] ,int row, int col);//排雷且判输赢

void OpenMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int coly);//展开坐标周围

void OpenMine(char mine[ROWS][COLS], char show[ROWS][COLS], int x, int y);
#endif