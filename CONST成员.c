#include<iostream>
using namespace std;
/*
Const������ĳ�Ա����
��ʵ�������θó�Ա����������thisָ�룬
�����ó�Ա�������ܶ�����κγ�Ա�����޸� 
*/ 



class Date
{
	public:
		void Display()
		{
			cout<<"Display ()" <<endl;
            cout<<"year:" <<_year<< endl;
            cout<<"month:" <<_month<< endl;
			cout<<"day:"<<_day<<endl;	
		}
		void Display() const
		{
			cout<<"Display ()" <<endl;
            cout<<"year:" <<_year<< endl;
            cout<<"month:" <<_month<< endl;
			cout<<"day:"<<_day<<endl;			
		}
	private:
		int _year;
		int _month;
		int _day;
	
};
int main()
{
	Date d1;
	d1.Display();
	const Date d2;
	d2.Display();
}

/*
ȡ��ַ��constȡ��ַ���������� 
*/
class Date1
{
	public:
		Date1* operator&()
		{
			return this;
		}
		const Date1* operator&() const
		{
			return this;
		}
	private:
		int _year;
		int _month;
		int _day;
};

