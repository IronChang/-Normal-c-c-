#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

//ͳ��һ�������Ķ��������м���1��

//
//int count_one_bits(int val)
//{
//	int count = 0;
//	int i = 0;
//	for (i = 0; i < 32; i++)
//	{
//		if ((val >> i) & 1 == 1)
//			count++;
//	}
//	return count;
//}
//
//int count_one_bits2(int val)
//{
//	int count = 0;
//	int i = 0;
//	for (i = 1; i <= 32; i++)
//	{
//		if (val % 2 == 1)
//		{
//			count++;
//		}
//		val = val / 2;
//	}
//	return count;
//}
//

//int count_one_bits3(int val)
//{
//	int count = 0;
//	int i = 0;
//	//�������ͻ�ȡѭ������
//	for (i = 1; i != 0; i <<= 1)
//	{
//		//�ѵ�iλ�Ƶ���һλ����1���а�λ��&���㣬��ȡ������ֵ
//		if ((val & i) != 0)
//		{
//			count++;
//		}
//	}
//	return count;
//}

//int count_one_bits4(int val)
//{
//	int count = 0;
//	while (val)
//	{
//		val = val&(val - 1);
//		count++;
//	}
//	return count;
//}
//

//int count_one_bits4(int n)
//{
//	int count = 0;
//	int flag = 1;
//	while (flag) {
//		if ((n & flag) != 0) {
//			count++;
//		}
//		flag = flag << 1;
//	}
//	return count;
//}

//int main()
//{
//	int val=0;
//	int ret = 0;
//	scanf("%d", &val);
//	ret = count_one_bits3(val);
//	printf("%d\n",ret);
//	system("pause");
//	return 0;
//}

//2.��ȡһ�������������������е�ż��λ������λ�� �ֱ�������������С�

//void print_binary_bit(int val)
//{
//	int i = 0;
//	printf("ż���У�> ");
//	for (i = 30; i >= 0; i -= 2)
//	{
//		printf("%d", (val >> i) & 1);
//	}
//	printf("\n");
//	printf("�����У�> ");
//	for (i = 31 ; i >= 0; i -= 2)
//	{
//		printf("%d", (val >> i) & 1);
//	}
//	printf("\n");
//}

//void print_binary_bit2(int val)
//{
//	int arr1[16] = { 0 };
//	int arr2[16] = { 0 };
//	int i = 0;
//	for (i = 0; i < 16; i++)
//	{
//		if ((val & 1) == 1)
//		{
//			arr1[i] = 1;
//		}
//		val >>= 1;
//		if ((val & 1) == 1)
//		{
//			arr2[i] = 1;
//		}
//		val >>= 1;
//	}
//	printf("ż���У�> ");
//	for (i = 15; i >= 0; i--)
//	{
//		printf("%d ", arr2[i]);
//	}
//	printf("\n");
//
//	printf("�����У�> ");
//	for (i = 15; i >= 0; i--)
//	{
//		printf("%d ", arr1[i]);
//	}
//	printf("\n");
//}
//
//int main()
//{
//	int val = 0;
//	scanf("%d", &val);
//	print_binary_bit(val);
//	system("pause");
//	return 0;
//}

// ���һ��������ÿһλ�� 

//void printfs(int val)//�ݹ�
//{
//	if (val > 9)
//	{
//		printfs(val / 10);
//	}
//	printf("%d\n", val % 10);
//}

//void printfs2(int val)
//{
//	if (val == 0)
//	{
//		printf("0\n");
//		return;
//	}
//
//
//	int len = 0;
//	//��ȡ����
//	int tmp = val;
//	while (tmp)
//	{
//		len++;
//		tmp /= 10;
//	}
//
//	while (len)
//	{
//		int num = val / pow(10, len - 1);
//		printf("%d ", num % 10);
//		len--;
//	}
//	printf("\n");
//}

//int main()
//{
//	int val = 0;
//	scanf("%d", &val);
//	printfs2(val);
//	printf("\n");
//	system("pause");
//	return 0;
//}

//����int��32λ������m��n�Ķ����Ʊ���У��ж��ٸ�λ(bit)��ͬ��

//int calculateDifferentBit(int m, int n)
//{
//	//m��n��������Ķ����Ʊ�ʾ�У�1��λ��ʾm��n��ͬ��λ
//	//����������ж����Ʊ�ʾ��1�ĸ���
//	int yihuo = m^n;
//	int i = 0;
//	int count = 0;
//
//	while (yihuo)
//	{
//		yihuo = yihuo & (yihuo - 1);
//		count++;
//	}
//	return count;
//}

//int calculateDifferentBit2(int m, int n)
//{
//	int count = 0;
//	int i = 0;
//	for (i; i < 32; i++)
//	{
//		if (((m >> i) & 1) != ((n >> i) & 1))
//			count++;
//	}
//	return count;
//}

//int main()
//{
//	int m = 0;
//	int n = 0;
//	int ret = 0;
//	scanf("%d", &m);
//	scanf("%d", &n);
//	ret=calculateDifferentBit(m,n);
//	printf("%d\n", ret);
//	system("pause");
//	return 0;
//}