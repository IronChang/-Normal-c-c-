#include<stdio.h>

/*��������*/ 
//ֱ�Ӳ�������

void InsertSort(int *arr,int n)
{
    int i = 0; 
	for(i;i<n-1;++i)
	{
		int end = i;
		int tmp = arr[end+1];
		
		while(end>=0)
		{
			if(tmp<a[end])
			{
				a[end+1] = a[end];
				--end;
			}
			else
			{
				break;
			}
		}
		a[end+1] = tmp;
	}
}
 
int main()
{
	return 0;
 } 
