#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

void bubble_sort(int arr[], int sz)
{
	int i = 0;
	int j = 0;

	for (i = 0; i < sz - 1; i++)
	{
		for (j = 0; j < sz - i-1; j++)
		{
			if (arr[j]>arr[j + 1])
			{
				int temp = 0;
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j+1]=temp;
			}
		}
	}

}

int main()
{
	int a[] = { 9, 8, 7, 6, 5, 4, 3, 2, 1 };
	int sz = sizeof(a) / sizeof(a[0]);
	for (int i = 0; i < sz; i++)
	{
		printf("%d", a[i]);
	}
	bubble_sort(a, sz);
	printf("\n");
	for (int i = 0; i < sz; i++)
	{
		printf("%d", a[i]);
	}
	printf("\n");
	system("pause");
	return 0;
}