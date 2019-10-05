//迭代器的作用就是为了让容器的访问像指针一样可以实现++，-- ，解引用，->，以及重载? != ， == 的比较符。
//
//迭代器有两种实现方式：
//1.原生态指针，如vectot
//2.将原生态指针进行封装，因迭代器的使用形式与指针完全相同，?因此，在自定义的类中必须实现以下方法：
//1)指针可以解引用，迭代器的类中必须重载operator*()
//2)指针可以通过->访问其所指空间成员，迭代器类中必须重载oprator->()
//3)指针可以++向后移动，迭代器类中必须重载operator++()与operator++(int)
//4)迭代器需要进行是否相等的比较，因此还需要重载operator == ()与operator != ()
//
//模拟实现list ，首先需要构造结点和迭代器，然后创建list链表结构及其相关接口


//___________________________________________________________
//模拟实现list
//___________________________________________________________


	//list的节点类
	template<class T>
	struct ListNode
	{
		ListNode(const T& val = T())
		:_prev(nullptr)
		, _next(nullptr)
		, _val = val
		{}

		ListNode<T>* _prev;
		ListNode<T>* _next;
		T _val;
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

		//重载!= ==
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

		self& operator ++(int)
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

		self& operator --(int)
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

		self& operator ++(int)
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

		self& operator --(int)
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
			return Node(t);
		}

		List()//构造函数
			:_head(buynode(T()))
		{
			_head->_next = _head;
			_head->_prev = _head
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

