#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<assert.h>

/*1. strstr( ) Ѱ�����ַ���
����ԭ�� char *strstr( const char* str, const char* substr );
���壺�ж�str2�Ƿ�Ϊstr1���ִ��������򷵻�str2��str1���״γ��ֵ�ָ��λ�ã������Ƿ���NULL
ע�⣺ƥ����̲�������ֹ���ַ���������������ֹͣ��
�Ӵ������ַ������Ӽ������ҳ��ֵ�˳����ַ����г��ֵ�˳����һ���ģ���������
������:��һ����������
*/

char* strstr(const char* src, const char* sub)
{
	const char *bp;
	const char *sp;
	if (!src || !sub)
	{
		return src;
	}
	/* ����src�ַ���  */
	while (*src)
	{
		/* ���������Ӵ� */
		bp = src;
		sp = sub;
		do
		{
			if (!*sp)  /*����sub�Ľ���λ�ã�����srcλ��   */
				return src;
		} while (*bp++ == *sp++);
		src++;
	}
	return NULL;
}

int main()
{
	char p[] = "123456";
	char q[] = "23";
	char *r = strstr(p, q);
	printf("r:%s\n", r);
	getchar();
	system("pause");
	return 0;
}

/*2. strchr() ����ĳ���ַ��и��ַ���
����ԭ�� char * strchr ( const char *, int ); 
ע�⣺���ַ������ҵ���һ�����ֵ��ַ�������ָ��C�ַ���str�е�һ���ַ����ֵ�ָ�롣��ֹ���ַ�����Ϊ��C�ַ�����һ���֡�
��ˣ�Ҳ���Զ�λ���Ա����ָ���ַ���ĩβ��ָ�롣
ע�⣺�����ַ���s���״γ����ַ�c��λ��,�����״γ���c��λ�õ�ָ�룬���s�в�����c�򷵻�NULL��
*/

char*  my_strchr(const char* dst, int c)
{
	assert(dst);

	while (*dst != '\0')
	{
		if (*dst == c)
		{
			return dst;
		}
		dst++;
	}
	return NULL;
}

int main()
{
	char a[] = { "hello world!" };
	char c = 0;
	scanf("%c", &c);
	printf("%s\n", my_strchr(a, c));
	system("pause");
	return 0;
}