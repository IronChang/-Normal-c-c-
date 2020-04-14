//C++11中---unique_ptr---防拷贝以及赋值
template<class T>
class Unique_ptr
{
public:
	Unique_ptr(T* ptr)
	:_ptr(ptr)
	{
	}

	~Unique_ptr()
	{
		if (_ptr)
		{
			cout << "delete:" << _ptr << endl;
			delete _ptr;
		}
	}

	T& operator*()
	{
		return *_ptr;
	}

	T* operator->()
	{
		return _ptr;
	}
private:
	//C++11 防止拷贝的方法 delete
	//Unique_ptr(Unique_ptr<T>& up) = delete;
	//Unique_ptr<T>& operator =(Unique_ptr<T>& up) = delete;

	//C++98 防止拷贝的方法 只声明不定义  + 声明为private
	Unique_ptr(Unique_ptr<T>& up)
	{}
	Unique_ptr<T>& operator =(Unique_ptr<T>& up)
	{}
private:
	T* _ptr;
};
