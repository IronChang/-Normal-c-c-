#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


struct Compare//仿函数能实现
{
	bool operator() (int a, int b)
	{ return (a > b); }
} cmp;
void testalgorithm()
{
	int myints[] = { 32, 71, 12, 45, 26, 80, 53, 33 };
	vector<int> vc(myints, myints + 8);
	//sort(vc.begin(), vc.end());
	sort(vc.begin(), vc.end(), cmp);
	for (auto& e : vc)
	{
		cout << e << " ";
	}
	cout << endl;

}

namespace N
{
	template<class Iterator,class T>
	Iterator find(Iterator first, Iterator last, const T& val)
	{
		while (first != last)
		{
			if (*first == val)
				return first;
			++first;
		}
		return last;
	}

	template<class Iterator>
	void reverse(Iterator first, Iterator last)
	{
		while ((first != last) && (first != --last))
		{
			std::iter_swap(first, last);
			++first;
		}
	}
}
void testfind()
{
	int myints[] = { 32, 71, 12, 45, 26, 80, 53, 33 };
	vector<int> vc(myints, myints + 8);
	//vector<int>::iterator it = find(vc.begin(), vc.end(), 45);
	vector<int>::iterator it = N::find(vc.begin(), vc.end(), 45);
	cout << *it << endl;
}

void testreverse()
{
	int myints[] = { 32, 71, 12, 45, 26, 80, 53, 33 };
	vector<int> vc(myints, myints + 8);

	//reverse(vc.begin(), vc.end());
	N::reverse(vc.begin(), vc.end());

	for (auto& e : vc)
	{
		cout << e << " ";
	}
	cout << endl;
}

void testtatate()
{
	int myints[] = { 32, 71, 12, 45, 26, 80, 53, 33 };
	vector<int> vc(myints, myints + 8);
	rotate(vc.begin(), vc.begin() + 7, vc.end());

	for (auto& e : vc)
	{
		cout << e << " ";
	}
	cout << endl;

}


int main()
{
	//testalgorithm();
	//testtatate();
	//testfind();
	testreverse();
	system("pause");
	return 0;
}