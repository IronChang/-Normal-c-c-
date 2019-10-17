#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<algorithm>
#include<assert.h>
using namespace std;

class string1
{
public:
	typedef char* iterator;
	string1(const char* str = "")
	{
		_size = strlen(str);
		_capacity = _size;
		_str = new char[_capacity + 1];
		strcpy(_str, str);
	}
	void Swap(string1& s)
	{
		swap(this->_str, s._str);
		swap(this->_size, s._size);
		swap(this->_capacity, s._capacity);
	}
	string1(const string1& s)
		:_str(nullptr)
		, _size(0)
		, _capacity(0)
	{
		string1 tmp(s._str);
		Swap(tmp);
	}
	string1& operator=(string1 s)
	{
		this->Swap(s);
		return *this;

	}
	~string1()
	{
		if (_str != nullptr)
		{
			delete[] _str;
			_str = nullptr;
			_size = _capacity = 0;
		}
	}

	iterator begin()
	{
		return _str;
	}
	iterator end()
	{
		return _str + _size;
	}

	size_t size() const
	{
		return _size;
	}
	size_t capacity() const
	{
		return _capacity;
	}
	bool empty() const
	{
		return _size == 0;
	}
	void reserve(size_t newcapacity)
	{
		//���newcapacity����__capacity������
		char* str = new char[newcapacity + 1];
		strcpy(str, _str);

		//�ͷ�ԭ���Ŀռ�
		delete[] _str;
		_str = str;
		_capacity = newcapacity;


	}
	void resize(size_t newsize, char ch = '\0')
	{
		if (newsize > _size)//��ǰnewsize��������_size
		{
			if (newsize > _capacity)//������������
			{
				reserve(newsize);
			}

			memset(_str + _size, ch, newsize - _size);
		}

		_size = newsize;
		_str[newsize] = '\0';
	}

	void push_back(char ch)
	{
		if (_size == _capacity)
		{
			_capacity = _capacity == 0 ? 16 : 2 * _capacity;
			reserve(2 * _capacity);
		}
		_str[_size] = ch;
		++_size;
		_str[_size] = '\0';
	}
	void pop_back()
	{
		assert(_str != nullptr);
		--_size;
	}
	void append(const char* str)
	{
		size_t len = strlen(str);
		if (_size + len > _capacity)
		{
			reserve(_size + len);
		}
		strcpy(_str + _size, str);
		_size += len;
	}
	string1& operator+=(char n)
	{
		push_back(n);
		return *this;
	}
	string1 & operator+=(const char* str)
	{
		append(str);
		return *this;
	}
	size_t find(const char* str)
	{
		size_t index_str = 0;
		//ѭ���˳�������Ҫô���ҵ��ˣ�Ҫô���ǲ��ҵ��˽�βҲû���ҵ�
		while (_str[index_str] != '\0') {
			if (_str[index_str] == *str) {
				//��ͷ���ַ������
				//����ƥ��Ĳ�����
				size_t find_index = index_str;
				size_t str_index = 0;
				while (1) {
					//������������ַ���str���ͱ�ʾ�ҵ���
					if (str[str_index] == '\0') {
						//��strΪNUL��ʱ�򣬾ͱ�ʾƥ�䣬ֱ�ӷ����±�
						return index_str;
					}
					//�������Ⱦͽ���ѭ��
					if (_str[find_index] != str[str_index]) {
						break;
					}
					find_index++;
					str_index++;
				}//ѭ������
			}//��ʾ��ƥ����
			//�������Ⱦͼ�����ǰ����
			index_str++;
		}
		return -1;
	}
	size_t find(char ch)
	{
		assert(_str != nullptr);
		size_t index = 0;
		while (_str[index] != ch)
		{
			++index;
		}
		return index+1;
	}
	void insert(size_t pos, char ch)
	{
		assert(_str != nullptr);

	}
	void insert(size_t pos, const char* str);
	char& operator[](size_t pos)
	{
		assert(pos < _size);
		return _str[pos];
	}
	
private:
	char* _str;
	size_t _size;
	size_t _capacity;
}; 

void test()
{
	string1 s1("hello");
	string1 s2(s1);
	//s2.pop_back();
	s1.push_back('k');
	s1.append("fuck you");
	s2 += " i love you";
	s1.push_back(' ');
	s1.pop_back();
	cout << s2.find("you") << endl;
	cout << s1.find('o') << endl;
	
	
	//s2.~string1();
	//s1.resize(3, 'm');
	//s1.reserve(10);
	for (size_t i = 0; i < s1.size(); ++i)
	{
		cout << s1[i] << " ";
	}
	cout << endl;

	string1::iterator it = s2.begin();
	while (it != s2.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;
}

int main()
{
	test();
	system("pause");
	return 0;

}
