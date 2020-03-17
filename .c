enum Color//颜色
{
	RED = 1,
	GREEN = 2,
	BLUE = 4
};

enum DAY
{
	MON = 1, TUE, WED, THU, FRI, SAT, SUN
} day;

//int main()
//{
//	// 遍历枚举元素
//	for (day = MON; day <= SUN; day++) {
//		printf("枚举元素：%d \n", day);
//	}
//	system("pause");
//}

#include <stdio.h>
#include <stdlib.h>
//int main()
//{
//
//	enum color { red = 1, green, blue };
//
//	enum  color favorite_color;
//
//	/* ask user to choose color */
//	printf("请输入你喜欢的颜色: (1. red, 2. green, 3. blue): ");
//	scanf("%d", &favorite_color);
//
//	/* 输出结果 */
//	switch (favorite_color)
//	{
//	case red:
//		printf("你喜欢的颜色是红色");
//		break;
//	case green:
//		printf("你喜欢的颜色是绿色");
//		break;
//	case blue:
//		printf("你喜欢的颜色是蓝色");
//		break;
//	default:
//		printf("你没有选择你喜欢的颜色");
//	}
//
//	system("pause");
//	return 0;
//}


#include <stdio.h>
#include <stdlib.h>
//int main()
//{
//
//	enum color { red = 1, green, blue };
//
//	enum  color favorite_color;
//
//	/* ask user to choose color */
//	printf("请输入你喜欢的颜色: (1. red, 2. green, 3. blue): ");
//	scanf("%d", &favorite_color);
//
//	/* 输出结果 */
//	switch (favorite_color)
//	{
//	case red:
//		printf("你喜欢的颜色是红色");
//		break;
//	case green:
//		printf("你喜欢的颜色是绿色");
//		break;
//	case blue:
//		printf("你喜欢的颜色是蓝色");
//		break;
//	default:
//		printf("你没有选择你喜欢的颜色");
//	}
//
//	return 0;
//}


union un
{
	int i;
	char c;
};
union un pp;


union Un1
{
	char c[5];
	int i;
};
union Un2
{
	short c[7];
	int i;
};
//下面输出的结果是什么？



int main()
{
	//printf("%p\n", &(pp.i));
	//printf("%p\n", &(pp.c));

	//pp.i = 0x11223344;
	//pp.c = 0x55;

	//printf("%x\n", pp.i);

	printf("%d\n", sizeof(union Un1));//输出
	printf("%d\n", sizeof(union Un2));//输出

	system("pause");
	return 0;
}





