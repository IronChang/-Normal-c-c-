#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

//�������鵱�е�����
//int main()
//{
//	int a[] = { 1, 2, 3, 4, 5 };
//	int b[] = { 6, 7, 8, 9, 10 };
//	int i = 0;
//	int j = 0;
//	int temp;
//
//	for (i; i < 5; i++)//�����м�ֵ���н���
//	{
//		
//		   temp = b[i];
//			b[i] = a[i];
//			a[i] = temp;
//		
//	}
//	for (int l = 0; l < 5; l++)
//	{
//		printf("%d  ", a[l]);
//		
//	}
//
//	system("pause");
//	return 0;
//}

//����1 / 1 - 1 / 2 + 1 / 3 - 1 / 4 + 1 / 5 ���� + 1 / 99 - 1 / 100 ��ֵ
//int main()
//{
//	int i = 0;
//	double sum1 = 0;
//	double sum2 = 0;
//	for (i = 1; i <= 100; i += 2)//���������֮��
//	{
//		sum1 += (1.0/ i);
//	}
//	for (i = 2; i <= 100; i += 2)//���ż����֮��
//	{
//		sum2 += (1.0 / i);
//	}
//    printf("%lf\n", sum1-sum2);
//	system("pause");
//	return 0;
//}

//��д������һ�� 1�� 100 �����������г��ֶ��ٴ�����9
//int main()
//{
//	int i = 0;
//	int k = 0;
//	for (i = 1; i <= 100; i++)
//	{
//		if (i % 10 == 9)//��Ը�λ��9��
//		{
//			k++;
//		}
//		if (i / 10 == 9)//���ʮλ��9��
//		{
//			k++;
//		}
//
//	}
//
//	printf("�ܹ�����9�ĸ���Ϊ��%d\n", k);
//	system("pause");
//	return 0;
//}