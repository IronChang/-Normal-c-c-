#ifndef _GAME_H_
#define _GAME_H_
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define ROW 3
#define COL 3

void init_chess(char arr[ROW][COL], int row, int col);//��ʼ������

void display_chess(char arr[ROW][COL], int row, int col);//��ӡ����

void ComeputerMove(char board[ROW][COL], int row, int col);//��������

void PlayerMove(char arr[ROW][COL], int row, int col);//�������

int IsFull(char arr[ROW][COL], int row, int col);//�ж������Ƿ�����

char IsWin(char arr[ROW][COL], int row, int col);//�ж���Ӯ

#endif