#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

//int main()
//{
//	int a = 98;
//	int b = 888;
//	int c = 0;
//	c = a > b ? a : b;//条件操作符（三目操作符）
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
//	printf("%p\n", &arr);//取出数组的地址
//	printf("%p\n", &arr+1);//加一个完整的数组大小
//
//	system("pause");
//	return 0;
//}

//int main()
//{
//	int a = 10;
//	printf("%d\n", sizeof(int));//计算类型时不可以省略括号
//	printf("%d\n", sizeof(int));
//	printf("%d\n", sizeof a );//计算变量是可以省略括号
//
//	int arr[10] = { 0 };
//	printf("%d\n", sizeof(arr));//当且仅当放入数组名时，sizeof计算的是数组整个大小。此时arr表示的是整个数组
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
//	printf("%d\n", ~a);  //按位取反操作符
//	system("pause");
//	return 0;
//}

//int main()
//{
//	int a = 3;
//	int b = 0;
//	printf("%d\n", a && b);//逻辑与  全真才真
//	printf("%d\n", a || b);//逻辑或  全假才假
//
//	system("pause");
//	return 0;
//}

////结构体
//struct stu
//	{
//		char name[20];
//		short age;
//		char sex[10];
//	};
//print(struct stu* s)
//{
//	printf("%s %d %s\n", s->name, s->age, s->sex);// "->"针对结构体指针
//
//}
//int main()
//{
//	struct stu s = {"张三",20,"男"};
//	printf("%s %d %s\n", s.name, s.age, s.sex);//"."针对结构体本 身
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
//	//int c;11111111111111111111111110000010//类型转换无符号补原符号位-补码
//	//10000000000000000000000001111110-原码   （补码-1取反）
//	//-（2+4+8+16+32+64）=-126
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

