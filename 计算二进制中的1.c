/*
��Ŀ����unsigned int�ͱ������ڴ��ж�����1�ĸ���
˼·��
*/

int Numberof1(int n)
{
	int count = 0;;
	while (n)
	{
		++count;
		n = (n - 1)&n;
	}
	return count;
}

int main()
{
	printf("%d\n", Numberof1(2));
    system("pause");
	return 0;
} 
