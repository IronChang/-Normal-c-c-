#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

//命名空间的用法

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

//c++输入&输出

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

//缺省函数

//void Func(int a = 0)
//{
//	cout << a << endl;
//}

//全省缺参数
//void Func(int a = 10, int b = 20, int c = 30)
//{
//	cout << "a=" << a << endl;
//	cout << "b=" << b << endl;
//	cout << "c=" << c << endl;
//}

//半缺省参数
//void Func(int a, int b, int c = 40)
//{
//	cout << "a=" << a << endl;
//	cout << "b=" << b << endl;
//	cout << "c=" << c << endl;
//}
//半缺省参数必须从右往左依次给出，不能间隔着
 
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


//引用
//引用在定义时必须初始化
//同一块内存空间 不同的名字
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
//赋值规则（指针和引用） 权限缩小 ok  权限变大 no

//int main()
//{
//	//Test();
//	system("pause");
//	return 0;
//}


// 引用 1、做参数
//void swap(int& left, int& right)
//{
//	int tmp = left;
//	left = right;
//	right = tmp;
//}
//
////做函数返回值
//
////代码来源：RUNOOB
//
//
//float temp;
//float fn1(float r){
//	temp = r*r*3.14;
//	return temp;
//}
//float &fn2(float r){ //&说明返回的是temp的引用，换句话说就是返回temp本身
//	temp = r*r*3.14;
//	return temp;
//}
//int main(){
//	float a = fn1(5.0); //case 1：返回值
//	//float &b=fn1(5.0); //case 2:用函数的返回值作为引用的初始化值 [Error] invalid initialization of non-const reference of type 'float&' from an rvalue of type 'float'
//	//（有些编译器可以成功编译该语句，但会给出一个warning） 
//	float c = fn2(5.0);//case 3：返回引用
//	float &d = fn2(5.0);//case 4：用函数返回的引用作为新引用的初始化值
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


