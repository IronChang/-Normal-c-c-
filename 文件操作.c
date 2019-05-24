#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

//int main()
//{
//	int a = 10000;
//	FILE* pf = fopen("test.txt", "wb");//“wb”只写
//	fwrite(&a, 4, 1, pf);//以二进制的形式写到文件
//	fclose(pf);
//	pf = NULL;
//
//	system("pause");
//	return 0;
//}

//文件指针
//FILE*

//文件的打开和关闭
/*
1.FILE* fopen( const char* filename,const char* mode);
打开名称在参数filename中指定的文件
流上允许的操作及其执行方式由mode参数定义
如果文件成功打开，则该函数返回指向FILE对象的指针，该象可用于在将来的操作中标识流。
否则，返回空指针。
2.int fclose(FILE* stream);
关闭与流关联的文件并取消关联。
如果成功关闭流，则返回零值。
失败时，返回EOF。

3.int fputs（const char * str，FILE * stream）;
带有要写入流的内容的C字符串。
指向标识输出流的FILE对象的指针。
成功时，返回非负值。
出错时，该函数返回EOF并设置错误指示符（ferror）。
*/

//int main()
//{
//	FILE* pFile;
//	pFile = fopen("myfile.tet", "w");
//	if (pFile != NULL)
//	{
//		fputs("fopen example", pFile);
//		fclose(pFile);
//	}
//	system("pause");
//	return 0;
//}


//文件的随机读写

/*int fseek(FILE* stream, long int offset, int origin);
重定位流（数据流/文件）上的文件内部位置指针，把文件指针指向文件的开头。
指向标识流的FILE对象的指针。
抵消
二进制文件：从原点偏移的字节数。
文本文件：零或ftell返回的值。
起源
位置用作偏移的参考。它由<cstdio>中定义的以下常量之一指定，专门用作此函数的参数：
不变	参考位置
SEEK_SET	文件开头
SEEK_CUR	文件指针的当前位置
SEEK_END	文件结束*
*允许库实现无意义地支持SEEK_END（因此，使用它的代码没有真正的标准可移植性）。*/

//int main()
//{
//	FILE * pFile;
//	pFile = fopen("example.txt", "wb");
//	fputs("This is an apple.", pFile);
//	fseek(pFile, 9, SEEK_SET);
//	fputs(" sam", pFile);
//	fclose(pFile);
//	system("pause"); 
//	return 0;
//}
