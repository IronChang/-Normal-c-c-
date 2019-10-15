namespace bit
{
	template<class T>
	struct __list_node
	{
		__list_node<T>* _next;
		__list_node<T>* _prev;
		T _data;

		__list_node(const T& x)
			:_data(x)
			, _next(nullptr)
			, _prev(nullptr)
		{}
	};

	template<class T>
	struct __list_iterator
	{
		typedef __list_node<T> node;

		node* _node;

		__list_iterator(node* node)
			:_node(node)
		{}

		T& operator*()
		{
			return _node->_data;
		}

		__list_iterator<T>& operator++()
		{
			_node = _node->_next;
			return *this;
		}

		__list_iterator<T> operator++(int)
		{
			__list_iterator<T> tmp(*this);
			_node = _node->_next;
			return tmp;
		}

		// it1 !=  it2
		bool operator!=(const __list_iterator<T>& it)
		{
			return _node != it._node;
		}
	};

	template<class T>
	class list
	{
		typedef __list_node<T> node;
	public:
		typedef __list_iterator<T> iterator;

		iterator begin()
		{
			return iterator(_head->_next);
		}

		iterator end()
		{
			return iterator(_head);
		}

		list()
		{
			_head = new node(T());
			_head->_next = _head;
			_head->_prev = _head;
		}

		void push_back(const T& x)
		{
			node* tail = _head->_prev;
			node* newnode = new node(x);

			// head ... tail newnode 
			tail->_next = newnode;
			newnode->_prev = tail;
			newnode->_next = _head;
			_head->_prev = newnode;
		}

		// 


	private:
		node* _head;
	};

	void test_list1()
	{
		list<int> l;
		l.push_back(1);
		l.push_back(2);
		l.push_back(3);
		l.push_back(4);

		list<int>::iterator it = l.begin();
		while (it != l.end())
		{
			cout << *it << " ";
			++it;
		}
		cout << endl;
	}
}