#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

//int main()
//{
//	int a = 10000;
//	FILE* pf = fopen("test.txt", "wb");//��wb��ֻд
//	fwrite(&a, 4, 1, pf);//�Զ����Ƶ���ʽд���ļ�
//	fclose(pf);
//	pf = NULL;
//
//	system("pause");
//	return 0;
//}

//�ļ�ָ��
//FILE*

//�ļ��Ĵ򿪺͹ر�
/*
1.FILE* fopen( const char* filename,const char* mode);
�������ڲ���filename��ָ�����ļ�
��������Ĳ�������ִ�з�ʽ��mode��������
����ļ��ɹ��򿪣���ú�������ָ��FILE�����ָ�룬����������ڽ����Ĳ����б�ʶ����
���򣬷��ؿ�ָ�롣
2.int fclose(FILE* stream);
�ر������������ļ���ȡ��������
����ɹ��ر������򷵻���ֵ��
ʧ��ʱ������EOF��

3.int fputs��const char * str��FILE * stream��;
����Ҫд���������ݵ�C�ַ�����
ָ���ʶ�������FILE�����ָ�롣
�ɹ�ʱ�����طǸ�ֵ��
����ʱ���ú�������EOF�����ô���ָʾ����ferror����
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


//�ļ��������д

/*int fseek(FILE* stream, long int offset, int origin);
�ض�λ����������/�ļ����ϵ��ļ��ڲ�λ��ָ�룬���ļ�ָ��ָ���ļ��Ŀ�ͷ��
ָ���ʶ����FILE�����ָ�롣
����
�������ļ�����ԭ��ƫ�Ƶ��ֽ�����
�ı��ļ������ftell���ص�ֵ��
��Դ
λ������ƫ�ƵĲο�������<cstdio>�ж�������³���֮һָ����ר�������˺����Ĳ�����
����	�ο�λ��
SEEK_SET	�ļ���ͷ
SEEK_CUR	�ļ�ָ��ĵ�ǰλ��
SEEK_END	�ļ�����*
*�����ʵ���������֧��SEEK_END����ˣ�ʹ�����Ĵ���û�������ı�׼����ֲ�ԣ���*/

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
