#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<algorithm>
#include<assert.h>
#include<string>
using namespace std;

//vector����һ����̬˳���

template<class T>
class vector
{
public:
	//vector�ĵ���������һ��ԭ��ָ��
	typedef T* iterator;
	typedef const T* constiterator;

	iterator begin()
	{
		return _start;
	}

	iterator end()
	{
		return _finish;
	}

	constiterator cbegin() const
	{
		return _start;
	}

	constiterator cend() const
	{
		return _finish;
	}

	size_t size() const
	{
		return _finish - _start;
	}

	size_t capacity() const
	{
		return _endofstorage - _start;
	}

	//�޲ι��캯��
	vector()
		:_start(nullptr)
		,_finish(nullptr)
		,_endofstorage(nullptr)
	{ }

	//��ʼ��n��ֵΪval������vector
	vector(int n, const T& = value = T())
		:_start(nullptr)
		, _finish(nullptr)
		, _endofstorage(nullptr)
	{
		Reserve(n);
		while (n--)
		{
			PushBack(value);
		}
	}

	//��������������
	template<class inpputiterator>
	vector(inpputiterator first, inpputiterator last)//��һ������ȥ��ʼ������
	{
		Reserve(last - first);
		while (first != last)
		{
			PushBack(*first);
			++first;
		}
	}

	//�������캯��
	vector(const vector<T>& v)
		:_start(nullptr)
		, _finish(nullptr)
		, _endofstorage(nullptr)
	{
		Reserve(v.capacity());

		iterator it = begin();
		constiterator vit = cbegin();

		while (vit != v.cend)
		{
			*it++ = *vit++;
		}

		_finish = _start + v.size();
		_endofstorage = _start + v.capacity;
	}

	vector<T>& operator= (vector<T> v)
	{
		Swap(v);
		return *this;
	}

	~vector()
	{
		delete[] _start;
		_start = _finish = _endofstorage = nullptr;
	}

	void Reserve(size_t n)
	{
		if (n > capacity())
		{
			size_t Size = size();
			T* tmp = new T[n];

			if (_start)
			{
				for (size_t i = 0; i < Size; ++i)
				{
					tmp[i] = _start[i];
				}
			}
			_start = tmp;
			_finish = _start + size();
			_endofstorage = _start + n;
		}
	}

	void resize(size_t n, const T& value = T())
	{
		if (n <= size())
		{
			_finish = _start + n;
			return;
		}

		if (n > capacity())
		{
			Reserve(n);
		}

		iterator it = _finish;
		iterator _finish = _start + n;

		while (it != _finish)
		{
			*it = value;
			++it;
		}
	}

	void Swap(vector<T>& v)
	{
		swap(_start, v._start);
		swap(_finish, v._finish);
		swap(_endofstorage, v._endofstorage);
	}


	void PushBack(const T& x)
	{
		insert(end(), x);
	}

	void popback()
	{
		erase(--end());
	}

	iterator insert(iterator pos, const T& x)
	{
		assert(pos <= _finish);

		if (_finish == _endofstorage)
		{
			size_t Size = size();
			size_t newcapacity = capacity() == 0 ? 1 : capacity() * 2;
			Reserve(newcapacity);
			pos = _start + Size;
		}

		iterator end = _finish - 1;
		while (end >= pos)
		{
			*(end + 1) = *end;
			--end;
		}

		*pos = x;
		++_finish;
		return pos;
	}

	iterator erase(iterator pos)
	{
		iterator begin = pos + 1;
		while (begin != _finish)
		{
			*(brgin + 1) = *begin;
			++begin;
		}
		--_finish;
		return pos;
	}

	T& operator[](size_t pos)
	{
		return _start[pos];
	}



private:
	iterator _start;//ָ�����ݿ�Ŀ�ʼ
	iterator _finish;//ָ����Ч���ݵ�β
	iterator _endofstorage;//ָ��洢������β
};

int main()
{
	vector<int> v;
	v.PushBack(1);
	v.PushBack(2);
	v.PushBack(3);
	v.PushBack(4);
	v.PushBack(5);

	//for (auto e : v)
	//{
	//	cout << e << " ";
	//}
	//cout<<endl;

	vector<int>::iterator it = v.begin();
	while (it != v.end())
	{
		cout << *it << " ";
	}
	cout <<endl;

	system("pause");
	return 0;
}
