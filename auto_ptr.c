#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

//	C++98---auto_ptr--管理权转移
template<class T>
class Auto_ptr
{
public:
	Auto_ptr(T* ptr) 
		:_ptr(ptr)
	{
		cout << "Auto_ptr" << endl;
	}

	Auto_ptr(Auto_ptr<T>& ap)
		:_ptr(ap._ptr)
	{
		cout << "Auto_ptr(Auto_ptr<T>& ap)" << endl;
		ap._ptr = nullptr;
	}
	
	Auto_ptr<T>& operator=(Auto_ptr<T>& ap)
	{
		cout << "Auto_ptr<T>& operator=(Auto_ptr<T>& ap)" << endl;
		if (_ptr)
			delete _ptr;

		if (this != &ap)
		{
			_ptr = ap._ptr;
			ap._ptr = nullptr;
		}
		return *this;
	}
	~Auto_ptr()
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
	}
private:
	T* _ptr;
};

int main()
{
	Auto_ptr<int> ap(new int);
	Auto_ptr<int> ap2(ap);
	Auto_ptr<int> ap3 = new int;
	Auto_ptr<int> ap4 = ap3;
	ap = ap4;


	system("pause");
	return 0;
}
