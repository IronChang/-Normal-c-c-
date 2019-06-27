#include"Slist.h"

void SlistInit(Slist *plt)//链表初始化
{
	assert(plt);

	plt->_head = NULL;
}

void SlistPushBack(Slist *plt, SlistNodeDate x)//尾部插入
{
	assert(plt);

	SlistNode *newnode = (SlistNode*)malloc(sizeof(SlistNode));
	newnode->_date = x;
	newnode->_next = NULL;

	if (plt->_head == NULL)//链表为空
	{
		plt->_head = newnode;
	}
	else//链表不为空
	{
		SlistNode *cur = plt->_head;
		while (cur->_next != NULL)
		{
			cur = cur->_next;
		}
		cur->_next = newnode;
	}
}

void SlistPushFront(Slist *plt, SlistNodeDate x)//头部插入
{
	assert(plt);

	SlistNode  *newnode =(SlistNode*)malloc(sizeof(SlistNode));
	newnode->_date = x;
	newnode->_next = NULL;

	if (plt->_head == NULL)//链表为空
	{
		plt->_head = newnode;
	}
	else//链表不为空
	{
		newnode->_next = plt->_head;
		plt->_head = newnode;
	}
}

void SlistPopBack(Slist *plt)//尾部删除
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

void SlistPopFront(Slist *plt)//头部删除
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

void SlistDestory(Slist *plt)//删除链表
{
	assert(plt);
	SlistNode *cur = plt->_head;

	if (plt->_head == NULL)
	{
		printf("空链表\n");
	}
	else
	{
		while (plt->_head != NULL)
		{
			SlistNode *cur = plt->_head;
			plt->_head = cur->_next;
			free(cur);
		}
		printf("删除成功！\n");
	}
}

void SlistPrint(Slist *plt)//输出链表
{
	SlistNode *cur = plt->_head;
	if (plt->_head == NULL)
	{
		printf("链表为空！\n");
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

void Test_Slist_1()//测试函数
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

void Test_Slist_2()//测试函数
{
	Slist pk;

	SlistInit(&pk);
	SlistDestory(&pk);
	SlistPrint(&pk);

}


