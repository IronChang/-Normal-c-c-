#include <time.h>
#include<iostream>
using namespace std;
 
struct A
{
 
int a[10000];
};
//A ��40000���ֽ� 
//�����д�ֵ����Ҫ����40000���ֽ� 
void TestFunc1(A a)
{}
//�����д����� ����Ҫ���� 
void TestFunc2(A& a)
{}
void TestRefAndValue()
{
 
A a;
 
// ��ֵ��Ϊ��������
 
size_t begin1 = clock();
 
for (size_t i = 0; i < 100000; ++i)
 
TestFunc1(a);
 
size_t end1 = clock();
 
// ��������Ϊ��������
 
size_t begin2 = clock();
 
for (size_t i = 0; i < 100000; ++i)
 
TestFunc2(a);
 
size_t end2 = clock();
cout << "TestFunc1(int*)-time:" << end1 - begin1 << endl;
 
cout << "TestFunc2(int&)-time:" << end2 - begin2 << endl;
}
// ���ж�Σ����ֵ�������ڴ��η����Ч������
int main()
{
 
TestRefAndValue();
 
 
return 0;
}

