#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;


	//___________________________________________________________
	//ģ��ʵ��list
	//___________________________________________________________


	//list�Ľڵ���
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

	//����������
	//typedef _Listiterator<T,T&,T*> iterator;
	//typedef _Listiterator<T,const T&,const T*> const_iterator;

	template<class T, class ref, class ptr>
	struct Listiterator
	{
		typedef ListNode<T> Node;//������ڵ�������ΪNode
		typedef Listiterator<T, T&, T*> self;//���Լ������ʹ�������
		Node* _node;

		Listiterator()//�޲ι��������
			:_node(nullptr)
		{}
		Listiterator(Node* node)//�вι��������
			:_node(node)
		{}

		//���� != ==
		bool operator != (const self& s)
		{
			return _node != s._node;
		}

		bool operator == (const self& s)
		{
			return _node == s._node;
		}

		//����++,ǰ�á�����
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

		//����-- ǰ�á�����
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

		//����* ->������
		ref operator *()
		{
			return (*_node)._val;
		}

		ref operator ->()
		{
			return *_node;
		}
	};

	//���巴�������,ģ�����ΪT,T������,T���͵�ָ��
	template<typename T, typename ref, typename ptr>
	struct ListReverseiterator
	{
		typedef ListNode<T> Node;//������ڵ�������Ϊ Node
		typedef ListReverseiterator<T, T&, T*> self;//���Լ�������������Ϊself��������

		Node* _node;
		ListReverseiterator()
			:_node(nullptr)
		{}
		ListReverseiterator(Node* node)
			:_node(node)
		{}

		//����++
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

		//����--
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

		//���� != ==
		bool operator ==(const self& s)
		{
			return _node->val == s._node->_val;
		}

		bool operator !=(const self& s)
		{
			return _node->_val != s._node->_val;
		}

		//����1* ->������
		ref operator *()
		{
			return (*_node)._val;
		}

		ref operator ->()
		{
			return *_node;
		}
	};

	//��������
	template<class T>
	class List
	{
		typedef ListNode<T> Node;

	public:
		typedef Listiterator<T, T&, T*> Iterator;//������Ϊ������
		typedef ListReverseiterator<T, T&, T*> ReverseIterator;//������Ϊ���������

		Node* buynode(const T& t)//����һ���½ڵ�
		{
			return new Node(t);
		}

		List()//���캯��
			:_head(buynode(T()))
		{
			_head->_next = _head;
			_head->_prev = _head;
		}

		void push_back(const T& x)//β������Ԫ��
		{
			Node* tail = _head->_prev;
			Node* tmp = buynode(x);
			tail->_next = tmp;
			tmp->_prev = tail;
			tmp->_next = _head;
			_head->_prev = tmp;
		}

		//���巵�ص��������͵�Begin()��End()
		Iterator begin()
		{
			return Iterator(_head->_next);
		}

		Iterator end()
		{
			return Iterator(_head);
		}

		//���巵�ص��������͵�Begin()��End()
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
	List<int> l;//����һ��list
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
