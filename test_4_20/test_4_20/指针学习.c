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
//	//一维数组
//	//sizeof()是运算符，计算时看的是参数自身类型，除数组名除外
//	//int a[] = { 1, 2, 3, 4 };
//	//printf("%d\n", sizeof(a));//16
//	//printf("%d\n", sizeof(a + 0));//指针 4
//	//printf("%d\n", sizeof(*a));//整形 4
//	//printf("%d\n", sizeof(a + 1));//指针 4
//	//printf("%d\n", sizeof(a[1]));//整形 4
//	//printf("%d\n", sizeof(&a));//数组的地址，也就相当于数组指针4
//	//printf("%d\n", sizeof(*&a));//整个数组 16
//	//printf("%d\n", sizeof(&a + 1));//指针 4
//	//printf("%d\n", sizeof(&a[0]));//指针 4
//	//printf("%d\n", sizeof(&a[0] + 1));//指针 4
//
//
//	//char arr[] = { 'a', 'b', 'c', 'd', 'e', 'f' };//不完全初始化，没有'\0'
//	//printf("%d\n", sizeof(arr));  //6
//	//printf("%d\n", sizeof(arr + 0)); //指针 4
//	//printf("%d\n", sizeof(*arr)); // char类型 1
//	//printf("%d\n", sizeof(arr[1])); //char类型 1
//	//printf("%d\n", sizeof(&arr));//数组的地址 ，也就相当于数组指针 4
//	//printf("%d\n", sizeof(&arr + 1));//指针 4
//	//printf("%d\n", sizeof(&arr[0] + 1));//指针 4
//
//	//strlen（）不能传入数组的地址，以及类型
//	//printf("%d\n", strlen(arr)); // 数组名这个数组没有‘\0’,数值随机 （特殊代表整个数组）
//	//printf("%d\n", strlen(arr + 0)); // 同上
//	////printf("%d\n", strlen(*arr)); // 编不过
//	////printf("%d\n", strlen(arr[1])); // 编不过
//	////printf("%d\n", strlen(&arr));// 编不过
//	////printf("%d\n", strlen(&arr + 1)); // 随机
//	//printf("%d\n", strlen(&arr[0] + 1)); // 数组没有'\0'
//
//
//	//char arr[] = "abcdef";//进行完全初始化，有‘\0’
//	//printf("%d\n", sizeof(arr)); // 7 szieof()函数,参数是数组时计算编译时分配给数组的空间大小
//	//printf("%d\n", sizeof(arr + 0)); //指针4
//	//printf("%d\n", sizeof(*arr)); //char 类型 1
//	//printf("%d\n", sizeof(arr[1])); //char 类型 1
//	//printf("%d\n", sizeof(&arr)); //数组地址 就相当于数组指针 4
//	//printf("%d\n", sizeof(&arr + 1)); //指针 4
//	//printf("%d\n", sizeof(&arr[0] + 1)); //指针 4
//
//	//printf("%d\n", strlen(arr)); //6  strlen（）计算字符串长度，不包含结束符 （特殊代表整个数组）
//	//printf("%d\n", strlen(arr + 0));//6 同上
//	////printf("%d\n", strlen(*arr));//编不过
//	////printf("%d\n", strlen(arr[1]));//编不过
//	////printf("%d\n", strlen(&arr));//编不过
//	////printf("%d\n", strlen(&arr + 1));编不过
//	//printf("%d\n", strlen(&arr[0] + 1)); //5 首地址向后移1位
//
//
//	//char *p = "abcdef";//指针指向常量字符串，有'\0'
//	//printf("%d\n", sizeof(p)); //指针 4
//	//printf("%d\n", sizeof(p + 1)); //指针 4
//	//printf("%d\n", sizeof(*p));//char 1
//	//printf("%d\n", sizeof(p[0])); //char 1
//	//printf("%d\n", sizeof(&p));//指针 4
//	//printf("%d\n", sizeof(&p + 1)); //指针 4
//	//printf("%d\n", sizeof(&p[0] + 1));//指针 4
//
//	//printf("%d\n", strlen(p)); //6 计算指针p所指向的常量字符串 （特殊代表整个数组）
//	//printf("%d\n", strlen(p + 1)); //5 首地址向后移1位
//	///*printf("%d\n", strlen(*p));
//	//printf("%d\n", strlen(p[0]));
//	//printf("%d\n", strlen(&p));
//	//printf("%d\n", strlen(&p + 1));编不过*/
//	//printf("%d\n", strlen(&p[0] + 1));//5 将首元素地址向后移1位
//
//
////	int a[3][4] = { 0 };
////	printf("%d\n", sizeof(a)); //48 a就相当于数组地址 特殊情况
////	printf("%d\n", sizeof(a[0][0])); //int 4
////	printf("%d\n", sizeof(a[0])); //16 在二维数组中 a[0]表示第一行数组的首地址，
////	printf("%d\n", sizeof(a[0] + 1)); //4 指针
////	printf("%d\n", sizeof(*(a[0] + 1))); //表示第二行数组首元素 int 4
////	printf("%d\n", sizeof(a + 1));// 4 指针
////	printf("%d\n", sizeof(*(a + 1))); //16 第一行数组+1解引用表示整个数组
////	printf("%d\n", sizeof(&a[0] + 1)); //指针 4 &a[0]是第一行地址 数组指针
////	printf("%d\n", sizeof(*(&a[0] + 1))); //16  第一行数组地址+1在解引用表示整个数组
////	printf("%d\n", sizeof(*a));//16 第一行数组的整个数组
////	printf("%d\n", sizeof(a[3])); //16  在二维数组当中a[i]酒标偶是第几行的数组地址
//
////	// 二维数组中，a[i]就是第i行的数组名
////	printf("%p\n", a[0]); // a[0]是第一行首元素的地址
////	printf("%p\n", a[0] + 1);
////	int* p0 = a[0];
//
////	printf("%p\n", &a[0]); // &a[0]是第一行地址 数组指针
////	printf("%p\n", &a[0] + 1);
////	int(*p1)[4] = &a[0];
//
////	system("pause");
////	return 0;
////}
//
////一级指针传参
//void swap1(int* ptr1, int* ptr2)
//{
//	int x = *ptr1;
//	*ptr1 = *ptr2;
//	*ptr2 = x;
//}
//
////二级指针传参
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