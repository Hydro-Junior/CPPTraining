#include<iostream>
#include<sstream>
#include<algorithm>
#include<cfloat>
#include<cmath>
#include<cstring>
#include<climits>
#include<vector>
#include<queue>
using namespace std;
/**
    每个加油站到各个住房有一定距离，选取最短距离最大的那个加油站，且不超出限定的距离范围
    常规的dijkstra算法运用，但需要一定熟练度，不然会写得比较慢，当然，重点是知道思路
    注意：加油站编号1-M在实际图中编号在正常节点之后，分别是N+1到N+M
*/
typedef pair<double,int> P;
class Edge{
public:
    int v;
    int u;
    double cost;
    Edge(int _v,int _u, double _cost):v(_v),u(_u),cost(_cost){}
    int another(int w){
        if(w == v) return u;
        else return v;
    }
};
int N,M,K;
bool vis[1011];
string s1,s2;
double range,mdist[11],sumd[11],dist[11][1011];
vector<Edge> G[1011];

//调试打印图时用
void printVec(vector<Edge>& v){
    for(int i = 0 ; i < v.size(); i++){
        cout<<"["<<v[i].v <<","<< v[i].u << ","<<v[i].cost<<"]    ";
    }
    cout<<endl;
}
int getV(string& s,int n){
    int st,num;
    stringstream ss;
    bool flag = false;
    if(s[0] == 'G'){
        st = 1;
        flag = true;
    }else st = 0;
    for(int i = st; i < s.size(); i ++){
        ss << s[i];
    }
    ss >> num;
    if(flag) return num + n;
    return num;
}
int main(){
    cin>>N>>M>>K>>range;
    for(int i = 0 ; i < K; i++){
        cin>>s1>>s2;
        int v1 = getV(s1,N);
        int v2 = getV(s2,N);
        double d ; cin >> d;
        Edge e(v1,v2,d);
        G[v1].push_back(e);
        G[v2].push_back(e);
    }
    //打印图结构
    /*for(int i = 1; i <= M+N; i++){
        cout<<"【"<<i<<"】:";
        printVec(G[i]);
    }*/
    for(int s = N+1; s <= N+M; s++){//遍历所有加油站，使用dijkstra求解最短距离
        fill(dist[s-N],dist[s-N]+N+M+1,DBL_MAX);//这个+1不小心漏掉的时候有几个案例硬是通不过，幸好最终发现
        mdist[s-N] = DBL_MAX;
        memset(vis,0,sizeof(vis));
        dist[s-N][s] = 0.0;
        priority_queue<P,vector<P>,greater<P> > pq;
        pq.push(P(dist[s-N][s],s));
        while(!pq.empty()){
            P p = pq.top(); pq.pop();
            int u = p.second;
            double du = p.first;
            if(u <= N && du < mdist[s-N]) mdist[s-N] = du;//更新该加油站的最小距离
            vis[u] = true;//无向图的话还是标注一下访问过
            for(Edge e : G[u]){
                int w = e.another(u);
                if(vis[w] || dist[s-N][w] < du)continue;
                if(e.cost + du < dist[s-N][w]){
                    dist[s-N][w] = e.cost + du;
                    pq.push(P(dist[s-N][w],w));
                }
            }
        }
        //cout<<"dists from G["<<s-N<<"]:"<<endl;
        for(int i = 1; i <= N; i++){
            if(dist[s-N][i] > range) {//超出范围
                dist[s-N][0] = -1;//无解
                /*cout<<"不符合要求！"<<endl;*/
                break;
            }
            sumd[s-N] += dist[s-N][i];
            /*cout<<i<<":"<<dist[s-N][i]<<" ";*/
        }
        /*cout<<endl;
        cout<<"the min one:"<< mdist[s-N]<< endl;*/
    }
    int gId = -1;
    double maxRes = DBL_MIN,sumRes = 0.0;
    for(int i = 1; i <= M; i++){
        if(dist[i][0] != -1){
            if(mdist[i] > maxRes){
                gId = i;
                maxRes = mdist[i];
                sumRes = sumd[i];
            }else if(mdist[i] == maxRes && sumd[i] < sumd[gId]){
                gId = i;
                sumRes = sumd[i];
            }
        }
    }
    if(gId == -1) cout<<"No Solution"<<endl;
    else {
        cout<<"G"<<gId<<endl;
        double r1 = maxRes;
        double r2 = sumRes/N;
        printf("%.1f %.1f",round(r1*10)/10,round(r2*10)/10);
        //cout<<setiosflags(ios::fixed)<<setprecision(1)<<r1<<" "<<r2<<endl;//这种用法只是保留小数位，没有四舍五入，并且不提倡这种用法
    }
    return 0;
}
