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

//int main()
//{
//	char p[] = "123456";
//	char q[] = "23";
//	char *r = strstr(p, q);
//	printf("r:%s\n", r);
//	getchar();
//	system("pause");
//	return 0;
//}

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

//int main()
//{
//	char a[] = { "hello world!" };
//	char c = 0;
//	scanf("%c", &c);
//	printf("%s\n", my_strchr(a, c));
//	system("pause");
//	return 0;
//}

/*3. memcpy()  �����ڴ��
����ԭ�� ��void * memcpy ( void * destination, const void * source, size_t num );
ע�⣺��numָ���λ�õ�num���ֽ�ֱֵ�Ӹ��Ƶ�destinationָ����ڴ�顣
Դ��Ŀ��ָ��ָ��Ķ���Ļ���������˺����޹�;��������ݵĶ����Ƹ�����
�ú��������Դ�е��κ���ֹ���ַ� - ��ʼ�ո��ƾ�ȷ��num���ֽڡ�
Ϊ���������Ŀ���Դ����ָ��������СӦ����Ϊnum���ֽڣ�
���Ҳ�Ӧ�ص��������ص����ڴ�飬memmove��һ�ָ���ȫ�ķ�������
*/

void* my_memcpy(void* dst,const void* src, int n)
{
	assert(dst && src);//��֤����ĵ�ַ����Ϊ��

	char* ret = dst;//�ݴ潫��Ҫ���ص��׵�ַ
	while (n--)
	{
		*(char*)dst = *(const char*)src;//void���Ͳ��ܽ��н�����Ҫ����ǿ������ת��
		++(char*)dst;//ͬ��void���Ͳ��ܽ���++��--
		++(char*)src;
	}
	return ret;
}

//int main()
//{
//	int arr1[10] = { 0 };
//	int arr2[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//	my_memcpy(arr1, arr2, sizeof(arr2));
//	int sz = sizeof(arr1) / sizeof(arr1[0]);
//	for (int i = 0; i < sz; i++)
//	{
//		printf("%d ", arr1[i]);
//	}
//	system("pause");
//	return 0;
//}


/*4. memmove()  �ƶ��ڴ�� �ڴ���������������ַ������������Դ��������������
����ԭ�� ��void * memmove��void * destination��const void * source��size_t num��;
ע�⣺��num�ֽڵ�ֵ��sourceָ���λ�ø��Ƶ�destinationָ����ڴ�顣���ƾ���ʹ���м仺����һ��������Ŀ���Դ�ص���Դָ���Ŀ��ָ��ָ��
�Ķ���Ļ���������˺����޹�; ��������ݵĶ����Ƹ����� �ú��������Դ�е��κ���ֹ���ַ�- ��ʼ�ո��ƾ�ȷ��num���ֽڡ� Ϊ�˱������������Ĵ�С������ָ��
Ŀ���Դ����Ӧ����Ϊnum���ֽڡ�
*/

void* my_memmove(void* dst, const void* src, int n)
{
	assert(dst && src);//�ж�����ĵ�ַ�Ƿ�Ϊ��
	char* ret = dst;//�ݴ�dst�ص�ַ����󷵻�

	if ((char*)dst <= (char*)src && (char*)dst >= (char*)src + n)//��������´�ǰ���󿽱�  
	{
		while (n--)
		{
			*(char*)dst = *(char*)src;//��Ҫע��ǿ������ת��
		}
	}
	else//�������ڴ渲��ʱ�Ӻ���ǰ����  
	{
		while (n--)
		{
			*((char*)dst + n) = *((char*)src + n);//��Ҫע��ǿ������ת��
		}
	}
	return ret;
}

int main()
{
	char str[] = "memmove can be very useful......";
	my_memmove(str + 20, str + 15, 11);
	puts(str);
    system("pause");
	return 0;
}
	

