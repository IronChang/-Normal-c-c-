#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include <algorithm>  
using namespace std;
 
const int MAXN = 1005;
 
int DP[MAXN][MAXN];
 
int main()
{
	string a;
	string b;
	while(cin >> a >> b)
	{
		int l1 = a.size();
		int l2 = b.size();
		memset(DP, 0, sizeof(DP)); 
		for(int i = 1; i <= l1; i++)
			for(int j = 1; j <= l2; j++)
				if(a[i - 1] == b[j - 1])
					DP[i][j] = max(DP[i][j], DP[i - 1][j - 1] + 1);
				else
					DP[i][j] = max(DP[i][j - 1], DP[i - 1][j]);
		printf("%d\n", DP[l1][l2]);
	}
	return 0;
}
