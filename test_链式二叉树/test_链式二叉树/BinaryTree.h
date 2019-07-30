#pragma once
#include<stdio.h>
#include<windows.h>
#include<malloc.h>
#include<assert.h>
#include<stdbool.h>

typedef char BTDataType;

typedef struct BinaryTreeNode//�������ڵ����ݽṹ
{
	BTDataType _data;
	struct BinaryTreeNode* _left;
	struct BinaryTreeNode* _right;
}BTNode;

// ͨ��ǰ�����������"ABD##E#H##CF##G##"����������
BTNode* BinaryTreeCreate(BTDataType* a,int* pi);//������
void BinaryTreeDestory(BTNode* root);//������
int BinaryTreeSize(BTNode* root);//�������ڵ����
int BinaryTreeLeafSize(BTNode* root);//������Ҷ�ӽ�����
int BinaryTreeLevelKSize(BTNode* root, int k);//��������k��Ľڵ����
BTNode* BinaryTreeFind(BTNode* root, BTDataType x);//�������в��ҽڵ�
void BinaryTreePrevOrder(BTNode* root);//ǰ�����
void BinaryTreeInOrder(BTNode* root);//�������
void BinaryTreePostOrder(BTNode* root);//�������void BinaryTreeLevelOrder(BTNode* root);//�������



typedef BTNode* QUDataType;

typedef struct QueueNode
{
	struct QueueNode* _next;
	QUDataType _data;
}QueueNode;

typedef struct Queue
{
	QueueNode* _front;
	QueueNode* _tail;
}Queue;


void QueueInit(Queue* pq);//��ʼ��
void QueueDestory(Queue* pq);//����
QueueNode* BuyQueueNode(QUDataType x);//����һ���ڵ�
void QueuePush(Queue* pq, QUDataType x);//β��
void QueuePop(Queue* pq);//ͷɾ
QUDataType QueueFront(Queue* pq);//ȡ����ǰͷ��Ԫ��
QUDataType QueueBack(Queue* pq);//ȡ����ǰβ��Ԫ��
bool QueueEmpty(Queue* pq);//�ж϶����Ƿ�Ϊ��
int QueueSize(Queue* pq);//���㵱ǰ����Ԫ��
void QueuePirnt(Queue* pq);//����ȡ������Ԫ��


void Test();