template<class T>
T Add(const T& left, const T& right)
{
	cout << "模板特化" << endl;
	return left + right;
	
}

int Add(const int& left, const int& right)
{
	cout << "普通函数" << endl;
	return left + right;
}

template<class T>
class Vector
{
public:
	Vector(size_t Capacity = 2) : //构造函数
	_p(new T[Capacity])
	, size(0)
	, capacity(Capacity)
	{
	}

	void CheakCapacity()//检测容量
	{
		if (size == capacity)//内存面扩容
		{
			capacity *= 2;
			_p = (T*)realloc(_p, sizeof(T)*(2 * capacity));		
		}
	}

	void pushback(const T& data)
	{
		CheakCapacity();
		_p[size++] = data;
	}

	void Popback()
	{
		size--;
	}

	size_t Size()
	{
		return size;
	}
	T& operator[](size_t pos)
	{
		assert(pos < size);
		return _p[pos];
	}
	~Vector();
private:
	T* _p;
	size_t size;//有效元素个数
	size_t capacity;//容量
};

template<class T,size_t N  >
class Count
{

};

template <unsigned int n>
struct Sum_Solution
{
	enum Value
	{
		N = Sum_Solution<n - 1>::N + n;

	};

};
template<>
struct Sum_Solution<1>
{
	enum Value
	{
		N = 1
	};

};


template<class T>
Vector<T>::~Vector()
{
	cout << "!Vector" << endl;
	if (_p)
	{
		delete[] _p;
		size = capacity = 0;
	}
}


template<class T>
bool equal(T& left, T& right)
{
	return left == right;
}

template<>
bool equal<char*>(char*& left, char*& right)
{

}
void testppp()
{
	char* p1 = "hello";
	char* p2 = "world";

	if (equal(p1, p2))
	{

	}
	else
	{

	}
}

template<class T1, class T2>
class Data
{
public:
	Data() { cout << "Data<T1, T2>" << endl; }
private:
	T1 _d1;
	T2 _d2;
};
template<>
class Data<int, char>
{
public:
	Data() { cout << "Data<int, char>" << endl; }
private:
	T1 _d1;
	T2 _d2;
};

int main()
{
	//volatile const int a = 0;
	//int* p = (int*)&a;
	//*p = 20;
	//cout << a << endl;

	//void* p = new char[0xfffffffful];
	//cout << p << endl;

	//int a = 10, b = 10;
	//double c = 10.9;
	//Add(a, b);
	//Add(a, c);
	//Add<int>(a, b);

	//Vector<int> vc;
	//vc.pushback(1);
	//vc.pushback(2);
	//vc.pushback(3);
	//vc.pushback(4);
	//vc.~Vector();

	testppp();
	system("pause");
	return 0;
}
