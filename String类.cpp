#include<iostream>
#include<string>
using namespace std;


void teststring()
{
	string s1;//����յ�string�����s1 
	string s2("hello bit");//��c��ʽ�ַ�������string�����s2 
	string s3(10,'a');//��10���ַ���a ������string�����s3 
	string s4(s2);//��������s4 
	string s5(s3,5);//��s3��ǰ5���ַ�����string����s5 
}

void teststring2()
{
	//ע�⣺string�����֧��ֱ����cin��cout������������ 
	string s("hello bit!!!");
	cout<<s.length()<<endl;//�����ַ�����Ч�ַ����� 
	cout<<s.size()<<endl;//ͬ�� 
	cout<<s.capacity()<<endl;//���ؿռ��ܴ�С 
	//cout<<s<<endl;
	
	
	//��s�е��ַ�����գ�ע�����ʱֻ�ǽ�size��0�����ı�ײ�ռ��С
	s.clear();
	cout<<s.size()<<endl;
	cout<<s.capacity()<<endl; 
	
	
	//��s����Ч�ַ��������ӵ�10�������λ���á�a���������
    s.resize(10,'a');
	cout<<s.size()<<endl;
	cout<<s.capacity()<<endl; 
	
	//��s����Ч�ַ��������ӵ�15�������λ����ȱʡֵ'\0' 
	s.resize(15);
	cout<<s.size()<<endl;
	cout<<s.capacity()<<endl;
	
	//��s����Ч�ַ�������С��5��
	s.resize(5);
	cout<<s.size()<<endl;
	cout<<s.capacity()<<endl;	
}

// string�����ķ��ʲ���  ����const���� ��  ��const����
//const�������ã� char& operator[] ( size_t pos )
//��const�������ã� const char& operator[] ( size_t pos ) const


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
	
	//s2[0] = 'h';���������ʧ�ܣ���Ϊconst���Ͷ������޸� 	
}

//string�������޸Ĳ���
void teststring4()
{
	string str;
	string s1("family");
	cout << str.size() << endl;

	str.append("hello");//��str��׷��һ���ַ�"hello"
	str.push_back(' ');//��str�����ո� 
	str += 'b';
	str.push_back(' ');//��str�����ո� 
	str += "it";
	str.push_back(' ');//��str�����ո� 
	str += s1;
	cout << str << endl;
	cout << str.c_str() << endl;//��C���Եķ�ʽ��ӡ�ַ���
} 

int main()
{
	teststring3(); 	
	return 0;
} 
