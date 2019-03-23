#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>
#include <malloc.h>

//快速排序
//#define BUF_SIZE 10
//void display(int array[], int maxlen)
//{
//	int i;
//
//	for (i = 0; i < maxlen; i++)
//	{
//		printf("%-3d", array[i]);
//	}
//	printf("\n");
//
//	return;
//}
//void swap(int *a, int *b)
//{
//	int temp;
//
//	temp = *a;
//	*a = *b;
//	*b = temp;
//
//	return;
//}
//void quicksort(int array[], int maxlen, int begin, int end)
//{
//	int i, j;
//
//	if (begin < end)
//	{
//		i = begin + 1;  // 将array[begin]作为基准数，因此从array[begin+1]开始与基准数比较！
//		j = end;        // array[end]是数组的最后一位
//
//		while (i < j)
//		{
//			if (array[i] > array[begin])  // 如果比较的数组元素大于基准数，则交换位置。
//			{
//				swap(&array[i], &array[j]);  // 交换两个数
//				j--;
//			}
//			else
//			{
//				i++;  // 将数组向后移一位，继续与基准数比较。
//			}
//		}
//
//		/* 跳出while循环后，i = j。
//		* 此时数组被分割成两个部分  -->  array[begin+1] ~ array[i-1] < array[begin]
//		*                           -->  array[i+1] ~ array[end] > array[begin]
//		* 这个时候将数组array分成两个部分，再将array[i]与array[begin]进行比较，决定array[i]的位置。
//		* 最后将array[i]与array[begin]交换，进行两个分割部分的排序！以此类推，直到最后i = j不满足条件就退出！
//		*/
//
//		if (array[i] >= array[begin])  // 这里必须要取等“>=”，否则数组元素由相同的值时，会出现错误！
//		{
//			i--;
//		}
//
//		swap(&array[begin], &array[i]);  // 交换array[i]与array[begin]
//
//		quicksort(array, maxlen, begin, i);
//		quicksort(array, maxlen, j, end);
//	}
//}
//// 主函数
//int main()
//{
//	int n;
//	int array[BUF_SIZE] = { 12, 85, 25, 16, 34, 23, 49, 95, 17, 61 };
//	int maxlen = BUF_SIZE;
//
//	printf("排序前的数组\n");
//	display(array, maxlen);
//
//	quicksort(array, maxlen, 0, maxlen - 1);  // 快速排序
//
//	printf("排序后的数组\n");
//	display(array, maxlen);
//
//	system("pause");
//	return 0;
//}

////希尔排序
//void shellsort1(int a[], int n)
//{
//	int i, j, gap;
//
//	for (gap = n / 2; gap > 0; gap /= 2) //步长
//	for (i = 0; i < gap; i++)        //直接插入排序
//	{
//		for (j = i + gap; j < n; j += gap)
//		if (a[j] < a[j - gap])
//		{
//			int temp = a[j];
//			int k = j - gap;
//			while (k >= 0 && a[k] > temp)
//			{
//				a[k + gap] = a[k];
//				k -= gap;
//			}
//			a[k + gap] = temp;
//		}
//	}
//}
//
//int main()
//{
//	int arr[] = { 5, 7, 9, 8, 6, 4, 2, 1, 3, 10 };
//	int len = sizeof(arr) / sizeof(arr[0]);
//
//	for (int i = 0; i < len; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//	shellsort1(arr, len);
//	for (int i = 0; i < len; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//    system("pause");
//	return 0;
//}

////归并排序
//void merge(int src[], int des[], int low, int high, int mid)
//{
//	int i = low;
//	int k = low;
//	int j = mid + 1;
//
//	while ((i <= mid) && (j <= high))
//	{
//		if (src[i] < src[j])
//		{
//			des[k++] = src[i++];
//		}
//		else
//		{
//			des[k++] = src[j++];
//		}
//	}
//	while (i <= mid)
//	{
//		des[k++] = src[i++];
//	}
//	while (j <= high)
//	{
//		des[k++] = src[j++];
//	}
//}
//
//void MSort(int src[], int des[], int low, int high, int max_size)
//{
//	int mid = (low + high) / 2;
//	if (low == high)
//	{
//		des[low] = src[low];
//	}
//	else
//	{
//		int mid = (low + high) / 2;
//		int * des_space = (int *)malloc(sizeof(int)* max_size);
//
//		if (NULL != des_space)
//		{
//			MSort(src, des_space, low, mid, max_size);
//			MSort(src, des_space, mid + 1, high, max_size);
//
//			merge(des_space, des, low, high, mid);
//		}
//
//		free(des_space);
//	}
//}
//
//void Meger_Sort(int arr[], int low, int high, int len)
//{
//	MSort(arr, arr, low, high, len);
//}
//
//int main(void)
//{
//	int arr[10];
//
//	for (int i = 0; i<10; i++)  //初始化数据
//	{
//		arr[i] = rand() % 100;  //随机生成数据
//	}
//	printf("排序前:\n");  //打印排序前的数据
//	for (int i = 0; i < 10; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//
//	//开始排序
//	Meger_Sort(arr, 0, 10 - 1, 10);
//
//
//	printf("\n排序后:\n"); //打印排序后的数据
//	for (int i = 0; i < 10; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//	system("pause");
//	return 0;
//}

////堆排序
////堆调整，构建大顶堆，arr[]是待调整的数组，i是待调整的数组
////元素的位置，length是数组的长度
//void HeapAdjust(int arr[], int i, int length)
//{
//	int Child;
//	int temp;
//	for (; 2 * i + 1 < length; i = Child)
//	{
//		//子节点的位置 = 2 * (parent(父结点)) + 1
//		Child = 2 * i + 1;
//		//得到子结点中较大的结点
//		if (Child < length - 1 && arr[Child + 1] > arr[Child])
//			++Child;
//		//如果较大的子结点大于父结点那么把较大的子结点往上移动
//		//替换它的父结点
//		if (arr[i] < arr[Child])
//		{
//			temp = arr[i];
//			arr[i] = arr[Child];
//			arr[Child] = temp;
//		}
//		else
//			break;
//	}
//}
////堆排序算法
//void HeapSort(int arr[], int length)
//{
//	int i;
//	//调整序列的前半部分元素，调整完之后第一个元素
//	//是序列的最大元素，length/2-1是最后一个非叶子结点
//	for (i = length / 2 - 1; i >= 0; --i)
//		HeapAdjust(arr, i, length);
//	//从最后一个元素开始对序列进行调整，不断的缩小调整
//	//的范围直到第一个元素
//	//循环里是把第一个元素和当前的最后一个元素交换
//	//保证当前的最后一个位置的元素是现在这个序列的最大的
//	//不断的缩小调整heap的范围，每一次调整完毕保证第一个
//	//元素是当前序列的最大的元素
//	for (i = length - 1; i > 0; --i)
//	{
//		arr[i] = arr[0] ^ arr[i];
//		arr[0] = arr[0] ^ arr[i];
//		arr[i] = arr[0] ^ arr[i];
//		HeapAdjust(arr, 0, i);						//递归调整
//	}
//}
//
//int main()
//{
//	int i;
//	int num[] = { 1, 9, 5, 10, 6, 8, 7, 2, 3 };
//	printf("待排序的数据是：\n");
//	for (i = 0; i < sizeof(num) / sizeof(int); i++)
//	{
//		printf("%d ", num[i]);
//	}
//	printf("\n");
//	HeapSort(num, sizeof(num) / sizeof(int));
//	printf("排序后的数据是：\n");
//	for (i = 0; i < sizeof(num) / sizeof(int); i++)
//	{
//		printf("%d ", num[i]);
//	}
//	printf("\n");
//	system("pause");
//	return 0;
//}
