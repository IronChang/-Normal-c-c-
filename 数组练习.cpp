#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

void test()
{


	int arr1[10] = { 1, 2, 3 };
	int arr2[] = { 1, 2, 3, 4 };
	int arr3[5] = { 1,2,3,4,5 };
	char arr4[3] = { 'a', 98, 'c' };
	char arr5[] = { 'a', 'b', 'c' };
	char arr6[] = "abcdef";


	int arr[10] = { 0 };
	int len = sizeof(arr) / sizeof(arr[0]);

	int i = 0;
	for (i = 0; i < 10; i++)
	{
		arr[i] = i;
	}

	for (i = 0; i < 10; i++)
	{
		printf("%d ", arr[i]);
	}
	
}
void test2()
{
	//int arr1[][] = { { 2, 3 }, { 4, 5 } };
	//char arr2[3][5];
	//double arr3[2][4];
	//int arr4[][3]{{ 2, 3 }, { 4, 5 }};;
	////int arr[2][];   二维数组不允许出现这种数组创建


	int arr[3][4] = {0};
	for (int i = 0; i < 3; i++){
		for (int j = 0; j < 4; j++){
			arr[i][j] = i * 4 + j;
		}
	}


	for (int i = 0; i < 3; i++){
		for (int j = 0; j < 4; j++){
			printf("&arr[%d][%d] = %p\n", i, j, &arr[i][j]);
		}
		printf("\n");
	}
}
void bubble_sort(char arr[])
{
	int len = sizeof(arr) / sizeof(arr[0]);
}
void test3()
{
	char arr[] = { 3, 1, 7, 5, 8, 9, 0, 2, 4, 6 };
	bubble_sort(arr);
}
void test4()
{
	int arr[10] = { 0 };
	int i = 0;
	for (i = 0; i<sizeof(arr) / sizeof(arr[0]); ++i)
	{
		printf("&arr[%d] = %p\n", i, &arr[i]);
	}
}

void test5()
{
	int arr1[3][4] = { 1, 2, 3, 4 };
	int arr2[3][4] = { { 1, 2 }, { 4, 5 } };
	int arr3[][4] = { { 2, 3 }, { 4, 5 } };

	int a1[2][2] = { { 1 },{ 2 } };

	int a2[][2] = { 1, 2, 3, 4 };

	int a3[2][2] = { { 1 },2, 3 };

	//int a4[2][] = { { 1,2 },{ 3, 4 } };
}

void test6()
{
	int arr[3][4];
	int i = 0;
	for (i = 0; i<3; i++)
	{
		int j = 0;
		for (j = 0; j<4; j++)
		{
			printf("&arr[%d][%d] = %p\n", i, j, &arr[i][j]);
		}
	}
}

int main()
{

	test6();

	system("pause");
	return 0;
}