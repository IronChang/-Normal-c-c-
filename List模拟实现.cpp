namespace nm
{
	//list节点类
	template<class T>
	struct ListNode
	{
		ListNode(const T& val = T())
		:_prev(nullptr)
		, _next(nullptr)
		, _val(val)
		{}

		ListNode<T>* _prev;
		ListNode<T>* _next;
		T _val;
	};


	//正向迭代器实现
	template<class T,class ref,class ptr>
	class Listiterator
	{
		typedef ListNode<T>* Node;
		typedef Listiterator<T, ref, ptr> self;
	public:
		Listiterator(Node* pNode = nullptr)//构造函数
			:_node(pNode)
		{}

		Listiterator(const self& l)//拷贝构造函数
		{
			_node = l._node;
		}

		T& operator *()
		{
			return _node->_val;
		}

		T* operator ->()
		{
			return &(operator *());
		}

		self& operator ++()//前++
		{
			_node = _node->_next;
			return *this;
		}

		self operator ++(int)//后++
		{
			self tmp(*this);
			_node = _node->_next;
			return tmp;
		}

		bool operator != (const self& l)
		{
			return _node != l._node;
		}

		bool operator == (const self& l)
		{
			return _node != l._node;
		}
		Node _node;
	};


    //反向迭代器
	template<class T,class ref,class ptr,class iterator>
	class Listreverseiterator
	{
		typedef Listreverseiterator<T, ref, ptr, iterator> self;
	public:
		Listreverseiterator(const iterator& it)//构造函数
			:_it(it)
		{}

		Listreverseiterator(const self& s)//拷贝构造函数
		{
			_it = s._it;
		}

		ref operator*()
		{
			iterator tmp = _it;
			return *(--tmp);
		}

		ptr operator->()
		{
			return &operator*();
		}

		self& operator++()
		{
			--_it;
			return *this;
		}

		self operator++(int)
		{
			iterator tmp(_it);
			--_it;
			return tmp;
		}

		self& operator--()
		{
			++_it;
			return *this;
		}

		self operator--(int)
		{
			iterator tmp(_it);
			++_it;
			return tmp;
		}

		bool operator ==(const self& s)
		{
			return _it == s._it;
		}

		bool operator !=(const self& s)
		{
			return _it != s._it;
		}
	private:
		iterator _it;
	};

	//List
	template<class T>
	class List
	{
		typedef ListNode<T> Node;
		typedef Node* PNode;
	public:
		typedef ListIterator<T, T&, T*> iterator;
		typedef ListIterator<T, const T&, const T&> ConstIterator;
		typedef ListReverseIterator<T, T&, T*,Iterator> ReverseIterator;
		typedef ListReverseIterator<T, const T&, const T*,ConstIterator>ConstReverseIterator;

		//List构造
		List()//无参构造函数
		{
			CreateHead();
		}

		List(int n, const T& value = T())//初始化n个有value去初始化值
		{
			CreateHead();
			for (int i = 0; i < n; ++i)
			{
				pushback(value);
			}
		}

		template<class iterator>
		List(iterator first, iterator last)//用一个去见去初始化
		{
			CreateHead();
			while (first != last)
			{
				pushback(*first);
				++first;
			}
		}

		List(const List<T>& l)//拷贝构造函数
		{
			CreateHead();
			//用l中的元素去临时构造tmp，然后再与当前对象交换
			List<T> tmp(l.cbegin(), l.cend());
			this->swap(tmp);
		}

		list<T>& operator =(const List<T>& l)//赋值运算符
		{
			if (this != &l)
			{
				List<T> tmp(l);
				this->swap(temp);
			}
			return *this;
		}

		~List()
		{
			clear();
			delete _pHead;
			_pHead = nullptr;
		}

		//////////////////////////////////////////////////////////
		//List iterator
		iterator begin()
		{
			return iterator(_pHead->_next);
		}

		iterator end()
		{
			return iterator(_pHead);
		}

		ConstIterator cbegin() const
		{
			return ConstIterator(_pHead->_next);
		}

		ConstIterator cend() const
		{
			return ConstIterator(_pHead);
		}

		ReverseIterator rbegin()
		{
			return ReverseIterator(end());
		}

		ReverseIterator rend()
		{
			return ReverseIterator(begin());
		}

		ConstReverseIterator crbegin()
		{
			return ConstReverseIterator(cend());
		}

		ConstReverseIterator crend()
		{
			return ConstReverseIterator(cbegin());
		}

		//////////////////////////////////////////////////////
		//List capacity
		size_t size() const
		{
			size_t count = 0;
			PNode pCur = _pHead->_next;
			while (pCur != _pHead)
			{
				++count;
				pCur = pCur->_next;
			}
			return count;
		}

		bool empty()
		{
			return _pHead->_next == -_pHead;
		}

		void resize(size_t newsize, const T& val = T())
		{
			size_t oldsize = size();
			if (oldsize <= newsize)
			{
				for (size_t i = oldsize; i < newsize; ++i)
				{
					pushback(val);
				}
			}
			else
			{
				for (size_t i = onewsize; i < oldsize; ++i)
				{
					popback();
				}
			}
		}

		////////////////////////////////////////////////////
		//List access
		T& front()
		{
			return _pHead->_next->_val;
		}

		const T& front() const
		{
			return _pHead->_next->_val;
		}

		T& back()
		{
			return _pHead->_prev->_val;
		}

		const T& back() const
		{
			return _pHead->_prev->_val;
		}

		////////////////////////////////////////
		//List modify
		void pushback(const T& val)
		{
			PNode pNewNode = new Node(val);
	
			// 先把新节点尾插进去
			pNewNode->_pNext = _pHead;
			pNewNode->_pPre = _pHead->_pPre;

			// 再链接剩余两个指针
			_pHead->_pPre = pNewNode;
			pNewNode->_pPre->_pNext = pNewNode;

		}

		void popback()
		{
			PNode pDel = _pHead->_prev;

			if (_pDel != _pHead)
			{
				_pHead->_prev = pDel->_prev;
				pDel->_prev->_next = _pHead;
				delete pDel;
			}
		}


		void pushfront(const T& val)
		{
			PNode pNewNode = new Node(val);

			pNewNode->_next = _pHead->_next;
			pNewNode->_prev = _pHead;

			_pHead->_next = pNewNode;
			pNewNode->_next->_prev =pNewNode；
		}

		void popfront()
		{
			PNode pDel = _pHead->_next;
			if (pDel != -_pHead)
			{
				_pHead->_next = pDel->_next;
				pDel->_next->_prev = -_pHead;
				delete pDel;
			}
		}

		iterator insert(iterator pos, const T& val)
		{
			PNode pNewNode = new Node(val);
			pNode pCur = pos._Node;
			pNewNode->_pPre = pCur->_pPre;
			pNewNode->_pNext = pCur;
			pNewNode->_pPre->_pNext = pNewNode;
			pCur->_pPre = pNewNode;
			return Iterator(pNewNode);
		}

		void clear()
		{
			PNode pCur = _pHead->_pNext;
			while (pCur != _pHead)
			{
				_pHead->_pNext = pCur->_pNext;
				delete pCur;
				pCur = _pHead->_pNext;
			}
			_pHead->_pNext = _pHead;
			_pHead->_pPre = _pHead;
		}

		void swap(List<T>& l)
		{
			swap(_pHead, l._pHead);
		}


	private:
		void CreateHead()
		{
			_pHead = new Node;
			_pHead->_prev = _pHead;
			_pHead->_next = _pHead;
		}

	private:
		PNode _pHead;
	};
}
