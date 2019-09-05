/*
初始化链表初始化 
*/ 
#include<iostream>
#include<malloc.h>
using namespace std;

class Time
{
	public:
		Time(int hour = 0):_hour(hour)
		{
			cout<<"Time()"<<endl; 
			
		}
	private:
		int _hour;
};

class Date1
{
	public:
		Date1(int day)//不是默认构造函数 
		{
		}
	private:
		int _day;
		Time _t;//对于自定义类型，调用其默认构造函数 
}; 

class Array
{
	public:
		Array(int size):_size(size),_array((int*)malloc(sizeof(int)*_size))
        {
		}
	private:
		int _size;
		int *_array;		
}; 

class Date2
{
	public:
		explicit Date2(int year):_year(year)
		{
		}
	
	private:
		int _year;
		int _month;
		int _day;
};

/*
Static成员 
*/

class A1
{
	public:
		A1()//构造函数 
		{ ++_scount;
		}
		
		A1(const A1& t)//拷贝构造函数 
		{ ++_scount;
		}
		
		void Display()
		{
			GetACount();//非静态成员函数可以调用静态成员函数		
		}
		 
		static int GetACount()//静态成员函数 
		{  
		   //Display();
		   //静态成员函数不能调用非静态成员函数 
		   //因为静态成员函数没有隐藏的this指针 
		   return _scount;
	    } 
	private:
	static int _scount; //静态成员变量 
	
}; 

int A1::_scount = 0;//静态成员变量一定要在类外进行初始化 

int test()
{
	cout<<A1::GetACount()<<endl;
	A1 a1, a2;//调用两次构造函数 
	A1 a3(a1);//调用一次拷贝构造函数 
	cout<<A1::GetACount()<<endl;
}

/*
c++11的成员初始化
c++11支持非静态成员变量在声明时，直接初始化。 
*/

class B
{
	public:
		B(int b = 0):_b(b)
		{
		}

	    int _b;//我必须定义成共有的，防止访问越界 
}; 

class A2
{
	public:
		void print()
		{
			cout<<a<<endl;
			cout<<b._b<<endl;
			cout<<p<<endl;
		}
	private:
		int a = 10;
		B b = 20;
		int* p = (int*)malloc(4);
		static int n;
};

int A2::n = 10;//静态成员变量必须在类外进行初始化 

/*
友元：友元函数和友元类
 
 
*/

int main()
{
	//Date1 d1(1);
	//Array a(1);
	//Date2 d2(2018);
	//用一个整型变量给日期类型对象复制
	//实际上，编译器先用2019构造一个无名对象，
	//最后用对象给d2进行赋值。 
	//d2 = 2019;//调用：构造+拷贝 
	//test();
	A2 a;
	a.print();	
	return 0;
}
