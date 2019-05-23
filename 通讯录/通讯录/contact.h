#pragma once
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<string.h>

typedef struct Contact// 联系人
{
	char _Name[24];
	char _Tel[16];
	char _Address[64];
	int age;
}Contact;

typedef struct ContactBook//通讯录
{
	Contact* _con_arrary;//联系人结构体指针
	size_t _size;//联系人个数
	size_t _capacity;//通讯录容量
}ContactBook;

void ContactBookInit(ContactBook* pbook); //初始化通讯录
void ContactBookDestory(ContactBook* pbook);//通讯录销毁
void ContactBookAppend(ContactBook* pbook,Contact* con);//添加联系人
void ContactBookDelete(ContactBook* pbook);//删除指定联系人
void ContactBookFind(ContactBook* pbook); //查找指定联系人
void ContactBookUpdate(ContactBook* pbook);//修改指定联系人
void ContactBookSave(ContactBook* pbook,const char* file);//文件读入
void ContactBookLoad(ContactBook* pbook,const char* file);//文件读出
void ContactPrint(ContactBook* pbook);//输出联系人
void ContactName_Sort(ContactBook* pbook);//按姓名排名