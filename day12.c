
void test9()
{
	int a = -10;
	int *p = NULL;
	printf("%d\n", !2);
	printf("%d\n", !0);
	a = -a;
	p = &a;
	printf("%d\n", sizeof(a));
	printf("%d\n", sizeof(int));
	printf("%d\n", sizeof a);//这样写行不行？
	//printf("%d\n", sizeof int);//这样写行不行？
}


void test10(int arr[])
{
	printf("%d\n", sizeof(arr));//(2)
}
void test11(char ch[])
{
	printf("%d\n", sizeof(ch));//(4)
}
void test12()
{
	int arr[10] = { 0 };
	char ch[10] = { 0 };
	printf("%d\n", sizeof(arr));//(1)
	printf("%d\n", sizeof(ch));//(3)
	test10(arr);
	test11(ch);
}

void test13()
{
	int i = 0, a = 0, b = 2, c = 3, d = 4;
	i = a++ && ++b && d++;
	printf("a = %d\n b = %d\n c = %d\nd = %d\n", a, b, c, d);
}

void test14()
{
	int a = 1;
	int b = 2;
	int c = (a > b, a = b + 10, b = a + 1);
}

void test15()
{
	char c = 1;
	printf("%u\n", sizeof(c));
	printf("%u\n", sizeof(+c));
	printf("%u\n", sizeof(!c));
}
int main()
{

	test15();

	system("pause");
	return 0;
}
