#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//#include<stdlib.h>

/*����ָ�룺����ָ��У���һ��ָ��ĵ�ַ��һ�����������Ա�ʾ������ָ��
(1)������ ���ο�������Ҳ��������Ԫ�صĵ�ַ��
(2)ȡ��ַ������ ���ο�;ȡ��ַ������Ҳ����������Ԫ�صĵ�ַ��
(3)ͨʽ void (*+ָ����)�� �� ����ֵΪ void
*/

//����1 ��*��void ��*��������0��������//��ʵ��һ�������ĵ���
//����ָ������ú��һ������������������ʾ��������
//��void ��*��������0 // ��0ǿ��ת���ɸ����͵ĺ���ָ��
//Ȼ��ͽ����ã����൱�ڵ��ú���
//ʵ���ϴ�ʱӦ�ó��ִ��󣬡�0���ĵ�ַΪ�ǲ��������ʵġ�Ҳ���൱�ڿ�ָ�롣
//��ָ����൱�ڸ��ڴ�ռ��һ����ַλ���ǲ��������ʵġ�


//����2 void (*signal(int , void(*)(int)))(int)�� //�����൱��һ������������
//������;signal(int , void(*)(int))
//������int,����ָ�� (int , void(*)(int)
//����ֵ����һ������ָ�� void ��*+signal��������int��
//���뿴�������Ѷ��������Ż�һ�£�
//typedef void(*Func)(int)
//Func signal(int ,Func)   

/*����ָ�����飺��ź���ָ���һ�༯��
��1�� ͨʽ:int (*arr[10])()
����arr�Ⱥ�[]��ϣ�˵��arr��һ�����飬�������ŵ��� int (* )() ���͵ĺ���ָ��
*/ 


//����ָ���������;�� ת�Ʊ�
//ʵ�֣��������� һ�㷽ʽʵ��

//int  add(int a, int b)
//{
//	return a + b;
//}

//int  sub(int a, int b)
//{
//	return a - b;
//}

//int  mul(int a, int b)
//{
//	return a * b;
//}

//int  div(int a, int b)
//{
//	return a / b;
//}

//int main()
//{
//	int x = 0;
//	int y = 0;
//	int input = 1;
//	int ret = 0;
//	
//	while (input)
//	{
//		printf("********************************\n");
//		printf("1: add                    2: sub\n");
//		printf("3: mul                    4: div\n");
//		printf("********************************\n");
//		printf("��ѡ��> ");
//		scanf("%d", &input);
//
//		switch (input)
//		{
//		case 1:
//			printf("������������������>");
//			scanf("%d %d", &x, &y);
//			ret = add(x, y);
//			break;
//		case 2:
//			printf("������������������>");
//			scanf("%d %d", &x, &y);
//			ret = mul(x, y);
//			break;
//		case 3:
//			printf("������������������>");
//			scanf("%d %d", &x, &y);
//			ret =mul(x, y);
//			break;
//		case 4:
//			printf("������������������>");
//			scanf("%d %d", &x, &y);
//			ret = div(x, y);
//			break;
//		default:
//			printf("������󣡣�������������");
//			break;
//		}
//		printf("��� = %d\n", ret);
//	}
//	system("pause");
//	return 0;
//}

//���ú���ָ������ʵ��

int  add(int a, int b)
{
	return a + b;
}

int  sub(int a, int b)
{
	return a - b;
}

int  mul(int a, int b)
{
	return a * b;
}

int  div(int a, int b)
{
	return a / b;
}

int main()
{
	int x = 0;
	int y = 0;
	int input = 1;
	int ret = 0;
	int(*p[5])(int x, int y) = { 0, add, sub, mul, div };

	while (input)
	{
		printf("********************************\n");
		printf("1: add                    2: sub\n");
		printf("3: mul                    4: div\n");
		printf("********************************\n");
		printf("��ѡ��> ");
		scanf("%d", &input);

		if (input <= 4 && input >= 1)
		{
			printf("������������������>");
			scanf("%d %d", &x, &y);
			ret = (*p[input])(x, y);
		}
		else
		{
			printf("������󣡣���������������\n");
		}
		printf("%d\n", ret);
	}
	
	system("pause");
	return 0;
}