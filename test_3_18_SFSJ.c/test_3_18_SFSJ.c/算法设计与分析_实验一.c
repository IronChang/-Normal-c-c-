#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>
#include <malloc.h>

//��������
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
//		i = begin + 1;  // ��array[begin]��Ϊ��׼������˴�array[begin+1]��ʼ���׼���Ƚϣ�
//		j = end;        // array[end]����������һλ
//
//		while (i < j)
//		{
//			if (array[i] > array[begin])  // ����Ƚϵ�����Ԫ�ش��ڻ�׼�����򽻻�λ�á�
//			{
//				swap(&array[i], &array[j]);  // ����������
//				j--;
//			}
//			else
//			{
//				i++;  // �����������һλ���������׼���Ƚϡ�
//			}
//		}
//
//		/* ����whileѭ����i = j��
//		* ��ʱ���鱻�ָ����������  -->  array[begin+1] ~ array[i-1] < array[begin]
//		*                           -->  array[i+1] ~ array[end] > array[begin]
//		* ���ʱ������array�ֳ��������֣��ٽ�array[i]��array[begin]���бȽϣ�����array[i]��λ�á�
//		* ���array[i]��array[begin]���������������ָ�ֵ������Դ����ƣ�ֱ�����i = j�������������˳���
//		*/
//
//		if (array[i] >= array[begin])  // �������Ҫȡ�ȡ�>=������������Ԫ������ͬ��ֵʱ������ִ���
//		{
//			i--;
//		}
//
//		swap(&array[begin], &array[i]);  // ����array[i]��array[begin]
//
//		quicksort(array, maxlen, begin, i);
//		quicksort(array, maxlen, j, end);
//	}
//}
//// ������
//int main()
//{
//	int n;
//	int array[BUF_SIZE] = { 12, 85, 25, 16, 34, 23, 49, 95, 17, 61 };
//	int maxlen = BUF_SIZE;
//
//	printf("����ǰ������\n");
//	display(array, maxlen);
//
//	quicksort(array, maxlen, 0, maxlen - 1);  // ��������
//
//	printf("����������\n");
//	display(array, maxlen);
//
//	system("pause");
//	return 0;
//}

////ϣ������
//void shellsort1(int a[], int n)
//{
//	int i, j, gap;
//
//	for (gap = n / 2; gap > 0; gap /= 2) //����
//	for (i = 0; i < gap; i++)        //ֱ�Ӳ�������
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

////�鲢����
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
//	for (int i = 0; i<10; i++)  //��ʼ������
//	{
//		arr[i] = rand() % 100;  //�����������
//	}
//	printf("����ǰ:\n");  //��ӡ����ǰ������
//	for (int i = 0; i < 10; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//
//	//��ʼ����
//	Meger_Sort(arr, 0, 10 - 1, 10);
//
//
//	printf("\n�����:\n"); //��ӡ����������
//	for (int i = 0; i < 10; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//	system("pause");
//	return 0;
//}

////������
////�ѵ����������󶥶ѣ�arr[]�Ǵ����������飬i�Ǵ�����������
////Ԫ�ص�λ�ã�length������ĳ���
//void HeapAdjust(int arr[], int i, int length)
//{
//	int Child;
//	int temp;
//	for (; 2 * i + 1 < length; i = Child)
//	{
//		//�ӽڵ��λ�� = 2 * (parent(�����)) + 1
//		Child = 2 * i + 1;
//		//�õ��ӽ���нϴ�Ľ��
//		if (Child < length - 1 && arr[Child + 1] > arr[Child])
//			++Child;
//		//����ϴ���ӽ����ڸ������ô�ѽϴ���ӽ�������ƶ�
//		//�滻���ĸ����
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
////�������㷨
//void HeapSort(int arr[], int length)
//{
//	int i;
//	//�������е�ǰ�벿��Ԫ�أ�������֮���һ��Ԫ��
//	//�����е����Ԫ�أ�length/2-1�����һ����Ҷ�ӽ��
//	for (i = length / 2 - 1; i >= 0; --i)
//		HeapAdjust(arr, i, length);
//	//�����һ��Ԫ�ؿ�ʼ�����н��е��������ϵ���С����
//	//�ķ�Χֱ����һ��Ԫ��
//	//ѭ�����ǰѵ�һ��Ԫ�غ͵�ǰ�����һ��Ԫ�ؽ���
//	//��֤��ǰ�����һ��λ�õ�Ԫ��������������е�����
//	//���ϵ���С����heap�ķ�Χ��ÿһ�ε�����ϱ�֤��һ��
//	//Ԫ���ǵ�ǰ���е�����Ԫ��
//	for (i = length - 1; i > 0; --i)
//	{
//		arr[i] = arr[0] ^ arr[i];
//		arr[0] = arr[0] ^ arr[i];
//		arr[i] = arr[0] ^ arr[i];
//		HeapAdjust(arr, 0, i);						//�ݹ����
//	}
//}
//
//int main()
//{
//	int i;
//	int num[] = { 1, 9, 5, 10, 6, 8, 7, 2, 3 };
//	printf("������������ǣ�\n");
//	for (i = 0; i < sizeof(num) / sizeof(int); i++)
//	{
//		printf("%d ", num[i]);
//	}
//	printf("\n");
//	HeapSort(num, sizeof(num) / sizeof(int));
//	printf("�����������ǣ�\n");
//	for (i = 0; i < sizeof(num) / sizeof(int); i++)
//	{
//		printf("%d ", num[i]);
//	}
//	printf("\n");
//	system("pause");
//	return 0;
//}
