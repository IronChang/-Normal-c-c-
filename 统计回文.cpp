#include<iostream>
#include<string>
using namespace std;

bool is_Palindrome(string s)//�ж��Ƿ���ǻ��Ĵ�
{
	int len = s.size()/2;//����������´�
	int start = 0;
	int end = s.size() - 1;
	while (len--)
	{
		if (s[start] == s[end])
		{
			end--;
			start++;
		}
		else
		{
			return false;
		}
	}
	return true;
}

int main()
{
	string s1;
	string s2;
	cin >> s1;
	cin >> s2;
	string s3(s1);
	int count = 0;

	for (int i = 0; i <= s1.size(); i++)//�ж��Ƿ���ģ����Ҽ��� 
	{
		s1.insert(i, s2);
		if (is_Palindrome(s1))
		{
			count++;
		}
		s1.clear();
		s1 += s3;
	}
    cout<<count<<endl;
	return 0;
}
