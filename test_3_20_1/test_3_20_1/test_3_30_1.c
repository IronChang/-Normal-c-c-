#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

//int main()
//{
//	int a = 98;
//	int b = 888;
//	int c = 0;
//	c = a > b ? a : b;//��������������Ŀ��������
//	printf("%d\n", c);
//	system("pause");
//	return 0;
//}

//int main()
//{
//	int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//	int* p1 = arr;
//	int* p2 = arr[0];
//
//	printf("%p\n", arr);
//	printf("%p\n", arr+1);
//
//	printf("%p\n", &arr[0]);
//	printf("%p\n", &arr[0]+1);
//
//	printf("%p\n", &arr);//ȡ������ĵ�ַ
//	printf("%p\n", &arr+1);//��һ�������������С
//
//	system("pause");
//	return 0;
//}

//int main()
//{
//	int a = 10;
//	printf("%d\n", sizeof(int));//��������ʱ������ʡ������
//	printf("%d\n", sizeof(int));
//	printf("%d\n", sizeof a );//��������ǿ���ʡ������
//
//	int arr[10] = { 0 };
//	printf("%d\n", sizeof(arr));//���ҽ�������������ʱ��sizeof�����������������С����ʱarr��ʾ������������
//	printf("%d\n", sizeof(arr+0));
//
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	printf("%d\n", sz);
//
//
//	system("pause");
//	return 0;
//}

//int main()
//{
//	int a = 15;
//
//	printf("%d\n", ~a);  //��λȡ��������
//	system("pause");
//	return 0;
//}

//int main()
//{
//	int a = 3;
//	int b = 0;
//	printf("%d\n", a && b);//�߼���  ȫ�����
//	printf("%d\n", a || b);//�߼���  ȫ�ٲż�
//
//	system("pause");
//	return 0;
//}

////�ṹ��
//struct stu
//	{
//		char name[20];
//		short age;
//		char sex[10];
//	};
//print(struct stu* s)
//{
//	printf("%s %d %s\n", s->name, s->age, s->sex);// "->"��Խṹ��ָ��
//
//}
//int main()
//{
//	struct stu s = {"����",20,"��"};
//	printf("%s %d %s\n", s.name, s.age, s.sex);//"."��Խṹ�屾 ��
//	print(&s);
//	system("pause");
//	return 0;
//}

//int main()
//{
//	char a = 3;
//	char b = 127;
//	char c = a + b;
//	//int a=3;00000000000000000000000000000011
//	//char a=3;00000011
//	//int b=127;00000000000000000000000001111111
//	//char b=127;01111111
//	//int c=a+b
//	//00000000000000000000000000000011
//	//00000000000000000000000001111111
//	//00000000000000000000000010000010 
//	printf("%d\n", c);
//	//char c;10000010
//	//int c;11111111111111111111111110000010//����ת���޷��Ų�ԭ����λ-����
//	//10000000000000000000000001111110-ԭ��   ������-1ȡ����
//	//-��2+4+8+16+32+64��=-126
//	system("pause");
//	return 0;
//}

//int main()
//{
//
//	char a = 0xb6;
//	short b = 0xb600;
//	int c = 0xb6000000;
//	if (a == 0xb6)
//		//   
//		printf("a");
//	if (b == 0xb600)
//		printf("b");
//	if (c == 0xb6000000)
//		printf("c");
//
//	system("pause");
//	return 0;
//}

