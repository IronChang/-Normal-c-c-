#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<assert.h>
#include<windows.h>

//int MY_Atoi(char* array, int* num)
//{
//	assert(array);//�ж�����������Ƿ�Ϊ��
//	int len1 = strlen(array);//�����ַ����ĳ��ȣ�������ת�������ε�λ��
//	int len2 = len1;
//	int i = 0;
//	int mul = 1;
//	int l = 1;
//
//	if (array[i] == '-')
//	{
//		len2 -= 1;  //��ǰ��ķ���ȥ��
//		for (l; l < len2; l++)//��������λ���������
//		{
//			mul = mul * 10;
//		}
//
//		for (i = 1; i < len1; i++)
//		{
//			*num += (array[i] - '0')*(mul);
//			mul /= 10;
//		}
//
//		*num = (*num)*(-1);
//	}
//	else
//	{
//		for (l; l < len1; l++)//��������λ���������
//		{
//			mul = mul * 10;
//		}
//		for (i; i < len1; i++)
//		{
//			num += (array[i] - '0')*(mul);
//			mul /= 10;
//		}
//	}
//}


int Atoi(char*stuff)
{
	assert(stuff);

	int flag = 0;
	int i = 0;
	int total = 0;

	if (*stuff== '-')
	{
		++stuff;
		flag = 1;
	}

	while (*stuff)
	{
		total *= 10;
		total += *stuff - '0';
		++stuff;
	}

	if (flag == 1)
	{
		return -total;
	}
	else
	{
		return total;
	}
}


int main()
{
	char arr[] = {"-1234"};
	int num = 0;
	num=Atoi(arr);
	printf("%d\n", num);

	system("pause");
	return 0;
}