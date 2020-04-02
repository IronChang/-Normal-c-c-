void partsort(int* a,int left,int right)//前后指针法
{
	//排升序
	int cur = left;
	int prev = left -1;//
	int key = a[right];
	
	while(cur<right)
	{
		if(a[cur]<key && ++prev!=cur)
		{
			Swap(&a[cur],&a[prev]);
		}
		++cur;
	}
	++prev;
	Swap(&a[prev],&a[right]);
	return prev;
}

void QuickSort(int* a,int left,int right)
{
	if(left>=right)
		return;
	
	int key = partsort(a,left,right);
	QuickSort(a,left,key-1);
	QuickSort(a,key+1,right);
}

//逆序打印单链表--递归实现
void  Print(int* node)
{
	if(node ->next == nullptr)
	{
		return ;
	}
	
	Print(node->next);
	
	printf("%d",node->val);
}