#pragma once
#include<stdio.h>
#include<windows.h>
#include<malloc.h>
#include<assert.h>
#include<stdbool.h>

typedef char BTDataType;

typedef struct BinaryTreeNode//二叉树节点数据结构
{
	BTDataType _data;
	struct BinaryTreeNode* _left;
	struct BinaryTreeNode* _right;
}BTNode;

// 通过前序遍历的数组"ABD##E#H##CF##G##"构建二叉树
BTNode* BinaryTreeCreate(BTDataType* a,int* pi);//创建树
void BinaryTreeDestory(BTNode* root);//销毁树
int BinaryTreeSize(BTNode* root);//二叉树节点个数
int BinaryTreeLeafSize(BTNode* root);//二叉树叶子结点个数
int BinaryTreeLevelKSize(BTNode* root, int k);//二叉树第k层的节点个数
BTNode* BinaryTreeFind(BTNode* root, BTDataType x);//二叉树中查找节点
void BinaryTreePrevOrder(BTNode* root);//前序遍历
void BinaryTreeInOrder(BTNode* root);//中序遍历
void BinaryTreePostOrder(BTNode* root);//后序遍历void BinaryTreeLevelOrder(BTNode* root);//层序遍历



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


void QueueInit(Queue* pq);//初始化
void QueueDestory(Queue* pq);//销毁
QueueNode* BuyQueueNode(QUDataType x);//创建一个节点
void QueuePush(Queue* pq, QUDataType x);//尾插
void QueuePop(Queue* pq);//头删
QUDataType QueueFront(Queue* pq);//取出当前头部元素
QUDataType QueueBack(Queue* pq);//取出当前尾部元素
bool QueueEmpty(Queue* pq);//判断队列是否为空
int QueueSize(Queue* pq);//计算当前队列元素
void QueuePirnt(Queue* pq);//依次取出队列元素


void Test();