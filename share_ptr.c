//C++11----share_ptr----引用计数
template<class T>
class Share_ptr
{
public:
	Share_ptr(T* ptr = nullptr)
		:_ptr(ptr)
		, _RefCount(new int(1))
		, _pMutex(new mutex)
	{
	}

	~Share_ptr()
	{
		ReleaseRef();
	}

	Share_ptr(const Share_ptr<T>& sp)
		:_ptr(sp._ptr)
		, _RefCount(sp._RefCount)
		, _pMutex(sp._pMutex)
	{
		AddRef();
	}

	Share_ptr<T>& operator=(const Share_ptr<T>& sp)
	{
		if (_ptr != sp._ptr)
		{
			ReleaseRef();
			_ptr = sp._ptr;
			_RefCount = sp._RefCount;
			_pMutex = sp._pMutex;
			AddRef();
		}
		return *this;
	}

	void AddRef()
	{
		_pMutex->lock();
		++(*_RefCount);
		_pMutex->unlock();
	}

	void ReleaseRef()
	{
		bool deleteflag = false;
		_pMutex->lock();
		if (--(*_RefCount) == 0 && _ptr)
		{
			cout << "Delete:" << _ptr << endl;
			delete _ptr;
			delete _RefCount;
			deleteflag = true;
		}
		_pMutex->unlock();

		if (deleteflag == true)
		{
			delete _pMutex;
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

	T* GetPtr() const
	{
		return _ptr;
	}
private:
	T* _ptr;
	int* _RefCount;
	mutex* _pMutex;
};