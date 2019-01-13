#include<iostream>
#include<cstdio>
using namespace std;
typedef long long ll;
int n;
ll a,b,c,lowA,lowB,lowC;
bool res;
//越界时移位判断，但是容易出错，负数因为是补码，前面相等时直接比较低位即可，不必取反！
int main(){
    scanf("%d",&n);
    for(int i = 0 ; i < n; i++){
        cin>>a>>b>>c;
        lowA = a & 1; a >>= 1;
        lowB = b & 1; b >>= 1;
        lowC = c & 1; c >>= 1;
        if(a + b > c){
            res = true;
        }else if(a + b == c){
            res = (lowA + lowB > lowC);
        }else{
            res = false;
        }

        cout<<"Case #"<<i+1<<": "<<(res==true?"true":"false")<<endl;
    }
    return 0;
}
