void BubbleSort(int* arr, size_t n)
{
	int end = n;
	while (end > 0)
	{
		for (int i = 0; i < end; i++)
		{
			if (arr[i-1] > arr[i])
			{
				Swap(&arr[i - 1], &arr[i]);
			}
		}
		--end;
	}
}