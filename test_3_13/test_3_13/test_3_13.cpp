#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<math.h>


//��ӡ����
//int main()
//{
//	int i = 0;
//	scanf("%d", &i);
//	printflingxing(i);
//	system("pause");
//	return 0;
//}
//
//void printline(int blacck_count, int start_count)
//{
//	int i = 0;
//
//	for (i = 0; i < blacck_count; i++)//��ӡ�ո�
//	{
//		printf(" ");
//	}
//
//	for (i = 0; i < start_count; i++)//��ӡ*��
//	{
//		printf("*");
//	}
//
//	printf("\n");
//}
//
//void printflingxing(int n)
//{
//	int i = 1;
//	for (i = 1; i < n; i++)
//	{
//		printline(n - i, 2 * i - 1);//��ӡ�����ϰ벿��
//	}
//
//	printline(0, 2 * n - 1);//��ӡ�м�һ��
//
//	for (i = n - 1; i > 0; i--)//��ӡ�����°벿��
//	{
//		printline(n - i, 2 * i - 1);
//	}
//}


//����ˮ�ɻ���
//int main()
//{
//	int i = 0;
//	for (i; i <= 999; i++)//0��999֮���ˮ�ɻ���
//	{
//		int a = 0,b = 0, c = 0;
//		int n=0;
//		a = i / 100;//������λ
//		b = (i / 10) % 10;//�����ʮλ
//		c = i % 10;//�������λ
//		n = a*a*a + b*b*b + c*c*c;
//		if (i == n)//�ж��Ƿ���ˮ�ɻ���
//		{
//			printf("%d  ", i);
//		}
//
//	}
//
//	system("pause");
//	return 0;
//}
//
//
//Sn=a+aa+aaa+aaaa+aaaaa��ǰ5��֮��
//int main()
//{
//
//	int n = 0, i = 0;
//	scanf("%d", &n);
//	int sum = n;
//  int temp = n;
//
//	for (i = 0; i < 4; i++)
//	{
//		temp= temp * 10 + n; //����a+aa+aaa+aaaa+aaaaa
//		sum =sum + temp;
//	}
//	printf("Sn=%d\n", sum);
//
//	system("pause");
//	return 0;
//}