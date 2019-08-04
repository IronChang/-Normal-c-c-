#include<iostream>
#include<string.h>
using namespace std;

class String
{
	public:
		String(char* str = "")
		{
			if(str == NULL)
			_str = "";
			
			_str = (char*)malloc(strlen(str)+1);
			strcpy(_str,str);
		}
	private:
		char* _str;

};

int main()
{
	return 0;
}
