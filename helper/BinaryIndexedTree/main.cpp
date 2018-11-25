#include <iostream>

using namespace std;
/**
    树状数组，常用于统计区间和，功能没有线段树全，但较为简单。
*/
class BIT{
private:
    int *bit;//存储区间和的数组，2,4,6,8号分别存储的是1-2,1-4,5-6,1-8的和
    int n;//数据总个数
public:
    BIT(int _n){
        n = _n;
        bit = new int[n+1]();
    }
    ~BIT(){
        delete []bit;
    }
    //1-i的区间和
    int sum(int i){
        int s = 0;
        while(i > 0){
            s += bit[i];
            i -= i & -i;//i的二进制的最后一个1可以通过i&-i得到
        }
        return s;
    }
    //第i个数增加x，并更新树状数组
    void add(int i , int x){
        while(i <= n){
            bit[i] += x;
            i += i & -i;
        }
    }
};
int main()
{
    int n ;
    scanf("%d",&n);
    BIT bit(n);
    for(int i = 1 ; i <= n ; i++){
        bit.add(i,1);
    }
    for(int i = 1 ; i <= n; i++){
        cout<<bit.sum(i);
    }
    return 0;
}
