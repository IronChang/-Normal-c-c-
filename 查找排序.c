#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<assert.h>
#include<string.h>
#include<Windows.h>

int binarysearch(int arr[],int len,int x)
{
	assert(arr);

	//×ó±ÕÓÒ¿ª
	int begin = 0;
	int end = len - 1;
	int mid = begin + ((len - begin) >> 1);

	while (begin < end)
	{
		if (arr[mid]>x)
		{
			end = mid - 1;
		}
		else if (arr[mid] < x)
		{
			begin = mid + 1;
		}
		else
		{
			return mid;
		}
	}
	return -1;
}

//int main()
//{
//	int arr[5] = { 1, 2, 3, 4, 5 };
//	printf("%d\n", binarysearch(arr, 5, 3));
//
//	system("pause");
//	return 0;
//}


//Ã°ÅÝÅÅÐò

void bubblesort(int arr[],int len)
{
	int i = 0;
	int j = 0;

	for (i; i < len - 1; i++)
	{
		for (j = i + 1; j < len - 1 - i; j++)
		{
			if (arr[j]>arr[j+1])
			{
				int tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
	}
}

int main()
{
	int arr[10] = { 13, 51, 74, 96, 64, 41, 86, 37, 19, 58 };
	bubblesort(arr, 10);
	for (int i = 0; i < 10; i++)
	{
		printf("%d    ", arr[i]);
	}
	printf("\n");

	system("pause");
	return 0;
}
