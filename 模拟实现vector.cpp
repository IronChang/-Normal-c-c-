//vector���Ľӿ�ģ��ʵ��
namespace tt
{
	template<class T>
	class Vector
	{
	public:
		typedef T* Iterator;

		Iterator begin()//���ؿ�ʼλ��
		{
			return _start;
		}

		Iterator end()//�������һλ
		{
			return _finish;
		}

		size_t size() const//����vector������С
		{
			return _finish - _start;
		}

		size_t capacity() const //���ؿռ��С
		{
			return _endOfStorage - _start;
		}

		Vector()//�޲ι��캯��
			: _start(nullptr)
			, _finish(nullptr)
			, _endOfStorage(nullptr)
		{
		}

		Vector(const Vector<T>& v)//�������캯��
		{
			_start = new T[v.size()];
			memcpy(_start, v._start, sizeof(T)*v.size());
			_finish = _start + v.size();
			_endOfStorage = _start + v.size();
		}

		//���� =   v1 = v2
		Vector<T>& operator=(Vector<T> v)
		{
			//������thisָ��;
			swap(v);//Լ���� this -> swap(v);
			return *this;
		}

		~Vector()//�������� 
		{
			if (_start)
			{
				delete[] _start;
				_start = _finish = _endOfStorage = nullptr;
			}
		}

		//�������� v1.swap��v2��
		void swap(Vector<T>& v)
		{
			swap(_start, v._start);
			swap(_finish, v._finish);
			swap(_endOfStorage, v._endOfStorage);
		}

		//�ı����ݵĸ���
		Vector resize(size_t n, const T& val = T())
		{
			if (n < size())//���1
			{
				_finish = _start + n;
			}

			if (n > capacity())//���3
			{
				reserve(n);
			}

			while (_finish != _start + n)//���2 + 3
			{
				*_finish = val;
				++_finish;
			}

		}

		//�ı������Ĵ�С
		Vector reserve(size_t n)
		{
			if (n > capacity())
			{
				size_t sz = size();
				T* tmp = new T[n];
				if (_start��
				{
					memcpy(tmp, _start, sizeof(T)*sz);//��������
					delete[] _start;//����ԭ��������
				}

				_start = tmp;
				_finish = _start + sz;
				_endOfStorage = _start + n;
			}
		}

		void insert(iterator pos, const T& x)//��posλ��ǰ��������x
		{
			assert(pos->_start && pos <= _finish);
			
			if (_finish == _endOfStorage)//�ж������Ƿ�մ��
			{
				size_t n = pos - _start;
				size_t newcapacity = capacity() == 0 ? 2 : capacity * 2;
				reserve(newcapacity);
				pos = _start + n;
			}

			iterator end = _finish - 1;//������
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
