#ifndef _GAME_H_
#define _GAME_H_
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define ROW 3
#define COL 3

void init_chess(char arr[ROW][COL], int row, int col);//初始化数组

void display_chess(char arr[ROW][COL], int row, int col);//打印棋盘

void ComeputerMove(char board[ROW][COL], int row, int col);//电脑下棋

void PlayerMove(char arr[ROW][COL], int row, int col);//玩家下棋

int IsFull(char arr[ROW][COL], int row, int col);//判断棋盘是否下满

char IsWin(char arr[ROW][COL], int row, int col);//判断输赢

#endif