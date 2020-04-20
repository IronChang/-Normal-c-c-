#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;


//设计一个类，只能在堆上创建
class HeapOnly
{
public:
	static HeapOnly* CreateObject()
	{
		return new HeapOnly;
	}
private:
	HeapOnly(){}
	HeapOnly(HeapOnly& ho){};;//拷贝构造函数私有，是为了防止调用拷贝在栈上生成对象
};

//设计一个类，只能在栈上创建;;主需要将构造函数私有或者私有operator new

class StackOnly
{
	//public:
	//	static StackOnly& CreateObject()
	//	{
	//		return StackOnly();
	//	}
	//private:
	//	StackOnly(){}
public:
	StackOnly()
	{}
private:
	void* operator new(size_t size);
	void operator delete(void* p);
};


//设计一个类，不能被拷贝
class CopyBan
{
public:
	CopyBan(){}
private:
	//CopyBan(const CopyBan& cb)
	//{
	//}

	//CopyBan& operator=(const CopyBan& cb)
	//{
	//}
	CopyBan(const CopyBan& cb) = delete;
	CopyBan& operator=(const CopyBan& cb) = delete;


};

//设计一个类，不能被继承  私有化构造函数或者使用final关键字
class NonInherit
{
private:
	NonInherit(){}
};

class A :public NonInherit
{

};


//设计一个类智能实例化一个对象

//懒汉---在程序启动是就实例化一个唯一的对象
class SingLeton
{
public:
	static SingLeton* GetInstance()
	{
		return &M_singleton;
	}

private:
	SingLeton(){}

	//防拷贝
	SingLeton& operator=(const SingLeton& sl) = delete;
	SingLeton(const SingLeton& sl) = delete;
	static SingLeton M_singleton;
};

SingLeton SingLeton::M_singleton;//在程序入口前完成对象初始化

//饿汉
#include<mutex>
class SingLeton2
{public:
	static SingLeton2* GetInstance()
	{
		if (nullptr == M_SingLeton2)//双重判断，有效的保证线程安全
		{
			M_mtx.lock();
			if (nullptr == M_SingLeton2)
			{
				M_SingLeton2 = new  SingLeton2();
			}
			M_mtx.unlock();
		}
		return M_SingLeton2;
	}

	//实现一个内嵌类回收垃圾
	class CClean
	{
	public:
		~CClean()
		{
			if (SingLeton2::M_SingLeton2)
			{
				cout << "delete:" << SingLeton2::M_SingLeton2 << endl;
				delete SingLeton2::M_SingLeton2;
			}
		}
	};
	static CClean CC;
private:
	SingLeton2(){};


	//防止拷贝
	SingLeton2& operator=(const SingLeton2& sl) = delete;
	SingLeton2(const SingLeton2& sl) = delete;

	static SingLeton2* M_SingLeton2;
	static mutex M_mtx;

};

SingLeton2* SingLeton2::M_SingLeton2 = nullptr;
mutex SingLeton2::M_mtx;
SingLeton2::CClean CC;
int main()
{
	//HeapOnly* ho = HeapOnly::CreateObject();
	////StackOnly so = StackOnly::CreateObject();
	//StackOnly so;
	//CopyBan cb;
	////CopyBan cb2(cb);
	//
	//A a;

	SingLeton2* sl = SingLeton2::GetInstance();
	return 0;
}
