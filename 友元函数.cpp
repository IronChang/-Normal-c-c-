#include<iostream>
using namespace std;


/*
友元：友元函数和友元类
突破了类的封装，但是也增加了耦合度 
*/
//友元函数
class Date1
{
	public:
		Date1(int year,int month,int day)
		:_year(year)
		,_month(month)
		,_day(day)
		{}
		ostream& operator<<(ostream& _cout)
		{
			_cout<<this->_year<<"-"<<this->_month<<"-"<<this->_day;
			return _cout;
		}
	private:
		int _year;
		int _month;
		int _day;
};

class Date2
{
	friend ostream& operator<<(ostream& _cout,const Date2 d);
	friend istream& operator>>(istream& _cin,const Date2 d);
	public:
		Date2(int year,int month,int day)
		:_year(year)
		,_month(month)
		,_day(day)
		{}
	private:
		int _year;
		int _month;
		int _day;
	
};

ostream& operator<<(ostream& _cout,const Date2 d)
{
	_cout<<d._year<<"-"<<d._month<<"-"<<d._day;
	
	return _cout;
}

istream& operator>>(istream& _cin,Date2 d)
{
	_cin>>d._year;
	_cin>>d._month;
	_cin>>d._day;
	
	return _cin;
}

class Date3;
class Time
{
	friend class Date3;
	public:
		Time(int hour = 0,int minute = 0,int second = 0)
		:_hour(hour)
		,_minute(minute)
		,_second(second)
		{} 
	private:
		int _hour;
		int _minute;
		int _second;	
}; 

class Date3
{
	public:
		Date3(int year = 1900,int month = 1,int day = 1)
		:_year(year)
		,_month(month)
		,_day(day)
		{}
		
		void settimeofDate(int hour,int minute,int second)
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
int main()
{
	//Date1 d1(2019,9,6);
	//cout<<d;
	//d<<cout;
	//Date2 d2;
	//cin>>d2;
	//cout<<d2<<endl;
	return 0;
 } 
