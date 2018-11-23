#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
/**
   筛选与排序问题，循环中两个队列交替
*/
struct Node{
  int idx;
  int weight;
  int mark;
  Node(int _idx, int _weight):idx(_idx),weight(_weight){}
};
struct cmpW{
    bool operator()(const Node &n1,const Node &n2){
        return n1.weight < n2.weight;
    }
};
struct cmpM{
    bool operator()(const Node &n1, const Node &n2){
        return n1.mark < n2.mark;
    }
};
int n,g,seq;
int main(){
    scanf("%d%d",&n,&g);
    queue<int> q1,q2;
    priority_queue<Node,vector<Node>,cmpW> pq;
    priority_queue<Node,vector<Node>,cmpM> res;
    int mouse[n];
    int rank[n];
    for(int i = 0;i < n; i++){
        scanf("%d",&mouse[i]);
    }
    for(int i = 0 ; i < n; i++){
        scanf("%d",&seq);
        q1.push(seq);
    }
    int round = 0;
    while(true){
        queue<int> *q = NULL, *nq = NULL;
        if(q1.empty()){q = &q2;nq = &q1;}
        else {q = &q1;nq = &q2;}
        while(!(*q).empty()){
            int tk = g;
            while(!(*q).empty() && tk > 0){
                int a = (*q).front();(*q).pop();
                Node n = Node(a,mouse[a]);
                pq.push(n);
                tk--;
            }
            Node n1 = pq.top();pq.pop();//本组中最大的
            (*nq).push(n1.idx);
            while(!pq.empty()){
                Node n2 = pq.top();pq.pop();
                n2.mark = round;
                res.push(n2);
            }
        }
        if((*nq).size()==1){
            int top = (*nq).front();(*nq).pop();
            Node n3 = Node(top,mouse[top]);
            n3.mark = round+1;
            res.push(n3);
            break;
        }
        round++;
    }
    int count = 1;
    int r = 1;
    Node pre = res.top();res.pop();
    rank[pre.idx] = r;
    while(!res.empty()){
        Node tmp = res.top();res.pop();
        count ++;
        if(tmp.mark == pre.mark){
            rank[tmp.idx] = r;
        }else{
            rank[tmp.idx] = count;
            r = count;
        }
        pre = tmp;
    }
    for(int i = 0 ; i < n; i++){
        if(i==0) cout<<rank[i];
        else cout<<" "<<rank[i];
    }
    return 0;
}
