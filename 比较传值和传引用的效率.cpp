#include <time.h>
#include<iostream>
using namespace std;
 
struct A
{
 
int a[10000];
};
//A 就40000个字节 
//向其中传值就是要拷贝40000个字节 
void TestFunc1(A a)
{}
//向其中传引用 不需要拷贝 
void TestFunc2(A& a)
{}
void TestRefAndValue()
{
 
A a;
 
// 以值作为函数参数
 
size_t begin1 = clock();
 
for (size_t i = 0; i < 100000; ++i)
 
TestFunc1(a);
 
size_t end1 = clock();
 
// 以引用作为函数参数
 
size_t begin2 = clock();
 
for (size_t i = 0; i < 100000; ++i)
 
TestFunc2(a);
 
size_t end2 = clock();
cout << "TestFunc1(int*)-time:" << end1 - begin1 << endl;
 
cout << "TestFunc2(int&)-time:" << end2 - begin2 << endl;
}
// 运行多次，检测值和引用在传参方面的效率区别
int main()
{
 
TestRefAndValue();
 
 
return 0;
}

