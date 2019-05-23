#pragma once
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<string.h>

typedef struct Contact// ��ϵ��
{
	char _Name[24];
	char _Tel[16];
	char _Address[64];
	int age;
}Contact;

typedef struct ContactBook//ͨѶ¼
{
	Contact* _con_arrary;//��ϵ�˽ṹ��ָ��
	size_t _size;//��ϵ�˸���
	size_t _capacity;//ͨѶ¼����
}ContactBook;

void ContactBookInit(ContactBook* pbook); //��ʼ��ͨѶ¼
void ContactBookDestory(ContactBook* pbook);//ͨѶ¼����
void ContactBookAppend(ContactBook* pbook,Contact* con);//�����ϵ��
void ContactBookDelete(ContactBook* pbook);//ɾ��ָ����ϵ��
void ContactBookFind(ContactBook* pbook); //����ָ����ϵ��
void ContactBookUpdate(ContactBook* pbook);//�޸�ָ����ϵ��
void ContactBookSave(ContactBook* pbook,const char* file);//�ļ�����
void ContactBookLoad(ContactBook* pbook,const char* file);//�ļ�����
void ContactPrint(ContactBook* pbook);//�����ϵ��
void ContactName_Sort(ContactBook* pbook);//����������