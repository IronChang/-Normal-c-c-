class assist{
public:
    assist() {N++;sum += N;}
    static void reset(){N=0;sum=0;}//在VS中不需要此调用函数也可以（不进行多加一次）
    static unsigned int GetSum(){return sum;}
private:
    static int N;
    static int sum;
};
int assist::N = 0;
int assist::sum = 0;
//设置一个静态变量N和sum，在构造函数中进行累加运算；
//然后构造一个以辅助类为类型、大小为n的数组，重复调用此构造函数n次来实现n次的累加运算
class Solution {
public:
    int Sum_Solution(int n) {
        assist::reset();
        assist * p = new assist[n];
        delete []p;
        p = nullptr;
        return assist::GetSum();
    }
};