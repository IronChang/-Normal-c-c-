
#include <iostream>
#include <string>
using namespace std;

//�����ĸ��û�з���0��ȫ����(С)д����10����Сд��Ϸ���20
int AboutLetter(const string& s,int length)
{
	int big = 0, small = 0;
	for (int i = 0; i < length; ++i)
	{
		if (s[i] >= 'a' && s[i] <= 'z')
			++small;
		else if (s[i] >= 'A' && s[i] <= 'Z')
			++big;
	}
	if ((small + big) == 0)
		return 0;
	else if (small == length || big == length)
		return 10;
	else if (small > 0 && big > 0)
		return 20;
	return 0;
}

//������ָ�����û�з���0����һ������10������һ������20
int NumOfNumber(const string& s, int length)
{
	int count = 0;
	for (int i = 0; i < length; ++i)
	{
		if (s[i] >= '0' && s[i] <= '9')
			++count;
	}
	if (0 == count)
		return 0;
	else if (1 == count)
		return 10;
	else
		return 20;
}

//�����Ÿ�����û�з���0����һ������10������һ������25
int NumOfSymbol(const string& s, int length)
{
	int count = 0;
	for (int i = 0; i < length; ++i)
	{
		//��������Ҳ������ĸ�Ļ����Ƿ�����
		if (!(s[i] >= '0' && s[i] <= '9')&&
			!(s[i] >= 'a' && s[i] <= 'z')&&
			!(s[i] >= 'A' && s[i] <= 'Z'))
			++count;
	}
	if (0 == count)
		return 0;
	else if (1 == count)
		return 10;
	else
		return 25;
}

int main()
{
	int sum1 = 0, sum2 = 0, sum3 = 0, sum4 = 0, sum5 = 0;
	string s;
	while (getline(cin, s))
	{
		int length = s.size();
		//sum1�������볤�ȵķ���
		if (length <= 4)
			sum1 = 5;
		else if (length <= 7)
			sum1 = 10;
		else
			sum1 = 25;

		sum2 = AboutLetter(s, length);//sum2������ĸ�ķ���
		sum3 = NumOfNumber(s, length);//sum3�������ֵķ���
		sum4 = NumOfSymbol(s, length);//sum4������ŵķ���

		//sum5���潱����
		if (sum2 > 0 && sum3 > 0)
		{
			if (sum4 > 0)
			{
				if (20 == sum2)
					sum5 = 5;
				else
					sum5 = 3;
			}
			else
				sum5 = 2;
		}

		//���ݵ÷������Ӧ�����ȫ�ȼ�
		if (sum1 + sum2 + sum3 + sum4 + sum5 >= 90)
			cout << "VERY_SECURE" << endl;
		else if (sum1 + sum2 + sum3 + sum4 + sum5 >= 80)
			cout << "SECURE" << endl;
		else if (sum1 + sum2 + sum3 + sum4 + sum5 >= 70)
			cout << "VERY_STRONG" << endl;
		else if (sum1 + sum2 + sum3 + sum4 + sum5 >= 60)
			cout << "STRONG" << endl;
		else if (sum1 + sum2 + sum3 + sum4 + sum5 >= 50)
			cout << "AVERAGE" << endl;
		else if (sum1 + sum2 + sum3 + sum4 + sum5 >= 25)
			cout << "WEAK" << endl;
		else
			cout << "VERY_WEAK" << endl;
	}
	return 0;
}


