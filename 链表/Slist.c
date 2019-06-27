#include"Slist.h"

void SlistInit(Slist *plt)//�����ʼ��
{
	assert(plt);

	plt->_head = NULL;
}

void SlistPushBack(Slist *plt, SlistNodeDate x)//β������
{
	assert(plt);

	SlistNode *newnode = (SlistNode*)malloc(sizeof(SlistNode));
	newnode->_date = x;
	newnode->_next = NULL;

	if (plt->_head == NULL)//����Ϊ��
	{
		plt->_head = newnode;
	}
	else//����Ϊ��
	{
		SlistNode *cur = plt->_head;
		while (cur->_next != NULL)
		{
			cur = cur->_next;
		}
		cur->_next = newnode;
	}
}

void SlistPushFront(Slist *plt, SlistNodeDate x)//ͷ������
{
	assert(plt);

	SlistNode  *newnode =(SlistNode*)malloc(sizeof(SlistNode));
	newnode->_date = x;
	newnode->_next = NULL;

	if (plt->_head == NULL)//����Ϊ��
	{
		plt->_head = newnode;
	}
	else//����Ϊ��
	{
		newnode->_next = plt->_head;
		plt->_head = newnode;
	}
}

void SlistPopBack(Slist *plt)//β��ɾ��
{
	assert(plt);
    SlistNode *cur = plt->_head;

	if (plt->_head == NULL)
	{
		return;
	}
	else if (cur->_next == NULL)
	{
		free(cur);
		plt->_head = NULL;
	}
	else
	{
		while (cur->_next->_next != NULL)
		{
			cur = cur->_next;
		}
		free(cur->_next);
		cur->_next = NULL;
	}
}

void SlistPopFront(Slist *plt)//ͷ��ɾ��
{
	assert(plt);
	SlistNode  *cur = plt->_head;

	if (plt->_head == NULL)
	{
		return;
	}
	else if (cur->_next == NULL)
	{
		free(cur);
		plt->_head = NULL;
	}
	else
	{
		plt->_head = cur->_next;
		free(cur);
	}
}

void SlistDestory(Slist *plt)//ɾ������
{
	assert(plt);
	SlistNode *cur = plt->_head;

	if (plt->_head == NULL)
	{
		printf("������\n");
	}
	else
	{
		while (plt->_head != NULL)
		{
			SlistNode *cur = plt->_head;
			plt->_head = cur->_next;
			free(cur);
		}
		printf("ɾ���ɹ���\n");
	}
}

void SlistPrint(Slist *plt)//�������
{
	SlistNode *cur = plt->_head;
	if (plt->_head == NULL)
	{
		printf("����Ϊ�գ�\n");
	}
	else
	{
		while (cur != NULL)
		{
			printf("%d->", cur->_date);
			cur = cur->_next;
		}
		printf("NULL\n");
	}

}

void Test_Slist_1()//���Ժ���
{
	Slist pl;

	SlistInit(&pl);

	SlistPushBack(&pl, 1);
	SlistPushBack(&pl, 2);
	SlistPushBack(&pl, 3);
	SlistPushBack(&pl, 4);
	SlistPushFront(&pl, 0);
	SlistPrint(&pl);

	SlistPopBack(&pl);
	SlistPopBack(&pl);
	//SlistPopBack(&pl);
	//SlistPopBack(&pl);
	//SlistPopFront(&pl);
	//SlistPopFront(&pl);
	//SlistPopFront(&pl);
	//SlistPopFront(&pl);
	//SlistPopFront(&pl);
	SlistPrint(&pl);
	//SlistDestory(&pl);


}

void Test_Slist_2()//���Ժ���
{
	Slist pk;

	SlistInit(&pk);
	SlistDestory(&pk);
	SlistPrint(&pk);

}


