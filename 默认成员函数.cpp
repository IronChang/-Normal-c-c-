#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
//
//class A
//{
//public:
//	void TestFunc(int a = 10)
//	{
//		cout << "void TestFunc(int)" << endl;
//	}
//	//void TestFunc(int a)
//	//{
//	//	cout << "void TestFunc(int)" << endl;
//	//}
//};


int add(int a,int b)
{
	int c = a + b;
	return c;
}

void Swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}


#include <time.h>
struct A
{
	int a[10000];
};

//void TestFunc1(A a)
//{}
//void TestFunc2(A& a)
//{}
//void TestRefAndValue()
//{
//	A a;
//	// ��ֵ��Ϊ��������
//	size_t begin1 = clock();
//	for (size_t i = 0; i < 10000; ++i)
//		TestFunc1(a);
//	size_t end1 = clock();
//	// ��������Ϊ��������
//	size_t begin2 = clock();
//	for (size_t i = 0; i < 10000; ++i)
//		TestFunc2(a);
//	size_t end2 = clock();
//	// �ֱ���������������н������ʱ��
//	cout << "TestFunc1(int*)-time:" << end1 - begin1 << endl;
//	cout << "TestFunc2(int&)-time:" << end2 - begin2 << endl;
//}

//A a;
//A TestFunc1()
//{
//	return a;
//} A
//& TestFunc2()
//{
//	return a;
//}
//void TestReturnByRefOrValue()
//{
//	// ��ֵ��Ϊ�����ķ���ֵ����
//	size_t begin1 = clock();
//	for (size_t i = 0; i < 100000; ++i)
//		TestFunc1();
//	size_t end1 = clock();
//	// ��������Ϊ�����ķ���ֵ����
//	size_t begin2 = clock();
//	for (size_t i = 0; i < 100000; ++i)
//		TestFunc2();
//	size_t end2 = clock();
//	// �������������������֮���ʱ��
//	cout << "TestFunc1 time:" << end1 - begin1 << endl;
//	cout << "TestFunc2 time:" << end2 - begin2 << endl;
//}

void test()
{
	int array[] = { 1, 2, 3, 4, 5 };
	for (auto& e : array)
	{
		e *= 2;
	}

	for (auto e : array)
	{
		cout << e << " ";
	}
}


class Time
{
public:
	Time()
	{
		cout << "Time()" << endl;
		_hour = 0;
		_minute = 0;
		_second = 0;
	}
private:
	int _hour;
	int _minute;
	int _second;
};
class Date
{
public:
	Date(){}
private:
	// ��������(��������)
	int _year;
	int _month;
	int _day;
	Time _t;
};

class Date
{
public:
	void testfunc1()//��const��Ա����
	{
		cout << "testfunc1"<<endl;
	}

	void testfunc2() const//const��Ա����
	{
		cout << "testfunc2 const" << endl;
	}

	void testfunc3()//��const��Ա����
	{
		testfunc1();// ��const��Ա�����ڵ��������ķ�const��Ա����
		testfunc2(); //��const��Ա�����ڵ���������const��Ա����
	}

	void testfunc4() const//const��Ա����
	{
		testfunc1();//.const��Ա�����ڵ��������ķ�const��Ա����
		testfunc2();//.const��Ա�����ڵ���������const��Ա����
	}
private:
	int _year;
};
int main()
{
	Date d1;//��const����
	d1.testfunc1();//��const������÷�const��Ա����
	d1.testfunc2();//��const�������const��Ա����

	const Date d2;//const����
	d2.testfunc1();//const������÷�const��Ա����---�������
	d2.testfunc2();//const�������const��Ա����
}
int main()
{
	
	//int& ret = Add(1, 2);
	//Add(3, 4);
	//cout << "Add(1, 2) is :" << ret << endl;
	//
	//for (int i = 0; i < 10; ++i)
	//{
	//	TestReturnByRefOrValue();
	//}

	//int ret = 0;
	//ret = add(1, 2);

	//int a = 10;
	//auto b = a;
	//auto c = 'a';
	//
	//cout << typeid(a).name() << endl;
	//cout << typeid(b).name() << endl;
	//cout << typeid(c).name() << endl;

	//test();

	//cout << sizeof(nullptr) << endl;
	//cout << sizeof((void*)0) << endl;
	Date d;



	system("pause");
	return 0;
}
