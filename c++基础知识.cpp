#include<iostream>
#include<windows.h>
#include<time.h>
using namespace std;
//class A
//{
//	public:
//		void PrintA() 
//		{
//			cout<<_a<<endl;
//		}
//	private:
//		char _a;
//};
//
////int main()
////{
////	cout<<sizeof(A)<<endl;
////	system("pause");
////}
//
//
//class Date
//{
//public:
//	void Display()
//	{
//		cout << _year << "-" << _month << "-" << _day << endl;
//	}
//
//	void setDate(int year = 1990,int month = 1,int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//	void Print()
//	{
//		int a = 10;
//		int& ra = a;//����������
//
//		printf("%p\n", &a);
//		printf("%p\n", &ra);
//
//	}
//private:
//	int _year;//��
//	int _month;//��
//	int _day;//��
//};
//
//int main()
//{
//	Date* p = NULL;
//	p->Print();
//	//p->Display();
//	system("pause");
//	return 0;
//}
//
//
//void test()
//{
//	int a = 10;
//	//int& ra;  //���ᱨ��û�г�ʼ��
//	//����һ�����������ж������
//	int& ra = a;
//	int& rra = a;
//	const int b = 10;
//	//int& rb = b;//����ʱ�ᱨ����ΪbΪ����
//	const int& rb = b;
//	//const double& rb = b; //�ᱨ�����Ͳ�����
//}

//int& Add(int a, int b)
//{
//	int c = a + b;
//	return c;
//}
//int main()
//{
//	int& ret = Add(1, 2);
//	Add(3, 4);
//	cout << "Add(1, 2) is :" << ret << endl; //���   
//	system("pause");
//	return 0;
//}

struct A
{
	int a[10000];
};

A a;

A test1()//��ֵ������ֵ
{
	return a;
}

void test2(A a)//��ֵ��Ϊ����
{
}

A& test3()//��������Ϊ����ֵ
{
	return a;
}

void test4(A& a)//��������Ϊ����
{
}

void test()
{
	size_t begin1 = clock();
	for (size_t i = 0; i < 10000; ++i)
	{
		test1();
	}
	size_t end1 = clock();

	size_t begin2 = clock();
	for (size_t i = 0; i < 10000; ++i)
	{
		test3();
	}
	size_t end2 = clock();

	size_t begin3 = clock();
	for (size_t i = 0; i < 100000; ++i)
	{
		test2(a);
	}
	size_t end3 = clock();

	size_t begin4 = clock();
	for (size_t i = 0; i < 100000; ++i)
	{
		test4(a);
	}
	size_t end4 = clock();
	cout << "��ֵ��Ϊ����ֵtest1-time:" << end1 - begin1 << endl;
	cout << "��������Ϊ����ֵtest3-time:" << end2 - begin2 << endl;
	cout << "��ֵ��Ϊ����test2-time:" << end3 - begin3 << endl;
	cout << "��������Ϊ����test4-time:" << end4 - begin4 << endl;
}

int main()
{
	test();
	system("pause");
	return 0;
}