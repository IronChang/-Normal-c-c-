#include<iostream>
#include<malloc.h>
#include<assert.h>
#include<string.h>
using namespace std;

/*
���캯����
�ص㣺��������������ͬ���޷���ֵ���Զ����á��������� 
����ڳ�����û����ʾ�Ķ��壬�������Ĭ�ϴ���һ���޲�����Ϊ��Ĭ�Ϲ��캯�� 
�޲ι��캯����ȫȱʡ�Ĺ��캯������ΪĬ�Ϲ��캯����ûд���캯��ʱ�������Զ����ɵ�
����Ĭ�Ϲ��캯��ֻ����һ���� 
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
		Date()//Ĭ�Ϲ��캯�� 
		{
			cout<<"Date()"<<endl;			
		}
		Date() = default;
		Date(int year,int month,int day)//���캯�������� 
		{
			_year = year;
			_month = month;
			_day = day;
			cout<<"Date(int year,int month,int day)"<<endl;
		 } 
		 
		 Date(int year = 2000,int month = 1,int day = 1)//ȫȱʡ���캯�����Կ���Ĭ�Ϲ��캯�� 
		 {
		 	_year = year;
			_month = month;
			_day = day;
			cout<<"Date(int year = 2000,int month = 1,int day = 1)"<<endl;
		 }
		 
		 Date(const Date& d)//Ĭ�Ͽ������캯�� ��ǳ����  ��������Դ����һ�ݵ�ַ	
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

/*�������� �������Դ������ 
�ص㣺����ǰ�� + ��~ �����޲����޷���ֵ���ڶ����������ڽ���ʱ�Զ�����
һ����ֻ����һ���������� 
 �������������ϵͳ���Զ�����Ĭ�ϵ�����������
 ���������������������Ͳ����в��� �����Զ������ͳ�Ա��������������
 ʲôʱ��һ��Ҫ�Լ�д���������������������Դ������ô��Ҫһ���Լ�д����������Ȼ���ڳ��ڴ�й©
 ����ϵͳһ���Ͻ�ͳͬһ���ڴ��ͷ����Σ�������Ӱ��������������� 
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
