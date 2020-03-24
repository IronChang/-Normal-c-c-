#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<iostream>
using namespace std;

typedef int SLTDataType;

typedef struct SListNode
{
	SLTDataType _value;
	struct SListNode* _next;
}SListNode;

class SList
{
public:
	SList();
	~SList();
	SListNode* BuySListNode(SLTDataType x);
	void SListPushFront(SLTDataType x);
	void SListPopFront();
	SListNode* SListFind(SLTDataType x);
	void SListInsert(SLTDataType x);
	void SListErase(SLTDataType x);
	void SlistReverse();
	void SListPrint();

private:
	SListNode* _head;//头结点
};


#define _CRT_SECURE_NO_WARNINGS 1
#include"test.h"
#include"Test.hpp"


SList::SList()//构造函数
{
	this->_head = nullptr;
}
SList::~SList()
{
	//判断链表是否为空
	if (this->_head == nullptr)
	{
		cout << "链表为空" << endl;
	}

	while (this->_head != nullptr)
	{
		SListNode* cur = this->_head;
		this->_head = cur->_next;
		delete cur;
	}
}
SListNode* SList::BuySListNode(SLTDataType x)
{
	//SListNode* tmp = new SListNode;
	SListNode* tmp = (SListNode*)malloc(sizeof(SListNode));
	if (tmp != nullptr)
	{
		tmp->_next = nullptr;
		tmp->_value = x;
	}
	return tmp;
}
void SList::SListPushFront(SLTDataType x)
{
	SListNode* tmp = BuySListNode(x);
	tmp->_next = this->_head;
	this->_head = tmp;
}
void SList::SListPopFront()
{
	if (this->_head == nullptr)
	{
		cout << "链表为空" << endl;
		return;
	}

	SListNode* cur = this->_head;
	this->_head = cur->_next;
	delete cur;
}
SListNode* SList::SListFind(SLTDataType x)
{
	if (this->_head == nullptr)
	{
		cout << "链表为空" << endl;
		return nullptr;
	}

	SListNode* cur = this->_head;
	while (cur)
	{
		if (cur->_value == x)
		{
			return cur;
		}
		cur = cur->_next;
	}
	cout << "表中没有该值" << endl;
	return nullptr;
}
void SList::SListInsert(SLTDataType x)
{
	if (this->_head == nullptr)
	{
		cout << "链表为空" << endl;
		return ;
	}

	SListNode*cur, *prev;
	prev = cur = this->_head;
	
	while (cur)
	{
		if (cur->_value == x)
		{

				SListNode* tmp = this->BuySListNode(x);
				tmp->_next = prev->_next;
				prev->_next = tmp;
			
		}

		prev = cur;
		cur = cur->_next;
	}
}
void SList::SListErase(SLTDataType x)
{
	if (this->_head == nullptr)
	{
		cout << "链表为空" << endl;
		return;
	}

	SListNode* cur, *prev = nullptr;
	cur = this->_head;

	while (cur)
	{
		if (cur->_value == x)
		{
			if (cur == this->_head)
			{
				this->_head = cur->_next;
			}
			else
			{
				prev->_next = cur->_next;
			}
			delete cur;
			return;
		}
		prev = cur;
		cur = cur->_next;
	}
}
void  SList::SlistReverse()
{
	if (this->_head == nullptr)
	{
		cout << "链表为空" << endl;
		return;
	}
	else if (this->_head->_next == nullptr)
	{
		return;
	}
	else
	{
		SListNode* cur, *prev, *next;
		cur = this->_head;
		next = prev = nullptr;
		while (cur)
		{
			next = cur->_next;
			cur->_next = prev;
			prev = cur;
			cur = next;
		}
		this->_head = prev;
	}
}
void SList::SListPrint()
{
	if (this->_head == nullptr)
	{
		cout << "链表为空" << endl;
		return;
	}
	else
	{

		SListNode* cur = this->_head;
		while (cur)
		{
			cout << cur->_value << "->";
			cur = cur->_next;
		}
		cout << "NULL" << endl;
	}
}


void test1()
{
	SList sl;
	sl.SListPushFront(0);
	sl.SListPushFront(1);
	sl.SListPushFront(2);
	sl.SListPushFront(3);
	sl.SListPushFront(4);

	sl.SListPrint();

	//sl.SListPopFront();
	//sl.SListInsert(3);
	//sl.SListErase(3);
	sl.SlistReverse();

	sl.SListPrint();


	//sl.SListFind(8);
}


int main()
{
	test2();
	system("pause");
	return 0;
}