#define _CRT_SECURE_NO_WARNINGS 1
#include"contact.h"

//初始化通讯录
void ContactBookInit(ContactBook* pbook) 
{
	assert(pbook);

	pbook->_con_arrary = (Contact*)malloc(sizeof(Contact)* 8);//申请空间
	if (pbook->_con_arrary == NULL)//判断是否成功申请空间
	{
		printf("mallloc error!!!");
		exit(-1);
	}

	pbook->_size = 0;
	pbook->_capacity = 8;
}

//添加联系人
void ContactBookAppend(ContactBook* pbook, Contact* con)
{
	assert(pbook && con);

	
	if ((pbook->_size) > (pbook->_capacity))//判断空间是否够用
	{   
		pbook->_capacity *= 2;
		Contact* _new_arrary = realloc(pbook->_con_arrary,sizeof(Contact)*pbook->_capacity);//利用realloc（）申请地址
		if (_new_arrary == NULL)//判断空间是否申请成功
		{
			printf("realloc error!!!");
			exit(-1);
		}
		pbook->_con_arrary = _new_arrary;//重新接受新申请的空间
	}

	Contact* arrary = pbook->_con_arrary;
	size_t i = pbook->_size;

	//进行赋值
	strcpy(arrary[i]._Name, con->_Name);
	strcpy(arrary[i]._Address,con->_Address);
	strcpy(arrary[i]._Tel, con->_Tel);;
	arrary[i].age = con->age;

	pbook->_size++;//人数增加一个
}

//输出联系人
void ContactPrint(ContactBook* pbook)
{
	assert(pbook);//判断输入的不为空
    
	for (size_t i = 0; i < pbook->_size; i++)//循环遍历
	{

		printf("============================================\n");
		printf("姓名：%s\n", pbook->_con_arrary[i]._Name);
		printf("年龄：%d\n", pbook->_con_arrary[i].age);
		printf("电话：%s\n", pbook->_con_arrary[i]._Tel);
		printf("地址：%s\n", pbook->_con_arrary[i]._Address);
		printf("============================================\n");
	}

}

//销毁整个通讯录
void ContactBookDestory(ContactBook* pbook)
{
	assert(pbook);//判断输入的是否为空

	free(pbook->_con_arrary);
	pbook->_con_arrary = NULL;
	pbook->_capacity = 0;
	pbook->_size = 0;
}

//位置查找函数
int Find(ContactBook* pbook, const char* name)
{
	assert(pbook && name);//判断输入的指针时候为空

	size_t i = 0;
	for (i; i < pbook->_size; i++)
	{
		if (0 == strcmp(pbook->_con_arrary[i]._Name, name))
		{
			return i;
		}
	}
	return -1;
}

//文件读入
void ContactBookSave(ContactBook* pbook, const char* file)
{
	assert(pbook&&file);//判断输入是否为空

	FILE* fout = fopen(file, "wb");//创建一个文件
	if (fout == NULL)
	{
		printf("打开文件失败\n");
	}

	Contact* array = pbook->_con_arrary;
	for (size_t i = 0; i < pbook->_size - 1; i++)
	{
		fwrite(&array[i], sizeof(Contact), 1, fout);
	}
	fclose(fout);
}

//文件读出
void ContactBookLoad(ContactBook* pbook, const char* file)
{
	FILE* fin = fopen(file, "rb");
	if (fin == NULL)
	{
		printf("打开文件失败\n");
		exit(-1);
	}
	Contact con;
	while (fread(&con, sizeof(Contact), 1, fin) == 1);
	{
		ContactBookAppend(pbook, &con);
	}
	fclose(fin);
}

//修改指定联系人
void ContactBookUpdate(ContactBook* pbook)
{
	assert(pbook);
	int find_name = 0;
	char name[20] = { 0 };
	int ret = 0;
	do
	{
		printf("请输入要修改的名字:\n");
		scanf("%s", name);
		find_name = Find(pbook, name);
		if (find_name != -1)
		{
			printf("请输入要修改的信息：\n");
			printf("年龄：\n");
			int new_age = 0;
			scanf("%d", &new_age);
			pbook->_con_arrary[find_name].age = new_age;

			printf("电话：\n");
			char new_tel[20] = { 0 };
			scanf("%s", new_tel);
			strcpy(pbook->_con_arrary[find_name]._Tel, new_tel);

			printf("地址：\n");
			char new_address[40] = { 0 };
			scanf("%s", new_address);
			strcpy(pbook->_con_arrary[find_name]._Address, new_address);

			printf("修改成功！！！\n");
		}
		else
		{
			printf("查无此人，修改失败！！!\n");
		}

		printf("是否继续修改，继续：1，结束：0\n");
		scanf("%d", &ret);
		while (ret != 0 && ret != 1)
		{
			printf("输入错误，重新选择：");
			scanf("%d", &ret);
		}

	} while (ret);

}

//删除指定联系人
void ContactBookDelete(ContactBook* pbook)
{
	assert(pbook);//检查输入是否为空
	int find_name = 0;
	char name[20] = { 0 };
	int ret = 0;
	int i = 0;
	do
	{
		printf("请输入要删除的名字:\n");
		scanf("%s", name);
		find_name = Find(pbook, name);
		if (find_name != -1)
		{
			for (size_t i = find_name; i < pbook->_size; i++)
			{
				pbook->_con_arrary[i] = pbook->_con_arrary[i + 1];//将该联系人后面的联系人往前一位，覆盖	
			}
			pbook->_size--;
		    printf("删除成功！！！\n");
		}
		if (find_name == -1)
		{
			printf("查无此人，删除失败！！！");
		}

		printf("是否继续查找，继续：1，结束：0\n");
		scanf("%d", &ret);
		while (ret != 0 && ret != 1)
		{
			printf("输入错误，重新选择：");
			scanf("%d", &ret);
		}

	} while (ret);
}

//查找指定联系人
void ContactBookFind(ContactBook* pbook)
{
	assert(pbook);
	int find_name = 0;
	char name[20] = { 0 };
	int ret = 0;
	do
	{
		printf("请输入要查找的名字:\n");
		scanf("%s", name);
		find_name = Find(pbook, name);
		if (find_name != -1)
		{
			printf("============================================\n");
			printf("姓名：%s\n", pbook->_con_arrary[find_name]._Name);
			printf("年龄：%d\n", pbook->_con_arrary[find_name].age);
			printf("电话：%s\n", pbook->_con_arrary[find_name]._Tel);
			printf("地址：%s\n", pbook->_con_arrary[find_name]._Address);
			printf("============================================\n");
			printf("查询成功！！！\n");
		}
		else
		{
			printf("查无此人,查询失败！！！\n");
		}

		printf("是否继续查找，继续：1，结束：0\n");
		scanf("%d", &ret);
		while (ret != 0 && ret != 1)
		{
			printf("输入错误，重新选择：");
			scanf("%d", &ret);
		}

	} while (ret);
}

//按姓名排名
void ContactName_Sort(ContactBook* pbook)//从A-Z排序
{
	assert(pbook);
	size_t i = 0;
	size_t j = 0;
    
	printf("按照姓名A-Z的顺序为：\n");
	for (i; i < pbook->_size; i++)
	{
		for (j; j < pbook->_size - i - 1; j++)
		{
			if (strcmp(pbook->_con_arrary[j]._Name, pbook->_con_arrary[j + 1]._Name)>0)//比较交换
			{
				Contact tmp;
				tmp = pbook->_con_arrary[j];
				pbook->_con_arrary[j] = pbook->_con_arrary[j + 1];
				pbook->_con_arrary[j + 1] = tmp;
			}
		}
	}
	ContactPrint(pbook);
}