#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
//��̬�ڴ濪��
//��̬�ڴ溯��malloc()��free()
//����ԭ�� : void* malloc(size_t size)
//����ԭ�� ��void* free(void* ptr)

//int main()
//{
//	int num = 0;
//	scanf("%d", &num);
//
//	int* ptr = NULL;
//	ptr = (int*)malloc(num*sizeof(int));
//	if (NULL != ptr)//�ж�ptrָ���Ƿ�Ϊ��
//	{
//		int i = 0;
//		for (i = 0; i < num; i++)
//		{
//			*(ptr + i) = 0;//��ʼ���ռ�����Ŀռ�
//		}
//	}
//
//	*(ptr+0) = 1;
//	*(ptr+1) = 2;
//	*(ptr+2) = 3;
//
//	for (int k = 0; k < num; k++)
//	{
//		printf("%d   ", *(ptr + k));
//	}
//	printf("\n");
//
//	free(ptr);//�ͷ�ptr��ָ��Ķ�̬�ڴ�
//	ptr = NULL;//�ÿ�  ��ֹҰָ��
//	system("pause");
//	return 0;
//}

  //����ԭ��  void* calloc(size_t num,size_t size)
  //���壺Ϊnum����СΪsize��Ԫ�ؿ���һ��ռ䣬���Ұѿռ��ÿһ���ֽڶ���ʼ��Ϊ0
  //�뺯��malloc()������ֻ����calloc()���ڷ��ص�ַ֮ǰ������Ŀռ��ÿһ���ֽڶ���ʼ��Ϊ0.

int main()
{
	int* p = calloc(10, sizeof(int));
	if (NULL != p)
	{
		for (int i = 0; i < 10; i++)
		{
			*(p + i) = i + 1;
		}
	}
	free(p);
	p = NULL;

	system("pause");
	return 0;
}