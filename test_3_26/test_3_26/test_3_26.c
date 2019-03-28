#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	//上三角形
//	int i = 0; 
//	int j = 0;
//	for (i=1; i <= n; i++)
//	{
//		//打印空格
//		for (j = 1; j <= n - i; j++)
//		{
//			printf(" ");
//		}
//		//打印*号
//		for (j = 1; j <= 2 * i - 1; j++)
//		{
//			printf("*");
//		}
//		printf("\n");
//	}
//
//	//打印下三角
//	for (i = 1; i < n; i++)
//	{
//		//打印空格
//		for (j = 1; j <= i; j++)
//		{
//			printf(" ");
//		}
//		for (j = 1; j <= 2 * (n - i) - 1; j++)
//		{
//			printf("*");
//		}
//		printf("\n");
//	}
//
//	system("pause");
//	return 0;
//}

//int main()//求水仙花数
//{
//	int i = 0;
//	int n = 0;
//	int m = 0;
//	scanf("%d %d", &n, &m);
//	for (i = n; i <m; i++)
//	{
//		int length=0;
//		int temp=i;
//		while (temp)
//		{
//			temp /= 10;
//			length++;
//		}
//	  int sum = 0;
//	  int n = i;
//     while (n)
//	{
//		int num=n % 10;
//		sum += pow(num, length);
//		n /= 10;
//	 }
//	 if (sum == i)
//	 {
//		 printf("%d\n", i);
//	 }
//	}
//	system("pause");
//	return 0;
//}

//
//int main()
//{
//	int a;
//	int n = 0;
//	scanf("%d %d", &a, &n);
//	int i = 0;
//	int sum = 0; 
//	int temp = 0;
//	for(i = 0; i < n; i++)
//	{
//		temp = temp * 10 + a;
//		printf("%d\n", temp);
//		sum += temp;
//	}
//	//printf("%d\n", 0xffffffff);
//	printf("%d\n", sum);
//	system("pause");
//	return 0;
//}

//猜数字游戏
//void menu()
//{
//	printf("****************************************\n");
//	printf("*************    1.play     ************\n");
//	printf("*************    0.exit     ************\n");
//	printf("****************************************\n");
//}
//
//void game()
//{
//	int ret = rand() % 100 + 1;
//	int n = 0;
//	
//	while (1)
//	{
//		printf("请输入数字：");
//		scanf("%d", &n);
//		if (ret > n)
//		{
//			printf("猜小了\n");
//		}
//		else if (ret < n)
//		{
//			printf("猜大了\n");
//		}
//		else
//		{
//			printf("猜对了\n");
//			break;
//		}
//	}
//}
//
//int main()
//{
//	
//	srand((unsigned int)time(NULL));
//	int input = 0;
//
//	do
//	{   menu();
//    	scanf("%d", &input);
//		switch (input)
//		{
//		case 1:
//			game();
//			break;
//		case 0:
//			printf("退出游戏！！\n");
//			break;
//		default:
//			printf("输入错误，请再次输入！\n");
//			break;
//		}
//	}while (input);
//	system("pause");
//	return 0;
//}

////二分查找
//int binary_search(int arr[], int key, int left, int right)
//{
//	
//	while (left <= right)
//	{
//		int mid = left + (right - left) / 2;
//		if (arr[mid] > key)
//		{
//			right = mid - 1;
//		}
//		else if (arr[mid] < key)
//		{
//			left = mid + 1;
//		}
//		else
//		{
//			return mid;
//		}
//	}
//	return -1;
//}
//int main()
//{
//	int a[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//	int key = 0;
//	int left = 0;
//	int right = sizeof(a) / sizeof(a[0]) - 1;
//	int ret = 0;
//	printf("请输入要查找的数:>");
//	scanf("%d",&key);
//	ret=binary_search(a, key, left, right);
//	if (ret == -1)
//	{
//		printf("没有找到！！！\n");
//	}
//	else
//	{
//		printf("找到了，下标为:%d\n", ret);
//	}
//	system("pause");
//	return 0;
//}

//int main()
//{
//	char* p = { "123456mmp" };
//	int i = 0;
//	char a[100];
//    printf("请输入密码:>");
//	for (i = 0; i < 3; i++)
//	{
//		
//		scanf("%s", a);
//		if (strcmp(a, p) == 0)
//		{
//			printf("登陆成功！\n");
//			break;
//		}
//		else
//		{
//			printf("输入错误，请在此输入:>");
//		}
//	}
//	if (i == 3)
//	{
//		printf("三次输入失败，推出登陆！\n");
//	}
//	system("pause");
//	return 0;
//}