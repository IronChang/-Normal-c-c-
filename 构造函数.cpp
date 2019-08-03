#include<iostream>
#include<malloc.h>
#include<assert.h>
#include<string.h>
using namespace std;

/*
构造函数：
特点：函数名与类名相同、无返回值、自动调用、可以重载 
如果在程序中没有显示的定义，则编译器默认创建一个无参无作为的默认构造函数 
无参构造函数和全缺省的构造函数都成为默认构造函数和没写构造函数时编译器自动生成的
并且默认构造函数只能有一个。 
*/
/* 
class Time
{
	public:
		Time()
		{
			cout<<"Time()"<<endl;
		}
	private:
		int _hour;
};

class Date
{
	public:
		Date()//默认构造函数 
		{
			cout<<"Date()"<<endl;			
		}
		Date() = default;
		Date(int year,int month,int day)//构造函数的重载 
		{
			_year = year;
			_month = month;
			_day = day;
			cout<<"Date(int year,int month,int day)"<<endl;
		 } 
		 
		 Date(int year = 2000,int month = 1,int day = 1)//全缺省构造函数可以看成默认构造函数 
		 {
		 	_year = year;
			_month = month;
			_day = day;
			cout<<"Date(int year = 2000,int month = 1,int day = 1)"<<endl;
		 }
		 
		 Date(const Date& d)//默认拷贝构造函数 ，浅拷贝  拷贝的资源共用一份地址	
		 {
		 	this->_year = d._year;
		 	this->_month = d._month;
		 	this->_day = d._day;
		 }
		  ~Date()
		  {
		  	
		  }
		 void print()
		 {
		 	cout<<_year<<"-"<<_month<<"-"<<_day<<endl;
		 }
		 
	private:
		int _year = 1900;
		int _month = 1;
		int _day = 1;
		Time _t;
};
*/

/*析构函数 ：完成资源清理工作 
特点：类名前面 + ‘~ ’、无参数无返回值、在对象生命周期结束时自动调用
一个类只能有一个析构函数 
 如果不声明操作系统回自动生成默认的析构函数，
 析构函数对自身内置类型不进行操作 ，对自定义类型成员调用其析构函数
 什么时候一定要自己写析构函数：如果类中有资源管理那么就要一定自己写析构函数不然会在成内存泄漏
 操作系统一般严禁统同一块内存释放两次，，可能影响其他程序的运行 
*/

typedef int DataType;

/*class SeqList
{
	public:
		SeqList(int capacity)
		{
			int * newnode = (DataType*)malloc(capacity*sizeof(DataType));
			_a = newnode;
			free(newnode);
			assert(_a);
			_size = 0;
			_capacity = capacity; 
			cout<<"SeqList(int capacity)"<<endl;
		}
		~SeqList()
		{
			if(_a)
			{
				free(_a);
				_a = NULL;
				_capacity = 0;
				_size = 0; 
			}
			cout<<"~SeqList()"<<endl;
		}
	  
	private:
		int* _a;
		size_t _size;
		size_t _capacity;
 }; */
 
 class String
 {
 	public:
 		String(const char* str)
		 {
		 	_str = (char*)malloc(strlen(str)+1);
		 	strcpy(_str,str);
		  } 
		  ~String()
		  {
		  	cout<<"~String()"<<endl;
		  	free(_str);	
		  }
 	private:
 		char* _str;
   	
 };
 
class Person
{
private:
 
String _name;
 
int _age;
};
 
int main()
{
	Person p;
	//SeqList(10);
	//Date d2;
	//Date d1(d2);
	//d1.print();
	//d2.print();
	
	return 0;
 } 
