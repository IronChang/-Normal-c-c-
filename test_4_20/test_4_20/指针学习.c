//#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//
////void print(int* n, int sz)
////{
////	int i = 0;
////	for (i = 0; i < sz; i++)
////	{
////		printf("%d\n", *(n + i));
////	}
////}
////
////int main()
////{
////	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
////	int* p = arr;
////	int sz = sizeof(arr) / sizeof(arr[0]);
////	print(arr, sz);
////
////	system("pause");
////	return 0;
////}
//
////int main()
////{
//	//һά����
//	//sizeof()�������������ʱ�����ǲ����������ͣ�������������
//	//int a[] = { 1, 2, 3, 4 };
//	//printf("%d\n", sizeof(a));//16
//	//printf("%d\n", sizeof(a + 0));//ָ�� 4
//	//printf("%d\n", sizeof(*a));//���� 4
//	//printf("%d\n", sizeof(a + 1));//ָ�� 4
//	//printf("%d\n", sizeof(a[1]));//���� 4
//	//printf("%d\n", sizeof(&a));//����ĵ�ַ��Ҳ���൱������ָ��4
//	//printf("%d\n", sizeof(*&a));//�������� 16
//	//printf("%d\n", sizeof(&a + 1));//ָ�� 4
//	//printf("%d\n", sizeof(&a[0]));//ָ�� 4
//	//printf("%d\n", sizeof(&a[0] + 1));//ָ�� 4
//
//
//	//char arr[] = { 'a', 'b', 'c', 'd', 'e', 'f' };//����ȫ��ʼ����û��'\0'
//	//printf("%d\n", sizeof(arr));  //6
//	//printf("%d\n", sizeof(arr + 0)); //ָ�� 4
//	//printf("%d\n", sizeof(*arr)); // char���� 1
//	//printf("%d\n", sizeof(arr[1])); //char���� 1
//	//printf("%d\n", sizeof(&arr));//����ĵ�ַ ��Ҳ���൱������ָ�� 4
//	//printf("%d\n", sizeof(&arr + 1));//ָ�� 4
//	//printf("%d\n", sizeof(&arr[0] + 1));//ָ�� 4
//
//	//strlen�������ܴ�������ĵ�ַ���Լ�����
//	//printf("%d\n", strlen(arr)); // �������������û�С�\0��,��ֵ��� ����������������飩
//	//printf("%d\n", strlen(arr + 0)); // ͬ��
//	////printf("%d\n", strlen(*arr)); // �಻��
//	////printf("%d\n", strlen(arr[1])); // �಻��
//	////printf("%d\n", strlen(&arr));// �಻��
//	////printf("%d\n", strlen(&arr + 1)); // ���
//	//printf("%d\n", strlen(&arr[0] + 1)); // ����û��'\0'
//
//
//	//char arr[] = "abcdef";//������ȫ��ʼ�����С�\0��
//	//printf("%d\n", sizeof(arr)); // 7 szieof()����,����������ʱ�������ʱ���������Ŀռ��С
//	//printf("%d\n", sizeof(arr + 0)); //ָ��4
//	//printf("%d\n", sizeof(*arr)); //char ���� 1
//	//printf("%d\n", sizeof(arr[1])); //char ���� 1
//	//printf("%d\n", sizeof(&arr)); //�����ַ ���൱������ָ�� 4
//	//printf("%d\n", sizeof(&arr + 1)); //ָ�� 4
//	//printf("%d\n", sizeof(&arr[0] + 1)); //ָ�� 4
//
//	//printf("%d\n", strlen(arr)); //6  strlen���������ַ������ȣ������������� ����������������飩
//	//printf("%d\n", strlen(arr + 0));//6 ͬ��
//	////printf("%d\n", strlen(*arr));//�಻��
//	////printf("%d\n", strlen(arr[1]));//�಻��
//	////printf("%d\n", strlen(&arr));//�಻��
//	////printf("%d\n", strlen(&arr + 1));�಻��
//	//printf("%d\n", strlen(&arr[0] + 1)); //5 �׵�ַ�����1λ
//
//
//	//char *p = "abcdef";//ָ��ָ�����ַ�������'\0'
//	//printf("%d\n", sizeof(p)); //ָ�� 4
//	//printf("%d\n", sizeof(p + 1)); //ָ�� 4
//	//printf("%d\n", sizeof(*p));//char 1
//	//printf("%d\n", sizeof(p[0])); //char 1
//	//printf("%d\n", sizeof(&p));//ָ�� 4
//	//printf("%d\n", sizeof(&p + 1)); //ָ�� 4
//	//printf("%d\n", sizeof(&p[0] + 1));//ָ�� 4
//
//	//printf("%d\n", strlen(p)); //6 ����ָ��p��ָ��ĳ����ַ��� ����������������飩
//	//printf("%d\n", strlen(p + 1)); //5 �׵�ַ�����1λ
//	///*printf("%d\n", strlen(*p));
//	//printf("%d\n", strlen(p[0]));
//	//printf("%d\n", strlen(&p));
//	//printf("%d\n", strlen(&p + 1));�಻��*/
//	//printf("%d\n", strlen(&p[0] + 1));//5 ����Ԫ�ص�ַ�����1λ
//
//
////	int a[3][4] = { 0 };
////	printf("%d\n", sizeof(a)); //48 a���൱�������ַ �������
////	printf("%d\n", sizeof(a[0][0])); //int 4
////	printf("%d\n", sizeof(a[0])); //16 �ڶ�ά������ a[0]��ʾ��һ��������׵�ַ��
////	printf("%d\n", sizeof(a[0] + 1)); //4 ָ��
////	printf("%d\n", sizeof(*(a[0] + 1))); //��ʾ�ڶ���������Ԫ�� int 4
////	printf("%d\n", sizeof(a + 1));// 4 ָ��
////	printf("%d\n", sizeof(*(a + 1))); //16 ��һ������+1�����ñ�ʾ��������
////	printf("%d\n", sizeof(&a[0] + 1)); //ָ�� 4 &a[0]�ǵ�һ�е�ַ ����ָ��
////	printf("%d\n", sizeof(*(&a[0] + 1))); //16  ��һ�������ַ+1�ڽ����ñ�ʾ��������
////	printf("%d\n", sizeof(*a));//16 ��һ���������������
////	printf("%d\n", sizeof(a[3])); //16  �ڶ�ά���鵱��a[i]�Ʊ�ż�ǵڼ��е������ַ
//
////	// ��ά�����У�a[i]���ǵ�i�е�������
////	printf("%p\n", a[0]); // a[0]�ǵ�һ����Ԫ�صĵ�ַ
////	printf("%p\n", a[0] + 1);
////	int* p0 = a[0];
//
////	printf("%p\n", &a[0]); // &a[0]�ǵ�һ�е�ַ ����ָ��
////	printf("%p\n", &a[0] + 1);
////	int(*p1)[4] = &a[0];
//
////	system("pause");
////	return 0;
////}
//
////һ��ָ�봫��
//void swap1(int* ptr1, int* ptr2)
//{
//	int x = *ptr1;
//	*ptr1 = *ptr2;
//	*ptr2 = x;
//}
//
////����ָ�봫��
//void swap2(int** pptr1, int** pptr2)
//{
//	int* x = *pptr1;
//	*pptr1 = *pptr2;
//	*pptr2 = x;
//}
//
//int main()
//{
//	int a1 = 0;
//	int a2 = 1;
//	int* p1 = &a1;
//	int* p2 = &a2;
//
//	swap1(&a1, &a2);
//	printf("a1=%d a2=%d\n", a1, a2);
//	swap2(&p1, &p2);
//	printf("a1=%d a2=%d\n", p1, p2);
//
//	system("pause");
//	return 0;
//}