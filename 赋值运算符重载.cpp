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

//class String
//{
//public:
//	String(char* str = "")
//	{
//		if (str == NULL)
//			_str = "";
//
//		_str = (char*)malloc(strlen(str) + 1);
//		strcpy(_str, str);
//	}
//	~String()
//	{
//		if (_str)
//		{
//			free(_str);
//			_str = nullptr;
//		}
//		cout << "~String()" << endl;
//	}
//private:
//	char* _str;
//
//};
//
//class Person
//{
//public:
//
//private:
//	String _name;
//	String _sex;
//	int _age;
//};
//
//int main()
//{
//	Person P;
//
//	system("pause");
//	return 0;
//}

//�������캯����
//Ĭ�Ϲ��캯�����ö��������ͽ���ֵ���������Զ������ͻ�ȥ�����俽�����캯��

//class Time
//{
//public:
//
//	Time()
//	{
//		cout << "Time()" << endl;
//
//	}
//
//	Time(const Time& d)
//	{
//		cout << "Time(const Time& d)" << endl;
//	}
//private:
//	int _hour;
//};
//
////class Array
////{
////public:
////	Array(int n = 10)
////	{
////		_a = (int*)malloc(sizeof(int)*n);
////		_n = n;
////	}
////	~Array()
////	{
////		if (_a != nullptr)
////		{
////			free(_a);
////			_a = nullptr;
////			_n = 0;
////		}
////	}
////private:
////	int* _a;
////	int _n;
////};
//
//class Date
//{
//public:
//	Date(int year = 1900, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	//���û����ʾ�Ķ��壬��ϵͳ���Զ�����һ��ͬ���Ϳ������캯��
//
//	//Date(const Date& d)//�������캯��������Ĭ�Ͽ������캯��
//	//{
//	//	this->_year = d._year;
//	//	this->_month = d._month;
//	//	this->_day = d._day;
//	//}
//
//	void print()
//	{
//		cout << _year << "-" << _month << "-" << _day << endl;
//	}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//	Time _t;
//};
//
//int main()
//{
//	Date d1;
//	Date d2(d1);//���ÿ������캯����ȥ����
//	d1.print();
//	d2.print();
//
//	cout << sizeof(Date) << endl;
//
//	//Array aa1;
//	//Array aa2(aa1);
//
//
//	system("pause");
//	return 0;
//}

//class Time
//{
//public:
//	Time()
//	{
//		cout << "���ù��캯����Time()" << endl;
//	}
//
//	Time(const Time& t)
//	{
//		cout << "���ÿ������캯����Time(const Time& t)" << endl;
//	}
//private:
//	int  _hour;
//};
//
//class Date
//{
//public:
//	Date(int year = 1900, int  month = 1, int day = 1)//���캯��
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//	Date(const Date& d)//�������캯�� ���캯��������
//	{
//		_year = d._year;
//		_month = d._month;
//		_day = d._day;
//	}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//	Time _t;
//};
//
//int main()
//{
//	Date d1;
//	Date d2(d1);
//	system("pause");
//	return 0;
//}

//class Rect
//{
//public:
//	Rect()      // ���캯������������1
//	{
//		count++;
//	}
//	Rect(const Rect& r)   // �������캯��
//	{
//		width = r.width;
//		height = r.height;
//		count++;          // ��������1
//	}
//	~Rect()     // ������������������1
//	{
//		count--;
//	}
//	static int getCount()   // ���ؼ�������ֵ
//	{
//		return count;
//	}
//private:
//	int width;
//	int height;
//	static int count;       // һ��̬��Ա��Ϊ������
//};
//
//int Rect::count = 0;
//
//int main()
//{
//	Rect r1;
//	cout << "The count of Rect: " << Rect::getCount() << endl;
//	Rect r2(r1);
//	cout << "The count of Rect: " << Rect::getCount() << endl;
//	system("pause");
//	return 0;
//}

//��ֵ���������
/*
*/

//ȫ�ֵ�operator == 

//class Date
//{
//public:
//	Date(int year = 1900, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//	// bool operator==(Date* this, const Date& d2)
//	// ������Ҫע����ǣ����������thisָ��ĵ��ú����Ķ���
//	bool operator==(const Date& d2)
//	{
//		return _year == d2._year
//			&& _month == d2._month
//			&& _day == d2._day;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};

//// ����ᷢ����������س�ȫ�ֵľ���Ҫ��Ա�����ǹ��еģ���ô�������ˣ���װ����α�֤��
//// ������ʵ���������Ǻ���ѧϰ����Ԫ��������߸ɴ����سɳ�Ա����
////bool operator==(const Date& d1, const Date& d2)
////{
////	return d1._year == d2._year
////	    && d1._month == d2._month
////		&& d1._day == d2._day;
////}

//����operator = 

class Date
{
public:
	Date(int year = 1900, int month = 1, int day = 1)//���캯�� ��ʼ������
	{
		_year = year;
		_month = month;
		_day = day;
	}

	Date(const Date& d)//�������캯�� 
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}

	//Date& operator=(const Date& d)//���ظ�ֵ����= ʵ�ֿ������캯��
	//{
	//	if (this != &d)//��֤����ͬһ������
	//	{
	//		_year = d._year;
	//		_month = d._month;
	//		_day = d._day;
	//	}
	//}

	void show()//��Ա���� �����Ա����
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}
private:
	int _year;
	int _month;
	int _day;
};

void Test()
{
	Date d1(2018, 9, 26);
	Date d2;
	d2 = d1;
	d1.show();
	d2.show();


}

int main()
{
	Test();
	system("pause");
	return 0;
}

