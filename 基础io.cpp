#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<string>
using namespace std;

//int main()
//{
//	//���ļ��У�д������
//	FILE* fp = fopen("myfile", "w");
//	if (!fp)
//	{
//		printf("fpoen error!\n");
//	}
//	const char *msg = "hello bit!\n";
//	int count = 5;
//	while (count--)
//	{
//		fwrite(msg, strlen(msg), 1, fp);
//	}
//	fclose(fp);
//
//	//���ļ��������ȡ����
//	fp = fopen("myfile", "r");
//	if (!fp)
//	{
//		printf("fopen error!\n");
//	}
//	char buf[1024];
//	while (1)
//	{
//		int s = fread(buf, 1, strlen(msg), fp);
//		if (s > 0)
//		{
//			buf[s] = 0;
//			printf("%s", buf);
//		}
//		if (feof(fp))
//		{
//			break;
//		}
//	}
//	fclose(fp);
//	system("pause");
//	return 0;
//}


//int func()
//{
//	int i, j, k = 0;
//	for (i = 0, j = -1; j =0; i++, j++)
//	{
//		k++;
//	}
//	return k;
//}


//int main()
//{
//	//const char *msg = "hello world!\n";
//	//fwrite(msg, strlen(msg), 1, stdout);
//	//printf("hello world!\n");
//	//fprintf(stdout, "hello world!\n");
//
//	/*int ta[][3] = { { 0, , 2 }, {}, {3,4,5} };
//
//	string s;
//	getline(cin, s);
//	reverse(s.begin(), s.end());
//	auto start = s.begin();
//	while (start != s.end())
//	{
//		auto end = start;
//		while (end != s.end() && *end !=' ')
//		{
//			end++;
//		}
//		reverse(start,end);
//		if (end != s.end())
//		{
//			start = end + 1;
//		}
//		else
//		{
//			start = end;
//		}
//	}
//	cout << s;*/
//
//
//
//	/*cout << (func());*/
//
//	string s;
//	string c;
//	getline(cin, s);
//
//	auto start = s.begin();
//	auto end = start;
//	while (end != s.end())
//	{
//		
//		int max = 0;
//		while (end != s.end() && (*end < 48 || *end > 57))
//		{
//			end++;
//		}
//
//		if (end != s.end())
//		{
//			start = end;
//		}
//		else
//		{
//			start = end;
//		}
//
//		while (end != s.end() && (*end >= 48 && *end <= 57))
//		{
//			max++;
//			end++;
//		}
//
//
//		if ( max > c.size())
//		{
//			c.clear();
//			while (start != end)
//			{
//				c += *start;
//				start++;
//			}
//		}
//
//		if (end == s.end())
//		{
//			break;
//		}
//	}
//	cout << c<<endl;
//	
//	system("pause");
//	return 0;
//}



//
//int main()
//{
//
//	int A, B, C;
//	int a, b, c, d;
//	cin >> a >> b >> c >> d;
//	B = (b + d) / 2;
//	A = (a + c) / 2;
//
//	if (b < 0)
//	{
//		C = B + (-1 * b);
//	}
//	else if (b == 0)
//	{
//		C = B;
//	}
//	else
//	{
//		C = B - b;
//	}
//
//	if (A>0 && B>0 && C>0)
//	{
//		cout << A << " " << B << " " << C << endl;
//	}
//	else
//	{
//		cout << "No" << endl;
//	}
//	system("pause");
//	return 0;
//}


//int main()
//{
//	int x = 1;
//	do{
//		printf("%2d\n", x++);
//	} while (x--);
//	system("pause");
//	return 0;
//}

//bool is_Palindrome(string s)//�ж��Ƿ���ǻ��Ĵ�
//{
//	int len = s.size()/2;//����������´�
//	int start = 0;
//	int end = s.size() - 1;
//	while (len--)
//	{
//		if (s[start] == s[end])
//		{
//			end--;
//			start++;
//		}
//		else
//		{
//			return false;
//		}
//	}
//	return true;
//}
//
//
//int main()
//{
//	string s1;
//	string s2;
//	
//
//	cin >> s1;
//	cin >> s2;
//	string s3(s1);
//	int count = 0;
//
//	for (int i = 0; i <= s1.size(); i++)
//	{
//		s1.insert(i, s2);
//		if (is_Palindrome(s1))
//		{
//			count++;
//		}
//		s1.clear();
//		s1 += s3;
//	}
//
//	system("pause");
//	return 0;
//}



//#include<iostream>
//#include<string>
//#include<algorithm>
//using namespace std;
//
//int main()
//{
//	string s;
//	getline(cin, s);
//	string::iterator end = s.end();
//	int i = s.length();
//	
//	while (i>=0)
//	{
//		int count = 0;
//		while (s[i] != ' ')
//		{
//			i--;
//			count++;
//		}
//
//		cout << s.substr(i, count) << " ";
//		
//	}
//	system("pause");
//	return 0;
//}

//���ӣ� i like beijing.
// .gnijieb ekil i

//int main()
//{
//	string s;
//	getline(cin, s);
//	//���������ת
//	reverse(s.begin(), s.end());
//
//	//���в�����ת
//	string::iterator start = s.begin();
//	string::iterator end = start;
//	while (end != s.end())
//	{
//		//�ҿո������ո�ͣ��
//		while (end != s.end() && *end != ' ')
//		{
//			end++;
//		}
//		
//		if (end != s.end())
//		{
//			reverse(start, end);//���оֲ���ת
//			end++;
//			start = end;
//		}
//		else
//		{
//			reverse(start, end);//���оֲ���ת
//		}
//	}
//	cout << s << endl;
//	system("pause");
//	return 0;
//}



//���ӣ� i like beijing.

//int main()
//{
//	//����cin�����ո�ͽ���������
//	string s1;
//	string s2;
//	cin >> s2;
//	while (cin >> s1)
//	{
//		s2 = s1 + " " + s2;
//	}
//	system("pause");
//	return 0;
//}


//���ӣ� i like beijing.

//����substr�����н׶����



//
//int main()
//{
//	string s;
//	getline(cin, s);
//	auto start = 0;
//	auto end = s.length();
//	int count = 0;
//	while (end >= start)
//	{
//		count = 0;//ÿһ�μ���Ҫ��ȡ�ĳ���
//		//�ҿո�
//		while (end != start && s[end] != ' ')
//		{
//			end--;
//			++count;
//		}
//
//		if (end != start)
//		{
//			cout<<s.substr(end+1, count)<<" ";
//			end--;
//		}
//		else
//		{
//			cout << s.substr(end, count) << endl;
//		}
//	}
//	system("pause");
//	return 0;
//}
//
//template<class T>
//bool isequal(T& left, T& right)
//{
//	return left == right;
//}
//
//void test()
//{
//	char* p1 = "hello";
//	char* p2 = "world";
//
//	if (isequal(p1, p2))
//		cout << p1 << endl;
//	else
//		cout << p2 << endl;
//}
//
//int main()
//{
//	test();
//	system("pause");
//	return 0;
//}

//class Person
//{
//public:
//
//	void Print()
//	{
//
//		cout << "name:" << _name << endl;
//
//		cout << "age:" << _age << endl;
//	}
//protected:
//
//	string _name = "peter"; // ����
//
//	int _age = 18; // ����
//};
//class Student : public Person
//{
//protected:
//
//	int _stuid; // ѧ��
//};
//class Teacher : public Person
//{
//protected:
//
//	int _jobid; // ����
//};


//class Person
//{
//public:
//
//	void Print()
//	{
//
//		cout << _name << endl;
//	}
//protected:
//
//	string _name; // ����
//private:
//
//	int _age; // ����
//};
////class Student : protected Person
////class Student : private Person
//class Student : public Person
//{
//protected:
//
//	int _stunum; // ѧ��
//};


//class Person
//{
//protected:
//	string _name; // ����
//	string _sex; // �Ա�
//	int _age; // ����
//};
//class Student : public Person
//{
//public:
//	int _No; // ѧ��
//};
//void Test()
//{
//	Student sobj;
//	// 1.���������Ը�ֵ���������/ָ��/����
//	Person pobj = sobj;
//	Person* pp = &sobj;
//	Person& rp = sobj;
//	//2.��������ܸ�ֵ�����������
//    sobj = pobj;
//	// 3.�����ָ�����ͨ��ǿ������ת����ֵ���������ָ��
//	//pp = &sobj
//	//	Student* ps1 = (Student*)pp; // �������ת��ʱ���Եġ�
//	//ps1->_No = 10;
//	pp = &pobj;
//	Student* ps2 = (Student*)pp; // �������ת��ʱ��Ȼ���ԣ����ǻ����Խ����ʵ�����
//	ps2->_No = 10;
//}



// Student��_num��Person��_num�������ع�ϵ�����Կ�������������Ȼ���ܣ����Ƿǳ����׻���
//class Person
//{
//protected:
//
//	string _name =
//		"С����"; // ����
//
//	int _num = 111; // ���֤��
//};
//class Student : public Person
//{
//public:
//	void Print()
//	{
//		cout << " ����:" << _name << endl;
//		cout << " ���֤��:" << Person::_num << endl;
//		cout << " ѧ��:" << _num << endl;
//	}
//protected:
//	int _num = 999; // ѧ��
//};
//void Test()
//{
//	Student s1;
//	s1.Print();
//};

class Person
{
public:
	Person(const char* name = "peter")
		: _name(name)
	{
		cout << "Person()" << endl;
	}
	Person(const Person& p)
		: _name(p._name)
	{
		cout << "Person(const Person& p)" << endl;
	}
	Person& operator=(const Person& p)
	{
		cout << "Person operator=(const Person& p)" << endl;
		if (this != &p)
			_name = p._name;
		return *this;
	}

	~Person()
	{
		cout << "~Person()" << endl;
	}
protected:
	string _name; // ����
};

class Student : public Person
{
public:

	Student(const char* name, int num)
		: Person(name)
		, _num(num)
	{

		cout << "Student()" << endl;
	}


	Student(const Student& s)
		: Person(s)
		, _num(s._num)
	{

		cout << "Student(const Student& s)" << endl;
	}


	Student& operator = (const Student& s)
	{
		if (this != &s)
		{

			Person::operator=(s);
			_num = s._num;
		}
		cout << "Student& operator= (const Student& s)" << endl;
		return *this;
	}
	~Student()
	{

		cout << "~Student()" << endl;
	}
protected:

	int _num; //ѧ��
};
void Test()
{
	Student s1("jack", 18);
	Student s2(s1);
	Student s3("rose", 17);

	s1 = s3;
}
int main()
{
	Test();
	//Student s;
	//s.Print();
	system("pause");
	return 0;
}
