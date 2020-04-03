int GetMindIndex(int* a, int left, int right)
{
	int mid = left + (right - left) / 2;
	if (a[left] < a[mid])
	{
		if (a[mid] < a[right])
			return mid;
		else if (a[left] > a[right])
			return left;
		else
			return right;
	}
	else
	{
		if (a[right] < a[mid])
			return mid;
		else if (a[right] < a[left])
			return left;
		else
			return right;
	}
}

int PartSort1(int* arr,int left,int right)//前后指针法
{
	int mid = GetMindIndex(arr, left, right);
	Swap(&arr[mid], &arr[right]);

	int cur = left;
	int prev = left - 1;
	int key = arr[right];

	while (cur < right)
	{
		if (arr[cur] < key && ++prev != cur)
		{
			Swap(&arr[prev], &arr[cur]);
		}
		++cur;
	}
	++prev;
	Swap(&arr[prev], &arr[right]);
	return prev;
}

int PartSort2(int* arr, int left, int right)//左右指针法
{
	int mid = GetMindIndex(arr, left, right);
	Swap(&arr[mid], &arr[right]);

	int key = arr[right];//基准值
	int key_index = right;

	while (left < right)//升序 left找大，right找小
	{
		while (left < right && arr[left] <= key)
		{
			++left;
		}
		while (left < right && arr[right] >= key)
		{
			--right;
		}
		Swap(&arr[left], &arr[right]);	
	}
	Swap(&arr[left], &arr[key_index]);
	return left;
}

int PartSort3(int* arr, int left, int right)//挖坑法
{
	int mid = GetMindIndex(arr, left, right);
	Swap(&arr[mid], &arr[right]);

	int key = arr[right];

	while (left < right)
	{
		while (left < right &&arr[left] <= key)
		{
			++left;
		}
		arr[right] = arr[left];

		while (left < right&&arr[right] >= key)
		{
			--right;
		}
		arr[left] = arr[right];
	}
	arr[left] = key;
	return left;
}

void QuickSort(int* arr, int left,int right)//递归实现
{
	if (left >= right)
		return;

	if ((right - left + 1) > 10)
	{
		int key_index = PartSort2(arr, left, right);
		QuickSort(arr, left, key_index - 1);
		QuickSort(arr, key_index + 1, right);
	}
	else
	{
	
		InsertSort(arr, (right - left + 1));
	}
}

#include<stack>//利用数据结构栈模拟函数递归时栈帧

void QucikSortNonR(int* arr, int left, int right)//非递归实现
{
	
	stack<int> st;
	st.push(left);
	st.push(right);

	while (!st.empty())
	{
		int end = st.top();
		st.pop();
		int begin = st.top();
		st.pop();

		int mid = PartSort1(arr, begin, end);

		if (begin < mid - 1)
		{
			st.push(begin);
			st.push(mid - 1);
		}

		if (mid + 1 < end)
		{
			st.push(mid + 1);
			st.push(end);
		}
	}
}
