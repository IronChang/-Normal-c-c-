#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
//动态内存开辟
//动态内存函数malloc()和free()
//函数原型 : void* malloc(size_t size)
//函数原型 ：void* free(void* ptr)

//int main()
//{
//	int num = 0;
//	scanf("%d", &num);
//
//	int* ptr = NULL;
//	ptr = (int*)malloc(num*sizeof(int));
//	if (NULL != ptr)//判断ptr指针是否为空
//	{
//		int i = 0;
//		for (i = 0; i < num; i++)
//		{
//			*(ptr + i) = 0;//初始化空间申请的空间
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
//	free(ptr);//释放ptr所指向的动态内存
//	ptr = NULL;//置空  防止野指针
//	system("pause");
//	return 0;
//}

  //函数原型  void* calloc(size_t num,size_t size)
  //含义：为num个大小为size的元素开辟一块空间，并且把空间的每一个字节都初始化为0
  //与函数malloc()的区别只在于calloc()会在返回地址之前把申请的空间的每一个字节都初始化为0.

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