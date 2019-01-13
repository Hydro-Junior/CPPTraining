#include<cstdio>
using namespace std;
//1位位统计，分3种情况
int getRes(int n){
    int w = 1,res = 0;
    while(n/w > 0){
        int left = n/(w*10);
        int mid = (n/w)%10;
        int right = n % w;
        if(mid < 1){
            res += left*w;
        }else if(mid == 1){
            res += left*w +(right+1);
        }else{
            res += (left+1)*w;
        }
        w *= 10;
    }
    return res;
}
int main(){
    int n;
    scanf("%d",&n);
    printf("%d\n",getRes(n));
    return 0;
}

