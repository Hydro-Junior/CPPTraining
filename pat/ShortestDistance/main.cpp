#include<iostream>
#include<algorithm>
using namespace std;
/**
    ����̫�򵥣���ǰ׺������ʵ�ּ��ɣ���Ϊ���漰ĳ�������޸ģ�������״����ֻ��Ϊ�˽�һ����Ϥ������ݽṹ��ʹ�á�
*/
static int off = [](){
    ios::sync_with_stdio(false);
    cin.tie(0);
    return 0;
}();
//��������״����
class BIT{
private:
    int n;
    int* bit;
public:
    BIT(int _n){
        n = _n;
        bit = new int[n+1]();
    }
    ~BIT(){
        delete []bit;
    }
    void add(int i,int a){
        while(i <= n){
            bit[i] += a;
            i += i & (-i);
        }
    }
    int sum(int i){
        int s = 0;
        while(i > 0){
            s += bit[i];
            i -= i & (-i);
        }
        return s;
    }
};
int N,M,x,s1,s2;
int main(){
    cin>>N;
    BIT mybit(N);
    for(int i = 1 ; i <= N; i++){
        cin>>x;
        mybit.add(i,x);
    }
    int total = mybit.sum(N);
    cin>>M;
    while(M--){
        cin>>s1>>s2;
        if(s1 > s2){
            swap(s1,s2);
        }
        int sum1 = mybit.sum(s2-1)-mybit.sum(s1-1);
        int sum2 = total-sum1;
        cout<<min(sum1,sum2)<<endl;
    }
    return 0;
}
