#include<iostream>
using namespace std;

class A
{
	private:
		static int k;
		int h;
	public:
		class B
		{
			public:
				void foo(const A& a)
				{
					cout<<k<<endl;//�ڲ������ֱ�ӷ����ⲿ���е�static��ö�� 
					cout<<a.h<<endl;//�ڲ������ⲿ�����Ԫ���� 
				}
		};
};

int A::k= 1;

class B
{
public:
 
B() {++_scount;}
 
B(const A& t) {++_scount;}
 
static int GetACount() { return _scount;}
private:
 
static int _scount;
};
int B::_scount = 0;
void TestB()
{
 
cout<<B::GetACount()<<endl;
 
B a1;//, a2;
 
B a3(a1);
 
cout<<B::GetACount()<<endl;
}

int main()
{
	//A::B b;
	//b.foo(A());
	TestB();
	return 0;
 } 
