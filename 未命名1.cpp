#include<stdio.h>
#include<string.h>

int main()
{
	char a1[]="hello\0world";
	char a2[15]={0};
	strcpy(a2,a1);
	printf("%d\n",strlen(a2));
	printf("%d\n",sizeof(a1));
	printf("%s\n",a2);
	return 0;
 } 
