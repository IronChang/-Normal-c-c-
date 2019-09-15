class Solution
{
public:
	bool ispalindrome(string s)
	{
		if (s.empty())
		{
			return true;
		}
		int begin = 0;
		int end = s.size() - 1;
		char* p = (char*)s.c_str();

		while (begin < end)
		{
			// ��ǰ������һ�������ַ�������ĸ

			while (begin != end)
			{

				if (IsNumberOrLetter(s[begin]))

					break;

				++begin;
			}

			// �Ӻ���ǰ��һ�������ַ�������ĸ

			while (begin < end)
			{

				if (IsNumberOrLetter(s[end]))

					break;

				--end;
			}

			if (begin < end)
			{

				// ���start��endλ���ַ��Ƿ���� �����Ƿ����ִ�С�����

				if ((s[begin] + 32 - 'a') % 32 != (s[end] + 32 - 'a') % 32)

					return false;

				++begin;

				--end;
			}
		}

		return true;
	}

	bool IsNumberOrLetter(char c)
	{

		if (c >= '0' && c <= '9' ||

			c >= 'a' && c <= 'z' ||

			c >= 'A' && c <= 'Z')
		{

			return true;
		}

		return false;
	}
};

//�ַ������
#include <algorithm>
class Solution {
public:
int LSize = num1.size();

int RSize = num2.size();


// �Գ��ַ�����Ϊ�ⲿѭ��

if (LSize < RSize)
{

	num1.swap(num2);

	swap(LSize, RSize);
}


string strRet;

strRet.reserve(LSize + 1);


char cRet = 0;

char cstep = 0;


for (size_t i = 0; i < LSize; ++i)
{

	cRet = num1[LSize - i - 1] - '0' + cstep;

	cstep = 0;


	if (i < RSize)
	{

		cRet += num2[RSize - i - 1] - '0';
	}


	if (cRet >= 10)
	{

		cRet -= 10;

		cstep = 1;
	}


	strRet += cRet + '0';
}


if (cstep)

strRet += '1';


reverse(strRet.begin(), strRet.end());


return strRet;
 }
};
