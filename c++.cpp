#include<iostream>
 
 
 
/*namespace N1
{
 	int a;
 	
 	int Add(int left,int right)
 	{
 		return left + right;
	 }
} 

namespace N2
{
	int a;
	int b;
	int Add(int left,int right)
	{
		return left + right;
	}
	namespace N3
	{
		int c;
		int d;
		int sub(int left,int right)
		{
			return left - right;
		}
	}
}


namespace N3
{
	int mul(int left,int right)
	{
		return left * right;
	}
}*/


/*namespace N
{
	int a= 10;
	int b = 20;
	
	int Add(int left,int right)
	{
		return left + right;
	}
	
	int sub(int left,int right)
	{
		return left - right;
	}
}

using N::b;
int main()
{
	printf("%d\n",N::a);
    printf("%d\n",b);
    printf("%d\n",Add(50,40));
	return 0;
}
*/

using namespace std;
void Func_1(int a = 10,int b = 20,int c = 30)
{
	cout<<"a="<<a<<endl;
	cout<<"b="<<b<<endl;
	cout<<"c="<<c<<endl;
}

void Func_2(int a,int b = 10,int c = 20)
{
	cout<<"a="<<a<<endl;
	cout<<"b="<<b<<endl;
	cout<<"c="<<c<<endl;
}

int main()
{
	//全缺省参数
	//Func(); 
	//半缺省参数
	Func2(); 
	return 0;
}



