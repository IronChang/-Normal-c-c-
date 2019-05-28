#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<assert.h>
#include<windows.h>

//����ת��λ�ַ���

char* MY_Itoa(int num, char* array)
{
	assert(array);//�������������Ƿ�Ϊ��
	int i = 0;
	int flag = 0;

	if (num<0)//���Ҫת�����Ǹ���
	{
		num = 0 - num;//�ȰѸ����������
		flag = 1;
	}

	while (num>0)
	{
		array[i] = num % 10 + '0';//��ÿһλ�����ַ�0�������α���ַ���
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

	array[i] = '\0';//�������ַ������н�����
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

