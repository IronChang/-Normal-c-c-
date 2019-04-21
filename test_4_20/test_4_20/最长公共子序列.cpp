#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
#define MAX 100

//计算最长公共子序列长度
void  LCSlength(char* x, char* y, int m, int n, int c[][MAX], int b[][MAX])
{
	int i = 0;
	int j = 0;

	memset(c, 0, sizeof(c));//初始化数组c

	for (i = 1; i <= m; i++)
	{
		for (j = 1; j <= n; j++)
		{
			if (x[i - 1] == y[j - 1])
			{
				c[i][j] = c[i - 1][j - 1] + 1;
				b[i][j] = 0;
			}
			else if (c[i - 1][j] > c[i][j - 1])
			{
				c[i][j] = c[i - 1][j];
				b[i][j] = 1;
			}
			else
			{
				c[i][j] = c[i][j - 1];
				b[i][j] = -1;
			}
		}
	}
}

//打印最长公共子序列
void PrintLCS(int b[][MAX],char* x, int i, int j)
{
	if (i == 0 || j == 0)
		return;
	if (b[i][j]==0)
	{
		PrintLCS(b, x, i - 1, j - 1);
		cout << x[i - 1] << " ";
	}
	else if (b[i][j] == 1)
	{
		PrintLCS(b, x, i - 1, j);
	}
	else
	{
		PrintLCS(b, x, i, j-1);

	}
}

int main()
{
	char x[MAX] = { "abcdefggigk" };
	char y[MAX] = { "acdefhglkm" };
	int b[MAX][MAX];
	int c[MAX][MAX];
	int n = 0;
	int m = 0;

	m = strlen(x);
	n = strlen(y);

	cout << "序列x:> " << x << endl;
	cout << "序列y:> " << y << endl;
	LCSlength(x, y, m, n,  c, b);
	cout << "最长公共子序列为:> ";
	PrintLCS(b, x, m, n);
	cout << endl;

	system("pause");
	return 0;
}