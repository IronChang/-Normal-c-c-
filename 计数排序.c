
//计数排序
void CountSort(int *a, int len)
{
	assert(a);
	//通过max和min计算出临时数组所需要开辟的空间大小
	int max = a[0], min = a[0];
	for (int i = 0; i < len; i++)
	{
		if (a[i] > max)
			max = a[i];
		if (a[i] < min)
			min = a[i];
	}
	//使用calloc将数组都初始化为0
	int range = max - min + 1;
	
	//int *b = (int *)calloc(range, sizeof(int));//申请空间和初始化空间
	int* b = (int *)malloc(sizeof(int)*range);
	memset(b, 0, sizeof(int)*range);
	//使用临时数组记录原始数组中每个数的个数
	for (int i = 0; i < len; i++){
		//注意：这里在存储上要在原始数组数值上减去min才不会出现越界问题
		b[a[i] - min] += 1;
	}
	int j = 0;
	//根据统计结果，重新对元素进行回收
	for (int i = 0; i < range; i++){
		while (b[i]--){
			//注意：要将i的值加上min才能还原到原始数据
			a[j++] = i + min;
		}
	}
	//释放临时数组
	free(b);
	b = NULL;

}