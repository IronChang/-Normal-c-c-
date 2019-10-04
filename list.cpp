#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<list>
#include<vector>
using namespace std;

//list����һ����ͷ˫��ѭ������

//list�����ֳ�ʼ����ʽ
void chushihua()
{
	list<int> l1;//�޲ι���յ�list
	list<int> l2(4,100);//����n��ְλval�ĳ�ʼ��list
	list<int> l3(l2.begin(), l2.end());//���õ�������Χ��ʼ��[ * , *)
	list<int> l4(l3);//�������캯��

	//������Ϊ���������乹��l5
	int array[] = { 16, 2, 77, 29 };
	list<int> l5(array, array + sizeof(array) / sizeof(int));

	//�Ե������ķ�ʽ��ӡl5�ֵ�Ԫ��
	for (list<int>::iterator it = l5.begin(); it != l5.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;

	//���ڷ�Χfor��ӡl5�ֵ�Ԫ��
	for (auto& e : l2)
	{
		cout << e << " ";
	}
	cout << endl;

}

//list iterator��������ϰ,
void iterator_p()
{
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	list<int> l(arr, arr + sizeof(arr) / sizeof(arr[0]));//���÷�Χ���������г�ʼ��

	//ʹ�õ������������list�е�Ԫ��
	cout <<"list��Ԫ�ظ�����"<< l.size() << endl;

	//���list�Ƿ�Ϊ��
	if (l.empty())
	{
		cout << "�յ�list" << endl;
	}
	else
	{
		for (const auto& e : l)//���ڷ�Χfor����list
		{
			cout << e << " ";
		}
		cout << endl;
	}
}

void element_access()
{
	int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	list<int> l1(array, array + sizeof(array) / sizeof(array[0]));//���ڵ�����1��Χ��ʼ��list l1

	//���û��ڷ�Χfor�ȱ���һ��
	for (auto& e : l1)
	{
		cout << e << " ";
	}
	cout<<endl;

	//��list�е�һ���ڵ������һ���ڵ��ֵ��Ϊ18
	l1.front() = 18;//���ص���list��һ���ڵ���ֵ������
	l1.back() = 18;//���ص���list���һ���ڵ���ֵ������

	for (list<int>::iterator it = l1.begin(); it != l1.end(); it++)//����������
	{
		cout << *it << " ";
	}
	cout << endl;

	//��Χ��������ʼ��
	const list<int> l2(array, array + sizeof(array) / sizeof(array[0]));
	//int& a = 12.front(); ��䲻��ʵ�֣���Ϊl2����������const�����front���ص���������ҲΪconst
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

	//��listβ������4��ͷ������8
	L.push_back(4);
	L.push_front(8);
	Print(L);

	//ɾ��listβ���ڵ��ͷ���ڵ�
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
		Date(int year = 1900, int month = 1, int day = 1)//��ȱʡֵ��ʼ���б�Ĺ��캯��
			:_year(year)
			, _month(month)
			, _day(day)
		{
			cout << "Date(int ,int ,int):" << this << endl;
		}

		Date(const Date& d)//�������캯��
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
	//push_bac����
	Date d(2018, 10, 20);//����ʱ����Ĺ��캯��
	l.push_back(d);

	//elplace_back����
	l.emplace_back(2018, 10, 21);
	l.emplace_front(2018, 10, 19);

// push_backβ�壺�ȹ����Ԫ�أ�Ȼ��Ԫ�ؿ������ڵ��У�����ʱ�ȵ����캯�����ٵ��������캯��
// emplace_backβ�壺�ȹ���ڵ㣬Ȼ����ù��캯���ڽڵ���ֱ�ӹ������
// emplace_back��push_back����Ч������һ�ο������캯���ĵ���
}

void list_modidiers_3()
{
	//insert  erase  ��ϰ
	int arr[] = { 1, 2, 3 };
	list<int> L(arr, arr + sizeof(arr) / sizeof(arr[0]));

	//��ȡ�����еڶ����ڵ�
	auto pos = ++L.begin();//auto�Զ�������������
	cout << *pos << endl;

	//��posǰ����Ϊ40��Ԫ��
	L.insert(pos, 40);
	Print(L);

	//��posǰλ�ò���5��ֵΪ5��Ԫ��
	//�����Ƿ�ᷢ��������ʧЧ��? ����� ��Ϊ��˫��������ʽ���ǽڵ�洢���ڲ���ʱ���ڵ�ַ����ʧЧ
	L.insert(pos, 5, 50);
	Print(L);

	// ��posλ��ǰ����[v.begin(), v.end())�����е�Ԫ��
    vector<int> v{ 7, 8, 9 };
	L.insert(pos, v.begin(), v.end());
	Print(L);

	//ɾ��posλ���ϵ�Ԫ��
	L.erase(pos);
	Print(L);

	//ɾ��List��[begin, end)�����е�Ԫ�أ���ɾ��list������Ԫ�� ��clear()������������
	L.erase(L.begin(), L.end());
	Print(L);
	cout << L.size() << endl;
}

void list_modifiers_4()
{
	//  resize/swap/clear��ϰ
	int arr[] = { 1, 2, 3 };
	list<int> l1(arr, arr + sizeof(arr) / sizeof(arr[0]));
	Print(l1);

	//��l1��Ԫ�����ӵ�10�������Ԫ����Ĭ��ֵ���
	// (ע�⣺���list�з��õ����������ͣ�Ĭ��ֵΪ0, ���list�з����Զ�������Ԫ�أ�����ȱʡ���캯��)
	l1.resize(10);
	Print(l1);

	//��l1�е�Ԫ�����ӵ�20���������Ԫ����4�����
	l1.resize(20, 4);
	Print(l1);

	//��l1�е�Ԫ�ؼ��ٵ��������Ϊresize���Ըı�list���������б���vector�е�resize
	l1.resize(5, 100);//��ʼֵû����
	Print(l1);


	//�������е�Ԫ������ʼ������list
	vector<int> v{ 4, 5, 6 };
	list<int> l2(v.begin(), v.end());//��������ʼ��
	Print(l2);

	//��l2�е�Ԫ�����
	l2.clear();
	cout << l2.size() << endl;
}

void iterator_questions()
{
	//��Ϊlist�ĵײ�ԭ���Ǵ�ͷ˫��ѭ�����������ڲ���ʱ�ǲ��ᵼ��list�ĵ�����ʧЧ�ģ�ֻ����ɾ��ʱ�Ż�ʧЧ������ʧЧ��ֻ��ָ��ɾ���ڵ��������ָ�������ڵ�ĵ�������������ʧЧ��
	//������ʧЧ��������ָ��Ľڵ���Ч����ɾ����

	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	list<int> L(arr, arr + sizeof(arr) / sizeof(arr[0]));

	auto it = L.begin();
	while (it != L.end())
	{
		//L.erase(it);
		//++it;//��ʱ�ᱨ����Ϊ�Ѿ�ɾ����it��ָ����ĸ��ڵ㣬��ʱit�Ѿ���Ч��������¸�ֵ���Ľ�����
		//it = L.begin();

		//L.erase(it++);
		//erase()y��Ϊ������ ɾ��һ���ڵ����ǰһ���ڵ�ͺ�ҡ���ڵ��������������ر�ɾ���ڵ�ĺ�һ���ڵ�ĵ�ַ������
		it = L.erase(it);
	}
}

//ģ��ʵ��list
namespace my_list
{
	//list�Ľڵ���
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


