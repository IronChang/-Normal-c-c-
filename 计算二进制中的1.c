/*
题目：求unsigned int型变量在内存中二进制1的个数
思路：
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
