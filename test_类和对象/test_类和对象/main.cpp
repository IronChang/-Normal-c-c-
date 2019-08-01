#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

///类的定义

//struct Person
//{
//public:
//	void showInfo()
//	{
//		cout << _name << "-" << _sex << "-" << _age << endl;
//	}
//public:
//	char* _name;
//	char* _sex;
//	int _age;
//};
//
//int main()
//{
//	Person man;
//	man._name = "tom";
//	man._sex = "男";
//	man._age = 10;
//	man.showInfo();
//	system("pause");
//	return 0;
//}

///this指针

//class Data
//{
//public:
//	void Display()
//	{
//		cout << _year << "-" << _month << "-" << _day << endl;
//	}
//	void SetData(int year, int month, int day)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};

//class A
//{
//public:
//	void PrintA()
//	{
//		cout << _a << endl;
//	}
//	void show()
//	{
//		cout << "show()" << endl;
//	}
//private:
//	int _a = 10;
//};

//int main()
//{
//	//Data d1();
//	//Data d2();
//	//d1.SetData(2018, 5, 1);
//	//d2.SetData(2018, 7, 1);
//	//d1.Display();
//	//d2.Display();
//
//	A* p = nullptr;
//	A aa;
//	aa.PrintA();
//	//p->PrintA();
//	p->show();//在这里不是指针解引用，而是把p指向的内容传给了this
//	system("pause");
//	return 0;
//}


///构造函数 
//成员函数名字与类名相同，创建类对象时由编译器自动调用，在对象的声明周期只能调用一次

//class Date
//{
//
//public:
//	void SetDate(int year, int month, int day)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//	void Display()
//	{
//		cout << _year << "-" << _month << "-" << _day << endl;
//	}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//};

//定义重载两个构造函数会造成二义性
//class Date
//{
//public:
//	// 1.无参构造函数
//	//Date()
//	//{}
//	// 2.带参构造函数
//	//Date(int year, int month, int day)
//	//{
//	//	_year = year;
//	//	_month = month;
//	//	_day = day;
//	//}
//private:
//
//	int _year;
//	int _month;
//	int _day;
//};
//void TestDate()
//{
//
//	Date d1; // 调用无参构造函数
//
//	//Date d2(2015, 1, 1); // 调用带参的构造函数
//
//
//	// 注意：如果通过无参构造函数创建对象时，对象后面不用跟括号，否则就成了函数声明
//
//	// 以下代码的函数：声明了d3函数，该函数无参，返回一个日期类型的对象
//
//	//Date d3();
//}
//class Date
//{
//public:
//
//	Date()
//	{
//
//		_year = 1900;
//
//		_month = 1;
//
//		_day = 1;
//	}
//
//
//	//Date(int year = 1900, int month = 1, int day = 1)
//	//{
//
//	//	_year = year;
//
//	//	_month = month;
//
//	//	_day = day;
//	//}
//private:
//
//	int _year;
//
//	int _month;
//
//	int _day;
//};//class Time//{//public://	Time()//构造函数类的对象初始化//	{//		cout << "Time()" << endl;//		_hour = 0;//		_minute = 0;//		_second = 0;//	}//private://	int _hour;//	int _minute;//	int _second;//};//class Date//{//private://	///基本类型//	int _year;//	int _month;//	int _day;////	//自定义类型//	Time _t;////};
//int main()
//{
//	//Date d1;
//	//Date d2;
//	//d1.SetDate(2018, 5, 1);
//	//d1.Display();
//
//	//d2.SetDate(2018, 7, 1);
//	//d2.Display();
//	//Date d1;
//	Date d;
//	system("pause");
//	return 0;
//}

//析构函数

//class String
//{
//public:
//
//	String(const char* str = "jack")
//	{
//		_str = (char*)malloc(strlen(str) + 1);
//		strcpy(_str, str);
//	}
//
//	~String()
//	{
//		cout << "~String()" << endl;
//		free(_str);
//	}
//private:
//	char* _str;
//};
//class Person
//{
//private:
//	String _name;
//	int	_age;
//};

int main()
{
	Person p;
	system("pause");
	return 0;
}