#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

//�����ռ���÷�

//namespace N
//{
//	int a = 10;
//	int b = 20;
//
//	int Add(int left, int right)
//	{
//		return left + right;
//	}
//
//	int Sub(int left, int right)
//	{
//		return left - right;
//	}
//}
//
////int main()
////{
////	printf("%d\n", N::a);
////	system("pause");
////	return 0;
////}
//
////using namespace N;
////int main()
////{
////	printf("%d\n", a);
////	printf("%d\n", b);
////	system("pause");
////	return 0;
////}
//
////using  N ::b;
////int main()
////{
////	printf("%d\n", N::a);
////	printf("%d\n", b);
////	system("pause");
////	return 0;
////}

//c++����&���

//int main()
//{
//	/*cout << "hello world!!!" << endl;*/
//
//	int a;
//	double b;
//	char c;
//
//	cin >> a;
//	cin >> b >> c;
//
//	cout << a << endl;
//	cout << b << " " << c << endl;
//	system("pause");
//	return 0;
//}

//ȱʡ����

//void Func(int a = 0)
//{
//	cout << a << endl;
//}

//ȫʡȱ����
//void Func(int a = 10, int b = 20, int c = 30)
//{
//	cout << "a=" << a << endl;
//	cout << "b=" << b << endl;
//	cout << "c=" << c << endl;
//}

//��ȱʡ����
//void Func(int a, int b, int c = 40)
//{
//	cout << "a=" << a << endl;
//	cout << "b=" << b << endl;
//	cout << "c=" << c << endl;
//}
//��ȱʡ������������������θ��������ܼ����
 
//int main()
//{
//	Func(3,5);
//	Func(10,20);
//
//	system("pause");
//	return 0;
//}
//
//void Func(int a = 10)
//{
//	cout << "void Func(int)" << endl;
//}
//
//void Func(int a)
//{
//	cout << "void Func(int)" << endl;
//}


//����
//�����ڶ���ʱ�����ʼ��
//ͬһ���ڴ�ռ� ��ͬ������
//void Test()
//{
//	int a = 0;
//	int& ra = a;
//
//	printf("%p\n", &a);
//	printf("%p\n", &ra);
//}

void test()
{
	const int a = 10;
	const int& ra = a;

	const int& b = 10;

	double d = 12.34;
    const double& rd = d;
}
//��ֵ����ָ������ã� Ȩ����С ok  Ȩ�ޱ�� no

//int main()
//{
//	//Test();
//	system("pause");
//	return 0;
//}


// ���� 1��������
//void swap(int& left, int& right)
//{
//	int tmp = left;
//	left = right;
//	right = tmp;
//}
//
////����������ֵ
//
////������Դ��RUNOOB
//
//
//float temp;
//float fn1(float r){
//	temp = r*r*3.14;
//	return temp;
//}
//float &fn2(float r){ //&˵�����ص���temp�����ã����仰˵���Ƿ���temp����
//	temp = r*r*3.14;
//	return temp;
//}
//int main(){
//	float a = fn1(5.0); //case 1������ֵ
//	//float &b=fn1(5.0); //case 2:�ú����ķ���ֵ��Ϊ���õĳ�ʼ��ֵ [Error] invalid initialization of non-const reference of type 'float&' from an rvalue of type 'float'
//	//����Щ���������Գɹ��������䣬�������һ��warning�� 
//	float c = fn2(5.0);//case 3����������
//	float &d = fn2(5.0);//case 4���ú������ص�������Ϊ�����õĳ�ʼ��ֵ
//	cout << a << endl;//78.5
//	//cout<<b<<endl;//78.5
//	cout << c << endl;//78.5
//	cout << d << endl;//78.5
//	system("pause");
//	return 0;
//}


//int c = 0;
int& Add(int a, int b)
{
	int c = a + b;
	return c;
}

int main()
{
	//int& ret = Add(1, 2);
	//Add(3, 4);
	//cout << "Add(1,2) is :" << ret << endl;
	//cout << "Add(3,4) is :" << Add(3, 4) << endl;
	//cout << "ret is :" << ret << endl;



	system("pause");
	return 0;
}


