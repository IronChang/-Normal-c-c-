#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

//�ж��Ƿ�Ϊ����
//�����������ܱ�1�����������ⲻ�ܱ�������������
int main()
{
	 int i = 0;
	int count = 0;

	for (i = 100; i <= 200; i++)
	{
		int j = 0;
		for (j = 2; j <= i/2; j++)
		{
			if (i%j == 0)
			{
				break;
			}
		}
		if (j>(i/2))
		{
			printf("%d ", i);
			count++;
		}
	}
	printf("%d\n", count);
	system("pause");
	return 0;
}