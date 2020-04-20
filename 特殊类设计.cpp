#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;


//���һ���ֻ࣬���ڶ��ϴ���
class HeapOnly
{
public:
	static HeapOnly* CreateObject()
	{
		return new HeapOnly;
	}
private:
	HeapOnly(){}
	HeapOnly(HeapOnly& ho){};;//�������캯��˽�У���Ϊ�˷�ֹ���ÿ�����ջ�����ɶ���
};

//���һ���ֻ࣬����ջ�ϴ���;;����Ҫ�����캯��˽�л���˽��operator new

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


//���һ���࣬���ܱ�����
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

//���һ���࣬���ܱ��̳�  ˽�л����캯������ʹ��final�ؼ���
class NonInherit
{
private:
	NonInherit(){}
};

class A :public NonInherit
{

};


//���һ��������ʵ����һ������

//����---�ڳ��������Ǿ�ʵ����һ��Ψһ�Ķ���
class SingLeton
{
public:
	static SingLeton* GetInstance()
	{
		return &M_singleton;
	}

private:
	SingLeton(){}

	//������
	SingLeton& operator=(const SingLeton& sl) = delete;
	SingLeton(const SingLeton& sl) = delete;
	static SingLeton M_singleton;
};

SingLeton SingLeton::M_singleton;//�ڳ������ǰ��ɶ����ʼ��

//����
#include<mutex>
class SingLeton2
{public:
	static SingLeton2* GetInstance()
	{
		if (nullptr == M_SingLeton2)//˫���жϣ���Ч�ı�֤�̰߳�ȫ
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

	//ʵ��һ����Ƕ���������
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


	//��ֹ����
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
