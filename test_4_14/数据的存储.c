#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<windows.h>

//�����жϴ�С�˴洢ģʽ

//����һ
//int main()
//{
//	int x = 1;
//	char* p = (char*)&x;//ָ�����;�������������ʱ�����ֽڴ�С������ǿ������ת��
//
//	if (*p == 1)//1�ĵ�ΪΪ00000001���������ݵ�λ�������ڴ��λ
//	{
//		printf("С��ģʽ\n");
//	}
//	else
//	{
//		printf("���ģʽ\n");
//	}
//
//	system("pause");
//	return 0;
//}

//������
//int main()
//{
//	int x = 1;
//	char firstbyte = (char)x;//ǿ��ת��x�����int����ת��Ϊchar����
//
//	if (firstbyte == 1)
//	{
//		printf("С��ģʽ\n");
//	}
//	else
//	{
//		printf("���ģʽ\n");
//	}
//
//	system("pause");
//	return 0;
//}

//������
//int main()//������
//{
//	union UN //����������ռ䣬�����е��������Ͱ�������룬ȫ������һ���ռ�
//	{
//		int i;
//		char c;
//	};
//
//	union UN u;
//	u.i = 1;//����������i��ֵ����ʱ������u�ռ䱻ռ��
//
//	if (u.c == 1)
//	{
//		printf("С��ģʽ\n");
//	}
//	else
//	{
//		printf("���ģʽ\n");
//	}
//	system("pause");
//	return 0;
//}


//�з��ţ��޷���������� ���δ洢

//����һ��
//int main()
//{
//	// �ض� -- �����������޹�
//	char a = -1;
//	signed char b = -1;
//	unsigned char c = -1;
//
//	// �������� -- �����������з��ţ�����λ1����λ��1 ������λλ0����λ��0
//	// �������� -- ���������޷��ţ���λ��0
//	// a  ��24��1 11111111
//	// b  ��24��1 11111111
//	// c  ��24��0 11111111
//	printf("a=%d,b=%d,c=%d\n", a, b, c);
//	// 127 127 177601
//
// //10000000 00000000 00000000 00000001 ԭ
// //11111111 11111111 11111111 11111110 ��
// //11111111 11111111 11111111 11111111 ��
//
//// 00000000 00000000 00000000 11111111 ��
//	system("pause");
//	return 0;
//}

//�����
//int main()
//{
//	char a = -129;
//	//-129���ڴ���
//	//10000000 00000000 00000000 10000001 ԭ��
//	//11111111 11111111 11111111 01111111 ����
//	//�ض� 01111111
//	//�������� ��24��0 01111111
//	printf("%u\n", a);
//	system("pause");
//	return 0;
//}

//������
//int main()
//{
//	char a = 129;
//	printf("%u\n", a);
//	system("pause");
//	return 0;
//}

//������
//int main()
//{
//	int i = -20;
//	unsigned int j = 10;
//
//	printf("%d\n", i + j);
//
//	system("pause");
//	return 0;
//}

//������
//int main()
//{
//	unsigned int i;
//
//	for (i = 9; i >= 0; i--)
//	{
//		Sleep(500);
//		printf("%u\n", i);
//	}
//	//���������ѭ��
//	//��Ϊ��i=0�����i����ѭ��i=-1����Ϊi����������ʱ�޷������ͣ�����-1���ڴ���ʱ����
//	//11111111 11111111 11111111 11111111 �ᱻ��Ϊʱ����
//	//���ٴν���ѭ��
//	system("pause");
//	return 0;
//}

//������
//int main()
//{
//	char a[1000];
//	int i;
//
//	for (i = 0; i < 1000; i++)
//	{
//		a[i] = -1 - i;
//	}
//	printf("%d\n", strlen(a));
//
//	system("pause");
//	return 0;
//}

//������
//int main()
//{
//    unsigned char i = 0;//ͬ������
//
//	for (i = 0; i <= 255; i++)
//	{
//		printf("hello world\n");
//	}
//	system("pause");
//	return 0;
//}


//����洢
//int main()
//{
//	int n = 9;
//	float *pFloat = (float *)&n;
//	printf("n��ֵΪ��%d\n", n);
//	printf("*pFloat��ֵΪ��%f\n", *pFloat);
//	*pFloat = 9.0;
//	printf("num��ֵΪ��%d\n", n);
//	printf("*pFloat��ֵΪ��%f\n", *pFloat);
//	system("pause");
//	return 0;
//}
