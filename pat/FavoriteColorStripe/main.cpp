#include<iostream>
using namespace std;
int N,M,L,tp,sq[201],pos[201],dp[201],colors[10001];
int main(){
    cin>>N>>M;
    for(int i = 1 ; i <= M ; i++){
        cin >> tp;
        pos[tp] = i;//颜色tp在喜欢的序列中的位置
        sq[i] = tp;//喜欢的第i种颜色是tp
    }
    cin >> L;
    for(int i = 1; i <= L; i++){
        cin>>colors[i];
    }
    for(int i = 1; i <= L; i++){
        int c = colors[i];
        if(pos[c] != 0){//若该颜色在喜欢的序列中
            int subMax = 0;
            for(int j = 1; j <= pos[c]; j++){
                subMax = max(subMax,dp[sq[j]]);//找到前面的最长序列
            }
            dp[c] = subMax + 1;//dp数组表示以下标c结尾的最长序列的长度
        }
    }
    int res = 0;
    for(int i = 1 ;i <= N ;i ++){
        res = max(dp[i],res);//比较得出最大的长度
    }
    cout<<res;
    return 0;
}
