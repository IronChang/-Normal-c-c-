#define _CRT_SECURE_NO_WARNINGS 1
#include"contact.h"

//��ʼ��ͨѶ¼
void ContactBookInit(ContactBook* pbook) 
{
	assert(pbook);

	pbook->_con_arrary = (Contact*)malloc(sizeof(Contact)* 8);//����ռ�
	if (pbook->_con_arrary == NULL)//�ж��Ƿ�ɹ�����ռ�
	{
		printf("mallloc error!!!");
		exit(-1);
	}

	pbook->_size = 0;
	pbook->_capacity = 8;
}

//�����ϵ��
void ContactBookAppend(ContactBook* pbook, Contact* con)
{
	assert(pbook && con);

	
	if ((pbook->_size) > (pbook->_capacity))//�жϿռ��Ƿ���
	{   
		pbook->_capacity *= 2;
		Contact* _new_arrary = realloc(pbook->_con_arrary,sizeof(Contact)*pbook->_capacity);//����realloc���������ַ
		if (_new_arrary == NULL)//�жϿռ��Ƿ�����ɹ�
		{
			printf("realloc error!!!");
			exit(-1);
		}
		pbook->_con_arrary = _new_arrary;//���½���������Ŀռ�
	}

	Contact* arrary = pbook->_con_arrary;
	size_t i = pbook->_size;

	//���и�ֵ
	strcpy(arrary[i]._Name, con->_Name);
	strcpy(arrary[i]._Address,con->_Address);
	strcpy(arrary[i]._Tel, con->_Tel);;
	arrary[i].age = con->age;

	pbook->_size++;//��������һ��
}

//�����ϵ��
void ContactPrint(ContactBook* pbook)
{
	assert(pbook);//�ж�����Ĳ�Ϊ��
    
	for (size_t i = 0; i < pbook->_size; i++)//ѭ������
	{

		printf("============================================\n");
		printf("������%s\n", pbook->_con_arrary[i]._Name);
		printf("���䣺%d\n", pbook->_con_arrary[i].age);
		printf("�绰��%s\n", pbook->_con_arrary[i]._Tel);
		printf("��ַ��%s\n", pbook->_con_arrary[i]._Address);
		printf("============================================\n");
	}

}

//��������ͨѶ¼
void ContactBookDestory(ContactBook* pbook)
{
	assert(pbook);//�ж�������Ƿ�Ϊ��

	free(pbook->_con_arrary);
	pbook->_con_arrary = NULL;
	pbook->_capacity = 0;
	pbook->_size = 0;
}

//λ�ò��Һ���
int Find(ContactBook* pbook, const char* name)
{
	assert(pbook && name);//�ж������ָ��ʱ��Ϊ��

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

//�ļ�����
void ContactBookSave(ContactBook* pbook, const char* file)
{
	assert(pbook&&file);//�ж������Ƿ�Ϊ��

	FILE* fout = fopen(file, "wb");//����һ���ļ�
	if (fout == NULL)
	{
		printf("���ļ�ʧ��\n");
	}

	Contact* array = pbook->_con_arrary;
	for (size_t i = 0; i < pbook->_size - 1; i++)
	{
		fwrite(&array[i], sizeof(Contact), 1, fout);
	}
	fclose(fout);
}

//�ļ�����
void ContactBookLoad(ContactBook* pbook, const char* file)
{
	FILE* fin = fopen(file, "rb");
	if (fin == NULL)
	{
		printf("���ļ�ʧ��\n");
		exit(-1);
	}
	Contact con;
	while (fread(&con, sizeof(Contact), 1, fin) == 1);
	{
		ContactBookAppend(pbook, &con);
	}
	fclose(fin);
}

//�޸�ָ����ϵ��
void ContactBookUpdate(ContactBook* pbook)
{
	assert(pbook);
	int find_name = 0;
	char name[20] = { 0 };
	int ret = 0;
	do
	{
		printf("������Ҫ�޸ĵ�����:\n");
		scanf("%s", name);
		find_name = Find(pbook, name);
		if (find_name != -1)
		{
			printf("������Ҫ�޸ĵ���Ϣ��\n");
			printf("���䣺\n");
			int new_age = 0;
			scanf("%d", &new_age);
			pbook->_con_arrary[find_name].age = new_age;

			printf("�绰��\n");
			char new_tel[20] = { 0 };
			scanf("%s", new_tel);
			strcpy(pbook->_con_arrary[find_name]._Tel, new_tel);

			printf("��ַ��\n");
			char new_address[40] = { 0 };
			scanf("%s", new_address);
			strcpy(pbook->_con_arrary[find_name]._Address, new_address);

			printf("�޸ĳɹ�������\n");
		}
		else
		{
			printf("���޴��ˣ��޸�ʧ�ܣ���!\n");
		}

		printf("�Ƿ�����޸ģ�������1��������0\n");
		scanf("%d", &ret);
		while (ret != 0 && ret != 1)
		{
			printf("�����������ѡ��");
			scanf("%d", &ret);
		}

	} while (ret);

}

//ɾ��ָ����ϵ��
void ContactBookDelete(ContactBook* pbook)
{
	assert(pbook);//��������Ƿ�Ϊ��
	int find_name = 0;
	char name[20] = { 0 };
	int ret = 0;
	int i = 0;
	do
	{
		printf("������Ҫɾ��������:\n");
		scanf("%s", name);
		find_name = Find(pbook, name);
		if (find_name != -1)
		{
			for (size_t i = find_name; i < pbook->_size; i++)
			{
				pbook->_con_arrary[i] = pbook->_con_arrary[i + 1];//������ϵ�˺������ϵ����ǰһλ������	
			}
			pbook->_size--;
		    printf("ɾ���ɹ�������\n");
		}
		if (find_name == -1)
		{
			printf("���޴��ˣ�ɾ��ʧ�ܣ�����");
		}

		printf("�Ƿ�������ң�������1��������0\n");
		scanf("%d", &ret);
		while (ret != 0 && ret != 1)
		{
			printf("�����������ѡ��");
			scanf("%d", &ret);
		}

	} while (ret);
}

//����ָ����ϵ��
void ContactBookFind(ContactBook* pbook)
{
	assert(pbook);
	int find_name = 0;
	char name[20] = { 0 };
	int ret = 0;
	do
	{
		printf("������Ҫ���ҵ�����:\n");
		scanf("%s", name);
		find_name = Find(pbook, name);
		if (find_name != -1)
		{
			printf("============================================\n");
			printf("������%s\n", pbook->_con_arrary[find_name]._Name);
			printf("���䣺%d\n", pbook->_con_arrary[find_name].age);
			printf("�绰��%s\n", pbook->_con_arrary[find_name]._Tel);
			printf("��ַ��%s\n", pbook->_con_arrary[find_name]._Address);
			printf("============================================\n");
			printf("��ѯ�ɹ�������\n");
		}
		else
		{
			printf("���޴���,��ѯʧ�ܣ�����\n");
		}

		printf("�Ƿ�������ң�������1��������0\n");
		scanf("%d", &ret);
		while (ret != 0 && ret != 1)
		{
			printf("�����������ѡ��");
			scanf("%d", &ret);
		}

	} while (ret);
}

//����������
void ContactName_Sort(ContactBook* pbook)//��A-Z����
{
	assert(pbook);
	size_t i = 0;
	size_t j = 0;
    
	printf("��������A-Z��˳��Ϊ��\n");
	for (i; i < pbook->_size; i++)
	{
		for (j; j < pbook->_size - i - 1; j++)
		{
			if (strcmp(pbook->_con_arrary[j]._Name, pbook->_con_arrary[j + 1]._Name)>0)//�ȽϽ���
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