#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

///��Ķ���

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
//	man._sex = "��";
//	man._age = 10;
//	man.showInfo();
//	system("pause");
//	return 0;
//}

///thisָ��

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
//	p->show();//�����ﲻ��ָ������ã����ǰ�pָ������ݴ�����this
//	system("pause");
//	return 0;
//}


///���캯�� 
//��Ա����������������ͬ�����������ʱ�ɱ������Զ����ã��ڶ������������ֻ�ܵ���һ��

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

//���������������캯������ɶ�����
//class Date
//{
//public:
//	// 1.�޲ι��캯��
//	//Date()
//	//{}
//	// 2.���ι��캯��
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
//	Date d1; // �����޲ι��캯��
//
//	//Date d2(2015, 1, 1); // ���ô��εĹ��캯��
//
//
//	// ע�⣺���ͨ���޲ι��캯����������ʱ��������治�ø����ţ�����ͳ��˺�������
//
//	// ���´���ĺ�����������d3�������ú����޲Σ�����һ���������͵Ķ���
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
//};//class Time//{//public://	Time()//���캯����Ķ����ʼ��//	{//		cout << "Time()" << endl;//		_hour = 0;//		_minute = 0;//		_second = 0;//	}//private://	int _hour;//	int _minute;//	int _second;//};//class Date//{//private://	///��������//	int _year;//	int _month;//	int _day;////	//�Զ�������//	Time _t;////};
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

//��������

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