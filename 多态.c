//多态
//class Person
//{
//public:
//	 virtual ~Person(){ cout << "~Person()" << endl; }
//	 virtual  void display(){ cout << "i am Person" << endl; }
//};
//
//class Student :public Person
//{
//public:
//	virtual ~Student(){ cout << "~Student()" << endl; }
//	virtual void display() override{ cout << "i am Student" << endl; }
//};
//
//int main()
//{
//	Person* p1 = new Person;
//	Person* p2 = new Student;
//
//	p1->display();
//	p2->display();
//
//	delete p1;
//	delete p2;
//
//	return 0;
//}

//
//class Base
//{
//public:
//	virtual void Func1()
//	{
//		cout << "Base::Func1()" << endl;
//	}
//	virtual void Func2()
//	{
//		cout << "Base::Func2()" << endl;
//	}
//	void Func3()
//	{
//		cout << "Base::Func3()" << endl;
//	}
//private:
//	int _b = 1;
//};
//class Derive : public Base
//{
//public:
//	virtual void Func1()
//	{
//		cout << "Derive::Func1()" << endl;
//	}
//private:
//	int _d = 2;
//};

/*class Base
{
public:

	virtual void func1() { cout << "Base::func1" << endl; }
	virtual void func2() { cout << "Base::func2" << endl; }
private:
	int a;
};
class Derive :public Base {
public:
	virtual void func1() { cout << "Derive::func1" << endl; }
	virtual void func3() { cout << "Derive::func3" << endl; }
	virtual void func4() { cout << "Derive::func4" << endl; }

private:
	int b;
};

typedef void(*VFPTR)();

void PrintVTable(VFPTR vTable[])
{
	cout << "虚函数表地址：" << vTable << endl;
	for (int i = 0; vTable[i] != nullptr; i++)
	{
		printf("第%d个虚函数地址：0x%x", i, vTable[i]);
		VFPTR f = vTable[i];
		f();
	}
	cout << endl;
}*/
class Base1 { public: int _b1; };
class Base2 { public: int _b2; };
class Derive : public Base1, public Base2 { public: int _d; };


class A
{
public:
	virtual void func(int val = 1){ std::cout << "A->" << val << std::endl; }
	virtual void test(){ func(); }
};
class B : public A
{
public:
	void func(int val = 0){ std::cout << "B->" << val << std::endl; }
};
int main()
{
	Derive d;

	//VFPTR* vTableb = (VFPTR*)(*(int*)&b);
	//PrintVTable(vTableb);

	//VFPTR* vTabled = (VFPTR*)(*(int*)&d);
	//PrintVTable(vTabled);

	
	/*Base1* p1 = &d;
	Base2* p2 = &d;
	Derive* p3 = &d;*/

	B* p = new B;
	p->test();

	return 0;
}