#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<assert.h>
#include<windows.h>

//整形转换位字符串

char* MY_Itoa(int num, char* array)
{
	assert(array);//检查输入的数组是否为空
	int i = 0;
	int flag = 0;

	if (num<0)//如果要转换的是负数
	{
		num = 0 - num;//先把负数变成正数
		flag = 1;
	}

	while (num>0)
	{
		array[i] = num % 10 + '0';//把每一位加上字符0，从整形变成字符型
		num /= 10;
		++i;
	}

	if (flag == 1)
	{
		array[i++] = '-';
	}

	int left = 0;
	int right = i-1;
	while (left < right)
	{
		char tmp = array[left];
		array[left] = array[right];
		array[right] = tmp;
		++left;
		--right;
	}

	array[i] = '\0';//最后加上字符串独有结束符
	return array;
}



int main()
{
	int a = -1234;
	char stuff[] = { "-1234" };
	
	MY_Itoa(a, stuff);
	printf("%s", stuff);

	system("pause");
	return 0;
}

