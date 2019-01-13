#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
/**
    回溯法处理最多硬币组合问题（此题m最大不超过100，回溯法完全是可行的）
*/
vector<int> res;
int tb[101];
int n,m,num;
void printVec(vector<int>& vec){
    for(int i = 0; i < vec.size(); i++){
        if(i != 0) cout<<" "<<vec[i];
        else cout<<vec[i];
    }
}
bool find(int m){
    if(m == 0) return true;
    for(int i = 1; i <= m ; i++){
        if(tb[i] > 0){
           tb[i]--;
           if(find(m-i)){
                res.push_back(i);
                return true;
           }else{
               tb[i]++;
           }
        }
    }
    return false;
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i = 0 ; i < n ;i++){
        scanf("%d",&num);
        if(num <= m){//只有小于等于m的硬币才有可能参与组合
           tb[num] += 1;
        }
    }
    if(!find(m)){
        cout<<"No Solution"<<endl;
    }else{
        sort(res.begin(),res.end());//有必要排序
        printVec(res);
    }
    return 0;
}
