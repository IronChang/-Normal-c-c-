#define _CRT_SECURE_NO_WARNINGS 1
#include"contact.h"


int main()
{
	ContactBook cb;
	ContactBookInit(&cb);//��ʼ��ͨѶ¼
	Contact con1;
	strcpy(con1._Name, "���ɳ�");
	strcpy(con1._Address, "������");
	strcpy(con1._Tel, "12345678996");
	con1.age = 25;
	ContactBookAppend(&cb, &con1);//���ָ����ϵ��
	Contact con2;
	strcpy(con2._Name, "��Сٻ");
	strcpy(con2._Address, "������");
	strcpy(con2._Tel, "88967458666");
	con2.age = 100;
	ContactBookAppend(&cb, &con2);//���ָ����ϵ��
	Contact con3;
	strcpy(con3._Name, "��ɽ����");
	strcpy(con3._Address, "������");
	strcpy(con3._Tel, "85967412333");
	con3.age = 1000;
	ContactBookAppend(&cb, &con3);
	//ContactBookUpdate(&cb);//�޸�ָ����ϵ��
	//ContactBookSave(&cb, "Contact.txt");//�ļ�����
	//ContactBookLoad(&cb,"Contact.txt");//�ļ�д��
	//ContactBookFind(&cb);//��ѯָ����ϵ��
	//ContactBookDestory(&cb);//ɾ��ͨѶ¼
	ContactName_Sort(&cb);//��A-Z����
	//ContactPrint(&cb);//��ӡͨѶ¼
	system("pause");
	return 0;
}