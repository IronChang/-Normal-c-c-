#include<iostream>
using namespace std;


//string类的深浅拷贝 
class string1
{
	public:
		string(const char* str = "")//构造函数 
		{
			//构造函数string类对象时，如果传递nullptr指针，认为程序非法，此处断言						  
			  _str = new char[strlen(str)+1];
			  strcpy(_str,str);
		}
		
		~string()//析构函数 
		{
			if(_str)
			{
				delete[] _str;
				_str = nullptr;
			 } 	
		}
	private:
		char* _str;
};

class string2
{
	public:
		string2(const char* str = "")
		{
			if(nullptr == str)
			{
				assert(false);
				return ;
			}
			_str = new char[strlen(str)+1];
			strcpy(_str,str);
		}
		
		string2(const string& s)
		:_str(new char[strlen(s._str)+1])
		{
			strcpy(_str,s._str);	
		}
		
		string2& operator=(const string2& s)
		{
			if(this != &s)
			{
				char* pstr = new char[strlen(s._str)+1];
				strcpy(pstr,s._str);
				delete[] _str;
				_str = pstr;
			}
			return *this;
		}
		
		~string2()
		{
			if(_str)
			{
				delete[] _str;
				_str = nullptr;
			}
		}
	private:
		char* _str;
}; 

void test()
{
	string s1("hello bit!!!");
	string s2(s1);//调用默认拷贝构造函数
	cout<<s1<<endl;
	cout<<s2<<endl; 
	 
}

class string3
{
	public:
		string3(const char* str = "")
		{
			if(nullptr == str)
			str = "";
			
			_str = new char[strlen(str)+1];
			strcpy(_str,str);
		}
		
		string3(const string3& s)
		:_str(nullptr)
		{
			string3 strtmp(s._str);
			swap(_str,strtmp);	
		}
		
		string3& operator=(string3 s)
		{
			swap(_str,s._str);
			return *this;	
		} 
		
		~string3()
		{
			if(_str)
			{
				delete[] _str;
				_str = nullptr;
			}
		}
	private:
		char* _str;
};
int main()
{
	test();
	return 0;
 } 
