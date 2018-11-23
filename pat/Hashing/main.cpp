#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
/**
   【素性测试结合二次探测再散列】
   做此题的劣势在于不知道何为二次探测再散列，以及探测具体何时停止，个人猜测k值大于m就没必要试下去了，验证正确
*/
bool isPrime(int p){
    if(p < 2) return false;
    for(int i = 2 ; i * i <= p ;i ++){
        if(p % i == 0) return false;
    }
    return true;
}
int getPrime(int a){
    while(!isPrime(a)){
        a++;
    }
    return a;
}
int main(){
    int m,n;
    scanf("%d%d",&m,&n);
    m = getPrime(m);
    bool table[m];
    memset(table,0,sizeof(table));
    for(int i = 0 ; i < n ;i ++){
        int num;
        scanf("%d",&num);
        num %= m;
        bool noPos = false;
        int k = 1;
        while(table[num]){
            num = (num + k * k)% m;
            if(!table[num]) break;
            num = (num - k * k)% m;
            if(num < 0) num += m;
            if(!table[num]) break;
            k ++;
            if(k > m) noPos = true;
        }
        if(!noPos) {
           table[num] = true;
           if(i == 0) cout<<num;
           else cout<<" "<<num;
        }
        else cout<<" -";
    }
    return 0;
}
