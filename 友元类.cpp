//��Ԫ�� 
#include<iostream>
#include<malloc.h>
using namespace std;

class Date;
class Time
{
	friend class Date;
public:
	Time(int hour = 1, int minute = 1, int second = 1)
		:_hour(hour)
		, _minute(minute)
		, _second(second)
	{}
private:
	int _hour;
	int _minute;
	int _second;
};

class Date
{
public:
	Date(int year = 1900, int month = 1, int day = 1)
		:_year(year)
		, _month(month)
		, _day(day)
	{}

	void SET(int hour, int minute, int second)
	{

		_t._hour = hour;
		_t._minute = minute;
		_t._second = second;
	}
private:
	int _year;
	int _month;
	int _day;
	Time _t;
};

//void test()
//{
	//��̬����һ��int���͵Ŀռ�
//	int* ptr1 = new int ;
	
	//��̬����һ��int���͵Ŀռ䲢�ҳ�ʼ��wΪ11
//	int* ptr2 = new int(11);
	
	//��̬����10��int���͵Ŀռ�
//	int* ptr3 = new int[3];
	
//	delete ptr1;
//	delete ptr2;
//	delete[] ptr3; 
//}

class test
{
	public:
		test()
		:_date(0)
		{
			cout<<"test():"<<this<<endl;
		}
		~test()
		{
			cout<<"~test():"<<this<<endl;
		}
	private:
		int _date;
};

void test2()
{
	
// ���뵥��Test���͵Ŀռ�
 
test* p1 = (test*)malloc(sizeof(test));
 
free(p1);
 
 
// ����10��Test���͵Ŀռ�
 
test* p2 = (test*)malloc(sizeof(test) * 10);
 
free(p2);

}

void test3()
{
 
// ���뵥��Test���͵Ķ���
 
test* p1 = new test;
 
delete p1;
 
 
// ����10��Test���͵Ķ���
 
test* p2 = new test[10];
 
delete[] p2;
}

int main()
{
    //Date d;
    //d.SET(2, 2, 2);

	test2();
	test3();
	 
	system("pause");
	return 0;
}
