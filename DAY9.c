#define _CRT_SECURE_NO_WARNINGS 1
//
////����100-200֮�������
//#include<stdio.h>
//#include<stdlib.h>
//
//int main()
//{
//	int i, j;
//
//	for (i=100; i<= 200; i++) //����ѭ�������������
//	{
//		for (j = 2;j<i; j++)
//		{
//			if (i%j == 0)
//				break;//���Ҫ�������Ǿ�ֱ��������ѭ��
//		}
//		if (j == i)//���û������
//			printf("%d  ", i);
//	}
//	printf("\n");
//	system("pause");
//	return 0;
//}
//
//����˷��ھ���
#include<stdio.h>
#include<stdlib.h>

int main()
{
	int i , j;
	for (i = 1; i <= 9; i++)//���Ƴ˷��ھ��������
	{
		for (j = 1; j <= i; j++)//���Ƴ˷��ھ��������
		{
			printf("%d*%d=%2d  ", i, j, i*j);
		}
		printf("\n");
	}
	system("pause");
	return 0;
}
//
//

//���1000-2000֮�������
//#include<stdio.h>
//#include<stdlib.h>

//int main()
//{
//	int i;
//  int count = 0;
//	for (i = 1000; i <= 2000; i++)
//	{  
//		if (i % 100 != 0 && i % 4 == 0 || i % 400 == 0)//�ж�������������ܱ���������ͬʱ���ܱ�100�����������ܱ�400������
//		{         
//			printf("%d  ", i);
//          count++;
//		}
//			
//	}
//   printf("������: %d", count);
//	system("pause");
//    return 0;
//}