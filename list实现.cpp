#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;


	//___________________________________________________________
	//模拟实现list
	//___________________________________________________________


	//list的节点类
	template<class T>
	struct ListNode
	{
		ListNode<T>* _prev;
		ListNode<T>* _next;
		T _val;

		ListNode(const T& val = T())
			:_prev(nullptr)
			, _next(nullptr)
			, _val(val)
		{}
	};

	//创建迭代器
	//typedef _Listiterator<T,T&,T*> iterator;
	//typedef _Listiterator<T,const T&,const T*> const_iterator;

	template<class T, class ref, class ptr>
	struct Listiterator
	{
		typedef ListNode<T> Node;//将链表节点重命名为Node
		typedef Listiterator<T, T&, T*> self;//将自己的类型从新命名
		Node* _node;

		Listiterator()//无参构造迭代器
			:_node(nullptr)
		{}
		Listiterator(Node* node)//有参构造迭代器
			:_node(node)
		{}

		//重载 != ==
		bool operator != (const self& s)
		{
			return _node != s._node;
		}

		bool operator == (const self& s)
		{
			return _node == s._node;
		}

		//重载++,前置、后置
		self& operator ++()
		{
			_node = _node->next;
			return (self)_node;
		}

		self operator ++(int)
		{
			Node* tmp = _node;
			++_node;
			return tmp;
		}

		//重载-- 前置、后置
		self& operator --()
		{
			_node = _node->_prev;
			return (self)_node;
		}

		self operator --(int)
		{
			Node* tmp = _node;
			--_node;
			return tmp;
		}

		//重载* ->操作符
		ref operator *()
		{
			return (*_node)._val;
		}

		ref operator ->()
		{
			return *_node;
		}
	};

	//定义反向迭代器,模板参数为T,T的引用,T类型的指针
	template<typename T, typename ref, typename ptr>
	struct ListReverseiterator
	{
		typedef ListNode<T> Node;//将链表节点重命名为 Node
		typedef ListReverseiterator<T, T&, T*> self;//将自己的类型重命名为self，简化命名

		Node* _node;
		ListReverseiterator()
			:_node(nullptr)
		{}
		ListReverseiterator(Node* node)
			:_node(node)
		{}

		//重载++
		self& operator ++()
		{
			_node = _node->_prev;
			return _node;
		}

		self operator ++(int)
		{
			Node* tmp = _node;
			_node = _node->_prev;
			return tmp;
		}

		//重载--
		self& operator --()
		{
			_node = _node->_next;
			return _node;
		}

		self operator --(int)
		{
			Node* tmp = _node;
			_node = _node->_next;
			return tmp;
		}

		//重载 != ==
		bool operator ==(const self& s)
		{
			return _node->val == s._node->_val;
		}

		bool operator !=(const self& s)
		{
			return _node->_val != s._node->_val;
		}

		//重载1* ->操作符
		ref operator *()
		{
			return (*_node)._val;
		}

		ref operator ->()
		{
			return *_node;
		}
	};

	//定义链表
	template<class T>
	class List
	{
		typedef ListNode<T> Node;

	public:
		typedef Listiterator<T, T&, T*> Iterator;//重命名为迭代器
		typedef ListReverseiterator<T, T&, T*> ReverseIterator;//重命名为反向迭代器

		Node* buynode(const T& t)//申请一个新节点
		{
			return new Node(t);
		}

		List()//构造函数
			:_head(buynode(T()))
		{
			_head->_next = _head;
			_head->_prev = _head;
		}

		void push_back(const T& x)//尾部插入元素
		{
			Node* tail = _head->_prev;
			Node* tmp = buynode(x);
			tail->_next = tmp;
			tmp->_prev = tail;
			tmp->_next = _head;
			_head->_prev = tmp;
		}

		//定义返回迭代器类型的Begin()和End()
		Iterator begin()
		{
			return Iterator(_head->_next);
		}

		Iterator end()
		{
			return Iterator(_head);
		}

		//定义返回迭代器类型的Begin()和End()
		ReverseIterator rbegin()
		{
			return ReverseIterator(_head->_prev);
		}

		ReverseIterator rend()
		{
			return ReverseIterator(_head);
		}

	protected:
		Node* _head;
	};



int main()
{
	List<int> l;//创建一个list
	l.push_back(1);
	l.push_back(2);
	l.push_back(3);
	l.push_back(4);
	l.push_back(5);

	List<int>::ReverseIterator it = l.rbegin();
	while (it != l.rend())
	{
		cout << *it << " ";
		it++;
	}

	cout << endl;

	system("pause");
	return 0;
}
