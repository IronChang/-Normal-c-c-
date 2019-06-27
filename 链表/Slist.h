#include<stdio.h>
#include<malloc.h>
#include<assert.h>

typedef int SlistNodeDate;

//�ڵ�ṹ��
typedef struct SlistNode
{
	SlistNodeDate _date;
	struct SlistNode* _next;
}SlistNode;

//��д���� ��ֱֹ�Ӵ��ṹ����ֶ���ָ��
typedef struct Slist
{
	SlistNode* _head;
}Slist;


void SlistInit(Slist *plt);//�����ʼ��
void SlistPushBack(Slist *plt, SlistNodeDate x);//β������
void SlistPushFront(Slist *plt, SlistNodeDate x);//ͷ������
void SlistPopBack(Slist *plt);//β��ɾ��
void SlistPopFront(Slist *plt);//ͷ��ɾ��
void SlistDestory(Slist *plt);//ɾ������
void SlistPrint(Slist *plt);//�������

void Test_Slist_1();//���Ժ���
void Test_Slist_2();