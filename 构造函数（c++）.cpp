/*
��ʼ�������ʼ�� 
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
		Date1(int day)//����Ĭ�Ϲ��캯�� 
		{
		}
	private:
		int _day;
		Time _t;//�����Զ������ͣ�������Ĭ�Ϲ��캯�� 
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
Static��Ա 
*/

class A1
{
	public:
		A1()//���캯�� 
		{ ++_scount;
		}
		
		A1(const A1& t)//�������캯�� 
		{ ++_scount;
		}
		
		void Display()
		{
			GetACount();//�Ǿ�̬��Ա�������Ե��þ�̬��Ա����		
		}
		 
		static int GetACount()//��̬��Ա���� 
		{  
		   //Display();
		   //��̬��Ա�������ܵ��÷Ǿ�̬��Ա���� 
		   //��Ϊ��̬��Ա����û�����ص�thisָ�� 
		   return _scount;
	    } 
	private:
	static int _scount; //��̬��Ա���� 
	
}; 

int A1::_scount = 0;//��̬��Ա����һ��Ҫ��������г�ʼ�� 

int test()
{
	cout<<A1::GetACount()<<endl;
	A1 a1, a2;//�������ι��캯�� 
	A1 a3(a1);//����һ�ο������캯�� 
	cout<<A1::GetACount()<<endl;
}

/*
c++11�ĳ�Ա��ʼ��
c++11֧�ַǾ�̬��Ա����������ʱ��ֱ�ӳ�ʼ���� 
*/

class B
{
	public:
		B(int b = 0):_b(b)
		{
		}

	    int _b;//�ұ��붨��ɹ��еģ���ֹ����Խ�� 
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

int A2::n = 10;//��̬��Ա����������������г�ʼ�� 

/*
��Ԫ����Ԫ��������Ԫ��
 
 
*/

int main()
{
	//Date1 d1(1);
	//Array a(1);
	//Date2 d2(2018);
	//��һ�����ͱ������������Ͷ�����
	//ʵ���ϣ�����������2019����һ����������
	//����ö����d2���и�ֵ�� 
	//d2 = 2019;//���ã�����+���� 
	//test();
	A2 a;
	a.print();	
	return 0;
}
