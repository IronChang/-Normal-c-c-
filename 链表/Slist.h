#include<stdio.h>
#include<malloc.h>
#include<assert.h>

typedef int SlistNodeDate;

//节点结构体
typedef struct SlistNode
{
	SlistNodeDate _date;
	struct SlistNode* _next;
}SlistNode;

//编写操作 防止直接传结构体出现二级指针
typedef struct Slist
{
	SlistNode* _head;
}Slist;


void SlistInit(Slist *plt);//链表初始化
void SlistPushBack(Slist *plt, SlistNodeDate x);//尾部插入
void SlistPushFront(Slist *plt, SlistNodeDate x);//头部插入
void SlistPopBack(Slist *plt);//尾部删除
void SlistPopFront(Slist *plt);//头部删除
void SlistDestory(Slist *plt);//删除链表
void SlistPrint(Slist *plt);//输出链表

void Test_Slist_1();//测试函数
void Test_Slist_2();