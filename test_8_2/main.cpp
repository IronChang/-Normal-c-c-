#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;


//���캯��������ʼ�����󣬶����Ǵ�������
//�������޷���ֵ����������������ͬ���Զ����á���������

/*
//class Data
//{
////���û����ʾ�Ķ��壬���������Ĭ������һ���޲ι��캯�������κβ���
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

//һ�����п����ж�����캯�������ǲ����ֶ�ȥ���ö���ʵ�����Ǹ��ݲ�����ͬ�Զ�����

//Ĭ�Ϲ��캯�����������Ͳ����������Զ������͵�����Ĭ�Ϲ��캯��

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
	//1���޲ι��캯��
	//Date()
	//{

	//}
	//2�����ι��캯��
	Date() = default;//���߱������Զ�����һ���޲�Ĭ�Ϲ��캯������������ͬ���Ŀ��Կ����������غ���Ȼ���ٸ��ݲ�����ͬ���е���

	Date(int year, int month, int day)
	{
		_year = year;
		_month = month;
		_day = day;
	}
	//3�����ɴ�����Ҳ�ɲ����������������޲ι��캯����ͻ����ɶ����ԣ�
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
	//��������ֻ��һ����������û�п��ռ���ж���,ֻ����ʵ����ʱ�ŻῪ���ռ�
	int _year = 1990;
	int _month = 1;
	int _day = 1;
	Time t;
};

int main()
{

	//ʵ����ʱ�в���Ҫ�����ţ�û�в������ô�����
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


//���������������Դ��������һ������ֻ����һ����������
//�������ຯ����ǰ��~���޲����޷���ֵ�������������ڽ���ʱ�Զ�����


//�������캯����
//Ĭ�Ϲ��캯�����ö��������ͽ���ֵ���������Զ������ͻ�ȥ�����俽�����캯��

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
	//���û����ʾ�Ķ��壬��ϵͳ���Զ�����һ��ͬ���Ϳ������캯��

	//Date(const Date& d)//�������캯��������Ĭ�Ͽ������캯��
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
	Date d2(d1);//���ÿ������캯����ȥ����
	d1.print();
	d2.print();

	cout << sizeof(Date) << endl;

	//Array aa1;
	//Array aa2(aa1);


	system("pause");
	return 0;
}