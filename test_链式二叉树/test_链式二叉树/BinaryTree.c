#include"BinaryTree.h"



/************************队列**********************/

void QueueInit(Queue* pq)//初始化
{
	assert(pq);

	pq->_front = pq->_tail = (QueueNode*)malloc(sizeof(QueueNode));
	assert(pq->_front);
	pq->_front->_next = NULL;
	pq->_front->_data = 0;
}

void QueueDestory(Queue* pq)//销毁
{
	assert(pq);
	QueueNode *cur = pq->_front;
	while (cur)
	{
		QueueNode *next = cur->_next;
		free(cur);
		cur = next;
	}
	pq->_front = pq->_tail = NULL;
}

QueueNode* BuyQueueNode(QUDataType x)//创建一个节点
{
	QueueNode* newnode = (QueueNode*)malloc(sizeof(QueueNode));
	assert(newnode);
	newnode->_data = x;
	newnode->_next = NULL;
	return newnode;
}

void QueuePush(Queue* pq, QUDataType x)//尾插
{
	assert(pq);
	QueueNode* newnode = BuyQueueNode(x);
	assert(newnode);//判断申请空间是否成功
	pq->_tail->_next = newnode;
	pq->_tail = newnode;
}

void QueuePop(Queue* pq)//头删
{
	assert(pq && pq->_front->_next != NULL);
	QueueNode* next = pq->_front->_next;//保存对头第一个元素
	if (pq->_tail == next)
	{
		pq->_tail = pq->_front;
	}
	pq->_front->_next = next->_next;
	free(next);
	next = NULL;

}

QUDataType QueueFront(Queue* pq)//取出当前头部元素
{
	assert(pq);

	return pq->_front->_next->_data;;
}

QUDataType QueueBack(Queue* pq)//取出当前尾部元素
{
	assert(pq);

	return pq->_tail->_data;
}

bool QueueEmpty(Queue* pq)//判断队列是否为空
{
	assert(pq);

	return pq->_front == pq->_tail ? false : true;
}

int QueueSize(Queue* pq)//计算当前队列元素
{
	assert(pq);

	QueueNode* cur = pq->_front->_next;
	int count = 0;

	if (QueueEmpty == 0)
	{
		return 0;
	}
	else
	{
		while (cur)
		{
			++count;
			cur = cur->_next;
		}
	}
	return count;
}

void QueuePirnt(Queue* pq)//依次取出队列元素
{
	assert(pq);

	QueueNode* cur = pq->_front->_next;

	while (cur)
	{
		printf("%d->", cur->_data);
		cur = cur->_next;
	}
	printf("NULL\n");
}

/*********************二叉树********************/

BTNode* BuyNode(BTDataType x)//创建一个节点
{
	BTNode* newnode = (BTNode*)malloc(sizeof(BTNode));
	assert(newnode);
	newnode->_data = x;
	newnode->_left = newnode->_right = NULL;
	return newnode;
}
// 通过前序遍历的数组"ABD##E#H##C"构建二叉树
BTNode* BinaryTreeCreate(BTDataType* a,int* pi)
{
	//利用前序遍历 递归进行创建
	if (a[*pi] == '#')
	{
		++(*pi);
		return NULL;
	}

	BTNode* root = BuyNode(a[*pi]);//创建根节点
	++(*pi);
	root->_left = BinaryTreeCreate(a, pi);
	root->_right = BinaryTreeCreate(a, pi);

	return root;
}

void BinaryTreeDestory(BTNode* root)//销毁二叉树 利用递归删除
{
	assert(root);

	if (root == NULL)

		return;

	BinaryTreeDestory(root->_left);
	BinaryTreeDestory(root->_right);
	free(root);
	root = NULL;
}

int BinaryTreeSize(BTNode* root)//计算二叉树节点数
{
	if (root == NULL)
		return 0;

	return BinaryTreeSize(root->_left) + BinaryTreeSize(root->_right) + 1;
}

int BinaryTreeLeafSize(BTNode* root)//计算二叉树叶子节点
{
	if (root == NULL)
	{
		return 0;
	}

	if (root->_left == NULL  && root->_right == NULL)
	{
		return 1;
	}

	return BinaryTreeLeafSize(root->_left) + BinaryTreeLeafSize(root->_right);
}

int BinaryTreeLevelKSize(BTNode* root, int k)//计算第k层节点数
{
	if (root == NULL)
		return 0;

	if (k == 1)
		return 1;

	return BinaryTreeLevelKSize(root->_left, k - 1) + BinaryTreeLevelKSize(root->_right, k - 1);
}

BTNode* BinaryTreeFind(BTNode* root, BTDataType x)//查找节点
{
	if (root == NULL)
		return NULL;

	if (root->_data == x)
	{
		return root;
	}

	struct BinaryTreeNode* lerr = BinaryTreeFind(root->_left, x);
	if (lerr != NULL)
		return lerr;
	struct BinaryTreeNode* rerr = BinaryTreeFind(root->_left, x);
	if (rerr != NULL)
		return rerr;

	return NULL;
	
}

void BinaryTreePrevOrder(BTNode* root)//前序遍历
{
	if (root == NULL)
	{
		return ;
	}

	printf("%c ", root->_data);
	BinaryTreePrevOrder(root->_left);
	BinaryTreePrevOrder(root->_right);
}

void BinaryTreeInOrder(BTNode* root)//中序遍历
{
	if (root == NULL)
		return;

	BinaryTreeInOrder(root->_left);
	printf("%c ", root->_data);
	BinaryTreeInOrder(root->_right);
}

void BinaryTreePostOrder(BTNode* root)//后序遍历
{
	if (root == NULL)
		return;

	BinaryTreePostOrder(root->_left);
	BinaryTreePostOrder(root->_right);
	printf("%c ", root->_data);
}

void BinaryTreeLevelOrder(BTNode* root)//层序遍历{   	Queue q;	QueueInit(&q);	QueuePush(&q,root);	while (!QueueEmpty(&q))	{		BTNode* front = QueueFront(&q);		QueuePop(&q);		printf("%c ", front->_data);		QueuePush(&q, root->_left);		QueuePush(&q, root->_right);	}}

void Test()
{
	BTNode* a = "ABD##E##C##";
	int i = 0;
	BTNode* root = BinaryTreeCreate(a, &i);
	printf("前序遍历为：");
	BinaryTreePrevOrder(root);
	printf("\n");
	printf("中序遍历为：");
	BinaryTreeInOrder(root);
	printf("\n");
	printf("后序遍历为：");
	BinaryTreePostOrder(root);
	printf("\n");
	printf("后序遍历为：");
	BinaryTreeLevelOrder(root);
	printf("\n");
	printf("二叉树的节点个数：%d\n", BinaryTreeSize(root));
	printf("二叉树的叶子节点个数：%d\n", BinaryTreeLeafSize(root));
	
}