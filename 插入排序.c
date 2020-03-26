void InsertSort(int* array, int size)
{
	for (int i = 1; i < size; i++)
	{
		int key = array[i];
		int end = i - 1;

		while (end >= 0 && key < array[end])
		{
			array[end+1] = array[end];
			--end;
		}
		array[end+1] = key;
	}
}

void ShellSort(int *array, int size)
{
	int gap = size;
	while (gap >= 1)
	{
		gap = gap / 3 + 1;
		for (int i = 0; i < size; i+=gap)
		{
			int key = array[i];
			int end = i - gap;

			while (end >= 0 && key < array[end])
			{
				array[end + gap] = array[end];
				end -= gap;
			}
			array[end + gap] = key;
		}
		gap--;
	}
}

void printarray(int* array, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << array[i]<<" ";
	}
	cout << endl;
}
int main()
{
	int array[] = { 1, 5, 8, 6, 3, 4, 7, 8, 9, 2, 1, 4 };
	printarray(array, sizeof(array) / sizeof(array[0]));
	ShellSort(array, sizeof(array) / sizeof(array[0]));
	printarray(array, sizeof(array) / sizeof(array[0]));

	system("pause");
		return 0;
}
