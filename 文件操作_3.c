#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<windows.h>

//#define �����ʶ��  �����
//����+���ʽ�滻
#define N 100
//#define MAX(a,b) ((a) > (b) ? (a) : (b))//�꺯�������ٵ��ú��������ģ����Ч�ʡ�ֱ����Ԥ�������滻���迪��ջ֡
//
//int Max(int a, int b)//����ʱҪ���ڴ濪����Ӧջ֡ 
//{
//	return ((a) > (b) ? (a) : (b));//�����ź����������������ȼ�����
//}

//int main()
//{
//	int x1 = 0;
//	int x2 = 1;
//	printf("%d\n" ,MAX(x1, x2));
//	printf("%d\n", Max(x1, x2));
//
//	system("pause");
//	return 0;
//}

//#define ADD(a,b) ((a)+(b))
//
//int add(int a,int b)
//{
//	return a + b;
//}
//
//int main()
//{
//	printf("%d\n", ADD(1, 2) * 3);//���Ӧ����9��������7? why?
//	��Ϊ�������ȼ�������
//	printf("%d\n", add(1, 2) * 3);
//
//	int x1 = 1, x2 = 2;
//	printf("%d\n", ADD(x1 | x2,x1 | x2) * 3);//�������ȼ�������
//	printf("%d\n", add(x1 | x2, x1 | x2) * 3);
//
//	system("pause");
//	return 0;
//}


//�궨��Ѳ��������ַ�����
//#define PRINT(FORMAT, VALUE) \
//	printf("my value is "FORMAT"\n", VALUE);
#define PRINT(FORMAT, VALUE)\
printf("the value of " #VALUE "is "FORMAT "\n", VALUE);

int main()
{
	int i = 10;
	PRINT("%d", i + 3); printf("the value of " "i + 3" "is " "%d" "\n", i + 3);
	system("pause");
	return 0;
}