typedef int QUDataType;

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
void QueuePush(Queue* pq,QUDataType x);//β��
void QueuePop(Queue* pq);//ͷɾ
QUDataType QueueFront(Queue* pq);//ȡ����ǰͷ��Ԫ��
QUDataType QueueBack(Queue* pq);//ȡ����ǰβ��Ԫ��
int QueueEmpty(Queue* pq);//�ж϶����Ƿ�Ϊ��
int QueueSize(Queue* pq);//���㵱ǰ����Ԫ��
void QueuePirnt(Queue* pq);//����ȡ������Ԫ��
void Test();

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

int QueueEmpty(Queue* pq)//�ж϶����Ƿ�Ϊ��
{
	assert(pq);

	return pq->_front == pq->_tail ? 0 : 1;
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

typedef struct {
    Queue q1;
    Queue q2;
} MyStack;

/** Initialize your data structure here. */

MyStack* myStackCreate() {
    MyStack* st = (MyStack*)malloc(sizeof(MyStack));
    QueueInit(&(st->q1));
    QueueInit(&(st->q2));
    
    return st;
}

/** Push element x onto stack. */
void myStackPush(MyStack* obj, int x) {
  if(QueueEmpty(&(obj->q1) != 0))
  {
      QueuePush(&(obj->q1),x);
  }
  else
  {
      QueuePush(&(obj->q2),x);
  }
}

/** Removes the element on top of the stack and returns that element. */
int myStackPop(MyStack* obj) {
    Queue *empty = &(obj->q1),*noempty = &(obj->q2);
    if(QueueEmpty(&(obj->q1)) != 0)
    {
        empty = &(obj->q2);
        noempty = &(obj->q1); 
    }
    
    while(QueueSize(noempty) > 1)
    {
        QueuePush(empty,QueueFront(noempty));
        QueuePop(noempty);
    }
    
    int front = QueueFront(noempty);
    QueuePop(noempty);
    return front;
}

/** Get the top element. */
int myStackTop(MyStack* obj) {
  Queue* empty = &(obj->q1),*noempty = &(obj->q2);
    if(QueueEmpty(&(obj->q1)) != 0)
    {
        empty = &(obj->q2);
        noempty = &(obj->q1); 
    }
    
    while(QueueSize(noempty) > 1)
    {
        QueuePush(empty,QueueFront(noempty));
        QueuePop(noempty);
    }
    
    int front = QueueFront(noempty);
    QueuePush(empty,front);
    QueuePop(noempty);
    return front;
}

/** Returns whether the stack is empty. */
bool myStackEmpty(MyStack* obj) {
  return QueueEmpty(&(obj->q1)) + QueueEmpty(&(obj->q2)) == 0 ? true : false;
}

void myStackFree(MyStack* obj) {
    QueueDestory(&(obj->q1));
    QueueDestory(&(obj->q2));
    
    free(obj);

}

/**
 * Your MyStack struct will be instantiated and called as such:
 * MyStack* obj = myStackCreate();
 * myStackPush(obj, x);
 
 * int param_2 = myStackPop(obj);
 
 * int param_3 = myStackTop(obj);
 
 * bool param_4 = myStackEmpty(obj);
 
 * myStackFree(obj);
*/
