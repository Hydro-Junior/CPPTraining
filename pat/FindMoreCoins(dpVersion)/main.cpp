#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
/**
    动态规划法求解最多硬币问题，也能帮助更好地理解01背包问题
*/
vector<int> res[101],coins;
int n,m,num;
void printVec(vector<int>& vec){
    int sz = vec.size();
    for(int i = sz-1; i > 0; i--){//逆向打印，不打印0
        if(i != sz-1) cout<<" "<<vec[i];
        else cout<<vec[i];
    }
    cout<<endl;
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i = 0 ; i < n ;i++){
        scanf("%d",&num);
        if(num <= m){
           coins.push_back(num);
        }
    }
    int sz = coins.size();
    sort(coins.begin(),coins.end());
    res[0].push_back(0);
    for(int i = sz - 1 ; i >= 0; i--){//(越多硬币越好，最后肯定是较小硬币的方案)
        //cout<<"coins["<<i<<"]= "<<coins[i]<<endl;
        for(int j = m; j >= coins[i]; j--){//硬币只有1个，从大到小更新！（0-1背包从高到低坠落，不重复累积；多重背包从低到高，重复积累）
            if(res[j-coins[i]].size()) {
                res[j]=res[j-coins[i]];//整个容器赋值
                res[j].push_back(coins[i]);
            }
        }
        //打印过程值
        /*for(int i = 0 ; i <= m ; i++){
            cout<<i<<": ";
            printVec(res[i]);
        }
        cout<<"------------------------------------"<<endl;*/
    }
    if(res[m].size()==0){
        cout<<"No Solution"<<endl;
    }else{
        printVec(res[m]);
    }
    return 0;
}

