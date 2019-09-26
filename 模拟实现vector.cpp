//vector核心接口模拟实现
namespace tt
{
	template<class T>
	class Vector
	{
	public:
		typedef T* Iterator;

		Iterator begin()//返回开始位置
		{
			return _start;
		}

		Iterator end()//返回最后一位
		{
			return _finish;
		}

		size_t size() const//返回vector容量大小
		{
			return _finish - _start;
		}

		size_t capacity() const //返回空间大小
		{
			return _endOfStorage - _start;
		}

		Vector()//无参构造函数
			: _start(nullptr)
			, _finish(nullptr)
			, _endOfStorage(nullptr)
		{
		}

		Vector(const Vector<T>& v)//拷贝构造函数
		{
			_start = new T[v.size()];
			memcpy(_start, v._start, sizeof(T)*v.size());
			_finish = _start + v.size();
			_endOfStorage = _start + v.size();
		}

		//重载 =   v1 = v2
		Vector<T>& operator=(Vector<T> v)
		{
			//隐含的this指针;
			swap(v);//约等于 this -> swap(v);
			return *this;
		}

		~Vector()//析构函数 
		{
			if (_start)
			{
				delete[] _start;
				_start = _finish = _endOfStorage = nullptr;
			}
		}

		//交换函数 v1.swap（v2）
		void swap(Vector<T>& v)
		{
			swap(_start, v._start);
			swap(_finish, v._finish);
			swap(_endOfStorage, v._endOfStorage);
		}

		//改变数据的个数
		Vector resize(size_t n, const T& val = T())
		{
			if (n < size())//情况1
			{
				_finish = _start + n;
			}

			if (n > capacity())//情况3
			{
				reserve(n);
			}

			while (_finish != _start + n)//情况2 + 3
			{
				*_finish = val;
				++_finish;
			}

		}

		//改变容量的大小
		Vector reserve(size_t n)
		{
			if (n > capacity())
			{
				size_t sz = size();
				T* tmp = new T[n];
				if (_start）
				{
					memcpy(tmp, _start, sizeof(T)*sz);//拷贝数据
					delete[] _start;//销毁原来的数据
				}

				_start = tmp;
				_finish = _start + sz;
				_endOfStorage = _start + n;
			}
		}

		void insert(iterator pos, const T& x)//在pos位置前插入数据x
		{
			assert(pos->_start && pos <= _finish);
			
			if (_finish == _endOfStorage)//判断容量是否沾满
			{
				size_t n = pos - _start;
				size_t newcapacity = capacity() == 0 ? 2 : capacity * 2;
				reserve(newcapacity);
				pos = _start + n;
			}

			iterator end = _finish - 1;//迭代器
			while (end >= pos)
			{
				*(end + 1) = *end;
				--end;
			}
			*pos = x;
			++_finish;
		}

	private:
		Iterator _start;
		Iterator _finish;
		Iterator _endOfStorage;
	};
}
