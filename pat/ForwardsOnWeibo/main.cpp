#include<iostream>
#include<cstdio>
#include<queue>
#include<vector>
/**
	广搜结合层数判断
*/
using namespace std;
int main(){
    int V,L;
    scanf("%d%d",&V,&L);
    vector<int> G[V+1];
    for(int i = 1 ; i <= V; i++){
        int num;
        scanf("%d",&num);
        int adj[num];
        for(int j = 0 ; j < num; j++){
            scanf("%d",&adj[j]);
            G[adj[j]].push_back(i);
        }
    }
    queue<int> q;
    //查询转发量
    int queryN;
    scanf("%d",&queryN);
    int query[queryN];
    for(int i = 0 ; i < queryN; i++){
        scanf("%d",&query[i]);
    }
    for(int i = 0 ; i < queryN; i++){
        q = queue<int>();
        bool vis[V+1];
        fill(vis,vis+V+1,0);
        int level = 0,count = 0;
        q.push(query[i]);
        vis[query[i]] = true;
        q.push(-1);//利用插入-1的形式标记每一层
        while(!q.empty()){
            while(q.front() != -1){
                int v = q.front();q.pop();
                if(v != query[i])count++;
                for(int k = 0 ; k < G[v].size(); k++){
                    if(!vis[G[v][k]]){
                        vis[G[v][k]] = true;
                        q.push(G[v][k]);
                    }
                }
            }
            q.push(-1);
            q.pop();
            level++;
            if(level > L) break;
        }
        cout<<count<<endl;
    }
    return 0;
}
