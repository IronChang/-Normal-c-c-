//#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//#include<windows.h>
//#include<time.h>
//#include<math.h>

//���ֲ���
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
//		printf("�Ҳ���\n");
//	}
//	else
//	{
//		printf("�ҵ��ˣ�%d\n", ret);
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

//���ֲ���
//int main()
//{
//	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//	int k = 8;
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int ret = Binary_Search(arr, k, sz);
//	if (ret == -1)
//	{
//		printf("�Ҳ���\n");
//	}
//	else
//	{
//		printf("�ҵ���:%d\n", ret);
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

//�ַ��ƶ�
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

////������������
//int main()
//{
//	int i = 0;
//	int password[20] = { 0 };
//
//	for (i = 0; i < 3; i++)
//	{
//		printf("����������:>");
//		scanf("%s", password);
//		if (strcmp(password, "123456") == 0)
//		{
//			printf("��½�ɹ�\n");
//			break;
//		}
//		else
//		{
//			printf("������󣬴�������!\n");
//		}
//	}
//	if (i == 3)
//	{
//		printf("����ʧ�ܣ��˳�����");
//	}
//    system("pause");
//	return 0;
//}

////��������Ϸ
//void menu();
//void game();
//
//int main()
//{
//	int input = 0;
//	srand((unsigned int)time(NULL));//�����������  ǿ�ƶ�time()�������ͽ���ת��
//	do
//	{
//		menu();
//		printf("��ѡ��;>");
//		scanf("%d", &input);
//		switch (input)
//		{
//		case 1:
//			game();
//			break;
//		case 0:
//			printf("�˳���Ϸ��\n");
//			break;
//		default:
//			printf("ѡ�����\n");
//			break;
//		}
//
//	}while(input);//��Ϊ0����Ϊ����ѭ����
//    system("pause");
//	  return 0;
//}
//
//void menu()
//{
//	printf("************************************\n");
//	printf("************ 1.������Ϸ ************\n");
//	printf("************ 0.�˳���Ϸ ************\n");
//	printf("************************************\n");
//}
//
//void game()
//{
//	int ret = 0;
//	int guess = 0;
//	ret = rand() % 100 + 1;//rand()����������ķ�Χ0-32767,ȡ������Ϊ�˿����������ķ�Χ��
//   // printf("%d \n", ret);
//	while (1)
//   {
//		printf("�²¸����֣�>");
//		scanf("%d", &guess);
//
//    if (guess > ret)
//    {
//        printf("�´���\n");
//     }
//    else if (guess < ret)
//   {
//        printf("��С��\n");
//    }
//    else
//    {
//        printf("��ϲ���¶���\n");
//		break;
//    }
//  }
//	}

////goto���Ĵ�������
//
//int main()
//{
//again:
//	printf("he he\n");
//	goto again;//������ѭ��
//	system("pause");
//	return 0;
//}

////goto������ȷ����
//
//int main()
//{
//	char input[20] = { 0 };
//	system("shutdown -s -t 120");
//again:
//	printf("��ע����Խ����������ڹػ����������;������.��ȡ���ػ�!\n");
//	scanf("%s", input);
//	if (strcmp(input, "������") == 0)//strcmp(a,b)�ַ����ȽϺ�����a==b ����0��a>b ���ش���0��a<b ����С��0��
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

////�ַ����Ƚ����strcmp����
//int main()
//{
//	char input[20] = { 0 };
//	system("shutdown -s -t 120");
//	printf("��ע�⣬��ĵ��Ի��������Ӻ�ػ����������:�����������\n");
//	while (1)
//	{
//		scanf("%s", input);
//		if (strcmp(input, "������") == 0)
//		{
//			system("shutdown -a");
//			break;
//		}
//		else
//		{
//			printf("�������ʱ���ڼ��ٻ���Ͷ��\n");
//		}
//	}
//    system("pause");
//	return 0;
//}

//goto���ֻ�����Լ��ĺ��������ã���������ӣ�
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

////�ַ������ƺ���strcpy������
//char * strcpy(char * destination, const char * source);//strcpy��a��b�� a��Ҫ���Ƶĵط� b�����Ƶ�
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

////memset�Ǽ������C/C++���Գ�ʼ�������������ǽ�ĳһ���ڴ��е�����ȫ������Ϊָ����ֵ�� �������ͨ��Ϊ��������ڴ�����ʼ������
////void *memset( void *dest, int ch, size_t count )
////�������ͣ���dest�е�ǰλ�ú����count���ֽ� ��typedef unsigned int size_t ���� ch �滻�����أ� s 
//
//int main()
//{
//	char arr[] = "hello world";
//	memset(arr, 'a', 5);
//	printf("%s\n", arr);
//    system("pause");
//	return 0;
//}

////�ж�100-200֮�������
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


//������������ֵ��װ�ɺ���
////��ʵ�δ��ݸ��β�ʱ���β�ֻ��ʵ�ε�һ����ʱ�����Ҷ��βε��޸Ĳ���ı�ʵ�Σ����Ƿ�װ����ʱ������ֵ����Ҫ�õ�ַ���ݣ�
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

//�Ƚ���������С����װ�ɺ����������Ŀ����������ã�
//
//int Get_max(int x, int y)
//{
//	return (x > y) ? (x) : (y);//��Ŀ�����
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