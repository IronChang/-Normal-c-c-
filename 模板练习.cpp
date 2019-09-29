template<class T>
T ADD(const T& left,const T& right)
{
	return left+right;
}

//隐式实例化 :让编译器根据实参推演模板参数实际类型 
int main()
{
	int a1 = 10,a2 = 20;
	double d1 = 10.0,d2 = 20.0;
	ADD(a1,a2);
	ADD(d1,d2);
	ADD(a1,d1);//这里会报错，因为两个参数不同导致模板实例化失败因为模板的
	//参数列表中只有一个T。
	//解决方法：1：用户自己进行强制转换 2：使用显式实例化
	ADD(a1,(int)d2);//用户自己进行强制转换
	return 0;
}

//显式实例化 : 在函数名后的<>中指定参数的实际类型 
int main()
{
	int a = 10;
	double = 20.0;
	
	//显式实例化
	ADD<int>(a,b); 
	return 0;
} 

//专门处理int的加法非模板函数
int  add(int a,int b)
{
	return  a+b;
} 

//通用加法函数函数模板
template<class T>
T add(T a,T b)
{
	return left+right;
} 
int main()
{
	add(1,2);//与非函数模板匹配，编译器不需要特化 
	add<int>(1,2);//调用编译器特化add版本 
}


// 专门处理int的加法函数
int Add(int left, int right)
{
    return left + right;
}
// 通用加法函数
template<class T1, class T2>
T1 Add(T1 left, T2 right)
{
    return left + right;
}
void Test()
{
    Add(1, 2); // 与非函数模板类型完全匹配，不需要函数模板实例化 
    Add(1, 2.0); // 模板函数可以生成更加匹配的版本，编译器根据实参生成更加匹配的Add函数
}

template<class T>
class vevtor
{
	public:
		vector<size_t capacity = 10>//构造函数 
		:_pdate(new T[capacity])
		,_size(0)
		,_capacity(capacity)
		{ }
		//使用析构函数演示：在类内面声明，在类外定义
		~vector();
		
		void pushback(const T& date)//尾插 
		{
			_pdate[_size++] = date;
		} 
		
		void popback()//尾删 
		{
			--_size;
		}
		
		size_t size()//求顺序表中元素个数 
		{
			return _size;
		}
		
		T& operator[](size_t pos)//重载[] 
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































