#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<windows.h>

//��ͺ����ĶԱ�
//���з����������֮�䲻������������  
#define PRINT(FORMAT,VALUE) \
	printf("the value is " #VALUE" is "FORMAT"\n", VALUE);
// #VALUE ��˼������Ԥ����ʱ���к��滻ʱ��VALUE��Ϊ"value"
/*int main()
{
	int i = 10;
	PRINT("%d", i+3);
	//�滻Ϊ
	printf("the value is " "i+3 " "is ""%d",i+3);

	system("pause");
	return 0;
}
*/
//�ú�дһ�������������͵������Һ�����п��Գ�����
//tmp##NAME  �������  ��c��NAME����һ�� 
//��ֹ��ε��ú��� �����������
//�෴����Ϊ�в���������Ҳ��Եز����Ͻ�
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

//�������õĺ꺯��
#define  MAX(a,b) ((a)>(b)?(a):(b))//�����ŷ�ֹ���ȼ�����

/*int main()
{
	int x = 5;
	int y = 8;
	int z = MAX(x++, y++);
	//int z = ((x++) > (y++) ? (x++) : (y++));
	//int z = ((5++) > (8++) ? (5++) : (8++))
	//x����һ�Σ� y��������
	printf("x=%d,y=%d,z=%d" , x, y, z);

	system("pause");
	return 0;
}*/

