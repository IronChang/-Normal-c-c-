#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

//int main()
//{
//	FILE* fin = fopen("input.txt", "w");//打开文件以写文本文件
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
//	FILE* fin = fopen("intput.txt", "w");//输入数据到文件
//	fprintf(fin, "语文:%d\n数学:%d\n英语:%d\n排名:%d\n", 98, 100, 99, 2);
//	fclose(fin);
//	system("pause");
//	return 0;
//}
//
//int main()
//{
//	FILE* fout = fopen("intput.txt", "r");//读出数据从文件
//	int a, b, c, d;
//	fscanf(fout, "语文:%d\n数学:%d\n英语:%d\n排名:%d\n", &a, &b, &c, &d);
//	printf("语文:%d\n数学:%d\n英语:%d\n排名:%d\n", a, b, c, d);
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
//char* my_itoa(int num, char* buff)//整形转换为字符型
//{
//	assert(buff);
//	int i = 0;
//	int flag = 0;
//	if (num<0)//如果输入的是负数先将其转换位正数
//	{
//		flag = 1;
//		num = 0 - num;
//	}
//	while (num > 0)//将整形逐位转换成字符型
//	{
//		buff[i] = num % 10 + '0';
//		num /= 10;
//		++i;
//	}
//	if (flag == 1)//添加上负号
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
//	strcpy(info._name, "皮特");
//	strcpy(info._tel, "18516283077");
//	info._age = 19;
//
//	 //文本读写
//	FILE* fout_text = fopen("input_text.txt", "w");//输出数据到文件
//	fputs(info._name, fout_text);
//	fputc('\n', fout_text);
//
//	fputs(info._tel, fout_text);
//	fputc('\n', fout_text);
//
//	char age_buff[12];
//	my_itoa(info._age, age_buff);
//	fputs(age_buff, fout_text);//输出的是文本文件，就要把整形转换成字符型
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

int fprintf（FILE * stream，const char * format，...）;  将格式化数据写入流
int fprintf（FILE * stream，const char * format，...）;  从流中读取格式化数据
*/

//int main()
//{
//	struct TelInfo info;
//	strcpy(info._name, "宁采臣");
//	strcpy(info._tel, "18516283077");
//	info._age = 18;
//
//	// 文本读写
//	FILE* fout_text = fopen("input_text.txt", "w");//数据写出
//	fprintf(fout_text, "%s\n%s\n%d\n", info._name, info._tel, info._age);
//	fclose(fout_text);
//
//	struct TelInfo other;
//	FILE* fin_bin = fopen("input_text.txt", "r");//数据写入
//	fscanf(fin_bin, "%s\n%s\n%d\n", other._name, other._tel, &other._age);
//	fclose(fin_bin);
//	printf("%s,%s,%d\n", other._name, other._tel, other._age);
//
//	system("pause");
//	return 0;
//}


/*
fseek：int fseek（FILE * stream，long int offset，int origin）;
改变文件指针位置；
offset  偏移量
origin  起始位置
stream 指向标识流指针

SEEK_SET	文件开头
SEEK_CUR	文件指针的当前位置
SEEK_END	文件结束*
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
  ftell:long int ftell（FILE * stream）;
  返回文件指针相对于起始位置的偏移量
  rewind:long int ftell（FILE * stream）;
  让文件指针的位置回到文件的起始位置
*/

//int main()
//{
//	FILE* fout = fopen("input_3.txt", "r");
//	fseek(fout, 0, SEEK_END);
//	//fseek(fout, 0, SEEK_SET);
//	rewind(fout);//让文件指针的位置回到文件的起始位
//	long int len = ftell(fout);
//	printf("%d\n", len);//置
//
//	fclose(fout);
//	system("pause");
//	return 0;
//}


/*
ferror:int ferror（FILE * stream）;
ferror，函数名，在调用各种输入输出函数（如 putc.getc.fread.fwrite等）时，如果出现错误，除了函数返回值有所反映外，还可以用ferror函数检查。 它的一般调用形式为 ferror(fp)；如果ferror返回值为0（假），表示未出错。如果返回一个非零值，表示出错。应该注意，对同一个文件 每一次调用输入输出函数，均产生一个新的ferror函 数值，因此，应当在调用一个输入输出函数后立即检 查ferror函数的值，否则信息会丢失。在执行fopen函数时，ferror函数的初始值自动置为0。
*/

#include <errno.h>

int main()
{
	FILE* fout = fopen("input_3.txt", "r");
	if (fout == NULL)
	{
		printf("打开文件失败:%s\n", strerror(errno));
		return -1;
	}

	fseek(fout, 0, SEEK_END);
	long int len = ftell(fout);
	printf("%d\n", len);

	fseek(fout, 0, SEEK_SET);
	char ch = fgetc(fout);//从文件中读入字符
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