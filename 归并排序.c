void MergeSort(int* arr,int n)
{
	int* tmp = new int[n];
	_MergeSort(arr,0,n-1,tmp);
	delete[] tmp;
}

_MergeSort(int* arr,int left,int right,int* tmp)
{
	if(left == right)
		return ;
	
	//分解
	int mid = left + (right - left)/2;
	_MergeSort(arr,left,mid,tmp);
	_MergeSort(arr,mid+1,right,tmp);
	
	//归并
	int begin1 = left,end1 = mid;
	int begin2 = mid+1,end2 = right;
	int i = left;
	
	while(begin1 <= end1 && begin2 <= end2)
	{
		if(arr[begin1] < arr[begin2])
		{
			tmp[i++] = arr[begin1++];
		}
		else
		{
			tmp[i++] = arr[beign2++];
		}
	}
	
	while(begin1 <= end1)
	{
		tmp[i++] = arr[begin1++];
	}
	
	while(beign2 <= end2)
	{
		tmp[i++] = arr[begin2++];		
	}
	
	memcpy(arr+left,tmp + left,sizeof(int)*(i-left));
}