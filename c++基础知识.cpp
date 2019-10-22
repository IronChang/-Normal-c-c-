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
//		int& ra = a;//定义了引用
//
//		printf("%p\n", &a);
//		printf("%p\n", &ra);
//
//	}
//private:
//	int _year;//年
//	int _month;//月
//	int _day;//日
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
//	//int& ra;  //语句会报错，没有初始化
//	//体现一个变量可以有多个引用
//	int& ra = a;
//	int& rra = a;
//	const int b = 10;
//	//int& rb = b;//编译时会报错，因为b为常量
//	const int& rb = b;
//	//const double& rb = b; //会报错类型不符合
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
//	cout << "Add(1, 2) is :" << ret << endl; //输出   
//	system("pause");
//	return 0;
//}

struct A
{
	int a[10000];
};

A a;

A test1()//传值做返回值
{
	return a;
}

void test2(A a)//传值作为参数
{
}

A& test3()//传引用作为返回值
{
	return a;
}

void test4(A& a)//传引用作为参数
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
	cout << "传值作为返回值test1-time:" << end1 - begin1 << endl;
	cout << "传引用作为返回值test3-time:" << end2 - begin2 << endl;
	cout << "传值作为参数test2-time:" << end3 - begin3 << endl;
	cout << "传引用作为参数test4-time:" << end4 - begin4 << endl;
}

int main()
{
	test();
	system("pause");
	return 0;
}