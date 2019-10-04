#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<list>
#include<vector>
using namespace std;

//list就是一个带头双向循环链表

//list的四种初始化方式
void chushihua()
{
	list<int> l1;//无参构造空的list
	list<int> l2(4,100);//构造n个职位val的初始化list
	list<int> l3(l2.begin(), l2.end());//利用迭代器范围初始化[ * , *)
	list<int> l4(l3);//拷贝构造函数

	//以数组为迭代器区间构造l5
	int array[] = { 16, 2, 77, 29 };
	list<int> l5(array, array + sizeof(array) / sizeof(int));

	//以迭代器的方式打印l5种的元素
	for (list<int>::iterator it = l5.begin(); it != l5.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;

	//基于范围for打印l5种的元素
	for (auto& e : l2)
	{
		cout << e << " ";
	}
	cout << endl;

}

//list iterator迭代器练习,
void iterator_p()
{
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	list<int> l(arr, arr + sizeof(arr) / sizeof(arr[0]));//利用范围迭代器进行初始化

	//使用迭代器正向遍历list中的元素
	cout <<"list中元素个数："<< l.size() << endl;

	//检测list是否为空
	if (l.empty())
	{
		cout << "空的list" << endl;
	}
	else
	{
		for (const auto& e : l)//基于范围for遍历list
		{
			cout << e << " ";
		}
		cout << endl;
	}
}

void element_access()
{
	int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	list<int> l1(array, array + sizeof(array) / sizeof(array[0]));//基于迭代器1范围初始化list l1

	//利用基于范围for先遍历一下
	for (auto& e : l1)
	{
		cout << e << " ";
	}
	cout<<endl;

	//将list中第一个节点与左后一个节点的值改为18
	l1.front() = 18;//返回的是list第一个节点中值的引用
	l1.back() = 18;//返回的是list最后一个节点中值的引用

	for (list<int>::iterator it = l1.begin(); it != l1.end(); it++)//迭代器遍历
	{
		cout << *it << " ";
	}
	cout << endl;

	//范围迭代器初始化
	const list<int> l2(array, array + sizeof(array) / sizeof(array[0]));
	//int& a = 12.front(); 这句不能实现，因为l2对象类型是const，因此front返回的引用类型也为const
	const int& ca = l2.front();
}

void Print(list<int>& l)
{
	for (auto& e : l)
	{
		cout << e << " ";
	}
	cout << endl;
}

void list_modifiers_1()
{
	//push_back,pop_back, push_front pop_front
	int arr[] = { 1, 2, 3 };
	list<int> L(arr, arr + sizeof(arr) / sizeof(arr[0]));

	//在list尾部插入4，头部插入8
	L.push_back(4);
	L.push_front(8);
	Print(L);

	//删除list尾部节点和头部节点
	L.pop_back();
	L.pop_front();
	Print(L);

}

void list_modidiers_2()
{
	//========================================================================
	// push_back/pop_back/push_front/pop_front

	class Date
	{
	public:
		Date(int year = 1900, int month = 1, int day = 1)//带缺省值初始化列表的构造函数
			:_year(year)
			, _month(month)
			, _day(day)
		{
			cout << "Date(int ,int ,int):" << this << endl;
		}

		Date(const Date& d)//拷贝构造函数
		{
			_year = d._year;
			_month = d._month;
			_day = d._day;
			cout << "Date(const Date&):" << this << endl;
		}

	private:
		int _year;
		int _month;
		int _day;
	};

	list<Date> l;
	//push_bac插入
	Date d(2018, 10, 20);//调用时间类的构造函数
	l.push_back(d);

	//elplace_back插入
	l.emplace_back(2018, 10, 21);
	l.emplace_front(2018, 10, 19);

// push_back尾插：先构造好元素，然后将元素拷贝到节点中，插入时先调构造函数，再调拷贝构造函数
// emplace_back尾插：先构造节点，然后调用构造函数在节点中直接构造对象
// emplace_back比push_back更高效，少了一次拷贝构造函数的调用
}

void list_modidiers_3()
{
	//insert  erase  练习
	int arr[] = { 1, 2, 3 };
	list<int> L(arr, arr + sizeof(arr) / sizeof(arr[0]));

	//获取链表中第二个节点
	auto pos = ++L.begin();//auto自动推理数据类型
	cout << *pos << endl;

	//在pos前插入为40的元素
	L.insert(pos, 40);
	Print(L);

	//在pos前位置插入5个值为5的元素
	//这里是否会发生迭代器失效吗? 不会的 因为是双向链表形式都是节点存储，在插入时存在地址迭代失效
	L.insert(pos, 5, 50);
	Print(L);

	// 在pos位置前插入[v.begin(), v.end())区间中的元素
    vector<int> v{ 7, 8, 9 };
	L.insert(pos, v.begin(), v.end());
	Print(L);

	//删除pos位置上的元素
	L.erase(pos);
	Print(L);

	//删除List中[begin, end)区间中的元素，即删除list中所有元素 和clear()函数功能相似
	L.erase(L.begin(), L.end());
	Print(L);
	cout << L.size() << endl;
}

void list_modifiers_4()
{
	//  resize/swap/clear练习
	int arr[] = { 1, 2, 3 };
	list<int> l1(arr, arr + sizeof(arr) / sizeof(arr[0]));
	Print(l1);

	//将l1中元素增加到10，多出的元素用默认值填充
	// (注意：如果list中放置的是内置类型，默认值为0, 如果list中放置自定义类型元素，调用缺省构造函数)
	l1.resize(10);
	Print(l1);

	//将l1中的元素增加到20个，多出来元素用4来填充
	l1.resize(20, 4);
	Print(l1);

	//将l1中的元素减少到五个，因为resize可以改变list的容量，有别于vector中的resize
	l1.resize(5, 100);//初始值没有用
	Print(l1);


	//用容器中的元素来初始化构造list
	vector<int> v{ 4, 5, 6 };
	list<int> l2(v.begin(), v.end());//迭代器初始化
	Print(l2);

	//将l2中的元素清空
	l2.clear();
	cout << l2.size() << endl;
}

void iterator_questions()
{
	//因为list的底层原理是带头双向循环链表，所以在插入时是不会导致list的迭代器失效的，只有在删除时才会失效。并且失效的只有指向被删除节点迭代器。指向其他节点的迭代器正常不会失效。
	//迭代器失效：迭代器指向的节点无效即被删除了

	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	list<int> L(arr, arr + sizeof(arr) / sizeof(arr[0]));

	auto it = L.begin();
	while (it != L.end())
	{
		//L.erase(it);
		//++it;//此时会报错，因为已经删除了it所指向的哪个节点，此时it已经无效。必须从新赋值。改进日下
		//it = L.begin();

		//L.erase(it++);
		//erase()y因为是链表 删除一个节点后会把前一个节点和后摇滚节点连接起来，返回被删除节点的后一个节点的地址迭代器
		it = L.erase(it);
	}
}

//模拟实现list
namespace my_list
{
	//list的节点类
	template<class T>
	struct ListNode
	{
		ListNode(const T& val = T())
		:_prev(nullptr)
		, _next(nullptr)
		, _val = val
		{}

		ListNode<T>* _prev;
		ListNode<T>* _next;
		T _val;
	};
}

int main()
{
	//chushihua();
	//iterator_p();
	//element_access();
	//list_modifiers_1();
	//list_modidiers_2();
	//list_modidiers_3();
	//list_modifiers_4();
	iterator_questions();


	
	system("pause");
	return 0;
}


