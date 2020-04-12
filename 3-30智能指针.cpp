#include <iostream>
using namespace std;

//void Test()
//{
//	int* p1 = new int[10]; // ����Ҳ�����ܻ����쳣
//	int* p2 = new int[20];
//	int* p3 = new int[30];
//	try
//	{
//		// ...
//		func(); // ���ܻ����쳣
//	}
//	catch (...)
//	{
//		// ...
//		delete[] p1;
//		delete[] p2;
//		delete[] p3;
//
//		throw;
//	}
//
//	delete[] p1;
//	delete[] p2;
//	delete[] p3;
//}
//
//int main()
//{
//	//Test();
//
//	return 0;
//}

// ����˼�����RAII
template<class T>
class SmartPtr
{
public:
	SmartPtr(T* ptr)
		:_ptr(ptr)
	{}

	~SmartPtr()
	{
		cout <<"delete[]:" <<_ptr << endl;
		delete[] _ptr;
	}
private:
	T* _ptr;
};

//void Test()
//{
//	//int* p1 = new int;
//	//SmartPtr<int> sp1(p1);
//	SmartPtr<int> sp1(new int);
//
//	// ...
//	throw out_of_range("Խ��");
//
//	//delete p1;
//}

//void Test()
//{
//	SmartPtr<int> sp1(new int[10]);
//	SmartPtr<int> sp2(new int[20]);
//	SmartPtr<int> sp3(new int[30]);
//
//	// ...
//	// func();
//	throw out_of_range("Խ��");
//}
//
//int main()
//{
//	try
//	{
//		Test();
//	}
//	catch (exception& e)
//	{
//		cout << e.what() << endl;
//	}
//	catch (...)
//	{
//		cout << "δ֪�쳣" << endl;
//	}
//
//	return 0;
//}

// ����ָ��İ汾����չ��ʷ��
// C++98 auto_ptr

// 1.RAII������Դ
// 2.�ܹ���ָ��һ��ȥʹ��
namespace bit
{
	template<class T>
	class auto_ptr
	{
	public:
		auto_ptr(T* ptr)
			:_ptr(ptr)
		{}

		// copy(ap1)
		auto_ptr(auto_ptr<T>& ap)
			: _ptr(ap._ptr)
		{
			ap._ptr = nullptr;
		}

		// ap1 = ap2;
		auto_ptr<T>& operator=(auto_ptr<T>& ap)
		{
			if (this != &ap)
			{
				if (_ptr)
					delete _ptr;

				_ptr = ap._ptr;
				ap._ptr = nullptr;
			}

			return *this;
		}

		~auto_ptr()
		{
			if (_ptr)
			{
				cout << "delete:" << _ptr << endl;
				delete _ptr;
			}
		}

		T& operator*()
		{
			return *_ptr;
		}

		T* operator->()
		{
			return _ptr;
		}
	private:
		T* _ptr;
	};

	struct A
	{
		int _a1;
		int _a2;
	};

	void test_auto_ptr1()
	{
		int* p1 = new int;
		*p1 = 10;

		auto_ptr<int> ap1(new int);
		*ap1 = 10;

		A* pa = new A;
		(*pa)._a1 = 10;
		pa->_a1 = 20;

		auto_ptr<A> apa(new A);
		(*apa)._a1 = 10;
		//apa->->_a2 = 20;  ����Ӧ����������������Ϊ���﷨�ɶ��ԣ�ʡ����һ����ͷ
		apa->_a2 = 20;
	}

	void test_auto_ptr2()
	{
		auto_ptr<int> ap1(new int);
		auto_ptr<int> copy(ap1);  // ap1����������һ��copy���󣬹���Ȩת��copy
		auto_ptr<int> copy1 = copy; // ��������copy1������Ȩת��copy1 

		// �����ķ�ʽ��������ʲô�أ�
		*ap1 = 10;  // ���գ����ʻ����
	}


	// C++11  �򵥴ֱ���ֱ�Ӳ��ÿ���
	template<class T>
	class unique_ptr
	{
	public:
		unique_ptr(T* ptr)
			:_ptr(ptr)
		{}

		~unique_ptr()
		{
			if (_ptr)
			{
				cout << "delete:" << _ptr << endl;
				delete _ptr;
			}
		}

		T& operator*()
		{
			return *_ptr;
		}

		T* operator->()
		{
			return _ptr;
		}

		// �������ַ�ʽ����ѡһ�ֶ�����
		// C++11 ������
		//unique_ptr(const unique_ptr<T>&) = delete;
		//unique_ptr<T>& operator=(const unique_ptr<T>&) = delete;
	private:
		// C++98 �����󿽱�ʵ�ַ�ʽ��ֻ������ʵ��+������˽��
		unique_ptr(const unique_ptr<T>&);
		unique_ptr<T>& operator=(const unique_ptr<T>&);
	private:
		T* _ptr;
	};

	void test_unique_ptr()
	{
		unique_ptr<int> up1(new int);
		//unique_ptr<int> copy(up1);
	}

	// �����˽���Ժ󣬱���ʵ����Ҳ������
	//template<class T>
	//unique_ptr<T>::unique_ptr(const unique_ptr<T>& ap)
	//	:_ptr(ap._ptr)
	//{}

	// C++11 ֧�ֿ�����shared_ptr
	template<class T>
	class shared_ptr
	{
	public:
		// RAII
		shared_ptr(T* ptr)
			:_ptr(ptr)
			, _pCount(new int(1))
		{}

		// copy(sp1)
		shared_ptr(const shared_ptr<T>& sp)
			:_ptr(sp._ptr)
			, _pCount(sp._pCount)
		{
			++(*_pCount);
		}
		
		// sp1 = sp4
		// sp3 = sp4; ����sp3��sp4���ǹ�����ͬһ����Դ��
		shared_ptr<T>& operator=(const shared_ptr<T>& sp)
		{
			//if (this != &sp && _ptr != sp._ptr)
			if (_ptr != sp._ptr)
			{
				// ���ͷ�ԭ������Դ
				if (--(*_pCount) == 0)
				{
					delete _pCount;
					if (_ptr)
						delete _ptr;
				}
				_ptr = sp._ptr;
				_pCount = sp._pCount;
				++(*_pCount);
			}

			return *this;
		}

		~shared_ptr()
		{
			if (--(*_pCount) == 0)
			{
				delete _pCount;

				if (_ptr)
				{
					cout << "delete:" << _ptr << endl;
					delete _ptr;
				}	
			}
		}

		// ��ָ��һ��ʹ��
		T& operator*()
		{
			return *_ptr;
		}

		T* operator->()
		{
			return _ptr;
		}
	private:
		T* _ptr;
		int* _pCount; // ���ü���
	};

	void test_shared_ptr()
	{
		shared_ptr<int> sp1(new int);
		shared_ptr<int> copy1(sp1);
		shared_ptr<int> copy2(copy1);

		shared_ptr<int> sp3(new int);
		shared_ptr<int> sp4(sp3);

		sp1 = sp4;
		sp3 = sp4;
	}
}


int main()
{
	//bit::test_auto_ptr2();
	//bit::test_unique_ptr();
	bit::test_shared_ptr();

	return 0;
}
