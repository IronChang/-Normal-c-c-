#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

//int main()
//{
//	FILE* fin = fopen("input.txt", "w");//���ļ���д�ı��ļ�
//	fputc("x", fin);
//	fflush(fin);
//	fputs("\nhello", fin);
//	fclose(fin);
//
//	system("pause");
//	return 0;
//}

//int main()
//{
//	FILE* fin = fopen("intput.txt", "w");//�������ݵ��ļ�
//	fprintf(fin, "����:%d\n��ѧ:%d\nӢ��:%d\n����:%d\n", 98, 100, 99, 2);
//	fclose(fin);
//	system("pause");
//	return 0;
//}
//
//int main()
//{
//	FILE* fout = fopen("intput.txt", "r");//�������ݴ��ļ�
//	int a, b, c, d;
//	fscanf(fout, "����:%d\n��ѧ:%d\nӢ��:%d\n����:%d\n", &a, &b, &c, &d);
//	printf("����:%d\n��ѧ:%d\nӢ��:%d\n����:%d\n", a, b, c, d);
//	fclose(fout);
//	system("pause");
//	return 0;
//}


#include<assert.h>
#include<string.h>

struct TelInfo
{
	char _tel[16];
	char _name[24];
	int _age;
};
//
//char* my_itoa(int num, char* buff)//����ת��Ϊ�ַ���
//{
//	assert(buff);
//	int i = 0;
//	int flag = 0;
//	if (num<0)//���������Ǹ����Ƚ���ת��λ����
//	{
//		flag = 1;
//		num = 0 - num;
//	}
//	while (num > 0)//��������λת�����ַ���
//	{
//		buff[i] = num % 10 + '0';
//		num /= 10;
//		++i;
//	}
//	if (flag == 1)//����ϸ���
//	{
//		buff[i++] = '-';
//	}
//
//	int begin = 0;
//	int end = i - 1;
//	while (begin < end)
//	{
//		char tmp_ch = buff[end];
//		buff[end] = buff[begin];
//		buff[begin] = tmp_ch;
//		++begin;
//		--end;
//	}
//	buff[i] = '\0';
//
//	return buff;
//}
//
//int main()
//{
//	struct TelInfo info;
//	strcpy(info._name, "Ƥ��");
//	strcpy(info._tel, "18516283077");
//	info._age = 19;
//
//	 //�ı���д
//	FILE* fout_text = fopen("input_text.txt", "w");//������ݵ��ļ�
//	fputs(info._name, fout_text);
//	fputc('\n', fout_text);
//
//	fputs(info._tel, fout_text);
//	fputc('\n', fout_text);
//
//	char age_buff[12];
//	my_itoa(info._age, age_buff);
//	fputs(age_buff, fout_text);//��������ı��ļ�����Ҫ������ת�����ַ���
//	fputc('\n', fout_text);
//
//	fclose(fout_text);
//
//	/*char buff[10];
//	printf("%s\n", my_itoa(-1234, buff));*/
//
//	system("pause");
//	return 0;
//}
/*

int fprintf��FILE * stream��const char * format��...��;  ����ʽ������д����
int fprintf��FILE * stream��const char * format��...��;  �����ж�ȡ��ʽ������
*/

//int main()
//{
//	struct TelInfo info;
//	strcpy(info._name, "���ɳ�");
//	strcpy(info._tel, "18516283077");
//	info._age = 18;
//
//	// �ı���д
//	FILE* fout_text = fopen("input_text.txt", "w");//����д��
//	fprintf(fout_text, "%s\n%s\n%d\n", info._name, info._tel, info._age);
//	fclose(fout_text);
//
//	struct TelInfo other;
//	FILE* fin_bin = fopen("input_text.txt", "r");//����д��
//	fscanf(fin_bin, "%s\n%s\n%d\n", other._name, other._tel, &other._age);
//	fclose(fin_bin);
//	printf("%s,%s,%d\n", other._name, other._tel, other._age);
//
//	system("pause");
//	return 0;
//}


/*
fseek��int fseek��FILE * stream��long int offset��int origin��;
�ı��ļ�ָ��λ�ã�
offset  ƫ����
origin  ��ʼλ��
stream ָ���ʶ��ָ��

SEEK_SET	�ļ���ͷ
SEEK_CUR	�ļ�ָ��ĵ�ǰλ��
SEEK_END	�ļ�����*
*/
//int main()
//{
//	FILE* fin = fopen("input_3.txt", "w");
//	//fputs("world", fin);
//	//fseek(fin, 0, SEEK_SET);
//	//fputs("hello", fin);
//	fputs("world", fin);
//	fseek(fin, -2, SEEK_END);
//	fputs("hello", fin);
//
//	fclose(fin);
//  system("pause");
//	return 0;
//}

/*
  ftell:long int ftell��FILE * stream��;
  �����ļ�ָ���������ʼλ�õ�ƫ����
  rewind:long int ftell��FILE * stream��;
  ���ļ�ָ���λ�ûص��ļ�����ʼλ��
*/

//int main()
//{
//	FILE* fout = fopen("input_3.txt", "r");
//	fseek(fout, 0, SEEK_END);
//	//fseek(fout, 0, SEEK_SET);
//	rewind(fout);//���ļ�ָ���λ�ûص��ļ�����ʼλ
//	long int len = ftell(fout);
//	printf("%d\n", len);//��
//
//	fclose(fout);
//	system("pause");
//	return 0;
//}


/*
ferror:int ferror��FILE * stream��;
ferror�����������ڵ��ø������������������ putc.getc.fread.fwrite�ȣ�ʱ��������ִ��󣬳��˺�������ֵ������ӳ�⣬��������ferror������顣 ����һ�������ʽΪ ferror(fp)�����ferror����ֵΪ0���٣�����ʾδ�����������һ������ֵ����ʾ����Ӧ��ע�⣬��ͬһ���ļ� ÿһ�ε����������������������һ���µ�ferror�� ��ֵ����ˣ�Ӧ���ڵ���һ��������������������� ��ferror������ֵ��������Ϣ�ᶪʧ����ִ��fopen����ʱ��ferror�����ĳ�ʼֵ�Զ���Ϊ0��
*/

#include <errno.h>

int main()
{
	FILE* fout = fopen("input_3.txt", "r");
	if (fout == NULL)
	{
		printf("���ļ�ʧ��:%s\n", strerror(errno));
		return -1;
	}

	fseek(fout, 0, SEEK_END);
	long int len = ftell(fout);
	printf("%d\n", len);

	fseek(fout, 0, SEEK_SET);
	char ch = fgetc(fout);//���ļ��ж����ַ�
	long int count = 0;
	while (len--)
	{
		count++;
		printf("%c", ch);
		ch = fgetc(fout);
	}
	printf("%d\n", count);

	if (ferror(fout))
		puts("I/O error when reading");
	else if (feof(fout))
		puts("End of file reached successfully");

	fclose(fout);

	system("pause");
	return 0;
}