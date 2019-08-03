#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;


//构造函数用来初始化对象，而不是创建对象
//特征：无返回值、函数名与类名相同、自动调用、可以重载

/*
//class Data
//{
////如果没有显示的定义，则编译器回默认生成一个无参构造函数不做任何操作
//public:
//	Data(int year = 2001, int month = 3, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	void show()
//	{
//		cout << _year << "-" << _month << "-" << _day << endl;
//	}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//};

//class  A
//{
//public:
//	void show()
//	{
//		cout << "show()" << endl;
//	}
//
//	void print()
//	{
//		cout << _a << endl;
//	}
//
//private:
//	int _a;
//};

//一个类中可以有多个构造函数，但是不能手动去调用而是实例化是根据参数不同自动调用

//默认构造函数堆内置类型不作处理，对自定义类型调用其默认构造函数

class Time
{
public:
	Time()
	{
		cout << "Time()" << endl;
		_hour = 12;
	}
private:
	int _hour;
};

class Date
{
public:
	//1、无参构造函数
	//Date()
	//{

	//}
	//2、带参构造函数
	Date() = default;//告诉编译器自动生成一个无参默认构造函数，后面与其同名的可以看作是其重载函数然后再根据参数不同进行调用

	Date(int year, int month, int day)
	{
		_year = year;
		_month = month;
		_day = day;
	}
	//3、即可带参数也可不带参数（但是与无参构造函数冲突会造成二义性）
	//Date(int year = 1900, int month = 1, int day = 1)
	//{
	//	_year = year;
	//	_month = month;
	//	_day = day;
	//}
	void print()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}
private:
	//在这里这只是一个生命，并没有开空间进行定义,只有在实例化时才会开开空间
	int _year = 1990;
	int _month = 1;
	int _day = 1;
	Time t;
};

int main()
{

	//实例化时有参数要带括号，没有参数不用带括号
	Date d1(2019,8,3);
	d1.print();
	//d1.show();


	//A aa;
	//A* p= nullptr;

	////p->print();
	//p->show();

	system("pause");
	return 0;
}
*/


//析构函数：完成资源清理工作、一个类中只能有一个析构函数
//特征：类函数明前加~，无参数无返回值、对象生命周期结束时自动调用


//拷贝构造函数：
//默认构造函数调用对内置类型进行值拷贝，对自定义类型会去调用其拷贝构造函数

class Time
{
public:

	Time()
	{
		cout << "Time()" << endl;

	}

	Time(const Time& d)
	{
		cout << "Time(const Time& d)" << endl;
	}
private:
	int _hour;
};

//class Array
//{
//public:
//	Array(int n = 10)
//	{
//		_a = (int*)malloc(sizeof(int)*n);
//		_n = n;
//	}
//	~Array()
//	{
//		if (_a != nullptr)
//		{
//			free(_a);
//			_a = nullptr;
//			_n = 0;
//		}
//	}
//private:
//	int* _a;
//	int _n;
//};

class Date
{
public:
	Date(int year = 1900, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}
	//如果没有显示的定义，则系统会自动生成一个同类型拷贝构造函数

	//Date(const Date& d)//拷贝构造函数，不是默认拷贝构造函数
	//{
	//	this->_year = d._year;
	//	this->_month = d._month;
	//	this->_day = d._day;
	//}

	void print()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}

private:
	int _year;
	int _month;
	int _day;
	Time _t;
};

int main()
{
	Date d1;
	Date d2(d1);//调用拷贝构造函数，去数理化
	d1.print();
	d2.print();

	cout << sizeof(Date) << endl;

	//Array aa1;
	//Array aa2(aa1);


	system("pause");
	return 0;
}