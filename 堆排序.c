void AdjustDown(int *array,size_t size,int parent)
{
	//排升序，建大堆
	//排降序，建小堆
	//leftchild = parent * 2 + 1;
	//rightchild = parent * 2 + 2;
	int child = parent * 2 + 1;
	while (child < size)
	{
		if (child + 1 < size&&array[child + 1] > array[child])//大堆
		{
			++child;
		}

		if (array[child]>array[parent])
		{
			Swap(&array[child], &array[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}

	}
}

void HeapSort(int *array, int size)
{
	int end = size - 1;
	//建堆
	for (int i = (size - 2) / 2; i >= 0; i--)
	{
		AdjustDown(array, size, i);
	}

	//排序
	while (end > 0)
	{
		Swap(&array[0], &array[end]);
		AdjustDown(array, end, 0);
		--end;
	}
}
