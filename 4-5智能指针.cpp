#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
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
		shared_ptr(T* ptr = nullptr)
			:_ptr(ptr)
			, _pCount(new int(1))
			, _pMutex(new mutex)
		{}

		// copy(sp1)
		shared_ptr(const shared_ptr<T>& sp)
			:_ptr(sp._ptr)
			, _pCount(sp._pCount)
			, _pMutex(sp._pMutex)
		{
			AddRef();
		}
		
		// sp1 = sp4
		// sp3 = sp4; ����sp3��sp4���ǹ�����ͬһ����Դ��
		shared_ptr<T>& operator=(const shared_ptr<T>& sp)
		{
			//if (this != &sp && _ptr != sp._ptr)
			if (_ptr != sp._ptr)
			{
				// ���ͷ�ԭ������Դ
				ReleaseRef();
				_ptr = sp._ptr;
				_pCount = sp._pCount;
				_pMutex = sp._pMutex;
				AddRef();
			}

			return *this;
		}

		int GetRefCount()
		{
			return *_pCount;
		}

		// ���ü������̰߳�ȫ����
		// �����ü���
		void AddRef()
		{
			_pMutex->lock();
			++(*_pCount);
			_pMutex->unlock();
		}

		// �����ü���
		void ReleaseRef()
		{
			bool deleteflag = false;
			_pMutex->lock();
			if (--(*_pCount) == 0)
			{
				delete _pCount;
				delete _ptr;
				//cout << "delete:" << _ptr << endl;
				deleteflag = true;
			}
			_pMutex->unlock();

			if (deleteflag == true)
			{
				delete _pMutex;
			}
		}

		~shared_ptr()
		{
			ReleaseRef();
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

		T* GetPtr() const
		{
			return _ptr;
		}
	private:
		T* _ptr;
		int* _pCount; // ���ü���
		mutex* _pMutex;
	};

	//int*
	//Date*
	//int[]
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

	void test_shared_ptr_threads()
	{
		shared_ptr<int> sp(new int(0));
		vector<thread> vthreads;
		const size_t thread_size = 4;
		for (size_t i = 0; i < thread_size; ++i)
		{
			vthreads.push_back(thread([&]()
			{
				for (size_t i = 0; i < 10000; ++i)
				{
					shared_ptr<int> copy(sp);
					++(*sp);
				}
			}));
		}

		for (size_t i = 0; i < thread_size; ++i)
		{
			vthreads[i].join();
		}

		cout << ++(*sp) << endl;
		cout << sp.GetRefCount() << endl;
	}

	// ���Ĳ�����ר�Ž��shared_ptr��ѭ����������
	template<class T>
	class weak_ptr
	{
	public:
		weak_ptr()
			:_ptr(nullptr)
		{}

		weak_ptr(const shared_ptr<T>& sp)
			:_ptr(sp.GetPtr())
		{}

		weak_ptr<T>& operator=(const shared_ptr<T>& sp)
		{
			_ptr = sp.GetPtr();
			return *this;
		}

		~weak_ptr()
		{}

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

	// �ض��ĳ����²Ż����ѭ������
	struct ListNode
	{
		//shared_ptr<ListNode> _next;
		//shared_ptr<ListNode> _prev;
		weak_ptr<ListNode> _next;
		weak_ptr<ListNode> _prev;
		int val;

		~ListNode()
		{
			cout << "~ListNode()" << endl;
		}
	};


	void test_cycle_ref()
	{
		shared_ptr<ListNode> node1(new ListNode);
		shared_ptr<ListNode> node2(new ListNode);

		// ѭ������
		node1->_next = node2;
		node2->_prev = node1;

		cout << node1.GetRefCount() << endl;
		cout << node2.GetRefCount() << endl;
	}
}

#include <memory>

class A
{
public:
	~A()
	{
		cout << "~A()" << endl;
	}

	int _a1;
	int _a2;
};

template<class T>
struct DeleteArray
{
	void operator()(T* ptr)
	{
		delete[] ptr;
	}
};

//int main()
//{
//	//bit::test_auto_ptr2();
//	//bit::test_unique_ptr();
//	//bit::test_shared_ptr();
//	//bit::test_shared_ptr_threads();
//	//bit::test_cycle_ref();
//
//	// ����ɾ���� ->�º��� lamber  �˽�һ�� �����к��ٿ���
//	std::shared_ptr<A> sp1(new A[10], DeleteArray<A>());
//	std::shared_ptr<A> sp2(new A[10], [](A* ptr){delete[] ptr; });
//
//	std::shared_ptr<A> sp3((A*)malloc(sizeof(A)), [](A* ptr){free(ptr); });
//	std::shared_ptr<FILE> sp4(fopen("test.txt", "w"), [](FILE* ptr){fclose(ptr); });
//
//	return 0;
//}

// �쳣��ȫ
//new / malloc / fopen / lock
//
//throw exception()
//
//delete/ free/fclose / unlock

// ���RAII������
template<class Lock>
class LockGuard
{
public:
	LockGuard(Lock& lock)
		:_lock(lock)
	{
		_lock.lock();
	}

	~LockGuard()
	{
		_lock.unlock();
	}

	LockGuard(const LockGuard&) = delete;
private:
	Lock& _lock;  //ע�������Ǻ���ʵ��
};


int main()
{
	int n = 0;
	mutex mtx;
	vector<thread> vthreads;
	const size_t thread_size = 4;
	for (size_t i = 0; i < thread_size; ++i)
	{
		vthreads.push_back(thread([&n, &mtx]()
		{
			//mtx.lock();
			//LockGuard<mutex> lg(mtx);
			//lock_guard<mutex> lg(mtx);
			unique_lock<mutex> lg(mtx);
			for (size_t i = 0; i < 100000; ++i)
			{
				++n;
			}
			// func()  ��������������ܻ����쳣����ô����ͻ�����
			//mtx.unlock();
		}));
	}

	for (size_t i = 0; i < thread_size; ++i)
	{
		vthreads[i].join();
	}

	cout << n << endl;

	return 0;
}