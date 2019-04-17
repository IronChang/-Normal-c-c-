#define _CRT_SECURE_NO_WARNINGS 1
#include<stdlib.h>
#include<stdio.h>

//int main()
//{
//	char ch = 'w';
//	char* pc = &ch;
//	printf("%c\n", *pc);
//	*pc = 'f';
//	printf("%c\n", *pc);
//
//	system("pause");
//    return 0;
//}

//int main()
//{
//	char* pstr = "hello bit";
//	printf("%s\n", pstr);
//
//	system("pause");
//	return 0;
//}

int main()
{
	char str1[] = "hello bit.";
	char str2[] = "hello bit.";
	char *str3 = "hello bit.";
	char *str4 = "hello bit.";

	if (strcmp(str1,str2)==0)
		printf("str1 and str2 are same\n");
	else
		printf("str1 and str2 are not same\n");

	if (str3 == str4)
		printf("str3 and str4 are same\n");
	else
		printf("str3 and str4 are not same\n");

	system("pause");
	return 0;
}