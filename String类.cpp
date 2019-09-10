#include<iostream>
#include<string>
using namespace std;


void teststring()
{
	string s1;//构造空的string类对象s1 
	string s2("hello bit");//用c格式字符串构造string类对象s2 
	string s3(10,'a');//用10个字符‘a ’构造string类对象s3 
	string s4(s2);//拷贝构造s4 
	string s5(s3,5);//用s3中前5个字符构造string对象s5 
}

void teststring2()
{
	//注意：string类对象支持直接用cin和cout进行输入和输出 
	string s("hello bit!!!");
	cout<<s.length()<<endl;//返回字符串有效字符长度 
	cout<<s.size()<<endl;//同上 
	cout<<s.capacity()<<endl;//返回空间总大小 
	//cout<<s<<endl;
	
	
	//将s中的字符串清空，注意清空时只是将size清0，不改变底层空间大小
	s.clear();
	cout<<s.size()<<endl;
	cout<<s.capacity()<<endl; 
	
	
	//将s中有效字符个数增加到10个，多出位置用’a’进行填充
    s.resize(10,'a');
	cout<<s.size()<<endl;
	cout<<s.capacity()<<endl; 
	
	//将s中有效字符个数增加到15个，多出位置用缺省值'\0' 
	s.resize(15);
	cout<<s.size()<<endl;
	cout<<s.capacity()<<endl;
	
	//将s中有效字符个数缩小到5个
	s.resize(5);
	cout<<s.size()<<endl;
	cout<<s.capacity()<<endl;	
}

// string类对象的访问操作  对于const类型 和  非const类型
//const类对象调用： char& operator[] ( size_t pos )
//非const类对象调用： const char& operator[] ( size_t pos ) const


void teststring3()
{
	string s1("hello bit");
	const string s2("hello bit");
	cout<<s1<<" "<<s2<<endl;
	cout<<s1[0]<<" "<<s2[0]<<endl;
	
	s1[0] = 'H';
	cout<<s1<<endl; 
	
	size_t i = 0;
	for(i;i<s1.size();++i)
	{
		cout<<s1[i]<<endl;
	}
	
	//s2[0] = 'h';代码会运行失败，因为const类型对象不能修改 	
}

//string类对象的修改操作
void teststring4()
{
	string str;
	string s1("family");
	cout << str.size() << endl;

	str.append("hello");//在str后追加一个字符"hello"
	str.push_back(' ');//在str后插入空格 
	str += 'b';
	str.push_back(' ');//在str后插入空格 
	str += "it";
	str.push_back(' ');//在str后插入空格 
	str += s1;
	cout << str << endl;
	cout << str.c_str() << endl;//以C语言的方式打印字符串
} 

int main()
{
	teststring3(); 	
	return 0;
} 
