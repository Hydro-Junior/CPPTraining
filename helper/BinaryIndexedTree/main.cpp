#include <iostream>

using namespace std;
/**
    ��״���飬������ͳ������ͣ�����û���߶���ȫ������Ϊ�򵥡�
*/
class BIT{
private:
    int *bit;//�洢����͵����飬2,4,6,8�ŷֱ�洢����1-2,1-4,5-6,1-8�ĺ�
    int n;//�����ܸ���
public:
    BIT(int _n){
        n = _n;
        bit = new int[n+1]();
    }
    ~BIT(){
        delete []bit;
    }
    //1-i�������
    int sum(int i){
        int s = 0;
        while(i > 0){
            s += bit[i];
            i -= i & -i;//i�Ķ����Ƶ����һ��1����ͨ��i&-i�õ�
        }
        return s;
    }
    //��i��������x����������״����
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
