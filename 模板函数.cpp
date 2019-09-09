#include<iostream>
#include<assert.h>
using namespace std;

//��ͨʵ��һ����������
void swap1(int& left,int& right)
{
	int temp = left;
	left = right;
	right = temp;
} 

void swap2(double& left,double& right)
{
	double temp = left;
	left = right;
	right = temp;
}

void swap3(char& left,char& right)
{
	char temp = left;
	left = right;
	right = temp;
}
//��ͨ����ʵ�ֽ�������Ҫ���͸ı��Ҫ����ʵ�ִ��븴���ʱȽϵ�

//���ͱ�̣���д�������޹ص�ͨ�ô��룬ʱ���븴�õ�һ���ֶ�
//ģ��  ��  ����ģ��   ��ģ��

//����ģ��
//ģ����� template<typename T1,typename T2,......>
//         or  template<class T>  ������� 
//����ֵ���� ������(�������){}

//��������ģ��

template<typename T>
void Swap(T& left,T& right)
{
	T temp = left;
	left = right;
	right = temp;	
}

// ����ģ���ʵ���� 
//�ò�ͬ������ʹ�ú���ģ��ʱ����Ϊ����ģ���ʵ������
//ģ�����ʵ���������ַ�ʽ����ʽ����ʽ ��

//��ʽʵ�������ñ���������ʵ������ģ�����ʵ������
template<class T>
T Add(const T& left,const T& right)
{
	return left + right;
} 

//��ʽʵ������ �ں�������<>��ָ��ģ�������ʵ������
 

 //ע�⣺������Ͳ�ƥ�䣬�������������ʽ����ת������������򱨴�
  
  
//��ģ��
//template<class T1,class T2,.....,class Tn>
//class ��ģ����
//{// ��Ա����}��

//��̬˳���
template<class T>
class Vector
{
	public:
		 Vector(size_t capacity = 10)
		 :_pDate(new T[capacity])
		 ,_size(0)
		 ,_capacity(capacity)
		 {}
		 
		 //��Ϊ���ڿռ��������ͷţ�����Ҫ�Լ�д��������
		 ~ Vector()
		 {
		 		if(_pDate)
	{
		delete[] _pDate; 
	}
		 }
		 
		 void pushback(const T& date)
		 {
		 	_pDate[_size++] = date;
		 }
		 
		 void popback()
		 {
		 	--_size;
		 } 
		 
		 size_t size()
		 {
		 	return _size;
		 }
		 
		 T& operator[](size_t pos)
		 {
		 	assert(pos<_size);
		 	return _pDate[pos];
		 }
	private:
		T* _pDate;
		size_t _size;
		size_t _capacity;	
};

//��ģ��ʵ����
//��ģ��ʵ������Ҫ����ģ�����ֺ��<>��Ȼ��ʵ���������ͷ���<>�м��ɣ���ģ�����ֲ����������࣬��ʵ�����Ľ�������������ࡣ 

int main()
{
	int a = 10, b = 20;
    double c = 10.0, d = 20.0;
	//Swap(a,b);
	//c = Add(a,b);
	//printf("%d\n",Add(a,b));//������ʵ�������Զ�����Ϊ�β����� 
	//printf("%d\n",Add(c,d));//ͬ��
	//printf("%d\n",Add(a,c));//����ʵ���Ƶ�ʱ��һ��Ϊint���ڶ���Ϊdouble����ģ����ֻ��һ���������Ǳ������޷�ʶ�𣬾ͻᱨ��
	//������������������������1���û��Լ���ǿ��ת�� 2��������ʽʵ���� 
	//printf("%d\n",Add(a,(int)b));//�û�ǿ��ת�� 
	//printf("%d\n",Add<int>(a,b));//��ʽʵ���� 
	Vector<int> s1;
	s1.pushback(1);
	s1.pushback(2);
	s1.pushback(3);
	
	size_t i = 0;
	for(i;i<s1.size();++i)
	{
		cout<<s1[i]<<" ";
	}
	cout<<endl;
	return 0;
 } 
 




