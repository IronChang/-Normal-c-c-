#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

//1.һ��������ֻ�����������ǳ���һ�Σ�
//�����������ֶ����������Ρ�
//�ҳ�������ֻ����һ�ε����֣����ʵ�֡�

//������ı�����ⷨ����ı�ԭ����������ݣ�

//void search_ones(int* arr,int sz)
//{
//	int i = 0;
//	int j = 0;
//
//	for (i = 0; i < sz; i++)
//	{
//		for (j = i + 1; j < sz; j++)
//		{
//			if (arr[i] == arr[j])
//			{
//				arr[i] = 0;
//				arr[j] = 0;
//			}
//
//		}
//	}
//	printf("���ֹ�һ�ε�����:>");
//	for (i = 0; i < sz; i++)
//	{
//		if (arr[i] != 0)
//		{
//			printf("%d ", arr[i]);
//		}
//	}
//	printf("\n");
//}

//int main()
//{
//	int a[] = { 4,2,8,6,5,7,8,4,6,5};
//	int len = sizeof(a) / sizeof(a[0]);
//
//	printf("����Ԫ��:>");
//	for (int i = 0; i < len; i++)
//	{
//		printf("%d ", a[i]);
//	}
//	printf("\n");
//	search_ones(a, len);
//
//	system("pause");
//	return 0;
//}

//����Ľⷨ
void find_ones(int arr[], int sz)
{
	int i = 0;
	int ret = 0;//�������ֵ�������
	int pos = 0;//���ret�����Ƶ�һ��Ϊ1��λ��
	int x = 0;
	int y = 0;

	for (i = 0; i < sz; i++)//�����ֵȫ�����
	{
		ret ^= arr[i];
	}

	for (i = 0; i < 32; i++)//�õ�ret�е�һΪ1��λ��
	{
		if (1 == ((ret >> i) & 1))
		{
			pos = i;
			break;
		}
	}

	for (i = 0; i < sz; i++)//�������ֳ����飬�ֱ����ĵ�����ֵ
	{
		if (1 == ((arr[i] >> pos) & 1))
		{
			x ^= arr[i];
		}
		else
		{
			y ^= arr[i];
		}
	}

	printf("%d  %d\n", x, y);
}

int main()
{
	int a[] = { 4, 2, 8, 6, 5, 7, 8, 4, 6, 5 };
	int len = sizeof(a) / sizeof(a[0]);
	find_ones(a, len);

	system("pause");
	return 0;
}

//2.����ˮ��1ƿ��ˮ1Ԫ��2����ƿ���Ի�һƿ��ˮ��
//��20Ԫ�����Ժȶ�����ˮ��
//���ʵ�֡�

//int main()
//{
//	int m = 0;
//	int sum = 0;
//	int n = 0;
//	scanf("%d", &m);
//	sum = m;
//	while (m > 2)//�ÿ�ƿ������
//	{
//		m = m / 2;
//		sum +=m;
//	}
//	printf("%d\n", sum);
//	system("pause");
//	return 0;
//}


/*3.ģ��ʵ��strcpy

�������ܣ���sourceָ���C�ַ������Ƶ�destinationָ��������У�������ֹ���ַ������ڸõ�ֹͣ����
Ϊ���������Ŀ��ָ��������СӦ�㹻�����԰�����Դ��ͬ��C�ַ�����������ֹ���ַ��������Ҳ�Ӧ���ڴ�����Դ�ص���

�������: ����ԭ�� char * strcpy��char * destination��const char * source��;

����һ�·�������Ϊ char* ��ԭ��  ʹ����֧����ʽ���ʽ�����㸴�ƣ����Ӻ�������ԡ�
*/

//�Լ�д�ģ�������Ҫ����������

//void my_strcpy(char* a,const char* b,int len)
//{
//	for (int i = 0; i < len; i++)
//	{
//		a[i] = b[i];
//	}
//}

//int main()
//{
//	char arr1[] = { "abcdef" };
//	char arr2[] = {0};
//
//	int len = sizeof(arr1) / sizeof(arr1[0]);
//	my_strcpy(arr2, arr1,len);
//	printf("%s\n", arr2);
//
//	system("pause");
//	return 0;
//}

//�������

//char* my_strcpy1(char* dst, const char* src)
//{
//	assert((dst != NULL) && (src != NULL));//�����жϣ�����������ַ���ǿյ�
//	char* temp = dst;
//
//	while ((*dst++ = *src++) != '\0')
//	{
//	}
//
//	return temp;
//}

//int main()
//{
//		char arr1[] = { "abcdefgh" };
//		char arr2[] = {0};
//	    char* arr3=my_strcpy1(arr2, arr1);
//
//		printf("%s\n", arr1);
//		printf("%s\n", arr2);//������ɺ�arr2���������
//		printf("%s\n", arr3);//ͨ����������ֵ���ܵ�arr3���������
//
//		system("pause");
//		return 0;
//}

/*
4.ģ��ʵ��strcat

�������ܣ���Դ�ַ����ĸ������ӵ�Ŀ���ַ�����Ŀ���е���ֹ���ַ���Դ�ĵ�һ���ַ����ǣ�
��������Ŀ���е����������γɵ����ַ�����ĩβ�������ַ���
Ϊ���������Ŀ��ָ��������СӦ�㹻�����԰�����Դ��ͬ��C�ַ�����������ֹ���ַ��������Ҳ�Ӧ���ڴ�����Դ�ص���

�������������ԭ�� char * strcat ( char * destination, const char * source );

����һ�·�������Ϊ char* ��ԭ��  ʹ����֧����ʽ���ʽ�����㸴�ƣ����Ӻ�������ԡ�
*/
//
//char* my_strcat(char* dst, const char* src)
//{
//	assert((dst != NULL) && (src != NULL));//�����ж�,��֤�����ָ�벻�ǿ�ָ��
//	char* temp = dst;
//
//	while (*dst != '\0')//��ָ���Ƶ�Ŀ���ַ����ġ�\0����λ����
//	{
//		dst++;
//	}
//
//	while ((*dst=*src++)!= '\0')//��src�����ݸ�ֵ����dst�ĺ���
//	{
//	}
//	return temp;
//}

//int main()
//{
//	char str1[10] = "abc";
//	char str2[] = "bcd";
//	
//	printf("str1=%s\n", str1);
//	char* str3 = my_strcat(str1, str2);
//	printf("str2=%s\n", str2);
//	printf("str3=%s\n", str3);
//
//	system("pause");
//	return 0;
//}
