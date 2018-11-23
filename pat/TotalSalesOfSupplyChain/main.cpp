#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>
#include<unordered_map>
using namespace std;
/**
	广搜，用-1分割，将不同层分离
*/
int main(){
    int n;
    double p,r;
    scanf("%d%lf%lf",&n,&p,&r);
    unordered_map<int,int> map;
    vector<int> G[n];
    for(int i = 0 ; i < n ;i ++){
        int k;
        scanf("%d",&k);
        if(k == 0){
            int amount;
            scanf("%d",&amount);
            map.insert({i,amount});
        }else{
            for(int t = 0;t < k; t++){
                int v;
                scanf("%d",&v);
                G[i].push_back(v);
            }
        }
    }
    //广搜
    queue<int> q;
    q.push(0);
    q.push(-1);
    int level = 0;
    double sum = 0.0f;
    double R = 1.0;
    while(!q.empty()){
        if(q.front() == -1)break;
        while(q.front() != -1){
            int w = q.front();q.pop();
            if(G[w].size()==0){
                sum += p * map[w] * R;
            }else{
                for(int i = 0; i < G[w].size(); i++){
                    q.push(G[w][i]);
                }
            }
        }
        q.pop();
        q.push(-1);
        level++;
        R *= (1+ r/100);//过程中更新
    }
    printf("%.1f",sum);
    return 0;
}
