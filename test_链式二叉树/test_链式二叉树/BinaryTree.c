#include"BinaryTree.h"



/************************����**********************/

void QueueInit(Queue* pq)//��ʼ��
{
	assert(pq);

	pq->_front = pq->_tail = (QueueNode*)malloc(sizeof(QueueNode));
	assert(pq->_front);
	pq->_front->_next = NULL;
	pq->_front->_data = 0;
}

void QueueDestory(Queue* pq)//����
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

QueueNode* BuyQueueNode(QUDataType x)//����һ���ڵ�
{
	QueueNode* newnode = (QueueNode*)malloc(sizeof(QueueNode));
	assert(newnode);
	newnode->_data = x;
	newnode->_next = NULL;
	return newnode;
}

void QueuePush(Queue* pq, QUDataType x)//β��
{
	assert(pq);
	QueueNode* newnode = BuyQueueNode(x);
	assert(newnode);//�ж�����ռ��Ƿ�ɹ�
	pq->_tail->_next = newnode;
	pq->_tail = newnode;
}

void QueuePop(Queue* pq)//ͷɾ
{
	assert(pq && pq->_front->_next != NULL);
	QueueNode* next = pq->_front->_next;//�����ͷ��һ��Ԫ��
	if (pq->_tail == next)
	{
		pq->_tail = pq->_front;
	}
	pq->_front->_next = next->_next;
	free(next);
	next = NULL;

}

QUDataType QueueFront(Queue* pq)//ȡ����ǰͷ��Ԫ��
{
	assert(pq);

	return pq->_front->_next->_data;;
}

QUDataType QueueBack(Queue* pq)//ȡ����ǰβ��Ԫ��
{
	assert(pq);

	return pq->_tail->_data;
}

bool QueueEmpty(Queue* pq)//�ж϶����Ƿ�Ϊ��
{
	assert(pq);

	return pq->_front == pq->_tail ? false : true;
}

int QueueSize(Queue* pq)//���㵱ǰ����Ԫ��
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

void QueuePirnt(Queue* pq)//����ȡ������Ԫ��
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

/*********************������********************/

BTNode* BuyNode(BTDataType x)//����һ���ڵ�
{
	BTNode* newnode = (BTNode*)malloc(sizeof(BTNode));
	assert(newnode);
	newnode->_data = x;
	newnode->_left = newnode->_right = NULL;
	return newnode;
}
// ͨ��ǰ�����������"ABD##E#H##C"����������
BTNode* BinaryTreeCreate(BTDataType* a,int* pi)
{
	//����ǰ����� �ݹ���д���
	if (a[*pi] == '#')
	{
		++(*pi);
		return NULL;
	}

	BTNode* root = BuyNode(a[*pi]);//�������ڵ�
	++(*pi);
	root->_left = BinaryTreeCreate(a, pi);
	root->_right = BinaryTreeCreate(a, pi);

	return root;
}

void BinaryTreeDestory(BTNode* root)//���ٶ����� ���õݹ�ɾ��
{
	assert(root);

	if (root == NULL)

		return;

	BinaryTreeDestory(root->_left);
	BinaryTreeDestory(root->_right);
	free(root);
	root = NULL;
}

int BinaryTreeSize(BTNode* root)//����������ڵ���
{
	if (root == NULL)
		return 0;

	return BinaryTreeSize(root->_left) + BinaryTreeSize(root->_right) + 1;
}

int BinaryTreeLeafSize(BTNode* root)//���������Ҷ�ӽڵ�
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

int BinaryTreeLevelKSize(BTNode* root, int k)//�����k��ڵ���
{
	if (root == NULL)
		return 0;

	if (k == 1)
		return 1;

	return BinaryTreeLevelKSize(root->_left, k - 1) + BinaryTreeLevelKSize(root->_right, k - 1);
}

BTNode* BinaryTreeFind(BTNode* root, BTDataType x)//���ҽڵ�
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

void BinaryTreePrevOrder(BTNode* root)//ǰ�����
{
	if (root == NULL)
	{
		return ;
	}

	printf("%c ", root->_data);
	BinaryTreePrevOrder(root->_left);
	BinaryTreePrevOrder(root->_right);
}

void BinaryTreeInOrder(BTNode* root)//�������
{
	if (root == NULL)
		return;

	BinaryTreeInOrder(root->_left);
	printf("%c ", root->_data);
	BinaryTreeInOrder(root->_right);
}

void BinaryTreePostOrder(BTNode* root)//�������
{
	if (root == NULL)
		return;

	BinaryTreePostOrder(root->_left);
	BinaryTreePostOrder(root->_right);
	printf("%c ", root->_data);
}

void BinaryTreeLevelOrder(BTNode* root)//�������{   	Queue q;	QueueInit(&q);	QueuePush(&q,root);	while (!QueueEmpty(&q))	{		BTNode* front = QueueFront(&q);		QueuePop(&q);		printf("%c ", front->_data);		QueuePush(&q, root->_left);		QueuePush(&q, root->_right);	}}

void Test()
{
	BTNode* a = "ABD##E##C##";
	int i = 0;
	BTNode* root = BinaryTreeCreate(a, &i);
	printf("ǰ�����Ϊ��");
	BinaryTreePrevOrder(root);
	printf("\n");
	printf("�������Ϊ��");
	BinaryTreeInOrder(root);
	printf("\n");
	printf("�������Ϊ��");
	BinaryTreePostOrder(root);
	printf("\n");
	printf("�������Ϊ��");
	BinaryTreeLevelOrder(root);
	printf("\n");
	printf("�������Ľڵ������%d\n", BinaryTreeSize(root));
	printf("��������Ҷ�ӽڵ������%d\n", BinaryTreeLeafSize(root));
	
}