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
    ÿ������վ������ס����һ�����룬ѡȡ��̾��������Ǹ�����վ���Ҳ������޶��ľ��뷶Χ
    �����dijkstra�㷨���ã�����Ҫһ�������ȣ���Ȼ��д�ñȽ�������Ȼ���ص���֪��˼·
    ע�⣺����վ���1-M��ʵ��ͼ�б���������ڵ�֮�󣬷ֱ���N+1��N+M
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

//���Դ�ӡͼʱ��
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
    //��ӡͼ�ṹ
    /*for(int i = 1; i <= M+N; i++){
        cout<<"��"<<i<<"��:";
        printVec(G[i]);
    }*/
    for(int s = N+1; s <= N+M; s++){//�������м���վ��ʹ��dijkstra�����̾���
        fill(dist[s-N],dist[s-N]+N+M+1,DBL_MAX);//���+1��С��©����ʱ���м�������Ӳ��ͨ�������Һ����շ���
        mdist[s-N] = DBL_MAX;
        memset(vis,0,sizeof(vis));
        dist[s-N][s] = 0.0;
        priority_queue<P,vector<P>,greater<P> > pq;
        pq.push(P(dist[s-N][s],s));
        while(!pq.empty()){
            P p = pq.top(); pq.pop();
            int u = p.second;
            double du = p.first;
            if(u <= N && du < mdist[s-N]) mdist[s-N] = du;//���¸ü���վ����С����
            vis[u] = true;//����ͼ�Ļ����Ǳ�עһ�·��ʹ�
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
            if(dist[s-N][i] > range) {//������Χ
                dist[s-N][0] = -1;//�޽�
                /*cout<<"������Ҫ��"<<endl;*/
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
        //cout<<setiosflags(ios::fixed)<<setprecision(1)<<r1<<" "<<r2<<endl;//�����÷�ֻ�Ǳ���С��λ��û���������룬���Ҳ��ᳫ�����÷�
    }
    return 0;
}
