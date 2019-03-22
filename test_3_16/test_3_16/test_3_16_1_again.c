//#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//#include<windows.h>
//#include<time.h>
//#include<math.h>

//二分查找
//int main()
//{
//	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//	int k = 7;
//	int left = 0;
//	int right = sizeof(arr) / sizeof(arr[0]) - 1;
//	int ret = Binary_Search(arr, k, left, right);
//
//	if (ret == -1)
//	{
//		printf("找不到\n");
//	}
//	else
//	{
//		printf("找到了：%d\n", ret);
//	}
//    system("pause");
//	return 0;
//}
//
//int  Binary_Search(int arr[], int k, int left, int right)
//{
//	
//	while (left <= right)
//	{
//         int mid = left + (right - left) / 2;
//		 if (k > arr[mid])
//		 {
//			 left = mid + 1;
//		 }
//		 else if (k < arr[mid])
//		 {
//			 right = mid - 1;
//		 }
//		 else
//		 {
//			 return mid;
//		 }
//	}
//	return -1;
//}

//二分查找
//int main()
//{
//	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//	int k = 8;
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int ret = Binary_Search(arr, k, sz);
//	if (ret == -1)
//	{
//		printf("找不到\n");
//	}
//	else
//	{
//		printf("找到了:%d\n", ret);
//	}
//    system("pause");
//	return 0;
//}
//int Binary_Search(int arr[],int k,int sz)
//{
//	int left = 0;
//	int right = sz - 1;
//
//	while (left <= right)
//	{
//		int mid = left + (right - left) / 2;
//
//		if (k > arr[mid])
//		{
//			left = mid + 1;
//		}
//		else if (k < arr[mid])
//		{
//			right = mid - 1;
//		}
//		else
//		{
//			return mid;
//		}
//	}
//	return -1;
//}

//字符移动
//int main()
//{
//	char arr1[] = "welcome to bit!!!!!!";
//	char arr2[] = "####################";
//	int left = 0;
//	int right = strlen(arr1) - 1;
//
//	while (left <= right)
//	{
//		arr2[left] = arr1[left];
//		arr2[right] = arr1[right];
//        printf("%s\n", arr2);
//		Sleep(1000);
//		system("cls");
//		left++;
//		right--;
//
//	}
//	system("pause");
//	return 0;
//}

////输入三次密码
//int main()
//{
//	int i = 0;
//	int password[20] = { 0 };
//
//	for (i = 0; i < 3; i++)
//	{
//		printf("请输入密码:>");
//		scanf("%s", password);
//		if (strcmp(password, "123456") == 0)
//		{
//			printf("登陆成功\n");
//			break;
//		}
//		else
//		{
//			printf("输入错误，从新输入!\n");
//		}
//	}
//	if (i == 3)
//	{
//		printf("三次失败，退出程序！");
//	}
//    system("pause");
//	return 0;
//}

////猜数字游戏
//void menu();
//void game();
//
//int main()
//{
//	int input = 0;
//	srand((unsigned int)time(NULL));//随机数发生器  强制对time()返回类型进行转换
//	do
//	{
//		menu();
//		printf("请选择;>");
//		scanf("%d", &input);
//		switch (input)
//		{
//		case 1:
//			game();
//			break;
//		case 0:
//			printf("退出游戏！\n");
//			break;
//		default:
//			printf("选择错误！\n");
//			break;
//		}
//
//	}while(input);//不为0条件为真死循环！
//    system("pause");
//	  return 0;
//}
//
//void menu()
//{
//	printf("************************************\n");
//	printf("************ 1.进行游戏 ************\n");
//	printf("************ 0.退出游戏 ************\n");
//	printf("************************************\n");
//}
//
//void game()
//{
//	int ret = 0;
//	int guess = 0;
//	ret = rand() % 100 + 1;//rand()生成随机数的范围0-32767,取余数是为了控制生成数的范围。
//   // printf("%d \n", ret);
//	while (1)
//   {
//		printf("猜猜该数字：>");
//		scanf("%d", &guess);
//
//    if (guess > ret)
//    {
//        printf("猜大了\n");
//     }
//    else if (guess < ret)
//   {
//        printf("猜小了\n");
//    }
//    else
//    {
//        printf("恭喜，猜对了\n");
//		break;
//    }
//  }
//	}

////goto语句的错误运用
//
//int main()
//{
//again:
//	printf("he he\n");
//	goto again;//导致死循环
//	system("pause");
//	return 0;
//}

////goto语句的正确运用
//
//int main()
//{
//	char input[20] = { 0 };
//	system("shutdown -s -t 120");
//again:
//	printf("请注意电脑将在两分钟内关机，如果输入;我是猪.将取消关机!\n");
//	scanf("%s", input);
//	if (strcmp(input, "我是猪") == 0)//strcmp(a,b)字符串比较函数；a==b 返回0；a>b 返回大于0；a<b 返回小于0；
//	{
//		system("shutdown -a");
//	}
//	else
//	{
//		goto again;
//	}
//    system("pause");
//	return 0;
//}

////字符串比较语句strcmp运用
//int main()
//{
//	char input[20] = { 0 };
//	system("shutdown -s -t 120");
//	printf("请注意，你的电脑会在两分钟后关机。如果输入:我是猪。会解锁\n");
//	while (1)
//	{
//		scanf("%s", input);
//		if (strcmp(input, "我是猪") == 0)
//		{
//			system("shutdown -a");
//			break;
//		}
//		else
//		{
//			printf("输入错误时间在减少还不投降\n");
//		}
//	}
//    system("pause");
//	return 0;
//}

//goto语句只能在自己的函数中运用（错误的例子）
//
//void test()
//{
//tag:
//	printf("he he\n");
//}
//int main()
//{
//	printf("he he\n");
//	goto tag;
//	system("pause");
//	return 0;
//}
//

////字符串复制函数strcpy的运用
//char * strcpy(char * destination, const char * source);//strcpy（a，b） a是要复制的地方 b被复制的
//
//int main()
//{
//	char arr1[20] = "aaaaaaaaa";
//	char arr2[] = "bit!!";
//	strcpy(arr1, arr2);
//	printf("%s\n", arr1);
//	system("pause");
//	return 0;
//}

////memset是计算机中C/C++语言初始化函数。作用是将某一块内存中的内容全部设置为指定的值， 这个函数通常为新申请的内存做初始化工作
////void *memset( void *dest, int ch, size_t count )
////函数解释：将dest中当前位置后面的count个字节 （typedef unsigned int size_t ）用 ch 替换并返回； s 
//
//int main()
//{
//	char arr[] = "hello world";
//	memset(arr, 'a', 5);
//	printf("%s\n", arr);
//    system("pause");
//	return 0;
//}

////判断100-200之间的素数
//int is_prime(int n)
//{
//	int i = 0;
//	for (i = 2; i < sqrt(n); i++)
//	{
//		if (n%i == 0)
//		{
//			return 0;
//		}
//		
//	}
//	return 1;
//}
//
//int main()
//{
//	int i = 0;
//	int count=0;
//	for (i = 100; i <= 200; i++)
//	{
//		if (is_prime(i) == 1)
//		{
//			printf("%d  ", i);
//			count++;
//		}
//	}
//	printf("%d", count);
//	system("pause");
//	return 0;
//}


//交换两个数的值封装成函数
////当实参传递给形参时，形参只是实参的一份临时拷贝且对形参的修改不会改变实参（就是封装函数时不能用值传递要用地址传递）
//void Swap(int *x, int *y)
//{
//	int temp = *x;
//	*x = *y;
//	*y = temp;
//}
//
//int main()
//{
//	int a = 10;
//	int b = 20;
//	printf("%d %d\n", a, b);
//	Swap(&a,&b);
//	printf("%d %d\n", a, b);
//	system("pause");
//	return 0;
//}

//比较两个数大小（封装成函数）外加三目运算符的运用；
//
//int Get_max(int x, int y)
//{
//	return (x > y) ? (x) : (y);//三目运算符
//}
//
//int main()
//{
//	int a = 20;
//	int b = 15;
//	int max = 0;;
//
//    max= Get_max(a, b);
//	printf("%d\n", max);
//	system("pause");
//	return 0;
//}