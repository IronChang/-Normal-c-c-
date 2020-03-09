void test16()
{
	//int a = 10;
	//int *p = &a;
	//printf("&a = %p\n", &a);
	//printf("b = %p\n", p);
	//printf("&b = %p\n", &p);



}

//内存编址 一个内存单元为1字节大小
//32位机器侠，内存编址空间大小为4GB，32下有32根地址线，寻址是假设没很地址线可以产生一个电讯号，那么32位就会产生2^32次方的地址，同理64位下也是可以计算，前面可知指针就是存储地址的变量，那么变量是多大呢？因为32位下和64位下，地址的长度都不一样那么指针可定也是不一样的，32位地址长度位需要四个字节存储，但是64位下地址需要8个字节存储。

//可知指针存储就是指向变量所在内存空间的首地址，但是变量有不同的类型，那么指针可定也是有不同的类型，指针类型表明，所指向内存空间中变量的类型；  type + * +指针名

void test17()
{
	int n = 10;
	char *pc = (char*)&n;
	int* pi = &n;

	printf("%p\n", &n);
	printf("%p\n", pc);
	printf("%p\n", pc + 1);
	printf("%p\n", pi);
	printf("%p\n", pi + 1);

	//指针类型决定指针向前或者向后移动一步走多大距离；
}

void test18()
{
	//int n = 0x11223344;
	//char* pc = (char*)&n;
	//int* pi = &n;

	////*pc = 0;
	//printf("%d\n", *pc);
	//*pi = 0;


	int arr[5] = { 0 };
	printf("%p\n", arr);
	printf("%p\n", &arr[0]);
}

//void test20()
//{
	//指针运算
//#define N_VALUES 5
//	float values[N_VALUES];
//	float *vp;
//	//指针+-整数；指针的关系运算
//	for (vp = &values[0]; vp < &values[N_VALUES];)
//	{
//		*vp++ = 0;
//	}
//}

int test19(char* s)//计算字符串长度，相当于模拟实现strlen（）
{
	char *p = s;
	while (*p != '\0')
	{
		p++;
	}
	return p - s;
}

void test21()
{
	//数组名相当于首元素的地址
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	int *p = arr;
	int sz = sizeof(arr) / sizeof(arr[0]);
	//for (int i = 0; i < sz; i++){
	//	printf("&arr[%d] = %p   ========= p+%d = %p\n", i, &arr[i], i, p + i);
	//}

	//遍历数组元素除了利用下标运算符[] 和可以利用指针来遍历

	for (int i = 0; i < sz; i++)
	{
		printf("%d ", *(p + i));
	}
}

//指针也是一个变量，是变量就会有地址，那么指针的地址由谁存储。那就是二级指针

void test()
{
	int a = 10;
	int *pa = &a;//一级指针
	int **ppa = &pa;//二级指针



}

//指针数组和数组指针
//指针数组是数组，内面存放的数据是指针
//数组指针是指针，存放的是数组的地址


int main()
{

	//int ret = test19("hello world");

	//printf("%d\n", ret);

	test21();
	system("pause");
	return 0;