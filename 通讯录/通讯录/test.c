#define _CRT_SECURE_NO_WARNINGS 1
#include"contact.h"


int main()
{
	ContactBook cb;
	ContactBookInit(&cb);//初始化通讯录
	Contact con1;
	strcpy(con1._Name, "宁采臣");
	strcpy(con1._Address, "郭北县");
	strcpy(con1._Tel, "12345678996");
	con1.age = 25;
	ContactBookAppend(&cb, &con1);//添加指定联系人
	Contact con2;
	strcpy(con2._Name, "聂小倩");
	strcpy(con2._Address, "兰若寺");
	strcpy(con2._Tel, "88967458666");
	con2.age = 100;
	ContactBookAppend(&cb, &con2);//添加指定联系人
	Contact con3;
	strcpy(con3._Name, "黑山老妖");
	strcpy(con3._Address, "兰若寺");
	strcpy(con3._Tel, "85967412333");
	con3.age = 1000;
	ContactBookAppend(&cb, &con3);
	//ContactBookUpdate(&cb);//修改指定联系人
	//ContactBookSave(&cb, "Contact.txt");//文件读入
	//ContactBookLoad(&cb,"Contact.txt");//文件写出
	//ContactBookFind(&cb);//查询指定联系人
	//ContactBookDestory(&cb);//删除通讯录
	ContactName_Sort(&cb);//从A-Z排序
	//ContactPrint(&cb);//打印通讯录
	system("pause");
	return 0;
}