#define _CRT_SECURE_NO_WARNINGS 1
// 2、带头双向循环链表增删查改实现
typedef int LTDataType;
typedef struct ListNode
{
	LTDataType _data;
	struct ListNode* _next;
	struct ListNode* _prev;
}ListNode;

class List
{
public:
	List();
	~List();
	ListNode* BuyNode(LTDataType x);
	void ListPushBack(LTDataType x);
	void ListPopBack();
	void ListPushFront(LTDataType x);
	void ListPopFront();
	ListNode* ListFind(LTDataType x);
	void ListRemove(LTDataType x);
	void ListPrint();

private:
	ListNode* _head;
};

ListNode* List::BuyNode(LTDataType x)
{
	ListNode* tmp = new ListNode;
	tmp->_data = x;
	tmp->_next = tmp->_prev = nullptr;
	return tmp;
}

List::List()
{
	this->_head = this->BuyNode(0);
	this->_head->_next = this->_head;
	this->_head->_prev = this->_head;
}

List::~List()
{
	ListNode* cur = this->_head->_next;

	while (cur != this->_head)
	{
		ListNode* next = cur->_next;
		ListNode* prev = cur->_prev;

		prev->_next = next;
		next->_prev = prev;

		delete cur;

		cur = next;
	}

}

void List::ListPushBack(LTDataType x)
{
	ListNode* tmp = this->BuyNode(x);

	this->_head->_prev->_next = tmp;
	tmp->_next = this->_head;

	tmp->_prev = this->_head->_prev;
	this->_head->_prev = tmp;
}

void List::ListPrint()
{
	if (this->_head->_next == this->_head)
	{
		cout << "链表为空" << endl;
		return;
	}

	ListNode* cur = this->_head->_next;
	while (cur != this->_head)
	{
		cout << cur->_data << "->";
		cur = cur->_next;
	}
	cout << "NULL" << endl;
}

void List::ListPopBack()
{
	ListNode* cur = this->_head->_prev;
	this->_head->_prev = cur->_prev;
	cur->_prev->_next = this->_head;
	delete cur;
}

void List::ListPushFront(LTDataType x)
{
	ListNode* cur = this->_head->_next;
	ListNode* tmp = this->BuyNode(x);

	this->_head->_next = tmp;
	tmp->_next = cur;

	cur->_prev = tmp;
	tmp->_prev = this->_head;
}

void List::ListPopFront()
{
	ListNode* cur = this->_head->_next;

	this->_head->_next = cur->_next;
	cur->_next->_prev = this->_head;
	delete cur;
}

ListNode* List::ListFind(LTDataType x)
{
	ListNode* cur = this->_head->_next;

	while (cur != this->_head)
	{
		if (cur->_data == x)
		{
			return cur;
		}

		cur = cur->_next;

	}

	return nullptr;
}

void List::ListRemove(LTDataType x)
{
	ListNode* cur = this->ListFind(x);

	ListNode* prev = cur->_prev;
	ListNode* next = cur->_next;

	prev->_next = next;
	next->_prev = prev;

	delete cur;
}

void test2()
{
	List l;
	l.ListPushBack(0);
	l.ListPushBack(1);
	l.ListPushBack(2);
	l.ListPushBack(3);
	l.ListPrint();
	//l.ListPopBack();
	l.ListPrint();
	l.ListPushFront(7);
	l.ListPopFront();
	l.ListRemove(3);
	l.ListPrint();
	l.~List();
	l.ListPrint();

}



