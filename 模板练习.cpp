template<class T>
T ADD(const T& left,const T& right)
{
	return left+right;
}

//��ʽʵ���� :�ñ���������ʵ������ģ�����ʵ������ 
int main()
{
	int a1 = 10,a2 = 20;
	double d1 = 10.0,d2 = 20.0;
	ADD(a1,a2);
	ADD(d1,d2);
	ADD(a1,d1);//����ᱨ����Ϊ����������ͬ����ģ��ʵ����ʧ����Ϊģ���
	//�����б���ֻ��һ��T��
	//���������1���û��Լ�����ǿ��ת�� 2��ʹ����ʽʵ����
	ADD(a1,(int)d2);//�û��Լ�����ǿ��ת��
	return 0;
}

//��ʽʵ���� : �ں��������<>��ָ��������ʵ������ 
int main()
{
	int a = 10;
	double = 20.0;
	
	//��ʽʵ����
	ADD<int>(a,b); 
	return 0;
} 

//ר�Ŵ���int�ļӷ���ģ�庯��
int  add(int a,int b)
{
	return  a+b;
} 

//ͨ�üӷ���������ģ��
template<class T>
T add(T a,T b)
{
	return left+right;
} 
int main()
{
	add(1,2);//��Ǻ���ģ��ƥ�䣬����������Ҫ�ػ� 
	add<int>(1,2);//���ñ������ػ�add�汾 
}


// ר�Ŵ���int�ļӷ�����
int Add(int left, int right)
{
    return left + right;
}
// ͨ�üӷ�����
template<class T1, class T2>
T1 Add(T1 left, T2 right)
{
    return left + right;
}
void Test()
{
    Add(1, 2); // ��Ǻ���ģ��������ȫƥ�䣬����Ҫ����ģ��ʵ���� 
    Add(1, 2.0); // ģ�庯���������ɸ���ƥ��İ汾������������ʵ�����ɸ���ƥ���Add����
}

template<class T>
class vevtor
{
	public:
		vector<size_t capacity = 10>//���캯�� 
		:_pdate(new T[capacity])
		,_size(0)
		,_capacity(capacity)
		{ }
		//ʹ������������ʾ���������������������ⶨ��
		~vector();
		
		void pushback(const T& date)//β�� 
		{
			_pdate[_size++] = date;
		} 
		
		void popback()//βɾ 
		{
			--_size;
		}
		
		size_t size()//��˳�����Ԫ�ظ��� 
		{
			return _size;
		}
		
		T& operator[](size_t pos)//����[] 
		{
			assert(pos<_size);
			return _pdate[pos];
		}
		
	private:
		T* _pdate;
		size_t _size;
		size_t _capacity;	
}; 


template<class T>
vector<T> :: ~vector()
{
	if(_pdate)
	{
		delete[] _pdatee;
	}
}































