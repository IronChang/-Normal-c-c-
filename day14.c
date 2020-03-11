void test22()
{
	int n = 10;
	char* pc = (char*)&n;
	int *pi = &n;

	printf("%p\n", &n);
	printf("%p\n", pc);
	printf("%p\n", pc + 1);
	printf("%p\n", pi);
	printf("%p\n", pi + 1);
	
}

void test23()
{
	int n = 0x11223344;
	char *pc = (char *)&n;
	int *pi = &n;
	printf("%d\n", *pc);
	printf("%d\n", *pi);

	
}

void test24()
{
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	printf("%p\n", arr);
	printf("%p\n", &arr[0]);

}

int main()
{

	//int ret = test19("hello world");

	//printf("%d\n", ret);

	test24();
	system("pause");
	return 0;
}