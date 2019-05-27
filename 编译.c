#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<windows.h>

//宏和函数的对比
//续行符与后面的语句之间不能有其他东西  
#define PRINT(FORMAT,VALUE) \
	printf("the value is " #VALUE" is "FORMAT"\n", VALUE);
// #VALUE 意思就是在预处理时进行宏替换时将VALUE变为"value"
/*int main()
{
	int i = 10;
	PRINT("%d", i+3);
	//替换为
	printf("the value is " "i+3 " "is ""%d",i+3);

	system("pause");
	return 0;
}
*/
//用宏写一个交换任意类型的数据且宏参数中可以出类型
//tmp##NAME  含义就是  把c和NAME续在一起 
//防止多次调用函数 造成重名报错
//相反正因为有参数，所以也相对地不够严谨
#define SWAP(Type,NAME,x1,x2) \
	Type tmp##NAME = x1;       \
	x1 = x2;             \
	x2 = tmp##NAME;

/*int main()
{
	int x1 = 10;
	int x2 = 20;
	printf("%d %d\n", x1, x2);
	SWAP(int, 1,x1, x2);
	printf("%d %d\n", x1, x2);
	SWAP(int, 2, x1, x2);
	printf("%d %d\n", x1, x2);
	system("pause");
	return 0;
}
*/

//带副作用的宏函数
#define  MAX(a,b) ((a)>(b)?(a):(b))//用括号防止优先级竞争

/*int main()
{
	int x = 5;
	int y = 8;
	int z = MAX(x++, y++);
	//int z = ((x++) > (y++) ? (x++) : (y++));
	//int z = ((5++) > (8++) ? (5++) : (8++))
	//x加了一次， y加了两次
	printf("x=%d,y=%d,z=%d" , x, y, z);

	system("pause");
	return 0;
}*/

